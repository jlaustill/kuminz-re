using System;
using System.Collections;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
using System.Security;
using System.Threading;
using msdatasrc;
using stdole;

[assembly: Guid("c115893a-a3bf-43af-b28d-69db846077f3")]
[assembly: ImportedFromTypeLib("VSFlex8U")]
[assembly: TypeLibVersion(1, 0)]
[assembly: SecurityRules(SecurityRuleSet.Level2)]
[assembly: AssemblyVersion("1.0.0.0")]
namespace VSFlex8U;

public enum ClearWhatSettings
{
	flexClearEverything,
	flexClearText,
	flexClearFormatting,
	flexClearData
}
public enum ClearWhereSettings
{
	flexClearEverywhere,
	flexClearScrollable,
	flexClearSelection
}
public enum SaveExcelSettings
{
	flexXLSaveFixedRows = 1,
	flexXLSaveFixedCols,
	flexXLSaveFixedCells,
	flexXLSaveRaw
}
[ComImport]
[Guid("8951B2CE-ED39-4CF9-AA53-EFE34AE4A24E")]
[TypeLibType(4160)]
[DefaultMember("Text")]
public interface IVSFlexGrid
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-552)]
	[TypeLibFunc(64)]
	void About();

	[DispId(1)]
	string FontName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(1)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(2)]
	float FontSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(3)]
	bool FontBold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(4)]
	bool FontItalic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(5)]
	bool FontStrikethru
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(6)]
	bool FontUnderline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(6)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(6)]
		[param: In]
		set;
	}

	[DispId(7)]
	int Rows
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
	int Cols
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
	short Version
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
	string FormatString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(11)]
	int FixedRows
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[param: In]
		set;
	}

	[DispId(12)]
	int FixedCols
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[param: In]
		set;
	}

	[DispId(13)]
	int TopRow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(13)]
		[param: In]
		set;
	}

	[DispId(14)]
	int LeftCol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(14)]
		[param: In]
		set;
	}

	[DispId(15)]
	int RowSel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(16)]
	int ColSel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(16)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(17)]
	int Row
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(17)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(17)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(18)]
	int Col
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(18)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(18)]
		[param: In]
		set;
	}

	[DispId(0)]
	string Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(-501)]
	uint BackColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-501)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-501)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(-513)]
	uint ForeColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-513)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-513)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(20)]
	[ComAliasName("stdole.OLE_COLOR")]
	uint BackColorFixed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(21)]
	uint ForeColorFixed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(22)]
	uint BackColorSel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(23)]
	uint ForeColorSel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(24)]
	uint BackColorBkg
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(25)]
	bool WordWrap
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		set;
	}

	[DispId(26)]
	TextStyleSettings TextStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		set;
	}

	[DispId(27)]
	TextStyleSettings TextStyleFixed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[param: In]
		set;
	}

	[DispId(28)]
	bool ScrollTrack
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(28)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(28)]
		[param: In]
		set;
	}

	[DispId(29)]
	FocusRectSettings FocusRect
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(29)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(29)]
		[param: In]
		set;
	}

	[DispId(30)]
	ShowSelSettings HighLight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(30)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(30)]
		[param: In]
		set;
	}

	[DispId(31)]
	RedrawSettings Redraw
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(31)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(31)]
		[param: In]
		set;
	}

	[DispId(32)]
	ScrollBarsSettings ScrollBars
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[param: In]
		set;
	}

	[DispId(33)]
	int MouseRow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(34)]
	int MouseCol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(35)]
	int CellLeft
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(35)]
		get;
	}

	[DispId(36)]
	int CellTop
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(36)]
		get;
	}

	[DispId(37)]
	int CellWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(37)]
		get;
	}

	[DispId(38)]
	int CellHeight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(39)]
	int RowHeightMin
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[param: In]
		set;
	}

	[DispId(40)]
	FillStyleSettings FillStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[param: In]
		set;
	}

	[DispId(41)]
	GridStyleSettings GridLines
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(41)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(41)]
		[param: In]
		set;
	}

	[DispId(42)]
	GridStyleSettings GridLinesFixed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(42)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(42)]
		[param: In]
		set;
	}

	[DispId(43)]
	[ComAliasName("stdole.OLE_COLOR")]
	uint GridColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(43)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(43)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(44)]
	[ComAliasName("stdole.OLE_COLOR")]
	uint GridColorFixed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(44)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(44)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(45)]
	[ComAliasName("stdole.OLE_COLOR")]
	uint CellBackColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(45)]
		[TypeLibFunc(1024)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(45)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(46)]
	uint CellForeColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(46)]
		[TypeLibFunc(1024)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(46)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(47)]
	AlignmentSettings CellAlignment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(47)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(47)]
		[param: In]
		set;
	}

	[DispId(48)]
	TextStyleSettings CellTextStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(48)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(48)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(49)]
	IPictureDisp CellPicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(49)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(49)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[TypeLibFunc(1024)]
	[DispId(49)]
	void let_CellPicture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[DispId(50)]
	PictureAlignmentSettings CellPictureAlignment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(50)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(50)]
		[param: In]
		set;
	}

	[DispId(51)]
	string CellFontName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(51)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(51)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(52)]
	float CellFontSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(52)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(52)]
		[param: In]
		set;
	}

	[DispId(53)]
	bool CellFontBold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(53)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(53)]
		[param: In]
		set;
	}

	[DispId(54)]
	bool CellFontItalic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(54)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(54)]
		[param: In]
		set;
	}

	[DispId(55)]
	float CellFontWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(55)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(55)]
		[param: In]
		set;
	}

	[DispId(56)]
	bool CellFontUnderline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(56)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(56)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(57)]
	bool CellFontStrikethru
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(57)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(57)]
		[param: In]
		set;
	}

	[DispId(58)]
	float FontWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(58)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(58)]
		[param: In]
		set;
	}

	[DispId(59)]
	string Clip
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(60)]
	SortSettings Sort
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(60)]
		[param: In]
		set;
	}

	[DispId(61)]
	SelModeSettings SelectionMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		set;
	}

	[DispId(62)]
	MergeSettings MergeCells
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(62)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(62)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(-523)]
	IPictureDisp Picture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(-523)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
	}

	[DispId(64)]
	PictureTypeSettings PictureType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(64)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(64)]
		[param: In]
		set;
	}

	[DispId(65)]
	bool AllowBigSelection
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		[param: In]
		set;
	}

	[DispId(66)]
	AllowUserResizeSettings AllowUserResizing
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		[param: In]
		set;
	}

	[DispId(-521)]
	MousePointerSettings MousePointer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-521)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-521)]
		[param: In]
		set;
	}

	[DispId(-522)]
	[ComAliasName("stdole.IPictureDisp")]
	IPictureDisp MouseIcon
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-522)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-522)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(-522)]
	void let_MouseIcon([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[DispId(68)]
	string DataMember
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(4)]
		[DispId(68)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[TypeLibFunc(4)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(69)]
	DataSource DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(70)]
	bool VirtualData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		[param: In]
		set;
	}

	[DispId(71)]
	EditableSettings Editable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(71)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(71)]
		[param: In]
		set;
	}

	[DispId(72)]
	string ComboList
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(72)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(72)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(73)]
	double Value
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(73)]
		get;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(74)]
	uint FloodColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(74)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(74)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(75)]
	short CellFloodPercent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(75)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(75)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(76)]
	uint CellFloodColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(76)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(76)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(77)]
	SubtotalPositionSettings SubtotalPosition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(77)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(77)]
		[param: In]
		set;
	}

	[DispId(-504)]
	BorderStyleSettings BorderStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-504)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-504)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.IFontDisp")]
	[DispId(-512)]
	IFontDisp Font
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-512)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IFontDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-512)]
		[param: In]
		[param: ComAliasName("stdole.IFontDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(-512)]
	void let_Font([In][ComAliasName("stdole.IFontDisp")][MarshalAs(UnmanagedType.Interface)] IFontDisp pVal);

	[DispId(-514)]
	bool Enabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-514)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-514)]
		[param: In]
		set;
	}

	[DispId(-520)]
	AppearanceSettings Appearance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-520)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-520)]
		[param: In]
		set;
	}

	[DispId(82)]
	OutlineBarSettings OutlineBar
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(82)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(82)]
		[param: In]
		set;
	}

	[DispId(83)]
	[ComAliasName("stdole.OLE_COLOR")]
	uint TreeColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(83)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(83)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(84)]
	short GridLineWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(84)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(84)]
		[param: In]
		set;
	}

	[DispId(85)]
	bool AutoResize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(85)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(85)]
		[param: In]
		set;
	}

	[DispId(86)]
	int BottomRow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(86)]
		get;
	}

	[DispId(87)]
	int RightCol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(87)]
		get;
	}

	[DispId(88)]
	bool ExtendLastCol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(88)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(88)]
		[param: In]
		set;
	}

	[DispId(89)]
	int ClientWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(89)]
		get;
	}

	[DispId(90)]
	int ClientHeight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(90)]
		get;
	}

	[DispId(91)]
	string EditText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(91)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(91)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(-515)]
	int hWnd
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(-515)]
		get;
	}

	[DispId(93)]
	AutoSizeSettings AutoSizeMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(93)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(93)]
		[param: In]
		set;
	}

	[DispId(94)]
	bool RightToLeft
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(94)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(94)]
		[param: In]
		set;
	}

	[DispId(95)]
	bool MultiTotals
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(95)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(95)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(96)]
	uint BackColorAlternate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(96)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(96)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(97)]
	OwnerDrawSettings OwnerDraw
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(97)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(97)]
		[param: In]
		set;
	}

	[DispId(98)]
	DataModeSettings DataMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(98)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(98)]
		[param: In]
		set;
	}

	[DispId(99)]
	OLEDragModeSettings OLEDragMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(99)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(99)]
		[param: In]
		set;
	}

	[DispId(100)]
	OLEDropModeSettings OLEDropMode
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
	TabBehaviorSettings TabBehavior
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
	[ComAliasName("stdole.OLE_COLOR")]
	uint SheetBorder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(103)]
	bool AllowSelection
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
	bool PicturesOver
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		[param: In]
		set;
	}

	[DispId(105)]
	CellCheckedSettings CellChecked
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(105)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(105)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(106)]
	MergeCompareSettings MergeCompare
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(106)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(106)]
		[param: In]
		set;
	}

	[DispId(107)]
	EllipsisSettings Ellipsis
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
	int OutlineCol
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
	int RowHeightMax
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[param: In]
		set;
	}

	[DispId(110)]
	AutoSearchSettings AutoSearch
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(110)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(110)]
		[param: In]
		set;
	}

	[DispId(111)]
	ExplorerBarSettings ExplorerBar
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(111)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(111)]
		[param: In]
		set;
	}

	[DispId(112)]
	string EditMask
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(112)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(112)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(113)]
	int EditSelStart
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(113)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(113)]
		[param: In]
		set;
	}

	[DispId(114)]
	int EditSelLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(114)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(114)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(115)]
	string EditSelText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(115)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(115)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(116)]
	int EditMaxLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(116)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(116)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(117)]
	int ComboIndex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(117)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(117)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(118)]
	int ComboCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(118)]
		get;
	}

	[DispId(119)]
	AlignmentSettings ColAlignment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(119)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(119)]
		[param: In]
		set;
	}

	[DispId(120)]
	int ColWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(120)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(120)]
		[param: In]
		set;
	}

	[DispId(121)]
	int RowHeight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(121)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(121)]
		[param: In]
		set;
	}

	[DispId(122)]
	bool MergeRow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(122)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(122)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(123)]
	bool MergeCol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(123)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(123)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(124)]
	int RowPosition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(124)]
		[param: In]
		set;
	}

	[DispId(125)]
	int ColPosition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(125)]
		[param: In]
		set;
	}

	[DispId(126)]
	object RowData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(126)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(126)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(127)]
	object ColData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(127)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(127)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(128)]
	void AddItem([MarshalAs(UnmanagedType.BStr)] string Item, [Optional][MarshalAs(UnmanagedType.Struct)] object Row);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(129)]
	void RemoveItem([Optional][MarshalAs(UnmanagedType.Struct)] object Row);

	[DispId(130)]
	string TextMatrix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(130)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(130)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(131)]
	void Clear([Optional][MarshalAs(UnmanagedType.Struct)] object Where, [Optional][MarshalAs(UnmanagedType.Struct)] object What);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(132)]
	void EditCell();

	[DispId(133)]
	double ValueMatrix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(133)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(134)]
	bool IsSubtotal
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(134)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(134)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(135)]
	void Subtotal(SubtotalSettings Function, [Optional][MarshalAs(UnmanagedType.Struct)] object GroupOn, [Optional][MarshalAs(UnmanagedType.Struct)] object TotalOn, [Optional][MarshalAs(UnmanagedType.Struct)] object Format, [Optional][MarshalAs(UnmanagedType.Struct)] object BackColor, [Optional][MarshalAs(UnmanagedType.Struct)] object ForeColor, [Optional][MarshalAs(UnmanagedType.Struct)] object FontBold, [Optional][MarshalAs(UnmanagedType.Struct)] object Caption, [Optional][MarshalAs(UnmanagedType.Struct)] object MatchFrom, [Optional][MarshalAs(UnmanagedType.Struct)] object TotalOnly);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-550)]
	void Refresh();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(137)]
	void Outline(short Level);

	[DispId(138)]
	AlignmentSettings FixedAlignment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(138)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(138)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(139)]
	bool RowIsVisible
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(139)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(140)]
	bool ColIsVisible
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(140)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(141)]
	int RowPos
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(141)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(142)]
	int ColPos
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(142)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(143)]
	bool IsSelected
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(143)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(143)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(144)]
	string TextArray
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(144)]
		[TypeLibFunc(64)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(144)]
		[TypeLibFunc(64)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(145)]
	CollapsedSettings IsCollapsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(145)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(145)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(146)]
	void Select(int Row, int Col, [Optional][MarshalAs(UnmanagedType.Struct)] object RowSel, [Optional][MarshalAs(UnmanagedType.Struct)] object ColSel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(147)]
	void AutoSize(int Col1, [Optional][MarshalAs(UnmanagedType.Struct)] object Col2, [Optional][MarshalAs(UnmanagedType.Struct)] object Equal, [Optional][MarshalAs(UnmanagedType.Struct)] object ExtraSpace);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(148)]
	void DataRefresh();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(149)]
	void CellBorder([ComAliasName("stdole.OLE_COLOR")] uint Color, short Left, short Top, short Right, short Bottom, short Vertical, short Horizontal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(150)]
	void OLEDrag();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(151)]
	void SaveGrid([MarshalAs(UnmanagedType.BStr)] string FileName, SaveLoadSettings SaveWhat, [Optional][MarshalAs(UnmanagedType.Struct)] object Options);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(152)]
	void LoadGrid([MarshalAs(UnmanagedType.BStr)] string FileName, SaveLoadSettings LoadWhat, [Optional][MarshalAs(UnmanagedType.Struct)] object Options);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(153)]
	void Archive([MarshalAs(UnmanagedType.BStr)] string ArcFileName, [MarshalAs(UnmanagedType.BStr)] string FileName, ArchiveSettings Action);

	[DispId(154)]
	object ArchiveInfo
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(154)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(155)]
	SortSettings ColSort
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(155)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(155)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(156)]
	string ColFormat
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(156)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(156)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(157)]
	DataTypeSettings ColDataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(157)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(157)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(158)]
	object Cell
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(158)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(158)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(158)]
	[TypeLibFunc(1024)]
	void let_Cell(CellPropertySettings Setting, [Optional][MarshalAs(UnmanagedType.Struct)] object Row1, [Optional][MarshalAs(UnmanagedType.Struct)] object Col1, [Optional][MarshalAs(UnmanagedType.Struct)] object Row2, [Optional][MarshalAs(UnmanagedType.Struct)] object Col2, [In][MarshalAs(UnmanagedType.Struct)] object pVal);

	[DispId(159)]
	RowStatusSettings RowStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(159)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(159)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(160)]
	int FindRow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(160)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(161)]
	string ComboItem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(161)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(162)]
	string ComboData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(162)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(163)]
	void BindToArray([Optional][MarshalAs(UnmanagedType.Struct)] object VariantArray, [Optional][MarshalAs(UnmanagedType.Struct)] object RowDim, [Optional][MarshalAs(UnmanagedType.Struct)] object ColDim, [Optional][MarshalAs(UnmanagedType.Struct)] object PageDim, [Optional][MarshalAs(UnmanagedType.Struct)] object CurrentPage);

	[DispId(164)]
	string ColEditMask
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(164)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(164)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(165)]
	string ColComboList
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(165)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(165)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(166)]
	short RowOutlineLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(166)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(166)]
		[param: In]
		set;
	}

	[DispId(167)]
	int SelectedRows
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(167)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(168)]
	int SelectedRow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(168)]
		get;
	}

	[DispId(169)]
	bool ScrollTips
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(169)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(169)]
		[param: In]
		set;
	}

	[DispId(170)]
	string ScrollTipText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(170)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(170)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(171)]
	bool RowHidden
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(171)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(171)]
		[param: In]
		set;
	}

	[DispId(172)]
	bool ColHidden
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(172)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(172)]
		[param: In]
		set;
	}

	[DispId(173)]
	int ColWidthMin
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(173)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(173)]
		[param: In]
		set;
	}

	[DispId(174)]
	int ColWidthMax
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(174)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(174)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(175)]
	void GetMergedRange(int Row, int Col, ref int R1, ref int C1, ref int R2, ref int C2);

	[DispId(176)]
	ShowButtonSettings ShowComboButton
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(176)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(176)]
		[param: In]
		set;
	}

	[DispId(177)]
	[ComAliasName("stdole.IPictureDisp")]
	IPictureDisp CellButtonPicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(177)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(177)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(177)]
	void let_CellButtonPicture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[DispId(178)]
	ComboSearchSettings ComboSearch
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(178)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(178)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(179)]
	void LoadArray([Optional][MarshalAs(UnmanagedType.Struct)] object VariantArray, [Optional][MarshalAs(UnmanagedType.Struct)] object RowDim, [Optional][MarshalAs(UnmanagedType.Struct)] object ColDim, [Optional][MarshalAs(UnmanagedType.Struct)] object PageDim, [Optional][MarshalAs(UnmanagedType.Struct)] object CurrentPage);

	[DispId(180)]
	bool AutoSizeMouse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(180)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(180)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(181)]
	void GetSelection(ref int Row1, ref int Col1, ref int Row2, ref int Col2);

	[DispId(182)]
	string ClipSeparators
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(182)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(182)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(183)]
	void PrintGrid([Optional][In][MarshalAs(UnmanagedType.Struct)] object DocName, [Optional][In][MarshalAs(UnmanagedType.Struct)] object ShowDialog, [Optional][In][MarshalAs(UnmanagedType.Struct)] object Orientation, [Optional][In][MarshalAs(UnmanagedType.Struct)] object MarginLR, [Optional][In][MarshalAs(UnmanagedType.Struct)] object MarginTB);

	[DispId(184)]
	int ColImageList
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(184)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(184)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(185)]
	string ColKey
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(185)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(185)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(186)]
	int ColIndex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(186)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(188)]
	int FrozenRows
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(188)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(188)]
		[param: In]
		set;
	}

	[DispId(189)]
	int FrozenCols
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(189)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(189)]
		[param: In]
		set;
	}

	[DispId(190)]
	AllowUserFreezeSettings AllowUserFreezing
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(190)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(190)]
		[param: In]
		set;
	}

	[DispId(191)]
	[ComAliasName("stdole.OLE_COLOR")]
	uint BackColorFrozen
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(191)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(191)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(192)]
	[ComAliasName("stdole.OLE_COLOR")]
	uint ForeColorFrozen
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(192)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(192)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(193)]
	IVSFlexDataSource FlexDataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(193)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(193)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(194)]
	int GetNodeRow([In] int Row, [In] NodeTypeSettings Which);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(195)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string BuildComboList([MarshalAs(UnmanagedType.IDispatch)] object rs, [MarshalAs(UnmanagedType.BStr)] string FieldList, [Optional][MarshalAs(UnmanagedType.Struct)] object KeyField, [Optional][MarshalAs(UnmanagedType.Struct)] object BackColor);

	[DispId(196)]
	[ComAliasName("stdole.IPictureDisp")]
	IPictureDisp NodeOpenPicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(196)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(196)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(196)]
	void let_NodeOpenPicture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(197)]
	IPictureDisp NodeClosedPicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(197)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(197)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(197)]
	void let_NodeClosedPicture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(198)]
	void ShowCell(int Row, int Col);

	[DispId(199)]
	float AutoSearchDelay
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(199)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(199)]
		[param: In]
		set;
	}

	[DispId(200)]
	int EditWindow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(200)]
		get;
	}

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(201)]
	IPictureDisp WallPaper
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(201)]
	void let_WallPaper([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[DispId(202)]
	PictureAlignmentSettings WallPaperAlignment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[param: In]
		set;
	}

	[DispId(203)]
	double Aggregate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(203)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(204)]
	int DragRow(int Row);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(205)]
	[return: MarshalAs(UnmanagedType.Interface)]
	VSFlexNode GetNode([Optional][MarshalAs(UnmanagedType.Struct)] object Row);

	[DispId(206)]
	object Bookmark
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(206)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(207)]
	int ColIndent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(207)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(207)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(210)]
	void LoadGridURL([MarshalAs(UnmanagedType.BStr)] string URL, SaveLoadSettings LoadWhat, [Optional][MarshalAs(UnmanagedType.Struct)] object Options);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(211)]
	void FinishEditing([In] bool Cancel);

	[DispId(212)]
	string AccessibleName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(212)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(212)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(213)]
	string AccessibleDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(213)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(213)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(214)]
	string AccessibleValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(214)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(214)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(215)]
	object AccessibleRole
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(215)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(215)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(216)]
	bool IsSearching
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(216)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(217)]
	ControlFlagsSettings Flags
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(217)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(217)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(218)]
	MergeSettings MergeCellsFixed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(218)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(218)]
		[param: In]
		set;
	}

	[DispId(219)]
	MergeCompareSettings GroupCompare
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(219)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(219)]
		[param: In]
		set;
	}

	[DispId(220)]
	[ComAliasName("stdole.IPictureDisp")]
	IPictureDisp SortAscendingPicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(220)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(220)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[TypeLibFunc(1024)]
	[DispId(220)]
	void let_SortAscendingPicture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(221)]
	IPictureDisp SortDescendingPicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(221)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(221)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(221)]
	[TypeLibFunc(1024)]
	void let_SortDescendingPicture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[DispId(222)]
	int FindRowRegex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(222)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(223)]
	void CellBorderRange(int Row1, int Col1, int Row2, int Col2, [ComAliasName("stdole.OLE_COLOR")] uint Color, short Left, short Top, short Right, short Bottom, short Vertical, short Horizontal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(224)]
	void Cut();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(225)]
	void Copy();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(226)]
	void Paste();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(227)]
	void Delete();
}
public enum TextStyleSettings
{
	flexTextFlat,
	flexTextRaised,
	flexTextInset,
	flexTextRaisedLight,
	flexTextInsetLight
}
public enum FocusRectSettings
{
	flexFocusNone,
	flexFocusLight,
	flexFocusHeavy,
	flexFocusSolid,
	flexFocusRaised,
	flexFocusInset
}
public enum ShowSelSettings
{
	flexHighlightNever,
	flexHighlightAlways,
	flexHighlightWithFocus
}
public enum RedrawSettings
{
	flexRDNone,
	flexRDDirect,
	flexRDBuffered
}
public enum ScrollBarsSettings
{
	flexScrollBarNone,
	flexScrollBarHorizontal,
	flexScrollBarVertical,
	flexScrollBarBoth
}
public enum FillStyleSettings
{
	flexFillSingle,
	flexFillRepeat
}
public enum GridStyleSettings
{
	flexGridNone,
	flexGridFlat,
	flexGridInset,
	flexGridRaised,
	flexGridFlatHorz,
	flexGridInsetHorz,
	flexGridRaisedHorz,
	flexGridSkipHorz,
	flexGridFlatVert,
	flexGridInsetVert,
	flexGridRaisedVert,
	flexGridSkipVert,
	flexGridExplorer,
	flexGridExcel,
	flexGridDataGrid
}
public enum AlignmentSettings
{
	flexAlignLeftTop,
	flexAlignLeftCenter,
	flexAlignLeftBottom,
	flexAlignCenterTop,
	flexAlignCenterCenter,
	flexAlignCenterBottom,
	flexAlignRightTop,
	flexAlignRightCenter,
	flexAlignRightBottom,
	flexAlignGeneral,
	flexAlignGeneralTop,
	flexAlignGeneralCenter,
	flexAlignGeneralBottom
}
public enum PictureAlignmentSettings
{
	flexPicAlignLeftTop,
	flexPicAlignLeftCenter,
	flexPicAlignLeftBottom,
	flexPicAlignCenterTop,
	flexPicAlignCenterCenter,
	flexPicAlignCenterBottom,
	flexPicAlignRightTop,
	flexPicAlignRightCenter,
	flexPicAlignRightBottom,
	flexPicAlignStretch,
	flexPicAlignTile
}
public enum SortSettings
{
	flexSortNone,
	flexSortGenericAscending,
	flexSortGenericDescending,
	flexSortNumericAscending,
	flexSortNumericDescending,
	flexSortStringNoCaseAscending,
	flexSortStringNoCaseDescending,
	flexSortStringAscending,
	flexSortStringDescending,
	flexSortCustom,
	flexSortUseColSort
}
public enum SelModeSettings
{
	flexSelectionFree,
	flexSelectionByRow,
	flexSelectionByColumn,
	flexSelectionListBox
}
public enum MergeSettings
{
	flexMergeNever,
	flexMergeFree,
	flexMergeRestrictRows,
	flexMergeRestrictColumns,
	flexMergeRestrictAll,
	flexMergeFixedOnly,
	flexMergeSpill,
	flexMergeOutline
}
public enum PictureTypeSettings
{
	flexPictureColor,
	flexPictureMonochrome,
	flexPictureEnhMetafile
}
public enum AllowUserResizeSettings
{
	flexResizeNone,
	flexResizeColumns,
	flexResizeRows,
	flexResizeBoth,
	flexResizeBothUniform
}
public enum MousePointerSettings
{
	flexDefault = 0,
	flexArrow = 1,
	flexCross = 2,
	flexIBeam = 3,
	flexIcon = 4,
	flexSize = 5,
	flexSizeNESW = 6,
	flexSizeNS = 7,
	flexSizeNWSE = 8,
	flexSizeEW = 9,
	flexUpArrow = 10,
	flexHourglass = 11,
	flexNoDrop = 12,
	flexArrowHourGlass = 13,
	flexArrowQuestion = 14,
	flexSizeAll = 15,
	flexPointerCopy = 50,
	flexPointerMove = 51,
	flexSizeHorz = 52,
	flexSizeVert = 53,
	flexHand = 54,
	flexCustom = 99
}
public enum EditableSettings
{
	flexEDNone,
	flexEDKbd,
	flexEDKbdMouse
}
public enum SubtotalPositionSettings
{
	flexSTBelow,
	flexSTAbove
}
public enum BorderStyleSettings
{
	flexBorderNone,
	flexBorderFlat
}
public enum AppearanceSettings
{
	flexFlat,
	flex3D,
	flex3DLight,
	flexXPThemes
}
public enum OutlineBarSettings
{
	flexOutlineBarNone,
	flexOutlineBarComplete,
	flexOutlineBarSimple,
	flexOutlineBarSymbols,
	flexOutlineBarCompleteLeaf,
	flexOutlineBarSimpleLeaf,
	flexOutlineBarSymbolsLeaf
}
public enum AutoSizeSettings
{
	flexAutoSizeColWidth,
	flexAutoSizeRowHeight
}
public enum OwnerDrawSettings
{
	flexODNone,
	flexODOver,
	flexODContent,
	flexODComplete,
	flexODOverFixed,
	flexODContentFixed,
	flexODCompleteFixed
}
public enum DataModeSettings
{
	flexDMFree,
	flexDMBound,
	flexDMBoundBatch,
	flexDMBoundImmediate,
	flexDMBoundNoRowCount
}
public enum OLEDragModeSettings
{
	flexOLEDragManual,
	flexOLEDragAutomatic
}
public enum OLEDropModeSettings
{
	flexOLEDropNone,
	flexOLEDropManual,
	flexOLEDropAutomatic
}
public enum TabBehaviorSettings
{
	flexTabControls,
	flexTabCells
}
public enum CellCheckedSettings
{
	flexNoCheckbox,
	flexChecked,
	flexUnchecked,
	flexTSChecked,
	flexTSUnchecked,
	flexTSGrayed
}
public enum MergeCompareSettings
{
	flexMCExact,
	flexMCNoCase,
	flexMCTrimNoCase,
	flexMCIncludeNulls
}
public enum EllipsisSettings
{
	flexNoEllipsis,
	flexEllipsisEnd,
	flexEllipsisPath
}
public enum AutoSearchSettings
{
	flexSearchNone,
	flexSearchFromTop,
	flexSearchFromCursor
}
public enum ExplorerBarSettings
{
	flexExNone = 0,
	flexExSort = 1,
	flexExMove = 2,
	flexExSortAndMove = 3,
	flexExSortShow = 5,
	flexExSortShowAndMove = 7,
	flexExMoveRows = 8
}
public enum SubtotalSettings
{
	flexSTNone,
	flexSTClear,
	flexSTSum,
	flexSTPercent,
	flexSTCount,
	flexSTAverage,
	flexSTMax,
	flexSTMin,
	flexSTStd,
	flexSTVar,
	flexSTStdPop,
	flexSTVarPop
}
public enum CollapsedSettings
{
	flexOutlineExpanded,
	flexOutlineSubtotals,
	flexOutlineCollapsed
}
public enum SaveLoadSettings
{
	flexFileAll,
	flexFileData,
	flexFileFormat,
	flexFileCommaText,
	flexFileTabText,
	flexFileCustomText,
	flexFileExcel
}
public enum ArchiveSettings
{
	arcAdd,
	arcStore,
	arcExtract,
	arcDelete
}
public enum ArchiveInfoSettings
{
	arcFileCount,
	ArcFileName,
	arcFileSize,
	arcFileCompressedSize,
	arcFileDate
}
public enum DataTypeSettings
{
	flexDTEmpty = 0,
	flexDTNull = 1,
	flexDTShort = 2,
	flexDTLong = 3,
	flexDTSingle = 4,
	flexDTDouble = 5,
	flexDTCurrency = 6,
	flexDTDate = 7,
	flexDTString = 8,
	flexDTDispatch = 9,
	flexDTError = 10,
	flexDTBoolean = 11,
	flexDTVariant = 12,
	flexDTUnknown = 13,
	flexDTDecimal = 14,
	flexDTLong8 = 20,
	flexDTStringC = 30,
	flexDTStringW = 31
}
public enum CellPropertySettings
{
	flexcpText,
	flexcpTextStyle,
	flexcpAlignment,
	flexcpPicture,
	flexcpPictureAlignment,
	flexcpChecked,
	flexcpBackColor,
	flexcpForeColor,
	flexcpFloodPercent,
	flexcpFloodColor,
	flexcpFont,
	flexcpFontName,
	flexcpFontSize,
	flexcpFontBold,
	flexcpFontItalic,
	flexcpFontUnderline,
	flexcpFontStrikethru,
	flexcpFontWidth,
	flexcpValue,
	flexcpTextDisplay,
	flexcpData,
	flexcpCustomFormat,
	flexcpLeft,
	flexcpTop,
	flexcpWidth,
	flexcpHeight,
	flexcpVariantValue,
	flexcpRefresh,
	flexcpSort
}
public enum RowStatusSettings
{
	flexrsNew,
	flexrsUpdated,
	flexrsModified,
	flexrsDeleted
}
public enum ShowButtonSettings
{
	flexSBEditing,
	flexSBFocus,
	flexSBAlways
}
public enum ComboSearchSettings
{
	flexCmbSearchNone,
	flexCmbSearchLists,
	flexCmbSearchCombos,
	flexCmbSearchAll
}
public enum AllowUserFreezeSettings
{
	flexFreezeNone,
	flexFreezeColumns,
	flexFreezeRows,
	flexFreezeBoth
}
[ComImport]
[InterfaceType(1)]
[Guid("8E203240-537D-11D3-BD8C-000000000000")]
[TypeLibType(64)]
public interface IVSFlexDataSource
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	int GetFieldCount();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	int GetRecordCount();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetFieldName([In] int Field);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetData([In] int Field, [In] int Record);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void SetData([In] int Field, [In] int Record, [In][MarshalAs(UnmanagedType.BStr)] string newData);
}
public enum NodeTypeSettings
{
	flexNTRoot,
	flexNTParent,
	flexNTFirstChild,
	flexNTLastChild,
	flexNTFirstSibling,
	flexNTLastSibling,
	flexNTNextSibling,
	flexNTPreviousSibling
}
[ComImport]
[DefaultMember("Text")]
[Guid("666C0896-C89F-4A8D-A92A-6BA9CD3C7623")]
[TypeLibType(4160)]
public interface IVSFlexNode
{
	[DispId(0)]
	string Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1)]
	string Key
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

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(2)]
	IPictureDisp Image
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(2)]
	void let_Image([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[DispId(3)]
	bool Expanded
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
	short Level
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}

	[DispId(5)]
	int Children
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
	}

	[DispId(6)]
	int Row
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	bool Move(NodeMoveSettings MoveTo, [Optional][MarshalAs(UnmanagedType.Struct)] object TargetNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void Sort(SortSettings How);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void EnsureVisible();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	void Select();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	[return: MarshalAs(UnmanagedType.Interface)]
	VSFlexNode GetNode(NodeTypeSettings Which);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	[return: MarshalAs(UnmanagedType.Interface)]
	VSFlexNode AddNode(NodeTypeSettings AddWhere, [MarshalAs(UnmanagedType.BStr)] string Item, [Optional][MarshalAs(UnmanagedType.Struct)] object Key, [Optional][MarshalAs(UnmanagedType.Struct)] object Image);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	void RemoveNode();
}
public enum NodeMoveSettings
{
	flexNMIn,
	flexNMOut,
	flexNMUp,
	flexNMDown,
	flexNMFirst,
	flexNMLast,
	flexNMChildOf
}
public enum ControlFlagsSettings
{
	flexCFNone = 0,
	flexCFV7SelectionEvents = 1,
	flexCFAutoClipboard = 2,
	flexCFNoEditIndent = 4,
	flexCFBindToBinaryFields = 8
}
[ComImport]
[TypeLibType(4096)]
[InterfaceType(2)]
[Guid("F9EAA4F2-AC4F-4759-B9D2-B8462B8E293E")]
public interface _IVSFlexGridEvents
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-600)]
	void Click();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-601)]
	void DblClick();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-602)]
	void KeyDown([In][Out] ref short KeyCode, short Shift);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-603)]
	void KeyPress([In][Out] ref short KeyAscii);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-604)]
	void KeyUp([In][Out] ref short KeyCode, short Shift);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-605)]
	void MouseDown(short Button, short Shift, float X, float Y);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-606)]
	void MouseMove(short Button, short Shift, float X, float Y);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-607)]
	void MouseUp(short Button, short Shift, float X, float Y);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void SelChange();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void RowColChange();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void EnterCell();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void LeaveCell();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void BeforeMouseDown(short Button, short Shift, float X, float Y, [In][Out] ref bool Cancel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void BeforeRowColChange(int OldRow, int OldCol, int NewRow, int NewCol, [In][Out] ref bool Cancel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void AfterRowColChange(int OldRow, int OldCol, int NewRow, int NewCol);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void BeforeSelChange(int OldRowSel, int OldColSel, int NewRowSel, int NewColSel, [In][Out] ref bool Cancel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void AfterSelChange(int OldRowSel, int OldColSel, int NewRowSel, int NewColSel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	void BeforeScroll(int OldTopRow, int OldLeftCol, int NewTopRow, int NewLeftCol, [In][Out] ref bool Cancel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	void AfterScroll(int OldTopRow, int OldLeftCol, int NewTopRow, int NewLeftCol);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	void Compare(int Row1, int Row2, [In][Out] ref short Cmp);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	void BeforeSort(int Col, [In][Out] ref short Order);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	void AfterSort(int Col, [In][Out] ref short Order);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	void BeforeMoveColumn(int Col, [In][Out] ref int Position);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(16)]
	void AfterMoveColumn(int Col, [In][Out] ref int Position);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	void BeforeUserResize(int Row, int Col, [In][Out] ref bool Cancel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	void AfterUserResize(int Row, int Col);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	void BeforeCollapse(int Row, short State, [In][Out] ref bool Cancel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(20)]
	void AfterCollapse(int Row, short State);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(21)]
	void BeforeEdit(int Row, int Col, [In][Out] ref bool Cancel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(22)]
	void StartEdit(int Row, int Col, [In][Out] ref bool Cancel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(23)]
	void ValidateEdit(int Row, int Col, [In][Out] ref bool Cancel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(24)]
	void AfterEdit(int Row, int Col);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(25)]
	void KeyPressEdit(int Row, int Col, [In][Out] ref short KeyAscii);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(26)]
	void KeyDownEdit(int Row, int Col, [In][Out] ref short KeyCode, short Shift);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(27)]
	void KeyUpEdit(int Row, int Col, [In][Out] ref short KeyCode, short Shift);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(28)]
	void ChangeEdit();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(29)]
	void BeforePageBreak(int Row, [In][Out] ref bool BreakOK);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(30)]
	void GetHeaderRow(int Row, [In][Out] ref int HeaderRow);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(31)]
	void StartPage(int hDC, int Page, [In][Out] ref bool Cancel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(32)]
	void DrawCell(int hDC, int Row, int Col, int Left, int Top, int Right, int Bottom, [In][Out] ref bool Done);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(33)]
	void Error(int ErrorCode, [In][Out] ref bool ShowMsgBox);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(34)]
	void CellButtonClick(int Row, int Col);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(35)]
	void BeforeScrollTip(int Row);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(36)]
	void AfterUserFreeze();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(37)]
	void OLEStartDrag([MarshalAs(UnmanagedType.Interface)] ref VSDataObject Data, [In][Out] ref int AllowedEffects);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(38)]
	void OLEGiveFeedback(ref int Effect, [In][Out] ref bool DefaultCursors);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(39)]
	void OLESetData([MarshalAs(UnmanagedType.Interface)] ref VSDataObject Data, [In][Out] ref short DataFormat);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(40)]
	void OLECompleteDrag([In][Out] ref int Effect);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(41)]
	void OLEDragOver([MarshalAs(UnmanagedType.Interface)] ref VSDataObject Data, [In][Out] ref int Effect, short Button, short Shift, float X, float Y, [In][Out] ref short State);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(42)]
	void OLEDragDrop([MarshalAs(UnmanagedType.Interface)] ref VSDataObject Data, [In][Out] ref int Effect, short Button, short Shift, float X, float Y);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(47)]
	void OLESetCustomDataObject([In][Out][MarshalAs(UnmanagedType.Struct)] ref object CustomDataObject);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(43)]
	void CellChanged(int Row, int Col);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(44)]
	void BeforeMoveRow(int Row, [In][Out] ref int Position);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(45)]
	void AfterMoveRow(int Row, [In][Out] ref int Position);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(46)]
	void SetupEditWindow(int Row, int Col, int EditWindow, bool IsCombo);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(48)]
	void SetupEditStyle(int Row, int Col, bool IsCombo, ref int Style, ref int StyleEx);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(49)]
	void ComboDropDown(int Row, int Col);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(50)]
	void ComboCloseUp(int Row, int Col, ref bool FinishEdit);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(51)]
	void StartAutoSearch();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(52)]
	void EndAutoSearch();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(80)]
	void FilterData(int Row, int Col, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string Value, bool SavingToDB, [In][Out] ref bool WantThisCol);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(81)]
	void BeforeDataRefresh([In][Out] ref bool Cancel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(82)]
	void AfterDataRefresh();
}
[ComImport]
[Guid("8B1B2E13-0F5D-4CC8-925A-769E6091D633")]
[ClassInterface(0)]
[TypeLibType(2)]
public class VSDataObjectClass : IVSDataObject, VSDataObject
{
	[DispId(2)]
	public virtual extern short FileCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[DispId(3)]
	public virtual extern object GetData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(4)]
	public virtual extern bool GetFormat
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}

	[DispId(5)]
	public virtual extern string Files
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	public virtual extern void Clear();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	public virtual extern void SetData([MarshalAs(UnmanagedType.Struct)] object Value, [Optional][MarshalAs(UnmanagedType.Struct)] object Format);
}
[ComImport]
[Guid("72C7C49C-B3A0-4244-8F65-80E6C29D15A6")]
[CoClass(typeof(VSDataObjectClass))]
public interface VSDataObject : IVSDataObject
{
}
[ComImport]
[Guid("72C7C49C-B3A0-4244-8F65-80E6C29D15A6")]
[TypeLibType(4160)]
public interface IVSDataObject
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void Clear();

	[DispId(2)]
	short FileCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[DispId(3)]
	object GetData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(4)]
	bool GetFormat
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}

	[DispId(5)]
	string Files
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void SetData([MarshalAs(UnmanagedType.Struct)] object Value, [Optional][MarshalAs(UnmanagedType.Struct)] object Format);
}
[ComImport]
[TypeLibType(2)]
[DefaultMember("Text")]
[Guid("3705B4E2-8FCB-4A21-8CCE-5D6A98C32456")]
[ComSourceInterfaces("VSFlex8U._IVSFlexGridEvents\0\0")]
[ClassInterface(0)]
public class VSFlexGridClass : IVSFlexGrid, VSFlexGrid, _IVSFlexGridEvents_Event
{
	[DispId(1)]
	public virtual extern string FontName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(2)]
	public virtual extern float FontSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(2)]
		[param: In]
		set;
	}

	[DispId(3)]
	public virtual extern bool FontBold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(4)]
	public virtual extern bool FontItalic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(4)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(4)]
		[param: In]
		set;
	}

	[DispId(5)]
	public virtual extern bool FontStrikethru
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(5)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(6)]
	public virtual extern bool FontUnderline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(6)]
		[param: In]
		set;
	}

	[DispId(7)]
	public virtual extern int Rows
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
	public virtual extern int Cols
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
	public virtual extern short Version
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
	public virtual extern string FormatString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(11)]
	public virtual extern int FixedRows
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[param: In]
		set;
	}

	[DispId(12)]
	public virtual extern int FixedCols
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[param: In]
		set;
	}

	[DispId(13)]
	public virtual extern int TopRow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(13)]
		[param: In]
		set;
	}

	[DispId(14)]
	public virtual extern int LeftCol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(15)]
	public virtual extern int RowSel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(15)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(15)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(16)]
	public virtual extern int ColSel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(16)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(17)]
	public virtual extern int Row
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(17)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(17)]
		[param: In]
		set;
	}

	[DispId(18)]
	public virtual extern int Col
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(18)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(0)]
	public virtual extern string Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(-501)]
	[ComAliasName("stdole.OLE_COLOR")]
	public virtual extern uint BackColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-501)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-501)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(-513)]
	public virtual extern uint ForeColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-513)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-513)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(20)]
	[ComAliasName("stdole.OLE_COLOR")]
	public virtual extern uint BackColorFixed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(21)]
	[ComAliasName("stdole.OLE_COLOR")]
	public virtual extern uint ForeColorFixed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(22)]
	public virtual extern uint BackColorSel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(23)]
	[ComAliasName("stdole.OLE_COLOR")]
	public virtual extern uint ForeColorSel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(23)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(24)]
	public virtual extern uint BackColorBkg
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(25)]
	public virtual extern bool WordWrap
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[param: In]
		set;
	}

	[DispId(26)]
	public virtual extern TextStyleSettings TextStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[param: In]
		set;
	}

	[DispId(27)]
	public virtual extern TextStyleSettings TextStyleFixed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[param: In]
		set;
	}

	[DispId(28)]
	public virtual extern bool ScrollTrack
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(28)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(28)]
		[param: In]
		set;
	}

	[DispId(29)]
	public virtual extern FocusRectSettings FocusRect
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(29)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(29)]
		[param: In]
		set;
	}

	[DispId(30)]
	public virtual extern ShowSelSettings HighLight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(30)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(30)]
		[param: In]
		set;
	}

	[DispId(31)]
	public virtual extern RedrawSettings Redraw
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(31)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(31)]
		[param: In]
		set;
	}

	[DispId(32)]
	public virtual extern ScrollBarsSettings ScrollBars
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[param: In]
		set;
	}

	[DispId(33)]
	public virtual extern int MouseRow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(34)]
	public virtual extern int MouseCol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(34)]
		get;
	}

	[DispId(35)]
	public virtual extern int CellLeft
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(35)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(36)]
	public virtual extern int CellTop
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(36)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(37)]
	public virtual extern int CellWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(37)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(38)]
	public virtual extern int CellHeight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(38)]
		get;
	}

	[DispId(39)]
	public virtual extern int RowHeightMin
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[param: In]
		set;
	}

	[DispId(40)]
	public virtual extern FillStyleSettings FillStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(40)]
		[param: In]
		set;
	}

	[DispId(41)]
	public virtual extern GridStyleSettings GridLines
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(41)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(41)]
		[param: In]
		set;
	}

	[DispId(42)]
	public virtual extern GridStyleSettings GridLinesFixed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(42)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(42)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(43)]
	public virtual extern uint GridColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(43)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(43)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(44)]
	public virtual extern uint GridColorFixed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(44)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(44)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(45)]
	public virtual extern uint CellBackColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(45)]
		[TypeLibFunc(1024)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(45)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(46)]
	public virtual extern uint CellForeColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(46)]
		[TypeLibFunc(1024)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(46)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(47)]
	public virtual extern AlignmentSettings CellAlignment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(47)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(47)]
		[param: In]
		set;
	}

	[DispId(48)]
	public virtual extern TextStyleSettings CellTextStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(48)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(48)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(49)]
	public virtual extern IPictureDisp CellPicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(49)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(49)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(50)]
	public virtual extern PictureAlignmentSettings CellPictureAlignment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(50)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(50)]
		[param: In]
		set;
	}

	[DispId(51)]
	public virtual extern string CellFontName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(51)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(51)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(52)]
	public virtual extern float CellFontSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(52)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(52)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(53)]
	public virtual extern bool CellFontBold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(53)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(53)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(54)]
	public virtual extern bool CellFontItalic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(54)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(54)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(55)]
	public virtual extern float CellFontWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(55)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(55)]
		[param: In]
		set;
	}

	[DispId(56)]
	public virtual extern bool CellFontUnderline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(56)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(56)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(57)]
	public virtual extern bool CellFontStrikethru
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(57)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(57)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(58)]
	public virtual extern float FontWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(58)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(58)]
		[param: In]
		set;
	}

	[DispId(59)]
	public virtual extern string Clip
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(59)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(60)]
	public virtual extern SortSettings Sort
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(61)]
	public virtual extern SelModeSettings SelectionMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		set;
	}

	[DispId(62)]
	public virtual extern MergeSettings MergeCells
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(62)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(62)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(-523)]
	public virtual extern IPictureDisp Picture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-523)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
	}

	[DispId(64)]
	public virtual extern PictureTypeSettings PictureType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(64)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(64)]
		[param: In]
		set;
	}

	[DispId(65)]
	public virtual extern bool AllowBigSelection
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(65)]
		[param: In]
		set;
	}

	[DispId(66)]
	public virtual extern AllowUserResizeSettings AllowUserResizing
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(66)]
		[param: In]
		set;
	}

	[DispId(-521)]
	public virtual extern MousePointerSettings MousePointer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-521)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-521)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(-522)]
	public virtual extern IPictureDisp MouseIcon
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-522)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-522)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(68)]
	public virtual extern string DataMember
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[TypeLibFunc(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(68)]
		[TypeLibFunc(4)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(69)]
	public virtual extern DataSource DataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(69)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(70)]
	public virtual extern bool VirtualData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(70)]
		[param: In]
		set;
	}

	[DispId(71)]
	public virtual extern EditableSettings Editable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(71)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(71)]
		[param: In]
		set;
	}

	[DispId(72)]
	public virtual extern string ComboList
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(72)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(72)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(73)]
	public virtual extern double Value
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(73)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(74)]
	[ComAliasName("stdole.OLE_COLOR")]
	public virtual extern uint FloodColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(74)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(74)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(75)]
	public virtual extern short CellFloodPercent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(75)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(75)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(76)]
	public virtual extern uint CellFloodColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(76)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(76)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(77)]
	public virtual extern SubtotalPositionSettings SubtotalPosition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(77)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(77)]
		[param: In]
		set;
	}

	[DispId(-504)]
	public virtual extern BorderStyleSettings BorderStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-504)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-504)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.IFontDisp")]
	[DispId(-512)]
	public virtual extern IFontDisp Font
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-512)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IFontDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-512)]
		[param: In]
		[param: ComAliasName("stdole.IFontDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(-514)]
	public virtual extern bool Enabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-514)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-514)]
		[param: In]
		set;
	}

	[DispId(-520)]
	public virtual extern AppearanceSettings Appearance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-520)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-520)]
		[param: In]
		set;
	}

	[DispId(82)]
	public virtual extern OutlineBarSettings OutlineBar
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(82)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(82)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(83)]
	public virtual extern uint TreeColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(83)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(83)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(84)]
	public virtual extern short GridLineWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(84)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(84)]
		[param: In]
		set;
	}

	[DispId(85)]
	public virtual extern bool AutoResize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(85)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(85)]
		[param: In]
		set;
	}

	[DispId(86)]
	public virtual extern int BottomRow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(86)]
		get;
	}

	[DispId(87)]
	public virtual extern int RightCol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(87)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(88)]
	public virtual extern bool ExtendLastCol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(88)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(88)]
		[param: In]
		set;
	}

	[DispId(89)]
	public virtual extern int ClientWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(89)]
		get;
	}

	[DispId(90)]
	public virtual extern int ClientHeight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(90)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(91)]
	public virtual extern string EditText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(91)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(91)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(-515)]
	public virtual extern int hWnd
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(-515)]
		get;
	}

	[DispId(93)]
	public virtual extern AutoSizeSettings AutoSizeMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(93)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(93)]
		[param: In]
		set;
	}

	[DispId(94)]
	public virtual extern bool RightToLeft
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(94)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(94)]
		[param: In]
		set;
	}

	[DispId(95)]
	public virtual extern bool MultiTotals
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(95)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(95)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(96)]
	public virtual extern uint BackColorAlternate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(96)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(96)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(97)]
	public virtual extern OwnerDrawSettings OwnerDraw
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(97)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(97)]
		[param: In]
		set;
	}

	[DispId(98)]
	public virtual extern DataModeSettings DataMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(98)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(98)]
		[param: In]
		set;
	}

	[DispId(99)]
	public virtual extern OLEDragModeSettings OLEDragMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(99)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(99)]
		[param: In]
		set;
	}

	[DispId(100)]
	public virtual extern OLEDropModeSettings OLEDropMode
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
	public virtual extern TabBehaviorSettings TabBehavior
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(102)]
	public virtual extern uint SheetBorder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(103)]
	public virtual extern bool AllowSelection
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
	public virtual extern bool PicturesOver
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		[param: In]
		set;
	}

	[DispId(105)]
	public virtual extern CellCheckedSettings CellChecked
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(105)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(105)]
		[param: In]
		set;
	}

	[DispId(106)]
	public virtual extern MergeCompareSettings MergeCompare
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(106)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(106)]
		[param: In]
		set;
	}

	[DispId(107)]
	public virtual extern EllipsisSettings Ellipsis
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
	public virtual extern int OutlineCol
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
	public virtual extern int RowHeightMax
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[param: In]
		set;
	}

	[DispId(110)]
	public virtual extern AutoSearchSettings AutoSearch
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(110)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(110)]
		[param: In]
		set;
	}

	[DispId(111)]
	public virtual extern ExplorerBarSettings ExplorerBar
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(111)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(111)]
		[param: In]
		set;
	}

	[DispId(112)]
	public virtual extern string EditMask
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(112)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(112)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(113)]
	public virtual extern int EditSelStart
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(113)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(113)]
		[param: In]
		set;
	}

	[DispId(114)]
	public virtual extern int EditSelLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(114)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(114)]
		[param: In]
		set;
	}

	[DispId(115)]
	public virtual extern string EditSelText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(115)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(115)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(116)]
	public virtual extern int EditMaxLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(116)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(116)]
		[param: In]
		set;
	}

	[DispId(117)]
	public virtual extern int ComboIndex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(117)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(117)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(118)]
	public virtual extern int ComboCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(118)]
		get;
	}

	[DispId(119)]
	public virtual extern AlignmentSettings ColAlignment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(119)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(119)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(120)]
	public virtual extern int ColWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(120)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(120)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(121)]
	public virtual extern int RowHeight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(121)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(121)]
		[param: In]
		set;
	}

	[DispId(122)]
	public virtual extern bool MergeRow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(122)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(122)]
		[param: In]
		set;
	}

	[DispId(123)]
	public virtual extern bool MergeCol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(123)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(123)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(124)]
	public virtual extern int RowPosition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(124)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(125)]
	public virtual extern int ColPosition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(125)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(126)]
	public virtual extern object RowData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(126)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(126)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(127)]
	public virtual extern object ColData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(127)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(127)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(130)]
	public virtual extern string TextMatrix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(130)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(130)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(133)]
	public virtual extern double ValueMatrix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(133)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(134)]
	public virtual extern bool IsSubtotal
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(134)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(134)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(138)]
	public virtual extern AlignmentSettings FixedAlignment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(138)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(138)]
		[param: In]
		set;
	}

	[DispId(139)]
	public virtual extern bool RowIsVisible
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(139)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(140)]
	public virtual extern bool ColIsVisible
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(140)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(141)]
	public virtual extern int RowPos
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(141)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(142)]
	public virtual extern int ColPos
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(142)]
		get;
	}

	[DispId(143)]
	public virtual extern bool IsSelected
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(143)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(143)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(144)]
	public virtual extern string TextArray
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(144)]
		[TypeLibFunc(64)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(144)]
		[TypeLibFunc(64)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(145)]
	public virtual extern CollapsedSettings IsCollapsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(145)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(145)]
		[param: In]
		set;
	}

	[DispId(154)]
	public virtual extern object ArchiveInfo
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(154)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(155)]
	public virtual extern SortSettings ColSort
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(155)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(155)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(156)]
	public virtual extern string ColFormat
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(156)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(156)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(157)]
	public virtual extern DataTypeSettings ColDataType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(157)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(157)]
		[param: In]
		set;
	}

	[DispId(158)]
	public virtual extern object Cell
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(158)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(158)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(159)]
	public virtual extern RowStatusSettings RowStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(159)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(159)]
		[param: In]
		set;
	}

	[DispId(160)]
	public virtual extern int FindRow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(160)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(161)]
	public virtual extern string ComboItem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(161)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(162)]
	public virtual extern string ComboData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(162)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(164)]
	public virtual extern string ColEditMask
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(164)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(164)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(165)]
	public virtual extern string ColComboList
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(165)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(165)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(166)]
	public virtual extern short RowOutlineLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(166)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(166)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(167)]
	public virtual extern int SelectedRows
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(167)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(168)]
	public virtual extern int SelectedRow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(168)]
		get;
	}

	[DispId(169)]
	public virtual extern bool ScrollTips
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(169)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(169)]
		[param: In]
		set;
	}

	[DispId(170)]
	public virtual extern string ScrollTipText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(170)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(170)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(171)]
	public virtual extern bool RowHidden
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(171)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(171)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(172)]
	public virtual extern bool ColHidden
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(172)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(172)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(173)]
	public virtual extern int ColWidthMin
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(173)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(173)]
		[param: In]
		set;
	}

	[DispId(174)]
	public virtual extern int ColWidthMax
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(174)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(174)]
		[param: In]
		set;
	}

	[DispId(176)]
	public virtual extern ShowButtonSettings ShowComboButton
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(176)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(176)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(177)]
	public virtual extern IPictureDisp CellButtonPicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(177)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(177)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(178)]
	public virtual extern ComboSearchSettings ComboSearch
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(178)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(178)]
		[param: In]
		set;
	}

	[DispId(180)]
	public virtual extern bool AutoSizeMouse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(180)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(180)]
		[param: In]
		set;
	}

	[DispId(182)]
	public virtual extern string ClipSeparators
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(182)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(182)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(184)]
	public virtual extern int ColImageList
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(184)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(184)]
		[param: In]
		set;
	}

	[DispId(185)]
	public virtual extern string ColKey
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(185)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(185)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(186)]
	public virtual extern int ColIndex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(186)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(188)]
	public virtual extern int FrozenRows
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(188)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(188)]
		[param: In]
		set;
	}

	[DispId(189)]
	public virtual extern int FrozenCols
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(189)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(189)]
		[param: In]
		set;
	}

	[DispId(190)]
	public virtual extern AllowUserFreezeSettings AllowUserFreezing
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(190)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(190)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(191)]
	public virtual extern uint BackColorFrozen
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(191)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(191)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(192)]
	public virtual extern uint ForeColorFrozen
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(192)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(192)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(193)]
	public virtual extern IVSFlexDataSource FlexDataSource
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(193)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(193)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(196)]
	public virtual extern IPictureDisp NodeOpenPicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(196)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(196)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(197)]
	[ComAliasName("stdole.IPictureDisp")]
	public virtual extern IPictureDisp NodeClosedPicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(197)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(197)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(199)]
	public virtual extern float AutoSearchDelay
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(199)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(199)]
		[param: In]
		set;
	}

	[DispId(200)]
	public virtual extern int EditWindow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(200)]
		get;
	}

	[DispId(201)]
	[ComAliasName("stdole.IPictureDisp")]
	public virtual extern IPictureDisp WallPaper
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(201)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(202)]
	public virtual extern PictureAlignmentSettings WallPaperAlignment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(202)]
		[param: In]
		set;
	}

	[DispId(203)]
	public virtual extern double Aggregate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(203)]
		get;
	}

	[DispId(206)]
	public virtual extern object Bookmark
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(206)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(207)]
	public virtual extern int ColIndent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(207)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(207)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(212)]
	public virtual extern string AccessibleName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(212)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(212)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(213)]
	public virtual extern string AccessibleDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(213)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(213)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(214)]
	public virtual extern string AccessibleValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(214)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(214)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(215)]
	public virtual extern object AccessibleRole
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(215)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(215)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(216)]
	public virtual extern bool IsSearching
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(216)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(217)]
	public virtual extern ControlFlagsSettings Flags
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(217)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(217)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(218)]
	public virtual extern MergeSettings MergeCellsFixed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(218)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(218)]
		[param: In]
		set;
	}

	[DispId(219)]
	public virtual extern MergeCompareSettings GroupCompare
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(219)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(219)]
		[param: In]
		set;
	}

	[DispId(220)]
	[ComAliasName("stdole.IPictureDisp")]
	public virtual extern IPictureDisp SortAscendingPicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(220)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(220)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(221)]
	public virtual extern IPictureDisp SortDescendingPicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(221)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(221)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(222)]
	public virtual extern int FindRowRegex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(222)]
		get;
	}

	public virtual extern event _IVSFlexGridEvents_ClickEventHandler Click;

	public virtual extern event _IVSFlexGridEvents_DblClickEventHandler DblClick;

	public virtual extern event _IVSFlexGridEvents_KeyDownEventHandler KeyDown;

	public virtual extern event _IVSFlexGridEvents_KeyPressEventHandler KeyPress;

	public virtual extern event _IVSFlexGridEvents_KeyUpEventHandler KeyUp;

	public virtual extern event _IVSFlexGridEvents_MouseDownEventHandler MouseDown;

	public virtual extern event _IVSFlexGridEvents_MouseMoveEventHandler MouseMove;

	public virtual extern event _IVSFlexGridEvents_MouseUpEventHandler MouseUp;

	public virtual extern event _IVSFlexGridEvents_SelChangeEventHandler SelChange;

	public virtual extern event _IVSFlexGridEvents_RowColChangeEventHandler RowColChange;

	public virtual extern event _IVSFlexGridEvents_EnterCellEventHandler EnterCell;

	public virtual extern event _IVSFlexGridEvents_LeaveCellEventHandler LeaveCell;

	public virtual extern event _IVSFlexGridEvents_BeforeMouseDownEventHandler BeforeMouseDown;

	public virtual extern event _IVSFlexGridEvents_BeforeRowColChangeEventHandler BeforeRowColChange;

	public virtual extern event _IVSFlexGridEvents_AfterRowColChangeEventHandler AfterRowColChange;

	public virtual extern event _IVSFlexGridEvents_BeforeSelChangeEventHandler BeforeSelChange;

	public virtual extern event _IVSFlexGridEvents_AfterSelChangeEventHandler AfterSelChange;

	public virtual extern event _IVSFlexGridEvents_BeforeScrollEventHandler BeforeScroll;

	public virtual extern event _IVSFlexGridEvents_AfterScrollEventHandler AfterScroll;

	public virtual extern event _IVSFlexGridEvents_CompareEventHandler Compare;

	public virtual extern event _IVSFlexGridEvents_BeforeSortEventHandler BeforeSort;

	public virtual extern event _IVSFlexGridEvents_AfterSortEventHandler AfterSort;

	public virtual extern event _IVSFlexGridEvents_BeforeMoveColumnEventHandler BeforeMoveColumn;

	public virtual extern event _IVSFlexGridEvents_AfterMoveColumnEventHandler AfterMoveColumn;

	public virtual extern event _IVSFlexGridEvents_BeforeUserResizeEventHandler BeforeUserResize;

	public virtual extern event _IVSFlexGridEvents_AfterUserResizeEventHandler AfterUserResize;

	public virtual extern event _IVSFlexGridEvents_BeforeCollapseEventHandler BeforeCollapse;

	public virtual extern event _IVSFlexGridEvents_AfterCollapseEventHandler AfterCollapse;

	public virtual extern event _IVSFlexGridEvents_BeforeEditEventHandler BeforeEdit;

	public virtual extern event _IVSFlexGridEvents_StartEditEventHandler StartEdit;

	public virtual extern event _IVSFlexGridEvents_ValidateEditEventHandler ValidateEdit;

	public virtual extern event _IVSFlexGridEvents_AfterEditEventHandler AfterEdit;

	public virtual extern event _IVSFlexGridEvents_KeyPressEditEventHandler KeyPressEdit;

	public virtual extern event _IVSFlexGridEvents_KeyDownEditEventHandler KeyDownEdit;

	public virtual extern event _IVSFlexGridEvents_KeyUpEditEventHandler KeyUpEdit;

	public virtual extern event _IVSFlexGridEvents_ChangeEditEventHandler ChangeEdit;

	public virtual extern event _IVSFlexGridEvents_BeforePageBreakEventHandler BeforePageBreak;

	public virtual extern event _IVSFlexGridEvents_GetHeaderRowEventHandler GetHeaderRow;

	public virtual extern event _IVSFlexGridEvents_StartPageEventHandler StartPage;

	public virtual extern event _IVSFlexGridEvents_DrawCellEventHandler DrawCell;

	public virtual extern event _IVSFlexGridEvents_ErrorEventHandler Error;

	public virtual extern event _IVSFlexGridEvents_CellButtonClickEventHandler CellButtonClick;

	public virtual extern event _IVSFlexGridEvents_BeforeScrollTipEventHandler BeforeScrollTip;

	public virtual extern event _IVSFlexGridEvents_AfterUserFreezeEventHandler AfterUserFreeze;

	public virtual extern event _IVSFlexGridEvents_OLEStartDragEventHandler OLEStartDrag;

	public virtual extern event _IVSFlexGridEvents_OLEGiveFeedbackEventHandler OLEGiveFeedback;

	public virtual extern event _IVSFlexGridEvents_OLESetDataEventHandler OLESetData;

	public virtual extern event _IVSFlexGridEvents_OLECompleteDragEventHandler OLECompleteDrag;

	public virtual extern event _IVSFlexGridEvents_OLEDragOverEventHandler OLEDragOver;

	public virtual extern event _IVSFlexGridEvents_OLEDragDropEventHandler OLEDragDrop;

	public virtual extern event _IVSFlexGridEvents_OLESetCustomDataObjectEventHandler OLESetCustomDataObject;

	public virtual extern event _IVSFlexGridEvents_CellChangedEventHandler CellChanged;

	public virtual extern event _IVSFlexGridEvents_BeforeMoveRowEventHandler BeforeMoveRow;

	public virtual extern event _IVSFlexGridEvents_AfterMoveRowEventHandler AfterMoveRow;

	public virtual extern event _IVSFlexGridEvents_SetupEditWindowEventHandler SetupEditWindow;

	public virtual extern event _IVSFlexGridEvents_SetupEditStyleEventHandler SetupEditStyle;

	public virtual extern event _IVSFlexGridEvents_ComboDropDownEventHandler ComboDropDown;

	public virtual extern event _IVSFlexGridEvents_ComboCloseUpEventHandler ComboCloseUp;

	public virtual extern event _IVSFlexGridEvents_StartAutoSearchEventHandler StartAutoSearch;

	public virtual extern event _IVSFlexGridEvents_EndAutoSearchEventHandler EndAutoSearch;

	public virtual extern event _IVSFlexGridEvents_FilterDataEventHandler FilterData;

	public virtual extern event _IVSFlexGridEvents_BeforeDataRefreshEventHandler BeforeDataRefresh;

	public virtual extern event _IVSFlexGridEvents_AfterDataRefreshEventHandler AfterDataRefresh;

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-552)]
	[TypeLibFunc(64)]
	public virtual extern void About();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(49)]
	[TypeLibFunc(1024)]
	public virtual extern void let_CellPicture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(-522)]
	public virtual extern void let_MouseIcon([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(-512)]
	public virtual extern void let_Font([In][ComAliasName("stdole.IFontDisp")][MarshalAs(UnmanagedType.Interface)] IFontDisp pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(128)]
	public virtual extern void AddItem([MarshalAs(UnmanagedType.BStr)] string Item, [Optional][MarshalAs(UnmanagedType.Struct)] object Row);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(129)]
	public virtual extern void RemoveItem([Optional][MarshalAs(UnmanagedType.Struct)] object Row);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(131)]
	public virtual extern void Clear([Optional][MarshalAs(UnmanagedType.Struct)] object Where, [Optional][MarshalAs(UnmanagedType.Struct)] object What);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(132)]
	public virtual extern void EditCell();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(135)]
	public virtual extern void Subtotal(SubtotalSettings Function, [Optional][MarshalAs(UnmanagedType.Struct)] object GroupOn, [Optional][MarshalAs(UnmanagedType.Struct)] object TotalOn, [Optional][MarshalAs(UnmanagedType.Struct)] object Format, [Optional][MarshalAs(UnmanagedType.Struct)] object BackColor, [Optional][MarshalAs(UnmanagedType.Struct)] object ForeColor, [Optional][MarshalAs(UnmanagedType.Struct)] object FontBold, [Optional][MarshalAs(UnmanagedType.Struct)] object Caption, [Optional][MarshalAs(UnmanagedType.Struct)] object MatchFrom, [Optional][MarshalAs(UnmanagedType.Struct)] object TotalOnly);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-550)]
	public virtual extern void Refresh();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(137)]
	public virtual extern void Outline(short Level);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(146)]
	public virtual extern void Select(int Row, int Col, [Optional][MarshalAs(UnmanagedType.Struct)] object RowSel, [Optional][MarshalAs(UnmanagedType.Struct)] object ColSel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(147)]
	public virtual extern void AutoSize(int Col1, [Optional][MarshalAs(UnmanagedType.Struct)] object Col2, [Optional][MarshalAs(UnmanagedType.Struct)] object Equal, [Optional][MarshalAs(UnmanagedType.Struct)] object ExtraSpace);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(148)]
	public virtual extern void DataRefresh();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(149)]
	public virtual extern void CellBorder([ComAliasName("stdole.OLE_COLOR")] uint Color, short Left, short Top, short Right, short Bottom, short Vertical, short Horizontal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(150)]
	public virtual extern void OLEDrag();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(151)]
	public virtual extern void SaveGrid([MarshalAs(UnmanagedType.BStr)] string FileName, SaveLoadSettings SaveWhat, [Optional][MarshalAs(UnmanagedType.Struct)] object Options);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(152)]
	public virtual extern void LoadGrid([MarshalAs(UnmanagedType.BStr)] string FileName, SaveLoadSettings LoadWhat, [Optional][MarshalAs(UnmanagedType.Struct)] object Options);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(153)]
	public virtual extern void Archive([MarshalAs(UnmanagedType.BStr)] string ArcFileName, [MarshalAs(UnmanagedType.BStr)] string FileName, ArchiveSettings Action);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(158)]
	[TypeLibFunc(1024)]
	public virtual extern void let_Cell(CellPropertySettings Setting, [Optional][MarshalAs(UnmanagedType.Struct)] object Row1, [Optional][MarshalAs(UnmanagedType.Struct)] object Col1, [Optional][MarshalAs(UnmanagedType.Struct)] object Row2, [Optional][MarshalAs(UnmanagedType.Struct)] object Col2, [In][MarshalAs(UnmanagedType.Struct)] object pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(163)]
	public virtual extern void BindToArray([Optional][MarshalAs(UnmanagedType.Struct)] object VariantArray, [Optional][MarshalAs(UnmanagedType.Struct)] object RowDim, [Optional][MarshalAs(UnmanagedType.Struct)] object ColDim, [Optional][MarshalAs(UnmanagedType.Struct)] object PageDim, [Optional][MarshalAs(UnmanagedType.Struct)] object CurrentPage);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(175)]
	public virtual extern void GetMergedRange(int Row, int Col, ref int R1, ref int C1, ref int R2, ref int C2);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(177)]
	public virtual extern void let_CellButtonPicture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(179)]
	public virtual extern void LoadArray([Optional][MarshalAs(UnmanagedType.Struct)] object VariantArray, [Optional][MarshalAs(UnmanagedType.Struct)] object RowDim, [Optional][MarshalAs(UnmanagedType.Struct)] object ColDim, [Optional][MarshalAs(UnmanagedType.Struct)] object PageDim, [Optional][MarshalAs(UnmanagedType.Struct)] object CurrentPage);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(181)]
	public virtual extern void GetSelection(ref int Row1, ref int Col1, ref int Row2, ref int Col2);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(183)]
	public virtual extern void PrintGrid([Optional][In][MarshalAs(UnmanagedType.Struct)] object DocName, [Optional][In][MarshalAs(UnmanagedType.Struct)] object ShowDialog, [Optional][In][MarshalAs(UnmanagedType.Struct)] object Orientation, [Optional][In][MarshalAs(UnmanagedType.Struct)] object MarginLR, [Optional][In][MarshalAs(UnmanagedType.Struct)] object MarginTB);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(194)]
	public virtual extern int GetNodeRow([In] int Row, [In] NodeTypeSettings Which);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(195)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string BuildComboList([MarshalAs(UnmanagedType.IDispatch)] object rs, [MarshalAs(UnmanagedType.BStr)] string FieldList, [Optional][MarshalAs(UnmanagedType.Struct)] object KeyField, [Optional][MarshalAs(UnmanagedType.Struct)] object BackColor);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(196)]
	public virtual extern void let_NodeOpenPicture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(197)]
	public virtual extern void let_NodeClosedPicture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(198)]
	public virtual extern void ShowCell(int Row, int Col);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(201)]
	public virtual extern void let_WallPaper([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(204)]
	public virtual extern int DragRow(int Row);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(205)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern VSFlexNode GetNode([Optional][MarshalAs(UnmanagedType.Struct)] object Row);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(210)]
	public virtual extern void LoadGridURL([MarshalAs(UnmanagedType.BStr)] string URL, SaveLoadSettings LoadWhat, [Optional][MarshalAs(UnmanagedType.Struct)] object Options);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(211)]
	public virtual extern void FinishEditing([In] bool Cancel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(220)]
	[TypeLibFunc(1024)]
	public virtual extern void let_SortAscendingPicture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(221)]
	[TypeLibFunc(1024)]
	public virtual extern void let_SortDescendingPicture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(223)]
	public virtual extern void CellBorderRange(int Row1, int Col1, int Row2, int Col2, [ComAliasName("stdole.OLE_COLOR")] uint Color, short Left, short Top, short Right, short Bottom, short Vertical, short Horizontal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(224)]
	public virtual extern void Cut();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(225)]
	public virtual extern void Copy();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(226)]
	public virtual extern void Paste();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(227)]
	public virtual extern void Delete();
}
[ComVisible(false)]
[ComEventInterface(typeof(_IVSFlexGridEvents\u0000), typeof(_IVSFlexGridEvents_EventProvider\u0000))]
[TypeLibType(16)]
public interface _IVSFlexGridEvents_Event
{
	event _IVSFlexGridEvents_ClickEventHandler Click;

