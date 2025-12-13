using System;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("C219E4F9-6276-46FB-8834-F4F3E549E029")]
[assembly: ImportedFromTypeLib("ContainerComponentsLib")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace ContainerComponentsLib;

[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("6E468B03-4F68-490B-8813-7CC3BF691F35")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IButtonBar
{
	[DispId(1)]
	string ButtonText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(2)]
	bool IsButtonVisible
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[DispId(3)]
	bool IsButtonEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[DispId(4)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();
}
[ComImport]
[CoClass(typeof(ButtonBarClass))]
[Guid("6E468B03-4F68-490B-8813-7CC3BF691F35")]
public interface ButtonBar : IButtonBar
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ClassInterface(ClassInterfaceType.None)]
[Guid("D09538E5-1D09-4B87-8E0F-E9E22445E387")]
public class ButtonBarClass : IButtonBar, ButtonBar
{
	[DispId(1)]
	public virtual extern string ButtonText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(2)]
	public virtual extern bool IsButtonVisible
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[DispId(3)]
	public virtual extern bool IsButtonEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[DispId(4)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void Reset();
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("281609FB-07A1-4358-AF78-04E71FD385DC")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IPropertyPageProxy
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Initialize([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkPropPage);

	[DispId(1610678273)]
	IPropertyPageSite pageSite
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPageInfo(out tagPROPPAGEINFO pPageInfo);
}
[ComImport]
[Guid("281609FB-07A1-4358-AF78-04E71FD385DC")]
[CoClass(typeof(PropertyPageProxyClass))]
public interface PropertyPageProxy : IPropertyPageProxy
{
}
[ComImport]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("B832A096-AB91-47DE-AC0A-7A634C9F404D")]
public class PropertyPageProxyClass : IPropertyPageProxy, PropertyPageProxy
{
	[DispId(1610678273)]
	public virtual extern IPropertyPageSite pageSite
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void Initialize([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkPropPage);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void GetPageInfo(out tagPROPPAGEINFO pPageInfo);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
[Guid("71919300-8BED-406B-99F4-E3F9BE8B583F")]
public interface IFeatureOutputAdapter
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void ApplyNewState([In][MarshalAs(UnmanagedType.Interface)] ISFContainerState pContainerState);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void ChangeInstruction([In][MarshalAs(UnmanagedType.BStr)] string newInstruct);
}
[ComImport]
[CoClass(typeof(FeatureOutputAdapterClass))]
[Guid("71919300-8BED-406B-99F4-E3F9BE8B583F")]
public interface FeatureOutputAdapter : IFeatureOutputAdapter
{
}
[ComImport]
[Guid("B0AE6AAB-941B-4E83-B72A-93FDBE90C1EE")]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class FeatureOutputAdapterClass : IFeatureOutputAdapter, FeatureOutputAdapter
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	public virtual extern void ApplyNewState([In][MarshalAs(UnmanagedType.Interface)] ISFContainerState pContainerState);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void ChangeInstruction([In][MarshalAs(UnmanagedType.BStr)] string newInstruct);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("27BF50B1-5D50-4C4B-9824-890C3234841F")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IFeatureInputAdapter
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RequestCommand([In][MarshalAs(UnmanagedType.BStr)] string CommandID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Abort();
}
[ComImport]
[Guid("27BF50B1-5D50-4C4B-9824-890C3234841F")]
[CoClass(typeof(FeatureInputAdapterClass))]
public interface FeatureInputAdapter : IFeatureInputAdapter
{
}
[ComImport]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("D246614F-5FF0-4B01-9BCA-21F2C871C5F1")]
public class FeatureInputAdapterClass : IFeatureInputAdapter, FeatureInputAdapter
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void RequestCommand([In][MarshalAs(UnmanagedType.BStr)] string CommandID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void Abort();
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("B196B28C-BAB4-101A-B69C-00AA00341D07")]
public interface IPropertyPageSite
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnStatusChange([In] uint dwFlags);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetLocaleID(out uint pLocaleID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPageContainer([MarshalAs(UnmanagedType.IUnknown)] out object ppUnk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void TranslateAccelerator([In] ref tagMSG pMsg);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct tagPROPPAGEINFO
{
	public uint cb;

	[MarshalAs(UnmanagedType.LPWStr)]
	public string pszTitle;

	public tagSIZE size;

	[MarshalAs(UnmanagedType.LPWStr)]
	public string pszDocString;

	[MarshalAs(UnmanagedType.LPWStr)]
	public string pszHelpFile;

	public uint dwHelpContext;
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[Guid("24A44574-42DE-43F3-8AF2-0B9400F8273E")]
public interface ISFContainerState
{
	[DispId(1)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	ISFButtons Buttons
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(3)]
	bool IsActive
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(4)]
	string Subtitle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("ContainerComponentsLib.CursorTypes")]
	[DispId(5)]
	CursorTypes CursorType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("ContainerComponentsLib.CursorTypes")]
		get;
	}

	[DispId(6)]
	string CurrentPageID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(7)]
	object CurrentPage
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	[DispId(8)]
	string title
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(9)]
	string InstructionsLabel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(10)]
	string ShowLabel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("6225811B-410F-40FB-A15A-13BD5FEBAB70")]
public interface ISFButton
{
	[DispId(1)]
	string ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	string Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	bool IsEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(4)]
	bool IsVisible
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(5)]
	string CommandID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("8791AB7B-96CA-4786-8B46-943E6B70127C")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface ISFButtons
{
	[DispId(1)]
	ISFButton Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}
}
public enum CursorTypes
{
	NORMAL,
	BUSY,
	WORKING
}
public enum __MIDL___MIDL_itf_ContainerComponents_0001_0065_0001
{
	NORMAL,
	BUSY,
	WORKING
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
[Guid("6E468B03-4F68-490B-8813-7CC3BF691F36")]
public interface IButtonBarClient
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void ButtonClicked([In][MarshalAs(UnmanagedType.BStr)] string buttonID);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct tagMSG
{
	[ComAliasName("ContainerComponentsLib.wireHWND")]
	public IntPtr hwnd;

	public uint message;

	[ComAliasName("ContainerComponentsLib.UINT_PTR")]
	public uint wParam;

	[ComAliasName("ContainerComponentsLib.LONG_PTR")]
	public int lParam;

	public uint time;

	public tagPOINT pt;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct _RemotableHandle
{
	public int fContext;

	public __MIDL_IWinTypes_0009 u;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct tagPOINT
{
	public int x;

	public int y;
}
[StructLayout(LayoutKind.Explicit, Pack = 4, Size = 4)]
public struct __MIDL_IWinTypes_0009
{
	[FieldOffset(0)]
	public int hInproc;

	[FieldOffset(0)]
	public int hRemote;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct tagSIZE
{
	public int cx;

	public int cy;
}
[ComImport]
[Guid("27BF50B1-5D50-4C4B-9824-890C32348421")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
public interface IFeatureInputAdapterConfig
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Initialize();
}
