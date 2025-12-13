using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using System.Xml;
using Cummins;
using CureCore;

[assembly: AssemblyFileVersion("1.1.0.10127")]
[assembly: Guid("54cae30e-cccf-46ad-8aa5-bc746c78a8f7")]
[assembly: ComVisible(false)]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2009-2010")]
[assembly: AssemblyProduct("CureModelController")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyTitle("CureModelController")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("1.1.0.10127")]
namespace CURE;

public interface ICUREView
{
	void AddListener(CUREUIController controller);

	void runCURE();

	void updateDevices(string[] deviceNames, int[] deviceIDs);

	void updateProgress(float percentage);

	void onError(CUREUIExitCode_t exitCode);

	void onDownloadComplete(float downloadTime);
}
public struct CURE_ECUInfo
{
	public int address;

	public string serialNumber;

	public string partNumber;

	public string ECUcalibrationVersion;

	public bool licCompatibility;

	public CURE_ECUInfo(int ecuaddress, string serialnumber, string partnumber, string ecuCal, bool liccompat)
	{
		address = ecuaddress;
		ECUcalibrationVersion = ecuCal;
		serialNumber = serialnumber;
		partNumber = partnumber;
		licCompatibility = liccompat;
	}
}
public enum CUREUIExitCode_t
{
	CURE_RET_DOWNLOAD_COMPLETED_SUCCESSFULLY = 0,
	CURE_RET_UNKNOWN_ERROR = 255,
	CURE_RET_INVALID_INPUT_FORMAT_USAGE = 16,
	CURE_RET_INVALID_VENDOR_DLL = 17,
	CURE_RET_INVALID_DEVICEID = 18,
	CURE_RET_CALIBRATION_FILE_NOT_FOUND = 19,
	CURE_RET_INVALID_CALIBRATION_FILE = 20,
	CURE_RET_INVALID_LICENSE = 21,
	CURE_RET_ERROR_CREATING_LOG = 22,
	CURE_RET_PRODUCT_ID_LICENSE_CHECK_FAILED = 23,
	CURE_RET_FILE_PASSWORD_LICENSE_CHECK_FAILED = 24,
	CURE_RET_GENERAL_ERROR_CONNECTING_TO_ECM = 32,
	CURE_RET_COMMUNICATION_TIMEOUT = 33,
	CURE_RET_NEGATIVE_RESPONSE_FROM_ECM = 34,
	CURE_RET_NO_ECM_DETECTED = 35,
	CURE_RET_AVAILABLE_ECMS_NOT_COMPATIBLE = 36,
	CURE_RET_GENERAL_ERROR_PREPARING_FOR_DOWNLOAD = 48,
	CURE_RET_COMMUNICATION_TIMEOUT_PREPARING_FOR_DOWNLOAD = 49,
	CURE_RET_NEGATIVE_RESPONSE_FROM_ECM_PREPARING_FOR_DOWNLOAD = 50,
	CURE_RET_GENERAL_ERROR_TRANSFERRING_DATA = 64,
	CURE_RET_COMMUNICATION_TIMEOUT_TRANSFERRING_DATA = 65,
	CURE_RET_NEGATIVE_RESPONSE_FROM_ECM_TRANSFERRING_DATA = 66,
	CURE_RET_GENERAL_ERROR_POST_DOWNLOAD_PROCESSING = 80,
	CURE_RET_COMMUNICATION_TIMEOUT_POST_DOWNLOAD_PROCESSING = 81,
	CURE_RET_NEGATIVE_RESPONSE_FROM_ECM_POST_DOWNLOAD_PROCESSING = 82
}
public class ERRORINFO
{
	public TranslationString_t state;

	public TranslationString_t error;

	public TranslationString_t comment;

	public ERRORINFO(TranslationString_t reflashState, TranslationString_t reflashError, TranslationString_t reflashComment)
	{
		state = reflashState;
		error = reflashError;
		comment = reflashComment;
	}

	public string getState()
	{
		return LanguageTranslation.getString(state);
	}

	public string getError()
	{
		return LanguageTranslation.getString(error);
	}

	public string getComment()
	{
		return LanguageTranslation.getString(comment);
	}
}
public class CUREUIModel
{
	private const int MAX_ERR_RET_CODES = 256;

	private Thread downloadThread;

	private DownloadLibrary lib;

	private ArrayList deviceList;

	private CUREUIController controller;

	private Dictionary<ELogEntryField, string> logEntry;

	private ActivityLogCS activityLog;

	private string vendorPrefix;

	private string deviceName;

	private int deviceID;

	private string calibrationFile;

	private int ecuAddress = 255;

	private ERRORINFO[] errorInfoArray;

	public int ECUAddress
	{
		get
		{
			return ecuAddress;
		}
		set
		{
			ecuAddress = value;
		}
	}

	public string VendorPrefix
	{
		get
		{
			return vendorPrefix;
		}
		set
		{
			vendorPrefix = value;
		}
	}

	public int DeviceID
	{
		get
		{
			return deviceID;
		}
		set
		{
			deviceID = value;
		}
	}