	event _IVSFlexGridEvents_DblClickEventHandler DblClick;

	event _IVSFlexGridEvents_KeyDownEventHandler KeyDown;

	event _IVSFlexGridEvents_KeyPressEventHandler KeyPress;

	event _IVSFlexGridEvents_KeyUpEventHandler KeyUp;

	event _IVSFlexGridEvents_MouseDownEventHandler MouseDown;

	event _IVSFlexGridEvents_MouseMoveEventHandler MouseMove;

	event _IVSFlexGridEvents_MouseUpEventHandler MouseUp;

	event _IVSFlexGridEvents_SelChangeEventHandler SelChange;

	event _IVSFlexGridEvents_RowColChangeEventHandler RowColChange;

	event _IVSFlexGridEvents_EnterCellEventHandler EnterCell;

	event _IVSFlexGridEvents_LeaveCellEventHandler LeaveCell;

	event _IVSFlexGridEvents_BeforeMouseDownEventHandler BeforeMouseDown;

	event _IVSFlexGridEvents_BeforeRowColChangeEventHandler BeforeRowColChange;

	event _IVSFlexGridEvents_AfterRowColChangeEventHandler AfterRowColChange;

	event _IVSFlexGridEvents_BeforeSelChangeEventHandler BeforeSelChange;

