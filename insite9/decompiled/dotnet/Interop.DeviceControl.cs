using System;
using System.Collections;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
using System.Threading;

[assembly: Guid("A8D69B68-CD36-11D5-9FFA-FFFFFF000000")]
[assembly: ImportedFromTypeLib("CILDCLDEVICECONTROLLib")]
[assembly: TypeLibVersion(1, 0)]
[assembly: AssemblyVersion("7.6.0.272")]
namespace CILDCLDEVICECONTROLLib;

[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("BAD58358-C7B8-11D5-9FF6-FFFFFF000000")]
public interface ICIRequest
{
	[DispId(1)]
	int Timeout
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
	short Retries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	[DispId(3)]
	ReqProtocolEnum ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[DispId(4)]
	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	RequestTypeEnum ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	[DispId(5)]
	RequestStatusEnum ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	[DispId(6)]
	int ReqDataLength
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
	object ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(8)]
	int DclStatus
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
	string DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[CoClass(typeof(DCLRequestClass))]
[Guid("BAD58358-C7B8-11D5-9FF6-FFFFFF000000")]
public interface DCLRequest : ICIRequest
{
}
[ComImport]
[Guid("68637035-AE08-4950-B92E-89E359DEBDE4")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
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
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("8BBBAB3A-7BA7-4384-9203-AFCCFBDB390E")]
public interface ICIRequest2
{
	[DispId(1)]
	bool Asynchronous
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
[Guid("F710E180-CD64-11D5-9FFA-FFFFFF000000")]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ClassInterface(ClassInterfaceType.None)]
public class DCLRequestClass : ICIRequest, DCLRequest, ICIAssignMsgGroup, ICIRequest2
{
	[DispId(1)]
	public virtual extern int Timeout
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
	public virtual extern short Retries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	[DispId(3)]
	public virtual extern ReqProtocolEnum ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	[DispId(4)]
	public virtual extern RequestTypeEnum ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	[DispId(5)]
	public virtual extern RequestStatusEnum ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	[DispId(6)]
	public virtual extern int ReqDataLength
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
	public virtual extern object ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(8)]
	public virtual extern int DclStatus
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
	public virtual extern string DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.BStr)]
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

	public virtual extern bool Asynchronous
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("BAD5835A-C7B8-11D5-9FF6-FFFFFF000000")]
public interface ICICPPWriteRequest : ICIRequest
{
	[DispId(1)]
	new int Timeout
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
	new short Retries
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
	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	new ReqProtocolEnum ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	[DispId(4)]
	new RequestTypeEnum ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[DispId(5)]
	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	new RequestStatusEnum ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	[DispId(6)]
	new int ReqDataLength
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
	new object ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(8)]
	new int DclStatus
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
	new string DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(100)]
	int WriteName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.CPPWriteTypeEnum")]
	[DispId(101)]
	CPPWriteTypeEnum WriteType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.CPPWriteTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.CPPWriteTypeEnum")]
		set;
	}

	[DispId(102)]
	int WriteOffset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		[param: In]
		set;
	}

	[DispId(103)]
	[ComAliasName("CILDCLDEVICECONTROLLib.CPPWriteMethodEnum")]
	CPPWriteMethodEnum WriteMethod
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(103)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.CPPWriteMethodEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(103)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.CPPWriteMethodEnum")]
		set;
	}

	[DispId(104)]
	[ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
	CPPInstProtocolEnum CppInstProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
		set;
	}

	[DispId(105)]
	int Address
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(105)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(105)]
		[param: In]
		set;
	}
}
[ComImport]
[CoClass(typeof(CPPWriteRequestClass))]
[Guid("BAD5835A-C7B8-11D5-9FF6-FFFFFF000000")]
public interface CPPWriteRequest : ICICPPWriteRequest
{
}
[ComImport]
[Guid("BAD58355-C7B8-11D5-9FF6-FFFFFF000000")]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class CPPWriteRequestClass : ICICPPWriteRequest, CPPWriteRequest, ICIRequest, ICIAssignMsgGroup
{
	[DispId(1)]
	public virtual extern int Timeout
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
	public virtual extern short Retries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	[DispId(3)]
	public virtual extern ReqProtocolEnum ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[DispId(4)]
	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	public virtual extern RequestTypeEnum ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[DispId(5)]
	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	public virtual extern RequestStatusEnum ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	[DispId(6)]
	public virtual extern int ReqDataLength
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
	public virtual extern object ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(8)]
	public virtual extern int DclStatus
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
	public virtual extern string DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(100)]
	public virtual extern int WriteName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		[param: In]
		set;
	}

	[DispId(101)]
	[ComAliasName("CILDCLDEVICECONTROLLib.CPPWriteTypeEnum")]
	public virtual extern CPPWriteTypeEnum WriteType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.CPPWriteTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.CPPWriteTypeEnum")]
		set;
	}

	[DispId(102)]
	public virtual extern int WriteOffset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		[param: In]
		set;
	}

	[DispId(103)]
	[ComAliasName("CILDCLDEVICECONTROLLib.CPPWriteMethodEnum")]
	public virtual extern CPPWriteMethodEnum WriteMethod
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(103)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.CPPWriteMethodEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(103)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.CPPWriteMethodEnum")]
		set;
	}

	[DispId(104)]
	[ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
	public virtual extern CPPInstProtocolEnum CppInstProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
		set;
	}

	[DispId(105)]
	public virtual extern int Address
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(105)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(105)]
		[param: In]
		set;
	}

	public virtual extern int ICIRequest_Timeout
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern short ICIRequest_Retries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	public virtual extern ReqProtocolEnum ICIRequest_ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	public virtual extern RequestTypeEnum ICIRequest_ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	public virtual extern RequestStatusEnum ICIRequest_ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	public virtual extern int ICIRequest_ReqDataLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern object ICIRequest_ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern int ICIRequest_DclStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern string ICIRequest_DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
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
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("9BB0F6A2-C881-11D5-9FF6-FFFFFF000000")]
public interface ICICPPReadRequest : ICIRequest
{
	[DispId(1)]
	new int Timeout
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
	new short Retries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	[DispId(3)]
	new ReqProtocolEnum ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[DispId(4)]
	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	new RequestTypeEnum ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[DispId(5)]
	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	new RequestStatusEnum ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	[DispId(6)]
	new int ReqDataLength
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
	new object ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(8)]
	new int DclStatus
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
	new string DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(100)]
	int ReadLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		[param: In]
		set;
	}

	[DispId(101)]
	int ReadName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[param: In]
		set;
	}

	[DispId(102)]
	[ComAliasName("CILDCLDEVICECONTROLLib.CPPReadTypeEnum")]
	CPPReadTypeEnum ReadType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.CPPReadTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.CPPReadTypeEnum")]
		set;
	}

	[DispId(103)]
	int ReadOffset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(103)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(103)]
		[param: In]
		set;
	}

	[DispId(104)]
	[ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
	CPPInstProtocolEnum CppInstProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
		set;
	}

	[DispId(105)]
	int Address
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(105)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(105)]
		[param: In]
		set;
	}
}
[ComImport]
[CoClass(typeof(CPPReadRequestClass))]
[Guid("9BB0F6A2-C881-11D5-9FF6-FFFFFF000000")]
public interface CPPReadRequest : ICICPPReadRequest
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ClassInterface(ClassInterfaceType.None)]
[Guid("3EE4B82A-CD3C-11D5-9FFA-FFFFFF000000")]
public class CPPReadRequestClass : ICICPPReadRequest, CPPReadRequest, ICIRequest, ICIAssignMsgGroup
{
	[DispId(1)]
	public virtual extern int Timeout
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
	public virtual extern short Retries
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
	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	public virtual extern ReqProtocolEnum ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	[DispId(4)]
	public virtual extern RequestTypeEnum ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[DispId(5)]
	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	public virtual extern RequestStatusEnum ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	[DispId(6)]
	public virtual extern int ReqDataLength
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
	public virtual extern object ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(8)]
	public virtual extern int DclStatus
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
	public virtual extern string DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(100)]
	public virtual extern int ReadLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		[param: In]
		set;
	}

	[DispId(101)]
	public virtual extern int ReadName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.CPPReadTypeEnum")]
	[DispId(102)]
	public virtual extern CPPReadTypeEnum ReadType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.CPPReadTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.CPPReadTypeEnum")]
		set;
	}

	[DispId(103)]
	public virtual extern int ReadOffset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(103)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(103)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
	[DispId(104)]
	public virtual extern CPPInstProtocolEnum CppInstProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
		set;
	}

	[DispId(105)]
	public virtual extern int Address
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(105)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(105)]
		[param: In]
		set;
	}

	public virtual extern int ICIRequest_Timeout
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern short ICIRequest_Retries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	public virtual extern ReqProtocolEnum ICIRequest_ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	public virtual extern RequestTypeEnum ICIRequest_ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	public virtual extern RequestStatusEnum ICIRequest_ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	public virtual extern int ICIRequest_ReqDataLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern object ICIRequest_ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern int ICIRequest_DclStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern string ICIRequest_DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
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
}
[ComImport]
[Guid("9BB0F6A4-C881-11D5-9FF6-FFFFFF000000")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICICPPCommandRequest : ICIRequest
{
	[DispId(1)]
	new int Timeout
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
	new short Retries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	[DispId(3)]
	new ReqProtocolEnum ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[DispId(4)]
	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	new RequestTypeEnum ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[DispId(5)]
	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	new RequestStatusEnum ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	[DispId(6)]
	new int ReqDataLength
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
	new object ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(8)]
	new int DclStatus
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
	new string DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.CPPCommandEnum")]
	[DispId(100)]
	CPPCommandEnum Command
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.CPPCommandEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.CPPCommandEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
	[DispId(101)]
	CPPInstProtocolEnum CppInstProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
		set;
	}
}
[ComImport]
[CoClass(typeof(CPPCommandRequestClass))]
[Guid("9BB0F6A4-C881-11D5-9FF6-FFFFFF000000")]
public interface CPPCommandRequest : ICICPPCommandRequest
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("690928FC-CD3C-11D5-9FFA-FFFFFF000000")]
[ClassInterface(ClassInterfaceType.None)]
public class CPPCommandRequestClass : ICICPPCommandRequest, CPPCommandRequest, ICIRequest, ICIAssignMsgGroup
{
	[DispId(1)]
	public virtual extern int Timeout
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
	public virtual extern short Retries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	[DispId(3)]
	public virtual extern ReqProtocolEnum ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[DispId(4)]
	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	public virtual extern RequestTypeEnum ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	[DispId(5)]
	public virtual extern RequestStatusEnum ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	[DispId(6)]
	public virtual extern int ReqDataLength
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
	public virtual extern object ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(8)]
	public virtual extern int DclStatus
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
	public virtual extern string DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(100)]
	[ComAliasName("CILDCLDEVICECONTROLLib.CPPCommandEnum")]
	public virtual extern CPPCommandEnum Command
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.CPPCommandEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.CPPCommandEnum")]
		set;
	}

	[DispId(101)]
	[ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
	public virtual extern CPPInstProtocolEnum CppInstProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.CPPInstProtocolEnum")]
		set;
	}

	public virtual extern int ICIRequest_Timeout
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern short ICIRequest_Retries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	public virtual extern ReqProtocolEnum ICIRequest_ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	public virtual extern RequestTypeEnum ICIRequest_ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	public virtual extern RequestStatusEnum ICIRequest_ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	public virtual extern int ICIRequest_ReqDataLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern object ICIRequest_ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern int ICIRequest_DclStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern string ICIRequest_DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
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
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("40D3CE2F-D522-4C70-B143-A897A31229BF")]
public interface ICICLIPRequest : ICIRequest
{
	[DispId(1)]
	new int Timeout
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
	new short Retries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	[DispId(3)]
	new ReqProtocolEnum ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	[DispId(4)]
	new RequestTypeEnum ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[DispId(5)]
	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	new RequestStatusEnum ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	[DispId(6)]
	new int ReqDataLength
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
	new object ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(8)]
	new int DclStatus
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
	new string DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(100)]
	short ResponseCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		get;
	}

	[DispId(101)]
	string ResponseCodeDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(111)]
	void GetParametersByID([In][MarshalAs(UnmanagedType.Struct)] ref object parameters);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(112)]
	void SetParametersByID([In][MarshalAs(UnmanagedType.Struct)] ref object parametersAndData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(113)]
	void GetDataByAddress([In] int Address, [In] short length);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(114)]
	void SetDataByAddress([In] int Address, [In] short length, [In][MarshalAs(UnmanagedType.Struct)] ref object data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(115)]
	void GetAddressByParameterID([In] int parameterId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(116)]
	void ExecuteOperation([In] int operation, [In][MarshalAs(UnmanagedType.Struct)] ref object args);
}
[ComImport]
[Guid("BAD274D9-EEDE-4C6B-846A-76A6DE763B9E")]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
public interface _ICICLIPInterimResponseEvent
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void InterimResponseReceived([In] short lResponseCode, [In] double dblTimestamp, [In][MarshalAs(UnmanagedType.Struct)] object vtData);
}
[ComEventInterface(typeof(_ICICLIPInterimResponseEvent), typeof(_ICICLIPInterimResponseEvent_EventProvider))]
[ComVisible(false)]
[TypeLibType(TypeLibTypeFlags.FHidden)]
public interface _ICICLIPInterimResponseEvent_Event
{
	event _ICICLIPInterimResponseEvent_InterimResponseReceivedEventHandler InterimResponseReceived;
}
[ComImport]
[CoClass(typeof(CLIPRequestClass))]
[Guid("40D3CE2F-D522-4C70-B143-A897A31229BF")]
public interface CLIPRequest : ICICLIPRequest, _ICICLIPInterimResponseEvent_Event
{
}
[ComImport]
[Guid("85B813C4-F9D3-4D42-B43E-79DA9B2FC2EF")]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
public interface _ICICLIPFinalResponseEvent
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1001)]
	void FinalResponseReceived([In] short lResponseCode, [In] double dblTimestamp, [In][MarshalAs(UnmanagedType.Struct)] object vtData);
}
[ComVisible(false)]
[TypeLibType(TypeLibTypeFlags.FHidden)]
[ComEventInterface(typeof(_ICICLIPFinalResponseEvent), typeof(_ICICLIPFinalResponseEvent_EventProvider))]
public interface _ICICLIPFinalResponseEvent_Event
{
	event _ICICLIPFinalResponseEvent_FinalResponseReceivedEventHandler FinalResponseReceived;
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
[Guid("30297455-C5FD-47D2-9FFF-13F5A76ABDC0")]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
public interface _ICIRequestStatusEvent
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void RequestStatus([In][ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")] RequestStatusEnum RequestStatus);
}
[ComEventInterface(typeof(_ICIRequestStatusEvent), typeof(_ICIRequestStatusEvent_EventProvider))]
[TypeLibType(TypeLibTypeFlags.FHidden)]
[ComVisible(false)]
public interface _ICIRequestStatusEvent_Event
{
	event _ICIRequestStatusEvent_RequestStatusEventHandler RequestStatus;
}
[ComImport]
[ComSourceInterfaces("CILDCLDEVICECONTROLLib._ICICLIPInterimResponseEvent\0CILDCLDEVICECONTROLLib._ICICLIPFinalResponseEvent\0CILDCLDEVICECONTROLLib._ICIRequestStatusEvent\0\0")]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ClassInterface(ClassInterfaceType.None)]
[Guid("C9625A01-52B3-4DEC-9E4D-D49D553C7529")]
public class CLIPRequestClass : ICICLIPRequest, CLIPRequest, _ICICLIPInterimResponseEvent_Event, ICIRequest, ICIAssignMsgGroup, ICIRequest2, _ICICLIPFinalResponseEvent_Event, _ICIRequestStatusEvent_Event
{
	[DispId(1)]
	public virtual extern int Timeout
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
	public virtual extern short Retries
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
	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	public virtual extern ReqProtocolEnum ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[DispId(4)]
	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	public virtual extern RequestTypeEnum ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	[DispId(5)]
	public virtual extern RequestStatusEnum ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	[DispId(6)]
	public virtual extern int ReqDataLength
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
	public virtual extern object ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(8)]
	public virtual extern int DclStatus
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
	public virtual extern string DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(100)]
	public virtual extern short ResponseCode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		get;
	}

	[DispId(101)]
	public virtual extern string ResponseCodeDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIRequest_Timeout
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern short ICIRequest_Retries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	public virtual extern ReqProtocolEnum ICIRequest_ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	public virtual extern RequestTypeEnum ICIRequest_ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	public virtual extern RequestStatusEnum ICIRequest_ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	public virtual extern int ICIRequest_ReqDataLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern object ICIRequest_ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern int ICIRequest_DclStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern string ICIRequest_DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
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

	public virtual extern bool Asynchronous
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern event _ICICLIPInterimResponseEvent_InterimResponseReceivedEventHandler InterimResponseReceived;

	public virtual extern event _ICICLIPFinalResponseEvent_FinalResponseReceivedEventHandler FinalResponseReceived;

	public virtual extern event _ICIRequestStatusEvent_RequestStatusEventHandler RequestStatus;

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(111)]
	public virtual extern void GetParametersByID([In][MarshalAs(UnmanagedType.Struct)] ref object parameters);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(112)]
	public virtual extern void SetParametersByID([In][MarshalAs(UnmanagedType.Struct)] ref object parametersAndData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(113)]
	public virtual extern void GetDataByAddress([In] int Address, [In] short length);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(114)]
	public virtual extern void SetDataByAddress([In] int Address, [In] short length, [In][MarshalAs(UnmanagedType.Struct)] ref object data);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(115)]
	public virtual extern void GetAddressByParameterID([In] int parameterId);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(116)]
	public virtual extern void ExecuteOperation([In] int operation, [In][MarshalAs(UnmanagedType.Struct)] ref object args);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("BAD58356-C7B8-11D5-9FF6-FFFFFF000000")]