	public string CalibrationFile
	{
		get
		{
			return calibrationFile;
		}
		set
		{
			string action = "Loading Calibration File and Verifying License";
			calibrationFile = value;
			if (!isCalFileExists())
			{
				updateLog(action, "Calibration file doesnot exist", CUREUIExitCode_t.CURE_RET_CALIBRATION_FILE_NOT_FOUND.ToString());
				onError(CUREUIExitCode_t.CURE_RET_CALIBRATION_FILE_NOT_FOUND);
				return;
			}
			try
			{
				if (lib != null)
				{
					lib.Dispose();
					lib = null;
				}
				lib = new DownloadLibrary(calibrationFile);
				lib.OnMsgReceived += lib_OnMsgReceived;
				lib.verifyLoadedCalibration();
			}
			catch (CureException ex)
			{
				updateLog(action, ex.ToString(), getErrorCode(ex).ToString());
				onError(getErrorCode(ex));
			}
			updateLog(action, "SUCCESS", null);
		}
	}

	private void initErrorInfoArray()
	{
		errorInfoArray = new ERRORINFO[256];
		errorInfoArray[0] = new ERRORINFO(TranslationString_t.ReflashCompleteState, TranslationString_t.ReflashCompleteMessage, TranslationString_t.ReflashCompleteMessage);
		errorInfoArray[16] = new ERRORINFO(TranslationString_t.ValidatingInputsState, TranslationString_t.InvalidInputError, TranslationString_t.InvalidInputErrorMessage);
		errorInfoArray[17] = new ERRORINFO(TranslationString_t.ValidatingInputsState, TranslationString_t.InvalidVendorDLLError, TranslationString_t.InvalidVendorDLLErrorMessage);
		errorInfoArray[18] = new ERRORINFO(TranslationString_t.ValidatingInputsState, TranslationString_t.InvalidDeviceIdError, TranslationString_t.InvalidDeviceIDErrorMessage);
		errorInfoArray[19] = new ERRORINFO(TranslationString_t.ValidatingInputsState, TranslationString_t.CalFileNotFoundError, TranslationString_t.CalibrationFileNotFoundErrorMessage);
		errorInfoArray[20] = new ERRORINFO(TranslationString_t.ValidatingInputsState, TranslationString_t.InvalidCalFileError, TranslationString_t.CalibrationFileNotFoundErrorMessage);
		errorInfoArray[21] = new ERRORINFO(TranslationString_t.ValidatingInputsState, TranslationString_t.InvalidLicenseError, TranslationString_t.InvalidLicenseErrorMessage);
		errorInfoArray[22] = new ERRORINFO(TranslationString_t.ValidatingInputsState, TranslationString_t.LogFileCreationError, TranslationString_t.CheckFilePermissionErrorMessage);
		errorInfoArray[23] = new ERRORINFO(TranslationString_t.ValidatingInputsState, TranslationString_t.CheckProductIdLicenseError, TranslationString_t.CheckCalFileOrSelectedECUMessage);
		errorInfoArray[24] = new ERRORINFO(TranslationString_t.ValidatingInputsState, TranslationString_t.FilePasswordLicenseError, TranslationString_t.CheckCalFileOrSelectedECUMessage);
		errorInfoArray[32] = new ERRORINFO(TranslationString_t.ConnectingToECUState, TranslationString_t.ConnectToECUError, TranslationString_t.VendorDeviceErrorMessage);
		errorInfoArray[33] = new ERRORINFO(TranslationString_t.ConnectingToECUState, TranslationString_t.CommunicationTimeoutError, TranslationString_t.ConnectionSetupErrorMessage);
		errorInfoArray[34] = new ERRORINFO(TranslationString_t.ConnectingToECUState, TranslationString_t.NegRespFromECUError, TranslationString_t.ConnectionSetupErrorMessage);
		errorInfoArray[35] = new ERRORINFO(TranslationString_t.ConnectingToECUState, TranslationString_t.NoECUDetectedError, TranslationString_t.VendorDeviceErrorMessage);
		errorInfoArray[36] = new ERRORINFO(TranslationString_t.ConnectingToECUState, TranslationString_t.NocompatibleECUsError, TranslationString_t.ConnectionSetupErrorMessage);
		errorInfoArray[48] = new ERRORINFO(TranslationString_t.PreparingForReflashState, TranslationString_t.GeneralError, TranslationString_t.ConnectionSetupErrorMessage);
		errorInfoArray[49] = new ERRORINFO(TranslationString_t.PreparingForReflashState, TranslationString_t.CommunicationTimeoutError, TranslationString_t.ConnectionSetupErrorMessage);
		errorInfoArray[50] = new ERRORINFO(TranslationString_t.PreparingForReflashState, TranslationString_t.NegRespFromECUError, TranslationString_t.ConnectionSetupErrorMessage);
		errorInfoArray[64] = new ERRORINFO(TranslationString_t.TransferringDataState, TranslationString_t.GeneralError, TranslationString_t.ConnectionSetupErrorMessage);
		errorInfoArray[65] = new ERRORINFO(TranslationString_t.TransferringDataState, TranslationString_t.CommunicationTimeoutError, TranslationString_t.ConnectionSetupErrorMessage);
		errorInfoArray[66] = new ERRORINFO(TranslationString_t.TransferringDataState, TranslationString_t.NegRespFromECUError, TranslationString_t.ConnectionSetupErrorMessage);
		errorInfoArray[80] = new ERRORINFO(TranslationString_t.PostDownloadState, TranslationString_t.GeneralError, TranslationString_t.ConnectionSetupErrorMessage);
		errorInfoArray[81] = new ERRORINFO(TranslationString_t.PostDownloadState, TranslationString_t.CommunicationTimeoutError, TranslationString_t.ConnectionSetupErrorMessage);
		errorInfoArray[82] = new ERRORINFO(TranslationString_t.PostDownloadState, TranslationString_t.NegRespFromECUError, TranslationString_t.ConnectionSetupErrorMessage);
	}

