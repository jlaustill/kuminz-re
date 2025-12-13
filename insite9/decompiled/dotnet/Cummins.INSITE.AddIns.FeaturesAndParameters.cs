#define TRACE
using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Data;
using System.Data.Common;
using System.Data.OleDb;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Printing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Windows.Forms;
using ADDINFACTORYAPILib;
using APPLICATIONAPILib;
using C1.Win.C1FlexGrid;
using CGnD5VbQPNAYMkBriD;
using COLLECTIONLib;
using CONFIGSERVICELib;
using CONMANAPILib;
using CONMANEVENTSLib;
using CW4fPqkAuCM3Jii1sM;
using Cummins.INSITE.CNL.AddInFramework;
using Cummins.INSITE.CNL.AddInFramework.AddinControlInfoProvider;
using Cummins.INSITE.CNL.AddInFramework.Delegates;
using Cummins.INSITE.CNL.AddInFramework.Enums;
using Cummins.INSITE.CNL.Common;
using Cummins.INSITE.CNL.Events;
using Cummins.INSITE.CNL.Events.Proxies;
using Cummins.INSITE.CNL.Factory;
using Cummins.INSITE.CNL.FeaturesAndParametersDataOM;
using Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Classes;
using Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Enums;
using Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Interfaces;
using Cummins.INSITE.CNL.FeaturesAndParametersDataOM.Helper.Structures;
using Cummins.INSITE.CNL.Help;
using Cummins.INSITE.CNL.Localization;
using Cummins.INSITE.CNL.Security;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using Cummins.Insite.AddIns.FeaturesAndParameters;
using Cummins.Insite.AddIns.FeaturesAndParameters.Helper;
using Cummins.Insite.AddIns.FeaturesAndParameters.Model;
using Cummins.Insite.AddIns.FeaturesAndParameters.Model.Tooltip;
using Cummins.Insite.AddIns.FeaturesAndParameters.Presenter;
using Cummins.Insite.AddIns.FeaturesAndParameters.Resources;
using Cummins.Insite.AddIns.FeaturesAndParameters.View;
using DmTyxpPpKrTZcTxtUK;
using ECMSERVICESAPILib;
using FLEXGRIDHELPERLib;
using INFOSERVICEAPILib;
using Microsoft.Win32;
using Oi9MLENQ4D5oZ3VmRU;
using PRINTEDIMAGESAPILib;
using PaWVBLGVAj3mxwh9fZ;
using SHELLADDINAPILib;
using ToolSecurityServicesAPILib;
using VFwHZlTNZDkF9HsxXy;
using VSFlex8U;
using VSPrinter8Lib;
using VersionServiceLib;
using W9sDiGH2Jt9mSGDUMX;
using WjeZhbiQgYbsYgg8qV;
using aGJH07CLHmAAlye44W;
using dgnVOwLrooQc8bKdN9;
using e62y0ZIuxWPh3qxjyt;
using nj2wYj9KU7s8FDbKmD;
using wGKmsfvfCZmgDZNFek;
using zl7Cv8tqx0Tv1ehO8N;

[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyProduct("FeaturesAndParameters")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: CLSCompliant(true)]
[assembly: AssemblyDelaySign(false)]
[assembly: CompilationRelaxations(8)]
[assembly: Guid("ee5d5f7a-26e7-4d9a-97d1-366b0ea0ba0a")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: NeutralResourcesLanguage("en")]
[assembly: AssemblyTitle("FeaturesAndParameters")]
[assembly: ComVisible(true)]
[assembly: AssemblyVersion("7.6.0.272")]
namespace mbBL59VAmZN6OeqccL
{
	internal static class T5hJAHpipYsTHgI4FP
	{
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.View
{
	public interface IFnPView
	{
		int EditSelStart { get; }

		int CurrentColumn { get; set; }

		int CurrentRow { get; set; }

		string EditText { get; }

		IntPtr Handle { get; }

		int MouseColumn { get; }

		int MouseRow { get; }

		TooltipActiveState TooltipState { get; }

		GridProperties GridProperties { get; set; }

		int RowsCount { get; set; }

		AnchorStyles Anchor { set; }

		Cursor Cursor { set; }

		void AutoSizeRows();

		void AddItem(string item);

		void AddSystemName(string systemName);

		void AddModuleName(string moduleName);

		void AutoSizeCol(int colIndex);

		void AutoSizeCols();

		Rectangle GetCellRect(int row, int col);

		DialogResult DisplayMessage(string message, string caption, MessageBoxButtons buttons, MessageBoxIcon icon);

		void DisplayTooltip(int rowIndex, int columnIndex, string toolTipText);

		string GetFnPData();

		int GetParentRowIndex(int rowIndex);

		bool GetRowCollapse(int rowIndex);

		Node GetRowNode(int rowIndex);

		int GetRowOutlineLevel(int rowIndex);

		object GetValue(PropertyDescriptor propertyDescriptor, int rowIndex, int columnIndex);

		void HideTooltip();

		bool IsRowHidden(int rowIndex);

		bool IsVisible();

		void PrintGrid(PrintProperties printProperties);

		void PrintTo();

		void PutEditMask(int rowId, string editMask);

		void PutRedraw(bool redraw);

		void PutRowCollapse(int rowIndex, bool isRowCollapse);

		void PutRowHidden(int rowid, bool hide);

		void ResizeView();

		void SelectRow(int rowIndex);

		void SetComboDropdownList(string itemList, int rowid);

		void SetupView();

		void SetValue(PropertyDescriptor propertyDescriptor, int rowIndex, int colIndex, object value);

		void ShowPageSetupDialog();

		void ShowPrintPreviewDialog(PrintProperties printProperties);

		void EnableUI(bool enable);

		void SetGridColumnWidth();
	}
}
namespace Oi9MLENQ4D5oZ3VmRU
{
	internal sealed class yS2KTu37cDalfYYdDf : IFnPView
	{
		private int PsO5r6PwK;

		private IFlexGridHelper iISpEDchG;

		private ILocalizedStringProvider Fm5VhJAHi;

		private IVSFlexGrid aYs3THgI4;

		private VSPrinter GPPNbBL59;

		int IFnPView.EditSelStart
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return 0;
			}
		}

		int IFnPView.CurrentColumn
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(258));
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(348));
			}
		}

		int IFnPView.CurrentRow
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(438));
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(528));
			}
		}

		string IFnPView.EditText
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(888));
			}
		}

		IntPtr IFnPView.Handle
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(1068));
			}
		}

		int IFnPView.MouseColumn
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(1158));
			}
		}

		int IFnPView.MouseRow
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(1248));
			}
		}

		TooltipActiveState IFnPView.TooltipState
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(1698));
			}
		}

		GridProperties IFnPView.GridProperties
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(1878));
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(1968));
			}
		}

		int IFnPView.RowsCount
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return aYs3THgI4.Rows;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				aYs3THgI4.Rows = rows;
			}
		}

		AnchorStyles IFnPView.Anchor
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(2598));
			}
		}

		Cursor IFnPView.Cursor
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(2778));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public yS2KTu37cDalfYYdDf(VSPrinter P_0)
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
			iISpEDchG = new FlexGridHelperClass();
			Fm5VhJAHi = Factory.CreateInstance<ILocalizedStringProvider>();
			Fm5VhJAHi.Initialize(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(0));
			iISpEDchG.GetLicensedFlexGrid(out var pUnkVsFlexGrid);
			aYs3THgI4 = (IVSFlexGrid)pUnkVsFlexGrid;
			GPPNbBL59 = P_0;
			PsO5r6PwK = 1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AutoSizeRows()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AddItem(string P_0)
		{
			aYs3THgI4.OutlineBar = OutlineBarSettings.flexOutlineBarCompleteLeaf;
			aYs3THgI4.AddItem(P_0.TrimEnd(MeILRM8wWV0x9o1PR0.VE9ZA4chWi), PsO5r6PwK);
			aYs3THgI4.set_IsSubtotal(PsO5r6PwK, pVal: true);
			PsO5r6PwK++;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AddSystemName(string P_0)
		{
			aYs3THgI4.OutlineBar = OutlineBarSettings.flexOutlineBarCompleteLeaf;
			aYs3THgI4.AddItem(P_0.TrimEnd(MeILRM8wWV0x9o1PR0.VE9ZA4chWi), PsO5r6PwK);
			aYs3THgI4.set_IsSubtotal(PsO5r6PwK, pVal: true);
			PsO5r6PwK++;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AddModuleName(string P_0)
		{
			aYs3THgI4.OutlineBar = OutlineBarSettings.flexOutlineBarCompleteLeaf;
			aYs3THgI4.AddItem(P_0.TrimEnd(MeILRM8wWV0x9o1PR0.VE9ZA4chWi), PsO5r6PwK);
			aYs3THgI4.set_IsSubtotal(PsO5r6PwK, pVal: true);
			PsO5r6PwK++;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AutoSizeCol(int P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(78));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AutoSizeCols()
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(168));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		Rectangle IFnPView.GetCellRect(int P_0, int P_1)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(618));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		DialogResult IFnPView.DisplayMessage(string P_0, string P_1, MessageBoxButtons P_2, MessageBoxIcon P_3)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(708));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.DisplayTooltip(int P_0, int P_1, string P_2)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(798));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		string IFnPView.GetFnPData()
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(978));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		int IFnPView.GetParentRowIndex(int P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(1338));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPView.GetRowCollapse(int P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(1428));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		Node IFnPView.GetRowNode(int P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(1518));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		int IFnPView.GetRowOutlineLevel(int P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(1608));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		object IFnPView.GetValue(Cummins.Insite.AddIns.FeaturesAndParameters.PropertyDescriptor P_0, int P_1, int P_2)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(1788));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.HideTooltip()
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(2058));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPView.IsRowHidden(int P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(2148));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPView.IsVisible()
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(2238));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PrintGrid(PrintProperties P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(2328));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PrintTo()
		{
			aYs3THgI4.AutoSizeMode = AutoSizeSettings.flexAutoSizeRowHeight;
			aYs3THgI4.AutoSize(0, 0, false, 300);
			aYs3THgI4.AutoSizeMode = AutoSizeSettings.flexAutoSizeColWidth;
			aYs3THgI4.AutoSize(0, 0, false, 300);
			GPPNbBL59.RenderControl = aYs3THgI4.hWnd;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PutEditMask(int P_0, string P_1)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PutRedraw(bool P_0)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PutRowCollapse(int P_0, bool P_1)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PutRowHidden(int P_0, bool P_1)
		{
			aYs3THgI4.set_RowHidden(P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.ResizeView()
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(2418));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.SelectRow(int P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(2508));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.SetComboDropdownList(string P_0, int P_1)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(2688));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.SetupView()
		{
			string[] array = Fm5VhJAHi.GetLocalizedString(StringIdProvider.FeaturesAndParametersHeader).Split(new char[1] { '|' });
			aYs3THgI4.Cols = 3;
			aYs3THgI4.FixedRows = 1;
			aYs3THgI4.FixedCols = 0;
			aYs3THgI4.AutoSizeMode = AutoSizeSettings.flexAutoSizeRowHeight;
			aYs3THgI4.WordWrap = true;
			aYs3THgI4.set_ColWidth(0, Convert.ToInt32(6720.000000000001));
			aYs3THgI4.set_ColWidth(1, Convert.ToInt32(2040.0000000000002));
			aYs3THgI4.set_ColWidth(2, Convert.ToInt32(2040.0000000000002));
			aYs3THgI4.Row = 0;
			aYs3THgI4.Col = 0;
			aYs3THgI4.Text = array[0];
			aYs3THgI4.Row = 0;
			aYs3THgI4.Col = 1;
			aYs3THgI4.Text = array[1];
			aYs3THgI4.Row = 0;
			aYs3THgI4.Col = 2;
			aYs3THgI4.Text = array[2];
			aYs3THgI4.WordWrap = true;
			aYs3THgI4.set_ColAlignment(0, AlignmentSettings.flexAlignLeftBottom);
			aYs3THgI4.set_ColAlignment(1, AlignmentSettings.flexAlignLeftBottom);
			aYs3THgI4.set_ColAlignment(2, AlignmentSettings.flexAlignLeftBottom);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.SetValue(Cummins.Insite.AddIns.FeaturesAndParameters.PropertyDescriptor P_0, int P_1, int P_2, object P_3)
		{
			switch (P_0)
			{
			case Cummins.Insite.AddIns.FeaturesAndParameters.PropertyDescriptor.OutlineLevel:
				aYs3THgI4.set_RowOutlineLevel(P_1, Convert.ToInt16(P_3, CultureInfo.InvariantCulture));
				break;
			case Cummins.Insite.AddIns.FeaturesAndParameters.PropertyDescriptor.Picture:
			case Cummins.Insite.AddIns.FeaturesAndParameters.PropertyDescriptor.Value:
			case Cummins.Insite.AddIns.FeaturesAndParameters.PropertyDescriptor.Combolist:
				break;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.ShowPageSetupDialog()
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(2868));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.ShowPrintPreviewDialog(PrintProperties P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(2958));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.EnableUI(bool P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(3048));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.SetGridColumnWidth()
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(3138));
		}
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.Presenter
{
	[CLSCompliant(false)]
	public interface IFnPPrintPresenter
	{
		void CreateCSVFile(string imageFilePath, string csvFilePath, string headerInfo);

		void PrintImageInToolFormat(object kernel, string connetionId, VSPrinter printer, int featureID);

		string GetFnPDataInTextFormat(object kernel, string connetionId, int featureID);
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.Helper
{
	public static class NativeMethods
	{
		internal struct vOrETEDXiCV9UWxCsJ
		{
			public int tdDSfOi9M;

			public int qEQG4D5oZ;

			public int dVmZRUuOr;

			public int RTEbXiCV9;
		}

		[DllImport("user32.dll", CharSet = CharSet.Auto, EntryPoint = "GetParent", ExactSpelling = true)]
		internal static extern IntPtr AmZDN6Oeq(IntPtr P_0);

		[DllImport("user32.dll", EntryPoint = "SetParent", SetLastError = true)]
		internal static extern IntPtr scLdwS2KT(IntPtr P_0, IntPtr P_1);

		[DllImport("user32.dll", EntryPoint = "GetClientRect")]
		[return: MarshalAs(UnmanagedType.Bool)]
		internal static extern bool v7cHDalfY(IntPtr P_0, out vOrETEDXiCV9UWxCsJ P_1);
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters
{
	public enum LimitParameterType
	{
		None,
		Min,
		Max
	}
	public enum RowType
	{
		Unknown,
		System,
		Market,
		Feature,
		SubFeature,
		Parameter
	}
	public enum SecurityLevel
	{
		Basic,
		OBDRSGR,
		OBD,
		RSGR,
		RSGRPlus,
		Lite,
		IndustrialPro,
		Pro,
		ProPlus
	}
	public enum ECMPasswordType
	{
		None,
		Master,
		Adjustment,
		Reset,
		OEM,
		OEM2
	}
	public enum LogCategory
	{
		None,
		FnPAddIn,
		ECMDataReader,
		WriteDataHelper,
		FeatureExclusivityTooltip,
		LimitsTooltip,
		LockStateTooltip,
		StaticTooltip,
		TooltipDataReader,
		TooltipExpressionParser,
		TooltipProvider,
		FnPModel,
		FnPPresenter,
		FnPPrintPresenter,
		FnPTextPrintView,
		FnPToolPrintView,
		FnPViewControl,
		LimitsDialog
	}
	public enum LoggerOption
	{
		None,
		LogToDebugger,
		LogToFile,
		LogToConsole
	}
	public enum ContextMenuItem
	{
		Find,
		SendTo,
		SendToECM,
		SendToPrinter,
		Expand,
		Collapse,
		RestoreOriginalValue,
		RestoreAllOriginalValues,
		Refresh,
		RefreshAll,
		RefreshSelectedECM,
		RefreshSelectedECMForHeader,
		RefreshSelectedItem,
		Limits,
		ExpandAll,
		CollapseAll,
		AutoSizeColumn,
		AutoSizeAllColumns
	}
	public enum ContextMenuType
	{
		GridContextMenu,
		GridHeaderContextMenu
	}
	public enum PropertyDescriptor
	{
		Picture,
		Value,
		OutlineLevel,
		Combolist,
		FontBold
	}
	public enum ValidateLimit
	{
		WithinLimit,
		MinLimitExceeded,
		MaxLimitExceeded
	}
	public enum EngineType
	{
		None,
		Automotive,
		Industrial
	}
	public enum ConnectionType
	{
		None,
		Simulator,
		Image,
		Physical,
		PCLJ1939,
		PCLUDS
	}
	public enum TooltipActiveState
	{
		None,
		Persistent,
		ActiveHove
	}
	public enum IconState
	{
		DefaultUnselected,
		DefaultSelected,
		LockedUnselected,
		LockedSelected
	}
	public enum TooltipQueryType
	{
		None,
		LimitsTooltipQuery,
		LockstateTooltipQuery,
		InvalidvalueTooltipQuery
	}
	public enum LimitsTooltipType
	{
		None,
		MinLimit,
		MaxLimit
	}
	public enum NodeState
	{
		UnSelected,
		Selected
	}
	public enum GridColIndex
	{
		SystemModuleCol,
		ECMValueCol,
		UnitCol,
		OriginalValueCol
	}
	public enum UIState
	{
		NoConnection,
		Connected,
		Populated
	}
	public enum ConnectionStatus
	{
		ConnectionSuccessful = 1,
		ECMRomBooted,
		ECMSeeded,
		ECMFootprinted,
		CommunicationRestored
	}
	public enum FieldName
	{
		ParameterId,
		MinValue,
		MaxValue,
		DisplayName,
		DisplayValue,
		OriginalValue,
		DesireValue,
		Unit,
		EditType
	}
	public enum Limit
	{
		Min,
		Max
	}
	public enum TooltipDependencyType
	{
		MinValue,
		MaxValue,
		ReadOrWriteBlocked
	}
	public enum GridOutlineLevel
	{
		SystemOutlineLevel,
		ModuleOutlineLevel,
		FeatureOutlineLevel,
		SubFeatureOutlineLevel,
		ParameterOutlineLevel
	}
	public enum PrintFormat
	{
		None,
		Text,
		Tool
	}
	public enum GTISStateValue
	{
		None,
		StateGTISReadDiagnosticAccess,
		StateGTISDependentReadWrite,
		StateGTISDependentFullReadWrite
	}
	public enum StringIdProvider
	{
		None = 0,
		ViewBarName = 101,
		ViewBarTooltip = 102,
		FeaturesAndParametersHeader = 103,
		NoECMConnected = 106,
		ReadingData = 107,
		Refresh = 119,
		Expand = 120,
		Collapse = 121,
		ExpandAll = 123,
		CollapseAll = 124,
		ContinueFromBeginMessageCaption = 125,
		ContinueFromEndMessageCaption = 126,
		NoMatchFoundMessageCaption = 127,
		ContinueFromBeginMessage = 128,
		ContinueFromEndMessage = 129,
		NoMatchFoundMessage = 130,
		GridNameColumn = 169,
		GridUnitsColumn = 170,
		GridValueColumn = 171,
		GridOriginalValueColumn = 172,
		Find = 173,
		AutoSizeCol = 174,
		AutoSizeAllCols = 175,
		SendToECM = 176,
		SendToPrinter = 177,
		Limits = 178,
		RestoreOriginalValue = 179,
		RestoreAllOriginalValues = 180,
		RefreshAll = 181,
		RefreshItem = 182,
		RefreshECM = 183,
		SendTo = 184,
		MenuBarFindNext = 188,
		MenuBarRestoreAll = 189,
		ReadOnlyTooltip = 196,
		GenericBlockedTooltip = 198,
		ConnectedToECMImageTooltip = 199,
		SorryTitle = 201,
		BasicToolLevelTooltip = 206,
		UserRightsTooltip = 207,
		PasswordLockedTooltip = 208,
		SendChangesMessage = 209,
		InsiteTitle = 210,
		MaxLengthTooltip = 211,
		LimitsTitle = 212,
		LimitsParamGroup = 213,
		MaxLimitGroup = 214,
		MinLimitGroup = 215,
		ParameterMaxLimtMessage = 216,
		ParameterMinLimitMessage = 217,
		HelpButtonCaption = 219,
		RSGRLockedTooltip = 220,
		FeatureTooltipHeader = 221,
		ParameterTooltipHeader = 222,
		InvalidValueTooltipHeader = 223,
		WriteUnsuccessfulTitle = 224,
		WriteUnsuccessfulMessage = 225,
		WriteSuccessfulTitle = 226,
		WriteSuccessfulMessage = 227,
		WriteConfirmTitle = 228,
		WriteConfirmMessage = 229,
		EngineSpeedNotZero = 232,
		FeatureReadBlockedTooltip = 245,
		ParameterReadBlockedTooltip = 246,
		OEMLockedTooltip = 247,
		ResetPasswordLockedTooltip = 248,
		AlternateFuelingTableTitle = 249,
		AlternateFuelingTableMessage = 250,
		AutomotiveToolLevelTooltip = 251,
		LowToolLevelTooltip = 252,
		RestoreAllOriginalValuesTitle = 255,
		RestoreAllOriginalValuesMessage = 256,
		HPCRTooltip = 257,
		AirConditionerControlTooltip = 259,
		PulsePerDistanceTooltip = 260,
		ExpandedDroopInputEnableTooltip = 261,
		FeatureExclusivityTooltip = 266,
		EngineSpeedAccelManagementTooltip = 268,
		EGRValvePositionTooltip = 269,
		OEM2LockedTooltip = 270,
		FeatureMaxLimitMessage = 271,
		FeatureMinLimitMessage = 272,
		FeatureLimitsTitle = 273,
		SelectedFeature = 274,
		UserSelectableLockedTooltip = 275,
		TransmissionAcceleratorInterlockEnableTooltip = 279,
		CruiseControlAutoResumeEnableTooltip = 281,
		ExpandedDroopInputEnableVersion2ToolTip = 282,
		PrinterNotAvailableTitle = 283,
		PrinterNotAvailableMessage = 284,
		OtherDevices = 285,
		SmartDevicesUnavailableMessage = 286,
		EngineCoolantLevelShutdown = 287,
		InvalidDate = 288,
		ResetMissedOilValvePulsesTooltip = 289,
		NoOtherDevice = 290
	}
	public enum FindDialogButtons
	{
		Next = 1,
		Cancel
	}
	public enum FeatureId
	{
		All = -1,
		OtherSmartDevices = 552
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.Presenter
{
	public interface IPresenterEventPublisher
	{
		event EventHandler ToolBarStateRefreshRequested;

		event EventHandler MenuBarStateRefreshRequested;
	}
	public abstract class FnPPresenterBase
	{
		private int wWxsCsJJs;

		private IFnPView BxoPOZLuB;

		private Dictionary<int, Dictionary<int, List<int>>> cT1Warbh6;

		[CLSCompliant(false)]
		protected ILocalizedStringProvider _stringProvider;

		protected IFnPView FnpView
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return BxoPOZLuB;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				BxoPOZLuB = value;
			}
		}

		protected int NumberOfModules
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return wWxsCsJJs;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				wWxsCsJJs = value;
			}
		}

		protected Dictionary<int, Dictionary<int, List<int>>> ElementParameterIdMap
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return cT1Warbh6;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				cT1Warbh6 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected FnPPresenterBase()
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
			_stringProvider = Factory.CreateInstance<ILocalizedStringProvider>();
			_stringProvider.Initialize(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(3228));
			ElementParameterIdMap = null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void PopulateGrid(IFeaturesAndParametersDataOM fnpDataOM, int FeatureID)
		{
			if (fnpDataOM == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(3306), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(3426));
			}
			FnpView.PutRedraw(redraw: false);
			FnpView.RowsCount = 1;
			int num = 0;
			FnpView.AddSystemName(fnpDataOM.SystemName);
			FnpView.SetValue(PropertyDescriptor.OutlineLevel, FnpView.RowsCount - 1, 0, num);
			FnpView.SetValue(PropertyDescriptor.FontBold, FnpView.RowsCount - 1, 0, true);
			Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IModules modules = fnpDataOM.Modules;
			PopulateModules(modules, num + 1);
			if (FeatureID == -1 || FeatureID == 552)
			{
				PopulateSmartDevices(fnpDataOM.SmartDevices);
			}
			FnpView.PutRedraw(redraw: true);
			FnpView.AutoSizeRows();
		}

		protected abstract void PopulateSmartDevices(Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IModules smartDevices);

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void PopulateModules(Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IModules modules, int gridOutlineLevel)
		{
			if (modules == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(3448), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(3574));
			}
			NumberOfModules = 0;
			bool isMultiModule = modules.Count > 1;
			for (int i = 0; i < modules.Count; i++)
			{
				try
				{
					if (ElementParameterIdMap != null && !ElementParameterIdMap.ContainsKey(NumberOfModules))
					{
						ElementParameterIdMap.Add(NumberOfModules, new Dictionary<int, List<int>>());
					}
					Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IModule module = modules[i];
					PopulateModule(module, isMultiModule, gridOutlineLevel);
					NumberOfModules++;
				}
				catch (ArgumentException exception)
				{
					FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
				}
				catch (InvalidOperationException exception2)
				{
					FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
				}
			}
		}

		protected abstract bool CheckFnPElementLockState(IFnPElement element);

		protected abstract float GetPrecission(IFnPElement element, int moduleType);

		protected abstract void PopulateModule(Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IModule module, bool isMultiModule, int gridOutlineLevel);

		protected abstract void PopulateFeature(IFeature feature, int gridOutLineLevel);

		protected abstract void PopulateSubFeature(ISubFeature subFeature, int parentRow, int gridOutLineLevel);

		protected abstract void PopulateParameter(Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameter parameter, int gridOutLineLevel);

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void PopulateFeatures(IFeatures features, int gridOutlineLevel)
		{
			if (features == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(3592), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(3720));
			}
			for (int i = 0; i < features.Count; i++)
			{
				try
				{
					IFeature feature = features[i];
					if (feature != null && feature.Id > 0)
					{
						PopulateFeature(feature, gridOutlineLevel);
					}
				}
				catch (ArgumentException exception)
				{
					FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
				}
				catch (InvalidOperationException exception2)
				{
					FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void PopulateSubFeatures(ISubFeatures subFeatures, int parentRow, int gridOutLineLevel)
		{
			if (subFeatures == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(3740), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(3874));
			}
			for (int i = 0; i < subFeatures.Count; i++)
			{
				try
				{
					ISubFeature subFeature = subFeatures[i];
					PopulateSubFeature(subFeature, parentRow, gridOutLineLevel);
				}
				catch (ArgumentException exception)
				{
					FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
				}
				catch (InvalidOperationException exception2)
				{
					FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void PopulateParameters(Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameters parameters, int gridOutLineLevel)
		{
			if (parameters == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(3900), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4032));
			}
			for (int i = 0; i < parameters.Count; i++)
			{
				try
				{
					Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameter parameter = parameters[i];
					PopulateParameter(parameter, gridOutLineLevel);
				}
				catch (ArgumentException exception)
				{
					FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
				}
				catch (InvalidOperationException exception2)
				{
					FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
				}
			}
		}
	}
	[CLSCompliant(false)]
	public interface IFnPPresenter
	{
		bool IsECMConnectionInterrupted { get; set; }

		bool AllowDisconnect(int cookie);

		bool CanCloseFnP();

		bool CanPrint();

		void CollapseAll();

		void ConManRefresh();

		[CLSCompliant(false)]
		void ConnectionEstablished(string connectionId, ConnectionStatusEnum status, ECMSERVICESAPILib.IDisconnectCallback callback);

		void ConnectionTerminated(string connectionId);

		void ExpandAll();

		void Find();

		void FindNext();

		void GroupChanged(int groupNumber);

		void HandleDisconnect(int cookie);

		bool HasData();

		void LoadFindDialog();

		void PageSetUp();

		void PrepareView(int hwndParent);

		void Print();

		void PrintPreview();

		void ProcessViewMsg(int msg);

		void RefreshAll();

		void RefreshSelectedECM();

		void RestoreAllOriginalValues();

		void SendToECM();

		void ToolLevelChanged(string toolLevel);

		void HandleConnectionRestablished();
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.Model
{
	public interface IModelEventListener
	{
		void OnFeatureDataAvailable(object sender, EventArgs e);

		void OnErrorInFnPModel(object sender, EventArgs e);
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.View
{
	public interface IViewEventListener
	{
		void OnAfterCollapse(object sender, RowColEventArgs e);

		void OnAfterEdit(object sender, RowColEventArgs e);

		void OnAfterRowColChange(object sender, RangeEventArgs e);

		void OnBeforeCollapse(object sender, RowColEventArgs e);

		void OnBeforeEdit(object sender, RowColEventArgs e);

		void OnFnPViewLoaded(object sender, EventArgs e);

		void OnGridKeyPressEdit(object sender, KeyPressEditEventArgs e);

		void OnKeyDown(object sender, KeyEventArgs e);

		void OnKeyUp(object sender, KeyEventArgs e);

		void OnMouseDown(object sender, MouseEventArgs e);

		void OnMouseMove(object sender, MouseEventArgs e);

		void OnStartEdit(object sender, RowColEventArgs e);

		void OnValidateEdit(object sender, ValidateEditEventArgs e);
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.Presenter
{
	[Guid("BFF52F35-3CE7-35A1-867B-0DD040A07E03")]
	public sealed class FnPPresenter : FnPPresenterBase, IModelEventListener, IFnPPresenter, IViewEventListener, IDisposable, IPresenterEventPublisher
	{
		private bool dWnpYjQ8oZ;

		private WriteDataHelper KajpIplcST;

		private int LxppusUOl4;

		private int qqbpkInfT6;

		private UIState n5BpUAFLQd;

		private ConnectionType R9XpMIjBHc;

		private string yaipw9J3BE;

		private IFnPModel SS4phmddGR;

		private ManualResetEvent f9ipADcKnZ;

		private ManualResetEvent PwQpBrEhIB;

		private ContextMenuHelper VIapek5Ra3;

		private ContextMenuStrip OWxpQ6pSJO;

		private ContextMenuStrip IDhpKBhX27;

		private EventHandler nEipyErRXd;

		private EventHandler caEpJ8GPs8;

		private int ipZpFvNF2L;

		private int c8wpl5k3Qc;

		private int LL3pxtrScZ;

		private CommonFindDialog Jhbp0jg3fZ;

		private Timer GKMpgJXCAS;

		private bool f6Ep744kDM;

		private object ewMpqKX74K;

		private Dictionary<int, List<string>> or0p8F3Pdx;

		[CompilerGenerated]
		private bool c5Ipih9Of8;

		[CompilerGenerated]
		private bool RPZpjLTr4k;

		[CompilerGenerated]
		private bool dOHpOGqief;

		[CompilerGenerated]
		private bool Gu6pX8QWL8;

		[CompilerGenerated]
		private bool ovVpCsCi5D;

		[CompilerGenerated]
		private bool Qo7pEZFmDV;

		[CompilerGenerated]
		private Dictionary<int, RowInformation> SN1p1BnVwI;

		[CompilerGenerated]
		private SecurityLevel DwJpf6Lyf7;

		[CompilerGenerated]
		private ECMPasswordType QFnpm5mJbZ;

		[CompilerGenerated]
		private string zgIp4BLj5u;

		[CompilerGenerated]
		private int QOwp2PToMq;

		[CompilerGenerated]
		private int LQsp6OupFn;

		[CompilerGenerated]
		private Dictionary<int, int> Tq6pn4LJBF;

		public bool IsECMConnectionInterrupted
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return RPZpjLTr4k;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				RPZpjLTr4k = value;
			}
		}

		public bool IsOEMAvailable
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return dOHpOGqief;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				dOHpOGqief = value;
			}
		}

		public bool IsOEM2Available
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return Gu6pX8QWL8;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				Gu6pX8QWL8 = value;
			}
		}

		public bool IsConnectedToImage
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return ovVpCsCi5D;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				ovVpCsCi5D = value;
			}
		}

		public bool HasUserRights
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return Qo7pEZFmDV;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			private set
			{
				Qo7pEZFmDV = value;
			}
		}

		public Dictionary<int, RowInformation> ElementRowStructureMap
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return SN1p1BnVwI;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				SN1p1BnVwI = value;
			}
		}

		public SecurityLevel CurrentSecurityLevel
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return DwJpf6Lyf7;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				DwJpf6Lyf7 = value;
			}
		}

		public ECMPasswordType PasswordLevel
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return QFnpm5mJbZ;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				QFnpm5mJbZ = value;
			}
		}

		public string Seperator
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return zgIp4BLj5u;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				zgIp4BLj5u = value;
			}
		}

		public int ModuleType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return QOwp2PToMq;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				QOwp2PToMq = value;
			}
		}

		public int ParameterCounter
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return LQsp6OupFn;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				LQsp6OupFn = value;
			}
		}

		public Dictionary<int, int> ModuleIdParameterCountMap
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return Tq6pn4LJBF;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				Tq6pn4LJBF = value;
			}
		}

		private event EventHandler JHip9tOUTL
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler eventHandler = nEipyErRXd;
				EventHandler eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref nEipyErRXd, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler eventHandler = nEipyErRXd;
				EventHandler eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref nEipyErRXd, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		private event EventHandler iYQpT9gdBB
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler eventHandler = caEpJ8GPs8;
				EventHandler eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref caEpJ8GPs8, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler eventHandler = caEpJ8GPs8;
				EventHandler eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref caEpJ8GPs8, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		event EventHandler IPresenterEventPublisher.ToolBarStateRefreshRequested
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				JHip9tOUTL += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				JHip9tOUTL -= value;
			}
		}

		event EventHandler IPresenterEventPublisher.MenuBarStateRefreshRequested
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				iYQpT9gdBB += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				iYQpT9gdBB -= value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		[CompilerGenerated]
		private bool X5opZTMfOn()
		{
			return c5Ipih9Of8;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		[CompilerGenerated]
		private void XgApbm8i5Z(bool value)
		{
			c5Ipih9Of8 = value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CLSCompliant(false)]
		public FnPPresenter(IFnPModel fnpModel)
		{
			//IL_0082: Unknown result type (might be due to invalid IL or missing references)
			//IL_008c: Expected O, but got Unknown
			//IL_00a8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b2: Expected O, but got Unknown
			//IL_00b3: Unknown result type (might be due to invalid IL or missing references)
			//IL_00bd: Expected O, but got Unknown
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			dWnpYjQ8oZ = true;
			ewMpqKX74K = new object();
			base..ctor();
			ModuleIdParameterCountMap = new Dictionary<int, int>();
			SS4phmddGR = fnpModel;
			base.FnpView = null;
			n5BpUAFLQd = UIState.NoConnection;
			LL3pxtrScZ = -1;
			CurrentSecurityLevel = SecurityLevel.Basic;
			PasswordLevel = ECMPasswordType.None;
			ElementRowStructureMap = new Dictionary<int, RowInformation>();
			ParameterCounter = 0;
			KajpIplcST = new WriteDataHelper();
			Jhbp0jg3fZ = new CommonFindDialogClass();
			GKMpgJXCAS = new Timer();
			GKMpgJXCAS.Interval = 1000;
			VIapek5Ra3 = new ContextMenuHelper();
			IDhpKBhX27 = new ContextMenuStrip();
			OWxpQ6pSJO = new ContextMenuStrip();
			base.ElementParameterIdMap = new Dictionary<int, Dictionary<int, List<int>>>();
			IsECMConnectionInterrupted = false;
			oXaLWVBLV();
			XgApbm8i5Z(value: false);
			or0p8F3Pdx = null;
			qMw5eWV0x9();
			f9ipADcKnZ = new ManualResetEvent(initialState: true);
			PwQpBrEhIB = new ManualResetEvent(initialState: true);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Dispose()
		{
			Aj3cmxwh9();
			((Component)(object)GKMpgJXCAS).Dispose();
			((Component)(object)IDhpKBhX27).Dispose();
			((Component)(object)OWxpQ6pSJO).Dispose();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IModelEventListener.OnFeatureDataAvailable(object sender, EventArgs e)
		{
			f9ipADcKnZ.Set();
			PwQpBrEhIB.Set();
			if (n5BpUAFLQd == UIState.NoConnection)
			{
				return;
			}
			lock (ewMpqKX74K)
			{
				if (n5BpUAFLQd == UIState.NoConnection)
				{
					return;
				}
				try
				{
					base.FnpView.EnableUI(enable: false);
					if (!base.FnpView.IsVisible())
					{
						return;
					}
					base.FnpView.Cursor = Cursors.WaitCursor;
					kCR5sDeYyM();
					IFeaturesAndParametersDataOM fnPDataObject = SS4phmddGR.GetFnPDataObject();
					if (fnPDataObject != null)
					{
						if (n5BpUAFLQd != UIState.NoConnection)
						{
							PopulateGrid(fnPDataObject, -1);
						}
						n5BpUAFLQd = UIState.Populated;
						Twl55rds0w();
						w3y5pWBxpN();
					}
					base.FnpView.Cursor = Cursors.Default;
				}
				catch (ArgumentException exception)
				{
					FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
				}
				catch (InvalidOperationException exception2)
				{
					FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
				}
				finally
				{
					base.FnpView.EnableUI(enable: true);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IModelEventListener.OnErrorInFnPModel(object sender, EventArgs e)
		{
			f9ipADcKnZ.Set();
			PwQpBrEhIB.Set();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void PopulateModule(Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IModule module, bool isMultiModule, int gridOutlineLevel)
		{
			if (n5BpUAFLQd == UIState.NoConnection)
			{
				return;
			}
			if (module == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4056), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4180));
			}
			ParameterCounter = 0;
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(module.MarketName);
			ModuleType = module.DetectType;
			if (isMultiModule)
			{
				stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4196));
				stringBuilder.Append(module.SourceAddress.ToString(CultureInfo.InvariantCulture));
				stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4202));
				if (!string.IsNullOrEmpty(module.ServiceEcmMarketingName))
				{
					stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4208));
					stringBuilder.Append(module.ServiceEcmMarketingName);
					stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4214));
				}
			}
			base.FnpView.AddModuleName(stringBuilder.ToString());
			base.FnpView.SetValue(PropertyDescriptor.OutlineLevel, base.FnpView.RowsCount - 1, 0, gridOutlineLevel);
			base.FnpView.SetValue(PropertyDescriptor.FontBold, base.FnpView.RowsCount - 1, 0, true);
			ParameterCounter++;
			IFeatures features = module.Features;
			PopulateFeatures(features, gridOutlineLevel + 1);
			if (!ModuleIdParameterCountMap.ContainsKey(base.NumberOfModules))
			{
				ModuleIdParameterCountMap.Add(base.NumberOfModules, ParameterCounter);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void PopulateSmartDevices(Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IModules smartDevices)
		{
			if (smartDevices.Count > 0)
			{
				base.FnpView.AddSystemName(_stringProvider.GetLocalizedString(StringIdProvider.OtherDevices));
				base.FnpView.SetValue(PropertyDescriptor.FontBold, base.FnpView.RowsCount - 1, 0, true);
				base.FnpView.SetValue(PropertyDescriptor.OutlineLevel, base.FnpView.RowsCount - 1, 0, 0);
				PopulateModules(smartDevices, 1);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void PopulateFeature(IFeature feature, int gridOutlineLevel)
		{
			if (feature == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4220), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4346));
			}
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(feature.Name.Trim());
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4364));
			stringBuilder.Append(feature.Value.Trim());
			RowInformation rowInformation = T5NAFmPE3(feature, RowType.Feature);
			base.FnpView.AddItem(stringBuilder.ToString());
			base.FnpView.SetValue(PropertyDescriptor.OutlineLevel, base.FnpView.RowsCount - 1, 0, gridOutlineLevel);
			base.FnpView.SetValue(PropertyDescriptor.FontBold, base.FnpView.RowsCount - 1, 0, true);
			ParameterCounter++;
			int rowsCount = base.FnpView.RowsCount;
			rrCU7XmAi(feature, rowsCount - 1, rowInformation);
			WY6ByPR0k(rowsCount - 1, rowInformation.FnPElement.ValueType);
			ElementRowStructureMap.Add(rowsCount - 1, rowInformation);
			cQPuNAYMk(feature.EnableId, rowInformation.ModuleId, rowsCount - 1);
			ISubFeatures subFeatures = feature.SubFeatures;
			PopulateSubFeatures(subFeatures, rowsCount - 1, gridOutlineLevel + 1);
			base.FnpView.PutRowCollapse(rowsCount - 1, isRowCollapse: true);
			if (feature.ReadBlocked)
			{
				base.FnpView.PutRowCollapse(rowsCount - 1, isRowCollapse: true);
				base.FnpView.PutRowHidden(rowsCount - 1, hide: true);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static bool psDviG2Jt(IFnPElement P_0)
		{
			bool result = false;
			if (P_0.ReadBlocked || P_0.WriteBlocked || !P_0.Writable || P_0.GtisLocked)
			{
				result = true;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool pmSrGDUMX()
		{
			bool result = false;
			if (CurrentSecurityLevel <= SecurityLevel.Basic || CurrentSecurityLevel == SecurityLevel.OBD || CurrentSecurityLevel == SecurityLevel.OBDRSGR)
			{
				result = true;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool ldY9fTuS2(IFnPElement P_0)
		{
			bool result = false;
			if (P_0.HasUsage(UsageType.RSGRParameters) && CurrentSecurityLevel == SecurityLevel.RSGR)
			{
				result = true;
			}
			else if (P_0.HasUsage(UsageType.OEMProtectedParameters))
			{
				result = !IsOEMAvailable;
			}
			else if (P_0.HasUsage(UsageType.OEM2ProtectedParameters))
			{
				result = !IsOEM2Available;
			}
			else if (P_0 is Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameter)
			{
				result = ((!P_0.HasUsage(UsageType.ResetParameters)) ? (((PasswordLevel != ECMPasswordType.Master && PasswordLevel != ECMPasswordType.Adjustment) || !P_0.HasUsage(UsageType.AdjustableSubFeaturesAndParameters)) ? true : false) : ((PasswordLevel != ECMPasswordType.Master && PasswordLevel != ECMPasswordType.Reset) ? true : false));
			}
			else if (P_0 is IFeature)
			{
				result = (((PasswordLevel != ECMPasswordType.Master && PasswordLevel != ECMPasswordType.Adjustment) || !P_0.HasUsage(UsageType.AdjustableFeatures)) ? true : false);
			}
			else if (P_0 is ISubFeature)
			{
				result = (((PasswordLevel != ECMPasswordType.Master && PasswordLevel != ECMPasswordType.Adjustment) || !P_0.HasUsage(UsageType.AdjustableSubFeaturesAndParameters)) ? true : false);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static bool NZcRaCHFL(IFnPElement P_0)
		{
			bool result = false;
			if (P_0 is IFeatureElement featureElement)
			{
				result = featureElement.EnableId == 0;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override bool CheckFnPElementLockState(IFnPElement element)
		{
			bool flag = false;
			if (IsConnectedToImage || !HasUserRights)
			{
				return true;
			}
			if (pmSrGDUMX())
			{
				return true;
			}
			if (psDviG2Jt(element))
			{
				return true;
			}
			if (!NZcRaCHFL(element))
			{
				return ldY9fTuS2(element);
			}
			if (PasswordLevel == ECMPasswordType.None)
			{
				return true;
			}
			return false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void PopulateSubFeature(ISubFeature subFeature, int parentRow, int gridOutlineLevel)
		{
			if (subFeature == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4370), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4502));
			}
			int rowsCount = base.FnpView.RowsCount;
			bool flag = false;
			if (subFeature.Id > 99)
			{
				StringBuilder stringBuilder = new StringBuilder();
				stringBuilder.Append(subFeature.Name.Trim());
				stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4526));
				stringBuilder.Append(subFeature.Value.Trim());
				RowInformation rowInformation = T5NAFmPE3(subFeature, RowType.SubFeature);
				base.FnpView.AddItem(stringBuilder.ToString());
				base.FnpView.SetValue(PropertyDescriptor.OutlineLevel, base.FnpView.RowsCount - 1, 0, gridOutlineLevel);
				base.FnpView.SetValue(PropertyDescriptor.FontBold, base.FnpView.RowsCount - 1, 0, true);
				flag = true;
				ParameterCounter++;
				rrCU7XmAi(subFeature, rowsCount, rowInformation);
				WY6ByPR0k(rowsCount, rowInformation.FnPElement.ValueType);
				ElementRowStructureMap.Add(rowsCount, rowInformation);
				cQPuNAYMk(subFeature.EnableId, rowInformation.ModuleId, rowsCount);
				base.FnpView.PutRowCollapse(rowsCount, isRowCollapse: true);
			}
			else
			{
				gridOutlineLevel--;
			}
			Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameters parameters = subFeature.Parameters;
			PopulateParameters(parameters, gridOutlineLevel + 1);
			ISubFeatures subFeatures = subFeature.SubFeatures;
			PopulateSubFeatures(subFeatures, parentRow, gridOutlineLevel + 1);
			if (flag)
			{
				base.FnpView.PutRowCollapse(rowsCount, isRowCollapse: true);
			}
			if (subFeature.ReadBlocked)
			{
				base.FnpView.PutRowCollapse(rowsCount, isRowCollapse: true);
				base.FnpView.PutRowHidden(rowsCount, hide: true);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void PopulateParameter(Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameter parameter, int gridOutlineLevel)
		{
			if (parameter == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4532), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4662));
			}
			string text = parameter.Value;
			if (NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4684) == text)
			{
				text = "";
			}
			string unit = parameter.Unit;
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(parameter.Name.Trim());
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4698));
			stringBuilder.Append(text.Trim());
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4704));
			stringBuilder.Append(unit.Trim());
			RowInformation rowInformation = T5NAFmPE3(parameter, RowType.Parameter);
			base.FnpView.AddItem(stringBuilder.ToString());
			base.FnpView.SetValue(PropertyDescriptor.OutlineLevel, base.FnpView.RowsCount - 1, 0, gridOutlineLevel);
			ParameterCounter++;
			int rowsCount = base.FnpView.RowsCount;
			rrCU7XmAi(parameter, rowsCount - 1, rowInformation);
			WY6ByPR0k(rowsCount - 1, rowInformation.FnPElement.ValueType);
			ElementRowStructureMap.Add(rowsCount - 1, rowInformation);
			cQPuNAYMk(parameter.Id, rowInformation.ModuleId, rowsCount - 1);
			if (parameter.ReadBlocked)
			{
				base.FnpView.PutRowCollapse(rowsCount - 1, isRowCollapse: true);
				base.FnpView.PutRowHidden(rowsCount - 1, hide: true);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override float GetPrecission(IFnPElement element, int moduleType)
		{
			if (element == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4710), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4832));
			}
			return SS4phmddGR.GetPrecission(element, moduleType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void oXaLWVBLV()
		{
			((IModelEventPublisher)SS4phmddGR).FeatureDataAvailable += ((IModelEventListener)this).OnFeatureDataAvailable;
			((IModelEventPublisher)SS4phmddGR).ErrorInFnPModel += ((IModelEventListener)this).OnErrorInFnPModel;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Aj3cmxwh9()
		{
			((IModelEventPublisher)SS4phmddGR).FeatureDataAvailable -= ((IModelEventListener)this).OnFeatureDataAvailable;
			((IModelEventPublisher)SS4phmddGR).ErrorInFnPModel -= ((IModelEventListener)this).OnErrorInFnPModel;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void SZ9T3bA1e()
		{
			if (base.ElementParameterIdMap != null && base.ElementParameterIdMap.Count > 0)
			{
				base.ElementParameterIdMap.Clear();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private List<int> aMuYdtwDI(int P_0, int P_1)
		{
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4850), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(4986));
			}
			List<int> result = new List<int>();
			if (base.ElementParameterIdMap.ContainsKey(P_1) && base.ElementParameterIdMap[P_1].ContainsKey(P_0))
			{
				result = base.ElementParameterIdMap[P_1][P_0];
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool GdZIQGnD5(int P_0, int P_1)
		{
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(5012), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(5170));
			}
			bool result = false;
			if (base.ElementParameterIdMap.ContainsKey(P_1) && base.ElementParameterIdMap[P_1].ContainsKey(P_0))
			{
				result = true;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void cQPuNAYMk(int P_0, int P_1, int P_2)
		{
			List<int> list = new List<int>();
			if (base.ElementParameterIdMap.ContainsKey(P_1) && base.ElementParameterIdMap[P_1].ContainsKey(P_0))
			{
				list = base.ElementParameterIdMap[P_1][P_0];
				list.Add(P_2);
			}
			else
			{
				list.Add(P_2);
			}
			base.ElementParameterIdMap[P_1][P_0] = list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void BrikDItJY(RowInformation P_0)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(5196), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(5332));
			}
			if (FnPValueType.List == P_0.FnPElement.ValueType)
			{
				string text = string.Empty;
				IEnumerableFnPElement enumerableFnPElement = (IEnumerableFnPElement)P_0.FnPElement;
				if (enumerableFnPElement == null)
				{
					return;
				}
				Dictionary<string, double> enumerationInfo = enumerableFnPElement.GetEnumerationInfo();
				if (enumerationInfo != null)
				{
					if (enumerationInfo.Count == 0)
					{
						text = P_0.FnPElement.Value.Trim();
					}
					else
					{
						foreach (string key in enumerationInfo.Keys)
						{
							if (string.IsNullOrEmpty(text))
							{
								text = key.ToString(CultureInfo.InvariantCulture).Trim();
								continue;
							}
							text += NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(5350);
							text += key.ToString(CultureInfo.InvariantCulture).Trim();
						}
					}
				}
				P_0.EnumString = text;
			}
			else
			{
				P_0.EnumString = string.Empty;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void rrCU7XmAi(IFnPElement P_0, int P_1, RowInformation P_2)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(5356), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(5472));
			}
			if (P_2 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(5490), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(5606));
			}
			if (P_0 is IFeature || P_0 is ISubFeature)
			{
				T2WMsSKmT(P_0, P_1, P_2);
			}
			else if (P_0 is Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameter)
			{
				ExpwpKrTZ(P_0, P_1, P_2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void T2WMsSKmT(IFnPElement P_0, int P_1, RowInformation P_2)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(5624), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(5754));
			}
			if (P_2 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(5772), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(5902));
			}
			if (CheckFnPElementLockState(P_0))
			{
				P_2.IconState = IconState.LockedUnselected;
				base.FnpView.SetValue(PropertyDescriptor.Picture, P_1, 0, FnPResources.FnPFeatureUnselectedLocked.ToBitmap());
			}
			else
			{
				P_2.IconState = IconState.DefaultUnselected;
				base.FnpView.SetValue(PropertyDescriptor.Picture, P_1, 0, FnPResources.FnPFeatureUnselected.ToBitmap());
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ExpwpKrTZ(IFnPElement P_0, int P_1, RowInformation P_2)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(5920), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(6054));
			}
			if (P_2 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(6072), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(6206));
			}
			if (CheckFnPElementLockState(P_0))
			{
				P_2.IconState = IconState.LockedUnselected;
				base.FnpView.SetValue(PropertyDescriptor.Picture, P_1, 0, FnPResources.FnPParameterUnselectedLocked.ToBitmap());
			}
			else
			{
				P_2.IconState = IconState.DefaultUnselected;
				base.FnpView.SetValue(PropertyDescriptor.Picture, P_1, 0, FnPResources.FnPParameterUnselected.ToBitmap());
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static int rTxhtUKRm(IFnPElement P_0)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(6224), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(6348));
			}
			int num = 0;
			if (!(P_0 is IFeatureElement { EnableId: var enableId }))
			{
				return P_0.Id;
			}
			return enableId;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private RowInformation T5NAFmPE3(IFnPElement P_0, RowType P_1)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(6366), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(6502));
			}
			RowInformation rowInformation = new RowInformation();
			rowInformation.RowType = P_1;
			rowInformation.FnPElement = P_0;
			rowInformation.ModuleId = base.NumberOfModules;
			rowInformation.Precission = GetPrecission(P_0, ModuleType);
			BrikDItJY(rowInformation);
			return rowInformation;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void WY6ByPR0k(int P_0, FnPValueType P_1)
		{
			switch (P_1)
			{
			case FnPValueType.RealTime:
				base.FnpView.PutEditMask(P_0, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(6520));
				break;
			case FnPValueType.HHHHHHMM:
				base.FnpView.PutEditMask(P_0, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(6540));
				break;
			case FnPValueType.MMSS:
				base.FnpView.PutEditMask(P_0, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(6564));
				break;
			case FnPValueType.Long:
			case FnPValueType.Double:
			case FnPValueType.Float:
			case FnPValueType.String:
				base.FnpView.PutEditMask(P_0, string.Empty);
				break;
			case FnPValueType.RealDate:
			case FnPValueType.NaturalNumber:
			case FnPValueType.Binary:
			case FnPValueType.List:
			case FnPValueType.Reset:
			case FnPValueType.Default:
			case FnPValueType.Unknown:
				break;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void iKmesffCZ(ref bool P_0)
		{
			//IL_0054: Unknown result type (might be due to invalid IL or missing references)
			//IL_0059: Unknown result type (might be due to invalid IL or missing references)
			//IL_005b: Unknown result type (might be due to invalid IL or missing references)
			//IL_005c: Invalid comparison between I4 and Unknown
			//IL_0084: Unknown result type (might be due to invalid IL or missing references)
			//IL_0085: Invalid comparison between I4 and Unknown
			if (KajpIplcST.ModuleIdParamMap.Count > 0)
			{
				string localizedString = _stringProvider.GetLocalizedString(StringIdProvider.InsiteTitle);
				string localizedString2 = _stringProvider.GetLocalizedString(StringIdProvider.SendChangesMessage);
				DialogResult val = base.FnpView.DisplayMessage(localizedString2, localizedString, (MessageBoxButtons)3, (MessageBoxIcon)48);
				if (6 == (int)val)
				{
					if (p2W5WO8JXo())
					{
						if (y825nkIZ9d())
						{
							L7xKRSRQV();
						}
						P_0 = true;
					}
				}
				else if (7 == (int)val)
				{
					L7xKRSRQV();
					P_0 = true;
				}
				else
				{
					P_0 = false;
				}
			}
			else
			{
				P_0 = true;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void TgDQZNFek()
		{
			base.FnpView.Cursor = Cursors.WaitCursor;
			Dictionary<int, Dictionary<string, object>> moduleIdParamMap = KajpIplcST.ModuleIdParamMap;
			foreach (int key in moduleIdParamMap.Keys)
			{
				foreach (string key2 in moduleIdParamMap[key].Keys)
				{
					int result = 0;
					if (!int.TryParse(key2, out result) || !GdZIQGnD5(result, key))
					{
						continue;
					}
					List<int> list = aMuYdtwDI(result, key);
					foreach (int item in list)
					{
						IFnPElement fnPElement = ElementRowStructureMap[item].FnPElement;
						fnPElement.ClearDesiredValue(result);
						fnPElement.Value = fnPElement.OriginalValue;
						fnPElement.OriginalValue = string.Empty;
						fnPElement.RefreshElement(updateBucket: true, readFromECM: false);
						inQ5Pg1v7Y(fnPElement.ImpactedParameters, key, false);
						RsQ5ruJ36U(item);
						rnI0VgnVO(fnPElement, item);
					}
				}
			}
			KajpIplcST.Clear();
			base.FnpView.Cursor = Cursors.Default;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void L7xKRSRQV()
		{
			try
			{
				lock (ewMpqKX74K)
				{
					if (KajpIplcST.ModuleIdParamMap == null || KajpIplcST.ModuleIdParamMap.Keys.Count <= 0)
					{
						return;
					}
					foreach (int key in KajpIplcST.ModuleIdParamMap.Keys)
					{
						foreach (string key2 in KajpIplcST.ModuleIdParamMap[key].Keys)
						{
							int result = 0;
							if (!int.TryParse(key2, out result) || !GdZIQGnD5(result, key))
							{
								continue;
							}
							List<int> list = aMuYdtwDI(result, key);
							foreach (int item in list)
							{
								IFnPElement fnPElement = ElementRowStructureMap[item].FnPElement;
								fnPElement.Value = fnPElement.OriginalValue;
								fnPElement.OriginalValue = string.Empty;
								if (dWnpYjQ8oZ && !SS4phmddGR.IsConnectionLost())
								{
									fnPElement.ClearDesiredValue(result);
									fnPElement.RefreshElement(updateBucket: true, readFromECM: true);
									inQ5Pg1v7Y(fnPElement.ImpactedParameters, key, true);
									RsQ5ruJ36U(item);
								}
							}
						}
					}
					KajpIplcST.Clear();
				}
			}
			catch (ECMConnectionException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception);
				KajpIplcST.Clear();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool Kr2yIvaea(char P_0, IFnPElement P_1)
		{
			if (P_1 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(6578), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(6710));
			}
			bool result = false;
			char c = char.Parse(CultureInfo.CurrentCulture.NumberFormat.NumberDecimalSeparator);
			char obj = char.Parse(CultureInfo.CurrentCulture.NumberFormat.NegativeSign);
			int decimalPrecission = SS4phmddGR.GetDecimalPrecission(rTxhtUKRm(P_1), ModuleType);
			if (P_0.Equals(c))
			{
				if ((base.FnpView.EditText.Contains(c.ToString()) && base.FnpView.EditSelStart > 0) || decimalPrecission == 0)
				{
					result = true;
				}
			}
			else if (P_0.Equals(obj))
			{
				if (base.FnpView.EditSelStart > 0 || !TCR5Uwbjvs(P_1))
				{
					result = true;
				}
			}
			else if (char.IsNumber(P_0))
			{
				if (base.FnpView.EditText.Contains(c.ToString()) && base.FnpView.EditSelStart > base.FnpView.EditText.IndexOf(c) + decimalPrecission)
				{
					result = true;
				}
			}
			else
			{
				result = true;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void UvjJ2wYjK()
		{
			base.FnpView.Cursor = Cursors.WaitCursor;
			SZ9T3bA1e();
			ElementRowStructureMap.Clear();
			f9ipADcKnZ.Reset();
			ThreadPool.QueueUserWorkItem(SS4phmddGR.PrepareFnPDataObject);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void w7sF8FDbK()
		{
			base.FnpView.PutRowCollapse(base.FnpView.CurrentRow, isRowCollapse: false);
			RsQ5ruJ36U(base.FnpView.CurrentRow);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void TDsl5ISil(int P_0, bool P_1)
		{
			SS4phmddGR.RefreshModule(P_0, P_1);
			nnL5vcie30();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void oKwxensI6(int P_0)
		{
			if (!ElementRowStructureMap.ContainsKey(P_0))
			{
				return;
			}
			Node node = base.FnpView.GetRowNode(P_0);
			while (node.Level >= 2)
			{
				if (base.FnpView.GetRowCollapse(node.GetNode(NodeTypeEnum.Parent).Row.Index))
				{
					base.FnpView.PutRowCollapse(node.GetNode(NodeTypeEnum.Parent).Row.Index, isRowCollapse: false);
				}
				node = node.GetNode(NodeTypeEnum.Parent);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void rnI0VgnVO(IFnPElement P_0, int P_1)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(6728), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(6886));
			}
			if (FnPValueType.List == P_0.ValueType && P_0 is IEnumerableFnPElement enumerableFnPElement && 0.0 == enumerableFnPElement.GetEnumForDisplayValue(P_0.Value))
			{
				base.FnpView.PutRowCollapse(P_1, isRowCollapse: true);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool yrogoQc8b(ref int P_0)
		{
			//IL_00d4: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d9: Invalid comparison between I4 and Unknown
			//IL_007c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0081: Invalid comparison between I4 and Unknown
			//IL_0199: Unknown result type (might be due to invalid IL or missing references)
			bool flag = false;
			bool flag2 = true;
			bool flag3 = true;
			int num = base.FnpView.RowsCount - 1;
			int num2 = base.FnpView.CurrentRow;
			while (flag2)
			{
				if (Jhbp0jg3fZ.DirectionDown)
				{
					num2++;
					if (num2 > num)
					{
						if (6 != (int)base.FnpView.DisplayMessage(_stringProvider.GetLocalizedString(StringIdProvider.ContinueFromBeginMessage), _stringProvider.GetLocalizedString(StringIdProvider.ContinueFromBeginMessageCaption), (MessageBoxButtons)4, (MessageBoxIcon)32))
						{
							flag3 = false;
							break;
						}
						num2 = 0;
					}
				}
				else
				{
					num2--;
					if (num2 < 0)
					{
						if (6 != (int)base.FnpView.DisplayMessage(_stringProvider.GetLocalizedString(StringIdProvider.ContinueFromEndMessage), _stringProvider.GetLocalizedString(StringIdProvider.ContinueFromEndMessageCaption), (MessageBoxButtons)4, (MessageBoxIcon)32))
						{
							flag3 = false;
							break;
						}
						num2 = num;
					}
				}
				if (num2 == P_0)
				{
					flag2 = false;
					flag = false;
					flag3 = true;
					break;
				}
				if (ElementRowStructureMap.ContainsKey(num2))
				{
					object value = base.FnpView.GetValue(PropertyDescriptor.Value, num2, Jhbp0jg3fZ.FindIn);
					if (value != null)
					{
						string text = value.ToString();
						flag = DdN79kVU5(text, num2);
						flag2 = !flag;
					}
				}
			}
			if (flag)
			{
				P_0 = num2;
			}
			else if (flag3)
			{
				base.FnpView.DisplayMessage(_stringProvider.GetLocalizedString(StringIdProvider.NoMatchFoundMessage), _stringProvider.GetLocalizedString(StringIdProvider.NoMatchFoundMessageCaption), (MessageBoxButtons)0, (MessageBoxIcon)48);
			}
			return flag;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool DdN79kVU5(string P_0, int P_1)
		{
			bool result = false;
			if (!string.IsNullOrEmpty(P_0) && !ElementRowStructureMap[P_1].FnPElement.ReadBlocked)
			{
				string findWhat = Jhbp0jg3fZ.FindWhat;
				if (!Jhbp0jg3fZ.MatchCase)
				{
					P_0 = P_0.ToUpperInvariant();
					findWhat = findWhat.ToUpperInvariant();
					result = P_0.Contains(findWhat);
				}
				else
				{
					result = P_0.Contains(findWhat);
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void lNAqu4EKH(int P_0)
		{
			try
			{
				if (-1 != LL3pxtrScZ)
				{
					ICommunicationsLock communicationLock = SS4phmddGR.GetCommunicationLock();
					if (communicationLock != null)
					{
						communicationLock.UnregisterDisconnectCallback(LL3pxtrScZ);
						LL3pxtrScZ = -1;
					}
				}
			}
			catch (COMException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void fLE8xx2Fw(ECMSERVICESAPILib.IDisconnectCallback P_0)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(6904), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7052));
			}
			try
			{
				if (-1 == LL3pxtrScZ)
				{
					ICommunicationsLock communicationLock = SS4phmddGR.GetCommunicationLock();
					communicationLock.RegisterDisconnectCallback(P_0, ref LL3pxtrScZ);
				}
			}
			catch (COMException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private Dictionary<string, string> gZliNZDkF(int P_0, IFeatureExclusiveFnPElement P_1, int P_2)
		{
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7072), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7208));
			}
			if (P_1 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7234), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7370));
			}
			Dictionary<string, string> dictionary = new Dictionary<string, string>();
			List<FeatureExclusivityInfo> featureExclusivityInfo = P_1.FeatureExclusivityInfo;
			if (featureExclusivityInfo != null && featureExclusivityInfo.Count > 0)
			{
				foreach (FeatureExclusivityInfo item in featureExclusivityInfo)
				{
					if (item.SourceParameter1Id.Equals(P_0))
					{
						pHsjxXyvP(item.SourceParameter2Id, dictionary, P_2);
						pHsjxXyvP(item.ConfigParameter1Id, dictionary, P_2);
						pHsjxXyvP(item.ConfigParameter2Id, dictionary, P_2);
					}
					else if (item.SourceParameter2Id.Equals(P_0))
					{
						pHsjxXyvP(item.SourceParameter1Id, dictionary, P_2);
						pHsjxXyvP(item.ConfigParameter1Id, dictionary, P_2);
						pHsjxXyvP(item.ConfigParameter2Id, dictionary, P_2);
					}
					else if (item.ConfigParameter1Id.Equals(P_0))
					{
						pHsjxXyvP(item.SourceParameter1Id, dictionary, P_2);
						pHsjxXyvP(item.SourceParameter2Id, dictionary, P_2);
						pHsjxXyvP(item.ConfigParameter2Id, dictionary, P_2);
					}
					else if (item.ConfigParameter2Id.Equals(P_0))
					{
						pHsjxXyvP(item.SourceParameter1Id, dictionary, P_2);
						pHsjxXyvP(item.SourceParameter2Id, dictionary, P_2);
						pHsjxXyvP(item.ConfigParameter1Id, dictionary, P_2);
					}
				}
			}
			return dictionary;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void pHsjxXyvP(int P_0, Dictionary<string, string> parameterMap, int P_2)
		{
			if (P_0 == 0 || !GdZIQGnD5(P_0, P_2))
			{
				return;
			}
			List<int> list = aMuYdtwDI(P_0, P_2);
			foreach (int item in list)
			{
				parameterMap.Add(ElementRowStructureMap[item].FnPElement.FullName, ElementRowStructureMap[item].FnPElement.Value);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static ValidateLimit rxyOabt3o(string P_0, IFnPElement P_1)
		{
			if (string.IsNullOrEmpty(P_0))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7388), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7528));
			}
			if (P_1 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7550), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7690));
			}
			ValidateLimit result = ValidateLimit.WithinLimit;
			if (!P_1.MaxValue.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7708)) || !P_1.MinValue.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7738)) || P_1.ValueType == FnPValueType.HHHHHHMM || P_1.ValueType == FnPValueType.MMSS)
			{
				if (P_1.ValueType == FnPValueType.RealTime || P_1.ValueType == FnPValueType.HHHHHHMM || P_1.ValueType == FnPValueType.MMSS)
				{
					if (P_0.Contains(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7768)) || P_0.Contains(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7774)))
					{
						P_0 = P_0.Replace(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7780), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7786));
						P_0 = P_0.Replace(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7792), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7798));
					}
					result = WGxXIF5RN(P_0, P_1);
				}
				else
				{
					result = mh3Eqxjyt(P_0, P_1);
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static ValidateLimit WGxXIF5RN(string P_0, IFnPElement P_1)
		{
			if (string.IsNullOrEmpty(P_0))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7804), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7966));
			}
			if (P_1 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(7988), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8150));
			}
			ValidateLimit result = ValidateLimit.WithinLimit;
			double num = 0.0;
			double num2 = 0.0;
			double num3 = 0.0;
			if (P_1.ValueType == FnPValueType.RealTime)
			{
				num = EWg1fmqbh(P_0);
				num2 = EWg1fmqbh(P_1.MinValue);
				num3 = EWg1fmqbh(P_1.MaxValue);
				if (!P_1.MaxValue.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8168)) && num > num3)
				{
					result = ValidateLimit.MaxLimitExceeded;
				}
				else if (!P_1.MaxValue.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8198)) && num < num2)
				{
					result = ValidateLimit.MinLimitExceeded;
				}
			}
			else if (P_1.ValueType == FnPValueType.HHHHHHMM)
			{
				num = rlefaa6sg(P_0);
				num2 = rlefaa6sg(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8228));
				num3 = rlefaa6sg(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8252));
				if (num > num3)
				{
					result = ValidateLimit.MaxLimitExceeded;
				}
				else if (num < num2)
				{
					result = ValidateLimit.MinLimitExceeded;
				}
			}
			else if (P_1.ValueType == FnPValueType.MMSS)
			{
				num = EeWm4fPqA(P_0);
				num3 = EeWm4fPqA(P_1.MaxValue);
				num2 = EeWm4fPqA(P_1.MinValue);
				if (!P_1.MaxValue.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8276)) && num > num3)
				{
					result = ValidateLimit.MaxLimitExceeded;
				}
				else if (!P_1.MinValue.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8306)) && num < num2)
				{
					result = ValidateLimit.MinLimitExceeded;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool W2yC0ZuxW(string P_0, RowInformation P_1)
		{
			IFnPElement fnPElement = P_1.FnPElement;
			if (string.IsNullOrEmpty(P_0))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8336), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8456));
			}
			if (fnPElement == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8478), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8598));
			}
			if ((float)P_0.Length == P_1.Precission)
			{
				if (DateTime.TryParseExact(P_0, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8616), CultureInfo.InvariantCulture, DateTimeStyles.None, out var _))
				{
					return true;
				}
				return false;
			}
			return false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static ValidateLimit mh3Eqxjyt(string P_0, IFnPElement P_1)
		{
			if (string.IsNullOrEmpty(P_0))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8632), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8778));
			}
			if (P_1 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8800), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8946));
			}
			ValidateLimit result = ValidateLimit.WithinLimit;
			if (!P_1.MaxValue.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8964)) && double.Parse(P_0, CultureInfo.CurrentCulture) > double.Parse(P_1.MaxValue, CultureInfo.CurrentCulture))
			{
				result = ValidateLimit.MaxLimitExceeded;
			}
			else if (!P_1.MaxValue.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(8994)) && double.Parse(P_0, CultureInfo.CurrentCulture) < double.Parse(P_1.MinValue, CultureInfo.CurrentCulture))
			{
				result = ValidateLimit.MinLimitExceeded;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static double EWg1fmqbh(string P_0)
		{
			if (string.IsNullOrEmpty(P_0))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(9024), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(9170));
			}
			double num = 0.0;
			string text = P_0.Substring(0, P_0.IndexOf(':'));
			if (!string.IsNullOrEmpty(text))
			{
				num += (double)(int.Parse(text, CultureInfo.CurrentCulture) * 3600);
			}
			string text2 = P_0.Substring(P_0.IndexOf(':') + 1, P_0.LastIndexOf(':') - P_0.IndexOf(':') - 1);
			if (!string.IsNullOrEmpty(text2))
			{
				num += (double)(int.Parse(text2, CultureInfo.CurrentCulture) * 60);
			}
			string text3 = P_0.Substring(P_0.LastIndexOf(':') + 1);
			if (!string.IsNullOrEmpty(text3))
			{
				num += (double)int.Parse(text3, CultureInfo.CurrentCulture);
			}
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static double rlefaa6sg(string P_0)
		{
			if (string.IsNullOrEmpty(P_0))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(9184), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(9330));
			}
			double num = 0.0;
			string text = P_0.Substring(0, P_0.IndexOf(':'));
			if (!string.IsNullOrEmpty(text))
			{
				num += double.Parse(text, CultureInfo.CurrentCulture) * 3600.0;
			}
			string text2 = P_0.Substring(P_0.LastIndexOf(':') + 1);
			if (!string.IsNullOrEmpty(text2))
			{
				num += double.Parse(text2, CultureInfo.CurrentCulture) * 60.0;
			}
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static double EeWm4fPqA(string P_0)
		{
			if (string.IsNullOrEmpty(P_0))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(9344), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(9490));
			}
			double num = 0.0;
			string text = P_0.Substring(0, P_0.IndexOf(':'));
			if (!string.IsNullOrEmpty(text))
			{
				num += double.Parse(text, CultureInfo.CurrentCulture) * 60.0;
			}
			string text2 = P_0.Substring(P_0.LastIndexOf(':') + 1);
			if (!string.IsNullOrEmpty(text2))
			{
				num += double.Parse(text2, CultureInfo.CurrentCulture);
			}
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void vCM43Jii1()
		{
			base.FnpView.HideTooltip();
			base.FnpView.ResizeView();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void lMs2vAR4r()
		{
			PwQpBrEhIB.WaitOne();
			if (base.FnpView != null)
			{
				GD15co8GTw();
				((IDisposable)base.FnpView).Dispose();
				base.FnpView = null;
			}
			GKMpgJXCAS.Stop();
			Twl55rds0w();
			w3y5pWBxpN();
			SZ9T3bA1e();
			ElementRowStructureMap.Clear();
			ModuleIdParameterCountMap.Clear();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool M1I6uV5nZ(int P_0, string P_1, IFeatureExclusiveFnPElement P_2, int P_3)
		{
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(9504), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(9660));
			}
			if (P_2 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(9678), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(9834));
			}
			bool flag = false;
			if (P_1.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(9852)) || P_1.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(9858)))
			{
				return xW5ns2VU8(P_0, P_1, P_2, P_3);
			}
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool xW5ns2VU8(int P_0, string P_1, IFeatureExclusiveFnPElement P_2, int P_3)
		{
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(9864), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(9992));
			}
			if (P_2 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10010), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10138));
			}
			bool result = true;
			if (P_2 != null)
			{
				List<FeatureExclusivityInfo> featureExclusivityInfo = P_2.FeatureExclusivityInfo;
				if (featureExclusivityInfo != null && featureExclusivityInfo.Count > 0)
				{
					foreach (FeatureExclusivityInfo item in featureExclusivityInfo)
					{
						if (Q9kt9mtc6(P_0, item, P_1, P_3))
						{
							result = false;
							break;
						}
					}
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool Q9kt9mtc6(int P_0, FeatureExclusivityInfo P_1, string P_2, int P_3)
		{
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10156), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10296));
			}
			bool result = false;
			string text = string.Empty;
			string text2 = string.Empty;
			string text3 = string.Empty;
			string text4 = string.Empty;
			if (P_1.ConfigParameter1Id.Equals(P_0) || P_1.ConfigParameter2Id.Equals(P_0))
			{
				if (P_1.ConfigParameter1Id.Equals(P_0))
				{
					text = P_2;
					text2 = vQooeOJRm(P_1, P_3);
				}
				else
				{
					text = HPEz56sP0(P_1, P_3);
					text2 = P_2;
				}
				text3 = ep15abiBe7(P_1.SourceParameter1Id, P_3);
				text4 = ep15abiBe7(P_1.SourceParameter2Id, P_3);
			}
			else if (P_1.SourceParameter1Id.Equals(P_0) || P_1.SourceParameter2Id.Equals(P_0))
			{
				if (P_1.SourceParameter1Id.Equals(P_0))
				{
					text3 = P_2;
					text4 = ep15abiBe7(P_1.SourceParameter2Id, P_3);
				}
				else
				{
					text3 = ep15abiBe7(P_1.SourceParameter1Id, P_3);
					text4 = P_2;
				}
				text = HPEz56sP0(P_1, P_3);
				text2 = vQooeOJRm(P_1, P_3);
			}
			if (text.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10314)) && text2.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10320)) && text3.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10326)) && text4.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10332)))
			{
				result = true;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string vQooeOJRm(FeatureExclusivityInfo P_0, int P_1)
		{
			string empty = string.Empty;
			if (P_0.ConfigParameter2Id.Equals(0))
			{
				return NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10338);
			}
			return ep15abiBe7(P_0.ConfigParameter2Id, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string HPEz56sP0(FeatureExclusivityInfo P_0, int P_1)
		{
			string empty = string.Empty;
			if (P_0.ConfigParameter2Id.Equals(0))
			{
				return NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10344);
			}
			return ep15abiBe7(P_0.ConfigParameter1Id, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string ep15abiBe7(int P_0, int P_1)
		{
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10350), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10476));
			}
			string text = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10502);
			if (GdZIQGnD5(P_0, P_1))
			{
				List<int> list = aMuYdtwDI(P_0, P_1);
				foreach (int item in list)
				{
					text = ElementRowStructureMap[item].FnPElement.Value;
					text = SS4phmddGR.GetRawValueFromDisplayValue(P_0.ToString(), text, P_1.ToString()).ToString();
				}
			}
			return text;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Twl55rds0w()
		{
			if (caEpJ8GPs8 != null)
			{
				caEpJ8GPs8(this, new EventArgs());
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void w3y5pWBxpN()
		{
			if (nEipyErRXd != null)
			{
				nEipyErRXd(this, new EventArgs());
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void jst5VmtRIf(Dictionary<int, List<string>> failedParameterList)
		{
			//IL_03de: Unknown result type (might be due to invalid IL or missing references)
			//IL_0397: Unknown result type (might be due to invalid IL or missing references)
			if (failedParameterList != null && failedParameterList.Count > 0)
			{
				Dictionary<int, List<string>> dictionary = new Dictionary<int, List<string>>();
				foreach (int key in KajpIplcST.ModuleIdParamMap.Keys)
				{
					foreach (string key2 in KajpIplcST.ModuleIdParamMap[key].Keys)
					{
						if (!failedParameterList.ContainsKey(key) || !failedParameterList[key].Contains(key2) || !failedParameterList.ContainsKey(key))
						{
							if (dictionary.ContainsKey(key))
							{
								dictionary[key].Add(key2);
								continue;
							}
							dictionary.Add(key, new List<string>());
							dictionary[key].Add(key2);
						}
					}
				}
				foreach (int key3 in dictionary.Keys)
				{
					foreach (string item in dictionary[key3])
					{
						if (!KajpIplcST.ContainsParameter(item, key3))
						{
							continue;
						}
						int result = 0;
						if (int.TryParse(item, out result) && dWnpYjQ8oZ && !SS4phmddGR.IsConnectionLost())
						{
							List<int> list = aMuYdtwDI(result, key3);
							foreach (int item2 in list)
							{
								IFnPElement fnPElement = ElementRowStructureMap[item2].FnPElement;
								fnPElement.DesiredValue = string.Empty;
								fnPElement.OriginalValue = string.Empty;
								fnPElement.RefreshElement(updateBucket: true, readFromECM: false);
								RsQ5ruJ36U(item2);
							}
						}
						KajpIplcST.RemoveParameter(key3, item);
					}
				}
				dictionary.Clear();
				string localizedString = _stringProvider.GetLocalizedString(StringIdProvider.WriteUnsuccessfulTitle);
				StringBuilder stringBuilder = new StringBuilder();
				stringBuilder.Append(_stringProvider.GetLocalizedString(StringIdProvider.WriteUnsuccessfulMessage));
				foreach (int key4 in failedParameterList.Keys)
				{
					foreach (string item3 in failedParameterList[key4])
					{
						int result2 = 0;
						if (!int.TryParse(item3, out result2))
						{
							continue;
						}
						List<int> list2 = aMuYdtwDI(result2, key4);
						foreach (int item4 in list2)
						{
							IFnPElement fnPElement2 = ElementRowStructureMap[item4].FnPElement;
							stringBuilder.Append(Environment.NewLine);
							stringBuilder.Append(fnPElement2.FullName);
						}
					}
				}
				base.FnpView.DisplayMessage(stringBuilder.ToString(), localizedString, (MessageBoxButtons)0, (MessageBoxIcon)48);
			}
			else
			{
				L7xKRSRQV();
				string localizedString2 = _stringProvider.GetLocalizedString(StringIdProvider.WriteSuccessfulTitle);
				string localizedString3 = _stringProvider.GetLocalizedString(StringIdProvider.WriteSuccessfulMessage);
				base.FnpView.DisplayMessage(localizedString3, localizedString2, (MessageBoxButtons)0, (MessageBoxIcon)0);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void tBP53xLEY9(int P_0, NodeState P_1)
		{
			if (ElementRowStructureMap.ContainsKey(P_0))
			{
				RowInformation rowInformation = ElementRowStructureMap[P_0];
				if (RowType.Feature == rowInformation.RowType || RowType.SubFeature == rowInformation.RowType)
				{
					Qrm5DXldqL(P_0, P_1, rowInformation);
				}
				else if (RowType.Parameter == rowInformation.RowType)
				{
					GId5NA5kEy(P_0, P_1, rowInformation);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void GId5NA5kEy(int P_0, NodeState P_1, RowInformation P_2)
		{
			if (P_2 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10508), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10652));
			}
			Bitmap value = null;
			if (P_2.IconState == IconState.DefaultUnselected || IconState.DefaultSelected == P_2.IconState)
			{
				value = ((P_1 == NodeState.UnSelected) ? FnPResources.FnPParameterUnselected.ToBitmap() : FnPResources.FnPParameterSelected.ToBitmap());
			}
			else if (IconState.LockedUnselected == P_2.IconState || IconState.LockedSelected == P_2.IconState)
			{
				value = ((P_1 == NodeState.UnSelected) ? FnPResources.FnPParameterUnselectedLocked.ToBitmap() : FnPResources.FnPParameterSelectedLocked.ToBitmap());
			}
			base.FnpView.SetValue(PropertyDescriptor.Picture, P_0, 0, value);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Qrm5DXldqL(int P_0, NodeState P_1, RowInformation P_2)
		{
			if (P_2 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10670), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10810));
			}
			Bitmap value = null;
			if (P_2.IconState == IconState.DefaultUnselected || IconState.DefaultSelected == P_2.IconState)
			{
				value = ((P_1 == NodeState.UnSelected) ? FnPResources.FnPFeatureUnselected.ToBitmap() : FnPResources.FnPFeatureSelected.ToBitmap());
			}
			else if (IconState.LockedUnselected == P_2.IconState || IconState.LockedSelected == P_2.IconState)
			{
				value = ((P_1 == NodeState.UnSelected) ? FnPResources.FnPFeatureUnselectedLocked.ToBitmap() : FnPResources.FnPFeatureSelectedLocked.ToBitmap());
			}
			base.FnpView.SetValue(PropertyDescriptor.Picture, P_0, 0, value);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aB75dbl8ko(int P_0, RowInformation P_1)
		{
			if (P_1 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10828), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10942));
			}
			if (string.IsNullOrEmpty(P_1.FnPElement.DesiredValue))
			{
				base.FnpView.SetValue(PropertyDescriptor.Value, P_0, 1, P_1.FnPElement.Value);
				base.FnpView.SetValue(PropertyDescriptor.Value, P_0, 3, string.Empty);
			}
			else
			{
				base.FnpView.SetValue(PropertyDescriptor.Value, P_0, 1, P_1.FnPElement.DesiredValue);
				base.FnpView.SetValue(PropertyDescriptor.Value, P_0, 3, P_1.FnPElement.OriginalValue);
			}
			base.FnpView.SetValue(PropertyDescriptor.Value, P_0, 2, P_1.FnPElement.Unit);
			rrCU7XmAi(P_1.FnPElement, P_0, P_1);
			if (P_1.EnumString.Trim().Length == 0 && P_1.FnPElement.ValueType == FnPValueType.List)
			{
				P_1.EnumString = P_1.FnPElement.Value;
			}
			rnI0VgnVO(P_1.FnPElement, P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void xcH5Hlmei2(int P_0, int P_1)
		{
			if (P_0 <= 0 || P_1 != 0)
			{
				return;
			}
			Node rowNode = base.FnpView.GetRowNode(P_0);
			if (rowNode != null && rowNode.Children > 0)
			{
				if (base.FnpView.GetRowCollapse(P_0))
				{
					base.FnpView.PutRowCollapse(P_0, isRowCollapse: false);
					return;
				}
				base.FnpView.CurrentRow = P_0 + 1;
				base.FnpView.CurrentColumn = 0;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void SI95SB0rZe(int P_0, int P_1)
		{
			if (P_0 > 0 && P_1 == 0 && base.FnpView.GetRowCollapse(P_0))
			{
				base.FnpView.PutRowCollapse(P_0, isRowCollapse: false);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void MiX5GovuOU(int P_0, int P_1)
		{
			if (P_0 > 0 && P_1 == 0 && !base.FnpView.GetRowCollapse(P_0))
			{
				Node rowNode = base.FnpView.GetRowNode(P_0);
				if (rowNode != null && rowNode.Children > 0)
				{
					base.FnpView.PutRowCollapse(P_0, isRowCollapse: true);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void att5ZVBwx1(int P_0, int P_1)
		{
			if (P_0 <= 1 || P_1 != 0)
			{
				return;
			}
			bool flag = true;
			if (!base.FnpView.GetRowCollapse(P_0))
			{
				Node rowNode = base.FnpView.GetRowNode(P_0);
				if (rowNode != null && rowNode.Children > 0)
				{
					base.FnpView.PutRowCollapse(P_0, isRowCollapse: true);
					flag = false;
				}
			}
			if (flag)
			{
				int parentRowIndex = base.FnpView.GetParentRowIndex(P_0);
				base.FnpView.CurrentRow = parentRowIndex;
				base.FnpView.CurrentColumn = 0;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void D215bNFEiN()
		{
			base.FnpView.PutRowCollapse(base.FnpView.CurrentRow, isRowCollapse: true);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void kCR5sDeYyM()
		{
			PasswordLevel = SS4phmddGR.GetCurrentPasswordLevel();
			IsOEMAvailable = SS4phmddGR.IsOEMAvailable();
			IsOEM2Available = SS4phmddGR.IsOEM2Available();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void inQ5Pg1v7Y(IList<string> tokensList, int P_1, bool P_2)
		{
			if (tokensList == null || tokensList.Count <= 0)
			{
				return;
			}
			foreach (string tokens in tokensList)
			{
				int result = 0;
				if (!int.TryParse(tokens, out result) || !GdZIQGnD5(result, P_1))
				{
					continue;
				}
				List<int> list = aMuYdtwDI(result, P_1);
				foreach (int item in list)
				{
					ElementRowStructureMap[item].FnPElement.RefreshElement(updateBucket: false, P_2);
					RsQ5ruJ36U(item);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool p2W5WO8JXo()
		{
			//IL_0050: Unknown result type (might be due to invalid IL or missing references)
			bool flag = SS4phmddGR.IsEngineIdle();
			if (!flag)
			{
				string localizedString = _stringProvider.GetLocalizedString(StringIdProvider.SorryTitle);
				string localizedString2 = _stringProvider.GetLocalizedString(StringIdProvider.EngineSpeedNotZero);
				base.FnpView.DisplayMessage(localizedString2, localizedString, (MessageBoxButtons)0, (MessageBoxIcon)48);
			}
			return flag;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void nnL5vcie30()
		{
			base.FnpView.Cursor = Cursors.WaitCursor;
			int rowsCount = base.FnpView.RowsCount;
			for (int i = 0; i < rowsCount; i++)
			{
				if (!ElementRowStructureMap.ContainsKey(i))
				{
					continue;
				}
				RowInformation rowInformation = ElementRowStructureMap[i];
				if (RowType.Feature == rowInformation.RowType)
				{
					if (rowInformation.FnPElement.ReadBlocked)
					{
						base.FnpView.PutRowCollapse(i, isRowCollapse: true);
						base.FnpView.PutRowHidden(i, hide: true);
					}
					else if (!base.FnpView.GetRowCollapse(i) && base.FnpView.GetRowNode(i).Children > 0)
					{
						RsQ5ruJ36U(i);
					}
					else
					{
						aB75dbl8ko(i, rowInformation);
					}
				}
			}
			base.FnpView.Cursor = Cursors.Default;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void RsQ5ruJ36U(int P_0)
		{
			if (ElementRowStructureMap.ContainsKey(P_0))
			{
				aB75dbl8ko(P_0, ElementRowStructureMap[P_0]);
				if (!ElementRowStructureMap[P_0].FnPElement.ReadBlocked)
				{
					Node rowNode = base.FnpView.GetRowNode(P_0);
					if (rowNode.Children > 0 && !base.FnpView.GetRowCollapse(P_0))
					{
						for (Node node = rowNode.GetNode(NodeTypeEnum.FirstChild); node != null; node = node.GetNode(NodeTypeEnum.NextSibling))
						{
							RsQ5ruJ36U(node.Row.Index);
						}
					}
					if (!base.FnpView.GetRowCollapse(base.FnpView.GetRowNode(P_0).GetNode(NodeTypeEnum.Parent).Row.Index) && !V4N59KQfVm(P_0))
					{
						base.FnpView.PutRowHidden(P_0, hide: false);
					}
				}
				else
				{
					base.FnpView.PutRowCollapse(P_0, isRowCollapse: true);
					base.FnpView.PutRowHidden(P_0, hide: true);
				}
				return;
			}
			Node rowNode2 = base.FnpView.GetRowNode(P_0);
			if (rowNode2.Children > 0 && !base.FnpView.GetRowCollapse(P_0))
			{
				for (Node node2 = rowNode2.GetNode(NodeTypeEnum.FirstChild); node2 != null; node2 = node2.GetNode(NodeTypeEnum.NextSibling))
				{
					RsQ5ruJ36U(node2.Row.Index);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool V4N59KQfVm(int P_0)
		{
			bool result = false;
			if (base.FnpView.GetRowNode(P_0).Level > 0)
			{
				int index = base.FnpView.GetRowNode(P_0).GetNode(NodeTypeEnum.Parent).Row.Index;
				result = base.FnpView.GetRowCollapse(index) || V4N59KQfVm(index);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void mNh5R0kpVi(ConnectionType P_0, EngineType P_1, string P_2)
		{
			if (P_2 == null)
			{
				return;
			}
			if (P_2 == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10960))
			{
				CurrentSecurityLevel = SecurityLevel.Basic;
				if (P_0 == ConnectionType.Simulator)
				{
					CurrentSecurityLevel = SecurityLevel.Lite;
				}
			}
			else if (P_2 == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10974))
			{
				CurrentSecurityLevel = SecurityLevel.RSGR;
			}
			else if (P_2 == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10986))
			{
				CurrentSecurityLevel = SecurityLevel.Lite;
			}
			else if (P_2 == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(10998))
			{
				CurrentSecurityLevel = SecurityLevel.Pro;
			}
			else if (P_2 == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11008))
			{
				CurrentSecurityLevel = SecurityLevel.OBDRSGR;
			}
			else if (P_2 == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11028))
			{
				CurrentSecurityLevel = SecurityLevel.OBD;
			}
			else if (P_2 == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11038))
			{
				CurrentSecurityLevel = SecurityLevel.ProPlus;
			}
			else if (P_2 == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11058))
			{
				CurrentSecurityLevel = SecurityLevel.RSGRPlus;
			}
			else if (P_1 == EngineType.Industrial && P_2 == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11080))
			{
				CurrentSecurityLevel = SecurityLevel.Pro;
			}
			else if (P_1 == EngineType.Automotive && P_2 == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11168))
			{
				CurrentSecurityLevel = SecurityLevel.Basic;
				f6Ep744kDM = true;
				if (P_0 == ConnectionType.Simulator)
				{
					CurrentSecurityLevel = SecurityLevel.Lite;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Qyl5LQEKq8()
		{
			//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b5: Expected O, but got Unknown
			//IL_00e5: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ef: Expected O, but got Unknown
			//IL_0102: Unknown result type (might be due to invalid IL or missing references)
			//IL_010c: Expected O, but got Unknown
			//IL_011f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0129: Expected O, but got Unknown
			((IViewEventPublisher)base.FnpView).AfterCollapse += ((IViewEventListener)this).OnAfterCollapse;
			((IViewEventPublisher)base.FnpView).AfterEdit += ((IViewEventListener)this).OnAfterEdit;
			((IViewEventPublisher)base.FnpView).AfterRowColChange += ((IViewEventListener)this).OnAfterRowColChange;
			((IViewEventPublisher)base.FnpView).BeforeCollapse += ((IViewEventListener)this).OnBeforeCollapse;
			((IViewEventPublisher)base.FnpView).BeforeEdit += ((IViewEventListener)this).OnBeforeEdit;
			((IViewEventPublisher)base.FnpView).KeyDown += new KeyEventHandler(((IViewEventListener)this).OnKeyDown);
			((IViewEventPublisher)base.FnpView).KeyPressEdit += ((IViewEventListener)this).OnGridKeyPressEdit;
			((IViewEventPublisher)base.FnpView).KeyUp += new KeyEventHandler(((IViewEventListener)this).OnKeyUp);
			((IViewEventPublisher)base.FnpView).MouseDown += new MouseEventHandler(((IViewEventListener)this).OnMouseDown);
			((IViewEventPublisher)base.FnpView).MouseMove += new MouseEventHandler(((IViewEventListener)this).OnMouseMove);
			((IViewEventPublisher)base.FnpView).StartEdit += ((IViewEventListener)this).OnStartEdit;
			((IViewEventPublisher)base.FnpView).ValidateEdit += ((IViewEventListener)this).OnValidateEdit;
			((IViewEventPublisher)base.FnpView).ViewLoaded += ((IViewEventListener)this).OnFnPViewLoaded;
			GKMpgJXCAS.Tick += UUU5TttXSZ;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void GD15co8GTw()
		{
			//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b5: Expected O, but got Unknown
			//IL_00e5: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ef: Expected O, but got Unknown
			//IL_0102: Unknown result type (might be due to invalid IL or missing references)
			//IL_010c: Expected O, but got Unknown
			//IL_011f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0129: Expected O, but got Unknown
			((IViewEventPublisher)base.FnpView).AfterCollapse -= ((IViewEventListener)this).OnAfterCollapse;
			((IViewEventPublisher)base.FnpView).AfterEdit -= ((IViewEventListener)this).OnAfterEdit;
			((IViewEventPublisher)base.FnpView).AfterRowColChange -= ((IViewEventListener)this).OnAfterRowColChange;
			((IViewEventPublisher)base.FnpView).BeforeCollapse -= ((IViewEventListener)this).OnBeforeCollapse;
			((IViewEventPublisher)base.FnpView).BeforeEdit -= ((IViewEventListener)this).OnBeforeEdit;
			((IViewEventPublisher)base.FnpView).KeyDown -= new KeyEventHandler(((IViewEventListener)this).OnKeyDown);
			((IViewEventPublisher)base.FnpView).KeyPressEdit -= ((IViewEventListener)this).OnGridKeyPressEdit;
			((IViewEventPublisher)base.FnpView).KeyUp -= new KeyEventHandler(((IViewEventListener)this).OnKeyUp);
			((IViewEventPublisher)base.FnpView).MouseDown -= new MouseEventHandler(((IViewEventListener)this).OnMouseDown);
			((IViewEventPublisher)base.FnpView).MouseMove -= new MouseEventHandler(((IViewEventListener)this).OnMouseMove);
			((IViewEventPublisher)base.FnpView).StartEdit -= ((IViewEventListener)this).OnStartEdit;
			((IViewEventPublisher)base.FnpView).ValidateEdit -= ((IViewEventListener)this).OnValidateEdit;
			((IViewEventPublisher)base.FnpView).ViewLoaded -= ((IViewEventListener)this).OnFnPViewLoaded;
			GKMpgJXCAS.Tick -= UUU5TttXSZ;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void UUU5TttXSZ(object P_0, EventArgs P_1)
		{
			if (base.FnpView != null)
			{
				if (base.FnpView.TooltipState != TooltipActiveState.None)
				{
					base.FnpView.HideTooltip();
				}
				if ((c8wpl5k3Qc == 0 || c8wpl5k3Qc == 1) && base.FnpView.TooltipState == TooltipActiveState.None)
				{
					qqq5Y7vYb0();
				}
				GKMpgJXCAS.Stop();
			}
			else
			{
				GKMpgJXCAS.Stop();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qqq5Y7vYb0()
		{
			int mouseRow = base.FnpView.MouseRow;
			int mouseColumn = base.FnpView.MouseColumn;
			if (ipZpFvNF2L == mouseRow && c8wpl5k3Qc == mouseColumn && mouseRow > 0 && mouseColumn >= 0 && ElementRowStructureMap.ContainsKey(ipZpFvNF2L))
			{
				RowInformation rowInformation = ElementRowStructureMap[ipZpFvNF2L];
				if ((IconState.LockedSelected == rowInformation.IconState || IconState.LockedUnselected == rowInformation.IconState) && base.FnpView.TooltipState != TooltipActiveState.ActiveHove)
				{
					LockStateTooltipInfo tooltipInfo = new LockStateTooltipInfo
					{
						ConnectionType = R9XpMIjBHc,
						CurrentSecurityLevel = CurrentSecurityLevel,
						ElementType = rowInformation.RowType,
						HasUserRights = HasUserRights,
						IsOEM2Available = IsOEM2Available,
						IsOEMAvailable = IsOEMAvailable,
						PasswordLevel = PasswordLevel,
						PreviousLevel = f6Ep744kDM,
						DetectType = ModuleType
					};
					string toolTipText = SS4phmddGR.TooltipProvider.ProvideLockStateTooltip(tooltipInfo, rowInformation.FnPElement);
					base.FnpView.DisplayTooltip(mouseRow, mouseColumn, toolTipText);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string EQ45IXYf7O(RowInformation P_0)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11256), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11382));
			}
			StringBuilder stringBuilder = new StringBuilder();
			if (RowType.Feature == P_0.RowType || RowType.SubFeature == P_0.RowType)
			{
				stringBuilder.Append(_stringProvider.GetLocalizedString(StringIdProvider.FeatureMaxLimitMessage));
			}
			else if (RowType.Parameter == P_0.RowType)
			{
				stringBuilder.Append(_stringProvider.GetLocalizedString(StringIdProvider.ParameterMaxLimtMessage));
			}
			stringBuilder.Append(Environment.NewLine);
			string value = string.Empty;
			if (P_0.FnPElement is Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameter)
			{
				value = SS4phmddGR.ECMDataReader.GetMinMaxLimitDependantParameterInfo(LimitParameterType.Max, rTxhtUKRm(P_0.FnPElement).ToString(), P_0.FnPElement.ModuleId.ToString());
			}
			if (string.IsNullOrEmpty(value))
			{
				if (NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11400) == P_0.FnPElement.MaxValue)
				{
					stringBuilder.Append(P_0.FnPElement.MaxValue.Trim());
				}
				else
				{
					stringBuilder.Append(P_0.FnPElement.MaxValue.Trim());
					stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11430));
					stringBuilder.Append(P_0.FnPElement.Unit.Trim());
				}
			}
			else
			{
				stringBuilder.Append(value);
			}
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string rW05uksPiF(RowInformation P_0)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11436), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11562));
			}
			StringBuilder stringBuilder = new StringBuilder();
			if (RowType.Feature == P_0.RowType || RowType.SubFeature == P_0.RowType)
			{
				stringBuilder.Append(_stringProvider.GetLocalizedString(StringIdProvider.FeatureMinLimitMessage));
			}
			else if (RowType.Parameter == P_0.RowType)
			{
				stringBuilder.Append(_stringProvider.GetLocalizedString(StringIdProvider.ParameterMinLimitMessage));
			}
			stringBuilder.Append(Environment.NewLine);
			string value = string.Empty;
			if (P_0.FnPElement is Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameter)
			{
				value = SS4phmddGR.ECMDataReader.GetMinMaxLimitDependantParameterInfo(LimitParameterType.Min, rTxhtUKRm(P_0.FnPElement).ToString(), P_0.FnPElement.ModuleId.ToString());
			}
			if (string.IsNullOrEmpty(value))
			{
				if (NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11580) == P_0.FnPElement.MinValue)
				{
					stringBuilder.Append(P_0.FnPElement.MinValue.Trim());
				}
				else
				{
					stringBuilder.Append(P_0.FnPElement.MinValue.Trim());
					stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11610));
					stringBuilder.Append(P_0.FnPElement.Unit.Trim());
				}
			}
			else
			{
				stringBuilder.Append(value);
			}
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string YQZ5kw0uDC(string P_0, int P_1)
		{
			string empty = string.Empty;
			int decimalPrecission = SS4phmddGR.GetDecimalPrecission(P_1, ModuleType);
			double num = double.Parse(P_0);
			return string.Format(CultureInfo.CurrentCulture, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11616) + decimalPrecission + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11628), new object[1] { num });
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool TCR5Uwbjvs(IFnPElement P_0)
		{
			bool flag = false;
			if (P_0.ValueType == FnPValueType.RealTime)
			{
				return !(EWg1fmqbh(P_0.MinValue) >= 0.0);
			}
			if (P_0.ValueType == FnPValueType.RealDate || P_0.ValueType == FnPValueType.HHHHHHMM || P_0.ValueType == FnPValueType.MMSS)
			{
				return false;
			}
			if (P_0.ValueType == FnPValueType.NaturalNumber)
			{
				return false;
			}
			double result = 0.0;
			if (double.TryParse(P_0.MinValue, out result))
			{
				return !(result >= 0.0);
			}
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool sQ05Mt8NvY(RowInformation P_0, string P_1, int P_2, int P_3)
		{
			bool flag = true;
			IFnPElement fnPElement = P_0.FnPElement;
			int num = rTxhtUKRm(fnPElement);
			try
			{
				if (fnPElement is IFeatureExclusiveFnPElement featureExclusiveFnPElement)
				{
					string text = SS4phmddGR.GetRawValueFromDisplayValue(num.ToString(), P_1, P_0.ModuleId.ToString()).ToString();
					flag = M1I6uV5nZ(num, text, featureExclusiveFnPElement, P_0.ModuleId);
					if (!flag)
					{
						FeatureExclusiveTooltipInfo tooltipInfo = new FeatureExclusiveTooltipInfo
						{
							FEPararmeterMap = gZliNZDkF(num, featureExclusiveFnPElement, P_0.ModuleId)
						};
						string toolTipText = SS4phmddGR.TooltipProvider.ProvideFeatureExclusiveTooltip(tooltipInfo);
						base.FnpView.SetValue(PropertyDescriptor.Value, P_2, P_3, fnPElement.Value);
						base.FnpView.DisplayTooltip(P_2, P_3, toolTipText);
						base.FnpView.Cursor = Cursors.Default;
					}
				}
			}
			catch (Exception exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
				flag = true;
			}
			return flag;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool Bpq5wF7v0V(RowInformation P_0, string P_1, int P_2, int P_3)
		{
			bool flag = false;
			IFnPElement fnPElement = P_0.FnPElement;
			try
			{
				if (fnPElement != null)
				{
					int tokenId = rTxhtUKRm(fnPElement);
					if (SS4phmddGR.ECMDataReader.GetDependantParameterList(tokenId.ToString(), fnPElement.ModuleId.ToString(CultureInfo.InvariantCulture)).Count > 0)
					{
						string toolTipText = SS4phmddGR.TooltipProvider.ProvideInvalidValueTooltip(fnPElement);
						base.FnpView.DisplayTooltip(P_2, P_3, toolTipText);
						base.FnpView.Cursor = Cursors.Default;
						fnPElement.ClearDesiredValue(tokenId);
						if (!fnPElement.Value.Equals(fnPElement.OriginalValue))
						{
							fnPElement.DesiredValue = fnPElement.Value;
						}
						base.FnpView.SetValue(PropertyDescriptor.Value, P_2, P_3, fnPElement.Value);
						flag = true;
					}
					else
					{
						flag = false;
					}
					if (!flag)
					{
						List<string> list = SS4phmddGR.CheckFnPRules(fnPElement);
						if (list != null)
						{
							string toolTipText2 = SS4phmddGR.TooltipProvider.ProvideInvalidValueTooltip(fnPElement, list);
							base.FnpView.DisplayTooltip(P_2, P_3, toolTipText2);
							base.FnpView.Cursor = Cursors.Default;
							fnPElement.ClearDesiredValue(tokenId);
							if (!fnPElement.Value.Equals(fnPElement.OriginalValue))
							{
								fnPElement.DesiredValue = fnPElement.Value;
							}
							base.FnpView.SetValue(PropertyDescriptor.Value, P_2, P_3, fnPElement.Value);
							flag = true;
						}
					}
				}
			}
			catch (Exception exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
				flag = false;
			}
			return flag;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool rit5hGnyWT(IFnPElement P_0, int P_1, int P_2, int P_3)
		{
			//IL_0091: Unknown result type (might be due to invalid IL or missing references)
			//IL_0096: Unknown result type (might be due to invalid IL or missing references)
			//IL_0099: Unknown result type (might be due to invalid IL or missing references)
			//IL_009b: Invalid comparison between I4 and Unknown
			bool result = false;
			try
			{
				int num = P_1;
				if (num == 21441)
				{
					string text = SS4phmddGR.GetRawValueFromDisplayValue(P_1.ToString(), P_0.Value, P_0.ModuleId.ToString()).ToString();
					if (NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11634) == text)
					{
						string localizedString = _stringProvider.GetLocalizedString(StringIdProvider.AlternateFuelingTableTitle);
						string localizedString2 = _stringProvider.GetLocalizedString(StringIdProvider.AlternateFuelingTableMessage);
						DialogResult val = base.FnpView.DisplayMessage(localizedString2, localizedString, (MessageBoxButtons)1, (MessageBoxIcon)32);
						if (1 != (int)val)
						{
							base.FnpView.SetValue(PropertyDescriptor.Value, P_2, P_3, P_0.Value);
							base.FnpView.Cursor = Cursors.Default;
							result = true;
						}
					}
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
				result = false;
			}
			catch (Exception exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
				result = false;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IViewEventListener.OnAfterCollapse(object sender, RowColEventArgs e)
		{
			try
			{
				base.FnpView.HideTooltip();
				if (!base.FnpView.GetRowCollapse(e.Row))
				{
					RsQ5ruJ36U(e.Row);
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IViewEventListener.OnAfterEdit(object sender, RowColEventArgs e)
		{
			try
			{
				base.FnpView.Cursor = Cursors.WaitCursor;
				if (ElementRowStructureMap.ContainsKey(e.Row))
				{
					RowInformation rowInformation = ElementRowStructureMap[e.Row];
					IFnPElement fnPElement = rowInformation.FnPElement;
					string originalValue = fnPElement.OriginalValue;
					string text = base.FnpView.GetValue(PropertyDescriptor.Value, e.Row, e.Col).ToString();
					if (fnPElement.ValueType == FnPValueType.RealTime || fnPElement.ValueType == FnPValueType.HHHHHHMM || fnPElement.ValueType == FnPValueType.MMSS)
					{
						if (text.Contains(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11640)))
						{
							text = text.Replace(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11646), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11652));
						}
					}
					else
					{
						text = text.Trim();
					}
					if (!string.IsNullOrEmpty(text))
					{
						int num = rTxhtUKRm(fnPElement);
						if (FnPValueType.RealTime != rowInformation.FnPElement.ValueType && FnPValueType.List != rowInformation.FnPElement.ValueType && FnPValueType.String != rowInformation.FnPElement.ValueType && FnPValueType.RealDate != rowInformation.FnPElement.ValueType && FnPValueType.HHHHHHMM != rowInformation.FnPElement.ValueType && FnPValueType.MMSS != rowInformation.FnPElement.ValueType)
						{
							text = YQZ5kw0uDC(text, num);
						}
						if (!fnPElement.Value.Trim().Equals(text))
						{
							if (!sQ05Mt8NvY(rowInformation, text, e.Row, e.Col) || rit5hGnyWT(fnPElement, num, e.Row, e.Col))
							{
								return;
							}
							if (!text.Equals(originalValue.TrimEnd(new char[0])))
							{
								fnPElement.DesiredValue = text;
								originalValue = fnPElement.OriginalValue;
								if (Bpq5wF7v0V(rowInformation, text, e.Row, e.Col))
								{
									return;
								}
								fnPElement.Value = text;
								base.FnpView.SetValue(PropertyDescriptor.Value, e.Row, e.Col + 2, originalValue);
								KajpIplcST.AddParameter(rowInformation.ModuleId, num.ToString(CultureInfo.InvariantCulture), fnPElement.DesiredValue);
							}
							else
							{
								fnPElement.ClearDesiredValue(num);
								fnPElement.Value = fnPElement.OriginalValue;
								fnPElement.OriginalValue = string.Empty;
								base.FnpView.SetValue(PropertyDescriptor.Value, e.Row, 3, fnPElement.OriginalValue);
								KajpIplcST.RemoveParameter(rowInformation.ModuleId, num.ToString(CultureInfo.InvariantCulture));
							}
							fnPElement.RefreshElement(updateBucket: true, readFromECM: false);
							inQ5Pg1v7Y(fnPElement.ImpactedParameters, rowInformation.ModuleId, false);
							RsQ5ruJ36U(e.Row);
							rnI0VgnVO(fnPElement, e.Row);
							if (Ke45AmIIL9(fnPElement.Id))
							{
								inQ5Pg1v7Y(fnPElement.ImpactedParameters, rowInformation.ModuleId, false);
							}
						}
						else
						{
							base.FnpView.SetValue(PropertyDescriptor.Value, e.Row, e.Col, fnPElement.Value);
						}
					}
					else
					{
						base.FnpView.SetValue(PropertyDescriptor.Value, e.Row, e.Col, fnPElement.Value);
					}
				}
				base.FnpView.Cursor = Cursors.Default;
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
			catch (FormatException exception3)
			{
				base.FnpView.SetValue(PropertyDescriptor.Value, e.Row, e.Col, ElementRowStructureMap[e.Row].FnPElement.Value);
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception3);
			}
			base.FnpView.Cursor = Cursors.Default;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool Ke45AmIIL9(int P_0)
		{
			bool result = false;
			try
			{
				if (P_0 >= 1020210 && P_0 <= 1020231)
				{
					result = true;
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception);
			}
			catch (OverflowException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception2);
			}
			catch (FormatException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception3);
			}
			catch (Exception exception4)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception4);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IViewEventListener.OnAfterRowColChange(object sender, RangeEventArgs e)
		{
			try
			{
				tBP53xLEY9(e.OldRange.r1, NodeState.UnSelected);
				tBP53xLEY9(e.NewRange.r1, NodeState.Selected);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IViewEventListener.OnBeforeCollapse(object sender, RowColEventArgs e)
		{
			try
			{
				if (ElementRowStructureMap.ContainsKey(e.Row))
				{
					base.FnpView.HideTooltip();
					RowInformation rowInformation = ElementRowStructureMap[e.Row];
					if (base.FnpView.GetRowCollapse(e.Row) && FnPValueType.List == rowInformation.FnPElement.ValueType && 0.0 == (rowInformation.FnPElement as IEnumerableFnPElement).GetEnumForDisplayValue(rowInformation.FnPElement.Value))
					{
						e.Cancel = true;
					}
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IViewEventListener.OnBeforeEdit(object sender, RowColEventArgs e)
		{
			try
			{
				if (1 == e.Col && e.Row > 1 && ElementRowStructureMap.ContainsKey(e.Row))
				{
					RowInformation rowInformation = ElementRowStructureMap[e.Row];
					if (IconState.LockedUnselected == rowInformation.IconState || IconState.LockedSelected == rowInformation.IconState)
					{
						e.Cancel = true;
						return;
					}
					switch (rowInformation.FnPElement.ValueType)
					{
					case FnPValueType.None:
					case FnPValueType.Unknown:
						e.Cancel = true;
						break;
					case FnPValueType.Numeric:
					case FnPValueType.Long:
					case FnPValueType.Double:
					case FnPValueType.Float:
					case FnPValueType.String:
					case FnPValueType.RealDate:
					case FnPValueType.NaturalNumber:
					case FnPValueType.List:
					case FnPValueType.HHHHHHMM:
					case FnPValueType.MMSS:
						base.FnpView.SetValue(PropertyDescriptor.Combolist, e.Row, 1, rowInformation.EnumString);
						break;
					case FnPValueType.RealTime:
					{
						string text = rowInformation.FnPElement.Value.Substring(0, rowInformation.FnPElement.Value.IndexOf(':'));
						if (text.Length > 2)
						{
							base.FnpView.PutEditMask(e.Row, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11658));
						}
						else
						{
							base.FnpView.PutEditMask(e.Row, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11680));
						}
						base.FnpView.SetValue(PropertyDescriptor.Combolist, e.Row, 1, rowInformation.EnumString);
						break;
					}
					case FnPValueType.Binary:
					case FnPValueType.Reset:
					case FnPValueType.Default:
						break;
					}
				}
				else
				{
					e.Cancel = true;
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IViewEventListener.OnFnPViewLoaded(object sender, EventArgs e)
		{
			base.FnpView.Cursor = Cursors.WaitCursor;
			try
			{
				if (UIState.Connected == n5BpUAFLQd || UIState.Populated == n5BpUAFLQd)
				{
					base.FnpView.RowsCount = 1;
					base.FnpView.AddItem(_stringProvider.GetLocalizedString(StringIdProvider.ReadingData));
					base.FnpView.SetValue(PropertyDescriptor.OutlineLevel, base.FnpView.RowsCount - 1, 0, 0);
					f9ipADcKnZ.Reset();
					PwQpBrEhIB.Reset();
					ThreadPool.QueueUserWorkItem(SS4phmddGR.PrepareFnPDataObject);
				}
				else
				{
					base.FnpView.RowsCount = 1;
					base.FnpView.AddItem(_stringProvider.GetLocalizedString(StringIdProvider.NoECMConnected));
					base.FnpView.SetValue(PropertyDescriptor.OutlineLevel, base.FnpView.RowsCount - 1, 0, 0);
					base.FnpView.Cursor = Cursors.Default;
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IViewEventListener.OnGridKeyPressEdit(object sender, KeyPressEditEventArgs e)
		{
			try
			{
				if (!char.IsControl(e.KeyChar) && ElementRowStructureMap.ContainsKey(e.Row))
				{
					switch (ElementRowStructureMap[e.Row].FnPElement.ValueType)
					{
					case FnPValueType.Long:
					case FnPValueType.Double:
					case FnPValueType.Float:
					case FnPValueType.RealTime:
					case FnPValueType.RealDate:
					case FnPValueType.NaturalNumber:
					case FnPValueType.HHHHHHMM:
					case FnPValueType.MMSS:
						e.Handled = Kr2yIvaea(e.KeyChar, ElementRowStructureMap[e.Row].FnPElement);
						break;
					case FnPValueType.String:
					case FnPValueType.Binary:
					case FnPValueType.List:
					case FnPValueType.Reset:
					case FnPValueType.Default:
					case FnPValueType.Unknown:
						break;
					}
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IViewEventListener.OnKeyDown(object sender, KeyEventArgs e)
		{
			//IL_0015: Unknown result type (might be due to invalid IL or missing references)
			//IL_001a: Invalid comparison between I4 and Unknown
			//IL_0043: Unknown result type (might be due to invalid IL or missing references)
			//IL_0048: Invalid comparison between I4 and Unknown
			//IL_0071: Unknown result type (might be due to invalid IL or missing references)
			//IL_0076: Invalid comparison between I4 and Unknown
			//IL_009f: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a4: Invalid comparison between I4 and Unknown
			//IL_00cd: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d2: Invalid comparison between I4 and Unknown
			//IL_00da: Unknown result type (might be due to invalid IL or missing references)
			//IL_00df: Invalid comparison between I4 and Unknown
			//IL_00f2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f7: Invalid comparison between I4 and Unknown
			//IL_010c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0111: Invalid comparison between I4 and Unknown
			//IL_00ff: Unknown result type (might be due to invalid IL or missing references)
			//IL_0104: Invalid comparison between I4 and Unknown
			//IL_0119: Unknown result type (might be due to invalid IL or missing references)
			//IL_011e: Invalid comparison between I4 and Unknown
			try
			{
				base.FnpView.HideTooltip();
				if (37 == (int)e.KeyCode)
				{
					att5ZVBwx1(base.FnpView.CurrentRow, base.FnpView.CurrentColumn);
				}
				else if (39 == (int)e.KeyCode)
				{
					xcH5Hlmei2(base.FnpView.CurrentRow, base.FnpView.CurrentColumn);
				}
				else if (107 == (int)e.KeyCode)
				{
					SI95SB0rZe(base.FnpView.CurrentRow, base.FnpView.CurrentColumn);
				}
				else if (109 == (int)e.KeyCode)
				{
					MiX5GovuOU(base.FnpView.CurrentRow, base.FnpView.CurrentColumn);
				}
				else
				{
					if (114 == (int)e.KeyCode)
					{
						return;
					}
					if (112 == (int)e.KeyCode)
					{
						nqn5B58eIL();
					}
					else if ((93 == (int)e.KeyCode || 121 == (int)e.KeyCode) && (93 == (int)e.KeyCode || (121 == (int)e.KeyCode && e.Shift.Equals(obj: true))))
					{
						e.SuppressKeyPress = true;
						base.FnpView.HideTooltip();
						qqbpkInfT6 = base.FnpView.CurrentColumn;
						LxppusUOl4 = base.FnpView.CurrentRow;
						Rectangle cellRect = base.FnpView.GetCellRect(base.FnpView.CurrentRow, base.FnpView.CurrentColumn);
						if (base.FnpView.CurrentRow < 1)
						{
							VIapek5Ra3.ProcessContextMenu(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11700));
							? val = OWxpQ6pSJO;
							IFnPView fnpView = base.FnpView;
							((ToolStripDropDown)val).Show((Control)((fnpView is Control) ? fnpView : null), cellRect.Location);
						}
						else
						{
							VIapek5Ra3.ProcessContextMenu(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11728));
							? val2 = IDhpKBhX27;
							IFnPView fnpView2 = base.FnpView;
							((ToolStripDropDown)val2).Show((Control)((fnpView2 is Control) ? fnpView2 : null), cellRect.Location);
						}
					}
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IViewEventListener.OnKeyUp(object sender, KeyEventArgs e)
		{
			//IL_000a: Unknown result type (might be due to invalid IL or missing references)
			//IL_000f: Invalid comparison between I4 and Unknown
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_001c: Invalid comparison between I4 and Unknown
			//IL_002f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0034: Invalid comparison between I4 and Unknown
			//IL_003c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0041: Invalid comparison between I4 and Unknown
			try
			{
				if (37 == (int)e.KeyCode || 109 == (int)e.KeyCode)
				{
					D215bNFEiN();
				}
				else if (39 == (int)e.KeyCode || 107 == (int)e.KeyCode)
				{
					w7sF8FDbK();
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IViewEventListener.OnMouseDown(object sender, MouseEventArgs e)
		{
			//IL_0040: Unknown result type (might be due to invalid IL or missing references)
			//IL_0045: Invalid comparison between I4 and Unknown
			try
			{
				if (base.FnpView.MouseRow >= 1)
				{
					LxppusUOl4 = base.FnpView.MouseRow;
					qqbpkInfT6 = base.FnpView.MouseColumn;
				}
				if (2097152 == (int)e.Button)
				{
					base.FnpView.HideTooltip();
					qqbpkInfT6 = base.FnpView.MouseColumn;
					if (base.FnpView.MouseRow < 1)
					{
						VIapek5Ra3.ProcessContextMenu(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11744));
						? val = OWxpQ6pSJO;
						IFnPView fnpView = base.FnpView;
						((ToolStripDropDown)val).Show((Control)((fnpView is Control) ? fnpView : null), e.Location);
					}
					else
					{
						VIapek5Ra3.ProcessContextMenu(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11772));
						? val2 = IDhpKBhX27;
						IFnPView fnpView2 = base.FnpView;
						((ToolStripDropDown)val2).Show((Control)((fnpView2 is Control) ? fnpView2 : null), e.Location);
					}
					base.FnpView.SelectRow(LxppusUOl4);
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IViewEventListener.OnMouseMove(object sender, MouseEventArgs e)
		{
			try
			{
				int mouseRow = base.FnpView.MouseRow;
				int mouseColumn = base.FnpView.MouseColumn;
				if ((mouseRow != ipZpFvNF2L || mouseColumn != c8wpl5k3Qc) && mouseColumn >= 0 && mouseRow >= 0)
				{
					ipZpFvNF2L = mouseRow;
					c8wpl5k3Qc = mouseColumn;
					GKMpgJXCAS.Start();
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IViewEventListener.OnStartEdit(object sender, RowColEventArgs e)
		{
			try
			{
				if (!ElementRowStructureMap.ContainsKey(e.Row))
				{
					return;
				}
				RowInformation rowInformation = ElementRowStructureMap[e.Row];
				if (!rowInformation.FnPElement.Writable)
				{
					e.Cancel = true;
					return;
				}
				switch (rowInformation.FnPElement.ValueType)
				{
				case FnPValueType.None:
				case FnPValueType.Unknown:
					e.Cancel = true;
					break;
				case FnPValueType.Long:
				case FnPValueType.Double:
				case FnPValueType.Float:
				case FnPValueType.String:
				case FnPValueType.RealTime:
				case FnPValueType.RealDate:
				case FnPValueType.NaturalNumber:
				case FnPValueType.List:
				case FnPValueType.HHHHHHMM:
				case FnPValueType.MMSS:
					e.Cancel = false;
					break;
				default:
					e.Cancel = true;
					break;
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IViewEventListener.OnValidateEdit(object sender, ValidateEditEventArgs e)
		{
			try
			{
				string text = string.Empty;
				if (ElementRowStructureMap.ContainsKey(e.Row))
				{
					RowInformation rowInformation = ElementRowStructureMap[e.Row];
					switch (rowInformation.FnPElement.ValueType)
					{
					case FnPValueType.None:
					case FnPValueType.Unknown:
						e.Cancel = true;
						break;
					case FnPValueType.String:
						if ((float)base.FnpView.EditText.Length > rowInformation.Precission && rowInformation.Precission > 0f)
						{
							e.Cancel = true;
							text = _stringProvider.GetLocalizedString(StringIdProvider.MaxLengthTooltip);
						}
						break;
					case FnPValueType.Long:
					case FnPValueType.Double:
					case FnPValueType.Float:
					case FnPValueType.RealTime:
					{
						string editText4 = base.FnpView.EditText;
						ValidateLimit validateLimit2 = rxyOabt3o(editText4, ElementRowStructureMap[e.Row].FnPElement);
						if (validateLimit2 != ValidateLimit.WithinLimit)
						{
							e.Cancel = true;
							LimitsTooltipInfo tooltipInfo3 = new LimitsTooltipInfo
							{
								EditValue = editText4
							};
							if (ValidateLimit.MaxLimitExceeded == validateLimit2)
							{
								tooltipInfo3.LimitValue = ElementRowStructureMap[e.Row].FnPElement.MaxValue;
							}
							else if (ValidateLimit.MinLimitExceeded == validateLimit2)
							{
								tooltipInfo3.LimitValue = ElementRowStructureMap[e.Row].FnPElement.MinValue;
							}
							text = SS4phmddGR.TooltipProvider.ProvideLimitsTooltip(tooltipInfo3, ElementRowStructureMap[e.Row].FnPElement, validateLimit2);
						}
						break;
					}
					case FnPValueType.RealDate:
					{
						string editText3 = base.FnpView.EditText;
						if (!W2yC0ZuxW(editText3, rowInformation))
						{
							e.Cancel = true;
							text = _stringProvider.GetLocalizedString(StringIdProvider.InvalidDate);
						}
						break;
					}
					case FnPValueType.NaturalNumber:
					{
						string editText2 = base.FnpView.EditText;
						double num = Convert.ToDouble(ElementRowStructureMap[e.Row].FnPElement.MaxValue);
						double num2 = 0.0;
						if (!string.IsNullOrEmpty(editText2))
						{
							num2 = Convert.ToDouble(editText2);
						}
						if (num2 >= num)
						{
							e.Cancel = true;
							LimitsTooltipInfo tooltipInfo2 = new LimitsTooltipInfo
							{
								EditValue = editText2,
								LimitValue = ElementRowStructureMap[e.Row].FnPElement.MaxValue
							};
							text = SS4phmddGR.TooltipProvider.ProvideLimitsTooltip(tooltipInfo2, ElementRowStructureMap[e.Row].FnPElement, ValidateLimit.MaxLimitExceeded);
						}
						break;
					}
					case FnPValueType.HHHHHHMM:
					{
						string editText5 = base.FnpView.EditText;
						ValidateLimit validateLimit3 = rxyOabt3o(editText5, ElementRowStructureMap[e.Row].FnPElement);
						if (validateLimit3 != ValidateLimit.WithinLimit)
						{
							e.Cancel = true;
							LimitsTooltipInfo tooltipInfo4 = new LimitsTooltipInfo
							{
								EditValue = editText5
							};
							if (ValidateLimit.MaxLimitExceeded == validateLimit3)
							{
								tooltipInfo4.LimitValue = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11788);
							}
							else if (ValidateLimit.MinLimitExceeded == validateLimit3)
							{
								tooltipInfo4.LimitValue = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11812);
							}
							text = SS4phmddGR.TooltipProvider.ProvideLimitsTooltip(tooltipInfo4, ElementRowStructureMap[e.Row].FnPElement, validateLimit3);
						}
						break;
					}
					case FnPValueType.MMSS:
					{
						string editText = base.FnpView.EditText;
						ValidateLimit validateLimit = rxyOabt3o(editText, ElementRowStructureMap[e.Row].FnPElement);
						if (validateLimit != ValidateLimit.WithinLimit)
						{
							e.Cancel = true;
							LimitsTooltipInfo tooltipInfo = new LimitsTooltipInfo
							{
								EditValue = editText
							};
							if (ValidateLimit.MaxLimitExceeded == validateLimit)
							{
								tooltipInfo.LimitValue = ElementRowStructureMap[e.Row].FnPElement.MaxValue;
							}
							else if (ValidateLimit.MinLimitExceeded == validateLimit)
							{
								tooltipInfo.LimitValue = ElementRowStructureMap[e.Row].FnPElement.MinValue;
							}
							text = SS4phmddGR.TooltipProvider.ProvideLimitsTooltip(tooltipInfo, ElementRowStructureMap[e.Row].FnPElement, validateLimit);
						}
						break;
					}
					default:
						e.Cancel = true;
						break;
					case FnPValueType.List:
						break;
					}
				}
				if (!e.Cancel)
				{
					base.FnpView.HideTooltip();
				}
				else if (!string.IsNullOrEmpty(text))
				{
					base.FnpView.DisplayTooltip(e.Row, e.Col, text);
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
			catch (FormatException exception3)
			{
				e.Cancel = true;
				base.FnpView.SetValue(PropertyDescriptor.Value, e.Row, e.Col, ElementRowStructureMap[e.Row].FnPElement.Value);
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception3);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void nqn5B58eIL()
		{
			int num = base.FnpView.CurrentRow;
			string text = GetType().GUID.ToString();
			IContextSensitiveHelpProvider contextSensitiveHelpProvider = SS4phmddGR.GetContextSensitiveHelpProvider();
			bool flag = false;
			string text2 = text;
			try
			{
				if (ElementRowStructureMap.ContainsKey(num))
				{
					RowInformation rowInformation = ElementRowStructureMap[num];
					RowType rowType = rowInformation.RowType;
					if (RowType.Parameter == rowType)
					{
						while (rowType != RowType.Feature && !flag)
						{
							Node rowNode = base.FnpView.GetRowNode(num);
							Node node = rowNode.GetNode(NodeTypeEnum.Parent);
							num = node.Row.Index;
							rowInformation = ElementRowStructureMap[num];
							rowType = rowInformation.RowType;
							if (RowType.SubFeature == rowType)
							{
								text = rowInformation.FnPElement.Id.ToString();
								text = text2 + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11836) + text;
								try
								{
									flag = contextSensitiveHelpProvider.IsHelpAvailable(text);
								}
								catch
								{
								}
							}
						}
					}
					else if (RowType.SubFeature == rowType)
					{
						while (rowType != RowType.Feature && !flag)
						{
							if (RowType.SubFeature == rowType)
							{
								rowInformation = ElementRowStructureMap[num];
								text = rowInformation.FnPElement.Id.ToString();
								text = text2 + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11848) + text;
								try
								{
									flag = contextSensitiveHelpProvider.IsHelpAvailable(text);
								}
								catch
								{
								}
								if (!flag)
								{
									Node rowNode2 = base.FnpView.GetRowNode(num);
									Node node2 = rowNode2.GetNode(NodeTypeEnum.Parent);
									num = node2.Row.Index;
									rowInformation = ElementRowStructureMap[num];
									rowType = rowInformation.RowType;
								}
							}
						}
					}
					if (RowType.Feature == rowType)
					{
						_ = rowInformation.FnPElement.Id;
						text = rowInformation.FnPElement.Id.ToString();
						text = text2 + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11860) + text;
						try
						{
							flag = contextSensitiveHelpProvider.IsHelpAvailable(text);
						}
						catch
						{
						}
					}
				}
				contextSensitiveHelpProvider.ShowHelp(text, enumHelpType.GENERIC);
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qMw5eWV0x9()
		{
			//IL_036c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0373: Expected O, but got Unknown
			//IL_0373: Unknown result type (might be due to invalid IL or missing references)
			//IL_037a: Expected O, but got Unknown
			//IL_037a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0381: Expected O, but got Unknown
			//IL_0381: Unknown result type (might be due to invalid IL or missing references)
			//IL_0388: Expected O, but got Unknown
			//IL_0388: Unknown result type (might be due to invalid IL or missing references)
			//IL_038f: Expected O, but got Unknown
			//IL_038f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0396: Expected O, but got Unknown
			//IL_0396: Unknown result type (might be due to invalid IL or missing references)
			//IL_039d: Expected O, but got Unknown
			//IL_039d: Unknown result type (might be due to invalid IL or missing references)
			//IL_03a4: Expected O, but got Unknown
			ToolStripMenuItem val = Y1P5QR0nje(StringIdProvider.ExpandAll, null, null, jhb5KQgYbs);
			ToolStripMenuItem val2 = Y1P5QR0nje(StringIdProvider.CollapseAll, null, null, tgg5y8qVE6);
			ToolStripMenuItem val3 = Y1P5QR0nje(StringIdProvider.AutoSizeCol, null, OEc56nr2E3, d7p5JcgnZV);
			ToolStripMenuItem val4 = Y1P5QR0nje(StringIdProvider.AutoSizeAllCols, null, OEc56nr2E3, wpF5FDAfcO);
			ToolStripMenuItem val5 = Y1P5QR0nje(StringIdProvider.RestoreAllOriginalValues, null, OEc56nr2E3, yNJ5lDLxtk);
			ToolStripMenuItem val6 = Y1P5QR0nje(StringIdProvider.RestoreAllOriginalValues, null, OEc56nr2E3, yNJ5lDLxtk);
			ToolStripMenuItem val7 = Y1P5QR0nje(StringIdProvider.Refresh, null, OEc56nr2E3, null);
			ToolStripMenuItem val8 = Y1P5QR0nje(StringIdProvider.Refresh, null, OEc56nr2E3, null);
			ToolStripMenuItem val9 = Y1P5QR0nje(StringIdProvider.RefreshAll, null, OEc56nr2E3, L2a5xTjVO7);
			ToolStripMenuItem val10 = Y1P5QR0nje(StringIdProvider.RefreshItem, null, OEc56nr2E3, X0M5CCxdxG);
			ToolStripMenuItem val11 = Y1P5QR0nje(StringIdProvider.RefreshECM, null, ANJpdIBXUQ, Nxe50Ccbi4);
			ToolStripMenuItem val12 = Y1P5QR0nje(StringIdProvider.RefreshAll, null, OEc56nr2E3, L2a5xTjVO7);
			ToolStripMenuItem val13 = Y1P5QR0nje(StringIdProvider.RefreshItem, null, OEc56nr2E3, X0M5CCxdxG);
			ToolStripMenuItem val14 = Y1P5QR0nje(StringIdProvider.RefreshECM, null, ANJpdIBXUQ, Nxe50Ccbi4);
			ToolStripMenuItem val15 = Y1P5QR0nje(StringIdProvider.Find, null, OEc56nr2E3, z5G57JH07L);
			ToolStripMenuItem val16 = Y1P5QR0nje(StringIdProvider.SendTo, null, OEc56nr2E3, null);
			ToolStripMenuItem val17 = Y1P5QR0nje(StringIdProvider.SendToECM, null, OEc56nr2E3, hmA5qAlye4);
			ToolStripMenuItem val18 = Y1P5QR0nje(StringIdProvider.SendToPrinter, null, BnqpSLwyXX, UWK58GJYJA);
			ToolStripMenuItem val19 = Y1P5QR0nje(StringIdProvider.Expand, null, OEc56nr2E3, RLS5i6nLrP);
			ToolStripMenuItem val20 = Y1P5QR0nje(StringIdProvider.Collapse, null, OEc56nr2E3, S4h5gXVG2O);
			ToolStripMenuItem val21 = Y1P5QR0nje(StringIdProvider.RestoreOriginalValue, null, OEc56nr2E3, Fmi5j3vh7t);
			ToolStripMenuItem val22 = Y1P5QR0nje(StringIdProvider.Limits, null, vF2pHAZvej, gIe5OJs4f0);
			ToolStripSeparator val23 = new ToolStripSeparator();
			ToolStripSeparator val24 = new ToolStripSeparator();
			ToolStripSeparator val25 = new ToolStripSeparator();
			ToolStripSeparator val26 = new ToolStripSeparator();
			ToolStripSeparator val27 = new ToolStripSeparator();
			ToolStripSeparator val28 = new ToolStripSeparator();
			ToolStripSeparator val29 = new ToolStripSeparator();
			ToolStripSeparator val30 = new ToolStripSeparator();
			((ToolStripDropDownItem)val7).DropDownItems.AddRange((ToolStripItem[])(object)new ToolStripItem[3]
			{
				(ToolStripItem)val9,
				(ToolStripItem)val11,
				(ToolStripItem)val10
			});
			((ToolStripDropDownItem)val8).DropDownItems.AddRange((ToolStripItem[])(object)new ToolStripItem[3]
			{
				(ToolStripItem)val12,
				(ToolStripItem)val14,
				(ToolStripItem)val13
			});
			((ToolStripDropDownItem)val16).DropDownItems.AddRange((ToolStripItem[])(object)new ToolStripItem[2]
			{
				(ToolStripItem)val17,
				(ToolStripItem)val18
			});
			((ToolStrip)OWxpQ6pSJO).Items.AddRange((ToolStripItem[])(object)new ToolStripItem[9]
			{
				(ToolStripItem)val,
				(ToolStripItem)val2,
				(ToolStripItem)val23,
				(ToolStripItem)val3,
				(ToolStripItem)val4,
				(ToolStripItem)val24,
				(ToolStripItem)val6,
				(ToolStripItem)val25,
				(ToolStripItem)val7
			});
			((ToolStrip)IDhpKBhX27).Items.AddRange((ToolStripItem[])(object)new ToolStripItem[13]
			{
				(ToolStripItem)val15,
				(ToolStripItem)val26,
				(ToolStripItem)val16,
				(ToolStripItem)val27,
				(ToolStripItem)val19,
				(ToolStripItem)val20,
				(ToolStripItem)val28,
				(ToolStripItem)val21,
				(ToolStripItem)val5,
				(ToolStripItem)val29,
				(ToolStripItem)val8,
				(ToolStripItem)val30,
				(ToolStripItem)val22
			});
			VIapek5Ra3.Add(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11872), IDhpKBhX27);
			VIapek5Ra3.Add(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11888), OWxpQ6pSJO);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private ToolStripMenuItem Y1P5QR0nje(Enum P_0, CheckerCallback P_1, EnablerCallback P_2, EventHandler P_3)
		{
			//IL_001f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0025: Expected O, but got Unknown
			ToolStripMenuItemInfo toolStripMenuItemInfo = new ToolStripMenuItemInfo
			{
				Checker = P_1,
				Enabler = P_2
			};
			ToolStripMenuItem val = new ToolStripMenuItem();
			((ToolStripItem)val).Tag = toolStripMenuItemInfo;
			((ToolStripItem)val).Text = _stringProvider.GetLocalizedString(P_0);
			((ToolStripItem)val).Click += P_3;
			return val;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void jhb5KQgYbs(object P_0, EventArgs P_1)
		{
			DCq5EtK7kR();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void tgg5y8qVE6(object P_0, EventArgs P_1)
		{
			Soe51OtbJ3();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void d7p5JcgnZV(object P_0, EventArgs P_1)
		{
			base.FnpView.AutoSizeCol(qqbpkInfT6);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void wpF5FDAfcO(object P_0, EventArgs P_1)
		{
			base.FnpView.AutoSizeCols();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void yNJ5lDLxtk(object P_0, EventArgs P_1)
		{
			TJl5flnTDD();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void L2a5xTjVO7(object P_0, EventArgs P_1)
		{
			zD954yL3iO(true);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Nxe50Ccbi4(object P_0, EventArgs P_1)
		{
			r0752K4HRe(true);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void S4h5gXVG2O(object P_0, EventArgs P_1)
		{
			base.FnpView.PutRowCollapse(LxppusUOl4, isRowCollapse: true);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void z5G57JH07L(object P_0, EventArgs P_1)
		{
			RMB5tKGbhZ();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void hmA5qAlye4(object P_0, EventArgs P_1)
		{
			y825nkIZ9d();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void UWK58GJYJA(object P_0, EventArgs P_1)
		{
			OKX5ooF78f();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void RLS5i6nLrP(object P_0, EventArgs P_1)
		{
			base.FnpView.PutRowCollapse(LxppusUOl4, isRowCollapse: false);
			RsQ5ruJ36U(LxppusUOl4);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Fmi5j3vh7t(object P_0, EventArgs P_1)
		{
			sOf5mAD5n0();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void gIe5OJs4f0(object P_0, EventArgs P_1)
		{
			if (ElementRowStructureMap.ContainsKey(LxppusUOl4))
			{
				RowInformation rowInformation = ElementRowStructureMap[LxppusUOl4];
				switch (rowInformation.FnPElement.ValueType)
				{
				case FnPValueType.Long:
				case FnPValueType.Double:
				case FnPValueType.Float:
				case FnPValueType.RealTime:
				case FnPValueType.HHHHHHMM:
				case FnPValueType.MMSS:
					j3W5XCpFQh(rowInformation);
					break;
				case FnPValueType.None:
				case FnPValueType.Numeric:
				case FnPValueType.String:
				case FnPValueType.RealDate:
				case FnPValueType.NaturalNumber:
				case FnPValueType.Binary:
				case FnPValueType.List:
				case FnPValueType.Reset:
				case FnPValueType.Default:
				case FnPValueType.Unknown:
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void j3W5XCpFQh(RowInformation P_0)
		{
			//IL_0146: Unknown result type (might be due to invalid IL or missing references)
			FsBxoOdZLuBpT1arbh fsBxoOdZLuBpT1arbh = new FsBxoOdZLuBpT1arbh();
			fsBxoOdZLuBpT1arbh.I1NVV1wqdM(SS4phmddGR.GetContextSensitiveHelpProvider());
			string text = string.Empty;
			string text2 = string.Empty;
			string text3 = EQ45IXYf7O(P_0);
			string text4 = rW05uksPiF(P_0);
			if (RowType.Feature == P_0.RowType || RowType.SubFeature == P_0.RowType)
			{
				text = _stringProvider.GetLocalizedString(StringIdProvider.FeatureLimitsTitle);
				text2 = _stringProvider.GetLocalizedString(StringIdProvider.SelectedFeature);
			}
			else if (RowType.Parameter == P_0.RowType)
			{
				text = _stringProvider.GetLocalizedString(StringIdProvider.LimitsTitle);
				text2 = _stringProvider.GetLocalizedString(StringIdProvider.LimitsParamGroup);
			}
			fsBxoOdZLuBpT1arbh.wAeVNG5B9c(text, text2);
			fsBxoOdZLuBpT1arbh.waVVDKTlS3(_stringProvider.GetLocalizedString(StringIdProvider.MaxLimitGroup));
			fsBxoOdZLuBpT1arbh.LrQVdFjyY2(_stringProvider.GetLocalizedString(StringIdProvider.MinLimitGroup));
			fsBxoOdZLuBpT1arbh.FxYVHPR7OV(_stringProvider.GetLocalizedString(StringIdProvider.HelpButtonCaption));
			fsBxoOdZLuBpT1arbh.RjrV3OWPkc(P_0.FnPElement.FullName.Trim());
			fsBxoOdZLuBpT1arbh.xvDVS3oZLE(text3);
			fsBxoOdZLuBpT1arbh.wEAVGU0u9i(text4);
			? val = fsBxoOdZLuBpT1arbh;
			IFnPView fnpView = base.FnpView;
			((Form)val).ShowDialog((IWin32Window)((fnpView is IWin32Window) ? fnpView : null));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void X0M5CCxdxG(object P_0, EventArgs P_1)
		{
			ygypGk13E3(true);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPPresenter.AllowDisconnect(int cookie)
		{
			bool result = false;
			dWnpYjQ8oZ = false;
			try
			{
				if (SS4phmddGR.IsConnectionLost())
				{
					result = true;
					f9ipADcKnZ.Set();
				}
				else
				{
					iKmesffCZ(ref result);
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
			catch (COMException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception3);
			}
			finally
			{
				dWnpYjQ8oZ = true;
			}
			f9ipADcKnZ.WaitOne();
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPPresenter.CanCloseFnP()
		{
			bool result = false;
			try
			{
				iKmesffCZ(ref result);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
			catch (COMException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception3);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPPresenter.CanPrint()
		{
			return BnqpSLwyXX();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.CollapseAll()
		{
			try
			{
				Soe51OtbJ3();
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.ConManRefresh()
		{
			try
			{
				kCR5sDeYyM();
				zD954yL3iO(false);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.ConnectionEstablished(string connectionId, ConnectionStatusEnum status, ECMSERVICESAPILib.IDisconnectCallback callback)
		{
			if (string.IsNullOrEmpty(connectionId))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(11916), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12054));
			}
			try
			{
				if (status == ConnectionStatusEnum.ConnectionSuccessful)
				{
					XgApbm8i5Z(value: false);
					if (or0p8F3Pdx != null)
					{
						or0p8F3Pdx.Clear();
						or0p8F3Pdx = null;
					}
					fLE8xx2Fw(callback);
					yaipw9J3BE = connectionId;
					n5BpUAFLQd = UIState.Connected;
					R9XpMIjBHc = SS4phmddGR.GetConnectionType(yaipw9J3BE);
					IsConnectedToImage = R9XpMIjBHc == ConnectionType.Image;
					HasUserRights = SS4phmddGR.HasUserRights();
					EngineType engineType = SS4phmddGR.GetEngineType();
					string currentToolLevel = SS4phmddGR.GetCurrentToolLevel();
					mNh5R0kpVi(R9XpMIjBHc, engineType, currentToolLevel);
					if (base.FnpView != null && base.FnpView.IsVisible())
					{
						base.FnpView.Cursor = Cursors.WaitCursor;
						base.FnpView.RowsCount = 1;
						base.FnpView.AddItem(_stringProvider.GetLocalizedString(StringIdProvider.ReadingData));
						base.FnpView.SetValue(PropertyDescriptor.OutlineLevel, base.FnpView.RowsCount - 1, 0, 0);
						PwQpBrEhIB.Reset();
						UvjJ2wYjK();
					}
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.ConnectionTerminated(string connectionId)
		{
			n5BpUAFLQd = UIState.NoConnection;
			lock (ewMpqKX74K)
			{
				try
				{
					yaipw9J3BE = string.Empty;
					n5BpUAFLQd = UIState.NoConnection;
					IsConnectedToImage = false;
					SS4phmddGR.ClearDataOM();
					KajpIplcST.Clear();
					if (base.FnpView != null && base.FnpView.IsVisible())
					{
						PwQpBrEhIB.Set();
						SZ9T3bA1e();
						ElementRowStructureMap.Clear();
						ModuleIdParameterCountMap.Clear();
						base.FnpView.RowsCount = 1;
						base.FnpView.AddItem(_stringProvider.GetLocalizedString(StringIdProvider.NoECMConnected));
						base.FnpView.SetValue(PropertyDescriptor.OutlineLevel, base.FnpView.RowsCount - 1, 0, 0);
					}
					Twl55rds0w();
				}
				catch (ArgumentException exception)
				{
					FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
				}
				catch (InvalidOperationException exception2)
				{
					FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.ExpandAll()
		{
			try
			{
				DCq5EtK7kR();
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.Find()
		{
			try
			{
				RMB5tKGbhZ();
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.FindNext()
		{
			try
			{
				if (base.FnpView.IsVisible())
				{
					base.FnpView.Cursor = Cursors.WaitCursor;
					int currentRow = base.FnpView.CurrentRow;
					if (yrogoQc8b(ref currentRow))
					{
						oKwxensI6(currentRow);
						base.FnpView.CurrentRow = currentRow;
					}
					base.FnpView.Cursor = Cursors.Default;
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.GroupChanged(int groupNumber)
		{
			try
			{
				if (2 == groupNumber)
				{
					GridProperties gridProperties = base.FnpView.GridProperties;
					if (gridProperties != null)
					{
						base.FnpView.SetGridColumnWidth();
						base.FnpView.GridProperties = gridProperties;
					}
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.HandleDisconnect(int cookie)
		{
			try
			{
				lNAqu4EKH(cookie);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPPresenter.HasData()
		{
			return OEc56nr2E3();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.LoadFindDialog()
		{
			try
			{
				string empty = string.Empty;
				int plIndex = 0;
				empty = _stringProvider.GetLocalizedString(StringIdProvider.GridNameColumn);
				Jhbp0jg3fZ.AddFindIn(empty, out plIndex);
				empty = _stringProvider.GetLocalizedString(StringIdProvider.GridValueColumn);
				Jhbp0jg3fZ.AddFindIn(empty, out plIndex);
				empty = _stringProvider.GetLocalizedString(StringIdProvider.GridUnitsColumn);
				Jhbp0jg3fZ.AddFindIn(empty, out plIndex);
				empty = _stringProvider.GetLocalizedString(StringIdProvider.GridOriginalValueColumn);
				Jhbp0jg3fZ.AddFindIn(empty, out plIndex);
				Jhbp0jg3fZ.MatchCase = false;
				Jhbp0jg3fZ.DirectionDown = true;
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.PageSetUp()
		{
			try
			{
				base.FnpView.ShowPageSetupDialog();
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.PrepareView(int hwndParent)
		{
			try
			{
				IConfigService configService = SS4phmddGR.Kernel as IConfigService;
				base.FnpView = new FnPViewControl(hwndParent, configService);
				base.FnpView.Anchor = (AnchorStyles)15;
				Qyl5LQEKq8();
				NativeMethods.scLdwS2KT(base.FnpView.Handle, new IntPtr(hwndParent));
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.Print()
		{
			try
			{
				OKX5ooF78f();
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.PrintPreview()
		{
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				bool flag = false;
				FlexGridHelper flexGridHelper = new FlexGridHelperClass();
				if (!flexGridHelper.IsPrinterAvailable())
				{
					string localizedString = _stringProvider.GetLocalizedString(StringIdProvider.PrinterNotAvailableTitle);
					string localizedString2 = _stringProvider.GetLocalizedString(StringIdProvider.PrinterNotAvailableMessage);
					base.FnpView.DisplayMessage(localizedString2, localizedString, (MessageBoxButtons)0, (MessageBoxIcon)64);
				}
				else
				{
					PrintProperties printProperties = RV35za45pj();
					base.FnpView.ShowPrintPreviewDialog(printProperties);
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.ProcessViewMsg(int msg)
		{
			try
			{
				switch (msg)
				{
				case 5:
					vCM43Jii1();
					break;
				case 2:
					lMs2vAR4r();
					break;
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.RefreshAll()
		{
			try
			{
				zD954yL3iO(true);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.RefreshSelectedECM()
		{
			try
			{
				r0752K4HRe(true);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.RestoreAllOriginalValues()
		{
			try
			{
				TJl5flnTDD();
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.SendToECM()
		{
			try
			{
				y825nkIZ9d();
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.ToolLevelChanged(string toolLevel)
		{
			//IL_0133: Unknown result type (might be due to invalid IL or missing references)
			//IL_0138: Unknown result type (might be due to invalid IL or missing references)
			//IL_013b: Unknown result type (might be due to invalid IL or missing references)
			//IL_013d: Invalid comparison between I4 and Unknown
			try
			{
				if (UIState.Connected != n5BpUAFLQd && UIState.Populated != n5BpUAFLQd)
				{
					return;
				}
				SecurityLevel currentSecurityLevel = CurrentSecurityLevel;
				string currentToolLevel = SS4phmddGR.GetCurrentToolLevel();
				EngineType engineType = SS4phmddGR.GetEngineType();
				R9XpMIjBHc = SS4phmddGR.GetConnectionType(yaipw9J3BE);
				f6Ep744kDM = false;
				mNh5R0kpVi(R9XpMIjBHc, engineType, currentToolLevel);
				if (currentSecurityLevel == CurrentSecurityLevel || !base.FnpView.IsVisible())
				{
					return;
				}
				if (KajpIplcST.ModuleIdParamMap.Count > 0 && ((currentSecurityLevel > SecurityLevel.Basic && CurrentSecurityLevel == SecurityLevel.Basic) || (currentSecurityLevel > SecurityLevel.RSGR && CurrentSecurityLevel == SecurityLevel.RSGR) || (currentSecurityLevel > SecurityLevel.OBDRSGR && CurrentSecurityLevel == SecurityLevel.OBDRSGR) || (currentSecurityLevel > SecurityLevel.OBD && CurrentSecurityLevel == SecurityLevel.OBD) || (currentSecurityLevel > SecurityLevel.RSGRPlus && CurrentSecurityLevel == SecurityLevel.RSGRPlus)))
				{
					string localizedString = _stringProvider.GetLocalizedString(StringIdProvider.SendChangesMessage);
					string localizedString2 = _stringProvider.GetLocalizedString(StringIdProvider.InsiteTitle);
					DialogResult val = base.FnpView.DisplayMessage(localizedString, localizedString2, (MessageBoxButtons)4, (MessageBoxIcon)48);
					if (6 == (int)val)
					{
						if (y825nkIZ9d())
						{
							L7xKRSRQV();
						}
					}
					else
					{
						L7xKRSRQV();
					}
				}
				zD954yL3iO(false);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPPresenter.HandleConnectionRestablished()
		{
			if (X5opZTMfOn())
			{
				XgApbm8i5Z(value: false);
				jst5VmtRIf(or0p8F3Pdx);
			}
			if (SS4phmddGR.GetFnPDataObject() == null)
			{
				KajpIplcST.Clear();
				if (base.FnpView != null && base.FnpView.IsVisible())
				{
					PwQpBrEhIB.Set();
					SZ9T3bA1e();
					ElementRowStructureMap.Clear();
					ModuleIdParameterCountMap.Clear();
					base.FnpView.RowsCount = 1;
					base.FnpView.AddItem(_stringProvider.GetLocalizedString(StringIdProvider.ReadingData));
					base.FnpView.SetValue(PropertyDescriptor.OutlineLevel, base.FnpView.RowsCount - 1, 0, 0);
					f9ipADcKnZ.Reset();
					PwQpBrEhIB.Reset();
					ThreadPool.QueueUserWorkItem(SS4phmddGR.PrepareFnPDataObject);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void DCq5EtK7kR()
		{
			int rowsCount = base.FnpView.RowsCount;
			for (int i = 1; i < rowsCount; i++)
			{
				if (base.FnpView.GetRowCollapse(i))
				{
					if (ElementRowStructureMap.ContainsKey(i))
					{
						base.FnpView.PutRowCollapse(i, isRowCollapse: false);
					}
					else if (base.FnpView.GetRowNode(i).Level == 1 || base.FnpView.GetRowNode(i).Level == 0)
					{
						base.FnpView.PutRowCollapse(i, isRowCollapse: false);
					}
				}
			}
			nnL5vcie30();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Soe51OtbJ3()
		{
			int rowsCount = base.FnpView.RowsCount;
			for (int num = rowsCount - 1; num > 1; num--)
			{
				if (2 <= base.FnpView.GetRowOutlineLevel(num))
				{
					base.FnpView.PutRowCollapse(num, isRowCollapse: true);
				}
			}
			base.FnpView.HideTooltip();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void TJl5flnTDD()
		{
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0043: Unknown result type (might be due to invalid IL or missing references)
			//IL_0045: Unknown result type (might be due to invalid IL or missing references)
			//IL_0046: Invalid comparison between I4 and Unknown
			string localizedString = _stringProvider.GetLocalizedString(StringIdProvider.RestoreAllOriginalValuesTitle);
			string localizedString2 = _stringProvider.GetLocalizedString(StringIdProvider.RestoreAllOriginalValuesMessage);
			DialogResult val = base.FnpView.DisplayMessage(localizedString2, localizedString, (MessageBoxButtons)1, (MessageBoxIcon)32);
			if (1 == (int)val)
			{
				TgDQZNFek();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void sOf5mAD5n0()
		{
			base.FnpView.Cursor = Cursors.WaitCursor;
			if (ElementRowStructureMap.ContainsKey(LxppusUOl4))
			{
				RowInformation rowInformation = ElementRowStructureMap[LxppusUOl4];
				string text = rTxhtUKRm(rowInformation.FnPElement).ToString(CultureInfo.InvariantCulture);
				if (KajpIplcST.ContainsParameter(text, rowInformation.ModuleId))
				{
					IFnPElement fnPElement = rowInformation.FnPElement;
					if (fnPElement is IFeatureExclusiveFnPElement)
					{
						int result = 0;
						if (int.TryParse(text, out result) && !sQ05Mt8NvY(rowInformation, fnPElement.OriginalValue, LxppusUOl4, qqbpkInfT6))
						{
							return;
						}
					}
					fnPElement.ClearDesiredValue(int.Parse(text));
					fnPElement.Value = fnPElement.OriginalValue;
					fnPElement.OriginalValue = string.Empty;
					fnPElement.RefreshElement(updateBucket: true, readFromECM: false);
					inQ5Pg1v7Y(fnPElement.ImpactedParameters, rowInformation.ModuleId, false);
					KajpIplcST.RemoveParameter(rowInformation.ModuleId, text);
					rnI0VgnVO(fnPElement, LxppusUOl4);
					RsQ5ruJ36U(LxppusUOl4);
				}
			}
			base.FnpView.Cursor = Cursors.Default;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void zD954yL3iO(bool P_0)
		{
			base.FnpView.Cursor = Cursors.WaitCursor;
			SS4phmddGR.RefreshDataOM(P_0);
			nnL5vcie30();
			base.FnpView.Cursor = Cursors.Default;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void r0752K4HRe(bool P_0)
		{
			base.FnpView.Cursor = Cursors.WaitCursor;
			if (LxppusUOl4 > 1)
			{
				int num = LxppusUOl4;
				if (ElementRowStructureMap.ContainsKey(LxppusUOl4))
				{
					while (base.FnpView.GetRowNode(num).Level > 1)
					{
						num--;
					}
					num++;
				}
				else
				{
					num++;
				}
				int moduleId = ElementRowStructureMap[num].ModuleId;
				TDsl5ISil(moduleId, P_0);
			}
			base.FnpView.Cursor = Cursors.Default;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool OEc56nr2E3()
		{
			return n5BpUAFLQd == UIState.Populated;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool y825nkIZ9d()
		{
			//IL_016a: Unknown result type (might be due to invalid IL or missing references)
			//IL_008a: Unknown result type (might be due to invalid IL or missing references)
			//IL_008f: Invalid comparison between I4 and Unknown
			bool result = false;
			try
			{
				if (KajpIplcST.ModuleIdParamMap.Count > 0 && CurrentSecurityLevel != SecurityLevel.OBDRSGR && SecurityLevel.OBD != CurrentSecurityLevel && CurrentSecurityLevel != SecurityLevel.Basic)
				{
					if (SS4phmddGR.IsEngineIdle())
					{
						string localizedString = _stringProvider.GetLocalizedString(StringIdProvider.WriteConfirmTitle);
						string localizedString2 = _stringProvider.GetLocalizedString(StringIdProvider.WriteConfirmMessage);
						if (1 == (int)base.FnpView.DisplayMessage(localizedString2, localizedString, (MessageBoxButtons)1, (MessageBoxIcon)48))
						{
							if (UIState.Connected == n5BpUAFLQd || UIState.Populated == n5BpUAFLQd)
							{
								base.FnpView.Cursor = Cursors.WaitCursor;
								or0p8F3Pdx = SS4phmddGR.SendToECM(KajpIplcST.ModuleIdParamMap);
								base.FnpView.Cursor = Cursors.Default;
								if (UIState.Connected == n5BpUAFLQd || UIState.Populated == n5BpUAFLQd)
								{
									SS4phmddGR.ShowKeyOffMessage();
									if (!IsECMConnectionInterrupted)
									{
										jst5VmtRIf(or0p8F3Pdx);
										XgApbm8i5Z(value: false);
									}
									else
									{
										XgApbm8i5Z(value: true);
									}
								}
							}
						}
						else
						{
							result = true;
						}
					}
					else
					{
						base.FnpView.DisplayMessage(_stringProvider.GetLocalizedString(232), _stringProvider.GetLocalizedString(201), (MessageBoxButtons)0, (MessageBoxIcon)48);
					}
				}
			}
			catch (ECMServicesException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception);
				result = true;
				base.FnpView.Cursor = Cursors.Default;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void RMB5tKGbhZ()
		{
			if (!base.FnpView.IsVisible())
			{
				return;
			}
			base.FnpView.Cursor = Cursors.WaitCursor;
			int num = Jhbp0jg3fZ.DisplayModal(base.FnpView.Handle.ToInt32());
			if (1 == num)
			{
				int currentRow = base.FnpView.CurrentRow;
				if (yrogoQc8b(ref currentRow))
				{
					oKwxensI6(currentRow);
					base.FnpView.CurrentRow = currentRow;
				}
			}
			base.FnpView.Cursor = Cursors.Default;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void OKX5ooF78f()
		{
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			bool flag = false;
			FlexGridHelper flexGridHelper = new FlexGridHelperClass();
			if (!flexGridHelper.IsPrinterAvailable())
			{
				string localizedString = _stringProvider.GetLocalizedString(StringIdProvider.PrinterNotAvailableTitle);
				string localizedString2 = _stringProvider.GetLocalizedString(StringIdProvider.PrinterNotAvailableMessage);
				base.FnpView.DisplayMessage(localizedString2, localizedString, (MessageBoxButtons)0, (MessageBoxIcon)64);
			}
			else
			{
				PrintProperties printProperties = RV35za45pj();
				base.FnpView.PrintGrid(printProperties);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private PrintProperties RV35za45pj()
		{
			PrintProperties result = default(PrintProperties);
			n0hpal7Cv8(ref result);
			Kx0p5Tv1eh(ref result);
			O8Npp8sVO2(ref result);
			N4RpVe16re(ref result);
			Dpdp31NmKi(ref result);
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void n0hpal7Cv8(ref PrintProperties P_0)
		{
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(_stringProvider.GetLocalizedString(102));
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append(_stringProvider.GetLocalizedString(244));
			stringBuilder.Append(shwpDO1UjJ(1009));
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append(_stringProvider.GetLocalizedString(242));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12082));
			P_0.LeftHeader = stringBuilder.ToString();
			P_0.LeftFooter = DateTime.Now.ToLongTimeString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Kx0p5Tv1eh(ref PrintProperties P_0)
		{
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(_stringProvider.GetLocalizedString(241));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12090));
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append(_stringProvider.GetLocalizedString(239));
			stringBuilder.Append(shwpDO1UjJ(1011));
			P_0.CenterHeader = stringBuilder.ToString();
			P_0.CenterFooter = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12108);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void O8Npp8sVO2(ref PrintProperties P_0)
		{
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12142));
			stringBuilder.Append(MYtpNN90oC());
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append(_stringProvider.GetLocalizedString(240));
			stringBuilder.Append(shwpDO1UjJ(3003));
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append(_stringProvider.GetLocalizedString(243));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12160));
			P_0.RightHeader = stringBuilder.ToString();
			P_0.RightFooter = string.Format(CultureInfo.InvariantCulture, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12168), new object[1] { DateTime.Now });
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void N4RpVe16re(ref PrintProperties P_0)
		{
			//IL_0073: Unknown result type (might be due to invalid IL or missing references)
			//IL_007d: Expected O, but got Unknown
			using (RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12202)))
			{
				object value = registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12406));
				if (value != null)
				{
					int result = 0;
					int.TryParse(value.ToString(), out result);
					P_0.PrintFontSize = result;
				}
				else
				{
					P_0.PrintFontSize = 8;
				}
			}
			P_0.HeaderFooterFont = new Font(FontFamily.GenericMonospace, 8f);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void Dpdp31NmKi(ref PrintProperties P_0)
		{
			//IL_00af: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b9: Expected O, but got Unknown
			using RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12436));
			if (registryKey != null)
			{
				object value = registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12536));
				if (value != null)
				{
					int result = 0;
					int.TryParse(value.ToString(), out result);
					P_0.PaperSize = result;
				}
				value = registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12558));
				if (value != null)
				{
					int result2 = 0;
					int.TryParse(value.ToString(), out result2);
					P_0.PaperSource = result2;
				}
				value = registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12584));
				if (value != null)
				{
					int result3 = 0;
					int.TryParse(value.ToString(), out result3);
					P_0.Orientation = result3;
				}
				P_0.PrintPageMargins = new Margins();
				value = registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12610));
				int result4 = 0;
				if (value != null)
				{
					int.TryParse(value.ToString(), out result4);
					P_0.PrintPageMargins.Left = result4 / 10;
				}
				value = registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12634));
				result4 = 0;
				if (value != null)
				{
					int.TryParse(value.ToString(), out result4);
					P_0.PrintPageMargins.Right = result4 / 10;
				}
				value = registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12660));
				result4 = 0;
				if (value != null)
				{
					int.TryParse(value.ToString(), out result4);
					P_0.PrintPageMargins.Top = result4 / 10;
				}
				value = registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12682));
				result4 = 0;
				if (value != null)
				{
					int.TryParse(value.ToString(), out result4);
					P_0.PrintPageMargins.Bottom = result4 / 10;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string MYtpNN90oC()
		{
			string result = string.Empty;
			IVersionProvider versionProvider = new VersionProviderClass();
			if (versionProvider != null)
			{
				result = versionProvider.ToolVersionForDisplay;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string shwpDO1UjJ(int P_0)
		{
			string result = string.Empty;
			int parentModuleId = SS4phmddGR.GetParentModuleId();
			if (GdZIQGnD5(P_0, parentModuleId))
			{
				List<int> list = aMuYdtwDI(P_0, parentModuleId);
				if (list.Count > 0)
				{
					RowInformation rowInformation = ElementRowStructureMap[list[0]];
					result = rowInformation.FnPElement.Value;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool ANJpdIBXUQ()
		{
			if (base.NumberOfModules > 1)
			{
				return OEc56nr2E3();
			}
			return false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool vF2pHAZvej()
		{
			bool result = false;
			if (ElementRowStructureMap.ContainsKey(LxppusUOl4))
			{
				RowInformation rowInformation = ElementRowStructureMap[LxppusUOl4];
				if (rowInformation != null)
				{
					if (rowInformation.FnPElement.ReadBlocked)
					{
						result = false;
					}
					IFnPElement fnPElement = null;
					fnPElement = SS4phmddGR.GetParentFeatureElement(rowInformation.FnPElement);
					if (!rowInformation.FnPElement.ReadBlocked && rowInformation.FnPElement.Id > 0 && fnPElement.Id != 56 && !rowInformation.FnPElement.WriteBlocked && rowInformation.FnPElement.Writable)
					{
						switch (rowInformation.FnPElement.ValueType)
						{
						case FnPValueType.Long:
						case FnPValueType.Double:
						case FnPValueType.Float:
						case FnPValueType.RealTime:
						case FnPValueType.NaturalNumber:
						case FnPValueType.HHHHHHMM:
						case FnPValueType.MMSS:
							result = true;
							break;
						case FnPValueType.None:
						case FnPValueType.String:
						case FnPValueType.RealDate:
						case FnPValueType.List:
						case FnPValueType.Unknown:
							result = false;
							break;
						default:
							result = false;
							break;
						}
					}
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool BnqpSLwyXX()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ygypGk13E3(bool P_0)
		{
			if (ElementRowStructureMap.ContainsKey(LxppusUOl4))
			{
				RowInformation rowInformation = ElementRowStructureMap[LxppusUOl4];
				rowInformation.FnPElement.RefreshElement(updateBucket: true, P_0);
				inQ5Pg1v7Y(rowInformation.FnPElement.ImpactedParameters, rowInformation.ModuleId, P_0);
				RsQ5ruJ36U(LxppusUOl4);
			}
		}
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.Helper
{
	public class RowInformation
	{
		private RowType li6ptMB1Kw;

		private IFnPElement KrrpoVLm9b;

		private IconState K2mpz1ex5N;

		private string TBsVaddbkB;

		private int XWnV5PCBCM;

		private float uHkVpi2WOV;

		public float Precission
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return uHkVpi2WOV;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				uHkVpi2WOV = value;
			}
		}

		public int ModuleId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return XWnV5PCBCM;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				XWnV5PCBCM = value;
			}
		}

		public IconState IconState
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return K2mpz1ex5N;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				K2mpz1ex5N = value;
			}
		}

		public RowType RowType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return li6ptMB1Kw;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				li6ptMB1Kw = value;
			}
		}

		public IFnPElement FnPElement
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return KrrpoVLm9b;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				KrrpoVLm9b = value;
			}
		}

		public string EnumString
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return TBsVaddbkB;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				TBsVaddbkB = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public RowInformation()
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
		}
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.View
{
	public interface IFnPPrintView
	{
		void PerformTextPrinting(string csvFilePath, Stream printData);
	}
}
namespace W9sDiGH2Jt9mSGDUMX
{
	[Guid("FE2EE4B1-EB19-4048-A358-F77C152D12E0")]
	internal class FsBxoOdZLuBpT1arbh : Form, IHelpInformation
	{
		private IContextSensitiveHelpProvider pGKVP9s0Mq;

		private GroupBox etjVWaHyrh;

		private GroupBox UPpVv1m4AC;

		private GroupBox KNCVr3ustG;

		private Button Fv2V9d0jZl;

		private Button v6wVRdkuPF;

		private Label zTZVLw9F8w;

		private Label DbeVcSEmWP;

		private Label BJMVT40yDl;

		private IContainer D2UVYSJEf0;

		Guid IHelpInformation.GUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ((object)this).GetType().GUID;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FsBxoOdZLuBpT1arbh()
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			((Form)this)..ctor();
			LC1VsNJufu();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void I1NVV1wqdM(IContextSensitiveHelpProvider P_0)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12710), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12826));
			}
			pGKVP9s0Mq = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RjrV3OWPkc(string P_0)
		{
			((Control)zTZVLw9F8w).Text = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void wAeVNG5B9c(string P_0, string P_1)
		{
			((Control)this).Text = P_0;
			((Control)etjVWaHyrh).Text = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void waVVDKTlS3(string P_0)
		{
			((Control)UPpVv1m4AC).Text = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void LrQVdFjyY2(string P_0)
		{
			((Control)KNCVr3ustG).Text = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void FxYVHPR7OV(string P_0)
		{
			((Control)v6wVRdkuPF).Text = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void xvDVS3oZLE(string P_0)
		{
			((Control)DbeVcSEmWP).Text = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void wEAVGU0u9i(string P_0)
		{
			((Control)BJMVT40yDl).Text = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void guTVZGCglj(object P_0, EventArgs P_1)
		{
			((Form)this).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void wqVVbOoydu(object P_0, EventArgs P_1)
		{
			pGKVP9s0Mq.ShowHelp(this);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Dispose(bool P_0)
		{
			if (P_0 && D2UVYSJEf0 != null)
			{
				D2UVYSJEf0.Dispose();
			}
			((Form)this).Dispose(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void LC1VsNJufu()
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Expected O, but got Unknown
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			//IL_001d: Expected O, but got Unknown
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			//IL_0029: Unknown result type (might be due to invalid IL or missing references)
			//IL_0033: Expected O, but got Unknown
			//IL_0034: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Expected O, but got Unknown
			//IL_003f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0049: Expected O, but got Unknown
			//IL_004a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0054: Expected O, but got Unknown
			//IL_0055: Unknown result type (might be due to invalid IL or missing references)
			//IL_005f: Expected O, but got Unknown
			etjVWaHyrh = new GroupBox();
			zTZVLw9F8w = new Label();
			UPpVv1m4AC = new GroupBox();
			DbeVcSEmWP = new Label();
			KNCVr3ustG = new GroupBox();
			BJMVT40yDl = new Label();
			Fv2V9d0jZl = new Button();
			v6wVRdkuPF = new Button();
			((Control)etjVWaHyrh).SuspendLayout();
			((Control)UPpVv1m4AC).SuspendLayout();
			((Control)KNCVr3ustG).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)etjVWaHyrh).Controls.Add((Control)(object)zTZVLw9F8w);
			((Control)etjVWaHyrh).Location = new Point(12, 12);
			((Control)etjVWaHyrh).Name = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12854);
			((Control)etjVWaHyrh).Size = new Size(358, 100);
			((Control)etjVWaHyrh).TabIndex = 0;
			etjVWaHyrh.TabStop = false;
			((Control)etjVWaHyrh).Text = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12884);
			((Control)zTZVLw9F8w).Location = new Point(6, 16);
			((Control)zTZVLw9F8w).Name = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12924);
			((Control)zTZVLw9F8w).Size = new Size(346, 81);
			((Control)zTZVLw9F8w).TabIndex = 0;
			((Control)zTZVLw9F8w).Text = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12956);
			((Control)UPpVv1m4AC).Controls.Add((Control)(object)DbeVcSEmWP);
			((Control)UPpVv1m4AC).Location = new Point(12, 118);
			((Control)UPpVv1m4AC).Name = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(12988);
			((Control)UPpVv1m4AC).Size = new Size(358, 100);
			((Control)UPpVv1m4AC).TabIndex = 0;
			UPpVv1m4AC.TabStop = false;
			((Control)UPpVv1m4AC).Text = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13016);
			((Control)DbeVcSEmWP).Location = new Point(6, 16);
			((Control)DbeVcSEmWP).Name = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13046);
			((Control)DbeVcSEmWP).Size = new Size(346, 81);
			((Control)DbeVcSEmWP).TabIndex = 0;
			((Control)DbeVcSEmWP).Text = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13068);
			((Control)KNCVr3ustG).Controls.Add((Control)(object)BJMVT40yDl);
			((Control)KNCVr3ustG).Location = new Point(12, 224);
			((Control)KNCVr3ustG).Name = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13090);
			((Control)KNCVr3ustG).Size = new Size(358, 100);
			((Control)KNCVr3ustG).TabIndex = 0;
			KNCVr3ustG.TabStop = false;
			((Control)KNCVr3ustG).Text = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13118);
			((Control)BJMVT40yDl).Location = new Point(6, 16);
			((Control)BJMVT40yDl).Name = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13148);
			((Control)BJMVT40yDl).Size = new Size(346, 81);
			((Control)BJMVT40yDl).TabIndex = 0;
			((Control)BJMVT40yDl).Text = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13170);
			Fv2V9d0jZl.DialogResult = (DialogResult)2;
			((Control)Fv2V9d0jZl).Location = new Point(65, 330);
			((Control)Fv2V9d0jZl).Name = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13192);
			((Control)Fv2V9d0jZl).Size = new Size(75, 23);
			((Control)Fv2V9d0jZl).TabIndex = 1;
			((Control)Fv2V9d0jZl).Text = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13208);
			((ButtonBase)Fv2V9d0jZl).UseVisualStyleBackColor = true;
			((Control)Fv2V9d0jZl).Click += guTVZGCglj;
			((Control)v6wVRdkuPF).Location = new Point(229, 330);
			((Control)v6wVRdkuPF).Name = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13216);
			((Control)v6wVRdkuPF).Size = new Size(75, 23);
			((Control)v6wVRdkuPF).TabIndex = 2;
			((Control)v6wVRdkuPF).Text = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13236);
			((ButtonBase)v6wVRdkuPF).UseVisualStyleBackColor = true;
			((Control)v6wVRdkuPF).Click += wqVVbOoydu;
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Form)this).CancelButton = (IButtonControl)(object)Fv2V9d0jZl;
			((Form)this).ClientSize = new Size(382, 360);
			((Control)this).Controls.Add((Control)(object)v6wVRdkuPF);
			((Control)this).Controls.Add((Control)(object)Fv2V9d0jZl);
			((Control)this).Controls.Add((Control)(object)UPpVv1m4AC);
			((Control)this).Controls.Add((Control)(object)KNCVr3ustG);
			((Control)this).Controls.Add((Control)(object)etjVWaHyrh);
			((Form)this).FormBorderStyle = (FormBorderStyle)1;
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13248);
			((Form)this).ShowIcon = false;
			((Form)this).StartPosition = (FormStartPosition)1;
			((Control)this).Text = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13276);
			((Control)etjVWaHyrh).ResumeLayout(false);
			((Control)UPpVv1m4AC).ResumeLayout(false);
			((Control)KNCVr3ustG).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.View
{
	public interface IViewEventPublisher
	{
		event RowColEventHandler AfterCollapse;

		event RowColEventHandler AfterEdit;

		event RangeEventHandler AfterRowColChange;

		event RowColEventHandler BeforeCollapse;

		event RowColEventHandler BeforeEdit;

		event EventHandler ViewLoaded;

		event KeyPressEditEventHandler KeyPressEdit;

		event KeyEventHandler KeyDown;

		event KeyEventHandler KeyUp;

		event MouseEventHandler MouseDown;

		event MouseEventHandler MouseMove;

		event RowColEventHandler StartEdit;

		event ValidateEditEventHandler ValidateEdit;
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.Helper
{
	public class FnPAddInException : ApplicationException
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public FnPAddInException()
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FnPAddInException(string message)
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor(message);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FnPAddInException(string message, Exception innerException)
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor(message, innerException);
		}
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.Presenter
{
	public interface IPresenterEventListener
	{
		void IPresenterEventPublisher_MenuBarStateRefreshRequested(object sender, EventArgs e);

		void IPresenterEventPublisher_ToolBarStateRefreshRequested(object sender, EventArgs e);
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.Model.Tooltip
{
	public interface ITooltipProvider
	{
		string ProvideFeatureExclusiveTooltip(FeatureExclusiveTooltipInfo tooltipInfo);

		string ProvideLimitsTooltip(LimitsTooltipInfo tooltipInfo, IFnPElement element, ValidateLimit limit);

		string ProvideLockStateTooltip(LockStateTooltipInfo tooltipInfo, IFnPElement element);

		string ProvideInvalidValueTooltip(IFnPElement element);

		string ProvideInvalidValueTooltip(IFnPElement element, List<string> failedRules);
	}
}
namespace PaWVBLGVAj3mxwh9fZ
{
	internal class ldYfTuSS2jZcaCHFLr
	{
		private ECMDataReader PXyVq2ccTg;

		private wVU5sNcAu4EKHDLExx DPGV8QaUNf;

		private ILocalizedStringProvider ePtViX2kHB;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ldYfTuSS2jZcaCHFLr(ILocalizedStringProvider P_0, ECMDataReader P_1)
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
			PXyVq2ccTg = P_1;
			ePtViX2kHB = P_0;
			DPGV8QaUNf = new wVU5sNcAu4EKHDLExx(PXyVq2ccTg);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string KSXVIAV2DW(LockStateTooltipInfo P_0, IFnPElement P_1)
		{
			if (P_1 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13312), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13428));
			}
			return u5BVkipZt2(P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static int GP6VuVBDLo(IFnPElement P_0)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13446), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13570));
			}
			int num = 0;
			if (!(P_0 is IFeatureElement { EnableId: var enableId }))
			{
				return P_0.Id;
			}
			return enableId;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string u5BVkipZt2(LockStateTooltipInfo P_0, IFnPElement P_1)
		{
			if (P_1 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13588), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13722));
			}
			string result = string.Empty;
			string empty = string.Empty;
			int num = GP6VuVBDLo(P_1);
			empty = BMQVKUOO0B(P_0.ConnectionType);
			if (string.IsNullOrEmpty(empty))
			{
				empty = wSEVyIPPRa(P_0.CurrentSecurityLevel, P_0.PreviousLevel);
				if (string.IsNullOrEmpty(empty))
				{
					empty = qnaVQkT1xl(P_0.HasUserRights);
					if (string.IsNullOrEmpty(empty))
					{
						empty = BgrVJ6ClNi(P_0.PasswordLevel, P_1);
						if (string.IsNullOrEmpty(empty))
						{
							empty = UBmVFbCjUJ(P_0.IsOEMAvailable, P_0.IsOEM2Available, P_1);
							if (string.IsNullOrEmpty(empty))
							{
								empty = mA5Vlmrfv7(P_0.CurrentSecurityLevel, P_1);
								if (string.IsNullOrEmpty(empty))
								{
									empty = uM6VhCwRCx(P_1);
									if (string.IsNullOrEmpty(empty))
									{
										empty = vvNVeVBjvS(P_1, P_0.ElementType);
										if (string.IsNullOrEmpty(empty))
										{
											empty = ipAVAFwucm(P_1, P_0.DetectType);
											if (string.IsNullOrEmpty(empty))
											{
												empty = CndVwxYKBP(num, P_1, TooltipQueryType.LockstateTooltipQuery);
												if (string.IsNullOrEmpty(empty))
												{
													empty = DNoVU2stT3(P_1, TooltipQueryType.LockstateTooltipQuery);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			if (!string.IsNullOrEmpty(empty))
			{
				result = YmEVxtsK7a(P_0.ElementType, P_1);
				result += Environment.NewLine;
				result += empty;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected string DNoVU2stT3(IFnPElement P_0, TooltipQueryType P_1)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13740), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13884));
			}
			int num = GP6VuVBDLo(P_0);
			StringBuilder stringBuilder = new StringBuilder();
			List<string> dependantParameterList = PXyVq2ccTg.GetDependantParameterList(num.ToString(CultureInfo.InvariantCulture), P_0.ModuleId.ToString(CultureInfo.InvariantCulture));
			foreach (string item in dependantParameterList)
			{
				string empty = string.Empty;
				try
				{
					empty = cPVV7VueFQ(num, item);
					if (string.IsNullOrEmpty(empty))
					{
						int result = 0;
						if (int.TryParse(item, out result))
						{
							empty = CndVwxYKBP(result, P_0, P_1);
							if (string.IsNullOrEmpty(empty))
							{
								empty = PXyVq2ccTg.GetParameterFullName(P_0.ModuleId, item) + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13902) + PXyVq2ccTg.GetDisplayValueForTooltip(item, P_0.ModuleId.ToString(CultureInfo.InvariantCulture));
							}
						}
					}
					stringBuilder.Append(empty);
					stringBuilder.Append(Environment.NewLine);
				}
				catch (ArgumentException exception)
				{
					FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.LockStateTooltip, exception);
				}
				catch (InvalidOperationException exception2)
				{
					FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.LockStateTooltip, exception2);
				}
				catch (ECMDataReaderException exception3)
				{
					FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.LockStateTooltip, exception3);
				}
			}
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected string XZtVMDLig0(IFnPElement P_0, List<string> failedTokens, TooltipQueryType P_2)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(13912), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(14056));
			}
			int num = GP6VuVBDLo(P_0);
			StringBuilder stringBuilder = new StringBuilder();
			foreach (string failedToken in failedTokens)
			{
				string empty = string.Empty;
				try
				{
					empty = cPVV7VueFQ(num, failedToken);
					if (string.IsNullOrEmpty(empty))
					{
						int result = 0;
						if (int.TryParse(failedToken, out result))
						{
							empty = CndVwxYKBP(result, P_0, P_2);
							if (string.IsNullOrEmpty(empty))
							{
								empty = PXyVq2ccTg.GetParameterFullName(P_0.ModuleId, failedToken) + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(14074) + PXyVq2ccTg.GetDisplayValueForTooltip(failedToken, P_0.ModuleId.ToString(CultureInfo.InvariantCulture));
							}
						}
					}
					stringBuilder.Append(empty);
					stringBuilder.Append(Environment.NewLine);
				}
				catch (ArgumentException exception)
				{
					FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.LockStateTooltip, exception);
				}
				catch (InvalidOperationException exception2)
				{
					FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.LockStateTooltip, exception2);
				}
				catch (ECMDataReaderException exception3)
				{
					FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.LockStateTooltip, exception3);
				}
			}
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string CndVwxYKBP(int P_0, IFnPElement P_1, TooltipQueryType P_2)
		{
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(14084), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(14214));
			}
			string result = string.Empty;
			if (EWgfmqubhLleaa6sgy.xQnd1Hm8Bf(P_0, P_2, LimitsTooltipType.None))
			{
				string text = EWgfmqubhLleaa6sgy.BxRdfQETf4(P_0, P_2);
				result = DPGV8QaUNf.JvINejk1WK(text, P_1, P_2);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string uM6VhCwRCx(IFnPElement P_0)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(14240), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(14368));
			}
			L7xRSRrQV7r2Ivaea2 l7xRSRrQV7r2Ivaea = new L7xRSRrQV7r2Ivaea2(ePtViX2kHB);
			return l7xRSRrQV7r2Ivaea.Vag3uk7LtC(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string ipAVAFwucm(IFnPElement P_0, int P_1)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(14386), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(14522));
			}
			string result = string.Empty;
			if (P_0.GtisLocked)
			{
				result = Bj3VBN2Bj6(P_0, P_1);
				result += ePtViX2kHB.GetLocalizedString(StringIdProvider.UserSelectableLockedTooltip);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string Bj3VBN2Bj6(IFnPElement P_0, int P_1)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(14540), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(14676));
			}
			string result = string.Empty;
			if (P_0 is IFeature)
			{
				result = P_0.Name;
			}
			else if (P_0 is Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameter)
			{
				IFeatureElement parent = (P_0 as Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameter).Parent;
				result = ((parent.EnableId != 0 && parent.GtisId != 0) ? ((parent.Id >= 99) ? parent.Name : (P_0 as Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameter).Name) : Bj3VBN2Bj6(parent, P_1));
			}
			else if (P_0 is ISubFeature)
			{
				result = (((P_0 as ISubFeature).EnableId == 0) ? Bj3VBN2Bj6((P_0 as ISubFeature).ParentFeature, P_1) : (((P_0 as ISubFeature).GtisId != (P_0 as ISubFeature).ParentFeature.GtisId && (P_0 as ISubFeature).GtisId != 0) ? P_0.Name : Bj3VBN2Bj6((P_0 as ISubFeature).ParentFeature, P_1)));
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string vvNVeVBjvS(IFnPElement P_0, RowType P_1)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(14694), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(14826));
			}
			string result = string.Empty;
			if (RowType.Feature == P_1)
			{
				if (!P_0.HasUsage(UsageType.AdjustableFeatures) || !P_0.Writable)
				{
					result = ePtViX2kHB.GetLocalizedString(StringIdProvider.ReadOnlyTooltip);
				}
			}
			else if ((RowType.SubFeature == P_1 || RowType.Parameter == P_1) && (!P_0.HasUsage(UsageType.AdjustableSubFeaturesAndParameters) || !P_0.Writable))
			{
				result = ePtViX2kHB.GetLocalizedString(StringIdProvider.ReadOnlyTooltip);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string qnaVQkT1xl(bool P_0)
		{
			string result = string.Empty;
			if (!P_0)
			{
				result = ePtViX2kHB.GetLocalizedString(StringIdProvider.UserRightsTooltip);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string BMQVKUOO0B(Cummins.Insite.AddIns.FeaturesAndParameters.ConnectionType P_0)
		{
			string result = string.Empty;
			if (Cummins.Insite.AddIns.FeaturesAndParameters.ConnectionType.Image == P_0)
			{
				result = ePtViX2kHB.GetLocalizedString(StringIdProvider.ConnectedToECMImageTooltip);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string wSEVyIPPRa(SecurityLevel P_0, bool P_1)
		{
			string result = string.Empty;
			if (P_0 == SecurityLevel.Basic && P_1)
			{
				result = ePtViX2kHB.GetLocalizedString(StringIdProvider.AutomotiveToolLevelTooltip);
			}
			else if (SecurityLevel.Basic >= P_0)
			{
				result = ePtViX2kHB.GetLocalizedString(StringIdProvider.BasicToolLevelTooltip);
			}
			else if (SecurityLevel.OBD == P_0 || SecurityLevel.OBDRSGR == P_0)
			{
				result = ePtViX2kHB.GetLocalizedString(StringIdProvider.LowToolLevelTooltip);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string BgrVJ6ClNi(ECMPasswordType P_0, IFnPElement P_1)
		{
			if (P_1 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(14844), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(14996));
			}
			string result = string.Empty;
			bool flag = false;
			if (P_1 is Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameter)
			{
				flag = P_1.HasUsage(UsageType.ResetParameters);
			}
			if (!flag && ECMPasswordType.Master != P_0 && ECMPasswordType.Adjustment != P_0)
			{
				result = ePtViX2kHB.GetLocalizedString(StringIdProvider.PasswordLockedTooltip);
			}
			else if (flag && ECMPasswordType.Master != P_0 && ECMPasswordType.Reset != P_0)
			{
				result = ePtViX2kHB.GetLocalizedString(StringIdProvider.ResetPasswordLockedTooltip);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string UBmVFbCjUJ(bool P_0, bool P_1, IFnPElement P_2)
		{
			if (P_2 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(15014), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(15156));
			}
			string result = string.Empty;
			if (P_2.HasUsage(UsageType.OEMProtectedParameters) && !P_0)
			{
				result = ePtViX2kHB.GetLocalizedString(StringIdProvider.OEMLockedTooltip);
			}
			else if (P_2.HasUsage(UsageType.OEM2ProtectedParameters) && !P_1)
			{
				result = ePtViX2kHB.GetLocalizedString(StringIdProvider.OEM2LockedTooltip);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string mA5Vlmrfv7(SecurityLevel P_0, IFnPElement P_1)
		{
			if (P_1 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(15174), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(15318));
			}
			string result = string.Empty;
			if (P_1.HasUsage(UsageType.RSGRParameters) && (SecurityLevel.RSGR == P_0 || SecurityLevel.RSGRPlus == P_0))
			{
				result = ePtViX2kHB.GetLocalizedString(StringIdProvider.RSGRLockedTooltip);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string YmEVxtsK7a(RowType P_0, IFnPElement P_1)
		{
			if (P_1 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(15336), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(15464));
			}
			string result = string.Empty;
			if (RowType.Feature == P_0 || RowType.SubFeature == P_0)
			{
				result = FAyV07GrW7(P_1);
			}
			else if (RowType.Parameter == P_0)
			{
				result = RpmVgWHmDr(P_1);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string FAyV07GrW7(IFnPElement P_0)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(15482), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(15624));
			}
			string empty = string.Empty;
			if (P_0.ReadBlocked)
			{
				return ePtViX2kHB.GetLocalizedString(StringIdProvider.FeatureReadBlockedTooltip);
			}
			return ePtViX2kHB.GetLocalizedString(StringIdProvider.FeatureTooltipHeader);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string RpmVgWHmDr(IFnPElement P_0)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(15642), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(15788));
			}
			string empty = string.Empty;
			if (P_0.ReadBlocked)
			{
				return ePtViX2kHB.GetLocalizedString(StringIdProvider.ParameterReadBlockedTooltip);
			}
			return ePtViX2kHB.GetLocalizedString(StringIdProvider.ParameterTooltipHeader);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string cPVV7VueFQ(int P_0, string P_1)
		{
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(15806), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(15966));
			}
			if (string.IsNullOrEmpty(P_1))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(15992), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16152));
			}
			string empty = string.Empty;
			L7xRSRrQV7r2Ivaea2 l7xRSRrQV7r2Ivaea = new L7xRSRrQV7r2Ivaea2(ePtViX2kHB);
			return l7xRSRrQV7r2Ivaea.sdp3kIlQRw(P_0, int.Parse(P_1));
		}
	}
}
namespace CGnD5VbQPNAYMkBriD
{
	internal class p3bA1eZ5MudtwDIldZ : ldYfTuSS2jZcaCHFLr
	{
		private ECMDataReader KeSVXvSMSZ;

		private ILocalizedStringProvider oVWVCWXoP1;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public p3bA1eZ5MudtwDIldZ(ILocalizedStringProvider P_0, ECMDataReader P_1)
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor(P_0, P_1);
			KeSVXvSMSZ = P_1;
			oVWVCWXoP1 = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string nMUVjbe4x4(IFnPElement P_0)
		{
			StringBuilder stringBuilder = new StringBuilder();
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16184), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16304));
			}
			stringBuilder.Append(oVWVCWXoP1.GetLocalizedString(StringIdProvider.InvalidValueTooltipHeader));
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append(DNoVU2stT3(P_0, TooltipQueryType.InvalidvalueTooltipQuery));
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string IIMVOm6eTb(IFnPElement P_0, List<string> failedTokens)
		{
			StringBuilder stringBuilder = new StringBuilder();
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16322), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16442));
			}
			stringBuilder.Append(oVWVCWXoP1.GetLocalizedString(StringIdProvider.InvalidValueTooltipHeader));
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append(XZtVMDLig0(P_0, failedTokens, TooltipQueryType.InvalidvalueTooltipQuery));
			return stringBuilder.ToString();
		}
	}
}
namespace DmTyxpPpKrTZcTxtUK
{
	internal class utJYLrsC7XmAim2WsS
	{
		private ILocalizedStringProvider CyfV1SLFqp;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public utJYLrsC7XmAim2WsS(ILocalizedStringProvider P_0)
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
			CyfV1SLFqp = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string UO4VEqxj54(FeatureExclusiveTooltipInfo P_0)
		{
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(CyfV1SLFqp.GetLocalizedString(StringIdProvider.FeatureExclusivityTooltip));
			foreach (string key in P_0.FEPararmeterMap.Keys)
			{
				stringBuilder.Append(Environment.NewLine);
				stringBuilder.Append(key.Trim());
				stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16460));
				stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16466));
				stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16472));
				stringBuilder.Append(P_0.FEPararmeterMap[key].Trim());
			}
			return stringBuilder.ToString();
		}
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.Model
{
	[CLSCompliant(false)]
	public interface IFnPModel
	{
		ECMDataReader ECMDataReader { get; }

		object Kernel { get; }

		ITooltipProvider TooltipProvider { get; }

		void ClearDataOM();

		IContextSensitiveHelpProvider GetContextSensitiveHelpProvider();

		[CLSCompliant(false)]
		ICommunicationsLock GetCommunicationLock();

		ConnectionType GetConnectionType(string connectionId);

		ECMPasswordType GetCurrentPasswordLevel();

		string GetCurrentToolLevel();

		EngineType GetEngineType();

		IFeaturesAndParametersDataOM GetFnPDataObject();

		float GetPrecission(IFnPElement element, int moduleType);

		bool HasUserRights();

		void Initialize(object kernel, object shell);

		bool IsEngineIdle();

		bool IsOEMAvailable();

		bool IsOEM2Available();

		void PrepareFnPDataObject(object value);

		void PrepareFnPPrintDataObject(object kernel, string connectionId, int featureID);

		void RefreshDataOM(bool readFromECM);

		void RefreshModule(int selectedModuleId, bool readFromECM);

		Dictionary<int, List<string>> SendToECM(Dictionary<int, Dictionary<string, object>> moduleIdMap);

		void ShowKeyOffMessage();

		int GetParentModuleId();

		bool IsConnectionLost();

		int GetDecimalPrecission(int parameterId, int moduleType);

		object GetRawValueFromDisplayValue(string parameterId, string displayValue, string moduleID);

		IFnPElement GetParentFeatureElement(IFnPElement element);

		List<string> CheckFnPRules(IFnPElement element);
	}
	public interface IModelEventPublisher
	{
		event EventHandler FeatureDataAvailable;

		event EventHandler ErrorInFnPModel;
	}
	public sealed class FnPModel : IFnPModel, IModelEventPublisher
	{
		private ECMDataReader Ksv3dcFYve;

		private EventHandler Rdy3HJIkKD;

		private EventHandler Pm73SuxgrJ;

		private IFeaturesAndParametersDataOM XJP3GisQ4E;

		private object sWd3ZxiCXv;

		private object D783bsomAJ;

		private ToolSecurity LnY3smVfA0;

		private ITooltipProvider dUl3PUoh2G;

		private object Uux3W8ktKM;

		ECMDataReader IFnPModel.ECMDataReader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Ksv3dcFYve;
			}
		}

		ITooltipProvider IFnPModel.TooltipProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return dUl3PUoh2G;
			}
		}

		object IFnPModel.Kernel
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return sWd3ZxiCXv;
			}
		}

		private event EventHandler eiq3pkg09t
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler eventHandler = Rdy3HJIkKD;
				EventHandler eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref Rdy3HJIkKD, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler eventHandler = Rdy3HJIkKD;
				EventHandler eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref Rdy3HJIkKD, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		private event EventHandler qih3DfwufX
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler eventHandler = Pm73SuxgrJ;
				EventHandler eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref Pm73SuxgrJ, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler eventHandler = Pm73SuxgrJ;
				EventHandler eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref Pm73SuxgrJ, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		event EventHandler IModelEventPublisher.FeatureDataAvailable
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				eiq3pkg09t += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				eiq3pkg09t -= value;
			}
		}

		event EventHandler IModelEventPublisher.ErrorInFnPModel
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				qih3DfwufX += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				qih3DfwufX -= value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FnPModel(ToolSecurity toolSecurity)
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			Uux3W8ktKM = new object();
			base..ctor();
			LnY3smVfA0 = toolSecurity;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPModel.ClearDataOM()
		{
			lock (Uux3W8ktKM)
			{
				try
				{
					((IDisposable)XJP3GisQ4E).Dispose();
					XJP3GisQ4E = null;
				}
				catch (InvalidOperationException exception)
				{
					FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		IContextSensitiveHelpProvider IFnPModel.GetContextSensitiveHelpProvider()
		{
			IContextSensitiveHelpProvider contextSensitiveHelpProvider = Factory.CreateInstance<IContextSensitiveHelpProvider>();
			contextSensitiveHelpProvider.Initialize(sWd3ZxiCXv, D783bsomAJ);
			return contextSensitiveHelpProvider;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		ICommunicationsLock IFnPModel.GetCommunicationLock()
		{
			ICommunicationsLock result = null;
			try
			{
				ECMSERVICESAPILib.IECMServices iECMServices = (ECMSERVICESAPILib.IECMServices)sWd3ZxiCXv;
				string activeConnectionID = iECMServices.ActiveConnectionID;
				ECMSERVICESAPILib.IConnection connection = iECMServices.Connections.get_Item((object)activeConnectionID);
				if (connection != null)
				{
					ECMSERVICESAPILib.ISystem system = connection.System;
					if (system != null)
					{
						result = system.CommunicationsLock;
					}
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
			catch (COMException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception3);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		ConnectionType IFnPModel.GetConnectionType(string connectionId)
		{
			if (string.IsNullOrEmpty(connectionId))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16478), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16608));
			}
			ConnectionType result = ConnectionType.None;
			try
			{
				if (!string.IsNullOrEmpty(connectionId))
				{
					ECMSERVICESAPILib.IECMServices iECMServices = (ECMSERVICESAPILib.IECMServices)sWd3ZxiCXv;
					ECMSERVICESAPILib.IConnection connection = iECMServices.Connections.get_Item((object)connectionId);
					if (connection != null)
					{
						result = connection.type switch
						{
							ConnectionTypesEnum.CT_Image => ConnectionType.Image, 
							ConnectionTypesEnum.CT_PCL_PJ1939 => ConnectionType.PCLJ1939, 
							ConnectionTypesEnum.CT_PCL_UDS => ConnectionType.PCLUDS, 
							ConnectionTypesEnum.CT_Physical => ConnectionType.Physical, 
							ConnectionTypesEnum.CT_Simulator => ConnectionType.Simulator, 
							_ => ConnectionType.None, 
						};
					}
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
			catch (COMException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception3);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		ECMPasswordType IFnPModel.GetCurrentPasswordLevel()
		{
			ECMPasswordType result = ECMPasswordType.None;
			try
			{
				if (SN1V4AoVcr(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16636)))
				{
					result = ECMPasswordType.Master;
				}
				else
				{
					bool flag = SN1V4AoVcr(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16672));
					bool flag2 = SN1V4AoVcr(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16718));
					result = ((flag && flag2) ? ECMPasswordType.Master : (flag ? ECMPasswordType.Adjustment : (flag2 ? ECMPasswordType.Reset : ECMPasswordType.None)));
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		string IFnPModel.GetCurrentToolLevel()
		{
			string result = string.Empty;
			try
			{
				IToolLevelRegistration toolLevelRegistration = (IToolLevelRegistration)sWd3ZxiCXv;
				result = toolLevelRegistration.GetCurrentToolLevel();
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
			catch (COMException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception3);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		EngineType IFnPModel.GetEngineType()
		{
			EngineType result = EngineType.None;
			try
			{
				result = ((int.Parse(Ksv3dcFYve.GetRawValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16752), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16762)), CultureInfo.InvariantCulture) == 0) ? EngineType.Automotive : EngineType.Industrial);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
			catch (ECMDataReaderException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception3);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		IFeaturesAndParametersDataOM IFnPModel.GetFnPDataObject()
		{
			return XJP3GisQ4E;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		float IFnPModel.GetPrecission(IFnPElement element, int moduleType)
		{
			if (element == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16768), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16890));
			}
			float result = 0f;
			try
			{
				ECMSERVICESAPILib.IECMServices iECMServices = (ECMSERVICESAPILib.IECMServices)sWd3ZxiCXv;
				int num = dboVmB9XR4(element);
				ECMSERVICESAPILib.IParameterDefinition parameterDefinition = iECMServices.ParameterDefinitions.GetParameterDefinition(num.ToString(CultureInfo.InvariantCulture), moduleType);
				if (parameterDefinition != null)
				{
					result = parameterDefinition.Precision;
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
			catch (COMException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception3);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPModel.HasUserRights()
		{
			bool result = true;
			try
			{
				result = SN1V4AoVcr(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16906));
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPModel.IsEngineIdle()
		{
			bool result = false;
			try
			{
				ECMSERVICESAPILib.IECMServices iECMServices = (ECMSERVICESAPILib.IECMServices)sWd3ZxiCXv;
				Cummins.INSITE.Kernel.ECMServicesAPI.IECMServices iECMServices2 = (Cummins.INSITE.Kernel.ECMServicesAPI.IECMServices)iECMServices;
				int num = 0;
				if (K69Vo5VSDj(iECMServices2.Connections, Convert.ToInt32(iECMServices.ActiveConnectionID)))
				{
					Cummins.INSITE.Kernel.ECMServicesAPI.IDataServices dataServices = iECMServices2.DataServices;
					ISystemDataService systemDataService = dataServices.AddSystemDataService(Convert.ToInt32(iECMServices.ActiveConnectionID));
					Cummins.INSITE.Kernel.ECMServicesAPI.IParameter parameter = systemDataService.ReadParameter(Convert.ToInt32(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16940)));
					num = int.Parse(parameter.RawValue.ToString(), CultureInfo.InvariantCulture);
				}
				else
				{
					num = int.Parse(Ksv3dcFYve.GetRawValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16946), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16952)), CultureInfo.InvariantCulture);
				}
				if (num == 0)
				{
					result = true;
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
			catch (ECMDataReaderException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception3);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPModel.IsOEMAvailable()
		{
			bool result = true;
			try
			{
				result = SN1V4AoVcr(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16958));
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPModel.IsOEM2Available()
		{
			bool result = true;
			try
			{
				result = SN1V4AoVcr(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(16988));
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPModel.PrepareFnPDataObject(object value)
		{
			lock (Uux3W8ktKM)
			{
				try
				{
					if (XJP3GisQ4E == null)
					{
						XJP3GisQ4E = new FeaturesAndParametersDataOM(sWd3ZxiCXv);
						Ksv3dcFYve.FnpDataOM = XJP3GisQ4E;
						XJP3GisQ4E.PopulateData(FeatureIdentifier.All);
					}
					else
					{
						XJP3GisQ4E.RefreshDataOM(readFromECM: false);
					}
					iBPV2jeCE0();
				}
				catch (ECMServicesException ex)
				{
					if (ex.ErrorCode != ECMServicesErrorCodes.DatalinkTimeout && ex.ErrorCode != ECMServicesErrorCodes.DatalinkError)
					{
						return;
					}
					lock (Uux3W8ktKM)
					{
						try
						{
							((IDisposable)XJP3GisQ4E).Dispose();
							XJP3GisQ4E = null;
						}
						catch (InvalidOperationException exception)
						{
							FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
						}
					}
				}
				catch (ArgumentException exception2)
				{
					V9mV6INqmb();
					FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
				}
				catch (InvalidOperationException exception3)
				{
					V9mV6INqmb();
					FnPTraceLoger.TryLog(LogCategory.FnPModel, exception3);
				}
				catch (COMException exception4)
				{
					V9mV6INqmb();
					FnPTraceLoger.TryLog(LogCategory.FnPModel, exception4);
				}
				catch (Exception exception5)
				{
					V9mV6INqmb();
					FnPTraceLoger.TryLog(LogCategory.FnPModel, exception5);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPModel.PrepareFnPPrintDataObject(object kernel, string connectionId, int featureID)
		{
			if (kernel == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(17020), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(17166));
			}
			if (string.IsNullOrEmpty(connectionId))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(17182), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(17328));
			}
			try
			{
				if (XJP3GisQ4E == null)
				{
					XJP3GisQ4E = new FeaturesAndParametersDataOM(kernel, connectionId);
					if (featureID == -1)
					{
						XJP3GisQ4E.PopulateData(FeatureIdentifier.All);
					}
					else
					{
						XJP3GisQ4E.PopulateData((FeatureIdentifier)featureID);
					}
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPModel.RefreshDataOM(bool readFromECM)
		{
			try
			{
				XJP3GisQ4E.RefreshDataOM(readFromECM);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPModel.RefreshModule(int selectedModuleID, bool readFromECM)
		{
			try
			{
				XJP3GisQ4E.RefreshModule(selectedModuleID, readFromECM);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		Dictionary<int, List<string>> IFnPModel.SendToECM(Dictionary<int, Dictionary<string, object>> moduleIdMap)
		{
			if (moduleIdMap == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(17356), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(17470));
			}
			Dictionary<int, List<string>> dictionary = new Dictionary<int, List<string>>();
			try
			{
				foreach (int key in moduleIdMap.Keys)
				{
					List<string> list = new List<string>();
					try
					{
						ReadOnlyCollection<string> readOnlyCollection = XJP3GisQ4E.PerformWrite(key, moduleIdMap[key]);
						if (readOnlyCollection != null && readOnlyCollection.Count > 0)
						{
							foreach (string item in readOnlyCollection)
							{
								list.Add(item);
							}
						}
					}
					catch (COMException exception)
					{
						list = BhAVfpnvKR(key, moduleIdMap[key]);
						FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
					}
					if (list == null || list.Count <= 0)
					{
						continue;
					}
					foreach (string item2 in list)
					{
						if (dictionary.ContainsKey(key))
						{
							dictionary[key].Add(item2);
							continue;
						}
						dictionary.Add(key, new List<string>());
						dictionary[key].Add(item2);
					}
				}
			}
			catch (ArgumentException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
			catch (InvalidOperationException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception3);
			}
			return dictionary;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPModel.ShowKeyOffMessage()
		{
			try
			{
				IAddInFactory addInFactory = (IAddInFactory)sWd3ZxiCXv;
				((IConManWorker)addInFactory.get_Item(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(17496)))?.ShowKeyMessage(30);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
			catch (COMException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception3);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPModel.Initialize(object kernel, object shell)
		{
			if (kernel == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(17576), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(17692));
			}
			if (shell == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(17708), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(17824));
			}
			sWd3ZxiCXv = kernel;
			D783bsomAJ = shell;
			Ksv3dcFYve = new ECMDataReader(sWd3ZxiCXv);
			dUl3PUoh2G = new TooltipProvider(Ksv3dcFYve);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		int IFnPModel.GetParentModuleId()
		{
			return XJP3GisQ4E.Modules[0].Id;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPModel.IsConnectionLost()
		{
			bool result = false;
			try
			{
				string parameterValue = Ksv3dcFYve.GetParameterValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(17838), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(17850));
				if (string.Compare(parameterValue, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(17856)) == 0)
				{
					result = true;
				}
			}
			catch (InvalidOperationException exception)
			{
				result = true;
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			catch (ECMDataReaderException exception2)
			{
				result = true;
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
			catch (COMException exception3)
			{
				result = true;
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception3);
			}
			catch (ECMServicesException exception4)
			{
				result = true;
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception4);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		int IFnPModel.GetDecimalPrecission(int parameterId, int moduleType)
		{
			if (parameterId == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(17870), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18006));
			}
			int num = 0;
			try
			{
				ECMSERVICESAPILib.IECMServices iECMServices = (ECMSERVICESAPILib.IECMServices)sWd3ZxiCXv;
				ECMSERVICESAPILib.IParameterDefinition parameterDefinition = iECMServices.ParameterDefinitions.GetParameterDefinition(parameterId.ToString(CultureInfo.InvariantCulture), moduleType);
				if (parameterDefinition != null)
				{
					num = parameterDefinition.Decimal;
					num *= -1;
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
			catch (COMException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception3);
			}
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		object IFnPModel.GetRawValueFromDisplayValue(string parameterId, string displayValue, string moduleID)
		{
			if (NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18032) == parameterId)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18038), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18174));
			}
			try
			{
				return Ksv3dcFYve.GetRawValueFromDisplayValue(parameterId, displayValue, moduleID);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
			catch (COMException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception3);
			}
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		IFnPElement IFnPModel.GetParentFeatureElement(IFnPElement element)
		{
			if (element == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18200), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18336));
			}
			IFnPElement fnPElement = null;
			try
			{
				return x8lVn0TdQ5(element);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
				return element;
			}
			catch (Exception exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
				return element;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		List<string> IFnPModel.CheckFnPRules(IFnPElement element)
		{
			if (element == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18354), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18476));
			}
			List<string> list = null;
			try
			{
				Dictionary<string, string> dictionary = meAVthTy28();
				if (dictionary.ContainsKey(element.Id.ToString()) && Ksv3dcFYve.GetParameterValue(dictionary[element.Id.ToString()], element.ModuleId.ToString()).Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18494)))
				{
					if (list == null)
					{
						list = new List<string>();
						list.Add(dictionary[element.Id.ToString()]);
					}
					else
					{
						list.Add(dictionary[element.Id.ToString()]);
					}
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
			catch (COMException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception3);
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private List<string> BhAVfpnvKR(int P_0, Dictionary<string, object> writeData)
		{
			List<string> list = new List<string>();
			uint age = uint.MaxValue;
			try
			{
				ECMSERVICESAPILib.IECMServices iECMServices = (ECMSERVICESAPILib.IECMServices)sWd3ZxiCXv;
				ECMSERVICESAPILib.IDataService dataService = iECMServices.DataServices.Add(iECMServices.ActiveConnectionID);
				dataService.CurrentModuleID = P_0.ToString(CultureInfo.CurrentUICulture);
				foreach (string key in writeData.Keys)
				{
					try
					{
						if (dataService.IsReadBlocked(key))
						{
							list.Add(key);
							continue;
						}
						ECMSERVICESAPILib.IParameter parameter = (ECMSERVICESAPILib.IParameter)dataService.ReadWithAge(key, ReadTypesEnum.RT_Parameter, age);
						if (!parameter.DisplayValue.Trim().Equals(writeData[key].ToString().Trim()))
						{
							list.Add(key);
						}
					}
					catch (COMException exception)
					{
						list.Add(key);
						FnPTraceLoger.TryLog(LogCategory.FnPModel, exception);
					}
				}
				iECMServices.DataServices.Remove(dataService.ID);
			}
			catch (COMException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception2);
			}
			catch (NullReferenceException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPModel, exception3);
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static int dboVmB9XR4(IFnPElement P_0)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18500), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18624));
			}
			int num = 0;
			if (!(P_0 is IFeatureElement { EnableId: var enableId }))
			{
				return P_0.Id;
			}
			return enableId;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool SN1V4AoVcr(string P_0)
		{
			if (string.IsNullOrEmpty(P_0))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18642), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18774));
			}
			return LnY3smVfA0.IsValid(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void iBPV2jeCE0()
		{
			Rdy3HJIkKD?.BeginInvoke(this, new EventArgs(), null, null);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void V9mV6INqmb()
		{
			Pm73SuxgrJ?.BeginInvoke(this, new EventArgs(), null, null);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IFnPElement x8lVn0TdQ5(IFnPElement P_0)
		{
			IFnPElement result = null;
			if (P_0 is IFeature)
			{
				result = P_0;
			}
			else if (P_0 is Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameter)
			{
				result = (P_0 as Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameter).Parent;
				result = x8lVn0TdQ5(result);
			}
			else if (P_0 is ISubFeature)
			{
				result = (P_0 as ISubFeature).ParentFeature;
				result = x8lVn0TdQ5(result);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private Dictionary<string, string> meAVthTy28()
		{
			Dictionary<string, string> dictionary = new Dictionary<string, string>();
			dictionary.Add(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18796), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18816));
			dictionary.Add(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18834), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18854));
			return dictionary;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool K69Vo5VSDj(Cummins.INSITE.Kernel.ECMServicesAPI.IConnections P_0, int P_1)
		{
			Cummins.INSITE.Kernel.ECMServicesAPI.IConnection connection = P_0.Get(P_1);
			if (connection != null)
			{
				Cummins.INSITE.Kernel.ECMServicesAPI.ISystems systems = connection.Systems;
				if (systems != null)
				{
					IECU eCU = systems[0].GetECU(0);
					if (eCU != null)
					{
						GTISLevel gTISLevel = eCU.GTISLevel;
						if (gTISLevel == GTISLevel.GTIS_45 || gTISLevel == GTISLevel.GTIS_46)
						{
							return true;
						}
						return false;
					}
				}
			}
			return false;
		}
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.Model.Tooltip
{
	public class LimitTooltip
	{
		private wVU5sNcAu4EKHDLExx rbo3LCD2T4;

		private ILocalizedStringProvider kSB3cNvEp3;

		private ECMDataReader wKY3T0jM4I;

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CLSCompliant(false)]
		public LimitTooltip(ILocalizedStringProvider stringProvider, ECMDataReader ecmDataReader)
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
			kSB3cNvEp3 = stringProvider;
			rbo3LCD2T4 = new wVU5sNcAu4EKHDLExx(ecmDataReader);
			wKY3T0jM4I = ecmDataReader;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetTooltip(LimitsTooltipInfo tooltipInfo, IFnPElement element, ValidateLimit limit)
		{
			if (element == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18872), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(18992));
			}
			string result = string.Empty;
			int num = mDC39eRXbm(element);
			if (ValidateLimit.MaxLimitExceeded == limit)
			{
				result = X9F3vVOrSe(num, tooltipInfo, element);
			}
			else if (ValidateLimit.MinLimitExceeded == limit)
			{
				result = NQB3ruSiaj(num, tooltipInfo, element);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string X9F3vVOrSe(int P_0, LimitsTooltipInfo P_1, IFnPElement P_2)
		{
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(19010), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(19158));
			}
			string empty = string.Empty;
			empty = kSB3cNvEp3.GetLocalizedString(StringIdProvider.ParameterMaxLimtMessage);
			empty += Environment.NewLine;
			if (EWgfmqubhLleaa6sgy.xQnd1Hm8Bf(P_0, TooltipQueryType.LimitsTooltipQuery, LimitsTooltipType.MaxLimit))
			{
				return empty + NUq3R22PJ3(P_0, LimitsTooltipType.MaxLimit, P_2);
			}
			string minMaxLimitDependantParameterInfo = wKY3T0jM4I.GetMinMaxLimitDependantParameterInfo(LimitParameterType.Max, P_0.ToString(), P_2.ModuleId.ToString());
			if (!string.IsNullOrEmpty(minMaxLimitDependantParameterInfo))
			{
				return empty + minMaxLimitDependantParameterInfo;
			}
			return empty + P_1.LimitValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string NQB3ruSiaj(int P_0, LimitsTooltipInfo P_1, IFnPElement P_2)
		{
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(19184), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(19332));
			}
			string empty = string.Empty;
			empty = kSB3cNvEp3.GetLocalizedString(StringIdProvider.ParameterMinLimitMessage);
			empty += Environment.NewLine;
			if (EWgfmqubhLleaa6sgy.xQnd1Hm8Bf(P_0, TooltipQueryType.LimitsTooltipQuery, LimitsTooltipType.MinLimit))
			{
				return empty + NUq3R22PJ3(P_0, LimitsTooltipType.MinLimit, P_2);
			}
			string text = string.Empty;
			if (P_2 is Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameter)
			{
				text = wKY3T0jM4I.GetMinMaxLimitDependantParameterInfo(LimitParameterType.Min, P_0.ToString(), P_2.ModuleId.ToString());
			}
			if (!string.IsNullOrEmpty(text))
			{
				return empty + text;
			}
			return empty + P_1.LimitValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static int mDC39eRXbm(IFnPElement P_0)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(19358), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(19482));
			}
			int num = 0;
			if (!(P_0 is IFeatureElement { EnableId: var enableId }))
			{
				return P_0.Id;
			}
			return enableId;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string NUq3R22PJ3(int P_0, LimitsTooltipType P_1, IFnPElement P_2)
		{
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(19500), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(19630));
			}
			string empty = string.Empty;
			string text = EWgfmqubhLleaa6sgy.ntCdmhEcw5(P_0, P_1);
			return rbo3LCD2T4.JvINejk1WK(text, P_2, TooltipQueryType.LimitsTooltipQuery);
		}
	}
}
namespace wGKmsfvfCZmgDZNFek
{
	internal sealed class qmm5NFWmPE36Y6yPR0 : IFnPView
	{
		private int jl63YtXuRd;

		private string hsZ3IFf0sY;

		int IFnPView.EditSelStart
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return 0;
			}
		}

		int IFnPView.CurrentColumn
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(19864));
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(19954));
			}
		}

		int IFnPView.CurrentRow
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(20044));
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(20134));
			}
		}

		string IFnPView.EditText
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(20494));
			}
		}

		IntPtr IFnPView.Handle
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(20584));
			}
		}

		int IFnPView.MouseColumn
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(20674));
			}
		}

		int IFnPView.MouseRow
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(20764));
			}
		}

		TooltipActiveState IFnPView.TooltipState
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(21214));
			}
		}

		GridProperties IFnPView.GridProperties
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(21394));
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(21484));
			}
		}

		int IFnPView.RowsCount
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return jl63YtXuRd;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				jl63YtXuRd = num;
			}
		}

		AnchorStyles IFnPView.Anchor
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(22114));
			}
		}

		Cursor IFnPView.Cursor
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(22294));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public qmm5NFWmPE36Y6yPR0()
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
			hsZ3IFf0sY = Environment.NewLine;
			jl63YtXuRd = 1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AutoSizeRows()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AddItem(string P_0)
		{
			string[] array = P_0.TrimEnd(MeILRM8wWV0x9o1PR0.VE9ZA4chWi).Split(MeILRM8wWV0x9o1PR0.VE9ZA4chWi);
			string text = array[0];
			if (text.Contains(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(19656)))
			{
				array[0] = text.Replace(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(19662), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(19668));
			}
			string[] array2 = array;
			foreach (string text2 in array2)
			{
				hsZ3IFf0sY += text2;
				hsZ3IFf0sY += NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(19678);
			}
			hsZ3IFf0sY = hsZ3IFf0sY.TrimEnd(MeILRM8wWV0x9o1PR0.R5oZBVxwnF);
			hsZ3IFf0sY += Environment.NewLine;
			jl63YtXuRd++;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AddSystemName(string P_0)
		{
			hsZ3IFf0sY += P_0;
			hsZ3IFf0sY += Environment.NewLine;
			jl63YtXuRd++;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AddModuleName(string P_0)
		{
			hsZ3IFf0sY += P_0;
			hsZ3IFf0sY += Environment.NewLine;
			jl63YtXuRd++;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AutoSizeCol(int P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(19684));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AutoSizeCols()
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(19774));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		Rectangle IFnPView.GetCellRect(int P_0, int P_1)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(20224));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		DialogResult IFnPView.DisplayMessage(string P_0, string P_1, MessageBoxButtons P_2, MessageBoxIcon P_3)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(20314));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.DisplayTooltip(int P_0, int P_1, string P_2)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(20404));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		string IFnPView.GetFnPData()
		{
			return hsZ3IFf0sY;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		int IFnPView.GetParentRowIndex(int P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(20854));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPView.GetRowCollapse(int P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(20944));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		Node IFnPView.GetRowNode(int P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(21034));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		int IFnPView.GetRowOutlineLevel(int P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(21124));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		object IFnPView.GetValue(Cummins.Insite.AddIns.FeaturesAndParameters.PropertyDescriptor P_0, int P_1, int P_2)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(21304));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.HideTooltip()
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(21574));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPView.IsRowHidden(int P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(21664));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPView.IsVisible()
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(21754));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PrintGrid(PrintProperties P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(21844));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PrintTo()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PutEditMask(int P_0, string P_1)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PutRedraw(bool P_0)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PutRowCollapse(int P_0, bool P_1)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PutRowHidden(int P_0, bool P_1)
		{
			if (!P_1)
			{
				return;
			}
			string[] separator = new string[1] { Environment.NewLine };
			string[] array = hsZ3IFf0sY.Split(separator, StringSplitOptions.None);
			hsZ3IFf0sY = string.Empty;
			int num = 0;
			string[] array2 = array;
			foreach (string text in array2)
			{
				if (text.Length == 0)
				{
					hsZ3IFf0sY += Environment.NewLine;
				}
				else
				{
					hsZ3IFf0sY += text;
					hsZ3IFf0sY += Environment.NewLine;
					num++;
				}
				if (num == P_0)
				{
					jl63YtXuRd = num;
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.ResizeView()
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(21934));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.SelectRow(int P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(22024));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.SetComboDropdownList(string P_0, int P_1)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(22204));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.SetupView()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.SetValue(Cummins.Insite.AddIns.FeaturesAndParameters.PropertyDescriptor P_0, int P_1, int P_2, object P_3)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.ShowPageSetupDialog()
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(22384));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.ShowPrintPreviewDialog(PrintProperties P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(22474));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.EnableUI(bool P_0)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(22564));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.SetGridColumnWidth()
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(22654));
		}
	}
}
namespace nj2wYj9KU7s8FDbKmD
{
	internal class L7xRSRrQV7r2Ivaea2
	{
		private ILocalizedStringProvider zCS3M4YsZb;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public L7xRSRrQV7r2Ivaea2(ILocalizedStringProvider P_0)
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
			zCS3M4YsZb = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string Vag3uk7LtC(IFnPElement P_0)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(22744), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(22864));
			}
			string result = string.Empty;
			switch (mev3UapxEa(P_0))
			{
			case 143:
			case 16801741:
			case 16801742:
			case 16801743:
			case 16801744:
			case 16801745:
			case 16801746:
			case 16807289:
			case 16807476:
				result = zCS3M4YsZb.GetLocalizedString(StringIdProvider.HPCRTooltip);
				break;
			case 16824016:
				if (P_0.WriteBlocked)
				{
					result = zCS3M4YsZb.GetLocalizedString(StringIdProvider.EngineSpeedAccelManagementTooltip);
				}
				break;
			case 16790207:
				result = zCS3M4YsZb.GetLocalizedString(StringIdProvider.EGRValvePositionTooltip);
				break;
			case 16793806:
				result = zCS3M4YsZb.GetLocalizedString(StringIdProvider.ExpandedDroopInputEnableTooltip);
				break;
			case 194:
				result = zCS3M4YsZb.GetLocalizedString(StringIdProvider.AirConditionerControlTooltip);
				break;
			case 16824309:
				result = zCS3M4YsZb.GetLocalizedString(StringIdProvider.ExpandedDroopInputEnableVersion2ToolTip);
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string sdp3kIlQRw(int P_0, int P_1)
		{
			string result = string.Empty;
			switch (P_0)
			{
			case 16816596:
				if (P_1 == 1020366)
				{
					result = zCS3M4YsZb.GetLocalizedString(StringIdProvider.PulsePerDistanceTooltip);
				}
				break;
			case 16785222:
				if (P_1 == 1020394)
				{
					result = zCS3M4YsZb.GetLocalizedString(StringIdProvider.CruiseControlAutoResumeEnableTooltip);
				}
				break;
			case 16816701:
				switch (P_1)
				{
				case 1020431:
				case 1020432:
				case 1020433:
					result = zCS3M4YsZb.GetLocalizedString(StringIdProvider.EngineCoolantLevelShutdown);
					break;
				case 1020434:
				case 1020435:
					result = zCS3M4YsZb.GetLocalizedString(StringIdProvider.ReadOnlyTooltip);
					break;
				}
				break;
			case 16824102:
				if (P_1 == 16783822)
				{
					result = zCS3M4YsZb.GetLocalizedString(StringIdProvider.TransmissionAcceleratorInterlockEnableTooltip);
				}
				break;
			case 111021:
				if (P_1 == 16795808)
				{
					result = zCS3M4YsZb.GetLocalizedString(StringIdProvider.ResetMissedOilValvePulsesTooltip);
				}
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static int mev3UapxEa(IFnPElement P_0)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(22882), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23006));
			}
			int num = 0;
			if (!(P_0 is IFeatureElement { EnableId: var enableId }))
			{
				return P_0.Id;
			}
			return enableId;
		}
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.Helper
{
	public class WriteDataHelper
	{
		private Dictionary<int, Dictionary<string, object>> FBF3wjIc3x;

		private object jCK3hclM3t;

		public Dictionary<int, Dictionary<string, object>> ModuleIdParamMap
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return FBF3wjIc3x;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public WriteDataHelper()
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			jCK3hclM3t = new object();
			base..ctor();
			FBF3wjIc3x = new Dictionary<int, Dictionary<string, object>>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddParameter(int moduleId, string parameterId, object value)
		{
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23024), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23144));
			}
			if (value == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23170), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23290));
			}
			lock (jCK3hclM3t)
			{
				if (FBF3wjIc3x.ContainsKey(moduleId))
				{
					if (FBF3wjIc3x[moduleId].ContainsKey(parameterId))
					{
						FBF3wjIc3x[moduleId][parameterId] = value;
					}
					else
					{
						FBF3wjIc3x[moduleId].Add(parameterId, value);
					}
				}
				else
				{
					FBF3wjIc3x.Add(moduleId, new Dictionary<string, object>());
					FBF3wjIc3x[moduleId].Add(parameterId, value);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RemoveParameter(int moduleId, string parameterId)
		{
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23304), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23430));
			}
			lock (jCK3hclM3t)
			{
				if (FBF3wjIc3x.ContainsKey(moduleId))
				{
					FBF3wjIc3x[moduleId].Remove(parameterId);
					if (FBF3wjIc3x[moduleId].Count == 0)
					{
						FBF3wjIc3x.Remove(moduleId);
					}
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool ContainsParameter(string parameterId, int moduleId)
		{
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23456), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23586));
			}
			bool result = false;
			lock (jCK3hclM3t)
			{
				if (FBF3wjIc3x.ContainsKey(moduleId) && FBF3wjIc3x[moduleId].ContainsKey(parameterId))
				{
					result = true;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Clear()
		{
			lock (jCK3hclM3t)
			{
				if (FBF3wjIc3x != null)
				{
					FBF3wjIc3x.Clear();
				}
			}
		}
	}
}
namespace dgnVOwLrooQc8bKdN9
{
	internal class l5ISilRrKwensI6LnI
	{
		private const string JY53KtjuHI = "100";

		private const string hNy3yVpDeS = "0";

		private const string VyA3Jevd66 = "30";

		public const string eyk3FuCA6l = "167";

		public const string M9g3lDCbqR = "27";

		private const string zbN3xIrXpv = "131";

		private const string FTL30fV7ao = "111";

		private string[] USK3gcHqA9;

		private ECMSERVICESAPILib.IEnumerations TOj375AllP;

		private ECMSERVICESAPILib.IParameterDefinitions JVy3q0xpgD;

		private ECMSERVICESAPILib.IModules FDb380CnMP;

		private Dictionary<int, Dictionary<string, double>> Acv3iyRMsj;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public l5ISilRrKwensI6LnI(ECMSERVICESAPILib.IParameterDefinitions P_0, ECMSERVICESAPILib.IEnumerations P_1, ECMSERVICESAPILib.IModules P_2)
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			USK3gcHqA9 = new string[1] { NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23612) };
			base..ctor();
			Acv3iyRMsj = new Dictionary<int, Dictionary<string, double>>();
			JVy3q0xpgD = P_0;
			TOj375AllP = P_1;
			FDb380CnMP = P_2;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public object INI3AcRS18(string P_0, string P_1, string P_2)
		{
			object obj = 0.0;
			ECMSERVICESAPILib.IParameterDefinition parameterDefinition = JVy3q0xpgD.GetParameterDefinition(P_1, JTU3Be1fWm(P_0));
			int num = int.Parse(parameterDefinition.enumerationId);
			if (num == 0)
			{
				return lDA3QZZ8pr(parameterDefinition.unitId, parameterDefinition.UnitsFamilyID, P_2);
			}
			return cm13eqUlo8(num, P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private int JTU3Be1fWm(string P_0)
		{
			int result = -1;
			for (int i = 1; i <= FDb380CnMP.Count; i++)
			{
				ECMSERVICESAPILib.IModule module = FDb380CnMP.get_Item((object)i);
				if (module.ID == P_0)
				{
					result = module.ModuleType;
					break;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private object cm13eqUlo8(int P_0, string P_1)
		{
			object result = 0.0;
			if (Acv3iyRMsj.ContainsKey(P_0))
			{
				result = Acv3iyRMsj[P_0][P_1];
			}
			else
			{
				ECMSERVICESAPILib.IEnumeration enumeration = TOj375AllP.GetEnumeration(P_0.ToString());
				BSTRCollection values = enumeration.Values;
				BSTRCollection enumRawValues = enumeration.EnumRawValues;
				Acv3iyRMsj.Add(P_0, new Dictionary<string, double>());
				for (int i = 1; i <= values.Count; i++)
				{
					string text = ((IBSTRCollection)values).get_Item(i);
					double num = double.Parse(((IBSTRCollection)enumRawValues).get_Item(i));
					Acv3iyRMsj[P_0].Add(text, num);
					if (P_1 == text)
					{
						result = num;
					}
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private object lDA3QZZ8pr(string P_0, string P_1, string P_2)
		{
			object result = 0.0;
			string text;
			if ((text = P_0) == null)
			{
				goto IL_01a8;
			}
			if (!(text == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23618)))
			{
				if (!(text == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23628)))
				{
					if (!(text == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23638)))
					{
						if (!(text == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23648)))
						{
							goto IL_01a8;
						}
						result = P_2;
					}
					else if (P_1 == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23672))
					{
						result = P_2;
					}
					else if (!P_2.Equals(string.Empty))
					{
						string[] array = P_2.Split(USK3gcHqA9, StringSplitOptions.RemoveEmptyEntries);
						if (2 == array.Length)
						{
							result = long.Parse(array[0]) * 60 + long.Parse(array[1]);
						}
					}
				}
				else if (P_1 == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23662))
				{
					result = P_2;
				}
				else
				{
					string[] array2 = P_2.Split(USK3gcHqA9, StringSplitOptions.RemoveEmptyEntries);
					result = (long.Parse(array2[0]) * 3600 + long.Parse(array2[1]) * 60 + long.Parse(array2[2])) * 1000;
				}
			}
			else if (P_1 == NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23654))
			{
				result = P_2;
			}
			else
			{
				string[] array3 = P_2.Split(USK3gcHqA9, StringSplitOptions.RemoveEmptyEntries);
				result = (long.Parse(array3[0]) * 3600 + long.Parse(array3[1]) * 60 + long.Parse(array3[2])) * 1000;
			}
			goto IL_01b4;
			IL_01b4:
			return result;
			IL_01a8:
			result = double.Parse(P_2);
			goto IL_01b4;
		}
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.Helper
{
	public class ECMDataReader
	{
		private ECMSERVICESAPILib.IECMServices Vvq3ERCM0E;

		private IFeaturesAndParametersDataOM XER31WPVSe;

		private object Ffn3f90BHq;

		public IFeaturesAndParametersDataOM FnpDataOM
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return XER31WPVSe;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				XER31WPVSe = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMDataReader(object kernel)
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			Ffn3f90BHq = new object();
			base..ctor();
			Vvq3ERCM0E = (ECMSERVICESAPILib.IECMServices)kernel;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetParameterName(string parameterId, string moduleId)
		{
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23680), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23808));
			}
			string empty = string.Empty;
			lock (Ffn3f90BHq)
			{
				try
				{
					ECMSERVICESAPILib.IDataService dataService = Vvq3ERCM0E.DataServices.Add(Vvq3ERCM0E.ActiveConnectionID);
					dataService.CurrentModuleID = moduleId;
					ECMSERVICESAPILib.IParameter parameter = (ECMSERVICESAPILib.IParameter)dataService.Read(parameterId, ReadTypesEnum.RT_Parameter);
					empty = parameter.Name;
					Vvq3ERCM0E.DataServices.Remove(dataService.ID);
					return empty;
				}
				catch (ECMServicesException exception)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23834));
				}
				catch (InvalidComObjectException exception2)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception2);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(23944));
				}
				catch (COMException exception3)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception3);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(24054));
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetParameterName(string parameterId, int detectType)
		{
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(24164), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(24292));
			}
			string result = string.Empty;
			lock (Ffn3f90BHq)
			{
				try
				{
					if (Vvq3ERCM0E != null)
					{
						ECMSERVICESAPILib.IParameterDefinition parameterDefinition = Vvq3ERCM0E.ParameterDefinitions.GetParameterDefinition(parameterId, detectType);
						if (parameterDefinition != null)
						{
							result = parameterDefinition.Name;
						}
					}
				}
				catch (ECMServicesException exception)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(24318));
				}
				catch (InvalidComObjectException exception2)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception2);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(24428));
				}
				catch (COMException exception3)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception3);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(24538));
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetParameterFullName(int moduleId, string parameterId)
		{
			string result = string.Empty;
			if (int.TryParse(parameterId, out var result2))
			{
				IFnPElement fnPElement = XER31WPVSe.FindFnPElement(moduleId, result2);
				result = ((fnPElement == null) ? GetParameterName(parameterId, moduleId.ToString(CultureInfo.InvariantCulture)) : fnPElement.FullName);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetRawValue(string parameterId, string moduleId)
		{
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(24648), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(24766));
			}
			string empty = string.Empty;
			lock (Ffn3f90BHq)
			{
				try
				{
					ECMSERVICESAPILib.IDataService dataService = Vvq3ERCM0E.DataServices.Add(Vvq3ERCM0E.ActiveConnectionID);
					dataService.CurrentModuleID = moduleId;
					ECMSERVICESAPILib.IParameter parameter = (ECMSERVICESAPILib.IParameter)dataService.Read(parameterId, ReadTypesEnum.RT_Parameter);
					empty = ycV3XduRbG(parameter);
					Vvq3ERCM0E.DataServices.Remove(dataService.ID);
					return empty;
				}
				catch (ECMServicesException exception)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(24792));
				}
				catch (InvalidComObjectException exception2)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception2);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(24912));
				}
				catch (COMException exception3)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception3);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(25032));
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetParameterValue(string parameterId, string moduleId)
		{
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(25152), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(25282));
			}
			string empty = string.Empty;
			lock (Ffn3f90BHq)
			{
				try
				{
					ECMSERVICESAPILib.IDataService dataService = Vvq3ERCM0E.DataServices.Add(Vvq3ERCM0E.ActiveConnectionID);
					dataService.CurrentModuleID = moduleId;
					ECMSERVICESAPILib.IParameter parameter = (ECMSERVICESAPILib.IParameter)dataService.Read(parameterId, ReadTypesEnum.RT_Parameter);
					empty = parameter.DisplayValue;
					Vvq3ERCM0E.DataServices.Remove(dataService.ID);
					return empty;
				}
				catch (ECMServicesException exception)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(25308));
				}
				catch (InvalidComObjectException exception2)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception2);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(25420));
				}
				catch (COMException exception3)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception3);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(25532));
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetDisplayValueForTooltip(string parameterId, string moduleId)
		{
			string empty = string.Empty;
			empty = BKk3ChkU2G(parameterId, moduleId);
			if (string.IsNullOrEmpty(empty))
			{
				empty = GetParameterValue(parameterId, moduleId);
			}
			return empty;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public List<string> GetDependantParameterList(string parameterId, string moduleId)
		{
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(25644), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(25790));
			}
			List<string> list = new List<string>();
			lock (Ffn3f90BHq)
			{
				try
				{
					ECMSERVICESAPILib.IDataService dataService = Vvq3ERCM0E.DataServices.Add(Vvq3ERCM0E.ActiveConnectionID);
					dataService.CurrentModuleID = moduleId;
					IDependencyDefinitions dependencyDefinitions = dataService.CheckDependencies(parameterId, ReadTypesEnum.RT_Parameter);
					for (int i = 1; i <= dependencyDefinitions.Count; i++)
					{
						try
						{
							ECMSERVICESAPILib.IDependencyDefinition dependencyDefinition = dependencyDefinitions.get_Item((object)i);
							if (DependencyBlockTypeEnum.BT_True == dependencyDefinition.IsBlocking && !pD23jBsW9o(dependencyDefinition.DependencyParameterID))
							{
								list.Add(dependencyDefinition.DependencyParameterID);
							}
						}
						catch (ECMServicesException exception)
						{
							FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception);
						}
						catch (InvalidOperationException exception2)
						{
							FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception2);
						}
						catch (InvalidComObjectException exception3)
						{
							FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception3);
						}
						catch (COMException exception4)
						{
							FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception4);
						}
					}
					Vvq3ERCM0E.DataServices.Remove(dataService.ID);
					return list;
				}
				catch (ECMServicesException exception5)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception5);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(25816));
				}
				catch (InvalidComObjectException exception6)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception6);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(25966));
				}
				catch (COMException exception7)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception7);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(26116));
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool pD23jBsW9o(string P_0)
		{
			bool result = false;
			try
			{
				int num = int.Parse(P_0);
				if (num >= 1020233 && num <= 1020254)
				{
					result = true;
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception);
			}
			catch (OverflowException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception2);
			}
			catch (FormatException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception3);
			}
			catch (Exception exception4)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception4);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetMinMaxLimitDependantParameterInfo(LimitParameterType limitParameterType, string parameterId, string moduleId)
		{
			if (string.IsNullOrEmpty(parameterId))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(26266), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(26434));
			}
			StringBuilder stringBuilder = new StringBuilder();
			string text = string.Empty;
			string text2 = string.Empty;
			lock (Ffn3f90BHq)
			{
				try
				{
					ECMSERVICESAPILib.IDataService dataService = Vvq3ERCM0E.DataServices.Add(Vvq3ERCM0E.ActiveConnectionID);
					dataService.CurrentModuleID = moduleId;
					IDependencyDefinitions dependencyDefinitions = dataService.CheckDependencies(parameterId, ReadTypesEnum.RT_Parameter);
					for (int i = 1; i <= dependencyDefinitions.Count; i++)
					{
						try
						{
							ECMSERVICESAPILib.IDependencyDefinition dependencyDefinition = dependencyDefinitions.get_Item((object)i);
							RuleTypesEnum ruleType = dependencyDefinition.RuleType;
							if ((limitParameterType != LimitParameterType.Min || RuleTypesEnum.RT_Lower != ruleType) && (limitParameterType != LimitParameterType.Max || RuleTypesEnum.RT_Upper != ruleType))
							{
								continue;
							}
							string displayValueForTooltip = GetDisplayValueForTooltip(dependencyDefinition.DependencyParameterID, moduleId);
							switch (limitParameterType)
							{
							case LimitParameterType.Min:
								if (text2.Length == 0 || double.Parse(displayValueForTooltip) > double.Parse(text2))
								{
									text2 = displayValueForTooltip;
									text = dependencyDefinition.DependencyParameterID;
								}
								break;
							case LimitParameterType.Max:
								if (text2.Length == 0 || double.Parse(displayValueForTooltip) < double.Parse(text2))
								{
									text2 = displayValueForTooltip;
									text = dependencyDefinition.DependencyParameterID;
								}
								break;
							}
						}
						catch (ArgumentException exception)
						{
							FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception);
						}
						catch (FormatException exception2)
						{
							FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception2);
						}
						catch (ECMDataReaderException exception3)
						{
							FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception3);
						}
						catch (InvalidOperationException exception4)
						{
							FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception4);
						}
						catch (InvalidComObjectException exception5)
						{
							FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception5);
						}
						catch (COMException exception6)
						{
							FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception6);
						}
						catch (ECMServicesException exception7)
						{
							FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception7);
						}
					}
					if (text.Length != 0)
					{
						IFnPElement fnPElement = XER31WPVSe.FindFnPElement(int.Parse(moduleId), int.Parse(text));
						if (fnPElement != null)
						{
							stringBuilder.Append(fnPElement.FullName);
							if (!string.IsNullOrEmpty(fnPElement.DesiredValue))
							{
								stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(26460));
								stringBuilder.Append(fnPElement.DesiredValue);
							}
							else
							{
								stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(26470));
								stringBuilder.Append(fnPElement.Value);
							}
							stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(26480));
							stringBuilder.Append(fnPElement.Unit);
						}
					}
					Vvq3ERCM0E.DataServices.Remove(dataService.ID);
				}
				catch (ECMServicesException exception8)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception8);
				}
				catch (InvalidComObjectException exception9)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception9);
				}
				catch (COMException exception10)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception10);
				}
			}
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string R6l3OijQLy(LimitParameterType P_0, string P_1, string P_2)
		{
			StringBuilder stringBuilder = new StringBuilder();
			try
			{
				if (LimitParameterType.Max == P_0)
				{
					string text = string.Empty;
					int num = int.Parse(P_1);
					if (num >= 1020211 && num <= 1020219)
					{
						int num2 = int.Parse(GetDisplayValueForTooltip(1020232.ToString(), P_2));
						text = ((num != 1020210 + num2 - 2) ? (num + 1).ToString() : 1020220.ToString());
					}
					else if (num >= 1020222 && num <= 1020230)
					{
						int num3 = int.Parse(GetDisplayValueForTooltip(1020232.ToString(), P_2));
						text = ((num != 1020221 + num3 - 2) ? (num + 1).ToString() : 1020231.ToString());
					}
					if (!string.IsNullOrEmpty(text))
					{
						IFnPElement fnPElement = XER31WPVSe.FindFnPElement(int.Parse(P_2), int.Parse(text));
						if (fnPElement != null)
						{
							IFnPElement fnPElement2 = XER31WPVSe.FindFnPElement(int.Parse(P_2), int.Parse(P_1));
							stringBuilder.Append(fnPElement.FullName);
							stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(26486));
							stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(26500));
							stringBuilder.Append(fnPElement2.MaxValue);
							stringBuilder.Append(fnPElement.Unit);
						}
					}
				}
				else if (LimitParameterType.Min == P_0)
				{
					string empty = string.Empty;
					int num4 = int.Parse(P_1);
					if ((num4 >= 1020211 && num4 <= 1020219) || (num4 >= 1020222 && num4 <= 1020230))
					{
						empty = (num4 - 1).ToString();
						IFnPElement fnPElement3 = XER31WPVSe.FindFnPElement(int.Parse(P_2), int.Parse(empty));
						if (fnPElement3 != null)
						{
							IFnPElement fnPElement4 = XER31WPVSe.FindFnPElement(int.Parse(P_2), int.Parse(P_1));
							stringBuilder.Append(fnPElement3.FullName);
							stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(26510));
							stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(26524));
							stringBuilder.Append(fnPElement4.MinValue);
							stringBuilder.Append(fnPElement3.Unit);
						}
					}
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception);
			}
			catch (FormatException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception2);
			}
			catch (ECMDataReaderException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception3);
			}
			catch (InvalidOperationException exception4)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception4);
			}
			catch (ECMServicesException exception5)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception5);
			}
			catch (InvalidComObjectException exception6)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception6);
			}
			catch (COMException exception7)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception7);
			}
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public object GetRawValueFromDisplayValue(string parameterId, string displayValue, string moduleId)
		{
			lock (Ffn3f90BHq)
			{
				try
				{
					ECMSERVICESAPILib.IDataService dataService = Vvq3ERCM0E.DataServices.Add(Vvq3ERCM0E.ActiveConnectionID);
					dataService.CurrentModuleID = moduleId;
					l5ISilRrKwensI6LnI l5ISilRrKwensI6LnI = new l5ISilRrKwensI6LnI(Vvq3ERCM0E.ParameterDefinitions, Vvq3ERCM0E.Enumerations, dataService.Connection.System.Modules);
					object result = l5ISilRrKwensI6LnI.INI3AcRS18(moduleId, parameterId, displayValue);
					Vvq3ERCM0E.DataServices.Remove(dataService.ID);
					return result;
				}
				catch (ECMServicesException exception)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(26534));
				}
				catch (InvalidComObjectException exception2)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception2);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(26646));
				}
				catch (COMException exception3)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception3);
					throw new ECMDataReaderException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(26758));
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string ycV3XduRbG(ECMSERVICESAPILib.IParameter P_0)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(26870), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(26990));
			}
			string empty = string.Empty;
			if (P_0.RawValue is int)
			{
				return ((int)P_0.RawValue).ToString(CultureInfo.InvariantCulture);
			}
			if (P_0.RawValue is float)
			{
				return ((float)P_0.RawValue).ToString(CultureInfo.InvariantCulture);
			}
			if (P_0.RawValue is uint)
			{
				return ((uint)P_0.RawValue).ToString(CultureInfo.InvariantCulture);
			}
			if (P_0.RawValue is sbyte)
			{
				return ((sbyte)P_0.RawValue).ToString(CultureInfo.InvariantCulture);
			}
			if (P_0.RawValue is bool)
			{
				return ((bool)P_0.RawValue).ToString();
			}
			if (P_0.RawValue is double)
			{
				return P_0.RawValue.ToString();
			}
			return (string)P_0.RawValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string BKk3ChkU2G(string P_0, string P_1)
		{
			string result = string.Empty;
			if (string.IsNullOrEmpty(P_0))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(27012), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(27142));
			}
			lock (Ffn3f90BHq)
			{
				try
				{
					ECMSERVICESAPILib.IDataService dataService = Vvq3ERCM0E.DataServices.Add(Vvq3ERCM0E.ActiveConnectionID);
					dataService.CurrentModuleID = P_1;
					object desiredValue = dataService.GetDesiredValue(P_0);
					if (desiredValue != null)
					{
						result = desiredValue.ToString();
					}
					Vvq3ERCM0E.DataServices.Remove(dataService.ID);
				}
				catch (ECMServicesException exception)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception);
				}
				catch (InvalidComObjectException exception2)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception2);
				}
				catch (COMException exception3)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception3);
				}
				catch (NotImplementedException exception4)
				{
					FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception4);
				}
			}
			return result;
		}
	}
	public class GridProperties
	{
		private bool D943mCrmNm;

		private bool mgV34QL9Lv;

		private bool zJc32k9aLG;

		private bool Hv336ZynBS;

		private int yDF3n2owdi;

		private string tWb3tpoCNA;

		private Color DlN3oQi3BN;

		private Color wAp3zZkTqh;

		private Color PnCNa64Kk2;

		public int FontSize
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return yDF3n2owdi;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				yDF3n2owdi = value;
			}
		}

		public bool IsBold
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return D943mCrmNm;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				D943mCrmNm = value;
			}
		}

		public bool IsItalic
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return mgV34QL9Lv;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				mgV34QL9Lv = value;
			}
		}

		public bool IsStrike
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return zJc32k9aLG;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				zJc32k9aLG = value;
			}
		}

		public bool IsUnderline
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Hv336ZynBS;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				Hv336ZynBS = value;
			}
		}

		public string FontName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return tWb3tpoCNA;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				tWb3tpoCNA = value;
			}
		}

		public Color FontColor
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return DlN3oQi3BN;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				DlN3oQi3BN = value;
			}
		}

		public Color BackColor
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return wAp3zZkTqh;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				wAp3zZkTqh = value;
			}
		}

		public Color GridColor
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return PnCNa64Kk2;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				PnCNa64Kk2 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public GridProperties()
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
		}
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.Resources
{
	[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "2.0.0.0")]
	[CompilerGenerated]
	[DebuggerNonUserCode]
	internal class FnPResources
	{
		private static ResourceManager resourceMan;

		private static CultureInfo resourceCulture;

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static ResourceManager ResourceManager
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (object.ReferenceEquals(resourceMan, null))
				{
					ResourceManager resourceManager = new ResourceManager("Cummins.Insite.AddIns.FeaturesAndParameters.Resources.FnPResources", typeof(FnPResources).Assembly);
					resourceMan = resourceManager;
				}
				return resourceMan;
			}
		}

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static CultureInfo Culture
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return resourceCulture;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				resourceCulture = value;
			}
		}

		internal static Icon FnPFeatureSelected
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				//IL_0022: Unknown result type (might be due to invalid IL or missing references)
				//IL_0028: Expected O, but got Unknown
				object obj = ResourceManager.GetObject(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(27168), resourceCulture);
				return (Icon)obj;
			}
		}

		internal static Icon FnPFeatureSelectedLocked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				//IL_0022: Unknown result type (might be due to invalid IL or missing references)
				//IL_0028: Expected O, but got Unknown
				object obj = ResourceManager.GetObject(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(27208), resourceCulture);
				return (Icon)obj;
			}
		}

		internal static Icon FnPFeatureUnselected
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				//IL_0022: Unknown result type (might be due to invalid IL or missing references)
				//IL_0028: Expected O, but got Unknown
				object obj = ResourceManager.GetObject(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(27260), resourceCulture);
				return (Icon)obj;
			}
		}

		internal static Icon FnPFeatureUnselectedLocked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				//IL_0022: Unknown result type (might be due to invalid IL or missing references)
				//IL_0028: Expected O, but got Unknown
				object obj = ResourceManager.GetObject(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(27304), resourceCulture);
				return (Icon)obj;
			}
		}

		internal static Icon FnPParameterSelected
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				//IL_0022: Unknown result type (might be due to invalid IL or missing references)
				//IL_0028: Expected O, but got Unknown
				object obj = ResourceManager.GetObject(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(27360), resourceCulture);
				return (Icon)obj;
			}
		}

		internal static Icon FnPParameterSelectedLocked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				//IL_0022: Unknown result type (might be due to invalid IL or missing references)
				//IL_0028: Expected O, but got Unknown
				object obj = ResourceManager.GetObject(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(27404), resourceCulture);
				return (Icon)obj;
			}
		}

		internal static Icon FnPParameterUnselected
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				//IL_0022: Unknown result type (might be due to invalid IL or missing references)
				//IL_0028: Expected O, but got Unknown
				object obj = ResourceManager.GetObject(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(27460), resourceCulture);
				return (Icon)obj;
			}
		}

		internal static Icon FnPParameterUnselectedLocked
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				//IL_0022: Unknown result type (might be due to invalid IL or missing references)
				//IL_0028: Expected O, but got Unknown
				object obj = ResourceManager.GetObject(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(27508), resourceCulture);
				return (Icon)obj;
			}
		}

		internal static Icon FnPUI
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				//IL_0022: Unknown result type (might be due to invalid IL or missing references)
				//IL_0028: Expected O, but got Unknown
				object obj = ResourceManager.GetObject(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(27568), resourceCulture);
				return (Icon)obj;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal FnPResources()
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
		}
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters
{
	[ProgId("Cummins.INSITE.FeaturesAndParameters.FnPAddin")]
	[ClassInterface(ClassInterfaceType.None)]
	[ComVisible(true)]
	[Guid("2E473ECD-9359-4B78-BC47-AF5E692D9DE0")]
	public sealed class FnPAddIn : IAppWindowCallback, IViewCreator, IAddIn, IAddinInterfaceProvider, IViewMessageProcessor, ECMSERVICESAPILib.IDisconnectCallback, IPresenterEventListener, IDisposable, IPrintImageEx
	{
		private ILocalizedStringProvider CPfNYOjfbw;

		private AddInBase rlvNI2Mfsf;

		private IFnPModel XjDNuagSlk;

		private IFnPPresenter DcuNkyjXQL;

		private IFnPPrintPresenter T1iNUoxCss;

		private IEventSubscriber GElNMRKpqS;

		private ToolBar FVhNwlYZAn;

		private MenuBar gfTNhXZEik;

		private ViewSelector VCUNAtwrWo;

		private ToolSecurity vXmNBmbbiS;

		public bool CanClose
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return DcuNkyjXQL.CanCloseFnP();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void FtlN5XclX9()
		{
			if (VCUNAtwrWo != null)
			{
				ViewSelectorButton viewSelectorButton = new ViewSelectorButton();
				viewSelectorButton.ButtonText = CPfNYOjfbw.GetLocalizedString(StringIdProvider.ViewBarName);
				viewSelectorButton.LargeBitmapId = 102;
				viewSelectorButton.SmallBitmapId = 102;
				viewSelectorButton.ToolTip = CPfNYOjfbw.GetLocalizedString(StringIdProvider.ViewBarTooltip);
				viewSelectorButton.ButtonIndex = 0;
				viewSelectorButton.DefaultWindowType = 1;
				viewSelectorButton.GroupId = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(27582);
				viewSelectorButton.LargeBitmapIcon = FnPResources.FnPUI;
				viewSelectorButton.SmallBitmapIcon = FnPResources.FnPUI;
				VCUNAtwrWo.InitViewSelectorButtonInfo(viewSelectorButton);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FnPAddIn()
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
			meeNVMKmTW();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Init(int GITCookie)
		{
			FnPTraceLoger.OpenLogger(LoggerOption.LogToFile);
			rlvNI2Mfsf.Init(GITCookie);
			XjDNuagSlk.Initialize(rlvNI2Mfsf.GetProvider(FunctionProvider.Kernel), rlvNI2Mfsf.GetProvider(FunctionProvider.Shell));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Load()
		{
			rlvNI2Mfsf.Load();
			DcuNkyjXQL.LoadFindDialog();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Unload()
		{
			rlvNI2Mfsf.Unload();
			FnPTraceLoger.CloseLogger();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IntPtr GetInterface(Guid guid)
		{
			IntPtr ppv = IntPtr.Zero;
			if (typeof(IViewSelectorClient).GUID == guid)
			{
				IntPtr iUnknownForObject = Marshal.GetIUnknownForObject(VCUNAtwrWo);
				Marshal.QueryInterface(iUnknownForObject, in guid, out ppv);
			}
			else if (typeof(IToolBarClient).GUID == guid)
			{
				IntPtr iUnknownForObject2 = Marshal.GetIUnknownForObject(FVhNwlYZAn);
				Marshal.QueryInterface(iUnknownForObject2, in guid, out ppv);
			}
			else
			{
				if (!(typeof(IMenuBarClient).GUID == guid))
				{
					throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(27662));
				}
				IntPtr iUnknownForObject3 = Marshal.GetIUnknownForObject(gfTNhXZEik);
				Marshal.QueryInterface(iUnknownForObject3, in guid, out ppv);
			}
			return ppv;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CLSCompliant(false)]
		public IViewMessageProcessor CreateView(int lhwndParent)
		{
			DcuNkyjXQL.PrepareView(lhwndParent);
			return this;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IntPtr GetWindowICON()
		{
			return FnPResources.FnPUI.ToBitmap().GetHicon();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ProcessWndMessage(int msg)
		{
			DcuNkyjXQL.ProcessViewMsg(msg);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Dispose()
		{
			w52NpDRbha(true);
			GC.SuppressFinalize(this);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CLSCompliant(false)]
		public void Print(object pKernel, string bstrConnetionId, VSPrinter pPrinter, int lFeatureID)
		{
			if (T1iNUoxCss == null)
			{
				T1iNUoxCss = new nPLxyaYbt3o6GxIF5R(XjDNuagSlk);
			}
			T1iNUoxCss.PrintImageInToolFormat(pKernel, bstrConnetionId, pPrinter, lFeatureID);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SerializeData(object pKernel, string bstrConnetionId, out string bstrFnPData, int lFeatureID)
		{
			if (T1iNUoxCss == null)
			{
				T1iNUoxCss = new nPLxyaYbt3o6GxIF5R(XjDNuagSlk);
			}
			bstrFnPData = T1iNUoxCss.GetFnPDataInTextFormat(pKernel, bstrConnetionId, lFeatureID);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IPresenterEventListener.IPresenterEventPublisher_MenuBarStateRefreshRequested(object sender, EventArgs e)
		{
			gfTNhXZEik.RefreshMenuBarStates();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IPresenterEventListener.IPresenterEventPublisher_ToolBarStateRefreshRequested(object sender, EventArgs e)
		{
			FVhNwlYZAn.RefreshToolBarStates();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool AllowDisconnect(int cookie)
		{
			return DcuNkyjXQL.AllowDisconnect(cookie);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void HandleDisconnect(int cookie)
		{
			DcuNkyjXQL.HandleDisconnect(cookie);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void w52NpDRbha(bool P_0)
		{
			if (P_0)
			{
				((IDisposable)GElNMRKpqS).Dispose();
				GElNMRKpqS = null;
				((IDisposable)DcuNkyjXQL).Dispose();
				DcuNkyjXQL = null;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void meeNVMKmTW()
		{
			GElNMRKpqS = null;
			rlvNI2Mfsf = new AddInBase();
			vXmNBmbbiS = new ToolSecurity();
			FVhNwlYZAn = new ToolBar();
			gfTNhXZEik = new MenuBar();
			VCUNAtwrWo = new ViewSelector();
			XjDNuagSlk = new FnPModel(vXmNBmbbiS);
			DcuNkyjXQL = new FnPPresenter(XjDNuagSlk);
			CPfNYOjfbw = Factory.CreateInstance<ILocalizedStringProvider>();
			CPfNYOjfbw.Initialize(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(27796));
			JpHNDFBw5q();
			aKvNdnqRod();
			rZTNHGpHoE();
			n5fN3VXUD2();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void n5fN3VXUD2()
		{
			((IPresenterEventPublisher)DcuNkyjXQL).MenuBarStateRefreshRequested += ((IPresenterEventListener)this).IPresenterEventPublisher_MenuBarStateRefreshRequested;
			((IPresenterEventPublisher)DcuNkyjXQL).ToolBarStateRefreshRequested += ((IPresenterEventListener)this).IPresenterEventPublisher_ToolBarStateRefreshRequested;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void pLsNNiiy4c()
		{
			((IPresenterEventPublisher)DcuNkyjXQL).MenuBarStateRefreshRequested -= ((IPresenterEventListener)this).IPresenterEventPublisher_MenuBarStateRefreshRequested;
			((IPresenterEventPublisher)DcuNkyjXQL).ToolBarStateRefreshRequested -= ((IPresenterEventListener)this).IPresenterEventPublisher_ToolBarStateRefreshRequested;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void JpHNDFBw5q()
		{
			rlvNI2Mfsf.AddInitInfo(FtlN5XclX9);
			rlvNI2Mfsf.AddInitInfo(qnCNTv17ha);
			rlvNI2Mfsf.AddInitInfo(zFUNLiQEue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aKvNdnqRod()
		{
			rlvNI2Mfsf.AddloadInfo(iG7NSnBsRy);
			rlvNI2Mfsf.AddloadInfo(hRwNGO4bPY);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void rZTNHGpHoE()
		{
			rlvNI2Mfsf.AddUnloadInfo(GKTNZsF4AA);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void iG7NSnBsRy()
		{
			try
			{
				GElNMRKpqS = Factory.CreateInstance<IEventSubscriber>();
				GElNMRKpqS.Initialize(rlvNI2Mfsf.GetProvider(FunctionProvider.Kernel), this);
				IConnectionEventsProxy connectionEventsProxy = Factory.CreateInstance<IConnectionEventsProxy>();
				connectionEventsProxy.ECMConnectionEstablished += BOQNvavNDB;
				connectionEventsProxy.ECMConnectionTerminated += xqTNW6113J;
				GElNMRKpqS.SubscribeToEvents(ComponentIds.ConnectionManagerWorker, EventIDs.ConnectionEvents, connectionEventsProxy);
				IPrefDispEventsProxy prefDispEventsProxy = Factory.CreateInstance<IPrefDispEventsProxy>();
				prefDispEventsProxy.ECMGroupChanged += F6ONsUH7Kp;
				GElNMRKpqS.SubscribeToEvents(ComponentIds.PrefDispUI, EventIDs.PrefDispEvents, prefDispEventsProxy);
				IToolSecurityEventsProxy toolSecurityEventsProxy = Factory.CreateInstance<IToolSecurityEventsProxy>();
				toolSecurityEventsProxy.ECMToolLevelChanged += FLbNb18aWb;
				GElNMRKpqS.SubscribeToEvents(ComponentIds.ToolSecurity, EventIDs.ToolSecurityEvents, toolSecurityEventsProxy);
				IConManEventForFnPProxy conManEventForFnPProxy = Factory.CreateInstance<IConManEventForFnPProxy>();
				conManEventForFnPProxy.ECMConnectionEstablished += VR0NPHIxkn;
				GElNMRKpqS.SubscribeToEvents(ComponentIds.ConnectionManagerWorker, EventIDs.ConManEventForFnP, conManEventForFnPProxy);
				IConnectionLostEventsProxy connectionLostEventsProxy = Factory.CreateInstance<IConnectionLostEventsProxy>();
				connectionLostEventsProxy.ECMConnectionInterrupted += FqHNrndXC6;
				connectionLostEventsProxy.ECMConnectionRestored += OTgN9AIVB3;
				GElNMRKpqS.SubscribeToEvents(ComponentIds.ConnectionManagerWorker, EventIDs.ConnectionLostEvents, connectionLostEventsProxy);
			}
			catch (InvalidOperationException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPAddIn, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void hRwNGO4bPY()
		{
			try
			{
				vXmNBmbbiS.LoadLicenses(rlvNI2Mfsf.GetProvider(FunctionProvider.Kernel), typeof(FnPAddIn).GUID);
			}
			catch (FileNotFoundException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPAddIn, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void GKTNZsF4AA()
		{
			if (GElNMRKpqS != null)
			{
				GElNMRKpqS.UnsubscribeFromEvents(ComponentIds.ConnectionManagerWorker, EventIDs.ConnectionEvents);
				GElNMRKpqS.UnsubscribeFromEvents(ComponentIds.ConnectionManagerWorker, EventIDs.ConManEventForFnP);
				GElNMRKpqS.UnsubscribeFromEvents(ComponentIds.PrefDispUI, EventIDs.PrefDispEvents);
				GElNMRKpqS.UnsubscribeFromEvents(ComponentIds.ToolSecurity, EventIDs.ToolSecurityEvents);
				GElNMRKpqS.UnsubscribeFromEvents(ComponentIds.ConnectionManagerWorker, EventIDs.ConnectionLostEvents);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void FLbNb18aWb(object P_0, ToolSecurityEventArgs P_1)
		{
			DcuNkyjXQL.ToolLevelChanged(P_1.ToolLevel);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void F6ONsUH7Kp(object P_0, GroupChangedEventArgs P_1)
		{
			DcuNkyjXQL.GroupChanged(P_1.GroupNum);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void VR0NPHIxkn(object P_0, EventArgs P_1)
		{
			DcuNkyjXQL.ConManRefresh();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void xqTNW6113J(object P_0, ConnectionTerminatedEventArgs P_1)
		{
			DcuNkyjXQL.ConnectionTerminated(P_1.ConnectionId);
			DcuNkyjXQL.IsECMConnectionInterrupted = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void BOQNvavNDB(object P_0, ConnectionEstablishedEventArgs P_1)
		{
			DcuNkyjXQL.ConnectionEstablished(P_1.ConnectionId, P_1.ConnectionStatus, this);
			DcuNkyjXQL.IsECMConnectionInterrupted = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void FqHNrndXC6(object P_0, EventArgs P_1)
		{
			DcuNkyjXQL.IsECMConnectionInterrupted = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void OTgN9AIVB3(object P_0, EventArgs P_1)
		{
			DcuNkyjXQL.IsECMConnectionInterrupted = false;
			DcuNkyjXQL.HandleConnectionRestablished();
			DcuNkyjXQL.RefreshAll();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void sqvNRvd9SJ(ToolBarButtonCollection P_0, string P_1, EnableFlag P_2, EnablerCallback P_3, HandlerCallback P_4)
		{
			if (P_0 != null)
			{
				ToolBarButton toolBarButton = new ToolBarButton();
				toolBarButton.ButtonId = P_1;
				toolBarButton.EnableFlags = P_2;
				toolBarButton.Enabler = P_3;
				toolBarButton.Handler = P_4;
				P_0.Add(toolBarButton);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void zFUNLiQEue()
		{
			try
			{
				ToolBarButtonCollection buttons = FVhNwlYZAn.Buttons;
				sqvNRvd9SJ(buttons, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(27874), (EnableFlag)6, DcuNkyjXQL.CanPrint, DcuNkyjXQL.Print);
				sqvNRvd9SJ(buttons, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(27964), (EnableFlag)6, DcuNkyjXQL.CanPrint, DcuNkyjXQL.PrintPreview);
				sqvNRvd9SJ(buttons, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(28058), (EnableFlag)6, DcuNkyjXQL.HasData, DcuNkyjXQL.RefreshAll);
				sqvNRvd9SJ(buttons, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(28152), (EnableFlag)6, DcuNkyjXQL.HasData, DcuNkyjXQL.Find);
				sqvNRvd9SJ(buttons, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(28240), EnableFlag.UserDefined, DcuNkyjXQL.HasData, DcuNkyjXQL.SendToECM);
				FVhNwlYZAn.SetToolBarCallbacks(rlvNI2Mfsf.GetProvider, null);
			}
			catch (InvalidOperationException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPAddIn, exception);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void hJSNcjndGx(MenuBarItemCollection P_0, string P_1, string P_2, EnableFlag P_3, int P_4, string P_5, EnablerCallback P_6, HandlerCallback P_7)
		{
			if (P_0 != null)
			{
				MenuBarItem menuBarItem = new MenuBarItem();
				menuBarItem.MenuItemId = P_1;
				menuBarItem.ParentId = P_2;
				menuBarItem.EnableFlags = P_3;
				menuBarItem.Style = P_4;
				menuBarItem.Text = P_5;
				menuBarItem.Enabler = P_6;
				menuBarItem.Handler = P_7;
				P_0.Add(menuBarItem);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qnCNTv17ha()
		{
			try
			{
				MenuBarItemCollection items = gfTNhXZEik.Items;
				hJSNcjndGx(items, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(28342), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(28440), (EnableFlag)6, 0, CPfNYOjfbw.GetLocalizedString(StringIdProvider.None), DcuNkyjXQL.CanPrint, DcuNkyjXQL.PageSetUp);
				hJSNcjndGx(items, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(28528), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(28632), (EnableFlag)6, 0, CPfNYOjfbw.GetLocalizedString(StringIdProvider.None), DcuNkyjXQL.CanPrint, DcuNkyjXQL.PrintPreview);
				hJSNcjndGx(items, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(28720), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(28810), (EnableFlag)6, 0, CPfNYOjfbw.GetLocalizedString(StringIdProvider.None), DcuNkyjXQL.CanPrint, DcuNkyjXQL.Print);
				hJSNcjndGx(items, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(28898), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(28996), EnableFlag.UserDefined, 0, CPfNYOjfbw.GetLocalizedString(StringIdProvider.None), DcuNkyjXQL.HasData, DcuNkyjXQL.SendToECM);
				hJSNcjndGx(items, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(29084), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(29172), (EnableFlag)6, 0, CPfNYOjfbw.GetLocalizedString(StringIdProvider.None), DcuNkyjXQL.HasData, DcuNkyjXQL.Find);
				hJSNcjndGx(items, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(29260), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(29366), (EnableFlag)6, 0, CPfNYOjfbw.GetLocalizedString(StringIdProvider.MenuBarFindNext), DcuNkyjXQL.HasData, DcuNkyjXQL.FindNext);
				hJSNcjndGx(items, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(29454), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(29554), (EnableFlag)12, 2048, CPfNYOjfbw.GetLocalizedString(StringIdProvider.None), null, null);
				hJSNcjndGx(items, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(29642), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(29776), (EnableFlag)6, 0, CPfNYOjfbw.GetLocalizedString(StringIdProvider.MenuBarRestoreAll), DcuNkyjXQL.HasData, DcuNkyjXQL.RestoreAllOriginalValues);
				hJSNcjndGx(items, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(29864), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(29962), (EnableFlag)6, 0, CPfNYOjfbw.GetLocalizedString(StringIdProvider.None), DcuNkyjXQL.HasData, DcuNkyjXQL.ExpandAll);
				hJSNcjndGx(items, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(30050), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(30152), (EnableFlag)6, 0, CPfNYOjfbw.GetLocalizedString(StringIdProvider.None), DcuNkyjXQL.HasData, DcuNkyjXQL.CollapseAll);
				hJSNcjndGx(items, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(30240), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(30334), (EnableFlag)6, 0, CPfNYOjfbw.GetLocalizedString(StringIdProvider.None), DcuNkyjXQL.HasData, DcuNkyjXQL.RefreshAll);
				gfTNhXZEik.SetMenuBarCallbacks(rlvNI2Mfsf.GetProvider, null);
			}
			catch (InvalidOperationException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.FnPAddIn, exception);
			}
		}
	}
}
namespace VFwHZlTNZDkF9HsxXy
{
	internal class wVU5sNcAu4EKHDLExx
	{
		private ECMDataReader KjdNFVUmEE;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public wVU5sNcAu4EKHDLExx(ECMDataReader P_0)
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
			KjdNFVUmEE = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string JvINejk1WK(string P_0, IFnPElement P_1, TooltipQueryType P_2)
		{
			if (string.IsNullOrEmpty(P_0))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(30422), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(30554));
			}
			StringBuilder stringBuilder = new StringBuilder();
			Regex regex = new Regex(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(30584));
			Match match = regex.Match(P_0);
			while (match.Success)
			{
				try
				{
					if (match.Value.Length > 0)
					{
						string value = match.Value;
						if (!string.IsNullOrEmpty(value))
						{
							string text = value.Substring(0, 2);
							if (text.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(30762)))
							{
								stringBuilder.Append(rL1NQ7tHh7(value, P_1, P_2));
							}
							else if (text.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(30770)))
							{
								stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(30778));
								stringBuilder.Append(AmVNK32ie8(value));
								stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(30784));
							}
							else if (text.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(30790)))
							{
								stringBuilder.Append(f24NyRc5Ul(value, P_1.ModuleId.ToString(CultureInfo.InvariantCulture)));
							}
							else if (text.Equals(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(30798)))
							{
								stringBuilder.Append(ot8NJymHYU(value));
							}
						}
					}
				}
				catch (ArgumentException exception)
				{
					FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.TooltipExpressionParser, exception);
				}
				catch (ECMDataReaderException exception2)
				{
					FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.TooltipExpressionParser, exception2);
				}
				match = match.NextMatch();
			}
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string rL1NQ7tHh7(string P_0, IFnPElement P_1, TooltipQueryType P_2)
		{
			if (string.IsNullOrEmpty(P_0))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(30806), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(30934));
			}
			if (P_1 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(30964), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31092));
			}
			string result = string.Empty;
			string empty = string.Empty;
			Regex regex = new Regex(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31110));
			Match match = regex.Match(P_0);
			empty = match.Value;
			if (TooltipQueryType.LockstateTooltipQuery == P_2)
			{
				int moduleId = P_1.ModuleId;
				result = KjdNFVUmEE.GetParameterFullName(moduleId, empty);
			}
			else if (TooltipQueryType.LimitsTooltipQuery == P_2 || TooltipQueryType.InvalidvalueTooltipQuery == P_2)
			{
				result = KjdNFVUmEE.GetParameterName(empty, P_1.ModuleId.ToString(CultureInfo.InvariantCulture));
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string AmVNK32ie8(string P_0)
		{
			if (string.IsNullOrEmpty(P_0))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31126), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31254));
			}
			string result = string.Empty;
			Regex regex = new Regex(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31284));
			Match match = regex.Match(P_0);
			if (match != null)
			{
				string value = match.Value;
				regex = new Regex(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31356));
				match = regex.Match(value);
				if (match != null)
				{
					result = match.Value;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string f24NyRc5Ul(string P_0, string P_1)
		{
			if (string.IsNullOrEmpty(P_0))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31424), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31554));
			}
			string result = string.Empty;
			string empty = string.Empty;
			Regex regex = new Regex(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31584));
			Match match = regex.Match(P_0);
			if (match != null)
			{
				empty = match.Value;
				result = KjdNFVUmEE.GetDisplayValueForTooltip(empty, P_1);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string ot8NJymHYU(string P_0)
		{
			if (string.IsNullOrEmpty(P_0))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31600), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31728));
			}
			string result = string.Empty;
			Regex regex = new Regex(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31758));
			Match match = regex.Match(P_0);
			if (match != null)
			{
				result = match.Value;
			}
			return result;
		}
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.Helper
{
	public static class FnPTraceLoger
	{
		private static object SBuNxqxkD5;

		private static bool G8TN0ZQWZp;

		private static uint Bl0NgrQXvB;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void OpenLogger(LoggerOption loggerOption)
		{
			if (aeVNlYuPL3())
			{
				lock (SBuNxqxkD5)
				{
					if (Bl0NgrQXvB == 0)
					{
						string text = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31774) + DateTime.Now.ToString(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31822), CultureInfo.InvariantCulture) + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31856);
						Trace.Listeners.Clear();
						if (LoggerOption.LogToFile == loggerOption)
						{
							FileInfo fileInfo = new FileInfo(text);
							if (fileInfo.Exists)
							{
								fileInfo.Delete();
							}
							Stream stream = File.Create(text);
							stream.Seek(0L, SeekOrigin.End);
							TextWriterTraceListener listener = new TextWriterTraceListener(stream);
							Trace.Listeners.Add(listener);
						}
						else if (LoggerOption.LogToDebugger == loggerOption)
						{
							Trace.Listeners.Add(new DefaultTraceListener());
						}
						else if (LoggerOption.LogToConsole == loggerOption)
						{
							Trace.Listeners.Add(new ConsoleTraceListener());
						}
						Trace.WriteLine(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31868));
						Trace.WriteLine(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(31974));
						Trace.WriteLine(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32080) + DateTime.Now);
						Trace.WriteLine(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32094));
						G8TN0ZQWZp = true;
						Bl0NgrQXvB++;
					}
					else
					{
						Bl0NgrQXvB++;
					}
					return;
				}
			}
			G8TN0ZQWZp = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void CloseLogger()
		{
			if (!aeVNlYuPL3())
			{
				return;
			}
			lock (SBuNxqxkD5)
			{
				if (--Bl0NgrQXvB == 0)
				{
					G8TN0ZQWZp = false;
					Trace.Close();
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void Log(LogCategory category, string message)
		{
			lock (SBuNxqxkD5)
			{
				if (category == LogCategory.None)
				{
					Trace.WriteLine(DateTime.Now.ToString(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32200), CultureInfo.InvariantCulture) + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32230) + message);
					return;
				}
				Trace.WriteLine(DateTime.Now.ToString(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32238), CultureInfo.InvariantCulture) + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32268) + category.ToString() + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32276) + message);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void Log(LogCategory category, string format, params object[] arguments)
		{
			lock (SBuNxqxkD5)
			{
				if (category == LogCategory.None)
				{
					Trace.WriteLine(DateTime.Now.ToString(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32284), CultureInfo.InvariantCulture) + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32320) + string.Format(CultureInfo.CurrentCulture, format, arguments));
					return;
				}
				Trace.WriteLine(DateTime.Now.ToString(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32328), CultureInfo.InvariantCulture) + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32364) + category.ToString() + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32372) + string.Format(CultureInfo.CurrentCulture, format, arguments));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void Log(LogCategory category, Exception exception)
		{
			lock (SBuNxqxkD5)
			{
				Log(category, exception.ToString());
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool TryLog(LogCategory category, Exception exception)
		{
			bool result = false;
			lock (SBuNxqxkD5)
			{
				if (G8TN0ZQWZp)
				{
					Log(category, exception);
					result = true;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool TryLog(LogCategory category, string message)
		{
			bool result = false;
			lock (SBuNxqxkD5)
			{
				if (G8TN0ZQWZp)
				{
					Log(category, message);
					result = true;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool TryLog(LogCategory category, string format, params object[] arguments)
		{
			bool result = false;
			lock (SBuNxqxkD5)
			{
				if (G8TN0ZQWZp)
				{
					Log(category, format, arguments);
					result = true;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static bool aeVNlYuPL3()
		{
			bool result = false;
			using (RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32380)))
			{
				if (registryKey != null)
				{
					result = bool.Parse(registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32584), false).ToString());
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static FnPTraceLoger()
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			SBuNxqxkD5 = new object();
		}
	}
	public class ECMDataReaderException : FnPAddInException
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMDataReaderException()
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMDataReaderException(string message)
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor(message);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMDataReaderException(string message, Exception innerException)
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor(message, innerException);
		}
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.View
{
	public sealed class FnPViewControl : UserControl, IFnPView, IViewEventPublisher
	{
		[CompilerGenerated]
		private sealed class <>c__DisplayClass4
		{
			public FnPViewControl <>4__this;

			public string item;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass4()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <Cummins.Insite.AddIns.FeaturesAndParameters.View.IFnPView.AddItem>b__2()
			{
				((IFnPView)<>4__this).AddItem(item);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass8
		{
			public FnPViewControl <>4__this;

			public string systemName;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass8()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <Cummins.Insite.AddIns.FeaturesAndParameters.View.IFnPView.AddSystemName>b__6()
			{
				((IFnPView)<>4__this).AddSystemName(systemName);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClassc
		{
			public FnPViewControl <>4__this;

			public string moduleName;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClassc()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <Cummins.Insite.AddIns.FeaturesAndParameters.View.IFnPView.AddModuleName>b__a()
			{
				((IFnPView)<>4__this).AddModuleName(moduleName);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass10
		{
			public FnPViewControl <>4__this;

			public int colIndex;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass10()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <Cummins.Insite.AddIns.FeaturesAndParameters.View.IFnPView.AutoSizeCol>b__e()
			{
				((IFnPView)<>4__this).AutoSizeCol(colIndex);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass16
		{
			public FnPViewControl <>4__this;

			public int rowIndex;

			public int colIndex;

			public string toolTipText;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass16()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <Cummins.Insite.AddIns.FeaturesAndParameters.View.IFnPView.DisplayTooltip>b__14()
			{
				((IFnPView)<>4__this).DisplayTooltip(rowIndex, colIndex, toolTipText);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass1e
		{
			public FnPViewControl <>4__this;

			public int rowIndex;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass1e()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <Cummins.Insite.AddIns.FeaturesAndParameters.View.IFnPView.SelectRow>b__1c()
			{
				((IFnPView)<>4__this).SelectRow(rowIndex);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass24
		{
			public FnPViewControl <>4__this;

			public PropertyDescriptor propertyDescriptor;

			public int rowIndex;

			public int columnIndex;

			public object value;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass24()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <Cummins.Insite.AddIns.FeaturesAndParameters.View.IFnPView.SetValue>b__22()
			{
				((IFnPView)<>4__this).SetValue(propertyDescriptor, rowIndex, columnIndex, value);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass28
		{
			public FnPViewControl <>4__this;

			public bool enable;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass28()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <Cummins.Insite.AddIns.FeaturesAndParameters.View.IFnPView.EnableUI>b__26()
			{
				((IFnPView)<>4__this).EnableUI(enable);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass2c
		{
			public FnPViewControl <>4__this;

			public string itemList;

			public int rowid;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass2c()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <SetDropdownList>b__2a()
			{
				<>4__this.dUxNqtv58b(itemList, rowid);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass30
		{
			public FnPViewControl <>4__this;

			public int rowId;

			public string editMask;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass30()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <SetEditMask>b__2e()
			{
				<>4__this.aSwN8qUBTJ(rowId, editMask);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass34
		{
			public FnPViewControl <>4__this;

			public bool redraw;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass34()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <SetRedraw>b__32()
			{
				<>4__this.TRHNiddbt1(redraw);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass38
		{
			public FnPViewControl <>4__this;

			public int rowIndex;

			public bool isRowCollapse;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass38()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <SetRowCollapse>b__36()
			{
				<>4__this.zq7NjgO3IF(rowIndex, isRowCollapse);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass3c
		{
			public FnPViewControl <>4__this;

			public int rowid;

			public bool hide;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass3c()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <SetRowHidden>b__3a()
			{
				<>4__this.lWRNOTT6do(rowid, hide);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass40
		{
			public FnPViewControl <>4__this;

			public int column;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass40()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <SetCurrentColumn>b__3e()
			{
				<>4__this.J0QNXBGpXK(column);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass44
		{
			public FnPViewControl <>4__this;

			public int row;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass44()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <SetCurrentRow>b__42()
			{
				<>4__this.auwNC3brJW(row);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass48
		{
			public FnPViewControl <>4__this;

			public int count;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass48()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <SetRowCount>b__46()
			{
				<>4__this.gCYNE3VoU4(count);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass4c
		{
			public FnPViewControl <>4__this;

			public Cursor cursor;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass4c()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <SetCursor>b__4a()
			{
				<>4__this.EOdN1kNajQ(cursor);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass50
		{
			public FnPViewControl <>4__this;

			public AnchorStyles anchorStyle;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass50()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <SetAnchor>b__4e()
			{
				//IL_000e: Unknown result type (might be due to invalid IL or missing references)
				<>4__this.fZcNfMdKPB(anchorStyle);
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass54
		{
			public FnPViewControl <>4__this;

			public GridProperties gridProperties;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass54()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <SetGridProperties>b__52()
			{
				<>4__this.iiTN6jW1Nv(gridProperties);
			}
		}

		private C1FlexGrid gthdIiefK6;

		private RowColEventHandler rYTdu0QIHX;

		private RowColEventHandler MlTdk8Utyb;

		private RangeEventHandler xJOdUFZnV5;

		private RowColEventHandler XqEdMxVc97;

		private RowColEventHandler ak0dwXuKb4;

		private KeyEventHandler DHVdhbjufN;

		private KeyPressEditEventHandler H4adAPG9Ps;

		private KeyEventHandler MqydBrgvnu;

		private MouseEventHandler SH0devwYLc;

		private MouseEventHandler S3qdQZq059;

		private RowColEventHandler vkcdKErPpP;

		private ValidateEditEventHandler adodyAJ9VC;

		private int RnOdJIJHgs;

		private ILocalizedStringProvider PKadFLxUZr;

		private ToolTip CvTdlym1Lr;

		private TooltipActiveState w2edxHjeYL;

		private EventHandler xpud0VBIjV;

		private IConfigService nG0dg1Pi5D;

		private int TIod7wpY0h;

		private IContainer euIdqLtSbZ;

		int IFnPView.EditSelStart
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				int result = 0;
				Control editor = gthdIiefK6.Editor;
				TextBox val = (TextBox)(object)((editor is TextBox) ? editor : null);
				if (val != null)
				{
					result = ((TextBoxBase)val).SelectionStart;
				}
				else
				{
					ComboBox val2 = (ComboBox)(object)((editor is ComboBox) ? editor : null);
					if (val2 != null)
					{
						result = val2.SelectionStart;
					}
				}
				return result;
			}
		}

		int IFnPView.CurrentColumn
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return gthdIiefK6.Col;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				J0QNXBGpXK(value);
			}
		}

		int IFnPView.CurrentRow
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return gthdIiefK6.Row;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				auwNC3brJW(value);
			}
		}

		string IFnPView.EditText
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return gthdIiefK6.Editor.Text;
			}
		}

		IntPtr IFnPView.Handle
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ((Control)this).Handle;
			}
		}

		int IFnPView.MouseColumn
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return gthdIiefK6.MouseCol;
			}
		}

		int IFnPView.MouseRow
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return gthdIiefK6.MouseRow;
			}
		}

		TooltipActiveState IFnPView.TooltipState
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return w2edxHjeYL;
			}
		}

		GridProperties IFnPView.GridProperties
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return AYNDNJM3e1();
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				iiTN6jW1Nv(value);
			}
		}

		int IFnPView.RowsCount
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return gthdIiefK6.Rows.Count;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				gCYNE3VoU4(value);
			}
		}

		AnchorStyles IFnPView.Anchor
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				//IL_0008: Unknown result type (might be due to invalid IL or missing references)
				fZcNfMdKPB(value);
			}
		}

		Cursor IFnPView.Cursor
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				EOdN1kNajQ(value);
			}
		}

		private event RowColEventHandler mGrDJKjlvI
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				RowColEventHandler rowColEventHandler = rYTdu0QIHX;
				RowColEventHandler rowColEventHandler2;
				do
				{
					rowColEventHandler2 = rowColEventHandler;
					RowColEventHandler value2 = (RowColEventHandler)Delegate.Combine(rowColEventHandler2, value);
					rowColEventHandler = Interlocked.CompareExchange(ref rYTdu0QIHX, value2, rowColEventHandler2);
				}
				while ((object)rowColEventHandler != rowColEventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				RowColEventHandler rowColEventHandler = rYTdu0QIHX;
				RowColEventHandler rowColEventHandler2;
				do
				{
					rowColEventHandler2 = rowColEventHandler;
					RowColEventHandler value2 = (RowColEventHandler)Delegate.Remove(rowColEventHandler2, value);
					rowColEventHandler = Interlocked.CompareExchange(ref rYTdu0QIHX, value2, rowColEventHandler2);
				}
				while ((object)rowColEventHandler != rowColEventHandler2);
			}
		}

		private event RowColEventHandler wK4D0bmwXi
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				RowColEventHandler rowColEventHandler = MlTdk8Utyb;
				RowColEventHandler rowColEventHandler2;
				do
				{
					rowColEventHandler2 = rowColEventHandler;
					RowColEventHandler value2 = (RowColEventHandler)Delegate.Combine(rowColEventHandler2, value);
					rowColEventHandler = Interlocked.CompareExchange(ref MlTdk8Utyb, value2, rowColEventHandler2);
				}
				while ((object)rowColEventHandler != rowColEventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				RowColEventHandler rowColEventHandler = MlTdk8Utyb;
				RowColEventHandler rowColEventHandler2;
				do
				{
					rowColEventHandler2 = rowColEventHandler;
					RowColEventHandler value2 = (RowColEventHandler)Delegate.Remove(rowColEventHandler2, value);
					rowColEventHandler = Interlocked.CompareExchange(ref MlTdk8Utyb, value2, rowColEventHandler2);
				}
				while ((object)rowColEventHandler != rowColEventHandler2);
			}
		}

		private event RangeEventHandler MNJD8kfQsw
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				RangeEventHandler rangeEventHandler = xJOdUFZnV5;
				RangeEventHandler rangeEventHandler2;
				do
				{
					rangeEventHandler2 = rangeEventHandler;
					RangeEventHandler value2 = (RangeEventHandler)Delegate.Combine(rangeEventHandler2, value);
					rangeEventHandler = Interlocked.CompareExchange(ref xJOdUFZnV5, value2, rangeEventHandler2);
				}
				while ((object)rangeEventHandler != rangeEventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				RangeEventHandler rangeEventHandler = xJOdUFZnV5;
				RangeEventHandler rangeEventHandler2;
				do
				{
					rangeEventHandler2 = rangeEventHandler;
					RangeEventHandler value2 = (RangeEventHandler)Delegate.Remove(rangeEventHandler2, value);
					rangeEventHandler = Interlocked.CompareExchange(ref xJOdUFZnV5, value2, rangeEventHandler2);
				}
				while ((object)rangeEventHandler != rangeEventHandler2);
			}
		}

		private event RowColEventHandler f9IDXHDhQ1
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				RowColEventHandler rowColEventHandler = XqEdMxVc97;
				RowColEventHandler rowColEventHandler2;
				do
				{
					rowColEventHandler2 = rowColEventHandler;
					RowColEventHandler value2 = (RowColEventHandler)Delegate.Combine(rowColEventHandler2, value);
					rowColEventHandler = Interlocked.CompareExchange(ref XqEdMxVc97, value2, rowColEventHandler2);
				}
				while ((object)rowColEventHandler != rowColEventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				RowColEventHandler rowColEventHandler = XqEdMxVc97;
				RowColEventHandler rowColEventHandler2;
				do
				{
					rowColEventHandler2 = rowColEventHandler;
					RowColEventHandler value2 = (RowColEventHandler)Delegate.Remove(rowColEventHandler2, value);
					rowColEventHandler = Interlocked.CompareExchange(ref XqEdMxVc97, value2, rowColEventHandler2);
				}
				while ((object)rowColEventHandler != rowColEventHandler2);
			}
		}

		private event RowColEventHandler YW9DfJXi8N
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				RowColEventHandler rowColEventHandler = ak0dwXuKb4;
				RowColEventHandler rowColEventHandler2;
				do
				{
					rowColEventHandler2 = rowColEventHandler;
					RowColEventHandler value2 = (RowColEventHandler)Delegate.Combine(rowColEventHandler2, value);
					rowColEventHandler = Interlocked.CompareExchange(ref ak0dwXuKb4, value2, rowColEventHandler2);
				}
				while ((object)rowColEventHandler != rowColEventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				RowColEventHandler rowColEventHandler = ak0dwXuKb4;
				RowColEventHandler rowColEventHandler2;
				do
				{
					rowColEventHandler2 = rowColEventHandler;
					RowColEventHandler value2 = (RowColEventHandler)Delegate.Remove(rowColEventHandler2, value);
					rowColEventHandler = Interlocked.CompareExchange(ref ak0dwXuKb4, value2, rowColEventHandler2);
				}
				while ((object)rowColEventHandler != rowColEventHandler2);
			}
		}

		private event KeyEventHandler zWoD6U69Qs
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				//IL_0017: Unknown result type (might be due to invalid IL or missing references)
				//IL_001d: Expected O, but got Unknown
				KeyEventHandler val = DHVdhbjufN;
				KeyEventHandler val2;
				do
				{
					val2 = val;
					KeyEventHandler value2 = (KeyEventHandler)Delegate.Combine((Delegate?)(object)val2, (Delegate?)(object)value);
					val = Interlocked.CompareExchange(ref DHVdhbjufN, value2, val2);
				}
				while (val != val2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				//IL_0017: Unknown result type (might be due to invalid IL or missing references)
				//IL_001d: Expected O, but got Unknown
				KeyEventHandler val = DHVdhbjufN;
				KeyEventHandler val2;
				do
				{
					val2 = val;
					KeyEventHandler value2 = (KeyEventHandler)Delegate.Remove((Delegate?)(object)val2, (Delegate?)(object)value);
					val = Interlocked.CompareExchange(ref DHVdhbjufN, value2, val2);
				}
				while (val != val2);
			}
		}

		private event KeyPressEditEventHandler AIXDzq7hOS
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				KeyPressEditEventHandler keyPressEditEventHandler = H4adAPG9Ps;
				KeyPressEditEventHandler keyPressEditEventHandler2;
				do
				{
					keyPressEditEventHandler2 = keyPressEditEventHandler;
					KeyPressEditEventHandler value2 = (KeyPressEditEventHandler)Delegate.Combine(keyPressEditEventHandler2, value);
					keyPressEditEventHandler = Interlocked.CompareExchange(ref H4adAPG9Ps, value2, keyPressEditEventHandler2);
				}
				while ((object)keyPressEditEventHandler != keyPressEditEventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				KeyPressEditEventHandler keyPressEditEventHandler = H4adAPG9Ps;
				KeyPressEditEventHandler keyPressEditEventHandler2;
				do
				{
					keyPressEditEventHandler2 = keyPressEditEventHandler;
					KeyPressEditEventHandler value2 = (KeyPressEditEventHandler)Delegate.Remove(keyPressEditEventHandler2, value);
					keyPressEditEventHandler = Interlocked.CompareExchange(ref H4adAPG9Ps, value2, keyPressEditEventHandler2);
				}
				while ((object)keyPressEditEventHandler != keyPressEditEventHandler2);
			}
		}

		private event KeyEventHandler GipdV3nnRe
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				//IL_0017: Unknown result type (might be due to invalid IL or missing references)
				//IL_001d: Expected O, but got Unknown
				KeyEventHandler val = MqydBrgvnu;
				KeyEventHandler val2;
				do
				{
					val2 = val;
					KeyEventHandler value2 = (KeyEventHandler)Delegate.Combine((Delegate?)(object)val2, (Delegate?)(object)value);
					val = Interlocked.CompareExchange(ref MqydBrgvnu, value2, val2);
				}
				while (val != val2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				//IL_0017: Unknown result type (might be due to invalid IL or missing references)
				//IL_001d: Expected O, but got Unknown
				KeyEventHandler val = MqydBrgvnu;
				KeyEventHandler val2;
				do
				{
					val2 = val;
					KeyEventHandler value2 = (KeyEventHandler)Delegate.Remove((Delegate?)(object)val2, (Delegate?)(object)value);
					val = Interlocked.CompareExchange(ref MqydBrgvnu, value2, val2);
				}
				while (val != val2);
			}
		}

		private event MouseEventHandler WANdddkaLk
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				//IL_0017: Unknown result type (might be due to invalid IL or missing references)
				//IL_001d: Expected O, but got Unknown
				MouseEventHandler val = SH0devwYLc;
				MouseEventHandler val2;
				do
				{
					val2 = val;
					MouseEventHandler value2 = (MouseEventHandler)Delegate.Combine((Delegate?)(object)val2, (Delegate?)(object)value);
					val = Interlocked.CompareExchange(ref SH0devwYLc, value2, val2);
				}
				while (val != val2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				//IL_0017: Unknown result type (might be due to invalid IL or missing references)
				//IL_001d: Expected O, but got Unknown
				MouseEventHandler val = SH0devwYLc;
				MouseEventHandler val2;
				do
				{
					val2 = val;
					MouseEventHandler value2 = (MouseEventHandler)Delegate.Remove((Delegate?)(object)val2, (Delegate?)(object)value);
					val = Interlocked.CompareExchange(ref SH0devwYLc, value2, val2);
				}
				while (val != val2);
			}
		}

		private event MouseEventHandler M64dZjm6Mk
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				//IL_0017: Unknown result type (might be due to invalid IL or missing references)
				//IL_001d: Expected O, but got Unknown
				MouseEventHandler val = S3qdQZq059;
				MouseEventHandler val2;
				do
				{
					val2 = val;
					MouseEventHandler value2 = (MouseEventHandler)Delegate.Combine((Delegate?)(object)val2, (Delegate?)(object)value);
					val = Interlocked.CompareExchange(ref S3qdQZq059, value2, val2);
				}
				while (val != val2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				//IL_0017: Unknown result type (might be due to invalid IL or missing references)
				//IL_001d: Expected O, but got Unknown
				MouseEventHandler val = S3qdQZq059;
				MouseEventHandler val2;
				do
				{
					val2 = val;
					MouseEventHandler value2 = (MouseEventHandler)Delegate.Remove((Delegate?)(object)val2, (Delegate?)(object)value);
					val = Interlocked.CompareExchange(ref S3qdQZq059, value2, val2);
				}
				while (val != val2);
			}
		}

		private event RowColEventHandler XNFdWSoTml
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				RowColEventHandler rowColEventHandler = vkcdKErPpP;
				RowColEventHandler rowColEventHandler2;
				do
				{
					rowColEventHandler2 = rowColEventHandler;
					RowColEventHandler value2 = (RowColEventHandler)Delegate.Combine(rowColEventHandler2, value);
					rowColEventHandler = Interlocked.CompareExchange(ref vkcdKErPpP, value2, rowColEventHandler2);
				}
				while ((object)rowColEventHandler != rowColEventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				RowColEventHandler rowColEventHandler = vkcdKErPpP;
				RowColEventHandler rowColEventHandler2;
				do
				{
					rowColEventHandler2 = rowColEventHandler;
					RowColEventHandler value2 = (RowColEventHandler)Delegate.Remove(rowColEventHandler2, value);
					rowColEventHandler = Interlocked.CompareExchange(ref vkcdKErPpP, value2, rowColEventHandler2);
				}
				while ((object)rowColEventHandler != rowColEventHandler2);
			}
		}

		private event ValidateEditEventHandler GA5dRO5eKE
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				ValidateEditEventHandler validateEditEventHandler = adodyAJ9VC;
				ValidateEditEventHandler validateEditEventHandler2;
				do
				{
					validateEditEventHandler2 = validateEditEventHandler;
					ValidateEditEventHandler value2 = (ValidateEditEventHandler)Delegate.Combine(validateEditEventHandler2, value);
					validateEditEventHandler = Interlocked.CompareExchange(ref adodyAJ9VC, value2, validateEditEventHandler2);
				}
				while ((object)validateEditEventHandler != validateEditEventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				ValidateEditEventHandler validateEditEventHandler = adodyAJ9VC;
				ValidateEditEventHandler validateEditEventHandler2;
				do
				{
					validateEditEventHandler2 = validateEditEventHandler;
					ValidateEditEventHandler value2 = (ValidateEditEventHandler)Delegate.Remove(validateEditEventHandler2, value);
					validateEditEventHandler = Interlocked.CompareExchange(ref adodyAJ9VC, value2, validateEditEventHandler2);
				}
				while ((object)validateEditEventHandler != validateEditEventHandler2);
			}
		}

		private event EventHandler lBWdY1Pugp
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler eventHandler = xpud0VBIjV;
				EventHandler eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref xpud0VBIjV, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler eventHandler = xpud0VBIjV;
				EventHandler eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref xpud0VBIjV, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		event RowColEventHandler IViewEventPublisher.AfterCollapse
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				mGrDJKjlvI += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				mGrDJKjlvI -= value;
			}
		}

		event RowColEventHandler IViewEventPublisher.AfterEdit
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				wK4D0bmwXi += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				wK4D0bmwXi -= value;
			}
		}

		event RangeEventHandler IViewEventPublisher.AfterRowColChange
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				MNJD8kfQsw += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				MNJD8kfQsw -= value;
			}
		}

		event RowColEventHandler IViewEventPublisher.BeforeCollapse
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				f9IDXHDhQ1 += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				f9IDXHDhQ1 -= value;
			}
		}

		event RowColEventHandler IViewEventPublisher.BeforeEdit
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				YW9DfJXi8N += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				YW9DfJXi8N -= value;
			}
		}

		event EventHandler IViewEventPublisher.ViewLoaded
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lBWdY1Pugp += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lBWdY1Pugp -= value;
			}
		}

		event KeyPressEditEventHandler IViewEventPublisher.KeyPressEdit
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				AIXDzq7hOS += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				AIXDzq7hOS -= value;
			}
		}

		event KeyEventHandler IViewEventPublisher.KeyDown
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				zWoD6U69Qs += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				zWoD6U69Qs -= value;
			}
		}

		event KeyEventHandler IViewEventPublisher.KeyUp
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				GipdV3nnRe += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				GipdV3nnRe -= value;
			}
		}

		event MouseEventHandler IViewEventPublisher.MouseDown
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				WANdddkaLk += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				WANdddkaLk -= value;
			}
		}

		event MouseEventHandler IViewEventPublisher.MouseMove
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				M64dZjm6Mk += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				M64dZjm6Mk -= value;
			}
		}

		event RowColEventHandler IViewEventPublisher.StartEdit
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				XNFdWSoTml += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				XNFdWSoTml -= value;
			}
		}

		event ValidateEditEventHandler IViewEventPublisher.ValidateEdit
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				GA5dRO5eKE += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				GA5dRO5eKE -= value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal FnPViewControl(int lhwndParent, IConfigService configService)
		{
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			((UserControl)this)..ctor();
			IFyDM2Kko0();
			nG0dg1Pi5D = configService;
			gthdIiefK6 = new C1FlexGrid();
			RnOdJIJHgs = lhwndParent;
			CvTdlym1Lr = new ToolTip();
			CvTdlym1Lr.IsBalloon = true;
			CvTdlym1Lr.InitialDelay = 500;
			PKadFLxUZr = Factory.CreateInstance<ILocalizedStringProvider>();
			PKadFLxUZr.Initialize(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32606));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal FnPViewControl()
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			((UserControl)this)..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AutoSizeRows()
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			MethodInvoker val = null;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						((IFnPView)this).AutoSizeRows();
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				gthdIiefK6.AutoSizeRows();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AddItem(string item)
		{
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass4 CS$<>8__locals5 = new <>c__DisplayClass4();
			CS$<>8__locals5.item = item;
			CS$<>8__locals5.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						((IFnPView)CS$<>8__locals5.<>4__this).AddItem(CS$<>8__locals5.item);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				Row row = gthdIiefK6.AddItem(CS$<>8__locals5.item);
				row.IsNode = true;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AddSystemName(string systemName)
		{
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass8 CS$<>8__locals5 = new <>c__DisplayClass8();
			CS$<>8__locals5.systemName = systemName;
			CS$<>8__locals5.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						((IFnPView)CS$<>8__locals5.<>4__this).AddSystemName(CS$<>8__locals5.systemName);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				Row row = gthdIiefK6.AddItem(CS$<>8__locals5.systemName);
				row.IsNode = true;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AddModuleName(string moduleName)
		{
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClassc CS$<>8__locals5 = new <>c__DisplayClassc();
			CS$<>8__locals5.moduleName = moduleName;
			CS$<>8__locals5.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						((IFnPView)CS$<>8__locals5.<>4__this).AddModuleName(CS$<>8__locals5.moduleName);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				Row row = gthdIiefK6.AddItem(CS$<>8__locals5.moduleName);
				row.IsNode = true;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AutoSizeCol(int colIndex)
		{
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass10 CS$<>8__locals5 = new <>c__DisplayClass10();
			CS$<>8__locals5.colIndex = colIndex;
			CS$<>8__locals5.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						((IFnPView)CS$<>8__locals5.<>4__this).AutoSizeCol(CS$<>8__locals5.colIndex);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				gthdIiefK6.Redraw = false;
				gthdIiefK6.AutoSizeCol(CS$<>8__locals5.colIndex);
				gthdIiefK6.AutoSizeRows();
				gthdIiefK6.Redraw = true;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.AutoSizeCols()
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			MethodInvoker val = null;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						((IFnPView)this).AutoSizeCols();
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				gthdIiefK6.Redraw = false;
				gthdIiefK6.AutoSizeCols();
				gthdIiefK6.AutoSizeRows();
				gthdIiefK6.Redraw = true;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		Rectangle IFnPView.GetCellRect(int row, int col)
		{
			return gthdIiefK6.GetCellRect(row, col);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		DialogResult IFnPView.DisplayMessage(string message, string caption, MessageBoxButtons buttons, MessageBoxIcon icon)
		{
			//IL_000a: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Unknown result type (might be due to invalid IL or missing references)
			//IL_000e: Unknown result type (might be due to invalid IL or missing references)
			return MessageBox.Show((IWin32Window)(object)this, message, caption, buttons, icon, (MessageBoxDefaultButton)0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.DisplayTooltip(int rowIndex, int colIndex, string toolTipText)
		{
			//IL_0044: Unknown result type (might be due to invalid IL or missing references)
			//IL_004a: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass16 CS$<>8__locals14 = new <>c__DisplayClass16();
			CS$<>8__locals14.rowIndex = rowIndex;
			CS$<>8__locals14.colIndex = colIndex;
			CS$<>8__locals14.toolTipText = toolTipText;
			CS$<>8__locals14.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						((IFnPView)CS$<>8__locals14.<>4__this).DisplayTooltip(CS$<>8__locals14.rowIndex, CS$<>8__locals14.colIndex, CS$<>8__locals14.toolTipText);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else if (CS$<>8__locals14.rowIndex >= 0 && CS$<>8__locals14.colIndex >= 0)
			{
				Point point = WDyNmQ7RRc(CS$<>8__locals14.rowIndex, CS$<>8__locals14.colIndex);
				if (point.X > 0 && point.Y > 0 && point.X < ((Control)gthdIiefK6).Width && point.Y < ((Control)gthdIiefK6).Height)
				{
					CvTdlym1Lr.Show("", (IWin32Window)(object)gthdIiefK6, point);
					CvTdlym1Lr.SetToolTip((Control)(object)gthdIiefK6, CS$<>8__locals14.toolTipText);
					CvTdlym1Lr.Show(CS$<>8__locals14.toolTipText, (IWin32Window)(object)gthdIiefK6, point);
					w2edxHjeYL = TooltipActiveState.ActiveHove;
				}
			}
			else
			{
				CvTdlym1Lr.Hide((IWin32Window)(object)gthdIiefK6);
				CvTdlym1Lr.RemoveAll();
				w2edxHjeYL = TooltipActiveState.None;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		string IFnPView.GetFnPData()
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32684));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		int IFnPView.GetParentRowIndex(int rowIndex)
		{
			return gthdIiefK6.Rows[rowIndex].Node.GetNode(NodeTypeEnum.Parent).Row.Index;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPView.GetRowCollapse(int rowIndex)
		{
			return gthdIiefK6.Rows[rowIndex].Node.Collapsed;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		Node IFnPView.GetRowNode(int rowIndex)
		{
			return gthdIiefK6.Rows[rowIndex].Node;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		int IFnPView.GetRowOutlineLevel(int rowIndex)
		{
			return gthdIiefK6.Rows[rowIndex].Node.Level;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		object IFnPView.GetValue(PropertyDescriptor propertyDescriptor, int rowIndex, int columnIndex)
		{
			object result = null;
			switch (propertyDescriptor)
			{
			case PropertyDescriptor.Picture:
				result = gthdIiefK6.Rows[rowIndex].Node.Image;
				break;
			case PropertyDescriptor.Value:
				result = gthdIiefK6[rowIndex, columnIndex];
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.HideTooltip()
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			MethodInvoker val = null;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						((IFnPView)this).HideTooltip();
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				CvTdlym1Lr.Hide((IWin32Window)(object)gthdIiefK6);
				CvTdlym1Lr.RemoveAll();
				w2edxHjeYL = TooltipActiveState.None;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPView.IsRowHidden(int rowIndex)
		{
			return !gthdIiefK6.Rows[rowIndex].Visible;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		bool IFnPView.IsVisible()
		{
			return ((Control)this).Visible;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PrintGrid(PrintProperties printProperties)
		{
			//IL_00f9: Unknown result type (might be due to invalid IL or missing references)
			//IL_00fe: Unknown result type (might be due to invalid IL or missing references)
			//IL_0108: Expected O, but got Unknown
			//IL_014e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0153: Unknown result type (might be due to invalid IL or missing references)
			//IL_015d: Expected O, but got Unknown
			//IL_002c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0031: Unknown result type (might be due to invalid IL or missing references)
			//IL_003b: Expected O, but got Unknown
			//IL_0082: Unknown result type (might be due to invalid IL or missing references)
			//IL_0087: Unknown result type (might be due to invalid IL or missing references)
			//IL_0091: Expected O, but got Unknown
			//IL_00b5: Unknown result type (might be due to invalid IL or missing references)
			//IL_00bb: Invalid comparison between Unknown and I4
			GridProperties gridProperties = AYNDNJM3e1();
			((Control)gthdIiefK6).Font = new Font(gridProperties.FontName, (float)printProperties.PrintFontSize, ((Control)gthdIiefK6).Font.Style);
			gthdIiefK6.Styles[NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32774)].Font = new Font(gridProperties.FontName, (float)printProperties.PrintFontSize, gthdIiefK6.Styles[NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32802)].Font.Style);
			try
			{
				dcdN2BamjJ(printProperties);
				PrintDialog val = WEFN4r9bI5();
				val.Document = gthdIiefK6.PrintParameters.PrintDocument;
				if ((int)((CommonDialog)val).ShowDialog() == 1)
				{
					val.Document.Print();
				}
			}
			catch
			{
			}
			finally
			{
				((Control)gthdIiefK6).Font = new Font(gridProperties.FontName, (float)gridProperties.FontSize, ((Control)gthdIiefK6).Font.Style);
				gthdIiefK6.Styles[NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32830)].Font = new Font(gridProperties.FontName, (float)gridProperties.FontSize, gthdIiefK6.Styles[NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32858)].Font.Style);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PrintTo()
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32886));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PutEditMask(int rowId, string editMask)
		{
			aSwN8qUBTJ(rowId, editMask);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PutRedraw(bool redraw)
		{
			TRHNiddbt1(redraw);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PutRowCollapse(int rowIndex, bool isRowCollapse)
		{
			zq7NjgO3IF(rowIndex, isRowCollapse);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.PutRowHidden(int rowid, bool hide)
		{
			lWRNOTT6do(rowid, hide);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.ResizeView()
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			MethodInvoker val = null;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						((IFnPView)this).ResizeView();
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				NativeMethods.v7cHDalfY(NativeMethods.AmZDN6Oeq(new IntPtr(RnOdJIJHgs)), out var vOrETEDXiCV9UWxCsJ);
				C1FlexGrid c1FlexGrid = gthdIiefK6;
				int width = (((Control)this).Width = vOrETEDXiCV9UWxCsJ.dVmZRUuOr - vOrETEDXiCV9UWxCsJ.tdDSfOi9M);
				((Control)c1FlexGrid).Width = width;
				C1FlexGrid c1FlexGrid2 = gthdIiefK6;
				int height = (((Control)this).Height = vOrETEDXiCV9UWxCsJ.RTEbXiCV9 - vOrETEDXiCV9UWxCsJ.qEQG4D5oZ);
				((Control)c1FlexGrid2).Height = height;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.SelectRow(int rowIndex)
		{
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass1e CS$<>8__locals5 = new <>c__DisplayClass1e();
			CS$<>8__locals5.rowIndex = rowIndex;
			CS$<>8__locals5.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						((IFnPView)CS$<>8__locals5.<>4__this).SelectRow(CS$<>8__locals5.rowIndex);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				gthdIiefK6.Select(CS$<>8__locals5.rowIndex, 0);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.SetComboDropdownList(string itemList, int rowid)
		{
			dUxNqtv58b(itemList, rowid);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.SetupView()
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			MethodInvoker val = null;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						((IFnPView)this).SetupView();
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
				return;
			}
			NativeMethods.scLdwS2KT(((Control)gthdIiefK6).Handle, ((Control)this).Handle);
			NativeMethods.v7cHDalfY(NativeMethods.AmZDN6Oeq(new IntPtr(RnOdJIJHgs)), out var vOrETEDXiCV9UWxCsJ);
			C1FlexGrid c1FlexGrid = gthdIiefK6;
			int width = (((Control)this).Width = vOrETEDXiCV9UWxCsJ.dVmZRUuOr - vOrETEDXiCV9UWxCsJ.tdDSfOi9M);
			((Control)c1FlexGrid).Width = width;
			int tIod7wpY0h = (((Control)this).Width = vOrETEDXiCV9UWxCsJ.dVmZRUuOr - vOrETEDXiCV9UWxCsJ.tdDSfOi9M);
			TIod7wpY0h = tIod7wpY0h;
			C1FlexGrid c1FlexGrid2 = gthdIiefK6;
			int height = (((Control)this).Height = vOrETEDXiCV9UWxCsJ.RTEbXiCV9 - vOrETEDXiCV9UWxCsJ.qEQG4D5oZ);
			((Control)c1FlexGrid2).Height = height;
			((Control)gthdIiefK6).Anchor = (AnchorStyles)15;
			gthdIiefK6.Rows.Count = 1;
			gthdIiefK6.Cols.Count = 4;
			gthdIiefK6.Rows.Fixed = 1;
			gthdIiefK6.Cols.Fixed = -1;
			qJiDDIJm8n();
			gthdIiefK6.ExtendLastCol = true;
			string[] array = PKadFLxUZr.GetLocalizedString(StringIdProvider.FeaturesAndParametersHeader).Split(new char[1] { '|' });
			gthdIiefK6[0, 0] = array[0];
			gthdIiefK6[0, 1] = array[1];
			gthdIiefK6[0, 2] = array[2];
			gthdIiefK6[0, 3] = array[3];
			gthdIiefK6.SetUserData(0, 0, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(32976));
			gthdIiefK6.SetUserData(0, 1, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33036));
			gthdIiefK6.SetUserData(0, 2, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33082));
			gthdIiefK6.SetUserData(0, 3, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33124));
			gthdIiefK6.Cols[0].TextAlign = TextAlignEnum.LeftCenter;
			gthdIiefK6.Cols[0].TextAlignFixed = TextAlignEnum.LeftBottom;
			gthdIiefK6.Cols[1].TextAlign = TextAlignEnum.RightCenter;
			gthdIiefK6.Cols[1].TextAlignFixed = TextAlignEnum.RightBottom;
			gthdIiefK6.Cols[2].TextAlign = TextAlignEnum.LeftCenter;
			gthdIiefK6.Cols[2].TextAlignFixed = TextAlignEnum.LeftBottom;
			gthdIiefK6.Cols[3].TextAlign = TextAlignEnum.LeftCenter;
			gthdIiefK6.Cols[3].TextAlignFixed = TextAlignEnum.LeftBottom;
			gthdIiefK6.Tree.Column = 0;
			gthdIiefK6.Tree.Style = TreeStyleFlags.Simple;
			gthdIiefK6.ScrollBars = (ScrollBars)3;
			gthdIiefK6.AllowResizing = AllowResizingEnum.Both;
			gthdIiefK6.AllowDragging = AllowDraggingEnum.None;
			gthdIiefK6.AllowSorting = AllowSortingEnum.None;
			gthdIiefK6.Styles.Normal.Trimming = (StringTrimming)3;
			gthdIiefK6.KeyActionTab = KeyActionEnum.MoveAcross;
			gthdIiefK6.SelectionMode = SelectionModeEnum.Row;
			gthdIiefK6.HighLight = HighLightEnum.Always;
			gthdIiefK6.FocusRect = FocusRectEnum.Heavy;
			gthdIiefK6.Styles.Focus.BackColor = gthdIiefK6.Styles.Highlight.BackColor;
			gthdIiefK6.Styles.Focus.ForeColor = gthdIiefK6.Styles.Highlight.ForeColor;
			gthdIiefK6.Styles.Normal.WordWrap = true;
			gthdIiefK6.Cols[0].AllowEditing = false;
			gthdIiefK6.Cols[2].AllowEditing = false;
			gthdIiefK6.Cols[3].AllowEditing = false;
			gthdIiefK6.Styles[CellStyleEnum.EmptyArea].BackColor = gthdIiefK6.Styles.Normal.BackColor;
			iiTN6jW1Nv(AYNDNJM3e1());
			RjAN7yEjWw();
			gthdIiefK6.AutoSizeRows();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.SetValue(PropertyDescriptor propertyDescriptor, int rowIndex, int columnIndex, object value)
		{
			//IL_004c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0052: Expected O, but got Unknown
			//IL_00a8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b2: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass24 CS$<>8__locals22 = new <>c__DisplayClass24();
			CS$<>8__locals22.propertyDescriptor = propertyDescriptor;
			CS$<>8__locals22.rowIndex = rowIndex;
			CS$<>8__locals22.columnIndex = columnIndex;
			CS$<>8__locals22.value = value;
			CS$<>8__locals22.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						((IFnPView)CS$<>8__locals22.<>4__this).SetValue(CS$<>8__locals22.propertyDescriptor, CS$<>8__locals22.rowIndex, CS$<>8__locals22.columnIndex, CS$<>8__locals22.value);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else if (CS$<>8__locals22.value != null)
			{
				switch (CS$<>8__locals22.propertyDescriptor)
				{
				case PropertyDescriptor.Picture:
					gthdIiefK6.Rows[CS$<>8__locals22.rowIndex].Node.Image = (Image)CS$<>8__locals22.value;
					break;
				case PropertyDescriptor.Value:
					gthdIiefK6[CS$<>8__locals22.rowIndex, CS$<>8__locals22.columnIndex] = CS$<>8__locals22.value;
					break;
				case PropertyDescriptor.OutlineLevel:
					gthdIiefK6.Rows[CS$<>8__locals22.rowIndex].Node.Level = Convert.ToInt32(CS$<>8__locals22.value, CultureInfo.InvariantCulture);
					break;
				case PropertyDescriptor.Combolist:
					gthdIiefK6.Rows[CS$<>8__locals22.rowIndex].ComboList = CS$<>8__locals22.value.ToString();
					break;
				case PropertyDescriptor.FontBold:
					gthdIiefK6.Rows[CS$<>8__locals22.rowIndex].Style = gthdIiefK6.Styles[NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33170)];
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.ShowPageSetupDialog()
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_000d: Expected O, but got Unknown
			//IL_0024: Unknown result type (might be due to invalid IL or missing references)
			PageSetupDialog val = new PageSetupDialog();
			val.Document = gthdIiefK6.PrintParameters.PrintDocument;
			((CommonDialog)val).ShowDialog();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.ShowPrintPreviewDialog(PrintProperties printProperties)
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_000d: Expected O, but got Unknown
			//IL_002b: Unknown result type (might be due to invalid IL or missing references)
			PrintPreviewDialog val = new PrintPreviewDialog();
			dcdN2BamjJ(printProperties);
			val.Document = gthdIiefK6.PrintParameters.PrintDocument;
			((Form)val).ShowDialog();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.EnableUI(bool enable)
		{
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass28 CS$<>8__locals6 = new <>c__DisplayClass28();
			CS$<>8__locals6.enable = enable;
			CS$<>8__locals6.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						((IFnPView)CS$<>8__locals6.<>4__this).EnableUI(CS$<>8__locals6.enable);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				((Control)this).Enabled = CS$<>8__locals6.enable;
				((Control)gthdIiefK6).Enabled = CS$<>8__locals6.enable;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IFnPView.SetGridColumnWidth()
		{
			string text = "";
			object obj = "";
			float num = 0f;
			int num2 = 0;
			try
			{
				if (nG0dg1Pi5D != null && gthdIiefK6 != null)
				{
					ColumnCollection cols = gthdIiefK6.Cols;
					num2 = cols.Count;
					int width = ((Control)gthdIiefK6).Width;
					for (int i = 0; i < num2; i++)
					{
						text = (string)gthdIiefK6.GetUserData(0, i);
						obj = nG0dg1Pi5D.ReadSetting(text);
						num = (float)obj;
						gthdIiefK6.Cols[i].Width = (int)((float)width * (num / 100f));
					}
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception2);
			}
			catch (InvalidComObjectException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception3);
			}
			catch (COMException exception4)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception4);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void RjAN7yEjWw()
		{
			//IL_008f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0095: Unknown result type (might be due to invalid IL or missing references)
			//IL_0096: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a0: Expected O, but got Unknown
			CellStyle cellStyle = null;
			cellStyle = ((!gthdIiefK6.Styles.Contains(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33198))) ? gthdIiefK6.Styles.Add(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33254)) : gthdIiefK6.Styles[NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33226)]);
			cellStyle.Font = new Font(((Control)gthdIiefK6).Font.Name, ((Control)gthdIiefK6).Font.Size, (FontStyle)(((Control)gthdIiefK6).Font.Style | 1));
			cellStyle.ForeColor = gthdIiefK6.Styles.Normal.ForeColor;
			cellStyle.BackColor = gthdIiefK6.Styles.Normal.BackColor;
			cellStyle.WordWrap = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void dUxNqtv58b(string P_0, int P_1)
		{
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0043: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass2c CS$<>8__locals8 = new <>c__DisplayClass2c();
			CS$<>8__locals8.itemList = P_0;
			CS$<>8__locals8.rowid = P_1;
			CS$<>8__locals8.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						CS$<>8__locals8.<>4__this.dUxNqtv58b(CS$<>8__locals8.itemList, CS$<>8__locals8.rowid);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				gthdIiefK6.Rows[CS$<>8__locals8.rowid].ComboList = CS$<>8__locals8.itemList;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aSwN8qUBTJ(int P_0, string P_1)
		{
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0043: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass30 CS$<>8__locals8 = new <>c__DisplayClass30();
			CS$<>8__locals8.rowId = P_0;
			CS$<>8__locals8.editMask = P_1;
			CS$<>8__locals8.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						CS$<>8__locals8.<>4__this.aSwN8qUBTJ(CS$<>8__locals8.rowId, CS$<>8__locals8.editMask);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				gthdIiefK6.Rows[CS$<>8__locals8.rowId].EditMask = CS$<>8__locals8.editMask;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void TRHNiddbt1(bool P_0)
		{
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass34 CS$<>8__locals5 = new <>c__DisplayClass34();
			CS$<>8__locals5.redraw = P_0;
			CS$<>8__locals5.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						CS$<>8__locals5.<>4__this.TRHNiddbt1(CS$<>8__locals5.redraw);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				gthdIiefK6.Redraw = CS$<>8__locals5.redraw;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void zq7NjgO3IF(int P_0, bool P_1)
		{
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0043: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass38 CS$<>8__locals8 = new <>c__DisplayClass38();
			CS$<>8__locals8.rowIndex = P_0;
			CS$<>8__locals8.isRowCollapse = P_1;
			CS$<>8__locals8.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						CS$<>8__locals8.<>4__this.zq7NjgO3IF(CS$<>8__locals8.rowIndex, CS$<>8__locals8.isRowCollapse);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				gthdIiefK6.Rows[CS$<>8__locals8.rowIndex].Node.Collapsed = CS$<>8__locals8.isRowCollapse;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void lWRNOTT6do(int P_0, bool P_1)
		{
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0043: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass3c CS$<>8__locals8 = new <>c__DisplayClass3c();
			CS$<>8__locals8.rowid = P_0;
			CS$<>8__locals8.hide = P_1;
			CS$<>8__locals8.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						CS$<>8__locals8.<>4__this.lWRNOTT6do(CS$<>8__locals8.rowid, CS$<>8__locals8.hide);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				gthdIiefK6.Rows[CS$<>8__locals8.rowid].Visible = !CS$<>8__locals8.hide;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void J0QNXBGpXK(int P_0)
		{
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass40 CS$<>8__locals5 = new <>c__DisplayClass40();
			CS$<>8__locals5.column = P_0;
			CS$<>8__locals5.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						CS$<>8__locals5.<>4__this.J0QNXBGpXK(CS$<>8__locals5.column);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				gthdIiefK6.Col = CS$<>8__locals5.column;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void auwNC3brJW(int P_0)
		{
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass44 CS$<>8__locals5 = new <>c__DisplayClass44();
			CS$<>8__locals5.row = P_0;
			CS$<>8__locals5.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						CS$<>8__locals5.<>4__this.auwNC3brJW(CS$<>8__locals5.row);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				gthdIiefK6.Row = CS$<>8__locals5.row;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void gCYNE3VoU4(int P_0)
		{
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass48 CS$<>8__locals5 = new <>c__DisplayClass48();
			CS$<>8__locals5.count = P_0;
			CS$<>8__locals5.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						CS$<>8__locals5.<>4__this.gCYNE3VoU4(CS$<>8__locals5.count);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				gthdIiefK6.Rows.Count = CS$<>8__locals5.count;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void EOdN1kNajQ(Cursor P_0)
		{
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass4c CS$<>8__locals5 = new <>c__DisplayClass4c();
			CS$<>8__locals5.cursor = P_0;
			CS$<>8__locals5.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						CS$<>8__locals5.<>4__this.EOdN1kNajQ(CS$<>8__locals5.cursor);
					});
				}
				((Control)this).BeginInvoke((Delegate)(object)val);
			}
			else
			{
				((Control)gthdIiefK6).Cursor = CS$<>8__locals5.cursor;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void fZcNfMdKPB(AnchorStyles P_0)
		{
			//IL_0010: Unknown result type (might be due to invalid IL or missing references)
			//IL_0011: Unknown result type (might be due to invalid IL or missing references)
			//IL_0046: Unknown result type (might be due to invalid IL or missing references)
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass50 CS$<>8__locals5 = new <>c__DisplayClass50();
			CS$<>8__locals5.anchorStyle = P_0;
			CS$<>8__locals5.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						//IL_000e: Unknown result type (might be due to invalid IL or missing references)
						CS$<>8__locals5.<>4__this.fZcNfMdKPB(CS$<>8__locals5.anchorStyle);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
			}
			else
			{
				((Control)this).Anchor = CS$<>8__locals5.anchorStyle;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private Point WDyNmQ7RRc(int P_0, int P_1)
		{
			Point scrollPosition = gthdIiefK6.ScrollPosition;
			if (P_1 == 0)
			{
				scrollPosition.X += gthdIiefK6.Cols[P_1].Left + gthdIiefK6.Rows[P_0].Node.Level * 9 + 24;
				scrollPosition.Y += gthdIiefK6.Rows[P_0].Bottom - 5;
			}
			else
			{
				scrollPosition.X += gthdIiefK6.Cols[P_1].Left + 10;
				scrollPosition.Y += gthdIiefK6.Rows[P_0].Bottom - 5;
			}
			return scrollPosition;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static PrintDialog WEFN4r9bI5()
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_000d: Expected O, but got Unknown
			PrintDialog val = new PrintDialog();
			val.AllowSomePages = true;
			val.AllowSelection = true;
			val.AllowPrintToFile = true;
			val.UseEXDialog = true;
			return val;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void dcdN2BamjJ(PrintProperties P_0)
		{
			//IL_0119: Unknown result type (might be due to invalid IL or missing references)
			//IL_0123: Expected O, but got Unknown
			//IL_0123: Unknown result type (might be due to invalid IL or missing references)
			//IL_0129: Expected O, but got Unknown
			GridPrinter printParameters = gthdIiefK6.PrintParameters;
			printParameters.PrintGridFlags = PrintGridFlags.FitToPageWidth | PrintGridFlags.ExtendLastCol;
			printParameters.HeaderFont = P_0.HeaderFooterFont;
			printParameters.FooterFont = P_0.HeaderFooterFont;
			printParameters.Header = P_0.LeftHeader + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33282) + P_0.CenterHeader + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33288) + P_0.RightHeader;
			printParameters.Footer = P_0.LeftFooter + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33294) + P_0.CenterFooter + NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33300) + P_0.RightFooter;
			printParameters.PrintDocument.DocumentName = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33306);
			printParameters.PrintDocument.PrinterSettings.PrintRange = (PrintRange)0;
			printParameters.PrintDocument.PrinterSettings.FromPage = 1;
			printParameters.PrintDocument.PrinterSettings.ToPage = 1;
			printParameters.PrintDocument.PrintController = (PrintController)new StandardPrintController();
			PageSettings val = new PageSettings();
			val.Margins = P_0.PrintPageMargins;
			val.PaperSource.RawKind = P_0.PaperSource;
			val.PaperSize.RawKind = P_0.PaperSize;
			if (P_0.Orientation > 0)
			{
				val.Landscape = true;
			}
			else
			{
				val.Landscape = false;
			}
			printParameters.PrintDocument.DefaultPageSettings = val;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void iiTN6jW1Nv(GridProperties P_0)
		{
			//IL_0045: Unknown result type (might be due to invalid IL or missing references)
			//IL_0056: Unknown result type (might be due to invalid IL or missing references)
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			//IL_005d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0074: Unknown result type (might be due to invalid IL or missing references)
			//IL_0076: Unknown result type (might be due to invalid IL or missing references)
			//IL_006e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0077: Unknown result type (might be due to invalid IL or missing references)
			//IL_008e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0090: Unknown result type (might be due to invalid IL or missing references)
			//IL_0088: Unknown result type (might be due to invalid IL or missing references)
			//IL_0091: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00aa: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c9: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ca: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d4: Expected O, but got Unknown
			MethodInvoker val = null;
			<>c__DisplayClass54 CS$<>8__locals15 = new <>c__DisplayClass54();
			CS$<>8__locals15.gridProperties = P_0;
			CS$<>8__locals15.<>4__this = this;
			if (((Control)this).InvokeRequired)
			{
				if (val == null)
				{
					val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
					{
						CS$<>8__locals15.<>4__this.iiTN6jW1Nv(CS$<>8__locals15.gridProperties);
					});
				}
				((Control)this).Invoke((Delegate)(object)val);
				return;
			}
			FontStyle val2 = (FontStyle)0;
			val2 = (FontStyle)(CS$<>8__locals15.gridProperties.IsBold ? 1 : ((int)val2));
			val2 = (FontStyle)(CS$<>8__locals15.gridProperties.IsItalic ? (val2 | 2) : val2);
			val2 = (FontStyle)(CS$<>8__locals15.gridProperties.IsStrike ? (val2 | 8) : val2);
			val2 = (FontStyle)(CS$<>8__locals15.gridProperties.IsUnderline ? (val2 | 4) : val2);
			((Control)gthdIiefK6).Font = new Font(CS$<>8__locals15.gridProperties.FontName, (float)CS$<>8__locals15.gridProperties.FontSize, val2);
			gthdIiefK6.Styles.Fixed.ForeColor = CS$<>8__locals15.gridProperties.FontColor;
			gthdIiefK6.Styles.Normal.ForeColor = CS$<>8__locals15.gridProperties.FontColor;
			gthdIiefK6.Styles.Normal.BackColor = CS$<>8__locals15.gridProperties.BackColor;
			gthdIiefK6.Styles.Fixed.Border.Color = CS$<>8__locals15.gridProperties.GridColor;
			gthdIiefK6.Styles.Normal.Border.Color = CS$<>8__locals15.gridProperties.GridColor;
			if (gthdIiefK6.Styles.Contains(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33326)))
			{
				CellStyle cellStyle = gthdIiefK6.Styles[NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33354)];
				cellStyle.Font = gthdIiefK6.Styles.Normal.Font;
				cellStyle.ForeColor = gthdIiefK6.Styles.Normal.ForeColor;
				cellStyle.BackColor = gthdIiefK6.Styles.Normal.BackColor;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static Color SY0NnmDcWT()
		{
			Color result = default(Color);
			int result2 = 0;
			RegistryKey registryKey = null;
			string name = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33382);
			registryKey = Registry.LocalMachine.OpenSubKey(name);
			if (registryKey != null)
			{
				if (int.TryParse(registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33544), 16777215).ToString(), out result2))
				{
					result = ColorTranslator.FromWin32(result2);
				}
				registryKey.Close();
			}
			else if (int.TryParse(16777215.ToString(CultureInfo.InvariantCulture), out result2))
			{
				result = ColorTranslator.FromWin32(result2);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static Color ahuNt5km4q()
		{
			Color result = default(Color);
			int result2 = 0;
			RegistryKey registryKey = null;
			string name = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33590);
			registryKey = Registry.LocalMachine.OpenSubKey(name);
			if (registryKey != null)
			{
				if (int.TryParse(registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33750), 12632256).ToString(), out result2))
				{
					result = ColorTranslator.FromWin32(result2);
				}
				registryKey.Close();
			}
			else if (int.TryParse(12632256.ToString(CultureInfo.InvariantCulture), out result2))
			{
				result = ColorTranslator.FromWin32(result2);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static Color zhwNo4GD7D()
		{
			Color result = default(Color);
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33796));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33912));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33948));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(33954));
			RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(stringBuilder.ToString());
			int result2 = 0;
			if (registryKey != null)
			{
				if (int.TryParse(registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34000), 0).ToString(), out result2))
				{
					result = ColorTranslator.FromWin32(result2);
				}
				registryKey.Close();
			}
			else if (int.TryParse(0.ToString(CultureInfo.InvariantCulture), out result2))
			{
				result = ColorTranslator.FromWin32(result2);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static int cXhNzfhbA9()
		{
			int result = 0;
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34014));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34130));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34166));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34172));
			RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(stringBuilder.ToString());
			int result2 = 0;
			if (registryKey != null)
			{
				if (int.TryParse(registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34218), 12).ToString(), out result2))
				{
					result = result2;
				}
				registryKey.Close();
			}
			else if (int.TryParse(12.ToString(CultureInfo.InvariantCulture), out result2))
			{
				result = result2;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static bool CTIDa0BmJZ()
		{
			bool result = false;
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34230));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34346));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34382));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34388));
			RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(stringBuilder.ToString());
			bool result2 = false;
			if (registryKey != null)
			{
				if (bool.TryParse(registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34434), false).ToString(), out result2))
				{
					result = result2;
				}
				registryKey.Close();
			}
			else if (bool.TryParse(false.ToString(CultureInfo.InvariantCulture), out result2))
			{
				result = result2;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static bool QWwD5sUTmY()
		{
			bool result = false;
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34446));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34562));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34598));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34604));
			RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(stringBuilder.ToString());
			bool result2 = false;
			if (registryKey != null)
			{
				if (bool.TryParse(registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34650), false).ToString(), out result2))
				{
					result = result2;
				}
				registryKey.Close();
			}
			else if (bool.TryParse(false.ToString(CultureInfo.InvariantCulture), out result2))
			{
				result = result2;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static bool Rn5DpxA1U9()
		{
			bool result = false;
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34666));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34782));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34818));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34824));
			RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(stringBuilder.ToString());
			bool result2 = false;
			if (registryKey != null)
			{
				if (bool.TryParse(registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34870), false).ToString(), out result2))
				{
					result = result2;
				}
				registryKey.Close();
			}
			else if (bool.TryParse(false.ToString(CultureInfo.InvariantCulture), out result2))
			{
				result = result2;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static bool an3DVqkduF()
		{
			bool result = false;
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(34900));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35016));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35052));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35058));
			RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(stringBuilder.ToString());
			bool result2 = false;
			if (registryKey != null)
			{
				if (bool.TryParse(registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35104), false).ToString(), out result2))
				{
					result = result2;
				}
				registryKey.Close();
			}
			else if (bool.TryParse(false.ToString(CultureInfo.InvariantCulture), out result2))
			{
				result = result2;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string NDHD3JEYqn()
		{
			string empty = string.Empty;
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35126));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35242));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35278));
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35284));
			RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(stringBuilder.ToString());
			if (registryKey != null)
			{
				empty = registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35330), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35342)).ToString();
				registryKey.Close();
			}
			else
			{
				empty = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35370).ToString();
			}
			return empty;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static GridProperties AYNDNJM3e1()
		{
			GridProperties gridProperties = new GridProperties();
			gridProperties.BackColor = SY0NnmDcWT();
			gridProperties.GridColor = ahuNt5km4q();
			gridProperties.FontColor = zhwNo4GD7D();
			gridProperties.FontSize = cXhNzfhbA9();
			gridProperties.IsBold = CTIDa0BmJZ();
			gridProperties.IsItalic = QWwD5sUTmY();
			gridProperties.IsStrike = Rn5DpxA1U9();
			gridProperties.IsUnderline = an3DVqkduF();
			gridProperties.FontName = NDHD3JEYqn();
			return gridProperties;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qJiDDIJm8n()
		{
			gthdIiefK6.Cols[0].Width = (int)((double)((Control)gthdIiefK6).Width * 0.56);
			gthdIiefK6.Cols[1].Width = (int)((double)((Control)gthdIiefK6).Width * 0.17);
			gthdIiefK6.Cols[2].Width = (int)((double)((Control)gthdIiefK6).Width * 0.1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void SHTDdv6H52(object P_0, EventArgs P_1)
		{
			((IFnPView)this).SetupView();
			((IFnPView)this).SetGridColumnWidth();
			iQ5DS28766();
			lhMDHKCYnL();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void lhMDHKCYnL()
		{
			if (xpud0VBIjV != null)
			{
				xpud0VBIjV(this, new EventArgs());
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void iQ5DS28766()
		{
			//IL_00e3: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ed: Expected O, but got Unknown
			//IL_00fa: Unknown result type (might be due to invalid IL or missing references)
			//IL_0104: Expected O, but got Unknown
			//IL_0111: Unknown result type (might be due to invalid IL or missing references)
			//IL_011b: Expected O, but got Unknown
			//IL_0128: Unknown result type (might be due to invalid IL or missing references)
			//IL_0132: Expected O, but got Unknown
			//IL_013f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0149: Expected O, but got Unknown
			//IL_016d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0177: Expected O, but got Unknown
			gthdIiefK6.BeforeCollapse += TPDDsG0Cc7;
			gthdIiefK6.AfterCollapse += jhlDPCAWJI;
			gthdIiefK6.BeforeEdit += zIgDWaOEU0;
			gthdIiefK6.AfterEdit += pYyDvAO8MP;
			gthdIiefK6.BeforeRowColChange += itDDr0GkF7;
			gthdIiefK6.AfterRowColChange += A6mD9Qi1Xq;
			gthdIiefK6.KeyPressEdit += Yw5DRwi8lZ;
			gthdIiefK6.StartEdit += BvEDL99eLp;
			gthdIiefK6.ValidateEdit += vr4DYLXae7;
			((Control)gthdIiefK6).KeyDown += new KeyEventHandler(NUjDIbcZi0);
			((Control)gthdIiefK6).KeyUp += new KeyEventHandler(UJaDu0Jx9x);
			((Control)gthdIiefK6).MouseMove += new MouseEventHandler(Y38DkTMpTh);
			((Control)gthdIiefK6).MouseDown += new MouseEventHandler(eeJDUqBEUH);
			((Control)gthdIiefK6).MouseWheel += new MouseEventHandler(muoDbkZwqn);
			gthdIiefK6.AfterResizeColumn += sQtDZ9kV6v;
			((Control)gthdIiefK6).MouseUp += new MouseEventHandler(t2GDGLND99);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void t2GDGLND99(object P_0, MouseEventArgs P_1)
		{
			if (gthdIiefK6.MouseRow == 0)
			{
				((Control)this).Focus();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void sQtDZ9kV6v(object P_0, RowColEventArgs P_1)
		{
			gthdIiefK6.Redraw = false;
			gthdIiefK6.AutoSizeRows();
			gthdIiefK6.Redraw = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void muoDbkZwqn(object P_0, MouseEventArgs P_1)
		{
			CvTdlym1Lr.Hide((IWin32Window)(object)gthdIiefK6);
			CvTdlym1Lr.RemoveAll();
			w2edxHjeYL = TooltipActiveState.None;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void TPDDsG0Cc7(object P_0, RowColEventArgs P_1)
		{
			if (XqEdMxVc97 != null)
			{
				XqEdMxVc97(this, P_1);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void jhlDPCAWJI(object P_0, RowColEventArgs P_1)
		{
			if (rYTdu0QIHX != null)
			{
				rYTdu0QIHX(this, P_1);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void zIgDWaOEU0(object P_0, RowColEventArgs P_1)
		{
			if (ak0dwXuKb4 != null)
			{
				ak0dwXuKb4(this, P_1);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void pYyDvAO8MP(object P_0, RowColEventArgs P_1)
		{
			if (MlTdk8Utyb != null)
			{
				gthdIiefK6.Styles.Focus.BackColor = gthdIiefK6.Styles.Highlight.BackColor;
				gthdIiefK6.Styles.Focus.ForeColor = gthdIiefK6.Styles.Highlight.ForeColor;
				MlTdk8Utyb(this, P_1);
			}
			gthdIiefK6.Select(P_1.Row, P_1.Col, gthdIiefK6.RowSel, gthdIiefK6.ColSel, show: true);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void itDDr0GkF7(object P_0, RangeEventArgs P_1)
		{
			if (P_1.NewRange.r1 == 0)
			{
				P_1.Cancel = true;
			}
			if (P_1.NewRange.c1 == 0)
			{
				gthdIiefK6.AutoSearch = AutoSearchEnum.FromCursor;
			}
			else
			{
				gthdIiefK6.AutoSearch = AutoSearchEnum.None;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void A6mD9Qi1Xq(object P_0, RangeEventArgs P_1)
		{
			if (xJOdUFZnV5 != null)
			{
				xJOdUFZnV5(this, P_1);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Yw5DRwi8lZ(object P_0, KeyPressEditEventArgs P_1)
		{
			if (H4adAPG9Ps != null)
			{
				H4adAPG9Ps(this, P_1);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void BvEDL99eLp(object P_0, RowColEventArgs P_1)
		{
			//IL_00a6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b0: Expected O, but got Unknown
			if (vkcdKErPpP == null)
			{
				return;
			}
			gthdIiefK6.Styles.Focus.BackColor = gthdIiefK6.Styles.Normal.BackColor;
			gthdIiefK6.Styles.Focus.ForeColor = gthdIiefK6.Styles.Normal.ForeColor;
			Control editor = gthdIiefK6.Editor;
			if (editor != null)
			{
				if (editor is TextBox)
				{
					gthdIiefK6.Styles.Editor.TextAlign = TextAlignEnum.RightCenter;
					((editor is TextBox) ? editor : null).MouseUp += new MouseEventHandler(yImDT7ZD90);
					((editor is TextBox) ? editor : null).LostFocus += x2bDcjpKqm;
				}
				else if (editor is ComboBox)
				{
					gthdIiefK6.Styles.Editor.TextAlign = TextAlignEnum.LeftCenter;
				}
			}
			vkcdKErPpP(this, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void x2bDcjpKqm(object P_0, EventArgs P_1)
		{
			if (P_0 is TextBox)
			{
				gthdIiefK6.Styles.Focus.BackColor = gthdIiefK6.Styles.Highlight.BackColor;
				gthdIiefK6.Styles.Focus.ForeColor = gthdIiefK6.Styles.Highlight.ForeColor;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void yImDT7ZD90(object P_0, MouseEventArgs P_1)
		{
			TextBox val = (TextBox)((P_0 is TextBox) ? P_0 : null);
			if (val != null)
			{
				((TextBoxBase)val).SelectAll();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void vr4DYLXae7(object P_0, ValidateEditEventArgs P_1)
		{
			if (adodyAJ9VC != null)
			{
				adodyAJ9VC(this, P_1);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void NUjDIbcZi0(object P_0, KeyEventArgs P_1)
		{
			if (DHVdhbjufN != null)
			{
				DHVdhbjufN.Invoke((object)this, P_1);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void UJaDu0Jx9x(object P_0, KeyEventArgs P_1)
		{
			if (MqydBrgvnu != null)
			{
				MqydBrgvnu.Invoke((object)this, P_1);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Y38DkTMpTh(object P_0, MouseEventArgs P_1)
		{
			if (S3qdQZq059 != null)
			{
				S3qdQZq059.Invoke((object)this, P_1);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void eeJDUqBEUH(object P_0, MouseEventArgs P_1)
		{
			if (SH0devwYLc != null)
			{
				SH0devwYLc.Invoke((object)this, P_1);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Dispose(bool disposing)
		{
			string text = "";
			float num = 0f;
			int num2 = 0;
			try
			{
				if (nG0dg1Pi5D != null)
				{
					ColumnCollection cols = gthdIiefK6.Cols;
					num2 = cols.Count;
					for (int i = 0; i < num2; i++)
					{
						num = gthdIiefK6.Cols[i].Width;
						text = (string)gthdIiefK6.GetUserData(0, i);
						float num3 = num / (float)TIod7wpY0h;
						num3 *= 100f;
						object value = num3;
						nG0dg1Pi5D.WriteSetting(text, value);
						nG0dg1Pi5D.Commit(text);
					}
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception2);
			}
			catch (InvalidComObjectException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception3);
			}
			catch (COMException exception4)
			{
				FnPTraceLoger.TryLog(LogCategory.ECMDataReader, exception4);
			}
			if (disposing && euIdqLtSbZ != null)
			{
				euIdqLtSbZ.Dispose();
			}
			((ContainerControl)this).Dispose(disposing);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void IFyDM2Kko0()
		{
			((Control)this).SuspendLayout();
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Control)this).AutoSize = true;
			((Control)this).Name = NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35398);
			((Control)this).Size = new Size(621, 600);
			((UserControl)this).Load += SHTDdv6H52;
			((Control)this).ResumeLayout(false);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CompilerGenerated]
		private void N06DwtKrtX()
		{
			((IFnPView)this).AutoSizeRows();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CompilerGenerated]
		private void EmGDhJ31IO()
		{
			((IFnPView)this).AutoSizeCols();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CompilerGenerated]
		private void X5xDA6OanM()
		{
			((IFnPView)this).HideTooltip();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CompilerGenerated]
		private void iaUDBAW9P8()
		{
			((IFnPView)this).ResizeView();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CompilerGenerated]
		private void afvDeGhiKK()
		{
			((IFnPView)this).SetupView();
		}
	}
}
namespace e62y0ZIuxWPh3qxjyt
{
	internal class nPLxyaYbt3o6GxIF5R : FnPPresenterBase, IFnPPrintPresenter
	{
		private IFnPModel kkAdC4ectm;

		private PrintFormat I8RdEQSZCV;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public nPLxyaYbt3o6GxIF5R(IFnPModel P_0)
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
			kkAdC4ectm = P_0;
			I8RdEQSZCV = PrintFormat.None;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void CreateCSVFile(string P_0, string P_1, string P_2)
		{
			throw new NotImplementedException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35430));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void PrintImageInToolFormat(object P_0, string P_1, VSPrinter P_2, int P_3)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35520), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35660));
			}
			if (P_2 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35676), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35816));
			}
			if (string.IsNullOrEmpty(P_1))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35834), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(35974));
			}
			try
			{
				I8RdEQSZCV = PrintFormat.Tool;
				kkAdC4ectm.PrepareFnPPrintDataObject(P_0, P_1, P_3);
				Pnnd873ltq(P_2, P_3);
				kkAdC4ectm.ClearDataOM();
				I8RdEQSZCV = PrintFormat.None;
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.FnPPrintPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.FnPPrintPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetFnPDataInTextFormat(object P_0, string P_1, int P_2)
		{
			I8RdEQSZCV = PrintFormat.Text;
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36000), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36140));
			}
			if (string.IsNullOrEmpty(P_1))
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36156), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36296));
			}
			string result = null;
			try
			{
				kkAdC4ectm.PrepareFnPPrintDataObject(P_0, P_1, P_2);
				result = wKbdikseTd(P_2);
				kkAdC4ectm.ClearDataOM();
				I8RdEQSZCV = PrintFormat.None;
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.FnPPrintPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.FnPPrintPresenter, exception2);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override bool CheckFnPElementLockState(IFnPElement P_0)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36322), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36466));
			}
			return false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void PopulateModule(Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IModule P_0, bool P_1, int P_2)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36484), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36608));
			}
			try
			{
				StringBuilder stringBuilder = new StringBuilder();
				stringBuilder.Append(P_0.MarketName);
				if (P_1)
				{
					stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36624));
					stringBuilder.Append(P_0.SourceAddress.ToString(CultureInfo.InvariantCulture));
					stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36630));
					if (!string.IsNullOrEmpty(P_0.ServiceEcmMarketingName))
					{
						stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36636));
						stringBuilder.Append(P_0.ServiceEcmMarketingName);
						stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36642));
					}
				}
				base.FnpView.AddModuleName(stringBuilder.ToString());
				base.FnpView.SetValue(Cummins.Insite.AddIns.FeaturesAndParameters.PropertyDescriptor.OutlineLevel, base.FnpView.RowsCount - 1, 0, P_2);
				IFeatures features = P_0.Features;
				PopulateFeatures(features, P_2 + 1);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.FnPPrintPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.FnPPrintPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void PopulateSmartDevices(Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IModules P_0)
		{
			base.FnpView.AddSystemName(_stringProvider.GetLocalizedString(StringIdProvider.OtherDevices));
			if (P_0.Count > 0)
			{
				base.FnpView.SetValue(Cummins.Insite.AddIns.FeaturesAndParameters.PropertyDescriptor.FontBold, base.FnpView.RowsCount - 1, 0, true);
				base.FnpView.SetValue(Cummins.Insite.AddIns.FeaturesAndParameters.PropertyDescriptor.OutlineLevel, base.FnpView.RowsCount - 1, 0, 0);
				PopulateModules(P_0, 1);
			}
			else
			{
				base.FnpView.AddItem(_stringProvider.GetLocalizedString(StringIdProvider.NoOtherDevice));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void PopulateFeature(IFeature P_0, int P_1)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36648), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36774));
			}
			try
			{
				StringBuilder stringBuilder = new StringBuilder();
				stringBuilder.Append(P_0.Name.Trim());
				stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36792));
				stringBuilder.Append(P_0.Value.Trim());
				string empty = string.Empty;
				empty = ((I8RdEQSZCV != PrintFormat.Text) ? stringBuilder.ToString() : (Environment.NewLine + stringBuilder.ToString()));
				base.FnpView.AddItem(empty);
				base.FnpView.SetValue(Cummins.Insite.AddIns.FeaturesAndParameters.PropertyDescriptor.OutlineLevel, base.FnpView.RowsCount - 1, 0, P_1);
				int rowsCount = base.FnpView.RowsCount;
				CFWdOEQNRf(P_0, rowsCount, P_1);
				if (P_0.ReadBlocked)
				{
					base.FnpView.PutRowCollapse(rowsCount - 1, isRowCollapse: true);
					base.FnpView.PutRowHidden(rowsCount - 1, hide: true);
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.FnPPrintPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.FnPPrintPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void PopulateSubFeature(ISubFeature P_0, int P_1, int P_2)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36798), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36930));
			}
			try
			{
				int rowsCount = base.FnpView.RowsCount;
				if (P_0.Id > 99)
				{
					StringBuilder stringBuilder = new StringBuilder();
					if (I8RdEQSZCV == PrintFormat.Text)
					{
						stringBuilder.Append(P_0.FullName.Trim());
					}
					else
					{
						stringBuilder.Append(P_0.Name.Trim());
					}
					stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36954));
					stringBuilder.Append(P_0.Value.Trim());
					base.FnpView.AddItem(stringBuilder.ToString());
					base.FnpView.SetValue(Cummins.Insite.AddIns.FeaturesAndParameters.PropertyDescriptor.OutlineLevel, base.FnpView.RowsCount - 1, 0, P_2);
				}
				else
				{
					P_2--;
				}
				OqrdX35oKh(P_0, P_1, P_2);
				if (P_0.ReadBlocked)
				{
					base.FnpView.PutRowCollapse(rowsCount, isRowCollapse: true);
					base.FnpView.PutRowHidden(rowsCount, hide: true);
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.FnPPrintPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.FnPPrintPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void PopulateParameter(Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameter P_0, int P_1)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(36960), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(37090));
			}
			try
			{
				string text = P_0.Value;
				if (NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(37112) == text)
				{
					text = "";
				}
				string unit = P_0.Unit;
				StringBuilder stringBuilder = new StringBuilder();
				stringBuilder.Append(P_0.Name.Trim());
				stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(37126));
				stringBuilder.Append(text.Trim());
				stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(37132));
				stringBuilder.Append(unit.Trim());
				base.FnpView.AddItem(stringBuilder.ToString());
				base.FnpView.SetValue(Cummins.Insite.AddIns.FeaturesAndParameters.PropertyDescriptor.OutlineLevel, base.FnpView.RowsCount - 1, 0, P_1);
				int rowsCount = base.FnpView.RowsCount;
				if (P_0.ReadBlocked)
				{
					base.FnpView.PutRowCollapse(rowsCount - 1, isRowCollapse: true);
					base.FnpView.PutRowHidden(rowsCount - 1, hide: true);
				}
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.FnPPrintPresenter, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.FnPPrintPresenter, exception2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override float GetPrecission(IFnPElement P_0, int P_1)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(37138), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(37260));
			}
			return 0f;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Pnnd873ltq(VSPrinter P_0, int P_1)
		{
			if (P_0 == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(37278), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(37408));
			}
			base.FnpView = new yS2KTu37cDalfYYdDf(P_0);
			base.FnpView.SetupView();
			PopulateGrid(kkAdC4ectm.GetFnPDataObject(), P_1);
			base.FnpView.PrintTo();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string wKbdikseTd(int P_0)
		{
			base.FnpView = new qmm5NFWmPE36Y6yPR0();
			base.FnpView.SetupView();
			yExdj6bOp9(P_0);
			PopulateGrid(kkAdC4ectm.GetFnPDataObject(), P_0);
			return base.FnpView.GetFnPData();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void yExdj6bOp9(int P_0)
		{
			ILocalizedStringProvider localizedStringProvider = Factory.CreateInstance<ILocalizedStringProvider>();
			localizedStringProvider.Initialize(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(37426));
			string localizedString = localizedStringProvider.GetLocalizedString(102);
			if (I8RdEQSZCV == PrintFormat.Text && P_0 == -1)
			{
				base.FnpView.AddItem(localizedString);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void CFWdOEQNRf(IFeature P_0, int P_1, int P_2)
		{
			ISubFeatures subFeatures = P_0.SubFeatures;
			if (FnPValueType.List == P_0.ValueType)
			{
				if (P_0 is IEnumerableFnPElement)
				{
					(P_0 as IEnumerableFnPElement).GetEnumerationInfo();
					if (0.0 != (P_0 as IEnumerableFnPElement).GetEnumForDisplayValue(P_0.Value))
					{
						PopulateSubFeatures(subFeatures, P_1 - 1, P_2 + 1);
					}
				}
			}
			else
			{
				PopulateSubFeatures(subFeatures, P_1 - 1, P_2 + 1);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void OqrdX35oKh(ISubFeature P_0, int P_1, int P_2)
		{
			if (FnPValueType.List == P_0.ValueType)
			{
				if (P_0 is IEnumerableFnPElement)
				{
					(P_0 as IEnumerableFnPElement).GetEnumerationInfo();
					if (0.0 != (P_0 as IEnumerableFnPElement).GetEnumForDisplayValue(P_0.Value))
					{
						Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameters parameters = P_0.Parameters;
						PopulateParameters(parameters, P_2 + 1);
						ISubFeatures subFeatures = P_0.SubFeatures;
						PopulateSubFeatures(subFeatures, P_1, P_2 + 1);
					}
				}
			}
			else
			{
				Cummins.INSITE.CNL.FeaturesAndParametersDataOM.IParameters parameters2 = P_0.Parameters;
				PopulateParameters(parameters2, P_2 + 1);
				ISubFeatures subFeatures2 = P_0.SubFeatures;
				PopulateSubFeatures(subFeatures2, P_1, P_2 + 1);
			}
		}
	}
}
namespace CW4fPqkAuCM3Jii1sM
{
	internal static class EWgfmqubhLleaa6sgy
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool xQnd1Hm8Bf(int P_0, TooltipQueryType P_1, LimitsTooltipType P_2)
		{
			//IL_00be: Expected O, but got Unknown
			//IL_000e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0014: Expected O, but got Unknown
			//IL_0083: Unknown result type (might be due to invalid IL or missing references)
			//IL_008a: Expected O, but got Unknown
			bool result = false;
			try
			{
				OleDbConnection val = new OleDbConnection(AL8d4XGnjC());
				((DbConnection)(object)val).Open();
				DataSet dataSet = new DataSet();
				dataSet.Locale = CultureInfo.InvariantCulture;
				StringBuilder stringBuilder = new StringBuilder();
				stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(37504));
				stringBuilder.Append(P_0);
				stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(37640));
				stringBuilder.Append((int)P_1);
				stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(37682));
				stringBuilder.Append((int)P_2);
				OleDbDataAdapter val2 = new OleDbDataAdapter(stringBuilder.ToString(), val);
				((DataAdapter)(object)val2).Fill(dataSet);
				((DbConnection)(object)val).Close();
				if (dataSet.Tables[0].Rows.Count > 0)
				{
					result = true;
				}
			}
			catch (OleDbException ex)
			{
				OleDbException exception = ex;
				FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.TooltipDataReader, (Exception)(object)exception);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static string BxRdfQETf4(int P_0, TooltipQueryType P_1)
		{
			//IL_00bb: Expected O, but got Unknown
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_0038: Expected O, but got Unknown
			//IL_005f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0066: Expected O, but got Unknown
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(37714), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(37842));
			}
			string result = string.Empty;
			try
			{
				OleDbConnection val = new OleDbConnection(AL8d4XGnjC());
				((DbConnection)(object)val).Open();
				DataSet dataSet = new DataSet();
				dataSet.Locale = CultureInfo.InvariantCulture;
				string empty = string.Empty;
				empty = quMdtUgBqk(P_0, P_1);
				OleDbDataAdapter val2 = new OleDbDataAdapter(empty, val);
				((DataAdapter)(object)val2).Fill(dataSet);
				((DbConnection)(object)val).Close();
				if (dataSet.Tables[0].Rows.Count > 0)
				{
					result = dataSet.Tables[0].Rows[0][0].ToString();
				}
			}
			catch (OleDbException ex)
			{
				OleDbException exception = ex;
				FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.TooltipDataReader, (Exception)(object)exception);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static string ntCdmhEcw5(int P_0, LimitsTooltipType P_1)
		{
			//IL_00b5: Expected O, but got Unknown
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_0038: Expected O, but got Unknown
			//IL_0059: Unknown result type (might be due to invalid IL or missing references)
			//IL_0060: Expected O, but got Unknown
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(37868), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(37996));
			}
			string result = string.Empty;
			try
			{
				OleDbConnection val = new OleDbConnection(AL8d4XGnjC());
				((DbConnection)(object)val).Open();
				DataSet dataSet = new DataSet();
				dataSet.Locale = CultureInfo.InvariantCulture;
				string text = J4ud21mRQP(P_0, P_1);
				OleDbDataAdapter val2 = new OleDbDataAdapter(text, val);
				((DataAdapter)(object)val2).Fill(dataSet);
				((DbConnection)(object)val).Close();
				if (dataSet.Tables[0].Rows.Count > 0)
				{
					result = dataSet.Tables[0].Rows[0][0].ToString();
				}
			}
			catch (OleDbException ex)
			{
				OleDbException exception = ex;
				FnPTraceLoger.TryLog(Cummins.Insite.AddIns.FeaturesAndParameters.LogCategory.TooltipDataReader, (Exception)(object)exception);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string AL8d4XGnjC()
		{
			string text = string.Empty;
			using (RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(38022)))
			{
				if (registryKey != null)
				{
					text = registryKey.GetValue(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(38226)) as string;
				}
			}
			return string.Format(CultureInfo.InvariantCulture, NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(38252), new object[1] { text });
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string J4ud21mRQP(int P_0, LimitsTooltipType P_1)
		{
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(38402), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(38526));
			}
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(38552));
			stringBuilder.Append(P_0);
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(38700));
			stringBuilder.Append(1);
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(38742));
			stringBuilder.Append((int)P_1);
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string EjGd6ufmYf(int P_0)
		{
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(38774), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(38904));
			}
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(38930));
			stringBuilder.Append(P_0);
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(39078));
			stringBuilder.Append(2);
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string P5Adni69oi(int P_0)
		{
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(39120), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(39256));
			}
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(39282));
			stringBuilder.Append(P_0);
			stringBuilder.Append(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(39430));
			stringBuilder.Append(3);
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string quMdtUgBqk(int P_0, TooltipQueryType P_1)
		{
			if (P_0 == 0)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(39472), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(39608));
			}
			string result = string.Empty;
			if (TooltipQueryType.LockstateTooltipQuery == P_1)
			{
				result = EjGd6ufmYf(P_0);
			}
			else if (TooltipQueryType.InvalidvalueTooltipQuery == P_1)
			{
				result = P5Adni69oi(P_0);
			}
			return result;
		}
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters
{
	public struct FeatureExclusiveTooltipInfo
	{
		public Dictionary<string, string> FEPararmeterMap;
	}
	public struct LimitsTooltipInfo
	{
		private string VSTdoyqtPD;

		private string PhZdzDNF5D;

		public string EditValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return VSTdoyqtPD;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				VSTdoyqtPD = value;
			}
		}

		public string LimitValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return PhZdzDNF5D;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				PhZdzDNF5D = value;
			}
		}
	}
	public struct LockStateTooltipInfo
	{
		private bool zjtHak2S3b;

		private bool AjkH5tTbsN;

		private bool YinHpLYvZN;

		private ConnectionType rN9HVFsg0t;

		private SecurityLevel O3GH3UHBKO;

		private ECMPasswordType eEDHNCobm8;

		private RowType mGWHDYsIRe;

		private bool UhKHd5dqyP;

		private int RHPHHXpHBP;

		public bool IsOEMAvailable
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return zjtHak2S3b;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				zjtHak2S3b = value;
			}
		}

		public bool IsOEM2Available
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return AjkH5tTbsN;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				AjkH5tTbsN = value;
			}
		}

		public bool HasUserRights
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return YinHpLYvZN;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				YinHpLYvZN = value;
			}
		}

		public ConnectionType ConnectionType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return rN9HVFsg0t;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				rN9HVFsg0t = value;
			}
		}

		public SecurityLevel CurrentSecurityLevel
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return O3GH3UHBKO;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				O3GH3UHBKO = value;
			}
		}

		public ECMPasswordType PasswordLevel
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return eEDHNCobm8;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				eEDHNCobm8 = value;
			}
		}

		public RowType ElementType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return mGWHDYsIRe;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				mGWHDYsIRe = value;
			}
		}

		public bool PreviousLevel
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return UhKHd5dqyP;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				UhKHd5dqyP = value;
			}
		}

		public int DetectType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return RHPHHXpHBP;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				RHPHHXpHBP = value;
			}
		}
	}
	public struct PrintProperties
	{
		private int RuYHSFK0wk;

		private string ylqHGgjx05;

		private string T1gHZ2Opnq;

		private string tpKHbBtnEH;

		private string OI8HsWGybM;

		private string MQqHPYhS6s;

		private string a98HWxn5Wk;

		private int EuVHviwDXi;

		private int JvcHrqL7NT;

		private int GOEH9ctalD;

		private Font x7PHRLQ98H;

		private Margins kFaHLTQKsa;

		public int PrintFontSize
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return RuYHSFK0wk;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				RuYHSFK0wk = value;
			}
		}

		public string LeftHeader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ylqHGgjx05;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				ylqHGgjx05 = value;
			}
		}

		public string RightHeader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return T1gHZ2Opnq;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				T1gHZ2Opnq = value;
			}
		}

		public string CenterHeader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return tpKHbBtnEH;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				tpKHbBtnEH = value;
			}
		}

		public string LeftFooter
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return OI8HsWGybM;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				OI8HsWGybM = value;
			}
		}

		public string RightFooter
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MQqHPYhS6s;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				MQqHPYhS6s = value;
			}
		}

		public string CenterFooter
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return a98HWxn5Wk;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				a98HWxn5Wk = value;
			}
		}

		public int PaperSize
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return EuVHviwDXi;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				EuVHviwDXi = value;
			}
		}

		public int PaperSource
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return JvcHrqL7NT;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				JvcHrqL7NT = value;
			}
		}

		public int Orientation
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return GOEH9ctalD;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				GOEH9ctalD = value;
			}
		}

		public Font HeaderFooterFont
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return x7PHRLQ98H;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				x7PHRLQ98H = value;
			}
		}

		public Margins PrintPageMargins
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return kFaHLTQKsa;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				kFaHLTQKsa = value;
			}
		}
	}
}
namespace l2VU8EM9k9mtc6uQoe
{
	internal static class lvAR4rU81IuV5nZUW5
	{
		public const string vZCHcGO3Da = "FnPDatabase.mdb";

		public const int IaQHTGUAIU = 16801741;

		public const int UbhHYnpJ3f = 16801742;

		public const int jF2HIklV1X = 16801743;

		public const int c9AHueVNcS = 16801744;

		public const int GXUHkreR89 = 16801745;

		public const int IYVHU5ksNO = 16801746;

		public const int AXnHMAP20o = 16807289;

		public const int yH8Hw0iHxm = 16807476;

		public const int fKQHhJio9m = 143;

		public const int J5EHAoUe36 = 16816701;

		public const int f4tHBn51MJ = 16824016;

		public const int Vd6HeHaVLs = 16790207;

		public const int VrRHQ2srGn = 16793806;

		public const int MH3HKWOFgb = 194;

		public const int TqnHyswg5Y = 16816596;

		public const int rL8HJsikYC = 16824309;

		public const string VR6HF8Rbl2 = "SELECT ToolTipExpression FROM ToolTipExpressionInfo WHERE ParameterID = ";

		public const string UaBHlgGrlf = " AND ToolTipType = ";

		public const string vfUHx72WNw = " AND MinMax = ";

		public const string wawH0J621T = "SELECT ParameterID FROM ToolTipExpressionInfo WHERE ParameterID = ";

		public const string eYZHg8QJj1 = "SELECT ToolTipExpression FROM ToolTipExpressionInfo WHERE ParameterID = ";

		public const string rXPH7VGyGw = "SELECT ToolTipExpression FROM ToolTipExpressionInfo WHERE ParameterID = ";

		public const int rVcHqb8Uib = 16824102;

		public const int ENbH8S6wwa = 16785222;

		public const int pqYHiDUZxN = 1020366;

		public const int znkHjYB92g = 1020394;

		public const int p3yHOwZFmN = 16783822;

		public const int Y7FHXKTtLT = 111021;

		public const int Ed2HCYm4Oj = 16795808;
	}
}
namespace Ae7mwlhrds0wk3yWBx
{
	internal static class OJRmxPwE56sP03p1bi
	{
		public const string CjxHE3LXjn = "{0:dd-MMM-yyyy}";

		public const string fapH1NijFw = "Page {0} of {1}";

		public const int EGAHfvULSs = 8;

		public const string IV4Hm4DBUi = "SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\GUI\\";

		public const int RO3H4e2OwD = 8;

		public const string uxIH2RR0wt = "SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\AIF\\AddIns\\{2E473ECD-9359-4B78-BC47-AF5E692D9DE0}";

		public const int WF7H6HluKt = 1009;

		public const int FO7Hn0PkVP = 1011;

		public const int lpGHtPLH1s = 3003;

		public const int GpsHoiGxbD = -1;

		public const string riUHzfVZ46 = "Not Available";

		public const string KFGSa3d3mn = "Disable";

		public const string PZGS5Ef57f = "FeaturesAndParametersResources_EN.xml";

		public const string Ye9SpHGMPi = "##:##:##";

		public const string w8nSV4KWp2 = "###:##:##";

		public const string aNwS3F0xHZ = "#######:##";

		public const string pBuSN73Rie = "##:##";

		public const int tIsSDx6O2L = 2;

		public const int katSdbMloY = 1;

		public const string kHrSHZx3Jx = "Basic";

		public const string udpSSLqSyd = "RSGR";

		public const string apOSGk7RmX = "Lite";

		public const string HidSZZtvAv = "Pro";

		public const string PhXSbhKD2i = "OBD-RSGR";

		public const string aBTSsYOx1Q = "OBD";

		public const string jGdSPqiq8O = "Pro Plus";

		public const string TgnSWPuPrc = "RSGR Plus";

		public const string l8WSvOeE7C = "Industrial / Power Generation Applications";

		public const string DbUSrUsxmn = "[";

		public const string KnvS9cB8Ik = "]";

		public const string FELSRPqBWC = "\t";

		public const string uccSLnSaDT = ",";

		public const string urKSc1o4aG = "ERROR";

		public const string qQiSTferZA = "";

		public const string TBsSYZHVQX = "FnP_Adjust_User";

		public const string e4dSI8xLbw = "FnP_TOOL_LIC_BASIC";

		public const string fv3SuxRmCd = "FnP_TOOL_LIC_LITE";

		public const string UK0Ske6T57 = "FnP_TOOL_LIC_RSGR";

		public const string PIASUtfdy2 = "FnP_ECMPW_MASTER";

		public const string ep7SMnV5hV = "FnP_ECMPW_ADJUSTABLES";

		public const string BdbSw2teP8 = "FnP_ECMPW_OEM";

		public const string GHuShhtoco = "FnP_ECMPW_OEM2";

		public const string frcSAPnVnG = "FnP_ECMPW_RESET";

		public const string OvtSBmpJX7 = "1";

		public const string mvgSehDuFR = "0";

		public const int s67SQcBjqh = 0;

		public const int Rg4SKk8Rrm = 232;

		public const int vFLSyvEKC1 = 201;

		internal const string POmSJiuCoi = " ";

		internal const string QYfSFsYFiQ = "_";

		internal const string qvqSl830fr = "0";

		public const int gtJSxWEhO1 = 21441;
	}
}
namespace pFIdA5BkEyCrmXldqL
{
	internal static class aNZstmAtRIfYBPxLEY
	{
		public const string DLZS0coHD4 = "2";

		public const string RLnSgA307K = "100";

		public const string m95S79fZ8t = "0";

		public const string ThFSq3y0np = "1";

		public const string IZGS8VeNfa = "SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\AIF\\AddIns\\{2E473ECD-9359-4B78-BC47-AF5E692D9DE0}";

		public const int zHiSis776V = 30;

		public const string HrQSjyeINS = "[PN]+\\([0-9]*\\)|[PV]+\\([0-9]*\\)|[CT]+\\([0-9]*\\)|[OP]+\\([!*+-<=>{AND}{OR}{NAND}{NOR}]+\\)";

		public const string WZ3SOsvDZ8 = "[0-9]+";

		public const string YIxSXcmVjm = "[0-9]+";

		public const string rkXSCCccek = "\\([!*+-<=>{AND}{OR}{NAND}{NOR}]+\\)";

		public const string MiqSERNmGR = "[!*+-<=><={AND}{OR}{NAND}{NOR}]+";

		public const string lQ4S1VYlIE = "[0-9]+";

		public const string XOZSflIeUv = "PN";

		public const string pMYSm9k27d = "OP";

		public const string vYyS4849FO = "PV";

		public const string F52S2iJgwn = "CT";

		public const string j50S6vTTap = " ";

		public const string NR4SndBIl0 = "=";

		public const string oinStU9NGr = "4010";

		public const string voPSosrUC9 = "0";

		public const string fs3SzFbVxH = "0";

		public const int lbDGaEFRKl = 1020210;

		public const int h6XG5KPK8G = 1020211;

		public const int lU4GpUogGd = 1020219;

		public const int hpqGVBMSSw = 1020220;

		public const int xFIG35lIfp = 1020221;

		public const int JUkGNok5ke = 1020222;

		public const int y30GDE7mao = 1020230;

		public const int fQtGdQAaB4 = 1020231;

		public const int QFAGHruYFs = 1020232;
	}
}
namespace u9B0rZQeiiXovuOUat
{
	internal static class aB7bl8ekoMcHlmei21
	{
		public const string fmPGS0KObw = "{4EA70356-74C3-4493-9E2B-AE26CD904318}File";

		public const string odKGGM6LMq = "{4EA70356-74C3-4493-9E2B-AE26CD904318}PageSetup";

		public const string U4qGZgp61y = "{4EA70356-74C3-4493-9E2B-AE26CD904318}PrintPreview";

		public const string XghGbBI3p5 = "{4EA70356-74C3-4493-9E2B-AE26CD904318}Print";

		public const string tnYGsIVUKg = "{4EA70356-74C3-4493-9E2B-AE26CD904318}SendToECM";

		public const string zktGPhhGcm = "{4EA70356-74C3-4493-9E2B-AE26CD904318}Edit";

		public const string uvEGWBMyJs = "{4EA70356-74C3-4493-9E2B-AE26CD904318}Find";

		public const string Tl0Gv5uaZp = "{4EA70356-74C3-4493-9E2B-AE26CD904318}Find &Next\tF3";

		public const string KLXGrhstXU = "{4EA70356-74C3-4493-9E2B-AE26CD904318}Separator1";

		public const string nbHG9uCFXl = "{4EA70356-74C3-4493-9E2B-AE26CD904318}Restore All Original Values";

		public const string G15GRroXbx = "{4EA70356-74C3-4493-9E2B-AE26CD904318}View";

		public const string TAwGLXgwVA = "{4EA70356-74C3-4493-9E2B-AE26CD904318}CollapseAll";

		public const string jEuGcGM3m4 = "{4EA70356-74C3-4493-9E2B-AE26CD904318}ExpandAll";

		public const string soaGT4uUvD = "{4EA70356-74C3-4493-9E2B-AE26CD904318}Refresh";

		public const int ppMGYE4QDq = 2048;

		public const int Xr1GI9mdfi = 0;
	}
}
namespace feYyMGynQg1v7Yr2WO
{
	internal static class XVBwx1KK21NFEiNbCR
	{
		public const string TBKGuYdfTE = "{4EA70356-74C3-4493-9E2B-AE26CD904318}Print";

		public const string GpVGkSX4QW = "{4EA70356-74C3-4493-9E2B-AE26CD904318}Preview";

		public const string A88GU9Qehm = "{4EA70356-74C3-4493-9E2B-AE26CD904318}Refresh";

		public const string dwGGMwY9Ps = "{4EA70356-74C3-4493-9E2B-AE26CD904318}Find";

		public const string DGnGwaDwJN = "{4EA70356-74C3-4493-9E2B-AE26CD904318}Send to ECM";
	}
}
namespace d6U64NFKQfVmPNh0kp
{
	internal static class MJXovnJLcie301sQuJ
	{
		public const string isIGhrg5ZA = "GridHeaderCM";

		public const string xjgGA73eep = "GridCM";
	}
}
namespace y4UUttxXSZRqq7vYb0
{
	internal static class ciCylQlEKq8lD1o8GT
	{
		public const int CMjGBm9ynR = 102;

		public const int tqbGelfSLf = 102;

		public const int CQwGQKDmXL = 0;

		public const int OTOGKIGS1s = 1;

		public const string whlGy3lC8r = "{2E473ECD-9359-4B78-BC47-AF5E692D9DE0}";
	}
}
namespace CZw0uDgCfCRwbjvsTQ
{
	internal static class EQ4XYf07OLW0ksPiFt
	{
		internal const string xtHGJNBsem = "{4EA70356-74C3-4493-9E2B-AE26CD904318}";

		internal const string pTBGFqQJnf = "{052113AD-8285-4E41-83FA-66B61C7458DF}";
	}
}
namespace inyWT7qe4mIIL9vqn5
{
	internal static class It8NvY7BpqF7v0VLit
	{
		public const int mIGGlf58RR = 5;

		public const int Q6LGxA76p4 = 16;

		public const int S6rG0gV2g0 = 2;

		public const uint wncGgVaWPB = uint.MaxValue;

		public const int yWcG7U5TwL = 102;

		public const string ChHGqOjSJx = "INSITE";

		public const int l1FG8iixSN = 239;

		public const int RodGikqELW = 240;

		public const int a31GjdcdyS = 241;

		public const string ufhGOwbBh7 = "Cummins";

		public const int yeGGX2Rjix = 242;

		public const int Yh4GCdfShq = 243;

		public const string RpRGEYvD02 = "NA";

		public const int exvG1EheMe = 244;
	}
}
namespace WjeZhbiQgYbsYgg8qV
{
	internal static class MeILRM8wWV0x9o1PR0
	{
		public const int HA2GfH7Sme = 4;

		public const int UZsGmyBNP2 = 3;

		public const int LYRG4MGEBk = 1;

		public const int CHaG2gZVL1 = -1;

		public const string pKZG6IC52F = "Features & Parameters";

		public const string oFXGnoMR8f = "SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\Users\\Administrator";

		public const int wZHGtHbrTx = 0;

		public const int qIAGoxXiId = 1;

		public const int slBGzolBuX = 2;

		public const int SqKZao1hbg = 3;

		public const int m2wZ5EpTNo = 0;

		public const string yRoZpwNDYR = "\\Appearance\\Backgrounds";

		public const string DMZZV9NQ97 = "\\Appearance\\Grid Lines";

		public const string MSKZ3ChMX3 = "\\Appearance\\Text";

		public const string hN8ZNmDVP2 = "\\";

		public const string ukRZDEBAZ2 = " - ";

		public const string gj7ZduhKis = "Color";

		public const string yvvZH8s4MD = "Bold";

		public const string nbpZSel2va = "Italic";

		public const string ajdZGuibew = "Name";

		public const string x07ZZDplRU = "Size";

		public const string xO7ZbWOOk2 = "Strikethrough";

		public const string HhXZsy9bPj = "Underline";

		public const string qPvZPHCqW7 = "Document";

		public const int l9QZWljy3S = 16777215;

		public const int PN3ZvI4i1S = 12632256;

		public const int OSAZrGWINg = 0;

		public const int Qi0Z97swp6 = 12;

		public const bool iqZZRWdDjX = false;

		public const bool FcOZLcZDOI = false;

		public const string RbDZcGQFJ7 = "MS Shell Dlg";

		public const bool a4nZTiBiRV = false;

		public const bool gE4ZYf4UQ6 = false;

		public const string VOLZITHBgD = "FeatureStyle";

		public const int TF3ZulhtQI = 99;

		public const string qfGZkmKlPQ = "FNP_IDS_HEADER_FEATURESPARAM";

		public const string AxYZUCDFIe = "FNP_IDS_HEADER_ECMVAL";

		public const string c7WZMvtxZ6 = "FNP_IDS_HEADER_UNIT";

		public const string uRUZwBDXcu = "FNP_IDS_HEADER_ORGVAL";

		public const int zPyZhF7HYW = 12000;

		public static char[] VE9ZA4chWi;

		public static char[] R5oZBVxwnF;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static MeILRM8wWV0x9o1PR0()
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			VE9ZA4chWi = new char[1] { '\t' };
			R5oZBVxwnF = new char[1] { ',' };
		}
	}
}
namespace Cummins.Insite.AddIns.FeaturesAndParameters.Model.Tooltip
{
	public sealed class TooltipProvider : ITooltipProvider
	{
		private ECMDataReader WAFZek8A8w;

		private ILocalizedStringProvider SCqZQn1sTN;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public TooltipProvider(ECMDataReader ecmDataReader)
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
			WAFZek8A8w = ecmDataReader;
			SCqZQn1sTN = Factory.CreateInstance<ILocalizedStringProvider>();
			SCqZQn1sTN.Initialize(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(39634));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		string ITooltipProvider.ProvideFeatureExclusiveTooltip(FeatureExclusiveTooltipInfo tooltipInfo)
		{
			string result = string.Empty;
			try
			{
				utJYLrsC7XmAim2WsS utJYLrsC7XmAim2WsS = new utJYLrsC7XmAim2WsS(SCqZQn1sTN);
				result = utJYLrsC7XmAim2WsS.UO4VEqxj54(tooltipInfo);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.TooltipProvider, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.TooltipProvider, exception2);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		string ITooltipProvider.ProvideLimitsTooltip(LimitsTooltipInfo tooltipInfo, IFnPElement element, ValidateLimit limit)
		{
			if (element == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(39712), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(39848));
			}
			string result = string.Empty;
			try
			{
				LimitTooltip limitTooltip = new LimitTooltip(SCqZQn1sTN, WAFZek8A8w);
				result = limitTooltip.GetTooltip(tooltipInfo, element, limit);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.TooltipProvider, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.TooltipProvider, exception2);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		string ITooltipProvider.ProvideLockStateTooltip(LockStateTooltipInfo tooltipInfo, IFnPElement element)
		{
			if (element == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(39866), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(40008));
			}
			string result = string.Empty;
			try
			{
				ldYfTuSS2jZcaCHFLr ldYfTuSS2jZcaCHFLr = new ldYfTuSS2jZcaCHFLr(SCqZQn1sTN, WAFZek8A8w);
				result = ldYfTuSS2jZcaCHFLr.KSXVIAV2DW(tooltipInfo, element);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.TooltipProvider, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.TooltipProvider, exception2);
			}
			catch (ECMDataReaderException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.TooltipProvider, exception3);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		string ITooltipProvider.ProvideInvalidValueTooltip(IFnPElement element)
		{
			if (element == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(40026), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(40168));
			}
			string result = string.Empty;
			try
			{
				p3bA1eZ5MudtwDIldZ p3bA1eZ5MudtwDIldZ = new p3bA1eZ5MudtwDIldZ(SCqZQn1sTN, WAFZek8A8w);
				result = p3bA1eZ5MudtwDIldZ.nMUVjbe4x4(element);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.TooltipProvider, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.TooltipProvider, exception2);
			}
			catch (ECMDataReaderException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.TooltipProvider, exception3);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		string ITooltipProvider.ProvideInvalidValueTooltip(IFnPElement element, List<string> failedRules)
		{
			if (element == null)
			{
				throw new ArgumentException(NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(40186), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(40328));
			}
			string result = string.Empty;
			try
			{
				p3bA1eZ5MudtwDIldZ p3bA1eZ5MudtwDIldZ = new p3bA1eZ5MudtwDIldZ(SCqZQn1sTN, WAFZek8A8w);
				result = p3bA1eZ5MudtwDIldZ.IIMVOm6eTb(element, failedRules);
			}
			catch (ArgumentException exception)
			{
				FnPTraceLoger.TryLog(LogCategory.TooltipProvider, exception);
			}
			catch (InvalidOperationException exception2)
			{
				FnPTraceLoger.TryLog(LogCategory.TooltipProvider, exception2);
			}
			catch (ECMDataReaderException exception3)
			{
				FnPTraceLoger.TryLog(LogCategory.TooltipProvider, exception3);
			}
			return result;
		}
	}
}
internal class <Module>{D4832F71-D695-4C4F-A2E3-178214897E1A}
{
}
namespace OwNJDLOxtkq2aTjVO7
{
	internal class Q637pcjgnZVkpFDAfc
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static System.Reflection.Module A3DZK8Dtch;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void s5nkaw44e1wqP(int typemdt)
		{
			Type type = A3DZK8Dtch.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)A3DZK8Dtch.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Q637pcjgnZVkpFDAfc()
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static Q637pcjgnZVkpFDAfc()
		{
			EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
			A3DZK8Dtch = typeof(Q637pcjgnZVkpFDAfc).Assembly.ManifestModule;
		}
	}
}
namespace aGJH07CLHmAAlye44W
{
	internal class NxeCcbXi414hXVG2Oh
	{
		internal class DGJYJAEELS6nLrPJmi : Attribute
		{
			internal class dvh7td1IeJs4f0G3WC<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public dvh7td1IeJs4f0G3WC()
				{
					EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[DGJYJAEELS6nLrPJmi(typeof(NxeCcbXi414hXVG2Oh/DGJYJAEELS6nLrPJmi/dvh7td1IeJs4f0G3WC<object>[]))]
			public DGJYJAEELS6nLrPJmi(object P_0)
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}
		}

		internal class aFQht0fMCxdxGKCqtK
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[DGJYJAEELS6nLrPJmi(typeof(NxeCcbXi414hXVG2Oh/DGJYJAEELS6nLrPJmi/dvh7td1IeJs4f0G3WC<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (BfLbToX8pp(Convert.ToBase64String(typeof(NxeCcbXi414hXVG2Oh).Assembly.GetName().GetPublicKeyToken()), NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(40346)) != NxeCcbXi414hXVG2Oh.pLOZyGi5pJ(40352))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[DGJYJAEELS6nLrPJmi(typeof(NxeCcbXi414hXVG2Oh/DGJYJAEELS6nLrPJmi/dvh7td1IeJs4f0G3WC<object>[]))]
			internal static string BfLbToX8pp(string P_0, string P_1)
			{
				byte[] bytes = Encoding.Unicode.GetBytes(P_0);
				byte[] array = bytes;
				byte[] key = new byte[32]
				{
					82, 102, 104, 110, 32, 77, 24, 34, 118, 181,
					51, 17, 18, 51, 12, 109, 10, 32, 77, 24,
					34, 158, 161, 41, 97, 28, 118, 181, 5, 25,
					1, 88
				};
				MD5 mD = new MD5CryptoServiceProvider();
				byte[] iV = mD.ComputeHash(Encoding.Unicode.GetBytes(P_1));
				MemoryStream memoryStream = new MemoryStream();
				Rijndael rijndael = Rijndael.Create();
				rijndael.Key = key;
				rijndael.IV = iV;
				CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateEncryptor(), CryptoStreamMode.Write);
				cryptoStream.Write(array, 0, array.Length);
				cryptoStream.Close();
				return Convert.ToBase64String(memoryStream.ToArray());
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public aFQht0fMCxdxGKCqtK()
			{
				EXoF78nf1V3a45pjv0.W2wkaw4z78Yh4();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint KkRfoemOtbJ3mJllnT([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr fDTOfA4D5n0hD9yL3i();

		internal struct Oc07K42HReOEcnr2E3
		{
			internal bool kPVbYZSvHk;

			internal byte[] DigbIRT5RX;
		}

		[Flags]
		private enum y82kIZ69dEMBKGbhZO
		{

		}

		private static byte[] f6kbplVVT5;

		private static IntPtr drYbNlXtf1;

		private static int KE5bSdsKhZ;

		private static SortedList lI1bZVGPHm;

		private static int lvUbbqmOdI;

		internal static KkRfoemOtbJ3mJllnT B0sbWWI3Rl;

		internal static Hashtable SkDbcIhOYv;

		private static byte[] hDPb5INxZT;

		private static int ArLbrL2Js2;

		private static object u8ObdC7tyw;

		private static byte[] IBOb300DIa;

		private static bool EJybGEXoQ6;

		internal static KkRfoemOtbJ3mJllnT a9VbPksPxt;

		private static int ibrbR1IJjH;

		private static int[] QoEbHCJSXf;

		private static long S44bs0Kras;

		private static long Marbv9o9Vo;

		private static byte[] qNrbV59CTv;

		private static IntPtr LxdbL0vkLU;

		private static IntPtr IExbDo4K3X;

		private static bool UxJb9nlyIO;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static NxeCcbXi414hXVG2Oh()
		{
			hDPb5INxZT = new byte[0];
			f6kbplVVT5 = new byte[0];
			qNrbV59CTv = new byte[0];
			IBOb300DIa = new byte[0];
			drYbNlXtf1 = IntPtr.Zero;
			IExbDo4K3X = IntPtr.Zero;
			u8ObdC7tyw = new string[0];
			QoEbHCJSXf = new int[0];
			KE5bSdsKhZ = 1;
			EJybGEXoQ6 = false;
			lI1bZVGPHm = new SortedList();
			lvUbbqmOdI = 0;
			S44bs0Kras = 0L;
			a9VbPksPxt = null;
			B0sbWWI3Rl = null;
			Marbv9o9Vo = 0L;
			ArLbrL2Js2 = 0;
			UxJb9nlyIO = false;
			ibrbR1IJjH = 0;
			LxdbL0vkLU = IntPtr.Zero;
			SkDbcIhOYv = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void yU7kaw4NOo77o()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[DGJYJAEELS6nLrPJmi(typeof(NxeCcbXi414hXVG2Oh/DGJYJAEELS6nLrPJmi/dvh7td1IeJs4f0G3WC<object>[]))]
		static string pLOZyGi5pJ(int P_0)
		{
			int num = 302;
			int num7 = default(int);
			byte[] array2 = default(byte[]);
			byte[] array = default(byte[]);
			int num4 = default(int);
			ICryptoTransform transform = default(ICryptoTransform);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array6 = default(byte[]);
			byte[] array3 = default(byte[]);
			int num5 = default(int);
			MemoryStream memoryStream = default(MemoryStream);
			byte[] array5 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			byte[] array4 = default(byte[]);
			int num6 = default(int);
			CryptoStream cryptoStream = default(CryptoStream);
			while (true)
			{
				int num2 = num;
				while (true)
				{
					int num3 = num2;
					while (true)
					{
						switch (num3)
						{
						case 271:
							break;
						case 7:
							goto IL_002a;
						case 99:
							goto IL_0042;
						case 75:
							goto IL_005e;
						case 305:
							num7 = 54 + 43;
							num2 = 56;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 235;
						case 364:
							array2[4] = 132;
							num3 = 75;
							continue;
						case 370:
							array[30] = (byte)num7;
							num2 = 72;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 92;
						case 92:
							array[26] = (byte)num4;
							num2 = 36;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 119;
						case 107:
							array[21] = (byte)num4;
							num3 = 52;
							continue;
						case 282:
							array[11] = 108;
							num3 = 110;
							continue;
						case 367:
							num4 = 91 + 66;
							num3 = 98;
							continue;
						case 147:
							transform = (ICryptoTransform)ELOc1qHvmswRMKk0Ci(rijndaelManaged, array6, array3);
							num = 161;
							goto end_IL_21b6;
						case 157:
							array2[1] = 99;
							num2 = 5;
							goto end_IL_21ba;
						case 259:
							num5 = 176 - 58;
							num = 10;
							goto end_IL_21b6;
						case 202:
							array[6] = (byte)num4;
							num2 = 77;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 189;
						case 189:
							qNrbV59CTv = (byte[])GGxY4jGxu3rxDvWvBp(memoryStream);
							num = 182;
							goto end_IL_21b6;
						case 248:
							array2[11] = (byte)num5;
							num = 276;
							goto end_IL_21b6;
						case 293:
							num7 = 239 - 79;
							num2 = 379;
							goto end_IL_21ba;
						case 48:
							num4 = 136 - 45;
							num = 199;
							goto end_IL_21b6;
						case 41:
							array[18] = (byte)num4;
							num = 354;
							goto end_IL_21b6;
						case 251:
							num7 = 102 + 92;
							num = 309;
							goto end_IL_21b6;
						case 292:
							array[14] = 7;
							num = 326;
							goto end_IL_21b6;
						case 211:
							array[13] = (byte)num7;
							num2 = 163;
							goto end_IL_21ba;
						case 317:
							array[2] = (byte)num7;
							num = 372;
							goto end_IL_21b6;
						case 84:
							array[26] = 171;
							num = 140;
							goto end_IL_21b6;
						case 156:
							array5 = (byte[])hsNjYl3d33cfvln9f9(binaryReader, (int)tR7OGj4nAWgokekjTN(gZHkPSFV5Xc638Iapm(binaryReader)));
							num2 = 102;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 204;
						case 204:
							array[27] = 136;
							num = 214;
							goto end_IL_21b6;
						case 26:
							num4 = 168 + 10;
							num = 131;
							goto end_IL_21b6;
						case 17:
							num5 = 212 - 70;
							num2 = 45;
							goto end_IL_21ba;
						case 265:
							num7 = 110 + 36;
							num = 71;
							goto end_IL_21b6;
						case 190:
							array[26] = (byte)num4;
							num2 = 327;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 355;
						case 355:
							array[20] = (byte)num7;
							num2 = 47;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 226;
						case 226:
							array3[11] = array4[5];
							num2 = 288;
							goto end_IL_21ba;
						case 47:
							num4 = 124 + 51;
							num = 208;
							goto end_IL_21b6;
						case 258:
							num5 = 43 + 81;
							num = 176;
							goto end_IL_21b6;
						case 58:
							num7 = 101 + 44;
							num2 = 224;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 372;
						case 372:
							array[3] = 120;
							num2 = 83;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 112;
						case 112:
							array[15] = (byte)num7;
							num2 = 26;
							goto end_IL_21ba;
						case 260:
							num5 = 50 + 83;
							num2 = 145;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 215;
						case 338:
							num5 = 76 + 32;
							num2 = 23;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 165;
						case 165:
							array[26] = 144;
							num = 84;
							goto end_IL_21b6;
						case 311:
							num4 = 181 - 60;
							num3 = 74;
							continue;
						case 91:
							array[9] = (byte)num7;
							num2 = 365;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 208;
						case 200:
							array2[5] = 245;
							num2 = 313;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 212;
						case 212:
							num5 = 58 + 97;
							num = 96;
							goto end_IL_21b6;
						case 113:
							array[25] = 84;
							num3 = 46;
							continue;
						case 381:
							array[8] = 119;
							num2 = 49;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 24;
						case 382:
							array[1] = 133;
							num3 = 249;
							continue;
						case 314:
							num7 = 126 - 42;
							num2 = 322;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 373;
						case 24:
							array[27] = 114;
							num2 = 204;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 351;
						case 351:
							array2[4] = (byte)num5;
							num2 = 100;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 166;
						case 166:
							num4 = 76 + 73;
							num2 = 22;
							goto end_IL_21ba;
						case 309:
							array[0] = (byte)num7;
							num = 2;
							goto end_IL_21b6;
						case 23:
							array2[13] = (byte)num5;
							num2 = 310;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 377;
						case 377:
							array[12] = 126;
							num2 = 33;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 130;
						case 130:
							array4 = (byte[])mqLnYcOXgYAUALPE7L(B2OXD426J4ytl2STuS(cVN3wQ16m1st3lE0ec(typeof(NxeCcbXi414hXVG2Oh).TypeHandle).Assembly));
							num = 172;
							goto end_IL_21b6;
						case 366:
							array[22] = 139;
							num = 125;
							goto end_IL_21b6;
						case 126:
							array[2] = 174;
							num = 330;
							goto end_IL_21b6;
						case 326:
							array[15] = 88;
							num2 = 277;
							goto end_IL_21ba;
						case 37:
							array[4] = 104;
							num2 = 217;
							goto end_IL_21ba;
						case 216:
							array2[10] = 109;
							num3 = 186;
							continue;
						case 184:
							num7 = 92 + 100;
							num2 = 195;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 98;
						case 98:
							array[16] = (byte)num4;
							num = 291;
							goto end_IL_21b6;
						case 96:
							array2[3] = (byte)num5;
							num3 = 259;
							continue;
						case 331:
							array2[12] = 74;
							num3 = 149;
							continue;
						case 280:
						case 375:
							num5 = 88 + 85;
							num2 = 239;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 236;
						case 236:
							array2[8] = 96;
							num3 = 201;
							continue;
						case 67:
							array[17] = (byte)num7;
							num = 295;
							goto end_IL_21b6;
						case 117:
							array2[10] = (byte)num5;
							num2 = 374;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 171;
						case 171:
						case 219:
							array[23] = (byte)num4;
							num2 = 29;
							goto end_IL_21ba;
						case 33:
							num7 = 248 - 82;
							num = 335;
							goto end_IL_21b6;
						case 90:
							array2[9] = (byte)num5;
							num = 216;
							goto end_IL_21b6;
						case 57:
							array[28] = 134;
							num2 = 240;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 300;
						case 300:
							array[24] = (byte)num4;
							num2 = 312;
							goto end_IL_21ba;
						case 11:
							array[28] = (byte)num7;
							num = 241;
							goto end_IL_21b6;
						case 363:
							array2[12] = (byte)num5;
							num = 341;
							goto end_IL_21b6;
						case 103:
							num5 = 52 + 3;
							num2 = 332;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 65;
						case 65:
							array[0] = 137;
							num = 340;
							goto end_IL_21b6;
						case 380:
							array[12] = 91;
							num = 27;
							goto end_IL_21b6;
						case 323:
							num7 = 123 + 93;
							num = 196;
							goto end_IL_21b6;
						case 127:
							array[8] = (byte)num4;
							num2 = 184;
							goto end_IL_21ba;
						case 40:
							array2[10] = (byte)num5;
							num = 63;
							goto end_IL_21b6;
						case 50:
							array3[5] = array4[2];
							num2 = 70;
							goto end_IL_21ba;
						case 279:
							array3[1] = array4[0];
							num3 = 183;
							continue;
						case 182:
							tgCs6hPhrY3hxGAtbv(memoryStream);
							num2 = 86;
							goto end_IL_21ba;
						case 308:
							num5 = 99 + 65;
							num3 = 349;
							continue;
						case 310:
							num5 = 128 - 42;
							num = 290;
							goto end_IL_21b6;
						case 123:
							num5 = 193 - 90;
							num3 = 88;
							continue;
						case 201:
							num5 = 68 + 47;
							num3 = 170;
							continue;
						case 383:
							array[26] = (byte)num7;
							num3 = 165;
							continue;
						case 148:
							array[17] = 130;
							num = 150;
							goto end_IL_21b6;
						case 80:
							array2[6] = 89;
							num3 = 237;
							continue;
						case 14:
							array[27] = (byte)num7;
							num2 = 24;
							goto end_IL_21ba;
						case 160:
							array[30] = (byte)num7;
							num3 = 320;
							continue;
						case 297:
							array2[4] = (byte)num5;
							num2 = 105;
							goto end_IL_21ba;
						case 313:
							num5 = 106 + 62;
							num2 = 118;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 70;
						case 70:
							array3[7] = array4[3];
							num = 346;
							goto end_IL_21b6;
						case 94:
							num5 = 253 - 84;
							num2 = 42;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 289;
						case 289:
							num4 = 85 + 66;
							num = 185;
							goto end_IL_21b6;
						case 243:
							array[5] = 136;
							num2 = 218;
							goto end_IL_21ba;
						case 349:
							array2[13] = (byte)num5;
							num3 = 9;
							continue;
						case 168:
							num7 = 154 - 51;
							num2 = 343;
							goto end_IL_21ba;
						case 140:
							array[27] = 148;
							num3 = 361;
							continue;
						case 295:
							num7 = 194 - 64;
							num = 203;
							goto end_IL_21b6;
						case 93:
							array[10] = 157;
							num2 = 206;
							goto end_IL_21ba;
						case 135:
							array[10] = (byte)num4;
							num2 = 93;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 315;
						case 315:
							array[6] = 167;
							num2 = 177;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 258;
						case 19:
							num7 = 143 - 47;
							num = 213;
							goto end_IL_21b6;
						case 144:
							array2[9] = 97;
							num = 318;
							goto end_IL_21b6;
						case 175:
							num4 = 254 - 84;
							num2 = 263;
							goto end_IL_21ba;
						case 60:
							array[19] = (byte)num4;
							num2 = 254;
							goto end_IL_21ba;
						case 109:
							num7 = 226 - 75;
							num = 106;
							goto end_IL_21b6;
						case 273:
							array2[0] = 186;
							num2 = 230;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 228;
						case 228:
							array[4] = 54;
							num = 116;
							goto end_IL_21b6;
						case 249:
							num7 = 0 + 4;
							num2 = 188;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 5;
						case 5:
							array2[1] = 113;
							num3 = 284;
							continue;
						case 337:
							array2[14] = 194;
							num2 = 103;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 291;
						case 291:
							num4 = 38 + 118;
							num = 138;
							goto end_IL_21b6;
						case 186:
							num5 = 105 + 15;
							num3 = 117;
							continue;
						case 174:
							f3kCM7gyuLBqHWBb07(true);
							num2 = 156;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 56;
						case 38:
							array2[15] = (byte)num5;
							num3 = 316;
							continue;
						case 362:
							array[14] = (byte)num4;
							num3 = 1;
							continue;
						case 83:
							array[3] = 40;
							num2 = 68;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 346;
						case 346:
							array3[9] = array4[4];
							num2 = 226;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 290;
						case 290:
							array2[13] = (byte)num5;
							num = 308;
							goto end_IL_21b6;
						case 6:
							num7 = 35 + 92;
							num2 = 347;
							goto end_IL_21ba;
						case 124:
							array[19] = 143;
							num2 = 369;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 235;
						case 235:
							array[21] = (byte)num7;
							num2 = 151;
							goto end_IL_21ba;
						case 358:
							array[22] = 221;
							num = 104;
							goto end_IL_21b6;
						case 307:
							array[31] = 151;
							num2 = 191;
							goto end_IL_21ba;
						case 131:
							array[15] = (byte)num4;
							num2 = 58;
							goto end_IL_21ba;
						case 333:
							num5 = 204 - 82;
							num2 = 40;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 185;
						case 263:
							array[21] = (byte)num4;
							num = 155;
							goto end_IL_21b6;
						case 114:
							array2[3] = (byte)num5;
							num3 = 250;
							continue;
						case 318:
							num5 = 232 - 77;
							num3 = 321;
							continue;
						case 29:
							num4 = 151 - 50;
							num = 181;
							goto end_IL_21b6;
						case 220:
							num4 = 177 - 59;
							num2 = 356;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 192;
						case 192:
							array[24] = 225;
							num2 = 314;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 68;
						case 335:
							array[12] = (byte)num7;
							num = 109;
							goto end_IL_21b6;
						case 359:
							num4 = 166 + 87;
							num3 = 62;
							continue;
						case 116:
							num7 = 2 + 114;
							num2 = 197;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 336;
						case 336:
							array2[7] = (byte)num5;
							num2 = 357;
							goto end_IL_21ba;
						case 101:
							num4 = 161 - 56;
							num2 = 300;
							goto end_IL_21ba;
						case 246:
							array[17] = 119;
							num = 148;
							goto end_IL_21b6;
						case 272:
							num5 = 216 - 72;
							num2 = 261;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 222;
						case 68:
							array[3] = 132;
							num2 = 34;
							goto end_IL_21ba;
						case 373:
							num4 = 51 + 10;
							num2 = 287;
							goto end_IL_21ba;
						case 20:
							array[6] = (byte)num4;
							num3 = 48;
							continue;
						case 230:
							num5 = 7 + 16;
							num2 = 233;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 166;
						case 267:
							num4 = 167 - 55;
							num = 362;
							goto end_IL_21b6;
						case 203:
							array[17] = (byte)num7;
							num3 = 223;
							continue;
						case 369:
							array[19] = 145;
							num3 = 55;
							continue;
						case 185:
							array[7] = (byte)num4;
							num2 = 85;
							goto end_IL_21ba;
						case 172:
							if (array4 != null)
							{
								num = 345;
								goto end_IL_21b6;
							}
							goto case 158;
						case 241:
							array[28] = 99;
							num2 = 35;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 339;
						case 339:
							array2[11] = 159;
							num = 133;
							goto end_IL_21b6;
						case 136:
							num7 = 215 - 71;
							num = 348;
							goto end_IL_21b6;
						case 122:
							num7 = 196 - 65;
							num3 = 194;
							continue;
						case 277:
							num7 = 167 - 55;
							num2 = 112;
							goto end_IL_21ba;
						case 125:
							array[22] = 127;
							num3 = 215;
							continue;
						case 81:
							num7 = 77 - 50;
							num = 355;
							goto end_IL_21b6;
						case 252:
							array[20] = 49;
							num2 = 81;
							goto end_IL_21ba;
						case 146:
							num4 = 44 + 92;
							num2 = 274;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 199;
						case 199:
							array[6] = (byte)num4;
							num2 = 143;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 79;
						case 150:
							num7 = 216 - 72;
							num3 = 67;
							continue;
						case 296:
							array2[14] = (byte)num5;
							num = 121;
							goto end_IL_21b6;
						case 250:
							num5 = 120 + 3;
							num3 = 325;
							continue;
						case 334:
							num6 = E7Co76LwTtDfSI0B7o(qNrbV59CTv, P_0);
							num2 = 384;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 371;
						case 371:
							num4 = 111 + 25;
							num = 92;
							goto end_IL_21b6;
						case 229:
							array[13] = (byte)num7;
							num = 267;
							goto end_IL_21b6;
						case 21:
							num5 = 82 + 69;
							num2 = 38;
							goto end_IL_21ba;
						case 76:
							array2[9] = (byte)num5;
							num2 = 54;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 244;
						case 244:
							num5 = 191 - 63;
							num2 = 111;
							goto end_IL_21ba;
						case 61:
							array[0] = (byte)num7;
							num2 = 65;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 261;
						case 261:
							array2[2] = (byte)num5;
							num2 = 59;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 22;
						case 22:
							array[24] = (byte)num4;
							num3 = 220;
							continue;
						case 169:
							array2[7] = (byte)num5;
							num2 = 360;
							goto end_IL_21ba;
						case 111:
							array2[8] = (byte)num5;
							num3 = 173;
							continue;
						case 134:
							array6 = array;
							num3 = 262;
							continue;
						case 104:
							array[22] = 124;
							num3 = 366;
							continue;
						case 322:
							array[24] = (byte)num7;
							num = 101;
							goto end_IL_21b6;
						case 77:
							array[6] = 147;
							num = 119;
							goto end_IL_21b6;
						case 87:
							num5 = 164 - 54;
							num = 51;
							goto end_IL_21b6;
						case 2:
							array[1] = 118;
							num2 = 311;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 215;
						case 215:
							num4 = 79 + 121;
							num = 238;
							goto end_IL_21b6;
						case 85:
							array[7] = 118;
							num2 = 66;
							goto end_IL_21ba;
						case 163:
							num7 = 171 - 56;
							num = 229;
							goto end_IL_21b6;
						case 210:
							array[25] = 96;
							num = 371;
							goto end_IL_21b6;
						case 269:
							num5 = 254 - 84;
							num = 152;
							goto end_IL_21b6;
						case 132:
							array[20] = 95;
							num2 = 252;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 232;
						case 232:
							array[19] = (byte)num7;
							num2 = 285;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 71;
						case 71:
							array[13] = (byte)num7;
							num2 = 298;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 162;
						case 162:
							num7 = 34 - 18;
							num3 = 91;
							continue;
						case 188:
							array[1] = (byte)num7;
							num3 = 128;
							continue;
						case 303:
							num5 = 151 - 81;
							num3 = 114;
							continue;
						case 64:
							array[9] = 72;
							num = 305;
							goto end_IL_21b6;
						case 49:
							num4 = 225 - 75;
							num = 127;
							goto end_IL_21b6;
						case 360:
							num5 = 242 - 80;
							num2 = 306;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 118;
						case 118:
							array2[6] = (byte)num5;
							goto case 280;
						case 209:
							num5 = 213 - 71;
							num2 = 363;
							goto end_IL_21ba;
						case 121:
							array2[14] = 96;
							num2 = 337;
							goto end_IL_21ba;
						case 328:
							array[29] = (byte)num4;
							num = 129;
							goto end_IL_21b6;
						case 275:
							array[29] = 120;
							num2 = 136;
							goto end_IL_21ba;
						case 195:
							array[8] = (byte)num7;
							num2 = 139;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 133;
						case 133:
							num5 = 50 - 31;
							num = 248;
							goto end_IL_21b6;
						case 237:
							array2[6] = 86;
							num = 97;
							goto end_IL_21b6;
						case 274:
							array[19] = (byte)num4;
							num2 = 124;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 233;
						case 233:
							array2[1] = (byte)num5;
							num2 = 157;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 108;
						case 108:
							num7 = 80 + 53;
							num3 = 301;
							continue;
						case 283:
							array[11] = 212;
							num = 257;
							goto end_IL_21b6;
						case 324:
							array[31] = 68;
							num2 = 307;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 347;
						case 347:
							array[13] = (byte)num7;
							num3 = 265;
							continue;
						case 254:
							num7 = 136 - 45;
							num2 = 232;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 155;
						case 155:
							num7 = 56 + 24;
							num2 = 235;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 159;
						case 43:
							array[21] = (byte)num4;
							num3 = 175;
							continue;
						case 164:
							v121xeXPm5iKaEy2tR(gZHkPSFV5Xc638Iapm(binaryReader), 0L);
							num2 = 174;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 316;
						case 316:
							array2[15] = 120;
							num2 = 89;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 345;
						case 345:
							if (array4.Length <= 0)
							{
								goto case 158;
							}
							num = 279;
							goto end_IL_21b6;
						case 170:
							array2[8] = (byte)num5;
							num3 = 244;
							continue;
						case 45:
							array2[11] = (byte)num5;
							num3 = 339;
							continue;
						case 1:
							array[14] = 142;
							num2 = 292;
							goto end_IL_21ba;
						case 178:
							array[2] = (byte)num7;
							num3 = 69;
							continue;
						case 52:
							num7 = 207 - 98;
							num = 53;
							goto end_IL_21b6;
						case 167:
							num5 = 217 - 72;
							num = 352;
							goto end_IL_21b6;
						case 231:
							num4 = 83 - 22;
							num = 328;
							goto end_IL_21b6;
						case 234:
							num4 = 140 - 46;
							num2 = 135;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 373;
						case 321:
							array2[9] = (byte)num5;
							num3 = 258;
							continue;
						case 152:
							array2[3] = (byte)num5;
							num3 = 212;
							continue;
						case 151:
							num4 = 130 - 43;
							num2 = 107;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 73;
						case 205:
							WsHH9MQFg73DyPSjyI(cryptoStream);
							num = 189;
							goto end_IL_21b6;
						case 18:
							array2[13] = (byte)num5;
							num2 = 304;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 28;
						case 28:
							num4 = 69 + 59;
							num2 = 319;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 343;
						case 343:
							array[5] = (byte)num7;
							num2 = 108;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 368;
						case 368:
							num5 = 54 + 106;
							num2 = 336;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 328;
						case 183:
							array3[3] = array4[1];
							num2 = 50;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 304;
						case 304:
							array2[13] = 152;
							num = 338;
							goto end_IL_21b6;
						case 143:
							num4 = 82 + 92;
							num2 = 202;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 379;
						case 379:
							array[29] = (byte)num7;
							num = 275;
							goto end_IL_21b6;
						case 281:
							array[2] = (byte)num7;
							num3 = 126;
							continue;
						case 89:
							array2[15] = 244;
							num2 = 268;
							goto end_IL_21ba;
						case 39:
							array[23] = 164;
							num3 = 222;
							continue;
						case 257:
							num7 = 61 + 123;
							num = 378;
							goto end_IL_21b6;
						case 319:
							array[30] = (byte)num4;
							num = 141;
							goto end_IL_21b6;
						case 4:
							num7 = 50 + 50;
							num = 61;
							goto end_IL_21b6;
						case 25:
							array2[11] = (byte)num5;
							num2 = 115;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 357;
						case 357:
							num5 = 251 - 83;
							num3 = 169;
							continue;
						case 284:
							array2[1] = 130;
							num2 = 123;
							goto end_IL_21ba;
						case 213:
							array[18] = (byte)num7;
							num3 = 78;
							continue;
						case 344:
							DmgQiGZeiaoi9mtNL6(cryptoStream, array5, 0, array5.Length);
							num = 205;
							goto end_IL_21b6;
						case 95:
							array3[15] = array4[7];
							num3 = 158;
							continue;
						case 79:
							num7 = 176 - 58;
							num = 13;
							goto end_IL_21b6;
						case 341:
							array2[12] = 64;
							num2 = 331;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 378;
						case 378:
							array[12] = (byte)num7;
							num = 377;
							goto end_IL_21b6;
						case 15:
							num5 = 213 - 71;
							num = 73;
							goto end_IL_21b6;
						case 181:
							array[23] = (byte)num4;
							num = 359;
							goto end_IL_21b6;
						case 149:
							array2[12] = 40;
							num3 = 198;
							continue;
						case 270:
							num7 = 95 + 78;
							num2 = 160;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 154;
						case 154:
							num5 = 233 - 77;
							num2 = 18;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 55;
						case 55:
							num7 = 161 - 53;
							num2 = 256;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 337;
						case 191:
							array[31] = 185;
							num3 = 134;
							continue;
						case 69:
							num7 = 75 - 70;
							num = 317;
							goto end_IL_21b6;
						case 129:
							num7 = 153 - 51;
							num = 370;
							goto end_IL_21b6;
						case 348:
							array[29] = (byte)num7;
							num2 = 231;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 250;
						case 218:
							array[5] = 181;
							num = 168;
							goto end_IL_21b6;
						case 187:
							array[24] = (byte)num4;
							num = 192;
							goto end_IL_21b6;
						case 78:
							num4 = 155 - 51;
							num2 = 41;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 97;
						case 97:
							array2[6] = 120;
							num2 = 368;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 197;
						case 197:
							array[5] = (byte)num7;
							num3 = 243;
							continue;
						case 153:
							array[11] = 100;
							num = 282;
							goto end_IL_21b6;
						case 46:
							num7 = 171 - 57;
							num2 = 207;
							goto end_IL_21ba;
						case 332:
							array2[14] = (byte)num5;
							num2 = 260;
							goto end_IL_21ba;
						case 12:
							PI8lOqyIDcjuNFldlH(binaryReader);
							num = 334;
							goto end_IL_21b6;
						case 53:
							array[21] = (byte)num7;
							num = 242;
							goto end_IL_21b6;
						case 299:
							array2[0] = 106;
							num = 255;
							goto end_IL_21b6;
						case 268:
							array3 = array2;
							num2 = 130;
							goto end_IL_21ba;
						case 13:
							array[13] = (byte)num7;
							num2 = 6;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 63;
						case 298:
							num7 = 213 - 71;
							num = 211;
							goto end_IL_21b6;
						case 306:
							array2[7] = (byte)num5;
							num2 = 271;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 312;
						case 312:
							num7 = 100 + 118;
							num2 = 221;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 354;
						case 354:
							num7 = 76 - 20;
							num2 = 16;
							goto end_IL_21ba;
						case 374:
							num5 = 133 - 44;
							num2 = 350;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 352;
						case 352:
							array2[13] = (byte)num5;
							num = 154;
							goto end_IL_21b6;
						case 35:
							array[28] = 82;
							num = 57;
							goto end_IL_21b6;
						case 36:
							num4 = 14 + 56;
							num2 = 190;
							goto end_IL_21ba;
						case 31:
							num4 = 87 + 85;
							num = 187;
							goto end_IL_21b6;
						case 102:
							array = new byte[32];
							num = 294;
							goto end_IL_21b6;
						case 137:
							array2[5] = (byte)num5;
							num = 87;
							goto end_IL_21b6;
						case 325:
							array2[4] = (byte)num5;
							num2 = 364;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 340;
						case 340:
							num7 = 123 + 29;
							num2 = 329;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 56;
						case 56:
							array[9] = (byte)num7;
							num = 162;
							goto end_IL_21b6;
						case 240:
							array[28] = 152;
							num3 = 122;
							continue;
						case 356:
							array[24] = (byte)num4;
							num = 31;
							goto end_IL_21b6;
						case 227:
							array[17] = (byte)num4;
							num3 = 19;
							continue;
						case 193:
							array[31] = 131;
							num3 = 324;
							continue;
						case 106:
							array[12] = (byte)num7;
							num = 380;
							goto end_IL_21b6;
						case 16:
							array[18] = (byte)num7;
							num2 = 3;
							goto end_IL_21ba;
						case 207:
							array[25] = (byte)num7;
							goto case 210;
						default:
							num3 = 210;
							continue;
						case 198:
							array2[12] = 37;
							num = 167;
							goto end_IL_21b6;
						case 120:
							array2[7] = 106;
							num = 8;
							goto end_IL_21b6;
						case 32:
							array[11] = 165;
							num = 283;
							goto end_IL_21b6;
						case 365:
							num4 = 19 + 91;
							num3 = 247;
							continue;
						case 115:
							array2[11] = 84;
							num3 = 17;
							continue;
						case 245:
							array2[0] = (byte)num5;
							num2 = 273;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 361;
						case 361:
							num7 = 180 - 60;
							num3 = 14;
							continue;
						case 177:
							num4 = 34 + 50;
							num = 20;
							goto end_IL_21b6;
						case 266:
							array2[2] = (byte)num5;
							num3 = 269;
							continue;
						case 105:
							num5 = 49 - 17;
							num2 = 351;
							goto end_IL_21ba;
						case 44:
							gQitw9KOT8rYrnnB48(rijndaelManaged, CipherMode.CBC);
							num = 147;
							goto end_IL_21b6;
						case 73:
							array2[3] = (byte)num5;
							num3 = 303;
							continue;
						case 320:
							array[31] = 156;
							num2 = 193;
							goto end_IL_21ba;
						case 9:
							num5 = 101 + 52;
							num2 = 296;
							goto end_IL_21ba;
						case 242:
							array[22] = 104;
							num2 = 358;
							goto end_IL_21ba;
						case 72:
							array[30] = 163;
							num3 = 28;
							continue;
						case 128:
							array[1] = 175;
							num2 = 82;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 253;
						case 59:
							num5 = 197 + 53;
							num2 = 266;
							goto end_IL_21ba;
						case 294:
							array[0] = 132;
							num = 4;
							goto end_IL_21b6;
						case 88:
							array2[1] = (byte)num5;
							num3 = 353;
							continue;
						case 247:
							array[10] = (byte)num4;
							num = 234;
							goto end_IL_21b6;
						case 63:
							num5 = 130 - 43;
							num2 = 25;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 225;
						case 225:
							array2[5] = 142;
							num2 = 376;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 256;
						case 256:
							array[20] = (byte)num7;
							num3 = 132;
							continue;
						case 30:
							cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
							num2 = 344;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 220;
						case 302:
							if (qNrbV59CTv.Length == 0)
							{
								num = 180;
								goto end_IL_21b6;
							}
							goto case 334;
						case 51:
							array2[5] = (byte)num5;
							num2 = 225;
							goto end_IL_21ba;
						case 330:
							num4 = 173 - 57;
							num2 = 286;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 159;
						case 159:
							num4 = 195 - 65;
							num3 = 43;
							continue;
						case 34:
							array[3] = 152;
							num2 = 373;
							goto end_IL_21ba;
						case 54:
							array2[9] = 186;
							num3 = 342;
							continue;
						case 142:
							num4 = 187 - 67;
							num = 264;
							goto end_IL_21b6;
						case 42:
							array2[5] = (byte)num5;
							num = 200;
							goto end_IL_21b6;
						case 214:
							num7 = 107 + 87;
							num = 11;
							goto end_IL_21b6;
						case 139:
							array[9] = 151;
							num2 = 64;
							goto end_IL_21ba;
						case 206:
							array[10] = 242;
							num3 = 323;
							continue;
						case 110:
							num4 = 184 - 61;
							num = 7;
							goto end_IL_21b6;
						case 173:
							num5 = 46 - 25;
							num2 = 278;
							goto end_IL_21ba;
						case 141:
							array[30] = 166;
							num3 = 270;
							continue;
						case 10:
							array2[3] = (byte)num5;
							num2 = 15;
							goto end_IL_21ba;
						case 100:
							num5 = 53 + 27;
							num = 137;
							goto end_IL_21b6;
						case 224:
							array[16] = (byte)num7;
							num = 367;
							goto end_IL_21b6;
						case 276:
							array2[12] = 154;
							num3 = 209;
							continue;
						case 0:
							array2[7] = (byte)num5;
							num = 236;
							goto end_IL_21b6;
						case 287:
							array[3] = (byte)num4;
							num3 = 142;
							continue;
						case 176:
							array2[9] = (byte)num5;
							num2 = 179;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 223;
						case 223:
							num4 = 125 + 67;
							num3 = 227;
							continue;
						case 82:
							num7 = 182 - 60;
							num2 = 281;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 327;
						case 327:
							num7 = 27 + 122;
							num2 = 383;
							goto end_IL_21ba;
						case 288:
							array3[13] = array4[6];
							num = 95;
							goto end_IL_21b6;
						case 239:
							array2[6] = (byte)num5;
							num2 = 80;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 238;
						case 238:
							array[22] = (byte)num4;
							num3 = 39;
							continue;
						case 138:
							array[16] = (byte)num4;
							num3 = 246;
							continue;
						case 8:
							num5 = 152 + 90;
							num3 = 0;
							continue;
						case 253:
							num7 = 226 - 75;
							num2 = 178;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 150;
						case 353:
							array2[2] = 135;
							num2 = 272;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 179;
						case 179:
							num5 = 171 - 57;
							num3 = 76;
							continue;
						case 208:
							array[21] = (byte)num4;
							num2 = 159;
							goto end_IL_21ba;
						case 194:
							array[29] = (byte)num7;
							num = 293;
							goto end_IL_21b6;
						case 342:
							num5 = 146 - 39;
							num = 90;
							goto end_IL_21b6;
						case 3:
							num4 = 17 + 1;
							num2 = 60;
							goto end_IL_21ba;
						case 86:
							tgCs6hPhrY3hxGAtbv(cryptoStream);
							num2 = 12;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 27;
						case 27:
							array[12] = 24;
							num2 = 79;
							if (true)
							{
								goto end_IL_21ba;
							}
							goto case 286;
						case 286:
							array[2] = (byte)num4;
							num2 = 253;
							goto end_IL_21ba;
						case 74:
							array[1] = (byte)num4;
							num = 382;
							goto end_IL_21b6;
						case 301:
							array[5] = (byte)num7;
							num3 = 315;
							continue;
						case 285:
							array[19] = 79;
							num2 = 146;
							goto end_IL_21ba;
						case 278:
							array2[8] = (byte)num5;
							num2 = 144;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 222;
						case 222:
							num4 = 74 + 83;
							BypMbfv5Ob2LFsdGxq();
							num = (RM6B75bnB42drYYcTO() ? 219 : 375);
							goto end_IL_21b6;
						case 262:
							array2 = new byte[16];
							num3 = 299;
							continue;
						case 264:
							array[3] = (byte)num4;
							num2 = 37;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 105;
						case 329:
							array[0] = (byte)num7;
							num3 = 251;
							continue;
						case 376:
							array2[5] = 148;
							num = 94;
							goto end_IL_21b6;
						case 145:
							array2[14] = (byte)num5;
							num2 = 21;
							goto end_IL_21ba;
						case 221:
							array[25] = (byte)num7;
							num = 113;
							goto end_IL_21b6;
						case 217:
							array[4] = 91;
							num2 = 228;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 105;
						case 119:
							array[6] = 69;
							num2 = 289;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 196;
						case 196:
							array[11] = (byte)num7;
							num2 = 153;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 255;
						case 255:
							num5 = 216 - 72;
							num2 = 245;
							if (RM6B75bnB42drYYcTO())
							{
								goto end_IL_21ba;
							}
							goto case 180;
						case 180:
							binaryReader = new BinaryReader((Stream)jnKr7qsoy8rSbCYEQY(cVN3wQ16m1st3lE0ec(typeof(NxeCcbXi414hXVG2Oh).TypeHandle).Assembly, "qvCde1fxkcL95DmYAG.8eSRdCyIog6oLch6Yg"));
							num = 164;
							goto end_IL_21b6;
						case 62:
							array[23] = (byte)num4;
							num2 = 166;
							if (!BypMbfv5Ob2LFsdGxq())
							{
								goto end_IL_21ba;
							}
							goto case 350;
						case 350:
							array2[10] = (byte)num5;
							num2 = 333;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 66;
						case 66:
							array[7] = 8;
							num2 = 381;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 384;
						case 384:
							try
							{
								return (string)meIf6AM6Ien5Udm9Yr(lnADS8wi3gldlnAI0B(), qNrbV59CTv, P_0 + 4, num6);
							}
							catch
							{
							}
							return "";
						case 158:
							rijndaelManaged = new RijndaelManaged();
							num3 = 44;
							continue;
						case 161:
							memoryStream = new MemoryStream();
							num2 = 30;
							if (0 == 0)
							{
								goto end_IL_21ba;
							}
							goto case 195;
						}
						num5 = 59 + 103;
						num = 99;
						goto end_IL_21b6;
						IL_005e:
						num5 = 188 - 62;
						num = 297;
						goto end_IL_21b6;
						IL_0042:
						array2[7] = (byte)num5;
						num2 = 120;
						break;
						IL_002a:
						array[11] = (byte)num4;
						num = 32;
						goto end_IL_21b6;
						continue;
						end_IL_21ba:
						break;
					}
					continue;
					end_IL_21b6:
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[DGJYJAEELS6nLrPJmi(typeof(NxeCcbXi414hXVG2Oh/DGJYJAEELS6nLrPJmi/dvh7td1IeJs4f0G3WC<object>[]))]
		internal static string yGDZJhLEaj(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void tFWZFgr9Jn(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int fDrZlFC54x(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr GB6ZxqwZpN(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void gfTZ0MSEaC()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void NJ7ZgKs3Bf()
		{
			try
			{
				RSACryptoServiceProvider.UseMachineKeyStore = true;
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object cCuZ7I0Zv7(object P_0)
		{
			try
			{
				if (File.Exists(((Assembly)P_0).Location))
				{
					return ((Assembly)P_0).Location;
				}
			}
			catch
			{
			}
			try
			{
				if (File.Exists(((Assembly)P_0).GetName().CodeBase.ToString().Replace("file:///", "")))
				{
					return ((Assembly)P_0).GetName().CodeBase.ToString().Replace("file:///", "");
				}
			}
			catch
			{
			}
			try
			{
				if (File.Exists(P_0.GetType().GetProperty("Location").GetValue(P_0, new object[0])
					.ToString()))
				{
					return P_0.GetType().GetProperty("Location").GetValue(P_0, new object[0])
						.ToString();
				}
			}
			catch
			{
			}
			return "";
		}

		[DllImport("kernel32", EntryPoint = "LoadLibrary")]
		public static extern IntPtr qpBZqgyRHK(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr o79Z8wqR1M(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int AhLZi6a9kI(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int rnAZjWForO(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int cl3ZOGa34Z(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr HoLZXI3gkZ(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int M0GZC8LSLO(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[DGJYJAEELS6nLrPJmi(typeof(NxeCcbXi414hXVG2Oh/DGJYJAEELS6nLrPJmi/dvh7td1IeJs4f0G3WC<object>[]))]
		private static byte[] nKkZEAGyuV(string P_0)
		{
			using FileStream fileStream = new FileStream(P_0, FileMode.Open, FileAccess.Read, FileShare.Read);
			int num = 0;
			long length = fileStream.Length;
			int num2 = (int)length;
			byte[] array = new byte[num2];
			while (num2 > 0)
			{
				int num3 = fileStream.Read(array, num, num2);
				num += num3;
				num2 -= num3;
			}
			return array;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[DGJYJAEELS6nLrPJmi(typeof(NxeCcbXi414hXVG2Oh/DGJYJAEELS6nLrPJmi/dvh7td1IeJs4f0G3WC<object>[]))]
		private static byte[] kERZ1lOPY9(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				14, 16, 10, 168, 10, 4, 205, 248, 114, 150,
				185, 56, 162, 238, 217, 68, 185, 206, 49, 143,
				170, 54, 7, 84, 114, 174, 200, 244, 119, 185,
				66, 167
			};
			rijndael.IV = new byte[16]
			{
				187, 165, 243, 126, 112, 29, 253, 190, 125, 208,
				234, 64, 103, 134, 7, 182
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] TwkZfe3axk()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] vdaZmchBV5()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] WKiZ47sB9x()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] aLsZ2Nyt3o()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] i21Z6AuLYa()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] MhTZnRdXK9()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] D2UZtW4l88()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] rBSZoPUw26()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] zmNZzKtREC()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] fEfbaxK9FA()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public NxeCcbXi414hXVG2Oh()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type cVN3wQ16m1st3lE0ec(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object jnKr7qsoy8rSbCYEQY(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object gZHkPSFV5Xc638Iapm(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void v121xeXPm5iKaEy2tR(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void f3kCM7gyuLBqHWBb07(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long tR7OGj4nAWgokekjTN(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object hsNjYl3d33cfvln9f9(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object B2OXD426J4ytl2STuS(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object mqLnYcOXgYAUALPE7L(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void gQitw9KOT8rYrnnB48(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object ELOc1qHvmswRMKk0Ci(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void DmgQiGZeiaoi9mtNL6(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void WsHH9MQFg73DyPSjyI(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object GGxY4jGxu3rxDvWvBp(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void tgCs6hPhrY3hxGAtbv(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void PI8lOqyIDcjuNFldlH(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int E7Co76LwTtDfSI0B7o(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object lnADS8wi3gldlnAI0B()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object meIf6AM6Ien5Udm9Yr(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool RM6B75bnB42drYYcTO()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool BypMbfv5Ob2LFsdGxq()
		{
			return false;
		}
	}
}
namespace zl7Cv8tqx0Tv1ehO8N
{
	internal class EXoF78nf1V3a45pjv0
	{
		private static bool OHHbuZYoai;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void W2wkaw4z78Yh4()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public EXoF78nf1V3a45pjv0()
		{
		}
	}
}
