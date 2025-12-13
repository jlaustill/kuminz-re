using System;
using System.Collections;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
using System.Threading;
using stdole;

[assembly: ImportedFromTypeLib("VSPrinter8Lib")]
[assembly: Guid("54850c51-14ea-4470-a5e4-8c5db32dc853")]
[assembly: TypeLibVersion(1, 0)]
[assembly: AssemblyVersion("1.0.0.0")]
namespace VSPrinter8Lib;

public enum StyleFlagsSettings
{
	vpsCharacter = 1,
	vpsParagraph = 2,
	vpsGraphics = 4,
	vpsContent = 7,
	vpsPage = 8,
	vpsAll = 65535
}
public enum AppearanceSettings
{
	apFlat,
	ap3D,
	ap3DLight
}
public enum BorderStyleSettings
{
	bsNone,
	bsSingle
}
public enum MousePointerSettings
{
	mpDefault = 0,
	mpArrow = 1,
	mpCross = 2,
	mpIBeam = 3,
	mpIcon = 4,
	mpSize = 5,
	mpSizeNESW = 6,
	mpSizeNS = 7,
	mpSizeNWSE = 8,
	mpSizeEW = 9,
	mpUpArrow = 10,
	mpHourglass = 11,
	mpNoDrop = 12,
	mpArrowHourGlass = 13,
	mpArrowQuestion = 14,
	mpSizeAll = 15,
	mpHandPoint = 50,
	mpHandDrag = 51,
	mpPage = 52,
	mpZoom = 53,
	mpCustom = 99
}
public enum ZoomModeSettings
{
	zmPercentage,
	zmThumbnail,
	zmTwoPages,
	zmWholePage,
	zmPageWidth,
	zmStretch
}
public enum NavBarSettings
{
	vpnbNone,
	vpnbTop,
	vpnbBottom,
	vpnbTopPrint,
	vpnbBottomPrint
}
public enum NavigationSettings
{
	vpnvNone,
	vpnvMouse,
	vpnvWheel,
	vpnvMouseWheel,
	vpnvKeyboard,
	vpnvMouseKeyboard,
	vpnvWheelKeyboard,
	vpnvAll
}
public enum PrinterErrorSettings
{
	vperCantAccessPrinter = 3,
	vperCantStartJob,
	vperUserAborted,
	vperAlreadyPrinting,
	vperDeviceIncapable,
	vperControlIncapable,
	vperCantInBrowser
}
public enum ExportFormatSettings
{
	vpxPlainHTML,
	vpxDHTML,
	vpxPagedHTML,
	vpxPagedDHTML,
	vpxRTF,
	vpxRTFExtended,
	vpxDHTMLExtended
}
public enum PrintDialogSettings
{
	pdPrinterSetup = 0,
	pdPageSetup = 1,
	pdPrint = 2,
	pdPrintCopies = 3,
	pdGetFromPage = 100,
	pdGetToPage = 101,
	pdGetToFile = 102,
	pdGetNumCopies = 103
}
public enum AbortWindowPosSettings
{
	awAppWindow,
	awScreenCenter
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
	arcFileName,
	arcFileSize,
	arcFileCompressedSize,
	arcFileDate
}
public enum ActionSettings
{
	paNone,
	paPrintFile,
	paChoosePrintFile,
	paStartDoc,
	paNewPage,
	paNewCol,
	paEndDoc,
	paAbortDoc,
	paPrintPage,
	paChoosePrintPage,
	paCopyPage,
	paPrintAll,
	paChoosePrintAll,
	paChoosePrinter,
	paPageSetup
}
public enum ShowGuideSettings
{
	gdHide,
	gdShow,
	gdDesignTime
}
public enum TextAlignSettings
{
	taLeftTop,
	taCenterTop,
	taRightTop,
	taLeftBottom,
	taCenterBottom,
	taRightBottom,
	taLeftMiddle,
	taCenterMiddle,
	taRightMiddle,
	taJustTop,
	taJustBottom,
	taJustMiddle
}
public enum PictureAlignSettings
{
	vppaLeftTop,
	vppaCenterTop,
	vppaRightTop,
	vppaLeftBottom,
	vppaCenterBottom,
	vppaRightBottom,
	vppaLeftMiddle,
	vppaCenterMiddle,
	vppaRightMiddle,
	vppaClip,
	vppaZoom,
	vppaStretch,
	vppaTile
}
public enum PageBorderSettings
{
	pbNone,
	pbBottom,
	pbTop,
	pbTopBottom,
	pbBox,
	pbColumns,
	pbColTopBottom,
	pbAll,
	pbColTop,
	pbColBottom
}
public enum TableBorderSettings
{
	tbNone,
	tbBottom,
	tbTop,
	tbTopBottom,
	tbBox,
	tbColumns,
	tbColTopBottom,
	tbAll,
	tbBoxRows,
	tbBoxColumns,
	tbBelowHeader,
	tbRows
}
public enum TableCellSettings
{
	tcIndent,
	tcRows,
	tcCols,
	tcInsertRow,
	tcInsertCol,
	tcDeleteRow,
	tcDeleteCol,
	tcRowHeight,
	tcRowBorder,
	tcRowData,
	tcRowSource,
	tcRowKeepWithNext,
	tcRowIsSubHeader,
	tcColWidth,
	tcColBorder,
	tcColData,
	tcColSource,
	tcColSpan,
	tcText,
	tcAlign,
	tcBackColor,
	tcForeColor,
	tcFont,
	tcFontName,
	tcFontSize,
	tcFontBold,
	tcFontItalic,
	tcFontUnderline,
	tcFontStrikethru,
	tcPicture,
	tcPictureAlign,
	tcColAlign,
	tcColNoWrap,
	tcColSkipRepeats,
	tcRowSpaceBefore,
	tcRowSpaceAfter,
	tcRowBorderAbove,
	tcRowBorderBelow,
	tcRowBorderColor,
	tcRowNewPage,
	tcRowKeepTogether,
	tcRowSpan,
	tcVertical,
	tcColBorderLeft,
	tcColBorderRight,
	tcColBorderColor,
	tcAlignCurrency
}
public enum OrientationSettings
{
	orPortrait,
	orLandscape
}
public enum PrintQualitySettings
{
	pqDraft = -1,
	pqLow = -2,
	pqMedium = -3,
	pqHigh = -4
}
public enum ColorModeSettings
{
	cmMonochrome = 1,
	cmColor
}
public enum DuplexSettings
{
	dupSimplex = 1,
	dupVertical,
	dupHorizontal
}
public enum TrueTypeSettings
{
	ttBitmap = 1,
	ttDownload,
	ttSubDevice,
	ttOutline
}
public enum CollateSettings
{
	colFalse,
	colTrue
}
public enum PaperBinSettings
{
	binUpper = 1,
	binLower = 2,
	binMiddle = 3,
	binManual = 4,
	binEnvelope = 5,
	binEnvManual = 6,
	binAuto = 7,
	binTractor = 8,
	binSmallFmt = 9,
	binLargeFmt = 10,
	binLargeCapacity = 11,
	binCassette = 14,
	binFormSource = 15,
	binUser = 256
}
public enum PaperSizeSettings
{
	pprLetter = 1,
	pprLetterSmall = 2,
	pprTabloid = 3,
	pprLedger = 4,
	pprLegal = 5,
	pprStatement = 6,
	pprExecutive = 7,
	pprA3 = 8,
	pprA4 = 9,
	pprA4Small = 10,
	pprA5 = 11,
	pprB4 = 12,
	pprB5 = 13,
	pprFolio = 14,
	pprQuarto = 15,
	ppr10x14 = 16,
	ppr11x17 = 17,
	pprNote = 18,
	pprEnv9 = 19,
	pprEnv10 = 20,
	pprEnv11 = 21,
	pprEnv12 = 22,
	pprEnv14 = 23,
	pprCSheet = 24,
	pprDSheet = 25,
	pprESheet = 26,
	pprEnvDL = 27,
	pprEnvC5 = 28,
	pprEnvC3 = 29,
	pprEnvC4 = 30,
	pprEnvC6 = 31,
	pprEnvC65 = 32,
	pprEnvB4 = 33,
	pprEnvB5 = 34,
	pprEnvB6 = 35,
	pprEnvItaly = 36,
	pprEnvMonarch = 37,
	pprEnvPersonal = 38,
	pprFanfoldUS = 39,
	pprFanfoldStdGerman = 40,
	pprFanfoldLglGerman = 41,
	pprISOB4 = 42,
	pprJapanesePostcard = 43,
	ppr9x11 = 44,
	ppr10x11 = 45,
	ppr15x11 = 46,
	pprEnvInvite = 47,
	pprLetterExtra = 50,
	pprLegalExtra = 51,
	pprTabloidExtra = 52,
	pprA4Extra = 53,
	pprLetterTransverse = 54,
	pprA4Transverse = 55,
	pprLetterExtraTransverse = 56,
	pprAPlus = 57,
	pprBPlus = 58,
	pprLetterPlus = 59,
	pprA4Plus = 60,
	pprA5Transverse = 61,
	pprB5Transverse = 62,
	pprA3Extra = 63,
	pprA5Extra = 64,
	pprB5Extra = 65,
	pprA2 = 66,
	pprA3Transverse = 67,
	pprA3ExtraTransverse = 68,
	pprUser = 256
}
public enum ReadyStateSettings
{
	vpstEmpty,
	vpstLoading,
	vpstReady,
	vpstOpen,
	vpstSaving,
	vpstPrinting
}
public enum PenStyleSettings
{
	psSolid,
	psDash,
	psDot,
	psDashDot,
	psDashDotDot,
	psTransparent,
	psInsideSolid
}
public enum BrushStyleSettings
{
	bsSolid,
	bsTransparent,
	bsHorzLine,
	bsVertLine,
	bsDiagonalUp,
	bsDiagonalDown,
	bsCross,
	bsDiagonalCross
}
public enum DrawSettings
{
	doNothing,
	doLine,
	doRectangle,
	doEllipse
}
[ComImport]
[TypeLibType(4160)]
[Guid("1D433C63-E7F0-43EB-960D-B1BF82B5FE1E")]
public interface IVSPrinterStyle
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void Clear();

	[DispId(2)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void Add([MarshalAs(UnmanagedType.BStr)] string Key, StyleFlagsSettings Flags);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void Remove([MarshalAs(UnmanagedType.Struct)] object Index);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void Apply([MarshalAs(UnmanagedType.Struct)] object Index);

	[DispId(6)]
	string Key
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(7)]
	StyleFlagsSettings Flags
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void Save([MarshalAs(UnmanagedType.BStr)] string FileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void Load([MarshalAs(UnmanagedType.BStr)] string FileName);
}
[ComImport]
[Guid("B19E69FD-F3CC-41C9-BB01-F5F6AEF3243B")]
[TypeLibType(4160)]
[DefaultMember("Paragraph")]
public interface IVSPrinter
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[TypeLibFunc(64)]
	[DispId(-552)]
	void About();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-550)]
	void Refresh();

	[DispId(-515)]
	int hWnd
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(-515)]
		get;
	}

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

	[DispId(-501)]
	[ComAliasName("stdole.OLE_COLOR")]
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

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(-522)]
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

	[DispId(-523)]
	[ComAliasName("stdole.IPictureDisp")]
	IPictureDisp Picture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-523)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-523)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(-523)]
	void let_Picture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[DispId(-512)]
	[ComAliasName("stdole.IFontDisp")]
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

	[DispId(2)]
	string FontName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	float FontSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(3)]
		[param: In]
		set;
	}

	[DispId(4)]
	bool FontBold
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
	bool FontItalic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(5)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(5)]
		[param: In]
		set;
	}

	[DispId(6)]
	bool FontStrikethru
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(7)]
	bool FontUnderline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(8)]
	short Version
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
	OrientationSettings Orientation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(9)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(9)]
		[param: In]
		set;
	}

	[DispId(10)]
	short Copies
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(11)]
	float PaperWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(11)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(12)]
	float PaperHeight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(12)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(12)]
		[param: In]
		set;
	}

	[DispId(13)]
	PaperSizeSettings PaperSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(13)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(13)]
		[param: In]
		set;
	}

	[DispId(14)]
	PrintQualitySettings PrintQuality
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(14)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(15)]
	ColorModeSettings ColorMode
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
	DuplexSettings Duplex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(16)]
		[param: In]
		set;
	}

	[DispId(17)]
	TrueTypeSettings TrueType
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
	CollateSettings Collate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(18)]
		[param: In]
		set;
	}

	[DispId(19)]
	short ScaleOutput
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(19)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(19)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(20)]
	PaperBinSettings PaperBin
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(20)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(20)]
		[param: In]
		set;
	}

	[DispId(21)]
	bool PaperSizes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(22)]
	bool PaperBins
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(22)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(23)]
	string Devices
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	short NDevices
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(24)]
		get;
	}

	[DispId(25)]
	string Ports
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(26)]
	short NPorts
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(27)]
	string Device
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(27)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(28)]
	string Port
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(28)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(28)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(29)]
	string Driver
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(29)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(30)]
	bool DefaultDevice
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
	double PageWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(32)]
	double PageHeight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(32)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(33)]
	double Zoom
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[param: In]
		set;
	}

	[DispId(34)]
	bool PhysicalPage
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[param: In]
		set;
	}

	[DispId(35)]
	[ComAliasName("stdole.OLE_COLOR")]
	uint EmptyColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(35)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(35)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(36)]
	[ComAliasName("stdole.OLE_COLOR")]
	uint BrushColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(36)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(36)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(37)]
	[ComAliasName("stdole.OLE_COLOR")]
	uint PenColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(37)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(37)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(38)]
	uint TextColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(39)]
	[ComAliasName("stdole.OLE_COLOR")]
	uint HdrColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(40)]
	double LargeChangeHorz
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
	double LargeChangeVert
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
	double SmallChangeHorz
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
	double SmallChangeVert
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(43)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(43)]
		[param: In]
		set;
	}

	[DispId(44)]
	bool Track
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(44)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(44)]
		[param: In]
		set;
	}

	[DispId(46)]
	bool ProportionalBars
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(46)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(46)]
		[param: In]
		set;
	}

	[DispId(47)]
	double ScrollLeft
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(47)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(47)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(48)]
	double ScrollTop
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(48)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(48)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(49)]
	object MarginLeft
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(49)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(49)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(50)]
	object MarginTop
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(50)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(50)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(51)]
	object MarginRight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(51)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(51)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(52)]
	object MarginBottom
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(52)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(52)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(53)]
	object IndentLeft
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(53)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(53)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(54)]
	object IndentRight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(54)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(54)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(55)]
	object IndentFirst
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(55)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(55)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(56)]
	object IndentTab
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(56)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(56)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(57)]
	object LineSpacing
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(57)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(57)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(58)]
	short Columns
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(58)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(58)]
		[param: In]
		set;
	}

	[DispId(59)]
	object ColumnSpacing
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(60)]
	ShowGuideSettings ShowGuides
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[param: In]
		set;
	}

	[DispId(61)]
	object MarginHeader
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(62)]
	object MarginFooter
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(62)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(62)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(63)]
	object SpaceBefore
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(63)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(63)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(64)]
	object SpaceAfter
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(64)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(64)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(65)]
	void StartDoc();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(66)]
	void EndDoc();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(67)]
	void KillDoc();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(68)]
	void NewPage();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(69)]
	void NewColumn();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(70)]
	void PrintDoc([Optional][MarshalAs(UnmanagedType.Struct)] object Choose, [Optional][MarshalAs(UnmanagedType.Struct)] object FromPage, [Optional][MarshalAs(UnmanagedType.Struct)] object ToPage);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(71)]
	void PrintFile([MarshalAs(UnmanagedType.BStr)] string FileName);

	[DispId(72)]
	ActionSettings Action
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(72)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(73)]
	DrawSettings Draw
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(73)]
		[param: In]
		set;
	}

	[DispId(74)]
	BrushStyleSettings BrushStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(74)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(74)]
		[param: In]
		set;
	}

	[DispId(75)]
	PenStyleSettings PenStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(75)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(75)]
		[param: In]
		set;
	}

	[DispId(76)]
	object PenWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(76)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(76)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(77)]
	object X1
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(77)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(77)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(78)]
	object Y1
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(78)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(78)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(79)]
	object X2
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(79)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(79)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(80)]
	object Y2
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(80)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(80)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(81)]
	string Polyline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(81)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(82)]
	string Polygon
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(82)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(83)]
	void DrawLine([MarshalAs(UnmanagedType.Struct)] object X1, [MarshalAs(UnmanagedType.Struct)] object Y1, [Optional][MarshalAs(UnmanagedType.Struct)] object X2, [Optional][MarshalAs(UnmanagedType.Struct)] object Y2);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(84)]
	void DrawRectangle([MarshalAs(UnmanagedType.Struct)] object X1, [MarshalAs(UnmanagedType.Struct)] object Y1, [MarshalAs(UnmanagedType.Struct)] object X2, [MarshalAs(UnmanagedType.Struct)] object Y2, [Optional][MarshalAs(UnmanagedType.Struct)] object Radius1, [Optional][MarshalAs(UnmanagedType.Struct)] object Radius2);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(85)]
	void DrawCircle([MarshalAs(UnmanagedType.Struct)] object CenterX, [MarshalAs(UnmanagedType.Struct)] object CenterY, [MarshalAs(UnmanagedType.Struct)] object Radius, [Optional][MarshalAs(UnmanagedType.Struct)] object Start, [Optional][MarshalAs(UnmanagedType.Struct)] object End);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(86)]
	void DrawEllipse([MarshalAs(UnmanagedType.Struct)] object X1, [MarshalAs(UnmanagedType.Struct)] object Y1, [MarshalAs(UnmanagedType.Struct)] object X2, [MarshalAs(UnmanagedType.Struct)] object Y2, [Optional][MarshalAs(UnmanagedType.Struct)] object Start, [Optional][MarshalAs(UnmanagedType.Struct)] object End);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(87)]
	void DrawPicture([ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp Picture, [MarshalAs(UnmanagedType.Struct)] object Left, [MarshalAs(UnmanagedType.Struct)] object Top, [Optional][MarshalAs(UnmanagedType.Struct)] object Width, [Optional][MarshalAs(UnmanagedType.Struct)] object Height, [Optional][MarshalAs(UnmanagedType.Struct)] object Align, [Optional][MarshalAs(UnmanagedType.Struct)] object Shade);

	[DispId(88)]
	short PreviewPage
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(88)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(88)]
		[param: In]
		set;
	}

	[DispId(89)]
	short PreviewPages
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(89)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(90)]
	short PageCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(90)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(91)]
	PageBorderSettings PageBorder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(91)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(91)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(92)]
	void ClientToPage(ref float X, ref float Y, [Optional][MarshalAs(UnmanagedType.Struct)] ref object Page);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(93)]
	void PageToClient(ref float X, ref float Y);

	[DispId(94)]
	string Header
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(94)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(94)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(95)]
	string Footer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(95)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(95)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("stdole.IFontDisp")]
	[DispId(96)]
	IFontDisp HdrFont
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(96)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IFontDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(96)]
		[param: In]
		[param: ComAliasName("stdole.IFontDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(96)]
	void let_HdrFont([In][ComAliasName("stdole.IFontDisp")][MarshalAs(UnmanagedType.Interface)] IFontDisp pVal);

	[DispId(97)]
	string HdrFontName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(97)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(97)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(98)]
	float HdrFontSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(98)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(98)]
		[param: In]
		set;
	}

	[DispId(99)]
	bool HdrFontBold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(99)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(99)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(100)]
	bool HdrFontItalic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(100)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(101)]
	bool HdrFontStrikethru
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(102)]
	bool HdrFontUnderline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(103)]
	void TextBox([MarshalAs(UnmanagedType.BStr)] string Text, [MarshalAs(UnmanagedType.Struct)] object X, [MarshalAs(UnmanagedType.Struct)] object Y, [MarshalAs(UnmanagedType.Struct)] object Width, [MarshalAs(UnmanagedType.Struct)] object Height, [Optional][MarshalAs(UnmanagedType.Struct)] object Wrap, [Optional][MarshalAs(UnmanagedType.Struct)] object Calc, [Optional][MarshalAs(UnmanagedType.Struct)] object Shade);

	[DispId(0)]
	string Paragraph
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(105)]
	string Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(105)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(106)]
	object CurrentX
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(106)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(106)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(107)]
	object CurrentY
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(107)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(107)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(108)]
	TextAlignSettings TextAlign
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(108)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(108)]
		[param: In]
		set;
	}

	[DispId(109)]
	short TextAngle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(109)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(111)]
	short ZoomMax
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
	short ZoomMin
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(112)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(112)]
		[param: In]
		set;
	}

	[DispId(113)]
	short ZoomStep
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(113)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(113)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(115)]
	void Archive([MarshalAs(UnmanagedType.BStr)] string arcFileName, [MarshalAs(UnmanagedType.BStr)] string FileName, ArchiveSettings Action);

	[DispId(116)]
	object ArchiveInfo
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(116)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(117)]
	short CurrentPage
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(117)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(118)]
	short CurrentColumn
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(118)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(118)]
		[param: In]
		set;
	}

	[DispId(119)]
	short CurrentLine
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
	double TwipsPerPixelX
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(120)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(121)]
	double TwipsPerPixelY
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(121)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(122)]
	int RenderControl
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(122)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(123)]
	void SaveDoc([MarshalAs(UnmanagedType.BStr)] string FileName, [Optional][MarshalAs(UnmanagedType.Struct)] object Compress, [Optional][MarshalAs(UnmanagedType.Struct)] object FromPage, [Optional][MarshalAs(UnmanagedType.Struct)] object ToPage);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(124)]
	void LoadDoc([MarshalAs(UnmanagedType.BStr)] string FileName, [Optional][MarshalAs(UnmanagedType.Struct)] object Append);

	[DispId(125)]
	int hDC
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(125)]
		get;
	}

	[DispId(126)]
	bool Preview
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(126)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(126)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(127)]
	void StartOverlay(short Page, [Optional][MarshalAs(UnmanagedType.Struct)] object Preserve);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(128)]
	void EndOverlay();

	[DispId(129)]
	bool AutoRTF
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(129)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(129)]
		[param: In]
		set;
	}

	[DispId(130)]
	string TextRTF
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(130)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(131)]
	string TableSep
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(131)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(131)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(132)]
	TableBorderSettings TableBorder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(132)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(132)]
		[param: In]
		set;
	}

	[DispId(133)]
	string Table
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(133)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(134)]
	void AddTable([MarshalAs(UnmanagedType.BStr)] string Format, [MarshalAs(UnmanagedType.BStr)] string Header, [MarshalAs(UnmanagedType.BStr)] string Body, [Optional][MarshalAs(UnmanagedType.Struct)] object HeaderShade, [Optional][MarshalAs(UnmanagedType.Struct)] object BodyShade, [Optional][MarshalAs(UnmanagedType.Struct)] object Append);

	[DispId(135)]
	string Measure
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(135)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(136)]
	double TextWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(136)]
		get;
	}

	[DispId(137)]
	double TextHeight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(137)]
		get;
	}

	[DispId(138)]
	bool Measuring
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(138)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(139)]
	double TextWid
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(139)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(140)]
	double TextHei
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(140)]
		get;
	}

	[DispId(141)]
	string CalcParagraph
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(141)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(142)]
	[TypeLibFunc(1024)]
	void let_CalcPicture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp P_0);

	[DispId(142)]
	[ComAliasName("stdole.IPictureDisp")]
	IPictureDisp CalcPicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(142)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(143)]
	string CalcTable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(143)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(144)]
	string CalcText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(144)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(145)]
	string CalcTextRTF
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(145)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(146)]
	int PrintDialog(PrintDialogSettings DialogType);

	[DispId(147)]
	string FileName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(147)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(147)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(148)]
	string AbortCaption
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(148)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(148)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(149)]
	string AbortTextButton
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(149)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(149)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(150)]
	string AbortTextDevice
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(150)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(150)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(151)]
	string AbortTextPage
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(151)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(151)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(152)]
	bool AbortWindow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(152)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(152)]
		[param: In]
		set;
	}

	[DispId(153)]
	AbortWindowPosSettings AbortWindowPos
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(153)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(153)]
		[param: In]
		set;
	}

	[DispId(154)]
	short DPI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(154)]
		get;
	}

	[DispId(155)]
	object TablePen
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(155)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(155)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(156)]
	object TablePenLR
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(156)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(156)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(157)]
	object TablePenTB
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(157)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(157)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(158)]
	void AddTableArray([MarshalAs(UnmanagedType.BStr)] string Format, [MarshalAs(UnmanagedType.BStr)] string Header, [MarshalAs(UnmanagedType.Struct)] object Body, [Optional][MarshalAs(UnmanagedType.Struct)] object HeaderShade, [Optional][MarshalAs(UnmanagedType.Struct)] object BodyShade, [Optional][MarshalAs(UnmanagedType.Struct)] object Append);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(159)]
	void StartTable();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(160)]
	void EndTable();

	[DispId(161)]
	object TableCell
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(161)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(161)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[TypeLibFunc(1024)]
	[DispId(161)]
	void let_TableCell(TableCellSettings Setting, [Optional][MarshalAs(UnmanagedType.Struct)] object Row1, [Optional][MarshalAs(UnmanagedType.Struct)] object Col1, [Optional][MarshalAs(UnmanagedType.Struct)] object Row2, [Optional][MarshalAs(UnmanagedType.Struct)] object Col2, [In][MarshalAs(UnmanagedType.Struct)] object pVal);

	[DispId(162)]
	string OutputFileName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(162)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(162)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(163)]
	PrinterErrorSettings Error
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(163)]
		get;
	}

	[DispId(164)]
	ZoomModeSettings ZoomMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(164)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(164)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(165)]
	void GetMargins();

	[DispId(166)]
	string DocName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(166)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(166)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(170)]
	IPictureDisp PalettePicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(170)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(170)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(170)]
	void let_PalettePicture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[DispId(171)]
	NavBarSettings NavBar
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(171)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(171)]
		[param: In]
		set;
	}

	[DispId(172)]
	string NavBarText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(172)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(172)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(173)]
	uint NavBarColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(173)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(173)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(174)]
	string ExportFile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(174)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(174)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(175)]
	ExportFormatSettings ExportFormat
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(175)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(175)]
		[param: In]
		set;
	}

	[DispId(176)]
	string ExportRaw
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(176)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(177)]
	string ExportNavBar
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(177)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(177)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(178)]
	ReadyStateSettings ReadyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(178)]
		get;
	}

	[DispId(179)]
	string ErrorDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(179)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(180)]
	string URL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(180)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(180)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(181)]
	NavigationSettings Navigation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(181)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(181)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(182)]
	void Clear();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(183)]
	void ScrollIntoView([MarshalAs(UnmanagedType.Struct)] object Left, [MarshalAs(UnmanagedType.Struct)] object Top, [Optional][MarshalAs(UnmanagedType.Struct)] object Right, [Optional][MarshalAs(UnmanagedType.Struct)] object Bottom);

	[DispId(184)]
	VSPrinterStyle Styles
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(184)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(185)]
	int FindText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(185)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(186)]
	string RetrieveText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(186)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(187)]
	int FindTag
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(187)]
		get;
	}

	[DispId(188)]
	string RetrieveTag
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(188)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(189)]
	void StartTag([MarshalAs(UnmanagedType.BStr)] string Text, [Optional][MarshalAs(UnmanagedType.Struct)] object Left, [Optional][MarshalAs(UnmanagedType.Struct)] object Top, [Optional][MarshalAs(UnmanagedType.Struct)] object Right, [Optional][MarshalAs(UnmanagedType.Struct)] object Bottom);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(190)]
	void EndTag();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(191)]
	void MovePages(int First, int Last, bool bToFront);

	[DispId(192)]
	string NavBarMenuText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(192)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(192)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(193)]
	IPictureDisp LoadPicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(193)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
	}

	[DispId(194)]
	bool AutoLinkNavigate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(194)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(194)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(195)]
	void AddLink([MarshalAs(UnmanagedType.BStr)] string LinkText, [MarshalAs(UnmanagedType.BStr)] string LinkTarget, bool Formatted);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(196)]
	void AddLinkTarget([MarshalAs(UnmanagedType.BStr)] string TargetText, [MarshalAs(UnmanagedType.BStr)] string TargetName);

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
}
[ComImport]
[TypeLibType(4096)]
[InterfaceType(2)]
[Guid("5810EFA5-748A-47AC-B2BF-C9A3A6844E28")]
public interface _IVSPrinterEvents
{
	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-600)]
	void Click();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-601)]
	void DblClick();

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
	[DispId(-602)]
	void KeyDown([In][Out] ref short KeyCode, short Shift);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-603)]
	void KeyPress([In][Out] ref short KeyAscii);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-604)]
	void KeyUp([In][Out] ref short KeyCode, short Shift);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void StartDoc();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void NewLine();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void NewColumn();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	void NewPage();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void EndPage();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(6)]
	void EndDoc();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	void Error();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	void ResetDC();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	void SavingDoc(short Page, short Of, [In][Out] ref bool Cancel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(10)]
	void LoadingDoc(short Page, short Of, [In][Out] ref bool Cancel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(11)]
	void BeforeHeader();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(12)]
	void BeforeFooter();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(13)]
	void AfterHeader();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	void AfterFooter();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	void ReadyStateChange(int ReadyState);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	void BeforeUserZoom([In][Out] ref short NewZoom);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	void AfterUserZoom();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	void BeforeUserPage([In][Out] ref short NewPage);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(20)]
	void AfterUserPage();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(21)]
	void BeforeUserScroll([In][Out] ref bool Cancel);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(22)]
	void AfterUserScroll();

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(23)]
	void BeforeTableCell(int Row, int Col, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string Text, [In][Out] ref bool KeepFiring);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(24)]
	void AfterTableCell(int Row, int Col, double Left, double Top, double Right, double Bottom, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string Text, [In][Out] ref bool KeepFiring);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(25)]
	void LayoutThumbnails([In][Out] ref short PagesX);

	[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(26)]
	void MouseLink([MarshalAs(UnmanagedType.BStr)] ref string Link, bool Clicked, [In][Out] ref short Cancel);
}
[ComImport]
[Guid("819F123A-B24A-4EB8-BED1-B5DFC5CB5194")]
[TypeLibType(2)]
[ComSourceInterfaces("VSPrinter8Lib._IVSPrinterEvents\0\0")]
[ClassInterface(0)]
[DefaultMember("Paragraph")]
public class VSPrinterClass : IVSPrinter, VSPrinter, _IVSPrinterEvents_Event
{
	[DispId(-515)]
	public virtual extern int hWnd
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-515)]
		[TypeLibFunc(1024)]
		get;
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

	[ComAliasName("stdole.IPictureDisp")]
	[DispId(-523)]
	public virtual extern IPictureDisp Picture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-523)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-523)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
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

	[DispId(2)]
	public virtual extern string FontName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(2)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(3)]
	public virtual extern float FontSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(3)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(3)]
		[param: In]
		set;
	}

	[DispId(4)]
	public virtual extern bool FontBold
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
	public virtual extern bool FontItalic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(5)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(5)]
		[param: In]
		set;
	}

	[DispId(6)]
	public virtual extern bool FontStrikethru
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(6)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(7)]
	public virtual extern bool FontUnderline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(7)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(7)]
		[param: In]
		set;
	}

	[DispId(8)]
	public virtual extern short Version
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
	public virtual extern OrientationSettings Orientation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(10)]
	public virtual extern short Copies
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(10)]
		[param: In]
		set;
	}

	[DispId(11)]
	public virtual extern float PaperWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(11)]
		[param: In]
		set;
	}

	[DispId(12)]
	public virtual extern float PaperHeight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(12)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(13)]
	public virtual extern PaperSizeSettings PaperSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(13)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(14)]
	public virtual extern PrintQualitySettings PrintQuality
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(14)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(14)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(15)]
	public virtual extern ColorModeSettings ColorMode
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
	public virtual extern DuplexSettings Duplex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(16)]
		[param: In]
		set;
	}

	[DispId(17)]
	public virtual extern TrueTypeSettings TrueType
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
	public virtual extern CollateSettings Collate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(18)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(19)]
	public virtual extern short ScaleOutput
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(19)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(19)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(20)]
	public virtual extern PaperBinSettings PaperBin
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(21)]
	public virtual extern bool PaperSizes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(21)]
		get;
	}

	[DispId(22)]
	public virtual extern bool PaperBins
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(22)]
		get;
	}

	[DispId(23)]
	public virtual extern string Devices
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(23)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(24)]
	public virtual extern short NDevices
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(25)]
	public virtual extern string Ports
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(26)]
	public virtual extern short NPorts
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(26)]
		get;
	}

	[DispId(27)]
	public virtual extern string Device
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(27)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(28)]
	public virtual extern string Port
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(28)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(28)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(29)]
	public virtual extern string Driver
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(29)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(30)]
	public virtual extern bool DefaultDevice
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
	public virtual extern double PageWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(32)]
	public virtual extern double PageHeight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(32)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(33)]
	public virtual extern double Zoom
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(33)]
		[param: In]
		set;
	}

	[DispId(34)]
	public virtual extern bool PhysicalPage
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[param: In]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(35)]
	public virtual extern uint EmptyColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(35)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(35)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(36)]
	public virtual extern uint BrushColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(36)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(36)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(37)]
	[ComAliasName("stdole.OLE_COLOR")]
	public virtual extern uint PenColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(37)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(37)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(38)]
	public virtual extern uint TextColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(38)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[ComAliasName("stdole.OLE_COLOR")]
	[DispId(39)]
	public virtual extern uint HdrColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(39)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(40)]
	public virtual extern double LargeChangeHorz
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
	public virtual extern double LargeChangeVert
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
	public virtual extern double SmallChangeHorz
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
	public virtual extern double SmallChangeVert
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(43)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(43)]
		[param: In]
		set;
	}

	[DispId(44)]
	public virtual extern bool Track
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(44)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(44)]
		[param: In]
		set;
	}

	[DispId(46)]
	public virtual extern bool ProportionalBars
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(46)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(46)]
		[param: In]
		set;
	}

	[DispId(47)]
	public virtual extern double ScrollLeft
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(47)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(47)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(48)]
	public virtual extern double ScrollTop
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(48)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(48)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(49)]
	public virtual extern object MarginLeft
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(49)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(49)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(50)]
	public virtual extern object MarginTop
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(50)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(50)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(51)]
	public virtual extern object MarginRight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(51)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(51)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(52)]
	public virtual extern object MarginBottom
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(52)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(52)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(53)]
	public virtual extern object IndentLeft
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(53)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(53)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(54)]
	public virtual extern object IndentRight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(54)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(54)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(55)]
	public virtual extern object IndentFirst
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(55)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(55)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(56)]
	public virtual extern object IndentTab
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(56)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(56)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(57)]
	public virtual extern object LineSpacing
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(57)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(57)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(58)]
	public virtual extern short Columns
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(58)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(58)]
		[param: In]
		set;
	}

	[DispId(59)]
	public virtual extern object ColumnSpacing
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(59)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(60)]
	public virtual extern ShowGuideSettings ShowGuides
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(60)]
		[param: In]
		set;
	}

	[DispId(61)]
	public virtual extern object MarginHeader
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(61)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(62)]
	public virtual extern object MarginFooter
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(62)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(62)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(63)]
	public virtual extern object SpaceBefore
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(63)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(63)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(64)]
	public virtual extern object SpaceAfter
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(64)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(64)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(72)]
	public virtual extern ActionSettings Action
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(72)]
		[param: In]
		set;
	}

	[DispId(73)]
	public virtual extern DrawSettings Draw
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(73)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(74)]
	public virtual extern BrushStyleSettings BrushStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(74)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(74)]
		[param: In]
		set;
	}

	[DispId(75)]
	public virtual extern PenStyleSettings PenStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(75)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(75)]
		[param: In]
		set;
	}

	[DispId(76)]
	public virtual extern object PenWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(76)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(76)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(77)]
	public virtual extern object X1
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(77)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(77)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(78)]
	public virtual extern object Y1
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(78)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(78)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(79)]
	public virtual extern object X2
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(79)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(79)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(80)]
	public virtual extern object Y2
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(80)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(80)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(81)]
	public virtual extern string Polyline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(81)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(82)]
	public virtual extern string Polygon
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(82)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(88)]
	public virtual extern short PreviewPage
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(88)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(88)]
		[param: In]
		set;
	}

	[DispId(89)]
	public virtual extern short PreviewPages
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(89)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(90)]
	public virtual extern short PageCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(90)]
		get;
	}

	[DispId(91)]
	public virtual extern PageBorderSettings PageBorder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(91)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(91)]
		[param: In]
		set;
	}

	[DispId(94)]
	public virtual extern string Header
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(94)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(94)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(95)]
	public virtual extern string Footer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(95)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(95)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("stdole.IFontDisp")]
	[DispId(96)]
	public virtual extern IFontDisp HdrFont
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(96)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IFontDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(96)]
		[param: In]
		[param: ComAliasName("stdole.IFontDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(97)]
	public virtual extern string HdrFontName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(97)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(97)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(98)]
	public virtual extern float HdrFontSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(98)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(98)]
		[param: In]
		set;
	}

	[DispId(99)]
	public virtual extern bool HdrFontBold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(99)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(99)]
		[param: In]
		set;
	}

	[DispId(100)]
	public virtual extern bool HdrFontItalic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(100)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(101)]
	public virtual extern bool HdrFontStrikethru
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(101)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(101)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(102)]
	public virtual extern bool HdrFontUnderline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(102)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(0)]
	public virtual extern string Paragraph
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(105)]
	public virtual extern string Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(105)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(106)]
	public virtual extern object CurrentX
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(106)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(106)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(107)]
	public virtual extern object CurrentY
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(107)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(107)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(108)]
	public virtual extern TextAlignSettings TextAlign
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(108)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(108)]
		[param: In]
		set;
	}

	[DispId(109)]
	public virtual extern short TextAngle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(109)]
		[TypeLibFunc(1024)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(109)]
		[param: In]
		set;
	}

	[DispId(111)]
	public virtual extern short ZoomMax
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
	public virtual extern short ZoomMin
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(112)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(112)]
		[param: In]
		set;
	}

	[DispId(113)]
	public virtual extern short ZoomStep
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(113)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(113)]
		[param: In]
		set;
	}

	[DispId(116)]
	public virtual extern object ArchiveInfo
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(116)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(117)]
	public virtual extern short CurrentPage
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(117)]
		get;
	}

	[DispId(118)]
	public virtual extern short CurrentColumn
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(118)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(118)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(119)]
	public virtual extern short CurrentLine
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
	public virtual extern double TwipsPerPixelX
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(120)]
		get;
	}

	[DispId(121)]
	public virtual extern double TwipsPerPixelY
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(121)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(122)]
	public virtual extern int RenderControl
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(122)]
		[TypeLibFunc(1024)]
		[param: In]
		set;
	}

	[DispId(125)]
	public virtual extern int hDC
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(125)]
		get;
	}

	[DispId(126)]
	public virtual extern bool Preview
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(126)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(126)]
		[param: In]
		set;
	}

	[DispId(129)]
	public virtual extern bool AutoRTF
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(129)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(129)]
		[param: In]
		set;
	}

	[DispId(130)]
	public virtual extern string TextRTF
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(130)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(131)]
	public virtual extern string TableSep
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(131)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(131)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(132)]
	public virtual extern TableBorderSettings TableBorder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(132)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(132)]
		[param: In]
		set;
	}

	[DispId(133)]
	public virtual extern string Table
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(133)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(135)]
	public virtual extern string Measure
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(135)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(136)]
	public virtual extern double TextWidth
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(136)]
		get;
	}

	[DispId(137)]
	public virtual extern double TextHeight
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(137)]
		get;
	}

	[DispId(138)]
	public virtual extern bool Measuring
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(138)]
		get;
	}

	[DispId(139)]
	public virtual extern double TextWid
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(139)]
		get;
	}

	[DispId(140)]
	public virtual extern double TextHei
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(140)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(141)]
	public virtual extern string CalcParagraph
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(141)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(142)]
	[ComAliasName("stdole.IPictureDisp")]
	public virtual extern IPictureDisp CalcPicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(142)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(143)]
	public virtual extern string CalcTable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(143)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(144)]
	public virtual extern string CalcText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(144)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(145)]
	public virtual extern string CalcTextRTF
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(145)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(147)]
	public virtual extern string FileName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(147)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(147)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(148)]
	public virtual extern string AbortCaption
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(148)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(148)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(149)]
	public virtual extern string AbortTextButton
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(149)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(149)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(150)]
	public virtual extern string AbortTextDevice
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(150)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(150)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(151)]
	public virtual extern string AbortTextPage
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(151)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(151)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(152)]
	public virtual extern bool AbortWindow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(152)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(152)]
		[param: In]
		set;
	}

	[DispId(153)]
	public virtual extern AbortWindowPosSettings AbortWindowPos
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(153)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(153)]
		[param: In]
		set;
	}

	[DispId(154)]
	public virtual extern short DPI
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(154)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(155)]
	public virtual extern object TablePen
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(155)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(155)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(156)]
	public virtual extern object TablePenLR
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(156)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(156)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(157)]
	public virtual extern object TablePenTB
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(157)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(157)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(161)]
	public virtual extern object TableCell
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(161)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(161)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(162)]
	public virtual extern string OutputFileName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(162)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(162)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(163)]
	public virtual extern PrinterErrorSettings Error
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(163)]
		get;
	}

	[DispId(164)]
	public virtual extern ZoomModeSettings ZoomMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(164)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(164)]
		[param: In]
		set;
	}

	[DispId(166)]
	public virtual extern string DocName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(166)]
		[TypeLibFunc(1024)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(166)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(170)]
	[ComAliasName("stdole.IPictureDisp")]
	public virtual extern IPictureDisp PalettePicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(170)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(170)]
		[param: In]
		[param: ComAliasName("stdole.IPictureDisp")]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(171)]
	public virtual extern NavBarSettings NavBar
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(171)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(171)]
		[param: In]
		set;
	}

	[DispId(172)]
	public virtual extern string NavBarText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(172)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(172)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(173)]
	[ComAliasName("stdole.OLE_COLOR")]
	public virtual extern uint NavBarColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(173)]
		[return: ComAliasName("stdole.OLE_COLOR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(173)]
		[param: In]
		[param: ComAliasName("stdole.OLE_COLOR")]
		set;
	}

	[DispId(174)]
	public virtual extern string ExportFile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(174)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(174)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(175)]
	public virtual extern ExportFormatSettings ExportFormat
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(175)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(175)]
		[param: In]
		set;
	}

	[DispId(176)]
	public virtual extern string ExportRaw
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(176)]
		[TypeLibFunc(1024)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(177)]
	public virtual extern string ExportNavBar
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(177)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(177)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(178)]
	public virtual extern ReadyStateSettings ReadyState
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(178)]
		get;
	}

	[DispId(179)]
	public virtual extern string ErrorDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(179)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(180)]
	public virtual extern string URL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(180)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(180)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(181)]
	public virtual extern NavigationSettings Navigation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(181)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(181)]
		[param: In]
		set;
	}

	[DispId(184)]
	public virtual extern VSPrinterStyle Styles
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(184)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(185)]
	public virtual extern int FindText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(185)]
		[TypeLibFunc(1024)]
		get;
	}

	[DispId(186)]
	public virtual extern string RetrieveText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(186)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(187)]
	public virtual extern int FindTag
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(187)]
		get;
	}

	[DispId(188)]
	public virtual extern string RetrieveTag
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[TypeLibFunc(1024)]
		[DispId(188)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(192)]
	public virtual extern string NavBarMenuText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(192)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(192)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(193)]
	[ComAliasName("stdole.IPictureDisp")]
	public virtual extern IPictureDisp LoadPicture
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(193)]
		[return: MarshalAs(UnmanagedType.Interface)]
		[return: ComAliasName("stdole.IPictureDisp")]
		get;
	}

	[DispId(194)]
	public virtual extern bool AutoLinkNavigate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(194)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(194)]
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

	public virtual extern event _IVSPrinterEvents_ClickEventHandler Click;

	public virtual extern event _IVSPrinterEvents_DblClickEventHandler DblClick;

	public virtual extern event _IVSPrinterEvents_MouseDownEventHandler MouseDown;

	public virtual extern event _IVSPrinterEvents_MouseMoveEventHandler MouseMove;

	public virtual extern event _IVSPrinterEvents_MouseUpEventHandler MouseUp;

	public virtual extern event _IVSPrinterEvents_KeyDownEventHandler KeyDown;

	public virtual extern event _IVSPrinterEvents_KeyPressEventHandler KeyPress;

	public virtual extern event _IVSPrinterEvents_KeyUpEventHandler KeyUp;

	public virtual extern event _IVSPrinterEvents_StartDocEventHandler _IVSPrinterEvents_Event_StartDoc;

	public virtual extern event _IVSPrinterEvents_NewLineEventHandler NewLine;

	public virtual extern event _IVSPrinterEvents_NewColumnEventHandler _IVSPrinterEvents_Event_NewColumn;

	public virtual extern event _IVSPrinterEvents_NewPageEventHandler _IVSPrinterEvents_Event_NewPage;

	public virtual extern event _IVSPrinterEvents_EndPageEventHandler EndPage;

	public virtual extern event _IVSPrinterEvents_EndDocEventHandler _IVSPrinterEvents_Event_EndDoc;

	public virtual extern event _IVSPrinterEvents_ErrorEventHandler _IVSPrinterEvents_Event_Error;

	public virtual extern event _IVSPrinterEvents_ResetDCEventHandler ResetDC;

	public virtual extern event _IVSPrinterEvents_SavingDocEventHandler SavingDoc;

	public virtual extern event _IVSPrinterEvents_LoadingDocEventHandler LoadingDoc;

	public virtual extern event _IVSPrinterEvents_BeforeHeaderEventHandler BeforeHeader;

	public virtual extern event _IVSPrinterEvents_BeforeFooterEventHandler BeforeFooter;

	public virtual extern event _IVSPrinterEvents_AfterHeaderEventHandler AfterHeader;

	public virtual extern event _IVSPrinterEvents_AfterFooterEventHandler AfterFooter;

	public virtual extern event _IVSPrinterEvents_ReadyStateChangeEventHandler ReadyStateChange;

	public virtual extern event _IVSPrinterEvents_BeforeUserZoomEventHandler BeforeUserZoom;

	public virtual extern event _IVSPrinterEvents_AfterUserZoomEventHandler AfterUserZoom;

	public virtual extern event _IVSPrinterEvents_BeforeUserPageEventHandler BeforeUserPage;

	public virtual extern event _IVSPrinterEvents_AfterUserPageEventHandler AfterUserPage;

	public virtual extern event _IVSPrinterEvents_BeforeUserScrollEventHandler BeforeUserScroll;

	public virtual extern event _IVSPrinterEvents_AfterUserScrollEventHandler AfterUserScroll;

	public virtual extern event _IVSPrinterEvents_BeforeTableCellEventHandler BeforeTableCell;

	public virtual extern event _IVSPrinterEvents_AfterTableCellEventHandler AfterTableCell;

	public virtual extern event _IVSPrinterEvents_LayoutThumbnailsEventHandler LayoutThumbnails;

	public virtual extern event _IVSPrinterEvents_MouseLinkEventHandler MouseLink;

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-552)]
	[TypeLibFunc(64)]
	public virtual extern void About();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-550)]
	public virtual extern void Refresh();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(-522)]
	public virtual extern void let_MouseIcon([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(-523)]
	public virtual extern void let_Picture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(-512)]
	public virtual extern void let_Font([In][ComAliasName("stdole.IFontDisp")][MarshalAs(UnmanagedType.Interface)] IFontDisp pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(65)]
	public virtual extern void StartDoc();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(66)]
	public virtual extern void EndDoc();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(67)]
	public virtual extern void KillDoc();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(68)]
	public virtual extern void NewPage();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(69)]
	public virtual extern void NewColumn();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(70)]
	public virtual extern void PrintDoc([Optional][MarshalAs(UnmanagedType.Struct)] object Choose, [Optional][MarshalAs(UnmanagedType.Struct)] object FromPage, [Optional][MarshalAs(UnmanagedType.Struct)] object ToPage);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(71)]
	public virtual extern void PrintFile([MarshalAs(UnmanagedType.BStr)] string FileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(83)]
	public virtual extern void DrawLine([MarshalAs(UnmanagedType.Struct)] object X1, [MarshalAs(UnmanagedType.Struct)] object Y1, [Optional][MarshalAs(UnmanagedType.Struct)] object X2, [Optional][MarshalAs(UnmanagedType.Struct)] object Y2);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(84)]
	public virtual extern void DrawRectangle([MarshalAs(UnmanagedType.Struct)] object X1, [MarshalAs(UnmanagedType.Struct)] object Y1, [MarshalAs(UnmanagedType.Struct)] object X2, [MarshalAs(UnmanagedType.Struct)] object Y2, [Optional][MarshalAs(UnmanagedType.Struct)] object Radius1, [Optional][MarshalAs(UnmanagedType.Struct)] object Radius2);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(85)]
	public virtual extern void DrawCircle([MarshalAs(UnmanagedType.Struct)] object CenterX, [MarshalAs(UnmanagedType.Struct)] object CenterY, [MarshalAs(UnmanagedType.Struct)] object Radius, [Optional][MarshalAs(UnmanagedType.Struct)] object Start, [Optional][MarshalAs(UnmanagedType.Struct)] object End);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(86)]
	public virtual extern void DrawEllipse([MarshalAs(UnmanagedType.Struct)] object X1, [MarshalAs(UnmanagedType.Struct)] object Y1, [MarshalAs(UnmanagedType.Struct)] object X2, [MarshalAs(UnmanagedType.Struct)] object Y2, [Optional][MarshalAs(UnmanagedType.Struct)] object Start, [Optional][MarshalAs(UnmanagedType.Struct)] object End);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(87)]
	public virtual extern void DrawPicture([ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp Picture, [MarshalAs(UnmanagedType.Struct)] object Left, [MarshalAs(UnmanagedType.Struct)] object Top, [Optional][MarshalAs(UnmanagedType.Struct)] object Width, [Optional][MarshalAs(UnmanagedType.Struct)] object Height, [Optional][MarshalAs(UnmanagedType.Struct)] object Align, [Optional][MarshalAs(UnmanagedType.Struct)] object Shade);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(92)]
	public virtual extern void ClientToPage(ref float X, ref float Y, [Optional][MarshalAs(UnmanagedType.Struct)] ref object Page);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(93)]
	public virtual extern void PageToClient(ref float X, ref float Y);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(96)]
	public virtual extern void let_HdrFont([In][ComAliasName("stdole.IFontDisp")][MarshalAs(UnmanagedType.Interface)] IFontDisp pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(103)]
	public virtual extern void TextBox([MarshalAs(UnmanagedType.BStr)] string Text, [MarshalAs(UnmanagedType.Struct)] object X, [MarshalAs(UnmanagedType.Struct)] object Y, [MarshalAs(UnmanagedType.Struct)] object Width, [MarshalAs(UnmanagedType.Struct)] object Height, [Optional][MarshalAs(UnmanagedType.Struct)] object Wrap, [Optional][MarshalAs(UnmanagedType.Struct)] object Calc, [Optional][MarshalAs(UnmanagedType.Struct)] object Shade);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(115)]
	public virtual extern void Archive([MarshalAs(UnmanagedType.BStr)] string arcFileName, [MarshalAs(UnmanagedType.BStr)] string FileName, ArchiveSettings Action);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(123)]
	public virtual extern void SaveDoc([MarshalAs(UnmanagedType.BStr)] string FileName, [Optional][MarshalAs(UnmanagedType.Struct)] object Compress, [Optional][MarshalAs(UnmanagedType.Struct)] object FromPage, [Optional][MarshalAs(UnmanagedType.Struct)] object ToPage);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(124)]
	public virtual extern void LoadDoc([MarshalAs(UnmanagedType.BStr)] string FileName, [Optional][MarshalAs(UnmanagedType.Struct)] object Append);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(127)]
	public virtual extern void StartOverlay(short Page, [Optional][MarshalAs(UnmanagedType.Struct)] object Preserve);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(128)]
	public virtual extern void EndOverlay();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(134)]
	public virtual extern void AddTable([MarshalAs(UnmanagedType.BStr)] string Format, [MarshalAs(UnmanagedType.BStr)] string Header, [MarshalAs(UnmanagedType.BStr)] string Body, [Optional][MarshalAs(UnmanagedType.Struct)] object HeaderShade, [Optional][MarshalAs(UnmanagedType.Struct)] object BodyShade, [Optional][MarshalAs(UnmanagedType.Struct)] object Append);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(142)]
	[TypeLibFunc(1024)]
	public virtual extern void let_CalcPicture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp P_0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(146)]
	public virtual extern int PrintDialog(PrintDialogSettings DialogType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(158)]
	public virtual extern void AddTableArray([MarshalAs(UnmanagedType.BStr)] string Format, [MarshalAs(UnmanagedType.BStr)] string Header, [MarshalAs(UnmanagedType.Struct)] object Body, [Optional][MarshalAs(UnmanagedType.Struct)] object HeaderShade, [Optional][MarshalAs(UnmanagedType.Struct)] object BodyShade, [Optional][MarshalAs(UnmanagedType.Struct)] object Append);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(159)]
	public virtual extern void StartTable();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(160)]
	public virtual extern void EndTable();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(161)]
	[TypeLibFunc(1024)]
	public virtual extern void let_TableCell(TableCellSettings Setting, [Optional][MarshalAs(UnmanagedType.Struct)] object Row1, [Optional][MarshalAs(UnmanagedType.Struct)] object Col1, [Optional][MarshalAs(UnmanagedType.Struct)] object Row2, [Optional][MarshalAs(UnmanagedType.Struct)] object Col2, [In][MarshalAs(UnmanagedType.Struct)] object pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(165)]
	public virtual extern void GetMargins();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[SpecialName]
	[DispId(170)]
	public virtual extern void let_PalettePicture([In][ComAliasName("stdole.IPictureDisp")][MarshalAs(UnmanagedType.Interface)] IPictureDisp pVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(182)]
	public virtual extern void Clear();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(183)]
	public virtual extern void ScrollIntoView([MarshalAs(UnmanagedType.Struct)] object Left, [MarshalAs(UnmanagedType.Struct)] object Top, [Optional][MarshalAs(UnmanagedType.Struct)] object Right, [Optional][MarshalAs(UnmanagedType.Struct)] object Bottom);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(189)]
	public virtual extern void StartTag([MarshalAs(UnmanagedType.BStr)] string Text, [Optional][MarshalAs(UnmanagedType.Struct)] object Left, [Optional][MarshalAs(UnmanagedType.Struct)] object Top, [Optional][MarshalAs(UnmanagedType.Struct)] object Right, [Optional][MarshalAs(UnmanagedType.Struct)] object Bottom);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(190)]
	public virtual extern void EndTag();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(191)]
	public virtual extern void MovePages(int First, int Last, bool bToFront);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(195)]
	public virtual extern void AddLink([MarshalAs(UnmanagedType.BStr)] string LinkText, [MarshalAs(UnmanagedType.BStr)] string LinkTarget, bool Formatted);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(196)]
	public virtual extern void AddLinkTarget([MarshalAs(UnmanagedType.BStr)] string TargetText, [MarshalAs(UnmanagedType.BStr)] string TargetName);
}
[ComEventInterface(typeof(_IVSPrinterEvents\u0000), typeof(_IVSPrinterEvents_EventProvider\u0000))]
[ComVisible(false)]
[TypeLibType(16)]
public interface _IVSPrinterEvents_Event
{
	event _IVSPrinterEvents_ClickEventHandler Click;

