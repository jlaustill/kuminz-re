using System;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: Guid("81274f0d-b309-4147-94e6-9a1ec2d29efb")]
[assembly: ImportedFromTypeLib("OLE")]
[assembly: AssemblyVersion("7.1.40304.0")]
namespace Microsoft.VisualStudio.OLE.Interop;

[ComImport]
[Guid("B722BCC5-4E68-101B-A2BC-00AA00404770")]
[InterfaceType(1)]
public interface IOleDocument
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CreateView([In][MarshalAs(UnmanagedType.Interface)] IOleInPlaceSite pIPSite, [In][MarshalAs(UnmanagedType.Interface)] IStream pstm, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved, [MarshalAs(UnmanagedType.Interface)] out IOleDocumentView ppView);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDocMiscStatus([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwStatus);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumViews([MarshalAs(UnmanagedType.Interface)] out IEnumOleDocumentViews ppEnum, [MarshalAs(UnmanagedType.Interface)] out IOleDocumentView ppView);
}
[ComImport]
[Guid("00000119-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IOleInPlaceSite : IOleWindow
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetWindow(out IntPtr phwnd);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void ContextSensitiveHelp([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fEnterMode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CanInPlaceActivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnInPlaceActivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnUIActivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetWindowContext([MarshalAs(UnmanagedType.Interface)] out IOleInPlaceFrame ppFrame, [MarshalAs(UnmanagedType.Interface)] out IOleInPlaceUIWindow ppDoc, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] lprcPosRect, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] lprcClipRect, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLEINPLACEFRAMEINFO")][MarshalAs(UnmanagedType.LPArray)] OLEINPLACEFRAMEINFO[] lpFrameInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Scroll([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.SIZE")] SIZE scrollExtant);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnUIDeactivate([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fUndoable);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnInPlaceDeactivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DiscardUndoState();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DeactivateAndUndo();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnPosRectChange([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] lprcPosRect);
}
[ComImport]
[ComConversionLoss]
[Guid("00000114-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IOleWindow
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetWindow(out IntPtr phwnd);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ContextSensitiveHelp([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fEnterMode);
}
[ComImport]
[InterfaceType(1)]
[ComConversionLoss]
[Guid("00000116-0000-0000-C000-000000000046")]
public interface IOleInPlaceFrame : IOleInPlaceUIWindow
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetWindow(out IntPtr phwnd);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void ContextSensitiveHelp([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fEnterMode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetBorder([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] lprectBorder);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void RequestBorderSpace([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCBORDERWIDTHS")][MarshalAs(UnmanagedType.LPArray)] RECT[] pborderwidths);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void SetBorderSpace([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCBORDERWIDTHS")][MarshalAs(UnmanagedType.LPArray)] RECT[] pborderwidths);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void SetActiveObject([In][MarshalAs(UnmanagedType.Interface)] IOleInPlaceActiveObject pActiveObject, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszObjName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void InsertMenus([In] IntPtr hmenuShared, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLEMENUGROUPWIDTHS")][MarshalAs(UnmanagedType.LPArray)] OLEMENUGROUPWIDTHS[] lpMenuWidths);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetMenu([In] IntPtr hmenuShared, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.HOLEMENU")] IntPtr HOLEMENU, [In] IntPtr hwndActiveObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoveMenus([In] IntPtr hmenuShared);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetStatusText([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszStatusText);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnableModeless([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fEnable);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int TranslateAccelerator([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.MSG")][MarshalAs(UnmanagedType.LPArray)] MSG[] lpmsg, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")] ushort wID);
}
[ComImport]
[Guid("00000115-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IOleInPlaceUIWindow : IOleWindow
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetWindow(out IntPtr phwnd);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void ContextSensitiveHelp([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fEnterMode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetBorder([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] lprectBorder);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RequestBorderSpace([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCBORDERWIDTHS")][MarshalAs(UnmanagedType.LPArray)] RECT[] pborderwidths);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetBorderSpace([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCBORDERWIDTHS")][MarshalAs(UnmanagedType.LPArray)] RECT[] pborderwidths);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetActiveObject([In][MarshalAs(UnmanagedType.Interface)] IOleInPlaceActiveObject pActiveObject, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszObjName);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct RECT
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int left;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int top;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int right;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int bottom;
}
[ComImport]
[Guid("00000117-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IOleInPlaceActiveObject : IOleWindow
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetWindow(out IntPtr phwnd);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void ContextSensitiveHelp([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fEnterMode);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int TranslateAccelerator([In][MarshalAs(UnmanagedType.LPArray)] MSG[] lpmsg);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnFrameWindowActivate([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fActivate);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnDocWindowActivate([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fActivate);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ResizeBorder([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] prcBorder, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In][MarshalAs(UnmanagedType.Interface)] IOleInPlaceUIWindow pUIWindow, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fFrameWindow);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnableModeless([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fEnable);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct OLEMENUGROUPWIDTHS
{
	[MarshalAs(UnmanagedType.ByValArray, SizeConst = 6)]
	public int[] width;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct MSG
{
	[ComConversionLoss]
	public IntPtr hwnd;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")]
	public uint message;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT_PTR")]
	public IntPtr wParam;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG_PTR")]
	public IntPtr lParam;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint time;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.POINT")]
	public POINT pt;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct POINT
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int x;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int y;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct OLEINPLACEFRAMEINFO
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")]
	public uint cb;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	public int fMDIApp;

	[ComConversionLoss]
	public IntPtr hwndFrame;

	[ComConversionLoss]
	public IntPtr haccel;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")]
	public uint cAccelEntries;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct SIZE
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int cx;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int cy;
}
[ComImport]
[Guid("0000000C-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IStream : ISequentialStream
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Read([Out][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] byte[] pv, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cb, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcbRead);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Write([In][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] byte[] pv, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cb, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcbWritten);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Seek([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LARGE_INTEGER")] LARGE_INTEGER dlibMove, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwOrigin, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")][MarshalAs(UnmanagedType.LPArray)] ULARGE_INTEGER[] plibNewPosition);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetSize([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")] ULARGE_INTEGER libNewSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CopyTo([In][MarshalAs(UnmanagedType.Interface)] IStream pstm, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")] ULARGE_INTEGER cb, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")][MarshalAs(UnmanagedType.LPArray)] ULARGE_INTEGER[] pcbRead, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")][MarshalAs(UnmanagedType.LPArray)] ULARGE_INTEGER[] pcbWritten);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Commit([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfCommitFlags);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Revert();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void LockRegion([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")] ULARGE_INTEGER libOffset, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")] ULARGE_INTEGER cb, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwLockType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void UnlockRegion([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")] ULARGE_INTEGER libOffset, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")] ULARGE_INTEGER cb, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwLockType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Stat([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.STATSTG")][MarshalAs(UnmanagedType.LPArray)] STATSTG[] pstatstg, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfStatFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IStream ppstm);
}
[ComImport]
[Guid("0C733A30-2A1C-11CE-ADE5-00AA0044773D")]
[InterfaceType(1)]
public interface ISequentialStream
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Read([Out][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] byte[] pv, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cb, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcbRead);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Write([In][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] byte[] pv, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cb, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcbWritten);
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct LARGE_INTEGER
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONGLONG")]
	public long QuadPart;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct ULARGE_INTEGER
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONGLONG")]
	public ulong QuadPart;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct STATSTG
{
	[MarshalAs(UnmanagedType.LPWStr)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")]
	public string pwcsName;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint type;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")]
	public ULARGE_INTEGER cbSize;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.FILETIME")]
	public FILETIME mtime;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.FILETIME")]
	public FILETIME ctime;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.FILETIME")]
	public FILETIME atime;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint grfMode;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint grfLocksSupported;

	public Guid clsid;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint grfStateBits;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint reserved;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct FILETIME
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwLowDateTime;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwHighDateTime;
}
[ComImport]
[InterfaceType(1)]
[Guid("B722BCC6-4E68-101B-A2BC-00AA00404770")]
public interface IOleDocumentView
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetInPlaceSite([In][MarshalAs(UnmanagedType.Interface)] IOleInPlaceSite pIPSite);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetInPlaceSite([MarshalAs(UnmanagedType.Interface)] out IOleInPlaceSite ppIPSite);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDocument([MarshalAs(UnmanagedType.IUnknown)] out object ppunk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetRect([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] prcView);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetRect([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] prcView);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetRectComplex([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] prcView, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] prcHScroll, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] prcVScroll, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] prcSizeBox);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Show([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fShow);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void UIActivate([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fUIActivate);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Open();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CloseView([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SaveViewState([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPSTREAM")][MarshalAs(UnmanagedType.Interface)] IStream pstm);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ApplyViewState([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPSTREAM")][MarshalAs(UnmanagedType.Interface)] IStream pstm);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([In][MarshalAs(UnmanagedType.Interface)] IOleInPlaceSite pIPSiteNew, [MarshalAs(UnmanagedType.Interface)] out IOleDocumentView ppViewNew);
}
[ComImport]
[Guid("B722BCC8-4E68-101B-A2BC-00AA00404770")]
[InterfaceType(1)]
public interface IEnumOleDocumentViews
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cViews, [Out][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.Interface)] IOleDocumentView[] rgpView, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcFetched);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cViews);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumOleDocumentViews ppEnum);
}
[ComImport]
[Guid("B722BCC7-4E68-101B-A2BC-00AA00404770")]
[InterfaceType(1)]
public interface IOleDocumentSite
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ActivateMe([In][MarshalAs(UnmanagedType.Interface)] IOleDocumentView pViewToActivate);
}
[ComImport]
[InterfaceType(1)]
[Guid("B722BCCA-4E68-101B-A2BC-00AA00404770")]
public interface IContinueCallback
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FContinue();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FContinuePrinting([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int nCntPrinted, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int nCurPage, [In][MarshalAs(UnmanagedType.LPWStr)] string pwszPrintStatus);
}
[ComImport]
[InterfaceType(1)]
[Guid("B722BCC9-4E68-101B-A2BC-00AA00404770")]
[ComConversionLoss]
public interface IPrint
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetInitialPageNum([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int nFirstPage);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPageInfo([ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] out int pnFirstPage, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] out int pcPages);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Print([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfFlags, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DVTARGETDEVICE")] ref IntPtr pptd, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.PAGESET")] ref IntPtr ppPageSet, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.STGMEDIUM")][MarshalAs(UnmanagedType.LPArray)] STGMEDIUM[] pstgmOptions, [In][MarshalAs(UnmanagedType.Interface)] IContinueCallback pcallback, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int nFirstPage, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] out int pcPagesPrinted, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] out int pnLastPage);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct DVTARGETDEVICE
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint tdSize;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort tdDriverNameOffset;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort tdDeviceNameOffset;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort tdPortNameOffset;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort tdExtDevmodeOffset;

	[ComConversionLoss]
	public IntPtr tdData;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct PAGESET
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cbStruct;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	public int fOddPages;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	public int fEvenPages;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cPageRange;

	[ComConversionLoss]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.PAGERANGE")]
	public IntPtr rgPages;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct PAGERANGE
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int nFromPage;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int nToPage;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct STGMEDIUM
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint tymed;

	public IntPtr unionmember;

	[MarshalAs(UnmanagedType.IUnknown)]
	public object pUnkForRelease;
}
[ComImport]
[InterfaceType(1)]
[Guid("0000000B-0000-0000-C000-000000000046")]
[ComConversionLoss]
public interface IStorage
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CreateStream([In][MarshalAs(UnmanagedType.LPWStr)] string pwcsName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfMode, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint reserved1, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint reserved2, [MarshalAs(UnmanagedType.Interface)] out IStream ppstm);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OpenStream([In][MarshalAs(UnmanagedType.LPWStr)] string pwcsName, [In] IntPtr reserved1, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfMode, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint reserved2, [MarshalAs(UnmanagedType.Interface)] out IStream ppstm);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CreateStorage([In][MarshalAs(UnmanagedType.LPWStr)] string pwcsName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfMode, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint reserved1, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint reserved2, [MarshalAs(UnmanagedType.Interface)] out IStorage ppstg);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OpenStorage([In][MarshalAs(UnmanagedType.LPWStr)] string pwcsName, [In][MarshalAs(UnmanagedType.Interface)] IStorage pstgPriority, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfMode, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.SNB")] IntPtr snbExclude, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint reserved, [MarshalAs(UnmanagedType.Interface)] out IStorage ppstg);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CopyTo([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint ciidExclude, [In][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] Guid[] rgiidExclude, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.SNB")] IntPtr snbExclude, [In][MarshalAs(UnmanagedType.Interface)] IStorage pstgDest);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void MoveElementTo([In][MarshalAs(UnmanagedType.LPWStr)] string pwcsName, [In][MarshalAs(UnmanagedType.Interface)] IStorage pstgDest, [In][MarshalAs(UnmanagedType.LPWStr)] string pwcsNewName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfFlags);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Commit([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfCommitFlags);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Revert();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumElements([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint reserved1, [In] IntPtr reserved2, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint reserved3, [MarshalAs(UnmanagedType.Interface)] out IEnumSTATSTG ppEnum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DestroyElement([In][MarshalAs(UnmanagedType.LPWStr)] string pwcsName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RenameElement([In][MarshalAs(UnmanagedType.LPWStr)] string pwcsOldName, [In][MarshalAs(UnmanagedType.LPWStr)] string pwcsNewName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetElementTimes([In][MarshalAs(UnmanagedType.LPWStr)] string pwcsName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FILETIME")][MarshalAs(UnmanagedType.LPArray)] FILETIME[] pctime, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FILETIME")][MarshalAs(UnmanagedType.LPArray)] FILETIME[] patime, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FILETIME")][MarshalAs(UnmanagedType.LPArray)] FILETIME[] pmtime);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetClass([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFCLSID")] ref Guid clsid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetStateBits([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfStateBits, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfMask);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Stat([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.STATSTG")][MarshalAs(UnmanagedType.LPArray)] STATSTG[] pstatstg, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfStatFlag);
}
[ComImport]
[Guid("0000000D-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IEnumSTATSTG
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.STATSTG")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] STATSTG[] rgelt, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pceltFetched);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumSTATSTG ppEnum);
}
[ComImport]
[Guid("B722BCCB-4E68-101B-A2BC-00AA00404770")]
[InterfaceType(1)]
public interface IOleCommandTarget
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int QueryStatus([In] ref Guid pguidCmdGroup, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cCmds, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECMD")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] OLECMD[] prgCmds, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECMDTEXT")] IntPtr pCmdText);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Exec([In] ref Guid pguidCmdGroup, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint nCmdID, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint nCmdexecopt, [In] IntPtr pvaIn, [In] IntPtr pvaOut);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct OLECMD
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cmdID;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint cmdf;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct OLECMDTEXT
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint cmdtextf;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cwActual;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cwBuf;

	[ComConversionLoss]
	public IntPtr rgwz;
}
public enum DOCMISC
{
	DOCMISC_CANCREATEMULTIPLEVIEWS = 1,
	DOCMISC_SUPPORTCOMPLEXRECTANGLES = 2,
	DOCMISC_CANTOPENEDIT = 4,
	DOCMISC_NOFILESUPPORT = 8
}
[Flags]
public enum PRINTFLAG
{
	PRINTFLAG_MAYBOTHERUSER = 1,
	PRINTFLAG_PROMPTUSER = 2,
	PRINTFLAG_USERMAYCHANGEPRINTER = 4,
	PRINTFLAG_RECOMPOSETODEVICE = 8,
	PRINTFLAG_DONTACTUALLYPRINT = 0x10,
	PRINTFLAG_FORCEPROPERTIES = 0x20,
	PRINTFLAG_PRINTTOFILE = 0x40
}
public enum OLECMDF
{
	OLECMDF_SUPPORTED = 1,
	OLECMDF_ENABLED = 2,
	OLECMDF_LATCHED = 4,
	OLECMDF_NINCHED = 8,
	OLECMDF_INVISIBLE = 0x10,
	OLECMDF_DEFHIDEONCTXTMENU = 0x20
}
public enum OLECMDTEXTF
{
	OLECMDTEXTF_NONE,
	OLECMDTEXTF_NAME,
	OLECMDTEXTF_STATUS
}
public enum OLECMDEXECOPT
{
	OLECMDEXECOPT_DODEFAULT,
	OLECMDEXECOPT_PROMPTUSER,
	OLECMDEXECOPT_DONTPROMPTUSER,
	OLECMDEXECOPT_SHOWHELP
}
public enum OLECMDID
{
	OLECMDID_OPEN = 1,
	OLECMDID_NEW,
	OLECMDID_SAVE,
	OLECMDID_SAVEAS,
	OLECMDID_SAVECOPYAS,
	OLECMDID_PRINT,
	OLECMDID_PRINTPREVIEW,
	OLECMDID_PAGESETUP,
	OLECMDID_SPELL,
	OLECMDID_PROPERTIES,
	OLECMDID_CUT,
	OLECMDID_COPY,
	OLECMDID_PASTE,
	OLECMDID_PASTESPECIAL,
	OLECMDID_UNDO,
	OLECMDID_REDO,
	OLECMDID_SELECTALL,
	OLECMDID_CLEARSELECTION,
	OLECMDID_ZOOM,
	OLECMDID_GETZOOMRANGE,
	OLECMDID_UPDATECOMMANDS,
	OLECMDID_REFRESH,
	OLECMDID_STOP,
	OLECMDID_HIDETOOLBARS,
	OLECMDID_SETPROGRESSMAX,
	OLECMDID_SETPROGRESSPOS,
	OLECMDID_SETPROGRESSTEXT,
	OLECMDID_SETTITLE,
	OLECMDID_SETDOWNLOADSTATE,
	OLECMDID_STOPDOWNLOAD,
	OLECMDID_ONTOOLBARACTIVATED,
	OLECMDID_FIND,
	OLECMDID_DELETE,
	OLECMDID_HTTPEQUIV,
	OLECMDID_HTTPEQUIV_DONE,
	OLECMDID_ENABLE_INTERACTION,
	OLECMDID_ONUNLOAD,
	OLECMDID_PROPERTYBAG2,
	OLECMDID_PREREFRESH,
	OLECMDID_SHOWSCRIPTERROR,
	OLECMDID_SHOWMESSAGE,
	OLECMDID_SHOWFIND,
	OLECMDID_SHOWPAGESETUP,
	OLECMDID_SHOWPRINT,
	OLECMDID_CLOSE,
	OLECMDID_ALLOWUILESSSAVEAS,
	OLECMDID_DONTDOWNLOADCSS,
	OLECMDID_UPDATEPAGESTATUS,
	OLECMDID_PRINT2,
	OLECMDID_PRINTPREVIEW2,
	OLECMDID_SETPRINTTEMPLATE,
	OLECMDID_GETPRINTTEMPLATE
}
public enum _OLECRF
{
	olecrfNeedIdleTime = 1,
	olecrfNeedPeriodicIdleTime = 2,
	olecrfPreTranslateKeys = 4,
	olecrfPreTranslateAll = 8,
	olecrfNeedSpecActiveNotifs = 0x10,
	olecrfNeedAllActiveNotifs = 0x20,
	olecrfExclusiveBorderSpace = 0x40,
	olecrfExclusiveActivation = 0x80
}
public enum _OLECADVF
{
	olecadvfModal = 1,
	olecadvfRedrawOff = 2,
	olecadvfWarningsOff = 4,
	olecadvfRecording = 8
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct OLECRINFO
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cbSize;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint uIdleTimeInterval;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECRF")]
	public uint grfcrf;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECADVF")]
	public uint grfcadvf;
}
public enum _OLECHOSTF
{
	olechostfExclusiveBorderSpace = 1
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct OLECHOSTINFO
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cbSize;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECHOSTF")]
	public uint grfchostf;
}
public enum _OLEIDLEF
{
	oleidlefPeriodic = 1,
	oleidlefNonPeriodic = 2,
	oleidlefPriority = 4,
	oleidlefAll = -1
}
public enum _OLELOOP
{
	oleloopFocusWait = 1,
	oleloopDoEvents,
	oleloopDebug,
	oleloopModalForm
}
public enum _OLECSTATE
{
	olecstateModal = 1,
	olecstateRedrawOff,
	olecstateWarningsOff,
	olecstateRecording
}
public enum _OLECCONTEXT
{
	oleccontextAll,
	oleccontextMine,
	oleccontextOthers
}
public enum _OLEGAC
{
	olegacActive,
	olegacTracking,
	olegacTrackingOrActive
}
public enum _OLECWINDOW
{
	olecWindowFrameToplevel,
	olecWindowFrameOwner,
	olecWindowComponent,
	olecWindowDlgOwner
}
[ComImport]
[Guid("000C0600-0000-0000-C000-000000000046")]
[ComConversionLoss]
[InterfaceType(1)]
public interface IOleComponent
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FReserved1([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint message, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT_PTR")] IntPtr wParam, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG_PTR")] IntPtr lParam);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FPreTranslateMessage([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.MSG")][MarshalAs(UnmanagedType.LPArray)] MSG[] pMsg);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnEnterState([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECSTATE")] uint uStateID, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fEnter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnAppActivate([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fActive, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwOtherThreadID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnLoseActivation();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnActivationChange([In][MarshalAs(UnmanagedType.Interface)] IOleComponent pic, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSameComponent, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECRINFO")][MarshalAs(UnmanagedType.LPArray)] OLECRINFO[] pcrinfo, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fHostIsActivating, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECHOSTINFO")][MarshalAs(UnmanagedType.LPArray)] OLECHOSTINFO[] pchostinfo, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FDoIdle([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLEIDLEF")] uint grfidlef);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FContinueMessageLoop([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLELOOP")] uint uReason, [In] IntPtr pvLoopData, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.MSG")][MarshalAs(UnmanagedType.LPArray)] MSG[] pMsgPeeked);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FQueryTerminate([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fPromptUser);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Terminate();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	IntPtr HwndGetWindow([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECWINDOW")] uint dwWhich, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved);
}
[ComImport]
[ComConversionLoss]
[InterfaceType(1)]
[Guid("000C0601-0000-0000-C000-000000000046")]
public interface IOleComponentManager
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void QueryService([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidService, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid iid, out IntPtr ppvObj);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FReserved1([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint message, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT_PTR")] IntPtr wParam, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG_PTR")] IntPtr lParam);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FRegisterComponent([In][MarshalAs(UnmanagedType.Interface)] IOleComponent piComponent, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECRINFO")][MarshalAs(UnmanagedType.LPArray)] OLECRINFO[] pcrinfo, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] out uint pdwComponentID);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FRevokeComponent([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint dwComponentID);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FUpdateComponentRegistration([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint dwComponentID, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECRINFO")][MarshalAs(UnmanagedType.LPArray)] OLECRINFO[] pcrinfo);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FOnComponentActivate([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint dwComponentID);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FSetTrackingComponent([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint dwComponentID, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fTrack);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnComponentEnterState([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint dwComponentID, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECSTATE")] uint uStateID, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECCONTEXT")] uint uContext, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cpicmExclude, [In][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.Interface)] IOleComponentManager[] rgpicmExclude, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FOnComponentExitState([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint dwComponentID, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECSTATE")] uint uStateID, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECCONTEXT")] uint uContext, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cpicmExclude, [In][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.Interface)] IOleComponentManager[] rgpicmExclude);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FInState([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECSTATE")] uint uStateID, [In] IntPtr pvoid);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FContinueIdle();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FPushMessageLoop([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint dwComponentID, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLELOOP")] uint uReason, [In] IntPtr pvLoopData);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FCreateSubComponentManager([In][MarshalAs(UnmanagedType.IUnknown)] object piunkOuter, [In][MarshalAs(UnmanagedType.IUnknown)] object piunkServProv, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, out IntPtr ppvObj);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FGetParentComponentManager([MarshalAs(UnmanagedType.Interface)] out IOleComponentManager ppicm);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int FGetActiveComponent([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLEGAC")] uint dwgac, [MarshalAs(UnmanagedType.Interface)] out IOleComponent ppic, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECRINFO")][MarshalAs(UnmanagedType.LPArray)] OLECRINFO[] pcrinfo, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved);
}
[Flags]
public enum TYPEFLAGS
{
	TYPEFLAG_FAPPOBJECT = 1,
	TYPEFLAG_FCANCREATE = 2,
	TYPEFLAG_FLICENSED = 4,
	TYPEFLAG_FPREDECLID = 8,
	TYPEFLAG_FHIDDEN = 0x10,
	TYPEFLAG_FCONTROL = 0x20,
	TYPEFLAG_FDUAL = 0x40,
	TYPEFLAG_FNONEXTENSIBLE = 0x80,
	TYPEFLAG_FOLEAUTOMATION = 0x100,
	TYPEFLAG_FRESTRICTED = 0x200,
	TYPEFLAG_FAGGREGATABLE = 0x400,
	TYPEFLAG_FREPLACEABLE = 0x800,
	TYPEFLAG_FDISPATCHABLE = 0x1000,
	TYPEFLAG_FREVERSEBIND = 0x2000,
	TYPEFLAG_FPROXY = 0x4000
}
[Flags]
public enum FUNCFLAGS
{
	FUNCFLAG_FRESTRICTED = 1,
	FUNCFLAG_FSOURCE = 2,
	FUNCFLAG_FBINDABLE = 4,
	FUNCFLAG_FREQUESTEDIT = 8,
	FUNCFLAG_FDISPLAYBIND = 0x10,
	FUNCFLAG_FDEFAULTBIND = 0x20,
	FUNCFLAG_FHIDDEN = 0x40,
	FUNCFLAG_FUSESGETLASTERROR = 0x80,
	FUNCFLAG_FDEFAULTCOLLELEM = 0x100,
	FUNCFLAG_FUIDEFAULT = 0x200,
	FUNCFLAG_FNONBROWSABLE = 0x400,
	FUNCFLAG_FREPLACEABLE = 0x800,
	FUNCFLAG_FIMMEDIATEBIND = 0x1000
}
[Flags]
public enum VARFLAGS
{
	VARFLAG_FREADONLY = 1,
	VARFLAG_FSOURCE = 2,
	VARFLAG_FBINDABLE = 4,
	VARFLAG_FREQUESTEDIT = 8,
	VARFLAG_FDISPLAYBIND = 0x10,
	VARFLAG_FDEFAULTBIND = 0x20,
	VARFLAG_FHIDDEN = 0x40,
	VARFLAG_FRESTRICTED = 0x80,
	VARFLAG_FDEFAULTCOLLELEM = 0x100,
	VARFLAG_FUIDEFAULT = 0x200,
	VARFLAG_FNONBROWSABLE = 0x400,
	VARFLAG_FREPLACEABLE = 0x800,
	VARFLAG_FIMMEDIATEBIND = 0x1000
}
public enum CHANGEKIND
{
	CHANGEKIND_ADDMEMBER,
	CHANGEKIND_DELETEMEMBER,
	CHANGEKIND_SETNAMES,
	CHANGEKIND_SETDOCUMENTATION,
	CHANGEKIND_GENERAL,
	CHANGEKIND_INVALIDATE,
	CHANGEKIND_CHANGEFAILED,
	CHANGEKIND_MAX
}
public enum SF_TYPE
{
	SF_ERROR = 10,
	SF_I1 = 16,
	SF_I2 = 2,
	SF_I4 = 3,
	SF_I8 = 20,
	SF_BSTR = 8,
	SF_UNKNOWN = 13,
	SF_DISPATCH = 9,
	SF_VARIANT = 12,
	SF_RECORD = 36,
	SF_HAVEIID = 32781
}
public enum TYPEKIND
{
	TKIND_ENUM,
	TKIND_RECORD,
	TKIND_MODULE,
	TKIND_INTERFACE,
	TKIND_DISPATCH,
	TKIND_COCLASS,
	TKIND_ALIAS,
	TKIND_UNION,
	TKIND_MAX
}
public enum CALLCONV
{
	CC_FASTCALL = 0,
	CC_CDECL = 1,
	CC_MSCPASCAL = 2,
	CC_PASCAL = 2,
	CC_MACPASCAL = 3,
	CC_STDCALL = 4,
	CC_FPFASTCALL = 5,
	CC_SYSCALL = 6,
	CC_MPWCDECL = 7,
	CC_MPWPASCAL = 8,
	CC_MAX = 9
}
public enum FUNCKIND
{
	FUNC_VIRTUAL,
	FUNC_PUREVIRTUAL,
	FUNC_NONVIRTUAL,
	FUNC_STATIC,
	FUNC_DISPATCH
}
public enum INVOKEKIND
{
	INVOKE_FUNC = 1,
	INVOKE_PROPERTYGET = 2,
	INVOKE_PROPERTYPUT = 4,
	INVOKE_PROPERTYPUTREF = 8
}
public enum VARKIND
{
	VAR_PERINSTANCE,
	VAR_STATIC,
	VAR_CONST,
	VAR_DISPATCH
}
public enum DESCKIND
{
	DESCKIND_NONE,
	DESCKIND_FUNCDESC,
	DESCKIND_VARDESC,
	DESCKIND_TYPECOMP,
	DESCKIND_IMPLICITAPPOBJ,
	DESCKIND_MAX
}
public enum SYSKIND
{
	SYS_WIN16,
	SYS_WIN32,
	SYS_MAC,
	SYS_WIN64
}
[Flags]
public enum LIBFLAGS
{
	LIBFLAG_FRESTRICTED = 1,
	LIBFLAG_FCONTROL = 2,
	LIBFLAG_FHIDDEN = 4,
	LIBFLAG_FHASDISKIMAGE = 8
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct FUNCDESC
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.MEMBERID")]
	public int memid;

