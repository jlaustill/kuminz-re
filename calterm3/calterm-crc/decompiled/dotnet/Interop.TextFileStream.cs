using System;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: PrimaryInteropAssembly(1, 0)]
[assembly: Guid("cd2fc450-bd97-11d5-a0e9-0004ac9631b0")]
[assembly: ImportedFromTypeLib("CILTextFileStream")]
[assembly: TypeLibVersion(1, 0)]
[assembly: AssemblyVersion("3.0.5.17102")]
namespace Cummins.Interop.TextFileStream;

[ComImport]
[InterfaceType(1)]
[Guid("0C733A30-2A1C-11CE-ADE5-00AA0044773D")]
public interface ISequentialStream
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteRead(out byte pv, [In] uint cb, out uint pcbRead);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void RemoteWrite([In] ref byte pv, [In] uint cb, out uint pcbWritten);
}
[ComImport]
[InterfaceType(1)]
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
[InterfaceType(1)]
[Guid("0000010C-0000-0000-C000-000000000046")]
public interface IPersist
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetClassID(out Guid pClassID);
}
[ComImport]
[Guid("0000010B-0000-0000-C000-000000000046")]
[InterfaceType(1)]
public interface IPersistFile : IPersist
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	new void GetClassID(out Guid pClassID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void IsDirty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Load([In][MarshalAs(UnmanagedType.LPWStr)] string pszFileName, [In] uint dwMode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void Save([In][MarshalAs(UnmanagedType.LPWStr)] string pszFileName, [In] int fRemember);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SaveCompleted([In][MarshalAs(UnmanagedType.LPWStr)] string pszFileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void GetCurFile([MarshalAs(UnmanagedType.LPWStr)] out string ppszFileName);
}
[ComImport]
[Guid("D12BAEC6-85CC-4C3A-BE1E-87EC59916AC5")]
[TypeLibType(4160)]
public interface ICIPersistFile
{
	[DispId(1)]
	string CurrentFileName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743809)]
	void IsDirty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void Load([In][MarshalAs(UnmanagedType.BStr)] string pszFileName, [In] int dwMode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void Save([In][MarshalAs(UnmanagedType.BStr)] string pszFileName, [In] int fRemember);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void SaveCompleted([In][MarshalAs(UnmanagedType.BStr)] string pszFileName);
}
[ComImport]
[TypeLibType(2)]
[Guid("F4DA2D74-BC06-11D5-A0E9-0004AC9631B0")]
[ClassInterface(0)]
public class TextFileStreamClass : ICIPersistFile, TextFileStream, IPersistFile, IStream, ISequentialStream
{
	[DispId(1)]
	public virtual extern string CurrentFileName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743809)]
	public virtual extern void IsDirty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void Load([In][MarshalAs(UnmanagedType.BStr)] string pszFileName, [In] int dwMode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	public virtual extern void Save([In][MarshalAs(UnmanagedType.BStr)] string pszFileName, [In] int fRemember);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	public virtual extern void SaveCompleted([In][MarshalAs(UnmanagedType.BStr)] string pszFileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void GetClassID(out Guid pClassID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IPersistFile_IsDirty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void Load([In][MarshalAs(UnmanagedType.LPWStr)] string pszFileName, [In] uint dwMode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IPersistFile_Save([In][MarshalAs(UnmanagedType.LPWStr)] string pszFileName, [In] int fRemember);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IPersistFile_SaveCompleted([In][MarshalAs(UnmanagedType.LPWStr)] string pszFileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void GetCurFile([MarshalAs(UnmanagedType.LPWStr)] out string ppszFileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void RemoteRead(out byte pv, [In] uint cb, out uint pcbRead);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void RemoteWrite([In] ref byte pv, [In] uint cb, out uint pcbWritten);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void RemoteSeek([In] _LARGE_INTEGER dlibMove, [In] uint dwOrigin, out _ULARGE_INTEGER plibNewPosition);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void SetSize([In] _ULARGE_INTEGER libNewSize);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void RemoteCopyTo([In][MarshalAs(UnmanagedType.Interface)] IStream pstm, [In] _ULARGE_INTEGER cb, out _ULARGE_INTEGER pcbRead, out _ULARGE_INTEGER pcbWritten);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void Commit([In] uint grfCommitFlags);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void Revert();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void LockRegion([In] _ULARGE_INTEGER libOffset, [In] _ULARGE_INTEGER cb, [In] uint dwLockType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void UnlockRegion([In] _ULARGE_INTEGER libOffset, [In] _ULARGE_INTEGER cb, [In] uint dwLockType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void Stat(out tagSTATSTG pstatstg, [In] uint grfStatFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void Clone([MarshalAs(UnmanagedType.Interface)] out IStream ppstm);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ISequentialStream_RemoteRead(out byte pv, [In] uint cb, out uint pcbRead);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ISequentialStream_RemoteWrite([In] ref byte pv, [In] uint cb, out uint pcbWritten);
}
[ComImport]
[Guid("D12BAEC6-85CC-4C3A-BE1E-87EC59916AC5")]
[CoClass(typeof(TextFileStreamClass))]
public interface TextFileStream : ICIPersistFile
{
}
