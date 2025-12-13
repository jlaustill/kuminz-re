using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("767D21E7-D9D0-4423-8F52-DE9565F34E81")]
[assembly: ImportedFromTypeLib("COLLECTIONLib")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace COLLECTIONLib;

[ComImport]
[Guid("FA9B331E-58CF-484A-B8CF-7DF6286C1CCB")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IFloatCollection
{
	[DispId(1)]
	float Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
[ComImport]
[Guid("FA9B331E-58CF-484A-B8CF-7DF6286C1CCB")]
[CoClass(typeof(FloatCollectionClass))]
public interface FloatCollection : IFloatCollection
{
}
[ComImport]
[Guid("2ED68923-74A8-4225-A3CF-CC4D2206DCDA")]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ClassInterface(ClassInterfaceType.None)]
public class FloatCollectionClass : IFloatCollection, FloatCollection
{
	[DispId(1)]
	public virtual extern float Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("967A0762-2F87-4665-B706-E7C574FC135A")]
public interface IBSTRCollection
{
	[DispId(1)]
	string Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
[ComImport]
[CoClass(typeof(BSTRCollectionClass))]
[Guid("967A0762-2F87-4665-B706-E7C574FC135A")]
public interface BSTRCollection : IBSTRCollection
{
}
[ComImport]
[Guid("A3BE3711-132C-4DC4-B7E8-0E1E2866540D")]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ClassInterface(ClassInterfaceType.None)]
public class BSTRCollectionClass : IBSTRCollection, BSTRCollection
{
	[DispId(1)]
	public virtual extern string Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
[ComImport]
[Guid("474B0063-2291-4AD5-B0E8-D86D6B7363A1")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface ILongCollection
{
	[DispId(1)]
	int Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
[ComImport]
[CoClass(typeof(LongCollectionClass))]
[Guid("474B0063-2291-4AD5-B0E8-D86D6B7363A1")]
public interface LongCollection : ILongCollection
{
}
[ComImport]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("CDD7EA67-1C34-4282-BDF3-C6D5C19E2D66")]
public class LongCollectionClass : ILongCollection, LongCollection
{
	[DispId(1)]
	public virtual extern int Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
[ComImport]
[Guid("72E3E52C-571F-4C9A-ABDD-A57D0049D745")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IBoolCollection
{
	[DispId(1)]
	bool Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
[ComImport]
[Guid("72E3E52C-571F-4C9A-ABDD-A57D0049D745")]
[CoClass(typeof(BoolCollectionClass))]
public interface BoolCollection : IBoolCollection
{
}
[ComImport]
[Guid("79A28B9A-DAEB-4005-9B04-A061F0901667")]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ClassInterface(ClassInterfaceType.None)]
public class BoolCollectionClass : IBoolCollection, BoolCollection
{
	[DispId(1)]
	public virtual extern bool Item
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(2)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}
}
