using System;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using stdole;

[assembly: ImportedFromTypeLib("APPLICATIONAPILib")]
[assembly: Guid("4B7213E0-3F2A-4FF1-87EE-B6E03FD14FDE")]
[assembly: TypeLibVersion(1, 0)]
[assembly: AssemblyVersion("7.6.0.272")]
namespace APPLICATIONAPILib;

[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[Guid("865BBA81-27CB-4E98-BAD6-7B3AC639C87F")]
public interface IMenuBarEntry
{
	[DispId(1610678272)]
	string ParentID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610678273)]
	string MenuItemID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610678274)]
	int Position
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678275)]
	int EnableFlags
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678276)]
	string Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610678277)]
	object Bitmap
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	[DispId(1610678278)]
	int Style
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678279)]
	bool HasHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678280)]
	bool HandlerRegistered
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678281)]
	int HandlerID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[DispId(1610678283)]
	bool ShouldEnable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678284)]
	bool ShouldDisplay
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("BAE07E81-25E0-46DA-83F5-290B4984DD9B")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IMenuBarClient
{
	[DispId(1610678272)]
	IMenuBarEntry Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610678273)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}
}
[ComImport]
[Guid("14AFC46A-31CC-4684-89BF-CD11370A91D1")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IViewSelectorClient
{
	[DispId(1610678272)]
	int LargeBitmapID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678273)]
	int SmallBitmapID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678274)]
	string ToolTip
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610678275)]
	string ButtonText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610678276)]
	int ButtonIndex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678277)]
	string GroupID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610678278)]
	int DefaultWindowType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678279)]
	string WindowID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610678281)]
	IStream LargeBitmapStream
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610678282)]
	IStream SmallBitmapStream
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610678283)]
	bool ShouldAdd
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	bool IsNotifyAddIn();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void NotifyAddIn();
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("0C733A30-2A1C-11CE-ADE5-00AA0044773D")]
public interface ISequentialStream
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteRead(out byte pv, [In] uint cb, out uint pcbRead);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteWrite([In] ref byte pv, [In] uint cb, out uint pcbWritten);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("0000000C-0000-0000-C000-000000000046")]
public interface IStream : ISequentialStream
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void RemoteRead(out byte pv, [In] uint cb, out uint pcbRead);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void RemoteWrite([In] ref byte pv, [In] uint cb, out uint pcbWritten);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteSeek([In] _LARGE_INTEGER dlibMove, [In] uint dwOrigin, out _ULARGE_INTEGER plibNewPosition);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetSize([In] _ULARGE_INTEGER libNewSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteCopyTo([In][MarshalAs(UnmanagedType.Interface)] IStream pstm, [In] _ULARGE_INTEGER cb, out _ULARGE_INTEGER pcbRead, out _ULARGE_INTEGER pcbWritten);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Commit([In] uint grfCommitFlags);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Revert();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void LockRegion([In] _ULARGE_INTEGER libOffset, [In] _ULARGE_INTEGER cb, [In] uint dwLockType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void UnlockRegion([In] _ULARGE_INTEGER libOffset, [In] _ULARGE_INTEGER cb, [In] uint dwLockType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Stat(out tagSTATSTG pstatstg, [In] uint grfStatFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IStream ppstm);
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct _LARGE_INTEGER
{
	public long QuadPart;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct _ULARGE_INTEGER
{
	public ulong QuadPart;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct tagSTATSTG
{
	[MarshalAs(UnmanagedType.LPWStr)]
	public string pwcsName;

	public uint type;

	public _ULARGE_INTEGER cbSize;

	public _FILETIME mtime;

	public _FILETIME ctime;

	public _FILETIME atime;

	public uint grfMode;

	public uint grfLocksSupported;

	public Guid clsid;

	public uint grfStateBits;

	public uint reserved;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct _FILETIME
{
	public uint dwLowDateTime;

	public uint dwHighDateTime;
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("8CD655FE-245D-4ED9-853C-D42CF7CBA644")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface ISystemManager
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetSystemObject([In][MarshalAs(UnmanagedType.IUnknown)] object SystemObject);
}
[ComImport]
[Guid("C11583D1-2365-11D4-BDCB-0004AC966830")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IViewSelector
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1280)]
	int AddSelector([In] int lAddinResourceHandle, [In] int lLargeBitmapID, [In] int lSmallBitmapID, [In][MarshalAs(UnmanagedType.BStr)] string bstrToolTip, [In][MarshalAs(UnmanagedType.BStr)] string bstrButtonText, [In] int lButtonIndex, [In][MarshalAs(UnmanagedType.BStr)] string bstrGroupName, [In][MarshalAs(UnmanagedType.IUnknown)] object pIUnkAddin, [In] int lWindowType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1281)]
	void RemoveSelector([In] int lSelectorID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1282)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	object GetAddInInterfaceForWindow([In] int lWindowHandle);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1283)]
	int GetAddInWindowHandle([In][MarshalAs(UnmanagedType.IUnknown)] object pUnk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1284)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetViewSelectorWindowID();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1285)]
	void OpenAddInWindow([In] int lSelectorID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1286)]
	void ForceOpenAddInWindow([In] int lSelectorID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1287)]
	void SetShell([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkShell);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1288)]
	void SetKernel([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkKernel);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("C3BE8DB1-4E2E-4B7B-A357-AB0E74556F10")]