	event _IVSFlexGridEvents_AfterSelChangeEventHandler AfterSelChange;

	event _IVSFlexGridEvents_BeforeScrollEventHandler BeforeScroll;

	event _IVSFlexGridEvents_AfterScrollEventHandler AfterScroll;

	event _IVSFlexGridEvents_CompareEventHandler Compare;

	event _IVSFlexGridEvents_BeforeSortEventHandler BeforeSort;

	event _IVSFlexGridEvents_AfterSortEventHandler AfterSort;

	event _IVSFlexGridEvents_BeforeMoveColumnEventHandler BeforeMoveColumn;

	event _IVSFlexGridEvents_AfterMoveColumnEventHandler AfterMoveColumn;

	event _IVSFlexGridEvents_BeforeUserResizeEventHandler BeforeUserResize;

	event _IVSFlexGridEvents_AfterUserResizeEventHandler AfterUserResize;

	event _IVSFlexGridEvents_BeforeCollapseEventHandler BeforeCollapse;

	event _IVSFlexGridEvents_AfterCollapseEventHandler AfterCollapse;

	event _IVSFlexGridEvents_BeforeEditEventHandler BeforeEdit;

	event _IVSFlexGridEvents_StartEditEventHandler StartEdit;

	event _IVSFlexGridEvents_ValidateEditEventHandler ValidateEdit;

