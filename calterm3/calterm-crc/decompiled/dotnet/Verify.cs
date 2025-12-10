using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using System.Text;
using System.Windows.Forms;
using System.Xml;
using System.Xml.XPath;
using System.Xml.Xsl;
using Cummins.ApplicationServices;
using Cummins.Calibration;
using Cummins.EventLog;
using Cummins.Launcher;
using Cummins.Parameter;
using Cummins.Services;
using Cummins.Widgets;

[assembly: AssemblyTitle("Poodle")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - Verify")]
[assembly: AssemblyDelaySign(false)]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.Verify;

public class Verifier
{
	private const short CODESUBFILE = 3;

	private const string nameSeparator = " , ";

	private SubfileDisk subfile;

	private VerifyReporter reporter;

	private ResourceManager resourceManager;

	private GTISVersion gtisVersion;

	private CaltermProgress caltermProgress;

	private bool accessFromCLI;

	private string subfileName;

	private string configurationFileName;

	public bool AccessFromCLI
	{
		get
		{
			return accessFromCLI;
		}
		set
		{
			accessFromCLI = value;
		}
	}

	public Verifier(string subfileName, string configFileName, VerifyReporter reporter, CaltermProgress progress, ResourceManager resourceManager, GTISVersion gtisVersion)
	{
		if (subfileName != null && configFileName != null && reporter != null && resourceManager != null)
		{
			accessFromCLI = false;
			this.reporter = reporter;
			this.resourceManager = resourceManager;
			this.gtisVersion = gtisVersion;
			caltermProgress = progress;
			this.subfileName = subfileName;
			configurationFileName = configFileName;
			return;
		}
		throw new ArgumentNullException("Verifier arguments are null.");
	}

	public virtual void Verify()
	{
		bool clearVerifyBit = true;
		if (!AccessFromCLI)
		{
			if (caltermProgress == null)
			{
				throw new ArgumentNullException("Verifier caltermProgress is null.");
			}
			caltermProgress.SetProgress(0, 0, resourceManager.GetString("VerificationStart") + Path.GetFileName(subfileName));
		}
		subfile = new SubfileDisk(configurationFileName, subfileName);
		if (3 == subfile.SubfileType)
		{
			return;
		}
		reporter.UpdateSubfileHeader(subfileName, configurationFileName);
		try
		{
			try
			{
				VerifyProduct();
			}
			catch (MismatchException ex)
			{
				clearVerifyBit = false;
				reporter.LogReport(ex.Message);
			}
			try
			{
				VerifyVersion();
			}
			catch (MismatchException ex2)
			{
				reporter.LogReport(ex2.Message);
			}
			VerifyBreakpointTables();
			UpdateReleaseLevel(clearVerifyBit);
		}
		catch (VerifyException ex3)
		{
			EventLogger.Error("Verication Failed", "Verification Failed for subfile " + subfileName, ex3);
			reporter.LogReport(ex3.Message);
			UpdateReleaseLevel(clearVerifyBit: false);
		}
		catch (SystemException ex4)
		{
			clearVerifyBit = false;
			reporter.LogReport(ex4.Message);
		}
	}

	protected void VerifyProduct()
	{
		byte[] array = new byte[1];
		string text = "";
		if (!AccessFromCLI)
		{
			caltermProgress.SetProgress(resourceManager.GetString("VerifyProductCompatibility"));
		}
		try
		{
			SpecialParameters parameter = SpecialParameters.ConfigFile_Product_ID;
			IParameterModel parameterModel = subfile.Get(parameter);
			switch (gtisVersion)
			{
			case GTISVersion.PreGTIS:
			case GTISVersion.GTIS20:
			case GTISVersion.GTIS38:
			{
				IArray1DModel array1DModel = (IArray1DModel)parameterModel;
				for (int i = 0; i < array1DModel.Length; i++)
				{
					array[0] = byte.Parse(array1DModel[i], NumberStyles.AllowHexSpecifier);
					text += Encoding.ASCII.GetChars(array)[0];
				}
				break;
			}
			case GTISVersion.GTIS45:
				text = ((IValueModel)parameterModel).ScaledValue;
				break;
			}
			string setting = AppSettingHelper.GetSetting(ApplicationSettings.LastProduct);
			if (text == setting)
			{
				reporter.LogReport(resourceManager.GetString("VerifyProductSucess"));
				return;
			}
			throw new MismatchException(SubfileVerifyMessageId.ProductIdMisMatched, resourceManager.GetString("VerifyProductFailed"));
		}
		catch (Exception)
		{
		}
	}

	protected void VerifyVersion()
	{
		if (!AccessFromCLI)
		{
			caltermProgress.SetProgress(resourceManager.GetString("VerifyVersionCompatibility"));
		}
		string text = subfile.CalibrationDataServer.ConfigDate.Trim();
		if (text != "")
		{
			if (gtisVersion != GTISVersion.GTIS45 && gtisVersion != GTISVersion.GTIS38)
			{
				text = text.PadRight(10, '0');
			}
			string[] array = text.Split(new char[1] { '.' }, 4);
			text = "";
			string text2 = "";
			string[] array2 = array;
			foreach (string text3 in array2)
			{
				text2 = text3;
				while (text2.Length < 2)
				{
					text2 = '0' + text3;
				}
				text += text2;
			}
			if (long.Parse(subfile.EndVersion).CompareTo(long.Parse(text)) >= 0 && long.Parse(text).CompareTo(long.Parse(subfile.StartVersion)) >= 0)
			{
				reporter.LogReport(resourceManager.GetString("VerifyVersionSucess"));
			}
			else if (gtisVersion != GTISVersion.GTIS45)
			{
				string message = $"The config file date {text} is not within the subfile max activation version {subfile.StartVersion} - min deactivation version {subfile.EndVersion} range";
				throw new MismatchException(SubfileVerifyMessageId.VersionMismatch, message);
			}
			return;
		}
		throw new VerifyException(SubfileVerifyMessageId.UnableToGetConfigDate, "Configuration file does not contain config date");
	}

	protected void VerifyBreakpointTables()
	{
		int num = 0;
		DataSet parameters = subfile.Parameters;
		DataRow[] array = parameters.Tables["ArrayXYZRelatedAxis"].Select();
		StringBuilder stringBuilder = new StringBuilder();
		DataRow[] array2 = array;
		foreach (DataRow dataRow in array2)
		{
			string name = dataRow["ArrayXYZName"].ToString();
			string parameterName = dataRow["ArrayXAxisName"].ToString();
			string parameterName2 = dataRow["ArrayXYAxisName"].ToString();
			IParameterModel parameterModel = subfile.Get(name);
			try
			{
				if (parameterModel != null && parameterModel.DataType == ParameterType.ArrayXYZ)
				{
					string text = CheckAscending(parameterName);
					if (text != string.Empty)
					{
						stringBuilder.Append(text + " , ");
					}
					string text2 = CheckAscending(parameterName2);
					if (text2 != string.Empty)
					{
						stringBuilder.Append(text2 + " , ");
					}
				}
				else if (parameterModel != null && parameterModel.DataType == ParameterType.ArrayXY)
				{
					string text3 = CheckAscending(parameterName);
					if (text3 != string.Empty)
					{
						stringBuilder.Append(text3 + " , ");
					}
				}
			}
			catch (Exception)
			{
			}
			if (!AccessFromCLI)
			{
				caltermProgress.SetProgress(array.Length, ++num, resourceManager.GetString("VerifyBreakpointTables") + parameterModel.Name + "  ]");
			}
		}
		if (stringBuilder.ToString() == string.Empty)
		{
			reporter.LogReport(resourceManager.GetString("VerifyBreakpointTablesSuccess"));
			return;
		}
		throw new AscendingOrderException(SubfileVerifyMessageId.NotInAscendingOrder, resourceManager.GetString("VerifyBreakpointTablesFailed") + " Parameter: " + stringBuilder.ToString().TrimEnd(new char[1] { ',' }));
	}

	private bool IsAxisAscending(IParameterModel parameterModel)
	{
		return (parameterModel as IArray1DModel).IsAscending();
	}

	private string CheckAscending(string parameterName)
	{
		IParameterModel parameterModel = subfile.Get(parameterName);
		string result = string.Empty;
		if (parameterModel != null && parameterModel.SubfileNumber == subfile.SubfileType && !IsAxisAscending(parameterModel))
		{
			result = parameterModel.Name;
		}
		return result;
	}

	protected void UpdateReleaseLevel(bool clearVerifyBit)
	{
		if (!AccessFromCLI)
		{
			caltermProgress.SetProgress(resourceManager.GetString("VerifyReleaseLevel"));
		}
		SubfileReleaseState releaseState = subfile.ReleaseState;
		SubfileReleaseState subfileReleaseState = subfile.ReleaseState;
		bool flag = false;
		flag = (subfile.ReleaseState & (SubfileReleaseState)1) == (SubfileReleaseState)1;
		if (flag && clearVerifyBit)
		{
			subfileReleaseState = subfile.ReleaseState & SubfileReleaseState.Checked;
		}
		else if (!flag && !clearVerifyBit)
		{
			subfileReleaseState = subfile.ReleaseState | (SubfileReleaseState)1;
		}
		if (subfileReleaseState != releaseState)
		{
			if (!AccessFromCLI)
			{
				caltermProgress.SetProgress(resourceManager.GetString("SubfileSave"));
			}
			try
			{
				subfile.Save(subfileReleaseState);
				if (flag)
				{
					reporter.LogReport(resourceManager.GetString("VerifyBitReset"));
				}
				else
				{
					reporter.LogReport(resourceManager.GetString("VerifyBitSet"));
				}
			}
			catch (UnableToSaveException)
			{
				throw new UnableToSaveSubfile(SubfileVerifyMessageId.UnableToSaveSubfile, "Error in saving subfile");
			}
		}
		if (clearVerifyBit)
		{
			reporter.LogReport(resourceManager.GetString("VerifySuccessful"));
		}
		else
		{
			reporter.LogReport(resourceManager.GetString("VerifyFailed"));
		}
	}
}
public class VerifyComponent : Component, IPropertyPageProvider, ICommandLine
{
	private const string resourceFilename = "Cummins.Verify.VerifyStrings";

	private Container components;

	private VerifyReporter reporter;

	private CaltermProgress caltermProgress;

	private ResourceManager resourceManager;

	private bool accessFromCLI;

	private bool processSuccess;

	private string resultMessage;

	public CaltermProgress Progress
	{
		get
		{
			return caltermProgress;
		}
		set
		{
			caltermProgress = value;
		}
	}

	public ArrayList Pages
	{
		get
		{
			ArrayList arrayList = new ArrayList();
			VerifyProperties value = new VerifyProperties("", "Verify");
			arrayList.Add(value);
			return arrayList;
		}
	}

	public event ProcessCompleteEventHandler ProcessCompleteEvent;

	public VerifyComponent()
	{
		InitializeComponent();
		resourceManager = new ResourceManager("Cummins.Verify.VerifyStrings", Assembly.GetExecutingAssembly());
		reporter = new VerifyReporter(resourceManager);
		accessFromCLI = false;
	}

	public VerifyComponent(bool accessFromCLI)
	{
		InitializeComponent();
		resourceManager = new ResourceManager("Cummins.Verify.VerifyStrings", Assembly.GetExecutingAssembly());
		reporter = new VerifyReporter(resourceManager);
		this.accessFromCLI = accessFromCLI;
	}

	public void VerifySubfiles(string configFileName, ArrayList subfileList, string gtisVersion)
	{
		if (configFileName != null && subfileList != null && gtisVersion != null)
		{
			if (subfileList.Count > 8)
			{
				throw new VerifyException(SubfileVerifyMessageId.InvalidSetofSubfiles, "Subfile set has more than 8 subfiles.");
			}
			if (!accessFromCLI)
			{
				Progress.Title = "Verify progress";
			}
			DateTime now = DateTime.Now;
			string setting = AppSettingHelper.GetSetting(ApplicationSettings.LastProduct);
			GTISVersion gTISLevelFromString = GetGTISLevelFromString(gtisVersion);
			try
			{
				foreach (string subfile in subfileList)
				{
					if (File.Exists(subfile))
					{
						try
						{
							Verifier verifier = new Verifier(subfile, configFileName, reporter, Progress, resourceManager, gTISLevelFromString);
							verifier.AccessFromCLI = accessFromCLI;
							verifier.Verify();
						}
						catch (Exception ex)
						{
							reporter.LogReport(ex.Message);
							reporter.LogReport(resourceManager.GetString("VerifyFailed"));
						}
						continue;
					}
					throw new FileNotFoundException(subfile + " not found.");
				}
				return;
			}
			catch (Exception ex2)
			{
				reporter.LogReport("Error in  Subfile Verify - " + ex2.Message);
				return;
			}
			finally
			{
				DateTime now2 = DateTime.Now;
				reporter.UpdateReportHeader(setting, now.ToString(), now2.ToString());
				reporter.Save();
			}
		}
		throw new ArgumentNullException("Subfile verification arguments are null");
	}

	private GTISVersion GetGTISLevelFromString(string gtisVersion)
	{
		GTISVersion result = GTISVersion.GTIS45;
		switch (gtisVersion)
		{
		case "GTIS45":
			result = GTISVersion.GTIS45;
			break;
		case "GTIS38":
			result = GTISVersion.GTIS38;
			break;
		case "GTIS20":
			result = GTISVersion.GTIS20;
			break;
		case "CM4X":
			result = GTISVersion.CM4X;
			break;
		case "ECMB":
			result = GTISVersion.ECMB;
			break;
		case "PreGTIS":
			result = GTISVersion.PreGTIS;
			break;
		case "Unknown":
			result = GTISVersion.Unknown;
			break;
		}
		return result;
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		base.Dispose(disposing);
	}

	private void InitializeComponent()
	{
		components = new Container();
	}

	public void Start(DataSet argumentDataSet)
	{
		processSuccess = true;
		resultMessage = string.Empty;
		try
		{
			if (argumentDataSet == null)
			{
				processSuccess = false;
				resultMessage = "VerifyComponent.Start - called with null argument";
				throw new ArgumentNullException("argumentDataSet", resultMessage);
			}
			DataTable dataTable = argumentDataSet.Tables["Assemble"];
			if (dataTable == null)
			{
				processSuccess = false;
				resultMessage = "VerifyComponent.Start - no Subfile verify arguments related DataTable provided.";
				throw new ArgumentException(resultMessage, "argumentDataSet");
			}
			DataRow dataRow = dataTable.Rows[0];
			if (dataRow == null)
			{
				processSuccess = false;
				resultMessage = "VerifyComponent.Start - no Subfile verify arguments related DataRow provided.";
				throw new ArgumentException(resultMessage, "argumentDataSet");
			}
			string text = dataRow["Product"].ToString();
			string text2 = dataRow["ParameterFile"].ToString();
			string text3 = dataRow["VerifyConfigurationFile"].ToString();
			string text4 = dataRow["VerifyReportFile"].ToString();
			string text5 = dataRow["VerifyReportFormat"].ToString().ToUpper();
			bool appendReportFile = false;
			if (dataRow["AppendVerifyreport"] != DBNull.Value)
			{
				appendReportFile = bool.Parse(dataRow["AppendVerifyreport"].ToString());
			}
			IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			if (productInformationService == null)
			{
				processSuccess = false;
				resultMessage = "VerifyComponent is not ble to get ProductInfomationService.";
				throw new VerifyException(SubfileVerifyMessageId.UnableToGetService, resultMessage);
			}
			string gtisVersion = productInformationService.GTISLevel(text);
			if (!File.Exists(text2))
			{
				processSuccess = false;
				resultMessage = $"Specified subfile parameter file {text2} does not exist.";
				throw new ArgumentException(resultMessage);
			}
			if (!File.Exists(text3))
			{
				processSuccess = false;
				resultMessage = $"Specified configuration file {text3} does not exist.";
				throw new ArgumentException(resultMessage);
			}
			StreamReader streamReader = new StreamReader(text2);
			string text6 = streamReader.ReadToEnd();
			text6 = text6.Trim();
			text6 = text6.Replace("\n", "");
			char[] separator = new char[1] { '\r' };
			string[] array = text6.Split(separator);
			streamReader.Close();
			ArrayList arrayList = new ArrayList();
			for (int i = 0; i < array.Length; i++)
			{
				string text7 = array[i].Trim();
				if (!File.Exists(text7))
				{
					processSuccess = false;
					resultMessage = $"Specified Subfile {text7} does not exist.";
					throw new ArgumentException(resultMessage);
				}
				arrayList.Add(text7);
			}
			if (text5.Length > 0)
			{
				reporter.ReportFormat = text5;
			}
			reporter.AppendReportFile = appendReportFile;
			if (text4.Length > 0)
			{
				reporter.ReportFile = text4;
			}
			reporter.AccessFromCLI = accessFromCLI;
			reporter.ProductID = text;
			VerifySubfiles(text3, arrayList, gtisVersion);
		}
		catch (SystemException ex)
		{
			processSuccess = false;
			resultMessage = " Subfile verify failed, and the error is: " + ex.Message;
		}
		finally
		{
			resultMessage += $" The Subfile Verify report file is {reporter.ReportFile}.";
			RaiseProcessCompleteEvent(processSuccess, resultMessage);
		}
	}

	public void Start(XmlDocument xmlDoc)
	{
		throw new InvalidOperationException();
	}

	public void RaiseProcessCompleteEvent(bool flag, string resultMessage)
	{
		if (this.ProcessCompleteEvent != null)
		{
			ProcessCompleteEventArgs args = new ProcessCompleteEventArgs(flag, resultMessage);
			this.ProcessCompleteEvent(this, args);
		}
	}
}
public enum SubfileVerifyMessageId
{
	ProductIdMisMatched = 1,
	VersionMismatch,
	NotInAscendingOrder,
	UnableToSaveSubfile,
	InvalidSetofSubfiles,
	VerifyReportXsdResourceNotFound,
	UnableToGetConfigDate,
	UnableToGetService
}
public class VerifyException : BaseException
{
	public VerifyException()
		: base(Facility.Verify, 0)
	{
	}

	public VerifyException(SubfileVerifyMessageId errorID, string message)
		: base(Facility.Verify, (short)errorID, message)
	{
	}

	public VerifyException(SubfileVerifyMessageId errorID, string message, Exception inner)
		: base(Facility.Verify, (short)errorID, message, inner)
	{
	}
}
public class MismatchException : VerifyException
{
	public MismatchException()
	{
	}

	public MismatchException(SubfileVerifyMessageId errorID, string message)
		: base(errorID, message)
	{
	}

	public MismatchException(SubfileVerifyMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
	}
}
public class AscendingOrderException : VerifyException
{
	public AscendingOrderException()
	{
	}

	public AscendingOrderException(SubfileVerifyMessageId errorID, string message)
		: base(errorID, message)
	{
	}

	public AscendingOrderException(SubfileVerifyMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
	}
}
public class UnableToSaveSubfile : VerifyException
{
	public UnableToSaveSubfile()
	{
	}

	public UnableToSaveSubfile(SubfileVerifyMessageId errorID, string message)
		: base(errorID, message)
	{
	}

	public UnableToSaveSubfile(SubfileVerifyMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
	}
}
public class VerifyProperties : UserControl, IPropertyPage
{
	private Label lblFilePrefix;

	private Label lblOutputFormat;

	private CheckBox displayReport;

	private TextBox txtFileprefix;

	private ComboBox comboReportFormat;

	private Container components;

	private IAppConfigService appConfigService;

	private string parentNode;

	private string currentNode;

	public string ReportFormat
	{
		get
		{
			return ((Control)comboReportFormat).Text.Trim();
		}
		set
		{
			((Control)comboReportFormat).Text = value;
		}
	}

	public string FilePrefix
	{
		get
		{
			return ((Control)txtFileprefix).Text.Trim();
		}
		set
		{
			((Control)txtFileprefix).Text = value;
		}
	}

	public bool ShowVerifyReport
	{
		get
		{
			return displayReport.Checked;
		}
		set
		{
			displayReport.Checked = value;
		}
	}

	public string CurrentNode
	{
		get
		{
			return currentNode;
		}
		set
		{
			currentNode = value;
		}
	}

	public string ParentNode
	{
		get
		{
			return parentNode;
		}
		set
		{
			parentNode = value;
		}
	}

	public VerifyProperties()
	{
		InitializeComponent();
		Initialize();
	}

	public VerifyProperties(string parentNode, string currentNode)
	{
		if (parentNode != null && currentNode != null)
		{
			InitializeComponent();
			this.parentNode = parentNode;
			this.currentNode = currentNode;
			Initialize();
			return;
		}
		throw new ArgumentNullException("VerifyProperties arguments are null");
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		((ContainerControl)this).Dispose(disposing);
	}

	private void InitializeComponent()
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_000b: Expected O, but got Unknown
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0016: Expected O, but got Unknown
		//IL_0017: Unknown result type (might be due to invalid IL or missing references)
		//IL_0021: Expected O, but got Unknown
		//IL_0022: Unknown result type (might be due to invalid IL or missing references)
		//IL_002c: Expected O, but got Unknown
		//IL_002d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0037: Expected O, but got Unknown
		txtFileprefix = new TextBox();
		lblFilePrefix = new Label();
		comboReportFormat = new ComboBox();
		lblOutputFormat = new Label();
		displayReport = new CheckBox();
		((Control)this).SuspendLayout();
		((Control)txtFileprefix).Location = new Point(184, 88);
		((Control)txtFileprefix).Name = "txtFileprefix";
		((Control)txtFileprefix).Size = new Size(120, 20);
		((Control)txtFileprefix).TabIndex = 1;
		((Control)txtFileprefix).Text = "verify";
		((Control)lblFilePrefix).Location = new Point(104, 88);
		((Control)lblFilePrefix).Name = "lblFilePrefix";
		((Control)lblFilePrefix).Size = new Size(80, 23);
		((Control)lblFilePrefix).TabIndex = 7;
		((Control)lblFilePrefix).Text = "File Prefix:";
		comboReportFormat.DropDownStyle = (ComboBoxStyle)2;
		comboReportFormat.Items.AddRange(new object[3] { "XML", "HTML", "TXT" });
		((Control)comboReportFormat).Location = new Point(184, 56);
		((Control)comboReportFormat).Name = "comboReportFormat";
		((Control)comboReportFormat).Size = new Size(121, 21);
		((Control)comboReportFormat).TabIndex = 0;
		((Control)lblOutputFormat).Location = new Point(104, 56);
		((Control)lblOutputFormat).Name = "lblOutputFormat";
		((Control)lblOutputFormat).Size = new Size(80, 23);
		((Control)lblOutputFormat).TabIndex = 5;
		((Control)lblOutputFormat).Text = "Output Format:";
		displayReport.Checked = true;
		displayReport.CheckState = (CheckState)1;
		((Control)displayReport).Location = new Point(104, 120);
		((Control)displayReport).Name = "displayReport";
		((Control)displayReport).Size = new Size(136, 24);
		((Control)displayReport).TabIndex = 2;
		((Control)displayReport).Text = "Display Output Report";
		((Control)this).Controls.Add((Control)(object)displayReport);
		((Control)this).Controls.Add((Control)(object)txtFileprefix);
		((Control)this).Controls.Add((Control)(object)lblFilePrefix);
		((Control)this).Controls.Add((Control)(object)comboReportFormat);
		((Control)this).Controls.Add((Control)(object)lblOutputFormat);
		((Control)this).Name = "VerifyProperties";
		((Control)this).Size = new Size(472, 216);
		((Control)this).ResumeLayout(false);
	}

	public void Initialize(XmlNode appSetting)
	{
	}

	public void Initialize()
	{
		appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		if (appConfigService != null)
		{
			ReportFormat = appConfigService.GetAppSetting(ApplicationSettings.VerifyReportFormat);
			FilePrefix = appConfigService.GetAppSetting(ApplicationSettings.VerifyReportPrefix);
			ShowVerifyReport = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.VerifyReportDisplay));
			return;
		}
		throw new ArgumentNullException("Application configuration service not initialized.");
	}

	public void SetOptions()
	{
		appConfigService.SetAppSetting(ApplicationSettings.VerifyReportFormat, ReportFormat);
		appConfigService.SetAppSetting(ApplicationSettings.VerifyReportPrefix, FilePrefix);
		appConfigService.SetAppSetting(ApplicationSettings.VerifyReportDisplay, ShowVerifyReport.ToString());
	}

	public void SetOptions(ref XmlDocument appSetting)
	{
		SetOptions();
	}
}
public class VerifyReporter
{
	private const string xmlSchemaFileName = "Cummins.Verify.VerifyReport.xsd";

