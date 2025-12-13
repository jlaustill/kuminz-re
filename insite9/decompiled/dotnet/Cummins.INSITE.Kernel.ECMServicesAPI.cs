using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using GpOo02qu3LicxVqGjU;
using JtJw5Fp1ACDjpI5msD;
using MCHBv7UBQSPXUA9P88;
using OHITIbwEDvYfcFsFpw;
using cD5SNHrMKaHqURMyT1;

[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: SuppressIldasm]
[assembly: AssemblyKeyName("")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTitle("Cummins.INSITE.Kernel.ECMServicesAPI")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyProduct("Cummins.INSITE.Kernel.ECMServicesAPI")]
[assembly: Guid("dc6d7399-0bf4-4247-9c4a-5cdbff64b067")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: ComVisible(true)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace Uy86jILQBmZKoe0yFy
{
	internal static class I7dBHkhSda7EBYOXr8
	{
	}
}
namespace Cummins.INSITE.Kernel.ECMServicesAPI
{
	public struct PasswordsStruct
	{
		[CompilerGenerated]
		private bool Q10tNAiMA;

		[CompilerGenerated]
		private bool s6ThnZg3m;

		public bool IsOEMAccessible
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return Q10tNAiMA;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				Q10tNAiMA = value;
			}
		}

		public bool IsOEM2Accessible
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return s6ThnZg3m;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				s6ThnZg3m = value;
			}
		}
	}
	[Guid("20B60AD1-7829-4404-AD2F-F0F38F433564")]
	[ComVisible(true)]
	public interface IImageService
	{
		int Id { get; }

		int ECUId { get; set; }

		event EventHandler<ImageProcessEventArgs> ImageProcessingStatus;

		event EventHandler<TemplateTransferEventArgs> TemplateTransferStatus;

		ImageCreationResult CreateImage(string imageFilePath, string PCID);

		TemplateTransferResult TransferTemplateToECU(string templateFilePath, PasswordsStruct Passwords, out IParameterGroup unwrittenParameterIds);

		void CancelImageCreation();
	}
	[Serializable]
	public class ECMServicesException : Exception
	{
		private static readonly int ET7LdBHkS;

		private static readonly int Wa78EBYOX;

		private static readonly int s84Uy86jI;

		private static readonly int VBmEZKoe0;

		private ECMServicesErrorCodes BFywHVlkf;

		public ECMServicesErrorCodes ErrorCode
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return BFywHVlkf;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMServicesException()
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			this..ctor(ET7LdBHkS, string.Empty, null);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMServicesException(ECMServicesErrorCodes errorCode)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			this..ctor(errorCode, string.Empty, null);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMServicesException(ECMServicesErrorCodes errorCode, string message)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			this..ctor(errorCode, message, null);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMServicesException(ECMServicesErrorCodes errorCode, string message, Exception innerException)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor(message + UVlkfJ8hxa0DXOaoKF.vhxia0DXO(errorCode), innerException);
			BFywHVlkf = errorCode;
			base.HResult = convertToHRESULT(errorCode);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMServicesException(int gtisErrorCode)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			this..ctor(gtisErrorCode, string.Empty, null);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMServicesException(int gtisErrorCode, string message)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			this..ctor(gtisErrorCode, message, null);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMServicesException(int gtisErrorCode, string message, Exception innerException)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor(message, innerException);
			BFywHVlkf = ECMServicesErrorCodes.ErrorFromECU;
			base.HResult = convertToHRESULT(gtisErrorCode);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected ECMServicesException(SerializationInfo info, StreamingContext context)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor(info, context);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected int convertToHRESULT(ECMServicesErrorCodes errorCode)
		{
			if (errorCode == ECMServicesErrorCodes.NoError)
			{
				return Wa78EBYOX;
			}
			int num = s84Uy86jI + Convert.ToInt32(errorCode);
			return int.MinValue + num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected int convertToHRESULT(int ecuErrorCode)
		{
			if (ecuErrorCode == Wa78EBYOX)
			{
				return Wa78EBYOX;
			}
			int num = VBmEZKoe0 + Convert.ToInt32(ecuErrorCode);
			return int.MinValue + num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static ECMServicesException()
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			ET7LdBHkS = -16389;
			Wa78EBYOX = 0;
			s84Uy86jI = 10000;
			VBmEZKoe0 = 20000;
		}
	}
}
namespace MCHBv7UBQSPXUA9P88
{
	internal static class UVlkfJ8hxa0DXOaoKF
	{
		private static Dictionary<ECMServicesErrorCodes, string> noKqF3CHB;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static UVlkfJ8hxa0DXOaoKF()
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			noKqF3CHB = new Dictionary<ECMServicesErrorCodes, string>();
			noKqF3CHB.Add(ECMServicesErrorCodes.NoError, OWwpBsspLF0Q0PqPbZ.RZBcZQRG7(0));
			noKqF3CHB.Add(ECMServicesErrorCodes.DatalinkError, OWwpBsspLF0Q0PqPbZ.RZBcZQRG7(92));
			noKqF3CHB.Add(ECMServicesErrorCodes.DatalinkTimeout, OWwpBsspLF0Q0PqPbZ.RZBcZQRG7(192));
			noKqF3CHB.Add(ECMServicesErrorCodes.ParameterReadBlocked, OWwpBsspLF0Q0PqPbZ.RZBcZQRG7(288));
			noKqF3CHB.Add(ECMServicesErrorCodes.ParameterWriteBlocked, OWwpBsspLF0Q0PqPbZ.RZBcZQRG7(426));
			noKqF3CHB.Add(ECMServicesErrorCodes.ValueOutOfRange, OWwpBsspLF0Q0PqPbZ.RZBcZQRG7(566));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string vhxia0DXO(ECMServicesErrorCodes P_0)
		{
			string result = string.Empty;
			if (noKqF3CHB.ContainsKey(P_0))
			{
				result = noKqF3CHB[P_0];
			}
			return result;
		}
	}
}
namespace Cummins.INSITE.Kernel.ECMServicesAPI
{
	[Guid("3AF436C6-06C9-4429-9FC4-760BC6562F31")]
	[ComVisible(true)]
	public enum ImageCreationResult
	{
		Success,
		NoDiskSpace,
		ECUNotInApplication,
		UnknownFailure,
		Cancelled,
		Interrupted
	}
	[ComVisible(true)]
	[Guid("B5D78A53-065D-4324-9BC6-9F990884D5D6")]
	public enum TemplateTransferResult
	{
		Success,
		TemplateNotWriteable,
		ECUNotInApplication,
		TemplateLoadFailure,
		UnknownFailure,
		EngineSpeedDetected,
		Interrupted
	}
	[Guid("F140D577-3A93-4F02-BF4F-D39498B611C8")]
	[ComVisible(true)]
	public enum ImageProcessStatus
	{
		InProgress = 1,
		Succeeded,
		Failed
	}
	[Guid("04EDB756-D934-4DC8-B88F-CB74A56FA194")]
	[ComVisible(true)]
	public enum TemplateTransferStatus
	{
		InProgress = 1,
		Succeeded,
		Failed
	}
	[Guid("E37F449A-5D49-45B1-8FB9-DEE83EBF77F0")]
	[ComVisible(true)]
	public enum ImageSectionInProcess
	{
		Header,
		Parameters,
		Arrays,
		SpecialData,
		FileSave
	}
	[Guid("57A1688E-42C8-4143-BD1B-406B57ABFBA2")]
	[ComVisible(true)]
	public interface IECMServices
	{
		IMetadataServices MetadataServices { get; }

		IDataServices DataServices { get; }

		IConnections Connections { get; }

		IMonitorServices MonitorServices { get; }

		IImageServices ImageServices { get; }

		void Initialize(string metadataDatabasePath, string xmlResourcesFolderPath, string iclDatafilesFolderPath, string configfilePath, string fnpDatabasePath, string dynamicEnumXmlPath);
	}
	[ComVisible(true)]
	[Guid("33D3E096-83D8-4B7E-8CDE-1CB6F12B37C2")]
	public interface ICumminsECUs : ICollection<ICumminsECU>, IList<ICumminsECU>, IEnumerable, IEnumerable<ICumminsECU>
	{
		new int Count { get; }

		new ICumminsECU this[int index] { get; }
	}
	[ComVisible(true)]
	[Guid("179FB785-20D6-4965-8989-DBD2F5E1B32B")]
	public interface IECU
	{
		int Id { get; }

		string Name { get; }

		int ECUType { get; }

		int ECUDetectType { get; }

		bool CumminsECU { get; }

		string ProductId { get; }

		string ECUId { get; }

		int SourceAddress { get; }

		RunLocation RunLocation { get; }

		GTISLevel GTISLevel { get; }

		ECUHierarchy HierarchyState { get; }

		double ECMVersion { get; }

		string ECMPhase { get; }

		bool IsConnected { get; }
	}
	[ComVisible(true)]
	[Guid("96101B1B-5D09-42A8-9BDC-98D0EDF6693F")]
	public interface ICumminsECU : IECU
	{
		int HarnessKeyECMInstance { get; }

		int HarnessKeyStatus { get; }

		string ServiceECMMarketingName { get; }

		bool Visible { get; }
	}
	[ComVisible(true)]
	[Guid("D7ACCB06-479D-4937-962A-20373D31B22F")]
	[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
	public interface IConnectionEvents
	{
		[DispId(1)]
		void OnConnectionStatusChanged(int connectionId, ConnectionStatus status);
	}
	[ComVisible(false)]
	public delegate void ConnectionStatusChangedDelegate(int connectionId, ConnectionStatus status);
	[ComVisible(false)]
	public class ConnectionStatusEventArgs : EventArgs
	{
		private readonly int a7BAQSPXU;

		private readonly ConnectionStatus i9PD88nuV;

		public int ConnectionId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return a7BAQSPXU;
			}
		}

