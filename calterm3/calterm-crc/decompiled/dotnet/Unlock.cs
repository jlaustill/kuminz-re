#define TRACE
using System;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Threading;
using System.Windows.Forms;
using System.Xml;
using Cummins.AddressRepresentation;
using Cummins.ApplicationServices;
using Cummins.Calibration;
using Cummins.EventLog;
using Cummins.MessageDialog;
using Cummins.Module;
using Cummins.ProductInformationProvider;
using Cummins.Services;
using Cummins.Widgets;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyTitle("Poodle")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.Unlock;

public class AutoStopBroadcastChangedEventArgs : EventArgs
{
	private bool isAutoStopBroadcast;

	public bool IsAutoStopBroadcast => isAutoStopBroadcast;

	public AutoStopBroadcastChangedEventArgs(bool isAutostopBroadcast)
	{
		isAutoStopBroadcast = isAutostopBroadcast;
	}
}
public class CurrentDeviceChangedEventArgs : EventArgs
{
	private string detectionInformation;

	private string deviceAddress;

	private bool isManualAddress;

	public string DeviceAddress
	{
		get
		{
			return deviceAddress;
		}
		set
		{
			deviceAddress = value;
		}
	}

	public bool IsManualAddress
	{
		get
		{
			return isManualAddress;
		}
		set
		{
			isManualAddress = value;
		}
	}

	public string DetectionConfiguration
	{
		get
		{
			return detectionInformation;
		}
		set
		{
			detectionInformation = value;
		}
	}

	public CurrentDeviceChangedEventArgs(string deviceAddress)
	{
		this.deviceAddress = deviceAddress;
	}
}
public class DeviceAddressListChangedEventArgs : EventArgs
{
	private StringCollection devices;

	public StringCollection Devices => devices;

	public DeviceAddressListChangedEventArgs(StringCollection devices)
	{
		this.devices = devices;
	}
}
public class DeviceInfoChangedEventArgs : EventArgs
{
	private RunLocationType runLocation = RunLocationType.Undefined;

	private SecurityStatus securityState = SecurityStatus.NotApplicable;

	private string firmwareRevision = string.Empty;

	private string adapter = string.Empty;

	private string calibrationVersion = string.Empty;

	private string productID = string.Empty;

	private ECMState ecmStatus = ECMState.Unknown;

	private string moduleType = string.Empty;

	private string serialNumber = string.Empty;

	private string ecmCodeRevision = string.Empty;

	private string partNumber = string.Empty;

	private string ecmCode = string.Empty;

	private string deviceAddress = string.Empty;

	private bool connected = true;

	public ECMState ECMStatus
	{
		get
		{
			return ecmStatus;
		}
		set
		{
			ecmStatus = value;
		}
	}

	public string FirmwareRevision
	{
		get
		{
			return firmwareRevision;
		}
		set
		{
			firmwareRevision = value;
		}
	}

	public string Adapter
	{
		get
		{
			return adapter;
		}
		set
		{
			adapter = value;
		}
	}

	public string CalibrationVersion
	{
		get
		{
			return calibrationVersion;
		}
		set
		{
			calibrationVersion = value;
		}
	}

	public SecurityStatus SecurityState
	{
		get
		{
			return securityState;
		}
		set
		{
			securityState = value;
		}
	}