	private const string TransformExtension = ".xslt";

	private const string TransformPrefix = "Cummins.Verify.verify_";

	private const string reportHeaderTableName = "reportHeader";

	private const string subfileTableName = "subfile";

	private const string subfileHeaderTableName = "header";

	private const string messagesTableName = "messages";

	private const string messageTableName = "message";

	private const string defaultReportFilePrefix = "verify";

	private DataSet reportDataSet;

	private ResourceManager resourceManager;

	private int subfileID = -1;

	private int messagesID = -1;

	private string reportFormat = "html";

	private bool accessFromCLI;

	private string productID = string.Empty;

	private string reportFile = string.Empty;

	private bool appendReportFile;

	public string ReportFormat
	{
		get
		{
			return reportFormat;
		}
		set
		{
			reportFormat = value;
		}
	}

	public string ReportFile
	{
		get
		{
			return reportFile;
		}
		set
		{
			reportFile = value;
		}
	}

	public bool AccessFromCLI
	{
		get
		{
			return accessFromCLI;
		}
		set
		{
			accessFromCLI = value;
		}
	}

	public string ProductID
	{
		get
		{
			return productID;
		}
		set
		{
			productID = value;
		}
	}

	public bool AppendReportFile
	{
		get
		{
			return appendReportFile;
		}
		set
		{
			appendReportFile = value;
		}
	}