	event _IVSPrinterEvents_DblClickEventHandler DblClick;

	event _IVSPrinterEvents_MouseDownEventHandler MouseDown;

	event _IVSPrinterEvents_MouseMoveEventHandler MouseMove;

	event _IVSPrinterEvents_MouseUpEventHandler MouseUp;

	event _IVSPrinterEvents_KeyDownEventHandler KeyDown;

	event _IVSPrinterEvents_KeyPressEventHandler KeyPress;

	event _IVSPrinterEvents_KeyUpEventHandler KeyUp;

	event _IVSPrinterEvents_StartDocEventHandler StartDoc;

	event _IVSPrinterEvents_NewLineEventHandler NewLine;

	event _IVSPrinterEvents_NewColumnEventHandler NewColumn;

	event _IVSPrinterEvents_NewPageEventHandler NewPage;

	event _IVSPrinterEvents_EndPageEventHandler EndPage;

	event _IVSPrinterEvents_EndDocEventHandler EndDoc;

	event _IVSPrinterEvents_ErrorEventHandler Error;

	event _IVSPrinterEvents_ResetDCEventHandler ResetDC;

	event _IVSPrinterEvents_SavingDocEventHandler SavingDoc;

	event _IVSPrinterEvents_LoadingDocEventHandler LoadingDoc;

