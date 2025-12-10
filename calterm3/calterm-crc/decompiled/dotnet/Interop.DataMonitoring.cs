using System;
using System.Collections;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
using System.Threading;

[assembly: TypeLibVersion(1, 0)]
[assembly: ImportedFromTypeLib("CIDataMonitoringLib")]
[assembly: PrimaryInteropAssembly(1, 0)]
[assembly: Guid("9d6a7220-f67a-4803-8214-38bde4b1188b")]
[assembly: AssemblyVersion("3.0.5.17102")]
namespace Cummins.Interop.DataMonitoring;

[Guid("C45AA9F4-BC56-4C33-B178-FE6F78FA2268")]
public enum DataMonitoringMsgEnum
{
	MSG_DIAG_DATAELEMRETFAIL = 1,
	MSG_DIAG_DATAREAD = 2,
	MSG_DIAG_INVPARAMETHCALL = 3,
	MSG_DIAG_SUBSLOCKED = 4,
	MSG_DIAG_GENERALERROR = 5,
	MSG_DIAG_BAMIDLNOTSUPP = 6,
	MSG_DIAG_BAMIDLCONFERROR = 7,
	MSG_DIAG_BAMIDLSUBPROG = 8,
	MSG_DIAG_PB_SPN_VALUE_NOT_FOUND = 9,
	MSG_DIAG_PB_DATA_OVERFLOW = 10,
	MSG_DIAG_DATALINKDROPPED = 11,
	MSG_DIAG_FMNOTFASTENOUGH = 12,
	MSG_DIAG_DC_STOP_TIMEOUT = 13,
	MSG_DIAG_INVALID_RUN_LOCATION = 14,
	MSG_DIAG_STOP_BROADCAST = 15,
	MSG_DIAG_DC_START_TIMEOUT = 16,
	MSG_DIAG_IDL_START_BUFF_TRANS = 17,
	MSG_DIAG_DC2_NOT_SUPPORTED = 20,
	MSG_DIAG_BAM2_STOPPED_FAST_RATE = 21,
	MSG_DIAG_IDL2_KEYON_BUFFER_FULL = 22,
	MSG_DIAG_IDL2_RETRIEVING_RECS = 23,
	MSG_DIAG_IDL2_DATA_RETRIEVAL_RATE_LESS = 24,
	MSG_DIAG_IDL2_DATA_RETRIEVAL_RATE_MORE = 25,
	MSG_DAIG_XML_NOTIFICATION_OBSOLETE = 26,
	MSG_PROG_DATAELEMNOTIF = 101,
	MSG_PROG_BAMIDLSTATUS = 102,
	MSG_PROG_IDLBUFFTRANSTART = 103,
	MSG_PROG_IDLBUFFTRANCMP = 104,
	MSG_PROG_IDLCLIENTNOTSTART = 105,
	MSG_PROG_IDLCLIENTNOTCMP = 106,
	MSG_PROG_EDMDATANOTIFICATION = 107,
	MSG_PERF_DATAMONITPERF = 201,
	MSG_PERF_RETRIEVE_DC2_CONFIG = 108,
	MSG_PERF_PROCESS_RETRIEVE_DC2_CONFIG_PARAM_INFO = 109,
	MSG_REQ_QUERY_COLL_STAT = 301
}
public enum tagDataMonitoringMsgEnum
{
	MSG_DIAG_DATAELEMRETFAIL = 1,
	MSG_DIAG_DATAREAD = 2,
	MSG_DIAG_INVPARAMETHCALL = 3,
	MSG_DIAG_SUBSLOCKED = 4,
	MSG_DIAG_GENERALERROR = 5,
	MSG_DIAG_BAMIDLNOTSUPP = 6,
	MSG_DIAG_BAMIDLCONFERROR = 7,
	MSG_DIAG_BAMIDLSUBPROG = 8,
	MSG_DIAG_PB_SPN_VALUE_NOT_FOUND = 9,
	MSG_DIAG_PB_DATA_OVERFLOW = 10,
	MSG_DIAG_DATALINKDROPPED = 11,
	MSG_DIAG_FMNOTFASTENOUGH = 12,
	MSG_DIAG_DC_STOP_TIMEOUT = 13,
	MSG_DIAG_INVALID_RUN_LOCATION = 14,
	MSG_DIAG_STOP_BROADCAST = 15,
	MSG_DIAG_DC_START_TIMEOUT = 16,
	MSG_DIAG_IDL_START_BUFF_TRANS = 17,
	MSG_DIAG_DC2_NOT_SUPPORTED = 20,
	MSG_DIAG_BAM2_STOPPED_FAST_RATE = 21,
	MSG_DIAG_IDL2_KEYON_BUFFER_FULL = 22,
	MSG_DIAG_IDL2_RETRIEVING_RECS = 23,
	MSG_DIAG_IDL2_DATA_RETRIEVAL_RATE_LESS = 24,
	MSG_DIAG_IDL2_DATA_RETRIEVAL_RATE_MORE = 25,
	MSG_DAIG_XML_NOTIFICATION_OBSOLETE = 26,
	MSG_PROG_DATAELEMNOTIF = 101,
	MSG_PROG_BAMIDLSTATUS = 102,
	MSG_PROG_IDLBUFFTRANSTART = 103,
	MSG_PROG_IDLBUFFTRANCMP = 104,
	MSG_PROG_IDLCLIENTNOTSTART = 105,
	MSG_PROG_IDLCLIENTNOTCMP = 106,
	MSG_PROG_EDMDATANOTIFICATION = 107,
	MSG_PERF_DATAMONITPERF = 201,
	MSG_PERF_RETRIEVE_DC2_CONFIG = 108,
	MSG_PERF_PROCESS_RETRIEVE_DC2_CONFIG_PARAM_INFO = 109,
	MSG_REQ_QUERY_COLL_STAT = 301
}
[ComImport]
[Guid("BCFE590C-3B92-46E0-8492-E9FFBE36E8E9")]
[TypeLibType(4160)]
public interface ICISubManager
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	bool IsActive([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);
}
[ComImport]
[Guid("DFCEB193-4F14-42E2-B68E-FCB835AA56A6")]
[TypeLibType(4160)]
public interface ICISubscription
{
	[DispId(1)]
	int BaseRate
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
	CIDMCollection MonitoredDataElements
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(3)]
	ICICalDataServer DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(4)]
	tagCIDMNotifyTypesEnum NotificationType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		set;
	}

	[DispId(5)]
	bool NotifyOnChange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		set;
	}
}
[ComImport]
[TypeLibType(4160)]
[Guid("B77C0D91-7042-43A4-871A-C835C5711185")]
public interface ICICollection : IEnumerable
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();

	[DispId(1)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(0)]
	object this[[In][MarshalAs(UnmanagedType.Struct)] object loc]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void Add([In][MarshalAs(UnmanagedType.Struct)] object Item);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void Insert([In][MarshalAs(UnmanagedType.Struct)] object loc, [In][MarshalAs(UnmanagedType.Struct)] object Item);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object Remove([In][MarshalAs(UnmanagedType.Struct)] object loc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void Clear();
}
[ComImport]
[Guid("94F1C80C-8D92-4CB7-9EB6-480EB99C63C3")]
[TypeLibType(4160)]
public interface ICICalDataServer
{
	[DispId(1)]
	ICIDataAccess DataAccess
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(2)]
	ICISymbolicTree SymbolicTree
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(3)]
	ICICalEntity RootEntity
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICICalEntity GetEntityByName([In][MarshalAs(UnmanagedType.Interface)] ICICalEntity refEntity, [In][MarshalAs(UnmanagedType.BStr)] string EntityName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void ReadData([In] tagCIAddressingMode adressType, [In] int location, [In] int offset, [In] int size, [In] short timeout, [In] short retry, [MarshalAs(UnmanagedType.Struct)] out object data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void WriteData([In] tagCIAddressingMode addressType, [In] int location, [In] int offset, [In] short timeout, [In] short retry, [In][MarshalAs(UnmanagedType.Struct)] object data, [In] tagCIWriteMethod writeMethod);

	[DispId(7)]
	tagCICacheMode DefaultCacheMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		set;
	}

	[DispId(8)]
	tagCIByteOrder ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[param: In]
		set;
	}

	[DispId(9)]
	tagCIWriteMethod DefaultWriteMethod
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICICalEntity GetEntityByID([In][MarshalAs(UnmanagedType.Interface)] ICICalEntity refEntity, [In] int parameterID);

	[DispId(11)]
	string Configuration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}
}
[ComImport]
[Guid("A5623120-C467-48A7-AB9A-C5648D39CA7A")]
[TypeLibType(4160)]
public interface ICIDataAccess
{
	[DispId(1)]
	object DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.IDispatch)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void ReadData([In] tagCIAddressingMode adressType, [In] int location, [In] int offset, [In] int size, [In] short timeout, [In] short retry, [In][MarshalAs(UnmanagedType.Interface)] ICICalDataServer calDataServer, [MarshalAs(UnmanagedType.Struct)] out object data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void WriteData([In] tagCIAddressingMode addressType, [In] int location, [In] int offset, [In] short timeout, [In] short retry, [In][MarshalAs(UnmanagedType.Interface)] ICICalDataServer calDataServer, [In][MarshalAs(UnmanagedType.Struct)] object data, [In] tagCIWriteMethod writeMethod);

	[DispId(4)]
	tagCIAddressingMode PreferredAddressMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}
}
public enum tagCIAddressingMode
{
	address = 1,
	indexTableNumber,
	nameTableName,
	parameterID
}
public enum tagCIWriteMethod
{
	WRITE_AUTOMATIC,
	WRITE_SECURE_DATA,
	WRITE_DEVELOP_MEM,
	WRITE_SCRATCH_MEM,
	WRITE_SCRATCH_CRC_SWAP
}
[ComImport]
[Guid("9902629C-1F05-4DC4-9766-2CB66ABF303F")]
[TypeLibType(4160)]
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
[TypeLibType(4160)]
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
	object data
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
[TypeLibType(4160)]
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
	object address
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
	int nameTableName
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
	object size
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
[TypeLibType(4160)]
[Guid("8A4905A5-0627-4327-8D15-A67771655E46")]
public interface ICICalEntity
{
	[DispId(10)]
	string FullName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(11)]
	string EntityName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(12)]
	bool IsArrayDescendent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	void GetNonAddrText([In] int column, [In] int row, [MarshalAs(UnmanagedType.BStr)] out string text);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	void GetNonAddrColumn([In][MarshalAs(UnmanagedType.BStr)] string text, [In] int row, out int column);

	[DispId(15)]
	int NumberOfNonAddrRows
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		get;
	}

	[DispId(16)]
	int NumberOfNonAddrColumns
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		get;
	}

	[DispId(17)]
	tagCISymbolicType EntityType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(17)]
		get;
	}

	[DispId(18)]
	bool IsStructDescendent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		get;
	}
}
public enum tagCICacheMode
{
	readWrite = 1,
	writeThru,
	dataVolatile
}
public enum tagCIByteOrder
{
	ECM = 0,
	MSB = 1,
	LSB = 2,
	Signed = 4
}
public enum tagCIDMNotifyTypesEnum
{
	DM_NOTIFY_MESSAGE = 1,
	DM_NOTIFY_EVENT,
	DM_NOTIFY_BOTH,
	DM_NOTIFY_MESSAGE_XML,
	DM_NOTIFY_EVENT_XML,
	DM_NOTIFY_BOTH_XML
}
[ComImport]
[TypeLibType(4160)]
[Guid("6487306D-89D3-4D46-BAFE-142F500F2EA0")]
public interface ICIConfiguration
{
	[DispId(500)]
	string Configuration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(500)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(500)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}
}
[ComImport]
[InterfaceType(2)]
[Guid("0531F57B-F9D9-4365-9AB0-BC03DDC2139D")]
[TypeLibType(4096)]
public interface _IDataMonitorEventEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(100)]
	void DataUpdate([In][MarshalAs(UnmanagedType.IDispatch)] object notifications);
}
[ComImport]
[TypeLibType(4096)]
[Guid("EAFFB851-8234-11D6-BE30-00062930B735")]
[InterfaceType(2)]
public interface _ICIReceiveMailboxEvent
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(80)]
	void ReceiveMailboxMessage([In][MarshalAs(UnmanagedType.Struct)] object pHeader, [In][MarshalAs(UnmanagedType.Struct)] object pPacketData, [In] uint timeStamp);
}
[ComImport]
[Guid("F822FA55-282A-4DB2-B7F8-DD165E0F6767")]
[TypeLibType(4160)]
public interface ICISubscription2
{
	[DispId(1)]
	tagCIDMMonitorMode MonitorMode
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
public enum tagCIDMMonitorMode
{
	DM_MM_POLL = 1,
	DM_MM_BAM,
	DM_MM_IDL,
	DM_MM_POLL_FAULTS,
	DM_MM_EDM
}
[ComImport]
[InterfaceType(2)]
[Guid("2CB6B54D-9444-41F8-B154-9E1F02FA7B32")]
[TypeLibType(4096)]
public interface _ICIDataMonitorEvent2
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(101)]
	void DataUpdateXML([In][MarshalAs(UnmanagedType.BStr)] string bsXMLNotifications, [In][MarshalAs(UnmanagedType.Interface)] CISubscription pSubscription);
}
public enum tagCIDMRateEnum
{
	DM_RATE_MAX = 0,
	DM_RATE_DEFAULT = 200,
	DM_EDM_RATE_DEFAULT = 5
}
[ComImport]
[ComSourceInterfaces("Cummins.Interop.DataMonitoring._IDataMonitorEventEvents\0Cummins.Interop.DataMonitoring._ICIDataMonitorEvent2\0\0")]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("6FA42489-8EB9-48C9-9837-BC52E62FBF9C")]
public class CISubscriptionClass : ICISubscription, CISubscription, _IDataMonitorEventEvents_Event, ICIDataCollectorSubscription, ICIFaultCodeSubscription, ICIAssignMsgGroup, ICIConfiguration, ICISubscription2, _ICIDataMonitorEvent2_Event
{
	[DispId(1)]
	public virtual extern int BaseRate
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
	public virtual extern CIDMCollection MonitoredDataElements
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(3)]
	public virtual extern ICICalDataServer DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(4)]
	public virtual extern tagCIDMNotifyTypesEnum NotificationType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		set;
	}

	[DispId(5)]
	public virtual extern bool NotifyOnChange
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		set;
	}

	public virtual extern tagCIDMMonitorMode MonitorMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern tagCIDMTriggerMode TriggerMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int RateMultiplier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern CIDMIDLStopMode IDLStopMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[ComAliasName("Cummins.Interop.DataMonitoring.CIFaultStatusFilterEnum")]
	public virtual extern CIFaultStatusFilterEnum FilterOnStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.DataMonitoring.CIFaultStatusFilterEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("Cummins.Interop.DataMonitoring.CIFaultStatusFilterEnum")]
		set;
	}

	public virtual extern CIDMCollection FilterOnNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	public virtual extern int Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

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

	public virtual extern tagCIDMMonitorMode ICISubscription2_MonitorMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern event _IDataMonitorEventEvents_DataUpdateEventHandler DataUpdate;

	public virtual extern event _ICIDataMonitorEvent2_DataUpdateXMLEventHandler DataUpdateXML;
}
[TypeLibType(16)]
[ComVisible(false)]
[ComEventInterface(typeof(_IDataMonitorEventEvents\u0000), typeof(_IDataMonitorEventEvents_EventProvider\u0000))]
public interface _IDataMonitorEventEvents_Event
{
	event _IDataMonitorEventEvents_DataUpdateEventHandler DataUpdate;
}
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IDataMonitorEventEvents_DataUpdateEventHandler([In][MarshalAs(UnmanagedType.IDispatch)] object notifications);
[TypeLibType(16)]
[ComEventInterface(typeof(_ICIDataMonitorEvent2\u0000), typeof(_ICIDataMonitorEvent2_EventProvider\u0000))]
[ComVisible(false)]
public interface _ICIDataMonitorEvent2_Event
{
	event _ICIDataMonitorEvent2_DataUpdateXMLEventHandler DataUpdateXML;
}
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _ICIDataMonitorEvent2_DataUpdateXMLEventHandler([In][MarshalAs(UnmanagedType.BStr)] string bsXMLNotifications, [In][MarshalAs(UnmanagedType.Interface)] CISubscription pSubscription);
[ComImport]
[Guid("DFCEB193-4F14-42E2-B68E-FCB835AA56A6")]
[CoClass(typeof(CISubscriptionClass))]
public interface CISubscription : ICISubscription, _IDataMonitorEventEvents_Event
{
}
[ComImport]
[Guid("BA71CBAD-1120-4AC8-9EE5-29B4F9EF99DA")]
[TypeLibType(4160)]
public interface ICIDataCollectorSubscription
{
	[DispId(1)]
	tagCIDMMonitorMode MonitorMode
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
	tagCIDMTriggerMode TriggerMode
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
	int RateMultiplier
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
	CIDMIDLStopMode IDLStopMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		set;
	}
}
public enum tagCIDMTriggerMode
{
	DM_IS_ENGINE_SPEED = 1,
	DM_IS_ROAD_SPEED,
	DM_IS_TURBO_SPEED,
	DM_IS_CLOCK,
	DM_IS_FRAME,
	DM_IS_FOREGROUNDACTIVATED,
	DM_IS_CAM_CRANK_SPEED,
	DM_IS_TIMER
}
public enum CIDMIDLStopMode
{
	DM_IDL_IMMEDIATE = 1,
	DM_IDL_CENTERED,
	DM_IDL_FULL,
	DM_IDL_KEYON_FULL
}
[ComImport]
[Guid("5497CF5A-7FAB-4C9E-B14B-974740D63655")]
[TypeLibType(4160)]
public interface ICIFaultCodeSubscription
{
	[DispId(1)]
	[ComAliasName("Cummins.Interop.DataMonitoring.CIFaultStatusFilterEnum")]
	CIFaultStatusFilterEnum FilterOnStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: ComAliasName("Cummins.Interop.DataMonitoring.CIFaultStatusFilterEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: ComAliasName("Cummins.Interop.DataMonitoring.CIFaultStatusFilterEnum")]
		set;
	}