	public VerifyReporter(ResourceManager resourceManager)
	{
		if (resourceManager != null)
		{
			this.resourceManager = resourceManager;
			reportDataSet = new DataSet();
			Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream("Cummins.Verify.VerifyReport.xsd");
			if (manifestResourceStream == null || manifestResourceStream.Length == 0)
			{
				throw new ResourceException(Facility.Verify, 6, "VerifyReporter::The Verify report schema resource for loading Cummins.Verify.VerifyReport.xsd not found.", "Cummins.Verify.VerifyReport.xsd");
			}
			reportDataSet.ReadXmlSchema(manifestResourceStream);
			return;
		}
		throw new ArgumentNullException("System.Resources.ResourceManager is null.");
	}

	public void LogReport(string messageDescription)
	{
		if (messageDescription != null)
		{
			if (messagesID == -1)
			{
				DataRow dataRow = reportDataSet.Tables["messages"].NewRow();
				if (subfileID == -1)
				{
					DataRow dataRow2 = reportDataSet.Tables["subfile"].NewRow();
					subfileID = int.Parse(dataRow2["subfile_id"].ToString());
					reportDataSet.Tables["subfile"].Rows.Add(dataRow2);
					DataRow dataRow3 = reportDataSet.Tables["header"].NewRow();
					dataRow3["subfileName"] = " ";
					dataRow3["configFileName"] = " ";
					dataRow3["subfile_id"] = subfileID;
					reportDataSet.Tables["header"].Rows.Add(dataRow3);
				}
				dataRow["subfile_id"] = subfileID;
				messagesID = int.Parse(dataRow["messages_Id"].ToString());
				reportDataSet.Tables["messages"].Rows.Add(dataRow);
			}
			DataRow dataRow4 = reportDataSet.Tables["message"].NewRow();
			dataRow4["message_Column"] = messageDescription;
			dataRow4["messages_id"] = messagesID;
			reportDataSet.Tables["message"].Rows.Add(dataRow4);
			return;
		}
		throw new ArgumentNullException("Message description is null.");
	}