	event _IVSPrinterEvents_BeforeHeaderEventHandler BeforeHeader;

	event _IVSPrinterEvents_BeforeFooterEventHandler BeforeFooter;

	event _IVSPrinterEvents_AfterHeaderEventHandler AfterHeader;

	event _IVSPrinterEvents_AfterFooterEventHandler AfterFooter;

	event _IVSPrinterEvents_ReadyStateChangeEventHandler ReadyStateChange;

	event _IVSPrinterEvents_BeforeUserZoomEventHandler BeforeUserZoom;

	event _IVSPrinterEvents_AfterUserZoomEventHandler AfterUserZoom;

	event _IVSPrinterEvents_BeforeUserPageEventHandler BeforeUserPage;

	event _IVSPrinterEvents_AfterUserPageEventHandler AfterUserPage;

	event _IVSPrinterEvents_BeforeUserScrollEventHandler BeforeUserScroll;

	event _IVSPrinterEvents_AfterUserScrollEventHandler AfterUserScroll;

	event _IVSPrinterEvents_BeforeTableCellEventHandler BeforeTableCell;

	event _IVSPrinterEvents_AfterTableCellEventHandler AfterTableCell;

	event _IVSPrinterEvents_LayoutThumbnailsEventHandler LayoutThumbnails;