public interface IViewSelector2
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int AddSelector2([In][MarshalAs(UnmanagedType.Interface)] IStream LargeIcon, [In][MarshalAs(UnmanagedType.Interface)] IStream SmallIcon, [In][MarshalAs(UnmanagedType.BStr)] string bstrToolTip, [In][MarshalAs(UnmanagedType.BStr)] string bstrButtonText, [In] int lButtonIndex, [In][MarshalAs(UnmanagedType.BStr)] string bstrGroupName, [In][MarshalAs(UnmanagedType.IUnknown)] object pIUnkAddin, [In] int lWindowType, [In][MarshalAs(UnmanagedType.IUnknown)] object pAddIn, [In][MarshalAs(UnmanagedType.BStr)] string bstrViewType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetWindowIDOfViewbarButton([In] int SelectorID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int RefreshSelector([In][MarshalAs(UnmanagedType.Interface)] IStream LargeIcon, [In][MarshalAs(UnmanagedType.Interface)] IStream SmallIcon, [In][MarshalAs(UnmanagedType.BStr)] string bstrToolTip, [In][MarshalAs(UnmanagedType.BStr)] string bstrButtonText, [In] int lButtonIndex, [In][MarshalAs(UnmanagedType.BStr)] string bstrGroupName, [In][MarshalAs(UnmanagedType.IUnknown)] object pIUnkAddin, [In] int lWindowType, [In][MarshalAs(UnmanagedType.BStr)] string bstrWindowID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int GetViewSelectorHwnd();
}
[ComImport]
[Guid("390DDBA8-0BFF-4C13-BA99-424453C41879")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IStatusBar
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void AddControl([In] int lControlHwnd, [In] int lPosition, out int lControlID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void GetStatusBarHwnd(out int plHwnd);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void GetControlHandle([In] int lControlID, out int lHwndCtrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void UpdateStatusBar();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void AddTrayItem([In] int lTrayItemHwnd, out int plTrayItemID);
}
[ComImport]
[Guid("CBF1CD38-4FCF-4224-A138-843A8C4ECEFD")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IToolBarButtonEntry
{
	[DispId(1610678272)]
	string ButtonID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610678273)]
	string ToolTip
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610678274)]
	int Position
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678275)]
	int EnableFlags
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678276)]
	IStream LargeBitmapStream
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610678277)]
	IStream SmallBitmapStream
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610678278)]
	int Style
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678279)]
	bool HasHandler
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678280)]
	bool HandlerRegistered
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678281)]
	int HandlerID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[DispId(1610678283)]
	bool ShouldEnable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("1E6D55F6-B5EF-4EF3-9699-D9A9EF670F6A")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IToolBarEventCallback
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ToolBarButtonClicked([In][MarshalAs(UnmanagedType.BStr)] string ToolBarButtonID);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[Guid("3D60EDD5-252B-41A8-9CA6-875E5684A336")]
public interface IToolBarClient
{
	[DispId(1610678272)]
	IToolBarButtonEntry Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610678273)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("C11583CF-2365-11D4-BDCB-0004AC966830")]
