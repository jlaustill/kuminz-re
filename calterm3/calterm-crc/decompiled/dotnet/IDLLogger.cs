using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Timers;
using System.Windows.Forms;
using System.Xml;
using Cummins.AddressRepresentation;
using Cummins.ApplicationServices;
using Cummins.CUTY;
using Cummins.CalToolsLib;
using Cummins.Calibration;
using Cummins.EventLog;
using Cummins.IDLLogger.EventDriven;
using Cummins.Interop.DataMonitoring;
using Cummins.Logging;
using Cummins.Logging.LogManager;
using Cummins.MessageDialog;
using Cummins.Module;
using Cummins.Parameter;
using Cummins.Services;
using Cummins.Subscription;
using Cummins.Widgets;

[assembly: AssemblyProduct("Calterm III - IDLLogger")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTitle("Poodle")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.IDLLogger
{
	public class BlankIDLLoggingPreferencePage : UserControl, IPropertyPage
	{
		private Label label1;

		private Container components;

		private string parentNode;

		private string currentNode;

		public string CurrentNode
		{
			get
			{
				return currentNode;
			}
			set
			{
				currentNode = value;
			}
		}

		public string ParentNode
		{
			get
			{
				return parentNode;
			}
			set
			{
				parentNode = value;
			}
		}

		public BlankIDLLoggingPreferencePage(string parentNode, string currentNode)
		{
			InitializeComponent();
			ParentNode = parentNode;
			CurrentNode = currentNode;
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((ContainerControl)this).Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			label1 = new Label();
			((Control)this).SuspendLayout();
			((Control)label1).Location = new Point(8, 8);
			((Control)label1).Name = "label1";
			((Control)label1).Size = new Size(376, 16);
			((Control)label1).TabIndex = 0;
			((Control)label1).Text = "All IDL Logging options has moved to Configure IDL under Logging menu.";
			((Control)this).Controls.Add((Control)(object)label1);
			((Control)this).Name = "BlankIDLLoggingPreferencePage";
			((Control)this).Size = new Size(408, 48);
			((Control)this).ResumeLayout(false);
		}

		public void SetOptions()
		{
		}

		public void Initialize()
		{
		}
	}
	public class ConfigureIDLDialog : Form
	{
		private RadioButton radioButtonUseCurrScreen;

		private RadioButton radioButtonSpecifyFile;

		private Label labelPeriod;

		private Label labelSource;

		private RadioButton radioButtonUserSpecifiedRate;

		private RadioButton radioButtonMaxRate;

		private CheckBox checkBoxAutoRetrieval;

		private Button buttonCancel;

		private RadioButton radioButtonFill;

		private RadioButton radioButtonCenter;

		private RadioButton radioButtonStop;

		private CheckBox checkBoxStartIDLKeyOn;

		private GroupBox groupTrigger;

		private GroupBox groupStartStopMode;

		private GroupBox groupIDLParameter;

		private ComboBox comboTriggerSource;

		private GroupBox groupIDLBufferRetrieval;

		private TextBox textTriggerPeriod;

		private Label labelBytePerSec;

		private TextBox textRetrievalRate;

		private Label labelPeriodUnit;

		private FileSelectionControl fileSelectionControl;

		private ErrorProvider errorProvider;

		private Button buttonOk;

		private IContainer components;

		private IDLConfiguration idlConfiguration;

		private bool isTriggerPeriodValid = true;

		private bool isRetrievalRateValid = true;

		private IDLStopType IDLStopMode
		{
			get
			{
				return idlConfiguration.IDLStopMode;
			}
			set
			{
				switch (value)
				{
				case IDLStopType.Stop:
					radioButtonStop.Checked = true;
					break;
				case IDLStopType.Center:
					radioButtonCenter.Checked = true;
					break;
				case IDLStopType.Fill:
					radioButtonFill.Checked = true;
					break;
				default:
					throw new NotSupportedException();
				}
				idlConfiguration.IDLStopMode = value;
			}
		}

		private bool IsTriggerPeriodValid
		{
			get
			{
				return isTriggerPeriodValid;
			}
			set
			{
				isTriggerPeriodValid = value;
				if (isTriggerPeriodValid)
				{
					CheckValidInput();
				}
			}
		}

		private bool IsRetrievalRateValid
		{
			get
			{
				return isRetrievalRateValid;
			}
			set
			{
				isRetrievalRateValid = value;
				if (isRetrievalRateValid)
				{
					CheckValidInput();
				}
			}
		}

		public ConfigureIDLDialog()
		{
			InitializeComponent();
			Initialize();
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
			//IL_0114: Unknown result type (might be due to invalid IL or missing references)
			//IL_011e: Expected O, but got Unknown
			//IL_011f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0129: Expected O, but got Unknown
			//IL_0d87: Unknown result type (might be due to invalid IL or missing references)
			//IL_0d91: Expected O, but got Unknown
			components = new Container();
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(ConfigureIDLDialog));
			groupIDLParameter = new GroupBox();
			fileSelectionControl = new FileSelectionControl();
			radioButtonUseCurrScreen = new RadioButton();
			radioButtonSpecifyFile = new RadioButton();
			groupTrigger = new GroupBox();
			labelPeriodUnit = new Label();
			textTriggerPeriod = new TextBox();
			labelPeriod = new Label();
			comboTriggerSource = new ComboBox();
			labelSource = new Label();
			groupIDLBufferRetrieval = new GroupBox();
			labelBytePerSec = new Label();
			textRetrievalRate = new TextBox();
			radioButtonUserSpecifiedRate = new RadioButton();
			radioButtonMaxRate = new RadioButton();
			checkBoxAutoRetrieval = new CheckBox();
			buttonCancel = new Button();
			groupStartStopMode = new GroupBox();
			radioButtonFill = new RadioButton();
			radioButtonCenter = new RadioButton();
			radioButtonStop = new RadioButton();
			checkBoxStartIDLKeyOn = new CheckBox();
			errorProvider = new ErrorProvider(components);
			buttonOk = new Button();
			((Control)groupIDLParameter).SuspendLayout();
			((Control)groupTrigger).SuspendLayout();
			((Control)groupIDLBufferRetrieval).SuspendLayout();
			((Control)groupStartStopMode).SuspendLayout();
			((ISupportInitialize)errorProvider).BeginInit();
			((Control)this).SuspendLayout();
			((Control)groupIDLParameter).Controls.Add((Control)(object)fileSelectionControl);
			((Control)groupIDLParameter).Controls.Add((Control)(object)radioButtonUseCurrScreen);
			((Control)groupIDLParameter).Controls.Add((Control)(object)radioButtonSpecifyFile);
			((Control)groupIDLParameter).Location = new Point(8, 184);
			((Control)groupIDLParameter).Name = "groupIDLParameter";
			((Control)groupIDLParameter).Size = new Size(344, 96);
			((Control)groupIDLParameter).TabIndex = 26;
			groupIDLParameter.TabStop = false;
			((Control)groupIDLParameter).Text = "IDL Parameters";
			fileSelectionControl.AllowEdit = true;
			fileSelectionControl.AllowSelect = true;
			((Control)fileSelectionControl).Enabled = false;
			fileSelectionControl.FileName = "";
			fileSelectionControl.Filter = "Screen File (*.scr.xml)|*.scr.xml|All files (*.*)|*.*";
			fileSelectionControl.FilterIndex = 0;
			fileSelectionControl.Flat = false;
			((Control)fileSelectionControl).Location = new Point(40, 64);
			((Control)fileSelectionControl).Name = "fileSelectionControl";
			fileSelectionControl.SelectionType = SelectionType.File;
			((Control)fileSelectionControl).Size = new Size(288, 16);
			((Control)fileSelectionControl).TabIndex = 14;
			radioButtonUseCurrScreen.Checked = true;
			((Control)radioButtonUseCurrScreen).Location = new Point(24, 16);
			((Control)radioButtonUseCurrScreen).Name = "radioButtonUseCurrScreen";
			((Control)radioButtonUseCurrScreen).Size = new Size(200, 24);
			((Control)radioButtonUseCurrScreen).TabIndex = 13;
			radioButtonUseCurrScreen.TabStop = true;
			((Control)radioButtonUseCurrScreen).Text = "Use current screen file parameters";
			radioButtonUseCurrScreen.CheckedChanged += radioButtonUseCurrScreen_CheckedChanged;
			((Control)radioButtonSpecifyFile).Location = new Point(24, 40);
			((Control)radioButtonSpecifyFile).Name = "radioButtonSpecifyFile";
			((Control)radioButtonSpecifyFile).Size = new Size(120, 24);
			((Control)radioButtonSpecifyFile).TabIndex = 12;
			((Control)radioButtonSpecifyFile).Text = "Specify screen file";
			((Control)groupTrigger).Controls.Add((Control)(object)labelPeriodUnit);
			((Control)groupTrigger).Controls.Add((Control)(object)textTriggerPeriod);
			((Control)groupTrigger).Controls.Add((Control)(object)labelPeriod);
			((Control)groupTrigger).Controls.Add((Control)(object)comboTriggerSource);
			((Control)groupTrigger).Controls.Add((Control)(object)labelSource);
			((Control)groupTrigger).Location = new Point(8, 8);
			((Control)groupTrigger).Name = "groupTrigger";
			((Control)groupTrigger).Size = new Size(240, 88);
			((Control)groupTrigger).TabIndex = 25;
			groupTrigger.TabStop = false;
			((Control)groupTrigger).Text = "Trigger";
			((Control)labelPeriodUnit).Location = new Point(120, 50);
			((Control)labelPeriodUnit).Name = "labelPeriodUnit";
			((Control)labelPeriodUnit).Size = new Size(112, 23);
			((Control)labelPeriodUnit).TabIndex = 14;
			((Control)labelPeriodUnit).Text = "ms";
			labelPeriodUnit.TextAlign = (ContentAlignment)16;
			((Control)textTriggerPeriod).Location = new Point(64, 52);
			((TextBoxBase)textTriggerPeriod).MaxLength = 4;
			((Control)textTriggerPeriod).Name = "textTriggerPeriod";
			((Control)textTriggerPeriod).Size = new Size(56, 20);
			((Control)textTriggerPeriod).TabIndex = 12;
			textTriggerPeriod.TextAlign = (HorizontalAlignment)1;
			((Control)textTriggerPeriod).Leave += textTriggerPeriod_Leave;
			((Control)labelPeriod).Location = new Point(16, 56);
			((Control)labelPeriod).Name = "labelPeriod";
			((Control)labelPeriod).Size = new Size(40, 16);
			((Control)labelPeriod).TabIndex = 1;
			((Control)labelPeriod).Text = "Period";
			comboTriggerSource.Items.AddRange(new object[3] { "Road Speed", "Timer", "Clock" });
			((Control)comboTriggerSource).Location = new Point(64, 20);
			((Control)comboTriggerSource).Name = "comboTriggerSource";
			((Control)comboTriggerSource).Size = new Size(144, 21);
			((Control)comboTriggerSource).TabIndex = 8;
			((ListControl)comboTriggerSource).SelectedValueChanged += comboTriggerSource_SelectedValueChanged;
			((Control)labelSource).Location = new Point(16, 24);
			((Control)labelSource).Name = "labelSource";
			((Control)labelSource).Size = new Size(40, 16);
			((Control)labelSource).TabIndex = 0;
			((Control)labelSource).Text = "Source";
			((Control)groupIDLBufferRetrieval).Controls.Add((Control)(object)labelBytePerSec);
			((Control)groupIDLBufferRetrieval).Controls.Add((Control)(object)textRetrievalRate);
			((Control)groupIDLBufferRetrieval).Controls.Add((Control)(object)radioButtonUserSpecifiedRate);
			((Control)groupIDLBufferRetrieval).Controls.Add((Control)(object)radioButtonMaxRate);
			((Control)groupIDLBufferRetrieval).Controls.Add((Control)(object)checkBoxAutoRetrieval);
			((Control)groupIDLBufferRetrieval).Location = new Point(8, 288);
			((Control)groupIDLBufferRetrieval).Name = "groupIDLBufferRetrieval";
			((Control)groupIDLBufferRetrieval).Size = new Size(344, 96);
			((Control)groupIDLBufferRetrieval).TabIndex = 24;
			groupIDLBufferRetrieval.TabStop = false;
			((Control)groupIDLBufferRetrieval).Text = "IDL Buffer Retrieval";
			((Control)labelBytePerSec).Enabled = false;
			((Control)labelBytePerSec).Location = new Point(184, 40);
			((Control)labelBytePerSec).Name = "labelBytePerSec";
			((Control)labelBytePerSec).Size = new Size(56, 23);
			((Control)labelBytePerSec).TabIndex = 15;
			((Control)labelBytePerSec).Text = "bytes/sec";
			labelBytePerSec.TextAlign = (ContentAlignment)32;
			((Control)textRetrievalRate).Enabled = false;
			((Control)textRetrievalRate).Location = new Point(136, 42);
			((TextBoxBase)textRetrievalRate).MaxLength = 4;
			((Control)textRetrievalRate).Name = "textRetrievalRate";
			((Control)textRetrievalRate).Size = new Size(48, 20);
			((Control)textRetrievalRate).TabIndex = 13;
			textRetrievalRate.TextAlign = (HorizontalAlignment)1;
			((Control)textRetrievalRate).Leave += textRetrievalRate_Leave;
			((Control)radioButtonUserSpecifiedRate).Location = new Point(24, 40);
			((Control)radioButtonUserSpecifiedRate).Name = "radioButtonUserSpecifiedRate";
			((Control)radioButtonUserSpecifiedRate).Size = new Size(120, 24);
			((Control)radioButtonUserSpecifiedRate).TabIndex = 6;
			((Control)radioButtonUserSpecifiedRate).Text = "User specified rate";
			radioButtonMaxRate.Checked = true;
			((Control)radioButtonMaxRate).Location = new Point(24, 16);
			((Control)radioButtonMaxRate).Name = "radioButtonMaxRate";
			((Control)radioButtonMaxRate).Size = new Size(96, 24);
			((Control)radioButtonMaxRate).TabIndex = 7;
			radioButtonMaxRate.TabStop = true;
			((Control)radioButtonMaxRate).Text = "Maximum rate";
			radioButtonMaxRate.CheckedChanged += radioButtonMaxRate_CheckedChanged;
			((Control)checkBoxAutoRetrieval).Location = new Point(24, 64);
			((Control)checkBoxAutoRetrieval).Name = "checkBoxAutoRetrieval";
			((Control)checkBoxAutoRetrieval).Size = new Size(140, 24);
			((Control)checkBoxAutoRetrieval).TabIndex = 4;
			((Control)checkBoxAutoRetrieval).Text = "Auto retrieve IDL buffer";
			checkBoxAutoRetrieval.CheckedChanged += checkBoxAutoRetrieval_CheckedChanged;
			buttonCancel.DialogResult = (DialogResult)2;
			((Control)buttonCancel).Location = new Point(272, 400);
			((Control)buttonCancel).Name = "buttonCancel";
			((Control)buttonCancel).Size = new Size(75, 23);
			((Control)buttonCancel).TabIndex = 23;
			((Control)buttonCancel).Text = "&Cancel";
			((Control)groupStartStopMode).Controls.Add((Control)(object)radioButtonFill);
			((Control)groupStartStopMode).Controls.Add((Control)(object)radioButtonCenter);
			((Control)groupStartStopMode).Controls.Add((Control)(object)radioButtonStop);
			((Control)groupStartStopMode).Controls.Add((Control)(object)checkBoxStartIDLKeyOn);
			((Control)groupStartStopMode).Location = new Point(8, 104);
			((Control)groupStartStopMode).Name = "groupStartStopMode";
			((Control)groupStartStopMode).Size = new Size(240, 72);
			((Control)groupStartStopMode).TabIndex = 21;
			groupStartStopMode.TabStop = false;
			((Control)groupStartStopMode).Text = "Start/Stop Mode";
			((Control)radioButtonFill).Location = new Point(144, 40);
			((Control)radioButtonFill).Name = "radioButtonFill";
			((Control)radioButtonFill).Size = new Size(48, 24);
			((Control)radioButtonFill).TabIndex = 2;
			((Control)radioButtonFill).Text = "Fill";
			radioButtonFill.CheckedChanged += OnIDLStopModeChanged;
			((Control)radioButtonCenter).Location = new Point(80, 40);
			((Control)radioButtonCenter).Name = "radioButtonCenter";
			((Control)radioButtonCenter).Size = new Size(56, 24);
			((Control)radioButtonCenter).TabIndex = 1;
			((Control)radioButtonCenter).Text = "Center";
			radioButtonCenter.CheckedChanged += OnIDLStopModeChanged;
			radioButtonStop.Checked = true;
			((Control)radioButtonStop).Location = new Point(24, 40);
			((Control)radioButtonStop).Name = "radioButtonStop";
			((Control)radioButtonStop).Size = new Size(48, 24);
			((Control)radioButtonStop).TabIndex = 0;
			radioButtonStop.TabStop = true;
			((Control)radioButtonStop).Text = "Stop";
			radioButtonStop.CheckedChanged += OnIDLStopModeChanged;
			((Control)checkBoxStartIDLKeyOn).Location = new Point(24, 16);
			((Control)checkBoxStartIDLKeyOn).Name = "checkBoxStartIDLKeyOn";
			((Control)checkBoxStartIDLKeyOn).Size = new Size(128, 24);
			((Control)checkBoxStartIDLKeyOn).TabIndex = 3;
			((Control)checkBoxStartIDLKeyOn).Text = "Start IDL on Key On";
			checkBoxStartIDLKeyOn.CheckedChanged += checkBoxStartIDLKeyOn_CheckedChanged;
			errorProvider.ContainerControl = (ContainerControl)(object)this;
			((Control)buttonOk).Location = new Point(192, 400);
			((Control)buttonOk).Name = "buttonOk";
			((Control)buttonOk).Size = new Size(75, 23);
			((Control)buttonOk).TabIndex = 27;
			((Control)buttonOk).Text = "&Ok";
			((Control)buttonOk).Click += buttonOk_Click;
			((Form)this).CancelButton = (IButtonControl)(object)buttonCancel;
			((Form)this).ClientSize = new Size(362, 437);
			((Control)this).Controls.Add((Control)(object)buttonOk);
			((Control)this).Controls.Add((Control)(object)groupIDLParameter);
			((Control)this).Controls.Add((Control)(object)groupTrigger);
			((Control)this).Controls.Add((Control)(object)groupIDLBufferRetrieval);
			((Control)this).Controls.Add((Control)(object)buttonCancel);
			((Control)this).Controls.Add((Control)(object)groupStartStopMode);
			((Form)this).FormBorderStyle = (FormBorderStyle)1;
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = "ConfigureIDLDialog";
			((Form)this).StartPosition = (FormStartPosition)4;
			((Control)this).Text = "IDL Configuration";
			((Control)groupIDLParameter).ResumeLayout(false);
			((Control)groupTrigger).ResumeLayout(false);
			((Control)groupTrigger).PerformLayout();
			((Control)groupIDLBufferRetrieval).ResumeLayout(false);
			((Control)groupIDLBufferRetrieval).PerformLayout();
			((Control)groupStartStopMode).ResumeLayout(false);
			((ISupportInitialize)errorProvider).EndInit();
			((Control)this).ResumeLayout(false);
		}

		private void Initialize()
		{
			idlConfiguration = new IDLConfiguration();
			SetIDLTriggerModes();
			((Control)comboTriggerSource).Text = idlConfiguration.IDLTriggerMode.ToString();
			((Control)textTriggerPeriod).Text = idlConfiguration.TriggerPeriod.ToString();
			checkBoxStartIDLKeyOn.Checked = idlConfiguration.IDLOnKeyOn;
			IDLStopMode = idlConfiguration.IDLStopMode;
			radioButtonUseCurrScreen.Checked = idlConfiguration.UseCurrentScreenParameters;
			fileSelectionControl.FileName = idlConfiguration.ScreenFilePath;
			radioButtonMaxRate.Checked = idlConfiguration.RetrieveIDLAtMaxRate;
			((Control)textRetrievalRate).Text = idlConfiguration.BufferRetrievalRate.ToString();
			checkBoxAutoRetrieval.Checked = idlConfiguration.AutoBufferRetrieval;
		}

		private void SetIDLTriggerModes()
		{
			comboTriggerSource.Items.Clear();
			string[] names = Enum.GetNames(idlConfiguration.IDLTriggerType);
			comboTriggerSource.Items.AddRange((object[])names);
		}

		private void CheckValidInput()
		{
			if (isTriggerPeriodValid && isRetrievalRateValid)
			{
				errorProvider.SetError((Control)(object)buttonOk, "");
			}
		}

		private void checkBoxStartIDLKeyOn_CheckedChanged(object sender, EventArgs e)
		{
			idlConfiguration.IDLOnKeyOn = checkBoxStartIDLKeyOn.Checked;
			((Control)radioButtonStop).Enabled = !checkBoxStartIDLKeyOn.Checked;
			((Control)radioButtonCenter).Enabled = !checkBoxStartIDLKeyOn.Checked;
			((Control)radioButtonFill).Enabled = !checkBoxStartIDLKeyOn.Checked;
		}

		private void OnIDLStopModeChanged(object sender, EventArgs e)
		{
			IDLStopType iDLStopMode = IDLStopType.Stop;
			RadioButton val = (RadioButton)((sender is RadioButton) ? sender : null);
			if (val.Checked)
			{
				if (val == radioButtonFill)
				{
					iDLStopMode = IDLStopType.Fill;
				}
				else if (val == radioButtonStop)
				{
					iDLStopMode = IDLStopType.Stop;
				}
				else if (val == radioButtonCenter)
				{
					iDLStopMode = IDLStopType.Center;
				}
				idlConfiguration.IDLStopMode = iDLStopMode;
			}
		}

		private void radioButtonUseCurrScreen_CheckedChanged(object sender, EventArgs e)
		{
			idlConfiguration.UseCurrentScreenParameters = radioButtonUseCurrScreen.Checked;
			radioButtonSpecifyFile.Checked = !radioButtonUseCurrScreen.Checked;
			((Control)fileSelectionControl).Enabled = !radioButtonUseCurrScreen.Checked;
		}

		private void radioButtonMaxRate_CheckedChanged(object sender, EventArgs e)
		{
			idlConfiguration.RetrieveIDLAtMaxRate = radioButtonMaxRate.Checked;
			radioButtonUserSpecifiedRate.Checked = !radioButtonMaxRate.Checked;
			((Control)textRetrievalRate).Enabled = !radioButtonMaxRate.Checked;
			((Control)labelBytePerSec).Enabled = !radioButtonMaxRate.Checked;
			if (radioButtonMaxRate.Checked)
			{
				errorProvider.SetError((Control)(object)textRetrievalRate, "");
				((Control)textRetrievalRate).Text = idlConfiguration.BufferRetrievalRate.ToString();
				IsRetrievalRateValid = true;
			}
		}

		private void comboTriggerSource_SelectedValueChanged(object sender, EventArgs e)
		{
			((Control)labelPeriodUnit).Text = IDLLogger.GetUnit((TriggerType)Enum.Parse(typeof(TriggerType), ((Control)comboTriggerSource).Text, ignoreCase: true));
			idlConfiguration.IDLTriggerMode = (TriggerType)Enum.Parse(typeof(TriggerType), ((Control)comboTriggerSource).Text, ignoreCase: true);
		}

		private void textTriggerPeriod_Leave(object sender, EventArgs e)
		{
			IsTriggerPeriodValid = true;
			TextBox val = (TextBox)((sender is TextBox) ? sender : null);
			errorProvider.SetError((Control)(object)val, "");
			try
			{
				idlConfiguration.TriggerPeriod = int.Parse(((Control)val).Text);
			}
			catch (ArgumentOutOfRangeException ex)
			{
				IsTriggerPeriodValid = false;
				errorProvider.SetError((Control)(object)val, ex.Message);
			}
			catch
			{
				IsTriggerPeriodValid = false;
				errorProvider.SetError((Control)(object)val, "Please enter an integer value");
			}
		}

		private void textRetrievalRate_Leave(object sender, EventArgs e)
		{
			IsRetrievalRateValid = true;
			TextBox val = (TextBox)((sender is TextBox) ? sender : null);
			errorProvider.SetError((Control)(object)val, "");
			try
			{
				idlConfiguration.BufferRetrievalRate = int.Parse(((Control)val).Text);
			}
			catch (ArgumentOutOfRangeException ex)
			{
				IsRetrievalRateValid = false;
				errorProvider.SetError((Control)(object)val, ex.Message);
			}
			catch
			{
				IsRetrievalRateValid = false;
				errorProvider.SetError((Control)(object)val, "Please enter an integer value");
			}
		}

		private void checkBoxAutoRetrieval_CheckedChanged(object sender, EventArgs e)
		{
			idlConfiguration.AutoBufferRetrieval = checkBoxAutoRetrieval.Checked;
		}

		private void buttonOk_Click(object sender, EventArgs e)
		{
			idlConfiguration.ScreenFilePath = fileSelectionControl.FileName;
			if (IsTriggerPeriodValid && IsRetrievalRateValid)
			{
				((Form)this).DialogResult = (DialogResult)1;
				idlConfiguration.SaveConfiguration();
			}
			else
			{
				((Form)this).DialogResult = (DialogResult)0;
				errorProvider.SetIconAlignment((Control)(object)buttonOk, (ErrorIconAlignment)2);
				errorProvider.SetError((Control)(object)buttonOk, "Please fix the input error before proceed");
			}
		}
	}
}
namespace Cummins.IDLLogger.EventDriven
{
	public class ConditionEdit : UserControl
	{
		internal const int LeadingSpace = 4;