	event _IVSPrinterEvents_MouseLinkEventHandler MouseLink;
}
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSPrinterEvents_ClickEventHandler();
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_DblClickEventHandler();
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_MouseDownEventHandler(short Button, short Shift, float X, float Y);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_MouseMoveEventHandler(short Button, short Shift, float X, float Y);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSPrinterEvents_MouseUpEventHandler(short Button, short Shift, float X, float Y);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSPrinterEvents_KeyDownEventHandler([In][Out] ref short KeyCode, short Shift);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_KeyPressEventHandler([In][Out] ref short KeyAscii);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_KeyUpEventHandler([In][Out] ref short KeyCode, short Shift);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_StartDocEventHandler();
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_NewLineEventHandler();
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSPrinterEvents_NewColumnEventHandler();
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_NewPageEventHandler();
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_EndPageEventHandler();
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSPrinterEvents_EndDocEventHandler();
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSPrinterEvents_ErrorEventHandler();
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_ResetDCEventHandler();
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSPrinterEvents_SavingDocEventHandler(short Page, short Of, [In][Out] ref bool Cancel);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_LoadingDocEventHandler(short Page, short Of, [In][Out] ref bool Cancel);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSPrinterEvents_BeforeHeaderEventHandler();
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_BeforeFooterEventHandler();
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSPrinterEvents_AfterHeaderEventHandler();
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_AfterFooterEventHandler();
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSPrinterEvents_ReadyStateChangeEventHandler(int ReadyState);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_BeforeUserZoomEventHandler([In][Out] ref short NewZoom);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSPrinterEvents_AfterUserZoomEventHandler();
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_BeforeUserPageEventHandler([In][Out] ref short NewPage);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_AfterUserPageEventHandler();
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSPrinterEvents_BeforeUserScrollEventHandler([In][Out] ref bool Cancel);
[TypeLibType(16)]
[ComVisible(false)]
public delegate void _IVSPrinterEvents_AfterUserScrollEventHandler();
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_BeforeTableCellEventHandler(int Row, int Col, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string Text, [In][Out] ref bool KeepFiring);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_AfterTableCellEventHandler(int Row, int Col, double Left, double Top, double Right, double Bottom, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string Text, [In][Out] ref bool KeepFiring);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_LayoutThumbnailsEventHandler([In][Out] ref short PagesX);
[ComVisible(false)]
[TypeLibType(16)]
public delegate void _IVSPrinterEvents_MouseLinkEventHandler([MarshalAs(UnmanagedType.BStr)] ref string Link, bool Clicked, [In][Out] ref short Cancel);
[ComImport]
[CoClass(typeof(VSPrinterClass))]
[Guid("B19E69FD-F3CC-41C9-BB01-F5F6AEF3243B")]
public interface VSPrinter : IVSPrinter, _IVSPrinterEvents_Event
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("3FF69F86-5AEB-479F-ADBB-BE01F08C2C13")]
public class VSPrinterStyleClass : IVSPrinterStyle, VSPrinterStyle
{
	[DispId(2)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		get;
	}

