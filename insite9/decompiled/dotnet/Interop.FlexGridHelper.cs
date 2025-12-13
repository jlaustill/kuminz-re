using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: ImportedFromTypeLib("FLEXGRIDHELPERLib")]
[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("36C98255-239C-4151-899E-D6D5C2B16510")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace FLEXGRIDHELPERLib;

[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("A54C7DFE-085A-46D9-8DED-10306917114E")]
public interface IFlexGridHelper
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void setXMLConfigFile([In][MarshalAs(UnmanagedType.BStr)] string FilePath);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void setFlexGrid([In][MarshalAs(UnmanagedType.IUnknown)] object pFlexGrid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void SetECMServices([In][MarshalAs(UnmanagedType.IDispatch)] object pECMServices);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void PopulateGrid();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void ClearGrid();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void PrintGrid([In] bool bShowPrintDialog);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void AddObject([In][MarshalAs(UnmanagedType.BStr)] string Name, [In][MarshalAs(UnmanagedType.IDispatch)] object pDispObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void PrintPreview([In] bool bImagePrinting);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void RefreshData();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	void ShowPageSetup();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	void PrintTo([In][MarshalAs(UnmanagedType.IDispatch)] object pDispPrinter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	void SetPrinter([In][MarshalAs(UnmanagedType.IDispatch)] object pDispPrinter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	bool IsPrinterAvailable();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	void PopulateData([In][MarshalAs(UnmanagedType.Struct)] object nFixedRows, [In][MarshalAs(UnmanagedType.Struct)] object nFixedCols, [In][MarshalAs(UnmanagedType.Struct)] object varData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	void AddValueStore([In][MarshalAs(UnmanagedType.BStr)] string Name, [In][MarshalAs(UnmanagedType.Struct)] object varValue, [In][MarshalAs(UnmanagedType.BStr)] string bstrType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	void AddPageInfoToFooter([In][MarshalAs(UnmanagedType.IDispatch)] object pDispPrinter, [In] bool bIsOverrideFooterInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	void GetLicensedFlexGrid([MarshalAs(UnmanagedType.IUnknown)] out object pUnkVsFlexGrid);
}
[ComImport]
[CoClass(typeof(FlexGridHelperClass))]
[Guid("A54C7DFE-085A-46D9-8DED-10306917114E")]
public interface FlexGridHelper : IFlexGridHelper
{
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
[Guid("36106B3F-8E56-464A-BD10-D4F9D76B13B0")]
[ClassInterface(ClassInterfaceType.None)]
public class FlexGridHelperClass : IFlexGridHelper, FlexGridHelper
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	public virtual extern void setXMLConfigFile([In][MarshalAs(UnmanagedType.BStr)] string FilePath);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void setFlexGrid([In][MarshalAs(UnmanagedType.IUnknown)] object pFlexGrid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	public virtual extern void SetECMServices([In][MarshalAs(UnmanagedType.IDispatch)] object pECMServices);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	public virtual extern void PopulateGrid();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void ClearGrid();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	public virtual extern void PrintGrid([In] bool bShowPrintDialog);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	public virtual extern void AddObject([In][MarshalAs(UnmanagedType.BStr)] string Name, [In][MarshalAs(UnmanagedType.IDispatch)] object pDispObject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	public virtual extern void PrintPreview([In] bool bImagePrinting);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	public virtual extern void RefreshData();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	public virtual extern void ShowPageSetup();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	public virtual extern void PrintTo([In][MarshalAs(UnmanagedType.IDispatch)] object pDispPrinter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	public virtual extern void SetPrinter([In][MarshalAs(UnmanagedType.IDispatch)] object pDispPrinter);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	public virtual extern bool IsPrinterAvailable();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	public virtual extern void PopulateData([In][MarshalAs(UnmanagedType.Struct)] object nFixedRows, [In][MarshalAs(UnmanagedType.Struct)] object nFixedCols, [In][MarshalAs(UnmanagedType.Struct)] object varData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	public virtual extern void AddValueStore([In][MarshalAs(UnmanagedType.BStr)] string Name, [In][MarshalAs(UnmanagedType.Struct)] object varValue, [In][MarshalAs(UnmanagedType.BStr)] string bstrType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	public virtual extern void AddPageInfoToFooter([In][MarshalAs(UnmanagedType.IDispatch)] object pDispPrinter, [In] bool bIsOverrideFooterInfo);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	public virtual extern void GetLicensedFlexGrid([MarshalAs(UnmanagedType.IUnknown)] out object pUnkVsFlexGrid);
}
[ComImport]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
[Guid("AF2C71E3-E3E6-4E95-A9E6-06D98AD21413")]
public interface ISystemDataRepository
{
	[DispId(1)]
	string Value
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[CoClass(typeof(SystemDataRepositoryClass))]
[Guid("AF2C71E3-E3E6-4E95-A9E6-06D98AD21413")]
public interface SystemDataRepository : ISystemDataRepository
{
}
[ComImport]
[ClassInterface(ClassInterfaceType.None)]
[Guid("60E15EF0-4E42-456D-BCDC-CAF0477897F1")]
[TypeLibType(TypeLibTypeFlags.FCanCreate)]
public class SystemDataRepositoryClass : ISystemDataRepository, SystemDataRepository
{
	[DispId(1)]
	public virtual extern string Value
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
