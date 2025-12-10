using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.Serialization;
using System.Runtime.Versioning;
using System.Text;
using System.Xml;
using Cummins.AddressRepresentation;
using Cummins.EventLog;
using Cummins.Services;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyTitle("")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - Interface")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins
{
	public class BaseException : ApplicationException
	{
		private string context;

		public int ErrorCode
		{
			get
			{
				return base.HResult;
			}
			set
			{
				base.HResult = value;
			}
		}

		public string ContextData
		{
			get
			{
				return context;
			}
			set
			{
				context = value;
			}
		}

		public BaseException(Facility facility, short errorNo)
		{
			base.HResult = MakeHResult(Severity.Error, facility, errorNo);
		}

		public BaseException(Facility facility, short errorNo, string message)
			: base(message)
		{
			base.HResult = MakeHResult(Severity.Error, facility, errorNo);
		}

		public BaseException(Facility facility, short errorNo, string message, Exception inner)
			: base(message, inner)
		{
			base.HResult = MakeHResult(Severity.Error, facility, errorNo);
		}

		public BaseException(Facility facility, short errorNo, string message, string context)
			: base(message)
		{
			base.HResult = MakeHResult(Severity.Error, facility, errorNo);
			this.context = context;
		}

		public BaseException(Facility facility, short errorNo, string message, string context, Exception inner)
			: base(message, inner)
		{
			base.HResult = MakeHResult(Severity.Error, facility, errorNo);
			this.context = context;
		}

		public BaseException(SerializationInfo info, StreamingContext context)
			: base(info, context)
		{
		}

		protected int MakeHResult(Severity severity, Facility facility, short errorNo)
		{
			int num = (int)facility << 4;
			num += errorNo;
			return num + ((int)severity << 7);
		}
	}
	public class AppConfigValueException : BaseException
	{
		public AppConfigValueException(Facility facility, short errId)
			: base(facility, errId)
		{
		}

		public AppConfigValueException(Facility facility, short errId, string message)
			: base(facility, errId, message)
		{
		}

		public AppConfigValueException(Facility facility, short errId, string message, Exception inner)
			: base(facility, errId, message, inner)
		{
		}

		public AppConfigValueException(Facility facility, short errorNo, string message, string key)
			: base(facility, errorNo, message, key)
		{
		}

		public AppConfigValueException(Facility facility, short errorNo, string message, string key, Exception inner)
			: base(facility, errorNo, message, key, inner)
		{
		}
	}
	public enum Facility
	{
		Unknown = 0,
		DataDefintion = 1,
		SubfileComponent = 8,
		Calterm = 512,
		CaltermApplication = 513,
		ApplicationServices = 514,
		EventLog = 515,
		Logging = 516,
		MessageServices = 517,
		Calibration = 518,
		Parameter = 519,
		ModuleNetwork = 520,
		ProductInformation = 521,
		CRCUtility = 522,
		Editor = 523,
		FaultMonitor = 524,
		Subscription = 525,
		DynamicSwitches = 526,
		CalibrationEdit = 527,
		Filter = 528,
		CalTransfer = 529,
		CalDocument = 530,
		CalCompare = 531,
		CalibrationDivide = 532,
		AssemblyInvoker = 533,
		Overlay = 534,
		Verify = 535,
		SpeedTransfer = 536,
		SendOperation = 537,
		IDLLogger = 538,
		ProductInformationProvider = 539,
		Connection = 540,
		Unlock = 541,
		Session = 542
	}
	public enum Severity
	{
		Information,
		Warning,
		Error
	}
	public enum ErrorSources
	{
		Connection,
		CalTransfer,
		ConfigurationFile,
		Calibration,
		SubFile
	}
	public enum ConnectionErrorCodes
	{
		DataLinkError,
		ProtocolError,
		GTISLevelMismatch,
		ECMNotResponding,
		ECMNotRespondingAfterConnect,
		ECMConnectionLost,
		InvalidTCPIPAddressFormat,
		InvalidTCPIPAddress,
		ASAMServerNotResponding,
		InvalidASAMConfigurationFile
	}
	public enum CalibrationErrorCodes
	{
		IssueRomBootFailed,
		DLWriteFailed
	}
	public enum CalTransferErrorCodes
	{
		RunLocationDevelopment,
		ECMSecured,
		VehicleSpeedNotZero,
		EngineSpeedNotZero,
		DCL33Cal2Big,
		DCL97BlockTransferTimeOut,
		NoRemoteResponse,
		AuditTrailProcessFailed,
		BlockTransferFailed,
		MasterHeaderRecordClearing,
		AuditPreProcessingFailed,
		UnknownErrorInUpload
	}
	public enum ConfigFileErrorCodes
	{
		InvalidConfigFile
	}
	public enum SubFileErrorCodes
	{
		InvalidSubFile
	}
	public enum ProductInformationType
	{
		MarketingName,
		EngineeringName,
		HardwareName,
		ProductType,
		WordSize,
		ByteOrder,
		ECMIdentifier,
		Active,
		GTISLevel,
		SpeedSupport,
		NumberOfECM,
		Parent,
		Child
	}
	public enum DataSourceFileType
	{
		Configuration20,
		Configuration38,
		Configuration45,
		Calibration20,
		Calibration38,
		Calibration45,
		Subfile,
		ImportExportXml,
		ImportExportOvl20,
		ImportExportOvl38,
		Unknown
	}
	public enum UserResponse
	{
		Continue,
		Hold,
		None
	}
	public enum RangeLimit
	{
		Clip,
		Enforce,
		Ignore
	}
	public class CRCException : BaseException
	{
		private string fileName = string.Empty;

		public string FileName => fileName;

		public CRCException(Facility facility, short errorNo)
			: base(facility, errorNo)
		{
		}

		public CRCException(Facility facility, short errorNo, string message)
			: base(facility, errorNo, message)
		{
		}

		public CRCException(Facility facility, short errorNo, string message, Exception inner)
			: base(facility, errorNo, message, inner)
		{
		}

		public CRCException(Facility facility, short errorNo, string message, string fileName)
			: base(facility, errorNo, message)
		{
			this.fileName = fileName;
		}

		public CRCException(Facility facility, short errorNo, string message, string fileName, Exception inner)
			: base(facility, errorNo, message, inner)
		{
			this.fileName = fileName;
		}
	}
	public class ErrorHelper
	{
		private const int ErrorSourceLength = 3;

		private const int ErrorCodeLength = 4;

		private const string ErrorCodeSeparator = "-";

		private static char CharZero = '0';

		public static string GetErrorCode(ErrorSources source, ushort errorCode)
		{
			int num = (int)source;
			return num.ToString().PadLeft(3, CharZero) + "-" + errorCode.ToString().PadLeft(4, CharZero);
		}
	}
	public class ExceptionParser
	{
		public static string ParseException(Exception ex)
		{
			return new ExceptionParser().InternalParseException(ex);
		}

		private string InternalParseException(Exception exception)
		{
			StringBuilder stringBuilder = new StringBuilder();
			while (exception != null)
			{
				if (exception.Message.StartsWith("<"))
				{
					stringBuilder.Append(ParseXMLNode(exception.Message));
				}
				else
				{
					stringBuilder.Append(exception.Message);
					stringBuilder.Append(Environment.NewLine);
				}
				stringBuilder.Append(Environment.NewLine);
				stringBuilder.Append("Stack Trace: ");
				stringBuilder.Append(exception.StackTrace);
				exception = exception.InnerException;
			}
			return stringBuilder.ToString();
		}

		private string ParseXMLNode(string xmlString)
		{
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_000c: Expected O, but got Unknown
			//IL_002b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0031: Expected O, but got Unknown
			StringBuilder stringBuilder = new StringBuilder();
			try
			{
				XmlDocument val = new XmlDocument();
				val.LoadXml(xmlString);
				XmlNodeList childNodes = ((XmlNode)val).ChildNodes;
				foreach (XmlElement item in childNodes)
				{
					XmlElement xmlelement = item;
					stringBuilder.Append(ProcessXmlElement(xmlelement));
					stringBuilder.Append(Environment.NewLine);
				}
			}
			catch (Exception ex)
			{
				stringBuilder.Append(Environment.NewLine);
				stringBuilder.Append("Exception Parser Error :");
				stringBuilder.Append(ex.Message);
				stringBuilder.Append(Environment.NewLine);
				stringBuilder.Append(xmlString);
			}
			return stringBuilder.ToString();
		}

		private string ProcessXmlElement(XmlElement xmlelement)
		{
			//IL_0021: Unknown result type (might be due to invalid IL or missing references)
			//IL_0027: Expected O, but got Unknown
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0043: Expected O, but got Unknown
			_ = ((XmlNode)xmlelement).ChildNodes;
			string text = "";
			foreach (XmlNode childNode in ((XmlNode)xmlelement).ChildNodes)
			{
				XmlNode val = childNode;
				foreach (XmlNode childNode2 in val.ChildNodes)
				{
					XmlNode val2 = childNode2;
					text = text + val2.Name + ": " + val2.InnerText;
					text += Environment.NewLine;
				}
			}
			return text;
		}
	}
	public class SessionException : Exception
	{
		public SessionException(string message)
			: base(message)
		{
		}
	}
	public class FileValidationException : BaseException
	{
		public FileValidationException(Facility facility, short errorNo)
			: base(facility, errorNo)
		{
		}

		public FileValidationException(Facility facility, short errorNo, string message)
			: base(facility, errorNo, message)
		{
		}

		public FileValidationException(Facility facility, short errorNo, string message, Exception inner)
			: base(facility, errorNo, message, inner)
		{
		}

		public FileValidationException(Facility facility, short errorNo, string message, string filename)
			: base(facility, errorNo, message, filename)
		{
		}

		public FileValidationException(Facility facility, short errorNo, string message, string filename, Exception inner)
			: base(facility, errorNo, message, filename, inner)
		{
		}
	}
}
namespace Cummins.AddressRepresentation
{
	public enum AddressType
	{
		ECM,
		ASAM,
		DISK
	}
	public interface IAddressValue : IComparable
	{
		string Value { get; }