		private ComboBox cmbConditionBase;

		private TextBox edValue;

		private ComboBox cmbRelation;

		private DateTimePicker dateTimePickerTime;

		private Container components;

		private RadioButton rbOR;

		private RadioButton rbAND;

		private ConditionEditController controller;

		[Browsable(false)]
		public string OutputCondition
		{
			get
			{
				string text = "";
				if (controller.Validate())
				{
					if (controller.ConditionType == ConditionType.Value)
					{
						text = ((Control)cmbConditionBase).Text + " " + ((Control)cmbRelation).Text + " " + ((Control)edValue).Text;
					}
					else if (controller.ConditionType == ConditionType.Blank)
					{
						text = string.Empty;
					}
					if (controller.ConditionType != ConditionType.Blank && rbAND.Checked)
					{
						text += " AND ";
					}
					else if (controller.ConditionType != ConditionType.Blank && rbOR.Checked)
					{
						text += " OR ";
					}
				}
				return text;
			}
		}

		[Browsable(false)]
		public bool IsValid => controller.Validate();

		public ConditionEdit()
		{
			InitializeComponent();
			ArrayList dataSource = (ArrayList)Global.MonitoredParameters.Clone();
			cmbConditionBase.DataSource = dataSource;
		}

		public ConditionEdit(ValueCondition condition)
		{
			InitializeComponent();
			ArrayList arrayList = (ArrayList)Global.MonitoredParameters.Clone();
			arrayList.AddRange(new string[1] { "" });
			cmbConditionBase.DataSource = arrayList;
			controller = new ConditionEditController();
			ConditionEditController conditionEditController = controller;
			conditionEditController.ConditionTypeChangedEvent = (EventHandler)Delegate.Combine(conditionEditController.ConditionTypeChangedEvent, new EventHandler(OnConditionTypeChanged));
			controller.Initialize(condition);
			cmbConditionBase.SelectedIndexChanged -= ConditionTypeIndexChanged;
			((Control)cmbConditionBase).Text = controller.ConditionBase;
			cmbConditionBase.SelectedIndexChanged += ConditionTypeIndexChanged;
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((ContainerControl)this).Dispose(disposing);
		}

		private void InitializeComponent()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Expected O, but got Unknown
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_002c: Expected O, but got Unknown
			//IL_002d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0037: Expected O, but got Unknown
			//IL_0038: Unknown result type (might be due to invalid IL or missing references)
			//IL_0042: Expected O, but got Unknown
			cmbRelation = new ComboBox();
			edValue = new TextBox();
			cmbConditionBase = new ComboBox();
			dateTimePickerTime = new DateTimePicker();
			rbOR = new RadioButton();
			rbAND = new RadioButton();
			((Control)this).SuspendLayout();
			((Control)cmbRelation).Location = new Point(216, 8);
			((Control)cmbRelation).Name = "cmbRelation";
			((Control)cmbRelation).Size = new Size(168, 21);
			((Control)cmbRelation).TabIndex = 2;
			cmbRelation.SelectedIndexChanged += RelationIndexChanged;
			((Control)edValue).Location = new Point(160, 8);
			((Control)edValue).Name = "edValue";
			((Control)edValue).Size = new Size(48, 20);
			((Control)edValue).TabIndex = 1;
			edValue.TextAlign = (HorizontalAlignment)1;
			((Control)edValue).TextChanged += OnValueChanged;
			cmbConditionBase.DropDownStyle = (ComboBoxStyle)2;
			cmbConditionBase.Items.AddRange(new object[5] { "", "_Engine_Speed", "_Coolant_Pressure", "TIME", "FAULT" });
			((Control)cmbConditionBase).Location = new Point(0, 8);
			((Control)cmbConditionBase).Name = "cmbConditionBase";
			((Control)cmbConditionBase).Size = new Size(152, 21);
			((Control)cmbConditionBase).TabIndex = 0;
			cmbConditionBase.SelectedIndexChanged += ConditionTypeIndexChanged;
			dateTimePickerTime.Format = (DateTimePickerFormat)4;
			((Control)dateTimePickerTime).Location = new Point(392, 8);
			((Control)dateTimePickerTime).Name = "dateTimePickerTime";
			dateTimePickerTime.ShowUpDown = true;
			((Control)dateTimePickerTime).Size = new Size(96, 20);
			((Control)dateTimePickerTime).TabIndex = 14;
			((Control)dateTimePickerTime).Visible = false;
			dateTimePickerTime.ValueChanged += OnValueChanged;
			((Control)rbOR).Location = new Point(64, 32);
			((Control)rbOR).Name = "rbOR";
			((Control)rbOR).Size = new Size(56, 16);
			((Control)rbOR).TabIndex = 4;
			((Control)rbOR).Text = "OR";
			((Control)rbOR).Visible = false;
			rbOR.CheckedChanged += OnConditionJoinerSuffixChanged;
			rbAND.Checked = true;
			((Control)rbAND).Location = new Point(8, 32);
			((Control)rbAND).Name = "rbAND";
			((Control)rbAND).Size = new Size(56, 16);
			((Control)rbAND).TabIndex = 3;
			rbAND.TabStop = true;
			((Control)rbAND).Text = "AND";
			((Control)rbAND).Visible = false;
			rbAND.CheckedChanged += OnConditionJoinerSuffixChanged;
			((Control)this).Controls.Add((Control)(object)rbOR);
			((Control)this).Controls.Add((Control)(object)rbAND);
			((Control)this).Controls.Add((Control)(object)dateTimePickerTime);
			((Control)this).Controls.Add((Control)(object)cmbConditionBase);
			((Control)this).Controls.Add((Control)(object)cmbRelation);
			((Control)this).Controls.Add((Control)(object)edValue);
			((Control)this).Name = "ConditionEdit";
			((Control)this).Size = new Size(424, 50);
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}

		private void ConditionTypeIndexChanged(object sender, EventArgs e)
		{
			try
			{
				controller.SelectConditionType(((Control)cmbConditionBase).Text);
			}
			catch
			{
			}
		}

		private void OnConditionTypeChanged(object sender, EventArgs e)
		{
			//IL_00b0: Unknown result type (might be due to invalid IL or missing references)
			try
			{
				UpdateUILayout();
				((ListControl)cmbRelation).SelectedIndex = controller.Relation;
				if (controller.ConditionType == ConditionType.Value || controller.ConditionType == ConditionType.Fault)
				{
					((Control)edValue).Text = controller.Value;
				}
				else if (controller.ConditionType == ConditionType.Time)
				{
					dateTimePickerTime.Value = Convert.ToDateTime(controller.Value);
				}
				if (controller.Suffix == ConditionJoiner.AND)
				{
					rbAND.Checked = true;
				}
				else
				{
					rbOR.Checked = true;
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message, "IDL", (MessageBoxButtons)0, (MessageBoxIcon)16);
			}
		}

		private void OnValueChanged(object sender, EventArgs e)
		{
			controller.Value = ((Control)((sender is Control) ? sender : null)).Text;
		}

		private void RelationIndexChanged(object sender, EventArgs e)
		{
			controller.Relation = ((ListControl)cmbRelation).SelectedIndex;
		}

		private void OnConditionJoinerSuffixChanged(object sender, EventArgs e)
		{
			if (rbAND.Checked)
			{
				controller.Suffix = ConditionJoiner.AND;
			}
			else
			{
				controller.Suffix = ConditionJoiner.OR;
			}
		}

