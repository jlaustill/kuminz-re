#define TRACE
using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Threading;
using System.Xml;
using Cummins.AddressRepresentation;
using Cummins.Calibration;
using Cummins.EventLog;
using Cummins.Interop;
using Cummins.Interop.DeviceControl;
using Cummins.Interop.Error;
using Cummins.Interop.Message;
using Cummins.Interop.ModuleDetection;
using Cummins.Messages;
using Cummins.ProductInformationProvider;
using Cummins.Services;
using Cummins.Subscription;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyTitle("")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - ModuleNetwork")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.Module;

public class DatalinkConfigurationHelper
{
	public static string DeviceSettingsInlineII(string protocol, string port, string j1939DeviceAddress, string j1939ToolAddress, string productId, string CANSpeed, bool isUnlockTool, bool blockTransfer)
	{
		string text = "9600 Baud ";
		string text2 = "115K Baud ";
		CANSpeed = CANSpeed.Substring(0, 3) + "K Baud";
		string text3 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><dclDeviceConfiguration xmlns=\"\">";
		text3 += "<protocol>";
		text3 = text3 + "<" + protocol + ">";
		if (protocol == "J1939")
		{
			string text4 = ((!blockTransfer) ? "InLine_II" : "InLineIIBlockMode");
			text3 = text3 + "<" + text4 + ">";
			text3 = text3 + "<Port_Number>" + port + "</Port_Number>";
			text3 = text3 + "<PC_BaudRate>" + text2 + "</PC_BaudRate>";
			text3 = text3 + "<DatalinkRate_1939>" + CANSpeed + "</DatalinkRate_1939>";
			text3 = text3 + "</" + text4 + ">";
		}
		else if (protocol == "J1708")
		{
			text3 += "<InLine_II>";
			text3 = text3 + "<Port_Number>" + port + "</Port_Number>";
			text3 = text3 + "<PC_BaudRate>" + text + "</PC_BaudRate>";
			text3 = text3 + "<DLA_BaudRate>" + text + "</DLA_BaudRate>";
			text3 += "</InLine_II>";
		}
		text3 = text3 + "</" + protocol + ">";
		text3 += CheckProtocol(protocol, productId, isUnlockTool);
		text3 += "</protocol>";
		text3 += FigureSourceDestinationAddress(j1939DeviceAddress, j1939ToolAddress);
		text3 += AddOptimization(productId);
		return text3 + "</dclDeviceConfiguration>";
	}

	public static string DeviceSettingsPeakSystems(string protocol, string port, string j1939DeviceAddress, string j1939ToolAddress, string productId, string CANSpeed, bool isUnlockTool, bool blockTransfer)
	{
		CANSpeed = CANSpeed.Substring(0, 3) + "K Baud";
		string text = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><dclDeviceConfiguration xmlns=\"\">";
		text += "<protocol>";
		text = text + "<" + protocol + ">";
		text += "<PeakSys>";
		text += "<Net_Name>Cummins_Net</Net_Name>";
		text = text + "<DatalinkRate_1939>" + CANSpeed + "</DatalinkRate_1939>";
		text += "</PeakSys>";
		text = text + "</" + protocol + ">";
		text += CheckProtocol(protocol, productId, isUnlockTool);
		text += "</protocol>";
		text += FigureSourceDestinationAddress(j1939DeviceAddress, j1939ToolAddress);
		text += AddOptimization(productId);
		return text + "</dclDeviceConfiguration>";
	}

	public static string DeviceSettingsRP1210a(string port, string j1939DeviceAddress, string j1939ToolAddress, string dllName, string deviceId, string productId, string CANSpeed, bool isUnlockTool, bool blockTransfer)
	{
		string text = "J1939";
		CANSpeed = CANSpeed.Substring(0, 3) + "K Baud";
		string text2 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><dclDeviceConfiguration xmlns=\"\">";
		text2 += "<protocol>";
		text2 = text2 + "<" + text + ">";
		string text3 = (blockTransfer ? "0" : "3");
		text2 += "<RP1210a>";
		text2 = text2 + "<Dll_Name>" + dllName + "</Dll_Name>";
		text2 = text2 + "<ServiceID>" + deviceId + "</ServiceID>";
		text2 = text2 + "<DclTransportLevel>" + text3 + "</DclTransportLevel>";
		text2 += "</RP1210a>";
		text2 = text2 + "</" + text + ">";
		text2 += CheckProtocol(text, productId, isUnlockTool);
		text2 += "</protocol>";
		text2 += FigureSourceDestinationAddress(j1939DeviceAddress, j1939ToolAddress);
		text2 += AddOptimization(productId);
		return text2 + "</dclDeviceConfiguration>";
	}

	public static string DeviceSettingsCANCard(string port, string j1939DeviceAddress, string j1939ToolAddress, string productId, string CANSpeed, bool isUnlockTool, bool blockTransfer)
	{
		string text = "J1939";
		CANSpeed = CANSpeed.Substring(0, 3) + "K Baud";
		string text2 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><dclDeviceConfiguration xmlns=\"\">";
		text2 += "<protocol>";
		text2 = text2 + "<" + text + ">";
		text2 += "<CanCard>";
		text2 = text2 + "<Channel>" + port + "</Channel>";
		text2 = text2 + "<DatalinkRate_1939>" + CANSpeed + "</DatalinkRate_1939>";
		text2 += "</CanCard>";
		text2 = text2 + "</" + text + ">";
		text2 += CheckProtocol(text, productId, isUnlockTool);
		text2 += "</protocol>";
		text2 += FigureSourceDestinationAddress(j1939DeviceAddress, j1939ToolAddress);
		text2 += AddOptimization(productId);
		return text2 + "</dclDeviceConfiguration>";
	}

	public static string DeviceSettingsAC2(string port, string j1939DeviceAddress, string j1939ToolAddress, string productId, string CANSpeed, bool isUnlockTool, bool blockTransfer)
	{
		string text = "J1939";
		CANSpeed = CANSpeed.Substring(0, 3) + "K Baud";
		string text2 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><dclDeviceConfiguration xmlns=\"\">";
		text2 += "<protocol>";
		text2 = text2 + "<" + text + ">";
		text2 += "<AC2>";
		text2 = text2 + "<Channel>" + port + "</Channel>";
		text2 += "<MemAddress>d000dfff</MemAddress>";
		text2 = text2 + "<DatalinkRate_1939>" + CANSpeed + "</DatalinkRate_1939>";
		text2 += "</AC2>";
		text2 = text2 + "</" + text + ">";
		text2 += CheckProtocol(text, productId, isUnlockTool);
		text2 += "</protocol>";
		text2 += FigureSourceDestinationAddress(j1939DeviceAddress, j1939ToolAddress);
		text2 += AddOptimization(productId);
		return text2 + "</dclDeviceConfiguration>";
	}

	public static string DeviceSettingsInline(string port, string productId, bool isUnlockTool, bool blockTransfer)
	{
		string text = "9600 Baud ";
		string text2 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><dclDeviceConfiguration xmlns=\"\">";
		text2 += "<protocol>";
		text2 += "<J1708>";
		text2 += "<InLine_InLineI>";
		text2 = text2 + "<Port_Number>" + port + "</Port_Number>";
		text2 = text2 + "<PC_BaudRate>" + text + "</PC_BaudRate>";
		text2 = text2 + "<DLA_BaudRate>" + text + "</DLA_BaudRate>";
		text2 += "</InLine_InLineI>";
		text2 += "</J1708>";
		text2 += CheckProtocol("J1708", productId, isUnlockTool);
		text2 += "</protocol>";
		text2 += AddOptimization(productId);
		return text2 + "</dclDeviceConfiguration>";
	}

	private static string AddOptimization(string productId)
	{
		IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
		IProduct calTermProduct = productInformationService.GetCalTermProduct(productId);
		string text = "<Optimizations>";
		text += "<JoinContiguousReads>DISABLE</JoinContiguousReads>";
		text += "<JoinNearContigReads>DISABLE</JoinNearContigReads>";
		text += "<JoinContiguousWrites>DISABLE</JoinContiguousWrites>";
		text += "<JoinNearContigWrites>DISABLE</JoinNearContigWrites>";
		text += "<CombineMultipleReqst>DISABLE</CombineMultipleReqst>";
		text += "<CombineDuplicateReqst>DISABLE</CombineDuplicateReqst>";
		text += "<UseSmartMailBox>FALSE</UseSmartMailBox>";
		if (calTermProduct.HardwareName.StartsWith("CM4"))
		{
			text += "<EnableRestrictedAccess>DISABLE</EnableRestrictedAccess>";
		}
		return text + "</Optimizations>";
	}

	private static string FigureSourceDestinationAddress(string j1939DeviceAddress, string j1939ToolAddress)
	{
		string text = "<sourceDestinationAddress>";
		text = text + "<sourceAddress>" + j1939ToolAddress + "</sourceAddress>";
		string text2 = j1939DeviceAddress;
		if (text2.ToUpper().IndexOf(":") == -1 && text2.ToUpper().IndexOf("0X") == -1)
		{
			try
			{
				j1939DeviceAddress = Convert.ToString(byte.Parse(j1939DeviceAddress), 16);
			}
			catch (Exception)
			{
				j1939DeviceAddress = Convert.ToString(byte.Parse("0"), 16);
			}
		}
		text = text + "<destinationAddress>" + text2 + "</destinationAddress>";
		return text + "</sourceDestinationAddress>";
	}

	private static string CheckProtocol(string protocol, string productId, bool isUnlockTool)
	{
		string text = string.Empty;
		if (!isUnlockTool)
		{
			DeviceProtocol deviceProtocol = DeviceProtocol.J1939;
			if (protocol == "J1708")
			{
				deviceProtocol = DeviceProtocol.J1708;
			}
			ICIProductMaster iCIProductMaster = new ProductData();
			ICIProductDetail iCIProductDetail = iCIProductMaster[productId];
			ArrayList arrayList = iCIProductDetail.InstructionProtocols(deviceProtocol);
			if (arrayList.Count == 0)
			{
				throw new ProtocolNotSupportedException($"{protocol} Protocol is not supported by product {productId}.", 1, productId);
			}
			if (deviceProtocol == DeviceProtocol.J1708)
			{
				string text2 = "DEVCTRL_" + arrayList[0].ToString();
				text = text + "<InstructionProtocol>" + text2 + "</InstructionProtocol>";
			}
		}
		else if (protocol == "J1708")
		{
			string text3 = "DEVCTRL_CPPJ1708_32";
			text = text + "<InstructionProtocol>" + text3 + "</InstructionProtocol>";
		}
		return text;
	}
}
public class DeviceAddressEventArgs : EventArgs
{
	private IAddressValue deviceAddress;

	public IAddressValue DeviceAddress => deviceAddress;

	public DeviceAddressEventArgs(IAddressValue deviceAddress)
	{
		this.deviceAddress = deviceAddress;
	}
}
public enum MsgID
{
	NoDevicesDetectedAutomatic,
	NotConnectedToAnyManual,
	NoDevicesConnectedAutomatic,
	NoDevicesConnectedManual,
	NoDevicesInitialized,
	NotSupportedProductDetected
}
public class ConnectionException : BaseException
{
	public ConnectionException(Facility facility, short errorNo)
		: base(facility, errorNo)
	{
	}

