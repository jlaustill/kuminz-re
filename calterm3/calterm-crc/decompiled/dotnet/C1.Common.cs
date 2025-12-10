using System;
using System.Collections;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Data;
using System.Drawing;
using System.Drawing.Design;
using System.Drawing.Imaging;
using System.Drawing.Printing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Windows.Forms;
using System.Windows.Forms.Design;
using System.Xml.Serialization;
using C1.C1PrintDocument;
using C1.C1PrintDocument.DocEngine;
using C1.C1PrintDocument.DocEngine.Render;
using C1.C1PrintDocument.DocEngine.Src;
using C1.C1PrintDocument.Export;
using C1.C1PrintDocument.Util;
using C1.Util;

[assembly: AssemblyConfiguration("")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyCompany("ComponentOne LLC")]
[assembly: AssemblyDescription("Common interfaces and definitions for ComponentOne components.")]
[assembly: CLSCompliant(true)]
[assembly: AssemblyTitle("C1.Common")]
[assembly: AssemblyKeyName("")]
[assembly: AssemblyKeyFile("..\\..\\C1.Common.snk")]
[assembly: AssemblyFileVersion("1.0.20031.117")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyCopyright("© 2002, ComponentOne LLC. All rights reserved.")]
[assembly: AssemblyProduct("")]
[assembly: AssemblyVersion("1.0.20031.116")]
namespace C1.C1PrintDocument.ControlPrinters
{
	public abstract class ControlPrintInfoBase
	{
	}
	public interface IC1ControlPrinter
	{
		double WidthMm { get; }

		double HeightMm { get; }

		event EventHandler WidthChanged;

		event EventHandler HeightChanged;

		void GeneratePortion(bool generateAll, double availableHeightMm, double availableWidthMm, out double generatedHeightMm, out double generatedWidthMm, out C1.C1PrintDocument.DocEngine.Src.IDrawel drawel, out bool finished);

		void Initialize(ControlPrintInfoBase info);
	}
	public interface IC1ControlPrintable
	{
		IC1ControlPrinter GetPrinter();
	}
}
namespace C1.C1PrintDocument.DocEngine.Render
{
	public interface IDrawel
	{
		ILayer Layer { get; }

		IPage Page { get; }

		C1.C1PrintDocument.DocEngine.Src.IDrawel Source { get; }

		RectangleF RectAll { get; }

		RectangleF RectBorder { get; }

		RectangleF RectPadding { get; }

		RectangleF RectContent { get; }

		float Rotation { get; }

		RectangleF GetRectangle(DrawelBoundsEnum bounds);
	}
	public interface ILayer
	{
		IPage Page { get; }

		IEnumerable Drawels { get; }