		private void UpdateUILayout()
		{
			cmbRelation.SelectedIndexChanged -= RelationIndexChanged;
			cmbRelation.DataSource = null;
			cmbRelation.DropDownStyle = (ComboBoxStyle)2;
			((Control)cmbRelation).Width = 170;
			if (controller.ConditionType == ConditionType.Value)
			{
				cmbRelation.DataSource = controller.parameterOptionsArray.Clone();
			}
			else
			{
				cmbRelation.DataSource = null;
			}
			((Control)dateTimePickerTime).Visible = false;
			((Control)cmbRelation).Left = ((Control)cmbConditionBase).Left + ((Control)cmbConditionBase).Width + 4;
			((Control)edValue).Left = ((Control)cmbRelation).Left + ((Control)cmbRelation).Width + 4;
			((Control)edValue).Width = 65;
			((Control)edValue).Text = string.Empty;
			((Control)edValue).Visible = true;
			((Control)cmbRelation).TabIndex = 1;
			((Control)edValue).TabIndex = 2;
			((Control)dateTimePickerTime).TabIndex = 5;
			cmbRelation.SelectedIndexChanged += RelationIndexChanged;
		}
	}
	public enum ConditionType
	{
		Blank = -1,
		Value,
		Fault,
		Time
	}
	public class ConditionEditController
	{
		internal string[] faultOptionsArray = new string[3] { "becomes Active", "becomes Inactive", "New" };

		internal string[] parameterOptionsArray = new string[6] { "is greater than", "is greater than or equal to", "is less than", "is less than or equal to", "equals", "does not equals" };

		internal string[] timeOptionsArray = new string[2] { "is greater than or equal to", "is less than or equal to" };

		private ValueCondition condition;

		private ConditionType conditionType;

		private int relation;

		private string actualValue;

		private ConditionJoiner suffix;

		private string conditionBase = "";

		public EventHandler ConditionTypeChangedEvent;

		public EventHandler ConditionDataChangedEvent;

		public ConditionType ConditionType
		{
			get
			{
				return conditionType;
			}
			set
			{
				if (conditionType != value)
				{
					conditionType = value;
					RaiseConditionTypeChangedEvent();
				}
				if (conditionType == ConditionType.Blank)
				{
					Suffix = ConditionJoiner.AND;
					Relation = -1;
					Value = "";
				}
			}
		}

		public string ConditionBase
		{
			get
			{
				if (ConditionType == ConditionType.Fault)
				{
					conditionBase = "FAULT";
				}
				else if (ConditionType == ConditionType.Time)
				{
					conditionBase = "TIME";
				}
				return conditionBase;
			}
			set
			{
				conditionBase = value;
			}
		}

		public int Relation
		{
			get
			{
				int result = relation;
				if (ConditionType == ConditionType.Time)
				{
					result = ((relation > 2) ? 1 : 0);
				}
				return result;
			}
			set
			{
				relation = value;
			}
		}

		public string Value
		{
			get
			{
				string result = actualValue;
				if (ConditionType == ConditionType.Time)
				{
					try
					{
						Convert.ToDateTime(actualValue);
					}
					catch
					{
						result = DateTime.Now.ToShortTimeString();
					}
				}
				return result;
			}
			set
			{
				actualValue = value;
			}
		}

		public ConditionJoiner Suffix
		{
			get
			{
				return suffix;
			}
			set
			{
				suffix = value;
			}
		}

		public ConditionEditController()
		{
			ConditionType = ConditionType.Blank;
		}

		public void Initialize(ValueCondition condition)
		{
			this.condition = condition;
			if (condition != null)
			{
				Suffix = condition.Suffix;
				Relation = (int)condition.Operation;
				Value = condition.BaseValue;
				ConditionBase = condition.Name;
				ConditionType = ConditionType.Value;
			}
			else
			{
				ConditionType = ConditionType.Blank;
			}
		}

		public void SelectConditionType(string conditionType)
		{
			Relation = 0;
			Suffix = ConditionJoiner.AND;
			Value = "";
			if (conditionType == null || conditionType.Length == 0)
			{
				ConditionType = ConditionType.Blank;
			}
			else if (conditionType == "FAULT")
			{
				ConditionType = ConditionType.Fault;
			}
			else if (conditionType == "TIME")
			{
				ConditionType = ConditionType.Time;
			}
			else
			{
				ConditionType = ConditionType.Value;
			}
		}

		public bool Validate()
		{
			bool flag = true;
			if (ConditionType == ConditionType.Blank)
			{
				return true;
			}
			flag &= Relation != -1;
			return flag & (Value != "");
		}

		protected virtual void RaiseConditionTypeChangedEvent()
		{
			if (ConditionTypeChangedEvent != null)
			{
				ConditionTypeChangedEvent(this, EventArgs.Empty);
			}
		}

		protected virtual void RaiseConditionDataChangedEvent()
		{
			_ = ConditionDataChangedEvent;
		}
	}
	public class EventDrivenIDLController
	{
		internal const char UnderScore = '_';

		internal const char Dot = '.';

		private Hashtable idlDataProviderList = new Hashtable();

		private Hashtable paramMonitor = new Hashtable();

		private ArrayList registeredIdHolder = new ArrayList();

		private ArrayList _allRegisteredIds = new ArrayList();

		protected void OnEvaluate(object source)
		{
		}

		public void RegisterDataProvider(IDataProvider dataProvider)
		{
			if (dataProvider == null)
			{
				throw new ArgumentNullException("dataProvider");
			}
			lock (registeredIdHolder)
			{
				if (!registeredIdHolder.Contains(dataProvider.ID) && !_allRegisteredIds.Contains(dataProvider.ID))
				{
					dataProvider.Notification += OnDataRefreshed;
					_allRegisteredIds.Add(dataProvider.ID);
					idlDataProviderList.Add(dataProvider.ID, dataProvider);
				}
			}
		}

		public void UnRegisterDataProvider(IDataProvider dataProvider)
		{
			if (dataProvider == null)
			{
				throw new ArgumentNullException("dataProvider");
			}
			lock (registeredIdHolder)
			{
				if (registeredIdHolder.Contains(dataProvider.ID))
				{
					if (_allRegisteredIds.Contains(dataProvider.ID))
					{
						dataProvider.Notification -= OnDataRefreshed;
						_allRegisteredIds.Remove(dataProvider.ID);
					}
					registeredIdHolder.Remove(dataProvider.ID);
				}
			}
		}

		public void OnDataRefreshed(object sender, DataRefreshEventArgs e)
		{
			RecordData(e);
		}

		public void RecordData(DataRefreshEventArgs e)
		{
			bool flag = false;
			if (e.DataSourceType == DataSourceTypeEnum.ASAM)
			{
				if ((e as ASAMDataRefreshEventArgs).ASAMData != null)
				{
					flag = true;
				}
			}
			else if (e.DataSourceType == DataSourceTypeEnum.ECM)
			{
				if ((e as ECMDataRefreshEventArgs).ECMData != null)
				{
					flag = true;
				}
			}
			else if (e.DataSourceType == DataSourceTypeEnum.J1939_71 && (e as J1939_71DataRefreshEventArgs).J1939_71Data != null)
			{
				flag = true;
			}
			if (flag)
			{
				if (e.DataSourceType == DataSourceTypeEnum.ECM)
				{
					(e as ECMDataRefreshEventArgs).ECMData.ToString();
					RecordNotification((e as ECMDataRefreshEventArgs).ECMData, (e as ECMDataRefreshEventArgs).SourceAddress);
				}
				else if (e.DataSourceType == DataSourceTypeEnum.ASAM)
				{
					RecordNotification((e as ASAMDataRefreshEventArgs).ASAMData, (e as ASAMDataRefreshEventArgs).SourceAddress);
				}
				else if (e.DataSourceType == DataSourceTypeEnum.J1939_71)
				{
					CompositeJ1939_71Data compositeJ1939_71Data = new CompositeJ1939_71Data();
					PCLSubscriptionHelper.MergeJ1939_71Notifications(compositeJ1939_71Data, e as J1939_71DataRefreshEventArgs);
					RecordNotification(compositeJ1939_71Data);
				}
			}
		}

		protected bool RecordNotification(ArrayList parameterValues, IAddressValue sourceAddress)
		{
			string empty = string.Empty;
			CICPPMonitor cICPPMonitor = null;
			string empty2 = string.Empty;
			int num = -1;
			bool result = true;
			foreach (ICIDataElementNotification parameterValue in parameterValues)
			{
				try
				{
					if (parameterValue.Status == tagCIDMStatusEnum.DM_STATUS_OK)
					{
						cICPPMonitor = (CICPPMonitor)parameterValue.DataElementMonitor;
						switch (cICPPMonitor.mode)
						{
						case tagCIDMAccessModeEnum.DM_MODE_PARAMETER_ID:
						case tagCIDMAccessModeEnum.DM_MODE_NAME:
							empty2 = cICPPMonitor.location.ToString();
							num = empty2.LastIndexOf('.');
							if (num != -1)
							{
								empty2 = empty2.Substring(num + 1);
							}
							empty = IDLParamName(empty2, sourceAddress);
							UpdateMonitor(empty, parameterValue.ScaledValue);
							break;
						case tagCIDMAccessModeEnum.DM_MODE_ADDRESS:
							empty = IDLParamName((int)uint.Parse(cICPPMonitor.location.ToString()), cICPPMonitor.offset, cICPPMonitor.Length, sourceAddress);
							UpdateMonitor(empty, parameterValue.ScaledValue);
							break;
						}
					}
					else
					{
						result = false;
					}
				}
				catch (Exception)
				{
					result = false;
				}
			}
			return result;
		}

		protected bool RecordNotification(ICINotification asamNotification, IAddressValue sourceAddress)
		{
			bool result = true;
			ICIMonitorElement iCIMonitorElement = null;
			string empty = string.Empty;
			for (int i = 0; i < asamNotification.Count; i++)
			{
				iCIMonitorElement = asamNotification.GetElement(i);
				try
				{
					empty = string.Empty;
					empty = IDLParamName(iCIMonitorElement.Name, sourceAddress);
					if (iCIMonitorElement.Value == null)
					{
						result = false;
					}
					else
					{
						UpdateMonitor(empty, iCIMonitorElement.Value);
					}
				}
				catch (Exception)
				{
					result = false;
				}
			}
			return result;
		}

		protected bool RecordNotification(CompositeJ1939_71Data data)
		{
			bool result = true;
			string empty = string.Empty;
			J1939_71PGNMap j1939_71PGNMap = null;
			foreach (ushort key in data.Keys)
			{
				j1939_71PGNMap = data[key];
				foreach (PGN value in j1939_71PGNMap.Values)
				{
					if (value.SPNs == null)
					{
						continue;
					}
					foreach (SPN sPN in value.SPNs)
					{
						try
						{
							empty = string.Empty;
							empty = IDLParamName(SPN.FigureFullName(value.Name, sPN.Name), AddressFactory.ProductAddressValue(key));
							if (sPN.Value == null)
							{
								result = false;
							}
							else
							{
								UpdateMonitor(empty, sPN.Value);
							}
						}
						catch (Exception)
						{
							result = false;
						}
					}
				}
			}
			return result;
		}

		internal static string IDLParamName(string parameterName, IAddressValue sourceAddress)
		{
			return '_' + sourceAddress.Value + '_' + parameterName;
		}

		internal static string IDLParamName(int location, int offset, int length, IAddressValue sourceAddress)
		{
			return '_' + sourceAddress.Value + '_' + location.ToString("X8") + '_' + offset.ToString("X8") + '_' + length.ToString("X2");
		}

		protected void UpdateMonitor(string name, string val)
		{
			if (!paramMonitor.Contains(name))
			{
				paramMonitor.Add(name, val);
			}
			else
			{
				paramMonitor[name] = val;
			}
		}
	}
	public class Trigger
	{
		private ArrayList conditions;

		public ArrayList Conditions
		{
			get
			{
				if (conditions == null)
				{
					conditions = new ArrayList();
				}
				return conditions;
			}
		}

		public Trigger(string trigger, Hashtable idlParams)
		{
			if (trigger == null)
			{
				throw new ArgumentNullException("trigger");
			}
			if (trigger.Length <= 0)
			{
				return;
			}
			ValueCondition valueCondition = null;
			string empty = string.Empty;
			string empty2 = string.Empty;
			string text = trigger;
			int num = -1;
			int num2 = -1;
			Regex regex = new Regex(" OR | AND ");
			string[] array = regex.Split(trigger);
			if (array.Length == 0)
			{
				valueCondition = Create(trigger, idlParams);
				if (valueCondition != null)
				{
					Conditions.Add(valueCondition);
				}
			}
			else
			{
				if (array.Length > 4)
				{
					return;
				}
				for (int i = 0; i < array.Length; i++)
				{
					num2 = -1;
					empty2 = string.Empty;
					empty = array[i].Trim();
					num = text.IndexOf(empty);
					if (num != -1 && array.Length - i > 1)
					{
						num2 = text.IndexOf(array[i + 1], num + empty.Length);
						empty2 = text.Substring(num + empty.Length, num2 - (num + empty.Length));
					}
					valueCondition = Create(empty + " " + empty2, idlParams);
					if (valueCondition != null)
					{
						Conditions.Add(valueCondition);
					}
					if (num2 != -1)
					{
						text = text.Substring(num2);
					}
				}
			}
		}

		public ValueCondition Create(string condition, Hashtable idlParams)
		{
			if (condition == null)
			{
				throw new ArgumentNullException("condition");
			}
			ValueCondition valueCondition = null;
			condition = condition.Trim();
			if (idlParams != null)
			{
				return new ValueCondition(condition, idlParams);
			}
			return new ValueCondition(condition, null);
		}

		public bool Evaluate()
		{
			bool flag = false;
			if (Conditions.Count > 0)
			{
				flag = (Conditions[0] as ValueCondition).Evaluate();
			}
			bool flag2 = false;
			for (int i = 1; i < Conditions.Count; i++)
			{
				flag2 = (Conditions[i] as ValueCondition).Evaluate();
				switch ((Conditions[i - 1] as ValueCondition).Suffix)
				{
				case ConditionJoiner.AND:
					flag = flag && flag2;
					break;
				case ConditionJoiner.OR:
					flag = flag || flag2;
					break;
				}
			}
			return flag;
		}
	}
	public class TriggerConfigurationDlg : Form
	{
		private TriggerLoggingOptions triggerOptions;

		private IContainer components;

		private GroupBox gbStartTrigger;

		private Label laPreTrigger;

		private TextBox edPreTrigger;

		private Label laPreTriggerSeconds;

		private TextBox edStartTrigger;

		private CheckBox ckEnableStartTrigger;

		private Button btnEditStartTrigger;

		private GroupBox gbTriggers;

		private Label laPostTriggerSeconds;

		private Label laPostTrigger;

		private TextBox edPostTrigger;

		private CheckBox ckEnableStopTrigger;

		private TextBox edStopTrigger;

		private Button btnEditStopTrigger;

		private TextBox edRepeat;

		private Label laRepeatTimes;

		private CheckBox ckRepeatLogging;

		private Button btnCancel;

		private Button btnOK;

		public TriggerConfigurationDlg()
		{
			InitializeComponent();
		}

		public TriggerConfigurationDlg(TriggerLoggingOptions triggerOptions)
		{
			InitializeComponent();
			this.triggerOptions = triggerOptions;
			((Control)edStartTrigger).Text = triggerOptions.StartTrigger;
			ckEnableStartTrigger.Checked = triggerOptions.StartTrigger.Length != 0;
			((Control)edStopTrigger).Text = triggerOptions.StopTrigger;
			ckEnableStopTrigger.Checked = triggerOptions.StopTrigger.Length != 0;
			((Control)edPreTrigger).Text = triggerOptions.PreTrigger.ToString();
			((Control)edPostTrigger).Text = triggerOptions.PostTrigger.ToString();
			ckRepeatLogging.Checked = triggerOptions.RepeatCount != 0;
			((Control)edRepeat).Enabled = triggerOptions.RepeatCount != 0;
			((Control)edRepeat).Text = triggerOptions.RepeatCount.ToString();
			EnableDisableUIComponents();
		}

		private void btnEditStartTrigger_Click(object sender, EventArgs e)
		{
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0023: Invalid comparison between Unknown and I4
			TriggerEditor triggerEditor = new TriggerEditor(((Control)edStartTrigger).Text);
			triggerEditor.HeadingText = "Edit Start Condition";
			if ((int)((Form)triggerEditor).ShowDialog() == 1)
			{
				((Control)edStartTrigger).Text = triggerEditor.OutputTrigger;
			}
		}

		private void btnOK_Click(object sender, EventArgs e)
		{
			bool flag = true;
			if (ckEnableStartTrigger.Checked)
			{
				if (((Control)edStartTrigger).Text.Trim().Length > 0)
				{
					try
					{
						new Trigger(((Control)edStartTrigger).Text, null);
					}
					catch
					{
						flag = InvalidateForm("Please specify a Start Trigger", (Control)(object)edStartTrigger);
					}
				}
				else
				{
					flag = InvalidateForm("Please specify a Start Trigger", (Control)(object)edStartTrigger);
				}
			}
			else
			{
				flag = false;
			}
			if (flag)
			{
				if (ckEnableStopTrigger.Checked)
				{
					if (((Control)edStopTrigger).Text.Trim().Length == 0)
					{
						flag = InvalidateForm("Please specify a Stop Trigger", (Control)(object)edStopTrigger);
					}
					else
					{
						try
						{
							new Trigger(((Control)edStopTrigger).Text, null);
						}
						catch
						{
							flag = InvalidateForm("Please specify a Stop Trigger", (Control)(object)edStopTrigger);
						}
					}
				}
				else if (((Control)edPostTrigger).Text.Trim().Length == 0)
				{
					flag = InvalidateForm("Please specify a valid number for Duration of IDL logging", (Control)(object)edPostTrigger);
				}
			}
			if (flag && ((Control)edPreTrigger).Text.Length != 0)
			{
				flag = ValidateNumericField((Control)(object)edPreTrigger, "Please specify a numeric value for PreTrigger");
			}
			if (flag && !ckEnableStopTrigger.Checked && ((Control)edPostTrigger).Text.Length != 0)
			{
				flag = ValidateNumericField((Control)(object)edPostTrigger, "Please specify a numeric value for Duration of IDL logging");
			}
			if (flag && ((Control)edRepeat).Text.Trim().Length != 0)
			{
				flag = ValidateNumericField((Control)(object)edRepeat, "Please specify a numeric value for Repeat count of IDL logging cycle");
			}
			if (flag)
			{
				((Form)this).DialogResult = (DialogResult)1;
				Global.mode = Mode.EventDriven;
			}
		}

		public void DoDataExchange()
		{
			if (ckEnableStartTrigger.Checked)
			{
				triggerOptions.StartTrigger = ((Control)edStartTrigger).Text;
			}
			else
			{
				triggerOptions.StartTrigger = "";
			}
			if (ckEnableStopTrigger.Checked)
			{
				triggerOptions.StopTrigger = ((Control)edStopTrigger).Text;
			}
			else
			{
				triggerOptions.StopTrigger = "";
			}
			triggerOptions.PreTrigger = int.Parse(((Control)edPreTrigger).Text);
			triggerOptions.PostTrigger = int.Parse(((Control)edPostTrigger).Text);
			triggerOptions.RepeatCount = int.Parse(((Control)edRepeat).Text);
			triggerOptions.Save();
		}

		private bool InvalidateForm(string message, Control focusControl)
		{
			//IL_0009: Unknown result type (might be due to invalid IL or missing references)
			MessageBox.Show(message, "IDL Logging", (MessageBoxButtons)0, (MessageBoxIcon)64);
			focusControl.Focus();
			((Form)this).DialogResult = (DialogResult)0;
			return false;
		}

		private void btnEditStopTrigger_Click(object sender, EventArgs e)
		{
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0023: Invalid comparison between Unknown and I4
			TriggerEditor triggerEditor = new TriggerEditor(((Control)edStopTrigger).Text);
			triggerEditor.HeadingText = "Edit Stop Condition";
			if ((int)((Form)triggerEditor).ShowDialog() == 1)
			{
				((Control)edStopTrigger).Text = triggerEditor.OutputTrigger;
			}
		}

		private void ckEnableStartTrigger_CheckedChanged(object sender, EventArgs e)
		{
			EnableDisableUIComponents();
		}

		private bool ValidateNumericField(Control field, string message)
		{
			bool result = true;
			try
			{
				int.Parse(((Control)edPreTrigger).Text);
			}
			catch
			{
				result = InvalidateForm(message, field);
			}
			return result;
		}

		private void EnableDisableUIComponents()
		{
			((Control)edStartTrigger).Enabled = ckEnableStartTrigger.Checked;
			((Control)btnEditStartTrigger).Enabled = ckEnableStartTrigger.Checked;
			((Control)edPreTrigger).Enabled = ckEnableStartTrigger.Checked;
			((Control)ckEnableStopTrigger).Enabled = ckEnableStartTrigger.Checked;
			((Control)edStopTrigger).Enabled = ((Control)ckEnableStopTrigger).Enabled && ckEnableStopTrigger.Checked;
			((Control)btnEditStopTrigger).Enabled = ((Control)ckEnableStopTrigger).Enabled && ckEnableStopTrigger.Checked;
			((Control)edPostTrigger).Enabled = ckEnableStartTrigger.Checked && !ckEnableStopTrigger.Checked;
			((Control)ckRepeatLogging).Enabled = ckEnableStartTrigger.Checked && (ckEnableStopTrigger.Checked || ((Control)edPostTrigger).Text.Trim().Length != 0);
			((Control)edRepeat).Enabled = ckRepeatLogging.Checked;
			if (!ckRepeatLogging.Checked)
			{
				((Control)edRepeat).Text = "0";
			}
		}

		private void ckEnableStopTrigger_CheckedChanged(object sender, EventArgs e)
		{
			EnableDisableUIComponents();
		}

		private void btnCancel_Click(object sender, EventArgs e)
		{
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
			//IL_0345: Unknown result type (might be due to invalid IL or missing references)
			//IL_034f: Expected O, but got Unknown
			//IL_0739: Unknown result type (might be due to invalid IL or missing references)
			//IL_0743: Expected O, but got Unknown
			//IL_0af4: Unknown result type (might be due to invalid IL or missing references)
			//IL_0afe: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(TriggerConfigurationDlg));
			gbStartTrigger = new GroupBox();
			laPreTrigger = new Label();
			edPreTrigger = new TextBox();
			laPreTriggerSeconds = new Label();
			edStartTrigger = new TextBox();
			ckEnableStartTrigger = new CheckBox();
			btnEditStartTrigger = new Button();
			gbTriggers = new GroupBox();
			laPostTriggerSeconds = new Label();
			laPostTrigger = new Label();
			edPostTrigger = new TextBox();
			ckEnableStopTrigger = new CheckBox();
			edStopTrigger = new TextBox();
			btnEditStopTrigger = new Button();
			edRepeat = new TextBox();
			laRepeatTimes = new Label();
			ckRepeatLogging = new CheckBox();
			btnCancel = new Button();
			btnOK = new Button();
			((Control)gbStartTrigger).SuspendLayout();
			((Control)gbTriggers).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)gbStartTrigger).Controls.Add((Control)(object)laPreTrigger);
			((Control)gbStartTrigger).Controls.Add((Control)(object)edPreTrigger);
			((Control)gbStartTrigger).Controls.Add((Control)(object)laPreTriggerSeconds);
			((Control)gbStartTrigger).Controls.Add((Control)(object)edStartTrigger);
			((Control)gbStartTrigger).Controls.Add((Control)(object)ckEnableStartTrigger);
			((Control)gbStartTrigger).Controls.Add((Control)(object)btnEditStartTrigger);
			((Control)gbStartTrigger).Location = new Point(0, 10);
			((Control)gbStartTrigger).Name = "gbStartTrigger";
			((Control)gbStartTrigger).Size = new Size(488, 128);
			((Control)gbStartTrigger).TabIndex = 2;
			gbStartTrigger.TabStop = false;
			((Control)gbStartTrigger).Text = "Starting Configuration";
			((Control)laPreTrigger).Location = new Point(8, 88);
			((Control)laPreTrigger).Name = "laPreTrigger";
			((Control)laPreTrigger).Size = new Size(360, 26);
			((Control)laPreTrigger).TabIndex = 5;
			((Control)laPreTrigger).Text = "&Pretrigger (Time interval prior to the start trigger getting active from which data should actually be logged) :";
			((Control)laPreTrigger).Visible = false;
			((Control)edPreTrigger).Location = new Point(376, 91);
			((TextBoxBase)edPreTrigger).MaxLength = 5;
			((Control)edPreTrigger).Name = "edPreTrigger";
			((Control)edPreTrigger).Size = new Size(48, 20);
			((Control)edPreTrigger).TabIndex = 6;
			((Control)edPreTrigger).Text = "0";
			edPreTrigger.TextAlign = (HorizontalAlignment)1;
			((Control)edPreTrigger).Visible = false;
			((Control)laPreTriggerSeconds).AutoSize = true;
			((Control)laPreTriggerSeconds).Location = new Point(434, 93);
			((Control)laPreTriggerSeconds).Name = "laPreTriggerSeconds";
			((Control)laPreTriggerSeconds).Size = new Size(47, 13);
			((Control)laPreTriggerSeconds).TabIndex = 7;
			((Control)laPreTriggerSeconds).Text = "seconds";
			((Control)laPreTriggerSeconds).Visible = false;
			((Control)edStartTrigger).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)edStartTrigger).Location = new Point(8, 40);
			((TextBoxBase)edStartTrigger).Multiline = true;
			((Control)edStartTrigger).Name = "edStartTrigger";
			((Control)edStartTrigger).Size = new Size(472, 40);
			((Control)edStartTrigger).TabIndex = 4;
			((Control)ckEnableStartTrigger).Location = new Point(8, 16);
			((Control)ckEnableStartTrigger).Name = "ckEnableStartTrigger";
			((Control)ckEnableStartTrigger).Size = new Size(136, 24);
			((Control)ckEnableStartTrigger).TabIndex = 2;
			((Control)ckEnableStartTrigger).Text = "Enable &Start Trigger";
			ckEnableStartTrigger.CheckedChanged += ckEnableStartTrigger_CheckedChanged;
			((Control)btnEditStartTrigger).Location = new Point(360, 16);
			((Control)btnEditStartTrigger).Name = "btnEditStartTrigger";
			((Control)btnEditStartTrigger).Size = new Size(120, 23);
			((Control)btnEditStartTrigger).TabIndex = 3;
			((Control)btnEditStartTrigger).Text = "&Edit Start Trigger";
			((Control)btnEditStartTrigger).Click += btnEditStartTrigger_Click;
			((Control)gbTriggers).Controls.Add((Control)(object)laPostTriggerSeconds);
			((Control)gbTriggers).Controls.Add((Control)(object)laPostTrigger);
			((Control)gbTriggers).Controls.Add((Control)(object)edPostTrigger);
			((Control)gbTriggers).Controls.Add((Control)(object)ckEnableStopTrigger);
			((Control)gbTriggers).Controls.Add((Control)(object)edStopTrigger);
			((Control)gbTriggers).Controls.Add((Control)(object)btnEditStopTrigger);
			((Control)gbTriggers).Location = new Point(0, 149);
			((Control)gbTriggers).Name = "gbTriggers";
			((Control)gbTriggers).Size = new Size(488, 136);
			((Control)gbTriggers).TabIndex = 9;
			gbTriggers.TabStop = false;
			((Control)gbTriggers).Text = "Stopping Configuration";
			((Control)laPostTriggerSeconds).AutoSize = true;
			((Control)laPostTriggerSeconds).Location = new Point(434, 101);
			((Control)laPostTriggerSeconds).Name = "laPostTriggerSeconds";
			((Control)laPostTriggerSeconds).Size = new Size(47, 13);
			((Control)laPostTriggerSeconds).TabIndex = 14;
			((Control)laPostTriggerSeconds).Text = "seconds";
			((Control)laPostTriggerSeconds).Visible = false;
			((Control)laPostTrigger).Location = new Point(8, 96);
			((Control)laPostTrigger).Name = "laPostTrigger";
			((Control)laPostTrigger).Size = new Size(360, 26);
			((Control)laPostTrigger).TabIndex = 12;
			((Control)laPostTrigger).Text = "&Duration upto which Logging should continue once it has been started  automatically by the start trigger:";
			((Control)laPostTrigger).Visible = false;
			((Control)edPostTrigger).Location = new Point(376, 99);
			((TextBoxBase)edPostTrigger).MaxLength = 5;
			((Control)edPostTrigger).Name = "edPostTrigger";
			((Control)edPostTrigger).Size = new Size(48, 20);
			((Control)edPostTrigger).TabIndex = 13;
			((Control)edPostTrigger).Text = "0";
			edPostTrigger.TextAlign = (HorizontalAlignment)1;
			((Control)edPostTrigger).Visible = false;
			((Control)ckEnableStopTrigger).Location = new Point(8, 24);
			((Control)ckEnableStopTrigger).Name = "ckEnableStopTrigger";
			((Control)ckEnableStopTrigger).Size = new Size(136, 24);
			((Control)ckEnableStopTrigger).TabIndex = 9;
			((Control)ckEnableStopTrigger).Text = "Enable Stop T&rigger";
			ckEnableStopTrigger.CheckedChanged += ckEnableStartTrigger_CheckedChanged;
			((Control)edStopTrigger).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)edStopTrigger).Location = new Point(8, 48);
			((TextBoxBase)edStopTrigger).Multiline = true;
			((Control)edStopTrigger).Name = "edStopTrigger";
			((Control)edStopTrigger).Size = new Size(472, 40);
			((Control)edStopTrigger).TabIndex = 11;
			((Control)btnEditStopTrigger).Location = new Point(360, 24);
			((Control)btnEditStopTrigger).Name = "btnEditStopTrigger";
			((Control)btnEditStopTrigger).Size = new Size(120, 23);
			((Control)btnEditStopTrigger).TabIndex = 10;
			((Control)btnEditStopTrigger).Text = "Edit S&top Trigger";
			((Control)btnEditStopTrigger).Click += btnEditStopTrigger_Click;
			((Control)edRepeat).Location = new Point(155, 293);
			((Control)edRepeat).Name = "edRepeat";
			((Control)edRepeat).Size = new Size(40, 20);
			((Control)edRepeat).TabIndex = 21;
			((Control)edRepeat).Text = "0";
			edRepeat.TextAlign = (HorizontalAlignment)1;
			((Control)laRepeatTimes).Location = new Point(197, 299);
			((Control)laRepeatTimes).Name = "laRepeatTimes";
			((Control)laRepeatTimes).Size = new Size(32, 8);
			((Control)laRepeatTimes).TabIndex = 22;
			((Control)laRepeatTimes).Text = "times";
			laRepeatTimes.TextAlign = (ContentAlignment)16;
			((Control)ckRepeatLogging).Location = new Point(0, 295);
			((Control)ckRepeatLogging).Name = "ckRepeatLogging";
			((Control)ckRepeatLogging).Size = new Size(147, 16);
			((Control)ckRepeatLogging).TabIndex = 20;
			((Control)ckRepeatLogging).Text = "&Repeat Logging cycle :";
			ckRepeatLogging.CheckedChanged += ckEnableStartTrigger_CheckedChanged;
			btnCancel.DialogResult = (DialogResult)2;
			((Control)btnCancel).Location = new Point(413, 327);
			((Control)btnCancel).Name = "btnCancel";
			((Control)btnCancel).Size = new Size(75, 23);
			((Control)btnCancel).TabIndex = 24;
			((Control)btnCancel).Text = "Cancel";
			((Control)btnCancel).Click += btnCancel_Click;
			btnOK.DialogResult = (DialogResult)1;
			((Control)btnOK).Location = new Point(323, 327);
			((Control)btnOK).Name = "btnOK";
			((Control)btnOK).Size = new Size(75, 23);
			((Control)btnOK).TabIndex = 23;
			((Control)btnOK).Text = "OK";
			((Control)btnOK).Click += btnOK_Click;
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Form)this).ClientSize = new Size(488, 357);
			((Control)this).Controls.Add((Control)(object)edRepeat);
			((Control)this).Controls.Add((Control)(object)laRepeatTimes);
			((Control)this).Controls.Add((Control)(object)ckRepeatLogging);
			((Control)this).Controls.Add((Control)(object)btnCancel);
			((Control)this).Controls.Add((Control)(object)btnOK);
			((Control)this).Controls.Add((Control)(object)gbTriggers);
			((Control)this).Controls.Add((Control)(object)gbStartTrigger);
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Control)this).Name = "TriggerConfigurationDlg";
			((Control)this).Text = "Event Driven IDL";
			((Control)gbStartTrigger).ResumeLayout(false);
			((Control)gbStartTrigger).PerformLayout();
			((Control)gbTriggers).ResumeLayout(false);
			((Control)gbTriggers).PerformLayout();
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}
	}
	public class Global
	{
		public static IDLState state = IDLState.Idle;

		public static Mode mode = Mode.Manual;

		public static bool eventDrivenStarted = false;

		public static bool eventDrivenStopped = false;

		public static int repeatCount = 0;

		public static ArrayList MonitoredParameters = new ArrayList();

		public static ArrayList logParamList = new ArrayList();

		public static TriggerLoggingOptions triggerOptions = new TriggerLoggingOptions();
	}
	internal enum MessageIDs
	{
		UnableToLoadLogfileSchema = 1,
		InvalidCondition,
		MalformedValueCondition,
		ConditionJoinerInvalid,
		MalformedFaultCondition,
		MalformedTimerCondition,
		InvalidTime,
		InvalidTrigger,
		InsufficientDiskSpace,
		NoUpdateRateSpecified,
		NegativeUpdateRateSpecified
	}
	public class TriggerEditor : Form
	{
		internal const int MaxConditions = 1;

		private string condition;

		private string UnderScore = "_";

		private string TriggerName;

		private ConditionEdit[] conditionEditList;

		private string outputTrigger = string.Empty;

		private Trigger trigger;

		private IContainer components;

		private Button buttonCancel;

		private Button buttonOK;

		[Browsable(false)]
		public string HeadingText
		{
			set
			{
				((Control)this).Text = value;
			}
		}

		[Browsable(false)]
		public string OutputTrigger
		{
			get
			{
				if (outputTrigger.EndsWith("OR "))
				{
					outputTrigger = outputTrigger.Remove(outputTrigger.LastIndexOf("OR "), 3);
				}
				else if (outputTrigger.EndsWith("AND "))
				{
					outputTrigger = outputTrigger.Remove(outputTrigger.LastIndexOf("AND "), 4);
				}
				return outputTrigger;
			}
		}

		public TriggerEditor()
		{
			InitializeComponent();
		}

		public TriggerEditor(string trigger)
		{
			this.trigger = new Trigger(trigger, null);
			InitializeComponent();
			CreateConditionEdits();
		}

		private void CreateConditionEdits()
		{
			int num = 50;
			conditionEditList = new ConditionEdit[1];
			for (int i = 0; i < trigger.Conditions.Count; i++)
			{
				conditionEditList[i] = new ConditionEdit(trigger.Conditions[i] as ValueCondition);
				((Control)conditionEditList[i]).Location = new Point(8, num * i);
				((Control)conditionEditList[i]).Name = "conditionEdit" + i;
				((Control)conditionEditList[i]).Size = new Size(424, num);
				((Control)conditionEditList[i]).TabIndex = i;
			}
			for (int j = trigger.Conditions.Count; j < 1; j++)
			{
				conditionEditList[j] = new ConditionEdit(null);
				((Control)conditionEditList[j]).Location = new Point(8, num * j);
				((Control)conditionEditList[j]).Name = "conditionEdit" + j;
				((Control)conditionEditList[j]).Size = new Size(424, num);
				((Control)conditionEditList[j]).TabIndex = j;
			}
			((Control)this).Controls.AddRange((Control[])(object)conditionEditList);
		}

		private void buttonOK_Click(object sender, EventArgs e)
		{
			//IL_002f: Unknown result type (might be due to invalid IL or missing references)
			bool flag = true;
			for (int i = 0; i < conditionEditList.Length; i++)
			{
				if (!conditionEditList[i].IsValid)
				{
					string text = $"Condition {i} is incorrect or not fully specfied. Please correct the condition.";
					MessageBox.Show(text, "Logging", (MessageBoxButtons)0, (MessageBoxIcon)48);
					((Control)conditionEditList[i]).Focus();
					flag = false;
					break;
				}
			}
			outputTrigger = "";
			if (flag)
			{
				ConditionEdit[] array = conditionEditList;
				foreach (ConditionEdit conditionEdit in array)
				{
					if (conditionEdit.OutputCondition.Length != 0)
					{
						outputTrigger += conditionEdit.OutputCondition;
					}
				}
			}
			else
			{
				((Form)this).DialogResult = (DialogResult)0;
			}
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
			//IL_016d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0177: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(TriggerEditor));
			buttonCancel = new Button();
			buttonOK = new Button();
			((Control)this).SuspendLayout();
			buttonCancel.DialogResult = (DialogResult)2;
			((Control)buttonCancel).Location = new Point(184, 232);
			((Control)buttonCancel).Name = "buttonCancel";
			((Control)buttonCancel).Size = new Size(75, 23);
			((Control)buttonCancel).TabIndex = 22;
			((Control)buttonCancel).Text = "Cancel";
			buttonOK.DialogResult = (DialogResult)1;
			((Control)buttonOK).Location = new Point(96, 232);
			((Control)buttonOK).Name = "buttonOK";
			((Control)buttonOK).Size = new Size(75, 23);
			((Control)buttonOK).TabIndex = 21;
			((Control)buttonOK).Text = "OK";
			((Control)buttonOK).Click += buttonOK_Click;
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Form)this).ClientSize = new Size(504, 254);
			((Control)this).Controls.Add((Control)(object)buttonCancel);
			((Control)this).Controls.Add((Control)(object)buttonOK);
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Control)this).Name = "TriggerEditor";
			((Control)this).Text = "Trigger Editor";
			((Control)this).ResumeLayout(false);
		}
	}
	public class TriggerLoggingOptions
	{
		internal const string TriggerFile = "IDLtrigger.xml";

		internal const int DefaultPreTrigger = 5;

		internal const int DefaultPostTrigger = 60;

		internal const string Slash = "\\";

		private string startTrigger;

		private string stopTrigger;

		private int repeatCount;

		private int preTrigger;

		private int postTrigger;

		private EventHandler triggerOptionsChangedEvent;

		private EventHandler startTriggerChangedEvent;

		private EventHandler stopTriggerChangedEvent;

		private EventHandler repeatCountChangedEvent;

		private DataRow dataRow;

		public bool StartTriggerSpecified => StartTrigger.Length > 0;

		public string StartTrigger
		{
			get
			{
				return startTrigger;
			}
			set
			{
				if (startTrigger != value)
				{
					startTrigger = value;
					RaiseStartTriggerChangedEvent();
				}
			}
		}

		public bool StopTriggerSpecified
		{
			get
			{
				if (StopTrigger.Length <= 0)
				{
					return PostTrigger != 0;
				}
				return true;
			}
		}

		public string StopTrigger
		{
			get
			{
				return stopTrigger;
			}
			set
			{
				if (stopTrigger != value)
				{
					stopTrigger = value;
					RaiseStopTriggerChangedEvent();
				}
			}
		}

		public int PreTrigger
		{
			get
			{
				return preTrigger;
			}
			set
			{
				preTrigger = value;
			}
		}

		public int PostTrigger
		{
			get
			{
				return postTrigger;
			}
			set
			{
				postTrigger = value;
			}
		}

		public int RepeatCount
		{
			get
			{
				return repeatCount;
			}
			set
			{
				if (repeatCount != value)
				{
					repeatCount = value;
					RaiseRepeatCountChangedEvent();
				}
			}
		}

		public EventHandler TriggerOptionsChangedEvent
		{
			get
			{
				return triggerOptionsChangedEvent;
			}
			set
			{
				triggerOptionsChangedEvent = value;
			}
		}

		public EventHandler StopTriggerChangedEvent
		{
			get
			{
				return stopTriggerChangedEvent;
			}
			set
			{
				stopTriggerChangedEvent = value;
			}
		}

		public EventHandler StartTriggerChangedEvent
		{
			get
			{
				return startTriggerChangedEvent;
			}
			set
			{
				startTriggerChangedEvent = value;
			}
		}

		public EventHandler RepeatCountChangedEvent
		{
			get
			{
				return repeatCountChangedEvent;
			}
			set
			{
				repeatCountChangedEvent = value;
			}
		}

		public TriggerLoggingOptions()
		{
			//IL_00ac: Expected O, but got Unknown
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0044: Expected O, but got Unknown
			//IL_0045: Unknown result type (might be due to invalid IL or missing references)
			startTrigger = string.Empty;
			stopTrigger = string.Empty;
			preTrigger = 5;
			postTrigger = 60;
			repeatCount = 0;
			InitFromAppConfigService();
			try
			{
				XmlTextReader val = new XmlTextReader(GetTriggerFileName());
				((XmlReader)val).MoveToContent();
				((XmlReader)val).Read();
				StartTrigger = ((XmlReader)val).ReadElementString();
				StopTrigger = ((XmlReader)val).ReadElementString();
				PreTrigger = int.Parse(((XmlReader)val).ReadElementString());
				PostTrigger = int.Parse(((XmlReader)val).ReadElementString());
				RepeatCount = int.Parse(((XmlReader)val).ReadElementString());
				((XmlReader)val).ReadEndElement();
				((XmlReader)val).Close();
			}
			catch (XmlException ex)
			{
				XmlException ex2 = ex;
				EventLogger.Warn("Logging", "XML Exception in TriggerOptions creation " + ((Exception)(object)ex2).Message);
			}
			catch (FileNotFoundException)
			{
			}
			catch (Exception ex4)
			{
				EventLogger.Error("Logging", "Unknown error in TriggerOptions : " + ex4.Message);
			}
		}

		public void Initialize(DataRow dataRow)
		{
			try
			{
				startTrigger = dataRow["StartCondition"].ToString();
				stopTrigger = dataRow["StopCondition"].ToString();
				preTrigger = (int)dataRow["PreTrigger"];
				postTrigger = (int)dataRow["PostTrigger"];
				repeatCount = (int)dataRow["RepeatCount"];
				this.dataRow = dataRow;
			}
			catch (Exception ex)
			{
				EventLogger.Error("Logging", "Unknown error in TriggerOptions : " + ex.Message);
			}
		}

		public void Save()
		{
			//IL_0014: Unknown result type (might be due to invalid IL or missing references)
			//IL_001a: Expected O, but got Unknown
			FileStream fileStream = File.Open(GetTriggerFileName(), FileMode.Create, FileAccess.Write);
			XmlTextWriter val = new XmlTextWriter((Stream)fileStream, Encoding.UTF8);
			((XmlWriter)val).WriteStartDocument();
			((XmlWriter)val).WriteStartElement("trigger");
			((XmlWriter)val).WriteElementString("startCondition", StartTrigger);
			((XmlWriter)val).WriteElementString("stopCondition", StopTrigger);
			((XmlWriter)val).WriteElementString("preTrigger", PreTrigger.ToString());
			((XmlWriter)val).WriteElementString("postTrigger", PostTrigger.ToString());
			((XmlWriter)val).WriteElementString("repeatCount", RepeatCount.ToString());
			((XmlWriter)val).WriteEndElement();
			((XmlWriter)val).WriteEndDocument();
			((XmlWriter)val).Close();
			fileStream.Close();
			RaiseTriggerOptionsChangedEvent();
		}

		protected virtual void RaiseTriggerOptionsChangedEvent()
		{
			if (TriggerOptionsChangedEvent != null)
			{
				TriggerOptionsChangedEvent(this, EventArgs.Empty);
			}
		}

		protected virtual void RaiseStopTriggerChangedEvent()
		{
			if (StopTriggerChangedEvent != null)
			{
				StopTriggerChangedEvent(this, EventArgs.Empty);
			}
		}

		protected virtual void RaiseStartTriggerChangedEvent()
		{
			if (StartTriggerChangedEvent != null)
			{
				StartTriggerChangedEvent(this, EventArgs.Empty);
			}
		}

		protected virtual void RaiseRepeatCountChangedEvent()
		{
			if (RepeatCountChangedEvent != null)
			{
				RepeatCountChangedEvent(this, EventArgs.Empty);
			}
		}

		private string GetTriggerFileName()
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
			string text = directoryService.FolderName(FolderType.Product, appSetting);
			return text + "\\IDLtrigger.xml";
		}

		private void InitFromAppConfigService()
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			if (appConfigService != null)
			{
				try
				{
					preTrigger = int.Parse(appConfigService.GetAppSetting(ApplicationSettings.PreTrigger));
				}
				catch
				{
					preTrigger = 5;
					appConfigService.SetAppSetting(ApplicationSettings.PreTrigger, preTrigger.ToString());
				}
				try
				{
					postTrigger = int.Parse(appConfigService.GetAppSetting(ApplicationSettings.PostTrigger));
				}
				catch
				{
					postTrigger = 60;
					appConfigService.SetAppSetting(ApplicationSettings.PostTrigger, postTrigger.ToString());
				}
			}
		}
	}
	public class ValueCondition
	{
		private const string valuePattern = "[0-9,a-f,A-F]{2}[:]{1}\\w+\\s+(is greater than|is less than|equals|does not equals|is greater than or equal to|is less than or equal to|>|<|=|!=|>=|<=)\\s+(\\d+[.]?\\d*)\\s*(\\s*|AND\\s*|OR\\s*)$";

		public const string suffixOR = "OR";

		public const string suffixAND = "AND";

		internal const char UnderScore = '_';

		private string name;

		private Operation operation;

		private double scaledFloat;

		private Hashtable IDLParams;

		private string baseValue;

		private ConditionJoiner suffix;

		public string BaseValue
		{
			get
			{
				return baseValue;
			}
			set
			{
				baseValue = value;
			}
		}

		public ConditionJoiner Suffix
		{
			get
			{
				return suffix;
			}
			set
			{
				suffix = value;
			}
		}

		public string Name
		{
			get
			{
				return name.Trim();
			}
			set
			{
				name = value;
			}
		}

		public Operation Operation
		{
			get
			{
				return operation;
			}
			set
			{
				operation = value;
			}
		}

		public double ScaledFloat => scaledFloat;

		internal ValueCondition(string condition, Hashtable IDLParams)
		{
			Validate(condition);
			this.IDLParams = IDLParams;
			string pattern = "does not equals|equals|is greater than or equal to|is less than or equal to|is greater than|is less than|>=|<=|!=|=|>|<";
			Regex regex = new Regex(pattern);
			string[] array = regex.Split(condition);
			if (array.Length == 2)
			{
				Name = array[0];
				BaseValue = array[1];
				Suffix = ConditionJoiner.NONE;
				if (array[1].Trim().EndsWith("OR"))
				{
					Suffix = ConditionJoiner.OR;
					BaseValue = array[1].Remove(array[1].LastIndexOf("OR"), "OR".Length);
					condition = condition.Remove(condition.LastIndexOf("OR"), "OR".Length);
				}
				else if (array[1].Trim().EndsWith("AND"))
				{
					Suffix = ConditionJoiner.AND;
					BaseValue = array[1].Remove(array[1].LastIndexOf("AND"), "AND".Length);
					condition = condition.Remove(condition.LastIndexOf("AND"), "AND".Length);
				}
				string text = condition.Remove(condition.LastIndexOf(Name), Name.Length);
				text = text.Remove(text.LastIndexOf(BaseValue), BaseValue.Length);
				switch (text.Trim())
				{
				case "is less than":
				case "<":
					Operation = Operation.LessThan;
					break;
				case "is greater than":
				case ">":
					Operation = Operation.GreaterThan;
					break;
				case "equals":
				case "=":
					Operation = Operation.Equal;
					break;
				case "does not equals":
				case "!=":
					Operation = Operation.NotEqual;
					break;
				case "is greater than or equal to":
				case ">=":
					Operation = Operation.GreatherThanEqual;
					break;
				case "is less than or equal to":
				case "<=":
					Operation = Operation.LessThanEqual;
					break;
				}
				try
				{
					scaledFloat = double.Parse(BaseValue);
					return;
				}
				catch (Exception inner)
				{
					throw new IDLException(2, "Not a valid float", inner);
				}
			}
			throw new IDLException(2);
		}

		public bool Evaluate()
		{
			if (IDLParams == null)
			{
				throw new InvalidOperationException("IDL Params are not initialized");
			}
			double num = 0.0;
			try
			{
				string s = IDLParams[ColumnName()].ToString();
				num = double.Parse(s);
			}
			catch
			{
				num = 0.0;
			}
			bool result = false;
			switch (Operation)
			{
			case Operation.GreaterThan:
				result = num > ScaledFloat;
				break;
			case Operation.GreatherThanEqual:
				result = num >= ScaledFloat;
				break;
			case Operation.LessThan:
				result = num < ScaledFloat;
				break;
			case Operation.LessThanEqual:
				result = num <= ScaledFloat;
				break;
			case Operation.NotEqual:
				result = num != ScaledFloat;
				break;
			case Operation.Equal:
				result = num == ScaledFloat;
				break;
			}
			return result;
		}

		protected void Validate(string condition)
		{
			if (condition.Trim().Length == 0)
			{
				throw new ArgumentNullException("condition");
			}
			Regex regex = new Regex("[0-9,a-f,A-F]{2}[:]{1}\\w+\\s+(is greater than|is less than|equals|does not equals|is greater than or equal to|is less than or equal to|>|<|=|!=|>=|<=)\\s+(\\d+[.]?\\d*)\\s*(\\s*|AND\\s*|OR\\s*)$");
			if (!regex.IsMatch(condition))
			{
				throw new IDLException(3);
			}
		}

		private string ColumnName()
		{
			string empty = string.Empty;
			string empty2 = string.Empty;
			string[] array = Name.Split(new char[1] { ':' });
			string empty3 = string.Empty;
			empty = array[^1];
			empty2 = Name.Substring(0, Name.Length - empty.Length - 1);
			return '_' + empty2 + '_' + empty;
		}
	}
	public enum Operation
	{
		GreaterThan,
		GreatherThanEqual,
		LessThan,
		LessThanEqual,
		Equal,
		NotEqual
	}
	public enum ConditionJoiner
	{
		AND,
		OR,
		NONE
	}
}
namespace Cummins.IDLLogger
{
	internal abstract class IDLValidator
	{
		protected ModuleValidatorResultType validatorResultType;