	public string getDefaultFileExtension()
	{
		return DownloadLibrary.getDefaultFileExtension();
	}

	public string getCalibrationVersion()
	{
		string action = "Retrieving Calibration Version";
		if (lib != null)
		{
			return lib.getCalibrationFileVersion();
		}
		updateLog(action, "Library not instantiated", CUREUIExitCode_t.CURE_RET_UNKNOWN_ERROR.ToString());
		onError(CUREUIExitCode_t.CURE_RET_UNKNOWN_ERROR);
		return null;
	}

	~CUREUIModel()
	{
		activityLog.Shutdown();
		DownloadLibrary.stopSystem();
	}

	public bool initializeCure()
	{
		string action = "Initialize CURE";
		try
		{
			activityLog = ActivityLogCS.CreateActivityLog();
			initErrorInfoArray();
			Dictionary<EToolSetup, string> dictionary = new Dictionary<EToolSetup, string>();
			dictionary.Add(EToolSetup._LANGUAGE, "ENGLISH");
			dictionary.Add(EToolSetup._PC_DATE, DateTime.Today.Date.ToString());
			dictionary.Add(EToolSetup._PC_TIME, DateTime.Today.Hour.ToString());
			dictionary.Add(EToolSetup._TOOL_NAME, "CURE - Cummins Reflash Utility");
			dictionary.Add(EToolSetup._OSVERSION, Environment.OSVersion.ToString());
			dictionary.Add(EToolSetup._PC_ID, Environment.MachineName.ToString());
			activityLog.Init("CURE.log", 1000000u, dictionary);
			logEntry = new Dictionary<ELogEntryField, string>();
			DownloadLibrary.startSystem();
			deviceList = DownloadLibrary.getInstalledDevices();
			updateLog(action, "SUCCESS", null);
			return true;
		}
		catch (CureException ex)
		{
			updateLog(action, ex.ToString(), getErrorCode(ex).ToString());
			onError(getErrorCode(ex));
			return false;
		}
		catch (Exception ex2)
		{
			updateLog(action, ex2.ToString(), CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_PREPARING_FOR_DOWNLOAD.ToString());
			onError(CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_PREPARING_FOR_DOWNLOAD);
			return false;
		}
	}

	public void addController(CUREUIController controller)
	{
		this.controller = controller;
	}

	public string[] getAvailableVendorNames()
	{
		//IL_001a: Unknown result type (might be due to invalid IL or missing references)
		//IL_001f: Unknown result type (might be due to invalid IL or missing references)
		ArrayList arrayList = new ArrayList();
		foreach (AdapterInfo device in deviceList)
		{
			if (!arrayList.Contains(device.vendorName))
			{
				arrayList.Add(device.vendorName);
			}
		}
		return (string[])arrayList.ToArray(Type.GetType("System.String"));
	}

	public string[] getAvailableDeviceIDs(string vendorName)
	{
		//IL_001a: Unknown result type (might be due to invalid IL or missing references)
		//IL_001f: Unknown result type (might be due to invalid IL or missing references)
		ArrayList arrayList = new ArrayList();
		foreach (AdapterInfo device in deviceList)
		{
			if (device.vendorName == vendorName)
			{
				arrayList.Add(device.deviceId);
			}
		}
		return (string[])arrayList.ToArray(Type.GetType("System.String"));
	}

	public void setVendorPrefix(string deviceName)
	{
		//IL_0014: Unknown result type (might be due to invalid IL or missing references)
		//IL_0019: Unknown result type (might be due to invalid IL or missing references)
		foreach (AdapterInfo device in deviceList)
		{
			if (device.deviceName == deviceName || device.deviceDescription == deviceName)
			{
				VendorPrefix = device.prefix;
				this.deviceName = device.deviceDescription;
				break;
			}
		}
	}

	public void onVendorChanged(string vendorName, ref string[] vendorPrefix, ref string[] deviceNames, ref int[] deviceIDs)
	{
		//IL_002e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0033: Unknown result type (might be due to invalid IL or missing references)
		ArrayList arrayList = new ArrayList();
		ArrayList arrayList2 = new ArrayList();
		ArrayList arrayList3 = new ArrayList();
		ArrayList arrayList4 = new ArrayList();
		foreach (AdapterInfo device in deviceList)
		{
			if (device.vendorName == vendorName)
			{
				arrayList.Add(device.deviceName);
				arrayList2.Add(device.deviceId);
				arrayList3.Add(device.prefix);
				arrayList4.Add(device.deviceDescription);
			}
		}
		if (arrayList4[0].ToString() != "")
		{
			deviceNames = (string[])arrayList4.ToArray(Type.GetType("System.String"));
		}
		else
		{
			deviceNames = (string[])arrayList.ToArray(Type.GetType("System.String"));
		}
		deviceIDs = (int[])arrayList2.ToArray(Type.GetType("System.Int32"));
		vendorPrefix = (string[])arrayList3.ToArray(Type.GetType("System.String"));
	}