		public ConnectionStatus Status
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return i9PD88nuV;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ConnectionStatusEventArgs(int connectionId, ConnectionStatus status)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor();
			a7BAQSPXU = connectionId;
			i9PD88nuV = status;
		}
	}
	[ComVisible(true)]
	[Guid("EC8832B2-92CB-47EC-9E1B-B83ED02CA42F")]
	public interface IParameterDefinition
	{
		int Id { get; }

		string Name { get; }

		int Decimal { get; }

		int Precision { get; }

		int UnitId { get; }

		int UnitFamilyId { get; }

		int EnumerationId { get; }

		ParameterValueType ValueType { get; }
	}
	[Guid("404534A2-FADC-479A-ACC7-A8BDB9FAF557")]
	[ComVisible(true)]
	public interface IParameterDefinitions
	{
		IParameterDefinition GetParameterDefinition(int ecuType, int parameterId);

		bool IsParameterSupported(int ecuType, int parameterId);

		bool IsParameterSupportedInArray(int ecuType, int parameterId, int arrayId);
	}
	[Guid("A678E2C5-96BD-4C18-B929-799915687B8D")]
	[ComVisible(true)]
	public interface IMetadataServices
	{
		IEnumerations Enumerations { get; }

		IUnitDefinitions UnitDefinitions { get; }

		IParameterDefinitions ParameterDefinitions { get; }

		IUsageDefinitions UsageDefinitions { get; }

		IArrayDefinitions ArrayDefinitions { get; }

		IFeatureDefinitions FeatureDefinitions { get; }

		IProductInformation GetProductInformation(string productId, int harnessKeyECMInstance = 0);

		void SetVersion(int connectionId, int ecuId);

		void SetPhase(int connectionId, int ecuId);

		bool IsECUSupported(string ecuId, double ecmVersion);

		IProductInformation GetProductInformation(int ecuType);

		IProductInformation GetProductInformation(string ecmPhase, double ecmVersion, int detectType, string productId, string ecuId, int harnessKeyECMInstance = 0, bool bSimulatorType = false);

		int GetDetectTypeForECUType(int ECUType);

		IParameterGroup GetParametersForECU(int detectType);

		IParameterGroup GetArraysForECU(int detectType);

		ISimulatorInformations GetAllSimulators();

		ISpecialFeatureInformations GetSupportedSpecialFeatures(int connectionId, int ecuId);

		IDiagnosticTestInformations GetSupportedDiagnosticTests(int connectionId, int ecuId);

		IPrintableFeatureInformations GetSupportedPrintableFeatures(int connectionId, int ecuId);

		IPrintableFeatureInformations GetSupportedTemplatePrintableFeatures();

		IFaultInformation GetFaultInformation(int ECUType, int faultCode);

		IParameterGroup GetDynamicEnumerationInfo();

		EnumerationValueType GetEnumerationValueType(int ecuId, int ecuType, int connectionId, int parameterID, string rawValue);
	}
	[Guid("8F60E737-2677-4B4E-AC8D-7F65360CA5F7")]
	[ComVisible(true)]
	public interface IConnection
	{
		int ConnectionId { get; }

		ConnectionType ConnectionType { get; }

		IConnectionConfiguration ConnectionConfiguration { get; }

		string FirmwareVersion { get; }

		bool IsConnected { get; }

		string Name { get; set; }

		ISystems Systems { get; }

		bool CanDisconnect { get; }

		event EventHandler<ConnectionStatusEventArgs> ConnectionStatusChanged;

		int RegisterDisconnectCallback(IDisconnectCallback callback);

		void UnregisterDisconnectCallback(int cookie);

		void Connect(IConnectionConfiguration connectionConfiguration);

		void Disconnect(bool forceDisconnect, bool fireEvent = true);

		void Reinitialize();

		void SuspendCommunication(int ecuId);

		void ResumeCommunication(int ecuId);

		void ConnectSystem(object ModuleAddressesInSystem);
	}
	[ComVisible(true)]
	[Guid("D2201EAC-F268-4F6E-ACBA-954588243DCA")]
	public interface IFaultInformation
	{
		int FaultCode { get; }

		int ECUType { get; }

		int ResourceId { get; }

		int SourceIdentifier { get; }

		int ParameterIdentifier { get; }

		int FailureModeIndicator { get; }

		int FailureModeIndicator2 { get; }

		int SuspectParameterName { get; }

		string Lamp { get; }
	}
	[ComVisible(true)]
	[Guid("41B83712-5AC3-4778-8160-1216F01BDD63")]
	public interface IDisconnectCallback
	{
		bool AllowDisconnect(int connectionId);

		void HandleDisconnect(int connectionId);
	}
	[Flags]
	[Guid("423D6B23-70CA-4F35-9141-0C86DBAF4E07")]
	[ComVisible(true)]
	public enum TriggerType
	{
		None = 0,
		ValueChanged = 1,
		Periodic = 2,
		Custom = 4,
		All = 7
	}
	public interface IMonitorService
	{
		int Id { get; }

		ICustomTriggerManager CustomTriggerManager { get; }

		ILogger Logger { get; }

		bool IsActive { get; }

		event EventHandler<RawValueUpdatedEventArgs> RawValueUpdated;

		event EventHandler<DisplayValueUpdatedEventArgs> DisplayValueUpdated;

		void AddParameter(int parameterId, int ECUId, int samplingRate, TriggerType triggerType);

		IList<int> AddGroup(IParameterGroup groupForMonitoring, int ECUId, int samplingRate, TriggerType triggerType);

		void RemoveParameter(int parameterId, int ECUId);

		void RemoveGroup(IParameterGroup monitoredParameters, int ECUId);

		void StartMonitoring();

		void StopMonitoring();

		void RemoveGroupForModule(int ECUId);
	}
	[ComVisible(true)]
	[Guid("D27B9D91-6EF0-433A-B02D-24D3CB3D3251")]
	public interface IImageServices
	{
		int Count { get; }

		IImageService Add(int connectionId);

		void Remove(int imageServiceId);

		IImageService Get(int imageServiceId);

		IOfflineImageService Add(string imageFilePath);

		IOfflineTemplateService AddTemplateService(string templateFilePath);
	}
	[Guid("E4E23B57-AAFF-4E8D-BC18-F564B149B840")]
	[ComVisible(true)]
	public interface IDataService
	{
		int Id { get; }

		event Action<int> GroupReadProgressStatus;

		bool IsReadBlocked(int parameterId);

		bool IsWriteBlocked(int parameterId);

		bool IsWritable(int parameterId);

		IParameter ReadParameter(int parameterId, bool forceRead = true);

		IArray ReadArray(int arrayId, bool forceRead = true);

		IList<IArray> ReadArrays(IList<int> arrayIds, bool forceRead = true);

		IGroup ReadGroup(IParameterGroup groupForRead, bool forceRead = true);

		void CancelGroupRead();

		void WriteParameter<T>(int parameterId, T paramValue, bool valueIsRaw, bool saveChanges);

		void WriteParameter(int parameterId, object paramValue, bool valueIsRaw, bool saveChanges);

		IGroup WriteGroup(IParameterValueGroup groupForWrite, bool valuesAreRaw, bool saveChanges);

		int ExecuteOperation(int operationId, IParameterValueGroup inputArgs, out IGroup outParams);

		void SetDesiredValue<T>(int parameterId, T desiredValue, bool valueIsRaw = false);

		void ClearDesiredValue(int parameterId);

		T GetDesiredValue<T>(int parameterId, bool rawValue = false);

		IList<IDependencyDefinition> CheckDependencies(int parameterId);
	}
	[ComVisible(true)]
	[Guid("C00F6372-77F4-427E-B2CC-B2DB67542DD8")]
	public interface ISystemDataService : IDataService
	{
	}
	[ComVisible(true)]
	[Guid("56CAB64F-9D10-47FF-B529-D2D4C028C1E6")]
	public interface ISessionInfo
	{
		string SessionInformation { get; set; }

		string Password { set; }

		PasswordType PasswordType { get; set; }

		int EncryptionLevel { get; set; }

		uint ToolFamily { get; set; }

		uint ToolId { get; set; }

		uint ToolInstance { get; set; }

		uint ToolVersion { get; set; }
	}
	[Guid("32242F1D-89AB-4A7A-B0DE-A0419BAF1041")]
	[ComVisible(true)]
	public interface IECUs : ICollection<IECU>, IList<IECU>, IEnumerable, IEnumerable<IECU>
	{
		new int Count { get; }

		new IECU this[int index] { get; }
	}
	[Guid("321489F1-9B9C-4DFA-A7A1-6DB917A212A9")]
	[ComVisible(true)]
	public enum CustomTriggerOperator
	{
		Equal,
		LessThan,
		LessThanOrEqual,
		GreaterThan,
		GreaterThanOrEqual,
		NotEqual
	}
	[Guid("7C10D02F-951C-4617-AAF6-FF12B42AD371")]
	[ComVisible(true)]
	public enum CustomTriggerOperandType
	{
		Value,
		Parameter
	}
	[Guid("8B4A7B10-4C62-48A6-9B4E-C07285E71526")]
	[ComVisible(true)]
	public interface ICustomTriggers : ICollection<ICustomTrigger>, IList<ICustomTrigger>, IEnumerable, IEnumerable<ICustomTrigger>
	{
	}
	[ComVisible(true)]
	[Guid("F991C0B5-F231-4892-9B59-CE7C709E5317")]
	public interface ICustomTrigger
	{
		int Id { get; }

		int ParameterId { get; }

		int ECUId { get; }

		CustomTriggerOperator Operator { get; }

		CustomTriggerOperandType OperandType { get; }

		object OperandValue { get; }

		int OperandParameterId { get; }
	}
	[Guid("EC95040A-47E8-46BE-9503-D651CA209C0C")]
	[ComVisible(true)]
	public enum RunLocation
	{
		Unknown,
		Default,
		Development,
		Boot,
		Application
	}
	[ComVisible(true)]
	[Guid("E109CDBF-905F-41D1-B71A-9E4096FECDC2")]
	public enum ParameterValueType
	{
		Unknown = -1,
		Array,
		Block,
		Enumeration,
		Decimal,
		Integer,
		String,
		Structure,
		DateTime
	}
	[ComVisible(true)]
	[Guid("59AE43FF-556E-416A-9F03-5144189282F3")]
	public enum ConnectionStatus
	{
		ConnectionIsValid,
		ConnectionEstablished,
		ConnectionTerminated,
		ConnectionToDatalinkLost,
		ConnectionToECULost,
		ConnectionReestablished,
		ConnectionSuspended,
		ConnectionResumed,
		ECUHasChanged,
		ECUCountHasChanged,
		SnHasChanged
	}
	[Guid("B0C88CE8-9849-43AD-8722-5F59F6ECE104")]
	[ComVisible(true)]
	public enum ConnectionType
	{
		Physical,
		Simulator,
		Image
	}
	[ComVisible(true)]
	[Guid("B87E0BA4-8616-4FF6-9FCC-82591825810D")]
	public enum PasswordType
	{
		Master = 1,
		OEM = 2,
		Adjustable = 3,
		Reset = 4,
		OEM2 = 6
	}
	[ComVisible(true)]
	[Guid("CD754D55-B3F3-4888-A354-4CF729412261")]
	public enum ToolFamily
	{
		Production
	}
	[ComVisible(true)]
	[Guid("543A1C82-8D8B-4E11-984A-507856386202")]
	public enum DLAType
	{
		INLINE_II = 1,
		INLINE = 4,
		RP1210 = 11
	}
	[Guid("3B226CAA-BFB1-4222-B70D-AB075A9809BB")]
	[ComVisible(true)]
	public enum ConnectionProtocol
	{
		J1939 = 0,
		J1708 = 2
	}
	[Guid("BB50D2F3-6C5F-455E-9B91-FDF66EA370BE")]
	[ComVisible(true)]
	public enum ECUHierarchy
	{
		Unknown,
		Standalone,
		Parent,
		Child,
		ParentAndChild
	}
	[Guid("F3E1DB81-CCEC-454E-BF6B-0CF6800B5231")]
	[ComVisible(true)]
	public enum GTISLevel
	{
		Unknown = -1,
		NonGTIS,
		Legacy,
		GTIS_20,
		GTIS_38,
		GTIS_45,
		GTIS_46
	}
	[Guid("15358242-945F-4D9F-8F78-886A57997879")]
	[ComVisible(true)]
	public enum EngineType
	{
		Automotive,
		Industrial
	}
	[ComVisible(true)]
	[Guid("FC434E57-4C67-43DB-A986-12279BA0D2F8")]
	public enum EnumerationValueType
	{
		Supported,
		NotSupported,
		NotApplicable
	}
	[Guid("752F0F9D-3B57-4363-96F8-78F6C6DFB3A5")]
	[ComVisible(true)]
	public interface IArrayDefinition
	{
		int Id { get; }

		int DetectType { get; }

		string Name { get; }

		IParameterGroup Parameters { get; }
	}
	[ComVisible(true)]
	[Guid("F49FDA97-8B06-473F-8410-943EB7619D67")]
	public interface IArrayDefinitions
	{
		IArrayDefinition GetArrayDefinition(int arrayId, int detectType);
	}
	[Guid("D0ECEF89-2E22-48C5-B084-A5D6520B6C42")]
	[ComVisible(true)]
	public interface IProductInformation
	{
		string ProductId { get; }

		int ECUType { get; }

		int DetectType { get; }

		int SystemType { get; }

		int EngineProgramType { get; }

		EngineType EngineType { get; }

		GTISLevel GTISLevel { get; }
	}
	[Guid("02806E14-1CD3-4E3A-835B-93D791547A8F")]
	[ComVisible(true)]
	public interface ILogger
	{
		string LogFilePath { get; set; }

		bool IsActive { get; }

		int AutoWriteFrequency { get; set; }

		event EventHandler LowDiskSpace;

		void StartLogging();

		void StopLogging();

		void SaveLogFile(bool clearCachedData);

		void SetHeaderItem(string itemName, string itemValue);

		void SetHeaderItems(IDictionary<string, string> headerItems);

		void AddEventMarker(int eventId);

		void AddEventDescription(int eventId, string description);
	}
	[ComVisible(true)]
	[Guid("AB5452B0-79D4-4A62-B54F-1C81B8380973")]
	[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
	public interface IImageEvents
	{
		void OnImageProcess(ImageProcessStatus status, int percentComplete, ImageSectionInProcess sectionInProcess);
	}
	[ComVisible(false)]
	public class ImageProcessEventArgs : EventArgs
	{
		private ImageProcessStatus ObhsmyglE;

		private int QD8pe22FH;

		private ImageSectionInProcess yTIebEDvY;

		public ImageProcessStatus Status
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ObhsmyglE;
			}
		}

		public int PercentComplete
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return QD8pe22FH;
			}
		}

		public ImageSectionInProcess SectionInProcess
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return yTIebEDvY;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ImageProcessEventArgs(ImageProcessStatus status, int percentComplete, ImageSectionInProcess sectionInProcess)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor();
			ObhsmyglE = status;
			QD8pe22FH = percentComplete;
			yTIebEDvY = sectionInProcess;
		}
	}
	[ComVisible(true)]
	[Guid("5F1D888E-ADEB-4447-9D45-0DE528609270")]
	public interface IParameter
	{
		int Id { get; }

		string Name { get; }

		ParameterValueType ValueType { get; }

		string DisplayValue { get; }

		object RawValue { get; }

		int UnitId { get; }

		int UnitsFamilyId { get; }

		string MaxDisplayValue { get; }

		string MinDisplayValue { get; }

		ECMServicesErrorCodes LastReadStatus { get; }

		ECMServicesErrorCodes LastWriteStatus { get; }

		T RawValueAs<T>();
	}
	[Guid("CBC04FC4-81AC-4DDB-99C4-90E8DCE5BF98")]
	[ComVisible(true)]
	public interface IParameterGroup : ICollection<int>, IList<int>, IEnumerable, IEnumerable<int>
	{
		int Id { get; }

		new int Count { get; }

		new int this[int index] { get; set; }

		new void Add(int parameterId);

		void Add(IList<int> parameterIds);

		new void Clear();

		new bool Contains(int parameterId);

		new bool Remove(int parameterId);

		new void RemoveAt(int index);
	}
	[ComVisible(true)]
	[Guid("D1AAC18B-868B-46A0-954A-09DC6FE6422B")]
	public interface IParameterValueGroup : ICollection<KeyValuePair<int, object>>, IDictionary<int, object>, IEnumerable, IEnumerable<KeyValuePair<int, object>>
	{
		new int Count { get; }

		new object this[int parameterId] { get; set; }

		new void Add(int parameterId, object value);

		new bool ContainsKey(int parameterId);

		new bool Remove(int parameterId);
	}
	[ComVisible(true)]
	[Guid("0529E8CA-3FEA-458D-92FC-EFD7F0F141A0")]
	public interface IGroupBuilder
	{
		IParameterGroup CreateParameterGroup();

		IParameterGroup CreateParameterGroup(IEnumerable<int> paramCollection);

		IParameterValueGroup CreateParameterValueGroup();

		IParameterValueGroup CreateParameterValueGroup(IDictionary<int, object> paramCollection);
	}
	[ComVisible(true)]
	[Guid("20BB402F-BFCA-4940-9E19-0A6C24F5C95A")]
	public interface IPrintableFeatureInformation
	{
		int Id { get; }

		int ResourceId { get; }

		string ToolFormatFileName { get; }

		Guid FeatureGUID { get; }

		Guid ObjectGUID { get; }

		string AdditionalXml { get; }

		int I18NRequired { get; }

		string ObjectName { get; }
	}
	[ComVisible(true)]
	[Guid("735409A6-18CD-4520-9B8C-97F3F9871368")]
	public interface IPrintableFeatureInformations : ICollection<IPrintableFeatureInformation>, IList<IPrintableFeatureInformation>, IEnumerable, IEnumerable<IPrintableFeatureInformation>
	{
		new int Count { get; }

		new IPrintableFeatureInformation this[int index] { get; }
	}
	[Guid("5B708A2D-A81C-457C-94DC-22113E20CF1B")]
	[ComVisible(true)]
	public interface IECUDataService : IDataService
	{
		int ECUId { get; set; }
	}
	[ComVisible(true)]
	[Guid("7A29AFC5-D059-4A23-A0A9-B7CB6DC8B429")]
	public interface IStructure : IParameter
	{
		IParameter this[int index] { get; }

		IParameter this[string parameterId] { get; }

		int FieldCount { get; }

		IEnumerable<int> ParameterIds { get; }
	}
	[Guid("E83D0710-BD16-4FAE-B501-3E464FF7CBF5")]
	[ComVisible(true)]
	public interface IDataServices : ICollection<IDataService>, IList<IDataService>, IEnumerable, IEnumerable<IDataService>
	{
		new int Count { get; }

		IECUDataService AddECUDataService(int connectionId);

		ISystemDataService AddSystemDataService(int connectionId);

		void Remove(int dataServiceId);

		IDataService Get(int dataServiceId);
	}
	[Guid("52F6195F-9546-4345-AD19-0387F6714440")]
	[ComVisible(true)]
	public interface IOfflineTemplateService
	{
		string TransformTemplateForPrinting();
	}
	[ComVisible(true)]
	[Guid("B1884330-5D68-4714-A7F7-8CE27AB09CAA")]
	public interface IDependencyDefinition
	{
		int AccessType { get; set; }

		int DependencyParameterID { get; set; }

		int ID { get; set; }

		int IsBlocking { get; set; }

		int ParameterID { get; set; }

		int RuleType { get; set; }
	}
	[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
	[ComVisible(true)]
	[Guid("277C5992-DFFF-43DD-9868-57D719B6D89C")]
	public interface IMonitorEvents
	{
		void OnRawValueUpdated(int parameterId, int ecuId, object value, DateTime timestamp, TriggerType triggerType, int customTriggerId);

		void OnDisplayValueUpdated(int parameterId, int ecuId, string displayValue, DateTime timestamp, TriggerType triggerType, int customTriggerId);
	}
	[ComVisible(false)]
	public abstract class ValueUpdatedEventArgs : EventArgs
	{
		protected readonly int _parameterId;

		protected readonly int _ecuId;

		protected readonly DateTime _timestamp;

		protected readonly TriggerType _triggerType;

		protected readonly int _customTriggerId;

		public int ParameterId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _parameterId;
			}
		}

		public int ECUId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _ecuId;
			}
		}

		public DateTime Timestamp
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _timestamp;
			}
		}

		public TriggerType TriggerType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _triggerType;
			}
		}

		public int CustomTriggerId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _customTriggerId;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected ValueUpdatedEventArgs(int parameterId, int ecuId, DateTime timestamp, TriggerType triggerType, int customTriggerId)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor();
			_parameterId = parameterId;
			_ecuId = ecuId;
			_timestamp = timestamp;
			_triggerType = triggerType;
			_customTriggerId = customTriggerId;
		}
	}
	[ComVisible(false)]
	public class RawValueUpdatedEventArgs : ValueUpdatedEventArgs
	{
		private readonly object pcFasFpw9;

		public object Value
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return pcFasFpw9;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public RawValueUpdatedEventArgs(int parameterId, int ecuId, object value, DateTime timestamp, TriggerType triggerType, int customTriggerId)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor(parameterId, ecuId, timestamp, triggerType, customTriggerId);
			pcFasFpw9 = value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public RawValueUpdatedEventArgs(int parameterId, int ecuId, object value, DateTime timestamp, TriggerType triggerType)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor(parameterId, ecuId, timestamp, triggerType, 0);
			pcFasFpw9 = value;
		}
	}
	[ComVisible(false)]
	public class DisplayValueUpdatedEventArgs : ValueUpdatedEventArgs
	{
		private readonly string qvKOEUHYG;

		public string Value
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return qvKOEUHYG;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DisplayValueUpdatedEventArgs(int parameterId, int ecuId, string value, DateTime timestamp, TriggerType triggerType, int customTriggerId)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor(parameterId, ecuId, timestamp, triggerType, customTriggerId);
			qvKOEUHYG = value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DisplayValueUpdatedEventArgs(int parameterId, int ecuId, string value, DateTime timestamp, TriggerType triggerType)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor(parameterId, ecuId, timestamp, triggerType, 0);
			qvKOEUHYG = value;
		}
	}
	[ComVisible(true)]
	[Guid("4D1B3C82-CB8E-4BF1-9AEA-6CD9261CF723")]
	public interface IConnections : ICollection<IConnection>, IList<IConnection>, IEnumerable, IEnumerable<IConnection>
	{
		new int Count { get; }

		new IConnection this[int index] { get; }

		IConnection Add(ConnectionType connectionType);

		IConnection Get(int connectionId);

		void Remove(int connectionId);

		ISystems Detect(IPhysicalConnectionConfiguration connectionConfiguration);

		IConnection AddConnectionForSystem(ISystem detectedSystem);
	}
	[Guid("C4372447-0791-499D-B237-EF1EC6FD3687")]
	[ComVisible(true)]
	public enum ECMServicesErrorCodes
	{
		NoError = 0,
		AcquiringChangeLockFailed = 1,
		AddingECUFailed = 2,
		BuildingSystemFailed = 3,
		ChangeLockUnavailable = 4,
		ConnectionAlreadyRemoved = 5,
		ConnectionIsActive = 6,
		ConnectionNotActive = 7,
		DatalinkError = 8,
		DatalinkTimeout = 9,
		DataServiceAlreadyRemoved = 10,
		ExpressionComputationError = 11,
		InvalidConnectionType = 12,
		InvalidMetadataFormat = 13,
		InvalidNonStandardEntityExpression = 14,
		InvalidParameterRule = 15,
		MetadataSourceUnavailable = 16,
		MonitoringIsActive = 17,
		NoDevicesDetected = 18,
		NonStandardEntityNotFound = 19,
		ParameterDependencyBlocked = 20,
		ParameterReadBlocked = 21,
		ParameterWriteBlocked = 22,
		PostActionFailed = 23,
		PreActionFailed = 24,
		ProtocolNotSuportedByECU = 25,
		RequiredLibraryNotFound = 26,
		SaveChangesFailed = 27,
		SettingSessionFailed = 28,
		TypeMismatch = 29,
		UnsupportedConnectionConfiguration = 30,
		ValueOutOfRange = 31,
		ParameterNotWriteable = 32,
		GroupReadCancelled = 33,
		NoImageCreationInProgress = 34,
		InvalidToken = 35,
		ModuleRejected = 36,
		InvalidFileFormat = 37,
		ErrorFromECU = 131072,
		MultipleSystemsDetected = -11541,
		UnknownError = 1048575
	}
	[Guid("FC047EBF-06A5-4529-BBA8-7278FF0D13CB")]
	[ComVisible(true)]
	public interface IOfflineImageService
	{
		IPrintableFeatureInformations SupportedPrintableFeatures { get; }

		string TransformImageForPrinting(string selectedFeatures);

		string TransformImageForPrinting(IPrintableFeatureInformations selectedFeatures);

		void Close();
	}
	[ComVisible(true)]
	[Guid("00AD3812-BC06-4844-BB63-FAA249FA6CC0")]
	public interface IEnumeration
	{
		int Id { get; }

		bool IsDynamic { get; }

		IList<int> RawValues { get; }

		IList<string> DisplayValues { get; }

		string GetDisplayValueForEnum(int rawValue);

		int GetRawValue(string displayValue);
	}
	[ComVisible(true)]
	[Guid("76C609E3-032A-402D-95F3-2CF5CE0AE49D")]
	public interface IEnumerations
	{
		IEnumeration GetEnumeration(int enumerationId, int connectionId = 0, int ecuId = 0);
	}
	[ComVisible(true)]
	[Guid("4456BA9D-E04D-4A9F-8F72-B82D1B8E849D")]
	public interface ICustomTriggerManager
	{
		int AddTriggerWithValueCheck(int parameterId, int ECUId, CustomTriggerOperator triggerOperator, object operandValue);

		int AddTriggerWithParameterCheck(int parameterId, int ECUId, CustomTriggerOperator triggerOperator, int operandParameterId);

		void RemoveTrigger(int triggerId);

		ICustomTriggers GetTriggersForParameter(int parameterId, int ECUId);

		ICustomTrigger GetTrigger(int triggerId);
	}
	[Guid("704384FF-AA69-42AA-92DA-D51CBEE880EA")]
	[ComVisible(true)]
	public interface ISimulatorInformation
	{
		int SystemType { get; }

		int ECUType { get; }

		int SimulatorType { get; }

		int DetectType { get; }

		string SimulatorName { get; }

		int EngineType { get; }
	}
	[Guid("92A9905C-BAE7-4CBE-A54B-D14FD9D23F68")]
	[ComVisible(true)]
	public interface ISimulatorInformations : ICollection<ISimulatorInformation>, IList<ISimulatorInformation>, IEnumerable, IEnumerable<ISimulatorInformation>
	{
		new int Count { get; }

		new ISimulatorInformation this[int index] { get; }
	}
	[ComVisible(true)]
	[Guid("EFC987B6-555E-446B-A7C7-D376E77C68E6")]
	public interface ISystems : ICollection<ISystem>, IList<ISystem>, IEnumerable, IEnumerable<ISystem>
	{
		new int Count { get; }

		new ISystem this[int index] { get; }
	}
	[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
	[ComVisible(true)]
	[Guid("FB1B1510-2A41-4A9A-BEB2-4792731AA90F")]
	public interface ITemplateEvents
	{
		void OnTransferringTemplate(TemplateTransferStatus status, int percentComplete);
	}
	[ComVisible(false)]
	public class TemplateTransferEventArgs : EventArgs
	{
		private TemplateTransferStatus PZ8GQ3sQv;

		private int GpOfo02u3;

		public TemplateTransferStatus Status
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return PZ8GQ3sQv;
			}
		}

		public int PercentComplete
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return GpOfo02u3;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TemplateTransferEventArgs(TemplateTransferStatus status, int percentComplete)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor();
			PZ8GQ3sQv = status;
			GpOfo02u3 = percentComplete;
		}
	}
	[Guid("C4924793-9D5F-4B06-BD31-007BA8803498")]
	[ComVisible(true)]
	public interface IUsageDefinition
	{
		int Id { get; }

		int ECUType { get; }

		string Name { get; }

		IParameterGroup Parameters { get; }

		bool HasParameter(int parameterId);
	}
	[Guid("76C70855-A387-4C59-B02A-BB27C9A3DC16")]
	[ComVisible(true)]
	public interface IUsageDefinitions
	{
		IUsageDefinition GetUsageDefinition(int ecuType, int usageId);

		IList<int> GetUsages(int ecuType);

		bool IsUsagePresent(int ecuType, int usageId);

		IList<int> GetUsagesForParameter(int ecuType, int parameterId);

		bool ParameterHasUsage(int ecuType, int usageId, int parameterId);

		bool ParameterHasUsageFromDetectType(int detectType, int usageId, int parameterId);
	}
	[ComVisible(true)]
	[Guid("64F31444-608C-4C12-B045-23490A9453E4")]
	public interface IUnitDefinition
	{
		int Id { get; }

		string ShortName { get; }

		string LongName { get; }
	}
	[ComVisible(true)]
	[Guid("86EDC3C7-3FCB-45BB-ADE1-030F1FFF4BEA")]
	public interface IUnitDefinitions
	{
		IUnitDefinition GetUnitDefinition(int unitId);

		string GetUnitFamilyName(int unitFamilyId);
	}
	[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
	[Guid("348CC449-513E-4FDE-A798-EE5ACF0DC57E")]
	[ComVisible(true)]
	public interface ILoggerEvents
	{
		void OnLowDiskSpace();
	}
	[ProgId("Cummins.INSITE.Kernel.GroupBuilder.1")]
	[ComVisible(true)]
	[Guid("581A54B7-14E2-4AED-8156-A35511748FCE")]
	[ClassInterface(ClassInterfaceType.None)]
	public class GroupBuilder : IGroupBuilder
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public GroupBuilder()
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup CreateParameterGroup()
		{
			return new TuVFbhEmyglEBD8e22();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterGroup CreateParameterGroup(IEnumerable<int> paramCollection)
		{
			return new TuVFbhEmyglEBD8e22(paramCollection);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValueGroup CreateParameterValueGroup()
		{
			return new xWvKEUiHYGPZ8Q3sQv();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValueGroup CreateParameterValueGroup(IDictionary<int, object> paramCollection)
		{
			return new xWvKEUiHYGPZ8Q3sQv(paramCollection);
		}
	}
}
namespace OHITIbwEDvYfcFsFpw
{
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("Cummins.INSITE.Kernel.ParameterGroup.1")]
	[Guid("1616D20D-130E-42F0-BB28-C71DFCEEE088")]
	[ComVisible(true)]
	internal class TuVFbhEmyglEBD8e22 : List<int>, IList<int>, IParameterGroup, ICollection<int>, IEnumerable, IEnumerable<int>
	{
		private static int cicWxVqGj;

		private int eqYZ9wOkH;

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return eqYZ9wOkH;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TuVFbhEmyglEBD8e22()
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor();
			eqYZ9wOkH = cicWxVqGj++;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TuVFbhEmyglEBD8e22(IEnumerable<int> paramCollection)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor(paramCollection);
			eqYZ9wOkH = cicWxVqGj++;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public new void Add(int P_0)
		{
			if (!Contains(P_0))
			{
				base.Add(P_0);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Add(IList<int> parameterIds)
		{
			foreach (int parameterId in parameterIds)
			{
				Add(parameterId);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static TuVFbhEmyglEBD8e22()
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			cicWxVqGj = 1;
		}
	}
}
namespace GpOo02qu3LicxVqGjU
{
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("Cummins.INSITE.Kernel.ParameterValueGroup.1")]
	[Guid("D558DAFF-3DAB-44D2-B7EE-5FE3CFBD355F")]
	internal class xWvKEUiHYGPZ8Q3sQv : Dictionary<int, object>, IDictionary<int, object>, IParameterValueGroup, ICollection<KeyValuePair<int, object>>, IEnumerable, IEnumerable<KeyValuePair<int, object>>
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public xWvKEUiHYGPZ8Q3sQv()
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public xWvKEUiHYGPZ8Q3sQv(IDictionary<int, object> paramCollection)
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor(paramCollection);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public new void Add(int P_0, object P_1)
		{
			if (ContainsKey(P_0))
			{
				base[P_0] = P_1;
			}
			else
			{
				base.Add(P_0, P_1);
			}
		}
	}
}
namespace Cummins.INSITE.Kernel.ECMServicesAPI
{
	[Guid("86A6989B-8FA3-4FDF-9258-63C603FEA1E7")]
	[ComVisible(true)]
	public interface ISpecialFeatureInformation
	{
		int Id { get; }

		string DisplayName { get; }

		int ResourceId { get; }

		Guid PageGUID { get; }

		Guid LogicGUID { get; }
	}
	[ComVisible(true)]
	[Guid("417DA8A2-296F-4EEA-9184-E46D47348B22")]
	public interface ISpecialFeatureInformations : ICollection<ISpecialFeatureInformation>, IList<ISpecialFeatureInformation>, IEnumerable, IEnumerable<ISpecialFeatureInformation>
	{
		new int Count { get; }

		new ISpecialFeatureInformation this[int index] { get; }
	}
	[ComVisible(true)]
	[Guid("58D58443-3149-4173-B767-25FC7A8C7A0B")]
	public interface IConnectionConfiguration
	{
		string ConnectionString { get; set; }

		ConnectionType ConnectionType { get; }

		uint ToolInstance { get; set; }

		uint ToolVersion { get; set; }

		uint ToolId { get; set; }

		PasswordType PasswordType { get; set; }

		string Password { get; set; }
	}
	[Guid("9906722A-7654-4B66-8C11-A884E9E07F10")]
	[ComVisible(true)]
	public abstract class ConnectionConfiguration : IConnectionConfiguration
	{
		protected string _connectionString;

		protected uint _toolInstance;

		protected uint _toolVersion;

		protected uint _toolId;

		protected PasswordType _passwordType;

		protected string _password;

		public string ConnectionString
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _connectionString;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_connectionString = value;
			}
		}

		public abstract ConnectionType ConnectionType { get; }

		public uint ToolInstance
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _toolInstance;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_toolInstance = value;
			}
		}

		public uint ToolVersion
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _toolVersion;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_toolVersion = value;
			}
		}

		public uint ToolId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _toolId;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_toolId = value;
			}
		}

		public PasswordType PasswordType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _passwordType;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_passwordType = value;
			}
		}

		public string Password
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _password;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_password = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected ConnectionConfiguration()
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor();
		}
	}
	[Guid("12500C37-6E8B-4E02-831F-CC39C4902B53")]
	[ComVisible(true)]
	public interface IPhysicalConnectionConfiguration : IConnectionConfiguration
	{
		int Port { get; set; }

		int IRQ { get; set; }

		bool IsAutoDetect { get; set; }

		DLAType DLAType { get; set; }

		string ProtocolString { get; }

		string RP1201IniFileName { get; set; }

		int RP1210DeviceId { get; set; }

		ConnectionProtocol Protocol { get; set; }
	}
	[ProgId("Cummins.INSITE.Kernel.PhysicalConnectionConfiguration.1")]
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("A80522E3-FE00-40A8-855D-898057E033A8")]
	public sealed class PhysicalConnectionConfiguration : ConnectionConfiguration, IPhysicalConnectionConfiguration, IConnectionConfiguration
	{
		private int LJr65e7Lu;

		private int jXNrFZKaO;

		private bool CSWxc9hFA;

		private DLAType k1kuFWwpB;

		private ConnectionProtocol kpLJF0Q0P;

		private string iPblZjtJw;

		private int DF19ACDjp;

		private string y5mVsDZbr;

		public override ConnectionType ConnectionType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ConnectionType.Physical;
			}
		}

		public int Port
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return LJr65e7Lu;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				LJr65e7Lu = value;
			}
		}

		public int IRQ
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return jXNrFZKaO;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				jXNrFZKaO = value;
			}
		}

		public bool IsAutoDetect
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return CSWxc9hFA;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				CSWxc9hFA = value;
			}
		}

		public DLAType DLAType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return k1kuFWwpB;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				k1kuFWwpB = value;
			}
		}

		public string ProtocolString
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (string.IsNullOrEmpty(y5mVsDZbr))
				{
					return kpLJF0Q0P.ToString();
				}
				return y5mVsDZbr;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				y5mVsDZbr = value;
			}
		}

		public string RP1201IniFileName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return iPblZjtJw;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				iPblZjtJw = value;
			}
		}

		public int RP1210DeviceId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return DF19ACDjp;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				DF19ACDjp = value;
			}
		}

		public ConnectionProtocol Protocol
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return kpLJF0Q0P;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				kpLJF0Q0P = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public PhysicalConnectionConfiguration()
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor();
		}
	}
	[ComVisible(true)]
	[Guid("FE46185D-433C-4489-BE32-61C422BDA04B")]
	public interface ISimulatorConnectionConfiguration : IConnectionConfiguration
	{
		int SimulatorType { get; set; }

		int DetectType { get; set; }

		int SystemType { get; set; }
	}
	[ProgId("Cummins.INSITE.Kernel.SimulatorConnectionConfiguration.1")]
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[Guid("7DC45C6E-B0B3-4D82-9A6A-BFFBF1448720")]
	public sealed class SimulatorConnectionConfiguration : ConnectionConfiguration, ISimulatorConnectionConfiguration, IConnectionConfiguration
	{
		private int gO1IwunyV;

		private int ubEgscqxL;

		private int rs6Rr904w;

		public override ConnectionType ConnectionType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ConnectionType.Simulator;
			}
		}

		public int SimulatorType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return gO1IwunyV;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				gO1IwunyV = value;
			}
		}

		public int DetectType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ubEgscqxL;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				ubEgscqxL = value;
			}
		}

		public int SystemType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return rs6Rr904w;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				rs6Rr904w = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SimulatorConnectionConfiguration()
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor();
		}
	}
	[ComVisible(true)]
	[Guid("FF594F9C-4DA9-473D-92EE-186025D9521D")]
	public interface IImageConnectionConfiguration : IConnectionConfiguration
	{
		string ImageFilePath { get; set; }
	}
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("Cummins.INSITE.Kernel.ImageConnectionConfiguration.1")]
	[Guid("C6EC3AE3-D78D-4842-93D6-2CBEF553E34D")]
	public sealed class ImageConnectionConfiguration : ConnectionConfiguration, IImageConnectionConfiguration, IConnectionConfiguration
	{
		private string HjlyRaP2e;

		public override ConnectionType ConnectionType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ConnectionType.Image;
			}
		}

		public string ImageFilePath
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return HjlyRaP2e;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				HjlyRaP2e = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ImageConnectionConfiguration()
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor();
		}
	}
	[Guid("0117D719-5BB1-4F88-B073-F9A23DD9FADA")]
	[ComVisible(true)]
	public class SessionInfo : ISessionInfo
	{
		private string VIA0AxT02;

		private string E9f55yt0S;

		private PasswordType fVXmRSgJi;

		private int LXNX7dSm7;

		private uint IWVM0rEKv;

		private uint mR92wVaIS;

		private uint dR0KH4xyt;

		private uint C1STepkw1;

		public string SessionInformation
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return VIA0AxT02;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				VIA0AxT02 = value;
			}
		}

		public string Password
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal get
			{
				return E9f55yt0S;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				E9f55yt0S = value;
			}
		}

		public PasswordType PasswordType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return fVXmRSgJi;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				fVXmRSgJi = value;
			}
		}

		public int EncryptionLevel
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return LXNX7dSm7;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				LXNX7dSm7 = value;
			}
		}

		public uint ToolFamily
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return mR92wVaIS;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				mR92wVaIS = value;
			}
		}

		public uint ToolId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return IWVM0rEKv;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				IWVM0rEKv = value;
			}
		}

		public uint ToolInstance
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return dR0KH4xyt;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				dR0KH4xyt = value;
			}
		}

		public uint ToolVersion
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return C1STepkw1;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				C1STepkw1 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SessionInfo()
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor();
		}
	}
	[ComVisible(true)]
	[Guid("0111C7C5-8236-4470-9A25-2FD03D2290AF")]
	public interface IMonitorServices
	{
		IMonitorService Add(int connectionId);

		void Remove(int monitorServiceId);

		IMonitorService Get(int monitorServiceId);
	}
	[ComVisible(true)]
	[Guid("85F2F6D6-FDCA-432B-9055-24F5675574BE")]
	public interface IGroup : ICollection<IParameter>, IList<IParameter>, IEnumerable, IEnumerable<IParameter>
	{
		new int Count { get; }

		new IParameter this[int index] { get; }

		ECMServicesErrorCodes LastStatus { get; }
	}
	[ComVisible(true)]
	[Guid("D1B35A3E-42AA-4C64-A2CA-562DD2969190")]
	public interface IFeatureDefinition
	{
		int Id { get; }

		int DetectType { get; }

		string Name { get; }

		IList<int> Parameters { get; }
	}
	[Guid("299BE3A8-D8EC-4BA8-84D3-AA12DA969650")]
	[ComVisible(true)]
	public interface IFeatureDefinitions
	{
		IFeatureDefinition GetFeatureDefinition(int ecuType, int featureId);

		IList<int> GetFeaturesForECU(int ecuType);

		IList<int> GetFeaturesForParameter(int ecuType, int parameterId);

		IList<string> GetFeaturesHierarchyForParameter(int ecuType, int parameterId, int connectionId, int moduleId);

		bool IsFeatureSupported(int ecuType, int featureId);

		bool IsParameterInFeature(int ecuType, int featureId, int parameterId);
	}
	[Guid("C3EF3C84-15E3-4E79-951C-C0EC6642F951")]
	[ComVisible(true)]
	public interface IArray : IParameter
	{
		int Dimension { get; }

		Type ElementType { get; }

		int Count { get; }

		T ItemAs<T>(int index);

		object Item(int index);
	}
	[Guid("D2743BC5-DBA5-43ED-A9E4-D325A18EFA33")]
	[ComVisible(true)]
	public interface IDiagnosticTestInformation
	{
		int Id { get; }

		int ResourceId { get; }

		string DisplayName { get; }

		Guid PageGUID { get; }

		Guid LogicGUID { get; }

		bool IsLegacy { get; }

		string SourceFileName { get; }

		string Subtitle { get; }
	}
	[Guid("98F58C2C-BBED-4FD8-AF8B-5EB9A5239333")]
	[ComVisible(true)]
	public interface IDiagnosticTestInformations : ICollection<IDiagnosticTestInformation>, IList<IDiagnosticTestInformation>, IEnumerable, IEnumerable<IDiagnosticTestInformation>
	{
		new int Count { get; }

		new IDiagnosticTestInformation this[int index] { get; }
	}
	[ComVisible(true)]
	[Guid("6B99A0D0-714E-4828-AA78-DA2DC384E120")]
	public interface IDetectedSystems : ICollection<ISystem>, IList<ISystem>, IEnumerable, IEnumerable<ISystem>
	{
		new int Count { get; }

		new ISystem this[int index] { get; }
	}
	[Guid("761F488F-8C6B-4091-B239-C60D2D08E3D6")]
	[ComVisible(true)]
	public interface ISession
	{
		void OpenSession(int ecuId);

		void CloseSession(int ecuId);

		void SetSessionInfo(int ecuId, ISessionInfo sessionInfo);

		ISessionInfo GetSessionInfo(int ecuId);
	}
	[Guid("3C62939C-2EFF-4685-B2D5-B1D053D9F46C")]
	[ComVisible(true)]
	public interface ISystem
	{
		int SystemType { get; }

		string Name { get; }

		int PrimaryECUId { get; }

		ICumminsECUs CumminsECUs { get; }

		IECUs OtherDevices { get; }

		IECU GetECU(int ECUId);

		IECU GetECUByAddress(int sourceAddress);
	}
}
internal class <Module>{51E9601E-00FD-4B7B-8301-70C6F7942B0A}
{
}
namespace MFZKaOD0SWc9hFAD1k
{
	internal class iY9wOkAHSJr5e7LuDX
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module GFaj1SYy9;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void jTVwkIssGLsPD(int typemdt)
		{
			Type type = GFaj1SYy9.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)GFaj1SYy9.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public iY9wOkAHSJr5e7LuDX()
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static iY9wOkAHSJr5e7LuDX()
		{
			WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
			GFaj1SYy9 = typeof(iY9wOkAHSJr5e7LuDX).Assembly.ManifestModule;
		}
	}
}
namespace JtJw5Fp1ACDjpI5msD
{
	internal class OWwpBsspLF0Q0PqPbZ
	{
		internal class rbrwO1ewunyVubEscq : Attribute
		{
			internal class tLZs6ra904wKjlRaP2<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public tLZs6ra904wKjlRaP2()
				{
					WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[rbrwO1ewunyVubEscq(typeof(OWwpBsspLF0Q0PqPbZ/rbrwO1ewunyVubEscq/tLZs6ra904wKjlRaP2<object>[]))]
			public rbrwO1ewunyVubEscq(object P_0)
			{
				WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
				base..ctor();
			}
		}

