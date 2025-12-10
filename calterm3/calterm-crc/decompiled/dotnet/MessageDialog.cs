using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using System.Windows.Forms;
using System.Xml;
using Cummins.ApplicationServices;
using Cummins.ErrorDataRepository;
using Cummins.ErrorDataRepositoryViewer;
using Cummins.Services;

[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTitle("Poodle")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - MessageDialog")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.MessageDialog;

public class CheckBoxMessageDialog : Form
{
	private enum DialogStyle
	{
		Detail,
		General
	}

	private const string More = "More >>";

	private const string Less = "Less <<";

	private Container components;

	private ResourceManager resources = new ResourceManager(typeof(MessageDialog));

	private PictureBox iconPictureBox;

	private TextBox detailTextBox;

	private string appConfigSetting;

	private Size maxDialogSize = new Size(404, 354);

	private Size maxTexBoxSize = new Size(404, 166);

	private Size minDialogSize = new Size(404, 188);

	private Button button3;

	private Button button2;

	private Button button1;

	private TextBox generalTextBox;

	private CheckBox checkBox1;

	private Size minTextBoxSize = new Size(0, 0);

	public CheckBoxMessageDialog()
	{
		InitializeComponent();
		((Form)this).ClientSize = minDialogSize;
		((Control)detailTextBox).Size = minTextBoxSize;
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
		//IL_0043: Unknown result type (might be due to invalid IL or missing references)
		//IL_004d: Expected O, but got Unknown
		//IL_01fd: Unknown result type (might be due to invalid IL or missing references)
		//IL_0207: Expected O, but got Unknown
		iconPictureBox = new PictureBox();
		detailTextBox = new TextBox();
		button3 = new Button();
		button2 = new Button();
		button1 = new Button();
		generalTextBox = new TextBox();
		checkBox1 = new CheckBox();
		((Control)this).SuspendLayout();
		((Control)iconPictureBox).Location = new Point(7, 22);
		((Control)iconPictureBox).Name = "iconPictureBox";
		((Control)iconPictureBox).Size = new Size(57, 50);
		iconPictureBox.TabIndex = 6;
		iconPictureBox.TabStop = false;
		((Control)detailTextBox).BackColor = SystemColors.InactiveBorder;
		((Control)detailTextBox).Dock = (DockStyle)2;
		((Control)detailTextBox).Location = new Point(0, 187);
		((TextBoxBase)detailTextBox).Multiline = true;
		((Control)detailTextBox).Name = "detailTextBox";
		((TextBoxBase)detailTextBox).ReadOnly = true;
		detailTextBox.ScrollBars = (ScrollBars)3;
		((Control)detailTextBox).Size = new Size(408, 166);
		((Control)detailTextBox).TabIndex = 7;
		((Control)detailTextBox).Text = "";
		((TextBoxBase)detailTextBox).WordWrap = false;
		((Control)button3).Location = new Point(303, 152);
		((Control)button3).Name = "button3";
		((Control)button3).Size = new Size(82, 23);
		((Control)button3).TabIndex = 3;
		((Control)button2).Location = new Point(158, 151);
		((Control)button2).Name = "button2";
		((Control)button2).Size = new Size(82, 23);
		((Control)button2).TabIndex = 3;
		((Control)button2).Visible = false;
		((Control)button1).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
		((Control)button1).Location = new Point(15, 152);
		((Control)button1).Name = "button1";
		((Control)button1).Size = new Size(79, 23);
		((Control)button1).TabIndex = 5;
		((Control)button1).Visible = false;
		((TextBoxBase)generalTextBox).BorderStyle = (BorderStyle)0;
		((Control)generalTextBox).Location = new Point(80, 24);
		((TextBoxBase)generalTextBox).Multiline = true;
		((Control)generalTextBox).Name = "generalTextBox";
		((TextBoxBase)generalTextBox).ReadOnly = true;
		((Control)generalTextBox).Size = new Size(320, 96);
		((Control)generalTextBox).TabIndex = 8;
		((Control)generalTextBox).Text = "";
		((Control)checkBox1).Location = new Point(160, 128);
		((Control)checkBox1).Name = "checkBox1";
		((Control)checkBox1).Size = new Size(216, 16);
		((Control)checkBox1).TabIndex = 9;
		((Control)checkBox1).Text = " Do not show this message again.";
		checkBox1.CheckedChanged += checkBox1_CheckedChanged;
		((Form)this).AutoScale = false;
		((Form)this).AutoScaleBaseSize = new Size(5, 13);
		((Form)this).ClientSize = new Size(408, 353);
		((Control)this).Controls.Add((Control)(object)checkBox1);
		((Control)this).Controls.Add((Control)(object)generalTextBox);
		((Control)this).Controls.Add((Control)(object)detailTextBox);
		((Control)this).Controls.Add((Control)(object)iconPictureBox);
		((Control)this).Controls.Add((Control)(object)button3);
		((Control)this).Controls.Add((Control)(object)button1);
		((Control)this).Controls.Add((Control)(object)button2);
		((Form)this).FormBorderStyle = (FormBorderStyle)5;
		((Form)this).MaximizeBox = false;
		((Form)this).MinimizeBox = false;
		((Control)this).Name = "CheckBoxMessageDialog";
		((Form)this).SizeGripStyle = (SizeGripStyle)2;
		((Form)this).StartPosition = (FormStartPosition)1;
		((Control)this).Text = "Calterm III";
		((Form)this).TopMost = true;
		((Control)this).ResumeLayout(false);
	}

	internal DialogResult Show(string message, MessageDialogButtons button, MessageDialogIcon icon, string appConfigSetting)
	{
		//IL_0024: Unknown result type (might be due to invalid IL or missing references)
		SetIcon(icon);
		SetButton(button, DialogStyle.General);
		((Control)generalTextBox).Text = message;
		this.appConfigSetting = appConfigSetting;
		return ((Form)this).ShowDialog();
	}

	internal DialogResult Show(IWin32Window owner, string message, MessageDialogButtons button, MessageDialogIcon icon, string appConfigSetting)
	{
		//IL_0026: Unknown result type (might be due to invalid IL or missing references)
		SetIcon(icon);
		SetButton(button, DialogStyle.General);
		((Control)generalTextBox).Text = message;
		this.appConfigSetting = appConfigSetting;
		return ((Form)this).ShowDialog(owner);
	}

	internal DialogResult Show(string message, string detailText, MessageDialogButtons button, MessageDialogIcon icon, string appConfigSetting)
	{
		//IL_0042: Unknown result type (might be due to invalid IL or missing references)
		((Control)generalTextBox).Text = message;
		SetIcon(icon);
		SetButton(button, DialogStyle.Detail);
		if (detailText.Length == 0)
		{
			((Control)button1).Enabled = false;
		}
		else
		{
			ParseXMLNode(detailText);
		}
		this.appConfigSetting = appConfigSetting;
		return ((Form)this).ShowDialog();
	}

	internal DialogResult Show(IWin32Window owner, string message, string detailText, MessageDialogButtons button, MessageDialogIcon icon, string appConfigSetting)
	{
		//IL_003a: Unknown result type (might be due to invalid IL or missing references)
		((Control)generalTextBox).Text = message;
		((Control)detailTextBox).Text = detailText;
		ParseXMLNode(detailText);
		SetIcon(icon);
		SetButton(button, DialogStyle.Detail);
		this.appConfigSetting = appConfigSetting;
		return ((Form)this).ShowDialog(owner);
	}

	private void SetIcon(MessageDialogIcon icon)
	{
		//IL_002e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0038: Expected O, but got Unknown
		//IL_004a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0054: Expected O, but got Unknown
		//IL_0066: Unknown result type (might be due to invalid IL or missing references)
		//IL_0070: Expected O, but got Unknown
		//IL_0082: Unknown result type (might be due to invalid IL or missing references)
		//IL_008c: Expected O, but got Unknown
		//IL_009e: Unknown result type (might be due to invalid IL or missing references)
		//IL_00a8: Expected O, but got Unknown
		switch (icon)
		{
		case MessageDialogIcon.Stop:
			iconPictureBox.Image = (Image)new Bitmap(((object)this).GetType(), "stop.bmp");
			break;
		case MessageDialogIcon.Error:
			iconPictureBox.Image = (Image)new Bitmap(((object)this).GetType(), "error.bmp");
			break;
		case MessageDialogIcon.Information:
			iconPictureBox.Image = (Image)new Bitmap(((object)this).GetType(), "information.bmp");
			break;
		case MessageDialogIcon.Question:
			iconPictureBox.Image = (Image)new Bitmap(((object)this).GetType(), "question.bmp");
			break;
		case MessageDialogIcon.Warning:
			iconPictureBox.Image = (Image)new Bitmap(((object)this).GetType(), "warning.bmp");
			break;
		}
	}

	private void SetButton(MessageDialogButtons button, DialogStyle style)
	{
		if (style == DialogStyle.General)
		{
			((Control)button1).Visible = false;
			switch (button)
			{
			case MessageDialogButtons.OK:
				((Control)button2).Visible = false;
				((Control)button3).Text = "&OK";
				((Control)button3).Click += OKButton_Click;
				break;
			case MessageDialogButtons.OKCancel:
				((Control)button2).Visible = true;
				((Control)button2).Text = "&OK";
				((Control)button3).Text = "&Cancel";
				((Control)button2).Click += OKButton_Click;
				((Control)button3).Click += CancelButton_Click;
				break;
			case MessageDialogButtons.YesNo:
				((Control)button2).Visible = true;
				((Control)button2).Text = "&Yes";
				((Control)button3).Text = "&No";
				((Control)button2).Click += YesButton_Click;
				((Control)button3).Click += NoButton_Click;
				break;
			}
			return;
		}
		((Control)button1).Text = "More >>";
		((Control)button1).Visible = true;
		((Control)button1).Click += MoreLessButton_Click;
		switch (button)
		{
		case MessageDialogButtons.OK:
			((Control)button2).Visible = false;
			((Control)button3).Text = "&OK";
			((Control)button3).Click += OKButton_Click;
			break;
		case MessageDialogButtons.OKCancel:
			((Control)button2).Visible = true;
			((Control)button2).Text = "&OK";
			((Control)button3).Text = "&Cancel";
			((Control)button2).Click += OKButton_Click;
			((Control)button3).Click += CancelButton_Click;
			break;
		case MessageDialogButtons.YesNo:
			((Control)button2).Visible = true;
			((Control)button2).Text = "&Yes";
			((Control)button3).Text = "&No";
			((Control)button2).Click += YesButton_Click;
			((Control)button3).Click += NoButton_Click;
			break;
		}
	}

	private void OKButton_Click(object sender, EventArgs e)
	{
		((Form)this).DialogResult = (DialogResult)1;
		((Component)this).Dispose();
	}

	private void YesButton_Click(object sender, EventArgs e)
	{
		((Form)this).DialogResult = (DialogResult)6;
		((Component)this).Dispose();
	}

	private void NoButton_Click(object sender, EventArgs e)
	{
		((Form)this).DialogResult = (DialogResult)7;
		((Component)this).Dispose();
	}

	private void CancelButton_Click(object sender, EventArgs e)
	{
		((Form)this).DialogResult = (DialogResult)2;
		((Component)this).Dispose();
	}

	private void MoreLessButton_Click(object sender, EventArgs e)
	{
		if (((Control)button1).Text == "More >>")
		{
			((Form)this).ClientSize = maxDialogSize;
			((Control)detailTextBox).Size = maxTexBoxSize;
			((Control)button1).Text = "Less <<";
		}
		else
		{
			((Control)button1).Text = "More >>";
			((Form)this).ClientSize = minDialogSize;
			((Control)detailTextBox).Size = minTextBoxSize;
		}
	}

	private void ParseXMLNode(string xmlString)
	{
		//IL_0000: Unknown result type (might be due to invalid IL or missing references)
		//IL_0006: Expected O, but got Unknown
		//IL_0023: Unknown result type (might be due to invalid IL or missing references)
		//IL_0029: Expected O, but got Unknown
		try
		{
			XmlDocument val = new XmlDocument();
			val.LoadXml(xmlString);
			XmlNodeList childNodes = ((XmlNode)val).ChildNodes;
			foreach (XmlElement item in childNodes)
			{
				XmlElement xmlelement = item;
				ProcessXmlElement(xmlelement);
			}
		}
		catch (Exception)
		{
			((Control)detailTextBox).Text = xmlString;
		}
	}

	private void ProcessXmlElement(XmlElement xmlelement)
	{
		//IL_0030: Unknown result type (might be due to invalid IL or missing references)
		//IL_0036: Expected O, but got Unknown
		XmlNodeList childNodes = ((XmlNode)xmlelement).ChildNodes;
		for (int i = 0; i < childNodes.Count; i++)
		{
			string text = "";
			foreach (XmlNode childNode in childNodes[i].ChildNodes)
			{
				XmlNode val = childNode;
				string text2 = text;
				text = text2 + val.Name + ": " + val.InnerText + "\r\n";
			}
			TextBox obj = detailTextBox;
			((Control)obj).Text = ((Control)obj).Text + text + "\r\n";
		}
	}

	private void checkBox1_CheckedChanged(object sender, EventArgs e)
	{
		AppSettingHelper.ChangeSetting(ApplicationSettings.UnlockSecurityMessageCheck, checkBox1.Checked.ToString());
	}
}
public class MessageDialog : Form
{
	private enum DialogStyle
	{
		Detail,
		General
	}

	private const string More = "More >>";

	private const string Less = "Less <<";

	private Container components;

	private ResourceManager resources = new ResourceManager(typeof(MessageDialog));

	private PictureBox iconPictureBox;

	private TextBox detailTextBox;

	private string errorCode = string.Empty;

	private Size maxDialogSize = new Size(404, 354);

	private Size maxTexBoxSize = new Size(404, 166);

	private Size minDialogSize = new Size(404, 188);

	private Button button3;

	private Button button2;

	private Button button1;

	private TextBox generalTextBox;

	private LinkLabel linkLabelTroubleshoot;

	private Size minTextBoxSize = new Size(0, 0);

	public MessageDialog()
	{
		InitializeComponent();
		((Form)this).ClientSize = minDialogSize;
		((Control)detailTextBox).Size = minTextBoxSize;
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
		//IL_0208: Unknown result type (might be due to invalid IL or missing references)
		//IL_0212: Expected O, but got Unknown
		//IL_02e5: Unknown result type (might be due to invalid IL or missing references)
		//IL_0378: Unknown result type (might be due to invalid IL or missing references)
		//IL_0382: Expected O, but got Unknown
		//IL_0421: Unknown result type (might be due to invalid IL or missing references)
		//IL_042b: Expected O, but got Unknown
		ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(MessageDialog));
		iconPictureBox = new PictureBox();
		detailTextBox = new TextBox();
		button3 = new Button();
		button2 = new Button();
		button1 = new Button();
		generalTextBox = new TextBox();
		linkLabelTroubleshoot = new LinkLabel();
		((ISupportInitialize)iconPictureBox).BeginInit();
		((Control)this).SuspendLayout();
		((Control)iconPictureBox).Location = new Point(7, 22);
		((Control)iconPictureBox).Name = "iconPictureBox";
		((Control)iconPictureBox).Size = new Size(57, 50);
		iconPictureBox.TabIndex = 6;
		iconPictureBox.TabStop = false;
		((Control)detailTextBox).BackColor = SystemColors.InactiveBorder;
		((Control)detailTextBox).Dock = (DockStyle)2;
		((Control)detailTextBox).Location = new Point(0, 187);
		((TextBoxBase)detailTextBox).Multiline = true;
		((Control)detailTextBox).Name = "detailTextBox";
		((TextBoxBase)detailTextBox).ReadOnly = true;
		detailTextBox.ScrollBars = (ScrollBars)3;
		((Control)detailTextBox).Size = new Size(408, 166);
		((Control)detailTextBox).TabIndex = 7;
		((TextBoxBase)detailTextBox).WordWrap = false;
		((Control)button3).Location = new Point(303, 152);
		((Control)button3).Name = "button3";
		((Control)button3).Size = new Size(82, 23);
		((Control)button3).TabIndex = 3;
		((Control)button2).Location = new Point(158, 151);
		((Control)button2).Name = "button2";
		((Control)button2).Size = new Size(82, 23);
		((Control)button2).TabIndex = 3;
		((Control)button2).Visible = false;
		((Control)button1).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
		((Control)button1).Location = new Point(15, 152);
		((Control)button1).Name = "button1";
		((Control)button1).Size = new Size(79, 23);
		((Control)button1).TabIndex = 5;
		((Control)button1).Visible = false;
		((TextBoxBase)generalTextBox).BorderStyle = (BorderStyle)0;
		((Control)generalTextBox).Location = new Point(80, 24);
		((TextBoxBase)generalTextBox).Multiline = true;
		((Control)generalTextBox).Name = "generalTextBox";
		((TextBoxBase)generalTextBox).ReadOnly = true;
		((Control)generalTextBox).Size = new Size(320, 96);
		((Control)generalTextBox).TabIndex = 8;
		((Control)linkLabelTroubleshoot).AutoSize = true;
		linkLabelTroubleshoot.LinkArea = new LinkArea(13, 4);
		((Control)linkLabelTroubleshoot).Location = new Point(79, 123);
		((Control)linkLabelTroubleshoot).Name = "linkLabelTroubleshoot";
		((Control)linkLabelTroubleshoot).Size = new Size(320, 17);
		((Control)linkLabelTroubleshoot).TabIndex = 9;
		linkLabelTroubleshoot.TabStop = true;
		((Control)linkLabelTroubleshoot).Text = "Please click here for more information and troubleshooting tips.";
		linkLabelTroubleshoot.UseCompatibleTextRendering = true;
		((Control)linkLabelTroubleshoot).Visible = false;
		linkLabelTroubleshoot.LinkClicked += new LinkLabelLinkClickedEventHandler(OnlinkLabelTroubleshootClicked);
		((Form)this).ClientSize = new Size(408, 353);
		((Control)this).Controls.Add((Control)(object)linkLabelTroubleshoot);
		((Control)this).Controls.Add((Control)(object)generalTextBox);
		((Control)this).Controls.Add((Control)(object)detailTextBox);
		((Control)this).Controls.Add((Control)(object)iconPictureBox);
		((Control)this).Controls.Add((Control)(object)button3);
		((Control)this).Controls.Add((Control)(object)button1);
		((Control)this).Controls.Add((Control)(object)button2);
		((Form)this).FormBorderStyle = (FormBorderStyle)5;
		((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
		((Form)this).MaximizeBox = false;
		((Form)this).MinimizeBox = false;
		((Control)this).Name = "MessageDialog";
		((Form)this).SizeGripStyle = (SizeGripStyle)2;
		((Form)this).StartPosition = (FormStartPosition)1;
		((Control)this).Text = "Calterm III";
		((Form)this).TopMost = true;
		((ISupportInitialize)iconPictureBox).EndInit();
		((Control)this).ResumeLayout(false);
		((Control)this).PerformLayout();
	}

	internal DialogResult Show(string message, MessageDialogButtons button, MessageDialogIcon icon)
	{
		//IL_001c: Unknown result type (might be due to invalid IL or missing references)
		SetIcon(icon);
		SetButton(button, DialogStyle.General);
		((Control)generalTextBox).Text = message;
		return ((Form)this).ShowDialog();
	}

	internal DialogResult Show(IWin32Window owner, string message, MessageDialogButtons button, MessageDialogIcon icon)
	{
		//IL_001e: Unknown result type (might be due to invalid IL or missing references)
		SetIcon(icon);
		SetButton(button, DialogStyle.General);
		((Control)generalTextBox).Text = message;
		return ((Form)this).ShowDialog(owner);
	}

	internal DialogResult Show(string message, string detailText, MessageDialogButtons button, MessageDialogIcon icon)
	{
		//IL_000b: Unknown result type (might be due to invalid IL or missing references)
		return Show(message, detailText, string.Empty, button, icon);
	}

	internal DialogResult Show(IWin32Window owner, string message, string detailText, MessageDialogButtons button, MessageDialogIcon icon)
	{
		//IL_0032: Unknown result type (might be due to invalid IL or missing references)
		((Control)generalTextBox).Text = message;
		((Control)detailTextBox).Text = detailText;
		ParseXMLNode(detailText);
		SetIcon(icon);
		SetButton(button, DialogStyle.Detail);
		return ((Form)this).ShowDialog(owner);
	}

	internal DialogResult Show(string message, string detailText, string errorCode, MessageDialogButtons button, MessageDialogIcon icon)
	{
		//IL_0069: Unknown result type (might be due to invalid IL or missing references)
		((Control)generalTextBox).Text = message;
		this.errorCode = errorCode;
		SetIcon(icon);
		SetButton(button, DialogStyle.Detail);
		if (detailText.Length == 0)
		{
			((Control)button1).Enabled = false;
		}
		else
		{
			ParseXMLNode(detailText);
		}
		if (Cummins.ErrorDataRepository.ErrorDataRepository.Instance.IsErrorIdPresent(errorCode))
		{
			((Control)linkLabelTroubleshoot).Visible = true;
		}
		else
		{
			((Control)linkLabelTroubleshoot).Visible = false;
		}
		return ((Form)this).ShowDialog();
	}

	private void SetIcon(MessageDialogIcon icon)
	{
		//IL_002e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0038: Expected O, but got Unknown
		//IL_004a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0054: Expected O, but got Unknown
		//IL_0066: Unknown result type (might be due to invalid IL or missing references)
		//IL_0070: Expected O, but got Unknown
		//IL_0082: Unknown result type (might be due to invalid IL or missing references)
		//IL_008c: Expected O, but got Unknown
		//IL_009e: Unknown result type (might be due to invalid IL or missing references)
		//IL_00a8: Expected O, but got Unknown
		switch (icon)
		{
		case MessageDialogIcon.Stop:
			iconPictureBox.Image = (Image)new Bitmap(((object)this).GetType(), "stop.bmp");
			break;
		case MessageDialogIcon.Error:
			iconPictureBox.Image = (Image)new Bitmap(((object)this).GetType(), "error.bmp");
			break;
		case MessageDialogIcon.Information:
			iconPictureBox.Image = (Image)new Bitmap(((object)this).GetType(), "information.bmp");
			break;
		case MessageDialogIcon.Question:
			iconPictureBox.Image = (Image)new Bitmap(((object)this).GetType(), "question.bmp");
			break;
		case MessageDialogIcon.Warning:
			iconPictureBox.Image = (Image)new Bitmap(((object)this).GetType(), "warning.bmp");
			break;
		}
	}

	private void SetButton(MessageDialogButtons button, DialogStyle style)
	{
		if (style == DialogStyle.General)
		{
			((Control)button1).Visible = false;
			switch (button)
			{
			case MessageDialogButtons.OK:
				((Control)button2).Visible = false;
				((Control)button3).Text = "&OK";
				((Control)button3).Click += OKButton_Click;
				break;
			case MessageDialogButtons.OKCancel:
				((Control)button2).Visible = true;
				((Control)button2).Text = "&OK";
				((Control)button3).Text = "&Cancel";
				((Control)button2).Click += OKButton_Click;
				((Control)button3).Click += CancelButton_Click;
				break;
			case MessageDialogButtons.YesNo:
				((Control)button2).Visible = true;
				((Control)button2).Text = "&Yes";
				((Control)button3).Text = "&No";
				((Control)button2).Click += YesButton_Click;
				((Control)button3).Click += NoButton_Click;
				break;
			}
			return;
		}
		((Control)button1).Text = "More >>";
		((Control)button1).Visible = true;
		((Control)button1).Click += MoreLessButton_Click;
		switch (button)
		{
		case MessageDialogButtons.OK:
			((Control)button2).Visible = false;
			((Control)button3).Text = "&OK";
			((Control)button3).Click += OKButton_Click;
			break;
		case MessageDialogButtons.OKCancel:
			((Control)button2).Visible = true;
			((Control)button2).Text = "&OK";
			((Control)button3).Text = "&Cancel";
			((Control)button2).Click += OKButton_Click;
			((Control)button3).Click += CancelButton_Click;
			break;
		case MessageDialogButtons.YesNo:
			((Control)button2).Visible = true;
			((Control)button2).Text = "&Yes";
			((Control)button3).Text = "&No";
			((Control)button2).Click += YesButton_Click;
			((Control)button3).Click += NoButton_Click;
			break;
		}
	}

	private void OKButton_Click(object sender, EventArgs e)
	{
		((Form)this).DialogResult = (DialogResult)1;
		((Component)this).Dispose();
	}

	private void YesButton_Click(object sender, EventArgs e)
	{
		((Form)this).DialogResult = (DialogResult)6;
		((Component)this).Dispose();
	}

	private void NoButton_Click(object sender, EventArgs e)
	{
		((Form)this).DialogResult = (DialogResult)7;
		((Component)this).Dispose();
	}

	private void CancelButton_Click(object sender, EventArgs e)
	{
		((Form)this).DialogResult = (DialogResult)2;
		((Component)this).Dispose();
	}

	private void MoreLessButton_Click(object sender, EventArgs e)
	{
		if (((Control)button1).Text == "More >>")
		{
			((Form)this).ClientSize = maxDialogSize;
			((Control)detailTextBox).Size = maxTexBoxSize;
			((Control)button1).Text = "Less <<";
		}
		else
		{
			((Control)button1).Text = "More >>";
			((Form)this).ClientSize = minDialogSize;
			((Control)detailTextBox).Size = minTextBoxSize;
		}
	}

	private void ParseXMLNode(string xmlString)
	{
		//IL_0000: Unknown result type (might be due to invalid IL or missing references)
		//IL_0006: Expected O, but got Unknown
		//IL_0023: Unknown result type (might be due to invalid IL or missing references)
		//IL_0029: Expected O, but got Unknown
		try
		{
			XmlDocument val = new XmlDocument();
			val.LoadXml(xmlString);
			XmlNodeList childNodes = ((XmlNode)val).ChildNodes;
			foreach (XmlElement item in childNodes)
			{
				XmlElement xmlelement = item;
				ProcessXmlElement(xmlelement);
			}
		}
		catch (Exception)
		{
			((Control)detailTextBox).Text = xmlString;
		}
	}

	private void ProcessXmlElement(XmlElement xmlelement)
	{
		//IL_0030: Unknown result type (might be due to invalid IL or missing references)
		//IL_0036: Expected O, but got Unknown
		XmlNodeList childNodes = ((XmlNode)xmlelement).ChildNodes;
		for (int i = 0; i < childNodes.Count; i++)
		{
			string text = "";
			foreach (XmlNode childNode in childNodes[i].ChildNodes)
			{
				XmlNode val = childNode;
				string text2 = text;
				text = text2 + val.Name + ": " + val.InnerText + "\r\n";
			}
			TextBox obj = detailTextBox;
			((Control)obj).Text = ((Control)obj).Text + text + "\r\n";
		}
	}

	private void OnlinkLabelTroubleshootClicked(object sender, LinkLabelLinkClickedEventArgs e)
	{
		Cummins.ErrorDataRepositoryViewer.ErrorDataRepositoryViewer.Instance.ShowErrorInformation(errorCode);
	}
}
public interface IMessageDialog
{
	DialogResult Show(string message, MessageDialogButtons button, MessageDialogIcon icon);

	DialogResult Show(IWin32Window owner, string message, MessageDialogButtons button, MessageDialogIcon icon);

	DialogResult Show(string message, string detailText, MessageDialogButtons button, MessageDialogIcon icon);

	DialogResult Show(IWin32Window owner, string message, string detailText, MessageDialogButtons button, MessageDialogIcon icon);

	DialogResult Show(string caption, string message, string detailText, MessageDialogButtons button, MessageDialogIcon icon);

	DialogResult Show(string caption, string message, string detailText, string errorCode, MessageDialogButtons button, MessageDialogIcon icon);

	DialogResult ShowWithCheckBox(string message, MessageDialogButtons button, MessageDialogIcon icon, string appConfigSetting);

	DialogResult ShowWithCheckBox(IWin32Window owner, string message, MessageDialogButtons button, MessageDialogIcon icon, string appConfigSetting);

	DialogResult ShowWithCheckBox(string message, string detailText, MessageDialogButtons button, MessageDialogIcon icon, string appConfigSetting);

	DialogResult ShowWithCheckBox(IWin32Window owner, string message, string detailText, MessageDialogButtons button, MessageDialogIcon icon, string appConfigSetting);

	DialogResult ShowWithCheckBox(string caption, string message, string detailText, MessageDialogButtons button, MessageDialogIcon icon, string appConfigSetting);
}
public class MessageDialogComponent : IMessageDialog
{
	private static MessageDialogComponent caltermMessageDialog;

	private static object syncObj = new object();

	public static MessageDialogComponent CaltermMessageDialog
	{
		get
		{
			if (caltermMessageDialog == null)
			{
				lock (syncObj)
				{
					if (caltermMessageDialog == null)
					{
						caltermMessageDialog = new MessageDialogComponent();
					}
				}
			}
			return caltermMessageDialog;
		}
	}

	private MessageDialogComponent()
	{
	}

	public DialogResult Show(string message, MessageDialogButtons button, MessageDialogIcon icon)
	{
		//IL_000a: Unknown result type (might be due to invalid IL or missing references)
		MessageDialog messageDialog = new MessageDialog();
		return messageDialog.Show(message, button, icon);
	}

	public DialogResult Show(IWin32Window owner, string message, MessageDialogButtons button, MessageDialogIcon icon)
	{
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		MessageDialog messageDialog = new MessageDialog();
		return messageDialog.Show(owner, message, button, icon);
	}

	public DialogResult Show(IWin32Window owner, string message, string detailText, MessageDialogButtons button, MessageDialogIcon icon)
	{
		//IL_000e: Unknown result type (might be due to invalid IL or missing references)
		MessageDialog messageDialog = new MessageDialog();
		return messageDialog.Show(owner, message, detailText, button, icon);
	}

	public DialogResult Show(string message, string detailText, MessageDialogButtons button, MessageDialogIcon icon)
	{
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		MessageDialog messageDialog = new MessageDialog();
		return messageDialog.Show(message, detailText, button, icon);
	}

	public DialogResult Show(string caption, string message, string detailText, MessageDialogButtons button, MessageDialogIcon icon)
	{
		//IL_0014: Unknown result type (might be due to invalid IL or missing references)
		MessageDialog messageDialog = new MessageDialog();
		((Control)messageDialog).Text = caption;
		return messageDialog.Show(message, detailText, button, icon);
	}

	public DialogResult Show(string caption, string message, string detailText, string errorCode, MessageDialogButtons button, MessageDialogIcon icon)
	{
		//IL_000f: Unknown result type (might be due to invalid IL or missing references)
		MessageDialog messageDialog = new MessageDialog();
		return messageDialog.Show(message, detailText, errorCode, button, icon);
	}

	public DialogResult ShowWithCheckBox(string message, MessageDialogButtons button, MessageDialogIcon icon, string appConfigSetting)
	{
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		CheckBoxMessageDialog checkBoxMessageDialog = new CheckBoxMessageDialog();
		return checkBoxMessageDialog.Show(message, button, icon, appConfigSetting);
	}

	public DialogResult ShowWithCheckBox(IWin32Window owner, string message, MessageDialogButtons button, MessageDialogIcon icon, string appConfigSetting)
	{
		//IL_000e: Unknown result type (might be due to invalid IL or missing references)
		CheckBoxMessageDialog checkBoxMessageDialog = new CheckBoxMessageDialog();
		return checkBoxMessageDialog.Show(owner, message, button, icon, appConfigSetting);
	}

	public DialogResult ShowWithCheckBox(IWin32Window owner, string message, string detailText, MessageDialogButtons button, MessageDialogIcon icon, string appConfigSetting)
	{
		//IL_0010: Unknown result type (might be due to invalid IL or missing references)
		CheckBoxMessageDialog checkBoxMessageDialog = new CheckBoxMessageDialog();
		return checkBoxMessageDialog.Show(owner, message, detailText, button, icon, appConfigSetting);
	}

	public DialogResult ShowWithCheckBox(string message, string detailText, MessageDialogButtons button, MessageDialogIcon icon, string appConfigSetting)
	{
		//IL_000e: Unknown result type (might be due to invalid IL or missing references)
		CheckBoxMessageDialog checkBoxMessageDialog = new CheckBoxMessageDialog();
		return checkBoxMessageDialog.Show(message, detailText, button, icon, appConfigSetting);
	}

	public DialogResult ShowWithCheckBox(string caption, string message, string detailText, MessageDialogButtons button, MessageDialogIcon icon, string appConfigSetting)
	{
		//IL_0016: Unknown result type (might be due to invalid IL or missing references)
		CheckBoxMessageDialog checkBoxMessageDialog = new CheckBoxMessageDialog();
		((Control)checkBoxMessageDialog).Text = caption;
		return checkBoxMessageDialog.Show(message, detailText, button, icon, appConfigSetting);
	}
}
public enum MsgBoxResult
{
	OK,
	Cancel,
	Yes,
	No,
	None,
	Retry
}
public enum MsgBoxIcon
{
	Stop,
	Error,
	Information,
	Question,
	Warning,
	Exclamation
}
public enum MsgBoxButtons
{
	OK,
	OKCancel,
	YesNo,
	YesNoCancel,
	YesNoRetry
}
public enum MessageDialogIcon
{
	Stop,
	Error,
	Information,
	Question,
	Warning
}
public enum MessageDialogButtons
{
	OK,
	OKCancel,
	YesNo
}
public class MsgBox : Form
{
	private delegate MsgBoxResult MsgBoxShowDelegate(string message, string caption, string details, MsgBoxButtons buttons, MsgBoxIcon icon);

	internal const string ExceptionMessage = "Either the CHM file or database file is missing";

	private TextBox detailTextBox;

	private IContainer components;

	private RichTextBox generalTextBox;

	private PictureBox iconPictureBox;

	private Panel paButtons;

	private Button btn2;

	private Button btn1;

	private Button btn0;

	private Button btnDetails;

	private LinkLabel linkLabelTroubleshoot;

	private ImageList imageList1;

	private static string errorCode;

	private static string ErrorCodeMessageFormat = "ErrorCode: {0} - ";

	private static bool enableTroubleShootLink;

	private bool isDetailShown = true;

	public static bool AreAlertsDisabled
	{
		get
		{
			bool result = false;
			string setting = AppSettingHelper.GetSetting(ApplicationSettings.DisableAlertsChecked);
			if (setting != null && setting.Length > 0)
			{
				try
				{
					result = bool.Parse(setting);
				}
				catch
				{
				}
			}
			return result;
		}
	}

	public static MsgBoxResult Show(string message)
	{
		return Show(message, "", "", MsgBoxButtons.OK, MsgBoxIcon.Information);
	}

	public static MsgBoxResult Show(string message, MsgBoxIcon icon)
	{
		return Show(message, "", "", MsgBoxButtons.OK, icon);
	}

	public static MsgBoxResult Show(string message, MsgBoxButtons buttons, MsgBoxIcon icon)
	{
		return Show(message, "", "", buttons, icon);
	}

	public static MsgBoxResult Show(string message, string caption, MsgBoxButtons buttons, MsgBoxIcon icon)
	{
		return Show(message, caption, "", buttons, icon);
	}

	public static MsgBoxResult Show(ErrorSources errorSource, ushort errorID, string detailedText, MsgBoxButtons buttons, MsgBoxIcon icon, params object[] paramValues)
	{
		errorCode = ErrorHelper.GetErrorCode(errorSource, errorID);
		string errorHeadline = Cummins.ErrorDataRepository.ErrorDataRepository.Instance.GetErrorHeadline(errorCode);
		string text = string.Format(ErrorCodeMessageFormat, errorCode);
		errorHeadline = text + errorHeadline;
		if (paramValues.Length > 0)
		{
			errorHeadline = string.Format(errorHeadline, paramValues);
		}
		enableTroubleShootLink = Cummins.ErrorDataRepository.ErrorDataRepository.Instance.IsErrorIdPresent(errorCode);
		return Show(errorHeadline, errorSource.ToString(), detailedText, buttons, icon);
	}

	public static MsgBoxResult Show(ErrorSources errorSource, ushort errorID, string detailedText, string customMessage, MsgBoxButtons buttons, MsgBoxIcon icon, params object[] paramValues)
	{
		errorCode = ErrorHelper.GetErrorCode(errorSource, errorID);
		string errorHeadline = Cummins.ErrorDataRepository.ErrorDataRepository.Instance.GetErrorHeadline(errorCode);
		string text = string.Format(ErrorCodeMessageFormat, errorCode);
		errorHeadline = customMessage + text + errorHeadline;
		if (paramValues.Length > 0)
		{
			errorHeadline = string.Format(errorHeadline, paramValues);
		}
		enableTroubleShootLink = Cummins.ErrorDataRepository.ErrorDataRepository.Instance.IsErrorIdPresent(errorCode);
		return Show(errorHeadline, errorSource.ToString(), detailedText, buttons, icon);
	}

	public static MsgBoxResult Show(string message, string caption, string details, MsgBoxButtons buttons, MsgBoxIcon icon)
	{
		//IL_0193: Unknown result type (might be due to invalid IL or missing references)
		//IL_019d: Expected O, but got Unknown
		//IL_01a3: Unknown result type (might be due to invalid IL or missing references)
		//IL_01a8: Unknown result type (might be due to invalid IL or missing references)
		//IL_01b3: Unknown result type (might be due to invalid IL or missing references)
		if (ApplicationInfo.MainApplicationForm == null || !((Control)ApplicationInfo.MainApplicationForm).InvokeRequired)
		{
			if (AreAlertsDisabled)
			{
				return (buttons != MsgBoxButtons.OK && buttons != MsgBoxButtons.OKCancel) ? MsgBoxResult.Yes : MsgBoxResult.OK;
			}
			MsgBox msgBox = new MsgBox();
			((Control)msgBox).Text = ((caption == "") ? ("Calterm III - " + icon) : ("Calterm III - " + caption));
			if (details.Length > 0)
			{
				((Control)msgBox.btnDetails).Visible = true;
				((Control)msgBox.detailTextBox).Text = details;
				message += "\r\n\r\nPlease click on Details>> for more information.";
			}
			((Control)msgBox.generalTextBox).Text = message;
			((Control)msgBox.linkLabelTroubleshoot).Visible = enableTroubleShootLink;
			enableTroubleShootLink = false;
			msgBox.AdjustFormSize();
			switch (buttons)
			{
			case MsgBoxButtons.OK:
				SetButton(msgBox.btn0, MsgBoxResult.OK);
				break;
			case MsgBoxButtons.OKCancel:
				SetButton(msgBox.btn0, MsgBoxResult.OK);
				SetButton(msgBox.btn1, MsgBoxResult.Cancel);
				break;
			case MsgBoxButtons.YesNo:
				SetButton(msgBox.btn0, MsgBoxResult.Yes);
				SetButton(msgBox.btn1, MsgBoxResult.No);
				break;
			case MsgBoxButtons.YesNoCancel:
				SetButton(msgBox.btn0, MsgBoxResult.Yes);
				SetButton(msgBox.btn1, MsgBoxResult.No);
				SetButton(msgBox.btn2, MsgBoxResult.Cancel);
				break;
			case MsgBoxButtons.YesNoRetry:
				SetButton(msgBox.btn0, MsgBoxResult.Yes);
				SetButton(msgBox.btn1, MsgBoxResult.No);
				SetButton(msgBox.btn2, MsgBoxResult.Retry);
				break;
			}
			msgBox.iconPictureBox.Image = (Image)new Bitmap(((object)msgBox).GetType(), "icons." + icon.ToString() + ".gif");
			DialogResult val = ((Form)msgBox).ShowDialog((IWin32Window)(object)ApplicationInfo.MainApplicationForm);
			return (MsgBoxResult)Enum.Parse(typeof(MsgBoxResult), ((object)val).ToString());
		}
		MsgBoxShowDelegate msgBoxShowDelegate = Show;
		return (MsgBoxResult)((Control)ApplicationInfo.MainApplicationForm).Invoke((Delegate)msgBoxShowDelegate, new object[5] { message, caption, details, buttons, icon });
	}

	private static void SetButton(Button button, MsgBoxResult result)
	{
		((Control)button).Text = result.ToString();
		((Control)button).Visible = true;
	}

	private void AdjustFormSize()
	{
		int height = ((Control)generalTextBox).Height;
		int num = 20;
		int num2 = 69;
		int num3 = ((TextBoxBase)generalTextBox).Lines.Length + 1;
		string[] lines = ((TextBoxBase)generalTextBox).Lines;
		foreach (string text in lines)
		{
			num3 += text.Length / num2;
		}
		int num4 = 5;
		if (num3 > num)
		{
			((Control)generalTextBox).Height = num4 + num * ((Control)generalTextBox).Font.Height;
			generalTextBox.ScrollBars = (RichTextBoxScrollBars)2;
		}
		else
		{
			((Control)generalTextBox).Height = num4 + num3 * ((Control)generalTextBox).Font.Height;
			generalTextBox.ScrollBars = (RichTextBoxScrollBars)0;
		}
		int num5 = ((Control)generalTextBox).Height - height;
		((Control)this).Height = ((Control)this).Height + num5;
		Button obj = btn0;
		((Control)obj).Top = ((Control)obj).Top + num5;
		Button obj2 = btn1;
		((Control)obj2).Top = ((Control)obj2).Top + num5;
		Button obj3 = btn2;
		((Control)obj3).Top = ((Control)obj3).Top + num5;
		Button obj4 = btnDetails;
		((Control)obj4).Top = ((Control)obj4).Top + num5;
		LinkLabel obj5 = linkLabelTroubleshoot;
		((Control)obj5).Top = ((Control)obj5).Top + num5;
	}

	private void MsgBox_Load(object sender, EventArgs e)
	{
		ToggleDetails();
	}

	private void generalTextBox_TextChanged(object sender, EventArgs e)
	{
		AdjustFormSize();
	}

	private void btn_Click(object sender, EventArgs e)
	{
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		//IL_001b: Unknown result type (might be due to invalid IL or missing references)
		((Form)this).DialogResult = (DialogResult)Enum.Parse(typeof(DialogResult), ((Control)(Button)sender).Text);
		((Component)this).Dispose();
	}

	private void btnDetails_Click(object sender, EventArgs e)
	{
		ToggleDetails();
	}

	private void ToggleDetails()
	{
		int num = 5;
		int num2 = ((Control)detailTextBox).Height + num;
		((Control)this).Height = ((Control)this).Height + (isDetailShown ? (-num2) : num2);
		isDetailShown = !isDetailShown;
		((ButtonBase)btnDetails).ImageIndex = (isDetailShown ? 1 : 0);
		((Control)detailTextBox).Visible = isDetailShown;
	}

	public MsgBox()
	{
		InitializeComponent();
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
		//IL_0022: Unknown result type (might be due to invalid IL or missing references)
		//IL_002c: Expected O, but got Unknown
		//IL_002d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0037: Expected O, but got Unknown
		//IL_0038: Unknown result type (might be due to invalid IL or missing references)
		//IL_0042: Expected O, but got Unknown
		//IL_0043: Unknown result type (might be due to invalid IL or missing references)
		//IL_004d: Expected O, but got Unknown
		//IL_004e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0058: Expected O, but got Unknown
		//IL_0059: Unknown result type (might be due to invalid IL or missing references)
		//IL_0063: Expected O, but got Unknown
		//IL_0064: Unknown result type (might be due to invalid IL or missing references)
		//IL_006e: Expected O, but got Unknown
		//IL_006f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0079: Expected O, but got Unknown
		//IL_007a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0084: Expected O, but got Unknown
		//IL_0085: Unknown result type (might be due to invalid IL or missing references)
		//IL_008f: Expected O, but got Unknown
		//IL_00b1: Unknown result type (might be due to invalid IL or missing references)
		//IL_00bb: Expected O, but got Unknown
		//IL_0236: Unknown result type (might be due to invalid IL or missing references)
		//IL_0240: Expected O, but got Unknown
		//IL_02f0: Unknown result type (might be due to invalid IL or missing references)
		//IL_02fa: Expected O, but got Unknown
		//IL_038a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0394: Expected O, but got Unknown
		//IL_0424: Unknown result type (might be due to invalid IL or missing references)
		//IL_042e: Expected O, but got Unknown
		//IL_04be: Unknown result type (might be due to invalid IL or missing references)
		//IL_04c8: Expected O, but got Unknown
		//IL_0581: Unknown result type (might be due to invalid IL or missing references)
		//IL_0619: Unknown result type (might be due to invalid IL or missing references)
		//IL_0623: Expected O, but got Unknown
		//IL_06e1: Unknown result type (might be due to invalid IL or missing references)
		//IL_06eb: Expected O, but got Unknown
		components = new Container();
		ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(MsgBox));
		imageList1 = new ImageList(components);
		detailTextBox = new TextBox();
		generalTextBox = new RichTextBox();
		iconPictureBox = new PictureBox();
		paButtons = new Panel();
		btn2 = new Button();
		btn1 = new Button();
		btn0 = new Button();
		btnDetails = new Button();
		linkLabelTroubleshoot = new LinkLabel();
		((ISupportInitialize)iconPictureBox).BeginInit();
		((Control)this).SuspendLayout();
		imageList1.ImageStream = (ImageListStreamer)componentResourceManager.GetObject("imageList1.ImageStream");
		imageList1.TransparentColor = Color.Transparent;
		imageList1.Images.SetKeyName(0, "");
		imageList1.Images.SetKeyName(1, "");
		((Control)detailTextBox).BackColor = SystemColors.Info;
		((Control)detailTextBox).Dock = (DockStyle)2;
		((Control)detailTextBox).Location = new Point(0, 195);
		((TextBoxBase)detailTextBox).Multiline = true;
		((Control)detailTextBox).Name = "detailTextBox";
		((TextBoxBase)detailTextBox).ReadOnly = true;
		detailTextBox.ScrollBars = (ScrollBars)2;
		((Control)detailTextBox).Size = new Size(498, 137);
		((Control)detailTextBox).TabIndex = 6;
		((Control)detailTextBox).Visible = false;
		((TextBoxBase)generalTextBox).BorderStyle = (BorderStyle)0;
		((TextBoxBase)generalTextBox).HideSelection = false;
		((Control)generalTextBox).Location = new Point(64, 16);
		((TextBoxBase)generalTextBox).Multiline = true;
		((Control)generalTextBox).Name = "generalTextBox";
		((TextBoxBase)generalTextBox).ReadOnly = true;
		((Control)generalTextBox).Size = new Size(424, 110);
		((Control)generalTextBox).TabIndex = 0;
		((Control)generalTextBox).TabStop = false;
		((Control)generalTextBox).TextChanged += generalTextBox_TextChanged;
		generalTextBox.LinkClicked += new LinkClickedEventHandler(OngeneralTextboxlinkLabelClicked);
		((Control)iconPictureBox).Location = new Point(8, 16);
		((Control)iconPictureBox).Name = "iconPictureBox";
		((Control)iconPictureBox).Size = new Size(48, 50);
		iconPictureBox.TabIndex = 7;
		iconPictureBox.TabStop = false;
		((Control)paButtons).Location = new Point(176, 136);
		((Control)paButtons).Name = "paButtons";
		((Control)paButtons).Size = new Size(200, 48);
		((Control)paButtons).TabIndex = 14;
		((Control)btn2).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)btn2).Location = new Point(392, 160);
		((Control)btn2).Name = "btn2";
		((Control)btn2).Size = new Size(88, 26);
		((Control)btn2).TabIndex = 5;
		((Control)btn2).Text = "button 2";
		((Control)btn2).Visible = false;
		((Control)btn2).Click += btn_Click;
		((Control)btn1).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)btn1).Location = new Point(288, 160);
		((Control)btn1).Name = "btn1";
		((Control)btn1).Size = new Size(88, 26);
		((Control)btn1).TabIndex = 4;
		((Control)btn1).Text = "button 1";
		((Control)btn1).Visible = false;
		((Control)btn1).Click += btn_Click;
		((Control)btn0).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)btn0).Location = new Point(184, 160);
		((Control)btn0).Name = "btn0";
		((Control)btn0).Size = new Size(88, 26);
		((Control)btn0).TabIndex = 3;
		((Control)btn0).Text = "button 0";
		((Control)btn0).Visible = false;
		((Control)btn0).Click += btn_Click;
		((Control)btnDetails).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((ButtonBase)btnDetails).ImageAlign = (ContentAlignment)16;
		((ButtonBase)btnDetails).ImageIndex = 0;
		((ButtonBase)btnDetails).ImageList = imageList1;
		((Control)btnDetails).Location = new Point(80, 160);
		((Control)btnDetails).Name = "btnDetails";
		((Control)btnDetails).Size = new Size(88, 26);
		((Control)btnDetails).TabIndex = 2;
		((Control)btnDetails).Text = "Details";
		((Control)btnDetails).Visible = false;
		((Control)btnDetails).Click += btnDetails_Click;
		((Control)linkLabelTroubleshoot).AutoSize = true;
		linkLabelTroubleshoot.LinkArea = new LinkArea(13, 4);
		((Control)linkLabelTroubleshoot).Location = new Point(168, 134);
		((Control)linkLabelTroubleshoot).Name = "linkLabelTroubleshoot";
		((Control)linkLabelTroubleshoot).Size = new Size(320, 17);
		((Control)linkLabelTroubleshoot).TabIndex = 1;
		linkLabelTroubleshoot.TabStop = true;
		((Control)linkLabelTroubleshoot).Text = "Please click here for more information and troubleshooting tips.";
		linkLabelTroubleshoot.UseCompatibleTextRendering = true;
		((Control)linkLabelTroubleshoot).Visible = false;
		linkLabelTroubleshoot.LinkClicked += new LinkLabelLinkClickedEventHandler(OnlinkLabelTroubleshootClicked);
		((Form)this).AutoScaleBaseSize = new Size(5, 13);
		((Form)this).ClientSize = new Size(498, 332);
		((Control)this).Controls.Add((Control)(object)linkLabelTroubleshoot);
		((Control)this).Controls.Add((Control)(object)btn2);
		((Control)this).Controls.Add((Control)(object)detailTextBox);
		((Control)this).Controls.Add((Control)(object)generalTextBox);
		((Control)this).Controls.Add((Control)(object)btn1);
		((Control)this).Controls.Add((Control)(object)btn0);
		((Control)this).Controls.Add((Control)(object)btnDetails);
		((Control)this).Controls.Add((Control)(object)iconPictureBox);
		((Form)this).FormBorderStyle = (FormBorderStyle)3;
		((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
		((Form)this).MaximizeBox = false;
		((Form)this).MinimizeBox = false;
		((Control)this).Name = "MsgBox";
		((Form)this).ShowInTaskbar = false;
		((Form)this).TopMost = true;
		((Form)this).StartPosition = (FormStartPosition)1;
		((Control)this).Text = "Calterm III Message";
		((Form)this).Load += MsgBox_Load;
		((ISupportInitialize)iconPictureBox).EndInit();
		((Control)this).ResumeLayout(false);
		((Control)this).PerformLayout();
	}

	private void OnlinkLabelTroubleshootClicked(object sender, LinkLabelLinkClickedEventArgs e)
	{
		try
		{
			Cummins.ErrorDataRepositoryViewer.ErrorDataRepositoryViewer.Instance.ShowErrorInformation(errorCode);
		}
		catch
		{
			Show("Either the CHM file or database file is missing");
		}
	}

	private void OngeneralTextboxlinkLabelClicked(object sender, LinkClickedEventArgs e)
	{
		try
		{
			ProcessStartInfo startInfo = new ProcessStartInfo(e.LinkText.ToString());
			Process.Start(startInfo);
		}
		catch (Exception ex)
		{
			Show("Error in opening link path", "Link Error", ex.ToString(), MsgBoxButtons.OK, MsgBoxIcon.Error);
		}
	}
}