	public bool startDownload()
	{
		string action = "Starting Download Thread";
		updateLog(action, "Downloading Calibration file : " + CalibrationFile, null);
		if (!isValidVendorPrefix())
		{
			updateLog(action, "Invalid Vendor Name", CUREUIExitCode_t.CURE_RET_INVALID_VENDOR_DLL.ToString());
			onError(CUREUIExitCode_t.CURE_RET_INVALID_VENDOR_DLL);
			return false;
		}
		if (!isValidDeviceID())
		{
			updateLog(action, "Invalid Device ID", CUREUIExitCode_t.CURE_RET_INVALID_DEVICEID.ToString());
			onError(CUREUIExitCode_t.CURE_RET_INVALID_DEVICEID);
			return false;
		}
		if (!isCalFileExists())
		{
			updateLog(action, "Calibration file not found", CUREUIExitCode_t.CURE_RET_CALIBRATION_FILE_NOT_FOUND.ToString());
			onError(CUREUIExitCode_t.CURE_RET_CALIBRATION_FILE_NOT_FOUND);
			return false;
		}
		LanguageTranslation.getString(TranslationString_t.CURETitle);
		try
		{
			if (lib == null)
			{
				lib = new DownloadLibrary(calibrationFile);
				lib.OnMsgReceived += lib_OnMsgReceived;
				lib.verifyLoadedCalibration();
			}
			downloadThread = new Thread(runDownload);
			downloadThread.SetApartmentState(ApartmentState.MTA);
			downloadThread.Start();
			updateLog(action, "SUCCESS", null);
			return true;
		}
		catch (Exception ex)
		{
			updateLog(action, ex.ToString(), CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_PREPARING_FOR_DOWNLOAD.ToString());
			onError(CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_PREPARING_FOR_DOWNLOAD);
			return false;
		}
	}

	private void runDownload()
	{
		string action = "Execute Download";
		try
		{
			lib.executeDownload(VendorPrefix, DeviceID, ecuAddress);
			updateLog(action, "SUCCESS", null);
		}
		catch (CureException ex)
		{
			updateLog(action, ex.ToString(), getErrorCode(ex).ToString());
			onError(getErrorCode(ex));
		}
	}

	public unsafe ArrayList getAvailableECUs()
	{
		//IL_00af: Expected O, but got Ref
		//IL_00b6: Expected O, but got Ref
		//IL_00bd: Expected O, but got Ref
		//IL_00c4: Expected O, but got Ref
		//IL_00cb: Expected O, but got Ref
		string action = "Get Available ECUs";
		ArrayList arrayList = new ArrayList();
		try
		{
			if (!isValidVendorPrefix())
			{
				updateLog(action, "Invalid Vendor Name", CUREUIExitCode_t.CURE_RET_INVALID_VENDOR_DLL.ToString());
				onError(CUREUIExitCode_t.CURE_RET_INVALID_VENDOR_DLL);
				return arrayList;
			}
			if (!isValidDeviceID())
			{
				updateLog(action, "Invalid Device Id", CUREUIExitCode_t.CURE_RET_INVALID_DEVICEID.ToString());
				onError(CUREUIExitCode_t.CURE_RET_INVALID_DEVICEID);
				return arrayList;
			}
			if (lib != null)
			{
				ArrayList availableECUs = lib.getAvailableECUs(VendorPrefix, DeviceID);
				foreach (ECUInfo item in availableECUs)
				{
					ECUInfo eCUInfo = item;
					CURE_ECUInfo cURE_ECUInfo = new CURE_ECUInfo(((ECUInfo)(&eCUInfo)).address, ((ECUInfo)(&eCUInfo)).serialNumber, ((ECUInfo)(&eCUInfo)).partNumber, ((ECUInfo)(&eCUInfo)).ECUcalibrationVersion, ((ECUInfo)(&eCUInfo)).licCompatibility);
					arrayList.Add(cURE_ECUInfo);
				}
				return arrayList;
			}
			updateLog(action, "Download Library not instantiated", CUREUIExitCode_t.CURE_RET_UNKNOWN_ERROR.ToString());
			onError(CUREUIExitCode_t.CURE_RET_UNKNOWN_ERROR);
			return arrayList;
		}
		catch (CureException ex)
		{
			updateLog(action, ex.ToString(), ex.getExceptionCode().ToString() + ":" + ex.getErrorType());
			onError(getErrorCode(ex));
			return arrayList;
		}
	}

	public DownloadAlgorithm getDownloadAlgorithm()
	{
		return DownloadLibrary.getDownloadAlgorithm();
	}

	public bool isCalFileExists()
	{
		if (!File.Exists(CalibrationFile))
		{
			return false;
		}
		return true;
	}

	public bool isValidVendorPrefix()
	{
		//IL_0014: Unknown result type (might be due to invalid IL or missing references)
		//IL_0019: Unknown result type (might be due to invalid IL or missing references)
		foreach (AdapterInfo device in deviceList)
		{
			if (VendorPrefix.Equals(device.prefix))
			{
				return true;
			}
			if (string.Compare(vendorPrefix, device.prefix, ignoreCase: true) == 0)
			{
				vendorPrefix = device.prefix;
				return true;
			}
		}
		return false;
	}

	public bool isValidDeviceID()
	{
		//IL_0014: Unknown result type (might be due to invalid IL or missing references)
		//IL_0019: Unknown result type (might be due to invalid IL or missing references)
		foreach (AdapterInfo device in deviceList)
		{
			if (VendorPrefix.Equals(device.prefix, StringComparison.InvariantCultureIgnoreCase) && DeviceID.Equals(device.deviceId))
			{
				return true;
			}
		}
		return false;
	}

