using System;
using System.Collections;
using System.Collections.Specialized;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.ComponentModel.Design.Serialization;
using System.Configuration;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Design;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using System.Drawing.Printing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Reflection.Emit;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Security;
using System.Security.Permissions;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using System.Windows.Forms.Design;
using C1.C1PrintDocument;
using C1.C1PrintDocument.ControlPrinters;
using C1.C1PrintDocument.DocEngine.Src;
using C1.Data;
using C1.Util.Localization;
using C1.Win;
using C1.Win.C1FlexGrid.Design;
using C1.Win.C1FlexGrid.Util;
using C1.Win.C1FlexGrid.Util.BaseControls;
using C1.Win.C1FlexGrid.Util.Styles;
using Microsoft.Win32;

[assembly: AllowPartiallyTrustedCallers]
[assembly: AssemblyCopyright("(c) 2002, 2003 ComponentOne LLC")]
[assembly: AssemblyFileVersion("2.1.20034.144")]
[assembly: AssemblyTrademark("C1FlexGrid")]
[assembly: AssemblyProduct("ComponentOne C1FlexGrid")]
[assembly: AssemblyCompany("ComponentOne LLC")]
[assembly: AssemblyDescription("C1FlexGrid control for .NET Windows Forms.")]
[assembly: AssemblyTitle("ComponentOne C1FlexGrid")]
[assembly: AssemblyKeyFile("..\\..\\C1.Win.C1FlexGrid.snk")]
[assembly: 1("23", "ADCF702F-5914-419d-B0BE-8FF50C272BBC")]
[assembly: CLSCompliant(true)]
[assembly: AssemblyKeyName("")]
[assembly: ComVisible(true)]
[assembly: AssemblyDelaySign(false)]
[assembly: 2("21B11D57-9478-420e-A2B2-4C6AAEF98E46")]
[assembly: 5("support.flexgrid.net@componentone.com", "news://news.componentone.com/Component1.public.net.flexgrid", "")]
[assembly: AssemblyVersion("2.1.20031.104")]
namespace C1.Data
{
	public interface IC1GetDataSource
	{
		IC1DataSource GetDataSource();
	}
	public interface IC1DataSource
	{
		void SetBoundControl(object boundControl, string name);

		int GetVirtualSegmentSize();

		void SetVisibleRowCount(int value, string name);

		void BoundControlScrolled();
	}
	public interface IC1ComplexBoundControl
	{
		int GetFirstVisibleRow();

		int GetVisibleRowCount();

		void ScrollToRow(int firstVisibleRow, int rowCount);
	}
	public interface IC1EditableObject
	{
		void RequestModification();
	}
	public class LateBindingIC1DataSource : IC1DataSource
	{
		private object FI;

		private MethodInfo FJ;

		private MethodInfo FK;

		private MethodInfo FL;

		private MethodInfo FM;

		public static LateBindingIC1DataSource GetDataSource(object obj)
		{
			MethodInfo method = obj.GetType().GetMethod("GetDataSource", new Type[0]);
			if ((object)method == null)
			{
				return null;
			}
			object obj2 = method.Invoke(obj, null);
			if (obj2 == null)
			{
				return null;
			}
			LateBindingIC1DataSource lateBindingIC1DataSource = new LateBindingIC1DataSource(obj2);
			if ((object)lateBindingIC1DataSource.FM == null || (object)lateBindingIC1DataSource.FK == null || (object)lateBindingIC1DataSource.FJ == null || (object)lateBindingIC1DataSource.FL == null)
			{
				return null;
			}
			return lateBindingIC1DataSource;
		}

		private LateBindingIC1DataSource(object obj)
		{
			FI = obj;
			FJ = FI.GetType().GetMethod("SetBoundControl");
			FK = FI.GetType().GetMethod("GetVirtualSegmentSize", new Type[0]);
			FL = FI.GetType().GetMethod("SetVisibleRowCount", new Type[2]
			{
				typeof(int),
				typeof(string)
			});
			FM = FI.GetType().GetMethod("BoundControlScrolled", new Type[0]);
		}

		private void 17(object XM, string XN)
		{
			if ((object)FJ != null)
			{
				object[] parameters = new object[2] { XM, XN };
				FJ.Invoke(FI, parameters);
			}
		}

		void IC1DataSource.SetBoundControl(object XM, string XN)
		{
			//ILSpy generated this explicit interface implementation from .override directive in 17
			this.17(XM, XN);
		}

		private int 18()
		{
			if ((object)FK == null)
			{
				return 0;
			}
			return (int)FK.Invoke(FI, null);
		}

		int IC1DataSource.GetVirtualSegmentSize()
		{
			//ILSpy generated this explicit interface implementation from .override directive in 18
			return this.18();
		}

		private void 19(int XO, string XP)
		{
			if ((object)FL != null)
			{
				object[] parameters = new object[2] { XO, XP };
				FL.Invoke(FI, parameters);
			}
		}

		void IC1DataSource.SetVisibleRowCount(int XO, string XP)
		{
			//ILSpy generated this explicit interface implementation from .override directive in 19
			this.19(XO, XP);
		}

		private void 1A()
		{
			if ((object)FM != null)
			{
				FM.Invoke(FI, null);
			}
		}

		void IC1DataSource.BoundControlScrolled()
		{
			//ILSpy generated this explicit interface implementation from .override directive in 1A
			this.1A();
		}
	}
	public class LateBindingIC1ComplexBoundControl : IC1ComplexBoundControl
	{
		private object FN;

		private MethodInfo FO;

		private MethodInfo FP;

		private MethodInfo FQ;

		public static LateBindingIC1ComplexBoundControl NewLateBindingIC1ComplexBoundControl(object obj)
		{
			LateBindingIC1ComplexBoundControl lateBindingIC1ComplexBoundControl = new LateBindingIC1ComplexBoundControl(obj);
			if ((object)lateBindingIC1ComplexBoundControl.FO == null || (object)lateBindingIC1ComplexBoundControl.FP == null || (object)lateBindingIC1ComplexBoundControl.FQ == null)
			{
				return null;
			}
			return lateBindingIC1ComplexBoundControl;
		}

		private LateBindingIC1ComplexBoundControl(object obj)
		{
			FN = obj;
			FO = FN.GetType().GetMethod("GetFirstVisibleRow", new Type[0]);
			FP = FN.GetType().GetMethod("GetVisibleRowCount", new Type[0]);
			FQ = FN.GetType().GetMethod("ScrollToRow", new Type[2]
			{
				typeof(int),
				typeof(int)
			});
		}

		private int 1B()
		{
			if ((object)FO == null)
			{
				return -1;
			}
			return (int)FO.Invoke(FN, null);
		}

		int IC1ComplexBoundControl.GetFirstVisibleRow()
		{
			//ILSpy generated this explicit interface implementation from .override directive in 1B
			return this.1B();
		}

		private int 1C()
		{
			if ((object)FP == null)
			{
				return 0;
			}
			return (int)FP.Invoke(FN, null);
		}

		int IC1ComplexBoundControl.GetVisibleRowCount()
		{
			//ILSpy generated this explicit interface implementation from .override directive in 1C
			return this.1C();
		}

		private void 1D(int XQ, int XR)
		{
			if ((object)FQ != null)
			{
				object[] parameters = new object[2] { XQ, XR };
				FQ.Invoke(FN, parameters);
			}
		}

		void IC1ComplexBoundControl.ScrollToRow(int XQ, int XR)
		{
			//ILSpy generated this explicit interface implementation from .override directive in 1D
			this.1D(XQ, XR);
		}
	}
}
namespace C1.Win.C1FlexGrid.Design
{
	internal class GridAutoFormatForm : Form
	{
		private Button _btnOK;

		private Button _btnCancel;

		private Label _lblPreview;

		private Label _lblFormats;

		private ListBox _lstFormats;

		private C1FlexGrid _fgPreview;

		private Container components = null;

		private CellStyleCollection _styles;

		private ListDictionary _styleTable = new ListDictionary();

		public GridAutoFormatForm(CellStyleCollection styles)
		{
			InitializeComponent();
			F.2F((Control)(object)this, components);
			_styles = styles;
			_styleTable.Clear();
			_styleTable.Add("Default", "");
			_styleTable.Add("Professional 1", "Normal{BackColor:DarkGray;Border:None,1,Black,Both;} Alternate{BackColor:LightGray;} Fixed{BackColor:Control;ForeColor:ControlText;Border:Flat,1,ControlDark,Both;} Highlight{BackColor:Navy;ForeColor:White;}");
			_styleTable.Add("Professional 2", "Normal{BackColor:Silver;Border:Flat,1,White,Both;} Alternate{BackColor:Gainsboro;} Fixed{BackColor:DarkGray;ForeColor:ControlText;Border:None,1,Black,Both;} Highlight{BackColor:DarkSlateBlue;ForeColor:White;}");
			_styleTable.Add("Professional 3", "Normal{BackColor:Gainsboro;Border:None,1,Black,Both;} Alternate{BackColor:LightGray;} Fixed{BackColor:MidnightBlue;ForeColor:White;Border:None,1,Black,Both;} Highlight{BackColor:CadetBlue;ForeColor:White;} EmptyArea{BackColor:Silver;Border:Flat,1,ControlDarkDark,Both;}");
			_styleTable.Add("Professional 4", "Normal{BackColor:LightGray;Border:None,1,Black,Both;} Alternate{BackColor:Lavender;} Fixed{BackColor:MidnightBlue;ForeColor:WhiteSmoke;Border:None,1,Black,Both;} Highlight{BackColor:CadetBlue;ForeColor:WhiteSmoke;} EmptyArea{BackColor:WhiteSmoke;Border:Flat,1,ControlDarkDark,Both;}");
			_styleTable.Add("Classic", "Normal{BackColor:Gainsboro;Border:Flat,1,Silver,Both;} Alternate{BackColor:WhiteSmoke;} Fixed{BackColor:Black;ForeColor:White;Border:None,1,Black,Both;} Highlight{BackColor:Firebrick;ForeColor:White;}\t EmptyArea{BackColor:DarkGray;Border:Flat,1,ControlDarkDark,Both;}");
			_styleTable.Add("Simple", "Normal{BackColor:White;ForeColor:DarkSlateGray;Border:Flat,1,DarkGray,Both;} Alternate{BackColor:White;} Fixed{BackColor:DarkGreen;ForeColor:White;Border:None,1,Black,Both;} Highlight{BackColor:DarkSeaGreen;ForeColor:Black;}");
			_styleTable.Add("Mainframe", "Normal{Font:Lucida Console,8.25pt;BackColor:Ivory;Border:None,1,Black,Both;}\tAlternate{BackColor:DarkSeaGreen;} Fixed{Font:Lucida Console,8.25pt,style=Bold;BackColor:DarkGray;ForeColor:ControlText;Border:Flat,1,ControlDark,Both;} Highlight{Font:Lucida Console,8.25pt,style=Bold;BackColor:Black;ForeColor:White;}");
			_styleTable.Add("Toolbox", "Normal{BackColor:Control;ForeColor:ControlDark;} Fixed{} Highlight{BackColor:PaleGoldenRod;ForeColor:WindowText;Border:Inset,1,Black,Both;} Focus{BackColor:Beige;ForeColor:WindowText;Border:Inset,1,Black,Both;}");
			_styleTable.Add("Colorful 1", "Normal{BackColor:White;ForeColor:DarkSlateBlue;Border:None,1,Black,Both;} Alternate{BackColor:LightGoldenrodYellow;} Fixed{BackColor:Maroon;ForeColor:LightGoldenrodYellow;Border:None,1,Black,Both;} Highlight{BackColor:DarkSlateBlue;ForeColor:GhostWhite;} EmptyArea{BackColor:Gainsboro;Border:Flat,1,ControlDarkDark,Both;}");
			_styleTable.Add("Colorful 2", "Normal{BackColor:GhostWhite;ForeColor:MidnightBlue;Border:Flat,1,RoyalBlue,Both;} Alternate{BackColor:GhostWhite;ForeColor:MidnightBlue;} Fixed{BackColor:MidnightBlue;ForeColor:Lavender;Border:None,1,Black,Both;} Highlight{BackColor:Teal;ForeColor:PaleGreen;} EmptyArea{BackColor:Lavender;Border:Flat,1,ControlDarkDark,Both;}");
			_styleTable.Add("Colorful 3", "Normal{BackColor:OldLace;ForeColor:DarkSlateGray;Border:Flat,1,Tan,Both;} Alternate{BackColor:OldLace;ForeColor:DarkSlateGray;} Fixed{BackColor:Wheat;ForeColor:SaddleBrown;Border:None,1,Black,Both;} Highlight{BackColor:SlateGray;ForeColor:White;} EmptyArea{BackColor:Tan;Border:Flat,1,ControlDarkDark,Both;}");
			_styleTable.Add("Colorful 4", "Normal{BackColor:White;ForeColor:Black;Border:Flat,1,Wheat,Both;} Alternate{BackColor:White;ForeColor:Black;} Fixed{BackColor:CadetBlue;ForeColor:Black;Border:None,1,Black,Both;} Highlight{BackColor:Wheat;ForeColor:DarkSlateBlue;} EmptyArea{BackColor:Ivory;Border:Flat,1,ControlDarkDark,Both;}");
			_styleTable.Add("256 Color 1", "Normal{BackColor:White;ForeColor:Black;Border:Flat,1,Silver,Both;} Alternate{BackColor:Silver;ForeColor:Black;} Fixed{BackColor:Silver;ForeColor:Black;Border:Raised,1,Black,Both;} Highlight{BackColor:Maroon;ForeColor:White;} EmptyArea{BackColor:AppWorkspace;Border:Flat,1,ControlDarkDark,Both;}");
			_styleTable.Add("256 Color 2", "Normal{BackColor:White;ForeColor:Black;Border:Flat,1,Silver,Both;} Alternate{BackColor:White;ForeColor:Black;} Fixed{BackColor:Black;ForeColor:White;Border:None,1,Black,Both;} Highlight{BackColor:Maroon;ForeColor:White;} EmptyArea{BackColor:AppWorkspace;Border:Flat,1,ControlDarkDark,Both;}");
			_lstFormats.Items.Clear();
			foreach (string key in _styleTable.Keys)
			{
				_lstFormats.Items.Add((object)key);
			}
			((ListControl)_lstFormats).SelectedIndex = 0;
			DataTable dataSource = new DataTable
			{
				Locale = CultureInfo.CurrentCulture,
				Columns = 
				{
					{
						"First Name",
						typeof(string)
					},
					{
						"Last Name",
						typeof(string)
					}
				},
				Rows = 
				{
					new object[2] { "Eliza", "Acton" },
					new object[2] { "Lucy", "Aikin" },
					new object[2] { "Elizabeth", "Bath" },
					new object[2] { "Hannah", "Brand" }
				}
			};
			_fgPreview.DataSource = dataSource;
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0011: Unknown result type (might be due to invalid IL or missing references)
			//IL_001b: Expected O, but got Unknown
			//IL_001c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Expected O, but got Unknown
			//IL_0027: Unknown result type (might be due to invalid IL or missing references)
			//IL_0031: Expected O, but got Unknown
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0047: Expected O, but got Unknown
			//IL_0194: Unknown result type (might be due to invalid IL or missing references)
			//IL_019e: Expected O, but got Unknown
			//IL_022c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0236: Expected O, but got Unknown
			//IL_0454: Unknown result type (might be due to invalid IL or missing references)
			//IL_045e: Expected O, but got Unknown
			ResourceManager resourceManager = new ResourceManager(typeof(GridAutoFormatForm));
			_btnOK = new Button();
			_btnCancel = new Button();
			_lblPreview = new Label();
			_lblFormats = new Label();
			_lstFormats = new ListBox();
			_fgPreview = new C1FlexGrid();
			((ISupportInitialize)_fgPreview).BeginInit();
			((Control)this).SuspendLayout();
			((Control)_btnOK).Anchor = (AnchorStyles)9;
			_btnOK.DialogResult = (DialogResult)1;
			((ButtonBase)_btnOK).ImeMode = (ImeMode)0;
			((Control)_btnOK).Location = new Point(234, 182);
			((Control)_btnOK).Name = "_btnOK";
			((Control)_btnOK).Size = new Size(113, 28);
			((Control)_btnOK).TabIndex = 0;
			((Control)_btnOK).Text = "&OK";
			((Control)_btnOK).Click += _btnOK_Click;
			((Control)_btnCancel).Anchor = (AnchorStyles)9;
			_btnCancel.DialogResult = (DialogResult)2;
			((ButtonBase)_btnCancel).ImeMode = (ImeMode)0;
			((Control)_btnCancel).Location = new Point(358, 182);
			((Control)_btnCancel).Name = "_btnCancel";
			((Control)_btnCancel).Size = new Size(115, 28);
			((Control)_btnCancel).TabIndex = 0;
			((Control)_btnCancel).Text = "&Cancel";
			_lblPreview.FlatStyle = (FlatStyle)0;
			((Control)_lblPreview).Font = new Font("Microsoft Sans Serif", 8.25f);
			_lblPreview.ImeMode = (ImeMode)0;
			((Control)_lblPreview).Location = new Point(153, 8);
			((Control)_lblPreview).Name = "_lblPreview";
			((Control)_lblPreview).Size = new Size(322, 22);
			((Control)_lblPreview).TabIndex = 7;
			((Control)_lblPreview).Text = "Preview";
			_lblPreview.TextAlign = (ContentAlignment)16;
			_lblFormats.FlatStyle = (FlatStyle)0;
			((Control)_lblFormats).Font = new Font("Microsoft Sans Serif", 8.25f);
			_lblFormats.ImeMode = (ImeMode)0;
			((Control)_lblFormats).Location = new Point(7, 8);
			((Control)_lblFormats).Name = "_lblFormats";
			((Control)_lblFormats).Size = new Size(139, 22);
			((Control)_lblFormats).TabIndex = 7;
			((Control)_lblFormats).Text = "Formats";
			_lblFormats.TextAlign = (ContentAlignment)16;
			_lstFormats.IntegralHeight = false;
			((Control)_lstFormats).Location = new Point(7, 30);
			((Control)_lstFormats).Name = "_lstFormats";
			((Control)_lstFormats).Size = new Size(139, 144);
			((Control)_lstFormats).TabIndex = 8;
			_lstFormats.SelectedIndexChanged += _lstFormats_SelectedIndexChanged;
			_fgPreview.Cols = new ColumnCollection(5, 1, 0, 0, 0, 80, "0{Width:36;}\t");
			((Control)_fgPreview).Location = new Point(153, 30);
			((Control)_fgPreview).Name = "_fgPreview";
			_fgPreview.Rows.Count = 4;
			_fgPreview.ShowCursor = true;
			((Control)_fgPreview).Size = new Size(322, 144);
			_fgPreview.Styles = new CellStyleCollection("Fixed{BackColor:Control;ForeColor:ControlText;Border:Flat,1,ControlDark,Both;}\tHighlight{BackColor:Highlight;ForeColor:HighlightText;}\tSearch{BackColor:Highlight;ForeColor:HighlightText;}\tFrozen{BackColor:LightBlue;}\tEmptyArea{BackColor:AppWorkspace;Border:Flat,1,ControlDarkDark,Both;}\tGrandTotal{BackColor:Black;ForeColor:White;}\tSubtotal0{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal1{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal2{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal3{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal4{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal5{BackColor:ControlDarkDark;ForeColor:White;}\t");
			((Control)_fgPreview).TabIndex = 9;
			_fgPreview.Tree.LineColor = Color.FromArgb(128, 128, 128);
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).ClientSize = new Size(484, 217);
			((Control)this).Controls.AddRange((Control[])(object)new Control[6]
			{
				_fgPreview,
				(Control)_lstFormats,
				(Control)_btnOK,
				(Control)_btnCancel,
				(Control)_lblPreview,
				(Control)_lblFormats
			});
			((Form)this).FormBorderStyle = (FormBorderStyle)5;
			((Form)this).Icon = (Icon)resourceManager.GetObject("$this.Icon", CultureInfo.InvariantCulture);
			((Control)this).Name = "GridAutoFormatForm";
			((Form)this).StartPosition = (FormStartPosition)4;
			((Control)this).Text = "C1FlexGrid Auto Format";
			((ISupportInitialize)_fgPreview).EndInit();
			((Control)this).ResumeLayout(false);
		}

		private void _lstFormats_SelectedIndexChanged(object sender, EventArgs e)
		{
			string str = _styleTable[((Control)_lstFormats).Text] as string;
			_fgPreview.Styles.Clear();
			_fgPreview.Styles.ParseString(str);
		}

		private void _btnOK_Click(object sender, EventArgs e)
		{
			int num = 16;
			for (int i = 0; i < num; i++)
			{
				_styles[i].Clear();
			}
			string str = _fgPreview.Styles.BuildString(includeEmpty: true);
			_styles.ParseString(str);
		}
	}
	internal class GridColumnEditor : UITypeEditor
	{
		public override UITypeEditorEditStyle GetEditStyle(ITypeDescriptorContext ctx)
		{
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			if (ctx == null || ctx.Instance == null)
			{
				return ((UITypeEditor)this).GetEditStyle(ctx);
			}
			return (UITypeEditorEditStyle)2;
		}

		public override object EditValue(ITypeDescriptorContext ctx, IServiceProvider provider, object value)
		{
			//IL_0064: Unknown result type (might be due to invalid IL or missing references)
			//IL_006a: Expected O, but got Unknown
			//IL_0078: Unknown result type (might be due to invalid IL or missing references)
			//IL_007d: Unknown result type (might be due to invalid IL or missing references)
			//IL_007f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0082: Invalid comparison between Unknown and I4
			if (ctx == null || ctx.Instance == null || provider == null)
			{
				return value;
			}
			C1FlexGridBase c1FlexGridBase = ctx.Instance as C1FlexGridBase;
			if (c1FlexGridBase == null)
			{
				ColumnCollection columnCollection = value as ColumnCollection;
				if (value != null && columnCollection.UE != null && columnCollection.UE.PO != null)
				{
					c1FlexGridBase = columnCollection.UE.PO.Q8;
				}
			}
			if (c1FlexGridBase == null)
			{
				return value;
			}
			IWindowsFormsEditorService val = (IWindowsFormsEditorService)provider.GetService(typeof(IWindowsFormsEditorService));
			if (val == null)
			{
				return value;
			}
			GridColumnEditorForm gridColumnEditorForm = new GridColumnEditorForm(c1FlexGridBase);
			try
			{
				DialogResult val2 = val.ShowDialog((Form)(object)gridColumnEditorForm);
				if ((int)val2 == 1)
				{
					ctx.OnComponentChanging();
					ctx.OnComponentChanged();
				}
			}
			finally
			{
				((IDisposable)gridColumnEditorForm)?.Dispose();
			}
			return value;
		}
	}
	internal class GridDataTypeConverter : TypeListConverter
	{
		private static Type[] _sysTypes = new Type[16]
		{
			Type.GetType("System.Object"),
			Type.GetType("System.String"),
			Type.GetType("System.DateTime"),
			Type.GetType("System.Decimal"),
			Type.GetType("System.Int32"),
			Type.GetType("System.Double"),
			Type.GetType("System.Boolean"),
			Type.GetType("System.Byte"),
			Type.GetType("System.Char"),
			Type.GetType("System.Int16"),
			Type.GetType("System.Int64"),
			Type.GetType("System.SByte"),
			Type.GetType("System.Single"),
			Type.GetType("System.UInt16"),
			Type.GetType("System.UInt32"),
			Type.GetType("System.UInt64")
		};

		public GridDataTypeConverter()
			: base(_sysTypes)
		{
		}

		public override bool CanConvertTo(ITypeDescriptorContext ctx, Type type)
		{
			if ((object)type == typeof(string))
			{
				return true;
			}
			return base.CanConvertTo(ctx, type);
		}

		public override bool CanConvertFrom(ITypeDescriptorContext ctx, Type type)
		{
			if ((object)type == typeof(string))
			{
				return true;
			}
			return base.CanConvertFrom(ctx, type);
		}

		public override object ConvertTo(ITypeDescriptorContext ctx, CultureInfo ci, object obj, Type type)
		{
			if ((object)type == typeof(string))
			{
				if (obj == null)
				{
					obj = typeof(object);
				}
				string text = obj.ToString();
				int num = text.IndexOf('.');
				if (num > -1)
				{
					text = text.Substring(num + 1);
				}
				return text;
			}
			return base.ConvertTo(ctx, ci, obj, type);
		}

		public override object ConvertFrom(ITypeDescriptorContext ctx, CultureInfo ci, object obj)
		{
			if (obj is string)
			{
				string text = (string)obj;
				if (text.IndexOf('.') < 0)
				{
					text = "System." + text;
				}
				return Type.GetType(text);
			}
			if (obj == null)
			{
				return typeof(object);
			}
			return base.ConvertFrom(ctx, ci, obj);
		}
	}
	internal class GridColumnEditorForm : Form
	{
		private Panel panel1;

		private Splitter splitter1;

		private C1FlexGrid _flex;

		private Label lblHelp;

		private IContainer components;

		private PropertyGrid _ppg;

		private ToolBar _toolBar;

		private ToolBarButton _tbCategorized;

		private ToolBarButton _tbHelp;

		private ToolBarButton _tbSep0;

		private ToolBarButton _tbUndoChanges;

		private ToolBarButton _tbSep1;

		private ToolBarButton _tbInsBefore;

		private ToolBarButton _tbInsAfter;

		private ToolBarButton _tbDelete;

		private ToolBarButton _tbSep2;

		private ToolBarButton _tbSameWidth;

		private ToolBarButton _tbWider;

		private ToolBarButton _tbNarrower;

		private ToolBarButton _tbMakeVisible;

		private ToolBarButton _tbSep3;

		private ToolBarButton _tbAlignLeft;

		private ToolBarButton _tbAlignCenter;

		private ToolBarButton _tbAlignRight;

		private ToolBarButton _tbSep4;

		private ToolBarButton _tbAutoSize;

		private ToolBarButton _tbDataRefresh;

		private ImageList _ilToolbar;

		private Button _btnOK;

		private Button _btnCancel;

		private static Brush _brush;

		private C1FlexGridBase _flexUser;

		private int _col1;

		private int _col2;

		private int _cnt;

		private bool _freezeUpdate;

		private string _originalInfo;

		private int _originalCount;

		private int _originalFixed;

		private bool _originalAddNew;

		private bool _originalDelete;

		public GridColumnEditorForm(C1FlexGridBase fg)
		{
			//IL_002b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0035: Expected O, but got Unknown
			InitializeComponent();
			F.2F((Control)(object)this, components);
			if (_brush == null)
			{
				_brush = (Brush)new SolidBrush(Color.FromArgb(40, SystemColors.Highlight));
			}
			_flexUser = fg;
			_originalCount = fg.Cols.Count;
			_originalFixed = fg.Cols.Fixed;
			_originalInfo = fg.Cols.E7(0LS: true);
		}

		private void GridColumnEditorForm_Load(object sender, EventArgs e)
		{
			_tbAutoSize.Pushed = _flexUser.AutoResize;
			bool flag = _flexUser.DataSource != null;
			_tbAutoSize.Enabled = flag;
			_tbDataRefresh.Enabled = flag;
			_tbInsAfter.Enabled = !flag;
			_tbInsBefore.Enabled = !flag;
			_flex.DataSource = _flexUser;
			_originalAddNew = _flex.AllowAddNew;
			_originalDelete = _flex.AllowDelete;
			_flex.AllowAddNew = false;
			_flex.AllowDelete = false;
			UpdateSelection();
		}

		private void GridColumnEditorForm_Closing(object sender, CancelEventArgs e)
		{
			_flex.AllowAddNew = _originalAddNew;
			_flex.AllowDelete = _originalDelete;
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_001c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Expected O, but got Unknown
			//IL_0027: Unknown result type (might be due to invalid IL or missing references)
			//IL_0031: Expected O, but got Unknown
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0047: Expected O, but got Unknown
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			//IL_0052: Expected O, but got Unknown
			//IL_005e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0068: Expected O, but got Unknown
			//IL_0069: Unknown result type (might be due to invalid IL or missing references)
			//IL_0073: Expected O, but got Unknown
			//IL_0074: Unknown result type (might be due to invalid IL or missing references)
			//IL_007e: Expected O, but got Unknown
			//IL_007f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0089: Expected O, but got Unknown
			//IL_008a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0094: Expected O, but got Unknown
			//IL_0095: Unknown result type (might be due to invalid IL or missing references)
			//IL_009f: Expected O, but got Unknown
			//IL_00a0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00aa: Expected O, but got Unknown
			//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b5: Expected O, but got Unknown
			//IL_00b6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c0: Expected O, but got Unknown
			//IL_00c1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00cb: Expected O, but got Unknown
			//IL_00cc: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d6: Expected O, but got Unknown
			//IL_00d7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e1: Expected O, but got Unknown
			//IL_00e2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ec: Expected O, but got Unknown
			//IL_00ed: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f7: Expected O, but got Unknown
			//IL_00f8: Unknown result type (might be due to invalid IL or missing references)
			//IL_0102: Expected O, but got Unknown
			//IL_0103: Unknown result type (might be due to invalid IL or missing references)
			//IL_010d: Expected O, but got Unknown
			//IL_010e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0118: Expected O, but got Unknown
			//IL_0119: Unknown result type (might be due to invalid IL or missing references)
			//IL_0123: Expected O, but got Unknown
			//IL_0124: Unknown result type (might be due to invalid IL or missing references)
			//IL_012e: Expected O, but got Unknown
			//IL_012f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0139: Expected O, but got Unknown
			//IL_013a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0144: Expected O, but got Unknown
			//IL_014b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0155: Expected O, but got Unknown
			//IL_0156: Unknown result type (might be due to invalid IL or missing references)
			//IL_0160: Expected O, but got Unknown
			//IL_070d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0717: Expected O, but got Unknown
			//IL_0957: Unknown result type (might be due to invalid IL or missing references)
			//IL_0961: Expected O, but got Unknown
			//IL_0a5e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0a68: Expected O, but got Unknown
			components = new Container();
			ResourceManager resourceManager = new ResourceManager(typeof(GridColumnEditorForm));
			panel1 = new Panel();
			lblHelp = new Label();
			_btnOK = new Button();
			_btnCancel = new Button();
			_ppg = new PropertyGrid();
			_flex = new C1FlexGrid();
			_toolBar = new ToolBar();
			_tbCategorized = new ToolBarButton();
			_tbHelp = new ToolBarButton();
			_tbSep0 = new ToolBarButton();
			_tbUndoChanges = new ToolBarButton();
			_tbSep1 = new ToolBarButton();
			_tbInsBefore = new ToolBarButton();
			_tbInsAfter = new ToolBarButton();
			_tbDelete = new ToolBarButton();
			_tbSep2 = new ToolBarButton();
			_tbSameWidth = new ToolBarButton();
			_tbWider = new ToolBarButton();
			_tbNarrower = new ToolBarButton();
			_tbMakeVisible = new ToolBarButton();
			_tbSep3 = new ToolBarButton();
			_tbAlignLeft = new ToolBarButton();
			_tbAlignCenter = new ToolBarButton();
			_tbAlignRight = new ToolBarButton();
			_tbSep4 = new ToolBarButton();
			_tbAutoSize = new ToolBarButton();
			_tbDataRefresh = new ToolBarButton();
			_ilToolbar = new ImageList(components);
			splitter1 = new Splitter();
			((Control)panel1).SuspendLayout();
			((ISupportInitialize)_flex).BeginInit();
			((Control)this).SuspendLayout();
			((Control)panel1).Controls.AddRange((Control[])(object)new Control[3]
			{
				(Control)lblHelp,
				(Control)_btnOK,
				(Control)_btnCancel
			});
			((Control)panel1).Dock = (DockStyle)2;
			((Control)panel1).Location = new Point(0, 349);
			((Control)panel1).Name = "panel1";
			((Control)panel1).Size = new Size(598, 32);
			((Control)panel1).TabIndex = 1;
			((Control)lblHelp).Anchor = (AnchorStyles)13;
			lblHelp.ImeMode = (ImeMode)0;
			((Control)lblHelp).Location = new Point(4, 6);
			((Control)lblHelp).Name = "lblHelp";
			((Control)lblHelp).Size = new Size(376, 20);
			((Control)lblHelp).TabIndex = 1;
			lblHelp.TextAlign = (ContentAlignment)16;
			((Control)_btnOK).Anchor = (AnchorStyles)9;
			_btnOK.DialogResult = (DialogResult)1;
			((ButtonBase)_btnOK).ImeMode = (ImeMode)0;
			((Control)_btnOK).Location = new Point(392, 4);
			((Control)_btnOK).Name = "_btnOK";
			((Control)_btnOK).Size = new Size(96, 25);
			((Control)_btnOK).TabIndex = 0;
			((Control)_btnOK).Text = "OK";
			((Control)_btnCancel).Anchor = (AnchorStyles)9;
			_btnCancel.DialogResult = (DialogResult)2;
			((ButtonBase)_btnCancel).ImeMode = (ImeMode)0;
			((Control)_btnCancel).Location = new Point(496, 4);
			((Control)_btnCancel).Name = "_btnCancel";
			((Control)_btnCancel).Size = new Size(96, 25);
			((Control)_btnCancel).TabIndex = 0;
			((Control)_btnCancel).Text = "Cancel";
			((Control)_btnCancel).Click += btnCancel_Click;
			_ppg.CommandsVisibleIfAvailable = true;
			((Control)_ppg).Dock = (DockStyle)3;
			_ppg.HelpVisible = false;
			_ppg.LargeButtons = false;
			_ppg.LineColor = SystemColors.ScrollBar;
			((Control)_ppg).Location = new Point(0, 25);
			((Control)_ppg).Name = "_ppg";
			_ppg.PropertySort = (PropertySort)1;
			((Control)_ppg).Size = new Size(160, 324);
			((Control)_ppg).TabIndex = 5;
			((Control)_ppg).Text = "ppg";
			_ppg.ToolbarVisible = false;
			_ppg.ViewBackColor = SystemColors.Window;
			_ppg.ViewForeColor = SystemColors.WindowText;
			_flex.AllowEditing = false;
			_flex.AllowSorting = AllowSortingEnum.None;
			_flex.AutoResize = false;
			((Control)_flex).BackColor = SystemColors.Window;
			_flex.Cols = new ColumnCollection(2, 1, 0, 0, 0, 80, "");
			((Control)_flex).Dock = (DockStyle)5;
			_flex.DrawMode = DrawModeEnum.OwnerDraw;
			((Control)_flex).Location = new Point(165, 25);
			((Control)_flex).Name = "_flex";
			_flex.Rows.Count = 2;
			((Control)_flex).Size = new Size(433, 324);
			_flex.Styles = new CellStyleCollection("Fixed{BackColor:Control;ForeColor:ControlText;Border:Flat,1,ControlDark,Both;}\tHighlight{BackColor:Highlight;ForeColor:HighlightText;}\tSearch{BackColor:Highlight;ForeColor:HighlightText;}\tFrozen{BackColor:LightBlue;}\tEmptyArea{BackColor:AppWorkspace;Border:Flat,1,ControlDarkDark,Both;}\tGrandTotal{BackColor:Black;ForeColor:White;}\tSubtotal0{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal1{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal2{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal3{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal4{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal5{BackColor:ControlDarkDark;ForeColor:White;}\t");
			((Control)_flex).TabIndex = 3;
			_flex.Tree.LineColor = Color.FromArgb(128, 128, 128);
			_flex.BeforeMouseDown += _flex_BeforeMouseDown;
			_flex.SelChange += _flex_SelChange;
			_flex.OwnerDrawCell += _flex_OwnerDrawCell;
			((Control)_flex).DoubleClick += _flex_DoubleClick;
			_toolBar.Appearance = (ToolBarAppearance)1;
			_toolBar.Buttons.AddRange((ToolBarButton[])(object)new ToolBarButton[20]
			{
				_tbCategorized, _tbHelp, _tbSep0, _tbUndoChanges, _tbSep1, _tbInsBefore, _tbInsAfter, _tbDelete, _tbSep2, _tbSameWidth,
				_tbWider, _tbNarrower, _tbMakeVisible, _tbSep3, _tbAlignLeft, _tbAlignCenter, _tbAlignRight, _tbSep4, _tbAutoSize, _tbDataRefresh
			});
			_toolBar.DropDownArrows = true;
			_toolBar.ImageList = _ilToolbar;
			_toolBar.ImeMode = (ImeMode)0;
			((Control)_toolBar).Name = "_toolBar";
			_toolBar.ShowToolTips = true;
			((Control)_toolBar).Size = new Size(598, 25);
			((Control)_toolBar).TabIndex = 4;
			_toolBar.TextAlign = (ToolBarTextAlign)1;
			_toolBar.ButtonClick += new ToolBarButtonClickEventHandler(toolBar_ButtonClick);
			_tbCategorized.ImageIndex = 12;
			_tbCategorized.Style = (ToolBarButtonStyle)2;
			_tbCategorized.ToolTipText = "Group properties by category";
			_tbHelp.ImageIndex = 11;
			_tbHelp.Style = (ToolBarButtonStyle)2;
			_tbHelp.ToolTipText = "Show property help";
			_tbSep0.Style = (ToolBarButtonStyle)3;
			_tbUndoChanges.ImageIndex = 10;
			_tbUndoChanges.ToolTipText = "Undo all changes";
			_tbSep1.Style = (ToolBarButtonStyle)3;
			_tbInsBefore.ImageIndex = 0;
			_tbInsBefore.ToolTipText = "Insert columns before selection";
			_tbInsAfter.ImageIndex = 1;
			_tbInsAfter.ToolTipText = "Insert columns after selection";
			_tbDelete.ImageIndex = 2;
			_tbDelete.ToolTipText = "Delete columns";
			_tbSep2.Style = (ToolBarButtonStyle)3;
			_tbSameWidth.ImageIndex = 6;
			_tbSameWidth.ToolTipText = "Make selected columns the same width";
			_tbWider.ImageIndex = 7;
			_tbWider.ToolTipText = "Make selected columns wider";
			_tbNarrower.ImageIndex = 8;
			_tbNarrower.ToolTipText = "Make selected columns narrower";
			_tbMakeVisible.ImageIndex = 9;
			_tbMakeVisible.ToolTipText = "Make all columns visible";
			_tbSep3.Style = (ToolBarButtonStyle)3;
			_tbAlignLeft.ImageIndex = 3;
			_tbAlignLeft.ToolTipText = "Align left";
			_tbAlignCenter.ImageIndex = 4;
			_tbAlignCenter.ToolTipText = "Align center";
			_tbAlignRight.ImageIndex = 5;
			_tbAlignRight.ToolTipText = "Align right";
			_tbSep4.Style = (ToolBarButtonStyle)3;
			_tbAutoSize.ImageIndex = 13;
			_tbAutoSize.Style = (ToolBarButtonStyle)2;
			_tbAutoSize.ToolTipText = "Adjust column widths after loading data";
			_tbDataRefresh.ImageIndex = 14;
			_tbDataRefresh.ToolTipText = "Reload all columns from data source";
			_ilToolbar.ColorDepth = (ColorDepth)8;
			_ilToolbar.ImageSize = new Size(16, 16);
			_ilToolbar.ImageStream = (ImageListStreamer)resourceManager.GetObject("_ilToolbar.ImageStream", CultureInfo.InvariantCulture);
			_ilToolbar.TransparentColor = Color.Silver;
			splitter1.ImeMode = (ImeMode)0;
			((Control)splitter1).Location = new Point(160, 25);
			((Control)splitter1).Name = "splitter1";
			((Control)splitter1).Size = new Size(5, 324);
			((Control)splitter1).TabIndex = 2;
			splitter1.TabStop = false;
			((Form)this).AcceptButton = (IButtonControl)(object)_btnOK;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).CancelButton = (IButtonControl)(object)_btnCancel;
			((Form)this).ClientSize = new Size(598, 381);
			((Control)this).Controls.AddRange((Control[])(object)new Control[5]
			{
				_flex,
				(Control)splitter1,
				(Control)_ppg,
				(Control)_toolBar,
				(Control)panel1
			});
			((Form)this).Icon = (Icon)resourceManager.GetObject("$this.Icon", CultureInfo.InvariantCulture);
			((Control)this).Name = "GridColumnEditorForm";
			((Form)this).StartPosition = (FormStartPosition)4;
			((Control)this).Text = "C1FlexGrid Column Editor";
			((Form)this).Load += GridColumnEditorForm_Load;
			((Form)this).Closing += GridColumnEditorForm_Closing;
			((Control)panel1).ResumeLayout(false);
			((ISupportInitialize)_flex).EndInit();
			((Control)this).ResumeLayout(false);
		}

		private void UpdateSelection()
		{
			CellRange selection = _flex.Selection;
			bool flag = selection.c1 > -1 && selection.c2 > -1;
			_col1 = selection.c1;
			_col2 = selection.c2;
			_cnt = (flag ? (selection.c2 - selection.c1 + 1) : 0);
			((Control)lblHelp).Text = ((_cnt == 0) ? F.2E("No columns selected") : ((_cnt == 1) ? string.Format(CultureInfo.CurrentCulture, F.2E("Column {0} selected."), new object[1] { _col1 }) : string.Format(CultureInfo.CurrentCulture, F.2E("Columns {0}-{1} selected ({2} cols)."), new object[3] { _col1, _col2, _cnt })));
			object[] array = null;
			if (_cnt > 0)
			{
				array = new object[checked((uint)_cnt)];
				for (int i = 0; i < _cnt; i++)
				{
					array[i] = _flex.Cols[_col1 + i];
				}
			}
			_ppg.SelectedObjects = array;
		}

		private void Undo()
		{
			ColumnCollection cols = _flex.Cols;
			cols.Count = _originalCount;
			cols.Fixed = _originalFixed;
			cols.E8(_originalInfo);
		}

		private void _flex_SelChange(object sender, EventArgs e)
		{
			if (!_freezeUpdate)
			{
				UpdateSelection();
				((Control)_flex).Invalidate();
			}
		}

		private void toolBar_ButtonClick(object sender, ToolBarButtonClickEventArgs e)
		{
			_freezeUpdate = true;
			HandleButton(e.Button);
			_freezeUpdate = false;
			UpdateSelection();
			((Control)_ppg).Refresh();
		}

		private void HandleButton(ToolBarButton btn)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_000a: Unknown result type (might be due to invalid IL or missing references)
			//IL_000c: Invalid comparison between Unknown and I4
			bool flag = (Control.ModifierKeys & 0x10000) != 0;
			if (btn == _tbCategorized)
			{
				_ppg.PropertySort = (PropertySort)((!btn.Pushed) ? 1 : 2);
			}
			else if (btn == _tbHelp)
			{
				_ppg.HelpVisible = btn.Pushed;
			}
			else if (btn == _tbInsBefore)
			{
				int col = _col1;
				for (int i = 0; i < _cnt; i++)
				{
					_flex.Cols.Insert(_col1);
				}
				_flex.Col = col;
			}
			else if (btn == _tbInsAfter)
			{
				int col2 = _col2 + 1;
				for (int j = 0; j < _cnt; j++)
				{
					_flex.Cols.Insert(_col2 + 1);
				}
				_flex.Col = col2;
			}
			else if (btn == _tbDelete)
			{
				int num = _col1;
				for (int k = 0; k < _cnt; k++)
				{
					_flex.Cols.Remove(num);
				}
				if (num >= _flex.Cols.Count)
				{
					num = _flex.Cols.Count - 1;
				}
				if (num >= 0)
				{
					_flex.Col = num;
				}
			}
			else if (btn == _tbSameWidth)
			{
				int width = ((_cnt == 0 || flag) ? (-1) : _flex.Cols[_col1].Width);
				for (int l = 0; l < _cnt; l++)
				{
					_flex.Cols[_col1 + l].Width = width;
				}
			}
			else if (btn == _tbWider)
			{
				int width2 = ((_cnt == 0 || flag) ? (-1) : (_flex.Cols[_col1].WidthDisplay + 1));
				for (int m = 0; m < _cnt; m++)
				{
					_flex.Cols[_col1 + m].Width = width2;
				}
			}
			else if (btn == _tbNarrower)
			{
				int num2 = ((_cnt == 0 || flag) ? (-1) : (_flex.Cols[_col1].WidthDisplay - 1));
				if (num2 != 0)
				{
					for (int n = 0; n < _cnt; n++)
					{
						_flex.Cols[_col1 + n].Width = num2;
					}
				}
			}
			else if (btn == _tbMakeVisible)
			{
				for (int num3 = 0; num3 < _flex.Cols.Count; num3++)
				{
					_flex.Cols[num3].Visible = true;
				}
			}
			else if (btn == _tbAlignLeft)
			{
				for (int num4 = 0; num4 < _cnt; num4++)
				{
					_flex.Cols[_col1 + num4].TextAlign = TextAlignEnum.LeftCenter;
					if (flag)
					{
						_flex.Cols[_col1 + num4].TextAlignFixed = TextAlignEnum.LeftCenter;
					}
				}
			}
			else if (btn == _tbAlignCenter)
			{
				for (int num5 = 0; num5 < _cnt; num5++)
				{
					_flex.Cols[_col1 + num5].TextAlign = TextAlignEnum.CenterCenter;
					if (flag)
					{
						_flex.Cols[_col1 + num5].TextAlignFixed = TextAlignEnum.CenterCenter;
					}
				}
			}
			else if (btn == _tbAlignRight)
			{
				for (int num6 = 0; num6 < _cnt; num6++)
				{
					_flex.Cols[_col1 + num6].TextAlign = TextAlignEnum.RightCenter;
					if (flag)
					{
						_flex.Cols[_col1 + num6].TextAlignFixed = TextAlignEnum.RightCenter;
					}
				}
			}
			else if (btn == _tbUndoChanges)
			{
				Undo();
			}
			else
			{
				if (btn == _tbAutoSize)
				{
					_flexUser.AutoResize = btn.Pushed;
				}
				if (btn == _tbDataRefresh)
				{
					object dataSource = _flexUser.DataSource;
					_flexUser.DataSource = null;
					_flexUser.DataSource = dataSource;
				}
			}
		}

		private void _flex_OwnerDrawCell(object sender, OwnerDrawCellEventArgs e)
		{
			e.DrawCell();
			if (e.Row < _flex.Rows.Fixed && e.Col >= _col1 && e.Col <= _col2)
			{
				e.Graphics.FillRectangle(_brush, e.Bounds);
			}
		}

		private void _flex_DoubleClick(object sender, EventArgs e)
		{
			int mouseRow = _flex.MouseRow;
			int mouseCol = _flex.MouseCol;
			if (mouseRow == 0 && mouseCol > -1 && _flex.Rows.Fixed > 0)
			{
				Rectangle cellRect = _flex.GetCellRect(mouseRow, mouseCol, show: true);
				cellRect.Inflate(-5, 0);
				Point pt = ((Control)_flex).PointToClient(Control.MousePosition);
				if (cellRect.Contains(pt))
				{
					_flex.StartEditing(mouseRow, mouseCol);
				}
			}
		}

		private void _flex_BeforeMouseDown(object sender, BeforeMouseDownEventArgs e)
		{
			//IL_0023: Unknown result type (might be due to invalid IL or missing references)
			//IL_002d: Unknown result type (might be due to invalid IL or missing references)
			//IL_002f: Invalid comparison between Unknown and I4
			HitTestInfo hitTestInfo = _flex.HitTest(e.X, e.Y);
			if (hitTestInfo.Type == HitTestTypeEnum.ColumnHeader)
			{
				if ((Control.ModifierKeys & 0x10000) != 0)
				{
					_flex.Select(-1, _flex.Col, -1, hitTestInfo.Column, show: true);
				}
				else
				{
					_flex.Select(-1, hitTestInfo.Column, show: true);
				}
				if (hitTestInfo.Column < _flex.Cols.Fixed)
				{
					e.Cancel = true;
				}
			}
		}

		private void btnCancel_Click(object sender, EventArgs e)
		{
			Undo();
		}
	}
	internal class GridDesigner : ControlDesigner
	{
		public override void Initialize(IComponent component)
		{
			((ControlDesigner)this).Initialize(component);
			((ComponentDesigner)this).Verbs.Add(new DesignerVerb(F.2E("About C1FlexGrid..."), ShowAboutBox));
			((ComponentDesigner)this).Verbs.Add(new DesignerVerb(F.2E("Edit Styles..."), EditStyles));
			((ComponentDesigner)this).Verbs.Add(new DesignerVerb(F.2E("Edit Columns..."), EditColumns));
		}

		private void ShowAboutBox(object sender, EventArgs e)
		{
			ProviderInfo.ShowAboutBox(((ControlDesigner)this).Control);
		}

		private void EditStyles(object sender, EventArgs e)
		{
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0023: Unknown result type (might be due to invalid IL or missing references)
			//IL_0025: Invalid comparison between Unknown and I4
			if (!(((ControlDesigner)this).Control is C1FlexGridBase c1FlexGridBase))
			{
				return;
			}
			GridStyleEditorForm gridStyleEditorForm = new GridStyleEditorForm(c1FlexGridBase.Styles);
			try
			{
				DialogResult val = ((Form)gridStyleEditorForm).ShowDialog();
				if ((int)val == 1)
				{
					IComponentChangeService componentChangeService = (IComponentChangeService)((Component)(object)c1FlexGridBase).Site.GetService(typeof(IComponentChangeService));
					if (componentChangeService != null)
					{
						componentChangeService.OnComponentChanging(c1FlexGridBase, null);
						componentChangeService.OnComponentChanged(c1FlexGridBase, null, null, null);
					}
				}
			}
			finally
			{
				((IDisposable)gridStyleEditorForm)?.Dispose();
			}
		}

		private void EditColumns(object sender, EventArgs e)
		{
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0020: Invalid comparison between Unknown and I4
			if (!(((ControlDesigner)this).Control is C1FlexGridBase c1FlexGridBase))
			{
				return;
			}
			GridColumnEditorForm gridColumnEditorForm = new GridColumnEditorForm(c1FlexGridBase);
			try
			{
				DialogResult val = ((Form)gridColumnEditorForm).ShowDialog();
				if ((int)val == 1)
				{
					IComponentChangeService componentChangeService = (IComponentChangeService)((Component)(object)c1FlexGridBase).Site.GetService(typeof(IComponentChangeService));
					if (componentChangeService != null)
					{
						componentChangeService.OnComponentChanging(c1FlexGridBase, null);
						componentChangeService.OnComponentChanged(c1FlexGridBase, null, null, null);
					}
				}
			}
			finally
			{
				((IDisposable)gridColumnEditorForm)?.Dispose();
			}
		}
	}
	internal class GridStyleConverter : ExpandableObjectConverter
	{
		public override bool CanConvertTo(ITypeDescriptorContext context, Type dstType)
		{
			if ((object)dstType == typeof(InstanceDescriptor))
			{
				return true;
			}
			return base.CanConvertTo(context, dstType);
		}

		public override object ConvertTo(ITypeDescriptorContext context, CultureInfo culture, object value, Type dstType)
		{
			if ((object)dstType == null)
			{
				throw new ArgumentNullException("dstType");
			}
			if ((object)dstType == typeof(InstanceDescriptor))
			{
				Type[] types = new Type[1] { typeof(string) };
				ConstructorInfo constructor = typeof(CellStyleCollection).GetConstructor(types);
				if (!(value is CellStyleCollection cellStyleCollection))
				{
					return new InstanceDescriptor(constructor, new object[1] { "" });
				}
				return new InstanceDescriptor(constructor, new object[1] { cellStyleCollection.BuildString(includeEmpty: false) });
			}
			return base.ConvertTo(context, culture, value, dstType);
		}
	}
	internal class GridStyleEditor : UITypeEditor
	{
		public override UITypeEditorEditStyle GetEditStyle(ITypeDescriptorContext context)
		{
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			if (context == null || context.Instance == null)
			{
				return ((UITypeEditor)this).GetEditStyle(context);
			}
			return (UITypeEditorEditStyle)2;
		}

		public override object EditValue(ITypeDescriptorContext context, IServiceProvider provider, object value)
		{
			//IL_0020: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Expected O, but got Unknown
			//IL_0040: Unknown result type (might be due to invalid IL or missing references)
			//IL_0045: Unknown result type (might be due to invalid IL or missing references)
			//IL_0046: Unknown result type (might be due to invalid IL or missing references)
			//IL_0048: Invalid comparison between Unknown and I4
			if (context == null || context.Instance == null || provider == null)
			{
				return value;
			}
			IWindowsFormsEditorService val = (IWindowsFormsEditorService)provider.GetService(typeof(IWindowsFormsEditorService));
			if (val == null)
			{
				return value;
			}
			if (!(value is CellStyleCollection cellStyleCollection))
			{
				return value;
			}
			GridStyleEditorForm gridStyleEditorForm = new GridStyleEditorForm(cellStyleCollection);
			try
			{
				DialogResult val2 = val.ShowDialog((Form)(object)gridStyleEditorForm);
				if ((int)val2 == 1)
				{
					context.OnComponentChanging();
					context.OnComponentChanged();
				}
			}
			finally
			{
				((IDisposable)gridStyleEditorForm)?.Dispose();
			}
			return cellStyleCollection;
		}
	}
	internal class GridStyleEditorForm : Form
	{
		private Panel _panel;

		private Button _btnOK;

		private Button _btnCancel;

		private GroupBox _gBox;

		private Button _btnAdd;

		private Button _btnRemove;

		private Button _btnClear;

		private Button _btnAutoFormat;

		private Label _lblStyleName;

		private PropertyGrid _propGrid;

		private C1FlexGrid _fgStyleList;

		private CellStyleCollection _styles;

		private CellStyle _currentStyle;

		private int _builtInCount;

		private string _undoInfo;

		public GridStyleEditorForm(CellStyleCollection styles)
		{
			InitializeComponent();
			F.2F((Control)(object)this, null);
			_styles = styles;
			_undoInfo = styles.BuildString(includeEmpty: true);
		}

		protected override void Dispose(bool disposing)
		{
			((Form)this).Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0011: Unknown result type (might be due to invalid IL or missing references)
			//IL_001b: Expected O, but got Unknown
			//IL_001c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Expected O, but got Unknown
			//IL_0027: Unknown result type (might be due to invalid IL or missing references)
			//IL_0031: Expected O, but got Unknown
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0047: Expected O, but got Unknown
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			//IL_0052: Expected O, but got Unknown
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_005d: Expected O, but got Unknown
			//IL_005e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0068: Expected O, but got Unknown
			//IL_0069: Unknown result type (might be due to invalid IL or missing references)
			//IL_0073: Expected O, but got Unknown
			//IL_007f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0089: Expected O, but got Unknown
			//IL_021d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0227: Expected O, but got Unknown
			//IL_07b7: Unknown result type (might be due to invalid IL or missing references)
			//IL_07c1: Expected O, but got Unknown
			ResourceManager resourceManager = new ResourceManager(typeof(GridStyleEditorForm));
			_btnClear = new Button();
			_gBox = new GroupBox();
			_btnOK = new Button();
			_lblStyleName = new Label();
			_btnRemove = new Button();
			_propGrid = new PropertyGrid();
			_panel = new Panel();
			_btnAutoFormat = new Button();
			_btnCancel = new Button();
			_fgStyleList = new C1FlexGrid();
			_btnAdd = new Button();
			((Control)_panel).SuspendLayout();
			((ISupportInitialize)_fgStyleList).BeginInit();
			((Control)this).SuspendLayout();
			((ButtonBase)_btnClear).ImeMode = (ImeMode)0;
			((Control)_btnClear).Location = new Point(167, 336);
			((Control)_btnClear).Name = "_btnClear";
			((Control)_btnClear).TabIndex = 4;
			((Control)_btnClear).Text = "Clear";
			((Control)_btnClear).Click += btnClear_Click;
			((Control)_gBox).Dock = (DockStyle)2;
			((Control)_gBox).Location = new Point(0, 373);
			((Control)_gBox).Name = "_gBox";
			((Control)_gBox).Size = new Size(506, 2);
			((Control)_gBox).TabIndex = 1;
			_gBox.TabStop = false;
			((Control)_btnOK).Anchor = (AnchorStyles)9;
			((ButtonBase)_btnOK).ImeMode = (ImeMode)0;
			((Control)_btnOK).Location = new Point(306, 4);
			((Control)_btnOK).Name = "_btnOK";
			((Control)_btnOK).Size = new Size(92, 23);
			((Control)_btnOK).TabIndex = 0;
			((Control)_btnOK).Text = "&OK";
			((Control)_btnOK).Click += btnClose_Click;
			((Control)_lblStyleName).Anchor = (AnchorStyles)13;
			_lblStyleName.FlatStyle = (FlatStyle)0;
			((Control)_lblStyleName).Font = new Font("Microsoft Sans Serif", 8.25f);
			_lblStyleName.ImeMode = (ImeMode)0;
			((Control)_lblStyleName).Location = new Point(252, 4);
			((Control)_lblStyleName).Name = "_lblStyleName";
			((Control)_lblStyleName).Size = new Size(245, 23);
			((Control)_lblStyleName).TabIndex = 7;
			((Control)_lblStyleName).Text = "Current Style";
			_lblStyleName.TextAlign = (ContentAlignment)16;
			((ButtonBase)_btnRemove).ImeMode = (ImeMode)0;
			((Control)_btnRemove).Location = new Point(86, 336);
			((Control)_btnRemove).Name = "_btnRemove";
			((Control)_btnRemove).TabIndex = 4;
			((Control)_btnRemove).Text = "Remove";
			((Control)_btnRemove).Click += btnRemove_Click;
			((Control)_propGrid).Anchor = (AnchorStyles)13;
			_propGrid.CommandsVisibleIfAvailable = true;
			_propGrid.LargeButtons = false;
			_propGrid.LineColor = SystemColors.ScrollBar;
			((Control)_propGrid).Location = new Point(248, 28);
			((Control)_propGrid).Name = "_propGrid";
			_propGrid.PropertySort = (PropertySort)1;
			((Control)_propGrid).Size = new Size(249, 332);
			((Control)_propGrid).TabIndex = 6;
			((Control)_propGrid).Text = "_propGrid";
			_propGrid.ToolbarVisible = false;
			_propGrid.ViewBackColor = SystemColors.Window;
			_propGrid.ViewForeColor = SystemColors.WindowText;
			((Control)_panel).Controls.AddRange((Control[])(object)new Control[3]
			{
				(Control)_btnAutoFormat,
				(Control)_btnOK,
				(Control)_btnCancel
			});
			((Control)_panel).Dock = (DockStyle)2;
			((Control)_panel).Location = new Point(0, 375);
			((Control)_panel).Name = "_panel";
			((Control)_panel).Size = new Size(506, 32);
			((Control)_panel).TabIndex = 0;
			((ButtonBase)_btnAutoFormat).ImeMode = (ImeMode)0;
			((Control)_btnAutoFormat).Location = new Point(8, 4);
			((Control)_btnAutoFormat).Name = "_btnAutoFormat";
			((Control)_btnAutoFormat).Size = new Size(234, 23);
			((Control)_btnAutoFormat).TabIndex = 1;
			((Control)_btnAutoFormat).Text = "AutoFormat...";
			((Control)_btnAutoFormat).Click += btnAutoFormat_Click;
			((Control)_btnCancel).Anchor = (AnchorStyles)9;
			((ButtonBase)_btnCancel).ImeMode = (ImeMode)0;
			((Control)_btnCancel).Location = new Point(406, 4);
			((Control)_btnCancel).Name = "_btnCancel";
			((Control)_btnCancel).Size = new Size(92, 23);
			((Control)_btnCancel).TabIndex = 0;
			((Control)_btnCancel).Text = "&Cancel";
			((Control)_btnCancel).Click += btnClose_Click;
			_fgStyleList.BorderStyle = C1.Win.C1FlexGrid.Util.BaseControls.BorderStyleEnum.Light3D;
			_fgStyleList.Cols = new ColumnCollection(1, 0, 0, 0, 0, 80, "");
			_fgStyleList.ExtendLastCol = true;
			_fgStyleList.FocusRect = FocusRectEnum.None;
			((Control)_fgStyleList).Location = new Point(5, 4);
			((Control)_fgStyleList).Name = "_fgStyleList";
			_fgStyleList.Rows.Count = 0;
			_fgStyleList.Rows.Fixed = 0;
			_fgStyleList.SelectionMode = SelectionModeEnum.Cell;
			((Control)_fgStyleList).Size = new Size(236, 324);
			_fgStyleList.Styles = new CellStyleCollection("Normal{Border:None,1,Black,Both;}\tFixed{Font:Microsoft Sans Serif, 8.25pt, style=Bold;BackColor:Control;ForeColor:ControlText;Border:Flat,1,ControlDark,Both;}\tHighlight{BackColor:Highlight;ForeColor:HighlightText;}\tSearch{BackColor:Highlight;ForeColor:HighlightText;}\tFrozen{BackColor:LightBlue;}\tEmptyArea{BackColor:AppWorkspace;Border:Flat,1,ControlDarkDark,Both;}\tGrandTotal{BackColor:Black;ForeColor:White;}\tSubtotal0{BackColor:Control;ForeColor:ControlText;}\tSubtotal1{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal2{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal3{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal4{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal5{BackColor:ControlDarkDark;ForeColor:White;}\t");
			((Control)_fgStyleList).TabIndex = 5;
			_fgStyleList.Tree.Column = 0;
			_fgStyleList.Tree.LineColor = Color.FromArgb(128, 128, 128);
			_fgStyleList.Tree.Style = TreeStyleFlags.Symbols;
			_fgStyleList.SelChange += fgStyleList_SelChange;
			_fgStyleList.StartEdit += fgStyleList_StartEdit;
			_fgStyleList.BeforeSelChange += fgStyleList_BeforeSelChange;
			_fgStyleList.AfterEdit += fgStyleList_AfterEdit;
			((ButtonBase)_btnAdd).ImeMode = (ImeMode)0;
			((Control)_btnAdd).Location = new Point(5, 336);
			((Control)_btnAdd).Name = "_btnAdd";
			((Control)_btnAdd).TabIndex = 4;
			((Control)_btnAdd).Text = "Add";
			((Control)_btnAdd).Click += btnAdd_Click;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).ClientSize = new Size(506, 407);
			((Control)this).Controls.AddRange((Control[])(object)new Control[8]
			{
				(Control)_lblStyleName,
				(Control)_propGrid,
				_fgStyleList,
				(Control)_btnAdd,
				(Control)_gBox,
				(Control)_panel,
				(Control)_btnRemove,
				(Control)_btnClear
			});
			((Form)this).FormBorderStyle = (FormBorderStyle)3;
			((Form)this).Icon = (Icon)resourceManager.GetObject("$this.Icon", CultureInfo.InvariantCulture);
			((Control)this).Name = "GridStyleEditorForm";
			((Form)this).StartPosition = (FormStartPosition)4;
			((Control)this).Text = "C1FlexGrid Style Editor";
			((Form)this).Load += GridStyleEditorForm_Load;
			((Control)_panel).ResumeLayout(false);
			((ISupportInitialize)_fgStyleList).EndInit();
			((Control)this).ResumeLayout(false);
		}

		private void GridStyleEditorForm_Load(object sender, EventArgs e)
		{
			_builtInCount = 16;
			_fgStyleList.Rows.Count = 0;
			_fgStyleList.Rows.Count = _styles.Count;
			int i;
			for (i = 0; i < _styles.Count; i++)
			{
				_fgStyleList[i, 0] = _styles[i].Name;
				_fgStyleList.Rows[i].UserData = _styles[i];
			}
			RowCollection rows = _fgStyleList.Rows;
			i = _builtInCount + 1;
			rows.Insert(0);
			rows.Insert(i);
			Row row = rows[0];
			bool isNode = (rows[i].IsNode = true);
			row.IsNode = isNode;
			Row row2 = rows[0];
			CellStyle style = (rows[i].Style = _fgStyleList.Styles.Fixed);
			row2.Style = style;
			Row row3 = rows[0];
			int heightDisplay = (rows[i].HeightDisplay = rows.DefaultSize + 6);
			row3.HeightDisplay = heightDisplay;
			_fgStyleList[i, 0] = F.2E("Custom Styles");
			_fgStyleList[0, 0] = F.2E("Built-In Styles");
			fgStyleList_SelChange(this, null);
		}

		private void fgStyleList_SelChange(object sender, EventArgs e)
		{
			_currentStyle = null;
			int row = _fgStyleList.Row;
			if (row >= 0)
			{
				if (_fgStyleList.Rows[row].IsNode)
				{
					_fgStyleList.Row = row - 1;
					return;
				}
				_currentStyle = _fgStyleList.Rows[row].UserData as CellStyle;
				CurrentStyleChanged();
			}
		}

		private void fgStyleList_BeforeSelChange(object sender, RangeEventArgs e)
		{
			CellRange newRange = e.NewRange;
			if (newRange.r1 >= 0)
			{
				C1FlexGrid fgStyleList = _fgStyleList;
				newRange = e.NewRange;
				int r = newRange.r1;
				newRange = e.NewRange;
				fgStyleList.ShowCell(r, newRange.c1);
				RowCollection rows = _fgStyleList.Rows;
				newRange = e.NewRange;
				if (rows[newRange.r1].IsNode)
				{
					e.Cancel = true;
				}
			}
		}

		private void CurrentStyleChanged()
		{
			((Control)_lblStyleName).Text = ((_currentStyle != null) ? _currentStyle.Name : "");
			_propGrid.SelectedObject = _currentStyle;
			if (_currentStyle == null)
			{
				((Control)_btnRemove).Enabled = false;
				return;
			}
			int num = _styles.IndexOf(_currentStyle);
			((Control)_btnRemove).Enabled = num >= _builtInCount;
		}

		private void fgStyleList_StartEdit(object sender, RowColEventArgs e)
		{
			if (!(_fgStyleList.Rows[e.Row].UserData is CellStyle style) || _styles.IndexOf(style) < _builtInCount)
			{
				e.Cancel = true;
			}
		}

		private void fgStyleList_AfterEdit(object sender, RowColEventArgs e)
		{
			//IL_0056: Unknown result type (might be due to invalid IL or missing references)
			if (!(_fgStyleList.Rows[e.Row].UserData is CellStyle { Name: var name } cellStyle))
			{
				return;
			}
			try
			{
				cellStyle.Name = _fgStyleList.GetDataDisplay(e.Row, e.Col);
			}
			catch
			{
				MessageBox.Show(F.2E("Sorry, this name is invalid."));
				_fgStyleList[e.Row, e.Col] = name;
			}
		}

		private void btnAdd_Click(object sender, EventArgs e)
		{
			string text = null;
			for (int i = 1; i < 1000; i++)
			{
				string text2 = string.Format(CultureInfo.CurrentCulture, "CustomStyle{0}", new object[1] { i });
				if (!_styles.Contains(text2))
				{
					text = text2;
					break;
				}
			}
			if (text != null)
			{
				CellStyle userData = _styles.Add(text);
				Row row = _fgStyleList.Rows.Add();
				row.UserData = userData;
				int row2 = _fgStyleList.Rows.Count - 1;
				_fgStyleList[row2, 0] = text;
				_fgStyleList.Select(row2, 0);
				((Control)_fgStyleList).Focus();
			}
		}

		private void btnRemove_Click(object sender, EventArgs e)
		{
			if (_fgStyleList.Rows[_fgStyleList.Row].UserData is CellStyle style && _styles.IndexOf(style) >= _builtInCount)
			{
				int row = _fgStyleList.Row;
				RowCollection rows = _fgStyleList.Rows;
				if (row >= 0 && !rows[row].IsNode)
				{
					rows.Remove(row);
					_styles.Remove(style);
					fgStyleList_SelChange(this, null);
					((Control)_fgStyleList).Focus();
				}
			}
		}

		private void btnClear_Click(object sender, EventArgs e)
		{
			//IL_0015: Unknown result type (might be due to invalid IL or missing references)
			//IL_001a: Unknown result type (might be due to invalid IL or missing references)
			//IL_001b: Unknown result type (might be due to invalid IL or missing references)
			//IL_001d: Invalid comparison between Unknown and I4
			DialogResult val = MessageBox.Show(F.2E("Are you sure you want to clear all styles?"), F.2E("Please confirm"), (MessageBoxButtons)4);
			if ((int)val == 6)
			{
				_styles.Clear();
				GridStyleEditorForm_Load(this, null);
			}
		}

		private void btnAutoFormat_Click(object sender, EventArgs e)
		{
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			GridAutoFormatForm gridAutoFormatForm = new GridAutoFormatForm(_styles);
			((Form)gridAutoFormatForm).ShowDialog();
			((Control)_propGrid).Refresh();
		}

		private void btnClose_Click(object sender, EventArgs e)
		{
			if (sender == _btnCancel)
			{
				((Form)this).DialogResult = (DialogResult)2;
				_styles.Clear();
				_styles.ParseString(_undoInfo);
			}
			else
			{
				((Form)this).DialogResult = (DialogResult)1;
			}
			((Form)this).Close();
		}
	}
}
namespace C1.Win
{
	internal class AboutForm : Form
	{
		private Assembly _asm;

		private bool _memberOfStudio = true;

		private bool _webProduct = false;

		private bool _mobileProduct = false;

		private string _linkURL = null;

		private PictureBox pictureBox1;

		private PictureBox pictureBox2;

		private PictureBox pictureBox3;

		private IContainer components;

		private Panel panel1;

		private Button btnOk;

		private Label label3;

		private Label label4;

		private Label labSupportInfo;

		private Label labProductName;

		private Label labCopyright;

		private Label labCustomerCompany;

		private Label labCustomerName;

		private Button btnLicense;

		private Button btnRegister;

		private Button btnPurchase;

		private ToolTip toolTip1;

		private LinkLabel linkHome;

		private LinkLabel linkSupportOptions;

		private LinkLabel linkProductSupport;

		private LinkLabel linkWebStore;

		private LinkLabel linkUpdates;

		private LinkLabel linkNewsgroup;

		private LinkLabel linkResellers;

		private Label labProductVersion;

		private Label labEvalExpired;

		private Label label5;

		private Label labRuntimeMsg1;

		private Label labRuntimeMsg2;

		private Label labLicensedTo;

		private Label labVersionCaption;

		private Panel panelGlobalInfo;

		private Label labGlobalMsg1;

		private Label labGlobalMsg2;

		private Label labGlobalMsg3;

		private LinkLabel linkGlobalHome;

		private Label labEvaluationMsg1;

		private Label labEvaluationMsg2;

		private Label labStudioName;

		private ContextMenu contextMenu1;

		private MenuItem itemCopy;

		private LinkLabel linkContactUs;

		private Label labSubscriptionExpired;

		internal 6 _newLicense = null;

		internal AboutForm()
			: this(Assembly.GetExecutingAssembly(), null, designTime: true)
		{
		}

		internal AboutForm(Assembly asm, object instance, bool designTime)
		{
			//IL_060b: Unknown result type (might be due to invalid IL or missing references)
			InitializeComponent();
			F.2F((Control)(object)this, components);
			_asm = asm;
			2 10 = (2)Attribute.GetCustomAttribute(asm, typeof(2));
			if (10 != null)
			{
				switch (10.W8)
				{
				case "08F7D405-7096-4b5f-A288-F749B8C83E6A":
					_webProduct = true;
					break;
				case "5C114645-719C-4545-891F-1DE9152952A4":
					_mobileProduct = true;
					break;
				default:
					_memberOfStudio = false;
					break;
				case "21B11D57-9478-420e-A2B2-4C6AAEF98E46":
					break;
				}
			}
			else
			{
				_memberOfStudio = false;
			}
			8 11 = 9.23(asm, instance, designTime);
			bool h = 11.H3;
			string product = ((AssemblyProductAttribute)Attribute.GetCustomAttribute(asm, typeof(AssemblyProductAttribute))).Product;
			((Control)this).Text = string.Format(CultureInfo.InvariantCulture, ((Control)this).Text, new object[1] { product });
			((Control)labProductName).Text = product;
			9.A a = 9.1Z(asm);
			((Control)labProductVersion).Text = a.HO;
			if (!_memberOfStudio)
			{
				((Control)labStudioName).Visible = false;
			}
			else if (_webProduct)
			{
				((Control)labStudioName).Text = ((Control)labStudioName).Text.Replace(".NET", "ASP.NET");
			}
			else if (_mobileProduct)
			{
				((Control)labStudioName).Text = ((Control)labStudioName).Text.Replace(".NET", "Mobile Devices");
			}
			string text = a.HS.ToString(CultureInfo.InvariantCulture);
			if (a.HS > 2002)
			{
				((Control)labCopyright).Text = string.Format(CultureInfo.InvariantCulture, ((Control)labCopyright).Text, new object[1] { "-" + text });
			}
			else
			{
				((Control)labCopyright).Text = string.Format(CultureInfo.InvariantCulture, ((Control)labCopyright).Text, new object[1] { ", " + text });
			}
			if (designTime || h)
			{
				if (h || (11.H5 && 11.H4 != 7.GW && 11.H4 != 7.GV))
				{
					((Control)labCustomerName).Text = 11.H6;
					((Control)labCustomerCompany).Text = 11.H7;
					if (11.H5)
					{
						int num = 11.H8 + 1;
						int num2 = 11.H9 + 1;
						if (num2 == 5)
						{
							num++;
							num2 = 1;
						}
						((Control)labSubscriptionExpired).Text = string.Format(CultureInfo.InvariantCulture, ((Control)labSubscriptionExpired).Text, new object[2] { num2, num });
						((Control)labSubscriptionExpired).Visible = true;
					}
					((Control)labEvaluationMsg1).Visible = false;
					((Control)labEvaluationMsg2).Visible = false;
				}
				else
				{
					if (9.24(asm))
					{
						((Control)labEvalExpired).Visible = true;
					}
					((Control)labCustomerName).Visible = false;
					((Control)labCustomerCompany).Visible = false;
				}
			}
			else
			{
				((Control)labLicensedTo).Visible = false;
				((Control)btnLicense).Visible = false;
				((Control)btnRegister).Visible = false;
				((Control)btnPurchase).Visible = false;
				((Control)labProductName).Location = new Point(((Control)labProductName).Location.X, 64);
				((Control)labVersionCaption).Location = new Point(((Control)labVersionCaption).Location.X, 86);
				((Control)labProductVersion).Location = new Point(((Control)labProductVersion).Location.X, 86);
				if (Attribute.GetCustomAttribute(asm, typeof(3)) != null)
				{
					((Control)panel1).Location = new Point(((Control)panel1).Location.X, 134);
					((Control)labCustomerName).Visible = false;
					((Control)labCustomerCompany).Visible = false;
				}
				else
				{
					((Control)panel1).Visible = false;
					if (F.I0.Name.StartsWith("de"))
					{
						((Control)labRuntimeMsg1).Location = new Point(217, ((Control)labRuntimeMsg1).Location.Y);
						((Control)labRuntimeMsg2).Location = new Point(217, ((Control)labRuntimeMsg2).Location.Y);
					}
					((Control)labRuntimeMsg1).Visible = true;
					((Control)labRuntimeMsg2).Visible = true;
				}
			}
			((Control)linkHome).Tag = "http://www.componentone.com/default.aspx";
			5 12 = (5)Attribute.GetCustomAttribute(asm, typeof(5));
			if (12.WD.Length > 0)
			{
				((Control)linkUpdates).Tag = 12.WD;
			}
			else
			{
				((Control)linkUpdates).Tag = "http://www.componentone.com/Download.aspx?DownloadCode=1";
			}
			if (12.WC.Length > 0)
			{
				((Control)linkNewsgroup).Tag = 12.WC;
			}
			else
			{
				((Control)linkNewsgroup).Tag = "http://www.componentone.com/pages.aspx?pagesid=52";
			}
			((Control)linkWebStore).Tag = "http://www.store.yahoo.com/componentone-llc/";
			((Control)linkResellers).Tag = "http://www.componentone.com/resellers.aspx?ResellerCode=1";
			((Control)linkProductSupport).Text = 12.WB;
			((Control)linkProductSupport).Tag = "mailto:" + 12.WB + "?subject=" + product + " (version " + ((Control)labProductVersion).Text + ")";
			linkProductSupport.LinkArea = new LinkArea(0, ((Control)linkProductSupport).Text.Length);
			((Control)linkContactUs).Tag = "http://www.componentone.com/pages.aspx?pagesID=31";
			((Control)linkSupportOptions).Tag = "http://www.componentone.com/Support.aspx?SupportCode=1";
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing)
			{
				if (_newLicense != null)
				{
					_newLicense.Dispose();
					_newLicense = null;
				}
				if (components != null)
				{
					components.Dispose();
				}
			}
			((Form)this).Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_001c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Expected O, but got Unknown
			//IL_0027: Unknown result type (might be due to invalid IL or missing references)
			//IL_0031: Expected O, but got Unknown
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0047: Expected O, but got Unknown
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			//IL_0052: Expected O, but got Unknown
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_005d: Expected O, but got Unknown
			//IL_005e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0068: Expected O, but got Unknown
			//IL_0069: Unknown result type (might be due to invalid IL or missing references)
			//IL_0073: Expected O, but got Unknown
			//IL_0074: Unknown result type (might be due to invalid IL or missing references)
			//IL_007e: Expected O, but got Unknown
			//IL_007f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0089: Expected O, but got Unknown
			//IL_008a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0094: Expected O, but got Unknown
			//IL_0095: Unknown result type (might be due to invalid IL or missing references)
			//IL_009f: Expected O, but got Unknown
			//IL_00a0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00aa: Expected O, but got Unknown
			//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b5: Expected O, but got Unknown
			//IL_00b6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c0: Expected O, but got Unknown
			//IL_00c1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00cb: Expected O, but got Unknown
			//IL_00cc: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d6: Expected O, but got Unknown
			//IL_00d7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e1: Expected O, but got Unknown
			//IL_00e2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ec: Expected O, but got Unknown
			//IL_00ed: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f7: Expected O, but got Unknown
			//IL_00f8: Unknown result type (might be due to invalid IL or missing references)
			//IL_0102: Expected O, but got Unknown
			//IL_0103: Unknown result type (might be due to invalid IL or missing references)
			//IL_010d: Expected O, but got Unknown
			//IL_010e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0118: Expected O, but got Unknown
			//IL_0119: Unknown result type (might be due to invalid IL or missing references)
			//IL_0123: Expected O, but got Unknown
			//IL_0124: Unknown result type (might be due to invalid IL or missing references)
			//IL_012e: Expected O, but got Unknown
			//IL_012f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0139: Expected O, but got Unknown
			//IL_013a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0144: Expected O, but got Unknown
			//IL_0145: Unknown result type (might be due to invalid IL or missing references)
			//IL_014f: Expected O, but got Unknown
			//IL_0150: Unknown result type (might be due to invalid IL or missing references)
			//IL_015a: Expected O, but got Unknown
			//IL_015b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0165: Expected O, but got Unknown
			//IL_016c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0176: Expected O, but got Unknown
			//IL_0177: Unknown result type (might be due to invalid IL or missing references)
			//IL_0181: Expected O, but got Unknown
			//IL_0182: Unknown result type (might be due to invalid IL or missing references)
			//IL_018c: Expected O, but got Unknown
			//IL_018d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0197: Expected O, but got Unknown
			//IL_0198: Unknown result type (might be due to invalid IL or missing references)
			//IL_01a2: Expected O, but got Unknown
			//IL_01a3: Unknown result type (might be due to invalid IL or missing references)
			//IL_01ad: Expected O, but got Unknown
			//IL_01ae: Unknown result type (might be due to invalid IL or missing references)
			//IL_01b8: Expected O, but got Unknown
			//IL_01b9: Unknown result type (might be due to invalid IL or missing references)
			//IL_01c3: Expected O, but got Unknown
			//IL_01c4: Unknown result type (might be due to invalid IL or missing references)
			//IL_01ce: Expected O, but got Unknown
			//IL_01cf: Unknown result type (might be due to invalid IL or missing references)
			//IL_01d9: Expected O, but got Unknown
			//IL_01da: Unknown result type (might be due to invalid IL or missing references)
			//IL_01e4: Expected O, but got Unknown
			//IL_01e5: Unknown result type (might be due to invalid IL or missing references)
			//IL_01ef: Expected O, but got Unknown
			//IL_021e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0228: Expected O, but got Unknown
			//IL_02d5: Unknown result type (might be due to invalid IL or missing references)
			//IL_02df: Expected O, but got Unknown
			//IL_040c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0416: Expected O, but got Unknown
			//IL_04a7: Unknown result type (might be due to invalid IL or missing references)
			//IL_04b1: Expected O, but got Unknown
			//IL_0543: Unknown result type (might be due to invalid IL or missing references)
			//IL_054d: Expected O, but got Unknown
			//IL_05e2: Unknown result type (might be due to invalid IL or missing references)
			//IL_05ec: Expected O, but got Unknown
			//IL_05f5: Unknown result type (might be due to invalid IL or missing references)
			//IL_0685: Unknown result type (might be due to invalid IL or missing references)
			//IL_068f: Expected O, but got Unknown
			//IL_0703: Unknown result type (might be due to invalid IL or missing references)
			//IL_070d: Expected O, but got Unknown
			//IL_0910: Unknown result type (might be due to invalid IL or missing references)
			//IL_091a: Expected O, but got Unknown
			//IL_0a3a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0a44: Expected O, but got Unknown
			//IL_0ad2: Unknown result type (might be due to invalid IL or missing references)
			//IL_0adc: Expected O, but got Unknown
			//IL_0ae5: Unknown result type (might be due to invalid IL or missing references)
			//IL_0b76: Unknown result type (might be due to invalid IL or missing references)
			//IL_0b80: Expected O, but got Unknown
			//IL_0baa: Unknown result type (might be due to invalid IL or missing references)
			//IL_0bb4: Expected O, but got Unknown
			//IL_0c4f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0c59: Expected O, but got Unknown
			//IL_0cdf: Unknown result type (might be due to invalid IL or missing references)
			//IL_0ce9: Expected O, but got Unknown
			//IL_0d13: Unknown result type (might be due to invalid IL or missing references)
			//IL_0d1d: Expected O, but got Unknown
			//IL_0d9a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0da4: Expected O, but got Unknown
			//IL_0e3d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0e47: Expected O, but got Unknown
			//IL_0f1d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0f27: Expected O, but got Unknown
			//IL_0fe1: Unknown result type (might be due to invalid IL or missing references)
			//IL_0feb: Expected O, but got Unknown
			//IL_1066: Unknown result type (might be due to invalid IL or missing references)
			//IL_1070: Expected O, but got Unknown
			//IL_10ee: Unknown result type (might be due to invalid IL or missing references)
			//IL_10f8: Expected O, but got Unknown
			//IL_1187: Unknown result type (might be due to invalid IL or missing references)
			//IL_1191: Expected O, but got Unknown
			//IL_119a: Unknown result type (might be due to invalid IL or missing references)
			//IL_1227: Unknown result type (might be due to invalid IL or missing references)
			//IL_1231: Expected O, but got Unknown
			//IL_126c: Unknown result type (might be due to invalid IL or missing references)
			//IL_1276: Expected O, but got Unknown
			//IL_127f: Unknown result type (might be due to invalid IL or missing references)
			//IL_130f: Unknown result type (might be due to invalid IL or missing references)
			//IL_1319: Expected O, but got Unknown
			//IL_1354: Unknown result type (might be due to invalid IL or missing references)
			//IL_135e: Expected O, but got Unknown
			//IL_1367: Unknown result type (might be due to invalid IL or missing references)
			//IL_13f4: Unknown result type (might be due to invalid IL or missing references)
			//IL_13fe: Expected O, but got Unknown
			//IL_1439: Unknown result type (might be due to invalid IL or missing references)
			//IL_1443: Expected O, but got Unknown
			//IL_144c: Unknown result type (might be due to invalid IL or missing references)
			//IL_14dc: Unknown result type (might be due to invalid IL or missing references)
			//IL_14e6: Expected O, but got Unknown
			//IL_153d: Unknown result type (might be due to invalid IL or missing references)
			//IL_1547: Expected O, but got Unknown
			//IL_15ea: Unknown result type (might be due to invalid IL or missing references)
			//IL_15f4: Expected O, but got Unknown
			//IL_16a8: Unknown result type (might be due to invalid IL or missing references)
			//IL_16b2: Expected O, but got Unknown
			//IL_1739: Unknown result type (might be due to invalid IL or missing references)
			//IL_1743: Expected O, but got Unknown
			//IL_17e3: Unknown result type (might be due to invalid IL or missing references)
			//IL_17ed: Expected O, but got Unknown
			//IL_187a: Unknown result type (might be due to invalid IL or missing references)
			//IL_1884: Expected O, but got Unknown
			//IL_19e6: Unknown result type (might be due to invalid IL or missing references)
			//IL_19f0: Expected O, but got Unknown
			//IL_1a63: Unknown result type (might be due to invalid IL or missing references)
			//IL_1a6d: Expected O, but got Unknown
			//IL_1a97: Unknown result type (might be due to invalid IL or missing references)
			//IL_1aa1: Expected O, but got Unknown
			//IL_1b1d: Unknown result type (might be due to invalid IL or missing references)
			//IL_1b27: Expected O, but got Unknown
			//IL_1ba4: Unknown result type (might be due to invalid IL or missing references)
			//IL_1bae: Expected O, but got Unknown
			components = new Container();
			ResourceManager resourceManager = new ResourceManager(typeof(AboutForm));
			labCustomerCompany = new Label();
			btnOk = new Button();
			panel1 = new Panel();
			labEvaluationMsg1 = new Label();
			labEvaluationMsg2 = new Label();
			labCustomerName = new Label();
			linkHome = new LinkLabel();
			contextMenu1 = new ContextMenu();
			itemCopy = new MenuItem();
			labLicensedTo = new Label();
			pictureBox2 = new PictureBox();
			pictureBox1 = new PictureBox();
			pictureBox3 = new PictureBox();
			btnLicense = new Button();
			label3 = new Label();
			label4 = new Label();
			linkSupportOptions = new LinkLabel();
			labSupportInfo = new Label();
			linkProductSupport = new LinkLabel();
			labProductName = new Label();
			labCopyright = new Label();
			btnRegister = new Button();
			btnPurchase = new Button();
			labVersionCaption = new Label();
			labProductVersion = new Label();
			labStudioName = new Label();
			linkWebStore = new LinkLabel();
			linkUpdates = new LinkLabel();
			linkNewsgroup = new LinkLabel();
			linkResellers = new LinkLabel();
			toolTip1 = new ToolTip(components);
			labEvalExpired = new Label();
			labSubscriptionExpired = new Label();
			linkContactUs = new LinkLabel();
			label5 = new Label();
			labRuntimeMsg1 = new Label();
			labRuntimeMsg2 = new Label();
			panelGlobalInfo = new Panel();
			linkGlobalHome = new LinkLabel();
			labGlobalMsg1 = new Label();
			labGlobalMsg2 = new Label();
			labGlobalMsg3 = new Label();
			((Control)panel1).SuspendLayout();
			((Control)panelGlobalInfo).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)labCustomerCompany).Font = new Font("Verdana", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)labCustomerCompany).ForeColor = Color.Black;
			((Control)labCustomerCompany).Location = new Point(6, 22);
			((Control)labCustomerCompany).Name = "labCustomerCompany";
			((Control)labCustomerCompany).Size = new Size(348, 14);
			((Control)labCustomerCompany).TabIndex = 1;
			((Control)labCustomerCompany).Text = "Customer Company";
			labCustomerCompany.UseMnemonic = false;
			((Control)btnOk).BackColor = SystemColors.Control;
			btnOk.DialogResult = (DialogResult)1;
			((ButtonBase)btnOk).FlatStyle = (FlatStyle)0;
			((Control)btnOk).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)btnOk).ForeColor = Color.Black;
			((Control)btnOk).Location = new Point(496, 324);
			((Control)btnOk).Name = "btnOk";
			((Control)btnOk).Size = new Size(76, 24);
			((Control)btnOk).TabIndex = 11;
			((Control)btnOk).Text = "OK";
			panel1.BorderStyle = (BorderStyle)1;
			((Control)panel1).Controls.Add((Control)(object)labEvaluationMsg1);
			((Control)panel1).Controls.Add((Control)(object)labEvaluationMsg2);
			((Control)panel1).Controls.Add((Control)(object)labCustomerName);
			((Control)panel1).Controls.Add((Control)(object)labCustomerCompany);
			((Control)panel1).Location = new Point(224, 112);
			((Control)panel1).Name = "panel1";
			((Control)panel1).Size = new Size(348, 42);
			((Control)panel1).TabIndex = 9;
			((Control)labEvaluationMsg1).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)labEvaluationMsg1).ForeColor = Color.Red;
			((Control)labEvaluationMsg1).Location = new Point(6, 4);
			((Control)labEvaluationMsg1).Name = "labEvaluationMsg1";
			((Control)labEvaluationMsg1).Size = new Size(340, 14);
			((Control)labEvaluationMsg1).TabIndex = 28;
			((Control)labEvaluationMsg1).Text = "NOT LICENSED. THIS IS AN EVALUATION VERSION";
			labEvaluationMsg1.TextAlign = (ContentAlignment)2;
			labEvaluationMsg1.UseMnemonic = false;
			((Control)labEvaluationMsg2).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)labEvaluationMsg2).ForeColor = Color.Red;
			((Control)labEvaluationMsg2).Location = new Point(6, 22);
			((Control)labEvaluationMsg2).Name = "labEvaluationMsg2";
			((Control)labEvaluationMsg2).Size = new Size(340, 14);
			((Control)labEvaluationMsg2).TabIndex = 29;
			((Control)labEvaluationMsg2).Text = "You can use this product for a 30-day trial period.";
			labEvaluationMsg2.TextAlign = (ContentAlignment)2;
			labEvaluationMsg2.UseMnemonic = false;
			((Control)labCustomerName).Font = new Font("Verdana", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)labCustomerName).ForeColor = Color.Black;
			((Control)labCustomerName).Location = new Point(6, 4);
			((Control)labCustomerName).Name = "labCustomerName";
			((Control)labCustomerName).Size = new Size(348, 14);
			((Control)labCustomerName).TabIndex = 0;
			((Control)labCustomerName).Text = "Customer Name";
			labCustomerName.UseMnemonic = false;
			((Control)linkHome).ContextMenu = contextMenu1;
			((Control)linkHome).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			linkHome.LinkArea = new LinkArea(0, 27);
			((Control)linkHome).Location = new Point(172, 216);
			((Control)linkHome).Name = "linkHome";
			((Control)linkHome).Size = new Size(188, 16);
			((Control)linkHome).TabIndex = 3;
			((Label)linkHome).TabStop = true;
			((Control)linkHome).Tag = "";
			((Control)linkHome).Text = "http://www.componentone.com";
			linkHome.LinkClicked += new LinkLabelLinkClickedEventHandler(link_LinkClicked);
			((Control)linkHome).MouseEnter += link_MouseEnter;
			((Menu)contextMenu1).MenuItems.Add(itemCopy);
			itemCopy.Index = 0;
			itemCopy.Text = "Copy URL";
			itemCopy.Click += Copy_Click;
			((Control)labLicensedTo).Font = new Font("Verdana", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)labLicensedTo).ForeColor = Color.Black;
			((Control)labLicensedTo).Location = new Point(224, 96);
			((Control)labLicensedTo).Name = "labLicensedTo";
			((Control)labLicensedTo).Size = new Size(320, 16);
			((Control)labLicensedTo).TabIndex = 8;
			((Control)labLicensedTo).Text = "This product is licensed to:";
			pictureBox2.Image = 9.1E(resourceManager.GetObject("pictureBox2.Image"));
			((Control)pictureBox2).Location = new Point(224, 8);
			((Control)pictureBox2).Name = "pictureBox2";
			((Control)pictureBox2).Size = new Size(320, 56);
			pictureBox2.TabIndex = 4;
			pictureBox2.TabStop = false;
			pictureBox1.Image = 9.1E(resourceManager.GetObject("pictureBox1.Image"));
			((Control)pictureBox1).Location = new Point(12, 40);
			((Control)pictureBox1).Name = "pictureBox1";
			((Control)pictureBox1).Size = new Size(192, 160);
			pictureBox1.TabIndex = 3;
			pictureBox1.TabStop = false;
			pictureBox3.Image = 9.1E(resourceManager.GetObject("pictureBox3.Image"));
			((Control)pictureBox3).Location = new Point(216, 1);
			((Control)pictureBox3).Name = "pictureBox3";
			((Control)pictureBox3).Size = new Size(175, 19);
			pictureBox3.SizeMode = (PictureBoxSizeMode)2;
			pictureBox3.TabIndex = 30;
			pictureBox3.TabStop = false;
			((Control)pictureBox3).Visible = false;
			((Control)btnLicense).BackColor = SystemColors.Control;
			((ButtonBase)btnLicense).FlatStyle = (FlatStyle)0;
			((Control)btnLicense).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)btnLicense).ForeColor = Color.Black;
			((Control)btnLicense).Location = new Point(281, 160);
			((Control)btnLicense).Name = "btnLicense";
			((Control)btnLicense).Size = new Size(74, 24);
			((Control)btnLicense).TabIndex = 0;
			((Control)btnLicense).Text = "License";
			toolTip1.SetToolTip((Control)(object)btnLicense, "Click here if you purchased the product and already have a license key.");
			((Control)btnLicense).Click += btnLicense_Click;
			((Control)label3).BackColor = Color.Black;
			label3.BorderStyle = (BorderStyle)1;
			((Control)label3).ForeColor = Color.Black;
			((Control)label3).Location = new Point(12, 309);
			((Control)label3).Name = "label3";
			((Control)label3).Size = new Size(560, 3);
			((Control)label3).TabIndex = 20;
			((Control)label4).Font = new Font("Verdana", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)label4).ForeColor = Color.Black;
			((Control)label4).Location = new Point(12, 216);
			((Control)label4).Name = "label4";
			((Control)label4).Size = new Size(140, 16);
			((Control)label4).TabIndex = 2;
			((Control)label4).Text = "Online Resources:";
			((Control)linkSupportOptions).ContextMenu = contextMenu1;
			((Control)linkSupportOptions).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			linkSupportOptions.LinkArea = new LinkArea(0, 30);
			((Control)linkSupportOptions).Location = new Point(278, 284);
			((Control)linkSupportOptions).Name = "linkSupportOptions";
			((Control)linkSupportOptions).Size = new Size(266, 16);
			((Control)linkSupportOptions).TabIndex = 10;
			((Label)linkSupportOptions).TabStop = true;
			((Control)linkSupportOptions).Tag = "";
			((Control)linkSupportOptions).Text = "ComponentOne Technical Support";
			linkSupportOptions.LinkClicked += new LinkLabelLinkClickedEventHandler(link_LinkClicked);
			((Control)linkSupportOptions).MouseEnter += link_MouseEnter;
			((Control)labSupportInfo).Font = new Font("Verdana", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)labSupportInfo).ForeColor = Color.Black;
			((Control)labSupportInfo).Location = new Point(12, 262);
			((Control)labSupportInfo).Name = "labSupportInfo";
			((Control)labSupportInfo).Size = new Size(264, 16);
			((Control)labSupportInfo).TabIndex = 17;
			((Control)labSupportInfo).Text = "For email support, please write to:";
			labSupportInfo.TextAlign = (ContentAlignment)4;
			((Control)linkProductSupport).ContextMenu = contextMenu1;
			((Control)linkProductSupport).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)linkProductSupport).Location = new Point(278, 262);
			((Control)linkProductSupport).Name = "linkProductSupport";
			((Control)linkProductSupport).Size = new Size(302, 16);
			((Control)linkProductSupport).TabIndex = 8;
			((Label)linkProductSupport).TabStop = true;
			((Control)linkProductSupport).Tag = "";
			((Control)linkProductSupport).Text = "Support.C1Product.NET@ComponentOne.com";
			linkProductSupport.LinkClicked += new LinkLabelLinkClickedEventHandler(link_LinkClicked);
			((Control)linkProductSupport).MouseEnter += link_MouseEnter;
			((Control)labProductName).Font = new Font("Verdana", 9.75f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)labProductName).ForeColor = Color.Black;
			((Control)labProductName).Location = new Point(223, 60);
			((Control)labProductName).Name = "labProductName";
			((Control)labProductName).Size = new Size(361, 16);
			((Control)labProductName).TabIndex = 0;
			((Control)labProductName).Text = "ComponentOne Product Name";
			((Control)labCopyright).Font = new Font("Verdana", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)labCopyright).ForeColor = Color.Black;
			((Control)labCopyright).Location = new Point(12, 336);
			((Control)labCopyright).Name = "labCopyright";
			((Control)labCopyright).Size = new Size(482, 16);
			((Control)labCopyright).TabIndex = 1;
			((Control)labCopyright).Text = "Copyright (C) 2001{0} ComponentOne LLC. All rights reserved.";
			((Control)btnRegister).BackColor = SystemColors.Control;
			((ButtonBase)btnRegister).FlatStyle = (FlatStyle)0;
			((Control)btnRegister).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)btnRegister).ForeColor = Color.Black;
			((Control)btnRegister).Location = new Point(361, 160);
			((Control)btnRegister).Name = "btnRegister";
			((Control)btnRegister).Size = new Size(74, 24);
			((Control)btnRegister).TabIndex = 1;
			((Control)btnRegister).Tag = "";
			((Control)btnRegister).Text = "Register";
			toolTip1.SetToolTip((Control)(object)btnRegister, "Click here to register online (so we can send you quarterly updates).");
			((Control)btnRegister).Click += btnRegister_Click;
			((Control)btnPurchase).BackColor = SystemColors.Control;
			((ButtonBase)btnPurchase).FlatStyle = (FlatStyle)0;
			((Control)btnPurchase).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)btnPurchase).ForeColor = Color.Black;
			((Control)btnPurchase).Location = new Point(441, 160);
			((Control)btnPurchase).Name = "btnPurchase";
			((Control)btnPurchase).Size = new Size(74, 24);
			((Control)btnPurchase).TabIndex = 2;
			((Control)btnPurchase).Tag = "";
			((Control)btnPurchase).Text = "Purchase";
			toolTip1.SetToolTip((Control)(object)btnPurchase, "Click here to buy a copy of the product. After you purchase, you should license and register it.");
			((Control)btnPurchase).Click += btnPurchase_Click;
			((Control)labVersionCaption).Font = new Font("Tahoma", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)labVersionCaption).ForeColor = Color.Black;
			((Control)labVersionCaption).Location = new Point(224, 78);
			((Control)labVersionCaption).Name = "labVersionCaption";
			((Control)labVersionCaption).Size = new Size(64, 16);
			((Control)labVersionCaption).TabIndex = 15;
			((Control)labVersionCaption).Text = "Version:";
			((Control)labProductVersion).Font = new Font("Tahoma", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)labProductVersion).ForeColor = Color.Black;
			((Control)labProductVersion).Location = new Point(296, 78);
			((Control)labProductVersion).Name = "labProductVersion";
			((Control)labProductVersion).Size = new Size(248, 15);
			((Control)labProductVersion).TabIndex = 16;
			((Control)labProductVersion).Text = "1.1.20021.12345";
			((Control)labStudioName).Font = new Font("Verdana", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)labStudioName).ForeColor = Color.Black;
			((Control)labStudioName).Location = new Point(12, 318);
			((Control)labStudioName).Name = "labStudioName";
			((Control)labStudioName).Size = new Size(482, 16);
			((Control)labStudioName).TabIndex = 19;
			((Control)labStudioName).Text = "This product is included in ComponentOne Studio(TM) for .NET";
			((Control)linkWebStore).ContextMenu = contextMenu1;
			((Control)linkWebStore).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			linkWebStore.LinkArea = new LinkArea(0, 9);
			((Control)linkWebStore).Location = new Point(278, 238);
			((Control)linkWebStore).Name = "linkWebStore";
			((Control)linkWebStore).Size = new Size(98, 16);
			((Control)linkWebStore).TabIndex = 6;
			((Label)linkWebStore).TabStop = true;
			((Control)linkWebStore).Tag = "";
			((Control)linkWebStore).Text = "Web Store";
			linkWebStore.LinkClicked += new LinkLabelLinkClickedEventHandler(link_LinkClicked);
			((Control)linkWebStore).MouseEnter += link_MouseEnter;
			((Control)linkUpdates).ContextMenu = contextMenu1;
			((Control)linkUpdates).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			linkUpdates.LinkArea = new LinkArea(0, 24);
			((Control)linkUpdates).Location = new Point(380, 216);
			((Control)linkUpdates).Name = "linkUpdates";
			((Control)linkUpdates).Size = new Size(180, 16);
			((Control)linkUpdates).TabIndex = 4;
			((Label)linkUpdates).TabStop = true;
			((Control)linkUpdates).Tag = "";
			((Control)linkUpdates).Text = "Check for online updates";
			linkUpdates.LinkClicked += new LinkLabelLinkClickedEventHandler(link_LinkClicked);
			((Control)linkUpdates).MouseEnter += link_MouseEnter;
			((Control)linkNewsgroup).ContextMenu = contextMenu1;
			((Control)linkNewsgroup).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			linkNewsgroup.LinkArea = new LinkArea(0, 9);
			((Control)linkNewsgroup).Location = new Point(172, 238);
			((Control)linkNewsgroup).Name = "linkNewsgroup";
			((Control)linkNewsgroup).Size = new Size(104, 16);
			((Control)linkNewsgroup).TabIndex = 5;
			((Label)linkNewsgroup).TabStop = true;
			((Control)linkNewsgroup).Tag = "";
			((Control)linkNewsgroup).Text = "Newsgroup";
			linkNewsgroup.LinkClicked += new LinkLabelLinkClickedEventHandler(link_LinkClicked);
			((Control)linkNewsgroup).MouseEnter += link_MouseEnter;
			((Control)linkResellers).ContextMenu = contextMenu1;
			((Control)linkResellers).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			linkResellers.LinkArea = new LinkArea(0, 9);
			((Control)linkResellers).Location = new Point(380, 238);
			((Control)linkResellers).Name = "linkResellers";
			((Control)linkResellers).Size = new Size(160, 16);
			((Control)linkResellers).TabIndex = 7;
			((Label)linkResellers).TabStop = true;
			((Control)linkResellers).Tag = "";
			((Control)linkResellers).Text = "Resellers";
			linkResellers.LinkClicked += new LinkLabelLinkClickedEventHandler(link_LinkClicked);
			((Control)linkResellers).MouseEnter += link_MouseEnter;
			toolTip1.AutoPopDelay = 20000;
			toolTip1.InitialDelay = 500;
			toolTip1.ReshowDelay = 100;
			((Control)labEvalExpired).Font = new Font("Verdana", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)labEvalExpired).ForeColor = Color.Red;
			((Control)labEvalExpired).Location = new Point(224, 188);
			((Control)labEvalExpired).Name = "labEvalExpired";
			((Control)labEvalExpired).Size = new Size(352, 16);
			((Control)labEvalExpired).TabIndex = 10;
			((Control)labEvalExpired).Text = "This evaluation version has expired.";
			toolTip1.SetToolTip((Control)(object)labEvalExpired, "Please check our web site for a new version.");
			((Control)labEvalExpired).Visible = false;
			((Control)labSubscriptionExpired).Font = new Font("Verdana", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)labSubscriptionExpired).ForeColor = Color.Red;
			((Control)labSubscriptionExpired).Location = new Point(224, 188);
			((Control)labSubscriptionExpired).Name = "labSubscriptionExpired";
			((Control)labSubscriptionExpired).Size = new Size(352, 16);
			((Control)labSubscriptionExpired).TabIndex = 28;
			((Control)labSubscriptionExpired).Text = "Your subscription has expired since Q{0} {1}.";
			toolTip1.SetToolTip((Control)(object)labSubscriptionExpired, "Renew your subscription to get a new license key, or keep using the components released while your subscription was valid.");
			((Control)labSubscriptionExpired).Visible = false;
			((Control)linkContactUs).ContextMenu = contextMenu1;
			((Control)linkContactUs).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)linkContactUs).Location = new Point(172, 284);
			((Control)linkContactUs).Name = "linkContactUs";
			((Control)linkContactUs).Size = new Size(132, 16);
			((Control)linkContactUs).TabIndex = 9;
			((Label)linkContactUs).TabStop = true;
			((Control)linkContactUs).Tag = "";
			((Control)linkContactUs).Text = "Contact Us";
			linkContactUs.LinkClicked += new LinkLabelLinkClickedEventHandler(link_LinkClicked);
			((Control)linkContactUs).MouseEnter += link_MouseEnter;
			((Control)label5).BackColor = Color.Black;
			label5.BorderStyle = (BorderStyle)1;
			((Control)label5).ForeColor = Color.Black;
			((Control)label5).Location = new Point(12, 204);
			((Control)label5).Name = "label5";
			((Control)label5).Size = new Size(560, 3);
			((Control)label5).TabIndex = 24;
			((Control)labRuntimeMsg1).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)labRuntimeMsg1).ForeColor = Color.Red;
			((Control)labRuntimeMsg1).Location = new Point(224, 154);
			((Control)labRuntimeMsg1).Name = "labRuntimeMsg1";
			((Control)labRuntimeMsg1).Size = new Size(382, 16);
			((Control)labRuntimeMsg1).TabIndex = 25;
			((Control)labRuntimeMsg1).Text = "This dialog box will not be shown if you recompile the program";
			((Control)labRuntimeMsg1).Visible = false;
			((Control)labRuntimeMsg2).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)labRuntimeMsg2).ForeColor = Color.Red;
			((Control)labRuntimeMsg2).Location = new Point(224, 176);
			((Control)labRuntimeMsg2).Name = "labRuntimeMsg2";
			((Control)labRuntimeMsg2).Size = new Size(362, 16);
			((Control)labRuntimeMsg2).TabIndex = 26;
			((Control)labRuntimeMsg2).Text = "using a licensed version of this product.";
			((Control)labRuntimeMsg2).Visible = false;
			((Control)panelGlobalInfo).Controls.Add((Control)(object)linkGlobalHome);
			((Control)panelGlobalInfo).Controls.Add((Control)(object)labGlobalMsg1);
			((Control)panelGlobalInfo).Controls.Add((Control)(object)labGlobalMsg2);
			((Control)panelGlobalInfo).Controls.Add((Control)(object)labGlobalMsg3);
			((Control)panelGlobalInfo).Controls.Add((Control)(object)pictureBox3);
			((Control)panelGlobalInfo).Location = new Point(8, 212);
			((Control)panelGlobalInfo).Name = "panelGlobalInfo";
			((Control)panelGlobalInfo).Size = new Size(568, 92);
			((Control)panelGlobalInfo).TabIndex = 27;
			((Control)panelGlobalInfo).Visible = false;
			((Control)linkGlobalHome).ContextMenu = contextMenu1;
			((Control)linkGlobalHome).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)linkGlobalHome).Location = new Point(216, 71);
			((Control)linkGlobalHome).Name = "linkGlobalHome";
			((Control)linkGlobalHome).Size = new Size(336, 16);
			((Control)linkGlobalHome).TabIndex = 3;
			((Label)linkGlobalHome).TabStop = true;
			((Control)linkGlobalHome).Text = "linkGlobalHome";
			linkGlobalHome.LinkClicked += new LinkLabelLinkClickedEventHandler(link_LinkClicked);
			((Control)linkGlobalHome).MouseEnter += link_MouseEnter;
			((Control)labGlobalMsg1).Font = new Font("Tahoma", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)labGlobalMsg1).ForeColor = Color.Black;
			((Control)labGlobalMsg1).Location = new Point(216, 4);
			((Control)labGlobalMsg1).Name = "labGlobalMsg1";
			((Control)labGlobalMsg1).Size = new Size(336, 16);
			((Control)labGlobalMsg1).TabIndex = 0;
			((Control)labGlobalMsg1).Text = "msg1";
			((Control)labGlobalMsg2).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)labGlobalMsg2).ForeColor = Color.Black;
			((Control)labGlobalMsg2).Location = new Point(216, 28);
			((Control)labGlobalMsg2).Name = "labGlobalMsg2";
			((Control)labGlobalMsg2).Size = new Size(336, 16);
			((Control)labGlobalMsg2).TabIndex = 1;
			((Control)labGlobalMsg2).Text = "msg2";
			((Control)labGlobalMsg3).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)labGlobalMsg3).ForeColor = Color.Black;
			((Control)labGlobalMsg3).Location = new Point(216, 50);
			((Control)labGlobalMsg3).Name = "labGlobalMsg3";
			((Control)labGlobalMsg3).Size = new Size(336, 16);
			((Control)labGlobalMsg3).TabIndex = 2;
			((Control)labGlobalMsg3).Text = "msg3";
			((Form)this).AcceptButton = (IButtonControl)(object)btnOk;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Control)this).BackColor = Color.White;
			((Form)this).ClientSize = new Size(585, 359);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)panelGlobalInfo);
			((Control)this).Controls.Add((Control)(object)linkProductSupport);
			((Control)this).Controls.Add((Control)(object)linkSupportOptions);
			((Control)this).Controls.Add((Control)(object)labSubscriptionExpired);
			((Control)this).Controls.Add((Control)(object)label5);
			((Control)this).Controls.Add((Control)(object)labProductName);
			((Control)this).Controls.Add((Control)(object)labEvalExpired);
			((Control)this).Controls.Add((Control)(object)linkContactUs);
			((Control)this).Controls.Add((Control)(object)linkResellers);
			((Control)this).Controls.Add((Control)(object)linkNewsgroup);
			((Control)this).Controls.Add((Control)(object)linkUpdates);
			((Control)this).Controls.Add((Control)(object)linkWebStore);
			((Control)this).Controls.Add((Control)(object)labStudioName);
			((Control)this).Controls.Add((Control)(object)labProductVersion);
			((Control)this).Controls.Add((Control)(object)labVersionCaption);
			((Control)this).Controls.Add((Control)(object)btnPurchase);
			((Control)this).Controls.Add((Control)(object)btnRegister);
			((Control)this).Controls.Add((Control)(object)labCopyright);
			((Control)this).Controls.Add((Control)(object)labSupportInfo);
			((Control)this).Controls.Add((Control)(object)btnOk);
			((Control)this).Controls.Add((Control)(object)label3);
			((Control)this).Controls.Add((Control)(object)labLicensedTo);
			((Control)this).Controls.Add((Control)(object)panel1);
			((Control)this).Controls.Add((Control)(object)linkHome);
			((Control)this).Controls.Add((Control)(object)btnLicense);
			((Control)this).Controls.Add((Control)(object)pictureBox1);
			((Control)this).Controls.Add((Control)(object)labRuntimeMsg2);
			((Control)this).Controls.Add((Control)(object)labRuntimeMsg1);
			((Control)this).Controls.Add((Control)(object)pictureBox2);
			((Control)this).ForeColor = Color.Black;
			((Form)this).FormBorderStyle = (FormBorderStyle)3;
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = "AboutForm";
			((Form)this).StartPosition = (FormStartPosition)1;
			((Control)this).Text = "About {0}";
			((Control)panel1).ResumeLayout(false);
			((Control)panelGlobalInfo).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private void btnLicense_Click(object sender, EventArgs e)
		{
			//IL_001f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0025: Invalid comparison between Unknown and I4
			//IL_00e6: Unknown result type (might be due to invalid IL or missing references)
			LicensingForm licensingForm = new LicensingForm(_asm, _memberOfStudio, _webProduct, _mobileProduct);
			if ((int)((Form)licensingForm).ShowDialog() == 1)
			{
				8 10 = 9.1W(licensingForm._licenseKey, _asm, null, Z9: true);
				if (10.H3)
				{
					((Control)labCustomerName).Text = 10.H6;
					((Control)labCustomerCompany).Text = 10.H7;
					((Control)labCustomerName).Visible = true;
					((Control)labCustomerCompany).Visible = true;
					((Control)labEvaluationMsg1).Visible = false;
					((Control)labEvaluationMsg2).Visible = false;
					((Control)labSubscriptionExpired).Visible = false;
					((Control)labEvalExpired).Visible = false;
					if (_newLicense != null)
					{
						_newLicense.Dispose();
					}
					_newLicense = new 6(licensingForm._licenseKey);
					MessageBox.Show(licensingForm._info, licensingForm._caption, (MessageBoxButtons)0, (MessageBoxIcon)64);
				}
			}
			((Component)(object)licensingForm).Dispose();
		}

		private void btnRegister_Click(object sender, EventArgs e)
		{
			Process.Start("http://www.componentone.com/userpage/DesktopDefault.aspx?tabindex=0&tabsubindex=2&tabid=9");
		}

		private void btnPurchase_Click(object sender, EventArgs e)
		{
			Process.Start("http://www.componentone.com/pages.aspx?pagesid=60");
		}

		private void SafeNavigate()
		{
			if (_linkURL != null)
			{
				Process.Start(_linkURL);
			}
		}

		private void SetLinkURL(object sender)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0007: Expected O, but got Unknown
			//IL_0025: Unknown result type (might be due to invalid IL or missing references)
			//IL_002a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			//IL_0038: Unknown result type (might be due to invalid IL or missing references)
			LinkLabel val = (LinkLabel)sender;
			string text = (string)((Control)val).Tag;
			if (text == null || text.Length == 0)
			{
				string text2 = ((Control)val).Text;
				LinkArea linkArea = val.LinkArea;
				int start = ((LinkArea)(ref linkArea)).Start;
				linkArea = val.LinkArea;
				text = text2.Substring(start, ((LinkArea)(ref linkArea)).Length);
			}
			if (text.Length > 0)
			{
				_linkURL = text;
			}
			else
			{
				_linkURL = null;
			}
		}

		private void link_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
		{
			e.Link.Visited = true;
			SetLinkURL(sender);
			try
			{
				SafeNavigate();
			}
			catch (SecurityException)
			{
			}
		}

		private void Copy_Click(object sender, EventArgs e)
		{
			if (_linkURL != null)
			{
				Clipboard.SetDataObject((object)_linkURL, true);
			}
		}

		private void link_MouseEnter(object sender, EventArgs e)
		{
			SetLinkURL(sender);
		}
	}
	internal class 0
	{
		internal const string FR = "eval";

		internal const string FS = "int";

		internal const string FT = "ComponentOne LLC";

		internal const string FU = "(unknown)";

		internal const string FV = "devenv.exe.config";

		internal const string FW = "webmatrix.exe.config";

		internal const string FX = "bds.exe.config";

		internal const string FY = "724E8A91-AF12-4a3b-9AEB-EF89612E692E";

		internal const string FZ = "1";

		internal const string G0 = "?subject=";

		internal const string G1 = "Licenses";

		internal const string G2 = "http://www.componentone.com/default.aspx";

		internal const string G3 = "http://www.componentone.com/Download.aspx?DownloadCode=1";

		internal const string G4 = "http://www.componentone.com/pages.aspx?pagesid=52";

		internal const string G5 = "http://www.store.yahoo.com/componentone-llc/";

		internal const string G6 = "http://www.componentone.com/resellers.aspx?ResellerCode=1";

		internal const string G7 = "http://www.componentone.com/pages.aspx?pagesID=31";

		internal const string G8 = "http://www.componentone.com/Support.aspx?SupportCode=1";

		internal const string G9 = "http://www.componentone.com/userpage/DesktopDefault.aspx?tabindex=0&tabsubindex=2&tabid=9";

		internal const string GA = "http://www.componentone.com/pages.aspx?pagesid=60";

		internal const string GB = "http://www.componentone.com/userpage/DesktopDefault.aspx?tabindex=0&tabsubindex=3&tabid=9";

		internal const string GC = "21B11D57-9478-420e-A2B2-4C6AAEF98E46";

		internal const string GD = "08F7D405-7096-4b5f-A288-F749B8C83E6A";

		internal const string GE = "5C114645-719C-4545-891F-1DE9152952A4";

		internal const string GF = ".NET";

		internal const string GG = "ASP.NET";

		internal const string GH = "Mobile Devices";
	}
	[AttributeUsage(AttributeTargets.Assembly, Inherited = false, AllowMultiple = false)]
	internal class 1 : Attribute
	{
		private string GI;

		private string GJ;

		private bool GK = false;

		internal string W5 => GI;

		internal string W6 => GJ;

		internal bool W7 => GK;

		public 1(string productCode, string productGUID)
		{
			GI = productCode;
			GJ = productGUID;
		}

		public 1(string productCode, string productGUID, bool alwaysDesignTime)
			: this(productCode, productGUID)
		{
			GK = alwaysDesignTime;
		}
	}
	[AttributeUsage(AttributeTargets.Assembly, Inherited = false, AllowMultiple = false)]
	internal class 2 : Attribute
	{
		private string GL;

		internal string W8 => GL;

		public 2(string studioGUID)
		{
			GL = studioGUID;
		}
	}
	[AttributeUsage(AttributeTargets.Assembly, Inherited = false, AllowMultiple = false)]
	internal class 3 : Attribute
	{
	}
	[AttributeUsage(AttributeTargets.Assembly, Inherited = false, AllowMultiple = true)]
	internal class 4 : Attribute
	{
		private string GM;

		private string GN;

		internal string W9 => GM;

		internal string WA => GN;

		public 4(string code, string guid)
		{
			GM = code;
			GN = guid;
		}
	}
	[AttributeUsage(AttributeTargets.Assembly, Inherited = false, AllowMultiple = false)]
	internal class 5 : Attribute
	{
		private string GO;

		private string GP;

		private string GQ;

		internal string WB => GO;

		internal string WC => GP;

		internal string WD => GQ;

		public 5(string supportURL, string newsgroupURL, string updatesURL)
		{
			if (supportURL != null)
			{
				GO = supportURL;
			}
			else
			{
				GO = "";
			}
			if (newsgroupURL != null)
			{
				GP = newsgroupURL;
			}
			else
			{
				GP = "";
			}
			if (updatesURL != null)
			{
				GQ = updatesURL;
			}
			else
			{
				GQ = "";
			}
		}
	}
	internal class 6 : License
	{
		private string GR;

		private int GS;

		private int GT;

		private bool GU = false;

		public override string LicenseKey => GR;

		public bool WE => GU;

		public int WF => GS;

		public int WG => GT;

		internal 6(string licenseKey)
		{
			GR = licenseKey;
		}

		internal 6(string licenseKey, int year, int quarter)
		{
			GR = licenseKey;
			GS = year;
			GT = quarter;
			GU = true;
		}

		public override void Dispose()
		{
		}
	}
	internal enum 7
	{
		GV,
		GW,
		GX,
		GY,
		GZ,
		H0,
		H1,
		H2
	}
	internal sealed class 8
	{
		public bool H3 = false;

		public 7 H4;

		public bool H5;

		public string H6;

		public string H7;

		public int H8 = 0;

		public int H9 = 0;

		public bool HA = false;

		public bool HB = false;
	}
	internal class ProviderInfo : LicenseProvider
	{
		public override License GetLicense(LicenseContext context, Type type, object instance, bool allowExceptions)
		{
			return 9.1V(Assembly.GetExecutingAssembly(), LicenseManager.CurrentContext, type, instance);
		}

		internal static 8 ParseLicenseKey(string licenseKey)
		{
			Assembly executingAssembly = Assembly.GetExecutingAssembly();
			1 z = (1)Attribute.GetCustomAttribute(executingAssembly, typeof(1));
			bool flag = 9.1U(executingAssembly, LicenseManager.CurrentContext, z);
			8 10 = 9.1W(licenseKey, executingAssembly, null, flag);
			10.HB = !flag && (object)Assembly.GetEntryAssembly() == null;
			return 10;
		}

		internal static 8 Validate(Type type, object instance)
		{
			return 9.1X(type, instance);
		}

		internal static void ShowAboutBox(object instance)
		{
			9.1Y(instance);
		}
	}
	internal class 9
	{
		internal struct A
		{
			public string HO;

			public int HP;

			public int HQ;

			public int HR;

			public int HS;

			public int HT;
		}

		private const int HC = 2;

		private static bool HD;

		private static Hashtable HE;

		private static MethodInfo HF;

		private static object HG;

		private static MemoryStream HH;

		private static int HI;

		private static uint[] HJ;

		private static uint[] HK;

		internal static string HL;

		private static StringBuilder HM;

		internal static int HN;

		internal static Image 1E(object XS)
		{
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0044: Expected O, but got Unknown
			if (HI == 0)
			{
				if (!typeof(Bitmap).Assembly.FullName.StartsWith("System.CF.Drawing"))
				{
					HI = -1;
				}
				else
				{
					HI = 1;
				}
			}
			if (HI == -1)
			{
				return (Image)XS;
			}
			if ((object)HF == null)
			{
				MethodInfo[] methods = XS.GetType().GetMethods();
				for (int i = 0; i < methods.Length; i++)
				{
					if (methods[i].Name == "Save")
					{
						ParameterInfo[] parameters = methods[i].GetParameters();
						if (parameters.Length == 2 && parameters[0].Name == "stream" && parameters[1].Name == "format")
						{
							HF = methods[i];
							HG = parameters[1].ParameterType.GetProperty("Png", BindingFlags.Static | BindingFlags.Public).GetValue(null, new object[0]);
							break;
						}
					}
				}
				HH = new MemoryStream();
			}
			HF.Invoke(XS, new object[2] { HH, HG });
			return Image.FromStream((Stream)HH);
		}

		private static 6 1F(object XT, 1 XU)
		{
			if (XT is C)
			{
				string ZL = ((C)XT).2B();
				if (ZL != null && ZL.Length == 24)
				{
					byte[] array = Convert.FromBase64String(ZL);
					char[] array2 = (char[])Array.CreateInstance(typeof(char), array.Length / 2);
					int num = 0;
					for (int i = 0; i < array.Length; i += 2)
					{
						array2[num] = (char)(array[i] + (array[i + 1] << 8));
						num++;
					}
					string w = XU.W5;
					string zK = 0.8652559794322651.ToString(CultureInfo.InvariantCulture).Substring(2, 8);
					if (22(new string(array2), zK, ref ZL) && ZL.Substring(0, 2).Equals(w.Substring(0, 2)))
					{
						return new 6("int");
					}
				}
			}
			return null;
		}

		private static Hashtable 1G(Stream XV, string XW)
		{
			IFormatter formatter = new BinaryFormatter();
			object obj = formatter.Deserialize(XV);
			if (obj is object[])
			{
				object[] array = (object[])obj;
				if (array[0] is string && (string)array[0] == XW)
				{
					return (Hashtable)array[1];
				}
			}
			return null;
		}

		private static Hashtable 1H(Assembly XX, Type XY, string XZ, string Y0)
		{
			Stream stream = null;
			if (Y0 != null)
			{
				stream = XX.GetManifestResourceStream(Y0);
			}
			else
			{
				string text = XZ + ".licenses";
				stream = XX.GetManifestResourceStream(text);
				if (stream == null)
				{
					CompareInfo compareInfo = CultureInfo.InvariantCulture.CompareInfo;
					string[] manifestResourceNames = XX.GetManifestResourceNames();
					for (int i = 0; i < manifestResourceNames.Length; i++)
					{
						if (compareInfo.Compare(manifestResourceNames[i], text, CompareOptions.IgnoreCase) == 0)
						{
							stream = XX.GetManifestResourceStream(manifestResourceNames[i]);
							break;
						}
					}
				}
			}
			if (stream != null)
			{
				return 1G(stream, XZ.ToUpper(CultureInfo.InvariantCulture));
			}
			return null;
		}

		internal static Hashtable 1I(Assembly Y1, Type Y2, bool Y3)
		{
			if ((object)Y1 != null && !(Y1 is AssemblyBuilder))
			{
				string fullName = Y1.FullName;
				fullName = fullName.Substring(0, fullName.IndexOf(", Version="));
				fullName = ((!Y3) ? (fullName + ".dll") : (fullName + ".exe"));
				return 1H(Y1, Y2, fullName, null);
			}
			return null;
		}

		internal static Hashtable 1J(Assembly Y4, Type Y5, object Y6)
		{
			CompareInfo compareInfo = CultureInfo.InvariantCulture.CompareInfo;
			Assembly[] assemblies = Thread.GetDomain().GetAssemblies();
			string name = Y4.GetName().Name;
			try
			{
				Assembly[] array = assemblies;
				foreach (Assembly assembly in array)
				{
					if (assembly is AssemblyBuilder || 1M(Y6, assembly, YG: false))
					{
						continue;
					}
					AssemblyName[] referencedAssemblies = assembly.GetReferencedAssemblies();
					AssemblyName[] array2 = referencedAssemblies;
					foreach (AssemblyName assemblyName in array2)
					{
						if (compareInfo.Compare(assemblyName.Name, name, CompareOptions.IgnoreCase) != 0)
						{
							continue;
						}
						string codeBase = assembly.CodeBase;
						string text = codeBase.Substring(codeBase.LastIndexOf('/') + 1);
						string @string = text + ".licenses";
						string[] manifestResourceNames = assembly.GetManifestResourceNames();
						for (int k = 0; k < manifestResourceNames.Length; k++)
						{
							if (compareInfo.Compare(manifestResourceNames[k], @string, CompareOptions.IgnoreCase) == 0)
							{
								Hashtable hashtable = 1H(assembly, Y5, text, manifestResourceNames[k]);
								if (hashtable == null)
								{
									break;
								}
								return hashtable;
							}
						}
						break;
					}
				}
			}
			catch (SecurityException)
			{
			}
			return null;
		}

		private static 6 1K(string Y7, Assembly Y8)
		{
			if (Y7 != null)
			{
				8 10 = 1W(Y7, Y8, null, Z9: false);
				switch (10.H4)
				{
				case 7.GX:
				case 7.GY:
				case 7.GZ:
				case 7.H0:
					return new 6(Y7);
				}
			}
			return null;
		}

		private static 6 1L(string Y9, Assembly YA, object YB, Assembly YC, Assembly YD)
		{
			//IL_0043: Unknown result type (might be due to invalid IL or missing references)
			6 10 = 1K(Y9, YA);
			if (10 != null)
			{
				return 10;
			}
			if (!HD && ((object)YC != null || ((object)YD != null && YD.Equals(Assembly.GetAssembly(typeof(object))))))
			{
				AboutForm aboutForm = new AboutForm(YA, YB, designTime: false);
				HD = true;
				((Form)aboutForm).ShowDialog();
				((Component)(object)aboutForm).Dispose();
			}
			return new 6("eval");
		}

		private static bool 1M(object YE, Assembly YF, bool YG)
		{
			if (YE != null)
			{
				Assembly assembly = YE.GetType().Assembly;
				if ((object)assembly == YF)
				{
					if (!YG)
					{
						return true;
					}
					AssemblyCompanyAttribute assemblyCompanyAttribute = (AssemblyCompanyAttribute)Attribute.GetCustomAttribute(assembly, typeof(AssemblyCompanyAttribute));
					if (assemblyCompanyAttribute != null)
					{
						return !"ComponentOne LLC".Equals(assemblyCompanyAttribute.Company);
					}
					return true;
				}
			}
			return false;
		}

		private static string 1N(string YH)
		{
			int num = YH.IndexOf(", Version=");
			if (num == -1)
			{
				return YH;
			}
			int num2 = YH.IndexOf(',', num + 10);
			if (num2 == -1)
			{
				num2 = YH.Length;
			}
			int num3 = 0;
			for (int i = num + 10; i < num2; i++)
			{
				if (YH[i] == '.')
				{
					num3++;
					if (num3 == 3)
					{
						return YH.Remove(i, num2 - i);
					}
				}
			}
			return YH;
		}

		private static string 1O(string YI, Hashtable YJ)
		{
			IDictionaryEnumerator enumerator = YJ.GetEnumerator();
			while (enumerator.MoveNext())
			{
				if (enumerator.Key is string)
				{
					string text = 1N((string)enumerator.Key);
					if (text == YI)
					{
						return (string)enumerator.Value;
					}
				}
			}
			return null;
		}

		private static 6 1P(LicenseContext YK, Assembly YL, Type YM, object YN, bool YO)
		{
			string text = null;
			string yI = 1N(YM.AssemblyQualifiedName);
			Assembly entryAssembly = Assembly.GetEntryAssembly();
			Assembly assembly = null;
			if (YN is B)
			{
				assembly = ((B)YN).GetCallingAssembly();
			}
			bool flag = false;
			lock (typeof(9))
			{
				if (HE != null)
				{
					text = 1O(yI, HE);
					if (text != null)
					{
						flag = true;
					}
				}
				else
				{
					AppDomain currentDomain = AppDomain.CurrentDomain;
					if (currentDomain.SetupInformation.LicenseFile != null)
					{
						text = YK.GetSavedLicenseKey(YM, null);
						flag = true;
					}
					else if (Attribute.GetCustomAttribute(YL, typeof(3)) != null)
					{
						string text2 = ConfigurationSettings.AppSettings["License File"];
						if (text2 != null)
						{
							try
							{
								currentDomain.SetData("LICENSE_FILE", text2);
								text = YK.GetSavedLicenseKey(YM, null);
							}
							finally
							{
								currentDomain.SetData("LICENSE_FILE", null);
							}
						}
						flag = true;
					}
				}
				if (!flag)
				{
					if (HE == null && (object)entryAssembly != null)
					{
						HE = 1I(entryAssembly, YM, Y3: true);
						if (HE != null)
						{
							text = 1O(yI, HE);
							if (text != null)
							{
								flag = true;
							}
						}
						else
						{
							HE = new Hashtable();
						}
					}
					if (!flag)
					{
						if ((object)assembly != null && !1M(YN, assembly, YG: true))
						{
							Hashtable hashtable = 1I(assembly, YM, Y3: false);
							if (hashtable != null)
							{
								text = 1O(yI, hashtable);
								if (text != null)
								{
									flag = true;
								}
							}
						}
						if (!flag && HE == null)
						{
							HE = 1J(YL, YM, YN);
							if (HE != null)
							{
								text = 1O(yI, HE);
							}
							else
							{
								HE = new Hashtable();
							}
						}
					}
				}
			}
			if (YO)
			{
				return 1K(text, YL);
			}
			return 1L(text, YL, YN, entryAssembly, assembly);
		}

		internal static string 1Q(object YP)
		{
			if (YP is string)
			{
				return (string)YP;
			}
			return null;
		}

		private static void 1R(ref 6 YQ, string YR, int YS, int YT)
		{
			if (YQ == null || (YQ.WF <= YS && (YQ.WF != YS || YQ.WG < YT)))
			{
				YQ = new 6(YR, YS, YT);
			}
		}

		private static 6 1S(Assembly YU, 1 YV)
		{
			RegistryKey registryKey = Registry.ClassesRoot.OpenSubKey("Licenses");
			if (registryKey == null)
			{
				return null;
			}
			6 YQ = null;
			2 10 = (2)Attribute.GetCustomAttribute(YU, typeof(2));
			string text = ((10 == null) ? string.Empty : 10.W8);
			RegistryKey registryKey2;
			if (text.Equals("21B11D57-9478-420e-A2B2-4C6AAEF98E46") || text.Equals("08F7D405-7096-4b5f-A288-F749B8C83E6A") || text.Equals("5C114645-719C-4545-891F-1DE9152952A4"))
			{
				registryKey2 = registryKey.OpenSubKey("724E8A91-AF12-4a3b-9AEB-EF89612E692E");
				if (registryKey2 != null)
				{
					object value = registryKey2.GetValue("1");
					if (value is byte[])
					{
						byte[] array = (byte[])value;
						int num = array.Length / 2;
						char[] array2 = (char[])Array.CreateInstance(typeof(char), num);
						for (int i = 0; i < num; i++)
						{
							array2[i] = (char)((array[i + i + 1] << 8) + array[i + i]);
						}
						string text2 = new string(array2);
						8 11 = 1W(text2, YU, null, Z9: true);
						if (11.H4 == 7.GZ)
						{
							if (!11.H5)
							{
								return new 6(text2);
							}
							YQ = new 6(text2, 11.H8, 11.H9);
						}
					}
				}
				registryKey2 = registryKey.OpenSubKey(text);
				if (registryKey2 != null)
				{
					string text2 = 1Q(registryKey2.GetValue(""));
					if (text2 != null)
					{
						8 12 = 1W(text2, YU, null, Z9: true);
						if (12.H4 == 7.GY)
						{
							if (!12.H5)
							{
								return new 6(text2);
							}
							1R(ref YQ, text2, 12.H8, 12.H9);
						}
					}
				}
			}
			registryKey2 = registryKey.OpenSubKey(YV.W6);
			if (registryKey2 != null)
			{
				string text2 = 1Q(registryKey2.GetValue(""));
				if (text2 != null)
				{
					8 13 = 1W(text2, YU, YV.W5, Z9: true);
					if (13.H4 == 7.GX)
					{
						if (!13.H5)
						{
							return new 6(text2);
						}
						1R(ref YQ, text2, 13.H8, 13.H9);
					}
				}
			}
			4[] array3 = (4[])YU.GetCustomAttributes(typeof(4), inherit: false);
			4[] array4 = array3;
			foreach (4 14 in array4)
			{
				registryKey2 = registryKey.OpenSubKey(14.WA);
				if (registryKey2 == null)
				{
					continue;
				}
				string text2 = 1Q(registryKey2.GetValue(""));
				if (text2 == null)
				{
					continue;
				}
				8 15 = 1W(text2, YU, 14.W9, Z9: true);
				if (15.H4 == 7.H0)
				{
					if (!15.H5)
					{
						return new 6(text2);
					}
					1R(ref YQ, text2, 15.H8, 15.H9);
				}
			}
			return YQ;
		}

		internal static 6 1T(Assembly YW, Type YX, object YY)
		{
			string y = null;
			lock (typeof(9))
			{
				Hashtable hashtable = 1I(((B)YY).GetCallingAssembly(), YX, Y3: false);
				if (hashtable != null)
				{
					y = 1O(1N(YX.AssemblyQualifiedName), hashtable);
				}
			}
			return 1K(y, YW);
		}

		internal static bool 1U(Assembly YZ, LicenseContext Z0, 1 Z1)
		{
			if (Z1.W7 || Z0.UsageMode == LicenseUsageMode.Designtime)
			{
				return true;
			}
			string text = "";
			try
			{
				text = AppDomain.CurrentDomain.SetupInformation.ConfigurationFile;
			}
			catch (SecurityException)
			{
			}
			int num = text.LastIndexOf('\\');
			string str;
			if (num != -1 && (str = text.Substring(num + 1).ToLower(CultureInfo.InvariantCulture)) != null)
			{
				str = string.IsInterned(str);
				if ((object)str == "devenv.exe.config" || (object)str == "webmatrix.exe.config" || (object)str == "bds.exe.config")
				{
					return true;
				}
			}
			return false;
		}

		internal static 6 1V(Assembly Z2, LicenseContext Z3, Type Z4, object Z5)
		{
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0043: Expected O, but got Unknown
			//IL_00b1: Unknown result type (might be due to invalid IL or missing references)
			6 10 = null;
			1 11 = (1)Attribute.GetCustomAttribute(Z2, typeof(1));
			bool flag = 1U(Z2, Z3, 11);
			10 = 1F(Z5, 11);
			if (10 != null)
			{
				return 10;
			}
			if (!flag)
			{
				return 1P(Z3, Z2, Z4, Z5, YO: false);
			}
			try
			{
				RegistryPermission val = new RegistryPermission(PermissionState.Unrestricted);
				((CodeAccessPermission)val).Demand();
			}
			catch (SecurityException)
			{
				return null;
			}
			10 = 1S(Z2, 11);
			bool flag2 = 10 == null;
			if (!flag2)
			{
				flag2 |= 10.WE;
			}
			if (flag2)
			{
				if (Z5 is B && !1M(Z5, Z2, YG: true))
				{
					6 12 = 1T(Z2, Z4, Z5);
					if (12 != null)
					{
						return 12;
					}
				}
				if (!HD)
				{
					AboutForm aboutForm = new AboutForm(Z2, Z5, designTime: true);
					HD = true;
					((Form)aboutForm).ShowDialog();
					if (aboutForm._newLicense != null)
					{
						10 = aboutForm._newLicense;
						aboutForm._newLicense = null;
						flag2 = false;
					}
					((Component)(object)aboutForm).Dispose();
				}
				if (10 == null)
				{
					return new 6("eval");
				}
			}
			if (!flag2)
			{
				Z3.SetSavedLicenseKey(Z4, 10.LicenseKey);
			}
			return 10;
		}

		internal static 8 1W(string Z6, Assembly Z7, string Z8, bool Z9)
		{
			8 10 = new 8();
			if (Z6 == null || Z6.Length == 0 || Z6.Equals("eval"))
			{
				10.H3 = false;
				10.H4 = 7.GW;
				10.H5 = 24(Z7);
				10.H6 = "";
				10.H7 = "";
			}
			else if (Z6.Equals("int"))
			{
				10.H3 = true;
				10.H4 = 7.H1;
				10.H5 = false;
				10.H6 = "(unknown)";
				10.H7 = "ComponentOne LLC";
			}
			else
			{
				string ZL = "";
				bool flag = false;
				if (22(Z6, HL, ref ZL) && ZL.Length >= 9)
				{
					A a = 1Z(Z7);
					10.H8 = int.Parse(ZL.Substring(3, 2), CultureInfo.InvariantCulture) + 2000;
					10.H9 = int.Parse(ZL.Substring(2, 1), CultureInfo.InvariantCulture);
					bool flag2 = true;
					bool flag3 = false;
					bool flag4 = false;
					2 11 = (2)Attribute.GetCustomAttribute(Z7, typeof(2));
					if (11 == null)
					{
						flag2 = false;
					}
					else if ("08F7D405-7096-4b5f-A288-F749B8C83E6A".Equals(11.W8))
					{
						flag3 = true;
					}
					else if ("5C114645-719C-4545-891F-1DE9152952A4".Equals(11.W8))
					{
						flag4 = true;
					}
					else if (!"21B11D57-9478-420e-A2B2-4C6AAEF98E46".Equals(11.W8))
					{
						flag2 = false;
					}
					if (Z8 == null && flag2 && (ZL.StartsWith("SE") || (!flag3 && !flag4 && ZL.StartsWith("S8")) || (flag3 && ZL.StartsWith("S9")) || (flag4 && ZL.StartsWith("SM"))))
					{
						if (ZL.StartsWith("SE"))
						{
							10.H4 = 7.GZ;
						}
						else
						{
							10.H4 = 7.GY;
						}
						flag = true;
					}
					else
					{
						string w = ((1)Attribute.GetCustomAttribute(Z7, typeof(1))).W5;
						if (ZL.Substring(0, 2).Equals(w.Substring(0, 2)) && (Z8 == null || ZL.Substring(0, 2).Equals(Z8.Substring(0, 2))))
						{
							10.H4 = 7.GX;
							flag = true;
						}
					}
					if (!flag)
					{
						4[] array = (4[])Z7.GetCustomAttributes(typeof(4), inherit: false);
						4[] array2 = array;
						foreach (4 12 in array2)
						{
							if (ZL.Substring(0, 2).Equals(12.W9.Substring(0, 2)) && (Z8 == null || ZL.Substring(0, 2).Equals(Z8.Substring(0, 2))))
							{
								10.H4 = 7.H0;
								flag = true;
								break;
							}
						}
					}
					if (flag)
					{
						10.H5 = Z9 && a.HS * 4 + a.HT > 10.H8 * 4 + 10.H9 + 4;
						10.H3 = !10.H5;
						int num = 5;
						10.H6 = ZL.Substring(num + 1, ZL[num]);
						num += ZL[num] + 1;
						10.H7 = ZL.Substring(num + 1, ZL[num]);
					}
				}
				if (!flag)
				{
					10.H3 = false;
					10.H4 = 7.GW;
					10.H5 = 24(Z7);
					10.H6 = "";
					10.H7 = "";
				}
			}
			return 10;
		}

		internal static 8 1X(Type ZA, object ZB)
		{
			Assembly executingAssembly = Assembly.GetExecutingAssembly();
			LicenseContext currentContext = LicenseManager.CurrentContext;
			6 10 = 1V(executingAssembly, currentContext, ZA, ZB);
			if (10 == null)
			{
				throw new LicenseException(ZA, ZB);
			}
			1 z = (1)Attribute.GetCustomAttribute(executingAssembly, typeof(1));
			bool flag = 1U(executingAssembly, currentContext, z);
			8 11 = 1W(10.LicenseKey, executingAssembly, null, flag);
			10.Dispose();
			if (!flag)
			{
				Assembly entryAssembly = Assembly.GetEntryAssembly();
				Assembly assembly = null;
				if (ZB is B)
				{
					assembly = ((B)ZB).GetCallingAssembly();
				}
				11.HA = (object)entryAssembly == null && (object)assembly != null && assembly.Equals(Assembly.GetAssembly(typeof(object)));
				11.HB = (object)entryAssembly == null && !11.HA;
			}
			return 11;
		}

		internal static void 1Y(object ZC)
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_000d: Expected O, but got Unknown
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			Assembly executingAssembly = Assembly.GetExecutingAssembly();
			try
			{
				RegistryPermission val = new RegistryPermission(PermissionState.Unrestricted);
				((CodeAccessPermission)val).Demand();
			}
			catch (SecurityException)
			{
				return;
			}
			AboutForm aboutForm = new AboutForm(executingAssembly, ZC, designTime: true);
			((Form)aboutForm).ShowDialog();
			((Component)(object)aboutForm).Dispose();
		}

		internal static A 1Z(Assembly ZD)
		{
			A result = new A
			{
				HO = ((AssemblyFileVersionAttribute)Attribute.GetCustomAttribute(ZD, typeof(AssemblyFileVersionAttribute))).Version
			};
			string[] array = result.HO.Split('.', ' ');
			result.HP = int.Parse(array[0], CultureInfo.InvariantCulture);
			result.HQ = int.Parse(array[1], CultureInfo.InvariantCulture);
			result.HR = int.Parse(array[3], CultureInfo.InvariantCulture);
			int num = int.Parse(array[2], CultureInfo.InvariantCulture);
			result.HS = num / 10;
			result.HT = num % 10;
			return result;
		}

		internal static void 20(string ZE, out uint ZF, out uint ZG)
		{
			uint num = 65535u;
			uint num2 = uint.MaxValue;
			if (ZE != null)
			{
				foreach (uint num3 in ZE)
				{
					num = (num >> 8) ^ HJ[(num3 ^ num) & 0xFF];
					num = (num >> 8) ^ HJ[((num3 >> 8) ^ num) & 0xFF];
					num2 = (num2 >> 8) ^ HK[(num3 ^ num2) & 0xFF];
					num2 = (num2 >> 8) ^ HK[((num3 >> 8) ^ num2) & 0xFF];
				}
			}
			ZF = ~num & 0xFFFF;
			ZG = ~num2;
		}

		internal static string 21(string ZH, string ZI)
		{
			if (ZH != null && ZH.Length > 0)
			{
				uint[] array = (uint[])Array.CreateInstance(typeof(uint), 256);
				uint num = 0u;
				uint num2 = 0u;
				uint num3 = 6u;
				uint num4 = 0u;
				char[] array2 = (char[])Array.CreateInstance(typeof(char), 6);
				uint[] array3 = (uint[])Array.CreateInstance(typeof(uint), 6);
				for (uint num5 = 0u; num5 < 256; num5++)
				{
					array[num5] = num5;
				}
				for (uint num5 = 0u; num5 < 256; num5++)
				{
					uint num6 = array[num5];
					num2 = (ZI[(int)num] + array[num5] + num2) & 0xFF;
					array[num5] = array[num2];
					array[num2] = num6;
					num = (num + 1) % (uint)ZI.Length;
				}
				20(ZH, out var ZF, out var ZG);
				array3[0] = ZF & 0xFF;
				array3[1] = ZF >> 8;
				array3[2] = ZG & 0xFF;
				array3[3] = (ZG >> 8) & 0xFF;
				array3[4] = (ZG >> 16) & 0xFF;
				array3[5] = ZG >> 24;
				array2[0] = (char)(array3[0] + 1);
				array2[1] = (char)(array3[1] + 1);
				array2[2] = (char)(array3[2] + 1);
				array2[3] = (char)(array3[3] + 1);
				array2[4] = (char)(array3[4] + 1);
				array2[5] = (char)(array3[5] + 1);
				for (uint num5 = 0u; num5 < 6; num5++)
				{
					num = array[num5 + 1];
					num4 = (num + num4) & 0xFF;
					num2 = (array[num5 + 1] = array[num4]);
					array[num4] = num;
					array2[num5] = (char)(array2[num5] + array[(num + num2) & 0xFF]);
				}
				num = 0u;
				num2 = 0u;
				for (uint num5 = 0u; num5 < 256; num5++)
				{
					uint num6 = array[num5];
					num2 = (array3[num] + array[num5] + num2) & 0xFF;
					array[num5] = array[num2];
					array[num2] = num6;
					num = (num + 1) % 6;
				}
				StringBuilder stringBuilder = new StringBuilder(ZH.Length);
				stringBuilder.Length = ZH.Length;
				for (uint num5 = 0u; num5 < stringBuilder.Length; num5++)
				{
					num3 = (num3 + 1) & 0xFF;
					num = array[num3];
					num4 = (num + num4) & 0xFF;
					num2 = (array[num3] = array[num4]);
					array[num4] = num;
					num = (num + num2) & 0xFF;
					uint num6 = ZH[(int)num5];
					if (num6 < 43776)
					{
						stringBuilder[(int)num5] = (char)(num6 + array[num]);
						continue;
					}
					if (num6 >= 44032)
					{
						stringBuilder[(int)num5] = (char)(num6 ^ array[num]);
						continue;
					}
					throw new Exception("Invalid character has occured!");
				}
				for (uint num5 = 0u; num5 < 256; num5++)
				{
					array[num5] = 0u;
				}
				return new string(array2) + stringBuilder.ToString();
			}
			return "";
		}

		internal static bool 22(string ZJ, string ZK, ref string ZL)
		{
			if (ZJ != null && ZJ.Length > 6)
			{
				uint[] array = (uint[])Array.CreateInstance(typeof(uint), 256);
				uint num = 0u;
				uint num2 = 0u;
				uint num3 = 6u;
				uint num4 = 0u;
				uint[] array2 = (uint[])Array.CreateInstance(typeof(uint), 6);
				for (uint num5 = 0u; num5 < 256; num5++)
				{
					array[num5] = num5;
				}
				for (uint num5 = 0u; num5 < 256; num5++)
				{
					uint num6 = array[num5];
					num2 = (ZK[(int)num] + array[num5] + num2) & 0xFF;
					array[num5] = array[num2];
					array[num2] = num6;
					num = (num + 1) % (uint)ZK.Length;
				}
				for (uint num5 = 0u; num5 < 6; num5++)
				{
					num = array[num5 + 1];
					num4 = (num + num4) & 0xFF;
					num2 = (array[num5 + 1] = array[num4]);
					array[num4] = num;
					array2[num5] = ZJ[(int)num5] - array[(num + num2) & 0xFF] - 1;
				}
				num = 0u;
				num2 = 0u;
				for (uint num5 = 0u; num5 < 256; num5++)
				{
					uint num6 = array[num5];
					num2 = (array2[num] + array[num5] + num2) & 0xFF;
					array[num5] = array[num2];
					array[num2] = num6;
					num = (num + 1) % 6;
				}
				StringBuilder stringBuilder = new StringBuilder(ZJ.Substring(6));
				for (uint num5 = 0u; num5 < stringBuilder.Length; num5++)
				{
					num3 = (num3 + 1) & 0xFF;
					num = array[num3];
					num4 = (num + num4) & 0xFF;
					num2 = (array[num3] = array[num4]);
					array[num4] = num;
					num = (num + num2) & 0xFF;
					uint num6 = stringBuilder[(int)num5];
					if (num6 < 44032)
					{
						stringBuilder[(int)num5] = (char)(num6 - array[num]);
					}
					else
					{
						stringBuilder[(int)num5] = (char)(num6 ^ array[num]);
					}
				}
				for (uint num5 = 0u; num5 < 256; num5++)
				{
					array[num5] = 0u;
				}
				ZL = stringBuilder.ToString();
				20(ZL, out num, out num2);
				if (num == array2[0] + (array2[1] << 8))
				{
					return num2 == array2[2] + (array2[3] << 8) + (array2[4] << 16) + (array2[5] << 24);
				}
				return false;
			}
			ZL = "";
			if (ZJ != null)
			{
				return ZJ.Length == 0;
			}
			return true;
		}

		static 9()
		{
			HD = false;
			HE = null;
			HF = null;
			HG = null;
			HH = null;
			HI = 0;
			HJ = new uint[256]
			{
				0u, 49345u, 49537u, 320u, 49921u, 960u, 640u, 49729u, 50689u, 1728u,
				1920u, 51009u, 1280u, 50625u, 50305u, 1088u, 52225u, 3264u, 3456u, 52545u,
				3840u, 53185u, 52865u, 3648u, 2560u, 51905u, 52097u, 2880u, 51457u, 2496u,
				2176u, 51265u, 55297u, 6336u, 6528u, 55617u, 6912u, 56257u, 55937u, 6720u,
				7680u, 57025u, 57217u, 8000u, 56577u, 7616u, 7296u, 56385u, 5120u, 54465u,
				54657u, 5440u, 55041u, 6080u, 5760u, 54849u, 53761u, 4800u, 4992u, 54081u,
				4352u, 53697u, 53377u, 4160u, 61441u, 12480u, 12672u, 61761u, 13056u, 62401u,
				62081u, 12864u, 13824u, 63169u, 63361u, 14144u, 62721u, 13760u, 13440u, 62529u,
				15360u, 64705u, 64897u, 15680u, 65281u, 16320u, 16000u, 65089u, 64001u, 15040u,
				15232u, 64321u, 14592u, 63937u, 63617u, 14400u, 10240u, 59585u, 59777u, 10560u,
				60161u, 11200u, 10880u, 59969u, 60929u, 11968u, 12160u, 61249u, 11520u, 60865u,
				60545u, 11328u, 58369u, 9408u, 9600u, 58689u, 9984u, 59329u, 59009u, 9792u,
				8704u, 58049u, 58241u, 9024u, 57601u, 8640u, 8320u, 57409u, 40961u, 24768u,
				24960u, 41281u, 25344u, 41921u, 41601u, 25152u, 26112u, 42689u, 42881u, 26432u,
				42241u, 26048u, 25728u, 42049u, 27648u, 44225u, 44417u, 27968u, 44801u, 28608u,
				28288u, 44609u, 43521u, 27328u, 27520u, 43841u, 26880u, 43457u, 43137u, 26688u,
				30720u, 47297u, 47489u, 31040u, 47873u, 31680u, 31360u, 47681u, 48641u, 32448u,
				32640u, 48961u, 32000u, 48577u, 48257u, 31808u, 46081u, 29888u, 30080u, 46401u,
				30464u, 47041u, 46721u, 30272u, 29184u, 45761u, 45953u, 29504u, 45313u, 29120u,
				28800u, 45121u, 20480u, 37057u, 37249u, 20800u, 37633u, 21440u, 21120u, 37441u,
				38401u, 22208u, 22400u, 38721u, 21760u, 38337u, 38017u, 21568u, 39937u, 23744u,
				23936u, 40257u, 24320u, 40897u, 40577u, 24128u, 23040u, 39617u, 39809u, 23360u,
				39169u, 22976u, 22656u, 38977u, 34817u, 18624u, 18816u, 35137u, 19200u, 35777u,
				35457u, 19008u, 19968u, 36545u, 36737u, 20288u, 36097u, 19904u, 19584u, 35905u,
				17408u, 33985u, 34177u, 17728u, 34561u, 18368u, 18048u, 34369u, 33281u, 17088u,
				17280u, 33601u, 16640u, 33217u, 32897u, 16448u
			};
			HK = new uint[256]
			{
				0u, 1996959894u, 3993919788u, 2567524794u, 124634137u, 1886057615u, 3915621685u, 2657392035u, 249268274u, 2044508324u,
				3772115230u, 2547177864u, 162941995u, 2125561021u, 3887607047u, 2428444049u, 498536548u, 1789927666u, 4089016648u, 2227061214u,
				450548861u, 1843258603u, 4107580753u, 2211677639u, 325883990u, 1684777152u, 4251122042u, 2321926636u, 335633487u, 1661365465u,
				4195302755u, 2366115317u, 997073096u, 1281953886u, 3579855332u, 2724688242u, 1006888145u, 1258607687u, 3524101629u, 2768942443u,
				901097722u, 1119000684u, 3686517206u, 2898065728u, 853044451u, 1172266101u, 3705015759u, 2882616665u, 651767980u, 1373503546u,
				3369554304u, 3218104598u, 565507253u, 1454621731u, 3485111705u, 3099436303u, 671266974u, 1594198024u, 3322730930u, 2970347812u,
				795835527u, 1483230225u, 3244367275u, 3060149565u, 1994146192u, 31158534u, 2563907772u, 4023717930u, 1907459465u, 112637215u,
				2680153253u, 3904427059u, 2013776290u, 251722036u, 2517215374u, 3775830040u, 2137656763u, 141376813u, 2439277719u, 3865271297u,
				1802195444u, 476864866u, 2238001368u, 4066508878u, 1812370925u, 453092731u, 2181625025u, 4111451223u, 1706088902u, 314042704u,
				2344532202u, 4240017532u, 1658658271u, 366619977u, 2362670323u, 4224994405u, 1303535960u, 984961486u, 2747007092u, 3569037538u,
				1256170817u, 1037604311u, 2765210733u, 3554079995u, 1131014506u, 879679996u, 2909243462u, 3663771856u, 1141124467u, 855842277u,
				2852801631u, 3708648649u, 1342533948u, 654459306u, 3188396048u, 3373015174u, 1466479909u, 544179635u, 3110523913u, 3462522015u,
				1591671054u, 702138776u, 2966460450u, 3352799412u, 1504918807u, 783551873u, 3082640443u, 3233442989u, 3988292384u, 2596254646u,
				62317068u, 1957810842u, 3939845945u, 2647816111u, 81470997u, 1943803523u, 3814918930u, 2489596804u, 225274430u, 2053790376u,
				3826175755u, 2466906013u, 167816743u, 2097651377u, 4027552580u, 2265490386u, 503444072u, 1762050814u, 4150417245u, 2154129355u,
				426522225u, 1852507879u, 4275313526u, 2312317920u, 282753626u, 1742555852u, 4189708143u, 2394877945u, 397917763u, 1622183637u,
				3604390888u, 2714866558u, 953729732u, 1340076626u, 3518719985u, 2797360999u, 1068828381u, 1219638859u, 3624741850u, 2936675148u,
				906185462u, 1090812512u, 3747672003u, 2825379669u, 829329135u, 1181335161u, 3412177804u, 3160834842u, 628085408u, 1382605366u,
				3423369109u, 3138078467u, 570562233u, 1426400815u, 3317316542u, 2998733608u, 733239954u, 1555261956u, 3268935591u, 3050360625u,
				752459403u, 1541320221u, 2607071920u, 3965973030u, 1969922972u, 40735498u, 2617837225u, 3943577151u, 1913087877u, 83908371u,
				2512341634u, 3803740692u, 2075208622u, 213261112u, 2463272603u, 3855990285u, 2094854071u, 198958881u, 2262029012u, 4057260610u,
				1759359992u, 534414190u, 2176718541u, 4139329115u, 1873836001u, 414664567u, 2282248934u, 4279200368u, 1711684554u, 285281116u,
				2405801727u, 4167216745u, 1634467795u, 376229701u, 2685067896u, 3608007406u, 1308918612u, 956543938u, 2808555105u, 3495958263u,
				1231636301u, 1047427035u, 2932959818u, 3654703836u, 1088359270u, 936918000u, 2847714899u, 3736837829u, 1202900863u, 817233897u,
				3183342108u, 3401237130u, 1404277552u, 615818150u, 3134207493u, 3453421203u, 1423857449u, 601450431u, 3009837614u, 3294710456u,
				1567103746u, 711928724u, 3020668471u, 3272380065u, 1510334235u, 755167117u
			};
			HL = "53087483046183F702FCF30639C89CB4";
			HM = null;
			HN = 0;
			char[] array = HL.ToCharArray();
			for (int i = 0; i < array.Length; i++)
			{
				array[i] = (char)(array[i] - 45);
			}
			HL = new string(array);
		}

		internal static 8 23(Assembly ZM, object ZN, bool ZO)
		{
			8 10 = 1W("eval", ZM, null, ZO);
			if (10.H4 == 7.GV)
			{
				return 10;
			}
			6 11 = null;
			if (!ZO)
			{
				if (ZN != null)
				{
					11 = 1P(LicenseManager.CurrentContext, ZM, ZN.GetType(), ZN, YO: true);
				}
			}
			else
			{
				1 yV = (1)Attribute.GetCustomAttribute(ZM, typeof(1));
				11 = 1S(ZM, yV);
				bool flag = 11 == null;
				if (!flag)
				{
					flag |= 11.WE;
				}
				if (flag && ZN is B && !1M(ZN, ZM, YG: true))
				{
					6 12 = 1T(ZM, ZN.GetType(), ZN);
					if (12 != null)
					{
						return 1W(12.LicenseKey, ZM, null, ZO);
					}
				}
			}
			if (11 != null)
			{
				return 1W(11.LicenseKey, ZM, null, ZO);
			}
			return 10;
		}

		internal static bool 24(Assembly ZP)
		{
			A a = 1Z(ZP);
			if (a.HS > 2000 && a.HS < 3000 && a.HT >= 1 && a.HT <= 4)
			{
				DateTime now = DateTime.Now;
				return now.Year * 12 + now.Month > a.HS * 12 + a.HT * 3 + 2;
			}
			return false;
		}

		internal static bool 25(string ZQ)
		{
			CompareInfo compareInfo = CultureInfo.InvariantCulture.CompareInfo;
			string @string = ZQ.Substring(2, 1);
			if (compareInfo.Compare(@string, "1") < 0 || compareInfo.Compare(@string, "4") > 0)
			{
				return false;
			}
			@string = ZQ.Substring(3, 1);
			if (compareInfo.Compare(@string, "0") < 0 || compareInfo.Compare(@string, "9") > 0)
			{
				return false;
			}
			@string = ZQ.Substring(4, 1);
			if (compareInfo.Compare(@string, "0") < 0 || compareInfo.Compare(@string, "9") > 0)
			{
				return false;
			}
			return ZQ.Substring(8, 2).Equals(29(ZQ.Substring(0, 7), ZQ.Substring(11, 6)));
		}

		internal static int 26(string ZR, Assembly ZS)
		{
			if (ZR.Length == 17 && ZR.StartsWith("SE") && 25(ZR))
			{
				A a = 1Z(ZS);
				int num = int.Parse(ZR.Substring(3, 2), CultureInfo.InvariantCulture) + 2000;
				int num2 = int.Parse(ZR.Substring(2, 1), CultureInfo.InvariantCulture);
				if (a.HS * 4 + a.HT <= num * 4 + num2 + 4)
				{
					return 0;
				}
				return 2;
			}
			return 1;
		}

		internal static int 27(string ZT, Assembly ZU, bool ZV, bool ZW)
		{
			if (ZT.Length == 17 && ((!ZV && !ZW && ZT.StartsWith("S8")) || (ZV && ZT.StartsWith("S9")) || (ZW && ZT.StartsWith("SM"))) && 25(ZT))
			{
				A a = 1Z(ZU);
				int num = int.Parse(ZT.Substring(3, 2), CultureInfo.InvariantCulture) + 2000;
				int num2 = int.Parse(ZT.Substring(2, 1), CultureInfo.InvariantCulture);
				if (a.HS * 4 + a.HT <= num * 4 + num2 + 4)
				{
					return 0;
				}
				return 2;
			}
			return 1;
		}

		internal static int 28(string ZX, Assembly ZY)
		{
			string w = ((1)Attribute.GetCustomAttribute(ZY, typeof(1))).W5;
			if (ZX.Length == 17 && ZX.Substring(0, 2).Equals(w.Substring(0, 2)) && 25(ZX))
			{
				A a = 1Z(ZY);
				int num = int.Parse(ZX.Substring(3, 2), CultureInfo.InvariantCulture) + 2000;
				int num2 = int.Parse(ZX.Substring(2, 1), CultureInfo.InvariantCulture);
				if (a.HS * 4 + a.HT <= num * 4 + num2 + 4)
				{
					return 0;
				}
				return 2;
			}
			return 1;
		}

		internal static string 29(string ZZ, string 000)
		{
			StringBuilder stringBuilder = new StringBuilder(ZZ);
			stringBuilder.Append(000);
			StringBuilder stringBuilder2 = new StringBuilder();
			if (HM == null)
			{
				2A();
			}
			for (int i = 0; i < 2; i++)
			{
				int num = 0;
				for (int j = 0; j < stringBuilder.Length; j++)
				{
					num += (j ^ (i + 1)) * stringBuilder[j];
				}
				stringBuilder2.Append(HM[num % HM.Length]);
			}
			return stringBuilder2.ToString();
		}

		private static void 2A()
		{
			HM = new StringBuilder("23456789ABCDEFGHJKLMNPQRSTUVWXY");
			int length = HM.Length;
			for (int i = 1; i < length; i++)
			{
				char value = HM[i - 1];
				int num = 0;
				for (int j = 1; j < length; j++)
				{
					if (i * j % length == 1)
					{
						num = j;
						break;
					}
				}
				if (i < num)
				{
					HM[i - 1] = HM[num - 1];
					HM[num - 1] = value;
				}
			}
		}
	}
	internal interface B
	{
		Assembly GetCallingAssembly();
	}
	internal interface C
	{
		string 2B();
	}
	internal class LicensingForm : Form
	{
		private Assembly _asm;

		private bool _memberOfStudio;

		private bool _webProduct;

		private bool _mobileProduct;

		private IContainer components;

		private Button btnCancel;

		private Button btnOk;

		private PictureBox pictureBox1;

		private TextBox edName;

		private TextBox edCompany;

		private TextBox edSerialNumber;

		private LinkLabel linkEULA;

		private Label _msgInvalidSerialNumber;

		private TextBox _msgArchaicProductKey;

		private Label _msgEmptyCustomerName;

		private Label _msgEmptyCompanyName;

		private ContextMenu contextMenu1;

		private MenuItem itemCopy;

		private ToolTip toolTip1;

		private TextBox _msgSerialNumberHasExpired;

		private Label labProductName;

		private Label labName;

		private Label labCompany;

		private Label labSerialNumber;

		private Label labPersonalInfo;

		private Label labHR;

		private Label labSNTitle;

		private Label _msgTooLongCustomerName;

		private Label _msgTooLongCompanyName;

		private Label _msgLicensedInfo;

		private Label _msgStudioEnterprise;

		private Label _msgStudioForDotNET;

		private Label _msgStudioForASPdotNET;

		private Label _msgStudioForMobileDevices;

		private Label _msgCongratulations;

		internal string _licenseKey = "";

		internal string _info;

		internal string _caption;

		internal LicensingForm()
			: this(Assembly.GetExecutingAssembly(), memberOfStudio: true, webProduct: false, mobileProduct: false)
		{
		}

		internal LicensingForm(Assembly asm, bool memberOfStudio, bool webProduct, bool mobileProduct)
		{
			InitializeComponent();
			F.2F((Control)(object)this, components);
			_asm = asm;
			_memberOfStudio = memberOfStudio;
			_webProduct = webProduct;
			_mobileProduct = mobileProduct;
			((Control)labProductName).Text = ((AssemblyProductAttribute)Attribute.GetCustomAttribute(asm, typeof(AssemblyProductAttribute))).Product;
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_001c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Expected O, but got Unknown
			//IL_0027: Unknown result type (might be due to invalid IL or missing references)
			//IL_0031: Expected O, but got Unknown
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0047: Expected O, but got Unknown
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			//IL_0052: Expected O, but got Unknown
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_005d: Expected O, but got Unknown
			//IL_005e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0068: Expected O, but got Unknown
			//IL_0069: Unknown result type (might be due to invalid IL or missing references)
			//IL_0073: Expected O, but got Unknown
			//IL_0074: Unknown result type (might be due to invalid IL or missing references)
			//IL_007e: Expected O, but got Unknown
			//IL_007f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0089: Expected O, but got Unknown
			//IL_008a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0094: Expected O, but got Unknown
			//IL_0095: Unknown result type (might be due to invalid IL or missing references)
			//IL_009f: Expected O, but got Unknown
			//IL_00a0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00aa: Expected O, but got Unknown
			//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b5: Expected O, but got Unknown
			//IL_00b6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c0: Expected O, but got Unknown
			//IL_00c1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00cb: Expected O, but got Unknown
			//IL_00cc: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d6: Expected O, but got Unknown
			//IL_00d7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e1: Expected O, but got Unknown
			//IL_00e2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ec: Expected O, but got Unknown
			//IL_00ed: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f7: Expected O, but got Unknown
			//IL_00fe: Unknown result type (might be due to invalid IL or missing references)
			//IL_0108: Expected O, but got Unknown
			//IL_0109: Unknown result type (might be due to invalid IL or missing references)
			//IL_0113: Expected O, but got Unknown
			//IL_0114: Unknown result type (might be due to invalid IL or missing references)
			//IL_011e: Expected O, but got Unknown
			//IL_011f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0129: Expected O, but got Unknown
			//IL_012a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0134: Expected O, but got Unknown
			//IL_0135: Unknown result type (might be due to invalid IL or missing references)
			//IL_013f: Expected O, but got Unknown
			//IL_0140: Unknown result type (might be due to invalid IL or missing references)
			//IL_014a: Expected O, but got Unknown
			//IL_014b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0155: Expected O, but got Unknown
			//IL_0156: Unknown result type (might be due to invalid IL or missing references)
			//IL_0160: Expected O, but got Unknown
			//IL_0161: Unknown result type (might be due to invalid IL or missing references)
			//IL_016b: Expected O, but got Unknown
			//IL_0194: Unknown result type (might be due to invalid IL or missing references)
			//IL_019e: Expected O, but got Unknown
			//IL_021b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0225: Expected O, but got Unknown
			//IL_0296: Unknown result type (might be due to invalid IL or missing references)
			//IL_02a0: Expected O, but got Unknown
			//IL_0307: Unknown result type (might be due to invalid IL or missing references)
			//IL_0311: Expected O, but got Unknown
			//IL_037b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0385: Expected O, but got Unknown
			//IL_03f0: Unknown result type (might be due to invalid IL or missing references)
			//IL_03fa: Expected O, but got Unknown
			//IL_0480: Unknown result type (might be due to invalid IL or missing references)
			//IL_048a: Expected O, but got Unknown
			//IL_0534: Unknown result type (might be due to invalid IL or missing references)
			//IL_053e: Expected O, but got Unknown
			//IL_05bc: Unknown result type (might be due to invalid IL or missing references)
			//IL_05c6: Expected O, but got Unknown
			//IL_068d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0697: Expected O, but got Unknown
			//IL_076f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0779: Expected O, but got Unknown
			//IL_07f8: Unknown result type (might be due to invalid IL or missing references)
			//IL_0802: Expected O, but got Unknown
			//IL_080c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0886: Unknown result type (might be due to invalid IL or missing references)
			//IL_0890: Expected O, but got Unknown
			components = new Container();
			ResourceManager resourceManager = new ResourceManager(typeof(LicensingForm));
			edName = new TextBox();
			edCompany = new TextBox();
			labName = new Label();
			labCompany = new Label();
			labSerialNumber = new Label();
			labPersonalInfo = new Label();
			btnOk = new Button();
			btnCancel = new Button();
			edSerialNumber = new TextBox();
			labHR = new Label();
			labProductName = new Label();
			pictureBox1 = new PictureBox();
			labSNTitle = new Label();
			linkEULA = new LinkLabel();
			contextMenu1 = new ContextMenu();
			itemCopy = new MenuItem();
			_msgEmptyCustomerName = new Label();
			_msgEmptyCompanyName = new Label();
			_msgInvalidSerialNumber = new Label();
			_msgArchaicProductKey = new TextBox();
			toolTip1 = new ToolTip(components);
			_msgSerialNumberHasExpired = new TextBox();
			_msgTooLongCustomerName = new Label();
			_msgTooLongCompanyName = new Label();
			_msgLicensedInfo = new Label();
			_msgStudioEnterprise = new Label();
			_msgStudioForDotNET = new Label();
			_msgStudioForASPdotNET = new Label();
			_msgStudioForMobileDevices = new Label();
			_msgCongratulations = new Label();
			((Control)this).SuspendLayout();
			((Control)edName).BackColor = SystemColors.Window;
			((Control)edName).Font = new Font("Verdana", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)edName).Location = new Point(140, 124);
			((Control)edName).Name = "edName";
			((Control)edName).Size = new Size(238, 21);
			((Control)edName).TabIndex = 7;
			((Control)edName).Text = "";
			((Control)edCompany).BackColor = SystemColors.Window;
			((Control)edCompany).Font = new Font("Verdana", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)edCompany).Location = new Point(140, 150);
			((Control)edCompany).Name = "edCompany";
			((Control)edCompany).Size = new Size(238, 21);
			((Control)edCompany).TabIndex = 9;
			((Control)edCompany).Text = "";
			((Control)labName).Font = new Font("Verdana", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)labName).Location = new Point(36, 126);
			((Control)labName).Name = "labName";
			((Control)labName).Size = new Size(92, 16);
			((Control)labName).TabIndex = 6;
			((Control)labName).Text = "Name:";
			((Control)labCompany).Font = new Font("Verdana", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)labCompany).Location = new Point(36, 152);
			((Control)labCompany).Name = "labCompany";
			((Control)labCompany).Size = new Size(92, 16);
			((Control)labCompany).TabIndex = 8;
			((Control)labCompany).Text = "Company:";
			((Control)labSerialNumber).Font = new Font("Verdana", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)labSerialNumber).Location = new Point(36, 208);
			((Control)labSerialNumber).Name = "labSerialNumber";
			((Control)labSerialNumber).Size = new Size(92, 16);
			((Control)labSerialNumber).TabIndex = 11;
			((Control)labSerialNumber).Text = "S/N:";
			((Control)labPersonalInfo).Font = new Font("Verdana", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)labPersonalInfo).Location = new Point(15, 100);
			((Control)labPersonalInfo).Name = "labPersonalInfo";
			((Control)labPersonalInfo).Size = new Size(313, 16);
			((Control)labPersonalInfo).TabIndex = 5;
			((Control)labPersonalInfo).Text = "Your personal information:";
			((Control)btnOk).BackColor = SystemColors.Control;
			((ButtonBase)btnOk).FlatStyle = (FlatStyle)0;
			((Control)btnOk).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)btnOk).Location = new Point(120, 259);
			((Control)btnOk).Name = "btnOk";
			((Control)btnOk).Size = new Size(90, 24);
			((Control)btnOk).TabIndex = 14;
			((Control)btnOk).Text = "OK";
			((Control)btnOk).Click += btnOk_Click;
			((Control)btnCancel).BackColor = SystemColors.Control;
			btnCancel.DialogResult = (DialogResult)2;
			((ButtonBase)btnCancel).FlatStyle = (FlatStyle)0;
			((Control)btnCancel).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)btnCancel).Location = new Point(222, 259);
			((Control)btnCancel).Name = "btnCancel";
			((Control)btnCancel).Size = new Size(90, 24);
			((Control)btnCancel).TabIndex = 15;
			((Control)btnCancel).Text = "Cancel";
			((Control)edSerialNumber).BackColor = SystemColors.Window;
			((Control)edSerialNumber).Font = new Font("Verdana", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)edSerialNumber).Location = new Point(140, 206);
			((Control)edSerialNumber).Name = "edSerialNumber";
			((Control)edSerialNumber).Size = new Size(238, 21);
			((Control)edSerialNumber).TabIndex = 12;
			((Control)edSerialNumber).Text = "";
			labHR.BorderStyle = (BorderStyle)1;
			((Control)labHR).Location = new Point(10, 244);
			((Control)labHR).Name = "labHR";
			((Control)labHR).Size = new Size(404, 3);
			((Control)labHR).TabIndex = 13;
			((Control)labProductName).Font = new Font("Verdana", 9.75f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)labProductName).Location = new Point(15, 16);
			((Control)labProductName).Name = "labProductName";
			((Control)labProductName).Size = new Size(317, 36);
			((Control)labProductName).TabIndex = 0;
			((Control)labProductName).Text = "ComponentOne Product Name";
			pictureBox1.Image = 9.1E(resourceManager.GetObject("pictureBox1.Image"));
			((Control)pictureBox1).Location = new Point(332, 4);
			((Control)pictureBox1).Name = "pictureBox1";
			((Control)pictureBox1).Size = new Size(84, 50);
			pictureBox1.TabIndex = 14;
			pictureBox1.TabStop = false;
			((Control)labSNTitle).Font = new Font("Verdana", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)labSNTitle).Location = new Point(15, 182);
			((Control)labSNTitle).Name = "labSNTitle";
			((Control)labSNTitle).Size = new Size(313, 16);
			((Control)labSNTitle).TabIndex = 10;
			((Control)labSNTitle).Text = "Studio or product serial number:";
			((Control)linkEULA).ContextMenu = contextMenu1;
			((Control)linkEULA).Font = new Font("Verdana", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			linkEULA.LinkArea = new LinkArea(16, 26);
			((Control)linkEULA).Location = new Point(15, 67);
			((Control)linkEULA).Name = "linkEULA";
			((Control)linkEULA).Size = new Size(399, 27);
			((Control)linkEULA).TabIndex = 4;
			((Label)linkEULA).TabStop = true;
			((Control)linkEULA).Text = "Please read the END-USER LICENSE AGREEMENT before proceeding.";
			linkEULA.LinkClicked += new LinkLabelLinkClickedEventHandler(linkEULA_LinkClicked);
			((Menu)contextMenu1).MenuItems.Add(itemCopy);
			itemCopy.Index = 0;
			itemCopy.Text = "Copy URL";
			itemCopy.Click += Copy_Click;
			((Control)_msgEmptyCustomerName).Enabled = false;
			((Control)_msgEmptyCustomerName).Location = new Point(471, 8);
			((Control)_msgEmptyCustomerName).Name = "_msgEmptyCustomerName";
			((Control)_msgEmptyCustomerName).Size = new Size(277, 16);
			((Control)_msgEmptyCustomerName).TabIndex = 18;
			((Control)_msgEmptyCustomerName).Text = "Customer Name field cannot be empty.";
			((Control)_msgEmptyCustomerName).Visible = false;
			((Control)_msgEmptyCompanyName).Enabled = false;
			((Control)_msgEmptyCompanyName).Location = new Point(471, 40);
			((Control)_msgEmptyCompanyName).Name = "_msgEmptyCompanyName";
			((Control)_msgEmptyCompanyName).Size = new Size(277, 16);
			((Control)_msgEmptyCompanyName).TabIndex = 18;
			((Control)_msgEmptyCompanyName).Text = "Company Name field cannot be empty.";
			((Control)_msgEmptyCompanyName).Visible = false;
			((Control)_msgInvalidSerialNumber).Enabled = false;
			((Control)_msgInvalidSerialNumber).Location = new Point(471, 72);
			((Control)_msgInvalidSerialNumber).Name = "_msgInvalidSerialNumber";
			((Control)_msgInvalidSerialNumber).Size = new Size(277, 16);
			((Control)_msgInvalidSerialNumber).TabIndex = 18;
			((Control)_msgInvalidSerialNumber).Text = "The specified serial number is not valid.";
			((Control)_msgInvalidSerialNumber).Visible = false;
			((Control)_msgArchaicProductKey).Enabled = false;
			((Control)_msgArchaicProductKey).Location = new Point(472, 156);
			((TextBoxBase)_msgArchaicProductKey).Multiline = true;
			((Control)_msgArchaicProductKey).Name = "_msgArchaicProductKey";
			((TextBoxBase)_msgArchaicProductKey).ReadOnly = true;
			((Control)_msgArchaicProductKey).Size = new Size(276, 52);
			((Control)_msgArchaicProductKey).TabIndex = 19;
			((Control)_msgArchaicProductKey).Text = "This license key is older than the one currently installed.\r\nYou cannot replace new key with the old one because\r\nsome new products may become unlicensed.";
			((Control)_msgArchaicProductKey).Visible = false;
			((Control)_msgSerialNumberHasExpired).Enabled = false;
			((Control)_msgSerialNumberHasExpired).Location = new Point(472, 96);
			((TextBoxBase)_msgSerialNumberHasExpired).Multiline = true;
			((Control)_msgSerialNumberHasExpired).Name = "_msgSerialNumberHasExpired";
			((TextBoxBase)_msgSerialNumberHasExpired).ReadOnly = true;
			((Control)_msgSerialNumberHasExpired).Size = new Size(276, 52);
			((Control)_msgSerialNumberHasExpired).TabIndex = 20;
			((Control)_msgSerialNumberHasExpired).Text = "Sorry, this serial number has expired. You can still use\r\nthe previous builds with the current license, or renew\r\nyour subscription to get a new license key.";
			((Control)_msgSerialNumberHasExpired).Visible = false;
			((Control)_msgTooLongCustomerName).Enabled = false;
			((Control)_msgTooLongCustomerName).Location = new Point(471, 24);
			((Control)_msgTooLongCustomerName).Name = "_msgTooLongCustomerName";
			((Control)_msgTooLongCustomerName).Size = new Size(277, 16);
			((Control)_msgTooLongCustomerName).TabIndex = 21;
			((Control)_msgTooLongCustomerName).Text = "Customer Name is too long.";
			((Control)_msgTooLongCustomerName).Visible = false;
			((Control)_msgTooLongCompanyName).Enabled = false;
			((Control)_msgTooLongCompanyName).Location = new Point(471, 56);
			((Control)_msgTooLongCompanyName).Name = "_msgTooLongCompanyName";
			((Control)_msgTooLongCompanyName).Size = new Size(277, 16);
			((Control)_msgTooLongCompanyName).TabIndex = 22;
			((Control)_msgTooLongCompanyName).Text = "Company Name is too long.";
			((Control)_msgTooLongCompanyName).Visible = false;
			((Control)_msgLicensedInfo).Enabled = false;
			((Control)_msgLicensedInfo).Location = new Point(472, 216);
			((Control)_msgLicensedInfo).Name = "_msgLicensedInfo";
			((Control)_msgLicensedInfo).Size = new Size(276, 16);
			((Control)_msgLicensedInfo).TabIndex = 23;
			((Control)_msgLicensedInfo).Text = "You have licensed {0} !";
			((Control)_msgLicensedInfo).Visible = false;
			((Control)_msgStudioEnterprise).Enabled = false;
			((Control)_msgStudioEnterprise).Location = new Point(472, 232);
			((Control)_msgStudioEnterprise).Name = "_msgStudioEnterprise";
			((Control)_msgStudioEnterprise).Size = new Size(276, 16);
			((Control)_msgStudioEnterprise).TabIndex = 24;
			((Control)_msgStudioEnterprise).Text = "ComponentOne Studio Enterprise(TM)";
			((Control)_msgStudioEnterprise).Visible = false;
			((Control)_msgStudioForDotNET).Enabled = false;
			((Control)_msgStudioForDotNET).Location = new Point(472, 248);
			((Control)_msgStudioForDotNET).Name = "_msgStudioForDotNET";
			((Control)_msgStudioForDotNET).Size = new Size(276, 16);
			((Control)_msgStudioForDotNET).TabIndex = 25;
			((Control)_msgStudioForDotNET).Text = "ComponentOne Studio(TM) for .NET";
			((Control)_msgStudioForDotNET).Visible = false;
			((Control)_msgStudioForASPdotNET).Enabled = false;
			((Control)_msgStudioForASPdotNET).Location = new Point(472, 264);
			((Control)_msgStudioForASPdotNET).Name = "_msgStudioForASPdotNET";
			((Control)_msgStudioForASPdotNET).Size = new Size(276, 16);
			((Control)_msgStudioForASPdotNET).TabIndex = 26;
			((Control)_msgStudioForASPdotNET).Text = "ComponentOne Studio(TM) for ASP.NET";
			((Control)_msgStudioForASPdotNET).Visible = false;
			((Control)_msgStudioForMobileDevices).Enabled = false;
			((Control)_msgStudioForMobileDevices).Location = new Point(472, 280);
			((Control)_msgStudioForMobileDevices).Name = "_msgStudioForMobileDevices";
			((Control)_msgStudioForMobileDevices).Size = new Size(276, 16);
			((Control)_msgStudioForMobileDevices).TabIndex = 27;
			((Control)_msgStudioForMobileDevices).Text = "ComponentOne Studio(TM) for Mobile Devices";
			((Control)_msgStudioForMobileDevices).Visible = false;
			((Control)_msgCongratulations).Enabled = false;
			((Control)_msgCongratulations).Location = new Point(752, 216);
			((Control)_msgCongratulations).Name = "_msgCongratulations";
			((Control)_msgCongratulations).TabIndex = 28;
			((Control)_msgCongratulations).Text = "Congratulations";
			((Control)_msgCongratulations).Visible = false;
			((Form)this).AcceptButton = (IButtonControl)(object)btnOk;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Control)this).BackColor = Color.White;
			((Form)this).CancelButton = (IButtonControl)(object)btnCancel;
			((Form)this).ClientSize = new Size(426, 295);
			((Control)this).Controls.Add((Control)(object)_msgCongratulations);
			((Control)this).Controls.Add((Control)(object)_msgStudioForMobileDevices);
			((Control)this).Controls.Add((Control)(object)_msgStudioForASPdotNET);
			((Control)this).Controls.Add((Control)(object)_msgStudioForDotNET);
			((Control)this).Controls.Add((Control)(object)_msgStudioEnterprise);
			((Control)this).Controls.Add((Control)(object)_msgLicensedInfo);
			((Control)this).Controls.Add((Control)(object)_msgTooLongCompanyName);
			((Control)this).Controls.Add((Control)(object)_msgTooLongCustomerName);
			((Control)this).Controls.Add((Control)(object)_msgSerialNumberHasExpired);
			((Control)this).Controls.Add((Control)(object)_msgArchaicProductKey);
			((Control)this).Controls.Add((Control)(object)_msgEmptyCustomerName);
			((Control)this).Controls.Add((Control)(object)linkEULA);
			((Control)this).Controls.Add((Control)(object)labSNTitle);
			((Control)this).Controls.Add((Control)(object)pictureBox1);
			((Control)this).Controls.Add((Control)(object)labProductName);
			((Control)this).Controls.Add((Control)(object)labHR);
			((Control)this).Controls.Add((Control)(object)edSerialNumber);
			((Control)this).Controls.Add((Control)(object)labSerialNumber);
			((Control)this).Controls.Add((Control)(object)edName);
			((Control)this).Controls.Add((Control)(object)labCompany);
			((Control)this).Controls.Add((Control)(object)labName);
			((Control)this).Controls.Add((Control)(object)btnCancel);
			((Control)this).Controls.Add((Control)(object)btnOk);
			((Control)this).Controls.Add((Control)(object)labPersonalInfo);
			((Control)this).Controls.Add((Control)(object)edCompany);
			((Control)this).Controls.Add((Control)(object)_msgEmptyCompanyName);
			((Control)this).Controls.Add((Control)(object)_msgInvalidSerialNumber);
			((Control)this).ForeColor = Color.Black;
			((Form)this).FormBorderStyle = (FormBorderStyle)3;
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = "LicensingForm";
			((Form)this).StartPosition = (FormStartPosition)4;
			((Control)this).Text = "ComponentOne Licensing Form";
			((Control)this).ResumeLayout(false);
		}

		private void linkEULA_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
		{
			e.Link.Visited = true;
			Process.Start("http://www.componentone.com/userpage/DesktopDefault.aspx?tabindex=0&tabsubindex=3&tabid=9");
		}

		private void Copy_Click(object sender, EventArgs e)
		{
			Clipboard.SetDataObject((object)"http://www.componentone.com/userpage/DesktopDefault.aspx?tabindex=0&tabsubindex=3&tabid=9", true);
		}

		private bool KeyArchaic(string sn, 8 licInfo)
		{
			//IL_0062: Unknown result type (might be due to invalid IL or missing references)
			int num = int.Parse(sn.Substring(3, 2), CultureInfo.InvariantCulture) + 2000;
			int num2 = int.Parse(sn.Substring(2, 1), CultureInfo.InvariantCulture);
			if (licInfo.H8 * 4 + licInfo.H9 > num * 4 + num2)
			{
				((Control)edSerialNumber).Focus();
				MessageBox.Show(((Control)_msgArchaicProductKey).Text, ((Control)this).Text, (MessageBoxButtons)0, (MessageBoxIcon)48);
				return true;
			}
			return false;
		}

		private void btnOk_Click(object sender, EventArgs e)
		{
			//IL_0051: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
			//IL_0363: Unknown result type (might be due to invalid IL or missing references)
			//IL_0129: Unknown result type (might be due to invalid IL or missing references)
			//IL_0279: Unknown result type (might be due to invalid IL or missing references)
			string text = ((Control)edName).Text;
			int length = text.Length;
			if (length == 0 || length > 255)
			{
				((Control)edName).Focus();
				string text2 = ((length != 0) ? ((Control)_msgTooLongCustomerName).Text : ((Control)_msgEmptyCustomerName).Text);
				MessageBox.Show(text2, ((Control)this).Text, (MessageBoxButtons)0, (MessageBoxIcon)48);
				return;
			}
			string text3 = ((Control)edCompany).Text;
			length = text3.Length;
			if (length == 0 || length > 255)
			{
				((Control)edCompany).Focus();
				string text2 = ((length != 0) ? ((Control)_msgTooLongCompanyName).Text : ((Control)_msgEmptyCompanyName).Text);
				MessageBox.Show(text2, ((Control)this).Text, (MessageBoxButtons)0, (MessageBoxIcon)48);
				return;
			}
			string text4 = ((Control)edSerialNumber).Text;
			int num = 0;
			RegistryKey registryKey = null;
			if (_memberOfStudio)
			{
				if (text4.StartsWith("SE"))
				{
					int num2 = 9.26(text4, _asm);
					if (num2 != 0)
					{
						((Control)edSerialNumber).Focus();
						string text2 = ((num2 != 1) ? ((Control)_msgSerialNumberHasExpired).Text : ((Control)_msgInvalidSerialNumber).Text);
						MessageBox.Show(text2, ((Control)this).Text, (MessageBoxButtons)0, (MessageBoxIcon)48);
						return;
					}
					num = 1;
					registryKey = Registry.ClassesRoot.OpenSubKey("Licenses\\724E8A91-AF12-4a3b-9AEB-EF89612E692E", writable: true);
					if (registryKey == null)
					{
						registryKey = Registry.ClassesRoot.CreateSubKey("Licenses\\724E8A91-AF12-4a3b-9AEB-EF89612E692E");
					}
					else
					{
						object value = registryKey.GetValue("1");
						if (value is byte[])
						{
							byte[] array = (byte[])value;
							int num3 = array.Length / 2;
							char[] array2 = (char[])Array.CreateInstance(typeof(char), num3);
							for (int i = 0; i < num3; i++)
							{
								array2[i] = (char)((array[i + i + 1] << 8) + array[i + i]);
							}
							8 10 = 9.1W(new string(array2), _asm, null, Z9: true);
							if (10.H4 == 7.GZ && KeyArchaic(text4, 10))
							{
								return;
							}
						}
					}
				}
				else if (text4.StartsWith("S8") || text4.StartsWith("S9") || text4.StartsWith("SM"))
				{
					int num4 = 9.27(text4, _asm, _webProduct, _mobileProduct);
					if (num4 != 0)
					{
						((Control)edSerialNumber).Focus();
						string text2 = ((num4 != 1) ? ((Control)_msgSerialNumberHasExpired).Text : ((Control)_msgInvalidSerialNumber).Text);
						MessageBox.Show(text2, ((Control)this).Text, (MessageBoxButtons)0, (MessageBoxIcon)48);
						return;
					}
					string w = ((2)Attribute.GetCustomAttribute(_asm, typeof(2))).W8;
					num = 2;
					registryKey = Registry.ClassesRoot.OpenSubKey("Licenses\\" + w, writable: true);
					if (registryKey == null)
					{
						registryKey = Registry.ClassesRoot.CreateSubKey("Licenses\\" + w);
					}
					else
					{
						string text2 = 9.1Q(registryKey.GetValue(""));
						8 11 = 9.1W(text2, _asm, null, Z9: true);
						if (11.H4 == 7.GY && KeyArchaic(text4, 11))
						{
							return;
						}
					}
				}
			}
			if (num == 0)
			{
				int num5 = 9.28(text4, _asm);
				if (num5 != 0)
				{
					((Control)edSerialNumber).Focus();
					string text2 = ((num5 != 1) ? ((Control)_msgSerialNumberHasExpired).Text : ((Control)_msgInvalidSerialNumber).Text);
					MessageBox.Show(text2, ((Control)this).Text, (MessageBoxButtons)0, (MessageBoxIcon)48);
					return;
				}
				1 12 = (1)Attribute.GetCustomAttribute(_asm, typeof(1));
				registryKey = Registry.ClassesRoot.OpenSubKey("Licenses\\" + 12.W6, writable: true);
				if (registryKey == null)
				{
					registryKey = Registry.ClassesRoot.CreateSubKey("Licenses\\" + 12.W6);
				}
				else
				{
					string text2 = 9.1Q(registryKey.GetValue(""));
					8 13 = 9.1W(text2, _asm, 12.W5, Z9: true);
					if (13.H4 == 7.GX && KeyArchaic(text4, 13))
					{
						return;
					}
				}
			}
			StringBuilder stringBuilder = new StringBuilder(text4.Substring(0, 5));
			stringBuilder.Append((char)text.Length);
			stringBuilder.Append(text);
			stringBuilder.Append((char)text3.Length);
			stringBuilder.Append(text3);
			_licenseKey = 9.21(stringBuilder.ToString(), 9.HL);
			if (num != 1)
			{
				registryKey.SetValue("", _licenseKey);
				if (num == 0)
				{
					_info = string.Format(CultureInfo.InvariantCulture, ((Control)_msgLicensedInfo).Text, new object[1] { ((Control)labProductName).Text });
				}
				else if (_webProduct)
				{
					_info = string.Format(CultureInfo.InvariantCulture, ((Control)_msgLicensedInfo).Text, new object[1] { ((Control)_msgStudioForASPdotNET).Text });
				}
				else if (_mobileProduct)
				{
					_info = string.Format(CultureInfo.InvariantCulture, ((Control)_msgLicensedInfo).Text, new object[1] { ((Control)_msgStudioForMobileDevices).Text });
				}
				else
				{
					_info = string.Format(CultureInfo.InvariantCulture, ((Control)_msgLicensedInfo).Text, new object[1] { ((Control)_msgStudioForDotNET).Text });
				}
			}
			else
			{
				length = _licenseKey.Length;
				byte[] array3 = (byte[])Array.CreateInstance(typeof(byte), length + length);
				for (int i = 0; i < length; i++)
				{
					int num6 = _licenseKey[i];
					array3[i + i] = (byte)(num6 & 0xFF);
					array3[i + i + 1] = (byte)(num6 >> 8);
				}
				registryKey.SetValue("1", array3);
				_info = string.Format(CultureInfo.InvariantCulture, ((Control)_msgLicensedInfo).Text, new object[1] { ((Control)_msgStudioEnterprise).Text });
			}
			_caption = ((Control)_msgCongratulations).Text;
			((Form)this).DialogResult = (DialogResult)1;
		}
	}
}
namespace C1.Util.Localization
{
	[AttributeUsage(AttributeTargets.Assembly | AttributeTargets.Module | AttributeTargets.Class | AttributeTargets.Struct | AttributeTargets.Enum | AttributeTargets.Constructor | AttributeTargets.Method | AttributeTargets.Property | AttributeTargets.Field | AttributeTargets.Event | AttributeTargets.Interface | AttributeTargets.Parameter | AttributeTargets.Delegate | AttributeTargets.ReturnValue)]
	internal class D : DescriptionAttribute
	{
		private string HU = null;

		public override string Description
		{
			get
			{
				if (HU != null)
				{
					string text = F.2C(HU);
					if (text != null)
					{
						base.DescriptionValue = text;
					}
					HU = null;
				}
				return base.Description;
			}
		}

		public D(string key)
		{
			HU = key;
			base.DescriptionValue = key;
		}

		public D(string key, string description)
		{
			HU = key;
			base.DescriptionValue = description;
		}
	}
	[AttributeUsage(AttributeTargets.Assembly | AttributeTargets.Module | AttributeTargets.Class | AttributeTargets.Struct | AttributeTargets.Enum | AttributeTargets.Constructor | AttributeTargets.Method | AttributeTargets.Property | AttributeTargets.Field | AttributeTargets.Event | AttributeTargets.Interface | AttributeTargets.Parameter | AttributeTargets.Delegate | AttributeTargets.ReturnValue)]
	internal class E : CategoryAttribute
	{
		private string HV = null;

		public E(string name)
			: base(name)
		{
		}

		protected override string GetLocalizedString(string value)
		{
			if (HV != null)
			{
				return HV;
			}
			HV = F.2D(value);
			if (HV == null)
			{
				HV = value;
			}
			return HV;
		}
	}
	internal class F
	{
		private static Hashtable HW;

		private static Hashtable HX;

		private static Hashtable HY;

		private static Hashtable HZ;

		internal static CultureInfo I0;

		static F()
		{
			HW = null;
			HX = null;
			HY = null;
			HZ = null;
			I0 = CultureInfo.CurrentCulture;
		}

		internal static string 2C(string 001)
		{
			if (HW == null)
			{
				2J();
			}
			if (HW != null && HW.Contains(001))
			{
				return (string)HW[001];
			}
			return null;
		}

		internal static string 2D(string 002)
		{
			if (HX == null)
			{
				2J();
			}
			if (HX != null && HX.Contains(002))
			{
				return (string)HX[002];
			}
			return null;
		}

		internal static string 2E(string 003)
		{
			if (HY == null)
			{
				2J();
			}
			if (HY != null && HY.Contains(003))
			{
				return (string)HY[003];
			}
			return 003;
		}

		internal static void 2F(Control 004, IContainer 005)
		{
			if (HZ == null)
			{
				2J();
			}
			if (HZ != null && HZ.Contains(004.Name))
			{
				Hashtable 6 = (Hashtable)HZ[004.Name];
				2G(004, 005, 6);
			}
		}

		internal static void 2G(Control 006, IContainer 007, Hashtable 008)
		{
			//IL_013f: Unknown result type (might be due to invalid IL or missing references)
			//IL_00bb: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c1: Expected O, but got Unknown
			//IL_012c: Unknown result type (might be due to invalid IL or missing references)
			//IL_01c6: Unknown result type (might be due to invalid IL or missing references)
			//IL_01cd: Expected O, but got Unknown
			//IL_005a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0060: Expected O, but got Unknown
			//IL_0159: Unknown result type (might be due to invalid IL or missing references)
			//IL_0160: Expected O, but got Unknown
			//IL_0118: Unknown result type (might be due to invalid IL or missing references)
			//IL_01fc: Unknown result type (might be due to invalid IL or missing references)
			//IL_0203: Expected O, but got Unknown
			string text = 2I(006.Text, 008);
			if (text != null)
			{
				006.Text = text;
			}
			if (006.ContextMenu != null)
			{
				2H(((Menu)006.ContextMenu).MenuItems, 008);
			}
			if (007 != null)
			{
				foreach (Component component in 007.Components)
				{
					ToolTip val = null;
					if (component is ToolTip)
					{
						val = (ToolTip)component;
					}
					if (val != null)
					{
						text = val.GetToolTip(006);
						text = 2I(text, 008);
						if (text != null)
						{
							val.SetToolTip(006, text);
						}
					}
				}
			}
			if (006 is LinkLabel)
			{
				text = 006.Text;
				LinkLabel val2 = null;
				if (006 is LinkLabel)
				{
					val2 = (LinkLabel)006;
				}
				int num = text.IndexOf('<');
				int num2 = text.IndexOf('>');
				if (num > -1 && num2 > -1 && num2 > num)
				{
					text = text.Replace("<", "");
					text = text.Replace(">", "");
					((Control)val2).Text = text;
					val2.LinkArea = new LinkArea(num, num2 - num - 1);
				}
				else
				{
					val2.LinkArea = new LinkArea(0, text.Length);
				}
			}
			if (006 is ToolBar)
			{
				foreach (ToolBarButton button in ((ToolBar)006).Buttons)
				{
					ToolBarButton val3 = button;
					text = 2I(val3.Text, 008);
					if (text != null)
					{
						val3.Text = text;
					}
					text = 2I(val3.ToolTipText, 008);
					if (text != null)
					{
						val3.ToolTipText = text;
					}
				}
			}
			if (006 is TabPage)
			{
				TabPage val4 = null;
				if (006 is TabPage)
				{
					val4 = (TabPage)006;
				}
				text = 2I(val4.ToolTipText, 008);
				if (text != null)
				{
					val4.ToolTipText = text;
				}
			}
			foreach (Control control in 006.Controls)
			{
				Control 9 = control;
				2G(9, 007, 008);
			}
		}

		internal static void 2H(MenuItemCollection 009, Hashtable 00A)
		{
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0015: Expected O, but got Unknown
			foreach (MenuItem item in 009)
			{
				MenuItem val = item;
				string text = 2I(val.Text, 00A);
				if (text != null)
				{
					val.Text = text;
				}
				if (((Menu)val).MenuItems != null)
				{
					2H(((Menu)val).MenuItems, 00A);
				}
			}
		}

		internal static string 2I(string 00B, Hashtable 00C)
		{
			if (00B == null || 00B.Length == 0)
			{
				return null;
			}
			return (string)00C[00B];
		}

		private static void 2J()
		{
			HW = new Hashtable();
			HX = new Hashtable();
			HY = new Hashtable();
			HZ = new Hashtable();
			string name = I0.Name;
			if (name.StartsWith("de"))
			{
				Hashtable hashtable = new Hashtable();
				hashtable.Add("About {0}", "Info zu {0}");
				hashtable.Add("Check for online updates", "Suche nach Online-Updates");
				hashtable.Add("Click here if you purchased the product and already have a license key.", "Klicken Sie hier, wenn Sie das Produkt gekauft haben und bereits über einen Lizenzschlüssel verfügen.");
				hashtable.Add("Click here to buy a copy of the product. After you purchase, you should license and register it.", "Klicken Sie hier, um eine Kopie des Produkts zu kaufen. Nachdem Sie es gekauft haben, sollten Sie es lizenzieren und registrieren.");
				hashtable.Add("Click here to register online (so we can send you quarterly updates).", "Klicken Sie hier, um sich online zu registrieren (damit wir Ihnen die Quartals-Updates schicken können).");
				hashtable.Add("ComponentOne Technical Support", "ComponentOne Technischer Support");
				hashtable.Add("Contact Us", "Kontaktieren Sie uns");
				hashtable.Add("Copy URL", "URL kopieren");
				hashtable.Add("Copyright (C) 2001{0} ComponentOne LLC. All rights reserved.", "Copyright (C) 2001{0} ComponentOne LLC. All rights reserved.");
				hashtable.Add("For email support, please write to:", "Für Support per Email schreiben Sie bitte an:");
				hashtable.Add("License", "Lizenz");
				hashtable.Add("Newsgroup", "Newsgroup");
				hashtable.Add("NOT LICENSED. THIS IS AN EVALUATION VERSION", "NICHT LIZENZIERT. DIES IST EINE TESTVERSION. Sie können");
				hashtable.Add("Online Resources:", "Online Resourcen:");
				hashtable.Add("Please check our web site for a new version.", "Bitte erkundigen Sie sich auf unserer Website nach einer neuen Version.");
				hashtable.Add("Purchase", "Kaufen");
				hashtable.Add("Register", "Registrieren");
				hashtable.Add("Renew your subscription to get a new license key, or keep using the components released while your subscription was valid.", "Verlängern Sie Ihr Abonnement, um einen neuen Lizenzschlüssel zu bekommen; oder verwenden\r\nSie weiterhin die Komponenten, die veröffentlicht wurden, während Ihr Abonnement noch lief.");
				hashtable.Add("Resellers", "Fachhändler");
				hashtable.Add("using a licensed version of this product.", "Verwendung einer lizenzierten Version dieses Produktes rekompilieren.");
				hashtable.Add("This dialog box will not be shown if you recompile the program", "Dieses Dialogfenster wird nicht angezeigt, wenn Sie das Programm unter");
				hashtable.Add("This evaluation version has expired.", "Diese Testversion ist abgelaufen.");
				hashtable.Add("This product is included in ComponentOne Studio(TM) for .NET", "Dieses Produkt ist Bestandteil von ComponentOne Studio(TM) for .NET");
				hashtable.Add("This product is licensed to:", "Dieses Produkt ist lizenziert für:");
				hashtable.Add("You can use this product for a 30-day trial period.", "dieses Produkt während einer 30-tägigen Testphase verwenden.");
				hashtable.Add("Your subscription has expired since Q{0} {1}.", "Ihr Abonnement ist abgelaufen seit Q{0} {1}.");
				hashtable.Add("Web Store", "Online-Shop");
				HZ.Add("AboutForm", hashtable);
				Hashtable hashtable2 = new Hashtable();
				hashtable2.Add("Cancel", "Abbrechen");
				hashtable2.Add("Company Name field cannot be empty.", "Das Firmennamen-Feld darf nicht leer sein.");
				hashtable2.Add("Company Name is too long.", "Der Firmenname ist zu lang.");
				hashtable2.Add("Company:", "Firma:");
				hashtable2.Add("ComponentOne Licensing Form", "ComponentOne Lizenzierungs-Formular");
				hashtable2.Add("Congratulations", "Herzlichen Glückwunsch");
				hashtable2.Add("Copy URL", "URL kopieren");
				hashtable2.Add("Customer Name field cannot be empty.", "Das Kundenname-Feld darf nicht leer sein.");
				hashtable2.Add("Customer Name is too long.", "Der Kundenname ist zu lang.");
				hashtable2.Add("Name:", "Name:");
				hashtable2.Add("OK", "OK");
				hashtable2.Add("Please read the END-USER LICENSE AGREEMENT before proceeding.", "Bitte lesen Sie das <END-USER LICENSE AGREEMENT> bevor Sie fortfahren.");
				hashtable2.Add("S/N:", "S/N:");
				hashtable2.Add("Sorry, this serial number has expired. You can still use\r\nthe previous builds with the current license, or renew\r\nyour subscription to get a new license key.", "Diese Seriennummer ist leider abgelaufen. Sie können mit Ihrer Lizenz weiterhin\r\ndie früheren Versionen verwenden oder Ihr Abonnement verlängern, um einen\r\nneuen Lizenzierungsschlüssel zu bekommen.");
				hashtable2.Add("Studio or product serial number:", "Seriennummer des Studios oder eines Einzelprodukts:");
				hashtable2.Add("The specified serial number is not valid.", "Die eingegebene Seriennummer ist nicht gültig.");
				hashtable2.Add("This license key is older than the one currently installed.\r\nYou cannot replace new key with the old one because\r\nsome new products may become unlicensed.", "Dieser Lizenzierungsschlüssel ist älter als der momentan installierte. Sie können\r\neinen neuen Schlüssel nicht mit einem älteren ersetzen, da sonst neuere Produkte\r\nnicht mehr lizenziert sein könnten.");
				hashtable2.Add("You have licensed {0} !", "Sie haben {0} lizenziert!");
				hashtable2.Add("Your personal information:", "Ihre persönlichen Informationen:");
				HZ.Add("LicensingForm", hashtable2);
			}
			G.2L(HW, HX, HY, HZ, name);
		}
	}
	internal class G
	{
		internal static void 2K(Hashtable 00D, Hashtable 00E, Hashtable 00F, Hashtable 00G)
		{
			2L(00D, 00E, 00F, 00G, CultureInfo.CurrentCulture.Name);
		}

		internal static void 2L(Hashtable 00H, Hashtable 00I, Hashtable 00J, Hashtable 00K, string 00L)
		{
			if (!00L.StartsWith("en"))
			{
				if (00L.StartsWith("ja"))
				{
					00H.Add("AddItem", "グリッドへ行を追加します。");
					00H.Add("Aggregate", "特定範囲の集合関数（合計、平均など）を算出します。");
					00H.Add("AllowDragging", "マウスによる列や行のドラッグを可能にします。");
					00H.Add("AllowEditing", "グリッド内の編集を可能にします。");
					00H.Add("AllowFreezing", "マウスによる列や行の静止を可能にします。");
					00H.Add("AllowMerging", "同じ内容のセルをマージするかを決めます。");
					00H.Add("AllowResizing", "マウスによる行や列のサイズ変更を可能にします。");
					00H.Add("AllowSorting", "列ヘッダのクリックによる列のソートを可能にします。");
					00H.Add("AutoResize", "データをロードしたとき列の幅を自動的に調節するかを設定および参照します。");
					00H.Add("AutoSearch", "ユーザーが文字をタイプしたとき一致する項目を自動的に検索するかを設定および参照します。");
					00H.Add("AutoSearchDelay", "AutoSearchで使用されるバッファがリセットされるまでの遅延時間（秒単位）を設定および参照します。");
					00H.Add("BackColor", "セルの背景色");
					00H.Add("Border", "セルの周りの罫線");
					00H.Add("BorderStyle", "グリッド全体を取り囲むボーダースタイルを設定および参照します。");
					00H.Add("BottomRow", "スクロール可能な領域の最下部に見える行番号を参照します。");
					00H.Add("Caption", "最初の固定行のタイトルを設定および参照します。");
					00H.Add("CellButtonImage", "セルボタンに使用されるイメージを設定および参照します。");
					00H.Add("CellStyle", "セルのスタイルを設定および参照します。");
					00H.Add("Clear", "コントロールの内容をクリアします。");
					00H.Add("Clip", "選択範囲のセルの内容を設定および参照します。");
					00H.Add("ClipSeparators", "クリップストリングで使用される区切り文字を設定および参照します。");
					00H.Add("Col", "カレント列を設定および参照します。");
					00H.Add("Col.AllowDragging", "マウスによる列や行のドラッグができるかを設定および参照します。");
					00H.Add("Col.AllowEditing", "列内のセルが編集できるかを設定および参照します。");
					00H.Add("Col.AllowMerging", "同じ内容の隣接した列や行をマージするかを設定および参照します。");
					00H.Add("Col.AllowResizing", ":マウスによる行や列のサイズ変更ができるかを設定および参照します。");
					00H.Add("Col.AllowSorting", "列ヘッダのクリックによる列のソートができるかを設定および参照します。");
					00H.Add("Col.ComboList", "コンボやリストボックスのドロップダウンエディタで使用するリストを設定および参照します。");
					00H.Add("Col.Count", "コレクションにおける列数を設定および参照します。");
					00H.Add("Col.EditMask", "列のセル編集に使用する入力マスクを設定および参照します。");
					00H.Add("Col.ImageAlign", "列のセル内のどの位置にイメージを表示するかを設定および参照します。");
					00H.Add("Col.Name", "列の名前（インデクサとして利用）を設定および参照します。");
					00H.Add("Col.TextAlign", "列のセル内のどの位置にテキストを表示するかを設定および参照します。");
					00H.Add("Col.TextAlignFixed", "列の固定セル内のどの位置にテキストを表示するかを設定および参照します。");
					00H.Add("Cols", "Columnコレクション");
					00H.Add("ColSel", "選択範囲の最後の列を設定および参照します。");
					00H.Add("ComboList", "コンボやリストボックスのドロップダウンエディタで使用されるリストを設定および参照します。");
					00H.Add("CreateImage", "グリッドのイメージを作成します。");
					00H.Add("Cursor", "マウスがコントロール上を通過したときに表示されるカーソルを設定および参照します。");
					00H.Add("CursorCell", "選択範囲(Row, Col)を取得します。");
					00H.Add("DataMember", "グリッドに表示するデータソースのリストを設定および参照します。");
					00H.Add("DataSource", "グリッドに表示するデータソース");
					00H.Add("DataType", "列が保持するオブジェクトの型を設定および参照します。");
					00H.Add("DefinedElements", "どの要素がスタイルで定義されるかを示すフラグを設定および参照します。");
					00H.Add("DoubleBuffer", "コントロールを再描画するとき画面のちらつきを少なくするために画面外のバッファを使用するかを設定および参照します。");
					00H.Add("DragMode", "コントロールからデータをドラッグできるかを設定および参照します。");
					00H.Add("DrawMode", "コントロールがOwnerDrawCellイベントを発生させるかを指定します。");
					00H.Add("DropMode", "コントロールがドロップされたデータを受け入れるかを設定および参照します。");
					00H.Add("EditMask", "セル編集に使用する入力マスクを設定および参照します。");
					00H.Add("Editor", "セル編集中のコントロールの参照を返します。");
					00H.Add("ExtendLastCol", "グリッドの最後（右端）の列幅をコントロール幅に合わせて自動的に調節するかを設定します。");
					00H.Add("FindRow", "任意の文字列を含む行を見つけます。");
					00H.Add("Fixed", "コレクションの固定要素の数を設定および参照します。");
					00H.Add("FocusRect", "フォーカス枠のスタイルを設定および参照します。");
					00H.Add("Font", "セルのフォント");
					00H.Add("ForeColor", "セルの前景色");
					00H.Add("Format", "列のフォーマットを設定および参照します。");
					00H.Add("Frozen", "コレクションの静止要素の数を設定および参照します。");
					00H.Add("GetCellImage", "セル内のイメージを参照します。");
					00H.Add("GetCellRange", "セル範囲を操作するためにCellRangeオブジェクトを返します。");
					00H.Add("GetCellRect", "セルの境界線枠の座標を取得します。");
					00H.Add("GetData", "グリッドから値を取得します。");
					00H.Add("GetDataDisplay", "グリッドからフォーマットされた値を取得します。");
					00H.Add("GetMergedRange", "任意のセルがマージされた範囲を返します。");
					00H.Add("HighLight", "選択セルをハイライト表示するかを設定および参照します。");
					00H.Add("HitTest", "スクリーン上の特定ポイントのコントロール情報を取得します。");
					00H.Add("ImageAlign", "セルのどの位置にイメージを表示するかを設定および参照します。");
					00H.Add("ImageSpacing", "セルのイメージとテキストの間をピクセルで設定および参照します。.");
					00H.Add("Display", "イメージか文字列または両方を表示するかどうか");
					00H.Add("Invalidate", "セルまたは範囲を無効にします。)");
					00H.Add("KeyActionEnter", "Enterキーが押されたときに実行するアクションを設定および参照します。");
					00H.Add("KeyActionTab", "Tabキーが押されたときに実行するアクションを設定および参照します。");
					00H.Add("LeftCol", "スクロール可能な可視領域の左端に表示する列を設定および参照します。");
					00H.Add("LoadGrid", "グリッドをファイルから読み込みます。");
					00H.Add("Margins", "セルのコンテンツとセル枠の間をピクセルで設定および参照します。");
					00H.Add("MaxSize", "コレクションの要素の最大サイズを設定および参照します。");
					00H.Add("MinSize", "コレクションの要素の最小サイズを設定および参照します。");
					00H.Add("MouseCol", "マウスポインタが置かれている列番号を取得します。");
					00H.Add("MouseRow", "マウスポインタが置かれている行番号を取得します。");
					00H.Add("Name", "スタイル名");
					00H.Add("PrintGrid", "印刷");
					00H.Add("PrintParameters", "印刷");
					00H.Add("Redraw", "コントロールの内容を再描画すべきかを設定および参照します。");
					00H.Add("RemoveItem", "グリッドから行を削除します。");
					00H.Add("RightCol", "スクロール可能な可視領域の右端に表示される列を取得します。");
					00H.Add("Row", "カレント行を設定および参照します。");
					00H.Add("Row.Count", "コレクションにおける行数を設定および参照します。");
					00H.Add("Rows", "Rowコレクション");
					00H.Add("RowSel", "選択範囲の最後の行を設定および参照します。");
					00H.Add("SaveGrid", "グリッドをファイルへ保存します。");
					00H.Add("ScrollBars", "スクロールバーを表示すべきかを設定および参照します。");
					00H.Add("ScrollPosition", "現在のスクロール位置を設定および参照します。");
					00H.Add("ScrollTips", "垂直方向にスクロールするときツールチップを表示するかを設定および参照します。");
					00H.Add("ScrollTipText", "垂直方向にスクロールするとき表示するツールチップのテキストを設定および参照します。");
					00H.Add("ScrollTrack", "スクロールバーのつまみを動かしたときコントロールの内容をスクロールするかを設定および参照します。");
					00H.Add("Select", "セルまたは範囲を選択します。");
					00H.Add("Selected", "選択行のコレクションを取得します。");
					00H.Add("Selection", "選択範囲(Row, Col, RowSel, ColSel)を返します。");
					00H.Add("SelectionMode", "グリッドの選択モードを設定および参照します。");
					00H.Add("SetData", "グリッドに値を格納します。");
					00H.Add("SetDataBinding", "DataSourceとDataMemberプロパティを設定します。");
					00H.Add("ShowButtons", "セルのドロップダウンボタンを描画します。");
					00H.Add("ShowCell", "可視領域にセルをスクロールします。");
					00H.Add("ShowCursor", "固定列上のDBスタイルカーソルを表示します。");
					00H.Add("ShowSort", "ソート方向を示すアイコンをヘッダ上に表示します。");
					00H.Add("ShowSortAt", "ソート方向を示すアイコンを列ヘッダ上に表示します。");
					00H.Add("Sort", "列または範囲をソートします。");
					00H.Add("StartEditing", "セルの編集を開始します。");
					00H.Add("Style.Clear", "選択された要素をスタイルからクリアします。");
					00H.Add("Styles", "スタイルコレクション");
					00H.Add("Subtotal", "セルの内容に基づいたグループおよび列合計を算出します。");
					00H.Add("SubtotalPosition", "小計(ノード行）を挿入する位置（データの上または下）を設定および参照します。");
					00H.Add("TextAlign", "セルのどの位置にテキストを表示するかを設定および参照します。");
					00H.Add("TextEffect", "テキストに3D効果を適用します。");
					00H.Add("TopRow", "スクロール可能な領域の最上部に見える行番号を設定および参照します。");
					00H.Add("Tree", "ツリー（アウトライン列）の外観を制御します。");
					00H.Add("Trimming", "長い文字列がセルに収まらないときどのように制御するかを設定および参照します。");
					00H.Add("Visible", "行または列を表示するかを設定および参照します。");
					00H.Add("Width", "列幅を設定および参照します(-1はデフォルト幅を使用することを意味します)。");
					00H.Add("WordWrap", "テキストがセル幅よりも長いときに折り返して表示するかを設定します。");
					00H.Add("AllowAddNew", "最終行の下に新規データ行のテンプレートを表示するかを設定および参照します。");
					00H.Add("AllowDelete", "DELキーが押されたとき、選択された行を削除するかを設定および参照します。");
					00H.Add("ShowErrors", "データソースを監視しエラーを表示するかどうかを設定および参照します。");
					00H.Add("Glyphs", "組み込みイメージ（ソート方向やチェックボックスなど）のコレクションを参照します。");
					00I.Add("Layout", "レイアウト");
					00J.Add("Are you sure you want to clear all styles?", "全てのスタイルをクリアしてもいいですか？");
					00J.Add("Built-In Styles", "組み込みスタイル");
					00J.Add("Column {0} selected.", "列 {0} が選択されています。");
					00J.Add("Columns {0}-{1} selected ({2} cols).", "列 {0}-{1} が選択されています (全 {2} 列)。");
					00J.Add("Custom Styles", "カスタムスタイル");
					00J.Add("No columns selected", "列が選択されていません。");
					00J.Add("Please confirm", "確認してください。");
					00J.Add("Sorry, this name is invalid.", "不正な名前です。");
					00J.Add("About C1FlexGrid...", "C1FlexGridのバージョン情報...");
					00J.Add("Edit Styles...", "スタイルエディタ...");
					00J.Add("Edit Columns...", "列エディタ...");
					Hashtable hashtable = new Hashtable();
					hashtable.Add("C1FlexGrid Auto Format", "FlexGrid オートフォーマット");
					hashtable.Add("&Cancel", "キャンセル(&C)");
					hashtable.Add("&OK", "OK(&O)");
					hashtable.Add("Formats", "フォーマット");
					hashtable.Add("Preview", "プレビュー");
					Hashtable hashtable2 = new Hashtable();
					hashtable2.Add("C1FlexGrid Column Editor", "FlexGrid 列エディタ");
					hashtable2.Add("Adjust column widths after loading data", "ロード後に列幅を調整");
					hashtable2.Add("Align center", "中央揃え");
					hashtable2.Add("Align left", "左揃え");
					hashtable2.Add("Align right", "右揃え");
					hashtable2.Add("Cancel", "キャンセル");
					hashtable2.Add("Delete columns", "列削除");
					hashtable2.Add("Group properties by category", "項目別");
					hashtable2.Add("Insert columns after selection", "セルの後に列挿入");
					hashtable2.Add("Insert columns before selection", "セルの前に列挿入");
					hashtable2.Add("Make all columns visible", "非表示列を表示");
					hashtable2.Add("Make selected columns narrower", "列幅を狭くする");
					hashtable2.Add("Make selected columns the same width", "列幅を揃える");
					hashtable2.Add("Make selected columns wider", "列幅を広げる");
					hashtable2.Add("Reload all columns from data source", "データソースから再ロード");
					hashtable2.Add("Show property help", "プロパティヘルプ");
					hashtable2.Add("Undo all changes", "すべての変更を元に戻す");
					Hashtable hashtable3 = new Hashtable();
					hashtable3.Add("C1FlexGrid Style Editor", "FlexGrid スタイルエディタ");
					hashtable3.Add("&Cancel", "キャンセル(&C)");
					hashtable3.Add("&OK", "OK(&O)");
					hashtable3.Add("Add", "追加");
					hashtable3.Add("AutoFormat...", "オートフォーマット...");
					hashtable3.Add("Clear", "クリア");
					hashtable3.Add("Current Style", "現在のスタイル");
					hashtable3.Add("Remove", "削除");
					00K.Add("GridAutoFormatForm", hashtable);
					00K.Add("GridColumnEditorForm", hashtable2);
					00K.Add("GridStyleEditorForm", hashtable3);
				}
				if (00L.StartsWith("zh"))
				{
					00H.Add("AddItem", "在控件中添加一行，并填入给定数据。");
					00H.Add("Aggregate", "计算某单元格区域的聚合值。");
					00H.Add("AllowDragging", "确定用户是否可用鼠标来拖拽行和列。");
					00H.Add("AllowEditing", "确定用户是否可以编辑单元格。");
					00H.Add("AllowFreezing", "确定用户是否可用鼠标来冻结行和列。");
					00H.Add("AllowMerging", "确定是否合并内容相同的单元格。");
					00H.Add("AllowResizing", "确定用户是否可用鼠标来缩放行和列。");
					00H.Add("AllowSorting", "确定用户是否可用鼠标将列排序。");
					00H.Add("AutoResize", "获取或设置是否在读取数据时自动缩放列宽。");
					00H.Add("AutoSearch", "确定网格是否按用户输入的数据移动光标进行搜索。");
					00H.Add("AutoSearchDelay", "确定重设AutoSearch缓存区所用的延迟时间（以秒计）。");
					00H.Add("BackColor", "获取或设置单元格的背景色。");
					00H.Add("Border", "获取单元格边框的CellBorder 对象。");
					00H.Add("BorderStyle", "获取或设置控件的边框样式。");
					00H.Add("BottomRow", "返回并显示网格中可见行的最后一行。");
					00H.Add("Caption", "获取或设置该列第一个固定单元格的文本内容。");
					00H.Add("CellButtonImage", "确定用于单元格按钮的图像。");
					00H.Add("CellStyle", "获取或设置单元格的样式。");
					00H.Add("Clear", "清除网格内容。");
					00H.Add("Clip", "获取或设置单元格区域的内容。");
					00H.Add("ClipSeparators", "获取或设置在节选字符串中用作行列分隔符的标记。");
					00H.Add("Col", "获取或设置所选列的索引。");
					00H.Add("Col.AllowDragging", "获取或设置是否可以用鼠标来拖拽该列。");
					00H.Add("Col.AllowEditing", "获取或设置用户是否可以对该列的单元格进行编辑。");
					00H.Add("Col.AllowMerging", "获取或设置该列的单元格是否可以和相邻单元格合并。");
					00H.Add("Col.AllowResizing", "获取或设置是否可以用鼠标对该列进行缩放。");
					00H.Add("Col.AllowSorting", "获取或设置是否可以用鼠标对该列的内容进行排序。");
					00H.Add("Col.ComboList", "获取或设置该列下拉编辑框的选项列表。");
					00H.Add("Col.Count", "获取或设置集合中列的数目。");
					00H.Add("Col.EditMask", "获取或设置对该列单元格进行编辑时的输入掩码。");
					00H.Add("Col.ImageAlign", "确定该列单元格的图像对齐方式。");
					00H.Add("Col.Name", "获取或设置该列的名称，该名称可用作Cols 属性中的索引。");
					00H.Add("Col.TextAlign", "获取或设置该列单元格的文本对齐方式。");
					00H.Add("Col.TextAlignFixed", "获取或设置该列固定单元格的文本对齐方式。");
					00H.Add("Cols", "获取网格中的列集合。");
					00H.Add("ColSel", "获取或设置当前所选列中最后一列的索引。");
					00H.Add("ComboList", "获取或设置用于下拉编辑框的选项列表。");
					00H.Add("CreateImage", "为整个网格或区域创建图像。");
					00H.Add("Cursor", "当鼠标在该控件上方移动时显示的光标。");
					00H.Add("CursorCell", "获取含有某单元格的CellRange对象，该单元格的位置由Row、Col坐标确定。");
					00H.Add("DataMember", "获取或设置该网格应显示的DataSource对象中的子列表。");
					00H.Add("DataSource", "获取或设置网格的数据源。");
					00H.Add("DataType", "获取或设置该列的数据类型。");
					00H.Add("DefinedElements", "获取或设置当前CellStyle所定义的元素（其它元素继承自父CellStyle）。");
					00H.Add("DoubleBuffer", "获取或设置一个值，当重绘控件时，该值确定为了减少画面的有效性而是否使用画面外的缓冲区。");
					00H.Add("DragMode", "获取或设置一个值，用于说明用户能否从控件中拖动数据。");
					00H.Add("DrawMode", "指定是否对网格中的单元格提供自定义绘制。");
					00H.Add("DropMode", "获取或设置一个值，该值确定控件是否接受用户拖动给它的数据。");
					00H.Add("EditMask", "获取或设置编辑单元格时所用的输入掩码。");
					00H.Add("Editor", "获取正处于激活状态的单元格编辑器。");
					00H.Add("ExtendLastCol", "确定是否调整最后一列的列宽，使之填满控件的宽度。");
					00H.Add("FindRow", "找出含有给定字符串或对象的行。");
					00H.Add("Fixed", "获取或设置集合中固定列的数目。");
					00H.Add("FocusRect", "指定当前单元格周边的聚焦框的类型。");
					00H.Add("Font", "获取或设置单元格文本的字体。");
					00H.Add("ForeColor", "获取或设置单元格文本的字体颜色。");
					00H.Add("Format", "获取或设置一个字符串，用以说明如何对该列数据进行格式化。");
					00H.Add("Frozen", "获取或设置集合中冻结列的数目。");
					00H.Add("GetCellImage", "获取分配给单元格的图像。");
					00H.Add("GetCellRange", "返回一个CellRange对象，该对象可用来操作或格式化某个区域。");
					00H.Add("GetCellRect", "返回一个Rectangle对象，该对象含有屏幕上单元格的坐标值。");
					00H.Add("GetData", "返回某网格单元格中的数据。");
					00H.Add("GetDataDisplay", "返回某网格单元格中的数据，其格式为字符串。");
					00H.Add("GetMergedRange", "返回含有给定单元格的合并单元格区域。");
					00H.Add("HighLight", "确定何时高亮显示选定单元格。");
					00H.Add("HitTest", "返回控件表面给定点的相关信息。");
					00H.Add("ImageAlign", "获取或设置单元格图像的对齐方式。");
					00H.Add("ImageSpacing", "获取或设置单元格图像和文本之间的间距，并以像素表示。");
					00H.Add("Display", "是否显示图片,文字,还是两者都显示。");
					00H.Add("Invalidate", "使某特定网格区域失效，并向控件发送绘制信息。");
					00H.Add("KeyActionEnter", "指定当用户按下回车键时执行的动作。");
					00H.Add("KeyActionTab", "指定用户按下TAB键时执行的动作。");
					00H.Add("LeftCol", "获取或设置非固定列中最左一列的索引。");
					00H.Add("LoadGrid", "从文本文件中读取网格。");
					00H.Add("Margins", "获取或设置单元格边框和显示内容之间的间距。");
					00H.Add("MaxSize", "获取或设置一列的最大显示宽度。");
					00H.Add("MinSize", "获取或设置一列的最小显示宽度。");
					00H.Add("MouseCol", "获取鼠标光标所指向列的索引。");
					00H.Add("MouseRow", "获取鼠标光标所指向行的索引。");
					00H.Add("Name", "获取或设置该CellStyle 的名称。");
					00H.Add("PrintGrid", "打印网格，显示一个打印预览对话框（可选项）。");
					00H.Add("PrintParameters", "获取用于说明网格打印参数的GridPrinter对象。");
					00H.Add("Redraw", "确定网格是否重绘其内容。");
					00H.Add("RemoveItem", "删除控件中的某一行。");
					00H.Add("RightCol", "返回当前范围内最右列的索引（c1和c2中的较大值）。");
					00H.Add("Row", "获取或设置所选行的索引。");
					00H.Add("Row.Count", "获取或设置集合中行的数目。");
					00H.Add("Rows", "获取网格中的行集合。");
					00H.Add("RowSel", "获取或设置当前所选中行中最后一行的索引。");
					00H.Add("SaveGrid", "将网格保存为文本文件。");
					00H.Add("ScrollBars", "获取或设置将显示在网格中的滚动条。");
					00H.Add("ScrollPosition", "获取或设置滚动条的位置。");
					00H.Add("ScrollTips", "返回或设置当用户拖动垂直滚动条按钮时，是否在其上显示工具提示。");
					00H.Add("ScrollTipText", "获取或设置垂直滚动时显示的工具提示文本。");
					00H.Add("ScrollTrack", "确定用户拖动滚动条按钮时网格的表现行为。");
					00H.Add("Select", "选择一个单元格或一个单元格区域。");
					00H.Add("Selected", "取得已选择行的集合。");
					00H.Add("Selection", "获取当前所选内容所对应的CellRange对象。");
					00H.Add("SelectionMode", "指定网格的选择模式。");
					00H.Add("SetData", "为单元格分配数据。");
					00H.Add("SetDataBinding", "设置DataSource和DataMember的属性。");
					00H.Add("ShowButtons", "确定网格何时在可编辑单元格中显示下拉式按钮或弹出式按钮。");
					00H.Add("ShowCell", "滚动网格，使某单元格可见。");
					00H.Add("ShowCursor", "确定网格是否显示选择符图像。");
					00H.Add("ShowSort", "显示一个表示排序方向的图标");
					00H.Add("ShowSortAt", "在特定列显示一个表示排序方向的图标。");
					00H.Add("Sort", "根据一列或多列的内容对整个网格或一定范围内的行集合进行排序。");
					00H.Add("StartEditing", "使网格进入编辑模式并开始编辑单元格。");
					00H.Add("Style.Clear", "清除当前样式中选定的元素。");
					00H.Add("Styles", "获取网格中单元格样式的集合。");
					00H.Add("Subtotal", "根据行的内容对行进行分组和合计。");
					00H.Add("SubtotalPosition", "确定Subtotal方法是否在所汇总数据的上方或下方增加节点行。");
					00H.Add("TextAlign", "获取或设置单元格文本的对齐方式。");
					00H.Add("TextEffect", "获取或设置单元格文本的显示效果。");
					00H.Add("TopRow", "获取或设置当前可见的非固定行中最上一行的索引。");
					00H.Add("Tree", "获取控制网格中大纲组树外观的GridTree对象。");
					00H.Add("Trimming", "确定当文本过长而超出单元格时，文本的剪裁方式。");
					00H.Add("Visible", "获取或设置该列的可见性。");
					00H.Add("Width", "获取或设置该列列宽，并以像素表示 (如果采用默认列宽，则返回值为-1) 。");
					00H.Add("WordWrap", "指定是否允许长字符串在单元格内自动换行。");
					00H.Add("AllowAddNew", "确定用户是否可以在最后一行之后新建数据行。");
					00H.Add("AllowDelete", "指定当按下DEL键时是否可以删除被选中的行。");
					00H.Add("ShowErrors", "设定是否监视数据源显示错误信息。");
					00H.Add("Glyphs", "取得图像(排序方向及复选框等)集合。");
					00I.Add("Layout", "布局");
					00J.Add("Are you sure you want to clear all styles?", "是否删除所有样式？");
					00J.Add("Built-In Styles", "内置样式");
					00J.Add("Column {0} selected.", "选择了第{0}列。");
					00J.Add("Columns {0}-{1} selected ({2} cols).", "选择了第{0}至第{1}列(共{2}列)。");
					00J.Add("Custom Styles", "自定义样式");
					00J.Add("No columns selected", "没有选择列。");
					00J.Add("Please confirm", "请确认");
					00J.Add("Sorry, this name is invalid.", "对不起，名字不正确。");
					00J.Add("About C1FlexGrid...", "关于C1FlexGrid...");
					00J.Add("Edit Styles...", "样式编辑器(&E)...");
					00J.Add("Edit Columns...", "列编辑器(&M)...");
					Hashtable hashtable4 = new Hashtable();
					hashtable4.Add("C1FlexGrid Auto Format", "FlexGrid自动套用格式");
					hashtable4.Add("&Cancel", "取消(&C)");
					hashtable4.Add("&OK", "确定(&O)");
					hashtable4.Add("Formats", "格式");
					hashtable4.Add("Preview", "预览");
					Hashtable hashtable5 = new Hashtable();
					hashtable5.Add("C1FlexGrid Column Editor", "FlexGrid列编辑器");
					hashtable5.Add("Adjust column widths after loading data", "按导入数据调整列宽");
					hashtable5.Add("Align center", "居中对齐");
					hashtable5.Add("Align left", "左对齐");
					hashtable5.Add("Align right", "右对齐");
					hashtable5.Add("Cancel", "取消");
					hashtable5.Add("Delete columns", "删除列");
					hashtable5.Add("Group properties by category", "按分类显示");
					hashtable5.Add("Insert columns after selection", "在其右侧插入列");
					hashtable5.Add("Insert columns before selection", "在其左侧插入列");
					hashtable5.Add("Make all columns visible", "使所有列可见");
					hashtable5.Add("Make selected columns narrower", "减小列宽");
					hashtable5.Add("Make selected columns the same width", "使列宽相同");
					hashtable5.Add("Make selected columns wider", "增加列宽");
					hashtable5.Add("Reload all columns from data source", "从数据源重新导入数据");
					hashtable5.Add("Show property help", "显示属性帮助信息");
					hashtable5.Add("Undo all changes", "撤消所有更改");
					Hashtable hashtable6 = new Hashtable();
					hashtable6.Add("C1FlexGrid Style Editor", "FlexGrid样式编辑器");
					hashtable6.Add("&Cancel", "取消(&C)");
					hashtable6.Add("&OK", "确定(&O)");
					hashtable6.Add("Add", "添加(&A)");
					hashtable6.Add("AutoFormat...", "自动套用格式(&F)...");
					hashtable6.Add("Clear", "清除(&L)");
					hashtable6.Add("Current Style", "当前样式");
					hashtable6.Add("Remove", "删除(&R)");
					00K.Add("GridAutoFormatForm", hashtable4);
					00K.Add("GridColumnEditorForm", hashtable5);
					00K.Add("GridStyleEditorForm", hashtable6);
				}
			}
		}
	}
}
namespace C1.Win.C1FlexGrid.Util.Styles
{
	internal class H
	{
		internal Margins I1 = new Margins(0, 0, 0, 0);

		internal Brush I2;

		internal H()
		{
		}//IL_0005: Unknown result type (might be due to invalid IL or missing references)
		//IL_000f: Expected O, but got Unknown


		internal H(Brush brush, int thickness)
		{
			//IL_0005: Unknown result type (might be due to invalid IL or missing references)
			//IL_000f: Expected O, but got Unknown
			//IL_0021: Unknown result type (might be due to invalid IL or missing references)
			//IL_002b: Expected O, but got Unknown
			I2 = brush;
			I1 = new Margins(thickness, thickness, thickness, thickness);
		}

		internal H(Brush brush, int left, int right, int top, int bottom)
		{
			//IL_0005: Unknown result type (might be due to invalid IL or missing references)
			//IL_000f: Expected O, but got Unknown
			//IL_0023: Unknown result type (might be due to invalid IL or missing references)
			//IL_002d: Expected O, but got Unknown
			I2 = brush;
			I1 = new Margins(left, right, top, bottom);
		}

		internal H(Color color, int thickness)
		{
			//IL_0005: Unknown result type (might be due to invalid IL or missing references)
			//IL_000f: Expected O, but got Unknown
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			//IL_0026: Unknown result type (might be due to invalid IL or missing references)
			//IL_0030: Expected O, but got Unknown
			I2 = (Brush)new SolidBrush(color);
			I1 = new Margins(thickness, thickness, thickness, thickness);
		}

		internal H(Color color, int left, int right, int top, int bottom)
		{
			//IL_0005: Unknown result type (might be due to invalid IL or missing references)
			//IL_000f: Expected O, but got Unknown
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			//IL_0028: Unknown result type (might be due to invalid IL or missing references)
			//IL_0032: Expected O, but got Unknown
			I2 = (Brush)new SolidBrush(color);
			I1 = new Margins(left, right, top, bottom);
		}

		internal Rectangle 2M(Rectangle 00M)
		{
			Margins 6 = 2N();
			return 05.4K(00M, 6);
		}

		public virtual Margins 2N()
		{
			//IL_000b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0011: Expected O, but got Unknown
			return (Margins)I1.Clone();
		}

		public virtual void 2O(Graphics 00N, Rectangle 00O)
		{
			int width = 00O.Width;
			int height = 00O.Height;
			if (I2 != null && width > 0 && height > 0)
			{
				Margins val = 2N();
				if (val.Left > width)
				{
					val.Left = width;
				}
				if (val.Right > width)
				{
					val.Right = width;
				}
				if (val.Top > height)
				{
					val.Top = height;
				}
				if (val.Bottom > height)
				{
					val.Bottom = height;
				}
				if (val.Left > 0)
				{
					00N.FillRectangle(I2, 00O.X, 00O.Y, val.Left, 00O.Height);
				}
				if (val.Top > 0)
				{
					00N.FillRectangle(I2, 00O.X, 00O.Y, 00O.Width, val.Top);
				}
				if (val.Right > 0)
				{
					00N.FillRectangle(I2, 00O.X + 00O.Width - val.Right, 00O.Y, val.Right, 00O.Height);
				}
				if (val.Bottom > 0)
				{
					00N.FillRectangle(I2, 00O.X, 00O.Y + 00O.Height - val.Bottom, 00O.Width, val.Bottom);
				}
			}
		}
	}
	internal class I : H
	{
		internal I()
		{
		}

		internal I(int thickness)
		{
			//IL_000b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0015: Expected O, but got Unknown
			I1 = new Margins(thickness, thickness, thickness, thickness);
		}

		internal I(int left, int right, int top, int bottom)
		{
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Expected O, but got Unknown
			I1 = new Margins(left, right, top, bottom);
		}
	}
	internal class J : H
	{
		internal H I3;

		internal H I4;

		protected J()
		{
		}

		internal J(H outer, H inner)
		{
			I3 = outer;
			I4 = inner;
		}

		internal void 2P(H 00P)
		{
			I3 = ((I3 == null) ? 00P : new J(00P, I3));
		}

		internal void 2Q(H 00Q)
		{
			I4 = ((I4 == null) ? 00Q : new J(I4, 00Q));
		}

		public override Margins 2N()
		{
			//IL_004c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0052: Expected O, but got Unknown
			Margins val = I3.2N();
			Margins val2 = I4.2N();
			return new Margins(val.Left + val2.Left, val.Right + val2.Right, val.Top + val2.Top, val.Bottom + val2.Bottom);
		}

		public override void 2O(Graphics 00R, Rectangle 00S)
		{
			I3.2O(00R, 00S);
			00S = I3.2M(00S);
			I4.2O(00R, 00S);
		}
	}
	internal class K : J
	{
		internal K()
		{
			I3 = new H(SystemColors.ControlDark, 0, 1, 0, 1);
			I4 = new H(SystemColors.ControlLightLight, 1, 0, 1, 0);
		}

		internal K(int horz, int vert)
		{
			I3 = new H(SystemColors.ControlDark, 0, vert, 0, horz);
			I4 = new H(SystemColors.ControlLightLight, vert, 0, horz, 0);
		}
	}
	internal class L : J
	{
		internal L()
		{
			I3 = new H(SystemColors.ControlLightLight, 0, 1, 0, 1);
			I4 = new H(SystemColors.ControlDark, 1, 0, 1, 0);
		}

		internal L(int horz, int vert)
		{
			I3 = new H(SystemColors.ControlLightLight, 0, vert, 0, horz);
			I4 = new H(SystemColors.ControlDark, vert, 0, horz, 0);
		}
	}
	internal class M : J
	{
		internal M()
		{
			I3 = new L();
			I4 = new K();
		}

		internal M(int horz, int vert)
		{
			I3 = new L(horz, vert);
			I4 = new K(horz, vert);
		}
	}
	internal class N : J
	{
		internal N()
		{
			I3 = new K();
			I4 = new L();
		}

		internal N(int horz, int vert)
		{
			I3 = new K(horz, vert);
			I4 = new L(horz, vert);
		}
	}
	internal class O : J
	{
		protected O()
		{
		}

		internal O(Color color, int levels, int thickness)
		{
			2R(color, levels, thickness, thickness);
		}

		internal O(Color color, int levels, int thickness, int spacing)
		{
			2R(color, levels, thickness, spacing);
		}

		internal O(Color color, int[] thickness)
		{
			if (thickness.Length < 3)
			{
				throw new ArgumentException("BorderMulti needs an array with at least three values.");
			}
			I3 = new H(color, thickness[0]);
			for (int i = 1; i < thickness.Length - 1; i += 2)
			{
				2Q(new I(thickness[i]));
				2Q(new H(color, thickness[i + 1]));
			}
		}

		protected void 2R(Color 00T, int 00U, int 00V, int 00W)
		{
			if (00U < 2)
			{
				throw new ArgumentException("BorderMulti needs at least two levels");
			}
			I3 = new H(00T, 00V);
			while (00U > 1)
			{
				2Q(new I(00W));
				2Q(new H(00T, 00V));
				00U--;
			}
		}
	}
	internal class P : O
	{
		internal P(Color color, int thickness)
		{
			2R(color, 2, thickness, thickness);
		}

		internal P(Color color, int thickness, int spacing)
		{
			2R(color, 2, thickness, spacing);
		}
	}
	internal class Q : H
	{
		internal Pen I5;

		public Pen WH
		{
			get
			{
				return I5;
			}
			set
			{
				//IL_0019: Unknown result type (might be due to invalid IL or missing references)
				//IL_0023: Expected O, but got Unknown
				I5 = value;
				int num = (int)I5.Width;
				I1 = new Margins(num, num, num, num);
			}
		}

		protected Q()
		{
		}

		public Q(Pen pen)
		{
			WH = pen;
		}

		public override void 2O(Graphics 00Y, Rectangle 00Z)
		{
			bool flag = I1.Left % 2 != 0;
			int num = I1.Left / 2;
			00Z.Inflate(-num, -num);
			if (flag)
			{
				00Z.Height--;
				00Z.Width--;
			}
			if (00Z.Width > 0 && 00Z.Height > 0)
			{
				00Y.DrawRectangle(I5, 00Z);
			}
		}
	}
	internal class R : Q
	{
		public R(Color color, float thickness)
		{
			//IL_0009: Unknown result type (might be due to invalid IL or missing references)
			//IL_0013: Expected O, but got Unknown
			base.WH = new Pen(color, thickness);
		}

		public R(Color color, float thickness, DashStyle style)
		{
			//IL_0009: Unknown result type (might be due to invalid IL or missing references)
			//IL_0013: Expected O, but got Unknown
			//IL_0019: Unknown result type (might be due to invalid IL or missing references)
			//IL_001f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0020: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Unknown result type (might be due to invalid IL or missing references)
			//IL_0023: Unknown result type (might be due to invalid IL or missing references)
			//IL_0039: Expected I4, but got Unknown
			base.WH = new Pen(color, thickness);
			base.WH.DashStyle = style;
			switch (style - 1)
			{
			case 0:
				base.WH.DashPattern = new float[2] { 8f, 8f };
				break;
			case 2:
				base.WH.DashPattern = new float[4] { 8f, 8f, 1f, 8f };
				break;
			case 3:
				base.WH.DashPattern = new float[6] { 8f, 8f, 1f, 8f, 1f, 8f };
				break;
			case 1:
				base.WH.DashPattern = new float[2] { 1f, 6f };
				break;
			}
		}
	}
}
namespace C1.Win.C1FlexGrid.Util.BaseControls
{
	[EditorBrowsable(EditorBrowsableState.Never)]
	internal abstract class S : TextBox
	{
		private T I6;

		private ContentAlignment I7;

		private Margins I8;

		private int I9;

		public Margins WI
		{
			get
			{
				return I8;
			}
			set
			{
				I8 = value;
				2S();
			}
		}

		public ContentAlignment WJ
		{
			get
			{
				//IL_0001: Unknown result type (might be due to invalid IL or missing references)
				return I7;
			}
			set
			{
				//IL_0001: Unknown result type (might be due to invalid IL or missing references)
				//IL_0002: Unknown result type (might be due to invalid IL or missing references)
				I7 = value;
				2S();
			}
		}

		public string WK
		{
			get
			{
				return I6.WQ;
			}
			set
			{
				I6.WQ = value;
				((Control)this).OnTextChanged((EventArgs)null);
			}
		}

		public string WL => I6.33();

		public char WM
		{
			get
			{
				return I6.WP;
			}
			set
			{
				I6.WP = value;
				((Control)this).OnTextChanged((EventArgs)null);
			}
		}

		public int WN => 2X(201, ((TextBoxBase)this).SelectionStart);

		public int WO => 2W(186);

		public S()
		{
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			//IL_002a: Unknown result type (might be due to invalid IL or missing references)
			I6 = new T((Control)(object)this);
			I9 = 0;
			I8 = new Margins(0, 0, 0, 0);
			I7 = (ContentAlignment)1;
		}

		private void 2S()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_000a: Invalid comparison between Unknown and I4
			//IL_001b: Unknown result type (might be due to invalid IL or missing references)
			//IL_001e: Invalid comparison between Unknown and I4
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_000e: Invalid comparison between Unknown and I4
			//IL_0020: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Invalid comparison between Unknown and I4
			//IL_0010: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Invalid comparison between Unknown and I4
			//IL_00eb: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f4: Invalid comparison between Unknown and I4
			//IL_0028: Unknown result type (might be due to invalid IL or missing references)
			//IL_002e: Invalid comparison between Unknown and I4
			//IL_0014: Unknown result type (might be due to invalid IL or missing references)
			//IL_0017: Invalid comparison between Unknown and I4
			//IL_0107: Unknown result type (might be due to invalid IL or missing references)
			//IL_010d: Invalid comparison between Unknown and I4
			//IL_00f6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f9: Invalid comparison between Unknown and I4
			//IL_010f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0115: Invalid comparison between Unknown and I4
			//IL_00fb: Unknown result type (might be due to invalid IL or missing references)
			//IL_00fe: Invalid comparison between Unknown and I4
			//IL_0117: Unknown result type (might be due to invalid IL or missing references)
			//IL_011d: Invalid comparison between Unknown and I4
			//IL_0100: Unknown result type (might be due to invalid IL or missing references)
			//IL_0103: Invalid comparison between Unknown and I4
			ContentAlignment i = I7;
			if ((int)i <= 16)
			{
				if ((int)i != 1)
				{
					if ((int)i == 4)
					{
						goto IL_003b;
					}
					if ((int)i != 16)
					{
						goto IL_0044;
					}
				}
				goto IL_0032;
			}
			if ((int)i != 64)
			{
				if ((int)i == 256)
				{
					goto IL_0032;
				}
				if ((int)i != 1024)
				{
					goto IL_0044;
				}
			}
			goto IL_003b;
			IL_003b:
			((TextBox)this).TextAlign = (HorizontalAlignment)1;
			goto IL_004b;
			IL_0044:
			((TextBox)this).TextAlign = (HorizontalAlignment)2;
			goto IL_004b;
			IL_004b:
			I9 = WO;
			07.09 01D = new 07.09
			{
				MD = I8.Left + 1,
				ME = I8.Top,
				MF = ((Control)this).ClientRectangle.Right - I8.Right - 1,
				MG = ((Control)this).ClientRectangle.Bottom - I8.Bottom
			};
			int num = I9 * ((Control)this).Font.Height + 2;
			int num2 = 01D.WX - num;
			i = I7;
			if ((int)i <= 64)
			{
				if (((int)i == 16 || (int)i == 32 || (int)i == 64) && num2 > 0)
				{
					01D.64(0, num2 / 2);
				}
			}
			else if (((int)i == 256 || (int)i == 512 || (int)i == 1024) && num2 > 0)
			{
				01D.64(0, num2);
			}
			2Z(((Control)this).Handle, 179u, IntPtr.Zero, ref 01D);
			return;
			IL_0032:
			((TextBox)this).TextAlign = (HorizontalAlignment)0;
			goto IL_004b;
		}

		public string 2T()
		{
			string text = I6.34();
			if (text != null)
			{
				return text;
			}
			return ((Control)this).Text;
		}

		public bool IsValid()
		{
			return I6.34() != null;
		}

		public int 2U(int 014)
		{
			return I6.30(014);
		}

		protected override void OnKeyPress(KeyPressEventArgs e)
		{
			if (I6.36(e))
			{
				((TextBox)this).OnKeyPress(e);
			}
		}

		protected override void OnTextChanged(EventArgs e)
		{
			if (I6.37(e))
			{
				if (I9 != WO)
				{
					2S();
				}
				((TextBox)this).OnTextChanged(e);
			}
		}

		protected bool 2V()
		{
			return I6.32();
		}

		internal int 2W(int 015)
		{
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			Message val = Message.Create(((Control)this).Handle, 015, (IntPtr)0, (IntPtr)0);
			((Control)this).WndProc(ref val);
			return (int)((Message)(ref val)).Result;
		}

		internal int 2X(int 016, int 017)
		{
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			Message val = Message.Create(((Control)this).Handle, 016, (IntPtr)017, (IntPtr)0);
			((Control)this).WndProc(ref val);
			return (int)((Message)(ref val)).Result;
		}

		internal int 2Y(int 018, Point 019)
		{
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			Message val = Message.Create(((Control)this).Handle, 018, (IntPtr)0, 07.60(019));
			((Control)this).WndProc(ref val);
			return (int)((Message)(ref val)).Result;
		}

		[DllImport("USER32.DLL", EntryPoint = "SendMessage")]
		private static extern IntPtr 2Z(IntPtr 01A, uint 01B, IntPtr 01C, ref 07.09 01D);
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	internal abstract class MaskedComboBox : ComboBox
	{
		private T _mask;

		public string Mask
		{
			get
			{
				return _mask.WQ;
			}
			set
			{
				_mask.WQ = value;
				((Control)this).OnTextChanged((EventArgs)null);
			}
		}

		public string Content => _mask.33();

		public char PlaceHolder
		{
			get
			{
				return _mask.WP;
			}
			set
			{
				_mask.WP = value;
				((Control)this).OnTextChanged((EventArgs)null);
			}
		}

		public MaskedComboBox()
		{
			_mask = new T((Control)(object)this);
		}

		public string GetValidContent()
		{
			string text = _mask.34();
			if (text != null)
			{
				return text;
			}
			return ((Control)this).Text;
		}

		public bool IsValid()
		{
			return _mask.34() != null;
		}

		public int EditPosition(int index)
		{
			return _mask.30(index);
		}

		protected bool IsCombo()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0007: Invalid comparison between Unknown and I4
			return (int)((ComboBox)this).DropDownStyle != 2;
		}

		protected override void OnKeyPress(KeyPressEventArgs e)
		{
			if (!IsCombo() || _mask.36(e))
			{
				((ComboBox)this).OnKeyPress(e);
			}
		}

		protected override void OnKeyDown(KeyEventArgs e)
		{
			((ComboBox)this).OnKeyDown(e);
		}

		protected override void OnTextChanged(EventArgs e)
		{
			if (!IsCombo() || _mask.37(e))
			{
				((ComboBox)this).OnTextChanged(e);
			}
		}

		protected bool IsUpdating()
		{
			return _mask.32();
		}

		internal int SendMessage(int msg, int wParam)
		{
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			Message val = Message.Create(((Control)this).Handle, msg, (IntPtr)wParam, (IntPtr)0);
			((Control)this).WndProc(ref val);
			return (int)((Message)(ref val)).Result;
		}
	}
	internal class T
	{
		private const string IA = "09#L?Aa&";

		private const char IB = '\u0001';

		private const char IC = '\u0002';

		private const char ID = '\u0003';

		private const char IE = '\u0004';

		private const char IF = '\u0005';

		private const char IG = '\u0006';

		private const char IH = '\a';

		private const char II = '\b';

		private const char IJ = '\t';

		private const char IK = '\n';

		private const char IL = '\v';

		private const char IM = '\f';

		private const char IN = '\r';

		private string IO;

		private string IP;

		private char IQ = '\0';

		private char IR = '_';

		private int IS = -1;

		private bool IT = false;

		private bool IU = false;

		private Control IV = null;

		public char WP
		{
			get
			{
				return IR;
			}
			set
			{
				if (value < ' ')
				{
					throw new ArgumentException("PlaceHolder must be a printable character.");
				}
				IR = value;
			}
		}

		public string WQ
		{
			get
			{
				return IO;
			}
			set
			{
				IO = value;
				IS = -1;
				IQ = '\0';
				IR = '_';
				IP = null;
				if (IO == null || IO.Length == 0)
				{
					return;
				}
				NumberFormatInfo currentInfo = NumberFormatInfo.CurrentInfo;
				DateTimeFormatInfo currentInfo2 = DateTimeFormatInfo.CurrentInfo;
				IP = "";
				for (int i = 0; i < IO.Length; i++)
				{
					char c = IO[i];
					if (c == 'C')
					{
						c = '&';
					}
					int num = "09#L?Aa&".IndexOf(c);
					if (num > -1)
					{
						if (IS < 0)
						{
							IS = IP.Length;
						}
						IP += (char)(num + 1);
						continue;
					}
					switch (c)
					{
					case '>':
						IQ = c;
						continue;
					case '<':
						IQ = c;
						continue;
					case '.':
						IP += currentInfo.CurrencyDecimalSeparator;
						continue;
					case ',':
						IP += currentInfo.CurrencyGroupSeparator;
						continue;
					case ':':
						IP += currentInfo2.TimeSeparator;
						continue;
					case '/':
						IP += currentInfo2.DateSeparator;
						continue;
					case '\\':
						if (i < IO.Length - 1)
						{
							i++;
						}
						IP += IO[i];
						continue;
					case ';':
						if (IO.Length > i + 1 && IO[i + 1] >= ' ')
						{
							WP = IO[i + 1];
							i = IO.Length;
							continue;
						}
						break;
					}
					IP += c;
				}
			}
		}

		internal int WR
		{
			get
			{
				//IL_0013: Unknown result type (might be due to invalid IL or missing references)
				//IL_0031: Unknown result type (might be due to invalid IL or missing references)
				if (IV is TextBox)
				{
					return ((TextBoxBase)(TextBox)IV).SelectionStart;
				}
				if (IV is ComboBox)
				{
					return ((ComboBox)IV).SelectionStart;
				}
				return -1;
			}
			set
			{
				//IL_0013: Unknown result type (might be due to invalid IL or missing references)
				//IL_0031: Unknown result type (might be due to invalid IL or missing references)
				if (IV is TextBox)
				{
					((TextBoxBase)(TextBox)IV).SelectionStart = value;
				}
				if (IV is ComboBox)
				{
					((ComboBox)IV).SelectionStart = value;
				}
			}
		}

		internal T(Control ctl)
		{
			IV = ctl;
		}

		public int 30(int 01G)
		{
			int num = ((IP != null) ? IP.Length : 0);
			if (num == 0)
			{
				return 01G;
			}
			int num2 = 0;
			for (int i = 0; i < num; i++)
			{
				if (IP[i] <= '\b')
				{
					if (num2 == 01G)
					{
						return i;
					}
					num2++;
				}
			}
			return num;
		}

		internal string 31()
		{
			string text = "";
			int num = 0;
			string text2 = 33();
			for (int i = 0; i < IP.Length; i++)
			{
				if (IP[i] > '\b')
				{
					text += IP[i];
					continue;
				}
				bool flag = false;
				while (num < text2.Length)
				{
					char c = text2[num++];
					flag = c == IR || 35(c, IP[i]);
					if (flag)
					{
						if (IQ == '>')
						{
							c = char.ToUpper(c, CultureInfo.CurrentCulture);
						}
						if (IQ == '<')
						{
							c = char.ToLower(c, CultureInfo.CurrentCulture);
						}
						text += c;
						break;
					}
				}
				if (!flag)
				{
					text += IR;
				}
			}
			return text;
		}

		internal bool 32()
		{
			return IU;
		}

		internal string 33()
		{
			string text = "";
			if (IP == null || IP.Length == 0)
			{
				return IV.Text;
			}
			string text2 = IV.Text;
			int wR = WR;
			int num = IP.Length - text2.Length;
			for (int i = 0; i < text2.Length; i++)
			{
				int num2 = i;
				if (i >= wR)
				{
					num2 += num;
				}
				if (num2 < 0 || num2 >= IP.Length || IP[num2] <= '\b' || !35(text2[i], IP[num2]))
				{
					text += text2[i];
				}
			}
			return text;
		}

		internal string 34()
		{
			string text = IV.Text;
			string text2 = "";
			if (IP == null || IP.Length == 0)
			{
				return text;
			}
			int num = 0;
			for (int i = 0; i < IP.Length; i++)
			{
				char c = IP[i];
				if (num >= text.Length)
				{
					return null;
				}
				char c2 = text[num];
				if (c2 == IR)
				{
					switch (c)
					{
					case '\u0002':
					case '\u0003':
					case '\u0005':
					case '\a':
					case '\b':
						text2 += ' ';
						num++;
						break;
					default:
						return null;
					}
				}
				else
				{
					if (!35(c2, c))
					{
						return null;
					}
					text2 += c2;
					num++;
				}
			}
			if (num != text.Length)
			{
				return null;
			}
			return text2;
		}

		internal static bool 35(char 01H, char 01I)
		{
			switch (01I)
			{
			case '\u0001':
				return char.IsDigit(01H);
			case '\u0002':
				if (!char.IsDigit(01H))
				{
					return 01H == ' ';
				}
				return true;
			case '\u0003':
				if (!char.IsDigit(01H))
				{
					if (01H != ' ' && 01H != '+')
					{
						return 01H == '-';
					}
					return true;
				}
				return true;
			case '\u0004':
				return char.IsLetter(01H);
			case '\u0005':
				if (!char.IsLetter(01H))
				{
					return 01H == ' ';
				}
				return true;
			case '\u0006':
				return char.IsLetterOrDigit(01H);
			case '\a':
				if (!char.IsLetterOrDigit(01H))
				{
					return 01H == ' ';
				}
				return true;
			case '\b':
				return true;
			default:
				return 01H == 01I;
			}
		}

		internal bool 36(KeyPressEventArgs 01J)
		{
			//IL_002a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			if (IP == null || IP.Length == 0)
			{
				return true;
			}
			if (IV is TextBox)
			{
				((TextBoxBase)(TextBox)IV).MaxLength = 0;
			}
			if (IV is ComboBox)
			{
				((ComboBox)IV).MaxLength = 0;
			}
			IT = 01J.KeyChar == '\b';
			if (char.IsControl(01J.KeyChar))
			{
				return true;
			}
			int num = WR;
			if (num < IS)
			{
				int num2 = (WR = IS);
				num = num2;
			}
			if (num > -1 && num < IP.Length && !35(01J.KeyChar, IP[num]))
			{
				01J.Handled = true;
			}
			if (num == IP.Length)
			{
				01J.Handled = true;
			}
			return !01J.Handled;
		}

		internal bool 37(EventArgs 01K)
		{
			if (IU)
			{
				return false;
			}
			if (IP == null || IP.Length == 0)
			{
				return true;
			}
			bool flag = IV.Text.Length > IP.Length + 1;
			string text = 31();
			if (text == IV.Text)
			{
				return false;
			}
			int i = WR;
			IU = true;
			IV.Text = text;
			if (i > -1 && !flag)
			{
				if (i == 0)
				{
					IT = false;
				}
				for (; i < IP.Length - 1 && IP[i] >= '\t'; i++)
				{
					if (IT)
					{
						break;
					}
				}
				if (i < IS)
				{
					i = IS;
				}
				38(i, 0);
			}
			if (flag)
			{
				IT = false;
				for (i = IS; i < IV.Text.Length && IV.Text[i] != IR; i++)
				{
				}
				38(i, 0);
			}
			IU = false;
			return true;
		}

		internal void 38(int 01M, int 01N)
		{
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			if (IV is TextBox)
			{
				((TextBoxBase)(TextBox)IV).Select(01M, 01N);
				return;
			}
			if (IV is ComboBox)
			{
				((ComboBox)IV).Select(01M, 01N);
				return;
			}
			throw new Exception("Shouldn't happen!");
		}
	}
	public enum BorderStyleEnum
	{
		None,
		FixedSingle,
		Fixed3D,
		Light3D
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	public abstract class ScrollableControl : Control
	{
		private BorderStyleEnum IW;

		private ScrollBars IX;

		private bool IY;

		private bool IZ;

		private ToolTip J0;

		private Cursor J1;

		private Point J2;

		private Size J3;

		private Size J4;

		private Size J5;

		private bool J6;

		private bool J7;

		private bool J8;

		private bool J9;

		private 0A JA;

		private Rectangle JB;

		[E("Layout")]
		[DefaultValue(/*Could not decode attribute arguments.*/)]
		[Browsable(true)]
		[D("ScrollBars", "Gets or sets which scroll bars should appear on the control.")]
		public ScrollBars ScrollBars
		{
			get
			{
				//IL_0001: Unknown result type (might be due to invalid IL or missing references)
				return IX;
			}
			set
			{
				//IL_0001: Unknown result type (might be due to invalid IL or missing references)
				//IL_0002: Unknown result type (might be due to invalid IL or missing references)
				//IL_0009: Unknown result type (might be due to invalid IL or missing references)
				//IL_000f: Invalid comparison between Unknown and I4
				//IL_0012: Unknown result type (might be due to invalid IL or missing references)
				//IL_0018: Invalid comparison between Unknown and I4
				//IL_0024: Unknown result type (might be due to invalid IL or missing references)
				//IL_002a: Invalid comparison between Unknown and I4
				//IL_002d: Unknown result type (might be due to invalid IL or missing references)
				//IL_0033: Invalid comparison between Unknown and I4
				IX = value;
				IY = (int)IX == 1 || (int)IX == 3;
				IZ = (int)IX == 2 || (int)IX == 3;
				WS = J3;
				((Control)this).Invalidate();
			}
		}

		[Browsable(false)]
		internal Size WS
		{
			get
			{
				return J3;
			}
			set
			{
				if (!J7)
				{
					J3 = value;
				}
				else
				{
					if ((value == J3 && ((Control)this).ClientSize == J4) || J9)
					{
						return;
					}
					J9 = true;
					3F(1, 0, 0);
					3F(0, 0, 0);
					Size clientSize = ((Control)this).ClientSize;
					for (int i = 0; i < 5; i++)
					{
						3F(0, value.Width, clientSize.Width + 1);
						3F(1, value.Height, clientSize.Height + 1);
						if (clientSize == ((Control)this).ClientSize)
						{
							break;
						}
						clientSize = ((Control)this).ClientSize;
					}
					J3 = value;
					J4 = ((Control)this).ClientSize;
					39(J2);
					J9 = false;
				}
			}
		}

		[Browsable(false)]
		internal Size WT
		{
			get
			{
				return J5;
			}
			set
			{
				J5 = value;
			}
		}

		[Browsable(false)]
		internal bool WU
		{
			get
			{
				return J8;
			}
			set
			{
				J8 = value;
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[Browsable(false)]
		[D("ScrollPosition", "Gets or sets the current scroll position.")]
		public Point ScrollPosition
		{
			get
			{
				return J2;
			}
			set
			{
				39(value);
			}
		}

		[Browsable(true)]
		[DefaultValue(true)]
		[Category("Behavior")]
		[D("ScrollTrack", "Gets or sets whether the control should scroll as the user drags the scrollbar thumb.")]
		public bool ScrollTrack
		{
			get
			{
				return J6;
			}
			set
			{
				J6 = value;
			}
		}

		[DefaultValue(false)]
		[Browsable(true)]
		[Category("Behavior")]
		[D("ScrollTips", "Gets or sets whether the control should display tooltips as the user scrolls vertically.")]
		public bool ScrollTips
		{
			get
			{
				if (J0 != null)
				{
					return J0.Active;
				}
				return false;
			}
			set
			{
				//IL_0016: Unknown result type (might be due to invalid IL or missing references)
				//IL_0020: Expected O, but got Unknown
				if (value == ScrollTips)
				{
					return;
				}
				if (J0 == null && value)
				{
					try
					{
						J0 = new ToolTip();
						J0.SetToolTip((Control)(object)this, " ");
						J0.InitialDelay = 30000;
						J0.ReshowDelay = 30000;
						return;
					}
					catch
					{
					}
				}
				if (J0 != null)
				{
					J0.Active = value;
				}
			}
		}

		[D("ScrollTipText", "Gets or sets the tooltip text displayed as the user scrolls vertically.")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[Browsable(false)]
		public string ScrollTipText
		{
			get
			{
				if (J0 == null)
				{
					return "";
				}
				return J0.GetToolTip((Control)(object)this);
			}
			set
			{
				if (!(value == ScrollTipText) && J0 != null)
				{
					J0.SetToolTip((Control)(object)this, value);
				}
			}
		}

		[D("BorderStyle", "Gets or sets the type of border around the control.")]
		[Browsable(true)]
		[DefaultValue(BorderStyleEnum.Fixed3D)]
		[Category("Appearance")]
		public BorderStyleEnum BorderStyle
		{
			get
			{
				return IW;
			}
			set
			{
				if (IW != value)
				{
					IW = value;
					((Control)this).UpdateStyles();
				}
			}
		}

		[D("Cursor", "Gets or sets the cursor that appears when the mouse moves over the control.")]
		public override Cursor Cursor
		{
			get
			{
				return ((Control)this).Cursor;
			}
			set
			{
				J1 = value;
				if (value != ((Control)this).Cursor)
				{
					((Control)this).Cursor = value;
				}
			}
		}

		internal Cursor WV
		{
			get
			{
				return ((Control)this).Cursor;
			}
			set
			{
				if (value == (Cursor)null)
				{
					value = J1;
				}
				((Control)this).Cursor = value;
			}
		}

		internal bool WW
		{
			get
			{
				return J7;
			}
			set
			{
				if (J7 != value)
				{
					J7 = value;
					if (J7)
					{
						WS = J3;
						ScrollPosition = J2;
						((Control)this).Invalidate();
					}
				}
			}
		}

		public virtual Rectangle ScrollableRectangle => ((Control)this).ClientRectangle;

		protected override CreateParams CreateParams
		{
			get
			{
				CreateParams createParams = ((Control)this).CreateParams;
				createParams.Style |= 0x6000000;
				switch (IW)
				{
				case BorderStyleEnum.FixedSingle:
					createParams.Style |= 0x800000;
					break;
				case BorderStyleEnum.Fixed3D:
					createParams.ExStyle |= 0x200;
					break;
				case BorderStyleEnum.Light3D:
					createParams.ExStyle |= 0x20000;
					break;
				}
				return createParams;
			}
		}

		protected ScrollableControl()
		{
			((Control)this).SetStyle((ControlStyles)512, true);
			((Control)this).SetStyle((ControlStyles)8192, true);
			((Control)this).SetStyle((ControlStyles)2, true);
			((Control)this).SetStyle((ControlStyles)65536, true);
			((Control)this).SetStyle((ControlStyles)2048, true);
			((Control)this).SetStyle((ControlStyles)16, true);
			J7 = true;
			J6 = true;
			ref Point j = ref J2;
			j = new Point(0, 0);
			ref Size j2 = ref J3;
			j2 = new Size(0, 0);
			ref Size j3 = ref J5;
			j3 = new Size(10, 10);
			J1 = Cursors.Default;
			J8 = true;
			BorderStyle = BorderStyleEnum.Fixed3D;
			ScrollBars = (ScrollBars)3;
			JA = new 0A((Control)(object)this);
		}

		protected override void Dispose(bool disposing)
		{
			if (J0 != null)
			{
				J0.AutomaticDelay = 0;
				J0.RemoveAll();
				((Component)(object)J0).Dispose();
				J0 = null;
			}
			if (JA != null)
			{
				JA.66();
				JA = null;
			}
			((Control)this).Dispose(disposing);
		}

		private void 39(Point 01R)
		{
			if (!J7)
			{
				J2 = 01R;
				return;
			}
			3E(0, -01R.X);
			3E(1, -01R.Y);
			int num = 3C(0);
			int num2 = 3C(1);
			if (!IY)
			{
				num = Math.Min(-01R.X, J3.Width - ((Control)this).ClientSize.Width);
				if (num < 0)
				{
					num = 0;
				}
			}
			if (!IZ)
			{
				num2 = Math.Min(-01R.Y, J3.Height - ((Control)this).ClientSize.Height);
				if (num2 < 0)
				{
					num2 = 0;
				}
			}
			Point point = new Point(-num, -num2);
			if (point == J2)
			{
				return;
			}
			int num3 = point.X - J2.X;
			int num4 = point.Y - J2.Y;
			07.09  = Rectangle.Empty;
			bool flag = J8 && ((Control)this).BackgroundImage == null;
			if (flag)
			{
				 = BuildScrollableRectangle(num3, num4);
				if (.WY <= 0)
				{
					flag = false;
				}
			}
			if (flag && (JB.Width >= .WY || Math.Abs(num3) >= .WY || JB.Height >= .WX || Math.Abs(num4) >= .WX))
			{
				flag = false;
			}
			if (flag)
			{
				((Control)this).Update();
			}
			J2 = point;
			if (num3 != 0)
			{
				OnScroll((ScrollBars)1);
			}
			if (num4 != 0)
			{
				OnScroll((ScrollBars)2);
			}
			if (flag)
			{
				3G(, num3, num4);
			}
			else
			{
				((Control)this).Invalidate();
			}
		}

		protected void DrawComboButton(Graphics g, Rectangle rc, ButtonState bs)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			JA.67(g, rc, bs);
		}

		protected void DrawButton(Graphics g, Rectangle rc, ButtonState bs)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			JA.68(g, rc, bs);
		}

		protected virtual void OnImeStartComposition()
		{
		}

		protected virtual void OnScroll(ScrollBars sb)
		{
			((Control)this).Invalidate();
		}

		protected virtual void OnScrollTip(int newValue)
		{
		}

		protected virtual Rectangle BuildScrollableRectangle(int dx, int dy)
		{
			return ScrollableRectangle;
		}

		protected override void SetClientSizeCore(int x, int y)
		{
			if (J3.Width > x)
			{
				y += SystemInformation.HorizontalScrollBarHeight;
			}
			if (J3.Height > y)
			{
				x += SystemInformation.VerticalScrollBarWidth;
			}
			((Control)this).SetClientSizeCore(x, y);
		}

		protected override void OnInvalidated(InvalidateEventArgs e)
		{
			JB = e.InvalidRect;
			((Control)this).OnInvalidated(e);
		}

		protected override void OnPaint(PaintEventArgs e)
		{
			JB = Rectangle.Empty;
			((Control)this).OnPaint(e);
		}

		protected override void OnSizeChanged(EventArgs e)
		{
			if (!J9)
			{
				WS = J3;
				((Control)this).OnSizeChanged(e);
			}
		}

		protected override void OnMouseWheel(MouseEventArgs e)
		{
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			//IL_001c: Unknown result type (might be due to invalid IL or missing references)
			//IL_002b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0035: Unknown result type (might be due to invalid IL or missing references)
			int num = e.Delta / 120;
			num *= SystemInformation.MouseWheelScrollLines;
			if ((Control.ModifierKeys & 0x10000) != 0)
			{
				num *= 10;
			}
			Point scrollPosition = ScrollPosition;
			if ((Control.ModifierKeys & 0x20000) != 0)
			{
				scrollPosition.X += num * J5.Width;
			}
			else
			{
				scrollPosition.Y += num * J5.Height;
			}
			ScrollPosition = scrollPosition;
		}

		protected override void WndProc(ref Message m)
		{
			//IL_0042: Unknown result type (might be due to invalid IL or missing references)
			switch (((Message)(ref m)).Msg)
			{
			case 794:
				JA.66();
				break;
			case 269:
				OnImeStartComposition();
				break;
			case 276:
			case 277:
				3A(m);
				return;
			}
			((Control)this).WndProc(ref m);
		}

		private void 3A(Message 01U)
		{
			int num = 0;
			int num2 = 0;
			int num3 = 0;
			switch (((Message)(ref 01U)).Msg)
			{
			case 276:
				num = 0;
				num2 = J5.Width;
				num3 = ScrollableRectangle.Width;
				break;
			case 277:
				num = 1;
				num2 = J5.Height;
				num3 = ScrollableRectangle.Height;
				break;
			default:
				throw new Exception("Unexpected message in scroll routine");
			}
			int num4 = 3C(num);
			switch (((Message)(ref 01U)).WParam.ToInt32() & 0xFFFF)
			{
			case 6:
				num4 = 0;
				break;
			case 7:
				num4 = int.MaxValue;
				break;
			case 1:
				num4 += num2;
				break;
			case 0:
				num4 -= num2;
				break;
			case 3:
				num4 += num3;
				break;
			case 2:
				num4 -= num3;
				break;
			case 4:
				num4 = 3D(num);
				break;
			case 5:
				num4 = 3D(num);
				if (((Message)(ref 01U)).Msg == 277 && J0 != null && J0.Active)
				{
					J0.InitialDelay = 0;
					OnScrollTip(num4);
				}
				if (!J6)
				{
					return;
				}
				break;
			case 8:
				if (J0 != null && J0.Active)
				{
					J0.InitialDelay = 30000;
					J0.Active = false;
					J0.Active = true;
				}
				break;
			}
			if (num4 != 3C(num))
			{
				3E(num, num4);
				Point j = J2;
				if (IY)
				{
					j.X = -3C(0);
				}
				if (IZ)
				{
					j.Y = -3C(1);
				}
				ScrollPosition = j;
			}
		}

		private int 3B(int 01V)
		{
			return 07.5W(((Control)this).Handle, 01V);
		}

		private int 3C(int 01W)
		{
			return 07.5V(((Control)this).Handle, 01W);
		}

		private int 3D(int 01X)
		{
			return 07.5U(((Control)this).Handle, 01X);
		}

		private int 3E(int 01Y, int 01Z)
		{
			return 07.5X(((Control)this).Handle, 01Y, 01Z);
		}

		private int 3F(int 020, int 021, int 022)
		{
			if (!IY && 020 == 0)
			{
				021 = 0;
			}
			if (!IZ && 020 == 1)
			{
				021 = 0;
			}
			return 07.5Y(((Control)this).Handle, 020, 021, 022);
		}

		private int 3G(07.09 023, int 024, int 025)
		{
			return 07.5Z(((Control)this).Handle, ref 023, 024, 025);
		}
	}
}
namespace C1.Win.C1FlexGrid.Util.Styles
{
	internal enum U
	{
		JC,
		JD,
		JE,
		JF,
		JG,
		JH,
		JI,
		JJ,
		JK,
		JL,
		JM,
		JN,
		JO
	}
	internal enum V
	{
		JP,
		JQ,
		JR,
		JS,
		JT
	}
	internal enum W
	{
		JU,
		JV,
		JW
	}
	internal enum Z
	{
		JX,
		JY,
		JZ
	}
	internal enum 00
	{
		K0,
		K1,
		K2,
		K3,
		K4
	}
	internal enum 01
	{
		K5,
		K6,
		K7
	}
	[Flags]
	internal enum 02
	{
		K8 = 0,
		K9 = 1,
		KA = 2,
		KB = 4,
		KC = 0xFF
	}
	internal class 03 : EventArgs
	{
		internal readonly Style KD;

		internal 03(Style s)
		{
			KD = s;
		}
	}
	internal delegate void 04(object sender, 03 e);
	internal class 05
	{
		internal Style KE;

		internal Hashtable KF;

		internal StringFormat KG;

		internal static Brush KH = (Brush)new SolidBrush(Color.FromArgb(90, Color.Black));

		internal static Brush KI = (Brush)new SolidBrush(Color.FromArgb(90, Color.White));

		private 04 KJ;

		internal Brush KK;

		internal event 04 XK
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				KJ = (04)Delegate.Combine(KJ, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				KJ = (04)Delegate.Remove(KJ, value);
			}
		}

		internal 05()
		{
			3H(StringFormat.GenericDefault);
		}

		internal 05(StringFormat fmt)
		{
			3H(fmt);
		}

		internal void 3H(StringFormat 028)
		{
			//IL_0002: Unknown result type (might be due to invalid IL or missing references)
			//IL_000c: Expected O, but got Unknown
			KG = new StringFormat(028);
			KG.SetTabStops(0f, new float[8] { 150f, 150f, 150f, 150f, 150f, 150f, 150f, 150f });
			KF = new Hashtable(CaseInsensitiveHashCodeProvider.Default, CaseInsensitiveComparer.Default);
			KE = new Style(this, "Base", null);
			3J();
		}

		internal void 3I(Brush 029)
		{
			KK = 029;
		}

		internal void 3J()
		{
			//IL_0079: Unknown result type (might be due to invalid IL or missing references)
			//IL_0083: Expected O, but got Unknown
			//IL_008d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0097: Expected O, but got Unknown
			Hashtable kO = KE.KO;
			kO.Add("BackColor", SystemBrushes.Window);
			kO.Add("ForeColor", SystemBrushes.WindowText);
			kO.Add("Opaque", true);
			kO.Add("Font", Control.DefaultFont);
			kO.Add("Trimming", (object)(StringTrimming)0);
			kO.Add("Wrap", true);
			kO.Add("Margins", (object?)new Margins(0, 0, 0, 0));
			kO.Add("Padding", (object?)new Margins(0, 0, 0, 0));
			kO.Add("Border", new H());
			kO.Add("AlignHorz", V.JP);
			kO.Add("AlignVert", W.JU);
			kO.Add("TextEffect", Z.JX);
			kO.Add("AlignImage", U.JD);
			kO.Add("Spacing", 2);
			kO.Add("Display", 00.K3);
			kO.Add("Direction", 01.K5);
		}

		internal void 3K(03 02A)
		{
			if (KJ != null)
			{
				KJ(this, 02A);
			}
		}

		internal void 3L(Style 02B)
		{
			03 02A = new 03(02B);
			3K(02A);
		}

		internal Style 3M(string 02C, Style 02D)
		{
			if (02C == null)
			{
				02C = 4G();
			}
			Style style = new Style(this, 02C, 02D);
			KF.Add(02C, style);
			return style;
		}

		internal Style 3N(string 02E, string 02F)
		{
			return 3M(02E, 3W(02F));
		}

		internal Style 3O(string 02G)
		{
			return 3M(02G, null);
		}

		internal Style 3P()
		{
			return 3M(null, null);
		}

		internal void 3Q(string 02H)
		{
			3R(3W(02H));
		}

		internal void 3R(Style 02I)
		{
			Style 04D = 02I.4N();
			foreach (Style item in 3Y())
			{
				if (item.4N() == 02I)
				{
					item.4P(04D);
				}
			}
			KF.Remove(02I.4L());
			3L(null);
		}

		internal bool 3S(Style 02J, string 02K)
		{
			Style style = (Style)KF[02K];
			if (style != null && style != 02J)
			{
				return false;
			}
			KF.Remove(02J.4L());
			02J.KM = 02K;
			KF.Add(02K, 02J);
			return true;
		}

		internal void 3T()
		{
			KF.Clear();
			3L(null);
		}

		internal int 3U()
		{
			return KF.Count;
		}

		internal Style 3V()
		{
			return KE;
		}

		internal Style 3W(string 02L)
		{
			Style style = (Style)KF[02L];
			if (style == null)
			{
				throw new ArgumentException("Style '" + 02L + "' not defined");
			}
			return (Style)KF[02L];
		}

		internal bool 3X(string 02M)
		{
			return KF.Contains(02M);
		}

		internal ICollection 3Y()
		{
			return KF.Values;
		}

		internal void 3Z(Style 02N, Graphics 02O, Rectangle 02P, string 02Q, Image 02R, 02 02S)
		{
			//IL_0046: Unknown result type (might be due to invalid IL or missing references)
			//IL_004c: Expected O, but got Unknown
			//IL_0088: Unknown result type (might be due to invalid IL or missing references)
			//IL_008e: Expected O, but got Unknown
			//IL_0024: Unknown result type (might be due to invalid IL or missing references)
			//IL_002a: Expected O, but got Unknown
			if ((02S & 02.K9) != 02.K8 && (bool)02N.4V("Opaque"))
			{
				Brush val = (Brush)02N.4V("BackColor");
				if (val != KK)
				{
					02O.FillRectangle(val, 02P);
				}
			}
			Margins 6 = (Margins)02N.4V("Margins");
			02P = 4K(02P, 6);
			H h = (H)02N.4V("Border");
			if ((02S & 02.KA) != 02.K8)
			{
				h.2O(02O, 02P);
			}
			02P = h.2M(02P);
			6 = (Margins)02N.4V("Padding");
			02P = 4K(02P, 6);
			if ((02S & 02.KB) != 02.K8)
			{
				46(02N, 02O, 02P, 02Q, 02R);
			}
		}

		internal int 40(Style 02T, Graphics 02U, string 02V, Image 02W)
		{
			//IL_001f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0025: Expected O, but got Unknown
			Rectangle 6 = new Rectangle(0, 0, 0, 0);
			6 = 42(02T, 6);
			Margins 7 = (Margins)02T.4V("Padding");
			int num = -4K(6, 7).Width;
			00 8 = (00)02T.4V("Display");
			switch (8)
			{
			case 00.K4:
				02V = null;
				02W = null;
				break;
			case 00.K1:
				02V = null;
				break;
			case 00.K0:
				02W = null;
				break;
			}
			int num2 = (((01)02T.4V("Direction") == 01.K5) ? 43(02T, 02U, 02V) : 44(02T, 02U, 02V));
			num += num2;
			if (02W != null)
			{
				U u = (U)02T.4V("AlignImage");
				if (8 == 00.K3 && (4C(u) || 4D(u)))
				{
					num += 02W.Width + (int)02T.4V("Spacing");
				}
				else if (02W.Width > num2)
				{
					num += 02W.Width - num2;
				}
			}
			return num;
		}

		internal int 41(Style 02X, Graphics 02Y, int 02Z, string 030, Image 031)
		{
			//IL_001f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0025: Expected O, but got Unknown
			Rectangle 32 = new Rectangle(0, 0, 02Z, 0);
			32 = 42(02X, 32);
			Margins 33 = (Margins)02X.4V("Padding");
			32 = 4K(32, 33);
			int num = -32.Height;
			02Z = 32.Width;
			00 34 = (00)02X.4V("Display");
			switch (34)
			{
			case 00.K1:
				030 = null;
				break;
			case 00.K0:
				031 = null;
				break;
			}
			int num2 = (((01)02X.4V("Direction") == 01.K5) ? 45(02X, 02Y, 02Z, 030) : 43(02X, 02Y, 030));
			num += num2;
			if (031 != null)
			{
				U u = (U)02X.4V("AlignImage");
				if (34 == 00.K3 && (4E(u) || 4F(u)))
				{
					num += 031.Height + (int)02X.4V("Spacing");
				}
				else if (031.Height > num2)
				{
					num += 031.Height - num2;
				}
			}
			return num;
		}

		internal Rectangle 42(Style 032, Rectangle 033)
		{
			//IL_000b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0011: Expected O, but got Unknown
			Margins 34 = (Margins)032.4V("Margins");
			033 = 4K(033, 34);
			H h = (H)032.4V("Border");
			34 = h.2N();
			033 = 4K(033, 34);
			return 033;
		}

		internal int 43(Style 034, Graphics 035, string 036)
		{
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			//IL_001e: Expected O, but got Unknown
			if (036 == null || 036.Length == 0)
			{
				return 0;
			}
			Font val = (Font)034.4V("Font");
			return (int)035.MeasureString(036, val).Width + 1;
		}

		internal int 44(Style 037, Graphics 038, string 039)
		{
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			//IL_001e: Expected O, but got Unknown
			if (039 == null || 039.Length == 0)
			{
				return 0;
			}
			Font val = (Font)037.4V("Font");
			return (int)038.MeasureString(039, val).Height;
		}

		internal int 45(Style 03A, Graphics 03B, int 03C, string 03D)
		{
			//IL_001a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0020: Expected O, but got Unknown
			if (03D == null || 03D.Length == 0)
			{
				return 0;
			}
			Font val = (Font)03A.4V("Font");
			4H(03A, 03D, 044: false);
			return (int)03B.MeasureString(03D, val, 03C, KG).Height + 1;
		}

		internal void 46(Style 03E, Graphics 03F, Rectangle 03G, string 03H, Image 03I)
		{
			if (03G.Width <= 0 || 03G.Height <= 0)
			{
				return;
			}
			00 6 = (00)03E.4V("Display");
			switch (6)
			{
			case 00.K1:
				03H = null;
				break;
			case 00.K0:
				03I = null;
				break;
			}
			bool flag = 03I != null;
			bool flag2 = 03H != null && 03H.Length > 0;
			if (flag || flag2)
			{
				if (flag)
				{
					47(03E, 03F, 03G, 03I);
				}
				if (flag && flag2 && 6 == 00.K3)
				{
					03G = 4A(03E, 03G, 03I);
				}
				if (flag2)
				{
					48(03E, 03F, 03G, 03H);
				}
			}
		}

		internal void 47(Style 03J, Graphics 03K, Rectangle 03L, Image 03M)
		{
			//IL_0039: Unknown result type (might be due to invalid IL or missing references)
			//IL_003f: Expected O, but got Unknown
			//IL_00c5: Unknown result type (might be due to invalid IL or missing references)
			//IL_00cc: Expected O, but got Unknown
			U u = (U)03J.4V("AlignImage");
			switch (u)
			{
			case U.JM:
				03K.DrawImage(03M, 03L);
				return;
			case U.JN:
			{
				TextureBrush val = new TextureBrush(03M);
				try
				{
					val.TranslateTransform((float)03L.X, (float)03L.Y);
					03K.FillRectangle((Brush)(object)val, 03L);
					return;
				}
				finally
				{
					((IDisposable)val)?.Dispose();
				}
			}
			case U.JO:
				return;
			}
			Rectangle rectangle = 49(03J, 03L, 03M);
			if (rectangle.Width > 0 && rectangle.Height > 0)
			{
				if (u == U.JL)
				{
					03K.DrawImage(03M, rectangle);
					return;
				}
				if (03M is Metafile && (03M.Width > rectangle.Width || 03M.Height > rectangle.Height))
				{
					03M = (Image)new Bitmap(03M);
				}
				Rectangle rectangle2 = new Rectangle(0, 0, rectangle.Width, rectangle.Height);
				03K.DrawImage(03M, rectangle, rectangle2, (GraphicsUnit)2);
			}
		}

		internal void 48(Style 03N, Graphics 03O, Rectangle 03P, string 03Q)
		{
			//IL_0029: Unknown result type (might be due to invalid IL or missing references)
			//IL_002f: Expected O, but got Unknown
			//IL_003a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0040: Expected O, but got Unknown
			//IL_00b3: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ba: Expected O, but got Unknown
			//IL_0188: Unknown result type (might be due to invalid IL or missing references)
			//IL_018e: Invalid comparison between Unknown and I4
			if (03Q.Length != 0 && 03P.Width > 0 && 03P.Height > 0)
			{
				Font val = (Font)03N.4V("Font");
				Brush val2 = (Brush)03N.4V("ForeColor");
				bool 6 = (float)03P.Height <= 03O.MeasureString("A", val).Height;
				4H(03N, 03Q, 6);
				01 7 = (01)03N.4V("Direction");
				Matrix val3 = null;
				GraphicsState val4 = null;
				switch (7)
				{
				case 01.K6:
					4I((StringFormatFlags)2, 046: true);
					4I((StringFormatFlags)1, 046: true);
					val4 = 03O.Save();
					val3 = new Matrix();
					val3.RotateAt(180f, (PointF)new Point(03P.X + 03P.Width / 2, 03P.Y + 03P.Height / 2));
					03O.Transform = val3;
					break;
				case 01.K7:
					4I((StringFormatFlags)2, 046: true);
					4I((StringFormatFlags)1, 046: true);
					break;
				default:
					4I((StringFormatFlags)2, 046: false);
					4I((StringFormatFlags)1, 046: false);
					break;
				}
				Z z = (Z)03N.4V("TextEffect");
				if (z != Z.JX)
				{
					int num = ((z == Z.JY) ? 1 : (-1));
					Brush val5 = ((z == Z.JY) ? KH : KI);
					03P.Offset(num, num);
					03O.DrawString(03Q, val, val5, (RectangleF)03P, KG);
					03P.Offset(-num, -num);
				}
				if ((int)KG.Alignment == 2)
				{
					03Q += "\n";
				}
				03O.DrawString(03Q, val, val2, (RectangleF)03P, KG);
				if (val4 != null)
				{
					03O.Restore(val4);
					val3.Dispose();
				}
			}
		}

		internal Rectangle 49(Style 03R, Rectangle 03S, Image 03T)
		{
			U u = (U)03R.4V("AlignImage");
			if (u == U.JO || u == U.JM || u == U.JN)
			{
				return 03S;
			}
			Rectangle result = 03S;
			Size size = 03T.Size;
			if (size.Width < result.Width)
			{
				result.Width = size.Width;
			}
			if (size.Height < result.Height)
			{
				result.Height = size.Height;
			}
			int num = 03S.Height - result.Height;
			int num2 = 03S.Width - result.Width;
			switch (u)
			{
			case U.JD:
				result.Offset(0, num / 2);
				break;
			case U.JE:
				result.Offset(0, num);
				break;
			case U.JI:
				result.Offset(num2, 0);
				break;
			case U.JJ:
				result.Offset(num2, num / 2);
				break;
			case U.JK:
				result.Offset(num2, num);
				break;
			case U.JF:
				result.Offset(num2 / 2, 0);
				break;
			case U.JG:
				result.Offset(num2 / 2, num / 2);
				break;
			case U.JH:
				result.Offset(num2 / 2, num);
				break;
			case U.JL:
				result = 03S;
				if (result.Width * size.Height > result.Height * size.Width)
				{
					result.Width = result.Height * size.Width / size.Height;
				}
				else
				{
					result.Height = result.Width * size.Height / size.Width;
				}
				num = 03S.Height - result.Height;
				num2 = 03S.Width - result.Width;
				result.Offset(num2 / 2, num / 2);
				break;
			}
			return result;
		}

		internal Rectangle 4A(Style 03U, Rectangle 03V, Image 03W)
		{
			00 6 = (00)03U.4V("Display");
			if (6 == 00.K2)
			{
				return 03V;
			}
			U u = (U)03U.4V("AlignImage");
			if (u == U.JM || u == U.JN || 03W == null)
			{
				return 03V;
			}
			int num = (int)03U.4V("Spacing");
			int num2 = 03W.Width + num;
			int num3 = 03W.Height + num;
			if (4C(u))
			{
				03V.X += num2;
				03V.Width -= num2;
			}
			else if (4D(u))
			{
				03V.Width -= num2;
			}
			else if (4E(u))
			{
				03V.Y += num3;
				03V.Height -= num3;
			}
			else if (4F(u))
			{
				03V.Height -= num3;
			}
			return 03V;
		}

		internal static Color 4B(Color 03X)
		{
			if (03X.ToArgb() != 0)
			{
				return 03X;
			}
			return Color.Black;
		}

		private bool 4C(U 03Y)
		{
			return 03Y switch
			{
				U.JC => true, 
				U.JD => true, 
				U.JE => true, 
				_ => false, 
			};
		}

		private bool 4D(U 03Z)
		{
			return 03Z switch
			{
				U.JI => true, 
				U.JJ => true, 
				U.JK => true, 
				_ => false, 
			};
		}

		private bool 4E(U 040)
		{
			return 040 == U.JF;
		}

		private bool 4F(U 041)
		{
			return 041 == U.JH;
		}

		private string 4G()
		{
			int num = KF.Count;
			string text;
			while (true)
			{
				text = '{' + num.ToString(CultureInfo.InvariantCulture) + '}';
				if (!3X(text))
				{
					break;
				}
				num++;
			}
			return text;
		}

		private void 4H(Style 042, string 043, bool 044)
		{
			//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f5: Unknown result type (might be due to invalid IL or missing references)
			//IL_00fb: Invalid comparison between Unknown and I4
			KG.Trimming = (StringTrimming)042.4V("Trimming");
			4I((StringFormatFlags)4096, !(bool)042.4V("Wrap"));
			switch ((V)042.4V("AlignHorz"))
			{
			case V.JQ:
				KG.Alignment = (StringAlignment)0;
				break;
			case V.JS:
				KG.Alignment = (StringAlignment)2;
				break;
			case V.JR:
				KG.Alignment = (StringAlignment)1;
				break;
			case V.JT:
				KG.Alignment = (StringAlignment)0;
				break;
			case V.JP:
				KG.Alignment = 4J(043);
				break;
			}
			if (044)
			{
				4I((StringFormatFlags)8192, 046: false);
				4I((StringFormatFlags)16384, 046: false);
				KG.LineAlignment = (StringAlignment)0;
				return;
			}
			4I((StringFormatFlags)8192, 046: true);
			4I((StringFormatFlags)16384, (int)KG.Trimming != 0);
			switch ((W)042.4V("AlignVert"))
			{
			case W.JU:
				KG.LineAlignment = (StringAlignment)0;
				break;
			case W.JV:
				KG.LineAlignment = (StringAlignment)1;
				break;
			case W.JW:
				KG.LineAlignment = (StringAlignment)2;
				break;
			}
		}

		private void 4I(StringFormatFlags 045, bool 046)
		{
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0023: Unknown result type (might be due to invalid IL or missing references)
			//IL_0024: Unknown result type (might be due to invalid IL or missing references)
			//IL_0025: Unknown result type (might be due to invalid IL or missing references)
			//IL_000a: Unknown result type (might be due to invalid IL or missing references)
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0010: Unknown result type (might be due to invalid IL or missing references)
			if (046)
			{
				StringFormat kG = KG;
				kG.FormatFlags |= 045;
			}
			else
			{
				StringFormat kG2 = KG;
				kG2.FormatFlags &= ~045;
			}
		}

		private StringAlignment 4J(string 047)
		{
			if (06.5G(047))
			{
				return (StringAlignment)2;
			}
			return (StringAlignment)0;
		}

		public static Rectangle 4K(Rectangle 048, Margins 049)
		{
			048.X += 049.Left;
			048.Y += 049.Top;
			048.Width -= 049.Left + 049.Right;
			048.Height -= 049.Top + 049.Bottom;
			return 048;
		}
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	public class Style
	{
		internal 05 KL;

		internal string KM;

		internal Style KN;

		internal Hashtable KO;

		private Style(05 context, Style parent)
		{
			KL = context;
			KN = parent;
			KO = new Hashtable();
		}

		internal Style(05 context, string name, Style parent)
		{
			if (context == null)
			{
				throw new ArgumentException("Invalid context");
			}
			if (name == null || name.Length == 0 || context.3X(name))
			{
				throw new ArgumentException("Invalid name");
			}
			if (parent != null && parent.4Q() != context)
			{
				throw new ArgumentException("Invalid parent style");
			}
			KL = context;
			KN = parent;
			KO = new Hashtable();
			KM = name;
		}

		internal string 4L()
		{
			return KM;
		}

		internal bool 4M(string 04A)
		{
			return KL.3S(this, 04A);
		}

		internal Style 4N()
		{
			return KN;
		}

		internal Style 4O(Style 04B, bool 04C)
		{
			if (4S(04B))
			{
				KN = 04B;
			}
			if (04C)
			{
				KL.3L(this);
			}
			return this;
		}

		internal Style 4P(Style 04D)
		{
			return 4O(04D, 04C: true);
		}

		internal 05 4Q()
		{
			return KL;
		}

		internal Style 4R()
		{
			return new Style(KL, this);
		}

		internal bool 4S(Style 04E)
		{
			if (04E == null)
			{
				return true;
			}
			for (Style style = 04E; style != null; style = style.4N())
			{
				if (style == this)
				{
					return false;
				}
			}
			return true;
		}

		internal void 4T(string 04F, object 04G)
		{
			if (KL.3V() == this && !KO.Contains(04F))
			{
				KO.Add(04F, 04G);
				KL.3L(this);
			}
			else if (!KO.Contains(04F) || 04G == null || !04G.Equals(KO[04F]))
			{
				KO[04F] = 04G;
				KL.3L(this);
			}
		}

		internal void 4U(string 04H, object 04I)
		{
			object obj = 4V(04H);
			if (obj != null && obj.Equals(04I))
			{
				return;
			}
			if (KL.3V() == this)
			{
				4T(04H, 04I);
				return;
			}
			if (4W(04H))
			{
				4X(04H);
			}
			obj = 4V(04H);
			if (obj == null || !obj.Equals(04I))
			{
				4T(04H, 04I);
			}
		}

		internal object 4V(string 04J)
		{
			object obj = KO[04J];
			if (obj != null)
			{
				return obj;
			}
			if (KN != null)
			{
				return KN.4V(04J);
			}
			return KL.KE.KO[04J];
		}

		internal bool 4W(string 04K)
		{
			return KO.Contains(04K);
		}

		internal void 4X(string 04L)
		{
			KO.Remove(04L);
			KL.3L(this);
		}

		internal void 4Y()
		{
			KO.Clear();
			KL.3L(this);
		}

		internal bool 4Z()
		{
			return KO.Count == 0;
		}

		internal ICollection 50()
		{
			return KO.Keys;
		}

		internal void 51(Style 04M)
		{
			foreach (object key in 04M.KO.Keys)
			{
				KO[key] = 04M.KO[key];
			}
			KL.3L(this);
		}

		internal void 52(Graphics 04N, Rectangle 04O, string 04P, Image 04Q, 02 04R)
		{
			KL.3Z(this, 04N, 04O, 04P, 04Q, 04R);
		}

		internal void 53(Graphics 04S, Rectangle 04T, string 04U, Image 04V)
		{
			52(04S, 04T, 04U, 04V, 02.KC);
		}

		internal void 54(Graphics 04W, Rectangle 04X, string 04Y)
		{
			52(04W, 04X, 04Y, null, 02.KC);
		}

		internal void 55(Graphics 04Z, Rectangle 050, Image 051)
		{
			52(04Z, 050, null, 051, 02.KC);
		}

		internal void 56(Graphics 052, Rectangle 053, string 054, Image 055)
		{
			KL.46(this, 052, 053, 054, 055);
		}

		internal int 57(Graphics 056, string 057, Image 058)
		{
			return KL.40(this, 056, 057, 058);
		}

		internal int 58(Graphics 059, string 05A)
		{
			return KL.40(this, 059, 05A, null);
		}

		internal int 59(Graphics 05B, Image 05C)
		{
			return KL.40(this, 05B, null, 05C);
		}

		internal int 5A(Graphics 05D, int 05E, string 05F, Image 05G)
		{
			return KL.41(this, 05D, 05E, 05F, 05G);
		}

		internal int 5B(Graphics 05H, int 05I, string 05J)
		{
			return KL.41(this, 05H, 05I, 05J, null);
		}

		internal int 5C(Graphics 05K, int 05L, Image 05M)
		{
			return KL.41(this, 05K, 05L, null, 05M);
		}

		internal Rectangle 5D(Rectangle 05N)
		{
			return KL.42(this, 05N);
		}

		internal Rectangle 5E(Rectangle 05O, Image 05P)
		{
			return KL.49(this, 05O, 05P);
		}

		internal Rectangle 5F(Rectangle 05Q, Image 05R)
		{
			return KL.4A(this, 05Q, 05R);
		}

		public override string ToString()
		{
			return "{Style: " + 4L() + "}";
		}
	}
}
namespace C1.Win.C1FlexGrid.Util
{
	internal class 06
	{
		internal const string KP = "\"";

		internal const string KQ = "\"\"";

		internal static bool 5G(string 05S)
		{
			if (05S == null || 05S.Length == 0)
			{
				return false;
			}
			if (05S.EndsWith("%"))
			{
				05S = 05S.Substring(0, 05S.Length - 1);
			}
			double result;
			return double.TryParse(05S, NumberStyles.Any, null, out result);
		}

		internal static double 5H(string 05T)
		{
			bool flag = 05T.EndsWith("%");
			if (flag)
			{
				05T = 05T.Substring(0, 05T.Length - 1);
			}
			if (!double.TryParse(05T, NumberStyles.Any, null, out var result))
			{
				throw new InvalidCastException("Not a number");
			}
			if (flag)
			{
				return result / 100.0;
			}
			return result;
		}

		internal static int 5I(object 05U, object 05V)
		{
			if (05U == DBNull.Value)
			{
				05U = null;
			}
			if (05V == DBNull.Value)
			{
				05V = null;
			}
			if (05U == null && 05V != null)
			{
				return -1;
			}
			if (05U != null && 05V == null)
			{
				return 1;
			}
			if (05U == null && 05V == null)
			{
				return 0;
			}
			if (05U.Equals(05V))
			{
				return 0;
			}
			if (05U == null)
			{
				05U = "";
			}
			if (05V == null)
			{
				05V = "";
			}
			try
			{
				if (05U is IComparable)
				{
					int num = ((IComparable)05U).CompareTo(05V);
					return (num < 0) ? (-1) : ((num > 0) ? 1 : 0);
				}
			}
			catch
			{
			}
			return -2;
		}

		internal static object 5J(object 05W, Type 05X)
		{
			if (05W == null || (object)05X == null || (object)05X == typeof(object) || (object)05W.GetType() == 05X)
			{
				return 05W;
			}
			TypeConverter converter = TypeDescriptor.GetConverter(05W.GetType());
			if (converter.CanConvertTo(05X))
			{
				try
				{
					return converter.ConvertTo(05W, 05X);
				}
				catch
				{
				}
			}
			converter = TypeDescriptor.GetConverter(05X);
			if (converter.CanConvertFrom(05W.GetType()))
			{
				try
				{
					return converter.ConvertFrom(05W);
				}
				catch
				{
				}
			}
			string text = 05W.ToString();
			if (!5G(text))
			{
				return null;
			}
			double num = 5H(text);
			try
			{
				switch (Type.GetTypeCode(05X))
				{
				case TypeCode.Boolean:
					return num != 0.0;
				case TypeCode.Byte:
					return (byte)num;
				case TypeCode.Decimal:
					return (decimal)num;
				case TypeCode.Double:
					return num;
				case TypeCode.Int16:
					return (short)num;
				case TypeCode.Int32:
					return (int)num;
				case TypeCode.Int64:
					return (long)num;
				case TypeCode.SByte:
					return (sbyte)num;
				case TypeCode.Single:
					return (float)num;
				case TypeCode.UInt16:
					return (ushort)num;
				case TypeCode.UInt32:
					return (uint)num;
				case TypeCode.UInt64:
					return (ulong)num;
				case TypeCode.Char:
					break;
				}
			}
			catch
			{
			}
			return null;
		}

		internal static double 5K(object 05Y)
		{
			if (05Y is string)
			{
				string text = 05Y.ToString();
				if (!5G(text))
				{
					return double.NaN;
				}
				return 5H(text);
			}
			try
			{
				switch (Type.GetTypeCode(05Y.GetType()))
				{
				case TypeCode.Byte:
					return (int)(byte)05Y;
				case TypeCode.Decimal:
					return (double)(decimal)05Y;
				case TypeCode.Double:
					return (double)05Y;
				case TypeCode.Int16:
					return (short)05Y;
				case TypeCode.Int32:
					return (int)05Y;
				case TypeCode.Int64:
					return (long)05Y;
				case TypeCode.SByte:
					return (sbyte)05Y;
				case TypeCode.Single:
					return (float)05Y;
				case TypeCode.UInt16:
					return (int)(ushort)05Y;
				case TypeCode.UInt32:
					return (uint)05Y;
				case TypeCode.UInt64:
					return (ulong)05Y;
				}
			}
			catch
			{
			}
			return double.NaN;
		}

		internal static object 5L(string 05Z, Type 060)
		{
			try
			{
				if ((object)060 == typeof(Type))
				{
					return Type.GetType(05Z);
				}
				TypeConverter converter = TypeDescriptor.GetConverter(060);
				return converter.ConvertFromInvariantString(05Z);
			}
			catch
			{
			}
			return null;
		}

		internal static string 5M(object 061)
		{
			TypeConverter converter = TypeDescriptor.GetConverter(061.GetType());
			try
			{
				return converter.ConvertToInvariantString(061);
			}
			catch
			{
			}
			return null;
		}

		internal static string 5N(string 062)
		{
			062 = 062.Replace('\t', ' ');
			if (062.Length > 1 && 062.StartsWith("\"") && 062.EndsWith("\""))
			{
				062 = 062.Substring(1, 062.Length - 2);
			}
			return "\"" + 062.Replace("\"", "\"\"") + "\"";
		}

		internal static string 5O(string 063, string 064)
		{
			int num = 5P(063, 064 + ":");
			if (num < 0)
			{
				return null;
			}
			num += 064.Length;
			int num2 = 5Q(063, ";", num);
			if (num2 < 0)
			{
				return null;
			}
			063 = 063.Substring(num + 1, num2 - num - 1);
			if (063.Length > 1 && 063.StartsWith("\"") && 063.EndsWith("\""))
			{
				063 = 063.Substring(1, 063.Length - 2);
				063 = 063.Replace("\"\"", "\"");
			}
			return 063;
		}

		private static int 5P(string 065, string 066)
		{
			return 5Q(065, 066, 0);
		}

		private static int 5Q(string 067, string 068, int 069)
		{
			int num;
			for (num = 067.IndexOf(068, 069); num > -1; num = 067.IndexOf(068, num + 1))
			{
				bool flag = false;
				for (int i = 0; i < num; i++)
				{
					if (067[i] == "\""[0])
					{
						flag = !flag;
					}
				}
				if (!flag)
				{
					break;
				}
			}
			return num;
		}
	}
	internal class 07
	{
		internal struct 08
		{
			internal uint M6;

			internal uint M7;

			internal int M8;

			internal int M9;

			internal uint MA;

			internal int MB;

			internal int MC;

			internal 08(uint mask)
			{
				M7 = mask;
				M6 = 28u;
				M8 = (M9 = (MB = (MC = 0)));
				MA = 0u;
			}
		}

		internal struct 09
		{
			internal int MD;

			internal int ME;

			internal int MF;

			internal int MG;

			internal int WX => MG - ME;

			internal int WY => MF - MD;

			internal 09(Rectangle rc)
			{
				MD = rc.X;
				ME = rc.Y;
				MF = rc.Right;
				MG = rc.Bottom;
			}

			internal void 64(int 07G, int 07H)
			{
				MD += 07G;
				MF += 07G;
				ME += 07H;
				MG += 07H;
			}

			public static implicit operator Rectangle(09 rc)
			{
				return new Rectangle(rc.MD, rc.ME, rc.WY, rc.WX);
			}

			public static implicit operator 09(Rectangle rc)
			{
				return new 09(rc);
			}
		}

		internal const int KR = 8388608;

		internal const int KS = 2097152;

		internal const int KT = 1048576;

		internal const int KU = 67108864;

		internal const int KV = 33554432;

		internal const int KW = 131072;

		internal const int KX = 512;

		internal const int KY = 4194304;

		internal const int KZ = 16384;

		internal const int L0 = 1048576;

		internal const int L1 = 20;

		internal const int L2 = 256;

		internal const int L3 = 257;

		internal const int L4 = 258;

		internal const int L5 = 513;

		internal const int L6 = 514;

		internal const int L7 = 515;

		internal const int L8 = 276;

		internal const int L9 = 277;

		internal const int LA = 522;

		internal const int LB = 794;

		internal const int LC = 269;

		internal const int LD = 215;

		internal const int LE = 201;

		internal const int LF = 186;

		internal const int LG = 178;

		internal const int LH = 179;

		internal const int LI = 120;

		internal const int LJ = 0;

		internal const int LK = 1;

		internal const int LL = 2;

		internal const int LM = 3;

		internal const int LN = 0;

		internal const int LO = 1;

		internal const int LP = 2;

		internal const int LQ = 3;

		internal const int LR = 4;

		internal const int LS = 5;

		internal const int LT = 6;

		internal const int LU = 7;

		internal const int LV = 8;

		internal const int LW = 1;

		internal const int LX = 2;

		internal const int LY = 4;

		internal const int LZ = 8;

		internal const int M0 = 16;

		internal const int M1 = 23;

		internal const int M2 = 1;

		internal const int M3 = 2;

		internal const int M4 = 4;

		internal const int M5 = 16;

		[DllImport("USER32.DLL", EntryPoint = "ScrollWindowEx")]
		private static extern int 5R(IntPtr 06A, int 06B, int 06C, ref 09 06D, ref 09 06E, IntPtr 06F, IntPtr 06G, uint 06H);

		[DllImport("USER32.DLL", EntryPoint = "GetScrollInfo")]
		private static extern bool 5S(IntPtr 06I, int 06J, ref 08 06K);

		[DllImport("USER32.DLL", EntryPoint = "SetScrollInfo")]
		private static extern int 5T(IntPtr 06L, int 06M, ref 08 06N, int 06O);

		internal static int 5U(IntPtr 06P, int 06Q)
		{
			08 06K = new 08(20u);
			5S(06P, 06Q, ref 06K);
			return 06K.MC;
		}

		internal static int 5V(IntPtr 06R, int 06S)
		{
			08 06K = new 08(20u);
			5S(06R, 06S, ref 06K);
			return 06K.MB;
		}

		internal static int 5W(IntPtr 06T, int 06U)
		{
			08 06K = new 08(1u);
			5S(06T, 06U, ref 06K);
			return 06K.M9 - 06K.M8;
		}

		internal static int 5X(IntPtr 06V, int 06W, int 06X)
		{
			08 06N = new 08(4u);
			06N.MB = 06X;
			return 5T(06V, 06W, ref 06N, 1);
		}

		internal static int 5Y(IntPtr 06Y, int 06Z, int 070, int 071)
		{
			08 06N = new 08(3u);
			06N.M9 = 070;
			06N.MA = (uint)071;
			return 5T(06Y, 06Z, ref 06N, 1);
		}

		internal static int 5Z(IntPtr 072, ref 09 073, int 074, int 075)
		{
			return 5R(072, 074, 075, ref 073, ref 073, IntPtr.Zero, IntPtr.Zero, 2u);
		}

		internal static IntPtr 60(Point 076)
		{
			return (IntPtr)(076.X | (076.Y << 16));
		}

		internal static void 61(Graphics 077, Rectangle 078, Border3DStyle 079)
		{
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_0037: Unknown result type (might be due to invalid IL or missing references)
			//IL_0039: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Unknown result type (might be due to invalid IL or missing references)
			//IL_006a: Expected I4, but got Unknown
			//IL_006a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0071: Invalid comparison between Unknown and I4
			Pen control = SystemPens.Control;
			Pen controlLightLight = SystemPens.ControlLightLight;
			Pen controlDark = SystemPens.ControlDark;
			Pen controlDarkDark = SystemPens.ControlDarkDark;
			078.Width--;
			078.Height--;
			switch (079 - 1)
			{
			default:
				if ((int)079 != 16394)
				{
					break;
				}
				077.DrawRectangle(controlDark, 078);
				078.Inflate(-1, -1);
				077.DrawRectangle(control, 078);
				return;
			case 8:
				62(077, 078, control);
				63(077, 078, controlDarkDark);
				078.Inflate(-1, -1);
				62(077, 078, controlDarkDark);
				63(077, 078, control);
				return;
			case 5:
				62(077, 078, controlDark);
				63(077, 078, controlLightLight);
				078.Inflate(-1, -1);
				62(077, 078, controlLightLight);
				63(077, 078, controlDark);
				return;
			case 4:
				62(077, 078, control);
				63(077, 078, controlDarkDark);
				078.Inflate(-1, -1);
				62(077, 078, controlLightLight);
				63(077, 078, controlDark);
				return;
			case 3:
				62(077, 078, controlLightLight);
				63(077, 078, controlDark);
				return;
			case 0:
				62(077, 078, control);
				63(077, 078, controlDarkDark);
				return;
			case 9:
				62(077, 078, controlDark);
				63(077, 078, controlLightLight);
				078.Inflate(-1, -1);
				62(077, 078, controlDarkDark);
				63(077, 078, control);
				return;
			case 7:
				62(077, 078, controlDarkDark);
				63(077, 078, control);
				return;
			case 1:
				62(077, 078, controlDark);
				63(077, 078, controlLightLight);
				return;
			case 2:
			case 6:
				break;
			}
			throw new Exception("Unsupported BorderStyle.");
		}

		private static void 62(Graphics 07A, Rectangle 07B, Pen 07C)
		{
			07A.DrawLine(07C, 07B.Left, 07B.Bottom, 07B.Left, 07B.Top);
			07A.DrawLine(07C, 07B.Left, 07B.Top, 07B.Right, 07B.Top);
		}

		private static void 63(Graphics 07D, Rectangle 07E, Pen 07F)
		{
			07D.DrawLine(07F, 07E.Left, 07E.Bottom, 07E.Right, 07E.Bottom);
			07D.DrawLine(07F, 07E.Right, 07E.Bottom, 07E.Right, 07E.Top);
		}
	}
	internal class 0A : IDisposable
	{
		private enum 0B
		{
			MN,
			MO,
			MP
		}

		private Control MH;

		private IntPtr MI;

		private IntPtr MJ;

		private IntPtr MK;

		private bool ML;

		private static 0B MM = 0B.MN;

		internal 0A(Control control)
		{
			//IL_005b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0061: Expected O, but got Unknown
			MH = control;
			ML = false;
			switch (MM)
			{
			case 0B.MP:
				return;
			case 0B.MN:
			{
				MM = 0B.MP;
				IntPtr intPtr = 6C("UxTheme.dll");
				if (intPtr == IntPtr.Zero)
				{
					return;
				}
				MM = 0B.MO;
				6D(intPtr);
				break;
			}
			}
			try
			{
				ComboBox val = new ComboBox();
				try
				{
					IntPtr intPtr2 = 6K(((Control)val).Handle);
					ML = intPtr2 != IntPtr.Zero;
				}
				finally
				{
					((IDisposable)val)?.Dispose();
				}
			}
			catch
			{
			}
		}

		private void 65()
		{
			66();
		}

		void IDisposable.Dispose()
		{
			//ILSpy generated this explicit interface implementation from .override directive in 65
			this.65();
		}

		internal void 66()
		{
			if (MI != IntPtr.Zero)
			{
				6G(MI);
				MI = IntPtr.Zero;
			}
			if (MJ != IntPtr.Zero)
			{
				6G(MJ);
				MJ = IntPtr.Zero;
			}
			if (MK != IntPtr.Zero)
			{
				6G(MK);
				MK = IntPtr.Zero;
			}
		}

		internal void 67(Graphics 07I, Rectangle 07J, ButtonState 07K)
		{
			//IL_005a: Unknown result type (might be due to invalid IL or missing references)
			if (ML)
			{
				if (MJ == IntPtr.Zero)
				{
					MJ = 6F(MH.Handle, "COMBOBOX");
				}
				if (MJ != IntPtr.Zero)
				{
					6A(07I, MJ, 1, 1, 07J);
					return;
				}
			}
			ControlPaint.DrawComboButton(07I, 07J, 07K);
		}

		internal void 68(Graphics 07L, Rectangle 07M, ButtonState 07N)
		{
			//IL_005a: Unknown result type (might be due to invalid IL or missing references)
			if (ML)
			{
				if (MI == IntPtr.Zero)
				{
					MI = 6F(MH.Handle, "BUTTON");
				}
				if (MI != IntPtr.Zero)
				{
					6A(07L, MI, 1, 1, 07M);
					return;
				}
			}
			ControlPaint.DrawButton(07L, 07M, 07N);
		}

		internal void 69(Graphics 07O, Rectangle 07P, Brush 07Q, Border3DStyle 07R, bool 07S)
		{
			//IL_0091: Unknown result type (might be due to invalid IL or missing references)
			//IL_0098: Invalid comparison between Unknown and I4
			//IL_009c: Unknown result type (might be due to invalid IL or missing references)
			if (ML)
			{
				if (MK == IntPtr.Zero)
				{
					MK = 6F(MH.Handle, "HEADER");
				}
				if (MK != IntPtr.Zero)
				{
					6A(07O, MK, 1, (!07S) ? 1 : 2, 07P);
					07O.DrawLine(SystemPens.ControlDark, 07P.X, 07P.Y, 07P.Right, 07P.Y);
					return;
				}
			}
			if (07Q != null)
			{
				07O.FillRectangle(07Q, 07P);
			}
			if ((int)07R != 8192)
			{
				07.61(07O, 07P, 07R);
			}
		}

		private void 6A(Graphics 07T, IntPtr 07U, int 07V, int 07W, Rectangle 07X)
		{
			6B(07T, 07U, 07V, 07W, 07X, MH.ClientRectangle);
		}

		private void 6B(Graphics 07Y, IntPtr 07Z, int 080, int 081, Rectangle 082, Rectangle 083)
		{
			07.09 08H = new 07.09(082);
			07.09 08E = new 07.09(083);
			IntPtr hdc = 07Y.GetHdc();
			if (6J(07Z, 080, 081))
			{
				6I(MH.Handle, hdc, ref 08H);
			}
			IntPtr intPtr = 6H(07Z, hdc, 080, 081, ref 08H, ref 08E);
			07Y.ReleaseHdc(hdc);
			if (intPtr != IntPtr.Zero)
			{
				66();
			}
		}

		[DllImport("Kernel32.dll", EntryPoint = "LoadLibrary")]
		private static extern IntPtr 6C(string 084);

		[DllImport("Kernel32.dll", EntryPoint = "FreeLibrary")]
		private static extern bool 6D(IntPtr 085);

		[DllImport("UxTheme.dll", CharSet = CharSet.Unicode, EntryPoint = "IsThemeActive")]
		private static extern bool 6E();

		[DllImport("UxTheme.dll", CharSet = CharSet.Unicode, EntryPoint = "OpenThemeData")]
		private static extern IntPtr 6F(IntPtr 086, string 087);

		[DllImport("UxTheme.dll", CharSet = CharSet.Unicode, EntryPoint = "CloseThemeData")]
		private static extern IntPtr 6G(IntPtr 088);

		[DllImport("UxTheme.dll", CharSet = CharSet.Unicode, EntryPoint = "DrawThemeBackground")]
		private static extern IntPtr 6H(IntPtr 089, IntPtr 08A, int 08B, int 08C, ref 07.09 08D, ref 07.09 08E);

		[DllImport("UxTheme.dll", CharSet = CharSet.Unicode, EntryPoint = "DrawThemeParentBackground")]
		private static extern IntPtr 6I(IntPtr 08F, IntPtr 08G, ref 07.09 08H);

		[DllImport("UxTheme.dll", CharSet = CharSet.Unicode, EntryPoint = "IsThemeBackgroundPartiallyTransparent")]
		private static extern bool 6J(IntPtr 08I, int 08J, int 08K);

		[DllImport("UxTheme.dll", CharSet = CharSet.Unicode, EntryPoint = "GetWindowTheme")]
		private static extern IntPtr 6K(IntPtr 08L);
	}
}
namespace C1.Win.C1FlexGrid
{
	internal class 0C : IC1ControlPrinter
	{
		private C1FlexGridBase MQ;

		private bool MR;

		private int MS;

		private int MT;

		private Size MU;

		private Size MV;

		private Size MW;

		private ArrayList MX;

		private ArrayList MY;

		private EventHandler MZ;

		private EventHandler N0;

		public event EventHandler WidthChanged
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				MZ = (EventHandler)Delegate.Combine(MZ, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				MZ = (EventHandler)Delegate.Remove(MZ, value);
			}
		}

		public event EventHandler HeightChanged
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				N0 = (EventHandler)Delegate.Combine(N0, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				N0 = (EventHandler)Delegate.Remove(N0, value);
			}
		}

		internal 0C(C1FlexGridBase view)
		{
			MQ = view;
			MQ.GridChanged += 6N;
			ref Size mV = ref MV;
			mV = new Size(0, 0);
			MS = (MT = 0);
		}

		private void 6L(ControlPrintInfoBase 08M)
		{
			ref Size mV = ref MV;
			mV = new Size(0, 0);
			ref Size mU = ref MU;
			mU = new Size(0, 0);
			MS = (MT = 0);
		}

		void IC1ControlPrinter.Initialize(ControlPrintInfoBase 08M)
		{
			//ILSpy generated this explicit interface implementation from .override directive in 6L
			this.6L(08M);
		}

		private void 6M(bool 08N, double 08O, double 08P, out double 08Q, out double 08R, out IDrawel 08S, out bool 08T)
		{
			MV.Width = (int)Math.Round(LengthUnit.Convert((float)08P, LengthUnit.Units.Mm, LengthUnit.Units.Px));
			MV.Height = (int)Math.Round(LengthUnit.Convert((float)08O, LengthUnit.Units.Mm, LengthUnit.Units.Px));
			if (MS == 0)
			{
				MR = 08N;
				6R();
				6S();
			}
			if (MS > 0)
			{
				6T();
			}
			MW = MV;
			08S = PrintAsmbProxy.NewDrawel(typeof(IDrawelArea)) as IDrawelArea;
			08S.Name = ((Control)MQ).Name + MS.ToString(CultureInfo.CurrentCulture);
			08S.Width = "100%parent";
			Size size = 6U(08S);
			08Q = LengthUnit.Convert(size.Height, LengthUnit.Units.Px, LengthUnit.Units.Mm);
			08R = LengthUnit.Convert(size.Width, LengthUnit.Units.Px, LengthUnit.Units.Mm);
			MS++;
			08T = MS >= MT;
		}

		void IC1ControlPrinter.GeneratePortion(bool 08N, double 08O, double 08P, out double 08Q, out double 08R, out IDrawel 08S, out bool 08T)
		{
			//ILSpy generated this explicit interface implementation from .override directive in 6M
			this.6M(08N, 08O, 08P, out 08Q, out 08R, out 08S, out 08T);
		}

		[SpecialName]
		double IC1ControlPrinter.get_HeightMm()
		{
			return LengthUnit.Convert(6Q().Height, LengthUnit.Units.Px, LengthUnit.Units.Mm);
		}

		[SpecialName]
		double IC1ControlPrinter.get_WidthMm()
		{
			return LengthUnit.Convert(6Q().Width, LengthUnit.Units.Px, LengthUnit.Units.Mm);
		}

		private void 6N(object 08U, GridChangedEventArgs 08V)
		{
			switch (08V.GridChangedType)
			{
			case GridChangedTypeEnum.LayoutChanged:
			case GridChangedTypeEnum.AfterCollapse:
			case GridChangedTypeEnum.RowAdded:
			case GridChangedTypeEnum.RowRemoved:
			case GridChangedTypeEnum.ColAdded:
			case GridChangedTypeEnum.ColRemoved:
				6O();
				6P();
				break;
			}
		}

		protected virtual void 6O()
		{
			if (MZ != null)
			{
				MZ(this, EventArgs.Empty);
			}
		}

		protected virtual void 6P()
		{
			if (N0 != null)
			{
				N0(this, EventArgs.Empty);
			}
		}

		private Size 6Q()
		{
			Size result = new Size(0, 0);
			if (MQ.Rows.Count > 0 && MQ.Cols.Count > 0)
			{
				result.Width = MQ.Cols[MQ.Cols.Count - 1].Right;
				result.Height = MQ.Rows[MQ.Rows.Count - 1].Bottom;
			}
			return result;
		}

		private void 6R()
		{
			MU = MV;
			int count = MQ.Rows.Count;
			int count2 = MQ.Cols.Count;
			if (MR && count2 > 0 && count > 0)
			{
				double num = MQ.Cols[count2 - 1].Right;
				double num2 = MQ.Rows[count - 1].Bottom;
				double num3 = Math.Max(num / (double)MV.Width, num2 / (double)MV.Height);
				if (num3 > 1.0)
				{
					MU.Width = (int)((double)MV.Width * num3);
					MU.Height = (int)((double)MV.Height * num3);
				}
			}
		}

		private void 6S()
		{
			MT = 0;
			MX = new ArrayList();
			MY = new ArrayList();
			RowCollection rows = MQ.Rows;
			ColumnCollection cols = MQ.Cols;
			if (rows.Count == 0 || cols.Count == 0)
			{
				return;
			}
			int num = rows.Fixed + rows.Frozen;
			int num2 = cols.Fixed + cols.Frozen;
			int top = rows[num].Top;
			int left = cols[num2].Left;
			int num3 = top;
			int num4 = num;
			for (int i = num; i < rows.Count; i++)
			{
				if (MR)
				{
					break;
				}
				if (i - 1 > num4 && num3 + rows[i].HeightDisplay > MU.Height)
				{
					MX.Add(i - 1);
					num4 = i;
					num3 = top;
				}
				num3 += rows[i].HeightDisplay;
			}
			MX.Add(rows.Count - 1);
			int num5 = left;
			num4 = num2;
			for (int j = num2; j < cols.Count; j++)
			{
				if (MR)
				{
					break;
				}
				if (j - 1 > num4 && num5 + cols[j].WidthDisplay > MU.Width)
				{
					MY.Add(j - 1);
					num4 = j;
					num5 = left;
				}
				num5 += cols[j].WidthDisplay;
			}
			MY.Add(cols.Count - 1);
			MT = MX.Count * MY.Count;
		}

		private void 6T()
		{
			if (MS == 0 || MS >= MX.Count || MR || MW == MV)
			{
				return;
			}
			MU = MV;
			RowCollection rows = MQ.Rows;
			if (rows.Count == 0)
			{
				return;
			}
			int index = rows.Fixed + rows.Frozen;
			int top = rows[index].Top;
			while (MX.Count > MS)
			{
				MX.RemoveAt(MX.Count - 1);
			}
			int num = top;
			int num2 = (int)MX[MS - 1];
			for (int i = num2 + 1; i < rows.Count; i++)
			{
				if (i - 1 > num2 && num + rows[i].HeightDisplay > MU.Height)
				{
					MX.Add(i - 1);
					num2 = i;
					num = top;
				}
				num += rows[i].HeightDisplay;
			}
			MX.Add(rows.Count - 1);
			MT = MX.Count * MY.Count;
		}

		private Size 6U(IDrawel 08W)
		{
			Size result = new Size(0, 0);
			Image val = 6V(MS);
			if (val != null)
			{
				result = val.Size;
				IDrawelImage drawelImage = PrintAsmbProxy.NewDrawel(typeof(IDrawelImage)) as IDrawelImage;
				drawelImage.Image = val;
				drawelImage.Width = result.Width.ToString(CultureInfo.InvariantCulture) + LengthUnit.Units.Px.ToString(CultureInfo.InvariantCulture);
				drawelImage.Height = result.Height.ToString(CultureInfo.InvariantCulture) + LengthUnit.Units.Px.ToString(CultureInfo.InvariantCulture);
				drawelImage.ImageAlign = new C1DImageAlign();
				drawelImage.ImageAlign.Fit = true;
				08W.AppendChild(drawelImage);
			}
			return result;
		}

		private Image 6V(int 08X)
		{
			CellRange cellRange = MQ.GetCellRange(0, 0);
			cellRange.c2 = MQ.Cols.Fixed + MQ.Cols.Frozen - 1;
			for (int i = 0; i < MY.Count; i++)
			{
				cellRange.c1 = cellRange.c2 + 1;
				cellRange.c2 = (int)MY[i];
				cellRange.r2 = MQ.Rows.Fixed + MQ.Rows.Frozen - 1;
				for (int j = 0; j < MX.Count; j++)
				{
					cellRange.r1 = cellRange.r2 + 1;
					cellRange.r2 = (int)MX[j];
					if (08X == 0)
					{
						return MQ.CreateImage(cellRange, (EmfType)3);
					}
					08X--;
				}
			}
			return null;
		}
	}
	public enum AllowMergingEnum
	{
		None,
		Free,
		RestrictRows,
		RestrictCols,
		RestrictAll,
		FixedOnly,
		Spill,
		Nodes
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	[LicenseProvider(typeof(LicenseProvider))]
	public abstract class C1FlexGridBase : ScrollableControl, ISupportInitialize, B, IC1ControlPrintable
	{
		internal 0D N1;

		internal 0N N2;

		internal 0M N3;

		internal 0J N4;

		internal 0G N5;

		internal 0H N6;

		internal GridPrinter N7;

		internal CellRange N8;

		internal HighLightEnum N9;

		internal FocusRectEnum NA;

		internal AllowResizingEnum NB;

		internal AllowFreezingEnum NC;

		internal AllowDraggingEnum ND;

		internal AllowSortingEnum NE;

		internal DrawModeEnum NF;

		internal ShowButtonsEnum NG;

		internal bool NH;

		internal bool NI;

		internal bool NJ;

		internal bool NK;

		internal bool NL;

		internal bool NM;

		internal bool NN;

		internal bool NO;

		internal bool NP;

		private bool NQ = false;

		private GridChangedEventHandler NR;

		private BeforeMouseDownEventHandler NS;

		private DragRowColEventHandler NT;

		private DragRowColEventHandler NU;

		private DragRowColEventHandler NV;

		private DragRowColEventHandler NW;

		private SortColEventHandler NX;

		private SortColEventHandler NY;

		private RowColEventHandler NZ;

		private RowColEventHandler O0;

		private RowColEventHandler O1;

		private RowColEventHandler O2;

		private RowColEventHandler O3;

		private RowColEventHandler O4;

		private RowColEventHandler O5;

		private RowColEventHandler O6;

		private RowColEventHandler O7;

		private RowColEventHandler O8;

		private RangeEventHandler O9;

		private RangeEventHandler OA;

		private RowColEventHandler OB;

		private RangeEventHandler OC;

		private RangeEventHandler OD;

		private RangeEventHandler OE;

		private RangeEventHandler OF;

		private EventHandler OG;

		private EventHandler OH;

		private EventHandler OI;

		private EventHandler OJ;

		private RowColEventHandler OK;

		private RowColEventHandler OL;

		private RowColEventHandler OM;

		private RowColEventHandler ON;

		private RowColEventHandler OO;

		private ValidateEditEventHandler OP;

		private EventHandler OQ;

		private RowColEventHandler OR;

		private RowColEventHandler OS;

		private KeyEditEventHandler OT;

		private KeyEditEventHandler OU;

		private KeyPressEditEventHandler OV;

		private RowColEventHandler OW;

		private ListChangedEventHandler OX;

		private GridErrorEventHandler OY;

		private RowColEventHandler OZ;

		private RowColEventHandler P0;

		private OwnerDrawCellEventHandler P1;

		private RowColEventHandler P2;

		private PrintEventHandler P3;

		private PrintEventHandler P4;

		private PrintPageEventHandler P5;

		private DragEventHandler P6;

		private bool P7 = false;

		private static Point[] P8 = new Point[3];

		private MouseButtons P9 = (MouseButtons)0;

		private bool PA = false;

		public object this[int row, int col]
		{
			get
			{
				return GetData(row, col);
			}
			set
			{
				SetData(row, col, value);
			}
		}

		public object this[int row, string colName]
		{
			get
			{
				return GetData(row, Cols[colName].Index);
			}
			set
			{
				SetData(row, Cols[colName].Index, value);
			}
		}

		[Browsable(false)]
		public override string Text
		{
			get
			{
				return ((Control)this).Text;
			}
			set
			{
				((Control)this).Text = value;
			}
		}

		[Browsable(true)]
		[Category("Behavior")]
		[DefaultValue(AllowResizingEnum.Columns)]
		[D("AllowResizing", "Allow the user to resize rows and/or columns with the mouse.")]
		public AllowResizingEnum AllowResizing
		{
			get
			{
				return NB;
			}
			set
			{
				NB = value;
			}
		}

		[D("AllowFreezing", "Allow the user to freeze rows and/or columns with the mouse.")]
		[Browsable(true)]
		[DefaultValue(AllowFreezingEnum.None)]
		[Category("Behavior")]
		public AllowFreezingEnum AllowFreezing
		{
			get
			{
				return NC;
			}
			set
			{
				NC = value;
			}
		}

		[D("AllowDragging", "Allow the user to drag rows and/or columns.")]
		[Browsable(true)]
		[DefaultValue(AllowDraggingEnum.Columns)]
		[Category("Behavior")]
		public AllowDraggingEnum AllowDragging
		{
			get
			{
				return ND;
			}
			set
			{
				ND = value;
			}
		}

		[Category("Appearance")]
		[DefaultValue(HighLightEnum.Always)]
		[D("HighLight", "Gets or sets when to highlight selected cells.")]
		[Browsable(true)]
		public HighLightEnum HighLight
		{
			get
			{
				return N9;
			}
			set
			{
				if (N9 != value)
				{
					N9 = value;
					((Control)this).Invalidate();
				}
			}
		}

		[DefaultValue(FocusRectEnum.Light)]
		[Browsable(true)]
		[Category("Appearance")]
		[D("FocusRect", "Gets or sets the type of focus rectangle to display.")]
		public FocusRectEnum FocusRect
		{
			get
			{
				return NA;
			}
			set
			{
				if (NA != value)
				{
					NA = value;
					79(WZ.EK());
				}
			}
		}

		[DefaultValue(true)]
		[Category("Behavior")]
		[D("AllowEditing", "Allow the user to edit grid contents.")]
		[Browsable(true)]
		public bool AllowEditing
		{
			get
			{
				return NK;
			}
			set
			{
				NK = value;
			}
		}

		[Category("Appearance")]
		[DefaultValue(ShowButtonsEnum.WithFocus)]
		[D("ShowButtons", "Draw combo buttons on cells without the cursor.")]
		[Browsable(true)]
		public ShowButtonsEnum ShowButtons
		{
			get
			{
				return NG;
			}
			set
			{
				NG = value;
				((Control)this).Invalidate();
			}
		}

		[Browsable(true)]
		[D("ShowCursor", "Show DB-style cursor on fixed column.")]
		[Category("Appearance")]
		[DefaultValue(false)]
		public bool ShowCursor
		{
			get
			{
				return NH;
			}
			set
			{
				NH = value;
				((Control)this).Invalidate();
			}
		}

		[D("ShowSort", "Show sorting glyph (triangle) on the headers of sorted columns.")]
		[Category("Appearance")]
		[Browsable(true)]
		[DefaultValue(true)]
		public bool ShowSort
		{
			get
			{
				return NJ;
			}
			set
			{
				NJ = value;
				((Control)this).Invalidate();
			}
		}

		[D("ShowErrors", "Show ErrorInfo information (error icons in cells and tooltips).")]
		[Browsable(true)]
		[DefaultValue(false)]
		[Category("Data")]
		public bool ShowErrors
		{
			get
			{
				return NI;
			}
			set
			{
				NI = value;
				((Control)this).Invalidate();
			}
		}

		[DefaultValue(AllowSortingEnum.SingleColumn)]
		[Category("Behavior")]
		[Browsable(true)]
		[D("AllowSorting", "Allow the user to sort columns by clicking on the header cell.")]
		public AllowSortingEnum AllowSorting
		{
			get
			{
				return NE;
			}
			set
			{
				NE = value;
				((Control)this).Invalidate();
			}
		}

		[D("ExtendLastCol", "Determines whether the last column should be extended to fill the control.")]
		[Browsable(true)]
		[DefaultValue(false)]
		[E("Layout")]
		public bool ExtendLastCol
		{
			get
			{
				return NL;
			}
			set
			{
				if (NL != value)
				{
					NL = value;
					((Control)this).Invalidate();
				}
			}
		}

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[D("Row", "Gets or sets the row that contains the cursor.")]
		public int Row
		{
			get
			{
				return WZ.UX.r1;
			}
			set
			{
				Select(value, Col);
			}
		}

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[D("Col", "Gets or sets the column that contains the cursor.")]
		public int Col
		{
			get
			{
				return WZ.UX.c1;
			}
			set
			{
				Select(Row, value);
			}
		}

		[Browsable(false)]
		[D("RowSel", "Gets or sets the last row in the current selection.")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public int RowSel
		{
			get
			{
				return WZ.UX.r2;
			}
			set
			{
				75(value, ColSel, 09F: false);
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[Browsable(false)]
		[D("ColSel", "Gets or sets the last column in the current selection.")]
		public int ColSel
		{
			get
			{
				return WZ.UX.c2;
			}
			set
			{
				75(RowSel, value, 09F: false);
			}
		}

		[E("Layout")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[D("Rows", "Row collection.")]
		[Browsable(true)]
		public RowCollection Rows => N1.PJ;

		[E("Layout")]
		[Browsable(true)]
		[D("Cols", "Column collection.")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public ColumnCollection Cols
		{
			get
			{
				return N1.PK;
			}
			set
			{
				if (NP)
				{
					throw new Exception("This property is read-only.");
				}
				N1.PK = value;
				value.UE = N1;
			}
		}

		[Browsable(false)]
		[EditorBrowsable(EditorBrowsableState.Never)]
		[RefreshProperties(RefreshProperties.All)]
		[Localizable(true)]
		[DefaultValue(null)]
		public string ColumnInfo
		{
			get
			{
				return Cols.E6();
			}
			set
			{
				Cols = new ColumnCollection(value);
			}
		}

		[D("LeftCol", "Gets or sets the first visible column in the scrollable area.")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[Browsable(false)]
		public int LeftCol
		{
			get
			{
				return N8.c1;
			}
			set
			{
				bool redraw = Redraw;
				Redraw = true;
				int num = Cols.Fixed + Cols.Frozen;
				if (value < num)
				{
					value = num;
				}
				if (value >= Cols.Count)
				{
					value = Cols.Count - 1;
				}
				if (value >= num)
				{
					int num2 = Cols[value].Left - Cols[num].Left;
					int width = base.WS.Width;
					if (num2 > width)
					{
						num2 = width;
					}
					base.ScrollPosition = new Point(-num2, base.ScrollPosition.Y);
					Redraw = redraw;
				}
			}
		}

		[D("TopRow", "Gets or sets the first visible row in the scrollable area.")]
		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public int TopRow
		{
			get
			{
				return N8.r1;
			}
			set
			{
				bool redraw = Redraw;
				Redraw = true;
				int num = Rows.Fixed + Rows.Frozen;
				if (value < num)
				{
					value = num;
				}
				if (value >= Rows.Count)
				{
					value = Rows.Count - 1;
				}
				if (value >= num)
				{
					int num2 = Rows[value].Top - Rows[num].Top;
					int height = base.WS.Height;
					if (num2 > height)
					{
						num2 = height;
					}
					base.ScrollPosition = new Point(base.ScrollPosition.X, -num2);
					Redraw = redraw;
				}
			}
		}

		[D("RightCol", "Gets the last visible column in the scrollable area.")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[Browsable(false)]
		public int RightCol => N8.c2;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[D("BottomRow", "Gets the last visible row in the scrollable area.")]
		[Browsable(false)]
		public int BottomRow => N8.r2;

		[Browsable(true)]
		[Category("Behavior")]
		[DefaultValue(SelectionModeEnum.Default)]
		[D("SelectionMode", "Gets or sets the grid selection mode.")]
		public SelectionModeEnum SelectionMode
		{
			get
			{
				return WZ.XH;
			}
			set
			{
				WZ.XH = value;
			}
		}

		[D("Selection", "Returns the selected range (Row, Col, RowSel, ColSel) in normalized form.")]
		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public virtual CellRange Selection
		{
			get
			{
				CellRange result = WZ.EJ();
				result.Normalize();
				return result;
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[Browsable(false)]
		[D("CursorCell", "Returns the anchor point of the selected range (Row, Col).")]
		public virtual CellRange CursorCell
		{
			get
			{
				CellRange result = WZ.EJ();
				result.r2 = result.r1;
				result.c2 = result.c1;
				return result;
			}
		}

		[RefreshProperties(RefreshProperties.Repaint)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Visible)]
		[D("Styles", "Style collection.")]
		[Browsable(true)]
		[Category("Appearance")]
		public CellStyleCollection Styles
		{
			get
			{
				return N1.PN;
			}
			set
			{
				if (NP)
				{
					throw new Exception("This property is read-only.");
				}
				N1.PN = value;
				N1.PN.EU(N1);
				((Control)this).BackColor = Styles.Normal.BackColor;
			}
		}

		[Browsable(true)]
		[Category("Behavior")]
		[D("AutoSearch", "Gets or sets whether the grid will automatically search for items as the user types.")]
		[DefaultValue(AutoSearchEnum.None)]
		public AutoSearchEnum AutoSearch
		{
			get
			{
				return N3.X9;
			}
			set
			{
				N3.X9 = value;
			}
		}

		[D("AutoSearchDelay", "Gets or sets the delay (in seconds) before the AutoSearch buffer is cleared.")]
		[DefaultValue(1.0)]
		[Category("Behavior")]
		[Browsable(true)]
		public double AutoSearchDelay
		{
			get
			{
				return N3.XA;
			}
			set
			{
				N3.XA = value;
			}
		}

		[DefaultValue(KeyActionEnum.MoveDown)]
		[Category("Behavior")]
		[D("KeyActionEnter", "Gets or sets the action to be performed when the Enter key is pressed.")]
		[Browsable(true)]
		public KeyActionEnum KeyActionEnter
		{
			get
			{
				return N3.RY;
			}
			set
			{
				N3.RY = value;
			}
		}

		[DefaultValue(KeyActionEnum.None)]
		[Browsable(true)]
		[D("KeyActionTab", "Gets or sets the action to be performed when the Tab key is pressed.")]
		[Category("Behavior")]
		public KeyActionEnum KeyActionTab
		{
			get
			{
				return N3.RZ;
			}
			set
			{
				N3.RZ = value;
			}
		}

		[D("CellButtonImage", "Gets or sets the image to be used in cell buttons.")]
		[Browsable(true)]
		[DefaultValue(null)]
		[Category("Appearance")]
		public virtual Image CellButtonImage
		{
			get
			{
				return N1.X3;
			}
			set
			{
				N1.X3 = value;
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[Browsable(false)]
		[D("MouseRow", "Gets the row under the cursor.")]
		public virtual int MouseRow
		{
			get
			{
				Point point = ((Control)this).PointToClient(Cursor.Position);
				point = GetCellAt(point.X, point.Y, fixedOK: true);
				if (point.Y >= 0)
				{
					return point.Y;
				}
				return -1;
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[Browsable(false)]
		[D("MouseCol", "Gets the column under the cursor.")]
		public virtual int MouseCol
		{
			get
			{
				Point point = ((Control)this).PointToClient(Cursor.Position);
				point = GetCellAt(point.X, point.Y, fixedOK: true);
				if (point.X >= 0)
				{
					return point.X;
				}
				return -1;
			}
		}

		[Browsable(false)]
		[Category("Behavior")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[D("Redraw", "Gets or sets whether the control should display its contents.")]
		public bool Redraw
		{
			get
			{
				if (N1 != null && N1.X2 != base.WW)
				{
					base.WW = N1.X2;
				}
				return base.WW;
			}
			set
			{
				if (N1 != null)
				{
					N1.X2 = value;
				}
				base.WW = value;
				UpdateViewRange();
			}
		}

		[DefaultValue(DrawModeEnum.Normal)]
		[D("DrawMode", "Specifies whether the control should fire the OwnerDrawCell event.")]
		[Category("Behavior")]
		public DrawModeEnum DrawMode
		{
			get
			{
				return NF;
			}
			set
			{
				if (NF != value)
				{
					NF = value;
					((Control)this).Invalidate();
				}
			}
		}

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[D("DoubleBuffer", "Specifies whether the control should use an off-screen buffer when painting to reduce flicker.")]
		public bool DoubleBuffer
		{
			get
			{
				return ((Control)this).GetStyle((ControlStyles)65536);
			}
			set
			{
				if (DoubleBuffer != value)
				{
					((Control)this).SetStyle((ControlStyles)65536, value);
				}
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[Browsable(false)]
		[D("ClipSeparators", "Gets or sets the characters to be used as separators in Clip strings.")]
		public string ClipSeparators
		{
			get
			{
				return N1.PW;
			}
			set
			{
				if (value == null || value.Length != 2 || value[0] == value[1])
				{
					throw new ArgumentException("ClipSeparators must be a string with two distinct characters.");
				}
				N1.PW = value;
			}
		}

		[D("Clip", "Gets or sets the contents of the selected range.")]
		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public string Clip
		{
			get
			{
				if (SelectionMode != SelectionModeEnum.ListBox)
				{
					return N1.99(WZ.EJ(), 0E2: false);
				}
				return N1.98(0E0: false);
			}
			set
			{
				N1.9A(WZ.EJ(), value, 0E5: false);
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[D("Editor", "Returns a reference to the cell editor control that is currently active.")]
		[Browsable(false)]
		public Control Editor => (Control)X0.R8;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[D("ComboList", "Gets or sets the list of items to be used by the drop-down editor.")]
		[Browsable(false)]
		public string ComboList
		{
			get
			{
				return N1.PX;
			}
			set
			{
				N1.PX = ((value != null && value.Length > 0) ? value : null);
			}
		}

		[Browsable(false)]
		[D("EditMask", "Gets or sets the mask to be used by the editor.")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public string EditMask
		{
			get
			{
				return N1.PY;
			}
			set
			{
				N1.PY = ((value != null && value.Length > 0) ? value : null);
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[D("Tree", "Controls the appearance of the grid tree (outline column).")]
		[Browsable(true)]
		[E("Layout")]
		public GridTree Tree => N1.PM;

		[D("DataMember", "Gets or sets the sub-list of the data source that is bound to the grid.")]
		[Editor("System.Windows.Forms.Design.DataMemberListEditor, System.Design", typeof(UITypeEditor))]
		[Category("Data")]
		[DefaultValue("")]
		public string DataMember
		{
			get
			{
				return N1.9E();
			}
			set
			{
				N1.9F(this, value);
			}
		}

		[Category("Data")]
		[RefreshProperties(RefreshProperties.Repaint)]
		[TypeConverter("System.Windows.Forms.Design.DataSourceConverter, System.Design")]
		[DefaultValue(null)]
		[D("DataSource", "The data source that is bound to the grid.")]
		public object DataSource
		{
			get
			{
				return N1.9C();
			}
			set
			{
				if (value is C1FlexGridBase || value is 0D)
				{
					0D 0D2 = ((value is C1FlexGridBase) ? ((C1FlexGridBase)value).N1 : ((0D)value));
					if (0D2 != N1)
					{
						if (0D2 == null)
						{
							0D2 = new 0D(50, 10, 1, 1);
						}
						if (N1 != null)
						{
							N1.XL -= OnGridChanged;
						}
						N1 = 0D2;
						if (N1 != null)
						{
							N1.XL += OnGridChanged;
						}
						SetScrollSize();
						OnGridChanged(this, new GridChangedEventArgs(GridChangedTypeEnum.StyleChanged));
					}
				}
				else
				{
					N1.9D(this, value);
				}
			}
		}

		[D("AutoResize", "Gets or sets whether column widths are automatically adjusted when data is loaded.")]
		[Category("Data")]
		[DefaultValue(true)]
		public bool AutoResize
		{
			get
			{
				return NM;
			}
			set
			{
				NM = value;
			}
		}

		[DefaultValue(SubtotalPositionEnum.AboveData)]
		[D("SubtotalPosition", "Gets or sets whether subtotals (node rows) appear above or below the data.")]
		[Category("Behavior")]
		public SubtotalPositionEnum SubtotalPosition
		{
			get
			{
				return N1.X4;
			}
			set
			{
				N1.X4 = value;
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[D("PrintParameters", "Printing support.")]
		[Browsable(false)]
		public GridPrinter PrintParameters => N7;

		[DefaultValue(DropModeEnum.None)]
		[D("DropMode", "Gets or sets a value indicating whether the control can accept data that the user drags onto it.")]
		[Category("Behavior")]
		[Browsable(true)]
		public DropModeEnum DropMode
		{
			get
			{
				return N5.X7;
			}
			set
			{
				N5.X7 = value;
			}
		}

		[Category("Behavior")]
		[DefaultValue(DragModeEnum.Manual)]
		[D("DragMode", "Gets or sets a value indicating whether the user can drag data from the control.")]
		[Browsable(true)]
		public DragModeEnum DragMode
		{
			get
			{
				return N6.X8;
			}
			set
			{
				N6.X8 = value;
			}
		}

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public override bool AllowDrop
		{
			get
			{
				return ((Control)this).AllowDrop;
			}
			set
			{
				((Control)this).AllowDrop = value;
			}
		}

		[Category("Behavior")]
		[D("AllowAddNew", "Allow user to add rows by typing into the last row.")]
		[DefaultValue(false)]
		public bool AllowAddNew
		{
			get
			{
				return X1.X5;
			}
			set
			{
				X1.X5 = value;
			}
		}

		[D("AllowDelete", "Allow user to delete rows by selecting them and pressing DEL.")]
		[Category("Behavior")]
		[DefaultValue(false)]
		public bool AllowDelete
		{
			get
			{
				return X1.X6;
			}
			set
			{
				X1.X6 = value;
			}
		}

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[D("Glyphs", "Gets the collection of control glyphs (images used to show sorting, checkboxes, etc).")]
		public GridGlyphs Glyphs => new GridGlyphs(N1);

		internal 0V WZ => N1.PL;

		internal 0J X0 => N4;

		internal 0E X1 => N1.PT;

		[D("ScrollableRectangle", "Gets the scrollable rectangle (client area minus fixed and frozen rows and columns).")]
		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public override Rectangle ScrollableRectangle
		{
			get
			{
				Rectangle clientRectangle = ((Control)this).ClientRectangle;
				RowColCollection cols = Cols;
				int num = cols.Fixed + cols.Frozen;
				if (num > 0)
				{
					clientRectangle.X = cols.get_XF(num - 1).XE;
					clientRectangle.Width -= clientRectangle.X;
				}
				cols = Rows;
				num = cols.Fixed + cols.Frozen;
				if (num > 0)
				{
					clientRectangle.Y = cols.get_XF(num - 1).XE;
					clientRectangle.Height -= clientRectangle.Y;
				}
				return clientRectangle;
			}
		}

		public event GridChangedEventHandler GridChanged
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				NR = (GridChangedEventHandler)Delegate.Combine(NR, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				NR = (GridChangedEventHandler)Delegate.Remove(NR, value);
			}
		}

		public event BeforeMouseDownEventHandler BeforeMouseDown
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				NS = (BeforeMouseDownEventHandler)Delegate.Combine(NS, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				NS = (BeforeMouseDownEventHandler)Delegate.Remove(NS, value);
			}
		}

		public event DragRowColEventHandler BeforeDragRow
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				NT = (DragRowColEventHandler)Delegate.Combine(NT, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				NT = (DragRowColEventHandler)Delegate.Remove(NT, value);
			}
		}

		public event DragRowColEventHandler AfterDragRow
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				NU = (DragRowColEventHandler)Delegate.Combine(NU, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				NU = (DragRowColEventHandler)Delegate.Remove(NU, value);
			}
		}

		public event DragRowColEventHandler BeforeDragColumn
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				NV = (DragRowColEventHandler)Delegate.Combine(NV, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				NV = (DragRowColEventHandler)Delegate.Remove(NV, value);
			}
		}

		public event DragRowColEventHandler AfterDragColumn
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				NW = (DragRowColEventHandler)Delegate.Combine(NW, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				NW = (DragRowColEventHandler)Delegate.Remove(NW, value);
			}
		}

		public event SortColEventHandler BeforeSort
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				NX = (SortColEventHandler)Delegate.Combine(NX, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				NX = (SortColEventHandler)Delegate.Remove(NX, value);
			}
		}

		public event SortColEventHandler AfterSort
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				NY = (SortColEventHandler)Delegate.Combine(NY, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				NY = (SortColEventHandler)Delegate.Remove(NY, value);
			}
		}

		public event RowColEventHandler BeforeAutosizeRow
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				NZ = (RowColEventHandler)Delegate.Combine(NZ, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				NZ = (RowColEventHandler)Delegate.Remove(NZ, value);
			}
		}

		public event RowColEventHandler BeforeAutosizeColumn
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				O0 = (RowColEventHandler)Delegate.Combine(O0, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				O0 = (RowColEventHandler)Delegate.Remove(O0, value);
			}
		}

		public event RowColEventHandler BeforeResizeRow
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				O1 = (RowColEventHandler)Delegate.Combine(O1, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				O1 = (RowColEventHandler)Delegate.Remove(O1, value);
			}
		}

		public event RowColEventHandler AfterResizeRow
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				O2 = (RowColEventHandler)Delegate.Combine(O2, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				O2 = (RowColEventHandler)Delegate.Remove(O2, value);
			}
		}

		public event RowColEventHandler BeforeResizeColumn
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				O3 = (RowColEventHandler)Delegate.Combine(O3, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				O3 = (RowColEventHandler)Delegate.Remove(O3, value);
			}
		}

		public event RowColEventHandler AfterResizeColumn
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				O4 = (RowColEventHandler)Delegate.Combine(O4, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				O4 = (RowColEventHandler)Delegate.Remove(O4, value);
			}
		}

		public event RowColEventHandler BeforeFreezeRow
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				O5 = (RowColEventHandler)Delegate.Combine(O5, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				O5 = (RowColEventHandler)Delegate.Remove(O5, value);
			}
		}

		public event RowColEventHandler AfterFreezeRow
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				O6 = (RowColEventHandler)Delegate.Combine(O6, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				O6 = (RowColEventHandler)Delegate.Remove(O6, value);
			}
		}

		public event RowColEventHandler BeforeFreezeColumn
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				O7 = (RowColEventHandler)Delegate.Combine(O7, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				O7 = (RowColEventHandler)Delegate.Remove(O7, value);
			}
		}

		public event RowColEventHandler AfterFreezeColumn
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				O8 = (RowColEventHandler)Delegate.Combine(O8, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				O8 = (RowColEventHandler)Delegate.Remove(O8, value);
			}
		}

		public event RangeEventHandler BeforeScroll
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				O9 = (RangeEventHandler)Delegate.Combine(O9, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				O9 = (RangeEventHandler)Delegate.Remove(O9, value);
			}
		}

		public event RangeEventHandler AfterScroll
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OA = (RangeEventHandler)Delegate.Combine(OA, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OA = (RangeEventHandler)Delegate.Remove(OA, value);
			}
		}

		public event RowColEventHandler BeforeScrollTip
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OB = (RowColEventHandler)Delegate.Combine(OB, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OB = (RowColEventHandler)Delegate.Remove(OB, value);
			}
		}

		public event RangeEventHandler BeforeRowColChange
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OC = (RangeEventHandler)Delegate.Combine(OC, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OC = (RangeEventHandler)Delegate.Remove(OC, value);
			}
		}

		public event RangeEventHandler AfterRowColChange
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OD = (RangeEventHandler)Delegate.Combine(OD, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OD = (RangeEventHandler)Delegate.Remove(OD, value);
			}
		}

		public event RangeEventHandler BeforeSelChange
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OE = (RangeEventHandler)Delegate.Combine(OE, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OE = (RangeEventHandler)Delegate.Remove(OE, value);
			}
		}

		public event RangeEventHandler AfterSelChange
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OF = (RangeEventHandler)Delegate.Combine(OF, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OF = (RangeEventHandler)Delegate.Remove(OF, value);
			}
		}

		public event EventHandler RowColChange
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OG = (EventHandler)Delegate.Combine(OG, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OG = (EventHandler)Delegate.Remove(OG, value);
			}
		}

		public event EventHandler SelChange
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OH = (EventHandler)Delegate.Combine(OH, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OH = (EventHandler)Delegate.Remove(OH, value);
			}
		}

		public event EventHandler LeaveCell
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OI = (EventHandler)Delegate.Combine(OI, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OI = (EventHandler)Delegate.Remove(OI, value);
			}
		}

		public event EventHandler EnterCell
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OJ = (EventHandler)Delegate.Combine(OJ, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OJ = (EventHandler)Delegate.Remove(OJ, value);
			}
		}

		public event RowColEventHandler StartEdit
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OK = (RowColEventHandler)Delegate.Combine(OK, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OK = (RowColEventHandler)Delegate.Remove(OK, value);
			}
		}

		public event RowColEventHandler BeforeEdit
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OL = (RowColEventHandler)Delegate.Combine(OL, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OL = (RowColEventHandler)Delegate.Remove(OL, value);
			}
		}

		public event RowColEventHandler AfterEdit
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OM = (RowColEventHandler)Delegate.Combine(OM, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OM = (RowColEventHandler)Delegate.Remove(OM, value);
			}
		}

		public event RowColEventHandler CellButtonClick
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				ON = (RowColEventHandler)Delegate.Combine(ON, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				ON = (RowColEventHandler)Delegate.Remove(ON, value);
			}
		}

		public event RowColEventHandler SetupEditor
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OO = (RowColEventHandler)Delegate.Combine(OO, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OO = (RowColEventHandler)Delegate.Remove(OO, value);
			}
		}

		public event ValidateEditEventHandler ValidateEdit
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OP = (ValidateEditEventHandler)Delegate.Combine(OP, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OP = (ValidateEditEventHandler)Delegate.Remove(OP, value);
			}
		}

		public event EventHandler ChangeEdit
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OQ = (EventHandler)Delegate.Combine(OQ, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OQ = (EventHandler)Delegate.Remove(OQ, value);
			}
		}

		public event RowColEventHandler ComboCloseUp
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OR = (RowColEventHandler)Delegate.Combine(OR, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OR = (RowColEventHandler)Delegate.Remove(OR, value);
			}
		}

		public event RowColEventHandler ComboDropDown
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OS = (RowColEventHandler)Delegate.Combine(OS, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OS = (RowColEventHandler)Delegate.Remove(OS, value);
			}
		}

		public event KeyEditEventHandler KeyDownEdit
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OT = (KeyEditEventHandler)Delegate.Combine(OT, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OT = (KeyEditEventHandler)Delegate.Remove(OT, value);
			}
		}

		public event KeyEditEventHandler KeyUpEdit
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OU = (KeyEditEventHandler)Delegate.Combine(OU, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OU = (KeyEditEventHandler)Delegate.Remove(OU, value);
			}
		}

		public event KeyPressEditEventHandler KeyPressEdit
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OV = (KeyPressEditEventHandler)Delegate.Combine(OV, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OV = (KeyPressEditEventHandler)Delegate.Remove(OV, value);
			}
		}

		public event RowColEventHandler CellChanged
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OW = (RowColEventHandler)Delegate.Combine(OW, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OW = (RowColEventHandler)Delegate.Remove(OW, value);
			}
		}

		public event ListChangedEventHandler AfterDataRefresh
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OX = (ListChangedEventHandler)Delegate.Combine(OX, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OX = (ListChangedEventHandler)Delegate.Remove(OX, value);
			}
		}

		public event GridErrorEventHandler GridError
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OY = (GridErrorEventHandler)Delegate.Combine(OY, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OY = (GridErrorEventHandler)Delegate.Remove(OY, value);
			}
		}

		public event RowColEventHandler BeforeCollapse
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				OZ = (RowColEventHandler)Delegate.Combine(OZ, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				OZ = (RowColEventHandler)Delegate.Remove(OZ, value);
			}
		}

		public event RowColEventHandler AfterCollapse
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				P0 = (RowColEventHandler)Delegate.Combine(P0, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				P0 = (RowColEventHandler)Delegate.Remove(P0, value);
			}
		}

		public event OwnerDrawCellEventHandler OwnerDrawCell
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				P1 = (OwnerDrawCellEventHandler)Delegate.Combine(P1, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				P1 = (OwnerDrawCellEventHandler)Delegate.Remove(P1, value);
			}
		}

		public event RowColEventHandler BeforePageBreak
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				P2 = (RowColEventHandler)Delegate.Combine(P2, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				P2 = (RowColEventHandler)Delegate.Remove(P2, value);
			}
		}

		public event PrintEventHandler BeginPrint
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				//IL_000d: Unknown result type (might be due to invalid IL or missing references)
				//IL_0017: Expected O, but got Unknown
				P3 = (PrintEventHandler)Delegate.Combine((Delegate?)(object)P3, (Delegate?)(object)value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				//IL_000d: Unknown result type (might be due to invalid IL or missing references)
				//IL_0017: Expected O, but got Unknown
				P3 = (PrintEventHandler)Delegate.Remove((Delegate?)(object)P3, (Delegate?)(object)value);
			}
		}

		public event PrintEventHandler EndPrint
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				//IL_000d: Unknown result type (might be due to invalid IL or missing references)
				//IL_0017: Expected O, but got Unknown
				P4 = (PrintEventHandler)Delegate.Combine((Delegate?)(object)P4, (Delegate?)(object)value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				//IL_000d: Unknown result type (might be due to invalid IL or missing references)
				//IL_0017: Expected O, but got Unknown
				P4 = (PrintEventHandler)Delegate.Remove((Delegate?)(object)P4, (Delegate?)(object)value);
			}
		}

		public event PrintPageEventHandler PrintPage
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				//IL_000d: Unknown result type (might be due to invalid IL or missing references)
				//IL_0017: Expected O, but got Unknown
				P5 = (PrintPageEventHandler)Delegate.Combine((Delegate?)(object)P5, (Delegate?)(object)value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				//IL_000d: Unknown result type (might be due to invalid IL or missing references)
				//IL_0017: Expected O, but got Unknown
				P5 = (PrintPageEventHandler)Delegate.Remove((Delegate?)(object)P5, (Delegate?)(object)value);
			}
		}

		public event DragEventHandler StartDrag
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				//IL_000d: Unknown result type (might be due to invalid IL or missing references)
				//IL_0017: Expected O, but got Unknown
				P6 = (DragEventHandler)Delegate.Combine((Delegate?)(object)P6, (Delegate?)(object)value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				//IL_000d: Unknown result type (might be due to invalid IL or missing references)
				//IL_0017: Expected O, but got Unknown
				P6 = (DragEventHandler)Delegate.Remove((Delegate?)(object)P6, (Delegate?)(object)value);
			}
		}

		protected C1FlexGridBase()
		{
			//IL_0010: Unknown result type (might be due to invalid IL or missing references)
			ProviderInfo.Validate(typeof(C1FlexGridBase), this);
			NP = false;
			N1 = new 0D(50, 10, 1, 1);
			N2 = new 0N(this);
			N3 = new 0M(this);
			N4 = new 0J(this);
			N5 = new 0G(this);
			N6 = new 0H(this);
			N7 = new GridPrinter(this);
			N1.XL += OnGridChanged;
			Styles.Normal.Font = ((Control)this).Font;
			7S();
			SetScrollSize();
			if (((Control)this).BackColor != Styles.Normal.BackColor)
			{
				((Control)this).BackColor = Styles.Normal.BackColor;
			}
			AllowEditing = true;
			AllowSorting = AllowSortingEnum.SingleColumn;
			AllowResizing = AllowResizingEnum.Columns;
			AllowDragging = AllowDraggingEnum.Columns;
			AutoResize = true;
			HighLight = HighLightEnum.Always;
			FocusRect = FocusRectEnum.Light;
			DrawMode = DrawModeEnum.Normal;
			ShowButtons = ShowButtonsEnum.WithFocus;
			ShowCursor = false;
			ShowSort = true;
			NN = true;
			NP = true;
		}

		protected override void Dispose(bool disposing)
		{
			base.Dispose(disposing);
			if (N1 != null)
			{
				N1.XL -= OnGridChanged;
				N1 = null;
			}
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		public virtual Assembly GetCallingAssembly()
		{
			return null;
		}

		private IC1ControlPrinter 6W()
		{
			return new 0C(this);
		}

		IC1ControlPrinter IC1ControlPrintable.GetPrinter()
		{
			//ILSpy generated this explicit interface implementation from .override directive in 6W
			return this.6W();
		}

		public void BeginInit()
		{
			NP = false;
		}

		public void EndInit()
		{
			if (Cols.UH != null)
			{
				Cols.E8(Cols.UH);
			}
			Cols.UH = null;
			if (Rows.Count > Rows.Fixed && Cols.Count > Cols.Fixed)
			{
				Select(Rows.Fixed, Cols.Fixed);
			}
			NQ = true;
			SetScrollSize();
			NP = true;
		}

		protected override void OnBindingContextChanged(EventArgs e)
		{
			((Control)this).OnBindingContextChanged(e);
			if (NQ && NP)
			{
				NQ = false;
				NP = false;
				N1.9G(this, 0EE: true);
				NP = true;
				if (Redraw)
				{
					SetScrollSize();
					((Control)this).Invalidate();
				}
			}
		}

		protected internal virtual void OnBeforeSort(SortColEventArgs e)
		{
			if (NX != null)
			{
				NX(this, e);
			}
		}

		protected internal virtual void OnAfterSort(SortColEventArgs e)
		{
			if (NY != null)
			{
				NY(this, e);
			}
		}

		protected internal virtual void OnBeforeDragRow(DragRowColEventArgs e)
		{
			if (NT != null)
			{
				NT(this, e);
			}
		}

		protected internal virtual void OnAfterDragRow(DragRowColEventArgs e)
		{
			if (NU != null)
			{
				NU(this, e);
			}
		}

		protected internal virtual void OnBeforeDragColumn(DragRowColEventArgs e)
		{
			if (NV != null)
			{
				NV(this, e);
			}
		}

		protected internal virtual void OnAfterDragColumn(DragRowColEventArgs e)
		{
			if (NW != null)
			{
				NW(this, e);
			}
		}

		protected internal virtual void OnBeforeAutosizeRow(RowColEventArgs e)
		{
			if (NZ != null)
			{
				NZ(this, e);
			}
		}

		protected internal virtual void OnBeforeAutosizeColumn(RowColEventArgs e)
		{
			if (O0 != null)
			{
				O0(this, e);
			}
		}

		protected internal virtual void OnBeforeResizeRow(RowColEventArgs e)
		{
			if (O1 != null)
			{
				O1(this, e);
			}
		}

		protected internal virtual void OnAfterResizeRow(RowColEventArgs e)
		{
			if (O2 != null)
			{
				O2(this, e);
			}
		}

		protected internal virtual void OnBeforeResizeColumn(RowColEventArgs e)
		{
			if (O3 != null)
			{
				O3(this, e);
			}
		}

		protected internal virtual void OnAfterResizeColumn(RowColEventArgs e)
		{
			if (O4 != null)
			{
				O4(this, e);
			}
		}

		protected internal virtual void OnBeforeMouseDown(BeforeMouseDownEventArgs e)
		{
			if (NS != null)
			{
				NS(this, e);
			}
		}

		protected internal virtual void OnBeforeScroll(RangeEventArgs e)
		{
			if (O9 != null)
			{
				O9(this, e);
			}
		}

		protected internal virtual void OnAfterScroll(RangeEventArgs e)
		{
			if (OA != null)
			{
				OA(this, e);
			}
		}

		protected internal virtual void OnBeforeFreezeRow(RowColEventArgs e)
		{
			if (O5 != null)
			{
				O5(this, e);
			}
		}

		protected internal virtual void OnAfterFreezeRow(RowColEventArgs e)
		{
			if (O6 != null)
			{
				O6(this, e);
			}
		}

		protected internal virtual void OnBeforeFreezeColumn(RowColEventArgs e)
		{
			if (O7 != null)
			{
				O7(this, e);
			}
		}

		protected internal virtual void OnAfterFreezeColumn(RowColEventArgs e)
		{
			if (O8 != null)
			{
				O8(this, e);
			}
		}

		protected internal virtual void OnEnterCell(EventArgs e)
		{
			if (OJ != null)
			{
				OJ(this, e);
			}
		}

		protected internal virtual void OnLeaveCell(EventArgs e)
		{
			if (OI != null)
			{
				OI(this, e);
			}
		}

		protected internal virtual void OnBeforeRowColChange(RangeEventArgs e)
		{
			if (OC != null)
			{
				OC(this, e);
			}
		}

		protected internal virtual void OnAfterRowColChange(RangeEventArgs e)
		{
			if (OD != null)
			{
				OD(this, e);
			}
		}

		protected internal virtual void OnRowColChange(EventArgs e)
		{
			if (OG != null)
			{
				OG(this, e);
			}
		}

		protected internal virtual void OnBeforeSelChange(RangeEventArgs e)
		{
			if (OE != null)
			{
				OE(this, e);
			}
		}

		protected internal virtual void OnAfterSelChange(RangeEventArgs e)
		{
			if (OF != null)
			{
				OF(this, e);
			}
		}

		protected internal virtual void OnSelChange(EventArgs e)
		{
			if (OH != null)
			{
				OH(this, e);
			}
		}

		protected internal virtual void OnBeforeScrollTip(RowColEventArgs e)
		{
			if (OB != null)
			{
				OB(this, e);
			}
		}

		protected internal virtual void OnBeforeEdit(RowColEventArgs e)
		{
			if (OL != null)
			{
				OL(this, e);
			}
		}

		protected internal virtual void OnStartEdit(RowColEventArgs e)
		{
			if (OK != null)
			{
				OK(this, e);
			}
		}

		protected internal virtual void OnValidateEdit(ValidateEditEventArgs e)
		{
			if (OP != null)
			{
				OP(this, e);
			}
		}

		protected internal virtual void OnAfterEdit(RowColEventArgs e)
		{
			if (OM != null)
			{
				OM(this, e);
			}
		}

		protected internal virtual void OnSetupEditor(RowColEventArgs e)
		{
			if (OO != null)
			{
				OO(this, e);
			}
		}

		protected internal virtual void OnChangeEdit(EventArgs e)
		{
			if (OQ != null)
			{
				OQ(this, e);
			}
		}

		protected internal virtual void OnCellButtonClick(RowColEventArgs e)
		{
			if (ON != null)
			{
				ON(this, e);
			}
		}

		protected internal virtual void OnComboDropDown(RowColEventArgs e)
		{
			if (OS != null)
			{
				OS(this, e);
			}
		}

		protected internal virtual void OnComboCloseUp(RowColEventArgs e)
		{
			if (OR != null)
			{
				OR(this, e);
			}
		}

		protected internal virtual void OnKeyUpEdit(KeyEditEventArgs e)
		{
			if (OU != null)
			{
				OU(this, e);
			}
		}

		protected internal virtual void OnKeyDownEdit(KeyEditEventArgs e)
		{
			if (OT != null)
			{
				OT(this, e);
			}
		}

		protected internal virtual void OnKeyPressEdit(KeyPressEditEventArgs e)
		{
			if (OV != null)
			{
				OV(this, e);
			}
		}

		protected internal virtual void OnDataRefresh(ListChangedEventArgs e)
		{
			if (OX != null)
			{
				OX(this, e);
			}
		}

		protected internal virtual void OnCellChanged(RowColEventArgs e)
		{
			if (OW != null)
			{
				OW(this, e);
			}
		}

		protected internal virtual void OnGridError(GridErrorEventArgs e)
		{
			if (OY != null)
			{
				OY(this, e);
			}
		}

		protected internal virtual void OnStartDrag(DragEventArgs e)
		{
			if (P6 != null)
			{
				P6.Invoke((object)this, e);
			}
		}

		protected internal virtual void OnBeforeCollapse(RowColEventArgs e)
		{
			if (OZ != null)
			{
				OZ(this, e);
			}
		}

		protected internal virtual void OnAfterCollapse(RowColEventArgs e)
		{
			if (P0 != null)
			{
				P0(this, e);
			}
		}

		protected internal virtual void OnBeforePageBreak(RowColEventArgs e)
		{
			if (P2 != null)
			{
				P2(this, e);
			}
		}

		protected internal virtual void OnBeginPrint(PrintEventArgs e)
		{
			if (P3 != null)
			{
				P3.Invoke((object)this, e);
			}
		}

		protected internal virtual void OnEndPrint(PrintEventArgs e)
		{
			if (P4 != null)
			{
				P4.Invoke((object)this, e);
			}
		}

		protected internal virtual void OnPrintPage(PrintPageEventArgs e)
		{
			if (P5 != null)
			{
				P5.Invoke((object)this, e);
			}
		}

		protected internal virtual void OnOwnerDrawCell(object sender, OwnerDrawCellEventArgs e)
		{
			if (P1 != null)
			{
				P1(sender, e);
			}
		}

		internal void 6X()
		{
			CellRange v = WZ.V2;
			CellRange v2 = WZ.V3;
			bool flag = v.r1 != v2.r1 || v.c1 != v2.c1;
			bool flag2 = v.r2 != v2.r2 || v.c2 != v2.c2;
			WZ.V4 = false;
			if (flag)
			{
				OnLeaveCell(EventArgs.Empty);
				RangeEventArgs e = new RangeEventArgs(v, v2);
				OnBeforeRowColChange(e);
				WZ.V4 = e.Cancel;
			}
			if (!WZ.V4)
			{
				if (flag || flag2)
				{
					RangeEventArgs e2 = new RangeEventArgs(v, v2);
					OnBeforeSelChange(e2);
					WZ.V4 = e2.Cancel;
				}
				X1.9Q(this, v, v2);
			}
		}

		internal void 6Y(bool 08Y)
		{
			CellRange v = WZ.V2;
			CellRange v2 = WZ.V3;
			bool flag = v.r1 != v2.r1 || v.c1 != v2.c1;
			bool flag2 = v.r2 != v2.r2 || v.c2 != v2.c2 || 08Y;
			if (flag)
			{
				OnEnterCell(EventArgs.Empty);
				OnRowColChange(EventArgs.Empty);
				OnAfterRowColChange(new RangeEventArgs(v, v2));
			}
			if (flag2 || flag)
			{
				OnSelChange(EventArgs.Empty);
				OnAfterSelChange(new RangeEventArgs(v, v2));
			}
			X1.9R(this, v, v2);
		}

		internal bool 6Z(int 08Z, int 090)
		{
			if (!AllowEditing || N1.87(08Z, 090))
			{
				return false;
			}
			if (!Cols[090].AllowEditing || !Rows[08Z].AllowEditing)
			{
				return false;
			}
			if (Rows[08Z].IsNew)
			{
				return false;
			}
			RowColEventArgs e = new RowColEventArgs(08Z, 090);
			OnBeforeEdit(e);
			return !e.Cancel;
		}

		internal bool 70(int 091, int 092, bool 093)
		{
			CheckEnum check = 7P(091, 092);
			ValidateEditEventArgs e = new ValidateEditEventArgs(091, 092, check);
			e.Cancel = !093;
			OnValidateEdit(e);
			return e.Cancel;
		}

		internal bool 71(RowColEventArgs 094)
		{
			OnStartEdit(094);
			if (094.Cancel)
			{
				return false;
			}
			CheckEnum check = 7P(094.Row, 094.Col);
			ValidateEditEventArgs e = new ValidateEditEventArgs(094.Row, 094.Col, check);
			OnValidateEdit(e);
			if (e.Cancel)
			{
				return false;
			}
			return true;
		}

		internal void 72(int 095, int 096, Exception 097, bool 098)
		{
			if (OY != null && !P7)
			{
				P7 = true;
				GridErrorEventArgs e = new GridErrorEventArgs(095, 096, 097, 098);
				OnGridError(e);
				098 = e.Handled;
				P7 = false;
			}
			if (!098)
			{
				throw 097;
			}
		}

		internal void 73(IDataObject 099, ref DragDropEffects 09A)
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_0023: Expected I4, but got Unknown
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0024: Expected O, but got Unknown
			//IL_002d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0033: Expected I4, but got Unknown
			Point mousePosition = Control.MousePosition;
			DragEventArgs e = new DragEventArgs(099, (int)Control.ModifierKeys, mousePosition.X, mousePosition.Y, 09A, 09A);
			OnStartDrag(e);
			09A = (DragDropEffects)(int)e.Effect;
		}

		[D("CellStyle", "Gets or sets the style used to show a cell.")]
		public CellStyle GetCellStyle(int row, int col)
		{
			Style style = N1.8P(row, col);
			if (style == null)
			{
				return null;
			}
			return new CellStyle(style);
		}

		public void SetCellStyle(int row, int col, CellStyle newStyle)
		{
			Style 0CU = newStyle?.VA;
			N1.8Q(row, col, 0CU);
		}

		public CellStyle GetCellStyleDisplay(int row, int col)
		{
			Style styleDisplay = GetStyleDisplay(row, col);
			return new CellStyle(styleDisplay);
		}

		[D("GetCellImage", "Gets or sets the image in a grid cell.")]
		public Image GetCellImage(int row, int col)
		{
			return N1.8S(row, col);
		}

		public void SetCellImage(int row, int col, Image newImage)
		{
			N1.8T(row, col, newImage);
		}

		[D("SetData", "Stores a value in the grid.")]
		public virtual bool SetData(int row, int col, object data, bool coerce)
		{
			return 7N(row, col, data, coerce);
		}

		public virtual bool SetData(CellRange rg, object data, bool coerce)
		{
			bool result = true;
			rg.Normalize();
			for (int i = rg.r1; i <= rg.r2; i++)
			{
				for (int j = rg.c1; j <= rg.c2; j++)
				{
					if (!7N(i, j, data, coerce))
					{
						result = false;
					}
				}
			}
			return result;
		}

		public virtual bool SetData(int row, int col, object data)
		{
			return SetData(row, col, data, coerce: true);
		}

		public virtual bool SetData(CellRange rg, object data)
		{
			return SetData(rg, data, coerce: true);
		}

		public virtual bool SetData(int row, string colName, object data, bool coerce)
		{
			return SetData(row, Cols[colName].Index, data, coerce);
		}

		public virtual bool SetData(int row, string colName, object data)
		{
			return SetData(row, Cols[colName].Index, data);
		}

		protected internal virtual bool SetDataEdit(int row, int col, object data, bool coerce)
		{
			return SetData(row, col, data, coerce);
		}

		[D("GetData", "Gets a value from the grid.")]
		public virtual object GetData(int row, int col)
		{
			return N1.GetData(row, col);
		}

		public virtual object GetData(int row, string colName)
		{
			return GetData(row, Cols[colName].Index);
		}

		[D("GetDataDisplay", "Gets a formatted value from the grid.")]
		public virtual string GetDataDisplay(int row, int col)
		{
			return N1.GetDataDisplay(row, col);
		}

		public virtual string GetDataDisplay(int row, string colName)
		{
			return GetDataDisplay(row, Cols[colName].Index);
		}

		[D("Select", "Select a cell or range.")]
		public void Select(CellRange rg, bool show)
		{
			WZ.ED(this, rg, show);
		}

		public void Select(CellRange rg)
		{
			Select(rg, show: true);
		}

		public void Select(int row, int col, int rowSel, int colSel, bool show)
		{
			Select(new CellRange(N1, row, col, rowSel, colSel), show);
		}

		public void Select(int row, int col, int rowSel, int colSel)
		{
			Select(row, col, rowSel, colSel, show: true);
		}

		public void Select(int row, int col, bool show)
		{
			Select(row, col, row, col, show);
		}

		public void Select(int row, int col)
		{
			Select(row, col, show: true);
		}

		internal void 74(Point 09B, bool 09C)
		{
			Select(09B.Y, 09B.X, 09C);
		}

		internal void 75(int 09D, int 09E, bool 09F)
		{
			CellRange cellRange = WZ.EJ();
			Select(cellRange.r1, cellRange.c1, 09D, 09E, 09F);
		}

		internal void 76(Point 09G, bool 09H)
		{
			75(09G.Y, 09G.X, 09H);
		}

		internal void 77(int 09I, int 09J, bool 09K, RowCollection 09L)
		{
			WZ.EE(this, 09I, 09J, 09K, 09L);
		}

		internal bool 78()
		{
			return WZ.EI();
		}

		[D("Sort", "Sort columns or ranges.")]
		public virtual void Sort(SortFlags order, int col)
		{
			Sort(order, col, col);
		}

		public virtual void Sort(SortFlags order, int col1, int col2)
		{
			if (Rows.Count > Rows.Fixed)
			{
				Sort(order, new CellRange(N1, Rows.Fixed, col1, Rows.Count - 1, col2));
				ShowSortAt(order, col1);
			}
		}

		public virtual void Sort(SortFlags order, CellRange rg)
		{
			N1.Sort(order, rg);
			ShowSortAt(order, -1);
		}

		public virtual void Sort(int index, int count, IComparer comparer)
		{
			N1.Sort(index, count, comparer);
			ShowSortAt(SortFlags.None, -1);
		}

		public virtual void Sort(IComparer comparer)
		{
			N1.Sort(Rows.Fixed, Rows.Count - Rows.Fixed, comparer);
			ShowSortAt(SortFlags.None, -1);
		}

		[D("ShowSortAt", "Shows the sorting symbol on a column header.")]
		public void ShowSortAt(SortFlags order, int col)
		{
			N1.8H(order, col);
		}

		[D("ShowCell", "Scroll a cell into view.")]
		public virtual void ShowCell(int row, int col)
		{
			if (col > N8.c1 && col < N8.c2 && row > N8.r1 && row < N8.r2)
			{
				return;
			}
			Rectangle cellRectDisplay = GetCellRectDisplay(row, col);
			Rectangle rectangle = cellRectDisplay;
			Rectangle clientRectangle = ((Control)this).ClientRectangle;
			int num = Cols.Fixed + Cols.Frozen;
			if (col >= num)
			{
				int left = Cols[num].Left;
				if (rectangle.Right > clientRectangle.Right)
				{
					rectangle.X -= rectangle.Right - clientRectangle.Right;
				}
				if (rectangle.X < left)
				{
					rectangle.X = left;
				}
			}
			int num2 = Rows.Fixed + Rows.Frozen;
			if (row >= num2)
			{
				int top = Rows[num2].Top;
				if (rectangle.Bottom > clientRectangle.Bottom)
				{
					rectangle.Y -= rectangle.Bottom - clientRectangle.Bottom;
				}
				if (rectangle.Y < top)
				{
					rectangle.Y = top;
				}
			}
			if (rectangle.X != cellRectDisplay.X || rectangle.Y != cellRectDisplay.Y)
			{
				Point scrollPosition = base.ScrollPosition;
				scrollPosition.Offset(rectangle.X - cellRectDisplay.X, rectangle.Y - cellRectDisplay.Y);
				base.ScrollPosition = scrollPosition;
			}
		}

		[D("Invalidate", "Invalidate a cell or range.")]
		public void Invalidate(int row, int col)
		{
			Invalidate(new CellRange(N1, row, col));
		}

		public void Invalidate(int row1, int col1, int row2, int col2)
		{
			Invalidate(new CellRange(N1, row1, col1, row2, col2));
		}

		internal void 79(Point 09M)
		{
			Invalidate(new CellRange(N1, 09M.Y, 09M.X));
		}

		public virtual void Invalidate(CellRange rg)
		{
			if (!Redraw)
			{
				return;
			}
			if (rg.c1 < 0 && rg.r1 > -1)
			{
				rg.c1 = 0;
				rg.c2 = Cols.Count - 1;
			}
			if (rg.r1 < 0 && rg.c1 > -1)
			{
				rg.r1 = 0;
				rg.r2 = Rows.Count - 1;
			}
			if (!rg.IsValid)
			{
				return;
			}
			rg.Normalize();
			if ((rg.r1 <= Rows.Fixed + Rows.Frozen || (rg.r1 <= BottomRow && rg.r2 >= TopRow)) && (rg.c1 <= Cols.Fixed + Cols.Frozen || (rg.c1 <= RightCol && rg.c2 >= LeftCol)))
			{
				Rectangle rectangle = GetCellRectDisplay(rg.r1, rg.c1);
				if (!rg.IsSingleCell)
				{
					rectangle = Rectangle.Union(rectangle, GetCellRectDisplay(rg.r2, rg.c2));
				}
				((Control)this).Invalidate(rectangle);
			}
		}

		[D("HitTest", "Gets information about the control at a specified point on the screen.")]
		public HitTestInfo HitTest(int x, int y)
		{
			return N2.BS(x, y);
		}

		[D("GetCellRect", "Gets the bounding rectangle for a cell.")]
		public Rectangle GetCellRect(int row, int col, bool show)
		{
			if (show)
			{
				ShowCell(row, col);
			}
			return GetCellRectDisplay(row, col, clipHorz: true, clipVert: true);
		}

		public Rectangle GetCellRect(int row, int col)
		{
			return GetCellRect(row, col, show: false);
		}

		[D("FindRow", "Finds a row that contains a given string.")]
		public virtual int FindRow(string strFind, int rowStart, int col, bool caseSensitive, bool fullMatch, bool wrap)
		{
			return N1.FindRow(strFind, rowStart, col, caseSensitive, fullMatch, wrap);
		}

		public virtual int FindRow(object objFind, int rowStart, int col, bool wrap)
		{
			return N1.FindRow(objFind, rowStart, col, wrap);
		}

		[D("Clear", "Clears the contents of the control.")]
		public void Clear(ClearFlags clearFlags, CellRange rg)
		{
			N1.96(clearFlags, rg);
		}

		public void Clear(ClearFlags clearFlags, int row1, int col1, int row2, int col2)
		{
			Clear(clearFlags, new CellRange(N1, row1, col1, row2, col2));
		}

		public void Clear(ClearFlags clearFlags, int row, int col)
		{
			Clear(clearFlags, new CellRange(N1, row, col, row, col));
		}

		public void Clear(ClearFlags clearFlags)
		{
			Clear(clearFlags, new CellRange(N1, 0, 0, Rows.Count - 1, Cols.Count - 1));
		}

		public void Clear()
		{
			Clear(ClearFlags.All);
		}

		[D("GetCellRange", "Returns a CellRange object that can be used to manipulate a range of cells.")]
		public CellRange GetCellRange(int row, int col)
		{
			return new CellRange(N1, row, col);
		}

		public CellRange GetCellRange(int row1, int col1, int row2, int col2)
		{
			return new CellRange(N1, row1, col1, row2, col2);
		}

		[Browsable(false)]
		[D("CreateImage", "Creates an image of the grid.")]
		public Image CreateImage()
		{
			return CreateImage(0, 0, Rows.Count - 1, Cols.Count - 1);
		}

		public Image CreateImage(int row1, int col1, int row2, int col2)
		{
			CellRange rg = new CellRange(N1, row1, col1, row2, col2);
			return CreateImage(rg);
		}

		public Image CreateImage(CellRange rg)
		{
			return CreateImage(rg, (EmfType)3);
		}

		public Image CreateImage(int row1, int col1, int row2, int col2, EmfType emfType)
		{
			//IL_0014: Unknown result type (might be due to invalid IL or missing references)
			CellRange rg = new CellRange(N1, row1, col1, row2, col2);
			return CreateImage(rg, emfType);
		}

		public Image CreateImage(CellRange rg, EmfType emfType)
		{
			//IL_017a: Unknown result type (might be due to invalid IL or missing references)
			//IL_017b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0181: Expected O, but got Unknown
			bool redraw = Redraw;
			Redraw = false;
			try
			{
				ArrayList arrayList = new ArrayList();
				ArrayList arrayList2 = new ArrayList();
				rg.Normalize();
				if (rg.r1 > 0 || rg.r2 < Rows.Count - 1)
				{
					for (int i = Rows.Fixed + Rows.Frozen; i <= rg.r2; i++)
					{
						if (Rows[i].Visible && !rg.ContainsRow(i))
						{
							Rows[i].Visible = false;
							arrayList.Add(i);
						}
					}
				}
				if (rg.c1 > 0 || rg.c2 < Cols.Count - 1)
				{
					for (int j = Cols.Fixed + Cols.Frozen; j <= rg.c2; j++)
					{
						if (Cols[j].Visible && !rg.ContainsCol(j))
						{
							Cols[j].Visible = false;
							arrayList2.Add(j);
						}
					}
				}
				Rectangle rectangle = new Rectangle(0, 0, Cols[rg.c2].Right, Rows[rg.r2].Bottom);
				Graphics val = ((Control)this).CreateGraphics();
				Metafile val2;
				try
				{
					IntPtr hdc = val.GetHdc();
					val2 = new Metafile(hdc, rectangle, (MetafileFrameUnit)2, emfType);
					val.ReleaseHdc(hdc);
				}
				finally
				{
					((IDisposable)val)?.Dispose();
				}
				Graphics val3 = Graphics.FromImage((Image)(object)val2);
				try
				{
					val3.FillRectangle(Styles.Normal.XI, rectangle);
					7H(Styles.Normal.XI);
					rg.Normalize();
					for (int i = 0; i <= rg.r2; i++)
					{
						if (Rows[i].HeightDisplay > 0)
						{
							for (int j = 0; j <= rg.c2; j++)
							{
								DrawCellImage(val3, i, j, rectangle);
							}
						}
					}
					7H(null);
					CellStyle cellStyle = Styles[CellStyleEnum.EmptyArea];
					if (cellStyle.Border.Style != BorderStyleEnum.None)
					{
						cellStyle.VA.52(val3, rectangle, "", null, 02.KA);
						Rectangle 04O = rectangle;
						04O.Width = 1;
						cellStyle.VA.52(val3, 04O, "", null, 02.KA);
						04O = rectangle;
						04O.Height = 1;
						cellStyle.VA.52(val3, 04O, "", null, 02.KA);
					}
				}
				finally
				{
					((IDisposable)val3)?.Dispose();
				}
				foreach (object item in arrayList)
				{
					int index = (int)item;
					Rows[index].Visible = true;
				}
				foreach (object item2 in arrayList2)
				{
					int index2 = (int)item2;
					Cols[index2].Visible = true;
				}
				return (Image)(object)val2;
			}
			finally
			{
				Redraw = redraw;
			}
		}

		protected internal virtual void DrawCellImage(Graphics g, int row, int col, Rectangle rcBounds)
		{
			Rectangle rc = N1.88(row, col);
			rc.Intersect(rcBounds);
			if (!rc.IsEmpty)
			{
				Image 0AK;
				CheckEnum 0AL;
				string str = 7M(row, col, out 0AK, out 0AL);
				Style styleDisplay = N1.GetStyleDisplay(row, col);
				DrawCell(g, row, col, styleDisplay, rc, str, 0AK, 0AL);
			}
		}

		[D("StartEditing", "Start editing a cell.")]
		public virtual bool StartEditing(int row, int col, char key)
		{
			return StartEditing(row, col, key, force: true);
		}

		public bool StartEditing(int row, int col)
		{
			return StartEditing(row, col, '\r');
		}

		public bool StartEditing()
		{
			return StartEditing(Row, Col);
		}

		public bool FinishEditing()
		{
			return FinishEditing(cancel: false);
		}

		public bool FinishEditing(bool cancel)
		{
			return X0.BA(cancel);
		}

		protected internal virtual bool StartEditing(int row, int col, char key, bool force)
		{
			if (!Selection.Contains(row, col))
			{
				Select(row, col, show: true);
			}
			return X0.B4(row, col, key, force);
		}

		protected internal virtual bool StartEditing(int row, int col, Point ptMouse, bool dblClick)
		{
			return X0.B5(row, col, ptMouse, dblClick);
		}

		[D("SetDataBinding", "Set DataSource and DataMember properties.")]
		public void SetDataBinding(object dataSource, string dataMember)
		{
			N1.9B(this, dataSource, dataMember);
		}

		[D("Aggregate", "Gets Aggregate statistics for cell ranges.")]
		public double Aggregate(AggregateEnum aggType, CellRange rg, AggregateFlags flags)
		{
			switch (aggType)
			{
			case AggregateEnum.None:
			case AggregateEnum.Clear:
			case AggregateEnum.Percent:
				throw new ArgumentException("Invalid function for Aggregate.");
			default:
				return N1.9J(aggType, rg, flags);
			}
		}

		public double Aggregate(AggregateEnum aggType, AggregateFlags flags)
		{
			CellRange selection = Selection;
			if (SelectionMode == SelectionModeEnum.ListBox)
			{
				selection.r1 = (selection.r2 = -1);
			}
			return Aggregate(aggType, selection, flags);
		}

		public double Aggregate(AggregateEnum aggType, int r1, int c1, int r2, int c2, AggregateFlags flags)
		{
			CellRange rg = new CellRange(N1, r1, c1, r2, c2);
			return Aggregate(aggType, rg, flags);
		}

		public double Aggregate(AggregateEnum aggType, CellRange rg)
		{
			return Aggregate(aggType, rg, AggregateFlags.None);
		}

		public double Aggregate(AggregateEnum aggType)
		{
			return Aggregate(aggType, AggregateFlags.None);
		}

		public double Aggregate(AggregateEnum aggType, int r1, int c1, int r2, int c2)
		{
			return Aggregate(aggType, r1, c1, r2, c2, AggregateFlags.None);
		}

		[D("Subtotal", "Group and total rows based on cell contents.")]
		public void Subtotal(AggregateEnum aggType, int level, int groupFrom, int groupTo, int totalOn, string caption)
		{
			N1.9K(aggType, level, groupFrom, groupTo, totalOn, caption);
		}

		public void Subtotal(AggregateEnum aggType, int level, int groupOn, int totalOn, string caption)
		{
			int groupFrom = ((groupOn >= Cols.Fixed) ? Cols.Fixed : 0);
			if (groupOn == -1)
			{
				groupFrom = -1;
			}
			Subtotal(aggType, level, groupFrom, groupOn, totalOn, caption);
		}

		public void Subtotal(AggregateEnum aggType, int level, int groupOn, int totalOn)
		{
			int groupFrom = ((groupOn >= Cols.Fixed) ? Cols.Fixed : 0);
			if (groupOn == -1)
			{
				groupFrom = -1;
			}
			Subtotal(aggType, level, groupFrom, groupOn, totalOn, null);
		}

		public void Subtotal(AggregateEnum aggType)
		{
			Subtotal(aggType, -1, -1, -1, -1, null);
		}

		[D("AddItem", "Adds a row to the grid.")]
		public void AddItem(string item)
		{
			AddItem(item, Rows.Count);
		}

		public void AddItem(string item, int index)
		{
			Rows.Insert(index);
			if (item != null)
			{
				string[] array = item.Split(new char[1] { ClipSeparators[0] });
				int num = Math.Min(array.Length, Cols.Count);
				for (int i = 0; i < num; i++)
				{
					SetData(index, i, array[i], coerce: true);
				}
			}
		}

		public void AddItem(object[] items)
		{
			AddItem(items, Rows.Count, 0);
		}

		public void AddItem(object[] items, int rowIndex, int colIndex)
		{
			Rows.Insert(rowIndex);
			for (int i = 0; i < items.Length; i++)
			{
				int num = colIndex + i;
				if (num >= Cols.Count)
				{
					break;
				}
				SetData(rowIndex, num, items[i], coerce: true);
			}
		}

		[D("RemoveItem", "Removes a row from the grid.")]
		public void RemoveItem()
		{
			RemoveItem(Rows.Count - 1);
		}

		public void RemoveItem(int index)
		{
			Rows.Remove(index);
		}

		[D("PrintGrid", "Printing support.")]
		public bool PrintGrid(string docName, PrintGridFlags flags)
		{
			//IL_0021: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				return N7.D4(docName, flags);
			}
			catch (Exception ex)
			{
				MessageBox.Show("Cannot print grid: " + ex.Message);
				return false;
			}
		}

		public bool PrintGrid(string docName, PrintGridFlags flags, string header, string footer)
		{
			N7.Header = header;
			N7.Footer = footer;
			return PrintGrid(docName, flags);
		}

		public bool PrintGrid(string docName)
		{
			return PrintGrid(docName, PrintGridFlags.ActualSize);
		}

		[D("SaveGrid", "Saves the grid to a file.")]
		public void SaveGrid(string fileName, FileFormatEnum format, bool fixedCells, Encoding encoding)
		{
			0U.EC(this, fileName, format, fixedCells, encoding);
		}

		public void SaveGrid(string fileName, FileFormatEnum format, bool fixedCells)
		{
			0U.EC(this, fileName, format, fixedCells, Encoding.ASCII);
		}

		public void SaveGrid(string fileName, FileFormatEnum format)
		{
			0U.EC(this, fileName, format, 0M7: false, Encoding.ASCII);
		}

		[D("LoadGrid", "Loads a grid from a file.")]
		public void LoadGrid(string fileName, FileFormatEnum format, bool fixedCells, Encoding encoding)
		{
			0U.EA(this, fileName, format, fixedCells, encoding);
		}

		public void LoadGrid(string fileName, FileFormatEnum format, bool fixedCells)
		{
			0U.EA(this, fileName, format, fixedCells, Encoding.ASCII);
		}

		public void LoadGrid(string fileName, FileFormatEnum format)
		{
			0U.EA(this, fileName, format, 0LY: false, Encoding.ASCII);
		}

		protected internal virtual void OnGridChanged(object sender, GridChangedEventArgs e)
		{
			if (!NP)
			{
				return;
			}
			switch (e.GridChangedType)
			{
			case GridChangedTypeEnum.RepaintGrid:
				if (Redraw)
				{
					((Control)this).Invalidate();
				}
				break;
			case GridChangedTypeEnum.StyleChanged:
			{
				Color backColor = Styles.Normal.BackColor;
				if (((Control)this).BackColor != backColor)
				{
					((Control)this).BackColor = backColor;
				}
				backColor = Styles.Normal.ForeColor;
				if (((Control)this).ForeColor != backColor)
				{
					((Control)this).ForeColor = backColor;
				}
				if (Redraw && !NO)
				{
					((Control)this).Invalidate();
				}
				break;
			}
			case GridChangedTypeEnum.ColSelected:
				if (Redraw)
				{
					Invalidate(Rows.Fixed, e.c1, BottomRow, e.c2);
				}
				break;
			case GridChangedTypeEnum.RowSelected:
				if (Redraw)
				{
					Invalidate(e.r1, Cols.Fixed, e.r2, RightCol);
				}
				break;
			case GridChangedTypeEnum.BeforeSelChange:
				6X();
				break;
			case GridChangedTypeEnum.AfterSelChange:
				6Y(e.r1 > -1 || e.c1 > -1);
				break;
			case GridChangedTypeEnum.BeforeCollapse:
			{
				RowColEventArgs e2 = new RowColEventArgs(e.r1, N1.PM.Column);
				OnBeforeCollapse(e2);
				N1.PM.VS = e2.Cancel;
				break;
			}
			case GridChangedTypeEnum.AfterCollapse:
			{
				SetScrollSize();
				((Control)this).Invalidate();
				RowColEventArgs e2 = new RowColEventArgs(e.r1, N1.PM.Column);
				OnAfterCollapse(e2);
				break;
			}
			case GridChangedTypeEnum.RepaintCell:
				OnCellChanged(new RowColEventArgs(e.r1, e.c1));
				goto case GridChangedTypeEnum.RepaintRange;
			case GridChangedTypeEnum.Update:
				if (Redraw)
				{
					((Control)this).Update();
				}
				break;
			case GridChangedTypeEnum.RepaintRange:
				if (((Control)this).Visible && Redraw)
				{
					Invalidate(e.r1, e.c1, e.r2, e.c2);
					if (NH && Cols.Fixed > 0)
					{
						Invalidate(e.r1, 0, e.r2, 0);
					}
				}
				break;
			case GridChangedTypeEnum.RowMoved:
			case GridChangedTypeEnum.RowAdded:
				if (N1.9H())
				{
					N1.PO.A7();
				}
				else
				{
					ShowSortAt(SortFlags.None, -1);
				}
				goto default;
			case GridChangedTypeEnum.EnsureVisible:
				ShowCell(e.r1, e.c1);
				break;
			case GridChangedTypeEnum.Select:
				Select(e.r1, e.c1);
				break;
			default:
				if (((Control)this).Visible && Redraw)
				{
					X1.9P();
					SetScrollSize();
					((Control)this).Invalidate();
				}
				break;
			}
			if (NR != null)
			{
				NR(this, e);
			}
		}

		protected void InitView()
		{
			base.ScrollPosition = new Point(0, 0);
			SetScrollSize();
			((Control)this).Invalidate();
		}

		protected virtual void SetScrollSize()
		{
			if (Redraw)
			{
				Size wS = new Size(0, 0);
				int count = Cols.Count;
				if (count > 0)
				{
					wS.Width = Cols[count - 1].Right;
				}
				count = Rows.Count;
				if (count > 0)
				{
					wS.Height = Rows[count - 1].Bottom;
				}
				base.WS = wS;
				UpdateViewRange();
				base.WT = new Size(Cols.DefaultSize, Rows.DefaultSize);
			}
		}

		protected internal virtual Point GetCellAt(int x, int y, bool fixedOK)
		{
			Point result = new Point(-1, -1);
			if (fixedOK)
			{
				int num = Rows.Fixed + Rows.Frozen;
				for (int i = 0; i < num; i++)
				{
					if (Rows[i].Bottom > y)
					{
						result.Y = i;
						break;
					}
				}
			}
			if (result.Y < 0)
			{
				result.Y = Rows.DL(y - base.ScrollPosition.Y);
			}
			if (fixedOK)
			{
				int num2 = Cols.Fixed + Cols.Frozen;
				for (int j = 0; j < num2; j++)
				{
					if (Cols[j].Right > x)
					{
						result.X = j;
						break;
					}
				}
			}
			if (result.X < 0)
			{
				result.X = Cols.DL(x - base.ScrollPosition.X);
			}
			if (result.X < 0 && NL && x > 0)
			{
				result.X = Cols.DN();
			}
			return result;
		}

		protected internal virtual Point GetCellAt(int x, int y)
		{
			return GetCellAt(x, y, fixedOK: true);
		}

		protected internal virtual void MoveSelection(MoveCursorEnum move, bool extend)
		{
			CellRange cellRange = WZ.EJ();
			int row = (extend ? cellRange.r2 : cellRange.r1);
			int col = (extend ? cellRange.c2 : cellRange.c1);
			MoveSelection(move, extend, row, col);
		}

		protected internal virtual void MoveSelection(MoveCursorEnum move, bool extend, int row, int col)
		{
			switch (move)
			{
			case MoveCursorEnum.CellPrev:
			{
				int num = 7C(Cols, col);
				if (num != col)
				{
					col = num;
					break;
				}
				num = 7C(Rows, row);
				if (num != row)
				{
					row = num;
					col = 7B(Cols);
				}
				break;
			}
			case MoveCursorEnum.CellNext:
			{
				int num = 7D(Cols, col);
				if (num != col)
				{
					col = num;
					break;
				}
				num = 7D(Rows, row);
				if (num != row)
				{
					row = num;
					col = 7A(Cols);
				}
				break;
			}
			case MoveCursorEnum.CellUp:
				row = 7C(Rows, row);
				break;
			case MoveCursorEnum.CellDown:
				row = 7D(Rows, row);
				break;
			case MoveCursorEnum.PageUp:
				row = 7F(Rows, row, 09Y: true);
				break;
			case MoveCursorEnum.PageDown:
				row = 7E(Rows, row, 09V: true);
				break;
			case MoveCursorEnum.PageLeft:
				col = 7F(Cols, col, 09Y: false);
				break;
			case MoveCursorEnum.PageRight:
				col = 7E(Cols, col, 09V: false);
				break;
			case MoveCursorEnum.HomeUp:
				row = 7A(Rows);
				break;
			case MoveCursorEnum.EndDown:
				row = 7B(Rows);
				break;
			case MoveCursorEnum.HomeLeft:
				col = 7A(Cols);
				break;
			case MoveCursorEnum.EndRight:
				col = 7B(Cols);
				break;
			case MoveCursorEnum.CellLeft:
			{
				int num = 7C(Cols, col);
				if (num == col)
				{
					row = N1.PM.FH(row, MoveCursorEnum.CellLeft);
				}
				else
				{
					col = num;
				}
				break;
			}
			case MoveCursorEnum.CellRight:
			{
				int num = 7D(Cols, col);
				if (num == col)
				{
					row = N1.PM.FH(row, MoveCursorEnum.CellRight);
				}
				else
				{
					col = num;
				}
				break;
			}
			}
			CellRange 0MB;
			if (extend)
			{
				0MB = WZ.EJ();
				0MB.r2 = row;
				0MB.c2 = col;
			}
			else
			{
				0MB = new CellRange(N1, row, col);
			}
			WZ.ED(this, 0MB, 0MC: true);
		}

		internal int 7A(RowColCollection 09N)
		{
			int i;
			for (i = 09N.Fixed; i < 09N.Count && 09N.get_XF(i).XC == 0; i++)
			{
			}
			return i;
		}

		internal int 7B(RowColCollection 09O)
		{
			int num = 09O.Count - 1;
			while (num > 09O.Fixed && 09O.get_XF(num).XC == 0)
			{
				num--;
			}
			return num;
		}

		internal int 7C(RowColCollection 09P, int 09Q)
		{
			for (int num = 09Q - 1; num >= 09P.Fixed; num--)
			{
				if (09P.get_XF(num).XC > 0)
				{
					return num;
				}
			}
			return 09Q;
		}

		internal int 7D(RowColCollection 09R, int 09S)
		{
			if (09S < -1)
			{
				return 09S;
			}
			for (int i = 09S + 1; i < 09R.Count; i++)
			{
				if (09R.get_XF(i).XC > 0)
				{
					return i;
				}
			}
			return 09S;
		}

		internal int 7E(RowColCollection 09T, int 09U, bool 09V)
		{
			if (09U < -1)
			{
				return 09U;
			}
			Rectangle scrollableRectangle = ScrollableRectangle;
			int num = (09V ? scrollableRectangle.Height : scrollableRectangle.Width);
			int num2 = 0;
			int i = -1;
			for (int j = 09U + 1; j < 09T.Count - 1; j++)
			{
				num2 += 09T.get_XF(j + 1).XC;
				if (num2 >= num)
				{
					i = j;
					break;
				}
			}
			if (i < 0)
			{
				i = 09T.Count - 1;
			}
			for (; 09T.get_XF(i).XC == 0 && i < 09T.Count - 1; i++)
			{
			}
			return i;
		}

		internal int 7F(RowColCollection 09W, int 09X, bool 09Y)
		{
			Rectangle scrollableRectangle = ScrollableRectangle;
			int num = (09Y ? scrollableRectangle.Height : scrollableRectangle.Width);
			int num2 = 0;
			int num3 = -1;
			for (int num4 = 09X - 1; num4 > 09W.Fixed; num4--)
			{
				num2 += 09W.get_XF(num4 - 1).XC;
				if (num2 >= num)
				{
					num3 = num4;
					break;
				}
			}
			if (num3 < 0)
			{
				num3 = 09W.Fixed;
			}
			while (09W.get_XF(num3).XC == 0 && num3 > 09W.Fixed)
			{
				num3--;
			}
			return num3;
		}

		protected internal virtual int CheckNodeChildren(int row, int col, int level)
		{
			return N1.9M(row, level);
		}

		protected internal virtual Rectangle GetCellRectDisplay(int row, int col, bool clipHorz, bool clipVert)
		{
			if (col >= Cols.Count || row >= Rows.Count)
			{
				return new Rectangle(0, 0, 0, 0);
			}
			Rectangle clientRectangle = ((Control)this).ClientRectangle;
			Rectangle result = clientRectangle;
			if (col > -1)
			{
				result.X = Cols[col].Left;
				result.Width = Cols[col].WidthDisplay;
			}
			if (row > -1)
			{
				result.Y = Rows[row].Top;
				result.Height = Rows[row].HeightDisplay;
			}
			int num = Rows.Fixed + Rows.Frozen;
			int num2 = Cols.Fixed + Cols.Frozen;
			if (row >= num)
			{
				result.Y += base.ScrollPosition.Y;
			}
			if (col >= num2)
			{
				result.X += base.ScrollPosition.X;
			}
			if (clipHorz)
			{
				if (col >= num2)
				{
					int left = Cols[num2].Left;
					if (result.X < left)
					{
						result.Width -= left - result.X;
						result.X = left;
						if (result.Width < 0)
						{
							result.Width = 0;
						}
					}
				}
				if (result.Right > clientRectangle.Right)
				{
					result.Width -= result.Right - clientRectangle.Right - 3;
				}
			}
			if (clipVert)
			{
				if (row >= num)
				{
					int top = Rows[num].Top;
					if (result.Y < top)
					{
						result.Height -= top - result.Y;
						result.Y = top;
						if (result.Height < 0)
						{
							result.Height = 0;
						}
					}
				}
				if (result.Bottom > clientRectangle.Bottom)
				{
					result.Height -= result.Bottom - clientRectangle.Bottom - 3;
				}
			}
			if (NL && result.Right < clientRectangle.Right)
			{
				int num3 = Cols.DN();
				if (col == num3)
				{
					result.Width = clientRectangle.Right - result.Left;
				}
				if (col > num3)
				{
					result.X = clientRectangle.Right + 1;
				}
			}
			return result;
		}

		protected internal virtual Rectangle GetCellRectDisplay(int row, int col, bool clip)
		{
			return GetCellRectDisplay(row, col, clip, clip);
		}

		protected internal virtual Rectangle GetCellRectDisplay(int row, int col)
		{
			return GetCellRectDisplay(row, col, clipHorz: false, clipVert: false);
		}

		protected internal virtual Rectangle GetCellRectEditor(int row, int col)
		{
			Rectangle cellRectDisplay = GetCellRectDisplay(row, col, clipHorz: true, clipVert: true);
			if (!N1.8J(row, col))
			{
				cellRectDisplay.Intersect(ScrollableRectangle);
			}
			int num = N1.PM.FE(row, col);
			if (num > 0 && cellRectDisplay.Width > 12)
			{
				cellRectDisplay.X += num;
				cellRectDisplay.Width -= num;
			}
			return cellRectDisplay;
		}

		protected internal virtual bool ExtendCol(int col)
		{
			if (NL)
			{
				return col == Cols.DN();
			}
			return false;
		}

		protected override Rectangle BuildScrollableRectangle(int dx, int dy)
		{
			if (dx != 0 && dy != 0)
			{
				return Rectangle.Empty;
			}
			Rectangle scrollableRectangle = ScrollableRectangle;
			if (dx != 0)
			{
				scrollableRectangle.Y = 0;
				scrollableRectangle.Height = ((Control)this).ClientSize.Height;
			}
			if (dy != 0)
			{
				scrollableRectangle.X = 0;
				scrollableRectangle.Width = ((Control)this).ClientSize.Width;
			}
			return scrollableRectangle;
		}

		protected internal virtual bool IsCellCursor(int row, int col)
		{
			return N1.8L(row, col);
		}

		protected internal virtual bool IsCellFixed(int row, int col)
		{
			return N1.8I(row, col);
		}

		protected internal virtual bool IsCellHighlighted(int row, int col)
		{
			if (N1.8I(row, col))
			{
				return false;
			}
			if (!N1.8K(row, col))
			{
				return false;
			}
			if (HighLight == HighLightEnum.Never)
			{
				return false;
			}
			if (HighLight == HighLightEnum.WithFocus && !((Control)this).Focused)
			{
				return false;
			}
			if (N1.8L(row, col))
			{
				if (NA != FocusRectEnum.None && ((Control)this).Focused)
				{
					return false;
				}
				if (Editor != null)
				{
					return false;
				}
			}
			return true;
		}

		internal void 7G(int 09Z)
		{
			if (Rows.Count <= Rows.Fixed)
			{
				return;
			}
			SortColEventArgs e = new SortColEventArgs(09Z, SortFlags.None);
			Column column = Cols[09Z];
			bool flag = (column.Sort & SortFlags.Ascending) == 0;
			e.Order = (flag ? ((e.Order | SortFlags.Ascending) & ~SortFlags.Descending) : ((e.Order | SortFlags.Descending) & ~SortFlags.Ascending));
			OnBeforeSort(e);
			if (e.Cancel || e.Order == SortFlags.None)
			{
				return;
			}
			if (e.Handled)
			{
				N1.8H(e.Order, 09Z);
				return;
			}
			int num = 09Z;
			if (AllowSorting == AllowSortingEnum.MultiColumn)
			{
				num = Cols.Fixed;
				for (int i = Cols.Fixed; i < 09Z; i++)
				{
					if (Cols[i].Sort == SortFlags.None)
					{
						Cols[i].Sort = SortFlags.Ascending;
					}
				}
			}
			column.Sort = e.Order;
			if (N1.9H())
			{
				N1.PO.AF(SortFlags.UseColSort, num, 09Z);
			}
			else
			{
				Sort(SortFlags.UseColSort, num, 09Z);
			}
			ShowCell(Row, -1);
			OnAfterSort(e);
		}

		protected virtual void UpdateViewRange()
		{
			if (N1 == null)
			{
				return;
			}
			CellRange n = new CellRange(N1, -1, -1);
			Rectangle scrollableRectangle = ScrollableRectangle;
			int num = Rows.Fixed + Rows.Frozen;
			if (num < Rows.Count)
			{
				int num2 = Rows[num].Top - base.ScrollPosition.Y;
				n.r1 = Rows.DL(num2);
				n.r2 = Rows.DL(num2 + scrollableRectangle.Height);
				if (n.r2 < 0)
				{
					n.r2 = Rows.Count - 1;
				}
				if (n.r2 < Rows.Fixed)
				{
					n.r1 = (n.r2 = num);
				}
			}
			if (n.r2 < n.r1)
			{
				n.r2 = n.r1;
			}
			int num3 = Cols.Fixed + Cols.Frozen;
			if (num3 < Cols.Count)
			{
				int num4 = Cols[num3].Left - base.ScrollPosition.X;
				n.c1 = Cols.DL(num4);
				n.c2 = Cols.DL(num4 + scrollableRectangle.Width);
				if (n.c2 < 0)
				{
					n.c2 = Cols.Count - 1;
				}
				if (n.c2 < num3)
				{
					n.c1 = (n.c2 = num3);
				}
			}
			if (n.c2 < n.c1)
			{
				n.c2 = n.c1;
			}
			N8 = n;
			if (X0.B9())
			{
				((Control)this).Update();
				X0.B8();
			}
			if (N1.PO.QE != null)
			{
				N1.PO.QE.BoundControlScrolled();
			}
		}

		protected override void OnVisibleChanged(EventArgs e)
		{
			if (((Control)this).Visible)
			{
				SetScrollSize();
			}
			((Control)this).OnVisibleChanged(e);
		}

		protected override void OnSizeChanged(EventArgs e)
		{
			if (Redraw)
			{
				UpdateViewRange();
			}
			base.OnSizeChanged(e);
		}

		protected override void OnPaint(PaintEventArgs e)
		{
			if (Redraw)
			{
				DrawGrid(e);
				base.OnPaint(e);
			}
		}

		protected override void OnPaintBackground(PaintEventArgs e)
		{
			if (!Redraw || DoubleBuffer)
			{
				((Control)this).OnPaintBackground(e);
			}
		}

		internal void 7H(Brush 0A0)
		{
			SolidBrush val = (SolidBrush)(object)((0A0 is SolidBrush) ? 0A0 : null);
			if (val != null && val.Color.A == byte.MaxValue)
			{
				N1.PN.V6.3I(0A0);
			}
		}

		protected virtual void DrawGrid(PaintEventArgs e)
		{
			Graphics graphics = e.Graphics;
			if (Rows.Count == 0 || Cols.Count == 0)
			{
				CellStyle cellStyle = Styles[CellStyleEnum.EmptyArea];
				graphics.FillRectangle(cellStyle.XI, ((Control)this).ClientRectangle);
				return;
			}
			int num = Rows.Fixed + Rows.Frozen;
			for (int i = 0; i < num; i++)
			{
				if (Rows[i].HeightDisplay > 0)
				{
					DrawRow(e, i);
				}
			}
			Rectangle cellRectDisplay;
			if (num > 0 && num < Rows.Count)
			{
				int col = ((RightCol < 0) ? (num - 1) : RightCol);
				cellRectDisplay = GetCellRectDisplay(num - 1, col, clipHorz: false, clipVert: false);
				cellRectDisplay.Width = cellRectDisplay.Right;
				cellRectDisplay.Height = cellRectDisplay.Bottom;
				int x = (cellRectDisplay.Y = 0);
				cellRectDisplay.X = x;
				graphics.ExcludeClip(cellRectDisplay);
			}
			7H((DoubleBuffer && ((Control)this).BackColor == Styles.Normal.BackColor) ? Styles.Normal.XI : null);
			int num3 = Math.Max(num, TopRow);
			int num4 = Math.Min(BottomRow, Rows.Count - 1);
			for (int i = num3; i <= num4; i++)
			{
				if (Rows[i].HeightDisplay > 0)
				{
					DrawRow(e, i);
				}
			}
			7H(null);
			Rectangle clientRectangle = ((Control)this).ClientRectangle;
			cellRectDisplay = GetCellRectDisplay(Rows.Count - 1, Cols.Count - 1, clipHorz: false, clipVert: false);
			if (NL)
			{
				cellRectDisplay.Width = clientRectangle.Width - cellRectDisplay.Left;
			}
			if (cellRectDisplay.Right >= clientRectangle.Right && cellRectDisplay.Bottom >= clientRectangle.Bottom)
			{
				return;
			}
			CellStyle cellStyle2 = Styles[CellStyleEnum.EmptyArea];
			Brush xI = cellStyle2.XI;
			Brush xJ = cellStyle2.XJ;
			if (cellRectDisplay.Right < clientRectangle.Right)
			{
				int num5 = clientRectangle.Right - cellRectDisplay.Right;
				graphics.FillRectangle(xI, cellRectDisplay.Right, 0, num5, clientRectangle.Height);
				if (xJ != null)
				{
					graphics.FillRectangle(xJ, cellRectDisplay.Right, 0, 1, cellRectDisplay.Bottom + 1);
				}
			}
			if (cellRectDisplay.Bottom < clientRectangle.Bottom)
			{
				int num6 = clientRectangle.Bottom - cellRectDisplay.Bottom;
				graphics.FillRectangle(xI, 0, cellRectDisplay.Bottom, clientRectangle.Width, num6);
				if (xJ != null)
				{
					graphics.FillRectangle(xJ, 0, cellRectDisplay.Bottom, cellRectDisplay.Right, 1);
				}
			}
		}

		protected virtual void DrawRow(PaintEventArgs e, int row)
		{
			if (Cols.Count == 0 || Rows[row].HeightDisplay == 0)
			{
				return;
			}
			Rectangle rectangle = N1.88(row, 0);
			int num = Rows.Fixed + Rows.Frozen;
			if (row >= num)
			{
				rectangle.Y += base.ScrollPosition.Y;
			}
			_ = rectangle.Bottom;
			_ = 0;
			int num2 = Cols.Fixed + Cols.Frozen;
			for (int i = 0; i < num2; i++)
			{
				DrawCell(e, row, i);
			}
			if (num2 > 0 && num2 < Cols.Count)
			{
				rectangle = N1.88(row, 0);
				if (row >= num)
				{
					rectangle.Y += base.ScrollPosition.Y;
				}
				rectangle.Width = Cols[num2].Left;
				e.Graphics.ExcludeClip(rectangle);
			}
			if (LeftCol > -1 && RightCol > -1)
			{
				for (int i = LeftCol; i <= RightCol; i++)
				{
					DrawCell(e, row, i);
				}
			}
		}

		protected virtual int DrawCell(PaintEventArgs e, int row, int col)
		{
			Rectangle cellRectDisplay = GetCellRectDisplay(row, col);
			if (cellRectDisplay.Left > ((Control)this).ClientRectangle.Right || cellRectDisplay.Width == 0)
			{
				return col;
			}
			if (!cellRectDisplay.IntersectsWith(e.ClipRectangle))
			{
				return col;
			}
			Image 0AK;
			CheckEnum 0AL;
			string str = 7M(row, col, out 0AK, out 0AL);
			Style styleDisplay = GetStyleDisplay(row, col);
			DrawCell(e.Graphics, row, col, styleDisplay, cellRectDisplay, str, 0AK, 0AL);
			return col;
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		protected internal virtual void DrawCell(Graphics g, int row, int col, Style s, Rectangle rc, string str, Image img, CheckEnum chk)
		{
			//IL_0041: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d2: Unknown result type (might be due to invalid IL or missing references)
			//IL_0098: Unknown result type (might be due to invalid IL or missing references)
			//IL_02e9: Unknown result type (might be due to invalid IL or missing references)
			//IL_02f0: Expected O, but got Unknown
			bool flag = IsCellCursor(row, col);
			if (7L(row, col) && 7K(row, col))
			{
				0I 0I2 = X0.BB(row, col);
				ButtonState bs = (ButtonState)(NN ? 16384 : 0);
				switch (0I2)
				{
				case 0I.QY:
				case 0I.R2:
				{
					if (flag && Editor != null)
					{
						str = null;
						img = null;
						break;
					}
					Rectangle rectangle = X0.BC(rc);
					if (rectangle.Width > 0)
					{
						DrawComboButton(g, rectangle, bs);
					}
					rc.Width -= rectangle.Width - 1;
					break;
				}
				case 0I.QZ:
				case 0I.R0:
				{
					Rectangle rectangle = X0.BC(rc);
					if (rectangle.Width > 0)
					{
						DrawButton(g, rectangle, bs);
						if (CellButtonImage != null)
						{
							0D.PF.55(g, rectangle, CellButtonImage);
						}
						else
						{
							0D.PF.54(g, rectangle, "...");
						}
					}
					rc.Width -= rectangle.Width - 1;
					break;
				}
				}
			}
			Image val = 7Q(chk);
			if (val != null)
			{
				img = val;
				if (N1.8R(row, col))
				{
					str = null;
				}
			}
			DrawCellBody(g, row, col, s, rc, str, img);
			if (Rows.Frozen > 0 && row == Rows.Fixed + Rows.Frozen - 1)
			{
				g.FillRectangle(SystemBrushes.ControlDark, rc.X, rc.Bottom - 1, rc.Width + 1, 1);
			}
			if (Cols.Frozen > 0 && col == Cols.Fixed + Cols.Frozen - 1)
			{
				g.FillRectangle(SystemBrushes.ControlDark, rc.Right - 1, rc.Y, 1, rc.Height);
			}
			if (!flag || NA == FocusRectEnum.None || !((Control)this).Focused || IsCellFixed(row, col))
			{
				return;
			}
			rc = s.5D(rc);
			int num = N1.PM.FE(row, col);
			if (num > 0 && rc.Width > 12)
			{
				rc = s.5F(rc, img);
				rc.X += num;
				rc.Width -= num;
			}
			switch (NA)
			{
			case FocusRectEnum.Light:
				ControlPaint.DrawFocusRectangle(g, rc);
				break;
			case FocusRectEnum.Heavy:
				ControlPaint.DrawFocusRectangle(g, rc);
				rc.Inflate(-1, -1);
				ControlPaint.DrawFocusRectangle(g, rc);
				break;
			case FocusRectEnum.Solid:
			{
				rc.Width--;
				rc.Height--;
				Pen val2 = new Pen(Styles.Highlight.BackColor);
				try
				{
					g.DrawRectangle(val2, rc);
					break;
				}
				finally
				{
					((IDisposable)val2)?.Dispose();
				}
			}
			case FocusRectEnum.Inset:
				07.61(g, rc, (Border3DStyle)8);
				break;
			case FocusRectEnum.Raised:
				07.61(g, rc, (Border3DStyle)1);
				break;
			}
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		protected internal virtual void DrawCellBody(Graphics g, int row, int col, Style s, Rectangle rc, string str, Image img)
		{
			if (NF == DrawModeEnum.OwnerDraw)
			{
				CellStyle s2 = new CellStyle(s);
				OwnerDrawCellEventArgs e = new OwnerDrawCellEventArgs(this, g, row, col, s2, rc, str, img);
				NO = true;
				OnOwnerDrawCell(this, e);
				NO = false;
				if (e.Handled)
				{
					return;
				}
				if (e.RQ)
				{
					e.DrawCell();
					return;
				}
			}
			7I(g, row, col, s, rc, str, img, DrawCellFlags.All);
		}

		internal void 7I(Graphics 0A1, int 0A2, int 0A3, Style 0A4, Rectangle 0A5, string 0A6, Image 0A7, DrawCellFlags 0A8)
		{
			//IL_0080: Unknown result type (might be due to invalid IL or missing references)
			//IL_0087: Expected O, but got Unknown
			//IL_0172: Unknown result type (might be due to invalid IL or missing references)
			//IL_0179: Expected O, but got Unknown
			int num = N1.PM.FD(0A3);
			if (0A2 == 0 && Rows.Fixed > 0 && num > 0 && N1.PM.F6(TreeStyleFlags.ButtonBar))
			{
				N1.PM.FF(0A1, 0A4, 0A5, 0A6, 0A7);
				return;
			}
			Image 0AC = null;
			bool 0AD = false;
			if (7J(0A2, 0A3, 0A5, ref 0AC, ref 0AD))
			{
				int num2 = 0AC.Width + 4;
				Margins val = (Margins)0A4.4V("Padding");
				if (0AD)
				{
					val.Right += num2;
				}
				else
				{
					val.Left += num2;
				}
				0A4.52(0A1, 0A5, 0A6, 0A7, (02)0A8);
				if (0AD)
				{
					val.Right -= num2;
				}
				else
				{
					val.Left -= num2;
				}
				if (0AD)
				{
					0A5.X = 0A5.Right - num2;
				}
				else
				{
					0A5.Width = num2;
				}
				0A5.Width = num2;
				0D.PF.55(0A1, 0A5, 0AC);
				return;
			}
			if (num > 0 && 0A5.Width > 12)
			{
				Node node = Rows[0A2].Node;
				if (node != null && node.Level >= 0)
				{
					int num3 = (node.Level + 1) * N1.PM.Indent;
					Margins val2 = (Margins)0A4.4V("Padding");
					val2.Left += num3;
					0A4.52(0A1, 0A5, 0A6, 0A7, (02)0A8);
					val2.Left -= num3;
					N1.PM.FG(this, 0A1, 0A5, node, 0A2);
					return;
				}
			}
			0A4.52(0A1, 0A5, 0A6, 0A7, (02)0A8);
		}

		internal bool 7J(int 0A9, int 0AA, Rectangle 0AB, ref Image 0AC, ref bool 0AD)
		{
			if (NI && N1.9H() && N1.PO.AP(0A9, 0AA) != null)
			{
				0AC = N1.8A(GlyphEnum.ErrorInfo);
				return true;
			}
			if (NJ && Cols[0AA] == N1.PS && Rows.Fixed > 0 && 0AB.Width > 12 && 0AB.Height > 10)
			{
				int num = (Rows[0].AllowMerging ? (Rows.Fixed - 1) : 0);
				if (0A9 == num)
				{
					SortFlags sort = N1.PS.Sort;
					if ((sort & (SortFlags.Ascending | SortFlags.Descending)) == 0)
					{
						return false;
					}
					0AC = N1.8A(((sort & SortFlags.Ascending) == 0) ? GlyphEnum.Descending : GlyphEnum.Ascending);
					0AD = true;
					return true;
				}
			}
			if (0AA == 0 && Cols.Fixed > 0 && 0AB.Width > 12 && 0AB.Height > 10)
			{
				if ((Rows[0A9].TV & 0R.TR) != 0R.TH)
				{
					0AC = N1.8A(GlyphEnum.DBAdd);
					return true;
				}
				if (NH && 0A9 == Row)
				{
					0AC = N1.8A(GlyphEnum.DBCursor);
					return true;
				}
			}
			return false;
		}

		internal bool 7K(int 0AE, int 0AF)
		{
			if (!AllowEditing || !Cols[0AF].AllowEditing || !Rows[0AE].AllowEditing)
			{
				return false;
			}
			if (N1.8I(0AE, 0AF) || ((Component)(object)this).DesignMode)
			{
				return false;
			}
			if (OL == null)
			{
				return true;
			}
			RowColEventArgs e = new RowColEventArgs(0AE, 0AF);
			OL(this, e);
			return !e.Cancel;
		}

		internal bool 7L(int 0AG, int 0AH)
		{
			bool flag = IsCellCursor(0AG, 0AH);
			bool flag2 = Editor is TextBox;
			if (flag && Editor != null && !flag2)
			{
				return false;
			}
			switch (NG)
			{
			case ShowButtonsEnum.Always:
				return true;
			case ShowButtonsEnum.WithFocus:
				return flag;
			case ShowButtonsEnum.WhenEditing:
				if (flag)
				{
					return flag2;
				}
				return false;
			default:
				return false;
			}
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		protected internal virtual Style GetStyleDisplay(int row, int col)
		{
			Style styleDisplay = N1.GetStyleDisplay(row, col);
			if (N3.BO() && IsCellCursor(row, col))
			{
				return N1.8M(CellStyleEnum.Search).4O(styleDisplay, 04C: false);
			}
			if (IsCellHighlighted(row, col))
			{
				return N1.8M(CellStyleEnum.Highlight).4O(styleDisplay, 04C: false);
			}
			if (IsCellCursor(row, col) && ((Control)this).Focused)
			{
				return N1.8M(CellStyleEnum.Focus).4O(styleDisplay, 04C: false);
			}
			return styleDisplay;
		}

		internal string 7M(int 0AI, int 0AJ, out Image 0AK, out CheckEnum 0AL)
		{
			return N1.8W(0AI, 0AJ, out 0AK, out 0AL);
		}

		internal bool 7N(int 0AM, int 0AN, object 0AO, bool 0AP)
		{
			bool flag = N1.SetData(0AM, 0AN, 0AO, 0AP);
			if (!flag)
			{
				string message = string.Format(CultureInfo.CurrentCulture, "Cannot assign value '{0}' to column {1}.", new object[2] { 0AO, 0AN });
				Exception 11 = new ArgumentException(message);
				72(0AM, 0AN, 11, 098: true);
			}
			return flag;
		}

		public virtual CheckEnum GetCellCheck(int row, int col)
		{
			return N1.GetCellCheck(row, col);
		}

		public virtual void SetCellCheck(int row, int col, CheckEnum check)
		{
			N1.SetCellCheck(row, col, check);
		}

		protected internal virtual void ToggleCellCheck(int row, int col)
		{
			CheckEnum checkEnum = 7P(row, col);
			if (checkEnum != CheckEnum.None)
			{
				SetCellCheck(row, col, checkEnum);
			}
		}

		internal CheckEnum 7O(CheckEnum 0AQ)
		{
			return 0AQ switch
			{
				CheckEnum.Checked => CheckEnum.Unchecked, 
				CheckEnum.Unchecked => CheckEnum.Checked, 
				CheckEnum.TSChecked => CheckEnum.TSUnchecked, 
				CheckEnum.TSUnchecked => CheckEnum.TSGrayed, 
				CheckEnum.TSGrayed => CheckEnum.TSChecked, 
				_ => CheckEnum.None, 
			};
		}

		internal CheckEnum 7P(int 0AR, int 0AS)
		{
			return 7O(GetCellCheck(0AR, 0AS));
		}

		internal Image 7Q(CheckEnum 0AT)
		{
			return (Image)(0AT switch
			{
				CheckEnum.Checked => N1.8A(GlyphEnum.Checked), 
				CheckEnum.Unchecked => N1.8A(GlyphEnum.Unchecked), 
				CheckEnum.TSChecked => N1.8A(GlyphEnum.Checked), 
				CheckEnum.TSUnchecked => N1.8A(GlyphEnum.Unchecked), 
				CheckEnum.TSGrayed => N1.8A(GlyphEnum.Grayed), 
				_ => null, 
			});
		}

		protected internal virtual void SetCellCheckEdit(int row, int col, CheckEnum check)
		{
			SetCellCheck(row, col, check);
		}

		internal Rectangle 7R(int 0AU, int 0AV, Style 0AW, Rectangle 0AX)
		{
			int num = N1.PM.FE(0AU, 0AV);
			if (num > 0 && 0AX.Width > 12)
			{
				0AX.X += num;
				0AX.Width -= num;
			}
			Image 0AC = null;
			bool 0AD = false;
			if (7J(0AU, 0AV, 0AX, ref 0AC, ref 0AD))
			{
				num = 0AC.Width + 4;
				if (0AD)
				{
					0AX.Width -= num;
				}
				else
				{
					0AX.X += num;
					0AX.Width -= num;
				}
			}
			Image 05P = N1.8A(GlyphEnum.Checked);
			return 0AW.5E(0AX, 05P);
		}

		public virtual void AutoSizeCols(int row1, int col1, int row2, int col2, int extraSpace, AutoSizeFlags flags)
		{
			bool redraw = Redraw;
			if (col1 != col2)
			{
				Redraw = false;
			}
			try
			{
				Graphics val = ((Control)this).CreateGraphics();
				try
				{
					AutoSizeCols(val, row1, col1, row2, col2, extraSpace, flags);
				}
				finally
				{
					((IDisposable)val)?.Dispose();
				}
			}
			finally
			{
				Redraw = redraw;
			}
		}

		public virtual void AutoSizeCols()
		{
			AutoSizeCols(4);
		}

		public virtual void AutoSizeCols(int col1, int col2, int extraSpace)
		{
			AutoSizeCols(0, col1, Rows.Count - 1, col2, extraSpace, AutoSizeFlags.IgnoreHidden);
		}

		public virtual void AutoSizeCols(int extraSpace)
		{
			AutoSizeCols(0, 0, Rows.Count - 1, Cols.Count - 1, extraSpace, AutoSizeFlags.IgnoreHidden);
		}

		public virtual void AutoSizeCol(int col)
		{
			AutoSizeCol(col, 4);
		}

		public virtual void AutoSizeCol(int col, int extraSpace)
		{
			AutoSizeCols(0, col, Rows.Count - 1, col, extraSpace, AutoSizeFlags.IgnoreHidden);
		}

		public virtual void AutoSizeRows(int row1, int col1, int row2, int col2, int extra, AutoSizeFlags flags)
		{
			Graphics val = ((Control)this).CreateGraphics();
			try
			{
				AutoSizeRows(val, row1, col1, row2, col2, extra, flags);
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}

		public virtual void AutoSizeRows()
		{
			AutoSizeRows(0, 0, Rows.Count - 1, Cols.Count - 1, 0, AutoSizeFlags.IgnoreHidden);
		}

		public virtual void AutoSizeRow(int row)
		{
			AutoSizeRows(row, 0, row, Cols.Count - 1, 0, AutoSizeFlags.IgnoreHidden);
		}

		protected internal virtual void AutoSizeCols(Graphics g, int row1, int col1, int row2, int col2, int extra, AutoSizeFlags flags)
		{
			if (row2 > Rows.Count - 1)
			{
				row2 = Rows.Count - 1;
			}
			if (col2 > Cols.Count - 1)
			{
				col2 = Cols.Count - 1;
			}
			bool flag = (flags & AutoSizeFlags.IgnoreHidden) != 0;
			bool flag2 = (flags & AutoSizeFlags.SameSize) != 0;
			int num = -1;
			for (int i = col1; i <= col2; i++)
			{
				if (flag && Cols[i].WidthDisplay == 0)
				{
					continue;
				}
				int num2 = N1.PM.FD(i);
				for (int j = row1; j <= row2; j++)
				{
					if (flag && Rows[j].HeightDisplay == 0)
					{
						continue;
					}
					Image 0AK;
					CheckEnum 0AL;
					string text = 7M(j, i, out 0AK, out 0AL);
					if (0AK != null || text.Length != 0)
					{
						Style styleDisplay = GetStyleDisplay(j, i);
						int num3 = styleDisplay.57(g, text, 0AK) + num2;
						if (num3 > num)
						{
							num = num3;
						}
					}
				}
				if (!flag2 && num > -1)
				{
					Cols[i].Width = num + extra;
					num = -1;
				}
			}
			if (flag2 && num > -1)
			{
				for (int i = col1; i <= col2; i++)
				{
					Cols[i].Width = num + extra;
				}
			}
		}

		protected internal virtual void AutoSizeRows(Graphics g, int row1, int col1, int row2, int col2, int extra, AutoSizeFlags flags)
		{
			if (row2 > Rows.Count - 1)
			{
				row2 = Rows.Count - 1;
			}
			if (col2 > Cols.Count - 1)
			{
				col2 = Cols.Count - 1;
			}
			bool flag = (flags & AutoSizeFlags.IgnoreHidden) != 0;
			bool flag2 = (flags & AutoSizeFlags.SameSize) != 0;
			int num = -1;
			for (int i = row1; i <= row2; i++)
			{
				for (int j = col1; j <= col2; j++)
				{
					if (flag && Cols[j].WidthDisplay == 0)
					{
						continue;
					}
					Image 0AK;
					CheckEnum 0AL;
					string text = 7M(i, j, out 0AK, out 0AL);
					if (0AK != null || (text != null && text.Length != 0))
					{
						int num2 = N1.PM.FD(j);
						int 05E = Cols[j].WidthDisplay - num2;
						Style styleDisplay = GetStyleDisplay(i, j);
						int num3 = styleDisplay.5A(g, 05E, text, 0AK);
						if (num3 > num)
						{
							num = num3;
						}
					}
				}
				if (!flag2 && num > -1)
				{
					int num4 = num + extra;
					if (num4 <= Rows.DefaultSize)
					{
						num4 = -1;
					}
					Rows[i].Height = num4;
					num = -1;
				}
			}
			if (flag2 && num > -1)
			{
				int num5 = num + extra;
				if (num5 <= Rows.DefaultSize)
				{
					num5 = -1;
				}
				for (int i = row1; i <= row2; i++)
				{
					Rows[i].Height = num5;
				}
			}
		}

		protected override void OnHandleDestroyed(EventArgs e)
		{
			FinishEditing();
		}

		protected override void OnGotFocus(EventArgs e)
		{
			if (HighLight == HighLightEnum.WithFocus)
			{
				((Control)this).Invalidate();
			}
			else
			{
				79(WZ.EK());
			}
			((Control)this).OnGotFocus(e);
		}

		protected override void OnLostFocus(EventArgs e)
		{
			if (((Control)this).Capture)
			{
				((Control)this).Capture = false;
			}
			N2.C9();
			if (Editor == null || !Editor.Focused)
			{
				if (HighLight == HighLightEnum.WithFocus)
				{
					((Control)this).Invalidate();
				}
				else
				{
					79(WZ.EK());
				}
				if (N1.9H())
				{
					N1.PO.AB();
				}
				((Control)this).OnLostFocus(e);
			}
		}

		protected override void OnImeStartComposition()
		{
			if (Editor == null)
			{
				N3.BM('\r');
			}
		}

		protected override bool IsInputKey(Keys keyData)
		{
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_0011: Unknown result type (might be due to invalid IL or missing references)
			if (N3.BJ(keyData))
			{
				return true;
			}
			return ((Control)this).IsInputKey(keyData);
		}

		protected override bool IsInputChar(char charCode)
		{
			return true;
		}

		protected override void OnKeyDown(KeyEventArgs e)
		{
			N2.CA();
			((Control)this).OnKeyDown(e);
			if (!e.Handled)
			{
				N3.BK(e);
			}
		}

		protected override void OnKeyPress(KeyPressEventArgs e)
		{
			if (Editor == null)
			{
				((Control)this).OnKeyPress(e);
				if (e.Handled)
				{
					return;
				}
			}
			N3.BL(e);
		}

		protected override void OnValidating(CancelEventArgs e)
		{
			e.Cancel = Editor != null && N4.R7;
			((Control)this).OnValidating(e);
		}

		protected override void OnMouseMove(MouseEventArgs e)
		{
			N2.BU(e);
			((Control)this).OnMouseMove(e);
		}

		protected override void OnMouseDown(MouseEventArgs e)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_0023: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0046: Unknown result type (might be due to invalid IL or missing references)
			P9 = Control.MouseButtons;
			BeforeMouseDownEventArgs e2 = new BeforeMouseDownEventArgs(e);
			OnBeforeMouseDown(e2);
			if (e2.Cancel)
			{
				P9 = (MouseButtons)0;
			}
			else if (FinishEditing())
			{
				if (e.Clicks == 1 && (e.Button & 0x100000) != 0 && !((Control)this).Focused)
				{
					((Control)this).Focus();
				}
				N2.BV(e);
				((Control)this).OnMouseDown(e);
			}
		}

		protected override void OnMouseUp(MouseEventArgs e)
		{
			N2.C5(e);
			((Control)this).OnMouseUp(e);
		}

		protected override void OnDoubleClick(EventArgs e)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Invalid comparison between Unknown and I4
			//IL_001a: Unknown result type (might be due to invalid IL or missing references)
			//IL_002f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0035: Expected O, but got Unknown
			if ((int)P9 == 1048576)
			{
				Point point = ((Control)this).PointToClient(Control.MousePosition);
				MouseEventArgs 0IR = new MouseEventArgs(P9, 1, point.X, point.Y, 0);
				N2.C8(0IR);
			}
			((Control)this).OnDoubleClick(e);
		}

		protected override void OnScroll(ScrollBars sb)
		{
			CellRange n = N8;
			UpdateViewRange();
			CellRange n2 = N8;
			if (!PA)
			{
				RangeEventArgs e = new RangeEventArgs(n, n2);
				OnBeforeScroll(e);
				if (e.Cancel)
				{
					PA = true;
					TopRow = n.r1;
					LeftCol = n.c1;
					PA = false;
				}
				else
				{
					OnAfterScroll(e);
				}
			}
		}

		protected override void OnScrollTip(int newValue)
		{
			if (Rows.Count <= Rows.Fixed)
			{
				return;
			}
			int num = Rows.Fixed + Rows.Frozen;
			if (num < Rows.Count)
			{
				int 0KQ = (Rows[num].Top + Rows[num].Bottom) / 2 + newValue;
				for (num = Rows.DL(0KQ); num < Rows.Count - 1 && Rows[num].HeightDisplay == 0; num++)
				{
				}
				OnBeforeScrollTip(new RowColEventArgs(num, LeftCol));
			}
		}

		protected override void OnDragEnter(DragEventArgs e)
		{
			N5.AU(e);
			((Control)this).OnDragEnter(e);
		}

		protected override void OnDragOver(DragEventArgs e)
		{
			N5.AV(e);
			((Control)this).OnDragOver(e);
		}

		protected override void OnDragDrop(DragEventArgs e)
		{
			((Control)this).OnDragDrop(e);
			N5.AW(e);
		}

		protected override void OnBackColorChanged(EventArgs e)
		{
			((Control)this).OnBackColorChanged(e);
			if (N1 != null)
			{
				CellStyle normal = Styles.Normal;
				if (normal.BackColor != ((Control)this).BackColor)
				{
					normal.BackColor = ((Control)this).BackColor;
				}
			}
		}

		protected override void OnForeColorChanged(EventArgs e)
		{
			((Control)this).OnForeColorChanged(e);
			if (N1 != null)
			{
				CellStyle normal = Styles.Normal;
				if (normal.ForeColor != ((Control)this).ForeColor)
				{
					normal.ForeColor = ((Control)this).ForeColor;
				}
			}
		}

		protected override void OnFontChanged(EventArgs e)
		{
			((Control)this).OnFontChanged(e);
			7S();
		}

		private void 7S()
		{
			if (N1 != null)
			{
				CellStyle normal = Styles.Normal;
				normal.Font = ((Control)this).Font;
				int num = normal.Margins.Top + normal.Margins.Bottom;
				int num2 = ((Control)this).Font.Height + num + 2;
				if (Rows.DefaultSize != num2)
				{
					Rows.DefaultSize = num2;
					Cols.DefaultSize = 5 * Rows.DefaultSize;
					SetScrollSize();
				}
			}
		}
	}
	[LicenseProvider(typeof(LicenseProvider))]
	[ToolboxBitmap(typeof(C1FlexGrid))]
	[ComVisible(true)]
	[Designer(typeof(GridDesigner))]
	public class C1FlexGrid : C1FlexGridBase
	{
		private AllowMergingEnum PB;

		private Assembly PC = Assembly.GetCallingAssembly();

		[Category("Behavior")]
		[DefaultValue(AllowMergingEnum.None)]
		[D("AllowMerging", "Determines whether cells with the same contents should be visually merged.")]
		[Browsable(true)]
		public AllowMergingEnum AllowMerging
		{
			get
			{
				return PB;
			}
			set
			{
				if (PB != value)
				{
					PB = value;
					base.WU = value == AllowMergingEnum.None;
					((Control)this).Invalidate();
				}
			}
		}

		public C1FlexGrid()
		{
			PB = AllowMergingEnum.None;
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		public override Assembly GetCallingAssembly()
		{
			return PC;
		}

		[D("GetMergedRange", "Returns the merged range that contains a given cell.")]
		public virtual CellRange GetMergedRange(int row, int col, bool clip)
		{
			CellRange cellRange = new CellRange(N1, row, col);
			if (!cellRange.IsValid || (!7V(col) && !7W(row)))
			{
				return cellRange;
			}
			if (AllowMerging == AllowMergingEnum.Spill)
			{
				return GetSpillRange(cellRange, measure: true);
			}
			if (AllowMerging == AllowMergingEnum.Nodes)
			{
				return GetSpillRange(cellRange, measure: false);
			}
			if (AllowMerging == AllowMergingEnum.FixedOnly && !N1.8I(row, col))
			{
				return cellRange;
			}
			return GetDefaultMergedRange(cellRange, clip, vert: true, horz: true);
		}

		public CellRange GetMergedRange(int row, int col)
		{
			return GetMergedRange(row, col, clip: false);
		}

		protected CellRange GetDefaultMergedRange(CellRange rg, bool clip, bool vert, bool horz)
		{
			int r = rg.r1;
			int c = rg.c1;
			object data = GetData(r, c);
			if (82(data))
			{
				return rg;
			}
			RowCollection rows = base.Rows;
			if (7V(c) && !rows[rg.r1].IsNode && vert)
			{
				int num = rows.Fixed;
				int num2 = num + rows.Frozen;
				if (r < num)
				{
					rg = 7T(rg, 0, num - 1, data);
				}
				else if (r < num2)
				{
					rg = 7T(rg, num, num2 - 1, data);
				}
				else
				{
					int num3 = num2;
					int num4 = base.Rows.Count - 1;
					if (clip)
					{
						if (num3 < base.TopRow)
						{
							num3 = base.TopRow;
						}
						if (num4 > base.BottomRow)
						{
							num4 = base.BottomRow;
						}
						if (num3 > num4)
						{
							return rg;
						}
					}
					rg = 7T(rg, num3, num4, data);
				}
				if (rg.r2 > rg.r1 && c > base.Cols.Fixed && 80())
				{
					CellRange rg2 = new CellRange(N1, r, c - 1);
					rg2 = GetDefaultMergedRange(rg2, clip, vert: true, horz: false);
					if (rg.r1 < rg2.r1)
					{
						rg.r1 = rg2.r1;
					}
					if (rg.r2 > rg2.r2)
					{
						rg.r2 = rg2.r2;
					}
				}
			}
			if (rg.r1 == rg.r2 && 7W(r) && horz)
			{
				int num5 = base.Cols.Fixed;
				int num6 = num5 + base.Cols.Frozen;
				if (c < num5)
				{
					rg = 7U(rg, 0, num5 - 1, data);
				}
				else if (c < num6)
				{
					rg = 7U(rg, num5, num6 - 1, data);
				}
				else
				{
					int num7 = num6;
					int num8 = base.Cols.Count - 1;
					if (clip)
					{
						if (num7 < base.LeftCol)
						{
							num7 = base.LeftCol;
						}
						if (num8 > base.RightCol)
						{
							num8 = base.RightCol;
						}
						if (num7 > num8)
						{
							return rg;
						}
					}
					rg = 7U(rg, num7, num8, data);
				}
				if (rg.c2 > rg.c1 && r > base.Rows.Fixed && 7Z())
				{
					CellRange mergedRange = GetMergedRange(r - 1, c, clip);
					if (rg.c1 < mergedRange.c1)
					{
						rg.c1 = mergedRange.c1;
					}
					if (rg.c2 > mergedRange.c2)
					{
						rg.c2 = mergedRange.c2;
					}
				}
			}
			return rg;
		}

		private CellRange 7T(CellRange 0AY, int 0AZ, int 0B0, object 0B1)
		{
			while (0AY.r1 > 0AZ && !base.Rows[0AY.r1 - 1].IsNode && 7X(0AY.r1 - 1, 0AY.c1, 0B1))
			{
				0AY.r1--;
			}
			while (0AY.r2 < 0B0 && !base.Rows[0AY.r2 + 1].IsNode && 7X(0AY.r2 + 1, 0AY.c1, 0B1))
			{
				0AY.r2++;
			}
			return 0AY;
		}

		private CellRange 7U(CellRange 0B2, int 0B3, int 0B4, object 0B5)
		{
			while (0B2.c1 > 0B3 && 7X(0B2.r1, 0B2.c1 - 1, 0B5))
			{
				CellRange cellRange = GetCellRange(0B2.r1, 0B2.c1 - 1);
				cellRange = GetDefaultMergedRange(cellRange, clip: true, vert: true, horz: false);
				if (cellRange.r1 != cellRange.r2)
				{
					break;
				}
				0B2.c1--;
			}
			while (0B2.c2 < 0B4 && 7X(0B2.r1, 0B2.c2 + 1, 0B5))
			{
				CellRange cellRange2 = GetCellRange(0B2.r1, 0B2.c2 + 1);
				cellRange2 = GetDefaultMergedRange(cellRange2, clip: true, vert: true, horz: false);
				if (cellRange2.r1 != cellRange2.r2)
				{
					break;
				}
				0B2.c2++;
			}
			return 0B2;
		}

		protected CellRange GetSpillRange(CellRange rg, bool measure)
		{
			int r = rg.r1;
			int c = rg.c1;
			object data = GetData(r, c);
			ColumnCollection cols = base.Cols;
			if (82(data))
			{
				if (c == 0 || c == cols.Fixed)
				{
					return rg;
				}
				CellRange cellRange = GetCellRange(rg.r1, rg.c1 - 1);
				cellRange = GetSpillRange(cellRange, measure);
				if (!cellRange.ContainsCol(c))
				{
					return rg;
				}
				return cellRange;
			}
			if (!cols[c].Visible)
			{
				return rg;
			}
			Style styleDisplay = N1.GetStyleDisplay(r, c);
			switch ((V)styleDisplay.4V("AlignHorz"))
			{
			case V.JS:
				return rg;
			case V.JP:
				if (data.GetType().IsAssignableFrom(typeof(int)))
				{
					return rg;
				}
				break;
			}
			int num = ((c < cols.Fixed) ? (cols.Fixed - 1) : (cols.Count - 1));
			if (num <= c)
			{
				return rg;
			}
			object data2 = GetData(r, c + 1);
			if (!82(data2))
			{
				return rg;
			}
			int num2 = int.MaxValue;
			if (measure)
			{
				Graphics val = ((Control)this).CreateGraphics();
				try
				{
					string dataDisplay = GetDataDisplay(r, c);
					num2 = styleDisplay.57(val, dataDisplay, null);
				}
				finally
				{
					((IDisposable)val)?.Dispose();
				}
			}
			for (int i = cols[c].WidthDisplay; i < num2; i += cols[rg.c2].WidthDisplay)
			{
				if (rg.c2 >= num)
				{
					break;
				}
				data2 = GetData(r, rg.c2 + 1);
				if (!82(data2))
				{
					return rg;
				}
				rg.c2++;
			}
			return rg;
		}

		protected internal override bool SetDataEdit(int row, int col, object data, bool coerce)
		{
			if (!7Y(row, col))
			{
				return base.SetDataEdit(row, col, data, coerce);
			}
			CellRange mergedRange = GetMergedRange(row, col, clip: false);
			switch (PB)
			{
			case AllowMergingEnum.Spill:
			case AllowMergingEnum.Nodes:
				mergedRange.c2 = mergedRange.c1;
				break;
			}
			return base.SetData(mergedRange, data, coerce);
		}

		protected internal override void SetCellCheckEdit(int row, int col, CheckEnum check)
		{
			if (!7Y(row, col))
			{
				base.SetCellCheckEdit(row, col, check);
				return;
			}
			if (N1.8R(row, col))
			{
				bool flag = check == CheckEnum.Checked || check == CheckEnum.TSChecked;
				SetDataEdit(row, col, flag, coerce: true);
				return;
			}
			CellRange mergedRange = GetMergedRange(row, col, clip: false);
			switch (PB)
			{
			case AllowMergingEnum.Spill:
			case AllowMergingEnum.Nodes:
				mergedRange.c2 = mergedRange.c1;
				break;
			}
			for (row = mergedRange.r1; row <= mergedRange.r2; row++)
			{
				for (col = mergedRange.c1; col <= mergedRange.c2; col++)
				{
					N1.SetCellCheck(row, col, check);
				}
			}
		}

		public override void Invalidate(CellRange rg)
		{
			if (PB == AllowMergingEnum.None || rg.c1 < 0 || rg.r1 < 0)
			{
				base.Invalidate(rg);
				return;
			}
			rg.Normalize();
			bool flag = false;
			for (int i = rg.r1; i <= rg.r2; i++)
			{
				if (flag)
				{
					break;
				}
				if (!GetMergedRange(i, rg.c1, clip: true).IsSingleCell)
				{
					flag = true;
				}
				if (rg.c1 != rg.c2 && !flag && !GetMergedRange(i, rg.c2, clip: true).IsSingleCell)
				{
					flag = true;
				}
			}
			for (int j = rg.c1 + 1; j <= rg.c2 - 1; j++)
			{
				if (flag)
				{
					break;
				}
				if (!GetMergedRange(rg.r1, j, clip: true).IsSingleCell)
				{
					flag = true;
				}
				if (rg.r1 != rg.r2 && !flag && !GetMergedRange(rg.r2, j, clip: true).IsSingleCell)
				{
					flag = true;
				}
			}
			if (flag)
			{
				((Control)this).Invalidate();
			}
			else
			{
				base.Invalidate(rg);
			}
		}

		protected internal override Rectangle GetCellRectDisplay(int row, int col, bool clipHorz, bool clipVert)
		{
			if (row < 0 || col < 0)
			{
				return base.GetCellRectDisplay(row, col, clipHorz, clipVert);
			}
			if (!7Y(row, col))
			{
				return base.GetCellRectDisplay(row, col, clipHorz, clipVert);
			}
			CellRange mergedRange = GetMergedRange(row, col, clip: true);
			if (mergedRange.IsSingleCell)
			{
				return base.GetCellRectDisplay(row, col, clipHorz, clipVert);
			}
			Rectangle cellRectDisplay = base.GetCellRectDisplay(mergedRange.r1, mergedRange.c1, clipHorz: false, clipVert: false);
			Rectangle cellRectDisplay2 = base.GetCellRectDisplay(mergedRange.r2, mergedRange.c2, clipHorz: false, clipVert: false);
			return Rectangle.Union(cellRectDisplay, cellRectDisplay2);
		}

		protected internal override Rectangle GetCellRectEditor(int row, int col)
		{
			if (7Y(row, col))
			{
				CellRange mergedRange = GetMergedRange(row, col, clip: true);
				row = mergedRange.r1;
				col = mergedRange.c1;
			}
			return base.GetCellRectEditor(row, col);
		}

		protected internal override bool StartEditing(int row, int col, char key, bool force)
		{
			if (7Y(row, col))
			{
				CellRange mergedRange = GetMergedRange(row, col, clip: false);
				row = mergedRange.r1;
				col = mergedRange.c1;
			}
			return base.StartEditing(row, col, key, force);
		}

		protected internal override bool StartEditing(int row, int col, Point ptMouse, bool dblClick)
		{
			if (7Y(row, col))
			{
				CellRange mergedRange = GetMergedRange(row, col, clip: false);
				row = mergedRange.r1;
				col = mergedRange.c1;
			}
			return base.StartEditing(row, col, ptMouse, dblClick);
		}

		protected internal override bool IsCellCursor(int row, int col)
		{
			if (!7Y(row, col))
			{
				return base.IsCellCursor(row, col);
			}
			81(row, col, out var _, out var 0BG);
			return 0BG;
		}

		protected internal override int CheckNodeChildren(int row, int col, int level)
		{
			if (!7Y(row, col))
			{
				return base.CheckNodeChildren(row, col, level);
			}
			CellRange mergedRange = GetMergedRange(row, col, clip: false);
			row = ((base.SubtotalPosition == SubtotalPositionEnum.AboveData) ? mergedRange.r2 : mergedRange.r1);
			return base.CheckNodeChildren(mergedRange.r2, col, level);
		}

		protected internal override bool IsCellHighlighted(int row, int col)
		{
			if (((Component)(object)this).DesignMode)
			{
				return false;
			}
			if (!7Y(row, col))
			{
				return base.IsCellHighlighted(row, col);
			}
			if (base.HighLight == HighLightEnum.Never)
			{
				return false;
			}
			if (base.HighLight == HighLightEnum.WithFocus && !((Control)this).Focused)
			{
				return false;
			}
			if (N1.8I(row, col))
			{
				return false;
			}
			81(row, col, out var 0BF, out var 0BG);
			if (0BG)
			{
				if (base.FocusRect != FocusRectEnum.None && ((Control)this).Focused)
				{
					return false;
				}
				if (base.Editor != null)
				{
					return false;
				}
			}
			return 0BF;
		}

		protected override void DrawRow(PaintEventArgs e, int row)
		{
			if (base.Cols.Count == 0 || base.Rows[row].HeightDisplay == 0)
			{
				return;
			}
			if (!7W(row))
			{
				base.DrawRow(e, row);
				return;
			}
			Rectangle rectangle = N1.88(row, 0);
			int num = base.Rows.Fixed + base.Rows.Frozen;
			if (row >= num)
			{
				rectangle.Y += base.ScrollPosition.Y;
			}
			_ = rectangle.Bottom;
			_ = 0;
			int num2 = base.Cols.Fixed + base.Cols.Frozen;
			int num3;
			for (num3 = 0; num3 < num2; num3++)
			{
				num3 = DrawCell(e, row, num3);
			}
			if (num2 > 0 && num2 < base.Cols.Count)
			{
				rectangle = N1.88(row, 0);
				if (row >= num)
				{
					rectangle.Y += base.ScrollPosition.Y;
				}
				rectangle.Width = base.Cols[num2].Left;
				e.Graphics.ExcludeClip(rectangle);
			}
			if (base.LeftCol > -1 && base.RightCol > -1)
			{
				for (num3 = base.LeftCol; num3 <= base.RightCol; num3++)
				{
					num3 = DrawCell(e, row, num3);
				}
			}
		}

		protected override int DrawCell(PaintEventArgs e, int row, int col)
		{
			if (!7Y(row, col))
			{
				return base.DrawCell(e, row, col);
			}
			CellRange mergedRange = GetMergedRange(row, col, clip: true);
			while (mergedRange.r1 < mergedRange.r2 && !base.Rows[mergedRange.r1].Visible)
			{
				mergedRange.r1++;
			}
			while (mergedRange.c1 < mergedRange.c2 && !base.Cols[mergedRange.c1].Visible)
			{
				mergedRange.c1++;
			}
			if (mergedRange.IsSingleCell)
			{
				return base.DrawCell(e, row, col);
			}
			if (row > mergedRange.r1 && (row > base.TopRow || (row > 0 && row < base.Rows.Fixed)))
			{
				return mergedRange.c2;
			}
			if (col > mergedRange.c1 && (col > base.LeftCol || (col > 0 && col < base.Cols.Fixed)))
			{
				return mergedRange.c2;
			}
			Rectangle cellRectDisplay = base.GetCellRectDisplay(mergedRange.r1, mergedRange.c1, clipHorz: false, clipVert: false);
			Rectangle cellRectDisplay2 = base.GetCellRectDisplay(mergedRange.r2, mergedRange.c2, clipHorz: false, clipVert: false);
			Rectangle rc = Rectangle.Union(cellRectDisplay, cellRectDisplay2);
			Rectangle clientRectangle = ((Control)this).ClientRectangle;
			if (rc.Left > clientRectangle.Right)
			{
				return mergedRange.c2;
			}
			if (!rc.IntersectsWith(e.ClipRectangle) || rc.Width == 0)
			{
				return mergedRange.c2;
			}
			row = mergedRange.r1;
			col = mergedRange.c1;
			Image 0AK;
			CheckEnum 0AL;
			string str = 7M(row, col, out 0AK, out 0AL);
			Style styleDisplay = GetStyleDisplay(row, col);
			DrawCell(e.Graphics, row, col, styleDisplay, rc, str, 0AK, 0AL);
			return mergedRange.c2;
		}

		protected internal override void DrawCellImage(Graphics g, int row, int col, Rectangle rcBounds)
		{
			CellRange mergedRange = GetMergedRange(row, col, clip: false);
			while (mergedRange.r1 < mergedRange.r2 && !base.Rows[mergedRange.r1].Visible)
			{
				mergedRange.r1++;
			}
			while (mergedRange.c1 < mergedRange.c2 && !base.Cols[mergedRange.c1].Visible)
			{
				mergedRange.c1++;
			}
			if (mergedRange.r1 >= row && mergedRange.c1 >= col)
			{
				Rectangle rectangle = N1.88(mergedRange.r1, mergedRange.c1);
				if (mergedRange.r2 > mergedRange.r1 || mergedRange.c2 > mergedRange.c1)
				{
					rectangle = Rectangle.Union(rectangle, N1.88(mergedRange.r2, mergedRange.c2));
				}
				rectangle.Intersect(rcBounds);
				if (rectangle.Width != 0)
				{
					Image 0AK;
					CheckEnum 0AL;
					string str = 7M(row, col, out 0AK, out 0AL);
					Style styleDisplay = GetStyleDisplay(mergedRange.r1, mergedRange.c1);
					DrawCell(g, mergedRange.r1, mergedRange.c1, styleDisplay, rectangle, str, 0AK, 0AL);
				}
			}
		}

		protected internal override void MoveSelection(MoveCursorEnum move, bool extend)
		{
			if (PB == AllowMergingEnum.None)
			{
				base.MoveSelection(move, extend);
				return;
			}
			CellRange cellRange = base.WZ.EJ();
			int row = (extend ? cellRange.r2 : cellRange.r1);
			int col = (extend ? cellRange.c2 : cellRange.c1);
			cellRange = GetMergedRange(row, col, clip: false);
			switch (move)
			{
			case MoveCursorEnum.CellUp:
				row = cellRange.r1;
				break;
			case MoveCursorEnum.CellDown:
				row = cellRange.r2;
				break;
			case MoveCursorEnum.CellPrev:
				col = cellRange.c1;
				break;
			case MoveCursorEnum.CellLeft:
				col = cellRange.c1;
				break;
			case MoveCursorEnum.CellRight:
				col = cellRange.c2;
				break;
			case MoveCursorEnum.CellNext:
				col = cellRange.c2;
				break;
			}
			MoveSelection(move, extend, row, col);
		}

		protected internal override void AutoSizeCols(Graphics g, int row1, int col1, int row2, int col2, int extra, AutoSizeFlags flags)
		{
			if (PB == AllowMergingEnum.None)
			{
				base.AutoSizeCols(g, row1, col1, row2, col2, extra, flags);
				return;
			}
			bool flag = (flags & AutoSizeFlags.IgnoreHidden) != 0;
			bool flag2 = (flags & AutoSizeFlags.IgnoreMerged) != 0;
			bool flag3 = (flags & AutoSizeFlags.SameSize) != 0;
			int num = -1;
			for (int i = col1; i <= col2; i++)
			{
				if (flag && base.Cols[i].WidthDisplay == 0)
				{
					continue;
				}
				GridTree pM = N1.PM;
				int num2 = pM.FD(i);
				if (num2 > 0 && (pM.VZ & TreeStyleFlags.ButtonBar) != TreeStyleFlags.None)
				{
					num = num2 + pM.VT - extra;
				}
				for (int j = row1; j <= row2; j++)
				{
					if (flag && base.Rows[j].HeightDisplay == 0)
					{
						continue;
					}
					Image 0AK;
					CheckEnum 0AL;
					string text = 7M(j, i, out 0AK, out 0AL);
					if (0AK == null && text.Length == 0)
					{
						continue;
					}
					Style styleDisplay = GetStyleDisplay(j, i);
					int num3 = styleDisplay.57(g, text, 0AK) + num2;
					if (7Y(j, i))
					{
						CellRange mergedRange = GetMergedRange(j, i, clip: false);
						if (flag2 && !mergedRange.IsSingleCell)
						{
							continue;
						}
						num3 /= mergedRange.c2 - mergedRange.c1 + 1;
					}
					if (num3 > num)
					{
						num = num3;
					}
				}
				if (!flag3 && num > -1)
				{
					base.Cols[i].Width = num + extra;
					num = -1;
				}
			}
			if (flag3 && num > -1)
			{
				for (int i = col1; i <= col2; i++)
				{
					base.Cols[i].Width = num + extra;
				}
			}
		}

		protected internal override void AutoSizeRows(Graphics g, int row1, int col1, int row2, int col2, int extra, AutoSizeFlags flags)
		{
			if (PB == AllowMergingEnum.None)
			{
				base.AutoSizeRows(g, row1, col1, row2, col2, extra, flags);
				return;
			}
			bool flag = (flags & AutoSizeFlags.IgnoreHidden) != 0;
			bool flag2 = (flags & AutoSizeFlags.IgnoreMerged) != 0;
			bool flag3 = (flags & AutoSizeFlags.SameSize) != 0;
			int num = -1;
			for (int i = row1; i <= row2; i++)
			{
				if (flag && base.Rows[i].HeightDisplay == 0)
				{
					continue;
				}
				for (int j = col1; j <= col2; j++)
				{
					if (flag && base.Cols[j].WidthDisplay == 0)
					{
						continue;
					}
					Image 0AK;
					CheckEnum 0AL;
					string text = 7M(i, j, out 0AK, out 0AL);
					if (0AK == null && text.Length == 0)
					{
						continue;
					}
					Style styleDisplay = GetStyleDisplay(i, j);
					int num2 = styleDisplay.5A(g, GetCellRectDisplay(i, j, clipHorz: false, clipVert: false).Width, text, 0AK);
					if (7Y(i, j))
					{
						CellRange mergedRange = GetMergedRange(i, j, clip: false);
						if (flag2 && !mergedRange.IsSingleCell)
						{
							continue;
						}
						num2 /= mergedRange.r2 - mergedRange.r1 + 1;
					}
					if (num2 > num)
					{
						num = num2;
					}
				}
				if (!flag3 && num > -1)
				{
					int num3 = num + extra;
					if (num3 <= base.Rows.DefaultSize)
					{
						num3 = -1;
					}
					base.Rows[i].Height = num3;
					num = -1;
				}
			}
			if (flag3 && num > -1)
			{
				int num4 = num + extra;
				if (num4 <= base.Rows.DefaultSize)
				{
					num4 = -1;
				}
				for (int i = row1; i <= row2; i++)
				{
					base.Rows[i].Height = num4;
				}
			}
		}

		private bool 7V(int 0B6)
		{
			switch (PB)
			{
			case AllowMergingEnum.Spill:
			case AllowMergingEnum.Nodes:
				return false;
			default:
				if (!base.Cols[0B6].AllowMerging)
				{
					return false;
				}
				if (0B6 > base.Cols.Fixed && 80() && !7V(0B6 - 1))
				{
					return false;
				}
				return true;
			}
		}

		private bool 7W(int 0B7)
		{
			if (PB == AllowMergingEnum.Spill)
			{
				return true;
			}
			if (PB == AllowMergingEnum.Nodes && base.Rows[0B7].IsNode)
			{
				return true;
			}
			if (!base.Rows[0B7].AllowMerging)
			{
				return false;
			}
			if (0B7 > base.Rows.Fixed && 7Z() && !7W(0B7 - 1))
			{
				return false;
			}
			return true;
		}

		private bool 7X(int 0B8, int 0B9, object 0BA)
		{
			object data = GetData(0B8, 0B9);
			if (82(data) || (object)0BA.GetType() != data.GetType())
			{
				return false;
			}
			if (!(0BA is IComparable))
			{
				return 0BA.Equals(data);
			}
			return ((IComparable)0BA).CompareTo(data) == 0;
		}

		private bool 7Y(int 0BB, int 0BC)
		{
			switch (PB)
			{
			case AllowMergingEnum.None:
				return false;
			case AllowMergingEnum.Spill:
				return true;
			case AllowMergingEnum.Nodes:
				return base.Rows[0BB].IsNode;
			default:
				if (!base.Rows[0BB].AllowMerging)
				{
					return base.Cols[0BC].AllowMerging;
				}
				return true;
			}
		}

		private bool 7Z()
		{
			if (PB != AllowMergingEnum.RestrictAll)
			{
				return PB == AllowMergingEnum.RestrictRows;
			}
			return true;
		}

		private bool 80()
		{
			if (PB != AllowMergingEnum.RestrictAll)
			{
				return PB == AllowMergingEnum.RestrictCols;
			}
			return true;
		}

		private void 81(int 0BD, int 0BE, out bool 0BF, out bool 0BG)
		{
			0BF = false;
			0BG = false;
			CellRange mergedRange = GetMergedRange(0BD, 0BE, clip: false);
			for (0BD = mergedRange.r1; 0BD <= mergedRange.r2; 0BD++)
			{
				for (0BE = mergedRange.c1; 0BE <= mergedRange.c2; 0BE++)
				{
					if (N1.8K(0BD, 0BE))
					{
						0BF = true;
					}
					if (N1.8L(0BD, 0BE))
					{
						0BG = true;
					}
					if (0BF && 0BG)
					{
						break;
					}
				}
			}
		}

		private bool 82(object 0BH)
		{
			if (0BH == null || 0BH == DBNull.Value)
			{
				return true;
			}
			if (0BH is string && ((string)0BH).Length == 0)
			{
				return true;
			}
			return false;
		}
	}
	public enum AllowResizingEnum
	{
		None,
		Columns,
		Rows,
		Both,
		ColumnsUniform,
		RowsUniform,
		BothUniform
	}
	public enum AllowFreezingEnum
	{
		None,
		Columns,
		Rows,
		Both
	}
	public enum AllowDraggingEnum
	{
		None,
		Columns,
		Rows,
		Both
	}
	public enum AllowSortingEnum
	{
		None,
		SingleColumn,
		MultiColumn
	}
	public enum HighLightEnum
	{
		Never,
		Always,
		WithFocus
	}
	public enum FocusRectEnum
	{
		None,
		Light,
		Heavy,
		Solid,
		Raised,
		Inset
	}
	[Flags]
	public enum AutoSizeFlags
	{
		None = 0,
		SameSize = 1,
		IgnoreHidden = 2,
		IgnoreMerged = 4
	}
	public enum DrawModeEnum
	{
		Normal,
		OwnerDraw
	}
	[Flags]
	public enum DrawCellFlags
	{
		Background = 1,
		Border = 2,
		Content = 4,
		All = 0xFF
	}
	public enum FileFormatEnum
	{
		TextComma,
		TextTab,
		TextCustom
	}
	public enum ShowButtonsEnum
	{
		WhenEditing,
		WithFocus,
		Always
	}
	[Flags]
	public enum SortFlags
	{
		None = 0,
		Ascending = 1,
		Descending = 2,
		AsDisplayed = 4,
		IgnoreCase = 8,
		UseColSort = 0x10
	}
	[Flags]
	public enum ClearFlags
	{
		Content = 1,
		Style = 2,
		UserData = 4,
		All = 0xFFFF
	}
	public enum CheckEnum
	{
		None,
		Checked,
		Unchecked,
		TSChecked,
		TSUnchecked,
		TSGrayed
	}
	public enum AggregateEnum
	{
		None,
		Clear,
		Sum,
		Percent,
		Count,
		Average,
		Max,
		Min,
		Std,
		Var,
		StdPop,
		VarPop
	}
	[Flags]
	public enum AggregateFlags
	{
		None = 0,
		ExcludeNodes = 1,
		AggregateDates = 2
	}
	public enum SubtotalPositionEnum
	{
		AboveData,
		BelowData
	}
	public enum GlyphEnum
	{
		Ascending,
		Descending,
		Checked,
		Unchecked,
		Grayed,
		Collapsed,
		Expanded,
		DBCursor,
		DBAdd,
		ErrorInfo
	}
	public enum GridChangedTypeEnum
	{
		None,
		GridChanged,
		LayoutChanged,
		StyleChanged,
		RepaintGrid,
		RepaintCell,
		RepaintRange,
		Update,
		BeforeCollapse,
		AfterCollapse,
		EnsureVisible,
		Select,
		RowMoved,
		RowAdded,
		RowRemoved,
		RowSelected,
		ColMoved,
		ColAdded,
		ColRemoved,
		ColSelected,
		BeforeSelChange,
		AfterSelChange
	}
	public delegate void GridChangedEventHandler(object sender, GridChangedEventArgs e);
	public class GridChangedEventArgs : EventArgs
	{
		public readonly GridChangedTypeEnum GridChangedType;

		public readonly int r1;

		public readonly int c1;

		public readonly int r2;

		public readonly int c2;

		internal GridChangedEventArgs(GridChangedTypeEnum a)
		{
			r1 = (r2 = (c1 = (c2 = -1)));
			GridChangedType = a;
		}

		internal GridChangedEventArgs(GridChangedTypeEnum a, int row1, int col1, int row2, int col2)
		{
			r1 = row1;
			c1 = col1;
			r2 = row2;
			c2 = col2;
			GridChangedType = a;
		}

		internal GridChangedEventArgs(GridChangedTypeEnum a, int row, int col)
		{
			r1 = row;
			c1 = col;
			r2 = (c2 = -1);
			GridChangedType = a;
		}
	}
	internal class 0D
	{
		internal static Hashtable PD;

		internal static 05 PE;

		internal static Style PF;

		internal static Cursor PG;

		internal static Cursor PH;

		internal static Cursor PI;

		internal RowCollection PJ;

		internal ColumnCollection PK;

		internal 0V PL;

		internal GridTree PM;

		internal CellStyleCollection PN;

		internal 0F PO;

		internal Size PP;

		internal Image PQ;

		internal SubtotalPositionEnum PR;

		internal Column PS;

		internal 0E PT;

		internal Hashtable PU;

		internal bool PV;

		internal string PW;

		internal string PX;

		internal string PY;

		private GridChangedEventHandler PZ;

		internal bool X2
		{
			get
			{
				return PV;
			}
			set
			{
				if (PV != value)
				{
					PV = value;
					if (PV)
					{
						8G(GridChangedTypeEnum.GridChanged);
					}
				}
			}
		}

		internal Image X3
		{
			get
			{
				return PQ;
			}
			set
			{
				PQ = value;
				8G(GridChangedTypeEnum.RepaintGrid);
			}
		}

		internal SubtotalPositionEnum X4
		{
			get
			{
				return PR;
			}
			set
			{
				if (PR != value)
				{
					9K(AggregateEnum.Clear, 0, 0, 0, 0, null);
					PR = value;
				}
			}
		}

		internal event GridChangedEventHandler XL
		{
			[MethodImpl(MethodImplOptions.Synchronized)]
			add
			{
				PZ = (GridChangedEventHandler)Delegate.Combine(PZ, value);
			}
			[MethodImpl(MethodImplOptions.Synchronized)]
			remove
			{
				PZ = (GridChangedEventHandler)Delegate.Remove(PZ, value);
			}
		}

		internal 0D()
		{
			83();
		}

		internal 0D(int rows, int cols, int fixedRows, int fixedCols)
		{
			83();
			PK = new ColumnCollection(this, cols, fixedCols, PP.Width);
			PJ = new RowCollection(this, rows, fixedRows, PP.Height);
			8G(GridChangedTypeEnum.LayoutChanged);
		}

		protected virtual void 83()
		{
			//IL_0058: Unknown result type (might be due to invalid IL or missing references)
			//IL_005e: Expected O, but got Unknown
			//IL_00aa: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b4: Expected O, but got Unknown
			//IL_00bf: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c9: Expected O, but got Unknown
			//IL_00d4: Unknown result type (might be due to invalid IL or missing references)
			//IL_00de: Expected O, but got Unknown
			if (PD == null)
			{
				PD = new Hashtable();
				foreach (object value in Enum.GetValues(typeof(GlyphEnum)))
				{
					GlyphEnum glyphEnum = (GlyphEnum)value;
					Bitmap val = new Bitmap(8C(glyphEnum.ToString(CultureInfo.InvariantCulture) + ".bmp"));
					val.MakeTransparent(Color.FromArgb(0, 255, 0));
					PD.Add(glyphEnum, val);
				}
				PG = new Cursor(8C("OleDrag.cur"));
				PI = new Cursor(8C("FreezeRow.cur"));
				PH = new Cursor(8C("FreezeCol.cur"));
			}
			if (PE == null)
			{
				PE = new 05();
				Style style = PE.3O("Button");
				style.4T("AlignHorz", V.JR);
				style.4T("AlignVert", W.JV);
				style.4T("Wrap", false);
				style.4T("Trimming", (object)(StringTrimming)0);
				style.4T("AlignImage", U.JG);
				style.4T("Opaque", false);
				PF = style;
			}
			PV = true;
			PW = "\t\r";
			ref Size pP = ref PP;
			pP = new Size(75, 18);
			PR = SubtotalPositionEnum.AboveData;
			PO = new 0F();
			PL = new 0V(this);
			PM = new GridTree(this);
			PN = new CellStyleCollection(this);
			PT = new 0E(this);
		}

		internal void 84(object 0BK, 03 0BL)
		{
			8G(GridChangedTypeEnum.StyleChanged);
		}

		internal bool 85(int 0BM)
		{
			if (0BM >= 0)
			{
				return 0BM >= PJ.Count;
			}
			return true;
		}

		internal bool 86(int 0BN)
		{
			if (0BN >= 0)
			{
				return 0BN >= PK.Count;
			}
			return true;
		}

		internal bool 87(int 0BO, int 0BP)
		{
			if (!85(0BO))
			{
				return 86(0BP);
			}
			return true;
		}

		internal virtual Rectangle 88(int 0BQ, int 0BR)
		{
			return new Rectangle
			{
				X = PK[0BR].Left,
				Y = PJ[0BQ].Top,
				Width = PK[0BR].WidthDisplay,
				Height = PJ[0BQ].HeightDisplay
			};
		}

		internal void 89(GlyphEnum 0BS, Image 0BT)
		{
			if (PU == null && 0BT != null)
			{
				PU = new Hashtable();
			}
			if (0BT != null)
			{
				PU[0BS] = 0BT;
			}
			if (0BT == null && PU != null && PU.Contains(0BS))
			{
				PU.Remove(0BS);
			}
			8G(GridChangedTypeEnum.GridChanged);
		}

		internal Image 8A(GlyphEnum 0BU)
		{
			//IL_0042: Unknown result type (might be due to invalid IL or missing references)
			//IL_0048: Expected O, but got Unknown
			//IL_002c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0032: Expected O, but got Unknown
			if (PU != null && PU.Contains(0BU))
			{
				return (Image)PU[0BU];
			}
			return (Image)PD[0BU];
		}

		internal Image 8B(GlyphEnum 0BV)
		{
			//IL_002c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0032: Expected O, but got Unknown
			if (PU != null && PU.Contains(0BV))
			{
				return (Image)PU[0BV];
			}
			return null;
		}

		private Stream 8C(string 0BW)
		{
			Assembly executingAssembly = Assembly.GetExecutingAssembly();
			string[] manifestResourceNames = executingAssembly.GetManifestResourceNames();
			foreach (string text in manifestResourceNames)
			{
				if (text.EndsWith(0BW))
				{
					return executingAssembly.GetManifestResourceStream(text);
				}
			}
			return null;
		}

		internal virtual void 8D(GridChangedTypeEnum 0BX, int 0BY, int 0BZ, int 0C0, int 0C1)
		{
			bool flag = false;
			switch (0BX)
			{
			case GridChangedTypeEnum.RowMoved:
			case GridChangedTypeEnum.RowAdded:
			case GridChangedTypeEnum.RowRemoved:
			case GridChangedTypeEnum.ColMoved:
			case GridChangedTypeEnum.ColAdded:
			case GridChangedTypeEnum.ColRemoved:
				flag = true;
				break;
			case GridChangedTypeEnum.LayoutChanged:
			{
				ref CellRange uX = ref PL.UX;
				uX = new CellRange(this, -2, -2);
				flag = true;
				break;
			}
			}
			if (flag)
			{
				PL.EM();
			}
			if (0BX == GridChangedTypeEnum.AfterSelChange && 9H())
			{
				PO.AK();
			}
			if (PZ != null)
			{
				PZ(this, new GridChangedEventArgs(0BX, 0BY, 0BZ, 0C0, 0C1));
			}
		}

		internal virtual void 8E(GridChangedTypeEnum 0C2, CellRange 0C3)
		{
			8D(0C2, 0C3.r1, 0C3.c1, 0C3.r2, 0C3.c2);
		}

		internal virtual void 8F(GridChangedTypeEnum 0C4, int 0C5, int 0C6)
		{
			8D(0C4, 0C5, 0C6, -1, -1);
		}

		internal virtual void 8G(GridChangedTypeEnum 0C7)
		{
			8D(0C7, -1, -1, -1, -1);
		}

		internal virtual int FindRow(string strFind, int rowStart, int col, bool caseSensitive, bool fullMatch, bool wrap)
		{
			if (strFind == null || strFind.Length == 0)
			{
				return rowStart;
			}
			int length = strFind.Length;
			bool ignoreCase = !caseSensitive;
			for (int i = rowStart; i < PJ.Count; i++)
			{
				string dataDisplay = GetDataDisplay(i, col);
				if (dataDisplay != null && (!fullMatch || dataDisplay.Length == length) && string.Compare(strFind, 0, dataDisplay, 0, length, ignoreCase, CultureInfo.CurrentCulture) == 0)
				{
					return i;
				}
			}
			if (wrap)
			{
				for (int i = PJ.Fixed; i < rowStart; i++)
				{
					string dataDisplay = GetDataDisplay(i, col);
					if (dataDisplay != null && (!fullMatch || dataDisplay.Length == length) && string.Compare(strFind, 0, dataDisplay, 0, length, ignoreCase, CultureInfo.CurrentCulture) == 0)
					{
						return i;
					}
				}
			}
			return -1;
		}

		internal virtual int FindRow(object objFind, int rowStart, int col, bool wrap)
		{
			for (int i = rowStart; i < PJ.Count; i++)
			{
				if (06.5I(objFind, GetData(i, col)) == 0)
				{
					return i;
				}
			}
			if (wrap)
			{
				for (int i = PJ.Fixed; i < rowStart; i++)
				{
					if (06.5I(objFind, GetData(i, col)) == 0)
					{
						return i;
					}
				}
			}
			return -1;
		}

		internal virtual void Sort(int index, int count, IComparer compare)
		{
			ArrayList arrayList = (ArrayList)PJ.U6.Clone();
			arrayList.Sort(index, count, compare);
			PJ.U6 = arrayList;
			PJ.DM();
			8G(GridChangedTypeEnum.RowMoved);
		}

		internal virtual void Sort(SortFlags order, CellRange rg)
		{
			if (9H())
			{
				PO.AF(order, rg.c1, rg.c2);
				return;
			}
			CellRange uX = PL.UX;
			bool flag = rg.Equals(PL.UX);
			rg.Normalize();
			if (!rg.IsValid)
			{
				return;
			}
			0T comparer = new 0T(this, order, rg.c1, rg.c2);
			for (int i = rg.r1; i <= rg.r2; i++)
			{
				PJ[i].U3 = i;
			}
			ArrayList arrayList = (ArrayList)PJ.U6.Clone();
			int num = rg.r1;
			while (true)
			{
				if (num <= rg.r2 && PJ[num].IsNode)
				{
					num++;
					continue;
				}
				int j;
				for (j = num; j <= rg.r2 - 1 && !PJ[j + 1].IsNode; j++)
				{
				}
				if (num > rg.r2)
				{
					break;
				}
				if (j > num)
				{
					arrayList.Sort(num, j - num + 1, comparer);
				}
				num = j + 1;
			}
			PJ.U6 = arrayList;
			if (flag)
			{
				PL.EO(uX);
			}
			PJ.DM();
			8G(GridChangedTypeEnum.RowMoved);
		}

		internal virtual void 8H(SortFlags 0C9, int 0CA)
		{
			if (0C9 == SortFlags.None && PS == null)
			{
				return;
			}
			PS = null;
			if (!86(0CA))
			{
				PS = PK[0CA];
				if (0C9 != SortFlags.UseColSort)
				{
					PS.Sort = 0C9;
				}
			}
			8D(GridChangedTypeEnum.RepaintRange, 0, -1, 0, -1);
		}

		internal bool 8I(int 0CB, int 0CC)
		{
			if (!PJ.DO(0CB))
			{
				return PK.DO(0CC);
			}
			return true;
		}

		internal bool 8J(int 0CD, int 0CE)
		{
			if (!PJ.DP(0CD))
			{
				return PK.DP(0CE);
			}
			return true;
		}

		internal bool 8K(int 0CF, int 0CG)
		{
			return PL.EF(0CF, 0CG);
		}

		internal bool 8L(int 0CH, int 0CI)
		{
			return PL.EH(0CH, 0CI);
		}

		internal Style 8M(CellStyleEnum 0CJ)
		{
			return PN[0CJ].VA;
		}

		internal virtual Style GetStyleDisplay(int row, int col)
		{
			Style 0CK = (8I(row, col) ? 8M(CellStyleEnum.Fixed) : (8J(row, col) ? 8M(CellStyleEnum.Frozen) : (((row - PJ.Fixed) % 2 == 0) ? 8M(CellStyleEnum.Alternate) : 8M(CellStyleEnum.Normal))));
			return 8N(0CK, row, col);
		}

		internal virtual Style 8N(Style 0CK, int 0CL, int 0CM)
		{
			Style style = 8P(0CL, 0CM);
			Style style2 = ((0CL >= PJ.Fixed) ? PK[0CM].TX : PK[0CM].TY);
			Style style3 = ((0CM >= PK.Fixed) ? PJ[0CL].TX : PJ[0CL].TY);
			if (style3 != null)
			{
				0CK = style3.4O(0CK, 04C: false);
			}
			if (style2 != null)
			{
				0CK = style2.4O(0CK, 04C: false);
			}
			if (style != null)
			{
				0CK = style.4O(0CK, 04C: false);
			}
			if (style == null)
			{
				if (style2 == null)
				{
					if (style3 == null)
					{
						return 0CK;
					}
					return style3;
				}
				return style2;
			}
			return style;
		}

		internal virtual 0S 8O(int 0CN, int 0CO, bool 0CP)
		{
			int tU = PK[0CO].TU;
			ArrayList arrayList = PJ[0CN].U1;
			if (arrayList != null && tU < arrayList.Count && arrayList[tU] != null)
			{
				return (0S)arrayList[tU];
			}
			if (!0CP)
			{
				return null;
			}
			if (arrayList == null)
			{
				arrayList = new ArrayList(PK.Count);
				PJ[0CN].U1 = arrayList;
			}
			if (arrayList.Capacity < PK.Count)
			{
				arrayList.Capacity = PK.Count;
			}
			while (arrayList.Count <= tU)
			{
				arrayList.Add(null);
			}
			return (0S)(arrayList[tU] = new 0S());
		}

		internal virtual Style 8P(int 0CQ, int 0CR)
		{
			return 8O(0CQ, 0CR, 0CP: false)?.UI;
		}

		internal virtual void 8Q(int 0CS, int 0CT, Style 0CU)
		{
			0S 0S2 = 8O(0CS, 0CT, 0CU != null);
			if (0S2 != null)
			{
				0S2.UI = 0CU;
				8F(GridChangedTypeEnum.RepaintRange, 0CS, 0CT);
			}
		}

		internal virtual CheckEnum GetCellCheck(int row, int col)
		{
			if (8R(row, col))
			{
				object obj = 06.5J(GetData(row, col), typeof(bool));
				if (obj != null && !obj.Equals(false))
				{
					return CheckEnum.Checked;
				}
				return CheckEnum.Unchecked;
			}
			return 8O(row, col, 0CP: false)?.UJ ?? CheckEnum.None;
		}

		internal virtual void SetCellCheck(int row, int col, CheckEnum check)
		{
			if (8R(row, col))
			{
				bool flag = check == CheckEnum.Checked || check == CheckEnum.TSChecked;
				SetData(row, col, flag);
				return;
			}
			0S 0S2 = 8O(row, col, check != CheckEnum.None);
			if (0S2 != null)
			{
				0S2.UJ = check;
				8F(GridChangedTypeEnum.RepaintRange, row, col);
			}
		}

		internal bool 8R(int 0CV, int 0CW)
		{
			if (8I(0CV, 0CW))
			{
				return false;
			}
			if ((object)8X(0CV, 0CW) != typeof(bool))
			{
				return false;
			}
			if (91(0CV, 0CW) != null)
			{
				return false;
			}
			if (8Y(0CV, 0CW, 0DG: false).Length > 0)
			{
				return false;
			}
			if (PJ[0CV].IsNode)
			{
				object data = GetData(0CV, 0CW);
				if (data == null || (object)data.GetType() != typeof(bool))
				{
					return false;
				}
			}
			return true;
		}

		internal virtual Image 8S(int 0CX, int 0CY)
		{
			return 8O(0CX, 0CY, 0CP: false)?.UK;
		}

		internal virtual void 8T(int 0CZ, int 0D0, Image 0D1)
		{
			0S 0S2 = 8O(0CZ, 0D0, 0D1 != null);
			if (0S2 != null)
			{
				0S2.UK = 0D1;
				8F(GridChangedTypeEnum.RepaintRange, 0CZ, 0D0);
			}
		}

		internal virtual object 8U(int 0D2, int 0D3)
		{
			return 8O(0D2, 0D3, 0CP: false)?.UL;
		}

		internal virtual void 8V(int 0D4, int 0D5, object 0D6)
		{
			0S 0S2 = 8O(0D4, 0D5, 0D6 != null);
			if (0S2 != null)
			{
				0S2.UL = 0D6;
			}
		}

		internal virtual object GetData(int row, int col)
		{
			if (9H() && col >= PK.Fixed && PJ[row].DataIndex > -1)
			{
				return PO.A9(row, col);
			}
			int tU = PK[col].TU;
			ArrayList u = PJ[row].U0;
			if (u != null && tU < u.Count)
			{
				return u[tU];
			}
			return null;
		}

		internal virtual bool SetData(int row, int col, object data, bool coerce)
		{
			bool flag = 8I(row, col);
			if (9H() && !flag && !PJ[row].IsNode)
			{
				if (!PO.AA(row, col, data))
				{
					return false;
				}
				8F(GridChangedTypeEnum.RepaintCell, row, col);
				PT.9S(row, col);
				return true;
			}
			if (coerce && !flag && data != null)
			{
				data = 06.5J(data, 8X(row, col));
				if (data == null)
				{
					return false;
				}
			}
			int tU = PK[col].TU;
			ArrayList arrayList = PJ[row].U0;
			if (arrayList == null)
			{
				arrayList = new ArrayList(PK.Count);
				PJ[row].U0 = arrayList;
			}
			if (arrayList.Capacity < PK.Count)
			{
				arrayList.Capacity = PK.Count;
			}
			while (arrayList.Count <= tU)
			{
				arrayList.Add(null);
			}
			if (data == null && arrayList[tU] == null)
			{
				return true;
			}
			arrayList[tU] = data;
			8F(GridChangedTypeEnum.RepaintCell, row, col);
			PT.9S(row, col);
			return true;
		}

		internal virtual bool SetData(int row, int col, object data)
		{
			return SetData(row, col, data, coerce: true);
		}

		internal virtual string 8W(int 0D8, int 0D9, out Image 0DA, out CheckEnum 0DB)
		{
			0DB = GetCellCheck(0D8, 0D9);
			0DA = 8S(0D8, 0D9);
			if (0DA == null && (object)8X(0D8, 0D9) == typeof(Image))
			{
				object data = GetData(0D8, 0D9);
				0DA = (Image)((data is Image) ? data : null);
				if (0DA != null)
				{
					return null;
				}
			}
			if (0DA == null)
			{
				0DA = 93(0D8, 0D9);
				if (0DA != null && !94(0D8, 0D9))
				{
					return "";
				}
			}
			return GetDataDisplay(0D8, 0D9);
		}

		internal virtual string GetDataDisplay(int row, int col)
		{
			object data = GetData(row, col);
			if (data == null)
			{
				return "";
			}
			bool flag = 8I(row, col);
			if (9H() && !flag && !PJ[row].IsNode && (object)data.GetType() != PK[col].DataType && (object)PK[col].DataType != null && PK[col].DataType.IsEnum)
			{
				return PO.A8(data, col);
			}
			if (!flag && data != null && data != DBNull.Value)
			{
				System.Collections.IDictionary dictionary = 91(row, col);
				if (dictionary != null && dictionary.Contains(data))
				{
					return dictionary[data].ToString();
				}
			}
			string text = 8Y(row, col, 0DG: false);
			if (text == null || text.Length == 0)
			{
				TypeConverter converter = TypeDescriptor.GetConverter(data.GetType());
				if (converter == null || !converter.CanConvertTo(typeof(string)))
				{
					return data.ToString();
				}
				return converter.ConvertToString(null, CultureInfo.CurrentCulture, data);
			}
			try
			{
				if (data is bool)
				{
					string[] array = 8Y(row, col, 0DG: true).Split(new char[1] { ';' });
					return array[(!(bool)data) ? 1u : 0u];
				}
				return string.Format(CultureInfo.CurrentCulture, text, new object[1] { data });
			}
			catch
			{
				return data.ToString();
			}
		}

		internal Type 8X(int 0DC, int 0DD)
		{
			Style styleDisplay = GetStyleDisplay(0DC, 0DD);
			Type type = (Type)styleDisplay.4V("DataType");
			if ((object)type != typeof(object))
			{
				return type;
			}
			return null;
		}

		internal string 8Y(int 0DE, int 0DF, bool 0DG)
		{
			Style styleDisplay = GetStyleDisplay(0DE, 0DF);
			return styleDisplay.4V(0DG ? "Format" : "FormatStr") as string;
		}

		internal string 8Z(int 0DH, int 0DI)
		{
			Style styleDisplay = GetStyleDisplay(0DH, 0DI);
			if (styleDisplay.4V("ComboList") is string { Length: >0 } text)
			{
				return text;
			}
			return PX;
		}

		internal string 90(int 0DJ, int 0DK)
		{
			Style styleDisplay = GetStyleDisplay(0DJ, 0DK);
			if (styleDisplay.4V("EditMask") is string { Length: >0 } text)
			{
				return text;
			}
			return PY;
		}

		internal System.Collections.IDictionary 91(int 0DL, int 0DM)
		{
			Style styleDisplay = GetStyleDisplay(0DL, 0DM);
			return styleDisplay.4V("DataMap") as System.Collections.IDictionary;
		}

		internal System.Collections.IDictionary 92(int 0DN, int 0DO)
		{
			Style styleDisplay = GetStyleDisplay(0DN, 0DO);
			return styleDisplay.4V("ImageMap") as System.Collections.IDictionary;
		}

		internal Image 93(int 0DP, int 0DQ)
		{
			//IL_0061: Unknown result type (might be due to invalid IL or missing references)
			//IL_0067: Expected O, but got Unknown
			//IL_0050: Unknown result type (might be due to invalid IL or missing references)
			//IL_0056: Expected O, but got Unknown
			if (0DP < PJ.Fixed || 0DQ < PK.Fixed)
			{
				return null;
			}
			System.Collections.IDictionary dictionary = 92(0DP, 0DQ);
			if (dictionary == null)
			{
				return null;
			}
			object data = GetData(0DP, 0DQ);
			if (data != null && data != DBNull.Value && dictionary.Contains(data))
			{
				return (Image)dictionary[data];
			}
			return (Image)dictionary[""];
		}

		internal bool 94(int 0DR, int 0DS)
		{
			Style styleDisplay = GetStyleDisplay(0DR, 0DS);
			DisplayEnum displayEnum = (DisplayEnum)styleDisplay.4V("Display");
			return displayEnum != DisplayEnum.ImageOnly;
		}

		internal void 95(int 0DT, int 0DU, ClearFlags 0DV)
		{
			if ((0DV & ClearFlags.Content) != 0)
			{
				if (GetData(0DT, 0DU) != null)
				{
					SetData(0DT, 0DU, null, coerce: false);
				}
				8T(0DT, 0DU, null);
				SetCellCheck(0DT, 0DU, CheckEnum.None);
			}
			if ((0DV & ClearFlags.UserData) != 0)
			{
				8V(0DT, 0DU, null);
			}
			if ((0DV & ClearFlags.Style) != 0)
			{
				8Q(0DT, 0DU, null);
			}
		}

		internal void 96(ClearFlags 0DW, CellRange 0DX)
		{
			if (PJ.Count == 0 || PK.Count == 0 || 0DW == (ClearFlags)0)
			{
				return;
			}
			bool x = X2;
			X2 = false;
			try
			{
				8H(SortFlags.None, -1);
				0DX.Normalize();
				ClearFlags clearFlags = 0DW & ~ClearFlags.Content;
				if (clearFlags != 0)
				{
					for (int i = 0DX.r1; i <= 0DX.r2; i++)
					{
						PJ[i].Clear(clearFlags);
					}
					for (int j = 0DX.c1; j <= 0DX.c2; j++)
					{
						PK[j].Clear(clearFlags);
					}
				}
				for (int k = 0DX.r1; k <= 0DX.r2; k++)
				{
					for (int l = 0DX.c1; l <= 0DX.c2; l++)
					{
						95(k, l, 0DW);
					}
				}
			}
			finally
			{
				X2 = x;
			}
			8G(GridChangedTypeEnum.GridChanged);
		}

		internal char 97(bool 0DY, bool 0DZ)
		{
			if (!0DZ)
			{
				return PW[0DY ? 1 : 0];
			}
			if (!0DY)
			{
				return '\t';
			}
			return '\r';
		}

		internal string 98(bool 0E0)
		{
			string value = (0E0 ? "\r\n" : 97(0DY: true, 0E0).ToString(CultureInfo.CurrentCulture));
			char value2 = 97(0DY: false, 0E0);
			StringBuilder stringBuilder = new StringBuilder();
			for (int i = 0; i < PJ.Count; i++)
			{
				if (!PJ[i].Selected)
				{
					continue;
				}
				if (stringBuilder.Length > 0)
				{
					stringBuilder.Append(value);
				}
				for (int j = PK.Fixed; j < PK.Count; j++)
				{
					if (j > PK.Fixed)
					{
						stringBuilder.Append(value2);
					}
					stringBuilder.Append(GetDataDisplay(i, j));
				}
			}
			return stringBuilder.ToString();
		}

		internal string 99(CellRange 0E1, bool 0E2)
		{
			string value = (0E2 ? "\r\n" : 97(0DY: true, 0E2).ToString(CultureInfo.CurrentCulture));
			char value2 = 97(0DY: false, 0E2);
			0E1.Normalize();
			StringBuilder stringBuilder = new StringBuilder();
			for (int i = 0E1.r1; i <= 0E1.r2; i++)
			{
				if (i > 0E1.r1)
				{
					stringBuilder.Append(value);
				}
				for (int j = 0E1.c1; j <= 0E1.c2; j++)
				{
					if (j > 0E1.c1)
					{
						stringBuilder.Append(value2);
					}
					stringBuilder.Append(GetDataDisplay(i, j));
				}
			}
			return stringBuilder.ToString();
		}

		internal Size 9A(CellRange 0E3, string 0E4, bool 0E5)
		{
			0E3.Normalize();
			char c = 97(0DY: true, 0E5);
			char c2 = 97(0DY: false, 0E5);
			Size result = new Size(0, 0);
			string[] array = 0E4.Split(new char[1] { c });
			for (int i = 0; i < array.Length && 0E3.r1 + i <= 0E3.r2; i++)
			{
				string text = array[i];
				if (c == '\r' && text.Length > 0 && text[0] == '\n')
				{
					text = text.Substring(1);
				}
				if (0E5 && text.Length == 0 && i == array.Length - 1)
				{
					break;
				}
				result.Height++;
				string[] array2 = text.Split(new char[1] { c2 });
				for (int j = 0; j < array2.Length && 0E3.c1 + j <= 0E3.c2; j++)
				{
					object data = ((array2[j].Length == 0) ? null : array2[j]);
					SetData(0E3.r1 + i, 0E3.c1 + j, data, coerce: true);
					if (j + 1 > result.Width)
					{
						result.Width = j + 1;
					}
				}
			}
			return result;
		}

		internal void 9B(C1FlexGridBase 0E6, object 0E7, string 0E8)
		{
			PO.A1(0E6, 0E7, 0E8);
		}

		internal object 9C()
		{
			return PO.9X();
		}

		internal void 9D(C1FlexGridBase 0E9, object 0EA)
		{
			PO.9Y(0E9, 0EA);
		}

		internal string 9E()
		{
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Unknown result type (might be due to invalid IL or missing references)
			BindingMemberInfo val = PO.9Z();
			return ((BindingMemberInfo)(ref val)).BindingMember;
		}

		internal void 9F(C1FlexGridBase 0EB, string 0EC)
		{
			PO.A0(0EB, 0EC);
		}

		internal void 9G(C1FlexGridBase 0ED, bool 0EE)
		{
			PO.A2(0ED, 0EE);
		}

		internal bool 9H()
		{
			return PO.A6();
		}

		internal void 9I()
		{
			if (9H())
			{
				PO.AO();
			}
		}

		internal double 9J(AggregateEnum 0EG, CellRange 0EH, AggregateFlags 0EI)
		{
			int num = 0EH.TopRow;
			int num2 = 0EH.BottomRow;
			int leftCol = 0EH.LeftCol;
			int rightCol = 0EH.RightCol;
			if (leftCol < 0 || rightCol < 0)
			{
				return 0.0;
			}
			10 11 = default(10);
			bool flag = false;
			if (num < 0 || num2 < 0)
			{
				num = PJ.Fixed;
				num2 = PJ.Count - 1;
				flag = true;
			}
			bool flag2 = (0EI & AggregateFlags.ExcludeNodes) != 0;
			bool flag3 = (0EI & AggregateFlags.AggregateDates) != 0;
			for (int i = num; i <= num2; i++)
			{
				if ((flag && !PJ[i].Selected) || (flag2 && PJ[i].IsNode))
				{
					continue;
				}
				for (int j = leftCol; j <= rightCol; j++)
				{
					if (flag3)
					{
						object data = GetData(i, j);
						if (data is DateTime)
						{
							DateTime dateTime = (DateTime)data;
							11.F4((double)dateTime.Ticks);
						}
					}
					else
					{
						11.F4(GetData(i, j));
					}
				}
			}
			return 11.F5(0EG);
		}

		internal void 9K(AggregateEnum 0EJ, int 0EK, int 0EL, int 0EM, int 0EN, string 0EO)
		{
			bool x = X2;
			X2 = false;
			try
			{
				if (0EJ == AggregateEnum.Clear)
				{
					for (int i = PJ.Fixed; i < PJ.Count; i++)
					{
						if (PJ[i].IsNode)
						{
							PJ.DZ(i, 0LC: false);
							i--;
						}
					}
					X2 = x;
					return;
				}
				if (PJ.U6.Capacity < PJ.Count * 2)
				{
					PJ.U6.Capacity = PJ.Count * 2;
				}
				if ((86(0EL) || 86(0EM) || 0EL > 0EM) && (0EL != -1 || 0EM != -1))
				{
					throw new ArgumentException("Invalid parameters 'groupFrom', 'groupTo' in call to Subtotal method.");
				}
				if (0EJ != AggregateEnum.None && 86(0EN))
				{
					throw new ArgumentException("Invalid parameter 'totalOn' in call to Subtotal method.");
				}
				double 0EX = 0.0;
				if (0EJ == AggregateEnum.Percent && 0EN >= 0 && 0EN < PK.Count)
				{
					CellRange 0EH = new CellRange(this, PJ.Fixed, 0EN, PJ.Count - 1, 0EN);
					0EX = 9J(AggregateEnum.Sum, 0EH, AggregateFlags.ExcludeNodes);
				}
				int num = -1;
				int num2 = -1;
				for (int i = PJ.Fixed; i < PJ.Count; i++)
				{
					if (PJ[i].IsNode)
					{
						continue;
					}
					bool flag = false;
					if (0EL == -1 && 0EM == -1)
					{
						if (i == PJ.Fixed)
						{
							num = PJ.Fixed;
							num2 = PJ.Count - 1;
							flag = true;
						}
					}
					else if (num2 > -1 && num2 != i)
					{
						for (int j = 0EL; j <= 0EM; j++)
						{
							object data = GetData(i, j);
							object data2 = GetData(num2, j);
							if (06.5I(data, data2) != 0)
							{
								flag = true;
								break;
							}
						}
					}
					if (flag)
					{
						i = 9L(0EJ, 0EK, 0EL, 0EM, 0EN, 0EO, num, num2, 0EX);
						num = (num2 = -1);
						continue;
					}
					if (num < 0)
					{
						num = i;
					}
					num2 = i;
				}
				if (num2 >= 0)
				{
					9L(0EJ, 0EK, 0EL, 0EM, 0EN, 0EO, num, num2, 0EX);
				}
			}
			finally
			{
				X2 = x;
			}
		}

		private int 9L(AggregateEnum 0EP, int 0EQ, int 0ER, int 0ES, int 0ET, string 0EU, int 0EV, int 0EW, double 0EX)
		{
			object obj = null;
			if (0EP != AggregateEnum.None)
			{
				CellRange 0EH = new CellRange(this, 0EV, 0ET, 0EW, 0ET);
				bool flag = (object)PK[0ET].DataType == typeof(DateTime);
				AggregateFlags aggregateFlags = AggregateFlags.ExcludeNodes;
				if (flag)
				{
					aggregateFlags |= AggregateFlags.AggregateDates;
				}
				if (0EP == AggregateEnum.Percent)
				{
					obj = ((0EX != 0.0) ? (9J(AggregateEnum.Sum, 0EH, aggregateFlags) / 0EX * 100.0) : 0.0);
				}
				else
				{
					obj = 9J(0EP, 0EH, aggregateFlags);
					if (flag)
					{
						switch (0EP)
						{
						case AggregateEnum.Average:
						case AggregateEnum.Max:
						case AggregateEnum.Min:
							obj = new DateTime((long)(double)obj);
							break;
						}
					}
				}
			}
			bool flag2 = PR == SubtotalPositionEnum.AboveData;
			int i = (flag2 ? 0EV : (0EW + 1));
			if (flag2)
			{
				while (i > 0 && PJ[i - 1].IsNode && PJ[i - 1].U2 >= 0EQ)
				{
					i--;
				}
			}
			else
			{
				while (i > 0 && PJ[i - 1].IsNode && PJ[i - 1].U2 >= 0EQ)
				{
					i--;
				}
				for (; i < PJ.Count && PJ[i].IsNode && PJ[i].U2 > 0EQ; i++)
				{
				}
			}
			bool flag3 = i < PJ.Count && PJ[i].IsNode && PJ[i].U2 == 0EQ;
			if (!flag3)
			{
				Row row = PJ.DY(i, 0L9: false, 0R.TP);
				row.U2 = (short)0EQ;
				PJ.DM();
				int num = 0EQ;
				if (num < -1)
				{
					num = -1;
				}
				if (num > 5)
				{
					num = 5;
				}
				row.Style = PN[10 + num];
			}
			if (obj != null)
			{
				SetData(i, 0ET, obj, coerce: false);
			}
			if (!flag3)
			{
				int j = i;
				if (flag2)
				{
					for (; j < PJ.Count - 1 && PJ[j].IsNode; j++)
					{
					}
				}
				else
				{
					while (j > PJ.Fixed && PJ[j].IsNode)
					{
						j--;
					}
				}
				if (0EU == null)
				{
					if (0ER > -1)
					{
						for (int k = 0ER; k <= 0ES; k++)
						{
							SetData(i, k, GetData(j, k), coerce: false);
						}
					}
				}
				else if (!86(PM.Column))
				{
					if (0ER > -1)
					{
						if (0EU.IndexOf("{0}") > -1)
						{
							0EU = string.Format(CultureInfo.CurrentCulture, 0EU, new object[1] { GetDataDisplay(j, 0ES) });
						}
						else if (0EU.IndexOf("{0:") > -1)
						{
							0EU = string.Format(CultureInfo.CurrentCulture, 0EU, new object[1] { GetData(j, 0ES) });
						}
					}
					SetData(i, PM.Column, 0EU, coerce: false);
				}
			}
			if (!flag3)
			{
				return 0EW + 1;
			}
			return 0EW;
		}

		internal int 9M(int 0EY, int 0EZ)
		{
			int num = 0;
			if (PR == SubtotalPositionEnum.AboveData)
			{
				if (0EY >= PJ.Count - 1)
				{
					return 0;
				}
				if (!PJ[0EY + 1].IsNode)
				{
					num |= 1;
				}
			}
			else
			{
				if (0EY <= PJ.Fixed)
				{
					return 0;
				}
				if (!PJ[0EY - 1].IsNode)
				{
					num |= 1;
				}
			}
			if (PJ[0EY].IsNode)
			{
				Node node = PJ[0EY].Node;
				if (node.GetNode(NodeTypeEnum.FirstChild) != null)
				{
					num |= 2;
				}
			}
			return num;
		}
	}
	internal class 0E
	{
		internal 0D Q0;

		internal bool Q1;

		internal bool Q2;

		internal bool Q3;

		internal bool Q4;

		internal bool Q5;

		internal int Q6;

		internal bool X5
		{
			get
			{
				return Q1;
			}
			set
			{
				Q1 = value;
				9P();
			}
		}

		internal bool X6
		{
			get
			{
				return Q2;
			}
			set
			{
				Q2 = value;
			}
		}

		internal 0E(0D grid)
		{
			Q0 = grid;
			Q6 = -1;
		}

		internal bool 9N()
		{
			if (!Q1)
			{
				return false;
			}
			if (Q0.9H())
			{
				IBindingList qC = Q0.PO.QC;
				if (qC == null || !qC.AllowNew)
				{
					return false;
				}
			}
			return true;
		}

		internal bool 9O()
		{
			if (!Q2)
			{
				return false;
			}
			if (Q0.9H())
			{
				IBindingList qC = Q0.PO.QC;
				if (qC == null || !qC.AllowRemove)
				{
					return false;
				}
			}
			return true;
		}

		internal bool 9P()
		{
			RowCollection pJ = Q0.PJ;
			if (pJ == null)
			{
				return false;
			}
			if (Q4)
			{
				return false;
			}
			Q4 = true;
			bool flag = 9N();
			bool flag2 = false;
			if (pJ.Count > 0)
			{
				Row row = pJ[pJ.Count - 1];
				flag2 = (row.TV & 0R.TR) != 0R.TH;
			}
			if (flag && !flag2)
			{
				Row row2 = pJ.DY(pJ.Count, 0L9: false, 0R.TR);
				row2.Style = Q0.PN[CellStyleEnum.NewRow];
			}
			if (flag2 && !flag)
			{
				pJ.DZ(pJ.Count - 1, 0LC: false);
			}
			Q4 = false;
			return flag;
		}

		internal void 9Q(C1FlexGridBase 0F2, CellRange 0F3, CellRange 0F4)
		{
			if (0F3.r1 == 0F4.r1 || Q6 < 0 || Q3 || 0F3.r1 != Q6)
			{
				return;
			}
			if (0F4.r1 > 0F3.r1)
			{
				0F2.WZ.V4 = true;
				return;
			}
			Q6 = -1;
			if (0F3.r1 > 0F2.Rows.Fixed && 0F3.r1 < 0F2.Rows.Count)
			{
				0F2.Rows.DZ(0F3.r1, 0LC: true);
			}
		}

		internal void 9R(C1FlexGridBase 0F5, CellRange 0F6, CellRange 0F7)
		{
			if (0F6.r1 == 0F7.r1 || 0F7.r1 < 0 || !9N())
			{
				return;
			}
			int r = 0F7.r1;
			if (r < 0)
			{
				return;
			}
			Row row = 0F5.Rows[r];
			if ((row.TV & 0R.TR) == 0R.TH || Q5)
			{
				return;
			}
			int count = 0F5.Rows.Count;
			Q5 = true;
			0F5.Rows.DX(r, 0L7: true);
			Q5 = false;
			if (0F5.Rows.Count == count)
			{
				0F5.Select(0F6, show: true);
				return;
			}
			if (!Q0.9H())
			{
				0F5.Row = r;
			}
			if (0F5.Row == 0F5.Rows.Count - 1 && 0F5.Row != r)
			{
				0F5.Row = r;
			}
			Q3 = false;
			Q6 = r;
		}

		internal void 9S(int 0F8, int 0F9)
		{
			if (0F8 == Q6)
			{
				Q3 = true;
			}
		}

		internal bool 9T(C1FlexGridBase 0FA, KeyEventArgs 0FB)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0008: Invalid comparison between Unknown and I4
			//IL_0038: Unknown result type (might be due to invalid IL or missing references)
			//IL_003f: Invalid comparison between Unknown and I4
			if ((int)0FB.KeyCode == 27)
			{
				if (Q6 > -1 && !Q3)
				{
					Q0.PJ.DZ(Q6, 0LC: true);
					return true;
				}
				return false;
			}
			if ((int)0FB.KeyCode == 46 && 9O())
			{
				bool result = false;
				bool redraw = 0FA.Redraw;
				0FA.Redraw = false;
				try
				{
					if (0FA.SelectionMode == SelectionModeEnum.ListBox)
					{
						RowCollection selected = 0FA.Rows.Selected;
						foreach (Row item in (IEnumerable)selected)
						{
							0FA.Rows.Remove(item.Index);
						}
					}
					else
					{
						CellRange selection = 0FA.Selection;
						bool flag = (selection.c1 == 0FA.Cols.Fixed && selection.c2 == 0FA.Cols.Count - 1) || 0FA.SelectionMode == SelectionModeEnum.Row || 0FA.SelectionMode == SelectionModeEnum.RowRange;
						if (selection.r1 >= 0FA.Rows.Fixed && flag)
						{
							result = true;
							if (Q0.9H())
							{
								for (int num = selection.r2; num >= selection.r1; num--)
								{
									0FA.Rows.Remove(selection.r1);
								}
							}
							else
							{
								0FA.Rows.RemoveRange(selection.r1, selection.r2 - selection.r1 + 1);
							}
						}
					}
				}
				finally
				{
					0FA.Redraw = redraw;
				}
				if (0FA.Row == 0FA.Rows.Count - 1)
				{
					CellRange cellRange = 0FA.GetCellRange(-1, -1);
					CellRange selection2 = 0FA.Selection;
					9R(0FA, cellRange, selection2);
				}
				return result;
			}
			return false;
		}

		internal void 9U(C1FlexGridBase 0FC)
		{
			if (0FC.Row == Q6)
			{
				Q3 = false;
			}
		}
	}
	public struct CellRange
	{
		internal 0D Q7;

		public int r1;

		public int c1;

		public int r2;

		public int c2;

		public bool IsSingleCell
		{
			get
			{
				if (r1 == r2)
				{
					return c1 == c2;
				}
				return false;
			}
		}

		public bool IsValid
		{
			get
			{
				if (r1 < 0 || r2 < 0 || c1 < 0 || c2 < 0 || Q7 == null)
				{
					return false;
				}
				if (Q7.86(c1) || Q7.86(c2) || Q7.85(r1) || Q7.85(r2))
				{
					return false;
				}
				return true;
			}
		}

		public int TopRow
		{
			get
			{
				if (r1 > r2)
				{
					return r2;
				}
				return r1;
			}
		}

		public int BottomRow
		{
			get
			{
				if (r2 < r1)
				{
					return r1;
				}
				return r2;
			}
		}

		public int LeftCol
		{
			get
			{
				if (c1 > c2)
				{
					return c2;
				}
				return c1;
			}
		}

		public int RightCol
		{
			get
			{
				if (c2 < c1)
				{
					return c1;
				}
				return c2;
			}
		}

		public object Data
		{
			get
			{
				9V();
				return Q7.GetData(r1, c1);
			}
			set
			{
				9V();
				for (int i = TopRow; i <= BottomRow; i++)
				{
					for (int j = LeftCol; j <= RightCol; j++)
					{
						Q7.SetData(i, j, value);
					}
				}
			}
		}

		public string DataDisplay
		{
			get
			{
				9V();
				return Q7.GetDataDisplay(r1, c1);
			}
		}

		public CellStyle Style
		{
			get
			{
				9V();
				Style style = Q7.8P(r1, c1);
				for (int i = TopRow; i <= BottomRow; i++)
				{
					for (int j = LeftCol; j <= RightCol; j++)
					{
						if (i != r1 || j != c1)
						{
							Q7.8Q(i, j, style);
						}
					}
				}
				if (style == null)
				{
					return null;
				}
				return new CellStyle(style);
			}
			set
			{
				Style 0CU = value?.VA;
				for (int i = TopRow; i <= BottomRow; i++)
				{
					for (int j = LeftCol; j <= RightCol; j++)
					{
						Q7.8Q(i, j, 0CU);
					}
				}
			}
		}

		public CellStyle StyleNew
		{
			get
			{
				9V();
				CellStyle style = Style;
				if (style != null)
				{
					return style;
				}
				Style style2 = Q7.PN.ER();
				return Style = new CellStyle(style2);
			}
		}

		public CellStyle StyleDisplay
		{
			get
			{
				9V();
				Style styleDisplay = Q7.GetStyleDisplay(r1, c1);
				return new CellStyle(styleDisplay);
			}
		}

		public CheckEnum Checkbox
		{
			get
			{
				9V();
				return Q7.GetCellCheck(r1, c1);
			}
			set
			{
				9V();
				for (int i = TopRow; i <= BottomRow; i++)
				{
					for (int j = LeftCol; j <= RightCol; j++)
					{
						Q7.SetCellCheck(i, j, value);
					}
				}
			}
		}

		public Image Image
		{
			get
			{
				9V();
				return Q7.8S(r1, c1);
			}
			set
			{
				9V();
				for (int i = TopRow; i <= BottomRow; i++)
				{
					for (int j = LeftCol; j <= RightCol; j++)
					{
						Q7.8T(i, j, value);
					}
				}
			}
		}

		public object UserData
		{
			get
			{
				9V();
				return Q7.8U(r1, c1);
			}
			set
			{
				9V();
				for (int i = TopRow; i <= BottomRow; i++)
				{
					for (int j = LeftCol; j <= RightCol; j++)
					{
						Q7.8V(i, j, value);
					}
				}
			}
		}

		public string Clip
		{
			get
			{
				9V();
				return Q7.99(this, 0E2: false);
			}
			set
			{
				9V();
				Q7.9A(this, value, 0E5: false);
			}
		}

		internal CellRange(0D grid, int row, int col)
		{
			Q7 = grid;
			r1 = (r2 = row);
			c1 = (c2 = col);
		}

		internal CellRange(0D grid, int row1, int col1, int row2, int col2)
		{
			Q7 = grid;
			r1 = row1;
			c1 = col1;
			r2 = ((row2 >= 0) ? row2 : row1);
			c2 = ((col2 >= 0) ? col2 : col1);
		}

		public bool ContainsRow(int row)
		{
			if (r1 < 0 || r2 < 0)
			{
				return false;
			}
			if (row < r1 || row > r2)
			{
				if (row >= r2)
				{
					return row <= r1;
				}
				return false;
			}
			return true;
		}

		public bool ContainsCol(int col)
		{
			if (c1 < 0 || c2 < 0)
			{
				return false;
			}
			if (col < c1 || col > c2)
			{
				if (col >= c2)
				{
					return col <= c1;
				}
				return false;
			}
			return true;
		}

		public bool Contains(int row, int col)
		{
			if (ContainsRow(row))
			{
				return ContainsCol(col);
			}
			return false;
		}

		public void Normalize()
		{
			if (r1 > r2)
			{
				int num = r1;
				r1 = r2;
				r2 = num;
			}
			if (c1 > c2)
			{
				int num2 = c1;
				c1 = c2;
				c2 = num2;
			}
		}

		internal void 9V()
		{
			if (!IsValid)
			{
				throw new Exception("Invalid CellRange for this operation");
			}
		}

		internal CellRange 9W(CellRange 0FD)
		{
			0FD.Normalize();
			if (0FD.c1 == LeftCol && 0FD.c2 == RightCol)
			{
				if (0FD.r1 == TopRow)
				{
					0FD.r1 = Math.Min(0FD.r2, BottomRow);
					0FD.r2 = Math.Max(0FD.r2, BottomRow);
					return 0FD;
				}
				if (0FD.r2 == BottomRow)
				{
					0FD.r2 = Math.Max(0FD.r1, TopRow);
					0FD.r1 = Math.Min(0FD.r1, TopRow);
					return 0FD;
				}
			}
			if (0FD.r1 == TopRow && 0FD.r2 == BottomRow)
			{
				if (0FD.c1 == LeftCol)
				{
					0FD.c1 = Math.Min(0FD.c2, RightCol);
					0FD.c2 = Math.Max(0FD.c2, RightCol);
					return 0FD;
				}
				if (0FD.c2 == RightCol)
				{
					0FD.c2 = Math.Max(0FD.c1, LeftCol);
					0FD.c1 = Math.Min(0FD.c1, LeftCol);
					return 0FD;
				}
			}
			0FD.r1 = (0FD.r2 = (0FD.c1 = (0FD.c2 = -1)));
			return 0FD;
		}

		public void Clear(ClearFlags clearFlags)
		{
			9V();
			for (int i = TopRow; i <= BottomRow; i++)
			{
				for (int j = LeftCol; j <= RightCol; j++)
				{
					Q7.95(i, j, clearFlags);
				}
			}
		}

		public override string ToString()
		{
			return string.Format(CultureInfo.CurrentCulture, "CellRange: ({0},{1})-({2},{3})", r1, c1, r2, c2);
		}
	}
	internal class 0F
	{
		internal C1FlexGridBase Q8 = null;

		internal object Q9 = null;

		internal CurrencyManager QA = null;

		internal BindingMemberInfo QB;

		internal IBindingList QC = null;

		internal PropertyDescriptorCollection QD = null;

		internal IC1DataSource QE = null;

		internal int QF = -1;

		internal int QG = -1;

		internal bool QH = false;

		internal ToolTip QI = null;

		private bool QJ = false;

		internal object 9X()
		{
			return Q9;
		}

		internal void 9Y(C1FlexGridBase 0FE, object 0FF)
		{
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			Q8 = 0FE;
			if (0FF == null)
			{
				((BindingMemberInfo)(ref QB))..ctor("");
			}
			A3(0FF, QB, 0FP: false);
		}

		internal BindingMemberInfo 9Z()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			return QB;
		}

		internal void A0(C1FlexGridBase 0FG, string 0FH)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0034: Unknown result type (might be due to invalid IL or missing references)
			//IL_0035: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Unknown result type (might be due to invalid IL or missing references)
			Q8 = 0FG;
			BindingMemberInfo qB = QB;
			try
			{
				A3(Q9, new BindingMemberInfo(0FH), 0FP: false);
			}
			catch (Exception 11)
			{
				Q8.72(-1, -1, 11, 098: true);
				QB = qB;
			}
		}

		internal void A1(C1FlexGridBase 0FI, object 0FJ, string 0FK)
		{
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0014: Unknown result type (might be due to invalid IL or missing references)
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			Q8 = 0FI;
			object q = Q9;
			BindingMemberInfo qB = QB;
			try
			{
				A3(0FJ, new BindingMemberInfo(0FK), 0FP: false);
			}
			catch (Exception 11)
			{
				Q8.72(-1, -1, 11, 098: true);
				Q9 = q;
				QB = qB;
			}
		}

		internal void A2(C1FlexGridBase 0FL, bool 0FM)
		{
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			Q8 = 0FL;
			A3(Q9, QB, 0FM);
		}

		protected void A3(object 0FN, BindingMemberInfo 0FO, bool 0FP)
		{
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			//IL_0082: Unknown result type (might be due to invalid IL or missing references)
			//IL_0083: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e5: Unknown result type (might be due to invalid IL or missing references)
			//IL_00eb: Expected O, but got Unknown
			//IL_01a8: Unknown result type (might be due to invalid IL or missing references)
			//IL_01b2: Expected O, but got Unknown
			//IL_01ec: Unknown result type (might be due to invalid IL or missing references)
			//IL_01f6: Expected O, but got Unknown
			bool flag = 0FN != Q9;
			bool flag2 = !((BindingMemberInfo)(ref QB)).Equals((object)0FO);
			if ((!flag && !flag2 && !0FP) || QJ)
			{
				return;
			}
			QJ = true;
			if (Q8 != null)
			{
				Q8.FinishEditing(cancel: true);
			}
			if (Q9 is IComponent)
			{
				((IComponent)Q9).Disposed -= AG;
			}
			Q9 = 0FN;
			QB = 0FO;
			if (Q9 is IComponent)
			{
				((IComponent)Q9).Disposed += AG;
			}
			CurrencyManager val = null;
			IBindingList bindingList = null;
			if (0FN != null && 0FN != Convert.DBNull && ((Control)Q8).BindingContext != null)
			{
				try
				{
					val = (CurrencyManager)((Control)Q8).BindingContext[0FN, ((BindingMemberInfo)(ref 0FO)).BindingMember];
				}
				catch
				{
					QJ = false;
					return;
				}
				bindingList = val.List as IBindingList;
			}
			QE = null;
			if (bindingList != null)
			{
				QE = LateBindingIC1DataSource.GetDataSource(bindingList);
				if (QE != null)
				{
					QE.SetBoundControl(this, ((Control)Q8).Name);
				}
			}
			if (QA != val || QC != bindingList)
			{
				if (QC != null && QC.SupportsChangeNotification)
				{
					QC.ListChanged -= AH;
				}
				if (QA != null)
				{
					((BindingManagerBase)QA).PositionChanged -= AJ;
					QA.ItemChanged -= new ItemChangedEventHandler(AI);
				}
				QA = val;
				QC = bindingList;
				if (QA != null)
				{
					((BindingManagerBase)QA).PositionChanged += AJ;
					QA.ItemChanged += new ItemChangedEventHandler(AI);
				}
				if (QC != null && QC.SupportsChangeNotification)
				{
					QC.ListChanged += AH;
				}
			}
			if (flag2 || flag || 0FP)
			{
				A4();
			}
			if (QA == null && Q8 != null)
			{
				Q8.N1.8G(GridChangedTypeEnum.GridChanged);
			}
			QJ = false;
		}

		protected void A4()
		{
			if (QA == null)
			{
				if (QD != null && Q8 != null)
				{
					QD = null;
					Q8.Clear(ClearFlags.Content);
				}
				return;
			}
			bool redraw = Q8.Redraw;
			Q8.Redraw = false;
			try
			{
				QD = ((BindingManagerBase)QA).GetItemProperties();
				int frozen = Q8.Rows.Frozen;
				Q8.Rows.DW(Q8.Rows.Fixed, 0L5: false);
				Q8.Rows.DW(Q8.Rows.Fixed + ((BindingManagerBase)QA).Count, 0L5: false);
				Q8.Rows.Frozen = frozen;
				QG = ((BindingManagerBase)QA).Count;
				if (Q8.NP)
				{
					frozen = Q8.Cols.Frozen;
					Q8.Cols.E2(Q8.Cols.Fixed, 0LI: false);
					foreach (PropertyDescriptor item in QD)
					{
						A5(item);
					}
					Q8.Cols.Frozen = frozen;
				}
				int num = Q8.Col;
				if (num >= Q8.Cols.Count)
				{
					num = -1;
				}
				Q8.Select(-1, num);
				AJ(this, null);
				if (redraw && Q8.LeftCol > Q8.Cols.Fixed + Q8.Cols.Frozen)
				{
					Q8.LeftCol = 0;
				}
				A7();
				if (Q8.NP && Q8.AutoResize)
				{
					Q8.AutoSizeCols();
				}
			}
			finally
			{
				Q8.Redraw = redraw;
			}
			Q8.OnDataRefresh(new ListChangedEventArgs(ListChangedType.Reset, -1, -1));
		}

		internal void A5(PropertyDescriptor 0FQ)
		{
			Column column = Q8.Cols.Add();
			column.Caption = 0FQ.DisplayName;
			column.Name = 0FQ.Name;
			column.AllowEditing = !0FQ.IsReadOnly;
			column.DataType = 0FQ.PropertyType;
			if ((object)column.DataType == typeof(byte[]) || typeof(IList).IsAssignableFrom(column.DataType))
			{
				bool visible = (column.AllowEditing = false);
				column.Visible = visible;
			}
			if (typeof(Image).IsAssignableFrom(column.DataType))
			{
				column.AllowEditing = false;
			}
		}

		internal bool A6()
		{
			return QA != null;
		}

		internal bool A7()
		{
			0D n = Q8.N1;
			n.PS = null;
			if (QC == null || !QC.SupportsSorting || !QC.IsSorted)
			{
				return false;
			}
			PropertyDescriptor sortProperty = QC.SortProperty;
			if (sortProperty == null)
			{
				return false;
			}
			Column column = Q8.Cols[sortProperty.Name];
			if (column == null)
			{
				return false;
			}
			SortFlags 0C2 = ((QC.SortDirection == ListSortDirection.Ascending) ? SortFlags.Ascending : SortFlags.Descending);
			n.8H(0C2, column.Index);
			return true;
		}

		internal string A8(object 0FR, int 0FS)
		{
			PropertyDescriptor propertyDescriptor = QD[Q8.Cols[0FS].Name];
			try
			{
				0FR = propertyDescriptor.Converter.ConvertToString(null, CultureInfo.CurrentCulture, 0FR);
			}
			catch
			{
			}
			return 0FR.ToString();
		}

		internal object A9(int 0FT, int 0FU)
		{
			try
			{
				int num = AM(0FT);
				if (num < 0)
				{
					return null;
				}
				object component = QA.List[num];
				PropertyDescriptor propertyDescriptor = QD[Q8.Cols[0FU].Name];
				if (propertyDescriptor != null)
				{
					return propertyDescriptor.GetValue(component);
				}
			}
			catch (Exception 11)
			{
				Q8.72(0FT, 0FU, 11, 098: true);
			}
			return null;
		}

		internal bool AA(int 0FV, int 0FW, object 0FX)
		{
			bool flag = false;
			0FV = AM(0FV);
			object obj = QA.List[0FV];
			PropertyDescriptor propertyDescriptor = QD[Q8.Cols[0FW].Name];
			try
			{
				propertyDescriptor.SetValue(obj, 0FX);
				flag = true;
			}
			catch
			{
			}
			if (!flag && propertyDescriptor != null)
			{
				object obj3 = 06.5J(0FX, propertyDescriptor.PropertyType);
				if (obj3 != null || 0FX == null)
				{
					try
					{
						QD[Q8.Cols[0FW].Name].SetValue(obj, obj3);
						flag = true;
					}
					catch
					{
					}
				}
			}
			if (flag)
			{
				if (obj is IEditableObject editableObject)
				{
					editableObject.BeginEdit();
				}
				QH = true;
			}
			return flag;
		}

		internal void AB()
		{
			try
			{
				if (QH)
				{
					((BindingManagerBase)QA).EndCurrentEdit();
				}
				QH = false;
			}
			catch (Exception 11)
			{
				Q8.72(Q8.Row, Q8.Col, 11, 098: true);
			}
		}

		internal void AC(int 0FY)
		{
			((BindingManagerBase)QA).RemoveAt(0FY);
		}

		internal void AD(int 0FZ)
		{
			try
			{
				((BindingManagerBase)QA).AddNew();
			}
			catch (Exception 11)
			{
				Q8.72(-1, -1, 11, 098: true);
			}
		}

		internal void AE(int 0G0, int 0G1)
		{
			if (0G0 != 0G1 && (QC == null || !QC.SupportsSorting || !QC.IsSorted))
			{
				object value = QA.List[0G0];
				QA.List.RemoveAt(0G0);
				QA.List.Insert(0G1, value);
			}
		}

		internal bool AF(SortFlags 0G2, int 0G3, int 0G4)
		{
			if (QC is DataView dataView)
			{
				string text = "";
				for (int i = 0G3; i <= 0G4; i++)
				{
					Column column = Q8.Cols[i];
					if ((object)column.DataType == typeof(byte[]) || column.Name == null || QD[column.Name] == null)
					{
						continue;
					}
					SortFlags sortFlags = ((0G2 == SortFlags.UseColSort) ? column.Sort : 0G2);
					if ((sortFlags & (SortFlags.Ascending | SortFlags.Descending)) != SortFlags.None)
					{
						string text2 = column.Name;
						if (text2.IndexOf(" ") > -1)
						{
							text2 = "[" + text2 + "]";
						}
						if (text.Length > 0)
						{
							text += ", ";
						}
						text += text2;
						if ((sortFlags & SortFlags.Descending) != SortFlags.None)
						{
							text += " DESC";
						}
					}
				}
				dataView.Sort = text;
				return true;
			}
			if (QC == null || !QC.SupportsSorting)
			{
				return false;
			}
			bool flag = false;
			for (int i = 0G4; i >= 0G3; i--)
			{
				Column column2 = Q8.N1.PK[i];
				if ((object)column2.DataType != typeof(byte[]) && column2.Name != null && QD[column2.Name] != null)
				{
					SortFlags sortFlags2 = ((0G2 == SortFlags.UseColSort) ? column2.Sort : 0G2);
					if ((sortFlags2 & (SortFlags.Ascending | SortFlags.Descending)) != SortFlags.None)
					{
						ListSortDirection direction = (((sortFlags2 & SortFlags.Ascending) == 0) ? ListSortDirection.Descending : ListSortDirection.Ascending);
						QC.ApplySort(QD[column2.Name], direction);
						flag = true;
					}
				}
			}
			if (!flag)
			{
				QC.RemoveSort();
			}
			return true;
		}

		private void AG(object 0G5, EventArgs 0G6)
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			A3(null, new BindingMemberInfo(""), 0FP: true);
		}

		private void AH(object 0G7, ListChangedEventArgs 0G8)
		{
			bool flag = false;
			switch (0G8.ListChangedType)
			{
			case ListChangedType.ItemChanged:
			{
				int num = AL(0G8.NewIndex);
				if (num >= 0)
				{
					Q8.N1.8F(GridChangedTypeEnum.RepaintCell, num, -1);
					flag = true;
					break;
				}
				goto case ListChangedType.Reset;
			}
			case ListChangedType.ItemAdded:
			{
				if (((BindingManagerBase)QA).Count == QG)
				{
					return;
				}
				RowCollection rows = Q8.Rows;
				int num = AL(0G8.NewIndex);
				if (num < 0)
				{
					num = rows.Count;
					if (Q8.X1.9N())
					{
						num--;
					}
				}
				rows.DX(num, 0L7: false);
				if (rows[num].DataIndex == 0G8.NewIndex)
				{
					flag = true;
					break;
				}
				goto case ListChangedType.Reset;
			}
			case ListChangedType.ItemDeleted:
			{
				int num = AL(0G8.NewIndex);
				if (num >= 0)
				{
					Q8.Rows.DZ(num, 0LC: false);
					AJ(this, null);
					flag = true;
					break;
				}
				goto case ListChangedType.Reset;
			}
			case ListChangedType.ItemMoved:
			{
				int num = AL(0G8.NewIndex);
				int num2 = AL(0G8.OldIndex);
				if (num >= 0 && num2 >= 0)
				{
					int row = Q8.Row;
					Q8.Rows.E0(num2, num, 0LF: false);
					AJ(this, null);
					if (row == num && Q8.Row != row)
					{
						Q8.Row = row;
					}
					flag = true;
					break;
				}
				goto case ListChangedType.Reset;
			}
			case ListChangedType.Reset:
			{
				QH = false;
				Q8.N2.C9();
				bool redraw = Q8.Redraw;
				Q8.Redraw = false;
				try
				{
					RowCollection rows = Q8.Rows;
					int num3 = (Q8.X1.9N() ? 1 : 0);
					bool flag2 = rows.Count > rows.Fixed + num3;
					int num4 = rows.Fixed + ((BindingManagerBase)QA).Count;
					if (Q8.Rows.Count != num4 + num3 || rows.XG > -1)
					{
						int frozen = Q8.Rows.Frozen;
						rows.DW(rows.Fixed, 0L5: false);
						rows.DW(num4, 0L5: false);
						Q8.Rows.Frozen = frozen;
					}
					AJ(this, null);
					bool flag3 = rows.Count > rows.Fixed;
					if (!flag2 && flag3 && Q8.AutoResize)
					{
						Q8.AutoSizeCols();
					}
				}
				finally
				{
					Q8.Redraw = redraw;
				}
				flag = true;
				break;
			}
			case ListChangedType.PropertyDescriptorAdded:
				QD = ((BindingManagerBase)QA).GetItemProperties();
				A5(QD[QD.Count - 1]);
				flag = true;
				break;
			case ListChangedType.PropertyDescriptorDeleted:
			{
				PropertyDescriptorCollection itemProperties = ((BindingManagerBase)QA).GetItemProperties();
				int i;
				for (i = 0; i < itemProperties.Count && QD[i].Equals(itemProperties[i]); i++)
				{
				}
				Column column = Q8.Cols[QD[i].Name];
				if (column != null)
				{
					Q8.Cols.Remove(column.Index);
					QD = itemProperties;
					flag = true;
				}
				break;
			}
			}
			QG = ((BindingManagerBase)QA).Count;
			A7();
			if (!flag)
			{
				A2(Q8, 0FM: true);
			}
			else
			{
				Q8.OnDataRefresh(0G8);
			}
		}

		private void AI(object 0G9, ItemChangedEventArgs 0GA)
		{
			if (0GA.Index < 0)
			{
				if (QC != QA.List)
				{
					if (QC != null && QC.SupportsChangeNotification)
					{
						QC.ListChanged -= AH;
					}
					QC = QA.List as IBindingList;
					if (QC != null && QC.SupportsChangeNotification)
					{
						QC.ListChanged += AH;
					}
					ListChangedEventArgs 0G10 = new ListChangedEventArgs(ListChangedType.Reset, -1, -1);
					AH(this, 0G10);
				}
			}
			else if (QC == null || !QC.SupportsChangeNotification)
			{
				ListChangedEventArgs 0G11 = new ListChangedEventArgs(ListChangedType.ItemChanged, 0GA.Index, 0GA.Index);
				AH(this, 0G11);
			}
		}

		private void AJ(object 0GB, EventArgs 0GC)
		{
			int position = ((BindingManagerBase)QA).Position;
			if (position < 0)
			{
				Q8.Row = -1;
				return;
			}
			int row = Q8.Row;
			int num = AL(position);
			if (num >= 0 && row != num)
			{
				Q8.Select(num, Q8.Col);
			}
		}

		internal void AK()
		{
			int position = ((BindingManagerBase)QA).Position;
			int num = AM(Q8.Row);
			if (num < 0 || position == num)
			{
				return;
			}
			try
			{
				if (((BindingManagerBase)QA).Position > -1)
				{
					((BindingManagerBase)QA).EndCurrentEdit();
				}
				((BindingManagerBase)QA).Position = num;
			}
			catch (Exception 11)
			{
				AJ(this, null);
				Q8.N2.C9();
				Q8.72(Q8.Row, Q8.Col, 11, 098: true);
				Q8.X1.9U(Q8);
			}
		}

		internal int AL(int 0GD)
		{
			if (0GD < 0)
			{
				return -1;
			}
			RowCollection rows = Q8.Rows;
			rows.Update();
			for (int i = 0GD + rows.Fixed; i < rows.Count; i++)
			{
				if (rows[i].TU == 0GD)
				{
					return i;
				}
			}
			return -1;
		}

		internal int AM(int 0GE)
		{
			if (0GE < 0)
			{
				return -1;
			}
			int dataIndex = Q8.Rows[0GE].DataIndex;
			if (dataIndex >= ((BindingManagerBase)QA).Count)
			{
				return -1;
			}
			return dataIndex;
		}

		internal int AN(string 0GF)
		{
			if (0GF == null)
			{
				return -1;
			}
			PropertyDescriptor propertyDescriptor = QD[0GF];
			if (propertyDescriptor == null)
			{
				return -1;
			}
			return QD.IndexOf(propertyDescriptor);
		}

		internal void AO()
		{
			throw new Exception("Invalid action when bound.");
		}

		internal string AP(int 0GG, int 0GH)
		{
			int num = AM(0GG);
			if (num < 0 || 0GH < 0)
			{
				return null;
			}
			if (!(QA.List[num] is IDataErrorInfo dataErrorInfo))
			{
				return null;
			}
			string name = Q8.Cols[0GH].Name;
			if (name != null && name.Length > 0)
			{
				string text = dataErrorInfo[name];
				if (text.Length != 0)
				{
					return text;
				}
				return null;
			}
			if (0GH == 0 && Q8.Cols.Fixed > 0)
			{
				string error = dataErrorInfo.Error;
				if (error.Length != 0)
				{
					return error;
				}
				return null;
			}
			return null;
		}

		internal void AQ(MouseEventArgs 0GI)
		{
			//IL_0084: Unknown result type (might be due to invalid IL or missing references)
			//IL_008e: Expected O, but got Unknown
			Point cellAt = Q8.GetCellAt(0GI.X, 0GI.Y);
			string text = AP(cellAt.Y, cellAt.X);
			if (text != null)
			{
				Rectangle cellRect = Q8.GetCellRect(cellAt.Y, cellAt.X, show: false);
				int width = Q8.N1.8A(GlyphEnum.ErrorInfo).Width;
				if (0GI.X > cellRect.X + width + 4)
				{
					text = null;
				}
			}
			if (text != null)
			{
				if (QI == null)
				{
					try
					{
						QI = new ToolTip();
						QI.InitialDelay = 1;
					}
					catch
					{
					}
				}
				if (QI != null && text != QI.GetToolTip((Control)(object)Q8))
				{
					QI.SetToolTip((Control)(object)Q8, text);
				}
			}
			else if (QI != null)
			{
				QI.RemoveAll();
				((Component)(object)QI).Dispose();
				QI = null;
			}
		}

		public int AR()
		{
			return AM(Q8.TopRow);
		}

		public int AS()
		{
			return AM(Q8.BottomRow) - AM(Q8.TopRow);
		}

		public void AT(int 0GJ, int 0GK)
		{
			int count = QA.List.Count;
			if (0GK != count)
			{
				0GJ *= count / 0GK;
			}
			if (0GJ >= count)
			{
				0GJ = count;
			}
			Q8.TopRow = AL(0GJ);
			int num = AM(Q8.TopRow);
			if (num != ((BindingManagerBase)QA).Position)
			{
				((BindingManagerBase)QA).Position = Q8.TopRow;
			}
		}
	}
	public enum DropModeEnum
	{
		None,
		Manual,
		Automatic
	}
	public enum DragModeEnum
	{
		Manual,
		Automatic,
		AutomaticCopy,
		AutomaticMove
	}
	internal class 0G
	{
		private C1FlexGridBase QK;

		private DropModeEnum QL;

		private long QM = 500L;

		private long QN = 50L;

		private long QO = 500L;

		private long QP;

		private int QQ;

		private Point QR;

		public DropModeEnum X7
		{
			get
			{
				return QL;
			}
			set
			{
				QL = value;
				((Control)QK).AllowDrop = QL != DropModeEnum.None;
			}
		}

		internal 0G(C1FlexGridBase view)
		{
			QK = view;
			QL = DropModeEnum.None;
			ref Point qR = ref QR;
			qR = new Point(0, 0);
		}

		public void AU(DragEventArgs 0GM)
		{
			//IL_002a: Unknown result type (might be due to invalid IL or missing references)
			if (QL == DropModeEnum.Automatic)
			{
				0GM.Effect = (DragDropEffects)0;
				string text = B0(0GM.Data);
				if (text.Length > 0)
				{
					0GM.Effect = AZ(0GM);
				}
			}
		}

		public void AV(DragEventArgs 0GN)
		{
			//IL_000b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0020: Unknown result type (might be due to invalid IL or missing references)
			//IL_0015: Unknown result type (might be due to invalid IL or missing references)
			if (QL == DropModeEnum.Automatic)
			{
				if ((int)0GN.Effect != 0)
				{
					0GN.Effect = AZ(0GN);
				}
				if ((int)0GN.Effect != 0)
				{
					AX(0GN);
				}
			}
		}

		public void AW(DragEventArgs 0GO)
		{
			//IL_000a: Unknown result type (might be due to invalid IL or missing references)
			if (QL != DropModeEnum.Automatic || (int)0GO.AllowedEffect == 0)
			{
				return;
			}
			CellRange cellRange = QK.GetCellRange(QK.MouseRow, QK.MouseCol);
			if (cellRange.r1 >= QK.Rows.Fixed && cellRange.c1 >= QK.Cols.Fixed)
			{
				cellRange.r2 = QK.Rows.Count - 1;
				cellRange.c2 = QK.Cols.Count - 1;
				string text = B0(0GO.Data);
				if (text.Length != 0)
				{
					Size size = QK.N1.9A(cellRange, text, 0E5: true);
					cellRange.c2 = cellRange.c1 + size.Width - 1;
					cellRange.r2 = cellRange.r1 + size.Height - 1;
					QK.Select(cellRange, show: false);
					0H.QV = QK.N1;
				}
			}
		}

		private void AX(DragEventArgs 0GP)
		{
			//IL_0002: Unknown result type (might be due to invalid IL or missing references)
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Unknown result type (might be due to invalid IL or missing references)
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0139: Unknown result type (might be due to invalid IL or missing references)
			//IL_013a: Unknown result type (might be due to invalid IL or missing references)
			//IL_013c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0140: Unknown result type (might be due to invalid IL or missing references)
			//IL_0156: Expected I4, but got Unknown
			Keys val = AY(0GP);
			if ((int)val == 0)
			{
				0GP.Effect = (DragDropEffects)(0GP.Effect & 0x7FFFFFFF);
				QP = 0L;
				return;
			}
			0GP.Effect = (DragDropEffects)(0GP.Effect | int.MinValue);
			long num = DateTime.Now.Ticks / 10000;
			if (QP == 0)
			{
				QQ = 0;
				QR.X = QK.Cols.DefaultSize / 3;
				QR.Y = QK.Rows.DefaultSize / 2;
				QP = num;
				QO = QM;
			}
			else if (num - QP >= QO)
			{
				QP = num;
				QO = QN;
				QQ++;
				if (QQ % 20 == 0 && QR.Y < 10 * QK.Rows.DefaultSize)
				{
					QR.Y += QK.Rows.DefaultSize / 2;
				}
				Point scrollPosition = QK.ScrollPosition;
				Keys val2 = val;
				switch (val2 - 37)
				{
				case 0:
					scrollPosition.X += QR.X;
					break;
				case 2:
					scrollPosition.X -= QR.X;
					break;
				case 1:
					scrollPosition.Y += QR.Y;
					break;
				case 3:
					scrollPosition.Y -= QR.Y;
					break;
				}
				QK.ScrollPosition = scrollPosition;
			}
		}

		private Keys AY(DragEventArgs 0GQ)
		{
			int num = 10;
			Rectangle scrollableRectangle = QK.ScrollableRectangle;
			scrollableRectangle.Inflate(1, 1);
			Point point = new Point(0GQ.X, 0GQ.Y);
			point = ((Control)QK).PointToClient(point);
			if (scrollableRectangle.Contains(point))
			{
				if (point.X <= scrollableRectangle.Left + num)
				{
					return (Keys)37;
				}
				if (point.X >= scrollableRectangle.Right - num)
				{
					return (Keys)39;
				}
				if (point.Y <= scrollableRectangle.Top + num)
				{
					return (Keys)38;
				}
				if (point.Y >= scrollableRectangle.Bottom - num)
				{
					return (Keys)40;
				}
			}
			return (Keys)0;
		}

		private DragDropEffects AZ(DragEventArgs 0GR)
		{
			//IL_0016: Unknown result type (might be due to invalid IL or missing references)
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0019: Invalid comparison between Unknown and I4
			//IL_0027: Unknown result type (might be due to invalid IL or missing references)
			//IL_0029: Invalid comparison between Unknown and I4
			//IL_001b: Unknown result type (might be due to invalid IL or missing references)
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_003f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			DragDropEffects val = (DragDropEffects)(((0GR.KeyState & 8) != 0) ? 1 : 2);
			if ((int)val == 2 && (val & 0GR.AllowedEffect) == 0)
			{
				val = (DragDropEffects)1;
			}
			if ((int)val == 2 && 0GR.Data.GetDataPresent("FileDrop"))
			{
				val = (DragDropEffects)1;
			}
			return val;
		}

		private string B0(IDataObject 0GS)
		{
			if (0GS.GetDataPresent("Text"))
			{
				return (string)0GS.GetData("Text");
			}
			if (0GS.GetDataPresent("FileDrop"))
			{
				string[] array = (string[])0GS.GetData("FileDrop");
				string text = "";
				for (int i = 0; i < array.Length; i++)
				{
					if (i > 0)
					{
						text += "\r\n";
					}
					text += array[i];
				}
				return text;
			}
			return null;
		}
	}
	internal class 0H
	{
		private const int QS = 3;

		private C1FlexGridBase QT;

		private DragModeEnum QU;

		internal static 0D QV;

		public DragModeEnum X8
		{
			get
			{
				return QU;
			}
			set
			{
				QU = value;
			}
		}

		internal 0H(C1FlexGridBase view)
		{
			QT = view;
			QU = DragModeEnum.Manual;
		}

		public bool B1(MouseEventArgs 0GU)
		{
			if (QU == DragModeEnum.Manual)
			{
				return false;
			}
			if (!((Control)QT).Focused)
			{
				return false;
			}
			Point cellAt = QT.GetCellAt(0GU.X, 0GU.Y);
			if (cellAt.Y < QT.Rows.Fixed || cellAt.X < QT.Cols.Fixed)
			{
				return false;
			}
			Rectangle rectangle = new Rectangle(-100, -100, -100, -100);
			if (QT.SelectionMode == SelectionModeEnum.ListBox)
			{
				if (QT.Rows[cellAt.Y].Selected)
				{
					rectangle = QT.GetCellRect(cellAt.Y, cellAt.X, show: false);
				}
			}
			else
			{
				CellRange selection = QT.Selection;
				Rectangle cellRect = QT.GetCellRect(selection.r1, selection.c1, show: false);
				Rectangle cellRect2 = QT.GetCellRect(selection.r2, selection.c2, show: false);
				rectangle = Rectangle.Union(cellRect, cellRect2);
			}
			if (!rectangle.Contains(0GU.X, 0GU.Y))
			{
				return false;
			}
			rectangle.Inflate(-3, -3);
			if (rectangle.Contains(0GU.X, 0GU.Y))
			{
				return false;
			}
			return true;
		}

		public void B2(MouseEventArgs 0GV)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0025: Unknown result type (might be due to invalid IL or missing references)
			//IL_0029: Unknown result type (might be due to invalid IL or missing references)
			//IL_002d: Unknown result type (might be due to invalid IL or missing references)
			//IL_004b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0051: Expected O, but got Unknown
			//IL_005f: Unknown result type (might be due to invalid IL or missing references)
			//IL_006a: Unknown result type (might be due to invalid IL or missing references)
			//IL_006b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0070: Unknown result type (might be due to invalid IL or missing references)
			//IL_0071: Unknown result type (might be due to invalid IL or missing references)
			//IL_0073: Invalid comparison between Unknown and I4
			DragDropEffects 09A = (DragDropEffects)0;
			switch (QU)
			{
			case DragModeEnum.Manual:
				return;
			case DragModeEnum.Automatic:
				09A = (DragDropEffects)3;
				break;
			case DragModeEnum.AutomaticCopy:
				09A = (DragDropEffects)1;
				break;
			case DragModeEnum.AutomaticMove:
				09A = (DragDropEffects)2;
				break;
			}
			QV = null;
			CellRange selection = QT.Selection;
			IDataObject val = (IDataObject)new DataObject((object)QT.Clip);
			QT.73(val, ref 09A);
			if ((int)09A == 0)
			{
				return;
			}
			DragDropEffects val2 = ((Control)QT).DoDragDrop((object)val, 09A);
			if ((int)val2 != 2)
			{
				return;
			}
			CellRange cellRange = QT.GetCellRange(-1, -1);
			if (QV == QT.N1)
			{
				cellRange = QT.Selection;
			}
			for (int i = selection.r1; i <= selection.r2; i++)
			{
				for (int j = selection.c1; j <= selection.c2; j++)
				{
					if (!cellRange.Contains(i, j))
					{
						QT.Clear(ClearFlags.Content, i, j);
					}
				}
			}
		}
	}
	internal interface IGridEditor
	{
		void StartEditing(int row, int col, Point pt, bool dblClick);

		void StartEditing(int row, int col, char key);

		void UpdatePosition();

		bool IsValid();

		object GetContent();
	}
	internal enum 0I
	{
		QW,
		QX,
		QY,
		QZ,
		R0,
		R1,
		R2,
		R3
	}
	internal class 0J
	{
		internal C1FlexGridBase R4;

		internal int R5;

		internal int R6;

		internal bool R7;

		internal IGridEditor R8;

		internal IGridEditor R9;

		internal IGridEditor RA;

		internal IGridEditor RB;

		internal 0J(C1FlexGridBase view)
		{
			R4 = view;
		}

		internal bool B3(int 0GW, int 0GX, char 0GY)
		{
			return B4(0GW, 0GX, 0GY, 0H2: false);
		}

		internal bool B4(int 0GZ, int 0H0, char 0H1, bool 0H2)
		{
			bool flag = R4.6Z(0GZ, 0H0);
			if (!0H2 && !flag)
			{
				return false;
			}
			if (R4.NG == ShowButtonsEnum.WhenEditing)
			{
				R4.Invalidate(0GZ, 0H0);
			}
			0I 0I2 = BB(0GZ, 0H0);
			switch (0I2)
			{
			case 0I.R1:
				if (0H1 != ' ' && 0H1 != '\r')
				{
					return false;
				}
				return B6(0GZ, 0H0);
			case 0I.R3:
				if (0H1 != ' ' && 0H1 != '\r')
				{
					return false;
				}
				return B7(0GZ, 0H0);
			default:
			{
				RowColEventArgs e = new RowColEventArgs(0GZ, 0H0);
				if (0I2 == 0I.QZ && 0H1 <= ' ')
				{
					R4.OnStartEdit(e);
					if (e.Cancel)
					{
						return false;
					}
					R4.Invalidate(e.Row, e.Col);
					R4.OnCellButtonClick(e);
					R4.OnAfterEdit(e);
					return true;
				}
				R4.OnStartEdit(e);
				if (e.Cancel)
				{
					return false;
				}
				if (!BD(0GZ, 0H0))
				{
					return false;
				}
				R8.StartEditing(0GZ, 0H0, 0H1);
				return true;
			}
			}
		}

		internal bool B5(int 0H3, int 0H4, Point 0H5, bool 0H6)
		{
			if (R4.Editor != null)
			{
				return false;
			}
			if (!R4.6Z(0H3, 0H4))
			{
				return false;
			}
			if (R4.NG == ShowButtonsEnum.WhenEditing)
			{
				R4.Invalidate(0H3, 0H4);
			}
			0I 0I2 = BB(0H3, 0H4);
			Rectangle cellRectDisplay = R4.GetCellRectDisplay(0H3, 0H4);
			RowColEventArgs e = new RowColEventArgs(0H3, 0H4);
			if (!0H6)
			{
				switch (0I2)
				{
				case 0I.QZ:
				case 0I.R0:
					if (!BC(cellRectDisplay).Contains(0H5))
					{
						return false;
					}
					if (!R4.Selection.Contains(0H3, 0H4))
					{
						R4.Select(0H3, 0H4, show: false);
					}
					R4.OnStartEdit(e);
					if (e.Cancel)
					{
						return false;
					}
					R4.Invalidate(e.Row, e.Col);
					R4.OnCellButtonClick(e);
					R4.OnAfterEdit(e);
					return true;
				case 0I.QY:
				case 0I.R2:
					if (!BC(cellRectDisplay).Contains(0H5))
					{
						return false;
					}
					if (!R4.Selection.Contains(0H3, 0H4))
					{
						R4.Select(0H3, 0H4, show: false);
					}
					R4.OnStartEdit(e);
					if (e.Cancel)
					{
						return false;
					}
					if (!BD(0H3, 0H4))
					{
						return false;
					}
					R8.StartEditing(0H3, 0H4, 0H5, 0H6);
					return true;
				case 0I.R1:
				{
					Style styleDisplay = R4.GetStyleDisplay(0H3, 0H4);
					if (!R4.7R(0H3, 0H4, styleDisplay, cellRectDisplay).Contains(0H5))
					{
						return false;
					}
					if (!R4.Selection.Contains(0H3, 0H4) && !R4.Rows[0H3].Selected && !R4.IsCellFixed(0H3, 0H4))
					{
						R4.Select(0H3, 0H4, show: false);
					}
					B6(0H3, 0H4);
					return true;
				}
				default:
					return false;
				}
			}
			switch (0I2)
			{
			case 0I.R1:
				return false;
			case 0I.R3:
				return B7(0H3, 0H4);
			default:
				R4.OnStartEdit(e);
				if (e.Cancel)
				{
					return false;
				}
				if (!BD(0H3, 0H4))
				{
					return false;
				}
				R8.StartEditing(0H3, 0H4, 0H5, 0H6);
				return true;
			}
		}

		internal bool B6(int 0H7, int 0H8)
		{
			CheckEnum checkEnum = R4.7P(0H7, 0H8);
			if (checkEnum == CheckEnum.None)
			{
				return false;
			}
			bool flag = R4.SelectionMode == SelectionModeEnum.ListBox;
			RowColEventArgs e;
			if (flag && R4.Rows[0H7].Selected)
			{
				for (int i = R4.Rows.Fixed; i < R4.Rows.Count; i++)
				{
					if (R4.Rows[i].Selected && R4.GetCellCheck(i, 0H8) != CheckEnum.None)
					{
						e = new RowColEventArgs(i, 0H8);
						if (R4.71(e))
						{
							R4.SetCellCheckEdit(i, 0H8, checkEnum);
							R4.OnAfterEdit(e);
						}
					}
				}
				return true;
			}
			CellRange selection = R4.Selection;
			if (!flag && selection.Contains(0H7, 0H8))
			{
				for (int j = selection.r1; j <= selection.r2; j++)
				{
					for (int k = selection.c1; k <= selection.c2; k++)
					{
						if (R4.GetCellCheck(j, k) != CheckEnum.None)
						{
							e = new RowColEventArgs(j, 0H8);
							if (R4.71(e))
							{
								R4.SetCellCheckEdit(j, k, checkEnum);
								R4.OnAfterEdit(e);
							}
						}
					}
				}
				return true;
			}
			e = new RowColEventArgs(0H7, 0H8);
			if (!R4.71(e))
			{
				return false;
			}
			R4.SetCellCheckEdit(0H7, 0H8, checkEnum);
			R4.OnAfterEdit(e);
			return true;
		}

		internal bool B7(int 0H9, int 0HA)
		{
			RowColEventArgs e = new RowColEventArgs(0H9, 0HA);
			if (!R4.71(e))
			{
				return false;
			}
			object obj = R4.GetData(0H9, 0HA);
			if (obj == null || !(obj is bool))
			{
				obj = false;
			}
			R4.SetDataEdit(0H9, 0HA, !(bool)obj, coerce: true);
			R4.OnAfterEdit(e);
			return true;
		}

		internal void B8()
		{
			if (R8 != null)
			{
				R8.UpdatePosition();
			}
		}

		internal bool B9()
		{
			return R8 != null;
		}

		internal bool BA(bool 0HB)
		{
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_001d: Expected O, but got Unknown
			R7 = false;
			if (!B9())
			{
				return true;
			}
			Control val = (Control)R8;
			if (!0HB && R4.70(R5, R6, R8.IsValid()))
			{
				R4.ShowCell(R5, R6);
				R7 = true;
				return false;
			}
			object data = ((R8 != null) ? R8.GetContent() : null);
			R8 = null;
			if (val.Focused)
			{
				((Control)R4).Focus();
			}
			val.Visible = false;
			if (!0HB)
			{
				R4.SetDataEdit(R5, R6, data, coerce: true);
				R4.OnAfterEdit(new RowColEventArgs(R5, R6));
			}
			if (!((Control)R4).Focused && R4.N1.9H())
			{
				R4.N1.PO.AB();
			}
			return true;
		}

		internal 0I BB(int 0HC, int 0HD)
		{
			if (R4.GetCellCheck(0HC, 0HD) != CheckEnum.None)
			{
				return 0I.R1;
			}
			if (R4.IsCellFixed(0HC, 0HD))
			{
				return 0I.QX;
			}
			string text = R4.N1.8Z(0HC, 0HD);
			if (text != null && text.Length > 0)
			{
				if (text == "...")
				{
					return 0I.QZ;
				}
				if (text == "|...")
				{
					return 0I.R0;
				}
				return 0I.QY;
			}
			if (R4.N1.91(0HC, 0HD) != null)
			{
				return 0I.QY;
			}
			Type type = R4.N1.8X(0HC, 0HD);
			if ((object)type != null && type.IsEnum)
			{
				return 0I.QY;
			}
			if ((object)type == typeof(DateTime))
			{
				string text2 = R4.N1.90(0HC, 0HD);
				if (text2 == null || text2.Length == 0)
				{
					text2 = R4.EditMask;
				}
				if (text2 == null || text2.Length == 0)
				{
					return 0I.R2;
				}
			}
			if ((object)R4.N1.8X(0HC, 0HD) == typeof(bool))
			{
				string text3 = R4.N1.8Y(0HC, 0HD, 0DG: false);
				if (text3 != null && text3.Length > 0)
				{
					return 0I.R3;
				}
			}
			return 0I.QX;
		}

		internal virtual Rectangle BC(Rectangle 0HE)
		{
			int verticalScrollBarWidth = SystemInformation.VerticalScrollBarWidth;
			Rectangle result = new Rectangle(0HE.X, 0HE.Y, 0, 0HE.Height);
			if (0HE.Width > verticalScrollBarWidth && 0HE.Height > 5)
			{
				result.X = 0HE.Right - verticalScrollBarWidth;
				result.Width = verticalScrollBarWidth;
			}
			return result;
		}

		internal virtual bool BD(int 0HF, int 0HG)
		{
			//IL_0112: Unknown result type (might be due to invalid IL or missing references)
			//IL_011d: Unknown result type (might be due to invalid IL or missing references)
			0I 0I2 = BB(0HF, 0HG);
			if (0I2 == 0I.QW)
			{
				return false;
			}
			BA(0HB: false);
			R4.N2.C9();
			Control val = null;
			switch (0I2)
			{
			case 0I.QX:
			case 0I.R0:
				if (R9 == null)
				{
					val = (Control)(object)new 0L(R4);
					R9 = (IGridEditor)val;
				}
				R8 = R9;
				break;
			case 0I.QY:
				if (RA == null)
				{
					val = (Control)(object)new GridEditorComboBox(R4);
					RA = (IGridEditor)val;
				}
				R8 = RA;
				break;
			case 0I.R2:
				if (RB == null)
				{
					val = (Control)(object)new 0K(R4);
					RB = (IGridEditor)val;
				}
				R8 = RB;
				break;
			}
			if (val != null)
			{
				val.Visible = false;
				((Control)R4).Controls.Add(val);
				val.Leave += BE;
			}
			if (R8 != null)
			{
				((Control)R8).ImeMode = ((Control)R4).ImeMode;
			}
			R5 = 0HF;
			R6 = 0HG;
			return R8 != null;
		}

		private void BE(object 0HH, EventArgs 0HI)
		{
			BA(0HB: false);
		}
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	internal class GridEditorComboBox : MaskedComboBox, IGridEditor
	{
		internal C1FlexGridBase _view;

		internal int _row;

		internal int _col;

		internal bool _fireEvents;

		internal Type _enumType;

		internal SizeF _itemSize;

		internal CellStyle _cellStyle;

		internal bool _wasDown;

		private int _pos = 0;

		private bool _dotNet11 = false;

		private static string _buf = "";

		private static long _lastCharTicks = 0L;

		internal GridEditorComboBox(C1FlexGridBase view)
		{
			_row = (_col = -1);
			_view = view;
			ref SizeF itemSize = ref _itemSize;
			itemSize = new SizeF(0f, 0f);
			_wasDown = false;
		}

		public void StartEditing(int row, int col, Point pt, bool dblClick)
		{
			InitEditor(row, col);
			((Control)this).Text = _view.N1.GetDataDisplay(row, col);
			if (dblClick && ((ComboBox)this).Items.Count > 0)
			{
				int selectedIndex = ((ListControl)this).SelectedIndex;
				if (selectedIndex > -1 || !IsCombo())
				{
					((ListControl)this).SelectedIndex = (selectedIndex + 1) % ((ComboBox)this).Items.Count;
					if (_view.FinishEditing())
					{
						return;
					}
				}
			}
			((Control)this).Visible = true;
			((ComboBox)this).DroppedDown = true;
			((Control)this).Focus();
			_pos = ((ComboBox)this).SelectionStart;
			_fireEvents = true;
			_view.OnChangeEdit(EventArgs.Empty);
		}

		public void StartEditing(int row, int col, char key)
		{
			InitEditor(row, col);
			((Control)this).Visible = true;
			((Control)this).Focus();
			if (key <= ' ')
			{
				string dataDisplay = _view.N1.GetDataDisplay(row, col);
				((ListControl)this).SelectedIndex = ((ComboBox)this).FindString(dataDisplay);
				if (((ListControl)this).SelectedIndex < 0)
				{
					if (IsCombo())
					{
						((Control)this).Text = dataDisplay;
					}
					else if (((ComboBox)this).Items.Count > 0)
					{
						((ListControl)this).SelectedIndex = 0;
					}
				}
				((ComboBox)this).Select(0, 32000);
				if (key == '\r')
				{
					((ComboBox)this).DroppedDown = true;
				}
			}
			else
			{
				((ListControl)this).SelectedIndex = ((ComboBox)this).FindString(key.ToString(CultureInfo.CurrentCulture));
				if (IsCombo())
				{
					int num = EditPosition(0);
					if (((ListControl)this).SelectedIndex < 0)
					{
						((Control)this).Text = ((((Control)this).Text.Length > 0) ? (((Control)this).Text.Substring(0, num) + key + ((Control)this).Text.Substring(num + 1)) : key.ToString(CultureInfo.CurrentCulture));
						if (num < ((Control)this).Text.Length && char.ToLower(((Control)this).Text[num], CultureInfo.CurrentCulture) == char.ToLower(key, CultureInfo.CurrentCulture))
						{
							num = EditPosition(1);
						}
					}
					else
					{
						num = EditPosition(1);
					}
					((ComboBox)this).Select(num, 32000);
				}
				else if (((ListControl)this).SelectedIndex < 0 && ((ComboBox)this).Items.Count > 0)
				{
					((ListControl)this).SelectedIndex = 0;
				}
			}
			_pos = ((ComboBox)this).SelectionStart;
			_fireEvents = true;
			_view.OnChangeEdit(EventArgs.Empty);
		}

		public void UpdatePosition()
		{
			Rectangle cellRectEditor = _view.GetCellRectEditor(_row, _col);
			if (cellRectEditor.Height <= 6 || cellRectEditor.Width <= 6)
			{
				((Control)this).Bounds = new Rectangle(-100, -100, 10, 10);
				return;
			}
			cellRectEditor.Inflate(2, 2);
			((Control)this).Bounds = cellRectEditor;
			((ComboBox)this).ItemHeight = cellRectEditor.Height - 6;
			((ComboBox)this).DrawMode = (DrawMode)((!((float)(cellRectEditor.Height - 6) > _itemSize.Height)) ? 1 : 2);
		}

		private void InitEditor(int row, int col)
		{
			//IL_0379: Unknown result type (might be due to invalid IL or missing references)
			//IL_037f: Invalid comparison between Unknown and I4
			_row = row;
			_col = col;
			_view.ShowCell(row, col);
			((ComboBox)this).DropDownStyle = (ComboBoxStyle)2;
			_wasDown = false;
			((ComboBox)this).Items.Clear();
			string text = _view.N1.8Z(row, col);
			if (((ComboBox)this).Items.Count == 0 && text != null && text.Length > 0)
			{
				if (text[0] == '|')
				{
					((ComboBox)this).DropDownStyle = (ComboBoxStyle)1;
				}
				string[] array = text.Split(new char[1] { '|' });
				foreach (string text2 in array)
				{
					if (text2.Length > 0)
					{
						((ComboBox)this).Items.Add((object)text2);
					}
				}
			}
			System.Collections.IDictionary dictionary = _view.N1.91(row, col);
			if (((ComboBox)this).Items.Count == 0 && dictionary != null)
			{
				foreach (object key in dictionary.Keys)
				{
					if (dictionary[key] != null)
					{
						((ComboBox)this).Items.Add((object)dictionary[key].ToString());
					}
				}
			}
			_enumType = null;
			if (((ComboBox)this).Items.Count == 0)
			{
				Type type = _view.N1.8X(row, col);
				if ((object)type != null && type.IsEnum)
				{
					_enumType = type;
					foreach (object value in Enum.GetValues(_enumType))
					{
						((ComboBox)this).Items.Add((object)value.ToString());
					}
				}
			}
			_cellStyle = _view.GetCellStyleDisplay(row, col);
			((Control)this).Font = _cellStyle.Font;
			Graphics val = ((Control)this).CreateGraphics();
			try
			{
				int num = Math.Max(_view.Cols.DefaultSize, _view.Cols[_col].WidthDisplay);
				int num2 = Math.Max(_view.Rows.DefaultSize, _view.Rows[_row].HeightDisplay);
				foreach (object item in ((ComboBox)this).Items)
				{
					SizeF sizeF = val.MeasureString(item.ToString(), ((Control)this).Font);
					if (sizeF.Width > (float)num)
					{
						num = (int)sizeF.Width;
					}
				}
				_itemSize.Height = num2;
				_itemSize.Width = num + SystemInformation.VerticalScrollBarWidth + 10;
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
			_fireEvents = false;
			((Control)this).BackColor = Color.FromArgb(255, _cellStyle.BackColor);
			((Control)this).ForeColor = Color.FromArgb(255, _cellStyle.ForeColor);
			((ComboBox)this).DrawMode = (DrawMode)1;
			((ComboBox)this).ItemHeight = (int)_itemSize.Height;
			((ComboBox)this).DropDownWidth = (int)_itemSize.Width;
			base.Mask = _view.N1.90(row, col);
			((Control)this).Text = "";
			if ((int)((Control)_view).RightToLeft == 1)
			{
				((ComboBox)this).DrawMode = (DrawMode)0;
			}
			UpdatePosition();
			_view.OnSetupEditor(new RowColEventArgs(row, col));
		}

		public object GetContent()
		{
			return GetContent(((ListControl)this).SelectedIndex);
		}

		public object GetContent(int index)
		{
			if (index < 0)
			{
				return GetValidContent();
			}
			string text = ((ComboBox)this).Items[index].ToString();
			System.Collections.IDictionary dictionary = _view.N1.91(_row, _col);
			if (dictionary != null)
			{
				foreach (object key in dictionary.Keys)
				{
					if (dictionary[key] != null && dictionary[key].ToString() == text)
					{
						return key;
					}
				}
			}
			if ((object)_enumType != null)
			{
				foreach (object value in Enum.GetValues(_enumType))
				{
					if (Enum.GetName(_enumType, value) == text)
					{
						return value;
					}
				}
			}
			return text;
		}

		protected override bool IsInputKey(Keys keyData)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Invalid comparison between Unknown and I4
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Invalid comparison between Unknown and I4
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			Keys val = (Keys)(keyData & -458753);
			if ((int)val == 13)
			{
				return true;
			}
			if ((int)val == 9)
			{
				return true;
			}
			return ((ComboBox)this).IsInputKey(keyData);
		}

		protected override void OnTextChanged(EventArgs e)
		{
			base.OnTextChanged(e);
			if (IsCombo() && ((Control)this).Visible && _fireEvents && !IsUpdating())
			{
				_fireEvents = false;
				_view.OnChangeEdit(EventArgs.Empty);
				_fireEvents = true;
			}
		}

		protected override void OnSelectedIndexChanged(EventArgs e)
		{
			if (!IsCombo() && ((Control)this).Visible && _fireEvents && !IsUpdating())
			{
				_fireEvents = false;
				_view.OnChangeEdit(EventArgs.Empty);
				_fireEvents = true;
			}
		}

		protected override void OnSelectionChangeCommitted(EventArgs e)
		{
			((ComboBox)this).OnSelectionChangeCommitted(e);
			RowColEventArgs e2 = new RowColEventArgs(_row, _col);
			if (((Control)this).Visible && _fireEvents && !IsUpdating() && _wasDown)
			{
				if (IsCombo() && ((ComboBox)this).SelectedItem != null)
				{
					((Control)this).Text = ((ComboBox)this).SelectedItem.ToString();
				}
				_wasDown = false;
				_view.OnComboCloseUp(e2);
				_view.FinishEditing();
			}
		}

		protected override void OnMouseUp(MouseEventArgs e)
		{
			_pos = ((ComboBox)this).SelectionStart;
			((ComboBox)this).OnMouseUp(e);
		}

		protected override void OnKeyDown(KeyEventArgs e)
		{
			//IL_0029: Unknown result type (might be due to invalid IL or missing references)
			//IL_0030: Invalid comparison between Unknown and I4
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			//IL_003a: Invalid comparison between Unknown and I4
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_0058: Unknown result type (might be due to invalid IL or missing references)
			//IL_005a: Unknown result type (might be due to invalid IL or missing references)
			//IL_005e: Invalid comparison between Unknown and I4
			//IL_0074: Unknown result type (might be due to invalid IL or missing references)
			//IL_0078: Invalid comparison between Unknown and I4
			//IL_0060: Unknown result type (might be due to invalid IL or missing references)
			//IL_0064: Invalid comparison between Unknown and I4
			//IL_007a: Unknown result type (might be due to invalid IL or missing references)
			//IL_007e: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a0: Expected I4, but got Unknown
			//IL_0069: Unknown result type (might be due to invalid IL or missing references)
			//IL_006d: Invalid comparison between Unknown and I4
			KeyEditEventArgs e2 = new KeyEditEventArgs(_row, _col, e);
			_view.OnKeyDownEdit(e2);
			if (e2.Handled)
			{
				return;
			}
			if ((int)e.KeyCode != 9 && (int)e.KeyCode != 13)
			{
				base.OnKeyDown(e);
			}
			if (e.Handled)
			{
				return;
			}
			bool flag = false;
			bool cancel = false;
			bool flag2 = true;
			Keys keyCode = e.KeyCode;
			if ((int)keyCode <= 13)
			{
				if ((int)keyCode == 9)
				{
					goto IL_00f6;
				}
				if ((int)keyCode == 13 && !e.Shift && !e.Control)
				{
					flag = true;
				}
			}
			else
			{
				if ((int)keyCode != 27)
				{
					switch (keyCode - 33)
					{
					case 4:
						flag = !IsCombo() || _pos == 0;
						goto IL_00f8;
					case 6:
						flag = !IsCombo() || _pos == ((Control)this).Text.Length;
						goto IL_00f8;
					case 0:
					case 1:
						break;
					default:
						goto IL_00f8;
					}
					goto IL_00f6;
				}
				flag = (cancel = true);
				flag2 = false;
			}
			goto IL_00f8;
			IL_00f6:
			flag = true;
			goto IL_00f8;
			IL_00f8:
			_pos = ((ComboBox)this).SelectionStart;
			if (flag)
			{
				e.Handled = true;
				if (((ComboBox)this).DroppedDown)
				{
					_view.OnComboCloseUp(new RowColEventArgs(_row, _col));
				}
				if (_view.FinishEditing(cancel) && flag2)
				{
					_view.N3.BN(e);
				}
			}
		}

		protected override void OnKeyUp(KeyEventArgs e)
		{
			KeyEditEventArgs e2 = new KeyEditEventArgs(_row, _col, e);
			_view.OnKeyUpEdit(e2);
			if (!e2.Handled)
			{
				((ComboBox)this).OnKeyUp(e);
			}
		}

		protected override void OnKeyPress(KeyPressEventArgs e)
		{
			KeyPressEditEventArgs e2 = new KeyPressEditEventArgs(_row, _col, e.KeyChar);
			_view.OnKeyPressEdit(e2);
			if (e2.Handled)
			{
				e.Handled = true;
				return;
			}
			base.OnKeyPress(e);
			if (!e.Handled)
			{
				e.Handled = e.KeyChar == '\r' || e.KeyChar == '\u001b' || e.KeyChar == '\t';
				if (!e.Handled)
				{
					e.Handled = AutoSearch(e.KeyChar);
				}
			}
		}

		protected override void OnDrawItem(DrawItemEventArgs e)
		{
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0044: Unknown result type (might be due to invalid IL or missing references)
			//IL_004a: Expected O, but got Unknown
			//IL_00db: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b1: Expected O, but got Unknown
			if (e.Index < 0)
			{
				return;
			}
			Style style = _cellStyle.VA;
			if ((e.State & 1) != 0)
			{
				style = _view.N1.8M(CellStyleEnum.Highlight).4O(style, 04C: false);
			}
			Brush val = (Brush)style.4V("BackColor");
			e.Graphics.FillRectangle(val, e.Bounds);
			Image 11 = null;
			System.Collections.IDictionary dictionary = _view.N1.92(_row, _col);
			if (dictionary != null)
			{
				object content = GetContent(e.Index);
				if (content != null && content != DBNull.Value && dictionary.Contains(content))
				{
					11 = (Image)dictionary[content];
				}
			}
			style.56(e.Graphics, e.Bounds, (string)((ComboBox)this).Items[e.Index], 11);
			if ((e.State & 0x10) != 0)
			{
				ControlPaint.DrawFocusRectangle(e.Graphics, e.Bounds);
			}
		}

		protected override void OnMeasureItem(MeasureItemEventArgs e)
		{
			e.ItemHeight = (int)_itemSize.Height;
			e.ItemWidth = (int)_itemSize.Width;
		}

		protected override void OnDropDown(EventArgs e)
		{
			((ComboBox)this).OnDropDown(e);
			_view.OnComboDropDown(new RowColEventArgs(_row, _col));
			_wasDown = true;
		}

		private bool AutoSearch(char chr)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_0009: Unknown result type (might be due to invalid IL or missing references)
			//IL_0017: Expected I4, but got Unknown
			ComboBoxStyle dropDownStyle = ((ComboBox)this).DropDownStyle;
			return (dropDownStyle - 1) switch
			{
				0 => AutoSearchCombo(chr), 
				1 => AutoSearchList(chr), 
				_ => false, 
			};
		}

		private bool AutoSearchCombo(char chr)
		{
			if (chr < ' ')
			{
				return false;
			}
			string text = ((Control)this).Text;
			if (_dotNet11 || ((ComboBox)this).SelectionLength > 0 || (text.Length > 0 && text[text.Length - 1] != chr))
			{
				_dotNet11 = true;
				text = text.Substring(0, ((ComboBox)this).SelectionStart) + chr;
			}
			int num = ((ComboBox)this).FindString(text);
			if (num < 0)
			{
				return false;
			}
			((ListControl)this).SelectedIndex = num;
			((ComboBox)this).Select(text.Length, 32000);
			return true;
		}

		private bool AutoSearchList(char chr)
		{
			if (AutoSearchListBuffer(chr))
			{
				return true;
			}
			_buf = "";
			return false;
		}

		private bool AutoSearchListBuffer(char chr)
		{
			if (chr < ' ')
			{
				return false;
			}
			long ticks = DateTime.Now.Ticks;
			if (_buf.Length > 0)
			{
				long num = ticks - _lastCharTicks;
				if (num > 5000000)
				{
					_buf = "";
				}
			}
			_buf += chr;
			_lastCharTicks = ticks;
			int num2 = -1;
			int selectedIndex = ((ListControl)this).SelectedIndex;
			if (_buf.Length > 1 && selectedIndex > -1)
			{
				num2 = ((ComboBox)this).FindString(_buf, selectedIndex - 1);
			}
			if (num2 < 0 && selectedIndex > -1 && selectedIndex < ((ComboBox)this).Items.Count - 1)
			{
				num2 = ((ComboBox)this).FindString(_buf, selectedIndex);
			}
			if (num2 < 0)
			{
				num2 = ((ComboBox)this).FindString(_buf);
			}
			if (num2 < 0)
			{
				return false;
			}
			((ListControl)this).SelectedIndex = num2;
			return true;
		}

		public override bool PreProcessMessage(ref Message msg)
		{
			//IL_001a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0020: Expected O, but got Unknown
			//IL_0021: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Invalid comparison between Unknown and I4
			//IL_002b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0032: Invalid comparison between Unknown and I4
			int msg2 = ((Message)(ref msg)).Msg;
			if (msg2 == 256)
			{
				KeyEventArgs e = new KeyEventArgs((Keys)(int)((Message)(ref msg)).WParam);
				if ((int)e.KeyCode == 9 || (int)e.KeyCode == 13)
				{
					((Control)this).OnKeyDown(e);
					return true;
				}
			}
			return false;
		}
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	internal class 0K : DateTimePicker, IGridEditor
	{
		internal C1FlexGridBase RC;

		internal int RD;

		internal int RE;

		internal bool RF;

		internal static Hashtable RG;

		internal 0K(C1FlexGridBase view)
		{
			if (RG == null)
			{
				RG = new Hashtable();
				DateTimeFormatInfo dateTimeFormat = CultureInfo.CurrentCulture.DateTimeFormat;
				RG.Add("d", dateTimeFormat.ShortDatePattern);
				RG.Add("D", dateTimeFormat.LongDatePattern);
				RG.Add("t", dateTimeFormat.ShortTimePattern);
				RG.Add("T", dateTimeFormat.LongTimePattern);
				RG.Add("f", dateTimeFormat.LongDatePattern + " " + dateTimeFormat.ShortTimePattern);
				RG.Add("F", dateTimeFormat.FullDateTimePattern);
				RG.Add("g", dateTimeFormat.ShortDatePattern + " " + dateTimeFormat.ShortTimePattern);
				RG.Add("G", dateTimeFormat.ShortDatePattern + " " + dateTimeFormat.LongTimePattern);
				RG.Add("M", dateTimeFormat.MonthDayPattern);
				RG.Add("R", dateTimeFormat.RFC1123Pattern);
				RG.Add("s", dateTimeFormat.SortableDateTimePattern);
				RG.Add("u", dateTimeFormat.UniversalSortableDateTimePattern);
				RG.Add("U", dateTimeFormat.FullDateTimePattern);
			}
			RC = view;
			RD = (RE = -1);
		}

		public void StartEditing(int row, int col, Point pt, bool dblClick)
		{
			BF(row, col);
			((Control)this).Visible = true;
			((Control)this).Focus();
			((Control)RC).Capture = false;
			pt.X -= ((Control)this).Bounds.X;
			pt.Y = 3;
			BG(513, pt);
			BG(514, pt);
			RF = true;
			RC.OnChangeEdit(EventArgs.Empty);
		}

		public void StartEditing(int row, int col, char key)
		{
			BF(row, col);
			((Control)this).Visible = true;
			((Control)this).Focus();
			((Control)RC).Capture = false;
			if (key > ' ')
			{
				KeyPressEditEventArgs e = new KeyPressEditEventArgs(RD, RE, key);
				RC.OnKeyPressEdit(e);
				if (!e.Handled)
				{
					Point 0HM = new Point(3, 3);
					BG(513, 0HM);
					BG(514, 0HM);
					BH(258, key);
				}
			}
			if (key == '\r')
			{
				Point 0HM2 = new Point(((Control)this).Width - 5, 3);
				BG(513, 0HM2);
				BG(514, 0HM2);
			}
			RF = true;
			RC.OnChangeEdit(EventArgs.Empty);
		}

		public void UpdatePosition()
		{
			Rectangle cellRectEditor = RC.GetCellRectEditor(RD, RE);
			if (cellRectEditor.Height < 6 || cellRectEditor.Width < 6)
			{
				((Control)this).Bounds = new Rectangle(-100, -100, 10, 10);
				return;
			}
			cellRectEditor.Inflate(2, 2);
			((Control)this).Bounds = cellRectEditor;
		}

		public object GetContent()
		{
			return ((DateTimePicker)this).Value;
		}

		public bool IsValid()
		{
			return true;
		}

		private void BF(int 0HJ, int 0HK)
		{
			RD = 0HJ;
			RE = 0HK;
			RC.ShowCell(0HJ, 0HK);
			RF = false;
			((DateTimePicker)this).ShowUpDown = false;
			CellStyle cellStyleDisplay = RC.GetCellStyleDisplay(0HJ, 0HK);
			CellStyle highlight = RC.Styles.Highlight;
			((Control)this).Font = cellStyleDisplay.Font;
			((DateTimePicker)this).CalendarFont = cellStyleDisplay.Font;
			((DateTimePicker)this).CalendarMonthBackground = Color.FromArgb(255, cellStyleDisplay.BackColor);
			((DateTimePicker)this).CalendarForeColor = Color.FromArgb(255, cellStyleDisplay.ForeColor);
			((DateTimePicker)this).CalendarTrailingForeColor = ((DateTimePicker)this).CalendarForeColor;
			((DateTimePicker)this).CalendarTitleBackColor = Color.FromArgb(255, highlight.BackColor);
			((DateTimePicker)this).CalendarTitleForeColor = Color.FromArgb(255, highlight.ForeColor);
			((DateTimePicker)this).Format = (DateTimePickerFormat)2;
			string text = RC.N1.8Y(0HJ, 0HK, 0DG: true);
			if (text != null && text.Length > 0)
			{
				((DateTimePicker)this).Format = (DateTimePickerFormat)8;
				((DateTimePicker)this).CustomFormat = (RG.ContainsKey(text) ? ((string)RG[text]) : text);
			}
			UpdatePosition();
			object data = RC.N1.GetData(0HJ, 0HK);
			if (data is DateTime)
			{
				DateTime dateTime = (DateTime)data;
				if (dateTime < ((DateTimePicker)this).MinDate)
				{
					dateTime = ((DateTimePicker)this).MinDate;
				}
				if (dateTime > ((DateTimePicker)this).MaxDate)
				{
					dateTime = ((DateTimePicker)this).MaxDate;
				}
				((DateTimePicker)this).Value = dateTime;
			}
			else
			{
				((DateTimePicker)this).Value = DateTime.Today;
			}
			RC.OnSetupEditor(new RowColEventArgs(0HJ, 0HK));
		}

		protected override bool IsInputKey(Keys keyData)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Invalid comparison between Unknown and I4
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0010: Invalid comparison between Unknown and I4
			//IL_0015: Unknown result type (might be due to invalid IL or missing references)
			Keys val = (Keys)(keyData & -458753);
			if ((int)val == 9 || (int)val == 13)
			{
				return true;
			}
			return ((DateTimePicker)this).IsInputKey(keyData);
		}

		protected override void OnValueChanged(EventArgs e)
		{
			((DateTimePicker)this).OnValueChanged(e);
			if (RF)
			{
				RF = false;
				RC.OnChangeEdit(e);
				RF = true;
			}
		}

		protected override void OnKeyDown(KeyEventArgs e)
		{
			//IL_0036: Unknown result type (might be due to invalid IL or missing references)
			//IL_003b: Unknown result type (might be due to invalid IL or missing references)
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0041: Invalid comparison between Unknown and I4
			//IL_0043: Unknown result type (might be due to invalid IL or missing references)
			//IL_0047: Invalid comparison between Unknown and I4
			//IL_0049: Unknown result type (might be due to invalid IL or missing references)
			//IL_004d: Invalid comparison between Unknown and I4
			KeyEditEventArgs e2 = new KeyEditEventArgs(RD, RE, e);
			RC.OnKeyDownEdit(e2);
			if (e2.Handled)
			{
				return;
			}
			((DateTimePicker)this).OnKeyDown(e);
			bool flag = false;
			bool cancel = false;
			bool flag2 = true;
			Keys keyCode = e.KeyCode;
			if ((int)keyCode != 9 && (int)keyCode != 13)
			{
				if ((int)keyCode == 27)
				{
					flag = (cancel = true);
					flag2 = false;
				}
			}
			else
			{
				flag = true;
			}
			if (flag)
			{
				e.Handled = true;
				Point 0HM = new Point(3, 3);
				BG(513, 0HM);
				BG(514, 0HM);
				flag = RC.FinishEditing(cancel);
				if (flag)
				{
					((DateTimePicker)this).ShowUpDown = true;
				}
				if (flag && flag2)
				{
					RC.N3.BN(e);
				}
			}
		}

		protected override void OnKeyUp(KeyEventArgs e)
		{
			KeyEditEventArgs e2 = new KeyEditEventArgs(RD, RE, e);
			RC.OnKeyUpEdit(e2);
			if (!e2.Handled)
			{
				((DateTimePicker)this).OnKeyUp(e);
			}
		}

		protected override void OnKeyPress(KeyPressEventArgs e)
		{
			KeyPressEditEventArgs e2 = new KeyPressEditEventArgs(RD, RE, e.KeyChar);
			RC.OnKeyPressEdit(e2);
			if (e2.Handled)
			{
				e.Handled = true;
				return;
			}
			((DateTimePicker)this).OnKeyPress(e);
			if (!e.Handled)
			{
				e.Handled |= e.KeyChar == '\r' || e.KeyChar == '\u001b';
				e.Handled |= e.KeyChar == '☻';
			}
		}

		protected override void OnDropDown(EventArgs e)
		{
			((DateTimePicker)this).OnDropDown(e);
			RC.OnComboDropDown(new RowColEventArgs(RD, RE));
		}

		protected override void OnCloseUp(EventArgs e)
		{
			((DateTimePicker)this).OnCloseUp(e);
			RC.OnComboCloseUp(new RowColEventArgs(RD, RE));
			if (RC.FinishEditing())
			{
				((Control)RC).Focus();
			}
		}

		internal int BG(int 0HL, Point 0HM)
		{
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			Message val = Message.Create(((Control)this).Handle, 0HL, (IntPtr)0, 07.60(0HM));
			((Control)this).WndProc(ref val);
			return (int)((Message)(ref val)).Result;
		}

		internal int BH(int 0HN, int 0HO)
		{
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			Message val = Message.Create(((Control)this).Handle, 0HN, (IntPtr)0HO, (IntPtr)0);
			((Control)this).WndProc(ref val);
			return (int)((Message)(ref val)).Result;
		}
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	internal class 0L : S, IGridEditor
	{
		internal C1FlexGridBase RH;

		internal Point RI;

		internal int RJ;

		internal int RK;

		internal bool RL;

		internal 0L(C1FlexGridBase view)
		{
			RH = view;
			RJ = (RK = -1);
			ref Point rI = ref RI;
			rI = new Point(0, 0);
		}

		public void StartEditing(int row, int col, Point pt, bool dblClick)
		{
			BI(row, col);
			object data = RH.N1.GetData(row, col);
			((Control)this).Text = ((data == null) ? "" : data.ToString());
			((Control)this).Visible = true;
			((Control)this).Focus();
			pt.Offset(-RI.X, -RI.Y);
			2Y(513, pt);
			2Y(514, pt);
			RL = true;
			RH.OnChangeEdit(EventArgs.Empty);
		}

		public void StartEditing(int row, int col, char key)
		{
			BI(row, col);
			((Control)this).Visible = true;
			((Control)this).Focus();
			if (key <= ' ')
			{
				object data = RH.N1.GetData(row, col);
				string text = (((Control)this).Text = ((data == null) ? "" : data.ToString()));
				int length = text.Length;
				if (key == ' ')
				{
					((TextBoxBase)this).Select(length, 0);
				}
				else
				{
					((TextBoxBase)this).Select(0, length);
				}
			}
			else
			{
				KeyPressEditEventArgs e = new KeyPressEditEventArgs(RJ, RK, key);
				RH.OnKeyPressEdit(e);
				if (e.Handled)
				{
					RH.FinishEditing(cancel: true);
					return;
				}
				int num = 2U(0);
				((Control)this).Text = ((((Control)this).Text.Length > num) ? (((Control)this).Text.Substring(0, num) + key + ((Control)this).Text.Substring(num + 1)) : key.ToString(CultureInfo.CurrentCulture));
				if (num < ((Control)this).Text.Length && char.ToLower(((Control)this).Text[num], CultureInfo.CurrentCulture) == char.ToLower(key, CultureInfo.CurrentCulture))
				{
					num = 2U(1);
				}
				((TextBoxBase)this).Select(num, 0);
			}
			RL = true;
			RH.OnChangeEdit(EventArgs.Empty);
		}

		public void UpdatePosition()
		{
			Rectangle cellRectEditor = RH.GetCellRectEditor(RJ, RK);
			int right = cellRectEditor.Right;
			CellStyle cellStyleDisplay = RH.GetCellStyleDisplay(RJ, RK);
			cellRectEditor = cellStyleDisplay.EZ(cellRectEditor);
			0I 0I2 = RH.X0.BB(RJ, RK);
			if (0I2 == 0I.R0)
			{
				int width = right - cellRectEditor.X - SystemInformation.VerticalScrollBarWidth;
				cellRectEditor.Width = width;
			}
			((Control)this).Bounds = cellRectEditor;
			RI.X = ((Control)this).Bounds.X + cellStyleDisplay.Margins.Left;
			RI.Y = ((Control)this).Bounds.Y + cellStyleDisplay.Margins.Top;
		}

		public object GetContent()
		{
			return 2T();
		}

		private void BI(int 0HP, int 0HQ)
		{
			//IL_00d1: Unknown result type (might be due to invalid IL or missing references)
			RJ = 0HP;
			RK = 0HQ;
			RH.ShowCell(0HP, 0HQ);
			RL = false;
			((TextBoxBase)this).AutoSize = false;
			((TextBoxBase)this).BorderStyle = (BorderStyle)0;
			CellStyle cellStyleDisplay = RH.GetCellStyleDisplay(0HP, 0HQ);
			((Control)this).Font = cellStyleDisplay.Font;
			((Control)this).BackColor = Color.FromArgb(255, cellStyleDisplay.BackColor);
			((Control)this).ForeColor = Color.FromArgb(255, cellStyleDisplay.ForeColor);
			bool wordWrap = (((TextBox)this).AcceptsReturn = cellStyleDisplay.WordWrap);
			((TextBoxBase)this).WordWrap = wordWrap;
			((TextBoxBase)this).Multiline = true;
			string dataDisplay = RH.N1.GetDataDisplay(0HP, 0HQ);
			base.WK = RH.N1.90(0HP, 0HQ);
			((Control)this).Text = "";
			UpdatePosition();
			base.WJ = cellStyleDisplay.EY(dataDisplay);
			base.WI = cellStyleDisplay.Margins;
			RH.OnSetupEditor(new RowColEventArgs(0HP, 0HQ));
		}

		protected override bool IsInputKey(Keys keyData)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Invalid comparison between Unknown and I4
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0010: Invalid comparison between Unknown and I4
			//IL_0015: Unknown result type (might be due to invalid IL or missing references)
			Keys val = (Keys)(keyData & -458753);
			if ((int)val == 9 || (int)val == 13)
			{
				return true;
			}
			return ((TextBox)this).IsInputKey(keyData);
		}

		protected override void OnTextChanged(EventArgs e)
		{
			base.OnTextChanged(e);
			if (RL && !2V())
			{
				RL = false;
				RH.OnChangeEdit(e);
				RL = true;
			}
		}

		protected override void OnKeyDown(KeyEventArgs e)
		{
			//IL_003f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0044: Unknown result type (might be due to invalid IL or missing references)
			//IL_0046: Unknown result type (might be due to invalid IL or missing references)
			//IL_004a: Invalid comparison between Unknown and I4
			//IL_0060: Unknown result type (might be due to invalid IL or missing references)
			//IL_0064: Invalid comparison between Unknown and I4
			//IL_004c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0050: Invalid comparison between Unknown and I4
			//IL_0069: Unknown result type (might be due to invalid IL or missing references)
			//IL_006d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0093: Expected I4, but got Unknown
			//IL_0055: Unknown result type (might be due to invalid IL or missing references)
			//IL_0059: Invalid comparison between Unknown and I4
			KeyEditEventArgs e2 = new KeyEditEventArgs(RJ, RK, e);
			RH.OnKeyDownEdit(e2);
			if (e2.Handled)
			{
				return;
			}
			((TextBox)this).OnKeyDown(e);
			if (e.Handled)
			{
				return;
			}
			bool flag = false;
			bool cancel = false;
			bool flag2 = true;
			Keys keyCode = e.KeyCode;
			if ((int)keyCode <= 13)
			{
				if ((int)keyCode == 9)
				{
					goto IL_0118;
				}
				if ((int)keyCode == 13)
				{
					if (e.Alt || e.Shift)
					{
						((TextBoxBase)this).SelectedText = "\r\n";
						e.Handled = true;
					}
					else if (!e.Control)
					{
						flag = true;
					}
				}
			}
			else
			{
				if ((int)keyCode != 27)
				{
					switch (keyCode - 33)
					{
					case 4:
						if (((TextBoxBase)this).SelectionStart == 0 && ((TextBoxBase)this).SelectionLength == 0)
						{
							flag = true;
						}
						goto IL_011a;
					case 6:
						if (((TextBoxBase)this).SelectionStart > ((TextBoxBase)this).TextLength - 1)
						{
							flag = true;
						}
						goto IL_011a;
					case 7:
						if (base.WN >= base.WO - 1)
						{
							flag = true;
						}
						goto IL_011a;
					case 5:
						if (base.WN == 0)
						{
							flag = true;
						}
						goto IL_011a;
					case 0:
					case 1:
						break;
					default:
						goto IL_011a;
					}
					goto IL_0118;
				}
				flag = (cancel = true);
				flag2 = false;
			}
			goto IL_011a;
			IL_0118:
			flag = true;
			goto IL_011a;
			IL_011a:
			if (flag)
			{
				e.Handled = true;
				if (RH.FinishEditing(cancel) && flag2)
				{
					RH.N3.BN(e);
				}
			}
		}

		protected override void OnKeyUp(KeyEventArgs e)
		{
			KeyEditEventArgs e2 = new KeyEditEventArgs(RJ, RK, e);
			RH.OnKeyUpEdit(e2);
			if (!e2.Handled)
			{
				((TextBox)this).OnKeyUp(e);
			}
		}

		protected override void OnKeyPress(KeyPressEventArgs e)
		{
			KeyPressEditEventArgs e2 = new KeyPressEditEventArgs(RJ, RK, e.KeyChar);
			RH.OnKeyPressEdit(e2);
			if (e2.Handled)
			{
				e.Handled = true;
				return;
			}
			base.OnKeyPress(e);
			if (!e.Handled)
			{
				if (e.KeyChar == '\r' || e.KeyChar == '\u001b' || e.KeyChar == '\t')
				{
					e.Handled = true;
				}
				if (e.KeyChar == '☻')
				{
					e.Handled = true;
				}
			}
		}
	}
	public delegate void BeforeMouseDownEventHandler(object sender, BeforeMouseDownEventArgs e);
	public class BeforeMouseDownEventArgs : EventArgs
	{
		public readonly MouseButtons Button;

		public readonly int Clicks;

		public readonly int X;

		public readonly int Y;

		public readonly int Delta;

		public bool Cancel;

		public BeforeMouseDownEventArgs(MouseEventArgs e)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			Button = e.Button;
			Clicks = e.Clicks;
			X = e.X;
			Y = e.Y;
			Delta = e.Delta;
			Cancel = false;
		}
	}
	public delegate void DragRowColEventHandler(object sender, DragRowColEventArgs e);
	public class DragRowColEventArgs : EventArgs
	{
		public readonly int Row;

		public readonly int Col;

		public int Position;

		public bool Cancel;

		public DragRowColEventArgs(int row, int col, int position)
		{
			Row = row;
			Col = col;
			Position = position;
			Cancel = false;
		}
	}
	public delegate void SortColEventHandler(object sender, SortColEventArgs e);
	public class SortColEventArgs : EventArgs
	{
		public readonly int Col;

		public SortFlags Order;

		public bool Cancel;

		public bool Handled;

		public SortColEventArgs(int col, SortFlags order)
		{
			Col = col;
			Order = order;
			Cancel = (Handled = false);
		}
	}
	public delegate void RowColEventHandler(object sender, RowColEventArgs e);
	public class RowColEventArgs : EventArgs
	{
		public readonly int Row;

		public readonly int Col;

		public bool Cancel;

		public RowColEventArgs(int row, int col)
		{
			Row = row;
			Col = col;
			Cancel = false;
		}
	}
	public delegate void RangeEventHandler(object sender, RangeEventArgs e);
	public class RangeEventArgs : EventArgs
	{
		public readonly CellRange OldRange;

		public readonly CellRange NewRange;

		public bool Cancel;

		public RangeEventArgs(CellRange rgOld, CellRange rgNew)
		{
			OldRange = rgOld;
			NewRange = rgNew;
			Cancel = false;
		}
	}
	public delegate void KeyEditEventHandler(object sender, KeyEditEventArgs e);
	public class KeyEditEventArgs : EventArgs
	{
		public readonly int Row;

		public readonly int Col;

		public readonly int KeyValue;

		public readonly Keys KeyCode;

		public readonly Keys KeyData;

		public readonly Keys Modifiers;

		public readonly bool Alt;

		public readonly bool Control;

		public readonly bool Shift;

		public bool Handled;

		public KeyEditEventArgs(int row, int col, KeyEventArgs e)
		{
			//IL_003a: Unknown result type (might be due to invalid IL or missing references)
			//IL_003f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0046: Unknown result type (might be due to invalid IL or missing references)
			//IL_004b: Unknown result type (might be due to invalid IL or missing references)
			//IL_005e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0063: Unknown result type (might be due to invalid IL or missing references)
			Row = row;
			Col = col;
			Alt = e.Alt;
			Shift = e.Shift;
			Control = e.Control;
			KeyCode = e.KeyCode;
			KeyData = e.KeyData;
			KeyValue = e.KeyValue;
			Modifiers = e.Modifiers;
			Handled = false;
		}
	}
	public delegate void KeyPressEditEventHandler(object sender, KeyPressEditEventArgs e);
	public class KeyPressEditEventArgs : EventArgs
	{
		public readonly int Row;

		public readonly int Col;

		public char KeyChar;

		public bool Handled;

		public KeyPressEditEventArgs(int row, int col, char key)
		{
			Row = row;
			Col = col;
			KeyChar = key;
			Handled = false;
		}
	}
	public delegate void ValidateEditEventHandler(object sender, ValidateEditEventArgs e);
	public class ValidateEditEventArgs : EventArgs
	{
		public readonly int Row;

		public readonly int Col;

		public readonly CheckEnum Checkbox;

		public bool Cancel;

		public ValidateEditEventArgs(int row, int col, CheckEnum check)
		{
			Row = row;
			Col = col;
			Checkbox = check;
			Cancel = false;
		}
	}
	public delegate void GridErrorEventHandler(object sender, GridErrorEventArgs e);
	public class GridErrorEventArgs : EventArgs
	{
		public readonly int Row;

		public readonly int Col;

		public readonly Exception Exception;

		public bool Handled;

		public GridErrorEventArgs(int row, int col, Exception exception, bool handled)
		{
			Row = row;
			Col = col;
			Exception = exception;
			Handled = handled;
		}
	}
	public delegate void OwnerDrawCellEventHandler(object sender, OwnerDrawCellEventArgs e);
	public class OwnerDrawCellEventArgs : EventArgs
	{
		public readonly Graphics Graphics;

		public readonly int Row;

		public readonly int Col;

		public readonly Rectangle Bounds;

		public bool Handled;

		internal C1FlexGridBase RM;

		internal string RN;

		internal Image RO;

		internal CellStyle RP;

		internal bool RQ;

		public string Text
		{
			get
			{
				return RN;
			}
			set
			{
				RN = value;
				RQ = true;
			}
		}

		public Image Image
		{
			get
			{
				return RO;
			}
			set
			{
				RO = value;
				RQ = true;
			}
		}

		public CellStyle Style
		{
			get
			{
				return RP;
			}
			set
			{
				RP = value;
				RQ = true;
			}
		}

		internal OwnerDrawCellEventArgs(C1FlexGridBase view, Graphics g, int row, int col, CellStyle s, Rectangle rc, string text, Image img)
		{
			RM = view;
			Graphics = g;
			Row = row;
			Col = col;
			Bounds = rc;
			Handled = false;
			RP = s;
			RN = text;
			RO = img;
			RQ = false;
		}

		public void DrawCell(DrawCellFlags flags)
		{
			Style vA = RP.VA;
			bool flag = false;
			Style styleDisplay = RM.GetStyleDisplay(Row, Col);
			Style style = vA.4N();
			if (!styleDisplay.Equals(vA) && !styleDisplay.Equals(style))
			{
				flag = true;
				vA.4O(styleDisplay, 04C: false);
			}
			RM.7I(Graphics, Row, Col, vA, Bounds, Text, Image, flags);
			Handled = true;
			if (flag)
			{
				vA.4O(style, 04C: false);
			}
		}

		public void DrawCell()
		{
			DrawCell(DrawCellFlags.All);
		}
	}
	public class GridGlyphs
	{
		private 0D RR;

		public Image this[GlyphEnum glyph]
		{
			get
			{
				return RR.8A(glyph);
			}
			set
			{
				RR.89(glyph, value);
			}
		}

		internal GridGlyphs(0D grid)
		{
			RR = grid;
		}
	}
	public enum AutoSearchEnum
	{
		None,
		FromTop,
		FromCursor
	}
	public enum KeyActionEnum
	{
		None,
		MoveDown,
		MoveAcross,
		MoveAcrossOut
	}
	internal class 0M
	{
		internal const double RS = 1.0;

		internal C1FlexGridBase RT;

		internal 0D RU;

		internal AutoSearchEnum RV;

		internal double RW;

		internal Timer RX;

		internal KeyActionEnum RY;

		internal KeyActionEnum RZ;

		internal string S0;

		private char S1 = '\0';

		internal AutoSearchEnum X9
		{
			get
			{
				return RV;
			}
			set
			{
				RV = value;
			}
		}

		internal double XA
		{
			get
			{
				return RW;
			}
			set
			{
				RW = Math.Max(0.0, value);
				RX.Interval = (int)(RW * 1000.0);
			}
		}

		internal 0M(C1FlexGridBase view)
		{
			//IL_0021: Unknown result type (might be due to invalid IL or missing references)
			//IL_002b: Expected O, but got Unknown
			RT = view;
			RU = view.N1;
			RX = new Timer();
			RX.Tick += BR;
			RY = KeyActionEnum.MoveDown;
			RZ = KeyActionEnum.None;
			XA = 1.0;
			BQ();
		}

		internal bool BJ(Keys 0HT)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_0008: Invalid comparison between Unknown and I4
			//IL_000e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0014: Unknown result type (might be due to invalid IL or missing references)
			//IL_0015: Unknown result type (might be due to invalid IL or missing references)
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			//IL_0019: Unknown result type (might be due to invalid IL or missing references)
			//IL_001c: Invalid comparison between Unknown and I4
			//IL_002d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0030: Unknown result type (might be due to invalid IL or missing references)
			//IL_0056: Expected I4, but got Unknown
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Invalid comparison between Unknown and I4
			//IL_0056: Unknown result type (might be due to invalid IL or missing references)
			//IL_0059: Unknown result type (might be due to invalid IL or missing references)
			//IL_006b: Expected I4, but got Unknown
			//IL_0023: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Invalid comparison between Unknown and I4
			bool flag = (0HT & 0x10000) != 0;
			0HT = (Keys)(0HT & -458753);
			Keys val = 0HT;
			bool num;
			if ((int)val <= 13)
			{
				if ((int)val == 9)
				{
					if (RZ == KeyActionEnum.MoveAcrossOut)
					{
						if (RT.Row < RT.Rows.Fixed || RT.Col < RT.Cols.Fixed)
						{
							return false;
						}
						if (!flag)
						{
							if (RT.Row == RT.Rows.Count - 1)
							{
								num = RT.Col == RT.Cols.DN();
								goto IL_0148;
							}
						}
						else if (RT.Row == RT.Rows.Fixed)
						{
							num = RT.Col == RT.Cols.Fixed;
							goto IL_0148;
						}
					}
					goto IL_014e;
				}
				if ((int)val == 13)
				{
					return RY != KeyActionEnum.None;
				}
			}
			else
			{
				switch (val - 33)
				{
				default:
					switch (val - 113)
					{
					case 0:
					case 2:
						break;
					default:
						goto end_IL_0031;
					}
					goto case 0;
				case 0:
				case 1:
				case 4:
				case 5:
				case 6:
				case 7:
					return true;
				case 2:
				case 3:
					break;
					end_IL_0031:
					break;
				}
			}
			return false;
			IL_0148:
			if (num)
			{
				return false;
			}
			goto IL_014e;
			IL_014e:
			return RZ != KeyActionEnum.None;
		}

		internal bool BK(KeyEventArgs 0HU)
		{
			//IL_002b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0032: Invalid comparison between Unknown and I4
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0045: Invalid comparison between Unknown and I4
			//IL_009d: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a4: Invalid comparison between Unknown and I4
			//IL_0050: Unknown result type (might be due to invalid IL or missing references)
			//IL_0057: Invalid comparison between Unknown and I4
			//IL_00d9: Unknown result type (might be due to invalid IL or missing references)
			//IL_00de: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e3: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f1: Expected I4, but got Unknown
			//IL_00f1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f5: Unknown result type (might be due to invalid IL or missing references)
			//IL_011b: Expected I4, but got Unknown
			//IL_01ba: Unknown result type (might be due to invalid IL or missing references)
			//IL_01c0: Invalid comparison between Unknown and I4
			//IL_018a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0190: Invalid comparison between Unknown and I4
			if (RU.PT.9T(RT, 0HU))
			{
				return true;
			}
			if (!RT.78())
			{
				return false;
			}
			if ((int)0HU.KeyCode == 113)
			{
				return BM('\r');
			}
			if ((int)0HU.KeyCode == 115 || (0HU.Alt && (int)0HU.KeyCode == 40))
			{
				int row = RT.Row;
				int col = RT.Col;
				0I 0I2 = RT.N4.BB(row, col);
				0I 0I3 = 0I2;
				if (0I3 == 0I.QY || 0I3 == 0I.R2)
				{
					return BM('\r');
				}
				return false;
			}
			if ((int)0HU.KeyCode == 40 && BO() && BP('\0'))
			{
				return true;
			}
			bool extend = 0HU.Shift && RT.WZ.EG();
			MoveCursorEnum moveCursorEnum = MoveCursorEnum.None;
			Keys keyCode = 0HU.KeyCode;
			switch (keyCode - 8)
			{
			default:
				switch (keyCode - 33)
				{
				case 7:
					moveCursorEnum = (0HU.Control ? MoveCursorEnum.EndDown : MoveCursorEnum.CellDown);
					break;
				case 1:
					moveCursorEnum = MoveCursorEnum.PageDown;
					break;
				case 5:
					moveCursorEnum = (0HU.Control ? MoveCursorEnum.HomeUp : MoveCursorEnum.CellUp);
					break;
				case 0:
					moveCursorEnum = MoveCursorEnum.PageUp;
					break;
				case 6:
					moveCursorEnum = (((int)((Control)RT).RightToLeft != 1) ? (0HU.Control ? MoveCursorEnum.EndRight : MoveCursorEnum.CellRight) : (0HU.Control ? MoveCursorEnum.HomeLeft : MoveCursorEnum.CellLeft));
					break;
				case 4:
					moveCursorEnum = (((int)((Control)RT).RightToLeft != 1) ? (0HU.Control ? MoveCursorEnum.HomeLeft : MoveCursorEnum.CellLeft) : (0HU.Control ? MoveCursorEnum.EndRight : MoveCursorEnum.CellRight));
					break;
				case 3:
					moveCursorEnum = (0HU.Control ? MoveCursorEnum.HomeUp : MoveCursorEnum.HomeLeft);
					break;
				case 2:
					moveCursorEnum = (0HU.Control ? MoveCursorEnum.EndDown : MoveCursorEnum.EndRight);
					break;
				}
				break;
			case 1:
				extend = false;
				moveCursorEnum = ((RZ != KeyActionEnum.MoveDown) ? (0HU.Shift ? MoveCursorEnum.CellPrev : MoveCursorEnum.CellNext) : (0HU.Shift ? MoveCursorEnum.CellUp : MoveCursorEnum.CellDown));
				break;
			case 0:
				break;
			}
			if (moveCursorEnum != MoveCursorEnum.None)
			{
				BQ();
				RT.MoveSelection(moveCursorEnum, extend);
				return true;
			}
			return false;
		}

		internal bool BL(KeyPressEventArgs 0HV)
		{
			if (!RT.78())
			{
				return false;
			}
			if (0HV.KeyChar == '\u001b')
			{
				BQ();
				return true;
			}
			if (BP(0HV.KeyChar))
			{
				return true;
			}
			if (BM(0HV.KeyChar))
			{
				return true;
			}
			if (0HV.KeyChar == '\r')
			{
				switch (RY)
				{
				case KeyActionEnum.MoveAcross:
				case KeyActionEnum.MoveAcrossOut:
					RT.MoveSelection(MoveCursorEnum.CellNext, extend: false);
					return true;
				case KeyActionEnum.MoveDown:
					RT.MoveSelection(MoveCursorEnum.CellDown, extend: false);
					return true;
				}
			}
			return false;
		}

		internal bool BM(char 0HW)
		{
			if (0HW != '\r' && 0HW < ' ' && 0HW > '\0')
			{
				return false;
			}
			Control editor = RT.Editor;
			if (editor != null)
			{
				if (S1 != 0)
				{
					0L 0L2 = editor as 0L;
					0L2?.2X(258, S1);
					GridEditorComboBox gridEditorComboBox = editor as GridEditorComboBox;
					gridEditorComboBox?.SendMessage(258, S1);
					if (0L2 == null && gridEditorComboBox == null)
					{
						editor.Text += S1;
					}
				}
				S1 = 0HW;
				return true;
			}
			S1 = '\0';
			if (!RT.AllowEditing || !RT.78())
			{
				return false;
			}
			Point point = RT.WZ.EK();
			if (!RT.Cols[point.X].AllowEditing)
			{
				return false;
			}
			BQ();
			RT.StartEditing(point.Y, point.X, 0HW, force: false);
			return true;
		}

		internal void BN(KeyEventArgs 0HX)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0008: Invalid comparison between Unknown and I4
			if ((int)0HX.KeyCode == 13)
			{
				switch (RY)
				{
				case KeyActionEnum.MoveAcross:
				case KeyActionEnum.MoveAcrossOut:
					RT.MoveSelection(0HX.Shift ? MoveCursorEnum.CellPrev : MoveCursorEnum.CellNext, extend: false);
					break;
				case KeyActionEnum.MoveDown:
					RT.MoveSelection(0HX.Shift ? MoveCursorEnum.CellUp : MoveCursorEnum.CellDown, extend: false);
					break;
				}
			}
			else
			{
				BK(0HX);
			}
		}

		internal bool BO()
		{
			return S0.Length > 0;
		}

		internal bool BP(char 0HY)
		{
			Point point = RT.WZ.EK();
			if (RV == AutoSearchEnum.None || (0HY > '\0' && 0HY < ' '))
			{
				BQ();
				return false;
			}
			if (!BO() && 0HY > ' ')
			{
				BQ();
			}
			RX.Stop();
			RX.Start();
			if (0HY == '\b' && S0.Length > 0)
			{
				S0 = S0.Substring(S0.Length - 1);
			}
			if (0HY >= ' ')
			{
				S0 += 0HY;
			}
			int num = point.Y;
			if (S0.Length == 1 || 0HY == '\0')
			{
				num++;
			}
			if (RV == AutoSearchEnum.FromTop && 0HY != 0)
			{
				num = RT.Rows.Fixed;
			}
			num = RT.FindRow(S0, num, point.X, caseSensitive: false, fullMatch: false, wrap: true);
			if (num >= 0)
			{
				RT.Select(num, point.X, show: true);
				return true;
			}
			if (0HY == ' ')
			{
				return false;
			}
			BQ();
			return true;
		}

		internal void BQ()
		{
			RX.Enabled = false;
			S0 = "";
			Point 09M = RT.WZ.EK();
			RT.79(09M);
		}

		internal void BR(object 0HZ, EventArgs 0I0)
		{
			BQ();
		}
	}
	internal class 0N
	{
		internal enum 0O
		{
			SM,
			SN,
			SO,
			SP,
			SQ,
			SR,
			SS,
			ST,
			SU,
			SV,
			SW,
			SX
		}

		internal const int S2 = 3;

		internal const int S3 = 10;

		internal const int S4 = 3;

		internal const int S5 = 50;

		private C1FlexGridBase S6;

		private 0O S7;

		private Point S8;

		private Point S9;

		private Point SA;

		private Rectangle SB;

		private int SC;

		private int SD;

		private int SE;

		private 0P SF;

		private RowCollection SG;

		private bool SH;

		private 0Q SI;

		private bool SJ;

		private bool SK;

		private int SL = 0;

		internal 0N(C1FlexGridBase view)
		{
			S6 = view;
			SF = new 0P();
			((Timer)SF).Interval = 50;
			((Timer)SF).Enabled = false;
			((Timer)SF).Tick += BT;
			SI = new 0Q((Control)(object)view);
		}

		internal HitTestInfo BS(int 0I1, int 0I2)
		{
			Point point = new Point(0I1, 0I2);
			point = S6.GetCellAt(0I1, 0I2, fixedOK: true);
			int num = point.Y;
			int num2 = point.X;
			HitTestTypeEnum hitTestTypeEnum = HitTestTypeEnum.None;
			if (num > -1 && num2 > -1)
			{
				hitTestTypeEnum = HitTestTypeEnum.Cell;
				if (num < S6.Rows.Fixed)
				{
					hitTestTypeEnum = HitTestTypeEnum.ColumnHeader;
					int num3 = CE(0I1, 0I2);
					if (num3 >= 0)
					{
						hitTestTypeEnum = HitTestTypeEnum.ColumnResize;
						num2 = num3;
					}
				}
				else if (num2 < S6.Cols.Fixed)
				{
					hitTestTypeEnum = HitTestTypeEnum.RowHeader;
					int num4 = CF(0I1, 0I2);
					if (num4 >= 0)
					{
						hitTestTypeEnum = HitTestTypeEnum.RowResize;
						num = num4;
					}
				}
				if (CG(0I1, 0I2) > -1)
				{
					hitTestTypeEnum = HitTestTypeEnum.ColumnFreeze;
				}
				else if (CH(0I1, 0I2) > -1)
				{
					hitTestTypeEnum = HitTestTypeEnum.RowFreeze;
				}
				switch (hitTestTypeEnum)
				{
				case HitTestTypeEnum.Cell:
				case HitTestTypeEnum.ColumnHeader:
				case HitTestTypeEnum.RowHeader:
					switch (S6.X0.BB(num, num2))
					{
					case 0I.R1:
					{
						Style styleDisplay = S6.GetStyleDisplay(num, num2);
						Rectangle cellRect = S6.GetCellRect(num, num2, show: false);
						if (S6.7R(num, num2, styleDisplay, cellRect).Contains(0I1, 0I2))
						{
							hitTestTypeEnum = HitTestTypeEnum.Checkbox;
						}
						break;
					}
					case 0I.QY:
					case 0I.QZ:
					case 0I.R0:
					case 0I.R2:
						if (hitTestTypeEnum == HitTestTypeEnum.Cell && S6.7L(num, num2))
						{
							Rectangle cellRect = S6.GetCellRect(num, num2, show: false);
							if (S6.N4.BC(cellRect).Contains(0I1, 0I2))
							{
								hitTestTypeEnum = HitTestTypeEnum.EditButton;
							}
						}
						break;
					}
					if (BZ(0I1, 0I2, num, num2) > -1)
					{
						hitTestTypeEnum = HitTestTypeEnum.OutlineBar;
					}
					else if (C0(0I1, 0I2, num, num2))
					{
						hitTestTypeEnum = HitTestTypeEnum.OutlineTree;
					}
					break;
				}
			}
			return new HitTestInfo(0I1, 0I2, num, num2, hitTestTypeEnum);
		}

		internal void BT(object 0I3, EventArgs 0I4)
		{
			//IL_0058: Unknown result type (might be due to invalid IL or missing references)
			//IL_006d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0077: Expected O, but got Unknown
			if (S7 == 0O.SM || !((Control)S6).Focused || !((Control)S6).Capture)
			{
				((Timer)SF).Enabled = false;
				return;
			}
			Point pt = ((Control)S6).PointToClient(Cursor.Position);
			if (!S6.ScrollableRectangle.Contains(pt))
			{
				BU(new MouseEventArgs(Control.MouseButtons, 0, pt.X, pt.Y, 0));
			}
		}

		internal bool BU(MouseEventArgs 0I5)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Unknown result type (might be due to invalid IL or missing references)
			//IL_001a: Unknown result type (might be due to invalid IL or missing references)
			if ((0I5.Button & 0x100000) != 0 && !C3(0I5))
			{
				return false;
			}
			if ((int)0I5.Button != 0)
			{
				return false;
			}
			if (S7 != 0O.SM)
			{
				C9();
			}
			SA.X = CE(0I5.X, 0I5.Y);
			if (SA.X >= 0)
			{
				S7 = 0O.SO;
				S6.WV = Cursors.VSplit;
				return true;
			}
			SA.Y = CF(0I5.X, 0I5.Y);
			if (SA.Y >= 0)
			{
				S7 = 0O.SO;
				S6.WV = Cursors.HSplit;
				return true;
			}
			SA.X = CG(0I5.X, 0I5.Y);
			if (SA.X >= 0)
			{
				S7 = 0O.SQ;
				S6.WV = 0D.PH;
				return true;
			}
			SA.Y = CH(0I5.X, 0I5.Y);
			if (SA.Y >= 0)
			{
				S7 = 0O.SQ;
				S6.WV = 0D.PI;
				return true;
			}
			if (S6.N6.B1(0I5))
			{
				S7 = 0O.SN;
				S6.WV = 0D.PG;
				return true;
			}
			if (S6.NI && S6.N1.9H())
			{
				S6.N1.PO.AQ(0I5);
			}
			return false;
		}

		internal bool BV(MouseEventArgs 0I6)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Unknown result type (might be due to invalid IL or missing references)
			if ((0I6.Button & 0x100000) == 0)
			{
				return false;
			}
			if (0I6.Clicks != 1)
			{
				return false;
			}
			if (S7 == 0O.SN)
			{
				C9();
				S6.N6.B2(0I6);
				return true;
			}
			ref Point s = ref S8;
			s = new Point(0I6.X, 0I6.Y);
			S9 = S6.GetCellAt(0I6.X, 0I6.Y);
			if (S7 == 0O.SO)
			{
				return BW(0I6);
			}
			if (S7 == 0O.SQ)
			{
				return BX(0I6);
			}
			if (SA.X < 0 && SA.Y < 0 && CU(0JO: false))
			{
				return true;
			}
			if (C1(0I6))
			{
				return true;
			}
			if (BY(0I6))
			{
				return true;
			}
			if (C2(0I6))
			{
				((Timer)SF).Enabled = true;
				return true;
			}
			return false;
		}

		internal bool BW(MouseEventArgs 0I7)
		{
			if (SA.X > -1)
			{
				RowColEventArgs e = new RowColEventArgs(-1, SA.X);
				S6.OnBeforeResizeColumn(e);
				if (!e.Cancel)
				{
					S7 = 0O.SP;
					CI(0I7, 0J4: true);
					return true;
				}
			}
			if (SA.Y > -1)
			{
				RowColEventArgs e2 = new RowColEventArgs(SA.Y, -1);
				S6.OnBeforeResizeRow(e2);
				if (!e2.Cancel)
				{
					S7 = 0O.SP;
					CJ(0I7, 0J6: true);
					return true;
				}
			}
			return false;
		}

		internal bool BX(MouseEventArgs 0I8)
		{
			if (SA.X > -1)
			{
				RowColEventArgs e = new RowColEventArgs(-1, S6.Cols.Frozen);
				S6.OnBeforeFreezeColumn(e);
				if (!e.Cancel)
				{
					S7 = 0O.SR;
					CM(0I8, 0JC: true);
					return true;
				}
			}
			if (SA.Y > -1)
			{
				RowColEventArgs e2 = new RowColEventArgs(S6.Rows.Frozen, -1);
				S6.OnBeforeFreezeRow(e2);
				if (!e2.Cancel)
				{
					S7 = 0O.SR;
					CN(0I8, 0JE: true);
					return true;
				}
			}
			return false;
		}

		internal bool BY(MouseEventArgs 0I9)
		{
			if (S9.X < 0 || S9.Y < 0)
			{
				return false;
			}
			if (S9.X >= S6.Cols.Fixed && S9.Y < S6.Rows.Fixed)
			{
				if (!CQ(S9.X) && !CS(S9.X))
				{
					return false;
				}
				S7 = 0O.SS;
				ref Point sA = ref SA;
				sA = new Point(S9.X, -1);
				return true;
			}
			if (S9.Y >= S6.Rows.Fixed && S9.X < S6.Cols.Fixed)
			{
				if (!CR(S9.Y))
				{
					return false;
				}
				S7 = 0O.SS;
				ref Point sA2 = ref SA;
				sA2 = new Point(-1, S9.Y);
				return true;
			}
			return false;
		}

		internal int BZ(int 0IA, int 0IB, int 0IC, int 0ID)
		{
			GridTree pM = S6.N1.PM;
			if (pM.FD(0ID) == 0)
			{
				return -1;
			}
			if (!pM.F6(TreeStyleFlags.ButtonBar) || 0IC != 0 || S6.Rows.Fixed == 0)
			{
				return -1;
			}
			Rectangle cellRectDisplay = S6.GetCellRectDisplay(0IC, 0ID);
			int uF = S6.Rows.UF;
			for (int i = 0; i <= uF + 1; i++)
			{
				if (pM.FB(cellRectDisplay, i).Contains(0IA, 0IB))
				{
					return i;
				}
			}
			return -1;
		}

		internal bool C0(int 0IE, int 0IF, int 0IG, int 0IH)
		{
			GridTree pM = S6.N1.PM;
			if (pM.FD(0IH) == 0)
			{
				return false;
			}
			if (!pM.F6(TreeStyleFlags.Symbols))
			{
				return false;
			}
			if (0IG < 0)
			{
				return false;
			}
			Row row = S6.Rows[0IG];
			if (!row.IsNode)
			{
				return false;
			}
			Node node = row.Node;
			Rectangle cellRectDisplay = S6.GetCellRectDisplay(0IG, 0IH);
			return pM.FC(cellRectDisplay, node.Level).Contains(0IE, 0IF);
		}

		internal bool C1(MouseEventArgs 0II)
		{
			//IL_0092: Unknown result type (might be due to invalid IL or missing references)
			//IL_009c: Unknown result type (might be due to invalid IL or missing references)
			int num = BZ(0II.X, 0II.Y, S9.Y, S9.X);
			if (num > -1)
			{
				S6.N1.PM.Show(num);
				return true;
			}
			if (C0(0II.X, 0II.Y, S9.Y, S9.X))
			{
				Node node = S6.Rows[S9.Y].Node;
				if ((Control.ModifierKeys & 0x30000) != 0)
				{
					num = node.Level;
					if (node.Collapsed)
					{
						num++;
					}
					S6.N1.PM.Show(num);
				}
				else
				{
					node.Collapsed = !node.Collapsed;
				}
				return true;
			}
			return false;
		}

		internal bool C2(MouseEventArgs 0IJ)
		{
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			//IL_004a: Invalid comparison between Unknown and I4
			//IL_0050: Unknown result type (might be due to invalid IL or missing references)
			//IL_005a: Unknown result type (might be due to invalid IL or missing references)
			//IL_005c: Invalid comparison between Unknown and I4
			CellRange rg = new CellRange(S6.N1, S9.Y, S9.X);
			if (rg.r1 < 0 || rg.c1 < 0)
			{
				return false;
			}
			bool flag = (Control.ModifierKeys & 0x10000) != 0;
			bool flag2 = (Control.ModifierKeys & 0x20000) != 0;
			bool flag3 = S6.Rows.DO(rg.r1);
			bool flag4 = S6.Cols.DO(rg.c1);
			if (flag3)
			{
				rg.r1 = S6.Rows.Fixed;
				rg.r2 = S6.Rows.Count - 1;
				if (rg.r1 > rg.r2)
				{
					rg.r1 = rg.r2;
				}
			}
			if (flag4)
			{
				rg.c1 = S6.Cols.Fixed;
				rg.c2 = S6.Cols.Count - 1;
				if (rg.c1 > rg.c2)
				{
					rg.c1 = rg.c2;
				}
			}
			SK = !flag4 && S6.Cols.DP(S9.X);
			SJ = !flag3 && S6.Rows.DP(S9.Y);
			switch (S6.SelectionMode)
			{
			case SelectionModeEnum.Cell:
			case SelectionModeEnum.CellRange:
				if (flag3)
				{
					rg.r1 = (rg.r2 = S6.Row);
				}
				if (flag4)
				{
					rg.c1 = (rg.c2 = S6.Col);
				}
				break;
			case SelectionModeEnum.Row:
			case SelectionModeEnum.RowRange:
			case SelectionModeEnum.ListBox:
				if (flag3)
				{
					return false;
				}
				if (flag4)
				{
					rg.c1 = (rg.c2 = S6.Col);
				}
				break;
			case SelectionModeEnum.Column:
			case SelectionModeEnum.ColumnRange:
				if (flag4)
				{
					return false;
				}
				if (flag3)
				{
					rg.r1 = (rg.r2 = S6.Row);
				}
				break;
			case SelectionModeEnum.Default:
				if (flag3 && flag4)
				{
					if (rg.IsValid)
					{
						S6.Select(rg, show: false);
					}
					return true;
				}
				break;
			}
			if (flag2 && S6.SelectionMode == SelectionModeEnum.ListBox)
			{
				S7 = 0O.SX;
				SG = S6.Rows.Selected;
				SH = !S6.Rows[S9.Y].Selected;
				S6.77(S9.Y, S6.Col, SH, null);
				return true;
			}
			S7 = 0O.SU;
			if (flag3)
			{
				S7 = 0O.SW;
			}
			if (flag4)
			{
				S7 = 0O.SV;
			}
			if (flag3 && flag4)
			{
				S7 = 0O.SM;
			}
			if (S6.Rows.Count == S6.Rows.Fixed)
			{
				rg.r1 = (rg.r2 = -1);
			}
			if (S6.Cols.Count == S6.Cols.Fixed)
			{
				rg.c1 = (rg.c2 = -1);
			}
			if (flag && S6.WZ.EG())
			{
				S6.75(rg.r1, rg.c1, 09F: false);
			}
			else if (rg.IsValid)
			{
				S6.Select(rg, show: false);
			}
			return true;
		}

		internal bool C3(MouseEventArgs 0IK)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Unknown result type (might be due to invalid IL or missing references)
			if ((0IK.Button & 0x100000) == 0)
			{
				return false;
			}
			if (S7 == 0O.SP)
			{
				if (SA.X > -1)
				{
					CI(0IK, 0J4: false);
				}
				if (SA.Y > -1)
				{
					CJ(0IK, 0J6: false);
				}
				return true;
			}
			if (S7 == 0O.SR)
			{
				if (SA.X > -1)
				{
					CM(0IK, 0JC: false);
				}
				if (SA.Y > -1)
				{
					CN(0IK, 0JE: false);
				}
				return true;
			}
			if (S7 == 0O.ST && SA.X >= 0)
			{
				int num = 0;
				if (SB.Right - 0IK.X < 3)
				{
					num = 1;
				}
				if (0IK.X - SB.Left < 3)
				{
					num = -1;
				}
				if (num != 0 && CT(num, 0))
				{
					return C3(0IK);
				}
				CK(0IK, 0J8: false);
				return true;
			}
			if (S7 == 0O.ST && SA.Y >= 0)
			{
				int num2 = 0;
				if (SB.Bottom - 0IK.Y < 3)
				{
					num2 = 1;
				}
				if (0IK.Y - SB.Top < 3)
				{
					num2 = -1;
				}
				if (num2 != 0 && CT(0, num2))
				{
					return C3(0IK);
				}
				CL(0IK, 0JA: false);
				return true;
			}
			if (S7 == 0O.SS)
			{
				if (SA.X >= S6.Cols.Fixed && CQ(SA.X) && Math.Abs(0IK.X - S8.X) > 10)
				{
					SB = S6.ScrollableRectangle;
					CK(0IK, 0J8: true);
					return true;
				}
				if (SA.Y >= S6.Rows.Fixed && CR(SA.Y) && Math.Abs(0IK.Y - S8.Y) > 10)
				{
					SB = S6.ScrollableRectangle;
					CL(0IK, 0JA: true);
					return true;
				}
			}
			return C4(0IK);
		}

		internal bool C4(MouseEventArgs 0IL)
		{
			RowCollection rows = S6.Rows;
			ColumnCollection cols = S6.Cols;
			Point cellAt = S6.GetCellAt(0IL.X, 0IL.Y, fixedOK: true);
			Point cellAt2 = S6.GetCellAt(0IL.X, 0IL.Y, fixedOK: false);
			Point point = new Point(0, 0);
			point.X = (SK ? cellAt.X : cellAt2.X);
			point.Y = (SJ ? cellAt.Y : cellAt2.Y);
			if (SK && !cols.DP(point.X))
			{
				SK = false;
			}
			if (SJ && !rows.DP(point.Y))
			{
				SJ = false;
			}
			if (point.X < -1)
			{
				point.X = cols.Count - 1;
			}
			if (point.Y < -1)
			{
				point.Y = rows.Count - 1;
			}
			if (point.Y < rows.Fixed && rows.Count > rows.Fixed)
			{
				point.Y = rows.Fixed;
				while (point.Y < rows.Count - 1 && !rows[point.Y].Visible)
				{
					point.Y++;
				}
			}
			if (point.X < cols.Fixed && cols.Count > cols.Fixed)
			{
				point.X = cols.Fixed;
				while (point.X < cols.Count - 1 && !cols[point.X].Visible)
				{
					point.X++;
				}
			}
			bool flag = S6.WZ.EG();
			switch (S7)
			{
			case 0O.SU:
				if (flag)
				{
					S6.76(point, 09H: true);
				}
				else
				{
					S6.74(point, 09C: true);
				}
				return true;
			case 0O.SX:
				S6.77(point.Y, point.X, SH, SG);
				return true;
			case 0O.SV:
				if (flag)
				{
					S6.75(point.Y, S6.ColSel, 09F: false);
				}
				else
				{
					S6.Select(point.Y, S6.Col, show: true);
				}
				S6.ShowCell(S6.RowSel, -1);
				return true;
			case 0O.SW:
				if (flag)
				{
					S6.75(S6.RowSel, point.X, 09F: false);
				}
				else
				{
					S6.Select(S6.Row, point.X, show: true);
				}
				S6.ShowCell(-1, S6.ColSel);
				return true;
			default:
				return false;
			}
		}

		internal bool C5(MouseEventArgs 0IM)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Unknown result type (might be due to invalid IL or missing references)
			if ((0IM.Button & 0x100000) == 0)
			{
				return false;
			}
			if (S7 == 0O.SP && SA.X > -1 && 0IM.X != S8.X)
			{
				RowColEventArgs e = new RowColEventArgs(-1, SA.X);
				int num = S6.Cols[SA.X].WidthDisplay + (0IM.X - S8.X);
				if (num < 1)
				{
					num = 1;
				}
				if (CC(S6.AllowResizing))
				{
					S6.Cols.DefaultSize = num;
					C7(SA.X, -1);
				}
				else
				{
					C7(SA.X, num);
				}
				C9();
				S6.OnAfterResizeColumn(e);
				return true;
			}
			if (S7 == 0O.SP && SA.Y > -1 && 0IM.Y != S8.Y)
			{
				RowColEventArgs e2 = new RowColEventArgs(SA.Y, -1);
				int num2 = S6.Rows[SA.Y].HeightDisplay + (0IM.Y - S8.Y);
				if (num2 < 1)
				{
					num2 = 1;
				}
				if (CC(S6.AllowResizing))
				{
					S6.Rows.DefaultSize = num2;
					C6(SA.Y, -1);
				}
				else
				{
					C6(SA.Y, num2);
				}
				C9();
				S6.OnAfterResizeRow(e2);
				return true;
			}
			if (S7 == 0O.SR && SA.X > -1)
			{
				S6.Cols.Frozen = SC - S6.Cols.Fixed;
				RowColEventArgs e3 = new RowColEventArgs(-1, S6.Cols.Frozen);
				C9();
				S6.OnAfterFreezeColumn(e3);
				return true;
			}
			if (S7 == 0O.SR && SA.Y > -1)
			{
				S6.Rows.Frozen = SC - S6.Rows.Fixed;
				RowColEventArgs e4 = new RowColEventArgs(S6.Rows.Frozen, -1);
				C9();
				S6.OnAfterFreezeRow(e4);
				return true;
			}
			if (S7 == 0O.ST && SA.X > -1)
			{
				int x = SA.X;
				int num3 = SC;
				if (num3 != x && num3 != x + 1)
				{
					if (num3 > x)
					{
						num3--;
					}
					DragRowColEventArgs e5 = new DragRowColEventArgs(-1, x, num3);
					S6.OnBeforeDragColumn(e5);
					if (!e5.Cancel)
					{
						S6.Cols.Move(e5.Col, e5.Position);
						S6.OnAfterDragColumn(e5);
					}
				}
				((Control)S6).Invalidate();
				C9();
				return true;
			}
			if (S7 == 0O.ST && SA.Y > -1)
			{
				int y = SA.Y;
				int num4 = SC;
				if (num4 != y && num4 != y + 1)
				{
					if (num4 > y)
					{
						num4--;
					}
					DragRowColEventArgs e6 = new DragRowColEventArgs(y, -1, num4);
					S6.OnBeforeDragRow(e6);
					if (!e6.Cancel)
					{
						S6.Rows.Move(e6.Row, e6.Position);
						S6.OnAfterDragRow(e6);
					}
				}
				((Control)S6).Invalidate();
				C9();
				return true;
			}
			if (S7 == 0O.SS)
			{
				Point cellAt = S6.GetCellAt(0IM.X, 0IM.Y);
				if (SA.X == cellAt.X && CS(SA.X) && S6.N1.8I(cellAt.Y, cellAt.X) && CD())
				{
					S6.7G(SA.X);
					C9();
					return true;
				}
			}
			if (S7 == 0O.SU)
			{
				if (!S6.WZ.V4)
				{
					CellRange cellRange = S6.WZ.EJ();
					S6.ShowCell(cellRange.r2, cellRange.c2);
				}
				C9();
				return true;
			}
			if (S7 == 0O.SS)
			{
				C2(0IM);
				C9();
				return true;
			}
			C9();
			return false;
		}

		internal void C6(int 0IN, int 0IO)
		{
			CellRange selection = S6.Selection;
			if (selection.c1 == S6.Cols.Fixed && selection.c2 == S6.Cols.Count - 1 && selection.ContainsRow(0IN))
			{
				for (0IN = selection.r1; 0IN <= selection.r2; 0IN++)
				{
					S6.Rows[0IN].Height = 0IO;
				}
			}
			else
			{
				S6.Rows[0IN].Height = 0IO;
			}
		}

		internal void C7(int 0IP, int 0IQ)
		{
			CellRange selection = S6.Selection;
			if (selection.r1 == S6.Rows.Fixed && selection.r2 == S6.Rows.Count - 1 && selection.ContainsCol(0IP))
			{
				for (0IP = selection.c1; 0IP <= selection.c2; 0IP++)
				{
					S6.Cols[0IP].Width = 0IQ;
				}
			}
			else
			{
				S6.Cols[0IP].Width = 0IQ;
			}
		}

		internal bool C8(MouseEventArgs 0IR)
		{
			int num = CE(0IR.X, 0IR.Y);
			if (num >= 0)
			{
				C9();
				RowColEventArgs e = new RowColEventArgs(-1, num);
				S6.OnBeforeAutosizeColumn(e);
				if (e.Cancel)
				{
					return true;
				}
				S6.AutoSizeCol(num);
				if (CC(S6.AllowResizing))
				{
					S6.Cols.DefaultSize = S6.Cols[num].WidthDisplay;
					C7(num, -1);
				}
				S6.OnAfterResizeColumn(e);
				return true;
			}
			int num2 = CF(0IR.X, 0IR.Y);
			if (num2 >= 0)
			{
				C9();
				RowColEventArgs e2 = new RowColEventArgs(num2, -1);
				S6.OnBeforeAutosizeRow(e2);
				if (e2.Cancel)
				{
					return true;
				}
				S6.AutoSizeRow(num2);
				if (CC(S6.AllowResizing))
				{
					S6.Rows.DefaultSize = S6.Rows[num2].HeightDisplay;
					C6(num2, -1);
				}
				S6.OnAfterResizeRow(e2);
				return true;
			}
			if (CU(0JO: true))
			{
				return true;
			}
			C9();
			return false;
		}

		internal void C9()
		{
			SI.CV();
			S6.WV = null;
			S7 = 0O.SM;
			ref Point sA = ref SA;
			int x = (SA.Y = -1);
			sA.X = x;
			SG = null;
		}

		internal void CA()
		{
			switch (S7)
			{
			case 0O.SP:
				C9();
				break;
			case 0O.SR:
				C9();
				break;
			case 0O.SS:
				C9();
				break;
			case 0O.ST:
				C9();
				break;
			case 0O.SQ:
				break;
			}
		}

		private bool CB(bool 0IS, AllowResizingEnum 0IT)
		{
			switch (0IT)
			{
			case AllowResizingEnum.Both:
			case AllowResizingEnum.BothUniform:
				return true;
			case AllowResizingEnum.Rows:
			case AllowResizingEnum.RowsUniform:
				return 0IS;
			case AllowResizingEnum.Columns:
			case AllowResizingEnum.ColumnsUniform:
				return !0IS;
			default:
				return false;
			}
		}

		private bool CC(AllowResizingEnum 0IU)
		{
			switch (0IU)
			{
			case AllowResizingEnum.ColumnsUniform:
			case AllowResizingEnum.RowsUniform:
			case AllowResizingEnum.BothUniform:
				return true;
			default:
				return false;
			}
		}

		private bool CD()
		{
			RowColCollection rows = S6.Rows;
			if (rows.Count > rows.Fixed + rows.Frozen)
			{
				return true;
			}
			rows = S6.Cols;
			if (rows.Count > rows.Fixed + rows.Frozen)
			{
				return true;
			}
			return false;
		}

		private int CE(int 0IV, int 0IW)
		{
			AllowResizingEnum allowResizing = S6.AllowResizing;
			if (!CB(0IS: false, allowResizing))
			{
				return -1;
			}
			Point cellAt = S6.GetCellAt(0IV, 0IW);
			if (cellAt.X < 0 || cellAt.Y < 0 || cellAt.Y >= S6.Rows.Fixed)
			{
				return -1;
			}
			int num = -1;
			Rectangle cellRectDisplay = S6.GetCellRectDisplay(cellAt.Y, cellAt.X);
			if (cellRectDisplay.Right - 0IV < 3)
			{
				num = cellAt.X;
			}
			if (0IV - cellRectDisplay.X < 3)
			{
				num = cellAt.X - 1;
			}
			while (num > 0 && S6.Cols[num].XC == 0)
			{
				num--;
			}
			if (num < 0 || !S6.Cols[num].AllowResizing || S6.Cols[num].XC == 0)
			{
				return -1;
			}
			if (S6.ExtendCol(num))
			{
				return -1;
			}
			return num;
		}

		private int CF(int 0IX, int 0IY)
		{
			AllowResizingEnum allowResizing = S6.AllowResizing;
			if (!CB(0IS: true, allowResizing))
			{
				return -1;
			}
			Point cellAt = S6.GetCellAt(0IX, 0IY);
			if (cellAt.X < 0 || cellAt.Y < 0 || cellAt.X >= S6.Cols.Fixed)
			{
				return -1;
			}
			int num = -1;
			Rectangle cellRectDisplay = S6.GetCellRectDisplay(cellAt.Y, cellAt.X);
			if (cellRectDisplay.Bottom - 0IY < 3)
			{
				num = cellAt.Y;
			}
			if (0IY - cellRectDisplay.Y < 3)
			{
				num = cellAt.Y - 1;
			}
			while (num > 0 && S6.Rows[num].XC == 0)
			{
				num--;
			}
			if (num < 0 || !S6.Rows[num].AllowResizing || S6.Rows[num].XC == 0)
			{
				return -1;
			}
			return num;
		}

		private int CG(int 0IZ, int 0J0)
		{
			AllowFreezingEnum allowFreezing = S6.AllowFreezing;
			if (allowFreezing != AllowFreezingEnum.Columns && allowFreezing != AllowFreezingEnum.Both)
			{
				return -1;
			}
			RowColCollection cols = S6.Cols;
			Point cellAt = S6.GetCellAt(0IZ, 0J0);
			if (cellAt.X != cols.Fixed + cols.Frozen - 1)
			{
				return -1;
			}
			int num = -1;
			if (S6.GetCellRectDisplay(cellAt.Y, cellAt.X).Right - 0IZ < 3)
			{
				num = cellAt.X;
			}
			if (S6.ExtendCol(num))
			{
				return -1;
			}
			return num;
		}

		private int CH(int 0J1, int 0J2)
		{
			AllowFreezingEnum allowFreezing = S6.AllowFreezing;
			if (allowFreezing != AllowFreezingEnum.Rows && allowFreezing != AllowFreezingEnum.Both)
			{
				return -1;
			}
			RowColCollection rows = S6.Rows;
			Point cellAt = S6.GetCellAt(0J1, 0J2);
			if (cellAt.Y != rows.Fixed + rows.Frozen - 1)
			{
				return -1;
			}
			int result = -1;
			if (S6.GetCellRectDisplay(cellAt.Y, cellAt.X).Bottom - 0J2 < 3)
			{
				result = cellAt.Y;
			}
			return result;
		}

		private void CI(MouseEventArgs 0J3, bool 0J4)
		{
			Rectangle cellRectDisplay;
			if (0J4)
			{
				cellRectDisplay = S6.GetCellRectDisplay(0, SA.X, clip: true);
				cellRectDisplay.Y = 0;
				cellRectDisplay.Width += ((Control)S6).ClientRectangle.Right - cellRectDisplay.Right;
				cellRectDisplay.Height = S6.Rows[S6.Rows.Fixed - 1].Bottom;
				SL = cellRectDisplay.X;
			}
			cellRectDisplay = ((Control)S6).ClientRectangle;
			cellRectDisplay.X = Math.Max(SL, 0J3.X - 1);
			cellRectDisplay.Width = 3;
			SI.CW(cellRectDisplay);
		}

		private void CJ(MouseEventArgs 0J5, bool 0J6)
		{
			Rectangle cellRectDisplay;
			if (0J6 && S6.Rows.Fixed > 0)
			{
				cellRectDisplay = S6.GetCellRectDisplay(SA.Y, 0, clip: true);
				cellRectDisplay.X = 0;
				cellRectDisplay.Height += ((Control)S6).ClientRectangle.Bottom - cellRectDisplay.Bottom;
				cellRectDisplay.Width = S6.Cols[S6.Rows.Fixed - 1].Right;
				SL = cellRectDisplay.Y;
			}
			cellRectDisplay = ((Control)S6).ClientRectangle;
			cellRectDisplay.Y = Math.Max(SL, 0J5.Y - 1);
			cellRectDisplay.Height = 3;
			SI.CW(cellRectDisplay);
		}

		private void CK(MouseEventArgs 0J7, bool 0J8)
		{
			Rectangle cellRectDisplay;
			if (0J8 && S6.Rows.Fixed > 0)
			{
				SE = (SD = SA.X);
				while (SD > S6.Cols.Fixed && CQ(SD - 1))
				{
					SD--;
				}
				while (SE < S6.Cols.Count - 1 && CQ(SE + 1))
				{
					SE++;
				}
				if (SE == SD)
				{
					return;
				}
				S7 = 0O.ST;
				S6.WV = Cursors.SizeWE;
				cellRectDisplay = S6.GetCellRectDisplay(0, SA.X, clip: true);
				cellRectDisplay.Height = S6.Rows[S6.Rows.Fixed - 1].Bottom;
				cellRectDisplay.Intersect(((Control)S6).ClientRectangle);
				cellRectDisplay = ((Control)S6).RectangleToScreen(cellRectDisplay);
				ControlPaint.FillReversibleRectangle(cellRectDisplay, SystemColors.ControlLightLight);
			}
			SC = CO(0J7, 0JG: true);
			cellRectDisplay = ((Control)S6).ClientRectangle;
			cellRectDisplay.Width = 3;
			if (SC > 0)
			{
				cellRectDisplay.X = S6.GetCellRectDisplay(-1, SC - 1, clip: true).Right - 1;
			}
			SI.CW(cellRectDisplay);
		}

		private void CL(MouseEventArgs 0J9, bool 0JA)
		{
			Rectangle cellRectDisplay;
			if (0JA)
			{
				S7 = 0O.ST;
				S6.WV = Cursors.SizeNS;
				SE = (SD = SA.Y);
				while (SD > S6.Rows.Fixed && CR(SD - 1))
				{
					SD--;
				}
				while (SE < S6.Rows.Count - 1 && CR(SE + 1))
				{
					SE++;
				}
				if (SE == SD)
				{
					return;
				}
				cellRectDisplay = S6.GetCellRectDisplay(SA.Y, 0, clip: true);
				cellRectDisplay.Width = S6.Cols[S6.Cols.Fixed - 1].Right;
				cellRectDisplay.Intersect(((Control)S6).ClientRectangle);
				cellRectDisplay = ((Control)S6).RectangleToScreen(cellRectDisplay);
				ControlPaint.FillReversibleRectangle(cellRectDisplay, SystemColors.Window);
			}
			SC = CP(0J9, 0JI: true);
			cellRectDisplay = ((Control)S6).ClientRectangle;
			cellRectDisplay.Height = 3;
			if (SC > 0)
			{
				cellRectDisplay.Y = S6.GetCellRectDisplay(SC - 1, -1, clip: true).Bottom - 1;
			}
			SI.CW(cellRectDisplay);
		}

		private void CM(MouseEventArgs 0JB, bool 0JC)
		{
			if (0JC)
			{
				SD = S6.Cols.Fixed;
				SE = S6.Cols.Count - 1;
				S6.LeftCol = 0;
			}
			SC = CO(0JB, 0JG: false);
			Rectangle clientRectangle = ((Control)S6).ClientRectangle;
			clientRectangle.Width = 3;
			if (SC > 0)
			{
				clientRectangle.X = S6.GetCellRectDisplay(-1, SC - 1, clip: true).Right - 1;
			}
			SI.CW(clientRectangle);
		}

		private void CN(MouseEventArgs 0JD, bool 0JE)
		{
			if (0JE)
			{
				SD = S6.Rows.Fixed;
				SE = S6.Rows.Count - 1;
				S6.TopRow = 0;
			}
			SC = CP(0JD, 0JI: false);
			Rectangle clientRectangle = ((Control)S6).ClientRectangle;
			clientRectangle.Height = 3;
			if (SC > 0)
			{
				clientRectangle.Y = S6.GetCellRectDisplay(SC - 1, -1, clip: true).Bottom - 1;
			}
			SI.CW(clientRectangle);
		}

		private int CO(MouseEventArgs 0JF, bool 0JG)
		{
			int i;
			for (i = (0JG ? S6.LeftCol : S6.Cols.Fixed); i < S6.Cols.Count; i++)
			{
				Rectangle cellRectDisplay = S6.GetCellRectDisplay(-1, i, clip: true);
				if (0JF.X < cellRectDisplay.Left + cellRectDisplay.Width / 2)
				{
					break;
				}
			}
			if (i > SE)
			{
				i = SE + 1;
			}
			if (i < SD)
			{
				i = SD;
			}
			return i;
		}

		private int CP(MouseEventArgs 0JH, bool 0JI)
		{
			int i;
			for (i = (0JI ? S6.TopRow : S6.Rows.Fixed); i < S6.Rows.Count; i++)
			{
				Rectangle cellRectDisplay = S6.GetCellRectDisplay(i, -1, clip: true);
				if (0JH.Y < cellRectDisplay.Top + cellRectDisplay.Height / 2)
				{
					break;
				}
			}
			if (i > SE)
			{
				i = SE + 1;
			}
			if (i < SD)
			{
				i = SD;
			}
			return i;
		}

		private bool CQ(int 0JJ)
		{
			AllowDraggingEnum allowDragging = S6.AllowDragging;
			if (allowDragging != AllowDraggingEnum.Columns && allowDragging != AllowDraggingEnum.Both)
			{
				return false;
			}
			return S6.Cols[0JJ].AllowDragging;
		}

		private bool CR(int 0JK)
		{
			AllowDraggingEnum allowDragging = S6.AllowDragging;
			if (allowDragging != AllowDraggingEnum.Rows && allowDragging != AllowDraggingEnum.Both)
			{
				return false;
			}
			return S6.Rows[0JK].AllowDragging;
		}

		private bool CS(int 0JL)
		{
			if (S6.AllowSorting == AllowSortingEnum.None)
			{
				return false;
			}
			return S6.Cols[0JL].AllowSorting;
		}

		private bool CT(int 0JM, int 0JN)
		{
			Point scrollPosition = S6.ScrollPosition;
			int num = Math.Abs(0JM) * 120;
			for (int i = 1; i < num; i += 12)
			{
				int num2 = scrollPosition.X - i * 0JM;
				S6.ScrollPosition = new Point(num2, scrollPosition.Y);
				if (S6.ScrollPosition.X != num2)
				{
					break;
				}
				((Control)S6).Update();
			}
			num = Math.Abs(0JN) * 80;
			for (int i = 1; i < num; i += 8)
			{
				int num3 = scrollPosition.Y - i * 0JN;
				S6.ScrollPosition = new Point(scrollPosition.X, num3);
				if (S6.ScrollPosition.Y != num3)
				{
					break;
				}
				((Control)S6).Update();
			}
			if (S6.ScrollPosition == scrollPosition)
			{
				return false;
			}
			S7 = 0O.SS;
			return true;
		}

		internal bool CU(bool 0JO)
		{
			int y = S9.Y;
			int x = S9.X;
			if (S6.N1.87(y, x))
			{
				return false;
			}
			if ((S6.Rows[y].TV & 0R.TR) != 0R.TH)
			{
				return false;
			}
			0I 0I2 = S6.X0.BB(y, x);
			if (0I2 != 0I.R1)
			{
				if (S6.N1.8I(y, x))
				{
					return false;
				}
				if (!0JO && !S6.7L(y, x))
				{
					return false;
				}
			}
			if (!S6.StartEditing(y, x, S8, 0JO))
			{
				return false;
			}
			C9();
			return true;
		}
	}
	internal class 0P : Timer
	{
		private bool SY = false;

		public override bool Enabled
		{
			get
			{
				return ((Timer)this).Enabled;
			}
			set
			{
				if (value != ((Timer)this).Enabled)
				{
					Application.DoEvents();
					if (!SY)
					{
						SY = true;
						((Timer)this).Enabled = value;
						SY = false;
					}
				}
			}
		}
	}
	internal class 0Q
	{
		private Rectangle SZ;

		private Control T0;

		private static Brush T1;

		internal 0Q(Control ctl)
		{
			//IL_002f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0039: Expected O, but got Unknown
			T0 = ctl;
			ref Rectangle sZ = ref SZ;
			sZ = new Rectangle(0, 0, 0, 0);
			if (T1 == null)
			{
				T1 = (Brush)new HatchBrush((HatchStyle)12, Color.Black, Color.White);
			}
		}

		internal void CV()
		{
			CW(Rectangle.Empty);
		}

		internal void CW(Rectangle 0JP)
		{
			if (SZ.Equals((object?)0JP))
			{
				return;
			}
			if (SZ.Width > 0 && SZ.Height > 0)
			{
				T0.Invalidate(SZ);
				T0.Update();
			}
			if (0JP.Width > 0 && 0JP.Height > 0)
			{
				Graphics val = T0.CreateGraphics();
				try
				{
					val.FillRectangle(T1, 0JP);
				}
				finally
				{
					((IDisposable)val)?.Dispose();
				}
			}
			SZ = 0JP;
		}
	}
	public struct HitTestInfo
	{
		public readonly int Row;

		public readonly int Column;

		public readonly int X;

		public readonly int Y;

		public readonly HitTestTypeEnum Type;

		internal HitTestInfo(int x, int y, int row, int col, HitTestTypeEnum type)
		{
			Row = ((row < 0) ? (-1) : row);
			Column = ((col < 0) ? (-1) : col);
			X = x;
			Y = y;
			Type = type;
		}
	}
	public enum HitTestTypeEnum
	{
		None,
		Cell,
		ColumnHeader,
		ColumnResize,
		ColumnFreeze,
		RowHeader,
		RowResize,
		RowFreeze,
		Checkbox,
		EditButton,
		OutlineBar,
		OutlineTree
	}
	public enum NodeTypeEnum
	{
		Root,
		Parent,
		FirstChild,
		LastChild,
		FirstSibling,
		LastSibling,
		NextSibling,
		PreviousSibling
	}
	public enum NodeMoveEnum
	{
		In,
		Out,
		Up,
		Down,
		First,
		Last,
		ChildOf
	}
	public class Node
	{
		private Row T2;

		public int Level
		{
			get
			{
				return T2.U2;
			}
			set
			{
				if (T2.U2 != (short)value)
				{
					T2.U2 = (short)value;
					T2.TW.DM();
					T2.TW.DU(GridChangedTypeEnum.RepaintGrid);
				}
			}
		}

		public bool Collapsed
		{
			get
			{
				return (T2.TV & 0R.TQ) != 0R.TH;
			}
			set
			{
				if (Collapsed == value)
				{
					return;
				}
				int safeIndex = T2.SafeIndex;
				0D uE = T2.TW.UE;
				uE.8F(GridChangedTypeEnum.BeforeCollapse, safeIndex, -1);
				if (uE.PM.VS)
				{
					return;
				}
				Point point = CX();
				if (point.X < 0)
				{
					if (Collapsed)
					{
						T2.DD(0R.TQ, 0KH: false);
						uE.8G(GridChangedTypeEnum.RepaintGrid);
					}
					return;
				}
				T2.DD(0R.TQ, value);
				RowCollection pJ = T2.TW.UE.PJ;
				if (uE.X4 == SubtotalPositionEnum.AboveData)
				{
					for (int i = point.X; i <= point.Y; i++)
					{
						Row row = pJ[i];
						row.DD(0R.TI, value);
						if (!value && row.IsNode && (row.TV & 0R.TQ) != 0R.TH)
						{
							Point point2 = row.Node.CX();
							if (point2.Y >= 0)
							{
								i = point2.Y;
							}
						}
					}
				}
				else
				{
					for (int num = point.Y; num >= point.X; num--)
					{
						Row row2 = pJ[num];
						row2.DD(0R.TI, value);
						if (!value && row2.IsNode && (row2.TV & 0R.TQ) != 0R.TH)
						{
							Point point3 = row2.Node.CX();
							if (point3.X >= 0)
							{
								num = point3.X;
							}
						}
					}
				}
				pJ.DM();
				uE.8F(GridChangedTypeEnum.AfterCollapse, safeIndex, -1);
			}
		}

		public bool Expanded
		{
			get
			{
				return !Collapsed;
			}
			set
			{
				Collapsed = !value;
			}
		}

		public int Children
		{
			get
			{
				Point point = CX();
				if (point.X < 0 || point.Y < 0)
				{
					return 0;
				}
				int num = 0;
				int num2 = T2.U2 + 1;
				0D uE = T2.TW.UE;
				for (int i = point.X; i <= point.Y; i++)
				{
					if (uE.PJ[i].IsNode && uE.PJ[i].U2 == num2)
					{
						num++;
					}
				}
				return num;
			}
		}

		public Image Image
		{
			get
			{
				0D uE = T2.TW.UE;
				int safeIndex = T2.SafeIndex;
				int column = uE.PM.Column;
				return new CellRange(uE, safeIndex, column).Image;
			}
			set
			{
				0D uE = T2.TW.UE;
				int safeIndex = T2.SafeIndex;
				int column = uE.PM.Column;
				CellRange cellRange = new CellRange(uE, safeIndex, column);
				cellRange.Image = value;
			}
		}

		public object Key
		{
			get
			{
				return T2.UserData;
			}
			set
			{
				T2.UserData = value;
			}
		}

		public object Data
		{
			get
			{
				0D uE = T2.TW.UE;
				int safeIndex = T2.SafeIndex;
				int column = uE.PM.Column;
				return uE.GetData(safeIndex, column);
			}
			set
			{
				0D uE = T2.TW.UE;
				int safeIndex = T2.SafeIndex;
				int column = uE.PM.Column;
				uE.SetData(safeIndex, column, value);
			}
		}

		public Row Row => T2;

		internal Node(Row row)
		{
			if (!row.IsNode)
			{
				throw new ArgumentException("Source Row is not a node");
			}
			T2 = row;
		}

		public CellRange GetCellRange()
		{
			0D uE = T2.TW.UE;
			Point point = CX();
			point.X = T2.SafeIndex;
			if (point.Y < 0)
			{
				point.Y = point.X;
			}
			return new CellRange(uE, point.X, 0, point.Y, uE.PK.Count - 1);
		}

		public Node GetNode(NodeTypeEnum position)
		{
			0D uE = T2.TW.UE;
			int num = D2(position);
			if (num < 0)
			{
				return null;
			}
			return new Node(uE.PJ[num]);
		}

		public Node AddNode(NodeTypeEnum position, object data, object key, Image img)
		{
			if (position == NodeTypeEnum.Root || position == NodeTypeEnum.Parent)
			{
				throw new ArgumentException("Cannot add Parent/Root nodes");
			}
			0D uE = T2.TW.UE;
			int num = T2.U2;
			if (position == NodeTypeEnum.LastChild || position == NodeTypeEnum.FirstChild)
			{
				num++;
			}
			bool flag = false;
			int num2 = D2(position);
			switch (position)
			{
			case NodeTypeEnum.FirstChild:
				if (num2 < 0)
				{
					flag = true;
				}
				break;
			case NodeTypeEnum.LastChild:
				flag = true;
				break;
			case NodeTypeEnum.LastSibling:
				flag = true;
				break;
			case NodeTypeEnum.PreviousSibling:
				if (num2 >= 0)
				{
					flag = true;
				}
				break;
			case NodeTypeEnum.NextSibling:
				if (num2 < 0)
				{
					flag = true;
				}
				break;
			}
			if (num2 < 0)
			{
				num2 = T2.SafeIndex;
			}
			if (num2 < 0)
			{
				throw new ArgumentException("Cannot find location for new node.");
			}
			if (flag)
			{
				Point point = uE.PJ[num2].Node.CX();
				num2 = ((point.Y > -1) ? (point.Y + 1) : (num2 + 1));
			}
			Row row = uE.PJ.DY(num2, 0L9: false, 0R.TP);
			Node node = row.Node;
			node.Level = num;
			node.Data = data;
			if (img != null)
			{
				node.Image = img;
			}
			if (key != null)
			{
				node.Key = key;
			}
			if (num2 > 0 && !uE.PJ[num2 - 1].Visible)
			{
				node.Collapsed = true;
			}
			return node;
		}

		public Node AddNode(NodeTypeEnum position, object data)
		{
			return AddNode(position, data, null, null);
		}

		public void RemoveNode()
		{
			Point point = CX();
			point.X = T2.SafeIndex;
			if (point.Y < 0)
			{
				point.Y = point.X;
			}
			0D uE = T2.TW.UE;
			bool x = uE.X2;
			uE.X2 = false;
			try
			{
				for (int i = point.X; i <= point.Y; i++)
				{
					uE.PJ.DZ(point.X, 0LC: false);
				}
			}
			finally
			{
				uE.X2 = x;
			}
		}

		public bool Move(NodeMoveEnum moveTo, Node targetNode)
		{
			RowCollection pJ = T2.TW.UE.PJ;
			int num4;
			int num5;
			Point point;
			int num3;
			int num;
			switch (moveTo)
			{
			case NodeMoveEnum.In:
				num = D2(NodeTypeEnum.PreviousSibling);
				if (num < 0)
				{
					return false;
				}
				point = CX();
				for (num = point.X; num <= point.Y; num++)
				{
					if (point.Y <= -1)
					{
						break;
					}
					if (pJ[num].IsNode)
					{
						pJ[num].U2++;
					}
				}
				Level++;
				break;
			case NodeMoveEnum.Out:
				num = D2(NodeTypeEnum.Parent);
				if (num < 0)
				{
					return false;
				}
				point = CX();
				for (num = point.X; num <= point.Y; num++)
				{
					if (point.Y <= -1)
					{
						break;
					}
					if (pJ[num].IsNode)
					{
						pJ[num].U2--;
					}
				}
				Level--;
				break;
			case NodeMoveEnum.First:
				num4 = D2(NodeTypeEnum.FirstSibling);
				goto IL_012f;
			case NodeMoveEnum.Up:
				num4 = D2(NodeTypeEnum.PreviousSibling);
				goto IL_012f;
			case NodeMoveEnum.Last:
				num5 = D2(NodeTypeEnum.LastSibling);
				goto IL_01a1;
			case NodeMoveEnum.Down:
				num5 = D2(NodeTypeEnum.NextSibling);
				goto IL_01a1;
			case NodeMoveEnum.ChildOf:
				{
					if (targetNode == null)
					{
						throw new ArgumentException("Need target node argument for this type of move.");
					}
					if (targetNode.T2 == T2)
					{
						return false;
					}
					if (targetNode == GetNode(NodeTypeEnum.Parent))
					{
						return false;
					}
					point = CX();
					point.X = T2.SafeIndex;
					if (point.Y < 0)
					{
						point.Y = point.X;
					}
					num = targetNode.T2.SafeIndex + 1;
					if (num > point.X && num <= point.Y)
					{
						return false;
					}
					short num2 = (short)(targetNode.Level + 1 - Level);
					bool flag = targetNode.Collapsed || !targetNode.Row.Visible;
					for (int i = point.X; i <= point.Y; i++)
					{
						if (pJ[i].IsNode)
						{
							pJ[i].U2 += num2;
						}
						if (flag)
						{
							pJ[i].Visible = false;
						}
					}
					num3 = point.Y - point.X + 1;
					if (point.X < num)
					{
						num -= num3;
					}
					pJ.MoveRange(point.X, num3, num);
					break;
				}
				IL_012f:
				num = num4;
				if (num < 0)
				{
					return false;
				}
				point = CX();
				point.X = T2.SafeIndex;
				if (point.Y < 0)
				{
					point.Y = point.X;
				}
				num3 = point.Y - point.X + 1;
				pJ.MoveRange(point.X, num3, num);
				break;
				IL_01a1:
				num = num5;
				if (num < 0)
				{
					return false;
				}
				point = pJ[num].Node.CX();
				num = ((point.Y < 0) ? (num + 1) : (point.Y + 1));
				point = CX();
				point.X = T2.SafeIndex;
				if (point.Y < 0)
				{
					point.Y = point.X;
				}
				num3 = point.Y - point.X + 1;
				num -= num3;
				pJ.MoveRange(point.X, num3, num);
				break;
			}
			return true;
		}

		public bool Move(NodeMoveEnum moveTo)
		{
			return Move(moveTo, null);
		}

		public void EnsureVisible()
		{
			T2.Visible = true;
			for (Node node = GetNode(NodeTypeEnum.Parent); node != null; node = node.GetNode(NodeTypeEnum.Parent))
			{
				if (node.Collapsed)
				{
					node.Collapsed = false;
				}
			}
			0D uE = T2.TW.UE;
			int safeIndex = T2.SafeIndex;
			int column = uE.PM.Column;
			uE.8F(GridChangedTypeEnum.EnsureVisible, safeIndex, column);
		}

		public void Select()
		{
			EnsureVisible();
			0D uE = T2.TW.UE;
			int safeIndex = T2.SafeIndex;
			int column = uE.PM.Column;
			uE.8F(GridChangedTypeEnum.Select, safeIndex, column);
		}

		public void Sort(SortFlags order, int col1, int col2)
		{
			Node node = GetNode(NodeTypeEnum.FirstChild);
			if (node != null)
			{
				D3(node, order, col1, col2);
			}
		}

		public void Sort(SortFlags order)
		{
			0D uE = T2.TW.UE;
			int column = uE.PM.Column;
			Sort(order, column, column);
		}

		internal Point CX()
		{
			return CY(T2.TW.UE, T2.SafeIndex);
		}

		internal static Point CY(0D 0JQ, int 0JR)
		{
			Point result = new Point(-1, -1);
			RowCollection pJ = 0JQ.PJ;
			if (!pJ[0JR].IsNode)
			{
				return result;
			}
			if (0JQ.PR == SubtotalPositionEnum.AboveData)
			{
				if (0JR >= pJ.Count - 1)
				{
					return result;
				}
				int u = pJ[0JR].U2;
				if (pJ[0JR + 1].IsNode && pJ[0JR + 1].U2 <= u)
				{
					return result;
				}
				int x = (result.Y = 0JR + 1);
				result.X = x;
				for (int i = result.X; i < pJ.Count; i++)
				{
					if (pJ[i].IsNode && pJ[i].U2 <= u)
					{
						return result;
					}
					result.Y = i;
				}
			}
			else
			{
				if (0JR <= pJ.Fixed)
				{
					return result;
				}
				int u2 = pJ[0JR].U2;
				if (pJ[0JR - 1].IsNode && pJ[0JR - 1].U2 <= u2)
				{
					return result;
				}
				int x = (result.Y = 0JR - 1);
				result.X = x;
				for (int num3 = result.X; num3 >= pJ.Fixed; num3--)
				{
					if (pJ[num3].IsNode && pJ[num3].U2 <= u2)
					{
						return result;
					}
					result.X = num3;
				}
			}
			return result;
		}

		internal int CZ(bool 0JS)
		{
			0D uE = T2.TW.UE;
			RowCollection pJ = uE.PJ;
			int u = T2.U2;
			if (uE.X4 == SubtotalPositionEnum.AboveData)
			{
				for (int num = T2.SafeIndex - 1; num >= 0; num--)
				{
					if (pJ[num].IsNode)
					{
						int u2 = pJ[num].U2;
						if (u2 < u)
						{
							if (!0JS)
							{
								return num;
							}
							if (u2 == pJ.UG)
							{
								return num;
							}
						}
					}
				}
			}
			else
			{
				for (int i = T2.SafeIndex + 1; i < pJ.Count; i++)
				{
					if (!pJ[i].IsNode)
					{
						continue;
					}
					int u3 = pJ[i].U2;
					if (u3 < u)
					{
						if (!0JS)
						{
							return i;
						}
						if (u3 == pJ.UG)
						{
							return i;
						}
					}
				}
			}
			return -1;
		}

		internal int D0(int 0JT)
		{
			RowCollection pJ = T2.TW.UE.PJ;
			int num = T2.U2 + 1;
			Point point = CX();
			if (point.X < 0)
			{
				return -1;
			}
			for (int i = point.X; i <= point.Y; i++)
			{
				if (!pJ[i].IsNode)
				{
					continue;
				}
				int u = pJ[i].U2;
				if (u <= num)
				{
					if (0JT == 0)
					{
						return i;
					}
					0JT--;
				}
			}
			return -1;
		}

		internal int D1(NodeTypeEnum 0JU)
		{
			RowCollection pJ = T2.TW.UE.PJ;
			int u = T2.U2;
			int safeIndex = T2.SafeIndex;
			int result = -1;
			switch (0JU)
			{
			case NodeTypeEnum.NextSibling:
				for (safeIndex++; safeIndex < pJ.Count; safeIndex++)
				{
					if (!pJ[safeIndex].IsNode)
					{
						continue;
					}
					int u4 = pJ[safeIndex].U2;
					if (u4 <= u)
					{
						if (u4 < u)
						{
							return -1;
						}
						return safeIndex;
					}
				}
				break;
			case NodeTypeEnum.PreviousSibling:
				for (safeIndex--; safeIndex >= 0; safeIndex--)
				{
					if (pJ[safeIndex].IsNode)
					{
						int u3 = pJ[safeIndex].U2;
						if (u3 <= u)
						{
							if (u3 < u)
							{
								return -1;
							}
							return safeIndex;
						}
					}
				}
				break;
			case NodeTypeEnum.FirstSibling:
				for (safeIndex--; safeIndex >= 0; safeIndex--)
				{
					if (pJ[safeIndex].IsNode)
					{
						int u5 = pJ[safeIndex].U2;
						if (u5 <= u)
						{
							if (u5 < u)
							{
								return result;
							}
							result = safeIndex;
						}
					}
				}
				return result;
			case NodeTypeEnum.LastSibling:
				for (safeIndex = safeIndex; safeIndex < pJ.Count; safeIndex++)
				{
					if (!pJ[safeIndex].IsNode)
					{
						continue;
					}
					int u2 = pJ[safeIndex].U2;
					if (u2 <= u)
					{
						if (u2 < u)
						{
							return result;
						}
						result = safeIndex;
					}
				}
				return result;
			}
			return -1;
		}

		internal int D2(NodeTypeEnum 0JV)
		{
			_ = T2.TW.UE.PJ;
			_ = T2.SafeIndex;
			_ = T2.U2;
			int result = -1;
			switch (0JV)
			{
			case NodeTypeEnum.Root:
				result = CZ(0JS: true);
				break;
			case NodeTypeEnum.Parent:
				result = CZ(0JS: false);
				break;
			case NodeTypeEnum.FirstChild:
				result = D0(0);
				break;
			case NodeTypeEnum.LastChild:
				result = D0(Children - 1);
				break;
			case NodeTypeEnum.FirstSibling:
				result = D1(0JV);
				break;
			case NodeTypeEnum.LastSibling:
				result = D1(0JV);
				break;
			case NodeTypeEnum.NextSibling:
				result = D1(0JV);
				break;
			case NodeTypeEnum.PreviousSibling:
				result = D1(0JV);
				break;
			}
			return result;
		}

		internal static void D3(Node 0JW, SortFlags 0JX, int 0JY, int 0JZ)
		{
			0D uE = 0JW.Row.TW.UE;
			uE.9I();
			ArrayList arrayList = new ArrayList();
			while (0JW != null)
			{
				arrayList.Add(0JW.Row);
				0JW = 0JW.GetNode(NodeTypeEnum.NextSibling);
			}
			0T comparer = new 0T(uE, 0JX, 0JY, 0JZ);
			arrayList.Sort(comparer);
			for (int num = arrayList.Count - 1; num >= 0; num--)
			{
				0JW = ((Row)arrayList[num]).Node;
				0JW.Move(NodeMoveEnum.First);
			}
		}
	}
	[Flags]
	public enum PrintGridFlags
	{
		ActualSize = 0,
		FitToPageWidth = 1,
		FitToPage = 2,
		ShowPageSetupDialog = 4,
		ShowPrintDialog = 8,
		ShowPreviewDialog = 0x10
	}
	public class GridPrinter
	{
		private C1FlexGridBase T3;

		private PrintDocument T4;

		private PrintPreviewDialog T5;

		private PrintGridFlags T6;

		private double T7;

		private string T8;

		private string T9;

		private Font TA;

		private Font TB;

		private int TC;

		private int TD;

		private Rectangle TE;

		private ArrayList TF;

		private ArrayList TG;

		public PrintDocument PrintDocument => T4;

		public Font HeaderFont
		{
			get
			{
				return TA;
			}
			set
			{
				if (value != null)
				{
					TA = value;
				}
			}
		}

		public Font FooterFont
		{
			get
			{
				return TB;
			}
			set
			{
				if (value != null)
				{
					TB = value;
				}
			}
		}

		public int PageNumber => TC + 1;

		public int PageCount => TD;

		public PrintPreviewDialog PrintPreviewDialog
		{
			get
			{
				//IL_0009: Unknown result type (might be due to invalid IL or missing references)
				//IL_0013: Expected O, but got Unknown
				if (T5 == null)
				{
					T5 = new PrintPreviewDialog();
					T5.StartPosition = (FormStartPosition)4;
					((Control)T5).Width = (int)((double)((Control)T5).Width * 1.5);
				}
				return T5;
			}
		}

		public PrintGridFlags PrintGridFlags
		{
			get
			{
				return T6;
			}
			set
			{
				T6 = value;
			}
		}

		public string Header
		{
			get
			{
				return T8;
			}
			set
			{
				T8 = ((value != null) ? value : string.Empty);
			}
		}

		public string Footer
		{
			get
			{
				return T9;
			}
			set
			{
				T9 = ((value != null) ? value : string.Empty);
			}
		}

		internal GridPrinter(C1FlexGridBase view)
		{
			//IL_000e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Expected O, but got Unknown
			//IL_0025: Unknown result type (might be due to invalid IL or missing references)
			//IL_002f: Expected O, but got Unknown
			//IL_003c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0046: Expected O, but got Unknown
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_005d: Expected O, but got Unknown
			//IL_0070: Unknown result type (might be due to invalid IL or missing references)
			//IL_007a: Expected O, but got Unknown
			T3 = view;
			T4 = new PrintDocument();
			T4.BeginPrint += new PrintEventHandler(D5);
			T4.EndPrint += new PrintEventHandler(D6);
			T4.PrintPage += new PrintPageEventHandler(D7);
			if (Environment.OSVersion.Platform < PlatformID.Win32NT)
			{
				T4.PrintController = (PrintController)new StandardPrintController();
			}
			T4.DocumentName = "C1FlexGrid";
			TA = (TB = ((Control)T3).Font);
			T8 = "";
			T9 = "\t\tPage {0} of {1}";
		}

		internal bool D4(string 0K0, PrintGridFlags 0K1)
		{
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0023: Expected O, but got Unknown
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_0059: Expected O, but got Unknown
			//IL_0030: Unknown result type (might be due to invalid IL or missing references)
			//IL_0036: Invalid comparison between Unknown and I4
			//IL_009e: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a3: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a4: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a6: Invalid comparison between Unknown and I4
			//IL_0066: Unknown result type (might be due to invalid IL or missing references)
			//IL_006c: Invalid comparison between Unknown and I4
			T4.DocumentName = 0K0;
			T6 = 0K1;
			if ((T6 & PrintGridFlags.ShowPrintDialog) != PrintGridFlags.ActualSize)
			{
				PrintDialog val = new PrintDialog();
				try
				{
					val.Document = T4;
					if ((int)((CommonDialog)val).ShowDialog() != 1)
					{
						return false;
					}
				}
				finally
				{
					((IDisposable)val)?.Dispose();
				}
			}
			if ((T6 & PrintGridFlags.ShowPageSetupDialog) != PrintGridFlags.ActualSize)
			{
				PageSetupDialog val2 = new PageSetupDialog();
				try
				{
					val2.Document = T4;
					if ((int)((CommonDialog)val2).ShowDialog() != 1)
					{
						return false;
					}
				}
				finally
				{
					((IDisposable)val2)?.Dispose();
				}
			}
			if ((T6 & PrintGridFlags.ShowPreviewDialog) != PrintGridFlags.ActualSize)
			{
				PrintPreviewDialog printPreviewDialog = PrintPreviewDialog;
				printPreviewDialog.Document = T4;
				DialogResult val3 = ((Form)printPreviewDialog).ShowDialog();
				return (int)val3 != 2;
			}
			T4.Print();
			return true;
		}

		private void D5(object 0K2, PrintEventArgs 0K3)
		{
			D9();
			TC = 0;
			T3.OnBeginPrint(0K3);
		}

		private void D6(object 0K4, PrintEventArgs 0K5)
		{
			T3.OnEndPrint(0K5);
			TC = 0;
			TD = 0;
		}

		private void D7(object 0K6, PrintPageEventArgs 0K7)
		{
			if (TC >= TD)
			{
				0K7.HasMorePages = false;
				0K7.Cancel = true;
				return;
			}
			Graphics graphics = 0K7.Graphics;
			int 0KC = (0K7.PageBounds.Top + 0K7.MarginBounds.Top) / 2;
			D8(graphics, T8, TA, 0K7.MarginBounds, 0KC);
			0KC = (0K7.PageBounds.Bottom + 0K7.MarginBounds.Bottom) / 2;
			D8(graphics, T9, TB, 0K7.MarginBounds, 0KC);
			Image val = DC(TC);
			Rectangle marginBounds = 0K7.MarginBounds;
			marginBounds.Width = (int)((double)val.Width / T7);
			marginBounds.Height = (int)((double)val.Height / T7);
			graphics.DrawImage(val, marginBounds);
			val.Dispose();
			T3.OnPrintPage(0K7);
			TC++;
			0K7.HasMorePages = TC < TD;
		}

		private void D8(Graphics 0K8, string 0K9, Font 0KA, Rectangle 0KB, int 0KC)
		{
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Expected O, but got Unknown
			if (0K9 != null && 0K9.Length != 0)
			{
				StringFormat val = new StringFormat();
				0KC -= 0KA.Height / 2;
				if (0K9.IndexOf("{0}") > -1)
				{
					0K9 = 0K9.Replace("{0}", (TC + 1).ToString(CultureInfo.CurrentCulture));
				}
				if (0K9.IndexOf("{1}") > -1)
				{
					0K9 = 0K9.Replace("{1}", TD.ToString(CultureInfo.CurrentCulture));
				}
				string[] array = 0K9.Split(new char[1] { '\t' });
				if (array.Length > 0 && array[0].Length > 0)
				{
					val.Alignment = (StringAlignment)0;
					0K8.DrawString(array[0], 0KA, Brushes.Black, (float)0KB.Left, (float)0KC, val);
				}
				if (array.Length > 1 && array[1].Length > 0)
				{
					val.Alignment = (StringAlignment)1;
					0K8.DrawString(array[1], 0KA, Brushes.Black, (float)((0KB.Left + 0KB.Right) / 2), (float)0KC, val);
				}
				if (array.Length > 2 && array[2].Length > 0)
				{
					val.Alignment = (StringAlignment)2;
					0K8.DrawString(array[2], 0KA, Brushes.Black, (float)0KB.Right, (float)0KC, val);
				}
			}
		}

		private void D9()
		{
			DA();
			DB();
		}

		private void DA()
		{
			PageSettings defaultPageSettings = T4.DefaultPageSettings;
			Rectangle bounds = defaultPageSettings.Bounds;
			Margins margins = defaultPageSettings.Margins;
			bounds.Width -= margins.Left + margins.Right;
			bounds.Height -= margins.Top + margins.Bottom;
			T7 = 1.0;
			int count = T3.Cols.Count;
			int count2 = T3.Rows.Count;
			if (count == 0 || count2 == 0)
			{
				return;
			}
			if ((T6 & PrintGridFlags.FitToPage) != PrintGridFlags.ActualSize)
			{
				double num = T3.Cols[count - 1].Right;
				double num2 = T3.Rows[count2 - 1].Bottom;
				double num3 = Math.Max(num / (double)bounds.Width, num2 / (double)bounds.Height);
				if (num3 > 1.0)
				{
					T7 = num3;
				}
			}
			else if ((T6 & PrintGridFlags.FitToPageWidth) != PrintGridFlags.ActualSize)
			{
				double num4 = T3.Cols[count - 1].Right;
				if (num4 > (double)bounds.Width)
				{
					T7 = num4 / (double)bounds.Width;
				}
			}
			bounds.Width = (int)((double)bounds.Width * T7);
			bounds.Height = (int)((double)bounds.Height * T7);
			TE = bounds;
		}

		private void DB()
		{
			TD = 0;
			ColumnCollection cols = T3.Cols;
			if (cols.Count == 0)
			{
				return;
			}
			int num = cols.Fixed + cols.Frozen;
			int num2 = ((num != 0) ? cols[num - 1].Right : 0);
			RowCollection rows = T3.Rows;
			if (rows.Count == 0)
			{
				return;
			}
			int num3 = rows.Fixed + rows.Frozen;
			int num4 = ((num3 != 0) ? rows[num3 - 1].Bottom : 0);
			bool flag = (T6 & PrintGridFlags.FitToPage) == 0;
			bool flag2 = (T6 & PrintGridFlags.FitToPage) == 0 && (T6 & PrintGridFlags.FitToPageWidth) == 0;
			TF = new ArrayList();
			int num5 = num4;
			int num6 = num3;
			int num7 = num3;
			while (flag && num7 < rows.Count)
			{
				if (num7 > num6 && num5 + rows[num7].HeightDisplay > TE.Height)
				{
					for (int num8 = num7; num8 > num6 + 1; num8--)
					{
						RowColEventArgs e = new RowColEventArgs(num8, -1);
						T3.OnBeforePageBreak(e);
						if (!e.Cancel)
						{
							num7 = num8;
							break;
						}
					}
					TF.Add(num7 - 1);
					num6 = num7;
					num5 = num4;
				}
				num5 += rows[num7].HeightDisplay;
				num7++;
			}
			TF.Add(rows.Count - 1);
			TG = new ArrayList();
			int num9 = num2;
			num6 = num;
			int num10 = num;
			while (flag2 && num10 < cols.Count)
			{
				if (num10 > num6 && num9 + cols[num10].WidthDisplay > TE.Width)
				{
					TG.Add(num10 - 1);
					num6 = num10;
					num9 = num2;
				}
				num9 += cols[num10].WidthDisplay;
				num10++;
			}
			TG.Add(cols.Count - 1);
			TD = TF.Count * TG.Count;
		}

		private Image DC(int 0KD)
		{
			CellRange cellRange = T3.GetCellRange(0, 0);
			cellRange.c2 = T3.Cols.Fixed + T3.Cols.Frozen - 1;
			for (int i = 0; i < TG.Count; i++)
			{
				cellRange.c1 = cellRange.c2 + 1;
				cellRange.c2 = (int)TG[i];
				cellRange.r2 = T3.Rows.Fixed + T3.Rows.Frozen - 1;
				for (int j = 0; j < TF.Count; j++)
				{
					cellRange.r1 = cellRange.r2 + 1;
					cellRange.r2 = (int)TF[j];
					if (0KD == 0)
					{
						cellRange.r1 = Math.Min(cellRange.r1, T3.Rows.Count - 1);
						cellRange.c1 = Math.Min(cellRange.c1, T3.Cols.Count - 1);
						return T3.CreateImage(cellRange, (EmfType)3);
					}
					0KD--;
				}
			}
			return null;
		}
	}
	[Flags]
	internal enum 0R : short
	{
		TH = 0,
		TI = 1,
		TJ = 2,
		TK = 4,
		TL = 8,
		TM = 0x10,
		TN = 0x20,
		TO = 0x40,
		TP = 0x80,
		TQ = 0x100,
		TR = 0x200
	}
	public abstract class RowCol
	{
		internal int TS;

		internal int TT;

		internal int TU;

		internal 0R TV;

		internal RowColCollection TW;

		internal Style TX;

		internal Style TY;

		internal object TZ;

		[D("Visible", "Gets or sets whether a Row or Column is visible.")]
		[DefaultValue(true)]
		[E("Layout")]
		public virtual bool Visible
		{
			get
			{
				return (TV & 0R.TI) == 0R.TH;
			}
			set
			{
				if (Visible != value)
				{
					DD(0R.TI, !value);
					DF();
					TW.DU(GridChangedTypeEnum.GridChanged);
				}
			}
		}

		[Browsable(false)]
		public virtual bool Selected
		{
			get
			{
				return (TV & 0R.TJ) != 0R.TH;
			}
			set
			{
				if (Selected != value)
				{
					DD(0R.TJ, value);
					Invalidate();
				}
			}
		}

		[Browsable(false)]
		public virtual object UserData
		{
			get
			{
				return TZ;
			}
			set
			{
				TZ = value;
			}
		}

		[Category("Behavior")]
		[D("Col.AllowDragging", "Gets or sets whether a Row or Column can be dragged with the mouse to a new position.")]
		[DefaultValue(true)]
		public virtual bool AllowDragging
		{
			get
			{
				return (TV & 0R.TK) == 0R.TH;
			}
			set
			{
				if (AllowDragging != value)
				{
					DD(0R.TK, !value);
				}
			}
		}

		[D("Col.AllowResizing", "Gets or sets whether a Row or Column can be resized with the mouse.")]
		[DefaultValue(true)]
		[Category("Behavior")]
		public virtual bool AllowResizing
		{
			get
			{
				return (TV & 0R.TM) == 0R.TH;
			}
			set
			{
				if (AllowResizing != value)
				{
					DD(0R.TM, !value);
				}
			}
		}

		[DefaultValue(false)]
		[Category("Behavior")]
		[D("Col.AllowMerging", "Gets or sets whether cells in a Row or Column can be merged with adjacent cells.")]
		public virtual bool AllowMerging
		{
			get
			{
				return (TV & 0R.TO) != 0R.TH;
			}
			set
			{
				if (AllowMerging != value)
				{
					DD(0R.TO, value);
					TW.DU(GridChangedTypeEnum.RepaintGrid);
				}
			}
		}

		[D("Col.AllowEditing", "Gets or sets whether cells in a Row or Column can be edited.")]
		[Category("Behavior")]
		[DefaultValue(true)]
		public virtual bool AllowEditing
		{
			get
			{
				return (TV & 0R.TN) == 0R.TH;
			}
			set
			{
				if (AllowEditing != value)
				{
					DD(0R.TN, !value);
				}
			}
		}

		[RefreshProperties(RefreshProperties.Repaint)]
		[D("DataType", "Gets or sets the type of object stored in a Row or Column.")]
		[E("Layout")]
		[TypeConverter(typeof(GridDataTypeConverter))]
		public virtual Type DataType
		{
			get
			{
				return StyleDisplay.DataType;
			}
			set
			{
				StyleNew.DataType = value;
				if ((object)value == typeof(bool) || (object)value == typeof(Image))
				{
					ImageAlign = ImageAlignEnum.CenterCenter;
				}
				else if ((object)value == typeof(string))
				{
					TextAlign = TextAlignEnum.LeftCenter;
				}
				else if ((object)value == typeof(DateTime))
				{
					TextAlign = TextAlignEnum.LeftCenter;
					Format = "d";
				}
				else if ((object)value != null && value.IsAssignableFrom(typeof(int)))
				{
					TextAlign = TextAlignEnum.RightCenter;
				}
				if (Format == "d" && (object)value != typeof(DateTime))
				{
					Format = null;
				}
			}
		}

		[DefaultValue(null)]
		[D("Format", "Gets or sets the format used to display values in a Row or Column.")]
		[Category("Appearance")]
		public string Format
		{
			get
			{
				return StyleDisplay.Format;
			}
			set
			{
				StyleNew.Format = value;
			}
		}

		[DefaultValue(null)]
		[D("Col.EditMask", "Gets or sets the edit mask to be used when editing entries in a Row or Column.")]
		[Category("Behavior")]
		public string EditMask
		{
			get
			{
				return StyleDisplay.EditMask;
			}
			set
			{
				StyleNew.EditMask = value;
			}
		}

		[Browsable(false)]
		public virtual int Index => TW.U6.IndexOf(this);

		[Browsable(false)]
		public virtual CellStyle Style
		{
			get
			{
				if (TX == null)
				{
					return null;
				}
				return new CellStyle(TX);
			}
			set
			{
				Style style = value?.VA;
				if (style != TX)
				{
					TX = style;
					Invalidate();
				}
			}
		}

		[Browsable(false)]
		public virtual CellStyle StyleNew
		{
			get
			{
				if (TX == null && TW != null)
				{
					TX = TW.DQ();
				}
				if (TX != null)
				{
					return new CellStyle(TX);
				}
				return null;
			}
		}

		[Browsable(false)]
		public virtual CellStyle StyleDisplay
		{
			get
			{
				Style style = TX;
				if (style == null && TW != null)
				{
					style = TW.DR(CellStyleEnum.Normal);
				}
				if (style != null)
				{
					return new CellStyle(style);
				}
				return null;
			}
		}

		[Browsable(false)]
		public virtual CellStyle StyleFixed
		{
			get
			{
				if (TY == null)
				{
					return null;
				}
				return new CellStyle(TY);
			}
			set
			{
				Style style = value?.VA;
				if (style != TY)
				{
					TY = style;
					Invalidate();
				}
			}
		}

		[Browsable(false)]
		public virtual CellStyle StyleFixedNew
		{
			get
			{
				if (TY == null && TW != null)
				{
					TY = TW.DQ();
				}
				if (TY != null)
				{
					return new CellStyle(TY);
				}
				return null;
			}
		}

		[Browsable(false)]
		public virtual CellStyle StyleFixedDisplay
		{
			get
			{
				Style style = TY;
				if (style == null && TW != null)
				{
					style = TW.DR(CellStyleEnum.Fixed);
				}
				if (style != null)
				{
					return new CellStyle(style);
				}
				return null;
			}
		}

		[DefaultValue(TextAlignEnum.GeneralCenter)]
		[Category("Appearance")]
		[D("Col.TextAlign", "Gets or sets the alignment for text in a Row or Column.")]
		public TextAlignEnum TextAlign
		{
			get
			{
				return StyleDisplay.TextAlign;
			}
			set
			{
				StyleNew.TextAlign = value;
			}
		}

		[Category("Appearance")]
		[DefaultValue(TextAlignEnum.GeneralCenter)]
		[D("Col.TextAlignFixed", "Gets or sets the alignment for text in fixed cells in a Row or Column.")]
		public TextAlignEnum TextAlignFixed
		{
			get
			{
				return StyleFixedDisplay.TextAlign;
			}
			set
			{
				StyleFixedNew.TextAlign = value;
			}
		}

		[Category("Appearance")]
		[D("Col.ImageAlign", "Gets or sets the alignment for images in a Row or Column.")]
		[DefaultValue(ImageAlignEnum.LeftCenter)]
		public ImageAlignEnum ImageAlign
		{
			get
			{
				return StyleDisplay.ImageAlign;
			}
			set
			{
				StyleNew.ImageAlign = value;
			}
		}

		[Browsable(false)]
		public System.Collections.IDictionary ImageMap
		{
			get
			{
				return StyleDisplay.ImageMap;
			}
			set
			{
				StyleNew.ImageMap = value;
			}
		}

		[Browsable(false)]
		public bool ImageAndText
		{
			get
			{
				return StyleDisplay.Display != DisplayEnum.ImageOnly;
			}
			set
			{
				StyleNew.Display = ((!value) ? DisplayEnum.ImageOnly : DisplayEnum.Stack);
			}
		}

		[Browsable(false)]
		public System.Collections.IDictionary DataMap
		{
			get
			{
				return StyleDisplay.DataMap;
			}
			set
			{
				StyleNew.DataMap = value;
			}
		}

		[Category("Behavior")]
		[DefaultValue(null)]
		[D("Col.ComboList", "Gets or sets a pipe-delimited list of items used in the list editor for a Row or Column.")]
		public string ComboList
		{
			get
			{
				return StyleDisplay.ComboList;
			}
			set
			{
				StyleNew.ComboList = value;
			}
		}

		internal int XB
		{
			get
			{
				return TS;
			}
			set
			{
				if (TS != value)
				{
					TS = value;
					DF();
					TW.DU(GridChangedTypeEnum.GridChanged);
				}
			}
		}

		internal int XC
		{
			get
			{
				if (!Visible)
				{
					return 0;
				}
				if (TW == null)
				{
					return Math.Max(0, TS);
				}
				int num = ((TS < 0) ? TW.UA : TS);
				if (num < TW.UB)
				{
					num = TW.UB;
				}
				if (TW.UC > 0 && num > TW.UC)
				{
					num = TW.UC;
				}
				return num;
			}
			set
			{
				Visible = true;
				XB = value;
			}
		}

		internal int XD
		{
			get
			{
				if (TW == null)
				{
					return 0;
				}
				if (TW.U9)
				{
					TW.Update();
				}
				return TT;
			}
		}

		internal int XE => XD + XC;

		protected RowCol()
		{
			TS = -1;
		}

		[Browsable(false)]
		public virtual void Clear(ClearFlags clearFlags)
		{
			if ((clearFlags & ClearFlags.UserData) != 0)
			{
				UserData = null;
			}
			if ((clearFlags & ClearFlags.Style) != 0)
			{
				TX = (TY = null);
			}
			if ((clearFlags & ClearFlags.Style) != 0)
			{
				TV &= 0R.TR;
				TS = -1;
				DF();
			}
			Invalidate();
		}

		public virtual void Move(int indexNew)
		{
			if (indexNew != Index)
			{
				TW.U6.RemoveAt(Index);
				TW.U6.Insert(indexNew, this);
				TW.DM();
			}
		}

		public abstract void Invalidate();

		internal void DD(0R 0KG, bool 0KH)
		{
			if (0KH)
			{
				TV |= 0KG;
			}
			else
			{
				TV = (0R)((int)TV & ~(int)0KG);
			}
		}

		internal bool DE(0R 0KI, bool 0KJ)
		{
			0R tV = TV;
			if (0KJ)
			{
				TV |= 0KI;
			}
			else
			{
				TV = (0R)((int)TV & ~(int)0KI);
			}
			return TV != tV;
		}

		internal void DF()
		{
			if (TW != null)
			{
				TW.DM();
			}
		}
	}
	public class Row : RowCol
	{
		internal ArrayList U0;

		internal ArrayList U1;

		internal short U2;

		internal int U3;

		[Browsable(false)]
		public object this[int columnIndex]
		{
			get
			{
				return TW.UE.GetData(Index, columnIndex);
			}
			set
			{
				TW.UE.SetData(Index, columnIndex, value);
			}
		}

		[Browsable(false)]
		public object this[string columnName]
		{
			get
			{
				return TW.UE.GetData(Index, TW.UE.PK.E3(columnName));
			}
			set
			{
				TW.UE.SetData(Index, TW.UE.PK.E3(columnName), value);
			}
		}

		public int Top => base.XD;

		public int Bottom => base.XE;

		public int Height
		{
			get
			{
				return base.XB;
			}
			set
			{
				base.XB = value;
			}
		}

		public int HeightDisplay
		{
			get
			{
				return base.XC;
			}
			set
			{
				base.XC = value;
			}
		}

		public override int Index
		{
			get
			{
				TW.Update();
				return U3;
			}
		}

		public virtual int SafeIndex
		{
			get
			{
				int index = Index;
				if (index < 0)
				{
					throw new Exception("Row does not belong to grid.");
				}
				return index;
			}
		}

		public int DataIndex
		{
			get
			{
				TW.Update();
				return TU;
			}
		}

		[Browsable(false)]
		public string Caption
		{
			get
			{
				0D uE = TW.UE;
				if (uE != null && uE.PJ.U7 > 0)
				{
					return uE.GetDataDisplay(SafeIndex, 0);
				}
				return "";
			}
			set
			{
				0D uE = TW.UE;
				if (uE != null && uE.PJ.U7 > 0)
				{
					uE.SetData(SafeIndex, 0, value, coerce: false);
				}
			}
		}

		[Browsable(false)]
		public bool IsNew => (TV & 0R.TR) != 0R.TH;

		public bool IsNode
		{
			get
			{
				return (TV & 0R.TP) != 0R.TH;
			}
			set
			{
				if (IsNode != value)
				{
					0D uE = TW.UE;
					uE.9I();
					if (!value)
					{
						Node.Collapsed = false;
					}
					uE.PM.F8(this, value);
				}
			}
		}

		public Node Node => TW.UE.PM.F9(this);

		[Browsable(false)]
		public override bool Selected
		{
			get
			{
				return (TV & 0R.TJ) != 0R.TH;
			}
			set
			{
				if (Selected != value)
				{
					TW.DU(GridChangedTypeEnum.BeforeSelChange);
					DD(0R.TJ, value);
					TW.DT(GridChangedTypeEnum.RowSelected, Index, -1);
					TW.DT(GridChangedTypeEnum.AfterSelChange, Index, -1);
				}
			}
		}

		internal Row(RowCollection coll)
		{
			TW = coll;
		}

		[Browsable(false)]
		public override void Clear(ClearFlags clearFlags)
		{
			base.Clear(clearFlags);
			if ((clearFlags & ClearFlags.Content) != 0)
			{
				0D uE = TW.UE;
				int index = Index;
				for (int i = 0; i < uE.PK.Count; i++)
				{
					uE.95(index, i, ClearFlags.Content);
				}
			}
		}

		public override void Move(int indexNew)
		{
			int index = Index;
			if (index != indexNew)
			{
				base.Move(indexNew);
				TW.DS(GridChangedTypeEnum.RowMoved, index, -1, indexNew, -1);
			}
		}

		public override void Invalidate()
		{
			if (TW.UE.X2)
			{
				TW.DT(GridChangedTypeEnum.RepaintRange, Index, -1);
			}
		}
	}
	public class Column : RowCol
	{
		internal string U4;

		internal SortFlags U5;

		[Browsable(false)]
		public object this[int rowIndex]
		{
			get
			{
				return TW.UE.GetData(rowIndex, Index);
			}
			set
			{
				TW.UE.SetData(rowIndex, Index, value);
			}
		}

		[Browsable(false)]
		public int Left => base.XD;

		[Browsable(false)]
		public int Right => base.XE;

		[D("Width", "Gets or sets the width for this column (-1 means use default width).")]
		[E("Layout")]
		[DefaultValue(-1)]
		public int Width
		{
			get
			{
				return base.XB;
			}
			set
			{
				base.XB = value;
			}
		}

		[Browsable(false)]
		public int WidthDisplay
		{
			get
			{
				return base.XC;
			}
			set
			{
				base.XC = value;
			}
		}

		[Browsable(false)]
		public virtual int SafeIndex
		{
			get
			{
				int index = Index;
				if (index < 0)
				{
					throw new Exception("Column does not belong to grid.");
				}
				return index;
			}
		}

		[Browsable(false)]
		public int DataIndex
		{
			get
			{
				0D uE = TW.UE;
				if (uE.9H())
				{
					return uE.PO.AN(U4);
				}
				int num = Index - TW.U7;
				if (num >= 0)
				{
					return num;
				}
				return -1;
			}
		}

		[DefaultValue(true)]
		[Category("Behavior")]
		[D("Col.AllowSorting", "Gets or sets whether this column can be sorted by clicking on the column header.")]
		public bool AllowSorting
		{
			get
			{
				return (TV & 0R.TL) == 0R.TH;
			}
			set
			{
				if (AllowSorting != value)
				{
					DD(0R.TL, !value);
				}
			}
		}

		[D("Col.Name", "Gets or sets the name for this column (can be used as an indexer).")]
		[MergableProperty(false)]
		[DefaultValue(null)]
		[E("Layout")]
		public string Name
		{
			get
			{
				if (U4 == null)
				{
					return "";
				}
				return U4;
			}
			set
			{
				U4 = value;
				TW.DU(GridChangedTypeEnum.RepaintGrid);
			}
		}

		[Browsable(false)]
		public SortFlags Sort
		{
			get
			{
				return U5;
			}
			set
			{
				U5 = value;
			}
		}

		[Browsable(false)]
		public override int Index => TW.UE.PK.U6.IndexOf(this);

		[Browsable(false)]
		public override bool Selected
		{
			get
			{
				return (TV & 0R.TJ) != 0R.TH;
			}
			set
			{
				if (Selected != value)
				{
					TW.DU(GridChangedTypeEnum.BeforeSelChange);
					DD(0R.TJ, value);
					TW.DT(GridChangedTypeEnum.ColSelected, -1, Index);
					TW.DT(GridChangedTypeEnum.AfterSelChange, -1, Index);
				}
			}
		}

		[E("Layout")]
		[DefaultValue(null)]
		[D("Caption", "Gets or sets the caption for a Row or Column (text at first fixed cell).")]
		public string Caption
		{
			get
			{
				0D uE = TW.UE;
				if (uE != null && uE.PJ.U7 > 0)
				{
					return uE.GetDataDisplay(0, SafeIndex);
				}
				return "";
			}
			set
			{
				0D uE = TW.UE;
				if (uE != null && uE.PJ.U7 > 0)
				{
					uE.SetData(0, SafeIndex, value, coerce: false);
				}
			}
		}

		internal Column(ColumnCollection coll, int index)
		{
			TW = coll;
			TU = index;
		}

		public override void Invalidate()
		{
			if (TW.UE.X2)
			{
				TW.DT(GridChangedTypeEnum.RepaintRange, -1, Index);
			}
		}

		[Browsable(false)]
		public override void Clear(ClearFlags clearFlags)
		{
			base.Clear(clearFlags);
			if ((clearFlags & ClearFlags.Content) != 0 && (TV & 0R.TR) == 0R.TH)
			{
				0D uE = TW.UE;
				int index = Index;
				for (int i = 0; i < uE.PJ.Count; i++)
				{
					uE.95(i, index, ClearFlags.Content);
				}
			}
		}

		public override void Move(int indexNew)
		{
			int index = Index;
			if (index != indexNew)
			{
				base.Move(indexNew);
				TW.DS(GridChangedTypeEnum.ColMoved, -1, index, -1, indexNew);
			}
		}

		internal string DG(bool 0KK)
		{
			StringBuilder stringBuilder = new StringBuilder();
			PropertyInfo[] properties = GetType().GetProperties();
			PropertyInfo[] array = properties;
			foreach (PropertyInfo propertyInfo in array)
			{
				if (!DI(propertyInfo))
				{
					continue;
				}
				object obj = propertyInfo.GetValue(this, null);
				if (obj == null || (!0KK && DJ(propertyInfo, obj)))
				{
					continue;
				}
				if (obj is string)
				{
					if (((string)obj).Length == 0)
					{
						continue;
					}
					obj = 06.5N((string)obj);
				}
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "{0}:{1};", new object[2]
				{
					propertyInfo.Name,
					06.5M(obj)
				});
			}
			return stringBuilder.ToString();
		}

		internal bool DH(string 0KL)
		{
			PropertyInfo[] properties = GetType().GetProperties();
			PropertyInfo[] array = properties;
			foreach (PropertyInfo propertyInfo in array)
			{
				if (!DI(propertyInfo))
				{
					continue;
				}
				string text = 06.5O(0KL, propertyInfo.Name);
				if (text != null)
				{
					try
					{
						object value = 06.5L(text, propertyInfo.PropertyType);
						propertyInfo.SetValue(this, value, null);
					}
					catch
					{
					}
				}
			}
			return true;
		}

		internal bool DI(PropertyInfo 0KM)
		{
			if (!0KM.CanRead || !0KM.CanWrite)
			{
				return false;
			}
			object[] customAttributes = 0KM.GetCustomAttributes(typeof(BrowsableAttribute), inherit: true);
			if (customAttributes.Length == 0)
			{
				return true;
			}
			BrowsableAttribute browsableAttribute = (BrowsableAttribute)customAttributes[0];
			return browsableAttribute.Browsable;
		}

		internal bool DJ(PropertyInfo 0KN, object 0KO)
		{
			if (0KO == null)
			{
				return true;
			}
			object[] customAttributes = 0KN.GetCustomAttributes(typeof(DefaultValueAttribute), inherit: true);
			if (customAttributes.Length == 0)
			{
				return false;
			}
			DefaultValueAttribute defaultValueAttribute = (DefaultValueAttribute)customAttributes[0];
			return 0KO.Equals(defaultValueAttribute.Value);
		}
	}
	[DefaultMember("Item")]
	public abstract class RowColCollection : IEnumerable
	{
		internal ArrayList U6;

		internal int U7;

		internal int U8;

		internal bool U9;

		internal int UA;

		internal int UB;

		internal int UC;

		internal int UD;

		internal 0D UE;

		internal RowCol XF => (RowCol)U6[0KP];

		public virtual int Count
		{
			get
			{
				return U6.Count;
			}
			set
			{
				throw new NotImplementedException("Cannot set in base class.");
			}
		}

		[D("Fixed", "Gets or sets the number of fixed elements in the collection.")]
		[DefaultValue(1)]
		[E("Layout")]
		public virtual int Fixed
		{
			get
			{
				return U7;
			}
			set
			{
				if (U7 != value)
				{
					U7 = value;
					DM();
					DU(GridChangedTypeEnum.LayoutChanged);
				}
			}
		}

		[D("Frozen", "Gets or sets the number of frozen elements in the collection.")]
		[DefaultValue(0)]
		[E("Layout")]
		public virtual int Frozen
		{
			get
			{
				return U8;
			}
			set
			{
				if (U8 != value)
				{
					U8 = value;
					DM();
					DU(GridChangedTypeEnum.LayoutChanged);
				}
			}
		}

		[E("Layout")]
		[DefaultValue(0)]
		[D("MinSize", "Gets or sets the minimum size for elements in the collection.")]
		public int MinSize
		{
			get
			{
				return UB;
			}
			set
			{
				if (UB != value)
				{
					if (value < 0)
					{
						value = 0;
					}
					UB = value;
					DM();
					DU(GridChangedTypeEnum.GridChanged);
				}
			}
		}

		[DefaultValue(0)]
		[E("Layout")]
		[D("MaxSize", "Gets or sets the maximum size for elements in the collection.")]
		public int MaxSize
		{
			get
			{
				return UC;
			}
			set
			{
				if (UC != value)
				{
					if (value < 0)
					{
						value = 0;
					}
					UC = value;
					DM();
					DU(GridChangedTypeEnum.GridChanged);
				}
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[Browsable(false)]
		public int DefaultSize
		{
			get
			{
				return UA;
			}
			set
			{
				if (UA != value)
				{
					if (value < 0)
					{
						value = 0;
					}
					UA = value;
					DM();
					DU(GridChangedTypeEnum.GridChanged);
				}
			}
		}

		private IEnumerator DK()
		{
			return U6.GetEnumerator();
		}

		IEnumerator IEnumerable.GetEnumerator()
		{
			//ILSpy generated this explicit interface implementation from .override directive in DK
			return this.DK();
		}

		public virtual void Move(int indexOld, int indexNew)
		{
			if (indexNew != indexOld)
			{
				RowCol value = this.get_XF(indexOld);
				U6.RemoveAt(indexOld);
				U6.Insert(indexNew, value);
				DM();
			}
		}

		public virtual void MoveRange(int index, int count, int indexNew)
		{
			if (index != indexNew && count >= 1)
			{
				if (index + count > U6.Count)
				{
					throw new ArgumentException("Bad arguments in MoveRange command (index+count > list size)");
				}
				if (indexNew < 0 || indexNew > U6.Count - count)
				{
					throw new ArgumentException("Bad arguments in MoveRange command (indexNew is out of range)");
				}
				ArrayList arrayList = new ArrayList(count);
				for (int i = 0; i < count; i++)
				{
					arrayList.Add(U6[index + i]);
				}
				U6.RemoveRange(index, count);
				U6.InsertRange(indexNew, arrayList);
				DM();
			}
		}

		public bool Contains(RowCol item)
		{
			return U6.Contains(item);
		}

		internal int DL(int 0KQ)
		{
			int num = 0;
			int num2 = DN() + 1;
			if (0KQ < 0 || num2 == 0)
			{
				return -1;
			}
			RowCol rowCol = this.get_XF(num2 - 1);
			if (0KQ > rowCol.XE)
			{
				return -100;
			}
			if (0KQ >= rowCol.XD)
			{
				return num2 - 1;
			}
			while (num2 > num)
			{
				int num3 = (num + num2) / 2;
				rowCol = this.get_XF(num3);
				int xD = rowCol.XD;
				if (xD > 0KQ)
				{
					num2 = num3;
				}
				else
				{
					num = num3;
				}
				if (xD <= 0KQ && xD + rowCol.XC > 0KQ)
				{
					num = num3;
					break;
				}
			}
			while (this.get_XF(num).XC == 0 && num > 0)
			{
				num--;
			}
			return num;
		}

		protected internal virtual void Update()
		{
			if (!U9)
			{
				return;
			}
			int num = 0;
			RowCol rowCol = null;
			foreach (RowCol item in U6)
			{
				item.TT = num;
				if ((item.TV & 0R.TI) == 0R.TH)
				{
					num += item.XC;
					rowCol = item;
				}
			}
			UD = rowCol?.Index ?? (-1);
			U9 = false;
		}

		internal void DM()
		{
			if (U7 < 0)
			{
				U7 = 0;
			}
			if (U7 > U6.Count)
			{
				U7 = U6.Count;
			}
			if (U8 < 0)
			{
				U8 = 0;
			}
			if (U8 > U6.Count - U7)
			{
				U8 = U6.Count - U7;
			}
			U9 = true;
		}

		internal int DN()
		{
			if (U9)
			{
				Update();
			}
			return UD;
		}

		internal bool DO(int 0KR)
		{
			return 0KR < U7;
		}

		internal bool DP(int 0KS)
		{
			return 0KS < U7 + U8;
		}

		internal Style DQ()
		{
			return UE.PN.ER();
		}

		internal Style DR(CellStyleEnum 0KT)
		{
			return UE.PN[0KT].VA;
		}

		internal void DS(GridChangedTypeEnum 0KU, int 0KV, int 0KW, int 0KX, int 0KY)
		{
			if (UE != null)
			{
				UE.8D(0KU, 0KV, 0KW, 0KX, 0KY);
			}
		}

		internal void DT(GridChangedTypeEnum 0KZ, int 0L0, int 0L1)
		{
			DS(0KZ, 0L0, 0L1, 0L0, 0L1);
		}

		internal void DU(GridChangedTypeEnum 0L2)
		{
			DS(0L2, -1, -1, -1, -1);
		}
	}
	[TypeConverter(typeof(ExpandableObjectConverter))]
	public class RowCollection : RowColCollection
	{
		internal int UF;

		internal int UG;

		public Row this[int index] => (Row)U6[index];

		[E("Layout")]
		[D("Row.Count", "Gets or sets the number of rows in the grid.")]
		[DefaultValue(50)]
		public override int Count
		{
			get
			{
				return U6.Count;
			}
			set
			{
				if (U6.Count != value)
				{
					UE.9I();
					DV(value);
				}
			}
		}

		public override int Fixed
		{
			get
			{
				return U7;
			}
			set
			{
				if (UE.9H())
				{
					while (value > U7)
					{
						U7++;
						DX(U7 - 1, 0L7: false);
					}
					while (value < U7)
					{
						U7--;
						DZ(U7, 0LC: false);
					}
				}
				else
				{
					base.Fixed = value;
				}
			}
		}

		[D("Selected", "Gets the collection of selected rows.")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[Browsable(false)]
		public RowCollection Selected
		{
			get
			{
				ArrayList arrayList = new ArrayList();
				foreach (Row item in U6)
				{
					if (item.Selected)
					{
						arrayList.Add(item);
					}
				}
				RowCollection rowCollection = new RowCollection(UE, 0, 0, UA);
				rowCollection.U6 = arrayList;
				return rowCollection;
			}
		}

		internal int XG
		{
			get
			{
				if (U9)
				{
					Update();
				}
				return UF;
			}
		}

		internal RowCollection(0D grid, int nItems, int nFixed, int defaultSize)
		{
			UE = grid;
			U7 = nFixed;
			U8 = 0;
			UA = defaultSize;
			U6 = new ArrayList(nItems);
			for (int i = 0; i < nItems; i++)
			{
				U6.Add(new Row(this));
			}
			DM();
		}

		internal void DV(int 0L3)
		{
			DW(0L3, 0L5: true);
		}

		internal void DW(int 0L4, bool 0L5)
		{
			int count = U6.Count;
			if (0L4 > count)
			{
				if (U6.Capacity < 0L4)
				{
					U6.Capacity = 0L4;
				}
				for (int i = count; i < 0L4; i++)
				{
					U6.Add(new Row(this));
				}
				DM();
				if (0L5)
				{
					DU(GridChangedTypeEnum.RowAdded);
				}
			}
			else if (0L4 < count)
			{
				U6.RemoveRange(0L4, count - 0L4);
				DM();
				if (0L5)
				{
					DU(GridChangedTypeEnum.RowRemoved);
				}
			}
		}

		public Row Add()
		{
			return DX(U6.Count, 0L7: true);
		}

		public Row Insert(int index)
		{
			return DX(index, 0L7: true);
		}

		public Node InsertNode(int index, int level)
		{
			Row row = DY(index, 0L9: false, 0R.TP);
			row.U2 = (short)level;
			return row.Node;
		}

		internal Row DX(int 0L6, bool 0L7)
		{
			return DY(0L6, 0L7, 0R.TH);
		}

		internal Row DY(int 0L8, bool 0L9, 0R 0LA)
		{
			if (0L9 && UE.9H())
			{
				UE.PO.AD(0L8 - U7);
				if (0L8 >= U6.Count)
				{
					return null;
				}
				return this[0L8];
			}
			Row row = new Row(this);
			U6.Insert(0L8, row);
			DM();
			bool flag = false;
			for (Node node = row.Node; node != null; node = node.GetNode(NodeTypeEnum.Parent))
			{
				if (!node.Row.Visible || node.Collapsed)
				{
					row.TV |= 0R.TI;
					flag = true;
					break;
				}
			}
			if (0LA != 0R.TH)
			{
				row.TV |= 0LA;
				flag = true;
			}
			if (flag)
			{
				DM();
			}
			DT(GridChangedTypeEnum.RowAdded, 0L8, -1);
			return row;
		}

		public void InsertRange(int index, int count)
		{
			UE.9I();
			for (int i = 0; i < count; i++)
			{
				U6.Insert(index, new Row(this));
			}
			DM();
			DT(GridChangedTypeEnum.RowAdded, index, -1);
		}

		public Row Remove(int index)
		{
			return DZ(index, 0LC: true);
		}

		public Row Remove(Row row)
		{
			return Remove(row.Index);
		}

		internal Row DZ(int 0LB, bool 0LC)
		{
			Row row = this[0LB];
			if (row.IsNode)
			{
				row.Node.Collapsed = false;
			}
			if (0LC && UE.9H() && row.DataIndex > -1)
			{
				UE.PO.AC(row.DataIndex);
				return row;
			}
			U6.RemoveAt(0LB);
			DM();
			DT(GridChangedTypeEnum.RowRemoved, 0LB, -1);
			return row;
		}

		public void RemoveRange(int index, int count)
		{
			UE.9I();
			for (int i = 0; i < count; i++)
			{
				U6.RemoveAt(index);
			}
			DM();
			DT(GridChangedTypeEnum.RowRemoved, index, -1);
		}

		public override void Move(int indexOld, int indexNew)
		{
			E0(indexOld, indexNew, 0LF: true);
		}

		internal void E0(int 0LD, int 0LE, bool 0LF)
		{
			if (0LF && UE.9H())
			{
				int dataIndex = this[0LD].DataIndex;
				int dataIndex2 = this[0LE].DataIndex;
				if (dataIndex > -1 && dataIndex2 > -1)
				{
					UE.PO.AE(dataIndex, dataIndex2);
					DS(GridChangedTypeEnum.RowMoved, 0LD, -1, 0LE, -1);
					return;
				}
				if (dataIndex > -1 || dataIndex2 > -1)
				{
					throw new ArgumentException("Invalid position for data row.");
				}
			}
			base.Move(0LD, 0LE);
			DS(GridChangedTypeEnum.RowMoved, 0LD, -1, 0LE, -1);
		}

		public override void MoveRange(int index, int count, int indexNew)
		{
			UE.9I();
			base.MoveRange(index, count, indexNew);
			DS(GridChangedTypeEnum.RowMoved, index, -1, indexNew, -1);
		}

		protected internal override void Update()
		{
			if (!U9)
			{
				return;
			}
			UD = -1;
			UF = -1;
			UG = int.MaxValue;
			int num = 0;
			int num2 = 0;
			int num3 = -U7;
			Row row = null;
			foreach (Row item in U6)
			{
				int xC = item.XC;
				item.U3 = num2;
				item.TT = num;
				num += xC;
				if (xC > 0)
				{
					UD = num2;
				}
				num2++;
				if ((item.TV & 0R.TP) != 0R.TH)
				{
					item.TU = -1;
					if (UF < item.U2)
					{
						UF = item.U2;
					}
					if (UG > item.U2)
					{
						UG = item.U2;
					}
				}
				else if ((item.TV & 0R.TR) != 0R.TH)
				{
					if (row == null)
					{
						row = item;
					}
					item.TU = -1;
				}
				else
				{
					item.TU = ((num3 < 0) ? (-1) : num3);
					num3++;
				}
			}
			U9 = false;
			if (row != null && row.U3 < Count - 1)
			{
				U6.Remove(row);
				DM();
				Update();
			}
			UE.PT.9P();
		}
	}
	[Editor(typeof(GridColumnEditor), typeof(UITypeEditor))]
	[TypeConverter(typeof(ExpandableObjectConverter))]
	public class ColumnCollection : RowColCollection
	{
		internal string UH;

		public Column this[int index] => (Column)U6[index];

		public Column this[string columnName]
		{
			get
			{
				int num = E3(columnName);
				if (num <= -1)
				{
					return null;
				}
				return this[num];
			}
		}

		[E("Layout")]
		[D("Col.Count", "Gets or sets the number of columns in the grid.")]
		[DefaultValue(10)]
		public override int Count
		{
			get
			{
				return U6.Count;
			}
			set
			{
				E1(value);
			}
		}

		public override int Fixed
		{
			get
			{
				return U7;
			}
			set
			{
				if (UE.9H())
				{
					while (value > U7)
					{
						U7++;
						Insert(U7 - 1);
					}
					while (value < U7)
					{
						U7--;
						Remove(U7);
					}
				}
				else
				{
					base.Fixed = value;
				}
			}
		}

		[Browsable(false)]
		public ColumnCollection Selected
		{
			get
			{
				ArrayList arrayList = new ArrayList();
				foreach (Column item in U6)
				{
					if (item.Selected)
					{
						arrayList.Add(item);
					}
				}
				ColumnCollection columnCollection = new ColumnCollection(UE, 0, 0, UA);
				columnCollection.U6 = arrayList;
				return columnCollection;
			}
		}

		internal ColumnCollection(0D grid, int nItems, int nFixed, int defaultSize)
		{
			E5(nItems, nFixed, 0, 0, 0, defaultSize, "");
			UE = grid;
		}

		public bool Contains(string columnName)
		{
			return E3(columnName) > -1;
		}

		internal void E1(int 0LG)
		{
			E2(0LG, 0LI: true);
		}

		internal void E2(int 0LH, bool 0LI)
		{
			if (0LH < 0)
			{
				throw new ArgumentException("Number of Columns must be positive");
			}
			int num = U6.Count;
			if (0LH > num)
			{
				for (int i = num; i < 0LH; i++)
				{
					U6.Add(new Column(this, i));
				}
				DM();
				if (0LI)
				{
					DU(GridChangedTypeEnum.ColAdded);
				}
			}
			if (0LH < num)
			{
				while (0LH < num)
				{
					E4(num - 1);
					num--;
				}
				DM();
				if (0LI)
				{
					DU(GridChangedTypeEnum.ColRemoved);
				}
			}
		}

		public Column Add()
		{
			return Insert(Count);
		}

		public Column Insert(int index)
		{
			Column column = new Column(this, Count);
			U6.Insert(index, column);
			DM();
			DT(GridChangedTypeEnum.ColAdded, -1, index);
			return column;
		}

		public void InsertRange(int index, int count)
		{
			for (int i = 0; i < count; i++)
			{
				U6.Insert(index, new Column(this, Count));
			}
			DM();
			DT(GridChangedTypeEnum.ColAdded, index, -1);
		}

		public Column Remove(int index)
		{
			Column result = this[index];
			E4(index);
			DM();
			DT(GridChangedTypeEnum.ColRemoved, -1, index);
			return result;
		}

		public Column Remove(Column column)
		{
			return Remove(column.Index);
		}

		public void RemoveRange(int index, int count)
		{
			for (int i = 0; i < count; i++)
			{
				E4(index);
			}
			DM();
			DT(GridChangedTypeEnum.ColRemoved, index, -1);
		}

		public override void Move(int indexOld, int indexNew)
		{
			base.Move(indexOld, indexNew);
			DS(GridChangedTypeEnum.ColMoved, -1, indexOld, -1, indexNew);
		}

		public override void MoveRange(int index, int count, int indexNew)
		{
			base.MoveRange(index, count, indexNew);
			DS(GridChangedTypeEnum.ColMoved, -1, index, -1, indexNew);
		}

		internal int E3(string 0LJ)
		{
			int num = 0;
			foreach (Column item in U6)
			{
				if (string.Compare(0LJ, item.Name, ignoreCase: true, CultureInfo.CurrentCulture) == 0)
				{
					return num;
				}
				num++;
			}
			return -1;
		}

		internal void E4(int 0LK)
		{
			int tU = this[0LK].TU;
			if (UE != null)
			{
				foreach (Row item in (IEnumerable)UE.PJ)
				{
					ArrayList u = item.U0;
					if (u != null && u.Count > tU)
					{
						u.RemoveAt(tU);
					}
					u = item.U1;
					if (u != null && u.Count > tU)
					{
						u.RemoveAt(tU);
					}
				}
			}
			foreach (Column item2 in U6)
			{
				if (item2.TU > tU)
				{
					item2.TU--;
				}
			}
			U6.RemoveAt(0LK);
		}

		public ColumnCollection(int count, int fixedItems, int sizeMin, int sizeMax, int sizeDefault, string colDefs)
		{
			E5(count, fixedItems, 0, sizeMin, sizeMax, sizeDefault, colDefs);
		}

		public ColumnCollection(int count, int fixedItems, int frozenItems, int sizeMin, int sizeMax, int sizeDefault, string colDefs)
		{
			E5(count, fixedItems, frozenItems, sizeMin, sizeMax, sizeDefault, colDefs);
		}

		internal ColumnCollection(string colDefs)
		{
			string 0LR = "";
			int num = colDefs.IndexOf("Columns:");
			if (num > 0)
			{
				0LR = colDefs.Substring(num + 8);
			}
			try
			{
				string[] array = colDefs.Split(new char[1] { ',' });
				int 0LL = int.Parse(array[0], CultureInfo.InvariantCulture);
				int 0LM = int.Parse(array[1], CultureInfo.InvariantCulture);
				int 0LN = int.Parse(array[2], CultureInfo.InvariantCulture);
				int 0LO = int.Parse(array[3], CultureInfo.InvariantCulture);
				int 0LP = int.Parse(array[4], CultureInfo.InvariantCulture);
				int 0LQ = int.Parse(array[5], CultureInfo.InvariantCulture);
				E5(0LL, 0LM, 0LN, 0LO, 0LP, 0LQ, 0LR);
			}
			catch
			{
				E5(10, 0, 1, 0, 0, 0, "");
			}
		}

		internal void E5(int 0LL, int 0LM, int 0LN, int 0LO, int 0LP, int 0LQ, string 0LR)
		{
			UE = null;
			U7 = 0LM;
			U8 = 0LN;
			UB = 0LO;
			UC = 0LP;
			UA = 0LQ;
			UD = -1;
			U6 = new ArrayList(0LL);
			for (int i = 0; i < 0LL; i++)
			{
				U6.Add(new Column(this, i));
			}
			UH = 0LR;
			DM();
		}

		internal string E6()
		{
			return string.Format(CultureInfo.InvariantCulture, "{0},{1},{2},{3},{4},{5},Columns:{6}", Count, Fixed, Frozen, base.MinSize, base.MaxSize, base.DefaultSize, E7(0LS: false));
		}

		internal string E7(bool 0LS)
		{
			StringBuilder stringBuilder = new StringBuilder();
			for (int i = 0; i < Count; i++)
			{
				string text = this[i].DG(0LS);
				if (text != null && text.Length != 0)
				{
					stringBuilder.Append(i.ToString(CultureInfo.InvariantCulture) + "{" + text + "}\t");
				}
			}
			return stringBuilder.ToString();
		}

		internal bool E8(string 0LT)
		{
			while (true)
			{
				int num = 0LT.IndexOf('{');
				int num2 = 0LT.IndexOf('}');
				if (num < 0 || num2 < 0)
				{
					break;
				}
				int num3 = -1;
				try
				{
					num3 = int.Parse(0LT.Substring(0, num).Trim(), CultureInfo.InvariantCulture);
				}
				catch
				{
				}
				if (num3 >= 0 && num3 < Count)
				{
					string 0KL = 0LT.Substring(num + 1, num2 - num - 1).Trim();
					this[num3].DH(0KL);
				}
				0LT = 0LT.Substring(num2 + 1);
			}
			DM();
			return true;
		}
	}
	internal class 0S
	{
		internal Style UI;

		internal CheckEnum UJ;

		internal Image UK;

		internal object UL;
	}
	internal class 0T : IComparer
	{
		internal 0D UM;

		private int UN;

		private int UO;

		private SortFlags UP;

		private bool UQ;

		private bool UR;

		private bool US;

		private bool UT;

		private bool UU;

		internal 0T(0D grid, SortFlags order, int colFrom, int colTo)
		{
			UM = grid;
			UN = colFrom;
			UO = colTo;
			UP = order;
			UQ = false;
			UU = false;
		}

		internal void E9(SortFlags 0LU)
		{
			US = (0LU & SortFlags.IgnoreCase) != 0;
			UR = (0LU & SortFlags.AsDisplayed) != 0;
			UT = (0LU & SortFlags.Descending) != 0;
			UU = (0LU & (SortFlags.Ascending | SortFlags.Descending)) == 0;
		}

		public int Compare(object x, object y)
		{
			int num = 0;
			Row row = (Row)x;
			Row row2 = (Row)y;
			if (row.Equals(row2))
			{
				return 0;
			}
			E9(UP);
			for (int i = UN; i <= UO; i++)
			{
				if ((UP & SortFlags.UseColSort) != SortFlags.None)
				{
					E9(UM.PK[i].Sort);
				}
				if (UU)
				{
					continue;
				}
				if (UR || UQ)
				{
					string dataDisplay = UM.GetDataDisplay(row.Index, i);
					string dataDisplay2 = UM.GetDataDisplay(row2.Index, i);
					if (UQ && 06.5G(dataDisplay) && 06.5G(dataDisplay2))
					{
						double num2 = 06.5H(dataDisplay);
						double num3 = 06.5H(dataDisplay2);
						num = ((num2 > num3) ? 1 : ((num2 < num3) ? (-1) : 0));
					}
					else
					{
						num = string.Compare(dataDisplay, dataDisplay2, US, CultureInfo.CurrentCulture);
					}
				}
				else
				{
					object data = UM.GetData(row.Index, i);
					object data2 = UM.GetData(row2.Index, i);
					num = ((data is string && data2 is string) ? string.Compare((string)data, (string)data2, US, CultureInfo.CurrentCulture) : 06.5I(data, data2));
					if (num < -1)
					{
						UQ = true;
						return Compare(x, y);
					}
				}
				if (num != 0)
				{
					break;
				}
			}
			if (UT)
			{
				num = -num;
			}
			if (num == 0)
			{
				num = row.U3 - row2.U3;
			}
			return num;
		}
	}
	internal class 0U
	{
		internal static void EA(C1FlexGridBase 0LV, string 0LW, FileFormatEnum 0LX, bool 0LY, Encoding 0LZ)
		{
			bool redraw = 0LV.Redraw;
			char c = ',';
			c = 0LX switch
			{
				FileFormatEnum.TextComma => ',', 
				FileFormatEnum.TextTab => '\t', 
				FileFormatEnum.TextCustom => 0LV.ClipSeparators[0], 
				_ => throw new ArgumentException(string.Format(CultureInfo.CurrentCulture, "Invalid file format: {0}.", new object[1] { 0LX })), 
			};
			StreamReader streamReader = null;
			try
			{
				streamReader = new StreamReader(0LW, 0LZ, detectEncodingFromByteOrderMarks: true);
				if (0LV.DataSource != null)
				{
					0LV.DataSource = null;
					0LV.Cols.Count = 0LV.Cols.Fixed;
					0LV.Rows.Count = 0LV.Rows.Fixed;
				}
				0LV.Redraw = false;
				int num = ((!0LY) ? 0LV.Rows.Fixed : 0);
				string text = streamReader.ReadLine();
				while (text != null)
				{
					int num2 = ((!0LY) ? 0LV.Cols.Fixed : 0);
					text = text.Replace("\\r\\n", "\r\n");
					string text2 = "";
					int num3 = 0;
					bool flag = false;
					for (int i = 0; i < text.Length; i++)
					{
						if (text[i] == '"')
						{
							if (i == num3)
							{
								flag = true;
								continue;
							}
							if (i < text.Length - 1 && text[i + 1] == '"')
							{
								i++;
								continue;
							}
							if (flag)
							{
								flag = false;
								continue;
							}
						}
						if (!flag && text[i] == c)
						{
							text2 = text.Substring(num3, i - num3);
							EB(0LV, num, num2, text2);
							num3 = i + 1;
							num2++;
						}
					}
					text2 = text.Substring(num3, text.Length - num3);
					EB(0LV, num, num2, text2);
					text = streamReader.ReadLine();
					num++;
				}
			}
			finally
			{
				0LV.Redraw = redraw;
				streamReader?.Close();
			}
		}

		internal static void EB(C1FlexGridBase 0M0, int 0M1, int 0M2, string 0M3)
		{
			if (0M3 != null)
			{
				if (0M3.Length > 1 && 0M3[0] == '"' && 0M3[0M3.Length - 1] == '"')
				{
					0M3 = 0M3.Substring(1, 0M3.Length - 2);
				}
				if (0M3.IndexOf('"') > -1)
				{
					0M3 = 0M3.Replace("\"\"", "\"");
				}
			}
			if (0M2 >= 0M0.Cols.Count)
			{
				0M0.Cols.Count = 0M2 + 1;
			}
			if (0M1 >= 0M0.Rows.Count)
			{
				0M0.Rows.Count = 0M1 + 1;
			}
			0M0[0M1, 0M2] = 0M3;
		}

		internal static void EC(C1FlexGridBase 0M4, string 0M5, FileFormatEnum 0M6, bool 0M7, Encoding 0M8)
		{
			string value;
			string value2;
			switch (0M6)
			{
			case FileFormatEnum.TextComma:
				value = ",";
				value2 = "\r\n";
				break;
			case FileFormatEnum.TextTab:
				value = "\t";
				value2 = "\r\n";
				break;
			case FileFormatEnum.TextCustom:
				value = 0M4.ClipSeparators[0].ToString(CultureInfo.CurrentCulture);
				value2 = "\r\n";
				break;
			default:
				throw new ArgumentException(string.Format(CultureInfo.CurrentCulture, "Invalid file format: {0}.", new object[1] { 0M6 }));
			}
			StreamWriter streamWriter = null;
			try
			{
				streamWriter = new StreamWriter(0M5, append: false, 0M8);
				for (int i = ((!0M7) ? 0M4.Rows.Fixed : 0); i < 0M4.Rows.Count; i++)
				{
					for (int j = ((!0M7) ? 0M4.Cols.Fixed : 0); j < 0M4.Cols.Count; j++)
					{
						string text = 0M4.GetDataDisplay(i, j);
						if (text == null)
						{
							text = "";
						}
						text = text.Replace("\r\n", "\\r\\n");
						bool flag = text.IndexOf("\"") > -1;
						if (flag)
						{
							text = text.Replace("\"", "\"\"");
						}
						if (flag || text.IndexOf(value) > -1 || text.IndexOf(value2) > -1)
						{
							text = "\"" + text + "\"";
						}
						streamWriter.Write(text);
						if (j < 0M4.Cols.Count - 1)
						{
							streamWriter.Write(value);
						}
					}
					if (i < 0M4.Rows.Count - 1)
					{
						streamWriter.Write(value2);
					}
				}
			}
			finally
			{
				if (streamWriter != null)
				{
					streamWriter.Flush();
					streamWriter.Close();
				}
			}
		}
	}
	public enum SelectionModeEnum
	{
		Default,
		Cell,
		CellRange,
		Row,
		RowRange,
		Column,
		ColumnRange,
		ListBox
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	public enum MoveCursorEnum
	{
		None,
		CellPrev,
		CellNext,
		CellUp,
		CellDown,
		CellLeft,
		CellRight,
		PageUp,
		PageDown,
		PageLeft,
		PageRight,
		HomeUp,
		EndDown,
		HomeLeft,
		EndRight
	}
	internal class 0V
	{
		internal 0D UV;

		internal SelectionModeEnum UW;

		internal CellRange UX;

		internal RowCol UY;

		internal RowCol UZ;

		internal RowCol V0;

		internal RowCol V1;

		internal CellRange V2;

		internal CellRange V3;

		internal bool V4;

		internal SelectionModeEnum XH
		{
			get
			{
				return UW;
			}
			set
			{
				if (UW == value)
				{
					return;
				}
				if (UW == SelectionModeEnum.ListBox)
				{
					RowCollection pJ = UV.PJ;
					for (int i = 0; i < UV.PJ.Count; i++)
					{
						pJ[i].DD(0R.TJ, 0KH: false);
					}
				}
				UW = value;
				UV.8G(GridChangedTypeEnum.RepaintGrid);
			}
		}

		internal 0V(0D grid)
		{
			UV = grid;
			UW = SelectionModeEnum.Default;
			ref CellRange uX = ref UX;
			uX = new CellRange(UV, -2, -2);
		}

		internal void ED(C1FlexGridBase 0MA, CellRange 0MB, bool 0MC)
		{
			bool flag = 0MB.Equals(UX);
			if (flag && UW == SelectionModeEnum.ListBox && 0MB.IsValid && !UV.PJ[0MB.r1].Selected)
			{
				flag = false;
			}
			if (flag)
			{
				return;
			}
			if (EL(0MB))
			{
				throw new IndexOutOfRangeException("Invalid parameters for Select method.");
			}
			if (!0MA.FinishEditing())
			{
				return;
			}
			if (EL(0MB))
			{
				0MB = new CellRange(UV, -1, -1);
			}
			V2 = UX;
			V3 = 0MB;
			UV.8G(GridChangedTypeEnum.BeforeSelChange);
			if (V4)
			{
				return;
			}
			if (UW == SelectionModeEnum.ListBox)
			{
				int num = -1;
				int 0C2 = -1;
				RowCollection pJ = UV.PJ;
				for (int i = 0; i < pJ.Count; i++)
				{
					bool 0KJ = 0MB.ContainsRow(i);
					if (pJ[i].DE(0R.TJ, 0KJ))
					{
						if (num < 0)
						{
							num = i;
						}
						0C2 = i;
					}
				}
				UV.8D(GridChangedTypeEnum.RowSelected, num, -1, 0C2, -1);
			}
			if (0MB.Equals(UX))
			{
				if (0MC)
				{
					0MA.ShowCell(UX.r2, UX.c2);
				}
				return;
			}
			CellRange 0C3 = UX;
			CellRange 0C4 = 0MB;
			switch (UW)
			{
			case SelectionModeEnum.ListBox:
				0C3 = new CellRange(UV, UX.r1, UX.c1);
				0C4 = new CellRange(UV, 0MB.r1, 0MB.c1);
				break;
			case SelectionModeEnum.Row:
			case SelectionModeEnum.RowRange:
			{
				int col = 0MA.Cols.Fixed;
				int col2 = 0MA.Cols.Count - 1;
				0C3 = new CellRange(UV, UX.r1, col, UX.r2, col2);
				0C4 = new CellRange(UV, 0MB.r1, col, 0MB.r2, col2);
				break;
			}
			case SelectionModeEnum.Column:
			case SelectionModeEnum.ColumnRange:
			{
				int row = 0MA.Rows.Fixed;
				int row2 = 0MA.Rows.Count - 1;
				0C3 = new CellRange(UV, row, UX.c1, row2, UX.c2);
				0C4 = new CellRange(UV, row, 0MB.c1, row2, 0MB.c2);
				break;
			}
			default:
			{
				CellRange cellRange = UX.9W(0MB);
				if (cellRange.IsValid)
				{
					0C3 = (0C4 = cellRange);
				}
				break;
			}
			}
			EO(0MB);
			UV.8G(GridChangedTypeEnum.AfterSelChange);
			UV.8E(GridChangedTypeEnum.RepaintRange, 0C3);
			if (0MC)
			{
				UV.8G(GridChangedTypeEnum.Update);
				0MA.ShowCell(UX.r2, UX.c2);
			}
			UV.8E(GridChangedTypeEnum.RepaintRange, 0C4);
		}

		internal void EE(C1FlexGridBase 0MD, int 0ME, int 0MF, bool 0MG, RowCollection 0MH)
		{
			0D uV = UV;
			RowCollection pJ = uV.PJ;
			if (!0MD.FinishEditing())
			{
				return;
			}
			if (0MH == null)
			{
				V2 = (V3 = UX);
				V3.r1 = (V3.r2 = 0ME);
				UV.8G(GridChangedTypeEnum.BeforeSelChange);
				if (!V4)
				{
					uV.8E(GridChangedTypeEnum.RepaintRange, UX);
					UX.r1 = (UX.r2 = 0ME);
					if (0MF >= uV.PK.Fixed)
					{
						UX.c1 = (UX.c2 = 0MF);
					}
					pJ[0ME].DE(0R.TJ, 0MG);
					uV.8E(GridChangedTypeEnum.RowSelected, UX);
					UV.8F(GridChangedTypeEnum.AfterSelChange, 0ME, -1);
				}
				return;
			}
			int num = -1;
			int 0C2 = -1;
			V2 = (V3 = UX);
			V3.r2 = 0ME;
			UV.8G(GridChangedTypeEnum.BeforeSelChange);
			if (V4)
			{
				return;
			}
			for (int i = UX.TopRow; i <= UX.BottomRow; i++)
			{
				if (V3.ContainsRow(i))
				{
					continue;
				}
				bool 0KJ = 0MH.Contains(pJ[i]);
				if (pJ[i].DE(0R.TJ, 0KJ))
				{
					if (num < 0)
					{
						num = i;
					}
					0C2 = i;
				}
			}
			UX = V3;
			for (int i = UX.TopRow; i <= UX.BottomRow; i++)
			{
				if (pJ[i].DE(0R.TJ, 0MG))
				{
					if (num < 0)
					{
						num = i;
					}
					0C2 = i;
				}
			}
			UV.8D(GridChangedTypeEnum.RowSelected, num, -1, 0C2, -1);
			UV.8D(GridChangedTypeEnum.AfterSelChange, num, -1, 0C2, -1);
			0MD.ShowCell(0ME, 0MF);
		}

		internal bool EF(int 0MI, int 0MJ)
		{
			bool flag = UV.8I(0MI, 0MJ);
			switch (UW)
			{
			case SelectionModeEnum.Cell:
				if (0MI == UX.r1 && 0MJ == UX.c1)
				{
					return true;
				}
				break;
			case SelectionModeEnum.CellRange:
				if (UX.Contains(0MI, 0MJ))
				{
					return true;
				}
				break;
			case SelectionModeEnum.Default:
				if (UX.Contains(0MI, 0MJ))
				{
					return true;
				}
				break;
			case SelectionModeEnum.Row:
				if (0MI == UX.r1 && !flag)
				{
					return true;
				}
				break;
			case SelectionModeEnum.RowRange:
				if (UX.ContainsRow(0MI) && !flag)
				{
					return true;
				}
				break;
			case SelectionModeEnum.Column:
				if (0MJ == UX.c1 && !flag)
				{
					return true;
				}
				break;
			case SelectionModeEnum.ColumnRange:
				if (UX.ContainsCol(0MJ) && !flag)
				{
					return true;
				}
				break;
			}
			0D uV = UV;
			if (!uV.8I(0MI, 0MJ))
			{
				if (!uV.PJ[0MI].Selected)
				{
					return uV.PK[0MJ].Selected;
				}
				return true;
			}
			return false;
		}

		internal bool EG()
		{
			switch (UW)
			{
			case SelectionModeEnum.Cell:
			case SelectionModeEnum.Row:
			case SelectionModeEnum.Column:
				return false;
			default:
				return true;
			}
		}

		internal bool EH(int 0MK, int 0ML)
		{
			if (0MK == UX.r1)
			{
				return 0ML == UX.c1;
			}
			return false;
		}

		internal bool EI()
		{
			return !UV.87(UX.r1, UX.c1);
		}

		internal CellRange EJ()
		{
			return UX;
		}

		internal Point EK()
		{
			return new Point(UX.c1, UX.r1);
		}

		internal bool EL(CellRange 0MM)
		{
			if (0MM.r1 < -2 || 0MM.c1 < -2 || 0MM.r2 < -2 || 0MM.c2 < -2)
			{
				return true;
			}
			0D uV = UV;
			int num = uV.PJ.Count - 1;
			if (0MM.r1 > num || 0MM.r2 > num)
			{
				return true;
			}
			num = uV.PK.Count - 1;
			if (0MM.c1 > num || 0MM.c2 > num)
			{
				return true;
			}
			return false;
		}

		internal void EM()
		{
			V3 = (V2 = UX);
			0D uV = UV;
			EN(uV.PJ, ref V3.r1, ref UY);
			EN(uV.PJ, ref V3.r2, ref UZ);
			EN(uV.PK, ref V3.c1, ref V0);
			EN(uV.PK, ref V3.c2, ref V1);
			if (!V3.Equals(V2))
			{
				UV.8G(GridChangedTypeEnum.BeforeSelChange);
				UX = V3;
				UV.8G(GridChangedTypeEnum.AfterSelChange);
			}
		}

		internal void EN(RowColCollection 0MN, ref int 0MO, ref RowCol 0MP)
		{
			if (0MO == -1)
			{
				0MP = null;
			}
			else if (0MO < 0MN.Fixed && 0MN.Count > 0MN.Fixed)
			{
				0MO = 0MN.Fixed;
				0MP = 0MN.get_XF(0MO);
			}
			else
			{
				if (0MO >= 0 && 0MO < 0MN.Count && 0MN.get_XF(0MO) == 0MP)
				{
					return;
				}
				if (0MP != null)
				{
					int num = 0MN.U6.IndexOf(0MP);
					if (num > -1)
					{
						0MO = num;
						return;
					}
				}
				if (0MO >= 0MN.Count)
				{
					0MO = 0MN.Count - 1;
					if (0MO < 0MN.Fixed)
					{
						0MO = -2;
					}
				}
				0MP = ((0MO > -1) ? 0MN.get_XF(0MO) : null);
			}
		}

		internal void EO(CellRange 0MQ)
		{
			0D uV = UV;
			UX = 0MQ;
			UY = (uV.85(0MQ.r1) ? null : uV.PJ[0MQ.r1]);
			UZ = (uV.85(0MQ.r2) ? null : uV.PJ[0MQ.r2]);
			V0 = (uV.86(0MQ.c1) ? null : uV.PK[0MQ.c1]);
			V1 = (uV.86(0MQ.c2) ? null : uV.PK[0MQ.c2]);
		}
	}
	public enum CellStyleEnum
	{
		Normal,
		Alternate,
		Fixed,
		Highlight,
		Focus,
		Search,
		Frozen,
		NewRow,
		EmptyArea,
		GrandTotal,
		Subtotal0,
		Subtotal1,
		Subtotal2,
		Subtotal3,
		Subtotal4,
		Subtotal5,
		FirstCustomStyle
	}
	public enum TextAlignEnum
	{
		LeftTop,
		LeftCenter,
		LeftBottom,
		CenterTop,
		CenterCenter,
		CenterBottom,
		RightTop,
		RightCenter,
		RightBottom,
		GeneralTop,
		GeneralCenter,
		GeneralBottom
	}
	public enum TextEffectEnum
	{
		Flat,
		Raised,
		Inset
	}
	public enum ImageAlignEnum
	{
		LeftTop,
		LeftCenter,
		LeftBottom,
		CenterTop,
		CenterCenter,
		CenterBottom,
		RightTop,
		RightCenter,
		RightBottom,
		Scale,
		Stretch,
		Tile,
		Hide
	}
	public enum DisplayEnum
	{
		TextOnly,
		ImageOnly,
		Overlay,
		Stack,
		None
	}
	public enum BorderStyleEnum
	{
		None,
		Flat,
		Double,
		Raised,
		Inset,
		Groove,
		Fillet,
		Dotted
	}
	public enum BorderDirEnum
	{
		Both,
		Horizontal,
		Vertical
	}
	[Flags]
	public enum StyleElementFlags
	{
		None = 0,
		Font = 1,
		BackColor = 2,
		ForeColor = 4,
		Margins = 8,
		Border = 0x10,
		TextAlign = 0x20,
		TextEffect = 0x40,
		ImageAlign = 0x80,
		ImageSpacing = 0x100,
		Trimming = 0x200,
		WordWrap = 0x400,
		Display = 0x800,
		Format = 0xFF6,
		EditMask = 0x2000,
		ComboList = 0x4000,
		ImageMap = 0x8000,
		DataType = 0x10000,
		DataMap = 0x20000,
		All = 0xFFFF
	}
	[TypeConverter(typeof(GridStyleConverter))]
	[Editor(typeof(GridStyleEditor), typeof(UITypeEditor))]
	public class CellStyleCollection : ICollection, IEnumerable
	{
		internal 0D V5;

		internal 05 V6;

		internal ArrayList V7;

		public CellStyle Normal => this[CellStyleEnum.Normal];

		public CellStyle Alternate => this[CellStyleEnum.Alternate];

		public CellStyle Fixed => this[CellStyleEnum.Fixed];

		public CellStyle Highlight => this[CellStyleEnum.Highlight];

		public CellStyle Focus => this[CellStyleEnum.Focus];

		public CellStyle Search => this[CellStyleEnum.Search];

		public CellStyle Frozen => this[CellStyleEnum.Frozen];

		public CellStyle NewRow => this[CellStyleEnum.NewRow];

		public CellStyle EmptyArea => this[CellStyleEnum.EmptyArea];

		public CellStyle this[int index] => new CellStyle((Style)V7[index]);

		public CellStyle this[CellStyleEnum index] => this[(int)index];

		public CellStyle this[string name]
		{
			get
			{
				int num = EQ(name);
				if (num < 0)
				{
					return null;
				}
				return new CellStyle(V6.3W(name));
			}
		}

		[Browsable(false)]
		public int Count => V7.Count;

		internal CellStyleCollection(0D grid)
		{
			ES();
			EU(grid);
		}

		public CellStyleCollection(string str)
		{
			ES();
			ParseString(str);
		}

		[SpecialName]
		bool ICollection.get_IsSynchronized()
		{
			return V7.IsSynchronized;
		}

		[SpecialName]
		object ICollection.get_SyncRoot()
		{
			return V7.SyncRoot;
		}

		private void EP(Array 0MR, int 0MS)
		{
			V7.CopyTo(0MR, 0MS);
		}

		void ICollection.CopyTo(Array 0MR, int 0MS)
		{
			//ILSpy generated this explicit interface implementation from .override directive in EP
			this.EP(0MR, 0MS);
		}

		public void CopyTo(CellStyle[] array, int index)
		{
			V7.CopyTo(array, index);
		}

		private IEnumerator DK()
		{
			return new 0W(V7);
		}

		IEnumerator IEnumerable.GetEnumerator()
		{
			//ILSpy generated this explicit interface implementation from .override directive in DK
			return this.DK();
		}

		public CellStyle Add(string name, CellStyle basedOn)
		{
			//IL_008b: Unknown result type (might be due to invalid IL or missing references)
			int num = EQ(name);
			if (num >= 0)
			{
				return this[num];
			}
			if (!EV(name))
			{
				throw new ArgumentException("Invalid syle name.");
			}
			Style style = V6.3M(name, Normal.VA);
			V7.Add(style);
			if (basedOn != null)
			{
				foreach (object key in basedOn.VA.KO.Keys)
				{
					object obj = basedOn.VA.KO[key];
					if (obj is Margins)
					{
						obj = ((Margins)obj).Clone();
					}
					style.KO.Add(key, obj);
				}
			}
			return new CellStyle(style);
		}

		public CellStyle Add(string name)
		{
			return Add(name, null);
		}

		public void Remove(int index)
		{
			int num = 16;
			if (index < num)
			{
				throw new IndexOutOfRangeException("Can't remove built-in styles.");
			}
			Style style = (Style)V7[index];
			for (int i = 0; i < V5.PJ.Count; i++)
			{
				if (V5.PJ[i].TX == style)
				{
					V5.PJ[i].TX = null;
				}
			}
			for (int j = 0; j < V5.PK.Count; j++)
			{
				if (V5.PK[j].TX == style)
				{
					V5.PK[j].TX = null;
				}
			}
			for (int i = 0; i < V5.PJ.Count; i++)
			{
				for (int j = 0; j < V5.PK.Count; j++)
				{
					if (V5.8P(i, j) == style)
					{
						V5.8Q(i, j, null);
					}
				}
			}
			V6.3R((Style)V7[index]);
			V7.RemoveAt(index);
		}

		public void Remove(string name)
		{
			int num = EQ(name);
			if (num < 0)
			{
				throw new IndexOutOfRangeException("Style not found in Collection.");
			}
			Remove(num);
		}

		public void Remove(CellStyle style)
		{
			int num = IndexOf(style);
			if (num < 0)
			{
				throw new IndexOutOfRangeException("Style not found in Collection.");
			}
			Remove(num);
		}

		public void Clear()
		{
			int num = 16;
			while (Count > num)
			{
				Remove(num);
			}
			bool flag = false;
			while (!flag)
			{
				flag = true;
				foreach (Style item in V6.3Y())
				{
					if (!Contains(item.4L()))
					{
						V6.KF.Remove(item.4L());
						flag = false;
						break;
					}
				}
			}
			ET();
			V5.8G(GridChangedTypeEnum.RepaintGrid);
		}

		public void ClearUnused()
		{
			Hashtable hashtable = new Hashtable();
			foreach (Row item in (IEnumerable)V5.PJ)
			{
				if (item.Style != null)
				{
					hashtable.Add(item.Style.VA, 1);
				}
				if (item.StyleFixed != null)
				{
					hashtable.Add(item.StyleFixed.VA, 1);
				}
			}
			foreach (Column item2 in (IEnumerable)V5.PK)
			{
				if (item2.Style != null)
				{
					hashtable.Add(item2.Style.VA, 1);
				}
				if (item2.StyleFixed != null)
				{
					hashtable.Add(item2.StyleFixed.VA, 1);
				}
			}
			for (int i = 0; i < V5.PJ.Count; i++)
			{
				for (int j = 0; j < V5.PK.Count; j++)
				{
					if (V5.8P(i, j) != null)
					{
						hashtable.Add(V5.8P(i, j), 1);
					}
				}
			}
			bool flag = false;
			while (!flag)
			{
				flag = true;
				foreach (Style item3 in V6.3Y())
				{
					if (!hashtable.Contains(item3) && !Contains(item3.4L()))
					{
						V6.KF.Remove(item3.4L());
						flag = false;
						break;
					}
				}
			}
			V5.8G(GridChangedTypeEnum.RepaintGrid);
		}

		public bool Contains(string name)
		{
			return EQ(name) >= 0;
		}

		public int IndexOf(CellStyle style)
		{
			return V7.IndexOf(style.VA);
		}

		public string BuildString(bool includeEmpty)
		{
			StringBuilder stringBuilder = new StringBuilder();
			for (int i = 0; i < Count; i++)
			{
				string name = this[i].Name;
				if (name != null && name.Length != 0)
				{
					string text = this[i].BuildString();
					if (includeEmpty || text.Length != 0)
					{
						stringBuilder.Append(name + "{" + text + "}\t");
					}
				}
			}
			return stringBuilder.ToString();
		}

		public bool ParseString(string str)
		{
			while (true)
			{
				int num = str.IndexOf('{');
				int num2 = str.IndexOf('}');
				if (num < 0 || num2 < 0)
				{
					break;
				}
				string text = str.Substring(0, num).Trim();
				string str2 = str.Substring(num + 1, num2 - num - 1).Trim();
				CellStyle cellStyle = (V7.Contains(text) ? this[text] : Add(text));
				cellStyle.Clear();
				cellStyle.ParseString(str2);
				str = str.Substring(num2 + 1);
			}
			return true;
		}

		internal int EQ(string 0MT)
		{
			for (int i = 0; i < V7.Count; i++)
			{
				Style style = (Style)V7[i];
				if (string.Compare(0MT, style.4L(), ignoreCase: true, CultureInfo.CurrentCulture) == 0)
				{
					return i;
				}
			}
			return -1;
		}

		internal Style ER()
		{
			return V6.3M(null, Normal.VA);
		}

		internal void ES()
		{
			//IL_008f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0099: Expected O, but got Unknown
			//IL_00a3: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ad: Expected O, but got Unknown
			V6 = new 05();
			V7 = new ArrayList();
			Style style = V6.3V();
			style.4T("BackColor", SystemBrushes.Window);
			style.4T("ForeColor", SystemBrushes.WindowText);
			style.4T("Opaque", true);
			style.4T("Font", Control.DefaultFont);
			style.4T("Trimming", (object)(StringTrimming)0);
			style.4T("Wrap", false);
			style.4T("Margins", (object)new Margins(0, 0, 0, 0));
			style.4T("Padding", (object)new Margins(1, 1, 1, 1));
			style.4T("AlignHorz", V.JP);
			style.4T("AlignVert", W.JV);
			style.4T("AlignImage", U.JD);
			style.4T("Spacing", 2);
			style.4T("Border", new H(SystemBrushes.Control, 0, 1, 0, 1));
			style.4T("Display", 00.K3);
			style.4T("DataType", null);
			style.4T("Format", string.Empty);
			style.4T("FormatStr", string.Empty);
			style.4T("EditMask", string.Empty);
			style.4T("ComboList", string.Empty);
			style.4T("ImageMap", null);
			style.4T("DataMap", null);
			Style style2 = V6.3O("Normal");
			V7.Add(style2);
			style = V6.3M("Alternate", style2);
			V7.Add(style);
			style = V6.3M("Fixed", style2);
			V7.Add(style);
			style = V6.3M("Highlight", style2);
			V7.Add(style);
			style = V6.3M("Focus", style2);
			V7.Add(style);
			style = V6.3M("Search", style2);
			V7.Add(style);
			style = V6.3M("Frozen", style2);
			V7.Add(style);
			style = V6.3M("NewRow", style2);
			V7.Add(style);
			style = V6.3M("EmptyArea", style2);
			V7.Add(style);
			style = V6.3M("GrandTotal", style2);
			V7.Add(style);
			for (int i = 0; i <= 5; i++)
			{
				style = V6.3M(string.Format(CultureInfo.InvariantCulture, "Subtotal{0}", new object[1] { i }), style2);
				V7.Add(style);
			}
			ET();
		}

		internal void ET()
		{
			ParseString("Normal{} Alternate{} Fixed{BackColor:Control;ForeColor:ControlText;Border:Flat,1,ControlDark,Both;} Highlight{BackColor:Highlight;ForeColor:HighlightText;} Focus{} Search{BackColor:Highlight;ForeColor:HighlightText;} Frozen{BackColor:Beige;} NewRow{} EmptyArea{BackColor:AppWorkspace;Border:Flat,1,ControlDarkDark,Both;} GrandTotal{BackColor:Black;ForeColor:White;} Subtotal0{BackColor:ControlDarkDark;ForeColor:White;} Subtotal1{BackColor:ControlDarkDark;ForeColor:White;} Subtotal2{BackColor:ControlDarkDark;ForeColor:White;} Subtotal3{BackColor:ControlDarkDark;ForeColor:White;} Subtotal4{BackColor:ControlDarkDark;ForeColor:White;} Subtotal5{BackColor:ControlDarkDark;ForeColor:White;}");
		}

		internal void EU(0D 0MU)
		{
			if (V5 != null && V6 != null)
			{
				V6.XK -= V5.84;
			}
			V5 = 0MU;
			if (V5 != null && V6 != null)
			{
				V6.XK += V5.84;
				V5.8G(GridChangedTypeEnum.RepaintGrid);
			}
		}

		internal static bool EV(string 0MV)
		{
			char[] anyOf = new char[2] { '{', '}' };
			if (0MV.Length > 0)
			{
				return 0MV.IndexOfAny(anyOf) < 0;
			}
			return false;
		}
	}
	internal class 0W : IEnumerator
	{
		private ArrayList V8;

		private int V9;

		internal 0W(ArrayList styles)
		{
			V8 = styles;
			V9 = -1;
		}

		[SpecialName]
		object IEnumerator.get_Current()
		{
			return new CellStyle((Style)V8[V9]);
		}

		private bool EW()
		{
			V9++;
			return V9 < V8.Count;
		}

		bool IEnumerator.MoveNext()
		{
			//ILSpy generated this explicit interface implementation from .override directive in EW
			return this.EW();
		}

		private void EX()
		{
			V9 = -1;
		}

		void IEnumerator.Reset()
		{
			//ILSpy generated this explicit interface implementation from .override directive in EX
			this.EX();
		}
	}
	[TypeConverter(typeof(ExpandableObjectConverter))]
	[RefreshProperties(RefreshProperties.Repaint)]
	public class CellStyle
	{
		private struct 0X
		{
			internal TextAlignEnum VC;

			internal V VD;

			internal W VE;

			internal 0X(TextAlignEnum ta, V ah, W av)
			{
				VC = ta;
				VD = ah;
				VE = av;
			}
		}

		internal Style VA;

		private static 0X[] VB = new 0X[12]
		{
			new 0X(TextAlignEnum.LeftTop, V.JQ, W.JU),
			new 0X(TextAlignEnum.LeftCenter, V.JQ, W.JV),
			new 0X(TextAlignEnum.LeftBottom, V.JQ, W.JW),
			new 0X(TextAlignEnum.CenterTop, V.JR, W.JU),
			new 0X(TextAlignEnum.CenterCenter, V.JR, W.JV),
			new 0X(TextAlignEnum.CenterBottom, V.JR, W.JW),
			new 0X(TextAlignEnum.RightTop, V.JS, W.JU),
			new 0X(TextAlignEnum.RightCenter, V.JS, W.JV),
			new 0X(TextAlignEnum.RightBottom, V.JS, W.JW),
			new 0X(TextAlignEnum.GeneralTop, V.JP, W.JU),
			new 0X(TextAlignEnum.GeneralCenter, V.JP, W.JV),
			new 0X(TextAlignEnum.GeneralBottom, V.JP, W.JW)
		};

		[Browsable(false)]
		[D("Name", "Style name.")]
		[RefreshProperties(RefreshProperties.Repaint)]
		public string Name
		{
			get
			{
				string text = VA.4L();
				if (text.StartsWith("{"))
				{
					return null;
				}
				return text;
			}
			set
			{
				if (!CellStyleCollection.EV(value) || !VA.4M(value))
				{
					throw new ArgumentException("Invalid or duplicate style name.");
				}
			}
		}

		[D("BackColor", "Cell background color.")]
		[Browsable(true)]
		[RefreshProperties(RefreshProperties.Repaint)]
		public Color BackColor
		{
			get
			{
				return F0("BackColor");
			}
			set
			{
				F1("BackColor", value);
			}
		}

		[D("ForeColor", "Cell foreground color.")]
		[Browsable(true)]
		[RefreshProperties(RefreshProperties.Repaint)]
		public Color ForeColor
		{
			get
			{
				return F0("ForeColor");
			}
			set
			{
				F1("ForeColor", value);
			}
		}

		[D("Font", "Cell font.")]
		[Browsable(true)]
		[RefreshProperties(RefreshProperties.Repaint)]
		public Font Font
		{
			get
			{
				//IL_0010: Unknown result type (might be due to invalid IL or missing references)
				//IL_0016: Expected O, but got Unknown
				return (Font)VA.4V("Font");
			}
			set
			{
				VA.4U("Font", value);
			}
		}

		[D("Margins", "Gets or sets the spacing between cell content and its edges, in pixels.")]
		[RefreshProperties(RefreshProperties.Repaint)]
		[Browsable(true)]
		public Margins Margins
		{
			get
			{
				//IL_0010: Unknown result type (might be due to invalid IL or missing references)
				//IL_0016: Expected O, but got Unknown
				return (Margins)VA.4V("Padding");
			}
			set
			{
				VA.4T("Padding", value);
			}
		}

		[RefreshProperties(RefreshProperties.Repaint)]
		[D("WordWrap", "Allow word wrapping within the cell.")]
		[DefaultValue(false)]
		[Browsable(true)]
		public bool WordWrap
		{
			get
			{
				return (bool)VA.4V("Wrap");
			}
			set
			{
				VA.4U("Wrap", value);
			}
		}

		[DefaultValue(/*Could not decode attribute arguments.*/)]
		[D("Trimming", "Controls how long strings are trimmed to fit the cell.")]
		[RefreshProperties(RefreshProperties.Repaint)]
		[Browsable(true)]
		public StringTrimming Trimming
		{
			get
			{
				return (StringTrimming)VA.4V("Trimming");
			}
			set
			{
				//IL_000b: Unknown result type (might be due to invalid IL or missing references)
				VA.4U("Trimming", value);
			}
		}

		[D("TextAlign", "Gets or sets the text alignment in the cell.")]
		[RefreshProperties(RefreshProperties.Repaint)]
		[DefaultValue(TextAlignEnum.GeneralCenter)]
		[Browsable(true)]
		public TextAlignEnum TextAlign
		{
			get
			{
				V v = (V)VA.4V("AlignHorz");
				W w = (W)VA.4V("AlignVert");
				for (int i = 0; i < VB.Length; i++)
				{
					if (VB[i].VD == v && VB[i].VE == w)
					{
						return VB[i].VC;
					}
				}
				return TextAlignEnum.GeneralCenter;
			}
			set
			{
				for (int i = 0; i < VB.Length; i++)
				{
					if (VB[i].VC == value)
					{
						VA.4U("AlignHorz", VB[i].VD);
						VA.4U("AlignVert", VB[i].VE);
						break;
					}
				}
			}
		}

		[DefaultValue(TextEffectEnum.Flat)]
		[RefreshProperties(RefreshProperties.Repaint)]
		[D("TextEffect", "Applies 3D effects to text.")]
		[Browsable(true)]
		public TextEffectEnum TextEffect
		{
			get
			{
				return (TextEffectEnum)VA.4V("TextEffect");
			}
			set
			{
				VA.4U("TextEffect", (Z)value);
			}
		}

		[RefreshProperties(RefreshProperties.Repaint)]
		[D("ImageAlign", "Gets or sets the image alignment in the cell.")]
		[DefaultValue(ImageAlignEnum.LeftCenter)]
		[Browsable(true)]
		public ImageAlignEnum ImageAlign
		{
			get
			{
				return (ImageAlignEnum)VA.4V("AlignImage");
			}
			set
			{
				VA.4U("AlignImage", (U)value);
			}
		}

		[RefreshProperties(RefreshProperties.Repaint)]
		[D("ImageSpacing", "Space between images and text in a cell, in pixels.")]
		[DefaultValue(2)]
		[Browsable(true)]
		public int ImageSpacing
		{
			get
			{
				return (int)VA.4V("Spacing");
			}
			set
			{
				VA.4U("Spacing", value);
			}
		}

		[D("Display", "Whether to show images, text, or both.")]
		[DefaultValue(DisplayEnum.Stack)]
		[Browsable(true)]
		public DisplayEnum Display
		{
			get
			{
				return (DisplayEnum)VA.4V("Display");
			}
			set
			{
				VA.4U("Display", (00)value);
			}
		}

		[D("Format", "Format string used to display values.")]
		[Browsable(true)]
		[DefaultValue("")]
		public string Format
		{
			get
			{
				return (string)VA.4V("Format");
			}
			set
			{
				if (value == null)
				{
					value = string.Empty;
				}
				VA.4U("Format", value);
				VA.4X("FormatStr");
				if (value.Length > 0)
				{
					string 04I = ((value.StartsWith("{") && value.EndsWith("}") && value.IndexOf(':') > -1) ? value : ("{0:" + value + "}"));
					VA.4U("FormatStr", 04I);
				}
			}
		}

		[DefaultValue("")]
		[D("EditMask", "Mask string used to edit values.")]
		[Browsable(true)]
		public string EditMask
		{
			get
			{
				return (string)VA.4V("EditMask");
			}
			set
			{
				VA.4U("EditMask", (value != null) ? value : string.Empty);
			}
		}

		[D("ComboList", "Pipe-delimited list of valid values.")]
		[Browsable(true)]
		public string ComboList
		{
			get
			{
				return (string)VA.4V("ComboList");
			}
			set
			{
				VA.4U("ComboList", (value != null) ? value : string.Empty);
			}
		}

		[Browsable(false)]
		[D("ImageMap", "Dictionary of values used to translate values into images.")]
		public System.Collections.IDictionary ImageMap
		{
			get
			{
				return VA.4V("ImageMap") as System.Collections.IDictionary;
			}
			set
			{
				VA.4U("ImageMap", value);
			}
		}

		[D("ImageMap", "Dictionary of values used to translate values into strings.")]
		[Browsable(false)]
		public System.Collections.IDictionary DataMap
		{
			get
			{
				return VA.4V("DataMap") as System.Collections.IDictionary;
			}
			set
			{
				VA.4U("DataMap", value);
			}
		}

		[Browsable(false)]
		[D("DataType", "Type of data contained in a grid element.")]
		public Type DataType
		{
			get
			{
				Type type = (Type)VA.4V("DataType");
				if ((object)type != typeof(object))
				{
					return type;
				}
				return null;
			}
			set
			{
				if ((object)value == null)
				{
					value = typeof(object);
				}
				VA.4U("DataType", value);
			}
		}

		[D("Border", "Border drawn around the cell.")]
		[Browsable(true)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[RefreshProperties(RefreshProperties.Repaint)]
		public CellBorder Border => new CellBorder(VA);

		[Browsable(false)]
		[D("DefinedElements", "Returns flags that indicate which elements are defined by this style.")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public StyleElementFlags DefinedElements
		{
			get
			{
				StyleElementFlags styleElementFlags = StyleElementFlags.None;
				if (VA.4W("Font"))
				{
					styleElementFlags |= StyleElementFlags.Font;
				}
				if (VA.4W("BackColor"))
				{
					styleElementFlags |= StyleElementFlags.BackColor;
				}
				if (VA.4W("ForeColor"))
				{
					styleElementFlags |= StyleElementFlags.ForeColor;
				}
				if (VA.4W("Padding"))
				{
					styleElementFlags |= StyleElementFlags.Margins;
				}
				if (VA.4W("Border"))
				{
					styleElementFlags |= StyleElementFlags.Border;
				}
				if (VA.4W("AlignHorz"))
				{
					styleElementFlags |= StyleElementFlags.TextAlign;
				}
				if (VA.4W("AlignVert"))
				{
					styleElementFlags |= StyleElementFlags.TextAlign;
				}
				if (VA.4W("TextEffect"))
				{
					styleElementFlags |= StyleElementFlags.TextEffect;
				}
				if (VA.4W("AlignImage"))
				{
					styleElementFlags |= StyleElementFlags.ImageAlign;
				}
				if (VA.4W("Spacing"))
				{
					styleElementFlags |= StyleElementFlags.ImageSpacing;
				}
				if (VA.4W("Trimming"))
				{
					styleElementFlags |= StyleElementFlags.Trimming;
				}
				if (VA.4W("Wrap"))
				{
					styleElementFlags |= StyleElementFlags.WordWrap;
				}
				if (VA.4W("Display"))
				{
					styleElementFlags |= StyleElementFlags.Display;
				}
				if (VA.4W("Format"))
				{
					styleElementFlags |= StyleElementFlags.Format;
				}
				if (VA.4W("EditMask"))
				{
					styleElementFlags |= StyleElementFlags.EditMask;
				}
				if (VA.4W("ComboList"))
				{
					styleElementFlags |= StyleElementFlags.ComboList;
				}
				if (VA.4W("ImageMap"))
				{
					styleElementFlags |= StyleElementFlags.ImageMap;
				}
				if (VA.4W("DataType"))
				{
					styleElementFlags |= StyleElementFlags.DataType;
				}
				if (VA.4W("DataMap"))
				{
					styleElementFlags |= StyleElementFlags.DataMap;
				}
				return styleElementFlags;
			}
			set
			{
				Clear(~value);
			}
		}

		internal Brush XI
		{
			get
			{
				object obj = VA.4V("BackColor");
				return (Brush)((obj is Brush) ? obj : null);
			}
		}

		internal Brush XJ
		{
			get
			{
				H h = (H)VA.4V("Border");
				return h.I2;
			}
		}

		internal CellStyle(Style style)
		{
			VA = style;
		}

		[D("Style.Clear", "Clears selected elements from this style.")]
		public void Clear(StyleElementFlags flags)
		{
			if ((flags & StyleElementFlags.Font) != StyleElementFlags.None)
			{
				VA.4X("Font");
			}
			if ((flags & StyleElementFlags.BackColor) != StyleElementFlags.None)
			{
				VA.4X("BackColor");
			}
			if ((flags & StyleElementFlags.ForeColor) != StyleElementFlags.None)
			{
				VA.4X("ForeColor");
			}
			if ((flags & StyleElementFlags.Margins) != StyleElementFlags.None)
			{
				VA.4X("Padding");
			}
			if ((flags & StyleElementFlags.Border) != StyleElementFlags.None)
			{
				VA.4X("Border");
			}
			if ((flags & StyleElementFlags.TextEffect) != StyleElementFlags.None)
			{
				VA.4X("TextEffect");
			}
			if ((flags & StyleElementFlags.ImageAlign) != StyleElementFlags.None)
			{
				VA.4X("AlignImage");
			}
			if ((flags & StyleElementFlags.ImageSpacing) != StyleElementFlags.None)
			{
				VA.4X("Spacing");
			}
			if ((flags & StyleElementFlags.Trimming) != StyleElementFlags.None)
			{
				VA.4X("Trimming");
			}
			if ((flags & StyleElementFlags.WordWrap) != StyleElementFlags.None)
			{
				VA.4X("Wrap");
			}
			if ((flags & StyleElementFlags.TextAlign) != StyleElementFlags.None)
			{
				VA.4X("AlignHorz");
				VA.4X("AlignVert");
			}
			if ((flags & StyleElementFlags.Display) != StyleElementFlags.None)
			{
				VA.4X("Display");
			}
			if ((flags & StyleElementFlags.Format) != StyleElementFlags.None)
			{
				VA.4X("Format");
				VA.4X("FormatStr");
			}
			if ((flags & StyleElementFlags.EditMask) != StyleElementFlags.None)
			{
				VA.4X("EditMask");
			}
			if ((flags & StyleElementFlags.ComboList) != StyleElementFlags.None)
			{
				VA.4X("ComboList");
			}
			if ((flags & StyleElementFlags.ImageMap) != StyleElementFlags.None)
			{
				VA.4X("ImageMap");
			}
			if ((flags & StyleElementFlags.DataType) != StyleElementFlags.None)
			{
				VA.4X("DataType");
			}
			if ((flags & StyleElementFlags.DataMap) != StyleElementFlags.None)
			{
				VA.4X("DataMap");
			}
		}

		public void Clear()
		{
			Clear(StyleElementFlags.All);
		}

		[D("Style.Merge", "Copies all defined attributes in a source CellStyle.")]
		public void MergeWith(CellStyle sourceStyle)
		{
			VA.51(sourceStyle.VA);
		}

		public string BuildString()
		{
			//IL_01b3: Unknown result type (might be due to invalid IL or missing references)
			StringBuilder stringBuilder = new StringBuilder();
			StyleElementFlags definedElements = DefinedElements;
			if ((definedElements & StyleElementFlags.Font) != StyleElementFlags.None)
			{
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "Font:{0};", new object[1] { 06.5M(Font) });
			}
			if ((definedElements & StyleElementFlags.BackColor) != StyleElementFlags.None)
			{
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "BackColor:{0};", new object[1] { 06.5M(BackColor) });
			}
			if ((definedElements & StyleElementFlags.ForeColor) != StyleElementFlags.None)
			{
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "ForeColor:{0};", new object[1] { 06.5M(ForeColor) });
			}
			if ((definedElements & StyleElementFlags.Margins) != StyleElementFlags.None)
			{
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "Margins:{0};", new object[1] { 06.5M(Margins) });
			}
			if ((definedElements & StyleElementFlags.TextAlign) != StyleElementFlags.None)
			{
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "TextAlign:{0};", new object[1] { 06.5M(TextAlign) });
			}
			if ((definedElements & StyleElementFlags.TextEffect) != StyleElementFlags.None)
			{
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "TextEffect:{0};", new object[1] { 06.5M(TextEffect) });
			}
			if ((definedElements & StyleElementFlags.ImageAlign) != StyleElementFlags.None)
			{
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "ImageAlign:{0};", new object[1] { 06.5M(ImageAlign) });
			}
			if ((definedElements & StyleElementFlags.ImageSpacing) != StyleElementFlags.None)
			{
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "ImageSpacing:{0};", new object[1] { 06.5M(ImageSpacing) });
			}
			if ((definedElements & StyleElementFlags.Trimming) != StyleElementFlags.None)
			{
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "Trimming:{0};", new object[1] { 06.5M(Trimming) });
			}
			if ((definedElements & StyleElementFlags.WordWrap) != StyleElementFlags.None)
			{
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "WordWrap:{0};", new object[1] { 06.5M(WordWrap) });
			}
			if ((definedElements & StyleElementFlags.Border) != StyleElementFlags.None)
			{
				CellBorder border = Border;
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "Border:{0},{1},{2},{3};", 06.5M(border.Style), border.Width, 06.5M(border.Color), 06.5M(border.Direction));
			}
			if ((definedElements & StyleElementFlags.Display) != StyleElementFlags.None)
			{
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "Display:{0};", new object[1] { 06.5M(Display) });
			}
			if ((definedElements & StyleElementFlags.Format) != StyleElementFlags.None && Format.Length > 0)
			{
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "Format:{0};", new object[1] { 06.5N(Format) });
			}
			if ((definedElements & StyleElementFlags.EditMask) != StyleElementFlags.None && EditMask.Length > 0)
			{
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "EditMask:{0};", new object[1] { 06.5N(EditMask) });
			}
			if ((definedElements & StyleElementFlags.ComboList) != StyleElementFlags.None && ComboList.Length > 0)
			{
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "ComboList:{0};", new object[1] { 06.5N(ComboList) });
			}
			if ((definedElements & StyleElementFlags.DataType) != StyleElementFlags.None)
			{
				stringBuilder.AppendFormat(CultureInfo.InvariantCulture, "DataType:{0};", new object[1] { 06.5M(DataType) });
			}
			return stringBuilder.ToString();
		}

		public bool ParseString(string str)
		{
			//IL_0020: Unknown result type (might be due to invalid IL or missing references)
			//IL_002a: Expected O, but got Unknown
			//IL_00a8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b2: Expected O, but got Unknown
			try
			{
				string text = 06.5O(str, "Font");
				if (text != null)
				{
					Font = (Font)06.5L(text, typeof(Font));
				}
				text = 06.5O(str, "BackColor");
				if (text != null)
				{
					BackColor = (Color)06.5L(text, typeof(Color));
				}
				text = 06.5O(str, "ForeColor");
				if (text != null)
				{
					ForeColor = (Color)06.5L(text, typeof(Color));
				}
				text = 06.5O(str, "Margins");
				if (text != null)
				{
					Margins = (Margins)06.5L(text, typeof(Margins));
				}
				text = 06.5O(str, "ImageAlign");
				if (text != null)
				{
					ImageAlign = (ImageAlignEnum)06.5L(text, typeof(ImageAlignEnum));
				}
				text = 06.5O(str, "ImageSpacing");
				if (text != null)
				{
					ImageSpacing = (int)06.5L(text, typeof(int));
				}
				text = 06.5O(str, "TextEffect");
				if (text != null)
				{
					TextEffect = (TextEffectEnum)06.5L(text, typeof(TextEffectEnum));
				}
				text = 06.5O(str, "TextAlign");
				if (text != null)
				{
					TextAlign = (TextAlignEnum)06.5L(text, typeof(TextAlignEnum));
				}
				text = 06.5O(str, "Trimming");
				if (text != null)
				{
					Trimming = (StringTrimming)06.5L(text, typeof(StringTrimming));
				}
				text = 06.5O(str, "Wrap");
				if (text != null)
				{
					WordWrap = (bool)06.5L(text, typeof(bool));
				}
				text = 06.5O(str, "Border");
				if (text != null)
				{
					string[] array = text.Split(new char[1] { ',' });
					string 05Z = "";
					if (array.Length == 4)
					{
						05Z = array[2];
					}
					if (array.Length == 6)
					{
						05Z = array[2] + "," + array[3] + "," + array[4];
					}
					if (array.Length == 7)
					{
						05Z = array[2] + "," + array[3] + "," + array[4] + "," + array[5];
					}
					CellBorder border = Border;
					border.Style = (BorderStyleEnum)06.5L(array[0], typeof(BorderStyleEnum));
					border.Width = (int)06.5L(array[1], typeof(int));
					border.Color = (Color)06.5L(05Z, typeof(Color));
					border.Direction = (BorderDirEnum)06.5L(array[^1], typeof(BorderDirEnum));
				}
				text = 06.5O(str, "Display");
				if (text != null)
				{
					Display = (DisplayEnum)06.5L(text, typeof(DisplayEnum));
				}
				text = 06.5O(str, "Format");
				if (text != null)
				{
					Format = text;
				}
				text = 06.5O(str, "EditMask");
				if (text != null)
				{
					EditMask = text;
				}
				text = 06.5O(str, "ComboList");
				if (text != null)
				{
					ComboList = text;
				}
				text = 06.5O(str, "DataType");
				if (text != null)
				{
					DataType = (Type)06.5L(text, typeof(Type));
				}
			}
			catch (Exception)
			{
				return false;
			}
			return true;
		}

		public override bool Equals(object o)
		{
			if (o is CellStyle cellStyle)
			{
				return cellStyle.VA == VA;
			}
			return false;
		}

		public override int GetHashCode()
		{
			return VA.GetHashCode();
		}

		internal ContentAlignment EY(string 0MW)
		{
			switch (TextAlign)
			{
			case TextAlignEnum.CenterBottom:
				return (ContentAlignment)512;
			case TextAlignEnum.CenterCenter:
				return (ContentAlignment)32;
			case TextAlignEnum.CenterTop:
				return (ContentAlignment)2;
			case TextAlignEnum.LeftBottom:
				return (ContentAlignment)256;
			case TextAlignEnum.LeftCenter:
				return (ContentAlignment)16;
			case TextAlignEnum.LeftTop:
				return (ContentAlignment)1;
			case TextAlignEnum.RightBottom:
				return (ContentAlignment)1024;
			case TextAlignEnum.RightCenter:
				return (ContentAlignment)64;
			case TextAlignEnum.RightTop:
				return (ContentAlignment)4;
			case TextAlignEnum.GeneralBottom:
				if (06.5G(0MW))
				{
					return (ContentAlignment)1024;
				}
				return (ContentAlignment)256;
			case TextAlignEnum.GeneralCenter:
				if (06.5G(0MW))
				{
					return (ContentAlignment)64;
				}
				return (ContentAlignment)16;
			case TextAlignEnum.GeneralTop:
				if (06.5G(0MW))
				{
					return (ContentAlignment)4;
				}
				return (ContentAlignment)1;
			default:
				return (ContentAlignment)1;
			}
		}

		internal Rectangle EZ(Rectangle 0MX)
		{
			return VA.5D(0MX);
		}

		private Color F0(string 0MY)
		{
			//IL_000e: Unknown result type (might be due to invalid IL or missing references)
			object obj = VA.4V(0MY);
			return ((SolidBrush)obj).Color;
		}

		private void F1(string 0MZ, Color 0N0)
		{
			//IL_001a: Unknown result type (might be due to invalid IL or missing references)
			if (!(0N0 == F0(0MZ)))
			{
				Brush 04I = (Brush)(0N0.IsSystemColor ? ((object)SystemBrushes.FromSystemColor(0N0)) : ((object)new SolidBrush(0N0)));
				VA.4U(0MZ, 04I);
			}
		}
	}
	[TypeConverter(typeof(ExpandableObjectConverter))]
	public class CellBorder
	{
		internal Style VF;

		internal BorderStyleEnum VG;

		internal BorderDirEnum VH;

		internal Color VI;

		internal int VJ;

		[RefreshProperties(RefreshProperties.Repaint)]
		[DefaultValue(BorderStyleEnum.Flat)]
		public BorderStyleEnum Style
		{
			get
			{
				return VG;
			}
			set
			{
				if (VG != value)
				{
					VG = value;
					F3();
				}
			}
		}

		[DefaultValue(BorderDirEnum.Both)]
		[RefreshProperties(RefreshProperties.Repaint)]
		public BorderDirEnum Direction
		{
			get
			{
				return VH;
			}
			set
			{
				if (VH != value)
				{
					VH = value;
					F3();
				}
			}
		}

		[RefreshProperties(RefreshProperties.Repaint)]
		public Color Color
		{
			get
			{
				return VI;
			}
			set
			{
				if (!(VI == value))
				{
					VI = value;
					F3();
				}
			}
		}

		[RefreshProperties(RefreshProperties.Repaint)]
		[DefaultValue(1)]
		public int Width
		{
			get
			{
				return VJ;
			}
			set
			{
				if (VJ != value)
				{
					VJ = value;
					F3();
				}
			}
		}

		internal CellBorder(Style style)
		{
			VF = style;
			F2();
		}

		internal void F2()
		{
			//IL_011f: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d8: Expected O, but got Unknown
			H h = (H)VF.4V("Border");
			VI = Color.Black;
			VJ = 1;
			if (h is I)
			{
				VG = BorderStyleEnum.None;
			}
			else if (h is K)
			{
				VG = BorderStyleEnum.Raised;
			}
			else if (h is L)
			{
				VG = BorderStyleEnum.Inset;
			}
			else if (h is M)
			{
				VG = BorderStyleEnum.Groove;
			}
			else if (h is N)
			{
				VG = BorderStyleEnum.Fillet;
			}
			else if (h is 0Y)
			{
				VG = BorderStyleEnum.Dotted;
				VI = ((0Y)h).VK;
			}
			else if (h is 0Z)
			{
				VG = BorderStyleEnum.Double;
				h = ((0Z)h).I4;
				SolidBrush val = (SolidBrush)h.I2;
				VI = ((val != null) ? val.Color : Color.Black);
				VJ = Math.Max(h.I1.Right, h.I1.Bottom);
			}
			else
			{
				VG = BorderStyleEnum.Flat;
				VI = ((SolidBrush)h.I2).Color;
				VJ = Math.Max(h.I1.Right, h.I1.Bottom);
			}
			VH = BorderDirEnum.Both;
			Margins val2 = h.2N();
			if (val2.Right > 0 && val2.Bottom == 0)
			{
				VH = BorderDirEnum.Vertical;
			}
			if (val2.Right == 0 && val2.Bottom > 0)
			{
				VH = BorderDirEnum.Horizontal;
			}
		}

		internal void F3()
		{
			int num = ((VH != BorderDirEnum.Vertical) ? VJ : 0);
			int num2 = ((VH != BorderDirEnum.Horizontal) ? VJ : 0);
			int horz = ((num > 0) ? 1 : 0);
			int vert = ((num2 > 0) ? 1 : 0);
			H 04I = null;
			switch (VG)
			{
			case BorderStyleEnum.None:
				04I = new I();
				break;
			case BorderStyleEnum.Flat:
				04I = new H(VI, 0, num2, 0, num);
				break;
			case BorderStyleEnum.Raised:
				04I = new K(horz, vert);
				break;
			case BorderStyleEnum.Inset:
				04I = new L(horz, vert);
				break;
			case BorderStyleEnum.Groove:
				04I = new M(horz, vert);
				break;
			case BorderStyleEnum.Fillet:
				04I = new N(horz, vert);
				break;
			case BorderStyleEnum.Double:
				04I = new 0Z(VI, num, num2);
				break;
			case BorderStyleEnum.Dotted:
				04I = new 0Y(VI, horz, vert);
				break;
			}
			VF.4U("Border", 04I);
		}
	}
	internal class 0Y : H
	{
		internal Color VK;

		public 0Y(Color color, int horz, int vert)
		{
			//IL_0016: Unknown result type (might be due to invalid IL or missing references)
			//IL_0020: Expected O, but got Unknown
			//IL_0025: Unknown result type (might be due to invalid IL or missing references)
			//IL_002f: Expected O, but got Unknown
			VK = color;
			I2 = (Brush)new HatchBrush((HatchStyle)12, color, Color.Transparent);
			I1 = new Margins(0, vert, 0, horz);
		}

		public override void 2O(Graphics 0N1, Rectangle 0N2)
		{
			if (I1.Bottom > 0)
			{
				0N1.FillRectangle(I2, 0N2.X, 0N2.Bottom - 1, 0N2.Width, 1);
			}
			if (I1.Right > 0)
			{
				0N1.FillRectangle(I2, 0N2.Right - 1, 0N2.Y, 1, 0N2.Height);
			}
		}
	}
	internal class 0Z : J
	{
		public 0Z(Color color, int horz, int vert)
		{
			I3 = new I(0, (vert > 0) ? 1 : 0, 0, (horz > 0) ? 1 : 0);
			2Q(new H(color, vert, vert, horz, horz));
		}
	}
	internal struct 10
	{
		private double VL;

		private double VM;

		private double VN;

		private double VO;

		private double VP;

		private double VQ;

		public void F4(object 0N3)
		{
			if (0N3 == null || 0N3 == DBNull.Value)
			{
				return;
			}
			VO += 1.0;
			double num = 06.5K(0N3);
			if (!double.IsNaN(num))
			{
				if (VN == 0.0)
				{
					VP = (VQ = num);
				}
				VN += 1.0;
				VL += num;
				VM += num * num;
				if (num < VQ)
				{
					VQ = num;
				}
				if (num > VP)
				{
					VP = num;
				}
			}
		}

		public double F5(AggregateEnum 0N4)
		{
			switch (0N4)
			{
			case AggregateEnum.Sum:
				return VL;
			case AggregateEnum.Count:
				return VO;
			case AggregateEnum.Average:
				if (VN != 0.0)
				{
					return VL / VN;
				}
				return 0.0;
			case AggregateEnum.Max:
				return VP;
			case AggregateEnum.Min:
				return VQ;
			case AggregateEnum.VarPop:
			{
				if (VN <= 1.0)
				{
					return 0.0;
				}
				double num = VL / VN;
				return VM / VN - num * num;
			}
			case AggregateEnum.StdPop:
				if (VN <= 1.0)
				{
					return 0.0;
				}
				return Math.Sqrt(F5(AggregateEnum.VarPop));
			case AggregateEnum.Var:
				if (VN <= 1.0)
				{
					return 0.0;
				}
				return F5(AggregateEnum.VarPop) * VN / (VN - 1.0);
			case AggregateEnum.Std:
				if (VN <= 1.0)
				{
					return 0.0;
				}
				return Math.Sqrt(F5(AggregateEnum.Var));
			default:
				return 0.0;
			}
		}
	}
	[Flags]
	public enum TreeStyleFlags
	{
		None = 0,
		Lines = 1,
		Symbols = 2,
		ButtonBar = 4,
		Leaf = 8,
		Complete = 7,
		Simple = 3,
		CompleteLeaf = 0xF,
		SimpleLeaf = 0xB
	}
	[TypeConverter(typeof(ExpandableObjectConverter))]
	public class GridTree
	{
		internal 0D VR;

		internal bool VS;

		internal int VT;

		internal int VU;

		internal Size VV;

		internal Brush VW;

		internal DashStyle VX;

		internal Color VY;

		internal TreeStyleFlags VZ;

		[DefaultValue(typeof(Color), "DarkGray")]
		public Color LineColor
		{
			get
			{
				return VY;
			}
			set
			{
				if (!(VY == value))
				{
					VY = value;
					F7(0N6: true);
				}
			}
		}

		[DefaultValue(/*Could not decode attribute arguments.*/)]
		public DashStyle LineStyle
		{
			get
			{
				//IL_0001: Unknown result type (might be due to invalid IL or missing references)
				return VX;
			}
			set
			{
				//IL_0001: Unknown result type (might be due to invalid IL or missing references)
				//IL_0006: Unknown result type (might be due to invalid IL or missing references)
				//IL_000b: Unknown result type (might be due to invalid IL or missing references)
				//IL_000c: Unknown result type (might be due to invalid IL or missing references)
				if (VX != value)
				{
					VX = value;
					F7(0N6: true);
				}
			}
		}

		[DefaultValue(TreeStyleFlags.Simple)]
		public TreeStyleFlags Style
		{
			get
			{
				return VZ;
			}
			set
			{
				if (VZ != value)
				{
					VZ = value;
					F7(0N6: true);
				}
			}
		}

		[DefaultValue(-1)]
		public int Column
		{
			get
			{
				return VU;
			}
			set
			{
				if (VU != value)
				{
					VU = value;
					F7(0N6: true);
				}
			}
		}

		[DefaultValue(13)]
		public int Indent
		{
			get
			{
				return VT;
			}
			set
			{
				VT = value;
				F7(0N6: true);
			}
		}

		[DefaultValue(null)]
		public Image NodeImageCollapsed
		{
			get
			{
				return VR.8B(GlyphEnum.Collapsed);
			}
			set
			{
				VR.89(GlyphEnum.Collapsed, value);
				F7(0N6: true);
			}
		}

		[DefaultValue(null)]
		public Image NodeImageExpanded
		{
			get
			{
				return VR.8B(GlyphEnum.Expanded);
			}
			set
			{
				VR.89(GlyphEnum.Expanded, value);
				F7(0N6: true);
			}
		}

		internal GridTree(0D grid)
		{
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			VR = grid;
			VT = 13;
			VU = -1;
			VX = (DashStyle)2;
			VY = Color.DarkGray;
			ref Size vV = ref VV;
			vV = new Size(0, 0);
			VZ = TreeStyleFlags.Simple;
			F7(0N6: false);
		}

		public void Show(int level)
		{
			if (level < 0)
			{
				level = int.MaxValue;
			}
			VR.8F(GridChangedTypeEnum.BeforeCollapse, -1, -1);
			if (VR.PM.VS)
			{
				return;
			}
			bool x = VR.X2;
			VR.X2 = false;
			try
			{
				RowCollection pJ = VR.PJ;
				for (int i = pJ.Fixed; i < pJ.Count; i++)
				{
					if (pJ[i].IsNode)
					{
						int u = pJ[i].U2;
						if (u >= 0 && u <= level)
						{
							Node node = pJ[i].Node;
							node.Collapsed = ((u == level) ? true : false);
						}
					}
				}
			}
			finally
			{
				VR.X2 = x;
			}
			VR.8F(GridChangedTypeEnum.AfterCollapse, -1, -1);
		}

		public void Sort(int level, SortFlags order, int col1, int col2)
		{
			bool x = VR.X2;
			VR.X2 = false;
			try
			{
				RowCollection pJ = VR.PJ;
				for (int i = pJ.Fixed; i < pJ.Count; i++)
				{
					if (pJ[i].IsNode && pJ[i].U2 == level)
					{
						Node node = pJ[i].Node;
						Node.D3(node, order, col1, col2);
						node = node.GetNode(NodeTypeEnum.LastSibling);
						i = node.GetCellRange().r2;
					}
				}
			}
			finally
			{
				VR.X2 = x;
			}
		}

		internal bool F6(TreeStyleFlags 0N5)
		{
			return (VZ & 0N5) != 0;
		}

		internal void F7(bool 0N6)
		{
			//IL_008a: Unknown result type (might be due to invalid IL or missing references)
			//IL_008f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0090: Unknown result type (might be due to invalid IL or missing references)
			//IL_0092: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a8: Expected I4, but got Unknown
			//IL_00b8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c2: Expected O, but got Unknown
			//IL_0105: Unknown result type (might be due to invalid IL or missing references)
			//IL_010f: Expected O, but got Unknown
			//IL_00d1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00db: Expected O, but got Unknown
			//IL_00eb: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f5: Expected O, but got Unknown
			//IL_0118: Unknown result type (might be due to invalid IL or missing references)
			//IL_0122: Expected O, but got Unknown
			Image val = VR.8A(GlyphEnum.Collapsed);
			Image val2 = VR.8A(GlyphEnum.Expanded);
			VV.Width = Math.Max(val.Width, val2.Width);
			VV.Height = Math.Max(val.Height, val2.Height);
			if (VT < VV.Width)
			{
				VT = VV.Width;
			}
			if (VW != null)
			{
				VW.Dispose();
			}
			DashStyle vX = VX;
			switch (vX - 1)
			{
			case 0:
				VW = (Brush)new HatchBrush((HatchStyle)21, VY, Color.Transparent);
				break;
			case 2:
				VW = (Brush)new HatchBrush((HatchStyle)5, VY, Color.Transparent);
				break;
			case 3:
				VW = (Brush)new HatchBrush((HatchStyle)31, VY, Color.Transparent);
				break;
			case 1:
				VW = (Brush)new HatchBrush((HatchStyle)12, VY, Color.Transparent);
				break;
			default:
				VW = (Brush)new SolidBrush(VY);
				break;
			}
			if (0N6)
			{
				VR.8G(GridChangedTypeEnum.RepaintGrid);
			}
		}

		internal void F8(Row 0N7, bool 0N8)
		{
			if (0N7.IsNode == 0N8)
			{
				return;
			}
			0N7.DD(0R.TP, 0N8);
			if (0N8 && !0N7.Visible)
			{
				Node node = 0N7.Node.GetNode(NodeTypeEnum.Parent);
				if (node == null || node.Expanded)
				{
					0N7.Visible = true;
				}
			}
			0N7.TW.DM();
			VR.8G(GridChangedTypeEnum.RepaintGrid);
		}

		internal Node F9(Row 0N9)
		{
			if (0N9.IsNode)
			{
				return new Node(0N9);
			}
			RowCollection pJ = VR.PJ;
			if (VR.X4 == SubtotalPositionEnum.AboveData)
			{
				for (int num = 0N9.Index; num >= 0; num--)
				{
					if (pJ[num].IsNode)
					{
						return new Node(pJ[num]);
					}
				}
			}
			else
			{
				for (int i = 0N9.Index; i < pJ.Count; i++)
				{
					if (pJ[i].IsNode)
					{
						return new Node(pJ[i]);
					}
				}
			}
			return null;
		}

		internal Image FA(int 0NA)
		{
			Row row = VR.PJ[0NA];
			if (!row.IsNode)
			{
				return null;
			}
			Row row2 = null;
			bool flag = VR.PR == SubtotalPositionEnum.AboveData;
			if (flag && 0NA < VR.PJ.Count - 1)
			{
				row2 = VR.PJ[0NA + 1];
			}
			if (!flag && 0NA > VR.PJ.Fixed)
			{
				row2 = VR.PJ[0NA - 1];
			}
			if (row2 == null)
			{
				return null;
			}
			if (row2.IsNode && row2.U2 <= row.U2)
			{
				return null;
			}
			bool flag2 = (VR.PJ[0NA].TV & 0R.TQ) != 0R.TH;
			return VR.8A(flag2 ? GlyphEnum.Collapsed : GlyphEnum.Expanded);
		}

		internal Rectangle FB(Rectangle 0NB, int 0NC)
		{
			Rectangle result = new Rectangle(0, 0, 0, 0);
			if (0NC < 0)
			{
				return result;
			}
			result = 0NB;
			result.X += 0NC * VT;
			result.Width = VT;
			return result;
		}

		internal Rectangle FC(Rectangle 0ND, int 0NE)
		{
			Rectangle result = new Rectangle(0, 0, 0, 0);
			if (0NE < 0)
			{
				return result;
			}
			result.X = 0ND.X + 0NE * VT + (VT - VV.Width) / 2;
			result.Y = 0ND.Y + (0ND.Height - VV.Height) / 2;
			result.Width = VV.Width;
			result.Height = VV.Height;
			result.Intersect(0ND);
			return result;
		}

		internal int FD(int 0NF)
		{
			if (Column != 0NF)
			{
				return 0;
			}
			if (Style == TreeStyleFlags.None)
			{
				return 0;
			}
			int xG = VR.PJ.XG;
			if (xG < 0)
			{
				return 0;
			}
			return Indent * (xG + 1);
		}

		internal int FE(int 0NG, int 0NH)
		{
			if (Column != 0NH || 0NG < VR.PJ.Fixed)
			{
				return 0;
			}
			Node node = VR.PJ[0NG].Node;
			if (node == null || node.Level < 0)
			{
				return 0;
			}
			return (node.Level + 1) * Indent;
		}

		internal void FF(Graphics 0NI, Style 0NJ, Rectangle 0NK, string 0NL, Image 0NM)
		{
			int xG = VR.PJ.XG;
			Rectangle 04X;
			for (int i = 0; i <= xG; i++)
			{
				04X = FB(0NK, i);
				string 04Y = string.Format(CultureInfo.CurrentCulture, "{0}", new object[1] { i + 1 });
				0NJ.54(0NI, 04X, 04Y);
			}
			04X = FB(0NK, xG + 1);
			0NJ.54(0NI, 04X, "*");
			int num = 04X.Right - 0NK.X;
			0NK.X += num;
			0NK.Width -= num;
			0NJ.53(0NI, 0NK, 0NL, 0NM);
		}

		internal void FG(C1FlexGridBase 0NN, Graphics 0NO, Rectangle 0NP, Node 0NQ, int 0NR)
		{
			int num = 0NQ?.Level ?? (-1);
			Rectangle 11 = FC(0NP, num);
			if (F6(TreeStyleFlags.Lines))
			{
				RowCollection pJ = VR.PJ;
				bool isNode = pJ[0NR].IsNode;
				bool flag = isNode && pJ[0NR].Node.Collapsed;
				bool flag2 = num <= 0;
				bool flag3 = F6(TreeStyleFlags.Leaf);
				bool flag4 = VR.X4 == SubtotalPositionEnum.AboveData;
				int num2 = 0NN.CheckNodeChildren(0NR, Column, num);
				bool flag5 = (num2 & 2) != 0 || (flag3 && (num2 & 1) != 0);
				Point point = new Point(0NP.X + num * VT + VT / 2, 0NP.Y + 0NP.Height / 2);
				Point point2 = point;
				Point point3 = new Point(point.X + VT / 2, point.Y);
				if (isNode && !flag2)
				{
					point2.X -= VT;
					0NO.FillRectangle(VW, point2.X, point2.Y, Math.Min(point.X, 0NP.Right) - point2.X, 1);
					if (flag4)
					{
						0NO.FillRectangle(VW, point2.X, 0NP.Y, 1, point2.Y - 0NP.Y);
					}
					else
					{
						0NO.FillRectangle(VW, point2.X, point2.Y, 1, 0NP.Bottom - point2.Y);
					}
				}
				else if (!isNode && flag3)
				{
					0NO.FillRectangle(VW, point2.X, point2.Y, Math.Min(point3.X, 0NP.Right) - point2.X, 1);
				}
				if (isNode || flag3)
				{
					point2 = (point3 = point);
					if (flag4)
					{
						if (!isNode)
						{
							point2.Y = 0NP.Y;
						}
						if (!flag && flag5)
						{
							point3.Y = 0NP.Bottom;
						}
					}
					else
					{
						if (!isNode)
						{
							point3.Y = 0NP.Bottom;
						}
						if (!flag && flag5)
						{
							point2.Y = 0NP.Y;
						}
					}
					0NO.FillRectangle(VW, point2.X, point2.Y, 1, point3.Y - point2.Y);
				}
				int num3 = 10000;
				if (flag4)
				{
					for (int i = 0NR + 1; i < pJ.Count; i++)
					{
						if (pJ[i].IsNode)
						{
							int u = pJ[i].U2;
							if (u <= 0)
							{
								break;
							}
							if (u < num3 && u <= num + 1 && (!isNode || u <= num))
							{
								int num4 = 0NP.X + u * VT - VT / 2 - 1;
								0NO.FillRectangle(VW, num4, 0NP.Y, 1, 0NP.Height);
								num3 = u;
							}
						}
					}
				}
				else
				{
					for (int num5 = 0NR - 1; num5 >= pJ.Fixed; num5--)
					{
						if (pJ[num5].IsNode)
						{
							int u2 = pJ[num5].U2;
							if (u2 <= 0)
							{
								break;
							}
							if (u2 < num3 && u2 <= num + 1 && (!isNode || u2 <= num))
							{
								int num6 = 0NP.X + u2 * VT - VT / 2 - 1;
								0NO.FillRectangle(VW, num6, 0NP.Y, 1, 0NP.Height);
								num3 = u2;
							}
						}
					}
				}
			}
			if (F6(TreeStyleFlags.Symbols))
			{
				Image val = FA(0NR);
				if (val != null)
				{
					0D.PF.55(0NO, 11, val);
				}
			}
		}

		internal int FH(int 0NS, MoveCursorEnum 0NT)
		{
			if (VR.86(Column) || !F6(TreeStyleFlags.Symbols))
			{
				return 0NS;
			}
			if (!VR.PJ[0NS].IsNode)
			{
				return 0NS;
			}
			Node node = VR.PJ[0NS].Node;
			if (node.Level < 0)
			{
				return 0NS;
			}
			switch (0NT)
			{
			case MoveCursorEnum.CellLeft:
				if (!node.Collapsed)
				{
					node.Collapsed = true;
					if (node.Collapsed)
					{
						return 0NS;
					}
				}
				node = node.GetNode(NodeTypeEnum.Parent);
				if (node != null)
				{
					0NS = node.Row.Index;
				}
				return 0NS;
			case MoveCursorEnum.CellRight:
				if (node.Collapsed)
				{
					node.Collapsed = false;
					if (!node.Collapsed)
					{
						return 0NS;
					}
				}
				node = node.GetNode(NodeTypeEnum.FirstChild);
				if (node != null)
				{
					0NS = node.Row.Index;
				}
				return 0NS;
			default:
				return 0NS;
			}
		}
	}
}
internal class 11
{
	[StructLayout(LayoutKind.Explicit, Pack = 1, Size = 1024)]
	private struct 12
	{
	}

	[StructLayout(LayoutKind.Explicit, Pack = 1, Size = 1024)]
	private struct 13
	{
	}

	[StructLayout(LayoutKind.Explicit, Pack = 1, Size = 16)]
	private struct 14
	{
	}

	[StructLayout(LayoutKind.Explicit, Pack = 1, Size = 24)]
	private struct 15
	{
	}

	[StructLayout(LayoutKind.Explicit, Pack = 1, Size = 32)]
	private struct 16
	{
	}

	internal static 12 W0/* Not supported: data(00 00 00 00 C1 C0 00 00 81 C1 00 00 40 01 00 00 01 C3 00 00 C0 03 00 00 80 02 00 00 41 C2 00 00 01 C6 00 00 C0 06 00 00 80 07 00 00 41 C7 00 00 00 05 00 00 C1 C5 00 00 81 C4 00 00 40 04 00 00 01 CC 00 00 C0 0C 00 00 80 0D 00 00 41 CD 00 00 00 0F 00 00 C1 CF 00 00 81 CE 00 00 40 0E 00 00 00 0A 00 00 C1 CA 00 00 81 CB 00 00 40 0B 00 00 01 C9 00 00 C0 09 00 00 80 08 00 00 41 C8 00 00 01 D8 00 00 C0 18 00 00 80 19 00 00 41 D9 00 00 00 1B 00 00 C1 DB 00 00 81 DA 00 00 40 1A 00 00 00 1E 00 00 C1 DE 00 00 81 DF 00 00 40 1F 00 00 01 DD 00 00 C0 1D 00 00 80 1C 00 00 41 DC 00 00 00 14 00 00 C1 D4 00 00 81 D5 00 00 40 15 00 00 01 D7 00 00 C0 17 00 00 80 16 00 00 41 D6 00 00 01 D2 00 00 C0 12 00 00 80 13 00 00 41 D3 00 00 00 11 00 00 C1 D1 00 00 81 D0 00 00 40 10 00 00 01 F0 00 00 C0 30 00 00 80 31 00 00 41 F1 00 00 00 33 00 00 C1 F3 00 00 81 F2 00 00 40 32 00 00 00 36 00 00 C1 F6 00 00 81 F7 00 00 40 37 00 00 01 F5 00 00 C0 35 00 00 80 34 00 00 41 F4 00 00 00 3C 00 00 C1 FC 00 00 81 FD 00 00 40 3D 00 00 01 FF 00 00 C0 3F 00 00 80 3E 00 00 41 FE 00 00 01 FA 00 00 C0 3A 00 00 80 3B 00 00 41 FB 00 00 00 39 00 00 C1 F9 00 00 81 F8 00 00 40 38 00 00 00 28 00 00 C1 E8 00 00 81 E9 00 00 40 29 00 00 01 EB 00 00 C0 2B 00 00 80 2A 00 00 41 EA 00 00 01 EE 00 00 C0 2E 00 00 80 2F 00 00 41 EF 00 00 00 2D 00 00 C1 ED 00 00 81 EC 00 00 40 2C 00 00 01 E4 00 00 C0 24 00 00 80 25 00 00 41 E5 00 00 00 27 00 00 C1 E7 00 00 81 E6 00 00 40 26 00 00 00 22 00 00 C1 E2 00 00 81 E3 00 00 40 23 00 00 01 E1 00 00 C0 21 00 00 80 20 00 00 41 E0 00 00 01 A0 00 00 C0 60 00 00 80 61 00 00 41 A1 00 00 00 63 00 00 C1 A3 00 00 81 A2 00 00 40 62 00 00 00 66 00 00 C1 A6 00 00 81 A7 00 00 40 67 00 00 01 A5 00 00 C0 65 00 00 80 64 00 00 41 A4 00 00 00 6C 00 00 C1 AC 00 00 81 AD 00 00 40 6D 00 00 01 AF 00 00 C0 6F 00 00 80 6E 00 00 41 AE 00 00 01 AA 00 00 C0 6A 00 00 80 6B 00 00 41 AB 00 00 00 69 00 00 C1 A9 00 00 81 A8 00 00 40 68 00 00 00 78 00 00 C1 B8 00 00 81 B9 00 00 40 79 00 00 01 BB 00 00 C0 7B 00 00 80 7A 00 00 41 BA 00 00 01 BE 00 00 C0 7E 00 00 80 7F 00 00 41 BF 00 00 00 7D 00 00 C1 BD 00 00 81 BC 00 00 40 7C 00 00 01 B4 00 00 C0 74 00 00 80 75 00 00 41 B5 00 00 00 77 00 00 C1 B7 00 00 81 B6 00 00 40 76 00 00 00 72 00 00 C1 B2 00 00 81 B3 00 00 40 73 00 00 01 B1 00 00 C0 71 00 00 80 70 00 00 41 B0 00 00 00 50 00 00 C1 90 00 00 81 91 00 00 40 51 00 00 01 93 00 00 C0 53 00 00 80 52 00 00 41 92 00 00 01 96 00 00 C0 56 00 00 80 57 00 00 41 97 00 00 00 55 00 00 C1 95 00 00 81 94 00 00 40 54 00 00 01 9C 00 00 C0 5C 00 00 80 5D 00 00 41 9D 00 00 00 5F 00 00 C1 9F 00 00 81 9E 00 00 40 5E 00 00 00 5A 00 00 C1 9A 00 00 81 9B 00 00 40 5B 00 00 01 99 00 00 C0 59 00 00 80 58 00 00 41 98 00 00 01 88 00 00 C0 48 00 00 80 49 00 00 41 89 00 00 00 4B 00 00 C1 8B 00 00 81 8A 00 00 40 4A 00 00 00 4E 00 00 C1 8E 00 00 81 8F 00 00 40 4F 00 00 01 8D 00 00 C0 4D 00 00 80 4C 00 00 41 8C 00 00 00 44 00 00 C1 84 00 00 81 85 00 00 40 45 00 00 01 87 00 00 C0 47 00 00 80 46 00 00 41 86 00 00 01 82 00 00 C0 42 00 00 80 43 00 00 41 83 00 00 00 41 00 00 C1 81 00 00 81 80 00 00 40 40 00 00) */;

	internal static 13 W1/* Not supported: data(00 00 00 00 96 30 07 77 2C 61 0E EE BA 51 09 99 19 C4 6D 07 8F F4 6A 70 35 A5 63 E9 A3 95 64 9E 32 88 DB 0E A4 B8 DC 79 1E E9 D5 E0 88 D9 D2 97 2B 4C B6 09 BD 7C B1 7E 07 2D B8 E7 91 1D BF 90 64 10 B7 1D F2 20 B0 6A 48 71 B9 F3 DE 41 BE 84 7D D4 DA 1A EB E4 DD 6D 51 B5 D4 F4 C7 85 D3 83 56 98 6C 13 C0 A8 6B 64 7A F9 62 FD EC C9 65 8A 4F 5C 01 14 D9 6C 06 63 63 3D 0F FA F5 0D 08 8D C8 20 6E 3B 5E 10 69 4C E4 41 60 D5 72 71 67 A2 D1 E4 03 3C 47 D4 04 4B FD 85 0D D2 6B B5 0A A5 FA A8 B5 35 6C 98 B2 42 D6 C9 BB DB 40 F9 BC AC E3 6C D8 32 75 5C DF 45 CF 0D D6 DC 59 3D D1 AB AC 30 D9 26 3A 00 DE 51 80 51 D7 C8 16 61 D0 BF B5 F4 B4 21 23 C4 B3 56 99 95 BA CF 0F A5 BD B8 9E B8 02 28 08 88 05 5F B2 D9 0C C6 24 E9 0B B1 87 7C 6F 2F 11 4C 68 58 AB 1D 61 C1 3D 2D 66 B6 90 41 DC 76 06 71 DB 01 BC 20 D2 98 2A 10 D5 EF 89 85 B1 71 1F B5 B6 06 A5 E4 BF 9F 33 D4 B8 E8 A2 C9 07 78 34 F9 00 0F 8E A8 09 96 18 98 0E E1 BB 0D 6A 7F 2D 3D 6D 08 97 6C 64 91 01 5C 63 E6 F4 51 6B 6B 62 61 6C 1C D8 30 65 85 4E 00 62 F2 ED 95 06 6C 7B A5 01 1B C1 F4 08 82 57 C4 0F F5 C6 D9 B0 65 50 E9 B7 12 EA B8 BE 8B 7C 88 B9 FC DF 1D DD 62 49 2D DA 15 F3 7C D3 8C 65 4C D4 FB 58 61 B2 4D CE 51 B5 3A 74 00 BC A3 E2 30 BB D4 41 A5 DF 4A D7 95 D8 3D 6D C4 D1 A4 FB F4 D6 D3 6A E9 69 43 FC D9 6E 34 46 88 67 AD D0 B8 60 DA 73 2D 04 44 E5 1D 03 33 5F 4C 0A AA C9 7C 0D DD 3C 71 05 50 AA 41 02 27 10 10 0B BE 86 20 0C C9 25 B5 68 57 B3 85 6F 20 09 D4 66 B9 9F E4 61 CE 0E F9 DE 5E 98 C9 D9 29 22 98 D0 B0 B4 A8 D7 C7 17 3D B3 59 81 0D B4 2E 3B 5C BD B7 AD 6C BA C0 20 83 B8 ED B6 B3 BF 9A 0C E2 B6 03 9A D2 B1 74 39 47 D5 EA AF 77 D2 9D 15 26 DB 04 83 16 DC 73 12 0B 63 E3 84 3B 64 94 3E 6A 6D 0D A8 5A 6A 7A 0B CF 0E E4 9D FF 09 93 27 AE 00 0A B1 9E 07 7D 44 93 0F F0 D2 A3 08 87 68 F2 01 1E FE C2 06 69 5D 57 62 F7 CB 67 65 80 71 36 6C 19 E7 06 6B 6E 76 1B D4 FE E0 2B D3 89 5A 7A DA 10 CC 4A DD 67 6F DF B9 F9 F9 EF BE 8E 43 BE B7 17 D5 8E B0 60 E8 A3 D6 D6 7E 93 D1 A1 C4 C2 D8 38 52 F2 DF 4F F1 67 BB D1 67 57 BC A6 DD 06 B5 3F 4B 36 B2 48 DA 2B 0D D8 4C 1B 0A AF F6 4A 03 36 60 7A 04 41 C3 EF 60 DF 55 DF 67 A8 EF 8E 6E 31 79 BE 69 46 8C B3 61 CB 1A 83 66 BC A0 D2 6F 25 36 E2 68 52 95 77 0C CC 03 47 0B BB B9 16 02 22 2F 26 05 55 BE 3B BA C5 28 0B BD B2 92 5A B4 2B 04 6A B3 5C A7 FF D7 C2 31 CF D0 B5 8B 9E D9 2C 1D AE DE 5B B0 C2 64 9B 26 F2 63 EC 9C A3 6A 75 0A 93 6D 02 A9 06 09 9C 3F 36 0E EB 85 67 07 72 13 57 00 05 82 4A BF 95 14 7A B8 E2 AE 2B B1 7B 38 1B B6 0C 9B 8E D2 92 0D BE D5 E5 B7 EF DC 7C 21 DF DB 0B D4 D2 D3 86 42 E2 D4 F1 F8 B3 DD 68 6E 83 DA 1F CD 16 BE 81 5B 26 B9 F6 E1 77 B0 6F 77 47 B7 18 E6 5A 08 88 70 6A 0F FF CA 3B 06 66 5C 0B 01 11 FF 9E 65 8F 69 AE 62 F8 D3 FF 6B 61 45 CF 6C 16 78 E2 0A A0 EE D2 0D D7 54 83 04 4E C2 B3 03 39 61 26 67 A7 F7 16 60 D0 4D 47 69 49 DB 77 6E 3E 4A 6A D1 AE DC 5A D6 D9 66 0B DF 40 F0 3B D8 37 53 AE BC A9 C5 9E BB DE 7F CF B2 47 E9 FF B5 30 1C F2 BD BD 8A C2 BA CA 30 93 B3 53 A6 A3 B4 24 05 36 D0 BA 93 06 D7 CD 29 57 DE 54 BF 67 D9 23 2E 7A 66 B3 B8 4A 61 C4 02 1B 68 5D 94 2B 6F 2A 37 BE 0B B4 A1 8E 0C C3 1B DF 05 5A 8D EF 02 2D) */;

	internal static 14 W2/* Not supported: data(00 00 00 41 00 00 00 41 00 00 80 3F 00 00 00 41) */;

	internal static 15 W3/* Not supported: data(00 00 00 41 00 00 00 41 00 00 80 3F 00 00 00 41 00 00 80 3F 00 00 00 41) */;

	internal static 16 W4/* Not supported: data(00 00 16 43 00 00 16 43 00 00 16 43 00 00 16 43 00 00 16 43 00 00 16 43 00 00 16 43 00 00 16 43) */;
}