public interface IToolBar
{
	[DispId(1)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	object Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(3)]
	object _NewEnum
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	[DispId(4)]
	string ToolBarID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string AddButton([In] int lAddinResourceHandle, [In] int lPos, [In][MarshalAs(UnmanagedType.BStr)] string ButtonID, [In] int lLargeBitmapID, [In] int lSmallBitmapID, [In] int lToolTipID, [In] int lStyle, [In] bool vbAlwaysEnable);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void RemoveButton([In][MarshalAs(UnmanagedType.BStr)] string bstrButtonID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetButtonEventByID([In][MarshalAs(UnmanagedType.BStr)] string bstrButtonID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void init([In] int lGITCookie);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	int GetResourceID([In][MarshalAs(UnmanagedType.BStr)] string bstrItemID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	int GetToolBarHwnd();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	void SetButtonImage([In][MarshalAs(UnmanagedType.BStr)] string bstrID, [In] int lAddinResourceHandle, [In] int lLargeBitmapID, [In] int lSmallBitmapID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	void CheckButton([In][MarshalAs(UnmanagedType.BStr)] string bstrID, [In] bool vbChecked);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	void RegisterCallback([In][MarshalAs(UnmanagedType.BStr)] string ToolBarButtonID, [In][MarshalAs(UnmanagedType.Interface)] IToolBarEventCallback EventCallback, out int CallbackID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	void UnregisterCallback([In] int CallbackID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	void RefreshToolBarButtonStates();
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("8B52351A-76D2-41FA-974E-AF60A6562110")]
public interface IToolBars
{
	[DispId(1)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	IToolBar Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IToolBar Add([In][MarshalAs(UnmanagedType.BStr)] string ToolBarID);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[Guid("580949A4-05F9-4728-B495-1237B7458A09")]
public interface IToolBar2
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Add([In] int Position, [In][MarshalAs(UnmanagedType.BStr)] string ButtonID, [In][MarshalAs(UnmanagedType.Interface)] IStream LargeBitmapStream, [In][MarshalAs(UnmanagedType.Interface)] IStream SmallBitmapStream, [In][MarshalAs(UnmanagedType.BStr)] string ToolTip, [In] int Style, [In] bool vbAlwaysEnable);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	bool IsButtonEnabled([In][MarshalAs(UnmanagedType.BStr)] string ButtonID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnableSmallButtonSet([In] bool EnableSmallButtonSet);

	[DispId(1610678275)]
	bool SmallButtonSetEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("14345C9D-7E43-4737-BE9D-6A9B8D0557A7")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IMenuEventCallback
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void MenuItemClicked([In][MarshalAs(UnmanagedType.BStr)] string MenuItemID);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[Guid("FD96D225-5CD4-4F59-B27E-FED0A139AD3B")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IMenuItem
{
	[DispId(1610678272)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610678273)]
	string Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610678275)]
	string Accel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610678277)]
	bool IsSubMenu
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678278)]
	IMenuItems SubMenuItems
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610678279)]
	string XML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CreateFromXML([In][MarshalAs(UnmanagedType.BStr)] string XML);

	[DispId(1610678281)]
	bool IsCheckmarked
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Checkmark([In] bool AddCheck);

	[DispId(1610678283)]
	bool IsEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("0BB7970C-288C-4BFA-B3E5-65E34977DB6D")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IMenuItems
{
	[DispId(1610678272)]
	IMenuItem Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610678273)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IMenuItem Add([In][MarshalAs(UnmanagedType.BStr)] string MenuItemID, [In] bool IsSubMenu);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Remove([In][MarshalAs(UnmanagedType.BStr)] string MenuItemID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IMenuItem Insert([In][MarshalAs(UnmanagedType.BStr)] string MenuItemID, [In][MarshalAs(UnmanagedType.BStr)] string InsertBeforeID, [In] bool IsSubMenu);

	[DispId(1610678277)]
	string XML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CreateFromXML([In][MarshalAs(UnmanagedType.BStr)] string XML);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[Guid("E95B6EA6-AB08-4D22-83FD-619C5B720CFD")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IMenuBar
{
	[DispId(1610678272)]
	IMenuItem Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610678273)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IMenuItem Add([In][MarshalAs(UnmanagedType.BStr)] string MenuItemsID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Remove([In][MarshalAs(UnmanagedType.BStr)] string MenuItemID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IMenuItem Insert([In][MarshalAs(UnmanagedType.BStr)] string MenuItemID, [In][MarshalAs(UnmanagedType.BStr)] string InsertBeforeID, [In] bool IsSubMenu);

	[DispId(1610678277)]
	string XML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CreateFromXML([In][MarshalAs(UnmanagedType.BStr)] string XML);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RegisterCallback([In][MarshalAs(UnmanagedType.BStr)] string MenuItemID, [In][MarshalAs(UnmanagedType.Interface)] IMenuEventCallback EventCallback, out int CallbackID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void UnregisterCallback([In] int CallbackID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RefreshMenuItemStates();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnableMenuBar([In] bool bEnable);
}
[ComImport]
[Guid("17689A06-E0F4-49D0-9FAF-778536F4B78A")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICommandRouter
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void AddCommand([In] uint nCommandID, [In][MarshalAs(UnmanagedType.BStr)] string bstrButtonID, [In][MarshalAs(UnmanagedType.BStr)] string bstrEventID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void RemoveCommand([In] uint nID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void GetEventForCommand([In] uint nCommandID, [MarshalAs(UnmanagedType.BStr)] out string pbstrEventID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void GetButtonForCommand([In] uint nCommandID, [MarshalAs(UnmanagedType.BStr)] out string pbstrID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void init([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkKernel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	int GetNewResourceID();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	int GetHighestResourceID();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void GetEnableStatus([In] int lID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void SetEnableStatus([In] int lID, [In] bool vbEnable);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	void AlwaysEnable([In] int lID, [In] bool vbEnable);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	void AddAccelerator([In] int lID, [In] byte fVirtKey, [In] bool vbShift, [In] bool vbAlt, [In] bool vbCtrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	int FindAccelerator([In] byte fVirtKey, [In] bool vbShift, [In] bool vbAlt, [In] bool vbCtrl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	void GetCommandForEvent([In][MarshalAs(UnmanagedType.BStr)] string bstrEvent, out uint pnCommandID);
}
[ComImport]
[Guid("4BE9A760-6CD3-40F6-8281-FBD372164235")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IAppWindow
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
	object Owner
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	[DispId(3)]
	string FrameType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(4)]
	string ViewType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(5)]
	bool IsVisible
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
	}

	[DispId(6)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void Show([In] bool MakeVisible);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void Open();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void Close();

	[DispId(10)]
	bool IsOpen
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		get;
	}

	[DispId(11)]
	object ViewObject
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(12)]
	IPicture WindowIcon
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	void ChangeFrameType([In][MarshalAs(UnmanagedType.BStr)] string NewFrameType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	void Activate();
}
[ComImport]
[Guid("1CF32EC4-0768-4D3C-ADC4-9BFC12BFAC6F")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IAppWindowManager
{
	[DispId(1610678272)]
	IAppWindow Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610678273)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678274)]
	string ActiveWindowID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IAppWindow Add([In][MarshalAs(UnmanagedType.IUnknown)] object Owner, [In][MarshalAs(UnmanagedType.BStr)] string ViewType, [In][MarshalAs(UnmanagedType.BStr)] string FrameType, [In][MarshalAs(UnmanagedType.Struct)] object ViewObj, [In][MarshalAs(UnmanagedType.IUnknown)] object addIn);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Remove([In][MarshalAs(UnmanagedType.BStr)] string WindowID);

	[ComAliasName("APPLICATIONAPILib.wireHWND")]
	[DispId(1610678277)]
	_RemotableHandle ActiveHWND
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("APPLICATIONAPILib.wireHWND")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("APPLICATIONAPILib.wireHWND")]
		set;
	}
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct _RemotableHandle
{
	public int fContext;

	public __MIDL_IWinTypes_0009 u;
}
[StructLayout(LayoutKind.Explicit, Pack = 4, Size = 4)]
public struct __MIDL_IWinTypes_0009
{
	[FieldOffset(0)]
	public int hInproc;

	[FieldOffset(0)]
	public int hRemote;
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("C7FC1A5E-D802-4785-A40D-9D69CE8D0EF6")]
public interface IAppWindowCallback
{
	[DispId(1610678272)]
	bool CanClose
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("8A79AC91-4CAB-4319-AADF-17966F554903")]
public interface IAppWindowEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void WindowAdded([In][MarshalAs(UnmanagedType.BStr)] string WindowID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void WindowOpened([In][MarshalAs(UnmanagedType.BStr)] string WindowID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void WindowChanged([In][MarshalAs(UnmanagedType.BStr)] string WindowID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void WindowClosed([In][MarshalAs(UnmanagedType.BStr)] string WindowID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void WindowRemoved([In][MarshalAs(UnmanagedType.BStr)] string WindowID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void WindowActivated([In][MarshalAs(UnmanagedType.BStr)] string WindowID, [In][MarshalAs(UnmanagedType.BStr)] string PreviousWindowID);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("A6A7C17C-25FD-11D4-BDCF-0004AC966830")]
public interface IShellServiceProvider
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IViewSelector GetViewSelector();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IMenuBar GetMenuBar();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICommandRouter GetCommandRouter();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IToolBar GetToolBar();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IStatusBar GetStatusBar();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	object GetInfoService();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	bool CanAppClose();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IAppWindowManager GetAppWindowManager();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	object GetUserManager();
}
[ComImport]
[Guid("37D79FBB-EEA6-4C1E-96BA-DB66CDC96496")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IViewMessageProcessor
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ProcessWndMessage([In] int msg);
}
[ComImport]
[ComConversionLoss]
[Guid("1D1D9EA1-3909-4F99-9A49-0A554F5BAA96")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IViewCreator
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IViewMessageProcessor CreateView([In] int lhwndParent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	IntPtr GetWindowICON();
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[Guid("3A92AFDE-2498-4238-8D38-9392B16A81B9")]
public interface IAddinInterfaceProvider
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	IntPtr GetInterface([In] Guid guid);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[Guid("A6A7C17E-25FD-11D4-BDCF-0004AC966830")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IApplication
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	object GetShell();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	object GetKernel();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsAddInActive([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkAddIn);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int GetMainWindow();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RefreshMainWindow();
}