	private CureMsgReturnType_t lib_OnMsgReceived(Message msg)
	{
		string text = "Message Recieved";
		ListDictionary parameters = msg.getParameters();
		ICollection values = parameters.Values;
		IEnumerator enumerator = values.GetEnumerator();
		try
		{
			if (MsgID_t.PDL_TRANSFER_PROGRESS.Equals(msg.getIdentifier()))
			{
				text = "Transfer Progress";
				int num = 0;
				while (enumerator.MoveNext() && num < 3)
				{
					num++;
				}
				MessageParam messageParam = (MessageParam)enumerator.Current;
				controller.updateProgress(messageParam.floatValue);
				string details = messageParam.floatValue + "% of Reflash Completed.";
				updateLog(text, details, null);
			}
			else if (MsgID_t.PDL_DOWNLOAD_PROGRESS.Equals(msg.getIdentifier()))
			{
				text = "Download Progress";
				enumerator.MoveNext();
				string details = ((MessageParam)enumerator.Current).stringValue + ": ";
				enumerator.MoveNext();
				details += ((MessageParam)enumerator.Current).stringValue;
				updateLog(text, details, null);
			}
			else if (MsgID_t.PDL_NOTIFY_COMPLETE.Equals(msg.getIdentifier()))
			{
				text = "Notify Complete";
				enumerator.MoveNext();
				MessageParam messageParam2 = (MessageParam)enumerator.Current;
				controller.onDownloadComplete(messageParam2.floatValue);
				string details = "Download Completed in: " + messageParam2.floatValue + " sec.";
				updateLog(text, details, CUREUIExitCode_t.CURE_RET_DOWNLOAD_COMPLETED_SUCCESSFULLY.ToString());
			}
			else if (MsgID_t.PDL_ERROR_REPORT.Equals(msg.getIdentifier()))
			{
				text = "Message Recieved";
				enumerator.MoveNext();
				MessageParam messageParam3 = (MessageParam)enumerator.Current;
				string details = "Error at FILE: " + msg.getFileName() + " LINE: " + msg.getLineNumber() + " : " + messageParam3.stringValue;
				updateLog(text, details, CUREUIExitCode_t.CURE_RET_UNKNOWN_ERROR.ToString());
			}
		}
		catch (Exception ex)
		{
			text = "Message Recieved";
			updateLog(text, ex.ToString(), CUREUIExitCode_t.CURE_RET_UNKNOWN_ERROR.ToString());
			onError(CUREUIExitCode_t.CURE_RET_UNKNOWN_ERROR);
		}
		return CureMsgReturnType_t.CURE_MSGRT_UNSPECIFIED;
	}

