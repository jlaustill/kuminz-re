using System;
using System.Collections;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Threading;

[assembly: ImportedFromTypeLib("stdole")]
[assembly: Guid("00020430-0000-0000-c000-000000000046")]
[assembly: PrimaryInteropAssembly(2, 0)]
[assembly: AssemblyVersion("7.0.3300.0")]
namespace stdole;

[StructLayout(LayoutKind.Sequential, Pack = 4)]
[TypeLibType(16)]
public struct GUID
{
	public uint Data1;

	public ushort Data2;

	public ushort Data3;

	[MarshalAs(UnmanagedType.ByValArray, SizeConst = 8)]
	public byte[] Data4;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
[TypeLibType(512)]
public struct DISPPARAMS
{
	[ComConversionLoss]
	public IntPtr rgvarg;

	[ComConversionLoss]
	public IntPtr rgdispidNamedArgs;

	public uint cArgs;

	public uint cNamedArgs;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[TypeLibType(512)]
[ComConversionLoss]
public struct EXCEPINFO
{
	public ushort wCode;

	public ushort wReserved;

	[MarshalAs(UnmanagedType.BStr)]
	public string bstrSource;

	[MarshalAs(UnmanagedType.BStr)]
	public string bstrDescription;

	[MarshalAs(UnmanagedType.BStr)]
	public string bstrHelpFile;

	public uint dwHelpContext;

	[ComConversionLoss]
	public IntPtr pvReserved;

	[ComConversionLoss]
	public IntPtr pfnDeferredFillIn;

	[MarshalAs(UnmanagedType.Error)]
	public int scode;
}
[ComImport]
[Guid("00000000-0000-0000-C000-000000000046")]
[InterfaceType(1)]
[TypeLibType(16)]
public interface IUnknown
{
}
[ComImport]
[Guid("00020400-0000-0000-C000-000000000046")]
[TypeLibType(512)]
public interface IDispatch
{
}
[ComImport]
[Guid("00020404-0000-0000-C000-000000000046")]
[InterfaceType(1)]
[TypeLibType(16)]
public interface IEnumVARIANT
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Next([In] uint celt, [In][MarshalAs(UnmanagedType.Struct)] ref object rgvar, out uint pceltFetched);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Skip([In] uint celt);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=1.0.3300.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")] out IEnumerator ppenum);
}
[Guid("6650430A-BE0F-101A-8BBB-00AA00300CAB")]
public enum OLE_TRISTATE
{
	Unchecked,
	Checked,
	Gray
}
[ComImport]
[Guid("BEF6E002-A874-101A-8BBA-00AA00300CAB")]
[InterfaceType(1)]
[TypeLibType(16)]
public interface IFont
{
	[DispId(1610678272)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610678274)]
	decimal Size
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Currency)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Currency)]
		set;
	}

	[DispId(1610678276)]
	bool Bold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[DispId(1610678278)]
	bool Italic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[DispId(1610678280)]
	bool Underline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[DispId(1610678282)]
	bool Strikethrough
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[DispId(1610678284)]
	short Weight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[DispId(1610678286)]
	short Charset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[DispId(1610678288)]
	[ComAliasName("stdole.OLE_HANDLE")]
	int hFont
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("stdole.OLE_HANDLE")]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IFont ppfont);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsEqual([In][MarshalAs(UnmanagedType.Interface)] IFont pfontOther);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetRatio([In] int cyLogical, [In] int cyHimetric);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddRefHfont([In][ComAliasName("stdole.OLE_HANDLE")] int hFont);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReleaseHfont([In][ComAliasName("stdole.OLE_HANDLE")] int hFont);
}
[ComImport]
[TypeLibType(4096)]
[DefaultMember("Name")]
[Guid("BEF6E003-A874-101A-8BBA-00AA00300CAB")]
[InterfaceType(2)]
public interface Font
{
	[DispId(0)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		set;
	}