	event _IVSFlexGridEvents_AfterEditEventHandler AfterEdit;

	event _IVSFlexGridEvents_KeyPressEditEventHandler KeyPressEdit;

	event _IVSFlexGridEvents_KeyDownEditEventHandler KeyDownEdit;

	event _IVSFlexGridEvents_KeyUpEditEventHandler KeyUpEdit;

	event _IVSFlexGridEvents_ChangeEditEventHandler ChangeEdit;

	event _IVSFlexGridEvents_BeforePageBreakEventHandler BeforePageBreak;

	event _IVSFlexGridEvents_GetHeaderRowEventHandler GetHeaderRow;

	event _IVSFlexGridEvents_StartPageEventHandler StartPage;

	event _IVSFlexGridEvents_DrawCellEventHandler DrawCell;

	event _IVSFlexGridEvents_ErrorEventHandler Error;

	event _IVSFlexGridEvents_CellButtonClickEventHandler CellButtonClick;

	event _IVSFlexGridEvents_BeforeScrollTipEventHandler BeforeScrollTip;

	event _IVSFlexGridEvents_AfterUserFreezeEventHandler AfterUserFreeze;

	event _IVSFlexGridEvents_OLEStartDragEventHandler OLEStartDrag;

	event _IVSFlexGridEvents_OLEGiveFeedbackEventHandler OLEGiveFeedback;