public interface ICIDCLDevice
{
	[DispId(1)]
	string Password
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.DeviceStateEnum")]
	[DispId(2)]
	DeviceStateEnum State
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.DeviceStateEnum")]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void Open([In][MarshalAs(UnmanagedType.BStr)] string configuration);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void Process([In][MarshalAs(UnmanagedType.Interface)] ICIRequest request);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void Close();

	[DispId(6)]
	string DeviceConfiguration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(7)]
	string DeviceInfo
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[Guid("BAD58356-C7B8-11D5-9FF6-FFFFFF000000")]
[CoClass(typeof(DCLDeviceClass))]
public interface DCLDevice : ICIDCLDevice
{
}
[ComImport]
[Guid("CB6101B1-7D3F-11D6-BE2F-00062930B735")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIMailboxManager
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(71)]
	void latOpen([In][MarshalAs(UnmanagedType.BStr)] string latConfiguration);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(72)]
	void latClose();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(73)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ReceiveMailbox createReceiveMailbox([In] int bEnableTimeStamp);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(74)]
	[return: MarshalAs(UnmanagedType.Interface)]
	TransmitMailbox createTransmitMailbox();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(75)]
	void latAddress([MarshalAs(UnmanagedType.BStr)] out string localAddress, [MarshalAs(UnmanagedType.BStr)] out string remoteAddress, out uint localAddressTag);

	[DispId(76)]
	string latInfo
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(76)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[Guid("011B7A49-1A36-4CD2-AB35-7788B3B7215F")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICICLIPSession
{
	[DispId(2)]
	ICIDictionary ToolContext
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(3)]
	ICIDictionary RemoteContext
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(4)]
	string configuration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(5)]
	int MaximumSendLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	void Connect([In][MarshalAs(UnmanagedType.Interface)] ICIDictionary ToolContext, [In][MarshalAs(UnmanagedType.BStr)] string configuration);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	void Disconnect();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICICLIPSession CreateNewSession();
}
[ComImport]
[Guid("B77B2A0B-E845-431B-819B-7D3BA447E254")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICICLIPSession2
{
	[DispId(300)]
	string ToolContext
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(300)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(301)]
	string RemoteContext
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(301)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(302)]
	string configuration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(302)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(303)]
	int MaximumSendLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(303)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(304)]
	void Connect([In][MarshalAs(UnmanagedType.BStr)] string ToolContext, [In][MarshalAs(UnmanagedType.BStr)] string configuration);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(305)]
	void Disconnect(bool sendClose);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(306)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICICLIPSession2 CreateNewSession();
}
[ComImport]
[Guid("6487306D-89D3-4D46-BAFE-142F500F2EA0")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIConfiguration
{
	[DispId(500)]
	string configuration
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
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("2E176C43-2D11-4FBD-980F-F90728C2096C")]
public interface ICIRP1210Command
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(300)]
	void RP1210SendCommand([In] short commandnumber, [In][MarshalAs(UnmanagedType.Struct)] object clientcommand);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate | TypeLibTypeFlags.FLicensed)]
