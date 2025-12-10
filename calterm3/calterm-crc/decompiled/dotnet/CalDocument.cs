using System;
using System.Collections;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
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
using Cummins.MessageDialog;
using Cummins.Parameter;
using Cummins.ParameterSelector;
using Cummins.Services;
using Cummins.Widgets;
using TSWizards;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyDescription("")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyTitle("Poodle")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - CalDocument")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.CalDocument;

public class UserCancelException : ApplicationException
{
}
public class CalDocument : Component, IPropertyPageProvider
{
	private Container components;

	private Configuration documentConfig;

	private Configuration compareConfig;

	private CaltermProgress progressView;

	private string _reportPath;

	ArrayList IPropertyPageProvider.Pages => null;

	public void SetReportPath(string value)
	{
		_reportPath = value;
	}

	public CalDocument(IContainer container)
	{
		container.Add(this);
		InitializeComponent();
		Initialize();
	}

	public CalDocument()
	{
		InitializeComponent();
		Initialize();
	}

	public void Document(ICalibrationECM[] modules)
	{
		DocumentWizard wizardObject = new DocumentWizard(modules);
		Document(wizardObject);
	}

	public void Document()
	{
		DocumentWizard wizardObject = new DocumentWizard();
		Document(wizardObject);
	}

	private void Document(object wizardObject)
	{
		//IL_0014: Unknown result type (might be due to invalid IL or missing references)
		//IL_001a: Invalid comparison between Unknown and I4
		//IL_0118: Unknown result type (might be due to invalid IL or missing references)
		DocumentWizard documentWizard = wizardObject as DocumentWizard;
		documentWizard.CurrentConfiguration = documentConfig;
		if ((int)((Form)documentWizard).ShowDialog() == 1)
		{
			DocumentReporter documentReporter = new DocumentReporter();
			documentReporter.ProgressComplete += reporter_ProgressComplete;
			documentReporter.ProgressUpdate += reporter_ProgressUpdate;
			documentReporter.StatusUpdate += reporter_StatusUpdate;
			progressView = new CaltermProgress("Calibration Document", allowCancel: true);
			progressView.CancelProgressEvent += ProgressCancelled;
			try
			{
				DocumentReporter.ProcessDelegate processDelegate = documentReporter.Process;
				IAsyncResult result = processDelegate.BeginInvoke(documentWizard.CurrentConfiguration, documentWizard.Calibration, null, null);
				progressView.StartModal();
				processDelegate.EndInvoke(result);
			}
			catch (UserCancelException)
			{
				documentReporter.DiscardReport();
				EventLogger.Info("Document", "Calibration Document process cancelled ");
			}
			catch (Exception ex2)
			{
				MessageBox.Show(ex2.Message, "Encountered error during the Calibration Document process." + Environment.NewLine + Environment.NewLine + "Details: " + ex2.ToString());
			}
		}
	}

	public void DocumentCLI(Configuration documentConfiguration, ICalibration sourceCal)
	{
		DocumentReporter documentReporter = new DocumentReporter();
		documentReporter.SetReportPath(_reportPath);
		DocumentReporter.ProcessDelegate processDelegate = documentReporter.Process;
		try
		{
			IAsyncResult result = processDelegate.BeginInvoke(documentConfiguration, sourceCal, null, null);
			processDelegate.EndInvoke(result);
		}
		catch (UserCancelException)
		{
			documentReporter.DiscardReport();
		}
	}

	public void Compare()
	{
		//IL_0013: Unknown result type (might be due to invalid IL or missing references)
		//IL_0019: Invalid comparison between Unknown and I4
		CompareWizard compareWizard = new CompareWizard();
		compareWizard.Configuration = compareConfig;
		try
		{
			if ((int)((Form)compareWizard).ShowDialog() == 1)
			{
				CompareReporter compareReporter = new CompareReporter();
				compareReporter.ProgressComplete += reporter_ProgressComplete;
				compareReporter.ProgressUpdate += reporter_ProgressUpdate;
				compareReporter.StatusUpdate += reporter_StatusUpdate;
				progressView = new CaltermProgress("Calibration Compare", allowCancel: true);
				progressView.CancelProgressEvent += ProgressCancelled;
				CompareReporter.ProcessDelegate processDelegate = compareReporter.Process;
				try
				{
					IAsyncResult result = processDelegate.BeginInvoke(compareWizard.Configuration, compareWizard.SourceOne, compareWizard.SourceTwo, null, null);
					progressView.StartModal();
					processDelegate.EndInvoke(result);
					return;
				}
				catch (UserCancelException)
				{
					compareReporter.DiscardReport();
					EventLogger.Info("Compare", "Calibration Compare process cancelled ");
					return;
				}
			}
		}
		catch (InvalidDataSourceException ex2)
		{
			MsgBox.Show(ex2.Message, "Compare", ex2.ToString(), MsgBoxButtons.OK, MsgBoxIcon.Error);
		}
	}

	public void CompareCLI(Configuration compareConfiguration, ICalibration sourceOne, ICalibration sourceTwo)
	{
		CompareReporter compareReporter = new CompareReporter();
		compareReporter.SetReportPath(_reportPath);
		CompareReporter.ProcessDelegate processDelegate = compareReporter.Process;
		try
		{
			IAsyncResult result = processDelegate.BeginInvoke(compareConfiguration, sourceOne, sourceTwo, null, null);
			processDelegate.EndInvoke(result);
		}
		catch (UserCancelException)
		{
			compareReporter.DiscardReport();
		}
	}

	private void Initialize()
	{
		compareConfig = new Configuration(ReportTypes.Compare);
		documentConfig = new Configuration(ReportTypes.Document);
	}

	private void InitializeComponent()
	{
		components = new Container();
	}

	private void reporter_StatusUpdate(object sender, StatusUpdateEventArgs args)
	{
		progressView.SetProgress(args.StatusMessage);
	}

	private void reporter_ProgressUpdate(object sender, ProgressUpdateEventArgs args)
	{
		progressView.SetProgress(args.MaxParameters, args.ParametersProcessed, "Processing parameters");
	}

	private void reporter_ProgressComplete(object sender, EventArgs e)
	{
		progressView.Finish();
	}

	private void ProgressCancelled(object sender, CancelEventArgs e)
	{
		progressView.Dispose();
		throw new UserCancelException();
	}
}
public class CalibrationStep : BaseStep
{
	private IContainer components;

	public virtual ICalibration Calibration => null;

	public virtual CalibrationFileSelectControl CalibrationFileSelectControl => null;

	public CalibrationStep()
	{
		InitializeComponent();
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
		((Control)this).Name = "CalibrationStep";
		((Control)this).Size = new Size(672, 296);
	}
}
public class CalibrationFileStep : CalibrationStep
{
	public delegate void ValidateFileTypesEventHandler(CalibrationStep sender, EventArgs e);

	private const string resourceFilename = "Cummins.CalDocument.strings";

	private IContainer components;

	private CalibrationFileSelectControl calibrationFileSelectControl1;

	private ResourceManager resourceManager;

	public override ICalibration Calibration => calibrationFileSelectControl1.SelectedCalibration;

	public override CalibrationFileSelectControl CalibrationFileSelectControl => calibrationFileSelectControl1;

	public string SetTitle
	{
		set
		{
			base.StepTitle = value;
		}
	}

	public event ValidateFileTypesEventHandler ValidateFileTypesEvent;

	public CalibrationFileStep()
	{
		InitializeComponent();
		base.Description = "Select a calibration file and its associated configuration file";
		resourceManager = new ResourceManager("Cummins.CalDocument.strings", Assembly.GetExecutingAssembly());
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
		calibrationFileSelectControl1 = new CalibrationFileSelectControl();
		((Control)this).SuspendLayout();
		calibrationFileSelectControl1.BaseDirectory = null;
		calibrationFileSelectControl1.CalibrationDataSourceType = CalibrationDataSourceType.Any;
		calibrationFileSelectControl1.CalibrationFilename = "";
		calibrationFileSelectControl1.ConfigFilename = "";
		calibrationFileSelectControl1.GTIS = GTISVersion.GTIS45;
		((Control)calibrationFileSelectControl1).Location = new Point(8, 88);
		((Control)calibrationFileSelectControl1).Name = "calibrationFileSelectControl1";
		((Control)calibrationFileSelectControl1).Size = new Size(456, 72);
		((Control)calibrationFileSelectControl1).TabIndex = 1;
		((UserControl)calibrationFileSelectControl1).TextChanged += OnCalibrationFileStepShown;
		((Control)this).Controls.Add((Control)(object)calibrationFileSelectControl1);
		((Control)this).Name = "CalibrationFileStep";
		base.StepTitle = "Select Calibration";
		base.ShowStep += OnCalibrationFileStepShown;
		((Control)this).ResumeLayout(false);
	}

	private void RaiseValidateFileTypesEvent()
	{
		if (this.ValidateFileTypesEvent != null)
		{
			this.ValidateFileTypesEvent(this, null);
		}
	}

	private void OnCalibrationFileStepShown(object sender, EventArgs e)
	{
		bool nextEnabled = true;
		IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
		IProduct calTermProduct = productInformationService.GetCalTermProduct(appConfigService.GetAppSetting(ApplicationSettings.LastProduct));
		GTISVersion gTIS = (GTISVersion)Enum.Parse(typeof(GTISVersion), calTermProduct.GTISLevel);
		calibrationFileSelectControl1.GTIS = gTIS;
		if (base.Wizard == null)
		{
			return;
		}
		if (calibrationFileSelectControl1.IsValidFiles)
		{
			try
			{
				RaiseValidateFileTypesEvent();
			}
			catch
			{
				nextEnabled = false;
			}
		}
		else
		{
			nextEnabled = false;
		}
		base.Wizard.NextEnabled = nextEnabled;
	}
}
public class CompareCLI : ICommandLine
{
	private const string resourceFilename = "Cummins.CalDocument.strings";

	private Configuration compareConfig;

	private CalDocument doc;

	private ICalibration sourceOne;

	private ICalibration sourceTwo;

	private string result;

	private bool successFlag;

	private string currentProduct;

	private string defaultSettingsList;

	private ComponentAccessor accessor;

	private ResourceManager resourceManager;

	private FilterView filterView;

	private string _reportPath;

	public ComponentAccessor CompareAccessor
	{
		get
		{
			return accessor;
		}
		set
		{
			accessor = value;
		}
	}

	public event ProcessCompleteEventHandler ProcessCompleteEvent;

	public void SetReportPath(string value)
	{
		_reportPath = value;
	}

	public CompareCLI()
	{
		resourceManager = new ResourceManager("Cummins.CalDocument.strings", Assembly.GetExecutingAssembly());
	}

	public void Start(DataSet argumentDataset)
	{
		throw new InvalidOperationException();
	}

	public void Start(XmlDocument xmlDoc)
	{
		successFlag = false;
		result = string.Empty;
		currentProduct = string.Empty;
		defaultSettingsList = string.Empty;
		CompareAccessor = ComponentAccessor.CLI;
		try
		{
			doc = new CalDocument();
			doc.SetReportPath(_reportPath);
			compareConfig = new Configuration(ReportTypes.Compare);
			SetConfiguration(xmlDoc);
			if (result == string.Empty)
			{
				doc.CompareCLI(compareConfig, sourceOne, sourceTwo);
				if (compareConfig.ResultMessage != string.Empty)
				{
					result += compareConfig.ResultMessage;
					successFlag = true;
				}
				else
				{
					result += " Execution Failed.";
					successFlag = false;
				}
			}
			else
			{
				result += " Execution Failed.";
				successFlag = false;
			}
			if (defaultSettingsList != string.Empty)
			{
				defaultSettingsList = defaultSettingsList.Trim();
				result = result + " Default values used for the following Configuration settings:" + defaultSettingsList.Remove(defaultSettingsList.Length - 1, 1);
			}
		}
		catch (Exception ex)
		{
			result = result + " " + ex.ToString();
		}
		finally
		{
			RaiseProcessCompleteEvent(successFlag, result);
		}
	}

	private void SetConfiguration(XmlDocument xmlDoc)
	{
		//IL_0036: Unknown result type (might be due to invalid IL or missing references)
		//IL_003d: Expected O, but got Unknown
		//IL_030d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0314: Expected O, but got Unknown
		string text = string.Empty;
		string text2 = string.Empty;
		string text3 = string.Empty;
		string text4 = string.Empty;
		string text5 = string.Empty;
		XmlNodeList elementsByTagName = xmlDoc.GetElementsByTagName("Configuration");
		XmlElement val = (XmlElement)elementsByTagName.Item(0);
		if (val.HasAttribute("ReportPrefix"))
		{
			compareConfig.Prefix = val.GetAttribute("ReportPrefix");
		}
		else
		{
			compareConfig.Prefix = "compare";
		}
		if (val.HasAttribute("ReportFormat"))
		{
			compareConfig.OutputFormat = (ReportFormats)GetValue("ReportFormat", val.GetAttribute("ReportFormat").ToUpper(), typeof(ReportFormats), ReportFormats.HTML);
		}
		else
		{
			compareConfig.OutputFormat = ReportFormats.HTML;
		}
		if (val.HasAttribute("SortByGroups"))
		{
			compareConfig.SortByGroups = (bool)GetValue("SortByGroups", val.GetAttribute("SortByGroups"), typeof(bool), true);
		}
		else
		{
			compareConfig.SortByGroups = true;
		}
		if (val.HasAttribute("SortBySubfiles"))
		{
			compareConfig.SortBySubfiles = (bool)GetValue("SortBySubfiles", val.GetAttribute("SortBySubfiles"), typeof(bool), true);
		}
		else
		{
			compareConfig.SortBySubfiles = true;
		}
		if (val.HasAttribute("AppendReport"))
		{
			compareConfig.AppendReport = (bool)GetValue("AppendReport", val.GetAttribute("AppendReport"), typeof(bool), false);
		}
		else
		{
			compareConfig.AppendReport = false;
		}
		compareConfig.IncludeDataplate = true;
		CalibrationDataSourceType calibrationDataSourceType;
		if (val.HasAttribute("SourceOneType"))
		{
			string text6 = val.GetAttribute("SourceOneType").ToLower();
			text6 = ((!(text6 == "import\\export")) ? (text6.Substring(0, 1).ToUpper() + text6.Substring(1).ToLower()) : "ImportExport");
			calibrationDataSourceType = (CalibrationDataSourceType)GetValue("SourceOneType", text6, typeof(CalibrationDataSourceType), CalibrationDataSourceType.Calibration);
		}
		else
		{
			calibrationDataSourceType = CalibrationDataSourceType.Calibration;
		}
		CalibrationDataSourceType calibrationDataSourceType2;
		if (val.HasAttribute("SourceTwoType"))
		{
			string text7 = val.GetAttribute("SourceTwoType").ToLower();
			text7 = ((!(text7 == "import\\export")) ? (text7.Substring(0, 1).ToUpper() + text7.Substring(1).ToLower()) : "ImportExport");
			calibrationDataSourceType2 = (CalibrationDataSourceType)GetValue("SourceTwoType", text7, typeof(CalibrationDataSourceType), CalibrationDataSourceType.Calibration);
		}
		else
		{
			calibrationDataSourceType2 = CalibrationDataSourceType.Calibration;
		}
		if (val.HasAttribute("Product"))
		{
			currentProduct = val.GetAttribute("Product");
		}
		foreach (XmlNode childNode in ((XmlNode)val).ChildNodes)
		{
			XmlNode val2 = childNode;
			switch (val2.Name)
			{
			case "SourceOneConfiguration":
				text2 = val2.InnerText;
				break;
			case "SourceOneCalibration":
				text = val2.InnerText;
				break;
			case "SourceTwoConfiguration":
				text4 = val2.InnerText;
				break;
			case "SourceTwoCalibration":
				text3 = val2.InnerText;
				break;
			case "ReportFilename":
				SetReportFilename(val2.InnerText);
				break;
			case "FilterFilename":
				if (val2.InnerText != string.Empty)
				{
					text5 = val2.InnerText;
				}
				break;
			}
		}
		try
		{
			new FileValidator();
			ValidateFiles(text2, text);
			ValidateFiles(text4, text3);
			if (calibrationDataSourceType == CalibrationDataSourceType.Subfile && calibrationDataSourceType2 == CalibrationDataSourceType.Subfile)
			{
				CheckValidSubfiles(text, text3);
			}
		}
		catch (Exception)
		{
			result += "File Format/CalConfigGTISMatch Validation failed.";
		}
		if (!(result == string.Empty))
		{
			return;
		}
		try
		{
			sourceOne = InitializeCalibration(calibrationDataSourceType, text2, text);
			sourceOne.ParametersInfo.Subfile3Parameters = Subfile3ParametersAddType.ExcludeCode;
			sourceTwo = InitializeCalibration(calibrationDataSourceType2, text4, text3);
			sourceTwo.ParametersInfo.Subfile3Parameters = Subfile3ParametersAddType.ExcludeCode;
			sourceTwo.ParametersInfo.IncludeRuntimeParameters = false;
			string empty = string.Empty;
			if (File.Exists(text5))
			{
				filterView = new FilterView();
				filterView.InitializeData(sourceOne.ParametersInfo);
				filterView.LoadFilter(text5, accessFromCLI: true, ref empty);
				if (!string.IsNullOrEmpty(empty))
				{
					FilterFileParamtersNotFound(empty);
				}
				sourceOne.ParametersInfo.ApplyFilter(filterView.ParameterFilterMode == ParameterFilterMode.Include);
				sourceTwo.ParametersInfo.SelectedParameters = sourceOne.ParametersInfo.SelectedParameters;
				sourceTwo.ParametersInfo.ApplyFilter(filterView.ParameterFilterMode == ParameterFilterMode.Include);
			}
			else
			{
				sourceOne.ParametersInfo.ApplyFilter(includeMode: false);
				sourceTwo.ParametersInfo.SelectedParameters = sourceOne.ParametersInfo.SelectedParameters;
				sourceTwo.ParametersInfo.ApplyFilter(includeMode: false);
			}
		}
		catch (Exception ex2)
		{
			result = result + " Unable to initialize Calibration files." + ex2.ToString() + ex2.StackTrace;
		}
	}