	event _IVSFlexGridEvents_OLESetDataEventHandler OLESetData;

	event _IVSFlexGridEvents_OLECompleteDragEventHandler OLECompleteDrag;

	event _IVSFlexGridEvents_OLEDragOverEventHandler OLEDragOver;

	event _IVSFlexGridEvents_OLEDragDropEventHandler OLEDragDrop;

	event _IVSFlexGridEvents_OLESetCustomDataObjectEventHandler OLESetCustomDataObject;

	event _IVSFlexGridEvents_CellChangedEventHandler CellChanged;

	event _IVSFlexGridEvents_BeforeMoveRowEventHandler BeforeMoveRow;

	event _IVSFlexGridEvents_AfterMoveRowEventHandler AfterMoveRow;

	event _IVSFlexGridEvents_SetupEditWindowEventHandler SetupEditWindow;

	event _IVSFlexGridEvents_SetupEditStyleEventHandler SetupEditStyle;

	event _IVSFlexGridEvents_ComboDropDownEventHandler ComboDropDown;

	event _IVSFlexGridEvents_ComboCloseUpEventHandler ComboCloseUp;

	event _IVSFlexGridEvents_StartAutoSearchEventHandler StartAutoSearch;

	event _IVSFlexGridEvents_EndAutoSearchEventHandler EndAutoSearch;

