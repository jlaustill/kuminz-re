using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("CF352CCE-F20C-11D6-A501-0008A1326F46")]
[assembly: ImportedFromTypeLib("CILSubFiles")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace CILSubFiles;

[ComImport]
[Guid("8310E706-77DE-4EA7-B47E-F08B9555E74C")]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
public interface ICIFile
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReadFile([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void WriteFile([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, [In] int bOverwrite);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReadFileDescription([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, [MarshalAs(UnmanagedType.BStr)] out string pbstrDescription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void VerifyFile([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, [In][MarshalAs(UnmanagedType.BStr)] string bstrVersion);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReadFileVersion([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, [MarshalAs(UnmanagedType.BStr)] out string pbstrVersion);

	[DispId(906)]
	object FileExtensions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(907)]
	string Configuration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(908)]
	string FileDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(909)]
	string FileVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(910)]
	string Description
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(911)]
	string Version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(912)]
	int CanRead
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(913)]
	int CanWrite
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}
}
[ComImport]
[Guid("8310E706-77DE-4EA7-B47E-F08B9555E74C")]
[CoClass(typeof(SubFileComponentClass))]
public interface SubFileComponent : ICIFile
{
}
[ComImport]
[Guid("8460488B-7983-11D6-A0B5-FFFFFF000000")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIBinaryDataList
{
	[DispId(1)]
	int ImageCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	BinaryData CurrentImage
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void SetCurrentImageByIndex([In] int index);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void SetCurrentImageByLocation([In] int Location, [In] int Offset);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void ClearImages();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	[return: MarshalAs(UnmanagedType.Interface)]
	BinaryData GetImage([In] int index);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void PutImage([In] int index, [In][MarshalAs(UnmanagedType.Interface)] BinaryData imageData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void AddImage([In][MarshalAs(UnmanagedType.Interface)] BinaryData newImageData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetDataValues([In] int Location, [In] int Offset, [In] int Length);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	void WriteDataValues([In] int Location, [In] int Offset, [In] int Length, [In][MarshalAs(UnmanagedType.Struct)] ref object pVal);
}
[ComImport]
[Guid("E07EC48F-F301-11D5-A54D-006094EB621F")]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
public interface ICIHeaderRecords
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ClearCalHeaders();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AppendCalHeader([In][MarshalAs(UnmanagedType.BStr)] string header);

	[DispId(3)]
	int CalHeaderCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetCalHeader([In] int index);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("68637035-AE08-4950-B92E-89E359DEBDE4")]
public interface ICIAssignMsgGroup
{
	[DispId(1)]
	int Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		set;
	}
}
[ComImport]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate | TypeLibTypeFlags.FLicensed)]
[Guid("CF352CDE-F20C-11D6-A501-0008A1326F46")]
public class SubFileComponentClass : ICIFile, SubFileComponent, ICIBinaryDataList, ICIHeaderRecords, ICIAssignMsgGroup
{
	[DispId(906)]
	public virtual extern object FileExtensions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(907)]
	public virtual extern string Configuration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(908)]
	public virtual extern string FileDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(909)]
	public virtual extern string FileVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(910)]
	public virtual extern string Description
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(911)]
	public virtual extern string Version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(912)]
	public virtual extern int CanRead
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(913)]
	public virtual extern int CanWrite
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ImageCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern BinaryData CurrentImage
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern int CalHeaderCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ReadFile([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void WriteFile([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, [In] int bOverwrite);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ReadFileDescription([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, [MarshalAs(UnmanagedType.BStr)] out string pbstrDescription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void VerifyFile([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, [In][MarshalAs(UnmanagedType.BStr)] string bstrVersion);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ReadFileVersion([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, [MarshalAs(UnmanagedType.BStr)] out string pbstrVersion);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void SetCurrentImageByIndex([In] int index);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void SetCurrentImageByLocation([In] int Location, [In] int Offset);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ClearImages();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern BinaryData GetImage([In] int index);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void PutImage([In] int index, [In][MarshalAs(UnmanagedType.Interface)] BinaryData imageData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void AddImage([In][MarshalAs(UnmanagedType.Interface)] BinaryData newImageData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object GetDataValues([In] int Location, [In] int Offset, [In] int Length);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void WriteDataValues([In] int Location, [In] int Offset, [In] int Length, [In][MarshalAs(UnmanagedType.Struct)] ref object pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ClearCalHeaders();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void AppendCalHeader([In][MarshalAs(UnmanagedType.BStr)] string header);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetCalHeader([In] int index);
}
[ComImport]
[Guid("84604888-7983-11D6-A0B5-FFFFFF000000")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIBinaryData
{
	[DispId(1)]
	int Location
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
	int Offset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		set;
	}

	[DispId(3)]
	int Length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		set;
	}

	[DispId(4)]
	object BinaryData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}
}
[ComImport]
[Guid("84604888-7983-11D6-A0B5-FFFFFF000000")]
[CoClass(typeof(BinaryDataClass))]
public interface BinaryData : ICIBinaryData
{
}
[ComImport]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("CF352CE0-F20C-11D6-A501-0008A1326F46")]
public class BinaryDataClass : ICIBinaryData, BinaryData
{
	[DispId(1)]
	public virtual extern int Location
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
	public virtual extern int Offset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		set;
	}

	[DispId(3)]
	public virtual extern int Length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		set;
	}

	[DispId(4)]
	public virtual extern object BinaryData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}
}
[Guid("69A52B02-6445-4715-8DE9-044745190126")]
public enum SubfilesMsgEnum
{
	MSG_DIAG_OPENFILEFAIL = 1,
	MSG_DIAG_READDATAFAIL = 2,
	MSG_DIAG_CRCINCORRECT = 3,
	MSG_DIAG_LINECSERRFOUND = 4,
	MSG_DIAG_WRITEDATAFAIL = 5,
	MSG_DIAG_DATANOTFOUND = 6,
	MSG_DIAG_INSERTDATAFAIL = 7,
	MSG_DIAG_EOF_BEFORE = 220,
	MSG_DIAG_BUSS_HR_MISS_EXPECTING_ECI = 8,
	MSG_PROG_OPEN_END = 101,
	MSG_PROG_CLOSE_END = 102,
	MSG_PROG_START_LOAD = 103,
	MSG_PROG_PROG_READ = 104,
	MSG_PROG_COMPLETE_LOAD = 105,
	MSG_PROG_START_WRITE = 106,
	MSG_PROG_PROG_WRITE = 107,
	MSG_PROG_COMPLETE_WRITE = 108,
	MSG_PROG_VERIFY_FILE = 109,
	MSG_PROG_LOAD_HDR_REC = 110,
	MSG_PROG_LOAD_DATA_REC = 111,
	MSG_PROG_WRITE_HDR_REC = 212,
	MSG_PROG_WRITE_DATA_REC = 213,
	MSG_PROG_START_READ = 214
}
public enum tagSubfilesMsgEnum
{
	MSG_DIAG_OPENFILEFAIL = 1,
	MSG_DIAG_READDATAFAIL = 2,
	MSG_DIAG_CRCINCORRECT = 3,
	MSG_DIAG_LINECSERRFOUND = 4,
	MSG_DIAG_WRITEDATAFAIL = 5,
	MSG_DIAG_DATANOTFOUND = 6,
	MSG_DIAG_INSERTDATAFAIL = 7,
	MSG_DIAG_EOF_BEFORE = 220,
	MSG_DIAG_BUSS_HR_MISS_EXPECTING_ECI = 8,
	MSG_PROG_OPEN_END = 101,
	MSG_PROG_CLOSE_END = 102,
	MSG_PROG_START_LOAD = 103,
	MSG_PROG_PROG_READ = 104,
	MSG_PROG_COMPLETE_LOAD = 105,
	MSG_PROG_START_WRITE = 106,
	MSG_PROG_PROG_WRITE = 107,
	MSG_PROG_COMPLETE_WRITE = 108,
	MSG_PROG_VERIFY_FILE = 109,
	MSG_PROG_LOAD_HDR_REC = 110,
	MSG_PROG_LOAD_DATA_REC = 111,
	MSG_PROG_WRITE_HDR_REC = 212,
	MSG_PROG_WRITE_DATA_REC = 213,
	MSG_PROG_START_READ = 214
}