[ClassInterface(ClassInterfaceType.None)]
[Guid("BAD58357-C7B8-11D5-9FF6-FFFFFF000000")]
public class DCLDeviceClass : ICIDCLDevice, DCLDevice, ICIAssignMsgGroup, ICIMailboxManager, ICICLIPSession, ICICLIPSession2, ICIConfiguration, ICIRP1210Command
{
	[DispId(1)]
	public virtual extern string Password
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.DeviceStateEnum")]
	[DispId(2)]
	public virtual extern DeviceStateEnum State
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.DeviceStateEnum")]
		get;
	}

	[DispId(6)]
	public virtual extern string DeviceConfiguration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(7)]
	public virtual extern string DeviceInfo
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
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

	public virtual extern string latInfo
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern ICIDictionary ToolContext
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern ICIDictionary RemoteContext
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern string configuration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int MaximumSendLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern string ICICLIPSession2_ToolContext
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICICLIPSession2_RemoteContext
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICICLIPSession2_configuration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICICLIPSession2_MaximumSendLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern string ICIConfiguration_configuration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	public virtual extern void Open([In][MarshalAs(UnmanagedType.BStr)] string configuration);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	public virtual extern void Process([In][MarshalAs(UnmanagedType.Interface)] ICIRequest request);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void Close();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void latOpen([In][MarshalAs(UnmanagedType.BStr)] string latConfiguration);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void latClose();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ReceiveMailbox createReceiveMailbox([In] int bEnableTimeStamp);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern TransmitMailbox createTransmitMailbox();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void latAddress([MarshalAs(UnmanagedType.BStr)] out string localAddress, [MarshalAs(UnmanagedType.BStr)] out string remoteAddress, out uint localAddressTag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void Connect([In][MarshalAs(UnmanagedType.Interface)] ICIDictionary ToolContext, [In][MarshalAs(UnmanagedType.BStr)] string configuration);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void Disconnect();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICLIPSession CreateNewSession();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void Connect([In][MarshalAs(UnmanagedType.BStr)] string ToolContext, [In][MarshalAs(UnmanagedType.BStr)] string configuration);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void Disconnect(bool sendClose);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICLIPSession2 ICICLIPSession2_CreateNewSession();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void RP1210SendCommand([In] short commandnumber, [In][MarshalAs(UnmanagedType.Struct)] object clientcommand);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("9C5B5DE5-6F19-11D6-BE2C-00062930B735")]
public interface ICITransmitMailbox
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	void Destroy();

	[DispId(11)]
	int Enable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	void Empty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	void Transmit([In] int headerVal, [In][MarshalAs(UnmanagedType.Struct)] object vData, [In] int dataLength);

	[DispId(14)]
	int MessageCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		get;
	}

	[DispId(15)]
	int Timeout
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		[param: In]
		set;
	}

	[DispId(16)]
	short Retry
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[param: In]
		set;
	}
}
[ComImport]
[Guid("9C5B5DE5-6F19-11D6-BE2C-00062930B735")]
[CoClass(typeof(TransmitMailboxClass))]
public interface TransmitMailbox : ICITransmitMailbox
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("9C5B5DE6-6F19-11D6-BE2C-00062930B735")]
[ClassInterface(ClassInterfaceType.None)]
public class TransmitMailboxClass : ICITransmitMailbox, TransmitMailbox, ICIAssignMsgGroup
{
	[DispId(11)]
	public virtual extern int Enable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[param: In]
		set;
	}

	[DispId(14)]
	public virtual extern int MessageCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		get;
	}

	[DispId(15)]
	public virtual extern int Timeout
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		[param: In]
		set;
	}

	[DispId(16)]
	public virtual extern short Retry
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
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
	[DispId(10)]
	public virtual extern void Destroy();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	public virtual extern void Empty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	public virtual extern void Transmit([In] int headerVal, [In][MarshalAs(UnmanagedType.Struct)] object vData, [In] int dataLength);
}
[ComImport]
[Guid("72E209F2-749C-11D6-BE2C-00062930B735")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIReceiveMailbox
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	void Destroy();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	void Empty();

	[DispId(43)]
	int Enable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(43)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(43)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	void SetReceiveMode([In][ComAliasName("CILDCLDEVICECONTROLLib.ReceiveModeEnum")] ReceiveModeEnum mode);

	[DispId(45)]
	int MessageCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(45)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	void SetOpenFilter();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	void SetProprietaryFilter([In] uint rmbFilter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(48)]
	void SetConnectMgmtFilter([In] uint rmbFilter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	void SetDataTransportFilter([In] uint rmbFilter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	void SetMaskMatchFilter([In] uint rmbMask, [In] uint rmbFilter);
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
[Guid("EAFFB851-8234-11D6-BE30-00062930B735")]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
public interface _ICIReceiveMailboxEvent
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(80)]
	void ReceiveMailboxMessage([In][MarshalAs(UnmanagedType.Struct)] object pHeader, [In][MarshalAs(UnmanagedType.Struct)] object pPacketData, [In] uint timeStamp);
}
[ComVisible(false)]
[TypeLibType(TypeLibTypeFlags.FHidden)]
[ComEventInterface(typeof(_ICIReceiveMailboxEvent), typeof(_ICIReceiveMailboxEvent_EventProvider))]
public interface _ICIReceiveMailboxEvent_Event
{
	event _ICIReceiveMailboxEvent_ReceiveMailboxMessageEventHandler ReceiveMailboxMessage;
}
[ComImport]
[Guid("72E209F2-749C-11D6-BE2C-00062930B735")]
[CoClass(typeof(ReceiveMailboxClass))]
public interface ReceiveMailbox : ICIReceiveMailbox, _ICIReceiveMailboxEvent_Event
{
}
[ComImport]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ComSourceInterfaces("CILDCLDEVICECONTROLLib._ICIReceiveMailboxEvent\0\0")]
[Guid("72E209F3-749C-11D6-BE2C-00062930B735")]
public class ReceiveMailboxClass : ICIReceiveMailbox, ReceiveMailbox, _ICIReceiveMailboxEvent_Event, ICIAssignMsgGroup
{
	[DispId(43)]
	public virtual extern int Enable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(43)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(43)]
		[param: In]
		set;
	}

	[DispId(45)]
	public virtual extern int MessageCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(45)]
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

	public virtual extern event _ICIReceiveMailboxEvent_ReceiveMailboxMessageEventHandler ReceiveMailboxMessage;

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	public virtual extern void Destroy();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	public virtual extern void Empty();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	public virtual extern void SetReceiveMode([In][ComAliasName("CILDCLDEVICECONTROLLib.ReceiveModeEnum")] ReceiveModeEnum mode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	public virtual extern void SetOpenFilter();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	public virtual extern void SetProprietaryFilter([In] uint rmbFilter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(48)]
	public virtual extern void SetConnectMgmtFilter([In] uint rmbFilter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	public virtual extern void SetDataTransportFilter([In] uint rmbFilter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	public virtual extern void SetMaskMatchFilter([In] uint rmbMask, [In] uint rmbFilter);
}
[ComImport]
[CoClass(typeof(CIConfigurationClass))]
[Guid("6487306D-89D3-4D46-BAFE-142F500F2EA0")]
public interface CIConfiguration : ICIConfiguration
{
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("94A1024D-74EA-4446-B027-19CD0E837FE5")]
[DefaultMember("GetConfigurationData")]
public interface ICIConfigurationData
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetConfigurationData([In][MarshalAs(UnmanagedType.BStr)] string xmlConfiguration);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ClassInterface(ClassInterfaceType.None)]
[DefaultMember("GetConfigurationData")]
[Guid("EF49BD7E-EBDA-4426-B778-7B18BAA8BAA7")]
public class CIConfigurationClass : ICIConfiguration, CIConfiguration, ICIConfigurationData
{
	[DispId(500)]
	public virtual extern string configuration
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

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object GetConfigurationData([In][MarshalAs(UnmanagedType.BStr)] string xmlConfiguration);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("D580DDEA-354D-4CF2-A8E1-EB1330A270AF")]
public interface ICIWoodwardRequest : ICIRequest
{
	[DispId(1)]
	new int Timeout
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
	new short Retries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	[DispId(3)]
	new ReqProtocolEnum ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[DispId(4)]
	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	new RequestTypeEnum ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	[DispId(5)]
	new RequestStatusEnum ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	[DispId(6)]
	new int ReqDataLength
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
	new object ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(8)]
	new int DclStatus
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
	new string DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(200)]
	int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(200)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(200)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.WoodwardRecordTypeEnum")]
	[DispId(201)]
	WoodwardRecordTypeEnum RecordType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.WoodwardRecordTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.WoodwardRecordTypeEnum")]
		set;
	}

	[DispId(202)]
	[ComAliasName("CILDCLDEVICECONTROLLib.WoodwardMethodEnum")]
	WoodwardMethodEnum WoodwardRWType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.WoodwardMethodEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.WoodwardMethodEnum")]
		set;
	}

	[DispId(203)]
	int Offset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(203)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(203)]
		[param: In]
		set;
	}

	[DispId(204)]
	int MessageID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(204)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(204)]
		[param: In]
		set;
	}

	[DispId(205)]
	int Location
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(205)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(205)]
		[param: In]
		set;
	}
}
[ComImport]
[Guid("D580DDEA-354D-4CF2-A8E1-EB1330A270AF")]
[CoClass(typeof(WoodwardRequestClass))]
public interface WoodwardRequest : ICIWoodwardRequest
{
}
[ComImport]
[ClassInterface(ClassInterfaceType.None)]
[Guid("1869928B-E0CB-444D-8389-D68B83FBEF57")]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class WoodwardRequestClass : ICIWoodwardRequest, WoodwardRequest, ICIRequest, ICIAssignMsgGroup
{
	[DispId(1)]
	public virtual extern int Timeout
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
	public virtual extern short Retries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	[DispId(3)]
	public virtual extern ReqProtocolEnum ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[DispId(4)]
	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	public virtual extern RequestTypeEnum ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	[DispId(5)]
	public virtual extern RequestStatusEnum ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	[DispId(6)]
	public virtual extern int ReqDataLength
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
	public virtual extern object ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(8)]
	public virtual extern int DclStatus
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
	public virtual extern string DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(200)]
	public virtual extern int length
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(200)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(200)]
		[param: In]
		set;
	}

	[DispId(201)]
	[ComAliasName("CILDCLDEVICECONTROLLib.WoodwardRecordTypeEnum")]
	public virtual extern WoodwardRecordTypeEnum RecordType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.WoodwardRecordTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.WoodwardRecordTypeEnum")]
		set;
	}

	[DispId(202)]
	[ComAliasName("CILDCLDEVICECONTROLLib.WoodwardMethodEnum")]
	public virtual extern WoodwardMethodEnum WoodwardRWType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.WoodwardMethodEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.WoodwardMethodEnum")]
		set;
	}

	[DispId(203)]
	public virtual extern int Offset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(203)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(203)]
		[param: In]
		set;
	}

	[DispId(204)]
	public virtual extern int MessageID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(204)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(204)]
		[param: In]
		set;
	}

	[DispId(205)]
	public virtual extern int Location
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(205)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(205)]
		[param: In]
		set;
	}

	public virtual extern int ICIRequest_Timeout
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern short ICIRequest_Retries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
	public virtual extern ReqProtocolEnum ICIRequest_ReqProtocol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.ReqProtocolEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
	public virtual extern RequestTypeEnum ICIRequest_ReqType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestTypeEnum")]
		set;
	}

	[ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
	public virtual extern RequestStatusEnum ICIRequest_ReqStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")]
		set;
	}

	public virtual extern int ICIRequest_ReqDataLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern object ICIRequest_ReqData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern int ICIRequest_DclStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern string ICIRequest_DclStatusDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
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
}
public enum ReqProtocolEnum
{
	REQUEST_CPP = 1,
	REQUEST_BINARY,
	REQUEST_CLIP,
	REQUEST_Woodward
}
public enum RequestTypeEnum
{
	DEVCTRL_READ = 1,
	DEVCTRL_WRITE,
	DEVCTRL_COMMAND,
	DEVCTRL_CLIP,
	DEVCTRL_SET,
	DEVCTRL_UNKNOWN
}
public enum RequestStatusEnum
{
	REQUEST_SUCCESS = 1,
	REQUEST_FAIL,
	REQUEST_PROCESSING,
	REQUEST_NEED_PROCESS
}
public enum CPPWriteTypeEnum
{
	CPP_WRITE_DATA_BY_NTN = 1,
	CPP_WRITE_BY_NTN_OFFSET,
	CPP_WRITE_ADDR_AT_NTN,
	CPP_WRITE_DATA_BY_ADDR,
	CPP_WRITE_DATA_BY_OPT
}
public enum CPPWriteMethodEnum
{
	CPP_WRITE_DEVELOP_MEM = 1,
	CPP_WRITE_SECURE_DATA,
	CPP_WRITE_SCRATCH_MEM,
	CPP_WRITE_SCRATCH_CRC_SWAP,
	CPP_WRITE_AUTOMATIC
}
public enum CPPInstProtocolEnum
{
	DEVCTRL_CPPJ1708_16 = 1,
	DEVCTRL_CPPJ1708_16_NOCRC,
	DEVCTRL_CPPJ1708_32,
	DEVCTRL_CPPJ1939,
	DEVCTRL_DEFAULT_INSTRUCTION_PROTOCOL
}
public enum CPPReadTypeEnum
{
	CPP_GET_DATA_BY_NTN = 1,
	CPP_GET_DATA_BY_NTN_OFFSET,
	CPP_GET_ADDR_AT_NTN,
	CPP_GET_DATA_BY_ADDR,
	CPP_GET_DATA_BY_OPT
}
public enum CPPCommandEnum
{
	CPP_ERASE_INACT_FAULTS = 1,
	CPP_ERASE_DEF_CAL = 2,
	CPP_ERASE_ACT_FAULTS = 3,
	CPP_STOP_BROADCAST = 4,
	CPP_START_BROADCAST = 5,
	CPP_STOP_EXECUTION = 6,
	CPP_RUN_DEF_CODE_AND_DATA = 7,
	CPP_RUN_DEV_CODE_AND_DATA = 8,
	CPP_RUN_DEV_CODE = 9,
	CPP_RUN_DEV_DATA = 10,
	CPP_RUN_BOOT_LOADER = 11,
	CPP_PING = 12,
	CPP_REQUEST_ACK = 13,
	CPP_CPY_DEF_COD_AND_DATA_FROM_DEV = 14,
	CPP_CPY_DEV_COD_AND_DATA_FROM_DEF = 15,
	CPP_CPY_DEF_COD_FROM_DEV = 16,
	CPP_CPY_DEV_COD_FROM_DEF = 17,
	CPP_CPY_DEF_DATA_FROM_DEV = 18,
	CPP_CPY_DEV_DATA_FROM_DEF = 19,
	CPP_WRITE_SCRATCH_PAD = 20,
	CPP_PREPARE_CAL_DOWNLOAD = 21,
	CPP_JUMP_TO_ABSOLUTE_ADDRESS = 22,
	CPP_ERASE_BLOCK_OF_MEMORY = 23,
	CPP_START_PRIVATE_BROADCAST = 25,
	CPP_START_FAST_PUBLIC_BROADCAST = 26,
	CPP_START_FAST_PRIVATE_BROADCAST = 27,
	CPP_SHUTDOWN_ENGINE = 28,
	CPP_ALLOW_ENGINE_RESTART = 29,
	CPP_SAVE_EE_SETPOINTS = 30,
	CPP_COPY_REFRESH_RAM_TO_EE = 31,
	CPP_CHANGE_TO_19200 = 32
}
[TypeLibType(TypeLibTypeFlags.FHidden)]
[ComVisible(false)]
public delegate void _ICICLIPInterimResponseEvent_InterimResponseReceivedEventHandler([In] short lResponseCode, [In] double dblTimestamp, [In][MarshalAs(UnmanagedType.Struct)] object vtData);
public enum DeviceStateEnum
{
	DEVCTRL_OPEN = 1,
	DEVCTRL_CLOSE,
	DEVCTRL_PROCESSING,
	DEVCTRL_UNINITIALIZE
}
public enum ReceiveModeEnum
{
	DEVCTRL_RMB_ONE_SHOT = 1,
	DEVCTRL_RMB_CONTINUOUS_NEW,
	DEVCTRL_RMB_CONTINUOUS_OLD
}
[TypeLibType(TypeLibTypeFlags.FHidden)]
[ComVisible(false)]
public delegate void _ICIReceiveMailboxEvent_ReceiveMailboxMessageEventHandler([In][MarshalAs(UnmanagedType.Struct)] object pHeader, [In][MarshalAs(UnmanagedType.Struct)] object pPacketData, [In] uint timeStamp);
public enum WoodwardRecordTypeEnum
{
	Woodward_DATA_REC_0,
	Woodward_EOF_0,
	Woodward_EXT_ADDR_0,
	Woodward_START_ADDR_0,
	Woodward_REQ_BOOT_BLK_VER,
	Woodward_REQ_BOOT_BLK_CS,
	Woodward_RESTART_CONTROL,
	Woodward_REQ_FLASH_CS,
	Woodward_ERASE_FLASH,
	Woodward_SHUTDOWN_ENGINE,
	Woodward_REQ_NUM_BANKS,
	Woodward_DATA_REC_1,
	Woodward_EOF_1,
	Woodward_EXT_ADDR_1,
	Woodward_START_ADDR_1,
	Woodward_DATA_REC_2,
	Woodward_EOF_2,
	Woodward_EXT_ADDR_2,
	Woodward_START_ADDR_2,
	Woodward_DATA_REC_3,
	Woodward_EOF_3,
	Woodward_EXT_ADDR_3,
	Woodward_START_ADDR_3,
	Woodward_DATA_REC_ACK_0,
	Woodward_DATA_REC_ACK_1,
	Woodward_DATA_REC_ACK_2,
	Woodward_DATA_REC_ACK_3
}
public enum WoodwardMethodEnum
{
	Woodward_RW_ABLS = 1,
	Woodward_RW_PARAM,
	Woodward_RW_RECORD
}
public enum DeviceControlMsgEnum
{
	MSG_DIAG_DATAREADFAIL = 2,
	MSG_DIAG_DATAWRITEFAIL = 3,
	MSG_DIAG_COMMANDFAILED = 4,
	MSG_DIAG_CONNECTCLOSED = 5,
	MSG_DIAG_OTHERERROR = 6,
	MSG_DIAG_OPENCLOSELINKFAIL = 7,
	MSG_DIAG_MESSAGETRANSFAIL = 8,
	MSG_DIAG_RECMESSAGEFAIL = 9,
	MSG_DIAG_DEVOPENFAIL = 10,
	MSG_DIAG_DEVCHLOCALADDR = 11,
	MSG_PROG_OPENDEVSUCCESS = 101,
	MSG_PROG_CLOSEDEVSUCCESS = 102,
	MSG_PROG_EXECCOMMRESP = 103,
	MSG_DIAG_CLIP_NETWORK = 48,
	MSG_DIAG_CLIP_SESSION_OPENED = 62,
	MSG_DIAG_CLIP_SESSION_CLOSED = 63,
	MSG_DIAG_CLIP_SESSION_OPENFAIL = 64,
	MSG_DIAG_CLIP_SESSION_ENCRYPTIONERROR = 65,
	MSG_DIAG_CLIP_SESSION_DECRYPTIONERROR = 66,
	MSG_DIAG_CLIP_TRANSPORT_OPEN = 80,
	MSG_DIAG_CLIP_TRANSPORT_CLOSE = 81,
	MSG_DIAG_CLIP_TRANSPORT_SEQHARDERR = 82,
	MSG_DIAG_CLIP_TRANSPORT_SEQSOFTERR = 83,
	MSG_DIAG_CLIP_TRANSPORT_OPENFAIL = 84,
	MSG_DIAG_CLIP_TRANSPORT_NOSESSION = 85,
	MSG_DIAG_CLIP_INSTRUCTION_ERROR = 96,
	MSG_PROG_CLIP_INSTRUCTION_DATARECV = 1,
	MSG_DIAG_CONNECTION_REESTABLISHED = 97,
	MSG_DIAG_CONNECTION_LOST = 98,
	MSG_DIAG_RECONNECTION_IN_PROGRESS = 99,
	MSG_DIAG_AUTORECONNECT_FAILED = 100,
	MSG_DIAG_AR_REGISTRATION_FAILED = 111,
	MSG_DIAG_AR_UNREGISTRATION_FAILED = 112,
	MSG_DIAG_AR_ABORT_FAILED = 113,
	MSG_DIAG_RP1210_SENDCOMMAND_SUCCESS = 116,
	MSG_DIAG_RP1210_SENDCOMMAND_FAILED = 117,
	MSG_DIAG_ABORT_DUE_TO_DCL_RECEIVE_ERROR = 118,
	MSG_DIAG_ABORT_DUE_TO_UNEXPECTED_DATA_PACKET_RECEIVED = 119,
	MSG_DIAG_DATA_PACKET_WITH_SEQUENCE_NO_GREATER_THAN_EXPECTED_RECEIVED_HENCE_ABORT = 120,
	MSG_DIAG_RE_CTS_SENT_DUE_TO_MISSED_PACKET = 121,
	MSG_DIAG_DCL_TRANSPORT_ABORTED_BY_REMOTE_NODE = 122,
	MSG_DIAG_ABORT_AS_INVALID_RTS_RECEIVED = 123,
	MSG_DIAG_ERROR_SENDING_DATA = 124,
	MSG_DIAG_DCL_TRANSMIT_OR_TIMEOUT_ERROR = 125,
	MSG_DIAG_CTS_WITH_ZERO_PACKETS_RECEIVED = 126,
	MSG_DIAG_CAN_BUS_OFF = 127,
	MSG_DIAG_CAN_BUS_HEAVY = 128,
	MSG_DIAG_CAN_BUS_LIGHT = 129
}
public enum tagDeviceControlMsgEnum
{
	MSG_DIAG_DATAREADFAIL = 2,
	MSG_DIAG_DATAWRITEFAIL = 3,
	MSG_DIAG_COMMANDFAILED = 4,
	MSG_DIAG_CONNECTCLOSED = 5,
	MSG_DIAG_OTHERERROR = 6,
	MSG_DIAG_OPENCLOSELINKFAIL = 7,
	MSG_DIAG_MESSAGETRANSFAIL = 8,
	MSG_DIAG_RECMESSAGEFAIL = 9,
	MSG_DIAG_DEVOPENFAIL = 10,
	MSG_DIAG_DEVCHLOCALADDR = 11,
	MSG_PROG_OPENDEVSUCCESS = 101,
	MSG_PROG_CLOSEDEVSUCCESS = 102,
	MSG_PROG_EXECCOMMRESP = 103,
	MSG_DIAG_CLIP_NETWORK = 48,
	MSG_DIAG_CLIP_SESSION_OPENED = 62,
	MSG_DIAG_CLIP_SESSION_CLOSED = 63,
	MSG_DIAG_CLIP_SESSION_OPENFAIL = 64,
	MSG_DIAG_CLIP_SESSION_ENCRYPTIONERROR = 65,
	MSG_DIAG_CLIP_SESSION_DECRYPTIONERROR = 66,
	MSG_DIAG_CLIP_TRANSPORT_OPEN = 80,
	MSG_DIAG_CLIP_TRANSPORT_CLOSE = 81,
	MSG_DIAG_CLIP_TRANSPORT_SEQHARDERR = 82,
	MSG_DIAG_CLIP_TRANSPORT_SEQSOFTERR = 83,
	MSG_DIAG_CLIP_TRANSPORT_OPENFAIL = 84,
	MSG_DIAG_CLIP_TRANSPORT_NOSESSION = 85,
	MSG_DIAG_CLIP_INSTRUCTION_ERROR = 96,
	MSG_PROG_CLIP_INSTRUCTION_DATARECV = 1,
	MSG_DIAG_CONNECTION_REESTABLISHED = 97,
	MSG_DIAG_CONNECTION_LOST = 98,
	MSG_DIAG_RECONNECTION_IN_PROGRESS = 99,
	MSG_DIAG_AUTORECONNECT_FAILED = 100,
	MSG_DIAG_AR_REGISTRATION_FAILED = 111,
	MSG_DIAG_AR_UNREGISTRATION_FAILED = 112,
	MSG_DIAG_AR_ABORT_FAILED = 113,
	MSG_DIAG_RP1210_SENDCOMMAND_SUCCESS = 116,
	MSG_DIAG_RP1210_SENDCOMMAND_FAILED = 117,
	MSG_DIAG_ABORT_DUE_TO_DCL_RECEIVE_ERROR = 118,
	MSG_DIAG_ABORT_DUE_TO_UNEXPECTED_DATA_PACKET_RECEIVED = 119,
	MSG_DIAG_DATA_PACKET_WITH_SEQUENCE_NO_GREATER_THAN_EXPECTED_RECEIVED_HENCE_ABORT = 120,
	MSG_DIAG_RE_CTS_SENT_DUE_TO_MISSED_PACKET = 121,
	MSG_DIAG_DCL_TRANSPORT_ABORTED_BY_REMOTE_NODE = 122,
	MSG_DIAG_ABORT_AS_INVALID_RTS_RECEIVED = 123,
	MSG_DIAG_ERROR_SENDING_DATA = 124,
	MSG_DIAG_DCL_TRANSMIT_OR_TIMEOUT_ERROR = 125,
	MSG_DIAG_CTS_WITH_ZERO_PACKETS_RECEIVED = 126,
	MSG_DIAG_CAN_BUS_OFF = 127,
	MSG_DIAG_CAN_BUS_HEAVY = 128,
	MSG_DIAG_CAN_BUS_LIGHT = 129
}
public enum tagDeviceStateEnum
{
	DEVCTRL_OPEN = 1,
	DEVCTRL_CLOSE,
	DEVCTRL_PROCESSING,
	DEVCTRL_UNINITIALIZE
}
public enum tagReqProtocolEnum
{
	REQUEST_CPP = 1,
	REQUEST_BINARY,
	REQUEST_CLIP,
	REQUEST_Woodward
}
public enum tagRequestTypeEnum
{
	DEVCTRL_READ = 1,
	DEVCTRL_WRITE,
	DEVCTRL_COMMAND,
	DEVCTRL_CLIP,
	DEVCTRL_SET,
	DEVCTRL_UNKNOWN
}
public enum tagRequestStatusEnum
{
	REQUEST_SUCCESS = 1,
	REQUEST_FAIL,
	REQUEST_PROCESSING,
	REQUEST_NEED_PROCESS
}
public enum tagCPPReadTypeEnum
{
	CPP_GET_DATA_BY_NTN = 1,
	CPP_GET_DATA_BY_NTN_OFFSET,
	CPP_GET_ADDR_AT_NTN,
	CPP_GET_DATA_BY_ADDR,
	CPP_GET_DATA_BY_OPT
}
public enum tagCPPInstProtocolEnum
{
	DEVCTRL_CPPJ1708_16 = 1,
	DEVCTRL_CPPJ1708_16_NOCRC,
	DEVCTRL_CPPJ1708_32,
	DEVCTRL_CPPJ1939,
	DEVCTRL_DEFAULT_INSTRUCTION_PROTOCOL
}
public enum tagCPPWriteTypeEnum
{
	CPP_WRITE_DATA_BY_NTN = 1,
	CPP_WRITE_BY_NTN_OFFSET,
	CPP_WRITE_ADDR_AT_NTN,
	CPP_WRITE_DATA_BY_ADDR,
	CPP_WRITE_DATA_BY_OPT
}
public enum tagCPPWriteMethodEnum
{
	CPP_WRITE_DEVELOP_MEM = 1,
	CPP_WRITE_SECURE_DATA,
	CPP_WRITE_SCRATCH_MEM,
	CPP_WRITE_SCRATCH_CRC_SWAP,
	CPP_WRITE_AUTOMATIC
}
public enum tagCPPCommandEnum
{
	CPP_ERASE_INACT_FAULTS = 1,
	CPP_ERASE_DEF_CAL = 2,
	CPP_ERASE_ACT_FAULTS = 3,
	CPP_STOP_BROADCAST = 4,
	CPP_START_BROADCAST = 5,
	CPP_STOP_EXECUTION = 6,
	CPP_RUN_DEF_CODE_AND_DATA = 7,
	CPP_RUN_DEV_CODE_AND_DATA = 8,
	CPP_RUN_DEV_CODE = 9,
	CPP_RUN_DEV_DATA = 10,
	CPP_RUN_BOOT_LOADER = 11,
	CPP_PING = 12,
	CPP_REQUEST_ACK = 13,
	CPP_CPY_DEF_COD_AND_DATA_FROM_DEV = 14,
	CPP_CPY_DEV_COD_AND_DATA_FROM_DEF = 15,
	CPP_CPY_DEF_COD_FROM_DEV = 16,
	CPP_CPY_DEV_COD_FROM_DEF = 17,
	CPP_CPY_DEF_DATA_FROM_DEV = 18,
	CPP_CPY_DEV_DATA_FROM_DEF = 19,
	CPP_WRITE_SCRATCH_PAD = 20,
	CPP_PREPARE_CAL_DOWNLOAD = 21,
	CPP_JUMP_TO_ABSOLUTE_ADDRESS = 22,
	CPP_ERASE_BLOCK_OF_MEMORY = 23,
	CPP_START_PRIVATE_BROADCAST = 25,
	CPP_START_FAST_PUBLIC_BROADCAST = 26,
	CPP_START_FAST_PRIVATE_BROADCAST = 27,
	CPP_SHUTDOWN_ENGINE = 28,
	CPP_ALLOW_ENGINE_RESTART = 29,
	CPP_SAVE_EE_SETPOINTS = 30,
	CPP_COPY_REFRESH_RAM_TO_EE = 31,
	CPP_CHANGE_TO_19200 = 32
}
[ComImport]
[Guid("BF32628A-D104-45FF-8539-BCD450D1C8BA")]
[ComConversionLoss]
[TypeLibType(TypeLibTypeFlags.FHidden | TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIDictionary
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(0)]
	void let_Item([In][MarshalAs(UnmanagedType.Struct)] ref object Key, [In][MarshalAs(UnmanagedType.Struct)] ref object pRetItem);

	[DispId(0)]
	object this[[In][MarshalAs(UnmanagedType.Struct)] ref object Key]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void Add([In][MarshalAs(UnmanagedType.Struct)] ref object Key, [In][MarshalAs(UnmanagedType.Struct)] ref object Item);

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	bool Exists([In][MarshalAs(UnmanagedType.Struct)] ref object Key);

	[DispId(5)]
	IntPtr Key
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object Keys();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void Remove([In][MarshalAs(UnmanagedType.Struct)] ref object Key);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void RemoveAll();
}
[ComImport]
[Guid("121B7434-5E41-4D78-995E-1516E6D7B9E8")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[DefaultMember("CLIPData")]
public interface ICICLIPRequestData
{
	[DispId(0)]
	tagCICLIPRequestDataStruct CLIPData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}
}
[StructLayout(LayoutKind.Sequential, Pack = 8)]
public struct tagCICLIPRequestDataStruct
{
	public tagCICLIPInstructionEnum instruction;

