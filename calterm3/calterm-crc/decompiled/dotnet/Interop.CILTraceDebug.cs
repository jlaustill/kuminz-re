using System;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Security;

[assembly: Guid("546c9cd2-e591-11d4-94a7-00062999c513")]
[assembly: TypeLibVersion(1, 0)]
[assembly: SecurityRules(SecurityRuleSet.Level2)]
[assembly: ImportedFromTypeLib("CILTraceDebug")]
[assembly: AssemblyVersion("1.0.0.0")]
namespace CILTraceDebug;

[Guid("EC492855-F6BB-11D4-94B7-00062999C513")]
public enum CILogLevels
{
	CILowLevel,
	CIMediumLevel,
	CIHighLevel
}
public enum tagCILogLevels
{
	CILowLevel,
	CIMediumLevel,
	CIHighLevel
}
[Guid("EC492851-F6BB-11D4-94B7-00062999C513")]
public enum CILogCategories
{
	CILogGeneral = 1,
	CILogError = 2,
	CILogInfo = 4,
	CILogWarning = 8,
	CILogCTOR = 16,
	CILogDTOR = 32,
	CILogConfiguration = 64,
	CILogToolDiag = 128,
	CILogECMTest = 256,
	CILogECMProgramming = 512,
	CILogLogging = 1024,
	CILogReporting = 2048,
	CILogCalManagement = 4096,
	CILogSysAdmin = 8192,
	CILogECMControl = 16384,
	CILogMonitor = 32768,
	CILogRemoteAccess = 65536,
	CILogEventNotify = 131072,
	CILogHelp = 262144,
	CILogSecurity = 524288,
	CILogParamAdjust = 1048576,
	CILogStructures = 2097152,
	CILogTrace = int.MinValue
}
public enum tagCILogCategories
{
	CILogGeneral = 1,
	CILogError = 2,
	CILogInfo = 4,
	CILogWarning = 8,
	CILogCTOR = 16,
	CILogDTOR = 32,
	CILogConfiguration = 64,
	CILogToolDiag = 128,
	CILogECMTest = 256,
	CILogECMProgramming = 512,
	CILogLogging = 1024,
	CILogReporting = 2048,
	CILogCalManagement = 4096,
	CILogSysAdmin = 8192,
	CILogECMControl = 16384,
	CILogMonitor = 32768,
	CILogRemoteAccess = 65536,
	CILogEventNotify = 131072,
	CILogHelp = 262144,
	CILogSecurity = 524288,
	CILogParamAdjust = 1048576,
	CILogStructures = 2097152,
	CILogTrace = int.MinValue
}
[ComImport]
[TypeLibType(4160)]
[DefaultMember("Enabled")]
[Guid("BB51DF36-F07F-11D4-94B3-00062999C513")]
public interface ICILogManager
{
	[DispId(0)]
	int Enabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		set;
	}

	[DispId(1)]
	short Level
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		set;
	}

	[DispId(2)]
	int Categories
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void SetStream([In][MarshalAs(UnmanagedType.Interface)] IStream newStream);
}
[ComImport]
[Guid("0000000C-0000-0000-C000-000000000046")]
[InterfaceType(1)]
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
[TypeLibType(4160)]
[DefaultMember("LogTraceMessage")]
[Guid("BB51DF37-F07F-11D4-94B3-00062999C513")]
public interface ICILog
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(0)]
	void LogTraceMessage([In][MarshalAs(UnmanagedType.BStr)] string signature, [In][MarshalAs(UnmanagedType.BStr)] string fileName, [In] int lineNumber, [In] int thread = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void LogMessage([In][MarshalAs(UnmanagedType.BStr)] string programmerText, [In][ComAliasName("CILTraceDebug.CILogLevels")] CILogLevels Level, [In] int Categories, [In][MarshalAs(UnmanagedType.BStr)] string fileName, [In] int lineNumber, [In] int thread = 0);
}
[ComImport]
[ClassInterface(0)]
[Guid("1B103B23-1243-11D5-94C4-00062999C513")]
[TypeLibType(2)]
[DefaultMember("LogTraceMessage")]
public class LoggerClass : ICILog, Logger, ICILogManager
{
	public virtual extern int Enabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern short Level
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int Categories
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(0)]
	public virtual extern void LogTraceMessage([In][MarshalAs(UnmanagedType.BStr)] string signature, [In][MarshalAs(UnmanagedType.BStr)] string fileName, [In] int lineNumber, [In] int thread = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	public virtual extern void LogMessage([In][MarshalAs(UnmanagedType.BStr)] string programmerText, [In][ComAliasName("CILTraceDebug.CILogLevels")] CILogLevels Level, [In] int Categories, [In][MarshalAs(UnmanagedType.BStr)] string fileName, [In] int lineNumber, [In] int thread = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void SetStream([In][MarshalAs(UnmanagedType.Interface)] IStream newStream);
}
[ComImport]
[CoClass(typeof(LoggerClass))]
[Guid("BB51DF37-F07F-11D4-94B3-00062999C513")]
public interface Logger : ICILog
{
}