	[DispId(6)]
	public virtual extern string Key
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(7)]
	public virtual extern StyleFlagsSettings Flags
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(7)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	public virtual extern void Clear();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	public virtual extern void Add([MarshalAs(UnmanagedType.BStr)] string Key, StyleFlagsSettings Flags);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	public virtual extern void Remove([MarshalAs(UnmanagedType.Struct)] object Index);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	public virtual extern void Apply([MarshalAs(UnmanagedType.Struct)] object Index);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(8)]
	public virtual extern void Save([MarshalAs(UnmanagedType.BStr)] string FileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(9)]
	public virtual extern void Load([MarshalAs(UnmanagedType.BStr)] string FileName);
}
[ComImport]
[CoClass(typeof(VSPrinterStyleClass))]
[Guid("1D433C63-E7F0-43EB-960D-B1BF82B5FE1E")]
public interface VSPrinterStyle : IVSPrinterStyle
{
}
[TypeLibType(TypeLibTypeFlags.FHidden)]
[ClassInterface(ClassInterfaceType.None)]
public sealed class _IVSPrinterEvents_SinkHelper : _IVSPrinterEvents
{
	public _IVSPrinterEvents_MouseLinkEventHandler m_MouseLinkDelegate;

	public _IVSPrinterEvents_ClickEventHandler m_ClickDelegate;