		internal class lvwC1hO8A0QIAAxT02
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[rbrwO1ewunyVubEscq(typeof(OWwpBsspLF0Q0PqPbZ/rbrwO1ewunyVubEscq/tLZs6ra904wKjlRaP2<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (NfytIwnns5(Convert.ToBase64String(typeof(OWwpBsspLF0Q0PqPbZ).Assembly.GetName().GetPublicKeyToken()), OWwpBsspLF0Q0PqPbZ.RZBcZQRG7(716)) != OWwpBsspLF0Q0PqPbZ.RZBcZQRG7(722))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[rbrwO1ewunyVubEscq(typeof(OWwpBsspLF0Q0PqPbZ/rbrwO1ewunyVubEscq/tLZs6ra904wKjlRaP2<object>[]))]
			internal static string NfytIwnns5(string P_0, string P_1)
			{
				byte[] bytes = Encoding.Unicode.GetBytes(P_0);
				byte[] array = bytes;
				byte[] key = new byte[32]
				{
					82, 102, 104, 110, 32, 77, 24, 34, 118, 181,
					51, 17, 18, 51, 12, 109, 10, 32, 77, 24,
					34, 158, 161, 41, 97, 28, 118, 181, 5, 25,
					1, 88
				};
				MD5 mD = new MD5CryptoServiceProvider();
				byte[] iV = mD.ComputeHash(Encoding.Unicode.GetBytes(P_1));
				MemoryStream memoryStream = new MemoryStream();
				Rijndael rijndael = Rijndael.Create();
				rijndael.Key = key;
				rijndael.IV = iV;
				CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateEncryptor(), CryptoStreamMode.Write);
				cryptoStream.Write(array, 0, array.Length);
				cryptoStream.Close();
				return Convert.ToBase64String(memoryStream.ToArray());
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public lvwC1hO8A0QIAAxT02()
			{
				WRG7PT6WNqlZ3H09WQ.z2YwkIszWydt1();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint E9f5ytG0SEVXRSgJiN([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr FN7dSmf7KWV0rEKvaR();

		internal struct xwVaISW8R0H4xyt01S
		{
			internal bool gdbtgDRvRi;

			internal byte[] nkDtRXZ1eX;
		}

		[Flags]
		private enum mpkw1MZFa1SYy9oZBZ
		{

		}

		private static byte[] QwBtivBE2V;

		private static byte[] snVtANiJ0G;

		private static IntPtr HG2tps7aZC;

		private static int ilptOKXfPT;

		internal static Hashtable qQ5tVyhrij;

		private static IntPtr rTyt9wH9oP;

		private static object pqsteL9KXE;

		private static int gv4tlN2jGu;

		private static byte[] ecBtDIEX0h;

		private static int nNFtu1QPwT;

		private static int[] ugAta1vNjl;

		private static SortedList NhxtfvUZU9;

		internal static E9f5ytG0SEVXRSgJiN wTOtrt4Ty7;

		internal static E9f5ytG0SEVXRSgJiN y5st6D6q8D;

		private static byte[] Cwltqx1iRe;

		private static long ITltxRh5YU;

		private static IntPtr IUKtslY732;

		private static bool ExmtG5dlh3;

		private static long cXVtZWkwNf;

		private static bool KCotJS7Q8w;

		private static int QmRtWtOANo;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static OWwpBsspLF0Q0PqPbZ()
		{
			QwBtivBE2V = new byte[0];
			Cwltqx1iRe = new byte[0];
			snVtANiJ0G = new byte[0];
			ecBtDIEX0h = new byte[0];
			IUKtslY732 = IntPtr.Zero;
			HG2tps7aZC = IntPtr.Zero;
			pqsteL9KXE = new string[0];
			ugAta1vNjl = new int[0];
			ilptOKXfPT = 1;
			ExmtG5dlh3 = false;
			NhxtfvUZU9 = new SortedList();
			QmRtWtOANo = 0;
			cXVtZWkwNf = 0L;
			y5st6D6q8D = null;
			wTOtrt4Ty7 = null;
			ITltxRh5YU = 0L;
			nNFtu1QPwT = 0;
			KCotJS7Q8w = false;
			gv4tlN2jGu = 0;
			rTyt9wH9oP = IntPtr.Zero;
			qQ5tVyhrij = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void gJbwkIsYSR2K7()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[rbrwO1ewunyVubEscq(typeof(OWwpBsspLF0Q0PqPbZ/rbrwO1ewunyVubEscq/tLZs6ra904wKjlRaP2<object>[]))]
		static string RZBcZQRG7(int P_0)
		{
			int num = 139;
			byte[] array4 = default(byte[]);
			int num3 = default(int);
			byte[] array = default(byte[]);
			byte[] array2 = default(byte[]);
			byte[] array3 = default(byte[]);
			int num8 = default(int);
			int num7 = default(int);
			int num5 = default(int);
			CryptoStream cryptoStream = default(CryptoStream);
			BinaryReader binaryReader = default(BinaryReader);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			MemoryStream memoryStream = default(MemoryStream);
			byte[] array6 = default(byte[]);
			byte[] array5 = default(byte[]);
			int num2 = default(int);
			ICryptoTransform transform = default(ICryptoTransform);
			while (true)
			{
				int num4;
				int num6;
				switch (num)
				{
				case 342:
					array4 = (byte[])Jm4s4RAQZvsapjdsrs(mB6P3m65J73cN7NFab(hLWFLIOH9O4mEdljnS(typeof(OWwpBsspLF0Q0PqPbZ).TypeHandle).Assembly));
					num4 = 189;
					if (!XMBO4ZsCO9rvrAc7d1())
					{
						goto case 197;
					}
					goto IL_0d3e;
				case 188:
					num3 = 61 + 64;
					num4 = 227;
					goto IL_0d3e;
				case 46:
					array[13] = 78;
					num = 36;
					continue;
				case 121:
					array2[12] = 154;
					num4 = 219;
					goto IL_0d3e;
				case 268:
					array3[11] = array4[5];
					num4 = 318;
					if (!XMBO4ZsCO9rvrAc7d1())
					{
						goto case 231;
					}
					goto IL_0d3e;
				case 175:
					array[14] = 95;
					num4 = 45;
					if (false)
					{
						goto case 37;
					}
					goto IL_0d3e;
				case 37:
					num8 = 68 - 26;
					num4 = 275;
					goto IL_0d3e;
				case 23:
					array[20] = 88;
					num4 = 10;
					if (false)
					{
						goto case 14;
					}
					goto IL_0d3e;
				case 14:
					array[26] = (byte)num3;
					num4 = 316;
					goto IL_0d3e;
				case 149:
					array[21] = 227;
					num = 330;
					continue;
				case 285:
					array[13] = (byte)num7;
					num6 = 15;
					goto IL_0d3a;
				case 318:
					array3[13] = array4[6];
					num4 = 40;
					goto IL_0d3e;
				case 112:
					array = new byte[32];
					num4 = 214;
					goto IL_0d3e;
				case 226:
					array[31] = 132;
					num4 = 11;
					if (zCqUXvftq408voPjcW())
					{
						goto case 151;
					}
					goto IL_0d3e;
				case 151:
					array[16] = (byte)num3;
					num4 = 19;
					if (false)
					{
						goto case 179;
					}
					goto IL_0d3e;
				case 179:
					array[9] = (byte)num7;
					num = 336;
					continue;
				case 38:
					array[7] = (byte)num3;
					num = 255;
					continue;
				case 336:
					array[10] = 102;
					num4 = 150;
					goto IL_0d3e;
				case 240:
					array[16] = (byte)num7;
					num6 = 197;
					goto IL_0d3a;
				case 295:
					array2[14] = 193;
					num = 64;
					continue;
				case 61:
					array[26] = 104;
					num = 191;
					continue;
				case 287:
					array2[0] = (byte)num8;
					num = 91;
					continue;
				case 247:
					array[28] = (byte)num3;
					num = 84;
					continue;
				case 196:
					array[6] = 137;
					num6 = 311;
					goto IL_0d3a;
				case 171:
					num7 = 166 - 55;
					num4 = 338;
					goto IL_0d3e;
				case 136:
					array2[11] = 118;
					num4 = 50;
					if (!zCqUXvftq408voPjcW())
					{
						goto IL_0d3e;
					}
					goto case 117;
				case 332:
					array2[8] = (byte)num5;
					num4 = 142;
					goto IL_0d3e;
				case 221:
					array[3] = 248;
					num = 101;
					continue;
				case 303:
					array[2] = (byte)num7;
					num = 294;
					continue;
				case 251:
					array2[3] = (byte)num5;
					num6 = 34;
					goto IL_0d3a;
				case 282:
					array2[8] = (byte)num8;
					num = 307;
					continue;
				case 93:
					array[15] = 90;
					num6 = 259;
					goto IL_0d3a;
				case 36:
					array[13] = 158;
					num4 = 292;
					if (false)
					{
						goto case 65;
					}
					goto IL_0d3e;
				case 65:
					array[28] = (byte)num7;
					num = 213;
					continue;
				case 22:
					num5 = 102 + 97;
					num4 = 352;
					if (1 == 0)
					{
						goto case 74;
					}
					goto IL_0d3e;
				case 74:
				case 296:
					array[10] = (byte)num7;
					num4 = 232;
					goto IL_0d3e;
				case 272:
					array[27] = (byte)num3;
					num4 = 252;
					if (!XMBO4ZsCO9rvrAc7d1())
					{
						goto case 334;
					}
					goto IL_0d3e;
				case 340:
					array[15] = (byte)num7;
					num = 280;
					continue;
				case 169:
					array[21] = 180;
					num4 = 115;
					goto IL_0d3e;
				case 30:
					array[20] = 112;
					num = 184;
					continue;
				case 255:
					num7 = 213 - 112;
					num = 17;
					continue;
				case 352:
					array2[1] = (byte)num5;
					num = 85;
					continue;
				case 334:
					num3 = 70 + 40;
					num6 = 204;
					goto IL_0d3a;
				case 103:
					num5 = 171 - 57;
					num4 = 82;
					if (1 == 0)
					{
						goto case 1;
					}
					goto IL_0d3e;
				case 1:
					array[31] = 125;
					num = 51;
					continue;
				case 338:
					array[7] = (byte)num7;
					num4 = 31;
					if (false)
					{
						goto case 207;
					}
					goto IL_0d3e;
				case 207:
					array[29] = (byte)num3;
					num6 = 39;
					goto IL_0d3a;
				case 288:
					num3 = 10 + 99;
					num4 = 100;
					goto IL_0d3e;
				case 218:
					array[14] = 156;
					num6 = 170;
					goto IL_0d3a;
				case 39:
					num7 = 111 + 76;
					num = 123;
					continue;
				case 0:
					num7 = 115 + 82;
					XMBO4ZsCO9rvrAc7d1();
					if (!zCqUXvftq408voPjcW())
					{
						num = 296;
						continue;
					}
					num4 = 250;
					goto IL_0d3e;
				case 198:
					sPIYthjk4iTkpOw4av(cryptoStream);
					num4 = 241;
					if (!XMBO4ZsCO9rvrAc7d1())
					{
						goto case 6;
					}
					goto IL_0d3e;
				case 107:
					num7 = 105 + 70;
					num6 = 52;
					goto IL_0d3a;
				case 133:
					array2[4] = 150;
					num = 177;
					continue;
				case 325:
					array[7] = (byte)num3;
					num6 = 95;
					goto IL_0d3a;
				case 96:
					array2[0] = 60;
					num6 = 253;
					goto IL_0d3a;
				case 95:
					array[7] = 92;
					num4 = 171;
					if (1 == 0)
					{
						goto case 163;
					}
					goto IL_0d3e;
				case 163:
					array[14] = (byte)num7;
					num6 = 120;
					goto IL_0d3a;
				case 9:
					array[16] = 85;
					num4 = 327;
					if (1 == 0)
					{
						goto case 97;
					}
					goto IL_0d3e;
				case 97:
					array[31] = (byte)num3;
					num = 99;
					continue;
				case 222:
					array[18] = (byte)num7;
					num = 94;
					continue;
				case 123:
					array[29] = (byte)num7;
					num = 349;
					continue;
				case 35:
					num5 = 173 - 57;
					num4 = 212;
					if (1 == 0)
					{
						goto case 31;
					}
					goto IL_0d3e;
				case 31:
					num3 = 82 + 99;
					num = 38;
					continue;
				case 329:
					array[12] = (byte)num3;
					num6 = 58;
					goto IL_0d3a;
				case 173:
					num5 = 113 + 116;
					num6 = 155;
					goto IL_0d3a;
				case 308:
					array[25] = (byte)num7;
					num4 = 158;
					if (!XMBO4ZsCO9rvrAc7d1())
					{
						goto case 108;
					}
					goto IL_0d3e;
				case 108:
					MM561fa5oeDQI1xGHh(n0Oso1WcLcfVTKeNbb(binaryReader), 0L);
					num = 270;
					continue;
				case 159:
					num8 = 254 - 84;
					num4 = 199;
					goto IL_0d3e;
				case 55:
					num7 = 215 - 71;
					num6 = 87;
					goto IL_0d3a;
				case 230:
					array[10] = 166;
					num4 = 144;
					goto IL_0d3e;
				case 219:
					array2[13] = 164;
					num6 = 153;
					goto IL_0d3a;
				case 197:
					num3 = 104 - 19;
					num4 = 151;
					if (!XMBO4ZsCO9rvrAc7d1())
					{
						goto case 130;
					}
					goto IL_0d3e;
				case 130:
					num3 = 223 - 74;
					num6 = 105;
					goto IL_0d3a;
				case 120:
					array[14] = 197;
					num4 = 175;
					if (1 == 0)
					{
						goto case 157;
					}
					goto IL_0d3e;
				case 157:
					array[24] = (byte)num3;
					num = 81;
					continue;
				case 345:
					array[12] = 146;
					num = 89;
					continue;
				case 21:
					num8 = 135 - 45;
					num = 282;
					continue;
				case 135:
					CaeReJBN1XBuTPIBWI(rijndaelManaged, CipherMode.CBC);
					num = 152;
					continue;
				case 277:
					array2[10] = 120;
					num6 = 37;
					goto IL_0d3a;
				case 215:
					array[28] = (byte)num3;
					num6 = 44;
					goto IL_0d3a;
				case 13:
					array3[3] = array4[1];
					num = 76;
					continue;
				case 292:
					num7 = 39 + 43;
					num4 = 285;
					if (XMBO4ZsCO9rvrAc7d1())
					{
						goto IL_0d3e;
					}
					goto case 206;
				case 6:
					array[0] = (byte)num7;
					num4 = 111;
					if (1 == 0)
					{
						goto case 259;
					}
					goto IL_0d3e;
				case 259:
					num3 = 69 + 40;
					num4 = 8;
					if (!zCqUXvftq408voPjcW())
					{
						goto IL_0d3e;
					}
					goto case 187;
				case 137:
					zVxdWITrFmqhlRPGCH(cryptoStream);
					num6 = 29;
					goto IL_0d3a;
				case 315:
					binaryReader = new BinaryReader((Stream)hZbliJEYJjaCY6drAx(hLWFLIOH9O4mEdljnS(typeof(OWwpBsspLF0Q0PqPbZ).TypeHandle).Assembly, "nbyPJQNbWSyLNwMSxd.DsNsRBZG2beYHncAc2"));
					num6 = 108;
					goto IL_0d3a;
				case 140:
					num8 = 151 - 50;
					num4 = 260;
					if (false)
					{
						goto case 274;
					}
					goto IL_0d3e;
				case 274:
					array[17] = (byte)num3;
					num4 = 127;
					goto IL_0d3e;
				case 189:
					if (array4 == null)
					{
						goto case 312;
					}
					num4 = 79;
					goto IL_0d3e;
				case 88:
					num3 = 120 + 38;
					num = 325;
					continue;
				case 11:
					array[31] = 52;
					num6 = 261;
					goto IL_0d3a;
				case 216:
					array[5] = 144;
					num = 339;
					continue;
				case 80:
					zVxdWITrFmqhlRPGCH(memoryStream);
					num6 = 137;
					goto IL_0d3a;
				case 231:
					num3 = 65 - 36;
					num4 = 75;
					if (false)
					{
						goto case 166;
					}
					goto IL_0d3e;
				case 166:
					num5 = 141 - 47;
					num4 = 254;
					goto IL_0d3e;
				case 286:
					array[26] = 94;
					num6 = 130;
					goto IL_0d3a;
				case 126:
					num8 = 220 - 73;
					num4 = 269;
					goto IL_0d3e;
				case 237:
					num7 = 158 - 80;
					num4 = 179;
					goto IL_0d3e;
				case 278:
					array[4] = (byte)num7;
					num4 = 216;
					if (1 == 0)
					{
						goto case 145;
					}
					goto IL_0d3e;
				case 145:
					array2[6] = 190;
					num4 = 246;
					if (false)
					{
						goto case 201;
					}
					goto IL_0d3e;
				case 201:
					array2 = new byte[16];
					num = 154;
					continue;
				case 32:
					array2[7] = (byte)num8;
					num = 126;
					continue;
				case 327:
					num7 = 238 - 79;
					num = 240;
					continue;
				case 256:
					array[8] = (byte)num3;
					num4 = 242;
					goto IL_0d3e;
				case 68:
					num8 = 189 - 63;
					num = 217;
					continue;
				case 190:
					num5 = 41 + 110;
					num6 = 251;
					goto IL_0d3a;
				case 79:
					if (array4.Length <= 0)
					{
						goto case 312;
					}
					num6 = 174;
					goto IL_0d3a;
				case 162:
					array2[14] = (byte)num8;
					num = 63;
					continue;
				case 90:
					array[27] = (byte)num3;
					num6 = 228;
					goto IL_0d3a;
				case 252:
					num3 = 100 + 10;
					num6 = 247;
					goto IL_0d3a;
				case 52:
					array[9] = (byte)num7;
					num4 = 42;
					if (false)
					{
						goto case 128;
					}
					goto IL_0d3e;
				case 128:
					num7 = 57 - 54;
					num6 = 186;
					goto IL_0d3a;
				case 314:
					array[24] = 190;
					num = 141;
					continue;
				case 66:
					array2[7] = 102;
					num = 324;
					continue;
				case 146:
					num3 = 73 + 49;
					goto case 236;
				default:
					num = 236;
					continue;
				case 45:
					array[14] = 192;
					num4 = 93;
					if (0 == 0)
					{
						goto IL_0d3e;
					}
					goto case 239;
				case 239:
					num7 = 1 + 37;
					num4 = 340;
					if (!zCqUXvftq408voPjcW())
					{
						goto IL_0d3e;
					}
					goto case 181;
				case 181:
					array6 = (byte[])LfeMx8lwcuFcsLoXKY(binaryReader, (int)Q2qZuORoYHFZAHKLZj(n0Oso1WcLcfVTKeNbb(binaryReader)));
					num = 112;
					continue;
				case 337:
					num5 = 64 + 6;
					num4 = 143;
					goto IL_0d3e;
				case 276:
					array[18] = (byte)num3;
					num6 = 124;
					goto IL_0d3a;
				case 350:
					array[25] = 207;
					num6 = 146;
					goto IL_0d3a;
				case 44:
					num3 = 72 + 71;
					num4 = 5;
					if (!XMBO4ZsCO9rvrAc7d1())
					{
						goto case 334;
					}
					goto IL_0d3e;
				case 236:
					array[26] = (byte)num3;
					num6 = 61;
					goto IL_0d3a;
				case 58:
					array[12] = 66;
					num6 = 46;
					goto IL_0d3a;
				case 110:
					array2[7] = (byte)num5;
					num = 21;
					continue;
				case 73:
					array[2] = 94;
					num4 = 77;
					goto IL_0d3e;
				case 99:
					array5 = array;
					num = 201;
					continue;
				case 161:
					array2[15] = (byte)num8;
					num4 = 273;
					if (XMBO4ZsCO9rvrAc7d1())
					{
						goto IL_0d3e;
					}
					goto case 228;
				case 89:
					num3 = 84 + 48;
					num6 = 329;
					goto IL_0d3a;
				case 351:
					array[19] = (byte)num3;
					num = 334;
					continue;
				case 16:
					array2[12] = 230;
					num4 = 121;
					if (XMBO4ZsCO9rvrAc7d1())
					{
						goto IL_0d3e;
					}
					goto case 158;
				case 158:
					num3 = 99 + 99;
					num = 353;
					continue;
				case 63:
					array2[14] = 162;
					num6 = 337;
					goto IL_0d3a;
				case 164:
					num3 = 86 + 89;
					num4 = 215;
					if (zCqUXvftq408voPjcW())
					{
						goto case 222;
					}
					goto IL_0d3e;
				case 49:
					array[30] = 254;
					num = 1;
					continue;
				case 174:
					array3[1] = array4[0];
					num = 13;
					continue;
				case 227:
					array[0] = (byte)num3;
					num = 178;
					continue;
				case 131:
					num3 = 198 - 66;
					num4 = 220;
					if (!zCqUXvftq408voPjcW())
					{
						goto IL_0d3e;
					}
					goto case 326;
				case 204:
					array[19] = (byte)num3;
					num4 = 267;
					goto IL_0d3e;
				case 24:
					array2[2] = 96;
					num4 = 35;
					if (!XMBO4ZsCO9rvrAc7d1())
					{
						goto case 35;
					}
					goto IL_0d3e;
				case 266:
					array[16] = (byte)num3;
					num = 70;
					continue;
				case 114:
					array[26] = (byte)num3;
					num4 = 56;
					if (XMBO4ZsCO9rvrAc7d1())
					{
						goto IL_0d3e;
					}
					goto case 225;
				case 225:
					array[0] = 227;
					num4 = 118;
					if (XMBO4ZsCO9rvrAc7d1())
					{
						goto IL_0d3e;
					}
					goto case 155;
				case 5:
					array[28] = (byte)num3;
					num = 185;
					continue;
				case 71:
					array[11] = (byte)num3;
					num4 = 288;
					goto IL_0d3e;
				case 210:
					num3 = 112 + 84;
					num4 = 180;
					if (!zCqUXvftq408voPjcW())
					{
						goto IL_0d3e;
					}
					goto case 28;
				case 28:
					array[23] = 172;
					num = 132;
					continue;
				case 298:
					array[22] = 102;
					num = 313;
					continue;
				case 270:
					UeYXbyy5BPDGJKnHVS(true);
					num4 = 181;
					goto IL_0d3e;
				case 211:
					array2[1] = (byte)num5;
					num = 159;
					continue;
				case 51:
					array[31] = 44;
					num4 = 226;
					if (!zCqUXvftq408voPjcW())
					{
						goto IL_0d3e;
					}
					goto case 239;
				case 10:
					num3 = 230 - 76;
					num6 = 320;
					goto IL_0d3a;
				case 139:
					if (snVtANiJ0G.Length != 0)
					{
						goto case 244;
					}
					num4 = 315;
					if (!zCqUXvftq408voPjcW())
					{
						goto IL_0d3e;
					}
					goto case 115;
				case 83:
					array[1] = (byte)num7;
					num4 = 165;
					goto IL_0d3e;
				case 125:
					num3 = 196 - 65;
					num6 = 351;
					goto IL_0d3a;
				case 244:
					num2 = SYmO2nwL2BmGdBkbAX(snVtANiJ0G, P_0);
					num = 354;
					continue;
				case 115:
					array[21] = 199;
					num6 = 200;
					goto IL_0d3a;
				case 41:
					num3 = 176 - 92;
					num = 274;
					continue;
				case 168:
					array[23] = (byte)num7;
					num4 = 172;
					if (zCqUXvftq408voPjcW())
					{
						goto case 175;
					}
					goto IL_0d3e;
				case 67:
					num5 = 128 - 42;
					num6 = 182;
					goto IL_0d3a;
				case 109:
					array[13] = (byte)num7;
					num4 = 289;
					goto IL_0d3e;
				case 147:
					num7 = 159 - 53;
					num6 = 222;
					goto IL_0d3a;
				case 217:
					array2[11] = (byte)num8;
					num = 297;
					continue;
				case 213:
					array[28] = 89;
					num4 = 262;
					if (0 == 0)
					{
						goto IL_0d3e;
					}
					goto case 98;
				case 98:
					num8 = 185 + 68;
					num6 = 321;
					goto IL_0d3a;
				case 273:
					num8 = 124 + 81;
					num4 = 33;
					if (!XMBO4ZsCO9rvrAc7d1())
					{
						goto case 308;
					}
					goto IL_0d3e;
				case 284:
					array2[9] = (byte)num5;
					num4 = 202;
					goto IL_0d3e;
				case 60:
					array[11] = 114;
					num6 = 194;
					goto IL_0d3a;
				case 25:
					array[21] = (byte)num3;
					num4 = 149;
					if (XMBO4ZsCO9rvrAc7d1())
					{
						goto IL_0d3e;
					}
					goto case 195;
				case 195:
					num3 = 168 - 56;
					num6 = 256;
					goto IL_0d3a;
				case 100:
					array[11] = (byte)num3;
					num6 = 176;
					goto IL_0d3a;
				case 62:
					num8 = 22 + 37;
					num6 = 2;
					goto IL_0d3a;
				case 34:
					array2[3] = 8;
					num4 = 113;
					goto IL_0d3e;
				case 42:
					array[9] = 169;
					num = 237;
					continue;
				case 302:
					array[3] = (byte)num3;
					num6 = 221;
					goto IL_0d3a;
				case 265:
					array[3] = (byte)num3;
					num = 209;
					continue;
				case 267:
					array[19] = 178;
					num = 23;
					continue;
				case 116:
					array3[9] = array4[4];
					num = 268;
					continue;
				case 269:
					array2[7] = (byte)num8;
					num = 66;
					continue;
				case 69:
					array2[2] = (byte)num5;
					num = 348;
					continue;
				case 91:
					array2[0] = 99;
					num6 = 4;
					goto IL_0d3a;
				case 353:
					array[25] = (byte)num3;
					num = 350;
					continue;
				case 8:
					array[15] = (byte)num3;
					num = 239;
					continue;
				case 183:
					array[16] = 66;
					num4 = 279;
					if (0 == 0)
					{
						goto IL_0d3e;
					}
					goto case 261;
				case 261:
					num3 = 144 + 81;
					num4 = 97;
					goto IL_0d3e;
				case 54:
					array2[9] = 143;
					num4 = 271;
					if (XMBO4ZsCO9rvrAc7d1())
					{
						goto IL_0d3e;
					}
					goto case 185;
				case 185:
					num7 = 190 - 63;
					num6 = 65;
					goto IL_0d3a;
				case 281:
					EkiaPcULms94qp7p7R(cryptoStream, array6, 0, array6.Length);
					num4 = 198;
					if (XMBO4ZsCO9rvrAc7d1())
					{
						goto IL_0d3e;
					}
					goto case 257;
				case 208:
					array[20] = 166;
					num4 = 72;
					if (0 == 0)
					{
						goto IL_0d3e;
					}
					goto case 143;
				case 143:
					array2[15] = (byte)num5;
					goto case 250;
				case 155:
					array2[11] = (byte)num5;
					num4 = 309;
					if (XMBO4ZsCO9rvrAc7d1())
					{
						goto IL_0d3e;
					}
					goto case 106;
				case 106:
					array[30] = (byte)num7;
					num6 = 257;
					goto IL_0d3a;
				case 224:
					array[27] = (byte)num3;
					num = 293;
					continue;
				case 53:
					array[21] = (byte)num7;
					num = 117;
					continue;
				case 156:
					num3 = 54 + 122;
					num = 272;
					continue;
				case 299:
					array[1] = (byte)num3;
					num = 310;
					continue;
				case 33:
					array2[15] = (byte)num8;
					num6 = 283;
					goto IL_0d3a;
				case 94:
					num3 = 166 - 55;
					num = 276;
					continue;
				case 117:
					num3 = 14 + 11;
					num4 = 25;
					goto IL_0d3e;
				case 209:
					array[3] = 206;
					num4 = 243;
					if (0 == 0)
					{
						goto IL_0d3e;
					}
					goto case 180;
				case 180:
					array[17] = (byte)num3;
					num6 = 335;
					goto IL_0d3a;
				case 241:
					snVtANiJ0G = (byte[])o7FOItCaaXsLhXvOl3(memoryStream);
					num = 80;
					continue;
				case 205:
					num3 = 66 + 102;
					num4 = 207;
					if (!XMBO4ZsCO9rvrAc7d1())
					{
						goto case 32;
					}
					goto IL_0d3e;
				case 138:
					array[26] = (byte)num3;
					num6 = 286;
					goto IL_0d3a;
				case 343:
					num8 = 204 - 68;
					num6 = 162;
					goto IL_0d3a;
				case 85:
					num5 = 143 - 47;
					num4 = 211;
					if (true)
					{
						goto IL_0d3e;
					}
					goto case 333;
				case 333:
					array2[6] = (byte)num5;
					num4 = 145;
					goto IL_0d3e;
				case 43:
					num7 = 70 + 48;
					num = 83;
					continue;
				case 160:
					array2[10] = (byte)num5;
					num6 = 277;
					goto IL_0d3a;
				case 304:
					array[25] = 117;
					num6 = 57;
					goto IL_0d3a;
				case 27:
					num5 = 37 + 53;
					num4 = 319;
					goto IL_0d3e;
				case 262:
					array[29] = 122;
					num4 = 205;
					if (true)
					{
						goto IL_0d3e;
					}
					goto case 322;
				case 322:
					array2[13] = (byte)num5;
					num4 = 295;
					if (0 == 0)
					{
						goto IL_0d3e;
					}
					goto case 346;
				case 346:
					array[15] = (byte)num7;
					num4 = 263;
					if (!zCqUXvftq408voPjcW())
					{
						goto IL_0d3e;
					}
					goto case 330;
				case 330:
					array[21] = 181;
					num = 298;
					continue;
				case 184:
					num3 = 245 - 81;
					num4 = 187;
					if (!XMBO4ZsCO9rvrAc7d1())
					{
						goto case 74;
					}
					goto IL_0d3e;
				case 257:
					num7 = 68 + 42;
					num = 234;
					continue;
				case 59:
					array2[14] = 211;
					num6 = 343;
					goto IL_0d3a;
				case 254:
					array2[4] = (byte)num5;
					num4 = 67;
					if (true)
					{
						goto IL_0d3e;
					}
					goto case 77;
				case 77:
					array[2] = 88;
					num = 7;
					continue;
				case 305:
					array[1] = 129;
					num4 = 43;
					goto IL_0d3e;
				case 87:
					array[27] = (byte)num7;
					num4 = 235;
					goto IL_0d3e;
				case 127:
					array[18] = 124;
					num6 = 147;
					goto IL_0d3a;
				case 101:
					num3 = 205 - 68;
					num4 = 341;
					if (true)
					{
						goto IL_0d3e;
					}
					goto case 176;
				case 176:
					num7 = 84 - 82;
					num = 223;
					continue;
				case 264:
					array2[4] = 147;
					num6 = 167;
					goto IL_0d3a;
				case 344:
					array2[0] = (byte)num8;
					num4 = 96;
					if (0 == 0)
					{
						goto IL_0d3e;
					}
					goto case 2;
				case 2:
					array2[11] = (byte)num8;
					num4 = 68;
					if (XMBO4ZsCO9rvrAc7d1())
					{
						goto IL_0d3e;
					}
					goto case 227;
				case 306:
					array3[7] = array4[3];
					num4 = 116;
					goto IL_0d3e;
				case 326:
					array[5] = 114;
					num6 = 231;
					goto IL_0d3a;
				case 263:
					array[15] = 122;
					num6 = 183;
					goto IL_0d3a;
				case 64:
					array2[14] = 128;
					num4 = 59;
					if (XMBO4ZsCO9rvrAc7d1())
					{
						goto IL_0d3e;
					}
					goto case 144;
				case 144:
					array[10] = 102;
					num4 = 0;
					if (0 == 0)
					{
						goto IL_0d3e;
					}
					goto case 154;
				case 154:
					num8 = 106 + 39;
					num = 344;
					continue;
				case 18:
					array2[6] = 103;
					num6 = 48;
					goto IL_0d3a;
				case 309:
					array2[12] = 98;
					num4 = 16;
					if (0 == 0)
					{
						goto IL_0d3e;
					}
					goto case 118;
				case 118:
					num7 = 57 - 44;
					num = 6;
					continue;
				case 170:
					num7 = 19 + 7;
					num4 = 163;
					if (zCqUXvftq408voPjcW())
					{
						goto case 157;
					}
					goto IL_0d3e;
				case 17:
					array[7] = (byte)num7;
					num = 129;
					continue;
				case 321:
					array2[5] = (byte)num8;
					num6 = 18;
					goto IL_0d3a;
				case 234:
					array[30] = (byte)num7;
					num = 49;
					continue;
				case 348:
					array2[3] = 103;
					num6 = 190;
					goto IL_0d3a;
				case 104:
					array[8] = 160;
					num6 = 195;
					goto IL_0d3a;
				case 191:
					num3 = 110 + 51;
					num6 = 114;
					goto IL_0d3a;
				case 150:
					array[10] = 86;
					num4 = 230;
					if (XMBO4ZsCO9rvrAc7d1())
					{
						goto IL_0d3e;
					}
					goto case 269;
				case 283:
					array3 = array2;
					num6 = 342;
					goto IL_0d3a;
				case 206:
					array2[9] = 168;
					num6 = 328;
					goto IL_0d3a;
				case 280:
					num7 = 102 + 80;
					num4 = 346;
					goto IL_0d3e;
				case 245:
					num5 = 100 + 97;
					num6 = 322;
					goto IL_0d3a;
				case 105:
					array[27] = (byte)num3;
					num = 55;
					continue;
				case 3:
					num5 = 96 + 100;
					num = 69;
					continue;
				case 82:
					array2[5] = (byte)num5;
					num4 = 98;
					if (true)
					{
						goto IL_0d3e;
					}
					goto case 310;
				case 310:
					num7 = 91 + 49;
					num4 = 86;
					goto IL_0d3e;
				case 75:
					array[5] = (byte)num3;
					num4 = 92;
					if (zCqUXvftq408voPjcW())
					{
						break;
					}
					goto IL_0d3e;
				case 92:
					array[6] = 126;
					num4 = 196;
					if (0 == 0)
					{
						goto IL_0d3e;
					}
					goto case 186;
				case 186:
					array[22] = (byte)num7;
					num4 = 78;
					if (true)
					{
						goto IL_0d3e;
					}
					goto case 20;
				case 20:
					num5 = 163 - 54;
					num4 = 26;
					if (true)
					{
						goto IL_0d3e;
					}
					goto case 153;
				case 153:
					array2[13] = 143;
					num4 = 140;
					goto IL_0d3e;
				case 289:
					array[13] = 121;
					num4 = 218;
					goto IL_0d3e;
				case 167:
					array2[5] = 120;
					num = 103;
					continue;
				case 319:
					array2[1] = (byte)num5;
					num6 = 233;
					goto IL_0d3a;
				case 119:
					array[25] = (byte)num3;
					num6 = 304;
					goto IL_0d3a;
				case 152:
					transform = (ICryptoTransform)RonHbqeinriBB4hTvN(rijndaelManaged, array5, array3);
					num = 300;
					continue;
				case 200:
					num7 = 107 + 24;
					num6 = 53;
					goto IL_0d3a;
				case 141:
					array[25] = 62;
					num6 = 248;
					goto IL_0d3a;
				case 328:
					array2[10] = 140;
					num6 = 258;
					goto IL_0d3a;
				case 248:
					num3 = 195 - 65;
					num4 = 119;
					if (true)
					{
						goto IL_0d3e;
					}
					goto case 172;
				case 172:
					num3 = 3 + 121;
					num4 = 157;
					goto IL_0d3e;
				case 203:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num6 = 281;
					goto IL_0d3a;
				case 290:
					array[19] = (byte)num3;
					num4 = 125;
					goto IL_0d3e;
				case 339:
					num7 = 132 - 44;
					num6 = 317;
					goto IL_0d3a;
				case 7:
					num7 = 129 + 103;
					num4 = 303;
					if (zCqUXvftq408voPjcW())
					{
						goto case 162;
					}
					goto IL_0d3e;
				case 29:
					av05bAZtRyAfD3msWL(binaryReader);
					num = 244;
					continue;
				case 47:
					array[1] = (byte)num7;
					num6 = 305;
					goto IL_0d3a;
				case 182:
					array2[4] = (byte)num5;
					num4 = 133;
					if (!zCqUXvftq408voPjcW())
					{
						goto IL_0d3e;
					}
					goto case 91;
				case 271:
					num5 = 54 + 124;
					num4 = 284;
					goto IL_0d3e;
				case 148:
					num7 = 75 - 38;
					num = 278;
					continue;
				case 347:
					num5 = 142 - 44;
					num4 = 110;
					goto IL_0d3e;
				case 229:
					array[4] = 217;
					num4 = 148;
					if (XMBO4ZsCO9rvrAc7d1())
					{
						goto IL_0d3e;
					}
					goto case 214;
				case 214:
					array[0] = 87;
					num4 = 188;
					goto IL_0d3e;
				case 199:
					array2[2] = (byte)num8;
					num4 = 24;
					if (true)
					{
						goto IL_0d3e;
					}
					goto case 291;
				case 291:
					num3 = 213 + 37;
					num4 = 299;
					goto IL_0d3e;
				case 102:
					num7 = 42 + 5;
					num4 = 109;
					goto IL_0d3e;
				case 331:
					array[1] = 87;
					num6 = 291;
					goto IL_0d3a;
				case 316:
					num3 = 202 - 67;
					num4 = 138;
					goto IL_0d3e;
				case 220:
					array[0] = (byte)num3;
					num = 225;
					continue;
				case 307:
					num5 = 169 - 56;
					num4 = 332;
					if (true)
					{
						goto IL_0d3e;
					}
					goto case 243;
				case 243:
					num3 = 174 - 58;
					num4 = 302;
					if (!zCqUXvftq408voPjcW())
					{
						goto IL_0d3e;
					}
					goto case 223;
				case 223:
					array[11] = (byte)num7;
					num = 345;
					continue;
				case 349:
					array[29] = 8;
					num4 = 238;
					if (XMBO4ZsCO9rvrAc7d1())
					{
						goto IL_0d3e;
					}
					goto case 194;
				case 194:
					num3 = 31 + 112;
					num4 = 71;
					goto IL_0d3e;
				case 142:
					array2[8] = 171;
					num = 54;
					continue;
				case 260:
					array2[13] = (byte)num8;
					num = 245;
					continue;
				case 253:
					num8 = 253 - 84;
					num4 = 287;
					goto IL_0d3e;
				case 233:
					array2[1] = 114;
					num = 22;
					continue;
				case 124:
					array[18] = 112;
					num4 = 249;
					if (true)
					{
						goto IL_0d3e;
					}
					goto case 70;
				case 70:
					array[16] = 87;
					num = 9;
					continue;
				case 279:
					num3 = 165 - 55;
					num = 266;
					continue;
				case 320:
					array[20] = (byte)num3;
					num = 30;
					continue;
				case 26:
					array2[6] = (byte)num5;
					num4 = 12;
					if (true)
					{
						goto IL_0d3e;
					}
					goto case 40;
				case 40:
					array3[15] = array4[7];
					num4 = 312;
					goto IL_0d3e;
				case 275:
					array2[10] = (byte)num8;
					num = 136;
					continue;
				case 72:
					array[20] = 173;
					num4 = 169;
					if (true)
					{
						goto IL_0d3e;
					}
					goto case 193;
				case 193:
					num8 = 110 + 34;
					num = 32;
					continue;
				case 48:
					array2[6] = 144;
					num6 = 20;
					goto IL_0d3a;
				case 86:
					array[2] = (byte)num7;
					num4 = 73;
					if (0 == 0)
					{
						goto IL_0d3e;
					}
					goto case 212;
				case 212:
					array2[2] = (byte)num5;
					num = 3;
					continue;
				case 122:
					array[11] = (byte)num3;
					num6 = 60;
					goto IL_0d3a;
				case 50:
					array2[11] = 164;
					num4 = 62;
					goto IL_0d3e;
				case 238:
					num7 = 56 + 103;
					num6 = 106;
					goto IL_0d3a;
				case 15:
					array[13] = 54;
					num = 102;
					continue;
				case 293:
					array[27] = 102;
					num6 = 156;
					goto IL_0d3a;
				case 76:
					array3[5] = array4[2];
					num6 = 306;
					goto IL_0d3a;
				case 177:
					array2[4] = 91;
					num = 264;
					continue;
				case 178:
					array[0] = 129;
					num6 = 131;
					goto IL_0d3a;
				case 165:
					array[1] = 123;
					num6 = 331;
					goto IL_0d3a;
				case 56:
					num3 = 79 + 84;
					num6 = 14;
					goto IL_0d3a;
				case 12:
					num5 = 153 - 51;
					num4 = 333;
					goto IL_0d3e;
				case 250:
				case 323:
					array2[15] = 128;
					num6 = 301;
					goto IL_0d3a;
				case 258:
					num5 = 127 - 42;
					num = 160;
					continue;
				case 57:
					num7 = 177 - 59;
					num6 = 308;
					goto IL_0d3a;
				case 113:
					array2[4] = 113;
					num4 = 166;
					if (0 == 0)
					{
						goto IL_0d3e;
					}
					goto case 324;
				case 324:
					array2[7] = 107;
					num = 347;
					continue;
				case 242:
					array[8] = 151;
					num6 = 107;
					goto IL_0d3a;
				case 341:
					array[4] = (byte)num3;
					num = 229;
					continue;
				case 134:
					num3 = 84 + 10;
					num = 122;
					continue;
				case 301:
					num8 = 137 - 45;
					num6 = 161;
					goto IL_0d3a;
				case 246:
					array2[6] = 196;
					num = 193;
					continue;
				case 129:
					array[8] = 126;
					num4 = 104;
					if (XMBO4ZsCO9rvrAc7d1())
					{
						goto IL_0d3e;
					}
					goto case 100;
				case 317:
					array[5] = (byte)num7;
					num = 326;
					continue;
				case 232:
					array[11] = 86;
					num4 = 134;
					if (true)
					{
						goto IL_0d3e;
					}
					goto case 235;
				case 235:
					num3 = 236 - 78;
					num4 = 90;
					goto IL_0d3e;
				case 81:
					array[24] = 153;
					num6 = 314;
					goto IL_0d3a;
				case 202:
					array2[9] = 154;
					num4 = 206;
					if (0 == 0)
					{
						goto IL_0d3e;
					}
					goto case 228;
				case 228:
					num3 = 68 + 100;
					num4 = 224;
					if (XMBO4ZsCO9rvrAc7d1())
					{
						goto IL_0d3e;
					}
					goto case 311;
				case 311:
					array[6] = 65;
					num4 = 88;
					goto IL_0d3e;
				case 132:
					num7 = 118 + 79;
					num = 168;
					continue;
				case 111:
					num7 = 198 - 66;
					num = 47;
					continue;
				case 192:
					array2[11] = (byte)num5;
					num4 = 173;
					goto IL_0d3e;
				case 19:
					array[17] = 126;
					num6 = 210;
					goto IL_0d3a;
				case 249:
					num3 = 80 + 89;
					num4 = 290;
					if (!zCqUXvftq408voPjcW())
					{
						goto IL_0d3e;
					}
					goto case 187;
				case 187:
					array[20] = (byte)num3;
					num4 = 208;
					if (0 == 0)
					{
						goto IL_0d3e;
					}
					goto case 294;
				case 294:
					num3 = 8 + 30;
					num6 = 265;
					goto IL_0d3a;
				case 4:
					array2[0] = 89;
					num6 = 27;
					goto IL_0d3a;
				case 297:
					num5 = 151 - 50;
					num = 192;
					continue;
				case 313:
					array[22] = 213;
					num4 = 128;
					goto IL_0d3e;
				case 84:
					array[28] = 165;
					num = 164;
					continue;
				case 78:
					array[23] = 46;
					num4 = 28;
					if (0 == 0)
					{
						goto IL_0d3e;
					}
					goto case 335;
				case 335:
					array[17] = 94;
					num = 41;
					continue;
				case 354:
					try
					{
						return (string)aLubOFPLRySaaR4NTK(ag9ntZkwtrRpGT8pvo(), snVtANiJ0G, P_0 + 4, num2);
					}
					catch
					{
					}
					return "";
				case 312:
					rijndaelManaged = new RijndaelManaged();
					num4 = 135;
					goto IL_0d3e;
				case 300:
					break;
					IL_0d3a:
					num4 = num6;
					goto IL_0d3e;
					IL_0d3e:
					num = num4;
					continue;
				}
				memoryStream = new MemoryStream();
				num = 203;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[rbrwO1ewunyVubEscq(typeof(OWwpBsspLF0Q0PqPbZ/rbrwO1ewunyVubEscq/tLZs6ra904wKjlRaP2<object>[]))]
		internal static string PTWSNqlZ3(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void V09NWQLD5(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int LNH3MKaHq(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr eRM1yT1XY(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void z2hFmDIGT()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void Gp0P1MISp()
		{
			try
			{
				RSACryptoServiceProvider.UseMachineKeyStore = true;
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object eO1B3vuXb(object P_0)
		{
			try
			{
				if (File.Exists(((Assembly)P_0).Location))
				{
					return ((Assembly)P_0).Location;
				}
			}
			catch
			{
			}
			try
			{
				if (File.Exists(((Assembly)P_0).GetName().CodeBase.ToString().Replace("file:///", "")))
				{
					return ((Assembly)P_0).GetName().CodeBase.ToString().Replace("file:///", "");
				}
			}
			catch
			{
			}
			try
			{
				if (File.Exists(P_0.GetType().GetProperty("Location").GetValue(P_0, new object[0])
					.ToString()))
				{
					return P_0.GetType().GetProperty("Location").GetValue(P_0, new object[0])
						.ToString();
				}
			}
			catch
			{
			}
			return "";
		}

		[DllImport("kernel32", EntryPoint = "LoadLibrary")]
		public static extern IntPtr n6XCKMt5T(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr txioKIrjU(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int yFLbjHloR(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int hpenlJ1bU(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int o2q4XS5U3(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr VhAHwyXBH(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int OcuQxPgiv(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[rbrwO1ewunyVubEscq(typeof(OWwpBsspLF0Q0PqPbZ/rbrwO1ewunyVubEscq/tLZs6ra904wKjlRaP2<object>[]))]
		private static byte[] g4IdZXiRD(string P_0)
		{
			using FileStream fileStream = new FileStream(P_0, FileMode.Open, FileAccess.Read, FileShare.Read);
			int num = 0;
			long length = fileStream.Length;
			int num2 = (int)length;
			byte[] array = new byte[num2];
			while (num2 > 0)
			{
				int num3 = fileStream.Read(array, num, num2);
				num += num3;
				num2 -= num3;
			}
			return array;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[rbrwO1ewunyVubEscq(typeof(OWwpBsspLF0Q0PqPbZ/rbrwO1ewunyVubEscq/tLZs6ra904wKjlRaP2<object>[]))]
		private static byte[] yMs7Fype8(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				153, 77, 79, 79, 63, 167, 237, 143, 32, 40,
				17, 188, 5, 168, 143, 34, 103, 86, 49, 106,
				204, 10, 52, 133, 178, 112, 162, 31, 50, 11,
				194, 186
			};
			rijndael.IV = new byte[16]
			{
				34, 62, 109, 230, 206, 132, 64, 39, 191, 132,
				83, 215, 181, 0, 109, 251
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] u2fYDHT38()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] RNszufmrt()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] usKtvkkaOD()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] mcutt3hrrG()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] mvDtheGC5Z()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] AeOtLACle9()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] rGPt87OkZF()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] xtttUx2quv()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] WcetE3oaDR()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] dZWtw1xf0y()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public OWwpBsspLF0Q0PqPbZ()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type hLWFLIOH9O4mEdljnS(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object hZbliJEYJjaCY6drAx(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object n0Oso1WcLcfVTKeNbb(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void MM561fa5oeDQI1xGHh(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void UeYXbyy5BPDGJKnHVS(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long Q2qZuORoYHFZAHKLZj(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object LfeMx8lwcuFcsLoXKY(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object mB6P3m65J73cN7NFab(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Jm4s4RAQZvsapjdsrs(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void CaeReJBN1XBuTPIBWI(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object RonHbqeinriBB4hTvN(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void EkiaPcULms94qp7p7R(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void sPIYthjk4iTkpOw4av(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object o7FOItCaaXsLhXvOl3(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void zVxdWITrFmqhlRPGCH(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void av05bAZtRyAfD3msWL(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int SYmO2nwL2BmGdBkbAX(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object ag9ntZkwtrRpGT8pvo()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object aLubOFPLRySaaR4NTK(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool XMBO4ZsCO9rvrAc7d1()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool zCqUXvftq408voPjcW()
		{
			return false;
		}
	}
}
namespace cD5SNHrMKaHqURMyT1
{
	internal class WRG7PT6WNqlZ3H09WQ
	{
		private static bool U9Dty9Sn95;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void z2YwkIszWydt1()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public WRG7PT6WNqlZ3H09WQ()
		{
		}
	}
}