		byte DeviceAddress { get; set; }

		string DisplayId { get; }

		AddressType Type { get; }
	}
}
namespace Cummins
{
	public enum CalibrationDataSourceType
	{
		Unknown,
		Calibration,
		Subfile,
		ImportExport,
		Any
	}
	public class InvalidFileFormatException : ApplicationException
	{
		private string fileName;

		public string FileName
		{
			get
			{
				return fileName;
			}
			set
			{
				fileName = value;
			}
		}

		public InvalidFileFormatException()
		{
			fileName = null;
		}

		public InvalidFileFormatException(string fileName)
		{
			FileName = fileName;
		}
	}
	public class InvalidConfigFileFormatException : InvalidFileFormatException
	{
		public InvalidConfigFileFormatException()
		{
		}

		public InvalidConfigFileFormatException(string fileName)
			: base(fileName)
		{
		}
	}
	public class InvalidCalFileFormatException : InvalidFileFormatException
	{
		public InvalidCalFileFormatException()
		{
		}

		public InvalidCalFileFormatException(string fileName)
			: base(fileName)
		{
		}
	}
	public class InvalidSubFileFormatException : InvalidFileFormatException
	{
		public InvalidSubFileFormatException()
		{
		}

		public InvalidSubFileFormatException(string fileName)
			: base(fileName)
		{
		}
	}
	public class InvalidImpExpFileFormatException : InvalidFileFormatException
	{
		public InvalidImpExpFileFormatException()
		{
		}

