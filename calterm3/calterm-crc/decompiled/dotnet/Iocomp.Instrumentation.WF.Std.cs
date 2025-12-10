using System;
using System.CodeDom;
using System.Collections;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.ComponentModel.Design.Serialization;
using System.Drawing;
using System.Drawing.Design;
using System.Drawing.Drawing2D;
using System.Drawing.Text;
using System.Globalization;
using System.Reflection;
using System.Security.Cryptography;
using System.Text;
using System.Windows.Forms;
using System.Windows.Forms.Design;
using Iocomp.Classes;
using Iocomp.Delegates;
using Iocomp.Design;
using Iocomp.Design.Plugin.EditorControls;
using Iocomp.Instrumentation.Standard;
using Iocomp.Interfaces;
using Iocomp.Licensing;
using Iocomp.Types;
using ToolboxBitmaps;

[assembly: AssemblyKeyFile("c:\\signing\\Iocomp.snk")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTrademark("Iocomp and the Iocomp Logo are registered trademarks of Iocomp Software Inc.")]
[assembly: AssemblyCopyright("Copyright 1998-2007 Iocomp Software Inc., All Rights Reserved.")]
[assembly: AssemblyProduct("Iocomp Components")]
[assembly: AssemblyCompany("Iocomp Software Inc.")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyDescription("Iocomp Instrumentation Pack Std Components")]
[assembly: AssemblyTitle("Iocomp Instrumentation Pack Std Components")]
[assembly: AssemblyKeyName("")]
[assembly: AssemblyVersion("3.0.6.15715")]
namespace Iocomp.Design
{
	public class LoadBeginEndSerializerComboBoxBase : CodeDomSerializer
	{
		public override object Deserialize(IDesignerSerializationManager manager, object codeDomObject)
		{
			//IL_001f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0025: Expected O, but got Unknown
			CodeDomSerializer val = (CodeDomSerializer)manager.GetSerializer(typeof(ComboBoxBase).BaseType, typeof(CodeDomSerializer));
			return val.Deserialize(manager, codeDomObject);
		}

		public override object Serialize(IDesignerSerializationManager manager, object value)
		{
			//IL_001f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0026: Expected O, but got Unknown
			//IL_0049: Unknown result type (might be due to invalid IL or missing references)
			//IL_004f: Expected O, but got Unknown
			//IL_005b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0061: Expected O, but got Unknown
			//IL_0092: Unknown result type (might be due to invalid IL or missing references)
			//IL_009c: Expected O, but got Unknown
			//IL_00a8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ae: Expected O, but got Unknown
			CodeDomSerializer val = (CodeDomSerializer)manager.GetSerializer(typeof(ComboBoxBase).BaseType, typeof(CodeDomSerializer));
			object obj = val.Serialize(manager, value);
			CodeExpression val2 = ((CodeDomSerializer)this).SerializeToReferenceExpression(manager, value);
			if (val2 == null)
			{
				return obj;
			}
			if (!(obj is CodeStatementCollection))
			{
				return obj;
			}
			CodeStatementCollection val3 = (CodeStatementCollection)obj;
			CodeMethodInvokeExpression val4 = new CodeMethodInvokeExpression(val2, "LoadingBegin", (CodeExpression[])(object)new CodeExpression[0]);
			int num = 0;
			for (int i = 0; i < ((System.Collections.CollectionBase)(object)val3).Count; i++)
			{
				if (val3[i] is CodeCommentStatement)
				{
					num = i + 1;
				}
			}
			val3.Insert(num, (CodeStatement)new CodeExpressionStatement((CodeExpression)(object)val4));
			val4 = new CodeMethodInvokeExpression(val2, "LoadingEnd", (CodeExpression[])(object)new CodeExpression[0]);
			val3.Add((CodeExpression)(object)val4);
			return obj;
		}
	}
}
namespace Iocomp.Classes
{
	[Description("Iocomp's ancestor class for all edit controls.")]
	[DesignerCategory("code")]
	[ToolboxItem(false)]
	[Editor(typeof(UITypeEditorGeneric), typeof(UITypeEditor))]
	[DesignerSerializer(typeof(LoadBeginEndSerializerComboBoxBase), typeof(CodeDomSerializer))]
	public abstract class ComboBoxBase : ComboBox, IControlBase, IComponentBase, IAmbientOwner, IPropertyDefaults, ISupportUITypeEditor
	{
		protected License m_License;

		private bool m_Loading;

		private bool m_Creating;

		private bool m_SettingDefaults;

		private bool m_UserGenerated;

		private SubClassBaseCollection m_SubClassList;

		private bool m_DefaultReadBack;

		Font IAmbientOwner.Font => Font;

		Color IAmbientOwner.ForeColor => ForeColor;

		Color IAmbientOwner.BackColor => BackColor;

		Color IAmbientOwner.Color => Color.Empty;

		Color IAmbientOwner.CustomColor1 => Color.Empty;

		Color IAmbientOwner.CustomColor2 => Color.Empty;

		Color IAmbientOwner.CustomColor3 => Color.Empty;

		bool IPropertyDefaults.DefaultReadBack
		{
			get
			{
				return DefaultReadBack;
			}
			set
			{
				DefaultReadBack = value;
			}
		}

		bool IControlBase.FreezeAutoSize
		{
			get
			{
				return false;
			}
			set
			{
			}
		}

		Control IControlBase.Control => (Control)(object)this;

		Control IControlBase._Parent => ((Control)this).Parent;

		protected override Size DefaultSize => GetDefaultSize();

		[RefreshProperties(RefreshProperties.All)]
		public Size Size
		{
			get
			{
				return ((ComboBox)this).Size;
			}
			set
			{
				((ComboBox)this).Size = value;
			}
		}

		[RefreshProperties(RefreshProperties.All)]
		public Font Font
		{
			get
			{
				return ((ComboBox)this).Font;
			}
			set
			{
				if (!GPFunctions.Equals(((ComboBox)this).Font, value))
				{
					((ComboBox)this).Font = value;
					DoPropertyChange(this, "Font");
				}
			}
		}

		public Color ForeColor
		{
			get
			{
				return ((ComboBox)this).ForeColor;
			}
			set
			{
				if (((ComboBox)this).ForeColor != value)
				{
					((ComboBox)this).ForeColor = value;
				}
			}
		}

		public Color BackColor
		{
			get
			{
				return ((ComboBox)this).BackColor;
			}
			set
			{
				if (((ComboBox)this).BackColor != value)
				{
					((ComboBox)this).BackColor = value;
				}
			}
		}

		private bool DefaultReadBack
		{
			get
			{
				return m_DefaultReadBack;
			}
			set
			{
				if (m_SubClassList == null)
				{
					return;
				}
				foreach (IPropertyDefaults subClass in m_SubClassList)
				{
					subClass.DefaultReadBack = value;
				}
			}
		}

		[Browsable(false)]
		public EventSource EventSource
		{
			get
			{
				if (m_UserGenerated)
				{
					return EventSource.User;
				}
				return EventSource.Code;
			}
		}

		[Browsable(false)]
		public bool Loading => m_Loading;

		[Browsable(false)]
		public bool Creating => m_Creating;

		[Browsable(false)]
		public bool SettingDefaults => m_SettingDefaults;

		[Browsable(false)]
		public bool Designing => ((Component)this).DesignMode;

		[Browsable(false)]
		public bool UserGenerated => m_UserGenerated;

		PlugInStandard ISupportUITypeEditor.GetPlugIn()
		{
			return GetPlugIn();
		}

		string ISupportUITypeEditor.GetPlugInTitle()
		{
			return GetPlugInTitle();
		}

		void IComponentBase.ForceDesignerChange()
		{
			ForceDesignerChange();
		}

		void IComponentBase.SetComponentDefaults()
		{
		}

		void IControlBase.DoAutoSize()
		{
			DoAutoSize();
		}

		void IControlBase.DoAutoSizeSpecialOffset(int specialOffset)
		{
			DoAutoSizeSpecialOffset(specialOffset);
		}

		void IComponentBase.DoPropertyChange(object sender, string propertyName)
		{
			DoPropertyChange(sender, propertyName);
		}

		protected void DoCreate()
		{
			m_Creating = true;
			m_DefaultReadBack = false;
			try
			{
				CreateObjects();
			}
			finally
			{
				m_Creating = false;
			}
			m_SettingDefaults = true;
			try
			{
				SetDefaults();
			}
			finally
			{
				m_SettingDefaults = false;
			}
		}

		protected virtual Size GetDefaultSize()
		{
			return new Size(50, 50);
		}

		protected override void Dispose(bool disposing)
		{
			if (m_License != null)
			{
				m_License.Dispose();
				m_License = null;
			}
			((ComboBox)this).Dispose(disposing);
		}

		protected virtual PlugInStandard GetPlugIn()
		{
			return null;
		}

		protected virtual string GetPlugInTitle()
		{
			return Const.EmptyString;
		}

		private void ResetSize()
		{
			Size = ((Control)this).DefaultSize;
		}

		protected void AddSubClass(ISubClassBase value)
		{
			if (m_SubClassList == null)
			{
				m_SubClassList = new SubClassBaseCollection();
			}
			m_SubClassList.Add(value);
			value.ControlBase = this;
			value.ComponentBase = this;
			value.AmbientOwner = this;
		}

		protected void DoPropertyChange(object sender, string propertyName)
		{
			if (!Creating && !SettingDefaults)
			{
				PropertyChangedHook(sender, propertyName);
			}
		}

		protected virtual void PropertyChangedHook(object sender, string propertyName)
		{
		}

		protected void DoAutoSize()
		{
		}

		protected void DoAutoSizeSpecialOffset(int specialOffset)
		{
		}

		protected void ForceDesignerChange()
		{
			((IComponentChangeService)((Component)(object)this).GetService(typeof(IComponentChangeService)))?.OnComponentChanged(this, null, null, null);
		}

		protected virtual void CreateObjects()
		{
		}

		protected virtual void Loaded()
		{
		}

		protected virtual void SetDefaults()
		{
		}

		public void LoadingBegin()
		{
			m_Loading = true;
		}

		public void LoadingEnd()
		{
			m_Loading = false;
			Loaded();
		}

		protected virtual void InternalOnKeyDown(KeyEventArgs e)
		{
		}

		protected virtual void InternalOnKeyUp(KeyEventArgs e)
		{
		}

		protected virtual void InternalOnKeyPress(KeyPressEventArgs e)
		{
		}

		protected virtual void InternalOnSelectionChangeCommitted(EventArgs e)
		{
		}

		protected virtual void InternalOnSelectedIndexChanged(EventArgs e)
		{
		}

		protected override void OnKeyDown(KeyEventArgs e)
		{
			((ComboBox)this).OnKeyDown(e);
			try
			{
				m_UserGenerated = true;
				InternalOnKeyDown(e);
			}
			finally
			{
				m_UserGenerated = false;
			}
		}

		protected override void OnKeyUp(KeyEventArgs e)
		{
			((ComboBox)this).OnKeyUp(e);
			try
			{
				m_UserGenerated = true;
				InternalOnKeyUp(e);
			}
			finally
			{
				m_UserGenerated = false;
			}
		}

		protected override void OnKeyPress(KeyPressEventArgs e)
		{
			((ComboBox)this).OnKeyPress(e);
			try
			{
				m_UserGenerated = true;
				InternalOnKeyPress(e);
			}
			finally
			{
				m_UserGenerated = false;
			}
		}

		protected override void OnSelectionChangeCommitted(EventArgs e)
		{
			try
			{
				m_UserGenerated = true;
				((ComboBox)this).OnSelectionChangeCommitted(e);
				InternalOnSelectionChangeCommitted(e);
			}
			finally
			{
				m_UserGenerated = false;
			}
		}

		protected override void OnSelectedIndexChanged(EventArgs e)
		{
			((ComboBox)this).OnSelectedIndexChanged(e);
			InternalOnSelectedIndexChanged(e);
		}

		public void ShowEditorCustom(bool designTimeStyle, bool modal)
		{
			((UITypeEditorGeneric)TypeDescriptor.GetEditor(this, typeof(UITypeEditor)))?.EditValue(this, designTimeStyle, modal);
		}

		virtual bool IControlBase.Focus()
		{
			return ((Control)this).Focus();
		}
	}
}
namespace Iocomp.Design
{
	public class DisplayDoubleDesigner : ControlDesigner
	{
		public override SelectionRules SelectionRules
		{
			get
			{
				//IL_0015: Unknown result type (might be due to invalid IL or missing references)
				//IL_0024: Unknown result type (might be due to invalid IL or missing references)
				//IL_002b: Unknown result type (might be due to invalid IL or missing references)
				//IL_002e: Unknown result type (might be due to invalid IL or missing references)
				//IL_003a: Unknown result type (might be due to invalid IL or missing references)
				//IL_0041: Unknown result type (might be due to invalid IL or missing references)
				//IL_0044: Unknown result type (might be due to invalid IL or missing references)
				//IL_005d: Unknown result type (might be due to invalid IL or missing references)
				//IL_0064: Unknown result type (might be due to invalid IL or missing references)
				//IL_0067: Unknown result type (might be due to invalid IL or missing references)
				//IL_0050: Unknown result type (might be due to invalid IL or missing references)
				//IL_0057: Unknown result type (might be due to invalid IL or missing references)
				//IL_005a: Unknown result type (might be due to invalid IL or missing references)
				ControlBase controlBase = ((ComponentDesigner)this).Component as ControlBase;
				if (!controlBase.AutoSize)
				{
					return base.SelectionRules;
				}
				if (controlBase.Rotation == RotationQuad.X000)
				{
					return (SelectionRules)(base.SelectionRules & -2 & -3);
				}
				if (controlBase.Rotation == RotationQuad.X090)
				{
					return (SelectionRules)(base.SelectionRules & -5 & -9);
				}
				if (controlBase.Rotation == RotationQuad.X180)
				{
					return (SelectionRules)(base.SelectionRules & -2 & -3);
				}
				return (SelectionRules)(base.SelectionRules & -5 & -9);
			}
		}

		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
			properties.Remove("CausesValidation");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[DefaultEvent("ValueChanged")]
	[DefaultProperty("Name")]
	[DesignerCategory("code")]
	[Designer(typeof(DisplayDoubleDesigner))]
	[Description("DisplayDouble")]
	[ToolboxBitmap(typeof(Access), "DisplayDouble.bmp")]
	public class DisplayDouble : ControlBase
	{
		private ValueDouble m_Value;

		private TextFormatDoubleAll m_TextFormatting;

		private TextLayoutFull m_TextLayout;

		[Category("Iocomp")]
		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ValueDouble Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsDouble = value.AsDouble;
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		[Description("Text Format properties")]
		public TextFormatDoubleAll TextFormatting => m_TextFormatting;

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("Text Alignment properties")]
		public TextLayoutFull TextLayout => m_TextLayout;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new DisplayDoubleEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Display Double";
		}

		public DisplayDouble()
		{
			m_License = LicenseManager.Validate(typeof(DisplayDouble), this);
			DoCreate();
		}

		~DisplayDouble()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Value = new ValueDouble();
			AddSubClass(Value);
			m_TextFormatting = new TextFormatDoubleAll();
			AddSubClass(TextFormatting);
			m_TextLayout = new TextLayoutFull();
			AddSubClass(TextLayout);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			base.BackColor = Color.Black;
			base.ForeColor = Color.Aqua;
			base.Border.Style = BorderStyleControl.Sunken;
			TextLayout.Trimming = (StringTrimming)0;
			TextLayout.LineLimit = false;
			TextLayout.MeasureTrailingSpaces = false;
			TextLayout.NoWrap = false;
			TextLayout.NoClip = false;
			TextLayout.AlignmentHorizontal.Style = (StringAlignment)1;
			TextLayout.AlignmentHorizontal.Margin = 0.5;
			TextLayout.AlignmentVertical.Style = (StringAlignment)1;
			TextLayout.AlignmentVertical.Margin = 0.5;
			TextFormatting.DateTimeFormat = "hh:mm:ss";
			TextFormatting.Style = TextFormatDoubleStyle.Number;
			TextFormatting.Precision = 3;
			TextFormatting.PrecisionStyle = PrecisionStyle.None;
			TextFormatting.UnitsText = "";
		}

		protected override Size GetDefaultSize()
		{
			return new Size(100, 20);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			Graphics val = ((Control)this).CreateGraphics();
			GraphicsAPI graphicsAPI = new GraphicsAPI(val);
			Size size = graphicsAPI.MeasureString("A", base.Font, typographic: true);
			val.Dispose();
			return new Size(0, size.Height + 4);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == this && propertyName == "Font")
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeTextFormatting()
		{
			return ((ISubClassBase)TextFormatting).ShouldSerialize();
		}

		private void ResetTextFormatting()
		{
			((ISubClassBase)TextFormatting).ResetToDefault();
		}

		private bool ShouldSerializeTextLayout()
		{
			return ((ISubClassBase)TextLayout).ShouldSerialize();
		}

		private void ResetTextLayout()
		{
			((ISubClassBase)TextLayout).ResetToDefault();
		}

		private void OnValueChanged(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			//IL_002f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0040: Expected O, but got Unknown
			string text = TextFormatting.GetText(m_Value.AsDouble);
			((ITextLayoutBase)TextLayout).Draw(p.Graphics, base.Font, (Brush)new SolidBrush(base.ForeColor), text, p.DrawRectangle);
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class DisplayDoubleEditorPlugIn : PlugInStandard
	{
		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private CheckBox AutoSizeCheckBox;

		private FocusLabel label1;

		private FocusLabel label4;

		private FontButton FontButton;

		private ColorPicker BackColorPicker;

		private ColorPicker ForeColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public DisplayDoubleEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			FontButton = new FontButton();
			AutoSizeCheckBox = new CheckBox();
			label1 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label4 = new FocusLabel();
			ForeColorPicker = new ColorPicker();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(63, 146);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(112, 144);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 4;
			((Control)FontButton).Location = new Point(264, 88);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 2;
			((Control)AutoSizeCheckBox).Location = new Point(264, 144);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 5;
			AutoSizeCheckBox.Text = "Auto Size";
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(51, 115);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(112, 112);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 3;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label4).Location = new Point(53, 91);
			((Control)label4).Name = "label4";
			label4.Size = new Size(59, 15);
			label4.Text = "Fore Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)ForeColorPicker).Location = new Point(112, 88);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(136, 21);
			((Control)ForeColorPicker).TabIndex = 1;
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(112, 24);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(76, 26);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(152, 178);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(112, 176);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 6;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(8, 178);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Name = "DisplayDoubleEditorPlugIn";
			((Control)this).Size = new Size(432, 224);
			base.Title = "Display Double Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueDoubleEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new TextFormatDoubleAllEditorPlugIn(), "Text Formatting", sameLevel: false);
			AddSubPlugIn(new TextLayoutFullEditorPlugin(), "Text Layout", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as DisplayDouble).Value;
			base.SubPlugIns[1].Value = (base.Value as DisplayDouble).TextFormatting;
			base.SubPlugIns[2].Value = (base.Value as DisplayDouble).TextLayout;
			base.SubPlugIns[3].Value = (base.Value as DisplayDouble).Border;
		}
	}
	public class DisplayIntegerDesigner : ControlDesigner
	{
		public override SelectionRules SelectionRules
		{
			get
			{
				//IL_0015: Unknown result type (might be due to invalid IL or missing references)
				//IL_0024: Unknown result type (might be due to invalid IL or missing references)
				//IL_002b: Unknown result type (might be due to invalid IL or missing references)
				//IL_002e: Unknown result type (might be due to invalid IL or missing references)
				//IL_003a: Unknown result type (might be due to invalid IL or missing references)
				//IL_0041: Unknown result type (might be due to invalid IL or missing references)
				//IL_0044: Unknown result type (might be due to invalid IL or missing references)
				//IL_005d: Unknown result type (might be due to invalid IL or missing references)
				//IL_0064: Unknown result type (might be due to invalid IL or missing references)
				//IL_0067: Unknown result type (might be due to invalid IL or missing references)
				//IL_0050: Unknown result type (might be due to invalid IL or missing references)
				//IL_0057: Unknown result type (might be due to invalid IL or missing references)
				//IL_005a: Unknown result type (might be due to invalid IL or missing references)
				ControlBase controlBase = ((ComponentDesigner)this).Component as ControlBase;
				if (!controlBase.AutoSize)
				{
					return base.SelectionRules;
				}
				if (controlBase.Rotation == RotationQuad.X000)
				{
					return (SelectionRules)(base.SelectionRules & -2 & -3);
				}
				if (controlBase.Rotation == RotationQuad.X090)
				{
					return (SelectionRules)(base.SelectionRules & -5 & -9);
				}
				if (controlBase.Rotation == RotationQuad.X180)
				{
					return (SelectionRules)(base.SelectionRules & -2 & -3);
				}
				return (SelectionRules)(base.SelectionRules & -5 & -9);
			}
		}

		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
			properties.Remove("CausesValidation");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[DesignerCategory("code")]
	[Description("Display Integer")]
	[Designer(typeof(DisplayIntegerDesigner))]
	[ToolboxBitmap(typeof(Access), "DisplayInteger.bmp")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[DefaultProperty("Name")]
	[DefaultEvent("ValueChanged")]
	public class DisplayInteger : ControlBase
	{
		private ValueLong m_Value;

		private TextFormatInteger m_TextFormatting;

		private TextLayoutFull m_TextLayout;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		[Category("Iocomp")]
		public ValueLong Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsLong = value.AsLong;
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		[Description("Text Format properties")]
		public TextFormatInteger TextFormatting => m_TextFormatting;

		[Description("Text Alignment properties")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		public TextLayoutFull TextLayout => m_TextLayout;

		[Category("Iocomp")]
		public event ValueLongEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueLongEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new DisplayIntegerEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Display Integer";
		}

		public DisplayInteger()
		{
			m_License = LicenseManager.Validate(typeof(DisplayInteger), this);
			DoCreate();
		}

		~DisplayInteger()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Value = new ValueLong();
			AddSubClass(Value);
			m_TextFormatting = new TextFormatInteger();
			AddSubClass(TextFormatting);
			m_TextLayout = new TextLayoutFull();
			AddSubClass(TextLayout);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			base.BackColor = Color.Black;
			base.ForeColor = Color.Aqua;
			base.Border.Style = BorderStyleControl.Sunken;
			TextLayout.Trimming = (StringTrimming)0;
			TextLayout.LineLimit = false;
			TextLayout.MeasureTrailingSpaces = false;
			TextLayout.NoWrap = false;
			TextLayout.NoClip = false;
			TextLayout.AlignmentHorizontal.Style = (StringAlignment)1;
			TextLayout.AlignmentHorizontal.Margin = 0.5;
			TextLayout.AlignmentVertical.Style = (StringAlignment)1;
			TextLayout.AlignmentVertical.Margin = 0.5;
			TextFormatting.Style = TextFormatIntegerStyle.Integer;
			TextFormatting.FixedLength = 0;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(100, 20);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			Graphics val = ((Control)this).CreateGraphics();
			GraphicsAPI graphicsAPI = new GraphicsAPI(val);
			Size size = graphicsAPI.MeasureString("A", base.Font, typographic: true);
			val.Dispose();
			return new Size(0, size.Height + 4);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == this && propertyName == "Font")
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeTextFormatting()
		{
			return ((ISubClassBase)TextFormatting).ShouldSerialize();
		}

		private void ResetTextFormatting()
		{
			((ISubClassBase)TextFormatting).ResetToDefault();
		}

		private bool ShouldSerializeTextLayout()
		{
			return ((ISubClassBase)TextLayout).ShouldSerialize();
		}

		private void ResetTextLayout()
		{
			((ISubClassBase)TextLayout).ResetToDefault();
		}

		private void OnValueChanged(object sender, ValueLongEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueLongEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			//IL_002f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0040: Expected O, but got Unknown
			string text = TextFormatting.GetText(m_Value.AsLong);
			((ITextLayoutBase)TextLayout).Draw(p.Graphics, base.Font, (Brush)new SolidBrush(base.ForeColor), text, p.DrawRectangle);
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class DisplayIntegerEditorPlugIn : PlugInStandard
	{
		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private CheckBox AutoSizeCheckBox;

		private FocusLabel label1;

		private FocusLabel label4;

		private FontButton FontButton;

		private ColorPicker BackColorPicker;

		private ColorPicker ForeColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public DisplayIntegerEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			FontButton = new FontButton();
			AutoSizeCheckBox = new CheckBox();
			label1 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label4 = new FocusLabel();
			ForeColorPicker = new ColorPicker();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(71, 146);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(120, 144);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 4;
			((Control)FontButton).Location = new Point(272, 88);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 2;
			((Control)AutoSizeCheckBox).Location = new Point(272, 144);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 5;
			AutoSizeCheckBox.Text = "Auto Size";
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(59, 115);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(120, 112);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 3;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label4).Location = new Point(61, 91);
			((Control)label4).Name = "label4";
			label4.Size = new Size(59, 15);
			label4.Text = "Fore Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)ForeColorPicker).Location = new Point(120, 88);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(136, 21);
			((Control)ForeColorPicker).TabIndex = 1;
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(120, 24);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(84, 26);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(160, 178);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(120, 176);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 6;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(16, 178);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Name = "DisplayIntegerEditorPlugIn";
			((Control)this).Size = new Size(432, 216);
			base.Title = "Display Integer Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueLongEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new TextFormatIntegerEditorPlugIn(), "Text Formatting", sameLevel: false);
			AddSubPlugIn(new TextLayoutFullEditorPlugin(), "Text Layout", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as DisplayInteger).Value;
			base.SubPlugIns[1].Value = (base.Value as DisplayInteger).TextFormatting;
			base.SubPlugIns[2].Value = (base.Value as DisplayInteger).TextLayout;
			base.SubPlugIns[3].Value = (base.Value as DisplayInteger).Border;
		}
	}
	public class DisplayStringDesigner : ControlDesigner
	{
		public override SelectionRules SelectionRules
		{
			get
			{
				//IL_0015: Unknown result type (might be due to invalid IL or missing references)
				//IL_0024: Unknown result type (might be due to invalid IL or missing references)
				//IL_002b: Unknown result type (might be due to invalid IL or missing references)
				//IL_002e: Unknown result type (might be due to invalid IL or missing references)
				//IL_003a: Unknown result type (might be due to invalid IL or missing references)
				//IL_0041: Unknown result type (might be due to invalid IL or missing references)
				//IL_0044: Unknown result type (might be due to invalid IL or missing references)
				//IL_005d: Unknown result type (might be due to invalid IL or missing references)
				//IL_0064: Unknown result type (might be due to invalid IL or missing references)
				//IL_0067: Unknown result type (might be due to invalid IL or missing references)
				//IL_0050: Unknown result type (might be due to invalid IL or missing references)
				//IL_0057: Unknown result type (might be due to invalid IL or missing references)
				//IL_005a: Unknown result type (might be due to invalid IL or missing references)
				ControlBase controlBase = ((ComponentDesigner)this).Component as ControlBase;
				if (!controlBase.AutoSize)
				{
					return base.SelectionRules;
				}
				if (controlBase.Rotation == RotationQuad.X000)
				{
					return (SelectionRules)(base.SelectionRules & -2 & -3);
				}
				if (controlBase.Rotation == RotationQuad.X090)
				{
					return (SelectionRules)(base.SelectionRules & -5 & -9);
				}
				if (controlBase.Rotation == RotationQuad.X180)
				{
					return (SelectionRules)(base.SelectionRules & -2 & -3);
				}
				return (SelectionRules)(base.SelectionRules & -5 & -9);
			}
		}

		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
			properties.Remove("CausesValidation");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[Description("Display String")]
	[ToolboxBitmap(typeof(Access), "DisplayString.bmp")]
	[DefaultProperty("Name")]
	[DesignerCategory("code")]
	[DefaultEvent("ValueChanged")]
	[Designer(typeof(DisplayStringDesigner))]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	public class DisplayString : ControlBase
	{
		private ValueString m_Value;

		private TextLayoutFull m_TextLayout;

		[Description("The value contained in the control.")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		public ValueString Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsString = value.AsString;
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("Contains the Text Alignment properties")]
		[Category("Iocomp")]
		public TextLayoutFull TextLayout => m_TextLayout;

		[Category("Iocomp")]
		public event ValueStringEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueStringEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new DisplayStringEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Display String";
		}

		public DisplayString()
		{
			m_License = LicenseManager.Validate(typeof(DisplayString), this);
			DoCreate();
		}

		~DisplayString()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Value = new ValueString();
			AddSubClass(Value);
			m_TextLayout = new TextLayoutFull();
			AddSubClass(TextLayout);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			base.BackColor = Color.Black;
			base.ForeColor = Color.Aqua;
			base.Border.Style = BorderStyleControl.Sunken;
			TextLayout.Trimming = (StringTrimming)0;
			TextLayout.LineLimit = false;
			TextLayout.MeasureTrailingSpaces = false;
			TextLayout.NoWrap = false;
			TextLayout.NoClip = false;
			TextLayout.AlignmentHorizontal.Style = (StringAlignment)1;
			TextLayout.AlignmentHorizontal.Margin = 0.5;
			TextLayout.AlignmentVertical.Style = (StringAlignment)1;
			TextLayout.AlignmentVertical.Margin = 0.5;
			Value.AsString = "Text";
		}

		protected override Size GetDefaultSize()
		{
			return new Size(100, 20);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			Graphics val = ((Control)this).CreateGraphics();
			GraphicsAPI graphicsAPI = new GraphicsAPI(val);
			Size size = graphicsAPI.MeasureString("A", base.Font, typographic: true);
			val.Dispose();
			return new Size(0, size.Height + 4);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == this && propertyName == "Font")
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeTextLayout()
		{
			return ((ISubClassBase)TextLayout).ShouldSerialize();
		}

		private void ResetTextLayout()
		{
			((ISubClassBase)TextLayout).ResetToDefault();
		}

		private void OnValueChanged(object sender, ValueStringEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueStringEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			//IL_0033: Expected O, but got Unknown
			((ITextLayoutBase)TextLayout).Draw(p.Graphics, base.Font, (Brush)new SolidBrush(base.ForeColor), Value.AsString, p.DrawRectangle);
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class DisplayStringEditorPlugIn : PlugInStandard
	{
		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private CheckBox AutoSizeCheckBox;

		private FocusLabel label1;

		private FocusLabel label4;

		private FontButton FontButton;

		private ColorPicker BackColorPicker;

		private ColorPicker ForeColorPicker;

		private FocusLabel focusLabel1;

		private EditMultiLine ValueEditMultiLine;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public DisplayStringEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			FontButton = new FontButton();
			AutoSizeCheckBox = new CheckBox();
			label1 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label4 = new FocusLabel();
			ForeColorPicker = new ColorPicker();
			focusLabel1 = new FocusLabel();
			ValueEditMultiLine = new EditMultiLine();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(71, 138);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(120, 136);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 4;
			((Control)FontButton).Location = new Point(272, 80);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 2;
			((Control)AutoSizeCheckBox).Location = new Point(272, 136);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).Size = new Size(80, 24);
			((Control)AutoSizeCheckBox).TabIndex = 5;
			AutoSizeCheckBox.Text = "Auto Size";
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(59, 107);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(120, 104);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 3;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label4).Location = new Point(61, 83);
			((Control)label4).Name = "label4";
			label4.Size = new Size(59, 15);
			label4.Text = "Fore Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)ForeColorPicker).Location = new Point(120, 80);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(136, 21);
			((Control)ForeColorPicker).TabIndex = 1;
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)ValueEditMultiLine;
			((Control)focusLabel1).Location = new Point(84, 19);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			ValueEditMultiLine.EditFont = null;
			((Control)ValueEditMultiLine).Location = new Point(120, 16);
			((Control)ValueEditMultiLine).Name = "ValueEditMultiLine";
			ValueEditMultiLine.PropertyName = "Value";
			((Control)ValueEditMultiLine).Size = new Size(224, 20);
			((Control)ValueEditMultiLine).TabIndex = 0;
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(160, 170);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(120, 168);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 6;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(16, 170);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)ValueEditMultiLine);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Name = "DisplayStringEditorPlugIn";
			((Control)this).Size = new Size(432, 216);
			base.Title = "Display String Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueStringEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new TextLayoutFullEditorPlugin(), "Text Layout", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as DisplayString).Value;
			base.SubPlugIns[1].Value = (base.Value as DisplayString).TextLayout;
			base.SubPlugIns[2].Value = (base.Value as DisplayString).Border;
		}
	}
	public class EditDoubleDesigner : ControlDesigner
	{
		public override SelectionRules SelectionRules
		{
			get
			{
				//IL_0020: Unknown result type (might be due to invalid IL or missing references)
				//IL_0013: Unknown result type (might be due to invalid IL or missing references)
				//IL_001a: Unknown result type (might be due to invalid IL or missing references)
				//IL_001d: Unknown result type (might be due to invalid IL or missing references)
				if (((TextBoxBase)(((ComponentDesigner)this).Component as EditBase)).AutoSize)
				{
					return (SelectionRules)(base.SelectionRules & -2 & -3);
				}
				return base.SelectionRules;
			}
		}

		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("CharacterCasing");
			properties.Remove("WordWrap");
			properties.Remove("Lines");
			properties.Remove("Multiline");
			properties.Remove("ScrollBars");
			properties.Remove("AcceptsReturn");
			properties.Remove("AcceptsTab");
			properties.Remove("PasswordChar");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("TextChanged");
			events.Remove("MultilineChanged");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[ToolboxItem(true)]
	[Description("Edit Double")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[ToolboxBitmap(typeof(Access), "EditDouble.bmp")]
	[Designer(typeof(EditDoubleDesigner))]
	[DefaultProperty("Name")]
	[DefaultEvent("ValueChanged")]
	[DesignerCategory("code")]
	public class EditDouble : EditBase
	{
		private ValueDouble m_Value;

		private TextFormatDoubleAll m_TextFormatting;

		private bool m_IgnoreDuplicateDecimalCharacter;

		[Category("Iocomp")]
		[Description("")]
		public bool IgnoreDuplicateDecimalCharacter
		{
			get
			{
				return m_IgnoreDuplicateDecimalCharacter;
			}
			set
			{
				PropertyUpdateDefault("IgnoreDuplicateDecimalCharacter", value);
				if (IgnoreDuplicateDecimalCharacter != value)
				{
					m_IgnoreDuplicateDecimalCharacter = value;
					DoPropertyChange(this, "IgnoreDuplicateDecimalCharacter");
				}
			}
		}

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		public ValueDouble Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsDouble = value.AsDouble;
			}
		}

		[Description("Text Format properties")]
		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public TextFormatDoubleAll TextFormatting => m_TextFormatting;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new EditDoubleEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Edit Double";
		}

		public EditDouble()
		{
			m_License = LicenseManager.Validate(typeof(EditDouble), this);
			DoCreate();
		}

		~EditDouble()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Value = new ValueDouble();
			AddSubClass(Value);
			m_TextFormatting = new TextFormatDoubleAll();
			AddSubClass(TextFormatting);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			IgnoreDuplicateDecimalCharacter = false;
			TextFormatting.DateTimeFormat = "hh:mm:ss";
			TextFormatting.Style = TextFormatDoubleStyle.Number;
			TextFormatting.Precision = 3;
			TextFormatting.PrecisionStyle = PrecisionStyle.None;
			TextFormatting.UnitsText = "";
		}

		protected override Size GetDefaultSize()
		{
			return new Size(100, 20);
		}

		private bool ShouldSerializeIgnoreDuplicateDecimalCharacter()
		{
			return PropertyShouldSerialize("IgnoreDuplicateDecimalCharacter");
		}

		private void ResetIgnoreDuplicateDecimalCharacter()
		{
			PropertyReset("IgnoreDuplicateDecimalCharacter");
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == Value)
			{
				UpdateText();
			}
			if (sender == TextFormatting)
			{
				UpdateText();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeTextFormatting()
		{
			return ((ISubClassBase)TextFormatting).ShouldSerialize();
		}

		private void ResetTextFormatting()
		{
			((ISubClassBase)TextFormatting).ResetToDefault();
		}

		private void OnValueChanged(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void InternalOnKeyPress(KeyPressEventArgs e)
		{
			bool flag = false;
			bool flag2 = false;
			if (e.KeyChar >= '0' && e.KeyChar <= '9')
			{
				flag = true;
			}
			if (e.KeyChar == '.')
			{
				flag = true;
			}
			if (e.KeyChar == ',')
			{
				flag = true;
			}
			if (e.KeyChar == '-')
			{
				flag = true;
			}
			if (e.KeyChar == '+')
			{
				flag = true;
			}
			if (e.KeyChar == '\b')
			{
				flag = true;
			}
			if (e.KeyChar == '\t')
			{
				flag = true;
			}
			if (e.KeyChar == '\u0003')
			{
				flag = true;
			}
			if (e.KeyChar == '\u0016')
			{
				flag = true;
			}
			if (e.KeyChar == '\u0018')
			{
				flag = true;
			}
			if (e.KeyChar == '\u001a')
			{
				flag = true;
			}
			if (e.KeyChar == 'e')
			{
				flag = true;
			}
			if (e.KeyChar == 'E')
			{
				flag = true;
			}
			if (TextFormatting.UnitsText.IndexOf(e.KeyChar) != -1)
			{
				flag = true;
			}
			if (TextFormatting.UnitsText.ToUpper().IndexOf(e.KeyChar.ToString().ToUpper()) != -1)
			{
				flag = true;
			}
			if (((Control)this).Text.IndexOf(".") >= 0)
			{
				flag2 = true;
			}
			if (((Control)this).Text.IndexOf(",") >= 0)
			{
				flag2 = true;
			}
			if (IgnoreDuplicateDecimalCharacter && e.KeyChar == '.' && flag2)
			{
				flag = false;
			}
			if (IgnoreDuplicateDecimalCharacter && e.KeyChar == ',' && flag2)
			{
				flag = false;
			}
			if (e.KeyChar == '\r')
			{
				UpdateValue();
				e.Handled = true;
			}
			else if (e.KeyChar == '\u001b')
			{
				UpdateText();
				e.Handled = true;
			}
			else
			{
				e.Handled = !flag;
			}
		}

		protected override void UpdateValue()
		{
			StringBuilder stringBuilder = new StringBuilder();
			string text = ((Control)this).Text.Trim();
			text = text.ToUpper();
			int num = text.IndexOf(TextFormatting.UnitsText.Trim().ToUpper());
			if (num != -1)
			{
				text = text.Remove(num, TextFormatting.UnitsText.Trim().Length);
			}
			if (text.Length != 0)
			{
				for (int i = 0; i < text.Length; i++)
				{
					bool flag = false;
					if (text[i] >= '0' && ((Control)this).Text[i] <= '9')
					{
						flag = true;
					}
					if (text[i] == '.')
					{
						flag = true;
					}
					if (text[i] == ',')
					{
						flag = true;
					}
					if (text[i] == '-')
					{
						flag = true;
					}
					if (text[i] == '+')
					{
						flag = true;
					}
					if (TextFormatting.Style == TextFormatDoubleStyle.Exponent && text[i] == 'e')
					{
						flag = true;
					}
					if (TextFormatting.Style == TextFormatDoubleStyle.Exponent && text[i] == 'E')
					{
						flag = true;
					}
					if (flag)
					{
						stringBuilder.Append(((Control)this).Text[i]);
					}
				}
				try
				{
					Value.AsDouble = Convert.ToDouble(stringBuilder.ToString(), CultureInfo.CurrentCulture);
				}
				catch
				{
				}
			}
			UpdateText();
		}

		protected override void UpdateText()
		{
			((Control)this).Text = TextFormatting.GetText(Value.AsDouble);
			((TextBoxBase)this).SelectionStart = 0;
			if (TextFormatting.UnitsText != null)
			{
				((TextBoxBase)this).SelectionLength = ((Control)this).Text.Length - TextFormatting.UnitsText.Length;
			}
			else
			{
				((TextBoxBase)this).SelectionLength = ((Control)this).Text.Length;
			}
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class EditDoubleEditorPlugIn : PlugInStandard
	{
		private CheckBox AutoSizeCheckBox;

		private CheckBox ReadOnlyCheckBox;

		private NumericUpDown MaxLengthNumericUpDown;

		private FocusLabel label7;

		private FocusLabel label2;

		private ComboBox BorderStyleComboBox;

		private FocusLabel label5;

		private ComboBox TextAlignComboBox;

		private FocusLabel label1;

		private FocusLabel label4;

		private CheckBox UpdateOnLostFocusCheckBox;

		private FontButton FontButton;

		private ColorPicker BackColorPicker;

		private ColorPicker ForeColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private CheckBox checkBox1;

		private Container components = null;

		public EditDoubleEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			AutoSizeCheckBox = new CheckBox();
			ReadOnlyCheckBox = new CheckBox();
			MaxLengthNumericUpDown = new NumericUpDown();
			label7 = new FocusLabel();
			FontButton = new FontButton();
			label2 = new FocusLabel();
			BorderStyleComboBox = new ComboBox();
			label5 = new FocusLabel();
			TextAlignComboBox = new ComboBox();
			label1 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label4 = new FocusLabel();
			ForeColorPicker = new ColorPicker();
			UpdateOnLostFocusCheckBox = new CheckBox();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			checkBox1 = new CheckBox();
			((Control)this).SuspendLayout();
			((Control)AutoSizeCheckBox).Location = new Point(264, 48);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 7;
			AutoSizeCheckBox.Text = "Auto Size";
			((Control)ReadOnlyCheckBox).Location = new Point(264, 72);
			((Control)ReadOnlyCheckBox).Name = "ReadOnlyCheckBox";
			ReadOnlyCheckBox.PropertyName = "ReadOnly";
			((Control)ReadOnlyCheckBox).TabIndex = 8;
			ReadOnlyCheckBox.Text = "Read Only";
			((Control)MaxLengthNumericUpDown).Location = new Point(320, 8);
			((NumericUpDown)MaxLengthNumericUpDown).Maximum = new decimal(new int[4] { 0, 0, -2147483648, 0 });
			((Control)MaxLengthNumericUpDown).Name = "MaxLengthNumericUpDown";
			MaxLengthNumericUpDown.PropertyName = "MaxLength";
			((Control)MaxLengthNumericUpDown).Size = new Size(72, 20);
			((Control)MaxLengthNumericUpDown).TabIndex = 6;
			((UpDownBase)MaxLengthNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label7.LoadingBegin();
			label7.FocusControl = (Control)(object)MaxLengthNumericUpDown;
			((Control)label7).Location = new Point(255, 9);
			((Control)label7).Name = "label7";
			label7.Size = new Size(65, 15);
			label7.Text = "Max Length";
			label7.UpdateFrameRate = 50.0;
			label7.LoadingEnd();
			((Control)FontButton).Location = new Point(264, 158);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 11;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)BorderStyleComboBox;
			((Control)label2).Location = new Point(36, 78);
			((Control)label2).Name = "label2";
			label2.Size = new Size(68, 15);
			label2.Text = "Border Style";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((ComboBox)BorderStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)BorderStyleComboBox).Location = new Point(104, 76);
			((Control)BorderStyleComboBox).Name = "BorderStyleComboBox";
			BorderStyleComboBox.PropertyName = "BorderStyle";
			((Control)BorderStyleComboBox).Size = new Size(144, 21);
			((Control)BorderStyleComboBox).TabIndex = 2;
			label5.LoadingBegin();
			label5.FocusControl = (Control)(object)TextAlignComboBox;
			((Control)label5).Location = new Point(48, 54);
			((Control)label5).Name = "label5";
			label5.Size = new Size(56, 15);
			label5.Text = "Text Align";
			label5.UpdateFrameRate = 50.0;
			label5.LoadingEnd();
			((ComboBox)TextAlignComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)TextAlignComboBox).Location = new Point(104, 52);
			((Control)TextAlignComboBox).Name = "TextAlignComboBox";
			TextAlignComboBox.PropertyName = "TextAlign";
			((Control)TextAlignComboBox).Size = new Size(144, 21);
			((Control)TextAlignComboBox).TabIndex = 1;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(43, 163);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(104, 160);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(144, 21);
			((Control)BackColorPicker).TabIndex = 4;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label4).Location = new Point(45, 139);
			((Control)label4).Name = "label4";
			label4.Size = new Size(59, 15);
			label4.Text = "Fore Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)ForeColorPicker).Location = new Point(104, 136);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(144, 21);
			((Control)ForeColorPicker).TabIndex = 3;
			((Control)UpdateOnLostFocusCheckBox).Location = new Point(264, 96);
			((Control)UpdateOnLostFocusCheckBox).Name = "UpdateOnLostFocusCheckBox";
			UpdateOnLostFocusCheckBox.PropertyName = "UpdateOnLostFocus";
			((Control)UpdateOnLostFocusCheckBox).Size = new Size(136, 24);
			((Control)UpdateOnLostFocusCheckBox).TabIndex = 9;
			UpdateOnLostFocusCheckBox.Text = "Update On Lost Focus";
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(104, 8);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(144, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(68, 10);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(144, 194);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(104, 192);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 5;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(0, 194);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)checkBox1).Location = new Point(264, 120);
			((Control)checkBox1).Name = "checkBox1";
			checkBox1.PropertyName = "IgnoreDuplicateDecimalCharacter";
			((Control)checkBox1).Size = new Size(208, 24);
			((Control)checkBox1).TabIndex = 10;
			checkBox1.Text = "Ignore Duplicate Decimal Character";
			((Control)this).Controls.Add((Control)(object)checkBox1);
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)UpdateOnLostFocusCheckBox);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label5);
			((Control)this).Controls.Add((Control)(object)TextAlignComboBox);
			((Control)this).Controls.Add((Control)(object)BorderStyleComboBox);
			((Control)this).Controls.Add((Control)(object)ReadOnlyCheckBox);
			((Control)this).Controls.Add((Control)(object)MaxLengthNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label7);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Name = "EditDoubleEditorPlugIn";
			((Control)this).Size = new Size(488, 232);
			base.Title = "Edit Double Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueDoubleEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new TextFormatDoubleAllEditorPlugIn(), "Text Formatting", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as EditDouble).Value;
			base.SubPlugIns[1].Value = (base.Value as EditDouble).TextFormatting;
		}
	}
	public class EditIntegerDesigner : ControlDesigner
	{
		public override SelectionRules SelectionRules
		{
			get
			{
				//IL_0020: Unknown result type (might be due to invalid IL or missing references)
				//IL_0013: Unknown result type (might be due to invalid IL or missing references)
				//IL_001a: Unknown result type (might be due to invalid IL or missing references)
				//IL_001d: Unknown result type (might be due to invalid IL or missing references)
				if (((TextBoxBase)(((ComponentDesigner)this).Component as EditBase)).AutoSize)
				{
					return (SelectionRules)(base.SelectionRules & -2 & -3);
				}
				return base.SelectionRules;
			}
		}

		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("CharacterCasing");
			properties.Remove("WordWrap");
			properties.Remove("Lines");
			properties.Remove("Multiline");
			properties.Remove("ScrollBars");
			properties.Remove("AcceptsReturn");
			properties.Remove("AcceptsTab");
			properties.Remove("PasswordChar");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("TextChanged");
			events.Remove("MultilineChanged");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[Description("Edit Integer")]
	[DesignerCategory("code")]
	[DefaultEvent("ValueChanged")]
	[ToolboxItem(true)]
	[ToolboxBitmap(typeof(Access), "EditInteger.bmp")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[Designer(typeof(EditIntegerDesigner))]
	[DefaultProperty("Name")]
	public class EditInteger : EditBase
	{
		private ValueLong m_Value;

		private TextFormatInteger m_TextFormatting;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		[Description("")]
		public ValueLong Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsLong = value.AsLong;
			}
		}

		[Description("Text Format properties")]
		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public TextFormatInteger TextFormatting => m_TextFormatting;

		[Category("Iocomp")]
		public event ValueLongEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueLongEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new EditIntegerEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Edit Integer";
		}

		public EditInteger()
		{
			m_License = LicenseManager.Validate(typeof(EditInteger), this);
			DoCreate();
		}

		~EditInteger()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Value = new ValueLong();
			AddSubClass(Value);
			m_TextFormatting = new TextFormatInteger();
			AddSubClass(TextFormatting);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			TextFormatting.Style = TextFormatIntegerStyle.Integer;
			TextFormatting.FixedLength = 0;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(100, 20);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == Value)
			{
				UpdateText();
			}
			if (sender == TextFormatting)
			{
				UpdateText();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeTextFormatting()
		{
			return ((ISubClassBase)TextFormatting).ShouldSerialize();
		}

		private void ResetTextFormatting()
		{
			((ISubClassBase)TextFormatting).ResetToDefault();
		}

		private void OnValueChanged(object sender, ValueLongEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueLongEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void InternalOnKeyPress(KeyPressEventArgs e)
		{
			bool flag = false;
			flag = false;
			if (e.KeyChar == '\b')
			{
				flag = true;
			}
			if (e.KeyChar == '\t')
			{
				flag = true;
			}
			if (e.KeyChar == '\u0003')
			{
				flag = true;
			}
			if (e.KeyChar == '\u0016')
			{
				flag = true;
			}
			if (e.KeyChar == '\u0018')
			{
				flag = true;
			}
			if (e.KeyChar == '\u001a')
			{
				flag = true;
			}
			if (TextFormatting.Style == TextFormatIntegerStyle.Integer)
			{
				if (e.KeyChar >= '0' && e.KeyChar <= '9')
				{
					flag = true;
				}
				if (e.KeyChar == '-')
				{
					flag = true;
				}
			}
			else if (TextFormatting.Style == TextFormatIntegerStyle.Binary)
			{
				if (e.KeyChar >= '0' && e.KeyChar <= '1')
				{
					flag = true;
				}
			}
			else if (TextFormatting.Style == TextFormatIntegerStyle.Octal)
			{
				if (e.KeyChar >= '0' && e.KeyChar <= '7')
				{
					flag = true;
				}
			}
			else if (TextFormatting.Style == TextFormatIntegerStyle.Hexadecimal)
			{
				if (e.KeyChar >= '0' && e.KeyChar <= '9')
				{
					flag = true;
				}
				if (e.KeyChar >= 'A' && e.KeyChar <= 'F')
				{
					flag = true;
				}
				if (e.KeyChar >= 'a' && e.KeyChar <= 'f')
				{
					flag = true;
				}
			}
			if (e.KeyChar == '\r')
			{
				UpdateValue();
				e.Handled = true;
			}
			else if (e.KeyChar == '\u001b')
			{
				UpdateText();
				e.Handled = true;
			}
			else
			{
				e.Handled = !flag;
			}
		}

		protected override void UpdateValue()
		{
			try
			{
				if (((Control)this).Text.Length != 0)
				{
					Value.AsLong = TextFormatting.GetValue(((Control)this).Text);
				}
			}
			catch
			{
			}
			UpdateText();
		}

		protected override void UpdateText()
		{
			((Control)this).Text = TextFormatting.GetText(Value.AsLong);
			((TextBoxBase)this).SelectAll();
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class EditIntegerEditorPlugIn : PlugInStandard
	{
		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private CheckBox UpdateOnLostFocusCheckBox;

		private FocusLabel label1;

		private ColorPicker BackColorPicker;

		private FocusLabel label4;

		private ColorPicker ForeColorPicker;

		private FocusLabel label5;

		private ComboBox TextAlignComboBox;

		private ComboBox BorderStyleComboBox;

		private CheckBox ReadOnlyCheckBox;

		private NumericUpDown MaxLengthNumericUpDown;

		private FocusLabel label7;

		private CheckBox AutoSizeCheckBox;

		private FontButton FontButton;

		private FocusLabel label2;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public EditIntegerEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			UpdateOnLostFocusCheckBox = new CheckBox();
			label1 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label4 = new FocusLabel();
			ForeColorPicker = new ColorPicker();
			label5 = new FocusLabel();
			TextAlignComboBox = new ComboBox();
			BorderStyleComboBox = new ComboBox();
			ReadOnlyCheckBox = new CheckBox();
			MaxLengthNumericUpDown = new NumericUpDown();
			label7 = new FocusLabel();
			AutoSizeCheckBox = new CheckBox();
			FontButton = new FontButton();
			label2 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(112, 8);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(144, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(76, 10);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			((Control)UpdateOnLostFocusCheckBox).Location = new Point(272, 96);
			((Control)UpdateOnLostFocusCheckBox).Name = "UpdateOnLostFocusCheckBox";
			UpdateOnLostFocusCheckBox.PropertyName = "UpdateOnLostFocus";
			((Control)UpdateOnLostFocusCheckBox).Size = new Size(136, 24);
			((Control)UpdateOnLostFocusCheckBox).TabIndex = 9;
			UpdateOnLostFocusCheckBox.Text = "Update On Lost Focus";
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(51, 163);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(112, 160);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(144, 21);
			((Control)BackColorPicker).TabIndex = 4;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label4).Location = new Point(53, 139);
			((Control)label4).Name = "label4";
			label4.Size = new Size(59, 15);
			label4.Text = "Fore Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)ForeColorPicker).Location = new Point(112, 136);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(144, 21);
			((Control)ForeColorPicker).TabIndex = 3;
			label5.LoadingBegin();
			label5.FocusControl = (Control)(object)TextAlignComboBox;
			((Control)label5).Location = new Point(56, 54);
			((Control)label5).Name = "label5";
			label5.Size = new Size(56, 15);
			label5.Text = "Text Align";
			label5.UpdateFrameRate = 50.0;
			label5.LoadingEnd();
			((ComboBox)TextAlignComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)TextAlignComboBox).Location = new Point(112, 52);
			((Control)TextAlignComboBox).Name = "TextAlignComboBox";
			TextAlignComboBox.PropertyName = "TextAlign";
			((Control)TextAlignComboBox).Size = new Size(144, 21);
			((Control)TextAlignComboBox).TabIndex = 1;
			((ComboBox)BorderStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)BorderStyleComboBox).Location = new Point(112, 76);
			((Control)BorderStyleComboBox).Name = "BorderStyleComboBox";
			BorderStyleComboBox.PropertyName = "BorderStyle";
			((Control)BorderStyleComboBox).Size = new Size(144, 21);
			((Control)BorderStyleComboBox).TabIndex = 2;
			((Control)ReadOnlyCheckBox).Location = new Point(272, 72);
			((Control)ReadOnlyCheckBox).Name = "ReadOnlyCheckBox";
			ReadOnlyCheckBox.PropertyName = "ReadOnly";
			((Control)ReadOnlyCheckBox).TabIndex = 8;
			ReadOnlyCheckBox.Text = "Read Only";
			((Control)MaxLengthNumericUpDown).Location = new Point(328, 8);
			((NumericUpDown)MaxLengthNumericUpDown).Maximum = new decimal(new int[4] { 0, 0, -2147483648, 0 });
			((Control)MaxLengthNumericUpDown).Name = "MaxLengthNumericUpDown";
			MaxLengthNumericUpDown.PropertyName = "MaxLength";
			((Control)MaxLengthNumericUpDown).Size = new Size(72, 20);
			((Control)MaxLengthNumericUpDown).TabIndex = 6;
			((UpDownBase)MaxLengthNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label7.LoadingBegin();
			label7.FocusControl = (Control)(object)MaxLengthNumericUpDown;
			((Control)label7).Location = new Point(263, 9);
			((Control)label7).Name = "label7";
			label7.Size = new Size(65, 15);
			label7.Text = "Max Length";
			label7.UpdateFrameRate = 50.0;
			label7.LoadingEnd();
			((Control)AutoSizeCheckBox).Location = new Point(272, 48);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 7;
			AutoSizeCheckBox.Text = "Auto Size";
			((Control)FontButton).Location = new Point(272, 136);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 10;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)BorderStyleComboBox;
			((Control)label2).Location = new Point(44, 78);
			((Control)label2).Name = "label2";
			label2.Size = new Size(68, 15);
			label2.Text = "Border Style";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(152, 194);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(112, 192);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 5;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(8, 194);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)UpdateOnLostFocusCheckBox);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label5);
			((Control)this).Controls.Add((Control)(object)TextAlignComboBox);
			((Control)this).Controls.Add((Control)(object)BorderStyleComboBox);
			((Control)this).Controls.Add((Control)(object)ReadOnlyCheckBox);
			((Control)this).Controls.Add((Control)(object)MaxLengthNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label7);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Name = "EditIntegerEditorPlugIn";
			((Control)this).Size = new Size(488, 232);
			base.Title = "Edit Integer Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueLongEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new TextFormatIntegerEditorPlugIn(), "Text Formatting", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as EditInteger).Value;
			base.SubPlugIns[1].Value = (base.Value as EditInteger).TextFormatting;
		}
	}
	public class EditStringDesigner : ControlDesigner
	{
		public override SelectionRules SelectionRules
		{
			get
			{
				//IL_0020: Unknown result type (might be due to invalid IL or missing references)
				//IL_0013: Unknown result type (might be due to invalid IL or missing references)
				//IL_001a: Unknown result type (might be due to invalid IL or missing references)
				//IL_001d: Unknown result type (might be due to invalid IL or missing references)
				if (((TextBoxBase)(((ComponentDesigner)this).Component as EditBase)).AutoSize)
				{
					return (SelectionRules)(base.SelectionRules & -2 & -3);
				}
				return base.SelectionRules;
			}
		}

		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("Text");
			properties.Remove("CharacterCasing");
			properties.Remove("WordWrap");
			properties.Remove("Lines");
			properties.Remove("Multiline");
			properties.Remove("ScrollBars");
			properties.Remove("AcceptsReturn");
			properties.Remove("AcceptsTab");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("TextChanged");
			events.Remove("MultilineChanged");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[DefaultProperty("Name")]
	[Designer(typeof(EditStringDesigner))]
	[ToolboxItem(true)]
	[DefaultEvent("ValueChanged")]
	[DesignerCategory("code")]
	[ToolboxBitmap(typeof(Access), "EditString.bmp")]
	[Description("EditString")]
	public class EditString : EditBase
	{
		private ValueString m_Value;

		[Description("")]
		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ValueString Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsString = value.AsString;
			}
		}

		[Category("Iocomp")]
		public event ValueStringEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueStringEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new EditStringEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Edit String";
		}

		public EditString()
		{
			m_License = LicenseManager.Validate(typeof(EditString), this);
			DoCreate();
		}

		~EditString()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Value = new ValueString();
			AddSubClass(Value);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			Value.AsString = "Edit";
		}

		protected override Size GetDefaultSize()
		{
			return new Size(100, 20);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == Value)
			{
				UpdateText();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private void OnValueChanged(object sender, ValueStringEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueStringEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void InternalOnKeyPress(KeyPressEventArgs e)
		{
			if (e.KeyChar == '\r')
			{
				UpdateValue();
				e.Handled = true;
			}
			else if (e.KeyChar == '\u001b')
			{
				UpdateText();
				e.Handled = true;
			}
			else
			{
				e.Handled = false;
			}
		}

		protected override void UpdateValue()
		{
			Value.AsString = ((Control)this).Text;
			UpdateText();
		}

		protected override void UpdateText()
		{
			((Control)this).Text = Value.AsString;
			((TextBoxBase)this).SelectAll();
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class EditStringEditorPlugIn : PlugInStandard
	{
		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private CheckBox UpdateOnLostFocusCheckBox;

		private FocusLabel label1;

		private ColorPicker BackColorPicker;

		private FocusLabel label4;

		private ColorPicker ForeColorPicker;

		private FocusLabel label5;

		private ComboBox TextAlignComboBox;

		private ComboBox BorderStyleComboBox;

		private CheckBox ReadOnlyCheckBox;

		private NumericUpDown MaxLengthNumericUpDown;

		private FocusLabel label7;

		private CheckBox AutoSizeCheckBox;

		private FontButton FontButton;

		private FocusLabel label2;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public EditStringEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			UpdateOnLostFocusCheckBox = new CheckBox();
			label1 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label4 = new FocusLabel();
			ForeColorPicker = new ColorPicker();
			label5 = new FocusLabel();
			TextAlignComboBox = new ComboBox();
			BorderStyleComboBox = new ComboBox();
			ReadOnlyCheckBox = new CheckBox();
			MaxLengthNumericUpDown = new NumericUpDown();
			label7 = new FocusLabel();
			AutoSizeCheckBox = new CheckBox();
			FontButton = new FontButton();
			label2 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(120, 8);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(144, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(84, 10);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			((Control)UpdateOnLostFocusCheckBox).Location = new Point(280, 96);
			((Control)UpdateOnLostFocusCheckBox).Name = "UpdateOnLostFocusCheckBox";
			UpdateOnLostFocusCheckBox.PropertyName = "UpdateOnLostFocus";
			((Control)UpdateOnLostFocusCheckBox).Size = new Size(136, 24);
			((Control)UpdateOnLostFocusCheckBox).TabIndex = 9;
			UpdateOnLostFocusCheckBox.Text = "Update On Lost Focus";
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(59, 163);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(120, 160);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(144, 21);
			((Control)BackColorPicker).TabIndex = 4;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label4).Location = new Point(61, 139);
			((Control)label4).Name = "label4";
			label4.Size = new Size(59, 15);
			label4.Text = "Fore Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)ForeColorPicker).Location = new Point(120, 136);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(144, 21);
			((Control)ForeColorPicker).TabIndex = 3;
			label5.LoadingBegin();
			label5.FocusControl = (Control)(object)TextAlignComboBox;
			((Control)label5).Location = new Point(64, 54);
			((Control)label5).Name = "label5";
			label5.Size = new Size(56, 15);
			label5.Text = "Text Align";
			label5.UpdateFrameRate = 50.0;
			label5.LoadingEnd();
			((ComboBox)TextAlignComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)TextAlignComboBox).Location = new Point(120, 52);
			((Control)TextAlignComboBox).Name = "TextAlignComboBox";
			TextAlignComboBox.PropertyName = "TextAlign";
			((Control)TextAlignComboBox).Size = new Size(144, 21);
			((Control)TextAlignComboBox).TabIndex = 1;
			((ComboBox)BorderStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)BorderStyleComboBox).Location = new Point(120, 76);
			((Control)BorderStyleComboBox).Name = "BorderStyleComboBox";
			BorderStyleComboBox.PropertyName = "BorderStyle";
			((Control)BorderStyleComboBox).Size = new Size(144, 21);
			((Control)BorderStyleComboBox).TabIndex = 2;
			((Control)ReadOnlyCheckBox).Location = new Point(280, 72);
			((Control)ReadOnlyCheckBox).Name = "ReadOnlyCheckBox";
			ReadOnlyCheckBox.PropertyName = "ReadOnly";
			((Control)ReadOnlyCheckBox).TabIndex = 8;
			ReadOnlyCheckBox.Text = "Read Only";
			((Control)MaxLengthNumericUpDown).Location = new Point(336, 8);
			((NumericUpDown)MaxLengthNumericUpDown).Maximum = new decimal(new int[4] { 0, 0, -2147483648, 0 });
			((Control)MaxLengthNumericUpDown).Name = "MaxLengthNumericUpDown";
			MaxLengthNumericUpDown.PropertyName = "MaxLength";
			((Control)MaxLengthNumericUpDown).Size = new Size(72, 20);
			((Control)MaxLengthNumericUpDown).TabIndex = 6;
			((UpDownBase)MaxLengthNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label7.LoadingBegin();
			label7.FocusControl = (Control)(object)MaxLengthNumericUpDown;
			((Control)label7).Location = new Point(271, 9);
			((Control)label7).Name = "label7";
			label7.Size = new Size(65, 15);
			label7.Text = "Max Length";
			label7.UpdateFrameRate = 50.0;
			label7.LoadingEnd();
			((Control)AutoSizeCheckBox).Location = new Point(280, 48);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 7;
			AutoSizeCheckBox.Text = "Auto Size";
			((Control)FontButton).Location = new Point(280, 136);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 10;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)BorderStyleComboBox;
			((Control)label2).Location = new Point(52, 78);
			((Control)label2).Name = "label2";
			label2.Size = new Size(68, 15);
			label2.Text = "Border Style";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(160, 194);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(120, 192);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 5;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(16, 194);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)UpdateOnLostFocusCheckBox);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label5);
			((Control)this).Controls.Add((Control)(object)TextAlignComboBox);
			((Control)this).Controls.Add((Control)(object)BorderStyleComboBox);
			((Control)this).Controls.Add((Control)(object)ReadOnlyCheckBox);
			((Control)this).Controls.Add((Control)(object)MaxLengthNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label7);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Name = "EditStringEditorPlugIn";
			((Control)this).Size = new Size(488, 224);
			base.Title = "Edit String Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueStringEditorPlugIn(), "Value", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as EditString).Value;
		}
	}
	public class GaugeAngularDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
			properties.Remove("CausesValidation");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[DefaultEvent("ValueChanged")]
	[Designer(typeof(GaugeAngularDesigner))]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[Description("GaugeAngular")]
	[DefaultProperty("Name")]
	[ToolboxBitmap(typeof(Access), "GaugeAngular.bmp")]
	[DesignerCategory("code")]
	public class GaugeAngular : ControlBase
	{
		private ColorSectionCollection m_ColorSections;

		private PointerGaugeAngularCollection m_Pointers;

		private Hub m_Hub;

		private ScaleRangeAngular m_ScaleRange;

		private IScaleRangeAngular I_Range;

		private ScaleDisplayAngular m_ScaleDisplay;

		private IScaleDisplayAngular I_Display;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		[Description("")]
		public PointerGaugeAngularCollection Pointers => m_Pointers;

		[Category("Iocomp")]
		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ColorSectionCollection ColorSections => m_ColorSections;

		[Description("")]
		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public ValueDouble Value
		{
			get
			{
				if (Pointers.Count != 0)
				{
					return Pointers[0].Value;
				}
				return null;
			}
			set
			{
				if (Pointers.Count != 0)
				{
					Pointers[0].Value = value;
				}
			}
		}

		[Category("Iocomp")]
		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public Hub Hub => m_Hub;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		[Category("Iocomp")]
		public ScaleRangeAngular ScaleRange => m_ScaleRange;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		[Description("")]
		public ScaleDisplayAngular ScaleDisplay => m_ScaleDisplay;

		[Description("")]
		[RefreshProperties(RefreshProperties.All)]
		[Category("Iocomp")]
		public int InnerRadius
		{
			get
			{
				return I_Display.Radius;
			}
			set
			{
				PropertyUpdateDefault("InnerRadius", value);
				if (I_Display.Radius != value)
				{
					I_Display.Radius = value;
					DoAutoSize();
					DoPropertyChange(this, "InnerRadius");
				}
			}
		}

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new GaugeAngularEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Gauge Angular";
		}

		public GaugeAngular()
		{
			m_License = LicenseManager.Validate(typeof(GaugeAngular), this);
			DoCreate();
		}

		~GaugeAngular()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_ColorSections = new ColorSectionCollection(this);
			m_Pointers = new PointerGaugeAngularCollection(this);
			m_Hub = new Hub();
			AddSubClass(Hub);
			m_ScaleRange = new ScaleRangeAngular();
			AddSubClass(ScaleRange);
			I_Range = ScaleRange;
			m_ScaleDisplay = new ScaleDisplayAngular();
			AddSubClass(ScaleDisplay);
			I_Display = ScaleDisplay;
			I_Display.Range = m_ScaleRange;
			m_Pointers.ObjectAdded += m_Pointers_ObjectAdded;
			m_Pointers.ObjectRemoved += m_Pointers_ObjectRemoved;
		}

		protected override void SetComponentDefaults()
		{
			ColorSections.Reset();
			Pointers.Reset();
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			InnerRadius = 74;
			Hub.Color = Color.Black;
			Hub.Size = 7;
			Hub.Visible = true;
			ScaleRange.AngleMin = 180.0;
			ScaleRange.AngleSpan = 90.0;
			ScaleRange.Span = 100.0;
			ScaleRange.Min = 0.0;
			ScaleRange.Reverse = false;
			ScaleDisplay.GeneratorAuto.DesiredIncrement = 0.0;
			ScaleDisplay.GeneratorAuto.MinTextSpacing = 1.0;
			ScaleDisplay.GeneratorAuto.MinorCount = 4;
			ScaleDisplay.GeneratorAuto.MidIncluded = false;
			ScaleDisplay.GeneratorFixed.MinorCount = 4;
			ScaleDisplay.GeneratorFixed.MidIncluded = false;
			ScaleDisplay.GeneratorFixed.MajorCount = 6;
			ScaleDisplay.GeneratorStyle = ScaleGeneratorStyle.Auto;
			ScaleDisplay.StartRefValue = 0.0;
			ScaleDisplay.StartRefEnabled = false;
			ScaleDisplay.TextAlignment = StringAlignmentAngular.Center;
			ScaleDisplay.Margin = 0;
			ScaleDisplay.TextWidthMinValue = 0.0;
			ScaleDisplay.TextWidthMinAuto = false;
			ScaleDisplay.LineInnerVisible = false;
			ScaleDisplay.LineOuterVisible = false;
			ScaleDisplay.Visible = true;
			ScaleDisplay.TextFormatting.Precision = 1;
			ScaleDisplay.TextFormatting.PrecisionStyle = PrecisionStyle.FixedDecimalPoints;
			ScaleDisplay.TextFormatting.UnitsText = "";
			ScaleDisplay.TextFormatting.Style = TextFormatDoubleStyle.Number;
			ScaleDisplay.TextFormatting.DateTimeFormat = "hh:mm:ss";
			ScaleDisplay.TickMinor.Alignment = AlignmentStyle.Center;
			ScaleDisplay.TickMinor.Length = 3;
			ScaleDisplay.TickMinor.Color = Color.Black;
			ScaleDisplay.TickMinor.Thickness = 1;
			ScaleDisplay.TickMid.Length = 5;
			ScaleDisplay.TickMid.Font = null;
			ScaleDisplay.TickMid.ForeColor = Color.Empty;
			ScaleDisplay.TickMid.TextVisible = true;
			ScaleDisplay.TickMid.TextMargin = 2;
			ScaleDisplay.TickMid.Alignment = AlignmentStyle.Near;
			ScaleDisplay.TickMid.Color = Color.Black;
			ScaleDisplay.TickMid.Thickness = 1;
			ScaleDisplay.TickMajor.Length = 12;
			ScaleDisplay.TickMajor.Font = null;
			ScaleDisplay.TickMajor.ForeColor = Color.Empty;
			ScaleDisplay.TickMajor.TextVisible = true;
			ScaleDisplay.TickMajor.TextMargin = 0;
			ScaleDisplay.TickMajor.Color = Color.Black;
			ScaleDisplay.TickMajor.Thickness = 1;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(128, 128);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			if (base.Loading)
			{
				return Size.Empty;
			}
			Graphics val = ((Control)this).CreateGraphics();
			PaintArgs p = new PaintArgs(val, base.InnerRectangle, Color.Empty);
			I_Display.CenterPoint = new Point(innerWidth / 2, innerHeight / 2);
			I_Display.Radius = InnerRadius;
			I_Display.HubRadius = Hub.Size;
			I_Display.Generate(p);
			val.Dispose();
			Size requiredSize = I_Display.RequiredSize;
			if (requiredSize.Width > requiredSize.Height)
			{
				return new Size(requiredSize.Width, requiredSize.Width);
			}
			return new Size(requiredSize.Height, requiredSize.Height);
		}

		protected override void ManualSizeFixup(int innerWidth, int innerHeight)
		{
			if (base.ManualSizeFixing)
			{
				return;
			}
			Graphics val = ((Control)this).CreateGraphics();
			PaintArgs p = new PaintArgs(val, base.InnerRectangle, Color.Empty);
			I_Display.CenterPoint = new Point(innerWidth / 2, innerHeight / 2);
			I_Display.Radius = InnerRadius;
			I_Display.Generate(p);
			Size requiredSize = I_Display.RequiredSize;
			int num = 0;
			for (int i = 0; i < innerWidth; i++)
			{
				I_Display.CenterPoint = new Point(innerWidth / 2, innerHeight / 2);
				I_Display.Radius = num;
				I_Display.Generate(p);
				requiredSize = I_Display.RequiredSize;
				if (requiredSize.Width >= innerWidth || requiredSize.Height >= innerHeight)
				{
					break;
				}
				num = i;
			}
			InnerRadius = num;
			val.Dispose();
			base.ManualSizeFixup(innerWidth, innerHeight);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == ScaleDisplay)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.GeneratorAuto)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.GeneratorFixed)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TickMid)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TickMajor)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TickMinor)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TextFormatting)
			{
				DoAutoSize();
			}
			if (sender == ScaleRange)
			{
				DoAutoSize();
			}
			if (sender == Hub)
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "InnerRadius")
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "Font")
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializePointers()
		{
			return Pointers.Count != 0;
		}

		private void ResetPointers()
		{
			Pointers.Reset();
		}

		private bool ShouldSerializeColorSections()
		{
			return true;
		}

		private void ResetColorSections()
		{
			ColorSections.Reset();
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeHub()
		{
			return ((ISubClassBase)Hub).ShouldSerialize();
		}

		private void ResetHub()
		{
			((ISubClassBase)Hub).ResetToDefault();
		}

		private bool ShouldSerializeScaleRange()
		{
			return ((ISubClassBase)ScaleRange).ShouldSerialize();
		}

		private void ResetScaleRange()
		{
			((ISubClassBase)ScaleRange).ResetToDefault();
		}

		private bool ShouldSerializeScaleDisplay()
		{
			return ((ISubClassBase)ScaleDisplay).ShouldSerialize();
		}

		private void ResetScaleDisplay()
		{
			((ISubClassBase)ScaleDisplay).ResetToDefault();
		}

		private bool ShouldSerializeInnerRadius()
		{
			return PropertyShouldSerialize("InnerRadius");
		}

		private void ResetInnerRadius()
		{
			PropertyReset("InnerRadius");
		}

		private void m_Pointers_ObjectAdded(object sender, ObjectEventArgs e)
		{
			(e.Object as PointerGaugeAngular).Value.Changing += OnValueBeforeChange;
			(e.Object as PointerGaugeAngular).Value.Changed += OnValueChanged;
		}

		private void m_Pointers_ObjectRemoved(object sender, ObjectEventArgs e)
		{
			(e.Object as PointerGaugeAngular).Value.Changing -= OnValueBeforeChange;
			(e.Object as PointerGaugeAngular).Value.Changed -= OnValueChanged;
		}

		private void OnValueChanged(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			p.Graphics.SmoothingMode = (SmoothingMode)4;
			if (ScaleDisplay.TextAlignment == StringAlignmentAngular.RadialInner || ScaleDisplay.TextAlignment == StringAlignmentAngular.RadialOuter)
			{
				p.Graphics.TextRenderingHint = (TextRenderingHint)4;
			}
			I_Display.CenterPoint = p.CenterPoint;
			I_Display.Radius = InnerRadius;
			I_Display.HubRadius = Hub.Size;
			I_Display.Generate(p);
			foreach (ColorSection colorSection in ColorSections)
			{
				if (colorSection.Visible)
				{
					double num = ScaleDisplay.ValueClamped(colorSection.Start);
					double num2 = ScaleDisplay.ValueClamped(colorSection.Stop);
					if (num != num2)
					{
						double num3 = I_Range.ValueToAngle(num);
						double num4 = I_Range.ValueToAngle(num2);
						p.Graphics.DrawGradientArc(colorSection.Color, (float)num3, (float)num4, I_Display.CenterPoint, InnerRadius + ScaleDisplay.Margin, ScaleDisplay.TickMajor.Length);
					}
				}
			}
			I_Display.Draw(p);
			foreach (IPointerGaugeAngular pointer in Pointers)
			{
				pointer.Draw(p, I_Display, I_Range);
			}
			if (Hub.Visible)
			{
				p.Graphics.FillCircle(I_Display.CenterPoint, I_Display.HubRadius, Hub.Color);
			}
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class GaugeAngularEditorPlugIn : PlugInStandard
	{
		private CheckBox AutoSizeCheckBox;

		private NumericUpDown InnerRadiusNumericUpDown;

		private FocusLabel label3;

		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private FocusLabel label2;

		private FocusLabel label1;

		private FontButton FontButton;

		private ColorPicker ForeColorPicker;

		private ColorPicker BackColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public GaugeAngularEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			FontButton = new FontButton();
			AutoSizeCheckBox = new CheckBox();
			InnerRadiusNumericUpDown = new NumericUpDown();
			label3 = new FocusLabel();
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			ForeColorPicker = new ColorPicker();
			label2 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			((Control)FontButton).Location = new Point(288, 96);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 3;
			((Control)AutoSizeCheckBox).Location = new Point(288, 152);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 6;
			AutoSizeCheckBox.Text = "Auto Size";
			((Control)InnerRadiusNumericUpDown).Location = new Point(136, 40);
			((NumericUpDown)InnerRadiusNumericUpDown).Maximum = new decimal(new int[4] { 0, 0, -2147483648, 0 });
			((Control)InnerRadiusNumericUpDown).Name = "InnerRadiusNumericUpDown";
			InnerRadiusNumericUpDown.PropertyName = "InnerRadius";
			((Control)InnerRadiusNumericUpDown).Size = new Size(48, 20);
			((Control)InnerRadiusNumericUpDown).TabIndex = 1;
			((UpDownBase)InnerRadiusNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)InnerRadiusNumericUpDown;
			((Control)label3).Location = new Point(66, 41);
			((Control)label3).Name = "label3";
			label3.Size = new Size(70, 15);
			label3.Text = "Inner Radius";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(87, 154);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((Control)RotationComboBox).Location = new Point(136, 152);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 5;
			((Control)ForeColorPicker).Location = new Point(136, 96);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(136, 21);
			((Control)ForeColorPicker).TabIndex = 2;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label2).Location = new Point(77, 99);
			((Control)label2).Name = "label2";
			label2.Size = new Size(59, 15);
			label2.Text = "Fore Color";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(136, 120);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 4;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(75, 123);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(136, 8);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(100, 10);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(176, 186);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(136, 184);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 7;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(32, 186);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)InnerRadiusNumericUpDown);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)label3);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Name = "GaugeAngularEditorPlugIn";
			((Control)this).Size = new Size(432, 216);
			base.Title = "Gauge Angular Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new PointerGaugeAngularCollectionEditorPlugIn(), "Pointers", sameLevel: false);
			AddSubPlugIn(new ColorSectionCollectionEditorPlugIn(), "Color Sections", sameLevel: false);
			AddSubPlugIn(new ScaleDisplayAngularEditorPlugIn(), "Scale Display", sameLevel: false);
			AddSubPlugIn(new ScaleRangeAngularEditorPlugIn(), "Scale Range", sameLevel: false);
			AddSubPlugIn(new HubEditorPlugIn(), "Hub", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as GaugeAngular).Pointers;
			base.SubPlugIns[1].Value = (base.Value as GaugeAngular).ColorSections;
			base.SubPlugIns[2].Value = (base.Value as GaugeAngular).ScaleDisplay;
			base.SubPlugIns[3].Value = (base.Value as GaugeAngular).ScaleRange;
			base.SubPlugIns[4].Value = (base.Value as GaugeAngular).Hub;
			base.SubPlugIns[5].Value = (base.Value as GaugeAngular).Border;
		}
	}
	public class GaugeLinearDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
			properties.Remove("CausesValidation");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[DefaultProperty("Name")]
	[DefaultEvent("ValueChanged")]
	[Designer(typeof(GaugeLinearDesigner))]
	[ToolboxBitmap(typeof(Access), "GaugeLinear.bmp")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[DesignerCategory("code")]
	[Description("GaugeLinear")]
	public class GaugeLinear : ControlBase
	{
		private ScaleRangeLinear m_ScaleRange;

		private IScaleRangeLinear I_Range;

		private ScaleDisplayLinear m_ScaleDisplay;

		private IScaleDisplayLinear I_Display;

		private PointerGaugeLinearCollection m_Pointers;

		private ColorSectionCollection m_ColorSections;

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[Description("")]
		public ValueDouble Value
		{
			get
			{
				if (Pointers.Count != 0)
				{
					return Pointers[0].Value;
				}
				return null;
			}
			set
			{
				if (Pointers.Count != 0)
				{
					Pointers[0].Value = value;
				}
			}
		}

		[Category("Iocomp")]
		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public PointerGaugeLinearCollection Pointers => m_Pointers;

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		public ColorSectionCollection ColorSections => m_ColorSections;

		[Description("")]
		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ScaleRangeLinear ScaleRange => m_ScaleRange;

		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		public ScaleDisplayLinear ScaleDisplay => m_ScaleDisplay;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new GaugeLinearEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Gauge Linear";
		}

		public GaugeLinear()
		{
			m_License = LicenseManager.Validate(typeof(GaugeLinear), this);
			DoCreate();
		}

		~GaugeLinear()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Pointers = new PointerGaugeLinearCollection(this);
			m_ColorSections = new ColorSectionCollection(this);
			m_ScaleRange = new ScaleRangeLinear();
			AddSubClass(ScaleRange);
			I_Range = ScaleRange;
			m_ScaleDisplay = new ScaleDisplayLinear();
			AddSubClass(ScaleDisplay);
			I_Display = ScaleDisplay;
			I_Display.Range = m_ScaleRange;
			m_Pointers.ObjectAdded += m_Pointers_ObjectAdded;
			m_Pointers.ObjectRemoved += m_Pointers_ObjectRemoved;
		}

		protected override void SetComponentDefaults()
		{
			ColorSections.Reset();
			Pointers.Reset();
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			ScaleRange.Span = 100.0;
			ScaleRange.Min = 0.0;
			ScaleRange.Reverse = false;
			ScaleDisplay.GeneratorAuto.DesiredIncrement = 0.0;
			ScaleDisplay.GeneratorAuto.MinTextSpacing = 1.0;
			ScaleDisplay.GeneratorAuto.MinorCount = 4;
			ScaleDisplay.GeneratorAuto.MidIncluded = false;
			ScaleDisplay.GeneratorFixed.MinorCount = 4;
			ScaleDisplay.GeneratorFixed.MidIncluded = false;
			ScaleDisplay.GeneratorFixed.MajorCount = 6;
			ScaleDisplay.AntiAliasEnabled = false;
			ScaleDisplay.GeneratorStyle = ScaleGeneratorStyle.Auto;
			ScaleDisplay.Direction = SideDirection.LeftToRight;
			ScaleDisplay.Margin = 0;
			ScaleDisplay.StartRefValue = 0.0;
			ScaleDisplay.StartRefEnabled = false;
			ScaleDisplay.TextRotation = TextRotation.X000;
			ScaleDisplay.TextAlignment = (StringAlignment)0;
			ScaleDisplay.TextWidthMinValue = 0.0;
			ScaleDisplay.TextWidthMinAuto = false;
			ScaleDisplay.LineInnerVisible = false;
			ScaleDisplay.LineOuterVisible = true;
			ScaleDisplay.Visible = true;
			ScaleDisplay.TextFormatting.Precision = 1;
			ScaleDisplay.TextFormatting.PrecisionStyle = PrecisionStyle.FixedDecimalPoints;
			ScaleDisplay.TextFormatting.UnitsText = "";
			ScaleDisplay.TextFormatting.Style = TextFormatDoubleStyle.Number;
			ScaleDisplay.TextFormatting.DateTimeFormat = "hh:mm:ss";
			ScaleDisplay.TickMinor.Alignment = AlignmentStyle.Near;
			ScaleDisplay.TickMinor.Length = 3;
			ScaleDisplay.TickMinor.Color = Color.Black;
			ScaleDisplay.TickMinor.Thickness = 1;
			ScaleDisplay.TickMid.Length = 5;
			ScaleDisplay.TickMid.Font = null;
			ScaleDisplay.TickMid.ForeColor = Color.Empty;
			ScaleDisplay.TickMid.TextVisible = true;
			ScaleDisplay.TickMid.TextMargin = 2;
			ScaleDisplay.TickMid.Alignment = AlignmentStyle.Near;
			ScaleDisplay.TickMid.Color = Color.Black;
			ScaleDisplay.TickMid.Thickness = 1;
			ScaleDisplay.TickMajor.Length = 10;
			ScaleDisplay.TickMajor.Font = null;
			ScaleDisplay.TickMajor.ForeColor = Color.Empty;
			ScaleDisplay.TickMajor.TextVisible = true;
			ScaleDisplay.TickMajor.TextMargin = 2;
			ScaleDisplay.TickMajor.Color = Color.Black;
			ScaleDisplay.TickMajor.Thickness = 1;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(56, 200);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			if (base.Loading)
			{
				return Size.Empty;
			}
			Graphics val = ((Control)this).CreateGraphics();
			PaintArgs p = new PaintArgs(val, base.InnerRectangle, Color.Empty);
			I_Display.SetClipEnds(0, innerHeight);
			I_Display.SetBoundsEnds(0, innerHeight);
			I_Display.Generate(p);
			val.Dispose();
			float num = I_Display.MaxDepth + ScaleDisplay.Margin + Pointers.GetMaxScaleOverlap(ScaleDisplay);
			return new Size((int)num, 0);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == ScaleDisplay)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.GeneratorAuto)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.GeneratorFixed)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TickMid)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TickMajor)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TickMinor)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TextFormatting)
			{
				DoAutoSize();
			}
			if (sender == ScaleRange)
			{
				DoAutoSize();
			}
			if (sender is PointerGaugeLinear)
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "Font")
			{
				DoAutoSize();
			}
			if (sender == Pointers)
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializePointers()
		{
			return Pointers.Count != 0;
		}

		private void ResetPointers()
		{
			Pointers.Reset();
		}

		private bool ShouldSerializeColorSections()
		{
			return true;
		}

		private void ResetColorSections()
		{
			ColorSections.Reset();
		}

		private bool ShouldSerializeScaleRange()
		{
			return ((ISubClassBase)ScaleRange).ShouldSerialize();
		}

		private void ResetScaleRange()
		{
			((ISubClassBase)ScaleRange).ResetToDefault();
		}

		private bool ShouldSerializeScaleDisplay()
		{
			return ((ISubClassBase)ScaleDisplay).ShouldSerialize();
		}

		private void ResetScaleDisplay()
		{
			((ISubClassBase)ScaleDisplay).ResetToDefault();
		}

		private void m_Pointers_ObjectAdded(object sender, ObjectEventArgs e)
		{
			(e.Object as PointerGaugeLinear).Value.Changing += OnValueBeforeChange;
			(e.Object as PointerGaugeLinear).Value.Changed += OnValueChanged;
		}

		private void m_Pointers_ObjectRemoved(object sender, ObjectEventArgs e)
		{
			(e.Object as PointerGaugeLinear).Value.Changing -= OnValueBeforeChange;
			(e.Object as PointerGaugeLinear).Value.Changed -= OnValueChanged;
		}

		private void OnValueChanged(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			p.Graphics.SmoothingMode = (SmoothingMode)4;
			int maxScaleOverlap = Pointers.GetMaxScaleOverlap(ScaleDisplay);
			if (ScaleDisplay.Direction == SideDirection.LeftToRight)
			{
				I_Display.EdgeRef = p.Left + maxScaleOverlap + ScaleDisplay.Margin;
			}
			else
			{
				I_Display.EdgeRef = p.Right - maxScaleOverlap - ScaleDisplay.Margin;
			}
			I_Display.SetClipEnds(p.Top, p.Bottom);
			I_Display.SetBoundsEnds(p.Top, p.Bottom);
			I_Display.Generate(p);
			foreach (ColorSection colorSection in ColorSections)
			{
				if (colorSection.Visible)
				{
					I_Display.DrawColorBar(p, colorSection.Start, colorSection.Stop, colorSection.Color);
				}
			}
			foreach (PointerGaugeLinear pointer in Pointers)
			{
				if (pointer.Style != PointerStyleGauge.TLine)
				{
					((IPointerGaugeLinear)pointer).Draw(p, ScaleDisplay);
				}
			}
			I_Display.Draw(p);
			p.Graphics.SmoothingMode = (SmoothingMode)0;
			foreach (PointerGaugeLinear pointer2 in Pointers)
			{
				if (pointer2.Style == PointerStyleGauge.TLine)
				{
					((IPointerGaugeLinear)pointer2).Draw(p, ScaleDisplay);
				}
			}
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class GaugeLinearEditorPlugIn : PlugInStandard
	{
		private CheckBox AutoSizeCheckBox;

		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private FocusLabel label2;

		private FocusLabel label1;

		private FontButton FontButton;

		private ColorPicker ForeColorPicker;

		private ColorPicker BackColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public GaugeLinearEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			FontButton = new FontButton();
			AutoSizeCheckBox = new CheckBox();
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			ForeColorPicker = new ColorPicker();
			label2 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			((Control)FontButton).Location = new Point(296, 72);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 2;
			((Control)AutoSizeCheckBox).Location = new Point(296, 128);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 5;
			AutoSizeCheckBox.Text = "Auto Size";
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(95, 130);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((Control)RotationComboBox).Location = new Point(144, 128);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 4;
			((Control)ForeColorPicker).Location = new Point(144, 72);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(136, 21);
			((Control)ForeColorPicker).TabIndex = 1;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label2).Location = new Point(85, 75);
			((Control)label2).Name = "label2";
			label2.Size = new Size(59, 15);
			label2.Text = "Fore Color";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(144, 96);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 3;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(83, 99);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(144, 8);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(108, 10);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(184, 162);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(144, 160);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 6;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(40, 162);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Name = "GaugeLinearEditorPlugIn";
			((Control)this).Size = new Size(448, 208);
			base.Title = "Gauge Linear Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new PointerGaugeLinearCollectionEditorPlugIn(), "Pointers", sameLevel: false);
			AddSubPlugIn(new ColorSectionCollectionEditorPlugIn(), "Color Sections", sameLevel: false);
			AddSubPlugIn(new ScaleDisplayLinearEditorPlugIn(), "Scale Display", sameLevel: false);
			AddSubPlugIn(new ScaleRangeLinearEditorPlugIn(), "Scale Range", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as GaugeLinear).Pointers;
			base.SubPlugIns[1].Value = (base.Value as GaugeLinear).ColorSections;
			base.SubPlugIns[2].Value = (base.Value as GaugeLinear).ScaleDisplay;
			base.SubPlugIns[3].Value = (base.Value as GaugeLinear).ScaleRange;
			base.SubPlugIns[4].Value = (base.Value as GaugeLinear).Border;
		}
	}
}
namespace Iocomp.Classes
{
	[Description("Contains the properties that control the appearance for the indicator.")]
	[DefaultProperty("Height")]
	public sealed class IndicatorSwitchLed : Indicator
	{
		private AlignmentQuadSide m_Alignment;

		private int m_Height;

		private int m_MarginOffset;

		private int m_MarginSides;

		[RefreshProperties(RefreshProperties.All)]
		[Description("Specifies the indicator height in pixels.")]
		public int Height
		{
			get
			{
				return m_Height;
			}
			set
			{
				PropertyUpdateDefault("Height", value);
				if (Height != value)
				{
					m_Height = value;
					DoPropertyChange(this, "Height");
				}
			}
		}

		[Description("Indicates the indicators alignment position.")]
		[RefreshProperties(RefreshProperties.All)]
		public AlignmentQuadSide Alignment
		{
			get
			{
				return m_Alignment;
			}
			set
			{
				PropertyUpdateDefault("Alignment", value);
				if (Alignment != value)
				{
					m_Alignment = value;
					DoPropertyChange(this, "Alignment");
				}
			}
		}

		[Description("Specifies the indicator's offset margin.")]
		[RefreshProperties(RefreshProperties.All)]
		public int MarginOffset
		{
			get
			{
				return m_MarginOffset;
			}
			set
			{
				PropertyUpdateDefault("MarginOffset", value);
				if (MarginOffset != value)
				{
					m_MarginOffset = value;
					DoPropertyChange(this, "MarginOffset");
				}
			}
		}

		[RefreshProperties(RefreshProperties.All)]
		[Description("Specifies the indicator's side margins.")]
		public int MarginSides
		{
			get
			{
				return m_MarginSides;
			}
			set
			{
				PropertyUpdateDefault("MarginSides", value);
				if (MarginSides != value)
				{
					m_MarginSides = value;
					DoPropertyChange(this, "MarginSides");
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new IndicatorSwitchLedEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Indicator";
		}

		public IndicatorSwitchLed()
		{
			DoCreate();
		}

		private bool ShouldSerializeHeight()
		{
			return PropertyShouldSerialize("Height");
		}

		private void ResetHeight()
		{
			PropertyReset("Height");
		}

		private bool ShouldSerializeAlignment()
		{
			return PropertyShouldSerialize("Alignment");
		}

		private void ResetAlignment()
		{
			PropertyReset("Alignment");
		}

		private bool ShouldSerializeMarginOffset()
		{
			return PropertyShouldSerialize("MarginOffset");
		}

		private void ResetMarginOffset()
		{
			PropertyReset("MarginOffset");
		}

		private bool ShouldSerializeMarginSides()
		{
			return PropertyShouldSerialize("MarginSides");
		}

		private void ResetMarginSides()
		{
			PropertyReset("MarginSides");
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class IndicatorSwitchLedEditorPlugIn : PlugInStandard
	{
		private GroupBox groupBox2;

		private FocusLabel label6;

		private FocusLabel label7;

		private ColorPicker ColorActiveColorPicker;

		private NumericUpDown HeightNumericUpDown;

		private FocusLabel label1;

		private ComboBox AlignmentComboBox;

		private FocusLabel label4;

		private GroupBox groupBox1;

		private NumericUpDown MarginOffsetNumericUpDown;

		private FocusLabel label2;

		private NumericUpDown MarginSidesNumericUpDown;

		private FocusLabel label3;

		private ColorPicker ColorInactiveColorPicker;

		private CheckBox ColorInactiveAutoCheckBox;

		private Container components = null;

		public IndicatorSwitchLedEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			//IL_006f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0079: Expected O, but got Unknown
			groupBox2 = new GroupBox();
			label6 = new FocusLabel();
			ColorInactiveColorPicker = new ColorPicker();
			label7 = new FocusLabel();
			ColorActiveColorPicker = new ColorPicker();
			ColorInactiveAutoCheckBox = new CheckBox();
			HeightNumericUpDown = new NumericUpDown();
			label1 = new FocusLabel();
			AlignmentComboBox = new ComboBox();
			label4 = new FocusLabel();
			groupBox1 = new GroupBox();
			MarginSidesNumericUpDown = new NumericUpDown();
			label3 = new FocusLabel();
			MarginOffsetNumericUpDown = new NumericUpDown();
			label2 = new FocusLabel();
			((Control)groupBox2).SuspendLayout();
			((Control)groupBox1).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)groupBox2).Controls.Add((Control)(object)label6);
			((Control)groupBox2).Controls.Add((Control)(object)label7);
			((Control)groupBox2).Controls.Add((Control)(object)ColorInactiveColorPicker);
			((Control)groupBox2).Controls.Add((Control)(object)ColorActiveColorPicker);
			((Control)groupBox2).Controls.Add((Control)(object)ColorInactiveAutoCheckBox);
			((Control)groupBox2).Location = new Point(16, 64);
			((Control)groupBox2).Name = "groupBox2";
			((Control)groupBox2).Size = new Size(216, 104);
			((Control)groupBox2).TabIndex = 2;
			groupBox2.TabStop = false;
			((Control)groupBox2).Text = "Color";
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)ColorInactiveColorPicker;
			((Control)label6).Location = new Point(11, 51);
			((Control)label6).Name = "label6";
			label6.Size = new Size(45, 15);
			label6.Text = "Inactive";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((Control)ColorInactiveColorPicker).Location = new Point(56, 48);
			((Control)ColorInactiveColorPicker).Name = "ColorInactiveColorPicker";
			ColorInactiveColorPicker.PropertyName = "ColorInactive";
			((Control)ColorInactiveColorPicker).Size = new Size(144, 21);
			((Control)ColorInactiveColorPicker).TabIndex = 1;
			label7.LoadingBegin();
			label7.FocusControl = (Control)(object)ColorActiveColorPicker;
			((Control)label7).Location = new Point(18, 27);
			((Control)label7).Name = "label7";
			label7.Size = new Size(38, 15);
			label7.Text = "Active";
			label7.UpdateFrameRate = 50.0;
			label7.LoadingEnd();
			((Control)ColorActiveColorPicker).Location = new Point(56, 24);
			((Control)ColorActiveColorPicker).Name = "ColorActiveColorPicker";
			ColorActiveColorPicker.PropertyName = "ColorActive";
			((Control)ColorActiveColorPicker).Size = new Size(144, 21);
			((Control)ColorActiveColorPicker).TabIndex = 0;
			((Control)ColorInactiveAutoCheckBox).Location = new Point(56, 72);
			((Control)ColorInactiveAutoCheckBox).Name = "ColorInactiveAutoCheckBox";
			ColorInactiveAutoCheckBox.PropertyName = "ColorInactiveAuto";
			((Control)ColorInactiveAutoCheckBox).Size = new Size(120, 24);
			((Control)ColorInactiveAutoCheckBox).TabIndex = 2;
			ColorInactiveAutoCheckBox.Text = "Inactive Auto";
			((Control)HeightNumericUpDown).Location = new Point(56, 16);
			((NumericUpDown)HeightNumericUpDown).Maximum = new decimal(new int[4] { 1000, 0, 0, 0 });
			((Control)HeightNumericUpDown).Name = "HeightNumericUpDown";
			HeightNumericUpDown.PropertyName = "Height";
			((Control)HeightNumericUpDown).Size = new Size(48, 20);
			((Control)HeightNumericUpDown).TabIndex = 0;
			((UpDownBase)HeightNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)HeightNumericUpDown;
			((Control)label1).Location = new Point(17, 17);
			((Control)label1).Name = "label1";
			label1.Size = new Size(39, 15);
			label1.Text = "Height";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((ComboBox)AlignmentComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)AlignmentComboBox).Location = new Point(256, 16);
			((Control)AlignmentComboBox).Name = "AlignmentComboBox";
			AlignmentComboBox.PropertyName = "Alignment";
			((Control)AlignmentComboBox).Size = new Size(121, 21);
			((Control)AlignmentComboBox).TabIndex = 1;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)AlignmentComboBox;
			((Control)label4).Location = new Point(199, 18);
			((Control)label4).Name = "label4";
			label4.Size = new Size(57, 15);
			label4.Text = "Alignment";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)groupBox1).Controls.Add((Control)(object)MarginSidesNumericUpDown);
			((Control)groupBox1).Controls.Add((Control)(object)label3);
			((Control)groupBox1).Controls.Add((Control)(object)MarginOffsetNumericUpDown);
			((Control)groupBox1).Controls.Add((Control)(object)label2);
			((Control)groupBox1).Location = new Point(256, 64);
			((Control)groupBox1).Name = "groupBox1";
			((Control)groupBox1).Size = new Size(112, 80);
			((Control)groupBox1).TabIndex = 3;
			groupBox1.TabStop = false;
			((Control)groupBox1).Text = "Margin";
			((Control)MarginSidesNumericUpDown).Location = new Point(56, 48);
			((NumericUpDown)MarginSidesNumericUpDown).Maximum = new decimal(new int[4] { 0, 0, -2147483648, 0 });
			((Control)MarginSidesNumericUpDown).Name = "MarginSidesNumericUpDown";
			MarginSidesNumericUpDown.PropertyName = "MarginSides";
			((Control)MarginSidesNumericUpDown).Size = new Size(48, 20);
			((Control)MarginSidesNumericUpDown).TabIndex = 1;
			((UpDownBase)MarginSidesNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)MarginSidesNumericUpDown;
			((Control)label3).Location = new Point(21, 49);
			((Control)label3).Name = "label3";
			label3.Size = new Size(35, 15);
			label3.Text = "Sides";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			((Control)MarginOffsetNumericUpDown).Location = new Point(56, 24);
			((NumericUpDown)MarginOffsetNumericUpDown).Maximum = new decimal(new int[4] { 0, 0, -2147483648, 0 });
			((Control)MarginOffsetNumericUpDown).Name = "MarginOffsetNumericUpDown";
			MarginOffsetNumericUpDown.PropertyName = "MarginOffset";
			((Control)MarginOffsetNumericUpDown).Size = new Size(48, 20);
			((Control)MarginOffsetNumericUpDown).TabIndex = 0;
			((UpDownBase)MarginOffsetNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)MarginOffsetNumericUpDown;
			((Control)label2).Location = new Point(19, 25);
			((Control)label2).Name = "label2";
			label2.Size = new Size(37, 15);
			label2.Text = "Offset";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)groupBox1);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)AlignmentComboBox);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)HeightNumericUpDown);
			((Control)this).Controls.Add((Control)(object)groupBox2);
			((Control)this).Location = new Point(10, 20);
			((Control)this).Name = "IndicatorSwitchLedEditorPlugIn";
			((Control)this).Size = new Size(488, 200);
			base.Title = "Indicator Editor";
			((Control)groupBox2).ResumeLayout(false);
			((Control)groupBox1).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	public class IocompLicenseProviderStd : IocompLicenseProvider
	{
		protected override bool LicenseKeyValid(Type type, string licensekey)
		{
			HashAlgorithm hashAlgorithm = HashAlgorithm.Create("SHA1");
			byte[] array = hashAlgorithm.ComputeHash(Encoding.Default.GetBytes(licensekey));
			string text = BitConverter.ToString(array);
			if ((object)type == typeof(DisplayDouble) && text == "60-F3-B7-AB-3C-F3-71-ED-69-F8-36-CE-CD-E6-A9-08-9E-15-F1-E0")
			{
				return true;
			}
			if ((object)type == typeof(DisplayInteger) && text == "8F-B6-F5-6C-AE-00-1D-4D-7B-CD-9C-94-A3-D3-27-71-D7-33-58-1E")
			{
				return true;
			}
			if ((object)type == typeof(DisplayString) && text == "91-76-87-37-BC-E9-77-C4-DA-56-97-1D-61-65-AE-76-83-42-DD-56")
			{
				return true;
			}
			if ((object)type == typeof(EditDouble) && text == "CC-4B-C2-94-73-46-77-BB-87-C2-31-97-E3-8E-61-80-82-FC-59-28")
			{
				return true;
			}
			if ((object)type == typeof(EditInteger) && text == "2B-A7-39-A4-A4-90-91-C0-FD-58-35-EF-28-C8-A8-8E-BA-E4-10-96")
			{
				return true;
			}
			if ((object)type == typeof(EditString) && text == "3B-0F-E9-90-3A-52-5F-6F-97-3A-B0-E0-A6-90-66-78-0E-D8-98-12")
			{
				return true;
			}
			if ((object)type == typeof(GaugeAngular) && text == "82-BA-0C-46-E4-B8-0C-5E-DF-19-CE-78-DA-8A-80-6E-0C-49-B0-58")
			{
				return true;
			}
			if ((object)type == typeof(GaugeLinear) && text == "D0-7B-49-11-24-4E-64-D3-6E-BF-22-DA-6B-65-F5-C0-35-EF-D0-06")
			{
				return true;
			}
			if ((object)type == typeof(Knob) && text == "41-D6-AF-F9-B2-EB-27-D6-4F-A2-84-10-2E-8E-3E-C4-B3-AF-1B-9F")
			{
				return true;
			}
			if ((object)type == typeof(Label) && text == "EC-71-4E-BD-41-CF-8D-91-8C-F5-D2-8D-8A-F5-5D-C1-56-A1-1F-F7")
			{
				return true;
			}
			if ((object)type == typeof(Led) && text == "A8-37-1D-5B-C2-7C-9E-28-7E-82-AB-EA-31-CB-FA-A2-F1-15-75-F4")
			{
				return true;
			}
			if ((object)type == typeof(LedBar) && text == "B0-88-C7-F7-59-2B-70-2D-A5-AB-2B-90-1F-7A-81-18-A5-DF-DD-E8")
			{
				return true;
			}
			if ((object)type == typeof(LedSpiral) && text == "5C-4D-23-42-E8-B7-F0-4C-D5-8D-A9-EF-63-45-13-DF-16-CC-59-E1")
			{
				return true;
			}
			if ((object)type == typeof(ModeComboBox) && text == "62-02-69-13-2D-1A-25-27-7D-53-E4-70-73-F3-8D-D2-A8-70-4E-30")
			{
				return true;
			}
			if ((object)type == typeof(Odometer) && text == "4D-9E-D6-F0-8B-9B-C5-D6-82-FF-C1-5A-B1-87-C6-1A-DA-E9-3B-91")
			{
				return true;
			}
			if ((object)type == typeof(SevenSegmentAnalog) && text == "BC-E5-8E-C7-9B-40-CF-84-CF-40-E6-E5-BF-99-40-25-9E-A6-58-16")
			{
				return true;
			}
			if ((object)type == typeof(SevenSegmentBinary) && text == "DD-AF-30-34-95-17-71-27-21-46-B0-01-5F-F5-5D-A3-04-1C-A8-B6")
			{
				return true;
			}
			if ((object)type == typeof(SevenSegmentCharacter) && text == "DB-95-89-80-2D-B6-3B-C9-E1-78-52-4A-E3-82-FE-8E-3D-7D-E8-C5")
			{
				return true;
			}
			if ((object)type == typeof(SevenSegmentClock) && text == "9E-77-9C-FF-78-31-28-01-AB-B9-12-4D-F4-F9-6B-9C-E0-28-78-5D")
			{
				return true;
			}
			if ((object)type == typeof(SevenSegmentHexadecimal) && text == "54-F0-06-08-48-51-20-03-BF-66-E2-14-27-4D-F1-1D-DF-B1-D7-CC")
			{
				return true;
			}
			if ((object)type == typeof(SevenSegmentInteger) && text == "92-0A-8F-D7-5D-D5-D7-78-83-38-E8-37-3F-88-CB-36-F3-CC-29-7E")
			{
				return true;
			}
			if ((object)type == typeof(Slider) && text == "6B-B7-FE-22-F0-03-25-07-60-C8-C7-2B-CD-50-9E-D1-31-33-45-DD")
			{
				return true;
			}
			if ((object)type == typeof(SwitchLed) && text == "25-71-5E-34-C8-E2-FF-1E-A5-83-00-85-56-AD-6D-D6-3E-6D-72-1C")
			{
				return true;
			}
			if ((object)type == typeof(SwitchPanel) && text == "8E-20-E8-97-44-F7-FD-AD-2A-FC-EE-E0-C7-4F-3D-29-5C-C5-FD-76")
			{
				return true;
			}
			if ((object)type == typeof(SwitchRotary) && text == "C5-AD-DC-FD-D5-DA-E3-1D-13-DF-E2-B4-BB-55-57-FE-81-50-C6-42")
			{
				return true;
			}
			if ((object)type == typeof(SwitchSlider) && text == "51-8E-4F-E1-1A-24-52-4B-16-70-97-29-03-8C-F8-F3-5A-6A-2E-95")
			{
				return true;
			}
			if ((object)type == typeof(SwitchToggle) && text == "48-8C-0D-66-2E-7B-7A-D4-4A-BC-D5-60-A0-DE-53-E8-B4-D6-EB-0C")
			{
				return true;
			}
			if ((object)type == typeof(Thermometer) && text == "91-F9-D2-4F-B1-14-61-16-BA-75-A6-52-10-2C-95-DE-89-26-38-1A")
			{
				return true;
			}
			return false;
		}
	}
}
namespace Iocomp.Design
{
	public class KnobDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[DefaultEvent("ValueChanged")]
	[ToolboxBitmap(typeof(Access), "Knob.bmp")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[Description("Knob")]
	[Designer(typeof(KnobDesigner))]
	[DefaultProperty("Name")]
	[DesignerCategory("code")]
	public class Knob : ControlBase
	{
		private ValueDouble m_Value;

		private KnobBody m_Body;

		private KnobOffSwitch m_OffSwitch;

		private PointerKnob m_Pointer;

		private ScaleRangeAngular m_ScaleRange;

		private IScaleRangeAngular I_Range;

		private ScaleDisplayAngular m_ScaleDisplay;

		private IScaleDisplayAngular I_Display;

		private UIControlKnob m_UIControl;

		private Point m_CenterPoint;

		private double m_MouseDownAngle;

		private bool m_MouseDownOffSwitch;

		[Category("Iocomp")]
		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Bindable(true)]
		public ValueDouble Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsDouble = value.AsDouble;
			}
		}

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("Body properties")]
		public KnobBody Body => m_Body;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		[Description("Off-Switch properties")]
		public KnobOffSwitch OffSwitch => m_OffSwitch;

		[Category("Iocomp")]
		[Description("Pointer properties")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public PointerKnob Pointer => m_Pointer;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("UIControl properties")]
		[Category("Iocomp")]
		public UIControlKnob UIControl => m_UIControl;

		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		public ScaleRangeAngular ScaleRange => m_ScaleRange;

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		public ScaleDisplayAngular ScaleDisplay => m_ScaleDisplay;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new KnobEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Knob";
		}

		public Knob()
		{
			m_License = LicenseManager.Validate(typeof(Knob), this);
			DoCreate();
		}

		~Knob()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Value = new ValueDouble();
			AddSubClass(Value);
			m_Body = new KnobBody();
			AddSubClass(Body);
			m_OffSwitch = new KnobOffSwitch();
			AddSubClass(OffSwitch);
			m_Pointer = new PointerKnob();
			AddSubClass(Pointer);
			m_ScaleRange = new ScaleRangeAngular();
			AddSubClass(ScaleRange);
			I_Range = ScaleRange;
			m_ScaleDisplay = new ScaleDisplayAngular();
			AddSubClass(ScaleDisplay);
			I_Display = ScaleDisplay;
			m_UIControl = new UIControlKnob();
			AddSubClass(UIControl);
			I_Display.Range = m_ScaleRange;
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			Body.Radius = 33;
			Body.EdgeWidth = 3;
			Body.Style = KnobBodyStyle.Raised;
			Body.Color = Color.Empty;
			OffSwitch.Enabled = false;
			OffSwitch.On = true;
			OffSwitch.ColorOn = Color.Lime;
			OffSwitch.ColorOff = Color.Red;
			OffSwitch.Size = 5;
			OffSwitch.Margin = 2;
			OffSwitch.OffsetAngle = 20;
			Pointer.Color = Color.Red;
			Pointer.Margin = 5;
			Pointer.Size = 5;
			Pointer.Style = PointerStyleKnob.DotSunken;
			ScaleRange.AngleMin = 225.0;
			ScaleRange.AngleSpan = 270.0;
			ScaleRange.Span = 100.0;
			ScaleRange.Min = 0.0;
			ScaleRange.Reverse = false;
			ScaleDisplay.GeneratorAuto.DesiredIncrement = 0.0;
			ScaleDisplay.GeneratorAuto.MinTextSpacing = 1.0;
			ScaleDisplay.GeneratorAuto.MinorCount = 4;
			ScaleDisplay.GeneratorAuto.MidIncluded = false;
			ScaleDisplay.GeneratorFixed.MinorCount = 4;
			ScaleDisplay.GeneratorFixed.MidIncluded = false;
			ScaleDisplay.GeneratorFixed.MajorCount = 6;
			ScaleDisplay.GeneratorStyle = ScaleGeneratorStyle.Auto;
			ScaleDisplay.StartRefValue = 0.0;
			ScaleDisplay.StartRefEnabled = false;
			ScaleDisplay.TextAlignment = StringAlignmentAngular.Center;
			ScaleDisplay.Margin = 2;
			ScaleDisplay.TextWidthMinValue = 0.0;
			ScaleDisplay.TextWidthMinAuto = false;
			ScaleDisplay.LineInnerVisible = false;
			ScaleDisplay.LineOuterVisible = false;
			ScaleDisplay.Visible = true;
			ScaleDisplay.TextFormatting.Precision = 1;
			ScaleDisplay.TextFormatting.PrecisionStyle = PrecisionStyle.FixedDecimalPoints;
			ScaleDisplay.TextFormatting.UnitsText = "";
			ScaleDisplay.TextFormatting.Style = TextFormatDoubleStyle.Number;
			ScaleDisplay.TextFormatting.DateTimeFormat = "hh:mm:ss";
			ScaleDisplay.TickMinor.Alignment = AlignmentStyle.Center;
			ScaleDisplay.TickMinor.Length = 3;
			ScaleDisplay.TickMinor.Color = Color.Black;
			ScaleDisplay.TickMinor.Thickness = 1;
			ScaleDisplay.TickMid.Length = 5;
			ScaleDisplay.TickMid.Font = null;
			ScaleDisplay.TickMid.ForeColor = Color.Empty;
			ScaleDisplay.TickMid.TextVisible = true;
			ScaleDisplay.TickMid.TextMargin = 2;
			ScaleDisplay.TickMid.Alignment = AlignmentStyle.Near;
			ScaleDisplay.TickMid.Color = Color.Black;
			ScaleDisplay.TickMid.Thickness = 1;
			ScaleDisplay.TickMajor.Length = 12;
			ScaleDisplay.TickMajor.Font = null;
			ScaleDisplay.TickMajor.ForeColor = Color.Empty;
			ScaleDisplay.TickMajor.TextVisible = true;
			ScaleDisplay.TickMajor.TextMargin = 0;
			ScaleDisplay.TickMajor.Color = Color.Black;
			ScaleDisplay.TickMajor.Thickness = 1;
			UIControl.MouseControlStyle = MouseControlStyleKnob.DragToDestination;
			UIControl.KeyboardEnabled = true;
			UIControl.FocusRectangleShow = true;
			UIControl.MouseWheelEnabled = true;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(157, 120);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			if (base.Loading)
			{
				return Size.Empty;
			}
			Graphics val = ((Control)this).CreateGraphics();
			PaintArgs p = new PaintArgs(val, base.InnerRectangle, Color.Empty);
			I_Display.CenterPoint = new Point(innerWidth / 2, innerHeight / 2);
			I_Display.Radius = Body.Radius;
			I_Display.Generate(p);
			val.Dispose();
			return I_Display.RequiredSize;
		}

		protected override void ManualSizeFixup(int innerWidth, int innerHeight)
		{
			Graphics val = ((Control)this).CreateGraphics();
			PaintArgs p = new PaintArgs(val, base.InnerRectangle, Color.Empty);
			I_Display.CenterPoint = new Point(innerWidth / 2, innerHeight / 2);
			I_Display.Radius = Body.Radius;
			I_Display.Generate(p);
			Size requiredSize = I_Display.RequiredSize;
			int radius = 0;
			for (int i = 0; i < innerWidth; i++)
			{
				I_Display.CenterPoint = new Point(innerWidth / 2, innerHeight / 2);
				I_Display.Radius = radius;
				I_Display.Generate(p);
				requiredSize = I_Display.RequiredSize;
				if (requiredSize.Width >= innerWidth || requiredSize.Height >= innerHeight)
				{
					break;
				}
				radius = i;
			}
			Body.Radius = radius;
			val.Dispose();
			base.ManualSizeFixup(innerWidth, innerHeight);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == ScaleDisplay)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.GeneratorAuto)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.GeneratorFixed)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TickMid)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TickMajor)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TickMinor)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TextFormatting)
			{
				DoAutoSize();
			}
			if (sender == ScaleRange)
			{
				DoAutoSize();
			}
			if (sender == Body)
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "Font")
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeBody()
		{
			return ((ISubClassBase)Body).ShouldSerialize();
		}

		private void ResetBody()
		{
			((ISubClassBase)Body).ResetToDefault();
		}

		private bool ShouldSerializeOffSwitch()
		{
			return ((ISubClassBase)OffSwitch).ShouldSerialize();
		}

		private void ResetOffSwitch()
		{
			((ISubClassBase)OffSwitch).ResetToDefault();
		}

		private bool ShouldSerializePointer()
		{
			return ((ISubClassBase)Pointer).ShouldSerialize();
		}

		private void ResetPointer()
		{
			((ISubClassBase)Pointer).ResetToDefault();
		}

		private bool ShouldSerializeUIControl()
		{
			return ((ISubClassBase)UIControl).ShouldSerialize();
		}

		private void ResetUIControl()
		{
			((ISubClassBase)UIControl).ResetToDefault();
		}

		private bool ShouldSerializeScaleRange()
		{
			return ((ISubClassBase)ScaleRange).ShouldSerialize();
		}

		private void ResetScaleRange()
		{
			((ISubClassBase)ScaleRange).ResetToDefault();
		}

		private bool ShouldSerializeScaleDisplay()
		{
			return ((ISubClassBase)ScaleDisplay).ShouldSerialize();
		}

		private void ResetScaleDisplay()
		{
			((ISubClassBase)ScaleDisplay).ResetToDefault();
		}

		private double MouseToValue(MouseEventArgs e)
		{
			double num = Math2.PointToAngle(m_CenterPoint, e.X, e.Y);
			double value = ScaleRange.AngleToValue((float)num);
			return ScaleDisplay.ValueClamped(value);
		}

		protected override void InternalOnMouseLeft(MouseEventArgs e)
		{
			base.IsMouseDown = true;
			((Control)this).Focus();
			m_MouseDownAngle = Math2.PointToAngle(m_CenterPoint, e.X, e.Y);
			if (OffSwitch.Enabled && OffSwitch.HitRectangle.Contains(e.X, e.Y))
			{
				m_MouseDownOffSwitch = true;
			}
			else
			{
				m_MouseDownOffSwitch = false;
			}
			InternalOnMouseMove(e);
		}

		protected override void InternalOnMouseMove(MouseEventArgs e)
		{
			if (m_MouseDownOffSwitch || !base.IsMouseDown)
			{
				return;
			}
			double num = I_Range.ValueToAngle(ScaleDisplay.ValueClamped(ScaleRange.Min));
			_ = OffSwitch.OffsetAngle;
			if (UIControl.MouseControlStyle == MouseControlStyleKnob.ClickToGoto)
			{
				Value.AsDouble = MouseToValue(e);
			}
			else
			{
				if (UIControl.MouseControlStyle != MouseControlStyleKnob.DragToDestination)
				{
					return;
				}
				if (m_MouseDownOffSwitch && !OffSwitch.HitRectangle.Contains(e.X, e.Y))
				{
					m_MouseDownOffSwitch = false;
				}
				double num2 = Math2.PointToAngle(m_CenterPoint, e.X, e.Y);
				double num3 = m_MouseDownAngle - num2;
				if (num3 > 200.0)
				{
					num3 -= 360.0;
				}
				if (num3 < -200.0)
				{
					num3 += 360.0;
				}
				double value = ScaleRange.ValueToAngle(Value.AsDouble) - num3;
				double num4 = ScaleRange.AngleToValue(value);
				if (OffSwitch.Enabled)
				{
					if (OffSwitch.On)
					{
						if (num4 < ScaleRange.Min - ScaleRange.Span / 100.0)
						{
							OffSwitch.On = false;
						}
					}
					else
					{
						if (num4 > ScaleRange.Min + ScaleRange.Span / 100.0)
						{
							OffSwitch.On = true;
						}
						num4 = ScaleRange.Min;
					}
				}
				Value.AsDouble = ScaleDisplay.ValueClamped(num4);
				m_MouseDownAngle = num2;
			}
		}

		protected override void InternalOnMouseUp(MouseEventArgs e)
		{
			base.IsMouseDown = false;
			if (m_MouseDownOffSwitch && OffSwitch.HitRectangle.Contains(e.X, e.Y))
			{
				if (OffSwitch.On)
				{
					OffSwitch.On = false;
					Value.AsDouble = ScaleRange.Min;
				}
				else
				{
					OffSwitch.On = true;
					Value.AsDouble = ScaleRange.Min;
				}
			}
		}

		protected override bool IsInputKey(Keys keyData)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0002: Unknown result type (might be due to invalid IL or missing references)
			//IL_0005: Unknown result type (might be due to invalid IL or missing references)
			//IL_002b: Expected I4, but got Unknown
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			return (keyData - 33) switch
			{
				4 => true, 
				6 => true, 
				7 => true, 
				5 => true, 
				0 => true, 
				1 => true, 
				3 => true, 
				2 => true, 
				_ => base.IsInputKey(keyData), 
			};
		}

		private void KeyboardAdjustValueUp(double value)
		{
			if (OffSwitch.Enabled && !OffSwitch.On)
			{
				OffSwitch.On = true;
				Value.AsDouble = ScaleRange.Min;
			}
			else
			{
				Value.AsDouble = ScaleDisplay.ValueClamped(Value.AsDouble + value);
			}
		}

		private void KeyboardAdjustValueDown(double value)
		{
			if (OffSwitch.Enabled && OffSwitch.On && Value.AsDouble == ScaleRange.Min)
			{
				OffSwitch.On = false;
				Value.AsDouble = 0.0;
			}
			else
			{
				Value.AsDouble = ScaleDisplay.ValueClamped(Value.AsDouble - value);
			}
		}

		protected override void InternalOnKeyDown(KeyEventArgs e)
		{
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Invalid comparison between Unknown and I4
			//IL_003b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0042: Invalid comparison between Unknown and I4
			//IL_0067: Unknown result type (might be due to invalid IL or missing references)
			//IL_006e: Invalid comparison between Unknown and I4
			//IL_0093: Unknown result type (might be due to invalid IL or missing references)
			//IL_009a: Invalid comparison between Unknown and I4
			//IL_00bf: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c6: Invalid comparison between Unknown and I4
			//IL_00eb: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f2: Invalid comparison between Unknown and I4
			//IL_0117: Unknown result type (might be due to invalid IL or missing references)
			//IL_011e: Invalid comparison between Unknown and I4
			//IL_0157: Unknown result type (might be due to invalid IL or missing references)
			//IL_015e: Invalid comparison between Unknown and I4
			if (!UIControl.KeyboardEnabled)
			{
				return;
			}
			if ((int)e.KeyCode == 33)
			{
				base.IsKeyDown = true;
				KeyboardAdjustValueUp(ScaleRange.Span / 10.0);
			}
			if ((int)e.KeyCode == 38)
			{
				base.IsKeyDown = true;
				KeyboardAdjustValueUp(ScaleRange.Span / 100.0);
			}
			if ((int)e.KeyCode == 39)
			{
				base.IsKeyDown = true;
				KeyboardAdjustValueUp(ScaleRange.Span / 100.0);
			}
			if ((int)e.KeyCode == 34)
			{
				base.IsKeyDown = true;
				KeyboardAdjustValueDown(ScaleRange.Span / 10.0);
			}
			if ((int)e.KeyCode == 40)
			{
				base.IsKeyDown = true;
				KeyboardAdjustValueDown(ScaleRange.Span / 100.0);
			}
			if ((int)e.KeyCode == 37)
			{
				base.IsKeyDown = true;
				KeyboardAdjustValueDown(ScaleRange.Span / 100.0);
			}
			if ((int)e.KeyCode == 36)
			{
				base.IsKeyDown = true;
				Value.AsDouble = ScaleRange.Min;
				if (OffSwitch.Enabled)
				{
					OffSwitch.On = true;
				}
			}
			if ((int)e.KeyCode == 35)
			{
				base.IsKeyDown = true;
				Value.AsDouble = ScaleRange.Max;
				if (OffSwitch.Enabled)
				{
					OffSwitch.On = true;
				}
			}
		}

		protected override void InternalOnMouseWheel(MouseEventArgs e)
		{
			if (UIControl.MouseWheelEnabled)
			{
				if (e.Delta > 0)
				{
					Value.AsDouble = ScaleDisplay.ValueClamped(Value.AsDouble + ScaleRange.Span / 100.0);
				}
				else
				{
					Value.AsDouble = ScaleDisplay.ValueClamped(Value.AsDouble - ScaleRange.Span / 100.0);
				}
			}
		}

		protected override void InternalOnKeyUp(KeyEventArgs e)
		{
			base.IsKeyDown = false;
			base.IsMouseDown = false;
		}

		private void OnValueChanged(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			p.Graphics.SmoothingMode = (SmoothingMode)4;
			Point centerPoint = p.CenterPoint;
			double num = I_Range.ValueToAngle(ScaleDisplay.ValueClamped(Value.AsDouble));
			double angle = I_Range.ValueToAngle(ScaleDisplay.ValueClamped(ScaleRange.Min));
			if (ScaleDisplay.TextAlignment == StringAlignmentAngular.RadialInner || ScaleDisplay.TextAlignment == StringAlignmentAngular.RadialOuter)
			{
				p.Graphics.TextRenderingHint = (TextRenderingHint)4;
			}
			I_Display.CenterPoint = centerPoint;
			I_Display.Radius = Body.Radius;
			I_Display.HubRadius = 0;
			I_Display.Generate(p);
			I_Display.Draw(p);
			if (Body.Radius > 0)
			{
				((IKnobBody)Body).Draw(p, I_Display.CenterPoint, base.IsDown);
				if (OffSwitch.Enabled && !OffSwitch.On)
				{
					((IPointerKnob)Pointer).Draw(p, I_Display.CenterPoint, num - (double)OffSwitch.OffsetAngle, ((IKnobBody)Body).RadiusEdge);
				}
				else
				{
					((IPointerKnob)Pointer).Draw(p, I_Display.CenterPoint, num, ((IKnobBody)Body).RadiusEdge);
				}
				((IKnobOffSwitch)OffSwitch).Draw(p, I_Display.CenterPoint, angle, ((IKnobBody)Body).RadiusEdge);
			}
			m_CenterPoint = I_Display.CenterPoint;
			if (UIControl.FocusRectangleShow && ((Control)this).Focused)
			{
				p.Graphics.DrawFocusRectangle(p.PenRectangle, base.BackColor);
			}
		}
	}
}
namespace Iocomp.Interfaces
{
	public interface IKnobBody
	{
		int RadiusEdge { get; }

		void Draw(PaintArgs p, Point centerPoint, bool mouseDown);
	}
}
namespace Iocomp.Types
{
	public enum KnobBodyStyle
	{
		Raised,
		RaisedEdge
	}
}
namespace Iocomp.Classes
{
	[Description("")]
	[DefaultProperty("Color")]
	public sealed class KnobBody : SubClassBase, IKnobBody
	{
		private int m_Radius;

		private int m_EdgeWidth;

		private KnobBodyStyle m_Style;

		int IKnobBody.RadiusEdge => RadiusEdge;

		[Description("")]
		[RefreshProperties(RefreshProperties.All)]
		public new Color Color
		{
			get
			{
				return base.Color;
			}
			set
			{
				base.Color = value;
			}
		}

		[Description("")]
		public int Radius
		{
			get
			{
				return m_Radius;
			}
			set
			{
				PropertyUpdateDefault("Radius", value);
				if (Radius != value)
				{
					m_Radius = value;
					DoPropertyChange(this, "Radius");
				}
			}
		}

		[Description("")]
		public int EdgeWidth
		{
			get
			{
				return m_EdgeWidth;
			}
			set
			{
				PropertyUpdateDefault("EdgeWidth", value);
				if (EdgeWidth != value)
				{
					m_EdgeWidth = value;
					DoPropertyChange(this, "EdgeWidth");
				}
			}
		}

		[Description("")]
		public KnobBodyStyle Style
		{
			get
			{
				return m_Style;
			}
			set
			{
				PropertyUpdateDefault("Style", value);
				if (Style != value)
				{
					m_Style = value;
					DoPropertyChange(this, "Style");
				}
			}
		}

		private int RadiusEdge
		{
			get
			{
				if (Style == KnobBodyStyle.Raised)
				{
					return Radius;
				}
				if (Style == KnobBodyStyle.RaisedEdge)
				{
					return Radius - EdgeWidth;
				}
				return Radius;
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new KnobBodyEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Knob Body";
		}

		void IKnobBody.Draw(PaintArgs p, Point centerPoint, bool mouseDown)
		{
			Draw(p, centerPoint, mouseDown);
		}

		public KnobBody()
		{
			DoCreate();
		}

		private bool ShouldSerializeColor()
		{
			return PropertyShouldSerialize("Color");
		}

		private void ResetColor()
		{
			PropertyReset("Color");
		}

		private bool ShouldSerializeRadius()
		{
			return PropertyShouldSerialize("Radius");
		}

		private void ResetRadius()
		{
			PropertyReset("Radius");
		}

		private bool ShouldSerializeEdgeWidth()
		{
			return PropertyShouldSerialize("EdgeWidth");
		}

		private void ResetEdgeWidth()
		{
			PropertyReset("EdgeWidth");
		}

		private bool ShouldSerializeStyle()
		{
			return PropertyShouldSerialize("Style");
		}

		private void ResetStyle()
		{
			PropertyReset("Style");
		}

		private void DrawRaised(PaintArgs p, Point centerPoint, bool mouseDown)
		{
			//IL_0055: Unknown result type (might be due to invalid IL or missing references)
			//IL_005b: Expected O, but got Unknown
			//IL_0063: Unknown result type (might be due to invalid IL or missing references)
			//IL_0069: Expected O, but got Unknown
			iColors.FaceColorFlat = iColors.Darken1(Color);
			if (mouseDown)
			{
				iColors.FaceColorFlat = iColors.Lighten2(iColors.FaceColorFlat);
			}
			Rectangle rectangle = new Rectangle(centerPoint.X - Radius, centerPoint.Y - Radius, Radius * 2, Radius * 2);
			GraphicsPath val = new GraphicsPath();
			val.AddEllipse(rectangle);
			PathGradientBrush val2 = new PathGradientBrush(val);
			val2.CenterColor = Color.White;
			val2.SurroundColors = new Color[1] { iColors.FaceColorFlat };
			float num = 225f - p.RotationAngle;
			val2.CenterPoint = Math2.ToRotatedPoint(num, (float)Radius * 0.67f, centerPoint);
			p.Graphics.FillPath((Brush)(object)val2, val);
			((Brush)val2).Dispose();
			p.Graphics.DrawEllipse(p.Graphics.Pen(iColors.FaceColorFlat), rectangle);
		}

		private void DrawRaisedEdge(PaintArgs p, Point centerPoint, bool mouseDown)
		{
			//IL_0055: Unknown result type (might be due to invalid IL or missing references)
			//IL_005b: Expected O, but got Unknown
			//IL_0063: Unknown result type (might be due to invalid IL or missing references)
			//IL_006a: Expected O, but got Unknown
			iColors.FaceColorFlat = iColors.Darken1(Color);
			if (mouseDown)
			{
				iColors.FaceColorFlat = iColors.Lighten2(iColors.FaceColorFlat);
			}
			Rectangle rectangle = new Rectangle(centerPoint.X - Radius, centerPoint.Y - Radius, Radius * 2, Radius * 2);
			GraphicsPath val = new GraphicsPath();
			val.AddEllipse(rectangle);
			PathGradientBrush val2 = new PathGradientBrush(val);
			val2.CenterColor = Color.White;
			val2.SurroundColors = new Color[1] { iColors.FaceColorFlat };
			float num = 225f - p.RotationAngle;
			val2.CenterPoint = Math2.ToRotatedPoint(num, (double)Radius * 1.414, centerPoint);
			p.Graphics.FillPath((Brush)(object)val2, val);
			((Brush)val2).Dispose();
			int num2 = Radius - EdgeWidth;
			rectangle = new Rectangle(centerPoint.X - num2, centerPoint.Y - num2, num2 * 2, num2 * 2);
			p.Graphics.FillEllipse(p.Graphics.Brush(Color), rectangle);
		}

		private void Draw(PaintArgs p, Point centerPoint, bool mouseDown)
		{
			if (Style == KnobBodyStyle.Raised)
			{
				DrawRaised(p, centerPoint, mouseDown);
			}
			else if (Style == KnobBodyStyle.RaisedEdge)
			{
				DrawRaisedEdge(p, centerPoint, mouseDown);
			}
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public sealed class KnobBodyEditorPlugIn : PlugInStandard
	{
		private FocusLabel label2;

		private ComboBox StyleComboBox;

		private FocusLabel label3;

		private FocusLabel label4;

		private NumericUpDown RadiusNumericUpDown;

		private NumericUpDown EdgeWidthNumericUpDown;

		private FocusLabel label9;

		private ColorPicker ColorPicker;

		private Container components = null;

		public KnobBodyEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label2 = new FocusLabel();
			StyleComboBox = new ComboBox();
			label3 = new FocusLabel();
			RadiusNumericUpDown = new NumericUpDown();
			label4 = new FocusLabel();
			EdgeWidthNumericUpDown = new NumericUpDown();
			label9 = new FocusLabel();
			ColorPicker = new ColorPicker();
			((Control)this).SuspendLayout();
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)StyleComboBox;
			((Control)label2).Location = new Point(24, 10);
			((Control)label2).Name = "label2";
			label2.Size = new Size(32, 15);
			label2.Text = "Style";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((ComboBox)StyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)StyleComboBox).Location = new Point(56, 8);
			((Control)StyleComboBox).Name = "StyleComboBox";
			StyleComboBox.PropertyName = "Style";
			((Control)StyleComboBox).Size = new Size(144, 21);
			((Control)StyleComboBox).TabIndex = 0;
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)RadiusNumericUpDown;
			((Control)label3).Location = new Point(78, 73);
			((Control)label3).Name = "label3";
			label3.Size = new Size(42, 15);
			label3.Text = "Radius";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			((Control)RadiusNumericUpDown).Location = new Point(120, 72);
			((NumericUpDown)RadiusNumericUpDown).Maximum = new decimal(new int[4] { 1000, 0, 0, 0 });
			((Control)RadiusNumericUpDown).Name = "RadiusNumericUpDown";
			RadiusNumericUpDown.PropertyName = "Radius";
			((Control)RadiusNumericUpDown).Size = new Size(48, 20);
			((Control)RadiusNumericUpDown).TabIndex = 2;
			((UpDownBase)RadiusNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)EdgeWidthNumericUpDown;
			((Control)label4).Location = new Point(56, 49);
			((Control)label4).Name = "label4";
			label4.Size = new Size(64, 15);
			label4.Text = "Edge Width";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)EdgeWidthNumericUpDown).Location = new Point(120, 48);
			((Control)EdgeWidthNumericUpDown).Name = "EdgeWidthNumericUpDown";
			EdgeWidthNumericUpDown.PropertyName = "EdgeWidth";
			((Control)EdgeWidthNumericUpDown).Size = new Size(48, 20);
			((Control)EdgeWidthNumericUpDown).TabIndex = 1;
			((UpDownBase)EdgeWidthNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label9.LoadingBegin();
			label9.FocusControl = (Control)(object)ColorPicker;
			((Control)label9).Location = new Point(22, 115);
			((Control)label9).Name = "label9";
			label9.Size = new Size(34, 15);
			label9.Text = "Color";
			label9.UpdateFrameRate = 50.0;
			label9.LoadingEnd();
			((Control)ColorPicker).Location = new Point(56, 112);
			((Control)ColorPicker).Name = "ColorPicker";
			ColorPicker.PropertyName = "Color";
			((Control)ColorPicker).Size = new Size(144, 21);
			((Control)ColorPicker).TabIndex = 3;
			((Control)this).Controls.Add((Control)(object)ColorPicker);
			((Control)this).Controls.Add((Control)(object)label3);
			((Control)this).Controls.Add((Control)(object)RadiusNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)EdgeWidthNumericUpDown);
			((Control)this).Controls.Add((Control)(object)StyleComboBox);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)label9);
			((Control)this).Location = new Point(10, 20);
			((Control)this).Name = "KnobBodyEditorPlugIn";
			((Control)this).Size = new Size(576, 216);
			base.Title = "Body Editor";
			((Control)this).ResumeLayout(false);
		}
	}
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class KnobEditorPlugIn : PlugInStandard
	{
		private CheckBox AutoSizeCheckBox;

		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private FocusLabel label1;

		private FocusLabel label2;

		private FontButton FontButton;

		private ColorPicker BackColorPicker;

		private ColorPicker ForeColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public KnobEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			FontButton = new FontButton();
			AutoSizeCheckBox = new CheckBox();
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			BackColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			ForeColorPicker = new ColorPicker();
			label2 = new FocusLabel();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			((Control)FontButton).Location = new Point(272, 72);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 2;
			((Control)AutoSizeCheckBox).Location = new Point(272, 128);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 5;
			AutoSizeCheckBox.Text = "Auto Size";
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(71, 130);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((Control)RotationComboBox).Location = new Point(120, 128);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 4;
			((Control)BackColorPicker).Location = new Point(120, 96);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 3;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(59, 99);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)ForeColorPicker).Location = new Point(120, 72);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(136, 21);
			((Control)ForeColorPicker).TabIndex = 1;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label2).Location = new Point(61, 75);
			((Control)label2).Name = "label2";
			label2.Size = new Size(59, 15);
			label2.Text = "Fore Color";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(120, 8);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(84, 10);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(160, 162);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(120, 160);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 6;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(16, 162);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Name = "KnobEditorPlugIn";
			((Control)this).Size = new Size(432, 200);
			base.Title = "Knob Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueDoubleEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new PointerKnobEditorPlugIn(), "Pointer", sameLevel: false);
			AddSubPlugIn(new ScaleDisplayAngularEditorPlugIn(), "Scale Display", sameLevel: false);
			AddSubPlugIn(new ScaleRangeAngularEditorPlugIn(), "Scale Range", sameLevel: false);
			AddSubPlugIn(new KnobBodyEditorPlugIn(), "Body", sameLevel: false);
			AddSubPlugIn(new KnobOffSwitchEditorPlugIn(), "Off Switch", sameLevel: false);
			AddSubPlugIn(new UIControlKnobEditorPlugIn(), "UI Control", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as Knob).Value;
			base.SubPlugIns[1].Value = (base.Value as Knob).Pointer;
			base.SubPlugIns[2].Value = (base.Value as Knob).ScaleDisplay;
			base.SubPlugIns[3].Value = (base.Value as Knob).ScaleRange;
			base.SubPlugIns[4].Value = (base.Value as Knob).Body;
			base.SubPlugIns[5].Value = (base.Value as Knob).OffSwitch;
			base.SubPlugIns[6].Value = (base.Value as Knob).UIControl;
			base.SubPlugIns[7].Value = (base.Value as Knob).Border;
		}
	}
}
namespace Iocomp.Interfaces
{
	public interface IKnobOffSwitch
	{
		void Draw(PaintArgs p, Point centerPoint, double angle, int radiusEdge);
	}
}
namespace Iocomp.Classes
{
	[DefaultProperty("Color")]
	[Description("")]
	public sealed class KnobOffSwitch : SubClassBase, IKnobOffSwitch
	{
		private bool m_Enabled;

		private bool m_On;

		private Color m_ColorOn;

		private Color m_ColorOff;

		private int m_Size;

		private int m_Margin;

		private int m_OffsetAngle;

		private Rectangle m_HitRectangle;

		[Description("")]
		public bool Enabled
		{
			get
			{
				return m_Enabled;
			}
			set
			{
				PropertyUpdateDefault("Enabled", value);
				if (Enabled != value)
				{
					m_Enabled = value;
					DoPropertyChange(this, "Enabled");
				}
			}
		}

		[Description("")]
		public bool On
		{
			get
			{
				return m_On;
			}
			set
			{
				PropertyUpdateDefault("On", value);
				if (On != value)
				{
					m_On = value;
					DoPropertyChange(this, "On");
				}
			}
		}

		[Description("")]
		public Color ColorOn
		{
			get
			{
				return m_ColorOn;
			}
			set
			{
				PropertyUpdateDefault("ColorOn", value);
				if (ColorOn != value)
				{
					m_ColorOn = value;
					DoPropertyChange(this, "ColorOn");
				}
			}
		}

		[Description("")]
		public Color ColorOff
		{
			get
			{
				return m_ColorOff;
			}
			set
			{
				PropertyUpdateDefault("ColorOff", value);
				if (ColorOff != value)
				{
					m_ColorOff = value;
					DoPropertyChange(this, "ColorOff");
				}
			}
		}

		[Description("")]
		public int Size
		{
			get
			{
				return m_Size;
			}
			set
			{
				PropertyUpdateDefault("Size", value);
				if (Size != value)
				{
					m_Size = value;
					DoPropertyChange(this, "Size");
				}
			}
		}

		[Description("")]
		public int Margin
		{
			get
			{
				return m_Margin;
			}
			set
			{
				PropertyUpdateDefault("Margin", value);
				if (Margin != value)
				{
					m_Margin = value;
					DoPropertyChange(this, "Margin");
				}
			}
		}

		[Description("")]
		public int OffsetAngle
		{
			get
			{
				return m_OffsetAngle;
			}
			set
			{
				PropertyUpdateDefault("OffsetAngle", value);
				if (OffsetAngle != value)
				{
					m_OffsetAngle = value;
					DoPropertyChange(this, "OffsetAngle");
				}
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[Description("")]
		[Browsable(false)]
		public Rectangle HitRectangle
		{
			get
			{
				return m_HitRectangle;
			}
			set
			{
				m_HitRectangle = value;
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new KnobBodyEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Knob Body";
		}

		void IKnobOffSwitch.Draw(PaintArgs p, Point centerPoint, double angle, int radiusEdge)
		{
			Draw(p, centerPoint, angle, radiusEdge);
		}

		public KnobOffSwitch()
		{
			DoCreate();
		}

		private bool ShouldSerializeEnabled()
		{
			return PropertyShouldSerialize("Enabled");
		}

		private void ResetEnabled()
		{
			PropertyReset("Enabled");
		}

		private bool ShouldSerializeOn()
		{
			return PropertyShouldSerialize("On");
		}

		private void ResetOn()
		{
			PropertyReset("On");
		}

		private bool ShouldSerializeColorOn()
		{
			return PropertyShouldSerialize("ColorOn");
		}

		private void ResetColorOn()
		{
			PropertyReset("ColorOn");
		}

		private bool ShouldSerializeColorOff()
		{
			return PropertyShouldSerialize("ColorOff");
		}

		private void ResetColorOff()
		{
			PropertyReset("ColorOff");
		}

		private bool ShouldSerializeSize()
		{
			return PropertyShouldSerialize("Size");
		}

		private void ResetSize()
		{
			PropertyReset("Size");
		}

		private bool ShouldSerializeMargin()
		{
			return PropertyShouldSerialize("Margin");
		}

		private void ResetMargin()
		{
			PropertyReset("Margin");
		}

		private bool ShouldSerializeOffsetAngle()
		{
			return PropertyShouldSerialize("OffsetAngle");
		}

		private void ResetOffsetAngle()
		{
			PropertyReset("OffsetAngle");
		}

		private void Draw(PaintArgs p, Point centerPoint, double angle, int radiusEdge)
		{
			if (Enabled)
			{
				Color color = ((!On) ? ColorOff : ColorOn);
				Point point = Math2.ToRotatedPoint(angle - (double)OffsetAngle, radiusEdge + Margin + Size, centerPoint);
				Rectangle rectangle = new Rectangle(point.X - Size, point.Y - Size, 2 * Size, 2 * Size);
				BorderSpecial.DrawEllipse(p, rectangle, BevelStyle.Sunken, 2f, color);
				m_HitRectangle = rectangle;
				rectangle.Inflate(-2, -2);
				p.Graphics.FillEllipse(p.Graphics.Brush(color), rectangle);
			}
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public sealed class KnobOffSwitchEditorPlugIn : PlugInStandard
	{
		private FocusLabel label3;

		private FocusLabel label4;

		private FocusLabel label9;

		private CheckBox EnabledCheckBox;

		private CheckBox OnCheckBox;

		private ColorPicker ColorOnPicker;

		private ColorPicker ColorOffPicker;

		private FocusLabel focusLabel1;

		private NumericUpDown SizeNumericUpDown;

		private NumericUpDown MarginNumericUpDown;

		private FocusLabel focusLabel2;

		private NumericUpDown OffsetAngleNumericUpDown;

		private Container components = null;

		public KnobOffSwitchEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label3 = new FocusLabel();
			SizeNumericUpDown = new NumericUpDown();
			label4 = new FocusLabel();
			MarginNumericUpDown = new NumericUpDown();
			label9 = new FocusLabel();
			ColorOnPicker = new ColorPicker();
			EnabledCheckBox = new CheckBox();
			OnCheckBox = new CheckBox();
			ColorOffPicker = new ColorPicker();
			focusLabel1 = new FocusLabel();
			focusLabel2 = new FocusLabel();
			OffsetAngleNumericUpDown = new NumericUpDown();
			((ISupportInitialize)SizeNumericUpDown).BeginInit();
			((ISupportInitialize)MarginNumericUpDown).BeginInit();
			((ISupportInitialize)OffsetAngleNumericUpDown).BeginInit();
			((Control)this).SuspendLayout();
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)SizeNumericUpDown;
			((Control)label3).Location = new Point(43, 89);
			((Control)label3).Name = "label3";
			label3.Size = new Size(29, 15);
			label3.Text = "Size";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			((Control)SizeNumericUpDown).Location = new Point(72, 88);
			((NumericUpDown)SizeNumericUpDown).Maximum = new decimal(new int[4] { 1000, 0, 0, 0 });
			((Control)SizeNumericUpDown).Name = "SizeNumericUpDown";
			SizeNumericUpDown.PropertyName = "Size";
			((Control)SizeNumericUpDown).Size = new Size(48, 20);
			((Control)SizeNumericUpDown).TabIndex = 2;
			((UpDownBase)SizeNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)MarginNumericUpDown;
			((Control)label4).Location = new Point(31, 113);
			((Control)label4).Name = "label4";
			label4.Size = new Size(41, 15);
			label4.Text = "Margin";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)MarginNumericUpDown).Location = new Point(72, 112);
			((Control)MarginNumericUpDown).Name = "MarginNumericUpDown";
			MarginNumericUpDown.PropertyName = "Margin";
			((Control)MarginNumericUpDown).Size = new Size(48, 20);
			((Control)MarginNumericUpDown).TabIndex = 3;
			((UpDownBase)MarginNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label9.LoadingBegin();
			label9.FocusControl = (Control)(object)ColorOnPicker;
			((Control)label9).Location = new Point(165, 91);
			((Control)label9).Name = "label9";
			label9.Size = new Size(51, 15);
			label9.Text = "Color On";
			label9.UpdateFrameRate = 50.0;
			label9.LoadingEnd();
			((Control)ColorOnPicker).Location = new Point(216, 88);
			((Control)ColorOnPicker).Name = "ColorOnPicker";
			ColorOnPicker.PropertyName = "ColorOn";
			((Control)ColorOnPicker).Size = new Size(144, 21);
			((Control)ColorOnPicker).TabIndex = 5;
			((Control)EnabledCheckBox).Location = new Point(32, 16);
			((Control)EnabledCheckBox).Name = "EnabledCheckBox";
			EnabledCheckBox.PropertyName = "Enabled";
			((Control)EnabledCheckBox).Size = new Size(120, 24);
			((Control)EnabledCheckBox).TabIndex = 0;
			EnabledCheckBox.Text = "Enabled";
			((Control)OnCheckBox).Location = new Point(72, 56);
			((Control)OnCheckBox).Name = "OnCheckBox";
			OnCheckBox.PropertyName = "On";
			((Control)OnCheckBox).Size = new Size(88, 24);
			((Control)OnCheckBox).TabIndex = 1;
			OnCheckBox.Text = "On";
			((Control)ColorOffPicker).Location = new Point(216, 112);
			((Control)ColorOffPicker).Name = "ColorOffPicker";
			ColorOffPicker.PropertyName = "ColorOff";
			((Control)ColorOffPicker).Size = new Size(144, 21);
			((Control)ColorOffPicker).TabIndex = 6;
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)ColorOffPicker;
			((Control)focusLabel1).Location = new Point(165, 115);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(51, 15);
			focusLabel1.Text = "Color Off";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)OffsetAngleNumericUpDown;
			((Control)focusLabel2).Location = new Point(4, 137);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(68, 15);
			focusLabel2.Text = "Offset Angle";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)OffsetAngleNumericUpDown).Location = new Point(72, 136);
			((Control)OffsetAngleNumericUpDown).Name = "OffsetAngleNumericUpDown";
			OffsetAngleNumericUpDown.PropertyName = "OffsetAngle";
			((Control)OffsetAngleNumericUpDown).Size = new Size(48, 20);
			((Control)OffsetAngleNumericUpDown).TabIndex = 4;
			((UpDownBase)OffsetAngleNumericUpDown).TextAlign = (HorizontalAlignment)2;
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)OffsetAngleNumericUpDown);
			((Control)this).Controls.Add((Control)(object)ColorOffPicker);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)OnCheckBox);
			((Control)this).Controls.Add((Control)(object)EnabledCheckBox);
			((Control)this).Controls.Add((Control)(object)ColorOnPicker);
			((Control)this).Controls.Add((Control)(object)label3);
			((Control)this).Controls.Add((Control)(object)SizeNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)MarginNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label9);
			((Control)this).Location = new Point(10, 20);
			((Control)this).Name = "KnobOffSwitchEditorPlugIn";
			((Control)this).Size = new Size(576, 184);
			base.Title = "Body Editor";
			((ISupportInitialize)SizeNumericUpDown).EndInit();
			((ISupportInitialize)MarginNumericUpDown).EndInit();
			((ISupportInitialize)OffsetAngleNumericUpDown).EndInit();
			((Control)this).ResumeLayout(false);
		}
	}
	public class LabelDesigner : ControlDesigner
	{
		public override DesignerVerbCollection Verbs
		{
			get
			{
				DesignerVerb[] value = new DesignerVerb[5]
				{
					new DesignerVerb("Editor (Custom)", EditorCustom),
					new DesignerVerb("Align Left", OnAlignLeft),
					new DesignerVerb("Align Right", OnAlignRight),
					new DesignerVerb("Align Top", OnAlignTop),
					new DesignerVerb("Align Bottom", OnAlignBottom)
				};
				return new DesignerVerbCollection(value);
			}
		}

		public override SelectionRules SelectionRules
		{
			get
			{
				//IL_001d: Unknown result type (might be due to invalid IL or missing references)
				//IL_0013: Unknown result type (might be due to invalid IL or missing references)
				//IL_001a: Unknown result type (might be due to invalid IL or missing references)
				if ((((ComponentDesigner)this).Component as Label).AutoSize)
				{
					return (SelectionRules)(base.SelectionRules & -16);
				}
				return base.SelectionRules;
			}
		}

		protected override void OnContextMenu(int x, int y)
		{
			((ComponentDesigner)this).Verbs[0].Enabled = (((ControlDesigner)this).Control as Label).FocusControl != null;
			((ComponentDesigner)this).Verbs[1].Enabled = (((ControlDesigner)this).Control as Label).FocusControl != null;
			((ComponentDesigner)this).Verbs[2].Enabled = (((ControlDesigner)this).Control as Label).FocusControl != null;
			((ComponentDesigner)this).Verbs[3].Enabled = (((ControlDesigner)this).Control as Label).FocusControl != null;
			base.OnContextMenu(x, y);
		}

		private void EditorCustom(object sender, EventArgs e)
		{
			DoEditorCustom();
		}

		private void OnAlignRight(object sender, EventArgs e)
		{
			(((ComponentDesigner)this).Component as Label).AlignRight();
			((ComponentDesigner)this).RaiseComponentChanged((MemberDescriptor)null, (object)null, (object)null);
		}

		private void OnAlignLeft(object sender, EventArgs e)
		{
			(((ComponentDesigner)this).Component as Label).AlignLeft();
			((ComponentDesigner)this).RaiseComponentChanged((MemberDescriptor)null, (object)null, (object)null);
		}

		private void OnAlignTop(object sender, EventArgs e)
		{
			(((ComponentDesigner)this).Component as Label).AlignTop();
			((ComponentDesigner)this).RaiseComponentChanged((MemberDescriptor)null, (object)null, (object)null);
		}

		private void OnAlignBottom(object sender, EventArgs e)
		{
			(((ComponentDesigner)this).Component as Label).AlignBottom();
			((ComponentDesigner)this).RaiseComponentChanged((MemberDescriptor)null, (object)null, (object)null);
		}

		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
			properties.Remove("CausesValidation");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[Description("Enhanced Label.")]
	[DefaultEvent("TextChanged")]
	[Designer(typeof(LabelDesigner))]
	[DefaultProperty("Name")]
	[ToolboxBitmap(typeof(Access), "Label.bmp")]
	[DesignerCategory("code")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	public class Label : ControlBase
	{
		private TextLayoutFull m_TextLayout;

		private Shadow m_TextShadow;

		private Control m_FocusControl;

		private int m_NewLocationX;

		private int m_NewLocationY;

		private int m_AlignOffset;

		private string m_Text;

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		public TextLayoutFull TextLayout => m_TextLayout;

		[Description("")]
		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public Shadow TextShadow => m_TextShadow;

		[DefaultValue(null)]
		[Category("Iocomp")]
		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Visible)]
		[RefreshProperties(RefreshProperties.All)]
		public Control FocusControl
		{
			get
			{
				return m_FocusControl;
			}
			set
			{
				if (FocusControl != value)
				{
					m_FocusControl = value;
					if (FocusControl != null)
					{
						RepositionControl();
					}
				}
			}
		}

		[Editor("System.Windows.Forms.Design.StringArrayEditor,System.Design", "System.Drawing.Design.UITypeEditor, System.Drawing")]
		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[Description("")]
		[RefreshProperties(RefreshProperties.All)]
		public string[] TextLines
		{
			get
			{
				return ((Control)this).Text.Split(new char[1] { '\n' });
			}
			set
			{
				StringBuilder stringBuilder = new StringBuilder(value.Length);
				for (int i = 0; i < value.Length; i++)
				{
					if (i < value.Length - 1)
					{
						stringBuilder.Append(value[i] + "\n");
					}
					else
					{
						stringBuilder.Append(value[i]);
					}
				}
				((Control)this).Text = stringBuilder.ToString();
			}
		}

		[Description("Specifies the text for the label.")]
		[RefreshProperties(RefreshProperties.All)]
		[Category("Iocomp")]
		public override string Text
		{
			get
			{
				return m_Text;
			}
			set
			{
				PropertyUpdateDefault("Text", value);
				if (((Control)this).Text != value)
				{
					m_Text = value;
					DoPropertyChange(this, "Text");
					((Control)this).OnTextChanged(EventArgs.Empty);
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new LabelEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Label";
		}

		public Label()
		{
			m_License = LicenseManager.Validate(typeof(Label), this);
			DoCreate();
		}

		~Label()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_TextLayout = new TextLayoutFull();
			AddSubClass(TextLayout);
			m_TextShadow = new Shadow();
			AddSubClass(TextShadow);
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			m_AlignOffset = 7;
			string[] textLines = new string[0];
			TextLines = textLines;
			((Control)this).Text = "";
			base.AutoSize = false;
			TextLines[0] = "";
			TextLayout.Trimming = (StringTrimming)0;
			TextLayout.LineLimit = false;
			TextLayout.MeasureTrailingSpaces = false;
			TextLayout.NoWrap = false;
			TextLayout.NoClip = false;
			TextLayout.AlignmentHorizontal.Style = (StringAlignment)1;
			TextLayout.AlignmentHorizontal.Margin = 0.5;
			TextLayout.AlignmentVertical.Style = (StringAlignment)1;
			TextLayout.AlignmentVertical.Margin = 0.5;
			TextShadow.Color = Color.Black;
			TextShadow.Offset = 2;
			TextShadow.Stretched = false;
			TextShadow.Style = ShadowStyle.None;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(100, 23);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			Graphics val = ((Control)this).CreateGraphics();
			int actualOffset = TextShadow.ActualOffset;
			Size requiredSize = ((ITextLayoutBase)TextLayout).GetRequiredSize(((Control)this).Text, base.Font, new GraphicsAPI(val));
			val.Dispose();
			return new Size(requiredSize.Width + actualOffset, requiredSize.Height + actualOffset);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == this && propertyName == "Text")
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "Font")
			{
				DoAutoSize();
			}
			if (sender == TextShadow)
			{
				DoAutoSize();
			}
			if (sender == TextLayout)
			{
				DoAutoSize();
			}
			if (sender == TextLayout.AlignmentHorizontal)
			{
				DoAutoSize();
			}
			if (sender == TextLayout.AlignmentVertical)
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		protected override Point CalculateAutoSizeLocation(Size NewSize)
		{
			//IL_000b: Unknown result type (might be due to invalid IL or missing references)
			//IL_002e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0034: Invalid comparison between Unknown and I4
			//IL_0093: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00bc: Invalid comparison between Unknown and I4
			int x = (((int)TextLayout.AlignmentHorizontal.Style == 0) ? ((Control)this).Location.X : (((int)TextLayout.AlignmentHorizontal.Style != 1) ? (((Control)this).Location.X + base.Size.Width - NewSize.Width) : (((Control)this).Location.X + base.Size.Width / 2 - NewSize.Width / 2)));
			int y = (((int)TextLayout.AlignmentVertical.Style == 0) ? ((Control)this).Location.Y : (((int)TextLayout.AlignmentVertical.Style != 1) ? (((Control)this).Location.Y + base.Size.Height - NewSize.Height) : (((Control)this).Location.Y + base.Size.Height / 2 - NewSize.Height / 2)));
			return new Point(x, y);
		}

		private bool ShouldSerializeTextLayout()
		{
			return ((ISubClassBase)TextLayout).ShouldSerialize();
		}

		private void ResetTextLayout()
		{
			((ISubClassBase)TextLayout).ResetToDefault();
		}

		private bool ShouldSerializeTextShadow()
		{
			return ((ISubClassBase)TextShadow).ShouldSerialize();
		}

		private void ResetTextShadow()
		{
			((ISubClassBase)TextShadow).ResetToDefault();
		}

		private bool ShouldSerializeTextLines()
		{
			return PropertyShouldSerialize("Text");
		}

		private void ResetTextLines()
		{
			PropertyReset("Text");
		}

		private bool ShouldSerializeText()
		{
			return PropertyShouldSerialize("Text");
		}

		private void ResetText()
		{
			PropertyReset("Text");
		}

		protected override void InternalOnMouseLeft(MouseEventArgs e)
		{
			if (FocusControl != null)
			{
				FocusControl.Focus();
			}
		}

		protected void RepositionControl()
		{
			AlignLeft();
		}

		public void AlignLeft()
		{
			if (FocusControl != null)
			{
				m_NewLocationX = FocusControl.Location.X - m_AlignOffset - ((Control)this).Width;
				m_NewLocationY = FocusControl.Location.Y + FocusControl.Height / 2 - ((Control)this).Height / 2;
				((Control)this).Location = new Point(m_NewLocationX, m_NewLocationY);
			}
		}

		public void AlignRight()
		{
			if (FocusControl != null)
			{
				m_NewLocationX = FocusControl.Location.X + m_AlignOffset + FocusControl.Width;
				m_NewLocationY = FocusControl.Location.Y + FocusControl.Height / 2 - ((Control)this).Height / 2;
				((Control)this).Location = new Point(m_NewLocationX, m_NewLocationY);
			}
		}

		public void AlignTop()
		{
			if (FocusControl != null)
			{
				m_NewLocationX = FocusControl.Location.X;
				m_NewLocationY = FocusControl.Top - m_AlignOffset - ((Control)this).Height;
				((Control)this).Location = new Point(m_NewLocationX, m_NewLocationY);
			}
		}

		public void AlignBottom()
		{
			if (FocusControl != null)
			{
				m_NewLocationX = FocusControl.Location.X;
				m_NewLocationY = FocusControl.Bottom + m_AlignOffset;
				((Control)this).Location = new Point(m_NewLocationX, m_NewLocationY);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			Rectangle drawRectangle = p.DrawRectangle;
			int actualOffset = TextShadow.ActualOffset;
			if (TextShadow.Style != ShadowStyle.None)
			{
				int num = ((TextShadow.Style == ShadowStyle.Raised) ? 1 : (-1));
				drawRectangle.Offset(actualOffset * num, actualOffset * num);
				if (TextShadow.Stretched)
				{
					for (int i = 0; i < actualOffset; i++)
					{
						((ITextLayoutBase)TextLayout).Draw(p.Graphics, base.Font, p.Graphics.Brush(TextShadow.Color), ((Control)this).Text, drawRectangle);
						drawRectangle.Offset(-num, -num);
					}
				}
				else
				{
					((ITextLayoutBase)TextLayout).Draw(p.Graphics, base.Font, p.Graphics.Brush(TextShadow.Color), ((Control)this).Text, drawRectangle);
				}
			}
			((ITextLayoutBase)TextLayout).Draw(p.Graphics, base.Font, p.Graphics.Brush(base.ForeColor), ((Control)this).Text, p.DrawRectangle);
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class LabelEditorPlugIn : PlugInStandard
	{
		private CheckBox AutoSizeCheckBox;

		private FocusLabel label3;

		private EditMultiLine TextEditMultiLine;

		private ComboBox RotationComboBox;

		private FocusLabel label6;

		private FocusLabel label2;

		private FocusLabel label1;

		private FontButton FontButton;

		private ColorPicker ForeColorPicker;

		private ColorPicker BackColorPicker;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public LabelEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			FontButton = new FontButton();
			AutoSizeCheckBox = new CheckBox();
			label3 = new FocusLabel();
			TextEditMultiLine = new EditMultiLine();
			RotationComboBox = new ComboBox();
			label6 = new FocusLabel();
			ForeColorPicker = new ColorPicker();
			label2 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			((Control)FontButton).Location = new Point(280, 64);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 2;
			((Control)AutoSizeCheckBox).Location = new Point(280, 120);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).Size = new Size(80, 24);
			((Control)AutoSizeCheckBox).TabIndex = 5;
			AutoSizeCheckBox.Text = "Auto Size";
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)TextEditMultiLine;
			((Control)label3).Location = new Point(99, 19);
			((Control)label3).Name = "label3";
			label3.Size = new Size(29, 15);
			label3.Text = "Text";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			TextEditMultiLine.EditFont = null;
			((Control)TextEditMultiLine).Location = new Point(128, 16);
			((Control)TextEditMultiLine).Name = "TextEditMultiLine";
			TextEditMultiLine.PropertyName = "Text";
			((Control)TextEditMultiLine).Size = new Size(232, 20);
			((Control)TextEditMultiLine).TabIndex = 0;
			((Control)RotationComboBox).Location = new Point(128, 120);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 4;
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(79, 122);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((Control)ForeColorPicker).Location = new Point(128, 64);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(136, 21);
			((Control)ForeColorPicker).TabIndex = 1;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label2).Location = new Point(69, 67);
			((Control)label2).Name = "label2";
			label2.Size = new Size(59, 15);
			label2.Text = "Fore Color";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(128, 88);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 3;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(67, 91);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(168, 154);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(128, 152);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 6;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(24, 154);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)TextEditMultiLine);
			((Control)this).Controls.Add((Control)(object)label3);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Name = "LabelEditorPlugIn";
			((Control)this).Size = new Size(432, 200);
			base.Title = "Label Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new TextLayoutFullEditorPlugin(), "Text Layout", sameLevel: false);
			AddSubPlugIn(new ShadowEditorPlugIn(), "Text Shadow", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as Label).TextLayout;
			base.SubPlugIns[1].Value = (base.Value as Label).TextShadow;
			base.SubPlugIns[2].Value = (base.Value as Label).Border;
		}
	}
	public class LedDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("ForeColor");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
			properties.Remove("CausesValidation");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("ForeColorChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[ToolboxBitmap(typeof(Access), "Led.bmp")]
	[DesignerCategory("code")]
	[Description("Led")]
	[DefaultEvent("ValueChanged")]
	[DefaultProperty("Name")]
	[Designer(typeof(LedDesigner))]
	public class Led : ControlBase
	{
		private ValueBoolean m_Value;

		private IndicatorLed m_Indicator;

		private bool m_BlinkerEnabled;

		private int m_BlinkerRate;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		[Description("Value Properties")]
		public ValueBoolean Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsBoolean = value.AsBoolean;
			}
		}

		[Category("Iocomp")]
		[Description("Indicator Properties")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public IndicatorLed Indicator => m_Indicator;

		[Description("")]
		[Category("Iocomp")]
		public bool BlinkerEnabled
		{
			get
			{
				return m_BlinkerEnabled;
			}
			set
			{
				PropertyUpdateDefault("BlinkerEnabled", value);
				if (BlinkerEnabled != value)
				{
					m_BlinkerEnabled = value;
					DoPropertyChange(this, "BlinkerEnabled");
					if (m_BlinkerEnabled && !base.Designing)
					{
						AnimationTimerCreate(BlinkerRate);
					}
					else
					{
						AnimationTimerDestroy();
					}
				}
			}
		}

		[Category("Iocomp")]
		[Description("")]
		public int BlinkerRate
		{
			get
			{
				return m_BlinkerRate;
			}
			set
			{
				PropertyUpdateDefault("BlinkerRate", value);
				if (BlinkerRate != value)
				{
					m_BlinkerRate = value;
					DoPropertyChange(this, "BlinkerRate");
					if (m_BlinkerEnabled && !base.Designing)
					{
						AnimationTimerDestroy();
						AnimationTimerCreate(BlinkerRate);
					}
				}
			}
		}

		[Category("Iocomp")]
		public event ValueBooleanEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueBooleanEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new LedEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Led";
		}

		public Led()
		{
			m_License = LicenseManager.Validate(typeof(Led), this);
			DoCreate();
		}

		~Led()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Value = new ValueBoolean();
			AddSubClass(Value);
			m_Indicator = new IndicatorLed();
			AddSubClass(Indicator);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			Indicator.Bezel.Style = BevelStyle.Raised;
			Indicator.Bezel.Color = Color.Empty;
			Indicator.Bezel.Thickness = 4;
			Indicator.Style = ShapeBasic.Ellipse;
			Indicator.Style3D = IndicatorStyleLED3D.Thin;
			Indicator.Text = "";
			Indicator.TextColorActive = Color.Black;
			Indicator.TextColorInactive = Color.White;
			Indicator.ColorInactiveAuto = true;
			Indicator.ColorActive = Color.Lime;
			Indicator.ColorInactive = iColors.ToOffColor(Color.Lime);
			BlinkerEnabled = false;
			BlinkerRate = 500;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(32, 32);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeIndicator()
		{
			return ((ISubClassBase)Indicator).ShouldSerialize();
		}

		private void ResetIndicator()
		{
			((ISubClassBase)Indicator).ResetToDefault();
		}

		private bool ShouldSerializeBlinkerEnabled()
		{
			return PropertyShouldSerialize("BlinkerEnabled");
		}

		private void ResetBlinkerEnabled()
		{
			PropertyReset("BlinkerEnabled");
		}

		private bool ShouldSerializeBlinkerRate()
		{
			return PropertyShouldSerialize("BlinkerRate");
		}

		private void ResetBlinkerRate()
		{
			PropertyReset("BlinkerRate");
		}

		private void OnValueChanged(object sender, ValueBooleanEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueBooleanEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void AnimationTimerHandler(object sender)
		{
			Value.AsBoolean = !Value.AsBoolean;
		}

		protected override void DoPaint(PaintArgs p)
		{
			((IIndicatorLed)Indicator).Draw(p, p.DrawRectangle, Value.AsBoolean);
		}
	}
}
namespace Iocomp.Design
{
	public class LedBarDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("ForeColor");
			properties.Remove("Font");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("ForeColorChanged");
			events.Remove("FontChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[ToolboxBitmap(typeof(Access), "LedBar.bmp")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[Description("LedBar")]
	[DefaultEvent("ValueChanged")]
	[DefaultProperty("Name")]
	[DesignerCategory("code")]
	[Designer(typeof(LedBarDesigner))]
	public class LedBar : ControlBase
	{
		private ColorSectionCollection m_ColorSections;

		private ValueDouble m_Value;

		private ScaleRangeLinear m_ScaleRange;

		private ScaleDrawSegments m_ScaleDraw;

		private SegmentsLedBar m_Segments;

		private Outline m_Outline;

		protected override int SpecialOffset => Outline.Thickness;

		[Category("Iocomp")]
		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ColorSectionCollection ColorSections => m_ColorSections;

		[Description("")]
		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ValueDouble Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsDouble = value.AsDouble;
			}
		}

		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		public ScaleRangeLinear ScaleRange => m_ScaleRange;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		[Description("")]
		public SegmentsLedBar Segments => m_Segments;

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("Outline properties")]
		public Outline Outline => m_Outline;

		private ScaleDrawSegments ScaleDraw => m_ScaleDraw;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new LedBarEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Led Bar";
		}

		public LedBar()
		{
			m_License = LicenseManager.Validate(typeof(LedBar), this);
			DoCreate();
		}

		~LedBar()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_ColorSections = new ColorSectionCollection(this);
			m_ScaleDraw = new ScaleDrawSegments();
			m_Value = new ValueDouble();
			AddSubClass(Value);
			m_ScaleRange = new ScaleRangeLinear();
			AddSubClass(ScaleRange);
			m_Segments = new SegmentsLedBar();
			AddSubClass(Segments);
			m_Outline = new Outline();
			AddSubClass(Outline);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetComponentDefaults()
		{
			ColorSections.Reset();
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			Outline.Thickness = 2;
			Outline.Color = Color.Black;
			((Control)this).TabStop = false;
			Segments.Color = Color.Lime;
			Segments.Separation = 1;
			Segments.Thickness = 1;
			Segments.Width = 12;
			Segments.CountDesired = 100;
			Segments.ShowOffSegments = true;
			Segments.Style = SegmentsLedStyle.Flat;
			ScaleRange.Span = 100.0;
			ScaleRange.Min = 0.0;
			ScaleRange.Reverse = false;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(16, 201);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			return ((ISegmentsLedBar)Segments).RequiredSize;
		}

		protected override void ManualSizeFixup(int innerWidth, int innerHeight)
		{
			Segments.CountDesired = (innerHeight + Segments.Separation) / (Segments.Thickness + Segments.Separation);
			Segments.Width = innerWidth;
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == Segments)
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeColorSections()
		{
			return true;
		}

		private void ResetColorSections()
		{
			ColorSections.Reset();
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeScaleRange()
		{
			return ((ISubClassBase)ScaleRange).ShouldSerialize();
		}

		private void ResetScaleRange()
		{
			((ISubClassBase)ScaleRange).ResetToDefault();
		}

		private bool ShouldSerializeSegments()
		{
			return ((ISubClassBase)Segments).ShouldSerialize();
		}

		private void ResetSegments()
		{
			((ISubClassBase)Segments).ResetToDefault();
		}

		private bool ShouldSerializeOutline()
		{
			return ((ISubClassBase)Outline).ShouldSerialize();
		}

		private void ResetOutline()
		{
			((ISubClassBase)Outline).ResetToDefault();
		}

		private void OnValueChanged(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			((IOutline)Outline).Draw(p, p.DrawRectangle);
			ScaleDraw.Rectangle = p.DrawRectangle;
			int num = (ScaleDraw.SpanPixels + Segments.Separation) / (Segments.Thickness + Segments.Separation);
			int value = (ScaleDraw.SpanPixels - num * (Segments.Thickness + Segments.Separation) + Segments.Separation) / 2;
			ScaleDraw.OffsetEnds(value);
			iRectangle r = new iRectangle(p.DrawRectangle);
			ScaleDraw.SetStartRectangle(r, Segments.Width, Segments.Thickness, ScaleRange.Reverse);
			for (int i = 0; i < num; i++)
			{
				double num2 = ScaleRange.PercentToValue((double)i / (double)num);
				bool active = num2 < Value.AsDouble;
				((ISegmentsLedBar)Segments).Draw(p, active, r, ColorSections.GetColor(num2, Segments.Color));
				ScaleDraw.ShiftRectangle(r, Segments.Thickness + Segments.Separation, ScaleRange.Reverse);
			}
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class LedBarEditorPlugIn : PlugInStandard
	{
		private CheckBox AutoSizeCheckBox;

		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private FocusLabel label1;

		private ColorPicker BackColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public LedBarEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			AutoSizeCheckBox = new CheckBox();
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			BackColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			((Control)AutoSizeCheckBox).Location = new Point(280, 88);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 3;
			AutoSizeCheckBox.Text = "Auto Size";
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(87, 90);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(136, 88);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 2;
			((Control)BackColorPicker).Location = new Point(136, 56);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 1;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(75, 59);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(136, 8);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(100, 10);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(176, 122);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(136, 120);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 4;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(32, 122);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Name = "LedBarEditorPlugIn";
			((Control)this).Size = new Size(432, 176);
			base.Title = "Led Bar Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueDoubleEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new SegmentsLedBarEditorPlugIn(), "Segments", sameLevel: false);
			AddSubPlugIn(new ColorSectionCollectionEditorPlugIn(), "Color Sections", sameLevel: false);
			AddSubPlugIn(new ScaleRangeLinearEditorPlugIn(), "Scale Range", sameLevel: false);
			AddSubPlugIn(new OutlineEditorPlugIn(), "Outline", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as LedBar).Value;
			base.SubPlugIns[1].Value = (base.Value as LedBar).Segments;
			base.SubPlugIns[2].Value = (base.Value as LedBar).ColorSections;
			base.SubPlugIns[3].Value = (base.Value as LedBar).ScaleRange;
			base.SubPlugIns[4].Value = (base.Value as LedBar).Outline;
			base.SubPlugIns[5].Value = (base.Value as LedBar).Border;
		}
	}
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class LedEditorPlugIn : PlugInStandard
	{
		private CheckBox AutoSizeCheckBox;

		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private FocusLabel label2;

		private FocusLabel label1;

		private FontButton FontButton;

		private ColorPicker ForeColorPicker;

		private ColorPicker BackColorPicker;

		private CheckBox ValueCheckBox;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public LedEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			FontButton = new FontButton();
			AutoSizeCheckBox = new CheckBox();
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			ForeColorPicker = new ColorPicker();
			label2 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			ValueCheckBox = new CheckBox();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			((Control)FontButton).Location = new Point(312, 56);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 2;
			((Control)AutoSizeCheckBox).Location = new Point(312, 120);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).Size = new Size(72, 24);
			((Control)AutoSizeCheckBox).TabIndex = 5;
			AutoSizeCheckBox.Text = "Auto Size";
			label6.LoadingBegin();
			label6.AutoSize = false;
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(115, 120);
			((Control)label6).Name = "label6";
			label6.Size = new Size(45, 18);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(160, 120);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 4;
			((Control)ForeColorPicker).Location = new Point(160, 56);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(136, 21);
			((Control)ForeColorPicker).TabIndex = 1;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label2).Location = new Point(101, 59);
			((Control)label2).Name = "label2";
			label2.Size = new Size(59, 15);
			label2.Text = "Fore Color";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(160, 80);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 3;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(99, 83);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)ValueCheckBox).Location = new Point(160, 8);
			((Control)ValueCheckBox).Name = "ValueCheckBox";
			ValueCheckBox.PropertyName = "Value";
			((Control)ValueCheckBox).TabIndex = 0;
			ValueCheckBox.Text = "Value";
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(200, 154);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(160, 152);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 6;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(56, 154);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)ValueCheckBox);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Name = "LedEditorPlugIn";
			((Control)this).Size = new Size(432, 192);
			base.Title = "Led Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueBooleanEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new IndicatorLedEditorPlugIn(), "Indicator", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as Led).Value;
			base.SubPlugIns[1].Value = (base.Value as Led).Indicator;
			base.SubPlugIns[2].Value = (base.Value as Led).Border;
		}
	}
	public class LedSpiralDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("ForeColor");
			properties.Remove("Font");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("ForeColorChanged");
			events.Remove("FontChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[DefaultProperty("Name")]
	[DesignerCategory("code")]
	[Designer(typeof(LedSpiralDesigner))]
	[Description("LedSpiral")]
	[DefaultEvent("ValueChanged")]
	[ToolboxBitmap(typeof(Access), "LedSpiral.bmp")]
	public class LedSpiral : ControlBase
	{
		private ColorSectionCollection m_ColorSections;

		private ValueDouble m_Value;

		private ScaleRangeAngular m_ScaleRange;

		private SegmentsLedSpiral m_Segments;

		private int m_InnerRadius;

		[Category("Iocomp")]
		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ColorSectionCollection ColorSections => m_ColorSections;

		[Description("")]
		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ValueDouble Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsDouble = value.AsDouble;
			}
		}

		[Description("")]
		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ScaleRangeAngular ScaleRange => m_ScaleRange;

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		public SegmentsLedSpiral Segments => m_Segments;

		[RefreshProperties(RefreshProperties.All)]
		[Category("Iocomp")]
		[Description("")]
		public int InnerRadius
		{
			get
			{
				return m_InnerRadius;
			}
			set
			{
				PropertyUpdateDefault("InnerRadius", value);
				if (InnerRadius != value)
				{
					m_InnerRadius = value;
					DoAutoSize();
					DoPropertyChange(this, "InnerRadius");
				}
			}
		}

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new LedSpiralEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Led Spiral";
		}

		public LedSpiral()
		{
			m_License = LicenseManager.Validate(typeof(LedSpiral), this);
			DoCreate();
		}

		~LedSpiral()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_ColorSections = new ColorSectionCollection(this);
			m_Value = new ValueDouble();
			AddSubClass(Value);
			m_ScaleRange = new ScaleRangeAngular();
			AddSubClass(ScaleRange);
			m_Segments = new SegmentsLedSpiral();
			AddSubClass(Segments);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetComponentDefaults()
		{
			ColorSections.Reset();
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			InnerRadius = 30;
			ScaleRange.AngleMin = 180.0;
			ScaleRange.AngleSpan = 360.0;
			ScaleRange.Min = 0.0;
			ScaleRange.Span = 100.0;
			ScaleRange.Reverse = false;
			Segments.Color = Color.Lime;
			Segments.Separation = 3;
			Segments.Thickness = 3;
			Segments.Width = 15;
			Segments.ShowOffSegments = true;
			Segments.Style = SegmentsLedStyle.Flat;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(78, 78);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			return new Size(2 * (InnerRadius + Segments.Width + 1), 2 * (InnerRadius + Segments.Width + 1));
		}

		protected override void ManualSizeFixup(int innerWidth, int innerHeight)
		{
			if (innerWidth < innerHeight)
			{
				InnerRadius = innerWidth / 2 - Segments.Width - 1;
			}
			else
			{
				InnerRadius = innerHeight / 2 - Segments.Width - 1;
			}
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == this && propertyName == "InnerRadius")
			{
				DoAutoSize();
			}
			if (sender == Segments && propertyName == "Width")
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeColorSections()
		{
			return true;
		}

		private void ResetColorSections()
		{
			ColorSections.Reset();
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeScaleRange()
		{
			return ((ISubClassBase)ScaleRange).ShouldSerialize();
		}

		private void ResetScaleRange()
		{
			((ISubClassBase)ScaleRange).ResetToDefault();
		}

		private bool ShouldSerializeSegments()
		{
			return ((ISubClassBase)Segments).ShouldSerialize();
		}

		private void ResetSegments()
		{
			((ISubClassBase)Segments).ResetToDefault();
		}

		private bool ShouldSerializeInnerRadius()
		{
			return PropertyShouldSerialize("InnerRadius");
		}

		private void ResetInnerRadius()
		{
			PropertyReset("InnerRadius");
		}

		private void OnValueChanged(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			p.Graphics.SmoothingMode = (SmoothingMode)4;
			if (Segments.Thickness + Segments.Separation < 1)
			{
				return;
			}
			double num = (double)(InnerRadius * 2) * Math.PI * ScaleRange.AngleSpan / 360.0;
			int num2 = ((ScaleRange.AngleSpan != 360.0) ? ((int)((num + (double)Segments.Separation) / (double)(Segments.Thickness + Segments.Separation))) : ((int)(num / (double)(Segments.Thickness + Segments.Separation))));
			if (num2 >= 2)
			{
				int num3 = ((ScaleRange.AngleSpan != 360.0) ? (num2 * (Segments.Thickness + Segments.Separation) - Segments.Separation) : (num2 * (Segments.Thickness + Segments.Separation)));
				double num4 = ScaleRange.Span / (double)num3 * (double)Segments.Thickness;
				double num5 = ScaleRange.Span / (double)num3 * (double)(Segments.Thickness + Segments.Separation);
				for (int i = 0; i < num2; i++)
				{
					double num6 = (double)i * num5;
					bool active = num6 < Value.AsDouble;
					double num7 = ((IScaleRangeAngular)ScaleRange).ValueToAngle(num6);
					double num8 = ((IScaleRangeAngular)ScaleRange).ValueToAngle(num6 + num4);
					((ISegmentsLedSpiral)Segments).Draw(p, active, (float)num7, (float)num8, InnerRadius, ColorSections.GetColor(num6, Segments.Color));
				}
			}
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class LedSpiralEditorPlugIn : PlugInStandard
	{
		private CheckBox AutoSizeCheckBox;

		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private FocusLabel label7;

		private NumericUpDown InnerRadiusNumericUpDown;

		private FocusLabel label1;

		private ColorPicker BackColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public LedSpiralEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			AutoSizeCheckBox = new CheckBox();
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			InnerRadiusNumericUpDown = new NumericUpDown();
			label7 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			((Control)AutoSizeCheckBox).Location = new Point(304, 120);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 4;
			AutoSizeCheckBox.Text = "Auto Size";
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(111, 122);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(160, 120);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 3;
			((Control)InnerRadiusNumericUpDown).Location = new Point(160, 48);
			((NumericUpDown)InnerRadiusNumericUpDown).Maximum = new decimal(new int[4] { 1000, 0, 0, 0 });
			((Control)InnerRadiusNumericUpDown).Name = "InnerRadiusNumericUpDown";
			InnerRadiusNumericUpDown.PropertyName = "InnerRadius";
			((Control)InnerRadiusNumericUpDown).Size = new Size(56, 20);
			((Control)InnerRadiusNumericUpDown).TabIndex = 1;
			((UpDownBase)InnerRadiusNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label7.LoadingBegin();
			label7.FocusControl = (Control)(object)InnerRadiusNumericUpDown;
			((Control)label7).Location = new Point(90, 49);
			((Control)label7).Name = "label7";
			label7.Size = new Size(70, 15);
			label7.Text = "Inner Radius";
			label7.UpdateFrameRate = 50.0;
			label7.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(160, 88);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 2;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(99, 91);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(160, 16);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(124, 18);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(200, 154);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(160, 152);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 5;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(56, 154);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)InnerRadiusNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label7);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Name = "LedSpiralEditorPlugIn";
			((Control)this).Size = new Size(440, 216);
			base.Title = "Led Spiral Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueDoubleEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new SegmentsLedSpiralEditorPlugIn(), "Segments", sameLevel: false);
			AddSubPlugIn(new ColorSectionCollectionEditorPlugIn(), "Color Sections", sameLevel: false);
			AddSubPlugIn(new ScaleRangeAngularEditorPlugIn(), "Scale Range", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as LedSpiral).Value;
			base.SubPlugIns[1].Value = (base.Value as LedSpiral).Segments;
			base.SubPlugIns[2].Value = (base.Value as LedSpiral).ColorSections;
			base.SubPlugIns[3].Value = (base.Value as LedSpiral).ScaleRange;
			base.SubPlugIns[4].Value = (base.Value as LedSpiral).Border;
		}
	}
	public class ModeComboBoxDesigner : ControlDesigner
	{
		public override SelectionRules SelectionRules => (SelectionRules)(base.SelectionRules & -2 & -3);

		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("DataSource");
			properties.Remove("DisplayMember");
			properties.Remove("DrawMode");
			properties.Remove("DropDownStyle");
			properties.Remove("ImeMode");
			properties.Remove("MaxLength");
			properties.Remove("RightToLeft");
			properties.Remove("Sorted");
			properties.Remove("Text");
			properties.Remove("ValueMember");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("DataSourceChanged");
			events.Remove("DisplayMemberChanged");
			events.Remove("DrawItem");
			events.Remove("DropDownStyleChanged");
			events.Remove("MeasureItem");
			events.Remove("RightToLeftChanged");
			events.Remove("SelectedIndexChanged");
			events.Remove("SelectedValueChanged");
			events.Remove("SelectionChangeCommitted");
			events.Remove("StyleChanged");
			events.Remove("TextChanged");
			events.Remove("ValueMemberChanged");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[DesignerCategory("code")]
	[Designer(typeof(ModeComboBoxDesigner))]
	[ToolboxItem(true)]
	[DefaultEvent("ValueChanged")]
	[DefaultProperty("Name")]
	[ToolboxBitmap(typeof(Access), "ModeComboBox.bmp")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[Description("ModeComboBox")]
	public class ModeComboBox : ComboBoxBase
	{
		private ValueDouble m_Value;

		private ModeComboBoxItemCollection m_Items;

		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		public ValueDouble Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsDouble = value.AsDouble;
			}
		}

		[Description("")]
		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ModeComboBoxItemCollection Items => m_Items;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new ModeComboBoxEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Mode ComboBox";
		}

		public ModeComboBox()
		{
			m_License = LicenseManager.Validate(typeof(ModeComboBox), this);
			DoCreate();
		}

		~ModeComboBox()
		{
			try
			{
				((Component)(object)this).Dispose();
			}
			finally
			{
				((ComboBox)this).Finalize();
			}
		}

		protected override void CreateObjects()
		{
			m_Value = new ValueDouble();
			AddSubClass(Value);
			m_Items = new ModeComboBoxItemCollection(this);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			((ComboBox)this).DropDownStyle = (ComboBoxStyle)2;
		}

		protected override void Loaded()
		{
			RegenerateList();
		}

		protected override Size GetDefaultSize()
		{
			return new Size(121, 21);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender is ModeComboBoxItem)
			{
				ItemPropertyChange();
			}
			if (sender is ModeComboBoxItemCollection)
			{
				ItemPropertyChange();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeItems()
		{
			return Items.Count != 0;
		}

		private void ResetItems()
		{
			Items.Clear();
		}

		private void OnValueChanged(object sender, ValueDoubleEventArgs e)
		{
			((ListControl)this).SelectedIndex = Items.IndexOf(e.ValueNew);
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void InternalOnSelectionChangeCommitted(EventArgs e)
		{
			if (((ListControl)this).SelectedIndex != -1)
			{
				Value.AsDouble = Items[((ListControl)this).SelectedIndex].Value;
			}
		}

		protected override void InternalOnSelectedIndexChanged(EventArgs e)
		{
			if (((ListControl)this).SelectedIndex != -1)
			{
				Value.AsDouble = Items[((ListControl)this).SelectedIndex].Value;
			}
		}

		private void RegenerateList()
		{
			((ComboBox)this).Items.Clear();
			foreach (ModeComboBoxItem item in Items)
			{
				((ComboBox)this).Items.Add((object)item.Text);
			}
			((ListControl)this).SelectedIndex = Items.IndexOf(Value.AsDouble);
		}

		private void ItemPropertyChange()
		{
			RegenerateList();
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class ModeComboBoxEditorPlugIn : PlugInStandard
	{
		private FocusLabel label4;

		private FocusLabel label1;

		private FontButton FontButton;

		private ColorPicker ForeColorPicker;

		private ColorPicker BackColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public ModeComboBoxEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			FontButton = new FontButton();
			label4 = new FocusLabel();
			ForeColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			((Control)FontButton).Location = new Point(288, 64);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 2;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label4).Location = new Point(85, 67);
			((Control)label4).Name = "label4";
			label4.Size = new Size(59, 15);
			label4.Text = "Fore Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)ForeColorPicker).Location = new Point(144, 64);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(136, 21);
			((Control)ForeColorPicker).TabIndex = 1;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(83, 91);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(144, 88);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 3;
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(144, 16);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(108, 18);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(184, 122);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(144, 120);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 4;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(40, 122);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Name = "ModeComboBoxEditorPlugIn";
			((Control)this).Size = new Size(416, 168);
			base.Title = "Mode ComboBox Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueDoubleEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new ModeComboBoxItemCollectionEditorPlugIn(), "Items", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as ModeComboBox).Value;
			base.SubPlugIns[1].Value = (base.Value as ModeComboBox).Items;
		}
	}
}
namespace Iocomp.Classes
{
	[DefaultProperty("Value")]
	[TypeConverter(typeof(CollectionItemConverter))]
	public class ModeComboBoxItem : SubClassBase
	{
		private double m_Value;

		private string m_Text;

		[Description("")]
		[Category("Iocomp")]
		public double Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				PropertyUpdateDefault("Value", value);
				if (Value != value)
				{
					m_Value = value;
					DoPropertyChange(this, "Value");
				}
			}
		}

		[Category("Iocomp")]
		[Description("")]
		public string Text
		{
			get
			{
				return m_Text;
			}
			set
			{
				PropertyUpdateDefault("Text", value);
				if (Text != value)
				{
					m_Text = value;
					DoPropertyChange(this, "Text");
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new ModeComboBoxItemEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Mode ComboBox Item";
		}

		public ModeComboBoxItem()
		{
			DoCreate();
		}

		public ModeComboBoxItem(double Value, string s)
		{
			DoCreate();
			m_Value = Value;
			m_Text = s;
		}

		protected override void CreateObjects()
		{
			base.CreateObjects();
			Value = 0.0;
			Text = "Undefined";
		}

		private bool ShouldSerializeValue()
		{
			return PropertyShouldSerialize("Value");
		}

		private void ResetValue()
		{
			PropertyReset("Value");
		}

		private bool ShouldSerializeText()
		{
			return PropertyShouldSerialize("Text");
		}

		private void ResetText()
		{
			PropertyReset("Text");
		}

		public override string ToString()
		{
			return Text;
		}
	}
	public class ModeComboBoxItemCollection : CollectionBase
	{
		public ModeComboBoxItem this[int index]
		{
			get
			{
				return base.List[index] as ModeComboBoxItem;
			}
			set
			{
				base.List[index] = value;
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new ModeComboBoxItemCollectionEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Item Collection";
		}

		public ModeComboBoxItemCollection()
			: base(null)
		{
		}

		public ModeComboBoxItemCollection(IComponentBase componentBase)
			: base(componentBase)
		{
		}

		public void CopyTo(ModeComboBoxItem[] array, int index)
		{
			((ICollection)this).CopyTo((Array)array, index);
		}

		public int Add(ModeComboBoxItem value)
		{
			return base.List.Add(value);
		}

		public void Insert(int index, ModeComboBoxItem value)
		{
			base.List.Insert(index, value);
		}

		public void Remove(ModeComboBoxItem value)
		{
			base.List.Remove(value);
		}

		public int IndexOf(ModeComboBoxItem value)
		{
			return base.List.IndexOf(value);
		}

		public bool Contains(ModeComboBoxItem value)
		{
			return base.List.Contains(value);
		}

		public int IndexOf(double value)
		{
			for (int i = 0; i < base.Count; i++)
			{
				if (this[i].Value == value)
				{
					return i;
				}
			}
			return -1;
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("code")]
	public class ModeComboBoxItemCollectionEditorPlugIn : PlugInCollection
	{
		protected override Type[] Types => new Type[1] { typeof(ModeComboBoxItem) };

		public ModeComboBoxItemCollectionEditorPlugIn()
		{
			base.Title = "Item Collection Editor";
		}

		protected override PlugInStandard[] CreatePlugInPool()
		{
			return new PlugInStandard[1]
			{
				new ModeComboBoxItemEditorPlugIn()
			};
		}

		protected override PlugInStandard GetClassPlugIn(object value)
		{
			if (value is ModeComboBoxItem)
			{
				return base.PlugInPool[0];
			}
			return null;
		}

		protected override int GetPlugInIndex(object value)
		{
			if (value is ModeComboBoxItem)
			{
				return 0;
			}
			return 0;
		}
	}
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class ModeComboBoxItemEditorPlugIn : PlugInStandard
	{
		private FocusLabel label2;

		private FocusLabel label1;

		private EditBox ValueTextBox;

		private EditBox TextTextBox;

		private Container components = null;

		public ModeComboBoxItemEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			ValueTextBox = new EditBox();
			label2 = new FocusLabel();
			TextTextBox = new EditBox();
			label1 = new FocusLabel();
			((Control)this).SuspendLayout();
			ValueTextBox.LoadingBegin();
			((Control)ValueTextBox).Location = new Point(80, 72);
			((Control)ValueTextBox).Name = "ValueTextBox";
			ValueTextBox.PropertyName = "Value";
			ValueTextBox.Size = new Size(128, 20);
			((Control)ValueTextBox).TabIndex = 1;
			ValueTextBox.LoadingEnd();
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)ValueTextBox;
			((Control)label2).Location = new Point(44, 74);
			((Control)label2).Name = "label2";
			label2.Size = new Size(36, 15);
			label2.Text = "Value";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			TextTextBox.LoadingBegin();
			((Control)TextTextBox).Location = new Point(80, 48);
			((Control)TextTextBox).Name = "TextTextBox";
			TextTextBox.PropertyName = "Text";
			TextTextBox.Size = new Size(128, 20);
			((Control)TextTextBox).TabIndex = 0;
			TextTextBox.LoadingEnd();
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)TextTextBox;
			((Control)label1).Location = new Point(51, 50);
			((Control)label1).Name = "label1";
			label1.Size = new Size(29, 15);
			label1.Text = "Text";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)TextTextBox);
			((Control)this).Controls.Add((Control)(object)ValueTextBox);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Name = "ModeComboBoxItemEditorPlugIn";
			((Control)this).Size = new Size(400, 136);
			((Control)this).Tag = "1";
			((Control)this).ResumeLayout(false);
		}
	}
	public class OdometerDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
			properties.Remove("CausesValidation");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[ToolboxBitmap(typeof(Access), "Odometer.bmp")]
	[Designer(typeof(OdometerDesigner))]
	[DesignerCategory("code")]
	[Description("Odometer")]
	[DefaultEvent("ValueChanged")]
	[DefaultProperty("Name")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	public class Odometer : ControlBase
	{
		private ValueDouble m_Value;

		private OdometerDigits m_Digits;

		private OdometerTenths m_Tenths;

		private int m_LastAutoSizeHeight;

		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		public ValueDouble Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsDouble = value.AsDouble;
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		[Description("")]
		public OdometerDigits Digits => m_Digits;

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		public OdometerTenths Tenths => m_Tenths;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new OdometerEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Odometer";
		}

		public Odometer()
		{
			m_License = LicenseManager.Validate(typeof(Odometer), this);
			DoCreate();
		}

		~Odometer()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Value = new ValueDouble();
			AddSubClass(Value);
			m_Digits = new OdometerDigits();
			AddSubClass(Digits);
			m_Tenths = new OdometerTenths();
			AddSubClass(Tenths);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			m_LastAutoSizeHeight = 18;
			Digits.Count = 5;
			Digits.BackColor1 = Color.White;
			Digits.BackColor2 = Color.Empty;
			Digits.ForeColor = Color.Empty;
			Digits.BorderColor = Color.Transparent;
			Digits.BackStyle = OdometerBackStyle.Gradient;
			Tenths.Count = 1;
			Tenths.BackColor1 = Color.Gray;
			Tenths.BackColor2 = Color.Empty;
			Tenths.ForeColor = Color.White;
			Tenths.BackStyle = OdometerBackStyle.Gradient;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(93, 18);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			int num = (int)((double)base.Font.GetHeight() * 1.5);
			int width = (int)((double)base.Font.GetHeight() * 1.5 * (double)Digits.Count);
			m_LastAutoSizeHeight = num;
			return new Size(width, num);
		}

		public override void LoadingEnd()
		{
			base.LoadingEnd();
			m_LastAutoSizeHeight = base.InnerRectangle.Height;
		}

		protected override void ManualSizeFixup(int innerWidth, int innerHeight)
		{
			//IL_0055: Unknown result type (might be due to invalid IL or missing references)
			//IL_005f: Expected O, but got Unknown
			if (base.AutoSize && m_LastAutoSizeHeight != innerHeight)
			{
				float num = (float)innerHeight / (1.5f * (float)base.Font.Height) * base.Font.Size;
				num = (float)Math.Round(num, 2);
				if (num > 1f)
				{
					base.Font = new Font(base.Font.Name, num, (FontStyle)0);
					m_LastAutoSizeHeight = innerHeight;
				}
			}
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == Digits && propertyName == "Count")
			{
				DoAutoSize();
			}
			if (sender == Tenths && propertyName == "Count")
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "Font")
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeDigits()
		{
			return ((ISubClassBase)Digits).ShouldSerialize();
		}

		private void ResetDigits()
		{
			((ISubClassBase)Digits).ResetToDefault();
		}

		private bool ShouldSerializeTenths()
		{
			return ((ISubClassBase)Tenths).ShouldSerialize();
		}

		private void ResetTenths()
		{
			((ISubClassBase)Tenths).ResetToDefault();
		}

		private void OnValueChanged(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		private void DrawDigitBorders(PaintArgs p, int digitWidth)
		{
			Pen pen = p.Graphics.Pen(Digits.BorderColor);
			p.Graphics.DrawLine(pen, p.Left, p.Top, p.Right, p.Top);
			p.Graphics.DrawLine(pen, p.Right, p.Top, p.Right, p.Bottom);
			p.Graphics.DrawLine(pen, p.Right, p.Bottom, p.Left, p.Bottom);
			p.Graphics.DrawLine(pen, p.Left, p.Bottom, p.Left, p.Top);
			for (int i = 0; i < Digits.Count; i++)
			{
				int num = p.Right - i * digitWidth;
				p.Graphics.DrawLine(pen, num, p.Top, num, p.Bottom);
			}
		}

		private void DrawBackground(PaintArgs p, int digitWidth)
		{
			iRectangle iRectangle = new iRectangle(p.DrawRectangle);
			iRectangle.Width -= Tenths.Count * digitWidth;
			if (Digits.BackStyle == OdometerBackStyle.Gradient)
			{
				p.Graphics.DrawGradientRect(Digits.BackColor1, iColors.Darken1(Digits.BackColor2), iRectangle.Rectangle, vertical: true, center: true, sigma: true);
			}
			else if (Digits.BackStyle == OdometerBackStyle.Flat)
			{
				p.Graphics.FillRectangle(p.Graphics.Brush(Digits.BackColor1), iRectangle.Rectangle);
			}
			iRectangle.Rectangle = p.DrawRectangle;
			if (Tenths.Count > 0)
			{
				iRectangle.Left = iRectangle.Right - Tenths.Count * digitWidth;
				iRectangle.Width = Tenths.Count * digitWidth;
				if (Tenths.BackStyle == OdometerBackStyle.Gradient)
				{
					p.Graphics.DrawGradientRect(Tenths.BackColor1, iColors.Darken1(Digits.BackColor2), iRectangle.Rectangle, vertical: true, center: true, sigma: true);
				}
				else if (Tenths.BackStyle == OdometerBackStyle.Flat)
				{
					p.Graphics.FillRectangle(p.Graphics.Brush(Tenths.BackColor1), iRectangle.Rectangle);
				}
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			if (Digits.Count < 1)
			{
				return;
			}
			p.Graphics.SetClip(p.DrawRectangle);
			int num = p.Width / Digits.Count;
			int height = p.Graphics.MeasureString("0", base.Font).Height;
			int num2 = p.Height / 2 + height / 2;
			DrawBackground(p, num);
			p.Graphics.TextRenderingHint = (TextRenderingHint)5;
			DrawStringFormat genericDefault = DrawStringFormat.GenericDefault;
			genericDefault.Alignment = (StringAlignment)1;
			genericDefault.LineAlignment = (StringAlignment)1;
			string text = Convert2.ToString((int)(Value.AsDouble * Math.Pow(10.0, Tenths.Count)));
			while (text.Length < Digits.Count)
			{
				text = '0' + text;
			}
			bool flag = true;
			float num3 = (float)Math2.Fraction(Value.AsDouble * Math.Pow(10.0, Tenths.Count));
			for (int i = 0; i < Digits.Count; i++)
			{
				string text2 = text.Substring(text.Length - 1 - i, 1);
				Rectangle r = new Rectangle(p.Right - (i + 1) * num, p.Top, num, p.Height);
				int num4 = Convert.ToInt32(text2, CultureInfo.CurrentCulture);
				string s = ((num4 != 9) ? Convert2.ToString(num4 + 1) : "0");
				string s2 = ((num4 != 0) ? Convert2.ToString(num4 - 1) : "9");
				Brush brush = ((i < Tenths.Count) ? p.Graphics.Brush(Tenths.ForeColor) : p.Graphics.Brush(Digits.ForeColor));
				int num5 = (flag ? ((int)((float)num2 * num3)) : 0);
				if (num4 != 9)
				{
					flag = false;
				}
				r.Offset(0, -num5);
				p.Graphics.DrawString(text2, base.Font, brush, r, genericDefault);
				r.Offset(0, -num2);
				p.Graphics.DrawString(s2, base.Font, brush, r, genericDefault);
				r.Offset(0, 2 * num2);
				p.Graphics.DrawString(s, base.Font, brush, r, genericDefault);
			}
			DrawDigitBorders(p, num);
		}
	}
}
namespace Iocomp.Types
{
	public enum OdometerBackStyle
	{
		Gradient,
		Flat,
		None
	}
}
namespace Iocomp.Classes
{
	[DefaultProperty("BackColor")]
	public abstract class OdometerDigit : SubClassBase
	{
		private Color m_BackColor1;

		private Color m_BackColor2;

		private OdometerBackStyle m_BackStyle;

		[Description("")]
		public new Color ForeColor
		{
			get
			{
				return base.ForeColor;
			}
			set
			{
				base.ForeColor = value;
			}
		}

		[Description("")]
		public OdometerBackStyle BackStyle
		{
			get
			{
				return m_BackStyle;
			}
			set
			{
				PropertyUpdateDefault("BackStyle", value);
				if (BackStyle != value)
				{
					m_BackStyle = value;
					DoPropertyChange(this, "BackStyle");
				}
			}
		}

		[Description("")]
		public Color BackColor1
		{
			get
			{
				return m_BackColor1;
			}
			set
			{
				PropertyUpdateDefault("BackColor1", value);
				if (BackColor1 != value)
				{
					m_BackColor1 = value;
					DoPropertyChange(this, "BackColor1");
				}
			}
		}

		[Description("")]
		public Color BackColor2
		{
			get
			{
				if (base.GettingDefault)
				{
					return m_BackColor2;
				}
				if (m_BackColor2 == Color.Empty && ControlBase != null)
				{
					return ControlBase.BackColor;
				}
				return m_BackColor2;
			}
			set
			{
				PropertyUpdateDefault("BackColor2", value);
				if (BackColor2 != value)
				{
					m_BackColor2 = value;
					DoPropertyChange(this, "BackColor2");
				}
			}
		}

		private bool ShouldSerializeForeColor()
		{
			return PropertyShouldSerialize("ForeColor");
		}

		private void ResetForeColor()
		{
			PropertyReset("ForeColor");
		}

		private bool ShouldSerializeBackStyle()
		{
			return PropertyShouldSerialize("BackStyle");
		}

		private void ResetBackStyle()
		{
			PropertyReset("BackStyle");
		}

		private bool ShouldSerializeBackColor1()
		{
			return PropertyShouldSerialize("BackColor1");
		}

		private void ResetBackColor1()
		{
			PropertyReset("BackColor1");
		}

		private bool ShouldSerializeBackColor2()
		{
			return PropertyShouldSerialize("BackColor2");
		}

		private void ResetBackColor2()
		{
			PropertyReset("BackColor2");
		}
	}
	[DefaultProperty("")]
	public sealed class OdometerDigits : OdometerDigit
	{
		private int m_Count;

		private Color m_BorderColor;

		[Description("")]
		public int Count
		{
			get
			{
				return m_Count;
			}
			set
			{
				PropertyUpdateDefault("Count", value);
				if (Count != value)
				{
					m_Count = value;
					DoPropertyChange(this, "Count");
				}
			}
		}

		[Description("")]
		public Color BorderColor
		{
			get
			{
				return m_BorderColor;
			}
			set
			{
				PropertyUpdateDefault("BorderColor", value);
				if (BorderColor != value)
				{
					m_BorderColor = value;
					DoPropertyChange(this, "BorderColor");
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new OdometerDigitsEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Odometer Digits";
		}

		public OdometerDigits()
		{
			DoCreate();
		}

		private bool ShouldSerializeCount()
		{
			return PropertyShouldSerialize("Count");
		}

		private void ResetCount()
		{
			PropertyReset("Count");
		}

		private bool ShouldSerializeBorderColor()
		{
			return PropertyShouldSerialize("BorderColor");
		}

		private void ResetBorderColor()
		{
			PropertyReset("BorderColor");
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class OdometerDigitsEditorPlugIn : PlugInStandard
	{
		private NumericUpDown CountNumericUpDown;

		private FocusLabel label1;

		private GroupBox groupBox1;

		private FocusLabel label6;

		private FocusLabel label3;

		private FocusLabel label2;

		private ComboBox BackStyleComboBox;

		private FocusLabel label4;

		private FocusLabel label5;

		private ColorPicker BackColor2Picker;

		private ColorPicker BackColor1Picker;

		private ColorPicker ForeColorPicker;

		private ColorPicker BorderColorPicker;

		private Container components = null;

		public OdometerDigitsEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			CountNumericUpDown = new NumericUpDown();
			label1 = new FocusLabel();
			groupBox1 = new GroupBox();
			BackStyleComboBox = new ComboBox();
			label6 = new FocusLabel();
			label3 = new FocusLabel();
			BackColor2Picker = new ColorPicker();
			label2 = new FocusLabel();
			BackColor1Picker = new ColorPicker();
			label4 = new FocusLabel();
			ForeColorPicker = new ColorPicker();
			BorderColorPicker = new ColorPicker();
			label5 = new FocusLabel();
			((Control)groupBox1).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)CountNumericUpDown).Location = new Point(80, 0);
			((Control)CountNumericUpDown).Name = "CountNumericUpDown";
			CountNumericUpDown.PropertyName = "Count";
			((Control)CountNumericUpDown).Size = new Size(48, 20);
			((Control)CountNumericUpDown).TabIndex = 0;
			((UpDownBase)CountNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)CountNumericUpDown;
			((Control)label1).Location = new Point(43, 1);
			((Control)label1).Name = "label1";
			label1.Size = new Size(37, 15);
			label1.Text = "Count";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)groupBox1).Controls.Add((Control)(object)BackStyleComboBox);
			((Control)groupBox1).Controls.Add((Control)(object)label6);
			((Control)groupBox1).Controls.Add((Control)(object)label3);
			((Control)groupBox1).Controls.Add((Control)(object)label2);
			((Control)groupBox1).Controls.Add((Control)(object)BackColor2Picker);
			((Control)groupBox1).Controls.Add((Control)(object)BackColor1Picker);
			((Control)groupBox1).Location = new Point(240, 0);
			((Control)groupBox1).Name = "groupBox1";
			((Control)groupBox1).Size = new Size(208, 104);
			((Control)groupBox1).TabIndex = 3;
			groupBox1.TabStop = false;
			((Control)groupBox1).Text = "Back";
			((ComboBox)BackStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)BackStyleComboBox).Location = new Point(56, 16);
			((Control)BackStyleComboBox).Name = "BackStyleComboBox";
			BackStyleComboBox.PropertyName = "BackStyle";
			((Control)BackStyleComboBox).Size = new Size(140, 21);
			((Control)BackStyleComboBox).TabIndex = 0;
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)BackStyleComboBox;
			((Control)label6).Location = new Point(24, 18);
			((Control)label6).Name = "label6";
			label6.Size = new Size(32, 15);
			label6.Text = "Style";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)BackColor2Picker;
			((Control)label3).Location = new Point(13, 75);
			((Control)label3).Name = "label3";
			label3.Size = new Size(43, 15);
			label3.Text = "Color 2";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			((Control)BackColor2Picker).Location = new Point(56, 72);
			((Control)BackColor2Picker).Name = "BackColor2Picker";
			BackColor2Picker.PropertyName = "BackColor2";
			((Control)BackColor2Picker).TabIndex = 2;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)BackColor1Picker;
			((Control)label2).Location = new Point(13, 51);
			((Control)label2).Name = "label2";
			label2.Size = new Size(43, 15);
			label2.Text = "Color 1";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)BackColor1Picker).Location = new Point(56, 48);
			((Control)BackColor1Picker).Name = "BackColor1Picker";
			BackColor1Picker.PropertyName = "BackColor1";
			((Control)BackColor1Picker).TabIndex = 1;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label4).Location = new Point(21, 51);
			((Control)label4).Name = "label4";
			label4.Size = new Size(59, 15);
			label4.Text = "Fore Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)ForeColorPicker).Location = new Point(80, 48);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).TabIndex = 1;
			((Control)BorderColorPicker).Location = new Point(80, 72);
			((Control)BorderColorPicker).Name = "BorderColorPicker";
			BorderColorPicker.PropertyName = "BorderColor";
			((Control)BorderColorPicker).TabIndex = 2;
			label5.LoadingBegin();
			label5.FocusControl = (Control)(object)BorderColorPicker;
			((Control)label5).Location = new Point(10, 75);
			((Control)label5).Name = "label5";
			label5.Size = new Size(70, 15);
			label5.Text = "Border Color";
			label5.UpdateFrameRate = 50.0;
			label5.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)BorderColorPicker);
			((Control)this).Controls.Add((Control)(object)label5);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)groupBox1);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)CountNumericUpDown);
			((Control)this).Name = "OdometerDigitsEditorPlugIn";
			((Control)this).Size = new Size(464, 112);
			base.Title = "Digits Editor";
			((Control)groupBox1).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}
	}
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class OdometerEditorPlugIn : PlugInStandard
	{
		private FocusLabel label1;

		private FocusLabel label4;

		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private CheckBox AutoSizeCheckBox;

		private ColorPicker ForeColorPicker;

		private ColorPicker BackColorPicker;

		private FontButton FontButton;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public OdometerEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			ForeColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			FontButton = new FontButton();
			label4 = new FocusLabel();
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			AutoSizeCheckBox = new CheckBox();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			((Control)ForeColorPicker).Location = new Point(152, 72);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(136, 21);
			((Control)ForeColorPicker).TabIndex = 1;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(91, 99);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(152, 96);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 3;
			((Control)FontButton).Location = new Point(304, 72);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 2;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label4).Location = new Point(93, 75);
			((Control)label4).Name = "label4";
			label4.Size = new Size(59, 15);
			label4.Text = "Fore Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(103, 130);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((Control)RotationComboBox).Location = new Point(152, 128);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 4;
			((Control)AutoSizeCheckBox).Location = new Point(304, 128);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 5;
			AutoSizeCheckBox.Text = "Auto Size";
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(152, 8);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(116, 10);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(192, 162);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(152, 160);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 6;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(48, 162);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Name = "OdometerEditorPlugIn";
			((Control)this).Size = new Size(512, 208);
			base.Title = "Odometer Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueDoubleEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new OdometerDigitsEditorPlugIn(), "Digits", sameLevel: false);
			AddSubPlugIn(new OdometerTenthsEditorPlugIn(), "Tenths", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as Odometer).Value;
			base.SubPlugIns[1].Value = (base.Value as Odometer).Digits;
			base.SubPlugIns[2].Value = (base.Value as Odometer).Tenths;
			base.SubPlugIns[3].Value = (base.Value as Odometer).Border;
		}
	}
}
namespace Iocomp.Classes
{
	[DefaultProperty("")]
	public sealed class OdometerTenths : OdometerDigit
	{
		private int m_Count;

		[Description("")]
		public int Count
		{
			get
			{
				return m_Count;
			}
			set
			{
				PropertyUpdateDefault("Count", value);
				if (Count != value)
				{
					m_Count = value;
					DoPropertyChange(this, "Count");
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new OdometerTenthsEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Odometer Tenths";
		}

		public OdometerTenths()
		{
			DoCreate();
		}

		private bool ShouldSerializeCount()
		{
			return PropertyShouldSerialize("Count");
		}

		private void ResetCount()
		{
			PropertyReset("Count");
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public sealed class OdometerTenthsEditorPlugIn : PlugInStandard
	{
		private GroupBox groupBox1;

		private ComboBox BackStyleComboBox;

		private FocusLabel label6;

		private FocusLabel label3;

		private FocusLabel label2;

		private FocusLabel label1;

		private NumericUpDown CountNumericUpDown;

		private FocusLabel label4;

		private FocusLabel Label5;

		private ColorPicker BackColor1Picker;

		private ColorPicker BackColor2Picker;

		private ColorPicker ForeColorPicker;

		private Container components = null;

		public OdometerTenthsEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			groupBox1 = new GroupBox();
			Label5 = new FocusLabel();
			BackColor1Picker = new ColorPicker();
			BackStyleComboBox = new ComboBox();
			label6 = new FocusLabel();
			label3 = new FocusLabel();
			BackColor2Picker = new ColorPicker();
			label2 = new FocusLabel();
			label1 = new FocusLabel();
			CountNumericUpDown = new NumericUpDown();
			label4 = new FocusLabel();
			ForeColorPicker = new ColorPicker();
			((Control)groupBox1).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)groupBox1).Controls.Add((Control)(object)Label5);
			((Control)groupBox1).Controls.Add((Control)(object)BackStyleComboBox);
			((Control)groupBox1).Controls.Add((Control)(object)label6);
			((Control)groupBox1).Controls.Add((Control)(object)label3);
			((Control)groupBox1).Controls.Add((Control)(object)BackColor2Picker);
			((Control)groupBox1).Controls.Add((Control)(object)BackColor1Picker);
			((Control)groupBox1).Location = new Point(240, 0);
			((Control)groupBox1).Name = "groupBox1";
			((Control)groupBox1).Size = new Size(208, 104);
			((Control)groupBox1).TabIndex = 2;
			groupBox1.TabStop = false;
			((Control)groupBox1).Text = "Back";
			Label5.LoadingBegin();
			Label5.FocusControl = (Control)(object)BackColor1Picker;
			((Control)Label5).Location = new Point(13, 51);
			((Control)Label5).Name = "Label5";
			Label5.Size = new Size(43, 15);
			Label5.Text = "Color 1";
			Label5.UpdateFrameRate = 50.0;
			Label5.LoadingEnd();
			((Control)BackColor1Picker).Location = new Point(56, 48);
			((Control)BackColor1Picker).Name = "BackColor1Picker";
			BackColor1Picker.PropertyName = "BackColor1";
			((Control)BackColor1Picker).TabIndex = 1;
			((ComboBox)BackStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)BackStyleComboBox).Location = new Point(56, 16);
			((Control)BackStyleComboBox).Name = "BackStyleComboBox";
			BackStyleComboBox.PropertyName = "BackStyle";
			((Control)BackStyleComboBox).Size = new Size(140, 21);
			((Control)BackStyleComboBox).TabIndex = 0;
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)BackStyleComboBox;
			((Control)label6).Location = new Point(24, 18);
			((Control)label6).Name = "label6";
			label6.Size = new Size(32, 15);
			label6.Text = "Style";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)BackColor2Picker;
			((Control)label3).Location = new Point(13, 75);
			((Control)label3).Name = "label3";
			label3.Size = new Size(43, 15);
			label3.Text = "Color 2";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			((Control)BackColor2Picker).Location = new Point(56, 72);
			((Control)BackColor2Picker).Name = "BackColor2Picker";
			BackColor2Picker.PropertyName = "BackColor2";
			((Control)BackColor2Picker).TabIndex = 2;
			label2.LoadingBegin();
			((Control)label2).Location = new Point(17, 47);
			((Control)label2).Name = "label2";
			label2.Size = new Size(39, 18);
			label2.Text = "Color 1";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)CountNumericUpDown;
			((Control)label1).Location = new Point(35, 1);
			((Control)label1).Name = "label1";
			label1.Size = new Size(37, 15);
			label1.Text = "Count";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)CountNumericUpDown).Location = new Point(72, 0);
			((Control)CountNumericUpDown).Name = "CountNumericUpDown";
			CountNumericUpDown.PropertyName = "Count";
			((Control)CountNumericUpDown).Size = new Size(48, 20);
			((Control)CountNumericUpDown).TabIndex = 0;
			((UpDownBase)CountNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label4).Location = new Point(13, 35);
			((Control)label4).Name = "label4";
			label4.Size = new Size(59, 15);
			label4.Text = "Fore Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)ForeColorPicker).Location = new Point(72, 32);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).TabIndex = 1;
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)CountNumericUpDown);
			((Control)this).Controls.Add((Control)(object)groupBox1);
			((Control)this).Name = "OdometerTenthsEditorPlugIn";
			((Control)this).Size = new Size(464, 136);
			base.Title = "Tenths Editor";
			((Control)groupBox1).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}
	}
}
namespace Iocomp.Interfaces
{
	public interface IPointerGaugeAngular
	{
		void Draw(PaintArgs p, IScaleDisplayAngular display, IScaleRangeAngular range);
	}
}
namespace Iocomp.Types
{
	public enum PointerStyleGaugeAngular
	{
		ArrowLine,
		Arrow,
		Line,
		Triangle
	}
}
namespace Iocomp.Classes
{
	[Description("")]
	[TypeConverter(typeof(CollectionItemConverter))]
	public sealed class PointerGaugeAngular : SubClassBase, IPointerGaugeAngular
	{
		private ValueDouble m_Value;

		private PointerStyleGaugeAngular m_Style;

		private int m_Size;

		private int m_Margin;

		[Category("Iocomp")]
		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ValueDouble Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsDouble = value.AsDouble;
			}
		}

		[Description("")]
		public PointerStyleGaugeAngular Style
		{
			get
			{
				return m_Style;
			}
			set
			{
				PropertyUpdateDefault("Style", value);
				if (Style != value)
				{
					m_Style = value;
					DoPropertyChange(this, "Style");
				}
			}
		}

		[Description("")]
		public bool Visible
		{
			get
			{
				return base.VisibleInternal;
			}
			set
			{
				base.VisibleInternal = value;
			}
		}

		[Description("")]
		public new Color Color
		{
			get
			{
				return base.Color;
			}
			set
			{
				base.Color = value;
			}
		}

		[Description("")]
		public int Size
		{
			get
			{
				return m_Size;
			}
			set
			{
				PropertyUpdateDefault("Size", value);
				if (Size != value)
				{
					m_Size = value;
					DoPropertyChange(this, "Size");
				}
			}
		}

		[Description("")]
		public int Margin
		{
			get
			{
				return m_Margin;
			}
			set
			{
				PropertyUpdateDefault("Margin", value);
				if (Margin != value)
				{
					m_Margin = value;
					DoPropertyChange(this, "Margin");
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new PointerGaugeAngularEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Pointer";
		}

		void IPointerGaugeAngular.Draw(PaintArgs p, IScaleDisplayAngular display, IScaleRangeAngular range)
		{
			Draw(p, display, range);
		}

		public PointerGaugeAngular()
		{
			DoCreate();
		}

		protected override void CreateObjects()
		{
			base.CreateObjects();
			m_Value = new ValueDouble();
			AddSubClass(Value);
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			Style = PointerStyleGaugeAngular.Triangle;
			Visible = true;
			Color = Color.Black;
			Size = 5;
			Margin = 2;
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeStyle()
		{
			return PropertyShouldSerialize("Style");
		}

		private void ResetStyle()
		{
			PropertyReset("Style");
		}

		private bool ShouldSerializeVisible()
		{
			return PropertyShouldSerialize("Visible");
		}

		private void ResetVisible()
		{
			PropertyReset("Visible");
		}

		private bool ShouldSerializeColor()
		{
			return PropertyShouldSerialize("Color");
		}

		private void ResetColor()
		{
			PropertyReset("Color");
		}

		private bool ShouldSerializeSize()
		{
			return PropertyShouldSerialize("Size");
		}

		private void ResetSize()
		{
			PropertyReset("Size");
		}

		private bool ShouldSerializeMargin()
		{
			return PropertyShouldSerialize("Margin");
		}

		private void ResetMargin()
		{
			PropertyReset("Margin");
		}

		private void Draw(PaintArgs p, IScaleDisplayAngular display, IScaleRangeAngular range)
		{
			if (Visible)
			{
				double value = (display as ScaleDisplay).ValueClamped(Value.AsDouble);
				if (Style == PointerStyleGaugeAngular.Line)
				{
					p.Graphics.DrawLine(p.Graphics.Pen(Color), display.CenterPoint, display.GetScalePoint(value, display.Radius - Margin));
				}
				else if (Style == PointerStyleGaugeAngular.Triangle)
				{
					Point[] points = new Point[3]
					{
						display.GetScalePoint(value, display.Radius - Margin),
						Math2.ToRotatedPoint(range.ValueToAngle(value) + 90.0, Size, display.CenterPoint),
						Math2.ToRotatedPoint(range.ValueToAngle(value) - 90.0, Size, display.CenterPoint)
					};
					p.Graphics.FillPolygon(p.Graphics.Brush(Color), points);
				}
				else if (Style == PointerStyleGaugeAngular.Arrow)
				{
					Point[] points = new Point[3]
					{
						display.GetScalePoint(value, display.Radius - Margin),
						default(Point),
						default(Point)
					};
					Point scalePoint = display.GetScalePoint(value, display.Radius - 2 * Size - Margin);
					ref Point reference = ref points[1];
					reference = Math2.ToRotatedPoint(range.ValueToAngle(value) + 90.0, Size, scalePoint);
					ref Point reference2 = ref points[2];
					reference2 = Math2.ToRotatedPoint(range.ValueToAngle(value) - 90.0, Size, scalePoint);
					p.Graphics.FillPolygon(p.Graphics.Brush(Color), points);
				}
				else if (Style == PointerStyleGaugeAngular.ArrowLine)
				{
					Point[] points = new Point[3];
					p.Graphics.DrawLine(p.Graphics.Pen(Color), display.CenterPoint, display.GetScalePoint(value, display.Radius - Margin));
					ref Point reference3 = ref points[0];
					reference3 = display.GetScalePoint(value, display.Radius - Margin);
					Point scalePoint = display.GetScalePoint(value, display.Radius - 2 * Size - Margin);
					ref Point reference4 = ref points[1];
					reference4 = Math2.ToRotatedPoint(range.ValueToAngle(value) + 90.0, Size, scalePoint);
					ref Point reference5 = ref points[2];
					reference5 = Math2.ToRotatedPoint(range.ValueToAngle(value) - 90.0, Size, scalePoint);
					p.Graphics.FillPolygon(p.Graphics.Brush(Color), points);
				}
			}
		}

		public override string ToString()
		{
			return "Pointer";
		}
	}
	public class PointerGaugeAngularCollection : CollectionBase
	{
		public PointerGaugeAngular this[int index]
		{
			get
			{
				return base.List[index] as PointerGaugeAngular;
			}
			set
			{
				base.List[index] = value;
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new PointerGaugeAngularCollectionEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Pointer Collection";
		}

		public PointerGaugeAngularCollection()
			: base(null)
		{
		}

		public PointerGaugeAngularCollection(IComponentBase componentBase)
			: base(componentBase)
		{
		}

		public void CopyTo(PointerGaugeAngular[] array, int index)
		{
			((ICollection)this).CopyTo((Array)array, index);
		}

		public int Add(PointerGaugeAngular value)
		{
			return base.List.Add(value);
		}

		public void Insert(int index, PointerGaugeAngular value)
		{
			base.List.Insert(index, value);
		}

		public void Remove(PointerGaugeAngular value)
		{
			base.List.Remove(value);
		}

		public int IndexOf(PointerGaugeAngular value)
		{
			return base.List.IndexOf(value);
		}

		public bool Contains(PointerGaugeAngular value)
		{
			return base.List.Contains(value);
		}

		public override void Reset()
		{
			Clear();
			Add(new PointerGaugeAngular());
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("code")]
	[ToolboxItem(false)]
	public class PointerGaugeAngularCollectionEditorPlugIn : PlugInCollection
	{
		protected override Type[] Types => new Type[1] { typeof(PointerGaugeAngular) };

		public PointerGaugeAngularCollectionEditorPlugIn()
		{
			base.Title = "Pointer Collection Editor";
		}

		protected override PlugInStandard[] CreatePlugInPool()
		{
			return new PlugInStandard[1]
			{
				new PointerGaugeAngularEditorPlugIn()
			};
		}

		protected override PlugInStandard GetClassPlugIn(object value)
		{
			if (value is PointerGaugeAngular)
			{
				return base.PlugInPool[0];
			}
			return null;
		}

		protected override int GetPlugInIndex(object value)
		{
			if (value is PointerGaugeAngular)
			{
				return 0;
			}
			return 0;
		}
	}
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class PointerGaugeAngularEditorPlugIn : PlugInStandard
	{
		private FocusLabel label2;

		private FocusLabel label4;

		private CheckBox VisibleCheckBox;

		private FocusLabel label1;

		private NumericUpDown MarginNumericUpDown;

		private NumericUpDown SizeNumericUpDown;

		private ColorPicker ColorPicker;

		private FocusLabel label6;

		private ComboBox StyleComboBox;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private Container components = null;

		public PointerGaugeAngularEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label2 = new FocusLabel();
			SizeNumericUpDown = new NumericUpDown();
			ColorPicker = new ColorPicker();
			label4 = new FocusLabel();
			VisibleCheckBox = new CheckBox();
			label1 = new FocusLabel();
			MarginNumericUpDown = new NumericUpDown();
			label6 = new FocusLabel();
			StyleComboBox = new ComboBox();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			((Control)this).SuspendLayout();
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)SizeNumericUpDown;
			((Control)label2).Location = new Point(43, 137);
			((Control)label2).Name = "label2";
			label2.Size = new Size(29, 15);
			label2.Text = "Size";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)SizeNumericUpDown).Location = new Point(72, 136);
			((NumericUpDown)SizeNumericUpDown).Maximum = new decimal(new int[4] { 1000, 0, 0, 0 });
			((Control)SizeNumericUpDown).Name = "SizeNumericUpDown";
			SizeNumericUpDown.PropertyName = "Size";
			((Control)SizeNumericUpDown).Size = new Size(56, 20);
			((Control)SizeNumericUpDown).TabIndex = 4;
			((UpDownBase)SizeNumericUpDown).TextAlign = (HorizontalAlignment)2;
			((Control)ColorPicker).Location = new Point(72, 104);
			((Control)ColorPicker).Name = "ColorPicker";
			ColorPicker.PropertyName = "Color";
			((Control)ColorPicker).Size = new Size(144, 21);
			((Control)ColorPicker).TabIndex = 3;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ColorPicker;
			((Control)label4).Location = new Point(38, 107);
			((Control)label4).Name = "label4";
			label4.Size = new Size(34, 15);
			label4.Text = "Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)VisibleCheckBox).Location = new Point(72, 8);
			((Control)VisibleCheckBox).Name = "VisibleCheckBox";
			VisibleCheckBox.PropertyName = "Visible";
			((Control)VisibleCheckBox).TabIndex = 0;
			VisibleCheckBox.Text = "Visible";
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)MarginNumericUpDown;
			((Control)label1).Location = new Point(31, 161);
			((Control)label1).Name = "label1";
			label1.Size = new Size(41, 15);
			label1.Text = "Margin";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)MarginNumericUpDown).Location = new Point(72, 160);
			((NumericUpDown)MarginNumericUpDown).Maximum = new decimal(new int[4] { 1000, 0, 0, 0 });
			((Control)MarginNumericUpDown).Name = "MarginNumericUpDown";
			MarginNumericUpDown.PropertyName = "Margin";
			((Control)MarginNumericUpDown).Size = new Size(56, 20);
			((Control)MarginNumericUpDown).TabIndex = 5;
			((UpDownBase)MarginNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)StyleComboBox;
			((Control)label6).Location = new Point(40, 74);
			((Control)label6).Name = "label6";
			label6.Size = new Size(32, 15);
			label6.Text = "Style";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)StyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)StyleComboBox).Location = new Point(72, 72);
			((Control)StyleComboBox).Name = "StyleComboBox";
			StyleComboBox.PropertyName = "Style";
			((Control)StyleComboBox).Size = new Size(121, 21);
			((Control)StyleComboBox).TabIndex = 2;
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(72, 40);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 1;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(36, 42);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)StyleComboBox);
			((Control)this).Controls.Add((Control)(object)SizeNumericUpDown);
			((Control)this).Controls.Add((Control)(object)MarginNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)VisibleCheckBox);
			((Control)this).Controls.Add((Control)(object)ColorPicker);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Name = "PointerGaugeAngularEditorPlugIn";
			((Control)this).Size = new Size(384, 224);
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueDoubleEditorPlugIn(), "Value", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as PointerGaugeAngular).Value;
		}
	}
}
namespace Iocomp.Interfaces
{
	public interface IPointerGaugeLinear
	{
		void Draw(PaintArgs p, ScaleDisplayLinear display);
	}
}
namespace Iocomp.Types
{
	public enum PointerStyleGauge
	{
		Pointer,
		Triangle,
		TLine,
		ColorBar,
		Tube
	}
}
namespace Iocomp.Classes
{
	[TypeConverter(typeof(CollectionItemConverter))]
	[Description("")]
	[DefaultProperty("ColorBase")]
	public sealed class PointerGaugeLinear : SubClassBase, IPointerGaugeLinear
	{
		private ValueDouble m_Value;

		private PointerStyleGauge m_Style;

		private int m_Margin;

		private int m_Size;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		[Category("Iocomp")]
		public ValueDouble Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsDouble = value.AsDouble;
			}
		}

		[Description("")]
		[Category("Iocomp")]
		public bool Visible
		{
			get
			{
				return base.VisibleInternal;
			}
			set
			{
				base.VisibleInternal = value;
			}
		}

		[Description("")]
		[Category("Iocomp")]
		public PointerStyleGauge Style
		{
			get
			{
				return m_Style;
			}
			set
			{
				PropertyUpdateDefault("Style", value);
				if (Style != value)
				{
					m_Style = value;
					DoPropertyChange(this, "Style");
				}
			}
		}

		[Description("")]
		[Category("Iocomp")]
		public int Size
		{
			get
			{
				return m_Size;
			}
			set
			{
				PropertyUpdateDefault("Size", value);
				if (Size != value)
				{
					m_Size = value;
					DoPropertyChange(this, "Size");
				}
			}
		}

		[Description("")]
		[Category("Iocomp")]
		public int Margin
		{
			get
			{
				return m_Margin;
			}
			set
			{
				PropertyUpdateDefault("Margin", value);
				if (Margin != value)
				{
					m_Margin = value;
					DoPropertyChange(this, "Margin");
				}
			}
		}

		[Description("")]
		[Category("Iocomp")]
		public new Color Color
		{
			get
			{
				return base.Color;
			}
			set
			{
				base.Color = value;
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new PointerGaugeLinearEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Pointer";
		}

		void IPointerGaugeLinear.Draw(PaintArgs p, ScaleDisplayLinear display)
		{
			Draw(p, display);
		}

		public PointerGaugeLinear()
		{
			DoCreate();
		}

		protected override void CreateObjects()
		{
			base.CreateObjects();
			m_Value = new ValueDouble();
			AddSubClass(Value);
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			Visible = true;
			Style = PointerStyleGauge.Pointer;
			Color = Color.Blue;
			Size = 10;
			Margin = 0;
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeVisible()
		{
			return PropertyShouldSerialize("Visible");
		}

		private void ResetVisible()
		{
			PropertyReset("Visible");
		}

		private bool ShouldSerializeStyle()
		{
			return PropertyShouldSerialize("Style");
		}

		private void ResetStyle()
		{
			PropertyReset("Style");
		}

		private bool ShouldSerializeSize()
		{
			return PropertyShouldSerialize("Size");
		}

		private void ResetSize()
		{
			PropertyReset("Size");
		}

		private bool ShouldSerializeMargin()
		{
			return PropertyShouldSerialize("Margin");
		}

		private void ResetMargin()
		{
			PropertyReset("Margin");
		}

		private bool ShouldSerializeColor()
		{
			return PropertyShouldSerialize("Color");
		}

		private void ResetColor()
		{
			PropertyReset("Color");
		}

		[Browsable(false)]
		[Description("")]
		public int GetScaleOverlap(ScaleDisplay display)
		{
			if (Style == PointerStyleGauge.Pointer)
			{
				if (2 * Size + Margin > display.TickMajor.Length)
				{
					return 2 * Size + Margin - display.TickMajor.Length;
				}
				return 0;
			}
			if (Style == PointerStyleGauge.Triangle)
			{
				if (Size + Margin > display.TickMajor.Length)
				{
					return Size + Margin - display.TickMajor.Length;
				}
				return 0;
			}
			if (Style == PointerStyleGauge.TLine)
			{
				return 1;
			}
			if (Style == PointerStyleGauge.ColorBar)
			{
				return 0;
			}
			if (Style == PointerStyleGauge.Tube)
			{
				return 0;
			}
			return 0;
		}

		private void Draw(PaintArgs p, ScaleDisplayLinear display)
		{
			if (!Visible)
			{
				return;
			}
			int edgeRef = ((IScaleDisplay)display).EdgeRef;
			int value = display.ValueToPixels(Value.AsDouble);
			int length = display.TickMajor.Length;
			if (Style == PointerStyleGauge.Pointer)
			{
				if (display.Direction == SideDirection.LeftToRight)
				{
					int num = length - 2 * Size - Margin;
					Rectangle r = new Rectangle(edgeRef + num, value - Size / 2, 2 * Size, Size);
					Point[] pointerPoints = Shapes.GetPointerPoints(r, Direction.Right);
					p.Graphics.FillPolygon(p.Graphics.Brush(Color), pointerPoints);
				}
				else
				{
					int num = length - Margin - 1;
					Rectangle r = new Rectangle(edgeRef - num, value - Size / 2, 2 * Size, Size);
					Point[] pointerPoints = Shapes.GetPointerPoints(r, Direction.Left);
					p.Graphics.FillPolygon(p.Graphics.Brush(Color), pointerPoints);
				}
			}
			else if (Style == PointerStyleGauge.Triangle)
			{
				Point[] pointerPoints;
				if (display.Direction == SideDirection.LeftToRight)
				{
					int num = length - Size - Margin;
					Rectangle r = new Rectangle(edgeRef + num, value - Size / 2, Size, Size);
					pointerPoints = Shapes.GetTrianglePoints(r, Direction.Right);
					p.Graphics.FillPolygon(p.Graphics.Brush(Color), pointerPoints);
				}
				else
				{
					int num = length - Margin - 1;
					Rectangle r = new Rectangle(edgeRef - num, value - Size / 2, Size, Size);
					pointerPoints = Shapes.GetTrianglePoints(r, Direction.Left);
					p.Graphics.FillPolygon(p.Graphics.Brush(Color), pointerPoints);
				}
				p.Graphics.FillPolygon(p.Graphics.Brush(Color), pointerPoints);
			}
			else if (Style == PointerStyleGauge.TLine)
			{
				if (display.Direction == SideDirection.LeftToRight)
				{
					p.Graphics.DrawLine(p.Graphics.Pen(Color, 2f), edgeRef - Margin, display.PixelsMin, edgeRef - Margin, display.PixelsMax);
					p.Graphics.DrawLine(p.Graphics.Pen(Color, 2f), edgeRef - Margin, value, edgeRef - Margin + length, value);
				}
				else
				{
					p.Graphics.DrawLine(p.Graphics.Pen(Color, 2f), edgeRef + Margin + 1, display.PixelsMin, edgeRef + Margin + 1, display.PixelsMax);
					p.Graphics.DrawLine(p.Graphics.Pen(Color, 2f), edgeRef + Margin + 1, value, edgeRef + Margin - length + 1, value);
				}
			}
			else if (Style == PointerStyleGauge.ColorBar)
			{
				((IScaleDisplayLinear)display).DrawColorBar(p, display.ScaleRange.Min, Value.AsDouble, Color);
			}
			else if (Style == PointerStyleGauge.Tube)
			{
				int value2 = display.ValueToPixels(display.ScaleRange.Min);
				if (value2 < value)
				{
					Math2.Switch(ref value2, ref value);
				}
				Rectangle r = ((display.Direction != SideDirection.LeftToRight) ? new Rectangle(edgeRef - length, value, length, value2 - value) : new Rectangle(edgeRef, value, length, value2 - value));
				p.Graphics.FillTube3D(r, Color, (Orientation)1, 0.5f, sigma: true);
			}
		}

		public override string ToString()
		{
			return "Pointer";
		}
	}
	public class PointerGaugeLinearCollection : CollectionBase
	{
		public PointerGaugeLinear this[int index]
		{
			get
			{
				return base.List[index] as PointerGaugeLinear;
			}
			set
			{
				base.List[index] = value;
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new PointerGaugeLinearCollectionEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Pointer Collection";
		}

		public PointerGaugeLinearCollection()
			: base(null)
		{
		}

		public PointerGaugeLinearCollection(IComponentBase componentBase)
			: base(componentBase)
		{
		}

		public void CopyTo(PointerGaugeLinear[] array, int index)
		{
			((ICollection)this).CopyTo((Array)array, index);
		}

		public int Add(PointerGaugeLinear value)
		{
			return base.List.Add(value);
		}

		public void Insert(int index, PointerGaugeLinear value)
		{
			base.List.Insert(index, value);
		}

		public void Remove(PointerGaugeLinear value)
		{
			base.List.Remove(value);
		}

		public int IndexOf(PointerGaugeLinear value)
		{
			return base.List.IndexOf(value);
		}

		public bool Contains(PointerGaugeLinear value)
		{
			return base.List.Contains(value);
		}

		public override void Reset()
		{
			Clear();
			Add(new PointerGaugeLinear());
		}

		public int GetMaxScaleOverlap(ScaleDisplay display)
		{
			int num = 0;
			IEnumerator enumerator = GetEnumerator();
			try
			{
				while (enumerator.MoveNext())
				{
					PointerGaugeLinear pointerGaugeLinear = (PointerGaugeLinear)enumerator.Current;
					if (pointerGaugeLinear.Visible && pointerGaugeLinear.GetScaleOverlap(display) > num)
					{
						num = pointerGaugeLinear.GetScaleOverlap(display);
					}
				}
				return num;
			}
			finally
			{
				IDisposable disposable = enumerator as IDisposable;
				if (disposable != null)
				{
					disposable.Dispose();
				}
			}
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("code")]
	public class PointerGaugeLinearCollectionEditorPlugIn : PlugInCollection
	{
		protected override Type[] Types => new Type[1] { typeof(PointerGaugeLinear) };

		public PointerGaugeLinearCollectionEditorPlugIn()
		{
			base.Title = "Pointer Collection Editor";
		}

		protected override PlugInStandard[] CreatePlugInPool()
		{
			return new PlugInStandard[1]
			{
				new PointerGaugeLinearEditorPlugIn()
			};
		}

		protected override PlugInStandard GetClassPlugIn(object value)
		{
			if (value is PointerGaugeLinear)
			{
				return base.PlugInPool[0];
			}
			return null;
		}

		protected override int GetPlugInIndex(object value)
		{
			if (value is PointerGaugeLinear)
			{
				return 0;
			}
			return 0;
		}
	}
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class PointerGaugeLinearEditorPlugIn : PlugInStandard
	{
		private FocusLabel label4;

		private CheckBox VisibleCheckBox;

		private NumericUpDown MarginNumericUpDown;

		private FocusLabel label7;

		private FocusLabel label6;

		private ComboBox StyleComboBox;

		private NumericUpDown SizeNumericUpDown;

		private FocusLabel label3;

		private ColorPicker ColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private Container components = null;

		public PointerGaugeLinearEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			ColorPicker = new ColorPicker();
			label4 = new FocusLabel();
			VisibleCheckBox = new CheckBox();
			MarginNumericUpDown = new NumericUpDown();
			label7 = new FocusLabel();
			label6 = new FocusLabel();
			StyleComboBox = new ComboBox();
			SizeNumericUpDown = new NumericUpDown();
			label3 = new FocusLabel();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			((Control)this).SuspendLayout();
			((Control)ColorPicker).Location = new Point(72, 104);
			((Control)ColorPicker).Name = "ColorPicker";
			ColorPicker.PropertyName = "Color";
			((Control)ColorPicker).Size = new Size(144, 21);
			((Control)ColorPicker).TabIndex = 3;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ColorPicker;
			((Control)label4).Location = new Point(38, 107);
			((Control)label4).Name = "label4";
			label4.Size = new Size(34, 15);
			label4.Text = "Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)VisibleCheckBox).Location = new Point(72, 8);
			((Control)VisibleCheckBox).Name = "VisibleCheckBox";
			VisibleCheckBox.PropertyName = "Visible";
			((Control)VisibleCheckBox).TabIndex = 0;
			VisibleCheckBox.Text = "Visible";
			((Control)MarginNumericUpDown).Location = new Point(72, 160);
			((NumericUpDown)MarginNumericUpDown).Maximum = new decimal(new int[4] { 1000, 0, 0, 0 });
			((Control)MarginNumericUpDown).Name = "MarginNumericUpDown";
			MarginNumericUpDown.PropertyName = "Margin";
			((Control)MarginNumericUpDown).Size = new Size(56, 20);
			((Control)MarginNumericUpDown).TabIndex = 5;
			((UpDownBase)MarginNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label7.LoadingBegin();
			label7.FocusControl = (Control)(object)MarginNumericUpDown;
			((Control)label7).Location = new Point(31, 161);
			((Control)label7).Name = "label7";
			label7.Size = new Size(41, 15);
			label7.Text = "Margin";
			label7.UpdateFrameRate = 50.0;
			label7.LoadingEnd();
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)StyleComboBox;
			((Control)label6).Location = new Point(40, 74);
			((Control)label6).Name = "label6";
			label6.Size = new Size(32, 15);
			label6.Text = "Style";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)StyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)StyleComboBox).Location = new Point(72, 72);
			((Control)StyleComboBox).Name = "StyleComboBox";
			StyleComboBox.PropertyName = "Style";
			((Control)StyleComboBox).Size = new Size(121, 21);
			((Control)StyleComboBox).TabIndex = 2;
			((Control)SizeNumericUpDown).Location = new Point(72, 136);
			((NumericUpDown)SizeNumericUpDown).Maximum = new decimal(new int[4] { 1000, 0, 0, 0 });
			((Control)SizeNumericUpDown).Name = "SizeNumericUpDown";
			SizeNumericUpDown.PropertyName = "Size";
			((Control)SizeNumericUpDown).Size = new Size(56, 20);
			((Control)SizeNumericUpDown).TabIndex = 4;
			((UpDownBase)SizeNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)SizeNumericUpDown;
			((Control)label3).Location = new Point(43, 137);
			((Control)label3).Name = "label3";
			label3.Size = new Size(29, 15);
			label3.Text = "Size";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(72, 40);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 1;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(36, 42);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)SizeNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label3);
			((Control)this).Controls.Add((Control)(object)MarginNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)StyleComboBox);
			((Control)this).Controls.Add((Control)(object)VisibleCheckBox);
			((Control)this).Controls.Add((Control)(object)ColorPicker);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)label7);
			((Control)this).Name = "PointerGaugeLinearEditorPlugIn";
			((Control)this).Size = new Size(312, 192);
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueDoubleEditorPlugIn(), "Value", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as PointerGaugeLinear).Value;
		}
	}
}
namespace Iocomp.Interfaces
{
	public interface IPointerKnob
	{
		void Draw(PaintArgs p, Point centerPoint, double angle, int radiusEdge);
	}
}
namespace Iocomp.Types
{
	public enum PointerStyleKnob
	{
		DotSunken,
		DotRaised,
		Dot,
		LineCenter,
		LineCustom,
		Triangle
	}
}
namespace Iocomp.Classes
{
	[Description("")]
	public sealed class PointerKnob : SubClassBase, IPointerKnob
	{
		private PointerStyleKnob m_Style;

		private int m_Size;

		private int m_Margin;

		[Description("")]
		public PointerStyleKnob Style
		{
			get
			{
				return m_Style;
			}
			set
			{
				PropertyUpdateDefault("Style", value);
				if (Style != value)
				{
					m_Style = value;
					DoPropertyChange(this, "Style");
				}
			}
		}

		[Description("")]
		public new Color Color
		{
			get
			{
				return base.Color;
			}
			set
			{
				base.Color = value;
			}
		}

		[Description("")]
		public int Size
		{
			get
			{
				return m_Size;
			}
			set
			{
				PropertyUpdateDefault("Size", value);
				if (Size != value)
				{
					m_Size = value;
					DoPropertyChange(this, "Size");
				}
			}
		}

		[Description("")]
		public int Margin
		{
			get
			{
				return m_Margin;
			}
			set
			{
				PropertyUpdateDefault("Margin", value);
				if (Margin != value)
				{
					m_Margin = value;
					DoPropertyChange(this, "Margin");
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new PointerKnobEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Pointer";
		}

		void IPointerKnob.Draw(PaintArgs p, Point centerPoint, double angle, int radiusEdge)
		{
			Draw(p, centerPoint, angle, radiusEdge);
		}

		public PointerKnob()
		{
			DoCreate();
		}

		private bool ShouldSerializeStyle()
		{
			return PropertyShouldSerialize("Style");
		}

		private void ResetStyle()
		{
			PropertyReset("Style");
		}

		private bool ShouldSerializeColor()
		{
			return PropertyShouldSerialize("Color");
		}

		private void ResetColor()
		{
			PropertyReset("Color");
		}

		private bool ShouldSerializeSize()
		{
			return PropertyShouldSerialize("Size");
		}

		private void ResetSize()
		{
			PropertyReset("Size");
		}

		private bool ShouldSerializeMargin()
		{
			return PropertyShouldSerialize("Margin");
		}

		private void ResetMargin()
		{
			PropertyReset("Margin");
		}

		private void Draw(PaintArgs p, Point centerPoint, double angle, int radiusEdge)
		{
			if (Style == PointerStyleKnob.Dot)
			{
				Point point = Math2.ToRotatedPoint(angle, radiusEdge - Margin - Size, centerPoint);
				Rectangle rect = new Rectangle(point.X - Size, point.Y - Size, 2 * Size, 2 * Size);
				p.Graphics.FillEllipse(p.Graphics.Brush(Color), rect);
			}
			else if (Style == PointerStyleKnob.DotRaised)
			{
				Point point = Math2.ToRotatedPoint(angle, radiusEdge - Margin - Size, centerPoint);
				Rectangle rect = new Rectangle(point.X - Size, point.Y - Size, 2 * Size, 2 * Size);
				BorderSpecial.DrawEllipse(p, rect, BevelStyle.Raised, 2f, Color);
				rect.Inflate(-2, -2);
				p.Graphics.FillEllipse(p.Graphics.Brush(Color), rect);
			}
			else if (Style == PointerStyleKnob.DotSunken)
			{
				Point point = Math2.ToRotatedPoint(angle, radiusEdge - Margin - Size, centerPoint);
				Rectangle rect = new Rectangle(point.X - Size, point.Y - Size, 2 * Size, 2 * Size);
				BorderSpecial.DrawEllipse(p, rect, BevelStyle.Sunken, 2f, Color);
				rect.Inflate(-2, -2);
				p.Graphics.FillEllipse(p.Graphics.Brush(Color), rect);
			}
			else if (Style == PointerStyleKnob.LineCenter)
			{
				Point point = Math2.ToRotatedPoint(angle, radiusEdge - Margin, centerPoint);
				p.Graphics.DrawLine(p.Graphics.Pen(Color), point, centerPoint);
			}
			else if (Style == PointerStyleKnob.LineCustom)
			{
				Point pt = Math2.ToRotatedPoint(angle, radiusEdge - Margin, centerPoint);
				Point pt2 = Math2.ToRotatedPoint(angle, radiusEdge - Margin - Size, centerPoint);
				p.Graphics.DrawLine(p.Graphics.Pen(Color), pt, pt2);
			}
			else if (Style == PointerStyleKnob.Triangle)
			{
				Point[] array = new Point[3]
				{
					Math2.ToRotatedPoint(angle, radiusEdge - Margin, centerPoint),
					default(Point),
					default(Point)
				};
				Point point = Math2.ToRotatedPoint(angle, radiusEdge - Margin - 2 * Size, centerPoint);
				ref Point reference = ref array[1];
				reference = Math2.ToRotatedPoint(angle + 90.0, Size, point);
				ref Point reference2 = ref array[2];
				reference2 = Math2.ToRotatedPoint(angle - 90.0, Size, point);
				p.Graphics.FillPolygon(p.Graphics.Brush(Color), array);
			}
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class PointerKnobEditorPlugIn : PlugInStandard
	{
		private FocusLabel label9;

		private FocusLabel label3;

		private NumericUpDown SizeNumericUpDown;

		private FocusLabel label4;

		private NumericUpDown MarginNumericUpDown;

		private ComboBox StyleComboBox;

		private FocusLabel label1;

		private ColorPicker ColorPicker;

		private Container components = null;

		public PointerKnobEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label9 = new FocusLabel();
			ColorPicker = new ColorPicker();
			label3 = new FocusLabel();
			SizeNumericUpDown = new NumericUpDown();
			label4 = new FocusLabel();
			MarginNumericUpDown = new NumericUpDown();
			StyleComboBox = new ComboBox();
			label1 = new FocusLabel();
			((Control)this).SuspendLayout();
			label9.LoadingBegin();
			label9.FocusControl = (Control)(object)ColorPicker;
			((Control)label9).Location = new Point(70, 115);
			((Control)label9).Name = "label9";
			label9.Size = new Size(34, 15);
			label9.Text = "Color";
			label9.UpdateFrameRate = 50.0;
			label9.LoadingEnd();
			((Control)ColorPicker).Location = new Point(104, 112);
			((Control)ColorPicker).Name = "ColorPicker";
			ColorPicker.PropertyName = "Color";
			((Control)ColorPicker).Size = new Size(144, 21);
			((Control)ColorPicker).TabIndex = 3;
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)SizeNumericUpDown;
			((Control)label3).Location = new Point(75, 49);
			((Control)label3).Name = "label3";
			label3.Size = new Size(29, 15);
			label3.Text = "Size";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			((Control)SizeNumericUpDown).Location = new Point(104, 48);
			((NumericUpDown)SizeNumericUpDown).Maximum = new decimal(new int[4] { 1000, 0, 0, 0 });
			((Control)SizeNumericUpDown).Name = "SizeNumericUpDown";
			SizeNumericUpDown.PropertyName = "Size";
			((Control)SizeNumericUpDown).Size = new Size(48, 20);
			((Control)SizeNumericUpDown).TabIndex = 1;
			((UpDownBase)SizeNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)MarginNumericUpDown;
			((Control)label4).Location = new Point(63, 73);
			((Control)label4).Name = "label4";
			label4.Size = new Size(41, 15);
			label4.Text = "Margin";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)MarginNumericUpDown).Location = new Point(104, 72);
			((NumericUpDown)MarginNumericUpDown).Maximum = new decimal(new int[4] { 1000, 0, 0, 0 });
			((Control)MarginNumericUpDown).Name = "MarginNumericUpDown";
			MarginNumericUpDown.PropertyName = "Margin";
			((Control)MarginNumericUpDown).Size = new Size(48, 20);
			((Control)MarginNumericUpDown).TabIndex = 2;
			((UpDownBase)MarginNumericUpDown).TextAlign = (HorizontalAlignment)2;
			((ComboBox)StyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)StyleComboBox).Location = new Point(104, 8);
			((Control)StyleComboBox).Name = "StyleComboBox";
			StyleComboBox.PropertyName = "Style";
			((Control)StyleComboBox).Size = new Size(144, 21);
			((Control)StyleComboBox).TabIndex = 0;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)StyleComboBox;
			((Control)label1).Location = new Point(72, 10);
			((Control)label1).Name = "label1";
			label1.Size = new Size(32, 15);
			label1.Text = "Style";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)label9);
			((Control)this).Controls.Add((Control)(object)ColorPicker);
			((Control)this).Controls.Add((Control)(object)label3);
			((Control)this).Controls.Add((Control)(object)SizeNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)MarginNumericUpDown);
			((Control)this).Controls.Add((Control)(object)StyleComboBox);
			((Control)this).Location = new Point(10, 20);
			((Control)this).Name = "PointerKnobEditorPlugIn";
			((Control)this).Size = new Size(480, 136);
			base.Title = "Pointer Editor";
			((Control)this).ResumeLayout(false);
		}
	}
}
namespace Iocomp.Interfaces
{
	public interface IPointerSlider
	{
		SizeF RequiredSize { get; }

		void Draw(PaintArgs p, Rectangle r, int posPixels, bool mouseDown, SideDirection direction);
	}
}
namespace Iocomp.Types
{
	public enum PointerStyleSlider
	{
		Bar,
		BarIndicator,
		BarIndicatorLight,
		Pointer
	}
}
namespace Iocomp.Classes
{
	[DefaultProperty("Style")]
	[Description("Contains the properties that control the slider's pointer properties.")]
	public sealed class PointerSlider : SubClassBase, IPointerSlider
	{
		private PointerStyleSlider m_Style;

		private int m_Height;

		private int m_Width;

		private PointerTrackStyle m_TrackStyle;

		private Color m_TrackColor;

		private Indicator m_Indicator;

		private Bevel m_Bevel;

		SizeF IPointerSlider.RequiredSize => RequiredSize;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		public Indicator Indicator => m_Indicator;

		[Description("")]
		[Category("Iocomp")]
		public PointerStyleSlider Style
		{
			get
			{
				return m_Style;
			}
			set
			{
				PropertyUpdateDefault("Style", value);
				if (Style != value)
				{
					m_Style = value;
					DoPropertyChange(this, "Style");
				}
			}
		}

		[Description("")]
		public new Color Color
		{
			get
			{
				return base.Color;
			}
			set
			{
				base.Color = value;
			}
		}

		[Description("")]
		public int Height
		{
			get
			{
				return m_Height;
			}
			set
			{
				PropertyUpdateDefault("Height", value);
				if (Height != value)
				{
					m_Height = value;
					DoPropertyChange(this, "Height");
				}
			}
		}

		[Description("")]
		public int Width
		{
			get
			{
				return m_Width;
			}
			set
			{
				PropertyUpdateDefault("Width", value);
				if (Width != value)
				{
					m_Width = value;
					DoPropertyChange(this, "Width");
				}
			}
		}

		[Description("")]
		[Category("Iocomp")]
		public PointerTrackStyle TrackStyle
		{
			get
			{
				return m_TrackStyle;
			}
			set
			{
				PropertyUpdateDefault("TrackStyle", value);
				if (TrackStyle != value)
				{
					m_TrackStyle = value;
					DoPropertyChange(this, "TrackStyle");
				}
			}
		}

		[Description("")]
		public Color TrackColor
		{
			get
			{
				return m_TrackColor;
			}
			set
			{
				PropertyUpdateDefault("TrackColor", value);
				if (TrackColor != value)
				{
					m_TrackColor = value;
					DoPropertyChange(this, "TrackColor");
				}
			}
		}

		private SizeF RequiredSize => new SizeF(Width, Height);

		protected override PlugInStandard GetPlugIn()
		{
			return new PointerSliderEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Pointer";
		}

		void IPointerSlider.Draw(PaintArgs p, Rectangle r, int posPixels, bool mouseDown, SideDirection direction)
		{
			Draw(p, r, posPixels, mouseDown, direction);
		}

		public PointerSlider()
		{
			DoCreate();
		}

		protected override void CreateObjects()
		{
			base.CreateObjects();
			m_Bevel = new Bevel();
			m_Indicator = new Indicator();
			AddSubClass(Indicator);
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			m_Bevel.Thickness = BevelThickness.X4;
			m_Bevel.Visible = true;
		}

		private bool ShouldSerializeIndicator()
		{
			return ((ISubClassBase)Indicator).ShouldSerialize();
		}

		private void ResetIndicator()
		{
			((ISubClassBase)Indicator).ResetToDefault();
		}

		private bool ShouldSerializeStyle()
		{
			return PropertyShouldSerialize("Style");
		}

		private void ResetStyle()
		{
			PropertyReset("Style");
		}

		private bool ShouldSerializeColor()
		{
			return PropertyShouldSerialize("Color");
		}

		private void ResetColor()
		{
			PropertyReset("Color");
		}

		private bool ShouldSerializeHeight()
		{
			return PropertyShouldSerialize("Height");
		}

		private void ResetHeight()
		{
			PropertyReset("Height");
		}

		private bool ShouldSerializeWidth()
		{
			return PropertyShouldSerialize("Width");
		}

		private void ResetWidth()
		{
			PropertyReset("Width");
		}

		private bool ShouldSerializeTrackStyle()
		{
			return PropertyShouldSerialize("TrackStyle");
		}

		private void ResetTrackStyle()
		{
			PropertyReset("TrackStyle");
		}

		private bool ShouldSerializeTrackColor()
		{
			return PropertyShouldSerialize("TrackColor");
		}

		private void ResetTrackColor()
		{
			PropertyReset("TrackColor");
		}

		private void Draw(PaintArgs p, Rectangle r, int posPixels, bool mouseDown, SideDirection direction)
		{
			Color color = ((!mouseDown) ? Color : iColors.Lighten3(Color));
			Color stateColor = Indicator.GetStateColor(mouseDown);
			iRectangle iRectangle2 = new iRectangle(r);
			if (TrackStyle == PointerTrackStyle.BevelRaised)
			{
				iRectangle2.Left = p.CenterX - 2;
				m_Bevel.Style = BevelStyle.Raised;
				((IBevel)m_Bevel).Draw(p, iRectangle2.Rectangle, p.ControlBackColor, (Orientation)1);
			}
			else if (TrackStyle == PointerTrackStyle.BevelSunken)
			{
				iRectangle2.Left = p.CenterX - 2;
				m_Bevel.Style = BevelStyle.Sunken;
				((IBevel)m_Bevel).Draw(p, iRectangle2.Rectangle, p.ControlBackColor, (Orientation)1);
			}
			else if (TrackStyle == PointerTrackStyle.Box)
			{
				iRectangle2.Left += 4;
				iRectangle2.Width -= 8;
				p.Graphics.FillRectangle(p.Graphics.Brush(TrackColor), iRectangle2.Rectangle);
				BorderSimple.Draw(p, iRectangle2.Rectangle, BorderStyleSimple.Sunken, p.ControlBackColor);
			}
			iRectangle2.Rectangle = r;
			if (Style == PointerStyleSlider.Bar)
			{
				iRectangle2.Width = Width;
				iRectangle2.Top = (int)((float)posPixels - (float)Height / 2f);
				iRectangle2.Height = Height;
				p.Graphics.FillRectangle(p.Graphics.Brush(color), iRectangle2.Rectangle);
				BorderSimple.Draw(p, iRectangle2.Rectangle, BorderStyleSimple.Raised, p.ControlBackColor);
			}
			else if (Style == PointerStyleSlider.BarIndicator)
			{
				iRectangle2.Width = Width;
				iRectangle2.Top = (int)((float)posPixels - (float)Height / 2f);
				iRectangle2.Height = Height;
				iRectangle2.Inflate(-2, -2);
				p.Graphics.FillRectangle(p.Graphics.Brush(stateColor), iRectangle2.Rectangle);
				iRectangle2.Inflate(2, 2);
				BorderSimple.Draw(p, iRectangle2.Rectangle, BorderStyleSimple.Raised, p.ControlBackColor);
			}
			else if (Style == PointerStyleSlider.BarIndicatorLight)
			{
				iRectangle2.Width = Width;
				iRectangle2.Top = (int)((float)posPixels - (float)Height / 2f);
				iRectangle2.Height = Height;
				p.Graphics.FillRectangle(p.Graphics.Brush(color), iRectangle2.Rectangle);
				p.Graphics.DrawLine(p.Graphics.Pen(stateColor), iRectangle2.Left + 3, iRectangle2.CenterY - 1, iRectangle2.Right - 4, iRectangle2.CenterY - 1);
				p.Graphics.DrawLine(p.Graphics.Pen(stateColor), iRectangle2.Left + 3, iRectangle2.CenterY, iRectangle2.Right - 4, iRectangle2.CenterY);
				BorderSimple.Draw(p, iRectangle2.Rectangle, BorderStyleSimple.Raised, p.ControlBackColor);
			}
			else if (Style == PointerStyleSlider.Pointer)
			{
				iRectangle2.Width = Width;
				iRectangle2.Top = posPixels - Height / 2;
				iRectangle2.Height = Height;
				Point[] array = ((direction != SideDirection.LeftToRight) ? Shapes.GetPointerPoints(iRectangle2.Rectangle, Direction.Left) : Shapes.GetPointerPoints(iRectangle2.Rectangle, Direction.Right));
				iColors.FaceColorLight = SystemColors.ControlLightLight;
				iColors.FaceColorDark = SystemColors.ControlDarkDark;
				p.Graphics.SmoothingMode = (SmoothingMode)4;
				p.Graphics.FillPolygon(p.Graphics.Brush(color), array);
				p.Graphics.DrawLine(p.Graphics.Pen(iColors.ToFaceColor(FaceReference.Left, p.Rotation, invert: false)), array[0], array[1]);
				p.Graphics.DrawLine(p.Graphics.Pen(iColors.ToFaceColor(FaceReference.Bottom, p.Rotation, invert: false)), array[1], array[2]);
				p.Graphics.DrawLine(p.Graphics.Pen(iColors.ToFaceColor(FaceReference.Bottom, p.Rotation, invert: false)), array[2], array[3]);
				p.Graphics.DrawLine(p.Graphics.Pen(iColors.ToFaceColor(FaceReference.Top, p.Rotation, invert: false)), array[3], array[4]);
				p.Graphics.DrawLine(p.Graphics.Pen(iColors.ToFaceColor(FaceReference.Top, p.Rotation, invert: false)), array[4], array[0]);
				p.Graphics.SmoothingMode = (SmoothingMode)0;
			}
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class PointerSliderEditorPlugIn : PlugInStandard
	{
		private FocusLabel label1;

		private FocusLabel label2;

		private FocusLabel label3;

		private ComboBox StyleComboBox;

		private NumericUpDown WidthNumericUpDown;

		private NumericUpDown HeightNumericUpDown;

		private FocusLabel label4;

		private ComboBox TrackStyleComboBox;

		private FocusLabel label7;

		private FocusLabel label6;

		private ColorPicker TrackColorPicker;

		private ColorPicker ColorPicker;

		private Container components = null;

		public PointerSliderEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			WidthNumericUpDown = new NumericUpDown();
			label1 = new FocusLabel();
			label2 = new FocusLabel();
			HeightNumericUpDown = new NumericUpDown();
			label3 = new FocusLabel();
			StyleComboBox = new ComboBox();
			label4 = new FocusLabel();
			TrackStyleComboBox = new ComboBox();
			label7 = new FocusLabel();
			TrackColorPicker = new ColorPicker();
			ColorPicker = new ColorPicker();
			label6 = new FocusLabel();
			((Control)this).SuspendLayout();
			((Control)WidthNumericUpDown).Location = new Point(72, 8);
			((Control)WidthNumericUpDown).Name = "WidthNumericUpDown";
			WidthNumericUpDown.PropertyName = "Width";
			((Control)WidthNumericUpDown).Size = new Size(48, 20);
			((Control)WidthNumericUpDown).TabIndex = 0;
			((UpDownBase)WidthNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)WidthNumericUpDown;
			((Control)label1).Location = new Point(36, 9);
			((Control)label1).Name = "label1";
			label1.Size = new Size(36, 15);
			label1.Text = "Width";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)HeightNumericUpDown;
			((Control)label2).Location = new Point(33, 33);
			((Control)label2).Name = "label2";
			label2.Size = new Size(39, 15);
			label2.Text = "Height";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)HeightNumericUpDown).Location = new Point(72, 32);
			((Control)HeightNumericUpDown).Name = "HeightNumericUpDown";
			HeightNumericUpDown.PropertyName = "Height";
			((Control)HeightNumericUpDown).Size = new Size(48, 20);
			((Control)HeightNumericUpDown).TabIndex = 1;
			((UpDownBase)HeightNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)StyleComboBox;
			((Control)label3).Location = new Point(256, 10);
			((Control)label3).Name = "label3";
			label3.Size = new Size(32, 15);
			label3.Text = "Style";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			((ComboBox)StyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)StyleComboBox).Location = new Point(288, 8);
			((Control)StyleComboBox).Name = "StyleComboBox";
			StyleComboBox.PropertyName = "Style";
			((Control)StyleComboBox).Size = new Size(121, 21);
			((Control)StyleComboBox).TabIndex = 4;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)TrackStyleComboBox;
			((Control)label4).Location = new Point(226, 34);
			((Control)label4).Name = "label4";
			label4.Size = new Size(62, 15);
			label4.Text = "Track Style";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((ComboBox)TrackStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)TrackStyleComboBox).Location = new Point(288, 32);
			((Control)TrackStyleComboBox).Name = "TrackStyleComboBox";
			TrackStyleComboBox.PropertyName = "TrackStyle";
			((Control)TrackStyleComboBox).Size = new Size(121, 21);
			((Control)TrackStyleComboBox).TabIndex = 5;
			label7.LoadingBegin();
			label7.FocusControl = (Control)(object)TrackColorPicker;
			((Control)label7).Location = new Point(8, 99);
			((Control)label7).Name = "label7";
			label7.Size = new Size(64, 15);
			label7.Text = "Track Color";
			label7.UpdateFrameRate = 50.0;
			label7.LoadingEnd();
			((Control)TrackColorPicker).Location = new Point(72, 96);
			((Control)TrackColorPicker).Name = "TrackColorPicker";
			TrackColorPicker.PropertyName = "TrackColor";
			((Control)TrackColorPicker).Size = new Size(144, 21);
			((Control)TrackColorPicker).TabIndex = 3;
			((Control)ColorPicker).Location = new Point(72, 72);
			((Control)ColorPicker).Name = "ColorPicker";
			ColorPicker.PropertyName = "Color";
			((Control)ColorPicker).Size = new Size(144, 21);
			((Control)ColorPicker).TabIndex = 2;
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)ColorPicker;
			((Control)label6).Location = new Point(38, 75);
			((Control)label6).Name = "label6";
			label6.Size = new Size(34, 15);
			label6.Text = "Color";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)TrackColorPicker);
			((Control)this).Controls.Add((Control)(object)label7);
			((Control)this).Controls.Add((Control)(object)ColorPicker);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)TrackStyleComboBox);
			((Control)this).Controls.Add((Control)(object)label3);
			((Control)this).Controls.Add((Control)(object)StyleComboBox);
			((Control)this).Controls.Add((Control)(object)HeightNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)WidthNumericUpDown);
			((Control)this).Location = new Point(10, 20);
			((Control)this).Name = "PointerSliderEditorPlugIn";
			((Control)this).Size = new Size(544, 248);
			base.Title = "Pointer Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new IndicatorEditorPlugIn(), "Indicator", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as PointerSlider).Indicator;
		}
	}
}
namespace Iocomp.Interfaces
{
	public interface IPointerSwitchPanel
	{
		void Draw(PaintArgs p, Rectangle r, float angle, bool focusShow, bool isDown);
	}
}
namespace Iocomp.Classes
{
	[Description("")]
	public sealed class PointerSwitchPanel : SubClassBase, IPointerSwitchPanel
	{
		private Color m_EdgeColor;

		private Color m_HandleColor;

		private int m_EdgeWidth;

		private int m_HandleWidth;

		private int m_Margin;

		[Description("")]
		public Color EdgeColor
		{
			get
			{
				return m_EdgeColor;
			}
			set
			{
				PropertyUpdateDefault("EdgeColor", value);
				if (EdgeColor != value)
				{
					m_EdgeColor = value;
					DoPropertyChange(this, "EdgeColor");
				}
			}
		}

		[Description("")]
		public Color HandleColor
		{
			get
			{
				return m_HandleColor;
			}
			set
			{
				PropertyUpdateDefault("HandleColor", value);
				if (HandleColor != value)
				{
					m_HandleColor = value;
					DoPropertyChange(this, "HandleColor");
				}
			}
		}

		public new Color BackColor
		{
			get
			{
				return base.BackColor;
			}
			set
			{
				base.BackColor = value;
			}
		}

		[Description("")]
		public int EdgeWidth
		{
			get
			{
				return m_EdgeWidth;
			}
			set
			{
				PropertyUpdateDefault("EdgeWidth", value);
				if (EdgeWidth != value)
				{
					m_EdgeWidth = value;
					DoPropertyChange(this, "EdgeWidth");
				}
			}
		}

		[Description("")]
		public int HandleWidth
		{
			get
			{
				return m_HandleWidth;
			}
			set
			{
				PropertyUpdateDefault("HandleWidth", value);
				if (HandleWidth != value)
				{
					m_HandleWidth = value;
					DoPropertyChange(this, "HandleWidth");
				}
			}
		}

		[Description("")]
		public int Margin
		{
			get
			{
				return m_Margin;
			}
			set
			{
				PropertyUpdateDefault("Margin", value);
				if (Margin != value)
				{
					m_Margin = value;
					DoPropertyChange(this, "Margin");
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new PointerSwitchPanelEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Pointer";
		}

		void IPointerSwitchPanel.Draw(PaintArgs p, Rectangle r, float angle, bool focusShow, bool isDown)
		{
			Draw(p, r, angle, focusShow, isDown);
		}

		public PointerSwitchPanel()
		{
			DoCreate();
		}

		private bool ShouldSerializeEdgeColor()
		{
			return PropertyShouldSerialize("EdgeColor");
		}

		private void ResetEdgeColor()
		{
			PropertyReset("EdgeColor");
		}

		private bool ShouldSerializeHandleColor()
		{
			return PropertyShouldSerialize("HandleColor");
		}

		private void ResetHandleColor()
		{
			PropertyReset("HandleColor");
		}

		private bool ShouldSerializeBackColor()
		{
			return PropertyShouldSerialize("BackColor");
		}

		private void ResetBackColor()
		{
			PropertyReset("BackColor");
		}

		private bool ShouldSerializeEdgeWidth()
		{
			return PropertyShouldSerialize("EdgeWidth");
		}

		private void ResetEdgeWidth()
		{
			PropertyReset("EdgeWidth");
		}

		private bool ShouldSerializeHandleWidth()
		{
			return PropertyShouldSerialize("HandleWidth");
		}

		private void ResetHandleWidth()
		{
			PropertyReset("HandleWidth");
		}

		private bool ShouldSerializeMargin()
		{
			return PropertyShouldSerialize("Margin");
		}

		private void ResetMargin()
		{
			PropertyReset("Margin");
		}

		private void Draw(PaintArgs p, Rectangle r, float angle, bool focusShow, bool isDown)
		{
			//IL_0101: Unknown result type (might be due to invalid IL or missing references)
			//IL_0108: Expected O, but got Unknown
			Color color;
			Color color2;
			Color color3;
			if (isDown)
			{
				color = iColors.Lighten2(EdgeColor);
				color2 = iColors.Lighten2(BackColor);
				color3 = iColors.Lighten2(HandleColor);
			}
			else
			{
				color = EdgeColor;
				color2 = BackColor;
				color3 = HandleColor;
			}
			int num = ((r.Width >= r.Height) ? ((r.Height - 2 * Margin) / 2) : ((r.Width - 2 * Margin) / 2));
			int radius = num - EdgeWidth;
			Point centerPoint = new Point((r.Left + r.Right) / 2, (r.Top + r.Bottom) / 2);
			iRectangle iRectangle2 = new iRectangle(iDraw.GetRadiusRectangle(centerPoint, num));
			Rectangle radiusRectangle = iDraw.GetRadiusRectangle(centerPoint, radius);
			p.Graphics.FillEllipse(p.Graphics.Brush(color), iRectangle2.Rectangle);
			p.Graphics.FillEllipse(p.Graphics.Brush(color2), radiusRectangle);
			GraphicsPath val = new GraphicsPath();
			val.AddEllipse(radiusRectangle);
			p.Graphics.SetClip(val);
			GraphicsState gstate = p.Graphics.Save();
			p.Graphics.TranslateTransform(centerPoint.X, centerPoint.Y);
			p.Graphics.RotateTransform(angle);
			p.Graphics.TranslateTransform(-centerPoint.X, -centerPoint.Y);
			Rectangle rect = new Rectangle(centerPoint.X - HandleWidth / 2, radiusRectangle.Top, HandleWidth, radiusRectangle.Height);
			p.Graphics.FillRectangle(p.Graphics.Brush(color3), rect);
			p.Graphics.DrawRectangle(p.Graphics.Pen(color2), rect.Left, rect.Top, rect.Width, rect.Height);
			p.Graphics.Restore(gstate);
			p.Graphics.ResetClip();
			if (ControlBase.Focused && focusShow)
			{
				iRectangle2.Inflate(2, 2);
				iRectangle2.Offset(1, 1);
				p.Graphics.DrawFocusRectangle(iRectangle2.PenRectangle, ControlBase.BackColor);
			}
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class PointerSwitchPanelEditorPlugIn : PlugInStandard
	{
		private GroupBox groupBox3;

		private FocusLabel label1;

		private FocusLabel label5;

		private NumericUpDown MarginNumericUpDown;

		private NumericUpDown EdgeWidthNumericUpDown;

		private FocusLabel label7;

		private GroupBox groupBox1;

		private FocusLabel label2;

		private FocusLabel label4;

		private NumericUpDown HandleWidthNumericUpDown;

		private ColorPicker HandleColorPicker;

		private FocusLabel label6;

		private ColorPicker BackColorPicker;

		private ColorPicker EdgeColorPicker;

		private Container components = null;

		public PointerSwitchPanelEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			//IL_004e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0058: Expected O, but got Unknown
			groupBox3 = new GroupBox();
			label7 = new FocusLabel();
			EdgeColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			EdgeWidthNumericUpDown = new NumericUpDown();
			MarginNumericUpDown = new NumericUpDown();
			label5 = new FocusLabel();
			groupBox1 = new GroupBox();
			label4 = new FocusLabel();
			HandleColorPicker = new ColorPicker();
			HandleWidthNumericUpDown = new NumericUpDown();
			label2 = new FocusLabel();
			label6 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			((Control)groupBox3).SuspendLayout();
			((Control)groupBox1).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)groupBox3).Controls.Add((Control)(object)label7);
			((Control)groupBox3).Controls.Add((Control)(object)EdgeColorPicker);
			((Control)groupBox3).Controls.Add((Control)(object)label1);
			((Control)groupBox3).Controls.Add((Control)(object)EdgeWidthNumericUpDown);
			((Control)groupBox3).Location = new Point(248, 8);
			((Control)groupBox3).Name = "groupBox3";
			((Control)groupBox3).Size = new Size(200, 80);
			((Control)groupBox3).TabIndex = 2;
			groupBox3.TabStop = false;
			((Control)groupBox3).Text = "Edge";
			label7.LoadingBegin();
			label7.FocusControl = (Control)(object)EdgeColorPicker;
			((Control)label7).Location = new Point(14, 51);
			((Control)label7).Name = "label7";
			label7.Size = new Size(34, 15);
			label7.Text = "Color";
			label7.UpdateFrameRate = 50.0;
			label7.LoadingEnd();
			((Control)EdgeColorPicker).Location = new Point(48, 48);
			((Control)EdgeColorPicker).Name = "EdgeColorPicker";
			EdgeColorPicker.PropertyName = "EdgeColor";
			((Control)EdgeColorPicker).Size = new Size(144, 21);
			((Control)EdgeColorPicker).TabIndex = 1;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)EdgeWidthNumericUpDown;
			((Control)label1).Location = new Point(12, 25);
			((Control)label1).Name = "label1";
			label1.Size = new Size(36, 15);
			label1.Text = "Width";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)EdgeWidthNumericUpDown).Location = new Point(48, 24);
			((Control)EdgeWidthNumericUpDown).Name = "EdgeWidthNumericUpDown";
			EdgeWidthNumericUpDown.PropertyName = "EdgeWidth";
			((Control)EdgeWidthNumericUpDown).Size = new Size(48, 20);
			((Control)EdgeWidthNumericUpDown).TabIndex = 0;
			((UpDownBase)EdgeWidthNumericUpDown).TextAlign = (HorizontalAlignment)2;
			((Control)MarginNumericUpDown).Location = new Point(64, 16);
			((Control)MarginNumericUpDown).Name = "MarginNumericUpDown";
			MarginNumericUpDown.PropertyName = "Margin";
			((Control)MarginNumericUpDown).Size = new Size(48, 20);
			((Control)MarginNumericUpDown).TabIndex = 0;
			((UpDownBase)MarginNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label5.LoadingBegin();
			label5.FocusControl = (Control)(object)MarginNumericUpDown;
			((Control)label5).Location = new Point(23, 17);
			((Control)label5).Name = "label5";
			label5.Size = new Size(41, 15);
			label5.Text = "Margin";
			label5.UpdateFrameRate = 50.0;
			label5.LoadingEnd();
			((Control)groupBox1).Controls.Add((Control)(object)label4);
			((Control)groupBox1).Controls.Add((Control)(object)HandleColorPicker);
			((Control)groupBox1).Controls.Add((Control)(object)HandleWidthNumericUpDown);
			((Control)groupBox1).Controls.Add((Control)(object)label2);
			((Control)groupBox1).Location = new Point(248, 96);
			((Control)groupBox1).Name = "groupBox1";
			((Control)groupBox1).Size = new Size(200, 80);
			((Control)groupBox1).TabIndex = 3;
			groupBox1.TabStop = false;
			((Control)groupBox1).Text = "Handle";
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)HandleColorPicker;
			((Control)label4).Location = new Point(14, 51);
			((Control)label4).Name = "label4";
			label4.Size = new Size(34, 15);
			label4.Text = "Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)HandleColorPicker).Location = new Point(48, 48);
			((Control)HandleColorPicker).Name = "HandleColorPicker";
			HandleColorPicker.PropertyName = "HandleColor";
			((Control)HandleColorPicker).Size = new Size(144, 21);
			((Control)HandleColorPicker).TabIndex = 1;
			((Control)HandleWidthNumericUpDown).Location = new Point(48, 24);
			((Control)HandleWidthNumericUpDown).Name = "HandleWidthNumericUpDown";
			HandleWidthNumericUpDown.PropertyName = "HandleWidth";
			((Control)HandleWidthNumericUpDown).Size = new Size(48, 20);
			((Control)HandleWidthNumericUpDown).TabIndex = 0;
			((UpDownBase)HandleWidthNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)HandleWidthNumericUpDown;
			((Control)label2).Location = new Point(12, 25);
			((Control)label2).Name = "label2";
			label2.Size = new Size(36, 15);
			label2.Text = "Width";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)BackColorPicker;
			((Control)label6).Location = new Point(3, 155);
			((Control)label6).Name = "label6";
			label6.Size = new Size(61, 15);
			label6.Text = "Back Color";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(64, 152);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(144, 21);
			((Control)BackColorPicker).TabIndex = 1;
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)groupBox1);
			((Control)this).Controls.Add((Control)(object)MarginNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label5);
			((Control)this).Controls.Add((Control)(object)groupBox3);
			((Control)this).Location = new Point(10, 20);
			((Control)this).Name = "PointerSwitchPanelEditorPlugIn";
			((Control)this).Size = new Size(472, 192);
			base.Title = "Switch Editor";
			((Control)groupBox3).ResumeLayout(false);
			((Control)groupBox1).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}
	}
}
namespace Iocomp.Interfaces
{
	public interface IPointerSwitchRotary
	{
		SizeF RequiredSize { get; }

		void Draw(PaintArgs p, Point centerPoint, float angle, bool mouseDown);
	}
}
namespace Iocomp.Types
{
	public enum PointerStyleSwitchRotary
	{
		Pointer,
		Bar
	}
}
namespace Iocomp.Classes
{
	[Description("Contains the properties that control the slider's pointer properties.")]
	[DefaultProperty("Style")]
	public sealed class PointerSwitchRotary : SubClassBase, IPointerSwitchRotary
	{
		private PointerStyleSwitchRotary m_Style;

		private int m_Length;

		private int m_Width;

		SizeF IPointerSwitchRotary.RequiredSize => RequiredSize;

		[Category("Iocomp")]
		[Description("")]
		public PointerStyleSwitchRotary Style
		{
			get
			{
				return m_Style;
			}
			set
			{
				PropertyUpdateDefault("Style", value);
				if (Style != value)
				{
					m_Style = value;
					DoPropertyChange(this, "Style");
				}
			}
		}

		[Description("")]
		public new Color Color
		{
			get
			{
				return base.Color;
			}
			set
			{
				base.Color = value;
			}
		}

		[Description("")]
		public int Length
		{
			get
			{
				return m_Length;
			}
			set
			{
				PropertyUpdateDefault("Length", value);
				if (Length != value)
				{
					m_Length = value;
					DoPropertyChange(this, "Length");
				}
			}
		}

		[Description("")]
		public int Width
		{
			get
			{
				return m_Width;
			}
			set
			{
				PropertyUpdateDefault("Width", value);
				if (Width != value)
				{
					m_Width = value;
					DoPropertyChange(this, "Width");
				}
			}
		}

		private SizeF RequiredSize => new SizeF(Width, Length);

		protected override PlugInStandard GetPlugIn()
		{
			return new PointerSwitchRotaryEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Pointer";
		}

		void IPointerSwitchRotary.Draw(PaintArgs p, Point centerPoint, float angle, bool mouseDown)
		{
			Draw(p, centerPoint, angle, mouseDown);
		}

		public PointerSwitchRotary()
		{
			DoCreate();
		}

		private bool ShouldSerializeStyle()
		{
			return PropertyShouldSerialize("Style");
		}

		private void ResetStyle()
		{
			PropertyReset("Style");
		}

		private bool ShouldSerializeColor()
		{
			return PropertyShouldSerialize("Color");
		}

		private void ResetColor()
		{
			PropertyReset("Color");
		}

		private bool ShouldSerializeLength()
		{
			return PropertyShouldSerialize("Length");
		}

		private void ResetLength()
		{
			PropertyReset("Length");
		}

		private bool ShouldSerializeWidth()
		{
			return PropertyShouldSerialize("Width");
		}

		private void ResetWidth()
		{
			PropertyReset("Width");
		}

		private Color GetAngleShadowColor(PaintArgs p, double angle)
		{
			Color result;
			Color result2;
			if (Color != SystemColors.Control)
			{
				result = iColors.Darken4(Color);
				result2 = iColors.Lighten4(Color);
			}
			else
			{
				result = SystemColors.ControlDarkDark;
				result2 = SystemColors.ControlLightLight;
			}
			if (angle >= 270.0)
			{
				return result2;
			}
			if (angle >= 0.0 && angle < 90.0)
			{
				return result2;
			}
			return result;
		}

		private void DrawBar(PaintArgs p, Point centerPoint, float angle, bool mouseDown)
		{
			Color color = ((!mouseDown) ? Color : iColors.Lighten3(Color));
			double[] array = new double[4];
			Point[] array2 = new Point[4];
			array[0] = Math2.AngleNormalized(270f + angle + p.RotationAngle);
			array[1] = Math2.AngleNormalized(0f + angle + p.RotationAngle);
			array[2] = Math2.AngleNormalized(90f + angle + p.RotationAngle);
			array[3] = Math2.AngleNormalized(180f + angle + p.RotationAngle);
			Point centerPoint2 = Math2.ToRotatedPoint(angle - 180f, Length / 2, centerPoint);
			Point centerPoint3 = Math2.ToRotatedPoint(angle, Length / 2, centerPoint);
			ref Point reference = ref array2[0];
			reference = Math2.ToRotatedPoint(angle + 90f, Width / 2, centerPoint2);
			ref Point reference2 = ref array2[1];
			reference2 = Math2.ToRotatedPoint(angle - 90f, Width / 2, centerPoint2);
			ref Point reference3 = ref array2[2];
			reference3 = Math2.ToRotatedPoint(angle - 90f, Width / 2, centerPoint3);
			ref Point reference4 = ref array2[3];
			reference4 = Math2.ToRotatedPoint(angle + 90f, Width / 2, centerPoint3);
			Point pt = Math2.ToRotatedPoint(angle, Length / 2 - 1, centerPoint);
			Point pt2 = Math2.ToRotatedPoint(angle, Length / 2 - 8, centerPoint);
			p.Graphics.FillPolygon(p.Graphics.Brush(color), array2);
			p.Graphics.DrawLine(p.Graphics.Pen(GetAngleShadowColor(p, array[0])), array2[1], array2[0]);
			p.Graphics.DrawLine(p.Graphics.Pen(GetAngleShadowColor(p, array[1])), array2[2], array2[1]);
			p.Graphics.DrawLine(p.Graphics.Pen(GetAngleShadowColor(p, array[2])), array2[3], array2[2]);
			p.Graphics.DrawLine(p.Graphics.Pen(GetAngleShadowColor(p, array[3])), array2[0], array2[3]);
			p.Graphics.DrawLine(p.Graphics.Pen(Color.Black), pt, pt2);
		}

		private void DrawPointer(PaintArgs p, Point centerPoint, float angle, bool mouseDown)
		{
			Color color = ((!mouseDown) ? Color : iColors.Lighten3(Color));
			double[] array = new double[5];
			Point[] array2 = new Point[5];
			array[0] = Math2.AngleNormalized(270f + angle + p.RotationAngle);
			array[1] = Math2.AngleNormalized(0f + angle + p.RotationAngle);
			array[2] = Math2.AngleNormalized(90f + angle + p.RotationAngle);
			array[3] = Math2.AngleNormalized(180f + angle + p.RotationAngle);
			array[4] = Math2.AngleNormalized(180f + angle + p.RotationAngle);
			Point centerPoint2 = Math2.ToRotatedPoint(angle - 180f, Length / 2, centerPoint);
			Point centerPoint3 = Math2.ToRotatedPoint(angle, Length / 2 - Width / 2, centerPoint);
			ref Point reference = ref array2[0];
			reference = Math2.ToRotatedPoint(angle + 90f, Width / 2, centerPoint2);
			ref Point reference2 = ref array2[1];
			reference2 = Math2.ToRotatedPoint(angle - 90f, Width / 2, centerPoint2);
			ref Point reference3 = ref array2[2];
			reference3 = Math2.ToRotatedPoint(angle - 90f, Width / 2, centerPoint3);
			ref Point reference4 = ref array2[3];
			reference4 = Math2.ToRotatedPoint(angle, Width / 2, centerPoint3);
			ref Point reference5 = ref array2[4];
			reference5 = Math2.ToRotatedPoint(angle + 90f, Width / 2, centerPoint3);
			p.Graphics.FillPolygon(p.Graphics.Brush(color), array2);
			p.Graphics.DrawLine(p.Graphics.Pen(GetAngleShadowColor(p, array[0])), array2[1], array2[0]);
			p.Graphics.DrawLine(p.Graphics.Pen(GetAngleShadowColor(p, array[1])), array2[2], array2[1]);
			p.Graphics.DrawLine(p.Graphics.Pen(GetAngleShadowColor(p, array[2])), array2[3], array2[2]);
			p.Graphics.DrawLine(p.Graphics.Pen(GetAngleShadowColor(p, array[3])), array2[4], array2[3]);
			p.Graphics.DrawLine(p.Graphics.Pen(GetAngleShadowColor(p, array[4])), array2[0], array2[4]);
		}

		private void Draw(PaintArgs p, Point centerPoint, float angle, bool mouseDown)
		{
			p.Graphics.SmoothingMode = (SmoothingMode)4;
			if (Style == PointerStyleSwitchRotary.Bar)
			{
				DrawBar(p, centerPoint, angle, mouseDown);
			}
			else if (Style == PointerStyleSwitchRotary.Pointer)
			{
				DrawPointer(p, centerPoint, angle, mouseDown);
			}
			p.Graphics.SmoothingMode = (SmoothingMode)0;
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class PointerSwitchRotaryEditorPlugIn : PlugInStandard
	{
		private FocusLabel label1;

		private NumericUpDown WidthNumericUpDown;

		private NumericUpDown LengthNumericUpDown;

		private FocusLabel label2;

		private FocusLabel label3;

		private ComboBox StyleComboBox;

		private FocusLabel label4;

		private ColorPicker ColorPicker;

		private Container components = null;

		public PointerSwitchRotaryEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label1 = new FocusLabel();
			WidthNumericUpDown = new NumericUpDown();
			LengthNumericUpDown = new NumericUpDown();
			label2 = new FocusLabel();
			label3 = new FocusLabel();
			StyleComboBox = new ComboBox();
			label4 = new FocusLabel();
			ColorPicker = new ColorPicker();
			((Control)this).SuspendLayout();
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)WidthNumericUpDown;
			((Control)label1).Location = new Point(28, 49);
			((Control)label1).Name = "label1";
			label1.Size = new Size(36, 15);
			label1.Text = "Width";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)WidthNumericUpDown).Location = new Point(64, 48);
			((NumericUpDown)WidthNumericUpDown).Maximum = new decimal(new int[4] { 1000, 0, 0, 0 });
			((Control)WidthNumericUpDown).Name = "WidthNumericUpDown";
			WidthNumericUpDown.PropertyName = "Width";
			((Control)WidthNumericUpDown).Size = new Size(48, 20);
			((Control)WidthNumericUpDown).TabIndex = 1;
			((UpDownBase)WidthNumericUpDown).TextAlign = (HorizontalAlignment)2;
			((Control)LengthNumericUpDown).Location = new Point(64, 72);
			((NumericUpDown)LengthNumericUpDown).Maximum = new decimal(new int[4] { 1000, 0, 0, 0 });
			((Control)LengthNumericUpDown).Name = "LengthNumericUpDown";
			LengthNumericUpDown.PropertyName = "Length";
			((Control)LengthNumericUpDown).Size = new Size(48, 20);
			((Control)LengthNumericUpDown).TabIndex = 2;
			((UpDownBase)LengthNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)LengthNumericUpDown;
			((Control)label2).Location = new Point(23, 73);
			((Control)label2).Name = "label2";
			label2.Size = new Size(41, 15);
			label2.Text = "Length";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)StyleComboBox;
			((Control)label3).Location = new Point(32, 10);
			((Control)label3).Name = "label3";
			label3.Size = new Size(32, 15);
			label3.Text = "Style";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			((ComboBox)StyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)StyleComboBox).Location = new Point(64, 8);
			((ComboBox)StyleComboBox).MaxDropDownItems = 20;
			((Control)StyleComboBox).Name = "StyleComboBox";
			StyleComboBox.PropertyName = "Style";
			((Control)StyleComboBox).Size = new Size(144, 21);
			((Control)StyleComboBox).TabIndex = 0;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ColorPicker;
			((Control)label4).Location = new Point(30, 115);
			((Control)label4).Name = "label4";
			label4.Size = new Size(34, 15);
			label4.Text = "Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			((Control)ColorPicker).Location = new Point(64, 112);
			((Control)ColorPicker).Name = "ColorPicker";
			ColorPicker.PropertyName = "Color";
			((Control)ColorPicker).TabIndex = 3;
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)ColorPicker);
			((Control)this).Controls.Add((Control)(object)label3);
			((Control)this).Controls.Add((Control)(object)StyleComboBox);
			((Control)this).Controls.Add((Control)(object)LengthNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)WidthNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Name = "PointerSwitchRotaryEditorPlugIn";
			((Control)this).Size = new Size(592, 288);
			base.Title = "Pointer Editor";
			((Control)this).ResumeLayout(false);
		}
	}
}
namespace Iocomp.Interfaces
{
	public interface IPointerSwitchToggle
	{
		void Draw(PaintArgs p);
	}
}
namespace Iocomp.Classes
{
	[DefaultProperty("BevelStyle")]
	[Description("Contains the properties that control the appearance of the switch.")]
	public sealed class PointerSwitchToggle : SubClassBase, IPointerSwitchToggle
	{
		private Bevel m_Bevel;

		private int m_Height;

		[Description("Contains the properties for title.")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public Bevel Bevel => m_Bevel;

		[Description("Specifies the size of the pointer based on the percent of the control's height.")]
		public int Height
		{
			get
			{
				return m_Height;
			}
			set
			{
				PropertyUpdateDefault("Height", value);
				if (value < 10)
				{
					ThrowStreamingSafeException("Height value must be greater than 10.");
				}
				if (value > 90)
				{
					ThrowStreamingSafeException("Height value must be less than 90.");
				}
				if (value < 10)
				{
					value = 10;
				}
				if (value > 90)
				{
					value = 90;
				}
				if (Height != value)
				{
					m_Height = value;
					DoPropertyChange(this, "Height");
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new PointerSwitchToggleEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Switch";
		}

		void IPointerSwitchToggle.Draw(PaintArgs p)
		{
			Draw(p);
		}

		public PointerSwitchToggle()
		{
			DoCreate();
		}

		protected override void CreateObjects()
		{
			base.CreateObjects();
			m_Bevel = new Bevel();
			AddSubClass(Bevel);
		}

		private bool ShouldSerializeBevel()
		{
			return ((ISubClassBase)Bevel).ShouldSerialize();
		}

		private void ResetBevel()
		{
			((ISubClassBase)Bevel).ResetToDefault();
		}

		private bool ShouldSerializeHeight()
		{
			return PropertyShouldSerialize("Height");
		}

		private void ResetHeight()
		{
			PropertyReset("Height");
		}

		private void Draw(PaintArgs p)
		{
			((IBevel)Bevel).DrawRange(p, p.DrawRectangle, p.ControlBackColor, (Orientation)0);
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class PointerSwitchToggleEditorPlugIn : PlugInStandard
	{
		private FocusLabel label1;

		private NumericUpDown HeightNumericUpDown;

		private Container components = null;

		public PointerSwitchToggleEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label1 = new FocusLabel();
			HeightNumericUpDown = new NumericUpDown();
			((Control)this).SuspendLayout();
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)HeightNumericUpDown;
			((Control)label1).Location = new Point(65, 33);
			((Control)label1).Name = "label1";
			label1.Size = new Size(39, 15);
			label1.Text = "Height";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)HeightNumericUpDown).Location = new Point(104, 32);
			((NumericUpDown)HeightNumericUpDown).Maximum = new decimal(new int[4] { 1000, 0, 0, 0 });
			((Control)HeightNumericUpDown).Name = "HeightNumericUpDown";
			HeightNumericUpDown.PropertyName = "Height";
			((Control)HeightNumericUpDown).Size = new Size(56, 20);
			((Control)HeightNumericUpDown).TabIndex = 0;
			((UpDownBase)HeightNumericUpDown).TextAlign = (HorizontalAlignment)2;
			((Control)this).Controls.Add((Control)(object)HeightNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Name = "PointerSwitchToggleEditorPlugIn";
			((Control)this).Size = new Size(384, 104);
			base.Title = "Pointer Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new BevelEditorPlugIn(), "Bevel", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as PointerSwitchToggle).Bevel;
		}
	}
}
namespace Iocomp.Interfaces
{
	public interface IPointerThermometer
	{
		int TubeRight { get; }

		int TotalWidth { get; }
	}
}
namespace Iocomp.Classes
{
	[Description("Controls the thermometer pointer properties.")]
	[DefaultProperty("ForeColor")]
	public sealed class PointerThermometer : SubClassBase, IPointerThermometer
	{
		private int m_TubeWidth;

		private int m_BulbWidth;

		private AlignmentSide m_Alignment;

		int IPointerThermometer.TotalWidth => TotalWidth;

		int IPointerThermometer.TubeRight => TubeRight;

		public new Color ForeColor
		{
			get
			{
				return base.ForeColor;
			}
			set
			{
				base.ForeColor = value;
			}
		}

		public new Color BackColor
		{
			get
			{
				return base.BackColor;
			}
			set
			{
				base.BackColor = value;
			}
		}

		[Description("")]
		public int TubeWidth
		{
			get
			{
				return m_TubeWidth;
			}
			set
			{
				PropertyUpdateDefault("TubeWidth", value);
				if (m_TubeWidth != value)
				{
					m_TubeWidth = value;
					DoPropertyChange(this, "TubeWidth");
				}
			}
		}

		[Description("")]
		public int BulbWidth
		{
			get
			{
				return m_BulbWidth;
			}
			set
			{
				PropertyUpdateDefault("BulbWidth", value);
				if (BulbWidth != value)
				{
					m_BulbWidth = value;
					DoPropertyChange(this, "BulbWidth");
				}
			}
		}

		[Description("")]
		public AlignmentSide Alignment
		{
			get
			{
				return m_Alignment;
			}
			set
			{
				PropertyUpdateDefault("Alignment", value);
				if (Alignment != value)
				{
					m_Alignment = value;
					DoPropertyChange(this, "Alignment");
				}
			}
		}

		private int TubeRight => TotalWidth / 2 + TubeWidth / 2;

		private int TotalWidth => Math.Max(TubeWidth, BulbWidth);

		protected override PlugInStandard GetPlugIn()
		{
			return new PointerThermometerEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Pointer";
		}

		public PointerThermometer()
		{
			DoCreate();
		}

		private bool ShouldSerializeForeColor()
		{
			return PropertyShouldSerialize("ForeColor");
		}

		private void ResetForeColor()
		{
			PropertyReset("ForeColor");
		}

		private bool ShouldSerializeBackColor()
		{
			return PropertyShouldSerialize("BackColor");
		}

		private void ResetBackColor()
		{
			PropertyReset("BackColor");
		}

		private bool ShouldSerializeTubeWidth()
		{
			return PropertyShouldSerialize("TubeWidth");
		}

		private void ResetTubeWidth()
		{
			PropertyReset("TubeWidth");
		}

		private bool ShouldSerializeBulbWidth()
		{
			return PropertyShouldSerialize("BulbWidth");
		}

		private void ResetBulbWidth()
		{
			PropertyReset("BulbWidth");
		}

		private bool ShouldSerializeAlignment()
		{
			return PropertyShouldSerialize("Alignment");
		}

		private void ResetAlignment()
		{
			PropertyReset("Alignment");
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class PointerThermometerEditorPlugIn : PlugInStandard
	{
		private ComboBox AlignmentComboBox;

		private FocusLabel label4;

		private FocusLabel label5;

		private FocusLabel label8;

		private EditBox BulbWidthTextBox;

		private EditBox TubeWidthTextBox;

		private FocusLabel label2;

		private FocusLabel label1;

		private ColorPicker BackColorPicker;

		private ColorPicker ForeColorPicker;

		private Container components = null;

		public PointerThermometerEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			AlignmentComboBox = new ComboBox();
			label4 = new FocusLabel();
			label5 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			ForeColorPicker = new ColorPicker();
			label8 = new FocusLabel();
			BulbWidthTextBox = new EditBox();
			TubeWidthTextBox = new EditBox();
			label2 = new FocusLabel();
			label1 = new FocusLabel();
			((Control)this).SuspendLayout();
			((ComboBox)AlignmentComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)AlignmentComboBox).Location = new Point(72, 8);
			((Control)AlignmentComboBox).Name = "AlignmentComboBox";
			AlignmentComboBox.PropertyName = "Alignment";
			((Control)AlignmentComboBox).Size = new Size(136, 21);
			((Control)AlignmentComboBox).TabIndex = 0;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)AlignmentComboBox;
			((Control)label4).Location = new Point(15, 10);
			((Control)label4).Name = "label4";
			label4.Size = new Size(57, 15);
			label4.Text = "Alignment";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			label5.LoadingBegin();
			label5.FocusControl = (Control)(object)BackColorPicker;
			((Control)label5).Location = new Point(11, 115);
			((Control)label5).Name = "label5";
			label5.Size = new Size(61, 15);
			label5.Text = "Back Color";
			label5.UpdateFrameRate = 50.0;
			label5.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(72, 112);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(144, 21);
			((Control)BackColorPicker).TabIndex = 3;
			((Control)ForeColorPicker).Location = new Point(72, 136);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(144, 21);
			((Control)ForeColorPicker).TabIndex = 4;
			label8.LoadingBegin();
			label8.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label8).Location = new Point(13, 139);
			((Control)label8).Name = "label8";
			label8.Size = new Size(59, 15);
			label8.Text = "Fore Color";
			label8.UpdateFrameRate = 50.0;
			label8.LoadingEnd();
			BulbWidthTextBox.LoadingBegin();
			((Control)BulbWidthTextBox).Location = new Point(72, 48);
			((Control)BulbWidthTextBox).Name = "BulbWidthTextBox";
			BulbWidthTextBox.PropertyName = "BulbWidth";
			BulbWidthTextBox.Size = new Size(48, 20);
			((Control)BulbWidthTextBox).TabIndex = 1;
			BulbWidthTextBox.LoadingEnd();
			TubeWidthTextBox.LoadingBegin();
			((Control)TubeWidthTextBox).Location = new Point(72, 72);
			((Control)TubeWidthTextBox).Name = "TubeWidthTextBox";
			TubeWidthTextBox.PropertyName = "TubeWidth";
			TubeWidthTextBox.Size = new Size(48, 20);
			((Control)TubeWidthTextBox).TabIndex = 2;
			TubeWidthTextBox.LoadingEnd();
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)BulbWidthTextBox;
			((Control)label2).Location = new Point(11, 50);
			((Control)label2).Name = "label2";
			label2.Size = new Size(61, 15);
			label2.Text = "Bulb Width";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)TubeWidthTextBox;
			((Control)label1).Location = new Point(8, 74);
			((Control)label1).Name = "label1";
			label1.Size = new Size(64, 15);
			label1.Text = "Tube Width";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)BulbWidthTextBox);
			((Control)this).Controls.Add((Control)(object)TubeWidthTextBox);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)label5);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label8);
			((Control)this).Controls.Add((Control)(object)AlignmentComboBox);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Location = new Point(10, 20);
			((Control)this).Name = "PointerThermometerEditorPlugIn";
			((Control)this).Size = new Size(232, 192);
			base.Title = "Pointer Editor";
			((Control)this).ResumeLayout(false);
		}
	}
}
namespace Iocomp.Interfaces
{
	public interface ISegmentsLedBar
	{
		Size RequiredSize { get; }

		Color GetStateColor(Color color, bool value);

		void Draw(PaintArgs p, bool active, iRectangle r, Color color);
	}
}
namespace Iocomp.Classes
{
	[Description("")]
	[DefaultProperty("Color")]
	public sealed class SegmentsLedBar : SubClassBase, ISegmentsLedBar
	{
		private int m_CountDesired;

		private int m_Separation;

		private int m_Thickness;

		private int m_Width;

		private bool m_ShowOffSegments;

		private SegmentsLedStyle m_Style;

		Size ISegmentsLedBar.RequiredSize => RequiredSize;

		[Description("Specifies the default color of the segments.")]
		public new Color Color
		{
			get
			{
				return base.Color;
			}
			set
			{
				base.Color = value;
			}
		}

		[Description("Specifies the desired number of segments. If AutoSize is enabled, the control will grow in size to accommodate the CountDesired value. If AutoSize is disabled, the CountDesired will be adjusted  based on the size of the control")]
		[RefreshProperties(RefreshProperties.All)]
		public int CountDesired
		{
			get
			{
				return m_CountDesired;
			}
			set
			{
				PropertyUpdateDefault("CountDesired", value);
				if (CountDesired != value)
				{
					m_CountDesired = value;
					DoPropertyChange(this, "CountDesired");
				}
			}
		}

		[Description("Specifies the seperation between each segment in pixels.")]
		public int Separation
		{
			get
			{
				return m_Separation;
			}
			set
			{
				PropertyUpdateDefault("Separation", value);
				if (Separation != value)
				{
					m_Separation = value;
					DoPropertyChange(this, "Separation");
				}
			}
		}

		[Description("Specifies the thickness of each segment in pixels.")]
		public int Thickness
		{
			get
			{
				return m_Thickness;
			}
			set
			{
				PropertyUpdateDefault("Thickness", value);
				if (Thickness != value)
				{
					m_Thickness = value;
					DoPropertyChange(this, "Thickness");
				}
			}
		}

		[Description("Specifies the width of each segments in pixels.")]
		public int Width
		{
			get
			{
				return m_Width;
			}
			set
			{
				PropertyUpdateDefault("Width", value);
				if (Width != value)
				{
					m_Width = value;
					DoPropertyChange(this, "Width");
				}
			}
		}

		[Description("Specifies if the off segments are shown")]
		public bool ShowOffSegments
		{
			get
			{
				return m_ShowOffSegments;
			}
			set
			{
				PropertyUpdateDefault("ShowOffSegments", value);
				if (ShowOffSegments != value)
				{
					m_ShowOffSegments = value;
					DoPropertyChange(this, "ShowOffSegments");
				}
			}
		}

		[Description("Specifies the drawing style of the segments")]
		public SegmentsLedStyle Style
		{
			get
			{
				return m_Style;
			}
			set
			{
				PropertyUpdateDefault("Style", value);
				if (Style != value)
				{
					m_Style = value;
					DoPropertyChange(this, "Style");
				}
			}
		}

		private Size RequiredSize => new Size(Width, CountDesired * (Thickness + Separation) - Separation);

		protected override PlugInStandard GetPlugIn()
		{
			return new SegmentsLedBarEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Segments Led Bar";
		}

		Color ISegmentsLedBar.GetStateColor(Color color, bool value)
		{
			return GetStateColor(color, value);
		}

		void ISegmentsLedBar.Draw(PaintArgs p, bool active, iRectangle r, Color color)
		{
			Draw(p, active, r, color);
		}

		public SegmentsLedBar()
		{
			DoCreate();
		}

		private bool ShouldSerializeColor()
		{
			return PropertyShouldSerialize("Color");
		}

		private void ResetColor()
		{
			PropertyReset("Color");
		}

		private bool ShouldSerializeCountDesired()
		{
			return PropertyShouldSerialize("CountDesired");
		}

		private void ResetCountDesired()
		{
			PropertyReset("CountDesired");
		}

		private bool ShouldSerializeSeparation()
		{
			return PropertyShouldSerialize("Separation");
		}

		private void ResetSeparation()
		{
			PropertyReset("Separation");
		}

		private bool ShouldSerializeThickness()
		{
			return PropertyShouldSerialize("Thickness");
		}

		private void ResetThickness()
		{
			PropertyReset("Thickness");
		}

		private bool ShouldSerializeWidth()
		{
			return PropertyShouldSerialize("Width");
		}

		private void ResetWidth()
		{
			PropertyReset("Width");
		}

		private bool ShouldSerializeShowOffSegments()
		{
			return PropertyShouldSerialize("ShowOffSegments");
		}

		private void ResetShowOffSegments()
		{
			PropertyReset("ShowOffSegments");
		}

		private bool ShouldSerializeStyle()
		{
			return PropertyShouldSerialize("Style");
		}

		private void ResetStyle()
		{
			PropertyReset("Style");
		}

		private Color GetStateColor(Color color, bool value)
		{
			if (value)
			{
				return color;
			}
			return iColors.ToOffColor(color);
		}

		private void Draw(PaintArgs p, bool active, iRectangle r, Color color)
		{
			if (active || ShowOffSegments)
			{
				if (Style == SegmentsLedStyle.Flat)
				{
					p.Graphics.FillRectangle(p.Graphics.Brush(GetStateColor(color, active)), r.Rectangle);
				}
				else
				{
					p.Graphics.FillTube3D(r.Rectangle, GetStateColor(color, active), (Orientation)1, 0.5f, sigma: true);
				}
			}
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class SegmentsLedBarEditorPlugIn : PlugInStandard
	{
		private FocusLabel label7;

		private NumericUpDown SeperationNumericUpDown;

		private FocusLabel label6;

		private NumericUpDown ThicknessNumericUpDown;

		private FocusLabel label8;

		private NumericUpDown WidthNumericUpDown;

		private FocusLabel label9;

		private NumericUpDown CountsDesiredNumericUpDown;

		private FocusLabel label10;

		private FocusLabel label2;

		private ComboBox StyleComboBox;

		private CheckBox ShowOffSegmentsCheckBox;

		private ColorPicker ColorPicker;

		private Container components = null;

		public SegmentsLedBarEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label7 = new FocusLabel();
			ColorPicker = new ColorPicker();
			ShowOffSegmentsCheckBox = new CheckBox();
			SeperationNumericUpDown = new NumericUpDown();
			label6 = new FocusLabel();
			ThicknessNumericUpDown = new NumericUpDown();
			label8 = new FocusLabel();
			WidthNumericUpDown = new NumericUpDown();
			label9 = new FocusLabel();
			CountsDesiredNumericUpDown = new NumericUpDown();
			label10 = new FocusLabel();
			label2 = new FocusLabel();
			StyleComboBox = new ComboBox();
			((Control)this).SuspendLayout();
			label7.LoadingBegin();
			label7.FocusControl = (Control)(object)ColorPicker;
			((Control)label7).Location = new Point(54, 139);
			((Control)label7).Name = "label7";
			label7.Size = new Size(34, 15);
			label7.Text = "Color";
			label7.UpdateFrameRate = 50.0;
			label7.LoadingEnd();
			((Control)ColorPicker).Location = new Point(88, 136);
			((Control)ColorPicker).Name = "ColorPicker";
			ColorPicker.PropertyName = "Color";
			((Control)ColorPicker).Size = new Size(144, 21);
			((Control)ColorPicker).TabIndex = 5;
			((Control)ShowOffSegmentsCheckBox).Location = new Point(88, 0);
			((Control)ShowOffSegmentsCheckBox).Name = "ShowOffSegmentsCheckBox";
			ShowOffSegmentsCheckBox.PropertyName = "ShowOffSegments";
			((Control)ShowOffSegmentsCheckBox).Size = new Size(136, 24);
			((Control)ShowOffSegmentsCheckBox).TabIndex = 0;
			ShowOffSegmentsCheckBox.Text = "Show Off Segments";
			((Control)SeperationNumericUpDown).Location = new Point(88, 32);
			((Control)SeperationNumericUpDown).Name = "SeperationNumericUpDown";
			SeperationNumericUpDown.PropertyName = "Separation";
			((Control)SeperationNumericUpDown).Size = new Size(48, 20);
			((Control)SeperationNumericUpDown).TabIndex = 1;
			((UpDownBase)SeperationNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)SeperationNumericUpDown;
			((Control)label6).Location = new Point(27, 33);
			((Control)label6).Name = "label6";
			label6.Size = new Size(61, 15);
			label6.Text = "Separation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((Control)ThicknessNumericUpDown).Location = new Point(88, 56);
			((Control)ThicknessNumericUpDown).Name = "ThicknessNumericUpDown";
			ThicknessNumericUpDown.PropertyName = "Thickness";
			((Control)ThicknessNumericUpDown).Size = new Size(48, 20);
			((Control)ThicknessNumericUpDown).TabIndex = 2;
			((UpDownBase)ThicknessNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label8.LoadingBegin();
			label8.FocusControl = (Control)(object)ThicknessNumericUpDown;
			((Control)label8).Location = new Point(31, 57);
			((Control)label8).Name = "label8";
			label8.Size = new Size(57, 15);
			label8.Text = "Thickness";
			label8.UpdateFrameRate = 50.0;
			label8.LoadingEnd();
			((Control)WidthNumericUpDown).Location = new Point(88, 104);
			((Control)WidthNumericUpDown).Name = "WidthNumericUpDown";
			WidthNumericUpDown.PropertyName = "Width";
			((Control)WidthNumericUpDown).Size = new Size(48, 20);
			((Control)WidthNumericUpDown).TabIndex = 4;
			((UpDownBase)WidthNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label9.LoadingBegin();
			label9.FocusControl = (Control)(object)WidthNumericUpDown;
			((Control)label9).Location = new Point(52, 105);
			((Control)label9).Name = "label9";
			label9.Size = new Size(36, 15);
			label9.Text = "Width";
			label9.UpdateFrameRate = 50.0;
			label9.LoadingEnd();
			((Control)CountsDesiredNumericUpDown).Location = new Point(88, 80);
			((NumericUpDown)CountsDesiredNumericUpDown).Maximum = new decimal(new int[4] { 1000, 0, 0, 0 });
			((Control)CountsDesiredNumericUpDown).Name = "CountsDesiredNumericUpDown";
			CountsDesiredNumericUpDown.PropertyName = "CountDesired";
			((Control)CountsDesiredNumericUpDown).Size = new Size(48, 20);
			((Control)CountsDesiredNumericUpDown).TabIndex = 3;
			((UpDownBase)CountsDesiredNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label10.LoadingBegin();
			label10.FocusControl = (Control)(object)CountsDesiredNumericUpDown;
			((Control)label10).Location = new Point(5, 81);
			((Control)label10).Name = "label10";
			label10.Size = new Size(83, 15);
			label10.Text = "Counts Desired";
			label10.UpdateFrameRate = 50.0;
			label10.LoadingEnd();
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)StyleComboBox;
			((Control)label2).Location = new Point(208, 34);
			((Control)label2).Name = "label2";
			label2.Size = new Size(32, 15);
			label2.Text = "Style";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((ComboBox)StyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)StyleComboBox).Location = new Point(240, 32);
			((ComboBox)StyleComboBox).MaxDropDownItems = 20;
			((Control)StyleComboBox).Name = "StyleComboBox";
			StyleComboBox.PropertyName = "Style";
			((Control)StyleComboBox).Size = new Size(144, 21);
			((Control)StyleComboBox).TabIndex = 6;
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)StyleComboBox);
			((Control)this).Controls.Add((Control)(object)CountsDesiredNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label10);
			((Control)this).Controls.Add((Control)(object)WidthNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label9);
			((Control)this).Controls.Add((Control)(object)ThicknessNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label8);
			((Control)this).Controls.Add((Control)(object)SeperationNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)ShowOffSegmentsCheckBox);
			((Control)this).Controls.Add((Control)(object)ColorPicker);
			((Control)this).Controls.Add((Control)(object)label7);
			((Control)this).Location = new Point(10, 20);
			((Control)this).Name = "SegmentsLedBarEditorPlugIn";
			((Control)this).Size = new Size(472, 184);
			base.Title = "Segments Editor";
			((Control)this).ResumeLayout(false);
		}
	}
}
namespace Iocomp.Interfaces
{
	public interface ISegmentsLedSpiral
	{
		Color GetStateColor(Color color, bool value);

		void Draw(PaintArgs p, bool active, float angle1, float angle2, int innerRadius, Color color);
	}
}
namespace Iocomp.Classes
{
	[Description("")]
	[DefaultProperty("Color")]
	public sealed class SegmentsLedSpiral : SubClassBase, ISegmentsLedSpiral
	{
		private int m_Separation;

		private int m_Thickness;

		private int m_Width;

		private bool m_ShowOffSegments;

		private SegmentsLedStyle m_Style;

		private Point[] m_PointArray;

		[Description("Specifies the default color of the segments.")]
		public new Color Color
		{
			get
			{
				return base.Color;
			}
			set
			{
				base.Color = value;
			}
		}

		[Description("Specifies the seperation between each segment in pixels.")]
		public int Separation
		{
			get
			{
				return m_Separation;
			}
			set
			{
				PropertyUpdateDefault("Separation", value);
				if (Separation != value)
				{
					m_Separation = value;
					DoPropertyChange(this, "Separation");
				}
			}
		}

		[Description("Specifies the thickness of each segment in pixels.")]
		public int Thickness
		{
			get
			{
				return m_Thickness;
			}
			set
			{
				PropertyUpdateDefault("Thickness", value);
				if (Thickness != value)
				{
					m_Thickness = value;
					DoPropertyChange(this, "Thickness");
				}
			}
		}

		[Description("Specifies the width of each segments in pixels.")]
		public int Width
		{
			get
			{
				return m_Width;
			}
			set
			{
				PropertyUpdateDefault("Width", value);
				if (Width != value)
				{
					m_Width = value;
					DoPropertyChange(this, "Width");
				}
			}
		}

		[Description("Specifies if the off segments are shown")]
		public bool ShowOffSegments
		{
			get
			{
				return m_ShowOffSegments;
			}
			set
			{
				PropertyUpdateDefault("ShowOffSegments", value);
				if (ShowOffSegments != value)
				{
					m_ShowOffSegments = value;
					DoPropertyChange(this, "ShowOffSegments");
				}
			}
		}

		[Description("Specifies the drawing style of the segments")]
		public SegmentsLedStyle Style
		{
			get
			{
				return m_Style;
			}
			set
			{
				PropertyUpdateDefault("Style", value);
				if (Style != value)
				{
					m_Style = value;
					DoPropertyChange(this, "Style");
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new SegmentsLedSpiralEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Segments Led Spiral";
		}

		void ISegmentsLedSpiral.Draw(PaintArgs p, bool active, float angle1, float angle2, int innerRadius, Color color)
		{
			Draw(p, active, angle1, angle2, innerRadius, color);
		}

		Color ISegmentsLedSpiral.GetStateColor(Color color, bool value)
		{
			return GetStateColor(color, value);
		}

		public SegmentsLedSpiral()
		{
			DoCreate();
		}

		protected override void CreateObjects()
		{
			base.CreateObjects();
			m_PointArray = new Point[4];
		}

		private bool ShouldSerializeColor()
		{
			return PropertyShouldSerialize("Color");
		}

		private void ResetColor()
		{
			PropertyReset("Color");
		}

		private bool ShouldSerializeSeparation()
		{
			return PropertyShouldSerialize("Separation");
		}

		private void ResetSeparation()
		{
			PropertyReset("Separation");
		}

		private bool ShouldSerializeThickness()
		{
			return PropertyShouldSerialize("Thickness");
		}

		private void ResetThickness()
		{
			PropertyReset("Thickness");
		}

		private bool ShouldSerializeWidth()
		{
			return PropertyShouldSerialize("Width");
		}

		private void ResetWidth()
		{
			PropertyReset("Width");
		}

		private bool ShouldSerializeShowOffSegments()
		{
			return PropertyShouldSerialize("ShowOffSegments");
		}

		private void ResetShowOffSegments()
		{
			PropertyReset("ShowOffSegments");
		}

		private bool ShouldSerializeStyle()
		{
			return PropertyShouldSerialize("Style");
		}

		private void ResetStyle()
		{
			PropertyReset("Style");
		}

		private Color GetStateColor(Color color, bool value)
		{
			if (value)
			{
				return color;
			}
			return iColors.ToOffColor(color);
		}

		private void Draw(PaintArgs p, bool active, float angle1, float angle2, int innerRadius, Color color)
		{
			if (active || ShowOffSegments)
			{
				if (Style == SegmentsLedStyle.Flat)
				{
					int num = innerRadius + Width;
					double num2 = Math2.Radians(angle1);
					double num3 = Math2.Radians(angle2);
					ref Point reference = ref m_PointArray[0];
					reference = new Point((int)((double)p.CenterX + Math.Cos(num2) * (double)innerRadius), (int)((double)p.CenterY + Math.Sin(num2) * (double)innerRadius));
					ref Point reference2 = ref m_PointArray[1];
					reference2 = new Point((int)((double)p.CenterX + Math.Cos(num3) * (double)innerRadius), (int)((double)p.CenterY + Math.Sin(num3) * (double)innerRadius));
					ref Point reference3 = ref m_PointArray[2];
					reference3 = new Point((int)((double)p.CenterX + Math.Cos(num3) * (double)num), (int)((double)p.CenterY + Math.Sin(num3) * (double)num));
					ref Point reference4 = ref m_PointArray[3];
					reference4 = new Point((int)((double)p.CenterX + Math.Cos(num2) * (double)num), (int)((double)p.CenterY + Math.Sin(num2) * (double)num));
					p.Graphics.FillPolygon(p.Graphics.Brush(GetStateColor(color, active)), m_PointArray);
				}
				else
				{
					p.Graphics.DrawGradientArc(GetStateColor(color, active), angle1, angle2, p.CenterPoint, innerRadius, Width);
				}
			}
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class SegmentsLedSpiralEditorPlugIn : PlugInStandard
	{
		private FocusLabel label2;

		private ComboBox StyleComboBox;

		private NumericUpDown WidthNumericUpDown;

		private FocusLabel label9;

		private NumericUpDown ThicknessNumericUpDown;

		private FocusLabel label8;

		private NumericUpDown SeperationNumericUpDown;

		private FocusLabel label6;

		private FocusLabel label7;

		private CheckBox ShowOffSegmentsCheckBox;

		private ColorPicker ColorPicker;

		private Container components = null;

		public SegmentsLedSpiralEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label2 = new FocusLabel();
			StyleComboBox = new ComboBox();
			WidthNumericUpDown = new NumericUpDown();
			label9 = new FocusLabel();
			ThicknessNumericUpDown = new NumericUpDown();
			label8 = new FocusLabel();
			SeperationNumericUpDown = new NumericUpDown();
			label6 = new FocusLabel();
			ShowOffSegmentsCheckBox = new CheckBox();
			ColorPicker = new ColorPicker();
			label7 = new FocusLabel();
			((Control)this).SuspendLayout();
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)StyleComboBox;
			((Control)label2).Location = new Point(216, 34);
			((Control)label2).Name = "label2";
			label2.Size = new Size(32, 15);
			label2.Text = "Style";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((ComboBox)StyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)StyleComboBox).Location = new Point(248, 32);
			((ComboBox)StyleComboBox).MaxDropDownItems = 20;
			((Control)StyleComboBox).Name = "StyleComboBox";
			StyleComboBox.PropertyName = "Style";
			((Control)StyleComboBox).Size = new Size(144, 21);
			((Control)StyleComboBox).TabIndex = 5;
			((Control)WidthNumericUpDown).Location = new Point(72, 80);
			((NumericUpDown)WidthNumericUpDown).Maximum = new decimal(new int[4] { 1000, 0, 0, 0 });
			((Control)WidthNumericUpDown).Name = "WidthNumericUpDown";
			WidthNumericUpDown.PropertyName = "Width";
			((Control)WidthNumericUpDown).Size = new Size(48, 20);
			((Control)WidthNumericUpDown).TabIndex = 3;
			((UpDownBase)WidthNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label9.LoadingBegin();
			label9.FocusControl = (Control)(object)WidthNumericUpDown;
			((Control)label9).Location = new Point(36, 81);
			((Control)label9).Name = "label9";
			label9.Size = new Size(36, 15);
			label9.Text = "Width";
			label9.UpdateFrameRate = 50.0;
			label9.LoadingEnd();
			((Control)ThicknessNumericUpDown).Location = new Point(72, 56);
			((NumericUpDown)ThicknessNumericUpDown).Maximum = new decimal(new int[4] { 1000, 0, 0, 0 });
			((Control)ThicknessNumericUpDown).Name = "ThicknessNumericUpDown";
			ThicknessNumericUpDown.PropertyName = "Thickness";
			((Control)ThicknessNumericUpDown).Size = new Size(48, 20);
			((Control)ThicknessNumericUpDown).TabIndex = 2;
			((UpDownBase)ThicknessNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label8.LoadingBegin();
			label8.FocusControl = (Control)(object)ThicknessNumericUpDown;
			((Control)label8).Location = new Point(15, 57);
			((Control)label8).Name = "label8";
			label8.Size = new Size(57, 15);
			label8.Text = "Thickness";
			label8.UpdateFrameRate = 50.0;
			label8.LoadingEnd();
			((Control)SeperationNumericUpDown).Location = new Point(72, 32);
			((Control)SeperationNumericUpDown).Name = "SeperationNumericUpDown";
			SeperationNumericUpDown.PropertyName = "Separation";
			((Control)SeperationNumericUpDown).Size = new Size(48, 20);
			((Control)SeperationNumericUpDown).TabIndex = 1;
			((UpDownBase)SeperationNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)SeperationNumericUpDown;
			((Control)label6).Location = new Point(11, 33);
			((Control)label6).Name = "label6";
			label6.Size = new Size(61, 15);
			label6.Text = "Separation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((Control)ShowOffSegmentsCheckBox).Location = new Point(72, 0);
			((Control)ShowOffSegmentsCheckBox).Name = "ShowOffSegmentsCheckBox";
			ShowOffSegmentsCheckBox.PropertyName = "ShowOffSegments";
			((Control)ShowOffSegmentsCheckBox).Size = new Size(128, 24);
			((Control)ShowOffSegmentsCheckBox).TabIndex = 0;
			ShowOffSegmentsCheckBox.Text = "Show Off Segments";
			((Control)ColorPicker).Location = new Point(72, 112);
			((Control)ColorPicker).Name = "ColorPicker";
			ColorPicker.PropertyName = "Color";
			((Control)ColorPicker).Size = new Size(144, 21);
			((Control)ColorPicker).TabIndex = 4;
			label7.LoadingBegin();
			label7.FocusControl = (Control)(object)ColorPicker;
			((Control)label7).Location = new Point(38, 115);
			((Control)label7).Name = "label7";
			label7.Size = new Size(34, 15);
			label7.Text = "Color";
			label7.UpdateFrameRate = 50.0;
			label7.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)StyleComboBox);
			((Control)this).Controls.Add((Control)(object)WidthNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label9);
			((Control)this).Controls.Add((Control)(object)ThicknessNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label8);
			((Control)this).Controls.Add((Control)(object)SeperationNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)ShowOffSegmentsCheckBox);
			((Control)this).Controls.Add((Control)(object)ColorPicker);
			((Control)this).Controls.Add((Control)(object)label7);
			((Control)this).Location = new Point(10, 20);
			((Control)this).Name = "SegmentsLedSpiralEditorPlugIn";
			((Control)this).Size = new Size(440, 144);
			base.Title = "Segments Editor";
			((Control)this).ResumeLayout(false);
		}
	}
	public class SevenSegmentAnalogDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("Font");
			properties.Remove("ForeColor");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
			properties.Remove("CausesValidation");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("FontChanged");
			events.Remove("ForeColorChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[DefaultProperty("Name")]
	[Description("SevenSegmentAnalog")]
	[DefaultEvent("ValueChanged")]
	[DesignerCategory("code")]
	[Designer(typeof(SevenSegmentAnalogDesigner))]
	[ToolboxBitmap(typeof(Access), "SevenSegmentAnalog.bmp")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	public class SevenSegmentAnalog : SevenSegmentBase
	{
		private ValueDouble m_Value;

		private LeadingStyle m_DigitLeadingStyle;

		private int m_DigitCount;

		private bool m_ShowSign;

		private int m_Precision;

		[Category("Iocomp")]
		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ValueDouble Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsDouble = value.AsDouble;
			}
		}

		[Description("Specifies the style of the leading digit character. The leading character can be a space or zero.")]
		[RefreshProperties(RefreshProperties.All)]
		[Category("Iocomp")]
		public LeadingStyle DigitLeadingStyle
		{
			get
			{
				return m_DigitLeadingStyle;
			}
			set
			{
				PropertyUpdateDefault("DigitLeadingStyle", value);
				if (DigitLeadingStyle != value)
				{
					m_DigitLeadingStyle = value;
					DoPropertyChange(this, "DigitLeadingStyle");
				}
			}
		}

		[Category("Iocomp")]
		[RefreshProperties(RefreshProperties.All)]
		[Description("Specifies the number of digits to display.")]
		public int DigitCount
		{
			get
			{
				return m_DigitCount;
			}
			set
			{
				PropertyUpdateDefault("DigitCount", value);
				if (value < 1 && !base.Loading)
				{
					ThrowStreamingSafeException("DigitCount value must be 1 or greater.");
				}
				if (value < 1)
				{
					value = 1;
				}
				if (DigitCount != value)
				{
					m_DigitCount = value;
					DoPropertyChange(this, "DigitCount");
				}
			}
		}

		[RefreshProperties(RefreshProperties.All)]
		[Description("Specifies if the value's positive or negative sign will be shown.")]
		[Category("Iocomp")]
		public bool ShowSign
		{
			get
			{
				return m_ShowSign;
			}
			set
			{
				PropertyUpdateDefault("ShowSign", value);
				if (ShowSign != value)
				{
					m_ShowSign = value;
					DoPropertyChange(this, "ShowSign");
				}
			}
		}

		[Category("Iocomp")]
		[Description("")]
		[RefreshProperties(RefreshProperties.All)]
		public int Precision
		{
			get
			{
				return m_Precision;
			}
			set
			{
				PropertyUpdateDefault("Precision", value);
				if (value < 0 && !base.Loading)
				{
					ThrowStreamingSafeException("Precsion value must be positive.");
				}
				if (value < 0)
				{
					value = 0;
				}
				if (Precision != value)
				{
					m_Precision = value;
					DoPropertyChange(this, "Precision");
				}
			}
		}

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new SevenSegmentAnalogEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Seven Segment Analog";
		}

		public SevenSegmentAnalog()
		{
			m_License = LicenseManager.Validate(typeof(SevenSegmentAnalog), this);
			DoCreate();
		}

		~SevenSegmentAnalog()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			base.CreateObjects();
			m_Value = new ValueDouble();
			AddSubClass(Value);
			m_Value.Changing += OnValueBeforeChange;
			m_Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			DigitCount = 5;
			DigitLeadingStyle = LeadingStyle.None;
			ShowSign = true;
			Precision = 1;
			base.Outline.Thickness = 3;
			base.Outline.Color = Color.Black;
			base.Segment.ColorOffAuto = true;
			base.Segment.ColorOn = Color.Lime;
			base.Segment.ColorOff = iColors.ToOffColor(Color.Lime);
			base.Segment.Size = 1;
			base.Segment.Separation = 1;
			base.Segment.ShowOffSegments = true;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(108, 31);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			int num = ((!ShowSign) ? DigitCount : (DigitCount + 1));
			Size requiredSize = ((ISegment7)base.Segment).GetRequiredSize(Segment7Character.X0);
			return new Size((requiredSize.Width + base.DigitSpacing + 1) * num - base.DigitSpacing, requiredSize.Height + 1);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == this && propertyName == "DigitCount")
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "DigitSpacing")
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "ShowSign")
			{
				DoAutoSize();
			}
			if (sender == base.Segment && propertyName == "Size")
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeDigitLeadingStyle()
		{
			return PropertyShouldSerialize("DigitLeadingStyle");
		}

		private void ResetDigitLeadingStyle()
		{
			PropertyReset("DigitLeadingStyle");
		}

		private bool ShouldSerializeDigitCount()
		{
			return PropertyShouldSerialize("DigitCount");
		}

		private void ResetDigitCount()
		{
			PropertyReset("DigitCount");
		}

		private bool ShouldSerializeShowSign()
		{
			return PropertyShouldSerialize("ShowSign");
		}

		private void ResetShowSign()
		{
			PropertyReset("ShowSign");
		}

		private bool ShouldSerializePrecision()
		{
			return PropertyShouldSerialize("Precision");
		}

		private void ResetPrecision()
		{
			PropertyReset("Precision");
		}

		private void OnValueChanged(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			p.Graphics.SmoothingMode = (SmoothingMode)4;
			((IOutline)base.Outline).Draw(p, p.DrawRectangle);
			int num = ((!ShowSign) ? DigitCount : (DigitCount + 1));
			bool flag = Convert2.ToString(Math.Abs(Value.AsDouble)).Length > DigitCount;
			int num2 = (p.Width - base.DigitSpacing * (num - 1)) / num;
			int num3 = (p.Width - num * (num2 + base.DigitSpacing) + base.DigitSpacing) / 2;
			string text = Convert2.ToString(m_Precision);
			string text2 = string.Format(CultureInfo.InvariantCulture, "{0:f" + text + "}", new object[1] { Math.Abs(Value.AsDouble) });
			text2 = text2.Replace(".", "");
			while (text2.Length < DigitCount)
			{
				text2 = ((DigitLeadingStyle != LeadingStyle.None) ? ('0' + text2) : (' ' + text2));
			}
			flag = text2.Length > DigitCount;
			iRectangle iRectangle = new iRectangle(p.DrawRectangle);
			iRectangle.Left = p.Left + num3;
			iRectangle.Width = num2;
			if (ShowSign)
			{
				if (Value.AsDouble < 0.0)
				{
					((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar('-'));
				}
				else
				{
					((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar('+'));
				}
				iRectangle.OffsetX(num2 + base.DigitSpacing);
			}
			for (int i = 0; i < DigitCount; i++)
			{
				if (flag)
				{
					if (Value.AsDouble < 0.0)
					{
						((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar('<'));
					}
					else
					{
						((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar('>'));
					}
				}
				else
				{
					((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar(text2[i]));
				}
				iRectangle.OffsetX(num2 + base.DigitSpacing);
			}
			if (Precision > 0 && !flag)
			{
				iRectangle.Width = ((ISegment7)base.Segment).GetRequiredSize(base.Segment.ConvertChar('.')).Width - 1;
				iRectangle.OffsetX(-(num2 + base.DigitSpacing) * Precision);
				iRectangle.OffsetX(-(iRectangle.Width / 2 + base.DigitSpacing / 2));
				((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar('.'));
			}
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class SevenSegmentAnalogEditorPlugIn : PlugInStandard
	{
		private CheckBox AutoSizeCheckBox;

		private NumericUpDown PrecisionNumericUpDown;

		private FocusLabel label3;

		private CheckBox ShowSignCheckBox;

		private GroupBox groupBox2;

		private FocusLabel label5;

		private FocusLabel label7;

		private FocusLabel label8;

		private ComboBox DigitLeadingStyleComboBox;

		private NumericUpDown DigitSpacingNumericUpDown;

		private NumericUpDown DigitCountNumericUpDown;

		private ComboBox RotationComboBox;

		private FocusLabel label6;

		private FocusLabel label1;

		private ColorPicker BackColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public SevenSegmentAnalogEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_002d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0037: Expected O, but got Unknown
			AutoSizeCheckBox = new CheckBox();
			PrecisionNumericUpDown = new NumericUpDown();
			label3 = new FocusLabel();
			ShowSignCheckBox = new CheckBox();
			groupBox2 = new GroupBox();
			DigitLeadingStyleComboBox = new ComboBox();
			DigitSpacingNumericUpDown = new NumericUpDown();
			DigitCountNumericUpDown = new NumericUpDown();
			label5 = new FocusLabel();
			label7 = new FocusLabel();
			label8 = new FocusLabel();
			RotationComboBox = new ComboBox();
			label6 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)groupBox2).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)AutoSizeCheckBox).Location = new Point(264, 176);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 6;
			AutoSizeCheckBox.Text = "Auto Size";
			((Control)PrecisionNumericUpDown).Location = new Point(112, 80);
			((NumericUpDown)PrecisionNumericUpDown).Maximum = new decimal(new int[4] { 0, 0, -2147483648, 0 });
			((Control)PrecisionNumericUpDown).Name = "PrecisionNumericUpDown";
			PrecisionNumericUpDown.PropertyName = "Precision";
			((Control)PrecisionNumericUpDown).Size = new Size(48, 20);
			((Control)PrecisionNumericUpDown).TabIndex = 2;
			((UpDownBase)PrecisionNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)PrecisionNumericUpDown;
			((Control)label3).Location = new Point(59, 81);
			((Control)label3).Name = "label3";
			label3.Size = new Size(53, 15);
			label3.Text = "Precision";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			((Control)ShowSignCheckBox).Location = new Point(112, 48);
			((Control)ShowSignCheckBox).Name = "ShowSignCheckBox";
			ShowSignCheckBox.PropertyName = "ShowSign";
			((Control)ShowSignCheckBox).TabIndex = 1;
			ShowSignCheckBox.Text = "Show Sign";
			((Control)groupBox2).Controls.Add((Control)(object)DigitLeadingStyleComboBox);
			((Control)groupBox2).Controls.Add((Control)(object)DigitSpacingNumericUpDown);
			((Control)groupBox2).Controls.Add((Control)(object)DigitCountNumericUpDown);
			((Control)groupBox2).Controls.Add((Control)(object)label5);
			((Control)groupBox2).Controls.Add((Control)(object)label7);
			((Control)groupBox2).Controls.Add((Control)(object)label8);
			((Control)groupBox2).Location = new Point(264, 8);
			((Control)groupBox2).Name = "groupBox2";
			((Control)groupBox2).Size = new Size(216, 104);
			((Control)groupBox2).TabIndex = 3;
			groupBox2.TabStop = false;
			((Control)groupBox2).Text = "Digit";
			((ComboBox)DigitLeadingStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)DigitLeadingStyleComboBox).Location = new Point(88, 72);
			((Control)DigitLeadingStyleComboBox).Name = "DigitLeadingStyleComboBox";
			DigitLeadingStyleComboBox.PropertyName = "DigitLeadingStyle";
			((Control)DigitLeadingStyleComboBox).Size = new Size(121, 21);
			((Control)DigitLeadingStyleComboBox).TabIndex = 2;
			((Control)DigitSpacingNumericUpDown).Location = new Point(88, 48);
			((Control)DigitSpacingNumericUpDown).Name = "DigitSpacingNumericUpDown";
			DigitSpacingNumericUpDown.PropertyName = "DigitSpacing";
			((Control)DigitSpacingNumericUpDown).Size = new Size(48, 20);
			((Control)DigitSpacingNumericUpDown).TabIndex = 1;
			((UpDownBase)DigitSpacingNumericUpDown).TextAlign = (HorizontalAlignment)2;
			((Control)DigitCountNumericUpDown).Location = new Point(88, 24);
			((Control)DigitCountNumericUpDown).Name = "DigitCountNumericUpDown";
			DigitCountNumericUpDown.PropertyName = "DigitCount";
			((Control)DigitCountNumericUpDown).Size = new Size(48, 20);
			((Control)DigitCountNumericUpDown).TabIndex = 0;
			((UpDownBase)DigitCountNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label5.LoadingBegin();
			label5.FocusControl = (Control)(object)DigitLeadingStyleComboBox;
			((Control)label5).Location = new Point(14, 74);
			((Control)label5).Name = "label5";
			label5.Size = new Size(74, 15);
			label5.Text = "Leading Style";
			label5.UpdateFrameRate = 50.0;
			label5.LoadingEnd();
			label7.LoadingBegin();
			label7.FocusControl = (Control)(object)DigitSpacingNumericUpDown;
			((Control)label7).Location = new Point(41, 49);
			((Control)label7).Name = "label7";
			label7.Size = new Size(47, 15);
			label7.Text = "Spacing";
			label7.UpdateFrameRate = 50.0;
			label7.LoadingEnd();
			label8.LoadingBegin();
			label8.FocusControl = (Control)(object)DigitCountNumericUpDown;
			((Control)label8).Location = new Point(51, 25);
			((Control)label8).Name = "label8";
			label8.Size = new Size(37, 15);
			label8.Text = "Count";
			label8.UpdateFrameRate = 50.0;
			label8.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(112, 176);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 5;
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(63, 178);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(112, 144);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 4;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(51, 147);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(112, 16);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(76, 18);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(152, 210);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(112, 208);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 7;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(8, 210);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)groupBox2);
			((Control)this).Controls.Add((Control)(object)ShowSignCheckBox);
			((Control)this).Controls.Add((Control)(object)PrecisionNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label3);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Name = "SevenSegmentAnalogEditorPlugIn";
			((Control)this).Size = new Size(488, 272);
			base.Title = "Seven-Segment Analog Editor";
			((Control)groupBox2).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueDoubleEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new Segment7EditorPlugIn(), "Segment", sameLevel: false);
			AddSubPlugIn(new OutlineEditorPlugIn(), "Outline", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as SevenSegmentAnalog).Value;
			base.SubPlugIns[1].Value = (base.Value as SevenSegmentAnalog).Segment;
			base.SubPlugIns[2].Value = (base.Value as SevenSegmentAnalog).Outline;
			base.SubPlugIns[3].Value = (base.Value as SevenSegmentAnalog).Border;
		}
	}
	public class SevenSegmentBinaryDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("Font");
			properties.Remove("ForeColor");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
			properties.Remove("CausesValidation");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("FontChanged");
			events.Remove("ForeColorChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[Designer(typeof(SevenSegmentBinaryDesigner))]
	[DesignerCategory("code")]
	[DefaultEvent("ValueChanged")]
	[DefaultProperty("Name")]
	[Description("SevenSegmentBinary")]
	[ToolboxBitmap(typeof(Access), "SevenSegmentBinary.bmp")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	public class SevenSegmentBinary : SevenSegmentBase
	{
		private ValueLong m_Value;

		private LeadingStyle m_DigitLeadingStyle;

		private int m_DigitCount;

		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		public ValueLong Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsLong = value.AsLong;
			}
		}

		[Description("")]
		[Category("Iocomp")]
		public LeadingStyle DigitLeadingStyle
		{
			get
			{
				return m_DigitLeadingStyle;
			}
			set
			{
				PropertyUpdateDefault("DigitLeadingStyle", value);
				if (DigitLeadingStyle != value)
				{
					m_DigitLeadingStyle = value;
					DoPropertyChange(this, "DigitLeadingStyle");
				}
			}
		}

		[Description("")]
		[RefreshProperties(RefreshProperties.All)]
		[Category("Iocomp")]
		public int DigitCount
		{
			get
			{
				return m_DigitCount;
			}
			set
			{
				PropertyUpdateDefault("DigitCount", value);
				if (value < 1 && !base.Loading)
				{
					ThrowStreamingSafeException("DigitCount value must be 1 or greater.");
				}
				if (value < 1)
				{
					value = 1;
				}
				if (DigitCount != value)
				{
					m_DigitCount = value;
					DoPropertyChange(this, "DigitCount");
				}
			}
		}

		[Category("Iocomp")]
		public event ValueLongEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueLongEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new SevenSegmentBinaryEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Seven Segment Binary";
		}

		public SevenSegmentBinary()
		{
			m_License = LicenseManager.Validate(typeof(SevenSegmentBinary), this);
			DoCreate();
		}

		~SevenSegmentBinary()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			base.CreateObjects();
			m_Value = new ValueLong();
			AddSubClass(Value);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			DigitCount = 6;
			DigitLeadingStyle = LeadingStyle.None;
			base.Outline.Thickness = 3;
			base.Outline.Color = Color.Black;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(108, 31);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			Size requiredSize = ((ISegment7)base.Segment).GetRequiredSize(Segment7Character.X0);
			return new Size((requiredSize.Width + base.DigitSpacing + 1) * DigitCount - base.DigitSpacing, requiredSize.Height + 1);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == this && propertyName == "DigitCount")
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "DigitSpacing")
			{
				DoAutoSize();
			}
			if (sender == base.Segment && propertyName == "Size")
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeDigitLeadingStyle()
		{
			return PropertyShouldSerialize("DigitLeadingStyle");
		}

		private void ResetDigitLeadingStyle()
		{
			PropertyReset("DigitLeadingStyle");
		}

		private bool ShouldSerializeDigitCount()
		{
			return PropertyShouldSerialize("DigitCount");
		}

		private void ResetDigitCount()
		{
			PropertyReset("DigitCount");
		}

		private void OnValueChanged(object sender, ValueLongEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueLongEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			p.Graphics.SmoothingMode = (SmoothingMode)4;
			((IOutline)base.Outline).Draw(p, p.DrawRectangle);
			bool flag = Convert2.ToString(Math.Abs(Value.AsLong), 2).Length > DigitCount;
			int num = (p.Width - base.DigitSpacing * (DigitCount - 1)) / DigitCount;
			int num2 = (p.Width - DigitCount * (num + base.DigitSpacing) + base.DigitSpacing) / 2;
			string text = TextFormatInteger.ToString(Value.AsLong, TextFormatIntegerStyle.Binary, DigitCount, DigitLeadingStyle);
			iRectangle iRectangle = new iRectangle(p.DrawRectangle);
			iRectangle.Left = p.Left + num2;
			iRectangle.Width = num;
			for (int i = 0; i < DigitCount; i++)
			{
				if (flag)
				{
					if (Value.AsLong < 0)
					{
						((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar('<'));
					}
					else
					{
						((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar('>'));
					}
				}
				else
				{
					((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar(text[i]));
				}
				iRectangle.OffsetX(num + base.DigitSpacing);
			}
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class SevenSegmentBinaryEditorPlugIn : PlugInStandard
	{
		private CheckBox AutoSizeCheckBox;

		private GroupBox groupBox2;

		private FocusLabel label5;

		private FocusLabel label7;

		private FocusLabel label8;

		private ComboBox DigitLeadingStyleComboBox;

		private NumericUpDown DigitSpacingNumericUpDown;

		private NumericUpDown DigitCountNumericUpDown;

		private ComboBox RotationComboBox;

		private FocusLabel label6;

		private FocusLabel label1;

		private ColorPicker BackColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public SevenSegmentBinaryEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Expected O, but got Unknown
			AutoSizeCheckBox = new CheckBox();
			groupBox2 = new GroupBox();
			DigitLeadingStyleComboBox = new ComboBox();
			DigitSpacingNumericUpDown = new NumericUpDown();
			DigitCountNumericUpDown = new NumericUpDown();
			label5 = new FocusLabel();
			label7 = new FocusLabel();
			label8 = new FocusLabel();
			RotationComboBox = new ComboBox();
			label6 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)groupBox2).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)AutoSizeCheckBox).Location = new Point(264, 168);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 4;
			AutoSizeCheckBox.Text = "Auto Size";
			((Control)groupBox2).Controls.Add((Control)(object)DigitLeadingStyleComboBox);
			((Control)groupBox2).Controls.Add((Control)(object)DigitSpacingNumericUpDown);
			((Control)groupBox2).Controls.Add((Control)(object)DigitCountNumericUpDown);
			((Control)groupBox2).Controls.Add((Control)(object)label5);
			((Control)groupBox2).Controls.Add((Control)(object)label7);
			((Control)groupBox2).Controls.Add((Control)(object)label8);
			((Control)groupBox2).Location = new Point(264, 16);
			((Control)groupBox2).Name = "groupBox2";
			((Control)groupBox2).Size = new Size(216, 104);
			((Control)groupBox2).TabIndex = 1;
			groupBox2.TabStop = false;
			((Control)groupBox2).Text = "Digit";
			((ComboBox)DigitLeadingStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)DigitLeadingStyleComboBox).Location = new Point(88, 72);
			((Control)DigitLeadingStyleComboBox).Name = "DigitLeadingStyleComboBox";
			DigitLeadingStyleComboBox.PropertyName = "DigitLeadingStyle";
			((Control)DigitLeadingStyleComboBox).Size = new Size(121, 21);
			((Control)DigitLeadingStyleComboBox).TabIndex = 2;
			((Control)DigitSpacingNumericUpDown).Location = new Point(88, 48);
			((Control)DigitSpacingNumericUpDown).Name = "DigitSpacingNumericUpDown";
			DigitSpacingNumericUpDown.PropertyName = "DigitSpacing";
			((Control)DigitSpacingNumericUpDown).Size = new Size(48, 20);
			((Control)DigitSpacingNumericUpDown).TabIndex = 1;
			((UpDownBase)DigitSpacingNumericUpDown).TextAlign = (HorizontalAlignment)2;
			((Control)DigitCountNumericUpDown).Location = new Point(88, 24);
			((Control)DigitCountNumericUpDown).Name = "DigitCountNumericUpDown";
			DigitCountNumericUpDown.PropertyName = "DigitCount";
			((Control)DigitCountNumericUpDown).Size = new Size(48, 20);
			((Control)DigitCountNumericUpDown).TabIndex = 0;
			((UpDownBase)DigitCountNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label5.LoadingBegin();
			label5.FocusControl = (Control)(object)DigitLeadingStyleComboBox;
			((Control)label5).Location = new Point(14, 74);
			((Control)label5).Name = "label5";
			label5.Size = new Size(74, 15);
			label5.Text = "Leading Style";
			label5.UpdateFrameRate = 50.0;
			label5.LoadingEnd();
			label7.LoadingBegin();
			label7.FocusControl = (Control)(object)DigitSpacingNumericUpDown;
			((Control)label7).Location = new Point(41, 49);
			((Control)label7).Name = "label7";
			label7.Size = new Size(47, 15);
			label7.Text = "Spacing";
			label7.UpdateFrameRate = 50.0;
			label7.LoadingEnd();
			label8.LoadingBegin();
			label8.FocusControl = (Control)(object)DigitCountNumericUpDown;
			((Control)label8).Location = new Point(51, 25);
			((Control)label8).Name = "label8";
			label8.Size = new Size(37, 15);
			label8.Text = "Count";
			label8.UpdateFrameRate = 50.0;
			label8.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(112, 168);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 3;
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(63, 170);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(112, 136);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 2;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(51, 139);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(112, 16);
			NameTextBox.LongFormat = EditBoxLongFormat.Binary;
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(76, 18);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(152, 202);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(112, 200);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 5;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(8, 202);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)groupBox2);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Name = "SevenSegmentBinaryEditorPlugIn";
			((Control)this).Size = new Size(504, 248);
			base.Title = "Seven-Segment Binary Editor";
			((Control)groupBox2).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueLongEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new Segment7EditorPlugIn(), "Segment", sameLevel: false);
			AddSubPlugIn(new OutlineEditorPlugIn(), "Outline", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as SevenSegmentBinary).Value;
			base.SubPlugIns[1].Value = (base.Value as SevenSegmentBinary).Segment;
			base.SubPlugIns[2].Value = (base.Value as SevenSegmentBinary).Outline;
			base.SubPlugIns[3].Value = (base.Value as SevenSegmentBinary).Border;
		}
	}
	public class SevenSegmentCharacterDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("Font");
			properties.Remove("ForeColor");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
			properties.Remove("CausesValidation");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("FontChanged");
			events.Remove("ForeColorChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[ToolboxBitmap(typeof(Access), "SevenSegmentCharacter.bmp")]
	[DefaultProperty("Name")]
	[DesignerCategory("code")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[DefaultEvent("Click")]
	[Description("SevenSegmentCharacter")]
	[Designer(typeof(SevenSegmentCharacterDesigner))]
	public class SevenSegmentCharacter : ControlBase
	{
		private Segment7 m_Segment;

		private Segment7Character m_Value;

		private Outline m_Outline;

		protected override int SpecialOffset => Outline.Thickness;

		[Category("Iocomp")]
		[Description("Outline properties")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public Outline Outline => m_Outline;

		[Description("Seven Segment properties")]
		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public Segment7 Segment => m_Segment;

		[Category("Iocomp")]
		[Description("Specifies the seven segment character to display.")]
		public Segment7Character Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				PropertyUpdateDefault("Value", value);
				if (Value != value)
				{
					m_Value = value;
					DoPropertyChange(this, "Value");
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new SevenSegmentCharacterEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Seven Segment Character";
		}

		public SevenSegmentCharacter()
		{
			m_License = LicenseManager.Validate(typeof(SevenSegmentCharacter), this);
			DoCreate();
		}

		~SevenSegmentCharacter()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Segment = new Segment7();
			AddSubClass(Segment);
			m_Outline = new Outline();
			AddSubClass(Outline);
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			Value = Segment7Character.X0;
			base.Border.Style = BorderStyleControl.Raised;
			base.Border.ThicknessDesired = 3;
			Outline.Thickness = 3;
			Outline.Color = Color.Black;
			Segment.ColorOffAuto = true;
			Segment.ColorOn = Color.Lime;
			Segment.ColorOff = iColors.ToOffColor(Color.Lime);
			Segment.Size = 1;
			Segment.Separation = 1;
			Segment.ShowOffSegments = true;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(22, 30);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			Size requiredSize = ((ISegment7)Segment).GetRequiredSize(Value);
			return new Size(requiredSize.Width, requiredSize.Height);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == this && propertyName == "Value")
			{
				DoAutoSize();
			}
			if (sender == Segment && propertyName == "Separation")
			{
				DoAutoSize();
			}
			if (sender == Segment && propertyName == "Size")
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeOutline()
		{
			return ((ISubClassBase)Outline).ShouldSerialize();
		}

		private void ResetOutline()
		{
			((ISubClassBase)Outline).ResetToDefault();
		}

		private bool ShouldSerializeSegment()
		{
			return ((ISubClassBase)Segment).ShouldSerialize();
		}

		private void ResetSegment()
		{
			((ISubClassBase)Segment).ResetToDefault();
		}

		private bool ShouldSerializeValue()
		{
			return PropertyShouldSerialize("Value");
		}

		private void ResetValue()
		{
			PropertyReset("Value");
		}

		protected override void DoPaint(PaintArgs p)
		{
			p.Graphics.SmoothingMode = (SmoothingMode)4;
			iRectangle r = new iRectangle(p.DrawRectangle);
			((IOutline)Outline).Draw(p, p.DrawRectangle);
			((ISegment7)Segment).Draw(p, r, Value);
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class SevenSegmentCharacterEditorPlugIn : PlugInStandard
	{
		private CheckBox AutoSizeCheckBox;

		private ComboBox RotationComboBox;

		private FocusLabel label6;

		private ComboBox ValueComboBox;

		private FocusLabel label2;

		private FocusLabel label1;

		private ColorPicker BackColorPicker;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public SevenSegmentCharacterEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			AutoSizeCheckBox = new CheckBox();
			RotationComboBox = new ComboBox();
			label6 = new FocusLabel();
			ValueComboBox = new ComboBox();
			label2 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			((Control)AutoSizeCheckBox).Location = new Point(336, 104);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 3;
			AutoSizeCheckBox.Text = "Auto Size";
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(184, 104);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 2;
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(135, 106);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)ValueComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)ValueComboBox).Location = new Point(184, 8);
			((Control)ValueComboBox).Name = "ValueComboBox";
			ValueComboBox.PropertyName = "Value";
			((Control)ValueComboBox).Size = new Size(136, 21);
			((Control)ValueComboBox).TabIndex = 0;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)ValueComboBox;
			((Control)label2).Location = new Point(148, 10);
			((Control)label2).Name = "label2";
			label2.Size = new Size(36, 15);
			label2.Text = "Value";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(184, 72);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 1;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(123, 75);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(224, 138);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(184, 136);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 4;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(80, 138);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)ValueComboBox);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Name = "SevenSegmentCharacterEditorPlugIn";
			((Control)this).Size = new Size(448, 184);
			base.Title = "Seven-Segment Character Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new Segment7EditorPlugIn(), "Segment", sameLevel: false);
			AddSubPlugIn(new OutlineEditorPlugIn(), "Outline", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as SevenSegmentCharacter).Segment;
			base.SubPlugIns[1].Value = (base.Value as SevenSegmentCharacter).Outline;
			base.SubPlugIns[2].Value = (base.Value as SevenSegmentCharacter).Border;
		}
	}
	public class SevenSegmentClockDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("Font");
			properties.Remove("ForeColor");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
			properties.Remove("CausesValidation");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("FontChanged");
			events.Remove("ForeColorChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[DefaultProperty("Name")]
	[DesignerCategory("code")]
	[Designer(typeof(SevenSegmentClockDesigner))]
	[Description("SevenSegmentClock")]
	[ToolboxBitmap(typeof(Access), "SevenSegmentClock.bmp")]
	[DefaultEvent("ValueChanged")]
	public class SevenSegmentClock : SevenSegmentBase
	{
		private ValueDateTime m_Value;

		private bool m_AutoUpdate;

		private bool m_ShowHours;

		private bool m_ShowMinutes;

		private bool m_ShowSeconds;

		private bool m_ShowMilliseconds;

		private int m_CharCount;

		private int m_ColonCount;

		private ClockHourStyle m_HourStyle;

		private int m_DigitWidth;

		private int m_ColonWidth;

		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		public ValueDateTime Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsDateTime = value.AsDateTime;
			}
		}

		[Category("Iocomp")]
		[Description("Specifies if the hours will be shown.")]
		public bool ShowHours
		{
			get
			{
				return m_ShowHours;
			}
			set
			{
				PropertyUpdateDefault("ShowHours", value);
				if (ShowHours != value)
				{
					m_ShowHours = value;
					DoPropertyChange(this, "ShowHours");
				}
			}
		}

		[Category("Iocomp")]
		[Description("Specifies if the minutes will be shown.")]
		public bool ShowMinutes
		{
			get
			{
				return m_ShowMinutes;
			}
			set
			{
				PropertyUpdateDefault("ShowMinutes", value);
				if (ShowMinutes != value)
				{
					m_ShowMinutes = value;
					DoPropertyChange(this, "ShowMinutes");
				}
			}
		}

		[Category("Iocomp")]
		[Description("Specifies if the seconds will be shown.")]
		public bool ShowSeconds
		{
			get
			{
				return m_ShowSeconds;
			}
			set
			{
				PropertyUpdateDefault("ShowSeconds", value);
				if (ShowSeconds != value)
				{
					m_ShowSeconds = value;
					DoPropertyChange(this, "ShowSeconds");
				}
			}
		}

		[Category("Iocomp")]
		[Description("Specifies if the milliseconds will be shown.")]
		public bool ShowMilliseconds
		{
			get
			{
				return m_ShowMilliseconds;
			}
			set
			{
				PropertyUpdateDefault("ShowMilliseconds", value);
				if (ShowMilliseconds != value)
				{
					m_ShowMilliseconds = value;
					DoPropertyChange(this, "ShowMilliseconds");
				}
			}
		}

		[Description("Specifies the clock hour style.")]
		[Category("Iocomp")]
		public ClockHourStyle HourStyle
		{
			get
			{
				return m_HourStyle;
			}
			set
			{
				PropertyUpdateDefault("HourStyle", value);
				if (HourStyle != value)
				{
					m_HourStyle = value;
					DoPropertyChange(this, "HourStyle");
				}
			}
		}

		[Description("")]
		[RefreshProperties(RefreshProperties.All)]
		[Category("Iocomp")]
		public bool AutoUpdate
		{
			get
			{
				return m_AutoUpdate;
			}
			set
			{
				PropertyUpdateDefault("AutoUpdate", value);
				if (AutoUpdate != value)
				{
					m_AutoUpdate = value;
					DoPropertyChange(this, "AutoUpdate");
					if (m_AutoUpdate)
					{
						AnimationTimerCreate(500);
					}
					else
					{
						AnimationTimerDestroy();
					}
				}
			}
		}

		[Category("Iocomp")]
		public event ValueDateTimeEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueDateTimeEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new SevenSegmentClockEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Seven Segment Clock";
		}

		public SevenSegmentClock()
		{
			m_License = LicenseManager.Validate(typeof(SevenSegmentClock), this);
			DoCreate();
		}

		~SevenSegmentClock()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			base.CreateObjects();
			m_Value = new ValueDateTime();
			AddSubClass(Value);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			AutoUpdate = false;
			ShowHours = true;
			ShowMinutes = true;
			ShowSeconds = true;
			ShowMilliseconds = false;
			HourStyle = ClockHourStyle.Hour12;
			base.Outline.Thickness = 3;
			base.Outline.Color = Color.Black;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(126, 31);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			UpdateCharacterCounts();
			Size requiredSize = ((ISegment7)base.Segment).GetRequiredSize(Segment7Character.X0);
			int width = ((ISegment7)base.Segment).GetRequiredSize(Segment7Character.Colon).Width;
			return new Size((requiredSize.Width + base.DigitSpacing + 1) * m_CharCount + (width + base.DigitSpacing + 1) * m_ColonCount - base.DigitSpacing, requiredSize.Height + 1);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == this && propertyName == "DigitSpacing")
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "ShowHours")
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "ShowMinutes")
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "ShowSeconds")
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "ShowMilliseconds")
			{
				DoAutoSize();
			}
			if (sender == base.Segment && propertyName == "Size")
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeShowHours()
		{
			return PropertyShouldSerialize("ShowHours");
		}

		private void ResetShowHours()
		{
			PropertyReset("ShowHours");
		}

		private bool ShouldSerializeShowMinutes()
		{
			return PropertyShouldSerialize("ShowMinutes");
		}

		private void ResetShowMinutes()
		{
			PropertyReset("ShowMinutes");
		}

		private bool ShouldSerializeShowSeconds()
		{
			return PropertyShouldSerialize("ShowSeconds");
		}

		private void ResetShowSeconds()
		{
			PropertyReset("ShowSeconds");
		}

		private bool ShouldSerializeShowMilliseconds()
		{
			return PropertyShouldSerialize("ShowMilliseconds");
		}

		private void ResetShowMilliseconds()
		{
			PropertyReset("ShowMilliseconds");
		}

		private bool ShouldSerializeHourStyle()
		{
			return PropertyShouldSerialize("HourStyle");
		}

		private void ResetHourStyle()
		{
			PropertyReset("HourStyle");
		}

		private bool ShouldSerializeAutoUpdate()
		{
			return PropertyShouldSerialize("AutoUpdate");
		}

		private void ResetAutoUpdate()
		{
			PropertyReset("AutoUpdate");
		}

		private void UpdateCharacterCounts()
		{
			m_CharCount = 0;
			int num = 0;
			if (ShowHours)
			{
				m_CharCount += 2;
				num++;
			}
			if (ShowMinutes)
			{
				m_CharCount += 2;
				num++;
			}
			if (ShowSeconds)
			{
				m_CharCount += 2;
				num++;
			}
			if (ShowMilliseconds)
			{
				m_CharCount += 3;
			}
			m_ColonCount = num - 1;
			if (m_ColonCount < 0)
			{
				m_ColonCount = 0;
			}
		}

		private void OnValueChanged(object sender, ValueDateTimeEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueDateTimeEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void AnimationTimerHandler(object sender)
		{
			Value.AsDateTime = DateTime.Now;
		}

		private void DrawBlock(PaintArgs p, iRectangle r, ref bool NeedsColon, int Value, int Length, bool NeedsPeriod)
		{
			if (NeedsPeriod)
			{
				Segment7Character character = Segment7Character.Period;
				r.Width = m_ColonWidth;
				r.Left = r.Left - base.DigitSpacing / 2 - r.Width / 2;
				((ISegment7)base.Segment).Draw(p, r, character);
				r.Left = r.Left + base.DigitSpacing / 2 + r.Width / 2;
			}
			else if (NeedsColon)
			{
				Segment7Character character = Segment7Character.Colon;
				r.Width = m_ColonWidth;
				((ISegment7)base.Segment).Draw(p, r, character);
				r.OffsetX(m_ColonWidth + base.DigitSpacing);
			}
			string text = Convert2.ToString(Value);
			while (text.Length < Length)
			{
				text = '0' + text;
			}
			for (int i = 0; i < Length; i++)
			{
				Segment7Character character = base.Segment.ConvertChar(text[i]);
				r.Width = m_DigitWidth;
				((ISegment7)base.Segment).Draw(p, r, character);
				r.OffsetX(m_DigitWidth + base.DigitSpacing);
			}
			NeedsColon = true;
		}

		protected override void DoPaint(PaintArgs p)
		{
			p.Graphics.SmoothingMode = (SmoothingMode)4;
			((IOutline)base.Outline).Draw(p, p.DrawRectangle);
			bool NeedsColon = false;
			UpdateCharacterCounts();
			if (m_CharCount + m_ColonCount != 0)
			{
				int value = ((HourStyle == ClockHourStyle.Hour24) ? Value.AsDateTime.Hour : ((Value.AsDateTime.Hour > 12) ? (Value.AsDateTime.Hour - 12) : ((Value.AsDateTime.Hour != 0) ? Value.AsDateTime.Hour : 12)));
				m_DigitWidth = (5 * p.Width - 5 * base.DigitSpacing * (m_CharCount + m_ColonCount - 1)) / (5 * m_CharCount + m_ColonCount);
				m_ColonWidth = m_DigitWidth / 5;
				int num = (p.Width - m_CharCount * (m_DigitWidth + base.DigitSpacing) - m_ColonCount * (m_ColonWidth + base.DigitSpacing) + base.DigitSpacing) / 2;
				iRectangle iRectangle = new iRectangle(p.DrawRectangle);
				iRectangle.Left = p.Left + num;
				if (ShowHours)
				{
					DrawBlock(p, iRectangle, ref NeedsColon, value, 2, NeedsPeriod: false);
				}
				if (ShowMinutes)
				{
					DrawBlock(p, iRectangle, ref NeedsColon, Value.AsDateTime.Minute, 2, NeedsPeriod: false);
				}
				if (ShowSeconds)
				{
					DrawBlock(p, iRectangle, ref NeedsColon, Value.AsDateTime.Second, 2, NeedsPeriod: false);
				}
				if (ShowMilliseconds)
				{
					DrawBlock(p, iRectangle, ref NeedsColon, Value.AsDateTime.Millisecond, 3, NeedsPeriod: true);
				}
			}
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class SevenSegmentClockEditorPlugIn : PlugInStandard
	{
		private CheckBox AutoSizeCheckBox;

		private FocusLabel label6;

		private ComboBox HourStyleComboBox;

		private GroupBox groupBox3;

		private FocusLabel label2;

		private GroupBox groupBox4;

		private NumericUpDown DigitSpacingNumericUpDown;

		private CheckBox ShowMinutesCheckBox;

		private CheckBox ShowSecondsCheckBox;

		private CheckBox ShowMillisecondsCheckBox;

		private CheckBox ShowHoursCheckBox;

		private ComboBox RotationComboBox;

		private FocusLabel label3;

		private FocusLabel label1;

		private ColorPicker BackColorPicker;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public SevenSegmentClockEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_002c: Expected O, but got Unknown
			//IL_0043: Unknown result type (might be due to invalid IL or missing references)
			//IL_004d: Expected O, but got Unknown
			AutoSizeCheckBox = new CheckBox();
			label6 = new FocusLabel();
			HourStyleComboBox = new ComboBox();
			groupBox3 = new GroupBox();
			DigitSpacingNumericUpDown = new NumericUpDown();
			label2 = new FocusLabel();
			groupBox4 = new GroupBox();
			ShowMinutesCheckBox = new CheckBox();
			ShowSecondsCheckBox = new CheckBox();
			ShowMillisecondsCheckBox = new CheckBox();
			ShowHoursCheckBox = new CheckBox();
			RotationComboBox = new ComboBox();
			label3 = new FocusLabel();
			label1 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)groupBox3).SuspendLayout();
			((Control)groupBox4).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)AutoSizeCheckBox).Location = new Point(288, 216);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 5;
			AutoSizeCheckBox.Text = "Auto Size";
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)HourStyleComboBox;
			((Control)label6).Location = new Point(77, 18);
			((Control)label6).Name = "label6";
			label6.Size = new Size(59, 15);
			label6.Text = "Hour Style";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)HourStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)HourStyleComboBox).Location = new Point(136, 16);
			((Control)HourStyleComboBox).Name = "HourStyleComboBox";
			HourStyleComboBox.PropertyName = "HourStyle";
			((Control)HourStyleComboBox).Size = new Size(121, 21);
			((Control)HourStyleComboBox).TabIndex = 0;
			((Control)groupBox3).Controls.Add((Control)(object)DigitSpacingNumericUpDown);
			((Control)groupBox3).Controls.Add((Control)(object)label2);
			((Control)groupBox3).Location = new Point(136, 64);
			((Control)groupBox3).Name = "groupBox3";
			((Control)groupBox3).Size = new Size(120, 56);
			((Control)groupBox3).TabIndex = 1;
			groupBox3.TabStop = false;
			((Control)groupBox3).Text = "Digit";
			((Control)DigitSpacingNumericUpDown).Location = new Point(64, 24);
			((Control)DigitSpacingNumericUpDown).Name = "DigitSpacingNumericUpDown";
			DigitSpacingNumericUpDown.PropertyName = "DigitSpacing";
			((Control)DigitSpacingNumericUpDown).Size = new Size(48, 20);
			((Control)DigitSpacingNumericUpDown).TabIndex = 0;
			((UpDownBase)DigitSpacingNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)DigitSpacingNumericUpDown;
			((Control)label2).Location = new Point(17, 25);
			((Control)label2).Name = "label2";
			label2.Size = new Size(47, 15);
			label2.Text = "Spacing";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)groupBox4).Controls.Add((Control)(object)ShowMinutesCheckBox);
			((Control)groupBox4).Controls.Add((Control)(object)ShowSecondsCheckBox);
			((Control)groupBox4).Controls.Add((Control)(object)ShowMillisecondsCheckBox);
			((Control)groupBox4).Controls.Add((Control)(object)ShowHoursCheckBox);
			((Control)groupBox4).Location = new Point(288, 8);
			((Control)groupBox4).Name = "groupBox4";
			((Control)groupBox4).Size = new Size(112, 128);
			((Control)groupBox4).TabIndex = 2;
			groupBox4.TabStop = false;
			((Control)groupBox4).Text = "Show";
			((Control)ShowMinutesCheckBox).Location = new Point(16, 48);
			((Control)ShowMinutesCheckBox).Name = "ShowMinutesCheckBox";
			ShowMinutesCheckBox.PropertyName = "ShowMinutes";
			((Control)ShowMinutesCheckBox).Size = new Size(64, 24);
			((Control)ShowMinutesCheckBox).TabIndex = 1;
			ShowMinutesCheckBox.Text = "Minutes";
			((Control)ShowSecondsCheckBox).Location = new Point(16, 72);
			((Control)ShowSecondsCheckBox).Name = "ShowSecondsCheckBox";
			ShowSecondsCheckBox.PropertyName = "ShowSeconds";
			((Control)ShowSecondsCheckBox).Size = new Size(72, 24);
			((Control)ShowSecondsCheckBox).TabIndex = 2;
			ShowSecondsCheckBox.Text = "Seconds";
			((Control)ShowMillisecondsCheckBox).Location = new Point(16, 96);
			((Control)ShowMillisecondsCheckBox).Name = "ShowMillisecondsCheckBox";
			ShowMillisecondsCheckBox.PropertyName = "ShowMilliseconds";
			((Control)ShowMillisecondsCheckBox).Size = new Size(88, 24);
			((Control)ShowMillisecondsCheckBox).TabIndex = 3;
			ShowMillisecondsCheckBox.Text = "Milliseconds";
			((Control)ShowHoursCheckBox).Location = new Point(16, 24);
			((Control)ShowHoursCheckBox).Name = "ShowHoursCheckBox";
			ShowHoursCheckBox.PropertyName = "ShowHours";
			((Control)ShowHoursCheckBox).Size = new Size(60, 24);
			((Control)ShowHoursCheckBox).TabIndex = 0;
			ShowHoursCheckBox.Text = "Hours";
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(136, 216);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 4;
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)RotationComboBox;
			((Control)label3).Location = new Point(87, 218);
			((Control)label3).Name = "label3";
			label3.Size = new Size(49, 15);
			label3.Text = "Rotation";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(75, 187);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(136, 184);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 3;
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(176, 250);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(136, 248);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 6;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(32, 250);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)label3);
			((Control)this).Controls.Add((Control)(object)groupBox4);
			((Control)this).Controls.Add((Control)(object)groupBox3);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)HourStyleComboBox);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Name = "SevenSegmentClockEditorPlugIn";
			((Control)this).Size = new Size(464, 288);
			base.Title = "Seven-Segment Clock Editor";
			((Control)groupBox3).ResumeLayout(false);
			((Control)groupBox4).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueDateTimeEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new Segment7EditorPlugIn(), "Segment", sameLevel: false);
			AddSubPlugIn(new OutlineEditorPlugIn(), "Outline", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as SevenSegmentClock).Value;
			base.SubPlugIns[1].Value = (base.Value as SevenSegmentClock).Segment;
			base.SubPlugIns[2].Value = (base.Value as SevenSegmentClock).Outline;
			base.SubPlugIns[3].Value = (base.Value as SevenSegmentClock).Border;
		}
	}
	public class SevenSegmentHexadecimalDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("Font");
			properties.Remove("ForeColor");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
			properties.Remove("CausesValidation");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("FontChanged");
			events.Remove("ForeColorChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[DefaultProperty("Name")]
	[Description("SevenSegmentHexadecimal")]
	[DesignerCategory("code")]
	[Designer(typeof(SevenSegmentHexadecimalDesigner))]
	[ToolboxBitmap(typeof(Access), "SevenSegmentHexadecimal.bmp")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[DefaultEvent("ValueChanged")]
	public class SevenSegmentHexadecimal : SevenSegmentBase
	{
		private ValueLong m_Value;

		private LeadingStyle m_DigitLeadingStyle;

		private int m_DigitCount;

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		public ValueLong Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsLong = value.AsLong;
			}
		}

		[Category("Iocomp")]
		[Description("Specifies the style of the leading digit character. The leading character can be a space or zero.")]
		public LeadingStyle DigitLeadingStyle
		{
			get
			{
				return m_DigitLeadingStyle;
			}
			set
			{
				PropertyUpdateDefault("DigitLeadingStyle", value);
				if (DigitLeadingStyle != value)
				{
					m_DigitLeadingStyle = value;
					DoPropertyChange(this, "DigitLeadingStyle");
				}
			}
		}

		[Category("Iocomp")]
		[Description("Specifies the number of digits to display.")]
		public int DigitCount
		{
			get
			{
				return m_DigitCount;
			}
			set
			{
				PropertyUpdateDefault("DigitCount", value);
				if (value < 1 && !base.Loading)
				{
					ThrowStreamingSafeException("DigitCount value must be 1 or greater.");
				}
				if (value < 1)
				{
					value = 1;
				}
				if (DigitCount != value)
				{
					m_DigitCount = value;
					DoPropertyChange(this, "DigitCount");
				}
			}
		}

		[Category("Iocomp")]
		public event ValueLongEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueLongEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new SevenSegmentHexadecimalEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Seven Segment Hexadecimal";
		}

		public SevenSegmentHexadecimal()
		{
			m_License = LicenseManager.Validate(typeof(SevenSegmentHexadecimal), this);
			DoCreate();
		}

		~SevenSegmentHexadecimal()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			base.CreateObjects();
			m_Value = new ValueLong();
			AddSubClass(Value);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			DigitCount = 6;
			DigitLeadingStyle = LeadingStyle.None;
			base.Outline.Thickness = 3;
			base.Outline.Color = Color.Black;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(108, 31);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			Size requiredSize = ((ISegment7)base.Segment).GetRequiredSize(Segment7Character.X0);
			return new Size((requiredSize.Width + base.DigitSpacing + 1) * DigitCount - base.DigitSpacing, requiredSize.Height + 1);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == this && propertyName == "DigitSpacing")
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "DigitCount")
			{
				DoAutoSize();
			}
			if (sender == base.Segment && propertyName == "Size")
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeDigitLeadingStyle()
		{
			return PropertyShouldSerialize("DigitLeadingStyle");
		}

		private void ResetDigitLeadingStyle()
		{
			PropertyReset("DigitLeadingStyle");
		}

		private bool ShouldSerializeDigitCount()
		{
			return PropertyShouldSerialize("DigitCount");
		}

		private void ResetDigitCount()
		{
			PropertyReset("DigitCount");
		}

		private void OnValueChanged(object sender, ValueLongEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueLongEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			p.Graphics.SmoothingMode = (SmoothingMode)4;
			((IOutline)base.Outline).Draw(p, p.DrawRectangle);
			bool flag = Convert2.ToString(Math.Abs(Value.AsLong), 16).Length > DigitCount;
			int num = (p.Width - base.DigitSpacing * (DigitCount - 1)) / DigitCount;
			int num2 = (p.Width - DigitCount * (num + base.DigitSpacing) + base.DigitSpacing) / 2;
			string text = TextFormatInteger.ToString(Value.AsLong, TextFormatIntegerStyle.Hexadecimal, DigitCount, DigitLeadingStyle);
			iRectangle iRectangle = new iRectangle(p.DrawRectangle);
			iRectangle.Left = p.Left + num2;
			iRectangle.Width = num;
			for (int i = 0; i < DigitCount; i++)
			{
				if (flag)
				{
					if (Value.AsLong < 0)
					{
						((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar('<'));
					}
					else
					{
						((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar('>'));
					}
				}
				else
				{
					((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar(text[i]));
				}
				iRectangle.OffsetX(num + base.DigitSpacing);
			}
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class SevenSegmentHexadecimalEditorPlugIn : PlugInStandard
	{
		private CheckBox AutoSizeCheckBox;

		private ComboBox DigitLeadingStyleComboBox;

		private NumericUpDown DigitSpacingNumericUpDown;

		private NumericUpDown DigitCountNumericUpDown;

		private FocusLabel label5;

		private FocusLabel label7;

		private FocusLabel label8;

		private ComboBox RotationComboBox;

		private FocusLabel label3;

		private FocusLabel label1;

		private ColorPicker BackColorPicker;

		private GroupBox DigitGroupBox;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public SevenSegmentHexadecimalEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Expected O, but got Unknown
			AutoSizeCheckBox = new CheckBox();
			DigitGroupBox = new GroupBox();
			DigitLeadingStyleComboBox = new ComboBox();
			DigitSpacingNumericUpDown = new NumericUpDown();
			DigitCountNumericUpDown = new NumericUpDown();
			label5 = new FocusLabel();
			label7 = new FocusLabel();
			label8 = new FocusLabel();
			RotationComboBox = new ComboBox();
			label3 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)DigitGroupBox).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)AutoSizeCheckBox).Location = new Point(256, 192);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 4;
			AutoSizeCheckBox.Text = "Auto Size";
			((Control)DigitGroupBox).Controls.Add((Control)(object)DigitLeadingStyleComboBox);
			((Control)DigitGroupBox).Controls.Add((Control)(object)DigitSpacingNumericUpDown);
			((Control)DigitGroupBox).Controls.Add((Control)(object)DigitCountNumericUpDown);
			((Control)DigitGroupBox).Controls.Add((Control)(object)label5);
			((Control)DigitGroupBox).Controls.Add((Control)(object)label7);
			((Control)DigitGroupBox).Controls.Add((Control)(object)label8);
			((Control)DigitGroupBox).Location = new Point(256, 24);
			((Control)DigitGroupBox).Name = "DigitGroupBox";
			((Control)DigitGroupBox).Size = new Size(216, 104);
			((Control)DigitGroupBox).TabIndex = 1;
			DigitGroupBox.TabStop = false;
			((Control)DigitGroupBox).Text = "Digit";
			((ComboBox)DigitLeadingStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)DigitLeadingStyleComboBox).Location = new Point(88, 72);
			((Control)DigitLeadingStyleComboBox).Name = "DigitLeadingStyleComboBox";
			DigitLeadingStyleComboBox.PropertyName = "DigitLeadingStyle";
			((Control)DigitLeadingStyleComboBox).Size = new Size(121, 21);
			((Control)DigitLeadingStyleComboBox).TabIndex = 2;
			((Control)DigitSpacingNumericUpDown).Location = new Point(88, 48);
			((Control)DigitSpacingNumericUpDown).Name = "DigitSpacingNumericUpDown";
			DigitSpacingNumericUpDown.PropertyName = "DigitSpacing";
			((Control)DigitSpacingNumericUpDown).Size = new Size(48, 20);
			((Control)DigitSpacingNumericUpDown).TabIndex = 1;
			((UpDownBase)DigitSpacingNumericUpDown).TextAlign = (HorizontalAlignment)2;
			((Control)DigitCountNumericUpDown).Location = new Point(88, 24);
			((Control)DigitCountNumericUpDown).Name = "DigitCountNumericUpDown";
			DigitCountNumericUpDown.PropertyName = "DigitCount";
			((Control)DigitCountNumericUpDown).Size = new Size(48, 20);
			((Control)DigitCountNumericUpDown).TabIndex = 0;
			((UpDownBase)DigitCountNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label5.LoadingBegin();
			label5.FocusControl = (Control)(object)DigitLeadingStyleComboBox;
			((Control)label5).Location = new Point(14, 74);
			((Control)label5).Name = "label5";
			label5.Size = new Size(74, 15);
			label5.Text = "Leading Style";
			label5.UpdateFrameRate = 50.0;
			label5.LoadingEnd();
			label7.LoadingBegin();
			label7.FocusControl = (Control)(object)DigitSpacingNumericUpDown;
			((Control)label7).Location = new Point(41, 49);
			((Control)label7).Name = "label7";
			label7.Size = new Size(47, 15);
			label7.Text = "Spacing";
			label7.UpdateFrameRate = 50.0;
			label7.LoadingEnd();
			label8.LoadingBegin();
			label8.FocusControl = (Control)(object)DigitCountNumericUpDown;
			((Control)label8).Location = new Point(51, 25);
			((Control)label8).Name = "label8";
			label8.Size = new Size(37, 15);
			label8.Text = "Count";
			label8.UpdateFrameRate = 50.0;
			label8.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(104, 192);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 3;
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)RotationComboBox;
			((Control)label3).Location = new Point(55, 194);
			((Control)label3).Name = "label3";
			label3.Size = new Size(49, 15);
			label3.Text = "Rotation";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(104, 160);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 2;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(43, 163);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(104, 32);
			NameTextBox.LongFormat = EditBoxLongFormat.Hex;
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(68, 34);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(144, 226);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(104, 224);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 5;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(0, 226);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)label3);
			((Control)this).Controls.Add((Control)(object)DigitGroupBox);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Name = "SevenSegmentHexadecimalEditorPlugIn";
			((Control)this).Size = new Size(512, 280);
			base.Title = "Seven-Segment Hexadecimal Editor";
			((Control)DigitGroupBox).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueLongEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new Segment7EditorPlugIn(), "Segment", sameLevel: false);
			AddSubPlugIn(new OutlineEditorPlugIn(), "Outline", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as SevenSegmentHexadecimal).Value;
			base.SubPlugIns[1].Value = (base.Value as SevenSegmentHexadecimal).Segment;
			base.SubPlugIns[2].Value = (base.Value as SevenSegmentHexadecimal).Outline;
			base.SubPlugIns[3].Value = (base.Value as SevenSegmentHexadecimal).Border;
		}
	}
	public class SevenSegmentIntegerDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("Font");
			properties.Remove("ForeColor");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
			properties.Remove("CausesValidation");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("FontChanged");
			events.Remove("ForeColorChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[Designer(typeof(SevenSegmentIntegerDesigner))]
	[DefaultEvent("ValueChanged")]
	[ToolboxBitmap(typeof(Access), "SevenSegmentInteger.bmp")]
	[Description("SevenSegmentInteger")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[DefaultProperty("Name")]
	[DesignerCategory("code")]
	public class SevenSegmentInteger : SevenSegmentBase
	{
		private ValueLong m_Value;

		private LeadingStyle m_DigitLeadingStyle;

		private int m_DigitCount;

		private bool m_ShowSign;

		[Category("Iocomp")]
		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ValueLong Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsLong = value.AsLong;
			}
		}

		[Description("Specifies the style of the leading digit character. The leading character can be a space or zero.")]
		[Category("Iocomp")]
		public LeadingStyle DigitLeadingStyle
		{
			get
			{
				return m_DigitLeadingStyle;
			}
			set
			{
				PropertyUpdateDefault("DigitLeadingStyle", value);
				if (DigitLeadingStyle != value)
				{
					m_DigitLeadingStyle = value;
					DoPropertyChange(this, "DigitLeadingStyle");
				}
			}
		}

		[Description("Specifies the number of digits to display.")]
		[Category("Iocomp")]
		public int DigitCount
		{
			get
			{
				return m_DigitCount;
			}
			set
			{
				PropertyUpdateDefault("DigitCount", value);
				if (value < 1 && !base.Loading)
				{
					ThrowStreamingSafeException("DigitCount value must be 1 or greater.");
				}
				if (value < 1)
				{
					value = 1;
				}
				if (DigitCount != value)
				{
					m_DigitCount = value;
					DoPropertyChange(this, "DigitCount");
				}
			}
		}

		[Category("Iocomp")]
		[Description("Specifies if the value's positive or negative sign will be shown.")]
		public bool ShowSign
		{
			get
			{
				return m_ShowSign;
			}
			set
			{
				PropertyUpdateDefault("ShowSign", value);
				if (ShowSign != value)
				{
					m_ShowSign = value;
					DoPropertyChange(this, "ShowSign");
				}
			}
		}

		[Category("Iocomp")]
		public event ValueLongEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueLongEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new SevenSegmentIntegerEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Seven Segment Integer";
		}

		public SevenSegmentInteger()
		{
			m_License = LicenseManager.Validate(typeof(SevenSegmentInteger), this);
			DoCreate();
		}

		~SevenSegmentInteger()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			base.CreateObjects();
			m_Value = new ValueLong();
			AddSubClass(Value);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			DigitCount = 5;
			DigitLeadingStyle = LeadingStyle.None;
			ShowSign = true;
			base.Outline.Thickness = 3;
			base.Outline.Color = Color.Black;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(108, 31);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			int num = ((!ShowSign) ? DigitCount : (DigitCount + 1));
			Size requiredSize = ((ISegment7)base.Segment).GetRequiredSize(Segment7Character.X0);
			return new Size((requiredSize.Width + base.DigitSpacing + 1) * num - base.DigitSpacing, requiredSize.Height + 1);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == this && propertyName == "DigitSpacing")
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "DigitCount")
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "ShowSign")
			{
				DoAutoSize();
			}
			if (sender == base.Segment && propertyName == "Size")
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeDigitLeadingStyle()
		{
			return PropertyShouldSerialize("DigitLeadingStyle");
		}

		private void ResetDigitLeadingStyle()
		{
			PropertyReset("DigitLeadingStyle");
		}

		private bool ShouldSerializeDigitCount()
		{
			return PropertyShouldSerialize("DigitCount");
		}

		private void ResetDigitCount()
		{
			PropertyReset("DigitCount");
		}

		private bool ShouldSerializeShowSign()
		{
			return PropertyShouldSerialize("ShowSign");
		}

		private void ResetShowSign()
		{
			PropertyReset("ShowSign");
		}

		private void OnValueChanged(object sender, ValueLongEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueLongEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			p.Graphics.SmoothingMode = (SmoothingMode)4;
			((IOutline)base.Outline).Draw(p, p.DrawRectangle);
			int num = ((!ShowSign) ? DigitCount : (DigitCount + 1));
			bool flag = Convert2.ToString(Math.Abs(Value.AsLong), 10).Length > DigitCount;
			int num2 = (p.Width - base.DigitSpacing * (num - 1)) / num;
			int num3 = (p.Width - num * (num2 + base.DigitSpacing) + base.DigitSpacing) / 2;
			string text = TextFormatInteger.ToString(Math.Abs(Value.AsLong), TextFormatIntegerStyle.Integer, DigitCount, DigitLeadingStyle);
			iRectangle iRectangle = new iRectangle(p.DrawRectangle);
			iRectangle.Left = p.Left + num3;
			iRectangle.Width = num2;
			if (ShowSign)
			{
				if (Value.AsLong < 0)
				{
					((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar('-'));
				}
				else
				{
					((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar('+'));
				}
				iRectangle.OffsetX(num2 + base.DigitSpacing);
			}
			for (int i = 0; i < DigitCount; i++)
			{
				if (flag)
				{
					if (Value.AsLong < 0)
					{
						((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar('<'));
					}
					else
					{
						((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar('>'));
					}
				}
				else
				{
					((ISegment7)base.Segment).Draw(p, iRectangle, base.Segment.ConvertChar(text[i]));
				}
				iRectangle.OffsetX(num2 + base.DigitSpacing);
			}
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class SevenSegmentIntegerEditorPlugIn : PlugInStandard
	{
		private CheckBox AutoSizeCheckBox;

		private CheckBox ShowSignCheckBox;

		private GroupBox groupBox2;

		private ComboBox DigitLeadingStyleComboBox;

		private NumericUpDown DigitSpacingNumericUpDown;

		private NumericUpDown DigitCountNumericUpDown;

		private FocusLabel label5;

		private FocusLabel label7;

		private FocusLabel label8;

		private ComboBox RotationComboBox;

		private FocusLabel label3;

		private FocusLabel label1;

		private ColorPicker BackColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public SevenSegmentIntegerEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			AutoSizeCheckBox = new CheckBox();
			ShowSignCheckBox = new CheckBox();
			groupBox2 = new GroupBox();
			DigitLeadingStyleComboBox = new ComboBox();
			DigitSpacingNumericUpDown = new NumericUpDown();
			DigitCountNumericUpDown = new NumericUpDown();
			label5 = new FocusLabel();
			label7 = new FocusLabel();
			label8 = new FocusLabel();
			RotationComboBox = new ComboBox();
			label3 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)groupBox2).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)AutoSizeCheckBox).Location = new Point(256, 192);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 5;
			AutoSizeCheckBox.Text = "Auto Size";
			((Control)ShowSignCheckBox).Location = new Point(104, 56);
			((Control)ShowSignCheckBox).Name = "ShowSignCheckBox";
			ShowSignCheckBox.PropertyName = "ShowSign";
			((Control)ShowSignCheckBox).TabIndex = 1;
			ShowSignCheckBox.Text = "Show Sign";
			((Control)groupBox2).Controls.Add((Control)(object)DigitLeadingStyleComboBox);
			((Control)groupBox2).Controls.Add((Control)(object)DigitSpacingNumericUpDown);
			((Control)groupBox2).Controls.Add((Control)(object)DigitCountNumericUpDown);
			((Control)groupBox2).Controls.Add((Control)(object)label5);
			((Control)groupBox2).Controls.Add((Control)(object)label7);
			((Control)groupBox2).Controls.Add((Control)(object)label8);
			((Control)groupBox2).Location = new Point(264, 16);
			((Control)groupBox2).Name = "groupBox2";
			((Control)groupBox2).Size = new Size(216, 104);
			((Control)groupBox2).TabIndex = 2;
			groupBox2.TabStop = false;
			((Control)groupBox2).Text = "Digit";
			((ComboBox)DigitLeadingStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)DigitLeadingStyleComboBox).Location = new Point(88, 72);
			((Control)DigitLeadingStyleComboBox).Name = "DigitLeadingStyleComboBox";
			DigitLeadingStyleComboBox.PropertyName = "DigitLeadingStyle";
			((Control)DigitLeadingStyleComboBox).Size = new Size(121, 21);
			((Control)DigitLeadingStyleComboBox).TabIndex = 2;
			((Control)DigitSpacingNumericUpDown).Location = new Point(88, 48);
			((Control)DigitSpacingNumericUpDown).Name = "DigitSpacingNumericUpDown";
			DigitSpacingNumericUpDown.PropertyName = "DigitSpacing";
			((Control)DigitSpacingNumericUpDown).Size = new Size(48, 20);
			((Control)DigitSpacingNumericUpDown).TabIndex = 1;
			((UpDownBase)DigitSpacingNumericUpDown).TextAlign = (HorizontalAlignment)2;
			((Control)DigitCountNumericUpDown).Location = new Point(88, 24);
			((Control)DigitCountNumericUpDown).Name = "DigitCountNumericUpDown";
			DigitCountNumericUpDown.PropertyName = "DigitCount";
			((Control)DigitCountNumericUpDown).Size = new Size(48, 20);
			((Control)DigitCountNumericUpDown).TabIndex = 0;
			((UpDownBase)DigitCountNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label5.LoadingBegin();
			label5.FocusControl = (Control)(object)DigitLeadingStyleComboBox;
			((Control)label5).Location = new Point(14, 74);
			((Control)label5).Name = "label5";
			label5.Size = new Size(74, 15);
			label5.Text = "Leading Style";
			label5.UpdateFrameRate = 50.0;
			label5.LoadingEnd();
			label7.LoadingBegin();
			label7.FocusControl = (Control)(object)DigitSpacingNumericUpDown;
			((Control)label7).Location = new Point(41, 49);
			((Control)label7).Name = "label7";
			label7.Size = new Size(47, 15);
			label7.Text = "Spacing";
			label7.UpdateFrameRate = 50.0;
			label7.LoadingEnd();
			label8.LoadingBegin();
			label8.FocusControl = (Control)(object)DigitCountNumericUpDown;
			((Control)label8).Location = new Point(51, 25);
			((Control)label8).Name = "label8";
			label8.Size = new Size(37, 15);
			label8.Text = "Count";
			label8.UpdateFrameRate = 50.0;
			label8.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(104, 192);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 4;
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)RotationComboBox;
			((Control)label3).Location = new Point(55, 194);
			((Control)label3).Name = "label3";
			label3.Size = new Size(49, 15);
			label3.Text = "Rotation";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(104, 160);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 3;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(43, 163);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(104, 24);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(68, 26);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(144, 226);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(104, 224);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 6;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(0, 226);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)label3);
			((Control)this).Controls.Add((Control)(object)groupBox2);
			((Control)this).Controls.Add((Control)(object)ShowSignCheckBox);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Name = "SevenSegmentIntegerEditorPlugIn";
			((Control)this).Size = new Size(504, 256);
			base.Title = "Seven-Segment Integer Editor";
			((Control)groupBox2).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueLongEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new Segment7EditorPlugIn(), "Segment", sameLevel: false);
			AddSubPlugIn(new OutlineEditorPlugIn(), "Outline", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as SevenSegmentInteger).Value;
			base.SubPlugIns[1].Value = (base.Value as SevenSegmentInteger).Segment;
			base.SubPlugIns[2].Value = (base.Value as SevenSegmentInteger).Outline;
			base.SubPlugIns[3].Value = (base.Value as SevenSegmentInteger).Border;
		}
	}
	public class SliderDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[DesignerCategory("code")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[ToolboxBitmap(typeof(Access), "Slider.bmp")]
	[DefaultEvent("ValueChanged")]
	[Designer(typeof(SliderDesigner))]
	[Description("Slider")]
	[DefaultProperty("Name")]
	public class Slider : ControlBase
	{
		private ValueDouble m_Value;

		private ScaleRangeLinear m_ScaleRange;

		private ScaleDisplayLinear m_ScaleDisplay;

		private IScaleDisplayLinear I_Display;

		private PointerSlider m_Pointer;

		private IPointerSlider I_Pointer;

		private UIControlSlider m_UIControl;

		private double m_MouseDownValue;

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("UIControl properties")]
		public UIControlSlider UIControl => m_UIControl;

		[Category("Iocomp")]
		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ValueDouble Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsDouble = value.AsDouble;
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		[Description("Pointer Properties.")]
		public PointerSlider Pointer => m_Pointer;

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		public ScaleRangeLinear ScaleRange => m_ScaleRange;

		[Description("")]
		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ScaleDisplayLinear ScaleDisplay => m_ScaleDisplay;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new SliderEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Slider";
		}

		public Slider()
		{
			m_License = LicenseManager.Validate(typeof(Slider), this);
			DoCreate();
		}

		~Slider()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Value = new ValueDouble();
			AddSubClass(Value);
			m_ScaleRange = new ScaleRangeLinear();
			AddSubClass(ScaleRange);
			m_ScaleDisplay = new ScaleDisplayLinear();
			AddSubClass(ScaleDisplay);
			I_Display = ScaleDisplay;
			m_Pointer = new PointerSlider();
			AddSubClass(Pointer);
			I_Pointer = Pointer;
			m_UIControl = new UIControlSlider();
			AddSubClass(UIControl);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
			I_Display.Range = m_ScaleRange;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			Pointer.Style = PointerStyleSlider.Bar;
			Pointer.Color = Color.Empty;
			Pointer.Width = 22;
			Pointer.Height = 11;
			Pointer.TrackStyle = PointerTrackStyle.Box;
			Pointer.TrackColor = Color.White;
			Pointer.Indicator.ColorActive = Color.Red;
			Pointer.Indicator.ColorInactive = Color.Black;
			Pointer.Indicator.ColorInactiveAuto = false;
			ScaleRange.Span = 100.0;
			ScaleRange.Min = 0.0;
			ScaleRange.Reverse = false;
			ScaleDisplay.GeneratorAuto.DesiredIncrement = 0.0;
			ScaleDisplay.GeneratorAuto.MinTextSpacing = 1.0;
			ScaleDisplay.GeneratorAuto.MinorCount = 4;
			ScaleDisplay.GeneratorAuto.MidIncluded = false;
			ScaleDisplay.GeneratorFixed.MinorCount = 4;
			ScaleDisplay.GeneratorFixed.MidIncluded = false;
			ScaleDisplay.GeneratorFixed.MajorCount = 6;
			ScaleDisplay.AntiAliasEnabled = false;
			ScaleDisplay.GeneratorStyle = ScaleGeneratorStyle.Auto;
			ScaleDisplay.Direction = SideDirection.LeftToRight;
			ScaleDisplay.Margin = 5;
			ScaleDisplay.StartRefValue = 0.0;
			ScaleDisplay.StartRefEnabled = false;
			ScaleDisplay.TextRotation = TextRotation.X000;
			ScaleDisplay.TextAlignment = (StringAlignment)0;
			ScaleDisplay.TextWidthMinValue = 0.0;
			ScaleDisplay.TextWidthMinAuto = false;
			ScaleDisplay.LineInnerVisible = false;
			ScaleDisplay.LineOuterVisible = false;
			ScaleDisplay.Visible = true;
			ScaleDisplay.TextFormatting.Precision = 1;
			ScaleDisplay.TextFormatting.PrecisionStyle = PrecisionStyle.FixedDecimalPoints;
			ScaleDisplay.TextFormatting.UnitsText = "";
			ScaleDisplay.TextFormatting.Style = TextFormatDoubleStyle.Number;
			ScaleDisplay.TextFormatting.DateTimeFormat = "hh:mm:ss";
			ScaleDisplay.TickMinor.Alignment = AlignmentStyle.Near;
			ScaleDisplay.TickMinor.Length = 3;
			ScaleDisplay.TickMinor.Color = Color.Black;
			ScaleDisplay.TickMinor.Thickness = 1;
			ScaleDisplay.TickMid.Length = 5;
			ScaleDisplay.TickMid.Font = null;
			ScaleDisplay.TickMid.ForeColor = Color.Empty;
			ScaleDisplay.TickMid.TextVisible = true;
			ScaleDisplay.TickMid.TextMargin = 2;
			ScaleDisplay.TickMid.Alignment = AlignmentStyle.Near;
			ScaleDisplay.TickMid.Color = Color.Black;
			ScaleDisplay.TickMid.Thickness = 1;
			ScaleDisplay.TickMajor.Length = 7;
			ScaleDisplay.TickMajor.Font = null;
			ScaleDisplay.TickMajor.ForeColor = Color.Empty;
			ScaleDisplay.TickMajor.TextVisible = true;
			ScaleDisplay.TickMajor.TextMargin = 2;
			ScaleDisplay.TickMajor.Color = Color.Black;
			ScaleDisplay.TickMajor.Thickness = 1;
			UIControl.MouseControlStyle = MouseControlStyleSlider.ClickToGoto;
			UIControl.KeyboardEnabled = true;
			UIControl.FocusRectangleShow = true;
			UIControl.MouseWheelEnabled = true;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(65, 203);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			if (base.Loading)
			{
				return Size.Empty;
			}
			Graphics val = ((Control)this).CreateGraphics();
			PaintArgs p = new PaintArgs(val, base.InnerRectangle, Color.Empty);
			I_Display.SetClipEnds(0, innerHeight);
			I_Display.SetBoundsEnds(Pointer.Height / 2, innerHeight - Pointer.Height / 2);
			I_Display.Generate(p);
			val.Dispose();
			SizeF requiredSize = I_Pointer.RequiredSize;
			return new Size(I_Display.MaxDepth + (int)requiredSize.Width, 0);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == ScaleDisplay)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.GeneratorAuto)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.GeneratorFixed)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TickMid)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TickMajor)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TickMinor)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TextFormatting)
			{
				DoAutoSize();
			}
			if (sender == ScaleRange)
			{
				DoAutoSize();
			}
			if (sender == Pointer && propertyName == "Style")
			{
				DoAutoSize();
			}
			if (sender == Pointer && propertyName == "Width")
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "Font")
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeUIControl()
		{
			return ((ISubClassBase)UIControl).ShouldSerialize();
		}

		private void ResetUIControl()
		{
			((ISubClassBase)UIControl).ResetToDefault();
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializePointer()
		{
			return ((ISubClassBase)Pointer).ShouldSerialize();
		}

		private void ResetPointer()
		{
			((ISubClassBase)Pointer).ResetToDefault();
		}

		private bool ShouldSerializeScaleRange()
		{
			return ((ISubClassBase)ScaleRange).ShouldSerialize();
		}

		private void ResetScaleRange()
		{
			((ISubClassBase)ScaleRange).ResetToDefault();
		}

		private bool ShouldSerializeScaleDisplay()
		{
			return ((ISubClassBase)ScaleDisplay).ShouldSerialize();
		}

		private void ResetScaleDisplay()
		{
			((ISubClassBase)ScaleDisplay).ResetToDefault();
		}

		protected override void InternalOnMouseLeft(MouseEventArgs e)
		{
			base.IsMouseDown = true;
			m_MouseDownValue = Value.AsDouble;
			((Control)this).Focus();
			InternalOnMouseMove(e);
		}

		protected override void InternalOnMouseMove(MouseEventArgs e)
		{
			if (!base.IsMouseDown)
			{
				return;
			}
			if (UIControl.MouseControlStyle == MouseControlStyleSlider.Slide)
			{
				double num = (double)(e.Y - base.MouseDownY) / (double)I_Display.PixelsSpan * ScaleRange.Span;
				if (ScaleRange.Reverse)
				{
					Value.AsDouble = ScaleDisplay.ValueClamped(m_MouseDownValue + num);
				}
				else
				{
					Value.AsDouble = ScaleDisplay.ValueClamped(m_MouseDownValue - num);
				}
			}
			else if (UIControl.MouseControlStyle == MouseControlStyleSlider.ClickToGoto)
			{
				Value.AsDouble = ScaleDisplay.ValueClamped(ScaleDisplay.PixelsToValue(e.Y));
			}
		}

		protected override void InternalOnMouseUp(MouseEventArgs e)
		{
			if (base.IsMouseDown)
			{
				base.IsMouseDown = false;
			}
			base.IsMouseDown = false;
		}

		protected override bool IsInputKey(Keys keyData)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0002: Unknown result type (might be due to invalid IL or missing references)
			//IL_0005: Unknown result type (might be due to invalid IL or missing references)
			//IL_002b: Expected I4, but got Unknown
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			return (keyData - 33) switch
			{
				4 => true, 
				6 => true, 
				7 => true, 
				5 => true, 
				0 => true, 
				1 => true, 
				3 => true, 
				2 => true, 
				_ => base.IsInputKey(keyData), 
			};
		}

		protected override void InternalOnKeyDown(KeyEventArgs e)
		{
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Invalid comparison between Unknown and I4
			//IL_0050: Unknown result type (might be due to invalid IL or missing references)
			//IL_0057: Invalid comparison between Unknown and I4
			//IL_0091: Unknown result type (might be due to invalid IL or missing references)
			//IL_0098: Invalid comparison between Unknown and I4
			//IL_00d2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d9: Invalid comparison between Unknown and I4
			//IL_0113: Unknown result type (might be due to invalid IL or missing references)
			//IL_011a: Invalid comparison between Unknown and I4
			//IL_0154: Unknown result type (might be due to invalid IL or missing references)
			//IL_015b: Invalid comparison between Unknown and I4
			//IL_0195: Unknown result type (might be due to invalid IL or missing references)
			//IL_019c: Invalid comparison between Unknown and I4
			//IL_01b5: Unknown result type (might be due to invalid IL or missing references)
			//IL_01bc: Invalid comparison between Unknown and I4
			if (UIControl.KeyboardEnabled)
			{
				if ((int)e.KeyCode == 33)
				{
					Value.AsDouble = ScaleDisplay.ValueClamped(Value.AsDouble + ScaleRange.Span / 10.0);
				}
				if ((int)e.KeyCode == 38)
				{
					Value.AsDouble = ScaleDisplay.ValueClamped(Value.AsDouble + ScaleRange.Span / 100.0);
				}
				if ((int)e.KeyCode == 39)
				{
					Value.AsDouble = ScaleDisplay.ValueClamped(Value.AsDouble + ScaleRange.Span / 100.0);
				}
				if ((int)e.KeyCode == 34)
				{
					Value.AsDouble = ScaleDisplay.ValueClamped(Value.AsDouble - ScaleRange.Span / 10.0);
				}
				if ((int)e.KeyCode == 40)
				{
					Value.AsDouble = ScaleDisplay.ValueClamped(Value.AsDouble - ScaleRange.Span / 100.0);
				}
				if ((int)e.KeyCode == 37)
				{
					Value.AsDouble = ScaleDisplay.ValueClamped(Value.AsDouble - ScaleRange.Span / 100.0);
				}
				if ((int)e.KeyCode == 36)
				{
					Value.AsDouble = ScaleRange.Min;
				}
				if ((int)e.KeyCode == 35)
				{
					Value.AsDouble = ScaleRange.Max;
				}
			}
		}

		protected override void InternalOnMouseWheel(MouseEventArgs e)
		{
			if (UIControl.MouseWheelEnabled)
			{
				if (e.Delta > 0)
				{
					Value.AsDouble = ScaleDisplay.ValueClamped(Value.AsDouble + ScaleRange.Span / 100.0);
				}
				else
				{
					Value.AsDouble = ScaleDisplay.ValueClamped(Value.AsDouble - ScaleRange.Span / 100.0);
				}
			}
		}

		private void OnValueChanged(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			double value = ScaleDisplay.ValueClamped(Value.AsDouble);
			int edgeRef;
			Rectangle rectangle;
			if (ScaleDisplay.Direction == SideDirection.LeftToRight)
			{
				rectangle = new Rectangle(p.Left, p.Top, Pointer.Width, p.Height);
				edgeRef = rectangle.Right;
			}
			else
			{
				rectangle = new Rectangle(p.Right - Pointer.Width, p.Top, Pointer.Width, p.Height);
				edgeRef = rectangle.Left;
			}
			I_Display.SetClipEnds(p.Top, p.Bottom);
			I_Display.SetBoundsEnds(p.Top + Pointer.Height / 2, p.Bottom - Pointer.Height / 2);
			I_Display.EdgeRef = edgeRef;
			I_Display.Generate(p);
			rectangle = Rectangle.FromLTRB(rectangle.Left, I_Display.PixelsLow - Pointer.Height / 2, rectangle.Right, I_Display.PixelsHigh + Pointer.Height / 2);
			I_Display.Draw(p);
			I_Pointer.Draw(p, rectangle, ScaleDisplay.ValueToPixels(value), base.IsMouseDown, ScaleDisplay.Direction);
			if (UIControl.FocusRectangleShow && ((Control)this).Focused)
			{
				p.Graphics.DrawFocusRectangle(p.PenRectangle, base.BackColor);
			}
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class SliderEditorPlugIn : PlugInStandard
	{
		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private CheckBox AutoSizeCheckBox;

		private FocusLabel label1;

		private FocusLabel label4;

		private FontButton FontButton;

		private ColorPicker ForeColorPicker;

		private ColorPicker BackColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public SliderEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			FontButton = new FontButton();
			AutoSizeCheckBox = new CheckBox();
			ForeColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label4 = new FocusLabel();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(71, 106);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(120, 104);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 4;
			((Control)FontButton).Location = new Point(272, 48);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 2;
			((Control)AutoSizeCheckBox).Location = new Point(272, 104);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 5;
			AutoSizeCheckBox.Text = "Auto Size";
			((Control)ForeColorPicker).Location = new Point(120, 48);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(136, 21);
			((Control)ForeColorPicker).TabIndex = 1;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(59, 75);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(120, 72);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 3;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label4).Location = new Point(61, 51);
			((Control)label4).Name = "label4";
			label4.Size = new Size(59, 15);
			label4.Text = "Fore Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(120, 8);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(84, 10);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(160, 138);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(120, 136);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 6;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(16, 138);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Name = "SliderEditorPlugIn";
			((Control)this).Size = new Size(496, 256);
			base.Title = "Slider Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueDoubleEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new PointerSliderEditorPlugIn(), "Pointer", sameLevel: false);
			AddSubPlugIn(new ScaleDisplayLinearEditorPlugIn(), "Scale Display", sameLevel: false);
			AddSubPlugIn(new ScaleRangeLinearEditorPlugIn(), "Scale Range", sameLevel: false);
			AddSubPlugIn(new UIControlSliderEditorPlugIn(), "UI Control", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as Slider).Value;
			base.SubPlugIns[1].Value = (base.Value as Slider).Pointer;
			base.SubPlugIns[2].Value = (base.Value as Slider).ScaleDisplay;
			base.SubPlugIns[3].Value = (base.Value as Slider).ScaleRange;
			base.SubPlugIns[4].Value = (base.Value as Slider).UIControl;
			base.SubPlugIns[5].Value = (base.Value as Slider).Border;
		}
	}
	public class SwitchLedDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[DefaultEvent("ValueChanged")]
	[DefaultProperty("Name")]
	[DesignerCategory("code")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[Description("Iocomp SwitchLed")]
	[Designer(typeof(SwitchLedDesigner))]
	[ToolboxBitmap(typeof(Access), "SwitchLed.bmp")]
	public class SwitchLed : ControlBase
	{
		private ValueBoolean m_Value;

		private string m_Text;

		private SwitchMomentaryStyle m_MomentaryStyle;

		private IndicatorSwitchLed m_Indicator;

		private UIControlSwitchLed m_UIControl;

		private TextLayoutFull m_TextLayout;

		private bool m_ShowDown;

		private int m_BorderThickness;

		protected override int SpecialOffset => BorderThickness;

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("Value Properties")]
		public ValueBoolean Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsBoolean = value.AsBoolean;
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		[Description("UIControl")]
		public UIControlSwitchLed UIControl => m_UIControl;

		[Description("Indicator")]
		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public IndicatorSwitchLed Indicator => m_Indicator;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("TextLayout")]
		[Category("Iocomp")]
		public TextLayoutFull TextLayout => m_TextLayout;

		[Category("Iocomp")]
		[RefreshProperties(RefreshProperties.All)]
		[Description("Specifies the text for the label.")]
		public override string Text
		{
			get
			{
				return m_Text;
			}
			set
			{
				PropertyUpdateDefault("Text", value);
				if (((Control)this).Text != value)
				{
					m_Text = value;
					DoPropertyChange(this, "Text");
					((Control)this).OnTextChanged(EventArgs.Empty);
				}
			}
		}

		[RefreshProperties(RefreshProperties.All)]
		[Category("Iocomp")]
		[Description("Determines the border thickness amount.")]
		public int BorderThickness
		{
			get
			{
				return m_BorderThickness;
			}
			set
			{
				PropertyUpdateDefault("BorderThickness", value);
				if (BorderThickness != value)
				{
					int borderThickness = m_BorderThickness;
					m_BorderThickness = value;
					DoAutoSizeSpecialOffset(m_BorderThickness - borderThickness);
					DoPropertyChange(this, "BorderThickness");
				}
			}
		}

		[Description("")]
		[Category("Iocomp")]
		public SwitchMomentaryStyle MomentaryStyle
		{
			get
			{
				return m_MomentaryStyle;
			}
			set
			{
				PropertyUpdateDefault("MomentaryStyle", value);
				if (MomentaryStyle != value)
				{
					m_MomentaryStyle = value;
					DoPropertyChange(this, "MomentaryStyle");
				}
			}
		}

		[Category("Iocomp")]
		public event ValueBooleanEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueBooleanEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new SwitchLedEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Switch Led";
		}

		public SwitchLed()
		{
			m_License = LicenseManager.Validate(typeof(SwitchLed), this);
			DoCreate();
		}

		~SwitchLed()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Value = new ValueBoolean();
			AddSubClass(Value);
			m_Indicator = new IndicatorSwitchLed();
			AddSubClass(Indicator);
			m_TextLayout = new TextLayoutFull();
			AddSubClass(TextLayout);
			m_UIControl = new UIControlSwitchLed();
			AddSubClass(UIControl);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetComponentDefaults()
		{
			((Control)this).Text = "ON";
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			((Control)this).Text = "ON";
			MomentaryStyle = SwitchMomentaryStyle.None;
			Indicator.Alignment = AlignmentQuadSide.Bottom;
			Indicator.Height = 20;
			Indicator.MarginOffset = 3;
			Indicator.MarginSides = 3;
			Indicator.ColorInactiveAuto = true;
			Indicator.ColorActive = Color.Lime;
			Indicator.ColorInactive = iColors.ToOffColor(Color.Lime);
			BorderThickness = 5;
			base.Border.Style = BorderStyleControl.None;
			TextLayout.AlignmentVertical.Style = (StringAlignment)1;
			TextLayout.AlignmentVertical.Margin = 0.25;
			TextLayout.AlignmentHorizontal.Style = (StringAlignment)1;
			TextLayout.AlignmentHorizontal.Margin = 0.25;
			TextLayout.Trimming = (StringTrimming)0;
			TextLayout.LineLimit = false;
			TextLayout.MeasureTrailingSpaces = false;
			TextLayout.NoWrap = false;
			TextLayout.NoClip = false;
			UIControl.MouseWheelEnabled = true;
			UIControl.KeyboardEnabled = true;
			UIControl.FocusRectangleShow = true;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(48, 40);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeUIControl()
		{
			return ((ISubClassBase)UIControl).ShouldSerialize();
		}

		private void ResetUIControl()
		{
			((ISubClassBase)UIControl).ResetToDefault();
		}

		private bool ShouldSerializeIndicator()
		{
			return ((ISubClassBase)Indicator).ShouldSerialize();
		}

		private void ResetIndicator()
		{
			((ISubClassBase)Indicator).ResetToDefault();
		}

		private bool ShouldSerializeTextLayout()
		{
			return ((ISubClassBase)TextLayout).ShouldSerialize();
		}

		private void ResetTextLayout()
		{
			((ISubClassBase)TextLayout).ResetToDefault();
		}

		public bool ShouldSerializeText()
		{
			return PropertyShouldSerialize("Text");
		}

		public void ResetText()
		{
			PropertyReset("Text");
		}

		private bool ShouldSerializeBorderThickness()
		{
			return PropertyShouldSerialize("BorderThickness");
		}

		private void ResetBorderThickness()
		{
			PropertyReset("BorderThickness");
		}

		private bool ShouldSerializeMomentaryStyle()
		{
			return PropertyShouldSerialize("MomentaryStyle");
		}

		private void ResetMomentaryStyle()
		{
			PropertyReset("MomentaryStyle");
		}

		private void OnValueChanged(object sender, ValueBooleanEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueBooleanEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void InternalOnMouseLeft(MouseEventArgs e)
		{
			Rectangle innerRectangle = base.InnerRectangle;
			innerRectangle.Inflate(BorderThickness, BorderThickness);
			if (innerRectangle.Contains(e.X, e.Y))
			{
				base.IsMouseDown = true;
			}
			((Control)this).Focus();
			if (MomentaryStyle == SwitchMomentaryStyle.Simple)
			{
				Value.AsBoolean = true;
			}
		}

		protected override void InternalOnMouseUp(MouseEventArgs e)
		{
			if (!base.IsMouseDown)
			{
				return;
			}
			base.IsMouseDown = false;
			Rectangle innerRectangle = base.InnerRectangle;
			innerRectangle.Inflate(BorderThickness, BorderThickness);
			if (MomentaryStyle == SwitchMomentaryStyle.None)
			{
				if (innerRectangle.Contains(e.X, e.Y))
				{
					Value.AsBoolean = !Value.AsBoolean;
				}
			}
			else if (MomentaryStyle == SwitchMomentaryStyle.Simple)
			{
				Value.AsBoolean = false;
			}
		}

		protected override void InternalOnMouseWheel(MouseEventArgs e)
		{
			if (UIControl.MouseWheelEnabled)
			{
				if (e.Delta > 0 && !Value.AsBoolean)
				{
					m_ShowDown = true;
					Value.AsBoolean = true;
					AnimationTimerCreate(100);
				}
				else if (e.Delta < 0 && Value.AsBoolean)
				{
					m_ShowDown = true;
					Value.AsBoolean = false;
					AnimationTimerCreate(100);
				}
			}
		}

		protected override void InternalOnKeyDown(KeyEventArgs e)
		{
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Invalid comparison between Unknown and I4
			if (UIControl.KeyboardEnabled && (int)e.KeyCode == 32)
			{
				base.IsKeyDown = true;
				base.IsMouseDown = false;
			}
		}

		protected override void InternalOnKeyUp(KeyEventArgs e)
		{
			//IL_0026: Unknown result type (might be due to invalid IL or missing references)
			//IL_002d: Invalid comparison between Unknown and I4
			if (UIControl.KeyboardEnabled && base.IsKeyDown)
			{
				base.IsKeyDown = false;
				base.IsMouseDown = false;
				if ((int)e.KeyCode == 32)
				{
					Value.AsBoolean = !Value.AsBoolean;
				}
			}
		}

		protected override void AnimationTimerHandler(object sender)
		{
			m_ShowDown = false;
			base.AnimationTimerHandler(sender);
		}

		private int GetIndicatorPixelHeight()
		{
			return (int)Math.Round((double)(base.InnerRectangle.Height * Indicator.Height) / 100.0);
		}

		private Rectangle CalcIndicatorRect(bool switchActive, Rectangle innerRectangle)
		{
			int indicatorPixelHeight = GetIndicatorPixelHeight();
			Rectangle result = ((Indicator.Alignment == AlignmentQuadSide.Left) ? new Rectangle(innerRectangle.Left + Indicator.MarginOffset, innerRectangle.Top + Indicator.MarginSides, indicatorPixelHeight, innerRectangle.Height - 2 * Indicator.MarginSides) : ((Indicator.Alignment == AlignmentQuadSide.Top) ? new Rectangle(innerRectangle.Left + Indicator.MarginSides, innerRectangle.Top + Indicator.MarginOffset, innerRectangle.Width - 2 * Indicator.MarginSides, indicatorPixelHeight) : ((Indicator.Alignment != AlignmentQuadSide.Bottom) ? new Rectangle(innerRectangle.Right - Indicator.MarginOffset - indicatorPixelHeight, innerRectangle.Top + Indicator.MarginSides, indicatorPixelHeight, innerRectangle.Height - 2 * Indicator.MarginSides) : new Rectangle(innerRectangle.Left + Indicator.MarginSides, innerRectangle.Bottom - Indicator.MarginOffset - indicatorPixelHeight, innerRectangle.Width - 2 * Indicator.MarginSides, indicatorPixelHeight))));
			if (switchActive)
			{
				result.Offset(1, 1);
			}
			return result;
		}

		private Rectangle CalcTextRect(bool switchActive, Rectangle indicatorRectangle, PaintArgs p)
		{
			Rectangle result = ((Indicator.Alignment == AlignmentQuadSide.Left) ? Rectangle.FromLTRB(indicatorRectangle.Right, indicatorRectangle.Top, p.Right, p.Bottom) : ((Indicator.Alignment == AlignmentQuadSide.Top) ? Rectangle.FromLTRB(p.Left, indicatorRectangle.Bottom, p.Right, p.Bottom) : ((Indicator.Alignment != AlignmentQuadSide.Bottom) ? Rectangle.FromLTRB(p.Left, p.Top, indicatorRectangle.Left, p.Bottom) : Rectangle.FromLTRB(p.Left, p.Top, p.Right, indicatorRectangle.Top))));
			if (switchActive)
			{
				result.Offset(1, 1);
			}
			return result;
		}

		protected override void DoPaint(PaintArgs p)
		{
			bool switchActive;
			BorderStyleControl style;
			if (base.IsDown || m_ShowDown)
			{
				switchActive = true;
				style = BorderStyleControl.Sunken;
			}
			else
			{
				switchActive = false;
				style = BorderStyleControl.Raised;
			}
			Rectangle rectangle = CalcIndicatorRect(switchActive, p.DrawRectangle);
			Rectangle r = CalcTextRect(switchActive, rectangle, p);
			((ITextLayoutBase)TextLayout).Draw(p.Graphics, base.Font, p.Graphics.Brush(base.ForeColor), ((Control)this).Text, r);
			Color stateColor = Indicator.GetStateColor(Value.AsBoolean);
			p.Graphics.FillRectangle(p.Graphics.Brush(stateColor), rectangle);
			BorderSimple.Draw(p, rectangle, BorderStyleSimple.SunkenOuter, base.BackColor);
			if (UIControl.FocusRectangleShow && ((Control)this).Focused)
			{
				Rectangle r2 = new Rectangle(p.DrawRectangle.Left, p.DrawRectangle.Top, p.DrawRectangle.Width - 1, p.DrawRectangle.Height - 1);
				r2.Inflate(-1, -1);
				p.Graphics.DrawFocusRectangle(r2, base.BackColor);
			}
			Rectangle drawRectangle = p.DrawRectangle;
			drawRectangle.Inflate(BorderThickness, BorderThickness);
			((IBorderControl)base.Border).Draw(p, drawRectangle, style, BorderThickness, base.BackColor);
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class SwitchLedEditorPlugIn : PlugInStandard
	{
		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private NumericUpDown BorderThicknessNumericUpDown;

		private FocusLabel label4;

		private FocusLabel label3;

		private FocusLabel label1;

		private FocusLabel label2;

		private CheckBox AutoSizeCheckBox;

		private FontButton FontButton;

		private ColorPicker ForeColorPicker;

		private ColorPicker BackColorPicker;

		private EditBox TextBox;

		private CheckBox ValueCheckBox;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public SwitchLedEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			BorderThicknessNumericUpDown = new NumericUpDown();
			label4 = new FocusLabel();
			TextBox = new EditBox();
			label3 = new FocusLabel();
			FontButton = new FontButton();
			ForeColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label2 = new FocusLabel();
			AutoSizeCheckBox = new CheckBox();
			ValueCheckBox = new CheckBox();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(119, 194);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(168, 192);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 6;
			((Control)BorderThicknessNumericUpDown).Location = new Point(256, 80);
			((NumericUpDown)BorderThicknessNumericUpDown).Maximum = new decimal(new int[4] { 0, 0, -2147483648, 0 });
			((Control)BorderThicknessNumericUpDown).Name = "BorderThicknessNumericUpDown";
			BorderThicknessNumericUpDown.PropertyName = "BorderThickness";
			((Control)BorderThicknessNumericUpDown).Size = new Size(48, 20);
			((Control)BorderThicknessNumericUpDown).TabIndex = 2;
			((UpDownBase)BorderThicknessNumericUpDown).TextAlign = (HorizontalAlignment)2;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)BorderThicknessNumericUpDown;
			((Control)label4).Location = new Point(163, 81);
			((Control)label4).Name = "label4";
			label4.Size = new Size(93, 15);
			label4.Text = "Border Thickness";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			TextBox.LoadingBegin();
			((Control)TextBox).Location = new Point(168, 48);
			((Control)TextBox).Name = "TextBox";
			TextBox.PropertyName = "Text";
			TextBox.Size = new Size(136, 20);
			((Control)TextBox).TabIndex = 1;
			TextBox.LoadingEnd();
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)TextBox;
			((Control)label3).Location = new Point(139, 50);
			((Control)label3).Name = "label3";
			label3.Size = new Size(29, 15);
			label3.Text = "Text";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			((Control)FontButton).Location = new Point(320, 136);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 4;
			((Control)ForeColorPicker).Location = new Point(168, 136);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(136, 21);
			((Control)ForeColorPicker).TabIndex = 3;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(107, 163);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(168, 160);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 5;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label2).Location = new Point(109, 139);
			((Control)label2).Name = "label2";
			label2.Size = new Size(59, 15);
			label2.Text = "Fore Color";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)AutoSizeCheckBox).Location = new Point(320, 192);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 7;
			AutoSizeCheckBox.Text = "Auto Size";
			((Control)ValueCheckBox).Location = new Point(168, 16);
			((Control)ValueCheckBox).Name = "ValueCheckBox";
			ValueCheckBox.PropertyName = "Value";
			((Control)ValueCheckBox).TabIndex = 0;
			ValueCheckBox.Text = "Value";
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(208, 226);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(168, 224);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 8;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(64, 226);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)ValueCheckBox);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)label3);
			((Control)this).Controls.Add((Control)(object)TextBox);
			((Control)this).Controls.Add((Control)(object)BorderThicknessNumericUpDown);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Name = "SwitchLedEditorPlugIn";
			((Control)this).Size = new Size(472, 280);
			base.Title = "Switch Led Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueBooleanEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new IndicatorSwitchLedEditorPlugIn(), "Indicator", sameLevel: false);
			AddSubPlugIn(new TextLayoutFullEditorPlugin(), "Text Layout", sameLevel: false);
			AddSubPlugIn(new UIControlSwitchLedEditorPlugIn(), "UI Control", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as SwitchLed).Value;
			base.SubPlugIns[1].Value = (base.Value as SwitchLed).Indicator;
			base.SubPlugIns[2].Value = (base.Value as SwitchLed).TextLayout;
			base.SubPlugIns[3].Value = (base.Value as SwitchLed).UIControl;
			base.SubPlugIns[4].Value = (base.Value as SwitchLed).Border;
		}
	}
	public class SwitchPanelDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[Description("SwitchPanel")]
	[DefaultEvent("ValueChanged")]
	[DefaultProperty("Name")]
	[ToolboxBitmap(typeof(Access), "SwitchPanel.bmp")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[DesignerCategory("code")]
	[Designer(typeof(SwitchPanelDesigner))]
	public class SwitchPanel : ControlBase
	{
		private SwitchPanelPanel m_Panel;

		private PointerSwitchPanel m_Pointer;

		private UIControlSwitchPanel m_UIControl;

		private ValueInteger m_Value;

		private float m_AAngleDelta;

		private Point m_PointerCenterPoint;

		private float m_MouseDownAngle;

		[Category("Iocomp")]
		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ValueInteger Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsInteger = value.AsInteger;
			}
		}

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		public SwitchPanelPanel Panel => m_Panel;

		[Category("Iocomp")]
		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public PointerSwitchPanel Pointer => m_Pointer;

		[Category("Iocomp")]
		[Description("UIControl properties")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public UIControlSwitchPanel UIControl => m_UIControl;

		[Category("Iocomp")]
		public event ValueIntegerEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueIntegerEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new SwitchPanelEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Switch Panel";
		}

		public SwitchPanel()
		{
			m_License = LicenseManager.Validate(typeof(SwitchPanel), this);
			DoCreate();
		}

		~SwitchPanel()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Value = new ValueInteger();
			AddSubClass(Value);
			m_Panel = new SwitchPanelPanel();
			AddSubClass(Panel);
			m_Pointer = new PointerSwitchPanel();
			AddSubClass(Pointer);
			m_UIControl = new UIControlSwitchPanel();
			AddSubClass(UIControl);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			Panel.PositionText1 = "On";
			Panel.PositionText2 = "Off";
			Panel.PositionText3 = "Auto";
			Panel.PositionCount = 3;
			Panel.BackColor = Color.Black;
			Panel.ForeColorActive = Color.Aqua;
			Panel.ForeColorInactive = Color.White;
			Panel.FontActive = null;
			Panel.FontInactive = null;
			Panel.MarginTop = 0.25;
			Panel.MarginRow = 0.25;
			Panel.MarginCol = 2.0;
			Panel.MarginBottom = 0.25;
			Panel.MarginSides = 2.0;
			Panel.DrawOutline = true;
			Pointer.EdgeWidth = 6;
			Pointer.HandleWidth = 8;
			Pointer.Margin = 8;
			Pointer.EdgeColor = Color.WhiteSmoke;
			Pointer.BackColor = Color.Gray;
			Pointer.HandleColor = Color.Yellow;
			UIControl.MouseControlStyle = MouseControlStyleSwitchPanel.All;
			UIControl.KeyboardEnabled = true;
			UIControl.FocusRectangleShow = true;
			UIControl.MouseWheelEnabled = true;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(96, 133);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			if (base.Loading)
			{
				return Size.Empty;
			}
			Graphics val = ((Control)this).CreateGraphics();
			PaintArgs p = new PaintArgs(val, base.InnerRectangle, Color.Empty);
			Size requiredSize = Panel.GetRequiredSize(p);
			val.Dispose();
			return new Size(requiredSize.Width, requiredSize.Height + requiredSize.Width);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == Panel)
			{
				DoAutoSize();
			}
			if (sender == Pointer)
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "Font")
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializePanel()
		{
			return ((ISubClassBase)Panel).ShouldSerialize();
		}

		private void ResetPanel()
		{
			((ISubClassBase)Panel).ResetToDefault();
		}

		private bool ShouldSerializePointer()
		{
			return ((ISubClassBase)Pointer).ShouldSerialize();
		}

		private void ResetPointer()
		{
			((ISubClassBase)Pointer).ResetToDefault();
		}

		private bool ShouldSerializeUIControl()
		{
			return ((ISubClassBase)UIControl).ShouldSerialize();
		}

		private void ResetUIControl()
		{
			((ISubClassBase)UIControl).ResetToDefault();
		}

		private float GetMouseAngle(MouseEventArgs e)
		{
			return 90f - (float)Math2.ToAngle(Math.Atan2(m_PointerCenterPoint.Y - e.X, e.X - m_PointerCenterPoint.X));
		}

		protected override void InternalOnMouseLeft(MouseEventArgs e)
		{
			base.IsMouseDown = true;
			((Control)this).Focus();
			m_MouseDownAngle = GetMouseAngle(e);
			if (UIControl.MouseControlStyle == MouseControlStyleSwitchPanel.ClickLabel || UIControl.MouseControlStyle == MouseControlStyleSwitchPanel.All)
			{
				if (Panel.PositionClickRect1.Contains(e.X, e.Y))
				{
					Value.AsInteger = 0;
				}
				else if (Panel.PositionClickRect2.Contains(e.X, e.Y))
				{
					Value.AsInteger = 1;
				}
				else if (Panel.PositionCount == 3 && Panel.PositionClickRect3.Contains(e.X, e.Y))
				{
					Value.AsInteger = 2;
				}
			}
			InternalOnMouseMove(e);
		}

		protected override void InternalOnMouseMove(MouseEventArgs e)
		{
			if (base.IsMouseDown && UIControl.MouseControlStyle != MouseControlStyleSwitchPanel.ClickLabel)
			{
				float mouseAngle = GetMouseAngle(e);
				float num = mouseAngle - m_MouseDownAngle;
				if (num > 30f)
				{
					ChangeIndex(Value.AsInteger + 1);
					m_MouseDownAngle = mouseAngle;
				}
				else if (num < -30f)
				{
					ChangeIndex(Value.AsInteger - 1);
					m_MouseDownAngle = mouseAngle;
				}
			}
		}

		protected override void InternalOnMouseUp(MouseEventArgs e)
		{
			base.IsMouseDown = false;
		}

		protected override bool IsInputKey(Keys keyData)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0002: Unknown result type (might be due to invalid IL or missing references)
			//IL_0005: Unknown result type (might be due to invalid IL or missing references)
			//IL_002b: Expected I4, but got Unknown
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			return (keyData - 33) switch
			{
				4 => true, 
				6 => true, 
				7 => true, 
				5 => true, 
				0 => true, 
				1 => true, 
				3 => true, 
				2 => true, 
				_ => base.IsInputKey(keyData), 
			};
		}

		private void ChangeIndex(int value)
		{
			int num = ((Panel.PositionCount == 2) ? 1 : 2);
			if (value < 0)
			{
				value = 0;
			}
			if (value >= num)
			{
				value = num;
			}
			Value.AsInteger = value;
		}

		protected override void InternalOnKeyDown(KeyEventArgs e)
		{
			//IL_001b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0022: Invalid comparison between Unknown and I4
			//IL_002b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0032: Invalid comparison between Unknown and I4
			//IL_003b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0042: Invalid comparison between Unknown and I4
			//IL_004b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0052: Invalid comparison between Unknown and I4
			//IL_0059: Unknown result type (might be due to invalid IL or missing references)
			//IL_0060: Invalid comparison between Unknown and I4
			//IL_0069: Unknown result type (might be due to invalid IL or missing references)
			//IL_0070: Invalid comparison between Unknown and I4
			//IL_0079: Unknown result type (might be due to invalid IL or missing references)
			//IL_0080: Invalid comparison between Unknown and I4
			//IL_0087: Unknown result type (might be due to invalid IL or missing references)
			//IL_008e: Invalid comparison between Unknown and I4
			if (!UIControl.KeyboardEnabled)
			{
				return;
			}
			int asInteger = Value.AsInteger;
			if ((int)e.KeyCode == 33)
			{
				asInteger += 2;
			}
			else if ((int)e.KeyCode == 38)
			{
				asInteger++;
			}
			else if ((int)e.KeyCode == 39)
			{
				asInteger++;
			}
			else if ((int)e.KeyCode == 34)
			{
				asInteger = 0;
			}
			else if ((int)e.KeyCode == 40)
			{
				asInteger--;
			}
			else if ((int)e.KeyCode == 37)
			{
				asInteger--;
			}
			else if ((int)e.KeyCode == 36)
			{
				asInteger = 0;
			}
			else
			{
				if ((int)e.KeyCode != 35)
				{
					return;
				}
				asInteger = 2;
			}
			ChangeIndex(asInteger);
		}

		protected override void InternalOnMouseWheel(MouseEventArgs e)
		{
			if (UIControl.MouseWheelEnabled)
			{
				int asInteger = Value.AsInteger;
				asInteger = ((e.Delta <= 0) ? (asInteger - 1) : (asInteger + 1));
				ChangeIndex(asInteger);
			}
		}

		private void OnValueChanged(object sender, ValueIntegerEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueIntegerEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			p.Graphics.SmoothingMode = (SmoothingMode)4;
			Size requiredSize = Panel.GetRequiredSize(p);
			Rectangle r = new Rectangle(p.Left + 1, p.Top + requiredSize.Height, p.Width - 2, p.Height - requiredSize.Height);
			ref Point pointerCenterPoint = ref m_PointerCenterPoint;
			pointerCenterPoint = new Point((r.Left + r.Right) / 2, (r.Top + r.Bottom) / 2);
			m_AAngleDelta = 90f - (float)Math2.ToAngle(Math.Atan2(m_PointerCenterPoint.Y - requiredSize.Height, p.Width - Panel.ColWidth - m_PointerCenterPoint.X));
			float angle = ((Panel.PositionCount == 2) ? ((Value.AsInteger != 0) ? m_AAngleDelta : (0f - m_AAngleDelta)) : ((Value.AsInteger == 0) ? (0f - m_AAngleDelta) : ((Value.AsInteger != 1) ? m_AAngleDelta : 0f)));
			((ISwitchPanelPanel)Panel).Draw(p, Value.AsInteger);
			((IPointerSwitchPanel)Pointer).Draw(p, r, angle, UIControl.FocusRectangleShow, base.IsDown);
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class SwitchPanelEditorPlugIn : PlugInStandard
	{
		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private CheckBox AutoSizeCheckBox;

		private FocusLabel label1;

		private FocusLabel label4;

		private FontButton FontButton;

		private ColorPicker ForeColorPicker;

		private ColorPicker BackColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public SwitchPanelEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			FontButton = new FontButton();
			AutoSizeCheckBox = new CheckBox();
			ForeColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label4 = new FocusLabel();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(87, 106);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(136, 104);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 4;
			((Control)FontButton).Location = new Point(288, 48);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 2;
			((Control)AutoSizeCheckBox).Location = new Point(288, 104);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 5;
			AutoSizeCheckBox.Text = "Auto Size";
			((Control)ForeColorPicker).Location = new Point(136, 48);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(136, 21);
			((Control)ForeColorPicker).TabIndex = 1;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(75, 75);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(136, 72);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 3;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label4).Location = new Point(77, 51);
			((Control)label4).Name = "label4";
			label4.Size = new Size(59, 15);
			label4.Text = "Fore Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(136, 8);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(100, 10);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(176, 138);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(136, 136);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 6;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(32, 138);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Name = "SwitchPanelEditorPlugIn";
			((Control)this).Size = new Size(440, 200);
			base.Title = "Switch Panel Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueIntegerEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new PointerSwitchPanelEditorPlugIn(), "Pointer", sameLevel: false);
			AddSubPlugIn(new SwitchPanelPanelEditorPlugIn(), "Panel", sameLevel: false);
			AddSubPlugIn(new UIControlSwitchPanelEditorPlugIn(), "UI Control", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as SwitchPanel).Value;
			base.SubPlugIns[1].Value = (base.Value as SwitchPanel).Pointer;
			base.SubPlugIns[2].Value = (base.Value as SwitchPanel).Panel;
			base.SubPlugIns[3].Value = (base.Value as SwitchPanel).UIControl;
			base.SubPlugIns[4].Value = (base.Value as SwitchPanel).Border;
		}
	}
}
namespace Iocomp.Interfaces
{
	public interface ISwitchPanelPanel
	{
		void Draw(PaintArgs p, int position);
	}
}
namespace Iocomp.Classes
{
	[Description("Controls the panel attributes for the SwitchPanel control.")]
	[DefaultProperty("Style")]
	public sealed class SwitchPanelPanel : SubClassBase, ISwitchPanelPanel
	{
		private string[] m_Labels;

		private int m_PositionCount;

		private Color m_ForeColorActive;

		private Color m_ForeColorInactive;

		private Font m_FontActive;

		private Font m_FontInactive;

		private double m_MarginTop;

		private double m_MarginRow;

		private double m_MarginCol;

		private double m_MarginBottom;

		private double m_MarginSides;

		private bool m_DrawOutline;

		private Rectangle m_PositionClickRect1;

		private Rectangle m_PositionClickRect2;

		private Rectangle m_PositionClickRect3;

		private Size[] m_LabelSizes;

		private int m_MarginPixelsTop;

		private int m_MarginPixelsRow;

		private int m_MarginPixelsCol;

		private int m_MarginPixelsBottom;

		private int m_MarginPixelsSides;

		private int m_Row1Top;

		private int m_Row2Top;

		private int m_Row1Height;

		private int m_Row2Height;

		private int m_Col1CenterX;

		private int m_Col2CenterX;

		private int m_Col3CenterX;

		private int m_ColWidth;

		private int m_Height;

		[Description("")]
		public string PositionText1
		{
			get
			{
				return m_Labels[0];
			}
			set
			{
				PropertyUpdateDefault("PositionText1", value);
				if (m_Labels[0] != value)
				{
					m_Labels[0] = value;
					DoPropertyChange(this, "PositionText1");
				}
			}
		}

		[Description("")]
		public string PositionText2
		{
			get
			{
				return m_Labels[1];
			}
			set
			{
				PropertyUpdateDefault("PositionText2", value);
				if (m_Labels[1] != value)
				{
					m_Labels[1] = value;
					DoPropertyChange(this, "PositionText2");
				}
			}
		}

		[Description("")]
		public string PositionText3
		{
			get
			{
				return m_Labels[2];
			}
			set
			{
				PropertyUpdateDefault("PositionText3", value);
				if (m_Labels[2] != value)
				{
					m_Labels[2] = value;
					DoPropertyChange(this, "PositionText3");
				}
			}
		}

		[Description("")]
		public int PositionCount
		{
			get
			{
				return m_PositionCount;
			}
			set
			{
				PropertyUpdateDefault("PositionCount", value);
				if (value < 2)
				{
					value = 2;
				}
				if (value > 3)
				{
					value = 3;
				}
				if (PositionCount != value)
				{
					m_PositionCount = value;
					DoPropertyChange(this, "PositionCount");
				}
			}
		}

		[Description("")]
		public double MarginTop
		{
			get
			{
				return m_MarginTop;
			}
			set
			{
				PropertyUpdateDefault("MarginTop", value);
				if (m_MarginTop != value)
				{
					m_MarginTop = value;
					DoPropertyChange(this, "MarginTop");
				}
			}
		}

		[Description("")]
		public double MarginRow
		{
			get
			{
				return m_MarginRow;
			}
			set
			{
				PropertyUpdateDefault("MarginRow", value);
				if (MarginRow != value)
				{
					m_MarginRow = value;
					DoPropertyChange(this, "MarginRow");
				}
			}
		}

		[Description("")]
		public double MarginCol
		{
			get
			{
				return m_MarginCol;
			}
			set
			{
				PropertyUpdateDefault("MarginCol", value);
				if (MarginCol != value)
				{
					m_MarginCol = value;
					DoPropertyChange(this, "MarginCol");
				}
			}
		}

		[Description("")]
		public double MarginBottom
		{
			get
			{
				return m_MarginBottom;
			}
			set
			{
				PropertyUpdateDefault("MarginBottom", value);
				if (MarginBottom != value)
				{
					m_MarginBottom = value;
					DoPropertyChange(this, "MarginBottom");
				}
			}
		}

		[Description("")]
		public double MarginSides
		{
			get
			{
				return m_MarginSides;
			}
			set
			{
				PropertyUpdateDefault("MarginSides", value);
				if (MarginSides != value)
				{
					m_MarginSides = value;
					DoPropertyChange(this, "MarginSides");
				}
			}
		}

		public new Color BackColor
		{
			get
			{
				return base.BackColor;
			}
			set
			{
				base.BackColor = value;
			}
		}

		[Description("")]
		public bool DrawOutline
		{
			get
			{
				return m_DrawOutline;
			}
			set
			{
				PropertyUpdateDefault("DrawOutline", value);
				if (DrawOutline != value)
				{
					m_DrawOutline = value;
					DoPropertyChange(this, "DrawOutline");
				}
			}
		}

		[Description("")]
		public Color ForeColorActive
		{
			get
			{
				return m_ForeColorActive;
			}
			set
			{
				PropertyUpdateDefault("ForeColorActive", value);
				if (ForeColorActive != value)
				{
					m_ForeColorActive = value;
					DoPropertyChange(this, "ForeColorActive");
				}
			}
		}

		[Description("")]
		public Color ForeColorInactive
		{
			get
			{
				return m_ForeColorInactive;
			}
			set
			{
				PropertyUpdateDefault("ForeColorInactive", value);
				if (ForeColorInactive != value)
				{
					m_ForeColorInactive = value;
					DoPropertyChange(this, "ForeColorInactive");
				}
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Visible)]
		[Description("")]
		public Font FontActive
		{
			get
			{
				if (base.GettingDefault)
				{
					return m_FontActive;
				}
				if (m_FontActive == null && ControlBase != null)
				{
					return ControlBase.Font;
				}
				return m_FontActive;
			}
			set
			{
				PropertyUpdateDefault("FontActive", value);
				if (!GPFunctions.Equals(FontActive, value))
				{
					m_FontActive = value;
					DoPropertyChange(this, "FontActive");
				}
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Visible)]
		[Description("")]
		public Font FontInactive
		{
			get
			{
				if (base.GettingDefault)
				{
					return m_FontInactive;
				}
				if (m_FontInactive == null && ControlBase != null)
				{
					return ControlBase.Font;
				}
				return m_FontInactive;
			}
			set
			{
				PropertyUpdateDefault("FontInactive", value);
				if (!GPFunctions.Equals(FontInactive, value))
				{
					m_FontInactive = value;
					DoPropertyChange(this, "FontInactive");
				}
			}
		}

		[Description("")]
		[Browsable(false)]
		public int ColWidth => m_ColWidth;

		[Browsable(false)]
		[Description("")]
		public Rectangle PositionClickRect1 => m_PositionClickRect1;

		[Description("")]
		[Browsable(false)]
		public Rectangle PositionClickRect2 => m_PositionClickRect2;

		[Browsable(false)]
		[Description("")]
		public Rectangle PositionClickRect3 => m_PositionClickRect3;

		protected override PlugInStandard GetPlugIn()
		{
			return new SwitchPanelPanelEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Panel";
		}

		void ISwitchPanelPanel.Draw(PaintArgs p, int position)
		{
			Draw(p, position);
		}

		public SwitchPanelPanel()
		{
			DoCreate();
		}

		protected override void CreateObjects()
		{
			m_Labels = new string[3];
			m_LabelSizes = new Size[3];
			base.CreateObjects();
		}

		private bool ShouldSerializePositionText1()
		{
			return PropertyShouldSerialize("PositionText1");
		}

		private void ResetPositionText1()
		{
			PropertyReset("PositionText1");
		}

		private bool ShouldSerializePositionText2()
		{
			return PropertyShouldSerialize("PositionText2");
		}

		private void ResetPositionText2()
		{
			PropertyReset("PositionText2");
		}

		private bool ShouldSerializePositionText3()
		{
			return PropertyShouldSerialize("PositionText3");
		}

		private void ResetPositionText3()
		{
			PropertyReset("PositionText3");
		}

		private bool ShouldSerializePositionCount()
		{
			return PropertyShouldSerialize("PositionCount");
		}

		private void ResetPositionCount()
		{
			PropertyReset("PositionCount");
		}

		private bool ShouldSerializeMarginTop()
		{
			return PropertyShouldSerialize("MarginTop");
		}

		private void ResetMarginTop()
		{
			PropertyReset("MarginTop");
		}

		private bool ShouldSerializeMarginRow()
		{
			return PropertyShouldSerialize("MarginRow");
		}

		private void ResetMarginRow()
		{
			PropertyReset("MarginRow");
		}

		private bool ShouldSerializeMarginCol()
		{
			return PropertyShouldSerialize("MarginCol");
		}

		private void ResetMarginCol()
		{
			PropertyReset("MarginCol");
		}

		private bool ShouldSerializeMarginBottom()
		{
			return PropertyShouldSerialize("MarginBottom");
		}

		private void ResetMarginBottom()
		{
			PropertyReset("MarginBottom");
		}

		private bool ShouldSerializeMarginSides()
		{
			return PropertyShouldSerialize("MarginSides");
		}

		private void ResetMarginSides()
		{
			PropertyReset("MarginSides");
		}

		private bool ShouldSerializeBackColor()
		{
			return PropertyShouldSerialize("BackColor");
		}

		private void ResetBackColor()
		{
			PropertyReset("BackColor");
		}

		private bool ShouldSerializeDrawOutline()
		{
			return PropertyShouldSerialize("DrawOutline");
		}

		private void ResetDrawOutline()
		{
			PropertyReset("DrawOutline");
		}

		private bool ShouldSerializeForeColorActive()
		{
			return PropertyShouldSerialize("ForeColorActive");
		}

		private void ResetForeColorActive()
		{
			PropertyReset("ForeColorActive");
		}

		private bool ShouldSerializeForeColorInactive()
		{
			return PropertyShouldSerialize("ForeColorInactive");
		}

		private void ResetForeColorInactive()
		{
			PropertyReset("ForeColorInactive");
		}

		private bool ShouldSerializeFontActive()
		{
			return PropertyShouldSerialize("FontActive");
		}

		private void ResetFontActive()
		{
			PropertyReset("FontActive");
		}

		private bool ShouldSerializeFontInactive()
		{
			return PropertyShouldSerialize("FontInactive");
		}

		private void ResetFontInactive()
		{
			PropertyReset("FontInactive");
		}

		public Size GetRequiredSize(PaintArgs p)
		{
			CalcRects(p);
			int width;
			int height;
			if (PositionCount == 2)
			{
				width = 2 * m_MarginPixelsSides + 2 * m_ColWidth + m_MarginPixelsCol;
				height = m_Row1Height + m_MarginPixelsTop + m_MarginPixelsBottom;
			}
			else
			{
				width = 2 * m_MarginPixelsSides + 2 * m_ColWidth + m_MarginPixelsCol;
				height = m_MarginPixelsTop + m_MarginPixelsBottom + m_MarginPixelsRow + m_Row1Height + m_Row2Height;
			}
			return new Size(width, height);
		}

		private void CalcRects(PaintArgs p)
		{
			Font font = ((p.Graphics.MeasureString(FontActive).Height <= p.Graphics.MeasureString(FontInactive).Height) ? FontInactive : FontActive);
			ref Size reference = ref m_LabelSizes[0];
			reference = p.Graphics.MeasureString(PositionText1, font);
			ref Size reference2 = ref m_LabelSizes[1];
			reference2 = p.Graphics.MeasureString(PositionText2, font);
			ref Size reference3 = ref m_LabelSizes[2];
			reference3 = p.Graphics.MeasureString(PositionText3, font);
			m_ColWidth = 0;
			m_ColWidth = Math.Max(m_ColWidth, m_LabelSizes[0].Width);
			m_ColWidth = Math.Max(m_ColWidth, m_LabelSizes[1].Width);
			if (PositionCount > 2)
			{
				m_ColWidth = Math.Max(m_ColWidth, m_LabelSizes[2].Width);
			}
			m_MarginPixelsTop = (int)((double)p.Graphics.MeasureString(font).Height * MarginTop);
			m_MarginPixelsRow = (int)((double)p.Graphics.MeasureString(font).Height * MarginRow);
			m_MarginPixelsCol = (int)((double)p.Graphics.MeasureString(font).Width * MarginCol);
			m_MarginPixelsBottom = (int)((double)p.Graphics.MeasureString(font).Height * MarginBottom);
			m_MarginPixelsSides = (int)((double)p.Graphics.MeasureString(font).Width * MarginSides);
			if (PositionCount == 2)
			{
				m_Row1Top = p.Top + m_MarginPixelsTop;
				m_Col1CenterX = p.Left + m_MarginPixelsSides + m_ColWidth / 2;
				m_Col2CenterX = p.Right - m_MarginPixelsSides - m_ColWidth / 2;
				m_Row1Height = 0;
				m_Row1Height = Math.Max(m_Row1Height, m_LabelSizes[0].Height);
				m_Row1Height = Math.Max(m_Row1Height, m_LabelSizes[1].Height);
				m_Height = m_Row1Height + m_MarginPixelsTop + m_MarginPixelsBottom;
				ref Rectangle positionClickRect = ref m_PositionClickRect1;
				positionClickRect = new Rectangle(m_Col1CenterX - m_LabelSizes[0].Width / 2, m_Row1Top, m_LabelSizes[0].Width + 1, m_LabelSizes[0].Height + 1);
				ref Rectangle positionClickRect2 = ref m_PositionClickRect2;
				positionClickRect2 = new Rectangle(m_Col2CenterX - m_LabelSizes[1].Width / 2, m_Row1Top, m_LabelSizes[1].Width + 1, m_LabelSizes[1].Height + 1);
			}
			else
			{
				m_Row1Top = p.Top + m_MarginPixelsTop;
				m_Row2Top = m_Row1Top + m_LabelSizes[1].Height + m_MarginPixelsRow;
				m_Col1CenterX = p.Left + m_MarginPixelsSides + m_ColWidth / 2;
				m_Col2CenterX = p.CenterX;
				m_Col3CenterX = p.Right - m_MarginPixelsSides - m_ColWidth / 2;
				m_Row1Height = m_LabelSizes[1].Height;
				m_Row2Height = 0;
				m_Row2Height = Math.Max(m_Row2Height, m_LabelSizes[0].Height);
				m_Row2Height = Math.Max(m_Row2Height, m_LabelSizes[2].Height);
				m_Height = m_Row1Height + m_Row2Height + m_MarginPixelsTop + m_MarginPixelsRow + m_MarginPixelsBottom;
				ref Rectangle positionClickRect3 = ref m_PositionClickRect1;
				positionClickRect3 = new Rectangle(m_Col1CenterX - m_LabelSizes[0].Width / 2, m_Row2Top, m_LabelSizes[0].Width + 1, m_LabelSizes[0].Height + 1);
				ref Rectangle positionClickRect4 = ref m_PositionClickRect2;
				positionClickRect4 = new Rectangle(m_Col2CenterX - m_LabelSizes[1].Width / 2, m_Row1Top, m_LabelSizes[1].Width + 1, m_LabelSizes[1].Height + 1);
				ref Rectangle positionClickRect5 = ref m_PositionClickRect3;
				positionClickRect5 = new Rectangle(m_Col3CenterX - m_LabelSizes[2].Width / 2, m_Row2Top, m_LabelSizes[2].Width + 1, m_LabelSizes[2].Height + 1);
			}
		}

		private Font GetLabelFont(int drawPosition, int activePosition)
		{
			if (drawPosition == activePosition)
			{
				return FontActive;
			}
			return FontInactive;
		}

		private Color GetLabelForeColor(int drawPosition, int activePosition)
		{
			if (drawPosition == activePosition)
			{
				return ForeColorActive;
			}
			return ForeColorInactive;
		}

		private void Draw(PaintArgs p, int position)
		{
			//IL_0075: Unknown result type (might be due to invalid IL or missing references)
			//IL_007f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0085: Unknown result type (might be due to invalid IL or missing references)
			CalcRects(p);
			if (DrawOutline)
			{
				p.Graphics.DrawRectangle(p.Graphics.Pen(BackColor), p.PenRectangle);
			}
			Rectangle rect = new Rectangle(p.Left, p.Top, p.Width, m_Height);
			p.Graphics.FillRectangle(p.Graphics.Brush(BackColor), rect);
			DrawStringFormat genericTypographic = DrawStringFormat.GenericTypographic;
			genericTypographic.FormatFlags = (StringFormatFlags)(genericTypographic.FormatFlags | 0x4000 | 0x1000);
			if (PositionCount == 2)
			{
				p.Graphics.DrawString(m_Labels[0], GetLabelFont(0, position), p.Graphics.Brush(GetLabelForeColor(0, position)), m_PositionClickRect1, genericTypographic);
				p.Graphics.DrawString(m_Labels[1], GetLabelFont(1, position), p.Graphics.Brush(GetLabelForeColor(1, position)), m_PositionClickRect2, genericTypographic);
			}
			else
			{
				p.Graphics.DrawString(m_Labels[0], GetLabelFont(0, position), p.Graphics.Brush(GetLabelForeColor(0, position)), m_PositionClickRect1, genericTypographic);
				p.Graphics.DrawString(m_Labels[1], GetLabelFont(1, position), p.Graphics.Brush(GetLabelForeColor(1, position)), m_PositionClickRect2, genericTypographic);
				p.Graphics.DrawString(m_Labels[2], GetLabelFont(2, position), p.Graphics.Brush(GetLabelForeColor(2, position)), m_PositionClickRect3, genericTypographic);
			}
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class SwitchPanelPanelEditorPlugIn : PlugInStandard
	{
		private FocusLabel label5;

		private GroupBox groupBox4;

		private FocusLabel label8;

		private FocusLabel label9;

		private FocusLabel label10;

		private FocusLabel label11;

		private FocusLabel label12;

		private NumericUpDown PositionCountNumericUpDown;

		private EditMultiLine PositionText1EditMultiLine;

		private EditMultiLine PositionText2EditMultiLine;

		private FocusLabel label13;

		private EditMultiLine PositionText3EditMultiLine;

		private FocusLabel label14;

		private FocusLabel label15;

		private GroupBox groupBox3;

		private GroupBox groupBox5;

		private FocusLabel label1;

		private FocusLabel label2;

		private CheckBox DrawOutlineCheckBox;

		private FocusLabel label7;

		private EditBox MarginRowNumericTextBox;

		private EditBox MarginColNumericTextBox;

		private EditBox MarginSidesNumericTextBox;

		private EditBox MarginTopNumericTextBox;

		private EditBox MarginBottomNumericTextBox;

		private ColorPicker BackColorPicker;

		private FontButton FontInactiveButton;

		private FontButton FontActiveButton;

		private ColorPicker ForeColorInactivePicker;

		private ColorPicker ForeColorActivePicker;

		private Container components = null;

		public SwitchPanelPanelEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_002c: Expected O, but got Unknown
			//IL_00e8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f2: Expected O, but got Unknown
			//IL_0109: Unknown result type (might be due to invalid IL or missing references)
			//IL_0113: Expected O, but got Unknown
			//IL_0c4d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0c57: Expected O, but got Unknown
			//IL_0dc4: Unknown result type (might be due to invalid IL or missing references)
			//IL_0dce: Expected O, but got Unknown
			DrawOutlineCheckBox = new CheckBox();
			label5 = new FocusLabel();
			PositionCountNumericUpDown = new NumericUpDown();
			groupBox4 = new GroupBox();
			MarginRowNumericTextBox = new EditBox();
			label12 = new FocusLabel();
			MarginColNumericTextBox = new EditBox();
			label11 = new FocusLabel();
			MarginSidesNumericTextBox = new EditBox();
			label10 = new FocusLabel();
			MarginTopNumericTextBox = new EditBox();
			label9 = new FocusLabel();
			MarginBottomNumericTextBox = new EditBox();
			label8 = new FocusLabel();
			PositionText1EditMultiLine = new EditMultiLine();
			PositionText2EditMultiLine = new EditMultiLine();
			label13 = new FocusLabel();
			PositionText3EditMultiLine = new EditMultiLine();
			label14 = new FocusLabel();
			label15 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			groupBox3 = new GroupBox();
			FontInactiveButton = new FontButton();
			FontActiveButton = new FontButton();
			groupBox5 = new GroupBox();
			label2 = new FocusLabel();
			ForeColorInactivePicker = new ColorPicker();
			label1 = new FocusLabel();
			ForeColorActivePicker = new ColorPicker();
			label7 = new FocusLabel();
			((Control)groupBox4).SuspendLayout();
			((Control)groupBox3).SuspendLayout();
			((Control)groupBox5).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)DrawOutlineCheckBox).Location = new Point(96, 88);
			((Control)DrawOutlineCheckBox).Name = "DrawOutlineCheckBox";
			DrawOutlineCheckBox.PropertyName = "DrawOutline";
			((Control)DrawOutlineCheckBox).TabIndex = 3;
			DrawOutlineCheckBox.Text = "Draw Outline";
			label5.LoadingBegin();
			label5.FocusControl = (Control)(object)PositionCountNumericUpDown;
			((Control)label5).Location = new Point(17, 121);
			((Control)label5).Name = "label5";
			label5.Size = new Size(79, 15);
			label5.Text = "Position Count";
			label5.UpdateFrameRate = 50.0;
			label5.LoadingEnd();
			((Control)PositionCountNumericUpDown).Location = new Point(96, 120);
			((NumericUpDown)PositionCountNumericUpDown).Maximum = new decimal(new int[4] { 3, 0, 0, 0 });
			((NumericUpDown)PositionCountNumericUpDown).Minimum = new decimal(new int[4] { 2, 0, 0, 0 });
			((Control)PositionCountNumericUpDown).Name = "PositionCountNumericUpDown";
			PositionCountNumericUpDown.PropertyName = "PositionCount";
			((Control)PositionCountNumericUpDown).Size = new Size(48, 20);
			((Control)PositionCountNumericUpDown).TabIndex = 4;
			((UpDownBase)PositionCountNumericUpDown).TextAlign = (HorizontalAlignment)2;
			((Control)groupBox4).Controls.Add((Control)(object)MarginRowNumericTextBox);
			((Control)groupBox4).Controls.Add((Control)(object)label12);
			((Control)groupBox4).Controls.Add((Control)(object)MarginColNumericTextBox);
			((Control)groupBox4).Controls.Add((Control)(object)label11);
			((Control)groupBox4).Controls.Add((Control)(object)MarginSidesNumericTextBox);
			((Control)groupBox4).Controls.Add((Control)(object)label10);
			((Control)groupBox4).Controls.Add((Control)(object)MarginTopNumericTextBox);
			((Control)groupBox4).Controls.Add((Control)(object)label9);
			((Control)groupBox4).Controls.Add((Control)(object)MarginBottomNumericTextBox);
			((Control)groupBox4).Controls.Add((Control)(object)label8);
			((Control)groupBox4).Location = new Point(368, 0);
			((Control)groupBox4).Name = "groupBox4";
			((Control)groupBox4).Size = new Size(112, 176);
			((Control)groupBox4).TabIndex = 8;
			groupBox4.TabStop = false;
			((Control)groupBox4).Text = "Margin";
			MarginRowNumericTextBox.LoadingBegin();
			((Control)MarginRowNumericTextBox).Location = new Point(56, 120);
			((Control)MarginRowNumericTextBox).Name = "MarginRowNumericTextBox";
			MarginRowNumericTextBox.PropertyName = "MarginRow";
			MarginRowNumericTextBox.Size = new Size(48, 20);
			((Control)MarginRowNumericTextBox).TabIndex = 3;
			MarginRowNumericTextBox.TextAlign = (HorizontalAlignment)2;
			MarginRowNumericTextBox.LoadingEnd();
			label12.LoadingBegin();
			label12.FocusControl = (Control)(object)MarginRowNumericTextBox;
			((Control)label12).Location = new Point(26, 122);
			((Control)label12).Name = "label12";
			label12.Size = new Size(30, 15);
			label12.Text = "Row";
			label12.UpdateFrameRate = 50.0;
			label12.LoadingEnd();
			MarginColNumericTextBox.LoadingBegin();
			((Control)MarginColNumericTextBox).Location = new Point(56, 144);
			((Control)MarginColNumericTextBox).Name = "MarginColNumericTextBox";
			MarginColNumericTextBox.PropertyName = "MarginCol";
			MarginColNumericTextBox.Size = new Size(48, 20);
			((Control)MarginColNumericTextBox).TabIndex = 4;
			MarginColNumericTextBox.TextAlign = (HorizontalAlignment)2;
			MarginColNumericTextBox.LoadingEnd();
			label11.LoadingBegin();
			label11.FocusControl = (Control)(object)MarginColNumericTextBox;
			((Control)label11).Location = new Point(32, 146);
			((Control)label11).Name = "label11";
			label11.Size = new Size(24, 15);
			label11.Text = "Col";
			label11.UpdateFrameRate = 50.0;
			label11.LoadingEnd();
			MarginSidesNumericTextBox.LoadingBegin();
			((Control)MarginSidesNumericTextBox).Location = new Point(56, 80);
			((Control)MarginSidesNumericTextBox).Name = "MarginSidesNumericTextBox";
			MarginSidesNumericTextBox.PropertyName = "MarginSides";
			MarginSidesNumericTextBox.Size = new Size(48, 20);
			((Control)MarginSidesNumericTextBox).TabIndex = 2;
			MarginSidesNumericTextBox.TextAlign = (HorizontalAlignment)2;
			MarginSidesNumericTextBox.LoadingEnd();
			label10.LoadingBegin();
			label10.FocusControl = (Control)(object)MarginSidesNumericTextBox;
			((Control)label10).Location = new Point(21, 82);
			((Control)label10).Name = "label10";
			label10.Size = new Size(35, 15);
			label10.Text = "Sides";
			label10.UpdateFrameRate = 50.0;
			label10.LoadingEnd();
			MarginTopNumericTextBox.LoadingBegin();
			((Control)MarginTopNumericTextBox).Location = new Point(56, 32);
			((Control)MarginTopNumericTextBox).Name = "MarginTopNumericTextBox";
			MarginTopNumericTextBox.PropertyName = "MarginTop";
			MarginTopNumericTextBox.Size = new Size(48, 20);
			((Control)MarginTopNumericTextBox).TabIndex = 0;
			MarginTopNumericTextBox.TextAlign = (HorizontalAlignment)2;
			MarginTopNumericTextBox.LoadingEnd();
			label9.LoadingBegin();
			label9.FocusControl = (Control)(object)MarginTopNumericTextBox;
			((Control)label9).Location = new Point(30, 34);
			((Control)label9).Name = "label9";
			label9.Size = new Size(26, 15);
			label9.Text = "Top";
			label9.UpdateFrameRate = 50.0;
			label9.LoadingEnd();
			MarginBottomNumericTextBox.LoadingBegin();
			((Control)MarginBottomNumericTextBox).Location = new Point(56, 56);
			((Control)MarginBottomNumericTextBox).Name = "MarginBottomNumericTextBox";
			MarginBottomNumericTextBox.PropertyName = "MarginBottom";
			MarginBottomNumericTextBox.Size = new Size(48, 20);
			((Control)MarginBottomNumericTextBox).TabIndex = 1;
			MarginBottomNumericTextBox.TextAlign = (HorizontalAlignment)2;
			MarginBottomNumericTextBox.LoadingEnd();
			label8.LoadingBegin();
			label8.FocusControl = (Control)(object)MarginBottomNumericTextBox;
			((Control)label8).Location = new Point(14, 58);
			((Control)label8).Name = "label8";
			label8.Size = new Size(42, 15);
			label8.Text = "Bottom";
			label8.UpdateFrameRate = 50.0;
			label8.LoadingEnd();
			PositionText1EditMultiLine.EditFont = null;
			((Control)PositionText1EditMultiLine).Location = new Point(96, 8);
			((Control)PositionText1EditMultiLine).Name = "PositionText1EditMultiLine";
			PositionText1EditMultiLine.PropertyName = "PositionText1";
			((Control)PositionText1EditMultiLine).Size = new Size(142, 20);
			((Control)PositionText1EditMultiLine).TabIndex = 0;
			PositionText2EditMultiLine.EditFont = null;
			((Control)PositionText2EditMultiLine).Location = new Point(96, 32);
			((Control)PositionText2EditMultiLine).Name = "PositionText2EditMultiLine";
			PositionText2EditMultiLine.PropertyName = "PositionText2";
			((Control)PositionText2EditMultiLine).Size = new Size(142, 20);
			((Control)PositionText2EditMultiLine).TabIndex = 1;
			label13.LoadingBegin();
			label13.FocusControl = (Control)(object)PositionText2EditMultiLine;
			((Control)label13).Location = new Point(16, 35);
			((Control)label13).Name = "label13";
			label13.Size = new Size(80, 15);
			label13.Text = "Position Text 2";
			label13.UpdateFrameRate = 50.0;
			label13.LoadingEnd();
			PositionText3EditMultiLine.EditFont = null;
			((Control)PositionText3EditMultiLine).Location = new Point(96, 56);
			((Control)PositionText3EditMultiLine).Name = "PositionText3EditMultiLine";
			PositionText3EditMultiLine.PropertyName = "PositionText3";
			((Control)PositionText3EditMultiLine).Size = new Size(142, 20);
			((Control)PositionText3EditMultiLine).TabIndex = 2;
			label14.LoadingBegin();
			label14.FocusControl = (Control)(object)PositionText3EditMultiLine;
			((Control)label14).Location = new Point(16, 59);
			((Control)label14).Name = "label14";
			label14.Size = new Size(80, 15);
			label14.Text = "Position Text 3";
			label14.UpdateFrameRate = 50.0;
			label14.LoadingEnd();
			label15.LoadingBegin();
			label15.FocusControl = (Control)(object)BackColorPicker;
			((Control)label15).Location = new Point(35, 155);
			((Control)label15).Name = "label15";
			label15.Size = new Size(61, 15);
			label15.Text = "Back Color";
			label15.UpdateFrameRate = 50.0;
			label15.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(96, 152);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(144, 21);
			((Control)BackColorPicker).TabIndex = 5;
			((Control)groupBox3).Controls.Add((Control)(object)FontInactiveButton);
			((Control)groupBox3).Controls.Add((Control)(object)FontActiveButton);
			((Control)groupBox3).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)groupBox3).Location = new Point(248, 0);
			((Control)groupBox3).Name = "groupBox3";
			((Control)groupBox3).Size = new Size(112, 88);
			((Control)groupBox3).TabIndex = 6;
			groupBox3.TabStop = false;
			((Control)groupBox3).Text = "Font";
			((Control)FontInactiveButton).Location = new Point(16, 56);
			((Control)FontInactiveButton).Name = "FontInactiveButton";
			FontInactiveButton.PropertyName = "FontInactive";
			((Control)FontInactiveButton).TabIndex = 1;
			FontInactiveButton.Text = "Inactive";
			((Control)FontActiveButton).Location = new Point(16, 24);
			((Control)FontActiveButton).Name = "FontActiveButton";
			FontActiveButton.PropertyName = "FontActive";
			((Control)FontActiveButton).TabIndex = 0;
			FontActiveButton.Text = "Active";
			((Control)groupBox5).Controls.Add((Control)(object)label2);
			((Control)groupBox5).Controls.Add((Control)(object)ForeColorInactivePicker);
			((Control)groupBox5).Controls.Add((Control)(object)label1);
			((Control)groupBox5).Controls.Add((Control)(object)ForeColorActivePicker);
			((Control)groupBox5).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			((Control)groupBox5).Location = new Point(248, 96);
			((Control)groupBox5).Name = "groupBox5";
			((Control)groupBox5).Size = new Size(112, 80);
			((Control)groupBox5).TabIndex = 7;
			groupBox5.TabStop = false;
			((Control)groupBox5).Text = "Fore Color";
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)ForeColorInactivePicker;
			((Control)label2).Location = new Point(11, 51);
			((Control)label2).Name = "label2";
			label2.Size = new Size(45, 15);
			label2.Text = "Inactive";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)ForeColorInactivePicker).Location = new Point(56, 48);
			((Control)ForeColorInactivePicker).Name = "ForeColorInactivePicker";
			ForeColorInactivePicker.PropertyName = "ForeColorInactive";
			((Control)ForeColorInactivePicker).Size = new Size(48, 21);
			ForeColorInactivePicker.Style = ColorPickerStyle.ColorBox;
			((Control)ForeColorInactivePicker).TabIndex = 1;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)ForeColorActivePicker;
			((Control)label1).Location = new Point(18, 19);
			((Control)label1).Name = "label1";
			label1.Size = new Size(38, 15);
			label1.Text = "Active";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)ForeColorActivePicker).Location = new Point(56, 16);
			((Control)ForeColorActivePicker).Name = "ForeColorActivePicker";
			ForeColorActivePicker.PropertyName = "ForeColorActive";
			((Control)ForeColorActivePicker).Size = new Size(48, 21);
			ForeColorActivePicker.Style = ColorPickerStyle.ColorBox;
			((Control)ForeColorActivePicker).TabIndex = 0;
			label7.LoadingBegin();
			label7.FocusControl = (Control)(object)PositionText1EditMultiLine;
			((Control)label7).Location = new Point(16, 11);
			((Control)label7).Name = "label7";
			label7.Size = new Size(80, 15);
			label7.Text = "Position Text 1";
			label7.UpdateFrameRate = 50.0;
			label7.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)groupBox5);
			((Control)this).Controls.Add((Control)(object)groupBox3);
			((Control)this).Controls.Add((Control)(object)label15);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)PositionText3EditMultiLine);
			((Control)this).Controls.Add((Control)(object)label14);
			((Control)this).Controls.Add((Control)(object)PositionText2EditMultiLine);
			((Control)this).Controls.Add((Control)(object)label13);
			((Control)this).Controls.Add((Control)(object)PositionText1EditMultiLine);
			((Control)this).Controls.Add((Control)(object)label7);
			((Control)this).Controls.Add((Control)(object)groupBox4);
			((Control)this).Controls.Add((Control)(object)label5);
			((Control)this).Controls.Add((Control)(object)PositionCountNumericUpDown);
			((Control)this).Controls.Add((Control)(object)DrawOutlineCheckBox);
			((Control)this).Name = "SwitchPanelPanelEditorPlugIn";
			((Control)this).Size = new Size(528, 192);
			base.Title = "Panel Editor";
			((Control)groupBox4).ResumeLayout(false);
			((Control)groupBox3).ResumeLayout(false);
			((Control)groupBox5).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}
	}
	public class SwitchRotaryDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[Description("SwitchRotary")]
	[DefaultProperty("Name")]
	[DefaultEvent("ValueChanged")]
	[DesignerCategory("code")]
	[ToolboxBitmap(typeof(Access), "SwitchRotary.bmp")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[Designer(typeof(SwitchRotaryDesigner))]
	public class SwitchRotary : ControlBase
	{
		private ValueInteger m_Value;

		private PointerSwitchRotary m_Pointer;

		private ScaleDisplayDiscreetAngular m_ScaleDisplay;

		private ScaleRangeDiscreetAngular m_ScaleRange;

		private UIControlSwitchRotary m_UIControl;

		private ScaleDiscreetItemCollection m_Items;

		private DrawExtent m_DrawExtent;

		private Point m_CenterPoint;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		[Category("Iocomp")]
		public ScaleDiscreetItemCollection Items => m_Items;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("UIControl properties")]
		[Category("Iocomp")]
		public UIControlSwitchRotary UIControl => m_UIControl;

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		public ScaleDisplayDiscreetAngular ScaleDisplay => m_ScaleDisplay;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		[Description("")]
		public ScaleRangeDiscreetAngular ScaleRange => m_ScaleRange;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		[Description("Pointer Properties.")]
		public PointerSwitchRotary Pointer => m_Pointer;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		[Category("Iocomp")]
		public ValueInteger Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsInteger = value.AsInteger;
			}
		}

		[Category("Iocomp")]
		public event ValueIntegerEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueIntegerEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new SwitchRotaryEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Switch Rotary";
		}

		public SwitchRotary()
		{
			m_License = LicenseManager.Validate(typeof(SwitchRotary), this);
			DoCreate();
		}

		~SwitchRotary()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Items = new ScaleDiscreetItemCollection(this);
			m_Value = new ValueInteger();
			AddSubClass(Value);
			m_Pointer = new PointerSwitchRotary();
			AddSubClass(Pointer);
			m_ScaleDisplay = new ScaleDisplayDiscreetAngular();
			AddSubClass(ScaleDisplay);
			m_ScaleRange = new ScaleRangeDiscreetAngular();
			AddSubClass(ScaleRange);
			m_UIControl = new UIControlSwitchRotary();
			AddSubClass(UIControl);
			m_DrawExtent = new DrawExtent();
			((IScaleDisplayDiscreetAngular)ScaleDisplay).ScaleRange = ScaleRange;
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetComponentDefaults()
		{
			Items.Reset();
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			Pointer.Style = PointerStyleSwitchRotary.Bar;
			Pointer.Color = Color.Empty;
			Pointer.Width = 10;
			Pointer.Length = 50;
			ScaleDisplay.Visible = true;
			ScaleDisplay.Margin = 3;
			ScaleDisplay.TextAlignment = StringAlignmentDiscreetAngular.CallOut;
			ScaleDisplay.TextActiveFont = null;
			ScaleDisplay.TextInactiveFont = null;
			ScaleDisplay.TextActiveForeColor = Color.Empty;
			ScaleDisplay.TextInactiveForeColor = Color.Empty;
			ScaleDisplay.TextMargin = 3;
			ScaleDisplay.Markers.Style = MarkerStyleLabel.Circle;
			ScaleDisplay.Markers.BevelStyle = BevelStyle.Sunken;
			ScaleDisplay.Markers.Size = 4;
			ScaleDisplay.Markers.Color = Color.Aqua;
			ScaleDisplay.CallOutLength = 8;
			ScaleRange.Reverse = false;
			ScaleRange.AngleMin = 180.0;
			ScaleRange.AngleSpan = 90.0;
			UIControl.MouseControlStyle = MouseControlStyleSwitchRotary.ClickToGoto;
			UIControl.KeyboardEnabled = true;
			UIControl.FocusRectangleShow = true;
			UIControl.MouseWheelEnabled = true;
		}

		public override void LoadingBegin()
		{
			base.LoadingBegin();
			Items.Clear();
		}

		protected override Size GetDefaultSize()
		{
			return new Size(112, 93);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			Graphics val = ((Control)this).CreateGraphics();
			PaintArgs paintArgs = new PaintArgs(val, base.InnerRectangle, Color.Empty);
			int num = Value.AsInteger;
			if (num < 0)
			{
				num = 0;
			}
			if (num >= Items.Count)
			{
				num = Items.Count - 1;
			}
			m_DrawExtent.Reset();
			m_DrawExtent.AddX(paintArgs.CenterX - Pointer.Length / 2);
			m_DrawExtent.AddX(paintArgs.CenterX + Pointer.Length / 2);
			m_DrawExtent.AddY(paintArgs.CenterY - Pointer.Length / 2);
			m_DrawExtent.AddY(paintArgs.CenterY + Pointer.Length / 2);
			if (ScaleDisplay.Visible)
			{
				((IScaleDisplayDiscreet)ScaleDisplay).Calculate(paintArgs, Items, paintArgs.CenterPoint, num, Pointer.Length / 2);
				for (int i = 0; i < Items.Count; i++)
				{
					m_DrawExtent.Add(Items[i].TextRectangle);
				}
			}
			val.Dispose();
			return new Size(m_DrawExtent.MaxWidth + 2, m_DrawExtent.MaxHeight + 2);
		}

		protected override void ManualSizeFixup(int innerWidth, int innerHeight)
		{
			base.ManualSizeFixup(innerWidth, innerHeight);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == this && propertyName == "Font")
			{
				DoAutoSize();
			}
			if (sender == Items)
			{
				DoAutoSize();
			}
			if (sender == Pointer)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.Markers)
			{
				DoAutoSize();
			}
			if (sender == ScaleRange)
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeItems()
		{
			return true;
		}

		private void ResetItems()
		{
			Items.Reset();
		}

		private bool ShouldSerializeUIControl()
		{
			return ((ISubClassBase)UIControl).ShouldSerialize();
		}

		private void ResetUIControl()
		{
			((ISubClassBase)UIControl).ResetToDefault();
		}

		private bool ShouldSerializeScaleDisplay()
		{
			return ((ISubClassBase)ScaleDisplay).ShouldSerialize();
		}

		private void ResetScaleDisplay()
		{
			((ISubClassBase)ScaleDisplay).ResetToDefault();
		}

		private bool ShouldSerializeScaleRange()
		{
			return ((ISubClassBase)ScaleRange).ShouldSerialize();
		}

		private void ResetScaleRange()
		{
			((ISubClassBase)ScaleRange).ResetToDefault();
		}

		private bool ShouldSerializePointer()
		{
			return ((ISubClassBase)Pointer).ShouldSerialize();
		}

		private void ResetPointer()
		{
			((ISubClassBase)Pointer).ResetToDefault();
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private int GetNewIndex(MouseEventArgs e)
		{
			double num = 360.0;
			int result = 0;
			double num2 = Math2.PointToAngle(m_CenterPoint, e.X, e.Y);
			for (int i = 0; i < Items.Count; i++)
			{
				if (ScaleDisplay.Visible && Items[i].TextRectangle.Contains(e.X, e.Y))
				{
					return i;
				}
				double num3 = ScaleRange.ValueToAngle(i, Items.Count);
				double num4 = Math.Abs(num3 - num2);
				if (num4 > 180.0)
				{
					num4 = 360.0 - num4;
				}
				if (num4 < num)
				{
					num = num4;
					result = i;
				}
			}
			return result;
		}

		protected override void InternalOnMouseLeft(MouseEventArgs e)
		{
			base.IsMouseDown = true;
			((Control)this).Focus();
			if (UIControl.MouseControlStyle == MouseControlStyleSwitchRotary.ClickToGoto)
			{
				Value.AsInteger = GetNewIndex(e);
			}
			InternalOnMouseMove(e);
		}

		protected override void InternalOnMouseMove(MouseEventArgs e)
		{
			if (base.IsMouseDown && UIControl.MouseControlStyle == MouseControlStyleSwitchRotary.DragToDestination)
			{
				Value.AsInteger = GetNewIndex(e);
			}
		}

		protected override void InternalOnMouseUp(MouseEventArgs e)
		{
			base.IsMouseDown = false;
		}

		protected override bool IsInputKey(Keys keyData)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0002: Unknown result type (might be due to invalid IL or missing references)
			//IL_0005: Unknown result type (might be due to invalid IL or missing references)
			//IL_002b: Expected I4, but got Unknown
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			return (keyData - 33) switch
			{
				4 => true, 
				6 => true, 
				7 => true, 
				5 => true, 
				0 => true, 
				1 => true, 
				3 => true, 
				2 => true, 
				_ => base.IsInputKey(keyData), 
			};
		}

		protected override void InternalOnKeyDown(KeyEventArgs e)
		{
			//IL_0035: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Invalid comparison between Unknown and I4
			//IL_0045: Unknown result type (might be due to invalid IL or missing references)
			//IL_004c: Invalid comparison between Unknown and I4
			//IL_0055: Unknown result type (might be due to invalid IL or missing references)
			//IL_005c: Invalid comparison between Unknown and I4
			//IL_0065: Unknown result type (might be due to invalid IL or missing references)
			//IL_006c: Invalid comparison between Unknown and I4
			//IL_0075: Unknown result type (might be due to invalid IL or missing references)
			//IL_007c: Invalid comparison between Unknown and I4
			//IL_0085: Unknown result type (might be due to invalid IL or missing references)
			//IL_008c: Invalid comparison between Unknown and I4
			//IL_0095: Unknown result type (might be due to invalid IL or missing references)
			//IL_009c: Invalid comparison between Unknown and I4
			//IL_00a3: Unknown result type (might be due to invalid IL or missing references)
			//IL_00aa: Invalid comparison between Unknown and I4
			if (!UIControl.KeyboardEnabled)
			{
				return;
			}
			if (Items.Count == 0)
			{
				Value.AsInteger = -1;
				return;
			}
			int asInteger = Value.AsInteger;
			if ((int)e.KeyCode == 33)
			{
				asInteger += 2;
			}
			else if ((int)e.KeyCode == 38)
			{
				asInteger++;
			}
			else if ((int)e.KeyCode == 39)
			{
				asInteger++;
			}
			else if ((int)e.KeyCode == 34)
			{
				asInteger -= 2;
			}
			else if ((int)e.KeyCode == 40)
			{
				asInteger--;
			}
			else if ((int)e.KeyCode == 37)
			{
				asInteger--;
			}
			else if ((int)e.KeyCode == 36)
			{
				asInteger = 0;
			}
			else
			{
				if ((int)e.KeyCode != 35)
				{
					return;
				}
				asInteger = Items.Count - 1;
			}
			if (asInteger < 0)
			{
				asInteger = 0;
			}
			if (asInteger >= Items.Count)
			{
				asInteger = Items.Count - 1;
			}
			Value.AsInteger = asInteger;
		}

		protected override void InternalOnMouseWheel(MouseEventArgs e)
		{
			if (UIControl.MouseWheelEnabled)
			{
				int asInteger = Value.AsInteger;
				asInteger = ((e.Delta <= 0) ? (asInteger - 1) : (asInteger + 1));
				if (asInteger < 0)
				{
					asInteger = 0;
				}
				if (asInteger >= Items.Count)
				{
					asInteger = Items.Count - 1;
				}
				Value.AsInteger = asInteger;
			}
		}

		private void OnValueChanged(object sender, ValueIntegerEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueIntegerEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			int num = Value.AsInteger;
			if (num < 0)
			{
				num = 0;
			}
			if (num >= Items.Count)
			{
				num = Items.Count - 1;
			}
			((IScaleDisplayDiscreet)ScaleDisplay).Calculate(p, Items, p.CenterPoint, num, Pointer.Length / 2);
			m_DrawExtent.Reset();
			m_DrawExtent.AddX(p.CenterX - Pointer.Length / 2);
			m_DrawExtent.AddX(p.CenterX + Pointer.Length / 2);
			m_DrawExtent.AddY(p.CenterY - Pointer.Length / 2);
			m_DrawExtent.AddY(p.CenterY + Pointer.Length / 2);
			if (ScaleDisplay.Visible)
			{
				for (int i = 0; i < Items.Count; i++)
				{
					m_DrawExtent.Add(Items[i].TextRectangle);
				}
			}
			m_CenterPoint = m_DrawExtent.GetNewCenterPoint(p.CenterPoint, p.DrawRectangle);
			((IScaleDisplayDiscreet)ScaleDisplay).Calculate(p, Items, m_CenterPoint, num, Pointer.Length / 2);
			((IScaleDisplayDiscreet)ScaleDisplay).Draw(p, Items, m_CenterPoint, num, base.BackColor);
			((IPointerSwitchRotary)Pointer).Draw(p, m_CenterPoint, (float)ScaleRange.ValueToAngle(num, Items.Count), base.IsMouseDown);
			if (UIControl.FocusRectangleShow && ((Control)this).Focused)
			{
				p.Graphics.DrawFocusRectangle(p.PenRectangle, base.BackColor);
			}
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class SwitchRotaryEditorPlugIn : PlugInStandard
	{
		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private CheckBox AutoSizeCheckBox;

		private FocusLabel label1;

		private FocusLabel label4;

		private FontButton FontButton;

		private ColorPicker ForeColorPicker;

		private ColorPicker BackColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public SwitchRotaryEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			FontButton = new FontButton();
			AutoSizeCheckBox = new CheckBox();
			ForeColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label4 = new FocusLabel();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(95, 114);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(144, 112);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 4;
			((Control)FontButton).Location = new Point(296, 56);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 2;
			((Control)AutoSizeCheckBox).Location = new Point(296, 112);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 5;
			AutoSizeCheckBox.Text = "Auto Size";
			((Control)ForeColorPicker).Location = new Point(144, 56);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(136, 21);
			((Control)ForeColorPicker).TabIndex = 1;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(83, 83);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(144, 80);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 3;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label4).Location = new Point(85, 59);
			((Control)label4).Name = "label4";
			label4.Size = new Size(59, 15);
			label4.Text = "Fore Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(144, 8);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(108, 10);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(184, 146);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(144, 144);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 6;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(40, 146);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Name = "SwitchRotaryEditorPlugIn";
			((Control)this).Size = new Size(464, 208);
			base.Title = "Switch Rotary Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueIntegerEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new PointerSwitchRotaryEditorPlugIn(), "Pointer", sameLevel: false);
			AddSubPlugIn(new ScaleDiscreetItemCollectionEditorPlugIn(), "Items", sameLevel: false);
			AddSubPlugIn(new ScaleDisplayDiscreetAngularEditorPlugIn(), "Scale Display", sameLevel: false);
			AddSubPlugIn(new ScaleRangeDiscreetAngularEditorPlugIn(), "Scale Range", sameLevel: false);
			AddSubPlugIn(new UIControlSwitchRotaryEditorPlugIn(), "UI Control", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as SwitchRotary).Value;
			base.SubPlugIns[1].Value = (base.Value as SwitchRotary).Pointer;
			base.SubPlugIns[2].Value = (base.Value as SwitchRotary).Items;
			base.SubPlugIns[3].Value = (base.Value as SwitchRotary).ScaleDisplay;
			base.SubPlugIns[4].Value = (base.Value as SwitchRotary).ScaleRange;
			base.SubPlugIns[5].Value = (base.Value as SwitchRotary).UIControl;
			base.SubPlugIns[6].Value = (base.Value as SwitchRotary).Border;
		}
	}
	public class SwitchSliderDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[DefaultEvent("ValueChanged")]
	[DefaultProperty("Name")]
	[ToolboxBitmap(typeof(Access), "SwitchSlider.bmp")]
	[Description("SwitchSlider")]
	[DesignerCategory("code")]
	[Designer(typeof(SwitchSliderDesigner))]
	public class SwitchSlider : ControlBase
	{
		private ValueInteger m_Value;

		private PointerSlider m_Pointer;

		private ScaleDisplayDiscreetLinear m_ScaleDisplay;

		private UIControlSwitchSlider m_UIControl;

		private ScaleDiscreetItemCollection m_Items;

		private int m_ScaleTop;

		private int m_ScaleBottom;

		private int m_ScaleHeight;

		private Rectangle m_InnerRect;

		private int m_MouseDownY;

		private int m_MouseDownIndex;

		[Category("Iocomp")]
		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ScaleDiscreetItemCollection Items => m_Items;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("UIControl properties")]
		[Category("Iocomp")]
		public UIControlSwitchSlider UIControl => m_UIControl;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		[Category("Iocomp")]
		public ScaleDisplayDiscreetLinear ScaleDisplay => m_ScaleDisplay;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("Pointer Properties.")]
		[Category("Iocomp")]
		public PointerSlider Pointer => m_Pointer;

		[Category("Iocomp")]
		[Description("")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ValueInteger Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsInteger = value.AsInteger;
			}
		}

		[Category("Iocomp")]
		public event ValueIntegerEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueIntegerEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new SwitchSliderEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Switch Slider";
		}

		public SwitchSlider()
		{
			m_License = LicenseManager.Validate(typeof(SwitchSlider), this);
			DoCreate();
		}

		~SwitchSlider()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Items = new ScaleDiscreetItemCollection(this);
			m_Value = new ValueInteger();
			AddSubClass(Value);
			m_Pointer = new PointerSlider();
			AddSubClass(Pointer);
			m_ScaleDisplay = new ScaleDisplayDiscreetLinear();
			AddSubClass(ScaleDisplay);
			m_UIControl = new UIControlSwitchSlider();
			AddSubClass(UIControl);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			Pointer.Style = PointerStyleSlider.Bar;
			Pointer.Color = Color.Empty;
			Pointer.Width = 22;
			Pointer.Height = 11;
			Pointer.TrackStyle = PointerTrackStyle.Box;
			Pointer.TrackColor = Color.White;
			Pointer.Indicator.ColorActive = Color.Red;
			Pointer.Indicator.ColorInactive = Color.Black;
			Pointer.Indicator.ColorInactiveAuto = false;
			ScaleDisplay.Visible = true;
			ScaleDisplay.Direction = SideDirection.LeftToRight;
			ScaleDisplay.Margin = 3;
			ScaleDisplay.TextActiveFont = null;
			ScaleDisplay.TextInactiveFont = null;
			ScaleDisplay.TextActiveForeColor = Color.Empty;
			ScaleDisplay.TextInactiveForeColor = Color.Empty;
			ScaleDisplay.TextMargin = 3;
			ScaleDisplay.Markers.Style = MarkerStyleLabel.Circle;
			ScaleDisplay.Markers.BevelStyle = BevelStyle.Sunken;
			ScaleDisplay.Markers.Size = 4;
			ScaleDisplay.Markers.Color = Color.Aqua;
			UIControl.MouseControlStyle = MouseControlStyleSwitchSlider.ClickToGoto;
			UIControl.KeyboardEnabled = true;
			UIControl.FocusRectangleShow = true;
			UIControl.MouseWheelEnabled = true;
		}

		public override void LoadingBegin()
		{
			base.LoadingBegin();
			Items.Clear();
		}

		protected override Size GetDefaultSize()
		{
			return new Size(80, 104);
		}

		protected override void SetComponentDefaults()
		{
			Items.Reset();
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			SizeF requiredSize = ((IPointerSlider)Pointer).RequiredSize;
			int num;
			if (ScaleDisplay.Visible)
			{
				num = ScaleDisplay.Margin;
				if (ScaleDisplay.Markers.Style != MarkerStyleLabel.None)
				{
					num += 2 * ScaleDisplay.Markers.Size;
				}
				num += ScaleDisplay.TextMargin;
				Graphics val = ((Control)this).CreateGraphics();
				GraphicsAPI graphicsAPI = new GraphicsAPI(val);
				_ = DrawStringFormat.GenericTypographic;
				float num2 = 0f;
				for (int i = 0; i < Items.Count; i++)
				{
					num2 = Math.Max(num2, graphicsAPI.MeasureString(Items[i].Text, ScaleDisplay.TextActiveFont, typographic: true).Width);
					num2 = Math.Max(num2, graphicsAPI.MeasureString(Items[i].Text, ScaleDisplay.TextInactiveFont, typographic: true).Width);
				}
				val.Dispose();
				num += (int)Math.Ceiling(num2);
			}
			else
			{
				num = 0;
			}
			return new Size(num + 4 + (int)requiredSize.Width, 0);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == this && propertyName == "Font")
			{
				DoAutoSize();
			}
			if (sender == Items)
			{
				DoAutoSize();
			}
			if (sender == Pointer)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.Markers)
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeItems()
		{
			return true;
		}

		private void ResetItems()
		{
			Items.Reset();
		}

		private bool ShouldSerializeUIControl()
		{
			return ((ISubClassBase)UIControl).ShouldSerialize();
		}

		private void ResetUIControl()
		{
			((ISubClassBase)UIControl).ResetToDefault();
		}

		private bool ShouldSerializeScaleDisplay()
		{
			return ((ISubClassBase)ScaleDisplay).ShouldSerialize();
		}

		private void ResetScaleDisplay()
		{
			((ISubClassBase)ScaleDisplay).ResetToDefault();
		}

		private bool ShouldSerializePointer()
		{
			return ((ISubClassBase)Pointer).ShouldSerialize();
		}

		private void ResetPointer()
		{
			((ISubClassBase)Pointer).ResetToDefault();
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private int GetNewIndex(MouseEventArgs e)
		{
			double num = (double)m_ScaleHeight / (double)(Items.Count - 1);
			int num2 = (int)(((double)(m_ScaleBottom - e.Y) + num / 2.0) / num);
			if (num2 < 0)
			{
				num2 = 0;
			}
			if (num2 >= Items.Count)
			{
				num2 = Items.Count - 1;
			}
			return num2;
		}

		protected override void InternalOnMouseLeft(MouseEventArgs e)
		{
			base.IsMouseDown = true;
			((Control)this).Focus();
			m_MouseDownY = e.Y;
			m_MouseDownIndex = Value.AsInteger;
			if (UIControl.MouseControlStyle == MouseControlStyleSwitchSlider.ClickToGoto)
			{
				Value.AsInteger = GetNewIndex(e);
			}
			InternalOnMouseMove(e);
		}

		protected override void InternalOnMouseMove(MouseEventArgs e)
		{
			if (!base.IsMouseDown)
			{
				return;
			}
			if (UIControl.MouseControlStyle == MouseControlStyleSwitchSlider.DragToDestination)
			{
				int num = m_ScaleHeight / (Items.Count - 1);
				int num2 = m_MouseDownIndex + (m_MouseDownY - e.Y) / num;
				if (num2 < 0)
				{
					num2 = 0;
				}
				if (num2 >= Items.Count)
				{
					num2 = Items.Count - 1;
				}
				if (Value.AsInteger != num2)
				{
					Value.AsInteger = num2;
					m_MouseDownY = e.Y;
					m_MouseDownIndex = Value.AsInteger;
				}
			}
			else if (UIControl.MouseControlStyle == MouseControlStyleSwitchSlider.ClickToGoto)
			{
				Value.AsInteger = GetNewIndex(e);
			}
		}

		protected override void InternalOnMouseUp(MouseEventArgs e)
		{
			base.IsMouseDown = false;
		}

		protected override bool IsInputKey(Keys keyData)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0002: Unknown result type (might be due to invalid IL or missing references)
			//IL_0005: Unknown result type (might be due to invalid IL or missing references)
			//IL_002b: Expected I4, but got Unknown
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			return (keyData - 33) switch
			{
				4 => true, 
				6 => true, 
				7 => true, 
				5 => true, 
				0 => true, 
				1 => true, 
				3 => true, 
				2 => true, 
				_ => base.IsInputKey(keyData), 
			};
		}

		protected override void InternalOnKeyDown(KeyEventArgs e)
		{
			//IL_0035: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Invalid comparison between Unknown and I4
			//IL_0045: Unknown result type (might be due to invalid IL or missing references)
			//IL_004c: Invalid comparison between Unknown and I4
			//IL_0055: Unknown result type (might be due to invalid IL or missing references)
			//IL_005c: Invalid comparison between Unknown and I4
			//IL_0065: Unknown result type (might be due to invalid IL or missing references)
			//IL_006c: Invalid comparison between Unknown and I4
			//IL_0075: Unknown result type (might be due to invalid IL or missing references)
			//IL_007c: Invalid comparison between Unknown and I4
			//IL_0085: Unknown result type (might be due to invalid IL or missing references)
			//IL_008c: Invalid comparison between Unknown and I4
			//IL_0095: Unknown result type (might be due to invalid IL or missing references)
			//IL_009c: Invalid comparison between Unknown and I4
			//IL_00a3: Unknown result type (might be due to invalid IL or missing references)
			//IL_00aa: Invalid comparison between Unknown and I4
			if (!UIControl.KeyboardEnabled)
			{
				return;
			}
			if (Items.Count == 0)
			{
				Value.AsInteger = -1;
				return;
			}
			int asInteger = Value.AsInteger;
			if ((int)e.KeyCode == 33)
			{
				asInteger += 2;
			}
			else if ((int)e.KeyCode == 38)
			{
				asInteger++;
			}
			else if ((int)e.KeyCode == 39)
			{
				asInteger++;
			}
			else if ((int)e.KeyCode == 34)
			{
				asInteger -= 2;
			}
			else if ((int)e.KeyCode == 40)
			{
				asInteger--;
			}
			else if ((int)e.KeyCode == 37)
			{
				asInteger--;
			}
			else if ((int)e.KeyCode == 36)
			{
				asInteger = 0;
			}
			else
			{
				if ((int)e.KeyCode != 35)
				{
					return;
				}
				asInteger = Items.Count - 1;
			}
			if (asInteger < 0)
			{
				asInteger = 0;
			}
			if (asInteger >= Items.Count)
			{
				asInteger = Items.Count - 1;
			}
			Value.AsInteger = asInteger;
		}

		protected override void InternalOnMouseWheel(MouseEventArgs e)
		{
			if (UIControl.MouseWheelEnabled)
			{
				int asInteger = Value.AsInteger;
				asInteger = ((e.Delta <= 0) ? (asInteger - 1) : (asInteger + 1));
				if (asInteger < 0)
				{
					asInteger = 0;
				}
				if (asInteger >= Items.Count)
				{
					asInteger = Items.Count - 1;
				}
				Value.AsInteger = asInteger;
			}
		}

		private void OnValueChanged(object sender, ValueIntegerEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueIntegerEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			m_InnerRect = p.DrawRectangle;
			int val = 0;
			val = Math.Max(val, (int)Math.Ceiling((float)Pointer.Height / 2f) + 2);
			val = Math.Max(val, (int)Math.Ceiling((float)p.Graphics.MeasureString(ScaleDisplay.TextActiveFont).Height / 2f) + 2);
			val = Math.Max(val, (int)Math.Ceiling((float)p.Graphics.MeasureString(ScaleDisplay.TextInactiveFont).Height / 2f) + 2);
			m_ScaleTop = p.Top + val;
			m_ScaleBottom = p.Bottom - val;
			m_ScaleHeight = m_ScaleBottom - m_ScaleTop;
			Rectangle r = ((ScaleDisplay.Direction != SideDirection.LeftToRight) ? new Rectangle(p.Right - 2 - Pointer.Width, m_ScaleTop - val / 2, Pointer.Width, m_ScaleHeight + val) : new Rectangle(2, m_ScaleTop - val / 2, Pointer.Width, m_ScaleHeight + val));
			int num = Value.AsInteger;
			if (num < 0)
			{
				num = 0;
			}
			if (num >= Items.Count)
			{
				num = Items.Count - 1;
			}
			int posPixels = m_ScaleBottom - num * m_ScaleHeight / (Items.Count - 1);
			((IPointerSlider)Pointer).Draw(p, r, posPixels, base.IsMouseDown, ScaleDisplay.Direction);
			DrawStringFormat genericTypographic = DrawStringFormat.GenericTypographic;
			genericTypographic.LineAlignment = (StringAlignment)0;
			genericTypographic.Alignment = (StringAlignment)0;
			if (ScaleDisplay.Visible)
			{
				for (int i = 0; i < Items.Count; i++)
				{
					Font font;
					Color color;
					if (i == num)
					{
						font = ScaleDisplay.TextActiveFont;
						color = ScaleDisplay.TextActiveForeColor;
					}
					else
					{
						font = ScaleDisplay.TextInactiveFont;
						color = ScaleDisplay.TextInactiveForeColor;
					}
					posPixels = ((Items.Count >= 2) ? (m_ScaleBottom - i * m_ScaleHeight / (Items.Count - 1)) : ((m_ScaleTop + m_ScaleBottom) / 2));
					Size size = p.Graphics.MeasureString(Items[i].Text, font, typographic: true);
					int num2 = ((ScaleDisplay.Direction != SideDirection.LeftToRight) ? (r.Left - 1) : (r.Right + 1));
					if (ScaleDisplay.Markers.Style != MarkerStyleLabel.None)
					{
						Point centerPoint = ((ScaleDisplay.Direction != SideDirection.LeftToRight) ? new Point(num2 - ScaleDisplay.Margin - ScaleDisplay.Markers.Size, posPixels) : new Point(num2 + ScaleDisplay.Margin + ScaleDisplay.Markers.Size, posPixels));
						((IScaleDiscreetMarker)ScaleDisplay.Markers).Draw(p, centerPoint, base.BackColor);
						num2 = ((ScaleDisplay.Direction != SideDirection.LeftToRight) ? (num2 + (-ScaleDisplay.Margin - 2 * ScaleDisplay.Markers.Size - 1)) : (num2 + (ScaleDisplay.Margin + 2 * ScaleDisplay.Markers.Size + 1)));
					}
					Rectangle r2 = ((ScaleDisplay.Direction != SideDirection.LeftToRight) ? new Rectangle(num2 - ScaleDisplay.TextMargin - size.Width, posPixels - size.Height / 2, size.Width + 1, size.Height + 1) : new Rectangle(num2 + ScaleDisplay.TextMargin, posPixels - size.Height / 2, size.Width + 1, size.Height + 1));
					p.Graphics.DrawString(Items[i].Text, font, p.Graphics.Brush(color), r2, genericTypographic);
				}
			}
			if (UIControl.FocusRectangleShow && ((Control)this).Focused)
			{
				p.Graphics.DrawFocusRectangle(p.PenRectangle, base.BackColor);
			}
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class SwitchSliderEditorPlugIn : PlugInStandard
	{
		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private CheckBox AutoSizeCheckBox;

		private FocusLabel label1;

		private FocusLabel label4;

		private FontButton FontButton;

		private ColorPicker ForeColorPicker;

		private ColorPicker BackColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public SwitchSliderEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			FontButton = new FontButton();
			AutoSizeCheckBox = new CheckBox();
			ForeColorPicker = new ColorPicker();
			label1 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			label4 = new FocusLabel();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(103, 114);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(152, 112);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 4;
			((Control)FontButton).Location = new Point(304, 56);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 2;
			((Control)AutoSizeCheckBox).Location = new Point(304, 112);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 5;
			AutoSizeCheckBox.Text = "Auto Size";
			((Control)ForeColorPicker).Location = new Point(152, 56);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(136, 21);
			((Control)ForeColorPicker).TabIndex = 1;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(91, 83);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(152, 80);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 3;
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label4).Location = new Point(93, 59);
			((Control)label4).Name = "label4";
			label4.Size = new Size(59, 15);
			label4.Text = "Fore Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(152, 8);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(116, 10);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(192, 146);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(152, 144);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 6;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(48, 146);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Name = "SwitchSliderEditorPlugIn";
			((Control)this).Size = new Size(464, 200);
			base.Title = "Switch Slider Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueIntegerEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new PointerSliderEditorPlugIn(), "Pointer", sameLevel: false);
			AddSubPlugIn(new ScaleDiscreetItemCollectionEditorPlugIn(), "Items", sameLevel: false);
			AddSubPlugIn(new ScaleDisplayDiscreetLinearEditorPlugIn(), "Scale Display", sameLevel: false);
			AddSubPlugIn(new UIControlSwitchSliderEditorPlugIn(), "UI Control", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as SwitchSlider).Value;
			base.SubPlugIns[1].Value = (base.Value as SwitchSlider).Pointer;
			base.SubPlugIns[2].Value = (base.Value as SwitchSlider).Items;
			base.SubPlugIns[3].Value = (base.Value as SwitchSlider).ScaleDisplay;
			base.SubPlugIns[4].Value = (base.Value as SwitchSlider).UIControl;
			base.SubPlugIns[5].Value = (base.Value as SwitchSlider).Border;
		}
	}
	public class SwitchToggleDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("Font");
			properties.Remove("ForeColor");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("FontChanged");
			events.Remove("ForeColorChanged");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[Designer(typeof(SwitchToggleDesigner))]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[DefaultEvent("ValueChanged")]
	[ToolboxBitmap(typeof(Access), "SwitchToggle.bmp")]
	[Description("Iocomp Switch Toggle ")]
	[DefaultProperty("Name")]
	[DesignerCategory("code")]
	public class SwitchToggle : ControlBase
	{
		private Rectangle m_SwitchRect;

		private Rectangle m_SwitchDestRect;

		private Rectangle m_DragDestRect;

		private PointerSwitchToggle m_Switch;

		private UIControlSwitchToggle m_UIControl;

		private ValueBoolean m_Value;

		[Category("Iocomp")]
		[Description("Value Properties")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ValueBoolean Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsBoolean = value.AsBoolean;
			}
		}

		[Description("Switch properties")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		public PointerSwitchToggle Switch => m_Switch;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		[Description("UIControl properties")]
		public UIControlSwitchToggle UIControl => m_UIControl;

		[Category("Iocomp")]
		public event ValueBooleanEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueBooleanEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new SwitchToggleEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Switch Toggle";
		}

		public SwitchToggle()
		{
			m_License = LicenseManager.Validate(typeof(SwitchToggle), this);
			DoCreate();
		}

		~SwitchToggle()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Value = new ValueBoolean();
			AddSubClass(Value);
			m_Switch = new PointerSwitchToggle();
			AddSubClass(Switch);
			m_UIControl = new UIControlSwitchToggle();
			AddSubClass(UIControl);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			base.Border.Style = BorderStyleControl.Sunken;
			Switch.Height = 50;
			Switch.Bevel.MarginEdge = 1;
			Switch.Bevel.Style = BevelStyle.Raised;
			Switch.Bevel.Thickness = BevelThickness.X3;
			Switch.Bevel.Visible = true;
			UIControl.MouseWheelEnabled = true;
			UIControl.KeyboardEnabled = true;
			UIControl.FocusRectangleShow = true;
			UIControl.MouseControlStyle = MouseControlStyleSwitchToggle.ClickToToggle;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(28, 52);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializeSwitch()
		{
			return ((ISubClassBase)Switch).ShouldSerialize();
		}

		private void ResetSwitch()
		{
			((ISubClassBase)Switch).ResetToDefault();
		}

		private bool ShouldSerializeUIControl()
		{
			return ((ISubClassBase)UIControl).ShouldSerialize();
		}

		private void ResetUIControl()
		{
			((ISubClassBase)UIControl).ResetToDefault();
		}

		private void OnValueChanged(object sender, ValueBooleanEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueBooleanEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void InternalOnMouseLeft(MouseEventArgs e)
		{
			bool isMouseDown = false;
			if (UIControl.MouseControlStyle == MouseControlStyleSwitchToggle.ClickDestination)
			{
				if (m_SwitchDestRect.Contains(e.X, e.Y))
				{
					isMouseDown = true;
				}
			}
			else if (UIControl.MouseControlStyle == MouseControlStyleSwitchToggle.DragToDestination)
			{
				if (m_SwitchRect.Contains(e.X, e.Y))
				{
					isMouseDown = true;
				}
			}
			else if (UIControl.MouseControlStyle == MouseControlStyleSwitchToggle.ClickToToggle && (m_SwitchRect.Contains(e.X, e.Y) || m_SwitchDestRect.Contains(e.X, e.Y)))
			{
				isMouseDown = true;
			}
			base.IsMouseDown = isMouseDown;
			((Control)this).Focus();
		}

		protected override void InternalOnMouseMove(MouseEventArgs e)
		{
			if (base.IsMouseDown && UIControl.MouseControlStyle == MouseControlStyleSwitchToggle.DragToDestination && m_DragDestRect.Contains(e.X, e.Y))
			{
				Value.AsBoolean = !Value.AsBoolean;
			}
		}

		protected override void InternalOnMouseUp(MouseEventArgs e)
		{
			if (!base.IsMouseDown)
			{
				return;
			}
			base.IsMouseDown = false;
			if (UIControl.MouseControlStyle == MouseControlStyleSwitchToggle.ClickDestination)
			{
				if (m_SwitchDestRect.Contains(e.X, e.Y))
				{
					Value.AsBoolean = !Value.AsBoolean;
				}
			}
			else if (UIControl.MouseControlStyle == MouseControlStyleSwitchToggle.ClickToToggle && (m_SwitchRect.Contains(e.X, e.Y) || m_SwitchDestRect.Contains(e.X, e.Y)))
			{
				Value.AsBoolean = !Value.AsBoolean;
			}
		}

		protected override void InternalOnMouseWheel(MouseEventArgs e)
		{
			if (UIControl.MouseWheelEnabled)
			{
				Value.AsBoolean = e.Delta > 0;
			}
		}

		protected override void InternalOnKeyDown(KeyEventArgs e)
		{
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Invalid comparison between Unknown and I4
			if (UIControl.KeyboardEnabled && (int)e.KeyCode == 32)
			{
				base.IsKeyDown = true;
				base.IsMouseDown = false;
			}
		}

		protected override void InternalOnKeyUp(KeyEventArgs e)
		{
			//IL_0026: Unknown result type (might be due to invalid IL or missing references)
			//IL_002d: Invalid comparison between Unknown and I4
			if (UIControl.KeyboardEnabled && base.IsKeyDown)
			{
				base.IsKeyDown = false;
				base.IsMouseDown = false;
				if ((int)e.KeyCode == 32)
				{
					Value.AsBoolean = !Value.AsBoolean;
				}
			}
		}

		private void CalcRects(PaintArgs p)
		{
			int num = Switch.Height * p.Height / 100;
			num = (num - 3) / 3 * 3 + 3;
			if (m_Value.AsBoolean)
			{
				ref Rectangle switchRect = ref m_SwitchRect;
				switchRect = new Rectangle(p.Left, p.Top, p.Width, num);
				ref Rectangle switchDestRect = ref m_SwitchDestRect;
				switchDestRect = new Rectangle(p.Left, num, p.Width, p.Height - num);
				ref Rectangle dragDestRect = ref m_DragDestRect;
				dragDestRect = new Rectangle(p.Left, p.Height / 2, p.Width, p.Height / 2);
			}
			else
			{
				ref Rectangle switchRect2 = ref m_SwitchRect;
				switchRect2 = new Rectangle(p.Left, p.Bottom - num, p.Width, num);
				ref Rectangle switchDestRect2 = ref m_SwitchDestRect;
				switchDestRect2 = new Rectangle(p.Left, p.Top, p.Width, p.Height - num);
				ref Rectangle dragDestRect2 = ref m_DragDestRect;
				dragDestRect2 = new Rectangle(p.Left, p.Top, p.Width, p.Height / 2);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			CalcRects(p);
			iRectangle iRectangle = new iRectangle(m_SwitchRect);
			BorderSimple.Draw(p, iRectangle.Rectangle, BorderStyleSimple.Raised, base.BackColor);
			iRectangle.Inflate(-2, -2);
			if (base.IsMouseDown)
			{
				p.Graphics.FillRectangle(p.Graphics.Brush(iColors.Lighten3(base.BackColor)), iRectangle.Rectangle);
			}
			iRectangle.Top++;
			iRectangle.Height -= 2;
			iRectangle.Right--;
			((IBevel)Switch.Bevel).DrawRange(p, iRectangle.Rectangle, base.BackColor, (Orientation)0);
			if (UIControl.FocusRectangleShow && ((Control)this).Focused)
			{
				Rectangle r = new Rectangle(p.DrawRectangle.Left, p.DrawRectangle.Top, p.DrawRectangle.Width - 1, p.DrawRectangle.Height - 1);
				p.Graphics.DrawFocusRectangle(r, base.BackColor);
			}
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class SwitchToggleEditorPlugIn : PlugInStandard
	{
		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private FocusLabel label1;

		private CheckBox AutoSizeCheckBox;

		private ColorPicker BackColorPicker;

		private CheckBox ValueCheckBox;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public SwitchToggleEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			label1 = new FocusLabel();
			BackColorPicker = new ColorPicker();
			AutoSizeCheckBox = new CheckBox();
			ValueCheckBox = new CheckBox();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(63, 90);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(112, 88);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 2;
			label1.LoadingBegin();
			label1.FocusControl = (Control)(object)BackColorPicker;
			((Control)label1).Location = new Point(51, 59);
			((Control)label1).Name = "label1";
			label1.Size = new Size(61, 15);
			label1.Text = "Back Color";
			label1.UpdateFrameRate = 50.0;
			label1.LoadingEnd();
			((Control)BackColorPicker).Location = new Point(112, 56);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 1;
			((Control)AutoSizeCheckBox).Location = new Point(264, 88);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 3;
			AutoSizeCheckBox.Text = "Auto Size";
			((Control)ValueCheckBox).Location = new Point(112, 8);
			((Control)ValueCheckBox).Name = "ValueCheckBox";
			ValueCheckBox.PropertyName = "Value";
			((Control)ValueCheckBox).TabIndex = 0;
			ValueCheckBox.Text = "Value";
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(152, 122);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(112, 120);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 4;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(8, 122);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)ValueCheckBox);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Name = "SwitchToggleEditorPlugIn";
			((Control)this).Size = new Size(432, 152);
			base.Title = "Switch Toggle Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueBooleanEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new PointerSwitchToggleEditorPlugIn(), "Switch", sameLevel: false);
			AddSubPlugIn(new UIControlSwitchToggleEditorPlugIn(), "UI Control", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as SwitchToggle).Value;
			base.SubPlugIns[1].Value = (base.Value as SwitchToggle).Switch;
			base.SubPlugIns[2].Value = (base.Value as SwitchToggle).UIControl;
			base.SubPlugIns[3].Value = (base.Value as SwitchToggle).Border;
		}
	}
	public class ThermometerDesigner : ControlDesigner
	{
		protected override void PostFilterProperties(IDictionary properties)
		{
			base.PostFilterProperties(properties);
			properties.Remove("BackgroundImage");
			properties.Remove("ImeMode");
			properties.Remove("RightToLeft");
			properties.Remove("Text");
			properties.Remove("TabStop");
			properties.Remove("TabIndex");
		}

		protected override void PostFilterEvents(IDictionary events)
		{
			base.PostFilterEvents(events);
			events.Remove("BackgroundImageChanged");
			events.Remove("ImeModeChanged");
			events.Remove("RightToLeftChanged");
			events.Remove("TextChanged");
			events.Remove("TabStopChanged");
			events.Remove("TabIndexChanged");
			events.Remove("KeyDown");
			events.Remove("KeyUp");
			events.Remove("KeyPress");
			events.Remove("Enter");
			events.Remove("Leave");
			events.Remove("CausesValidationChanged");
			events.Remove("Validating");
			events.Remove("Validated");
		}
	}
}
namespace Iocomp.Instrumentation.Standard
{
	[DesignerCategory("code")]
	[ToolboxBitmap(typeof(Access), "Thermometer.bmp")]
	[LicenseProvider(typeof(IocompLicenseProviderStd))]
	[DefaultEvent("ValueChanged")]
	[Designer(typeof(ThermometerDesigner))]
	[Description("Thermometer")]
	[DefaultProperty("Name")]
	public class Thermometer : ControlBase
	{
		private ValueDouble m_Value;

		private ScaleRangeLinear m_ScaleRange;

		private ScaleDisplayLinear m_ScaleDisplay;

		private IScaleDisplayLinear I_Display;

		private PointerThermometer m_Pointer;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Category("Iocomp")]
		[Description("")]
		public ValueDouble Value
		{
			get
			{
				return m_Value;
			}
			set
			{
				m_Value.AsDouble = value.AsDouble;
			}
		}

		[Category("Iocomp")]
		[Description("Pointer Properties.")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public PointerThermometer Pointer => m_Pointer;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		[Category("Iocomp")]
		public ScaleRangeLinear ScaleRange => m_ScaleRange;

		[Category("Iocomp")]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Description("")]
		public ScaleDisplayLinear ScaleDisplay => m_ScaleDisplay;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueChanged;

		[Category("Iocomp")]
		public event ValueDoubleEventHandler ValueBeforeChange;

		protected override PlugInStandard GetPlugIn()
		{
			return new ThermometerEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "Thermometer";
		}

		public Thermometer()
		{
			m_License = LicenseManager.Validate(typeof(Thermometer), this);
			DoCreate();
		}

		~Thermometer()
		{
			((Component)(object)this).Dispose();
		}

		protected override void CreateObjects()
		{
			m_Value = new ValueDouble();
			AddSubClass(Value);
			m_ScaleRange = new ScaleRangeLinear();
			AddSubClass(ScaleRange);
			m_ScaleDisplay = new ScaleDisplayLinear();
			AddSubClass(ScaleDisplay);
			I_Display = ScaleDisplay;
			m_Pointer = new PointerThermometer();
			AddSubClass(Pointer);
			Value.Changing += OnValueBeforeChange;
			Value.Changed += OnValueChanged;
			I_Display.Range = m_ScaleRange;
		}

		protected override void SetDefaults()
		{
			base.SetDefaults();
			Pointer.ForeColor = Color.Red;
			Pointer.BackColor = Color.Empty;
			Pointer.BulbWidth = 24;
			Pointer.TubeWidth = 12;
			Pointer.Alignment = AlignmentSide.AutoCenter;
			ScaleRange.Span = 100.0;
			ScaleRange.Min = 0.0;
			ScaleRange.Reverse = false;
			ScaleDisplay.GeneratorAuto.DesiredIncrement = 0.0;
			ScaleDisplay.GeneratorAuto.MinTextSpacing = 1.0;
			ScaleDisplay.GeneratorAuto.MinorCount = 4;
			ScaleDisplay.GeneratorAuto.MidIncluded = false;
			ScaleDisplay.GeneratorFixed.MinorCount = 4;
			ScaleDisplay.GeneratorFixed.MidIncluded = false;
			ScaleDisplay.GeneratorFixed.MajorCount = 6;
			ScaleDisplay.AntiAliasEnabled = false;
			ScaleDisplay.GeneratorStyle = ScaleGeneratorStyle.Auto;
			ScaleDisplay.Direction = SideDirection.LeftToRight;
			ScaleDisplay.Margin = 5;
			ScaleDisplay.StartRefValue = 0.0;
			ScaleDisplay.StartRefEnabled = false;
			ScaleDisplay.TextRotation = TextRotation.X000;
			ScaleDisplay.TextAlignment = (StringAlignment)0;
			ScaleDisplay.TextWidthMinValue = 0.0;
			ScaleDisplay.TextWidthMinAuto = false;
			ScaleDisplay.LineInnerVisible = false;
			ScaleDisplay.LineOuterVisible = false;
			ScaleDisplay.Visible = true;
			ScaleDisplay.TextFormatting.Precision = 1;
			ScaleDisplay.TextFormatting.PrecisionStyle = PrecisionStyle.FixedDecimalPoints;
			ScaleDisplay.TextFormatting.UnitsText = "";
			ScaleDisplay.TextFormatting.Style = TextFormatDoubleStyle.Number;
			ScaleDisplay.TextFormatting.DateTimeFormat = "hh:mm:ss";
			ScaleDisplay.TickMinor.Alignment = AlignmentStyle.Near;
			ScaleDisplay.TickMinor.Length = 3;
			ScaleDisplay.TickMinor.Color = Color.Black;
			ScaleDisplay.TickMinor.Thickness = 1;
			ScaleDisplay.TickMid.Length = 5;
			ScaleDisplay.TickMid.Font = null;
			ScaleDisplay.TickMid.ForeColor = Color.Empty;
			ScaleDisplay.TickMid.TextVisible = true;
			ScaleDisplay.TickMid.TextMargin = 2;
			ScaleDisplay.TickMid.Alignment = AlignmentStyle.Near;
			ScaleDisplay.TickMid.Color = Color.Black;
			ScaleDisplay.TickMid.Thickness = 1;
			ScaleDisplay.TickMajor.Length = 7;
			ScaleDisplay.TickMajor.Font = null;
			ScaleDisplay.TickMajor.ForeColor = Color.Empty;
			ScaleDisplay.TickMajor.TextVisible = true;
			ScaleDisplay.TickMajor.TextMargin = 2;
			ScaleDisplay.TickMajor.Color = Color.Black;
			ScaleDisplay.TickMajor.Thickness = 1;
		}

		protected override Size GetDefaultSize()
		{
			return new Size(66, 203);
		}

		protected override Size CalculateAutoSize(int innerWidth, int innerHeight)
		{
			if (base.Loading)
			{
				return Size.Empty;
			}
			Graphics val = ((Control)this).CreateGraphics();
			PaintArgs p = new PaintArgs(val, base.InnerRectangle, Color.Empty);
			I_Display.SetClipEnds(0, innerHeight - Pointer.BulbWidth);
			I_Display.SetBoundsEnds(0, innerHeight - Pointer.BulbWidth);
			I_Display.Generate(p);
			val.Dispose();
			float num = ((IPointerThermometer)Pointer).TubeRight;
			float num2 = num + (float)I_Display.MaxDepth + (float)ScaleDisplay.Margin;
			return new Size((int)num2, 0);
		}

		protected override void PropertyChangedHook(object sender, string propertyName)
		{
			if (sender == ScaleDisplay)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.GeneratorAuto)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.GeneratorFixed)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TickMid)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TickMajor)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TickMinor)
			{
				DoAutoSize();
			}
			if (sender == ScaleDisplay.TextFormatting)
			{
				DoAutoSize();
			}
			if (sender == ScaleRange)
			{
				DoAutoSize();
			}
			if (sender == Pointer)
			{
				DoAutoSize();
			}
			if (sender == this && propertyName == "Font")
			{
				DoAutoSize();
			}
			base.PropertyChangedHook(sender, propertyName);
		}

		private bool ShouldSerializeValue()
		{
			return ((ISubClassBase)Value).ShouldSerialize();
		}

		private void ResetValue()
		{
			((ISubClassBase)Value).ResetToDefault();
		}

		private bool ShouldSerializePointer()
		{
			return ((ISubClassBase)Pointer).ShouldSerialize();
		}

		private void ResetPointer()
		{
			((ISubClassBase)Pointer).ResetToDefault();
		}

		private bool ShouldSerializeScaleRange()
		{
			return ((ISubClassBase)ScaleRange).ShouldSerialize();
		}

		private void ResetScaleRange()
		{
			((ISubClassBase)ScaleRange).ResetToDefault();
		}

		private bool ShouldSerializeScaleDisplay()
		{
			return ((ISubClassBase)ScaleDisplay).ShouldSerialize();
		}

		private void ResetScaleDisplay()
		{
			((ISubClassBase)ScaleDisplay).ResetToDefault();
		}

		private void OnValueChanged(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueChanged != null)
			{
				this.ValueChanged(this, e);
			}
		}

		private void OnValueBeforeChange(object sender, ValueDoubleEventArgs e)
		{
			if (this.ValueBeforeChange != null)
			{
				this.ValueBeforeChange(this, e);
			}
		}

		protected override void DoPaint(PaintArgs p)
		{
			//IL_0270: Unknown result type (might be due to invalid IL or missing references)
			//IL_0277: Expected O, but got Unknown
			//IL_0308: Unknown result type (might be due to invalid IL or missing references)
			//IL_030f: Expected O, but got Unknown
			//IL_0379: Unknown result type (might be due to invalid IL or missing references)
			//IL_0380: Expected O, but got Unknown
			//IL_038a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0391: Expected O, but got Unknown
			p.Graphics.SmoothingMode = (SmoothingMode)4;
			I_Display.SetClipEnds(p.Top, p.Bottom - Pointer.BulbWidth);
			I_Display.SetBoundsEnds(p.Top, p.Bottom - Pointer.BulbWidth);
			I_Display.Generate(p);
			int totalWidth = ((IPointerThermometer)Pointer).TotalWidth;
			int num = I_Display.MaxDepth + ScaleDisplay.Margin;
			int num2 = Math.Max(((IPointerThermometer)Pointer).TubeRight + num, Pointer.BulbWidth);
			int num3 = p.Width - num2;
			int num4 = ((Pointer.Alignment == AlignmentSide.Center) ? p.CenterX : ((Pointer.Alignment == AlignmentSide.Side) ? ((ScaleDisplay.Direction != SideDirection.LeftToRight) ? (p.Right - totalWidth / 2) : (p.Left + totalWidth / 2)) : ((ScaleDisplay.Direction != SideDirection.LeftToRight) ? (p.Right - totalWidth / 2 - num3 / 2) : (p.Left + totalWidth / 2 + num3 / 2))));
			int x = num4 - Pointer.TubeWidth / 2;
			_ = Pointer.TubeWidth;
			Rectangle r = new Rectangle(x, p.Top, Pointer.TubeWidth, p.Height - Pointer.BulbWidth / 2);
			Rectangle rectangle = new Rectangle(num4 - Pointer.BulbWidth / 2, p.Bottom - Pointer.BulbWidth, Pointer.BulbWidth - 1, Pointer.BulbWidth - 1);
			if (ScaleDisplay.Direction == SideDirection.LeftToRight)
			{
				I_Display.EdgeRef = r.Right + ScaleDisplay.Margin;
			}
			else
			{
				I_Display.EdgeRef = r.Left - ScaleDisplay.Margin;
			}
			int num5 = ScaleDisplay.ValueToPixels(Value.AsDouble) - 1;
			if (num5 < r.Top)
			{
				num5 = r.Top;
			}
			if (num5 > r.Bottom)
			{
				num5 = r.Bottom;
			}
			Color colorStop = iColors.Darken2(Pointer.BackColor);
			Color colorStart = iColors.ToBright(Pointer.BackColor);
			GraphicsPath val = new GraphicsPath();
			val.AddArc(r.Left, r.Top, Pointer.TubeWidth, Pointer.TubeWidth, 180f, 180f);
			val.AddLine(r.Right, r.Bottom, r.Left, r.Bottom);
			p.Graphics.FillTube3D(r, val, colorStop, colorStart, (Orientation)1, 0.25f, sigma: false);
			colorStop = iColors.Darken2(Pointer.ForeColor);
			colorStart = iColors.ToBright(Pointer.ForeColor);
			GraphicsPath val2 = new GraphicsPath();
			val2.AddArc(r.Left, num5, Pointer.TubeWidth, Pointer.TubeWidth, 180f, 180f);
			val2.AddLine(r.Right, r.Bottom, r.Left, r.Bottom);
			p.Graphics.FillTube3D(r, val2, colorStop, colorStart, (Orientation)1, 0.25f, sigma: false);
			GraphicsPath val3 = new GraphicsPath();
			val3.AddEllipse(rectangle);
			PathGradientBrush val4 = new PathGradientBrush(val3);
			val4.CenterColor = colorStart;
			val4.CenterPoint = new PointF((float)num4 - (float)Pointer.TubeWidth / 4f, (float)p.Bottom - (float)Pointer.BulbWidth / 2f - (float)Pointer.TubeWidth / 4f);
			val4.SurroundColors = new Color[1] { colorStop };
			p.Graphics.FillPath((Brush)(object)val4, val3);
			p.Graphics.DrawEllipse(p.Graphics.Pen(colorStop), rectangle);
			I_Display.Draw(p);
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class ThermometerEditorPlugIn : PlugInStandard
	{
		private FocusLabel label6;

		private ComboBox RotationComboBox;

		private CheckBox AutoSizeCheckBox;

		private FocusLabel label3;

		private FocusLabel label4;

		private FontButton FontButton;

		private ColorPicker ForeColorPicker;

		private ColorPicker BackColorPicker;

		private EditBox NameTextBox;

		private FocusLabel focusLabel1;

		private FocusLabel focusLabel3;

		private EditBox UpdateFrameRateTextBox;

		private FocusLabel focusLabel2;

		private Container components = null;

		public ThermometerEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			label6 = new FocusLabel();
			RotationComboBox = new ComboBox();
			AutoSizeCheckBox = new CheckBox();
			FontButton = new FontButton();
			ForeColorPicker = new ColorPicker();
			BackColorPicker = new ColorPicker();
			label3 = new FocusLabel();
			label4 = new FocusLabel();
			NameTextBox = new EditBox();
			focusLabel1 = new FocusLabel();
			focusLabel3 = new FocusLabel();
			UpdateFrameRateTextBox = new EditBox();
			focusLabel2 = new FocusLabel();
			((Control)this).SuspendLayout();
			label6.LoadingBegin();
			label6.FocusControl = (Control)(object)RotationComboBox;
			((Control)label6).Location = new Point(87, 114);
			((Control)label6).Name = "label6";
			label6.Size = new Size(49, 15);
			label6.Text = "Rotation";
			label6.UpdateFrameRate = 50.0;
			label6.LoadingEnd();
			((ComboBox)RotationComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)RotationComboBox).Location = new Point(136, 112);
			((Control)RotationComboBox).Name = "RotationComboBox";
			RotationComboBox.PropertyName = "Rotation";
			((Control)RotationComboBox).Size = new Size(136, 21);
			((Control)RotationComboBox).TabIndex = 4;
			((Control)AutoSizeCheckBox).Location = new Point(288, 112);
			((Control)AutoSizeCheckBox).Name = "AutoSizeCheckBox";
			AutoSizeCheckBox.PropertyName = "AutoSize";
			((Control)AutoSizeCheckBox).TabIndex = 5;
			AutoSizeCheckBox.Text = "Auto Size";
			((Control)FontButton).Location = new Point(288, 56);
			((Control)FontButton).Name = "FontButton";
			FontButton.PropertyName = "Font";
			((Control)FontButton).TabIndex = 2;
			((Control)ForeColorPicker).Location = new Point(136, 56);
			((Control)ForeColorPicker).Name = "ForeColorPicker";
			ForeColorPicker.PropertyName = "ForeColor";
			((Control)ForeColorPicker).Size = new Size(136, 21);
			((Control)ForeColorPicker).TabIndex = 1;
			((Control)BackColorPicker).Location = new Point(136, 80);
			((Control)BackColorPicker).Name = "BackColorPicker";
			BackColorPicker.PropertyName = "BackColor";
			((Control)BackColorPicker).Size = new Size(136, 21);
			((Control)BackColorPicker).TabIndex = 3;
			label3.LoadingBegin();
			label3.FocusControl = (Control)(object)BackColorPicker;
			((Control)label3).Location = new Point(75, 83);
			((Control)label3).Name = "label3";
			label3.Size = new Size(61, 15);
			label3.Text = "Back Color";
			label3.UpdateFrameRate = 50.0;
			label3.LoadingEnd();
			label4.LoadingBegin();
			label4.FocusControl = (Control)(object)ForeColorPicker;
			((Control)label4).Location = new Point(77, 59);
			((Control)label4).Name = "label4";
			label4.Size = new Size(59, 15);
			label4.Text = "Fore Color";
			label4.UpdateFrameRate = 50.0;
			label4.LoadingEnd();
			NameTextBox.LoadingBegin();
			((Control)NameTextBox).Location = new Point(136, 16);
			((Control)NameTextBox).Name = "NameTextBox";
			NameTextBox.PropertyName = "Value";
			NameTextBox.Size = new Size(136, 20);
			((Control)NameTextBox).TabIndex = 0;
			NameTextBox.LoadingEnd();
			focusLabel1.LoadingBegin();
			focusLabel1.FocusControl = (Control)(object)NameTextBox;
			((Control)focusLabel1).Location = new Point(100, 18);
			((Control)focusLabel1).Name = "focusLabel1";
			focusLabel1.Size = new Size(36, 15);
			focusLabel1.Text = "Value";
			focusLabel1.UpdateFrameRate = 50.0;
			focusLabel1.LoadingEnd();
			focusLabel3.LoadingBegin();
			focusLabel3.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			focusLabel3.FocusControlAlignment = AlignmentQuadSide.Right;
			((Control)focusLabel3).Location = new Point(176, 146);
			((Control)focusLabel3).Name = "focusLabel3";
			focusLabel3.Size = new Size(60, 15);
			focusLabel3.Text = "(Max = 50)";
			focusLabel3.UpdateFrameRate = 50.0;
			focusLabel3.LoadingEnd();
			UpdateFrameRateTextBox.LoadingBegin();
			((Control)UpdateFrameRateTextBox).Location = new Point(136, 144);
			((Control)UpdateFrameRateTextBox).Name = "UpdateFrameRateTextBox";
			UpdateFrameRateTextBox.PropertyName = "UpdateFrameRate";
			UpdateFrameRateTextBox.Size = new Size(40, 20);
			((Control)UpdateFrameRateTextBox).TabIndex = 6;
			UpdateFrameRateTextBox.LoadingEnd();
			focusLabel2.LoadingBegin();
			focusLabel2.FocusControl = (Control)(object)UpdateFrameRateTextBox;
			((Control)focusLabel2).Location = new Point(32, 146);
			((Control)focusLabel2).Name = "focusLabel2";
			focusLabel2.Size = new Size(104, 15);
			focusLabel2.Text = "Update Frame Rate";
			focusLabel2.UpdateFrameRate = 50.0;
			focusLabel2.LoadingEnd();
			((Control)this).Controls.Add((Control)(object)focusLabel3);
			((Control)this).Controls.Add((Control)(object)UpdateFrameRateTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel2);
			((Control)this).Controls.Add((Control)(object)NameTextBox);
			((Control)this).Controls.Add((Control)(object)focusLabel1);
			((Control)this).Controls.Add((Control)(object)label4);
			((Control)this).Controls.Add((Control)(object)label3);
			((Control)this).Controls.Add((Control)(object)ForeColorPicker);
			((Control)this).Controls.Add((Control)(object)BackColorPicker);
			((Control)this).Controls.Add((Control)(object)AutoSizeCheckBox);
			((Control)this).Controls.Add((Control)(object)FontButton);
			((Control)this).Controls.Add((Control)(object)label6);
			((Control)this).Controls.Add((Control)(object)RotationComboBox);
			((Control)this).Name = "ThermometerEditorPlugIn";
			((Control)this).Size = new Size(536, 184);
			base.Title = "Thermometer Editor";
			((Control)this).ResumeLayout(false);
		}

		public override void CreateSubPlugIns()
		{
			AddSubPlugIn(new ValueDoubleEditorPlugIn(), "Value", sameLevel: false);
			AddSubPlugIn(new PointerThermometerEditorPlugIn(), "Pointer", sameLevel: false);
			AddSubPlugIn(new ScaleDisplayLinearEditorPlugIn(), "Scale Display", sameLevel: false);
			AddSubPlugIn(new ScaleRangeLinearEditorPlugIn(), "Scale Range", sameLevel: false);
			AddSubPlugIn(new BorderControlEditorPlugIn(), "Border", sameLevel: false);
		}

		public override void SetSubPlugInsValue()
		{
			base.SubPlugIns[0].Value = (base.Value as Thermometer).Value;
			base.SubPlugIns[1].Value = (base.Value as Thermometer).Pointer;
			base.SubPlugIns[2].Value = (base.Value as Thermometer).ScaleDisplay;
			base.SubPlugIns[3].Value = (base.Value as Thermometer).ScaleRange;
			base.SubPlugIns[4].Value = (base.Value as Thermometer).Border;
		}
	}
}
namespace Iocomp.Types
{
	public enum MouseControlStyleKnob
	{
		ClickToGoto,
		DragToDestination
	}
}
namespace Iocomp.Classes
{
	[DefaultProperty("MouseControlStyle")]
	[Description("Contains properties to control the knob's user interface characteristics.")]
	public sealed class UIControlKnob : UIControl
	{
		private MouseControlStyleKnob m_MouseControlStyle;

		[Description("Specifies how the user can use the mouse to move the pointer.")]
		public MouseControlStyleKnob MouseControlStyle
		{
			get
			{
				return m_MouseControlStyle;
			}
			set
			{
				PropertyUpdateDefault("MouseControlStyle", value);
				if (MouseControlStyle != value)
				{
					m_MouseControlStyle = value;
					DoPropertyChange(this, "MouseControlStyle");
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new UIControlKnobEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "UI Control";
		}

		public UIControlKnob()
		{
			DoCreate();
		}

		private bool ShouldSerializeMouseControlStyle()
		{
			return PropertyShouldSerialize("MouseControlStyle");
		}

		private void ResetMouseControlStyle()
		{
			PropertyReset("MouseControlStyle");
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class UIControlKnobEditorPlugIn : PlugInStandard
	{
		private CheckBox KeyboardEnabledCheckBox;

		private FocusLabel label2;

		private ComboBox MouseControlStyleComboBox;

		private CheckBox MouseWheelEnabledCheckBox;

		private CheckBox FocusRectangleShowCheckBox;

		private Container components = null;

		public UIControlKnobEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			KeyboardEnabledCheckBox = new CheckBox();
			MouseControlStyleComboBox = new ComboBox();
			label2 = new FocusLabel();
			MouseWheelEnabledCheckBox = new CheckBox();
			FocusRectangleShowCheckBox = new CheckBox();
			((Control)this).SuspendLayout();
			((Control)KeyboardEnabledCheckBox).Location = new Point(112, 40);
			((Control)KeyboardEnabledCheckBox).Name = "KeyboardEnabledCheckBox";
			KeyboardEnabledCheckBox.PropertyName = "KeyboardEnabled";
			((Control)KeyboardEnabledCheckBox).Size = new Size(120, 24);
			((Control)KeyboardEnabledCheckBox).TabIndex = 1;
			KeyboardEnabledCheckBox.Text = "Keyboard Enabled";
			((ComboBox)MouseControlStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)MouseControlStyleComboBox).Location = new Point(112, 8);
			((ComboBox)MouseControlStyleComboBox).MaxDropDownItems = 20;
			((Control)MouseControlStyleComboBox).Name = "MouseControlStyleComboBox";
			MouseControlStyleComboBox.PropertyName = "MouseControlStyle";
			((Control)MouseControlStyleComboBox).Size = new Size(144, 21);
			((Control)MouseControlStyleComboBox).TabIndex = 0;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)MouseControlStyleComboBox;
			((Control)label2).Location = new Point(6, 10);
			((Control)label2).Name = "label2";
			label2.Size = new Size(106, 15);
			label2.Text = "Mouse Control Style";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)MouseWheelEnabledCheckBox).Location = new Point(112, 64);
			((Control)MouseWheelEnabledCheckBox).Name = "MouseWheelEnabledCheckBox";
			MouseWheelEnabledCheckBox.PropertyName = "MouseWheelEnabled";
			((Control)MouseWheelEnabledCheckBox).Size = new Size(152, 24);
			((Control)MouseWheelEnabledCheckBox).TabIndex = 2;
			MouseWheelEnabledCheckBox.Text = "Mouse Wheel Enabled";
			((Control)FocusRectangleShowCheckBox).Location = new Point(112, 88);
			((Control)FocusRectangleShowCheckBox).Name = "FocusRectangleShowCheckBox";
			FocusRectangleShowCheckBox.PropertyName = "FocusRectangleShow";
			((Control)FocusRectangleShowCheckBox).Size = new Size(144, 24);
			((Control)FocusRectangleShowCheckBox).TabIndex = 3;
			FocusRectangleShowCheckBox.Text = "Focus Rectangle Show";
			((Control)this).Controls.Add((Control)(object)FocusRectangleShowCheckBox);
			((Control)this).Controls.Add((Control)(object)MouseWheelEnabledCheckBox);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)MouseControlStyleComboBox);
			((Control)this).Controls.Add((Control)(object)KeyboardEnabledCheckBox);
			((Control)this).Name = "UIControlKnobEditorPlugIn";
			((Control)this).Size = new Size(368, 136);
			base.Title = "UI Control Editor";
			((Control)this).ResumeLayout(false);
		}
	}
}
namespace Iocomp.Types
{
	public enum MouseControlStyleSlider
	{
		ClickToGoto,
		Slide
	}
}
namespace Iocomp.Classes
{
	[Description("Contains properties to control the knob's user interface characteristics.")]
	[DefaultProperty("MouseControlStyle")]
	public sealed class UIControlSlider : UIControl
	{
		private MouseControlStyleSlider m_MouseControlStyle;

		[RefreshProperties(RefreshProperties.All)]
		[Description("Specifies how the user can use the mouse to move the pointer.")]
		public MouseControlStyleSlider MouseControlStyle
		{
			get
			{
				return m_MouseControlStyle;
			}
			set
			{
				PropertyUpdateDefault("MouseControlStyle", value);
				if (MouseControlStyle != value)
				{
					m_MouseControlStyle = value;
					DoPropertyChange(this, "MouseControlStyle");
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new UIControlSliderEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "UI Control";
		}

		public UIControlSlider()
		{
			DoCreate();
		}

		private bool ShouldSerializeMouseControlStyle()
		{
			return PropertyShouldSerialize("MouseControlStyle");
		}

		private void ResetMouseControlStyle()
		{
			PropertyReset("MouseControlStyle");
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class UIControlSliderEditorPlugIn : PlugInStandard
	{
		private CheckBox KeyboardEnabledCheckBox;

		private FocusLabel label2;

		private ComboBox MouseControlStyleComboBox;

		private CheckBox MouseWheelEnabledCheckBox;

		private CheckBox FocusRectangleShowCheckBox;

		private Container components = null;

		public UIControlSliderEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			KeyboardEnabledCheckBox = new CheckBox();
			MouseControlStyleComboBox = new ComboBox();
			label2 = new FocusLabel();
			MouseWheelEnabledCheckBox = new CheckBox();
			FocusRectangleShowCheckBox = new CheckBox();
			((Control)this).SuspendLayout();
			((Control)KeyboardEnabledCheckBox).Location = new Point(128, 48);
			((Control)KeyboardEnabledCheckBox).Name = "KeyboardEnabledCheckBox";
			KeyboardEnabledCheckBox.PropertyName = "KeyboardEnabled";
			((Control)KeyboardEnabledCheckBox).Size = new Size(120, 24);
			((Control)KeyboardEnabledCheckBox).TabIndex = 1;
			KeyboardEnabledCheckBox.Text = "Keyboard Enabled";
			((ComboBox)MouseControlStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)MouseControlStyleComboBox).Location = new Point(128, 16);
			((ComboBox)MouseControlStyleComboBox).MaxDropDownItems = 20;
			((Control)MouseControlStyleComboBox).Name = "MouseControlStyleComboBox";
			MouseControlStyleComboBox.PropertyName = "MouseControlStyle";
			((Control)MouseControlStyleComboBox).Size = new Size(144, 21);
			((Control)MouseControlStyleComboBox).TabIndex = 0;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)MouseControlStyleComboBox;
			((Control)label2).Location = new Point(22, 18);
			((Control)label2).Name = "label2";
			label2.Size = new Size(106, 15);
			label2.Text = "Mouse Control Style";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)MouseWheelEnabledCheckBox).Location = new Point(128, 72);
			((Control)MouseWheelEnabledCheckBox).Name = "MouseWheelEnabledCheckBox";
			MouseWheelEnabledCheckBox.PropertyName = "MouseWheelEnabled";
			((Control)MouseWheelEnabledCheckBox).Size = new Size(144, 24);
			((Control)MouseWheelEnabledCheckBox).TabIndex = 2;
			MouseWheelEnabledCheckBox.Text = "Mouse Wheel Enabled";
			((Control)FocusRectangleShowCheckBox).Location = new Point(128, 96);
			((Control)FocusRectangleShowCheckBox).Name = "FocusRectangleShowCheckBox";
			FocusRectangleShowCheckBox.PropertyName = "FocusRectangleShow";
			((Control)FocusRectangleShowCheckBox).Size = new Size(144, 24);
			((Control)FocusRectangleShowCheckBox).TabIndex = 3;
			FocusRectangleShowCheckBox.Text = "Focus Rectangle Show";
			((Control)this).Controls.Add((Control)(object)FocusRectangleShowCheckBox);
			((Control)this).Controls.Add((Control)(object)MouseWheelEnabledCheckBox);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)MouseControlStyleComboBox);
			((Control)this).Controls.Add((Control)(object)KeyboardEnabledCheckBox);
			((Control)this).Name = "UIControlSliderEditorPlugIn";
			((Control)this).Size = new Size(360, 128);
			base.Title = "UI Control Editor";
			((Control)this).ResumeLayout(false);
		}
	}
}
namespace Iocomp.Classes
{
	[DefaultProperty("MouseWheelEnabled")]
	[Description("Contains properties to control the knob's user interface characteristics.")]
	public sealed class UIControlSwitchLed : UIControl
	{
		protected override PlugInStandard GetPlugIn()
		{
			return new UIControlSwitchLedEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "UI Control";
		}

		public UIControlSwitchLed()
		{
			DoCreate();
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class UIControlSwitchLedEditorPlugIn : PlugInStandard
	{
		private CheckBox KeyboardEnabledCheckBox;

		private CheckBox MouseWheelEnabledCheckBox;

		private CheckBox FocusRectangleShowCheckBox;

		private Container components = null;

		public UIControlSwitchLedEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			KeyboardEnabledCheckBox = new CheckBox();
			MouseWheelEnabledCheckBox = new CheckBox();
			FocusRectangleShowCheckBox = new CheckBox();
			((Control)this).SuspendLayout();
			((Control)KeyboardEnabledCheckBox).Location = new Point(40, 16);
			((Control)KeyboardEnabledCheckBox).Name = "KeyboardEnabledCheckBox";
			KeyboardEnabledCheckBox.PropertyName = "KeyboardEnabled";
			((Control)KeyboardEnabledCheckBox).Size = new Size(120, 24);
			((Control)KeyboardEnabledCheckBox).TabIndex = 0;
			KeyboardEnabledCheckBox.Text = "Keyboard Enabled";
			((Control)MouseWheelEnabledCheckBox).Location = new Point(40, 40);
			((Control)MouseWheelEnabledCheckBox).Name = "MouseWheelEnabledCheckBox";
			MouseWheelEnabledCheckBox.PropertyName = "MouseWheelEnabled";
			((Control)MouseWheelEnabledCheckBox).Size = new Size(144, 24);
			((Control)MouseWheelEnabledCheckBox).TabIndex = 1;
			MouseWheelEnabledCheckBox.Text = "Mouse Wheel Enabled";
			((Control)FocusRectangleShowCheckBox).Location = new Point(40, 64);
			((Control)FocusRectangleShowCheckBox).Name = "FocusRectangleShowCheckBox";
			FocusRectangleShowCheckBox.PropertyName = "FocusRectangleShow";
			((Control)FocusRectangleShowCheckBox).Size = new Size(144, 24);
			((Control)FocusRectangleShowCheckBox).TabIndex = 2;
			FocusRectangleShowCheckBox.Text = "Focus Rectangle Show";
			((Control)this).Controls.Add((Control)(object)FocusRectangleShowCheckBox);
			((Control)this).Controls.Add((Control)(object)MouseWheelEnabledCheckBox);
			((Control)this).Controls.Add((Control)(object)KeyboardEnabledCheckBox);
			((Control)this).Name = "UIControlSwitchLedEditorPlugIn";
			((Control)this).Size = new Size(344, 144);
			base.Title = "UI Control Editor";
			((Control)this).ResumeLayout(false);
		}
	}
}
namespace Iocomp.Types
{
	public enum MouseControlStyleSwitchPanel
	{
		DragToDestination,
		ClickLabel,
		All
	}
}
namespace Iocomp.Classes
{
	[DefaultProperty("MouseControlStyle")]
	[Description("Contains properties to control the switchpanels's user interface characteristics.")]
	public sealed class UIControlSwitchPanel : UIControl
	{
		private MouseControlStyleSwitchPanel m_MouseControlStyle;

		[Description("Specifies how the user can use the mouse to move the pointer.")]
		[RefreshProperties(RefreshProperties.All)]
		public MouseControlStyleSwitchPanel MouseControlStyle
		{
			get
			{
				return m_MouseControlStyle;
			}
			set
			{
				PropertyUpdateDefault("MouseControlStyle", value);
				if (MouseControlStyle != value)
				{
					m_MouseControlStyle = value;
					DoPropertyChange(this, "MouseControlStyle");
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new UIControlSwitchPanelEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "UI Control";
		}

		public UIControlSwitchPanel()
		{
			DoCreate();
		}

		private bool ShouldSerializeMouseControlStyle()
		{
			return PropertyShouldSerialize("MouseControlStyle");
		}

		private void ResetMouseControlStyle()
		{
			PropertyReset("MouseControlStyle");
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class UIControlSwitchPanelEditorPlugIn : PlugInStandard
	{
		private CheckBox KeyboardEnabledCheckBox;

		private ComboBox MouseControlStyleComboBox;

		private FocusLabel label2;

		private CheckBox MouseWheelEnabledCheckBox;

		private CheckBox FocusRectangleShowCheckBox;

		private Container components = null;

		public UIControlSwitchPanelEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			KeyboardEnabledCheckBox = new CheckBox();
			MouseControlStyleComboBox = new ComboBox();
			label2 = new FocusLabel();
			MouseWheelEnabledCheckBox = new CheckBox();
			FocusRectangleShowCheckBox = new CheckBox();
			((Control)this).SuspendLayout();
			((Control)KeyboardEnabledCheckBox).Location = new Point(120, 56);
			((Control)KeyboardEnabledCheckBox).Name = "KeyboardEnabledCheckBox";
			KeyboardEnabledCheckBox.PropertyName = "KeyboardEnabled";
			((Control)KeyboardEnabledCheckBox).Size = new Size(120, 24);
			((Control)KeyboardEnabledCheckBox).TabIndex = 1;
			KeyboardEnabledCheckBox.Text = "Keyboard Enabled";
			((ComboBox)MouseControlStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)MouseControlStyleComboBox).Location = new Point(120, 16);
			((ComboBox)MouseControlStyleComboBox).MaxDropDownItems = 20;
			((Control)MouseControlStyleComboBox).Name = "MouseControlStyleComboBox";
			MouseControlStyleComboBox.PropertyName = "MouseControlStyle";
			((Control)MouseControlStyleComboBox).Size = new Size(144, 21);
			((Control)MouseControlStyleComboBox).TabIndex = 0;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)MouseControlStyleComboBox;
			((Control)label2).Location = new Point(14, 18);
			((Control)label2).Name = "label2";
			label2.Size = new Size(106, 15);
			label2.Text = "Mouse Control Style";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)MouseWheelEnabledCheckBox).Location = new Point(120, 80);
			((Control)MouseWheelEnabledCheckBox).Name = "MouseWheelEnabledCheckBox";
			MouseWheelEnabledCheckBox.PropertyName = "MouseWheelEnabled";
			((Control)MouseWheelEnabledCheckBox).Size = new Size(144, 24);
			((Control)MouseWheelEnabledCheckBox).TabIndex = 2;
			MouseWheelEnabledCheckBox.Text = "Mouse Wheel Enabled";
			((Control)FocusRectangleShowCheckBox).Location = new Point(120, 104);
			((Control)FocusRectangleShowCheckBox).Name = "FocusRectangleShowCheckBox";
			FocusRectangleShowCheckBox.PropertyName = "FocusRectangleShow";
			((Control)FocusRectangleShowCheckBox).Size = new Size(144, 24);
			((Control)FocusRectangleShowCheckBox).TabIndex = 3;
			FocusRectangleShowCheckBox.Text = "Focus Rectangle Show";
			((Control)this).Controls.Add((Control)(object)FocusRectangleShowCheckBox);
			((Control)this).Controls.Add((Control)(object)MouseWheelEnabledCheckBox);
			((Control)this).Controls.Add((Control)(object)MouseControlStyleComboBox);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)KeyboardEnabledCheckBox);
			((Control)this).Name = "UIControlSwitchPanelEditorPlugIn";
			((Control)this).Size = new Size(280, 136);
			base.Title = "UI Control Editor";
			((Control)this).ResumeLayout(false);
		}
	}
}
namespace Iocomp.Types
{
	public enum MouseControlStyleSwitchRotary
	{
		ClickToGoto,
		DragToDestination
	}
}
namespace Iocomp.Classes
{
	[DefaultProperty("MouseControlStyle")]
	public sealed class UIControlSwitchRotary : UIControl
	{
		private MouseControlStyleSwitchRotary m_MouseControlStyle;

		[Description("Specifies how the user can use the mouse to move the pointer.")]
		public MouseControlStyleSwitchRotary MouseControlStyle
		{
			get
			{
				return m_MouseControlStyle;
			}
			set
			{
				PropertyUpdateDefault("MouseControlStyle", value);
				if (MouseControlStyle != value)
				{
					m_MouseControlStyle = value;
					DoPropertyChange(this, "MouseControlStyle");
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new UIControlSwitchRotaryEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "UI Control";
		}

		public UIControlSwitchRotary()
		{
			DoCreate();
		}

		private bool ShouldSerializeMouseControlStyle()
		{
			return PropertyShouldSerialize("MouseControlStyle");
		}

		private void ResetMouseControlStyle()
		{
			PropertyReset("MouseControlStyle");
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class UIControlSwitchRotaryEditorPlugIn : PlugInStandard
	{
		private CheckBox KeyboardEnabledCheckBox;

		private FocusLabel label2;

		private ComboBox MouseControlStyleComboBox;

		private CheckBox MouseWheelEnabledCheckBox;

		private CheckBox FocusRectangleShowCheckBox;

		private Container components = null;

		public UIControlSwitchRotaryEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			KeyboardEnabledCheckBox = new CheckBox();
			MouseControlStyleComboBox = new ComboBox();
			label2 = new FocusLabel();
			MouseWheelEnabledCheckBox = new CheckBox();
			FocusRectangleShowCheckBox = new CheckBox();
			((Control)this).SuspendLayout();
			((Control)KeyboardEnabledCheckBox).Location = new Point(168, 72);
			((Control)KeyboardEnabledCheckBox).Name = "KeyboardEnabledCheckBox";
			KeyboardEnabledCheckBox.PropertyName = "KeyboardEnabled";
			((Control)KeyboardEnabledCheckBox).Size = new Size(120, 24);
			((Control)KeyboardEnabledCheckBox).TabIndex = 1;
			KeyboardEnabledCheckBox.Text = "Keyboard Enabled";
			((ComboBox)MouseControlStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)MouseControlStyleComboBox).Location = new Point(168, 32);
			((ComboBox)MouseControlStyleComboBox).MaxDropDownItems = 20;
			((Control)MouseControlStyleComboBox).Name = "MouseControlStyleComboBox";
			MouseControlStyleComboBox.PropertyName = "MouseControlStyle";
			((Control)MouseControlStyleComboBox).Size = new Size(144, 21);
			((Control)MouseControlStyleComboBox).TabIndex = 0;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)MouseControlStyleComboBox;
			((Control)label2).Location = new Point(62, 34);
			((Control)label2).Name = "label2";
			label2.Size = new Size(106, 15);
			label2.Text = "Mouse Control Style";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)MouseWheelEnabledCheckBox).Location = new Point(168, 96);
			((Control)MouseWheelEnabledCheckBox).Name = "MouseWheelEnabledCheckBox";
			MouseWheelEnabledCheckBox.PropertyName = "MouseWheelEnabled";
			((Control)MouseWheelEnabledCheckBox).Size = new Size(144, 24);
			((Control)MouseWheelEnabledCheckBox).TabIndex = 2;
			MouseWheelEnabledCheckBox.Text = "Mouse Wheel Enabled";
			((Control)FocusRectangleShowCheckBox).Location = new Point(168, 120);
			((Control)FocusRectangleShowCheckBox).Name = "FocusRectangleShowCheckBox";
			FocusRectangleShowCheckBox.PropertyName = "FocusRectangleShow";
			((Control)FocusRectangleShowCheckBox).Size = new Size(144, 24);
			((Control)FocusRectangleShowCheckBox).TabIndex = 3;
			FocusRectangleShowCheckBox.Text = "Focus Rectangle Show";
			((Control)this).Controls.Add((Control)(object)FocusRectangleShowCheckBox);
			((Control)this).Controls.Add((Control)(object)MouseWheelEnabledCheckBox);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)MouseControlStyleComboBox);
			((Control)this).Controls.Add((Control)(object)KeyboardEnabledCheckBox);
			((Control)this).Name = "UIControlSwitchRotaryEditorPlugIn";
			((Control)this).Size = new Size(472, 200);
			base.Title = "UI Control Editor";
			((Control)this).ResumeLayout(false);
		}
	}
}
namespace Iocomp.Types
{
	public enum MouseControlStyleSwitchSlider
	{
		ClickToGoto,
		DragToDestination
	}
}
namespace Iocomp.Classes
{
	[DefaultProperty("MouseControlStyle")]
	public sealed class UIControlSwitchSlider : UIControl
	{
		private MouseControlStyleSwitchSlider m_MouseControlStyle;

		[Description("Specifies how the user can use the mouse to move the pointer.")]
		public MouseControlStyleSwitchSlider MouseControlStyle
		{
			get
			{
				return m_MouseControlStyle;
			}
			set
			{
				PropertyUpdateDefault("MouseControlStyle", value);
				if (MouseControlStyle != value)
				{
					m_MouseControlStyle = value;
					DoPropertyChange(this, "MouseControlStyle");
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new UIControlSwitchSliderEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "UI Control";
		}

		public UIControlSwitchSlider()
		{
			DoCreate();
		}

		private bool ShouldSerializeMouseControlStyle()
		{
			return PropertyShouldSerialize("MouseControlStyle");
		}

		private void ResetMouseControlStyle()
		{
			PropertyReset("MouseControlStyle");
		}
	}
}
namespace Iocomp.Design
{
	[DesignerCategory("Form")]
	[ToolboxItem(false)]
	public class UIControlSwitchSliderEditorPlugIn : PlugInStandard
	{
		private CheckBox KeyboardEnabledCheckBox;

		private FocusLabel label2;

		private ComboBox MouseControlStyleComboBox;

		private CheckBox MouseWheelEnabledCheckBox;

		private CheckBox FocusRectangleShowCheckBox;

		private Container components = null;

		public UIControlSwitchSliderEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			KeyboardEnabledCheckBox = new CheckBox();
			label2 = new FocusLabel();
			MouseControlStyleComboBox = new ComboBox();
			MouseWheelEnabledCheckBox = new CheckBox();
			FocusRectangleShowCheckBox = new CheckBox();
			((Control)this).SuspendLayout();
			((Control)KeyboardEnabledCheckBox).Location = new Point(216, 64);
			((Control)KeyboardEnabledCheckBox).Name = "KeyboardEnabledCheckBox";
			KeyboardEnabledCheckBox.PropertyName = "KeyboardEnabled";
			((Control)KeyboardEnabledCheckBox).Size = new Size(120, 24);
			((Control)KeyboardEnabledCheckBox).TabIndex = 1;
			KeyboardEnabledCheckBox.Text = "Keyboard Enabled";
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)MouseControlStyleComboBox;
			((Control)label2).Location = new Point(110, 26);
			((Control)label2).Name = "label2";
			label2.Size = new Size(106, 15);
			label2.Text = "Mouse Control Style";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((ComboBox)MouseControlStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)MouseControlStyleComboBox).Location = new Point(216, 24);
			((ComboBox)MouseControlStyleComboBox).MaxDropDownItems = 20;
			((Control)MouseControlStyleComboBox).Name = "MouseControlStyleComboBox";
			MouseControlStyleComboBox.PropertyName = "MouseControlStyle";
			((Control)MouseControlStyleComboBox).Size = new Size(144, 21);
			((Control)MouseControlStyleComboBox).TabIndex = 0;
			((Control)MouseWheelEnabledCheckBox).Location = new Point(216, 88);
			((Control)MouseWheelEnabledCheckBox).Name = "MouseWheelEnabledCheckBox";
			MouseWheelEnabledCheckBox.PropertyName = "MouseWheelEnabled";
			((Control)MouseWheelEnabledCheckBox).Size = new Size(144, 24);
			((Control)MouseWheelEnabledCheckBox).TabIndex = 2;
			MouseWheelEnabledCheckBox.Text = "Mouse Wheel Enabled";
			((Control)FocusRectangleShowCheckBox).Location = new Point(216, 112);
			((Control)FocusRectangleShowCheckBox).Name = "FocusRectangleShowCheckBox";
			FocusRectangleShowCheckBox.PropertyName = "FocusRectangleShow";
			((Control)FocusRectangleShowCheckBox).Size = new Size(144, 24);
			((Control)FocusRectangleShowCheckBox).TabIndex = 3;
			FocusRectangleShowCheckBox.Text = "Focus Rectangle Show";
			((Control)this).Controls.Add((Control)(object)FocusRectangleShowCheckBox);
			((Control)this).Controls.Add((Control)(object)MouseWheelEnabledCheckBox);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)MouseControlStyleComboBox);
			((Control)this).Controls.Add((Control)(object)KeyboardEnabledCheckBox);
			((Control)this).Name = "UIControlSwitchSliderEditorPlugIn";
			((Control)this).Size = new Size(536, 176);
			base.Title = "UI Control Editor";
			((Control)this).ResumeLayout(false);
		}
	}
}
namespace Iocomp.Types
{
	public enum MouseControlStyleSwitchToggle
	{
		ClickToToggle,
		ClickDestination,
		DragToDestination
	}
}
namespace Iocomp.Classes
{
	[DefaultProperty("MouseControlStyle")]
	public sealed class UIControlSwitchToggle : UIControl
	{
		private MouseControlStyleSwitchToggle m_MouseControlStyle;

		[Description("Specifies how the user can use the mouse to move the pointer.")]
		public MouseControlStyleSwitchToggle MouseControlStyle
		{
			get
			{
				return m_MouseControlStyle;
			}
			set
			{
				PropertyUpdateDefault("MouseControlStyle", value);
				if (MouseControlStyle != value)
				{
					m_MouseControlStyle = value;
					DoPropertyChange(this, "MouseControlStyle");
				}
			}
		}

		protected override PlugInStandard GetPlugIn()
		{
			return new UIControlSwitchToggleEditorPlugIn();
		}

		protected override string GetPlugInTitle()
		{
			return "UI Control";
		}

		public UIControlSwitchToggle()
		{
			DoCreate();
		}

		private bool ShouldSerializeMouseControlStyle()
		{
			return PropertyShouldSerialize("MouseControlStyle");
		}

		private void ResetMouseControlStyle()
		{
			PropertyReset("MouseControlStyle");
		}
	}
}
namespace Iocomp.Design
{
	[ToolboxItem(false)]
	[DesignerCategory("Form")]
	public class UIControlSwitchToggleEditorPlugIn : PlugInStandard
	{
		private CheckBox KeyboardEnabledCheckBox;

		private FocusLabel label2;

		private ComboBox MouseControlStyleComboBox;

		private CheckBox MouseWheelEnabledCheckBox;

		private CheckBox FocusRectangleShowCheckBox;

		private Container components = null;

		public UIControlSwitchToggleEditorPlugIn()
		{
			InitializeComponent();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			KeyboardEnabledCheckBox = new CheckBox();
			MouseControlStyleComboBox = new ComboBox();
			label2 = new FocusLabel();
			MouseWheelEnabledCheckBox = new CheckBox();
			FocusRectangleShowCheckBox = new CheckBox();
			((Control)this).SuspendLayout();
			((Control)KeyboardEnabledCheckBox).Location = new Point(208, 72);
			((Control)KeyboardEnabledCheckBox).Name = "KeyboardEnabledCheckBox";
			KeyboardEnabledCheckBox.PropertyName = "KeyboardEnabled";
			((Control)KeyboardEnabledCheckBox).Size = new Size(120, 24);
			((Control)KeyboardEnabledCheckBox).TabIndex = 1;
			KeyboardEnabledCheckBox.Text = "Keyboard Enabled";
			((ComboBox)MouseControlStyleComboBox).DropDownStyle = (ComboBoxStyle)2;
			((Control)MouseControlStyleComboBox).Location = new Point(208, 32);
			((ComboBox)MouseControlStyleComboBox).MaxDropDownItems = 20;
			((Control)MouseControlStyleComboBox).Name = "MouseControlStyleComboBox";
			MouseControlStyleComboBox.PropertyName = "MouseControlStyle";
			((Control)MouseControlStyleComboBox).Size = new Size(144, 21);
			((Control)MouseControlStyleComboBox).TabIndex = 0;
			label2.LoadingBegin();
			label2.FocusControl = (Control)(object)MouseControlStyleComboBox;
			((Control)label2).Location = new Point(102, 34);
			((Control)label2).Name = "label2";
			label2.Size = new Size(106, 15);
			label2.Text = "Mouse Control Style";
			label2.UpdateFrameRate = 50.0;
			label2.LoadingEnd();
			((Control)MouseWheelEnabledCheckBox).Location = new Point(208, 96);
			((Control)MouseWheelEnabledCheckBox).Name = "MouseWheelEnabledCheckBox";
			MouseWheelEnabledCheckBox.PropertyName = "MouseWheelEnabled";
			((Control)MouseWheelEnabledCheckBox).Size = new Size(144, 24);
			((Control)MouseWheelEnabledCheckBox).TabIndex = 2;
			MouseWheelEnabledCheckBox.Text = "Mouse Wheel Enabled";
			((Control)FocusRectangleShowCheckBox).Location = new Point(208, 120);
			((Control)FocusRectangleShowCheckBox).Name = "FocusRectangleShowCheckBox";
			FocusRectangleShowCheckBox.PropertyName = "FocusRectangleShow";
			((Control)FocusRectangleShowCheckBox).Size = new Size(144, 24);
			((Control)FocusRectangleShowCheckBox).TabIndex = 3;
			FocusRectangleShowCheckBox.Text = "Focus Rectangle Show";
			((Control)this).Controls.Add((Control)(object)FocusRectangleShowCheckBox);
			((Control)this).Controls.Add((Control)(object)MouseWheelEnabledCheckBox);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)MouseControlStyleComboBox);
			((Control)this).Controls.Add((Control)(object)KeyboardEnabledCheckBox);
			((Control)this).Name = "UIControlSwitchToggleEditorPlugIn";
			((Control)this).Size = new Size(576, 208);
			base.Title = "UI Control Editor";
			((Control)this).ResumeLayout(false);
		}
	}
}