	private CUREUIExitCode_t getErrorCode(CureException ex)
	{
		CUREUIExitCode_t cUREUIExitCode_t = CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_PREPARING_FOR_DOWNLOAD;
		switch (ex.getExceptionCode())
		{
		case CureExceptionCode_t.CURE_ERR_READ_FILE:
			return CUREUIExitCode_t.CURE_RET_INVALID_CALIBRATION_FILE;
		case CureExceptionCode_t.CURE_ERR_INVALID_CAL_FILE:
			return CUREUIExitCode_t.CURE_RET_INVALID_CALIBRATION_FILE;
		case CureExceptionCode_t.CURE_ERR_INVALID_EOF:
			return CUREUIExitCode_t.CURE_RET_INVALID_CALIBRATION_FILE;
		case CureExceptionCode_t.CURE_ERR_INVALID_FILE_CRC:
			return CUREUIExitCode_t.CURE_RET_INVALID_CALIBRATION_FILE;
		case CureExceptionCode_t.CURE_ERR_INVALID_CAL_ADDR:
			return CUREUIExitCode_t.CURE_RET_INVALID_CALIBRATION_FILE;
		case CureExceptionCode_t.CURE_ERR_INVALID_CAL_IMAGE:
			return CUREUIExitCode_t.CURE_RET_INVALID_CALIBRATION_FILE;
		case CureExceptionCode_t.CURE_ERR_PREPROCESSING_FAILED:
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_GENERAL_FAIL_EXCEPTION)
			{
				return CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_PREPARING_FOR_DOWNLOAD;
			}
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_NEG_ECU_RESPONSE_EXCEPTION)
			{
				return CUREUIExitCode_t.CURE_RET_NEGATIVE_RESPONSE_FROM_ECM_PREPARING_FOR_DOWNLOAD;
			}
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_DRIVER_EXCEPTION)
			{
				return CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_PREPARING_FOR_DOWNLOAD;
			}
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_NOT_IMPLEMENTED)
			{
				return CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_PREPARING_FOR_DOWNLOAD;
			}
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_COMMUNICATION_TIMEOUT)
			{
				return CUREUIExitCode_t.CURE_RET_COMMUNICATION_TIMEOUT_PREPARING_FOR_DOWNLOAD;
			}
			return CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_PREPARING_FOR_DOWNLOAD;
		case CureExceptionCode_t.CURE_ERR_DATA_TRANSFER_FAILED:
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_GENERAL_FAIL_EXCEPTION)
			{
				return CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_TRANSFERRING_DATA;
			}
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_NEG_ECU_RESPONSE_EXCEPTION)
			{
				return CUREUIExitCode_t.CURE_RET_NEGATIVE_RESPONSE_FROM_ECM_TRANSFERRING_DATA;
			}
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_DRIVER_EXCEPTION)
			{
				return CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_TRANSFERRING_DATA;
			}
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_NOT_IMPLEMENTED)
			{
				return CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_TRANSFERRING_DATA;
			}
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_COMMUNICATION_TIMEOUT)
			{
				return CUREUIExitCode_t.CURE_RET_COMMUNICATION_TIMEOUT_TRANSFERRING_DATA;
			}
			return CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_TRANSFERRING_DATA;
		case CureExceptionCode_t.CURE_ERR_POSTPROCESSING_FAILED:
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_GENERAL_FAIL_EXCEPTION)
			{
				return CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_POST_DOWNLOAD_PROCESSING;
			}
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_NEG_ECU_RESPONSE_EXCEPTION)
			{
				return CUREUIExitCode_t.CURE_RET_NEGATIVE_RESPONSE_FROM_ECM_POST_DOWNLOAD_PROCESSING;
			}
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_DRIVER_EXCEPTION)
			{
				return CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_POST_DOWNLOAD_PROCESSING;
			}
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_NOT_IMPLEMENTED)
			{
				return CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_POST_DOWNLOAD_PROCESSING;
			}
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_COMMUNICATION_TIMEOUT)
			{
				return CUREUIExitCode_t.CURE_RET_COMMUNICATION_TIMEOUT_POST_DOWNLOAD_PROCESSING;
			}
			return CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_POST_DOWNLOAD_PROCESSING;
		case CureExceptionCode_t.CURE_ERR_INVALID_DEVICE_CONFIG:
			return CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_CONNECTING_TO_ECM;
		case CureExceptionCode_t.CURE_ERR_UNSUPPORTED_ALGORITHM:
			return CUREUIExitCode_t.CURE_RET_INVALID_CALIBRATION_FILE;
		case CureExceptionCode_t.CURE_ERR_UNKNOWN:
			return CUREUIExitCode_t.CURE_RET_UNKNOWN_ERROR;
		case CureExceptionCode_t.CURE_ERR_SYSTEM_IS_NOT_STARTED:
			return CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_PREPARING_FOR_DOWNLOAD;
		case CureExceptionCode_t.CURE_ERR_INVALID_LICENSE:
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_FILE_PASSWORD_LICENSE_CHECK_FAILED)
			{
				return CUREUIExitCode_t.CURE_RET_FILE_PASSWORD_LICENSE_CHECK_FAILED;
			}
			if (ex.getErrorType() == CureErrorType_t.CURE_ERR_PRODUCT_ID_LICENSE_CHECK_FAILED)
			{
				return CUREUIExitCode_t.CURE_RET_PRODUCT_ID_LICENSE_CHECK_FAILED;
			}
			return CUREUIExitCode_t.CURE_RET_INVALID_LICENSE;
		case CureExceptionCode_t.CURE_ERR_AVAILABLE_ECMS_NOT_COMPATIBLE:
			return CUREUIExitCode_t.CURE_RET_AVAILABLE_ECMS_NOT_COMPATIBLE;
		case CureExceptionCode_t.CURE_ERR_INTERNAL_PROGRAMMING_ERROR:
			return CUREUIExitCode_t.CURE_RET_UNKNOWN_ERROR;
		case CureExceptionCode_t.CURE_ERR_NO_ECM_DETECTED:
			return CUREUIExitCode_t.CURE_RET_NO_ECM_DETECTED;
		default:
			return CUREUIExitCode_t.CURE_RET_GENERAL_ERROR_CONNECTING_TO_ECM;
		}
	}

	public ERRORINFO getErrorInfo(CUREUIExitCode_t exitCode)
	{
		uint num = 255u;
		if ((uint)exitCode < 256u)
		{
			num = (uint)exitCode;
		}
		return errorInfoArray[num];
	}

	private void updateLog(string action, string details, string exCode)
	{
		//IL_00dd: Unknown result type (might be due to invalid IL or missing references)
		//IL_00e2: Unknown result type (might be due to invalid IL or missing references)
		lock (logEntry)
		{
			logEntry.Add(ELogEntryField._ACTION, action);
			logEntry.Add(ELogEntryField._ACTION_DETAILS, details);
			logEntry.Add(ELogEntryField._DEVICE_HARDWARE_TYPE, getHWType(getDownloadAlgorithm()));
			logEntry.Add(ELogEntryField._DEVICE_PROTOCOL, getProtocol(getDownloadAlgorithm()));
			if (vendorPrefix != null)
			{
				logEntry.Add(ELogEntryField._DLA, vendorPrefix);
			}
			if (deviceName != null)
			{
				logEntry.Add(ELogEntryField._DEVICE_NAME, deviceName + " [ID: " + deviceID + "]");
			}
			else
			{
				if (deviceList != null)
				{
					foreach (AdapterInfo device in deviceList)
					{
						if (device.deviceId == deviceID && device.prefix == vendorPrefix)
						{
							if (device.deviceDescription != null)
							{
								deviceName = device.deviceDescription;
							}
							else
							{
								deviceName = device.deviceName;
							}
							break;
						}
					}
				}
				if (deviceName != null)
				{
					logEntry.Add(ELogEntryField._DEVICE_NAME, deviceName + " [ID: " + deviceID + "]");
				}
			}
			logEntry.Add(ELogEntryField._FEATURE_DETAILS, getHWType(getDownloadAlgorithm()));
			logEntry.Add(ELogEntryField._FEATURE_NAME, "Reflash");
			if (exCode != null)
			{
				logEntry.Add(ELogEntryField._ERRORID, exCode);
			}
			activityLog.WriteLogEntry(logEntry);
			logEntry.Clear();
		}
	}

	private string getHWType(DownloadAlgorithm algo)
	{
		return algo switch
		{
			(DownloadAlgorithm)0 => "Bosch_DCU", 
			(DownloadAlgorithm)1 => "GTIS4_ECU", 
			_ => "UNKNOWN_DEVICE", 
		};
	}

	private string getProtocol(DownloadAlgorithm algo)
	{
		if (algo == (DownloadAlgorithm)0)
		{
			return "PCL_TRANSPORT_ISO15765";
		}
		return "PCL_TRANSPORT_J1939";
	}

	private void onError(CUREUIExitCode_t code)
	{
		controller.onError(code);
		if (lib != null)
		{
			lib.Dispose();
		}
		lib = null;
	}
}
public class CUREConfiguration
{
	public static string ReadCureConfig(string xmlNode)
	{
		//IL_009e: Expected O, but got Unknown
		//IL_00c5: Unknown result type (might be due to invalid IL or missing references)
		//IL_0094: Unknown result type (might be due to invalid IL or missing references)
		//IL_004a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0051: Expected O, but got Unknown
		string result = "";
		string text = "";
		string text2 = "";
		XmlNode val = null;
		XmlDocument val2 = null;
		try
		{
			Assembly executingAssembly = Assembly.GetExecutingAssembly();
			text = executingAssembly.Location;
			text2 = Path.GetDirectoryName(text) + "\\CURE.exe.config";
			File.SetAttributes(text2, FileAttributes.Normal);
			if (File.Exists(text2))
			{
				val2 = new XmlDocument();
				val2.Load(text2);
				val = ((XmlNode)val2).SelectSingleNode(xmlNode);
				if (val != null)
				{
					result = val.FirstChild.Value;
				}
			}
			else
			{
				result = "";
				MessageBox.Show(LanguageTranslation.getString(TranslationString_t.ConfigFileLocateError) + "\r\n" + text2, LanguageTranslation.getString(TranslationString_t.CURETitle), (MessageBoxButtons)0, (MessageBoxIcon)48);
			}
		}
		catch (XmlException ex)
		{
			XmlException ex2 = ex;
			result = "";
			MessageBox.Show(LanguageTranslation.getString(TranslationString_t.ConfigFileReadError) + " \r\n" + ((Exception)(object)ex2).Message, LanguageTranslation.getString(TranslationString_t.CURETitle), (MessageBoxButtons)0, (MessageBoxIcon)48);
		}
		catch (Exception)
		{
			result = "";
		}
		return result;
	}