		public InvalidImpExpFileFormatException(string fileName)
			: base(fileName)
		{
		}
	}
	public class GTISVersionNotSupportedException : ApplicationException
	{
		private string message;

		public GTISVersionNotSupportedException()
		{
			message = string.Empty;
		}

		public GTISVersionNotSupportedException(string msg)
		{
			message = msg;
		}
	}
	public class GTISVersionMismatchException : ApplicationException
	{
		public GTISVersionMismatchException()
			: base(string.Empty)
		{
		}

		public GTISVersionMismatchException(string msg)
			: base(msg)
		{
		}
	}
	public interface IProduct
	{
		string ProductId { get; }

		string MarketingName { get; }

		string EngineeringName { get; }

		string HardwareName { get; }

		string ProductType { get; }

		byte WordSize { get; }

		string ByteOrder { get; }

		string ECMIdentifier { get; }

		string GTISLevel { get; }

		bool Active { get; }

		string SpeedSupport { get; }

		int NumberOfECMs { get; }

		string ParentProductId { get; }

		string ChildProductId { get; }

		string Group { get; set; }

		string BootGroup { get; }
	}
}
namespace Cummins.EventLog
{
	public enum EventTypes
	{
		Unknown = -1,
		Information,
		Warning,
		Error,
		Unexpected
	}
	public delegate void EventLogMessageHandler(EventTypes evenType, string title, string eventMessage, string deatiledDescription);
	public delegate void EventLogErrorMessageHandler(EventTypes evenType, string title, string eventMessage, string detailedDescription, string errorCode);
	public delegate void EventLogSaveHandler(string filename);
	public interface iEventLog
	{
		event EventLogMessageHandler EventLogMessageFired;

