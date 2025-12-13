using System;
using System.Collections;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
using System.Threading;

[assembly: Guid("81A103C3-9627-11D4-92BF-0050DAD1BAB1")]
[assembly: TypeLibVersion(1, 0)]
[assembly: ImportedFromTypeLib("CILMessage")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace CILMSGHANDLINGLib;

[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("33C2358B-A8F2-11D4-92D8-0050DAD1BAB1")]
public interface ICIFilter
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	int ShouldSend([In][MarshalAs(UnmanagedType.Interface)] ICIMsg message);

	[DispId(1)]
	ICIMsg Template
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
}
[ComImport]
[CoClass(typeof(filterClass))]
[Guid("33C2358B-A8F2-11D4-92D8-0050DAD1BAB1")]
public interface filter : ICIFilter
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("E483E5C4-BA3A-11D4-930B-0050DAD1BAB1")]
[ClassInterface(ClassInterfaceType.None)]
public class filterClass : ICIFilter, filter
{
	[DispId(1)]
	public virtual extern ICIMsg Template
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

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern int ShouldSend([In][MarshalAs(UnmanagedType.Interface)] ICIMsg message);
}
[ComImport]
[Guid("33C2358B-A8F2-11D4-92D8-0050DAD1BAB1")]
[CoClass(typeof(RequestFilterClass))]
public interface RequestFilter : ICIFilter
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ClassInterface(ClassInterfaceType.None)]
[Guid("A5230F19-C461-11D4-9318-0050DAD1BAB1")]
public class RequestFilterClass : ICIFilter, RequestFilter
{
	[DispId(1)]
	public virtual extern ICIMsg Template
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

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern int ShouldSend([In][MarshalAs(UnmanagedType.Interface)] ICIMsg message);
}
[ComImport]
[CoClass(typeof(DiagnosticFilterClass))]
[Guid("33C2358B-A8F2-11D4-92D8-0050DAD1BAB1")]
public interface DiagnosticFilter : ICIFilter
{
}
[ComImport]
[Guid("A5230F15-C461-11D4-9318-0050DAD1BAB1")]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class DiagnosticFilterClass : ICIFilter, DiagnosticFilter
{
	[DispId(1)]
	public virtual extern ICIMsg Template
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

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern int ShouldSend([In][MarshalAs(UnmanagedType.Interface)] ICIMsg message);
}
[ComImport]
[Guid("33C2358B-A8F2-11D4-92D8-0050DAD1BAB1")]
[CoClass(typeof(ProgressFilterClass))]
public interface ProgressFilter : ICIFilter
{
}
[ComImport]
[Guid("A5230F17-C461-11D4-9318-0050DAD1BAB1")]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class ProgressFilterClass : ICIFilter, ProgressFilter
{
	[DispId(1)]
	public virtual extern ICIMsg Template
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

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern int ShouldSend([In][MarshalAs(UnmanagedType.Interface)] ICIMsg message);
}
[ComImport]
[Guid("33C2358C-A8F2-11D4-92D8-0050DAD1BAB1")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIFilters : IEnumerable
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void Add([In][MarshalAs(UnmanagedType.Interface)] ICIFilter filter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void Clear();

	[DispId(1)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();

	[DispId(0)]
	ICIFilter this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[Guid("33C2358C-A8F2-11D4-92D8-0050DAD1BAB1")]
[CoClass(typeof(filtersClass))]
public interface filters : ICIFilters
{
}
[ComImport]
[Guid("E483E5C8-BA3A-11D4-930B-0050DAD1BAB1")]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ClassInterface(ClassInterfaceType.None)]
public class filtersClass : ICIFilters, filters, IEnumerable
{
	[DispId(1)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(0)]
	public virtual extern ICIFilter this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void Add([In][MarshalAs(UnmanagedType.Interface)] ICIFilter filter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	public virtual extern void Clear();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	public virtual extern IEnumerator GetEnumerator();
}
[ComImport]
[Guid("CF09B155-952A-11D4-92BE-0050DAD1BAB1")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIMsg
{
	[DispId(1)]
	int Identifier
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
	int Group
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
	int Originator
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
	int Synchronous
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
	[ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
	MsgTypeEnum MessageType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		set;
	}

	[DispId(6)]
	MsgParams Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(7)]
	string ProgrammerText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(8)]
	[ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
	MsgReturnTypeEnum Response
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		set;
	}
}
[ComImport]
[CoClass(typeof(MsgClass))]
[Guid("CF09B155-952A-11D4-92BE-0050DAD1BAB1")]
public interface Msg : ICIMsg
{
}
[ComImport]
[Guid("90371E19-BA53-11D4-930B-0050DAD1BAB1")]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class MsgClass : ICIMsg, Msg
{
	[DispId(1)]
	public virtual extern int Identifier
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
	public virtual extern int Group
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
	public virtual extern int Originator
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
	public virtual extern int Synchronous
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
	[ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
	public virtual extern MsgTypeEnum MessageType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		set;
	}

	[DispId(6)]
	public virtual extern MsgParams Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(7)]
	public virtual extern string ProgrammerText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
	[DispId(8)]
	public virtual extern MsgReturnTypeEnum Response
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		set;
	}
}
[ComImport]
[Guid("9D3C3D2C-9623-11D4-92BF-0050DAD1BAB1")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIRequestMsg : ICIMsg
{
	[DispId(1)]
	new int Identifier
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
	new int Group
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
	new int Originator
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
	new int Synchronous
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
	[DispId(5)]
	new MsgTypeEnum MessageType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		set;
	}

	[DispId(6)]
	new MsgParams Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(7)]
	new string ProgrammerText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(8)]
	[ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
	new MsgReturnTypeEnum Response
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")]
	[DispId(9)]
	MsgRequestTypeEnum requestType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")]
		set;
	}
}
[ComImport]
[CoClass(typeof(requestMsgClass))]
[Guid("9D3C3D2C-9623-11D4-92BF-0050DAD1BAB1")]
public interface requestMsg : ICIRequestMsg
{
}
[ComImport]
[Guid("90371E17-BA53-11D4-930B-0050DAD1BAB1")]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class requestMsgClass : ICIRequestMsg, requestMsg, ICIMsg
{
	[DispId(1)]
	public virtual extern int Identifier
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
	public virtual extern int Group
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
	public virtual extern int Originator
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
	public virtual extern int Synchronous
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
	[DispId(5)]
	public virtual extern MsgTypeEnum MessageType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		set;
	}

	[DispId(6)]
	public virtual extern MsgParams Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(7)]
	public virtual extern string ProgrammerText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
	[DispId(8)]
	public virtual extern MsgReturnTypeEnum Response
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		set;
	}

	[DispId(9)]
	[ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")]
	public virtual extern MsgRequestTypeEnum requestType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")]
		set;
	}

	public virtual extern int ICIMsg_Identifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int ICIMsg_Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int ICIMsg_Originator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int ICIMsg_Synchronous
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
	public virtual extern MsgTypeEnum ICIMsg_MessageType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		set;
	}

	public virtual extern MsgParams ICIMsg_Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	public virtual extern string ICIMsg_ProgrammerText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
	public virtual extern MsgReturnTypeEnum ICIMsg_Response
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		set;
	}
}
[ComImport]
[Guid("9D3C3D2F-9623-11D4-92BF-0050DAD1BAB1")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIDiagnosticMsg : ICIRequestMsg
{
	[DispId(1)]
	new int Identifier
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
	new int Group
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
	new int Originator
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
	new int Synchronous
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
	[ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
	new MsgTypeEnum MessageType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		set;
	}

	[DispId(6)]
	new MsgParams Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(7)]
	new string ProgrammerText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
	[DispId(8)]
	new MsgReturnTypeEnum Response
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")]
	[DispId(9)]
	new MsgRequestTypeEnum requestType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")]
		set;
	}

	[DispId(10)]
	int LineNumber
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
	string FileName
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

	[DispId(12)]
	string FunctionSignature
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(13)]
	DateTime Time
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[param: In]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgSeverityTypeEnum")]
	[DispId(14)]
	MsgSeverityTypeEnum severity
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgSeverityTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgSeverityTypeEnum")]
		set;
	}
}
[ComImport]
[CoClass(typeof(DiagnosticMsgClass))]
[Guid("9D3C3D2F-9623-11D4-92BF-0050DAD1BAB1")]
public interface DiagnosticMsg : ICIDiagnosticMsg
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ClassInterface(ClassInterfaceType.None)]
[Guid("90371E14-BA53-11D4-930B-0050DAD1BAB1")]
public class DiagnosticMsgClass : ICIDiagnosticMsg, DiagnosticMsg, ICIMsg, ICIRequestMsg
{
	[DispId(1)]
	public virtual extern int Identifier
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
	public virtual extern int Group
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
	public virtual extern int Originator
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
	public virtual extern int Synchronous
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[param: In]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
	[DispId(5)]
	public virtual extern MsgTypeEnum MessageType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		set;
	}

	[DispId(6)]
	public virtual extern MsgParams Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(7)]
	public virtual extern string ProgrammerText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
	[DispId(8)]
	public virtual extern MsgReturnTypeEnum Response
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		set;
	}

	[DispId(9)]
	[ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")]
	public virtual extern MsgRequestTypeEnum requestType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")]
		set;
	}

	[DispId(10)]
	public virtual extern int LineNumber
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
	public virtual extern string FileName
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

	[DispId(12)]
	public virtual extern string FunctionSignature
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(13)]
	public virtual extern DateTime Time
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[param: In]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgSeverityTypeEnum")]
	[DispId(14)]
	public virtual extern MsgSeverityTypeEnum severity
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgSeverityTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgSeverityTypeEnum")]
		set;
	}

	public virtual extern int ICIMsg_Identifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int ICIMsg_Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int ICIMsg_Originator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int ICIMsg_Synchronous
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
	public virtual extern MsgTypeEnum ICIMsg_MessageType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		set;
	}

	public virtual extern MsgParams ICIMsg_Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	public virtual extern string ICIMsg_ProgrammerText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
	public virtual extern MsgReturnTypeEnum ICIMsg_Response
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		set;
	}

	public virtual extern int ICIRequestMsg_Identifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int ICIRequestMsg_Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int ICIRequestMsg_Originator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int ICIRequestMsg_Synchronous
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
	public virtual extern MsgTypeEnum ICIRequestMsg_MessageType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		set;
	}

	public virtual extern MsgParams ICIRequestMsg_Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	public virtual extern string ICIRequestMsg_ProgrammerText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
	public virtual extern MsgReturnTypeEnum ICIRequestMsg_Response
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")]
	public virtual extern MsgRequestTypeEnum ICIRequestMsg_requestType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")]
		set;
	}
}
[ComImport]
[Guid("3D1FA696-9617-11D4-92BF-0050DAD1BAB1")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIPerformanceMsg : ICIMsg
{
	[DispId(1)]
	new int Identifier
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
	new int Group
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
	new int Originator
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
	new int Synchronous
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
	[ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
	new MsgTypeEnum MessageType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		set;
	}

	[DispId(6)]
	new MsgParams Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(7)]
	new string ProgrammerText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
	[DispId(8)]
	new MsgReturnTypeEnum Response
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		set;
	}

	[DispId(9)]
	int ElementsProcessed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[param: In]
		set;
	}

	[DispId(10)]
	float ElapsedSeconds
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[param: In]
		set;
	}
}
[ComImport]
[CoClass(typeof(performanceMsgClass))]
[Guid("3D1FA696-9617-11D4-92BF-0050DAD1BAB1")]
public interface performanceMsg : ICIPerformanceMsg
{
}
[ComImport]
[Guid("E71D7654-BC90-11D4-9310-000000000000")]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class performanceMsgClass : ICIPerformanceMsg, performanceMsg, ICIMsg
{
	[DispId(1)]
	public virtual extern int Identifier
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
	public virtual extern int Group
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
	public virtual extern int Originator
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
	public virtual extern int Synchronous
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
	[ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
	public virtual extern MsgTypeEnum MessageType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		set;
	}

	[DispId(6)]
	public virtual extern MsgParams Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(7)]
	public virtual extern string ProgrammerText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(8)]
	[ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
	public virtual extern MsgReturnTypeEnum Response
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		set;
	}

	[DispId(9)]
	public virtual extern int ElementsProcessed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[param: In]
		set;
	}

	[DispId(10)]
	public virtual extern float ElapsedSeconds
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[param: In]
		set;
	}

	public virtual extern int ICIMsg_Identifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int ICIMsg_Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int ICIMsg_Originator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int ICIMsg_Synchronous
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
	public virtual extern MsgTypeEnum ICIMsg_MessageType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		set;
	}

	public virtual extern MsgParams ICIMsg_Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	public virtual extern string ICIMsg_ProgrammerText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
	public virtual extern MsgReturnTypeEnum ICIMsg_Response
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		set;
	}
}
[ComImport]
[Guid("9D3C3D2E-9623-11D4-92BF-0050DAD1BAB1")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIProgressMsg : ICIMsg
{
	[DispId(1)]
	new int Identifier
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
	new int Group
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
	new int Originator
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
	new int Synchronous
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
	[ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
	new MsgTypeEnum MessageType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		set;
	}

	[DispId(6)]
	new MsgParams Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(7)]
	new string ProgrammerText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
	[DispId(8)]
	new MsgReturnTypeEnum Response
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	void PercentComplete(out float pVal);

	[DispId(9)]
	int ElementsProcessed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[param: In]
		set;
	}

	[DispId(10)]
	int TotalNumberOfElements
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
	[ComAliasName("CILMSGHANDLINGLib.MsgProgressTypeEnum")]
	MsgProgressTypeEnum progressType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgProgressTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgProgressTypeEnum")]
		set;
	}
}
[ComImport]
[CoClass(typeof(progressMsgClass))]
[Guid("9D3C3D2E-9623-11D4-92BF-0050DAD1BAB1")]
public interface progressMsg : ICIProgressMsg
{
}
[ComImport]
[ClassInterface(ClassInterfaceType.None)]
[Guid("E71D7657-BC90-11D4-9310-000000000000")]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class progressMsgClass : ICIProgressMsg, progressMsg, ICIMsg
{
	[DispId(1)]
	public virtual extern int Identifier
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
	public virtual extern int Group
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
	public virtual extern int Originator
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
	public virtual extern int Synchronous
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
	[ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
	public virtual extern MsgTypeEnum MessageType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		set;
	}

	[DispId(6)]
	public virtual extern MsgParams Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(7)]
	public virtual extern string ProgrammerText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
	[DispId(8)]
	public virtual extern MsgReturnTypeEnum Response
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		set;
	}

	[DispId(9)]
	public virtual extern int ElementsProcessed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[param: In]
		set;
	}

	[DispId(10)]
	public virtual extern int TotalNumberOfElements
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[param: In]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgProgressTypeEnum")]
	[DispId(11)]
	public virtual extern MsgProgressTypeEnum progressType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgProgressTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgProgressTypeEnum")]
		set;
	}

	public virtual extern int ICIMsg_Identifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int ICIMsg_Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int ICIMsg_Originator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int ICIMsg_Synchronous
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
	public virtual extern MsgTypeEnum ICIMsg_MessageType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")]
		set;
	}

	public virtual extern MsgParams ICIMsg_Parameters
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	public virtual extern string ICIMsg_ProgrammerText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
	public virtual extern MsgReturnTypeEnum ICIMsg_Response
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: ComAliasName("CILMSGHANDLINGLib.MsgReturnTypeEnum")]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	public virtual extern void PercentComplete(out float pVal);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("181804C0-9ECD-11D4-92C9-0050DAD1BAB1")]
[DefaultMember("Value")]
public interface ICIMsgParam
{
	[DispId(1)]
	string Name
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