	event _IVSFlexGridEvents_FilterDataEventHandler FilterData;

	event _IVSFlexGridEvents_BeforeDataRefreshEventHandler BeforeDataRefresh;

	event _IVSFlexGridEvents_AfterDataRefreshEventHandler AfterDataRefresh;
}
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_ClickEventHandler();
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_DblClickEventHandler();
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_KeyDownEventHandler([In][Out] ref short KeyCode, short Shift);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_KeyPressEventHandler([In][Out] ref short KeyAscii);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_KeyUpEventHandler([In][Out] ref short KeyCode, short Shift);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_MouseDownEventHandler(short Button, short Shift, float X, float Y);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_MouseMoveEventHandler(short Button, short Shift, float X, float Y);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_MouseUpEventHandler(short Button, short Shift, float X, float Y);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_SelChangeEventHandler();
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_RowColChangeEventHandler();
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_EnterCellEventHandler();
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_LeaveCellEventHandler();
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_BeforeMouseDownEventHandler(short Button, short Shift, float X, float Y, [In][Out] ref bool Cancel);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_BeforeRowColChangeEventHandler(int OldRow, int OldCol, int NewRow, int NewCol, [In][Out] ref bool Cancel);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_AfterRowColChangeEventHandler(int OldRow, int OldCol, int NewRow, int NewCol);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_BeforeSelChangeEventHandler(int OldRowSel, int OldColSel, int NewRowSel, int NewColSel, [In][Out] ref bool Cancel);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_AfterSelChangeEventHandler(int OldRowSel, int OldColSel, int NewRowSel, int NewColSel);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_BeforeScrollEventHandler(int OldTopRow, int OldLeftCol, int NewTopRow, int NewLeftCol, [In][Out] ref bool Cancel);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_AfterScrollEventHandler(int OldTopRow, int OldLeftCol, int NewTopRow, int NewLeftCol);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_CompareEventHandler(int Row1, int Row2, [In][Out] ref short Cmp);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_BeforeSortEventHandler(int Col, [In][Out] ref short Order);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_AfterSortEventHandler(int Col, [In][Out] ref short Order);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_BeforeMoveColumnEventHandler(int Col, [In][Out] ref int Position);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_AfterMoveColumnEventHandler(int Col, [In][Out] ref int Position);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_BeforeUserResizeEventHandler(int Row, int Col, [In][Out] ref bool Cancel);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_AfterUserResizeEventHandler(int Row, int Col);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_BeforeCollapseEventHandler(int Row, short State, [In][Out] ref bool Cancel);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_AfterCollapseEventHandler(int Row, short State);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_BeforeEditEventHandler(int Row, int Col, [In][Out] ref bool Cancel);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_StartEditEventHandler(int Row, int Col, [In][Out] ref bool Cancel);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_ValidateEditEventHandler(int Row, int Col, [In][Out] ref bool Cancel);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_AfterEditEventHandler(int Row, int Col);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_KeyPressEditEventHandler(int Row, int Col, [In][Out] ref short KeyAscii);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_KeyDownEditEventHandler(int Row, int Col, [In][Out] ref short KeyCode, short Shift);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_KeyUpEditEventHandler(int Row, int Col, [In][Out] ref short KeyCode, short Shift);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_ChangeEditEventHandler();
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_BeforePageBreakEventHandler(int Row, [In][Out] ref bool BreakOK);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_GetHeaderRowEventHandler(int Row, [In][Out] ref int HeaderRow);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_StartPageEventHandler(int hDC, int Page, [In][Out] ref bool Cancel);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_DrawCellEventHandler(int hDC, int Row, int Col, int Left, int Top, int Right, int Bottom, [In][Out] ref bool Done);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_ErrorEventHandler(int ErrorCode, [In][Out] ref bool ShowMsgBox);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_CellButtonClickEventHandler(int Row, int Col);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_BeforeScrollTipEventHandler(int Row);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_AfterUserFreezeEventHandler();
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_OLEStartDragEventHandler([MarshalAs(UnmanagedType.Interface)] ref VSDataObject Data, [In][Out] ref int AllowedEffects);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_OLEGiveFeedbackEventHandler(ref int Effect, [In][Out] ref bool DefaultCursors);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_OLESetDataEventHandler([MarshalAs(UnmanagedType.Interface)] ref VSDataObject Data, [In][Out] ref short DataFormat);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_OLECompleteDragEventHandler([In][Out] ref int Effect);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_OLEDragOverEventHandler([MarshalAs(UnmanagedType.Interface)] ref VSDataObject Data, [In][Out] ref int Effect, short Button, short Shift, float X, float Y, [In][Out] ref short State);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_OLEDragDropEventHandler([MarshalAs(UnmanagedType.Interface)] ref VSDataObject Data, [In][Out] ref int Effect, short Button, short Shift, float X, float Y);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_OLESetCustomDataObjectEventHandler([In][Out][MarshalAs(UnmanagedType.Struct)] ref object CustomDataObject);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_CellChangedEventHandler(int Row, int Col);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_BeforeMoveRowEventHandler(int Row, [In][Out] ref int Position);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_AfterMoveRowEventHandler(int Row, [In][Out] ref int Position);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_SetupEditWindowEventHandler(int Row, int Col, int EditWindow, bool IsCombo);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_SetupEditStyleEventHandler(int Row, int Col, bool IsCombo, ref int Style, ref int StyleEx);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_ComboDropDownEventHandler(int Row, int Col);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_ComboCloseUpEventHandler(int Row, int Col, ref bool FinishEdit);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_StartAutoSearchEventHandler();
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_EndAutoSearchEventHandler();
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_FilterDataEventHandler(int Row, int Col, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string Value, bool SavingToDB, [In][Out] ref bool WantThisCol);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSFlexGridEvents_BeforeDataRefreshEventHandler([In][Out] ref bool Cancel);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSFlexGridEvents_AfterDataRefreshEventHandler();
[ComImport]
[CoClass(typeof(VSFlexGridClass))]
[Guid("8951B2CE-ED39-4CF9-AA53-EFE34AE4A24E")]
public interface VSFlexGrid : IVSFlexGrid, _IVSFlexGridEvents_Event
{
}
[ComImport]
[Guid("C7D3E11D-1D28-4E68-ABC4-42199427CC6B")]
[ClassInterface(0)]
[DefaultMember("Text")]
[TypeLibType(2)]
public class VSFlexNodeClass : IVSFlexNode, VSFlexNode
{
	[DispId(0)]
	public virtual extern string Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1)]
	public virtual extern string Key
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

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(2)]
	public virtual extern IPictureDisp Image
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(3)]
	public virtual extern bool Expanded
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
	public virtual extern short Level
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		get;
	}

	[DispId(5)]
	public virtual extern int Children
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		get;
	}

	[DispId(6)]
	public virtual extern int Row
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(2)]
	public virtual extern void let_Image([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	public virtual extern bool Move(NodeMoveSettings MoveTo, [Optional][MarshalAs(UnmanagedType.Struct)] object TargetNode);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	public virtual extern void Sort(SortSettings How);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	public virtual extern void EnsureVisible();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	public virtual extern void Select();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern VSFlexNode GetNode(NodeTypeSettings Which);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern VSFlexNode AddNode(NodeTypeSettings AddWhere, [MarshalAs(UnmanagedType.BStr)] string Item, [Optional][MarshalAs(UnmanagedType.Struct)] object Key, [Optional][MarshalAs(UnmanagedType.Struct)] object Image);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	public virtual extern void RemoveNode();
}
[ComImport]
[Guid("666C0896-C89F-4A8D-A92A-6BA9CD3C7623")]
[CoClass(typeof(VSFlexNodeClass))]
public interface VSFlexNode : IVSFlexNode
{
}
[ClassInterface(ClassInterfaceType.None)]
[TypeLibType(TypeLibTypeFlags.FHidden)]
public sealed class _IVSFlexGridEvents_SinkHelper : _IVSFlexGridEvents
{
	public _IVSFlexGridEvents_ComboDropDownEventHandler m_ComboDropDownDelegate;

	public _IVSFlexGridEvents_ComboCloseUpEventHandler m_ComboCloseUpDelegate;

	public _IVSFlexGridEvents_StartAutoSearchEventHandler m_StartAutoSearchDelegate;

	public _IVSFlexGridEvents_EndAutoSearchEventHandler m_EndAutoSearchDelegate;

	public _IVSFlexGridEvents_FilterDataEventHandler m_FilterDataDelegate;

	public _IVSFlexGridEvents_BeforeDataRefreshEventHandler m_BeforeDataRefreshDelegate;

	public _IVSFlexGridEvents_AfterDataRefreshEventHandler m_AfterDataRefreshDelegate;

	public _IVSFlexGridEvents_BeforeEditEventHandler m_BeforeEditDelegate;

	public _IVSFlexGridEvents_StartEditEventHandler m_StartEditDelegate;

	public _IVSFlexGridEvents_ValidateEditEventHandler m_ValidateEditDelegate;

	public _IVSFlexGridEvents_AfterEditEventHandler m_AfterEditDelegate;

	public _IVSFlexGridEvents_KeyPressEditEventHandler m_KeyPressEditDelegate;

	public _IVSFlexGridEvents_KeyDownEditEventHandler m_KeyDownEditDelegate;

	public _IVSFlexGridEvents_KeyUpEditEventHandler m_KeyUpEditDelegate;

	public _IVSFlexGridEvents_ChangeEditEventHandler m_ChangeEditDelegate;

	public _IVSFlexGridEvents_BeforePageBreakEventHandler m_BeforePageBreakDelegate;

	public _IVSFlexGridEvents_GetHeaderRowEventHandler m_GetHeaderRowDelegate;

	public _IVSFlexGridEvents_StartPageEventHandler m_StartPageDelegate;

	public _IVSFlexGridEvents_DrawCellEventHandler m_DrawCellDelegate;

	public _IVSFlexGridEvents_ErrorEventHandler m_ErrorDelegate;

	public _IVSFlexGridEvents_CellButtonClickEventHandler m_CellButtonClickDelegate;

	public _IVSFlexGridEvents_BeforeScrollTipEventHandler m_BeforeScrollTipDelegate;

	public _IVSFlexGridEvents_AfterUserFreezeEventHandler m_AfterUserFreezeDelegate;

	public _IVSFlexGridEvents_OLEStartDragEventHandler m_OLEStartDragDelegate;

	public _IVSFlexGridEvents_OLEGiveFeedbackEventHandler m_OLEGiveFeedbackDelegate;

	public _IVSFlexGridEvents_OLESetDataEventHandler m_OLESetDataDelegate;

	public _IVSFlexGridEvents_OLECompleteDragEventHandler m_OLECompleteDragDelegate;

	public _IVSFlexGridEvents_OLEDragOverEventHandler m_OLEDragOverDelegate;

	public _IVSFlexGridEvents_OLEDragDropEventHandler m_OLEDragDropDelegate;

	public _IVSFlexGridEvents_OLESetCustomDataObjectEventHandler m_OLESetCustomDataObjectDelegate;

	public _IVSFlexGridEvents_CellChangedEventHandler m_CellChangedDelegate;

	public _IVSFlexGridEvents_BeforeMoveRowEventHandler m_BeforeMoveRowDelegate;

	public _IVSFlexGridEvents_AfterMoveRowEventHandler m_AfterMoveRowDelegate;

	public _IVSFlexGridEvents_SetupEditWindowEventHandler m_SetupEditWindowDelegate;

	public _IVSFlexGridEvents_SetupEditStyleEventHandler m_SetupEditStyleDelegate;

	public _IVSFlexGridEvents_ClickEventHandler m_ClickDelegate;

	public _IVSFlexGridEvents_DblClickEventHandler m_DblClickDelegate;

	public _IVSFlexGridEvents_KeyDownEventHandler m_KeyDownDelegate;

	public _IVSFlexGridEvents_KeyPressEventHandler m_KeyPressDelegate;

	public _IVSFlexGridEvents_KeyUpEventHandler m_KeyUpDelegate;

	public _IVSFlexGridEvents_MouseDownEventHandler m_MouseDownDelegate;

	public _IVSFlexGridEvents_MouseMoveEventHandler m_MouseMoveDelegate;

	public _IVSFlexGridEvents_MouseUpEventHandler m_MouseUpDelegate;

	public _IVSFlexGridEvents_SelChangeEventHandler m_SelChangeDelegate;

	public _IVSFlexGridEvents_RowColChangeEventHandler m_RowColChangeDelegate;

	public _IVSFlexGridEvents_EnterCellEventHandler m_EnterCellDelegate;

	public _IVSFlexGridEvents_LeaveCellEventHandler m_LeaveCellDelegate;

	public _IVSFlexGridEvents_BeforeMouseDownEventHandler m_BeforeMouseDownDelegate;

	public _IVSFlexGridEvents_BeforeRowColChangeEventHandler m_BeforeRowColChangeDelegate;

	public _IVSFlexGridEvents_AfterRowColChangeEventHandler m_AfterRowColChangeDelegate;

	public _IVSFlexGridEvents_BeforeSelChangeEventHandler m_BeforeSelChangeDelegate;

	public _IVSFlexGridEvents_AfterSelChangeEventHandler m_AfterSelChangeDelegate;

	public _IVSFlexGridEvents_BeforeScrollEventHandler m_BeforeScrollDelegate;

	public _IVSFlexGridEvents_AfterScrollEventHandler m_AfterScrollDelegate;

	public _IVSFlexGridEvents_CompareEventHandler m_CompareDelegate;

	public _IVSFlexGridEvents_BeforeSortEventHandler m_BeforeSortDelegate;

	public _IVSFlexGridEvents_AfterSortEventHandler m_AfterSortDelegate;

	public _IVSFlexGridEvents_BeforeMoveColumnEventHandler m_BeforeMoveColumnDelegate;

	public _IVSFlexGridEvents_AfterMoveColumnEventHandler m_AfterMoveColumnDelegate;

	public _IVSFlexGridEvents_BeforeUserResizeEventHandler m_BeforeUserResizeDelegate;

	public _IVSFlexGridEvents_AfterUserResizeEventHandler m_AfterUserResizeDelegate;

	public _IVSFlexGridEvents_BeforeCollapseEventHandler m_BeforeCollapseDelegate;

	public _IVSFlexGridEvents_AfterCollapseEventHandler m_AfterCollapseDelegate;

	public int m_dwCookie;

	public void ComboDropDown(int P_0, int P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_ComboDropDownDelegate != null)
		{
			m_ComboDropDownDelegate(P_0, P_1);
		}
	}

	public void ComboCloseUp(int P_0, int P_1, ref bool P_2)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_ComboCloseUpDelegate != null)
		{
			m_ComboCloseUpDelegate(P_0, P_1, ref P_2);
		}
	}

	public void StartAutoSearch()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_StartAutoSearchDelegate != null)
		{
			m_StartAutoSearchDelegate();
		}
	}

	public void EndAutoSearch()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_EndAutoSearchDelegate != null)
		{
			m_EndAutoSearchDelegate();
		}
	}

	public void FilterData(int P_0, int P_1, ref string P_2, bool P_3, ref bool P_4)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_FilterDataDelegate != null)
		{
			m_FilterDataDelegate(P_0, P_1, ref P_2, P_3, ref P_4);
		}
	}

	public void BeforeDataRefresh(ref bool P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeDataRefreshDelegate != null)
		{
			m_BeforeDataRefreshDelegate(ref P_0);
		}
	}

	public void AfterDataRefresh()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterDataRefreshDelegate != null)
		{
			m_AfterDataRefreshDelegate();
		}
	}

	public void BeforeEdit(int P_0, int P_1, ref bool P_2)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeEditDelegate != null)
		{
			m_BeforeEditDelegate(P_0, P_1, ref P_2);
		}
	}

	public void StartEdit(int P_0, int P_1, ref bool P_2)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_StartEditDelegate != null)
		{
			m_StartEditDelegate(P_0, P_1, ref P_2);
		}
	}

	public void ValidateEdit(int P_0, int P_1, ref bool P_2)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_ValidateEditDelegate != null)
		{
			m_ValidateEditDelegate(P_0, P_1, ref P_2);
		}
	}

	public void AfterEdit(int P_0, int P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterEditDelegate != null)
		{
			m_AfterEditDelegate(P_0, P_1);
		}
	}

	public void KeyPressEdit(int P_0, int P_1, ref short P_2)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_KeyPressEditDelegate != null)
		{
			m_KeyPressEditDelegate(P_0, P_1, ref P_2);
		}
	}

	public void KeyDownEdit(int P_0, int P_1, ref short P_2, short P_3)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_KeyDownEditDelegate != null)
		{
			m_KeyDownEditDelegate(P_0, P_1, ref P_2, P_3);
		}
	}

	public void KeyUpEdit(int P_0, int P_1, ref short P_2, short P_3)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_KeyUpEditDelegate != null)
		{
			m_KeyUpEditDelegate(P_0, P_1, ref P_2, P_3);
		}
	}

	public void ChangeEdit()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_ChangeEditDelegate != null)
		{
			m_ChangeEditDelegate();
		}
	}

	public void BeforePageBreak(int P_0, ref bool P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforePageBreakDelegate != null)
		{
			m_BeforePageBreakDelegate(P_0, ref P_1);
		}
	}

	public void GetHeaderRow(int P_0, ref int P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_GetHeaderRowDelegate != null)
		{
			m_GetHeaderRowDelegate(P_0, ref P_1);
		}
	}

	public void StartPage(int P_0, int P_1, ref bool P_2)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_StartPageDelegate != null)
		{
			m_StartPageDelegate(P_0, P_1, ref P_2);
		}
	}

	public void DrawCell(int P_0, int P_1, int P_2, int P_3, int P_4, int P_5, int P_6, ref bool P_7)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_DrawCellDelegate != null)
		{
			m_DrawCellDelegate(P_0, P_1, P_2, P_3, P_4, P_5, P_6, ref P_7);
		}
	}

	public void Error(int P_0, ref bool P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_ErrorDelegate != null)
		{
			m_ErrorDelegate(P_0, ref P_1);
		}
	}

	public void CellButtonClick(int P_0, int P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_CellButtonClickDelegate != null)
		{
			m_CellButtonClickDelegate(P_0, P_1);
		}
	}

	public void BeforeScrollTip(int P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeScrollTipDelegate != null)
		{
			m_BeforeScrollTipDelegate(P_0);
		}
	}

	public void AfterUserFreeze()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterUserFreezeDelegate != null)
		{
			m_AfterUserFreezeDelegate();
		}
	}

	public void OLEStartDrag(ref VSDataObject P_0, ref int P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_OLEStartDragDelegate != null)
		{
			m_OLEStartDragDelegate(ref P_0, ref P_1);
		}
	}

	public void OLEGiveFeedback(ref int P_0, ref bool P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_OLEGiveFeedbackDelegate != null)
		{
			m_OLEGiveFeedbackDelegate(ref P_0, ref P_1);
		}
	}

	public void OLESetData(ref VSDataObject P_0, ref short P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_OLESetDataDelegate != null)
		{
			m_OLESetDataDelegate(ref P_0, ref P_1);
		}
	}

	public void OLECompleteDrag(ref int P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_OLECompleteDragDelegate != null)
		{
			m_OLECompleteDragDelegate(ref P_0);
		}
	}

	public void OLEDragOver(ref VSDataObject P_0, ref int P_1, short P_2, short P_3, float P_4, float P_5, ref short P_6)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_OLEDragOverDelegate != null)
		{
			m_OLEDragOverDelegate(ref P_0, ref P_1, P_2, P_3, P_4, P_5, ref P_6);
		}
	}

	public void OLEDragDrop(ref VSDataObject P_0, ref int P_1, short P_2, short P_3, float P_4, float P_5)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_OLEDragDropDelegate != null)
		{
			m_OLEDragDropDelegate(ref P_0, ref P_1, P_2, P_3, P_4, P_5);
		}
	}

	public void OLESetCustomDataObject(ref object P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_OLESetCustomDataObjectDelegate != null)
		{
			m_OLESetCustomDataObjectDelegate(ref P_0);
		}
	}

	public void CellChanged(int P_0, int P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_CellChangedDelegate != null)
		{
			m_CellChangedDelegate(P_0, P_1);
		}
	}

	public void BeforeMoveRow(int P_0, ref int P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeMoveRowDelegate != null)
		{
			m_BeforeMoveRowDelegate(P_0, ref P_1);
		}
	}

	public void AfterMoveRow(int P_0, ref int P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterMoveRowDelegate != null)
		{
			m_AfterMoveRowDelegate(P_0, ref P_1);
		}
	}

	public void SetupEditWindow(int P_0, int P_1, int P_2, bool P_3)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_SetupEditWindowDelegate != null)
		{
			m_SetupEditWindowDelegate(P_0, P_1, P_2, P_3);
		}
	}

	public void SetupEditStyle(int P_0, int P_1, bool P_2, ref int P_3, ref int P_4)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_SetupEditStyleDelegate != null)
		{
			m_SetupEditStyleDelegate(P_0, P_1, P_2, ref P_3, ref P_4);
		}
	}

	public void Click()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_ClickDelegate != null)
		{
			m_ClickDelegate();
		}
	}

	public void DblClick()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_DblClickDelegate != null)
		{
			m_DblClickDelegate();
		}
	}

	public void KeyDown(ref short P_0, short P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_KeyDownDelegate != null)
		{
			m_KeyDownDelegate(ref P_0, P_1);
		}
	}

	public void KeyPress(ref short P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_KeyPressDelegate != null)
		{
			m_KeyPressDelegate(ref P_0);
		}
	}

	public void KeyUp(ref short P_0, short P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_KeyUpDelegate != null)
		{
			m_KeyUpDelegate(ref P_0, P_1);
		}
	}

	public void MouseDown(short P_0, short P_1, float P_2, float P_3)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_MouseDownDelegate != null)
		{
			m_MouseDownDelegate(P_0, P_1, P_2, P_3);
		}
	}

	public void MouseMove(short P_0, short P_1, float P_2, float P_3)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_MouseMoveDelegate != null)
		{
			m_MouseMoveDelegate(P_0, P_1, P_2, P_3);
		}
	}

	public void MouseUp(short P_0, short P_1, float P_2, float P_3)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_MouseUpDelegate != null)
		{
			m_MouseUpDelegate(P_0, P_1, P_2, P_3);
		}
	}

	public void SelChange()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_SelChangeDelegate != null)
		{
			m_SelChangeDelegate();
		}
	}

	public void RowColChange()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_RowColChangeDelegate != null)
		{
			m_RowColChangeDelegate();
		}
	}

	public void EnterCell()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_EnterCellDelegate != null)
		{
			m_EnterCellDelegate();
		}
	}

	public void LeaveCell()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_LeaveCellDelegate != null)
		{
			m_LeaveCellDelegate();
		}
	}

	public void BeforeMouseDown(short P_0, short P_1, float P_2, float P_3, ref bool P_4)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeMouseDownDelegate != null)
		{
			m_BeforeMouseDownDelegate(P_0, P_1, P_2, P_3, ref P_4);
		}
	}

	public void BeforeRowColChange(int P_0, int P_1, int P_2, int P_3, ref bool P_4)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeRowColChangeDelegate != null)
		{
			m_BeforeRowColChangeDelegate(P_0, P_1, P_2, P_3, ref P_4);
		}
	}

	public void AfterRowColChange(int P_0, int P_1, int P_2, int P_3)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterRowColChangeDelegate != null)
		{
			m_AfterRowColChangeDelegate(P_0, P_1, P_2, P_3);
		}
	}

	public void BeforeSelChange(int P_0, int P_1, int P_2, int P_3, ref bool P_4)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeSelChangeDelegate != null)
		{
			m_BeforeSelChangeDelegate(P_0, P_1, P_2, P_3, ref P_4);
		}
	}

	public void AfterSelChange(int P_0, int P_1, int P_2, int P_3)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterSelChangeDelegate != null)
		{
			m_AfterSelChangeDelegate(P_0, P_1, P_2, P_3);
		}
	}

	public void BeforeScroll(int P_0, int P_1, int P_2, int P_3, ref bool P_4)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeScrollDelegate != null)
		{
			m_BeforeScrollDelegate(P_0, P_1, P_2, P_3, ref P_4);
		}
	}

	public void AfterScroll(int P_0, int P_1, int P_2, int P_3)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterScrollDelegate != null)
		{
			m_AfterScrollDelegate(P_0, P_1, P_2, P_3);
		}
	}

	public void Compare(int P_0, int P_1, ref short P_2)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_CompareDelegate != null)
		{
			m_CompareDelegate(P_0, P_1, ref P_2);
		}
	}

	public void BeforeSort(int P_0, ref short P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeSortDelegate != null)
		{
			m_BeforeSortDelegate(P_0, ref P_1);
		}
	}

	public void AfterSort(int P_0, ref short P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterSortDelegate != null)
		{
			m_AfterSortDelegate(P_0, ref P_1);
		}
	}

	public void BeforeMoveColumn(int P_0, ref int P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeMoveColumnDelegate != null)
		{
			m_BeforeMoveColumnDelegate(P_0, ref P_1);
		}
	}

	public void AfterMoveColumn(int P_0, ref int P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterMoveColumnDelegate != null)
		{
			m_AfterMoveColumnDelegate(P_0, ref P_1);
		}
	}

	public void BeforeUserResize(int P_0, int P_1, ref bool P_2)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeUserResizeDelegate != null)
		{
			m_BeforeUserResizeDelegate(P_0, P_1, ref P_2);
		}
	}

	public void AfterUserResize(int P_0, int P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterUserResizeDelegate != null)
		{
			m_AfterUserResizeDelegate(P_0, P_1);
		}
	}

	public void BeforeCollapse(int P_0, short P_1, ref bool P_2)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeCollapseDelegate != null)
		{
			m_BeforeCollapseDelegate(P_0, P_1, ref P_2);
		}
	}

	public void AfterCollapse(int P_0, short P_1)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterCollapseDelegate != null)
		{
			m_AfterCollapseDelegate(P_0, P_1);
		}
	}

	internal _IVSFlexGridEvents_SinkHelper()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_dwCookie = 0;
		m_ComboDropDownDelegate = null;
		m_ComboCloseUpDelegate = null;
		m_StartAutoSearchDelegate = null;
		m_EndAutoSearchDelegate = null;
		m_FilterDataDelegate = null;
		m_BeforeDataRefreshDelegate = null;
		m_AfterDataRefreshDelegate = null;
		m_BeforeEditDelegate = null;
		m_StartEditDelegate = null;
		m_ValidateEditDelegate = null;
		m_AfterEditDelegate = null;
		m_KeyPressEditDelegate = null;
		m_KeyDownEditDelegate = null;
		m_KeyUpEditDelegate = null;
		m_ChangeEditDelegate = null;
		m_BeforePageBreakDelegate = null;
		m_GetHeaderRowDelegate = null;
		m_StartPageDelegate = null;
		m_DrawCellDelegate = null;
		m_ErrorDelegate = null;
		m_CellButtonClickDelegate = null;
		m_BeforeScrollTipDelegate = null;
		m_AfterUserFreezeDelegate = null;
		m_OLEStartDragDelegate = null;
		m_OLEGiveFeedbackDelegate = null;
		m_OLESetDataDelegate = null;
		m_OLECompleteDragDelegate = null;
		m_OLEDragOverDelegate = null;
		m_OLEDragDropDelegate = null;
		m_OLESetCustomDataObjectDelegate = null;
		m_CellChangedDelegate = null;
		m_BeforeMoveRowDelegate = null;
		m_AfterMoveRowDelegate = null;
		m_SetupEditWindowDelegate = null;
		m_SetupEditStyleDelegate = null;
		m_ClickDelegate = null;
		m_DblClickDelegate = null;
		m_KeyDownDelegate = null;
		m_KeyPressDelegate = null;
		m_KeyUpDelegate = null;
		m_MouseDownDelegate = null;
		m_MouseMoveDelegate = null;
		m_MouseUpDelegate = null;
		m_SelChangeDelegate = null;
		m_RowColChangeDelegate = null;
		m_EnterCellDelegate = null;
		m_LeaveCellDelegate = null;
		m_BeforeMouseDownDelegate = null;
		m_BeforeRowColChangeDelegate = null;
		m_AfterRowColChangeDelegate = null;
		m_BeforeSelChangeDelegate = null;
		m_AfterSelChangeDelegate = null;
		m_BeforeScrollDelegate = null;
		m_AfterScrollDelegate = null;
		m_CompareDelegate = null;
		m_BeforeSortDelegate = null;
		m_AfterSortDelegate = null;
		m_BeforeMoveColumnDelegate = null;
		m_AfterMoveColumnDelegate = null;
		m_BeforeUserResizeDelegate = null;
		m_AfterUserResizeDelegate = null;
		m_BeforeCollapseDelegate = null;
		m_AfterCollapseDelegate = null;
	}
}
internal sealed class _IVSFlexGridEvents_EventProvider : _IVSFlexGridEvents_Event, IDisposable
{
	private IConnectionPointContainer m_ConnectionPointContainer;