		event EventLogErrorMessageHandler EventLogErrorMessageFired;

		event EventLogSaveHandler EventLogSaveFired;

		void OnEventLogMessageFired(EventTypes eventType, string title, string eventMessage);

		void OnEventLogMessageFired(EventTypes eventType, string title, string eventMessage, string detailedInformation);

		void OnEventLogMessageFired(EventTypes eventType, string title, string eventMessage, Exception exception);

		void OnEventLogErrorMessageFired(EventTypes eventType, string title, string eventMessage, string detailedInformation, string errorCode);

		void OnEventLogErrorMessageFired(EventTypes eventType, string title, string eventMessage, Exception exception, string errorCode);

		void SaveEventLog(string filename);
	}
}
namespace Cummins
{
	public delegate void InterruptEventHandler(object sender, EventArgs eventArgs);
	public interface IProgress
	{
		bool AllowCancel { get; set; }

		string Title { set; }

		int Progress { get; }

		int MaxProgress { get; }

		string ProgressStatus { get; }

		event InterruptEventHandler InterruptEvent;

		event CancelEventHandler CancelProgressEvent;

		void Start();

		void StartModal();

		void Finish();

		void SetProgress(int max, int progress);

		void SetProgress(int progress, string status);

		void SetProgress(string status);

		void SetProgress(string feature, string status);

		void SetProgress(int progress);

		void SetProgress(int max, int progress, string status);

		void SetProgress(int max, int progress, string status, int id);