	private void FilterFileParamtersNotFound(string parameterlist)
	{
		Console.WriteLine("Following parameters from filter file were not being used.");
		Console.WriteLine(parameterlist);
	}

	private object GetValue(string attributeName, string attributeValue, Type valueType, object defaultValue)
	{
		object obj = defaultValue;
		try
		{
			if (valueType.IsEnum)
			{
				obj = Enum.Parse(valueType, attributeValue);
			}
			else if (valueType.ToString() == "System.Boolean")
			{
				obj = bool.Parse(attributeValue);
			}
		}
		catch (Exception)
		{
			defaultSettingsList = defaultSettingsList + attributeName + ", ";
		}
		return obj;
	}

	private void CheckValidSubfiles(string sourceOneSubfile, string sourceTwoSubfile)
	{
		try
		{
			FileValidator fileValidator = new FileValidator();
			fileValidator.ValidateSubfiles(sourceOneSubfile, sourceTwoSubfile);
		}
		catch (SubfileIncompatibilityException ex)
		{
			result = string.Format(resourceManager.GetString("SubfileTypeMismatch"), ex.sourceSubfileName, ex.sourceType.ToString(), ex.targetSubfileName, ex.targetType.ToString());
			throw ex;
		}
	}

	private void ValidateFiles(string configFileName, string dataSourceFileName)
	{
		try
		{
			FileValidator fileValidator = new FileValidator();
			fileValidator.ValidateFiles(configFileName, dataSourceFileName);
		}
		catch (InvalidConfigFileException ex)
		{
			result = string.Format(resourceManager.GetString("InvalidFileFormat"), ex.InvalidFile, "Configuration");
			throw ex;
		}
		catch (InvalidDataFileException ex2)
		{
			result = string.Format(resourceManager.GetString("InvalidFileFormat"), ex2.InvalidFile, "Calibration/Subfile");
			throw ex2;
		}
		catch (GTISIncompatibilityException ex3)
		{
			result = "Configuration and Calibration files belong to different GTIS levels. Configfile = '" + ex3.FirstFileGTISLevel.ToString() + "'   CalFile = '" + ex3.SecondFileGTISLevel.ToString() + "'";
			throw ex3;
		}
	}

	private ICalibration InitializeCalibration(CalibrationDataSourceType type, string sourceConfig, string sourceCal)
	{
		ICalibration calibration = null;
		switch (type)
		{
		case CalibrationDataSourceType.Calibration:
		{
			IProgress progress = null;
			CalibrationFactory calibrationFactory = new CalibrationFactory();
			calibration = calibrationFactory.Create(sourceConfig, sourceCal, progress);
			break;
		}
		case CalibrationDataSourceType.Subfile:
			calibration = new SubfileDisk(sourceConfig, sourceCal);
			break;
		case CalibrationDataSourceType.ImportExport:
			calibration = new CalibrationExport(sourceCal);
			break;
		default:
			result = "Invalid source File.";
			break;
		}
		return calibration;
	}

	private void SetReportFilename(string reportFilename)
	{
		if (reportFilename != string.Empty)
		{
			if (reportFilename.ToUpper().IndexOf(ReportFormats.HTML.ToString()) != -1)
			{
				compareConfig.OutputFormat = ReportFormats.HTML;
				compareConfig.ReportFilename = reportFilename;
			}
			else if (reportFilename.ToUpper().IndexOf(ReportFormats.TXT.ToString()) != -1)
			{
				compareConfig.OutputFormat = ReportFormats.TXT;
				compareConfig.ReportFilename = reportFilename;
			}
			else if (reportFilename.ToUpper().IndexOf(ReportFormats.XML.ToString()) != -1)
			{
				compareConfig.OutputFormat = ReportFormats.XML;
				compareConfig.ReportFilename = reportFilename;
			}
			else
			{
				compareConfig.OutputFormat = ReportFormats.HTML;
				compareConfig.ReportFilename = reportFilename + "." + compareConfig.OutputFormat;
			}
		}
		else
		{
			IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
			string path = directoryService.FolderName(FolderType.Product, currentProduct);
			compareConfig.ReportFilename = Utility.FindAvailableFilename(compareConfig.Prefix, ".cmp." + compareConfig.OutputFormat.ToString().ToLower(), path);
		}
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
public class CompareFileTypeSelectionStep : BaseStep
{
	private CalibrationDataSourceType firstSourceType;

	private CalibrationDataSourceType secondSourceType;

	private GroupBox groupBox2;

	private RadioButton radioTargetSubfile;

	private RadioButton radioTargetCal;

	private GroupBox groupBox1;

	private RadioButton radioSourceSubfile;

	private RadioButton radioSourceImportExport;

	private RadioButton radioSourceCalibration;

	public CalibrationDataSourceType FirstSourceType => firstSourceType;

	public CalibrationDataSourceType SecondSourceType => secondSourceType;

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
		//IL_0038: Unknown result type (might be due to invalid IL or missing references)
		//IL_0042: Expected O, but got Unknown
		//IL_0043: Unknown result type (might be due to invalid IL or missing references)
		//IL_004d: Expected O, but got Unknown
		groupBox2 = new GroupBox();
		radioTargetSubfile = new RadioButton();
		radioTargetCal = new RadioButton();
		groupBox1 = new GroupBox();
		radioSourceSubfile = new RadioButton();
		radioSourceImportExport = new RadioButton();
		radioSourceCalibration = new RadioButton();
		((Control)groupBox2).SuspendLayout();
		((Control)groupBox1).SuspendLayout();
		((Control)this).SuspendLayout();
		((Control)groupBox2).Controls.Add((Control)(object)radioTargetSubfile);
		((Control)groupBox2).Controls.Add((Control)(object)radioTargetCal);
		((Control)groupBox2).Location = new Point(392, 24);
		((Control)groupBox2).Name = "groupBox2";
		((Control)groupBox2).Size = new Size(200, 128);
		((Control)groupBox2).TabIndex = 4;
		groupBox2.TabStop = false;
		((Control)groupBox2).Text = "Second Source Type";
		((Control)radioTargetSubfile).Location = new Point(24, 56);
		((Control)radioTargetSubfile).Name = "radioTargetSubfile";
		((Control)radioTargetSubfile).TabIndex = 6;
		((Control)radioTargetSubfile).Text = "Subfile";
		radioTargetSubfile.CheckedChanged += radioTargetSubfile_CheckedChanged;
		radioTargetCal.Checked = true;
		((Control)radioTargetCal).Location = new Point(24, 24);
		((Control)radioTargetCal).Name = "radioTargetCal";
		((Control)radioTargetCal).TabIndex = 5;
		radioTargetCal.TabStop = true;
		((Control)radioTargetCal).Text = "Calibration";
		radioTargetCal.CheckedChanged += radioTargetCal_CheckedChanged;
		((Control)groupBox1).Controls.Add((Control)(object)radioSourceSubfile);
		((Control)groupBox1).Controls.Add((Control)(object)radioSourceImportExport);
		((Control)groupBox1).Controls.Add((Control)(object)radioSourceCalibration);
		((Control)groupBox1).Location = new Point(112, 24);
		((Control)groupBox1).Name = "groupBox1";
		((Control)groupBox1).Size = new Size(200, 128);
		((Control)groupBox1).TabIndex = 0;
		groupBox1.TabStop = false;
		((Control)groupBox1).Text = "First Source Type";
		((Control)radioSourceSubfile).Location = new Point(16, 56);
		((Control)radioSourceSubfile).Name = "radioSourceSubfile";
		((Control)radioSourceSubfile).TabIndex = 2;
		((Control)radioSourceSubfile).Text = "Subfile";
		radioSourceSubfile.CheckedChanged += radioSourceSubfile_CheckedChanged;
		((Control)radioSourceImportExport).Location = new Point(16, 88);
		((Control)radioSourceImportExport).Name = "radioSourceImportExport";
		((Control)radioSourceImportExport).TabIndex = 3;
		((Control)radioSourceImportExport).Text = "Import/Export";
		radioSourceImportExport.CheckedChanged += radioSourceImportExport_CheckedChanged;
		radioSourceCalibration.Checked = true;
		((Control)radioSourceCalibration).Location = new Point(16, 24);
		((Control)radioSourceCalibration).Name = "radioSourceCalibration";
		((Control)radioSourceCalibration).TabIndex = 1;
		radioSourceCalibration.TabStop = true;
		((Control)radioSourceCalibration).Text = "Calibration";
		radioSourceCalibration.CheckedChanged += radioSourceCalibration_CheckedChanged;
		((Control)this).Controls.Add((Control)(object)groupBox2);
		((Control)this).Controls.Add((Control)(object)groupBox1);
		((Control)this).Name = "CompareFileTypeSelectionStep";
		((Control)this).Size = new Size(712, 256);
		base.StepTitle = "Select Files Type";
		((Control)groupBox2).ResumeLayout(false);
		((Control)groupBox1).ResumeLayout(false);
		((Control)this).ResumeLayout(false);
	}

	public CompareFileTypeSelectionStep()
	{
		InitializeComponent();
		Initialize();
	}

	private void radioSourceCalibration_CheckedChanged(object sender, EventArgs e)
	{
		firstSourceType = CalibrationDataSourceType.Calibration;
	}

	private void radioSourceSubfile_CheckedChanged(object sender, EventArgs e)
	{
		firstSourceType = CalibrationDataSourceType.Subfile;
	}

	private void radioSourceImportExport_CheckedChanged(object sender, EventArgs e)
	{
		firstSourceType = CalibrationDataSourceType.ImportExport;
	}

	private void radioTargetCal_CheckedChanged(object sender, EventArgs e)
	{
		secondSourceType = CalibrationDataSourceType.Calibration;
	}

	private void radioTargetSubfile_CheckedChanged(object sender, EventArgs e)
	{
		secondSourceType = CalibrationDataSourceType.Subfile;
	}

	private void Initialize()
	{
		base.Description = "Select the type of source you want to compare";
		try
		{
			if (radioSourceCalibration.Checked)
			{
				firstSourceType = CalibrationDataSourceType.Calibration;
			}
			else if (radioSourceSubfile.Checked)
			{
				firstSourceType = CalibrationDataSourceType.Subfile;
			}
			else if (radioSourceImportExport.Checked)
			{
				firstSourceType = CalibrationDataSourceType.ImportExport;
			}
			if (radioTargetCal.Checked)
			{
				secondSourceType = CalibrationDataSourceType.Calibration;
			}
			else if (radioTargetSubfile.Checked)
			{
				secondSourceType = CalibrationDataSourceType.Subfile;
			}
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			string lastUsedValue = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastCompareFirstSourceType);
			string lastUsedValue2 = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastCompareSecondSourceType);
			switch (lastUsedValue)
			{
			case "Calibration":
				radioSourceCalibration.Checked = true;
				firstSourceType = CalibrationDataSourceType.Calibration;
				break;
			case "Subfile":
				radioSourceSubfile.Checked = true;
				firstSourceType = CalibrationDataSourceType.Subfile;
				break;
			case "ImportExport":
				radioSourceImportExport.Checked = true;
				firstSourceType = CalibrationDataSourceType.ImportExport;
				break;
			}
			switch (lastUsedValue2)
			{
			case "Calibration":
				radioTargetCal.Checked = true;
				secondSourceType = CalibrationDataSourceType.Calibration;
				break;
			case "Subfile":
				radioTargetSubfile.Checked = true;
				secondSourceType = CalibrationDataSourceType.Subfile;
				break;
			}
		}
		catch
		{
		}
	}

	internal void SaveSettings()
	{
		try
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			string newValue = string.Empty;
			string newValue2 = string.Empty;
			if (radioSourceCalibration.Checked)
			{
				newValue = "Calibration";
			}
			else if (radioSourceSubfile.Checked)
			{
				newValue = "Subfile";
			}
			else if (radioSourceImportExport.Checked)
			{
				newValue = "ImportExport";
			}
			if (radioTargetCal.Checked)
			{
				newValue2 = "Calibration";
			}
			else if (radioTargetSubfile.Checked)
			{
				newValue2 = "Subfile";
			}
			appConfigService.SetLastUsedValue(appSetting, newValue, LastUsedType.LastCompareFirstSourceType);
			appConfigService.SetLastUsedValue(appSetting, newValue2, LastUsedType.LastCompareSecondSourceType);
		}
		catch
		{
		}
	}
}
public abstract class Reporter
{
	protected const int Unset = -1;

	private const string StringResources = "Cummins.CalDocument.strings";

	private const string TransformExtension = ".xslt";

	protected const string FileFilter = "AvailableOffline = 'true' AND InterfaceParameter = 'false'";

	protected const string ModuleFilter = "InterfaceParameter = 'false'";

	protected string ReportPath;

	protected static SpecialParameters[] SubfileNames = new SpecialParameters[8]
	{
		SpecialParameters.Subfile1,
		SpecialParameters.Subfile2,
		SpecialParameters.Subfile3,
		SpecialParameters.Subfile4,
		SpecialParameters.Subfile5,
		SpecialParameters.Subfile6,
		SpecialParameters.Subfile7,
		SpecialParameters.Subfile8
	};

	protected static SpecialParameters[] FQFilePartNumber = new SpecialParameters[4]
	{
		SpecialParameters.FQFilePartNumber1,
		SpecialParameters.FQFilePartNumber2,
		SpecialParameters.FQFilePartNumber3,
		SpecialParameters.FQFilePartNumber4
	};

	protected static SpecialParameters[] FQFileVersion = new SpecialParameters[4]
	{
		SpecialParameters.FQFileVersion1,
		SpecialParameters.FQFileVersion2,
		SpecialParameters.FQFileVersion3,
		SpecialParameters.FQFileVersion4
	};

	protected XmlTextWriter writer;

	protected Configuration preferences;

	private string tempFilename;

	private bool inSubfile;

	private bool inGroup;

	private int currentGroup;

	private int currentSubfile;

	public event ProgressUpdateEventHandler ProgressUpdate;

	public event EventHandler ProgressComplete;

	public event StatusUpdateEventHandler StatusUpdate;

	public void SetReportPath(string value)
	{
		ReportPath = value;
	}

	protected Reporter()
	{
		inSubfile = false;
		inGroup = false;
		currentGroup = -1;
		currentSubfile = -1;
	}

	protected void RaiseProgressUpdateEvent(int elementsProcessed, int totalElements)
	{
		if (this.ProgressUpdate != null)
		{
			ProgressUpdateEventArgs args = new ProgressUpdateEventArgs(elementsProcessed, totalElements);
			this.ProgressUpdate(this, args);
		}
	}

	protected void RaiseProgressCompleteEvent()
	{
		if (this.ProgressComplete != null)
		{
			this.ProgressComplete(this, null);
		}
	}

	protected void RaiseStatusUpdateEvent(string messageID)
	{
		if (this.StatusUpdate != null)
		{
			ResourceManager resourceManager = new ResourceManager("Cummins.CalDocument.strings", Assembly.GetExecutingAssembly());
			string message = resourceManager.GetString(messageID);
			StatusUpdateEventArgs args = new StatusUpdateEventArgs(message);
			this.StatusUpdate(this, args);
		}
	}

	protected void CheckGroupAndSubfile(IParameterModel param1, IParameterModel param2)
	{
		IParameterModel parameterModel = ((param1 == null) ? param2 : param1);
		int newGroup = parameterModel.GroupNumber[parameterModel.GroupNumber.Length - 1];
		CheckGroupAndSubfile(newGroup, parameterModel.SubfileNumber, parameterModel.DataSource);
	}