	public static bool WriteCureConfig(string xmlNode, string nodeValue)
	{
		//IL_00e5: Expected O, but got Unknown
		//IL_0108: Unknown result type (might be due to invalid IL or missing references)
		//IL_0135: Unknown result type (might be due to invalid IL or missing references)
		//IL_00db: Unknown result type (might be due to invalid IL or missing references)
		//IL_0046: Unknown result type (might be due to invalid IL or missing references)
		//IL_004d: Expected O, but got Unknown
		bool result = true;
		string text = "";
		string text2 = "";
		XmlNode val = null;
		XmlDocument val2 = null;
		try
		{
			Assembly executingAssembly = Assembly.GetExecutingAssembly();
			text = executingAssembly.Location;
			text2 = Path.GetDirectoryName(text) + "\\CURE.exe.config";
			File.SetAttributes(text2, FileAttributes.Normal);
			if (File.Exists(text2))
			{
				val2 = new XmlDocument();
				val2.Load(text2);
				val = ((XmlNode)val2).SelectSingleNode(xmlNode);
				if (val != null)
				{
					val.InnerText = nodeValue;
					val2.Save(text2);
				}
				else
				{
					val = ((XmlNode)val2).LastChild;
					XmlNode val3 = null;
					val3 = val2.CreateNode((XmlNodeType)1, xmlNode.Substring(15, xmlNode.Length - 15), "");
					val3.InnerText = nodeValue;
					val.InsertAfter(val3, val.LastChild);
					val2.Save(text2);
				}
			}
			else
			{
				result = false;
				MessageBox.Show(LanguageTranslation.getString(TranslationString_t.ConfigFileLocateError) + "\r\n" + text2, LanguageTranslation.getString(TranslationString_t.CURETitle), (MessageBoxButtons)0, (MessageBoxIcon)48);
			}
		}
		catch (XmlException ex)
		{
			XmlException ex2 = ex;
			result = false;
			MessageBox.Show(LanguageTranslation.getString(TranslationString_t.ConfigFileSaveError) + "\r\n" + ((Exception)(object)ex2).Message, LanguageTranslation.getString(TranslationString_t.CURETitle), (MessageBoxButtons)0, (MessageBoxIcon)48);
		}
		catch (Exception ex3)
		{
			result = false;
			MessageBox.Show(LanguageTranslation.getString(TranslationString_t.ConfigFileSaveError) + "\r\n" + ex3.Message, LanguageTranslation.getString(TranslationString_t.CURETitle), (MessageBoxButtons)0, (MessageBoxIcon)48);
		}
		return result;
	}
}
public enum TranslationString_t
{
	CURE,
	CURETitle,
	ConnectionSettings,
	Vendor,
	Device,
	SelectCalFile,
	Browse,
	ReflashStatus,
	Reflash,
	ReflashCompleteMessage,
	InvalidInputErrorMessage,
	InvalidVendorDLLErrorMessage,
	InvalidDeviceIDErrorMessage,
	CalibrationFileNotFoundErrorMessage,
	VendorDeviceErrorMessage,
	ConnectionSetupErrorMessage,
	GeneralError,
	CommunicationTimeoutError,
	NegRespFromECUError,
	ValidatingInputsState,
	ConnectingToECUState,
	PreparingForReflashState,
	TransferringDataState,
	PostDownloadState,
	ReflashCompleteState,
	UnknownError,
	InvalidLicenseError,
	LogFileCreationError,
	EstimatingTotalTime,
	PercentReflashCompleted,
	EstimatedTimeleft,
	AnotherInstanceofCUREError,
	ReflashCompleteIn,
	seconds,
	ExitCode,
	InvalidInputFormatUsage,
	USAGE,
	ErrorCode,
	CURE_CLIInputUsageExample,
	minutes,
	NoDLADriverInstalledError,
	Step1of5,
	Step2of5,
	Step3of5,
	Step4of5,
	Step5of5,
	Next,
	Back,
	Cancel,
	Finish,
	ConfirmationMessage,
	SeleceECUMessage,
	ECUAddress,
	SerialNumber,
	ECUSoftwareVersion,
	PartNumber,
	NewSoftwareVersion,
	OldSoftwareVersion,
	ReflashConfirmation,
	InvalidLicenseErrorMessage,
	CheckConnectedECUMessage,
	CheckCalFileOrSelectedECUMessage,
	ID,
	NA,
	Calibrationfile,
	ConfigFileLocateError,
	ConfigFileReadError,
	ConfigFileSaveError,
	InvalidInputError,
	InvalidVendorDLLError,
	InvalidDeviceIdError,
	CalFileNotFoundError,
	InvalidCalFileError,
	ConnectToECUError,
	NoECUDetectedError,
	NocompatibleECUsError,
	CheckECUIDLicenseError,
	FilePasswordLicenseError,
	CheckProductIdLicenseError,
	CheckFilePermissionErrorMessage,
	Retry,
	Repeat
}
public class LanguageTranslation
{
	[DllImport("LTLWin32R.dll")]
	private static extern void LTLWIN_SetLanguageFile(IntPtr fileName);