		void Interrupt(object sender, EventArgs eventArgs);
	}
	public interface iProgressFactory
	{
		IProgress CreateProgress(string title, bool allowCancel);
	}
}
namespace Cummins.Services
{
	public enum OptionType
	{
		SC,
		DO,
		PJ,
		PI,
		EI,
		ES,
		FQ,
		ECM,
		AP,
		PP,
		PW,
		FR,
		FC,
		YB,
		YC,
		YI,
		YQ,
		With_No,
		FQSubFile,
		Invalid
	}
	public enum LastUsedType
	{
		LastConfigurationFile,
		LastCalFile,
		LastSubFile,
		LastSubfileConfiguration,
		LastScreenFile,
		LastScreenFileModule,
		LastScreenFileCalFile,
		LastScreenFileSubFile,
		LastCalibrationDownloadFile,
		LastVisitedFile,
		LastCompareFirstSourceType,
		LastCompareSecondSourceType,
		LastCompareFirstSourceConfigFile,
		LastCompareFirstSourceDataFile,
		LastCompareSecondSourceConfigFile,
		LastCompareSecondSourceCalFile,
		LastDocumentConfigFile,
		LastDocumentSourceFile,
		LastExportConfigFile,
		LastExportSourceFile,
		LastDivideConfigFile,
		LastDivideSourceFile,
		LastDownloadModule,
		LastDownloadConfigFile,
		LastDownloadSourceFile,
		LastUploadModule,
		LastUploadSourceFile,
		LastOverlayMode,
		LastOverlaySourceFileType,
		LastOverlayTargetFileType,
		LastOverlayDestinationFileOption,
		LastFilterFile,
		LastCalEditFilterEnabled,
		LastEditorQuickSearchText,
		LastEditExportFile,
		LastEditExportConfigFile,
		LastScreenFileExport,
		LastOverlaySourceConfigFile,
		LastOverlayTargetConfigFile,
		LastOverlaySourceDataFile,
		LastOverlayTargetDataFile,
		DownloadSaveAndRestore,
		LastOverlaySaveInProductFolder,
		LastOverlayDestinationFilePath,
		LastUsedCustomJ1939FileName,
		IsCustomJ1939FileUsed
	}
	public enum ApplicationSettings
	{
		SpeedUploadReport,
		SpeedDownloadReport,
		SpeedServerDownloadPath,
		SpeedServerUploadPath,
		SpeedReportFormat,
		Adapter,
		CanSpeed,
		Port,
		Protocol,
		BlockTransferChecked,
		J1939DeviceAddr,
		J1939ToolAddr,
		AutoStartChecked,
		AutoProductSelectionChecked,
		AutoUnlockSelectionChecked,
		AutoModuleSelectionChecked,
		AutoCalibrationEditorChecked,
		AutoSubfileEditorChecked,
		AutoModuleMonitorChecked,
		AutoModuleEditorChecked,
		AutoLoggingChecked,
		AutoRestoreProductChecked,
		AutoStopBroadCastChecked,
		DisableAlertsChecked,
		DisplayFaultsChecked,
		DisplayFaultCountChecked,
		DisplayFaultStatusChecked,
		DisplayFaultDescriptionChecked,
		DisplayFaultSourceAddrChecked,
		FaultMonitorRate,
		FaultDatabaseFilename,
		DisplayProdInfoChecked,
		DisplayRunLocChecked,
		DisplaySwitchesChecked,
		LastProduct,
		LogDisplay,
		LogPrefixRR,
		LogPrefixBAM,
		LogPrefixIDL,
		LogFormat,
		LogActiveFaults,
		LogPCTime,
		LogDLASecondsTime,
		MonitorLogAutoNumbering,
		DisplaySaveFileDialog,
		LogRate,
		RecordingMode,
		LogRateUnit,
		TraceDebugFilename,
		TraceDebugLevel,
		TraceDebugCategory,
		TraceDebugEnable,
		MRU,
		MRUProduct,
		CollectionTime,
		AutoReconnect,
		QueryRunLocation,
		AutoRequestChangeLockChecked,
		MonitorModeRequestReceiveChecked,
		MonitorModeBamChecked,
		MonitorModeIdlChecked,
		MonitorShowCommentsChecked,
		IDLTriggerSource,
		IDLTriggerPeriod,
		IDLOnKeyOn,
		IDLStopMode,
		IDLUseCurrentScreen,
		IDLParameterScreenFile,
		IDLRetrievalAtMaxRate,
		IDLRetrievalRate,
		IDLAutoRetreiveBuffer,
		IDLAutoConfigure,
		IDLStopIDLOnMonitorStart,
		DataRefreshRate,
		BamRefreshRate,
		DataRefreshRateUnits,
		ScreenRefreshRate,
		ScreenRefreshRateUnits,
		BamTriggerMode,
		OverlayVerboseReportingEnabled,
		OverlayRangeLimit,
		OverlayReportPrefix,
		OverlayReportFormat,
		OverlayShowMissingParameters,
		OverlayEnableOverwrite,
		OverlayScaledValuesEnabled,
		OverlayUseSourceFileNames,
		GeneralReportFormat,
		VerifyReportFormat,
		VerifyReportPrefix,
		VerifyReportDisplay,
		Version,
		RangeLimit,
		MultiModuleFaultMonitor,
		ParameterFilter,
		SearchCommentsChecked,
		ShowSCOption,
		ShowDOOption,
		ShowPPOption,
		ShowAPOption,
		ShowPIOption,
		ShowPWOption,
		ShowPJOption,
		ShowFROption,
		ShowFCOption,
		ShowEIOption,
		ShowESOption,
		ShowFQOption,
		ShowWith_NoOption,
		ShowFQSubfileOption,
		WorkingMode,
		AutoLoadScreenFile,
		CheckArrayAscendingOrder,
		ConnectionTimeoutEnabled,
		ConnectionTimeoutMinimum,
		ConnectionTimeoutFactor,
		EDMRefreshRate,
		UnlockSecurityMessageCheck,
		DetectionTimeOut,
		ViewAllMessagesChecked,
		WriteThroughScratchPad,
		LastModuleConnectSettingsType,
		PreTrigger,
		PostTrigger,
		DeleteOldestOnMediaFull,
		MaxLogFileSize,
		LogFilePath,
		LogFileName,
		LogFlushFrequency,
		LogFileCreationChoice,
		PromptForOverwrite,
		PromptForMediaFull,
		ExportParamsOnStartup,
		InputFilterFilename,
		OutputExportFilename,
		IDLRefreshRate,
		MonitorModeEDMChecked,
		ParameterSearchText,
		ExpireDate,
		RP1210Vendor,
		RP1210Option,
		RP1210DllName,
		RP1210DeviceID,
		AutoExportFileEditorChecked,
		AppendCheckBoxState,
		MaxPendingRequests,
		ComplexScreenRequestReceiveRefreshRate,
		ComplexScreenRequestReceiveRefreshRateUnits,
		InfoPanelShown,
		EnableUCL_Log,
		InsertEventNumber,
		UCLPreTriggerTime,
		UCLPostTriggerTime,
		DefaultCBFFile,
		J1939_71ParameterSearchText,
		BroadcastParameterSearchText,
		ActivityLogEnable,
		MaxActivityLogFileSize,
		DisplayVersion,
		EnableScripting,
		GreyOutUnchangedData,
		LogFileNameIn24hrTimeFormat,
		AutoPluginChecked,
		AutoPluginFile,
		DisableWrite,
		ChkboxConfigNameToHeaderChecked,
		OverrideCBFFileChecked,
		OverrideCBFFilePath
	}
	public enum ToolFamily
	{
		Engineering,
		FieldEngineering,
		NotInitialize
	}
	public interface IService
	{
		bool IsInitialized { get; }