	public ConnectionException(Facility facility, short errorNo, string message)
		: base(facility, errorNo, message)
	{
	}

	public ConnectionException(Facility facility, short errorNo, string message, Exception inner)
		: base(facility, errorNo, message, inner)
	{
	}

	public ConnectionException(Facility facility, short errorNo, string message, string context)
		: base(facility, errorNo, message, context)
	{
	}

	public ConnectionException(Facility facility, short errorNo, string message, string context, Exception inner)
		: base(facility, errorNo, message, context, inner)
	{
	}
}
public class NoDevicesDetectedException : ConnectionException
{
	public NoDevicesDetectedException(Facility facility, short errorNo)
		: base(facility, errorNo)
	{
	}

	public NoDevicesDetectedException(Facility facility, short errorNo, string message)
		: base(facility, errorNo, message)
	{
	}

	public NoDevicesDetectedException(Facility facility, short errorNo, string message, Exception inner)
		: base(facility, errorNo, message, inner)
	{
	}

	public NoDevicesDetectedException(Facility facility, short errorNo, string message, string destination)
		: base(facility, errorNo, message, destination)
	{
	}

	public NoDevicesDetectedException(Facility facility, short errorNo, string message, string destination, Exception inner)
		: base(facility, errorNo, message, destination, inner)
	{
	}
}
public class NoDevicesAvailableException : ConnectionException
{
	public NoDevicesAvailableException(Facility facility, short errorNo)
		: base(facility, errorNo)
	{
	}

	public NoDevicesAvailableException(Facility facility, short errorNo, string message)
		: base(facility, errorNo, message)
	{
	}

	public NoDevicesAvailableException(Facility facility, short errorNo, string message, Exception inner)
		: base(facility, errorNo, message, inner)
	{
	}

	public NoDevicesAvailableException(Facility facility, short errorNo, string message, string destination)
		: base(facility, errorNo, message, destination)
	{
	}

	public NoDevicesAvailableException(Facility facility, short errorNo, string message, string destination, Exception inner)
		: base(facility, errorNo, message, destination, inner)
	{
	}
}
public class NoDevicesConnectedException : ConnectionException
{
	public int DetectedDevicesCount;

	public NoDevicesConnectedException(Facility facility, short errorNo)
		: base(facility, errorNo)
	{
	}

	public NoDevicesConnectedException(Facility facility, short errorNo, string message)
		: base(facility, errorNo, message)
	{
	}

	public NoDevicesConnectedException(Facility facility, short errorNo, string message, Exception inner)
		: base(facility, errorNo, message, inner)
	{
	}

	public NoDevicesConnectedException(Facility facility, short errorNo, string message, string destination)
		: base(facility, errorNo, message, destination)
	{
	}

	public NoDevicesConnectedException(Facility facility, short errorNo, string message, string destination, Exception inner)
		: base(facility, errorNo, message, destination, inner)
	{
	}
}
public class NoDevicesInitializedException : ConnectionException
{
	public int DetectedDevicesCount;

	public NoDevicesInitializedException(Facility facility, short errorNo)
		: base(facility, errorNo)
	{
	}

	public NoDevicesInitializedException(Facility facility, short errorNo, string message)
		: base(facility, errorNo, message)
	{
	}

	public NoDevicesInitializedException(Facility facility, short errorNo, string message, Exception inner)
		: base(facility, errorNo, message, inner)
	{
	}

	public NoDevicesInitializedException(Facility facility, short errorNo, string message, string destination)
		: base(facility, errorNo, message, destination)
	{
	}

	public NoDevicesInitializedException(Facility facility, short errorNo, string message, string destination, Exception inner)
		: base(facility, errorNo, message, destination, inner)
	{
	}
}
public class NotSupportedProductException : ConnectionException
{
	public string NotSupportedProductID = string.Empty;

	public NotSupportedProductException(Facility facility, short errorNo)
		: base(facility, errorNo)
	{
	}

	public NotSupportedProductException(Facility facility, short errorNo, string message)
		: base(facility, errorNo, message)
	{
	}

	public NotSupportedProductException(Facility facility, short errorNo, string message, Exception inner)
		: base(facility, errorNo, message, inner)
	{
	}

	public NotSupportedProductException(Facility facility, short errorNo, string message, string destination)
		: base(facility, errorNo, message, destination)
	{
	}

	public NotSupportedProductException(Facility facility, short errorNo, string message, string destination, Exception inner)
		: base(facility, errorNo, message, destination, inner)
	{
	}
}
public class IniFileData
{
	private string fileName;

	private DataSet iniFileDataSet;

	public string FileName => fileName;

	public string XML => iniFileDataSet.GetXml();

	public DataSet IniFileDataSet => iniFileDataSet;

	private void PrepareDataset()
	{
		DataTable dataTable = new DataTable("sections");
		dataTable.Columns.Add("sectionid");
		dataTable.Columns[0].AutoIncrement = true;
		dataTable.Columns.Add("section").Unique = true;
		new UniqueConstraint("section constraint", dataTable.Columns["section"]);
		DataTable dataTable2 = new DataTable("keyvaluepairs");
		dataTable2.Columns.Add("sectionid");
		dataTable2.Columns["sectionid"].DataType = Type.GetType("System.Int32");
		dataTable2.Columns.Add("Key");
		dataTable2.Columns.Add("value");
		new ForeignKeyConstraint("sectionids", dataTable.Columns["sectionid"], dataTable2.Columns["sectionid"]);
		iniFileDataSet = new DataSet("empty");
		iniFileDataSet.Tables.Add(dataTable);
		iniFileDataSet.Tables.Add(dataTable2);
		iniFileDataSet.EnforceConstraints = true;
	}

	public IniFileData(string FileName)
	{
		PrepareDataset();
		ReadIniFile(FileName);
	}

	public IniFileData()
	{
		fileName = null;
		PrepareDataset();
	}

	~IniFileData()
	{
		if (iniFileDataSet == null)
		{
			iniFileDataSet.Dispose();
		}
		iniFileDataSet = null;
	}

	public void ReadIniFile(string PathName)
	{
		fileName = null;
		iniFileDataSet.Clear();
		iniFileDataSet.DataSetName = PathName;
		IniFileReader iniFileReader = new IniFileReader();
		iniFileReader.SectionRead += OnSectionRead;
		iniFileReader.KeyValueRead += OnKeyValueRead;
		iniFileReader.ReadIniFile(PathName);
		fileName = PathName;
	}

	private void OnSectionRead(string Section)
	{
		DataRow dataRow = iniFileDataSet.Tables["sections"].NewRow();
		iniFileDataSet.Tables["sections"].Rows.Add(dataRow);
		dataRow["section"] = Section;
		if (iniFileDataSet.HasErrors)
		{
			iniFileDataSet.RejectChanges();
		}
		else
		{
			iniFileDataSet.AcceptChanges();
		}
	}

	private void OnKeyValueRead(string Section, string Key, string sValue)
	{
		try
		{
			string filterExpression = "section='" + Section + "'";
			DataRow[] array = iniFileDataSet.Tables["sections"].Select(filterExpression);
			DataRow dataRow = iniFileDataSet.Tables["keyvaluepairs"].NewRow();
			dataRow["sectionid"] = array[0]["sectionid"];
			dataRow["key"] = Key;
			dataRow["value"] = sValue;
			iniFileDataSet.Tables["keyvaluepairs"].Rows.Add(dataRow);
			iniFileDataSet.AcceptChanges();
		}
		catch (Exception)
		{
			iniFileDataSet.RejectChanges();
		}
	}

	public string GetValue(string section, string key)
	{
		try
		{
			string filterExpression = "section='" + section + "'";
			int num = (int)iniFileDataSet.Tables["sections"].Select(filterExpression)[0][0];
			filterExpression = "sectionid=" + num + " and key='" + key + "'";
			return (string)iniFileDataSet.Tables["keyvaluepairs"].Select(filterExpression)[0][2];
		}
		catch (Exception)
		{
			return "";
		}
	}
}
public class IniFileReaderException : Exception
{
	public IniFileReaderException(string error)
		: base(error)
	{
	}
}
public class IniFileReader
{
	public delegate void SectionHandler(string sectionName);

	public delegate void KeyValueHandler(string section, string key, string sValue);

	public event SectionHandler SectionRead;

	public event KeyValueHandler KeyValueRead;

	public void ReadIniFile(string filename)
	{
		StreamReader streamReader = new StreamReader(filename);
		string text = null;
		string text2 = null;
		string[] array = null;
		while (streamReader.Peek() != -1)
		{
			text = streamReader.ReadLine();
			text.Trim();
			if (text.Length == 0)
			{
				continue;
			}
			if (text.StartsWith("[") && text.EndsWith("]"))
			{
				text2 = text.Substring(1, text.Length - 2);
				this.SectionRead(text2);
				continue;
			}
			array = text.Split(new char[1] { '=' }, 2);
			if (array.Length == 2)
			{
				this.KeyValueRead(text2, array[0], array[1]);
			}
		}
		streamReader.Close();
		streamReader = null;
	}
}
public interface IModuleNetwork : IDisposable
{
	string DeviceMasterPassword { get; }

	string DeviceInvalidPassword { get; }

	string SelectedConfigFilename { get; set; }

	SortedList ConfigFileList { get; set; }

	string DatalinkConfiguration { get; set; }

	string SessionConfiguration { get; set; }

	string SelectedProductID { get; set; }

	GTISVersion GTISLevel { get; set; }

	DetectionType Detection { get; set; }

	bool Offline { get; }

	SortedList Modules { get; }

	int NumberOfCumminsModules { get; }

	int IndexOfCumminsModule { get; }

	IAddressValue CurrentDeviceAddress { get; set; }

	IAddressValue ParentDeviceAddress { get; set; }

	IProgress Progress { get; set; }

	bool AutoReconnect { get; set; }

	bool QueryRunLocation { get; set; }

	SortedList DeviceInfoList { get; set; }

	ArrayList Warnings { get; }

	bool FeatureSuspendMonitoring { get; set; }

	bool UserSuspendMonitoring { get; set; }

	bool SuspendMonitoring { get; }

	bool SuspendDataMonitoring { get; }

	bool SystemSuspendAllMonitoring { get; set; }

	bool SystemPauseAllMonitoring { get; set; }

	bool ToggleUserSuspendMonitoring { set; }

	ISubscription BroadcastSubscription { get; }

	event DeviceAddressEventHandler ConnectionLost;

	event DeviceAddressEventHandler ConnectionFading;

	event DeviceAddressEventHandler ConnectionEstablished;

	event SuspendMonitoringChangedEventHandler SuspendMonitoringChanged;

	event PauseMonitoringChangedEventHandler PauseMonitoringChanged;

	event EventHandler CalibrationsVerified;

	ICalibrationOnline GetCalibration(IAddressValue sourceAddress);

	ICollection GetSourceAddresses();

	void Detect();

	void Connect();

	void Connect(SortedList devices);

	IDeviceInformation Connect(IAddressValue deviceAddress);

