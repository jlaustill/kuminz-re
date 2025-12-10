using System;
using System.Collections;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Runtime.Versioning;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using System.Xml;
using System.Xml.Schema;
using System.Xml.XPath;
using System.Xml.Xsl;
using CRC;
using Cummins.AssemblyInvoker;
using Cummins.Calibration;
using Cummins.EventLog;
using Cummins.Interop;
using Cummins.Interop.CalDataServer;
using Cummins.Interop.Error;
using Cummins.Interop.SubFiles;
using Cummins.Interop.SymbolicTree;
using Cummins.Launcher;
using Cummins.Parameter;
using Cummins.ProductInformationProvider;
using Cummins.Services;
using Cummins.Widgets;
using TSWizards;

[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyDescription("")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - CalDiv")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTitle("Poodle")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.CalDiv;

public class MessageInterruptEventArgs : EventArgs
{
	private string caption;

	private DialogResult result;

	private string message = "";

	private MessageBoxButtons buttons;

	private MessageBoxIcon icon;

	public string Caption => caption;

	public string Message => message;

	public MessageBoxButtons Buttons => buttons;

	public MessageBoxIcon Icon => icon;

	public DialogResult DialogResult
	{
		get
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			return result;
		}
		set
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0002: Unknown result type (might be due to invalid IL or missing references)
			result = value;
		}
	}

	public MessageInterruptEventArgs(string caption, string message, MessageBoxButtons buttons, MessageBoxIcon icon)
	{
		//IL_0020: Unknown result type (might be due to invalid IL or missing references)
		//IL_0021: Unknown result type (might be due to invalid IL or missing references)
		//IL_0027: Unknown result type (might be due to invalid IL or missing references)
		//IL_0029: Unknown result type (might be due to invalid IL or missing references)
		this.caption = caption;
		this.message = message;
		this.buttons = buttons;
		this.icon = icon;
	}
}
public delegate void ErrorOccuredEventHandler(object sender, ProcessCompleteEventArgs args);
public enum BitSize
{
	Sixteen = 4,
	ThirtyTwo = 8
}
public struct Block
{
	public uint Address;

	public uint Size;
}
public abstract class CalibrationDivide : Component
{
	private const string HeaderRecordFilename = "DEFAUL";

	private const short MaximumTableErrors = 50;

	private const short EffectCode = 0;

	private const short HeaderRecordNotesLength = 7;

	private const char SubfileCharacter = 'B';

	private const string FamilyGroup = "D00";

	private const int NumberOfSubfiles = 8;

	private const SpecialParameters CalibrationVersion = SpecialParameters.CalHeadersCalibration_version;

	protected const string CalibrationHeaders = "CalHeaders";

	private const SpecialParameters _BlockDataStructure = SpecialParameters.ConfigFile_Block_Data_Structure;

	private const string BlockAddressesAddressArray = "addressArray";

	private const string BlockLengthsLengthArray = "contentLengthArray";

	private const string ConfigurationFile = "ConfigFile";

	protected const SpecialParameters CalibrationDate = SpecialParameters.ConfigFile_CalibrationDate;

	private const string NumberOfBlocks = "numBlocks";

	private const SpecialParameters IndexTableAddress = SpecialParameters.CalHeadersIndex_table_address;

	public const string ResourceFilename = "Cummins.CalDiv.strings";

	protected const short CalibrationVersionLength = 8;

	protected const short CalibrationDateLength = 10;

	protected const char CalibrationDatePad = '0';

	protected const short RomDependentSubfileIndex = 2;

	protected const short RomDependentSubfile = 3;

	private const int TotalPercentage = 100;

	private const int SCNumberOfMinorOptions = 6;

	private const int DONumberOfMinorOptions = 2;

	private const int DOMajorOptionData = 1;

	private const string ECI_ROMDATE = "ConfigFile.ROM_DATE";

	private const string EarliestCalibrationDate = "010180";

	private const int maxHoleSizeAllowed = 3;

	private const int DataplateIndexTableNumber = 13;

	private const string ABCProduct = "ABC";

	protected const string DataPlateGroupFullName = "DataStructures.DataplateStructure";

	private int lastIndexTableNumber;

	protected HeaderBuilder headerBuilder;

	private IDirectoryService directoryService;

	private string[] dataPlateParameters = new string[1] { "Dataplate" };

	private static string[] ECISubfiles = new string[6] { "Engine Control", "Electronic Constants", "ROM Configuration", "Engine Configuration", "Sequencing", "Customer Specific" };

	private static string[] INDSubfiles = new string[4] { "Engine Control Data", "Electronic Constants", "Engine Control Code", "Application Constants" };

	private static string[] GENSubfiles = new string[8] { "Engine Control Data", "Electronic Constants", "Engine Control Code", "Engine Config Data", "Performance Control", "System Control Data", "Installation Trim", "Application Control" };

	private static string[] CESSubfiles = new string[8] { "AFTERTREATME CONTROL DATA", "AFM CONSTANTS DATA", "AFTERTREATME CONTROL CODE", "AFM CONFIGURATIO DATA", "AFM PFM CONTROL DATA", "AFM SYSTEM CONTROL DATA", "AFM ISN TRIM DATA", "AFM APL CONTROL DAT" };

	private ArrayList requestedSubfiles;

	protected ArrayList subfiles;

	protected ICalibrationDisk calibration;

	protected ICICalDataServer calDataSource;

	private string productID;

	private Container components;

	internal static ResourceManager resources;

	private string sourceCal;

	private string sourceConfig;

	private GTISVersion version;

	protected IndexTable gtisIndexTable;

	private uint holeSize;

	private int countOfCalDivideErrors;

	protected int[] earliestActivationVersionInConfigFile = new int[8];

	protected int[] latestIncompatibleDeactivationVersionNumberInConfigFile = new int[8];

	protected int[] latestDeactivationVersionNumberInConfigFile = new int[8];

	protected string[] earliestActivationDateInConfigFile = new string[8];

	protected string[] latestIncompatibleDeactivationDateInConfigFile = new string[8];

	protected string[] latestDeactivationDateInConfigFile = new string[8];

	private MajorOptionData[] majorOptionData;

	protected string result;

	private static string cliSuccessFailResult = string.Empty;

	private bool divideSuccess;

	public string ConfigurationFileName
	{
		get
		{
			return sourceConfig;
		}
		set
		{
			sourceConfig = value;
		}
	}

	public string CalibrationFileName
	{
		get
		{
			return sourceCal;
		}
		set
		{
			sourceCal = value;
		}
	}

