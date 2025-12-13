using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("E07EC481-F301-11D5-A54D-006094EB621F")]
[assembly: ImportedFromTypeLib("CILGTISBINIMAGELib")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace CILGTISBINIMAGELib;

[ComImport]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
[Guid("8310E706-77DE-4EA7-B47E-F08B9555E74C")]
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
[CoClass(typeof(CICalBinImageClass))]
public interface CICalBinImage : ICIFile
{
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("8241A551-3D04-11D2-A2EF-00805F0EE6A6")]
public interface ICIBinImage
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddImageData([In] int lAddress, [In][ComAliasName("CILGTISBINIMAGELib.CIBinImageData")] CIBinImageData recImageData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void AddNewImage([In] int lAddress, [In] int lLength);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ClearImages();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetCurrentImageByIndex([In] int lIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void SetCurrentImageByAddress([In] int lAddress);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("CILGTISBINIMAGELib.CIBinImageData")]
	CIBinImageData GetImageDataByIndex([In] int lIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("CILGTISBINIMAGELib.CIBinImageData")]
	CIBinImageData GetImageDataByAddress([In] int lAddress);

	[DispId(1610678279)]
	int ImageCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678280)]
	int ImageAddress
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678281)]
	int ImageLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(1610678282)]
	object ImageData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