		int Order { get; }
	}
	public interface IPage
	{
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		long PageId { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		int PageIdx { get; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		int PageNo { get; }

		IEnumerable Layers { get; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		PageSettings PageSettings { get; set; }

		void Draw(Graphics g);

		Metafile MakeMetafile();

		C1Stack FetchOutlineEntries(int pageNo, bool needAreas);
	}
	public interface IPages : ICollection, IEnumerable
	{
	}
	public interface IRoot
	{
		IPages Pages { get; }
	}
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public enum DrawelBoundsEnum
	{
		All,
		Border,
		Padding,
		Content
	}
}
namespace C1.C1PrintDocument.DocEngine.Src
{
	public interface IDictionary
	{
		string Name { get; set; }

		void AddImage(string name, Image image);
	}
	public interface IDictionaryProvider
	{
		IDictionary Dictionary { get; }

		void CreateDictionary(string name);
	}
	public interface IDictionaryItem
	{
		string Name { get; set; }
	}
}
namespace C1.Util
{
	public interface ITreeNode
	{
		ITreeNode Parent { get; }

		bool IsRoot { get; }

		bool IsLeaf { get; }

		IEnumerable Children { get; }

		ITreeNode FirstChild { get; }

		ITreeNode LastChild { get; }

		ITreeNode FirstSibling { get; }

		ITreeNode LastSibling { get; }

		ITreeNode PrevSibling { get; }

		ITreeNode NextSibling { get; }

		ITreeNode Root { get; }

		int Level { get; }

		IEnumerable All { get; }

		bool IsChildOf(ITreeNode parent);

		bool IsParentOf(ITreeNode child);

		ITreeNode ChildAt(int index);

		ITreeNode InsertChild(ITreeNode newChild, int index);

		ITreeNode InsertChild(ITreeNode newChild, ITreeNode before);

		ITreeNode AppendChild(ITreeNode newChild);

		ITreeNode InsertBefore(ITreeNode next);

		ITreeNode InsertAfter(ITreeNode prev);

		ITreeNode RemoveNode();

		string MakeIndexPath();

		void TraverseSubTree(NodeProc nodeProc, object param);
	}
}
namespace C1.C1PrintDocument.DocEngine.Src
{
	public interface IDrawelBase : ITreeNode
	{
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		long Id { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		string Name { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		Stacking Stack { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		LengthUnit LengthUnits { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		string X { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		string Y { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		string Width { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		string Height { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		float Rotation { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		Widths Spacing { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		Widths Padding { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		Widths BorderWidths { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		Names.RefSource Repeat { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		bool CanCausePageBreak { get; set; }

		IDrawelBase Copy();
	}
	public interface IDrawel : IDrawelBase, ITreeNode
	{
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		int Layer { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		int BorderLayerShift { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		C1DColors BorderColors { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		Font Font { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		Color Color { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		Color BackColor { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		Image BackgroundImage { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		string BackgroundImageDictName { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		C1DImageAlign BackgroundImageAlign { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		OutlineInfo OutlineInfo { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		object UserData { get; set; }
	}
	public interface IDrawelArea : IDrawel, IDrawelBase, ITreeNode, IDictionaryProvider
	{
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		IDrawelBase PageHeader { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		IDrawelBase PageFooter { get; set; }
	}
	public class DrawelConstants
	{
		public const LengthUnit.Units DefaultUnits = LengthUnit.Units.Doc;
	}
	public interface IDrawelGraphPathSet : IDrawel, IDrawelBase, ITreeNode
	{
	}
	public interface IDrawelImage : IDrawel, IDrawelBase, ITreeNode
	{
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		Image Image { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		string ImageDictName { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		C1DImageAlign ImageAlign { get; set; }
	}
	public interface IDrawelTextBase : IDrawel, IDrawelBase, ITreeNode
	{
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		bool CanSplit { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		Names.HorzTextAlignment HAlign { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		Names.VertTextAlignment VAlign { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		bool WordWrap { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		string TagPageNo { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		string TagTotalPages { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		string Text { get; set; }
	}
	public interface IDrawelMarkup : IDrawelTextBase, IDrawel, IDrawelBase, ITreeNode
	{
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		float LineSpacing { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		bool JustifyLastLine { get; set; }
	}
	public interface IDrawelPageSetting : IDrawel, IDrawelBase, ITreeNode
	{
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		PageSettings PageSettings { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		int PageNoBase { get; set; }
	}
	public interface IDrawelNewPage : IDrawelPageSetting, IDrawel, IDrawelBase, ITreeNode
	{
	}
	public interface IDrawelOwnerDraw : IDrawel, IDrawelBase, ITreeNode
	{
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		bool DependsOnTotalPages { get; set; }

		event DrawelOwnerDrawHandler OwnerDraw;
	}
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public class DrawelOwnerDrawArgs : EventArgs
	{
		public Graphics Graphics = null;

		public RectangleF Rect = RectangleF.Empty;

		public int PageNo = -1;

		public int TotalPages = -1;
	}
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public delegate void DrawelOwnerDrawHandler(object sender, DrawelOwnerDrawArgs e);
	public interface IDrawelPolygon : IDrawel, IDrawelBase, ITreeNode
	{
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		LengthInUnits LineWidth { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		Color FillColor { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		bool Closed { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		PointF[] Points { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		string PointsStr { get; set; }
	}
	public interface IDrawelRoot : IDrawelPageSetting, IDrawel, IDrawelBase, ITreeNode, IDictionaryProvider
	{
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		bool Reflowable { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		IDrawelBase PageHeader { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		IDrawelBase PageFooter { get; set; }
	}
	public interface IDrawelText : IDrawelTextBase, IDrawel, IDrawelBase, ITreeNode
	{
	}
	[TypeConverter(typeof(TypeConverter))]
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public sealed class C1DImageAlign
	{
		public class TypeConverter : TypeConverterBase
		{
			protected override object ObjFromString(string str)
			{
				return (C1DImageAlign)str;
			}

			protected override string StringFromObj(object o)
			{
				return (string)(C1DImageAlign)o;
			}
		}

		private static char[] s_delims = new char[2] { ';', ':' };

		private static char[] s_comma = new char[1] { ',' };

		private Names.ImageAlignment _alignHorz = Names.ImageAlignment.left;

		private Names.ImageAlignment _alignVert = Names.ImageAlignment.top;

		private float _zoom = 100f;

		private float _aspect = 0f;

		private bool _fit = false;

		private bool _tileHorz = false;

		private bool _tileVert = false;

		public static readonly C1DImageAlign DefaultImageAlign = new C1DImageAlign();

		public Names.ImageAlignment AlignHorz
		{
			get
			{
				return _alignHorz;
			}
			set
			{
				_alignHorz = value;
			}
		}

		public Names.ImageAlignment AlignVert
		{
			get
			{
				return _alignVert;
			}
			set
			{
				_alignVert = value;
			}
		}

		public Names.ImageAlignment Align
		{
			set
			{
				_alignHorz = (_alignVert = value);
			}
		}

		public float Zoom
		{
			get
			{
				return _zoom;
			}
			set
			{
				_zoom = value;
			}
		}

		public float Aspect
		{
			get
			{
				return _aspect;
			}
			set
			{
				_aspect = value;
			}
		}

		public bool Fit
		{
			get
			{
				return _fit;
			}
			set
			{
				_fit = value;
			}
		}

		public bool TileHorz
		{
			get
			{
				return _tileHorz;
			}
			set
			{
				_tileHorz = value;
			}
		}

		public bool TileVert
		{
			get
			{
				return _tileVert;
			}
			set
			{
				_tileVert = value;
			}
		}

		public bool Tile
		{
			set
			{
				_tileHorz = (_tileVert = value);
			}
		}

		public override bool Equals(object o)
		{
			if (o == null)
			{
				return false;
			}
			C1DImageAlign c1DImageAlign = (C1DImageAlign)o;
			if (c1DImageAlign.AlignHorz == AlignHorz && c1DImageAlign.AlignVert == AlignVert && c1DImageAlign.Zoom == Zoom && c1DImageAlign.Aspect == Aspect && c1DImageAlign.Fit == Fit && c1DImageAlign.TileHorz == TileHorz)
			{
				return c1DImageAlign.TileVert == TileVert;
			}
			return false;
		}

		public static explicit operator C1DImageAlign(string str)
		{
			C1DImageAlign c1DImageAlign = new C1DImageAlign();
			try
			{
				string[] array = str.Split(s_delims);
				string text = string.Empty;
				string[] array2 = array;
				foreach (string text2 in array2)
				{
					if (text.Length == 0)
					{
						text = text2;
						continue;
					}
					if (text2.Length == 0)
					{
						return c1DImageAlign;
					}
					string text3 = text;
					text = string.Empty;
					switch (text3)
					{
					case "align":
					{
						string[] array4 = text2.Split(s_comma);
						if (array4.Length == 1)
						{
							Names.ImageAlignment alignHorz = (c1DImageAlign.AlignVert = (Names.ImageAlignment)Enum.Parse(typeof(Names.ImageAlignment), array4[0]));
							c1DImageAlign.AlignHorz = alignHorz;
						}
						else if (array4.Length == 2)
						{
							c1DImageAlign.AlignHorz = (Names.ImageAlignment)Enum.Parse(typeof(Names.ImageAlignment), array4[0]);
							c1DImageAlign.AlignVert = (Names.ImageAlignment)Enum.Parse(typeof(Names.ImageAlignment), array4[1]);
						}
						break;
					}
					case "zoom":
						c1DImageAlign.Zoom = float.Parse(text2, CultureInfo.InvariantCulture);
						break;
					case "aspect":
						c1DImageAlign.Aspect = float.Parse(text2, CultureInfo.InvariantCulture);
						break;
					case "fit":
						c1DImageAlign.Fit = bool.Parse(text2);
						break;
					case "tile":
					{
						string[] array3 = text2.Split(s_comma);
						if (array3.Length == 1)
						{
							bool tileHorz = (c1DImageAlign.TileVert = bool.Parse(array3[0]));
							c1DImageAlign.TileHorz = tileHorz;
						}
						else if (array3.Length == 2)
						{
							c1DImageAlign.TileHorz = bool.Parse(array3[0]);
							c1DImageAlign.TileVert = bool.Parse(array3[1]);
						}
						break;
					}
					}
				}
			}
			catch (Exception)
			{
			}
			return c1DImageAlign;
		}

		public static explicit operator string(C1DImageAlign ia)
		{
			return "align:" + ((ia.AlignHorz == ia.AlignVert) ? ia.AlignHorz.ToString(CultureInfo.InvariantCulture) : (ia.AlignHorz.ToString(CultureInfo.InvariantCulture) + "," + ia.AlignVert.ToString(CultureInfo.InvariantCulture))) + ";zoom:" + ia.Zoom.ToString(CultureInfo.InvariantCulture) + ";aspect:" + ia.Aspect.ToString(CultureInfo.InvariantCulture) + ";fit:" + ia.Fit.ToString(CultureInfo.InvariantCulture) + ";tile:" + ((ia.TileHorz == ia.TileVert) ? ia.TileHorz.ToString(CultureInfo.InvariantCulture) : (ia.TileHorz.ToString(CultureInfo.InvariantCulture) + "," + ia.TileVert.ToString(CultureInfo.InvariantCulture)));
		}
	}
}
namespace C1.C1PrintDocument.Util
{
	[EditorBrowsable(EditorBrowsableState.Never)]
	public abstract class TypeConverterBase : TypeConverter
	{
		public override bool CanConvertFrom(ITypeDescriptorContext context, Type sourceType)
		{
			if ((object)sourceType != typeof(string))
			{
				return base.CanConvertFrom(context, sourceType);
			}
			return true;
		}

		public override bool CanConvertTo(ITypeDescriptorContext context, Type type)
		{
			if ((object)type != typeof(string))
			{
				return base.CanConvertTo(context, type);
			}
			return true;
		}

		protected abstract object ObjFromString(string str);

		protected abstract string StringFromObj(object o);

		public override object ConvertFrom(ITypeDescriptorContext context, CultureInfo culture, object value)
		{
			if (value is string)
			{
				return ObjFromString((string)value);
			}
			return base.ConvertFrom(context, culture, value);
		}

		public override object ConvertTo(ITypeDescriptorContext context, CultureInfo culture, object value, Type type)
		{
			if ((object)type == typeof(string))
			{
				return StringFromObj(value);
			}
			return base.ConvertTo(context, culture, value, type);
		}
	}
}
namespace C1.C1PrintDocument.DocEngine.Src
{
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	[TypeConverter(typeof(TypeConverter))]
	public struct LengthUnit
	{
		public enum Units
		{
			None,
			Em,
			Ex,
			Px,
			Percent,
			In,
			Cm,
			Mm,
			Pt,
			Pc,
			Tw,
			Doc,
			InHs
		}

		private struct ConvFactor
		{
			public Units _luFrom;

			public Units _luTo;

			public double _factor;

			public ConvFactor(Units luFrom, Units luTo, double factor)
			{
				_luFrom = luFrom;
				_luTo = luTo;
				_factor = factor;
			}
		}

		public class TypeConverter : TypeConverterBase
		{
			protected override object ObjFromString(string str)
			{
				return new LengthUnit(str);
			}

			protected override string StringFromObj(object o)
			{
				return (LengthUnit)o;
			}
		}

		public const float MmPerInch = 25.4f;

		public const float CmPerInch = 2.54f;

		private const int NFrom = 9;

		private const int NTo = 8;

		private static Hashtable s_unit2str;

		private static Hashtable s_str2unit;

		private static readonly ConvFactor[,] s_cfs;

		private static readonly Regex s_regex;

		private Units _unit;

		public Units Unit
		{
			get
			{
				return _unit;
			}
			set
			{
				_unit = value;
			}
		}

		static LengthUnit()
		{
			s_unit2str = new Hashtable(16);
			s_str2unit = new Hashtable(16);
			s_cfs = new ConvFactor[9, 8]
			{
				{
					new ConvFactor(Units.Px, Units.In, 1.0 / 96.0),
					new ConvFactor(Units.Px, Units.Cm, 0.026458332935969036),
					new ConvFactor(Units.Px, Units.Mm, 0.26458332935969037),
					new ConvFactor(Units.Px, Units.Pt, 0.75),
					new ConvFactor(Units.Px, Units.Pc, 0.0625),
					new ConvFactor(Units.Px, Units.Tw, 15.0),
					new ConvFactor(Units.Px, Units.Doc, 3.125),
					new ConvFactor(Units.Px, Units.InHs, 1.0416666666666667)
				},
				{
					new ConvFactor(Units.In, Units.Px, 96.0),
					new ConvFactor(Units.In, Units.Cm, 2.5399999618530273),
					new ConvFactor(Units.In, Units.Mm, 25.399999618530273),
					new ConvFactor(Units.In, Units.Pt, 72.0),
					new ConvFactor(Units.In, Units.Pc, 6.0),
					new ConvFactor(Units.In, Units.Tw, 1440.0),
					new ConvFactor(Units.In, Units.Doc, 300.0),
					new ConvFactor(Units.In, Units.InHs, 100.0)
				},
				{
					new ConvFactor(Units.Cm, Units.Px, 37.79527615817928),
					new ConvFactor(Units.Cm, Units.In, 0.39370079331436747),
					new ConvFactor(Units.Cm, Units.Mm, 10.0),
					new ConvFactor(Units.Cm, Units.Pt, 28.346457118634458),
					new ConvFactor(Units.Cm, Units.Pc, 2.362204759886205),
					new ConvFactor(Units.Cm, Units.Tw, 566.9291423726892),
					new ConvFactor(Units.Cm, Units.Doc, 118.11023799431024),
					new ConvFactor(Units.Cm, Units.InHs, 39.37007933143675)
				},
				{
					new ConvFactor(Units.Mm, Units.Px, 3.7795276158179276),
					new ConvFactor(Units.Mm, Units.In, 0.03937007933143675),
					new ConvFactor(Units.Mm, Units.Cm, 0.1),
					new ConvFactor(Units.Mm, Units.Pt, 2.834645711863446),
					new ConvFactor(Units.Mm, Units.Pc, 0.23622047598862048),
					new ConvFactor(Units.Mm, Units.Tw, 56.692914237268916),
					new ConvFactor(Units.Mm, Units.Doc, 11.811023799431025),
					new ConvFactor(Units.Mm, Units.InHs, 3.9370079331436747)
				},
				{
					new ConvFactor(Units.Pt, Units.Px, 1.3333333333333333),
					new ConvFactor(Units.Pt, Units.In, 1.0 / 72.0),
					new ConvFactor(Units.Pt, Units.Cm, 0.03527777724795871),
					new ConvFactor(Units.Pt, Units.Mm, 0.35277777247958714),
					new ConvFactor(Units.Pt, Units.Pc, 1.0 / 12.0),
					new ConvFactor(Units.Pt, Units.Tw, 20.0),
					new ConvFactor(Units.Pt, Units.Doc, 4.166666666666667),
					new ConvFactor(Units.Pt, Units.InHs, 1.3888888888888888)
				},
				{
					new ConvFactor(Units.Pc, Units.Px, 16.0),
					new ConvFactor(Units.Pc, Units.In, 1.0 / 6.0),
					new ConvFactor(Units.Pc, Units.Cm, 0.4233333269755046),
					new ConvFactor(Units.Pc, Units.Mm, 4.233333269755046),
					new ConvFactor(Units.Pc, Units.Pt, 12.0),
					new ConvFactor(Units.Pc, Units.Tw, 240.0),
					new ConvFactor(Units.Pc, Units.Doc, 50.0),
					new ConvFactor(Units.Pc, Units.InHs, 16.666666666666668)
				},
				{
					new ConvFactor(Units.Tw, Units.Px, 1.0 / 15.0),
					new ConvFactor(Units.Tw, Units.In, 0.0006944444444444445),
					new ConvFactor(Units.Tw, Units.Cm, 0.0017638888623979357),
					new ConvFactor(Units.Tw, Units.Mm, 0.017638888623979356),
					new ConvFactor(Units.Tw, Units.Pc, 1.0 / 240.0),
					new ConvFactor(Units.Tw, Units.Pt, 0.05),
					new ConvFactor(Units.Tw, Units.Doc, 5.0 / 24.0),
					new ConvFactor(Units.Tw, Units.InHs, 5.0 / 72.0)
				},
				{
					new ConvFactor(Units.Doc, Units.Px, 0.32),
					new ConvFactor(Units.Doc, Units.In, 1.0 / 300.0),
					new ConvFactor(Units.Doc, Units.Cm, 0.00846666653951009),
					new ConvFactor(Units.Doc, Units.Mm, 0.08466666539510091),
					new ConvFactor(Units.Doc, Units.Pt, 0.24),
					new ConvFactor(Units.Doc, Units.Pc, 0.02),
					new ConvFactor(Units.Doc, Units.Tw, 4.8),
					new ConvFactor(Units.Doc, Units.InHs, 1.0 / 3.0)
				},
				{
					new ConvFactor(Units.InHs, Units.Px, 0.96),
					new ConvFactor(Units.InHs, Units.In, 0.01),
					new ConvFactor(Units.InHs, Units.Cm, 0.025399999618530275),
					new ConvFactor(Units.InHs, Units.Mm, 0.2539999961853027),
					new ConvFactor(Units.InHs, Units.Pt, 0.72),
					new ConvFactor(Units.InHs, Units.Pc, 0.06),
					new ConvFactor(Units.InHs, Units.Tw, 14.4),
					new ConvFactor(Units.InHs, Units.Doc, 3.0)
				}
			};
			s_regex = new Regex("^((?'num'\\d*\\.?\\d*)(?'unit'em|ex|px|in|cm|mm|pt|pc|tw|doc|inhs|%)?)$", RegexOptions.IgnoreCase | RegexOptions.Compiled);
			s_unit2str.Add(Units.Em, "em");
			s_unit2str.Add(Units.Ex, "ex");
			s_unit2str.Add(Units.Px, "px");
			s_unit2str.Add(Units.Percent, "%");
			s_unit2str.Add(Units.In, "in");
			s_unit2str.Add(Units.Cm, "cm");
			s_unit2str.Add(Units.Mm, "mm");
			s_unit2str.Add(Units.Pt, "pt");
			s_unit2str.Add(Units.Pc, "pc");
			s_unit2str.Add(Units.Tw, "tw");
			s_unit2str.Add(Units.Doc, "doc");
			s_unit2str.Add(Units.InHs, "inhs");
			s_str2unit.Add("em", Units.Em);
			s_str2unit.Add("ex", Units.Ex);
			s_str2unit.Add("px", Units.Px);
			s_str2unit.Add("%", Units.Percent);
			s_str2unit.Add("in", Units.In);
			s_str2unit.Add("cm", Units.Cm);
			s_str2unit.Add("mm", Units.Mm);
			s_str2unit.Add("pt", Units.Pt);
			s_str2unit.Add("pc", Units.Pc);
			s_str2unit.Add("tw", Units.Tw);
			s_str2unit.Add("doc", Units.Doc);
			s_str2unit.Add("inhs", Units.InHs);
		}

		public static Units UnitsFromStr(string str)
		{
			object obj = s_str2unit[str.ToLower()];
			if (obj == null)
			{
				return Units.None;
			}
			return (Units)obj;
		}

		public static string UnitsToStr(Units u)
		{
			object obj = s_unit2str[u];
			if (obj == null)
			{
				return string.Empty;
			}
			return (string)obj;
		}

		public static float Convert(float val, Units luFrom, Units luTo)
		{
			if ((double)val == 0.0 || luFrom == luTo)
			{
				return val;
			}
			for (int i = 0; i < 9; i++)
			{
				if (s_cfs[i, 0]._luFrom != luFrom)
				{
					continue;
				}
				for (int j = 0; j < 8; j++)
				{
					if (s_cfs[i, j]._luTo == luTo)
					{
						return (float)((double)val * s_cfs[i, j]._factor);
					}
				}
			}
			throw new ArgumentOutOfRangeException();
		}

		public static float Convert(float val, LengthUnit from, LengthUnit to)
		{
			return Convert(val, from.Unit, to.Unit);
		}

		public static GraphicsUnit ToGraphicsUnit(Units from)
		{
			return (GraphicsUnit)(from switch
			{
				Units.In => 4, 
				Units.Mm => 6, 
				Units.Pt => 3, 
				Units.Doc => 5, 
				_ => throw new ArgumentOutOfRangeException("Unknown unit"), 
			});
		}

		public static GraphicsUnit ToGraphicsUnit(LengthUnit from)
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			return ToGraphicsUnit(from.Unit);
		}

		public static MetafileFrameUnit ToMetafileFrameUnit(Units from)
		{
			return (MetafileFrameUnit)(from switch
			{
				Units.In => 4, 
				Units.Mm => 6, 
				Units.Pt => 3, 
				Units.Doc => 5, 
				_ => throw new ArgumentOutOfRangeException("Unknown unit"), 
			});
		}

		public static MetafileFrameUnit ToMetafileFrameUnit(LengthUnit from)
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			return ToMetafileFrameUnit(from.Unit);
		}

		public static void ParseQualifiedLength(string str, out float length, out Units units)
		{
			Match match = s_regex.Match(str);
			if (match.Success)
			{
				length = float.Parse(match.Groups["num"].ToString(), CultureInfo.InvariantCulture);
				if (match.Groups["unit"].Success)
				{
					units = UnitsFromStr(match.Groups["unit"].ToString());
				}
				else
				{
					units = Units.None;
				}
			}
			else
			{
				length = 0f;
				units = Units.None;
			}
		}

		public static string MakeQualifiedLength(float length, Units units)
		{
			return length.ToString(NumberFormatInfo.InvariantInfo) + UnitsToStr(units);
		}

		public LengthUnit(Units unit)
		{
			_unit = unit;
		}

		public LengthUnit(LengthUnit lu)
		{
			_unit = lu.Unit;
		}

		public LengthUnit(string str)
		{
			_unit = UnitsFromStr(str);
		}

		public static implicit operator LengthUnit(string str)
		{
			return new LengthUnit(UnitsFromStr(str));
		}

		public static implicit operator string(LengthUnit lu)
		{
			return UnitsToStr(lu);
		}

		public static implicit operator LengthUnit(Units unit)
		{
			return new LengthUnit(unit);
		}

		public static implicit operator Units(LengthUnit lu)
		{
			return lu.Unit;
		}
	}
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	[TypeConverter(typeof(TypeConverter))]
	public struct LengthInUnits
	{
		public class TypeConverter : TypeConverterBase
		{
			protected override object ObjFromString(string str)
			{
				return new LengthInUnits(str);
			}

			protected override string StringFromObj(object o)
			{
				return (LengthInUnits)o;
			}
		}

		private float _length;

		private LengthUnit.Units _units;

		public float Length
		{
			get
			{
				return _length;
			}
			set
			{
				_length = value;
			}
		}

		public LengthUnit.Units Units
		{
			get
			{
				return _units;
			}
			set
			{
				_units = value;
			}
		}

		public LengthInUnits(float length, LengthUnit.Units units)
		{
			_length = length;
			_units = units;
		}

		public LengthInUnits(float length)
		{
			_length = length;
			_units = LengthUnit.Units.None;
		}

		public LengthInUnits(string str)
		{
			LengthUnit.ParseQualifiedLength(str, out _length, out _units);
		}

		public static implicit operator string(LengthInUnits lv)
		{
			return LengthUnit.MakeQualifiedLength(lv._length, lv._units);
		}

		public static implicit operator LengthInUnits(string str)
		{
			return new LengthInUnits(str);
		}

		public float ToLpix(LengthUnit.Units defaultUnits)
		{
			return LengthUnit.Convert(Length, (Units == LengthUnit.Units.None) ? defaultUnits : Units, LengthUnit.Units.Doc);
		}
	}
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public class XmlMisc
	{
		public const char PositionalDelimChar = ',';

		public const string PositionalDelimStr = ",";

		public const char NamedDelimChar = ';';

		public const char KeyNameDelimChar = ':';

		public static readonly char[] PositionalDelimChars = new char[1] { ',' };

		public static readonly char[] NamedKeyDelimChars = new char[2] { ';', ':' };

		public static readonly char[] NamedDelimChars = new char[1] { ';' };

		public static readonly char[] KeyNameDelimChars = new char[1] { ':' };
	}
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	[TypeConverter(typeof(TypeConverter))]
	public class Widths
	{
		public class TypeConverter : TypeConverterBase
		{
			protected override object ObjFromString(string str)
			{
				return new Widths(str);
			}

			protected override string StringFromObj(object o)
			{
				return (Widths)o;
			}
		}

		private LengthInUnits _top;

		private LengthInUnits _right;

		private LengthInUnits _bottom;

		private LengthInUnits _left;

		public LengthInUnits Top
		{
			get
			{
				return _top;
			}
			set
			{
				_top = value;
			}
		}

		public LengthInUnits Right
		{
			get
			{
				return _right;
			}
			set
			{
				_right = value;
			}
		}

		public LengthInUnits Bottom
		{
			get
			{
				return _bottom;
			}
			set
			{
				_bottom = value;
			}
		}

		public LengthInUnits Left
		{
			get
			{
				return _left;
			}
			set
			{
				_left = value;
			}
		}

		public Widths()
		{
		}

		public Widths(LengthInUnits top, LengthInUnits right, LengthInUnits bottom, LengthInUnits left)
		{
			_top = top;
			_right = right;
			_bottom = bottom;
			_left = left;
		}

		public Widths(string str)
		{
			if (str.Length != 0)
			{
				string[] array = str.Split(XmlMisc.PositionalDelimChars);
				switch (array.Length)
				{
				case 1:
					_top = (_right = (_bottom = (_left = array[0])));
					break;
				case 2:
					_top = (_bottom = array[0]);
					_right = (_left = array[1]);
					break;
				case 3:
					_top = array[0];
					_right = (_left = array[1]);
					_bottom = array[2];
					break;
				case 4:
					_top = array[0];
					_right = array[1];
					_bottom = array[2];
					_left = array[3];
					break;
				default:
					throw new ArgumentOutOfRangeException();
				case 0:
					break;
				}
			}
		}

		public static implicit operator string(Widths widths)
		{
			if (widths.Left.Equals(widths.Right))
			{
				if (widths.Top.Equals(widths.Bottom))
				{
					if (widths.Left.Equals(widths.Top))
					{
						return widths.Left;
					}
					return (string)widths.Top + ',' + (string)widths.Left;
				}
				return (string)widths.Top + ',' + (string)widths.Right + ',' + (string)widths.Bottom;
			}
			return (string)widths.Top + ',' + (string)widths.Right + ',' + (string)widths.Bottom + ',' + (string)widths.Left;
		}

		public static implicit operator Widths(string str)
		{
			return new Widths(str);
		}
	}
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	[TypeConverter(typeof(TypeConverter))]
	public class C1DColors
	{
		public class TypeConverter : TypeConverterBase
		{
			protected override object ObjFromString(string str)
			{
				return new C1DColors(str);
			}

			protected override string StringFromObj(object o)
			{
				return (C1DColors)o;
			}
		}

		private Color _top = Color.Black;

		private Color _right = Color.Black;

		private Color _bottom = Color.Black;

		private Color _left = Color.Black;

		public Color Top
		{
			get
			{
				return _top;
			}
			set
			{
				_top = value;
			}
		}

		public Color Right
		{
			get
			{
				return _right;
			}
			set
			{
				_right = value;
			}
		}

		public Color Bottom
		{
			get
			{
				return _bottom;
			}
			set
			{
				_bottom = value;
			}
		}

		public Color Left
		{
			get
			{
				return _left;
			}
			set
			{
				_left = value;
			}
		}

		public C1DColors()
		{
		}

		public C1DColors(Color top, Color right, Color bottom, Color left)
		{
			_top = top;
			_right = right;
			_bottom = bottom;
			_left = left;
		}

		public C1DColors(string str)
		{
			if (str.Length != 0)
			{
				string[] array = str.Split(XmlMisc.PositionalDelimChars);
				switch (array.Length)
				{
				case 1:
					_top = (_right = (_bottom = (_left = Color.FromName(array[0]))));
					break;
				case 2:
					_top = (_bottom = Color.FromName(array[0]));
					_right = (_left = Color.FromName(array[1]));
					break;
				case 3:
					_top = Color.FromName(array[0]);
					_right = (_left = Color.FromName(array[1]));
					_bottom = Color.FromName(array[2]);
					break;
				case 4:
					_top = Color.FromName(array[0]);
					_right = Color.FromName(array[1]);
					_bottom = Color.FromName(array[2]);
					_left = Color.FromName(array[3]);
					break;
				default:
					throw new ArgumentOutOfRangeException();
				case 0:
					break;
				}
			}
		}

		public static implicit operator C1DColors(string str)
		{
			return new C1DColors(str);
		}

		public static implicit operator C1DColors(Color color)
		{
			return new C1DColors(color.Name);
		}

		public static implicit operator string(C1DColors colors)
		{
			if (colors.Left == colors.Right)
			{
				if (colors.Top == colors.Bottom)
				{
					if (colors.Left == colors.Top)
					{
						return colors.Left.Name;
					}
					return colors.Top.Name + ',' + colors.Left.Name;
				}
				return colors.Top.Name + ',' + colors.Right.Name + ',' + colors.Bottom.Name;
			}
			return colors.Top.Name + ',' + colors.Right.Name + ',' + colors.Bottom.Name + ',' + colors.Left.Name;
		}

		public override bool Equals(object o)
		{
			if (o == null)
			{
				return false;
			}
			C1DColors c1DColors = (C1DColors)o;
			if (c1DColors.Left == Left && c1DColors.Top == Top && c1DColors.Right == Right)
			{
				return c1DColors.Bottom == Bottom;
			}
			return false;
		}
	}
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public class Names
	{
		public enum PageBreak
		{
			none,
			normal,
			extended
		}

		public enum HorzTextAlignment
		{
			left,
			center,
			right,
			justify
		}

		public enum VertTextAlignment
		{
			top,
			center,
			bottom,
			justify
		}

		public enum StackStrategy
		{
			none,
			block,
			inline
		}

		public enum StackDirection
		{
			none,
			ttb,
			btt,
			ltr,
			rtl
		}

		public enum RefSource
		{
			none,
			parent,
			prev,
			next,
			self,
			name,
			id,
			up,
			page,
			refParent,
			refOther
		}

		public enum RefDim
		{
			none,
			left,
			top,
			right,
			bottom,
			width,
			height
		}

		public enum ImageAlignment
		{
			left,
			top,
			center,
			right,
			bottom,
			stretch
		}
	}
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public class OutlineInfo
	{
		private int _level = 0;

		private string _text = null;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public int Level
		{
			get
			{
				return _level;
			}
			set
			{
				_level = value;
			}
		}

		[DefaultValue(0)]
		[EditorBrowsable(EditorBrowsableState.Never)]
		[XmlAttribute]
		public int l
		{
			get
			{
				return _level;
			}
			set
			{
				_level = value;
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public string Text
		{
			get
			{
				return _text;
			}
			set
			{
				_text = value;
			}
		}

		[XmlAttribute]
		[EditorBrowsable(EditorBrowsableState.Never)]
		[DefaultValue("")]
		public string t
		{
			get
			{
				return _text;
			}
			set
			{
				_text = value;
			}
		}

		public OutlineInfo()
		{
		}

		public OutlineInfo(int level, string text)
		{
			_level = level;
			_text = text;
		}
	}
	[TypeConverter(typeof(TypeConverter))]
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public class Stacking
	{
		public class TypeConverter : TypeConverterBase
		{
			protected override object ObjFromString(string str)
			{
				return new Stacking(str);
			}

			protected override string StringFromObj(object o)
			{
				return (Stacking)o;
			}
		}

		private Names.StackStrategy _strategy = Names.StackStrategy.block;

		private Names.StackDirection _direction = Names.StackDirection.ttb;

		public Names.StackStrategy Strategy
		{
			get
			{
				return _strategy;
			}
			set
			{
				_strategy = value;
			}
		}

		public Names.StackDirection Direction
		{
			get
			{
				return _direction;
			}
			set
			{
				_direction = value;
			}
		}

		public Stacking()
		{
		}

		public Stacking(Names.StackStrategy strategy, Names.StackDirection direction)
		{
			_strategy = strategy;
			_direction = direction;
		}

		public Stacking(string str)
		{
			if (str.Length != 0)
			{
				string[] array = str.Split(XmlMisc.PositionalDelimChars);
				if (array.Length == 0)
				{
					_strategy = Names.StackStrategy.none;
				}
				else
				{
					_strategy = (Names.StackStrategy)Enum.Parse(typeof(Names.StackStrategy), array[0]);
				}
				if (array.Length < 2)
				{
					_direction = Names.StackDirection.none;
				}
				else
				{
					_direction = (Names.StackDirection)Enum.Parse(typeof(Names.StackDirection), array[1]);
				}
			}
		}

		public override string ToString()
		{
			return this;
		}

		public static implicit operator Stacking(string str)
		{
			return new Stacking(str);
		}

		public static implicit operator string(Stacking s)
		{
			return s.Strategy.ToString() + ',' + s.Direction.ToString();
		}
	}
}
namespace C1.C1PrintDocument.DocEngine
{
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public enum DocumentStartedOpEnum
	{
		None,
		Clear,
		Render,
		Load,
		Refresh,
		Other
	}
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public class DocumentStartedArgs : EventArgs
	{
		public DocumentStartedOpEnum DocumentStartedOp = DocumentStartedOpEnum.None;

		public string DocumentName;
	}
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public delegate void DocumentStartedHandler(object sender, DocumentStartedArgs e);
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public class PageAddedArgs : EventArgs
	{
		public IPage RenderPage = null;

		public bool PageCanChangeLater = false;
	}
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public delegate void PageAddedHandler(object sender, PageAddedArgs e);
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public class PageChangedArgs : PageAddedArgs
	{
		public int PageNo = 0;

		public bool SimilarPage = false;

		public IEnumerable ChangedDrawels = null;
	}
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public delegate void PageChangedHandler(object sender, PageChangedArgs e);
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public class PageRemovedArgs
	{
		public int PageNo = 0;
	}
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public delegate void PageRemovedHandler(object sender, PageRemovedArgs e);
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public class PageInsertedArgs : PageAddedArgs
	{
		public int PageNo = 0;
	}
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public delegate void PageInsertedHandler(object sender, PageInsertedArgs e);
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public class DocumentEndedArgs : EventArgs
	{
	}
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public delegate void DocumentEndedHandler(object sender, DocumentEndedArgs e);
	public class DocEngineException : Exception
	{
	}
	public class SrcDrawelException : Exception
	{
		public readonly C1.C1PrintDocument.DocEngine.Src.IDrawel Drawel;

		public SrcDrawelException(C1.C1PrintDocument.DocEngine.Src.IDrawel drawel)
		{
			Drawel = drawel;
		}
	}
	public class CannotResolveDrawelException : SrcDrawelException
	{
		public CannotResolveDrawelException(C1.C1PrintDocument.DocEngine.Src.IDrawel drawel)
			: base(drawel)
		{
		}
	}
}
namespace C1.C1PrintDocument
{
	public enum UnitTypeEnum
	{
		Cm,
		Em,
		Ex,
		Inch,
		Mm,
		Percentage,
		Pica,
		Pixel,
		Point,
		Twip,
		Document,
		InHs
	}
}
namespace C1.C1PrintDocument.Export
{
	public interface IExporter
	{
		IExportProvider ExportProvider { get; }

		object Document { get; set; }

		string OutputFileName { get; set; }

		bool ShowOptions { get; set; }

		IOnLongOpInProgressProvider OnLongOpInProgressProvider { set; }

		string LastErrorText { get; }

		bool ShowOptionsDialog();

		void Export();
	}
	public interface IExporterHtml : IExporter
	{
	}
	public interface IExporterPdf : IExporter
	{
		bool UseCompression { get; set; }

		bool DetectNonAsciiCharsets { get; set; }

		bool EmbedTrueTypeFonts { get; set; }
	}
	public enum FormatEnum
	{
		None,
		C1D,
		PDF,
		HTML
	}
	public interface IExportProvider
	{
		string FormatName { get; }

		string DefaultExtension { get; }

		FormatEnum Format { get; }

		bool CanExportOutline { get; }

		bool CanExportSomePages { get; }

		bool CanShowOptions { get; }

		IExporter NewExporter();

		bool CanExportDocumentObject(object o);
	}
	public interface IExportProviders : IEnumerable
	{
		IExportProvider this[int i] { get; }

		IExportProvider this[string extension] { get; }

		IExportProvider this[FormatEnum fmt] { get; }
	}
}
namespace C1.C1PrintDocument.Util
{
	[TypeConverter(typeof(TypeConverter))]
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	public sealed class C1DPageSettings
	{
		public class TypeConverter : TypeConverterBase
		{
			private static char[] s_delims = new char[2] { ';', ':' };

			private static char[] s_comma = new char[1] { ',' };

			protected override object ObjFromString(string str)
			{
				//IL_0000: Unknown result type (might be due to invalid IL or missing references)
				//IL_0006: Expected O, but got Unknown
				//IL_0171: Unknown result type (might be due to invalid IL or missing references)
				//IL_017b: Expected O, but got Unknown
				try
				{
					PageSettings val = new PageSettings();
					string[] array = str.Split(s_delims);
					string text = string.Empty;
					string[] array2 = array;
					foreach (string text2 in array2)
					{
						if (text.Length == 0)
						{
							text = text2;
							continue;
						}
						if (text2.Length == 0)
						{
							return null;
						}
						string text3 = text;
						text = string.Empty;
						switch (text3)
						{
						case "color":
							val.Color = bool.Parse(text2);
							break;
						case "landscape":
							val.Landscape = bool.Parse(text2);
							break;
						case "margins":
						{
							string[] array4 = text2.Split(s_comma);
							if (array4.Length == 4)
							{
								try
								{
									int left = int.Parse(array4[0]);
									int top = int.Parse(array4[1]);
									int right = int.Parse(array4[2]);
									int bottom = int.Parse(array4[3]);
									val.Margins.Left = left;
									val.Margins.Top = top;
									val.Margins.Right = right;
									val.Margins.Bottom = bottom;
								}
								catch (Exception)
								{
								}
							}
							break;
						}
						case "papersize":
						{
							string[] array3 = text2.Split(s_comma);
							if (array3.Length == 3)
							{
								try
								{
									int num = int.Parse(array3[0]);
									int num2 = int.Parse(array3[1]);
									UnicodeEncoding unicodeEncoding = new UnicodeEncoding();
									string text4 = unicodeEncoding.GetString(Convert.FromBase64String(array3[2]));
									val.PaperSize = new PaperSize(text4, num, num2);
								}
								catch
								{
								}
							}
							break;
						}
						}
					}
					return new C1DPageSettings(val);
				}
				catch
				{
					return null;
				}
			}

			protected override string StringFromObj(object o)
			{
				try
				{
					UnicodeEncoding unicodeEncoding = new UnicodeEncoding();
					PageSettings pageSettings = ((C1DPageSettings)o).PageSettings;
					return "color:" + pageSettings.Color.ToString() + ";landscape:" + pageSettings.Landscape.ToString() + ";margins:" + pageSettings.Margins.Left + "," + pageSettings.Margins.Top + "," + pageSettings.Margins.Right + "," + pageSettings.Margins.Bottom + ";papersize:" + pageSettings.PaperSize.Width + "," + pageSettings.PaperSize.Height + "," + Convert.ToBase64String(unicodeEncoding.GetBytes(pageSettings.PaperSize.PaperName));
				}
				catch
				{
					return null;
				}
			}
		}

		private PageSettings _pageSettings;

		public PageSettings PageSettings => _pageSettings;

		public C1DPageSettings()
		{
		}

		public C1DPageSettings(PageSettings ps)
		{
			_pageSettings = ps;
		}
	}
	public class OutlineEntry
	{
		public int Level;

		public string Text;

		public int PageNo;

		public RectangleF PageArea;

		public OutlineEntry()
			: this(0, string.Empty, 0, RectangleF.Empty)
		{
		}

		public OutlineEntry(int level, string text, int pageNo)
			: this(level, text, pageNo, RectangleF.Empty)
		{
		}

		public OutlineEntry(int level, string text, int pageNo, RectangleF pageArea)
		{
			Level = level;
			Text = text;
			PageNo = pageNo;
			PageArea = pageArea;
		}
	}
	public class StrConv
	{
		public static object ValueFromString(Type type, string value)
		{
			if (value != null)
			{
				return TypeDescriptor.GetConverter(type).ConvertFromString(null, CultureInfo.InvariantCulture, value);
			}
			return null;
		}
	}
}
namespace C1.C1PrintDocument
{
	public interface IC1DocEngine
	{
		string Name { get; set; }

		string DisplayName { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		IDrawelRoot SourceTree { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		IRoot RenderTree { get; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		bool Busy { get; set; }

		string DefaultFileExtension { get; }

		string DefaultFileDescription { get; }

		event EventHandler BusyChanged;

		event DocumentStartedHandler DocumentStarted;

		event PageAddedHandler PageAdded;

		event PageChangedHandler PageChanged;

		event PageRemovedHandler PageRemoved;

		event PageInsertedHandler PageInserted;

		event DocumentEndedHandler DocumentEnded;

		event LongOpInProgressHandler LongOpInProgress;

		void CheckNotBusy(bool turnOn);

		void Clear();

		void RefreshViewer();

		void Render();

		void RenderBegin();

		void RenderNext();

		void RenderEnd();

		void SetSourceTreeIsFresh();

		bool Save(string path);

		bool Save(Stream stream);

		bool Load(string path);

		bool Load(Stream stream);

		void OnLongOpInProgress(out bool cancel);

		void OnLongOpInProgress();
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	public interface IC1PrintDocument
	{
		PageSettings PageSettings { get; set; }

		string DocumentName { get; set; }

		bool IsGenerating { get; }

		IC1DocEngine DocEngine { get; }

		bool GenerateDocumentHandled { get; }

		IPageHeader get_PageHeader();

		IPageFooter get_PageFooter();

		void Generate(PageSettings ps);

		void Generate();

		void StartDoc();

		void EndDoc();

		void KillDoc();

		void NewColumn();

		void NewPage();

		void NewPageConfigure();

		IMeasureInfo RenderDirectText_I(object X, object Y, string text, object width, Font font, Color textColor, AlignHorzEnum horzAlign);

		IMeasureInfo RenderDirectImage_I(object X, object Y, Image image, object width, object height, IImageAlignDef imageAlign);

		IMeasureInfo RenderDirectLine(object fromX, object fromY, object toX, object toY, ILineDef line);
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	public interface IDocumentElementBase
	{
		double Height { get; set; }
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	public interface IDocumentElementWithRO : IDocumentElementBase
	{
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	public interface IRunningTitle : IDocumentElementWithRO, IDocumentElementBase
	{
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	public interface IPageHeader : IRunningTitle, IDocumentElementWithRO, IDocumentElementBase
	{
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	public interface IPageFooter : IRunningTitle, IDocumentElementWithRO, IDocumentElementBase
	{
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	public interface IMeasureInfo
	{
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	public interface IImageAlignDef
	{
	}
	[EditorBrowsable(EditorBrowsableState.Never)]
	public interface ILineDef
	{
	}
	public enum HtmlTOCLinksLocationEnum
	{
		TopPage,
		LeftFrame,
		RightFrame,
		TopFrame,
		BottomFrame
	}
	public enum HtmlTOCTypeEnum
	{
		None,
		Outline,
		PageLinks
	}
	public enum AlignHorzEnum
	{
		Left,
		Right,
		Center,
		Justify
	}
	public enum AlignVertEnum
	{
		Top,
		Bottom,
		Center,
		Justify
	}
	public enum ImageAlignHorzEnum
	{
		Left,
		Right,
		Center
	}
	public enum ImageAlignVertEnum
	{
		Top,
		Bottom,
		Center
	}
	public enum SideEnum
	{
		Left,
		Top,
		Right,
		Bottom
	}
	public enum AlignInParentHorzEnum
	{
		Default,
		Left,
		Right,
		Center,
		Justify
	}
	public enum AlignInParentVertEnum
	{
		Default,
		Top,
		Bottom,
		Center,
		Justify
	}
	public interface IPrintHelper
	{
		bool ShrinkOversizedPages { get; set; }

		bool ExpandSmallPages { get; set; }

		bool AutoRotatePages { get; set; }

		PrintPageRange PageRange { get; set; }

		PageSettings DefaultPageSettings { get; set; }

		PrinterSettings PrinterSettings { get; set; }

		string DocumentName { get; set; }

		bool ShowProgressDialog { get; set; }

		PrintDocument PrintDocument { get; }

		int CurrPageNo { get; }

		void Print();
	}
	public class PrintHelperBase
	{
		public delegate Image GetPageImage(int pageIdx, out bool disposable);

		public delegate int GetMaxPageNo();

		public delegate string GetDocumentName();
	}
	public class PrintPageRange
	{
		public const int Dash = int.MinValue;

		private C1Stack _pages = null;

		private int _maxPage = 0;

		public int MaxPage
		{
			get
			{
				return _maxPage;
			}
			set
			{
				_maxPage = value;
			}
		}

		public int MinPage
		{
			get
			{
				if (_pages == null)
				{
					return 0;
				}
				int num = 0;
				foreach (object page in _pages)
				{
					int num2 = (int)page;
					if (num2 != int.MinValue)
					{
						num = Math.Min(num, num2);
					}
				}
				return num;
			}
		}

		public PrintPageRange(int maxPage)
		{
			_maxPage = maxPage;
		}

		public PrintPageRange(string range)
		{
			_pages = new C1Stack();
			string[] array = range.Split(',', ' ');
			string[] array2 = array;
			foreach (string text in array2)
			{
				if (text.Length == 0)
				{
					continue;
				}
				string[] array3 = text.Split(new char[1] { '-' }, 2);
				if (array3.Length == 2)
				{
					_pages.Push(int.Parse(array3[0], CultureInfo.InvariantCulture));
					_pages.Push(int.MinValue);
					_pages.Push(int.Parse(array3[1], CultureInfo.InvariantCulture));
				}
				else if (array3.Length == 1)
				{
					if (text[0] == '-')
					{
						_pages.Push(int.MinValue);
					}
					_pages.Push(int.Parse(array3[0], CultureInfo.InvariantCulture));
					if (text[text.Length - 1] == '-')
					{
						_pages.Push(int.MinValue);
					}
				}
				else
				{
					_pages.Push(int.Parse(text, CultureInfo.InvariantCulture));
				}
			}
			foreach (object page in _pages)
			{
				int val = (int)page;
				_maxPage = Math.Max(_maxPage, val);
			}
		}

		public PrintPageRange(int from, int to)
		{
			_pages = new C1Stack();
			_pages.Push(from);
			_pages.Push(int.MinValue);
			_pages.Push(to);
			_maxPage = to;
		}

		public PrintPageRange(IEnumerable pages)
		{
			_pages = new C1Stack();
			foreach (object page in pages)
			{
				int num = (int)page;
				_pages.Push(num);
				_maxPage = Math.Max(_maxPage, num);
			}
		}

		public PrintPageRange(PrinterSettings ps)
		{
			//IL_0026: Unknown result type (might be due to invalid IL or missing references)
			//IL_002c: Invalid comparison between Unknown and I4
			//IL_007d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0083: Invalid comparison between Unknown and I4
			if (ps == null)
			{
				return;
			}
			_pages = new C1Stack();
			if ((int)ps.PrintRange == 2)
			{
				_pages.Push(ps.FromPage);
				_pages.Push(int.MinValue);
				_pages.Push(ps.ToPage);
				_maxPage = ps.ToPage;
				return;
			}
			if ((int)ps.PrintRange == 1)
			{
				throw new ArgumentOutOfRangeException("rintPageRange can not be initialized from a PrinterSettings with a selection range");
			}
			_pages.Push(ps.MinimumPage);
			_pages.Push(int.MinValue);
			_pages.Push(ps.MaximumPage);
			_maxPage = ps.MaximumPage;
		}

		public bool IsPageInRange(int pageNo)
		{
			if (_pages == null)
			{
				return true;
			}
			bool flag = false;
			int num = 0;
			for (int i = 0; i < _pages.Length; i++)
			{
				int num2 = (int)_pages[i];
				if (num2 == pageNo)
				{
					return true;
				}
				if (num2 == int.MinValue)
				{
					if (i + 1 == _pages.Length && pageNo >= num)
					{
						return true;
					}
					flag = true;
				}
				else if (flag)
				{
					if (pageNo >= num && pageNo <= num2)
					{
						return true;
					}
					flag = false;
				}
				else
				{
					num = num2;
				}
			}
			return false;
		}
	}
	public interface ICommonAgent
	{
		IExportProviders AvailableExportProviders { get; }

		IC1DocEngine NewC1DocEngine();

		IC1PrintDocument NewC1PrintDocument();

		[EditorBrowsable(EditorBrowsableState.Never)]
		IC1PrintDocument NewC1PrintDocument(string info);

		C1.C1PrintDocument.DocEngine.Src.IDrawel NewDrawel(Type drawelIfaceType);

		IPrintHelper NewPrintHelper(IC1PrintDocument c1PrintDoc);

		IPrintHelper NewPrintHelper(IC1DocEngine c1DocEngine);

		IPrintHelper NewPrintHelper(PrintHelperBase.GetPageImage getPageImage, PrintHelperBase.GetMaxPageNo getMaxPageNo, PrintHelperBase.GetDocumentName getDocumentName);

		PaperSize GetCurrentLocaleDefaultPaperSize();

		PaperSize GetDefaultPaperSize();

		StringFormat GetStringFormat(bool wordWrap, Names.HorzTextAlignment hAlign, Names.VertTextAlignment vAlign);

		IImageAlignDef NewImageAlignDef(ImageAlignHorzEnum alignHor, ImageAlignVertEnum alignVert, bool stretchHor, bool stretchVert, bool keepAspectRatio, bool tileHor, bool tileVert);

		ILineDef NewLineDef(Color color, double widthPt);
	}
	public class PrintAsmbProxy
	{
		private static Assembly s_pdocAsmb;

		private static ICommonAgent s_agent;

		public static bool Loaded => s_agent != null;

		public static IExportProviders AvailableExportProviders => s_agent.AvailableExportProviders;

		static PrintAsmbProxy()
		{
			s_pdocAsmb = null;
			s_agent = null;
			try
			{
				try
				{
					s_pdocAsmb = Assembly.Load("C1.C1PrintDocument");
				}
				catch
				{
					s_pdocAsmb = null;
				}
				if ((object)s_pdocAsmb == null)
				{
					s_pdocAsmb = Assembly.LoadWithPartialName("C1.C1PrintDocument");
				}
				if ((object)s_pdocAsmb == null)
				{
					throw new Exception("Could not load C1.C1PrintDocument");
				}
				Type type = s_pdocAsmb.GetType("C1.C1PrintDocument.CommonAgent", throwOnError: true, ignoreCase: false);
				s_agent = Activator.CreateInstance(type) as ICommonAgent;
			}
			catch
			{
				s_pdocAsmb = null;
				s_agent = null;
			}
		}

		public static IC1DocEngine NewC1DocEngine()
		{
			if (s_agent != null)
			{
				return s_agent.NewC1DocEngine();
			}
			return null;
		}

		public static IC1PrintDocument NewC1PrintDocument()
		{
			if (s_agent != null)
			{
				return s_agent.NewC1PrintDocument();
			}
			return null;
		}

		public static IC1PrintDocument NewC1PrintDocument(string info)
		{
			if (s_agent != null)
			{
				return s_agent.NewC1PrintDocument(info);
			}
			return null;
		}

		public static C1.C1PrintDocument.DocEngine.Src.IDrawel NewDrawel(Type drawelIfaceType)
		{
			return s_agent.NewDrawel(drawelIfaceType);
		}

		public static IPrintHelper NewPrintHelper(IC1PrintDocument c1PrintDoc)
		{
			return s_agent.NewPrintHelper(c1PrintDoc);
		}

		public static IPrintHelper NewPrintHelper(IC1DocEngine c1DocEngine)
		{
			return s_agent.NewPrintHelper(c1DocEngine);
		}

		public static IPrintHelper NewPrintHelper(PrintHelperBase.GetPageImage getPageImage, PrintHelperBase.GetMaxPageNo getMaxPageNo, PrintHelperBase.GetDocumentName getDocumentName)
		{
			return s_agent.NewPrintHelper(getPageImage, getMaxPageNo, getDocumentName);
		}

		public static PaperSize GetCurrentLocaleDefaultPaperSize()
		{
			return s_agent.GetCurrentLocaleDefaultPaperSize();
		}

		public static PaperSize GetDefaultPaperSize()
		{
			return s_agent.GetDefaultPaperSize();
		}

		public static StringFormat GetStringFormat(bool wordWrap, Names.HorzTextAlignment hAlign, Names.VertTextAlignment vAlign)
		{
			return s_agent.GetStringFormat(wordWrap, hAlign, vAlign);
		}

		public static IImageAlignDef NewImageAlignDef(ImageAlignHorzEnum alignHor, ImageAlignVertEnum alignVert, bool stretchHor, bool stretchVert, bool keepAspectRatio, bool tileHor, bool tileVert)
		{
			return s_agent.NewImageAlignDef(alignHor, alignVert, stretchHor, stretchVert, keepAspectRatio, tileHor, tileVert);
		}

		public static ILineDef NewLineDef(Color color, double widthPt)
		{
			return s_agent.NewLineDef(color, widthPt);
		}
	}
}
namespace C1.Win.C1PrintPreview
{
	public interface IC1PrintPreview
	{
		Control C1PrintPreview { get; }

		Panel C1PreviewPane { get; }

		TabControl C1PreviewNavigationBar { get; }

		ToolBar C1PreviewToolBar { get; }

		Control C1PreviewStatusBar { get; }

		Splitter SplitterControl { get; }

		IC1DocEngine C1DocEngine { get; set; }

		PageSettings PageSettings { get; set; }

		float ZoomFactor { get; set; }
	}
	public interface ICommonAgent
	{
		IC1PrintPreview NewC1PrintPreview();

		[EditorBrowsable(EditorBrowsableState.Never)]
		IC1PrintPreview NewC1PrintPreview(string info);
	}
	public class PreviewAsmbProxy
	{
		private static Assembly s_pviewAsmb;

		private static ICommonAgent s_agent;

		static PreviewAsmbProxy()
		{
			s_pviewAsmb = null;
			s_agent = null;
			try
			{
				s_pviewAsmb = Assembly.Load("C1.Win.C1PrintPreview");
			}
			catch
			{
				s_pviewAsmb = null;
			}
			if ((object)s_pviewAsmb == null)
			{
				s_pviewAsmb = Assembly.LoadWithPartialName("C1.Win.C1PrintPreview");
			}
			if ((object)s_pviewAsmb == null)
			{
				throw new Exception("PreviewAsmbProxy initialization failure: C1.Win.C1PrintPreview could not be loaded");
			}
			Type type = s_pviewAsmb.GetType("C1.Win.C1PrintPreview.CommonAgent", throwOnError: true, ignoreCase: false);
			s_agent = Activator.CreateInstance(type) as ICommonAgent;
		}

		public static IC1PrintPreview NewC1PrintPreview()
		{
			if (s_agent != null)
			{
				return s_agent.NewC1PrintPreview();
			}
			return null;
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		public static IC1PrintPreview NewC1PrintPreview(string info)
		{
			if (s_agent != null)
			{
				return s_agent.NewC1PrintPreview(info);
			}
			return null;
		}
	}
}
namespace C1.Win.GridEditors
{
	public interface IC1GridEditor
	{
		event EventHandler ValueChanged;

		void AttachEditor(Type dataType);

		EditorButtonsFlags GetVisibleButtons();

		bool ShowEditor(Rectangle rect, object value, InitSelectionEnum initSelection, EditorProperties editorProperties);

		bool IsInputKey(Keys keyData);

		void OnKeyDown(Keys keyData);

		void OnKeyUp(Keys keyData);

		bool IsInputChar(char keyChar);

		void OnKeyPress(char keyChar);

		void OnMouseDown(MouseButtons button, Point p);

		void OnMouseUp(MouseButtons button, Point p);

		void OnMouseDoubleClick(MouseButtons button, Point p);

		void UpdatePosition(Rectangle rect);

		bool HideEditor();

		Keys GetLastKey();

		object GetValue();

		string GetLastError();
	}
	[Flags]
	public enum EditorButtonsFlags
	{
		None = 0,
		UpDown = 1,
		DropDown = 2,
		PopUp = 4,
		Custom = 0xFFFF
	}
	public enum InitSelectionEnum
	{
		SelectAll,
		AtStart,
		AtEnd
	}
	public class EditorProperties
	{
		public Color BackColor;

		public Color ForeColor;

		public Font Font;

		public bool WordWrap;

		public Cursor Cursor;

		public Margins Margins;

		public HorizontalAlignEnum HorizontalAlign;

		public VerticalAlignEnum VerticalAlign;

		public StringTrimming Trimming;

		public TextEffectEnum TextEffect;

		public Image BackgroundImage;

		public BackgroundImageAlignEnum BackgroundImageAlign;

		public Image ForegroundImage;

		public ForegroundImageAlignEnum ForegroundImageAlign;

		public int ForegroundImageSpacing;

		public ImeMode ImeMode;

		public RightToLeft RightToLeft;

		public BorderStyleEnum BorderStyle;

		public bool ReadOnly;

		public int MaxLength;

		public object DefaultValue;

		public string EditMask;

		public bool EditMaskUpdate;

		public string Format;

		public string ComboList;

		public object Tag;
	}
	public enum HorizontalAlignEnum
	{
		General,
		Left,
		Center,
		Right,
		Justify
	}
	public enum VerticalAlignEnum
	{
		Top,
		Middle,
		Bottom
	}
	public enum TextEffectEnum
	{
		Flat,
		Raised,
		Inset
	}
	public enum BackgroundImageAlignEnum
	{
		TopLeft,
		TopCenter,
		TopRight,
		MiddleLeft,
		MiddleCenter,
		MiddleRight,
		BottomLeft,
		BottomCenter,
		BottomRight,
		Scale,
		Stretch,
		Tile,
		Hide
	}
	public enum ForegroundImageAlignEnum
	{
		LeftOfText,
		RightOfText,
		TopOfText,
		BottomOfText,
		ImageOnly,
		TextOnly
	}
	public enum BorderStyleEnum
	{
		None,
		FixedSingle,
		Fixed3D,
		Light3D
	}
}
namespace C1.Util
{
	public class C1Stack : ArrayList
	{
		public object Top => Peek();

		public int Length => Count;

		public bool IsEmpty => Count == 0;

		public void Push(object o)
		{
			Add(o);
		}

		public object Pop()
		{
			int index = Count - 1;
			object result = this[index];
			RemoveAt(index);
			return result;
		}

		public object Peek()
		{
			int num = Count - 1;
			if (num >= 0)
			{
				return this[num];
			}
			return null;
		}

		public bool IsIndexInBounds(int idx)
		{
			if (idx >= 0)
			{
				return idx < Count;
			}
			return false;
		}
	}
	public sealed class DbErrors
	{
		private static readonly string c1DataRowTypeName = "C1.Data.C1DataRow";

		public static bool SetFieldError(object row, string fieldName, string errorText)
		{
			if (row == null)
			{
				return false;
			}
			if (row is DataRowView)
			{
				((DataRowView)row).Row.SetColumnError(fieldName, errorText);
				return true;
			}
			Type type = row.GetType().Assembly.GetType(c1DataRowTypeName);
			if ((object)type != null)
			{
				MethodInfo method = type.GetMethod("FromDataItem", new Type[1] { typeof(object) });
				if ((object)method != null)
				{
					object obj = method.Invoke(null, new object[1] { row });
					if (obj != null)
					{
						method = obj.GetType().GetMethod("SetFieldError", new Type[2]
						{
							typeof(string),
							typeof(string)
						});
						method.Invoke(obj, new object[2] { fieldName, errorText });
						return true;
					}
				}
			}
			return false;
		}

		public static bool SetFieldError(object row, int fieldIndex, string errorText)
		{
			if (row == null)
			{
				return false;
			}
			if (row is DataRowView)
			{
				((DataRowView)row).Row.SetColumnError(fieldIndex, errorText);
				return true;
			}
			Type type = row.GetType().Assembly.GetType(c1DataRowTypeName);
			if ((object)type != null)
			{
				MethodInfo method = type.GetMethod("FromDataItem", new Type[1] { typeof(object) });
				if ((object)method != null)
				{
					object obj = method.Invoke(null, new object[1] { row });
					if (obj != null)
					{
						method = obj.GetType().GetMethod("SetFieldError", new Type[2]
						{
							typeof(int),
							typeof(string)
						});
						method.Invoke(obj, new object[2] { fieldIndex, errorText });
						return true;
					}
				}
			}
			return false;
		}

		public static bool SetRowError(object row, string errorText)
		{
			if (row == null)
			{
				return false;
			}
			if (row is DataRowView)
			{
				((DataRowView)row).Row.RowError = errorText;
				return true;
			}
			Type type = row.GetType().Assembly.GetType(c1DataRowTypeName);
			if ((object)type != null)
			{
				MethodInfo method = type.GetMethod("FromDataItem", new Type[1] { typeof(object) });
				if ((object)method != null)
				{
					object obj = method.Invoke(null, new object[1] { row });
					if (obj != null)
					{
						PropertyInfo property = obj.GetType().GetProperty("RowError");
						property.SetValue(obj, errorText, new object[0]);
						return true;
					}
				}
			}
			return false;
		}
	}
	public interface IOnLongOpInProgressProvider
	{
		void OnLongOpInProgress(out bool cancel);

		void OnLongOpInProgress();
	}
	public class LongOpInProgressArgs : EventArgs
	{
		public bool CancelIfPossible = false;
	}
	public delegate void LongOpInProgressHandler(object sender, LongOpInProgressArgs e);
	public delegate void NodeProc(ITreeNode tn, object param);
	public class Pair
	{
		private object _first = null;

		private object _second = null;

		public object First
		{
			get
			{
				return _first;
			}
			set
			{
				_first = value;
			}
		}

		public object Second
		{
			get
			{
				return _second;
			}
			set
			{
				_second = value;
			}
		}

		public Pair()
		{
			_first = null;
			_second = null;
		}

		public Pair(object first, object second)
		{
			_first = first;
			_second = second;
		}
	}
}
namespace C1.Common
{
	public interface IDesignTimeServices
	{
		object CreateInstance(string typename);
	}
	public interface IThemeSourceProvider
	{
		object GetTheme();

		object GetThemeSource();

		void ApplyTheme(object theme);
	}
}
namespace C1.Util
{
	internal class UIString
	{
		public int Ordinal = 0;

		public string Value = string.Empty;

		public string DefaultValue = string.Empty;

		public string Description = string.Empty;

		public bool IsDefault => Value == DefaultValue;

		public UIString(int ordinal, string value, string description)
		{
			Ordinal = ordinal;
			Value = (DefaultValue = value);
			Description = description;
		}

		public void Reset()
		{
			Value = DefaultValue;
		}
	}
	internal class UisSorter : IComparable
	{
		public object Key;

		public string StrKey;

		public UIString Uis;

		public UisSorter(object key, string strKey, UIString uis)
		{
			Key = key;
			StrKey = strKey;
			Uis = uis;
		}

		public int CompareTo(object obj)
		{
			if (!(obj is UisSorter uisSorter))
			{
				return 1;
			}
			if (Uis.Ordinal < uisSorter.Uis.Ordinal)
			{
				return -1;
			}
			if (Uis.Ordinal > uisSorter.Uis.Ordinal)
			{
				return 1;
			}
			return string.Compare(StrKey, uisSorter.StrKey, ignoreCase: false, CultureInfo.InvariantCulture);
		}
	}
	public delegate void UIStringsItemEventHandler(object sender, UIStringsItemEventArgs e);
	public class UIStringsItemEventArgs : EventArgs
	{
		private object _key;

		private string _value;

		private bool _isDefault;

		private string _description;

		[Description("The key of the item being added or changed.")]
		public object Key => _key;

		[Description("The new string value.")]
		public string Value => _value;

		[Description("True if the value is equal to the default string.")]
		public bool IsDefault => _isDefault;

		[Description("The description provided for the item.")]
		public string Description => _description;

		internal UIStringsItemEventArgs(object key, string value, bool isDefault, string description)
		{
			_key = key;
			_value = value;
			_isDefault = isDefault;
			_description = description;
		}
	}
	[TypeConverter(typeof(TypeConverter))]
	public class UIStrings
	{
		public class TypeConverter : System.ComponentModel.TypeConverter
		{
			protected class StringPropertyDescriptor : SimplePropertyDescriptor
			{
				private string _name;

				private ITypeDescriptorContext _context;

				public override bool IsReadOnly => false;

				public override bool DesignTimeOnly => false;

				public StringPropertyDescriptor(string name, Attribute[] attributes, ITypeDescriptorContext context)
					: base(typeof(UIStrings), name, typeof(string), attributes)
				{
					_name = name;
					_context = context;
				}

				public override bool CanResetValue(object component)
				{
					return ShouldSerializeValue(component);
				}

				public override void ResetValue(object component)
				{
					if (_context == null || _context.OnComponentChanging())
					{
						((UIStrings)component).Reset(_name);
						if (_context != null)
						{
							_context.OnComponentChanged();
						}
					}
				}

				public override object GetValue(object component)
				{
					UIStrings uIStrings = component as UIStrings;
					return uIStrings[uIStrings.ConvertFromStr(_name)];
				}

				public override void SetValue(object component, object value)
				{
					if (_context == null || _context.OnComponentChanging())
					{
						UIStrings uIStrings = component as UIStrings;
						uIStrings[uIStrings.ConvertFromStr(_name)] = (string)value;
						if (_context != null)
						{
							_context.OnComponentChanged();
						}
					}
				}

				public override bool ShouldSerializeValue(object component)
				{
					UIStrings uIStrings = component as UIStrings;
					return !uIStrings.IsDefault(uIStrings.ConvertFromStr(_name));
				}
			}

			public override object ConvertTo(ITypeDescriptorContext context, CultureInfo culture, object value, Type type)
			{
				if ((object)type == typeof(string))
				{
					return ((UIStrings)value).Description;
				}
				return base.ConvertTo(context, culture, value, type);
			}

			public override PropertyDescriptorCollection GetProperties(ITypeDescriptorContext context, object value, Attribute[] attrFilter)
			{
				UIStrings uIStrings = (UIStrings)value;
				int count = uIStrings.Count;
				PropertyDescriptor[] array;
				string[] array2;
				int num;
				checked
				{
					array = new PropertyDescriptor[(uint)count];
					array2 = new string[(uint)count];
					num = 0;
				}
				foreach (UisSorter item in uIStrings.Sorter)
				{
					Attribute[] attributes = new Attribute[3]
					{
						new DescriptionAttribute(item.Uis.Description),
						new DefaultValueAttribute(item.Uis.DefaultValue),
						new RefreshPropertiesAttribute(RefreshProperties.Repaint)
					};
					array[num] = new StringPropertyDescriptor(item.StrKey, attributes, context);
					array2[num++] = item.StrKey;
				}
				return new PropertyDescriptorCollection(array).Sort(array2);
			}

			public override bool GetPropertiesSupported(ITypeDescriptorContext context)
			{
				return true;
			}
		}

		private const string c_keyValueFmt = "{0}:{1}";

		private const char c_delim = ':';

		private const char c_escape = '`';

		private Hashtable _items = new Hashtable();

		private string _description = "(UIStrings)";

		private Type _indexer = null;

		private UIStringsItemEventHandler _onItemAdded;

		private UIStringsItemEventHandler _onItemChanged;

		private EventHandler _onCollectionChanged;

		private ArrayList _sorter = new ArrayList();

		private bool _bunchUpdate = false;

		private bool _modified = false;

		[Description("Gets or sets the string value for the specified key.")]
		public string this[object key]
		{
			get
			{
				return ((UIString)_items[ValidateKey(key)]).Value;
			}
			set
			{
				key = ValidateKey(key);
				UIString uIString = (UIString)_items[key];
				if (uIString.Value != value)
				{
					uIString.Value = value;
					OnItemChanged(new UIStringsItemEventArgs(key, value, uIString.IsDefault, uIString.Description));
					if (!_bunchUpdate)
					{
						OnCollectionChanged(EventArgs.Empty);
					}
					else
					{
						_modified = true;
					}
				}
			}
		}

		[Browsable(false)]
		[Localizable(true)]
		[Description("Used for serialization of strings.")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Visible)]
		public string[] Content
		{
			get
			{
				return SaveToStringArray();
			}
			set
			{
				RestoreFromStringArray(value);
			}
		}

		[Description("This text is shown in Properties window in the IDE.")]
		[Browsable(false)]
		[EditorBrowsable(EditorBrowsableState.Never)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public string Description
		{
			get
			{
				return _description;
			}
			set
			{
				_description = value;
			}
		}

		[Description("Returns the number of elements contained in the collection.")]
		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public int Count => _items.Count;

		[EditorBrowsable(EditorBrowsableState.Never)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[Browsable(false)]
		public Hashtable Items => _items;

		[Browsable(false)]
		[EditorBrowsable(EditorBrowsableState.Never)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public ArrayList Sorter => _sorter;

		[Browsable(false)]
		[Description("Occurs when a new item added to the collection.")]
		public event UIStringsItemEventHandler ItemAdded
		{
			add
			{
				_onItemAdded = (UIStringsItemEventHandler)Delegate.Combine(_onItemAdded, value);
			}
			remove
			{
				_onItemAdded = (UIStringsItemEventHandler)Delegate.Remove(_onItemAdded, value);
			}
		}

		[Browsable(false)]
		[Description("Occurs when an item changed in the collection.")]
		public event UIStringsItemEventHandler ItemChanged
		{
			add
			{
				_onItemChanged = (UIStringsItemEventHandler)Delegate.Combine(_onItemChanged, value);
			}
			remove
			{
				_onItemChanged = (UIStringsItemEventHandler)Delegate.Remove(_onItemChanged, value);
			}
		}

		[Browsable(false)]
		[Description("Occurs when the collection has been changed.")]
		public event EventHandler CollectionChanged
		{
			add
			{
				_onCollectionChanged = (EventHandler)Delegate.Combine(_onCollectionChanged, value);
			}
			remove
			{
				_onCollectionChanged = (EventHandler)Delegate.Remove(_onCollectionChanged, value);
			}
		}

		[Description("Adds a string to the collection, specifying the ordinal.")]
		public void Add(object key, int ordinal, string value, string description)
		{
			if ((object)_indexer == null)
			{
				_indexer = key.GetType();
			}
			else if (!_indexer.Equals(key.GetType()))
			{
				throw new ArgumentException("Invalid key type: " + key.GetType().ToString());
			}
			string text = ConvertToStr(key);
			if (text == string.Empty)
			{
				throw new ArgumentException("key", "Key must not be empty.");
			}
			UIString uIString = new UIString(ordinal, value, description);
			_items.Add(key, uIString);
			UisSorter uisSorter = new UisSorter(key, text, uIString);
			_sorter.Insert(BinarySearch(uisSorter), uisSorter);
			OnItemAdded(new UIStringsItemEventArgs(key, value, isDefault: true, description));
			if (!_bunchUpdate)
			{
				OnCollectionChanged(EventArgs.Empty);
			}
			else
			{
				_modified = true;
			}
		}

		[Description("Adds a string to the collection in alphabetical order.")]
		public void Add(object key, string value, string description)
		{
			Add(key, 0, value, description);
		}

		[Description("Adds a string to the collection, preserving the order.")]
		public void AddInOrder(object key, string value, string description)
		{
			Add(key, _items.Count, value, description);
		}

		[Description("Sets all strings in collection to their default values.")]
		public void Reset()
		{
			bool bunchUpdate = _bunchUpdate;
			_bunchUpdate = true;
			try
			{
				IDictionaryEnumerator enumerator = _items.GetEnumerator();
				while (enumerator.MoveNext())
				{
					DictionaryEntry dictionaryEntry = (DictionaryEntry)enumerator.Current;
					UIString uIString = (UIString)dictionaryEntry.Value;
					if (!uIString.IsDefault)
					{
						uIString.Reset();
						OnItemChanged(new UIStringsItemEventArgs(dictionaryEntry.Key, uIString.Value, isDefault: true, uIString.Description));
						_modified = true;
					}
				}
			}
			finally
			{
				_bunchUpdate = bunchUpdate;
			}
			if (!_bunchUpdate && _modified)
			{
				_modified = false;
				OnCollectionChanged(EventArgs.Empty);
			}
		}

		[Description("Returns true if there is any non-default string in the collection.")]
		public bool ShouldSerialize()
		{
			IDictionaryEnumerator enumerator = _items.GetEnumerator();
			while (enumerator.MoveNext())
			{
				DictionaryEntry dictionaryEntry = (DictionaryEntry)enumerator.Current;
				if (!((UIString)dictionaryEntry.Value).IsDefault)
				{
					return true;
				}
			}
			return false;
		}

		[Description("Returns true if the string is equal to its default value.")]
		public bool IsDefault(object key)
		{
			return ((UIString)_items[ValidateKey(key)]).IsDefault;
		}

		[Description("Returns the item description.")]
		public string GetDescription(object key)
		{
			return ((UIString)_items[ValidateKey(key)]).Description;
		}

		[Description("Sets the string to its default value.")]
		public void Reset(object key)
		{
			key = ValidateKey(key);
			UIString uIString = (UIString)_items[key];
			if (!uIString.IsDefault)
			{
				uIString.Reset();
				OnItemChanged(new UIStringsItemEventArgs(key, uIString.Value, isDefault: true, uIString.Description));
				if (!_bunchUpdate)
				{
					OnCollectionChanged(EventArgs.Empty);
				}
				else
				{
					_modified = true;
				}
			}
		}

		private string Escape(string key)
		{
			if (key.IndexOf(':') == -1)
			{
				return key;
			}
			StringBuilder stringBuilder = new StringBuilder(key.Length + 3);
			foreach (char c in key)
			{
				if (c == ':' || c == '`')
				{
					stringBuilder.Append('`');
				}
				stringBuilder.Append(c);
			}
			return stringBuilder.ToString();
		}

		private string Unescape(string key)
		{
			if (key.IndexOf(':') == -1)
			{
				return key;
			}
			StringBuilder stringBuilder = new StringBuilder(key.Length);
			for (int i = 0; i < key.Length; i++)
			{
				char c = key[i];
				if (c == '`')
				{
					i++;
					if (i == key.Length)
					{
						throw new ArgumentException($"Key has invalid format: \"{key}\".");
					}
					c = key[i];
				}
				stringBuilder.Append(c);
			}
			return stringBuilder.ToString();
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		public object ConvertFromStr(string key)
		{
			return TypeDescriptor.GetConverter(_indexer).ConvertFromInvariantString(key);
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		public string ConvertToStr(object key)
		{
			return TypeDescriptor.GetConverter(_indexer).ConvertToInvariantString(key);
		}

		private string[] SaveToStringArray()
		{
			ArrayList arrayList = new ArrayList(Count);
			IDictionaryEnumerator enumerator = _items.GetEnumerator();
			while (enumerator.MoveNext())
			{
				DictionaryEntry dictionaryEntry = (DictionaryEntry)enumerator.Current;
				UIString uIString = (UIString)dictionaryEntry.Value;
				if (!uIString.IsDefault)
				{
					arrayList.Add($"{Escape(ConvertToStr(dictionaryEntry.Key))}:{uIString.Value}");
				}
			}
			return (string[])arrayList.ToArray(typeof(string));
		}

		private void RestoreFromStringArray(string[] items)
		{
			if (items == null)
			{
				Reset();
				return;
			}
			bool bunchUpdate = _bunchUpdate;
			_bunchUpdate = true;
			try
			{
				Reset();
				foreach (string text in items)
				{
					int num = 0;
					do
					{
						int startIndex = num + 1;
						num = text.IndexOf(':', startIndex);
						if (num == -1)
						{
							throw new ArgumentException("Invalid format of saved UIStrings.");
						}
					}
					while (text[num - 1] == '`');
					this[ConvertFromStr(Unescape(text.Substring(0, num)))] = text.Substring(num + 1);
				}
			}
			finally
			{
				_bunchUpdate = bunchUpdate;
			}
			if (!_bunchUpdate && _modified)
			{
				_modified = false;
				OnCollectionChanged(EventArgs.Empty);
			}
		}

		private object ValidateKey(object key)
		{
			if (key is string && (object)_indexer != typeof(string))
			{
				key = ConvertFromStr((string)key);
			}
			if (!_items.ContainsKey(key))
			{
				throw new ArgumentException("Key not found: " + key.ToString());
			}
			return key;
		}

		[Description("Returns the key of an item with the specified index.")]
		public object GetKeyAt(int index)
		{
			return ((UisSorter)_sorter[index]).Key;
		}

		[Description("Gets the string by its index.")]
		public string GetValueAt(int index)
		{
			return ((UisSorter)_sorter[index]).Uis.Value;
		}

		[Description("Sets the string by its index.")]
		public void SetValueAt(int index, string value)
		{
			UisSorter uisSorter = (UisSorter)_sorter[index];
			UIString uis = uisSorter.Uis;
			if (uis.Value != value)
			{
				uis.Value = value;
				OnItemChanged(new UIStringsItemEventArgs(uisSorter.Key, value, uis.IsDefault, uis.Description));
				if (!_bunchUpdate)
				{
					OnCollectionChanged(EventArgs.Empty);
				}
				else
				{
					_modified = true;
				}
			}
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		public string[] SaveValuesToStringArray()
		{
			string[] array = new string[checked((uint)_sorter.Count)];
			for (int i = 0; i < _sorter.Count; i++)
			{
				array[i] = ((UisSorter)_sorter[i]).Uis.Value;
			}
			return array;
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		public void RestoreValuesFromStringArray(string[] values)
		{
			if (values == null)
			{
				Reset();
				return;
			}
			if (values.Length > _items.Count)
			{
				throw new ArgumentException("values", "Values array contains too many items.");
			}
			bool bunchUpdate = _bunchUpdate;
			_bunchUpdate = true;
			try
			{
				Reset();
				for (int i = 0; i < values.Length; i++)
				{
					UisSorter uisSorter = (UisSorter)_sorter[i];
					UIString uis = uisSorter.Uis;
					if (uis.Value != values[i])
					{
						uis.Value = values[i];
						OnItemChanged(new UIStringsItemEventArgs(uisSorter.Key, uis.Value, uis.IsDefault, uis.Description));
						_modified = true;
					}
				}
			}
			finally
			{
				_bunchUpdate = bunchUpdate;
			}
			if (!_bunchUpdate && _modified)
			{
				_modified = false;
				OnCollectionChanged(EventArgs.Empty);
			}
		}

		private int BinarySearch(UisSorter item)
		{
			int num = 0;
			int num2 = _sorter.Count - 1;
			while (num <= num2)
			{
				int num3 = num + num2 >> 1;
				int num4 = item.CompareTo(_sorter[num3]);
				if (num4 > 0)
				{
					num = num3 + 1;
				}
				else
				{
					num2 = num3 - 1;
				}
			}
			return num;
		}

		protected virtual void OnItemAdded(UIStringsItemEventArgs e)
		{
			if (_onItemAdded != null)
			{
				_onItemAdded(this, e);
			}
		}

		protected virtual void OnItemChanged(UIStringsItemEventArgs e)
		{
			if (_onItemChanged != null)
			{
				_onItemChanged(this, e);
			}
		}

		protected virtual void OnCollectionChanged(EventArgs e)
		{
			if (_onCollectionChanged != null)
			{
				_onCollectionChanged(this, e);
			}
		}
	}
}
namespace C1.Win.Misc
{
	[ToolboxItem(false)]
	public class HighlightingToolBar : ToolBar
	{
		private IContainer components;

		private ImageList _imageListHi;

		private bool _trackMouse = false;

		private ToolBarButton _highlightedButton = null;

		private bool _captured = false;

		public ImageList ImageListHi
		{
			get
			{
				return _imageListHi;
			}
			set
			{
				if (_imageListHi != value)
				{
					EventHandler eventHandler = ImageListHiRecreateHandle;
					if (_imageListHi != null)
					{
						_imageListHi.RecreateHandle -= eventHandler;
					}
					_imageListHi = value;
					if (value != null)
					{
						value.RecreateHandle += eventHandler;
					}
					if (((Control)this).IsHandleCreated)
					{
						((Control)this).RecreateHandle();
					}
				}
			}
		}

		public HighlightingToolBar()
		{
			InitializeComponent();
		}

		private void InitializeComponent()
		{
			components = new Container();
		}

		private void ImageListHiRecreateHandle(object sender, EventArgs e)
		{
			if (((Control)this).IsHandleCreated)
			{
				((Control)this).RecreateHandle();
			}
		}

		private void Unhighlight()
		{
			if (_highlightedButton != null)
			{
				SwapImages(_highlightedButton.ImageIndex);
				((Control)this).Invalidate(_highlightedButton.Rectangle);
				_highlightedButton = null;
			}
		}

		private void SwapImages(int idx)
		{
			Image val = ((ToolBar)this).ImageList.Images[idx];
			((ToolBar)this).ImageList.Images[idx] = _imageListHi.Images[idx];
			_imageListHi.Images[idx] = val;
		}

		protected override void OnMouseMove(MouseEventArgs e)
		{
			//IL_0056: Unknown result type (might be due to invalid IL or missing references)
			//IL_005c: Expected O, but got Unknown
			if (_trackMouse && !_captured && (_highlightedButton == null || !_highlightedButton.Rectangle.Contains(e.X, e.Y)))
			{
				foreach (ToolBarButton button in ((ToolBar)this).Buttons)
				{
					ToolBarButton val = button;
					if (val.Rectangle.Contains(e.X, e.Y))
					{
						Unhighlight();
						if (val.Enabled && val.ImageIndex >= 0)
						{
							_highlightedButton = val;
							SwapImages(val.ImageIndex);
							((Control)this).Invalidate(val.Rectangle);
						}
						break;
					}
				}
			}
			((ToolBar)this).OnMouseMove(e);
		}

		protected override void OnMouseEnter(EventArgs e)
		{
			if (_imageListHi != null && ((Control)((Control)this).FindForm()).ContainsFocus)
			{
				_trackMouse = true;
			}
			((ToolBar)this).OnMouseEnter(e);
		}

		protected override void OnMouseLeave(EventArgs e)
		{
			_trackMouse = false;
			((ToolBar)this).OnMouseLeave(e);
			Unhighlight();
		}

		protected override void OnMouseDown(MouseEventArgs e)
		{
			((ToolBar)this).OnMouseDown(e);
			_captured = true;
		}

		protected override void OnMouseUp(MouseEventArgs e)
		{
			((ToolBar)this).OnMouseUp(e);
			_captured = false;
			if (_highlightedButton != null && !_highlightedButton.Enabled)
			{
				Unhighlight();
			}
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		public void DoRecreateHandle()
		{
			if (((Control)this).IsHandleCreated)
			{
				((Control)this).RecreateHandle();
			}
		}
	}
}
namespace C1.Util
{
	public class FindTypeByName
	{
		public static Type Find(string typeName)
		{
			Type type = Type.GetType(typeName, throwOnError: false);
			if ((object)type != null)
			{
				return type;
			}
			Assembly[] assemblies = Thread.GetDomain().GetAssemblies();
			for (int i = 0; i < assemblies.Length; i++)
			{
				type = assemblies[i].GetType(typeName, throwOnError: false);
				if ((object)type != null)
				{
					return type;
				}
			}
			Assembly executingAssembly = Assembly.GetExecutingAssembly();
			if ((object)executingAssembly == null)
			{
				return null;
			}
			return FindInReferencedAssemblies(typeName, executingAssembly);
		}

		private static Type FindInReferencedAssemblies(string typeName, Assembly parent)
		{
			AssemblyName[] referencedAssemblies = parent.GetReferencedAssemblies();
			Assembly[] assemblies = Thread.GetDomain().GetAssemblies();
			ArrayList arrayList = new ArrayList();
			Assembly assembly = null;
			Type type = null;
			for (int i = 0; i < referencedAssemblies.Length; i++)
			{
				string fullName = referencedAssemblies[i].FullName;
				bool flag = false;
				for (int j = 0; j < assemblies.Length; j++)
				{
					if (fullName == assemblies[j].FullName)
					{
						flag = true;
						break;
					}
				}
				if (!flag)
				{
					assembly = Assembly.Load(referencedAssemblies[i]);
					arrayList.Add(assembly);
					type = assembly.GetType(typeName, throwOnError: false);
					if ((object)type != null)
					{
						return type;
					}
				}
			}
			for (int i = 0; i < arrayList.Count; i++)
			{
				type = FindInReferencedAssemblies(typeName, (Assembly)arrayList[i]);
				if ((object)type != null)
				{
					return type;
				}
			}
			return null;
		}
	}
}
namespace C1.Util.Win.Design
{
	public abstract class DropDownFormClassNameEditor : UITypeEditor
	{
		private IWindowsFormsEditorService _edSvc = null;

		private ListBox _box;

		private Type _projectItemType;

		private Type _projectItemsType;

		private Type _projectType;

		private Type _projectsType;

		private Type _dteType;

		private Type _solutionType;

		private Type _fileCodeModelType;

		private Type _codeElementType;

		private Type _codeElementsType;

		private Type _codeNamespaceType;

		private Type _codeClassType;

		private object _namespaceEC;

		private object _classEC;

		private object _publicEC;

		private string _vbProjectC;

		private string _csProjectC;

		private MethodInfo _get_ContainingProject;

		private MethodInfo _get_ProjectKind;

		private MethodInfo _get_DTE;

		private MethodInfo _get_Solution;

		private MethodInfo _get_Projects;

		private MethodInfo _projectsEM;

		private MethodInfo _get_ProjectItems;

		private MethodInfo _projectItemsEM;

		private MethodInfo _get_Name;

		private MethodInfo _get_FileCodeModel;

		private MethodInfo _get_ProjectSubItems;

		private MethodInfo _get_CodeElements;

		private MethodInfo _codeElementsEM;

		private MethodInfo _get_Kind;

		private MethodInfo _get_Members;

		private MethodInfo _isDerivedMethod;

		private MethodInfo _get_IsAbstract;

		private MethodInfo _get_Access;

		private MethodInfo _get_FullName;

		private MethodInfo _projectItemsTemplatePath;

		private MethodInfo _addFromTemplate;

		private bool _initialized = false;

		private object _project;

		private object _solution;

		private IDesignerHost _dh;

		protected abstract string BaseFormClassName { get; }

		protected virtual string NoneString => "(none)";

		protected virtual bool IncludeNoneInList => true;

		protected virtual bool IncludeBaseFormClassInList => false;

		public override UITypeEditorEditStyle GetEditStyle(ITypeDescriptorContext context)
		{
			//IL_001a: Unknown result type (might be due to invalid IL or missing references)
			if (context == null || context.Instance == null || context.Instance is object[])
			{
				return ((UITypeEditor)this).GetEditStyle(context);
			}
			return (UITypeEditorEditStyle)3;
		}

		public override object EditValue(ITypeDescriptorContext context, IServiceProvider provider, object value)
		{
			//IL_002d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0037: Expected O, but got Unknown
			//IL_0042: Unknown result type (might be due to invalid IL or missing references)
			//IL_004c: Expected O, but got Unknown
			if (context == null || provider == null)
			{
				return value;
			}
			object instance = context.Instance;
			if (instance == null || instance is object[])
			{
				return value;
			}
			_edSvc = (IWindowsFormsEditorService)provider.GetService(typeof(IWindowsFormsEditorService));
			if (_edSvc == null)
			{
				return value;
			}
			_box = new ListBox();
			_box.Click += OnListBox_Click;
			_box.BorderStyle = (BorderStyle)0;
			if (IncludeNoneInList)
			{
				_box.Items.Add((object)NoneString);
			}
			FillListBox(instance);
			if (IncludeBaseFormClassInList && !_box.Items.Contains((object)BaseFormClassName))
			{
				_box.Items.Insert(IncludeNoneInList ? 1 : 0, (object)BaseFormClassName);
			}
			int num = ((value != null) ? _box.Items.IndexOf(value) : (-1));
			if (num != -1)
			{
				((ListControl)_box).SelectedIndex = num;
			}
			_edSvc.DropDownControl((Control)(object)_box);
			switch (((ListControl)_box).SelectedIndex)
			{
			case 0:
				value = "";
				break;
			default:
				value = _box.SelectedItem;
				break;
			case -1:
				break;
			}
			return value;
		}

		private void InitializeFields()
		{
			Assembly[] assemblies = Thread.GetDomain().GetAssemblies();
			Assembly assembly = null;
			Assembly assembly2 = null;
			for (int i = 0; i < assemblies.Length; i++)
			{
				string name = assemblies[i].GetName().Name;
				if (string.Compare(name, "EnvDTE", ignoreCase: true) == 0)
				{
					assembly = assemblies[i];
				}
				else if (string.Compare(name, "VSLangProj", ignoreCase: true) == 0)
				{
					assembly2 = assemblies[i];
				}
			}
			if ((object)assembly == null || (object)assembly2 == null)
			{
				return;
			}
			Type enumType = null;
			Type enumType2 = null;
			Type[] types = assembly.GetTypes();
			for (int j = 0; j < types.Length; j++)
			{
				switch (types[j].Name)
				{
				case "ProjectItem":
					_projectItemType = types[j];
					break;
				case "ProjectItems":
					_projectItemsType = types[j];
					break;
				case "Project":
					_projectType = types[j];
					break;
				case "Projects":
					_projectsType = types[j];
					break;
				case "_DTE":
					_dteType = types[j];
					break;
				case "_Solution":
					_solutionType = types[j];
					break;
				case "FileCodeModel":
					_fileCodeModelType = types[j];
					break;
				case "CodeElement":
					_codeElementType = types[j];
					break;
				case "CodeElements":
					_codeElementsType = types[j];
					break;
				case "vsCMElement":
					enumType = types[j];
					break;
				case "CodeNamespace":
					_codeNamespaceType = types[j];
					break;
				case "CodeClass":
					_codeClassType = types[j];
					break;
				case "vsCMAccess":
					enumType2 = types[j];
					break;
				}
			}
			_namespaceEC = Enum.Parse(enumType, "vsCMElementNamespace", ignoreCase: false);
			_classEC = Enum.Parse(enumType, "vsCMElementClass", ignoreCase: false);
			_publicEC = Enum.Parse(enumType2, "vsCMAccessPublic", ignoreCase: false);
			Type type = null;
			types = assembly2.GetTypes();
			for (int k = 0; k < types.Length; k++)
			{
				if (types[k].Name == "PrjKind")
				{
					type = types[k];
					break;
				}
			}
			_vbProjectC = (string)type.GetField("prjKindVBProject").GetValue(null);
			_csProjectC = (string)type.GetField("prjKindCSharpProject").GetValue(null);
			_get_ContainingProject = _projectItemType.GetMethod("get_ContainingProject");
			_get_ProjectKind = _projectType.GetMethod("get_Kind");
			_get_DTE = _projectType.GetMethod("get_DTE");
			_get_Solution = _dteType.GetMethod("get_Solution");
			_get_Projects = _solutionType.GetMethod("get_Projects");
			_projectsEM = _projectsType.GetMethod("GetEnumerator");
			_get_ProjectItems = _projectType.GetMethod("get_ProjectItems");
			_projectItemsEM = _projectItemsType.GetMethod("GetEnumerator");
			_get_Name = _projectItemType.GetMethod("get_Name");
			_get_FileCodeModel = _projectItemType.GetMethod("get_FileCodeModel");
			_get_ProjectSubItems = _projectItemType.GetMethod("get_ProjectItems");
			_get_CodeElements = _fileCodeModelType.GetMethod("get_CodeElements");
			_codeElementsEM = _codeElementsType.GetMethod("GetEnumerator");
			_get_Kind = _codeElementType.GetMethod("get_Kind");
			_get_Members = _codeNamespaceType.GetMethod("get_Members");
			_isDerivedMethod = _codeClassType.GetMethod("get_IsDerivedFrom");
			_get_IsAbstract = _codeClassType.GetMethod("get_IsAbstract");
			_get_Access = _codeClassType.GetMethod("get_Access");
			_get_FullName = _codeClassType.GetMethod("get_FullName");
			_projectItemsTemplatePath = _solutionType.GetMethod("ProjectItemsTemplatePath");
			_addFromTemplate = _projectItemsType.GetMethod("AddFromTemplate");
			_initialized = true;
		}

		private void FillListBox(object instance)
		{
			ISite site = ((Component)instance).Site;
			if (site == null)
			{
				return;
			}
			if (!_initialized)
			{
				InitializeFields();
			}
			_dh = site.GetService(typeof(IDesignerHost)) as IDesignerHost;
			if (!_initialized || _dh == null)
			{
				return;
			}
			object service = _dh.GetService(_projectItemType);
			if (service == null)
			{
				return;
			}
			_project = _get_ContainingProject.Invoke(service, null);
			_solution = _get_Solution.Invoke(_get_DTE.Invoke(_project, null), null);
			object obj = _get_Projects.Invoke(_solution, null);
			IEnumerator enumerator = (IEnumerator)_projectsEM.Invoke(obj, null);
			while (enumerator.MoveNext())
			{
				object current = enumerator.Current;
				try
				{
					IEnumerator enumerator2 = (IEnumerator)_projectItemsEM.Invoke(_get_ProjectItems.Invoke(current, null), null);
					while (enumerator2.MoveNext())
					{
						RetrieveFormsFromProjectItem(current, enumerator2.Current);
					}
				}
				catch
				{
				}
			}
		}

		private void RetrieveFormsFromProjectItem(object p, object projectItem)
		{
			object obj = _get_FileCodeModel.Invoke(projectItem, null);
			if (obj != null)
			{
				IEnumerator enumerator = (IEnumerator)_codeElementsEM.Invoke(_get_CodeElements.Invoke(obj, null), null);
				while (enumerator.MoveNext())
				{
					object current = enumerator.Current;
					object obj2 = _get_Kind.Invoke(current, null);
					if (_namespaceEC.Equals(obj2))
					{
						IEnumerator enumerator2 = (IEnumerator)_codeElementsEM.Invoke(_get_Members.Invoke(current, null), null);
						while (enumerator2.MoveNext())
						{
							if (_classEC.Equals(_get_Kind.Invoke(enumerator2.Current, null)))
							{
								AddFormInList(enumerator2.Current, p);
							}
						}
					}
					else if (_classEC.Equals(obj2))
					{
						AddFormInList(current, p);
					}
				}
				return;
			}
			object obj3 = _get_ProjectSubItems.Invoke(projectItem, null);
			if (obj3 != null)
			{
				IEnumerator enumerator3 = (IEnumerator)_projectItemsEM.Invoke(obj3, null);
				while (enumerator3.MoveNext())
				{
					RetrieveFormsFromProjectItem(p, enumerator3.Current);
				}
			}
		}

		private void AddFormInList(object ce, object p)
		{
			if ((bool)_isDerivedMethod.Invoke(ce, new object[1] { BaseFormClassName }) && !(bool)_get_IsAbstract.Invoke(ce, null) && (p == _project || _publicEC.Equals(_get_Access.Invoke(ce, null))))
			{
				_box.Items.Add(_get_FullName.Invoke(ce, null));
			}
		}

		private void OnListBox_Click(object sender, EventArgs e)
		{
			if (_edSvc != null)
			{
				_edSvc.CloseDropDown();
			}
		}
	}
}