	public GTISVersion GTISVersion
	{
		get
		{
			return version;
		}
		set
		{
			version = value;
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

	public ArrayList RequestedSubfiles
	{
		get
		{
			return requestedSubfiles;
		}
		set
		{
			requestedSubfiles = value;
		}
	}

	public string CLISuccessFailResult
	{
		get
		{
			return cliSuccessFailResult;
		}
		set
		{
			cliSuccessFailResult = value;
		}
	}

	public bool DivideSuccess
	{
		get
		{
			return divideSuccess;
		}
		set
		{
			divideSuccess = value;
		}
	}

	public abstract string BlockDataStructure { get; }

	public abstract IndexTable indexTable { get; }

	public abstract BitSize TRecordBitSize { get; }

	public abstract BitSize LRecordBitSize { get; }

	protected virtual string[] DataplateParameters => dataPlateParameters;

	protected MajorOptionData[] MajorOptions
	{
		get
		{
			if (majorOptionData == null)
			{
				IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
				int numberOfMajorOptions = productInformationService.GetNumberOfMajorOptions(productID);
				if (numberOfMajorOptions == 0)
				{
					throw new Exception("The product structure option data (SC/DO, PJ, etc) not found for selected Product ID (" + productID + ").");
				}
				majorOptionData = new MajorOptionData[numberOfMajorOptions];
				int num = 0;
				for (int i = 0; i < numberOfMajorOptions; i++)
				{
					majorOptionData[i] = default(MajorOptionData);
					majorOptionData[i].majorOptionType = productInformationService.GetMajorOption(productID, i);
					majorOptionData[i].description = majorOptionData[i].majorOptionType.ToString() + " Option";
					majorOptionData[i].optionCode = "";
					num = productInformationService.GetNumberOfFilesForOption(productID, majorOptionData[i].majorOptionType);
					majorOptionData[i].files = new FileData[num];
				}
			}
			return majorOptionData;
		}
	}

	public event ProgressUpdateEventHandler ProgressUpdateEvent;

	public event MessageUpdateEventHandler MessageUpdateEvent;

	public event InterruptEventHandler InterruptEvent;

	public event ProcessCompleteEventHandler ProcessCompleteEvent;

	public event ErrorOccuredEventHandler ErrorOccuredEvent;

	private void InitializeComponent()
	{
	}

	public CalibrationDivide()
	{
		InitializeComponent();
		components = new Container();
		requestedSubfiles = new ArrayList();
		subfiles = new ArrayList();
		resources = new ResourceManager("Cummins.CalDiv.strings", Assembly.GetExecutingAssembly());
		headerBuilder = new HeaderBuilder();
		directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
		ErrorOccuredEvent += OnErrorOccured;
	}

	public CalibrationDivide(IDirectoryService directoryservices)
		: this()
	{
		if (directoryservices != null)
		{
			directoryService = directoryservices;
		}
		resources = new ResourceManager("Cummins.CalDiv.strings", Assembly.GetExecutingAssembly());
	}

	private void ProcessDivide()
	{
		//IL_0258: Unknown result type (might be due to invalid IL or missing references)
		lock (this)
		{
			DivideSuccess = true;
			RaiseProgressUpdateEvent(0, "Initializing calibration");
			try
			{
				IProgress progress = null;
				CalibrationFactory calibrationFactory = new CalibrationFactory();
				calibration = calibrationFactory.Create(sourceConfig, sourceCal, progress, productID, shouldAddNonIDAccessible: true, shouldIncludeUnClaimedAxis: true);
				calibration.ParametersInfo.Subfile3Parameters = Subfile3ParametersAddType.IncludeAll;
				if (calibration.ProductID == null || calibration.ProductID.Length == 0)
				{
					calibration.ProductID = ProductID;
				}
				_ = calibration.ProductID != productID;
				ResetDataPlateParameters();
				ValidateCalibrationVersion();
				ValidateProductStructureOptionLength();
				RaiseProgressUpdateEvent(20, "Initializing index table");
				calDataSource = calibration.CalibrationDataServer.DataServer;
				AddParameterInformation();
				AddTabelType4Length();
				RaiseProgressUpdateEvent(30, "Validating index table");
				ValidateIndexTable();
				RaiseProgressUpdateEvent(40, "Creating subfiles");
				CreateSubfiles();
				RaiseProgressUpdateEvent(60, "Populating header records");
				PopulateHeaderRecords();
				RaiseProgressUpdateEvent(70, "Populating data records");
				PopulateDataRecords();
				RaiseProgressUpdateEvent(90, "Saving subfiles");
				WriteFiles();
				RaiseProgressUpdateEvent(100, "Completed");
				RaiseProcessCompleteEvent(DivideSuccess, CLISuccessFailResult);
			}
			catch (CalibrationDivideException ex)
			{
				EventLogger.Error("CalibrationDivide", resources.GetString("CalibrationDivideError"), ex);
				if (ex.InnerException != null)
				{
					CLISuccessFailResult = ex.InnerException.Message;
					RaiseMessageUpdateEvent(ex.InnerException.Message, MessageTypes.Warning);
				}
				else
				{
					CLISuccessFailResult = ex.Message;
					RaiseMessageUpdateEvent(resources.GetString("CalibrationDivideError") + " " + ex.Message, MessageTypes.Warning);
				}
				divideSuccess = false;
				RaiseErrorOccuredEvent(divideSuccess, CLISuccessFailResult);
			}
			catch (COMException ex2)
			{
				ICIErrorMessageSet iCIErrorMessageSet = new ErrorMessageSetClass();
				iCIErrorMessageSet.loadXML(ex2.Message);
				iCIErrorMessageSet.MoveFirst();
				EventLogger.Error("CalibrationDivide", iCIErrorMessageSet.description);
				MessageBox.Show(resources.GetString("CalibrationDivideError") + iCIErrorMessageSet.description, resources.GetString("ErrorCaption"), (MessageBoxButtons)0, (MessageBoxIcon)16);
				CLISuccessFailResult = $"{iCIErrorMessageSet.description}";
				divideSuccess = false;
				RaiseMessageUpdateEvent(resources.GetString("CalibrationDivideError") + iCIErrorMessageSet.description, MessageTypes.Information);
				RaiseErrorOccuredEvent(divideSuccess, CLISuccessFailResult);
			}
			catch (ThreadAbortException)
			{
				throw;
			}
			catch (Exception ex4)
			{
				EventLogger.Error("CalibrationDivide", resources.GetString("CalibrationDivideError"), ex4);
				MessageInterruptEventArgs eventArgs = new MessageInterruptEventArgs("Calibration Divide", ex4.Message, (MessageBoxButtons)0, (MessageBoxIcon)16);
				RaiseInteruppedEvent(this, eventArgs);
				RaiseMessageUpdateEvent(resources.GetString("CalibrationDivideError") + ex4.Message, MessageTypes.Warning);
				try
				{
					if (indexTable.ErrorMessage.Length > 0)
					{
						string[] array = indexTable.ErrorMessage.ToString().Split(new char[1] { '\n' }, StringSplitOptions.RemoveEmptyEntries);
						string[] array2 = array;
						foreach (string text in array2)
						{
							RaiseMessageUpdateEvent("*" + text, MessageTypes.Information);
						}
					}
				}
				catch
				{
				}
				CLISuccessFailResult = ex4.Message;
				divideSuccess = false;
				RaiseErrorOccuredEvent(divideSuccess, CLISuccessFailResult);
			}
		}
	}

	public void Divide()
	{
		//IL_00be: Unknown result type (might be due to invalid IL or missing references)
		try
		{
			if ("ABC" == productID)
			{
				string message = string.Format(resources.GetString("ProductNotSupported"), "ABC");
				throw new ProductNotSupportedException(CalibrationDivideMessageId.ProductNotSupported, message);
			}
			ProcessDivide();
		}
		catch (ProductNotSupportedException ex)
		{
			EventLogger.Error("Calibration Divide", "Divide Not Supported for ABC Product");
			RaiseMessageUpdateEvent("Divide Not Supported for ABC Product", MessageTypes.Warning);
			RaiseErrorOccuredEvent(flag: false, ex.Message);
		}
		catch (ThreadAbortException ex2)
		{
			EventLogger.Error("Calibration Divide", "User aborted the Divide Process");
			RaiseMessageUpdateEvent("User aborted the Divide Process", MessageTypes.Warning);
			RaiseErrorOccuredEvent(flag: false, ex2.Message);
		}
		catch (Exception ex3)
		{
			MessageBox.Show(resources.GetString("CalibrationDivideProcessError") + ex3, resources.GetString("ErrorCaption"), (MessageBoxButtons)0, (MessageBoxIcon)16);
		}
	}

	protected void RaiseProcessCompleteEvent(bool flag, string resultMessage)
	{
		if (this.ProcessCompleteEvent != null)
		{
			ProcessCompleteEventArgs args = new ProcessCompleteEventArgs(flag, resultMessage);
			this.ProcessCompleteEvent(this, args);
		}
	}

	protected void RaiseMessageUpdateEvent(string message, MessageTypes messagetype)
	{
		if (this.MessageUpdateEvent != null)
		{
			MessageUpdateEventArgs e = new MessageUpdateEventArgs();
			e.Message = message;
			e.MessageType = messagetype;
			this.MessageUpdateEvent(this, e);
		}
	}

	protected void RaiseProgressUpdateEvent(int progressPercentage, string message)
	{
		if (this.ProgressUpdateEvent != null)
		{
			ProgressUpdateEventArgs e = new ProgressUpdateEventArgs();
			e.UpdateMessage = message;
			e.UpdateValue = progressPercentage;
			this.ProgressUpdateEvent(this, e);
		}
	}

	protected void RaiseErrorOccuredEvent(bool flag, string resultMessage)
	{
		if (this.ErrorOccuredEvent != null)
		{
			ProcessCompleteEventArgs args = new ProcessCompleteEventArgs(flag, resultMessage);
			this.ErrorOccuredEvent(this, args);
		}
	}

	private void OnErrorOccured(object sender, ProcessCompleteEventArgs args)
	{
		RaiseProcessCompleteEvent(flag: false, args.resultString);
	}

	private void WriteFiles()
	{
		//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
		//IL_00b0: Invalid comparison between I4 and Unknown
		bool flag = true;
		int num = 1;
		MajorOptionData[] majorOptions = MajorOptions;
		int num2 = majorOptions.Length;
		_ = string.Empty;
		int num3 = 0;
		int num4 = 0;
		for (int i = 0; i < subfiles.Count; i++)
		{
			if (!flag)
			{
				break;
			}
			string text = "";
			_ = (Subfile)subfiles[i];
			text = ((subfiles[i] != null) ? ((Subfile)subfiles[i]).Write() : string.Empty);
			if (subfiles[i] != null && text == string.Empty)
			{
				if (7 == (int)MessageBox.Show(resources.GetString("WriteError"), resources.GetString("ErrorCaption"), (MessageBoxButtons)4, (MessageBoxIcon)16))
				{
					flag = false;
				}
				continue;
			}
			if (text != string.Empty)
			{
				RaiseMessageUpdateEvent(string.Format(resources.GetString("SubfileCreatedMessageFormat"), text), MessageTypes.Information);
			}
			if (num4 >= majorOptions[num3].files.Length)
			{
				num3++;
				num4 = 0;
			}
			majorOptions[num3].files[num4].fileType = num;
			majorOptions[num3].files[num4].name = text;
			string description;
			switch (productID)
			{
			case "IND":
				description = INDSubfiles[num - 1];
				break;
			case "ECI":
				description = ECISubfiles[num - 1];
				break;
			case "BFN":
			case "BFQ":
			case "BFZ":
			case "BGD":
				description = CESSubfiles[num - 1];
				break;
			default:
				description = GENSubfiles[num - 1];
				break;
			}
			majorOptions[num3].files[num4].description = description;
			num4++;
			num++;
		}
		if (flag && num3 == num2 - 1)
		{
			UpdateOptionsFile(majorOptions);
		}
	}

	protected virtual void PopulateDataRecords()
	{
	}

	private void PopulateHeaderRecords()
	{
		string[] notes = new string[7];
		foreach (Subfile subfile in subfiles)
		{
			if (subfile != null)
			{
				string headerRecord = headerBuilder.BuildBusinessRecord(Path.GetFileName(subfile.Filename), productID, 'B', "D00", 0);
				subfile.AddHeaderRecord(headerRecord);
				headerRecord = headerBuilder.BuildIdentificationRecord(subfile.SubfileType, HeaderBuilder.SubfileStatus.Unreleased);
				subfile.AddHeaderRecord(headerRecord);
				headerRecord = headerBuilder.BuildHeaderRecord("DEFAUL" + subfile.SubfileType, notes);
				subfile.AddHeaderRecord(headerRecord);
				if (subfile.SubfileType == 3)
				{
					AddROMHeaderRecords();
				}
			}
		}
		AddSoftwareVersionCompatibilityRecords(romDependentDesired: false);
		AddBlockDataStructureRecord();
		AddFixTableLengthRecords();
	}

	private void AddFixTableLengthRecords()
	{
		for (int i = 1; i < indexTable.Rows.Count; i++)
		{
			DataRow dataRow = indexTable.Rows[i];
			IndexTable.TableTypeEnum tableTypeEnum = (IndexTable.TableTypeEnum)dataRow["TableType"];
			if (tableTypeEnum == IndexTable.TableTypeEnum.TableType0 || IndexTable.TableTypeEnum.TableType2 == tableTypeEnum)
			{
				int index = (short)dataRow["SubfileType"] - 1;
				if (subfiles[index] != null)
				{
					bool sizeWord = (IndexTable.TableTypeEnum)dataRow["TableType"] == IndexTable.TableTypeEnum.TableType0;
					string headerRecord = headerBuilder.BuildFixTableLengthRecord(i, (uint)dataRow["Size"], sizeWord);
					((Subfile)subfiles[index]).AddHeaderRecord(headerRecord);
				}
			}
		}
	}

	private void AddBlockDataStructureRecord()
	{
		try
		{
			if (productID != "ECI")
			{
				int index = SubfileNumber(BlockDataStructure) - 1;
				if (subfiles[index] != null)
				{
					string headerRecord = headerBuilder.BuildBlockDataStructureRecord(indexTable.BDSTableNumber, indexTable.BDSBlockNumber);
					((Subfile)subfiles[index]).AddHeaderRecord(headerRecord);
				}
			}
		}
		catch
		{
			throw new CalibrationDivideException(CalibrationDivideMessageId.UnableToAddBlockDataStructureRecord, string.Format(resources.GetString("ParameterIsExpired"), BlockDataStructure));
		}
	}

	protected virtual void AddSoftwareVersionCompatibilityRecords(bool romDependentDesired)
	{
	}

	private void AddROMHeaderRecords()
	{
		AddSoftwareVersionCompatibilityRecords(romDependentDesired: true);
		AddIndexTableLocationAndLengthRecords();
		AddDataplateLocationRecord();
		AddGTISHeaderInformationRecords();
		AddTableLocationAndLengthRecords();
	}

	protected virtual void AddGTISHeaderInformationRecords()
	{
	}

	private void AddTableLocationAndLengthRecords()
	{
		int offset = 0;
		int num = 1;
		uint num2 = 0u;
		uint num3 = 0u;
		IndexTable.TableTypeEnum tableTypeEnum = IndexTable.TableTypeEnum.InvalidTableType;
		indexTable.Select("", "Address ASC");
		int count = indexTable.Rows.Count;
		for (int i = 1; i < count; i++)
		{
			if (num < count)
			{
				if (i == (int)indexTable.Rows[num]["TableNumber"])
				{
					DataRow dataRow = indexTable.Rows[num++];
					num2 = (uint)dataRow["Address"];
					num3 = (uint)dataRow["Size"];
					tableTypeEnum = (IndexTable.TableTypeEnum)dataRow["TableType"];
				}
				else
				{
					num2 = 0u;
					num3 = 0u;
					tableTypeEnum = IndexTable.TableTypeEnum.InvalidTableType;
				}
			}
			else
			{
				num2 = 0u;
				num3 = 0u;
				tableTypeEnum = IndexTable.TableTypeEnum.InvalidTableType;
			}
			string headerRecord = headerBuilder.BuildTableForcedLocationRecord(i, num2, offset, sizeWord: false, LRecordBitSize);
			((Subfile)subfiles[2]).AddHeaderRecord(headerRecord);
			if (tableTypeEnum != IndexTable.TableTypeEnum.TableType0 && IndexTable.TableTypeEnum.TableType2 != tableTypeEnum)
			{
				headerRecord = ((tableTypeEnum != IndexTable.TableTypeEnum.TableType1 && tableTypeEnum != IndexTable.TableTypeEnum.InvalidTableType) ? headerBuilder.BuildTruncateTableLengthRecod(i, num3, sizeWord: true, TRecordBitSize) : headerBuilder.BuildTruncateTableLengthRecod(i, num3, sizeWord: false, TRecordBitSize));
				((Subfile)subfiles[2]).AddHeaderRecord(headerRecord);
			}
		}
	}

	private void AddIndexTableLocationAndLengthRecords()
	{
		DataRow dataRow = indexTable.Rows[0];
		string headerRecord = headerBuilder.BuildTableForcedLocationRecord(0, (uint)dataRow["Address"], 0, sizeWord: true, LRecordBitSize);
		((Subfile)subfiles[2]).AddHeaderRecord(headerRecord);
		headerRecord = headerBuilder.BuildTruncateTableLengthRecod(0, indexTable.NumberOfTables, sizeWord: true, TRecordBitSize);
		((Subfile)subfiles[2]).AddHeaderRecord(headerRecord);
	}

	protected virtual void AddDataplateLocationRecord()
	{
	}

	private void AddParameterInformation()
	{
		StringBuilder stringBuilder = new StringBuilder();
		stringBuilder.Append("Address <> 0 AND ");
		stringBuilder.Append("TableNumber >= 0 ");
		lastIndexTableNumber = int.Parse(indexTable.Select(stringBuilder.ToString(), "TableNumber ASC")[^1]["TableNumber"].ToString());
		calibration.ParametersInfo.ResetSelectionStatus(selectionStatus: true);
		StringCollection selectedParameters = calibration.ParametersInfo.SelectedParameters;
		StringEnumerator enumerator = selectedParameters.GetEnumerator();
		try
		{
			while (enumerator.MoveNext())
			{
				string current = enumerator.Current;
				IParamInfo paramInfo = calibration.ParametersInfo[current];
				if (paramInfo != null && paramInfo.FullName.StartsWith("ConfigFile"))
				{
					SetActivationInformation(paramInfo);
					if (int.Parse(paramInfo.SubfileName) != 0 && paramInfo.IndexTable != 0)
					{
						indexTable[paramInfo.IndexTable]["TableType"] = GetTableType(paramInfo, lastIndexTableNumber);
					}
				}
			}
		}
		finally
		{
			if (enumerator is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}
		IParamInfo[] duplicatedParameters = calibration.DuplicatedParameters;
		IParamInfo[] array = duplicatedParameters;
		foreach (IParamInfo paramInfo2 in array)
		{
			if (paramInfo2 != null && paramInfo2.FullName.StartsWith("ConfigFile"))
			{
				SetActivationInformation(paramInfo2);
			}
		}
	}

	protected virtual void ValidateProductStructureOptionLength()
	{
	}

	protected abstract void SetActivationInformation(IParamInfo paramInfo);

	private void ResetDataPlateParameters()
	{
		try
		{
			for (int i = 0; i < DataplateParameters.Length; i++)
			{
				IGroupModel groupModel = (IGroupModel)calibration.Get(DataplateParameters[i]);
				foreach (string key in groupModel.Members.Keys)
				{
					switch (key)
					{
					case "_Product_ID":
					case "_System_Model":
					case "_Engine_Make":
					case "_OEM_Name":
					case "_OEM_Vehicle_Or_Equipment_Model":
					case "_ECM_Code":
					case "_Fuel_Code_Part_Number":
						continue;
					}
					try
					{
						IValueModel valueModel = (IValueModel)groupModel.Members[key];
						if (valueModel.ConfigFileType == 14)
						{
							byte[] array = new byte[valueModel.Length];
							for (int j = 0; j < array.Length; j++)
							{
								array[j] = 63;
							}
							valueModel.RawValue(array);
						}
						else
						{
							byte[] array2 = new byte[valueModel.Length * 2];
							for (int k = 0; k < array2.Length; k++)
							{
								array2[k] = 48;
							}
							valueModel.RawValue(array2);
						}
					}
					catch (Exception)
					{
					}
				}
			}
		}
		catch (Exception)
		{
		}
	}

	private IndexTable.TableTypeEnum GetTableType(IParamInfo symbolicData, int lastTableNumber)
	{
		bool flag = false;
		string text = "";
		lastIndexTableNumber = lastTableNumber;
		IndexTable.TableTypeEnum tableTypeEnum = IndexTable.TableTypeEnum.InvalidTableType;
		try
		{
			if (symbolicData.IndexTable > lastIndexTableNumber)
			{
				text = string.Format(resources.GetString("ITNOutOfRange"), symbolicData.Name, symbolicData.IndexTable, lastIndexTableNumber);
				throw new InvalidIndexTableNumberException(CalibrationDivideMessageId.IndexTableNumberOutOfRange, text);
			}
			indexTable[symbolicData.IndexTable]["SubfileType"] = int.Parse(symbolicData.SubfileName);
			switch (symbolicData.ConfigFileType)
			{
			case 10:
			case 11:
			case 22:
			{
				IParameterModel parameterModel = calibration.Get(symbolicData.Name);
				tableTypeEnum = ((!(parameterModel as IArrayModel).IsLegacyStyle) ? IndexTable.TableTypeEnum.TableType2 : IndexTable.TableTypeEnum.TableType0);
				break;
			}
			case 13:
			case 84:
			case 88:
			case 89:
				tableTypeEnum = IndexTable.TableTypeEnum.TableType0;
				break;
			case 12:
			case 70:
			case 90:
				tableTypeEnum = IndexTable.TableTypeEnum.TableType2;
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 8:
			case 9:
			case 14:
			case 17:
			case 66:
			case 67:
			case 78:
			case 79:
			case 83:
				tableTypeEnum = IndexTable.TableTypeEnum.TableType1;
				break;
			case 6:
			case 7:
			case 65:
				tableTypeEnum = IndexTable.TableTypeEnum.InvalidTableType;
				break;
			case 82:
				tableTypeEnum = IndexTable.TableTypeEnum.TableType3;
				break;
			case 76:
				tableTypeEnum = IndexTable.TableTypeEnum.TableType4;
				break;
			default:
				tableTypeEnum = IndexTable.TableTypeEnum.InvalidTableType;
				break;
			}
		}
		catch (InvalidIndexTableNumberException ex)
		{
			flag = true;
			ReportErrorMessage(ex.Message);
		}
		if (flag)
		{
			throw new InvalidIndexTableFormatException(CalibrationDivideMessageId.InvalidConfigFileEntries, "");
		}
		return tableTypeEnum;
	}

	protected byte[] ReadData(uint address, uint length, int offset = 0)
	{
		byte[] array = null;
		if (length == 0)
		{
			string message = "At least one parameter in the calibration is zero size. Divide process failed.\n";
			Exception ex = new Exception(message);
			throw ex;
		}
		array = new byte[length];
		try
		{
			IMemoryMapModel memoryMap = calibration.GetMemoryMap(address, length, offset);
			return memoryMap.RawValue();
		}
		catch (Exception ex2)
		{
			string message2 = $"Can not get at least one parameter's value because its address: {address} is out the range of the calibration\n";
			Exception ex3 = new Exception(message2, ex2.InnerException);
			throw ex3;
		}
	}

	protected virtual void AddTabelType4Length()
	{
	}

	private int Convert4Bytes(byte[] data, int index, ByteOrder byteOrder)
	{
		int num = 0;
		switch (byteOrder)
		{
		case ByteOrder.Motorola:
			num = data[index] * 16777216 + data[index + 1] * 65536 + data[index + 2] * 256 + data[index + 3];
			break;
		case ByteOrder.Intel:
			num = data[index + 3] * 16777216 + data[index + 2] * 65536 + data[index + 1] * 256 + data[index];
			break;
		}
		return num;
	}

	private int SubfileNumber(string parameter)
	{
		string empty = string.Empty;
		int num = parameter.IndexOf(".");
		empty = ((num == -1) ? parameter : parameter.Substring(num + 1, parameter.Length - num - 1));
		IParamInfo paramInfo = calibration.ParametersInfo[empty];
		return int.Parse(paramInfo.SubfileName);
	}

	private void UpdateOptionsFile(MajorOptionData[] data)
	{
		SelectionOptions selectionOptions = new SelectionOptions();
		selectionOptions.ProductID = productID;
		selectionOptions.SaveUnstructuredOptions(data, "");
	}

	public virtual void ValidateCalibrationVersion()
	{
		//IL_00dc: Unknown result type (might be due to invalid IL or missing references)
		//IL_00e1: Unknown result type (might be due to invalid IL or missing references)
		//IL_00e3: Unknown result type (might be due to invalid IL or missing references)
		//IL_00e6: Invalid comparison between Unknown and I4
		SpecialParameters parameter = SpecialParameters.ConfigHeadersCalibration_version;
		try
		{
			string calibrationVersion = GetCalibrationVersion();
			IValueModel valueModel = (IValueModel)calibration.Get(parameter);
			string text = valueModel.ScaledValue;
			if (version == GTISVersion.GTIS45)
			{
				string[] array = text.Split(new char[1] { '.' }, 4);
				string text2 = string.Empty;
				string[] array2 = array;
				foreach (string text3 in array2)
				{
					string text4 = text3;
					while (text4.Length < 2)
					{
						text4 = '0' + text3;
					}
					text2 += text4;
				}
				text = text2;
			}
			if (!text.Equals(calibrationVersion))
			{
				string text5 = resources.GetString("VersionMissMatch");
				MessageInterruptEventArgs e = new MessageInterruptEventArgs("Calibration Divide", text5 + " Do you want to continue?", (MessageBoxButtons)4, (MessageBoxIcon)48);
				this.InterruptEvent(this, e);
				DialogResult dialogResult = e.DialogResult;
				if ((int)dialogResult == 7)
				{
					throw new MisMatchedException(CalibrationDivideMessageId.CalibrationVersionMisMatched, text5);
				}
				RaiseMessageUpdateEvent(text5, MessageTypes.Warning);
			}
		}
		catch (MisMatchedException)
		{
			throw;
		}
		catch (Exception)
		{
		}
	}

	private void ValidateFilePath(string fullFilePath)
	{
		if (fullFilePath != "" && !File.Exists(fullFilePath))
		{
			throw new FileNotFoundException("Unable to find : " + fullFilePath);
		}
	}

	protected virtual void ValidateIndexTable()
	{
		if (GTISVersion != GTISVersion.GTIS45)
		{
			for (int i = 1; i <= indexTable.CountOfBlocks; i++)
			{
				StringBuilder stringBuilder = new StringBuilder();
				stringBuilder.Append("Address <> 0 AND ");
				stringBuilder.Append("TableNumber >= 0 AND ");
				stringBuilder.Append("BlockNumber = " + i);
				DataRow[] array = indexTable.Select(stringBuilder.ToString(), "Address ASC");
				for (int j = 1; j < array.Length; j++)
				{
					DataRow dataRow = array[j - 1];
					DataRow dataRow2 = array[j];
					uint num = (uint)dataRow["Address"] + (uint)dataRow["Size"];
					holeSize = (uint)dataRow2["Address"] - num;
					if (holeSize != 0 && holeSize > 3)
					{
						string format = "Hole of size {0} is found in the calibration between two index table entries {1}(0x{2:X}) and {3}(0x{4:x}).";
						string message = string.Format(format, holeSize, dataRow["TableNumber"], dataRow["Address"], dataRow2["TableNumber"], dataRow2["Address"]);
						RaiseMessageUpdateEvent(message, MessageTypes.Warning);
					}
				}
			}
		}
		bool flag = true;
		for (int k = 0; k < indexTable.Sections.Count; k++)
		{
			IndexTable.Section section = (IndexTable.Section)indexTable.Sections[k];
			for (int l = 0; l < section.count; l++)
			{
				DataRow dataRow3 = indexTable[(int)section.number + l];
				if (IndexTable.TableTypeEnum.InvalidTableType == (IndexTable.TableTypeEnum)dataRow3["TableType"])
				{
					flag = false;
					string message2 = string.Format(resources.GetString("InvalidTableFormat"), dataRow3["Address"], dataRow3["Size"], dataRow3["TableNumber"]);
					ReportErrorMessage(message2);
				}
				if (!IsAddressOutOfRange(uint.Parse(dataRow3["Address"].ToString())))
				{
					flag = false;
					string message3 = string.Format(resources.GetString("AddressOutOfRange"), dataRow3["TableNumber"], dataRow3["Address"], indexTable.BDSBlocks.Length);
					ReportErrorMessage(message3);
				}
			}
		}
		if (!flag)
		{
			throw new InvalidIndexTableFormatException(CalibrationDivideMessageId.InvalidConfigFileEntries, "");
		}
	}

	private bool IsAddressOutOfRange(uint address)
	{
		bool flag = false;
		Block[] bDSBlocks = indexTable.BDSBlocks;
		for (int i = 0; i < bDSBlocks.Length; i++)
		{
			uint num = bDSBlocks[i].Address + bDSBlocks[i].Size;
			if (address >= bDSBlocks[i].Address && address <= num)
			{
				flag = true;
				break;
			}
		}
		return flag;
	}

	protected void ReportErrorMessage(string Message)
	{
		if (countOfCalDivideErrors + 1 > 50)
		{
			string message = string.Format(resources.GetString("MaximumTableErrorsFormat"), (short)50);
			throw new MaxErrorReportedException(CalibrationDivideMessageId.MaxErrorLimitCrossed, message);
		}
		RaiseMessageUpdateEvent(Message, MessageTypes.Warning);
		countOfCalDivideErrors++;
	}

	protected string GetCalibrationDate()
	{
		uint num = 6u;
		string text = string.Empty;
		byte[] array = new byte[1];
		IParameterModel parameterModel = null;
		parameterModel = ((!(productID == "ECI")) ? calibration.Get(SpecialParameters.ConfigFile_CalibrationDate) : calibration.Get("ConfigFile.ROM_DATE"));
		IArray1DModel array1DModel = (IArray1DModel)parameterModel;
		if (productID != "ECI")
		{
			num = array1DModel.Length;
		}
		for (int i = 0; i < num; i++)
		{
			string s = array1DModel[i];
			if (productID == "ECI")
			{
				array[0] = byte.Parse(s, NumberStyles.Number);
			}
			else
			{
				array[0] = byte.Parse(s, NumberStyles.AllowHexSpecifier);
			}
			text += Encoding.ASCII.GetChars(array)[0];
		}
		return text;
	}

	protected string GetCalibrationVersion()
	{
		IValueModel valueModel = null;
		string empty = string.Empty;
		string text = string.Empty;
		SpecialParameters parameter = SpecialParameters.ConfigFile_Calibration_Version;
		SpecialParameters parameter2 = SpecialParameters.CalHeadersCalibration_version;
		try
		{
			valueModel = (IValueModel)calibration.Get(parameter);
			if (version.CompareTo(GTISVersion.GTIS45) == 0)
			{
				valueModel = (IValueModel)calibration.Get(parameter2);
				empty = valueModel.ScaledValue;
			}
			else if (valueModel == null)
			{
				valueModel = (IValueModel)calibration.Get(parameter2);
				empty = valueModel.ScaledValue;
			}
			else
			{
				empty = valueModel.ScaledValue;
			}
		}
		catch (NullReferenceException)
		{
			empty = "00.00.00.00";
		}
		string[] array = empty.Split(new char[1] { '.' }, 4);
		string[] array2 = array;
		foreach (string text2 in array2)
		{
			string text3 = text2;
			while (text3.Length < 2)
			{
				text3 = '0' + text2;
			}
			text += text3;
		}
		return text;
	}

	protected int CompareDates(string firstDate, string secondDate)
	{
		string text = ((firstDate == null) ? "010180" : ToDateFormat(firstDate));
		string strB = ((secondDate == null) ? "010180" : ToDateFormat(secondDate));
		return text.CompareTo(strB);
	}

	private string ToDateFormat(string data)
	{
		int num = int.Parse(string.Concat(data[4], data[5]));
		num += ((80 <= num && num <= 99) ? 1900 : 2000);
		string text = string.Concat(data[0], data[1], data[2], data[3]);
		return num + text;
	}

	protected void RaiseInteruppedEvent(object sender, MessageInterruptEventArgs eventArgs)
	{
		this.InterruptEvent(sender, eventArgs);
	}

	private void CreateSubfiles()
	{
		for (short num = 0; num < requestedSubfiles.Count; num++)
		{
			SubfileRequest subfileRequest = (SubfileRequest)requestedSubfiles[num];
			if (subfileRequest.Selected)
			{
				Subfile value = new Subfile((short)(num + 1), subfileRequest.Filename);
				subfiles.Add(value);
			}
			else
			{
				subfiles.Add(null);
			}
		}
	}
}
public interface IOfflineAccessible
{
	IProgress ProgressView { get; set; }

	event ProcessCompleteEventHandler ProcessCompleteEvent;

	void Initiate(DataSet configuration);

	void Cancel();
}
public class CalibrationDivideComponent : IOfflineAccessible
{
	private const string ResourceFilename = "Cummins.CalDiv.strings";

	private const int InitialRow = 0;

	private string calibrationFileName;

	private string configurationFileName;

	private string productID;

	private CalibrationDivide GTISDivider;

	private Thread divideThread;

	private Reporter reporter;

	private IProgress progressView;

	private GTISVersion gtisLevel;

	private ArrayList requestedSubfiles;

	private DivideConfigurationDataSet configuration;

	private string CLISuccessFailResult = string.Empty;

	private string reportfileName;

	private IDirectoryService directoryServices;

	private IAppConfigService appConfigService;

	private bool popReport;

	public IProgress ProgressView
	{
		get
		{
			return progressView;
		}
		set
		{
			progressView = value;
		}
	}

	public string CalibrationFileName
	{
		get
		{
			return calibrationFileName;
		}
		set
		{
			calibrationFileName = value;
		}
	}

	public string ConfigurationFileName
	{
		get
		{
			return configurationFileName;
		}
		set
		{
			configurationFileName = value;
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

	public event ProcessCompleteEventHandler ProcessCompleteEvent;

	public CalibrationDivideComponent(IDirectoryService directoryServices)
		: this()
	{
		this.directoryServices = directoryServices;
		progressView = new CaltermProgress("Calibration Divide", allowCancel: true);
	}

	public CalibrationDivideComponent()
	{
		appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		requestedSubfiles = new ArrayList();
	}

	public void Initiate(DataSet divideconfiguration)
	{
		if (divideconfiguration == null)
		{
			throw new ArgumentNullException();
		}
		configuration = divideconfiguration as DivideConfigurationDataSet;
		try
		{
			string empty = string.Empty;
			string empty2 = string.Empty;
			Reporter.Formats formats = Reporter.Formats.html;
			progressView.CancelProgressEvent += OnProgressCancelled;
			progressView.InterruptEvent += OnInterruptEvent;
			CalibrationFileName = configuration.DivideConfiguration.Rows[0]["CalibrationFileName"].ToString();
			ConfigurationFileName = configuration.DivideConfiguration.Rows[0]["ConfigurationFileName"].ToString();
			ProductID = configuration.DivideConfiguration.Rows[0]["productID"].ToString();
			string text = configuration.DivideConfiguration.Rows[0]["PopReport"].ToString();
			if (text.Equals("True"))
			{
				popReport = true;
			}
			else
			{
				popReport = false;
			}
			empty = configuration.ReporterInformation.Rows[0]["ReportPrefix"].ToString();
			empty2 = configuration.ReporterInformation.Rows[0]["ReportFormat"].ToString();
			reportfileName = configuration.ReporterInformation.Rows[0]["ReportFileName"].ToString();
			formats = (empty2.Equals("html") ? Reporter.Formats.html : Reporter.Formats.txt);
			if (reportfileName == null || reportfileName == "")
			{
				reportfileName = GetReportFileName(empty, formats);
			}
			bool appendReport = false;
			if (configuration.ReporterInformation.Rows[0]["AppendReportFile"] != DBNull.Value)
			{
				appendReport = (bool)configuration.ReporterInformation.Rows[0]["AppendReportFile"];
			}
			reporter = new Reporter(formats, empty, CalibrationFileName, ConfigurationFileName, ProductID, reportfileName, appendReport);
			CreateDivider();
			ConfigureDivider();
			divideThread = new Thread(GTISDivider.Divide);
			divideThread.Name = "Calibration Divide";
			divideThread.IsBackground = true;
			divideThread.Start();
			progressView.StartModal();
		}
		catch (Exception ex)
		{
			reporter.WriteMessage(ex.Message);
			RaiseProcessCompleteEvent(flag: false, ex.Message);
			reporter.Close(popReport);
			EventLogger.Error("Calibration Divide", "Divide Process Could not be completed Successfully", ex);
			progressView.Finish();
		}
	}

	public void Cancel()
	{
		divideThread.Abort();
	}

	protected void RaiseProcessCompleteEvent(bool flag, string resultMessage)
	{
		if (this.ProcessCompleteEvent != null)
		{
			ProcessCompleteEventArgs args = new ProcessCompleteEventArgs(flag, resultMessage);
			this.ProcessCompleteEvent(this, args);
		}
	}

	protected void OnInterruptEvent(object sender, EventArgs eventArgs)
	{
		//IL_001d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0023: Unknown result type (might be due to invalid IL or missing references)
		//IL_0028: Unknown result type (might be due to invalid IL or missing references)
		if (eventArgs is MessageInterruptEventArgs)
		{
			MessageInterruptEventArgs e = eventArgs as MessageInterruptEventArgs;
			e.DialogResult = MessageBox.Show(e.Message, e.Caption, e.Buttons, e.Icon);
		}
	}

	private void CreateDivider()
	{
		IFileProperties fileProperties = new FileProperties(CalibrationFileName);
		gtisLevel = fileProperties.GTISLevel;
		switch (gtisLevel)
		{
		case GTISVersion.GTIS45:
			GTISDivider = new GTIS45CalibrationDivide();
			break;
		case GTISVersion.GTIS38:
			GTISDivider = new GTIS38CalibrationDivide();
			break;
		case GTISVersion.PreGTIS:
		case GTISVersion.GTIS20:
			GTISDivider = new Pre38CalibrationDivide();
			break;
		default:
			throw new Cummins.Calibration.InvalidGTISLevelException(Facility.CalibrationDivide, 12);
		}
	}

	private void OnProgessInterrupt(object sender, MessageInterruptEventArgs e)
	{
		progressView.Interrupt(sender, e);
	}

	protected void OnProgressUpdate(object sender, ProgressUpdateEventArgs args)
	{
		progressView.SetProgress(100, args.UpdateValue, args.UpdateMessage);
	}

	protected void OnMessageUpdate(object sender, MessageUpdateEventArgs args)
	{
		if (args.MessageType != MessageTypes.Information)
		{
			CLISuccessFailResult = CLISuccessFailResult + Environment.NewLine + args.Message;
		}
		reporter.WriteMessage(args.Message);
	}

	protected void OnProcessComplete(object sender, ProcessCompleteEventArgs args)
	{
		reporter.Close(popReport);
		RaiseProcessCompleteEvent(args.success, CLISuccessFailResult);
		progressView.Finish();
	}

	protected void OnProgressCancelled(object sender, CancelEventArgs e)
	{
		divideThread.Abort();
	}

	private void ConfigureDivider()
	{
		GTISDivider.ProgressUpdateEvent += OnProgressUpdate;
		GTISDivider.InterruptEvent += OnProgessInterrupt;
		GTISDivider.MessageUpdateEvent += OnMessageUpdate;
		GTISDivider.ProcessCompleteEvent += OnProcessComplete;
		GTISDivider.CalibrationFileName = CalibrationFileName;
		GTISDivider.ConfigurationFileName = ConfigurationFileName;
		GTISDivider.GTISVersion = gtisLevel;
		GTISDivider.ProductID = ProductID;
		CreateSubfileInformation();
		GTISDivider.RequestedSubfiles = requestedSubfiles;
	}

	private string GetReportFileName(string prefix, Reporter.Formats format)
	{
		IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
		productInformationService.GetCalTermProduct(productID);
		IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
		string path = directoryService.FolderName(FolderType.Product, productID);
		return Utility.FindAvailableFilename(prefix, ".div." + format.ToString().ToLower(), path);
	}

	private void CreateSubfileInformation()
	{
		int count = configuration.SubfilesInformation.Rows.Count;
		for (int i = 0; i < count; i++)
		{
			string filename = configuration.SubfilesInformation.Rows[i]["SubfileName"].ToString();
			bool selected = bool.Parse(configuration.SubfilesInformation.Rows[i]["SubfileSelected"].ToString());
			requestedSubfiles.Add(new SubfileRequest(string.Empty, selected, filename));
		}
	}
}
public class Checksum
{
	private const string LinePrefix = ":";

	private const string CheckSumFormat = "X2";

	public static bool AddLineChecksum(ref string line)
	{
		return CRC.Checksum.AddLineChecksum(ref line);
	}
}
public class DivideCompleteEventArgs : EventArgs
{
	private bool divideResult;

	public bool DivideResult
	{
		get
		{
			return divideResult;
		}
		set
		{
			divideResult = value;
		}
	}
}
[Serializable]
[ToolboxItem(true)]
[DesignerCategory("code")]
[DebuggerStepThrough]
public class DivideConfigurationDataSet : DataSet
{
	public delegate void DivideConfigurationRowChangeEventHandler(object sender, DivideConfigurationRowChangeEvent e);

	public delegate void SubfilesInformationRowChangeEventHandler(object sender, SubfilesInformationRowChangeEvent e);

	public delegate void ReporterInformationRowChangeEventHandler(object sender, ReporterInformationRowChangeEvent e);

	[DebuggerStepThrough]
	public class DivideConfigurationDataTable : DataTable, IEnumerable
	{
		private DataColumn columnCalibrationFileName;

		private DataColumn columnConfigurationFileName;

		private DataColumn columnPopReport;

		private DataColumn columnproductID;

		private DataColumn columnDivideConfiguration_Id;

		[Browsable(false)]
		public int Count => base.Rows.Count;

		internal DataColumn CalibrationFileNameColumn => columnCalibrationFileName;

		internal DataColumn ConfigurationFileNameColumn => columnConfigurationFileName;

		internal DataColumn PopReportColumn => columnPopReport;

		internal DataColumn productIDColumn => columnproductID;

		internal DataColumn DivideConfiguration_IdColumn => columnDivideConfiguration_Id;

		public DivideConfigurationRow this[int index] => (DivideConfigurationRow)base.Rows[index];

		public event DivideConfigurationRowChangeEventHandler DivideConfigurationRowChanged;

		public event DivideConfigurationRowChangeEventHandler DivideConfigurationRowChanging;

		public event DivideConfigurationRowChangeEventHandler DivideConfigurationRowDeleted;

		public event DivideConfigurationRowChangeEventHandler DivideConfigurationRowDeleting;

		internal DivideConfigurationDataTable()
			: base("DivideConfiguration")
		{
			InitClass();
		}

		internal DivideConfigurationDataTable(DataTable table)
			: base(table.TableName)
		{
			if (table.CaseSensitive != table.DataSet.CaseSensitive)
			{
				base.CaseSensitive = table.CaseSensitive;
			}
			if (table.Locale.ToString() != table.DataSet.Locale.ToString())
			{
				base.Locale = table.Locale;
			}
			if (table.Namespace != table.DataSet.Namespace)
			{
				base.Namespace = table.Namespace;
			}
			base.Prefix = table.Prefix;
			base.MinimumCapacity = table.MinimumCapacity;
			base.DisplayExpression = table.DisplayExpression;
		}

		public void AddDivideConfigurationRow(DivideConfigurationRow row)
		{
			base.Rows.Add(row);
		}

		public DivideConfigurationRow AddDivideConfigurationRow(string CalibrationFileName, string ConfigurationFileName, string PopReport, string productID)
		{
			DivideConfigurationRow divideConfigurationRow = (DivideConfigurationRow)NewRow();
			divideConfigurationRow.ItemArray = new object[5] { CalibrationFileName, ConfigurationFileName, PopReport, productID, null };
			base.Rows.Add(divideConfigurationRow);
			return divideConfigurationRow;
		}

		public IEnumerator GetEnumerator()
		{
			return base.Rows.GetEnumerator();
		}

		public override DataTable Clone()
		{
			DivideConfigurationDataTable divideConfigurationDataTable = (DivideConfigurationDataTable)base.Clone();
			divideConfigurationDataTable.InitVars();
			return divideConfigurationDataTable;
		}

		protected override DataTable CreateInstance()
		{
			return new DivideConfigurationDataTable();
		}

		internal void InitVars()
		{
			columnCalibrationFileName = base.Columns["CalibrationFileName"];
			columnConfigurationFileName = base.Columns["ConfigurationFileName"];
			columnPopReport = base.Columns["PopReport"];
			columnproductID = base.Columns["productID"];
			columnDivideConfiguration_Id = base.Columns["DivideConfiguration_Id"];
		}

		private void InitClass()
		{
			columnCalibrationFileName = new DataColumn("CalibrationFileName", typeof(string), null, MappingType.Element);
			base.Columns.Add(columnCalibrationFileName);
			columnConfigurationFileName = new DataColumn("ConfigurationFileName", typeof(string), null, MappingType.Element);
			base.Columns.Add(columnConfigurationFileName);
			columnPopReport = new DataColumn("PopReport", typeof(string), null, MappingType.Element);
			base.Columns.Add(columnPopReport);
			columnproductID = new DataColumn("productID", typeof(string), null, MappingType.Element);
			base.Columns.Add(columnproductID);
			columnDivideConfiguration_Id = new DataColumn("DivideConfiguration_Id", typeof(int), null, MappingType.Hidden);
			base.Columns.Add(columnDivideConfiguration_Id);
			base.Constraints.Add(new UniqueConstraint("Constraint1", new DataColumn[1] { columnDivideConfiguration_Id }, isPrimaryKey: true));
			columnCalibrationFileName.AllowDBNull = false;
			columnConfigurationFileName.AllowDBNull = false;
			columnPopReport.AllowDBNull = false;
			columnproductID.AllowDBNull = false;
			columnDivideConfiguration_Id.AutoIncrement = true;
			columnDivideConfiguration_Id.AllowDBNull = false;
			columnDivideConfiguration_Id.Unique = true;
		}

		public DivideConfigurationRow NewDivideConfigurationRow()
		{
			return (DivideConfigurationRow)NewRow();
		}

		protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
		{
			return new DivideConfigurationRow(builder);
		}

		protected override Type GetRowType()
		{
			return typeof(DivideConfigurationRow);
		}

		protected override void OnRowChanged(DataRowChangeEventArgs e)
		{
			base.OnRowChanged(e);
			if (this.DivideConfigurationRowChanged != null)
			{
				this.DivideConfigurationRowChanged(this, new DivideConfigurationRowChangeEvent((DivideConfigurationRow)e.Row, e.Action));
			}
		}

		protected override void OnRowChanging(DataRowChangeEventArgs e)
		{
			base.OnRowChanging(e);
			if (this.DivideConfigurationRowChanging != null)
			{
				this.DivideConfigurationRowChanging(this, new DivideConfigurationRowChangeEvent((DivideConfigurationRow)e.Row, e.Action));
			}
		}

		protected override void OnRowDeleted(DataRowChangeEventArgs e)
		{
			base.OnRowDeleted(e);
			if (this.DivideConfigurationRowDeleted != null)
			{
				this.DivideConfigurationRowDeleted(this, new DivideConfigurationRowChangeEvent((DivideConfigurationRow)e.Row, e.Action));
			}
		}

		protected override void OnRowDeleting(DataRowChangeEventArgs e)
		{
			base.OnRowDeleting(e);
			if (this.DivideConfigurationRowDeleting != null)
			{
				this.DivideConfigurationRowDeleting(this, new DivideConfigurationRowChangeEvent((DivideConfigurationRow)e.Row, e.Action));
			}
		}

		public void RemoveDivideConfigurationRow(DivideConfigurationRow row)
		{
			base.Rows.Remove(row);
		}
	}

	[DebuggerStepThrough]
	public class DivideConfigurationRow : DataRow
	{
		private DivideConfigurationDataTable tableDivideConfiguration;

		public string CalibrationFileName
		{
			get
			{
				return (string)base[tableDivideConfiguration.CalibrationFileNameColumn];
			}
			set
			{
				base[tableDivideConfiguration.CalibrationFileNameColumn] = value;
			}
		}

		public string ConfigurationFileName
		{
			get
			{
				return (string)base[tableDivideConfiguration.ConfigurationFileNameColumn];
			}
			set
			{
				base[tableDivideConfiguration.ConfigurationFileNameColumn] = value;
			}
		}

		public string PopReport
		{
			get
			{
				return (string)base[tableDivideConfiguration.PopReportColumn];
			}
			set
			{
				base[tableDivideConfiguration.PopReportColumn] = value;
			}
		}

		public string productID
		{
			get
			{
				return (string)base[tableDivideConfiguration.productIDColumn];
			}
			set
			{
				base[tableDivideConfiguration.productIDColumn] = value;
			}
		}

		internal DivideConfigurationRow(DataRowBuilder rb)
			: base(rb)
		{
			tableDivideConfiguration = (DivideConfigurationDataTable)base.Table;
		}

		public SubfilesInformationRow[] GetSubfilesInformationRows()
		{
			return (SubfilesInformationRow[])GetChildRows(base.Table.ChildRelations["DivideConfiguration_SubfilesInformation"]);
		}

		public ReporterInformationRow[] GetReporterInformationRows()
		{
			return (ReporterInformationRow[])GetChildRows(base.Table.ChildRelations["DivideConfiguration_ReporterInformation"]);
		}
	}

	[DebuggerStepThrough]
	public class DivideConfigurationRowChangeEvent : EventArgs
	{
		private DivideConfigurationRow eventRow;

		private DataRowAction eventAction;

		public DivideConfigurationRow Row => eventRow;

		public DataRowAction Action => eventAction;

		public DivideConfigurationRowChangeEvent(DivideConfigurationRow row, DataRowAction action)
		{
			eventRow = row;
			eventAction = action;
		}
	}

	[DebuggerStepThrough]
	public class SubfilesInformationDataTable : DataTable, IEnumerable
	{
		private DataColumn columnSubfileNumber;

		private DataColumn columnSubfileName;

		private DataColumn columnSubfileSelected;

		private DataColumn columnDivideConfiguration_Id;

		[Browsable(false)]
		public int Count => base.Rows.Count;

		internal DataColumn SubfileNumberColumn => columnSubfileNumber;

		internal DataColumn SubfileNameColumn => columnSubfileName;

		internal DataColumn SubfileSelectedColumn => columnSubfileSelected;

		internal DataColumn DivideConfiguration_IdColumn => columnDivideConfiguration_Id;

		public SubfilesInformationRow this[int index] => (SubfilesInformationRow)base.Rows[index];

		public event SubfilesInformationRowChangeEventHandler SubfilesInformationRowChanged;

		public event SubfilesInformationRowChangeEventHandler SubfilesInformationRowChanging;

		public event SubfilesInformationRowChangeEventHandler SubfilesInformationRowDeleted;

		public event SubfilesInformationRowChangeEventHandler SubfilesInformationRowDeleting;

		internal SubfilesInformationDataTable()
			: base("SubfilesInformation")
		{
			InitClass();
		}

		internal SubfilesInformationDataTable(DataTable table)
			: base(table.TableName)
		{
			if (table.CaseSensitive != table.DataSet.CaseSensitive)
			{
				base.CaseSensitive = table.CaseSensitive;
			}
			if (table.Locale.ToString() != table.DataSet.Locale.ToString())
			{
				base.Locale = table.Locale;
			}
			if (table.Namespace != table.DataSet.Namespace)
			{
				base.Namespace = table.Namespace;
			}
			base.Prefix = table.Prefix;
			base.MinimumCapacity = table.MinimumCapacity;
			base.DisplayExpression = table.DisplayExpression;
		}

		public void AddSubfilesInformationRow(SubfilesInformationRow row)
		{
			base.Rows.Add(row);
		}

		public SubfilesInformationRow AddSubfilesInformationRow(string SubfileNumber, string SubfileName, string SubfileSelected, DivideConfigurationRow parentDivideConfigurationRowByDivideConfiguration_SubfilesInformation)
		{
			SubfilesInformationRow subfilesInformationRow = (SubfilesInformationRow)NewRow();
			subfilesInformationRow.ItemArray = new object[4]
			{
				SubfileNumber,
				SubfileName,
				SubfileSelected,
				parentDivideConfigurationRowByDivideConfiguration_SubfilesInformation[4]
			};
			base.Rows.Add(subfilesInformationRow);
			return subfilesInformationRow;
		}

		public IEnumerator GetEnumerator()
		{
			return base.Rows.GetEnumerator();
		}

		public override DataTable Clone()
		{
			SubfilesInformationDataTable subfilesInformationDataTable = (SubfilesInformationDataTable)base.Clone();
			subfilesInformationDataTable.InitVars();
			return subfilesInformationDataTable;
		}

		protected override DataTable CreateInstance()
		{
			return new SubfilesInformationDataTable();
		}

		internal void InitVars()
		{
			columnSubfileNumber = base.Columns["SubfileNumber"];
			columnSubfileName = base.Columns["SubfileName"];
			columnSubfileSelected = base.Columns["SubfileSelected"];
			columnDivideConfiguration_Id = base.Columns["DivideConfiguration_Id"];
		}

		private void InitClass()
		{
			columnSubfileNumber = new DataColumn("SubfileNumber", typeof(string), null, MappingType.Element);
			base.Columns.Add(columnSubfileNumber);
			columnSubfileName = new DataColumn("SubfileName", typeof(string), null, MappingType.Element);
			base.Columns.Add(columnSubfileName);
			columnSubfileSelected = new DataColumn("SubfileSelected", typeof(string), null, MappingType.Element);
			base.Columns.Add(columnSubfileSelected);
			columnDivideConfiguration_Id = new DataColumn("DivideConfiguration_Id", typeof(int), null, MappingType.Hidden);
			base.Columns.Add(columnDivideConfiguration_Id);
			columnSubfileNumber.AllowDBNull = false;
			columnSubfileName.AllowDBNull = false;
			columnSubfileSelected.AllowDBNull = false;
		}

		public SubfilesInformationRow NewSubfilesInformationRow()
		{
			return (SubfilesInformationRow)NewRow();
		}

		protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
		{
			return new SubfilesInformationRow(builder);
		}

		protected override Type GetRowType()
		{
			return typeof(SubfilesInformationRow);
		}

		protected override void OnRowChanged(DataRowChangeEventArgs e)
		{
			base.OnRowChanged(e);
			if (this.SubfilesInformationRowChanged != null)
			{
				this.SubfilesInformationRowChanged(this, new SubfilesInformationRowChangeEvent((SubfilesInformationRow)e.Row, e.Action));
			}
		}

		protected override void OnRowChanging(DataRowChangeEventArgs e)
		{
			base.OnRowChanging(e);
			if (this.SubfilesInformationRowChanging != null)
			{
				this.SubfilesInformationRowChanging(this, new SubfilesInformationRowChangeEvent((SubfilesInformationRow)e.Row, e.Action));
			}
		}

		protected override void OnRowDeleted(DataRowChangeEventArgs e)
		{
			base.OnRowDeleted(e);
			if (this.SubfilesInformationRowDeleted != null)
			{
				this.SubfilesInformationRowDeleted(this, new SubfilesInformationRowChangeEvent((SubfilesInformationRow)e.Row, e.Action));
			}
		}

		protected override void OnRowDeleting(DataRowChangeEventArgs e)
		{
			base.OnRowDeleting(e);
			if (this.SubfilesInformationRowDeleting != null)
			{
				this.SubfilesInformationRowDeleting(this, new SubfilesInformationRowChangeEvent((SubfilesInformationRow)e.Row, e.Action));
			}
		}

		public void RemoveSubfilesInformationRow(SubfilesInformationRow row)
		{
			base.Rows.Remove(row);
		}
	}

	[DebuggerStepThrough]
	public class SubfilesInformationRow : DataRow
	{
		private SubfilesInformationDataTable tableSubfilesInformation;

		public string SubfileNumber
		{
			get
			{
				return (string)base[tableSubfilesInformation.SubfileNumberColumn];
			}
			set
			{
				base[tableSubfilesInformation.SubfileNumberColumn] = value;
			}
		}

		public string SubfileName
		{
			get
			{
				return (string)base[tableSubfilesInformation.SubfileNameColumn];
			}
			set
			{
				base[tableSubfilesInformation.SubfileNameColumn] = value;
			}
		}

		public string SubfileSelected
		{
			get
			{
				return (string)base[tableSubfilesInformation.SubfileSelectedColumn];
			}
			set
			{
				base[tableSubfilesInformation.SubfileSelectedColumn] = value;
			}
		}

		public DivideConfigurationRow DivideConfigurationRow
		{
			get
			{
				return (DivideConfigurationRow)GetParentRow(base.Table.ParentRelations["DivideConfiguration_SubfilesInformation"]);
			}
			set
			{
				SetParentRow(value, base.Table.ParentRelations["DivideConfiguration_SubfilesInformation"]);
			}
		}

		internal SubfilesInformationRow(DataRowBuilder rb)
			: base(rb)
		{
			tableSubfilesInformation = (SubfilesInformationDataTable)base.Table;
		}
	}

	[DebuggerStepThrough]
	public class SubfilesInformationRowChangeEvent : EventArgs
	{
		private SubfilesInformationRow eventRow;

		private DataRowAction eventAction;

		public SubfilesInformationRow Row => eventRow;

		public DataRowAction Action => eventAction;

		public SubfilesInformationRowChangeEvent(SubfilesInformationRow row, DataRowAction action)
		{
			eventRow = row;
			eventAction = action;
		}
	}

	[DebuggerStepThrough]
	public class ReporterInformationDataTable : DataTable, IEnumerable
	{
		private DataColumn columnReportPrefix;

		private DataColumn columnReportFormat;

		private DataColumn columnAppendReportFile;

		private DataColumn columnReportFileName;

		private DataColumn columnDivideConfiguration_Id;

		[Browsable(false)]
		public int Count => base.Rows.Count;

		internal DataColumn ReportPrefixColumn => columnReportPrefix;

		internal DataColumn ReportFormatColumn => columnReportFormat;

		internal DataColumn AppendReportFileColumn => columnAppendReportFile;

		internal DataColumn ReportFileNameColumn => columnReportFileName;

		internal DataColumn DivideConfiguration_IdColumn => columnDivideConfiguration_Id;

		public ReporterInformationRow this[int index] => (ReporterInformationRow)base.Rows[index];

		public event ReporterInformationRowChangeEventHandler ReporterInformationRowChanged;

		public event ReporterInformationRowChangeEventHandler ReporterInformationRowChanging;

		public event ReporterInformationRowChangeEventHandler ReporterInformationRowDeleted;

		public event ReporterInformationRowChangeEventHandler ReporterInformationRowDeleting;

		internal ReporterInformationDataTable()
			: base("ReporterInformation")
		{
			InitClass();
		}

		internal ReporterInformationDataTable(DataTable table)
			: base(table.TableName)
		{
			if (table.CaseSensitive != table.DataSet.CaseSensitive)
			{
				base.CaseSensitive = table.CaseSensitive;
			}
			if (table.Locale.ToString() != table.DataSet.Locale.ToString())
			{
				base.Locale = table.Locale;
			}
			if (table.Namespace != table.DataSet.Namespace)
			{
				base.Namespace = table.Namespace;
			}
			base.Prefix = table.Prefix;
			base.MinimumCapacity = table.MinimumCapacity;
			base.DisplayExpression = table.DisplayExpression;
		}

		public void AddReporterInformationRow(ReporterInformationRow row)
		{
			base.Rows.Add(row);
		}

		public ReporterInformationRow AddReporterInformationRow(string ReportPrefix, string ReportFormat, bool AppendReportFile, string ReportFileName, DivideConfigurationRow parentDivideConfigurationRowByDivideConfiguration_ReporterInformation)
		{
			ReporterInformationRow reporterInformationRow = (ReporterInformationRow)NewRow();
			reporterInformationRow.ItemArray = new object[5]
			{
				ReportPrefix,
				ReportFormat,
				AppendReportFile,
				ReportFileName,
				parentDivideConfigurationRowByDivideConfiguration_ReporterInformation[4]
			};
			base.Rows.Add(reporterInformationRow);
			return reporterInformationRow;
		}

		public IEnumerator GetEnumerator()
		{
			return base.Rows.GetEnumerator();
		}

		public override DataTable Clone()
		{
			ReporterInformationDataTable reporterInformationDataTable = (ReporterInformationDataTable)base.Clone();
			reporterInformationDataTable.InitVars();
			return reporterInformationDataTable;
		}

		protected override DataTable CreateInstance()
		{
			return new ReporterInformationDataTable();
		}

		internal void InitVars()
		{
			columnReportPrefix = base.Columns["ReportPrefix"];
			columnReportFormat = base.Columns["ReportFormat"];
			columnAppendReportFile = base.Columns["AppendReportFile"];
			columnReportFileName = base.Columns["ReportFileName"];
			columnDivideConfiguration_Id = base.Columns["DivideConfiguration_Id"];
		}

		private void InitClass()
		{
			columnReportPrefix = new DataColumn("ReportPrefix", typeof(string), null, MappingType.Element);
			base.Columns.Add(columnReportPrefix);
			columnReportFormat = new DataColumn("ReportFormat", typeof(string), null, MappingType.Element);
			base.Columns.Add(columnReportFormat);
			columnAppendReportFile = new DataColumn("AppendReportFile", typeof(bool), null, MappingType.Element);
			base.Columns.Add(columnAppendReportFile);
			columnReportFileName = new DataColumn("ReportFileName", typeof(string), null, MappingType.Element);
			base.Columns.Add(columnReportFileName);
			columnDivideConfiguration_Id = new DataColumn("DivideConfiguration_Id", typeof(int), null, MappingType.Hidden);
			base.Columns.Add(columnDivideConfiguration_Id);
			columnReportPrefix.AllowDBNull = false;
			columnReportFormat.AllowDBNull = false;
			columnReportFileName.AllowDBNull = false;
		}

		public ReporterInformationRow NewReporterInformationRow()
		{
			return (ReporterInformationRow)NewRow();
		}

		protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
		{
			return new ReporterInformationRow(builder);
		}

		protected override Type GetRowType()
		{
			return typeof(ReporterInformationRow);
		}

		protected override void OnRowChanged(DataRowChangeEventArgs e)
		{
			base.OnRowChanged(e);
			if (this.ReporterInformationRowChanged != null)
			{
				this.ReporterInformationRowChanged(this, new ReporterInformationRowChangeEvent((ReporterInformationRow)e.Row, e.Action));
			}
		}

		protected override void OnRowChanging(DataRowChangeEventArgs e)
		{
			base.OnRowChanging(e);
			if (this.ReporterInformationRowChanging != null)
			{
				this.ReporterInformationRowChanging(this, new ReporterInformationRowChangeEvent((ReporterInformationRow)e.Row, e.Action));
			}
		}

		protected override void OnRowDeleted(DataRowChangeEventArgs e)
		{
			base.OnRowDeleted(e);
			if (this.ReporterInformationRowDeleted != null)
			{
				this.ReporterInformationRowDeleted(this, new ReporterInformationRowChangeEvent((ReporterInformationRow)e.Row, e.Action));
			}
		}

		protected override void OnRowDeleting(DataRowChangeEventArgs e)
		{
			base.OnRowDeleting(e);
			if (this.ReporterInformationRowDeleting != null)
			{
				this.ReporterInformationRowDeleting(this, new ReporterInformationRowChangeEvent((ReporterInformationRow)e.Row, e.Action));
			}
		}

		public void RemoveReporterInformationRow(ReporterInformationRow row)
		{
			base.Rows.Remove(row);
		}
	}

	[DebuggerStepThrough]
	public class ReporterInformationRow : DataRow
	{
		private ReporterInformationDataTable tableReporterInformation;

		public string ReportPrefix
		{
			get
			{
				return (string)base[tableReporterInformation.ReportPrefixColumn];
			}
			set
			{
				base[tableReporterInformation.ReportPrefixColumn] = value;
			}
		}

		public string ReportFormat
		{
			get
			{
				return (string)base[tableReporterInformation.ReportFormatColumn];
			}
			set
			{
				base[tableReporterInformation.ReportFormatColumn] = value;
			}
		}

		public bool AppendReportFile
		{
			get
			{
				try
				{
					return (bool)base[tableReporterInformation.AppendReportFileColumn];
				}
				catch (InvalidCastException innerException)
				{
					throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
				}
			}
			set
			{
				base[tableReporterInformation.AppendReportFileColumn] = value;
			}
		}

		public string ReportFileName
		{
			get
			{
				return (string)base[tableReporterInformation.ReportFileNameColumn];
			}
			set
			{
				base[tableReporterInformation.ReportFileNameColumn] = value;
			}
		}

		public DivideConfigurationRow DivideConfigurationRow
		{
			get
			{
				return (DivideConfigurationRow)GetParentRow(base.Table.ParentRelations["DivideConfiguration_ReporterInformation"]);
			}
			set
			{
				SetParentRow(value, base.Table.ParentRelations["DivideConfiguration_ReporterInformation"]);
			}
		}

		internal ReporterInformationRow(DataRowBuilder rb)
			: base(rb)
		{
			tableReporterInformation = (ReporterInformationDataTable)base.Table;
		}

		public bool IsAppendReportFileNull()
		{
			return IsNull(tableReporterInformation.AppendReportFileColumn);
		}

		public void SetAppendReportFileNull()
		{
			base[tableReporterInformation.AppendReportFileColumn] = Convert.DBNull;
		}
	}

	[DebuggerStepThrough]
	public class ReporterInformationRowChangeEvent : EventArgs
	{
		private ReporterInformationRow eventRow;

		private DataRowAction eventAction;

		public ReporterInformationRow Row => eventRow;

		public DataRowAction Action => eventAction;

		public ReporterInformationRowChangeEvent(ReporterInformationRow row, DataRowAction action)
		{
			eventRow = row;
			eventAction = action;
		}
	}

	private DivideConfigurationDataTable tableDivideConfiguration;

	private SubfilesInformationDataTable tableSubfilesInformation;

	private ReporterInformationDataTable tableReporterInformation;

	private DataRelation relationDivideConfiguration_SubfilesInformation;

	private DataRelation relationDivideConfiguration_ReporterInformation;

	[Browsable(false)]
	[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
	public DivideConfigurationDataTable DivideConfiguration => tableDivideConfiguration;

	[Browsable(false)]
	[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
	public SubfilesInformationDataTable SubfilesInformation => tableSubfilesInformation;

	[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
	[Browsable(false)]
	public ReporterInformationDataTable ReporterInformation => tableReporterInformation;

	public DivideConfigurationDataSet()
	{
		InitClass();
		CollectionChangeEventHandler value = SchemaChanged;
		base.Tables.CollectionChanged += value;
		base.Relations.CollectionChanged += value;
	}

	protected DivideConfigurationDataSet(SerializationInfo info, StreamingContext context)
	{
		//IL_0034: Unknown result type (might be due to invalid IL or missing references)
		//IL_003e: Expected O, but got Unknown
		string text = (string)info.GetValue("XmlSchema", typeof(string));
		if (text != null)
		{
			DataSet dataSet = new DataSet();
			dataSet.ReadXmlSchema((XmlReader?)new XmlTextReader((TextReader)new StringReader(text)));
			if (dataSet.Tables["DivideConfiguration"] != null)
			{
				base.Tables.Add(new DivideConfigurationDataTable(dataSet.Tables["DivideConfiguration"]));
			}
			if (dataSet.Tables["SubfilesInformation"] != null)
			{
				base.Tables.Add(new SubfilesInformationDataTable(dataSet.Tables["SubfilesInformation"]));
			}
			if (dataSet.Tables["ReporterInformation"] != null)
			{
				base.Tables.Add(new ReporterInformationDataTable(dataSet.Tables["ReporterInformation"]));
			}
			base.DataSetName = dataSet.DataSetName;
			base.Prefix = dataSet.Prefix;
			base.Namespace = dataSet.Namespace;
			base.Locale = dataSet.Locale;
			base.CaseSensitive = dataSet.CaseSensitive;
			base.EnforceConstraints = dataSet.EnforceConstraints;
			Merge(dataSet, preserveChanges: false, MissingSchemaAction.Add);
			InitVars();
		}
		else
		{
			InitClass();
		}
		GetSerializationData(info, context);
		CollectionChangeEventHandler value = SchemaChanged;
		base.Tables.CollectionChanged += value;
		base.Relations.CollectionChanged += value;
	}

	public override DataSet Clone()
	{
		DivideConfigurationDataSet divideConfigurationDataSet = (DivideConfigurationDataSet)base.Clone();
		divideConfigurationDataSet.InitVars();
		return divideConfigurationDataSet;
	}

	protected override bool ShouldSerializeTables()
	{
		return false;
	}

	protected override bool ShouldSerializeRelations()
	{
		return false;
	}

	protected override void ReadXmlSerializable(XmlReader reader)
	{
		Reset();
		DataSet dataSet = new DataSet();
		dataSet.ReadXml(reader);
		if (dataSet.Tables["DivideConfiguration"] != null)
		{
			base.Tables.Add(new DivideConfigurationDataTable(dataSet.Tables["DivideConfiguration"]));
		}
		if (dataSet.Tables["SubfilesInformation"] != null)
		{
			base.Tables.Add(new SubfilesInformationDataTable(dataSet.Tables["SubfilesInformation"]));
		}
		if (dataSet.Tables["ReporterInformation"] != null)
		{
			base.Tables.Add(new ReporterInformationDataTable(dataSet.Tables["ReporterInformation"]));
		}
		base.DataSetName = dataSet.DataSetName;
		base.Prefix = dataSet.Prefix;
		base.Namespace = dataSet.Namespace;
		base.Locale = dataSet.Locale;
		base.CaseSensitive = dataSet.CaseSensitive;
		base.EnforceConstraints = dataSet.EnforceConstraints;
		Merge(dataSet, preserveChanges: false, MissingSchemaAction.Add);
		InitVars();
	}

	protected override XmlSchema GetSchemaSerializable()
	{
		//IL_0009: Unknown result type (might be due to invalid IL or missing references)
		//IL_0013: Expected O, but got Unknown
		//IL_001c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0027: Expected O, but got Unknown
		MemoryStream memoryStream = new MemoryStream();
		WriteXmlSchema((XmlWriter?)new XmlTextWriter((Stream)memoryStream, (Encoding)null));
		memoryStream.Position = 0L;
		return XmlSchema.Read((XmlReader)new XmlTextReader((Stream)memoryStream), (ValidationEventHandler)null);
	}

	internal void InitVars()
	{
		tableDivideConfiguration = (DivideConfigurationDataTable)base.Tables["DivideConfiguration"];
		if (tableDivideConfiguration != null)
		{
			tableDivideConfiguration.InitVars();
		}
		tableSubfilesInformation = (SubfilesInformationDataTable)base.Tables["SubfilesInformation"];
		if (tableSubfilesInformation != null)
		{
			tableSubfilesInformation.InitVars();
		}
		tableReporterInformation = (ReporterInformationDataTable)base.Tables["ReporterInformation"];
		if (tableReporterInformation != null)
		{
			tableReporterInformation.InitVars();
		}
		relationDivideConfiguration_SubfilesInformation = base.Relations["DivideConfiguration_SubfilesInformation"];
		relationDivideConfiguration_ReporterInformation = base.Relations["DivideConfiguration_ReporterInformation"];
	}

	private void InitClass()
	{
		base.DataSetName = "DivideConfigurationDataSet";
		base.Prefix = "";
		base.Namespace = "";
		base.Locale = new CultureInfo("en-US");
		base.CaseSensitive = false;
		base.EnforceConstraints = true;
		tableDivideConfiguration = new DivideConfigurationDataTable();
		base.Tables.Add(tableDivideConfiguration);
		tableSubfilesInformation = new SubfilesInformationDataTable();
		base.Tables.Add(tableSubfilesInformation);
		tableReporterInformation = new ReporterInformationDataTable();
		base.Tables.Add(tableReporterInformation);
		ForeignKeyConstraint foreignKeyConstraint = new ForeignKeyConstraint("DivideConfiguration_SubfilesInformation", new DataColumn[1] { tableDivideConfiguration.DivideConfiguration_IdColumn }, new DataColumn[1] { tableSubfilesInformation.DivideConfiguration_IdColumn });
		tableSubfilesInformation.Constraints.Add(foreignKeyConstraint);
		foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
		foreignKeyConstraint.DeleteRule = Rule.Cascade;
		foreignKeyConstraint.UpdateRule = Rule.Cascade;
		foreignKeyConstraint = new ForeignKeyConstraint("DivideConfiguration_ReporterInformation", new DataColumn[1] { tableDivideConfiguration.DivideConfiguration_IdColumn }, new DataColumn[1] { tableReporterInformation.DivideConfiguration_IdColumn });
		tableReporterInformation.Constraints.Add(foreignKeyConstraint);
		foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
		foreignKeyConstraint.DeleteRule = Rule.Cascade;
		foreignKeyConstraint.UpdateRule = Rule.Cascade;
		relationDivideConfiguration_SubfilesInformation = new DataRelation("DivideConfiguration_SubfilesInformation", new DataColumn[1] { tableDivideConfiguration.DivideConfiguration_IdColumn }, new DataColumn[1] { tableSubfilesInformation.DivideConfiguration_IdColumn }, createConstraints: false);
		relationDivideConfiguration_SubfilesInformation.Nested = true;
		base.Relations.Add(relationDivideConfiguration_SubfilesInformation);
		relationDivideConfiguration_ReporterInformation = new DataRelation("DivideConfiguration_ReporterInformation", new DataColumn[1] { tableDivideConfiguration.DivideConfiguration_IdColumn }, new DataColumn[1] { tableReporterInformation.DivideConfiguration_IdColumn }, createConstraints: false);
		relationDivideConfiguration_ReporterInformation.Nested = true;
		base.Relations.Add(relationDivideConfiguration_ReporterInformation);
	}

	private bool ShouldSerializeDivideConfiguration()
	{
		return false;
	}

	private bool ShouldSerializeSubfilesInformation()
	{
		return false;
	}

	private bool ShouldSerializeReporterInformation()
	{
		return false;
	}

	private void SchemaChanged(object sender, CollectionChangeEventArgs e)
	{
		if (e.Action == CollectionChangeAction.Remove)
		{
			InitVars();
		}
	}
}
public abstract class IndexTable : DataTable
{
	public enum TableTypeEnum
	{
		InvalidTableType = -1,
		TableType0,
		TableType1,
		TableType2,
		TableType3,
		TableType4
	}

	public struct Section
	{
		public uint number;

		public uint count;
	}

	public const string TableNumber = "TableNumber";

	public const string Address = "Address";

	public const string Size = "Size";

	public const string BlockNumber = "BlockNumber";

	public const string TableType = "TableType";

	public const string SubfileType = "SubfileType";

	public const int CountOfBytesForAField = 4;

	public const int CountOfBytesForAnEntry = 8;

	protected const SpecialParameters IndexTableAddress = SpecialParameters.CalHeadersIndex_table_address;

	protected const SpecialParameters _BlockDataStructure = SpecialParameters.ConfigFile_Block_Data_Structure;

	protected const SpecialParameters BlockAddressesAddressArray = SpecialParameters.ConfigFile_Block_Data_StructureAddressArray;

	protected const SpecialParameters BlockLengthsLengthArray = SpecialParameters.ConfigFile_Block_Data_StructureContentLengthArray;

	protected const SpecialParameters NumberOfBlocks = SpecialParameters.ConfigFile_Block_Data_StructureNumBlocks;

	private int bdsBlockNumber;

	private int bdsTableNumber;

	protected uint sectionLength;

	protected ArrayList sections;

	private int numberOfBlocks;

	protected uint indexTableSize;

	protected uint countOfTables;

	private Block[] blocks;

	private StringBuilder _errorMessage;

	protected ICalibration calibration;

	public uint NumberOfTables => countOfTables;

	public uint Length => indexTableSize;

	public int BDSBlockNumber => bdsBlockNumber;

	public int BDSTableNumber => bdsTableNumber;

	public ArrayList Sections => sections;

	public int CountOfBlocks => numberOfBlocks;

	public Block[] BDSBlocks => blocks;

	public StringBuilder ErrorMessage => _errorMessage;

	public DataRow this[int tableNumber]
	{
		get
		{
			try
			{
				return Select("TableNumber = " + tableNumber)[0];
			}
			catch (IndexOutOfRangeException)
			{
				throw new InvalidIndexTableNumberException(CalibrationDivideMessageId.IndexTableNumberNotPresent, "Index table number " + tableNumber.ToString("X8") + " is not present in CalibrationFile.");
			}
		}
	}

	public IndexTable(ICalibration calibration)
	{
		_errorMessage = new StringBuilder();
		this.calibration = calibration;
		PopulateIndexTable();
		SetBlockNumbersForIndexTableEntries();
	}

	protected void BuildColumns()
	{
		base.Columns.Add("TableNumber", typeof(int));
		base.Columns.Add("Address", typeof(uint));
		base.Columns.Add("Size", typeof(uint));
		base.Columns.Add("BlockNumber", typeof(uint));
		base.Columns.Add("TableType", typeof(TableTypeEnum));
		base.Columns.Add("SubfileType", typeof(short));
		base.Columns["TableNumber"].AllowDBNull = true;
		base.PrimaryKey = new DataColumn[1] { base.Columns["TableNumber"] };
	}

	protected void AddIndexTableEntry(uint tableNumber, uint tableAddress, uint tableSize, uint blockNumber, TableTypeEnum tableType, short subfileType)
	{
		DataRow dataRow = NewRow();
		dataRow["TableNumber"] = tableNumber;
		dataRow["Address"] = tableAddress;
		dataRow["Size"] = tableSize;
		dataRow["BlockNumber"] = blockNumber;
		dataRow["TableType"] = tableType;
		dataRow["SubfileType"] = subfileType;
		base.Rows.Add(dataRow);
	}

	protected void AddIndexTableEntry(uint tableNumber, uint tableAddress, uint tableSize)
	{
		AddIndexTableEntry(tableNumber, tableAddress, tableSize, 0u, TableTypeEnum.InvalidTableType, -1);
	}

	protected void SetBlockNumbersForIndexTableEntries()
	{
		if (calibration.ProductID != "ECI")
		{
			ICICalEntity calEntity = ((IEntityModel)calibration.GetByFullName(SpecialParameters.ConfigFile_Block_Data_Structure)).CalEntity;
			Cummins.Interop.CalDataServer.ICITreeNode iCITreeNode = (Cummins.Interop.CalDataServer.ICITreeNode)calEntity;
			Cummins.Interop.SymbolicTree.ICISymbolicData iCISymbolicData = (Cummins.Interop.SymbolicTree.ICISymbolicData)iCITreeNode.Data;
			bdsTableNumber = iCISymbolicData.IndexTable;
			DataRow dataRow = Select("TableNumber = " + bdsTableNumber)[0];
			uint num = uint.Parse(dataRow["Address"].ToString());
			int.Parse(dataRow["Size"].ToString());
			RetrieveEntities(out var calArrayEntity, out var calValueEntity, calibration, SpecialParameters.ConfigFile_Block_Data_StructureAddressArray);
			RetrieveEntities(out var calArrayEntity2, out var calValueEntity2, calibration, SpecialParameters.ConfigFile_Block_Data_StructureContentLengthArray);
			numberOfBlocks = GetParameterValue(SpecialParameters.ConfigFile_Block_Data_StructureNumBlocks);
			uint num2 = 0u;
			uint num3 = 0u;
			blocks = new Block[numberOfBlocks];
			for (int i = 0; i < numberOfBlocks; i++)
			{
				calArrayEntity.CurrentIndex = i;
				num2 = (uint)calValueEntity.ScaledFloat;
				calArrayEntity2.CurrentIndex = i;
				num3 = (uint)calValueEntity2.ScaledFloat;
				blocks[i].Address = num2;
				blocks[i].Size = num3;
				if (num >= num2 && num < num2 + num3)
				{
					bdsBlockNumber = i + 1;
				}
				StringBuilder stringBuilder = new StringBuilder();
				stringBuilder.Append(num2 + " <= Address AND ");
				stringBuilder.Append(num2 + num3 + " > Address ");
				DataRow[] array = Select(stringBuilder.ToString());
				for (int j = 0; j < array.Length; j++)
				{
					array[j]["BlockNumber"] = i + 1;
				}
			}
			return;
		}
		foreach (DataRow row in base.Rows)
		{
			row["BlockNumber"] = 1;
		}
	}

	protected virtual void PopulateIndexTable()
	{
	}

	protected byte[] ReadData(uint address, uint length, int offset = 0)
	{
		IMemoryMapModel memoryMap = calibration.GetMemoryMap(address, length, offset);
		byte[] array = null;
		return memoryMap.RawValue();
	}

	protected uint Convert4Bytes(byte[] data, int index, ByteOrder byteOrder)
	{
		uint result = 0u;
		switch (byteOrder)
		{
		case ByteOrder.Motorola:
			result = (uint)(data[index] * 16777216 + data[index + 1] * 65536 + data[index + 2] * 256 + data[index + 3]);
			break;
		case ByteOrder.Intel:
			result = (uint)(data[index + 3] * 16777216 + data[index + 2] * 65536 + data[index + 1] * 256 + data[index]);
			break;
		}
		return result;
	}

	protected uint Convert2Bytes(byte[] data, int index, ByteOrder byteOrder)
	{
		uint result = 0u;
		switch (byteOrder)
		{
		case ByteOrder.Motorola:
			result = (uint)(data[index] * 256 + data[index + 1]);
			break;
		case ByteOrder.Intel:
			result = (uint)(data[index] + data[index + 1] * 256);
			break;
		}
		return result;
	}

	protected void RetrieveEntities(out ICICalArrayEntity calArrayEntity, out ICICalValueEntity calValueEntity, ICalibration calibration, SpecialParameters field)
	{
		calArrayEntity = (ICICalArrayEntity)((IEntityModel)calibration.GetByFullName(field)).CalEntity;
		Cummins.Interop.CalDataServer.ICITreeNode iCITreeNode = (Cummins.Interop.CalDataServer.ICITreeNode)calArrayEntity;
		Cummins.Interop.CalDataServer.ICITreeNode firstChild = iCITreeNode.FirstChild;
		calValueEntity = (ICICalValueEntity)firstChild;
	}

	protected int GetParameterValue(SpecialParameters parameter)
	{
		IValueModel valueModel = (IValueModel)calibration.Get(parameter);
		return (int)valueModel.ScaledFloat();
	}
}
public class ECIIndexTable : IndexTable
{
	public ECIIndexTable(ICalibration calibration)
		: base(calibration)
	{
	}

	protected override void PopulateIndexTable()
	{
		uint num = 0u;
		indexTableSize = 0u;
		byte[] array = null;
		IValueModel valueModel = (IValueModel)calibration.Get("ConfigFile.CAL_E2");
		num = valueModel.Address;
		ProductData productData = new ProductData();
		ICIProductDetail iCIProductDetail = productData[calibration.ProductID];
		array = ReadData(num, 2u);
		indexTableSize = (countOfTables = Convert2Bytes(array, 0, iCIProductDetail.ByteOrder));
		array = ReadData(num + 2, indexTableSize * 2);
		BuildColumns();
		AddIndexTableEntry(0u, num, indexTableSize);
		uint num2 = 1u;
		byte[] array2 = null;
		for (int i = 0; i < indexTableSize * 2; i += 2)
		{
			uint num3 = Convert2Bytes(array, i, iCIProductDetail.ByteOrder);
			array2 = ReadData(num3, 2u);
			uint tableSize = Convert2Bytes(array2, 0, iCIProductDetail.ByteOrder) + 2;
			AddIndexTableEntry(num2, num3, tableSize);
			num2++;
		}
	}
}
public enum CalibrationDivideMessageId
{
	IndexTableNumberOutOfRange = 1,
	IndexTableNumberNotPresent,
	MaxErrorLimitCrossed,
	ProductIdMisMatched,
	CalibrationVersionMisMatched,
	HoleSizeExceeded,
	InvalidConfigFileEntries,
	ActivationDeactivationNotCompatible,
	AddressOutOfRange,
	UnableToReadData,
	ProductStructureLengthIncorrect,
	ProductNotSupported,
	SubfileNumberIncorrect,
	SubfileNumberIsDuplicate,
	SubfileNameIsInvalid,
	UnableToAddBlockDataStructureRecord
}
public class CalibrationDivideException : BaseException
{
	public CalibrationDivideException()
		: base(Facility.AssemblyInvoker, 0)
	{
	}

	public CalibrationDivideException(CalibrationDivideMessageId errorID, string message)
		: base(Facility.CalibrationDivide, (short)errorID, message)
	{
	}

	public CalibrationDivideException(CalibrationDivideMessageId errorID, string message, Exception inner)
		: base(Facility.CalibrationDivide, (short)errorID, message, inner)
	{
	}
}
public class InvalidIndexTableNumberException : CalibrationDivideException
{
	public InvalidIndexTableNumberException()
	{
	}

	public InvalidIndexTableNumberException(CalibrationDivideMessageId errorID, string message)
		: base(errorID, message)
	{
	}

	public InvalidIndexTableNumberException(CalibrationDivideMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
	}
}
public class MaxErrorReportedException : CalibrationDivideException
{
	public MaxErrorReportedException()
	{
	}

	public MaxErrorReportedException(CalibrationDivideMessageId errorID, string message)
		: base(errorID, message)
	{
	}

	public MaxErrorReportedException(CalibrationDivideMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
	}
}
public class MisMatchedException : CalibrationDivideException
{
	public MisMatchedException()
	{
	}

	public MisMatchedException(CalibrationDivideMessageId errorID, string message)
		: base(errorID, message)
	{
	}

	public MisMatchedException(CalibrationDivideMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
	}
}
public class MaxHoleSizeExceededException : CalibrationDivideException
{
	public MaxHoleSizeExceededException()
	{
	}

	public MaxHoleSizeExceededException(CalibrationDivideMessageId errorID, string message)
		: base(errorID, message)
	{
	}

	public MaxHoleSizeExceededException(CalibrationDivideMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
	}
}
public class InvalidIndexTableFormatException : CalibrationDivideException
{
	public InvalidIndexTableFormatException()
	{
	}

	public InvalidIndexTableFormatException(CalibrationDivideMessageId errorID, string message)
		: base(errorID, message)
	{
	}

	public InvalidIndexTableFormatException(CalibrationDivideMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
	}
}
public class InvalidActivationDeactivationException : CalibrationDivideException
{
	private string activationNumber = "";

	private string deactivationNumber = "";

	public string ActivationNumber => activationNumber;

	public string DeactivationNumber => deactivationNumber;

	public InvalidActivationDeactivationException(string activationNumber, string deactivationNumber)
	{
		this.activationNumber = activationNumber;
		this.deactivationNumber = deactivationNumber;
	}

	public InvalidActivationDeactivationException(CalibrationDivideMessageId errorID, string message, string activationNumber, string deactivationNumber)
		: base(errorID, message)
	{
		this.activationNumber = activationNumber;
		this.deactivationNumber = deactivationNumber;
	}

	public InvalidActivationDeactivationException(CalibrationDivideMessageId errorID, string message, string activationNumber, string deactivationNumber, Exception inner)
		: base(errorID, message, inner)
	{
		this.activationNumber = activationNumber;
		this.deactivationNumber = deactivationNumber;
	}
}
public class InvalidAddressException : CalibrationDivideException
{
	public InvalidAddressException()
	{
	}

	public InvalidAddressException(CalibrationDivideMessageId errorID, string message)
		: base(errorID, message)
	{
	}

	public InvalidAddressException(CalibrationDivideMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
	}
}
public class InvalidProductStructureLength : CalibrationDivideException
{
	public InvalidProductStructureLength()
	{
	}

	public InvalidProductStructureLength(CalibrationDivideMessageId errorID, string message)
		: base(errorID, message)
	{
	}

	public InvalidProductStructureLength(CalibrationDivideMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
	}
}
public class ProductNotSupportedException : CalibrationDivideException
{
	public ProductNotSupportedException(CalibrationDivideMessageId errorID, string message)
		: base(errorID, message)
	{
	}

	public ProductNotSupportedException(CalibrationDivideMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
	}
}
public class InvalidSubfileNumberException : CalibrationDivideException
{
	public InvalidSubfileNumberException(CalibrationDivideMessageId errorID, string message)
		: base(errorID, message)
	{
	}

	public InvalidSubfileNumberException(CalibrationDivideMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
	}
}
public class DuplicateSubfileNumberException : CalibrationDivideException
{
	public DuplicateSubfileNumberException(CalibrationDivideMessageId errorID, string message)
		: base(errorID, message)
	{
	}

	public DuplicateSubfileNumberException(CalibrationDivideMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
	}
}
public class InvalidSubfileNameException : CalibrationDivideException
{
	public InvalidSubfileNameException(CalibrationDivideMessageId errorID, string message)
		: base(errorID, message)
	{
	}

	public InvalidSubfileNameException(CalibrationDivideMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
	}
}
public class FileSelectionStep : BaseStep
{
	private const string InvalidFileError = "Invalid file selection.";

	private const string InvalidFileInstructions = "Reselect files.";

	private string configurationFilename;

	private string calibrationFilename;

	private GTISVersion gtisVersion;

	private CalibrationFileSelectControl fileSelect;

	private ArrayList requestedSubfiles;

	private Container components;

	public string CalibrationFilename => calibrationFilename;

	public string ConfigurationFilename => configurationFilename;

	public CalibrationFileSelectControl CalibrationFileSelectControl => fileSelect;

	public FileSelectionStep(GTISVersion version, ArrayList requests)
	{
		gtisVersion = version;
		requestedSubfiles = requests;
		InitializeComponent();
		CalibrationFileSelectControl.BrowseButtonClick += OnEventBrowseButtonClick;
		base.Description = "Select Calibration Files";
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
		fileSelect = new CalibrationFileSelectControl();
		((Control)this).SuspendLayout();
		fileSelect.BaseDirectory = null;
		((Control)fileSelect.dataSourceLabel).Text = "Calibration:";
		fileSelect.GTIS = GTISVersion.GTIS45;
		((Control)fileSelect).Location = new Point(8, 88);
		((Control)fileSelect).Name = "fileSelect";
		((Control)fileSelect).Size = new Size(456, 72);
		((Control)fileSelect).TabIndex = 1;
		((UserControl)fileSelect).TextChanged += fileSelect_TextChanged;
		((Control)this).Controls.AddRange((Control[])(object)new Control[1] { (Control)fileSelect });
		((Control)this).Name = "FileSelectionStep";
		base.NextStep = "SubfileSelectionStep";
		base.StepTitle = "Select Calibration";
		base.ValidateStep += FileSelectionStep_ValidateStep;
		base.ShowStep += FileSelectionStep_ShowStep;
		((Control)this).ResumeLayout(false);
	}

	private void FileSelectionStep_ShowStep(object sender, EventArgs e)
	{
		fileSelect.GTIS = gtisVersion;
		base.Wizard.NextEnabled = fileSelect.IsValidFiles;
		if (!base.Wizard.NextEnabled)
		{
			return;
		}
		base.Wizard.FinishEnabled = false;
		for (int i = 0; i < requestedSubfiles.Count; i++)
		{
			if (((SubfileRequest)requestedSubfiles[i]).Selected)
			{
				base.Wizard.FinishEnabled = true;
				break;
			}
		}
	}

	private void FileSelectionStep_ValidateStep(object sender, CancelEventArgs e)
	{
		//IL_0039: Unknown result type (might be due to invalid IL or missing references)
		configurationFilename = fileSelect.ConfigFilename;
		calibrationFilename = fileSelect.CalibrationFilename;
		if (!fileSelect.IsValidFiles)
		{
			MessageBox.Show("Invalid file selection.", "Reselect files.");
			e.Cancel = true;
			return;
		}
		int num = CalibrationFilename.LastIndexOf("\\");
		int num2 = CalibrationFilename.LastIndexOf(".");
		string filename = CalibrationFilename.Substring(num + 1, num2 - num - 1);
		for (int i = 0; i < requestedSubfiles.Count; i++)
		{
			((SubfileRequest)requestedSubfiles[i]).Filename = filename;
		}
	}

	private void fileSelect_TextChanged(object sender, EventArgs e)
	{
		if (base.Wizard != null)
		{
			BaseWizard baseWizard = base.Wizard;
			bool nextEnabled = (base.Wizard.FinishEnabled = fileSelect.IsValidFiles);
			baseWizard.NextEnabled = nextEnabled;
		}
	}

	private void OnEventBrowseButtonClick(object source, CalibrationFileSelectControlArgs calibrationFileSelectControlArgs)
	{
		IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
		IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
		string text = directoryService.FolderName(FolderType.Product, appSetting);
		string lastUsedValue = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastDivideSourceFile);
		string lastUsedValue2 = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastDivideConfigFile);
		if (calibrationFileSelectControlArgs.FileType == "Calibration" && lastUsedValue.Trim().Length == 0)
		{
			fileSelect.BaseDirectory = text + "\\unrlcal";
		}
		else if (calibrationFileSelectControlArgs.FileType == "Calibration" && lastUsedValue.Trim().Length != 0)
		{
			fileSelect.BaseDirectory = Path.GetDirectoryName(lastUsedValue);
		}
		if (calibrationFileSelectControlArgs.FileType == "Configuration" && lastUsedValue2.Trim().Length == 0)
		{
			fileSelect.BaseDirectory = text + "\\descp";
		}
		else if (calibrationFileSelectControlArgs.FileType == "Configuration" && lastUsedValue2.Trim().Length != 0)
		{
			fileSelect.BaseDirectory = Path.GetDirectoryName(lastUsedValue2);
		}
	}
}
internal class GTIS20IndexTable : IndexTable
{
	public GTIS20IndexTable(ICalibration calibration)
		: base(calibration)
	{
	}

	protected override void PopulateIndexTable()
	{
		uint num = 0u;
		indexTableSize = 0u;
		byte[] array = null;
		ProductData productData = new ProductData();
		ICIProductDetail iCIProductDetail = productData[calibration.ProductID];
		int num2 = (int)iCIProductDetail.WordSize;
		IValueModel valueModel = (IValueModel)calibration.Get(SpecialParameters.CalHeadersIndex_table_address);
		num = valueModel.Address;
		array = ReadData(num, (uint)num2);
		uint num3 = 0u;
		num3 = (countOfTables = ((num2 != 4) ? Convert2Bytes(array, 0, iCIProductDetail.ByteOrder) : Convert4Bytes(array, 0, iCIProductDetail.ByteOrder)));
		indexTableSize = (uint)(num3 * num2 * 2);
		array = ReadData(num + (uint)num2, indexTableSize);
		BuildColumns();
		uint num4 = 1u;
		_ = calibration.ProductID;
		if (calibration.ProductID == "IND")
		{
			AddIndexTableEntry(0u, num, num3);
			for (int i = 0; i < num3 * 2; i += num2)
			{
				uint tableAddress = Convert2Bytes(array, i, iCIProductDetail.ByteOrder);
				uint tableSize = 0u;
				AddIndexTableEntry(num4, tableAddress, tableSize);
				num4++;
			}
			GetTableLengths();
			return;
		}
		AddIndexTableEntry(0u, num, indexTableSize);
		for (int j = 0; j < indexTableSize; j += num2 * 2)
		{
			uint tableAddress;
			uint tableSize;
			if (num2 == 4)
			{
				tableAddress = Convert4Bytes(array, j, iCIProductDetail.ByteOrder);
				tableSize = Convert4Bytes(array, j + num2, iCIProductDetail.ByteOrder);
			}
			else
			{
				tableAddress = Convert2Bytes(array, j, iCIProductDetail.ByteOrder);
				tableSize = Convert2Bytes(array, j + num2, iCIProductDetail.ByteOrder);
			}
			AddIndexTableEntry(num4, tableAddress, tableSize);
			num4++;
		}
	}

	private void GetTableLengths()
	{
		calibration.ParametersInfo.ResetSelectionStatus(selectionStatus: true);
		StringCollection selectedParameters = calibration.ParametersInfo.SelectedParameters;
		StringEnumerator enumerator = selectedParameters.GetEnumerator();
		try
		{
			while (enumerator.MoveNext())
			{
				string current = enumerator.Current;
				IParamInfo paramInfo = calibration.ParametersInfo[current];
				if (paramInfo == null || !paramInfo.FullName.StartsWith("ConfigFile"))
				{
					continue;
				}
				switch (paramInfo.ConfigFileType)
				{
				case 66:
				case 67:
				case 70:
				case 78:
				case 79:
					if (paramInfo.IndexTable <= int.Parse(base[0]["Size"].ToString()) && int.Parse(base[paramInfo.IndexTable]["Size"].ToString()) < int.Parse(paramInfo.AddressingOffset.ToString()) + int.Parse(paramInfo.Size.ToString()))
					{
						base[paramInfo.IndexTable]["Size"] = int.Parse(paramInfo.AddressingOffset.ToString()) + int.Parse(paramInfo.Size.ToString());
					}
					break;
				case 84:
				case 88:
				case 89:
				{
					int indexTable = paramInfo.IndexTable;
					uint address = Convert.ToUInt32(base[indexTable]["Address"].ToString());
					byte[] data = ReadData(address, 2u);
					base[indexTable]["Size"] = Convert2Bytes(data, 0, ByteOrder.Intel) + 2;
					break;
				}
				}
			}
		}
		finally
		{
			if (enumerator is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}
	}
}
internal class GTIS3845IndexTable : IndexTable
{
	public GTIS3845IndexTable(ICalibration calibration)
		: base(calibration)
	{
	}

	protected override void PopulateIndexTable()
	{
		uint num = 0u;
		uint num2 = 0u;
		indexTableSize = 0u;
		byte[] array = null;
		ProductData productData = new ProductData();
		ICIProductDetail iCIProductDetail = productData[calibration.ProductID];
		ByteOrder byteOrder = iCIProductDetail.ByteOrder;
		IValueModel valueModel = (IValueModel)calibration.Get(SpecialParameters.CalHeadersIndex_table_address);
		if (calibration.CalibrationDataServer.GTISLevel == GTISVersion.GTIS45)
		{
			num = uint.Parse(valueModel.ScaledValue, NumberStyles.AllowHexSpecifier);
		}
		else if (calibration.CalibrationDataServer.GTISLevel == GTISVersion.GTIS38)
		{
			num = uint.Parse(valueModel.ScaledValue);
		}
		array = ReadData(num, 4u);
		uint num3 = Convert4Bytes(array, 0, byteOrder);
		sectionLength = num3 * 8;
		array = ReadData(num, sectionLength, 4);
		sections = new ArrayList();
		Section section = default(Section);
		for (int i = 0; i < sectionLength; i += 8)
		{
			section.number = Convert4Bytes(array, i, byteOrder);
			section.count = Convert4Bytes(array, i + 4, byteOrder);
			sections.Add(section);
			num2 += section.count;
		}
		BuildColumns();
		indexTableSize = 4 + (num3 + num2) * 8;
		countOfTables = section.number + section.count - 1;
		AddIndexTableEntry(0u, num, indexTableSize);
		uint num4 = num + 4 + sectionLength;
		int num5 = (int)(4 + sectionLength);
		uint num6 = 1u;
		for (int j = 0; j < sections.Count; j++)
		{
			uint number = ((Section)sections[j]).number;
			uint count = ((Section)sections[j]).count;
			for (; num6 < number; num6++)
			{
				AddIndexTableEntry(num6, 0u, 0u);
			}
			num6 = number + count;
			for (uint num7 = 0u; num7 < count; num7++)
			{
				array = ReadData(num, 8u, num5);
				uint tableNumber = number + num7;
				uint num8 = Convert4Bytes(array, 0, byteOrder);
				uint num9 = Convert4Bytes(array, 4, byteOrder);
				if (num9 == 0)
				{
					string text = $"parameter: {num8}, its size is 0, please check ecfg file and calibration file.";
					EventLogger.Error("Calterm Divide", text);
					base.ErrorMessage.Append('\n' + text);
				}
				AddIndexTableEntry(tableNumber, num8, num9);
				num4 += 8;
				num5 += 8;
			}
		}
	}
}
public class GTIS38CalibrationDivide : CalibrationDivide
{
	private const int MAXVERSION = 99999999;

	private const string blockDataStructure = "ConfigFile.Block_Data_Structure";

	public override BitSize TRecordBitSize => BitSize.Sixteen;

	public override BitSize LRecordBitSize => BitSize.ThirtyTwo;

	public override string BlockDataStructure => "ConfigFile.Block_Data_Structure";

	public override IndexTable indexTable
	{
		get
		{
			if (gtisIndexTable == null)
			{
				gtisIndexTable = new GTIS3845IndexTable(calibration);
			}
			return gtisIndexTable;
		}
	}

	protected override void PopulateDataRecords()
	{
		DataTable dataTable = calibration.Parameters.Tables["Parameter"].Copy();
		for (int i = 0; i < 8; i++)
		{
			if ((Subfile)subfiles[i] != null && ((Subfile)subfiles[i]).ToWrite)
			{
				DataRow[] parameters = dataTable.Select("(AvailableOffline = 'true') and (SubfileNumber = " + (i + 1) + ")");
				WriteParameters(parameters);
			}
		}
	}

	protected override void AddSoftwareVersionCompatibilityRecords(bool romDependentDesired)
	{
		string headerRecord = "";
		string calibrationVersion = GetCalibrationVersion();
		int num = int.Parse(calibrationVersion);
		foreach (Subfile subfile in subfiles)
		{
			if (subfile == null)
			{
				continue;
			}
			int num2 = subfile.SubfileType - 1;
			bool flag = subfile.SubfileType == 3;
			if ((!flag || !romDependentDesired) && (flag || romDependentDesired))
			{
				continue;
			}
			if (!flag && !romDependentDesired)
			{
				int num3 = earliestActivationVersionInConfigFile[num2];
				int num4 = latestIncompatibleDeactivationVersionNumberInConfigFile[num2];
				int num5 = latestDeactivationVersionNumberInConfigFile[num2];
				if (num3 > num)
				{
					subfile.ToWrite = false;
					string text = string.Format(CalibrationDivide.resources.GetString("ActivationVersionNotValid"), subfile.SubfileType, calibrationVersion);
					text += string.Format(CalibrationDivide.resources.GetString("AbortDivideForASubfile"), subfile.SubfileType);
					ReportErrorMessage(text);
				}
				if (num5 < num)
				{
					subfile.ToWrite = false;
					string text2 = string.Format(CalibrationDivide.resources.GetString("DeactivationVersionNotValid"), subfile.SubfileType, calibrationVersion);
					text2 += string.Format(CalibrationDivide.resources.GetString("AbortDivideForASubfile"), subfile.SubfileType);
					ReportErrorMessage(text2);
				}
				string text3 = "";
				text3 = ((num4 != 0 && num3 <= num4) ? (num4 + 1).ToString("d8") : num3.ToString("d8"));
				headerRecord = headerBuilder.BuildSoftwareVersionCompatability(text3, calibrationVersion);
			}
			else if (flag && romDependentDesired)
			{
				headerRecord = headerBuilder.BuildSoftwareVersionCompatability(calibrationVersion, calibrationVersion);
			}
			subfile.AddHeaderRecord(headerRecord);
		}
	}

	protected override void AddGTISHeaderInformationRecords()
	{
		//IL_014f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0154: Unknown result type (might be due to invalid IL or missing references)
		//IL_0156: Unknown result type (might be due to invalid IL or missing references)
		//IL_0159: Invalid comparison between Unknown and I4
		string text = "";
		string text2 = "";
		string text3 = "";
		string text4 = "";
		string text5 = "";
		byte[] array = new byte[1];
		ICICalEntity entityByName = calDataSource.GetEntityByName(null, "CalHeaders");
		Cummins.Interop.CalDataServer.ICITreeNode iCITreeNode = (Cummins.Interop.CalDataServer.ICITreeNode)entityByName;
		Cummins.Interop.CalDataServer.ICITreeNode iCITreeNode2 = iCITreeNode.FirstChild;
		int num = 0;
		if (iCITreeNode2 != null)
		{
			num = iCITreeNode2.SiblingCount;
		}
		while (iCITreeNode2 != null && iCITreeNode2.Next != null)
		{
			iCITreeNode2 = iCITreeNode2.Next;
		}
		for (int i = 0; i < num; i++)
		{
			if (((ICICalEntity)iCITreeNode2).EntityName == "ProductID")
			{
				IParameterModel parameterModel = calibration.Get(SpecialParameters.ConfigFile_Product_ID);
				IArray1DModel array1DModel = (IArray1DModel)parameterModel;
				for (int j = 0; j < array1DModel.Length; j++)
				{
					text5 = array1DModel[j];
					array[0] = byte.Parse(text5, NumberStyles.AllowHexSpecifier);
					text4 += Encoding.ASCII.GetChars(array)[0];
				}
				text3 = text4;
				if (text3 != base.ProductID)
				{
					string text6 = string.Format(CalibrationDivide.resources.GetString("ProductIDMissMatch"), base.ProductID, text3);
					MessageInterruptEventArgs e = new MessageInterruptEventArgs("Calibration Divide", text6 + "Do you want to continue?", (MessageBoxButtons)4, (MessageBoxIcon)48);
					RaiseInteruppedEvent(this, e);
					DialogResult dialogResult = e.DialogResult;
					if ((int)dialogResult == 7)
					{
						throw new MisMatchedException(CalibrationDivideMessageId.ProductIdMisMatched, text6);
					}
					RaiseMessageUpdateEvent(text6, MessageTypes.Warning);
				}
				text2 = text3;
			}
			else
			{
				text2 = ((ICICalValueEntity)iCITreeNode2).ScaledValue;
			}
			text = headerBuilder.BuildGTISHeaderInformationRecord(((ICICalEntity)iCITreeNode2).EntityName + "=" + text2);
			((Subfile)subfiles[2]).AddHeaderRecord(text);
			iCITreeNode2 = iCITreeNode2.Previous;
		}
	}

	protected override void AddDataplateLocationRecord()
	{
		int num = 0;
		uint num2 = 0u;
		int offset = 0;
		num = 13;
		num2 = (uint)indexTable[13]["Size"];
		string headerRecord = headerBuilder.BuildDataplateLocationRecord(num, offset, base.ProductID, num2);
		((Subfile)subfiles[2]).AddHeaderRecord(headerRecord);
	}

	private void WriteParameters(DataRow[] parameters)
	{
		int num = int.Parse(GetCalibrationVersion());
		foreach (DataRow dataRow in parameters)
		{
			if (dataRow["FullName"].ToString().StartsWith("DataStructures.DataplateStructure"))
			{
				continue;
			}
			IEntityModel entityModel = (IEntityModel)calibration.Get((string)dataRow["Name"]);
			if (entityModel is IEnumerationModel)
			{
				continue;
			}
			Cummins.Interop.CalDataServer.ICISymbolicData iCISymbolicData = (Cummins.Interop.CalDataServer.ICISymbolicData)(entityModel.CalEntity as Cummins.Interop.CalDataServer.ICITreeNode).Data;
			int num2 = entityModel.SubfileNumber - 1;
			if (num2 >= 0 && num2 <= 7)
			{
				object data;
				if (entityModel.ConfigFileType == 67)
				{
					uint address = (uint)indexTable.Rows[iCISymbolicData.IndexTable]["Address"];
					uint length = (uint)indexTable.Rows[iCISymbolicData.IndexTable]["Size"];
					data = ReadData(address, length);
				}
				else
				{
					data = (entityModel.CalEntity as ICICalAddressableEntity).RawData;
				}
				try
				{
					int.Parse(iCISymbolicData.ActivationVersion);
					int.Parse(iCISymbolicData.DeactivationVersion);
				}
				catch
				{
					string message = string.Format(CalibrationDivide.resources.GetString("InvalidActivationDeactivationNumber"), iCISymbolicData.Name);
					throw new InvalidActivationDeactivationException(CalibrationDivideMessageId.InvalidConfigFileEntries, message, iCISymbolicData.ActivationVersion, iCISymbolicData.DeactivationVersion);
				}
				if (int.Parse(iCISymbolicData.ActivationVersion) <= num && int.Parse(iCISymbolicData.DeactivationVersion) >= num)
				{
					((Subfile)subfiles[num2]).AddDataRecord(iCISymbolicData.IndexTable, (int)iCISymbolicData.AddressingOffset, ref data);
				}
			}
		}
	}

	protected override void SetActivationInformation(IParamInfo symbolicData)
	{
		int num = 0;
		int num2 = 0;
		int num3 = 0;
		try
		{
			num = int.Parse(symbolicData.SubfileName) - 1;
		}
		catch
		{
			string message = CalibrationDivide.resources.GetString("SubfileTypeError") + "for parameter " + symbolicData.Name;
			throw new InvalidSubfileNumberException(CalibrationDivideMessageId.SubfileNumberIncorrect, message);
		}
		try
		{
			num2 = int.Parse(symbolicData.ActivationVersion);
			num3 = int.Parse(symbolicData.DeactivationVersion);
		}
		catch
		{
			string message2 = string.Format(CalibrationDivide.resources.GetString("InvalidActivationDeactivationNumber"), symbolicData.Name);
			throw new InvalidActivationDeactivationException(CalibrationDivideMessageId.InvalidConfigFileEntries, message2, symbolicData.ActivationVersion, symbolicData.DeactivationVersion);
		}
		try
		{
			int num4 = int.Parse(GetCalibrationVersion());
			if (0 > num || 7 < num)
			{
				return;
			}
			char c = '\0';
			try
			{
				c = (char)symbolicData.ConfigFileType;
			}
			catch (Exception)
			{
			}
			if (c != 'A')
			{
				if (earliestActivationVersionInConfigFile[num] == 0 || earliestActivationVersionInConfigFile[num] > num2)
				{
					earliestActivationVersionInConfigFile[num] = num2;
				}
				if (latestDeactivationVersionNumberInConfigFile[num] == 0 || latestDeactivationVersionNumberInConfigFile[num] < num3)
				{
					latestDeactivationVersionNumberInConfigFile[num] = num3;
				}
				if (num3 != 99999999 && num3 < num4 && latestIncompatibleDeactivationVersionNumberInConfigFile[num] < num3)
				{
					latestIncompatibleDeactivationVersionNumberInConfigFile[num] = num3;
				}
			}
		}
		catch (Exception ex2)
		{
			throw new Exception("Unable to SetActivationInformation for parameter " + symbolicData.Name + ":" + ex2.Message);
		}
	}
}
public class GTIS45CalibrationDivide : CalibrationDivide
{
	private const int NonPJLength = 98;

	private const int PJLength = 91;

	private const string blockDataStructure = "ConfigFile.Block_Data_Structure";

	private string[] GTIS45DataPlateParameters = new string[3] { "Software_Dataplate", "Hardware_Dataplate", "System_Dataplate" };

	public override IndexTable indexTable
	{
		get
		{
			if (gtisIndexTable == null)
			{
				gtisIndexTable = new GTIS3845IndexTable(calibration);
			}
			return gtisIndexTable;
		}
	}

	public override BitSize LRecordBitSize => BitSize.ThirtyTwo;

	public override BitSize TRecordBitSize => BitSize.ThirtyTwo;

	public override string BlockDataStructure => "ConfigFile.Block_Data_Structure";

	protected override string[] DataplateParameters => GTIS45DataPlateParameters;

	public GTIS45CalibrationDivide()
	{
	}

	public GTIS45CalibrationDivide(IDirectoryService directoryservices)
		: base(directoryservices)
	{
	}

	protected override void PopulateDataRecords()
	{
		int num = 0;
		for (int i = 1; i < indexTable.Rows.Count; i++)
		{
			DataRow dataRow = indexTable.Rows[i];
			num = (short)dataRow["SubfileType"] - 1;
			_ = (IndexTable.TableTypeEnum)dataRow["TableType"];
			if (IndexTable.TableTypeEnum.InvalidTableType != (IndexTable.TableTypeEnum)dataRow["TableType"] && subfiles[num] != null)
			{
				object data = ReadData((uint)dataRow["Address"], (uint)dataRow["Size"]);
				((Subfile)subfiles[num]).AddDataRecord(i, 0, ref data);
			}
		}
	}

	protected override void AddSoftwareVersionCompatibilityRecords(bool romDependentDesired)
	{
		string headerRecord = "";
		string calibrationVersion = GetCalibrationVersion();
		foreach (Subfile subfile in subfiles)
		{
			if (subfile == null)
			{
				continue;
			}
			bool flag = subfile.SubfileType == 3;
			if ((flag && romDependentDesired) || (!flag && !romDependentDesired))
			{
				if (!flag && !romDependentDesired)
				{
					headerRecord = headerBuilder.BuildSoftwareVersionCompatability(calibrationVersion, calibrationVersion);
				}
				else if (flag && romDependentDesired)
				{
					headerRecord = headerBuilder.BuildSoftwareVersionCompatability(calibrationVersion, calibrationVersion);
				}
				subfile.AddHeaderRecord(headerRecord);
			}
		}
	}

	protected override void AddGTISHeaderInformationRecords()
	{
		//IL_00f5: Unknown result type (might be due to invalid IL or missing references)
		//IL_00fa: Unknown result type (might be due to invalid IL or missing references)
		//IL_00fc: Unknown result type (might be due to invalid IL or missing references)
		//IL_00ff: Invalid comparison between Unknown and I4
		string text = "";
		string text2 = "";
		string text3 = "";
		ICICalEntity entityByName = calDataSource.GetEntityByName(null, "CalHeaders");
		Cummins.Interop.CalDataServer.ICITreeNode iCITreeNode = (Cummins.Interop.CalDataServer.ICITreeNode)entityByName;
		Cummins.Interop.CalDataServer.ICITreeNode iCITreeNode2 = iCITreeNode.FirstChild;
		int num = 0;
		if (iCITreeNode2 != null)
		{
			num = iCITreeNode2.SiblingCount;
		}
		while (iCITreeNode2 != null && iCITreeNode2.Next != null)
		{
			iCITreeNode2 = iCITreeNode2.Next;
		}
		for (int i = 0; i < num; i++)
		{
			if (!(((ICICalEntity)iCITreeNode2).EntityName == "index_table"))
			{
				if (((ICICalEntity)iCITreeNode2).EntityName == "product_id")
				{
					text3 = calibration.ProductID;
					if (text3 != base.ProductID)
					{
						string text4 = string.Format(CalibrationDivide.resources.GetString("ProductIDMissMatch"), base.ProductID, text3);
						MessageInterruptEventArgs e = new MessageInterruptEventArgs("Calibration Divide", text4 + "Do you want to continue?", (MessageBoxButtons)4, (MessageBoxIcon)48);
						RaiseInteruppedEvent(this, e);
						DialogResult dialogResult = e.DialogResult;
						if ((int)dialogResult == 7)
						{
							throw new MisMatchedException(CalibrationDivideMessageId.ProductIdMisMatched, text4);
						}
						RaiseMessageUpdateEvent(text4, MessageTypes.Warning);
					}
					text2 = text3;
				}
				else
				{
					text2 = ((ICICalValueEntity)iCITreeNode2).ScaledValue;
				}
				text = headerBuilder.BuildGTISHeaderInformationRecord("<" + ((ICICalEntity)iCITreeNode2).EntityName + ">" + text2 + "</" + ((ICICalEntity)iCITreeNode2).EntityName + ">");
				((Subfile)subfiles[2]).AddHeaderRecord(text);
			}
			iCITreeNode2 = iCITreeNode2.Previous;
		}
	}

	protected override void AddDataplateLocationRecord()
	{
		int num = 0;
		uint num2 = 0u;
		int offset = 0;
		num = 65535;
		num2 = 0u;
		string headerRecord = headerBuilder.BuildDataplateLocationRecord(num, offset, base.ProductID, num2);
		((Subfile)subfiles[2]).AddHeaderRecord(headerRecord);
	}

	protected override void ValidateProductStructureOptionLength()
	{
		string empty = string.Empty;
		IParameterModel byFullName = calibration.GetByFullName("C_GTIS_ProductStructureOptions");
		MajorOptionData[] majorOptions = base.MajorOptions;
		IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
		if (productInformationService.GetBootGroup(base.ProductID) == "BOOT38_46")
		{
			return;
		}
		for (int i = 0; i < majorOptions.Length; i++)
		{
			if (OptionType.PJ == majorOptions[i].majorOptionType && 91 != byFullName.Length)
			{
				empty = CalibrationDivide.resources.GetString("ProductStructureLengthIncorrect");
				empty = string.Format(empty, byFullName.Length, 91);
				throw new InvalidProductStructureLength(CalibrationDivideMessageId.ProductStructureLengthIncorrect, empty);
			}
			if (OptionType.PJ != majorOptions[i].majorOptionType && 98 != byFullName.Length)
			{
				empty = CalibrationDivide.resources.GetString("ProductStructureLengthIncorrect");
				empty = string.Format(empty, byFullName.Length, 98);
				throw new InvalidProductStructureLength(CalibrationDivideMessageId.ProductStructureLengthIncorrect, empty);
			}
		}
	}

	protected override void SetActivationInformation(IParamInfo symbolicData)
	{
	}
}
public class HeaderBuilder
{
	public enum SubfileStatus
	{
		Unreleased = 255,
		Validated = 254,
		Assembled = 253,
		Obsoleted = 252,
		Released = 240
	}

	private const string BlockDataStructureLinePrefix = "*B";

	private const string BusinessRecordLinePrefix = "B";

	private const short FileFieldLength = 7;

	private const string RecordPad = "000000000000000000000000";

	private const string EffectCodeFormat = "D2";

	private const char PadCharacter = ' ';

	private const string DataplateLocationRecordLinePrefix = "*D";

	private const string OffsetFormat = "X4";

	private const string LengthFormat = "X4";

	private const string FixedTableLengthRecordLinePrefix = "*F";

	private const string GTISHeaderInformationRecordLinePrefix = "*G";

	private const string StatusFormat = "X2";

	private const string SubfileTypeFormat = "X2";

	private const string IdentificationRecordLinePrefix = "*C";

	private const short SubfileTypeMinimum = 1;

	private const short SubfileTypeMaximum = 8;

	private const string HeaderRecordLinePrefix = "*H";

	private const int NotesArrayMaximum = 7;

	private const string SoftwareDateCompatibilityLinePrefix = "*R";

	private const int DateLength = 10;

	private const string SoftwareVersionCompatibilityRecordLinePrefix = "*V";

	private const int VersionLength = 8;

	private const string TableForcedLocationRecordLinePrefix = "*L";

	private const string Table16BitFormat = "X4";

	private const string Table32BitFormat = "X8";

	private const string TruncateTableLengthRecordLinePrefix = "*T";

	public string BuildBlockDataStructureRecord(int table, int block)
	{
		string text = ((table <= 65535 && block <= 65535) ? "X4" : "X8");
		string line = "*B" + table.ToString(text) + block.ToString(text);
		if (!Checksum.AddLineChecksum(ref line))
		{
			ResourceManager resourceManager = new ResourceManager("Cummins.CalDiv.strings", Assembly.GetExecutingAssembly());
			throw new Exception(resourceManager.GetString("ChecksumError"));
		}
		return line;
	}

	public string BuildBusinessRecord(string filename, string productDescp, char subfile, string familyGroup, short effectCode)
	{
		string text = filename.PadLeft(7, ' ');
		text = text.Substring(0, 7);
		return "B" + text + "000000000000000000000000" + productDescp + subfile + familyGroup + effectCode.ToString("D2");
	}

	public string BuildDataplateLocationRecord(int table, int offset, string productID, uint length)
	{
		string text = ((table <= 65535 && offset <= 65535 && length <= 65535) ? "X4" : "X8");
		string text2 = productID;
		string text3 = "*D" + table.ToString(text) + offset.ToString(text);
		int num = 0;
		foreach (char character in productID)
		{
			if (Uri.IsHexDigit(character))
			{
				num++;
			}
		}
		text2 = ((num % 2 != 0) ? (text2 + "CONT    ") : (text2 + "         "));
		text3 = text3 + text2 + length.ToString(text);
		if (!Checksum.AddLineChecksum(ref text3))
		{
			ResourceManager resourceManager = new ResourceManager("Cummins.CalDiv.strings", Assembly.GetExecutingAssembly());
			throw new Exception(resourceManager.GetString("ChecksumError"));
		}
		return text3;
	}

	public string BuildFixTableLengthRecord(int table, uint length, bool sizeWord)
	{
		string text = ((table <= 65535 && length <= 65535) ? "X4" : "X8");
		string text2 = "*F" + table.ToString(text) + length.ToString(text);
		text2 += (sizeWord ? "Y" : "N");
		if (!Checksum.AddLineChecksum(ref text2))
		{
			ResourceManager resourceManager = new ResourceManager("Cummins.CalDiv.strings", Assembly.GetExecutingAssembly());
			throw new Exception(resourceManager.GetString("ChecksumError"));
		}
		return text2;
	}

	public string BuildHeaderRecord(string filename, string[] notes)
	{
		string text = "*H" + filename;
		for (int i = 0; i < 7; i++)
		{
			text += ",";
			if (i < notes.Length)
			{
				text += notes[i];
			}
		}
		return text;
	}

	public string BuildIdentificationRecord(int subfileType, SubfileStatus status)
	{
		string text = "";
		if (subfileType >= 1 && subfileType <= 8)
		{
			int num = (int)status;
			text = "*C" + num.ToString("X2") + subfileType.ToString("X2");
			if (!Checksum.AddLineChecksum(ref text))
			{
				ResourceManager resourceManager = new ResourceManager("Cummins.CalDiv.strings", Assembly.GetExecutingAssembly());
				throw new Exception(resourceManager.GetString("ChecksumError"));
			}
			return text;
		}
		ResourceManager resourceManager2 = new ResourceManager("Cummins.CalDiv.strings", Assembly.GetExecutingAssembly());
		throw new Exception(resourceManager2.GetString("SubfileTypeError"));
	}

	public string BuildSoftwareDateCompatibilityRecord(string startDate, string endDate)
	{
		string line = "";
		if (startDate.Length == 10 && endDate.Length == 10)
		{
			line = "*R" + startDate + endDate;
			if (!Checksum.AddLineChecksum(ref line))
			{
				ResourceManager resourceManager = new ResourceManager("Cummins.CalDiv.strings", Assembly.GetExecutingAssembly());
				throw new Exception(resourceManager.GetString("ChecksumError"));
			}
		}
		return line;
	}

	public string BuildSoftwareVersionCompatability(string startVersion, string endVersion)
	{
		string line = "";
		if (startVersion.Length == 8 && endVersion.Length == 8)
		{
			ValidateVersion(startVersion, endVersion);
			line = "*V" + startVersion + endVersion;
			if (!Checksum.AddLineChecksum(ref line))
			{
				ResourceManager resourceManager = new ResourceManager("Cummins.CalDiv.strings", Assembly.GetExecutingAssembly());
				throw new Exception(resourceManager.GetString("ChecksumError"));
			}
		}
		return line;
	}

	private void ValidateVersion(string startVersion, string endVersion)
	{
		int num = 0;
		int num2 = 0;
		string text = "";
		try
		{
			num = int.Parse(startVersion);
			num2 = int.Parse(endVersion);
		}
		catch
		{
		}
		if (num2 < num)
		{
			text = "Error: Activation version number " + startVersion + " is greater than Deactivation version number " + endVersion + ".";
			throw new InvalidActivationDeactivationException(CalibrationDivideMessageId.ActivationDeactivationNotCompatible, text, startVersion, endVersion);
		}
	}

	public string BuildTableForcedLocationRecord(int table, uint address, int offset, bool sizeWord, BitSize bitSize)
	{
		string text = "X8";
		text = ((bitSize == BitSize.Sixteen) ? "X4" : "X8");
		string text2 = ((table <= 65535) ? "X4" : "X8");
		string text3 = "*L" + table.ToString(text2) + address.ToString(text) + offset.ToString(text);
		text3 += (sizeWord ? "Y" : "N");
		if (!Checksum.AddLineChecksum(ref text3))
		{
			ResourceManager resourceManager = new ResourceManager("Cummins.CalDiv.strings", Assembly.GetExecutingAssembly());
			throw new Exception(resourceManager.GetString("ChecksumError"));
		}
		return text3;
	}

	public string BuildTruncateTableLengthRecod(int table, uint length, bool sizeWord, BitSize bitSize)
	{
		string text = ((bitSize == BitSize.Sixteen) ? "X4" : "X8");
		string text2 = "*T" + table.ToString(text) + length.ToString(text);
		text2 += (sizeWord ? "Y" : "N");
		if (!Checksum.AddLineChecksum(ref text2))
		{
			ResourceManager resourceManager = new ResourceManager("Cummins.CalDiv.strings", Assembly.GetExecutingAssembly());
			throw new Exception(resourceManager.GetString("ChecksumError"));
		}
		return text2;
	}

	public string BuildGTISHeaderInformationRecord(string text)
	{
		return "*G" + text;
	}
}
public delegate void ProgressUpdateEventHandler(object sender, ProgressUpdateEventArgs e);
public delegate void MessageUpdateEventHandler(object sender, MessageUpdateEventArgs e);
public delegate void ProgressCompleteEventHandler(object sender, DivideCompleteEventArgs e);
public delegate void InterruptEventHandler(object sender, MessageInterruptEventArgs e);
public enum MessageTypes
{
	Information = 0,
	Warning = 1,
	Error = 1
}
public class MessageUpdateEventArgs : EventArgs
{
	private string message;

	private MessageTypes messageType;

	public string Message
	{
		get
		{
			return message;
		}
		set
		{
			message = value;
		}
	}

	public MessageTypes MessageType
	{
		get
		{
			return messageType;
		}
		set
		{
			messageType = value;
		}
	}
}
public class Pre38CalibrationDivide : CalibrationDivide
{
	private const string MAXDATE = "1266599";

	private const string SPARE = "SPARE";

	private const string blockDataStructure = "ConfigFile.BLOKDATA";

	public override BitSize TRecordBitSize => BitSize.Sixteen;

	public override BitSize LRecordBitSize
	{
		get
		{
			if (base.ProductID == "BVO" || base.ProductID == "CNG" || base.ProductID == "BNG" || base.ProductID == "IND" || base.ProductID == "ECI")
			{
				return BitSize.Sixteen;
			}
			return BitSize.ThirtyTwo;
		}
	}

	public override IndexTable indexTable
	{
		get
		{
			if (gtisIndexTable == null)
			{
				if (base.ProductID == "ECI")
				{
					gtisIndexTable = new ECIIndexTable(calibration);
				}
				else
				{
					gtisIndexTable = new GTIS20IndexTable(calibration);
				}
			}
			return gtisIndexTable;
		}
	}

	public override string BlockDataStructure => "ConfigFile.BLOKDATA";

	protected override void PopulateDataRecords()
	{
		DataTable dataTable = calibration.Parameters.Tables["Parameter"].Copy();
		for (int i = 0; i < base.RequestedSubfiles.Count; i++)
		{
			if ((Subfile)subfiles[i] != null && ((Subfile)subfiles[i]).ToWrite)
			{
				DataRow[] parameters = dataTable.Select("(AvailableOffline = 'true') and (SubfileNumber = " + (i + 1) + ")");
				WriteParameters(parameters);
			}
		}
	}

	protected override void AddSoftwareVersionCompatibilityRecords(bool romDependentDesired)
	{
		string headerRecord = "";
		string calibrationDate = GetCalibrationDate();
		string text = calibrationDate.PadRight(10, '0');
		foreach (Subfile subfile in subfiles)
		{
			if (subfile == null)
			{
				continue;
			}
			int num = subfile.SubfileType - 1;
			bool flag = subfile.SubfileType == 3;
			if ((!flag || !romDependentDesired) && (flag || romDependentDesired))
			{
				continue;
			}
			if (!flag && !romDependentDesired)
			{
				string text2 = earliestActivationDateInConfigFile[num];
				string text3 = latestIncompatibleDeactivationDateInConfigFile[num];
				string firstDate = latestDeactivationDateInConfigFile[num];
				if (CompareDates(text2, calibrationDate) == 1)
				{
					subfile.ToWrite = false;
					string text4 = string.Format(CalibrationDivide.resources.GetString("ActivationDateNotValid"), subfile.SubfileType, calibrationDate);
					text4 += string.Format(CalibrationDivide.resources.GetString("AbortDivideForASubfile"), subfile.SubfileType);
					ReportErrorMessage(text4);
				}
				if (CompareDates(firstDate, calibrationDate) == -1)
				{
					subfile.ToWrite = false;
					string text5 = string.Format(CalibrationDivide.resources.GetString("DeactivationDateNotValid"), subfile.SubfileType, calibrationDate);
					text5 += string.Format(CalibrationDivide.resources.GetString("AbortDivideForASubfile"), subfile.SubfileType);
					ReportErrorMessage(text5);
				}
				string text6 = "";
				text6 = ((text3 != null && CompareDates(text2, text3) != 1) ? DateTime.ParseExact(text3, "MMddyy", new CultureInfo("en-US")).AddDays(1.0).ToString("MMddyy")
					.PadRight(10, '0') : text2.PadRight(10, '0'));
				headerRecord = headerBuilder.BuildSoftwareDateCompatibilityRecord(text6, text);
			}
			else if (flag && romDependentDesired)
			{
				headerRecord = headerBuilder.BuildSoftwareDateCompatibilityRecord(text, text);
			}
			subfile.AddHeaderRecord(headerRecord);
		}
	}

	protected override void AddTabelType4Length()
	{
		calibration.ParametersInfo.ResetSelectionStatus(selectionStatus: true);
		StringCollection selectedParameters = calibration.ParametersInfo.SelectedParameters;
		StringEnumerator enumerator = selectedParameters.GetEnumerator();
		try
		{
			while (enumerator.MoveNext())
			{
				string current = enumerator.Current;
				IParamInfo paramInfo = calibration.ParametersInfo[current];
				try
				{
					if (paramInfo != null && paramInfo.FullName.StartsWith("ConfigFile") && paramInfo.ConfigFileType == 76)
					{
						indexTable[paramInfo.IndexTable]["TableType"] = IndexTable.TableTypeEnum.TableType4;
						indexTable[paramInfo.IndexTable][2] = paramInfo.Size;
					}
				}
				catch (Exception)
				{
				}
			}
		}
		finally
		{
			if (enumerator is IDisposable disposable)
			{
				disposable.Dispose();
			}
		}
	}

	protected override void AddDataplateLocationRecord()
	{
		int num = 13;
		if (base.ProductID == "IND" || base.ProductID == "COR")
		{
			num = 24;
		}
		if (base.ProductID == "BNG" || base.ProductID == "BVO" || base.ProductID == "CNG")
		{
			num = 61;
		}
		if (base.ProductID == "ECI")
		{
			num = 7;
		}
		uint num2 = 0u;
		int offset = 0;
		num2 = (uint)indexTable[num]["Size"];
		string headerRecord = headerBuilder.BuildDataplateLocationRecord(num, offset, base.ProductID, num2);
		((Subfile)subfiles[2]).AddHeaderRecord(headerRecord);
	}

	private void WriteParameters(DataRow[] parameters)
	{
		object obj = null;
		string calibrationDate = GetCalibrationDate();
		foreach (DataRow dataRow in parameters)
		{
			if (dataRow["FullName"].ToString().StartsWith("DataStructures.DataplateStructure"))
			{
				continue;
			}
			IEntityModel entityModel = (IEntityModel)calibration.Get((string)dataRow["Name"]);
			if (entityModel is IEnumerationModel)
			{
				continue;
			}
			Cummins.Interop.CalDataServer.ICISymbolicData iCISymbolicData = (Cummins.Interop.CalDataServer.ICISymbolicData)(entityModel.CalEntity as Cummins.Interop.SymbolicTree.ICITreeNode).Data;
			int num = entityModel.SubfileNumber - 1;
			if (num < 0 || num > 7)
			{
				continue;
			}
			switch (entityModel.ConfigFileType)
			{
			case 67:
			{
				if (base.ProductID == "IND" && iCISymbolicData.Name.StartsWith("SPARE"))
				{
					continue;
				}
				uint address2 = (uint)indexTable.Rows[iCISymbolicData.IndexTable]["Address"];
				uint length2 = (uint)indexTable.Rows[iCISymbolicData.IndexTable]["Size"];
				obj = ReadData(address2, length2);
				break;
			}
			case 84:
			case 88:
			case 89:
			case 90:
				if (base.ProductID != "ECI")
				{
					uint address = (uint)indexTable.Rows[iCISymbolicData.IndexTable]["Address"];
					uint length = (uint)indexTable.Rows[iCISymbolicData.IndexTable]["Size"];
					obj = ReadData(address, length);
				}
				else
				{
					obj = (entityModel.CalEntity as ICICalAddressableEntity).RawData;
				}
				break;
			default:
				obj = (entityModel.CalEntity as ICICalAddressableEntity).RawData;
				break;
			}
			if (CompareDates(iCISymbolicData.ActivationVersion, calibrationDate) != 1 && CompareDates(calibrationDate, iCISymbolicData.DeactivationVersion) != 1)
			{
				if (base.ProductID == "ECI")
				{
					((Subfile)subfiles[num]).AddDataRecord((int)indexTable[iCISymbolicData.IndexTable]["Address"], (int)iCISymbolicData.address - (int)indexTable[iCISymbolicData.IndexTable]["Address"], ref obj);
				}
				else
				{
					((Subfile)subfiles[num]).AddDataRecord(iCISymbolicData.IndexTable, (int)iCISymbolicData.AddressingOffset, ref obj);
				}
			}
		}
	}

	protected override void SetActivationInformation(IParamInfo symbolicData)
	{
		int num = 0;
		string calibrationDate = GetCalibrationDate();
		try
		{
			num = int.Parse(symbolicData.SubfileName) - 1;
		}
		catch
		{
			string message = CalibrationDivide.resources.GetString("SubfileTypeError") + "for parameter " + symbolicData.Name;
			throw new InvalidSubfileNumberException(CalibrationDivideMessageId.SubfileNumberIncorrect, message);
		}
		try
		{
			if (0 > num || 7 < num)
			{
				return;
			}
			char c = '\0';
			try
			{
				c = (char)symbolicData.ConfigFileType;
			}
			catch (Exception)
			{
			}
			if (c != 'A' && c != 'R' && c != 'L' && !symbolicData.Name.StartsWith("SPARE"))
			{
				if (earliestActivationDateInConfigFile[num] == null || CompareDates(earliestActivationDateInConfigFile[num], symbolicData.ActivationVersion) == 1)
				{
					earliestActivationDateInConfigFile[num] = symbolicData.ActivationVersion;
				}
				if (latestDeactivationDateInConfigFile[num] == null || CompareDates(latestDeactivationDateInConfigFile[num], symbolicData.DeactivationVersion) == -1)
				{
					latestDeactivationDateInConfigFile[num] = symbolicData.DeactivationVersion;
				}
				if (symbolicData.DeactivationVersion != "1266599" && CompareDates(symbolicData.DeactivationVersion, calibrationDate) == -1 && (latestIncompatibleDeactivationDateInConfigFile[num] == null || CompareDates(latestIncompatibleDeactivationDateInConfigFile[num], symbolicData.DeactivationVersion) == -1))
				{
					latestIncompatibleDeactivationDateInConfigFile[num] = symbolicData.DeactivationVersion;
				}
			}
		}
		catch (Exception ex2)
		{
			throw new Exception("Unable to SetActivationInformation for parameter " + symbolicData.Name + ":" + ex2.Message);
		}
	}

	protected override void ValidateIndexTable()
	{
	}
}
public class ProgressUpdateEventArgs : EventArgs
{
	private string updateMessage;

	private int updateValue;

	public string UpdateMessage
	{
		get
		{
			return updateMessage;
		}
		set
		{
			updateMessage = value;
		}
	}

	public int UpdateValue
	{
		get
		{
			return updateValue;
		}
		set
		{
			updateValue = value;
		}
	}
}
public class Reporter
{
	public enum Formats
	{
		txt,
		html
	}

	private const string TransformExtension = ".xslt";

	private readonly string TransformPrefix;

	private string tempFilename;

	private XmlTextWriter report;

	private string prefix;

	private Formats format;

	private string reportFilename = string.Empty;

	private string productId;

	private IDirectoryService directoryService;

	private bool appendReport;

	public Reporter(Formats format, string prefix, string calFile, string configFile)
	{
		//IL_0048: Unknown result type (might be due to invalid IL or missing references)
		//IL_0052: Expected O, but got Unknown
		this.prefix = prefix;
		this.format = format;
		TransformPrefix = "Cummins.CalDiv.caldiv_";
		tempFilename = Path.GetTempFileName();
		report = new XmlTextWriter((Stream)File.Open(tempFilename, FileMode.Open, FileAccess.ReadWrite), Encoding.UTF8);
		((XmlWriter)report).WriteStartDocument();
		((XmlWriter)report).WriteStartElement("divide");
		((XmlWriter)report).WriteStartElement("header");
		((XmlWriter)report).WriteAttributeString("date", DateTime.Now.ToShortDateString() + " " + DateTime.Now.ToLongTimeString());
		((XmlWriter)report).WriteStartElement("calibration");
		((XmlWriter)report).WriteElementString("data", calFile);
		((XmlWriter)report).WriteElementString("config", configFile);
		((XmlWriter)report).WriteEndElement();
		((XmlWriter)report).WriteEndElement();
		((XmlWriter)report).WriteStartElement("messages");
		directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
	}

	public Reporter(Formats format, string prefix, string calFile, string configFile, string productId, string reportFilename, bool appendReport)
		: this(format, prefix, calFile, configFile)
	{
		this.reportFilename = reportFilename;
		this.productId = productId;
		this.appendReport = appendReport;
	}

	public Reporter(Formats format, string prefix, string calFile, string configFile, string productId, string reportFilename)
		: this(format, prefix, calFile, configFile)
	{
		this.reportFilename = reportFilename;
		this.productId = productId;
	}

	public void Close(bool showReport)
	{
		//IL_0064: Unknown result type (might be due to invalid IL or missing references)
		//IL_006a: Expected O, but got Unknown
		//IL_006a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0070: Expected O, but got Unknown
		//IL_00a1: Unknown result type (might be due to invalid IL or missing references)
		//IL_00a8: Expected O, but got Unknown
		//IL_00ac: Unknown result type (might be due to invalid IL or missing references)
		//IL_00b6: Expected O, but got Unknown
		((XmlWriter)report).WriteEndElement();
		((XmlWriter)report).WriteEndDocument();
		((XmlWriter)report).Flush();
		report.BaseStream.Seek(0L, SeekOrigin.Begin);
		StreamWriter streamWriter = null;
		streamWriter = ((!appendReport) ? File.CreateText(reportFilename) : File.AppendText(reportFilename));
		XPathDocument val = new XPathDocument(report.BaseStream);
		XslTransform val2 = new XslTransform();
		string name = TransformPrefix + format.ToString().ToLower() + ".xslt";
		XmlTextReader val3 = new XmlTextReader(Assembly.GetExecutingAssembly().GetManifestResourceStream(name));
		val2.Load((IXPathNavigable)new XPathDocument((XmlReader)(object)val3, (XmlSpace)2));
		val2.Transform((IXPathNavigable)(object)val, (XsltArgumentList)null, (TextWriter)streamWriter);
		streamWriter.WriteLine();
		streamWriter.WriteLine();
		((XmlReader)val3).Close();
		streamWriter.Close();
		File.Delete(tempFilename);
		if (showReport)
		{
			Process.Start(reportFilename);
		}
	}

	public void WriteMessage(string message)
	{
		((XmlWriter)report).WriteElementString("message", message);
	}

	public Reporter(Formats format, string prefix, string calFile, string configFile, string reportName, IDirectoryService directoryService)
		: this(format, prefix, calFile, configFile, "ABC", reportName)
	{
		if (directoryService != null)
		{
			this.directoryService = directoryService;
			TransformPrefix = "UTCalibrationDivide.Code.caldiv_";
		}
	}
}
public class ReportStep : BaseStep
{
	private Label labelPrefix;

	private Label labelFormat;

	private TextBox reportPrefix;

	private ComboBox reportFormat;

	private IContainer components;

	private ErrorProvider prefixError;

	public string Prefix
	{
		get
		{
			if (!(((Control)reportPrefix).Text != ""))
			{
				return "caldiv";
			}
			return ((Control)reportPrefix).Text;
		}
	}

	public Reporter.Formats ReportFormat => (Reporter.Formats)Enum.Parse(typeof(Reporter.Formats), ((Control)reportFormat).Text);

	public ReportStep()
	{
		InitializeComponent();
		Initialize();
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		base.Dispose(disposing);
	}

	private void Initialize()
	{
		foreach (Reporter.Formats value in Enum.GetValues(typeof(Reporter.Formats)))
		{
			base.Description = "Select the format and prefix for the report";
			reportFormat.Items.Add((object)value.ToString());
		}
		IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		if (appConfigService != null)
		{
			((Control)reportFormat).Text = appConfigService.GetAppSetting(ApplicationSettings.GeneralReportFormat);
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
		labelPrefix = new Label();
		labelFormat = new Label();
		reportPrefix = new TextBox();
		reportFormat = new ComboBox();
		prefixError = new ErrorProvider();
		((Control)this).SuspendLayout();
		((Control)labelPrefix).Location = new Point(152, 72);
		((Control)labelPrefix).Name = "labelPrefix";
		((Control)labelPrefix).Size = new Size(48, 23);
		((Control)labelPrefix).TabIndex = 1;
		((Control)labelPrefix).Text = "Prefix:";
		((Control)labelFormat).Location = new Point(152, 96);
		((Control)labelFormat).Name = "labelFormat";
		((Control)labelFormat).Size = new Size(48, 23);
		((Control)labelFormat).TabIndex = 2;
		((Control)labelFormat).Text = "Format:";
		((Control)reportPrefix).Location = new Point(200, 72);
		((Control)reportPrefix).Name = "reportPrefix";
		((Control)reportPrefix).Size = new Size(120, 20);
		((Control)reportPrefix).TabIndex = 3;
		((Control)reportPrefix).Text = "";
		((Control)reportPrefix).TextChanged += reportPrefixSelect_TextChanged;
		((Control)reportPrefix).Validating += prefix_Validating;
		prefixError.DataMember = null;
		reportFormat.DropDownStyle = (ComboBoxStyle)2;
		((Control)reportFormat).Location = new Point(200, 96);
		((Control)reportFormat).Name = "reportFormat";
		((Control)reportFormat).Size = new Size(120, 21);
		((Control)reportFormat).TabIndex = 4;
		((Control)this).Controls.AddRange((Control[])(object)new Control[4]
		{
			(Control)reportFormat,
			(Control)reportPrefix,
			(Control)labelFormat,
			(Control)labelPrefix
		});
		base.IsFinished = true;
		((Control)this).Name = "ReportStep";
		base.PreviousStep = "SubfileSelectionStep";
		base.NextStep = "FINISHED";
		base.StepTitle = "Report Selection";
		base.ShowStep += ReportStep_ShowStep;
		((Control)this).ResumeLayout(false);
	}

	private void ReportStep_ShowStep(object sender, EventArgs e)
	{
		((Control)reportPrefix).Text = "caldiv";
	}

	private void reportPrefixSelect_TextChanged(object sender, EventArgs e)
	{
		string text = ((Control)reportPrefix).Text;
		base.Wizard.FinishEnabled = text.Trim() != "";
	}

	private void prefix_Validating(object sender, CancelEventArgs e)
	{
		if (((Control)reportPrefix).Text.IndexOf(Path.AltDirectorySeparatorChar) != -1 || ((Control)reportPrefix).Text.IndexOf(Path.DirectorySeparatorChar) != -1 || ((Control)reportPrefix).Text.IndexOf(Path.PathSeparator) != -1 || ((Control)reportPrefix).Text.IndexOf(Path.VolumeSeparatorChar) != -1 || ((Control)reportPrefix).Text.IndexOfAny(Path.InvalidPathChars) != -1)
		{
			e.Cancel = true;
			prefixError.SetError((Control)(object)reportPrefix, "Invalid character in prefix");
		}
	}
}
public class Subfile
{
	private const short MaximumFileVersion = 99;

	private const string Decimal2 = "D2";

	private const short Overwrite = 1;

	private const string SubfileChars = " ABCDEFGH";

	private const string FilenameFormat = "{0}.{1}{2}";

	private const string PathFormat = "{0}\\{1}";

	private string filename;

	private short subfileType;

	private SubFileComponent subfileFile;

	private bool toWrite = true;

	public string Filename
	{
		get
		{
			return filename;
		}
		set
		{
			filename = value;
		}
	}

	public short SubfileType
	{
		get
		{
			return subfileType;
		}
		set
		{
			subfileType = value;
		}
	}

	public bool ToWrite
	{
		get
		{
			return toWrite;
		}
		set
		{
			toWrite = value;
		}
	}

	public Subfile(short subfileType, string filename)
	{
		SubfileType = subfileType;
		Filename = filename;
		toWrite = true;
		LicensedComWrapper licensedComWrapper = new LicensedComWrapper(ComClassID.Subfiles);
		subfileFile = (SubFileComponent)licensedComWrapper.GetComInstance();
	}

	public void AddHeaderRecord(string headerRecord)
	{
		ICIHeaderRecords iCIHeaderRecords = (ICIHeaderRecords)subfileFile;
		iCIHeaderRecords.AppendCalHeader(headerRecord);
	}

	public void AddDataRecord(int origin, int offset, ref object data)
	{
		byte[] array = (byte[])data;
		ICIBinaryDataList iCIBinaryDataList = (ICIBinaryDataList)subfileFile;
		BinaryData binaryData = new BinaryDataClass();
		binaryData.Location = origin;
		binaryData.Length = array.Length;
		binaryData.Offset = offset;
		binaryData.BinaryData = data;
		iCIBinaryDataList.AddImage(binaryData);
	}

	public string Write()
	{
		string text = "";
		bool flag = true;
		int num = 0;
		string text2 = "";
		string arg = " ABCDEFGH"[subfileType].ToString();
		while (flag && num < 99)
		{
			text = string.Format("{0}.{1}{2}", Path.GetFileName(filename), arg, num.ToString("D2"));
			text2 = $"{Path.GetDirectoryName(filename)}\\{text}";
			flag = File.Exists(text2);
			num++;
		}
		subfileFile.WriteFile(text2, 1);
		return text;
	}
}
public class SubfileRequest
{
	private string subfileTitle;

	private bool selected;

	private string filename;

	public string SubfileTitle
	{
		get
		{
			return subfileTitle;
		}
		set
		{
			subfileTitle = value;
		}
	}

	public bool Selected
	{
		get
		{
			return selected;
		}
		set
		{
			selected = value;
		}
	}

	public string Filename
	{
		get
		{
			return filename;
		}
		set
		{
			filename = value;
		}
	}

	public SubfileRequest(string subfileTitle, bool selected, string filename)
	{
		SubfileTitle = subfileTitle;
		Selected = selected;
		Filename = filename;
	}
}
public class SubfileSelectionStep : BaseStep
{
	private const string InvalidChars = ":*?<>\"|\\/";

	private const string Step1Name = "FileSelectionStep";

	private const string FilenameError = "The filename is not valid.";

	private const string ErrorBoxTitle = "Error";

	private ListView subfileList;

	private ArrayList requestedSubfiles;

	private TextBox subfileName;

	private Label labelNote1;

	private Label labelNote2;

	private Button changeName;

	private Label labelSubfileName;

	private Container components;

	public SubfileSelectionStep(ArrayList requests)
	{
		//IL_0095: Unknown result type (might be due to invalid IL or missing references)
		//IL_009b: Expected O, but got Unknown
		requestedSubfiles = requests;
		InitializeComponent();
		base.Description = "Select the subfile to generate";
		subfileList.Columns.Add("Subfile Contents", ((Control)subfileList).Size.Width / 2 - 4, (HorizontalAlignment)0);
		subfileList.Columns.Add("Subfile Filename", ((Control)subfileList).Size.Width / 2, (HorizontalAlignment)0);
		for (int i = 0; i < requestedSubfiles.Count; i++)
		{
			SubfileRequest subfileRequest = (SubfileRequest)requestedSubfiles[i];
			ListViewItem val = new ListViewItem(subfileRequest.SubfileTitle);
			val.SubItems.Add(subfileRequest.Filename);
			val.Checked = subfileRequest.Selected;
			subfileList.Items.Add(val);
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
		//IL_00c3: Unknown result type (might be due to invalid IL or missing references)
		//IL_00cd: Expected O, but got Unknown
		subfileList = new ListView();
		subfileName = new TextBox();
		labelNote1 = new Label();
		labelNote2 = new Label();
		changeName = new Button();
		labelSubfileName = new Label();
		((Control)this).SuspendLayout();
		subfileList.CheckBoxes = true;
		subfileList.HideSelection = false;
		((Control)subfileList).Location = new Point(24, 40);
		((Control)subfileList).Name = "subfileList";
		((Control)subfileList).Size = new Size(376, 171);
		((Control)subfileList).TabIndex = 8;
		subfileList.View = (View)1;
		subfileList.ItemChecked += new ItemCheckedEventHandler(OnSubfileListItemChecked);
		subfileList.SelectedIndexChanged += OnSubfileListSelectedIndexChanged;
		subfileName.AcceptsReturn = true;
		((Control)subfileName).Enabled = false;
		((Control)subfileName).Location = new Point(88, 250);
		((Control)subfileName).Name = "subfileName";
		((Control)subfileName).Size = new Size(192, 20);
		((Control)subfileName).TabIndex = 10;
		((Control)subfileName).Text = "";
		((Control)labelNote1).Location = new Point(16, 252);
		((Control)labelNote1).Name = "labelNote1";
		((Control)labelNote1).Size = new Size(80, 16);
		((Control)labelNote1).TabIndex = 9;
		((Control)labelNote1).Text = "Subfile Name:";
		((Control)labelNote2).Location = new Point(16, 226);
		((Control)labelNote2).Name = "labelNote2";
		((Control)labelNote2).Size = new Size(408, 16);
		((Control)labelNote2).TabIndex = 12;
		((Control)labelNote2).Text = "Highlight lines and select the Change Name button to change the subfile names.";
		((Control)changeName).Enabled = false;
		((Control)changeName).Location = new Point(288, 249);
		((Control)changeName).Name = "changeName";
		((Control)changeName).Size = new Size(96, 23);
		((Control)changeName).TabIndex = 11;
		((Control)changeName).Text = "Change Name";
		((Control)changeName).Click += changeName_Click;
		((Control)labelSubfileName).Location = new Point(24, 16);
		((Control)labelSubfileName).Name = "labelSubfileName";
		((Control)labelSubfileName).Size = new Size(272, 16);
		((Control)labelSubfileName).TabIndex = 13;
		((Control)labelSubfileName).Text = "Check the boxes of the subfiles to create.";
		((Control)this).Controls.AddRange((Control[])(object)new Control[6]
		{
			(Control)labelSubfileName,
			(Control)labelNote2,
			(Control)changeName,
			(Control)subfileName,
			(Control)labelNote1,
			(Control)subfileList
		});
		((Control)this).Name = "SubfileSelectionStep";
		base.NextStep = "ReportStep";
		base.PreviousStep = "FileSelectionStep";
		((Control)this).Size = new Size(416, 272);
		base.StepTitle = "Subfile Selection";
		base.ShowStep += SubfileSelectionStep_ShowStep;
		((Control)this).ResumeLayout(false);
	}

	private void SubfileSelectionStep_ShowStep(object sender, EventArgs e)
	{
		BaseWizard baseWizard = base.Wizard;
		bool nextEnabled = (base.Wizard.FinishEnabled = subfileList.CheckedIndices.Count != 0);
		baseWizard.NextEnabled = nextEnabled;
		for (int i = 0; i < requestedSubfiles.Count; i++)
		{
			subfileList.Items[i].SubItems[1].Text = ((SubfileRequest)requestedSubfiles[i]).Filename;
		}
	}

	private void changeName_Click(object sender, EventArgs e)
	{
		//IL_0032: Unknown result type (might be due to invalid IL or missing references)
		if (ValidFilename(((Control)subfileName).Text))
		{
			SetSelectedFilenames(((Control)subfileName).Text);
		}
		else
		{
			MessageBox.Show("The filename is not valid.", "Error", (MessageBoxButtons)0, (MessageBoxIcon)16);
		}
	}

	private bool ValidFilename(string filename)
	{
		bool result = false;
		if (filename.TrimStart(new char[1] { ' ' }).Length != 0)
		{
			result = filename.IndexOfAny(":*?<>\"|\\/".ToCharArray()) < 0;
		}
		return result;
	}

	private void SetSelectedFilenames(string filename)
	{
		SelectedIndexCollection selectedIndices = subfileList.SelectedIndices;
		foreach (int item in selectedIndices)
		{
			SubfileRequest subfileRequest = (SubfileRequest)requestedSubfiles[item];
			subfileRequest.Filename = filename;
			subfileList.Items[item].SubItems[1].Text = filename;
		}
	}

	private void OnSubfileListItemChecked(object sender, ItemCheckedEventArgs e)
	{
		BaseWizard baseWizard = base.Wizard;
		bool nextEnabled = (base.Wizard.FinishEnabled = subfileList.CheckedIndices.Count != 0);
		baseWizard.NextEnabled = nextEnabled;
		((SubfileRequest)requestedSubfiles[e.Item.Index]).Selected = e.Item.Checked;
	}

	private void OnSubfileListSelectedIndexChanged(object sender, EventArgs e)
	{
		((Control)changeName).Enabled = subfileList.SelectedIndices.Count != 0;
		((Control)subfileName).Enabled = ((Control)changeName).Enabled;
		if (subfileList.SelectedIndices.Count <= 0)
		{
			return;
		}
		int num = subfileList.SelectedIndices[0];
		string text = subfileList.Items[num].SubItems[1].Text;
		for (int i = 1; i < subfileList.SelectedIndices.Count; i++)
		{
			num = subfileList.SelectedIndices[i];
			if (string.Compare(text, subfileList.Items[num].SubItems[1].Text) != 0)
			{
				text = "";
			}
		}
		((Control)subfileName).Text = text;
	}
}
public class Wizard : BaseWizard
{
	private const string Step1 = "FileSelectionStep";

	private const string Step2 = "SubfileSelectionStep";

	private const string Step3 = "ReportStep";

	private const string WizardTitle = "Calibration Divide";

	private static string[] ECISubfiles = new string[6] { "Engine Control", "Electronic Constants", "ROM Configuration", "Engine Configuration", "Sequencing", "Customer Specific" };

	private static string[] INDSubfiles = new string[4] { "Engine Control Data", "Electronic Constants", "Engine Control Code", "Application Constants" };

	private static string[] GENSubfiles = new string[8] { "Engine Control Data", "Electronic Constants", "Engine Control Code", "Engine Config Data", "Performance Control", "System Control Data", "Installation Trim", "Application Control" };

	private static string[] CESSubfiles = new string[8] { "AFTERTREATME CONTROL DATA", "AFM CONSTANTS DATA", "AFTERTREATME CONTROL CODE", "AFM CONFIGURATIO DATA", "AFM PFM CONTROL DATA", "AFM SYSTEM CONTROL DATA", "AFM ISN TRIM DATA", "AFM APL CONTROL DAT" };

	private FileSelectionStep fileSelectionStep;

	private SubfileSelectionStep subfileSelectionStep;

	private ReportStep reportStep;

	private Container components;

	private GTISVersion gtisVersion;

	private ArrayList requestedSubfiles;

	private string productID;

	public FileSelectionStep FileSelection => fileSelectionStep;

	public ReportStep Report => reportStep;

	private void Create8SubfileInformation()
	{
		for (int i = 0; i < GENSubfiles.GetLength(0); i++)
		{
			requestedSubfiles.Add(new SubfileRequest(GENSubfiles[i], selected: true, "default"));
		}
	}

	private void Create8CESSubfileInformation()
	{
		for (int i = 0; i < CESSubfiles.GetLength(0); i++)
		{
			requestedSubfiles.Add(new SubfileRequest(CESSubfiles[i], selected: true, "default"));
		}
	}

	private void Create4SubfileInformation()
	{
		for (int i = 0; i < INDSubfiles.GetLength(0); i++)
		{
			requestedSubfiles.Add(new SubfileRequest(INDSubfiles[i], selected: true, "default"));
		}
	}

	private void Create6SubfileInformation()
	{
		for (int i = 0; i < ECISubfiles.GetLength(0); i++)
		{
			requestedSubfiles.Add(new SubfileRequest(ECISubfiles[i], selected: true, "default"));
		}
	}

	public Wizard(string product, GTISVersion version)
	{
		IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
		IProduct calTermProduct = productInformationService.GetCalTermProduct(product);
		if (!calTermProduct.ProductType.ToUpper().Equals("CALIBRATION"))
		{
			productID = product;
			requestedSubfiles = new ArrayList();
			switch (product)
			{
			case "IND":
				Create4SubfileInformation();
				break;
			case "ECI":
				Create6SubfileInformation();
				break;
			case "BFN":
			case "BFQ":
			case "BFZ":
			case "BGD":
				Create8CESSubfileInformation();
				break;
			default:
				Create8SubfileInformation();
				break;
			}
			gtisVersion = version;
			InitializeComponent();
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			((Control)this).Text = "Calibration Divide-" + appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			((Form)this).DialogResult = (DialogResult)0;
			return;
		}
		string message = $"The Product ID  {product} is A-Type product and cannot be divided.";
		throw new ProductNotSupportedException(CalibrationDivideMessageId.ProductNotSupported, message);
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
				Help.ShowHelp((Control)(object)this, Application.StartupPath + "\\CaltermIII.chm", (HelpNavigator)(-2147483642), (object)"Divide");
			}
		}
		catch
		{
		}
		return ((Form)this).ProcessCmdKey(ref msg, keyData);
	}

	protected override void OnFinishClicked(EventArgs e)
	{
		try
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			appConfigService.SetLastUsedValue(appSetting, fileSelectionStep.CalibrationFileSelectControl.ConfigFilename, LastUsedType.LastDivideConfigFile);
			appConfigService.SetLastUsedValue(appSetting, fileSelectionStep.CalibrationFileSelectControl.CalibrationFilename, LastUsedType.LastDivideSourceFile);
		}
		catch
		{
		}
		base.OnFinishClicked(e);
	}

	private void WizardLoadSteps(object sender, EventArgs e)
	{
		fileSelectionStep = new FileSelectionStep(gtisVersion, requestedSubfiles);
		AddStep("FileSelectionStep", fileSelectionStep);
		subfileSelectionStep = new SubfileSelectionStep(requestedSubfiles);
		AddStep("SubfileSelectionStep", subfileSelectionStep);
		reportStep = new ReportStep();
		AddStep("ReportStep", reportStep);
		try
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			if (File.Exists(appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastDivideConfigFile)))
			{
				fileSelectionStep.CalibrationFileSelectControl.ConfigFilename = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastDivideConfigFile);
			}
			else
			{
				fileSelectionStep.CalibrationFileSelectControl.ConfigFilename = "";
			}
			if (File.Exists(appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastDivideSourceFile)))
			{
				fileSelectionStep.CalibrationFileSelectControl.CalibrationFilename = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastDivideSourceFile);
			}
			else
			{
				fileSelectionStep.CalibrationFileSelectControl.CalibrationFilename = "";
			}
		}
		catch
		{
		}
	}

	public DivideConfigurationDataSet GetConfiguration()
	{
		DivideConfigurationDataSet divideConfigurationDataSet = new DivideConfigurationDataSet();
		DataRow dataRow = divideConfigurationDataSet.ReporterInformation.NewRow();
		dataRow["ReportPrefix"] = Report.Prefix;
		dataRow["ReportFormat"] = Report.ReportFormat;
		dataRow["ReportFileName"] = "";
		divideConfigurationDataSet.ReporterInformation.Rows.Add(dataRow);
		divideConfigurationDataSet.ReporterInformation.AcceptChanges();
		DataRow dataRow2 = divideConfigurationDataSet.DivideConfiguration.NewRow();
		dataRow2["CalibrationFileName"] = FileSelection.CalibrationFilename;
		dataRow2["ConfigurationFileName"] = FileSelection.ConfigurationFilename;
		dataRow2["PopReport"] = "True";
		dataRow2["productID"] = productID;
		divideConfigurationDataSet.DivideConfiguration.Rows.Add(dataRow2);
		divideConfigurationDataSet.DivideConfiguration.AcceptChanges();
		for (int i = 0; i < requestedSubfiles.Count; i++)
		{
			DataRow dataRow3 = divideConfigurationDataSet.SubfilesInformation.NewRow();
			dataRow3["SubfileNumber"] = i.ToString();
			dataRow3["SubfileName"] = GetFolder(FolderType.UnreleasedCalibration) + "/" + ((SubfileRequest)requestedSubfiles[i]).Filename;
			dataRow3["SubfileSelected"] = ((SubfileRequest)requestedSubfiles[i]).Selected;
			divideConfigurationDataSet.SubfilesInformation.Rows.Add(dataRow3);
			divideConfigurationDataSet.SubfilesInformation.AcceptChanges();
		}
		return divideConfigurationDataSet;
	}

	private string GetFolder(FolderType type)
	{
		string result = string.Empty;
		IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
		if (directoryService != null)
		{
			result = directoryService.FolderName(type, productID);
		}
		return result;
	}

	private void InitializeComponent()
	{
		((Control)wizardTop).Name = "wizardTop";
		((Control)cancel).Name = "cancel";
		((Control)back).Name = "back";
		((Control)next).Name = "next";
		((Control)panelStep).Name = "panelStep";
		((Control)wizardLogo).Name = "wizardLogo";
		((Control)topLine).Name = "topLine";
		((Control)bottomLine).Name = "bottomLine";
		((Control)finish).Name = "finish";
		((Control)stepInfo).Name = "stepInfo";
		((Form)this).AutoScaleBaseSize = new Size(5, 13);
		((Form)this).ClientSize = new Size(696, 398);
		FirstStepName = "FileSelectionStep";
		((Control)this).Name = "Wizard";
		((Control)this).Text = "Calibration Divide";
		LoadSteps += WizardLoadSteps;
	}
}