	[DispId(2)]
	CIDMCollection FilterOnNumber
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}
}
[Guid("152CAAB0-B438-424E-B950-6843C1219E32")]
public enum CIFaultStatusFilterEnum
{
	DM_STATUS_ACTIVE,
	DM_STATUS_PREV_ACTIVE,
	DM_STATUS_ALL
}
public enum tagCIFaultStatusFilterEnum
{
	DM_STATUS_ACTIVE,
	DM_STATUS_PREV_ACTIVE,
	DM_STATUS_ALL
}
[ComImport]
[Guid("68637035-AE08-4950-B92E-89E359DEBDE4")]
[TypeLibType(4160)]
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
[ClassInterface(0)]
[Guid("517BFF5B-869D-46A4-A1A6-A7C1D900E3CF")]
[TypeLibType(2)]
public class CISubscriptionManagerClass : ICISubscriptionManager, CISubscriptionManager, ICISubscriptionManager2, ICISubscriptionManager3, ICIAssignMsgGroup
{
	[DispId(3)]
	public virtual extern bool PerformanceMsgEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		set;
	}

	public virtual extern bool ICISubscriptionManager2_PerformanceMsgEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern bool ICISubscriptionManager3_PerformanceMsgEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
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
	[DispId(1)]
	public virtual extern void Add([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void Remove([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	public virtual extern void Pause([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void Resume([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ICISubscriptionManager2_Add([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ICISubscriptionManager2_Remove([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ICISubscriptionManager2_Pause([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ICISubscriptionManager2_Resume([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void SaveDC2Configuration([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern CISubscription RetrieveDC2Configuration([In][MarshalAs(UnmanagedType.Interface)] ICICalDataServer DataSource);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ICISubscriptionManager3_Add([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ICISubscriptionManager3_Remove([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ICISubscriptionManager3_Pause([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ICISubscriptionManager3_Resume([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ICISubscriptionManager3_SaveDC2Configuration([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern CISubscription ICISubscriptionManager3_RetrieveDC2Configuration([In][MarshalAs(UnmanagedType.Interface)] ICICalDataServer DataSource);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void SetSubConfigurationForDC2([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);
}
[ComImport]
[Guid("2EC92B28-E98A-4A8E-85ED-487695579A14")]
[CoClass(typeof(CISubscriptionManagerClass))]
public interface CISubscriptionManager : ICISubscriptionManager
{
}
[ComImport]
[TypeLibType(4160)]
[Guid("2EC92B28-E98A-4A8E-85ED-487695579A14")]
public interface ICISubscriptionManager
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void Add([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void Remove([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[DispId(3)]
	bool PerformanceMsgEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void Pause([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void Resume([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);
}
[ComImport]
[TypeLibType(4160)]
[Guid("E841F08B-A170-4196-8FE8-31BD596924D5")]
public interface ICISubscriptionManager2 : ICISubscriptionManager
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	new void Add([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	new void Remove([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[DispId(3)]
	new bool PerformanceMsgEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	new void Pause([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	new void Resume([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void SaveDC2Configuration([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	[return: MarshalAs(UnmanagedType.Interface)]
	CISubscription RetrieveDC2Configuration([In][MarshalAs(UnmanagedType.Interface)] ICICalDataServer DataSource);
}
[ComImport]
[Guid("8CE7514E-44D3-4FF0-992E-0693BA2AE0DD")]
[TypeLibType(4160)]
public interface ICISubscriptionManager3 : ICISubscriptionManager2
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	new void Add([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	new void Remove([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[DispId(3)]
	new bool PerformanceMsgEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	new void Pause([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	new void Resume([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	new void SaveDC2Configuration([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new CISubscription RetrieveDC2Configuration([In][MarshalAs(UnmanagedType.Interface)] ICICalDataServer DataSource);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void SetSubConfigurationForDC2([In][MarshalAs(UnmanagedType.Interface)] CISubscription subscription);
}
[ComImport]
[Guid("79471965-F9CD-44E3-A33D-FFC8EAFE2088")]
[TypeLibType(2)]
[ClassInterface(0)]
public class CICPPMonitorClass : ICICPPMonitor, CICPPMonitor, ICIDataElementMonitor, ICIAssignMsgGroup
{
	[DispId(1)]
	public virtual extern tagCIDMAccessModeEnum mode
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
	public virtual extern object location
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(3)]
	public virtual extern int offset
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
	public virtual extern int Length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		set;
	}

	public virtual extern int RateMultiplier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern tagCIDMRequestTypeEnum RequestType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern CISubscription subscription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	public virtual extern int Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}
}
[ComImport]
[Guid("EBD4F1A5-0E3B-47B0-9A00-23CCBCA83BB7")]
[CoClass(typeof(CICPPMonitorClass))]
public interface CICPPMonitor : ICICPPMonitor
{
}
[ComImport]
[TypeLibType(4160)]
[Guid("EBD4F1A5-0E3B-47B0-9A00-23CCBCA83BB7")]
public interface ICICPPMonitor
{
	[DispId(1)]
	tagCIDMAccessModeEnum mode
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
	object location
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(3)]
	int offset
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
	int Length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		set;
	}
}
public enum tagCIDMAccessModeEnum
{
	DM_MODE_ADDRESS = 1,
	DM_MODE_PARAMETER_ID,
	DM_MODE_NAME
}
[ComImport]
[Guid("5FFD154B-4508-4DB8-BED4-E4E7A2BA72FB")]
[TypeLibType(4160)]
public interface ICIDataElementMonitor
{
	[DispId(1)]
	int RateMultiplier
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
	tagCIDMRequestTypeEnum RequestType
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
	CISubscription subscription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}
}
public enum tagCIDMRequestTypeEnum
{
	DM_REQ_CPP = 1
}
[ComImport]
[Guid("F524750A-7C10-42C1-B96E-0D06FEDA8462")]
[TypeLibType(2)]
[ClassInterface(0)]
public class CIDataElementNotificationClass : ICIDataElementNotification, CIDataElementNotification, ICIAssignMsgGroup
{
	[DispId(1)]
	public virtual extern double ScaledFloat
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
	public virtual extern string ScaledValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	public virtual extern string UnitOfMeasure
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(4)]
	public virtual extern tagCIDMStatusEnum Status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		set;
	}

	[DispId(5)]
	public virtual extern bool Changed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		set;
	}

	[DispId(6)]
	public virtual extern int timeStamp
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		set;
	}

	[DispId(7)]
	public virtual extern ICIDataElementMonitor DataElementMonitor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(8)]
	public virtual extern object RawData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern int Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}
}
[ComImport]
[Guid("BB2C8240-FC7A-42C4-867F-4173A6461329")]
[CoClass(typeof(CIDataElementNotificationClass))]
public interface CIDataElementNotification : ICIDataElementNotification
{
}
[ComImport]
[Guid("BB2C8240-FC7A-42C4-867F-4173A6461329")]
[TypeLibType(4160)]
public interface ICIDataElementNotification
{
	[DispId(1)]
	double ScaledFloat
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
	string ScaledValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	string UnitOfMeasure
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(4)]
	tagCIDMStatusEnum Status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		set;
	}

	[DispId(5)]
	bool Changed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		set;
	}

	[DispId(6)]
	int timeStamp
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		set;
	}

	[DispId(7)]
	ICIDataElementMonitor DataElementMonitor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(8)]
	object RawData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}
}
public enum tagCIDMStatusEnum
{
	DM_STATUS_OK,
	DM_STATUS_DATALINK_ERROR,
	DM_STATUS_RATE_ERROR
}
[ComImport]
[Guid("F3DF23B6-64D9-46E9-9666-157B7333E21A")]
[TypeLibType(2)]
[ClassInterface(0)]
public class CIDMCollectionClass : ICICollection, CIDMCollection, ICIManageCollection, IEnumerable
{
	[DispId(1)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(0)]
	public virtual extern object this[[In][MarshalAs(UnmanagedType.Struct)] object loc]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	public virtual extern bool Dirty
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern bool Lock
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	public virtual extern IEnumerator GetEnumerator();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void Add([In][MarshalAs(UnmanagedType.Struct)] object Item);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	public virtual extern void Insert([In][MarshalAs(UnmanagedType.Struct)] object loc, [In][MarshalAs(UnmanagedType.Struct)] object Item);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object Remove([In][MarshalAs(UnmanagedType.Struct)] object loc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void Clear();
}
[ComImport]
[Guid("B77C0D91-7042-43A4-871A-C835C5711185")]
[CoClass(typeof(CIDMCollectionClass))]
public interface CIDMCollection : ICICollection
{
}
[ComImport]
[TypeLibType(4160)]
[Guid("62C99C15-A2E4-4549-A6AF-1D99DACAEA72")]
public interface ICIManageCollection
{
	[DispId(10)]
	bool Dirty
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[param: In]
		set;
	}

	[DispId(11)]
	bool Lock
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[param: In]
		set;
	}
}
[ComImport]
[TypeLibType(2)]
[Guid("71DB676E-4FB4-4837-8A98-B3EF373E6E6E")]
[ClassInterface(0)]
public class CIDataCollectorInfoClass : ICIDataCollectorInfo, CIDataCollectorInfo
{
	[DispId(1)]
	public virtual extern ICICalDataServer DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(2)]
	public virtual extern tagCIDataCollectorTypeEnum DataCollectorType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[DispId(3)]
	public virtual extern tagCIDMMonitorMode MonitorMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[DispId(4)]
	public virtual extern tagCIDataCollectorStatus Status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}

	[DispId(5)]
	public virtual extern tagCIDMTriggerMode TriggerMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
	}

	[DispId(6)]
	public virtual extern CIDMIDLStopMode IDLStopMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}
}
[ComImport]
[Guid("85E7D6D5-8099-4837-85C9-9DF7C7111DC3")]
[CoClass(typeof(CIDataCollectorInfoClass))]
public interface CIDataCollectorInfo : ICIDataCollectorInfo
{
}
[ComImport]
[TypeLibType(4160)]
[Guid("85E7D6D5-8099-4837-85C9-9DF7C7111DC3")]
public interface ICIDataCollectorInfo
{
	[DispId(1)]
	ICICalDataServer DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(2)]
	tagCIDataCollectorTypeEnum DataCollectorType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[DispId(3)]
	tagCIDMMonitorMode MonitorMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[DispId(4)]
	tagCIDataCollectorStatus Status
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}

	[DispId(5)]
	tagCIDMTriggerMode TriggerMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
	}

	[DispId(6)]
	CIDMIDLStopMode IDLStopMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}
}
public enum tagCIDataCollectorTypeEnum
{
	NONE,
	DATA_COLLECTOR,
	DATA_COLLECTOR2
}
public enum tagCIDataCollectorStatus
{
	DATA_COLLECTION_OFF,
	DATA_COLLECTION_ON
}
[TypeLibType(TypeLibTypeFlags.FHidden)]
[ClassInterface(ClassInterfaceType.None)]
public sealed class _ICIDataMonitorEvent2_SinkHelper : _ICIDataMonitorEvent2
{
	public _ICIDataMonitorEvent2_DataUpdateXMLEventHandler m_DataUpdateXMLDelegate;

	public int m_dwCookie;

	public void DataUpdateXML(string P_0, CISubscription P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_DataUpdateXMLDelegate != null)
		{
			m_DataUpdateXMLDelegate(P_0, P_1);
		}
	}

	internal _ICIDataMonitorEvent2_SinkHelper()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_dwCookie = 0;
		m_DataUpdateXMLDelegate = null;
	}
}
internal sealed class _ICIDataMonitorEvent2_EventProvider : _ICIDataMonitorEvent2_Event, IDisposable
{
	private IConnectionPointContainer m_ConnectionPointContainer;

	private ArrayList m_aEventSinkHelpers;

	private IConnectionPoint m_ConnectionPoint;

	private void Init()
	{
		IConnectionPoint ppCP = null;
		Guid riid = new Guid(new byte[16]
		{
			77, 181, 182, 44, 68, 148, 248, 65, 177, 84,
			158, 31, 2, 250, 123, 50
		});
		m_ConnectionPointContainer.FindConnectionPoint(ref riid, out ppCP);
		m_ConnectionPoint = ppCP;
		m_aEventSinkHelpers = new ArrayList();
	}

	public void add_DataUpdateXML(_ICIDataMonitorEvent2_DataUpdateXMLEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_ICIDataMonitorEvent2_SinkHelper iCIDataMonitorEvent2_SinkHelper = new _ICIDataMonitorEvent2_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iCIDataMonitorEvent2_SinkHelper, out pdwCookie);
			iCIDataMonitorEvent2_SinkHelper.m_dwCookie = pdwCookie;
			iCIDataMonitorEvent2_SinkHelper.m_DataUpdateXMLDelegate = P_0;
			m_aEventSinkHelpers.Add(iCIDataMonitorEvent2_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_DataUpdateXML(_ICIDataMonitorEvent2_DataUpdateXMLEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_aEventSinkHelpers == null)
			{
				return;
			}
			int count = m_aEventSinkHelpers.Count;
			int num = 0;
			if (0 >= count)
			{
				return;
			}
			do
			{
				_ICIDataMonitorEvent2_SinkHelper iCIDataMonitorEvent2_SinkHelper = (_ICIDataMonitorEvent2_SinkHelper)m_aEventSinkHelpers[num];
				if (iCIDataMonitorEvent2_SinkHelper.m_DataUpdateXMLDelegate != null && ((iCIDataMonitorEvent2_SinkHelper.m_DataUpdateXMLDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iCIDataMonitorEvent2_SinkHelper.m_dwCookie);
					if (count <= 1)
					{
						Marshal.ReleaseComObject(m_ConnectionPoint);
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

	public _ICIDataMonitorEvent2_EventProvider(object P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_ConnectionPointContainer = (IConnectionPointContainer)P_0;
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
					_ICIDataMonitorEvent2_SinkHelper iCIDataMonitorEvent2_SinkHelper = (_ICIDataMonitorEvent2_SinkHelper)m_aEventSinkHelpers[num];
					m_ConnectionPoint.Unadvise(iCIDataMonitorEvent2_SinkHelper.m_dwCookie);
					num++;
				}
				while (num < count);
			}
			Marshal.ReleaseComObject(m_ConnectionPoint);
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
		//Error decoding local variables: Signature type sequence must have at least one element.
		Finalize();
		GC.SuppressFinalize(this);
	}
}
[TypeLibType(TypeLibTypeFlags.FHidden)]
[ClassInterface(ClassInterfaceType.None)]
public sealed class _IDataMonitorEventEvents_SinkHelper : _IDataMonitorEventEvents
{
	public _IDataMonitorEventEvents_DataUpdateEventHandler m_DataUpdateDelegate;

	public int m_dwCookie;

	public void DataUpdate(object P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_DataUpdateDelegate != null)
		{
			m_DataUpdateDelegate(P_0);
		}
	}

	internal _IDataMonitorEventEvents_SinkHelper()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_dwCookie = 0;
		m_DataUpdateDelegate = null;
	}
}
internal sealed class _IDataMonitorEventEvents_EventProvider : _IDataMonitorEventEvents_Event, IDisposable
{
	private IConnectionPointContainer m_ConnectionPointContainer;

	private ArrayList m_aEventSinkHelpers;

	private IConnectionPoint m_ConnectionPoint;

	private void Init()
	{
		IConnectionPoint ppCP = null;
		Guid riid = new Guid(new byte[16]
		{
			123, 245, 49, 5, 217, 249, 101, 67, 154, 176,
			188, 3, 221, 194, 19, 157
		});
		m_ConnectionPointContainer.FindConnectionPoint(ref riid, out ppCP);
		m_ConnectionPoint = ppCP;
		m_aEventSinkHelpers = new ArrayList();
	}

	public void add_DataUpdate(_IDataMonitorEventEvents_DataUpdateEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IDataMonitorEventEvents_SinkHelper iDataMonitorEventEvents_SinkHelper = new _IDataMonitorEventEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iDataMonitorEventEvents_SinkHelper, out pdwCookie);
			iDataMonitorEventEvents_SinkHelper.m_dwCookie = pdwCookie;
			iDataMonitorEventEvents_SinkHelper.m_DataUpdateDelegate = P_0;
			m_aEventSinkHelpers.Add(iDataMonitorEventEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_DataUpdate(_IDataMonitorEventEvents_DataUpdateEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_aEventSinkHelpers == null)
			{
				return;
			}
			int count = m_aEventSinkHelpers.Count;
			int num = 0;
			if (0 >= count)
			{
				return;
			}
			do
			{
				_IDataMonitorEventEvents_SinkHelper iDataMonitorEventEvents_SinkHelper = (_IDataMonitorEventEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iDataMonitorEventEvents_SinkHelper.m_DataUpdateDelegate != null && ((iDataMonitorEventEvents_SinkHelper.m_DataUpdateDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iDataMonitorEventEvents_SinkHelper.m_dwCookie);
					if (count <= 1)
					{
						Marshal.ReleaseComObject(m_ConnectionPoint);
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

	public _IDataMonitorEventEvents_EventProvider(object P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_ConnectionPointContainer = (IConnectionPointContainer)P_0;
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
					_IDataMonitorEventEvents_SinkHelper iDataMonitorEventEvents_SinkHelper = (_IDataMonitorEventEvents_SinkHelper)m_aEventSinkHelpers[num];
					m_ConnectionPoint.Unadvise(iDataMonitorEventEvents_SinkHelper.m_dwCookie);
					num++;
				}
				while (num < count);
			}
			Marshal.ReleaseComObject(m_ConnectionPoint);
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
		//Error decoding local variables: Signature type sequence must have at least one element.
		Finalize();
		GC.SuppressFinalize(this);
	}
}
