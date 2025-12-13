using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: ImportedFromTypeLib("ECMSERVICESEVENTSLib")]
[assembly: Guid("A7097780-6C52-11D7-AD87-0006294F9D62")]
[assembly: TypeLibVersion(1, 0)]
[assembly: AssemblyVersion("7.6.0.272")]
namespace ECMSERVICESEVENTSLib;

public enum TriggerStatusEnum
{
	TS_TriggersMetNone = 1,
	TS_TriggersMetAny,
	TS_TriggersMetAll
}
public enum __MIDL___MIDL_itf_ECMServicesEvents_0000_0000_0001
{
	TS_TriggersMetNone = 1,
	TS_TriggersMetAny,
	TS_TriggersMetAll
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
[Guid("580A2C3D-802E-40A6-8C5D-3BD95ADC9BF6")]
public interface ILoggerEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void OnLoggingStarted([In] int monitorID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void OnLoggingStopped([In] int monitorID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void OnLoggerError([In] int monitorID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void OnLoggerLowDiskSpace([In] int logID);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
[Guid("F73DBC48-E6B4-44A2-B7C1-2047B0403727")]
public interface ILogEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void OnActivate([In] int logID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void OnDeactivate([In] int logID);
}
[ComImport]
[Guid("CEF2DD96-0157-4E10-A493-DAE6E2C6E53A")]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
public interface IMonitorServiceEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void OnMonitorAdded([In] int monitorID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void OnMonitorRemoved([In] int monitorID);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
[Guid("DD9F8B57-6CC2-421E-A507-06FB388FB059")]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
public interface IMonitorEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void OnMonitorStarted([In] int monitorID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void OnMonitorStopped([In] int monitorID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void OnMonitorDataChanged([In] int monitorID, [In] int moduleID, [In][MarshalAs(UnmanagedType.BStr)] string parameterID, [In][MarshalAs(UnmanagedType.BStr)] string parameterDisplayValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void OnMonitorError([In] int monitorID);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
[Guid("C2593369-FB36-48E2-BFD9-5543D6CC628D")]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
public interface IMonitorDataChangedEvent
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void OnMonitorDataChanged([In] int monitorID, [In] int moduleID, [In][MarshalAs(UnmanagedType.BStr)] string parameterID, [In][MarshalAs(UnmanagedType.BStr)] string parameterDisplayValue);
}
[ComImport]
[Guid("BB7A826A-9817-40D3-A7A9-5561D9B05B67")]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
public interface ITriggerEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void OnTriggerMet([In] int triggerID, [In][ComAliasName("ECMSERVICESEVENTSLib.TriggerStatusEnum")] TriggerStatusEnum triggerStatus);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void OnTriggerError([In] int triggerID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void OnTriggerEnableChanged([In] int triggerID, [In] int isActive);
}
public enum GroupDefinitionEventsEnum
{
	Parameter_Added = 1,
	Parameter_Removed
}
public enum __MIDL___MIDL_itf_ECMServicesEvents_0001_0069_0001
{
	Parameter_Added = 1,
	Parameter_Removed
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("6AD03CED-A335-4856-80E1-A8786F9E6D38")]
public interface IGroupDefinitionEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void ParameterAdded([In][MarshalAs(UnmanagedType.BStr)] string groupDefinitionId, [In][MarshalAs(UnmanagedType.BStr)] string parameterID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void ParameterRemoved([In][MarshalAs(UnmanagedType.BStr)] string groupDefinitionId, [In][MarshalAs(UnmanagedType.BStr)] string parameterID);
}
public enum ImageServiceEventsEnum
{
	Update_Message = 1,
	Update_Percent
}
public enum __MIDL___MIDL_itf_ECMServicesEvents_0001_0070_0001
{
	Update_Message = 1,
	Update_Percent
}
[ComImport]
[Guid("276B1479-4BE4-4187-86BB-B5ABCC4C22C0")]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
public interface IImageServiceEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void UpdateMessage([In][MarshalAs(UnmanagedType.BStr)] string message);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void UpdatePercent([In] int percentComplete);
}