	public RunLocationType RunLocation
	{
		get
		{
			return runLocation;
		}
		set
		{
			runLocation = value;
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

	public string SerialNumber
	{
		get
		{
			return serialNumber;
		}
		set
		{
			serialNumber = value;
		}
	}

	public string ModuleType
	{
		get
		{
			return moduleType;
		}
		set
		{
			moduleType = value;
		}
	}

	public string PartNumber
	{
		get
		{
			return partNumber;
		}
		set
		{
			partNumber = value;
		}
	}

	public string DeviceAddress
	{
		get
		{
			return deviceAddress;
		}
		set
		{
			deviceAddress = value;
		}
	}

	public bool Connected
	{
		get
		{
			return connected;
		}
		set
		{
			connected = value;
		}
	}
}
public enum MsgID
{
	ECMStatusNotSupported,
	SecurityStatusNotSupported,
	UnableToToggleSecurity
}
public class UnlockException : BaseException
{
	public UnlockException(Facility facility, short errorNo)
		: base(facility, errorNo)
	{
	}

	public UnlockException(Facility facility, short errorNo, string message)
		: base(facility, errorNo, message)
	{
	}

	public UnlockException(Facility facility, short errorNo, string message, Exception inner)
		: base(facility, errorNo, message, inner)
	{
	}

	public UnlockException(Facility facility, short errorNo, string message, string context)
		: base(facility, errorNo, message, context)
	{
	}

	public UnlockException(Facility facility, short errorNo, string message, string context, Exception inner)
		: base(facility, errorNo, message, context, inner)
	{
	}
}
public class UnableToToggleSecurity : UnlockException
{
	public UnableToToggleSecurity(Facility facility, short errorNo)
		: base(facility, errorNo)
	{
	}

	public UnableToToggleSecurity(Facility facility, short errorNo, string message)
		: base(facility, errorNo, message)
	{
	}

	public UnableToToggleSecurity(Facility facility, short errorNo, string message, Exception inner)
		: base(facility, errorNo, message, inner)
	{
	}

	public UnableToToggleSecurity(Facility facility, short errorNo, string message, string context)
		: base(facility, errorNo, message, context)
	{
	}

	public UnableToToggleSecurity(Facility facility, short errorNo, string message, string context, Exception inner)
		: base(facility, errorNo, message, context, inner)
	{
	}
}
public class ECMStatusNotSupportedException : UnlockException
{
	private string moduleType = string.Empty;

	public string ModuleType => moduleType;

	public ECMStatusNotSupportedException(Facility facility, short errorNo, string moduleType)
		: base(facility, errorNo)
	{
		this.moduleType = moduleType;
	}

	public ECMStatusNotSupportedException(Facility facility, short errorNo, string message, string moduleType)
		: base(facility, errorNo, message)
	{
		this.moduleType = moduleType;
	}

	public ECMStatusNotSupportedException(Facility facility, short errorNo, string message, Exception inner, string moduleType)
		: base(facility, errorNo, message, inner)
	{
		this.moduleType = moduleType;
	}

	public ECMStatusNotSupportedException(Facility facility, short errorNo, string message, string context, string moduleType)
		: base(facility, errorNo, message, context)
	{
		this.moduleType = moduleType;
	}

	public ECMStatusNotSupportedException(Facility facility, short errorNo, string message, string context, Exception inner, string moduleType)
		: base(facility, errorNo, message, context, inner)
	{
		this.moduleType = moduleType;
	}
}
public class SecurityNotSupportedException : UnlockException
{
	private string moduleType = string.Empty;

	public string ModuleType => moduleType;

	public SecurityNotSupportedException(Facility facility, short errorNo, string moduleType)
		: base(facility, errorNo)
	{
		this.moduleType = moduleType;
	}

	public SecurityNotSupportedException(Facility facility, short errorNo, string message, string moduleType)
		: base(facility, errorNo, message)
	{
		this.moduleType = moduleType;
	}

	public SecurityNotSupportedException(Facility facility, short errorNo, string message, Exception inner, string moduleType)
		: base(facility, errorNo, message, inner)
	{
		this.moduleType = moduleType;
	}

	public SecurityNotSupportedException(Facility facility, short errorNo, string message, string context, string moduleType)
		: base(facility, errorNo, message, context)
	{
		this.moduleType = moduleType;
	}

	public SecurityNotSupportedException(Facility facility, short errorNo, string message, string context, Exception inner, string moduleType)
		: base(facility, errorNo, message, context, inner)
	{
		this.moduleType = moduleType;
	}
}
public interface IUnlock
{
	void Invoke(IWin32Window parent);
}
public class Unlock : IUnlock
{
	private UnlockView view;

	private UnlockModel model;

	private UnlockController controller;

	public Unlock()
	{
		model = new UnlockModel();
		controller = new UnlockController(model);
		view = new UnlockView(controller, model);
	}

	public void Invoke(IWin32Window parent)
	{
		//IL_0007: Unknown result type (might be due to invalid IL or missing references)
		((Form)view).ShowDialog(parent);
	}
}
public class UnlockController
{
	private UnlockModel model;

	public UnlockController(UnlockModel model)
	{
		this.model = model;
	}

	public virtual void OnSecurityStateChanged(object sender, EngrSecurityKeyChangedEventArgs args)
	{
		model.SecurityState = args.SecurityState;
	}

	public virtual void OnECMStatusChanged(object sender, ECMStatusChangedEventArgs args)
	{
		model.ECMStatus = args.PresentECMState;
	}

	public virtual void OnDeviceAddressChanged(object sender, CurrentDeviceChangedEventArgs args)
	{
		IAddressValue currentAddress = AddressFactory.ProductAddressValue(args.DeviceAddress);
		_ = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		model.CurrentAddress = currentAddress;
	}

	public virtual void OnFindAllDeviceAddress(object sender, EventArgs args)
	{
		model.FindAllDevices();
	}

	public virtual void OnViewExiting(object sender, CancelEventArgs args)
	{
		model.OnViewExiting();
	}

	public void OnAutoStopBroadcastChanged(object sender, AutoStopBroadcastChangedEventArgs args)
	{
		model.AutoStopBroadcast = args.IsAutoStopBroadcast;
	}
}
public delegate void DeviceInfoChangedEventHandler(object sender, DeviceInfoChangedEventArgs args);
public delegate void CurrentDeviceChangedEventHandler(object sender, CurrentDeviceChangedEventArgs args);
public delegate void DeviceAddressListChangedEventHandler(object sender, DeviceAddressListChangedEventArgs args);
public delegate void FindAllDeviceEventHandler(object sender, EventArgs args);
public delegate void AutoStopBroadcastChangedEventHandler(object sender, AutoStopBroadcastChangedEventArgs args);
public enum MessageIds
{
	UnableToReadProductID,
	UnableToReadCalibrationVersion,
	UnableToReadECMCode,
	UnableToReadECMCodeRevision,
	UnableToReadECMStatus,
	DeviceAddressChanged,
	SecurityStatusChanged,
	UnableToChangeSecurityStatus,
	SecurityStatusChangedRomBoot,
	UnableToConnect,
	OperationNotSupportedByECM,
	CM4XX,
	ECMB,
	CheckLogTab,
	ConnectionSettingsChanged
}
public class UnlockModel : IDisposable
{
	private delegate void SetActiveDeviceDelegate(IAddressValue deviceAddress);

	private const string gtis45ConfigFileName = "Cummins.Unlock.gtis45.ecfg";

	private const string gtis38ConfigFileName = "Cummins.Unlock.GTIS38.e2m";

	private const string ResourceFileName = "Cummins.Unlock.strings";

	private const string Gtis45ModuleEcmId = "XX";

	private const string ECMStatusNotSupportedModule = "ECMB";

	private ICalibrationECM activeDevice;

	private IPublicDataSource activeJ1939Device;

	private IModuleNetwork network;

	private IAddressValue currentDevice;

	private SecurityStatus securityState;

	private bool disposed;

	private string gtis45ConfigFile;

	private string gtis38ConfigFile;

	private ResourceManager resourceManager;

	private bool deviceDetected;

	private bool autoStopBroadcast;

	private string[] SecurityNotSupportedModules = new string[1] { "CM4" };

	public ECMState ECMStatus
	{
		get
		{
			ECMState result = ECMState.Unknown;
			if (IsECMStatusSupported())
			{
				result = ActiveDevice.ECMStatus;
			}
			return result;
		}
		set
		{
			if (!IsECMStatusSupported())
			{
				throw new ECMStatusNotSupportedException(Facility.Unlock, 0, GetModuleType());
			}
			CommandExecuting();
			try
			{
				bool flag = false;
				if (ActiveDevice.Secured == SecurityStatus.Secured)
				{
					flag = true;
					ActiveDevice.DataLink.EnableSecurity = true;
				}
				ActiveDevice.ECMStatus = value;
				if (flag)
				{
					ActiveDevice.DataLink.EnableSecurity = false;
				}
			}
			catch (CalibrationException e)
			{
				EventLogger.Error("Unlock", "Unable to change the ECM Status", e);
			}
		}
	}

	public SecurityStatus SecurityState
	{
		get
		{
			securityState = SecurityStatus.Unknown;
			if (IsSecuritySupported())
			{
				securityState = ActiveDevice.Secured;
			}
			return securityState;
		}
		set
		{
			try
			{
				if (ActiveDevice != null)
				{
					if (IsSecuritySupported())
					{
						CommandExecuting();
						ToggleSecurity();
						securityState = ActiveDevice.Secured;
						return;
					}
					throw new SecurityNotSupportedException(Facility.Unlock, 1, GetModuleType());
				}
				throw new UnableToToggleSecurity(Facility.Unlock, 2, resourceManager.GetString(MessageIds.UnableToChangeSecurityStatus.ToString()));
			}
			catch (DatalinkNotConnectedException inner)
			{
				throw new UnableToToggleSecurity(Facility.Unlock, 2, resourceManager.GetString(MessageIds.UnableToChangeSecurityStatus.ToString()), inner);
			}
			catch (COMException inner2)
			{
				throw new UnableToToggleSecurity(Facility.Unlock, 2, resourceManager.GetString(MessageIds.UnableToChangeSecurityStatus.ToString()), inner2);
			}
		}
	}

	public IAddressValue CurrentAddress
	{
		get
		{
			return currentDevice;
		}
		set
		{
			try
			{
				if (currentDevice != value)
				{
					currentDevice = value;
					SetActiveDeviceDelegate setActiveDeviceDelegate = SetActiveDevice;
					setActiveDeviceDelegate.BeginInvoke(currentDevice, null, null);
				}
			}
			catch (Exception e)
			{
				EventLogger.Error("Unlock", "Unable to change the device address", e);
			}
		}
	}

	public bool AutoStopBroadcast
	{
		get
		{
			return autoStopBroadcast;
		}
		set
		{
			autoStopBroadcast = value;
		}
	}

	private string GTIS45ConfigFile
	{
		get
		{
			if (gtis45ConfigFile == null)
			{
				gtis45ConfigFile = GetResourceConfigFileName("Cummins.Unlock.gtis45.ecfg");
			}
			return gtis45ConfigFile;
		}
	}

	private string GTIS38ConfigFile
	{
		get
		{
			if (gtis38ConfigFile == null)
			{
				gtis38ConfigFile = GetResourceConfigFileName("Cummins.Unlock.GTIS38.e2m");
			}
			return gtis38ConfigFile;
		}
	}

	private IModuleNetwork Network
	{
		get
		{
			if (network == null)
			{
				network = new ModuleNetwork();
				network.QueryRunLocation = false;
				network.AutoReconnect = false;
			}
			return network;
		}
		set
		{
			network = value;
		}
	}

	private ICalibrationECM ActiveDevice
	{
		get
		{
			return activeDevice;
		}
		set
		{
			if (value != null)
			{
				activeDevice = value;
				if (activeDevice.DeviceInfo.RunLocation != RunLocationType.RomBoot && AutoStopBroadcast)
				{
					activeDevice.Execute(CommandType.StopBroadcast);
				}
				RaiseDeviceInfoChanged(connected: true);
			}
			else if (activeJ1939Device == null)
			{
				EventLogger.Error("Unlock", "Unable to create the calibration");
				RaiseDeviceInfoChanged(connected: false);
			}
		}
	}

	private IPublicDataSource ActiveJ1939Device
	{
		get
		{
			return activeJ1939Device;
		}
		set
		{
			if (value != null)
			{
				activeJ1939Device = value;
				RaiseDeviceInfoChanged(connected: true);
			}
		}
	}

	public event DeviceInfoChangedEventHandler DeviceInfoChanged;

	public event DeviceAddressListChangedEventHandler DeviceAddressListChanged;

	public event EventHandler SecurityStatusChangedEvent;

	public event ECMStatusChangedEventHandler ECMStatusChangedEvent;

	public UnlockModel()
	{
		resourceManager = new ResourceManager("Cummins.Unlock.strings", Assembly.GetExecutingAssembly());
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
			try
			{
				if (network != null)
				{
					network.Disconnect();
					network.Dispose();
					File.Delete(network.SelectedConfigFilename);
				}
				if (activeDevice != null)
				{
					activeDevice.DatalinkDisconnect();
					activeDevice.DatalinkClose();
					activeDevice.Dispose();
					activeDevice = null;
				}
			}
			catch (Exception)
			{
			}
		}
	}

	private void OnECMStatusChanged(object sender, ECMStatusChangedEventArgs e)
	{
		RaiseECMStatusChanged(e);
	}

	public void FindAllDevices()
	{
		if (Network.Modules.Count != 0)
		{
			Network.Disconnect();
		}
		Thread thread = new Thread(DetectDevices);
		thread.Name = "Module Detection Thread";
		thread.Start();
	}

	public void OnViewExiting()
	{
		IDatalinkSessionService datalinkSessionService = (IDatalinkSessionService)ServiceManager.Services.GetService(typeof(IDatalinkSessionService));
		datalinkSessionService.SetSessionContext(GTIS45ToolFamily.Engineering);
		disposed = false;
		Dispose();
	}

	private void ToggleSecurity()
	{
		if (ActiveDevice == null)
		{
			return;
		}
		try
		{
			ExecutionResult executionResult = ActiveDevice.Execute(CommandType.ToggleSecurityKey);
			if (executionResult.returnCode == CommandReturnType.Succeed)
			{
				EventLogger.Info("Unlock", resourceManager.GetString(MessageIds.SecurityStatusChanged.ToString()));
				if (ActiveDevice.DeviceInfo.RunLocation == RunLocationType.RomBoot)
				{
					EventLogger.Info("Unlock", resourceManager.GetString(MessageIds.SecurityStatusChangedRomBoot.ToString()));
				}
				return;
			}
			EventLogger.Info("Unlock", resourceManager.GetString(MessageIds.UnableToChangeSecurityStatus.ToString()) + ":" + executionResult.responseDescription);
			throw new UnableToToggleSecurity(Facility.Unlock, 2);
		}
		catch (ECMCommandsException ex)
		{
			EventLogger.Error("Unlock", "Unable to change the security: Command Aborted", ex);
			throw new UnableToToggleSecurity(Facility.Unlock, 2, resourceManager.GetString(MessageIds.UnableToChangeSecurityStatus.ToString()), ex);
		}
	}

	private void SetActiveDevice(IAddressValue currentDevice)
	{
		ICalibrationECM calibrationECM = null;
		IDeviceInformation deviceInformation = null;
		try
		{
			deviceInformation = Network.Connect(currentDevice);
			if (deviceInformation != null)
			{
				ConfigureNetwork(deviceInformation);
				if (!IsProductSupported(deviceInformation.ProductId))
				{
					SetSelectedProduct(deviceInformation.EcmID);
				}
				calibrationECM = Network.CreateCalibration(deviceInformation, createNew: true);
				if (calibrationECM != null)
				{
					calibrationECM.ECMStatusChanged += OnECMStatusChanged;
					calibrationECM.EngrSecurityKeyChangedEvent += OnSecurityStatusChanged;
					if (calibrationECM.ECM_ID == "XX")
					{
						calibrationECM.Execute(CommandType.RequestChangeLock);
					}
					activeJ1939Device = null;
					ActiveDevice = calibrationECM;
				}
			}
			else if (Network.Modules.Contains(currentDevice))
			{
				activeDevice = null;
				ActiveJ1939Device = Network.Modules[currentDevice] as IPublicDataSource;
			}
		}
		catch (NoDevicesAvailableException)
		{
			EventLogger.Error("Unlock", "Unable to connect to any of the device.");
		}
		catch (NoDevicesDetectedException e)
		{
			EventLogger.Error("Unlock", "No Device Detected", e);
		}
		catch (NoDevicesConnectedException)
		{
			EventLogger.Error("Unlock", "Detected " + network.Modules.Count + " Devices. Unable to connect to any of the devices.");
		}
		catch (NoDevicesInitializedException)
		{
			EventLogger.Error("Unlock", "An error occured while connecting to device(s) in the network.");
		}
		catch (NotSupportedProductException ex4)
		{
			EventLogger.Error("Unlock", ex4.Message);
		}
		catch (CalibrationExceptions calibrationExceptions)
		{
			Trace.WriteLine("Unable to create the calibration" + calibrationExceptions.Message);
			EventLogger.Error("Unlock", "An Error Occur while creating the Calibration", calibrationExceptions);
		}
	}

	private void ConfigureNetwork(IDeviceInformation deviceInfo)
	{
		if (deviceInfo.EcmID == "XX")
		{
			network.GTISLevel = GTISVersion.GTIS45;
			deviceInfo.ConfigFile = GTIS45ConfigFile;
			network.SelectedConfigFilename = GTIS45ConfigFile;
		}
		else
		{
			network.GTISLevel = GTISVersion.GTIS38;
			network.SelectedConfigFilename = GTIS38ConfigFile;
			deviceInfo.ConfigFile = GTIS38ConfigFile;
		}
	}

	private void RaiseDeviceInfoChanged(bool connected)
	{
		if (this.DeviceInfoChanged == null)
		{
			return;
		}
		DeviceInfoChangedEventArgs e = new DeviceInfoChangedEventArgs();
		if (connected)
		{
			if (ActiveDevice != null)
			{
				e.DeviceAddress = ActiveDevice.DeviceInfo.Address.ToString("X");
				e.RunLocation = ActiveDevice.DeviceInfo.RunLocation;
				e.SecurityState = SecurityState;
				e.SerialNumber = ActiveDevice.DeviceInfo.SerialNumber;
				e.PartNumber = ActiveDevice.DeviceInfo.PartNumber;
				e.FirmwareRevision = GetFirmWareVersion(ActiveDevice.DatalinkDeviceInfo);
				e.Adapter = ActiveDevice.Adapter;
				e.ModuleType = GetModuleType();
				if (e.RunLocation != RunLocationType.RomBoot)
				{
					e.ProductID = ActiveDevice.DeviceInfo.ProductId;
					e.CalibrationVersion = GetCalibrationVersion();
				}
				else
				{
					EventLogger.Info("Unlock", resourceManager.GetString(MessageIds.UnableToReadProductID.ToString()));
					EventLogger.Info("Unlock", resourceManager.GetString(MessageIds.UnableToReadCalibrationVersion.ToString()));
				}
				try
				{
					e.ECMStatus = ECMStatus;
				}
				catch (UnableToReadECMStatusException e2)
				{
					EventLogger.Error("Unlock", resourceManager.GetString(MessageIds.UnableToReadECMStatus.ToString()), e2);
				}
				EventLogger.Info("Unlock", resourceManager.GetString(MessageIds.DeviceAddressChanged.ToString()));
			}
			else if (ActiveJ1939Device != null)
			{
				e.DeviceAddress = ActiveJ1939Device.SourceAddress.DisplayId;
				e.RunLocation = RunLocationType.Undefined;
				e.SecurityState = SecurityStatus.NotApplicable;
				e.SerialNumber = "NA";
				e.PartNumber = "NA";
				e.FirmwareRevision = GetFirmWareVersion(ActiveJ1939Device.DatalinkDeviceInfo);
				e.Adapter = ActiveJ1939Device.Adapter;
				e.ModuleType = "J1939 Device";
				e.ProductID = "NA";
				e.CalibrationVersion = "NA";
				e.ECMStatus = ECMState.Unknown;
				EventLogger.Info("Unlock", resourceManager.GetString(MessageIds.DeviceAddressChanged.ToString()));
			}
		}
		else
		{
			e.Connected = false;
		}
		this.DeviceInfoChanged(this, e);
	}

	private string GetFirmWareVersion(string deviceInfo)
	{
		//IL_0006: Unknown result type (might be due to invalid IL or missing references)
		//IL_000c: Expected O, but got Unknown
		string empty = string.Empty;
		XmlDocument val = new XmlDocument();
		val.LoadXml(deviceInfo);
		XmlNode val2 = ((XmlNode)val).SelectSingleNode("//DPAfirmwareId");
		return val2.InnerXml;
	}

	private string GetCalibrationVersion()
	{
		string text = string.Empty;
		try
		{
			if (ActiveDevice.DeviceInfo.EcmID == "XX")
			{
				string text2 = int.Parse(ActiveDevice.DeviceInfo.CalibrationVersion).ToString("X");
				text2 = text2.PadLeft(8, '0');
				int num = 0;
				for (int i = 2; i <= text2.Length + 1; i += 2)
				{
					num = int.Parse(text2.Substring(text2.Length - i, 2), NumberStyles.AllowHexSpecifier);
					text = num + "." + text;
				}
			}
			else
			{
				text = int.Parse(ActiveDevice.DeviceInfo.CalibrationVersion).ToString("X");
			}
		}
		catch
		{
		}
		return text;
	}

	private string GetModuleType()
	{
		string result = "UNKNOWN";
		string empty = string.Empty;
		try
		{
			empty = ((!(ActiveDevice.DeviceInfo.EcmID == "XX")) ? ActiveDevice.DeviceInfo.ProductId : ActiveDevice.ProductID);
			string[] array = empty.Split(new char[1] { ',' });
			if (array.Length > 0)
			{
				IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
				result = productInformationService.GetProductInformation(array[0], ProductInformationType.HardwareName);
			}
		}
		catch
		{
		}
		return result;
	}

	private void RaiseDeviceAddressListChanged()
	{
		if (this.DeviceAddressListChanged == null)
		{
			return;
		}
		StringCollection stringCollection = new StringCollection();
		if (deviceDetected)
		{
			foreach (object key in network.Modules.Keys)
			{
				stringCollection.Add(key.ToString());
			}
		}
		DeviceAddressListChangedEventArgs args = new DeviceAddressListChangedEventArgs(stringCollection);
		this.DeviceAddressListChanged(this, args);
	}

	private void RaiseECMStatusChanged(ECMStatusChangedEventArgs e)
	{
		if (this.ECMStatusChangedEvent != null)
		{
			this.ECMStatusChangedEvent(this, e);
		}
	}

	private void RaiseSecurityStatusChanged()
	{
		if (this.SecurityStatusChangedEvent != null)
		{
			EngrSecurityKeyChangedEventArgs e = new EngrSecurityKeyChangedEventArgs(securityState);
			this.SecurityStatusChangedEvent(this, e);
		}
	}

	private void DetectDevices()
	{
		new StringCollection();
		IDatalinkSessionService datalinkSessionService = (IDatalinkSessionService)ServiceManager.Services.GetService(typeof(IDatalinkSessionService));
		datalinkSessionService.SetSessionContext(GTIS45ToolFamily.Engineering_Unlock);
		Network.SessionConfiguration = datalinkSessionService.GetSessionSetting().InnerXml;
		Network.AutoReconnect = false;
		Network.QueryRunLocation = false;
		try
		{
			deviceDetected = false;
			Network.Detect();
			deviceDetected = true;
		}
		catch (NoDevicesAvailableException)
		{
			EventLogger.Error("Unlock", "Unable to connect to any of the device.");
		}
		catch (NoDevicesDetectedException e)
		{
			EventLogger.Error("Unlock", "No Device Detected", e);
		}
		catch (NoDevicesConnectedException)
		{
			EventLogger.Error("Unlock", "Detected " + network.Modules.Count + " Devices. Unable to connect to any of the devices.");
		}
		catch (NotSupportedProductException ex3)
		{
			EventLogger.Error("Unlock", ex3.Message);
		}
		catch (NoDevicesInitializedException)
		{
			EventLogger.Error("Unlock", "An error occured while connecting to device(s) in the network.");
		}
		RaiseDeviceAddressListChanged();
	}

	private void OnSecurityStatusChanged(object sender, EventArgs e)
	{
		if (this.SecurityStatusChangedEvent != null)
		{
			this.SecurityStatusChangedEvent(sender, e);
		}
	}

	private void CommandExecuting()
	{
		if (ActiveDevice.DeviceInfo.EcmID != "XX" && !ActiveDevice.DataLink.Opened)
		{
			ActiveDevice.DataLink.Open();
		}
		if (ActiveDevice.DeviceInfo.RunLocation != RunLocationType.RomBoot && AutoStopBroadcast)
		{
			ActiveDevice.Execute(CommandType.StopBroadcast);
		}
	}

	private string GetResourceConfigFileName(string resourceName)
	{
		string text = string.Empty;
		Stream stream = null;
		stream = Assembly.GetExecutingAssembly().GetManifestResourceStream(resourceName);
		if (stream != null || stream.Length != 0)
		{
			text = Path.GetTempFileName();
			Stream stream2 = File.Create(text);
			byte[] buffer = new byte[stream.Length];
			stream2.Write(buffer, 0, stream.Read(buffer, 0, (int)stream.Length));
			stream.Close();
			stream2.Close();
		}
		else
		{
			Trace.WriteLine("Unlock", "Unable to load config from resource");
		}
		return text;
	}

	private bool IsECMStatusSupported()
	{
		bool result = true;
		string moduleType = GetModuleType();
		if (moduleType.Contains("ECMB"))
		{
			result = false;
		}
		return result;
	}

	private bool IsSecuritySupported()
	{
		bool result = true;
		string moduleType = GetModuleType();
		string[] securityNotSupportedModules = SecurityNotSupportedModules;
		foreach (string value in securityNotSupportedModules)
		{
			if (moduleType.Contains(value))
			{
				result = false;
				break;
			}
		}
		return result;
	}

	private bool IsProductSupported(string productId)
	{
		bool result = false;
		try
		{
			ICIProductMaster iCIProductMaster = new ProductData();
			StringCollection supportedProducts = iCIProductMaster.SupportedProducts;
			result = supportedProducts.Contains(productId);
		}
		catch (Exception)
		{
		}
		return result;
	}

	private void SetSelectedProduct(string ecmId)
	{
		IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		string value = "ABC";
		if (ecmId != "XX")
		{
			try
			{
				IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
				string supportedProductIdFromECMId = productInformationService.GetSupportedProductIdFromECMId(ecmId);
				if (supportedProductIdFromECMId != string.Empty)
				{
					value = supportedProductIdFromECMId;
				}
			}
			catch (Exception)
			{
			}
		}
		appConfigService.SetAppSetting(ApplicationSettings.LastProduct, value);
	}
}
public class UnlockView : Form
{
	private delegate void OnDeviceInfoChangedDelegate(object sender, DeviceInfoChangedEventArgs args);