	[MarshalAs(UnmanagedType.Struct)]
	public object data;

	public uint Address;

	public uint operationID;

	public uint parameterId;

	public ushort length;

	public ushort ResponseCode;
}
public enum tagCICLIPInstructionEnum
{
	GetParametersByID = 16,
	SetParametersByID,
	ExecuteOperation,
	GetDataByAddress,
	SetDataByAddress,
	GetAddressByParameterID
}
public enum tagWoodwardRecordTypeEnum
{
	Woodward_DATA_REC_0,
	Woodward_EOF_0,
	Woodward_EXT_ADDR_0,
	Woodward_START_ADDR_0,
	Woodward_REQ_BOOT_BLK_VER,
	Woodward_REQ_BOOT_BLK_CS,
	Woodward_RESTART_CONTROL,
	Woodward_REQ_FLASH_CS,
	Woodward_ERASE_FLASH,
	Woodward_SHUTDOWN_ENGINE,
	Woodward_REQ_NUM_BANKS,
	Woodward_DATA_REC_1,
	Woodward_EOF_1,
	Woodward_EXT_ADDR_1,
	Woodward_START_ADDR_1,
	Woodward_DATA_REC_2,
	Woodward_EOF_2,
	Woodward_EXT_ADDR_2,
	Woodward_START_ADDR_2,
	Woodward_DATA_REC_3,
	Woodward_EOF_3,
	Woodward_EXT_ADDR_3,
	Woodward_START_ADDR_3,
	Woodward_DATA_REC_ACK_0,
	Woodward_DATA_REC_ACK_1,
	Woodward_DATA_REC_ACK_2,
	Woodward_DATA_REC_ACK_3
}
public enum tagWoodwardMethodEnum
{
	Woodward_RW_ABLS = 1,
	Woodward_RW_PARAM,
	Woodward_RW_RECORD
}
public enum tagReceiveModeEnum
{
	DEVCTRL_RMB_ONE_SHOT = 1,
	DEVCTRL_RMB_CONTINUOUS_NEW,
	DEVCTRL_RMB_CONTINUOUS_OLD
}
[ComVisible(false)]
[TypeLibType(TypeLibTypeFlags.FHidden)]
public delegate void _ICICLIPFinalResponseEvent_FinalResponseReceivedEventHandler([In] short lResponseCode, [In] double dblTimestamp, [In][MarshalAs(UnmanagedType.Struct)] object vtData);
[TypeLibType(TypeLibTypeFlags.FHidden)]
[ComVisible(false)]
public delegate void _ICIRequestStatusEvent_RequestStatusEventHandler([In][ComAliasName("CILDCLDEVICECONTROLLib.RequestStatusEnum")] RequestStatusEnum RequestStatus);
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FHidden)]
public sealed class _ICICLIPInterimResponseEvent_SinkHelper : _ICICLIPInterimResponseEvent
{
	public _ICICLIPInterimResponseEvent_InterimResponseReceivedEventHandler m_InterimResponseReceivedDelegate;

