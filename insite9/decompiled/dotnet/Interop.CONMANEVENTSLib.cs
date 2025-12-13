using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: ImportedFromTypeLib("CONMANEVENTSLib")]
[assembly: Guid("92603A20-A46C-40A3-B3D8-261A76923399")]
[assembly: TypeLibVersion(1, 0)]
[assembly: AssemblyVersion("7.6.0.272")]
namespace CONMANEVENTSLib;

public enum ConnectionStatusEnum
{
	ConnectionSuccessful = 1,
	ECMRomBooted,
	ECMSeeded,
	ECMFootprinted,
	CommunicationRestored
}
public enum __MIDL___MIDL_itf_ConManEvents_0000_0000_0001
{
	ConnectionSuccessful = 1,
	ECMRomBooted,
	ECMSeeded,
	ECMFootprinted,
	CommunicationRestored
}
public enum DisconnectReasonsEnum
{
	UserDisconnected = 1,
	LostCommunication
}
public enum __MIDL___MIDL_itf_ConManEvents_0000_0000_0002
{
	UserDisconnected = 1,
	LostCommunication
}
public enum ConnectionEventsEnum
{
	Connection_Established = 1,
	Connection_Terminated
}
public enum __MIDL___MIDL_itf_ConManEvents_0000_0000_0003
{
	Connection_Established = 1,
	Connection_Terminated
}
public enum ConnectionLostEventsEnum
{
	Connection_Interrupted = 1,
	Connection_Restored
}
public enum __MIDL___MIDL_itf_ConManEvents_0000_0000_0004
{
	Connection_Interrupted = 1,
	Connection_Restored
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("4DDED4FD-B9AF-4D6E-8071-BA9192AC252C")]
public interface IConManEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void ConManConnectEvent([In][MarshalAs(UnmanagedType.IUnknown)] object pDataService, [In][MarshalAs(UnmanagedType.Struct)] object vConnData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void ConManDisconnectEvent([In][MarshalAs(UnmanagedType.Struct)] object vConnData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void ConManPartialCommEvent([In][MarshalAs(UnmanagedType.IUnknown)] object pCommService, [In][MarshalAs(UnmanagedType.Struct)] object vConnData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void ConManRefreshDataEvent([In][MarshalAs(UnmanagedType.Struct)] object vConnData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void ConManConnectFailedEvent();
}
[ComImport]
[Guid("8E5C6E59-E230-41D2-AF46-9936250C796B")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IConnectionEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void ConnectionEstablished([In][MarshalAs(UnmanagedType.BStr)] string connectionId, [In][ComAliasName("CONMANEVENTSLib.ConnectionStatusEnum")] ConnectionStatusEnum status);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void ConnectionTerminated([In][MarshalAs(UnmanagedType.BStr)] string connectionId);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("AF1FBD55-1C0C-4C25-B426-ECFF245CB956")]
public interface IConnectionLostEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void ConnectionInterrupted();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void ConnectionRestored();
}
[ComImport]
[Guid("C878DEBC-E3C0-4E23-8A80-56E4BA9FB918")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface _IConManEventForFnP
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void ConManRefreshEventForFnP();
}