	[DispId(2)]
	decimal Size
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		set;
	}

	[DispId(3)]
	bool Bold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		set;
	}

	[DispId(4)]
	bool Italic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		set;
	}

	[DispId(5)]
	bool Underline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		set;
	}

	[DispId(6)]
	bool Strikethrough
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		set;
	}

	[DispId(7)]
	short Weight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		set;
	}

	[DispId(8)]
	short Charset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		set;
	}
}
[ComImport]
[Guid("BEF6E003-A874-101A-8BBA-00AA00300CAB")]
[InterfaceType(2)]
[DefaultMember("Name")]
public interface IFontDisp
{
	[DispId(0)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		set;
	}

	[DispId(2)]
	decimal Size
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		set;
	}

	[DispId(3)]
	bool Bold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		set;
	}

	[DispId(4)]
	bool Italic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		set;
	}

	[DispId(5)]
	bool Underline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		set;
	}

	[DispId(6)]
	bool Strikethrough
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		set;
	}

	[DispId(7)]
	short Weight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		set;
	}

	[DispId(8)]
	short Charset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		set;
	}
}
[ComImport]
[DefaultMember("Name")]
[ClassInterface(0)]
[ComSourceInterfaces("stdole.FontEvents\0\0")]
[Guid("0BE35203-8F91-11CE-9DE3-00AA004BB851")]
[TypeLibType(2)]
public class StdFontClass : Font, StdFont, FontEvents_Event, IFont
{
	[DispId(0)]
	public virtual extern string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		set;
	}

	[DispId(2)]
	public virtual extern decimal Size
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		set;
	}

	[DispId(3)]
	public virtual extern bool Bold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		set;
	}

	[DispId(4)]
	public virtual extern bool Italic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		set;
	}

	[DispId(5)]
	public virtual extern bool Underline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		set;
	}

	[DispId(6)]
	public virtual extern bool Strikethrough
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		set;
	}

	[DispId(7)]
	public virtual extern short Weight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		set;
	}

	[DispId(8)]
	public virtual extern short Charset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		set;
	}

	public virtual extern string IFont_Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	public virtual extern decimal IFont_Size
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Currency)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Currency)]
		set;
	}

	public virtual extern bool IFont_Bold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern bool IFont_Italic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern bool IFont_Underline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern bool IFont_Strikethrough
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern short IFont_Weight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern short IFont_Charset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.OLE_HANDLE")]
	public virtual extern int hFont
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("stdole.OLE_HANDLE")]
		get;
	}

	public virtual extern event FontEvents_FontChangedEventHandler FontChanged;

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void Clone([MarshalAs(UnmanagedType.Interface)] out IFont ppfont);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IsEqual([In][MarshalAs(UnmanagedType.Interface)] IFont pfontOther);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void SetRatio([In] int cyLogical, [In] int cyHimetric);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void AddRefHfont([In][ComAliasName("stdole.OLE_HANDLE")] int hFont);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ReleaseHfont([In][ComAliasName("stdole.OLE_HANDLE")] int hFont);
}
[ComVisible(false)]
[ComEventInterface(typeof(FontEvents\u0000), typeof(FontEvents_EventProvider\u0000))]
public interface FontEvents_Event
{
	event FontEvents_FontChangedEventHandler FontChanged;
}
[ComVisible(false)]
public delegate void FontEvents_FontChangedEventHandler([In][MarshalAs(UnmanagedType.BStr)] string PropertyName);
[ComImport]
[Guid("BEF6E003-A874-101A-8BBA-00AA00300CAB")]
[CoClass(typeof(StdFontClass))]
public interface StdFont : Font, FontEvents_Event
{
}
[ComImport]
[ComConversionLoss]
[TypeLibType(16)]
[Guid("7BF80980-BF32-101A-8BBB-00AA00300CAB")]
[InterfaceType(1)]
public interface IPicture
{
	[DispId(1610678272)]
	[ComAliasName("stdole.OLE_HANDLE")]
	int Handle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("stdole.OLE_HANDLE")]
		get;
	}

	[DispId(1610678273)]
	[ComAliasName("stdole.OLE_HANDLE")]
	int hPal
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("stdole.OLE_HANDLE")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("stdole.OLE_HANDLE")]
		set;
	}

	[DispId(1610678274)]
	short Type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678275)]
	[ComAliasName("stdole.OLE_XSIZE_HIMETRIC")]
	int Width
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("stdole.OLE_XSIZE_HIMETRIC")]
		get;
	}

	[DispId(1610678276)]
	[ComAliasName("stdole.OLE_YSIZE_HIMETRIC")]
	int Height
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("stdole.OLE_YSIZE_HIMETRIC")]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Render([In] int hdc, [In] int x, [In] int y, [In] int cx, [In] int cy, [In][ComAliasName("stdole.OLE_XPOS_HIMETRIC")] int xSrc, [In][ComAliasName("stdole.OLE_YPOS_HIMETRIC")] int ySrc, [In][ComAliasName("stdole.OLE_XSIZE_HIMETRIC")] int cxSrc, [In][ComAliasName("stdole.OLE_YSIZE_HIMETRIC")] int cySrc, [In] IntPtr prcWBounds);

	[DispId(1610678279)]
	int CurDC
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SelectPicture([In] int hdcIn, out int phdcOut, [ComAliasName("stdole.OLE_HANDLE")] out int phbmpOut);

	[DispId(1610678281)]
	bool KeepOriginalFormat
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void PictureChanged();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SaveAsFile([In] IntPtr pstm, [In] bool fSaveMemCopy, out int pcbSize);

	[DispId(1610678285)]
	int Attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetHdc([In][ComAliasName("stdole.OLE_HANDLE")] int hdc);
}
[ComImport]
[DefaultMember("Handle")]
[TypeLibType(4096)]
[Guid("7BF80981-BF32-101A-8BBB-00AA00300CAB")]
[InterfaceType(2)]
[ComConversionLoss]
public interface Picture
{
	[DispId(0)]
	[ComAliasName("stdole.OLE_HANDLE")]
	int Handle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		get;
	}

	[ComAliasName("stdole.OLE_HANDLE")]
	[DispId(2)]
	int hPal
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		set;
	}

	[DispId(3)]
	short Type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[ComAliasName("stdole.OLE_XSIZE_HIMETRIC")]
	[DispId(4)]
	int Width
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}

	[DispId(5)]
	[ComAliasName("stdole.OLE_YSIZE_HIMETRIC")]
	int Height
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
	}

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void Render(int hdc, int x, int y, int cx, int cy, [ComAliasName("stdole.OLE_XPOS_HIMETRIC")] int xSrc, [ComAliasName("stdole.OLE_YPOS_HIMETRIC")] int ySrc, [ComAliasName("stdole.OLE_XSIZE_HIMETRIC")] int cxSrc, [ComAliasName("stdole.OLE_YSIZE_HIMETRIC")] int cySrc, IntPtr prcWBounds);
}
[ComImport]
[DefaultMember("Handle")]
[InterfaceType(2)]
[Guid("7BF80981-BF32-101A-8BBB-00AA00300CAB")]
[ComConversionLoss]
public interface IPictureDisp
{
	[DispId(0)]
	[ComAliasName("stdole.OLE_HANDLE")]
	int Handle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		get;
	}

	[DispId(2)]
	[ComAliasName("stdole.OLE_HANDLE")]
	int hPal
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		set;
	}

	[DispId(3)]
	short Type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[DispId(4)]
	[ComAliasName("stdole.OLE_XSIZE_HIMETRIC")]
	int Width
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}

	[DispId(5)]
	[ComAliasName("stdole.OLE_YSIZE_HIMETRIC")]
	int Height
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
	}

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void Render(int hdc, int x, int y, int cx, int cy, [ComAliasName("stdole.OLE_XPOS_HIMETRIC")] int xSrc, [ComAliasName("stdole.OLE_YPOS_HIMETRIC")] int ySrc, [ComAliasName("stdole.OLE_XSIZE_HIMETRIC")] int cxSrc, [ComAliasName("stdole.OLE_YSIZE_HIMETRIC")] int cySrc, IntPtr prcWBounds);
}
[ComImport]
[TypeLibType(2)]
[ComConversionLoss]
[Guid("0BE35204-8F91-11CE-9DE3-00AA004BB851")]
[DefaultMember("Handle")]
[ClassInterface(0)]
public class StdPictureClass : Picture, StdPicture, IPicture
{
	[ComAliasName("stdole.OLE_HANDLE")]
	[DispId(0)]
	public virtual extern int Handle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		get;
	}

	[DispId(2)]
	[ComAliasName("stdole.OLE_HANDLE")]
	public virtual extern int hPal
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		set;
	}

	[DispId(3)]
	public virtual extern short Type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[DispId(4)]
	[ComAliasName("stdole.OLE_XSIZE_HIMETRIC")]
	public virtual extern int Width
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}

	[DispId(5)]
	[ComAliasName("stdole.OLE_YSIZE_HIMETRIC")]
	public virtual extern int Height
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
	}

	[ComAliasName("stdole.OLE_HANDLE")]
	public virtual extern int IPicture_Handle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("stdole.OLE_HANDLE")]
		get;
	}

	[ComAliasName("stdole.OLE_HANDLE")]
	public virtual extern int IPicture_hPal
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("stdole.OLE_HANDLE")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("stdole.OLE_HANDLE")]
		set;
	}

	public virtual extern short IPicture_Type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[ComAliasName("stdole.OLE_XSIZE_HIMETRIC")]
	public virtual extern int IPicture_Width
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("stdole.OLE_XSIZE_HIMETRIC")]
		get;
	}

	[ComAliasName("stdole.OLE_YSIZE_HIMETRIC")]
	public virtual extern int IPicture_Height
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("stdole.OLE_YSIZE_HIMETRIC")]
		get;
	}

	public virtual extern int CurDC
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern bool KeepOriginalFormat
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int Attributes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	public virtual extern void Render(int hdc, int x, int y, int cx, int cy, [ComAliasName("stdole.OLE_XPOS_HIMETRIC")] int xSrc, [ComAliasName("stdole.OLE_YPOS_HIMETRIC")] int ySrc, [ComAliasName("stdole.OLE_XSIZE_HIMETRIC")] int cxSrc, [ComAliasName("stdole.OLE_YSIZE_HIMETRIC")] int cySrc, IntPtr prcWBounds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IPicture_Render([In] int hdc, [In] int x, [In] int y, [In] int cx, [In] int cy, [In][ComAliasName("stdole.OLE_XPOS_HIMETRIC")] int xSrc, [In][ComAliasName("stdole.OLE_YPOS_HIMETRIC")] int ySrc, [In][ComAliasName("stdole.OLE_XSIZE_HIMETRIC")] int cxSrc, [In][ComAliasName("stdole.OLE_YSIZE_HIMETRIC")] int cySrc, [In] IntPtr prcWBounds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void SelectPicture([In] int hdcIn, out int phdcOut, [ComAliasName("stdole.OLE_HANDLE")] out int phbmpOut);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void PictureChanged();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void SaveAsFile([In] IntPtr pstm, [In] bool fSaveMemCopy, out int pcbSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void SetHdc([In][ComAliasName("stdole.OLE_HANDLE")] int hdc);
}
[ComImport]
[CoClass(typeof(StdPictureClass))]
[Guid("7BF80981-BF32-101A-8BBB-00AA00300CAB")]
public interface StdPicture : Picture
{
}
[Guid("E6C8FA08-BD9F-11D0-985E-00C04FC29993")]
public enum LoadPictureConstants
{
	Default = 0,
	Monochrome = 1,
	VgaColor = 2,
	Color = 4
}
[ComImport]
[Guid("4EF6100A-AF88-11D0-9846-00C04FC29993")]
[TypeLibType(4112)]
[InterfaceType(2)]
public interface FontEvents
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void FontChanged([In][MarshalAs(UnmanagedType.BStr)] string PropertyName);
}
[ComImport]
[InterfaceType(2)]
[Guid("4EF6100A-AF88-11D0-9846-00C04FC29993")]
public interface IFontEventsDisp
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void FontChanged([In][MarshalAs(UnmanagedType.BStr)] string PropertyName);
}
[ClassInterface(ClassInterfaceType.None)]
internal sealed class FontEvents_SinkHelper : FontEvents
{
	public FontEvents_FontChangedEventHandler m_FontChangedDelegate;