		void InitializeService();

		void UninitializeService();
	}
	public enum FolderType
	{
		Product,
		ReleasedCalibration,
		UnreleasedCalibration,
		ProductSupport,
		Download,
		Upload
	}
	public interface IDirectoryService : IService
	{
		string RootDirectory { get; }

		string TempDirectory { get; }

		string FolderName(FolderType folderType, string productIdentifier);
	}
	public interface ITraceDebugService : IService
	{
		bool Enabled { get; set; }

		string TraceFileName { get; }

		void InitializeTraceDebugSetting();

		void WriteLine(string message);

		void Write(string message);
	}
	public interface IAppConfigService : IService
	{
		string CBFFileName { get; set; }

		string DeviceSettingsXMLString();

		string DeviceSettingsXMLString(string protocol, string adapter, string port, string j1939DeviceAddress, string j1939ToolAddress, string productID);

		string GetAppSetting(ApplicationSettings applicationSetting);

		string GetAppSetting(ApplicationSettings applicationSetting, ushort entry);

		void SetAppSetting(ApplicationSettings applicationSetting, string value);

		void SetAppSetting(ApplicationSettings applicationSetting, string value, ushort entry);

		bool SaveConfigSetting();

		string GetLastUsedValue(string productId, LastUsedType type);

		string GetLastUsedValue(string productId, LastUsedType type, ushort entry);

		bool SetLastUsedValue(string productId, string newValue, LastUsedType type);

		bool SetLastUsedValue(string productId, string newValue, LastUsedType type, ushort entry);

		void SetDeviceAddress(IAddressValue deviceAddress);
	}
	public enum SecurityCode
	{
		Secured = 0,
		NoRunFromMaster = -23,
		Expired = -25,
		ProtectionNotFound = -28,
		NotProtected = -71,
		NotActivated = -213,
		ActivationError = -999
	}
	public interface ISecurityService : IService
	{
		string SerialNumber { get; }

		List<string> SelectedFeatures { get; }

		ReadOnlyCollection<string> LicensedProducts { get; }

		ReadOnlyCollection<string> LicensedGroups { get; }

		ToolFamily ToolFamily { get; }

		bool UseEncryptedConfigFiles { get; }

		string EncryptedConfigFilesKey { get; }

		event EventHandler LicenseChangedEvent;

		bool IsProductSupported(string productID);

		bool IsFeatureSelected(string featureName);

		bool IsTableEditAllowed(int subfileNumber);