[Guid("E07EC48F-F301-11D5-A54D-006094EB621F")]
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
[Guid("4E7A0013-4F42-4EB8-84F7-1F06BF61A8ED")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICISymbolicInit
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(400)]
	void CreateNewSymbolicData([In][MarshalAs(UnmanagedType.BStr)] string bstrName, [In] tagCISymbolicType eType, [MarshalAs(UnmanagedType.Interface)] out ICISymbolicData pData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(401)]
	void AttachToTree([In][MarshalAs(UnmanagedType.Interface)] ICISymbolicTree pTree, [In][MarshalAs(UnmanagedType.BStr)] string bstrName, [In][MarshalAs(UnmanagedType.BStr)] string bstrActiveVersion);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(402)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICITreeNode TransformDescriptor([In][MarshalAs(UnmanagedType.Interface)] ICISymbolicTree pTree, [In][MarshalAs(UnmanagedType.BStr)] string descriptor, [In][MarshalAs(UnmanagedType.BStr)] string Name);
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
	ICIBinaryData CurrentImage
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
	ICIBinaryData GetImage([In] int index);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void PutImage([In] int index, [In][MarshalAs(UnmanagedType.Interface)] ICIBinaryData ImageData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void AddImage([In][MarshalAs(UnmanagedType.Interface)] ICIBinaryData newImageData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetDataValues([In] int Location, [In] int Offset, [In] int Length);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	void WriteDataValues([In] int Location, [In] int Offset, [In] int Length, [In][MarshalAs(UnmanagedType.Struct)] ref object pVal);
}
[ComImport]
[ClassInterface(ClassInterfaceType.None)]
[Guid("E07EC490-F301-11D5-A54D-006094EB621F")]
[TypeLibType(TypeLibTypeFlags.FCanCreate | TypeLibTypeFlags.FLicensed)]
public class CICalBinImageClass : ICIFile, CICalBinImage, ICIBinImage, ICIHeaderRecords, ICISymbolicInit, ICIBinaryDataList
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

	public virtual extern int ImageAddress
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ImageLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern object ImageData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern int CalHeaderCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern int ICIBinaryDataList_ImageCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern ICIBinaryData CurrentImage
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
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
	public virtual extern void AddImageData([In] int lAddress, [In][ComAliasName("CILGTISBINIMAGELib.CIBinImageData")] CIBinImageData recImageData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void AddNewImage([In] int lAddress, [In] int lLength);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ClearImages();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void SetCurrentImageByIndex([In] int lIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void SetCurrentImageByAddress([In] int lAddress);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("CILGTISBINIMAGELib.CIBinImageData")]
	public virtual extern CIBinImageData GetImageDataByIndex([In] int lIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("CILGTISBINIMAGELib.CIBinImageData")]
	public virtual extern CIBinImageData GetImageDataByAddress([In] int lAddress);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ClearCalHeaders();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void AppendCalHeader([In][MarshalAs(UnmanagedType.BStr)] string header);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetCalHeader([In] int index);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void CreateNewSymbolicData([In][MarshalAs(UnmanagedType.BStr)] string bstrName, [In] tagCISymbolicType eType, [MarshalAs(UnmanagedType.Interface)] out ICISymbolicData pData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void AttachToTree([In][MarshalAs(UnmanagedType.Interface)] ICISymbolicTree pTree, [In][MarshalAs(UnmanagedType.BStr)] string bstrName, [In][MarshalAs(UnmanagedType.BStr)] string bstrActiveVersion);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICITreeNode TransformDescriptor([In][MarshalAs(UnmanagedType.Interface)] ICISymbolicTree pTree, [In][MarshalAs(UnmanagedType.BStr)] string descriptor, [In][MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ICIBinaryDataList_SetCurrentImageByIndex([In] int index);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void SetCurrentImageByLocation([In] int Location, [In] int Offset);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ICIBinaryDataList_ClearImages();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICIBinaryData GetImage([In] int index);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void PutImage([In] int index, [In][MarshalAs(UnmanagedType.Interface)] ICIBinaryData ImageData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void AddImage([In][MarshalAs(UnmanagedType.Interface)] ICIBinaryData newImageData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object GetDataValues([In] int Location, [In] int Offset, [In] int Length);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void WriteDataValues([In] int Location, [In] int Offset, [In] int Length, [In][MarshalAs(UnmanagedType.Struct)] ref object pVal);
}
public enum CalBinImageMsgEnum
{
	MSG_DIAG_FILE_READ_ERR = 1,
	MSG_DIAG_FILE_READ_START = 2,
	MSG_DIAG_FILE_READ_END = 3,
	MSG_DIAG_FILE_PROGRESS = 4,
	MSG_DIAG_FILE_WRITE_ERR = 5,
	MSG_DIAG_OVERLAP_BLOCK = 6,
	MSG_DIAG_CREATION_ERROR = 7,
	MSG_DIAG_FILE_FORMAT = 8,
	MSG_DIAG_ISTREAM_FAIL = 9,
	MSG_DIAG_FILE_OPEN_ERROR = 10,
	MSG_DIAG_FILE_NOT_FOUND = 11,
	MSG_DIAG_WRITE_CAL_ERROR = 12,
	MSG_DIAG_WRITE_PERM_ERROR = 13,
	MSG_DIAG_OVERWRITE_ERROR = 14,
	MSG_DIAG_LOC_VERS_OLDER = 15,
	MSG_DIAG_LOC_VERS_NEWER = 16,
	MSG_DIAG_INCOMPLETE_FILE = 17,
	MSG_DIAG_BAD_CHKSUM = 18,
	MSG_DIAG_BLOCK_NOT_FOUND = 19,
	MSG_DIAG_LOAD_FAILED = 20,
	MSG_DIAG_CALCULATED_CVN = 21,
	MSG_PROG_LOAD_HDR_REC = 50,
	MSG_PROG_LOAD_DATA_REC = 51,
	MSG_PROG_WRITE_HDR_REC = 52,
	MSG_PROG_WRITE_DATA_REC = 53,
	MSG_PROG_START_READ = 54,
	MSG_PROG_VERIFY_FILE = 55,
	MSG_PROG_START_LOAD = 56,
	MSG_PROG_COMPLETE_LOAD = 57,
	MSG_PROG_START_WRITE = 58,
	MSG_PROG_CALC_CRC = 59,
	MSG_PROG_COMPLETE_WRITE = 60,
	MSG_PROG_FETCH_FILE_INFO = 61
}
public enum tagCalBinImageMsgEnum
{
	MSG_DIAG_FILE_READ_ERR = 1,
	MSG_DIAG_FILE_READ_START = 2,
	MSG_DIAG_FILE_READ_END = 3,
	MSG_DIAG_FILE_PROGRESS = 4,
	MSG_DIAG_FILE_WRITE_ERR = 5,
	MSG_DIAG_OVERLAP_BLOCK = 6,
	MSG_DIAG_CREATION_ERROR = 7,
	MSG_DIAG_FILE_FORMAT = 8,
	MSG_DIAG_ISTREAM_FAIL = 9,
	MSG_DIAG_FILE_OPEN_ERROR = 10,
	MSG_DIAG_FILE_NOT_FOUND = 11,
	MSG_DIAG_WRITE_CAL_ERROR = 12,
	MSG_DIAG_WRITE_PERM_ERROR = 13,
	MSG_DIAG_OVERWRITE_ERROR = 14,
	MSG_DIAG_LOC_VERS_OLDER = 15,
	MSG_DIAG_LOC_VERS_NEWER = 16,
	MSG_DIAG_INCOMPLETE_FILE = 17,
	MSG_DIAG_BAD_CHKSUM = 18,
	MSG_DIAG_BLOCK_NOT_FOUND = 19,
	MSG_DIAG_LOAD_FAILED = 20,
	MSG_DIAG_CALCULATED_CVN = 21,
	MSG_PROG_LOAD_HDR_REC = 50,
	MSG_PROG_LOAD_DATA_REC = 51,
	MSG_PROG_WRITE_HDR_REC = 52,
	MSG_PROG_WRITE_DATA_REC = 53,
	MSG_PROG_START_READ = 54,
	MSG_PROG_VERIFY_FILE = 55,
	MSG_PROG_START_LOAD = 56,
	MSG_PROG_COMPLETE_LOAD = 57,
	MSG_PROG_START_WRITE = 58,
	MSG_PROG_CALC_CRC = 59,
	MSG_PROG_COMPLETE_WRITE = 60,
	MSG_PROG_FETCH_FILE_INFO = 61
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
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct CIBinImageData
{
	public int lAddress;

	public int lLength;

	[MarshalAs(UnmanagedType.Struct)]
	public object vtData;
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct __MIDL___MIDL_itf_GTISBinImage_0000_0000_0001
{
	public int lAddress;

	public int lLength;

	[MarshalAs(UnmanagedType.Struct)]
	public object vtData;
}
public enum tagCISymbolicType
{
	SymDataSource,
	SymGrouping,
	SymStructure,
	SymArray,
	SymInteger,
	SymFloatingPoint,
	SymDataBlock,
	SymCodeBlock,
	SymEnumeration,
	SymConstant,
	SymDynamic,
	SymDateTime,
	SymString,
	SymOperation,
	SymUnknown
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("DAEC4824-28E4-49CC-BF2B-7078F975E242")]
public interface ICISymbolicData
{
	[DispId(101)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(102)]
	string FullName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(103)]
	tagCISymbolicType Type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(103)]
		get;
	}

	[DispId(104)]
	string Units
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(105)]
	string Comment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(105)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(105)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(106)]
	object Address
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(106)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(106)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(107)]
	int IndexTable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(107)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(107)]
		[param: In]
		set;
	}

	[DispId(108)]
	int NameTableName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(108)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(108)]
		[param: In]
		set;
	}

	[DispId(109)]
	object AddressingOffset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(110)]
	object Size
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(110)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(110)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(111)]
	object LowerBound
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(111)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(111)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(112)]
	object UpperBound
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(112)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(112)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(113)]
	object ScalarMultiplier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(113)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(113)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(114)]
	int InvertScalarMultiplier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(114)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(114)]
		[param: In]
		set;
	}

	[DispId(115)]
	object ScalarOffset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(115)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(115)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(116)]
	int InvertScalarOffset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(116)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(116)]
		[param: In]
		set;
	}

	[DispId(117)]
	int ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(117)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(117)]
		[param: In]
		set;
	}

	[DispId(118)]
	int AccessLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(118)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(118)]
		[param: In]
		set;
	}

	[DispId(119)]
	string DisplayFormat
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(119)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(119)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(120)]
	short SubfileNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(120)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(120)]
		[param: In]
		set;
	}

	[DispId(121)]
	int RelatedAxis
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(121)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(121)]
		[param: In]
		set;
	}

	[DispId(122)]
	object GroupNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(122)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(122)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(123)]
	object NonAddressableData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(123)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(123)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(124)]
	string ActivationVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(124)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(124)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(125)]
	string DeactivationVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(125)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(125)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(126)]
	byte ConfigFileType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(126)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(126)]
		[param: In]
		set;
	}

	[DispId(127)]
	int IsSigned
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(127)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(127)]
		[param: In]
		set;
	}

	[DispId(128)]
	int ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(128)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(128)]
		[param: In]
		set;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("9902629C-1F05-4DC4-9766-2CB66ABF303F")]