	public _IVSPrinterEvents_DblClickEventHandler m_DblClickDelegate;

	public _IVSPrinterEvents_MouseDownEventHandler m_MouseDownDelegate;

	public _IVSPrinterEvents_MouseMoveEventHandler m_MouseMoveDelegate;

	public _IVSPrinterEvents_MouseUpEventHandler m_MouseUpDelegate;

	public _IVSPrinterEvents_KeyDownEventHandler m_KeyDownDelegate;

	public _IVSPrinterEvents_KeyPressEventHandler m_KeyPressDelegate;

	public _IVSPrinterEvents_KeyUpEventHandler m_KeyUpDelegate;

	public _IVSPrinterEvents_StartDocEventHandler m_StartDocDelegate;

	public _IVSPrinterEvents_NewLineEventHandler m_NewLineDelegate;

	public _IVSPrinterEvents_NewColumnEventHandler m_NewColumnDelegate;

	public _IVSPrinterEvents_NewPageEventHandler m_NewPageDelegate;

	public _IVSPrinterEvents_EndPageEventHandler m_EndPageDelegate;

	public _IVSPrinterEvents_EndDocEventHandler m_EndDocDelegate;

	public _IVSPrinterEvents_ErrorEventHandler m_ErrorDelegate;

	public _IVSPrinterEvents_ResetDCEventHandler m_ResetDCDelegate;