		string GetFeatureValue(string featureName);
	}
	public interface ISecurityCopyControlService : ISecurityService, IService
	{
		DateTime ExpirationDate { get; }

		int UpdateNumber { get; }

		int ValidateActivationCode(string destination, string activationCode);

		int CheckSecurity();

		int MoveProtection(string sourceDirectory, string destinationDirectory);

		string GetMessage(string securityCode);

		int UpdateSecurity(string destinationDir, string activationCode);

		void UpdateLicense(string licenseFilePath);
	}
	public interface ISecurityFlexNetService : ISecurityService, IService
	{
		bool TLLInitializeSegment(string asrFileName);

		bool IsLicenseAvailable();

		string GetVendorString();

		int GetRemainingDays();

		string GetErrorString();

		bool UpdateLicenseByServer(string activationID);

		bool UpdateLicense(string licenseFilePath);

		void UpdateLicense();
	}
	public interface IProductInformationService : IService
	{
		string GTISLevel(string product);

		IProduct GetCalTermProduct(string product);

		IProduct[] GetCaltermProductList();

		string GetProductInformation(string productId, ProductInformationType type);

		List<string> GetChildrenProductIds(string parentProductId);

		bool IsProductIdValid(string productId);

		List<string> GetProductGroup(string ProductID);

		int GetNumberOfMajorOptions(string product);

		OptionType GetMajorOption(string product, int index);

		int GetNumberOfFilesForOption(string product, OptionType option);

		string GetSupportedProductIdFromECMId(string ecmId);

		string GetBootGroup(string productId);
	}
	public enum GTIS45ToolFamily
	{
		Engineering,
		Field_Engineering,
		Production,
		Manufacturing,
		Engineering_Unlock,
		Password_Reset,
		ECM,
		Unknown
	}
	public enum ParameterID
	{
		Password_type = 16785960,
		Password = 16785961,
		Tool_family = 16785962,
		Tool_instance = 16785965,
		Tool_version = 16785964,
		Tool_id = 16785963
	}
	public enum SessionDataTable
	{
		ClipSessionConfiguration,
		SessionParam
	}
	public interface IDatalinkSessionService : IService
	{
		string SessionSettingXmlString { get; }

		string SessionContextDataXmlString { get; }

		string SessionConfigurationXmlString { get; }

		XmlNode GetSessionContextDataNode();

		XmlNode GetSessionSetting();

		XmlNode GetSessionConfigurationNode();

		bool Save(string filename);

		bool SetSessionContext(GTIS45ToolFamily toolFamily);

		bool SetSessionContext(string sessionComment, string sessionData, string sessionId);

		GTIS45ToolFamily GetCurrentToolFamily();

		DataTable GetSessionDataTable(SessionDataTable table);
	}
	public interface IActivityLogService : IService
	{
		bool Enabled { get; set; }

		bool Init(string logName, uint maxSize, Dictionary<EToolSetup, string> toolInfo);

		bool WriteLogEntry(Dictionary<ELogEntryField, string> logEntry);

		bool Shutdown();

		bool CacheLogContext(Dictionary<ELogEntryField, string> entryInfo);
	}
	public interface IDigitalSignatureService : IService
	{
		bool VerifyXml(string xmlFilename);

		bool VerifyFileSignature(string filename);
	}
}
namespace Cummins
{
	public interface iSession
	{
		iProgressFactory ProgressFactory { get; set; }

		iEventLog EventLog { get; }

		string DataPath { get; set; }

		string AppConfigurationFile { get; set; }

		IAppConfigService AppConfigService { get; }

		void CheckSession();
	}
}
namespace Cummins.Services
{
	public interface iSessionService : IService
	{
		iSession CurrentSession { get; }

		Guid CreateSession();

		void TerminateSession(Guid sessionId);

		iSession GetSession(Guid id);
	}
}
namespace Cummins
{
	public class SPN
	{
		public string PGNName;

		public string Name;

		public int Number = -1;

		public string Value;

		public string Units;

		public string FullName => FigureFullName(PGNName, Name);

		public static string FigureFullName(string pgnName, string spnName)
		{
			return pgnName + "." + spnName;
		}
	}
	public class PGN
	{
		private string _pgnName;