public interface ICISymbolicTree
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(300)]
	void GetDataByName([In][MarshalAs(UnmanagedType.BStr)] string bstrName, [MarshalAs(UnmanagedType.Interface)] out ICITreeNode pData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(301)]
	void GetDataByPathName([In][MarshalAs(UnmanagedType.Interface)] ICITreeNode pNode, [In][MarshalAs(UnmanagedType.BStr)] string bstrPathName, [MarshalAs(UnmanagedType.Interface)] out ICITreeNode pData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(302)]
	void CreateNode([In][MarshalAs(UnmanagedType.Interface)] ICISymbolicData pData, [MarshalAs(UnmanagedType.Interface)] out ICITreeNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(303)]
	void AddToTree([In][MarshalAs(UnmanagedType.Interface)] ICITreeNode pNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(304)]
	void GetDataByID([In][MarshalAs(UnmanagedType.Interface)] ICITreeNode pNode, [In] int ID, [MarshalAs(UnmanagedType.Interface)] out ICITreeNode pData);
}
[ComImport]
[Guid("C10D87F8-5ABB-4691-ACC5-AFF4130092B5")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICITreeNode
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(200)]
	void InsertNode([In][MarshalAs(UnmanagedType.Interface)] ICITreeNode pNode, [In] tagCIInsertLocation eLocation);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(201)]
	void DetachNode();

	[DispId(205)]
	ICITreeNode Next
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(205)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(205)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(206)]
	ICITreeNode Previous
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(206)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(206)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(207)]
	ICITreeNode FirstChild
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(207)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(207)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(208)]
	ICITreeNode Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(208)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(208)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(209)]
	int SiblingCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(209)]
		get;
	}

	[DispId(210)]
	int ChildCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(210)]
		get;
	}

	[DispId(211)]
	object Data
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(211)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(211)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}
}
public enum tagCIInsertLocation
{
	Next = 1,
	Previous,
	Child
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("84604888-7983-11D6-A0B5-FFFFFF000000")]
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