	public int m_dwCookie;

	public void InterimResponseReceived(short P_0, double P_1, object P_2)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_InterimResponseReceivedDelegate != null)
		{
			m_InterimResponseReceivedDelegate(P_0, P_1, P_2);
		}
	}

	internal _ICICLIPInterimResponseEvent_SinkHelper()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_dwCookie = 0;
		m_InterimResponseReceivedDelegate = null;
	}
}
internal sealed class _ICICLIPInterimResponseEvent_EventProvider : _ICICLIPInterimResponseEvent_Event, IDisposable
{
	private WeakReference m_wkConnectionPointContainer;

	private ArrayList m_aEventSinkHelpers;

	private IConnectionPoint m_ConnectionPoint;

	private void Init()
	{
		IConnectionPoint ppCP = null;
		Guid riid = new Guid(new byte[16]
		{
			217, 116, 210, 186, 222, 238, 107, 76, 132, 106,
			118, 166, 222, 118, 59, 158
		});
		((IConnectionPointContainer)m_wkConnectionPointContainer.Target).FindConnectionPoint(ref riid, out ppCP);
		m_ConnectionPoint = ppCP;
		m_aEventSinkHelpers = new ArrayList();
	}

	public void add_InterimResponseReceived(_ICICLIPInterimResponseEvent_InterimResponseReceivedEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_ICICLIPInterimResponseEvent_SinkHelper iCICLIPInterimResponseEvent_SinkHelper = new _ICICLIPInterimResponseEvent_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iCICLIPInterimResponseEvent_SinkHelper, out pdwCookie);
			iCICLIPInterimResponseEvent_SinkHelper.m_dwCookie = pdwCookie;
			iCICLIPInterimResponseEvent_SinkHelper.m_InterimResponseReceivedDelegate = P_0;
			m_aEventSinkHelpers.Add(iCICLIPInterimResponseEvent_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_InterimResponseReceived(_ICICLIPInterimResponseEvent_InterimResponseReceivedEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
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
				_ICICLIPInterimResponseEvent_SinkHelper iCICLIPInterimResponseEvent_SinkHelper = (_ICICLIPInterimResponseEvent_SinkHelper)m_aEventSinkHelpers[num];
				if (iCICLIPInterimResponseEvent_SinkHelper.m_InterimResponseReceivedDelegate != null && ((iCICLIPInterimResponseEvent_SinkHelper.m_InterimResponseReceivedDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iCICLIPInterimResponseEvent_SinkHelper.m_dwCookie);
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
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public _ICICLIPInterimResponseEvent_EventProvider(object P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_wkConnectionPointContainer = new WeakReference((IConnectionPointContainer)P_0, trackResurrection: false);
	}

	public void Finalize()
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
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
					_ICICLIPInterimResponseEvent_SinkHelper iCICLIPInterimResponseEvent_SinkHelper = (_ICICLIPInterimResponseEvent_SinkHelper)m_aEventSinkHelpers[num];
					m_ConnectionPoint.Unadvise(iCICLIPInterimResponseEvent_SinkHelper.m_dwCookie);
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
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
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
public sealed class _ICICLIPFinalResponseEvent_SinkHelper : _ICICLIPFinalResponseEvent
{
	public _ICICLIPFinalResponseEvent_FinalResponseReceivedEventHandler m_FinalResponseReceivedDelegate;

	public int m_dwCookie;

	public void FinalResponseReceived(short P_0, double P_1, object P_2)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_FinalResponseReceivedDelegate != null)
		{
			m_FinalResponseReceivedDelegate(P_0, P_1, P_2);
		}
	}

	internal _ICICLIPFinalResponseEvent_SinkHelper()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_dwCookie = 0;
		m_FinalResponseReceivedDelegate = null;
	}
}
internal sealed class _ICICLIPFinalResponseEvent_EventProvider : _ICICLIPFinalResponseEvent_Event, IDisposable
{
	private WeakReference m_wkConnectionPointContainer;

	private ArrayList m_aEventSinkHelpers;

	private IConnectionPoint m_ConnectionPoint;

	private void Init()
	{
		IConnectionPoint ppCP = null;
		Guid riid = new Guid(new byte[16]
		{
			196, 19, 184, 133, 211, 249, 66, 77, 180, 62,
			121, 218, 155, 47, 194, 239
		});
		((IConnectionPointContainer)m_wkConnectionPointContainer.Target).FindConnectionPoint(ref riid, out ppCP);
		m_ConnectionPoint = ppCP;
		m_aEventSinkHelpers = new ArrayList();
	}

	public void add_FinalResponseReceived(_ICICLIPFinalResponseEvent_FinalResponseReceivedEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_ICICLIPFinalResponseEvent_SinkHelper iCICLIPFinalResponseEvent_SinkHelper = new _ICICLIPFinalResponseEvent_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iCICLIPFinalResponseEvent_SinkHelper, out pdwCookie);
			iCICLIPFinalResponseEvent_SinkHelper.m_dwCookie = pdwCookie;
			iCICLIPFinalResponseEvent_SinkHelper.m_FinalResponseReceivedDelegate = P_0;
			m_aEventSinkHelpers.Add(iCICLIPFinalResponseEvent_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_FinalResponseReceived(_ICICLIPFinalResponseEvent_FinalResponseReceivedEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
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
				_ICICLIPFinalResponseEvent_SinkHelper iCICLIPFinalResponseEvent_SinkHelper = (_ICICLIPFinalResponseEvent_SinkHelper)m_aEventSinkHelpers[num];
				if (iCICLIPFinalResponseEvent_SinkHelper.m_FinalResponseReceivedDelegate != null && ((iCICLIPFinalResponseEvent_SinkHelper.m_FinalResponseReceivedDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iCICLIPFinalResponseEvent_SinkHelper.m_dwCookie);
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
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public _ICICLIPFinalResponseEvent_EventProvider(object P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_wkConnectionPointContainer = new WeakReference((IConnectionPointContainer)P_0, trackResurrection: false);
	}

	public void Finalize()
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
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
					_ICICLIPFinalResponseEvent_SinkHelper iCICLIPFinalResponseEvent_SinkHelper = (_ICICLIPFinalResponseEvent_SinkHelper)m_aEventSinkHelpers[num];
					m_ConnectionPoint.Unadvise(iCICLIPFinalResponseEvent_SinkHelper.m_dwCookie);
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
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void Dispose()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		Finalize();
		GC.SuppressFinalize(this);
	}
}
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FHidden)]
public sealed class _ICIRequestStatusEvent_SinkHelper : _ICIRequestStatusEvent
{
	public _ICIRequestStatusEvent_RequestStatusEventHandler m_RequestStatusDelegate;

	public int m_dwCookie;

	public void RequestStatus(RequestStatusEnum P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_RequestStatusDelegate != null)
		{
			m_RequestStatusDelegate(P_0);
		}
	}

	internal _ICIRequestStatusEvent_SinkHelper()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_dwCookie = 0;
		m_RequestStatusDelegate = null;
	}
}
internal sealed class _ICIRequestStatusEvent_EventProvider : _ICIRequestStatusEvent_Event, IDisposable
{
	private WeakReference m_wkConnectionPointContainer;