	public void UpdateReportHeader(string productID, string startTime, string endTime)
	{
		if (productID != null && startTime != null && endTime != null)
		{
			DataRow dataRow = reportDataSet.Tables["reportHeader"].NewRow();
			dataRow["product"] = productID;
			dataRow["startTime"] = startTime;
			dataRow["endTime"] = endTime;
			reportDataSet.Tables["reportHeader"].Rows.Add(dataRow);
			return;
		}
		throw new ArgumentNullException("Report header information is null.");
	}

	public void UpdateSubfileHeader(string subfileName, string configFileName)
	{
		if (subfileName != null && configFileName != null)
		{
			messagesID = -1;
			DataRow dataRow = reportDataSet.Tables["subfile"].NewRow();
			subfileID = int.Parse(dataRow["subfile_id"].ToString());
			reportDataSet.Tables["subfile"].Rows.Add(dataRow);
			DataRow dataRow2 = reportDataSet.Tables["header"].NewRow();
			dataRow2["subfileName"] = subfileName;
			dataRow2["configFileName"] = configFileName;
			dataRow2["subfile_id"] = subfileID;
			reportDataSet.Tables["header"].Rows.Add(dataRow2);
			return;
		}
		throw new ArgumentNullException("Subfile header information is null.");
	}

	public void Save()
	{
		//IL_01ec: Unknown result type (might be due to invalid IL or missing references)
		//IL_01f3: Expected O, but got Unknown
		//IL_01f3: Unknown result type (might be due to invalid IL or missing references)
		//IL_01fa: Expected O, but got Unknown
		//IL_021d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0224: Expected O, but got Unknown
		//IL_0229: Unknown result type (might be due to invalid IL or missing references)
		//IL_0244: Expected O, but got Unknown
		IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
		if (directoryService == null)
		{
			throw new VerifyException(SubfileVerifyMessageId.UnableToGetService, "VerifyReporter is not able to get the DirectoryService.");
		}
		string appSetting3;
		bool flag;
		string text;
		if (!AccessFromCLI)
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			if (appConfigService == null)
			{
				throw new VerifyException(SubfileVerifyMessageId.UnableToGetService, "VerifyReporter is not able to get the AppConfig Service.");
			}
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			string appSetting2 = appConfigService.GetAppSetting(ApplicationSettings.VerifyReportPrefix);
			appSetting3 = appConfigService.GetAppSetting(ApplicationSettings.VerifyReportFormat);
			flag = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.VerifyReportDisplay));
			string path = directoryService.FolderName(FolderType.Product, appSetting);
			text = Utility.FindAvailableFilename(appSetting2, ".vfy." + appSetting3.ToLower(), path);
		}
		else
		{
			string appSetting = ProductID;
			appSetting3 = ReportFormat;
			flag = false;
			if (ReportFile.Length == 0)
			{
				string appSetting2 = "verify";
				string path = directoryService.FolderName(FolderType.Product, appSetting);
				text = (ReportFile = Utility.FindAvailableFilename(appSetting2, ".vfy." + appSetting3.ToLower(), path));
			}
			else
			{
				FileInfo fileInfo = new FileInfo(ReportFile);
				string path = fileInfo.DirectoryName;
				DirectoryInfo directoryInfo = new DirectoryInfo(path);
				if (directoryInfo.Exists)
				{
					text = ReportFile;
				}
				else
				{
					string appSetting2 = "verify";
					path = directoryService.FolderName(FolderType.Product, appSetting);
					text = Utility.FindAvailableFilename(appSetting2, ".vfy." + appSetting3.ToLower(), path);
				}
				ReportFile = text;
			}
		}
		reportDataSet.AcceptChanges();
		if (appSetting3.ToUpper() == "XML")
		{
			reportDataSet.WriteXml(text);
		}
		else
		{
			string tempFileName = Path.GetTempFileName();
			reportDataSet.WriteXml(tempFileName, XmlWriteMode.IgnoreSchema);
			StreamWriter streamWriter = null;
			streamWriter = ((!AppendReportFile) ? File.CreateText(text) : File.AppendText(text));
			Stream stream = File.OpenRead(tempFileName);
			XPathDocument val = new XPathDocument(stream);
			XslTransform val2 = new XslTransform();
			string name = "Cummins.Verify.verify_" + appSetting3.ToLower() + ".xslt";
			XmlTextReader val3 = new XmlTextReader(Assembly.GetExecutingAssembly().GetManifestResourceStream(name));
			val2.Load((IXPathNavigable)new XPathDocument((XmlReader)(object)val3, (XmlSpace)2), (XmlResolver)null, GetType().Assembly.Evidence);
			val2.Transform((IXPathNavigable)(object)val, (XsltArgumentList)null, (TextWriter)streamWriter, (XmlResolver)null);
			streamWriter.WriteLine();
			streamWriter.WriteLine();
			streamWriter.Close();
			stream.Close();
			((XmlReader)val3).Close();
			File.Delete(tempFileName);
		}
		if (flag)
		{
			Process.Start(text);
		}
	}
}
