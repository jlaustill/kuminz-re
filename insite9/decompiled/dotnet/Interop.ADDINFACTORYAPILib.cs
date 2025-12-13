using System;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("E1E77047-EAC9-4916-B8D4-DC9509DBD14F")]
[assembly: ImportedFromTypeLib("ADDINFACTORYAPILib")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace ADDINFACTORYAPILib;

[ComImport]
[Guid("9231DA18-9DE9-4FF3-A1EC-752EB7CF7DF2")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IEnumAddIns
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Next([In] uint ulElementCount, out Guid pguidElements, out uint pulElementsFetchedCount);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip([In] uint ulElementCount);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumAddIns ppenum);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B1308F3B-7312-4659-B526-5B2964EDAB4F")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IAddInFactory
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void LoadActiveAddIns();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void UnloadActiveAddIns();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void LoadAddIn([In][MarshalAs(UnmanagedType.BStr)] string AddInID, [In] bool vbMakeActive);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void UnloadAddIn([In][MarshalAs(UnmanagedType.BStr)] string AddInID, [In] bool vbMakeInactive);

	[DispId(5)]
	IEnumAddIns LoadedAddInsEnum
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(6)]
	IEnumAddIns AllAddInsEnum
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(7)]
	object Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	[DispId(8)]
	object AddInProperty
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("2CAC35CA-9DA2-4861-B4BF-E0F8AD9047A9")]
public interface IAddIn
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Init(int GITCookie);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Load();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Unload();
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[Guid("57E5CCF4-FABF-4F03-89F5-FA4CEC406CCE")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IComponentLoadCallback
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ComponentLoad([In] int CallbackID, [In][MarshalAs(UnmanagedType.IUnknown)] object LoadedComponent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ComponentUnload([In] int CallbackID, [In][MarshalAs(UnmanagedType.IUnknown)] object UnloadedComponent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void StartingComponentLoads([In] int CallbackID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FinishedComponentLoads([In] int CallbackID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void StartingComponentUnloads([In] int CallbackID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FinishedComponentUnloads([In] int CallbackID);
}
[ComImport]
[Guid("CAE85B0F-04CA-4B43-9232-87B24BB767CE")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IComponentLoader
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RegisterComponentLoadCallback([In][MarshalAs(UnmanagedType.Interface)] IComponentLoadCallback ComponentLoadCallback, out int CallbackID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void UnregisterComponentUnloadCallback([In] int CallbackID);
}
