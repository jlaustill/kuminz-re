using System;
using System.Collections;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using COLLECTIONLib;

[assembly: Guid("62E2F7C1-6D5C-11D4-8A5F-00062999E309")]
[assembly: ImportedFromTypeLib("ECMSERVICESAPILib")]
[assembly: TypeLibVersion(1, 0)]
[assembly: AssemblyVersion("7.6.0.272")]
namespace ECMSERVICESAPILib;

[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("69DC952C-033A-4B5E-AB09-34A4B6B7E15E")]
public interface IAccessTypes
{
	[DispId(1)]
	string AccessType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
public enum AccessTypesEnum
{
	AT_Read,
	AT_Write,
	AT_All
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0015
{
	AT_Read,
	AT_Write,
	AT_All
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("F63B87AA-911A-456E-BDF6-2FF61B874ECD")]
public interface IArray
{
	[DispId(1)]
	int Dimension
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	object Items
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	[DispId(3)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[Guid("1135219C-5307-4457-A068-7848DBAD3218")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IArrays
{
	[DispId(1)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	IArray Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("15272071-D544-4DA1-8012-BDFF471F364F")]
public interface IArrayDefinition
{
	[DispId(1)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	BSTRCollection ParameterIDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(4)]
	int ModuleType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("3E55AC46-EF4F-472E-A4F0-A61EE9BC9056")]
public interface IArrayDefinitions
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IArrayDefinition GetArrayDefinition([In][MarshalAs(UnmanagedType.BStr)] string arrayId, int ModuleType);
}
[ComImport]
[Guid("78FDDD44-B30E-4FD7-B7DA-13E9394ADD0B")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICommunicationsLock
{
	[DispId(1)]
	bool IsReadLocked
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	bool IsWriteLocked
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[DispId(3)]
	string Owner
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(4)]
	string Reason
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void Lock([In][MarshalAs(UnmanagedType.Interface)] IDataService DataService, [In][ComAliasName("ECMSERVICESAPILib.LockTypesEnum")] LockTypesEnum type, [In][MarshalAs(UnmanagedType.BStr)] string Owner, [In][MarshalAs(UnmanagedType.BStr)] string Reason);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void Unlock([In][MarshalAs(UnmanagedType.Interface)] IDataService DataService);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	bool CanDisconnect();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void RegisterDisconnectCallback([MarshalAs(UnmanagedType.Interface)] IDisconnectCallback pCallback, ref int pCookie);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void UnregisterDisconnectCallback(int cookie);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("39EAF40D-D4E2-4B3A-9956-37D7DDB216D3")]
public interface IDataService
{
	[DispId(1)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	string CurrentModuleID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	IConnection Connection
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IDependencyDefinitions CheckDependencies([In][MarshalAs(UnmanagedType.BStr)] string ID, [In][ComAliasName("ECMSERVICESAPILib.ReadTypesEnum")] ReadTypesEnum type);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	object Read([In][MarshalAs(UnmanagedType.BStr)] string ID, [In][ComAliasName("ECMSERVICESAPILib.ReadTypesEnum")] ReadTypesEnum type);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	object Write([In][MarshalAs(UnmanagedType.BStr)] string ID, [In][ComAliasName("ECMSERVICESAPILib.WriteTypesEnum")] WriteTypesEnum type, [In][MarshalAs(UnmanagedType.Struct)] object WriteData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	bool IsReadBlocked([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	bool IsWriteBlocked([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

	[DispId(9)]
	IGroupDefinitions GroupDefinitions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	[TypeLibFunc(TypeLibFuncFlags.FHidden)]
	void SetDesiredValue([In][MarshalAs(UnmanagedType.BStr)] string ID, [In][MarshalAs(UnmanagedType.Struct)] object WriteData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	bool IsWritable([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	bool IsReadable([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[TypeLibFunc(TypeLibFuncFlags.FHidden)]
	void ClearDesiredValue([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	object ReadWithAge([In][MarshalAs(UnmanagedType.BStr)] string ID, [In][ComAliasName("ECMSERVICESAPILib.ReadTypesEnum")] ReadTypesEnum type, [In] uint age);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetDesiredValue([In][MarshalAs(UnmanagedType.BStr)] string ID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	void PingModule();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	bool IsReadBlockedEx([In][MarshalAs(UnmanagedType.BStr)] string ParameterID, [In] bool useCashing);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetRawDesiredValue([In][MarshalAs(UnmanagedType.BStr)] string ID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	object GetNewDataService();
}
public enum LockTypesEnum
{
	CL_ReadLock,
	CL_WriteLock
}
[ComImport]
[Guid("ED5DB7AB-5FBF-4460-98AB-846A28A4491C")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IDisconnectCallback
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	bool AllowDisconnect([In] int cookie);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void HandleDisconnect([In] int cookie);
}
[ComImport]
[Guid("82791E31-98E0-427A-B69F-A71B5F9DC70C")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IConnection
{
	[DispId(1)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	bool IsConnected
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[ComAliasName("ECMSERVICESAPILib.ConnectionTypesEnum")]
	[DispId(4)]
	ConnectionTypesEnum type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ECMSERVICESAPILib.ConnectionTypesEnum")]
		get;
	}

	[DispId(5)]
	ISystem System
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(6)]
	IDataLink DataLink
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void Connect([In][MarshalAs(UnmanagedType.BStr)] string connectionInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void Disconnect();

	[DispId(9)]
	string connectionInfo
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	void ReestablishCommunication([In][MarshalAs(UnmanagedType.BStr)] string bstrUserSerialNumber, [In][MarshalAs(UnmanagedType.BStr)] string bstrToolSerialNumber, [In] bool vbRSGREnabled);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	void HardDisconnect();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	void CloseCLIPSession();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	void ReconnectToPreviousSession([In][MarshalAs(UnmanagedType.BStr)] string bstrXMLSessionInfo, [In][MarshalAs(UnmanagedType.BStr)] string bstrModuleID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	void Reinitialize();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ISystems GetDetectedSystems();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	void ConnectSystem([In][MarshalAs(UnmanagedType.Struct)] object ModuleAddressesInSystem);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("C1155D88-9CFC-4A2B-A246-38D83159CB0A")]
public interface IDependencyDefinitions
{
	[DispId(1)]
	IDependencyDefinition Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
public enum ReadTypesEnum
{
	RT_Parameter = 1,
	RT_Array,
	RT_DynamicGroup,
	RT_UsageGroup,
	RT_FeatureGroup
}
public enum WriteTypesEnum
{
	WT_Parameter = 1,
	WT_Group
}
[ComImport]
[Guid("B8A1FD13-71DF-4139-97A6-9C0FFC9577C3")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IGroupDefinitions
{
	[DispId(1)]
	IGroupDefinition GroupDefinition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IGroupDefinition Add([In][MarshalAs(UnmanagedType.Interface)] BSTRCollection pCollection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void Remove([In][MarshalAs(UnmanagedType.BStr)] string groupId);

	[DispId(4)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}
}
public enum ConnectionTypesEnum
{
	CT_NoConnection,
	CT_Physical,
	CT_Simulator,
	CT_Image,
	CT_PCL_PJ1939,
	CT_PCL_UDS,
	CT_Image_Print
}
[ComImport]
[Guid("93C06C03-D142-4DD5-8E5B-B822AFF1F024")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ISystem
{
	[DispId(1)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	string PrimaryModuleID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	IModules Modules
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(4)]
	ICommunicationsLock CommunicationsLock
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(5)]
	int type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
	}

	[DispId(6)]
	ISmartDevices SmartDevices
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[Guid("0DC7C46D-BEB0-4076-88CB-05D4BBFFBF70")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IDataLink
{
	[DispId(1)]
	[ComAliasName("ECMSERVICESAPILib.DataLinkTypesEnum")]
	DataLinkTypesEnum type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: ComAliasName("ECMSERVICESAPILib.DataLinkTypesEnum")]
		get;
	}

	[DispId(2)]
	string FirmwareVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	int BaudRate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[DispId(4)]
	int Channel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}

	[ComAliasName("ECMSERVICESAPILib.DataLinkProtocolsEnum")]
	[DispId(5)]
	DataLinkProtocolsEnum Protocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("ECMSERVICESAPILib.DataLinkProtocolsEnum")]
		get;
	}

	[DispId(6)]
	int MemoryAddress
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[DispId(7)]
	int PortAddress
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void YieldResources();

	[DispId(10)]
	int Irq
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("1C12016B-2574-434C-83D3-F0D4F3C7C700")]
public interface ISystems
{
	[DispId(1)]
	ISystem Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0008
{
	CT_NoConnection,
	CT_Physical,
	CT_Simulator,
	CT_Image,
	CT_PCL_PJ1939,
	CT_PCL_UDS,
	CT_Image_Print
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("E9AE2B93-26A5-4E5F-B885-0DFD874A2A40")]
public interface IModules
{
	[DispId(1)]
	IModule Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("457726AF-3BC0-466A-86A3-E7989428EB6E")]
public interface ISmartDevices
{
	[DispId(1)]
	ISmartDevice Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("66317507-BC82-43F3-9E7C-B1025096B65A")]
public interface IModule
{
	[DispId(1)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	int SourceAddress
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[DispId(4)]
	int ModuleType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}

	[DispId(5)]
	IGroupDefinitions GroupDefinitions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(6)]
	int HarnessKeyStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[DispId(7)]
	string ServiceECMMarketingName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(8)]
	int DetectType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		get;
	}

	[DispId(9)]
	bool IsConnected
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		get;
	}
}
[ComImport]
[Guid("C5801F16-EB56-11D6-AC15-0004AC9669DA")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IGroupDefinition
{
	[DispId(1)]
	BSTRCollection ParameterIDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void Add([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void Remove([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

	[DispId(6)]
	IGroupWriteData GroupWriteData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("5AF07523-C337-4B52-B5C8-304B581E5541")]
public interface IGroupWriteData
{
	[DispId(1)]
	BSTRCollection ParameterIDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	object DesiredValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	bool HasDesiredValue([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void RemoveParameter([In][MarshalAs(UnmanagedType.BStr)] string ParameterID);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("CEC628FB-259F-4A0B-8704-44157A0655DF")]
public interface ISmartDevice
{
	[DispId(1)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	int SourceAddress
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[DispId(4)]
	int SmartDeviceType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}

	[DispId(5)]
	IGroupDefinitions GroupDefinitions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
public enum DataLinkTypesEnum
{
	DLT_None,
	DLT_DearbornCCan,
	DLT_Parasoft,
	DLT_LinkSimulator,
	DLT_Inline,
	DLT_Cancard,
	DLT_AC2,
	DLT_INXRF,
	DLT_DearbornCCanBTS,
	DLT_Modem,
	DLT_MPSI_Magikey,
	DLT_RP1210A,
	DLT_USB
}
public enum DataLinkProtocolsEnum
{
	DLP_J1939_11,
	DLP_J1939_12,
	DLP_J1708,
	DLP_J1850_Chrys,
	DLP_J1850_GM,
	DLP_J1850_Ford,
	DLP_ISO11898,
	DLP_CAN_11Bit_Id,
	DLP_USB_11
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0006
{
	DLT_None,
	DLT_DearbornCCan,
	DLT_Parasoft,
	DLT_LinkSimulator,
	DLT_Inline,
	DLT_Cancard,
	DLT_AC2,
	DLT_INXRF,
	DLT_DearbornCCanBTS,
	DLT_Modem,
	DLT_MPSI_Magikey,
	DLT_RP1210A,
	DLT_USB
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0007
{
	DLP_J1939_11,
	DLP_J1939_12,
	DLP_J1708,
	DLP_J1850_Chrys,
	DLP_J1850_GM,
	DLP_J1850_Ford,
	DLP_ISO11898,
	DLP_CAN_11Bit_Id,
	DLP_USB_11
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0009
{
	RT_Parameter = 1,
	RT_Array,
	RT_DynamicGroup,
	RT_UsageGroup,
	RT_FeatureGroup
}
[ComImport]
[Guid("C37883D6-D3F8-4AF6-BD2D-27C7AAA39220")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IDependencyDefinition
{
	[DispId(1)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	string DependencyParameterID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	[ComAliasName("ECMSERVICESAPILib.RuleTypesEnum")]
	RuleTypesEnum RuleType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: ComAliasName("ECMSERVICESAPILib.RuleTypesEnum")]
		get;
	}

	[DispId(4)]
	[ComAliasName("ECMSERVICESAPILib.AccessTypesEnum")]
	AccessTypesEnum AccessType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ECMSERVICESAPILib.AccessTypesEnum")]
		get;
	}

	[DispId(5)]
	string ParameterID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("ECMSERVICESAPILib.DependencyBlockTypeEnum")]
	[DispId(6)]
	DependencyBlockTypeEnum IsBlocking
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: ComAliasName("ECMSERVICESAPILib.DependencyBlockTypeEnum")]
		get;
	}
}
public enum RuleTypesEnum
{
	RT_True,
	RT_False,
	RT_Lower,
	RT_Upper
}
public enum DependencyBlockTypeEnum
{
	BT_False,
	BT_True,
	BT_Unknown
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0016
{
	RT_True,
	RT_False,
	RT_Lower,
	RT_Upper
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0004
{
	BT_False,
	BT_True,
	BT_Unknown
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0010
{
	WT_Parameter = 1,
	WT_Group
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0011
{
	CL_ReadLock,
	CL_WriteLock
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("B65D4591-0168-4F1B-9E6A-E4438DECB0BF")]
public interface IConnections
{
	[DispId(1)]
	IConnection Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IConnection Add([In][ComAliasName("ECMSERVICESAPILib.ConnectionTypesEnum")] ConnectionTypesEnum type);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void Remove([In][MarshalAs(UnmanagedType.BStr)] string connectionID);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("4D16BA30-DF41-4CFE-BAE1-EAA4E08B4213")]
public interface IDataLinkTypes
{
	[DispId(1)]
	string DataLinkType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("7C306502-9BC7-4625-8FBF-2CFE1A751B65")]
public interface IDataServices
{
	[DispId(1)]
	IDataService Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IDataService Add([In][MarshalAs(UnmanagedType.BStr)] string connectionID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void Remove([In][MarshalAs(UnmanagedType.BStr)] string dataServiceID);
}
[ComImport]
[Guid("A89682BE-DAFF-4564-9C23-7BE0489B3B06")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IECMServices
{
	[DispId(1)]
	string ActiveConnectionID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	IDataLinkTypes DataLinkTypes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(3)]
	IDataServices DataServices
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(4)]
	IConnections Connections
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(5)]
	IEnumerations Enumerations
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(6)]
	IUnitDefinitions UnitDefinitions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	IRuleTypes RuleTypes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(8)]
	IAccessTypes AccessTypes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	IParameterDefinitions ParameterDefinitions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	IMonitorServices MonitorServices
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	IUsageDefinitions UsageDefinitions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	IImageServices ImageServices
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(13)]
	IArrayDefinitions ArrayDefinitions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(14)]
	IFeatureDefinitions FeatureDefinitions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(15)]
	IConnectionPointServer ConnectionPointServer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(16)]
	IEnumerationReader EnumerationReader
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("79732A1A-10B4-4DA1-AB92-DB5D9F4850B0")]
public interface IEnumerations
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IEnumeration GetEnumeration([In][MarshalAs(UnmanagedType.BStr)] string enumerationId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetModuleNameFromEnum([In][MarshalAs(UnmanagedType.BStr)] string enumerationId, [In] int ModuleType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IEnumeration GetEnumerationEx([In][MarshalAs(UnmanagedType.BStr)] string enumerationId, [In] int moduleId, [In][MarshalAs(UnmanagedType.BStr)] string connectionID);
}
[ComImport]
[Guid("BCE7CD2B-9635-4E44-8D40-67E84EDFA93E")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IUnitDefinitions
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IUnitDefinition GetUnitDefinition([In][MarshalAs(UnmanagedType.BStr)] string unitId);

	[DispId(2)]
	string UnitsFamilyName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[Guid("45EBA101-3047-40D8-8D98-0D0E3839C12E")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IRuleTypes
{
	[DispId(1)]
	string RuleType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
[ComImport]
[Guid("14483239-A3A3-4C11-8A19-183FC64F9E67")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IParameterDefinitions
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IParameterDefinition GetParameterDefinition([In][MarshalAs(UnmanagedType.BStr)] string ParameterID, [In] int ModuleType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	bool IsParameterSupported([In] int ModuleType, [In][MarshalAs(UnmanagedType.BStr)] string ParameterID, [In][MarshalAs(UnmanagedType.BStr)] string arrayId);
}
[ComImport]
[Guid("AA26FB84-92FD-46A2-AEA9-E7F3833CED29")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
public interface IMonitorServices
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	int Add([In][MarshalAs(UnmanagedType.BStr)] string connectionID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void Remove([In] int monitorServiceID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IMonitorService get_MonitorService([In] int monitorServiceID);

	[DispId(4)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("D919EE68-0585-4636-843F-10B15BD79162")]
public interface IUsageDefinitions
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IUsageDefinition GetUsageDefinition([In][MarshalAs(UnmanagedType.BStr)] string usageId, int ModuleType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	[return: MarshalAs(UnmanagedType.Interface)]
	BSTRCollection GetUsages([In] int ModuleType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	BSTRCollection GetUsagesForParameter([In] int ModuleType, [In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	bool ParameterHasUsage([In] int ModuleType, [In][MarshalAs(UnmanagedType.BStr)] string usageId, [In][MarshalAs(UnmanagedType.BStr)] string ParameterID);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("6157E8D4-0839-42E7-9F81-87B6E142304B")]
public interface IImageServices
{
	[DispId(1)]
	IImageService Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IImageService Add([In][MarshalAs(UnmanagedType.BStr)] string connectionID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void Remove([In][MarshalAs(UnmanagedType.BStr)] string imageServiceID);

	[DispId(5)]
	IOfflineImageDataReader OfflineImageDataReader
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[Guid("732D42C5-29F2-404D-BCF5-1D601773450E")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IFeatureDefinitions
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IFeatureDefinition GetFeatureDefinition([In][MarshalAs(UnmanagedType.BStr)] string featureId, int ModuleType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	[return: MarshalAs(UnmanagedType.Interface)]
	BSTRCollection GetFeatures([In] int ModuleType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	BSTRCollection GetFeaturesForParameter([In] int ModuleType, [In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	bool IsParameterInFeature([In] int ModuleType, [In][MarshalAs(UnmanagedType.BStr)] string featureId, [In][MarshalAs(UnmanagedType.BStr)] string ParameterID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	bool IsFeatureSupported([In] int ModuleType, [In][MarshalAs(UnmanagedType.BStr)] string featureId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	[return: MarshalAs(UnmanagedType.Interface)]
	BSTRCollection GetFeaturesHierarchyForParameter([In] int ModuleType, [In][MarshalAs(UnmanagedType.BStr)] string bstrParameterId, [In] int connectionID, [In] int moduleId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	[return: MarshalAs(UnmanagedType.Interface)]
	BSTRCollection GetFeaturesHierarchyForParameterInModule([In] int ModuleType, [In][MarshalAs(UnmanagedType.BStr)] string bstrParameterId, [In] int connectionID, [In] int moduleId);
}
[ComImport]
[Guid("C86B16EF-5340-11D7-AD83-0006294F9D62")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
public interface IConnectionPointServer
{
}
[ComImport]
[Guid("5D5144F7-3350-48AB-9BD1-F37C1B67A5DC")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IEnumerationReader
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void GetValueNameFromEnum([In] int enumId, [In] int value, [MarshalAs(UnmanagedType.BStr)] out string bstrDisplayValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void GetValueNameFromEnumEx([In] int enumId, [In] int value, [In] int moduleId, [In][MarshalAs(UnmanagedType.BStr)] string connectionID, [MarshalAs(UnmanagedType.BStr)] out string bstrDisplayValue);
}
[ComImport]
[Guid("6EEC8B0E-3520-4156-9A41-659DD0E446D2")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IEnumeration
{
	[DispId(1)]
	BSTRCollection Values
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(5)]
	BSTRCollection EnumRawValues
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(4)]
	int StartingIndex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}
}
[ComImport]
[Guid("BEF2A6B9-80EC-498C-A77D-A3D1B5B6D773")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IUnitDefinition
{
	[DispId(1)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	string ShortName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	string LongName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[Guid("9A6B734A-4210-4276-A9BE-6763F1AFC98B")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IParameterDefinition
{
	[DispId(1)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	[ComAliasName("ECMSERVICESAPILib.ParameterTypesEnum")]
	ParameterTypesEnum ValueType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: ComAliasName("ECMSERVICESAPILib.ParameterTypesEnum")]
		get;
	}

	[DispId(3)]
	string unitId
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(4)]
	string enumerationId
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(5)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(6)]
	string UnitsFamilyID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(7)]
	string UnitsFamilyName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(8)]
	float Precision
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		get;
	}

	[DispId(9)]
	int Decimal
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		get;
	}
}
public enum ParameterTypesEnum
{
	PT_Unknown = 1,
	PT_Long,
	PT_Double,
	PT_Float,
	PT_Text,
	PT_RelTime,
	PT_Binary,
	PT_None
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0017
{
	PT_Unknown = 1,
	PT_Long,
	PT_Double,
	PT_Float,
	PT_Text,
	PT_RelTime,
	PT_Binary,
	PT_None
}
[ComImport]
[Guid("A5A7E3F4-4534-484F-B266-DF6093399BEA")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
public interface IMonitorService
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ILog CreateLog();

	[DispId(2)]
	IMonitors Monitors
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("62C4F9B0-92E9-441A-8469-08BD270A42A2")]
public interface ILog
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void TransferSourceToDestination([In][MarshalAs(UnmanagedType.BStr)] string sourceLocation, [In][MarshalAs(UnmanagedType.BStr)] string destinationLocation);

	[DispId(2)]
	int AutoWriteFrequency
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		set;
	}

	[DispId(3)]
	int LogID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void Flush();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void AutoWriteLogFile();
}
[ComImport]
[Guid("F4285B50-9BB1-486F-8A4D-3E8930D842BC")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
public interface IMonitors
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	int Add([In][MarshalAs(UnmanagedType.Interface)] IGroupDefinition GroupDefinition, [In] int moduleId, [In] int period);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void Remove([In] int monitorID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IMonitor get_Monitor([In] int monitorID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void StartAll();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void StopAll();

	[DispId(6)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void AddParameter([MarshalAs(UnmanagedType.BStr)] string groupDefinitionID, [MarshalAs(UnmanagedType.BStr)] string ParameterID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void RemoveParameter([MarshalAs(UnmanagedType.BStr)] string groupDefinitionID, [MarshalAs(UnmanagedType.BStr)] string ParameterID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void AddParameterLimits([MarshalAs(UnmanagedType.BStr)] string bstrGroupID, [MarshalAs(UnmanagedType.BStr)] string ParameterID, [MarshalAs(UnmanagedType.BStr)] string bstrMaxValue, [MarshalAs(UnmanagedType.BStr)] string bstrMinValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	int AddEx([In][MarshalAs(UnmanagedType.Interface)] IGroupDefinition GroupDefinition, [In] int moduleId, [In] int period, [In][ComAliasName("ECMSERVICESAPILib.ClientContextInfo")] ClientContextInfo ClientContextInfo);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("10810F57-680E-49C8-B077-E262AFA0CF20")]
public interface IMonitor
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void UpdateGlobalPeriod([In] int period);

	[DispId(2)]
	ITriggers Triggers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(3)]
	ILogger Logger
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(4)]
	int monitorID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}

	[DispId(5)]
	bool IsActive
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		set;
	}

	[DispId(6)]
	int DefaultPeriod
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void NotifyMonitorOfLoggerStart();
}
public enum ClientContextInfo
{
	DEFAULT,
	DML,
	MAXCLIENTS
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("71A1D732-C5E3-428F-9725-5D38D68114E1")]
public interface ITriggers
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	int Add([In] int ParameterID, [In][ComAliasName("ECMSERVICESAPILib.TriggerOperatorEnum")] TriggerOperatorEnum comparisonOperator, [In][MarshalAs(UnmanagedType.Struct)] object comparisonOperand);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void Remove([In] int triggerID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ITrigger get_Trigger([In] int triggerID);

	[DispId(4)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("E26598B0-A55E-4AE0-9344-89C90CD8B0D2")]
public interface ILogger
{
	[DispId(1)]
	ITriggers ActivationTriggers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	ITriggers DeactivationTriggers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(3)]
	ILog Log
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(4)]
	bool IsActive
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void AddEventMarker([In] int lEventId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void AddEventMarkerDescription([In] int lEventId, [In][MarshalAs(UnmanagedType.BStr)] string bstrEventDescription);
}
public enum TriggerOperatorEnum
{
	TO_GreaterThan = 1,
	TO_LessThan,
	TO_EqualTo,
	TO_NotEqualTo,
	TO_GreaterThanOrEqualTo,
	TO_LessThanOrEqualTo
}
[ComImport]
[Guid("E05BDA9F-4FA7-4F43-AA7D-0D5A63834170")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
public interface ITrigger
{
	[DispId(1)]
	int triggerID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	bool IsActive
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		set;
	}

	[DispId(3)]
	string ParameterID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(4)]
	[ComAliasName("ECMSERVICESAPILib.TriggerOperatorEnum")]
	TriggerOperatorEnum comparisonOperator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ECMSERVICESAPILib.TriggerOperatorEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: ComAliasName("ECMSERVICESAPILib.TriggerOperatorEnum")]
		set;
	}

	[DispId(5)]
	object comparisonOperand
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0014
{
	TO_GreaterThan = 1,
	TO_LessThan,
	TO_EqualTo,
	TO_NotEqualTo,
	TO_GreaterThanOrEqualTo,
	TO_LessThanOrEqualTo
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0001
{
	DEFAULT,
	DML,
	MAXCLIENTS
}
[ComImport]
[Guid("FA0E577F-3350-45C7-9CFB-B888D3405BF3")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IUsageDefinition
{
	[DispId(1)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	BSTRCollection ParameterIDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(4)]
	int ModuleType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}
}
[ComImport]
[Guid("1A424444-B6A0-4144-82AC-7E1E6001F860")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IImageService
{
	[DispId(1)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	string CurrentModuleID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	ISystem System
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: ComAliasName("ECMSERVICESAPILib.CreateImageResultsEnum")]
	CreateImageResultsEnum CreateImage([In][MarshalAs(UnmanagedType.BStr)] string bstrImageFilename, [In][MarshalAs(UnmanagedType.BStr)] string bstrPCID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	[return: ComAliasName("ECMSERVICESAPILib.CreateImageResultsEnum")]
	CreateImageResultsEnum CreateCSVImage([In][MarshalAs(UnmanagedType.BStr)] string bstrWorkOrderHeader, [In][MarshalAs(UnmanagedType.BStr)] string ImageInfoHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrCSVImageFilename, [In][MarshalAs(UnmanagedType.BStr)] string bstrDelimiter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void CreateTemplate([In][MarshalAs(UnmanagedType.BStr)] string bstrImageFilename, [In][MarshalAs(UnmanagedType.BStr)] string bstrTemplateFilename);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	[return: ComAliasName("ECMSERVICESAPILib.TemplateTransferResultsEnum")]
	TemplateTransferResultsEnum TransferTemplateToModule([In][MarshalAs(UnmanagedType.BStr)] string bstrTemplateFilename, [In] tagPasswordsStruct OEMPasswords, [MarshalAs(UnmanagedType.Interface)] out BSTRCollection punwrittenParameters);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	[return: ComAliasName("ECMSERVICESAPILib.CreateImageResultsEnum")]
	CreateImageResultsEnum ExportImageToCSV([In][MarshalAs(UnmanagedType.BStr)] string bstrSelectedFeaturesXML, [In][MarshalAs(UnmanagedType.BStr)] string bstrWorkOrderHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrImageInfoHeader, [In][MarshalAs(UnmanagedType.BStr)] string bstrImageFilePath, [In][MarshalAs(UnmanagedType.BStr)] string bstrCSVFilePath, [In][MarshalAs(UnmanagedType.BStr)] string bstrDelimiter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void CancelImageCreation();
}
[ComImport]
[Guid("F20EF986-9332-43CD-817A-ADB6F0E7C9E3")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IOfflineImageDataReader
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode BuildOfflineImage([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pRawImage);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode BuildOfflineImageExt([In][MarshalAs(UnmanagedType.BStr)] string selectedFeatures, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pRawImage);
}
public enum CreateImageResultsEnum
{
	CI_Success,
	CI_NoDiskSpace,
	CI_ModuleDevMode,
	CI_UnknownFailure,
	CI_Cancel,
	CI_Interrupted
}
public enum TemplateTransferResultsEnum
{
	TT_Success,
	TT_CantWriteTemplate,
	TT_ModuleDevMode,
	TT_TemplateLoadFailure,
	TT_UnknownFailure,
	TT_EngineSpeed
}
[StructLayout(LayoutKind.Sequential, Pack = 2)]
public struct tagPasswordsStruct
{
	public short bIsOEMAccessible;

	public short bIsOEM2Accessible;
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0018
{
	CI_Success,
	CI_NoDiskSpace,
	CI_ModuleDevMode,
	CI_UnknownFailure,
	CI_Cancel,
	CI_Interrupted
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0019
{
	TT_Success,
	TT_CantWriteTemplate,
	TT_ModuleDevMode,
	TT_TemplateLoadFailure,
	TT_UnknownFailure,
	TT_EngineSpeed
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("2933BF80-7B36-11D2-B20E-00C04F983E60")]
[ComConversionLoss]
public interface IXMLDOMNode
{
	[DispId(2)]
	string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
	DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
		get;
	}

	[DispId(6)]
	IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	bool hasChildNodes();

	[DispId(18)]
	IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);
}
public enum DOMNodeType
{
	NODE_INVALID,
	NODE_ELEMENT,
	NODE_ATTRIBUTE,
	NODE_TEXT,
	NODE_CDATA_SECTION,
	NODE_ENTITY_REFERENCE,
	NODE_ENTITY,
	NODE_PROCESSING_INSTRUCTION,
	NODE_COMMENT,
	NODE_DOCUMENT,
	NODE_DOCUMENT_TYPE,
	NODE_DOCUMENT_FRAGMENT,
	NODE_NOTATION
}
[ComImport]
[Guid("2933BF82-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
public interface IXMLDOMNodeList : IEnumerable
{
	[DispId(0)]
	IXMLDOMNode this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(74)]
	int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(74)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(76)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode nextNode();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(77)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(TypeLibFuncFlags.FRestricted | TypeLibFuncFlags.FHidden)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();
}
[ComImport]
[Guid("2933BF83-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
public interface IXMLDOMNamedNodeMap : IEnumerable
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(83)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode getNamedItem([In][MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(84)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode setNamedItem([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newItem);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(85)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode removeNamedItem([In][MarshalAs(UnmanagedType.BStr)] string Name);

	[DispId(0)]
	IXMLDOMNode this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(74)]
	int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(74)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(87)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode getQualifiedItem([In][MarshalAs(UnmanagedType.BStr)] string baseName, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(88)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode removeQualifiedItem([In][MarshalAs(UnmanagedType.BStr)] string baseName, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(89)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode nextNode();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(90)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(TypeLibFuncFlags.FRestricted | TypeLibFuncFlags.FHidden)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();
}
[ComImport]
[Guid("2933BF81-7B36-11D2-B20E-00C04F983E60")]
[ComConversionLoss]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
public interface IXMLDOMDocument : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(38)]
	IntPtr doctype
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		get;
	}

	[DispId(39)]
	IntPtr implementation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		get;
	}

	[DispId(40)]
	IntPtr documentElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMElement createElement([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	IntPtr createDocumentFragment();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	IntPtr createTextNode([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	IntPtr createComment([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	IntPtr createCDATASection([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	IntPtr createProcessingInstruction([In][MarshalAs(UnmanagedType.BStr)] string target, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	IntPtr createAttribute([In][MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	IntPtr createEntityReference([In][MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNodeList getElementsByTagName([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(54)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode createNode([In][MarshalAs(UnmanagedType.Struct)] object type, [In][MarshalAs(UnmanagedType.BStr)] string Name, [In][MarshalAs(UnmanagedType.BStr)] string namespaceURI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(56)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNode nodeFromID([In][MarshalAs(UnmanagedType.BStr)] string idString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(58)]
	bool load([In][MarshalAs(UnmanagedType.Struct)] object xmlSource);

	[DispId(-525)]
	int readyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-525)]
		get;
	}

	[DispId(59)]
	IntPtr parseError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		get;
	}

	[DispId(60)]
	string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(61)]
	bool async
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(62)]
	void abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(63)]
	bool loadXML([In][MarshalAs(UnmanagedType.BStr)] string bstrXML);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(64)]
	void save([In][MarshalAs(UnmanagedType.Struct)] object desination);

	[DispId(65)]
	bool validateOnParse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		[param: In]
		set;
	}

	[DispId(66)]
	bool resolveExternals
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		[param: In]
		set;
	}

	[DispId(67)]
	bool preserveWhiteSpace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(67)]
		[param: In]
		set;
	}

	[DispId(68)]
	object onreadystatechange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(69)]
	object ondataavailable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(70)]
	object ontransformnode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}
}
public enum tagDOMNodeType
{
	NODE_INVALID,
	NODE_ELEMENT,
	NODE_ATTRIBUTE,
	NODE_TEXT,
	NODE_CDATA_SECTION,
	NODE_ENTITY_REFERENCE,
	NODE_ENTITY,
	NODE_PROCESSING_INSTRUCTION,
	NODE_COMMENT,
	NODE_DOCUMENT,
	NODE_DOCUMENT_TYPE,
	NODE_DOCUMENT_FRAGMENT,
	NODE_NOTATION
}
[ComImport]
[Guid("2933BF8B-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
public interface IXMLDOMDocumentType : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(131)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(131)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(132)]
	IXMLDOMNamedNodeMap entities
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(132)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(133)]
	IXMLDOMNamedNodeMap notations
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(133)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[Guid("2933BF8F-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
public interface IXMLDOMImplementation
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(145)]
	bool hasFeature([In][MarshalAs(UnmanagedType.BStr)] string feature, [In][MarshalAs(UnmanagedType.BStr)] string version);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("2933BF86-7B36-11D2-B20E-00C04F983E60")]
public interface IXMLDOMElement : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(97)]
	string tagName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(97)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(99)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object getAttribute([In][MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(100)]
	void setAttribute([In][MarshalAs(UnmanagedType.BStr)] string Name, [In][MarshalAs(UnmanagedType.Struct)] object value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(101)]
	void removeAttribute([In][MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(102)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMAttribute getAttributeNode([In][MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(103)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMAttribute setAttributeNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMAttribute DOMAttribute);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(104)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMAttribute removeAttributeNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMAttribute DOMAttribute);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(105)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMNodeList getElementsByTagName([In][MarshalAs(UnmanagedType.BStr)] string tagName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(106)]
	void normalize();
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("3EFAA413-272F-11D2-836F-0000F87A7782")]
public interface IXMLDOMDocumentFragment : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("2933BF84-7B36-11D2-B20E-00C04F983E60")]
public interface IXMLDOMCharacterData : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(109)]
	string data
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(110)]
	int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(110)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(111)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string substringData([In] int offset, [In] int Count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(112)]
	void appendData([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(113)]
	void insertData([In] int offset, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(114)]
	void deleteData([In] int offset, [In] int Count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(115)]
	void replaceData([In] int offset, [In] int Count, [In][MarshalAs(UnmanagedType.BStr)] string data);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("2933BF87-7B36-11D2-B20E-00C04F983E60")]
public interface IXMLDOMText : IXMLDOMCharacterData
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(109)]
	new string data
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(110)]
	new int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(110)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(111)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string substringData([In] int offset, [In] int Count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(112)]
	new void appendData([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(113)]
	new void insertData([In] int offset, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(114)]
	new void deleteData([In] int offset, [In] int Count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(115)]
	new void replaceData([In] int offset, [In] int Count, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(123)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IXMLDOMText splitText([In] int offset);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("2933BF88-7B36-11D2-B20E-00C04F983E60")]
public interface IXMLDOMComment : IXMLDOMCharacterData
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(109)]
	new string data
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(110)]
	new int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(110)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(111)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string substringData([In] int offset, [In] int Count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(112)]
	new void appendData([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(113)]
	new void insertData([In] int offset, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(114)]
	new void deleteData([In] int offset, [In] int Count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(115)]
	new void replaceData([In] int offset, [In] int Count, [In][MarshalAs(UnmanagedType.BStr)] string data);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("2933BF8A-7B36-11D2-B20E-00C04F983E60")]
public interface IXMLDOMCDATASection : IXMLDOMText
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(109)]
	new string data
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(110)]
	new int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(110)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(111)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string substringData([In] int offset, [In] int Count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(112)]
	new void appendData([In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(113)]
	new void insertData([In] int offset, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(114)]
	new void deleteData([In] int offset, [In] int Count);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(115)]
	new void replaceData([In] int offset, [In] int Count, [In][MarshalAs(UnmanagedType.BStr)] string data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(123)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMText splitText([In] int offset);
}
[ComImport]
[Guid("2933BF89-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
public interface IXMLDOMProcessingInstruction : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(127)]
	string target
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(127)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(128)]
	string data
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(128)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(128)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}
}
[ComImport]
[Guid("2933BF85-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
public interface IXMLDOMAttribute : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
	[DispId(4)]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);

	[DispId(118)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(118)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(120)]
	object value
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(120)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(120)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}
}
[ComImport]
[Guid("2933BF8E-7B36-11D2-B20E-00C04F983E60")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
public interface IXMLDOMEntityReference : IXMLDOMNode
{
	[DispId(2)]
	new string nodeName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	new object nodeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(4)]
	[ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
	new DOMNodeType nodeType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("ECMSERVICESAPILib.DOMNodeType")]
		get;
	}

	[DispId(6)]
	new IXMLDOMNode parentNode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	new IntPtr childNodes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[DispId(8)]
	new IXMLDOMNode firstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	new IXMLDOMNode lastChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(10)]
	new IXMLDOMNode previousSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new IXMLDOMNode nextSibling
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(12)]
	new IntPtr attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode insertBefore([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Struct)] object refChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode replaceChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode oldChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode removeChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode childNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode appendChild([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode newChild);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	new bool hasChildNodes();

	[DispId(18)]
	new IntPtr ownerDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode cloneNode([In] bool deep);

	[DispId(21)]
	new string nodeTypeString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	new string text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(22)]
	new bool specified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	new IXMLDOMNode definition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(25)]
	new object nodeTypedValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(26)]
	new object dataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(27)]
	new string xml
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string transformNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNodeList selectNodes([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new IXMLDOMNode selectSingleNode([In][MarshalAs(UnmanagedType.BStr)] string queryString);

	[DispId(31)]
	new bool parsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new string namespaceURI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(33)]
	new string prefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(34)]
	new string baseName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	new void transformNodeToObject([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode stylesheet, [In][MarshalAs(UnmanagedType.Struct)] object outputObject);
}
[ComImport]
[Guid("3EFAA426-272F-11D2-836F-0000F87A7782")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[DefaultMember("errorCode")]
public interface IXMLDOMParseError
{
	[DispId(0)]
	int errorCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		get;
	}

	[DispId(179)]
	string url
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(179)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(180)]
	string Reason
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(180)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(181)]
	string srcText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(181)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(182)]
	int line
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(182)]
		get;
	}

	[DispId(183)]
	int linepos
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(183)]
		get;
	}

	[DispId(184)]
	int filepos
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(184)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("C89BD0C7-A802-495F-A570-75E856458BFC")]
public interface IFeatureDefinition
{
	[DispId(1)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	BSTRCollection ParameterIDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(4)]
	int ModuleType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}
}
[ComImport]
[Guid("32777E94-19B1-4D0D-B1F6-453D83324CE5")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IGroup
{
	[DispId(1)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	IParameters Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(3)]
	int Status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("2945D625-11B0-4C48-95DD-CBFC57B05CE5")]
public interface IParameters
{
	[DispId(1)]
	IParameter Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("8DFED79D-1B57-44F0-ADFF-957695B59318")]
public interface IParameter
{
	[DispId(1)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	string DisplayValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(4)]
	object RawValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(5)]
	string unitId
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(6)]
	string UnitsFamilyID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(7)]
	string MaxDisplayValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(8)]
	string MinDisplayValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	int ReadStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		get;
	}

	[DispId(10)]
	int ParamReadStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		get;
	}

	[DispId(11)]
	int WriteStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("C4AF1B35-8101-41E4-958F-037962B021EA")]
public interface IListener
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("48B350EA-B0C3-4853-AA84-3FECAA5F32C2")]
public interface IListeners
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("993D8406-021E-46C9-91DE-9E75F30FB68C")]
public interface IListenerService
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FNonExtensible | TypeLibTypeFlags.FDispatchable)]
[Guid("726DC6CC-FBBD-43DD-99BF-680728F8575F")]
public interface IListenerServices
{
}
[ComImport]
[Guid("F610F5AF-A42A-45C3-8946-8D3063300B67")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IParametersCollection
{
	[DispId(1)]
	IParameters Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
[ComImport]
[Guid("710583BD-5C5C-4B12-853E-A932FEB4985E")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IOfflineTemplateDataReader
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string BuildOfflineTemplate([In][MarshalAs(UnmanagedType.BStr)] string bstrRawTemplateXML);
}
[ComImport]
[Guid("E04725E7-324B-4B72-8591-05D0C3E348C0")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IECMObjectFactory
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void BuildParameter([In][MarshalAs(UnmanagedType.BStr)] string sParamId, [In] int lModuleId, [In][MarshalAs(UnmanagedType.Struct)] ref object pvtValue, [MarshalAs(UnmanagedType.Interface)] out IParameter ppIParam, [In] int lRTCRefTime = -1);
}
public enum MonitorServicesConstants
{
	MS_InvalidIndex = -1
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0002
{
	MS_InvalidIndex = -1
}
public enum GroupTypesEnum
{
	GT_Feature = 1,
	GT_Usage,
	GT_Dynamic
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0003
{
	GT_Feature = 1,
	GT_Usage,
	GT_Dynamic
}
public enum DependencyTypesEnum
{
	DT_Write = 1,
	DT_Read
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0005
{
	DT_Write = 1,
	DT_Read
}
public enum ValueTypesEnum
{
	VT_None = 1,
	VT_Numeric,
	VT_Text,
	VT_Binary,
	VT_TimeStamp,
	VT_TimeSpan
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0012
{
	VT_None = 1,
	VT_Numeric,
	VT_Text,
	VT_Binary,
	VT_TimeStamp,
	VT_TimeSpan
}
public enum LogReaderEnum
{
	LR_LogReaderNative = 1
}
public enum __MIDL___MIDL_itf_ECMServicesAPI_0000_0000_0013
{
	LR_LogReaderNative = 1
}
[ComImport]
[Guid("8313A442-CAF7-448E-9BD1-C9DC8D0D619A")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ILogWriter
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void AddEntry([In][MarshalAs(UnmanagedType.BStr)] string moduleId, [In][MarshalAs(UnmanagedType.BStr)] string ParameterID, [In][MarshalAs(UnmanagedType.BStr)] string parameterValue, [In][MarshalAs(UnmanagedType.BStr)] string timeStamp, [In][MarshalAs(UnmanagedType.BStr)] string SourceAddress, [In][MarshalAs(UnmanagedType.Interface)] BSTRCollection pParamsAdded, [In][MarshalAs(UnmanagedType.Interface)] BSTRCollection pParamsRemoved, [In][MarshalAs(UnmanagedType.BStr)] string bstrMaxValue, [In][MarshalAs(UnmanagedType.BStr)] string bstrMinValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void SetHeaderItem([In][MarshalAs(UnmanagedType.BStr)] string itemName, [In][MarshalAs(UnmanagedType.BStr)] string itemValue);

	[DispId(3)]
	string DestinationName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void MoveLogToLocation([In][MarshalAs(UnmanagedType.BStr)] string newLocation);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void AppendSampleNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);

	[DispId(6)]
	string LogStopTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void AddEventMarker([In][MarshalAs(UnmanagedType.BStr)] string bstrTimestamp, [In][MarshalAs(UnmanagedType.BStr)] string bstrEventId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void AddEventMarkerDescription([In][MarshalAs(UnmanagedType.BStr)] string bstrEventId, [In][MarshalAs(UnmanagedType.BStr)] string bstrEventDescription);
}
public enum CONNECTION_TYPE
{
	MISSING,
	SERIAL,
	PARALLEL,
	SIMULATOR,
	NGT,
	RP1210A,
	USB,
	IMAGE
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("6E2F8901-5756-11D4-8DBF-0004AC90F2F9")]
public interface IECMDataService
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void ReadNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void ChangeNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void CommitNode([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("6E2F8902-5756-11D4-8DBF-0004AC90F2F9")]
public interface IECMDataGroup
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void CreateGroup([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void GetGroup([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void RemoveGroup([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("8567A1D1-FB80-11D4-8AA9-00062999E309")]
public interface _IECMServicesCallBack
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void ReadStart();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void ReadStop();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void WriteStart();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void WriteStop();
}
[ComImport]
[Guid("9608904E-5754-11D4-8DBF-0004AC90F2F9")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IECMCommService
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void Connect([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void Disconnect();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void ECM_Lock([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void ECM_Unlock([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string SendTemplate2ECM([In][MarshalAs(UnmanagedType.BStr)] string bstrTemplateName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void RegisterCallBack([In][MarshalAs(UnmanagedType.Interface)] _IECMServicesCallBack pCallback);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void UnRegisterCallBack();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void ConnectedDLInfo([In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode, [MarshalAs(UnmanagedType.BStr)] out string pbstrFirmwareID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	void ValidateUnitSystem([In][MarshalAs(UnmanagedType.BStr)] string bstrTemplateName, out bool HasChanged, [MarshalAs(UnmanagedType.BStr)] out string Units);

	[DispId(11)]
	bool IsImage
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		get;
	}
}
[ComImport]
[Guid("96089050-5754-11D4-8DBF-0004AC90F2F9")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IECMDBService
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void MakeImage([In][MarshalAs(UnmanagedType.Interface)] IECMDataService pDataService, [In][MarshalAs(UnmanagedType.Interface)] IXMLDOMNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void Open([In][MarshalAs(UnmanagedType.Struct)] object vImage);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void Close();
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("96089051-5754-11D4-8DBF-0004AC90F2F9")]
public interface IECMSimulatorService
{
}
[ComImport]
[Guid("62966EE3-640F-11D4-8DBF-0004AC90F2F9")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IECMServicesList : IEnumerable
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void Reset();

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[DispId(3)]
	IECMDataService Next
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(0)]
	IECMDataService this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("62E2F7C2-6D5C-11D4-8A5F-00062999E309")]
public interface IECMServicesManagement
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IECMDataService CreateECMDataService(ref Guid rguidDataService, [In] ref int plDataServiceID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void DestroyECMDataService([In] int lDataServiceID);

	[DispId(3)]
	IECMServicesList ECMServicesList
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