	private delegate void InvokeOnDeviceAddressListChanged(object sender, DeviceAddressListChangedEventArgs args);

	private delegate void InvokeOnEventLogMessageFired(EventTypes evenType, string title, string eventMessage, string detailedDescription);

	private enum AdapterType
	{
		RP1210a
	}

	private const string ResourceFileName = "Cummins.Unlock.strings";

	private const string CheckBoxAppSetting = "UnlockSecurityMessageCheck";

	private TabControl tabControl1;

	private TabPage tabPage1;

	private TabPage tabPage2;

	private TabPage tabPage3;

	private GroupBox gbUnlockInfo;

	private Label laSecurityStatus;

	private Label laCalVersionValue;

	private Label label2;

	private Label laModuleType;

	private Label laProductIDValue;

	private Label laProductID;

	private Label laModuleStatus;

	private Label laModuleTypeValue;

	private Label laRunLocationValue;

	private Label laCalibrationSecurity;

	private StatusBar statusBar1;

	private StatusBarPanel statusBarPanel1;

	private Button btnSwitchCalStatus;

	private Button btnSwitchModuleStatus;

	private Label label1;

	private Button btnConnect;

	private ComboBox cmbDeviceAddress;

	private Button btnDisplayCurrentStatus;

	private TextBox tbLog;