	[ComConversionLoss]
	public IntPtr lprgscode;

	[ComConversionLoss]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ELEMDESC")]
	public IntPtr lprgelemdescParam;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.FUNCKIND")]
	public FUNCKIND FUNCKIND;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.INVOKEKIND")]
	public INVOKEKIND invkind;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.CALLCONV")]
	public CALLCONV CALLCONV;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.SHORT")]
	public short cParams;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.SHORT")]
	public short cParamsOpt;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.SHORT")]
	public short oVft;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.SHORT")]
	public short cScodes;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ELEMDESC")]
	public ELEMDESC elemdescFunc;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort wFuncFlags;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct ELEMDESC
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.TYPEDESC")]
	public TYPEDESC tdesc;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.PARAMDESC")]
	public PARAMDESC PARAMDESC;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct TYPEDESC
{
	public IntPtr unionmember;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.VARTYPE")]
	public ushort vt;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct SAFEARRAYBOUND
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElements;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int lLbound;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct PARAMDESC
{
	[ComConversionLoss]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.PARAMDESCEX")]
	public IntPtr pparamdescex;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.USHORT")]
	public ushort wParamFlags;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct PARAMDESCEX
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cBytes;

	[MarshalAs(UnmanagedType.Struct)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.VARIANTARG")]
	public object varDefaultValue;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct TYPEATTR
{
	public Guid guid;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LCID")]
	public uint LCID;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwReserved;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.MEMBERID")]
	public int memidConstructor;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.MEMBERID")]
	public int memidDestructor;

	[MarshalAs(UnmanagedType.LPWStr)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")]
	public string lpstrSchema;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cbSizeInstance;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.TYPEKIND")]
	public TYPEKIND TYPEKIND;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort cFuncs;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort cVars;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort cImplTypes;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort cbSizeVft;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort cbAlignment;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort wTypeFlags;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort wMajorVerNum;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort wMinorVerNum;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.TYPEDESC")]
	public TYPEDESC tdescAlias;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.IDLDESC")]
	public IDLDESC idldescType;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct IDLDESC
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")]
	public uint dwReserved;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.USHORT")]
	public ushort wIDLFlags;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct DISPPARAMS
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.VARIANTARG")]
	[ComConversionLoss]
	public IntPtr rgvarg;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DISPID")]
	[ComConversionLoss]
	public IntPtr rgdispidNamedArgs;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")]
	public uint cArgs;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")]
	public uint cNamedArgs;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct CUSTDATAITEM
{
	public Guid guid;

	[MarshalAs(UnmanagedType.Struct)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.VARIANTARG")]
	public object varValue;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CUSTDATA
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint cCustData;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCUSTDATAITEM")]
	[ComConversionLoss]
	public IntPtr prgCustData;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct TLIBATTR
{
	public Guid guid;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LCID")]
	public uint LCID;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.SYSKIND")]
	public SYSKIND SYSKIND;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort wMajorVerNum;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort wMinorVerNum;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort wLibFlags;
}
public enum EXTCONN
{
	EXTCONN_STRONG = 1,
	EXTCONN_WEAK = 2,
	EXTCONN_CALLABLE = 4
}
[Flags]
public enum BIND_FLAGS
{
	BIND_MAYBOTHERUSER = 1,
	BIND_JUSTTESTEXISTENCE = 2
}
public enum MKSYS
{
	MKSYS_NONE = 0,
	MKSYS_GENERICCOMPOSITE = 1,
	MKSYS_FILEMONIKER = 2,
	MKSYS_ANTIMONIKER = 3,
	MKSYS_ITEMMONIKER = 4,
	MKSYS_POINTERMONIKER = 5,
	MKSYS_CLASSMONIKER = 7,
	MKSYS_OBJREFMONIKER = 8,
	MKSYS_SESSIONMONIKER = 9
}
public enum MKRREDUCE
{
	MKRREDUCE_ONE = 196608,
	MKRREDUCE_TOUSER = 131072,
	MKRREDUCE_THROUGHUSER = 65536,
	MKRREDUCE_ALL = 0
}
public enum STGTY
{
	STGTY_STORAGE = 1,
	STGTY_STREAM,
	STGTY_LOCKBYTES,
	STGTY_PROPERTY
}
public enum STREAM_SEEK
{
	STREAM_SEEK_SET,
	STREAM_SEEK_CUR,
	STREAM_SEEK_END
}
public enum LOCKTYPE
{
	LOCK_WRITE = 1,
	LOCK_EXCLUSIVE = 2,
	LOCK_ONLYONCE = 4
}
public enum ADVF
{
	ADVF_NODATA = 1,
	ADVF_PRIMEFIRST = 2,
	ADVF_ONLYONCE = 4,
	ADVF_DATAONSTOP = 64,
	ADVFCACHE_NOHANDLER = 8,
	ADVFCACHE_FORCEBUILTIN = 16,
	ADVFCACHE_ONSAVE = 32
}
public enum TYMED
{
	TYMED_HGLOBAL = 1,
	TYMED_FILE = 2,
	TYMED_ISTREAM = 4,
	TYMED_ISTORAGE = 8,
	TYMED_GDI = 16,
	TYMED_MFPICT = 32,
	TYMED_ENHMF = 64,
	TYMED_NULL = 0
}
public enum DATADIR
{
	DATADIR_GET = 1,
	DATADIR_SET
}
public enum CALLTYPE
{
	CALLTYPE_TOPLEVEL = 1,
	CALLTYPE_NESTED,
	CALLTYPE_ASYNC,
	CALLTYPE_TOPLEVEL_CALLPENDING,
	CALLTYPE_ASYNC_CALLPENDING
}
public enum SERVERCALL
{
	SERVERCALL_ISHANDLED,
	SERVERCALL_REJECTED,
	SERVERCALL_RETRYLATER
}
public enum PENDINGTYPE
{
	PENDINGTYPE_TOPLEVEL = 1,
	PENDINGTYPE_NESTED
}
public enum PENDINGMSG
{
	PENDINGMSG_CANCELCALL,
	PENDINGMSG_WAITNOPROCESS,
	PENDINGMSG_WAITDEFPROCESS
}
public enum EOLE_AUTHENTICATION_CAPABILITIES
{
	EOAC_NONE = 0,
	EOAC_MUTUAL_AUTH = 1,
	EOAC_STATIC_CLOAKING = 32,
	EOAC_DYNAMIC_CLOAKING = 64,
	EOAC_ANY_AUTHORITY = 128,
	EOAC_MAKE_FULLSIC = 256,
	EOAC_DEFAULT = 2048,
	EOAC_SECURE_REFS = 2,
	EOAC_ACCESS_CONTROL = 4,
	EOAC_APPID = 8,
	EOAC_DYNAMIC = 16,
	EOAC_REQUIRE_FULLSIC = 512,
	EOAC_AUTO_IMPERSONATE = 1024,
	EOAC_NO_CUSTOM_MARSHAL = 8192,
	EOAC_DISABLE_AAA = 4096
}
public enum DCOM_CALL_STATE
{
	DCOM_NONE,
	DCOM_CALL_COMPLETE,
	DCOM_CALL_CANCELED
}
public enum ApplicationType
{
	ServerApplication,
	LibraryApplication
}
public enum ShutdownType
{
	IdleShutdown,
	ForcedShutdown
}
public enum APTTYPE
{
	APTTYPE_CURRENT = -1,
	APTTYPE_STA,
	APTTYPE_MTA,
	APTTYPE_NA,
	APTTYPE_MAINSTA
}
public enum THDTYPE
{
	THDTYPE_BLOCKMESSAGES,
	THDTYPE_PROCESSMESSAGES
}
public enum GUIDKIND
{
	GUIDKIND_DEFAULT_SOURCE_DISP_IID = 1
}
public enum CTRLINFO
{
	CTRLINFO_EATS_RETURN = 1,
	CTRLINFO_EATS_ESCAPE
}
public enum XFORMCOORDS
{
	XFORMCOORDS_POSITION = 1,
	XFORMCOORDS_SIZE = 2,
	XFORMCOORDS_HIMETRICTOCONTAINER = 4,
	XFORMCOORDS_CONTAINERTOHIMETRIC = 8,
	XFORMCOORDS_EVENTCOMPAT = 0x10
}
public enum PROPPAGESTATUS
{
	PROPPAGESTATUS_DIRTY = 1,
	PROPPAGESTATUS_VALIDATE = 2,
	PROPPAGESTATUS_CLEAN = 4
}
public enum PICTUREATTRIBUTES
{
	PICTURE_SCALABLE = 1,
	PICTURE_TRANSPARENT
}
[Flags]
public enum UASFLAGS
{
	UAS_NORMAL = 0,
	UAS_BLOCKED = 1,
	UAS_NOPARENTENABLE = 2,
	UAS_MASK = 3
}
public enum READYSTATE
{
	READYSTATE_UNINITIALIZED,
	READYSTATE_LOADING,
	READYSTATE_LOADED,
	READYSTATE_INTERACTIVE,
	READYSTATE_COMPLETE
}
[Flags]
public enum ACTIVATEFLAGS
{
	ACTIVATE_WINDOWLESS = 1
}
[Flags]
public enum OLEDCFLAGS
{
	OLEDC_NODRAW = 1,
	OLEDC_PAINTBKGND = 2,
	OLEDC_OFFSCREEN = 4
}
public enum VIEWSTATUS
{
	VIEWSTATUS_OPAQUE = 1,
	VIEWSTATUS_SOLIDBKGND = 2,
	VIEWSTATUS_DVASPECTOPAQUE = 4,
	VIEWSTATUS_DVASPECTTRANSPARENT = 8,
	VIEWSTATUS_SURFACE = 0x10,
	VIEWSTATUS_3DSURFACE = 0x20
}
public enum HITRESULT
{
	HITRESULT_OUTSIDE,
	HITRESULT_TRANSPARENT,
	HITRESULT_CLOSE,
	HITRESULT_HIT
}
public enum DVASPECT2
{
	DVASPECT_OPAQUE = 0x10,
	DVASPECT_TRANSPARENT = 0x20
}
public enum DVEXTENTMODE
{
	DVEXTENT_CONTENT,
	DVEXTENT_INTEGRAL
}
[Flags]
public enum DVASPECTINFOFLAG
{
	DVASPECTINFOFLAG_CANOPTIMIZE = 1
}
public enum POINTERINACTIVE
{
	POINTERINACTIVE_ACTIVATEONENTRY = 1,
	POINTERINACTIVE_DEACTIVATEONLEAVE = 2,
	POINTERINACTIVE_ACTIVATEONDRAG = 4
}
public enum PROPBAG2_TYPE
{
	PROPBAG2_TYPE_UNDEFINED,
	PROPBAG2_TYPE_DATA,
	PROPBAG2_TYPE_URL,
	PROPBAG2_TYPE_OBJECT,
	PROPBAG2_TYPE_STREAM,
	PROPBAG2_TYPE_STORAGE,
	PROPBAG2_TYPE_MONIKER
}
[Flags]
public enum QACONTAINERFLAGS
{
	QACONTAINER_SHOWHATCHING = 1,
	QACONTAINER_SHOWGRABHANDLES = 2,
	QACONTAINER_USERMODE = 4,
	QACONTAINER_DISPLAYASDEFAULT = 8,
	QACONTAINER_UIDEAD = 0x10,
	QACONTAINER_AUTOCLIP = 0x20,
	QACONTAINER_MESSAGEREFLECT = 0x40,
	QACONTAINER_SUPPORTSMNEMONICS = 0x80
}
public enum OLEGETMONIKER
{
	OLEGETMONIKER_ONLYIFTHERE = 1,
	OLEGETMONIKER_FORCEASSIGN,
	OLEGETMONIKER_UNASSIGN,
	OLEGETMONIKER_TEMPFORUSER
}
public enum OLEWHICHMK
{
	OLEWHICHMK_CONTAINER = 1,
	OLEWHICHMK_OBJREL,
	OLEWHICHMK_OBJFULL
}
public enum USERCLASSTYPE
{
	USERCLASSTYPE_FULL = 1,
	USERCLASSTYPE_SHORT,
	USERCLASSTYPE_APPNAME
}
public enum OLEMISC
{
	OLEMISC_RECOMPOSEONRESIZE = 1,
	OLEMISC_ONLYICONIC = 2,
	OLEMISC_INSERTNOTREPLACE = 4,
	OLEMISC_STATIC = 8,
	OLEMISC_CANTLINKINSIDE = 0x10,
	OLEMISC_CANLINKBYOLE1 = 0x20,
	OLEMISC_ISLINKOBJECT = 0x40,
	OLEMISC_INSIDEOUT = 0x80,
	OLEMISC_ACTIVATEWHENVISIBLE = 0x100,
	OLEMISC_RENDERINGISDEVICEINDEPENDENT = 0x200,
	OLEMISC_INVISIBLEATRUNTIME = 0x400,
	OLEMISC_ALWAYSRUN = 0x800,
	OLEMISC_ACTSLIKEBUTTON = 0x1000,
	OLEMISC_ACTSLIKELABEL = 0x2000,
	OLEMISC_NOUIACTIVATE = 0x4000,
	OLEMISC_ALIGNABLE = 0x8000,
	OLEMISC_SIMPLEFRAME = 0x10000,
	OLEMISC_SETCLIENTSITEFIRST = 0x20000,
	OLEMISC_IMEMODE = 0x40000,
	OLEMISC_IGNOREACTIVATEWHENVISIBLE = 0x80000,
	OLEMISC_WANTSTOMENUMERGE = 0x100000,
	OLEMISC_SUPPORTSMULTILEVELUNDO = 0x200000
}
public enum OLECLOSE
{
	OLECLOSE_SAVEIFDIRTY,
	OLECLOSE_NOSAVE,
	OLECLOSE_PROMPTSAVE
}
public enum OLERENDER
{
	OLERENDER_NONE,
	OLERENDER_DRAW,
	OLERENDER_FORMAT,
	OLERENDER_ASIS
}
public enum OLEUPDATE
{
	OLEUPDATE_ALWAYS = 1,
	OLEUPDATE_ONCALL = 3
}
public enum OLELINKBIND
{
	OLELINKBIND_EVENIFCLASSDIFF = 1
}
public enum BINDSPEED
{
	BINDSPEED_INDEFINITE = 1,
	BINDSPEED_MODERATE,
	BINDSPEED_IMMEDIATE
}
public enum OLECONTF
{
	OLECONTF_EMBEDDINGS = 1,
	OLECONTF_LINKS = 2,
	OLECONTF_OTHERS = 4,
	OLECONTF_ONLYUSER = 8,
	OLECONTF_ONLYIFRUNNING = 0x10
}
public enum DISCARDCACHE
{
	DISCARDCACHE_SAVEIFDIRTY,
	DISCARDCACHE_NOSAVE
}
public enum OLEVERBATTRIB
{
	OLEVERBATTRIB_NEVERDIRTIES = 1,
	OLEVERBATTRIB_ONCONTAINERMENU
}
public enum MONIKERPROPERTY
{
	MIMETYPEPROP,
	USE_SRC_URL
}
public enum BINDVERB
{
	BINDVERB_GET,
	BINDVERB_POST,
	BINDVERB_PUT,
	BINDVERB_CUSTOM
}
public enum BINDINFOF
{
	BINDINFOF_URLENCODESTGMEDDATA = 1,
	BINDINFOF_URLENCODEDEXTRAINFO
}
public enum BINDF
{
	BINDF_ASYNCHRONOUS = 1,
	BINDF_ASYNCSTORAGE = 2,
	BINDF_NOPROGRESSIVERENDERING = 4,
	BINDF_OFFLINEOPERATION = 8,
	BINDF_GETNEWESTVERSION = 0x10,
	BINDF_NOWRITECACHE = 0x20,
	BINDF_NEEDFILE = 0x40,
	BINDF_PULLDATA = 0x80,
	BINDF_IGNORESECURITYPROBLEM = 0x100,
	BINDF_RESYNCHRONIZE = 0x200,
	BINDF_HYPERLINK = 0x400,
	BINDF_NO_UI = 0x800,
	BINDF_SILENTOPERATION = 0x1000,
	BINDF_PRAGMA_NO_CACHE = 0x2000,
	BINDF_GETCLASSOBJECT = 0x4000,
	BINDF_RESERVED_1 = 0x8000,
	BINDF_FREE_THREADED = 0x10000,
	BINDF_DIRECT_READ = 0x20000,
	BINDF_FORMS_SUBMIT = 0x40000,
	BINDF_GETFROMCACHE_IF_NET_FAIL = 0x80000,
	BINDF_FROMURLMON = 0x100000,
	BINDF_FWD_BACK = 0x200000,
	BINDF_PREFERDEFAULTHANDLER = 0x400000,
	BINDF_ENFORCERESTRICTED = 0x800000
}
public enum URL_ENCODING
{
	URL_ENCODING_NONE = 0,
	URL_ENCODING_ENABLE_UTF8 = 0x10000000,
	URL_ENCODING_DISABLE_UTF8 = 0x20000000
}
public enum BINDINFO_OPTIONS
{
	BINDINFO_OPTIONS_WININETFLAG = 0x10000,
	BINDINFO_OPTIONS_ENABLE_UTF8 = 0x20000,
	BINDINFO_OPTIONS_DISABLE_UTF8 = 0x40000,
	BINDINFO_OPTIONS_USE_IE_ENCODING = 0x80000,
	BINDINFO_OPTIONS_BINDTOOBJECT = 0x100000
}
public enum BSCF
{
	BSCF_FIRSTDATANOTIFICATION = 1,
	BSCF_INTERMEDIATEDATANOTIFICATION = 2,
	BSCF_LASTDATANOTIFICATION = 4,
	BSCF_DATAFULLYAVAILABLE = 8,
	BSCF_AVAILABLEDATASIZEUNKNOWN = 0x10
}
public enum BINDSTATUS
{
	BINDSTATUS_FINDINGRESOURCE = 1,
	BINDSTATUS_CONNECTING,
	BINDSTATUS_REDIRECTING,
	BINDSTATUS_BEGINDOWNLOADDATA,
	BINDSTATUS_DOWNLOADINGDATA,
	BINDSTATUS_ENDDOWNLOADDATA,
	BINDSTATUS_BEGINDOWNLOADCOMPONENTS,
	BINDSTATUS_INSTALLINGCOMPONENTS,
	BINDSTATUS_ENDDOWNLOADCOMPONENTS,
	BINDSTATUS_USINGCACHEDCOPY,
	BINDSTATUS_SENDINGREQUEST,
	BINDSTATUS_CLASSIDAVAILABLE,
	BINDSTATUS_MIMETYPEAVAILABLE,
	BINDSTATUS_CACHEFILENAMEAVAILABLE,
	BINDSTATUS_BEGINSYNCOPERATION,
	BINDSTATUS_ENDSYNCOPERATION,
	BINDSTATUS_BEGINUPLOADDATA,
	BINDSTATUS_UPLOADINGDATA,
	BINDSTATUS_ENDUPLOADDATA,
	BINDSTATUS_PROTOCOLCLASSID,
	BINDSTATUS_ENCODING,
	BINDSTATUS_VERIFIEDMIMETYPEAVAILABLE,
	BINDSTATUS_CLASSINSTALLLOCATION,
	BINDSTATUS_DECODING,
	BINDSTATUS_LOADINGMIMEHANDLER,
	BINDSTATUS_CONTENTDISPOSITIONATTACH,
	BINDSTATUS_FILTERREPORTMIMETYPE,
	BINDSTATUS_CLSIDCANINSTANTIATE,
	BINDSTATUS_IUNKNOWNAVAILABLE,
	BINDSTATUS_DIRECTBIND,
	BINDSTATUS_RAWMIMETYPE,
	BINDSTATUS_PROXYDETECTING,
	BINDSTATUS_ACCEPTRANGES,
	BINDSTATUS_COOKIE_SENT,
	BINDSTATUS_COMPACT_POLICY_RECEIVED,
	BINDSTATUS_COOKIE_SUPPRESSED,
	BINDSTATUS_COOKIE_STATE_UNKNOWN,
	BINDSTATUS_COOKIE_STATE_ACCEPT,
	BINDSTATUS_COOKIE_STATE_REJECT,
	BINDSTATUS_COOKIE_STATE_PROMPT,
	BINDSTATUS_COOKIE_STATE_LEASH,
	BINDSTATUS_COOKIE_STATE_DOWNGRADE,
	BINDSTATUS_POLICY_HREF,
	BINDSTATUS_P3P_HEADER,
	BINDSTATUS_SESSION_COOKIE_RECEIVED,
	BINDSTATUS_PERSISTENT_COOKIE_RECEIVED,
	BINDSTATUS_SESSION_COOKIES_ALLOWED
}
public enum CIP_STATUS
{
	CIP_DISK_FULL,
	CIP_ACCESS_DENIED,
	CIP_NEWER_VERSION_EXISTS,
	CIP_OLDER_VERSION_EXISTS,
	CIP_NAME_CONFLICT,
	CIP_TRUST_VERIFICATION_COMPONENT_MISSING,
	CIP_EXE_SELF_REGISTERATION_TIMEOUT,
	CIP_UNSAFE_TO_ABORT,
	CIP_NEED_REBOOT
}
public enum BINDSTRING
{
	BINDSTRING_HEADERS = 1,
	BINDSTRING_ACCEPT_MIMES,
	BINDSTRING_EXTRA_URL,
	BINDSTRING_LANGUAGE,
	BINDSTRING_USERNAME,
	BINDSTRING_PASSWORD,
	BINDSTRING_UA_PIXELS,
	BINDSTRING_UA_COLOR,
	BINDSTRING_OS,
	BINDSTRING_USER_AGENT,
	BINDSTRING_ACCEPT_ENCODINGS,
	BINDSTRING_POST_COOKIE,
	BINDSTRING_POST_DATA_MIME,
	BINDSTRING_URL,
	BINDSTRING_IID,
	BINDSTRING_FLAG_BIND_TO_OBJECT,
	BINDSTRING_PTR_BIND_CONTEXT
}
[Flags]
public enum PI_FLAGS
{
	PI_PARSE_URL = 1,
	PI_FILTER_MODE = 2,
	PI_FORCE_ASYNC = 4,
	PI_USE_WORKERTHREAD = 8,
	PI_MIMEVERIFICATION = 0x10,
	PI_CLSIDLOOKUP = 0x20,
	PI_DATAPROGRESS = 0x40,
	PI_SYNCHRONOUS = 0x80,
	PI_APARTMENTTHREADED = 0x100,
	PI_CLASSINSTALL = 0x200,
	PI_PASSONBINDCTX = 0x2000,
	PI_NOMIMEHANDLER = 0x8000,
	PI_LOADAPPDIRECT = 0x4000,
	PD_FORCE_SWITCH = 0x10000,
	PI_PREFERDEFAULTHANDLER = 0x20000
}
[Flags]
public enum OIBDG_FLAGS
{
	OIBDG_APARTMENTTHREADED = 0x100,
	OIBDG_DATAONLY = 0x1000
}
public enum PARSEACTION
{
	PARSE_CANONICALIZE = 1,
	PARSE_FRIENDLY,
	PARSE_SECURITY_URL,
	PARSE_ROOTDOCUMENT,
	PARSE_DOCUMENT,
	PARSE_ANCHOR,
	PARSE_ENCODE,
	PARSE_DECODE,
	PARSE_PATH_FROM_URL,
	PARSE_URL_FROM_PATH,
	PARSE_MIME,
	PARSE_SERVER,
	PARSE_SCHEMA,
	PARSE_SITE,
	PARSE_DOMAIN,
	PARSE_LOCATION,
	PARSE_SECURITY_DOMAIN,
	PARSE_ESCAPE,
	PARSE_UNESCAPE
}
public enum PSUACTION
{
	PSU_DEFAULT = 1,
	PSU_SECURITY_URL_ONLY
}
public enum QUERYOPTION
{
	QUERY_EXPIRATION_DATE = 1,
	QUERY_TIME_OF_LAST_CHANGE,
	QUERY_CONTENT_ENCODING,
	QUERY_CONTENT_TYPE,
	QUERY_REFRESH,
	QUERY_RECOMBINE,
	QUERY_CAN_NAVIGATE,
	QUERY_USES_NETWORK,
	QUERY_IS_CACHED,
	QUERY_IS_INSTALLEDENTRY,
	QUERY_IS_CACHED_OR_MAPPED,
	QUERY_USES_CACHE,
	QUERY_IS_SECURE,
	QUERY_IS_SAFE
}
public enum PUAF
{
	PUAF_DEFAULT = 0,
	PUAF_NOUI = 1,
	PUAF_ISFILE = 2,
	PUAF_WARN_IF_DENIED = 4,
	PUAF_FORCEUI_FOREGROUND = 8,
	PUAF_CHECK_TIFS = 0x10,
	PUAF_DONTCHECKBOXINDIALOG = 0x20,
	PUAF_TRUSTED = 0x40,
	PUAF_ACCEPT_WILDCARD_SCHEME = 0x80,
	PUAF_ENFORCERESTRICTED = 0x100
}
[Flags]
public enum SZM_FLAGS
{
	SZM_CREATE = 0,
	SZM_DELETE = 1
}
public enum URLZONE
{
	URLZONE_PREDEFINED_MIN = 0,
	URLZONE_LOCAL_MACHINE = 0,
	URLZONE_INTRANET = 1,
	URLZONE_TRUSTED = 2,
	URLZONE_INTERNET = 3,
	URLZONE_UNTRUSTED = 4,
	URLZONE_PREDEFINED_MAX = 999,
	URLZONE_USER_MIN = 1000,
	URLZONE_USER_MAX = 10000
}
public enum URLTEMPLATE
{
	URLTEMPLATE_CUSTOM = 0,
	URLTEMPLATE_PREDEFINED_MIN = 65536,
	URLTEMPLATE_LOW = 65536,
	URLTEMPLATE_MEDLOW = 66816,
	URLTEMPLATE_MEDIUM = 69632,
	URLTEMPLATE_HIGH = 73728,
	URLTEMPLATE_PREDEFINED_MAX = 131072
}
[Flags]
public enum ZAFLAGS
{
	ZAFLAGS_CUSTOM_EDIT = 1,
	ZAFLAGS_ADD_SITES = 2,
	ZAFLAGS_REQUIRE_VERIFICATION = 4,
	ZAFLAGS_INCLUDE_PROXY_OVERRIDE = 8,
	ZAFLAGS_INCLUDE_INTRANET_SITES = 0x10,
	ZAFLAGS_NO_UI = 0x20,
	ZAFLAGS_SUPPORTS_VERIFICATION = 0x40,
	ZAFLAGS_UNC_AS_INTRANET = 0x80
}
public enum URLZONEREG
{
	URLZONEREG_DEFAULT,
	URLZONEREG_HKLM,
	URLZONEREG_HKCU
}
public enum MEMCTX
{
	MEMCTX_TASK = 1,
	MEMCTX_SHARED = 2,
	MEMCTX_MACSYSTEM = 3,
	MEMCTX_UNKNOWN = -1,
	MEMCTX_SAME = -2
}
public enum CLSCTX
{
	CLSCTX_INPROC_SERVER = 1,
	CLSCTX_INPROC_HANDLER = 2,
	CLSCTX_LOCAL_SERVER = 4,
	CLSCTX_INPROC_SERVER16 = 8,
	CLSCTX_REMOTE_SERVER = 0x10,
	CLSCTX_INPROC_HANDLER16 = 0x20,
	CLSCTX_RESERVED1 = 0x40,
	CLSCTX_RESERVED2 = 0x80,
	CLSCTX_RESERVED3 = 0x100,
	CLSCTX_RESERVED4 = 0x200,
	CLSCTX_NO_CODE_DOWNLOAD = 0x400,
	CLSCTX_RESERVED5 = 0x800,
	CLSCTX_NO_CUSTOM_MARSHAL = 0x1000,
	CLSCTX_ENABLE_CODE_DOWNLOAD = 0x2000,
	CLSCTX_NO_FAILURE_LOG = 0x4000,
	CLSCTX_DISABLE_AAA = 0x8000,
	CLSCTX_ENABLE_AAA = 0x10000,
	CLSCTX_FROM_DEFAULT_CONTEXT = 0x20000
}
[Flags]
public enum MSHLFLAGS
{
	MSHLFLAGS_NORMAL = 0,
	MSHLFLAGS_TABLESTRONG = 1,
	MSHLFLAGS_TABLEWEAK = 2,
	MSHLFLAGS_NOPING = 4,
	MSHLFLAGS_RESERVED1 = 8,
	MSHLFLAGS_RESERVED2 = 0x10,
	MSHLFLAGS_RESERVED3 = 0x20,
	MSHLFLAGS_RESERVED4 = 0x40
}
public enum MSHCTX
{
	MSHCTX_LOCAL,
	MSHCTX_NOSHAREDMEM,
	MSHCTX_DIFFERENTMACHINE,
	MSHCTX_INPROC,
	MSHCTX_CROSSCTX
}
public enum DVASPECT
{
	DVASPECT_CONTENT = 1,
	DVASPECT_THUMBNAIL = 2,
	DVASPECT_ICON = 4,
	DVASPECT_DOCPRINT = 8
}
public enum STGC
{
	STGC_DEFAULT = 0,
	STGC_OVERWRITE = 1,
	STGC_ONLYIFCURRENT = 2,
	STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE = 4,
	STGC_CONSOLIDATE = 8
}
public enum STGMOVE
{
	STGMOVE_MOVE,
	STGMOVE_COPY,
	STGMOVE_SHALLOWCOPY
}
[Flags]
public enum STATFLAG
{
	STATFLAG_DEFAULT = 0,
	STATFLAG_NONAME = 1,
	STATFLAG_NOOPEN = 2
}
public enum TYSPEC
{
	TYSPEC_CLSID,
	TYSPEC_FILEEXT,
	TYSPEC_MIMETYPE,
	TYSPEC_FILENAME,
	TYSPEC_PROGID,
	TYSPEC_PACKAGENAME,
	TYSPEC_OBJECTID
}
[ComImport]
[InterfaceType(1)]
[ComConversionLoss]
[Guid("00000003-0000-0000-C000-000000000046")]
public interface IMarshal
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetUnmarshalClass([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In] IntPtr pv, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDestContext, [In] IntPtr pvDestContext, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint MSHLFLAGS, out Guid pCid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetMarshalSizeMax([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In] IntPtr pv, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDestContext, [In] IntPtr pvDestContext, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint MSHLFLAGS, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void MarshalInterface([In][MarshalAs(UnmanagedType.Interface)] IStream pstm, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In] IntPtr pv, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDestContext, [In] IntPtr pvDestContext, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint MSHLFLAGS);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void UnmarshalInterface([In][MarshalAs(UnmanagedType.Interface)] IStream pstm, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, out IntPtr ppv);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReleaseMarshalData([In][MarshalAs(UnmanagedType.Interface)] IStream pstm);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DisconnectObject([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved);
}
[ComImport]
[Guid("000001CF-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IMarshal2 : IMarshal
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetUnmarshalClass([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In] IntPtr pv, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDestContext, [In] IntPtr pvDestContext, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint MSHLFLAGS, out Guid pCid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetMarshalSizeMax([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In] IntPtr pv, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDestContext, [In] IntPtr pvDestContext, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint MSHLFLAGS, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void MarshalInterface([In][MarshalAs(UnmanagedType.Interface)] IStream pstm, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In] IntPtr pv, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDestContext, [In] IntPtr pvDestContext, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint MSHLFLAGS);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void UnmarshalInterface([In][MarshalAs(UnmanagedType.Interface)] IStream pstm, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, out IntPtr ppv);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void ReleaseMarshalData([In][MarshalAs(UnmanagedType.Interface)] IStream pstm);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void DisconnectObject([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved);
}
[ComImport]
[Guid("00000002-0000-0000-C000-000000000046")]
[InterfaceType(1)]
[ComConversionLoss]
public interface IMalloc
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	IntPtr Alloc([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint cb);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	IntPtr Realloc([In] IntPtr pv, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint cb);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Free([In] IntPtr pv);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")]
	uint GetSize([In] IntPtr pv);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int DidAlloc(IntPtr pv);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void HeapMinimize();
}
[ComImport]
[Guid("0000001D-0000-0000-C000-000000000046")]
[ComConversionLoss]
[InterfaceType(1)]
public interface IMallocSpy
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")]
	uint PreAlloc([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint cbRequest);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	IntPtr PostAlloc([In] IntPtr pActual);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	IntPtr PreFree([In] IntPtr pRequest, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSpyed);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void PostFree([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSpyed);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")]
	uint PreRealloc([In] IntPtr pRequest, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint cbRequest, out IntPtr ppNewRequest, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSpyed);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	IntPtr PostRealloc([In] IntPtr pActual, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSpyed);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	IntPtr PreGetSize([In] IntPtr pRequest, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSpyed);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")]
	uint PostGetSize([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint cbActual, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSpyed);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	IntPtr PreDidAlloc([In] IntPtr pRequest, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSpyed);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int PostDidAlloc([In] IntPtr pRequest, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSpyed, [In] int fActual);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void PreHeapMinimize();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void PostHeapMinimize();
}
[ComImport]
[Guid("00000018-0000-0000-C000-000000000046")]
[InterfaceType(1)]
[ComConversionLoss]
public interface IStdMarshalInfo
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetClassForHandler([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDestContext, [In] IntPtr pvDestContext, out Guid pClsid);
}
[ComImport]
[InterfaceType(1)]
[Guid("00000019-0000-0000-C000-000000000046")]
public interface IExternalConnection
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	uint AddConnection([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint EXTCONN, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint reserved);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	uint ReleaseConnection([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint EXTCONN, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint reserved, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fLastReleaseCloses);
}
[ComImport]
[InterfaceType(1)]
[Guid("00000020-0000-0000-C000-000000000046")]
public interface IMultiQI
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void QueryMultipleInterfaces([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cMQIs, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.MULTI_QI")][MarshalAs(UnmanagedType.LPArray)] MULTI_QI[] pMQIs);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct MULTI_QI
{
	[ComConversionLoss]
	public IntPtr pIID;

	[MarshalAs(UnmanagedType.IUnknown)]
	public object pItf;

	[MarshalAs(UnmanagedType.Error)]
	public int hr;
}
[ComImport]
[InterfaceType(1)]
[Guid("00000021-0000-0000-C000-000000000046")]
[ComConversionLoss]
public interface IInternalUnknown
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void QueryInternalInterface([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, out IntPtr ppv);
}
[ComImport]
[Guid("00000100-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IEnumUnknown
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.IUnknown)] object[] rgelt, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pceltFetched);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumUnknown ppEnum);
}
[ComImport]
[Guid("0000000E-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IBindCtx
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RegisterObjectBound([In][MarshalAs(UnmanagedType.IUnknown)] object punk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RevokeObjectBound([In][MarshalAs(UnmanagedType.IUnknown)] object punk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReleaseBoundObjects();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetBindOptions([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BIND_OPTS2")][MarshalAs(UnmanagedType.LPArray)] BIND_OPTS2[] pbindopts);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetBindOptions([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BIND_OPTS2")][MarshalAs(UnmanagedType.LPArray)] BIND_OPTS2[] pbindopts);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetRunningObjectTable([MarshalAs(UnmanagedType.Interface)] out IRunningObjectTable pprot);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RegisterObjectParam([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszKey, [In][MarshalAs(UnmanagedType.IUnknown)] object punk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetObjectParam([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszKey, [MarshalAs(UnmanagedType.IUnknown)] out object ppunk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumObjectParam([MarshalAs(UnmanagedType.Interface)] out IEnumString ppEnum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RevokeObjectParam([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszKey);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct BIND_OPTS2
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint cbStruct;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint grfFlags;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint grfMode;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwTickCountDeadline;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwTrackFlags;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwClassContext;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LCID")]
	public uint locale;

	[ComConversionLoss]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.COSERVERINFO")]
	public IntPtr pServerInfo;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct COSERVERINFO
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwReserved1;

	[MarshalAs(UnmanagedType.LPWStr)]
	public string pwszName;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.COAUTHINFO")]
	[ComConversionLoss]
	public IntPtr pAuthInfo;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwReserved2;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct COAUTHINFO
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwAuthnSvc;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwAuthzSvc;

	[MarshalAs(UnmanagedType.LPWStr)]
	public string pwszServerPrincName;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwAuthnLevel;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwImpersonationLevel;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.COAUTHIDENTITY")]
	[ComConversionLoss]
	public IntPtr pAuthIdentityData;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwCapabilities;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct COAUTHIDENTITY
{
	[ComConversionLoss]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.USHORT")]
	public IntPtr User;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint UserLength;

	[ComConversionLoss]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.USHORT")]
	public IntPtr Domain;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint DomainLength;

	[ComConversionLoss]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.USHORT")]
	public IntPtr Password;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint PasswordLength;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint Flags;
}
[ComImport]
[InterfaceType(1)]
[Guid("00000010-0000-0000-C000-000000000046")]
public interface IRunningObjectTable
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Register([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfFlags, [In][MarshalAs(UnmanagedType.IUnknown)] object punkObject, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkObjectName, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwRegister);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Revoke([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwRegister);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int IsRunning([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkObjectName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetObject([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkObjectName, [MarshalAs(UnmanagedType.IUnknown)] out object ppunkObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void NoteChangeTime([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwRegister, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FILETIME")][MarshalAs(UnmanagedType.LPArray)] FILETIME[] pFileTime);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetTimeOfLastChange([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkObjectName, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FILETIME")][MarshalAs(UnmanagedType.LPArray)] FILETIME[] pFileTime);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumRunning([MarshalAs(UnmanagedType.Interface)] out IEnumMoniker ppenumMoniker);
}
[ComImport]
[InterfaceType(1)]
[Guid("0000000F-0000-0000-C000-000000000046")]
public interface IMoniker : IPersistStream
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new int GetClassID(out Guid pClassID);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new int IsDirty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Load([In][MarshalAs(UnmanagedType.Interface)] IStream pstm);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Save([In][MarshalAs(UnmanagedType.Interface)] IStream pstm, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fClearDirty);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetSizeMax([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")][MarshalAs(UnmanagedType.LPArray)] ULARGE_INTEGER[] pcbSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void BindToObject([In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkToLeft, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riidResult, [MarshalAs(UnmanagedType.IUnknown)] out object ppvResult);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void BindToStorage([In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkToLeft, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [MarshalAs(UnmanagedType.IUnknown)] out object ppvObj);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reduce([In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReduceHowFar, [In][Out][MarshalAs(UnmanagedType.Interface)] ref IMoniker ppmkToLeft, [MarshalAs(UnmanagedType.Interface)] out IMoniker ppmkReduced);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ComposeWith([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkRight, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fOnlyIfNotGeneric, [MarshalAs(UnmanagedType.Interface)] out IMoniker ppmkComposite);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Enum([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fForward, [MarshalAs(UnmanagedType.Interface)] out IEnumMoniker ppenumMoniker);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsEqual([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkOtherMoniker);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Hash([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwHash);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int IsRunning([In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkToLeft, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkNewlyRunning);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetTimeOfLastChange([In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkToLeft, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FILETIME")][MarshalAs(UnmanagedType.LPArray)] FILETIME[] pFileTime);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Inverse([MarshalAs(UnmanagedType.Interface)] out IMoniker ppmk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CommonPrefixWith([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkOther, [MarshalAs(UnmanagedType.Interface)] out IMoniker ppmkPrefix);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RelativePathTo([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkOther, [MarshalAs(UnmanagedType.Interface)] out IMoniker ppmkRelPath);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDisplayName([In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkToLeft, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPWStr)] out string ppszDisplayName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ParseDisplayName([In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmkToLeft, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszDisplayName, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pchEaten, [MarshalAs(UnmanagedType.Interface)] out IMoniker ppmkOut);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsSystemMoniker([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwMksys);
}
[ComImport]
[InterfaceType(1)]
[Guid("00000109-0000-0000-C000-000000000046")]
public interface IPersistStream : IPersist
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new int GetClassID(out Guid pClassID);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int IsDirty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Load([In][MarshalAs(UnmanagedType.Interface)] IStream pstm);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Save([In][MarshalAs(UnmanagedType.Interface)] IStream pstm, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fClearDirty);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetSizeMax([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")][MarshalAs(UnmanagedType.LPArray)] ULARGE_INTEGER[] pcbSize);
}
[ComImport]
[InterfaceType(1)]
[Guid("0000010C-0000-0000-C000-000000000046")]
public interface IPersist
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int GetClassID(out Guid pClassID);
}
[ComImport]
[InterfaceType(1)]
[Guid("00000102-0000-0000-C000-000000000046")]
public interface IEnumMoniker
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.Interface, SizeParamIndex = 0)] IMoniker[] rgelt, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pceltFetched);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumMoniker ppEnum);
}
[ComImport]
[Guid("00000101-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IEnumString
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 0)] string[] rgelt, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pceltFetched);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumString ppEnum);
}
[ComImport]
[Guid("00000126-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IRunnableObject
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetRunningClass(out Guid lpClsid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Run([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPBINDCTX")][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int IsRunning();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void LockRunning([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fLock, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fLastUnlockCloses);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetContainedObject([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fContained);
}
[ComImport]
[Guid("F29F6BC0-5021-11CE-AA15-00006901293F")]
[InterfaceType(1)]
public interface IROTData
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetComparisonData([Out][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] byte[] pbData, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cbMax, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcbData);
}
[ComImport]
[InterfaceType(1)]
[Guid("0000010B-0000-0000-C000-000000000046")]
public interface IPersistFile : IPersist
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new int GetClassID(out Guid pClassID);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int IsDirty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Load([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszFileName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwMode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Save([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszFileName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fRemember);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SaveCompleted([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszFileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetCurFile([ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPWStr)] out string ppszFileName);
}
[ComImport]
[Guid("0000010A-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IPersistStorage : IPersist
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new int GetClassID(out Guid pClassID);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int IsDirty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void InitNew([In][MarshalAs(UnmanagedType.Interface)] IStorage pstg);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Load([In][MarshalAs(UnmanagedType.Interface)] IStorage pstg);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Save([In][MarshalAs(UnmanagedType.Interface)] IStorage pStgSave, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSameAsLoad);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SaveCompleted([In][MarshalAs(UnmanagedType.Interface)] IStorage pStgNew);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void HandsOffStorage();
}
[ComImport]
[Guid("0000000A-0000-0000-C000-000000000046")]
[InterfaceType(1)]
[ComConversionLoss]
public interface ILockBytes
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReadAt([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")] ULARGE_INTEGER ulOffset, [Out][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] byte[] pv, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cb, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcbRead);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void WriteAt([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")] ULARGE_INTEGER ulOffset, [In][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] byte[] pv, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cb, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcbWritten);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Flush();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetSize([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")] ULARGE_INTEGER cb);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void LockRegion([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")] ULARGE_INTEGER libOffset, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")] ULARGE_INTEGER cb, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwLockType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void UnlockRegion([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")] ULARGE_INTEGER libOffset, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")] ULARGE_INTEGER cb, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwLockType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Stat([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.STATSTG")][MarshalAs(UnmanagedType.LPArray)] STATSTG[] pstatstg, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfStatFlag);
}
[ComImport]
[Guid("00000103-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IEnumFORMATETC
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FORMATETC")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] FORMATETC[] rgelt, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray)] uint[] pceltFetched);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumFORMATETC ppEnum);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct FORMATETC
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.CLIPFORMAT")]
	public ushort cfFormat;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DVTARGETDEVICE")]
	[ComConversionLoss]
	public IntPtr ptd;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwAspect;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int lindex;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint tymed;
}
[ComImport]
[InterfaceType(1)]
[Guid("00000105-0000-0000-C000-000000000046")]
public interface IEnumSTATDATA
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.STATDATA")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] STATDATA[] rgelt, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pceltFetched);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumSTATDATA ppEnum);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct STATDATA
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.FORMATETC")]
	public FORMATETC FORMATETC;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint ADVF;

	[MarshalAs(UnmanagedType.Interface)]
	public IAdviseSink pAdvSink;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwConnection;
}
[ComImport]
[Guid("0000010F-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IAdviseSink
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnDataChange([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FORMATETC")][MarshalAs(UnmanagedType.LPArray)] FORMATETC[] pFormatetc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ASYNC_STGMEDIUM")][MarshalAs(UnmanagedType.LPArray)] STGMEDIUM[] pStgmed);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnViewChange([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lindex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnRename([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnSave();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnClose();
}
[ComImport]
[InterfaceType(1)]
[Guid("00000012-0000-0000-C000-000000000046")]
public interface IRootStorage
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SwitchToFile([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszFile);
}
[ComImport]
[InterfaceType(1)]
[Guid("00000125-0000-0000-C000-000000000046")]
public interface IAdviseSink2 : IAdviseSink
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnDataChange([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FORMATETC")][MarshalAs(UnmanagedType.LPArray)] FORMATETC[] pFormatetc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ASYNC_STGMEDIUM")][MarshalAs(UnmanagedType.LPArray)] STGMEDIUM[] pStgmed);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnViewChange([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lindex);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnRename([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmk);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnSave();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnClose();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnLinkSrcChange([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmk);
}
[ComImport]
[InterfaceType(1)]
[Guid("0000010E-0000-0000-C000-000000000046")]
public interface IDataObject
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetData([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FORMATETC")][MarshalAs(UnmanagedType.LPArray)] FORMATETC[] pformatetcIn, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.STGMEDIUM")][MarshalAs(UnmanagedType.LPArray)] STGMEDIUM[] pRemoteMedium);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDataHere([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FORMATETC")][MarshalAs(UnmanagedType.LPArray)] FORMATETC[] pFormatetc, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.STGMEDIUM")][MarshalAs(UnmanagedType.LPArray)] STGMEDIUM[] pRemoteMedium);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int QueryGetData([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FORMATETC")][MarshalAs(UnmanagedType.LPArray)] FORMATETC[] pFormatetc);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int GetCanonicalFormatEtc([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FORMATETC")][MarshalAs(UnmanagedType.LPArray)] FORMATETC[] pformatectIn, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FORMATETC")][MarshalAs(UnmanagedType.LPArray)] FORMATETC[] pformatetcOut);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetData([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FORMATETC")][MarshalAs(UnmanagedType.LPArray)] FORMATETC[] pFormatetc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FLAG_STGMEDIUM")][MarshalAs(UnmanagedType.LPArray)] STGMEDIUM[] pmedium, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fRelease);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int EnumFormatEtc([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDirection, [MarshalAs(UnmanagedType.Interface)] out IEnumFORMATETC ppenumFormatEtc);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int DAdvise([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FORMATETC")][MarshalAs(UnmanagedType.LPArray)] FORMATETC[] pFormatetc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint ADVF, [In][MarshalAs(UnmanagedType.Interface)] IAdviseSink pAdvSink, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwConnection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DUnadvise([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwConnection);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int EnumDAdvise([MarshalAs(UnmanagedType.Interface)] out IEnumSTATDATA ppenumAdvise);
}
[ComImport]
[InterfaceType(1)]
[Guid("00000110-0000-0000-C000-000000000046")]
public interface IDataAdviseHolder
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Advise([In][MarshalAs(UnmanagedType.Interface)] IDataObject pDataObject, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FORMATETC")][MarshalAs(UnmanagedType.LPArray)] FORMATETC[] pFetc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint ADVF, [In][MarshalAs(UnmanagedType.Interface)] IAdviseSink pAdvise, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwConnection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Unadvise([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwConnection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumAdvise([MarshalAs(UnmanagedType.Interface)] out IEnumSTATDATA ppenumAdvise);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SendOnDataChange([In][MarshalAs(UnmanagedType.Interface)] IDataObject pDataObject, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint ADVF);
}
[ComImport]
[ComConversionLoss]
[Guid("00000016-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IMessageFilter
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	uint HandleInComingCall([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwCallType, [In] IntPtr htaskCaller, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwTickCount, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.INTERFACEINFO")][MarshalAs(UnmanagedType.LPArray)] INTERFACEINFO[] lpInterfaceInfo);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	uint RetryRejectedCall([In] IntPtr htaskCallee, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwTickCount, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwRejectType);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	uint MessagePending([In] IntPtr htaskCallee, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwTickCount, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwPendingType);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct INTERFACEINFO
{
	[MarshalAs(UnmanagedType.IUnknown)]
	public object punk;

	public Guid iid;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort wMethod;
}
[ComImport]
[InterfaceType(1)]
[ComConversionLoss]
[Guid("D5F56B60-593B-101A-B569-08002B2DBF7A")]
public interface IRpcChannelBuffer
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetBuffer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMessage, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SendReceive([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMessage, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pStatus);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FreeBuffer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMessage);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDestCtx([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwDestContext, out IntPtr ppvDestContext);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsConnected();
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct RPCOLEMESSAGE
{
	[ComConversionLoss]
	public IntPtr reserved1;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEDATAREP")]
	public uint dataRepresentation;

	[ComConversionLoss]
	public IntPtr Buffer;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cbBuffer;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint iMethod;

	[MarshalAs(UnmanagedType.ByValArray, SizeConst = 5)]
	[ComConversionLoss]
	public IntPtr[] reserved2;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint rpcFlags;
}
[ComImport]
[Guid("594F31D0-7F19-11D0-B194-00A0C90DC8BF")]
[InterfaceType(1)]
public interface IRpcChannelBuffer2 : IRpcChannelBuffer
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetBuffer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMessage, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void SendReceive([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMessage, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pStatus);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void FreeBuffer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMessage);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetDestCtx([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwDestContext, out IntPtr ppvDestContext);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void IsConnected();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetProtocolVersion([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] ref uint pdwVersion);
}
[ComImport]
[Guid("A5029FB6-3C34-11D1-9C99-00C04FB998AA")]
[ComConversionLoss]
[InterfaceType(1)]
public interface IAsyncRpcChannelBuffer : IRpcChannelBuffer2
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetBuffer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMessage, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void SendReceive([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMessage, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pStatus);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void FreeBuffer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMessage);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetDestCtx([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwDestContext, out IntPtr ppvDestContext);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void IsConnected();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetProtocolVersion([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] ref uint pdwVersion);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Send([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMsg, [In][MarshalAs(UnmanagedType.Interface)] ISynchronize pSync, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pulStatus);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Receive([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMsg, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pulStatus);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDestCtxEx([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMsg, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwDestContext, out IntPtr ppvDestContext);
}
[ComImport]
[Guid("00000030-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface ISynchronize
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Wait([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwMilliseconds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Signal();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Reset();
}
[ComImport]
[InterfaceType(1)]
[Guid("25B15600-0115-11D0-BF0D-00AA00B8DFD2")]
[ComConversionLoss]
public interface IRpcChannelBuffer3 : IRpcChannelBuffer2
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetBuffer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMessage, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void SendReceive([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMessage, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pStatus);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void FreeBuffer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMessage);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetDestCtx([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwDestContext, out IntPtr ppvDestContext);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void IsConnected();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetProtocolVersion([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] ref uint pdwVersion);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Send([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMsg, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pulStatus);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Receive([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMsg, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulSize, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pulStatus);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Cancel([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMsg);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetCallContext([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMsg, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, out IntPtr pInterface);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDestCtxEx([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMsg, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwDestContext, out IntPtr ppvDestContext);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetState([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMsg, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pState);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RegisterAsync([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMsg, [In][MarshalAs(UnmanagedType.Interface)] IAsyncManager pAsyncMgr);
}
[ComImport]
[Guid("0000002A-0000-0000-C000-000000000046")]
[InterfaceType(1)]
[ComConversionLoss]
public interface IAsyncManager
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CompleteCall([In][MarshalAs(UnmanagedType.Error)] int Result);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetCallContext([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, out IntPtr pInterface);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetState([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pulStateFlags);
}
[ComImport]
[InterfaceType(1)]
[Guid("58A08519-24C8-4935-B482-3FD823333A4F")]
public interface IRpcSyntaxNegotiate
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void NegotiateSyntax([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMsg);
}
[ComImport]
[Guid("D5F56A34-593B-101A-B569-08002B2DBF7A")]
[InterfaceType(1)]
public interface IRpcProxyBuffer
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Connect([In][MarshalAs(UnmanagedType.Interface)] IRpcChannelBuffer pRpcChannelBuffer);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Disconnect();
}
[ComImport]
[ComConversionLoss]
[Guid("D5F56AFC-593B-101A-B569-08002B2DBF7A")]
[InterfaceType(1)]
public interface IRpcStubBuffer
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Connect([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkServer);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Disconnect();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Invoke([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] _prpcmsg, [In][MarshalAs(UnmanagedType.Interface)] IRpcChannelBuffer _pRpcChannelBuffer);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	IRpcStubBuffer IsIIDSupported([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	uint CountRefs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DebugServerQueryInterface(ref IntPtr ppv);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DebugServerRelease(IntPtr pv);
}
[ComImport]
[ComConversionLoss]
[Guid("D5F569D0-593B-101A-B569-08002B2DBF7A")]
[InterfaceType(1)]
public interface IPSFactoryBuffer
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CreateProxy([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkOuter, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [MarshalAs(UnmanagedType.Interface)] out IRpcProxyBuffer ppProxy, out IntPtr ppv);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CreateStub([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In][MarshalAs(UnmanagedType.IUnknown)] object pUnkServer, [MarshalAs(UnmanagedType.Interface)] out IRpcStubBuffer ppStub);
}
[ComImport]
[Guid("1008C4A0-7613-11CF-9AF1-0020AF6E72F4")]
[InterfaceType(1)]
[ComConversionLoss]
public interface IChannelHook
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ClientGetSize([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid uExtent, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pDataSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ClientFillBuffer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid uExtent, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] ref uint pDataSize, [In] IntPtr pDataBuffer);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ClientNotify([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid uExtent, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cbDataSize, [In] IntPtr pDataBuffer, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint lDataRep, [In][MarshalAs(UnmanagedType.Error)] int hrFault);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ServerNotify([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid uExtent, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cbDataSize, [In] IntPtr pDataBuffer, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint lDataRep);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ServerGetSize([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid uExtent, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In][MarshalAs(UnmanagedType.Error)] int hrFault, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pDataSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ServerFillBuffer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid uExtent, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] ref uint pDataSize, [In] IntPtr pDataBuffer, [In][MarshalAs(UnmanagedType.Error)] int hrFault);
}
[ComImport]
[InterfaceType(1)]
[Guid("B196B284-BAB4-101A-B69C-00AA00341D07")]
public interface IConnectionPointContainer
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumConnectionPoints([MarshalAs(UnmanagedType.Interface)] out IEnumConnectionPoints ppEnum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FindConnectionPoint([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [MarshalAs(UnmanagedType.Interface)] out IConnectionPoint ppCP);
}
[ComImport]
[Guid("B196B285-BAB4-101A-B69C-00AA00341D07")]
[InterfaceType(1)]
public interface IEnumConnectionPoints
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cConnections, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCONNECTIONPOINT")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.Interface, SizeParamIndex = 0)] IConnectionPoint[] ppCP, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcFetched);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cConnections);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumConnectionPoints ppEnum);
}
[ComImport]
[Guid("B196B286-BAB4-101A-B69C-00AA00341D07")]
[InterfaceType(1)]
public interface IConnectionPoint
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetConnectionInterface(out Guid pIID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetConnectionPointContainer([MarshalAs(UnmanagedType.Interface)] out IConnectionPointContainer ppCPC);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Advise([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkSink, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwCookie);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Unadvise([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwCookie);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumConnections([MarshalAs(UnmanagedType.Interface)] out IEnumConnections ppEnum);
}
[ComImport]
[Guid("B196B287-BAB4-101A-B69C-00AA00341D07")]
[InterfaceType(1)]
public interface IEnumConnections
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cConnections, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.CONNECTDATA")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] CONNECTDATA[] rgcd, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcFetched);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cConnections);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumConnections ppEnum);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct CONNECTDATA
{
	[MarshalAs(UnmanagedType.IUnknown)]
	public object punk;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwCookie;
}
[ComImport]
[InterfaceType(1)]
[Guid("0000013D-0000-0000-C000-000000000046")]
[ComConversionLoss]
public interface IClientSecurity
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void QueryBlanket([In][MarshalAs(UnmanagedType.IUnknown)] object pProxy, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pAuthnSvc, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pAuthzSvc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECHAR")] IntPtr pServerPrincName, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pAuthnLevel, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pImpLevel, out IntPtr pAuthInfo, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pCapabilites);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetBlanket([In][MarshalAs(UnmanagedType.IUnknown)] object pProxy, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwAuthnSvc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwAuthzSvc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECHAR")][MarshalAs(UnmanagedType.LPWStr)] string pServerPrincName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwAuthnLevel, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwImpLevel, [In] IntPtr pAuthInfo, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwCapabilities);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CopyProxy([In][MarshalAs(UnmanagedType.IUnknown)] object pProxy, [MarshalAs(UnmanagedType.IUnknown)] out object ppCopy);
}
[ComImport]
[InterfaceType(1)]
[ComConversionLoss]
[Guid("0000013E-0000-0000-C000-000000000046")]
public interface IServerSecurity
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void QueryBlanket([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pAuthnSvc, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pAuthzSvc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECHAR")] IntPtr pServerPrincName, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pAuthnLevel, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pImpLevel, out IntPtr pPrivs, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] ref uint pCapabilities);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ImpersonateClient();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RevertToSelf();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int IsImpersonating();
}
[ComImport]
[Guid("00000140-0000-0000-C000-000000000046")]
[ComConversionLoss]
[InterfaceType(1)]
public interface IClassActivator
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetClassObject([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFCLSID")] ref Guid rclsid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwClassContext, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LCID")] uint locale, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, out IntPtr ppv);
}
[ComImport]
[Guid("00000144-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IRpcOptions
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Set([In][MarshalAs(UnmanagedType.IUnknown)] object pPrx, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwProperty, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint dwValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Query([In][MarshalAs(UnmanagedType.IUnknown)] object pPrx, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwProperty, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] out uint pdwValue);
}
[ComImport]
[InterfaceType(1)]
[Guid("99CAF010-415E-11CF-8814-00AA00B569F5")]
[ComConversionLoss]
public interface IFillLockBytes
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FillAppend([In][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] byte[] pv, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cb, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcbWritten);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FillAt([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")] ULARGE_INTEGER ulOffset, [In][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] byte[] pv, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cb, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcbWritten);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetFillSize([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")] ULARGE_INTEGER ulSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Terminate([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int bCanceled);
}
[ComImport]
[InterfaceType(1)]
[Guid("A9D758A0-4617-11CF-95FC-00AA00680DB4")]
public interface IProgressNotify
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnProgress([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwProgressCurrent, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwProgressMaximum, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fAccurate, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fOwner);
}
[ComImport]
[Guid("0E6D4D90-6738-11CF-9608-00AA00680DB4")]
[InterfaceType(1)]
public interface ILayoutStorage
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void LayoutScript([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.StorageLayout")][MarshalAs(UnmanagedType.LPArray)] StorageLayout[] pStorageLayout, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint nEntries, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint glfInterleavedFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void BeginMonitor();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EndMonitor();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReLayoutDocfile([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECHAR")][MarshalAs(UnmanagedType.LPWStr)] string pwcsNewDfName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReLayoutDocfileOnILockBytes([In][MarshalAs(UnmanagedType.Interface)] ILockBytes pILockBytes);
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
[ComConversionLoss]
public struct StorageLayout
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint LayoutType;

	[MarshalAs(UnmanagedType.LPWStr)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLECHAR")]
	[ComConversionLoss]
	public string pwcsElementName;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LARGE_INTEGER")]
	public LARGE_INTEGER cOffset;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LARGE_INTEGER")]
	public LARGE_INTEGER cBytes;
}
[ComImport]
[Guid("30F3D47A-6447-11D1-8E3C-00C04FB9386D")]
[InterfaceType(1)]
public interface IBlockingLock
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Lock([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwTimeout);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Unlock();
}
[ComImport]
[InterfaceType(1)]
[Guid("BC0BF6AE-8878-11D1-83E9-00C04FC2C6D4")]
public interface ITimeAndNoticeControl
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SuppressChanges([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint res1, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint res2);
}
[ComImport]
[Guid("8D19C834-8879-11D1-83E9-00C04FC2C6D4")]
[ComConversionLoss]
[InterfaceType(1)]
public interface IOplockStorage
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CreateStorageEx([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pwcsName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfMode, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint stgfmt, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfAttrs, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, out IntPtr ppstgOpen);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OpenStorageEx([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pwcsName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfMode, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint stgfmt, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfAttrs, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, out IntPtr ppstgOpen);
}
[ComImport]
[Guid("00000022-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface ISurrogate
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void LoadDllServer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFCLSID")] ref Guid clsid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FreeSurrogate();
}
[ComImport]
[ComConversionLoss]
[InterfaceType(1)]
[Guid("00000146-0000-0000-C000-000000000046")]
public interface IGlobalInterfaceTable
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RegisterInterfaceInGlobal([In][MarshalAs(UnmanagedType.IUnknown)] object punk, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwCookie);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RevokeInterfaceFromGlobal([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwCookie);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetInterfaceFromGlobal([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwCookie, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, out IntPtr ppv);
}
[ComImport]
[Guid("0E6D4D92-6738-11CF-9608-00AA00680DB4")]
[InterfaceType(1)]
public interface IDirectWriterLock
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int WaitForWriteAccess([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwTimeout);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReleaseWriteAccess();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int HaveWriteAccess();
}
[ComImport]
[InterfaceType(1)]
[Guid("00000031-0000-0000-C000-000000000046")]
[ComConversionLoss]
public interface ISynchronizeHandle
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetHandle(out IntPtr ph);
}
[ComImport]
[Guid("00000032-0000-0000-C000-000000000046")]
[ComConversionLoss]
[InterfaceType(1)]
public interface ISynchronizeEvent : ISynchronizeHandle
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetHandle(out IntPtr ph);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetEventHandle([In] IntPtr ph);
}
[ComImport]
[InterfaceType(1)]
[Guid("00000033-0000-0000-C000-000000000046")]
public interface ISynchronizeContainer
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddSynchronize([In][MarshalAs(UnmanagedType.Interface)] ISynchronize pSync);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void WaitMultiple([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwTimeout, [MarshalAs(UnmanagedType.Interface)] out ISynchronize ppSync);
}
[ComImport]
[Guid("00000025-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface ISynchronizeMutex : ISynchronize
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Wait([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwMilliseconds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Signal();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReleaseMutex();
}
[ComImport]
[InterfaceType(1)]
[Guid("00000029-0000-0000-C000-000000000046")]
public interface ICancelMethodCalls
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Cancel([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulSeconds);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int TestCancel();
}
[ComImport]
[Guid("1C733A30-2A1C-11CE-ADE5-00AA0044773D")]
[InterfaceType(1)]
public interface ICallFactory
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CreateCall([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In][MarshalAs(UnmanagedType.IUnknown)] object pCtrlUnk, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid2, [MarshalAs(UnmanagedType.IUnknown)] out object ppv);
}
[ComImport]
[ComConversionLoss]
[Guid("00000149-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IRpcHelper
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDCOMProtocolVersion([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pComVersion);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetIIDFromOBJREF([In] IntPtr pObjRef, out IntPtr pIID);
}
[ComImport]
[Guid("EB0CB9E8-7996-11D2-872E-0000F8080859")]
[InterfaceType(1)]
public interface IReleaseMarshalBuffers
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReleaseMarshalBuffer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RPCOLEMESSAGE")][MarshalAs(UnmanagedType.LPArray)] RPCOLEMESSAGE[] pMsg, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFlags, [In][MarshalAs(UnmanagedType.IUnknown)] object pChnl);
}
[ComImport]
[Guid("0000002B-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IWaitMultiple
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void WaitMultiple([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint timeout, [MarshalAs(UnmanagedType.Interface)] out ISynchronize pSync);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddSynchronize([In][MarshalAs(UnmanagedType.Interface)] ISynchronize pSync);
}
[ComImport]
[Guid("00000026-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IUrlMon
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AsyncGetClassBits([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFCLSID")] ref Guid rclsid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pszTYPE, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pszExt, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFileVersionMS, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFileVersionLS, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCodeBase, [In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwClassContext, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint Flags);
}
[ComImport]
[ComConversionLoss]
[InterfaceType(1)]
[Guid("00000145-0000-0000-C000-000000000046")]
public interface IForegroundTransfer
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AllowForegroundTransfer([In] IntPtr lpvReserved);
}
[ComImport]
[Guid("00000147-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IAddrTrackingControl
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnableCOMDynamicAddrTracking();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DisableCOMDynamicAddrTracking();
}
[ComImport]
[ComConversionLoss]
[Guid("00000148-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IAddrExclusionControl
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetCurrentAddrExclusionList([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, out IntPtr ppEnumerator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void UpdateAddrExclusionList([In][MarshalAs(UnmanagedType.IUnknown)] object pEnumerator);
}
[ComImport]
[Guid("969DC708-5C76-11D1-8D86-0000F804B057")]
[InterfaceType(1)]
[ComConversionLoss]
public interface IThumbnailExtractor
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ExtractThumbnail([In][MarshalAs(UnmanagedType.Interface)] IStorage pstg, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulLength, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulHeight, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pulOutputLength, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pulOutputHeight, out IntPtr phOutputBitmap);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnFileUpdated([In][MarshalAs(UnmanagedType.Interface)] IStorage pstg);
}
[ComImport]
[ComConversionLoss]
[InterfaceType(1)]
[Guid("947990DE-CC28-11D2-A0F7-00805F858FB1")]
public interface IDummyHICONIncluder
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Dummy([In] IntPtr h1, [In] IntPtr h2);
}
[ComImport]
[InterfaceType(1)]
[Guid("000001CE-0000-0000-C000-000000000046")]
public interface IComThreadingInfo
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetCurrentApartmentType([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.APTTYPE")][MarshalAs(UnmanagedType.LPArray)] APTTYPE[] pAptType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetCurrentThreadType([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.THDTYPE")][MarshalAs(UnmanagedType.LPArray)] THDTYPE[] pThreadType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetCurrentLogicalThreadId(out Guid pguidLogicalThreadId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetCurrentLogicalThreadId([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguid);
}
[ComImport]
[InterfaceType(1)]
[Guid("72380D55-8D2B-43A3-8513-2B6EF31434E9")]
public interface IProcessInitControl
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ResetInitializerTimeout([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwSecondsRemaining);
}
[ComImport]
[Guid("00000001-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IClassFactory
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CreateInstance([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [MarshalAs(UnmanagedType.IUnknown)] out object ppvObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void LockServer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fLock);
}
[ComImport]
[Guid("B196B28F-BAB4-101A-B69C-00AA00341D07")]
[InterfaceType(1)]
public interface IClassFactory2 : IClassFactory
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void CreateInstance([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [MarshalAs(UnmanagedType.IUnknown)] out object ppvObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void LockServer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fLock);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetLicInfo([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LICINFO")][MarshalAs(UnmanagedType.LPArray)] LICINFO[] pLicInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RequestLicKey([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved, [MarshalAs(UnmanagedType.BStr)] out string pBstrKey);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CreateInstanceLic([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In][MarshalAs(UnmanagedType.BStr)] string bstrKey, [MarshalAs(UnmanagedType.IUnknown)] out object ppvObj);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct LICINFO
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int cbLicInfo;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	public int fRuntimeKeyAvail;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	public int fLicVerified;
}
[ComImport]
[Guid("B196B283-BAB4-101A-B69C-00AA00341D07")]
[InterfaceType(1)]
public interface IProvideClassInfo
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetClassInfo([MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.TypeToTypeInfoMarshaler, CustomMarshalers, Version=1.0.5000.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")] out Type ppTI);
}
[ComImport]
[ComConversionLoss]
[Guid("00020401-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface ITypeInfo
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetTypeAttr([ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPTYPEATTR")] out IntPtr ppTypeAttr, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.CLEANLOCALSTORAGE")][MarshalAs(UnmanagedType.LPArray)] CLEANLOCALSTORAGE[] pDummy);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetTypeComp([MarshalAs(UnmanagedType.Interface)] out ITypeComp ppTComp);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetFuncDesc([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint index, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPFUNCDESC")] out IntPtr ppFuncDesc, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.CLEANLOCALSTORAGE")][MarshalAs(UnmanagedType.LPArray)] CLEANLOCALSTORAGE[] pDummy);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetVarDesc([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint index, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.VARDESC")] out IntPtr ppVarDesc, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.CLEANLOCALSTORAGE")][MarshalAs(UnmanagedType.LPArray)] CLEANLOCALSTORAGE[] pDummy);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetNames([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.MEMBERID")] int memid, [Out][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.BStr, SizeParamIndex = 2)] string[] rgBstrNames, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint cMaxNames, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] out uint pcNames);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetRefTypeOfImplType([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint index, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.HREFTYPE")] out uint pRefType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetImplTypeFlags([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint index, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.INT")] out int pImplTypeFlags);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetIDsOfNames();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Invoke();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDocumentation([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.MEMBERID")] int memid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint refPtrFlags, [MarshalAs(UnmanagedType.BStr)] out string pBstrName, [MarshalAs(UnmanagedType.BStr)] out string pBstrDocString, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwHelpContext, [MarshalAs(UnmanagedType.BStr)] out string pBstrHelpFile);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDllEntry([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.MEMBERID")] int memid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.INVOKEKIND")] INVOKEKIND invkind, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint refPtrFlags, [MarshalAs(UnmanagedType.BStr)] out string pBstrDllName, [MarshalAs(UnmanagedType.BStr)] out string pBstrName, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")] out ushort pwOrdinal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetRefTypeInfo([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.HREFTYPE")] uint HREFTYPE, [MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.TypeToTypeInfoMarshaler, CustomMarshalers, Version=1.0.5000.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")] out Type ppTInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddressOfMember();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CreateInstance([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [MarshalAs(UnmanagedType.IUnknown)] out object ppvObj);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetMops([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.MEMBERID")] int memid, [MarshalAs(UnmanagedType.BStr)] out string pBstrMops);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetContainingTypeLib([MarshalAs(UnmanagedType.Interface)] out ITypeLib ppTLib, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] out uint pIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReleaseTypeAttr();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReleaseFuncDesc();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReleaseVarDesc();
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CLEANLOCALSTORAGE
{
	[MarshalAs(UnmanagedType.IUnknown)]
	public object pInterface;

	[ComConversionLoss]
	public IntPtr pStorage;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint Flags;
}
[ComImport]
[Guid("00020403-0000-0000-C000-000000000046")]
[ComConversionLoss]
[InterfaceType(1)]
public interface ITypeComp
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Bind([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint lHashVal, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")] ushort wFlags, [MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.TypeToTypeInfoMarshaler, CustomMarshalers, Version=1.0.5000.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")] out Type ppTInfo, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DESCKIND")][MarshalAs(UnmanagedType.LPArray)] DESCKIND[] pDescKind, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPFUNCDESC")] out IntPtr ppFuncDesc, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.VARDESC")] out IntPtr ppVarDesc, [MarshalAs(UnmanagedType.Interface)] out ITypeComp ppTypeComp, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.CLEANLOCALSTORAGE")][MarshalAs(UnmanagedType.LPArray)] CLEANLOCALSTORAGE[] pDummy);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void BindType([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint lHashVal, [MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.TypeToTypeInfoMarshaler, CustomMarshalers, Version=1.0.5000.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")] out Type ppTInfo);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct VARDESC
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.MEMBERID")]
	public int memid;

	[MarshalAs(UnmanagedType.LPWStr)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")]
	public string lpstrSchema;

	public IntPtr unionmember;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ELEMDESC")]
	public ELEMDESC elemdescVar;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort wVarFlags;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.VARKIND")]
	public VARKIND VARKIND;
}
[ComImport]
[Guid("00020402-0000-0000-C000-000000000046")]
[ComConversionLoss]
[InterfaceType(1)]
public interface ITypeLib
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetTypeInfoCount([ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] out uint pcTInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetTypeInfo([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint index, [MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.TypeToTypeInfoMarshaler, CustomMarshalers, Version=1.0.5000.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")] out Type ppTInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetTypeInfoType([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint index, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.TYPEKIND")][MarshalAs(UnmanagedType.LPArray)] TYPEKIND[] pTKind);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetTypeInfoOfGuid([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guid, [MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.TypeToTypeInfoMarshaler, CustomMarshalers, Version=1.0.5000.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")] out Type ppTInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetLibAttr([ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPTLIBATTR")] out IntPtr ppTLibAttr, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.CLEANLOCALSTORAGE")][MarshalAs(UnmanagedType.LPArray)] CLEANLOCALSTORAGE[] pDummy);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetTypeComp([MarshalAs(UnmanagedType.Interface)] out ITypeComp ppTComp);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDocumentation([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.INT")] int index, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint refPtrFlags, [MarshalAs(UnmanagedType.BStr)] out string pBstrName, [MarshalAs(UnmanagedType.BStr)] out string pBstrDocString, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwHelpContext, [MarshalAs(UnmanagedType.BStr)] out string pBstrHelpFile);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsName([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szNameBuf, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint lHashVal, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfName, [MarshalAs(UnmanagedType.BStr)] out string pBstrLibName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FindName([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szNameBuf, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint lHashVal, [MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.TypeToTypeInfoMarshaler, CustomMarshalers, Version=1.0.5000.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")] out Type ppTInfo, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.MEMBERID")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 4)] int[] rgMemId, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.USHORT")] ref ushort pcFound, [MarshalAs(UnmanagedType.BStr)] out string pBstrLibName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReleaseTLibAttr();
}
[ComImport]
[Guid("A6BC3AC0-DBAA-11CE-9DE3-00AA004BB851")]
[InterfaceType(1)]
public interface IProvideClassInfo2 : IProvideClassInfo
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetClassInfo([MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.TypeToTypeInfoMarshaler, CustomMarshalers, Version=1.0.5000.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")] out Type ppTI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetGUID([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwGuidKind, out Guid pGUID);
}
[ComImport]
[Guid("A7ABA9C1-8983-11CF-8F20-00805F2CD064")]
[InterfaceType(1)]
public interface IProvideMultipleClassInfo : IProvideClassInfo2
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetClassInfo([MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.TypeToTypeInfoMarshaler, CustomMarshalers, Version=1.0.5000.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")] out Type ppTI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetGUID([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwGuidKind, out Guid pGUID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetMultiTypeInfoCount([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcti);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetInfoOfIndex([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint iti, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFlags, [MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.TypeToTypeInfoMarshaler, CustomMarshalers, Version=1.0.5000.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")] out Type pptiCoClass, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwTIFlags, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcdispidReserved, out Guid piidPrimary, out Guid piidSource);
}
[ComImport]
[InterfaceType(1)]
[Guid("B196B288-BAB4-101A-B69C-00AA00341D07")]
public interface IOleControl
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetControlInfo([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.CONTROLINFO")][MarshalAs(UnmanagedType.LPArray)] CONTROLINFO[] pCI);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnMnemonic([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.MSG")][MarshalAs(UnmanagedType.LPArray)] MSG[] pMsg);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnAmbientPropertyChange([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DISPID")] int DISPID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FreezeEvents([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int bFreeze);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CONTROLINFO
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cb;

	[ComConversionLoss]
	public IntPtr haccel;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.USHORT")]
	public ushort cAccel;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwFlags;
}
[ComImport]
[InterfaceType(1)]
[Guid("B196B289-BAB4-101A-B69C-00AA00341D07")]
public interface IOleControlSite
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnControlInfoChanged();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void LockInPlaceActive([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fLock);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetExtendedControl([MarshalAs(UnmanagedType.IDispatch)] out object ppDisp);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void TransformCoords([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.POINTL")][MarshalAs(UnmanagedType.LPArray)] POINTL[] pPtlHimetric, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.POINTF")][MarshalAs(UnmanagedType.LPArray)] POINTF[] pPtfContainer, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFlags);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int TranslateAccelerator([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.MSG")][MarshalAs(UnmanagedType.LPArray)] MSG[] pMsg, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfModifiers);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnFocus([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fGotFocus);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ShowPropertyFrame();
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct POINTL
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int x;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int y;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct POINTF
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.FLOAT")]
	public float x;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.FLOAT")]
	public float y;
}
[ComImport]
[ComConversionLoss]
[InterfaceType(1)]
[Guid("B196B28D-BAB4-101A-B69C-00AA00341D07")]
public interface IPropertyPage
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetPageSite([In][MarshalAs(UnmanagedType.Interface)] IPropertyPageSite pPageSite);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Activate([In] IntPtr hWndParent, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] pRect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int bModal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Deactivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPageInfo([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPPAGEINFO")][MarshalAs(UnmanagedType.LPArray)] PROPPAGEINFO[] pPageInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetObjects([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cObjects, [In][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.IUnknown, SizeParamIndex = 0)] object[] ppunk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Show([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint nCmdShow);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Move([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] pRect);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int IsPageDirty();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Apply();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Help([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszHelpDir);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int TranslateAccelerator([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.MSG")][MarshalAs(UnmanagedType.LPArray)] MSG[] pMsg);
}
[ComImport]
[InterfaceType(1)]
[Guid("B196B28C-BAB4-101A-B69C-00AA00341D07")]
public interface IPropertyPageSite
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnStatusChange([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFlags);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetLocaleID([ComAliasName("Microsoft.VisualStudio.OLE.Interop.LCID")] out uint pLocaleID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPageContainer([MarshalAs(UnmanagedType.IUnknown)] out object ppunk);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int TranslateAccelerator([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.MSG")][MarshalAs(UnmanagedType.LPArray)] MSG[] pMsg);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct PROPPAGEINFO
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cb;

	[MarshalAs(UnmanagedType.LPWStr)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")]
	public string pszTitle;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.SIZE")]
	public SIZE SIZE;

	[MarshalAs(UnmanagedType.LPWStr)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")]
	public string pszDocString;

	[MarshalAs(UnmanagedType.LPWStr)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")]
	public string pszHelpFile;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwHelpContext;
}
[ComImport]
[InterfaceType(1)]
[Guid("01E44665-24AC-101B-84ED-08002B2EC713")]
public interface IPropertyPage2 : IPropertyPage
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void SetPageSite([In][MarshalAs(UnmanagedType.Interface)] IPropertyPageSite pPageSite);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Activate([In] IntPtr hWndParent, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] pRect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int bModal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Deactivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetPageInfo([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPPAGEINFO")][MarshalAs(UnmanagedType.LPArray)] PROPPAGEINFO[] pPageInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void SetObjects([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cObjects, [In][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.IUnknown, SizeParamIndex = 0)] object[] ppunk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Show([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint nCmdShow);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Move([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] pRect);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new int IsPageDirty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Apply();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Help([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszHelpDir);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new int TranslateAccelerator([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.MSG")][MarshalAs(UnmanagedType.LPArray)] MSG[] pMsg);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EditProperty([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DISPID")] int DISPID);
}
[ComImport]
[Guid("9BFBBC02-EFF1-101A-84ED-00AA00341D07")]
[InterfaceType(1)]
public interface IPropertyNotifySink
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnChanged([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DISPID")] int DISPID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnRequestEdit([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DISPID")] int DISPID);
}
[ComImport]
[Guid("B196B28B-BAB4-101A-B69C-00AA00341D07")]
[InterfaceType(1)]
public interface ISpecifyPropertyPages
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPages([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.CAUUID")][MarshalAs(UnmanagedType.LPArray)] CAUUID[] pPages);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CAUUID
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	public IntPtr pElems;
}
[ComImport]
[InterfaceType(1)]
[Guid("BD1AE5E0-A6AE-11CE-BD37-504200C10000")]
public interface IPersistMemory : IPersist
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new int GetClassID(out Guid pClassID);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int IsDirty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Load([In][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] byte[] pMem, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cbSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Save([Out][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] byte[] pMem, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fClearDirty, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cbSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetSizeMax([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcbSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void InitNew();
}
[ComImport]
[Guid("7FD52380-4E07-101B-AE2D-08002B2EC713")]
[InterfaceType(1)]
public interface IPersistStreamInit : IPersist
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new int GetClassID(out Guid pClassID);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int IsDirty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Load([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPSTREAM")][MarshalAs(UnmanagedType.Interface)] IStream pstm);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Save([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPSTREAM")][MarshalAs(UnmanagedType.Interface)] IStream pstm, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fClearDirty);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetSizeMax([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")][MarshalAs(UnmanagedType.LPArray)] ULARGE_INTEGER[] pcbSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void InitNew();
}
[ComImport]
[Guid("37D84F60-42CB-11CE-8135-00AA004BB851")]
[InterfaceType(1)]
public interface IPersistPropertyBag : IPersist
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new int GetClassID(out Guid pClassID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void InitNew();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Load([In][MarshalAs(UnmanagedType.Interface)] IPropertyBag pPropBag, [In][MarshalAs(UnmanagedType.Interface)] IErrorLog pErrorLog);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Save([In][MarshalAs(UnmanagedType.Interface)] IPropertyBag pPropBag, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fClearDirty, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSaveAllProperties);
}
[ComImport]
[Guid("55272A00-42CB-11CE-8135-00AA004BB851")]
[InterfaceType(1)]
public interface IPropertyBag
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Read([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszPropName, [MarshalAs(UnmanagedType.Struct)] out object pVar, [In][MarshalAs(UnmanagedType.Interface)] IErrorLog pErrorLog, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint VARTYPE, [In][MarshalAs(UnmanagedType.IUnknown)] object pUnkObj);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Write([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszPropName, [In][MarshalAs(UnmanagedType.Struct)] ref object pVar);
}
[ComImport]
[InterfaceType(1)]
[Guid("3127CA40-446E-11CE-8135-00AA004BB851")]
public interface IErrorLog
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddError([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszPropName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.EXCEPINFO")][MarshalAs(UnmanagedType.LPArray)] EXCEPINFO[] pExcepInfo);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct EXCEPINFO
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort wCode;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort wReserved;

	[MarshalAs(UnmanagedType.BStr)]
	public string bstrSource;

	[MarshalAs(UnmanagedType.BStr)]
	public string bstrDescription;

	[MarshalAs(UnmanagedType.BStr)]
	public string bstrHelpFile;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwHelpContext;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")]
	public uint pvReserved;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")]
	public uint pfnDeferredFillIn;

	[MarshalAs(UnmanagedType.Error)]
	public int scode;
}
[ComImport]
[Guid("742B0E01-14E6-101B-914E-00AA00300CAB")]
[InterfaceType(1)]
[ComConversionLoss]
public interface ISimpleFrameSite
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int PreMessageFilter([In] IntPtr hwnd, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint MSG, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT_PTR")] uint wp, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG_PTR")] int lp, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG_PTR")] out int plResult, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwCookie);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int PostMessageFilter([In] IntPtr hwnd, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint MSG, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT_PTR")] uint wp, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG_PTR")] int lp, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG_PTR")] out int plResult, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwCookie);
}
[ComImport]
[InterfaceType(1)]
[Guid("00000113-0000-0000-C000-000000000046")]
public interface IOleInPlaceObject : IOleWindow
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetWindow(out IntPtr phwnd);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void ContextSensitiveHelp([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fEnterMode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void InPlaceDeactivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void UIDeactivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetObjectRects([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] lprcPosRect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] lprcClipRect);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReactivateAndUndo();
}
[ComImport]
[InterfaceType(1)]
[Guid("1C2056CC-5EF4-101B-8BC8-00AA003E3B29")]
public interface IOleInPlaceObjectWindowless : IOleInPlaceObject
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetWindow(out IntPtr phwnd);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void ContextSensitiveHelp([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fEnterMode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void InPlaceDeactivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void UIDeactivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void SetObjectRects([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] lprcPosRect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] lprcClipRect);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void ReactivateAndUndo();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int OnWindowMessage([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint MSG, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT_PTR")] IntPtr wParam, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG_PTR")] IntPtr lParam, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG_PTR")] out int plResult);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDropTarget([MarshalAs(UnmanagedType.Interface)] out IDropTarget ppDropTarget);
}
[ComImport]
[InterfaceType(1)]
[Guid("00000122-0000-0000-C000-000000000046")]
public interface IDropTarget
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DragEnter([In][MarshalAs(UnmanagedType.Interface)] IDataObject pDataObj, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfKeyState, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.POINTL")] POINTL pt, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] ref uint pdwEffect);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DragOver([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfKeyState, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.POINTL")] POINTL pt, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] ref uint pdwEffect);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DragLeave();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Drop([In][MarshalAs(UnmanagedType.Interface)] IDataObject pDataObj, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfKeyState, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.POINTL")] POINTL pt, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] ref uint pdwEffect);
}
[ComImport]
[Guid("9C2CAD80-3424-11CF-B670-00AA004CD6D8")]
[InterfaceType(1)]
public interface IOleInPlaceSiteEx : IOleInPlaceSite
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetWindow(out IntPtr phwnd);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void ContextSensitiveHelp([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fEnterMode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void CanInPlaceActivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnInPlaceActivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnUIActivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetWindowContext([MarshalAs(UnmanagedType.Interface)] out IOleInPlaceFrame ppFrame, [MarshalAs(UnmanagedType.Interface)] out IOleInPlaceUIWindow ppDoc, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] lprcPosRect, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] lprcClipRect, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLEINPLACEFRAMEINFO")][MarshalAs(UnmanagedType.LPArray)] OLEINPLACEFRAMEINFO[] lpFrameInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Scroll([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.SIZE")] SIZE scrollExtant);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnUIDeactivate([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fUndoable);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnInPlaceDeactivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void DiscardUndoState();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void DeactivateAndUndo();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnPosRectChange([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] lprcPosRect);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnInPlaceActivateEx([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfNoRedraw, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFlags);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnInPlaceDeactivateEx([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fNoRedraw);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int RequestUIActivate();
}
[ComImport]
[InterfaceType(1)]
[ComConversionLoss]
[Guid("922EADA0-3424-11CF-B670-00AA004CD6D8")]
public interface IOleInPlaceSiteWindowless : IOleInPlaceSiteEx
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetWindow(out IntPtr phwnd);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void ContextSensitiveHelp([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fEnterMode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void CanInPlaceActivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnInPlaceActivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnUIActivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetWindowContext([MarshalAs(UnmanagedType.Interface)] out IOleInPlaceFrame ppFrame, [MarshalAs(UnmanagedType.Interface)] out IOleInPlaceUIWindow ppDoc, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] lprcPosRect, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] lprcClipRect, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLEINPLACEFRAMEINFO")][MarshalAs(UnmanagedType.LPArray)] OLEINPLACEFRAMEINFO[] lpFrameInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Scroll([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.SIZE")] SIZE scrollExtant);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnUIDeactivate([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fUndoable);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnInPlaceDeactivate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void DiscardUndoState();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void DeactivateAndUndo();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnPosRectChange([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] lprcPosRect);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnInPlaceActivateEx([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfNoRedraw, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFlags);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnInPlaceDeactivateEx([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fNoRedraw);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void RequestUIActivate();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int CanWindowlessActivate();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int GetCapture();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int SetCapture([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fCapture);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int GetFocus();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int SetFocus([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fFocus);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDC([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] pRect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfFlags, out IntPtr phDC);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReleaseDC([In] IntPtr hDC);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void InvalidateRect([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] pRect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fErase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void InvalidateRgn([In] IntPtr hRGN, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fErase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ScrollRect([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.INT")] int dx, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.INT")] int dy, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] pRectScroll, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] pRectClip);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int AdjustRect([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] prc);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int OnDefWindowMessage([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint MSG, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT_PTR")] IntPtr wParam, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG_PTR")] IntPtr lParam, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG_PTR")] out int plResult);
}
[ComImport]
[ComConversionLoss]
[InterfaceType(1)]
[Guid("0000010D-0000-0000-C000-000000000046")]
public interface IViewObject
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Draw([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDrawAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lindex, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint pvAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DVTARGETDEVICE")][MarshalAs(UnmanagedType.LPArray)] DVTARGETDEVICE[] ptd, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint hdcTargetDev, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint hdcDraw, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECTL")][MarshalAs(UnmanagedType.LPArray)] RECTL[] lprcBounds, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECTL")][MarshalAs(UnmanagedType.LPArray)] RECTL[] lprcWBounds, [In][MarshalAs(UnmanagedType.Interface)] IContinue pContinue);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int GetColorSet([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDrawAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lindex, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint pvAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DVTARGETDEVICE")][MarshalAs(UnmanagedType.LPArray)] DVTARGETDEVICE[] ptd, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint hicTargetDev, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LOGPALETTE")] out IntPtr ppColorSet);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Freeze([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDrawAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lindex, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint pvAspect, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwFreeze);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Unfreeze([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFreeze);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetAdvise([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint aspects, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint ADVF, [In][MarshalAs(UnmanagedType.Interface)] IAdviseSink pAdvSink);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetAdvise([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pAspects, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pAdvf, [MarshalAs(UnmanagedType.Interface)] out IAdviseSink ppAdvSink);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct RECTL
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int left;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int top;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int right;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int bottom;
}
[ComImport]
[InterfaceType(1)]
[Guid("0000012A-0000-0000-C000-000000000046")]
public interface IContinue
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void FContinue();
}
[StructLayout(LayoutKind.Sequential, Pack = 2)]
[ComConversionLoss]
public struct LOGPALETTE
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort palVersion;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
	public ushort palNumEntries;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.PALETTEENTRY")]
	[ComConversionLoss]
	public IntPtr palPalEntry;
}
[StructLayout(LayoutKind.Sequential, Pack = 1)]
public struct PALETTEENTRY
{
	public byte peRed;

	public byte peGreen;

	public byte peBlue;

	public byte peFlags;
}
[ComImport]
[Guid("00000127-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IViewObject2 : IViewObject
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Draw([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDrawAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lindex, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint pvAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DVTARGETDEVICE")][MarshalAs(UnmanagedType.LPArray)] DVTARGETDEVICE[] ptd, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint hdcTargetDev, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint hdcDraw, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECTL")][MarshalAs(UnmanagedType.LPArray)] RECTL[] lprcBounds, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECTL")][MarshalAs(UnmanagedType.LPArray)] RECTL[] lprcWBounds, [In][MarshalAs(UnmanagedType.Interface)] IContinue pContinue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetColorSet([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDrawAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lindex, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint pvAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DVTARGETDEVICE")][MarshalAs(UnmanagedType.LPArray)] DVTARGETDEVICE[] ptd, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint hicTargetDev, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LOGPALETTE")] out IntPtr ppColorSet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Freeze([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDrawAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lindex, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint pvAspect, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwFreeze);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Unfreeze([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFreeze);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void SetAdvise([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint aspects, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint ADVF, [In][MarshalAs(UnmanagedType.Interface)] IAdviseSink pAdvSink);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetAdvise([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pAspects, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pAdvf, [MarshalAs(UnmanagedType.Interface)] out IAdviseSink ppAdvSink);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetExtent([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDrawAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lindex, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DVTARGETDEVICE")][MarshalAs(UnmanagedType.LPArray)] DVTARGETDEVICE[] ptd, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPSIZEL")][MarshalAs(UnmanagedType.LPArray)] SIZEL[] LPSIZEL);
}
[ComImport]
[ComConversionLoss]
[Guid("3AF24292-0C96-11CE-A0CF-00AA00600AB8")]
[InterfaceType(1)]
public interface IViewObjectEx : IViewObject2
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Draw([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDrawAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lindex, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint pvAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DVTARGETDEVICE")][MarshalAs(UnmanagedType.LPArray)] DVTARGETDEVICE[] ptd, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint hdcTargetDev, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint hdcDraw, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECTL")][MarshalAs(UnmanagedType.LPArray)] RECTL[] lprcBounds, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECTL")][MarshalAs(UnmanagedType.LPArray)] RECTL[] lprcWBounds, [In][MarshalAs(UnmanagedType.Interface)] IContinue pContinue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetColorSet([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDrawAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lindex, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint pvAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DVTARGETDEVICE")][MarshalAs(UnmanagedType.LPArray)] DVTARGETDEVICE[] ptd, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint hicTargetDev, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LOGPALETTE")] out IntPtr ppColorSet);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Freeze([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDrawAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lindex, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint pvAspect, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwFreeze);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Unfreeze([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFreeze);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void SetAdvise([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint aspects, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint ADVF, [In][MarshalAs(UnmanagedType.Interface)] IAdviseSink pAdvSink);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetAdvise([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pAspects, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pAdvf, [MarshalAs(UnmanagedType.Interface)] out IAdviseSink ppAdvSink);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetExtent([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDrawAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lindex, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DVTARGETDEVICE")][MarshalAs(UnmanagedType.LPArray)] DVTARGETDEVICE[] ptd, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPSIZEL")][MarshalAs(UnmanagedType.LPArray)] SIZEL[] LPSIZEL);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetRect([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwAspect, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RECTL")][MarshalAs(UnmanagedType.LPArray)] RECTL[] pRect);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetViewStatus([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwStatus);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void QueryHitPoint([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] pRectBounds, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.POINT")] POINT ptlLoc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lCloseHint, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pHitResult);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void QueryHitRect([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] pRectBounds, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] pRectLoc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lCloseHint, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pHitResult);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetNaturalExtent([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lindex, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DVTARGETDEVICE")][MarshalAs(UnmanagedType.LPArray)] DVTARGETDEVICE[] ptd, [In] IntPtr hicTargetDev, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DVEXTENTINFO")][MarshalAs(UnmanagedType.LPArray)] DVEXTENTINFO[] pExtentInfo, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPSIZEL")][MarshalAs(UnmanagedType.LPArray)] SIZEL[] pSizel);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct DVEXTENTINFO
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cb;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwExtentMode;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.SIZEL")]
	public SIZEL sizelProposed;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct SIZEL
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int cx;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int cy;
}
[ComImport]
[InterfaceType(1)]
[Guid("894AD3B0-EF97-11CE-9BC9-00AA00608E01")]
public interface IOleUndoUnit
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Do([In][MarshalAs(UnmanagedType.Interface)] IOleUndoManager pUndoManager);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDescription([MarshalAs(UnmanagedType.BStr)] out string pBstr);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetUnitType(out Guid pClsid, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] out int plID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnNextAdd();
}
[ComImport]
[Guid("D001F200-EF97-11CE-9BC9-00AA00608E01")]
[InterfaceType(1)]
public interface IOleUndoManager
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Open([In][MarshalAs(UnmanagedType.Interface)] IOleParentUndoUnit pPUU);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Close([In][MarshalAs(UnmanagedType.Interface)] IOleParentUndoUnit pPUU, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fCommit);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Add([In][MarshalAs(UnmanagedType.Interface)] IOleUndoUnit pUU);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int GetOpenParentState([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwState);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DiscardFrom([In][MarshalAs(UnmanagedType.Interface)] IOleUndoUnit pUU);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void UndoTo([In][MarshalAs(UnmanagedType.Interface)] IOleUndoUnit pUU);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RedoTo([In][MarshalAs(UnmanagedType.Interface)] IOleUndoUnit pUU);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumUndoable([MarshalAs(UnmanagedType.Interface)] out IEnumOleUndoUnits ppEnum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumRedoable([MarshalAs(UnmanagedType.Interface)] out IEnumOleUndoUnits ppEnum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetLastUndoDescription([MarshalAs(UnmanagedType.BStr)] out string pBstr);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetLastRedoDescription([MarshalAs(UnmanagedType.BStr)] out string pBstr);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Enable([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fEnable);
}
[ComImport]
[Guid("A1FAF330-EF97-11CE-9BC9-00AA00608E01")]
[InterfaceType(1)]
public interface IOleParentUndoUnit : IOleUndoUnit
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void Do([In][MarshalAs(UnmanagedType.Interface)] IOleUndoManager pUndoManager);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetDescription([MarshalAs(UnmanagedType.BStr)] out string pBstr);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetUnitType(out Guid pClsid, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] out int plID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnNextAdd();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Open([In][MarshalAs(UnmanagedType.Interface)] IOleParentUndoUnit pPUU);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Close([In][MarshalAs(UnmanagedType.Interface)] IOleParentUndoUnit pPUU, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fCommit);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Add([In][MarshalAs(UnmanagedType.Interface)] IOleUndoUnit pUU);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int FindUnit([In][MarshalAs(UnmanagedType.Interface)] IOleUndoUnit pUU);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetParentState([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwState);
}
[ComImport]
[InterfaceType(1)]
[Guid("B3E7C340-EF97-11CE-9BC9-00AA00608E01")]
public interface IEnumOleUndoUnits
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.Interface, SizeParamIndex = 0)] IOleUndoUnit[] rgelt, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pceltFetched);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumOleUndoUnits ppEnum);
}
[ComImport]
[InterfaceType(1)]
[Guid("55980BA0-35AA-11CF-B671-00AA004CD6D8")]
public interface IPointerInactive
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetActivationPolicy([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwPolicy);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnInactiveMouseMove([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] pRectBounds, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int x, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int y, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfKeyState);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int OnInactiveSetCursor([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] pRectBounds, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int x, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int y, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwMouseMsg, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSetAlways);
}
[ComImport]
[InterfaceType(1)]
[Guid("FC4801A3-2BA9-11CF-A229-00AA003D7352")]
[ComConversionLoss]
public interface IObjectWithSite
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetSite([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkSite);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetSite([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, out IntPtr ppvSite);
}
[ComImport]
[Guid("376BD3AA-3845-101B-84ED-08002B2EC713")]
[InterfaceType(1)]
public interface IPerPropertyBrowsing
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetDisplayString([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DISPID")] int DISPID, [MarshalAs(UnmanagedType.BStr)] out string pBstr);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void MapPropertyToPage([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DISPID")] int DISPID, out Guid pClsid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPredefinedStrings([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DISPID")] int DISPID, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.CALPOLESTR")][MarshalAs(UnmanagedType.LPArray)] CALPOLESTR[] pCaStringsOut, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.CADWORD")][MarshalAs(UnmanagedType.LPArray)] CADWORD[] pCaCookiesOut);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPredefinedValue([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DISPID")] int DISPID, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwCookie, [MarshalAs(UnmanagedType.Struct)] out object pVarOut);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CALPOLESTR
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")]
	[ComConversionLoss]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CADWORD
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	[ComConversionLoss]
	public IntPtr pElems;
}
[ComImport]
[InterfaceType(1)]
[Guid("22F55882-280B-11D0-A8A9-00A0C90C2004")]
public interface IPropertyBag2
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Read([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cProperties, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPBAG2")][MarshalAs(UnmanagedType.LPArray)] PROPBAG2[] pPropBag, [In][MarshalAs(UnmanagedType.Interface)] IErrorLog pErrLog, [MarshalAs(UnmanagedType.Struct)] out object pvarValue, [MarshalAs(UnmanagedType.Error)] out int phrError);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Write([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cProperties, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPBAG2")][MarshalAs(UnmanagedType.LPArray)] PROPBAG2[] pPropBag, [In][MarshalAs(UnmanagedType.Struct)] ref object pvarValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CountProperties([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcProperties);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPropertyInfo([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint iProperty, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cProperties, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPBAG2")][MarshalAs(UnmanagedType.LPArray)] PROPBAG2[] pPropBag, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcProperties);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void LoadObject([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pstrName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwHint, [In][MarshalAs(UnmanagedType.IUnknown)] object punkObject, [In][MarshalAs(UnmanagedType.Interface)] IErrorLog pErrLog);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct PROPBAG2
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwType;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.VARTYPE")]
	public ushort vt;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.CLIPFORMAT")]
	public ushort cfType;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwHint;

	[MarshalAs(UnmanagedType.LPWStr)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")]
	public string pstrName;

	public Guid clsid;
}
[ComImport]
[Guid("22F55881-280B-11D0-A8A9-00A0C90C2004")]
[InterfaceType(1)]
public interface IPersistPropertyBag2 : IPersist
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new int GetClassID(out Guid pClassID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void InitNew();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Load([In][MarshalAs(UnmanagedType.Interface)] IPropertyBag2 pPropBag, [In][MarshalAs(UnmanagedType.Interface)] IErrorLog pErrLog);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Save([In][MarshalAs(UnmanagedType.Interface)] IPropertyBag2 pPropBag, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fClearDirty, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSaveAllProperties);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int IsDirty();
}
[ComImport]
[Guid("3AF24290-0C96-11CE-A0CF-00AA00600AB8")]
[InterfaceType(1)]
public interface IAdviseSinkEx : IAdviseSink
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnDataChange([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FORMATETC")][MarshalAs(UnmanagedType.LPArray)] FORMATETC[] pFormatetc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ASYNC_STGMEDIUM")][MarshalAs(UnmanagedType.LPArray)] STGMEDIUM[] pStgmed);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnViewChange([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lindex);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnRename([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmk);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnSave();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void OnClose();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnViewStatusChange([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwViewStatus);
}
[ComImport]
[Guid("CF51ED10-62FE-11CF-BF86-00A0C9034836")]
[InterfaceType(1)]
public interface IQuickActivate
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void QuickActivate([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.QACONTAINER")][MarshalAs(UnmanagedType.LPArray)] QACONTAINER[] pQaContainer, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.QACONTROL")][MarshalAs(UnmanagedType.LPArray)] QACONTROL[] pQaControl);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetContentExtent([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPSIZEL")][MarshalAs(UnmanagedType.LPArray)] SIZEL[] pSizel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetContentExtent([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPSIZEL")][MarshalAs(UnmanagedType.LPArray)] SIZEL[] pSizel);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct QACONTAINER
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cbSize;

	[MarshalAs(UnmanagedType.Interface)]
	public IOleClientSite pClientSite;

	[MarshalAs(UnmanagedType.Interface)]
	public IAdviseSinkEx pAdviseSink;

	[MarshalAs(UnmanagedType.Interface)]
	public IPropertyNotifySink pPropertyNotifySink;

	[MarshalAs(UnmanagedType.IUnknown)]
	public object pUnkEventSink;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwAmbientFlags;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLE_COLOR")]
	public uint colorFore;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLE_COLOR")]
	public uint colorBack;

	[MarshalAs(UnmanagedType.Interface)]
	public IFont pFont;

	[MarshalAs(UnmanagedType.Interface)]
	public IOleUndoManager pUndoMgr;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwAppearance;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int LCID;

	[ComConversionLoss]
	public IntPtr hpal;

	[MarshalAs(UnmanagedType.Interface)]
	public IBindHost pBindHost;

	[MarshalAs(UnmanagedType.Interface)]
	public IOleControlSite pOleControlSite;

	[MarshalAs(UnmanagedType.Interface)]
	public IServiceProvider pServiceProvider;
}
[ComImport]
[Guid("00000118-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IOleClientSite
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SaveObject();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetMoniker([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwAssign, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwWhichMoniker, [MarshalAs(UnmanagedType.Interface)] out IMoniker ppmk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetContainer([MarshalAs(UnmanagedType.Interface)] out IOleContainer ppContainer);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ShowObject();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnShowWindow([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fShow);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RequestNewObjectLayout();
}
[ComImport]
[InterfaceType(1)]
[Guid("0000011B-0000-0000-C000-000000000046")]
public interface IOleContainer : IParseDisplayName
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void ParseDisplayName([In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszDisplayName, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pchEaten, [MarshalAs(UnmanagedType.Interface)] out IMoniker ppmkOut);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumObjects([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfFlags, [MarshalAs(UnmanagedType.Interface)] out IEnumUnknown ppEnum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void LockContainer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fLock);
}
[ComImport]
[Guid("0000011A-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IParseDisplayName
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ParseDisplayName([In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszDisplayName, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pchEaten, [MarshalAs(UnmanagedType.Interface)] out IMoniker ppmkOut);
}
[ComImport]
[ComConversionLoss]
[InterfaceType(1)]
[Guid("BEF6E002-A874-101A-8BBA-00AA00300CAB")]
public interface IFont
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void get_Name([MarshalAs(UnmanagedType.BStr)] out string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void put_Name([In][MarshalAs(UnmanagedType.BStr)] string name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void get_Size([Out][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.Currency)] decimal[] pSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void put_Size([In][MarshalAs(UnmanagedType.Currency)] decimal SIZE);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void get_Bold([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pBold);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int put_Bold([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int bold);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void get_Italic([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pItalic);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int put_Italic([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int italic);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void get_Underline([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pUnderline);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int put_Underline([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int underline);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void get_Strikethrough([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pStrikethrough);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int put_Strikethrough([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int strikethrough);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void get_Weight([ComAliasName("Microsoft.VisualStudio.OLE.Interop.SHORT")] out short pWeight);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int put_Weight([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.SHORT")] short weight);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void get_Charset([ComAliasName("Microsoft.VisualStudio.OLE.Interop.SHORT")] out short pCharset);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int put_Charset([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.SHORT")] short charset);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void get_hFont(out IntPtr phFont);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IFont ppFont);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsEqual([In][MarshalAs(UnmanagedType.Interface)] IFont pFontOther);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetRatio([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int cyLogical, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int cyHimetric);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void QueryTextMetrics([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.TEXTMETRICOLE")][MarshalAs(UnmanagedType.LPArray)] TEXTMETRICOLE[] pTM);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddRefHfont([In] IntPtr hFont);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int ReleaseHfont([In] IntPtr hFont);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetHdc([In] IntPtr hDC);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct TEXTMETRICOLE
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmHeight;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmAscent;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmDescent;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmInternalLeading;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmExternalLeading;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmAveCharWidth;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmMaxCharWidth;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmWeight;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmOverhang;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmDigitizedAspectX;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmDigitizedAspectY;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WCHAR")]
	public ushort tmFirstChar;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WCHAR")]
	public ushort tmLastChar;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WCHAR")]
	public ushort tmDefaultChar;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WCHAR")]
	public ushort tmBreakChar;

	public byte tmItalic;

	public byte tmUnderlined;

	public byte tmStruckOut;

	public byte tmPitchAndFamily;

	public byte tmCharSet;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct TEXTMETRICW
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmHeight;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmAscent;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmDescent;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmInternalLeading;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmExternalLeading;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmAveCharWidth;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmMaxCharWidth;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmWeight;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmOverhang;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmDigitizedAspectX;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int tmDigitizedAspectY;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WCHAR")]
	public ushort tmFirstChar;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WCHAR")]
	public ushort tmLastChar;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WCHAR")]
	public ushort tmDefaultChar;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WCHAR")]
	public ushort tmBreakChar;

	public byte tmItalic;

	public byte tmUnderlined;

	public byte tmStruckOut;

	public byte tmPitchAndFamily;

	public byte tmCharSet;
}
[ComImport]
[Guid("FC4801A1-2BA9-11CF-A229-00AA003D7352")]
[InterfaceType(1)]
public interface IBindHost
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void CreateMoniker([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szName, [In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [MarshalAs(UnmanagedType.Interface)] out IMoniker ppmk, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void MonikerBindToStorage([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmk, [In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][MarshalAs(UnmanagedType.Interface)] IBindStatusCallback pBSC, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [MarshalAs(UnmanagedType.IUnknown)] out object ppvObj);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void MonikerBindToObject([In][MarshalAs(UnmanagedType.Interface)] IMoniker pmk, [In][MarshalAs(UnmanagedType.Interface)] IBindCtx pbc, [In][MarshalAs(UnmanagedType.Interface)] IBindStatusCallback pBSC, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [MarshalAs(UnmanagedType.IUnknown)] out object ppvObj);
}
[ComImport]
[Guid("79EAC9C1-BAF9-11CE-8C82-00AA004BA90B")]
[InterfaceType(1)]
public interface IBindStatusCallback
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnStartBinding([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved, [In][MarshalAs(UnmanagedType.Interface)] IBinding pib);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPriority([ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] out int pnPriority);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnLowResource([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint reserved);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnProgress([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulProgress, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulProgressMax, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulStatusCode, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string szStatusText);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnStopBinding([In][MarshalAs(UnmanagedType.Error)] int hresult, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string szError);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetBindInfo([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint grfBINDF, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BINDINFO")][MarshalAs(UnmanagedType.LPArray)] BINDINFO[] pbindinfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnDataAvailable([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfBSCF, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwSize, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FORMATETC")][MarshalAs(UnmanagedType.LPArray)] FORMATETC[] pFormatetc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.STGMEDIUM")][MarshalAs(UnmanagedType.LPArray)] STGMEDIUM[] pStgmed);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void OnObjectAvailable([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [In][MarshalAs(UnmanagedType.IUnknown)] object punk);
}
[ComImport]
[InterfaceType(1)]
[Guid("79EAC9C0-BAF9-11CE-8C82-00AA004BA90B")]
public interface IBinding
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Abort();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Suspend();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Resume();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetPriority([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int nPriority);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetPriority([ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] out int pnPriority);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetBindResult(out Guid pclsidProtocol, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwResult, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")] IntPtr pszResult, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct BINDINFO
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cbSize;

	[MarshalAs(UnmanagedType.LPWStr)]
	public string szExtraInfo;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.STGMEDIUM")]
	public STGMEDIUM stgmedData;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint grfBindInfoF;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwBindVerb;

	[MarshalAs(UnmanagedType.LPWStr)]
	public string szCustomVerb;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint cbstgmedData;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwOptions;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwOptionsFlags;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwCodePage;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.SECURITY_ATTRIBUTES")]
	public SECURITY_ATTRIBUTES securityAttributes;

	public Guid iid;

	[MarshalAs(UnmanagedType.IUnknown)]
	public object punk;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwReserved;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct SECURITY_ATTRIBUTES
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint nLength;

	[ComConversionLoss]
	public IntPtr lpSecurityDescriptor;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	public int bInheritHandle;
}
[ComImport]
[InterfaceType(1)]
[Guid("6D5140C1-7436-11CE-8034-00AA006009FA")]
public interface IServiceProvider
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int QueryService([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidService, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, out IntPtr ppvObject);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct QACONTROL
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cbSize;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwMiscStatus;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwViewStatus;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwEventCookie;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwPropNotifyCookie;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwPointerActivationPolicy;
}
[ComImport]
[InterfaceType(1)]
[ComConversionLoss]
[Guid("00000112-0000-0000-C000-000000000046")]
public interface IOleObject
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetClientSite([In][MarshalAs(UnmanagedType.Interface)] IOleClientSite pClientSite);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetClientSite([MarshalAs(UnmanagedType.Interface)] out IOleClientSite ppClientSite);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetHostNames([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szContainerApp, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szContainerObj);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Close([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwSaveOption);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetMoniker([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwWhichMoniker, [In][MarshalAs(UnmanagedType.Interface)] IMoniker pmk);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetMoniker([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwAssign, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwWhichMoniker, [MarshalAs(UnmanagedType.Interface)] out IMoniker ppmk);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int InitFromData([In][MarshalAs(UnmanagedType.Interface)] IDataObject pDataObject, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fCreation, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetClipboardData([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved, [MarshalAs(UnmanagedType.Interface)] out IDataObject ppDataObject);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int DoVerb([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int iVerb, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.lpmsg")][MarshalAs(UnmanagedType.LPArray)] MSG[] lpmsg, [In][MarshalAs(UnmanagedType.Interface)] IOleClientSite pActiveSite, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lindex, [In] IntPtr hWndParent, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCRECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] lprcPosRect);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int EnumVerbs([MarshalAs(UnmanagedType.Interface)] out IEnumOLEVERB ppEnumOleVerb);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Update();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int IsUpToDate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetUserClassID(out Guid pClsid);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int GetUserType([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFormOfType, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")] IntPtr pszUserType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetExtent([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDrawAspect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.SIZEL")][MarshalAs(UnmanagedType.LPArray)] SIZEL[] pSizel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetExtent([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDrawAspect, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.SIZEL")][MarshalAs(UnmanagedType.LPArray)] SIZEL[] pSizel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Advise([In][MarshalAs(UnmanagedType.Interface)] IAdviseSink pAdvSink, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwConnection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Unadvise([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwConnection);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void EnumAdvise([MarshalAs(UnmanagedType.Interface)] out IEnumSTATDATA ppenumAdvise);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int GetMiscStatus([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwAspect, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwStatus);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetColorScheme([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LOGPALETTE")][MarshalAs(UnmanagedType.LPArray)] LOGPALETTE[] pLogpal);
}
[ComImport]
[Guid("00000104-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IEnumOLEVERB
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.OLEVERB")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] OLEVERB[] rgelt, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pceltFetched);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumOLEVERB ppEnum);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct OLEVERB
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public int lVerb;

	[MarshalAs(UnmanagedType.LPWStr)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")]
	public string lpszVerbName;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint fuFlags;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint grfAttribs;
}
[ComImport]
[ComConversionLoss]
[Guid("0000002F-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IRecordInfo
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RecordInit(out IntPtr pvNew);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RecordClear([In] IntPtr pvExisting);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RecordCopy([In] IntPtr pvExisting, out IntPtr pvNew);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetGUID(out Guid pGUID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetName([MarshalAs(UnmanagedType.BStr)] out string pBstrName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetSize([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcbSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetTypeInfo([MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.TypeToTypeInfoMarshaler, CustomMarshalers, Version=1.0.5000.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")] out Type ppTypeInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetField([In] IntPtr pvData, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szFieldName, [MarshalAs(UnmanagedType.Struct)] out object pvarField);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetFieldNoCopy([In] IntPtr pvData, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szFieldName, [MarshalAs(UnmanagedType.Struct)] out object pvarField, out IntPtr ppvDataCArray);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void PutField([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint wFlags, [In][Out] ref IntPtr pvData, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szFieldName, [In][MarshalAs(UnmanagedType.Struct)] ref object pvarField);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void PutFieldNoCopy([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint wFlags, [In][Out] ref IntPtr pvData, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szFieldName, [In][MarshalAs(UnmanagedType.Struct)] ref object pvarField);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetFieldNames([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] ref uint pcNames, [Out][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.BStr, SizeParamIndex = 0)] string[] rgBstrNames);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
	int IsMatchingType([In][MarshalAs(UnmanagedType.Interface)] IRecordInfo pRecordInfo);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	IntPtr RecordCreate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RecordCreateCopy([In] IntPtr pvSource, out IntPtr ppvDest);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RecordDestroy([In] IntPtr pvRecord);
}
[ComImport]
[InterfaceType(1)]
[Guid("00000138-0000-0000-C000-000000000046")]
public interface IPropertyStorage
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReadMultiple([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cpspec, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPSPEC")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] PROPSPEC[] rgpspec, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPVARIANT")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] PROPVARIANT[] rgpropvar);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void WriteMultiple([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cpspec, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPSPEC")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] PROPSPEC[] rgpspec, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPVARIANT")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] PROPVARIANT[] rgpropvar, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPID")] uint propidNameFirst);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DeleteMultiple([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cpspec, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPSPEC")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] PROPSPEC[] rgpspec);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReadPropertyNames([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cpropid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPID")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] uint[] rgpropid, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 0)] string[] rglpwstrName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void WritePropertyNames([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cpropid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPID")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] uint[] rgpropid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 0)] string[] rglpwstrName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DeletePropertyNames([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cpropid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPID")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] uint[] rgpropid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Commit([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfCommitFlags);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Revert();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Enum([MarshalAs(UnmanagedType.Interface)] out IEnumSTATPROPSTG ppEnum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetTimes([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FILETIME")][MarshalAs(UnmanagedType.LPArray)] FILETIME[] pctime, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FILETIME")][MarshalAs(UnmanagedType.LPArray)] FILETIME[] patime, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FILETIME")][MarshalAs(UnmanagedType.LPArray)] FILETIME[] pmtime);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetClass([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFCLSID")] ref Guid clsid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Stat([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.STATPROPSETSTG")][MarshalAs(UnmanagedType.LPArray)] STATPROPSETSTG[] pstatpsstg);
}
[StructLayout(LayoutKind.Explicit, Pack = 4)]
public struct PROPSPEC
{
	[FieldOffset(0)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint ulKind;

	[FieldOffset(4)]
	public IntPtr unionmember;
}
[StructLayout(LayoutKind.Explicit, Pack = 8)]
public struct PROPVARIANT
{
	[FieldOffset(0)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.VARTYPE")]
	public ushort vt;

	[FieldOffset(2)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPVAR_PAD1")]
	public byte wReserved1;

	[FieldOffset(3)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPVAR_PAD2")]
	public byte wReserved2;

	[FieldOffset(4)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPVAR_PAD3")]
	public uint wReserved3;

	[FieldOffset(8)]
	public IntPtr unionmember;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CLIPDATA
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cbSize;

	public int ulClipFmt;

	[ComConversionLoss]
	public IntPtr pClipData;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct BSTRBLOB
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cbSize;

	[ComConversionLoss]
	public IntPtr pData;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct BLOB
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cbSize;

	[ComConversionLoss]
	public IntPtr pBlobData;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct SAFEARRAY
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.USHORT")]
	public ushort cDims;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.USHORT")]
	public ushort fFeatures;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cbElements;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cLocks;

	[ComConversionLoss]
	public IntPtr pvData;

	[ComConversionLoss]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.SAFEARRAYBOUND")]
	public IntPtr rgsabound;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CAC
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CAUB
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.UCHAR")]
	[ComConversionLoss]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CAI
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.SHORT")]
	[ComConversionLoss]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CAUI
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.USHORT")]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CAL
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CAUL
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	[ComConversionLoss]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CAH
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LARGE_INTEGER")]
	[ComConversionLoss]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CAUH
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")]
	[ComConversionLoss]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CAFLT
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.FLOAT")]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CADBL
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CABOOL
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CASCODE
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CACY
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CADATE
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CAFILETIME
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.FILETIME")]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CACLSID
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CACLIPDATA
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.CLIPDATA")]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CABSTR
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CABSTRBLOB
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BSTRBLOB")]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CALPSTR
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CALPWSTR
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	public IntPtr pElems;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
[ComConversionLoss]
public struct CAPROPVARIANT
{
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")]
	public uint cElems;

	[ComConversionLoss]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPVARIANT")]
	public IntPtr pElems;
}
[ComImport]
[Guid("00000139-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IEnumSTATPROPSTG
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.STATPROPSTG")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] STATPROPSTG[] rgelt, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pceltFetched);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumSTATPROPSTG ppEnum);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct STATPROPSTG
{
	[MarshalAs(UnmanagedType.LPWStr)]
	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")]
	public string lpwstrName;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.PROPID")]
	public uint PROPID;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.VARTYPE")]
	public ushort vt;
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct STATPROPSETSTG
{
	public Guid fmtid;

	public Guid clsid;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint grfFlags;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.FILETIME")]
	public FILETIME mtime;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.FILETIME")]
	public FILETIME ctime;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.FILETIME")]
	public FILETIME atime;

	[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
	public uint dwOSVersion;
}
[ComImport]
[Guid("0000013B-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IEnumSTATPROPSETSTG
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.STATPROPSETSTG")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] STATPROPSETSTG[] rgelt, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pceltFetched);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	int Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Clone([MarshalAs(UnmanagedType.Interface)] out IEnumSTATPROPSETSTG ppEnum);
}
[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct VERSIONEDSTREAM
{
	public Guid guidVersion;

	[MarshalAs(UnmanagedType.Interface)]
	public IStream pStream;
}
public enum PIDMSI_STATUS_VALUE
{
	PIDMSI_STATUS_NORMAL = 0,
	PIDMSI_STATUS_NEW = 1,
	PIDMSI_STATUS_PRELIM = 2,
	PIDMSI_STATUS_DRAFT = 3,
	PIDMSI_STATUS_INPROGRESS = 4,
	PIDMSI_STATUS_EDIT = 5,
	PIDMSI_STATUS_REVIEW = 6,
	PIDMSI_STATUS_PROOF = 7,
	PIDMSI_STATUS_FINAL = 8,
	PIDMSI_STATUS_OTHER = 32767
}
[ComImport]
[Guid("0000013A-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IPropertySetStorage
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Create([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFFMTID")] ref Guid rfmtid, [In] ref Guid pClsid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfMode, [MarshalAs(UnmanagedType.Interface)] out IPropertyStorage ppprstg);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Open([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFFMTID")] ref Guid rfmtid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfMode, [MarshalAs(UnmanagedType.Interface)] out IPropertyStorage ppprstg);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Delete([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFFMTID")] ref Guid rfmtid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Enum([MarshalAs(UnmanagedType.Interface)] out IEnumSTATPROPSETSTG ppEnum);
}
[Flags]
public enum OLECMDID_REFRESHFLAG
{
	OLECMDIDF_REFRESH_NORMAL = 0,
	OLECMDIDF_REFRESH_IFEXPIRED = 1,
	OLECMDIDF_REFRESH_CONTINUE = 2,
	OLECMDIDF_REFRESH_COMPLETELY = 3,
	OLECMDIDF_REFRESH_NO_CACHE = 4,
	OLECMDIDF_REFRESH_RELOAD = 5,
	OLECMDIDF_REFRESH_LEVELMASK = 0xFF,
	OLECMDIDF_REFRESH_CLEARUSERINPUT = 0x1000,
	OLECMDIDF_REFRESH_PROMPTIFOFFLINE = 0x2000,
	OLECMDIDF_REFRESH_THROUGHSCRIPT = 0x4000
}
public enum Constants
{
	OLECMDSTATE_DISABLED = 1,
	OLECMDSTATE_UP = 3,
	OLECMDSTATE_DOWN = 7,
	OLECMDSTATE_NINCHED = 11,
	OLECMDSTATE_INVISIBLE = 17,
	OLECONTEXT_NULLMENU = -1,
	MSOCMDSTATE_DISABLED = 1,
	MSOCMDSTATE_UP = 3,
	MSOCMDSTATE_DOWN = 7,
	MSOCMDSTATE_NINCHED = 11,
	MSOCMDSTATE_INVISIBLE = 17,
	OLECMDERR_E_FIRST = -2147221248,
	OLECMDERR_E_NOTSUPPORTED = -2147221248,
	OLECMDERR_E_DISABLED = -2147221247,
	OLECMDERR_E_NOHELP = -2147221246,
	OLECMDERR_E_CANCELED = -2147221245,
	OLECMDERR_E_UNKNOWNGROUP = -2147221244,
	MSOCMDERR_E_FIRST = -2147221248,
	MSOCMDERR_E_NOTSUPPORTED = -2147221248,
	MSOCMDERR_E_DISABLED = -2147221247,
	MSOCMDERR_E_NOHELP = -2147221246,
	MSOCMDERR_E_CANCELED = -2147221245,
	MSOCMDERR_E_UNKNOWNGROUP = -2147221244,
	MSOCMDF_SUPPORTED = 1,
	MSOCMDF_ENABLED = 2,
	MSOCMDF_LATCHED = 4,
	MSOCMDF_NINCHED = 8,
	MSOCMDTEXTF_NONE = 0,
	MSOCMDTEXTF_NAME = 1,
	MSOCMDTEXTF_STATUS = 2,
	MSOCMDEXECOPT_DODEFAULT = 0,
	MSOCMDEXECOPT_PROMPTUSER = 1,
	MSOCMDEXECOPT_DONTPROMPTUSER = 2,
	MSOCMDEXECOPT_SHOWHELP = 3,
	MSOCMDID_OPEN = 1,
	MSOCMDID_NEW = 2,
	MSOCMDID_SAVE = 3,
	MSOCMDID_SAVEAS = 4,
	MSOCMDID_SAVECOPYAS = 5,
	MSOCMDID_PRINT = 6,
	MSOCMDID_PRINTPREVIEW = 7,
	MSOCMDID_PAGESETUP = 8,
	MSOCMDID_SPELL = 9,
	MSOCMDID_PROPERTIES = 10,
	MSOCMDID_CUT = 11,
	MSOCMDID_COPY = 12,
	MSOCMDID_PASTE = 13,
	MSOCMDID_PASTESPECIAL = 14,
	MSOCMDID_UNDO = 15,
	MSOCMDID_REDO = 16,
	MSOCMDID_SELECTALL = 17,
	MSOCMDID_CLEARSELECTION = 18,
	MSOCMDID_ZOOM = 19,
	MSOCMDID_GETZOOMRANGE = 20,
	PROPSETHDR_OSVERSION_UNKNOWN = -1,
	CCH_MAX_PROPSTG_NAME = 31
}
[ComImport]
[Guid("000C060B-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface SOleComponentManager
{
}