	protected void CheckGroupAndSubfile(int newGroup, int newSubfile, ICalibration reference)
	{
		if (newSubfile != currentSubfile)
		{
			currentSubfile = newSubfile;
			WriteArrayParameter();
			WriteSubfile(currentSubfile, ref inGroup, ref inSubfile);
		}
		if (newGroup == currentGroup)
		{
			return;
		}
		currentGroup = newGroup;
		DataRow[] array = reference.Parameters.Tables["Group"].Select("GroupNumber = " + currentGroup);
		if (array.Length == 1)
		{
			WriteArrayParameter();
			string comment = string.Empty;
			if (array[0].Table.Columns.Contains("Comment"))
			{
				comment = array[0]["Comment"].ToString();
			}
			WriteGroup(array[0]["Name"].ToString(), comment, ref inGroup);
		}
	}

	protected virtual void WriteArrayParameter()
	{
	}

	protected void CloseGroupAndSubfile()
	{
		if (inGroup)
		{
			((XmlWriter)writer).WriteEndElement();
			inGroup = false;
		}
		if (inSubfile)
		{
			((XmlWriter)writer).WriteEndElement();
			inSubfile = false;
		}
	}

	protected void WriteGroup(string name, string comment, ref bool inGroup)
	{
		if (inGroup)
		{
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteStartElement("group");
		((XmlWriter)writer).WriteAttributeString("name", name);
		((XmlWriter)writer).WriteAttributeString("comment", comment);
		inGroup = true;
	}

	protected void WriteSubfile(int number, ref bool inGroup, ref bool inSubfile)
	{
		if (inSubfile)
		{
			if (inGroup)
			{
				((XmlWriter)writer).WriteEndElement();
				inGroup = false;
			}
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteStartElement("subfile");
		((XmlWriter)writer).WriteAttributeString("number", number.ToString());
		inSubfile = true;
	}

	protected virtual void WriteSubfileName(int subfileNumber)
	{
	}

	protected void WriteMissingAxesInfo(string tableName, StringCollection missingAxes)
	{
		((XmlWriter)writer).WriteStartElement(tableName);
		StringEnumerator enumerator = missingAxes.GetEnumerator();
		try
		{
			while (enumerator.MoveNext())
			{
				string current = enumerator.Current;
				((XmlWriter)writer).WriteElementString("parameterName", current);
			}
		}
		finally
		{
			if (enumerator is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}
		((XmlWriter)writer).WriteEndElement();
	}

	protected XmlTextWriter OpenReport(string startTag)
	{
		//IL_001d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0023: Expected O, but got Unknown
		tempFilename = Path.GetTempFileName();
		XmlTextWriter val = new XmlTextWriter((Stream)File.Open(tempFilename, FileMode.Open, FileAccess.ReadWrite), Encoding.UTF8);
		val.Formatting = (Formatting)1;
		((XmlWriter)val).WriteStartDocument();
		((XmlWriter)val).WriteStartElement(startTag);
		return val;
	}

	public void DiscardReport()
	{
		((XmlWriter)writer).Close();
		File.Delete(tempFilename);
	}

	private void WriteToReport(string error)
	{
		if (ReportPath == null)
		{
			return;
		}
		StreamWriter streamWriter = null;
		try
		{
			string reportPath = ReportPath;
			reportPath = reportPath.Substring(0, reportPath.Length - 4);
			streamWriter = new StreamWriter(reportPath + DateTime.Now.ToString("_MM-dd-yyyy_hh-mm-ss") + ".txt", append: false);
			streamWriter.WriteLine("");
			streamWriter.WriteLine(error);
		}
		catch (Exception)
		{
			Console.WriteLine("SuccessFailureReport file is not accessible.");
		}
		finally
		{
			streamWriter?.Close();
		}
	}

	protected void CloseReport(string resourcePrefix, string reportExtension, string reportFilename)
	{
		//IL_012c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0133: Expected O, but got Unknown
		//IL_0133: Unknown result type (might be due to invalid IL or missing references)
		//IL_013a: Expected O, but got Unknown
		//IL_016d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0174: Expected O, but got Unknown
		//IL_0179: Unknown result type (might be due to invalid IL or missing references)
		//IL_0183: Expected O, but got Unknown
		bool flag = true;
		((XmlWriter)writer).WriteEndElement();
		((XmlWriter)writer).WriteEndDocument();
		((XmlWriter)writer).Flush();
		RaiseStatusUpdateEvent("StatusSaving");
		string empty = string.Empty;
		if (reportFilename == null)
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
			string path = directoryService.FolderName(FolderType.Product, appSetting);
			empty = Utility.FindAvailableFilename(preferences.Prefix, reportExtension + preferences.OutputFormat.ToString().ToLower(), path);
		}
		else
		{
			empty = reportFilename;
			flag = false;
		}
		try
		{
			if (preferences.OutputFormat == ReportFormats.XML)
			{
				((XmlWriter)writer).Close();
				File.Move(tempFilename, empty);
			}
			else
			{
				writer.BaseStream.Seek(0L, SeekOrigin.Begin);
				StreamWriter streamWriter = null;
				streamWriter = ((!preferences.AppendReport) ? File.CreateText(empty) : File.AppendText(empty));
				XPathDocument val = new XPathDocument(writer.BaseStream);
				XslTransform val2 = new XslTransform();
				string name = resourcePrefix + preferences.OutputFormat.ToString().ToLower() + ".xslt";
				XmlTextReader val3 = new XmlTextReader(Assembly.GetExecutingAssembly().GetManifestResourceStream(name));
				val2.Load((IXPathNavigable)new XPathDocument((XmlReader)(object)val3, (XmlSpace)2));
				val2.Transform((IXPathNavigable)(object)val, (XsltArgumentList)null, (TextWriter)streamWriter);
				streamWriter.WriteLine();
				streamWriter.WriteLine();
				((XmlReader)val3).Close();
				streamWriter.Close();
				File.Delete(tempFilename);
			}
		}
		catch (FileNotFoundException ex)
		{
			WriteToReport(ex.Message);
			throw;
		}
		catch (FieldAccessException ex2)
		{
			WriteToReport(ex2.Message);
			throw;
		}
		catch (FileLoadException ex3)
		{
			WriteToReport(ex3.Message);
			throw;
		}
		catch (Exception ex4)
		{
			WriteToReport(ex4.Message);
			throw;
		}
		if (flag)
		{
			Process.Start(empty);
		}
	}
}
public class CompareReporter : Reporter
{
	internal delegate void ProcessDelegate(Configuration prefs, ICalibration source1, ICalibration source2);

	private struct CompareParameters
	{
		public IParameterModel param1;

		public IParameterModel param2;

		public CompareParameters(IParameterModel param1, IParameterModel param2)
		{
			this.param1 = param1;
			this.param2 = param2;
		}
	}

	private const string FilterFileOption = "-g";

	private const string MissingValue = "######";

	private const string TransformPrefix = "Cummins.CalDocument.compare_";

	private const string TransformExtension = ".xslt";

	private const string XAxisLabel = "X";

	private const string YAxisLabel = "Y";

	private const string ZAxisLabel = "Z";

	private const string TableLabel = "T";

	private const int ValuePrecision = 2;

	private ICalibration source1;

	private IParameterListInfo paramsInfo1;

	private StringCollection uniqueParameters1;

	private CalibrationDataSourceType dataSourceType1;

	private IParameterModel currentParam1;

	private ICalibration source2;

	private IParameterListInfo paramsInfo2;

	private StringCollection uniqueParameters2;

	private CalibrationDataSourceType dataSourceType2;

	private IParameterModel currentParam2;

	private int countParametersDiffer;

	private StringCollection allParameters;

	private StringCollection movedParameters;

	private StringCollection unprocessedParameters;

	private ArrayList arrayParameters;

	private ArrayList parametersListWithUnitDiffers;

	private ArrayList parametersListWithUnitDiffersValueSame;

	private ArrayList parametersListWithDataTypeMismatch;

	private CompareCLI doc;

	public CompareReporter()
	{
		uniqueParameters1 = new StringCollection();
		uniqueParameters2 = new StringCollection();
		allParameters = new StringCollection();
		movedParameters = new StringCollection();
		unprocessedParameters = new StringCollection();
		arrayParameters = new ArrayList();
		parametersListWithUnitDiffers = new ArrayList();
		parametersListWithUnitDiffersValueSame = new ArrayList();
		parametersListWithDataTypeMismatch = new ArrayList();
	}

	public void Process(Configuration prefs, ICalibration source1, ICalibration source2)
	{
		//IL_0270: Unknown result type (might be due to invalid IL or missing references)
		uniqueParameters1.Clear();
		uniqueParameters2.Clear();
		allParameters.Clear();
		movedParameters.Clear();
		arrayParameters.Clear();
		unprocessedParameters.Clear();
		parametersListWithUnitDiffers.Clear();
		parametersListWithUnitDiffersValueSame.Clear();
		parametersListWithDataTypeMismatch.Clear();
		dataSourceType1 = ((!(source1.GetType() == typeof(CalibrationExport))) ? CalibrationDataSourceType.Calibration : CalibrationDataSourceType.ImportExport);
		dataSourceType2 = ((!(source2.GetType() == typeof(CalibrationExport))) ? CalibrationDataSourceType.Calibration : CalibrationDataSourceType.ImportExport);
		RangeLimit outOfRangeLimit = source2.CalibrationDataServer.OutOfRangeLimit;
		source2.CalibrationDataServer.OutOfRangeLimit = RangeLimit.Ignore;
		RaiseStatusUpdateEvent("StatusHeader");
		this.source1 = source1;
		paramsInfo1 = source1.ParametersInfo;
		this.source2 = source2;
		paramsInfo2 = source2.ParametersInfo;
		preferences = prefs;
		writer = OpenReport("compare");
		try
		{
			GenerateParameterLists();
			WriteHeader(source1, source2);
			WriteUniqueParametersReport();
			WriteMovedParametersReport();
			WriteParameterReport();
			WriteUnitDifferences();
			WriteUnitDifferenceWithSameValue();
			WriteDataTypeMismatchParameters();
			WriteUnprocessedParameters();
			WriteMissingAxesInfo("SourceMissingAxes", source1.ParametersInfo.MissingAxesTables);
			WriteMissingAxesInfo("TargetMissingAxes", source2.ParametersInfo.MissingAxesTables);
			WriteSummary();
			CloseReport("Cummins.CalDocument.compare_", ".cmp.", prefs.ReportFilename);
			prefs.ResultMessage = "Number of parameters processed : " + allParameters.Count + " .Number of parameter differences : " + countParametersDiffer + ".";
		}
		catch (UserCancelException)
		{
			DiscardReport();
		}
		catch (Exception ex2)
		{
			if (ReportPath != null)
			{
				Console.WriteLine("Calibration comparison encountered an error!" + Environment.NewLine + Environment.NewLine + "Details: " + ex2.ToString());
			}
			else
			{
				MessageBox.Show("Calibration comparison encountered an error!" + Environment.NewLine + Environment.NewLine + "Details: " + ex2.ToString());
			}
		}
		finally
		{
			uniqueParameters1.Clear();
			uniqueParameters2.Clear();
			allParameters.Clear();
			unprocessedParameters.Clear();
			RaiseProgressCompleteEvent();
			source2.CalibrationDataServer.OutOfRangeLimit = outOfRangeLimit;
		}
	}

	private void GenerateParameterLists()
	{
		StringEnumerator enumerator = paramsInfo1.IncludedParameters.GetEnumerator();
		try
		{
			while (enumerator.MoveNext())
			{
				string current = enumerator.Current;
				uniqueParameters1.Add(current);
				allParameters.Add(current);
			}
		}
		finally
		{
			if (enumerator is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}
		short num = (short)((source1 is ISubfile) ? (source1 as ISubfile).SubfileType : (-1));
		StringEnumerator enumerator2 = paramsInfo2.IncludedParameters.GetEnumerator();
		try
		{
			while (enumerator2.MoveNext())
			{
				string current2 = enumerator2.Current;
				if (num == -1 || num.ToString() == paramsInfo2[current2].SubfileName)
				{
					uniqueParameters2.Add(current2);
					if (!allParameters.Contains(current2))
					{
						allParameters.Add(current2);
					}
				}
			}
		}
		finally
		{
			if (enumerator2 is IDisposable disposable2)
			{
				disposable2.Dispose();
			}
		}
		StringEnumerator enumerator3 = allParameters.GetEnumerator();
		try
		{
			while (enumerator3.MoveNext())
			{
				string current3 = enumerator3.Current;
				if (uniqueParameters1.Contains(current3) && uniqueParameters2.Contains(current3))
				{
					uniqueParameters1.Remove(current3);
					uniqueParameters2.Remove(current3);
					if (paramsInfo1[current3].SubfileName != paramsInfo2[current3].SubfileName)
					{
						movedParameters.Add(current3);
					}
				}
			}
		}
		finally
		{
			if (enumerator3 is IDisposable disposable3)
			{
				disposable3.Dispose();
			}
		}
	}

	private void WriteSubfileNames(ICalibration source1, ICalibration source2)
	{
		((XmlWriter)writer).WriteStartElement("CalibrationSubfiles");
		int num = 8;
		if (source1.ProductID == "IND" && source2.ProductID == "IND")
		{
			num = 4;
		}
		for (int i = 1; i <= num; i++)
		{
			((XmlWriter)writer).WriteStartElement("SubfileName");
			string subfileName = GetSubfileName(source1, i);
			string subfileName2 = GetSubfileName(source2, i);
			((XmlWriter)writer).WriteAttributeString("SourceSubfile", subfileName);
			((XmlWriter)writer).WriteAttributeString("TargetSubfile", subfileName2);
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private string GetFilterFileName()
	{
		string result = "None";
		try
		{
			string fileName = Path.GetFileName(AppDomain.CurrentDomain.SetupInformation.ConfigurationFile);
			if (fileName.Equals("CaltermCLI.exe.Config"))
			{
				string[] commandLineArgs = Environment.GetCommandLineArgs();
				for (int i = 0; i < commandLineArgs.Length; i++)
				{
					if (commandLineArgs[i].Substring(0, 2).ToLower() == "-g")
					{
						result = commandLineArgs[i].Substring(2);
					}
				}
			}
			else
			{
				IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
				result = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastFilterFile);
			}
		}
		catch (SystemException)
		{
			result = "None";
		}
		return result;
	}

	private void WriteHeader(ICalibration source1, ICalibration source2)
	{
		((XmlWriter)writer).WriteStartElement("header");
		((XmlWriter)writer).WriteAttributeString("date", DateTime.Now.ToShortDateString() + " " + DateTime.Now.ToLongTimeString());
		((XmlWriter)writer).WriteStartElement("calibration");
		((XmlWriter)writer).WriteElementString("data", source1.DataSourceName);
		if (!(source1 is CalibrationExport))
		{
			((XmlWriter)writer).WriteElementString("config", source1.CalibrationDataServer.ConfigFileName);
		}
		((XmlWriter)writer).WriteEndElement();
		((XmlWriter)writer).WriteStartElement("calibration");
		((XmlWriter)writer).WriteElementString("data", source2.DataSourceName);
		((XmlWriter)writer).WriteElementString("config", source2.CalibrationDataServer.ConfigFileName);
		((XmlWriter)writer).WriteElementString("FilterFileName", GetFilterFileName());
		((XmlWriter)writer).WriteEndElement();
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteUniqueParametersReport()
	{
		if (uniqueParameters1.Count + uniqueParameters2.Count <= 0)
		{
			return;
		}
		((XmlWriter)writer).WriteStartElement("uniqueParameterReport");
		if (uniqueParameters1.Count > 0)
		{
			string[] array = new string[uniqueParameters1.Count];
			int num = 0;
			StringEnumerator enumerator = uniqueParameters1.GetEnumerator();
			try
			{
				while (enumerator.MoveNext())
				{
					string current = enumerator.Current;
					countParametersDiffer++;
					array[num++] = current;
				}
			}
			finally
			{
				if (enumerator is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
			Array.Sort(array);
			((XmlWriter)writer).WriteStartElement("first");
			for (num = 0; num < array.Length; num++)
			{
				((XmlWriter)writer).WriteElementString("name", array[num]);
			}
			((XmlWriter)writer).WriteEndElement();
		}
		if (uniqueParameters2.Count > 0)
		{
			string[] array2 = new string[uniqueParameters2.Count];
			int num2 = 0;
			StringEnumerator enumerator2 = uniqueParameters2.GetEnumerator();
			try
			{
				while (enumerator2.MoveNext())
				{
					string current2 = enumerator2.Current;
					countParametersDiffer++;
					array2[num2++] = current2;
				}
			}
			finally
			{
				if (enumerator2 is IDisposable disposable2)
				{
					disposable2.Dispose();
				}
			}
			Array.Sort(array2);
			((XmlWriter)writer).WriteStartElement("second");
			for (num2 = 0; num2 < array2.Length; num2++)
			{
				((XmlWriter)writer).WriteElementString("name", array2[num2]);
			}
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteMovedParametersReport()
	{
		if (movedParameters.Count <= 0)
		{
			return;
		}
		string[] array = new string[movedParameters.Count];
		int num = 0;
		StringEnumerator enumerator = movedParameters.GetEnumerator();
		try
		{
			while (enumerator.MoveNext())
			{
				string current = enumerator.Current;
				array[num++] = current;
			}
		}
		finally
		{
			if (enumerator is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}
		Array.Sort(array);
		((XmlWriter)writer).WriteStartElement("movedParameterReport");
		foreach (string text in array)
		{
			((XmlWriter)writer).WriteStartElement("movedParameter");
			((XmlWriter)writer).WriteAttributeString("name", text);
			((XmlWriter)writer).WriteAttributeString("subfile1", paramsInfo1[text].SubfileName);
			((XmlWriter)writer).WriteAttributeString("subfile2", paramsInfo2[text].SubfileName);
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteParameterReport()
	{
		((XmlWriter)writer).WriteStartElement("parameterReport");
		TreeViewSortingType sortType = ((!preferences.SortBySubfiles) ? (preferences.SortByGroups ? TreeViewSortingType.Group : TreeViewSortingType.Parameter) : TreeViewSortingType.Subfile);
		DataSet parameters = source1.Parameters;
		DataSet parameters2 = source2.Parameters;
		DataSet dataSet = new DataSet();
		dataSet.Merge(parameters, preserveChanges: true);
		dataSet.Merge(parameters2, preserveChanges: true);
		IParameterListInfo paramListInfo = new ParameterListInfo(dataSet, includeRuntime: false, Subfile3ParametersAddType.ExcludeCode, includeUnclaimedAxis: false);
		ParameterListViewData parameterListViewData = new ParameterListViewData();
		ArrayList orderedParameterList = ParameterListViewHelpers.GetOrderedParameterList(parameterListViewData, paramListInfo, allParameters, sortType);
		for (int i = 0; i < orderedParameterList.Count; i++)
		{
			if (i % 10 == 0)
			{
				RaiseProgressUpdateEvent(i, orderedParameterList.Count);
			}
			string text = (string)orderedParameterList[i];
			try
			{
				if (!uniqueParameters2.Contains(text))
				{
					currentParam1 = source1.Get(text);
				}
				else
				{
					currentParam1 = null;
				}
				if (!uniqueParameters1.Contains(text))
				{
					currentParam2 = source2.Get(text);
				}
				else
				{
					currentParam2 = null;
				}
				if (!IsAxisParameter(currentParam1, currentParam2) && ParameterType.Structure != GetPairType(currentParam1, currentParam2))
				{
					if (currentParam1 == null || currentParam2 == null)
					{
						CheckGroupAndSubfile(currentParam1, currentParam2);
						PreProcessWriteParamterToReport(currentParam1, currentParam2);
					}
					else
					{
						CompareAndWriteParameter();
					}
				}
			}
			catch
			{
			}
		}
		RaiseProgressUpdateEvent(allParameters.Count, allParameters.Count);
		WriteArrayParameter();
		CloseGroupAndSubfile();
		((XmlWriter)writer).WriteEndElement();
	}

	private void CompareAndWriteParameter()
	{
		if (currentParam1.DataType.Equals(currentParam2.DataType))
		{
			if (!currentParam1.EngineeringUnits.Equals(currentParam2.EngineeringUnits))
			{
				if (ConvertParameterUnits())
				{
					if (currentParam1.BaseConvertedEqual(currentParam2))
					{
						parametersListWithUnitDiffersValueSame.Add(new CompareParameters(currentParam1, currentParam2));
						return;
					}
					int newGroup = currentParam1.GroupNumber[currentParam1.GroupNumber.Length - 1];
					CheckGroupAndSubfile(newGroup, currentParam1.SubfileNumber, source1);
					PreProcessWriteParamterToReport(currentParam1, currentParam2);
					countParametersDiffer++;
				}
				else
				{
					parametersListWithUnitDiffers.Add(new CompareParameters(currentParam1, currentParam2));
					countParametersDiffer++;
				}
			}
			else if (!currentParam1.Equals(currentParam2))
			{
				int newGroup2 = currentParam1.GroupNumber[currentParam1.GroupNumber.Length - 1];
				CheckGroupAndSubfile(newGroup2, currentParam1.SubfileNumber, source1);
				PreProcessWriteParamterToReport(currentParam1, currentParam2);
				countParametersDiffer++;
			}
		}
		else
		{
			parametersListWithDataTypeMismatch.Add(new CompareParameters(currentParam1, currentParam2));
		}
	}

	private bool ConvertParameterUnits()
	{
		try
		{
			currentParam1.DisplayUnits = currentParam2.DisplayUnits;
		}
		catch
		{
			return false;
		}
		return true;
	}

	private void WriteParameter(IParameterModel param1, IParameterModel param2)
	{
		ParameterType pairType = GetPairType(param1, param2);
		try
		{
			switch (pairType)
			{
			case ParameterType.Value:
			case ParameterType.Enumeration:
				WriteValueParameter(param1 as IValueModel, param2 as IValueModel);
				break;
			case ParameterType.Array1D:
				((XmlWriter)writer).WriteStartElement("array");
				WriteAxis(param1 as IArray1DModel, param2 as IArray1DModel, "T");
				((XmlWriter)writer).WriteEndElement();
				break;
			case ParameterType.ArrayXY:
			{
				((XmlWriter)writer).WriteStartElement("arrayXYParameter");
				IArray1DModel param7 = ((param1 != null) ? ((IArrayAxis)param1).XAxis : null);
				IArray1DModel param8 = ((param2 != null) ? ((IArrayAxis)param2).XAxis : null);
				WriteAxis(param7, param8, "X");
				WriteAxis(param1 as IArray1DModel, param2 as IArray1DModel, "Y");
				((XmlWriter)writer).WriteEndElement();
				break;
			}
			case ParameterType.ArrayXYZ:
			{
				IArray1DModel param3 = ((param1 != null) ? ((IArrayAxis)param1).XAxis : null);
				IArray1DModel param4 = ((param2 != null) ? ((IArrayAxis)param2).XAxis : null);
				IArray1DModel param5 = ((param1 != null) ? ((IArrayAxis)param1).YAxis : null);
				IArray1DModel param6 = ((param2 != null) ? ((IArrayAxis)param2).YAxis : null);
				IArray2DModel array2DModel = param1 as IArray2DModel;
				IArray2DModel array2DModel2 = param2 as IArray2DModel;
				((XmlWriter)writer).WriteStartElement("arrayXYZParameter");
				((XmlWriter)writer).WriteAttributeString("FirstSource", (param1 == null) ? "0" : "1");
				((XmlWriter)writer).WriteAttributeString("SecondSource", (param2 == null) ? "0" : "1");
				WriteAxis(param3, param4, "X");
				WriteAxis(param5, param6, "Y");
				IArray2DModel array2DModel3 = ((array2DModel != null) ? array2DModel : array2DModel2);
				((XmlWriter)writer).WriteStartElement("axis");
				((XmlWriter)writer).WriteAttributeString("name", array2DModel3.Name);
				((XmlWriter)writer).WriteAttributeString("units1", (array2DModel != null) ? array2DModel.EngineeringUnits : "");
				((XmlWriter)writer).WriteAttributeString("units2", (array2DModel2 != null) ? array2DModel2.EngineeringUnits : "");
				if (dataSourceType1 != CalibrationDataSourceType.ImportExport)
				{
					((XmlWriter)writer).WriteAttributeString("comment", array2DModel3.Comment);
				}
				((XmlWriter)writer).WriteAttributeString("label", "Z");
				int num = MaxArraySize(param3, param4);
				int num2 = MaxArraySize(param5, param6);
				for (int i = 0; i < num; i++)
				{
					for (int j = 0; j < num2; j++)
					{
						try
						{
							((XmlWriter)writer).WriteStartElement("valuePair");
							WriteScaledValue(param1 as IArray2DModel, j, i);
							WriteScaledValue(param2 as IArray2DModel, j, i);
							((XmlWriter)writer).WriteEndElement();
						}
						catch (Exception)
						{
						}
					}
				}
				((XmlWriter)writer).WriteEndElement();
				((XmlWriter)writer).WriteEndElement();
				break;
			}
			case ParameterType.Array2D:
			case ParameterType.ArrayXAxis:
			case ParameterType.Group:
				break;
			}
		}
		catch (Exception)
		{
			((XmlWriter)writer).WriteEndElement();
			string value = ((param1 == null) ? param2.Name : param1.Name);
			unprocessedParameters.Add(value);
		}
	}

	private ParameterType GetPairType(IParameterModel param1, IParameterModel param2)
	{
		return param1?.DataType ?? param2.DataType;
	}

	private bool IsAxisParameter(IParameterModel param1, IParameterModel param2)
	{
		bool result = false;
		IParameterModel parameterModel = ((param1 == null) ? param2 : param1);
		try
		{
			result = parameterModel.DataSource.ParametersInfo[parameterModel.Name].IsAxis;
		}
		catch
		{
		}
		return result;
	}

	private void WriteValueParameter(IValueModel param1, IValueModel param2)
	{
		((XmlWriter)writer).WriteStartElement("valueParameter");
		IValueModel valueModel = ((param1 != null) ? param1 : param2);
		((XmlWriter)writer).WriteAttributeString("name", valueModel.Name);
		((XmlWriter)writer).WriteAttributeString("units1", (param1 != null) ? param1.EngineeringUnits : "");
		((XmlWriter)writer).WriteAttributeString("units2", (param2 != null) ? param2.EngineeringUnits : "");
		if (dataSourceType1 != CalibrationDataSourceType.ImportExport)
		{
			((XmlWriter)writer).WriteAttributeString("comment", valueModel.Comment);
		}
		((XmlWriter)writer).WriteStartElement("valuePair");
		try
		{
			WriteScaledValue(param1);
			WriteScaledValue(param2);
		}
		catch (Exception)
		{
		}
		((XmlWriter)writer).WriteEndElement();
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteAxis(IArray1DModel param1, IArray1DModel param2, string label)
	{
		IArray1DModel array1DModel = ((param1 != null) ? param1 : param2);
		int num = MaxArraySize(param1, param2);
		if (param1 == null && param2 == null)
		{
			((XmlWriter)writer).WriteStartElement("axis");
			((XmlWriter)writer).WriteAttributeString("comment", "Cal Defect: The '" + label + "'-Axes are missing from both calibrations.");
			((XmlWriter)writer).WriteEndElement();
			return;
		}
		((XmlWriter)writer).WriteStartElement("axis");
		((XmlWriter)writer).WriteAttributeString("name", array1DModel.Name);
		((XmlWriter)writer).WriteAttributeString("units1", (param1 != null) ? param1.EngineeringUnits : "");
		((XmlWriter)writer).WriteAttributeString("units2", (param2 != null) ? param2.EngineeringUnits : "");
		if (dataSourceType1 != CalibrationDataSourceType.ImportExport)
		{
			if (param1 == null)
			{
				((XmlWriter)writer).WriteAttributeString("comment", "Cal Defect: The '" + label + "'-Axis is missing from Source1 Calibration");
			}
			else if (param2 == null)
			{
				((XmlWriter)writer).WriteAttributeString("comment", "Cal Defect: The '" + label + "'-Axis is missing from Source2 Calibration");
			}
			else
			{
				((XmlWriter)writer).WriteAttributeString("comment", array1DModel.Comment);
			}
		}
		((XmlWriter)writer).WriteAttributeString("label", label);
		for (int i = 0; i < num; i++)
		{
			((XmlWriter)writer).WriteStartElement("valuePair");
			try
			{
				WriteScaledValue(param1, i);
				WriteScaledValue(param2, i);
			}
			catch (Exception)
			{
			}
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private int MaxArraySize(IArray1DModel param1, IArray1DModel param2)
	{
		int num = 0;
		if (param1 == null)
		{
			return param2.Count;
		}
		if (param2 == null)
		{
			return param1.Count;
		}
		return Math.Max(param1.Count, param2.Count);
	}

	private void WriteScaledValue(IArray2DModel param, int row, int col)
	{
		if (param != null)
		{
			try
			{
				((XmlWriter)writer).WriteElementString("value", param[col, row]);
				return;
			}
			catch (Exception)
			{
				((XmlWriter)writer).WriteElementString("value", "######");
				return;
			}
		}
		((XmlWriter)writer).WriteElementString("value", "######");
	}

	private void WriteScaledValue(IArray1DModel param, int index)
	{
		if (param != null)
		{
			try
			{
				((XmlWriter)writer).WriteElementString("value", param[index]);
				return;
			}
			catch (Exception)
			{
				((XmlWriter)writer).WriteElementString("value", "######");
				return;
			}
		}
		((XmlWriter)writer).WriteElementString("value", "######");
	}

	private void WriteScaledValue(IValueModel param)
	{
		if (param != null)
		{
			try
			{
				((XmlWriter)writer).WriteElementString("value", param.ScaledValue);
				return;
			}
			catch (Exception)
			{
				((XmlWriter)writer).WriteElementString("value", "######");
				return;
			}
		}
		((XmlWriter)writer).WriteElementString("value", "######");
	}

	private void WriteUnitDifferences()
	{
		((XmlWriter)writer).WriteStartElement("ParamterDiffersInUnitReport");
		for (int i = 0; i < parametersListWithUnitDiffers.Count; i++)
		{
			CompareParameters compareParameters = (CompareParameters)parametersListWithUnitDiffers[i];
			((XmlWriter)writer).WriteStartElement("ParamterDiffersInUnit");
			WriteParameter(compareParameters.param1, compareParameters.param2);
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteUnitDifferenceWithSameValue()
	{
		((XmlWriter)writer).WriteStartElement("ParamterDiffersInUnitSameValuesReport");
		for (int i = 0; i < parametersListWithUnitDiffersValueSame.Count; i++)
		{
			CompareParameters compareParameters = (CompareParameters)parametersListWithUnitDiffersValueSame[i];
			((XmlWriter)writer).WriteStartElement("ParamterDiffersInUnitSameValues");
			WriteParameter(compareParameters.param1, compareParameters.param2);
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteDataTypeMismatchParameters()
	{
		((XmlWriter)writer).WriteStartElement("ParamterDiffersInDataTypeReport");
		for (int i = 0; i < parametersListWithDataTypeMismatch.Count; i++)
		{
			CompareParameters compareParameters = (CompareParameters)parametersListWithDataTypeMismatch[i];
			((XmlWriter)writer).WriteStartElement("ParamterDiffersInDataType");
			((XmlWriter)writer).WriteAttributeString("name", compareParameters.param1.Name);
			((XmlWriter)writer).WriteAttributeString("datatype1", compareParameters.param1.DataType.ToString());
			((XmlWriter)writer).WriteAttributeString("datatype2", compareParameters.param2.DataType.ToString());
			((XmlWriter)writer).WriteAttributeString("units1", compareParameters.param1.EngineeringUnits);
			((XmlWriter)writer).WriteAttributeString("units2", compareParameters.param2.EngineeringUnits);
			((XmlWriter)writer).WriteEndElement();
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteUnprocessedParameters()
	{
		if (unprocessedParameters.Count > 0)
		{
			((XmlWriter)writer).WriteStartElement("unprocessedParameterReport");
			for (int i = 0; i < unprocessedParameters.Count; i++)
			{
				((XmlWriter)writer).WriteStartElement("first");
				((XmlWriter)writer).WriteElementString("name", unprocessedParameters[i]);
				((XmlWriter)writer).WriteEndElement();
			}
			((XmlWriter)writer).WriteEndElement();
		}
	}

	private void WriteSummary()
	{
		((XmlWriter)writer).WriteStartElement("Summary");
		((XmlWriter)writer).WriteElementString("Parameter_Processed", allParameters.Count.ToString());
		((XmlWriter)writer).WriteElementString("Number_Of_Parameter_Differences", countParametersDiffer.ToString());
		((XmlWriter)writer).WriteElementString("Unprocessed_Parameters", unprocessedParameters.Count.ToString());
		((XmlWriter)writer).WriteEndElement();
	}

	protected override void WriteArrayParameter()
	{
		for (int i = 0; i < arrayParameters.Count; i++)
		{
			CompareParameters compareParameters = (CompareParameters)arrayParameters[i];
			WriteParameter(compareParameters.param1, compareParameters.param2);
		}
		arrayParameters.Clear();
	}

	private string GetSubfileName(ICalibration source, int subfileNumber)
	{
		string text = "######";
		try
		{
			if (source.ProductID == "IND")
			{
				IValueModel valueModel = (IValueModel)source.Get(Reporter.FQFilePartNumber[subfileNumber - 1]);
				IValueModel valueModel2 = (IValueModel)source.Get(Reporter.FQFileVersion[subfileNumber - 1]);
				if (valueModel != null && valueModel2 != null)
				{
					text = valueModel.ScaledValue;
					text = text + "." + valueModel2.ScaledValue;
				}
			}
			else
			{
				IValueModel valueModel3 = (IValueModel)source.Get(Reporter.SubfileNames[subfileNumber - 1]);
				if (valueModel3 != null)
				{
					text = valueModel3.ScaledValue;
					text = text.Insert(text.Length - 3, ".");
				}
			}
		}
		catch
		{
		}
		return text;
	}

	private void DelayTheCompareForArrayParamters(IParameterModel param1, IParameterModel param2)
	{
		CompareParameters compareParameters = default(CompareParameters);
		compareParameters.param1 = param1;
		compareParameters.param2 = param2;
		arrayParameters.Add(compareParameters);
	}

	private void PreProcessWriteParamterToReport(IParameterModel param1, IParameterModel param2)
	{
		IParameterModel parameterModel = ((param1 == null) ? param2 : param1);
		if (parameterModel is IArrayModel)
		{
			DelayTheCompareForArrayParamters(param1, param2);
		}
		else
		{
			WriteParameter(param1, param2);
		}
	}
}
public class CompareWizard : BaseWizard
{
	private const string FileTypeSelectionStep = "CompareFileTypeSelectionStep";

	private const string SourceOneStepName = "Source1";

	private const string SourceTwoStepName = "Source2";

	private const string ConfigurationStepName = "Configuration";

	private const string FilterStepName = "Filter";

	private const string SourceStepOneDescription = "Select First Calibration";

	private const string SourceStepTwoDescription = "Select Second Calibration";

	private const string resourceFilename = "Cummins.CalDocument.strings";

	private IContainer components;

	private CompareFileTypeSelectionStep fileTypeSelectionStep;

	private CalibrationStep sourceOneStep;

	private CalibrationStep sourceTwoStep;

	private ConfigurationStep configurationStep;

	private FilterStep filterStep;

	private bool canFinish;

	private ResourceManager resourceManager;

	[Browsable(false)]
	public ICalibration SourceOne => sourceOneStep.Calibration;

	[Browsable(false)]
	public ICalibration SourceTwo => sourceTwoStep.Calibration;

	[Browsable(false)]
	public Configuration Configuration
	{
		get
		{
			return configurationStep.Configuration;
		}
		set
		{
			configurationStep.Configuration = value;
		}
	}

	[Description("Gets/Sets whether the finish button will be enabled")]
	[Browsable(true)]
	[Category("Wizard")]
	[DefaultValue(false)]
	public override bool FinishEnabled
	{
		get
		{
			return ((Control)finish).Enabled;
		}
		set
		{
			((Control)finish).Enabled = value && canFinish;
		}
	}

	private bool DifferentFileTypeSelection
	{
		get
		{
			bool flag = true;
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			string lastUsedValue = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastCompareFirstSourceType);
			string lastUsedValue2 = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastCompareSecondSourceType);
			if (fileTypeSelectionStep.FirstSourceType.ToString() == lastUsedValue && fileTypeSelectionStep.SecondSourceType.ToString() == lastUsedValue2)
			{
				return false;
			}
			return true;
		}
	}

	public CompareWizard()
	{
		InitializeComponent();
		IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		((Control)this).Text = "Calibration Compare-" + appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
		resourceManager = new ResourceManager("Cummins.CalDocument.strings", Assembly.GetExecutingAssembly());
		fileTypeSelectionStep = new CompareFileTypeSelectionStep();
		CalibrationFileStep calibrationFileStep = new CalibrationFileStep();
		calibrationFileStep.SetTitle = "Select First Calibration";
		calibrationFileStep.ValidateFileTypesEvent += OnValidateSourceFileTypes;
		sourceOneStep = calibrationFileStep;
		CalibrationFileStep calibrationFileStep2 = new CalibrationFileStep();
		calibrationFileStep2.SetTitle = "Select Second Calibration";
		calibrationFileStep2.ValidateFileTypesEvent += OnValidateTargetFileTypes;
		sourceTwoStep = calibrationFileStep2;
		configurationStep = new ConfigurationStep();
		filterStep = new FilterStep();
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		base.Dispose(disposing);
	}

	protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
	{
		//IL_000b: Unknown result type (might be due to invalid IL or missing references)
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		//IL_000f: Invalid comparison between Unknown and I4
		//IL_0011: Unknown result type (might be due to invalid IL or missing references)
		//IL_0017: Unknown result type (might be due to invalid IL or missing references)
		//IL_001d: Invalid comparison between Unknown and I4
		//IL_0045: Unknown result type (might be due to invalid IL or missing references)
		try
		{
			Keys val = (Keys)(int)((Message)(ref msg)).WParam;
			if ((int)val == 72 && (keyData & 0x20000) == 131072)
			{
				Help.ShowHelp((Control)(object)this, Application.StartupPath + "\\CaltermIII.chm", (HelpNavigator)(-2147483642), (object)"Compare");
			}
		}
		catch
		{
		}
		return ((Form)this).ProcessCmdKey(ref msg, keyData);
	}

	private void InitializeComponent()
	{
		((Control)wizardTop).SuspendLayout();
		((Control)this).SuspendLayout();
		((Control)wizardTop).Name = "wizardTop";
		((Control)wizardTop).Size = new Size(762, 64);
		((Control)cancel).Location = new Point(674, 409);
		((Control)cancel).Name = "cancel";
		((Control)back).Location = new Point(418, 409);
		((Control)back).Name = "back";
		((Control)next).Location = new Point(498, 409);
		((Control)next).Name = "next";
		((Control)panelStep).Name = "panelStep";
		((Control)panelStep).Size = new Size(746, 321);
		((Control)wizardLogo).Location = new Point(703, 0);
		((Control)wizardLogo).Name = "wizardLogo";
		((Control)topLine).Name = "topLine";
		((Control)topLine).Size = new Size(762, 2);
		((Control)bottomLine).Location = new Point(0, 401);
		((Control)bottomLine).Name = "bottomLine";
		((Control)bottomLine).Size = new Size(762, 2);
		((Control)wizardTitle).Name = "wizardTitle";
		((Control)finish).Location = new Point(586, 409);
		((Control)finish).Name = "finish";
		((Control)stepInfo).Name = "stepInfo";
		((Form)this).AutoScaleBaseSize = new Size(5, 13);
		((Form)this).ClientSize = new Size(762, 440);
		((Control)this).Name = "CompareWizard";
		((Control)this).Text = "Calibration Compare";
		LoadSteps += CompareWizard_LoadSteps;
		((Control)wizardTop).ResumeLayout(false);
		((Control)this).ResumeLayout(false);
	}

	public override void MoveNext()
	{
		//IL_0270: Unknown result type (might be due to invalid IL or missing references)
		//IL_0275: Invalid comparison between I4 and Unknown
		if (CurrentStep.NextStep == "Source1")
		{
			sourceOneStep.CalibrationFileSelectControl.CalibrationDataSourceType = fileTypeSelectionStep.FirstSourceType;
			sourceTwoStep.CalibrationFileSelectControl.CalibrationDataSourceType = fileTypeSelectionStep.SecondSourceType;
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			if (appConfigService != null && !DifferentFileTypeSelection)
			{
				if (File.Exists(appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastCompareFirstSourceConfigFile)))
				{
					sourceOneStep.CalibrationFileSelectControl.ConfigFilename = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastCompareFirstSourceConfigFile);
				}
				else
				{
					sourceOneStep.CalibrationFileSelectControl.ConfigFilename = "";
				}
				if (File.Exists(appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastCompareFirstSourceDataFile)))
				{
					sourceOneStep.CalibrationFileSelectControl.CalibrationFilename = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastCompareFirstSourceDataFile);
				}
				else
				{
					sourceOneStep.CalibrationFileSelectControl.CalibrationFilename = "";
				}
			}
		}
		if (CurrentStep.NextStep == "Source2")
		{
			sourceTwoStep.CalibrationFileSelectControl.CalibrationDataSourceType = fileTypeSelectionStep.SecondSourceType;
			IAppConfigService appConfigService2 = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting2 = appConfigService2.GetAppSetting(ApplicationSettings.LastProduct);
			if (appConfigService2 != null && !DifferentFileTypeSelection)
			{
				if (File.Exists(appConfigService2.GetLastUsedValue(appSetting2, LastUsedType.LastCompareSecondSourceConfigFile)))
				{
					sourceTwoStep.CalibrationFileSelectControl.ConfigFilename = appConfigService2.GetLastUsedValue(appSetting2, LastUsedType.LastCompareSecondSourceConfigFile);
				}
				else
				{
					sourceTwoStep.CalibrationFileSelectControl.ConfigFilename = "";
				}
				if (File.Exists(appConfigService2.GetLastUsedValue(appSetting2, LastUsedType.LastCompareSecondSourceCalFile)))
				{
					sourceTwoStep.CalibrationFileSelectControl.CalibrationFilename = appConfigService2.GetLastUsedValue(appSetting2, LastUsedType.LastCompareSecondSourceCalFile);
				}
				else
				{
					sourceTwoStep.CalibrationFileSelectControl.CalibrationFilename = "";
				}
			}
		}
		if (CurrentStep.NextStep != "Source1")
		{
			canFinish = true;
		}
		if (CurrentStep.NextStep == "FINISHED")
		{
			FinishEnabled = true;
		}
		try
		{
			base.MoveNext();
		}
		catch (UnableToReadFileException ex)
		{
			string text = ex.Message + " " + string.Format(resourceManager.GetString("SelectDifferentFile"), ex.FileType);
			if (6 == (int)MessageBox.Show(text, "Compare", (MessageBoxButtons)4, (MessageBoxIcon)16))
			{
				MoveTo("Source1", 1);
			}
			else
			{
				((Form)this).DialogResult = (DialogResult)2;
			}
		}
		catch (ProductNotSupportedException ex2)
		{
			string message = "Error in loading first datasource -  " + ex2.Message + ". " + string.Format(resourceManager.GetString("SelectDifferentFile"), "datasource");
			if (MsgBoxResult.Yes == MsgBox.Show(message, MsgBoxButtons.YesNo, MsgBoxIcon.Error))
			{
				MoveTo("Source1", 1);
			}
			else
			{
				((Form)this).DialogResult = (DialogResult)2;
			}
		}
	}

	public override void MoveBack()
	{
		if (CurrentStep.PreviousStep == "Source1" || CurrentStep.PreviousStep == "Source2")
		{
			canFinish = false;
		}
		base.MoveBack();
	}

	protected override void OnFinishClicked(EventArgs e)
	{
		//IL_00f7: Unknown result type (might be due to invalid IL or missing references)
		//IL_00fc: Invalid comparison between I4 and Unknown
		try
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			if (appConfigService != null)
			{
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
				fileTypeSelectionStep.SaveSettings();
				appConfigService.SetLastUsedValue(appSetting, sourceOneStep.CalibrationFileSelectControl.ConfigFilename, LastUsedType.LastCompareFirstSourceConfigFile);
				appConfigService.SetLastUsedValue(appSetting, sourceOneStep.CalibrationFileSelectControl.CalibrationFilename, LastUsedType.LastCompareFirstSourceDataFile);
				appConfigService.SetLastUsedValue(appSetting, sourceTwoStep.CalibrationFileSelectControl.ConfigFilename, LastUsedType.LastCompareSecondSourceConfigFile);
				appConfigService.SetLastUsedValue(appSetting, sourceTwoStep.CalibrationFileSelectControl.CalibrationFilename, LastUsedType.LastCompareSecondSourceCalFile);
			}
		}
		catch
		{
		}
		((Control)this).Cursor = Cursors.WaitCursor;
		try
		{
			filterStep.ApplyFilter();
			base.OnFinishClicked(e);
		}
		catch (UnableToReadFileException ex)
		{
			string text = ex.Message + " " + string.Format(resourceManager.GetString("SelectDifferentFile"), ex.FileType);
			if (6 == (int)MessageBox.Show(text, "Compare", (MessageBoxButtons)4, (MessageBoxIcon)16))
			{
				MoveTo("Source2", 2);
			}
			else
			{
				((Form)this).DialogResult = (DialogResult)2;
			}
		}
		catch (ProductNotSupportedException ex2)
		{
			string message = "Error in loading second datasource -  " + ex2.Message + ". " + string.Format(resourceManager.GetString("SelectDifferentFile"), "datasource");
			if (MsgBoxResult.Yes == MsgBox.Show(message, MsgBoxButtons.YesNo, MsgBoxIcon.Error))
			{
				MoveTo("Source2", 2);
			}
			else
			{
				((Form)this).DialogResult = (DialogResult)2;
			}
		}
		finally
		{
			((Control)this).Cursor = Cursors.Default;
		}
	}

	private void CompareWizard_LoadSteps(object sender, EventArgs e)
	{
		AddStep("CompareFileTypeSelectionStep", fileTypeSelectionStep);
		AddStep("Source1", sourceOneStep);
		AddStep("Source2", sourceTwoStep);
		AddStep("Configuration", configurationStep);
		AddStep("Filter", filterStep);
		FirstStepName = "CompareFileTypeSelectionStep";
		fileTypeSelectionStep.NextStep = "Source1";
		sourceOneStep.NextStep = "Source2";
		sourceOneStep.PreviousStep = "CompareFileTypeSelectionStep";
		sourceTwoStep.NextStep = "Configuration";
		sourceTwoStep.PreviousStep = "Source1";
		configurationStep.NextStep = "Filter";
		configurationStep.PreviousStep = "Source2";
		filterStep.NextStep = BaseStep.FinishStep;
		filterStep.PreviousStep = "Configuration";
	}

	private void OnValidateSourceFileTypes(CalibrationStep sender, EventArgs eventArgs)
	{
		ValidateFiles(sender);
	}

	private void OnValidateTargetFileTypes(CalibrationStep sender, EventArgs eventArgs)
	{
		//IL_00c9: Unknown result type (might be due to invalid IL or missing references)
		//IL_0157: Unknown result type (might be due to invalid IL or missing references)
		try
		{
			ValidateFiles(sender);
			FileValidator fileValidator = new FileValidator();
			string calibrationFilename = sourceOneStep.CalibrationFileSelectControl.CalibrationFilename;
			string calibrationFilename2 = sourceTwoStep.CalibrationFileSelectControl.CalibrationFilename;
			if (fileTypeSelectionStep.FirstSourceType != CalibrationDataSourceType.ImportExport)
			{
				fileValidator.CheckDataSourceGTISMatch(calibrationFilename, calibrationFilename2);
			}
			if (fileTypeSelectionStep.FirstSourceType == CalibrationDataSourceType.Subfile && fileTypeSelectionStep.SecondSourceType == CalibrationDataSourceType.Subfile)
			{
				fileValidator.ValidateSubfiles(calibrationFilename, calibrationFilename2);
			}
		}
		catch (GTISIncompatibilityException ex)
		{
			string text = string.Format(resourceManager.GetString("CalGTISVersionMismatch"), ex.FirstFileGTISLevel.ToString(), ex.SecondFileGTISLevel.ToString());
			string text2 = string.Format(resourceManager.GetString("ProjectName"), "Compare");
			MessageBox.Show(text, text2, (MessageBoxButtons)0, (MessageBoxIcon)16);
			throw ex;
		}
		catch (SubfileIncompatibilityException ex2)
		{
			string text3 = string.Format(resourceManager.GetString("SubfileTypeMismatch"), ex2.sourceSubfileName, ex2.sourceType.ToString(), ex2.targetSubfileName, ex2.targetType.ToString());
			string text4 = string.Format(resourceManager.GetString("ProjectName"), "Compare");
			MessageBox.Show(text3, text4, (MessageBoxButtons)0, (MessageBoxIcon)16);
			throw ex2;
		}
	}

	private void ValidateFiles(CalibrationStep calibrationStep)
	{
		//IL_00dc: Unknown result type (might be due to invalid IL or missing references)
		try
		{
			string configFilename = calibrationStep.CalibrationFileSelectControl.ConfigFilename;
			string calibrationFilename = calibrationStep.CalibrationFileSelectControl.CalibrationFilename;
			FileValidator fileValidator = new FileValidator();
			fileValidator.ValidateFiles(configFilename, calibrationFilename);
		}
		catch (InvalidConfigFileException ex)
		{
			ShowErrorMessageInValidateHandler(ex.InvalidFile, "Configuration");
			throw ex;
		}
		catch (InvalidDataFileException ex2)
		{
			ShowErrorMessageInValidateHandler(ex2.InvalidFile, "Calibration/Subfile");
			throw ex2;
		}
		catch (GTISIncompatibilityException ex3)
		{
			string text = string.Format(resourceManager.GetString("GTISVersionMismatch"), ex3.FirstFileName, ex3.FirstFileGTISLevel.ToString(), ex3.SecondFileName, ex3.SecondFileGTISLevel.ToString());
			string text2 = string.Format(resourceManager.GetString("ProjectName"), "Compare");
			MessageBox.Show(text, text2, (MessageBoxButtons)0, (MessageBoxIcon)16);
			throw ex3;
		}
	}

	private void ShowErrorMessageInValidateHandler(string fileName, string fileType)
	{
		//IL_0038: Unknown result type (might be due to invalid IL or missing references)
		string text = string.Format(resourceManager.GetString("InvalidFileFormat"), fileName, fileType);
		string text2 = string.Format(resourceManager.GetString("ProjectName"), "Compare");
		MessageBox.Show(text, text2, (MessageBoxButtons)0, (MessageBoxIcon)16);
	}
}
public enum ReportFormats
{
	XML,
	TXT,
	HTML
}
public enum ReportTypes
{
	Compare,
	Document
}
public class Configuration
{
	private const string DefaultComparePrefix = "compare";

	private const string DefaultDocumentPrefix = "caldoc";

	private const string DefaultPrefix = "unset";

	private bool sortByGroups;

	private bool sortBySubfiles;

	private string prefix;

	private ReportFormats outputFormat;

	private bool includeDataplate;

	private string reportFilename;

	private string resultMessage;

	private bool appendReport;

	public bool SortByGroups
	{
		get
		{
			return sortByGroups;
		}
		set
		{
			sortByGroups = value;
		}
	}

	public bool SortBySubfiles
	{
		get
		{
			return sortBySubfiles;
		}
		set
		{
			sortBySubfiles = value;
		}
	}

	public string Prefix
	{
		get
		{
			return prefix;
		}
		set
		{
			prefix = value;
		}
	}

	public ReportFormats OutputFormat
	{
		get
		{
			return outputFormat;
		}
		set
		{
			outputFormat = value;
		}
	}

	public bool IncludeDataplate
	{
		get
		{
			return includeDataplate;
		}
		set
		{
			includeDataplate = value;
		}
	}

	public string ReportFilename
	{
		get
		{
			return reportFilename;
		}
		set
		{
			reportFilename = value;
		}
	}

	public string ResultMessage
	{
		get
		{
			return resultMessage;
		}
		set
		{
			resultMessage = value;
		}
	}

	public bool AppendReport
	{
		get
		{
			return appendReport;
		}
		set
		{
			appendReport = value;
		}
	}

	public Configuration()
	{
	}

	public Configuration(ReportTypes reportType)
	{
		sortByGroups = true;
		sortBySubfiles = true;
		includeDataplate = true;
		outputFormat = ReportFormats.HTML;
		resultMessage = string.Empty;
		switch (reportType)
		{
		case ReportTypes.Compare:
			prefix = "compare";
			break;
		case ReportTypes.Document:
			prefix = "caldoc";
			break;
		default:
			prefix = "unset";
			break;
		}
	}
}
public class ConfigurationControl : UserControl, IPropertyPage
{
	private Label label1;

	private ComboBox format;

	private Label label2;

	private TextBox prefix;

	private CheckBox dataplate;

	private CheckBox subfiles;

	private CheckBox groups;

	private Container components;

	private string parentNode;

	private ErrorProvider prefixError;

	private string currentNode;

	string IPropertyPage.CurrentNode
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

	string IPropertyPage.ParentNode
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

	public bool ShowDataplateOption
	{
		get
		{
			return ((Control)dataplate).Visible;
		}
		set
		{
			((Control)dataplate).Visible = value;
		}
	}

	public bool SortBySubfiles
	{
		set
		{
			((Control)subfiles).Enabled = value;
			subfiles.Checked = value;
		}
	}

	public Configuration Configuration
	{
		get
		{
			Configuration configuration = new Configuration();
			configuration.SortByGroups = groups.Checked;
			configuration.SortBySubfiles = subfiles.Checked;
			configuration.IncludeDataplate = dataplate.Checked;
			configuration.Prefix = ((Control)prefix).Text;
			configuration.OutputFormat = (ReportFormats)Enum.Parse(typeof(ReportFormats), ((Control)format).Text);
			return configuration;
		}
		set
		{
			groups.Checked = value.SortByGroups;
			subfiles.Checked = value.SortBySubfiles;
			dataplate.Checked = value.IncludeDataplate;
			((Control)prefix).Text = value.Prefix;
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			if (appConfigService != null)
			{
				((Control)format).Text = appConfigService.GetAppSetting(ApplicationSettings.GeneralReportFormat);
			}
		}
	}

	public ConfigurationControl()
	{
		InitializeComponent();
		Initialize();
	}

	public ConfigurationControl(string parentNode, string currentNode)
	{
		InitializeComponent();
		Initialize();
		this.parentNode = parentNode;
		this.currentNode = currentNode;
	}

	void IPropertyPage.Initialize()
	{
	}

	void IPropertyPage.SetOptions()
	{
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		((ContainerControl)this).Dispose(disposing);
	}

	private void Initialize()
	{
		foreach (ReportFormats value in Enum.GetValues(typeof(ReportFormats)))
		{
			format.Items.Add((object)value.ToString());
		}
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
		//IL_0038: Unknown result type (might be due to invalid IL or missing references)
		//IL_0042: Expected O, but got Unknown
		//IL_0043: Unknown result type (might be due to invalid IL or missing references)
		//IL_004d: Expected O, but got Unknown
		//IL_004e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0058: Expected O, but got Unknown
		label1 = new Label();
		format = new ComboBox();
		label2 = new Label();
		prefix = new TextBox();
		dataplate = new CheckBox();
		subfiles = new CheckBox();
		groups = new CheckBox();
		prefixError = new ErrorProvider();
		((Control)this).SuspendLayout();
		((Control)label1).Location = new Point(8, 36);
		((Control)label1).Name = "label1";
		((Control)label1).Size = new Size(80, 23);
		((Control)label1).TabIndex = 2;
		((Control)label1).Text = "&Output Format:";
		format.DropDownStyle = (ComboBoxStyle)2;
		((Control)format).Location = new Point(143, 32);
		((Control)format).Name = "format";
		((Control)format).Size = new Size(121, 21);
		((Control)format).TabIndex = 3;
		((Control)label2).Location = new Point(8, 8);
		((Control)label2).Name = "label2";
		((Control)label2).Size = new Size(128, 23);
		((Control)label2).TabIndex = 0;
		((Control)label2).Text = "Report Filename &Prefix:";
		((Control)prefix).Location = new Point(144, 8);
		((Control)prefix).Name = "prefix";
		((Control)prefix).Size = new Size(120, 20);
		((Control)prefix).TabIndex = 1;
		((Control)prefix).Text = "";
		((Control)prefix).Validating += prefix_Validating;
		((Control)dataplate).Enabled = false;
		((Control)dataplate).Location = new Point(8, 64);
		((Control)dataplate).Name = "dataplate";
		((Control)dataplate).Size = new Size(256, 24);
		((Control)dataplate).TabIndex = 4;
		((Control)dataplate).Text = "Include &Dataplate";
		((Control)dataplate).Visible = false;
		((Control)subfiles).Location = new Point(8, 88);
		((Control)subfiles).Name = "subfiles";
		((Control)subfiles).Size = new Size(256, 24);
		((Control)subfiles).TabIndex = 5;
		((Control)subfiles).Text = "Sort by &subfiles";
		((Control)groups).Location = new Point(8, 112);
		((Control)groups).Name = "groups";
		((Control)groups).Size = new Size(256, 24);
		((Control)groups).TabIndex = 6;
		((Control)groups).Text = "Sort by &groups";
		prefixError.ContainerControl = (ContainerControl)(object)this;
		prefixError.DataMember = "";
		((Control)this).Controls.Add((Control)(object)groups);
		((Control)this).Controls.Add((Control)(object)subfiles);
		((Control)this).Controls.Add((Control)(object)dataplate);
		((Control)this).Controls.Add((Control)(object)prefix);
		((Control)this).Controls.Add((Control)(object)label2);
		((Control)this).Controls.Add((Control)(object)format);
		((Control)this).Controls.Add((Control)(object)label1);
		((Control)this).Name = "ConfigurationControl";
		((Control)this).Size = new Size(272, 136);
		((Control)this).ResumeLayout(false);
	}

	private void prefix_Validating(object sender, CancelEventArgs e)
	{
		if (((Control)prefix).Text.IndexOf(Path.AltDirectorySeparatorChar) != -1 || ((Control)prefix).Text.IndexOf(Path.DirectorySeparatorChar) != -1 || ((Control)prefix).Text.IndexOf(Path.PathSeparator) != -1 || ((Control)prefix).Text.IndexOf(Path.VolumeSeparatorChar) != -1 || ((Control)prefix).Text.IndexOfAny(Path.InvalidPathChars) != -1)
		{
			e.Cancel = true;
			prefixError.SetError((Control)(object)prefix, "Invalid character in prefix");
		}
	}
}
public class ConfigurationStep : BaseStep
{
	private ConfigurationControl configurationControl1;

	private IContainer components;

	[Browsable(false)]
	public Configuration Configuration
	{
		get
		{
			return configurationControl1.Configuration;
		}
		set
		{
			configurationControl1.Configuration = value;
		}
	}

	public ConfigurationStep()
	{
		InitializeComponent();
		base.Description = "Configure the report process";
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
		configurationControl1 = new ConfigurationControl();
		((Control)this).SuspendLayout();
		((Control)configurationControl1).Location = new Point(24, 56);
		((Control)configurationControl1).Name = "configurationControl1";
		configurationControl1.ShowDataplateOption = true;
		((Control)configurationControl1).Size = new Size(270, 170);
		((Control)configurationControl1).TabIndex = 1;
		((Control)this).Controls.AddRange((Control[])(object)new Control[1] { (Control)configurationControl1 });
		((Control)this).Name = "ConfigurationStep";
		base.StepTitle = "Configure Report";
		base.ShowStep += ConfigurationStep_ShowStep;
		((Control)this).ResumeLayout(false);
	}

	private void ConfigurationStep_ShowStep(object sender, EventArgs e)
	{
		if (base.Wizard is CompareWizard)
		{
			CompareFileTypeSelectionStep compareFileTypeSelectionStep = (CompareFileTypeSelectionStep)base.Wizard.GetStep("CompareFileTypeSelectionStep");
			configurationControl1.SortBySubfiles = CalibrationDataSourceType.ImportExport != compareFileTypeSelectionStep.FirstSourceType;
		}
		base.Wizard.NextEnabled = true;
	}
}
public class DocumentCLI : ICommandLine
{
	private const string resourceFilename = "Cummins.CalDocument.strings";

	private Configuration documentConfig;

	private CalDocument doc;

	private ICalibration sourceCal;

	private string result;

	private bool successFlag;

	private string currentProduct;

	private string defaultSettingsList;

	private ComponentAccessor accessor;

	private ResourceManager resourceManager;

	private FilterView filterView;

	private string _reportPath;

	public ComponentAccessor DocumentAccessor
	{
		get
		{
			return accessor;
		}
		set
		{
			accessor = value;
		}
	}

	public event ProcessCompleteEventHandler ProcessCompleteEvent;

	public void SetReportPath(string value)
	{
		_reportPath = value;
	}

	public DocumentCLI()
	{
		resourceManager = new ResourceManager("Cummins.CalDocument.strings", Assembly.GetExecutingAssembly());
	}

	public void Start(DataSet argumentDataset)
	{
		throw new InvalidOperationException();
	}

	public void Start(XmlDocument xmlDoc)
	{
		successFlag = false;
		result = string.Empty;
		currentProduct = string.Empty;
		defaultSettingsList = string.Empty;
		DocumentAccessor = ComponentAccessor.CLI;
		try
		{
			doc = new CalDocument();
			doc.SetReportPath(_reportPath);
			documentConfig = new Configuration(ReportTypes.Document);
			SetConfiguration(xmlDoc);
			if (result == string.Empty)
			{
				doc.DocumentCLI(documentConfig, sourceCal);
				if (documentConfig.ResultMessage != string.Empty)
				{
					result += documentConfig.ResultMessage;
					successFlag = true;
				}
				else
				{
					result += " Execution Failed.";
					successFlag = false;
				}
			}
			else
			{
				result += " Execution Failed.";
				successFlag = false;
			}
			if (defaultSettingsList != string.Empty)
			{
				defaultSettingsList = defaultSettingsList.Trim();
				result = result + " Default values used for the following Configuration settings:" + defaultSettingsList.Remove(defaultSettingsList.Length - 1, 1);
			}
		}
		catch (Exception ex)
		{
			result = result + " " + ex.ToString();
		}
		finally
		{
			RaiseProcessCompleteEvent(successFlag, result);
		}
	}

	private void SetConfiguration(XmlDocument xmlDoc)
	{
		//IL_0027: Unknown result type (might be due to invalid IL or missing references)
		//IL_002e: Expected O, but got Unknown
		//IL_027d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0284: Expected O, but got Unknown
		string dataSourceFileName = string.Empty;
		string text = string.Empty;
		string text2 = string.Empty;
		XmlNodeList elementsByTagName = xmlDoc.GetElementsByTagName("Configuration");
		XmlElement val = (XmlElement)elementsByTagName.Item(0);
		if (val.HasAttribute("ReportPrefix"))
		{
			documentConfig.Prefix = val.GetAttribute("ReportPrefix");
		}
		else
		{
			documentConfig.Prefix = "caldoc";
		}
		if (val.HasAttribute("ReportFormat"))
		{
			documentConfig.OutputFormat = (ReportFormats)GetValue("ReportFormat", val.GetAttribute("ReportFormat").ToUpper(), typeof(ReportFormats), ReportFormats.HTML);
		}
		else
		{
			documentConfig.OutputFormat = ReportFormats.HTML;
		}
		if (val.HasAttribute("SortByGroups"))
		{
			documentConfig.SortByGroups = (bool)GetValue("SortByGroups", val.GetAttribute("SortByGroups"), typeof(bool), true);
		}
		else
		{
			documentConfig.SortByGroups = true;
		}
		if (val.HasAttribute("SortBySubfiles"))
		{
			documentConfig.SortBySubfiles = (bool)GetValue("SortBySubfiles", val.GetAttribute("SortBySubfiles"), typeof(bool), true);
		}
		else
		{
			documentConfig.SortBySubfiles = true;
		}
		if (val.HasAttribute("AppendReport"))
		{
			documentConfig.AppendReport = (bool)GetValue("AppendReport", val.GetAttribute("AppendReport"), typeof(bool), false);
		}
		else
		{
			documentConfig.AppendReport = false;
		}
		documentConfig.IncludeDataplate = true;
		CalibrationDataSourceType type;
		if (val.HasAttribute("SourceType"))
		{
			string text3 = val.GetAttribute("SourceType").ToLower();
			text3 = ((!(text3 == "import\\export")) ? (text3.Substring(0, 1).ToUpper() + text3.Substring(1).ToLower()) : "ImportExport");
			type = (CalibrationDataSourceType)GetValue("SourceType", text3, typeof(CalibrationDataSourceType), CalibrationDataSourceType.Calibration);
		}
		else
		{
			type = CalibrationDataSourceType.Calibration;
		}
		if (val.HasAttribute("Product"))
		{
			currentProduct = val.GetAttribute("Product");
		}
		foreach (XmlNode childNode in ((XmlNode)val).ChildNodes)
		{
			XmlNode val2 = childNode;
			switch (val2.Name)
			{
			case "SourceConfiguration":
				text = val2.InnerText;
				break;
			case "SourceCalibration":
				dataSourceFileName = val2.InnerText;
				break;
			case "ReportFilename":
				SetReportFilename(val2.InnerText);
				break;
			case "FilterFilename":
				if (val2.InnerText != string.Empty)
				{
					text2 = val2.InnerText;
				}
				break;
			}
		}
		try
		{
			new FileValidator();
			ValidateFiles(text, dataSourceFileName);
		}
		catch (Exception)
		{
			result += "File Format/CalConfigGTISMatch Validation failed.";
		}
		if (!(result == string.Empty))
		{
			return;
		}
		try
		{
			string empty = string.Empty;
			sourceCal = InitializeCalibration(type, text, dataSourceFileName);
			sourceCal.ParametersInfo.Subfile3Parameters = Subfile3ParametersAddType.ExcludeCode;
			if (File.Exists(text2))
			{
				filterView = new FilterView();
				filterView.InitializeData(sourceCal.ParametersInfo);
				filterView.LoadFilter(text2, accessFromCLI: true, ref empty);
				if (!string.IsNullOrEmpty(empty))
				{
					FilterFileParamtersNotFound(empty);
				}
				sourceCal.ParametersInfo.ApplyFilter(filterView.ParameterFilterMode == ParameterFilterMode.Include);
			}
			else
			{
				sourceCal.ParametersInfo.ApplyFilter(includeMode: false);
			}
		}
		catch (Exception ex2)
		{
			result = result + " Unable to initialize Calibration files." + ex2.ToString() + ex2.StackTrace;
		}
	}

	private void FilterFileParamtersNotFound(string parameterlist)
	{
		Console.WriteLine("Following parameters from filter file were not being used.");
		Console.WriteLine(parameterlist);
	}

	private object GetValue(string attributeName, string attributeValue, Type valueType, object defaultValue)
	{
		object obj = defaultValue;
		try
		{
			if (valueType.IsEnum)
			{
				obj = Enum.Parse(valueType, attributeValue);
			}
			else if (valueType.ToString() == "System.Boolean")
			{
				obj = bool.Parse(attributeValue);
			}
		}
		catch (Exception)
		{
			defaultSettingsList = defaultSettingsList + attributeName + ", ";
		}
		return obj;
	}

	private void CheckValidSubfiles(string sourceOneSubfile, string sourceTwoSubfile)
	{
		try
		{
			FileValidator fileValidator = new FileValidator();
			fileValidator.ValidateSubfiles(sourceOneSubfile, sourceTwoSubfile);
		}
		catch (SubfileIncompatibilityException ex)
		{
			result = string.Format(resourceManager.GetString("SubfileTypeMismatch"), ex.sourceSubfileName, ex.sourceType.ToString(), ex.targetSubfileName, ex.targetType.ToString());
			throw ex;
		}
	}

	private void ValidateFiles(string configFileName, string dataSourceFileName)
	{
		try
		{
			FileValidator fileValidator = new FileValidator();
			fileValidator.ValidateFiles(configFileName, dataSourceFileName);
		}
		catch (InvalidConfigFileException ex)
		{
			result = string.Format(resourceManager.GetString("InvalidFileFormat"), ex.InvalidFile, "Configuration");
			throw ex;
		}
		catch (InvalidDataFileException ex2)
		{
			result = string.Format(resourceManager.GetString("InvalidFileFormat"), ex2.InvalidFile, "Calibration/Subfile");
			throw ex2;
		}
		catch (GTISIncompatibilityException ex3)
		{
			result = "Configuration and Calibration files belong to different GTIS levels. Configfile = '" + ex3.FirstFileGTISLevel.ToString() + "'   CalFile = '" + ex3.SecondFileGTISLevel.ToString() + "'";
			throw ex3;
		}
	}

	private ICalibration InitializeCalibration(CalibrationDataSourceType type, string sourceConfig, string sourceCal)
	{
		ICalibration calibration = null;
		switch (type)
		{
		case CalibrationDataSourceType.Calibration:
		{
			IProgress progress = null;
			CalibrationFactory calibrationFactory = new CalibrationFactory();
			calibration = ((DocumentAccessor != ComponentAccessor.GUI) ? calibrationFactory.Create(sourceConfig, sourceCal, progress, currentProduct) : calibrationFactory.Create(sourceConfig, sourceCal, progress));
			break;
		}
		case CalibrationDataSourceType.Subfile:
			calibration = ((DocumentAccessor != ComponentAccessor.GUI) ? new SubfileDisk(sourceConfig, sourceCal, currentProduct) : new SubfileDisk(sourceConfig, sourceCal));
			break;
		case CalibrationDataSourceType.ImportExport:
			calibration = ((DocumentAccessor != ComponentAccessor.GUI) ? new CalibrationExport(sourceCal, currentProduct) : new CalibrationExport(sourceCal));
			break;
		default:
			result = "Invalid source File.";
			break;
		}
		return calibration;
	}

	private void SetReportFilename(string reportFilename)
	{
		if (reportFilename != string.Empty)
		{
			if (reportFilename.ToUpper().IndexOf(ReportFormats.HTML.ToString()) != -1)
			{
				documentConfig.OutputFormat = ReportFormats.HTML;
				documentConfig.ReportFilename = reportFilename;
			}
			else if (reportFilename.ToUpper().IndexOf(ReportFormats.TXT.ToString()) != -1)
			{
				documentConfig.OutputFormat = ReportFormats.TXT;
				documentConfig.ReportFilename = reportFilename;
			}
			else if (reportFilename.ToUpper().IndexOf(ReportFormats.XML.ToString()) != -1)
			{
				documentConfig.OutputFormat = ReportFormats.XML;
				documentConfig.ReportFilename = reportFilename;
			}
			else
			{
				documentConfig.OutputFormat = ReportFormats.HTML;
				documentConfig.ReportFilename = reportFilename + "." + documentConfig.OutputFormat;
			}
		}
		else
		{
			IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
			string path = directoryService.FolderName(FolderType.Product, currentProduct);
			documentConfig.ReportFilename = Utility.FindAvailableFilename(documentConfig.Prefix, "." + documentConfig.OutputFormat.ToString().ToLower(), path);
		}
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
public class DocumentReporter : Reporter
{
	internal delegate void ProcessDelegate(Configuration prefs, ICalibration source);

	private const string FilterFileOption = "-g";

	private const string TransformPrefix = "Cummins.CalDocument.document_";

	private const string TableLabel = "T";

	private const string XAxisLabel = "X";

	private const string YAxisLabel = "Y";

	private const string ZAxisLabel = "Z";

	private ICalibration calSource;

	private IParameterListInfo paramListInfo;

	private ArrayList arrayParameters;

	public DocumentReporter()
	{
		arrayParameters = new ArrayList();
	}

	public void Process(Configuration prefs, ICalibration source)
	{
		//IL_00bb: Unknown result type (might be due to invalid IL or missing references)
		calSource = source;
		paramListInfo = source.ParametersInfo;
		preferences = prefs;
		writer = OpenReport("document");
		try
		{
			WriteHeader();
			WriteParameterReport();
			WriteMissingAxesInfo("MissingAxes", source.ParametersInfo.MissingAxesTables);
			CloseReport("Cummins.CalDocument.document_", ".doc.", prefs.ReportFilename);
			prefs.ResultMessage = "Calibration document created at location : " + prefs.ReportFilename;
		}
		catch (UserCancelException)
		{
			DiscardReport();
		}
		catch (Exception ex2)
		{
			MessageBox.Show("Error occurred during generation of calibration document." + Environment.NewLine + Environment.NewLine + "Details: " + ex2.ToString());
		}
		finally
		{
			RaiseProgressCompleteEvent();
		}
	}

	private void WriteHeader()
	{
		RaiseStatusUpdateEvent("StatusHeader");
		((XmlWriter)writer).WriteStartElement("header");
		((XmlWriter)writer).WriteAttributeString("date", DateTime.Now.ToShortDateString() + " " + DateTime.Now.ToLongTimeString());
		((XmlWriter)writer).WriteStartElement("calibration");
		((XmlWriter)writer).WriteElementString("data", calSource.DataSourceName);
		((XmlWriter)writer).WriteElementString("config", calSource.CalibrationDataServer.ConfigFileName);
		((XmlWriter)writer).WriteElementString("FilterFileName", GetFilterFileName());
		((XmlWriter)writer).WriteEndElement();
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteParameterReport()
	{
		try
		{
			((XmlWriter)writer).WriteStartElement("parameterReport");
			RaiseStatusUpdateEvent("StatusParameters");
			ArrayList arrayList = ParameterListViewHelpers.GetOrderedParameterList(sortType: (!preferences.SortBySubfiles) ? (preferences.SortByGroups ? TreeViewSortingType.Group : TreeViewSortingType.Parameter) : TreeViewSortingType.Subfile, parameterListViewData: new ParameterListViewData(), paramListInfo: paramListInfo, paramList: paramListInfo.IncludedParameters);
			for (int i = 0; i < arrayList.Count; i++)
			{
				if (i % 10 == 0)
				{
					RaiseProgressUpdateEvent(i, arrayList.Count);
				}
				string parameterName = (string)arrayList[i];
				try
				{
					IParameterModel parameterModel = calSource.Get(parameterName);
					int newGroup = parameterModel.GroupNumber[parameterModel.GroupNumber.Length - 1];
					switch (parameterModel.DataType)
					{
					case ParameterType.Value:
					case ParameterType.Enumeration:
						CheckGroupAndSubfile(newGroup, parameterModel.SubfileNumber, calSource);
						WriteParameter(parameterModel);
						break;
					case ParameterType.Array1D:
					case ParameterType.ArrayXY:
					case ParameterType.ArrayXYZ:
						CheckGroupAndSubfile(newGroup, parameterModel.SubfileNumber, calSource);
						arrayParameters.Add(parameterModel);
						break;
					}
				}
				catch (UserCancelException)
				{
					throw new UserCancelException();
				}
				catch (Exception)
				{
				}
			}
			RaiseProgressUpdateEvent(arrayList.Count, arrayList.Count);
			WriteArrayParameter();
			CloseGroupAndSubfile();
			((XmlWriter)writer).WriteEndElement();
		}
		catch (Exception)
		{
			throw new UserCancelException();
		}
	}

	protected override void WriteArrayParameter()
	{
		for (int i = 0; i < arrayParameters.Count; i++)
		{
			WriteParameter((IParameterModel)arrayParameters[i]);
		}
		arrayParameters.Clear();
	}

	protected override void WriteSubfileName(int subfileNumber)
	{
	}

	private void WriteParameter(IParameterModel parameter)
	{
		try
		{
			switch (parameter.DataType)
			{
			case ParameterType.Value:
			case ParameterType.Enumeration:
			{
				IValueModel valueModel = parameter as IValueModel;
				((XmlWriter)writer).WriteStartElement("valueParameter");
				WriteCommonAttributes(valueModel);
				try
				{
					((XmlWriter)writer).WriteString(valueModel.ScaledValue);
				}
				catch (Exception)
				{
				}
				((XmlWriter)writer).WriteEndElement();
				break;
			}
			case ParameterType.Array1D:
			{
				IArray1DModel axis2 = parameter as IArray1DModel;
				((XmlWriter)writer).WriteStartElement("arrayXParameter");
				WriteAxis(axis2, "T");
				((XmlWriter)writer).WriteEndElement();
				break;
			}
			case ParameterType.ArrayXY:
			{
				IArray1DModel axis = parameter as IArray1DModel;
				IArray1DModel xAxis2 = ((IArrayAxis)parameter).XAxis;
				((XmlWriter)writer).WriteStartElement("arrayXYParameter");
				WriteAxis(xAxis2, "X");
				WriteAxis(axis, "Y");
				((XmlWriter)writer).WriteEndElement();
				break;
			}
			case ParameterType.ArrayXYZ:
			{
				IArray1DModel xAxis = ((IArrayAxis)parameter).XAxis;
				IArray1DModel yAxis = ((IArrayAxis)parameter).YAxis;
				IArray2DModel array2DModel = parameter as IArray2DModel;
				((XmlWriter)writer).WriteStartElement("arrayXYZParameter");
				WriteAxis(xAxis, "X");
				WriteAxis(yAxis, "Y");
				((XmlWriter)writer).WriteStartElement("axis");
				WriteCommonAttributes(array2DModel);
				((XmlWriter)writer).WriteAttributeString("label", "Z");
				try
				{
					for (int i = 0; i < xAxis.Count; i++)
					{
						for (int j = 0; j < yAxis.Count; j++)
						{
							((XmlWriter)writer).WriteElementString("value", array2DModel[i, j]);
						}
					}
				}
				catch (Exception)
				{
				}
				((XmlWriter)writer).WriteEndElement();
				((XmlWriter)writer).WriteEndElement();
				break;
			}
			case ParameterType.Array2D:
			case ParameterType.ArrayXAxis:
			case ParameterType.Group:
				break;
			}
		}
		catch (Exception)
		{
			throw new UserCancelException();
		}
	}

	private void WriteCommonAttributes(IParameterModel parameter)
	{
		((XmlWriter)writer).WriteAttributeString("name", parameter.Name);
		((XmlWriter)writer).WriteAttributeString("units", parameter.EngineeringUnits);
		((XmlWriter)writer).WriteAttributeString("comment", parameter.Comment);
	}

	private void WriteMissingAxis(string label)
	{
		((XmlWriter)writer).WriteStartElement("axis");
		((XmlWriter)writer).WriteAttributeString("comment", "ERROR: The '" + label + "'-Axis for this table is missing from config file.");
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteAxis(IArray1DModel axis, string label)
	{
		if (axis == null)
		{
			WriteMissingAxis(label);
			return;
		}
		((XmlWriter)writer).WriteStartElement("axis");
		WriteCommonAttributes(axis);
		((XmlWriter)writer).WriteAttributeString("label", label);
		try
		{
			for (int i = 0; i < axis.Count; i++)
			{
				((XmlWriter)writer).WriteElementString("value", axis[i]);
			}
		}
		catch (Exception)
		{
		}
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteDataplateReport()
	{
		((XmlWriter)writer).WriteStartElement("dataPlateReport");
		((XmlWriter)writer).WriteEndElement();
	}

	private void WriteDataplateItem(string itemName, string itemValue)
	{
		((XmlWriter)writer).WriteStartElement("dataPlateItem");
		((XmlWriter)writer).WriteElementString("name", itemName);
		((XmlWriter)writer).WriteElementString("value", itemValue);
		((XmlWriter)writer).WriteEndElement();
	}

	private string GetFilterFileName()
	{
		string result = "None";
		try
		{
			string fileName = Path.GetFileName(AppDomain.CurrentDomain.SetupInformation.ConfigurationFile);
			if (fileName.Equals("CaltermCLI.exe.Config"))
			{
				string[] commandLineArgs = Environment.GetCommandLineArgs();
				for (int i = 0; i < commandLineArgs.Length; i++)
				{
					if (commandLineArgs[i].Substring(0, 2).ToLower() == "-g")
					{
						result = commandLineArgs[i].Substring(2);
					}
				}
			}
			else
			{
				IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
				result = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastFilterFile);
			}
		}
		catch (SystemException)
		{
			result = "None";
		}
		return result;
	}
}
public class DocumentWizard : BaseWizard
{
	private const string resourceFilename = "Cummins.CalDocument.strings";

	private string SourceStepName = "Source1";

	private string ConfigurationStepName = "Configuration";

	private string FilterStepName = "Filter";

	private IContainer components;

	private CalibrationStep sourceStep;

	private ConfigurationStep configurationStep;

	private FilterStep filterStep;

	private ResourceManager resourceManager;

	[Browsable(false)]
	public ICalibration Calibration => sourceStep.Calibration;

	[Browsable(false)]
	public Configuration CurrentConfiguration
	{
		get
		{
			return configurationStep.Configuration;
		}
		set
		{
			configurationStep.Configuration = value;
		}
	}

	public DocumentWizard()
	{
		InitializeComponent();
		IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		((Control)this).Text = "Calibration Document-" + appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
		resourceManager = new ResourceManager("Cummins.CalDocument.strings", Assembly.GetExecutingAssembly());
		CalibrationFileStep calibrationFileStep = new CalibrationFileStep();
		calibrationFileStep.ValidateFileTypesEvent += OnValidateFileTypes;
		sourceStep = calibrationFileStep;
		configurationStep = new ConfigurationStep();
		filterStep = new FilterStep();
	}

	public DocumentWizard(ICalibrationECM[] modules)
	{
		InitializeComponent();
		resourceManager = new ResourceManager("Cummins.CalDocument.strings", Assembly.GetExecutingAssembly());
		sourceStep = new ModuleStep(modules);
		configurationStep = new ConfigurationStep();
		filterStep = new FilterStep();
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		base.Dispose(disposing);
	}

	protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
	{
		//IL_000b: Unknown result type (might be due to invalid IL or missing references)
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		//IL_000f: Invalid comparison between Unknown and I4
		//IL_0011: Unknown result type (might be due to invalid IL or missing references)
		//IL_0017: Unknown result type (might be due to invalid IL or missing references)
		//IL_001d: Invalid comparison between Unknown and I4
		//IL_0045: Unknown result type (might be due to invalid IL or missing references)
		try
		{
			Keys val = (Keys)(int)((Message)(ref msg)).WParam;
			if ((int)val == 72 && (keyData & 0x20000) == 131072)
			{
				Help.ShowHelp((Control)(object)this, Application.StartupPath + "\\CaltermIII.chm", (HelpNavigator)(-2147483642), (object)"Document");
			}
		}
		catch
		{
		}
		return ((Form)this).ProcessCmdKey(ref msg, keyData);
	}

	protected override void OnFinishClicked(EventArgs e)
	{
		//IL_00ae: Unknown result type (might be due to invalid IL or missing references)
		//IL_00b3: Invalid comparison between I4 and Unknown
		try
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			if (appConfigService != null)
			{
				if (sourceStep is CalibrationFileStep)
				{
					string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
					appConfigService.SetLastUsedValue(appSetting, sourceStep.CalibrationFileSelectControl.ConfigFilename, LastUsedType.LastDocumentConfigFile);
					appConfigService.SetLastUsedValue(appSetting, sourceStep.CalibrationFileSelectControl.CalibrationFilename, LastUsedType.LastDocumentSourceFile);
				}
				else if (sourceStep is ModuleStep)
				{
					((ModuleStep)sourceStep).SaveSettings();
				}
			}
		}
		catch
		{
		}
		try
		{
			filterStep.ApplyFilter();
			base.OnFinishClicked(e);
		}
		catch
		{
			if (6 == (int)MessageBox.Show("An unknown error occurred while loading calibration. Do you want to select different calibration ?", "Document", (MessageBoxButtons)4, (MessageBoxIcon)16))
			{
				MoveTo("temp", 1);
			}
			else
			{
				((Form)this).DialogResult = (DialogResult)2;
			}
		}
	}

	public override void MoveNext()
	{
		//IL_0042: Unknown result type (might be due to invalid IL or missing references)
		//IL_0047: Invalid comparison between I4 and Unknown
		try
		{
			base.MoveNext();
		}
		catch (UnableToReadFileException ex)
		{
			string text = ex.Message + " " + string.Format(resourceManager.GetString("SelectDifferentFile"), ex.FileType);
			if (6 == (int)MessageBox.Show(text, "Compare", (MessageBoxButtons)4, (MessageBoxIcon)16))
			{
				MoveTo("Source1", 1);
			}
			else
			{
				((Form)this).DialogResult = (DialogResult)2;
			}
		}
		catch (ProductNotSupportedException ex2)
		{
			string message = "Error in loading datasource -  " + ex2.Message + ". " + string.Format(resourceManager.GetString("SelectDifferentFile"), "datasource");
			if (MsgBoxResult.Yes == MsgBox.Show(message, MsgBoxButtons.YesNo, MsgBoxIcon.Error))
			{
				MoveTo("Source1", 1);
			}
			else
			{
				((Form)this).DialogResult = (DialogResult)2;
			}
		}
	}

	private void InitializeComponent()
	{
		((Control)wizardTop).SuspendLayout();
		((Control)this).SuspendLayout();
		((Control)wizardTop).Name = "wizardTop";
		((Control)wizardTop).Size = new Size(762, 64);
		((Control)cancel).Location = new Point(674, 409);
		((Control)cancel).Name = "cancel";
		((Control)back).Location = new Point(418, 409);
		((Control)back).Name = "back";
		((Control)next).Location = new Point(498, 409);
		((Control)next).Name = "next";
		((Control)panelStep).Name = "panelStep";
		((Control)panelStep).Size = new Size(746, 321);
		((Control)wizardLogo).Location = new Point(703, 0);
		((Control)wizardLogo).Name = "wizardLogo";
		((Control)topLine).Name = "topLine";
		((Control)topLine).Size = new Size(762, 2);
		((Control)bottomLine).Location = new Point(0, 401);
		((Control)bottomLine).Name = "bottomLine";
		((Control)bottomLine).Size = new Size(762, 2);
		((Control)wizardTitle).Name = "wizardTitle";
		((Control)wizardTitle).Text = "Calibration Document";
		((Control)finish).Location = new Point(586, 409);
		((Control)finish).Name = "finish";
		((Control)stepInfo).Name = "stepInfo";
		((Form)this).AutoScaleBaseSize = new Size(5, 13);
		((Form)this).ClientSize = new Size(762, 440);
		FinishEnabled = false;
		FirstStepName = "Source";
		((Control)this).Name = "DocumentWizard";
		((Control)this).Text = "Calibration Document";
		Title = "Calibration Document";
		LoadSteps += DocumentWizard_LoadSteps;
		((Control)wizardTop).ResumeLayout(false);
		((Control)this).ResumeLayout(false);
	}

	private void DocumentWizard_LoadSteps(object sender, EventArgs e)
	{
		AddStep(SourceStepName, sourceStep);
		AddStep(ConfigurationStepName, configurationStep);
		AddStep(FilterStepName, filterStep);
		FirstStepName = SourceStepName;
		sourceStep.NextStep = ConfigurationStepName;
		configurationStep.NextStep = FilterStepName;
		configurationStep.PreviousStep = SourceStepName;
		filterStep.NextStep = BaseStep.FinishStep;
		filterStep.PreviousStep = ConfigurationStepName;
		IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		if (appConfigService != null && sourceStep is CalibrationFileStep)
		{
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			if (File.Exists(appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastDocumentConfigFile)))
			{
				sourceStep.CalibrationFileSelectControl.ConfigFilename = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastDocumentConfigFile);
			}
			else
			{
				sourceStep.CalibrationFileSelectControl.ConfigFilename = "";
			}
			if (File.Exists(appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastDocumentSourceFile)))
			{
				sourceStep.CalibrationFileSelectControl.CalibrationFilename = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastDocumentSourceFile);
			}
			else
			{
				sourceStep.CalibrationFileSelectControl.CalibrationFilename = "";
			}
		}
	}

	private void OnValidateFileTypes(CalibrationStep sender, EventArgs e)
	{
		ValidateFiles(sender);
	}

	private void ShowErrorMessageInValidateHandler(string fileName, string fileType)
	{
		//IL_0038: Unknown result type (might be due to invalid IL or missing references)
		string text = string.Format(resourceManager.GetString("InvalidFileFormat"), fileName, fileType);
		string text2 = string.Format(resourceManager.GetString("ProjectName"), "Document");
		MessageBox.Show(text, text2, (MessageBoxButtons)0, (MessageBoxIcon)16);
	}

	private void ValidateFiles(CalibrationStep calibrationStep)
	{
		//IL_00dc: Unknown result type (might be due to invalid IL or missing references)
		try
		{
			string configFilename = calibrationStep.CalibrationFileSelectControl.ConfigFilename;
			string calibrationFilename = calibrationStep.CalibrationFileSelectControl.CalibrationFilename;
			FileValidator fileValidator = new FileValidator();
			fileValidator.ValidateFiles(configFilename, calibrationFilename);
		}
		catch (InvalidConfigFileException ex)
		{
			ShowErrorMessageInValidateHandler(ex.InvalidFile, "Configuration");
			throw ex;
		}
		catch (InvalidDataFileException ex2)
		{
			ShowErrorMessageInValidateHandler(ex2.InvalidFile, "Calibration/Subfile");
			throw ex2;
		}
		catch (GTISIncompatibilityException ex3)
		{
			string text = string.Format(resourceManager.GetString("GTISVersionMismatch"), ex3.FirstFileName, ex3.FirstFileGTISLevel.ToString(), ex3.SecondFileName, ex3.SecondFileGTISLevel.ToString());
			string text2 = string.Format(resourceManager.GetString("ProjectName"), "Document");
			MessageBox.Show(text, text2, (MessageBoxButtons)0, (MessageBoxIcon)16);
			throw ex3;
		}
	}
}
public class FileValidator
{
	public void ValidateFiles(string configFileName, string dataSourceFileName)
	{
		IFileProperties configFileProperties = null;
		if (configFileName != null && configFileName.Length != 0)
		{
			configFileProperties = CalDataSource.ConfigFileReader.GetFileProperties(configFileName);
		}
		IFileProperties dataSourceFileProperties = new FileProperties(dataSourceFileName);
		ValidateFiles(configFileProperties, dataSourceFileProperties);
	}

	public void ValidateFiles(IFileProperties configFileProperties, IFileProperties dataSourceFileProperties)
	{
		if (configFileProperties != null && configFileProperties.FileType != FileType.ConfigFile)
		{
			throw new InvalidConfigFileException(configFileProperties.FileName);
		}
		if (dataSourceFileProperties.FileType != FileType.Calibration && dataSourceFileProperties.FileType != FileType.Subfile && dataSourceFileProperties.FileType != FileType.ImportExport)
		{
			throw new InvalidDataFileException(dataSourceFileProperties.FileName);
		}
		if (dataSourceFileProperties.FileType != FileType.ImportExport)
		{
			CheckForCalConfigGTISMatch(configFileProperties, dataSourceFileProperties);
		}
	}

	public void ValidateSubfiles(string firstSubfile, string secondSubfile)
	{
		if (firstSubfile == null || firstSubfile.Length == 0 || secondSubfile == null || secondSubfile.Length == 0)
		{
			throw new ArgumentNullException();
		}
		ISubfileProperties firstSubfileProperties = new SubfileProperties(firstSubfile);
		ISubfileProperties secondSubfileProperties = new SubfileProperties(secondSubfile);
		ValidateSubfiles(firstSubfileProperties, secondSubfileProperties);
	}

	public void ValidateSubfiles(ISubfileProperties firstSubfileProperties, ISubfileProperties secondSubfileProperties)
	{
		if (firstSubfileProperties.SubfileType != secondSubfileProperties.SubfileType)
		{
			string errorDescription = "First Source and Second Source subfile types differ.";
			throw new SubfileIncompatibilityException(errorDescription, firstSubfileProperties.FileName, secondSubfileProperties.FileName, firstSubfileProperties.SubfileType, secondSubfileProperties.SubfileType);
		}
	}

	public void CheckDataSourceGTISMatch(string firstDataSourceName, string secondDataSourceName)
	{
		if (firstDataSourceName == null || firstDataSourceName.Length == 0 || secondDataSourceName == null || secondDataSourceName.Length == 0)
		{
			throw new ArgumentNullException();
		}
		IFileProperties firstDataSourceProperties = new FileProperties(firstDataSourceName);
		IFileProperties secondDataSourceProperties = new FileProperties(secondDataSourceName);
		CheckDataSourceGTISMatch(firstDataSourceProperties, secondDataSourceProperties);
	}

	public void CheckDataSourceGTISMatch(IFileProperties firstDataSourceProperties, IFileProperties secondDataSourceProperties)
	{
		if (firstDataSourceProperties.GTISLevel != secondDataSourceProperties.GTISLevel)
		{
			string errorDescription = "Configuration and Calibration files belong to different GTIS levels. Configfile = '" + firstDataSourceProperties.GTISLevel.ToString() + "'   CalFile = '" + secondDataSourceProperties.GTISLevel.ToString() + "'";
			throw new GTISIncompatibilityException(errorDescription, firstDataSourceProperties.FileName, secondDataSourceProperties.FileName, firstDataSourceProperties.GTISLevel, secondDataSourceProperties.GTISLevel);
		}
	}

	private void CheckForCalConfigGTISMatch(IFileProperties configFileProperties, IFileProperties calFileProperties)
	{
		if (configFileProperties.GTISLevel != calFileProperties.GTISLevel)
		{
			string errorDescription = "Configuration and Calibration files belong to different GTIS levels. Configfile = '" + configFileProperties.GTISLevel.ToString() + "'   CalFile = '" + calFileProperties.GTISLevel.ToString() + "'";
			throw new GTISIncompatibilityException(errorDescription, configFileProperties.FileName, calFileProperties.FileName, configFileProperties.GTISLevel, calFileProperties.GTISLevel);
		}
	}
}
public class FilterStep : BaseStep
{
	private ICalibration sourceCal1;

	private ICalibration sourceCal2;

	private IContainer components;

	private FilterView filterView;

	public FilterStep()
	{
		InitializeComponent();
		base.Description = "Select the parameters to include in the report";
		base.ShowStep += FilterStep_ShowStep;
	}

	public void ApplyFilter()
	{
		sourceCal1.ParametersInfo.ApplyFilter(filterView.ParameterFilterMode == ParameterFilterMode.Include);
		CalibrationStep calibrationStep = (CalibrationStep)base.Wizard.GetStep("Source2");
		if (calibrationStep != null)
		{
			sourceCal2 = calibrationStep.Calibration;
			sourceCal2.ParametersInfo.Subfile3Parameters = Subfile3ParametersAddType.ExcludeCode;
			if (sourceCal2 != null)
			{
				sourceCal2.ParametersInfo.SelectedParameters = sourceCal1.ParametersInfo.SelectedParameters;
				sourceCal2.ParametersInfo.ApplyFilter(filterView.ParameterFilterMode == ParameterFilterMode.Include);
			}
		}
	}

	private void FilterStep_ShowStep(object sender, EventArgs e)
	{
		Cursor current = Cursor.Current;
		try
		{
			Cursor.Current = Cursors.WaitCursor;
			CalibrationStep calibrationStep = (CalibrationStep)base.Wizard.GetStep("Source1");
			sourceCal1 = calibrationStep.Calibration;
			sourceCal1.ParametersInfo.Subfile3Parameters = Subfile3ParametersAddType.ExcludeCode;
			if (sourceCal1 != null)
			{
				filterView.InitializeData(sourceCal1.ParametersInfo);
			}
		}
		finally
		{
			Cursor.Current = current;
		}
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
		filterView = new FilterView();
		((Control)this).SuspendLayout();
		((Control)filterView).Location = new Point(0, 0);
		((Control)filterView).Name = "filterView";
		((Control)filterView).Size = new Size(752, 366);
		((Control)filterView).TabIndex = 0;
		((Control)this).Controls.Add((Control)(object)filterView);
		((Control)this).Name = "FilterStep";
		((Control)this).Size = new Size(768, 360);
		base.StepTitle = "Filter Parameters";
		((Control)this).ResumeLayout(false);
	}
}
public class ModuleStep : CalibrationStep
{
	private ListBox modules;

	private IContainer components;

	private ICalibrationECM[] knownModules;

	public override ICalibration Calibration => knownModules[((ListControl)modules).SelectedIndex];

	public ModuleStep(ICalibrationECM[] modules)
	{
		InitializeComponent();
		base.Description = "Select a module";
		foreach (ICalibrationECM calibrationECM in modules)
		{
			this.modules.Items.Add((object)calibrationECM.ToString());
		}
		((ListControl)this.modules).SelectedIndex = 0;
		knownModules = modules;
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
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_000b: Expected O, but got Unknown
		modules = new ListBox();
		((Control)this).SuspendLayout();
		((Control)modules).Location = new Point(40, 80);
		((Control)modules).Name = "modules";
		((Control)modules).Size = new Size(392, 95);
		((Control)modules).TabIndex = 1;
		modules.SelectedIndexChanged += Validate;
		((Control)this).Controls.Add((Control)(object)modules);
		((Control)this).Name = "ModuleStep";
		((UserControl)this).Load += ModuleStep_Load;
		base.ShowStep += Validate;
		((Control)this).ResumeLayout(false);
	}

	private void Validate(object sender, EventArgs e)
	{
		if (base.Wizard != null)
		{
			if (((ListControl)modules).SelectedIndex != -1)
			{
				base.Wizard.NextEnabled = true;
				base.Wizard.FinishEnabled = true;
			}
			else
			{
				base.Wizard.NextEnabled = false;
				base.Wizard.FinishEnabled = false;
			}
		}
	}

	private void ModuleStep_Load(object sender, EventArgs e)
	{
		try
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			modules.SelectedItem = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastDivideSourceFile);
		}
		catch
		{
		}
	}

	internal void SaveSettings()
	{
		try
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			appConfigService.SetLastUsedValue(appSetting, modules.SelectedItem.ToString(), LastUsedType.LastDocumentConfigFile);
		}
		catch
		{
		}
	}
}
public class ProgressUpdateEventArgs : EventArgs
{
	private int parametersProcessed;

	private int maxParameters;

	public int MaxParameters => maxParameters;

	public int ParametersProcessed => parametersProcessed;

	public ProgressUpdateEventArgs()
	{
	}

	public ProgressUpdateEventArgs(int elementsProcessed, int totalElements)
	{
		maxParameters = totalElements;
		parametersProcessed = elementsProcessed;
	}
}
public delegate void ProgressUpdateEventHandler(object caller, ProgressUpdateEventArgs args);
public delegate void StatusUpdateEventHandler(object caller, StatusUpdateEventArgs args);
public class StatusUpdateEventArgs : EventArgs
{
	private string statusMessage;

	public string StatusMessage
	{
		get
		{
			return statusMessage;
		}
		set
		{
			statusMessage = value;
		}
	}

	public StatusUpdateEventArgs()
	{
		statusMessage = "";
	}

	public StatusUpdateEventArgs(string message)
	{
		statusMessage = message;
	}
}