	public int m_dwCookie;

	public void FontChanged(string A_1)
	{
		if (m_FontChangedDelegate != null)
		{
			m_FontChangedDelegate(A_1);
		}
	}

	internal FontEvents_SinkHelper()
	{
		m_dwCookie = 0;
		m_FontChangedDelegate = null;
	}
}
internal sealed class FontEvents_EventProvider : FontEvents_Event, IDisposable
{
	private UCOMIConnectionPointContainer m_ConnectionPointContainer;

	private ArrayList m_aEventSinkHelpers;

	private UCOMIConnectionPoint m_ConnectionPoint;

	private void Init()
	{
		//IL_00ec: Unknown result type (might be due to invalid IL or missing references)
		//IL_00f6: Expected O, but got Unknown
		UCOMIConnectionPoint val = null;
		Guid guid = new Guid(new byte[16]
		{
			10, 16, 246, 78, 136, 175, 208, 17, 152, 70,
			0, 192, 79, 194, 153, 147
		});
		m_ConnectionPointContainer.FindConnectionPoint(ref guid, ref val);
		m_ConnectionPoint = val;
		m_aEventSinkHelpers = new ArrayList();
	}

	public void add_FontChanged(FontEvents_FontChangedEventHandler A_1)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			FontEvents_SinkHelper fontEvents_SinkHelper = new FontEvents_SinkHelper();
			int dwCookie = 0;
			m_ConnectionPoint.Advise((object)fontEvents_SinkHelper, ref dwCookie);
			fontEvents_SinkHelper.m_dwCookie = dwCookie;
			fontEvents_SinkHelper.m_FontChangedDelegate = A_1;
			m_aEventSinkHelpers.Add(fontEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_FontChanged(FontEvents_FontChangedEventHandler A_1)
	{
		Monitor.Enter(this);
		try
		{
			int count = m_aEventSinkHelpers.Count;
			int num = 0;
			if (0 >= count)
			{
				return;
			}
			do
			{
				FontEvents_SinkHelper fontEvents_SinkHelper = (FontEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (fontEvents_SinkHelper.m_FontChangedDelegate != null && ((fontEvents_SinkHelper.m_FontChangedDelegate.Equals(A_1) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(fontEvents_SinkHelper.m_dwCookie);
					if (count <= 1)
					{
						m_ConnectionPoint = null;
						m_aEventSinkHelpers = null;
					}
					break;
				}
				num++;
			}
			while (num < count);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public FontEvents_EventProvider(object A_1)
	{
		//IL_0011: Unknown result type (might be due to invalid IL or missing references)
		//IL_001b: Expected O, but got Unknown
		m_ConnectionPointContainer = (UCOMIConnectionPointContainer)A_1;
	}

	public void Finalize()
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				return;
			}
			int count = m_aEventSinkHelpers.Count;
			int num = 0;
			if (0 < count)
			{
				do
				{
					FontEvents_SinkHelper fontEvents_SinkHelper = (FontEvents_SinkHelper)m_aEventSinkHelpers[num];
					m_ConnectionPoint.Unadvise(fontEvents_SinkHelper.m_dwCookie);
					num++;
				}
				while (num < count);
			}
		}
		catch (Exception)
		{
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void Dispose()
	{
		Finalize();
		GC.SuppressFinalize(this);
	}
}
