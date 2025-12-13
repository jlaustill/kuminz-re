using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("38D07BCB-3103-4152-95DD-EE0D673FB13A")]
[assembly: ImportedFromTypeLib("ERRORHANDLINGCOMPONENTSLib")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace ERRORHANDLINGCOMPONENTSLib;

[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("4A6BF833-E252-4ECE-AD80-0C018D669B5A")]
public interface IErrorInfoComponent
{
}
[ComImport]
[CoClass(typeof(ErrorInfoComponentClass))]
[Guid("4A6BF833-E252-4ECE-AD80-0C018D669B5A")]
public interface ErrorInfoComponent : IErrorInfoComponent
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("CE38368B-2BD3-46C1-B34A-4A7C36397E9A")]
[ClassInterface(ClassInterfaceType.None)]
public class ErrorInfoComponentClass : IErrorInfoComponent, ErrorInfoComponent
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("7F7A00DF-B7C4-4E4D-9A95-10527A4555A0")]
public interface IHelpInfoComponent
{
}
[ComImport]
[CoClass(typeof(HelpInfoComponentClass))]
[Guid("7F7A00DF-B7C4-4E4D-9A95-10527A4555A0")]
public interface HelpInfoComponent : IHelpInfoComponent
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual)]
[Guid("1C653C3C-FD22-428F-B31B-0EAFA86E76DA")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IHelpInfo
{
	[DispId(1)]
	string helpFile
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

	[DispId(2)]
	int helpContext
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
	int helpCommand
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[param: In]
		set;
	}
}
[ComImport]
[Guid("4610AC26-D6A9-4D92-93A8-EF13AABADC0B")]
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class HelpInfoComponentClass : IHelpInfoComponent, HelpInfoComponent, IHelpInfo
{
	public virtual extern string helpFile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	public virtual extern int helpContext
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern int helpCommand
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
[Guid("D0228BDD-B913-44F7-8AC5-4A8C4F56D783")]
public interface IErrorAndHelpComponent
{
}
[ComImport]
[CoClass(typeof(ErrorAndHelpComponentClass))]
[Guid("D0228BDD-B913-44F7-8AC5-4A8C4F56D783")]
public interface ErrorAndHelpComponent : IErrorAndHelpComponent
{
}
[ComImport]
[Guid("FFE16BEE-8085-4BD3-87A6-5026F460AEF8")]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[ClassInterface(ClassInterfaceType.None)]
public class ErrorAndHelpComponentClass : IErrorAndHelpComponent, ErrorAndHelpComponent
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("29F8DEB4-A333-41E6-9605-DDE34DC77914")]
public interface IErrorRecordComponent
{
}
[ComImport]
[Guid("29F8DEB4-A333-41E6-9605-DDE34DC77914")]
[CoClass(typeof(ErrorRecordComponentClass))]
public interface ErrorRecordComponent : IErrorRecordComponent
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("5A49CAF5-0E8E-4EBF-8027-54E6CA033F8C")]
[ClassInterface(ClassInterfaceType.None)]
public class ErrorRecordComponentClass : IErrorRecordComponent, ErrorRecordComponent
{
}