	[DllImport("LTLWin32R.dll")]
	private static extern IntPtr LTLWIN_GetText(uint id, ref uint length);

	[DllImport("LTLWin32R.dll")]
	private static extern void LTLWIN_CloseLanguageFile();

	public static void setLanguageFile(string file)
	{
		IntPtr intPtr = Marshal.StringToHGlobalAnsi(file);
		LTLWIN_SetLanguageFile(intPtr);
		Marshal.FreeHGlobal(intPtr);
	}

	public static string getString(TranslationString_t id)
	{
		uint length = 0u;
		IntPtr source = LTLWIN_GetText((uint)id, ref length);
		length--;
		byte[] array = new byte[length];
		Marshal.Copy(source, array, 0, (int)length);
		return Encoding.UTF8.GetString(array, 0, (int)length);
	}

	public static void closeLanguageFile()
	{
		LTLWIN_CloseLanguageFile();
	}
}
public class CUREUIController
{
	private delegate void onErrorCompleter(CUREUIExitCode_t exitCode);

	private ICUREView view;

	private CUREUIModel model;

	public CUREUIController(ICUREView view, CUREUIModel model)
	{
		this.model = model;
		this.model.addController(this);
		this.view = view;
		this.view.AddListener(this);
		if (this.model.initializeCure())
		{
			this.view.runCURE();
		}
	}

	public string[] getAvailableVendorNames()
	{
		return model.getAvailableVendorNames();
	}

	public void onVendorChanged(string vendorName, ref string[] vendorPrefix, ref string[] deviceNames, ref int[] deviceIDs)
	{
		model.onVendorChanged(vendorName, ref vendorPrefix, ref deviceNames, ref deviceIDs);
		setVendorPrefix(vendorPrefix[0]);
		view.updateDevices(deviceNames, deviceIDs);
	}

	public void onDeviceChanged(string deviceName)
	{
		model.setVendorPrefix(deviceName);
	}

	public void setECUAddress(int ecuAdd)
	{
		model.ECUAddress = ecuAdd;
	}

	public void setDeviceID(int deviceID)
	{
		model.DeviceID = deviceID;
	}

	public void setVendorPrefix(string vendorPrefix)
	{
		model.VendorPrefix = vendorPrefix;
	}

	public void setCalibrationFile(string calibrationFile)
	{
		model.CalibrationFile = calibrationFile;
	}

	public bool startDownload()
	{
		return model.startDownload();
	}

	public void onError(CUREUIExitCode_t exitCode)
	{
		view.onError(exitCode);
	}

	public void updateProgress(float percentage)
	{
		view.updateProgress(percentage);
	}

	public void onDownloadComplete(float downloadTime)
	{
		view.onDownloadComplete(downloadTime);
	}

	public ERRORINFO getErrorInfoForExitCode(CUREUIExitCode_t exitCode)
	{
		return model.getErrorInfo(exitCode);
	}

	public ArrayList getAvailableECUs()
	{
		return model.getAvailableECUs();
	}

	public string getCalibrationVersion()
	{
		return model.getCalibrationVersion();
	}

	public string getDefaultFileExtension()
	{
		return model.getDefaultFileExtension();
	}
}