		private ICalibrationOnline calibration;

		internal abstract ModuleValidatorResultType CanRunIDL { get; }

		protected ICalibrationOnline DataSource
		{
			get
			{
				return calibration;
			}
			set
			{
				calibration = value;
				validatorResultType = ModuleValidatorResultType.NotValidated;
			}
		}

		internal IDLValidator(ICalibrationOnline calibration)
		{
			DataSource = calibration;
		}

		internal abstract void RestoreModule();

		protected virtual bool Validate()
		{
			ValidateRunLocation();
			ValidateDataCollector();
			return true;
		}

		private void ValidateRunLocation()
		{
			if (DataSource.ECMRunLocation == RunLocationType.RomBoot)
			{
				string message = string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.ModuleIsROMBooted.ToString()), DataSource.SourceAddress.DisplayId);
				throw new IDLException(1, message);
			}
		}

		private void ValidateDataCollector()
		{
			IDataCollectorInfo dataCollectorInfo = new DataCollectorInfo(DataSource.CalibrationDataServer);
			if (dataCollectorInfo.DataCollectorType == DataCollectorType.None)
			{
				string message = string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.DataCollectorNotAvailable.ToString()), DataSource.SourceAddress.DisplayId);
				throw new IDLException(4, message);
			}
		}

		private void ValidateModuleSecurity()
		{
			if (DataSource.Secured == SecurityStatus.Secured && GTISVersion.GTIS45 == DataSource.CalibrationDataServer.GTISLevel)
			{
				string message = string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.ModuleIsSecure.ToString()), DataSource.SourceAddress.DisplayId);
				throw new IDLException(3, message);
			}
		}
	}
	internal class IDL45Validator : IDLValidator
	{
		private bool releaseChangeLock;

		internal override ModuleValidatorResultType CanRunIDL
		{
			get
			{
				if (validatorResultType == ModuleValidatorResultType.NotValidated)
				{
					Validate();
				}
				return validatorResultType;
			}
		}

		internal IDL45Validator(ICalibrationOnline calibration)
			: base(calibration)
		{
		}

		protected override bool Validate()
		{
			try
			{
				base.Validate();
				ValidateChangeLock();
				validatorResultType = ModuleValidatorResultType.CanRunIDL;
			}
			catch
			{
				validatorResultType = ModuleValidatorResultType.CanNotRunIDL;
				RestoreModule();
				throw;
			}
			return validatorResultType == ModuleValidatorResultType.CanNotRunIDL;
		}

		internal override void RestoreModule()
		{
			if (releaseChangeLock)
			{
				base.DataSource.Execute(Cummins.Calibration.CommandType.ReleaseChangeLock);
			}
		}

		private void ValidateChangeLock()
		{
			if (base.DataSource.ChangeLock != ChangeLockStatus.Unlocked && base.DataSource.ChangeLock != ChangeLockStatus.Unknown)
			{
				return;
			}
			string message = string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.RequestForChangeLock.ToString()), base.DataSource.SourceAddress.DisplayId);
			MsgBoxResult msgBoxResult = MsgBox.Show(message, "IDL Logger", MsgBoxButtons.YesNo, MsgBoxIcon.Question);
			if (msgBoxResult == MsgBoxResult.Yes)
			{
				ExecutionResult executionResult = default(ExecutionResult);
				try
				{
					executionResult = base.DataSource.Execute(Cummins.Calibration.CommandType.RequestChangeLock);
					if (CommandReturnType.Failed == executionResult.returnCode)
					{
						throw new Exception(executionResult.responseDescription);
					}
					releaseChangeLock = true;
					return;
				}
				catch (Exception inner)
				{
					message = string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.ECMCommandFailed.ToString()), Cummins.Calibration.CommandType.RequestChangeLock.ToString(), base.DataSource.SourceAddress.DisplayId);
					throw new IDLException(7, message, inner);
				}
			}
			message = string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.ChangeLockNotAcquired.ToString()), base.DataSource.SourceAddress.DisplayId);
			throw new IDLException(0, message);
		}
	}
	public class IDLConfiguration
	{
		private const int MaxValue = 4000;

		private const int MinValue = 1;

		private IAppConfigService appConfigService;

		private TriggerType idlTriggerMode = TriggerType.Clock;

		private int triggerPeriod = 20;

		private bool idlOnKeyOn;

		private IDLStopType idlStopMode = IDLStopType.Stop;

		private bool useCurrentScreen = true;

		private string screenFilePath = "";

		private bool retrieveIDLAtMaxRate = true;

		private int bufferRetrievalRate = 1;

		private bool autoBufferRetrieval;

		public Type IDLTriggerType
		{
			get
			{
				IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
				string text = productInformationService.GTISLevel(appSetting);
				Type typeFromHandle;
				if (text.Equals("GTIS45"))
				{
					typeFromHandle = typeof(IDL45TriggerType);
					idlTriggerMode = TriggerType.Clock;
				}
				else
				{
					typeFromHandle = typeof(IDLPre45TriggerType);
					idlTriggerMode = TriggerType.ForeGroundActivated;
				}
				return typeFromHandle;
			}
		}

		public TriggerType IDLTriggerMode
		{
			get
			{
				try
				{
					idlTriggerMode = (TriggerType)Enum.Parse(IDLTriggerType, appConfigService.GetAppSetting(ApplicationSettings.IDLTriggerSource), ignoreCase: true);
				}
				catch
				{
					appConfigService.SetAppSetting(ApplicationSettings.IDLTriggerSource, idlTriggerMode.ToString());
				}
				return idlTriggerMode;
			}
			set
			{
				idlTriggerMode = value;
			}
		}

		public int TriggerPeriod
		{
			get
			{
				try
				{
					int input = int.Parse(appConfigService.GetAppSetting(ApplicationSettings.IDLTriggerPeriod));
					if (IsValidRange(input, 1, 4000))
					{
						triggerPeriod = input;
					}
				}
				catch
				{
					appConfigService.SetAppSetting(ApplicationSettings.IDLTriggerPeriod, triggerPeriod.ToString());
				}
				return triggerPeriod;
			}
			set
			{
				if (IsValidRange(value, 1, 4000))
				{
					triggerPeriod = value;
					return;
				}
				throw new ArgumentOutOfRangeException("TriggerPeriod", $"{value} is not within [{1},{4000}]");
			}
		}

		public bool IDLOnKeyOn
		{
			get
			{
				try
				{
					idlOnKeyOn = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.IDLOnKeyOn));
				}
				catch
				{
					appConfigService.SetAppSetting(ApplicationSettings.IDLOnKeyOn, idlOnKeyOn.ToString());
				}
				return idlOnKeyOn;
			}
			set
			{
				idlOnKeyOn = value;
			}
		}

		public IDLStopType IDLStopMode
		{
			get
			{
				try
				{
					idlStopMode = (IDLStopType)Enum.Parse(typeof(IDLStopType), appConfigService.GetAppSetting(ApplicationSettings.IDLStopMode), ignoreCase: true);
				}
				catch
				{
					appConfigService.SetAppSetting(ApplicationSettings.IDLStopMode, idlStopMode.ToString());
				}
				return idlStopMode;
			}
			set
			{
				idlStopMode = value;
			}
		}

		public bool UseCurrentScreenParameters
		{
			get
			{
				try
				{
					useCurrentScreen = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.IDLUseCurrentScreen));
				}
				catch
				{
					appConfigService.SetAppSetting(ApplicationSettings.IDLUseCurrentScreen, useCurrentScreen.ToString());
				}
				return useCurrentScreen;
			}
			set
			{
				useCurrentScreen = value;
			}
		}

		public string ScreenFilePath
		{
			get
			{
				try
				{
					screenFilePath = appConfigService.GetAppSetting(ApplicationSettings.IDLParameterScreenFile);
				}
				catch
				{
					appConfigService.SetAppSetting(ApplicationSettings.IDLParameterScreenFile, screenFilePath);
				}
				return screenFilePath;
			}
			set
			{
				screenFilePath = value;
			}
		}

		public bool RetrieveIDLAtMaxRate
		{
			get
			{
				try
				{
					retrieveIDLAtMaxRate = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.IDLRetrievalAtMaxRate));
				}
				catch
				{
					appConfigService.SetAppSetting(ApplicationSettings.IDLRetrievalAtMaxRate, retrieveIDLAtMaxRate.ToString());
				}
				return retrieveIDLAtMaxRate;
			}
			set
			{
				retrieveIDLAtMaxRate = value;
			}
		}

		public int BufferRetrievalRate
		{
			get
			{
				try
				{
					int input = int.Parse(appConfigService.GetAppSetting(ApplicationSettings.IDLRetrievalRate));
					if (IsValidRange(input, 1, 4000))
					{
						bufferRetrievalRate = input;
					}
				}
				catch
				{
					appConfigService.SetAppSetting(ApplicationSettings.IDLRetrievalRate, bufferRetrievalRate.ToString());
				}
				return bufferRetrievalRate;
			}
			set
			{
				if (IsValidRange(value, 1, 4000))
				{
					bufferRetrievalRate = value;
					return;
				}
				throw new ArgumentOutOfRangeException("BufferRetrievalRate", $"{value} is not within [{1},{4000}]");
			}
		}

		public bool AutoBufferRetrieval
		{
			get
			{
				try
				{
					autoBufferRetrieval = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.IDLAutoRetreiveBuffer));
				}
				catch
				{
					appConfigService.SetAppSetting(ApplicationSettings.IDLAutoRetreiveBuffer, autoBufferRetrieval.ToString());
				}
				return autoBufferRetrieval;
			}
			set
			{
				autoBufferRetrieval = value;
			}
		}

		public bool AutoConfigureIDL
		{
			get
			{
				bool result = false;
				try
				{
					result = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.IDLAutoConfigure));
				}
				catch
				{
					appConfigService.SetAppSetting(ApplicationSettings.IDLAutoConfigure, result.ToString());
				}
				return result;
			}
		}

		public bool StopIDLOnMonitorStart
		{
			get
			{
				bool result = false;
				try
				{
					result = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.IDLStopIDLOnMonitorStart));
				}
				catch
				{
					appConfigService.SetAppSetting(ApplicationSettings.IDLStopIDLOnMonitorStart, result.ToString());
				}
				return result;
			}
		}

		public IDLConfiguration()
		{
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		}

		public void SaveConfiguration()
		{
			appConfigService.SetAppSetting(ApplicationSettings.IDLTriggerSource, idlTriggerMode.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.IDLTriggerPeriod, triggerPeriod.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.IDLOnKeyOn, idlOnKeyOn.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.IDLStopMode, idlStopMode.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.IDLUseCurrentScreen, useCurrentScreen.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.IDLParameterScreenFile, screenFilePath);
			appConfigService.SetAppSetting(ApplicationSettings.IDLRetrievalAtMaxRate, retrieveIDLAtMaxRate.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.IDLRetrievalRate, bufferRetrievalRate.ToString());
			appConfigService.SetAppSetting(ApplicationSettings.IDLAutoRetreiveBuffer, autoBufferRetrieval.ToString());
			appConfigService.SaveConfigSetting();
		}

		private bool IsValidRange(int input, int minValue, int maxValue)
		{
			if (minValue <= input)
			{
				return input <= maxValue;
			}
			return false;
		}
	}
	internal enum IDLMessageIDs : short
	{
		ChangeLockNotAcquired,
		ModuleIsROMBooted,
		ModuleIsInDefaultMode,
		ModuleIsSecure,
		DataCollectorNotAvailable,
		NotSupportedGTISLevel,
		IDLAlreadyRunning,
		ECMCommandFailed,
		ECMCommandCanNotBeExecuted,
		RequestForChangeLock,
		RequestForDevelopmentMode,
		BAMMonitoringOn,
		InterfaceParametersNotSupported,
		AddressParameterNotSupported,
		NotSupportedParameters,
		ErrorInAddingParameter,
		ConnectionLost,
		UnableToStartIDL,
		ModuleShouldnotInDefaultMode,
		ErrorInRetrievingData,
		ErrorInRetrievingDataReason,
		ErrorInSavingDC2Config,
		SaveDC2ConfigNotSupported,
		ErrorCreatingSubscriptionForResumeIDL,
		ErrorInResumingIDL,
		IDLLoggingList,
		IDLConfiguration,
		ErrorInConfiguringNonIdleIDL,
		UnableToStartIDLOnKeyOn,
		ErrorInRetrievingDataCollectorInfo,
		IDLRetrievalRateDetailMessage,
		UnableToStartIDLDetails,
		IDLSoueceAddressMissingLoggingList,
		NotInDevelopmentMode,
		AbortedIDLOnRunFromDefault
	}
	public class IDLException : BaseException
	{
		public IDLException(short errorNo)
			: base(Facility.IDLLogger, errorNo)
		{
		}

		public IDLException(short errorNo, string message)
			: base(Facility.IDLLogger, errorNo, message)
		{
		}

		public IDLException(short errorNo, string message, Exception inner)
			: base(Facility.IDLLogger, errorNo, message, inner)
		{
		}

		public IDLException(short errorNo, string message, string context)
			: base(Facility.IDLLogger, errorNo, message, context)
		{
		}

		public IDLException(short errorNo, string message, string context, Exception inner)
			: base(Facility.IDLLogger, errorNo, message, context, inner)
		{
		}
	}
	public enum IDL45TriggerType
	{
		EngineSpeed = 1,
		RoadSpeed,
		TurboSpeed,
		Clock,
		Frame
	}
	public enum IDLPre45TriggerType
	{
		RoadSpeed = 2,
		TurboSpeed = 3,
		ForeGroundActivated = 6,
		CamCrankSpeed = 7,
		Timer = 8
	}
	public class IDLLogger : Component, IPropertyPageProvider
	{
		internal const string StringResourceName = "Cummins.IDLLogger.Strings";

		public const string IDLCaption = "IDL Logger";

		private static IDLLogger instance = new IDLLogger();

		internal static ResourceManager resources = new ResourceManager("Cummins.IDLLogger.Strings", Assembly.GetExecutingAssembly());

		private BlankIDLLoggingPreferencePage blankidlLoggingPreferencePage;

		private IDLLoggingController controller;

		private IDLLoggingModel model;

		public static IDLLogger IDLLoggerInstance => instance;

		internal static ResourceManager Resources => resources;

		public IDLState IDLState
		{
			get
			{
				return Controller.IDLState;
			}
			set
			{
				Controller.IDLState = value;
			}
		}

		public IModuleNetwork Network
		{
			set
			{
				Model.Network = value;
			}
		}

		public ArrayList Pages
		{
			get
			{
				ArrayList arrayList = new ArrayList();
				blankidlLoggingPreferencePage = new BlankIDLLoggingPreferencePage("", "IDL Logging");
				arrayList.Add(blankidlLoggingPreferencePage);
				return arrayList;
			}
		}

		private IDLLoggingController Controller
		{
			get
			{
				if (controller == null)
				{
					controller = new IDLLoggingController(Model);
				}
				return controller;
			}
		}

		private IDLLoggingModel Model
		{
			get
			{
				if (model == null)
				{
					model = new IDLLoggingModel();
				}
				return model;
			}
		}

		public event IDLStateChangedEventHandler IDLStateChangedEvent
		{
			add
			{
				Model.IDLStateChangedEvent += value;
			}
			remove
			{
				Model.IDLStateChangedEvent -= value;
			}
		}

		public event LogFileSavingEventHandler LogFileSavingEvent
		{
			add
			{
				Model.IDLLogger.LogFileSavingEvent += value;
			}
			remove
			{
				Model.IDLLogger.LogFileSavingEvent -= value;
			}
		}

		public event RunLocationChangeEventHandler RunLocationChangeEvent
		{
			add
			{
				Controller.RunLocationChangeEvent += value;
			}
			remove
			{
				Controller.RunLocationChangeEvent -= value;
			}
		}

		public event StopBroadCastEventHandler StopBroadCastEvent
		{
			add
			{
				Controller.StopBroadCastEvent += value;
			}
			remove
			{
				Controller.StopBroadCastEvent -= value;
			}
		}

		private IDLLogger()
		{
		}

		public void ConfigureIDL(ArrayList parametersList, bool isOnline)
		{
			Controller.ConfigureIDL(parametersList, isOnline);
		}

		public void StartIDL(ArrayList parametersList)
		{
			Controller.StartIDL(parametersList);
		}

		public void RegisterDataProvider(IDataProvider dataProvider)
		{
			Controller.RegisterDataProvider(dataProvider);
		}

		public void ResumeIDL()
		{
			Controller.ResumeIDL();
		}

		public void StopIDL()
		{
			Controller.StopIDL();
		}

		public void CancelIDL()
		{
			Controller.CancelIDL();
		}

		public void RetrieveIDLbuffer()
		{
			Controller.RetrieveIDLbuffer();
		}

		public void OnGlobalLoggingOptionsChanged(object sender, EventArgs e)
		{
			ILoggerConfiguration srcOptions = (ILoggerConfiguration)sender;
			LogManager.SynchronizeOptions(srcOptions, Model.IDLLogger.Configuration);
		}

		public static string GetUnit(TriggerType triggerType)
		{
			if (triggerType == TriggerType.Clock || triggerType == TriggerType.Frame || triggerType == TriggerType.Timer || triggerType == TriggerType.ForeGroundActivated)
			{
				return "ms";
			}
			return "interrupts per trigger";
		}

		public bool ConfigureEventDriven(ArrayList paramList)
		{
			//IL_0064: Unknown result type (might be due to invalid IL or missing references)
			//IL_006a: Invalid comparison between Unknown and I4
			Global.MonitoredParameters.Clear();
			Global.logParamList = paramList;
			for (int i = 0; i < paramList.Count; i++)
			{
				LogParameters logParameters = (LogParameters)paramList[i];
				Global.MonitoredParameters.Add(logParameters.sourceAddess.Value + ":" + logParameters.parameterName);
			}
			TriggerConfigurationDlg triggerConfigurationDlg = new TriggerConfigurationDlg(Global.triggerOptions);
			bool result = false;
			try
			{
				if ((int)((Form)triggerConfigurationDlg).ShowDialog() == 1)
				{
					triggerConfigurationDlg.DoDataExchange();
					TriggerLoggingOptions triggerOptions = Global.triggerOptions;
					if (triggerOptions.StartTriggerSpecified || triggerOptions.StopTriggerSpecified)
					{
						result = true;
						Global.eventDrivenStarted = false;
						Global.eventDrivenStopped = false;
						Global.repeatCount = 0;
					}
				}
			}
			catch
			{
			}
			return result;
		}
	}
	[StructLayout(LayoutKind.Sequential, Size = 1)]
	public struct IDLPeriodUnit
	{
		public const string Time = "ms";

		public const string Event = "interrupts per trigger";
	}
	public enum Mode
	{
		Manual,
		EventDriven
	}
	public enum IDLState
	{
		Idle,
		Starting,
		Started,
		Stopping,
		Cancelling,
		WaitingForRetrieving,
		RetrievingBuffer,
		RetrievedBuffer,
		Logging,
		Configuring,
		Resuming,
		CleaningUp,
		Failed
	}
	public delegate void IDLStateChangedEventHandler(object sender, IDLStateChangedEventArgs e);
	public delegate void PauseSubscriptionDelegate(IECMSubscription subscription);
	public struct LogParameters
	{
		public string parameterName;

		public IAddressValue sourceAddess;
	}
	public class IDLStateChangedEventArgs : EventArgs
	{
		private IDLState state;

		public IDLState IDLState => state;

		public IDLStateChangedEventArgs(IDLState state)
		{
			this.state = state;
		}
	}
	internal class IDLLoggingController
	{
		internal const char UnderScore = '_';

		internal const char Dot = '.';

		internal const int DefaultEvaluteTimerRate = 1000;

		internal const int DefaultRepeatTimerRate = 120000;

		private const int FastestRateMultiplier = 1;

		private const int DefaultRateMultiplier = 5;

		private ArrayList idlDataProviderList = new ArrayList();

		private Hashtable paramMonitor = new Hashtable();

		private ArrayList registeredIdHolder = new ArrayList();

		private ArrayList _allRegisteredIds = new ArrayList();

		private bool evaluating;

		private System.Threading.Timer evaluateTimer;

		private System.Timers.Timer repeatTimer;

		private IDLLoggingModel idlLogModel;

		private SortedList subscriptionsList;

		private ManualResetEvent retrieveBufferSignal = new ManualResetEvent(initialState: false);

		private ArrayList logParametersList = new ArrayList();

		private ArrayList notSupportedParameters = new ArrayList();

		private bool canLogData;

		private int notificationExpected;

		private Thread idlThread;

		private SortedList moduleValidatorList;

		private SortedList offlineDC2subscriptionList = new SortedList();

		private IProgress IDLProgress;

		internal IDLState IDLState
		{
			get
			{
				return Model.IDLState;
			}
			set
			{
				Model.IDLState = value;
			}
		}

		private IDLLoggingModel Model
		{
			get
			{
				return idlLogModel;
			}
			set
			{
				if (value == null)
				{
					throw new ArgumentNullException("IDL Model");
				}
				idlLogModel = value;
			}
		}

		private SortedList SubscriptionsList
		{
			get
			{
				if (subscriptionsList == null)
				{
					subscriptionsList = new SortedList();
				}
				return subscriptionsList;
			}
		}

		private SortedList ModuleValidatorList
		{
			get
			{
				if (moduleValidatorList == null)
				{
					moduleValidatorList = new SortedList();
				}
				return moduleValidatorList;
			}
		}

		public event RunLocationChangeEventHandler RunLocationChangeEvent;

		public event StopBroadCastEventHandler StopBroadCastEvent;

		internal IDLLoggingController(IDLLoggingModel model)
		{
			if (model == null)
			{
				throw new ArgumentNullException("IDL Logger Model");
			}
			Model = model;
			evaluateTimer = new System.Threading.Timer(OnEvaluate, null, 1000, 1000);
		}

		internal void ConfigureIDL(ArrayList parameterList, bool isOnline)
		{
			if (IDLState != IDLState.Idle)
			{
				throw new IDLException(27, IDLLogger.Resources.GetString(IDLMessageIDs.ErrorInConfiguringNonIdleIDL.ToString()));
			}
			IDLState = IDLState.Configuring;
			if (!isOnline)
			{
				string text = "";
				if (parameterList == null)
				{
					throw new ArgumentNullException("IDL Logging Parameter List");
				}
				foreach (LogParameters parameter in parameterList)
				{
					object obj = text;
					text = string.Concat(obj, parameter.sourceAddess, ":", parameter.parameterName, "\r\n");
				}
				ReportIDLParameterList(text);
				TriggerType iDLTriggerMode = Model.IDLTriggerMode;
				int iDLRate = Model.IDLRate;
				bool iDLOnKeyOn = Model.IDLOnKeyOn;
				IDLStopType iDLStopMode = Model.IDLStopMode;
				ReportIDLConfiguration(iDLTriggerMode, iDLRate, iDLOnKeyOn, iDLStopMode);
				IDLState = IDLState.Idle;
			}
			else
			{
				logParametersList = parameterList;
				idlThread = new Thread(ConfigureIDL);
				idlThread.Priority = ThreadPriority.Highest;
				idlThread.SetApartmentState(ApartmentState.MTA);
				idlThread.Name = "IDL Configure Thread";
				idlThread.Start();
			}
		}

		internal void StartIDL(ArrayList parametersList)
		{
			if (IDLState != IDLState.Idle)
			{
				throw new IDLException(6, IDLLogger.Resources.GetString(IDLMessageIDs.IDLAlreadyRunning.ToString()));
			}
			if (Model.IDLOnKeyOn)
			{
				throw new IDLException(28, IDLLogger.Resources.GetString(IDLMessageIDs.UnableToStartIDLOnKeyOn.ToString()));
			}
			if (parametersList == null)
			{
				throw new ArgumentNullException("IDL Logging Parameter List");
			}
			if (Model.Network != null && !Model.Network.Offline)
			{
				Model.Network.SystemPauseAllMonitoring = true;
				IDLState = IDLState.Starting;
				IDLProgress = new CaltermProgress();
				IDLProgress.SetProgress("IDL Logger", "Starting IDL ...");
				IDLProgress.Start();
				logParametersList = parametersList;
				InitializeParameters();
				SetIDLSettings();
				InitializeIDLSession();
				idlThread = new Thread(StartIDLLogging);
				idlThread.Priority = ThreadPriority.Highest;
				idlThread.SetApartmentState(ApartmentState.MTA);
				idlThread.Name = "IDL Start Thread";
				idlThread.Start();
				IDLProgress.Finish();
			}
		}

		internal void ResumeIDL()
		{
			IDLState = IDLState.Resuming;
			if (Model.Network != null)
			{
				InitializeIDLSession();
				IDLProgress = new CaltermProgress();
				IDLProgress.SetProgress("IDL Logger", "Resuming IDL ...");
				IDLProgress.Start();
				idlThread = new Thread(ResumeIDLLogging);
				idlThread.Priority = ThreadPriority.Highest;
				idlThread.SetApartmentState(ApartmentState.MTA);
				idlThread.Name = "IDL Resume Thread";
				idlThread.Start();
			}
		}

		internal void StopIDL()
		{
			IDLState = IDLState.Stopping;
			idlThread = new Thread(StopIDLLogging);
			idlThread.Priority = ThreadPriority.Highest;
			idlThread.ApartmentState = ApartmentState.MTA;
			idlThread.Name = "IDL Stop Thread";
			idlThread.Start();
		}

		internal void CancelIDL()
		{
			IDLState = IDLState.Cancelling;
			retrieveBufferSignal.Set();
			for (int i = 0; i < SubscriptionsList.Count; i++)
			{
				IECMSubscription iECMSubscription = (IECMSubscription)SubscriptionsList.GetByIndex(i);
				if (iECMSubscription != null)
				{
					UnRegisterSubscriptionEvents(iECMSubscription);
					iECMSubscription.Stop();
				}
			}
			Model.IDLLogger.Abort();
			IDLCleanUp();
		}

		internal void RetrieveIDLbuffer()
		{
			retrieveBufferSignal.Set();
		}

		protected void OnEvaluate(object source)
		{
			try
			{
				Evaluate();
			}
			catch (Exception)
			{
			}
		}

		public void RegisterDataProvider(IDataProvider dataProvider)
		{
			if (dataProvider == null)
			{
				throw new ArgumentNullException("dataProvider");
			}
			lock (registeredIdHolder)
			{
				if (!registeredIdHolder.Contains(dataProvider.ID) && !_allRegisteredIds.Contains(dataProvider.ID))
				{
					dataProvider.Notification += OnDataRefreshed;
					_allRegisteredIds.Add(dataProvider.ID);
					idlDataProviderList.Add(dataProvider);
				}
			}
		}

		public void UnRegisterDataProvider(IDataProvider dataProvider)
		{
			if (dataProvider == null)
			{
				throw new ArgumentNullException("dataProvider");
			}
			lock (registeredIdHolder)
			{
				if (registeredIdHolder.Contains(dataProvider.ID))
				{
					if (_allRegisteredIds.Contains(dataProvider.ID))
					{
						dataProvider.Notification -= OnDataRefreshed;
						_allRegisteredIds.Remove(dataProvider.ID);
					}
					registeredIdHolder.Remove(dataProvider.ID);
				}
			}
		}

		public void OnDataRefreshed(object sender, DataRefreshEventArgs e)
		{
			RecordData(e);
		}

		public void RecordData(DataRefreshEventArgs e)
		{
			bool flag = false;
			if (e.DataSourceType == DataSourceTypeEnum.ASAM)
			{
				if ((e as ASAMDataRefreshEventArgs).ASAMData != null)
				{
					flag = true;
				}
			}
			else if (e.DataSourceType == DataSourceTypeEnum.ECM)
			{
				if ((e as ECMDataRefreshEventArgs).ECMData != null)
				{
					flag = true;
				}
			}
			else if (e.DataSourceType == DataSourceTypeEnum.J1939_71 && (e as J1939_71DataRefreshEventArgs).J1939_71Data != null)
			{
				flag = true;
			}
			if (flag)
			{
				if (e.DataSourceType == DataSourceTypeEnum.ECM)
				{
					(e as ECMDataRefreshEventArgs).ECMData.ToString();
					RecordNotification((e as ECMDataRefreshEventArgs).ECMData, (e as ECMDataRefreshEventArgs).SourceAddress);
				}
				else if (e.DataSourceType == DataSourceTypeEnum.ASAM)
				{
					RecordNotification((e as ASAMDataRefreshEventArgs).ASAMData, (e as ASAMDataRefreshEventArgs).SourceAddress);
				}
				else if (e.DataSourceType == DataSourceTypeEnum.J1939_71)
				{
					CompositeJ1939_71Data compositeJ1939_71Data = new CompositeJ1939_71Data();
					PCLSubscriptionHelper.MergeJ1939_71Notifications(compositeJ1939_71Data, e as J1939_71DataRefreshEventArgs);
					RecordNotification(compositeJ1939_71Data);
				}
			}
		}

		protected bool RecordNotification(ArrayList parameterValues, IAddressValue sourceAddress)
		{
			string empty = string.Empty;
			CICPPMonitor cICPPMonitor = null;
			string empty2 = string.Empty;
			int num = -1;
			bool result = true;
			foreach (ICIDataElementNotification parameterValue in parameterValues)
			{
				try
				{
					if (parameterValue.Status == tagCIDMStatusEnum.DM_STATUS_OK)
					{
						cICPPMonitor = (CICPPMonitor)parameterValue.DataElementMonitor;
						switch (cICPPMonitor.mode)
						{
						case tagCIDMAccessModeEnum.DM_MODE_PARAMETER_ID:
						case tagCIDMAccessModeEnum.DM_MODE_NAME:
							empty2 = cICPPMonitor.location.ToString();
							num = empty2.LastIndexOf('.');
							if (num != -1)
							{
								empty2 = empty2.Substring(num + 1);
							}
							empty = IDLParamName(empty2, sourceAddress);
							UpdateMonitor(empty, parameterValue.ScaledValue);
							break;
						case tagCIDMAccessModeEnum.DM_MODE_ADDRESS:
							empty = IDLParamName((int)uint.Parse(cICPPMonitor.location.ToString()), cICPPMonitor.offset, cICPPMonitor.Length, sourceAddress);
							UpdateMonitor(empty, parameterValue.ScaledValue);
							break;
						}
					}
					else
					{
						result = false;
					}
				}
				catch (Exception)
				{
					result = false;
				}
			}
			return result;
		}

		protected bool RecordNotification(ICINotification asamNotification, IAddressValue sourceAddress)
		{
			bool result = true;
			ICIMonitorElement iCIMonitorElement = null;
			string empty = string.Empty;
			for (int i = 0; i < asamNotification.Count; i++)
			{
				iCIMonitorElement = asamNotification.GetElement(i);
				try
				{
					empty = string.Empty;
					empty = IDLParamName(iCIMonitorElement.Name, sourceAddress);
					if (iCIMonitorElement.Value == null)
					{
						result = false;
					}
					else
					{
						UpdateMonitor(empty, iCIMonitorElement.Value);
					}
				}
				catch (Exception)
				{
					result = false;
				}
			}
			return result;
		}

		protected bool RecordNotification(CompositeJ1939_71Data data)
		{
			bool result = true;
			string empty = string.Empty;
			J1939_71PGNMap j1939_71PGNMap = null;
			foreach (ushort key in data.Keys)
			{
				j1939_71PGNMap = data[key];
				foreach (PGN value in j1939_71PGNMap.Values)
				{
					if (value.SPNs == null)
					{
						continue;
					}
					foreach (SPN sPN in value.SPNs)
					{
						try
						{
							empty = string.Empty;
							empty = IDLParamName(SPN.FigureFullName(value.Name, sPN.Name), AddressFactory.ProductAddressValue(key));
							if (sPN.Value == null)
							{
								result = false;
							}
							else
							{
								UpdateMonitor(empty, sPN.Value);
							}
						}
						catch (Exception)
						{
							result = false;
						}
					}
				}
			}
			return result;
		}

		internal static string IDLParamName(string parameterName, IAddressValue sourceAddress)
		{
			return '_' + sourceAddress.Value + '_' + parameterName;
		}

		internal static string IDLParamName(int location, int offset, int length, IAddressValue sourceAddress)
		{
			return '_' + sourceAddress.Value + '_' + location.ToString("X8") + '_' + offset.ToString("X8") + '_' + length.ToString("X2");
		}

		protected void UpdateMonitor(string name, string val)
		{
			if (!paramMonitor.Contains(name))
			{
				paramMonitor.Add(name, val);
			}
			else
			{
				paramMonitor[name] = val;
			}
		}

		private void ConfigureIDL()
		{
			InitializeParameters();
			InitializeIDLSession();
			SetIDLSettings();
			IDLCleanUp();
		}

		private void Evaluate()
		{
			if (Global.mode != Mode.EventDriven || evaluating)
			{
				return;
			}
			lock (this)
			{
				try
				{
					evaluating = true;
					TriggerLoggingOptions triggerOptions = Global.triggerOptions;
					if (IDLState == IDLState.Idle && triggerOptions.StartTriggerSpecified)
					{
						lock (paramMonitor)
						{
							Trigger trigger = new Trigger(triggerOptions.StartTrigger, paramMonitor);
							bool flag = trigger.Evaluate();
							ArrayList logParamList = Global.logParamList;
							if (flag && logParamList != null && !Global.eventDrivenStarted && !idlThread.IsAlive)
							{
								Global.eventDrivenStarted = true;
								StartIDL(logParamList);
							}
						}
					}
					else if (IDLState == IDLState.Started && triggerOptions.StopTriggerSpecified)
					{
						lock (paramMonitor)
						{
							Trigger trigger2 = new Trigger(triggerOptions.StopTrigger, paramMonitor);
							if (triggerOptions.StopTrigger.Length > 0 && trigger2.Evaluate() && Global.eventDrivenStarted && !Global.eventDrivenStopped && !idlThread.IsAlive)
							{
								Global.eventDrivenStopped = true;
								StopIDL();
							}
						}
					}
					evaluating = false;
					if (Global.eventDrivenStarted && Global.eventDrivenStopped)
					{
						Global.repeatCount++;
						if (Global.repeatCount < triggerOptions.RepeatCount)
						{
							Global.eventDrivenStarted = false;
							Global.eventDrivenStopped = false;
						}
					}
				}
				catch
				{
				}
				finally
				{
					evaluating = false;
				}
			}
		}

		private void StartIDLLogging()
		{
			StartAllSubsciptions(isResume: false);
			lock (SubscriptionsList)
			{
				if (notificationExpected > 0)
				{
					IDLState = IDLState.Started;
					IDLProgress.Finish();
					ReportNotSupportedParameters(notSupportedParameters);
				}
				else
				{
					StopIDLLogging();
					IDLProgress.Finish();
				}
			}
		}

		private void ResumeIDLLogging()
		{
			offlineDC2subscriptionList.Clear();
			Model.IDLLogger.RemoveAll();
			ClearAllSubScription();
			foreach (ICalibrationOnline value in Model.Network.Modules.Values)
			{
				if (value == null || value is IPublicDataSource)
				{
					continue;
				}
				IAddressValue addressValue = null;
				IECMSubscription iECMSubscription = null;
				try
				{
					addressValue = value.SourceAddress;
					iECMSubscription = SubscriptionsList[addressValue] as IECMSubscription;
					if (iECMSubscription == null)
					{
						IDataCollectorInfo dataCollectorInfo = new DataCollectorInfo(value.CalibrationDataServer);
						if (!value.Connected)
						{
							iECMSubscription = GetSubscription(value.SourceAddress, needToBeCleared: false);
							offlineDC2subscriptionList.Add(iECMSubscription, null);
						}
						else if (dataCollectorInfo.DataCollectorStatus == DataCollectorStatus.On || dataCollectorInfo.IDLStopMode == IDLStopType.KeyOn)
						{
							iECMSubscription = GetSubscription(value.SourceAddress, needToBeCleared: false);
							AddIDLLoggerParameter(iECMSubscription);
						}
					}
				}
				catch (DataRetrievalException ex)
				{
					EventLogger.Warn("IDL Logger", string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.ErrorInRetrievingDataCollectorInfo.ToString()), addressValue), ex);
				}
				catch (Exception e)
				{
					EventLogger.Error("IDL Logger", string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.ErrorCreatingSubscriptionForResumeIDL.ToString()), addressValue), e);
				}
			}
			StartAllSubsciptions(isResume: true);
			lock (SubscriptionsList)
			{
				if (notificationExpected > 0)
				{
					IDLState = IDLState.Started;
					IDLProgress.Finish();
					ReportNotSupportedParameters(notSupportedParameters);
				}
				else
				{
					StopIDLLogging();
					IDLProgress.Finish();
				}
			}
		}

		private void InitializeParameters()
		{
			IECMSubscription iECMSubscription = null;
			IParameterModel parameterModel = null;
			string text = "";
			notSupportedParameters.Clear();
			Model.IDLLogger.RemoveAll();
			ClearAllSubScription();
			string text2 = string.Empty;
			foreach (LogParameters logParameters in logParametersList)
			{
				try
				{
					parameterModel = null;
					if (Model.Network.Modules.Contains(logParameters.sourceAddess))
					{
						parameterModel = Model.Network.GetCalibration(logParameters.sourceAddess).FuzzyGet(logParameters.parameterName);
						iECMSubscription = GetSubscription(logParameters.sourceAddess, needToBeCleared: true);
					}
					else
					{
						string text3 = text2;
						text2 = text3 + logParameters.parameterName + " at source address " + logParameters.sourceAddess.DisplayId + "\r\n";
					}
				}
				catch (Exception ex)
				{
					string message = $"Can not add parameter {logParameters.parameterName} to IDL on device address {logParameters.sourceAddess.DisplayId}. Got an exception - {ex.Message}  while retrieving the parameter specification";
					EventLogger.Error("IDL Logger", message, ex);
					parameterModel = null;
				}
				if (parameterModel != null && iECMSubscription != null)
				{
					if (CanAddParameter(parameterModel, iECMSubscription))
					{
						AddParameter(parameterModel, iECMSubscription, logParameters.parameterName);
						object obj = text;
						text = string.Concat(obj, iECMSubscription.SourceAddress, ":", parameterModel.Name, "\r\n");
					}
					else
					{
						notSupportedParameters.Add(parameterModel);
					}
				}
			}
			ReportIDLParameterList(text);
			ReportSouceAddressNotAvailableList(text2);
		}

		private bool CanAddParameter(IParameterModel paramModel, IECMSubscription subscription)
		{
			IDataCollectorInfo dataCollectorInfo = new DataCollectorInfo(subscription.DataSource.CalibrationDataServer);
			if (!paramModel.IsInterfaceParameter && paramModel.DataType != ParameterType.Array1D && paramModel.DataType != ParameterType.Array2D && paramModel.DataType != ParameterType.ArrayXAxis && paramModel.DataType != ParameterType.ArrayXY && paramModel.DataType != ParameterType.ArrayXYZ)
			{
				if (paramModel.DataType != ParameterType.Value && paramModel.DataType != ParameterType.Enumeration && dataCollectorInfo.DataCollectorType != DataCollectorType.DataCollector2)
				{
					return subscription.DataSource.CalibrationDataServer.GTISLevel != GTISVersion.GTIS45;
				}
				return true;
			}
			return false;
		}

		private void AddParameter(IParameterModel paramModel, IECMSubscription subscription, string displayName)
		{
			try
			{
				if (paramModel.DataType == ParameterType.Value || paramModel.DataType == ParameterType.Enumeration)
				{
					subscription.Add(paramModel.FullName);
					if (IDLState != IDLState.Configuring || Model.IDLOnKeyOn)
					{
						Model.IDLLogger.Add(paramModel.Name, paramModel.EngineeringUnits, NetworkType.J1939, subscription.SourceAddress, paramModel is IPublicDataModel);
					}
					return;
				}
				uint length = ((paramModel is IDataBlockModel) ? 1u : paramModel.Length);
				subscription?.Add(paramModel.Address, paramModel.Offset, length, paramModel);
				if (IDLState != IDLState.Configuring || Model.IDLOnKeyOn)
				{
					uint num = paramModel.Address;
					int num2 = paramModel.Offset;
					if (Model.IDLOnKeyOn)
					{
						num += (uint)num2;
						num2 = 0;
					}
					Model.IDLLogger.Add(num, num2, length, paramModel.EngineeringUnits, subscription.SourceAddress, displayName);
				}
			}
			catch (Exception e)
			{
				string message = string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.ErrorInAddingParameter.ToString()), paramModel.Name);
				EventLogger.Error("IDL Logger", message, e);
			}
		}

		private void InitializeIDLSession()
		{
			retrieveBufferSignal.Reset();
			notificationExpected = 0;
			canLogData = false;
		}

		private void StopIDLLogging()
		{
			bool flag = false;
			lock (SubscriptionsList)
			{
				if (notificationExpected == 0)
				{
					StopDataLogger();
					IDLCleanUp();
					flag = true;
				}
			}
			if (flag || SubscriptionsList.Count <= 0)
			{
				return;
			}
			ConfigureCustomIDLHeader(SubscriptionsList.GetByIndex(0) as IECMSubscription);
			Model.IDLLogger.Start();
			retrieveBufferSignal.Reset();
			foreach (IECMSubscription value in SubscriptionsList.Values)
			{
				PauseSubscriptionDelegate pauseSubscriptionDelegate = PauseSubscription;
				pauseSubscriptionDelegate.BeginInvoke(value, null, null);
			}
		}

		private void PauseSubscription(IECMSubscription subscription)
		{
			try
			{
				if (subscription != null && subscription.IsActive)
				{
					subscription.Pause();
				}
			}
			catch (Exception ex)
			{
				string message = string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.ErrorInRetrievingData.ToString()), subscription.SourceAddress);
				string detailedMessage = IDLLogger.Resources.GetString(IDLMessageIDs.ErrorInRetrievingDataReason.ToString()) + Environment.NewLine + Environment.NewLine + ex.Message;
				EventLogger.Error("IDL Logger", message, detailedMessage);
				lock (SubscriptionsList)
				{
					notificationExpected--;
					if (notificationExpected == 0)
					{
						StopDataLogger();
						IDLCleanUp();
					}
				}
			}
		}

		private void AddIDLLoggerParameter(IECMSubscription subscription)
		{
			ArrayList subscriptionParameterList = subscription.SubscriptionParameterList;
			IAddressValue sourceAddress = subscription.SourceAddress;
			foreach (MonitoredElement item in subscriptionParameterList)
			{
				if (item.mode == AccessMode.Address)
				{
					Model.IDLLogger.Add(uint.Parse(item.location.ToString()), item.offset, (uint)item.length, "NA", sourceAddress, uint.Parse(item.location.ToString()).ToString("X8"));
				}
				else if (item.mode == AccessMode.Name || item.mode == AccessMode.ParameterId)
				{
					string text = item.location.ToString();
					text = text.Substring(text.IndexOf(".") + 1);
					IParameterModel parameterModel = subscription.DataSource.FuzzyGet(text);
					Model.IDLLogger.Add(parameterModel.Name, parameterModel.EngineeringUnits, NetworkType.J1939, sourceAddress, parameterModel is IPublicDataModel);
				}
			}
		}

		private void IDLCleanUp()
		{
			IDLState = IDLState.CleaningUp;
			foreach (IECMSubscription value in SubscriptionsList.Values)
			{
				try
				{
					value.RemoveAll();
				}
				catch (Exception)
				{
				}
			}
			RestoreModuleState();
			ClearModuleValidators();
			IDLState = IDLState.Idle;
		}

		private void StopDataLogger()
		{
			if (!canLogData)
			{
				Model.IDLLogger.Abort();
			}
			else
			{
				Model.IDLLogger.Stop();
			}
		}

		private bool ValidateDataSource(IAddressValue sourceAddress)
		{
			IDLValidator iDLValidator = null;
			ModuleValidatorResultType moduleValidatorResultType = ModuleValidatorResultType.NotValidated;
			try
			{
				if (!ModuleValidatorList.Contains(sourceAddress))
				{
					ICalibrationOnline calibration = Model.Network.GetCalibration(sourceAddress);
					iDLValidator = GetValidator(calibration);
					ModuleValidatorList.Add(sourceAddress, iDLValidator);
				}
				else
				{
					iDLValidator = (IDLValidator)ModuleValidatorList[sourceAddress];
				}
				moduleValidatorResultType = iDLValidator.CanRunIDL;
			}
			catch (IDLException ex)
			{
				EventLogger.Error("IDL Logger", ex.Message);
			}
			return moduleValidatorResultType == ModuleValidatorResultType.CanRunIDL;
		}

		private IDLValidator GetValidator(ICalibrationOnline calibration)
		{
			GTISVersion gTISLevel = calibration.CalibrationDataServer.GTISLevel;
			if (gTISLevel == GTISVersion.GTIS45)
			{
				return new IDL45Validator(calibration);
			}
			return new IDLPre45Validator(calibration);
		}

		private void SetIDLSettings()
		{
			SortedList sortedList = new SortedList();
			TriggerType iDLTriggerMode = Model.IDLTriggerMode;
			IDLStopType iDLStopType = Model.IDLStopMode;
			bool iDLOnKeyOn = Model.IDLOnKeyOn;
			if (iDLOnKeyOn)
			{
				iDLStopType = IDLStopType.KeyOn;
			}
			int iDLRate = Model.IDLRate;
			int num = Model.IDLRate;
			if (iDLTriggerMode == TriggerType.ForeGroundActivated || iDLTriggerMode == TriggerType.Timer || iDLTriggerMode == TriggerType.Clock || iDLTriggerMode == TriggerType.Frame)
			{
				num /= SubscriptionRateHelper.GetMaxBaseRate(SubscriptionsList, Model.IDLTriggerMode);
			}
			num = ((num < 1) ? 1 : num);
			ReportIDLConfiguration(iDLTriggerMode, iDLRate, iDLOnKeyOn, iDLStopType);
			foreach (IECMSubscription value in SubscriptionsList.Values)
			{
				if (value == null)
				{
					continue;
				}
				value.TriggerMode = iDLTriggerMode;
				value.IDLStopMode = iDLStopType;
				value.ValidateParameter = false;
				value.RateMultiplier = num;
				IDataCollectorInfo dataCollectorInfo = new DataCollectorInfo(value.DataSource.CalibrationDataServer);
				if (dataCollectorInfo.DataCollectorType == DataCollectorType.DataCollector2)
				{
					if (!sortedList.Contains(value.SourceAddress))
					{
						sortedList.Add(value.SourceAddress, ValidateDataSource(value.SourceAddress));
					}
					if ((bool)sortedList[value.SourceAddress])
					{
						if (!value.SaveDC2Configuration())
						{
							EventLogger.Error("IDL Logger", string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.ErrorInSavingDC2Config.ToString()), value.SourceAddress));
						}
						else if (value.IDLStopMode == IDLStopType.KeyOn)
						{
							notificationExpected++;
						}
					}
				}
				else
				{
					EventLogger.Info("IDL Logger", string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.SaveDC2ConfigNotSupported.ToString()), value.SourceAddress));
				}
			}
		}

		private void StartAllSubsciptions(bool isResume)
		{
			SortedList sortedList = new SortedList();
			try
			{
				foreach (IECMSubscription value in SubscriptionsList.Values)
				{
					try
					{
						if (!value.DataSource.Connected)
						{
							continue;
						}
						if (!sortedList.Contains(value.SourceAddress))
						{
							sortedList.Add(value.SourceAddress, ValidateDataSource(value.SourceAddress));
						}
						if (!(bool)sortedList[value.SourceAddress])
						{
							continue;
						}
						IDataCollectorInfo dataCollectorInfo = new DataCollectorInfo(value.DataSource.CalibrationDataServer);
						if (!isResume || dataCollectorInfo.DataCollectorStatus == DataCollectorStatus.On || dataCollectorInfo.IDLStopMode == IDLStopType.KeyOn)
						{
							if (!isResume)
							{
								value.Start();
							}
							else
							{
								value.Resume();
							}
							lock (SubscriptionsList)
							{
								notificationExpected++;
							}
						}
					}
					catch (Exception)
					{
						string message = string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.UnableToStartIDL.ToString()), value.SourceAddress);
						string detailedMessage = IDLLogger.Resources.GetString(IDLMessageIDs.UnableToStartIDLDetails.ToString());
						EventLogger.Error("IDL Logger", message, detailedMessage);
						if (ModuleValidatorList.Contains(value.SourceAddress))
						{
							((IDLValidator)ModuleValidatorList[value.SourceAddress]).RestoreModule();
							ModuleValidatorList.Remove(value.SourceAddress);
						}
					}
				}
			}
			finally
			{
				Model.Network.SystemPauseAllMonitoring = false;
			}
		}

		private IECMSubscription GetSubscription(IAddressValue sourceAddress, bool needToBeCleared)
		{
			IECMSubscription iECMSubscription;
			lock (SubscriptionsList)
			{
				if (SubscriptionsList.Contains(sourceAddress))
				{
					iECMSubscription = (IECMSubscription)SubscriptionsList[sourceAddress];
				}
				else
				{
					iECMSubscription = CreateSubscription(sourceAddress);
					if (needToBeCleared)
					{
						iECMSubscription.RemoveAll();
					}
					SubscriptionsList.Add(sourceAddress, iECMSubscription);
				}
			}
			iECMSubscription.IDLBufferRetrievalRate = Model.IDLBufferRetrievalRate;
			return iECMSubscription;
		}

		private IECMSubscription CreateSubscription(IAddressValue sourceAddress)
		{
			if (sourceAddress == null)
			{
				throw new ArgumentNullException($"Source Addess");
			}
			if (!Model.Network.Modules.Contains(sourceAddress))
			{
				throw new ArgumentException("Datasource not found for device address - " + sourceAddress.DisplayId);
			}
			ICalibrationOnline calibration = Model.Network.GetCalibration(sourceAddress);
			if (calibration == null)
			{
				throw new ArgumentNullException($"Calibration");
			}
			new SubscriptionProvider();
			IECMSubscription iECMSubscription = (IECMSubscription)SubscriptionProvider.Create(calibration, DataAcquisitionType.IDL, NotifyType.Message);
			RegisterSubscriptionEvents(iECMSubscription);
			return iECMSubscription;
		}

		private void ClearModuleValidators()
		{
			ModuleValidatorList.Clear();
		}

		private void RestoreModuleState()
		{
			foreach (IDLValidator value in ModuleValidatorList.Values)
			{
				value.RestoreModule();
			}
		}

		private void ClearAllSubScription()
		{
			int count = SubscriptionsList.Count;
			for (int i = 0; i < count; i++)
			{
				IECMSubscription iECMSubscription = (IECMSubscription)SubscriptionsList.GetByIndex(i);
				UnRegisterSubscriptionEvents(iECMSubscription);
				iECMSubscription?.Dispose();
			}
			SubscriptionsList.Clear();
		}

		private void RegisterSubscriptionEvents(IECMSubscription subscription)
		{
			if (subscription != null)
			{
				Model.IDLLogger.RegisterDataProvider(subscription as IDataProvider);
				subscription.IDLBufferTransferStarted += OnIDLBufferTransferStarted;
				subscription.IDLBufferTransferCompleted += OnIDLBufferTransferCompleted;
				subscription.IDLNotificationsStarted += OnIDLNotificationsStarted;
				subscription.IDLNotificationsCompleted += OnIDLNotificationsCompleted;
				subscription.IDLTransferInterrupt += OnIDLTransferInterrupt;
				subscription.IDLBufferIsFull += OnIDLBufferIsFull;
				subscription.IDLRetrievalRateIsTooFast += OnIDLRetrievalRateIsTooFast;
				subscription.IDLRetrievalRateIsTooSlow += OnIDLRetrievalRateIsTooSlow;
				(subscription.DataSource as ICalibrationOnline).ConnectionLost += OnConnectionLost;
				(subscription.DataSource as ICalibrationOnline).ConnectionEstablished += OnConnectionEstablished;
				subscription.Starting += OnSubscriptionStarting;
				subscription.Started += OnSubscriptionStarted;
				subscription.Stopping += OnSubscriptionStarting;
				subscription.Stopped += OnSubscriptionStarted;
				subscription.Pausing += OnSubscriptionStarting;
				subscription.Paused += OnSubscriptionStarted;
				subscription.Resuming += OnSubscriptionStarting;
				subscription.Resumed += OnSubscriptionStarted;
				if (subscription.DataSource is ICalibrationECM)
				{
					(subscription.DataSource as ICalibrationECM).CommandExecuteEvent += OnCommandExecute;
					(subscription.DataSource as ICalibrationECM).RunLocationChanged += OnRunLocationChanged;
				}
			}
		}

		private void UnRegisterSubscriptionEvents(IECMSubscription subscription)
		{
			if (subscription == null)
			{
				return;
			}
			Model.IDLLogger.UnRegisterDataProvider(subscription as IDataProvider);
			subscription.IDLBufferTransferStarted -= OnIDLBufferTransferStarted;
			subscription.IDLBufferTransferCompleted -= OnIDLBufferTransferCompleted;
			subscription.IDLNotificationsStarted -= OnIDLNotificationsStarted;
			subscription.IDLNotificationsCompleted -= OnIDLNotificationsCompleted;
			subscription.IDLTransferInterrupt -= OnIDLTransferInterrupt;
			try
			{
				IDataCollectorInfo dataCollectorInfo = new DataCollectorInfo(subscription.DataSource.CalibrationDataServer);
				if (dataCollectorInfo.DataCollectorType == DataCollectorType.DataCollector2)
				{
					(subscription.DataSource as ICalibrationOnline).ConnectionLost -= OnConnectionLost;
					(subscription.DataSource as ICalibrationOnline).ConnectionEstablished -= OnConnectionEstablished;
				}
			}
			catch (Exception)
			{
			}
			if (subscription.DataSource is ICalibrationECM)
			{
				(subscription.DataSource as ICalibrationECM).CommandExecuteEvent -= OnCommandExecute;
				(subscription.DataSource as ICalibrationECM).RunLocationChanged -= OnRunLocationChanged;
			}
		}

		private void ReportNotSupportedParameters(ArrayList notSupportedParameters)
		{
			if (notSupportedParameters == null || notSupportedParameters.Count <= 0)
			{
				return;
			}
			string text = string.Empty;
			foreach (IParameterModel notSupportedParameter in notSupportedParameters)
			{
				if (notSupportedParameter.DataType != ParameterType.Value || notSupportedParameter.DataType != ParameterType.Enumeration)
				{
					text = text + string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.AddressParameterNotSupported.ToString()), notSupportedParameter.Name, notSupportedParameter.DataType) + "\r\n";
				}
				else if (notSupportedParameter.IsInterfaceParameter)
				{
					text = text + string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.InterfaceParametersNotSupported.ToString()), notSupportedParameter.Name) + "\r\n";
				}
			}
			string message = IDLLogger.Resources.GetString(IDLMessageIDs.NotSupportedParameters.ToString());
			EventLogger.Info("IDL Logger", message, text);
		}

		private void OnIDLTransferInterrupt(object sender, IDLAutoTransferBufferEventArgs e)
		{
			if (Model.AutoTransferBuffer == InteropMessageReturnType.No)
			{
				Model.IDLState = IDLState.WaitingForRetrieving;
				retrieveBufferSignal.WaitOne();
				if (IDLState.Cancelling == IDLState)
				{
					e.ReturnType = InteropMessageReturnType.No;
				}
				else
				{
					e.ReturnType = InteropMessageReturnType.Yes;
				}
			}
			else
			{
				e.ReturnType = InteropMessageReturnType.Yes;
			}
		}

		public void OnIDLLoggingOptionsChangedEvent(object sender, EventArgs e)
		{
			Model.IDLLogger.Configuration.Initialize();
			Model.IDLLogger.Configuration.RecordingMode = RecordingModes.AnyDataReceived;
		}

		private void OnIDLBufferTransferStarted(object sender, EventArgs e)
		{
			Model.IDLState = IDLState.RetrievingBuffer;
		}

		private void OnIDLBufferTransferCompleted(object sender, EventArgs e)
		{
			Model.IDLState = IDLState.RetrievedBuffer;
		}

		private void OnIDLNotificationsStarted(object sender, EventArgs e)
		{
			Model.IDLState = IDLState.Logging;
			canLogData = true;
		}

		private void OnIDLNotificationsCompleted(object sender, EventArgs e)
		{
			lock (SubscriptionsList)
			{
				notificationExpected--;
				if (notificationExpected == 0)
				{
					StopDataLogger();
					idlThread = new Thread(IDLCleanUp);
					idlThread.Priority = ThreadPriority.Highest;
					idlThread.SetApartmentState(ApartmentState.MTA);
					idlThread.Name = "IDL CleanUp Thread";
					idlThread.Start();
				}
			}
		}

		private void OnIDLBufferIsFull(object sender, EventArgs e)
		{
			lock (this)
			{
				if (IDLState != IDLState.Stopping)
				{
					StopIDL();
				}
			}
		}

		private void OnIDLRetrievalRateIsTooFast(object sender, IDLRetrievalRateEventArgs e)
		{
			string detailedMessage = string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.IDLRetrievalRateDetailMessage.ToString()), e.ActualRate, e.RequestedRate);
			EventLogger.Warn("IDL Logger", e.Message, detailedMessage);
		}

		private void OnIDLRetrievalRateIsTooSlow(object sender, IDLRetrievalRateEventArgs e)
		{
			string detailedMessage = string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.IDLRetrievalRateDetailMessage.ToString()), e.ActualRate, e.RequestedRate);
			EventLogger.Warn("IDL Logger", e.Message, detailedMessage);
		}

		private void OnConnectionLost(object sender, EventArgs e)
		{
			ICalibrationOnline calibrationOnline = sender as ICalibrationOnline;
			IAddressValue sourceAddress = calibrationOnline.SourceAddress;
			if (calibrationOnline == null || SubscriptionsList[sourceAddress] == null)
			{
				return;
			}
			_ = SubscriptionsList[sourceAddress];
			lock (SubscriptionsList)
			{
				if (notificationExpected > 0)
				{
					notificationExpected--;
					if (notificationExpected == 0)
					{
						IDLCleanUp();
					}
				}
			}
		}

		private void OnConnectionEstablished(object sender, EventArgs e)
		{
			if (Model.StopIDLOnMonitorStart)
			{
				return;
			}
			ICalibrationOnline calibrationOnline = sender as ICalibrationOnline;
			IAddressValue sourceAddress = calibrationOnline.SourceAddress;
			if (calibrationOnline == null || SubscriptionsList[sourceAddress] == null)
			{
				return;
			}
			IECMSubscription iECMSubscription = SubscriptionsList[sourceAddress] as IECMSubscription;
			IDataCollectorInfo dataCollectorInfo = new DataCollectorInfo(iECMSubscription.DataSource.CalibrationDataServer);
			try
			{
				if (dataCollectorInfo.DataCollectorStatus == DataCollectorStatus.On || dataCollectorInfo.IDLStopMode == IDLStopType.KeyOn)
				{
					iECMSubscription.Resume();
					if (offlineDC2subscriptionList.Contains(iECMSubscription))
					{
						AddIDLLoggerParameter(iECMSubscription);
						offlineDC2subscriptionList.Remove(iECMSubscription);
					}
					lock (SubscriptionsList)
					{
						notificationExpected++;
						IDLState = IDLState.Started;
						return;
					}
				}
			}
			catch (Exception e2)
			{
				EventLogger.Error("IDL Logger", string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.ErrorInResumingIDL.ToString()), iECMSubscription.SourceAddress), e2);
			}
		}

		private UserResponse OnCommandExecute(Cummins.Calibration.CommandType command)
		{
			UserResponse result = UserResponse.Continue;
			if (IDLState != IDLState.Idle && IDLState.Starting != IDLState && IDLState != IDLState.CleaningUp)
			{
				switch (command)
				{
				case Cummins.Calibration.CommandType.RunFromDevelopment:
				case Cummins.Calibration.CommandType.StopEngine:
				case Cummins.Calibration.CommandType.CopyFromDevelopmentToDefault:
				case Cummins.Calibration.CommandType.CopyFromDefaultToDevelopment:
				case Cummins.Calibration.CommandType.RunFromBOOT:
				case Cummins.Calibration.CommandType.ReleaseChangeLock:
				case Cummins.Calibration.CommandType.RunFromApplication:
				case Cummins.Calibration.CommandType.ToggleSecurityKey:
				{
					string message = string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.ECMCommandCanNotBeExecuted.ToString()), command.ToString());
					throw new IDLException(8, message);
				}
				}
			}
			return result;
		}

		private void OnRunLocationChanged(object sender, RunLocationChangedEventArgs e)
		{
			if (IDLState != IDLState.Idle && IDLState.Cancelling != IDLState && IDLState.CleaningUp != IDLState && IDLState.Stopping != IDLState && RunLocationType.Default == e.EcmRunLocation)
			{
				CancelIDL();
				EventLogger.Error("IDL Logger", IDLLogger.Resources.GetString(IDLMessageIDs.AbortedIDLOnRunFromDefault.ToString()));
			}
		}

		private void OnStopBroadCast(object sender, StopBroadCastEventArgs e)
		{
			if (this.StopBroadCastEvent != null)
			{
				this.StopBroadCastEvent(sender, e);
			}
		}

		private void OnRunLocationChange(object sender, RunLocationChangeEventArgs e)
		{
			if (this.RunLocationChangeEvent != null)
			{
				this.RunLocationChangeEvent(sender, e);
			}
		}

		private void OnSubscriptionStarting(object sender, EventArgs e)
		{
			ICalibrationOnline calibrationOnline = (ICalibrationECM)Model.Network.GetCalibration((sender as IECMSubscription).SourceAddress);
			if (calibrationOnline is ICalibrationECM)
			{
				ICalibrationECM calibrationECM = (ICalibrationECM)calibrationOnline;
				GTISVersion gTISLevel = calibrationECM.CalibrationDataServer.GTISLevel;
				if ((gTISLevel == GTISVersion.GTIS38 || gTISLevel == GTISVersion.GTIS20) && calibrationECM.Secured == SecurityStatus.Secured && !calibrationECM.EnableTemporaryWrite)
				{
					(calibrationECM.DataLink as ICPPDataLink).EnableSecurity = true;
				}
			}
		}

		private void OnSubscriptionStarted(object sender, EventArgs e)
		{
			ICalibrationOnline calibrationOnline = (ICalibrationECM)Model.Network.GetCalibration((sender as IECMSubscription).SourceAddress);
			if (calibrationOnline is ICalibrationECM)
			{
				ICalibrationECM calibrationECM = (ICalibrationECM)calibrationOnline;
				GTISVersion gTISLevel = calibrationECM.CalibrationDataServer.GTISLevel;
				if ((gTISLevel == GTISVersion.GTIS38 || gTISLevel == GTISVersion.GTIS20) && calibrationECM.Secured == SecurityStatus.Secured && !calibrationECM.EnableTemporaryWrite)
				{
					(calibrationECM.DataLink as ICPPDataLink).EnableSecurity = false;
				}
			}
		}

		private void ReportIDLParameterList(string paramList)
		{
			if (paramList != null && paramList.Length > 0)
			{
				EventLogger.Info("IDL Logger", IDLLogger.Resources.GetString(IDLMessageIDs.IDLLoggingList.ToString()), paramList);
			}
		}

		private void ReportSouceAddressNotAvailableList(string paramList)
		{
			if (paramList != null && paramList.Length > 0)
			{
				EventLogger.Error("IDL Logger", IDLLogger.Resources.GetString(IDLMessageIDs.IDLSoueceAddressMissingLoggingList.ToString()), paramList);
			}
		}

		private void ReportIDLConfiguration(TriggerType triggerType, int idlRate, bool keyOn, IDLStopType stopType)
		{
			string text = "";
			object obj = text;
			text = string.Concat(obj, "Trigger source: ", triggerType, "\r\n");
			object obj2 = text;
			text = string.Concat(obj2, "Trigger period: ", idlRate, " ", IDLLogger.GetUnit(triggerType), "\r\n");
			if (keyOn)
			{
				text += "Start IDL on keyswitch on\r\n";
			}
			else
			{
				object obj3 = text;
				text = string.Concat(obj3, "Stop Mode: ", stopType, "\r\n");
			}
			EventLogger.Info("IDL Logger", IDLLogger.Resources.GetString(IDLMessageIDs.IDLConfiguration.ToString()), text);
		}

		private void ConfigureCustomIDLHeader(IECMSubscription subscription)
		{
			Model.IDLLogger.Configuration.AddSpecialFileHeaderValue("IDL Trigger Source", subscription.TriggerMode.ToString());
			int num = subscription.RateMultiplier * SubscriptionRateHelper.GetBaseRate(subscription, subscription.TriggerMode);
			Model.IDLLogger.Configuration.AddSpecialFileHeaderValue("IDL Trigger Period", num + " " + IDLLogger.GetUnit(subscription.TriggerMode));
			if (subscription.IDLStopMode == IDLStopType.KeyOn)
			{
				Model.IDLLogger.Configuration.RemoveSpecialFileHeader("IDL Stop Mode");
				Model.IDLLogger.Configuration.AddSpecialFileHeaderValue("IDL on key on", "");
			}
			else
			{
				Model.IDLLogger.Configuration.RemoveSpecialFileHeader("IDL on key on");
				Model.IDLLogger.Configuration.AddSpecialFileHeaderValue("IDL Stop Mode", subscription.IDLStopMode.ToString());
			}
		}
	}
	internal class IDLLoggingModel
	{
		private const string Slash = "\\";

		private const string CustomLogheaderFileName = "CustomLogHeader.xml";

		private Cummins.Logging.Logging idlLogger;

		private IModuleNetwork network;

		private IDLState idlState;

		private IDLConfiguration idlConfiguration;

		internal TriggerType IDLTriggerMode => idlConfiguration.IDLTriggerMode;

		internal IDLStopType IDLStopMode => idlConfiguration.IDLStopMode;

		internal bool IDLOnKeyOn => idlConfiguration.IDLOnKeyOn;

		internal bool AutoConfigureIDL => idlConfiguration.AutoConfigureIDL;

		internal bool StopIDLOnMonitorStart => idlConfiguration.StopIDLOnMonitorStart;

		internal int IDLBufferRetrievalRate
		{
			get
			{
				int bufferRetrievalRate = idlConfiguration.BufferRetrievalRate;
				return (!idlConfiguration.RetrieveIDLAtMaxRate) ? bufferRetrievalRate : 0;
			}
		}

		internal InteropMessageReturnType AutoTransferBuffer
		{
			get
			{
				InteropMessageReturnType interopMessageReturnType = InteropMessageReturnType.Unspecified;
				return idlConfiguration.AutoBufferRetrieval.ToString().ToUpper() switch
				{
					"TRUE" => InteropMessageReturnType.Yes, 
					"FALSE" => InteropMessageReturnType.No, 
					_ => InteropMessageReturnType.Unspecified, 
				};
			}
		}

		internal int IDLRate => idlConfiguration.TriggerPeriod;

		internal IDLState IDLState
		{
			get
			{
				return idlState;
			}
			set
			{
				if (value != IDLState)
				{
					idlState = value;
					RaiseIDLStateChangedEvent();
				}
			}
		}

		internal Cummins.Logging.Logging IDLLogger
		{
			get
			{
				if (idlLogger == null)
				{
					idlLogger = new Cummins.Logging.Logging();
					idlLogger.MonitorMode = DataAcquisitionType.IDL;
					idlLogger.Initialize();
					idlLogger.Configuration.RecordingMode = RecordingModes.AnyDataReceived;
				}
				return idlLogger;
			}
		}

		internal IModuleNetwork Network
		{
			get
			{
				return network;
			}
			set
			{
				if (IDLState == IDLState.Idle)
				{
					network = value;
					IDLLogger.Network = value;
				}
				else
				{
					new IDLException(6, Cummins.IDLLogger.IDLLogger.Resources.GetString(IDLMessageIDs.IDLAlreadyRunning.ToString()));
				}
			}
		}

		internal event IDLStateChangedEventHandler IDLStateChangedEvent;

		internal IDLLoggingModel()
		{
			idlConfiguration = new IDLConfiguration();
		}

		private void RaiseIDLStateChangedEvent()
		{
			if (this.IDLStateChangedEvent != null)
			{
				IDLStateChangedEventArgs e = new IDLStateChangedEventArgs(IDLState);
				this.IDLStateChangedEvent(this, e);
			}
		}
	}
	internal class IDLPre45Validator : IDLValidator
	{
		private bool changedRunLocation;

		internal override ModuleValidatorResultType CanRunIDL
		{
			get
			{
				if (validatorResultType == ModuleValidatorResultType.NotValidated)
				{
					Validate();
				}
				return validatorResultType;
			}
		}

		internal IDLPre45Validator(ICalibrationOnline calibration)
			: base(calibration)
		{
		}

		protected override bool Validate()
		{
			try
			{
				base.Validate();
				ValidateRunLocation();
				validatorResultType = ModuleValidatorResultType.CanRunIDL;
			}
			catch
			{
				validatorResultType = ModuleValidatorResultType.CanNotRunIDL;
				RestoreModule();
				throw;
			}
			return validatorResultType == ModuleValidatorResultType.CanNotRunIDL;
		}

		internal override void RestoreModule()
		{
			if (changedRunLocation)
			{
				base.DataSource.Execute(Cummins.Calibration.CommandType.RunFromDefault);
			}
		}

		private void ValidateRunLocation()
		{
			if (RunLocationType.Default != base.DataSource.ECMRunLocation)
			{
				return;
			}
			ISecurityService securityService = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
			if (securityService == null)
			{
				return;
			}
			if (!securityService.IsFeatureSelected(Cummins.CalToolsLib.SelectableFeatures.TemporaryWritestoSecureModules.ToString()))
			{
				string message = IDLLogger.Resources.GetString(IDLMessageIDs.ModuleIsInDefaultMode.ToString());
				MsgBoxResult msgBoxResult = MsgBox.Show(message, "IDL Logger", MsgBoxButtons.YesNo, MsgBoxIcon.Question);
				if (msgBoxResult == MsgBoxResult.Yes)
				{
					ExecutionResult executionResult = default(ExecutionResult);
					try
					{
						if (base.DataSource.Secured == SecurityStatus.Secured)
						{
							(base.DataSource.DataLink as ICPPDataLink).EnableSecurity = true;
						}
						executionResult = base.DataSource.Execute(Cummins.Calibration.CommandType.RunFromDevelopment);
						if (base.DataSource.Secured == SecurityStatus.Secured)
						{
							(base.DataSource.DataLink as ICPPDataLink).EnableSecurity = false;
						}
						if (CommandReturnType.Failed == executionResult.returnCode)
						{
							throw new Exception(executionResult.responseDescription);
						}
						changedRunLocation = true;
						return;
					}
					catch (Exception inner)
					{
						message = string.Format(IDLLogger.Resources.GetString(IDLMessageIDs.ECMCommandFailed.ToString()), Cummins.Calibration.CommandType.RunFromDevelopment.ToString(), base.DataSource.SourceAddress.DisplayId);
						throw new IDLException(7, message, inner);
					}
				}
				message = IDLLogger.Resources.GetString(IDLMessageIDs.ModuleShouldnotInDefaultMode.ToString());
				throw new IDLException(18, message);
			}
			string message2 = IDLLogger.Resources.GetString(IDLMessageIDs.NotInDevelopmentMode.ToString());
			throw new IDLException(33, message2);
		}
	}
	internal enum ModuleValidatorResultType
	{
		NotValidated,
		CanRunIDL,
		CanNotRunIDL
	}
}