	[DispId(0)]
	object Value
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
}
[ComImport]
[CoClass(typeof(msgParamClass))]
[Guid("181804C0-9ECD-11D4-92C9-0050DAD1BAB1")]
public interface msgParam : ICIMsgParam
{
}
[ComImport]
[Guid("9E2F8875-BC99-11D4-9311-0050DAD1BAB1")]
[ClassInterface(ClassInterfaceType.None)]
[DefaultMember("Value")]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class msgParamClass : ICIMsgParam, msgParam
{
	[DispId(1)]
	public virtual extern string Name
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

	[DispId(0)]
	public virtual extern object Value
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
}
[ComImport]
[Guid("4496E370-9ECB-11D4-92C9-0050DAD1BAB1")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIMsgParams : IEnumerable
{
	[DispId(1)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();

	[DispId(0)]
	msgParam this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void Add([In][MarshalAs(UnmanagedType.Interface)] msgParam param);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void ParameterByName([In][MarshalAs(UnmanagedType.BStr)] string Name, [MarshalAs(UnmanagedType.Interface)] out msgParam msgParam);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void AddParameter([In][MarshalAs(UnmanagedType.BStr)] string Name, [In][MarshalAs(UnmanagedType.Struct)] object Value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void RemoveAll();
}
[ComImport]
[Guid("4496E370-9ECB-11D4-92C9-0050DAD1BAB1")]
[CoClass(typeof(MsgParamsClass))]
public interface MsgParams : ICIMsgParams
{
}
[ComImport]
[Guid("A0C9C646-BC99-11D4-9311-0050DAD1BAB1")]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class MsgParamsClass : ICIMsgParams, MsgParams, IEnumerable
{
	[DispId(1)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(0)]
	public virtual extern msgParam this[[In] int index]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	public virtual extern IEnumerator GetEnumerator();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void Add([In][MarshalAs(UnmanagedType.Interface)] msgParam param);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	public virtual extern void ParameterByName([In][MarshalAs(UnmanagedType.BStr)] string Name, [MarshalAs(UnmanagedType.Interface)] out msgParam msgParam);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	public virtual extern void AddParameter([In][MarshalAs(UnmanagedType.BStr)] string Name, [In][MarshalAs(UnmanagedType.Struct)] object Value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void RemoveAll();
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("9D3C3D27-9623-11D4-92BF-0050DAD1BAB1")]
public interface ICIMsgManager
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void ProcessMessage([In][MarshalAs(UnmanagedType.Interface)] ICIMsg message);

	[DispId(2)]
	int Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
[ComImport]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
[Guid("9D3C3D2D-9623-11D4-92BF-0050DAD1BAB1")]
public interface _ICIMsgReceiverEvent
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void ReceiveMessage([In][MarshalAs(UnmanagedType.Interface)] ICIMsg pMessage);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void AssignFilters([In][MarshalAs(UnmanagedType.Interface)] filters filters);
}
[TypeLibType(TypeLibTypeFlags.FHidden)]
[ComVisible(false)]
[ComEventInterface(typeof(_ICIMsgReceiverEvent), typeof(_ICIMsgReceiverEvent_EventProvider))]
public interface _ICIMsgReceiverEvent_Event
{
	event _ICIMsgReceiverEvent_ReceiveMessageEventHandler ReceiveMessage;

	event _ICIMsgReceiverEvent_AssignFiltersEventHandler AssignFilters;
}
[ComImport]
[Guid("9D3C3D27-9623-11D4-92BF-0050DAD1BAB1")]
[CoClass(typeof(MsgManagerClass))]
public interface MsgManager : ICIMsgManager, _ICIMsgReceiverEvent_Event
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("95549157-A764-11D4-92D6-000000000000")]
public interface ICIMsgFactory
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Interface)]
	progressMsg CreateProgressMsg([In] int Identifier, [In] int Group, [In] int Originator, [In][ComAliasName("CILMSGHANDLINGLib.MsgProgressTypeEnum")] MsgProgressTypeEnum progressType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	[return: MarshalAs(UnmanagedType.Interface)]
	performanceMsg CreatePerformanceMsg([In] int Identifier, [In] int Group, [In] int Originator, [In] int ElementsProcessed, [In] float ElapsedSeconds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICIRequestMsg CreateRequestMsg([In] int Identifier, [In] int Group, [In] int Originator, [In][ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")] MsgRequestTypeEnum requestType, [In][MarshalAs(UnmanagedType.BStr)] string ProgrammerText);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Interface)]
	DiagnosticMsg CreateDiagnosticMsg([In] int Identifier, [In] int Group, [In] int Originator, [In][ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")] MsgRequestTypeEnum requestType, [In][MarshalAs(UnmanagedType.BStr)] string ProgrammerText, [In][MarshalAs(UnmanagedType.BStr)] string FileName, [In] int LineNumber, [In][MarshalAs(UnmanagedType.BStr)] string FunctionSignature, [In][ComAliasName("CILMSGHANDLINGLib.MsgSeverityTypeEnum")] MsgSeverityTypeEnum severity);
}
[ComImport]
[Guid("177B5E36-B19B-11D4-92FC-000000000000")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ICIFilterFactory
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICIFilter CreateMsgFilter([In] int Identifier, [In] int Originator, [In][ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")] MsgTypeEnum MessageType, [In] int Group);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICIFilter CreateRequestMsgFilter([In] int Identifier, [In] int Originator, [In] int Group, [In][ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")] MsgRequestTypeEnum requestType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICIFilter CreateDiagnosticMsgFilter([In] int Identifier, [In] int Originator, [In] int Group, [In][ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")] MsgRequestTypeEnum requestType, [In][ComAliasName("CILMSGHANDLINGLib.MsgSeverityTypeEnum")] MsgSeverityTypeEnum severity);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICIFilter CreateProgressMsgFilter([In] int Identifier, [In] int Originator, [In] int Group, [In][ComAliasName("CILMSGHANDLINGLib.MsgProgressTypeEnum")] MsgProgressTypeEnum progressType);
}
[ComImport]
[ComSourceInterfaces("CILMSGHANDLINGLib._ICIMsgReceiverEvent\0\0")]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("A5231009-C461-11D4-9318-0050DAD1BAB1")]
public class MsgManagerClass : ICIMsgManager, MsgManager, _ICIMsgReceiverEvent_Event, ICIMsgFactory, ICIFilterFactory
{
	[DispId(2)]
	public virtual extern int Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	public virtual extern event _ICIMsgReceiverEvent_ReceiveMessageEventHandler ReceiveMessage;

	public virtual extern event _ICIMsgReceiverEvent_AssignFiltersEventHandler AssignFilters;

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	public virtual extern void ProcessMessage([In][MarshalAs(UnmanagedType.Interface)] ICIMsg message);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern progressMsg CreateProgressMsg([In] int Identifier, [In] int Group, [In] int Originator, [In][ComAliasName("CILMSGHANDLINGLib.MsgProgressTypeEnum")] MsgProgressTypeEnum progressType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern performanceMsg CreatePerformanceMsg([In] int Identifier, [In] int Group, [In] int Originator, [In] int ElementsProcessed, [In] float ElapsedSeconds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICIRequestMsg CreateRequestMsg([In] int Identifier, [In] int Group, [In] int Originator, [In][ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")] MsgRequestTypeEnum requestType, [In][MarshalAs(UnmanagedType.BStr)] string ProgrammerText);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern DiagnosticMsg CreateDiagnosticMsg([In] int Identifier, [In] int Group, [In] int Originator, [In][ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")] MsgRequestTypeEnum requestType, [In][MarshalAs(UnmanagedType.BStr)] string ProgrammerText, [In][MarshalAs(UnmanagedType.BStr)] string FileName, [In] int LineNumber, [In][MarshalAs(UnmanagedType.BStr)] string FunctionSignature, [In][ComAliasName("CILMSGHANDLINGLib.MsgSeverityTypeEnum")] MsgSeverityTypeEnum severity);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICIFilter CreateMsgFilter([In] int Identifier, [In] int Originator, [In][ComAliasName("CILMSGHANDLINGLib.MsgTypeEnum")] MsgTypeEnum MessageType, [In] int Group);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICIFilter CreateRequestMsgFilter([In] int Identifier, [In] int Originator, [In] int Group, [In][ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")] MsgRequestTypeEnum requestType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICIFilter CreateDiagnosticMsgFilter([In] int Identifier, [In] int Originator, [In] int Group, [In][ComAliasName("CILMSGHANDLINGLib.MsgRequestTypeEnum")] MsgRequestTypeEnum requestType, [In][ComAliasName("CILMSGHANDLINGLib.MsgSeverityTypeEnum")] MsgSeverityTypeEnum severity);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICIFilter CreateProgressMsgFilter([In] int Identifier, [In] int Originator, [In] int Group, [In][ComAliasName("CILMSGHANDLINGLib.MsgProgressTypeEnum")] MsgProgressTypeEnum progressType);
}
[Guid("6E2680F4-F5D9-11D4-9AD6-0004AC96640B")]
public enum MsgTypeEnum
{
	MTYPE_REQUEST = 1,
	MTYPE_DIAGNOSTIC = 2,
	MTYPE_PERFORMANCE = 4,
	MTYPE_PROGRESS = 8,
	MTYPE_USERDEFINED = 16,
	MTYPE_ALL = -1
}
[Guid("73B197E2-F5DA-11D4-9AD6-0004AC96640B")]
public enum MsgReturnTypeEnum
{
	MSGRT_OK = 1,
	MSGRT_CANCEL = 2,
	MSGRT_YES = 4,
	MSGRT_NO = 8,
	MSGRT_RETRY = 16,
	MSGRT_IGNORE = 32,
	MSGRT_UNSPECIFIED = -1
}
[Guid("99305346-F5DA-11D4-9AD6-0004AC96640B")]
public enum MsgRequestTypeEnum
{
	MSGREQ_YESNO = 1,
	MSGREQ_YESNOCANCEL = 2,
	MSGREQ_RETRYCANCEL = 4,
	MSGREQ_OKCANCEL = 8,
	MSGREQ_IGNORERETRYCANCEL = 16,
	MSGREQ_INFORMATION = 32,
	MSGREQ_ANYREQUEST = -1
}
[Guid("BF2B08F2-F5DA-11D4-9AD6-0004AC96640B")]
public enum MsgSeverityTypeEnum
{
	MSGSEV_FATAL = 1,
	MSGSEV_ERROR = 2,
	MSGSEV_WARNING = 4,
	MSGSEV_INFORMATIONAL = 8,
	MSGSEV_ANYSEVERITY = -1
}
[Guid("F0F746C0-F5DA-11D4-9AD6-0004AC96640B")]
public enum MsgProgressTypeEnum
{
	MSGPROG_MAJOR = 1,
	MSGPROG_MINOR = 2,
	MSGPROG_INCREMENTAL = 4,
	MSGPROG_ANYPROGRESS = -1
}
[TypeLibType(TypeLibTypeFlags.FHidden)]
[ComVisible(false)]
public delegate void _ICIMsgReceiverEvent_ReceiveMessageEventHandler([In][MarshalAs(UnmanagedType.Interface)] ICIMsg pMessage);
[ComVisible(false)]
[TypeLibType(TypeLibTypeFlags.FHidden)]
public delegate void _ICIMsgReceiverEvent_AssignFiltersEventHandler([In][MarshalAs(UnmanagedType.Interface)] filters filters);
[Guid("BB16B205-990C-4D11-A706-F01C2D5BFC68")]
public enum MessageOriginatorConstants
{
	MSG_ORIG_DATADEF = 1,
	MSG_ORIG_DEVICECONTROL = 2,
	MSG_ORIG_CALDATASERVER = 5,
	MSG_ORIG_SUBFILE = 8,
	MSG_ORIG_CUDL = 10,
	MSG_ORIG_CONFIGFILE = 11,
	MSG_ORIG_CALBINIMAGE = 12,
	MSG_ORIG_UNITSOFMEASURE = 14,
	MSG_ORIG_SETSOFREQUESTS = 15,
	MSG_ORIG_FAULTCODEACQ = 16,
	MSG_ORIG_DATAMONITOR = 17,
	MSG_ORIG_ASSEMBLER = 18,
	MSG_ORIG_AUDITTRAIL = 19,
	MSG_ORIG_MODULEDETECTION = 20,
	MSG_ORIG_METADATA = 24,
	MSG_ORIG_COMPATFILEREADER = 30,
	MSG_ORIG_COMPRESSION = 100,
	MSG_ORIG_AUTOCONFIGDLA = 101
}
public enum tagMessageOriginatorConstants
{
	MSG_ORIG_DATADEF = 1,
	MSG_ORIG_DEVICECONTROL = 2,
	MSG_ORIG_CALDATASERVER = 5,
	MSG_ORIG_SUBFILE = 8,
	MSG_ORIG_CUDL = 10,
	MSG_ORIG_CONFIGFILE = 11,
	MSG_ORIG_CALBINIMAGE = 12,
	MSG_ORIG_UNITSOFMEASURE = 14,
	MSG_ORIG_SETSOFREQUESTS = 15,
	MSG_ORIG_FAULTCODEACQ = 16,
	MSG_ORIG_DATAMONITOR = 17,
	MSG_ORIG_ASSEMBLER = 18,
	MSG_ORIG_AUDITTRAIL = 19,
	MSG_ORIG_MODULEDETECTION = 20,
	MSG_ORIG_METADATA = 24,
	MSG_ORIG_COMPATFILEREADER = 30,
	MSG_ORIG_COMPRESSION = 100,
	MSG_ORIG_AUTOCONFIGDLA = 101
}
[Guid("32EB1504-F5D9-11D4-9AD6-0004AC96640B")]
public enum MessageConstants
{
	UNSPECIFIED_MSG_IDENTIFIER = -1,
	UNSPECIFIED_ORIGINATOR = -1,
	NO_GROUP = 0,
	UNSPECIFIED_GROUP = -1
}
public enum tagMessageConstants
{
	UNSPECIFIED_MSG_IDENTIFIER = -1,
	UNSPECIFIED_ORIGINATOR = -1,
	NO_GROUP = 0,
	UNSPECIFIED_GROUP = -1
}
public enum tagMsgTypeEnum
{
	MTYPE_REQUEST = 1,
	MTYPE_DIAGNOSTIC = 2,
	MTYPE_PERFORMANCE = 4,
	MTYPE_PROGRESS = 8,
	MTYPE_USERDEFINED = 16,
	MTYPE_ALL = -1
}
public enum tagMsgReturnTypeEnum
{
	MSGRT_OK = 1,
	MSGRT_CANCEL = 2,
	MSGRT_YES = 4,
	MSGRT_NO = 8,
	MSGRT_RETRY = 16,
	MSGRT_IGNORE = 32,
	MSGRT_UNSPECIFIED = -1
}
public enum tagMsgRequestTypeEnum
{
	MSGREQ_YESNO = 1,
	MSGREQ_YESNOCANCEL = 2,
	MSGREQ_RETRYCANCEL = 4,
	MSGREQ_OKCANCEL = 8,
	MSGREQ_IGNORERETRYCANCEL = 16,
	MSGREQ_INFORMATION = 32,
	MSGREQ_ANYREQUEST = -1
}
public enum tagMsgSeverityTypeEnum
{
	MSGSEV_FATAL = 1,
	MSGSEV_ERROR = 2,
	MSGSEV_WARNING = 4,
	MSGSEV_INFORMATIONAL = 8,
	MSGSEV_ANYSEVERITY = -1
}
public enum tagMsgProgressTypeEnum
{
	MSGPROG_MAJOR = 1,
	MSGPROG_MINOR = 2,
	MSGPROG_INCREMENTAL = 4,
	MSGPROG_ANYPROGRESS = -1
}
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FHidden)]
public sealed class _ICIMsgReceiverEvent_SinkHelper : _ICIMsgReceiverEvent
{
	public _ICIMsgReceiverEvent_ReceiveMessageEventHandler m_ReceiveMessageDelegate;

	public _ICIMsgReceiverEvent_AssignFiltersEventHandler m_AssignFiltersDelegate;

	public int m_dwCookie;

	public void ReceiveMessage(ICIMsg P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_ReceiveMessageDelegate != null)
		{
			m_ReceiveMessageDelegate(P_0);
		}
	}

	public void AssignFilters(filters P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AssignFiltersDelegate != null)
		{
			m_AssignFiltersDelegate(P_0);
		}
	}

	internal _ICIMsgReceiverEvent_SinkHelper()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_dwCookie = 0;
		m_ReceiveMessageDelegate = null;
		m_AssignFiltersDelegate = null;
	}
}
internal sealed class _ICIMsgReceiverEvent_EventProvider : _ICIMsgReceiverEvent_Event, IDisposable
{
	private WeakReference m_wkConnectionPointContainer;

	private ArrayList m_aEventSinkHelpers;

	private IConnectionPoint m_ConnectionPoint;

	private void Init()
	{
		IConnectionPoint ppCP = null;
		Guid riid = new Guid(new byte[16]
		{
			45, 61, 60, 157, 35, 150, 212, 17, 146, 191,
			0, 80, 218, 209, 186, 177
		});
		((IConnectionPointContainer)m_wkConnectionPointContainer.Target).FindConnectionPoint(ref riid, out ppCP);
		m_ConnectionPoint = ppCP;
		m_aEventSinkHelpers = new ArrayList();
	}

	public void add_ReceiveMessage(_ICIMsgReceiverEvent_ReceiveMessageEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_ICIMsgReceiverEvent_SinkHelper iCIMsgReceiverEvent_SinkHelper = new _ICIMsgReceiverEvent_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iCIMsgReceiverEvent_SinkHelper, out pdwCookie);
			iCIMsgReceiverEvent_SinkHelper.m_dwCookie = pdwCookie;
			iCIMsgReceiverEvent_SinkHelper.m_ReceiveMessageDelegate = P_0;
			m_aEventSinkHelpers.Add(iCIMsgReceiverEvent_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_ReceiveMessage(_ICIMsgReceiverEvent_ReceiveMessageEventHandler P_0)
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
				_ICIMsgReceiverEvent_SinkHelper iCIMsgReceiverEvent_SinkHelper = (_ICIMsgReceiverEvent_SinkHelper)m_aEventSinkHelpers[num];
				if (iCIMsgReceiverEvent_SinkHelper.m_ReceiveMessageDelegate != null && ((iCIMsgReceiverEvent_SinkHelper.m_ReceiveMessageDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iCIMsgReceiverEvent_SinkHelper.m_dwCookie);
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

	public void add_AssignFilters(_ICIMsgReceiverEvent_AssignFiltersEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_ICIMsgReceiverEvent_SinkHelper iCIMsgReceiverEvent_SinkHelper = new _ICIMsgReceiverEvent_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iCIMsgReceiverEvent_SinkHelper, out pdwCookie);
			iCIMsgReceiverEvent_SinkHelper.m_dwCookie = pdwCookie;
			iCIMsgReceiverEvent_SinkHelper.m_AssignFiltersDelegate = P_0;
			m_aEventSinkHelpers.Add(iCIMsgReceiverEvent_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_AssignFilters(_ICIMsgReceiverEvent_AssignFiltersEventHandler P_0)
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
				_ICIMsgReceiverEvent_SinkHelper iCIMsgReceiverEvent_SinkHelper = (_ICIMsgReceiverEvent_SinkHelper)m_aEventSinkHelpers[num];
				if (iCIMsgReceiverEvent_SinkHelper.m_AssignFiltersDelegate != null && ((iCIMsgReceiverEvent_SinkHelper.m_AssignFiltersDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iCIMsgReceiverEvent_SinkHelper.m_dwCookie);
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

	public _ICIMsgReceiverEvent_EventProvider(object P_0)
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
					_ICIMsgReceiverEvent_SinkHelper iCIMsgReceiverEvent_SinkHelper = (_ICIMsgReceiverEvent_SinkHelper)m_aEventSinkHelpers[num];
					m_ConnectionPoint.Unadvise(iCIMsgReceiverEvent_SinkHelper.m_dwCookie);
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