	private ArrayList m_aEventSinkHelpers;

	private IConnectionPoint m_ConnectionPoint;

	private void Init()
	{
		IConnectionPoint ppCP = null;
		Guid riid = new Guid(new byte[16]
		{
			242, 164, 234, 249, 79, 172, 89, 71, 185, 210,
			184, 70, 43, 142, 41, 62
		});
		m_ConnectionPointContainer.FindConnectionPoint(ref riid, out ppCP);
		m_ConnectionPoint = ppCP;
		m_aEventSinkHelpers = new ArrayList();
	}

	public void add_ComboDropDown(_IVSFlexGridEvents_ComboDropDownEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_ComboDropDownDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_ComboDropDown(_IVSFlexGridEvents_ComboDropDownEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_ComboDropDownDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_ComboDropDownDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_ComboCloseUp(_IVSFlexGridEvents_ComboCloseUpEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_ComboCloseUpDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_ComboCloseUp(_IVSFlexGridEvents_ComboCloseUpEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_ComboCloseUpDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_ComboCloseUpDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_StartAutoSearch(_IVSFlexGridEvents_StartAutoSearchEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_StartAutoSearchDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_StartAutoSearch(_IVSFlexGridEvents_StartAutoSearchEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_StartAutoSearchDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_StartAutoSearchDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_EndAutoSearch(_IVSFlexGridEvents_EndAutoSearchEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_EndAutoSearchDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_EndAutoSearch(_IVSFlexGridEvents_EndAutoSearchEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_EndAutoSearchDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_EndAutoSearchDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_FilterData(_IVSFlexGridEvents_FilterDataEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_FilterDataDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_FilterData(_IVSFlexGridEvents_FilterDataEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_FilterDataDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_FilterDataDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeDataRefresh(_IVSFlexGridEvents_BeforeDataRefreshEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_BeforeDataRefreshDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_BeforeDataRefresh(_IVSFlexGridEvents_BeforeDataRefreshEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_BeforeDataRefreshDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_BeforeDataRefreshDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterDataRefresh(_IVSFlexGridEvents_AfterDataRefreshEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_AfterDataRefreshDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_AfterDataRefresh(_IVSFlexGridEvents_AfterDataRefreshEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_AfterDataRefreshDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_AfterDataRefreshDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeEdit(_IVSFlexGridEvents_BeforeEditEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_BeforeEditDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_BeforeEdit(_IVSFlexGridEvents_BeforeEditEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_BeforeEditDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_BeforeEditDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_StartEdit(_IVSFlexGridEvents_StartEditEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_StartEditDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_StartEdit(_IVSFlexGridEvents_StartEditEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_StartEditDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_StartEditDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_ValidateEdit(_IVSFlexGridEvents_ValidateEditEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_ValidateEditDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_ValidateEdit(_IVSFlexGridEvents_ValidateEditEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_ValidateEditDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_ValidateEditDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterEdit(_IVSFlexGridEvents_AfterEditEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_AfterEditDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_AfterEdit(_IVSFlexGridEvents_AfterEditEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_AfterEditDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_AfterEditDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_KeyPressEdit(_IVSFlexGridEvents_KeyPressEditEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_KeyPressEditDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_KeyPressEdit(_IVSFlexGridEvents_KeyPressEditEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_KeyPressEditDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_KeyPressEditDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_KeyDownEdit(_IVSFlexGridEvents_KeyDownEditEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_KeyDownEditDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_KeyDownEdit(_IVSFlexGridEvents_KeyDownEditEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_KeyDownEditDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_KeyDownEditDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_KeyUpEdit(_IVSFlexGridEvents_KeyUpEditEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_KeyUpEditDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_KeyUpEdit(_IVSFlexGridEvents_KeyUpEditEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_KeyUpEditDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_KeyUpEditDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_ChangeEdit(_IVSFlexGridEvents_ChangeEditEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_ChangeEditDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_ChangeEdit(_IVSFlexGridEvents_ChangeEditEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_ChangeEditDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_ChangeEditDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforePageBreak(_IVSFlexGridEvents_BeforePageBreakEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_BeforePageBreakDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_BeforePageBreak(_IVSFlexGridEvents_BeforePageBreakEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_BeforePageBreakDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_BeforePageBreakDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_GetHeaderRow(_IVSFlexGridEvents_GetHeaderRowEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_GetHeaderRowDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_GetHeaderRow(_IVSFlexGridEvents_GetHeaderRowEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_GetHeaderRowDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_GetHeaderRowDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_StartPage(_IVSFlexGridEvents_StartPageEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_StartPageDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_StartPage(_IVSFlexGridEvents_StartPageEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_StartPageDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_StartPageDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_DrawCell(_IVSFlexGridEvents_DrawCellEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_DrawCellDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_DrawCell(_IVSFlexGridEvents_DrawCellEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_DrawCellDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_DrawCellDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_Error(_IVSFlexGridEvents_ErrorEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_ErrorDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_Error(_IVSFlexGridEvents_ErrorEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_ErrorDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_ErrorDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_CellButtonClick(_IVSFlexGridEvents_CellButtonClickEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_CellButtonClickDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_CellButtonClick(_IVSFlexGridEvents_CellButtonClickEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_CellButtonClickDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_CellButtonClickDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeScrollTip(_IVSFlexGridEvents_BeforeScrollTipEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_BeforeScrollTipDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_BeforeScrollTip(_IVSFlexGridEvents_BeforeScrollTipEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_BeforeScrollTipDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_BeforeScrollTipDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterUserFreeze(_IVSFlexGridEvents_AfterUserFreezeEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_AfterUserFreezeDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_AfterUserFreeze(_IVSFlexGridEvents_AfterUserFreezeEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_AfterUserFreezeDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_AfterUserFreezeDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_OLEStartDrag(_IVSFlexGridEvents_OLEStartDragEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_OLEStartDragDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_OLEStartDrag(_IVSFlexGridEvents_OLEStartDragEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_OLEStartDragDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_OLEStartDragDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_OLEGiveFeedback(_IVSFlexGridEvents_OLEGiveFeedbackEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_OLEGiveFeedbackDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_OLEGiveFeedback(_IVSFlexGridEvents_OLEGiveFeedbackEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_OLEGiveFeedbackDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_OLEGiveFeedbackDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_OLESetData(_IVSFlexGridEvents_OLESetDataEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_OLESetDataDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_OLESetData(_IVSFlexGridEvents_OLESetDataEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_OLESetDataDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_OLESetDataDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_OLECompleteDrag(_IVSFlexGridEvents_OLECompleteDragEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_OLECompleteDragDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_OLECompleteDrag(_IVSFlexGridEvents_OLECompleteDragEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_OLECompleteDragDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_OLECompleteDragDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_OLEDragOver(_IVSFlexGridEvents_OLEDragOverEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_OLEDragOverDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_OLEDragOver(_IVSFlexGridEvents_OLEDragOverEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_OLEDragOverDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_OLEDragOverDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_OLEDragDrop(_IVSFlexGridEvents_OLEDragDropEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_OLEDragDropDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_OLEDragDrop(_IVSFlexGridEvents_OLEDragDropEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_OLEDragDropDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_OLEDragDropDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_OLESetCustomDataObject(_IVSFlexGridEvents_OLESetCustomDataObjectEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_OLESetCustomDataObjectDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_OLESetCustomDataObject(_IVSFlexGridEvents_OLESetCustomDataObjectEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_OLESetCustomDataObjectDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_OLESetCustomDataObjectDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_CellChanged(_IVSFlexGridEvents_CellChangedEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_CellChangedDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_CellChanged(_IVSFlexGridEvents_CellChangedEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_CellChangedDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_CellChangedDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeMoveRow(_IVSFlexGridEvents_BeforeMoveRowEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_BeforeMoveRowDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_BeforeMoveRow(_IVSFlexGridEvents_BeforeMoveRowEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_BeforeMoveRowDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_BeforeMoveRowDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterMoveRow(_IVSFlexGridEvents_AfterMoveRowEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_AfterMoveRowDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_AfterMoveRow(_IVSFlexGridEvents_AfterMoveRowEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_AfterMoveRowDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_AfterMoveRowDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_SetupEditWindow(_IVSFlexGridEvents_SetupEditWindowEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_SetupEditWindowDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_SetupEditWindow(_IVSFlexGridEvents_SetupEditWindowEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_SetupEditWindowDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_SetupEditWindowDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_SetupEditStyle(_IVSFlexGridEvents_SetupEditStyleEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_SetupEditStyleDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_SetupEditStyle(_IVSFlexGridEvents_SetupEditStyleEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_SetupEditStyleDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_SetupEditStyleDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_Click(_IVSFlexGridEvents_ClickEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_ClickDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_Click(_IVSFlexGridEvents_ClickEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_ClickDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_ClickDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_DblClick(_IVSFlexGridEvents_DblClickEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_DblClickDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_DblClick(_IVSFlexGridEvents_DblClickEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_DblClickDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_DblClickDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_KeyDown(_IVSFlexGridEvents_KeyDownEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_KeyDownDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_KeyDown(_IVSFlexGridEvents_KeyDownEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_KeyDownDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_KeyDownDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_KeyPress(_IVSFlexGridEvents_KeyPressEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_KeyPressDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_KeyPress(_IVSFlexGridEvents_KeyPressEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_KeyPressDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_KeyPressDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_KeyUp(_IVSFlexGridEvents_KeyUpEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_KeyUpDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_KeyUp(_IVSFlexGridEvents_KeyUpEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_KeyUpDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_KeyUpDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_MouseDown(_IVSFlexGridEvents_MouseDownEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_MouseDownDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_MouseDown(_IVSFlexGridEvents_MouseDownEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_MouseDownDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_MouseDownDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_MouseMove(_IVSFlexGridEvents_MouseMoveEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_MouseMoveDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_MouseMove(_IVSFlexGridEvents_MouseMoveEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_MouseMoveDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_MouseMoveDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_MouseUp(_IVSFlexGridEvents_MouseUpEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_MouseUpDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_MouseUp(_IVSFlexGridEvents_MouseUpEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_MouseUpDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_MouseUpDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_SelChange(_IVSFlexGridEvents_SelChangeEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_SelChangeDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_SelChange(_IVSFlexGridEvents_SelChangeEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_SelChangeDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_SelChangeDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_RowColChange(_IVSFlexGridEvents_RowColChangeEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_RowColChangeDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_RowColChange(_IVSFlexGridEvents_RowColChangeEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_RowColChangeDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_RowColChangeDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_EnterCell(_IVSFlexGridEvents_EnterCellEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_EnterCellDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_EnterCell(_IVSFlexGridEvents_EnterCellEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_EnterCellDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_EnterCellDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_LeaveCell(_IVSFlexGridEvents_LeaveCellEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_LeaveCellDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_LeaveCell(_IVSFlexGridEvents_LeaveCellEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_LeaveCellDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_LeaveCellDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeMouseDown(_IVSFlexGridEvents_BeforeMouseDownEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_BeforeMouseDownDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_BeforeMouseDown(_IVSFlexGridEvents_BeforeMouseDownEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_BeforeMouseDownDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_BeforeMouseDownDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeRowColChange(_IVSFlexGridEvents_BeforeRowColChangeEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_BeforeRowColChangeDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_BeforeRowColChange(_IVSFlexGridEvents_BeforeRowColChangeEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_BeforeRowColChangeDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_BeforeRowColChangeDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterRowColChange(_IVSFlexGridEvents_AfterRowColChangeEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_AfterRowColChangeDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_AfterRowColChange(_IVSFlexGridEvents_AfterRowColChangeEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_AfterRowColChangeDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_AfterRowColChangeDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeSelChange(_IVSFlexGridEvents_BeforeSelChangeEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_BeforeSelChangeDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_BeforeSelChange(_IVSFlexGridEvents_BeforeSelChangeEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_BeforeSelChangeDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_BeforeSelChangeDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterSelChange(_IVSFlexGridEvents_AfterSelChangeEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_AfterSelChangeDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_AfterSelChange(_IVSFlexGridEvents_AfterSelChangeEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_AfterSelChangeDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_AfterSelChangeDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeScroll(_IVSFlexGridEvents_BeforeScrollEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_BeforeScrollDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_BeforeScroll(_IVSFlexGridEvents_BeforeScrollEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_BeforeScrollDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_BeforeScrollDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterScroll(_IVSFlexGridEvents_AfterScrollEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_AfterScrollDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_AfterScroll(_IVSFlexGridEvents_AfterScrollEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_AfterScrollDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_AfterScrollDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_Compare(_IVSFlexGridEvents_CompareEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_CompareDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_Compare(_IVSFlexGridEvents_CompareEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_CompareDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_CompareDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeSort(_IVSFlexGridEvents_BeforeSortEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_BeforeSortDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_BeforeSort(_IVSFlexGridEvents_BeforeSortEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_BeforeSortDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_BeforeSortDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterSort(_IVSFlexGridEvents_AfterSortEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_AfterSortDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_AfterSort(_IVSFlexGridEvents_AfterSortEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_AfterSortDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_AfterSortDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeMoveColumn(_IVSFlexGridEvents_BeforeMoveColumnEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_BeforeMoveColumnDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_BeforeMoveColumn(_IVSFlexGridEvents_BeforeMoveColumnEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_BeforeMoveColumnDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_BeforeMoveColumnDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterMoveColumn(_IVSFlexGridEvents_AfterMoveColumnEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_AfterMoveColumnDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_AfterMoveColumn(_IVSFlexGridEvents_AfterMoveColumnEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_AfterMoveColumnDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_AfterMoveColumnDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeUserResize(_IVSFlexGridEvents_BeforeUserResizeEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_BeforeUserResizeDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_BeforeUserResize(_IVSFlexGridEvents_BeforeUserResizeEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_BeforeUserResizeDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_BeforeUserResizeDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterUserResize(_IVSFlexGridEvents_AfterUserResizeEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_AfterUserResizeDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_AfterUserResize(_IVSFlexGridEvents_AfterUserResizeEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_AfterUserResizeDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_AfterUserResizeDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeCollapse(_IVSFlexGridEvents_BeforeCollapseEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_BeforeCollapseDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_BeforeCollapse(_IVSFlexGridEvents_BeforeCollapseEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_BeforeCollapseDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_BeforeCollapseDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterCollapse(_IVSFlexGridEvents_AfterCollapseEventHandler P_0)
	{
		bool lockTaken = default(bool);
		try
		{
			Monitor.Enter(this, ref lockTaken);
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = new _IVSFlexGridEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSFlexGridEvents_SinkHelper, out pdwCookie);
			iVSFlexGridEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSFlexGridEvents_SinkHelper.m_AfterCollapseDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSFlexGridEvents_SinkHelper);
		}
		finally
		{
			if (lockTaken)
			{
				Monitor.Exit(this);
			}
		}
	}

	public void remove_AfterCollapse(_IVSFlexGridEvents_AfterCollapseEventHandler P_0)
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
				_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSFlexGridEvents_SinkHelper.m_AfterCollapseDelegate != null && ((iVSFlexGridEvents_SinkHelper.m_AfterCollapseDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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

	public _IVSFlexGridEvents_EventProvider(object P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_ConnectionPointContainer = (IConnectionPointContainer)P_0;
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
					_IVSFlexGridEvents_SinkHelper iVSFlexGridEvents_SinkHelper = (_IVSFlexGridEvents_SinkHelper)m_aEventSinkHelpers[num];
					m_ConnectionPoint.Unadvise(iVSFlexGridEvents_SinkHelper.m_dwCookie);
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
