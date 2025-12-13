using System;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: Guid("8C926A5A-F787-4158-B1AF-41C0C20C969A")]
[assembly: TypeLibVersion(1, 0)]
[assembly: ImportedFromTypeLib("CILDICTIONARYLib")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace CILDICTIONARYLib;

[ComImport]
[ComConversionLoss]
[TypeLibType(TypeLibTypeFlags.FHidden | TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("BF32628A-D104-45FF-8539-BCD450D1C8BA")]
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
[Guid("BF32628A-D104-45FF-8539-BCD450D1C8BA")]
[CoClass(typeof(DictClass))]
public interface Dict : ICIDictionary
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ClassInterface(ClassInterfaceType.None)]
[Guid("0B1F67E6-0D36-446A-8477-723B5B5CF74B")]
[ComConversionLoss]
public class DictClass : ICIDictionary, Dict
{
	[DispId(0)]
	public virtual extern object this[[In][MarshalAs(UnmanagedType.Struct)] ref object Key]
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

	[DispId(2)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[DispId(5)]
	public virtual extern IntPtr Key
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(0)]
	public virtual extern void let_Item([In][MarshalAs(UnmanagedType.Struct)] ref object Key, [In][MarshalAs(UnmanagedType.Struct)] ref object pRetItem);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	public virtual extern void Add([In][MarshalAs(UnmanagedType.Struct)] ref object Key, [In][MarshalAs(UnmanagedType.Struct)] ref object Item);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	public virtual extern bool Exists([In][MarshalAs(UnmanagedType.Struct)] ref object Key);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object Keys();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	public virtual extern void Remove([In][MarshalAs(UnmanagedType.Struct)] ref object Key);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	public virtual extern void RemoveAll();
}