	ICalibrationECM CreateCalibration(IDeviceInformation deviceInfo, bool createNew = false);

	void Disconnect();

	string ConnectionDetails();

	bool SystemSuspendMonitoring();

	void SystemSuspendMonitoring(bool suspend);

	bool SystemSuspendMonitoring(IAddressValue deviceAddress);

	void SystemSuspendMonitoring(IAddressValue deviceAddress, bool suspend);

	bool HasBroadcast();

	void CloseBroadcastSubscription();

	void ReopenBroadcastSubscription();
}
public class ModuleNetwork : IModuleNetwork, IDisposable
{
	private const string ProtocolJ1939 = "J1939";

	private const int ModuleDetectOriginatorId = 20;

	private const string Type = "Type";

	public const string ResourceFilename = "Cummins.Module.ModuleStrings";

	private const string EventCategoryName = "Connection";

	private const string deviceMasterPassword = "ABCDEF";

	private ISubscription _broadcastSubscription;

	private ICIModuleDetection moduleDetect;

	private SortedList devices;

	private string datalinkConfiguration = string.Empty;

	private string sessionConfiguration;

	private string detectConfiguration;

	private GTISVersion gtisLevel;

	private string parentConfigFilename;

	private SortedList _configFileList;

	private DetectionType detection;

	private bool queryRunLocation = true;

	private Cummins.Messages.MsgManager messageManager;

	private bool disposed;

	private Thread detectThread;

	private IProgress progressMessages;

	private ResourceManager resources;

	private bool offline;

	private RangeLimit outOfRangeLimit;

	private bool autoReconnect;

	private IAddressValue parentDeviceAddress;

	private IAddressValue currentDeviceAddress;

	private SortedList deviceInfoList;

	private SortedList moduleState;

	private bool userSuspendMonitoring;

	private bool systemSuspendAllMonitoring;

	private bool featureSuspendMonitoring;

	private bool systemPauseAllMonitoring;

	private int numberOfCalibrationToVerify;

	private ICalibrationFactory calibrationFactory;

	private string selectedProduct = string.Empty;

	private Stack messageStack = new Stack();

	private ArrayList warnings = new ArrayList();

	private int detectedByMDC;

	private string _cbfName = string.Empty;

	private string _dlaPrefix = string.Empty;

	private string _dlaChannelID = string.Empty;

	private string _toolAddress = string.Empty;

	internal static string DetectionXML = "Cummins.Module.DetectConfiguration.xml";