	public _IVSPrinterEvents_SavingDocEventHandler m_SavingDocDelegate;

	public _IVSPrinterEvents_LoadingDocEventHandler m_LoadingDocDelegate;

	public _IVSPrinterEvents_BeforeHeaderEventHandler m_BeforeHeaderDelegate;

	public _IVSPrinterEvents_BeforeFooterEventHandler m_BeforeFooterDelegate;

	public _IVSPrinterEvents_AfterHeaderEventHandler m_AfterHeaderDelegate;

	public _IVSPrinterEvents_AfterFooterEventHandler m_AfterFooterDelegate;

	public _IVSPrinterEvents_ReadyStateChangeEventHandler m_ReadyStateChangeDelegate;

	public _IVSPrinterEvents_BeforeUserZoomEventHandler m_BeforeUserZoomDelegate;

	public _IVSPrinterEvents_AfterUserZoomEventHandler m_AfterUserZoomDelegate;

	public _IVSPrinterEvents_BeforeUserPageEventHandler m_BeforeUserPageDelegate;

	public _IVSPrinterEvents_AfterUserPageEventHandler m_AfterUserPageDelegate;

	public _IVSPrinterEvents_BeforeUserScrollEventHandler m_BeforeUserScrollDelegate;

	public _IVSPrinterEvents_AfterUserScrollEventHandler m_AfterUserScrollDelegate;

	public _IVSPrinterEvents_BeforeTableCellEventHandler m_BeforeTableCellDelegate;

	public _IVSPrinterEvents_AfterTableCellEventHandler m_AfterTableCellDelegate;

	public _IVSPrinterEvents_LayoutThumbnailsEventHandler m_LayoutThumbnailsDelegate;

	public int m_dwCookie;

	public void MouseLink(ref string P_0, bool P_1, ref short P_2)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_MouseLinkDelegate != null)
		{
			m_MouseLinkDelegate(ref P_0, P_1, ref P_2);
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

	public void StartDoc()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_StartDocDelegate != null)
		{
			m_StartDocDelegate();
		}
	}

	public void NewLine()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_NewLineDelegate != null)
		{
			m_NewLineDelegate();
		}
	}

	public void NewColumn()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_NewColumnDelegate != null)
		{
			m_NewColumnDelegate();
		}
	}

	public void NewPage()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_NewPageDelegate != null)
		{
			m_NewPageDelegate();
		}
	}

	public void EndPage()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_EndPageDelegate != null)
		{
			m_EndPageDelegate();
		}
	}

	public void EndDoc()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_EndDocDelegate != null)
		{
			m_EndDocDelegate();
		}
	}

	public void Error()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_ErrorDelegate != null)
		{
			m_ErrorDelegate();
		}
	}

	public void ResetDC()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_ResetDCDelegate != null)
		{
			m_ResetDCDelegate();
		}
	}

	public void SavingDoc(short P_0, short P_1, ref bool P_2)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_SavingDocDelegate != null)
		{
			m_SavingDocDelegate(P_0, P_1, ref P_2);
		}
	}

	public void LoadingDoc(short P_0, short P_1, ref bool P_2)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_LoadingDocDelegate != null)
		{
			m_LoadingDocDelegate(P_0, P_1, ref P_2);
		}
	}

	public void BeforeHeader()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeHeaderDelegate != null)
		{
			m_BeforeHeaderDelegate();
		}
	}

	public void BeforeFooter()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeFooterDelegate != null)
		{
			m_BeforeFooterDelegate();
		}
	}

	public void AfterHeader()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterHeaderDelegate != null)
		{
			m_AfterHeaderDelegate();
		}
	}

	public void AfterFooter()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterFooterDelegate != null)
		{
			m_AfterFooterDelegate();
		}
	}

	public void ReadyStateChange(int P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_ReadyStateChangeDelegate != null)
		{
			m_ReadyStateChangeDelegate(P_0);
		}
	}

	public void BeforeUserZoom(ref short P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeUserZoomDelegate != null)
		{
			m_BeforeUserZoomDelegate(ref P_0);
		}
	}

	public void AfterUserZoom()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterUserZoomDelegate != null)
		{
			m_AfterUserZoomDelegate();
		}
	}

	public void BeforeUserPage(ref short P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeUserPageDelegate != null)
		{
			m_BeforeUserPageDelegate(ref P_0);
		}
	}

	public void AfterUserPage()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterUserPageDelegate != null)
		{
			m_AfterUserPageDelegate();
		}
	}

	public void BeforeUserScroll(ref bool P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeUserScrollDelegate != null)
		{
			m_BeforeUserScrollDelegate(ref P_0);
		}
	}

	public void AfterUserScroll()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterUserScrollDelegate != null)
		{
			m_AfterUserScrollDelegate();
		}
	}

	public void BeforeTableCell(int P_0, int P_1, ref string P_2, ref bool P_3)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_BeforeTableCellDelegate != null)
		{
			m_BeforeTableCellDelegate(P_0, P_1, ref P_2, ref P_3);
		}
	}

	public void AfterTableCell(int P_0, int P_1, double P_2, double P_3, double P_4, double P_5, ref string P_6, ref bool P_7)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_AfterTableCellDelegate != null)
		{
			m_AfterTableCellDelegate(P_0, P_1, P_2, P_3, P_4, P_5, ref P_6, ref P_7);
		}
	}

	public void LayoutThumbnails(ref short P_0)
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		if (m_LayoutThumbnailsDelegate != null)
		{
			m_LayoutThumbnailsDelegate(ref P_0);
		}
	}

	internal _IVSPrinterEvents_SinkHelper()
	{
		//Error decoding local variables: Signature type sequence must have at least one element.
		m_dwCookie = 0;
		m_MouseLinkDelegate = null;
		m_ClickDelegate = null;
		m_DblClickDelegate = null;
		m_MouseDownDelegate = null;
		m_MouseMoveDelegate = null;
		m_MouseUpDelegate = null;
		m_KeyDownDelegate = null;
		m_KeyPressDelegate = null;
		m_KeyUpDelegate = null;
		m_StartDocDelegate = null;
		m_NewLineDelegate = null;
		m_NewColumnDelegate = null;
		m_NewPageDelegate = null;
		m_EndPageDelegate = null;
		m_EndDocDelegate = null;
		m_ErrorDelegate = null;
		m_ResetDCDelegate = null;
		m_SavingDocDelegate = null;
		m_LoadingDocDelegate = null;
		m_BeforeHeaderDelegate = null;
		m_BeforeFooterDelegate = null;
		m_AfterHeaderDelegate = null;
		m_AfterFooterDelegate = null;
		m_ReadyStateChangeDelegate = null;
		m_BeforeUserZoomDelegate = null;
		m_AfterUserZoomDelegate = null;
		m_BeforeUserPageDelegate = null;
		m_AfterUserPageDelegate = null;
		m_BeforeUserScrollDelegate = null;
		m_AfterUserScrollDelegate = null;
		m_BeforeTableCellDelegate = null;
		m_AfterTableCellDelegate = null;
		m_LayoutThumbnailsDelegate = null;
	}
}
internal sealed class _IVSPrinterEvents_EventProvider : _IVSPrinterEvents_Event, IDisposable
{
	private IConnectionPointContainer m_ConnectionPointContainer;

	private ArrayList m_aEventSinkHelpers;

	private IConnectionPoint m_ConnectionPoint;