	private Label laSerialNumberValue;

	private Label laPartNumberValue;

	private Label laSerialNumber;

	private Label label6;

	private ComboBox cmbModuleStatus;

	private Container components;

	private Label laModuleStatusValue;

	private ConnectionProperties connectionProperties1;

	private Label laCalibrationVersion;

	private CheckBox autoStopBroadcastBox;

	private StatusBarPanel statusBarPanel2;

	private IAppConfigService appConfigService;

	private ResourceManager resourceManager;

	private bool shouldDisplayFirstAddress;

	public event CurrentDeviceChangedEventHandler CurrentDeviceChangedEvent;

	public event FindAllDeviceEventHandler FindAllDevicesEvent;

	public event ECMStatusChangedEventHandler ECMStateChangedEvent;

	public event EngrSecurityKeyChangedEventHandler SecurityStateChangedEvent;

	public event AutoStopBroadcastChangedEventHandler AutoStopBroadcastChangedEvent;

	public UnlockView(UnlockController controller, UnlockModel model)
	{
		EventLogController.Instance.EventLogErrorMessageFired -= EventLogController.Instance.EvtLogView.AddEventLogErrorMessage;
		SessionService.CurrentSession.EventLog.EventLogMessageFired -= EventLogController.Instance.EvtLogView.AddEventLogMessage;
		connectionProperties1 = new ConnectionProperties();
		appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		SessionService.CurrentSession.EventLog.EventLogMessageFired += OnEventLogMessageFired;
		LoadSettings();
		InitializeComponent();
		((Control)tabPage1).Controls.Add((Control)(object)connectionProperties1);
		cmbModuleStatus.DropDownStyle = (ComboBoxStyle)2;
		((Form)this).Load += OnUnlockViewLoad;
		cmbModuleStatus.SelectedIndexChanged += OnCmbModuleStatusItemSelected;
		model.SecurityStatusChangedEvent += OnSecurityStatusChanged;
		model.ECMStatusChangedEvent += OnECMStatusChanged;
		model.DeviceAddressListChanged += OnDeviceAddressListChanged;
		model.DeviceInfoChanged += OnDeviceInfoChanged;
		SecurityStateChangedEvent += controller.OnSecurityStateChanged;
		CurrentDeviceChangedEvent += controller.OnDeviceAddressChanged;
		ECMStateChangedEvent += controller.OnECMStatusChanged;
		FindAllDevicesEvent += controller.OnFindAllDeviceAddress;
		((Form)this).Closing += controller.OnViewExiting;
		AutoStopBroadcastChangedEvent += controller.OnAutoStopBroadcastChanged;
		resourceManager = new ResourceManager("Cummins.Unlock.strings", Assembly.GetExecutingAssembly());
		connectionProperties1.ConnectionSettingsChangedEvent += OnConnectionSettingsChanged;
		ISecurityService securityService = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
		Button obj = btnSwitchModuleStatus;
		bool enabled = (((Control)btnSwitchCalStatus).Enabled = securityService.IsFeatureSelected(SelectableFeatures.ToggleSecurityKey.ToString()));
		((Control)obj).Enabled = enabled;
		try
		{
			autoStopBroadcastBox.Checked = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoStopBroadCastChecked));
		}
		catch
		{
		}
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		((Form)this).Dispose(disposing);
	}

	private void InitializeComponent()
	{
		//IL_0011: Unknown result type (might be due to invalid IL or missing references)
		//IL_001b: Expected O, but got Unknown
		//IL_001c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0026: Expected O, but got Unknown
		//IL_0027: Unknown result type (might be due to invalid IL or missing references)
		//IL_0031: Expected O, but got Unknown
		//IL_0032: Unknown result type (might be due to invalid IL or missing references)
		//IL_003c: Expected O, but got Unknown
		//IL_003d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0047: Expected O, but got Unknown
		//IL_0048: Unknown result type (might be due to invalid IL or missing references)
		//IL_0052: Expected O, but got Unknown
		//IL_0053: Unknown result type (might be due to invalid IL or missing references)
		//IL_005d: Expected O, but got Unknown
		//IL_005e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0068: Expected O, but got Unknown
		//IL_0069: Unknown result type (might be due to invalid IL or missing references)
		//IL_0073: Expected O, but got Unknown
		//IL_0074: Unknown result type (might be due to invalid IL or missing references)
		//IL_007e: Expected O, but got Unknown
		//IL_007f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0089: Expected O, but got Unknown
		//IL_008a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0094: Expected O, but got Unknown
		//IL_0095: Unknown result type (might be due to invalid IL or missing references)
		//IL_009f: Expected O, but got Unknown
		//IL_00a0: Unknown result type (might be due to invalid IL or missing references)
		//IL_00aa: Expected O, but got Unknown
		//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
		//IL_00b5: Expected O, but got Unknown
		//IL_00b6: Unknown result type (might be due to invalid IL or missing references)
		//IL_00c0: Expected O, but got Unknown
		//IL_00c1: Unknown result type (might be due to invalid IL or missing references)
		//IL_00cb: Expected O, but got Unknown
		//IL_00cc: Unknown result type (might be due to invalid IL or missing references)
		//IL_00d6: Expected O, but got Unknown
		//IL_00d7: Unknown result type (might be due to invalid IL or missing references)
		//IL_00e1: Expected O, but got Unknown
		//IL_00e2: Unknown result type (might be due to invalid IL or missing references)
		//IL_00ec: Expected O, but got Unknown
		//IL_00ed: Unknown result type (might be due to invalid IL or missing references)
		//IL_00f7: Expected O, but got Unknown
		//IL_00f8: Unknown result type (might be due to invalid IL or missing references)
		//IL_0102: Expected O, but got Unknown
		//IL_0103: Unknown result type (might be due to invalid IL or missing references)
		//IL_010d: Expected O, but got Unknown
		//IL_010e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0118: Expected O, but got Unknown
		//IL_0119: Unknown result type (might be due to invalid IL or missing references)
		//IL_0123: Expected O, but got Unknown
		//IL_0124: Unknown result type (might be due to invalid IL or missing references)
		//IL_012e: Expected O, but got Unknown
		//IL_012f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0139: Expected O, but got Unknown
		//IL_013a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0144: Expected O, but got Unknown
		//IL_0145: Unknown result type (might be due to invalid IL or missing references)
		//IL_014f: Expected O, but got Unknown
		//IL_0150: Unknown result type (might be due to invalid IL or missing references)
		//IL_015a: Expected O, but got Unknown
		//IL_015b: Unknown result type (might be due to invalid IL or missing references)
		//IL_0165: Expected O, but got Unknown
		//IL_0166: Unknown result type (might be due to invalid IL or missing references)
		//IL_0170: Expected O, but got Unknown
		//IL_0171: Unknown result type (might be due to invalid IL or missing references)
		//IL_017b: Expected O, but got Unknown
		//IL_03c4: Unknown result type (might be due to invalid IL or missing references)
		//IL_03ce: Expected O, but got Unknown
		//IL_04c4: Unknown result type (might be due to invalid IL or missing references)
		//IL_04ce: Expected O, but got Unknown
		//IL_0d90: Unknown result type (might be due to invalid IL or missing references)
		//IL_0d9a: Expected O, but got Unknown
		//IL_0e1c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0e26: Expected O, but got Unknown
		//IL_1162: Unknown result type (might be due to invalid IL or missing references)
		//IL_116c: Expected O, but got Unknown
		//IL_11f1: Unknown result type (might be due to invalid IL or missing references)
		//IL_11fb: Expected O, but got Unknown
		ResourceManager resourceManager = new ResourceManager(typeof(UnlockView));
		tabControl1 = new TabControl();
		tabPage2 = new TabPage();
		label1 = new Label();
		btnConnect = new Button();
		cmbDeviceAddress = new ComboBox();
		btnDisplayCurrentStatus = new Button();
		gbUnlockInfo = new GroupBox();
		laModuleStatusValue = new Label();
		cmbModuleStatus = new ComboBox();
		laSerialNumberValue = new Label();
		laPartNumberValue = new Label();
		laSerialNumber = new Label();
		label6 = new Label();
		laRunLocationValue = new Label();
		laCalibrationSecurity = new Label();
		laSecurityStatus = new Label();
		laCalVersionValue = new Label();
		label2 = new Label();
		laModuleType = new Label();
		laCalibrationVersion = new Label();
		laProductIDValue = new Label();
		laProductID = new Label();
		laModuleStatus = new Label();
		laModuleTypeValue = new Label();
		btnSwitchModuleStatus = new Button();
		btnSwitchCalStatus = new Button();
		tabPage1 = new TabPage();
		tabPage3 = new TabPage();
		tbLog = new TextBox();
		statusBar1 = new StatusBar();
		statusBarPanel1 = new StatusBarPanel();
		statusBarPanel2 = new StatusBarPanel();
		autoStopBroadcastBox = new CheckBox();
		((Control)tabControl1).SuspendLayout();
		((Control)tabPage2).SuspendLayout();
		((Control)gbUnlockInfo).SuspendLayout();
		((Control)tabPage1).SuspendLayout();
		((Control)tabPage3).SuspendLayout();
		((ISupportInitialize)statusBarPanel1).BeginInit();
		((ISupportInitialize)statusBarPanel2).BeginInit();
		((Control)this).SuspendLayout();
		((Control)tabControl1).Controls.Add((Control)(object)tabPage2);
		((Control)tabControl1).Controls.Add((Control)(object)tabPage1);
		((Control)tabControl1).Controls.Add((Control)(object)tabPage3);
		((Control)tabControl1).Dock = (DockStyle)1;
		((Control)tabControl1).Location = new Point(0, 0);
		((Control)tabControl1).Name = "tabControl1";
		tabControl1.SelectedIndex = 0;
		((Control)tabControl1).Size = new Size(560, 232);
		((Control)tabControl1).TabIndex = 0;
		((Control)tabPage2).Controls.Add((Control)(object)autoStopBroadcastBox);
		((Control)tabPage2).Controls.Add((Control)(object)label1);
		((Control)tabPage2).Controls.Add((Control)(object)btnConnect);
		((Control)tabPage2).Controls.Add((Control)(object)cmbDeviceAddress);
		((Control)tabPage2).Controls.Add((Control)(object)btnDisplayCurrentStatus);
		((Control)tabPage2).Controls.Add((Control)(object)gbUnlockInfo);
		tabPage2.Location = new Point(4, 22);
		((Control)tabPage2).Name = "tabPage2";
		((Control)tabPage2).Size = new Size(534, 206);
		tabPage2.TabIndex = 1;
		((Control)tabPage2).Text = "Unlock";
		((Control)label1).AutoSize = true;
		((Control)label1).Location = new Point(136, 13);
		((Control)label1).Name = "label1";
		((Control)label1).Size = new Size(87, 16);
		((Control)label1).TabIndex = 53;
		((Control)label1).Text = "Device Address:";
		((Control)btnConnect).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)btnConnect).Location = new Point(8, 9);
		((Control)btnConnect).Name = "btnConnect";
		((Control)btnConnect).Size = new Size(104, 23);
		((Control)btnConnect).TabIndex = 52;
		((Control)btnConnect).Text = "Find Devices";
		((Control)btnConnect).Click += btnConnect_Click;
		cmbDeviceAddress.ItemHeight = 13;
		((Control)cmbDeviceAddress).Location = new Point(224, 10);
		cmbDeviceAddress.MaxLength = 4;
		((Control)cmbDeviceAddress).Name = "cmbDeviceAddress";
		((Control)cmbDeviceAddress).Size = new Size(72, 21);
		((Control)cmbDeviceAddress).TabIndex = 54;
		cmbDeviceAddress.SelectedIndexChanged += cmbDeviceAddress_SelectedIndexChanged;
		((Control)btnDisplayCurrentStatus).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)btnDisplayCurrentStatus).Location = new Point(312, 9);
		((Control)btnDisplayCurrentStatus).Name = "btnDisplayCurrentStatus";
		((Control)btnDisplayCurrentStatus).Size = new Size(136, 23);
		((Control)btnDisplayCurrentStatus).TabIndex = 50;
		((Control)btnDisplayCurrentStatus).Text = "Display Current Status";
		((Control)btnDisplayCurrentStatus).Click += btnDisplayCurrentStatus_Click;
		((Control)gbUnlockInfo).Controls.Add((Control)(object)laModuleStatusValue);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)cmbModuleStatus);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)laSerialNumberValue);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)laPartNumberValue);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)laSerialNumber);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)label6);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)laRunLocationValue);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)laCalibrationSecurity);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)laSecurityStatus);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)laCalVersionValue);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)label2);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)laModuleType);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)laCalibrationVersion);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)laProductIDValue);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)laProductID);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)laModuleStatus);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)laModuleTypeValue);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)btnSwitchModuleStatus);
		((Control)gbUnlockInfo).Controls.Add((Control)(object)btnSwitchCalStatus);
		((Control)gbUnlockInfo).Location = new Point(0, 56);
		((Control)gbUnlockInfo).Name = "gbUnlockInfo";
		((Control)gbUnlockInfo).Size = new Size(528, 145);
		((Control)gbUnlockInfo).TabIndex = 47;
		gbUnlockInfo.TabStop = false;
		((Control)laModuleStatusValue).Location = new Point(318, 48);
		((Control)laModuleStatusValue).Name = "laModuleStatusValue";
		((Control)laModuleStatusValue).Size = new Size(56, 16);
		((Control)laModuleStatusValue).TabIndex = 53;
		((Control)laModuleStatusValue).Text = "NONE";
		cmbModuleStatus.ItemHeight = 13;
		cmbModuleStatus.Items.AddRange(new object[4] { "600D", "1D0A", "5EED", "2B16" });
		((Control)cmbModuleStatus).Location = new Point(392, 48);
		cmbModuleStatus.MaxLength = 4;
		((Control)cmbModuleStatus).Name = "cmbModuleStatus";
		((Control)cmbModuleStatus).Size = new Size(59, 21);
		((Control)cmbModuleStatus).TabIndex = 27;
		((Control)laSerialNumberValue).Location = new Point(318, 96);
		((Control)laSerialNumberValue).Name = "laSerialNumberValue";
		((Control)laSerialNumberValue).Size = new Size(74, 16);
		((Control)laSerialNumberValue).TabIndex = 26;
		((Control)laSerialNumberValue).Text = "SerialNumber";
		((Control)laPartNumberValue).Location = new Point(112, 96);
		((Control)laPartNumberValue).Name = "laPartNumberValue";
		((Control)laPartNumberValue).Size = new Size(74, 16);
		((Control)laPartNumberValue).TabIndex = 24;
		((Control)laPartNumberValue).Text = "PartNumber";
		((Control)laSerialNumber).AutoSize = true;
		((Control)laSerialNumber).Location = new Point(208, 96);
		((Control)laSerialNumber).Name = "laSerialNumber";
		((Control)laSerialNumber).Size = new Size(80, 16);
		((Control)laSerialNumber).TabIndex = 25;
		((Control)laSerialNumber).Text = "Serial Number:";
		((Control)label6).AutoSize = true;
		((Control)label6).Location = new Point(8, 96);
		((Control)label6).Name = "label6";
		((Control)label6).Size = new Size(71, 16);
		((Control)label6).TabIndex = 23;
		((Control)label6).Text = "Part Number:";
		((Control)laRunLocationValue).Location = new Point(318, 72);
		((Control)laRunLocationValue).Name = "laRunLocationValue";
		((Control)laRunLocationValue).Size = new Size(74, 16);
		((Control)laRunLocationValue).TabIndex = 22;
		((Control)laRunLocationValue).Text = "NONE";
		((Control)laCalibrationSecurity).Location = new Point(318, 20);
		((Control)laCalibrationSecurity).Name = "laCalibrationSecurity";
		((Control)laCalibrationSecurity).Size = new Size(58, 16);
		((Control)laCalibrationSecurity).TabIndex = 20;
		((Control)laCalibrationSecurity).Text = "NONE";
		((Control)laSecurityStatus).AutoSize = true;
		((Control)laSecurityStatus).Location = new Point(208, 20);
		((Control)laSecurityStatus).Name = "laSecurityStatus";
		((Control)laSecurityStatus).Size = new Size(106, 16);
		((Control)laSecurityStatus).TabIndex = 11;
		((Control)laSecurityStatus).Text = "Calibration Security:";
		((Control)laCalVersionValue).Location = new Point(112, 72);
		((Control)laCalVersionValue).Name = "laCalVersionValue";
		((Control)laCalVersionValue).Size = new Size(74, 16);
		((Control)laCalVersionValue).TabIndex = 10;
		((Control)laCalVersionValue).Text = "NONE";
		((Control)label2).AutoSize = true;
		((Control)label2).Location = new Point(208, 72);
		((Control)label2).Name = "label2";
		((Control)label2).Size = new Size(74, 16);
		((Control)label2).TabIndex = 17;
		((Control)label2).Text = "Run Location:";
		((Control)laModuleType).AutoSize = true;
		((Control)laModuleType).Location = new Point(8, 24);
		((Control)laModuleType).Name = "laModuleType";
		((Control)laModuleType).Size = new Size(73, 16);
		((Control)laModuleType).TabIndex = 5;
		((Control)laModuleType).Text = "Module Type:";
		((Control)laCalibrationVersion).AutoSize = true;
		((Control)laCalibrationVersion).Location = new Point(8, 72);
		((Control)laCalibrationVersion).Name = "laCalibrationVersion";
		((Control)laCalibrationVersion).TabIndex = 9;
		((Control)laCalibrationVersion).Text = "Calibration Version";
		((Control)laProductIDValue).Location = new Point(112, 48);
		((Control)laProductIDValue).Name = "laProductIDValue";
		((Control)laProductIDValue).Size = new Size(74, 16);
		((Control)laProductIDValue).TabIndex = 8;
		((Control)laProductIDValue).Text = "NONE";
		((Control)laProductID).AutoSize = true;
		((Control)laProductID).Location = new Point(8, 48);
		((Control)laProductID).Name = "laProductID";
		((Control)laProductID).Size = new Size(61, 16);
		((Control)laProductID).TabIndex = 7;
		((Control)laProductID).Text = "Product ID:";
		((Control)laModuleStatus).AutoSize = true;
		((Control)laModuleStatus).Location = new Point(208, 48);
		((Control)laModuleStatus).Name = "laModuleStatus";
		((Control)laModuleStatus).Size = new Size(80, 16);
		((Control)laModuleStatus).TabIndex = 14;
		((Control)laModuleStatus).Text = "Module Status:";
		((Control)laModuleTypeValue).Location = new Point(112, 24);
		((Control)laModuleTypeValue).Name = "laModuleTypeValue";
		((Control)laModuleTypeValue).Size = new Size(82, 16);
		((Control)laModuleTypeValue).TabIndex = 6;
		((Control)laModuleTypeValue).Text = "NONE";
		((Control)btnSwitchModuleStatus).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)btnSwitchModuleStatus).Location = new Point(456, 48);
		((Control)btnSwitchModuleStatus).Name = "btnSwitchModuleStatus";
		((Control)btnSwitchModuleStatus).Size = new Size(56, 20);
		((Control)btnSwitchModuleStatus).TabIndex = 51;
		((Control)btnSwitchModuleStatus).Text = "Apply";
		((Control)btnSwitchModuleStatus).Click += btnSwitchModuleStatus_Click;
		((Control)btnSwitchCalStatus).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)btnSwitchCalStatus).Location = new Point(392, 16);
		((Control)btnSwitchCalStatus).Name = "btnSwitchCalStatus";
		((Control)btnSwitchCalStatus).Size = new Size(56, 23);
		((Control)btnSwitchCalStatus).TabIndex = 49;
		((Control)btnSwitchCalStatus).Text = "Switch";
		((Control)btnSwitchCalStatus).Click += btnSwitchCalStatus_Click;
		tabPage1.Location = new Point(4, 22);
		((Control)tabPage1).Name = "tabPage1";
		((Control)tabPage1).Size = new Size(550, 206);
		tabPage1.TabIndex = 0;
		((Control)tabPage1).Text = "Datalink";
		((Control)tabPage3).Controls.Add((Control)(object)tbLog);
		tabPage3.Location = new Point(4, 22);
		((Control)tabPage3).Name = "tabPage3";
		((Control)tabPage3).Size = new Size(534, 206);
		tabPage3.TabIndex = 2;
		((Control)tabPage3).Text = "Log";
		((Control)tbLog).Dock = (DockStyle)5;
		((Control)tbLog).Location = new Point(0, 0);
		((TextBoxBase)tbLog).Multiline = true;
		((Control)tbLog).Name = "tbLog";
		tbLog.ScrollBars = (ScrollBars)2;
		((Control)tbLog).Size = new Size(534, 206);
		((Control)tbLog).TabIndex = 0;
		((Control)tbLog).Text = "Detailed Log";
		((Control)statusBar1).Location = new Point(0, 255);
		((Control)statusBar1).Name = "statusBar1";
		statusBar1.Panels.AddRange((StatusBarPanel[])(object)new StatusBarPanel[2] { statusBarPanel1, statusBarPanel2 });
		statusBar1.ShowPanels = true;
		((Control)statusBar1).Size = new Size(560, 22);
		((Control)statusBar1).TabIndex = 1;
		statusBarPanel1.Text = "Unlock Status, Adapter Information";
		statusBarPanel1.Width = 270;
		statusBarPanel2.Text = "Device Information";
		statusBarPanel2.Width = 270;
		((Control)autoStopBroadcastBox).Location = new Point(312, 40);
		((Control)autoStopBroadcastBox).Name = "autoStopBroadcastBox";
		((Control)autoStopBroadcastBox).Size = new Size(144, 16);
		((Control)autoStopBroadcastBox).TabIndex = 55;
		((Control)autoStopBroadcastBox).Text = "AutoStop Broadcast";
		autoStopBroadcastBox.CheckedChanged += OnAutoStopBroadcastBoxCheckedChanged;
		((Form)this).AutoScaleBaseSize = new Size(5, 13);
		((Form)this).ClientSize = new Size(560, 277);
		((Control)this).Controls.Add((Control)(object)statusBar1);
		((Control)this).Controls.Add((Control)(object)tabControl1);
		((Form)this).FormBorderStyle = (FormBorderStyle)2;
		((Form)this).Icon = (Icon)resourceManager.GetObject("$this.Icon");
		((Form)this).MaximizeBox = false;
		((Control)this).Name = "UnlockView";
		((Form)this).StartPosition = (FormStartPosition)1;
		((Control)this).Text = "Calterm III Unlock";
		((Control)tabControl1).ResumeLayout(false);
		((Control)tabPage2).ResumeLayout(false);
		((Control)gbUnlockInfo).ResumeLayout(false);
		((Control)tabPage1).ResumeLayout(false);
		((Control)tabPage3).ResumeLayout(false);
		((ISupportInitialize)statusBarPanel1).EndInit();
		((ISupportInitialize)statusBarPanel2).EndInit();
		((Control)this).ResumeLayout(false);
		((Form)this).FormClosing += new FormClosingEventHandler(UnlockView_Closing);
	}

	private void UnlockView_Closing(object sender, FormClosingEventArgs e)
	{
		EventLogController.Instance.EventLogErrorMessageFired += EventLogController.Instance.EvtLogView.AddEventLogErrorMessage;
		SessionService.CurrentSession.EventLog.EventLogMessageFired += EventLogController.Instance.EvtLogView.AddEventLogMessage;
	}

	private void btnConnect_Click(object sender, EventArgs e)
	{
		RaiseFindAllDevicesEvent();
		ChangeApplyButtonStatus();
	}

	private void ChangeApplyButtonStatus()
	{
		if (((Control)laModuleStatusValue).Text != "NONE" && ((ListControl)cmbModuleStatus).SelectedIndex > -1)
		{
			((Control)btnSwitchModuleStatus).Enabled = true;
		}
		else
		{
			((Control)btnSwitchModuleStatus).Enabled = false;
		}
	}

	private void btnSwitchModuleStatus_Click(object sender, EventArgs e)
	{
		//IL_008b: Unknown result type (might be due to invalid IL or missing references)
		try
		{
			RaiseECMStateChangedEvent(((Control)cmbModuleStatus).Text);
		}
		catch (ECMStatusNotSupportedException ex)
		{
			string text = resourceManager.GetString(MessageIds.CM4XX.ToString());
			text += Environment.NewLine;
			text += resourceManager.GetString(MessageIds.ECMB.ToString());
			string message = string.Format(resourceManager.GetString(MessageIds.OperationNotSupportedByECM.ToString()), "Module Status", ex.ModuleType);
			MessageDialogComponent.CaltermMessageDialog.Show((IWin32Window)(object)this, message, text, MessageDialogButtons.OK, MessageDialogIcon.Error);
			EventLogger.Error("Unlock", message, text);
		}
		catch (Exception)
		{
			ClearView();
			statusBarPanel1.Text = resourceManager.GetString(MessageIds.UnableToConnect.ToString());
			statusBarPanel2.Text = resourceManager.GetString(MessageIds.CheckLogTab.ToString());
		}
	}

	private void btnDisplayCurrentStatus_Click(object sender, EventArgs e)
	{
		if (!((Control)cmbDeviceAddress).Text.Trim().Equals(""))
		{
			RaiseCurrentDeviceChangedEvent(((Control)cmbDeviceAddress).Text);
			shouldDisplayFirstAddress = false;
		}
		else
		{
			RaiseFindAllDevicesEvent();
			shouldDisplayFirstAddress = true;
		}
	}

	private void btnSwitchCalStatus_Click(object sender, EventArgs e)
	{
		//IL_0080: Unknown result type (might be due to invalid IL or missing references)
		try
		{
			RaiseSecuityStateChangedEvent();
		}
		catch (SecurityNotSupportedException ex)
		{
			string text = resourceManager.GetString(MessageIds.CM4XX.ToString());
			text += Environment.NewLine;
			text += resourceManager.GetString(MessageIds.ECMB.ToString());
			string message = string.Format(resourceManager.GetString(MessageIds.OperationNotSupportedByECM.ToString()), "Calibration Security", ex.ModuleType);
			MessageDialogComponent.CaltermMessageDialog.Show((IWin32Window)(object)this, message, text, MessageDialogButtons.OK, MessageDialogIcon.Error);
			EventLogger.Error("Unlock", message, text);
		}
		catch (UnableToToggleSecurity)
		{
			ClearView();
			statusBarPanel1.Text = resourceManager.GetString(MessageIds.UnableToConnect.ToString());
			statusBarPanel2.Text = resourceManager.GetString(MessageIds.CheckLogTab.ToString());
		}
	}

	public void OnSecurityStatusChanged(object sender, EventArgs args)
	{
		//IL_006a: Unknown result type (might be due to invalid IL or missing references)
		((Control)laCalibrationSecurity).Text = (args as EngrSecurityKeyChangedEventArgs).SecurityState.ToString();
		if (!bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.UnlockSecurityMessageCheck)) && ((Control)laRunLocationValue).Text == "RomBoot")
		{
			MessageDialogComponent.CaltermMessageDialog.Show(resourceManager.GetString(MessageIds.SecurityStatusChangedRomBoot.ToString()), MessageDialogButtons.OK, MessageDialogIcon.Warning);
		}
	}

	public void OnECMStatusChanged(object sender, ECMStatusChangedEventArgs args)
	{
		((Control)laModuleStatusValue).Text = ((int)args.PresentECMState).ToString("X");
	}

	public void OnDeviceInfoChanged(object sender, DeviceInfoChangedEventArgs args)
	{
		if (((Control)laRunLocationValue).InvokeRequired)
		{
			OnDeviceInfoChangedDelegate onDeviceInfoChangedDelegate = OnDeviceInfoChanged;
			((Control)this).Invoke((Delegate)onDeviceInfoChangedDelegate, new object[2] { sender, args });
			return;
		}
		if (args.Connected)
		{
			((Control)laRunLocationValue).Text = args.RunLocation.ToString();
			((Control)laCalibrationSecurity).Text = args.SecurityState.ToString();
			((Control)laCalVersionValue).Text = args.CalibrationVersion;
			if (args.ECMStatus != ECMState.Unknown)
			{
				((Control)laModuleStatusValue).Text = ((int)args.ECMStatus).ToString("X");
			}
			else
			{
				((Control)laModuleStatusValue).Text = "Unknown";
			}
			((Control)laProductIDValue).Text = args.ProductID;
			((Control)laSerialNumberValue).Text = args.SerialNumber;
			((Control)laPartNumberValue).Text = args.PartNumber;
			((Control)laModuleTypeValue).Text = args.ModuleType;
			statusBarPanel1.Text = args.Adapter + " has firmware revision " + args.FirmwareRevision;
			statusBarPanel2.Text = "Information of Device Address " + args.DeviceAddress;
			((Control)gbUnlockInfo).Text = "Information of Device Address " + args.DeviceAddress;
		}
		else
		{
			ClearView();
			statusBarPanel1.Text = resourceManager.GetString(MessageIds.UnableToConnect.ToString());
			statusBarPanel2.Text = resourceManager.GetString(MessageIds.CheckLogTab.ToString());
		}
		ChangeApplyButtonStatus();
		((Control)this).Cursor = Cursors.Default;
	}

	public void OnDeviceAddressListChanged(object sender, DeviceAddressListChangedEventArgs args)
	{
		if (((Control)this).InvokeRequired)
		{
			InvokeOnDeviceAddressListChanged invokeOnDeviceAddressListChanged = OnDeviceAddressListChanged;
			((Control)this).Invoke((Delegate)invokeOnDeviceAddressListChanged, new object[2] { sender, args });
			return;
		}
		if (args.Devices.Count == 0)
		{
			statusBarPanel1.Text = resourceManager.GetString(MessageIds.UnableToConnect.ToString());
			statusBarPanel2.Text = resourceManager.GetString(MessageIds.CheckLogTab.ToString());
			shouldDisplayFirstAddress = false;
		}
		else
		{
			for (int i = 0; i < args.Devices.Count; i++)
			{
				cmbDeviceAddress.Items.Add((object)args.Devices[i]);
			}
			if (((Control)cmbDeviceAddress).Text == string.Empty)
			{
				((ListControl)cmbDeviceAddress).SelectedIndex = 0;
				if (shouldDisplayFirstAddress)
				{
					RaiseCurrentDeviceChangedEvent(((Control)cmbDeviceAddress).Text);
				}
			}
		}
		((Control)this).Cursor = Cursors.Default;
	}

	private void OnUnlockViewLoad(object sender, EventArgs e)
	{
		((Control)btnSwitchModuleStatus).Enabled = false;
	}

	private void OnCmbModuleStatusItemSelected(object sender, EventArgs e)
	{
		ChangeApplyButtonStatus();
	}

	private void RaiseFindAllDevicesEvent()
	{
		if (this.FindAllDevicesEvent != null)
		{
			cmbDeviceAddress.Items.Clear();
			((Control)cmbDeviceAddress).Text = "";
			ClearView();
			((Control)this).Cursor = Cursors.WaitCursor;
			try
			{
				SetOptions();
				this.FindAllDevicesEvent(this, EventArgs.Empty);
			}
			catch (Exception e)
			{
				statusBarPanel1.Text = resourceManager.GetString(MessageIds.UnableToConnect.ToString());
				statusBarPanel2.Text = resourceManager.GetString(MessageIds.CheckLogTab.ToString());
				EventLogger.Error("Unlock", "Unable to initialize the detection", e);
				((Control)this).Cursor = Cursors.Default;
			}
		}
	}

	private void RaiseCurrentDeviceChangedEvent(string deviceAddress)
	{
		if (this.CurrentDeviceChangedEvent != null)
		{
			ClearView();
			((Control)this).Cursor = Cursors.WaitCursor;
			CurrentDeviceChangedEventArgs e = new CurrentDeviceChangedEventArgs(deviceAddress);
			if (!cmbDeviceAddress.Items.Contains((object)deviceAddress))
			{
				e.IsManualAddress = true;
				SetOptions();
			}
			this.CurrentDeviceChangedEvent(this, e);
		}
	}

	private void RaiseSecuityStateChangedEvent()
	{
		if (this.SecurityStateChangedEvent != null)
		{
			EngrSecurityKeyChangedEventArgs e = new EngrSecurityKeyChangedEventArgs(SecurityStatus.Secured);
			this.SecurityStateChangedEvent(this, e);
		}
	}

	private void RaiseECMStateChangedEvent(string newStatus)
	{
		if (this.ECMStateChangedEvent != null)
		{
			ECMState newState = (ECMState)Enum.Parse(typeof(ECMState), int.Parse(newStatus, NumberStyles.HexNumber).ToString());
			ECMState oldState = (ECMState)Enum.Parse(typeof(ECMState), int.Parse(((Control)laModuleStatusValue).Text, NumberStyles.HexNumber).ToString());
			ECMStatusChangedEventArgs e = new ECMStatusChangedEventArgs(oldState, newState);
			this.ECMStateChangedEvent(this, e);
			EventLogger.Info("Unlock", "ECM Status Changed from " + ((int)e.PreviousEcmState).ToString("X") + " to " + ((int)e.PresentECMState).ToString("X"));
		}
	}

	private void OnEventLogMessageFired(EventTypes evenType, string title, string eventMessage, string detailedDescription)
	{
		if (((Control)tbLog).InvokeRequired)
		{
			InvokeOnEventLogMessageFired invokeOnEventLogMessageFired = OnEventLogMessageFired;
			((Control)this).Invoke((Delegate)invokeOnEventLogMessageFired, new object[4] { evenType, title, eventMessage, detailedDescription });
			return;
		}
		((Control)tbLog).Text = ((Control)tbLog).Text + Environment.NewLine + evenType;
		((Control)tbLog).Text = ((Control)tbLog).Text + Environment.NewLine + title + " : " + eventMessage;
		((Control)tbLog).Text = ((Control)tbLog).Text + Environment.NewLine + detailedDescription;
		((Control)tbLog).Text = ((Control)tbLog).Text + Environment.NewLine + "----------------------------------" + Environment.NewLine + Environment.NewLine;
	}

	private void cmbDeviceAddress_SelectedIndexChanged(object sender, EventArgs e)
	{
		ClearView();
	}

	private void ClearView()
	{
		((Control)laModuleTypeValue).Text = "NONE";
		((Control)laProductIDValue).Text = "NONE";
		((Control)laCalVersionValue).Text = "NONE";
		((Control)laPartNumberValue).Text = "PartNumber";
		((Control)laCalibrationSecurity).Text = "NONE";
		((Control)cmbModuleStatus).Text = "";
		((Control)laRunLocationValue).Text = "NONE";
		((Control)laSerialNumberValue).Text = "SerialNumber";
		((Control)laModuleStatusValue).Text = "NONE";
		statusBarPanel2.Text = "";
		statusBarPanel1.Text = "";
		((Control)gbUnlockInfo).Text = "";
	}

	private void SetOptions()
	{
		connectionProperties1.UpdateView(this, EventArgs.Empty);
		appConfigService.SetAppSetting(ApplicationSettings.Protocol, connectionProperties1.Protocol);
		appConfigService.SetAppSetting(ApplicationSettings.Adapter, AdapterType.RP1210a.ToString());
		connectionProperties1.SetDeviceSelectionString();
		appConfigService.SetAppSetting(ApplicationSettings.RP1210Option, connectionProperties1.RP1210DeviceIndex.ToString());
		appConfigService.SetAppSetting(ApplicationSettings.RP1210DllName, connectionProperties1.RP1210DllName);
		appConfigService.SetAppSetting(ApplicationSettings.RP1210DeviceID, connectionProperties1.RP1210DeviceID);
		appConfigService.SetAppSetting(ApplicationSettings.RP1210Vendor, connectionProperties1.RP1210VendorIndex.ToString());
	}

	private void LoadSettings()
	{
		try
		{
			connectionProperties1.Protocol = appConfigService.GetAppSetting(ApplicationSettings.Protocol);
			connectionProperties1.RP1210DeviceIndex = int.Parse(appConfigService.GetAppSetting(ApplicationSettings.RP1210Option));
			connectionProperties1.RP1210VendorIndex = int.Parse(appConfigService.GetAppSetting(ApplicationSettings.RP1210Vendor));
			connectionProperties1.RP1210DllName = appConfigService.GetAppSetting(ApplicationSettings.RP1210DllName);
			connectionProperties1.RP1210DeviceID = appConfigService.GetAppSetting(ApplicationSettings.RP1210DeviceID);
		}
		catch
		{
		}
	}

	private void OnConnectionSettingsChanged(object sender, EventArgs e)
	{
		ClearView();
		cmbDeviceAddress.Items.Clear();
		((Control)cmbDeviceAddress).Text = "";
	}

	private void OnAutoStopBroadcastBoxCheckedChanged(object sender, EventArgs e)
	{
		RaiseAutoStopBroadcastChangedEvent(autoStopBroadcastBox.Checked);
		appConfigService.SetAppSetting(ApplicationSettings.AutoStopBroadCastChecked, autoStopBroadcastBox.Checked.ToString());
	}

	private void RaiseAutoStopBroadcastChangedEvent(bool isAutoStopBroadcast)
	{
		if (this.AutoStopBroadcastChangedEvent != null)
		{
			AutoStopBroadcastChangedEventArgs args = new AutoStopBroadcastChangedEventArgs(isAutoStopBroadcast);
			this.AutoStopBroadcastChangedEvent(this, args);
		}
	}
}