		private uint _number;

		private List<SPN> _spns;

		public string Name
		{
			get
			{
				return _pgnName;
			}
			set
			{
				_pgnName = value;
			}
		}

		public uint Number
		{
			get
			{
				return _number;
			}
			set
			{
				_number = value;
			}
		}

		public List<SPN> SPNs
		{
			get
			{
				return _spns;
			}
			set
			{
				_spns = value;
			}
		}
	}
	public class PGNList
	{
		private ushort _sourceAddress;

		private ushort _destinationAddress;

		private uint _timestamp;

		private List<PGN> _pgns;

		public ushort SourceAddress
		{
			get
			{
				return _sourceAddress;
			}
			set
			{
				_sourceAddress = value;
			}
		}

		public ushort DestinationAddress
		{
			get
			{
				return _destinationAddress;
			}
			set
			{
				_destinationAddress = value;
			}
		}

		public uint TimeStamp
		{
			get
			{
				return _timestamp;
			}
			set
			{
				_timestamp = value;
			}
		}

		public List<PGN> PGNs
		{
			get
			{
				if (_pgns == null)
				{
					_pgns = new List<PGN>();
				}
				return _pgns;
			}
			set
			{
				_pgns = value;
			}
		}
	}
	public class ProtocolNotSupportedException : BaseException
	{
		private string productId;

		private short errorNumber;

		public string ProductID => productId;

		public ProtocolNotSupportedException(string message, short errorNo, string productId)
			: base(Facility.ApplicationServices, errorNo, message)
		{
			this.productId = productId;
			errorNumber = errorNo;
		}
	}
	public class ResourceException : BaseException
	{
		public ResourceException(Facility facility, short errId)
			: base(facility, errId)
		{
		}

		public ResourceException(Facility facility, short errId, string message)
			: base(facility, errId, message)
		{
		}

		public ResourceException(Facility facility, short errId, string message, Exception inner)
			: base(facility, errId, message, inner)
		{
		}

		public ResourceException(Facility facility, short errorNo, string message, string resourceName)
			: base(facility, errorNo, message, resourceName)
		{
		}

		public ResourceException(Facility facility, short errorNo, string message, string resourceName, Exception inner)
			: base(facility, errorNo, message, resourceName, inner)
		{
		}
	}
}
namespace Cummins.Exceptions
{
	public class LicenseFileException : BaseException
	{
		public LicenseFileException(short erroNo)
			: base(Facility.ApplicationServices, erroNo)
		{
		}

		public LicenseFileException(string message, short errorNo)
			: base(Facility.ApplicationServices, errorNo, message)
		{
		}

		public LicenseFileException(string message, short errorNo, Exception inner)
			: base(Facility.ApplicationServices, errorNo, message, inner)
		{
		}
	}
	public class FeatureNotSupportedException : BaseException
	{
		public FeatureNotSupportedException(short erroNo)
			: base(Facility.ApplicationServices, erroNo)
		{
		}

		public FeatureNotSupportedException(string message, short errorNo)
			: base(Facility.ApplicationServices, errorNo, message)
		{
		}

		public FeatureNotSupportedException(string message, short errorNo, Exception inner)
			: base(Facility.ApplicationServices, errorNo, message, inner)
		{
		}
	}
}
namespace Cummins.CalToolsLib
{
	public enum SelectableFeatures
	{
		IgnoreRangeLimits,
		TemporaryWritestoSecureModules
	}
}
namespace Cummins
{
	public class ServiceManagerException : BaseException
	{
		public ServiceManagerException(Facility facility, short errId)
			: base(facility, errId)
		{
		}

		public ServiceManagerException(Facility facility, short errId, string message)
			: base(facility, errId, message)
		{
		}

		public ServiceManagerException(Facility facility, short errId, string message, Exception inner)
			: base(facility, errId, message, inner)
		{
		}

		public ServiceManagerException(Facility facility, short errorNo, string message, Type serviceType)
			: base(facility, errorNo, message, serviceType.ToString())
		{
		}

		public ServiceManagerException(Facility facility, short errorNo, string message, Type serviceType, Exception inner)
			: base(facility, errorNo, message, serviceType.ToString(), inner)
		{
		}
	}
}