	private void Init()
	{
		IConnectionPoint ppCP = null;
		Guid riid = new Guid(new byte[16]
		{
			165, 239, 16, 88, 138, 116, 172, 71, 178, 191,
			201, 163, 166, 132, 78, 40
		});
		m_ConnectionPointContainer.FindConnectionPoint(ref riid, out ppCP);
		m_ConnectionPoint = ppCP;
		m_aEventSinkHelpers = new ArrayList();
	}

	public void add_MouseLink(_IVSPrinterEvents_MouseLinkEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_MouseLinkDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_MouseLink(_IVSPrinterEvents_MouseLinkEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_MouseLinkDelegate != null && ((iVSPrinterEvents_SinkHelper.m_MouseLinkDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_Click(_IVSPrinterEvents_ClickEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_ClickDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_Click(_IVSPrinterEvents_ClickEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_ClickDelegate != null && ((iVSPrinterEvents_SinkHelper.m_ClickDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_DblClick(_IVSPrinterEvents_DblClickEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_DblClickDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_DblClick(_IVSPrinterEvents_DblClickEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_DblClickDelegate != null && ((iVSPrinterEvents_SinkHelper.m_DblClickDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_MouseDown(_IVSPrinterEvents_MouseDownEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_MouseDownDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_MouseDown(_IVSPrinterEvents_MouseDownEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_MouseDownDelegate != null && ((iVSPrinterEvents_SinkHelper.m_MouseDownDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_MouseMove(_IVSPrinterEvents_MouseMoveEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_MouseMoveDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_MouseMove(_IVSPrinterEvents_MouseMoveEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_MouseMoveDelegate != null && ((iVSPrinterEvents_SinkHelper.m_MouseMoveDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_MouseUp(_IVSPrinterEvents_MouseUpEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_MouseUpDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_MouseUp(_IVSPrinterEvents_MouseUpEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_MouseUpDelegate != null && ((iVSPrinterEvents_SinkHelper.m_MouseUpDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_KeyDown(_IVSPrinterEvents_KeyDownEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_KeyDownDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_KeyDown(_IVSPrinterEvents_KeyDownEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_KeyDownDelegate != null && ((iVSPrinterEvents_SinkHelper.m_KeyDownDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_KeyPress(_IVSPrinterEvents_KeyPressEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_KeyPressDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_KeyPress(_IVSPrinterEvents_KeyPressEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_KeyPressDelegate != null && ((iVSPrinterEvents_SinkHelper.m_KeyPressDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_KeyUp(_IVSPrinterEvents_KeyUpEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_KeyUpDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_KeyUp(_IVSPrinterEvents_KeyUpEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_KeyUpDelegate != null && ((iVSPrinterEvents_SinkHelper.m_KeyUpDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_StartDoc(_IVSPrinterEvents_StartDocEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_StartDocDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_StartDoc(_IVSPrinterEvents_StartDocEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_StartDocDelegate != null && ((iVSPrinterEvents_SinkHelper.m_StartDocDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_NewLine(_IVSPrinterEvents_NewLineEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_NewLineDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_NewLine(_IVSPrinterEvents_NewLineEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_NewLineDelegate != null && ((iVSPrinterEvents_SinkHelper.m_NewLineDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_NewColumn(_IVSPrinterEvents_NewColumnEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_NewColumnDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_NewColumn(_IVSPrinterEvents_NewColumnEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_NewColumnDelegate != null && ((iVSPrinterEvents_SinkHelper.m_NewColumnDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_NewPage(_IVSPrinterEvents_NewPageEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_NewPageDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_NewPage(_IVSPrinterEvents_NewPageEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_NewPageDelegate != null && ((iVSPrinterEvents_SinkHelper.m_NewPageDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_EndPage(_IVSPrinterEvents_EndPageEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_EndPageDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_EndPage(_IVSPrinterEvents_EndPageEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_EndPageDelegate != null && ((iVSPrinterEvents_SinkHelper.m_EndPageDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_EndDoc(_IVSPrinterEvents_EndDocEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_EndDocDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_EndDoc(_IVSPrinterEvents_EndDocEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_EndDocDelegate != null && ((iVSPrinterEvents_SinkHelper.m_EndDocDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_Error(_IVSPrinterEvents_ErrorEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_ErrorDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_Error(_IVSPrinterEvents_ErrorEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_ErrorDelegate != null && ((iVSPrinterEvents_SinkHelper.m_ErrorDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_ResetDC(_IVSPrinterEvents_ResetDCEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_ResetDCDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_ResetDC(_IVSPrinterEvents_ResetDCEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_ResetDCDelegate != null && ((iVSPrinterEvents_SinkHelper.m_ResetDCDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_SavingDoc(_IVSPrinterEvents_SavingDocEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_SavingDocDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_SavingDoc(_IVSPrinterEvents_SavingDocEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_SavingDocDelegate != null && ((iVSPrinterEvents_SinkHelper.m_SavingDocDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_LoadingDoc(_IVSPrinterEvents_LoadingDocEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_LoadingDocDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_LoadingDoc(_IVSPrinterEvents_LoadingDocEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_LoadingDocDelegate != null && ((iVSPrinterEvents_SinkHelper.m_LoadingDocDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeHeader(_IVSPrinterEvents_BeforeHeaderEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_BeforeHeaderDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_BeforeHeader(_IVSPrinterEvents_BeforeHeaderEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_BeforeHeaderDelegate != null && ((iVSPrinterEvents_SinkHelper.m_BeforeHeaderDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeFooter(_IVSPrinterEvents_BeforeFooterEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_BeforeFooterDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_BeforeFooter(_IVSPrinterEvents_BeforeFooterEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_BeforeFooterDelegate != null && ((iVSPrinterEvents_SinkHelper.m_BeforeFooterDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterHeader(_IVSPrinterEvents_AfterHeaderEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_AfterHeaderDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_AfterHeader(_IVSPrinterEvents_AfterHeaderEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_AfterHeaderDelegate != null && ((iVSPrinterEvents_SinkHelper.m_AfterHeaderDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterFooter(_IVSPrinterEvents_AfterFooterEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_AfterFooterDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_AfterFooter(_IVSPrinterEvents_AfterFooterEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_AfterFooterDelegate != null && ((iVSPrinterEvents_SinkHelper.m_AfterFooterDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_ReadyStateChange(_IVSPrinterEvents_ReadyStateChangeEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_ReadyStateChangeDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_ReadyStateChange(_IVSPrinterEvents_ReadyStateChangeEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_ReadyStateChangeDelegate != null && ((iVSPrinterEvents_SinkHelper.m_ReadyStateChangeDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeUserZoom(_IVSPrinterEvents_BeforeUserZoomEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_BeforeUserZoomDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_BeforeUserZoom(_IVSPrinterEvents_BeforeUserZoomEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_BeforeUserZoomDelegate != null && ((iVSPrinterEvents_SinkHelper.m_BeforeUserZoomDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterUserZoom(_IVSPrinterEvents_AfterUserZoomEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_AfterUserZoomDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_AfterUserZoom(_IVSPrinterEvents_AfterUserZoomEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_AfterUserZoomDelegate != null && ((iVSPrinterEvents_SinkHelper.m_AfterUserZoomDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeUserPage(_IVSPrinterEvents_BeforeUserPageEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_BeforeUserPageDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_BeforeUserPage(_IVSPrinterEvents_BeforeUserPageEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_BeforeUserPageDelegate != null && ((iVSPrinterEvents_SinkHelper.m_BeforeUserPageDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterUserPage(_IVSPrinterEvents_AfterUserPageEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_AfterUserPageDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_AfterUserPage(_IVSPrinterEvents_AfterUserPageEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_AfterUserPageDelegate != null && ((iVSPrinterEvents_SinkHelper.m_AfterUserPageDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeUserScroll(_IVSPrinterEvents_BeforeUserScrollEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_BeforeUserScrollDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_BeforeUserScroll(_IVSPrinterEvents_BeforeUserScrollEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_BeforeUserScrollDelegate != null && ((iVSPrinterEvents_SinkHelper.m_BeforeUserScrollDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterUserScroll(_IVSPrinterEvents_AfterUserScrollEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_AfterUserScrollDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_AfterUserScroll(_IVSPrinterEvents_AfterUserScrollEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_AfterUserScrollDelegate != null && ((iVSPrinterEvents_SinkHelper.m_AfterUserScrollDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_BeforeTableCell(_IVSPrinterEvents_BeforeTableCellEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_BeforeTableCellDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_BeforeTableCell(_IVSPrinterEvents_BeforeTableCellEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_BeforeTableCellDelegate != null && ((iVSPrinterEvents_SinkHelper.m_BeforeTableCellDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_AfterTableCell(_IVSPrinterEvents_AfterTableCellEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_AfterTableCellDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_AfterTableCell(_IVSPrinterEvents_AfterTableCellEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_AfterTableCellDelegate != null && ((iVSPrinterEvents_SinkHelper.m_AfterTableCellDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public void add_LayoutThumbnails(_IVSPrinterEvents_LayoutThumbnailsEventHandler P_0)
	{
		Monitor.Enter(this);
		try
		{
			if (m_ConnectionPoint == null)
			{
				Init();
			}
			_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = new _IVSPrinterEvents_SinkHelper();
			int pdwCookie = 0;
			m_ConnectionPoint.Advise(iVSPrinterEvents_SinkHelper, out pdwCookie);
			iVSPrinterEvents_SinkHelper.m_dwCookie = pdwCookie;
			iVSPrinterEvents_SinkHelper.m_LayoutThumbnailsDelegate = P_0;
			m_aEventSinkHelpers.Add(iVSPrinterEvents_SinkHelper);
		}
		finally
		{
			Monitor.Exit(this);
		}
	}

	public void remove_LayoutThumbnails(_IVSPrinterEvents_LayoutThumbnailsEventHandler P_0)
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
				_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
				if (iVSPrinterEvents_SinkHelper.m_LayoutThumbnailsDelegate != null && ((iVSPrinterEvents_SinkHelper.m_LayoutThumbnailsDelegate.Equals(P_0) ? 1u : 0u) & 0xFFu) != 0)
				{
					m_aEventSinkHelpers.RemoveAt(num);
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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

	public _IVSPrinterEvents_EventProvider(object P_0)
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
					_IVSPrinterEvents_SinkHelper iVSPrinterEvents_SinkHelper = (_IVSPrinterEvents_SinkHelper)m_aEventSinkHelpers[num];
					m_ConnectionPoint.Unadvise(iVSPrinterEvents_SinkHelper.m_dwCookie);
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
