using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("7698c10b-904f-4287-9c5e-de81aa5c91de")]
[assembly: PrimaryInteropAssembly(1, 0)]
[assembly: ImportedFromTypeLib("CILUNITSOFMEASURELib")]
[assembly: AssemblyVersion("3.0.5.17102")]
namespace Cummins.Interop.UnitsOfMeasure;

[Guid("C5EE8DF7-6C70-4529-AEC7-79C179D59027")]
public enum UnitsofMeasureMsgEnum
{
	MSG_DIAG_INVALID_PARAM = 1,
	MSG_DIAG_XML_ERROR,
	MSG_DIAG_CONFIG_ERROR,
	MSG_DIAG_NOT_CONFIGURED,
	MSG_DIAG_UNK_CATEGORY,
	MSG_DIAG_UNK_UNIT,
	MSG_DIAG_UNK_FAMILY,
	MSG_DIAG_DEPENDENCY_ERROR,
	MSG_DIAG_INIT_ERROR,
	MSG_DIAG_CAUGHT_EX
}
public enum tagUnitsofMeasureMsgEnum
{
	MSG_DIAG_INVALID_PARAM = 1,
	MSG_DIAG_XML_ERROR,
	MSG_DIAG_CONFIG_ERROR,
	MSG_DIAG_NOT_CONFIGURED,
	MSG_DIAG_UNK_CATEGORY,
	MSG_DIAG_UNK_UNIT,
	MSG_DIAG_UNK_FAMILY,
	MSG_DIAG_DEPENDENCY_ERROR,
	MSG_DIAG_INIT_ERROR,
	MSG_DIAG_CAUGHT_EX
}
[ComImport]
[ClassInterface(0)]
[Guid("A3C8EFCF-EEC4-45F7-BDF9-D981767D2CAA")]
[TypeLibType(2)]
public class CIUnitsOfMeasureClass : ICIUnitConverter, CIUnitsOfMeasure, ICIAssignMsgGroup
{
	[DispId(2)]
	public virtual extern string Configuration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	public virtual extern string CurrentFamily
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

	public virtual extern int Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	public virtual extern double Convert([In] double inValue, [In][MarshalAs(UnmanagedType.BStr)] string inUnit, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string outUnit);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern double ConvertToUnit([In] double inValue, [In][MarshalAs(UnmanagedType.BStr)] string inUnit, [In][MarshalAs(UnmanagedType.BStr)] string outUnit);
}
[ComImport]
[Guid("2C7B18A1-FB1D-4639-B3AC-932D6A6D701D")]
[CoClass(typeof(CIUnitsOfMeasureClass))]
public interface CIUnitsOfMeasure : ICIUnitConverter
{
}
[ComImport]
[TypeLibType(4160)]
[Guid("2C7B18A1-FB1D-4639-B3AC-932D6A6D701D")]
public interface ICIUnitConverter
{
	[DispId(2)]
	string Configuration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	string CurrentFamily
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

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	double Convert([In] double inValue, [In][MarshalAs(UnmanagedType.BStr)] string inUnit, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string outUnit);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	double ConvertToUnit([In] double inValue, [In][MarshalAs(UnmanagedType.BStr)] string inUnit, [In][MarshalAs(UnmanagedType.BStr)] string outUnit);
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
[Guid("7A84E859-2D78-11D7-8AFD-0004AC965C2E")]
[TypeLibType(2)]
[ClassInterface(0)]
public class SAXContentHandlerClass : SAXContentHandler
{
}
[ComImport]
[CoClass(typeof(SAXContentHandlerClass))]
public interface SAXContentHandler
{
}
[ComImport]
[ClassInterface(0)]
[Guid("9E5AEC0D-2D94-11D7-8AFD-0004AC965C2E")]
[TypeLibType(2)]
public class SAXErrorHandlerClass : SAXErrorHandler
{
}
[ComImport]
[CoClass(typeof(SAXErrorHandlerClass))]
public interface SAXErrorHandler
{
}