	private readonly IAppConfigService _appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));

	public SortedList ConfigFileList
	{
		get
		{
			if (_configFileList == null)
			{
				_configFileList = new SortedList();
			}
			return _configFileList;
		}
		set
		{
			_configFileList = value;
		}
	}

	public IAddressValue CurrentDeviceAddress
	{
		get
		{
			return currentDeviceAddress;
		}
		set
		{
			currentDeviceAddress = value;
		}
	}

	public IAddressValue ParentDeviceAddress
	{
		get
		{
			return parentDeviceAddress;
		}
		set
		{
			parentDeviceAddress = value;
		}
	}

	public bool QueryRunLocation
	{
		get
		{
			return queryRunLocation;
		}
		set
		{
			if (queryRunLocation == value)
			{
				return;
			}
			queryRunLocation = value;
			foreach (ICalibrationOnline value2 in Modules.Values)
			{
				try
				{
					value2.QueryRunLocation = queryRunLocation;
				}
				catch (BlockedQueryRunLocationException ex)
				{
					EventLogger.Error("Connection", ex.Message);
				}
			}
		}
	}

	public string SelectedConfigFilename
	{
		get
		{
			return parentConfigFilename;
		}
		set
		{
			parentConfigFilename = value;
		}
	}

	public string DatalinkConfiguration
	{
		get
		{
			return AppSettingHelper.Service.DeviceSettingsXMLString();
		}
		set
		{
			datalinkConfiguration = value;
		}
	}

	public string SessionConfiguration
	{
		get
		{
			return sessionConfiguration;
		}
		set
		{
			sessionConfiguration = value;
		}
	}

	private string DetectConfiguration
	{
		get
		{
			if (detectConfiguration == null || detectConfiguration.Length == 0)
			{
				detectConfiguration = ReadDetectConfiguration();
			}
			return detectConfiguration;
		}
	}

	public ICalibrationFactory CalibrationCreator
	{
		get
		{
			if (calibrationFactory == null)
			{
				calibrationFactory = new CalibrationFactory();
				calibrationFactory.CalibrationCreated += OnCalibrationCreated;
			}
			return calibrationFactory;
		}
	}

	public GTISVersion GTISLevel
	{
		get
		{
			return gtisLevel;
		}
		set
		{
			gtisLevel = value;
		}
	}

	public string SelectedProductID
	{
		get
		{
			return selectedProduct;
		}
		set
		{
			selectedProduct = value;
		}
	}

	public DetectionType Detection
	{
		get
		{
			return detection;
		}
		set
		{
			detection = value;
		}
	}

	public SortedList Modules
	{
		get
		{
			if (devices == null)
			{
				devices = new SortedList();
			}
			return devices;
		}
	}

	public int NumberOfCumminsModules
	{
		get
		{
			int num = 0;
			foreach (ICalibration value in Modules.Values)
			{
				if (value is ICalibrationECM)
				{
					num++;
				}
				else if (!(value is IPublicDataSource))
				{
					num++;
				}
			}
			return num;
		}
	}

	public int IndexOfCumminsModule
	{
		get
		{
			int num = 0;
			foreach (ICalibration value in Modules.Values)
			{
				if (value is ICalibrationECM)
				{
					return num;
				}
				num++;
			}
			return 0;
		}
	}

	public SortedList DeviceInfoList
	{
		get
		{
			if (deviceInfoList == null)
			{
				deviceInfoList = new SortedList();
			}
			return deviceInfoList;
		}
		set
		{
			deviceInfoList = value;
		}
	}

	private Thread DetectThread
	{
		get
		{
			return detectThread;
		}
		set
		{
			detectThread = value;
		}
	}

	public IProgress Progress
	{
		get
		{
			return progressMessages;
		}
		set
		{
			progressMessages = value;
		}
	}

	public string DeviceMasterPassword => "ABCDEF";

	public string DeviceInvalidPassword
	{
		get
		{
			Random random = new Random();
			byte[] array = new byte[6];
			for (int i = 0; i < 6; i++)
			{
				array[i] = (byte)random.Next(32, 126);
			}
			return Encoding.Default.GetString(array);
		}
	}

	public bool Offline => offline;

	public RangeLimit OutOfRangeLimit
	{
		get
		{
			return outOfRangeLimit;
		}
		set
		{
			outOfRangeLimit = value;
		}
	}

	public bool AutoReconnect
	{
		get
		{
			return autoReconnect;
		}
		set
		{
			autoReconnect = value;
			foreach (ICalibrationOnline value2 in Modules.Values)
			{
				if (value2 != null)
				{
					value2.AutoReconnect = value;
				}
			}
		}
	}

	public bool SuspendMonitoring
	{
		get
		{
			if (!UserSuspendMonitoring && !SystemSuspendMonitoring())
			{
				return FeatureSuspendMonitoring;
			}
			return true;
		}
	}

	public bool SuspendDataMonitoring
	{
		get
		{
			if (!UserSuspendMonitoring)
			{
				return SystemSuspendMonitoring();
			}
			return true;
		}
	}

	public bool ToggleUserSuspendMonitoring
	{
		set
		{
			userSuspendMonitoring = value;
			foreach (ICalibrationOnline value2 in Modules.Values)
			{
				if (value2 != null)
				{
					value2.UserSuspendMonitoring = value;
				}
			}
			RaiseSuspendMonitoringChanged(null, allDevices: true, value, suspendDataMonitoring: true);
		}
	}

	public bool UserSuspendMonitoring
	{
		get
		{
			return userSuspendMonitoring;
		}
		set
		{
			if (value == userSuspendMonitoring)
			{
				return;
			}
			userSuspendMonitoring = value;
			foreach (ICalibrationOnline value2 in Modules.Values)
			{
				if (value2 != null)
				{
					value2.UserSuspendMonitoring = value;
				}
			}
			RaiseSuspendMonitoringChanged(null, allDevices: true, value, suspendDataMonitoring: true);
		}
	}

	public bool SystemPauseAllMonitoring
	{
		get
		{
			return systemPauseAllMonitoring;
		}
		set
		{
			if (systemPauseAllMonitoring != value)
			{
				systemPauseAllMonitoring = value;
				RaisePauseAllMonitoringEventChanged();
			}
		}
	}

	public bool SystemSuspendAllMonitoring
	{
		get
		{
			return systemSuspendAllMonitoring;
		}
		set
		{
			if (systemSuspendAllMonitoring == value)
			{
				return;
			}
			systemSuspendAllMonitoring = value;
			foreach (IAddressValue key in Modules.Keys)
			{
				SystemSuspendMonitoringQuietly(key, value);
			}
			RaiseSuspendMonitoringChanged(new AddressValue(byte.MaxValue), allDevices: true, value, suspendDataMonitoring: true);
		}
	}

	public bool FeatureSuspendMonitoring
	{
		get
		{
			return featureSuspendMonitoring;
		}
		set
		{
			if (value == featureSuspendMonitoring)
			{
				return;
			}
			featureSuspendMonitoring = value;
			foreach (ICalibrationOnline value2 in Modules.Values)
			{
				if (value2 != null)
				{
					value2.FeatureSuspendMonitoring = value;
				}
			}
			RaiseSuspendMonitoringChanged(new AddressValue(byte.MaxValue), allDevices: true, value, suspendDataMonitoring: false);
		}
	}

	public ArrayList Warnings => warnings;

	public ISubscription BroadcastSubscription
	{
		get
		{
			if (_broadcastSubscription == null && IsJ1939(DatalinkConfiguration) && IsUsingRp1210Dla())
			{
				_broadcastSubscription = new J1939_71BroadcastSubscription(_dlaPrefix, _dlaChannelID, _toolAddress, _cbfName);
				PCLSubscriptionBase pCLSubscriptionBase = _broadcastSubscription as PCLSubscriptionBase;
				ConnectionLost += pCLSubscriptionBase.DataLink_Dead;
				ConnectionEstablished += pCLSubscriptionBase.DataLink_Alive;
			}
			return _broadcastSubscription;
		}
	}

	private SortedList ModuleState
	{
		get
		{
			if (moduleState == null)
			{
				moduleState = new SortedList();
			}
			return moduleState;
		}
	}

	private ICIModuleDetection ModuleDetect
	{
		get
		{
			if (moduleDetect == null)
			{
				moduleDetect = new CIModuleDetectionClass();
			}
			return moduleDetect;
		}
	}

	private string Protocol => AppSettingHelper.GetSetting(ApplicationSettings.Protocol);

	public event DeviceAddressEventHandler ConnectionLost;

	public event DeviceAddressEventHandler ConnectionFading;

	public event DeviceAddressEventHandler ConnectionEstablished;

	public event SuspendMonitoringChangedEventHandler SuspendMonitoringChanged;

	public event PauseMonitoringChangedEventHandler PauseMonitoringChanged;

	public event EventHandler CalibrationsVerified;

	public ModuleNetwork()
	{
		DatalinkConfiguration = string.Empty;
		SessionConfiguration = string.Empty;
		GTISLevel = GTISVersion.GTIS45;
		SelectedConfigFilename = string.Empty;
		_configFileList = null;
		parentDeviceAddress = null;
		Initialize();
	}

	public ModuleNetwork(string dclConfiguration, string sessionConfiguration, string selectedConfigFilename, GTISVersion gtisLevel)
	{
		DatalinkConfiguration = dclConfiguration;
		SessionConfiguration = sessionConfiguration;
		GTISLevel = gtisLevel;
		SelectedConfigFilename = parentConfigFilename;
		parentDeviceAddress = null;
		Initialize();
	}

	protected virtual void Dispose(bool disposing)
	{
		if (!disposed && disposing)
		{
			CleanupResources();
		}
		disposed = true;
	}

	public void Dispose()
	{
		Dispose(disposing: true);
		GC.SuppressFinalize(this);
	}

	private void CleanupResources()
	{
		lock (this)
		{
			TeardownMessageManager();
			numberOfCalibrationToVerify = 0;
			foreach (IAddressValue key in Modules.Keys)
			{
				try
				{
					ICalibrationOnline calibrationOnline = (ICalibrationOnline)Modules[key];
					if (calibrationOnline != null)
					{
						calibrationOnline.DatalinkDisconnect();
						calibrationOnline.DatalinkClose();
						DetachConnectionEvent(calibrationOnline);
						calibrationOnline.Dispose();
						calibrationOnline = null;
					}
				}
				catch
				{
				}
			}
			_broadcastSubscription = null;
		}
	}

	private void TeardownMessageManager()
	{
		if (messageManager != null)
		{
			try
			{
				Cummins.Messages.MsgManager msgManager = messageManager;
				msgManager.ReceiveMessageEvent = (ReceiveMessageEventHandler)Delegate.Remove(msgManager.ReceiveMessageEvent, new ReceiveMessageEventHandler(OnReceiveMessage));
				Cummins.Messages.MsgManager msgManager2 = messageManager;
				msgManager2.AssignFiltersEvent = (AssignFiltersEventHandler)Delegate.Remove(msgManager2.AssignFiltersEvent, new AssignFiltersEventHandler(OnAssignFilters));
				messageManager.Dispose();
				messageManager = null;
			}
			catch
			{
			}
		}
	}

	public void Disconnect()
	{
		CleanupResources();
		ClearCollections();
		offline = true;
	}

	private void ClearCollections()
	{
		if (devices != null)
		{
			devices.Clear();
			devices = null;
		}
		if (DeviceInfoList != null)
		{
			foreach (object key in DeviceInfoList.Keys)
			{
				IDeviceInformation deviceInformation = (IDeviceInformation)DeviceInfoList[key];
				if (deviceInformation.Device != null)
				{
					deviceInformation.Device.Close();
					Marshal.FinalReleaseComObject(deviceInformation.Device);
					deviceInformation.Device = null;
				}
			}
			DeviceInfoList.Clear();
			DeviceInfoList = null;
		}
		if (moduleState != null)
		{
			moduleState.Clear();
			moduleState = null;
		}
	}

	public void Detect()
	{
		StartDetection();
	}

	private void StartDetection()
	{
		offline = true;
		parentDeviceAddress = null;
		ICICollection iCICollection = null;
		bool isJ = false;
		detectedByMDC = 0;
		warnings.Clear();
		try
		{
			lock (this)
			{
				InitializeMessageManager();
				if (Progress != null)
				{
					Progress.AllowCancel = false;
				}
				LicensedComWrapper licensedComWrapper = new LicensedComWrapper(ComClassID.DCLDevice);
				ICIDCLDevice pDataSource = (ICIDCLDevice)licensedComWrapper.GetComInstance();
				isJ = IsJ1939(DatalinkConfiguration);
				iCICollection = ModuleDetect.Detect(pDataSource, DatalinkConfiguration, DetectConfiguration, SessionConfiguration);
				if (iCICollection == null)
				{
					TeardownMessageManager();
					throw new NoDevicesDetectedException(Facility.Connection, 0);
				}
				detectedByMDC = iCICollection.Count;
			}
		}
		catch (COMException ex)
		{
			TeardownMessageManager();
			string text = string.Empty;
			if (GetErrorCode(ex) == 0)
			{
				text = AppSettingHelper.GetSetting(ApplicationSettings.Adapter);
			}
			EventLogger.Error(ErrorSources.Connection, GetErrorCode(ex), ex, text);
			throw new NoDevicesDetectedException(Facility.Connection, 0, GetError(ex), ex);
		}
		finally
		{
			if (moduleDetect != null)
			{
				try
				{
					Marshal.FinalReleaseComObject(moduleDetect);
					moduleDetect = null;
				}
				catch (ArgumentException)
				{
				}
			}
		}
		CacheDeviceInformation(iCICollection, isJ);
		ResolveDeviceConfigFile();
	}

	private void ResolveDeviceConfigFile()
	{
		if (ConfigFileList.Count <= 0)
		{
			return;
		}
		if (ConfigFileList.Count > 1)
		{
			foreach (IDeviceInformation value in DeviceInfoList.Values)
			{
				value.ConfigFile = "";
				foreach (string key in ConfigFileList.Keys)
				{
					if (value.ProductId.Contains(key))
					{
						value.ConfigFile = ConfigFileList[key].ToString();
						break;
					}
				}
			}
			return;
		}
		foreach (IDeviceInformation value2 in DeviceInfoList.Values)
		{
			value2.ConfigFile = ConfigFileList.GetByIndex(0).ToString();
		}
	}

	private bool IsJ1939(string datalinkConfiguration)
	{
		return datalinkConfiguration.Contains("<protocol><J1939>");
	}

	private bool IsUsingRp1210Dla()
	{
		return string.Equals(AdapterType.RP1210a.ToString(), _appConfigService.GetAppSetting(ApplicationSettings.Adapter));
	}

	public void Cancel()
	{
		if (DetectThread != null && DetectThread.ThreadState != System.Threading.ThreadState.Running)
		{
		}
	}

	public ICalibrationOnline GetCalibration(IAddressValue sourceAddress)
	{
		ICalibrationOnline calibrationOnline = null;
		lock (this)
		{
			if (Modules.Contains(sourceAddress))
			{
				if (Modules[sourceAddress] != null)
				{
					calibrationOnline = (ICalibrationOnline)Modules[sourceAddress];
				}
				else
				{
					calibrationOnline = CreateCalibration(sourceAddress);
					Modules[sourceAddress] = calibrationOnline;
				}
			}
			else
			{
				calibrationOnline = CreateOfflineCalibration(sourceAddress);
				Modules.Add(sourceAddress, calibrationOnline);
			}
		}
		return calibrationOnline;
	}

	public ICollection GetSourceAddresses()
	{
		return Modules.Keys;
	}

	private void Initialize()
	{
		Detection = DetectionType.All;
		OutOfRangeLimit = RangeLimitProvider.CurrentRangeLimit;
		AutoReconnect = false;
		UserSuspendMonitoring = false;
		SystemSuspendAllMonitoring = true;
		offline = true;
		resources = new ResourceManager("Cummins.Module.ModuleStrings", Assembly.GetExecutingAssembly());
	}

	private void InitializeMessageManager()
	{
		messageManager = new Cummins.Messages.MsgManager();
		Cummins.Messages.MsgManager msgManager = messageManager;
		msgManager.ReceiveMessageEvent = (ReceiveMessageEventHandler)Delegate.Combine(msgManager.ReceiveMessageEvent, new ReceiveMessageEventHandler(OnReceiveMessage));
		Cummins.Messages.MsgManager msgManager2 = messageManager;
		msgManager2.AssignFiltersEvent = (AssignFiltersEventHandler)Delegate.Combine(msgManager2.AssignFiltersEvent, new AssignFiltersEventHandler(OnAssignFilters));
	}

	private ICalibrationOnline CreateCalibration(IAddressValue sourceAddress)
	{
		ICalibrationOnline calibrationOnline = null;
		IDeviceInformation deviceInformation = (IDeviceInformation)DeviceInfoList[sourceAddress];
		_ = deviceInformation.DeviceSettings;
		_ = deviceInformation.Device;
		_ = deviceInformation.EcmID;
		GTISVersion gtisVersion = gtisLevel;
		if (ModuleState.Contains(sourceAddress))
		{
			deviceInformation.DeviceState = (Cummins.Calibration.ConnectionState)ModuleState[sourceAddress];
		}
		calibrationOnline = CalibrationCreator.Create(deviceInformation, gtisVersion, Progress, OutOfRangeLimit);
		if (calibrationOnline != null)
		{
			AttachConnectionEvent(calibrationOnline);
			calibrationOnline.AutoReconnect = AutoReconnect;
			try
			{
				calibrationOnline.QueryRunLocation = queryRunLocation;
			}
			catch (BlockedQueryRunLocationException ex)
			{
				EventLogger.Error("Connection", ex.Message);
			}
			calibrationOnline.UserSuspendMonitoring = UserSuspendMonitoring;
		}
		return calibrationOnline;
	}

	private ICalibrationOnline CreateOfflineCalibration(IAddressValue sourceAddress)
	{
		ICalibrationOnline calibrationOnline = null;
		calibrationOnline = ((sourceAddress.Type != AddressType.ASAM) ? CalibrationCreator.Create(SelectedConfigFilename, GTISLevel) : CalibrationCreator.Create(new ASAMConfigData(SelectedConfigFilename), sourceAddress, offline: true));
		if (calibrationOnline != null)
		{
			calibrationOnline.SystemSuspendMonitoring = true;
		}
		return calibrationOnline;
	}

	private void CacheDeviceInformation(ICICollection activeDevices, bool isJ1939)
	{
		for (int i = 0; i < detectedByMDC; i++)
		{
			ICIDeviceInfo iCIDeviceInfo = (ICIDeviceInfo)activeDevices[i];
			byte address = byte.MaxValue;
			IAddressValue addressValue = null;
			try
			{
				IDeviceInformation deviceInformation = new DeviceInformation();
				address = (byte)iCIDeviceInfo.Address;
				addressValue = AddressFactory.ProductAddressValue(address.ToString("X2"));
				deviceInformation.Address = address;
				deviceInformation.Device = (ICIDCLDevice)iCIDeviceInfo.DataSource;
				if (!DeviceInfoList.ContainsKey(addressValue))
				{
					DeviceInfoList.Add(addressValue, deviceInformation);
				}
				else
				{
					DeviceInfoList[addressValue] = deviceInformation;
				}
				if (!Modules.Contains(addressValue))
				{
					Modules.Add(addressValue, null);
				}
				else
				{
					Modules[addressValue] = null;
				}
				deviceInformation.DeviceSettings = iCIDeviceInfo.DeviceOpenConfiguration;
				ReadECMID(iCIDeviceInfo, deviceInformation);
				ReadRunLocation(iCIDeviceInfo, deviceInformation);
				ReadProductIdentifier(iCIDeviceInfo, deviceInformation);
				ReadPhase(iCIDeviceInfo, deviceInformation);
				deviceInformation.Password = DeviceInvalidPassword;
				deviceInformation.Device.Password = deviceInformation.Password;
				ReadPartNumber(iCIDeviceInfo, deviceInformation);
				ReadSerialNumber(iCIDeviceInfo, deviceInformation);
			}
			catch (Exception ex)
			{
				if (isJ1939)
				{
					if (addressValue == null || Modules.Contains(addressValue))
					{
						continue;
					}
					if (IsUsingRp1210Dla())
					{
						string cBFFileName = _appConfigService.CBFFileName;
						_dlaPrefix = _appConfigService.GetAppSetting(ApplicationSettings.RP1210DllName);
						_dlaChannelID = _appConfigService.GetAppSetting(ApplicationSettings.RP1210DeviceID);
						_toolAddress = _appConfigService.GetAppSetting(ApplicationSettings.J1939ToolAddr);
						try
						{
							GetDeviceConfig(iCIDeviceInfo);
							ICalibrationOnline calibrationOnline = CalibrationCreator.Create(cBFFileName, addressValue);
							Modules.Add(calibrationOnline.SourceAddress, calibrationOnline);
							EventLogger.Info("Connection", "Device at " + address.ToString("X2") + " added as a J1939 device");
						}
						catch
						{
							EventLogger.Warn("Connection", "Device at " + address.ToString("X2") + " ignored as it did not provide enough information", ex.Message);
						}
					}
					else
					{
						EventLogger.Warn("J1939 Broadcast Connection", "J1939 Broadcast will only work with an RP1210 compliant adapter", "If you want this feature you will need to select an RP1210 compliant datalink when opening a connection to the module");
					}
					continue;
				}
				EventLogger.Warn("Connection", "Device at " + address.ToString("X2") + " ignored as it did not provide enough information", ex.Message);
			}
		}
		if (IsJ1939(DatalinkConfiguration))
		{
			if (IsUsingRp1210Dla())
			{
				if (string.IsNullOrEmpty(_appConfigService.CBFFileName) || !File.Exists(_appConfigService.CBFFileName))
				{
					_appConfigService.CBFFileName = SessionService.CurrentSession.DataPath + "\\" + _appConfigService.GetAppSetting(ApplicationSettings.DefaultCBFFile);
				}
				_cbfName = _appConfigService.CBFFileName;
				_dlaPrefix = _appConfigService.GetAppSetting(ApplicationSettings.RP1210DllName);
				_dlaChannelID = _appConfigService.GetAppSetting(ApplicationSettings.RP1210DeviceID);
				_toolAddress = _appConfigService.GetAppSetting(ApplicationSettings.J1939ToolAddr);
				try
				{
					IAddressValue addressValue2 = null;
					addressValue2 = AddressFactory.ProductAddressValue("FF");
					ICalibrationOnline calibrationOnline2 = CalibrationCreator.Create(_cbfName, addressValue2);
					Modules.Add(calibrationOnline2.SourceAddress, calibrationOnline2);
				}
				catch (Exception e)
				{
					EventLogger.Error("Connection", "Could not open connection to broadcast data", e);
				}
			}
			else
			{
				EventLogger.Warn("J1939 Broadcast Connection", "J1939 Broadcast will only work with an RP1210 compliant adapter", "If you want this feature you will need to select an RP1210 compliant datalink when opening a connection to the module");
			}
		}
		if (DeviceInfoList.Count != activeDevices.Count && DeviceInfoList.Count != 0)
		{
			string message = string.Format(resources.GetString("UnableToConnectToAll"), activeDevices.Count, Modules.Count);
			EventLogger.Warn("Connection", message, ConnectionDetails());
		}
		else if (DeviceInfoList.Count == 0)
		{
			NoDevicesConnectedException ex2 = new NoDevicesConnectedException(Facility.Connection, 0);
			ex2.DetectedDevicesCount = activeDevices.Count;
			throw ex2;
		}
		ISecurityService securityService = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
		foreach (IDeviceInformation value in DeviceInfoList.Values)
		{
			if (value.RunLocation != RunLocationType.RomBoot && !securityService.IsProductSupported(value.ProductId))
			{
				string message2 = "The Product ID detected is not from the supported list of products. Detected Product ID = " + value.ProductId;
				NotSupportedProductException ex3 = new NotSupportedProductException(Facility.Connection, 5, message2);
				ex3.NotSupportedProductID = value.ProductId;
				throw ex3;
			}
		}
	}

	private string GetDeviceConfig(ICIDeviceInfo activeDevice)
	{
		string text;
		try
		{
			text = activeDevice.DeviceOpenConfiguration;
		}
		catch
		{
			string value = activeDevice.Address.ToString("X2");
			string text2 = "<destinationAddress>";
			string value2 = "</destinationAddress>";
			text = DatalinkConfiguration;
			int num = text.IndexOf(text2);
			int num2 = text.IndexOf(value2);
			if (num > -1 && num2 > -1)
			{
				num += text2.Length;
				int count = num2 - num;
				text = text.Remove(num, count);
				text = text.Insert(num, value);
			}
		}
		return text;
	}

	public void Connect()
	{
		try
		{
			int num = 0;
			numberOfCalibrationToVerify = DeviceInfoList.Count;
			for (int i = 0; i < DeviceInfoList.Count; i++)
			{
				IAddressValue addressValue = (IAddressValue)DeviceInfoList.GetKey(i);
				IDeviceInformation deviceInformation = (IDeviceInformation)DeviceInfoList[addressValue];
				Progress.SetProgress(string.Concat("Connecting to ", addressValue, "  Part#:", deviceInformation.PartNumber, " Serial#:", deviceInformation.SerialNumber));
				try
				{
					_ = (ICalibrationECM)GetCalibration(addressValue);
					num++;
				}
				catch (CRCException ex)
				{
					HandleConnectException(ex, deviceInformation, string.Format(resources.GetString("InvalidCRC"), addressValue.ToString(), ex.FileName));
				}
				catch (UnableToReadFileException ex2)
				{
					HandleConnectException(ex2, deviceInformation, string.Format(resources.GetString("UnableToReadConfigFile"), addressValue.ToString()));
				}
				catch (GTISLevelMismatchException ex3)
				{
					HandleConnectException(ex3, deviceInformation, string.Format(resources.GetString("GTISLevelMismatch"), ex3.ExpectedVersion, ex3.ActualVersion));
				}
				catch (ConfigFileGTISLevelMismatchException ex4)
				{
					HandleConnectException(ex4, deviceInformation, string.Format(resources.GetString("ConfigFileGTISLevelMismatch"), ex4.ExpectedVersion, ex4.ActualVersion));
				}
				catch (ECMIDMismatchException ex5)
				{
					HandleConnectException(ex5, deviceInformation, string.Format(resources.GetString("NotGTIS45"), selectedProduct, deviceInformation.EcmID, deviceInformation.ProductId));
				}
				catch (NotRunningGTIS45Exception ex6)
				{
					HandleConnectException(ex6, deviceInformation, string.Format(resources.GetString("NotRunningGTIS45Exception")));
				}
				catch (Exception ex7)
				{
					HandleConnectException(ex7, deviceInformation, string.Format(resources.GetString("UnabletoConnect"), addressValue.ToString()));
				}
			}
			offline = Modules.Count == 0;
			if (num == 0)
			{
				throw new NoDevicesInitializedException(Facility.Connection, 4);
			}
			if (num < DeviceInfoList.Count)
			{
				string message = string.Format(resources.GetString("UnableToInitializeAll"), detectedByMDC, DeviceInfoList.Count, num);
				EventLogger.Warn("Connection", message, ConnectionDetails());
			}
		}
		finally
		{
			if (DeviceInfoList != null)
			{
				DeviceInfoList.Clear();
				DeviceInfoList = null;
			}
			TeardownMessageManager();
		}
	}

	private string ChangeTagValue(string context, string tag, string newValue)
	{
		if (context == null || tag == null || newValue == null || context.Length == 0 || tag.Length == 0)
		{
			throw new ArgumentNullException();
		}
		string text = "<" + tag + ">";
		string value = "</" + tag + ">";
		string text2 = context;
		int num = context.IndexOf(text);
		int num2 = context.IndexOf(value);
		if (num >= 0 && num2 >= 0)
		{
			int num3 = num + text.Length;
			int count = num2 - num3;
			text2 = context.Remove(num3, count);
			return text2.Insert(num3, newValue);
		}
		throw new ArgumentException();
	}

	public void Connect(SortedList devices)
	{
		if (devices == null)
		{
			throw new ArgumentNullException("devices");
		}
		ICalibrationOnline calibrationOnline = null;
		if (Progress != null)
		{
			Progress.AllowCancel = false;
		}
		ServiceManager.Services.GetService(typeof(IDatalinkSessionService));
		IAddressValue addressValue = null;
		warnings.Clear();
		numberOfCalibrationToVerify = devices.Count;
		for (int i = 0; i < devices.Count; i++)
		{
			try
			{
				IDeviceInformation deviceInformation = new DeviceInformation();
				string fileName = (deviceInformation.ConfigFile = (string)devices.GetByIndex(i));
				addressValue = (IAddressValue)devices.GetKey(i);
				Progress.SetProgress(devices.Count, i + 1, "Connecting to " + addressValue.ToString());
				if (addressValue.Type == AddressType.ECM)
				{
					deviceInformation.DeviceSettings = ChangeTagValue(DatalinkConfiguration, "destinationAddress", addressValue.Value);
					deviceInformation.DeviceState = Cummins.Calibration.ConnectionState.Uninitialized;
					deviceInformation.Address = addressValue.DeviceAddress;
					LicensedComWrapper licensedComWrapper = new LicensedComWrapper(ComClassID.DCLDevice);
					deviceInformation.Device = (ICIDCLDevice)licensedComWrapper.GetComInstance();
					ICPPDataLink iCPPDataLink = new PreGTIS45DataLink(deviceInformation);
					iCPPDataLink.Open();
					deviceInformation.DeviceState = Cummins.Calibration.ConnectionState.Open;
					try
					{
						deviceInformation.EcmID = iCPPDataLink.ECMID;
						if (deviceInformation.EcmID == "XX")
						{
							iCPPDataLink = new GTIS45DataLink(deviceInformation);
							iCPPDataLink.State = Cummins.Calibration.ConnectionState.Open;
							try
							{
								iCPPDataLink.Connect();
								deviceInformation.DeviceState = Cummins.Calibration.ConnectionState.Connected;
							}
							catch (Exception ex)
							{
								string text2 = string.Format(resources.GetString("UnableToCLIP"), deviceInformation.Address.ToString("X2"));
								EventLogger.Error("Connection", text2, ex);
								Trace.WriteLine(ex.Message + Environment.NewLine + ex.StackTrace, "ModuleNetwork.Connect(devices)");
								messageStack.Push(text2);
							}
						}
						ICICollection iCICollection = ModuleDetect.Detect(deviceInformation.Device, null, null, SessionConfiguration);
						if (iCICollection != null && iCICollection[0] != null)
						{
							ICIDeviceInfo iCIDeviceInfo = (ICIDeviceInfo)iCICollection[0];
							ReadRunLocation(iCIDeviceInfo, deviceInformation);
							ReadProductIdentifier(iCIDeviceInfo, deviceInformation);
							ReadPhase(iCIDeviceInfo, deviceInformation);
							ReadPartNumber(iCIDeviceInfo, deviceInformation);
							ReadSerialNumber(iCIDeviceInfo, deviceInformation);
							deviceInformation.Password = DeviceInvalidPassword;
							deviceInformation.Device.Password = deviceInformation.Password;
							deviceInformation.DeviceSettings = iCIDeviceInfo.DeviceOpenConfiguration;
						}
					}
					catch (DataLinkException)
					{
						iCPPDataLink = null;
					}
					calibrationOnline = CalibrationCreator.Create(iCPPDataLink, deviceInformation, gtisLevel, Progress, OutOfRangeLimit);
				}
				else
				{
					calibrationOnline = CalibrationCreator.Create(new ASAMConfigData(fileName), addressValue, offline: false);
				}
				Modules.Add(addressValue, calibrationOnline);
				if (calibrationOnline != null)
				{
					AttachConnectionEvent(calibrationOnline);
					calibrationOnline.AutoReconnect = AutoReconnect;
					calibrationOnline.UserSuspendMonitoring = UserSuspendMonitoring;
				}
			}
			catch (InvalidASAMConfigurationFileException ex3)
			{
				numberOfCalibrationToVerify--;
				EventLogger.Error(ErrorSources.Connection, 9, ex3.Message, ex3.ConfigurationFileName);
			}
			catch (TCPIPCreateDataLinkException ex4)
			{
				numberOfCalibrationToVerify--;
				EventLogger.Error(ErrorSources.Connection, 7, ex4.Message, ex4.TCPIPAddress);
			}
			catch (TCPIPConnectDataLinkException ex5)
			{
				numberOfCalibrationToVerify--;
				EventLogger.Error(ErrorSources.Connection, 8, ex5.Message, ex5.TCPIPAddress);
			}
			catch (Exception ex6)
			{
				numberOfCalibrationToVerify--;
				string text3 = "Failed to connect to module at address " + addressValue.ToString() + ".";
				Trace.WriteLine(ex6.ToString(), "ModuleNetwork:Connect");
				Progress.SetProgress(devices.Count, i, text3);
				EventLogger.Error("Connection", text3, ex6);
				messageStack.Push(text3 + ". Please see Event log for further details");
			}
		}
		offline = Modules.Count == 0;
		if (Modules.Count == 0)
		{
			throw new NoDevicesAvailableException(Facility.Connection, 1);
		}
		if (Modules.Count != devices.Count)
		{
			string message = string.Format(resources.GetString("UnableToConnectToAll"), devices.Count, Modules.Count);
			EventLogger.Warn("Connection", message, ConnectionDetails());
		}
		if (!IsJ1939(DatalinkConfiguration))
		{
			return;
		}
		if (IsUsingRp1210Dla())
		{
			if (string.IsNullOrEmpty(_appConfigService.CBFFileName) || !File.Exists(_appConfigService.CBFFileName))
			{
				_appConfigService.CBFFileName = SessionService.CurrentSession.DataPath + "\\" + _appConfigService.GetAppSetting(ApplicationSettings.DefaultCBFFile);
			}
			_cbfName = _appConfigService.CBFFileName;
			_dlaPrefix = _appConfigService.GetAppSetting(ApplicationSettings.RP1210DllName);
			_dlaChannelID = _appConfigService.GetAppSetting(ApplicationSettings.RP1210DeviceID);
			_toolAddress = _appConfigService.GetAppSetting(ApplicationSettings.J1939ToolAddr);
			try
			{
				IAddressValue addressValue2 = null;
				addressValue2 = AddressFactory.ProductAddressValue("FF");
				ICalibrationOnline calibrationOnline2 = CalibrationCreator.Create(_cbfName, addressValue2);
				Modules.Add(calibrationOnline2.SourceAddress, calibrationOnline2);
				return;
			}
			catch (Exception e)
			{
				EventLogger.Error("Connection", "Could not open connection to broadcast data", e);
				return;
			}
		}
		EventLogger.Warn("J1939 Broadcast Connection", "J1939 Broadcast will only work with an RP1210 compliant adapter", "If you want this feature you will need to select an RP1210 compliant datalink when opening a connection to the module");
	}

	public IDeviceInformation Connect(IAddressValue deviceAddress)
	{
		if (deviceAddress == null)
		{
			throw new ArgumentNullException("DeviceAddress");
		}
		warnings.Clear();
		IDeviceInformation deviceInformation = null;
		try
		{
			if (!DeviceInfoList.Contains(deviceAddress))
			{
				if (!Modules.Contains(deviceAddress))
				{
					deviceInformation = new DeviceInformation();
					deviceInformation.DeviceSettings = ChangeTagValue(DatalinkConfiguration, "destinationAddress", deviceAddress.Value);
					deviceInformation.DeviceState = Cummins.Calibration.ConnectionState.Uninitialized;
					deviceInformation.Address = deviceAddress.DeviceAddress;
					LicensedComWrapper licensedComWrapper = new LicensedComWrapper(ComClassID.DCLDevice);
					deviceInformation.Device = (ICIDCLDevice)licensedComWrapper.GetComInstance();
					deviceInformation.DeviceSettings = ChangeTagValue(DatalinkConfiguration, "destinationAddress", deviceAddress.Value);
					ICPPDataLink iCPPDataLink = new PreGTIS45DataLink(deviceInformation);
					iCPPDataLink.Open();
					deviceInformation.DeviceState = Cummins.Calibration.ConnectionState.Open;
					deviceInformation.EcmID = iCPPDataLink.ECMID;
				}
				else
				{
					ICalibrationOnline calibrationOnline = (ICalibrationOnline)Modules[deviceAddress];
					if (calibrationOnline is ICalibrationECM)
					{
						ICalibrationECM calibrationECM = calibrationOnline as ICalibrationECM;
						deviceInformation = calibrationECM.DeviceInfo;
					}
				}
			}
			else
			{
				deviceInformation = (IDeviceInformation)DeviceInfoList[deviceAddress];
			}
		}
		catch (COMException ex)
		{
			TeardownMessageManager();
			EventLogger.Error(ErrorSources.Connection, GetErrorCode(ex), ex);
			throw new NoDevicesDetectedException(Facility.Connection, 0, GetError(ex), ex);
		}
		return deviceInformation;
	}

	public ICalibrationECM CreateCalibration(IDeviceInformation deviceInfo, bool createNew = false)
	{
		ICalibrationOnline calibrationOnline = null;
		IAddressValue key = AddressFactory.ProductAddressValue(deviceInfo.Address.ToString("X2"));
		if (Modules[key] == null)
		{
			ICPPDataLink iCPPDataLink;
			if (deviceInfo.EcmID == "XX")
			{
				iCPPDataLink = new GTIS45DataLink(deviceInfo);
				iCPPDataLink.State = Cummins.Calibration.ConnectionState.Open;
				try
				{
					iCPPDataLink.Connect();
					deviceInfo.DeviceState = Cummins.Calibration.ConnectionState.Connected;
				}
				catch (Exception ex)
				{
					string text = string.Format(resources.GetString("UnableToCLIP"), deviceInfo.Address.ToString("X2"));
					EventLogger.Error("Connection", text, ex);
					Trace.WriteLine(ex.Message + Environment.NewLine + ex.StackTrace, "ModuleNetwork.Connect(devices)");
					messageStack.Push(text);
				}
			}
			else
			{
				iCPPDataLink = new PreGTIS45DataLink(deviceInfo);
				iCPPDataLink.Open();
				deviceInfo.DeviceState = Cummins.Calibration.ConnectionState.Open;
			}
			ICICollection iCICollection = ModuleDetect.Detect(deviceInfo.Device, null, null, SessionConfiguration);
			if (iCICollection != null && iCICollection[0] != null)
			{
				ICIDeviceInfo iCIDeviceInfo = (ICIDeviceInfo)iCICollection[0];
				deviceInfo.Device = (ICIDCLDevice)iCIDeviceInfo.DataSource;
				ReadRunLocation(iCIDeviceInfo, deviceInfo);
				ReadProductIdentifier(iCIDeviceInfo, deviceInfo);
				ReadECMID(iCIDeviceInfo, deviceInfo);
				ReadPhase(iCIDeviceInfo, deviceInfo);
				ReadPartNumber(iCIDeviceInfo, deviceInfo);
				ReadSerialNumber(iCIDeviceInfo, deviceInfo);
				deviceInfo.Password = DeviceInvalidPassword;
				deviceInfo.Device.Password = deviceInfo.Password;
				deviceInfo.DeviceSettings = iCIDeviceInfo.DeviceOpenConfiguration;
			}
			IProgress progress = SessionService.CurrentSession.ProgressFactory.CreateProgress(string.Empty, allowCancel: false);
			calibrationOnline = (createNew ? CalibrationCreator.Create(iCPPDataLink, deviceInfo, gtisLevel) : CalibrationCreator.Create(iCPPDataLink, deviceInfo, gtisLevel, progress, OutOfRangeLimit));
			if (Modules.Count != devices.Count)
			{
				string message = string.Format(resources.GetString("UnableToConnectToAll"), devices.Count, Modules.Count);
				EventLogger.Warn("Connection", message, ConnectionDetails());
			}
		}
		else
		{
			calibrationOnline = (ICalibrationOnline)Modules[key];
		}
		return calibrationOnline as ICalibrationECM;
	}

	private string ReadDetectConfiguration()
	{
		string text = "";
		Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream(DetectionXML);
		DataSet dataSet = new DataSet();
		dataSet.ReadXml(manifestResourceStream);
		try
		{
			string setting = AppSettingHelper.GetSetting(ApplicationSettings.DetectionTimeOut);
			if (!string.IsNullOrEmpty(setting))
			{
				dataSet.Tables["Timeout"].Rows[0]["Timeout_Text"] = setting;
			}
		}
		catch
		{
		}
		return dataSet.GetXml();
	}

	private void RefreshDetectConfiguration()
	{
		//IL_0000: Unknown result type (might be due to invalid IL or missing references)
		//IL_0006: Expected O, but got Unknown
		XmlDocument val = new XmlDocument();
		val.LoadXml(DetectConfiguration);
		XmlNode documentElement = (XmlNode)(object)val.DocumentElement;
		XmlNode val2 = documentElement.SelectSingleNode("Type");
		val2.Value = Detection.ToString();
		detectConfiguration = ((XmlNode)val).InnerText;
	}

	private void OnReceiveMessage(object sender, ICIMsg msg)
	{
		try
		{
			switch (msg.MessageType)
			{
			case MsgTypeEnum.MTYPE_DIAGNOSTIC:
				ProcessDiagnosticMessage(msg);
				break;
			case MsgTypeEnum.MTYPE_PROGRESS:
				ProcessProgressMessage(msg);
				break;
			}
		}
		catch (Exception ex)
		{
			Trace.WriteLine(ex.Message + Environment.NewLine + ex.StackTrace, "ModuleNetwork:ReceiveMessage");
		}
	}

	private void OnAssignFilters(object sender, filters filters)
	{
		try
		{
			ICIFilterFactory iCIFilterFactory = (sender as Cummins.Messages.MsgManager).KSMessageManager as ICIFilterFactory;
			filters.Add(iCIFilterFactory.CreateProgressMsgFilter(-1, 20, -1, MsgProgressTypeEnum.MSGPROG_ANYPROGRESS));
			filters.Add(iCIFilterFactory.CreateDiagnosticMsgFilter(-1, 20, -1, MsgRequestTypeEnum.MSGREQ_ANYREQUEST, MsgSeverityTypeEnum.MSGSEV_ANYSEVERITY));
			filters.Add(iCIFilterFactory.CreateDiagnosticMsgFilter(-1, 2, -1, MsgRequestTypeEnum.MSGREQ_ANYREQUEST, MsgSeverityTypeEnum.MSGSEV_ANYSEVERITY));
		}
		catch
		{
		}
	}

	private void ProcessDiagnosticMessage(ICIMsg ksMSG)
	{
		msgParam msgParam = null;
		if (ksMSG.Originator == 20)
		{
			switch (ksMSG.Identifier)
			{
			case 1:
			case 8:
			case 11:
			case 12:
				EventLogger.Error("Connection", ksMSG.ProgrammerText);
				Trace.WriteLine(ksMSG.ProgrammerText, "Connection");
				messageStack.Push(ksMSG.ProgrammerText);
				break;
			case 3:
			case 4:
			case 5:
			case 7:
			case 10:
			case 13:
				ksMSG.Parameters.ParameterByName("lDeviceAddress", out msgParam);
				if (msgParam != null)
				{
					Trace.WriteLine(ksMSG.ProgrammerText + ", DeviceAddress:" + ((int)msgParam.Value).ToString("X2"), "Connection");
					messageStack.Push(ksMSG.ProgrammerText + ", DeviceAddress:" + ((int)msgParam.Value).ToString("X2"));
				}
				break;
			case 9:
				if (Protocol == "J1939")
				{
					EventLogger.Warn("Connection", ksMSG.ProgrammerText);
					Trace.WriteLine(ksMSG.ProgrammerText, "Connection");
					messageStack.Push(ksMSG.ProgrammerText);
				}
				break;
			default:
				EventLogger.Error("Connection", ksMSG.ProgrammerText);
				Trace.WriteLine(ksMSG.ProgrammerText, "Connection");
				break;
			}
		}
		else if (ksMSG.Originator == 2)
		{
			switch (ksMSG.Identifier)
			{
			case 80:
				FindAndSetDeviceState(ksMSG, Cummins.Calibration.ConnectionState.Connecting);
				break;
			case 62:
				FindAndSetDeviceState(ksMSG, Cummins.Calibration.ConnectionState.Connected);
				break;
			case 63:
				FindAndSetDeviceState(ksMSG, Cummins.Calibration.ConnectionState.Disconnecting);
				break;
			case 64:
			case 81:
			case 98:
				FindAndSetDeviceState(ksMSG, Cummins.Calibration.ConnectionState.Disconnected);
				break;
			case 5:
				FindAndSetDeviceState(ksMSG, Cummins.Calibration.ConnectionState.Closed);
				break;
			default:
				Trace.WriteLine(ksMSG.ProgrammerText, "Connection");
				messageStack.Push(ksMSG.ProgrammerText);
				break;
			}
			Trace.WriteLine(ksMSG.ProgrammerText, "Connection");
		}
	}

	private void ProcessProgressMessage(ICIMsg ksMSG)
	{
		if (ksMSG.Originator == 20)
		{
			msgParam msgParam = null;
			string text = "";
			switch (ksMSG.Identifier)
			{
			case 101:
				text = resources.GetString("DetectionStarted");
				break;
			case 102:
				text = resources.GetString("DetectionCompleted");
				break;
			case 103:
				ksMSG.Parameters.ParameterByName("lDeviceAddress", out msgParam);
				text = resources.GetString("DeviceDetected") + ((int)msgParam.Value).ToString("X2");
				break;
			case 104:
				ksMSG.Parameters.ParameterByName("lDeviceAddress", out msgParam);
				text = resources.GetString("DeviceIdentified") + ((int)msgParam.Value).ToString("X2");
				break;
			case 105:
				text = resources.GetString("AddressClaimCompleted");
				break;
			case 106:
				ksMSG.Parameters.ParameterByName("lDeviceAddress", out msgParam);
				text = string.Format(resources.GetString("RequestECMID"), ((int)msgParam.Value).ToString("X2"));
				break;
			case 107:
				text = resources.GetString("ECMIDRequestSuccess");
				break;
			case 108:
			{
				ksMSG.Parameters.ParameterByName("lDeviceAddress", out msgParam);
				string arg = ((int)msgParam.Value).ToString("X2");
				ksMSG.Parameters.ParameterByName("bsECMId", out msgParam);
				string arg2 = msgParam.Value.ToString();
				text = string.Format(resources.GetString("ReceivedECMID"), arg2, arg);
				break;
			}
			default:
				text = ksMSG.ProgrammerText;
				break;
			}
			Trace.WriteLine(text);
			if (Progress != null)
			{
				Progress.SetProgress(text);
			}
			EventLogger.Log("Connection", text);
			messageStack.Push(text);
		}
	}

	private void AttachConnectionEvent()
	{
		foreach (ICalibrationOnline value in Modules.Values)
		{
			AttachConnectionEvent(value);
		}
	}

	private void DetachConnectionEvent()
	{
		foreach (ICalibrationOnline value in Modules.Values)
		{
			DetachConnectionEvent(value);
		}
	}

	private void AttachConnectionEvent(ICalibrationOnline calibrationOnline)
	{
		if (calibrationOnline != null)
		{
			calibrationOnline.ConnectionEstablished += OnConnectionEstablished;
			calibrationOnline.ConnectionFading += OnConnectionFading;
			calibrationOnline.ConnectionLost += OnConnectionLost;
			calibrationOnline.SuspendMonitoringChanged += OnSuspendMonitoringChanged;
		}
	}

	private void DetachConnectionEvent(ICalibrationOnline calibrationOnline)
	{
		if (calibrationOnline != null)
		{
			calibrationOnline.ConnectionEstablished -= OnConnectionEstablished;
			calibrationOnline.ConnectionFading -= OnConnectionFading;
			calibrationOnline.ConnectionLost -= OnConnectionLost;
			calibrationOnline.SuspendMonitoringChanged -= OnSuspendMonitoringChanged;
		}
	}

	private void OnConnectionEstablished(object sender, EventArgs e)
	{
		ICalibrationOnline calibrationOnline = (ICalibrationOnline)sender;
		IAddressValue sourceAddress = calibrationOnline.SourceAddress;
		if (this.ConnectionEstablished != null)
		{
			DeviceAddressEventArgs e2 = new DeviceAddressEventArgs(sourceAddress);
			this.ConnectionEstablished(sender, e2);
		}
		IActivityLogService activityLogService = ServiceManager.Services.GetService(typeof(IActivityLogService)) as IActivityLogService;
		Dictionary<ELogEntryField, string> dictionary = new Dictionary<ELogEntryField, string>();
		dictionary.Add(ELogEntryField._FEATURE_NAME, "ConnectionEstablished");
		dictionary.Add(ELogEntryField._FEATURE_DETAILS, "Address = " + sourceAddress.DisplayId);
		activityLogService.CacheLogContext(dictionary);
	}

	private void OnConnectionFading(object sender, EventArgs e)
	{
		if (this.ConnectionFading != null)
		{
			IAddressValue sourceAddress = ((ICalibrationECM)sender).SourceAddress;
			DeviceAddressEventArgs e2 = new DeviceAddressEventArgs(sourceAddress);
			this.ConnectionFading(sender, e2);
		}
	}

	private void OnConnectionLost(object sender, EventArgs e)
	{
		if (this.ConnectionLost != null)
		{
			IAddressValue sourceAddress = ((ICalibrationOnline)sender).SourceAddress;
			DeviceAddressEventArgs e2 = new DeviceAddressEventArgs(sourceAddress);
			this.ConnectionLost(sender, e2);
		}
	}

	private void OnSuspendMonitoringChanged(object sender, SuspendMonitoringChangedEventArgs e)
	{
		RaiseSuspendMonitoringChanged(e.DeviceAddress, e.AllDevices, e.Suspend, e.SuspendDataMonitoring);
	}

	public bool HasBroadcast()
	{
		return IsJ1939(DatalinkConfiguration);
	}

	public bool SystemSuspendMonitoring()
	{
		return SystemSuspendMonitoring(CurrentDeviceAddress);
	}

	public void SystemSuspendMonitoring(bool suspend)
	{
		SystemSuspendMonitoring(CurrentDeviceAddress, suspend);
	}

	public bool SystemSuspendMonitoring(IAddressValue deviceAddress)
	{
		bool result = false;
		if (Modules.Contains(deviceAddress))
		{
			ICalibrationOnline calibrationOnline = (ICalibrationOnline)Modules[deviceAddress];
			if (calibrationOnline != null)
			{
				result = calibrationOnline.SystemSuspendMonitoring;
			}
		}
		return result;
	}

	public void SystemSuspendMonitoring(IAddressValue deviceAddress, bool suspend)
	{
		if (Modules.Contains(deviceAddress) && SystemSuspendMonitoringQuietly(deviceAddress, suspend))
		{
			RaiseSuspendMonitoringChanged(deviceAddress, allDevices: false, suspend, suspendDataMonitoring: true);
		}
	}

	private bool SystemSuspendMonitoringQuietly(IAddressValue deviceAddress, bool suspend)
	{
		bool flag = false;
		try
		{
			((ICalibrationOnline)Modules[deviceAddress]).SystemSuspendMonitoring = suspend;
			return true;
		}
		catch
		{
			return false;
		}
	}

	public string ConnectionDetails()
	{
		StringBuilder stringBuilder = new StringBuilder();
		while (messageStack.Count > 0)
		{
			stringBuilder.Append((string)messageStack.Pop());
			stringBuilder.Append(Environment.NewLine);
		}
		return stringBuilder.ToString();
	}

	public void CloseBroadcastSubscription()
	{
		if (_broadcastSubscription != null)
		{
			J1939_71BroadcastSubscription j1939_71BroadcastSubscription = _broadcastSubscription as J1939_71BroadcastSubscription;
			j1939_71BroadcastSubscription.Stop();
			j1939_71BroadcastSubscription.CloseConnection();
			_broadcastSubscription = null;
		}
	}

	public void ReopenBroadcastSubscription()
	{
		if (_broadcastSubscription != null)
		{
			J1939_71BroadcastSubscription j1939_71BroadcastSubscription = _broadcastSubscription as J1939_71BroadcastSubscription;
			j1939_71BroadcastSubscription.ReopenConnection();
			j1939_71BroadcastSubscription.Start();
		}
	}

	private void ReadPhase(ICIDeviceInfo activeDevice, IDeviceInformation deviceInfo)
	{
		try
		{
			deviceInfo.Phase = activeDevice.Phase;
			if (deviceInfo.RunLocation != RunLocationType.RomBoot && deviceInfo.RunLocation != RunLocationType.Undefined)
			{
				deviceInfo.Phase = activeDevice.Phase;
				if (activeDevice.Version != null)
				{
					deviceInfo.CalibrationVersion = activeDevice.Version.ToString();
				}
			}
		}
		catch (Exception ex)
		{
			string text = string.Format(resources.GetString("UnableToRead"), "Phase", deviceInfo.Address.ToString("X2"));
			EventLogger.Warn("Connection", text, ex.Message);
			Trace.WriteLine(ex.Message + Environment.NewLine + ex.StackTrace, "ModuleNetwork:ReadPhase");
			messageStack.Push(text);
		}
	}

	private void ReadRunLocation(ICIDeviceInfo activeDevice, IDeviceInformation deviceInfo)
	{
		try
		{
			deviceInfo.RunLocation = MapRunLocation(activeDevice.RunLocation);
		}
		catch (Exception ex)
		{
			string text = string.Format(resources.GetString("UnableToRead"), "RunLocation", deviceInfo.Address.ToString("X2"));
			EventLogger.Warn("Connection", text, ex.Message);
			Trace.WriteLine(ex.Message + Environment.NewLine + ex.StackTrace, "ModuleNetwork:ReadRunLocation");
			messageStack.Push(text);
		}
	}

	private void ReadProductIdentifier(ICIDeviceInfo activeDevice, IDeviceInformation deviceInfo)
	{
		deviceInfo.ProductId = activeDevice.ProductIdentifier;
		if (string.IsNullOrEmpty(SelectedProductID))
		{
			return;
		}
		try
		{
			bool flag = false;
			IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			string productInformation = productInformationService.GetProductInformation(SelectedProductID, ProductInformationType.Child);
			if (!((activeDevice.RunLocation == CIRunLocationEnum.MDC_RL_ROM_BOOT_LOADER) ? (-1 != deviceInfo.ProductId.ToUpper().IndexOf(SelectedProductID.ToUpper())) : ((!(productInformation != string.Empty)) ? SelectedProductID.ToUpper().Equals(deviceInfo.ProductId.ToUpper()) : (SelectedProductID.ToUpper().Equals(deviceInfo.ProductId.ToUpper()) || productInformation.ToUpper().Contains(deviceInfo.ProductId.ToUpper())))))
			{
				string value = string.Format(resources.GetString("ProductIDMismatch"), deviceInfo.Address.ToString("X2"), SelectedProductID, deviceInfo.ProductId);
				warnings.Add(value);
			}
		}
		catch (Exception ex)
		{
			deviceInfo.ProductId = string.Empty;
			string text = string.Format(resources.GetString("UnableToRead"), "ProductID", deviceInfo.Address.ToString("X2"));
			EventLogger.Warn("Connection", text, ex.Message);
			Trace.WriteLine(ex.Message + Environment.NewLine + ex.StackTrace, "ModuleNetwork:ReadProductID");
			messageStack.Push(text);
		}
	}

	private void ReadPartNumber(ICIDeviceInfo activeDevice, IDeviceInformation deviceInfo)
	{
		ICIDeviceInfo5 iCIDeviceInfo = activeDevice as ICIDeviceInfo5;
		try
		{
			deviceInfo.PartNumber = iCIDeviceInfo.ModulePartNumber2;
		}
		catch
		{
			deviceInfo.PartNumber = string.Empty;
		}
	}

	private void ReadSerialNumber(ICIDeviceInfo activeDevice, IDeviceInformation deviceInfo)
	{
		try
		{
			deviceInfo.SerialNumber = activeDevice.ModuleSerialNumber.ToString();
		}
		catch
		{
			deviceInfo.SerialNumber = string.Empty;
		}
	}

	private void ReadECMID(ICIDeviceInfo activeDevice, IDeviceInformation deviceInfo)
	{
		try
		{
			deviceInfo.EcmID = activeDevice.ModuleIdentifier;
		}
		catch (Exception ex)
		{
			deviceInfo.EcmID = string.Empty;
			EventLogger.Warn("Connection", "Unable to read ECM Identifier for device at address " + deviceInfo.Address.ToString("X2"), ex.Message);
			Trace.WriteLine(ex.Message + Environment.NewLine + ex.StackTrace, "ModuleNetwork:RefreshDeviceAddresses");
		}
	}

	private RunLocationType MapRunLocation(CIRunLocationEnum mdcRunLocation)
	{
		RunLocationType runLocationType = RunLocationType.Undefined;
		return mdcRunLocation switch
		{
			CIRunLocationEnum.MDC_RL_DEFAULT => (GTISLevel != GTISVersion.GTIS45) ? RunLocationType.Default : RunLocationType.Application, 
			CIRunLocationEnum.MDC_RL_DEVELOPMENT => RunLocationType.Development, 
			CIRunLocationEnum.MDC_RL_ROM_BOOT_LOADER => RunLocationType.RomBoot, 
			_ => RunLocationType.Undefined, 
		};
	}

	private string GetError(COMException ex)
	{
		int dCLErrorCode = DCL.GetDCLErrorCode(ex.Message);
		string empty = string.Empty;
		switch (dCLErrorCode)
		{
		case 22:
			empty = resources.GetString("NoDatalink");
			break;
		case 23:
			empty = resources.GetString("NoResponse");
			break;
		default:
		{
			ICIErrorMessageSet iCIErrorMessageSet = new ErrorMessageSetClass();
			iCIErrorMessageSet.loadXML(ex.Message);
			iCIErrorMessageSet.MoveFirst();
			empty = iCIErrorMessageSet.description;
			break;
		}
		}
		Trace.WriteLine(ex.Message, "Connection");
		return empty;
	}

	private ushort GetErrorCode(COMException ex)
	{
		int dCLErrorCode = DCL.GetDCLErrorCode(ex.Message);
		ushort num = 0;
		return dCLErrorCode switch
		{
			22 => 0, 
			23 => 4, 
			9 => 0, 
			228 => 0, 
			20 => 0, 
			107 => 0, 
			187 => 0, 
			_ => 3, 
		};
	}

	private void RaiseSuspendMonitoringChanged(IAddressValue deviceAddress, bool allDevices, bool suspended, bool suspendDataMonitoring)
	{
		if (this.SuspendMonitoringChanged != null)
		{
			SuspendMonitoringChangedEventArgs e = new SuspendMonitoringChangedEventArgs(deviceAddress, allDevices, suspended, suspendDataMonitoring);
			this.SuspendMonitoringChanged(this, e);
		}
	}

	private void FindAndSetDeviceState(ICIMsg ksMSG, Cummins.Calibration.ConnectionState state)
	{
		msgParam msgParam = null;
		if (ksMSG == null || ksMSG.Parameters == null)
		{
			return;
		}
		ksMSG.Parameters.ParameterByName("DeviceAddress", out msgParam);
		if (msgParam != null)
		{
			int num = int.Parse(msgParam.Value.ToString());
			string text = ksMSG.ProgrammerText + ", DeviceAddress:" + num.ToString("X2");
			Trace.WriteLine(text, "Connection");
			EventLogger.Log("Connection", text);
			messageStack.Push(text);
			IAddressValue key = AddressFactory.ProductAddressValue(num.ToString("X2"));
			if (ModuleState.Contains(key))
			{
				ModuleState[key] = state;
			}
			else
			{
				ModuleState.Add(key, state);
			}
		}
	}

	private void OnCalibrationCreated(object sender, CalibrationCreationEventArgs e)
	{
		if (e.Calibration != null)
		{
			e.Calibration.VerifiedHeaderRecordEvent += OnVerifiedHeaderRecordEvent;
			e.Calibration.VerifyHeaderRecordEvent += OnHeaderRecordVerified;
		}
	}

	private void OnHeaderRecordVerified(object sender, VerifyHeaderRecordEventArgs e)
	{
		if (sender is ICalibrationOnline && e is MisMatchEventArgs)
		{
			MisMatchEventArgs e2 = (MisMatchEventArgs)e;
			string value = string.Format(resources.GetString("HeaderMismatchError"), e2.HeaderRecord.ToString(), (sender as ICalibrationOnline).SourceAddress.ToString(), e2.ConfigHeaderValue, e2.ConfigFileValue);
			warnings.Add(value);
		}
	}

	private void OnVerifiedHeaderRecordEvent(object sender, EventArgs e)
	{
		numberOfCalibrationToVerify--;
		if (numberOfCalibrationToVerify == 0 && this.CalibrationsVerified != null)
		{
			this.CalibrationsVerified(null, EventArgs.Empty);
		}
	}

	private void HandleConnectException(Exception ex, IDeviceInformation deviceInfo, string msg)
	{
		numberOfCalibrationToVerify--;
		Trace.WriteLine(msg + Environment.NewLine + ex.Message + Environment.NewLine + ex.StackTrace, "Connection");
		LogError(ex, msg);
		messageStack.Push(msg);
		IAddressValue key = AddressFactory.ProductAddressValue(deviceInfo.Address.ToString());
		if (Modules.Contains(key))
		{
			Modules.Remove(key);
		}
		if (deviceInfo.Device != null && deviceInfo.Device.State == DeviceStateEnum.DEVCTRL_OPEN)
		{
			deviceInfo.Device.Close();
		}
	}

	private void LogError(Exception ex, string msg)
	{
		if (ex is GTISLevelMismatchException)
		{
			EventLogger.Error(ErrorSources.Connection, 2, ex, (ex as GTISLevelMismatchException).ExpectedVersion, (ex as GTISLevelMismatchException).ActualVersion);
		}
		else if (ex is ConfigFileGTISLevelMismatchException)
		{
			EventLogger.Error(ErrorSources.Connection, 2, ex, (ex as ConfigFileGTISLevelMismatchException).ActualVersion, (ex as ConfigFileGTISLevelMismatchException).ExpectedVersion);
		}
		else if (ex is NotRunningGTIS45Exception)
		{
			EventLogger.Error(ErrorSources.Connection, 2, ex, GTISVersion.GTIS45.ToString(), "NotGTIS45");
		}
		else
		{
			EventLogger.Error("Connection", msg, ex);
		}
	}

	private void RaisePauseAllMonitoringEventChanged()
	{
		if (this.PauseMonitoringChanged != null)
		{
			PauseMonitoringChangedEventArgs e = new PauseMonitoringChangedEventArgs(SystemPauseAllMonitoring);
			this.PauseMonitoringChanged(this, e);
		}
	}
}
public delegate void SuspendMonitoringChangedEventHandler(object sender, SuspendMonitoringChangedEventArgs e);
public delegate void PauseMonitoringChangedEventHandler(object sender, PauseMonitoringChangedEventArgs e);
public enum AdapterType
{
	RP1210a
}
public enum DetectionType
{
	DeviceAddress,
	DeviceID,
	EcmID,
	All
}
public delegate void DeviceAddressEventHandler(object sender, DeviceAddressEventArgs e);
public class PauseMonitoringChangedEventArgs : EventArgs
{
	private bool pauseMonitoring;

	public bool PauseMonitoring => pauseMonitoring;

	public PauseMonitoringChangedEventArgs(bool pausemonitoring)
	{
		pauseMonitoring = pausemonitoring;
	}
}