	private ArrayList m_aEventSinkHelpers;

	private IConnectionPoint m_ConnectionPoint;

	private void Init()
	{
		IConnectionPoint ppCP = null;
		Guid riid = new Guid(new byte[16]
		{
			85, 116, 41, 48, 253, 197, 210, 71, 159, 255,
			19, 245, 167, 106, 189, 192
		});
		((IConnectionPointContainer)m_wkConnectionPointContainer.Target).FindConnectionPoint(ref riid, out ppCP);
		m_ConnectionPoint = ppCP;
		m_aEventSinkHelpers = new ArrayList();
	}

	public void add_RequestStatus(_ICIRequestStatusEvent_RequestStatusEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_ICIRequestStatusEvent_SinkHelper iCIRequestStatusEvent_SinkHelper = new _ICIRequestStatusEvent_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iCIRequestStatusEvent_SinkHelper, out pdwCookie);
			iCIRequestStatusEvent_SinkHelper.m_dwCookie = pdwCookie;
			iCIRequestStatusEvent_SinkHelper.m_RequestStatusDelegate = P_0;
			m_aEventSinkHelpers.Add(iCIRequestStatusEvent_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_RequestStatus(_ICIRequestStatusEvent_RequestStatusEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
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
				_ICIRequestStatusEvent_SinkHelper iCIRequestStatusEvent_SinkHelper = (_ICIRequestStatusEvent_SinkHelper)m_aEventSinkHelpers[num];
				if (iCIRequestStatusEvent_SinkHelper.m_RequestStatusDelegate != null && ((iCIRequestStatusEvent_SinkHelper.m_RequestStatusDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iCIRequestStatusEvent_SinkHelper.m_dwCookie);
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
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public _ICIRequestStatusEvent_EventProvider(object P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_wkConnectionPointContainer = new WeakReference((IConnectionPointContainer)P_0, trackResurrection: false);
	}

	public void Finalize()
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
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
					_ICIRequestStatusEvent_SinkHelper iCIRequestStatusEvent_SinkHelper = (_ICIRequestStatusEvent_SinkHelper)m_aEventSinkHelpers[num];
					m_ConnectionPoint.Unadvise(iCIRequestStatusEvent_SinkHelper.m_dwCookie);
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
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
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
public sealed class _ICIReceiveMailboxEvent_SinkHelper : _ICIReceiveMailboxEvent
{
	public _ICIReceiveMailboxEvent_ReceiveMailboxMessageEventHandler m_ReceiveMailboxMessageDelegate;

	public int m_dwCookie;

	public void ReceiveMailboxMessage(object P_0, object P_1, uint P_2)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_ReceiveMailboxMessageDelegate != null)
		{
			m_ReceiveMailboxMessageDelegate(P_0, P_1, P_2);
		}
	}

	internal _ICIReceiveMailboxEvent_SinkHelper()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_dwCookie = 0;
		m_ReceiveMailboxMessageDelegate = null;
	}
}
internal sealed class _ICIReceiveMailboxEvent_EventProvider : _ICIReceiveMailboxEvent_Event, IDisposable
{
	private WeakReference m_wkConnectionPointContainer;

	private ArrayList m_aEventSinkHelpers;

	private IConnectionPoint m_ConnectionPoint;

	private void Init()
	{
		IConnectionPoint ppCP = null;
		Guid riid = new Guid(new byte[16]
		{
			81, 184, 255, 234, 52, 130, 214, 17, 190, 48,
			0, 6, 41, 48, 183, 53
		});
		((IConnectionPointContainer)m_wkConnectionPointContainer.Target).FindConnectionPoint(ref riid, out ppCP);
		m_ConnectionPoint = ppCP;
		m_aEventSinkHelpers = new ArrayList();
	}

	public void add_ReceiveMailboxMessage(_ICIReceiveMailboxEvent_ReceiveMailboxMessageEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_ICIReceiveMailboxEvent_SinkHelper iCIReceiveMailboxEvent_SinkHelper = new _ICIReceiveMailboxEvent_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iCIReceiveMailboxEvent_SinkHelper, out pdwCookie);
			iCIReceiveMailboxEvent_SinkHelper.m_dwCookie = pdwCookie;
			iCIReceiveMailboxEvent_SinkHelper.m_ReceiveMailboxMessageDelegate = P_0;
			m_aEventSinkHelpers.Add(iCIReceiveMailboxEvent_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_ReceiveMailboxMessage(_ICIReceiveMailboxEvent_ReceiveMailboxMessageEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
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
				_ICIReceiveMailboxEvent_SinkHelper iCIReceiveMailboxEvent_SinkHelper = (_ICIReceiveMailboxEvent_SinkHelper)m_aEventSinkHelpers[num];
				if (iCIReceiveMailboxEvent_SinkHelper.m_ReceiveMailboxMessageDelegate != null && ((iCIReceiveMailboxEvent_SinkHelper.m_ReceiveMailboxMessageDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iCIReceiveMailboxEvent_SinkHelper.m_dwCookie);
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
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public _ICIReceiveMailboxEvent_EventProvider(object P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_wkConnectionPointContainer = new WeakReference((IConnectionPointContainer)P_0, trackResurrection: false);
	}

	public void Finalize()
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
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
					_ICIReceiveMailboxEvent_SinkHelper iCIReceiveMailboxEvent_SinkHelper = (_ICIReceiveMailboxEvent_SinkHelper)m_aEventSinkHelpers[num];
					m_ConnectionPoint.Unadvise(iCIReceiveMailboxEvent_SinkHelper.m_dwCookie);
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
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void Dispose()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		Finalize();
		GC.SuppressFinalize(this);
	}
}
