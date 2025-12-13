using System;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: ImportedFromTypeLib("SECURITYMANAGERADDINAPILib")]
[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("BC225C53-A4C9-4C89-9A23-E8EE22FFDFC0")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace Cummins.INSITE.Addins.SecurityManagerAPI;

[ComImport]
[Guid("1D07C7DC-CC51-4653-A0A2-2B8CEC60FF1E")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface ISecurityPasswordRequest
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RequestFunctionalityPassword([In][MarshalAs(UnmanagedType.BStr)] string DlgTitle, [In][MarshalAs(UnmanagedType.BStr)] string DlgText);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	object RequestPassword([In][MarshalAs(UnmanagedType.BStr)] string DlgTitle, [In][MarshalAs(UnmanagedType.BStr)] string DlgText, [In][MarshalAs(UnmanagedType.BStr)] string LicenseID, [Optional][In][MarshalAs(UnmanagedType.Interface)] IStream __MIDL__ISecurityPasswordRequest0000, [In] int iPasswordType = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void DisplayPasswordInvalidMsg([In][MarshalAs(UnmanagedType.BStr)] string DlgText);
}
[ComImport]
[Guid("0C733A30-2A1C-11CE-ADE5-00AA0044773D")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
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
[Guid("DF5A36D8-13FA-401C-9D74-9E998CC23FFF")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface ILicenseLookup
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetLicenses([In][MarshalAs(UnmanagedType.BStr)] string bstrLicNames, [MarshalAs(UnmanagedType.BStr)] out string bstrLics);
}
[ComImport]
[Guid("7B158F77-A23A-4129-95BE-3A6F1D7C5172")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IPlusToolLevelSecurity
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	bool IsValidPlusLicenseAvailable();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void TogglePlusToolLevel([In] bool bUnsupportedEngine);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	bool IsValidLicenseAvailable([In][MarshalAs(UnmanagedType.BStr)] string bstrToolLevel);
}
[ComImport]
[Guid("353CEAAF-0493-4A55-BFBD-961EFFFA15FB")]
[TypeLibType(TypeLibTypeFlags.FOleAutomation)]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface ICertification
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsSigned([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, out bool pbSinged);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetLicense();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetCertifier();
}
