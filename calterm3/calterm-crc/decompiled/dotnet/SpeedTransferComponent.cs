using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using System.Text.RegularExpressions;
using System.Threading;
using System.Windows.Forms;
using System.Xml;
using System.Xml.XPath;
using System.Xml.Xsl;
using CRC;
using Cummins.ApplicationServices;
using Cummins.EventLog;
using Cummins.Launcher;
using Cummins.Services;
using Cummins.Widgets;
using ICSharpCode.SharpZipLib.Zip;

[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTitle("Poodle")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - SPEED Transfer Component")]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.SpeedTransferComponent;

public class DirectoryBrowser
{
	public static string Browse(string selectedPath)
	{
		//IL_0000: Unknown result type (might be due to invalid IL or missing references)
		//IL_0006: Expected O, but got Unknown
		//IL_0016: Unknown result type (might be due to invalid IL or missing references)
		//IL_001c: Invalid comparison between Unknown and I4
		FolderBrowserDialog val = new FolderBrowserDialog();
		val.RootFolder = Environment.SpecialFolder.MyComputer;
		val.SelectedPath = selectedPath;
		if ((int)((CommonDialog)val).ShowDialog() == 1)
		{
			return val.SelectedPath;
		}
		return "";
	}
}
public class DownloadFileInformation
{
	internal static int PartNumberStart = 1;

	internal static int PartNumberLength = 7;

	internal static int RevisionLevelStart = 12;

	internal static int RevisionLevelLength = 3;

	internal static int ReleaseNumberStart = 15;

	internal static int ReleaseNumberLength = 10;

	internal static int ReleasePhaseIndex = 25;

	internal static int ReleaseDateStart = 27;

	internal static int ReleaseDateLength = 5;

	internal static int ProductIDStart = 32;

	internal static int ProductIDLength = 3;

	internal static int DistributionGroupStart = 41;

	internal static int DistributionGroupLength = 3;

	internal static int MinLineLength = 255;

	internal static char SemiColon = ';';

	internal static string InvalidControlFile = "Invalid Control File";

	internal static string E2MExtension = "e2m";

	internal static string ECFGExtension = "ecfg";

	internal static string CalFolder = "Cal";

	internal static string UnreleaseCalFolder = "Unrlcal";

	internal static string DescpFolder = "Descp";

	private string partNumber;

	private short revisionLevel;

	private string releaseNumber;

	private ReleasePhase releasePhase;

	private string releaseDate;

	private string productID;

	private FileType fileType;

	private string distributionGroup;

	private string speedFileName;

	private string localFileName;

	private string filePathToExtract;

	private string extractedFileName;

	public string PartNumber => partNumber;

	public short RevisionLevel => revisionLevel;

	public string ReleaseNumber => releaseNumber;

	public ReleasePhase ReleasePhase => releasePhase;

	public string ReleaseDate => releaseDate;

	public string ProductID => productID;

	public FileType FileType
	{
		get
		{
			return fileType;
		}
		set
		{
			fileType = value;
		}
	}

	public string DistributionGroup => distributionGroup;

	public string SpeedFileName => speedFileName;

	public string LocalFileName => localFileName;

	public string FilePathToExtract => LocalFileName.Substring(0, LocalFileName.LastIndexOf("\\") + 1);

	public string ExtractedFileName
	{
		get
		{
			return extractedFileName;
		}
		set
		{
			extractedFileName = value;
		}
	}

	public DownloadFileInformation(string record, string localDownloadPath)
	{
		if (record == null)
		{
			throw new ArgumentNullException("business header record");
		}
		if (localDownloadPath == null || localDownloadPath.Length == 0)
		{
			throw new ArgumentNullException("LocalDownloadPath");
		}
		if (record.Length < MinLineLength)
		{
			throw InvalidRecordException.New(MessageIDs.InvalidRecordLength, "Invalid business header record : Length < 255 characters ", record);
		}
		partNumber = GetPartNumber(record, PartNumberStart);
		revisionLevel = short.Parse(record.Substring(RevisionLevelStart, RevisionLevelLength));
		releaseNumber = record.Substring(ReleaseNumberStart, ReleaseNumberLength);
		releasePhase = GetReleasePhaseFromCode(record[ReleasePhaseIndex]);
		releaseDate = record.Substring(ReleaseDateStart, ReleaseDateLength);
		productID = record.Substring(ProductIDStart, ProductIDLength);
		distributionGroup = record.Substring(DistributionGroupStart, DistributionGroupLength);
		int num = record.IndexOf(SemiColon);
		if (num == -1)
		{
			throw InvalidRecordException.New(MessageIDs.LocalFilenameSectionMissing, "Invalid record :  Local file name section not found!", record);
		}
		int num2 = record.IndexOf(SemiColon, num + 1);
		if (num2 == -1)
		{
			throw InvalidRecordException.New(MessageIDs.SpeedFilenameSectionMissing, "Invalid  record :  SPEED file name with full path information not found!", record);
		}
		speedFileName = record.Substring(num2 + 1);
		string fileName = speedFileName.Substring(speedFileName.LastIndexOf("\\") + 1);
		SetLocalFileName(fileName, localDownloadPath);
	}

	public FileType GetFileTypeFromCode(char code, string fileName)
	{
		FileType result = FileType.Other;
		switch (code)
		{
		case 'A':
			result = FileType.Calibration;
			break;
		case 'B':
			result = FileType.Subfile;
			break;
		case 'C':
			result = FileType.ControlFile;
			break;
		case 'E':
			if (fileName.ToLower().EndsWith(E2MExtension))
			{
				result = FileType.E2MFile;
			}
			else if (fileName.ToLower().EndsWith(ECFGExtension))
			{
				result = FileType.ECFGFile;
			}
			break;
		case 'F':
			result = FileType.RIOFile;
			break;
		case 'H':
			result = FileType.HDRFile;
			break;
		case 'I':
			result = FileType.SPEEDFile;
			break;
		case 'L':
			result = FileType.BOTFile;
			break;
		case 'V':
			result = FileType.NVDFile;
			break;
		case 'P':
			result = FileType.PCFGFile;
			break;
		}
		return result;
	}

	public static string GetPartNumber(string record, int partNumberStart)
	{
		string text = null;
		if (string.IsNullOrEmpty(record) || record.Length <= 9)
		{
			Exception ex = new Exception("record length is invalid");
			throw ex;
		}
		char c = record[partNumberStart];
		if (char.IsDigit(c))
		{
			return record.Substring(partNumberStart, 7);
		}
		return record.Substring(partNumberStart, 8);
	}

	private ReleasePhase GetReleasePhaseFromCode(char phase)
	{
		return phase switch
		{
			'E' => ReleasePhase.EPhase, 
			'D' => ReleasePhase.DPhase, 
			'L' => ReleasePhase.LPhase, 
			'P' => ReleasePhase.PPhase, 
			'O' => ReleasePhase.Obsolete, 
			_ => ReleasePhase.Invalid, 
		};
	}

	private void SetLocalFileName(string fileName, string path)
	{
		if (fileName == null)
		{
			throw new ArgumentNullException("file name");
		}
		if (path == null)
		{
			throw new ArgumentNullException("file path");
		}
		localFileName = path;
		if (!localFileName.EndsWith("\\"))
		{
			localFileName += "\\";
		}
		if (releasePhase == ReleasePhase.Obsolete)
		{
			localFileName = localFileName + UnreleaseCalFolder + "\\";
		}
		else if (fileType == FileType.Calibration || fileType == FileType.Subfile)
		{
			localFileName = localFileName + CalFolder + "\\";
		}
		else
		{
			localFileName = localFileName + DescpFolder + "\\";
		}
		if (fileName.Length != 0)
		{
			localFileName += fileName;
			return;
		}
		int num = speedFileName.LastIndexOf('\\');
		if (num == -1)
		{
			throw InvalidRecordException.New(MessageIDs.SpeedFilePathMissing, "Invalid record : Speed File name is not in the correct format", speedFileName);
		}
		localFileName += speedFileName.Substring(num + 1);
	}
}
public enum ColumnType
{
	TextBox,
	ComboBox,
	Time,
	Date,
	UserControl
}
public class EJRColumnStyle : DataGridColumnStyle
{
	private bool isEditing;

	private Control host;

	private ColumnType columnType;

	private EJRTextBox ejrTextBox;

	private EJRControl ejrControl;

	public Control Control => host;

	public ColumnType ColumnType
	{
		get
		{
			return columnType;
		}
		set
		{
			if (Control == null)
			{
				columnType = value;
				CreateControl();
			}
			else if (columnType != value)
			{
				columnType = value;
				CreateControl();
				Control.Visible = false;
				if (((DataGridColumnStyle)this).DataGridTableStyle != null && ((DataGridColumnStyle)this).DataGridTableStyle.DataGrid != null)
				{
					((DataGridColumnStyle)this).SetDataGridInColumn(((DataGridColumnStyle)this).DataGridTableStyle.DataGrid);
				}
			}
		}
	}

	public string InputMask
	{
		get
		{
			if (columnType == ColumnType.TextBox)
			{
				return ejrTextBox.InputMask;
			}
			return "null";
		}
		set
		{
			if (columnType == ColumnType.TextBox)
			{
				ejrTextBox.InputMask = value;
			}
		}
	}

	public char InputChar
	{
		get
		{
			if (columnType == ColumnType.TextBox)
			{
				return ejrTextBox.InputChar;
			}
			return '*';
		}
		set
		{
			if (columnType == ColumnType.TextBox)
			{
				ejrTextBox.InputChar = value;
			}
		}
	}

	public int MaxLength
	{
		get
		{
			if (columnType == ColumnType.TextBox)
			{
				return ((TextBoxBase)ejrTextBox).MaxLength;
			}
			return 0;
		}
		set
		{
			if (columnType == ColumnType.TextBox)
			{
				((TextBoxBase)ejrTextBox).MaxLength = value;
			}
		}
	}

	public EJRColumnStyle(ColumnType columnType)
	{
		this.columnType = columnType;
		CreateControl();
		Control.Visible = false;
	}

	protected override void Abort(int rowNum)
	{
		isEditing = false;
		Control.TextChanged -= EditTextChanged;
		((DataGridColumnStyle)this).Invalidate();
	}

	protected override bool Commit(CurrencyManager dataSource, int rowNum)
	{
		bool result = true;
		Control.Bounds = Rectangle.Empty;
		Control.TextChanged -= EditTextChanged;
		if (isEditing)
		{
			isEditing = false;
			try
			{
				if (columnType == ColumnType.UserControl && ejrControl != null)
				{
					Control.Text = ejrControl.EJRNumber;
				}
				string text = Control.Text;
				((DataGridColumnStyle)this).SetColumnValueAtRow(dataSource, rowNum, (object)text);
			}
			catch (Exception)
			{
				((DataGridColumnStyle)this).Abort(rowNum);
				result = false;
			}
			((DataGridColumnStyle)this).Invalidate();
		}
		return result;
	}

	protected override void Edit(CurrencyManager source, int rowNum, Rectangle bounds, bool readOnly, string instantText, bool cellIsVisible)
	{
		object obj = null;
		try
		{
			obj = ((DataGridColumnStyle)this).GetColumnValueAtRow(source, rowNum);
		}
		catch
		{
		}
		string text = "";
		if (obj != DBNull.Value)
		{
			text = (string)obj;
		}
		else if (ColumnType == ColumnType.Time)
		{
			text = DateTime.Now.ToShortTimeString();
		}
		else if (ColumnType == ColumnType.Date)
		{
			text = DateTime.Now.ToShortDateString();
		}
		if (cellIsVisible)
		{
			Control.Bounds = new Rectangle(bounds.X + 2, bounds.Y + 2, bounds.Width - 4, bounds.Height - 4);
			if (Control is DateTimePicker)
			{
				Control control = Control;
				((DateTimePicker)((control is DateTimePicker) ? control : null)).Value = Convert.ToDateTime(text);
			}
			else
			{
				Control.Text = text;
			}
			Control.Visible = true;
			Control.TextChanged += EditTextChanged;
			if (ejrControl != null)
			{
				EJRControl eJRControl = ejrControl;
				eJRControl.onEJRTextBoxUpdate = (EventHandler)Delegate.Combine(eJRControl.onEJRTextBoxUpdate, new EventHandler(EditTextChanged));
				EJRTextBoxEventArgs e = new EJRTextBoxEventArgs(text);
				ejrControl.OnEJRTextChanged(this, e);
			}
		}
		else
		{
			if (Control is DateTimePicker)
			{
				Control control2 = Control;
				((DateTimePicker)((control2 is DateTimePicker) ? control2 : null)).Value = Convert.ToDateTime(text);
			}
			else
			{
				Control.Text = text;
			}
			Control.Visible = false;
		}
		if (Control.Visible)
		{
			((Control)((DataGridColumnStyle)this).DataGridTableStyle.DataGrid).Invalidate(bounds);
			if (ejrControl != null)
			{
				((Control)ejrControl).Focus();
			}
			else if (ejrTextBox != null)
			{
				((Control)ejrTextBox).Focus();
				((TextBoxBase)ejrTextBox).SelectionStart = 0;
				((TextBoxBase)ejrTextBox).SelectionLength = 1;
			}
		}
	}

	protected override Size GetPreferredSize(Graphics g, object value)
	{
		return new Size(100, Control.Height + 2);
	}

	protected override int GetMinimumHeight()
	{
		return Control.Height + 2;
	}

	protected override int GetPreferredHeight(Graphics g, object value)
	{
		return Control.Height + 2;
	}

	protected override void Paint(Graphics g, Rectangle bounds, CurrencyManager source, int rowNum)
	{
		((DataGridColumnStyle)this).Paint(g, bounds, source, rowNum, false);
	}

	protected override void Paint(Graphics g, Rectangle bounds, CurrencyManager source, int rowNum, bool alignToRight)
	{
		((DataGridColumnStyle)this).Paint(g, bounds, source, rowNum, Brushes.Red, Brushes.Blue, alignToRight);
	}

	protected override void Paint(Graphics g, Rectangle bounds, CurrencyManager source, int rowNum, Brush backBrush, Brush foreBrush, bool alignToRight)
	{
		object obj = null;
		try
		{
			obj = ((DataGridColumnStyle)this).GetColumnValueAtRow(source, rowNum);
		}
		catch
		{
		}
		string text = "";
		if (obj != DBNull.Value)
		{
			text = (string)obj;
		}
		else if (ColumnType == ColumnType.Time)
		{
			text = DateTime.Now.ToShortTimeString();
		}
		else if (ColumnType == ColumnType.Date)
		{
			text = DateTime.Now.ToShortDateString();
		}
		Rectangle rectangle = bounds;
		g.FillRectangle(backBrush, rectangle);
		rectangle.Offset(0, 2);
		rectangle.Height -= 2;
		g.DrawString(text, ((Control)((DataGridColumnStyle)this).DataGridTableStyle.DataGrid).Font, foreBrush, (RectangleF)rectangle);
	}

	protected override void SetDataGridInColumn(DataGrid value)
	{
		((DataGridColumnStyle)this).SetDataGridInColumn(value);
		if (Control.Parent != null)
		{
			Control.Parent.Controls.Remove(Control);
		}
		if (value != null)
		{
			((Control)value).Controls.Add(Control);
		}
	}

	private void TimePickerValueChanged(object sender, EventArgs e)
	{
		isEditing = true;
		((DataGridColumnStyle)this).ColumnStartedEditing((Control)((sender is Control) ? sender : null));
	}

	private void EditTextChanged(object sender, EventArgs e)
	{
		isEditing = true;
		((DataGridColumnStyle)this).ColumnStartedEditing((Control)((sender is Control) ? sender : null));
	}

	private void CreateControl()
	{
		//IL_0023: Unknown result type (might be due to invalid IL or missing references)
		//IL_002d: Expected O, but got Unknown
		//IL_002f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0039: Expected O, but got Unknown
		//IL_005d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0067: Expected O, but got Unknown
		switch (columnType)
		{
		case ColumnType.ComboBox:
			host = (Control)new ComboBox();
			break;
		case ColumnType.Time:
		{
			host = (Control)new DateTimePicker();
			Control obj = host;
			((DateTimePicker)((obj is DateTimePicker) ? obj : null)).Format = (DateTimePickerFormat)4;
			Control obj2 = host;
			((DateTimePicker)((obj2 is DateTimePicker) ? obj2 : null)).ShowUpDown = true;
			break;
		}
		case ColumnType.Date:
			host = (Control)new DateTimePicker();
			break;
		case ColumnType.TextBox:
			ejrTextBox = new EJRTextBox();
			ejrTextBox.lastCharInputEvent += OnLastCharInputted;
			host = (Control)(object)ejrTextBox;
			break;
		case ColumnType.UserControl:
			ejrControl = new EJRControl();
			host = (Control)(object)ejrControl;
			ejrControl.onEJRTextChanged += ejrControl.OnEJRTextChanged;
			break;
		}
	}

	private void OnLastCharInputted(object sender, EJRTextBoxEventArgs e)
	{
		if (((Control)ejrTextBox).Focused)
		{
			((TextBoxBase)ejrTextBox).SelectionStart = e.LastCharPosition + 1;
			((TextBoxBase)ejrTextBox).SelectionLength = 0;
		}
	}
}
public delegate void LastCharInputEventHandler(object source, EJRTextBoxEventArgs lastInputChar);
public delegate void EJRTextChangeEventHandler(object source, EJRTextBoxEventArgs inputText);
public class EJRControl : UserControl
{
	internal const string EJRPattern = "[A-Z,a-z]{2}[0-9,a-z,A-Z, ,_]{1}[0-9]{4}[-]{1}[0-9]{2}";

	private const int WM_KEYUP = 257;

	public EventHandler onEJRTextBoxUpdate;

	private Panel panelFirst;

	private Panel panelSecond;

	private Panel panelThird;

	private Panel panelEJRTextBox;

	private EJRTextBox firstEJRTextBox;

	private EJRTextBox secEJRTextBox;

	private EJRTextBox thirdERJTextBox;

	private Container components;

	private Label hypen;

	private ResourceManager resourceManager;

	public string EJRNumber => ((Control)firstEJRTextBox).Text + ((Control)secEJRTextBox).Text + "-" + ((Control)thirdERJTextBox).Text;

	public event EJRTextChangeEventHandler onEJRTextChanged;

	public EJRControl()
	{
		InitializeComponent();
	}

	public void OnEJRTextChanged(object sender, EJRTextBoxEventArgs e)
	{
		((Control)firstEJRTextBox).Text = e.InputText.Substring(0, 3);
		if (((Control)secEJRTextBox).Text.Length == 5)
		{
			((Control)secEJRTextBox).Text = e.InputText.Substring(3, 5);
			((Control)thirdERJTextBox).Text = e.InputText.Substring(9, 2);
		}
		else
		{
			((Control)secEJRTextBox).Text = e.InputText.Substring(3, 4);
			((Control)thirdERJTextBox).Text = e.InputText.Substring(8, 2);
		}
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		((ContainerControl)this).Dispose(disposing);
	}

	protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
	{
		//IL_000b: Unknown result type (might be due to invalid IL or missing references)
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		//IL_000f: Invalid comparison between Unknown and I4
		//IL_00f9: Unknown result type (might be due to invalid IL or missing references)
		//IL_00fc: Invalid comparison between Unknown and I4
		//IL_012a: Unknown result type (might be due to invalid IL or missing references)
		try
		{
			Keys val = (Keys)(int)((Message)(ref msg)).WParam;
			if ((int)val == 9 && ((Control)firstEJRTextBox).Focused)
			{
				_ = ((Control)firstEJRTextBox).Text[2];
				if (((Control)firstEJRTextBox).Text[0] != '*' && ((Control)firstEJRTextBox).Text[1] != '*' && ((Control)firstEJRTextBox).Text[2] == '*')
				{
					string text = ((Control)firstEJRTextBox).Text.TrimEnd(new char[1] { '*' });
					((Control)firstEJRTextBox).Text = text + '0';
					((TextBoxBase)secEJRTextBox).SelectionStart = 0;
					((TextBoxBase)secEJRTextBox).SelectionLength = 1;
					((Control)firstEJRTextBox).TextChanged -= firstEJRTextBox_TextChanged;
				}
				else
				{
					((TextBoxBase)secEJRTextBox).SelectionStart = 0;
					((TextBoxBase)secEJRTextBox).SelectionLength = 1;
				}
			}
			else if ((int)val == 9 && ((Control)secEJRTextBox).Focused)
			{
				((TextBoxBase)thirdERJTextBox).SelectionStart = 0;
				((TextBoxBase)thirdERJTextBox).SelectionLength = 1;
			}
		}
		catch
		{
		}
		return ((ContainerControl)this).ProcessCmdKey(ref msg, keyData);
	}

	private void InitializeComponent()
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_000b: Expected O, but got Unknown
		//IL_0022: Unknown result type (might be due to invalid IL or missing references)
		//IL_002c: Expected O, but got Unknown
		//IL_002d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0037: Expected O, but got Unknown
		//IL_0043: Unknown result type (might be due to invalid IL or missing references)
		//IL_004d: Expected O, but got Unknown
		//IL_004e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0058: Expected O, but got Unknown
		//IL_02fc: Unknown result type (might be due to invalid IL or missing references)
		//IL_0306: Expected O, but got Unknown
		panelFirst = new Panel();
		firstEJRTextBox = new EJRTextBox();
		secEJRTextBox = new EJRTextBox();
		panelSecond = new Panel();
		hypen = new Label();
		thirdERJTextBox = new EJRTextBox();
		panelThird = new Panel();
		panelEJRTextBox = new Panel();
		((Control)panelFirst).SuspendLayout();
		((Control)panelSecond).SuspendLayout();
		((Control)panelThird).SuspendLayout();
		((Control)panelEJRTextBox).SuspendLayout();
		((Control)this).SuspendLayout();
		((Control)panelFirst).Controls.Add((Control)(object)firstEJRTextBox);
		((Control)panelFirst).Dock = (DockStyle)3;
		((Control)panelFirst).Location = new Point(0, 0);
		((Control)panelFirst).Name = "panelFirst";
		((Control)panelFirst).Size = new Size(40, 38);
		((Control)panelFirst).TabIndex = 0;
		((Control)firstEJRTextBox).Dock = (DockStyle)5;
		firstEJRTextBox.InputChar = '*';
		firstEJRTextBox.InputMask = "AAS";
		((Control)firstEJRTextBox).Location = new Point(0, 0);
		((TextBoxBase)firstEJRTextBox).MaxLength = 3;
		((Control)firstEJRTextBox).Name = "firstEJRTextBox";
		((Control)firstEJRTextBox).Size = new Size(40, 20);
		((Control)firstEJRTextBox).TabIndex = 0;
		((Control)firstEJRTextBox).Text = "***";
		((Control)firstEJRTextBox).GotFocus += firstEJRTextBox_GotFocus;
		firstEJRTextBox.lastCharInputEvent += OnLastCharInputted;
		((Control)firstEJRTextBox).TextChanged += firstEJRTextBox_TextChanged;
		secEJRTextBox.InputChar = '*';
		secEJRTextBox.InputMask = "DDDDD";
		((Control)secEJRTextBox).Location = new Point(6, 0);
		((TextBoxBase)secEJRTextBox).MaxLength = 5;
		((Control)secEJRTextBox).Name = "secEJRTextBox";
		((Control)secEJRTextBox).Size = new Size(40, 20);
		((Control)secEJRTextBox).TabIndex = 1;
		((Control)secEJRTextBox).Text = "****";
		((Control)secEJRTextBox).GotFocus += secEJRTextBox_GotFocus;
		secEJRTextBox.lastCharInputEvent += OnLastCharInputted;
		((Control)secEJRTextBox).TextChanged += secEJRTextBox_TextChanged;
		((Control)panelSecond).Controls.Add((Control)(object)secEJRTextBox);
		((Control)panelSecond).Controls.Add((Control)(object)hypen);
		((Control)panelSecond).Location = new Point(37, 0);
		((Control)panelSecond).Name = "panelSecond";
		((Control)panelSecond).Size = new Size(56, 24);
		((Control)panelSecond).TabIndex = 2;
		((Control)hypen).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)hypen).Location = new Point(40, -2);
		((Control)hypen).Name = "hypen";
		((Control)hypen).Size = new Size(22, 24);
		((Control)hypen).TabIndex = 3;
		((Control)hypen).Text = "-";
		hypen.TextAlign = (ContentAlignment)32;
		thirdERJTextBox.InputChar = '*';
		thirdERJTextBox.InputMask = "DD";
		((Control)thirdERJTextBox).Location = new Point(-1, 0);
		((TextBoxBase)thirdERJTextBox).MaxLength = 2;
		((Control)thirdERJTextBox).Name = "thirdERJTextBox";
		((Control)thirdERJTextBox).Size = new Size(24, 20);
		((Control)thirdERJTextBox).TabIndex = 2;
		((Control)thirdERJTextBox).Text = "**";
		thirdERJTextBox.lastCharInputEvent += OnLastCharInputted;
		((Control)thirdERJTextBox).TextChanged += thirdERJTextBox_TextChanged;
		((Control)panelThird).Controls.Add((Control)(object)thirdERJTextBox);
		((Control)panelThird).Location = new Point(104, 0);
		((Control)panelThird).Name = "panelThird";
		((Control)panelThird).Size = new Size(24, 38);
		((Control)panelThird).TabIndex = 4;
		((Control)panelEJRTextBox).Anchor = (AnchorStyles)15;
		((Control)panelEJRTextBox).Controls.Add((Control)(object)panelFirst);
		((Control)panelEJRTextBox).Controls.Add((Control)(object)panelThird);
		((Control)panelEJRTextBox).Controls.Add((Control)(object)panelSecond);
		((Control)panelEJRTextBox).Location = new Point(0, 0);
		((Control)panelEJRTextBox).Name = "panelEJRTextBox";
		((Control)panelEJRTextBox).Size = new Size(136, 38);
		((Control)panelEJRTextBox).TabIndex = 5;
		((Control)this).Controls.Add((Control)(object)panelEJRTextBox);
		((Control)this).Name = "EJRControl";
		((Control)this).Size = new Size(136, 24);
		((Control)panelFirst).ResumeLayout(false);
		((Control)panelSecond).ResumeLayout(false);
		((Control)panelThird).ResumeLayout(false);
		((Control)panelEJRTextBox).ResumeLayout(false);
		((Control)this).ResumeLayout(false);
	}

	private void firstEJRTextBox_TextChanged(object sender, EventArgs e)
	{
		Check_EJRFormat();
		if (onEJRTextBoxUpdate != null)
		{
			onEJRTextBoxUpdate(this, EventArgs.Empty);
		}
	}

	private void secEJRTextBox_TextChanged(object sender, EventArgs e)
	{
		Check_EJRFormat();
		if (onEJRTextBoxUpdate != null)
		{
			onEJRTextBoxUpdate(this, EventArgs.Empty);
		}
	}

	private void thirdERJTextBox_TextChanged(object sender, EventArgs e)
	{
		if (onEJRTextBoxUpdate != null)
		{
			onEJRTextBoxUpdate(this, EventArgs.Empty);
		}
	}

	private void Check_EJRFormat()
	{
		if (((Control)firstEJRTextBox).Text.Substring(0, 2) == "CR")
		{
			if (((Control)secEJRTextBox).Text.Length == 4)
			{
				EJRTextBox eJRTextBox = secEJRTextBox;
				((Control)eJRTextBox).Text = ((Control)eJRTextBox).Text + "*";
				((TextBoxBase)secEJRTextBox).MaxLength = 5;
				secEJRTextBox.format = "*****";
			}
		}
		else
		{
			((Control)secEJRTextBox).Text = ((Control)secEJRTextBox).Text.Substring(0, 4);
			((TextBoxBase)secEJRTextBox).MaxLength = 4;
			secEJRTextBox.format = "****";
		}
	}

	private void OnLastCharInputted(object sender, EJRTextBoxEventArgs e)
	{
		if (((Control)firstEJRTextBox).Focused)
		{
			if (e.LastCharInput == ' ' || e.LastCharInput == '_')
			{
				char[] trimChars = new char[2] { ' ', '_' };
				string text = ((Control)firstEJRTextBox).Text.TrimEnd(trimChars);
				((Control)firstEJRTextBox).Text = text + '0';
			}
			((Control)secEJRTextBox).Focus();
			((TextBoxBase)secEJRTextBox).SelectionStart = 0;
			((TextBoxBase)secEJRTextBox).SelectionLength = 1;
			if (onEJRTextBoxUpdate != null)
			{
				onEJRTextBoxUpdate(this, EventArgs.Empty);
			}
		}
		else if (((Control)secEJRTextBox).Focused)
		{
			((Control)thirdERJTextBox).Focus();
			((TextBoxBase)thirdERJTextBox).SelectionStart = 0;
			((TextBoxBase)thirdERJTextBox).SelectionLength = 1;
			if (onEJRTextBoxUpdate != null)
			{
				onEJRTextBoxUpdate(this, EventArgs.Empty);
			}
		}
		else if (((Control)thirdERJTextBox).Focused)
		{
			((TextBoxBase)thirdERJTextBox).SelectionStart = 2;
			((TextBoxBase)thirdERJTextBox).SelectionLength = 0;
			if (onEJRTextBoxUpdate != null)
			{
				onEJRTextBoxUpdate(this, EventArgs.Empty);
			}
		}
	}

	private void firstEJRTextBox_GotFocus(object sender, EventArgs e)
	{
		((TextBoxBase)firstEJRTextBox).SelectionStart = 0;
		((TextBoxBase)firstEJRTextBox).SelectionLength = 1;
	}

	private void secEJRTextBox_GotFocus(object sender, EventArgs e)
	{
		((Control)secEJRTextBox).Focus();
		((TextBoxBase)secEJRTextBox).SelectionStart = 0;
		((TextBoxBase)secEJRTextBox).SelectionLength = 1;
	}
}
public class EJRTextBox : TextBox
{
	private const int WM_KEYUP = 257;

	private const char MASK_KEY = '@';

	private const string EJRText_format = "********";

	public EventHandler TabKeyPressed;

	private string mask;

	public string format;

	private Hashtable posNdx;

	private int reqdCnt;

	private int optCnt;

	private char inputChar;

	private Hashtable regExps;

	private int caret;

	private ContextMenu operationContextMenu;

	public string InputMask
	{
		get
		{
			return mask;
		}
		set
		{
			mask = value;
			SetupMask();
			if (((Component)this).DesignMode || ((TextBox)this).Text.Length == 0 || !IsValidString(((TextBox)this).Text))
			{
				((TextBox)this).Text = format;
			}
			((TextBoxBase)this).MaxLength = format.Length;
		}
	}

	public char InputChar
	{
		get
		{
			return inputChar;
		}
		set
		{
			inputChar = value;
		}
	}

	public override int MaxLength
	{
		get
		{
			return ((TextBoxBase)this).MaxLength;
		}
		set
		{
			((TextBoxBase)this).MaxLength = value;
		}
	}

	private Hashtable RegExps
	{
		get
		{
			if (regExps == null)
			{
				regExps = new Hashtable();
				regExps.Add('A', "[a-zA-Z]");
				regExps.Add('S', "[a-zA-Z|0-9]");
				regExps.Add('D', "[0-9]");
				regExps.Add('Y', "[A-Z|0-9]");
				regExps.Add('@', "[A|S|D|Y]");
			}
			return regExps;
		}
	}

	public event LastCharInputEventHandler lastCharInputEvent;

	public EJRTextBox()
	{
		CreateContextMenu();
		caret = 0;
		((TextBox)this).Multiline = false;
	}

	protected override void WndProc(ref Message message)
	{
		if (((Message)(ref message)).Msg != 257)
		{
			((TextBox)this).WndProc(ref message);
		}
	}

	protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
	{
		//IL_0051: Unknown result type (might be due to invalid IL or missing references)
		//IL_0052: Unknown result type (might be due to invalid IL or missing references)
		//IL_0054: Unknown result type (might be due to invalid IL or missing references)
		//IL_005b: Invalid comparison between Unknown and I4
		//IL_00d5: Unknown result type (might be due to invalid IL or missing references)
		//IL_00dc: Invalid comparison between Unknown and I4
		//IL_005d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0061: Unknown result type (might be due to invalid IL or missing references)
		//IL_0097: Expected I4, but got Unknown
		//IL_00e1: Unknown result type (might be due to invalid IL or missing references)
		//IL_00e8: Invalid comparison between Unknown and I4
		//IL_0389: Unknown result type (might be due to invalid IL or missing references)
		//IL_0097: Unknown result type (might be due to invalid IL or missing references)
		//IL_009e: Unknown result type (might be due to invalid IL or missing references)
		//IL_00d0: Expected I4, but got Unknown
		int num = ((TextBoxBase)this).SelectionStart;
		int num2 = ((TextBoxBase)this).SelectionLength;
		int num3 = num + ((TextBoxBase)this).SelectionLength - 1;
		string text = ((TextBox)this).Text;
		if (((TextBoxBase)this).SelectionStart < format.Length && format[num] != inputChar)
		{
			num = Next(-1);
			num2 = 1;
		}
		if ((int)keyData <= 65581)
		{
			switch (keyData - 35)
			{
			case 2:
			case 3:
			{
				int num4 = Prev(num);
				if (num4 != num)
				{
					((TextBoxBase)this).SelectionStart = num4;
					((TextBoxBase)this).SelectionLength = 1;
				}
				caret = num4;
				return true;
			}
			case 4:
			case 5:
			{
				int num4 = Next(num);
				if (num4 != num)
				{
					((TextBoxBase)this).SelectionStart = num4;
					((TextBoxBase)this).SelectionLength = 1;
				}
				caret = num4;
				return true;
			}
			case 11:
				((TextBox)this).Text = text.Substring(0, num) + format.Substring(num, num2) + text.Substring(num + num2);
				((TextBoxBase)this).SelectionStart = num;
				((TextBoxBase)this).SelectionLength = 1;
				caret = num;
				return true;
			case 1:
				((TextBoxBase)this).SelectionStart = Next(-1);
				((TextBoxBase)this).SelectionLength = 1;
				caret = ((TextBoxBase)this).SelectionStart;
				return true;
			case 0:
				((TextBoxBase)this).SelectionStart = Prev(((TextBoxBase)this).MaxLength);
				((TextBoxBase)this).SelectionLength = 1;
				caret = ((TextBoxBase)this).SelectionStart;
				return true;
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
				goto IL_0387;
			}
			switch (keyData - 65571)
			{
			case 2:
			case 3:
				if (num < caret || (num == caret && num2 <= 1))
				{
					int num4 = Prev(num);
					((TextBoxBase)this).SelectionStart = ((TextBoxBase)this).SelectionStart - (num - num4);
					((TextBoxBase)this).SelectionLength = num2 + (num - num4);
				}
				else
				{
					((TextBoxBase)this).SelectionLength = num2 - (num3 - Prev(num3));
				}
				return true;
			case 4:
			case 5:
				if (num < caret)
				{
					int num4 = Next(num);
					((TextBoxBase)this).SelectionStart = ((TextBoxBase)this).SelectionStart + (num4 - num);
					((TextBoxBase)this).SelectionLength = num2 - (num4 - num);
				}
				else if (num == caret)
				{
					int num4 = Next(num3);
					((TextBoxBase)this).SelectionLength = num2 + (num4 - num3);
				}
				return true;
			case 1:
				if (num <= caret && num2 <= 1)
				{
					int num4 = Next(-1);
					((TextBoxBase)this).SelectionStart = ((TextBoxBase)this).SelectionStart - (num - num4);
					((TextBoxBase)this).SelectionLength = num2 + (num - num4);
				}
				else
				{
					int num4 = (((TextBoxBase)this).SelectionStart = Next(-1));
					((TextBoxBase)this).SelectionLength = caret - num4 + 1;
				}
				return true;
			case 0:
				if (num < caret)
				{
					int num4 = Prev(((TextBoxBase)this).MaxLength);
					((TextBoxBase)this).SelectionStart = caret;
					((TextBoxBase)this).SelectionLength = num4 - caret + 1;
				}
				else if (num == caret)
				{
					int num4 = Prev(((TextBoxBase)this).MaxLength);
					((TextBoxBase)this).SelectionLength = num2 + (num4 - num3);
				}
				return true;
			case 10:
				break;
			default:
				goto IL_0387;
			}
		}
		else
		{
			if ((int)keyData == 131139)
			{
				CopyInfo copyInfo = new CopyInfo();
				copyInfo.SetDataToClipBoard(((TextBox)this).Text);
				return true;
			}
			if ((int)keyData != 131158)
			{
				goto IL_0387;
			}
		}
		CopyInfo copyInfo2 = new CopyInfo();
		copyInfo2.GetClipBoardData();
		string text2 = text.Substring(0, num) + copyInfo2.ClipboardText + text.Substring(num + num2);
		if (IsValidString(text2))
		{
			((TextBox)this).Text = text2.Substring(0, format.Length);
		}
		return true;
		IL_0387:
		return ((TextBoxBase)this).ProcessCmdKey(ref msg, keyData);
	}

	protected override void OnKeyPress(KeyPressEventArgs e)
	{
		int num = ((TextBoxBase)this).SelectionStart;
		int num2 = ((TextBoxBase)this).SelectionLength;
		if (e.KeyChar == '\b')
		{
			string text = ((TextBox)this).Text;
			int num3 = Prev(num);
			if (num3 != num)
			{
				((TextBox)this).Text = text.Substring(0, num3) + inputChar + text.Substring(num3 + 1);
				((TextBoxBase)this).SelectionStart = num3;
				((TextBoxBase)this).SelectionLength = 1;
			}
			caret = num3;
			e.Handled = true;
			return;
		}
		if (num < format.Length && format[num] != inputChar)
		{
			num = Next(-1);
			num2 = 1;
		}
		if (num < format.Length && IsValidChar(e.KeyChar, (int)posNdx[num]))
		{
			string text2 = "";
			CheckPartNumberFormat(num, e.KeyChar);
			text2 = ((TextBox)this).Text.Substring(0, num);
			text2 += e.KeyChar;
			if (num + num2 != ((TextBoxBase)this).MaxLength)
			{
				if (num2 != 0)
				{
					text2 += format.Substring(num + 1, num2 - 1);
				}
				text2 += ((TextBox)this).Text.Substring(num + num2);
			}
			else
			{
				text2 += format.Substring(num + 1);
			}
			((TextBox)this).Text = text2;
			if (num < ((TextBoxBase)this).MaxLength - 1)
			{
				num = (((TextBoxBase)this).SelectionStart = Next(num));
				caret = num;
				((TextBoxBase)this).SelectionLength = 1;
			}
			else
			{
				caret = num + 1;
				if (this.lastCharInputEvent != null)
				{
					EJRTextBoxEventArgs lastInputChar = new EJRTextBoxEventArgs(e.KeyChar, caret);
					this.lastCharInputEvent(this, lastInputChar);
				}
			}
		}
		e.Handled = true;
	}

	protected override void OnMouseUp(MouseEventArgs e)
	{
		int num = ((TextBoxBase)this).SelectionStart;
		int num2 = num;
		int selectionLength = ((TextBoxBase)this).SelectionLength;
		if (num == ((TextBoxBase)this).MaxLength || format[num] != inputChar)
		{
			num = (((TextBoxBase)this).SelectionStart = ((Next(num) != num) ? Next(num) : Prev(num)));
		}
		if (selectionLength < 1)
		{
			((TextBoxBase)this).SelectionLength = 1;
		}
		else if (format[num2 + selectionLength - 1] != inputChar)
		{
			selectionLength += Next(num + selectionLength) - (num + selectionLength);
			((TextBoxBase)this).SelectionLength = selectionLength;
		}
		caret = num;
		((TextBoxBase)this).OnMouseUp(e);
	}

	protected void menuItemCopy_Click(object sender, EventArgs e)
	{
		try
		{
			CopyInfo copyInfo = new CopyInfo();
			copyInfo.SetDataToClipBoard(((TextBox)this).Text);
		}
		catch
		{
		}
	}

	protected void menuItemPaste_Click(object sender, EventArgs e)
	{
		try
		{
			int selectionStart = ((TextBoxBase)this).SelectionStart;
			int selectionLength = ((TextBoxBase)this).SelectionLength;
			string text = ((TextBox)this).Text;
			CopyInfo copyInfo = new CopyInfo();
			copyInfo.GetClipBoardData();
			string text2 = text.Substring(0, selectionStart) + copyInfo.ClipboardText + text.Substring(selectionStart + selectionLength);
			if (IsValidString(text2))
			{
				((TextBox)this).Text = text2.Substring(0, format.Length);
			}
		}
		catch
		{
		}
	}

	protected void menuItemCut_Click(object sender, EventArgs e)
	{
		try
		{
			int selectionStart = ((TextBoxBase)this).SelectionStart;
			int selectionLength = ((TextBoxBase)this).SelectionLength;
			string text = ((TextBox)this).Text;
			CopyInfo copyInfo = new CopyInfo();
			copyInfo.SetDataToClipBoard(((TextBox)this).Text);
			((TextBox)this).Text = text.Substring(0, selectionStart) + format.Substring(selectionStart, selectionLength) + text.Substring(selectionStart + selectionLength);
			((TextBoxBase)this).SelectionStart = selectionStart;
			((TextBoxBase)this).SelectionLength = 1;
			caret = selectionStart;
		}
		catch
		{
		}
	}

	private void CreateContextMenu()
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_000b: Expected O, but got Unknown
		//IL_0028: Unknown result type (might be due to invalid IL or missing references)
		//IL_0032: Expected O, but got Unknown
		//IL_0050: Unknown result type (might be due to invalid IL or missing references)
		//IL_005a: Expected O, but got Unknown
		//IL_0078: Unknown result type (might be due to invalid IL or missing references)
		//IL_0082: Expected O, but got Unknown
		operationContextMenu = new ContextMenu();
		((Menu)operationContextMenu).MenuItems.Add(0, new MenuItem("Cut", (EventHandler)menuItemCut_Click));
		((Menu)operationContextMenu).MenuItems.Add(0, new MenuItem("Copy", (EventHandler)menuItemCopy_Click));
		((Menu)operationContextMenu).MenuItems.Add(1, new MenuItem("Paste", (EventHandler)menuItemPaste_Click));
		((Control)this).ContextMenu = operationContextMenu;
	}

	private void SetupMask()
	{
		string inputMask = InputMask;
		format = "";
		if (posNdx == null)
		{
			posNdx = new Hashtable();
		}
		else
		{
			posNdx.Clear();
		}
		int num = 0;
		reqdCnt = 0;
		optCnt = 0;
		for (int i = 0; i < inputMask.Length; i++)
		{
			if (IsMaskChar(inputMask[i]))
			{
				posNdx.Add(num, i);
				format += inputChar;
				if (((string)RegExps[InputMask[i]]).IndexOf(' ') != -1)
				{
					optCnt++;
				}
				else
				{
					reqdCnt++;
				}
			}
			else if (inputMask[i] == '\\')
			{
				i++;
				format += inputMask[i];
			}
			else
			{
				format += inputMask[i];
			}
			num++;
		}
	}

	private void CheckPartNumberFormat(int strt, char input)
	{
		if ((((TextBox)this).Text.Length != 7 && ((TextBox)this).Text.Length != 8) || (strt != 0 && strt != 4))
		{
			return;
		}
		if (Regex.IsMatch(input.ToString(), "[A-Z]"))
		{
			((TextBoxBase)this).MaxLength = 8;
			format = "********";
			if (((TextBox)this).Text.Length == 7)
			{
				((TextBox)this).Text = ((TextBox)this).Text + "*";
			}
		}
		else if (Regex.IsMatch(input.ToString(), "[0-9]"))
		{
			((TextBoxBase)this).MaxLength = 7;
			format = "********".Substring(0, ((TextBoxBase)this).MaxLength);
			if (((TextBox)this).Text.Length == 8)
			{
				((TextBox)this).Text = ((TextBox)this).Text.Substring(0, ((TextBoxBase)this).MaxLength);
			}
		}
	}

	private bool IsMaskChar(char input)
	{
		return Regex.IsMatch(input.ToString(), (string)RegExps['@']);
	}

	private bool IsValidString(string s)
	{
		bool flag = true;
		int num = 0;
		while (flag && num < format.Length)
		{
			if (format[num] == inputChar)
			{
				if (num >= s.Length)
				{
					flag = ((string)RegExps[InputMask[(int)posNdx[num]]]).IndexOf(' ') != -1;
				}
				else
				{
					flag = IsValidChar(s[num], (int)posNdx[num]);
					if (!flag)
					{
						flag |= ((string)RegExps[InputMask[(int)posNdx[num]]]).IndexOf(' ') != -1 && (s[num] == ' ' || s[num] == inputChar);
					}
				}
			}
			else if (num < s.Length)
			{
				flag = s[num] == format[num];
			}
			num++;
		}
		return flag;
	}

	private bool IsValidChar(char input, int pos)
	{
		return Regex.IsMatch(input.ToString(), (string)RegExps[InputMask[pos]]);
	}

	private int Prev(int startPos)
	{
		int num = startPos;
		int result = num;
		while (num > 0)
		{
			num--;
			if (format[num] == inputChar)
			{
				return num;
			}
		}
		return result;
	}

	private int Next(int startPos)
	{
		int num = startPos;
		int result = num;
		_ = ((TextBoxBase)this).MaxLength;
		while (num < ((TextBoxBase)this).MaxLength - 1)
		{
			num++;
			if (format[num] == inputChar)
			{
				return num;
			}
		}
		return result;
	}
}
public class CopyInfo
{
	private string clipboardData;

	public string ClipboardText
	{
		get
		{
			return clipboardData;
		}
		set
		{
			clipboardData = value;
		}
	}

	public void GetClipBoardData()
	{
		Thread thread = new Thread(GetData);
		thread.SetApartmentState(ApartmentState.STA);
		thread.Name = "Clipboard accessor thread.";
		thread.Start();
		thread.Join();
	}

	private void GetData()
	{
		IDataObject dataObject = Clipboard.GetDataObject();
		if (dataObject.GetDataPresent(DataFormats.Text))
		{
			clipboardData = (string)dataObject.GetData(DataFormats.Text);
		}
	}

	public void SetDataToClipBoard(string copyData)
	{
		clipboardData = copyData;
		Thread thread = new Thread(CopyData);
		thread.SetApartmentState(ApartmentState.STA);
		thread.Name = "Clipboard Thread";
		thread.Start();
		thread.Join();
	}

	private void CopyData()
	{
		try
		{
			Clipboard.SetDataObject((object)clipboardData, true);
		}
		catch
		{
		}
	}
}
public class EJRTextBoxEventArgs : EventArgs
{
	private string inputText;

	private char lastInputChar;

	private int lastCharPosition;

	public char LastCharInput => lastInputChar;

	public int LastCharPosition => lastCharPosition;

	public string InputText => inputText;

	public EJRTextBoxEventArgs()
	{
	}

	public EJRTextBoxEventArgs(string text)
	{
		inputText = text;
	}

	public EJRTextBoxEventArgs(char lastInputChar, int lastCharPosition)
	{
		this.lastInputChar = lastInputChar;
		this.lastCharPosition = lastCharPosition;
	}
}
internal enum MessageIDs
{
	DataRecordsSectionAbsent = 1,
	DuplicatePartNumber,
	EmptyFile,
	EmptyRecordInENGDL,
	FilenameLengthTooLarge,
	HeaderRecordSectionAbsent,
	InvalidFileCRC,
	InvalidPartNumber,
	InvalidPreparedFile,
	InvalidRecordLength,
	InvalidSubfile,
	LocalFilenameSectionMissing,
	NullAppConfigService,
	NullDirectoryService,
	PartNumberInvalidLength,
	PartNumberIsNull,
	PreparedFilesSchemaInvalid,
	SpeedFilenameSectionMissing,
	SpeedFilePathMissing,
	StalePreparedFilesDatabase,
	TableNotFoundInReport,
	UnableToFindSPEEDSubdirectory,
	UnableToLoadReportSchema,
	InvalidEJRNumber,
	UploadFileNotExist,
	UnsupportedProduct
}
public struct PreparedFileInformation
{
	internal static char[] FileTypeCharArray = new char[12]
	{
		'D', 'A', 'B', 'C', 'E', 'E', 'F', 'H', 'I', 'L',
		'V', 'P'
	};

	internal static string PreparedFileNameFormat1 = "{0,1}.{1}.{2}.{3}";

	internal static string PreparedFileNameFormat2 = "{0,1}.{1}.{3}";

	private FileType type;

	private string filename;

	private string pathname;

	private string ejrNumber;

	private string partNumber;

	private string productID;

	public FileType FileType
	{
		get
		{
			return type;
		}
		set
		{
			type = value;
		}
	}

	public string Filename
	{
		get
		{
			return filename;
		}
		set
		{
			filename = value;
		}
	}

	public string Pathname
	{
		get
		{
			return pathname;
		}
		set
		{
			pathname = value;
		}
	}

	public string EJRNumber
	{
		get
		{
			return ejrNumber;
		}
		set
		{
			ejrNumber = value;
		}
	}

	public string PartNumber
	{
		get
		{
			return partNumber;
		}
		set
		{
			partNumber = value;
		}
	}

	public string SourceFilename
	{
		get
		{
			string text = Pathname;
			if (text[text.Length - 1] != '\\')
			{
				text += "\\";
			}
			return text + filename;
		}
	}

	public string PreparedFileName
	{
		get
		{
			string text = null;
			char c = FileTypeToChar(type);
			string text2 = ejrNumber.Substring(0, ejrNumber.Length - 2) + "-" + ejrNumber.Substring(ejrNumber.Length - 2, 2);
			if (text2 == SpeedPreparedFiles.DefaultEJRNumber)
			{
				return string.Format(PreparedFileNameFormat2, c, partNumber, ejrNumber, filename);
			}
			return string.Format(PreparedFileNameFormat1, c, partNumber, ejrNumber, filename);
		}
	}

	public string ProductID
	{
		get
		{
			return productID;
		}
		set
		{
			productID = value;
		}
	}

	private char FileTypeToChar(FileType fileType)
	{
		byte b = (byte)fileType;
		if (b > FileTypeCharArray.Length - 1 || b < 0)
		{
			b = 0;
		}
		return FileTypeCharArray[b];
	}
}
public class ProgressEventArgs : EventArgs
{
	private int total;

	private int current;

	private string progressStatus;

	public int Current
	{
		get
		{
			return current;
		}
		set
		{
			current = value;
		}
	}

	public int Total
	{
		get
		{
			return total;
		}
		set
		{
			total = value;
		}
	}

	public string Status
	{
		get
		{
			return progressStatus;
		}
		set
		{
			if (value == null)
			{
				throw new ArgumentNullException("Progress Status");
			}
			progressStatus = value;
		}
	}

	public ProgressEventArgs()
	{
	}

	public ProgressEventArgs(string status, int total, int current)
	{
		Status = status;
		this.total = total;
		this.current = current;
	}
}
public class SpeedConfiguration
{
	internal static string DefaultSpeedServerDownloadPath = "\\\\cidcspdapp1\\download";

	internal static string DefaultSpeedServerUploadPath = "\\\\cidcspdapp1\\upload";

	internal static string DefaultSpeedUploadReportFile = "upload";

	internal static string DefaultSpeedDownloadReportFile = "download";

	internal static string DefaultSpeedReportFormat = "HTML";

	internal static string SpeedReportFileTag = ".spd";

	private string downloadFileName;

	private string downdReportFileFullPathName;

	private string uploadFileName;

	private string productID;

	private bool accessedByCLI;

	private string speedServerDownloadPath;

	private string speedServerUploadPath;

	private string speedReportFormat;

	private ResourceManager resourceManager;

	private IServiceManager serviceManager;

	private bool appendReportFile;

	public string ProductID
	{
		get
		{
			if (!accessedByCLI)
			{
				return GetValueFromAppSettings(ApplicationSettings.LastProduct);
			}
			return productID;
		}
		set
		{
			productID = value;
		}
	}

	public string DownloadReportFileName
	{
		get
		{
			return downloadFileName;
		}
		set
		{
			if (value.Length == 0)
			{
				throw new ArgumentNullException("downloadFileName");
			}
			downloadFileName = value;
		}
	}

	public string DowndReportFileFullPathName
	{
		get
		{
			return downdReportFileFullPathName;
		}
		set
		{
			downdReportFileFullPathName = value;
		}
	}

	public string UploadReportFileName
	{
		get
		{
			return uploadFileName;
		}
		set
		{
			if (value.Length == 0)
			{
				throw new ArgumentNullException("uploadFileName");
			}
			uploadFileName = value;
		}
	}

	public PostDownloadAction PostDownloadAction => PostDownloadAction.CopyToUnrlcal;

	public string SpeedServerDownloadPath
	{
		get
		{
			if (string.IsNullOrEmpty(speedServerDownloadPath))
			{
				speedServerDownloadPath = GetValueFromAppSettings(ApplicationSettings.SpeedServerDownloadPath);
				if (string.IsNullOrEmpty(speedServerDownloadPath))
				{
					speedServerDownloadPath = DefaultSpeedServerDownloadPath;
				}
			}
			return speedServerDownloadPath;
		}
		set
		{
			if (value.Length == 0)
			{
				throw new ArgumentNullException("speedServerDownloadPath");
			}
			speedServerDownloadPath = value;
		}
	}

	public string SpeedServerUploadPath
	{
		get
		{
			if (string.IsNullOrEmpty(speedServerUploadPath))
			{
				speedServerUploadPath = GetValueFromAppSettings(ApplicationSettings.SpeedServerUploadPath);
				if (string.IsNullOrEmpty(speedServerUploadPath))
				{
					speedServerUploadPath = DefaultSpeedServerUploadPath;
				}
			}
			return speedServerUploadPath;
		}
		set
		{
			if (value.Length == 0)
			{
				throw new ArgumentNullException("speedServerUploadPath");
			}
			speedServerUploadPath = value;
		}
	}

	public string TempDownloadPath => GetPath(FolderType.Download);

	public string TempUploadPath => GetPath(FolderType.Upload);

	public string ProductUnrlCalPath => GetPath(FolderType.UnreleasedCalibration);

	public string ProductCalPath => GetPath(FolderType.ReleasedCalibration);

	public string ProductSupportPath => GetPath(FolderType.ProductSupport);

	public string ReportFormat
	{
		get
		{
			return speedReportFormat;
		}
		set
		{
			if (value.Length == 0)
			{
				throw new ArgumentNullException("speedReportFormat");
			}
			speedReportFormat = value;
		}
	}

	public bool AppendReportFile
	{
		get
		{
			return appendReportFile;
		}
		set
		{
			appendReportFile = value;
		}
	}

	public bool CESProduct()
	{
		bool result = false;
		if (ProductID == "BFN" || ProductID == "BFQ" || ProductID == "BFZ" || ProductID == "BGD")
		{
			result = true;
		}
		return result;
	}

	public SpeedConfiguration(ResourceManager resourceManager)
	{
		Initialize(resourceManager, caltermCLI: false, null);
	}

	public SpeedConfiguration(ResourceManager resourceManager, bool caltermCLI, string productIdentifier)
	{
		Initialize(resourceManager, caltermCLI, productIdentifier);
	}

	private void Initialize(ResourceManager resourceManager, bool caltermCLI, string productIdentifier)
	{
		this.resourceManager = resourceManager;
		accessedByCLI = caltermCLI;
		if (!string.IsNullOrEmpty(productIdentifier))
		{
			ProductID = productIdentifier;
		}
		serviceManager = ServiceManager.Services;
		uploadFileName = GetValueFromAppSettings(ApplicationSettings.SpeedUploadReport);
		if (uploadFileName == null || uploadFileName.Length == 0)
		{
			uploadFileName = DefaultSpeedUploadReportFile;
		}
		downloadFileName = GetValueFromAppSettings(ApplicationSettings.SpeedDownloadReport);
		if (downloadFileName == null || downloadFileName.Length == 0)
		{
			downloadFileName = DefaultSpeedDownloadReportFile;
		}
		speedReportFormat = GetValueFromAppSettings(ApplicationSettings.SpeedReportFormat);
		if (speedReportFormat == null || speedReportFormat.Length == 0)
		{
			speedReportFormat = DefaultSpeedReportFormat;
		}
		downdReportFileFullPathName = string.Empty;
	}

	public void Save()
	{
		IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		if (appConfigService != null)
		{
			appConfigService.SetAppSetting(ApplicationSettings.SpeedDownloadReport, downloadFileName);
			appConfigService.SetAppSetting(ApplicationSettings.SpeedUploadReport, uploadFileName);
			appConfigService.SetAppSetting(ApplicationSettings.SpeedServerDownloadPath, speedServerDownloadPath);
			appConfigService.SetAppSetting(ApplicationSettings.SpeedServerUploadPath, speedServerUploadPath);
			appConfigService.SetAppSetting(ApplicationSettings.SpeedReportFormat, speedReportFormat);
			return;
		}
		throw NewServiceManagerException(Facility.SpeedTransfer, 13, resourceManager.GetString("InvalidAppConfig"), typeof(IAppConfigService));
	}

	public string GenerateFullDownloadReportName()
	{
		return GenerateReportFileName(downloadFileName);
	}

	public string GenerateFullUploadReportName()
	{
		return GenerateReportFileName(uploadFileName);
	}

	private string GetPath(FolderType folderType)
	{
		string productIdentifier = ((!accessedByCLI) ? GetValueFromAppSettings(ApplicationSettings.LastProduct) : ProductID);
		IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
		if (directoryService != null)
		{
			string text = directoryService.FolderName(folderType, productIdentifier);
			if (text == null || text.Length == 0)
			{
				throw new SpeedTransferException(resourceManager.GetString("InvalidPath"));
			}
			return text;
		}
		throw NewServiceManagerException(Facility.SpeedTransfer, 14, resourceManager.GetString("InvalidAppConfig"), typeof(IDirectoryService));
	}

	private string GetValueFromAppSettings(ApplicationSettings itemName)
	{
		IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		string text = null;
		if (appConfigService != null)
		{
			return appConfigService.GetAppSetting(itemName);
		}
		throw NewServiceManagerException(Facility.SpeedTransfer, 13, resourceManager.GetString("InvalidAppConfig"), typeof(IAppConfigService));
	}

	private string GenerateReportFileName(string baseFilename)
	{
		if (baseFilename == null || baseFilename.Length == 0)
		{
			throw new ArgumentNullException("baseFilename");
		}
		string path = GetPath(FolderType.Product);
		string text = "";
		string text2 = "";
		int num = baseFilename.LastIndexOf('.');
		if (num != -1)
		{
			text = baseFilename.Substring(num + 1);
			text2 = baseFilename.Substring(0, num);
		}
		else
		{
			text = ((!speedReportFormat.Equals("TXT")) ? ("." + speedReportFormat.ToLower()) : ".txt");
			text2 = baseFilename;
		}
		text = SpeedReportFileTag + text;
		return Utility.FindAvailableFilename(text2, text, path);
	}

	public static ServiceManagerException NewServiceManagerException(Facility facility, short errId, string message, Type serviceType)
	{
		ServiceManagerException ex = new ServiceManagerException(facility, errId, message);
		ex.ContextData = serviceType.ToString();
		return ex;
	}
}
public class SpeedConfigurationPage : UserControl, IPropertyPage
{
	internal static string ResourceFilename = "Cummins.SpeedTransferComponent.Strings";

	private Label lblDefaultDowloadFileName;

	private TextBox txtDefaultUploadFilename;

	private TextBox txtDefaultDownloadFilename;

	private Label lblUploadFileName;

	private Label lblReportFormat;

	private ComboBox cmbReportFormat;

	private Container components;

	private SpeedConfiguration speedConfiguration;

	private string parentNode;

	private string currentNode;

	private Label lblSpeedServerDownloadPath;

	private TextBox txtSpeedServerDownloadPath;

	private Label lblSpeedServerUploadPath;

	private TextBox txtSpeedServerUploadPath;

	private ResourceManager resourceManager;

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

	public SpeedConfigurationPage()
	{
		InitializeComponent();
		parentNode = "";
		currentNode = "";
		resourceManager = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
		speedConfiguration = new SpeedConfiguration(resourceManager);
		Initialize();
	}

	public SpeedConfigurationPage(string parentNode, string currentNode)
	{
		InitializeComponent();
		this.parentNode = parentNode;
		this.currentNode = currentNode;
		resourceManager = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
		speedConfiguration = new SpeedConfiguration(resourceManager);
		Initialize();
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
		//IL_0043: Unknown result type (might be due to invalid IL or missing references)
		//IL_004d: Expected O, but got Unknown
		//IL_004e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0058: Expected O, but got Unknown
		//IL_0059: Unknown result type (might be due to invalid IL or missing references)
		//IL_0063: Expected O, but got Unknown
		//IL_0064: Unknown result type (might be due to invalid IL or missing references)
		//IL_006e: Expected O, but got Unknown
		lblSpeedServerDownloadPath = new Label();
		txtSpeedServerDownloadPath = new TextBox();
		txtDefaultDownloadFilename = new TextBox();
		lblDefaultDowloadFileName = new Label();
		txtDefaultUploadFilename = new TextBox();
		lblUploadFileName = new Label();
		lblReportFormat = new Label();
		cmbReportFormat = new ComboBox();
		lblSpeedServerUploadPath = new Label();
		txtSpeedServerUploadPath = new TextBox();
		((Control)this).SuspendLayout();
		((Control)lblSpeedServerDownloadPath).AutoSize = true;
		((Control)lblSpeedServerDownloadPath).Location = new Point(16, 18);
		((Control)lblSpeedServerDownloadPath).Name = "lblSpeedServerDownloadPath";
		((Control)lblSpeedServerDownloadPath).Size = new Size(181, 16);
		((Control)lblSpeedServerDownloadPath).TabIndex = 0;
		((Control)lblSpeedServerDownloadPath).Text = "&SPEED Server Download Pathname";
		lblSpeedServerDownloadPath.TextAlign = (ContentAlignment)32;
		((Control)txtSpeedServerDownloadPath).Location = new Point(209, 16);
		((Control)txtSpeedServerDownloadPath).Name = "txtSpeedServerDownloadPath";
		((Control)txtSpeedServerDownloadPath).Size = new Size(224, 20);
		((Control)txtSpeedServerDownloadPath).TabIndex = 1;
		((Control)txtSpeedServerDownloadPath).Text = "";
		((Control)txtSpeedServerDownloadPath).Validating += txtSpeedServerDownloadPath_Validating;
		((Control)txtDefaultDownloadFilename).Location = new Point(209, 86);
		((Control)txtDefaultDownloadFilename).Name = "txtDefaultDownloadFilename";
		((Control)txtDefaultDownloadFilename).Size = new Size(224, 20);
		((Control)txtDefaultDownloadFilename).TabIndex = 5;
		((Control)txtDefaultDownloadFilename).Text = "";
		((Control)txtDefaultDownloadFilename).Validating += txtDefaultDownloadFilename_Validating;
		((Control)lblDefaultDowloadFileName).AutoSize = true;
		((Control)lblDefaultDowloadFileName).Location = new Point(18, 90);
		((Control)lblDefaultDowloadFileName).Name = "lblDefaultDowloadFileName";
		((Control)lblDefaultDowloadFileName).Size = new Size(152, 16);
		((Control)lblDefaultDowloadFileName).TabIndex = 4;
		((Control)lblDefaultDowloadFileName).Text = "Default &Download Report File";
		lblDefaultDowloadFileName.TextAlign = (ContentAlignment)32;
		((Control)txtDefaultUploadFilename).Location = new Point(209, 123);
		((Control)txtDefaultUploadFilename).Name = "txtDefaultUploadFilename";
		((Control)txtDefaultUploadFilename).Size = new Size(224, 20);
		((Control)txtDefaultUploadFilename).TabIndex = 7;
		((Control)txtDefaultUploadFilename).Text = "";
		((Control)txtDefaultUploadFilename).Validating += txtDefaultUploadFilename_Validating;
		((Control)lblUploadFileName).AutoSize = true;
		((Control)lblUploadFileName).Location = new Point(18, 123);
		((Control)lblUploadFileName).Name = "lblUploadFileName";
		((Control)lblUploadFileName).Size = new Size(138, 16);
		((Control)lblUploadFileName).TabIndex = 6;
		((Control)lblUploadFileName).Text = "Default &Upload Report File";
		lblUploadFileName.TextAlign = (ContentAlignment)32;
		((Control)lblReportFormat).AutoSize = true;
		((Control)lblReportFormat).Location = new Point(21, 161);
		((Control)lblReportFormat).Name = "lblReportFormat";
		((Control)lblReportFormat).Size = new Size(77, 16);
		((Control)lblReportFormat).TabIndex = 8;
		((Control)lblReportFormat).Text = "Report &Format";
		((ListControl)cmbReportFormat).DisplayMember = "1";
		cmbReportFormat.DropDownStyle = (ComboBoxStyle)2;
		cmbReportFormat.Items.AddRange(new object[3] { "XML", "HTML", "TXT" });
		((Control)cmbReportFormat).Location = new Point(209, 157);
		((Control)cmbReportFormat).Name = "cmbReportFormat";
		((Control)cmbReportFormat).Size = new Size(121, 21);
		((Control)cmbReportFormat).TabIndex = 9;
		((Control)lblSpeedServerUploadPath).AutoSize = true;
		((Control)lblSpeedServerUploadPath).Location = new Point(18, 52);
		((Control)lblSpeedServerUploadPath).Name = "lblSpeedServerUploadPath";
		((Control)lblSpeedServerUploadPath).Size = new Size(167, 16);
		((Control)lblSpeedServerUploadPath).TabIndex = 2;
		((Control)lblSpeedServerUploadPath).Text = "&SPEED Server Upload Pathname";
		lblSpeedServerUploadPath.TextAlign = (ContentAlignment)32;
		((Control)txtSpeedServerUploadPath).Location = new Point(209, 50);
		((Control)txtSpeedServerUploadPath).Name = "txtSpeedServerUploadPath";
		((Control)txtSpeedServerUploadPath).Size = new Size(224, 20);
		((Control)txtSpeedServerUploadPath).TabIndex = 3;
		((Control)txtSpeedServerUploadPath).Text = "";
		((Control)txtSpeedServerUploadPath).Validating += txtSpeedServerUploadPath_Validating;
		((Control)this).Controls.Add((Control)(object)lblSpeedServerUploadPath);
		((Control)this).Controls.Add((Control)(object)txtSpeedServerUploadPath);
		((Control)this).Controls.Add((Control)(object)cmbReportFormat);
		((Control)this).Controls.Add((Control)(object)lblReportFormat);
		((Control)this).Controls.Add((Control)(object)txtDefaultUploadFilename);
		((Control)this).Controls.Add((Control)(object)lblUploadFileName);
		((Control)this).Controls.Add((Control)(object)lblDefaultDowloadFileName);
		((Control)this).Controls.Add((Control)(object)lblSpeedServerDownloadPath);
		((Control)this).Controls.Add((Control)(object)txtDefaultDownloadFilename);
		((Control)this).Controls.Add((Control)(object)txtSpeedServerDownloadPath);
		((Control)this).Name = "SpeedConfigurationPage";
		((Control)this).Size = new Size(448, 200);
		((Control)this).ResumeLayout(false);
	}

	public void Initialize()
	{
		((Control)txtDefaultDownloadFilename).Text = speedConfiguration.DownloadReportFileName;
		((Control)txtDefaultUploadFilename).Text = speedConfiguration.UploadReportFileName;
		((Control)txtSpeedServerDownloadPath).Text = speedConfiguration.SpeedServerDownloadPath;
		((Control)txtSpeedServerUploadPath).Text = speedConfiguration.SpeedServerUploadPath;
		((Control)cmbReportFormat).Text = speedConfiguration.ReportFormat;
	}

	public void SetOptions()
	{
		speedConfiguration.DownloadReportFileName = ((Control)txtDefaultDownloadFilename).Text;
		speedConfiguration.UploadReportFileName = ((Control)txtDefaultUploadFilename).Text;
		speedConfiguration.SpeedServerDownloadPath = ((Control)txtSpeedServerDownloadPath).Text;
		speedConfiguration.SpeedServerUploadPath = ((Control)txtSpeedServerUploadPath).Text;
		speedConfiguration.ReportFormat = ((Control)cmbReportFormat).Text;
		speedConfiguration.Save();
	}

	private void txtSpeedServerDownloadPath_Validating(object sender, CancelEventArgs e)
	{
		//IL_0042: Unknown result type (might be due to invalid IL or missing references)
		e.Cancel = false;
		if (!IsSpeedServerPathValid(((Control)txtSpeedServerDownloadPath).Text, "Download"))
		{
			MessageBox.Show(resourceManager.GetString("InvalidSpeedPath"), resourceManager.GetString("MessageBoxCaption"), (MessageBoxButtons)0, (MessageBoxIcon)48);
			((Control)txtSpeedServerDownloadPath).Select();
			e.Cancel = true;
		}
	}

	private void txtSpeedServerUploadPath_Validating(object sender, CancelEventArgs e)
	{
		//IL_0042: Unknown result type (might be due to invalid IL or missing references)
		e.Cancel = false;
		if (!IsSpeedServerPathValid(((Control)txtSpeedServerUploadPath).Text, "Upload"))
		{
			MessageBox.Show(resourceManager.GetString("InvalidSpeedPath"), resourceManager.GetString("MessageBoxCaption"), (MessageBoxButtons)0, (MessageBoxIcon)48);
			((Control)txtSpeedServerUploadPath).Select();
			e.Cancel = true;
		}
	}

	private void txtDefaultDownloadFilename_Validating(object sender, CancelEventArgs e)
	{
		e.Cancel = false;
		if (!IsReportPathValid(((Control)txtDefaultDownloadFilename).Text) || AreReportFilenamesSame())
		{
			((Control)txtDefaultDownloadFilename).Select();
			e.Cancel = true;
		}
	}

	private void txtDefaultUploadFilename_Validating(object sender, CancelEventArgs e)
	{
		e.Cancel = false;
		if (!IsReportPathValid(((Control)txtDefaultUploadFilename).Text) || AreReportFilenamesSame())
		{
			((Control)txtDefaultUploadFilename).Select();
			e.Cancel = true;
		}
	}

	private bool IsSpeedServerPathValid(string speedPath, string SpeedServerPathType)
	{
		//IL_0033: Unknown result type (might be due to invalid IL or missing references)
		//IL_00d5: Unknown result type (might be due to invalid IL or missing references)
		//IL_0109: Unknown result type (might be due to invalid IL or missing references)
		//IL_009e: Unknown result type (might be due to invalid IL or missing references)
		bool flag = speedPath.Length >= 3;
		if (!flag)
		{
			MessageBox.Show(resourceManager.GetString("EmptySpeedServerPath"), resourceManager.GetString("MessageBoxCaption"), (MessageBoxButtons)0, (MessageBoxIcon)48);
		}
		else if (!speedPath.StartsWith("\\"))
		{
			flag = char.IsLetter(speedPath[0]) && speedPath[1] == ':' && speedPath[2] == '\\';
			if (!flag)
			{
				string text = string.Format(resourceManager.GetString("InvalidSpeedServerPath"), SpeedServerPathType);
				MessageBox.Show(text, resourceManager.GetString("MessageBoxCaption"), (MessageBoxButtons)0, (MessageBoxIcon)64);
			}
		}
		if (flag && ContainsInvalidCharacter(speedPath))
		{
			flag = false;
			MessageBox.Show(resourceManager.GetString("InvalidCharactersInSpeedPath"), resourceManager.GetString("MessageBoxCaption"), (MessageBoxButtons)0, (MessageBoxIcon)16);
		}
		if (flag && !Directory.Exists(speedPath))
		{
			MessageBox.Show(resourceManager.GetString("SpeedPathMessage"), resourceManager.GetString("MessageBoxCaption"), (MessageBoxButtons)0, (MessageBoxIcon)48);
		}
		return flag;
	}

	private bool ContainsInvalidCharacter(string pathName)
	{
		char[] anyOf = new char[7] { '/', '*', '?', '"', '<', '>', '|' };
		int num = pathName.IndexOfAny(anyOf);
		return num != -1;
	}

	private bool IsFilenameValid(string fileName)
	{
		char[] anyOf = new char[1] { '\\' };
		int num = fileName.IndexOfAny(anyOf);
		bool flag = num == -1;
		if (flag)
		{
			flag = !ContainsInvalidCharacter(fileName);
		}
		return flag;
	}

	private bool IsReportPathValid(string path)
	{
		//IL_002d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0063: Unknown result type (might be due to invalid IL or missing references)
		bool result = true;
		if (path.Length == 0)
		{
			MessageBox.Show(resourceManager.GetString("EmptyReportFile"), resourceManager.GetString("MessageBoxCaption"), (MessageBoxButtons)0, (MessageBoxIcon)48);
			result = false;
		}
		else if (!IsFilenameValid(path))
		{
			MessageBox.Show(resourceManager.GetString("InvalidReportPrefix"), resourceManager.GetString("MessageBoxCaption"), (MessageBoxButtons)0, (MessageBoxIcon)48);
			result = false;
		}
		return result;
	}

	private bool AreReportFilenamesSame()
	{
		//IL_0042: Unknown result type (might be due to invalid IL or missing references)
		bool result = false;
		if (((Control)txtDefaultDownloadFilename).Text == ((Control)txtDefaultUploadFilename).Text)
		{
			MessageBox.Show(resourceManager.GetString("IdenticalReportFileNames"), resourceManager.GetString("MessageBoxCaption"), (MessageBoxButtons)0, (MessageBoxIcon)48);
			result = true;
		}
		return result;
	}
}
public class SpeedDownload
{
	private const string NotAvailable = "Not Available";

	internal static short MsgMissingFile = 900;

	internal static short MsgZeroSizeFile = 901;

	internal static short MsgCopySuccess = 902;

	internal static short MsgCopyFailure = 903;

	internal static short MsgDownloadFailure = 904;

	internal static short MsgInvalidLine = 905;

	internal static short MsgSubfileCopyError = 906;

	internal static short MsgDownloadSuccess = 913;

	internal static short MsgMoveError = 914;

	internal static short DataCheckFileNotPresent = 920;

	internal static short MsgFileWithoutExtension = 916;

	internal static short MsgInvalidDownloadServerPath = 917;

	internal static short MsgNoFilesPresent = 918;

	internal static short MsgNonExistentControlFile = 919;

	internal static int FileTypePosition = 35;

	internal static int SubfileTypeStart = 4;

	internal static int SubfileTypeLength = 2;

	internal static string FullFolderName = "full";

	private bool forCLI;

	private bool cliSuccess;

	internal static string FullDownloadControlFilename = "ENGDL1.DAT";

	internal static string DataCheckFilename = "Datacheckfile.txt";

	internal static int PartNumberStart = 2;

	internal static int RevisionNumberStart = 14;

	internal static string Slash = "\\";

	internal static string ExtensionSeparator = ".";

	internal static string Star = "*";

	internal static string Zip = "zip";

	private SpeedConfiguration configuration;

	private ResourceManager resourceManager;

	private DownloadType downloadType;

	private SpeedTransferReport reporter;

	private ArrayList downloadedFiles;

	private string _speedDownloadPath = string.Empty;

	private UnZip unZip = new UnZip();

	public event ProgressChangedEventHandler ProgressChangedEvent;

	public event EventHandler DownloadCompleteEvent;

	public SpeedDownload(DownloadType downloadType, SpeedConfiguration configuration, SpeedTransferReport reporter, ResourceManager resourceManager, bool caltermCLI = false)
	{
		bool flag = false;
		if (configuration == null)
		{
			throw new ArgumentNullException("configuration");
		}
		if (resourceManager == null)
		{
			throw new ArgumentNullException("resource Manager");
		}
		if (reporter == null)
		{
			throw new ArgumentNullException("upload reporter");
		}
		this.downloadType = downloadType;
		this.configuration = configuration;
		this.reporter = reporter;
		this.resourceManager = resourceManager;
		_speedDownloadPath = this.configuration.SpeedServerDownloadPath;
		forCLI = caltermCLI;
		if (!IsSpeedTransferSupported())
		{
			string message = string.Format(resourceManager.GetString(MessageIDs.UnsupportedProduct.ToString()), configuration.ProductID);
			throw new SpeedTransferException(message);
		}
		if (configuration.CESProduct())
		{
			_speedDownloadPath += "_CES";
		}
		downloadedFiles = new ArrayList();
	}

	private bool IsSpeedTransferSupported()
	{
		bool flag = false;
		IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
		if (productInformationService.GetProductInformation(configuration.ProductID, ProductInformationType.SpeedSupport).Equals("Not Available"))
		{
			return false;
		}
		return true;
	}

	public void Start()
	{
		string text = string.Empty;
		try
		{
			cliSuccess = false;
			string speedServerDownloadPath = GetSpeedServerDownloadPath();
			if (IsDownloadFolderEmpty(speedServerDownloadPath))
			{
				reporter.AddEntry(speedServerDownloadPath, ReportEntryType.ErrorEntry, MsgNoFilesPresent, resourceManager.GetString(MsgNoFilesPresent.ToString()));
				throw new FileNotFoundException(resourceManager.GetString(MsgNoFilesPresent.ToString()));
			}
			RaiseProgressEvent(resourceManager.GetString("CleaningDownloadDirectory"));
			ClearLocalDownloadDirectory();
			string controlFileName = GetControlFileName();
			RaiseProgressEvent(resourceManager.GetString("InitDownload"));
			ArrayList filesList = GetFilesList(controlFileName);
			RaiseProgressEvent(resourceManager.GetString("StartDownloadProcess"));
			DownloadAllFiles(filesList);
			RaiseProgressEvent(resourceManager.GetString("ValidatingDownload"));
			Validate();
			DeleteFiles(configuration.ProductCalPath, "");
			FinalizeDownload();
			cliSuccess = true;
		}
		catch (DirectoryNotFoundException ex)
		{
			if (!forCLI)
			{
				EventLogger.Error("SPEED Download", ex.Message);
			}
			else
			{
				text = ex.Message;
			}
		}
		catch (FileNotFoundException ex2)
		{
			if (!forCLI)
			{
				EventLogger.Error("SPEED Download", ex2.Message);
			}
			else
			{
				text = ex2.Message;
			}
		}
		catch (UnauthorizedAccessException ex3)
		{
			if (!forCLI)
			{
				EventLogger.Error("SPEED Download", ex3.Message);
			}
			else
			{
				text = ex3.Message;
			}
		}
		finally
		{
			try
			{
				string text2 = reporter.SaveToFile();
				if (!forCLI)
				{
					ProcessCompleteEventArgs processCompleteEventArgs = new ProcessCompleteEventArgs(successFlag: true, text);
					RaiseDownloadCompleteEvent(processCompleteEventArgs);
					Process.Start(text2);
				}
				else
				{
					string text3 = string.Empty;
					if (text.Length > 0)
					{
						text3 = text + " ";
					}
					text3 += $"SPEED Download report file: {text2}.";
					ProcessCompleteEventArgs processCompleteEventArgs2 = new ProcessCompleteEventArgs(cliSuccess, text3);
					RaiseDownloadCompleteEvent(processCompleteEventArgs2);
				}
				if (Directory.Exists(configuration.TempDownloadPath))
				{
					string[] directories = Directory.GetDirectories(configuration.TempDownloadPath);
					for (int i = 0; i < directories.Length; i++)
					{
						Directory.Delete(directories[i], recursive: true);
					}
				}
			}
			catch (SpeedTransferException ex4)
			{
				if (!forCLI)
				{
					EventLogger.Error("SPEED Download", ex4.Message);
				}
				else
				{
					text += ex4.Message;
				}
			}
			catch (UnauthorizedAccessException ex5)
			{
				if (!forCLI)
				{
					EventLogger.Error("SPEED Download", ex5.Message);
				}
				else
				{
					text += ex5.Message;
				}
			}
			finally
			{
				RaiseProgressCompleteEvent();
			}
		}
	}

	protected void RaiseDownloadCompleteEvent(ProcessCompleteEventArgs processCompleteEventArgs)
	{
		if (this.DownloadCompleteEvent != null)
		{
			this.DownloadCompleteEvent(this, processCompleteEventArgs);
		}
	}

	protected void RaiseProgressEvent(string status, int total, int current)
	{
		if (this.ProgressChangedEvent != null && !forCLI)
		{
			ProgressEventArgs progress = new ProgressEventArgs(status, total, current);
			this.ProgressChangedEvent(this, progress);
		}
	}

	protected void RaiseProgressEvent(string status)
	{
		if (this.ProgressChangedEvent != null && !forCLI)
		{
			ProgressEventArgs progress = new ProgressEventArgs(status, 0, 0);
			this.ProgressChangedEvent(this, progress);
		}
	}

	private void RaiseProgressCompleteEvent()
	{
		if (this.DownloadCompleteEvent != null)
		{
			this.DownloadCompleteEvent(this, EventArgs.Empty);
		}
	}

	private string GetSpeedServerDownloadPath()
	{
		string pathName = _speedDownloadPath;
		AppendSlash(ref pathName);
		if (downloadType == DownloadType.Full)
		{
			pathName = pathName + FullFolderName + Slash;
		}
		string text = pathName;
		pathName = text + configuration.ProductID + Slash + Zip + Slash;
		if (!Directory.Exists(pathName))
		{
			string message = string.Format(resourceManager.GetString("InvalidSpeedServerPath"), pathName);
			reporter.AddEntry(pathName, ReportEntryType.ErrorEntry, MsgInvalidDownloadServerPath, message);
			throw new DirectoryNotFoundException(message);
		}
		return pathName;
	}

	private string GetLocalDownloadDirectory()
	{
		string pathName = configuration.TempDownloadPath;
		AppendSlash(ref pathName);
		return pathName;
	}

	private int GetNumberOfFilesInDirectory(string path)
	{
		int num = 0;
		string[] directories = Directory.GetDirectories(path);
		string[] array = directories;
		foreach (string path2 in array)
		{
			num += GetNumberOfFilesInDirectory(path2);
		}
		string[] files = Directory.GetFiles(path);
		return num + files.Length;
	}

	private void ClearLocalDownloadDirectory()
	{
		string localDownloadDirectory = GetLocalDownloadDirectory();
		if (!Directory.Exists(localDownloadDirectory))
		{
			Directory.CreateDirectory(localDownloadDirectory);
		}
		if (GetNumberOfFilesInDirectory(localDownloadDirectory) != 0)
		{
			DeleteFiles(localDownloadDirectory, "");
		}
	}

	private string GetControlFileName()
	{
		string pathName = _speedDownloadPath;
		AppendSlash(ref pathName);
		if (downloadType == DownloadType.Full)
		{
			string text = pathName;
			return text + FullFolderName + Slash + configuration.ProductID + Slash + Zip + Slash + FullDownloadControlFilename;
		}
		return string.Empty;
	}

	private string GetDataCheckFileName()
	{
		string pathName = _speedDownloadPath;
		AppendSlash(ref pathName);
		if (downloadType == DownloadType.Full)
		{
			string text = pathName;
			return text + FullFolderName + Slash + configuration.ProductID + Slash + Zip + Slash + DataCheckFilename;
		}
		return string.Empty;
	}

	private ArrayList GetFilesList(string controlFile)
	{
		if (controlFile == null || controlFile.Length == 0)
		{
			throw new ArgumentNullException("controlFile");
		}
		ArrayList arrayList = null;
		if (File.Exists(controlFile))
		{
			arrayList = new ArrayList();
			TextReader textReader = null;
			try
			{
				textReader = new StreamReader(controlFile);
				for (string text = textReader.ReadLine(); text != null; text = textReader.ReadLine())
				{
					if (text.Length != 0)
					{
						arrayList.Add(text);
					}
				}
			}
			finally
			{
				textReader.Close();
			}
			if (arrayList != null && arrayList.Count == 0)
			{
				reporter.AddEntry(_speedDownloadPath, ReportEntryType.ErrorEntry, MsgNoFilesPresent, resourceManager.GetString(MsgNoFilesPresent.ToString()));
				throw new FileNotFoundException(resourceManager.GetString(MsgNoFilesPresent.ToString()), controlFile);
			}
			return arrayList;
		}
		reporter.AddEntry(controlFile, ReportEntryType.ErrorEntry, MsgNonExistentControlFile, resourceManager.GetString("NonExistentControlFile"));
		throw new FileNotFoundException(resourceManager.GetString("NonExistentControlFile"), controlFile);
	}

	private void DownloadOneFile(string line)
	{
		if (line == null || line.Length == 0)
		{
			throw new ArgumentNullException("line");
		}
		DownloadFileInformation downloadFileInformation = null;
		downloadFileInformation = GetDownloadFileInformation(line);
		if (downloadFileInformation == null)
		{
			return;
		}
		if (!File.Exists(downloadFileInformation.SpeedFileName))
		{
			reporter.AddEntry(downloadFileInformation.SpeedFileName, ReportEntryType.ErrorEntry, MsgCopyFailure, resourceManager.GetString(MsgCopyFailure.ToString()));
			return;
		}
		CreateLocalDirectory(downloadFileInformation.LocalFileName);
		try
		{
			if (downloadFileInformation.DistributionGroup.Trim().Length == 0)
			{
				string text = unZip.DoUnZip(downloadFileInformation.SpeedFileName, downloadFileInformation.FilePathToExtract);
				if (text != "")
				{
					downloadFileInformation.ExtractedFileName = text;
					downloadFileInformation.FileType = downloadFileInformation.GetFileTypeFromCode(line[FileTypePosition], text);
				}
				else
				{
					reporter.AddEntry(downloadFileInformation.SpeedFileName, ReportEntryType.ErrorEntry, MsgDownloadFailure, "There was a problem in extracting the SPEED zipped file");
				}
			}
			else
			{
				downloadFileInformation.ExtractedFileName = null;
				downloadFileInformation.FileType = downloadFileInformation.GetFileTypeFromCode(line[FileTypePosition], downloadFileInformation.LocalFileName);
				File.Copy(downloadFileInformation.SpeedFileName, downloadFileInformation.LocalFileName);
			}
			downloadedFiles.Add(downloadFileInformation);
		}
		catch (IOException ex)
		{
			reporter.AddEntry(downloadFileInformation.LocalFileName, ReportEntryType.ErrorEntry, MsgCopyFailure, resourceManager.GetString(MsgCopyFailure.ToString()) + "\r\n" + ex.Message);
		}
		catch (Exception ex2)
		{
			reporter.AddEntry(downloadFileInformation.SpeedFileName, ReportEntryType.ErrorEntry, MsgDownloadFailure, resourceManager.GetString(MsgDownloadFailure.ToString()) + "\r\n" + ex2.Message);
		}
	}

	private DownloadFileInformation GetDownloadFileInformation(string headerRecord)
	{
		if (headerRecord == null)
		{
			throw new ArgumentNullException("header Record");
		}
		DownloadFileInformation result = null;
		try
		{
			string text = headerRecord.Substring(headerRecord.LastIndexOf(";") + 1);
			if (text.Substring(text.LastIndexOf(".")).Length > 1)
			{
				result = new DownloadFileInformation(headerRecord, configuration.TempDownloadPath);
			}
			else
			{
				reporter.AddEntry(text, ReportEntryType.ErrorEntry, MsgFileWithoutExtension, resourceManager.GetString(MsgFileWithoutExtension.ToString()));
			}
		}
		catch (InvalidRecordException)
		{
			string message = string.Format(resourceManager.GetString(MsgInvalidLine.ToString()), headerRecord);
			reporter.AddEntry("Error", ReportEntryType.ErrorEntry, MsgInvalidLine, message);
		}
		catch (InvalidFileFormatException ex2)
		{
			string text2 = string.Format(resourceManager.GetString(MsgInvalidLine.ToString()), headerRecord);
			reporter.AddEntry("Error", ReportEntryType.ErrorEntry, MsgInvalidLine, text2 + " Error: " + ex2.Message);
		}
		catch (Exception ex3)
		{
			string text3 = string.Format(resourceManager.GetString(MsgInvalidLine.ToString()), headerRecord);
			reporter.AddEntry("Error", ReportEntryType.ErrorEntry, MsgInvalidLine, text3 + " Error: " + ex3.Message);
		}
		return result;
	}

	private void DownloadAllFiles(ArrayList fileList)
	{
		if (fileList == null)
		{
			throw new ArgumentNullException("file List");
		}
		string text = null;
		for (int i = 0; i < fileList.Count; i++)
		{
			text = (string)fileList[i];
			if (forCLI)
			{
				Console.Write($"\rDownloading.....{i}/{fileList.Count.ToString()}");
			}
			else
			{
				RaiseProgressEvent(resourceManager.GetString("DownloadingFile"), fileList.Count, i);
			}
			DownloadOneFile(text);
		}
		if (forCLI)
		{
			Console.WriteLine();
		}
	}

	private void Validate()
	{
		//IL_00fc: Unknown result type (might be due to invalid IL or missing references)
		string dataCheckFileName = GetDataCheckFileName();
		if (File.Exists(dataCheckFileName))
		{
			TextReader textReader = new StreamReader(dataCheckFileName);
			string text = textReader.ReadLine();
			text = textReader.ReadLine();
			while (text != null)
			{
				if (text.Length != 0)
				{
					string partNumber = DownloadFileInformation.GetPartNumber(text, PartNumberStart);
					if (partNumber.ToUpper().IndexOf("TOTAL") != 0)
					{
						partNumber = partNumber + "." + text.Substring(RevisionNumberStart, DownloadFileInformation.RevisionLevelLength);
						if (!ExistsInDownloadDirectory(partNumber))
						{
							reporter.AddEntry(partNumber, ReportEntryType.MissingFileEntry, MsgMissingFile, resourceManager.GetString(MsgMissingFile.ToString()));
						}
					}
					text = textReader.ReadLine();
					continue;
				}
				throw InvalidRecordException.New(MessageIDs.EmptyRecordInENGDL, resourceManager.GetString("InvalidDataCheckFile"), text);
			}
		}
		else if (!forCLI)
		{
			MessageBox.Show(DataCheckFileNotPresent + " - " + resourceManager.GetString(DataCheckFileNotPresent.ToString()), "SPEED Download");
		}
	}

	private bool ExistsInDownloadDirectory(string fileName)
	{
		bool result = false;
		string tempDownloadPath = configuration.TempDownloadPath;
		string[] directories = Directory.GetDirectories(tempDownloadPath);
		for (int i = 0; i < directories.Length; i++)
		{
			AppendSlash(ref directories[i]);
			if (File.Exists(directories[i] + fileName))
			{
				result = true;
				break;
			}
		}
		return result;
	}

	private void FinalizeSubfile(DownloadFileInformation fileInfo)
	{
		if (fileInfo == null)
		{
			throw new ArgumentNullException("download file information");
		}
		try
		{
			TextReader textReader = new StreamReader(fileInfo.ExtractedFileName);
			string text = textReader.ReadLine();
			if (text[0] != '*' || text[1] != 'C')
			{
				text = textReader.ReadLine();
			}
			textReader.Close();
			byte type = byte.Parse(text.Substring(SubfileTypeStart, SubfileTypeLength), NumberStyles.AllowHexSpecifier);
			string destinationPath = GetDestinationPath(type, fileInfo.PartNumber, fileInfo.RevisionLevel);
			DeleteFiles(configuration.ProductCalPath, fileInfo.PartNumber);
			MoveFile(fileInfo, destinationPath);
		}
		catch (Exception ex)
		{
			reporter.AddEntry(fileInfo.LocalFileName, ReportEntryType.ErrorEntry, MsgSubfileCopyError, resourceManager.GetString(MsgSubfileCopyError.ToString()) + "\r\n" + ex.Message);
		}
	}

	private string GetDestinationPath(byte type, string partNumber, short revisionLevel)
	{
		string pathName = configuration.ProductCalPath;
		AppendSlash(ref pathName);
		string text = revisionLevel.ToString();
		if (text.Length == 1)
		{
			text = "0" + text;
		}
		return pathName + string.Format("{0," + partNumber.Length + "}.{1,1}{2,2}", partNumber, type, text);
	}

	private string GetDestinationPathForSupportFile(DownloadFileInformation fileInfo)
	{
		string text = configuration.ProductSupportPath;
		if (!text.EndsWith("\\"))
		{
			text += Slash;
		}
		switch (fileInfo.FileType)
		{
		case FileType.ControlFile:
		{
			int num2 = fileInfo.SpeedFileName.LastIndexOf('\\');
			return text + fileInfo.SpeedFileName.Substring(num2 + 1);
		}
		case FileType.BOTFile:
			return text + fileInfo.PartNumber + ".bot";
		case FileType.E2MFile:
			return text + fileInfo.PartNumber + ".e2m";
		case FileType.ECFGFile:
			return text + fileInfo.PartNumber + ".ecfg";
		case FileType.HDRFile:
			return text + fileInfo.PartNumber + ".hdr";
		case FileType.RIOFile:
			return text + fileInfo.PartNumber + ".rio";
		case FileType.NVDFile:
			return text + fileInfo.PartNumber + ".nvd";
		case FileType.PCFGFile:
			return text + fileInfo.PartNumber + ".pcfg";
		case FileType.Other:
			return text + fileInfo.PartNumber + ".other";
		default:
		{
			int num = fileInfo.SpeedFileName.LastIndexOf(Slash);
			return text + fileInfo.SpeedFileName.Substring(num + 1);
		}
		}
	}

	private void CreateLocalDirectory(string localFileName)
	{
		string path = localFileName[..localFileName.LastIndexOf('\\')];
		if (!Directory.Exists(path))
		{
			Directory.CreateDirectory(path);
		}
	}

	private void FinalizeDownload()
	{
		for (int i = 0; i < downloadedFiles.Count; i++)
		{
			DownloadFileInformation downloadFileInformation = (DownloadFileInformation)downloadedFiles[i];
			if (downloadFileInformation.ExtractedFileName == null)
			{
				CompleteFinalizeProcess(downloadFileInformation, downloadFileInformation.LocalFileName);
			}
			else
			{
				CompleteFinalizeProcess(downloadFileInformation, downloadFileInformation.ExtractedFileName);
			}
		}
	}

	private void CompleteFinalizeProcess(DownloadFileInformation fileInfo, string fileName)
	{
		if (fileInfo == null)
		{
			throw new ArgumentNullException("fileInfo");
		}
		if (fileName == null || fileName.Length == 0)
		{
			throw new ArgumentNullException("fileName");
		}
		if (!File.Exists(fileName))
		{
			return;
		}
		if (fileInfo.ReleasePhase == ReleasePhase.Obsolete)
		{
			if (configuration.PostDownloadAction == PostDownloadAction.DeleteFromCal)
			{
				DeleteFiles(configuration.ProductCalPath, fileInfo.PartNumber);
			}
			else
			{
				MoveFiles(configuration.ProductCalPath, fileInfo.PartNumber, configuration.ProductUnrlCalPath);
			}
			return;
		}
		if (fileInfo.FileType == FileType.Subfile)
		{
			FinalizeSubfile(fileInfo);
			return;
		}
		if (fileInfo.FileType == FileType.Calibration)
		{
			string destinationPath = GetDestinationPath(0, fileInfo.PartNumber, fileInfo.RevisionLevel);
			DeleteFiles(configuration.ProductCalPath, fileInfo.PartNumber);
			MoveFile(fileInfo, destinationPath);
			return;
		}
		if (fileInfo.FileType == FileType.SPEEDFile)
		{
			string destinationPathForSupportFile = GetDestinationPathForSupportFile(fileInfo);
			File.Delete(destinationPathForSupportFile);
			MoveFile(fileInfo, destinationPathForSupportFile);
			return;
		}
		string destinationPathForSupportFile2 = GetDestinationPathForSupportFile(fileInfo);
		int num = destinationPathForSupportFile2.LastIndexOf(Slash);
		int num2 = destinationPathForSupportFile2.LastIndexOf(ExtensionSeparator);
		string startsWith = destinationPathForSupportFile2.Substring(num + 1, num2 - num - 1);
		DeleteFiles(configuration.ProductSupportPath, startsWith);
		MoveFile(fileInfo, destinationPathForSupportFile2);
	}

	private void MoveFile(DownloadFileInformation fileInfo, string outputFileName)
	{
		if (fileInfo == null)
		{
			throw new ArgumentNullException("fileInfo object");
		}
		if (outputFileName == null || outputFileName.Length == 0)
		{
			throw new ArgumentNullException("output file name");
		}
		int num = outputFileName.LastIndexOf('\\');
		if (num != -1)
		{
			string path = outputFileName.Substring(0, num);
			if (!Directory.Exists(path))
			{
				Directory.CreateDirectory(path);
			}
		}
		try
		{
			if (fileInfo.ExtractedFileName == null)
			{
				File.Move(fileInfo.LocalFileName, outputFileName);
			}
			else
			{
				File.Move(fileInfo.ExtractedFileName, outputFileName);
			}
			string message = string.Format(resourceManager.GetString(MsgDownloadSuccess.ToString()), outputFileName);
			reporter.AddEntry(fileInfo.SpeedFileName, ReportEntryType.DownloadedFileEntry, MsgDownloadSuccess, message);
		}
		catch (IOException ex)
		{
			string text = string.Format(resourceManager.GetString(MsgMoveError.ToString()), outputFileName);
			reporter.AddEntry(fileInfo.SpeedFileName, ReportEntryType.ErrorEntry, MsgMoveError, text + ". " + ex.Message);
		}
	}

	private void DeleteFiles(string path, string startsWith)
	{
		if (path == null || path.Length == 0)
		{
			throw new ArgumentNullException("Path");
		}
		if (startsWith == null)
		{
			throw new ArgumentNullException("startsWith");
		}
		if (Directory.Exists(path))
		{
			string[] directories = Directory.GetDirectories(path);
			string[] array = directories;
			foreach (string path2 in array)
			{
				DeleteFiles(path2, startsWith);
			}
			string[] files = Directory.GetFiles(path, startsWith + Star);
			string[] array2 = files;
			foreach (string path3 in array2)
			{
				File.Delete(path3);
			}
		}
	}

	private void MoveFiles(string srcPath, string startsWith, string destPath)
	{
		if (srcPath == null || srcPath.Length == 0)
		{
			throw new ArgumentNullException("Source Path");
		}
		if (destPath == null || destPath.Length == 0)
		{
			throw new ArgumentNullException("Destination Path");
		}
		if (startsWith == null || startsWith.Length == 0)
		{
			throw new ArgumentNullException("starting pattern");
		}
		AppendSlash(ref destPath);
		string[] files = Directory.GetFiles(srcPath, startsWith + Star);
		string text = null;
		int num = 0;
		string[] array = files;
		foreach (string text2 in array)
		{
			num = text2.LastIndexOf('\\');
			text = destPath + text2.Substring(num + 1);
			File.Move(text2, text);
		}
	}

	private void AppendSlash(ref string pathName)
	{
		if (pathName != null && pathName[pathName.Length - 1] != '\\')
		{
			pathName += Slash;
		}
	}

	private bool IsDownloadFolderEmpty(string speedServerDownloadPath)
	{
		bool result = false;
		string[] files = Directory.GetFiles(speedServerDownloadPath, "*");
		if (files.Length == 0)
		{
			result = true;
		}
		return result;
	}
}
public class SpeedPrepare
{
	private const string space = " ";

	internal static short MsgPrepareSuccess = 907;

	internal static short MsgPrepareFailure = 908;

	internal static short MsgFileAlreadyPrepared = 915;

	private SpeedConfiguration configuration;

	private ResourceManager resourceManager;

	private SpeedTransferReport reporter;

	public SpeedPrepare(SpeedConfiguration configuration, ResourceManager resourceManager, SpeedTransferReport reporter)
	{
		if (configuration == null)
		{
			throw new ArgumentNullException("configuration");
		}
		if (resourceManager == null)
		{
			throw new ArgumentNullException("resource Manager");
		}
		if (reporter == null)
		{
			throw new ArgumentNullException("upload reporter");
		}
		this.configuration = configuration;
		this.resourceManager = resourceManager;
		this.reporter = reporter;
	}

	public void Prepare(SpeedPreparedFiles preparedFiles)
	{
		if (preparedFiles == null)
		{
			throw new ArgumentNullException("preparedFiles");
		}
		if (!Directory.Exists(configuration.TempUploadPath))
		{
			Directory.CreateDirectory(configuration.TempUploadPath);
		}
		int count = preparedFiles.Count;
		for (int i = 0; i < count; i++)
		{
			PreparedFileInformation preparedFileInformation = preparedFiles[i];
			string.Format(resourceManager.GetString("PreparingFile"), preparedFileInformation.Filename);
			CopyToUploadDirectory(preparedFileInformation.SourceFilename, preparedFileInformation.PreparedFileName);
		}
	}

	public void CheckFile(string fileName, FileType fileType)
	{
		if (fileName == null || fileName.Length == 0)
		{
			throw new ArgumentNullException("file name");
		}
		int num = fileName.LastIndexOf('\\');
		string text = fileName.Substring(num + 1);
		if (text.Length > 30)
		{
			throw NewFileValidationException(Facility.SpeedTransfer, 5, resourceManager.GetString("InvalidFileLength"), fileName);
		}
		if (text.IndexOf(" ") != -1)
		{
			throw new FileNameWithSpaceException();
		}
		CheckFileSize(fileName);
		switch (fileType)
		{
		case FileType.Calibration:
			CheckCalFile(fileName);
			break;
		case FileType.E2MFile:
			CheckE2MFile(fileName);
			break;
		case FileType.ECFGFile:
		case FileType.PCFGFile:
			CheckECFGFile(fileName);
			break;
		case FileType.HDRFile:
			CheckHeaderFile(fileName);
			break;
		case FileType.Subfile:
			CheckSubile(fileName);
			break;
		case FileType.RIOFile:
			CheckRIOFile(fileName);
			break;
		default:
			CheckOtherFile(fileName);
			break;
		}
	}

	public FileType GetFileTypeFromFilename(string fileName)
	{
		if (fileName == null || fileName.Length == 0)
		{
			throw new ArgumentNullException("file name");
		}
		FileType result = FileType.Subfile;
		int num = fileName.LastIndexOf('.');
		if (num != -1)
		{
			switch (fileName.Substring(num + 1).ToLower())
			{
			case "cal":
			case "xcal":
				result = FileType.Calibration;
				break;
			case "e2m":
				result = FileType.E2MFile;
				break;
			case "ecfg":
				result = FileType.ECFGFile;
				break;
			case "pcfg":
				result = FileType.PCFGFile;
				break;
			case "hdr":
				result = FileType.HDRFile;
				break;
			case "rio":
				result = FileType.RIOFile;
				break;
			case "bot":
				result = FileType.BOTFile;
				break;
			case "nvd":
				result = FileType.NVDFile;
				break;
			case "dat":
				result = FileType.ControlFile;
				break;
			case "txt":
				result = FileType.SPEEDFile;
				break;
			}
		}
		else
		{
			result = FileType.Other;
		}
		return result;
	}

	private void CheckE2MFile(string e2mFile)
	{
		CheckECFGFile(e2mFile);
	}

	private void CheckECFGFile(string ecfgFile)
	{
		CRCFile cRCFile = new CRCFile();
		if (cRCFile.CheckConfigFileCRC(ecfgFile))
		{
			TextReader textReader = new StreamReader(ecfgFile);
			string contents;
			try
			{
				contents = textReader.ReadToEnd();
			}
			finally
			{
				textReader.Close();
			}
			if (!IsHeaderRecordSectionPresent(ref contents))
			{
				throw NewFileValidationException(Facility.SpeedTransfer, 6, resourceManager.GetString("InvalidConfigFile"), ecfgFile);
			}
			return;
		}
		string message = string.Format(resourceManager.GetString("InvalidCRC"), ecfgFile);
		throw NewCRCException(Facility.SpeedTransfer, 7, message, ecfgFile);
	}

	private void CheckCalFile(string calFile)
	{
		CRCFile cRCFile = new CRCFile();
		if (cRCFile.CheckCalFileCRC(calFile))
		{
			TextReader textReader = new StreamReader(calFile);
			string contents;
			try
			{
				contents = textReader.ReadToEnd();
			}
			finally
			{
				textReader.Close();
			}
			if (!IsHeaderRecordSectionPresent(ref contents))
			{
				throw NewFileValidationException(Facility.SpeedTransfer, 6, resourceManager.GetString("InvalidCalFile"), calFile);
			}
			int num = contents.IndexOf(':', 0);
			if (num == -1)
			{
				throw NewFileValidationException(Facility.SpeedTransfer, 1, resourceManager.GetString("InvalidCalFile"), calFile);
			}
			return;
		}
		string message = string.Format(resourceManager.GetString("InvalidCRC"), calFile);
		throw NewCRCException(Facility.SpeedTransfer, 7, message, calFile);
	}

	private bool IsHeaderRecordSectionPresent(ref string contents)
	{
		bool result = true;
		int num = contents.IndexOf("<compatibility_header>");
		if (num == -1)
		{
			num = contents.IndexOf("[Header Records]");
			if (num != -1)
			{
			}
		}
		else
		{
			int num2 = contents.IndexOf("</compatibility_header>", num);
			if (num2 == -1)
			{
				result = false;
			}
		}
		return result;
	}

	private void CheckHeaderFile(string headerFile)
	{
		CRCFile cRCFile = new CRCFile();
		if (!cRCFile.CheckHeaderFileCRC(headerFile))
		{
			string message = string.Format(resourceManager.GetString("InvalidCRC"), headerFile);
			throw NewCRCException(Facility.SpeedTransfer, 7, message, headerFile);
		}
	}

	private void CheckSubile(string subfile)
	{
		CRCFile cRCFile = new CRCFile();
		if (!cRCFile.CheckSubfileCRC(subfile))
		{
			string message = string.Format(resourceManager.GetString("InvalidCRC"), subfile);
			throw NewCRCException(Facility.SpeedTransfer, 7, message, subfile);
		}
	}

	private void CheckRIOFile(string riofile)
	{
		CRCFile cRCFile = new CRCFile();
		if (!cRCFile.CheckReConfigFileCRC(riofile))
		{
			string message = string.Format(resourceManager.GetString("InvalidCRC"), riofile);
			throw NewCRCException(Facility.SpeedTransfer, 7, message, riofile);
		}
	}

	private void CheckOtherFile(string otherFile)
	{
	}

	private void CheckFileSize(string fileName)
	{
		FileStream fileStream = new FileStream(fileName, FileMode.Open, FileAccess.Read);
		if (fileStream.Length == 0)
		{
			string message = string.Format(resourceManager.GetString("EmptyFile"), fileName);
			throw new SpeedTransferException(message);
		}
		fileStream.Close();
	}

	private void CopyToUploadDirectory(string sourceFile, string destinationFile)
	{
		if (sourceFile == null || sourceFile.Length == 0)
		{
			throw new ArgumentNullException("source file name");
		}
		if (destinationFile == null || destinationFile.Length == 0)
		{
			throw new ArgumentNullException("destination file name");
		}
		string text = configuration.TempUploadPath;
		if (!text.EndsWith("\\"))
		{
			text += "\\";
		}
		text += destinationFile;
		try
		{
			if (!File.Exists(text))
			{
				File.Copy(sourceFile, text);
				reporter.AddEntry(sourceFile, ReportEntryType.PreparedFileEntry, MsgPrepareSuccess, resourceManager.GetString(MsgPrepareSuccess.ToString()));
			}
			else
			{
				reporter.AddMessage(text, MsgFileAlreadyPrepared, resourceManager.GetString(MsgFileAlreadyPrepared.ToString()));
			}
		}
		catch (Exception ex)
		{
			reporter.AddEntry(text, ReportEntryType.ErrorEntry, MsgPrepareFailure, resourceManager.GetString(MsgPrepareFailure.ToString()) + ". " + ex.Message);
		}
	}

	private CRCException NewCRCException(Facility facility, short errId, string message, string filename, Exception inner)
	{
		CRCException ex = new CRCException(facility, errId, message, inner);
		ex.ContextData = filename;
		return ex;
	}

	private CRCException NewCRCException(Facility facility, short errId, string message, string filename)
	{
		return NewCRCException(facility, errId, message, filename, null);
	}

	private FileValidationException NewFileValidationException(Facility facility, short errId, string message, string filename, Exception inner)
	{
		FileValidationException ex = new FileValidationException(facility, errId, message, inner);
		ex.ContextData = filename;
		return ex;
	}

	private FileValidationException NewFileValidationException(Facility facility, short errId, string message, string filename)
	{
		return NewFileValidationException(facility, errId, message, filename, null);
	}
}
public class SpeedPreparedFiles
{
	internal static string PreparedFilesName = "PreparedFiles.xml";

	internal static string EJRPattern1 = "[A-Z,a-z]{2}[0-9,a-z,A-Z]{1}[0-9]{4}[-]{1}[0-9]{2}";

	internal static string EJRPattern2 = "[CR]{2}[0-9]{1}[0-9]{5}[-]{1}[0-9]{2}";

	internal static string PartNoPattern1 = "[0-9]{7}";

	internal static string PartNoPattern2 = "[A-Z]{1}[0-9]{3}[A-Z]{1}[0-9]{3}";

	internal static string PreparedFilesSchema = "Cummins.SpeedTransferComponent.PreparedFiles.xsd";

	internal static string PreparedFilesDataSet = "preparedFiles";

	internal static string PreparedFilesTable = "preparedFile";

	internal static string DefaultEJRNumber = "*******-**";

	internal static string DefaultPartNumber = "*******";

	private SpeedConfiguration configuration;

	private ResourceManager resourceManager;

	private DataSet preparedFiles;

	private string defaultEJRNumber = DefaultEJRNumber;

	private string defaultPartNumber = DefaultPartNumber;

	public int Count => preparedFiles.Tables[PreparedFilesTable].Rows.Count;

	public DataTable Table => preparedFiles.Tables[PreparedFilesTable];

	public PreparedFileInformation this[int index]
	{
		get
		{
			if (index < 0 || index >= preparedFiles.Tables[PreparedFilesTable].Rows.Count)
			{
				throw new ArgumentOutOfRangeException("Index");
			}
			PreparedFileInformation result = default(PreparedFileInformation);
			DataRow dataRow = preparedFiles.Tables[PreparedFilesTable].Rows[index];
			result.ProductID = dataRow["product_Id"].ToString();
			result.Filename = dataRow["fileName"].ToString();
			result.Pathname = dataRow["pathName"].ToString();
			string text = dataRow["EJRNo"].ToString();
			int num = text.LastIndexOf('-');
			result.EJRNumber = text.Substring(0, num);
			result.EJRNumber += text.Substring(num + 1, text.Length - num - 1);
			result.PartNumber = dataRow["partNumber"].ToString();
			result.FileType = (FileType)int.Parse(dataRow["fileType"].ToString());
			return result;
		}
	}

	public SpeedPreparedFiles(SpeedConfiguration configuration, ResourceManager resourceManager)
	{
		if (configuration == null)
		{
			throw new ArgumentNullException("configuration");
		}
		if (resourceManager == null)
		{
			throw new ArgumentNullException("resource manager");
		}
		this.configuration = configuration;
		this.resourceManager = resourceManager;
		InitDataSet();
		LoadTable();
	}

	public void Validate()
	{
		CheckIfFieldIsNull();
		if (preparedFiles.HasErrors)
		{
			throw NewFileValidationException(Facility.SpeedTransfer, 20, resourceManager.GetString("InvalidPreparedInformation"), PreparedFilesName);
		}
	}

	public void SaveToFile()
	{
		Validate();
		string text = configuration.TempUploadPath;
		if (!text.EndsWith("\\"))
		{
			text += "\\";
		}
		if (!Directory.Exists(text))
		{
			Directory.CreateDirectory(text);
		}
		text += PreparedFilesName;
		preparedFiles.WriteXml(text);
	}

	public void Clear()
	{
		if (preparedFiles == null)
		{
			throw new InvalidOperationException(resourceManager.GetString("PreparedFilesNull"));
		}
		DataTable dataTable = preparedFiles.Tables[PreparedFilesTable];
		if (dataTable != null)
		{
			dataTable.Rows.Clear();
			string text = configuration.TempUploadPath;
			if (text[text.Length - 1] != '\\')
			{
				text += "\\";
			}
			text += PreparedFilesName;
			File.Delete(text);
			return;
		}
		throw new InvalidOperationException(resourceManager.GetString("PreparedFilesNull"));
	}

	public void Add(string fileName, string path, FileType fileType)
	{
		DataTable dataTable = preparedFiles.Tables[PreparedFilesTable];
		if (dataTable == null)
		{
			throw new InvalidOperationException(resourceManager.GetString("PreparedFilesNull"));
		}
		string filterExpression = $"(fileName = '{fileName}' and fileType = {(int)fileType})";
		DataRow[] array = dataTable.Select(filterExpression);
		if (array.Length == 0)
		{
			DataRow dataRow = dataTable.NewRow();
			dataRow["product_Id"] = configuration.ProductID;
			dataRow["fileName"] = fileName;
			dataRow["pathName"] = path;
			dataRow["fileType"] = fileType;
			preparedFiles.Tables[PreparedFilesTable].ColumnChanging -= Column_Changing;
			dataRow["EJRNo"] = defaultEJRNumber;
			dataRow["partNumber"] = defaultPartNumber;
			dataTable.Rows.Add(dataRow);
			dataTable.AcceptChanges();
			preparedFiles.Tables[PreparedFilesTable].ColumnChanging += Column_Changing;
		}
	}

	public void Delete(string filename)
	{
		if (preparedFiles == null)
		{
			throw new InvalidOperationException(resourceManager.GetString("PreparedFilesNull"));
		}
		DataTable dataTable = preparedFiles.Tables[PreparedFilesTable];
		if (dataTable == null)
		{
			throw new InvalidOperationException(resourceManager.GetString("PreparedFilesNull"));
		}
		DataRow[] array = dataTable.Select("(fileName = '" + filename + "')");
		DataRow[] array2 = array;
		foreach (DataRow row in array2)
		{
			dataTable.Rows.Remove(row);
		}
	}

	private void LoadTable()
	{
		if (preparedFiles == null)
		{
			throw new InvalidOperationException("Unable to load table");
		}
		string text = configuration.TempUploadPath;
		if (text[text.Length - 1] != '\\')
		{
			text += "\\";
		}
		text += PreparedFilesName;
		if (File.Exists(text))
		{
			try
			{
				preparedFiles.ReadXml(text);
			}
			catch (DataException e)
			{
				EventLogger.Error("SpeedUpload", "Error reading speed prepared file.", e);
				File.Delete(text);
				preparedFiles.Clear();
			}
		}
	}

	private void InitDataSet()
	{
		preparedFiles = new DataSet(PreparedFilesDataSet);
		Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream(PreparedFilesSchema);
		if (manifestResourceStream == null || manifestResourceStream.Length == 0)
		{
			throw NewResourceException(Facility.SpeedTransfer, 17, resourceManager.GetString("InvalidPrepareSchema"), PreparedFilesSchema);
		}
		preparedFiles.ReadXmlSchema(manifestResourceStream);
		preparedFiles.Tables[PreparedFilesTable].ColumnChanging += Column_Changing;
	}

	private void Column_Changing(object sender, DataColumnChangeEventArgs e)
	{
		if (e.Column.ColumnName == "EJRNo")
		{
			ValidateEJRNumber(e.ProposedValue);
			defaultEJRNumber = e.ProposedValue.ToString();
		}
		else if (e.Column.ColumnName == "partNumber")
		{
			ValidatePartNumber(e.ProposedValue);
		}
	}

	private void ValidateEJRNumber(object ejrNumber)
	{
		//IL_008a: Unknown result type (might be due to invalid IL or missing references)
		if (ejrNumber == DBNull.Value)
		{
			throw new InvalidConstraintException(resourceManager.GetString("NullEJRNumber"));
		}
		string text = (string)ejrNumber;
		Match match;
		if (text.Length == 11)
		{
			Regex regex = new Regex(EJRPattern2);
			match = regex.Match(text);
		}
		else
		{
			Regex regex2 = new Regex(EJRPattern1);
			match = regex2.Match(text);
		}
		if (!match.Success)
		{
			string text2 = resourceManager.GetString("InvalidEJRNumber");
			string text3 = resourceManager.GetString("MessageBoxCaption");
			MessageBox.Show(text2, text3, (MessageBoxButtons)0, (MessageBoxIcon)16);
			throw new InvalidConstraintException(text2);
		}
	}

	private void ValidatePartNumber(object partNumber)
	{
		//IL_0062: Unknown result type (might be due to invalid IL or missing references)
		//IL_00b6: Unknown result type (might be due to invalid IL or missing references)
		//IL_0133: Unknown result type (might be due to invalid IL or missing references)
		if (partNumber.Equals(DBNull.Value))
		{
			throw PartNumberValidationException.New(MessageIDs.PartNumberIsNull, resourceManager.GetString("NullPartNumber"), (string)partNumber);
		}
		string text = (string)partNumber;
		if (text.Length > 8)
		{
			string text2 = resourceManager.GetString("InvalidPartNumberLength");
			string text3 = resourceManager.GetString("MessageBoxCaption");
			MessageBox.Show(text2, text3, (MessageBoxButtons)0, (MessageBoxIcon)16);
			throw PartNumberValidationException.New(MessageIDs.PartNumberInvalidLength, text2, (string)partNumber);
		}
		if (text.LastIndexOf('*') == -1 && PartNumberAlreadyExists(text))
		{
			string text4 = resourceManager.GetString("PartNumberAlreadyExists");
			string text5 = resourceManager.GetString("MessageBoxCaption");
			MessageBox.Show(text4, text5, (MessageBoxButtons)0, (MessageBoxIcon)16);
			throw PartNumberValidationException.New(MessageIDs.DuplicatePartNumber, text4, (string)partNumber);
		}
		Match match;
		if (text.Length == 8)
		{
			Regex regex = new Regex(PartNoPattern2);
			match = regex.Match(text);
		}
		else
		{
			Regex regex2 = new Regex(PartNoPattern1);
			match = regex2.Match(text);
		}
		if (!match.Success)
		{
			string text6 = resourceManager.GetString("InvalidPartNumber");
			string text7 = resourceManager.GetString("MessageBoxCaption");
			MessageBox.Show(text6, text7, (MessageBoxButtons)0, (MessageBoxIcon)16);
			throw PartNumberValidationException.New(MessageIDs.InvalidPartNumber, text6, (string)partNumber);
		}
	}

	private bool PartNumberAlreadyExists(string partNumber)
	{
		DataRow[] array = Table.Select("(partNumber = '" + partNumber + "')");
		bool result = false;
		if (array != null && array.Length != 0)
		{
			result = true;
		}
		return result;
	}

	private void CheckIfFieldIsNull()
	{
		DataTable dataTable = preparedFiles.Tables[PreparedFilesTable];
		if (dataTable == null)
		{
			throw new InvalidOperationException(resourceManager.GetString("InvalidPreparedInformation"));
		}
		foreach (DataRow row in dataTable.Rows)
		{
			if (row["partNumber"].ToString() == DefaultPartNumber)
			{
				string s = string.Format(resourceManager.GetString("ColumnWithNullValue"), "Part");
				throw new InvalidConstraintException(s);
			}
		}
	}

	private FileValidationException NewFileValidationException(Facility facility, short errId, string message, string filename)
	{
		FileValidationException ex = new FileValidationException(facility, errId, message);
		ex.ContextData = filename;
		return ex;
	}

	private ResourceException NewResourceException(Facility facility, short errId, string message, string resourceName)
	{
		ResourceException ex = new ResourceException(facility, errId, message);
		ex.ContextData = resourceName;
		return ex;
	}
}
public enum SubfileReleaseState
{
	Released,
	Unreleased
}
public class SpeedPrepareDialog : Form
{
	private const string space = " ";

	private const int defaultSelection = 0;

	internal static string AllFiles = "*.*";

	internal static string ReleasedSubfileExtensionPattern = "[0-9]{3}";

	internal static string UnReleasedSubfileExtensionPattern = "[a-h,A-H]{1}[0-9]{2}";

	internal static string ExtensionSeparator = ".";

	private Button btnAdd;

	private Button btnAddAll;

	private Button btnUpload;

	private DataGrid dgSelectedFiles;

	private Label lblProductID;

	private GroupBox gbSourceFiles;

	private ListBox lbSource;

	private ComboBox cmbFileType;

	private TextBox txtPath;

	private Button btnBrowse;

	private Container components;

	private ToolTip tooltip;

	private ResourceManager resourceManager;

	private SpeedConfiguration configuration;

	private SpeedPreparedFiles preparedFiles;

	private SpeedPrepare preparer;

	private DataView preparedFilesView;

	private AutoResetEvent browseFolderDone = new AutoResetEvent(initialState: false);

	private string directory;

	private FolderType[] folderTypeForSelctedItem;

	private DataGridTableStyle dgts;

	private DataGridTextBoxColumn dgtbc1;

	private EJRColumnStyle dgtbc2;

	private EJRColumnStyle dgtbc3;

	private DataGridTextBoxColumn dgtbc4;

	private FileType[] fileTypeForSelectedItem;

	private int indexOfSelectCalibaration;

	private Button btnRemove;

	private Button btnClose;

	private Button btnRemoveAll;

	private string[] FilterForSelectedItem;

	public SpeedPrepareDialog(ResourceManager resourceManager, SpeedConfiguration configuration, SpeedPreparedFiles preparedFiles, SpeedPrepare preparer)
	{
		InitializeComponent();
		this.resourceManager = resourceManager;
		this.configuration = configuration;
		this.preparedFiles = preparedFiles;
		this.preparer = preparer;
		preparedFilesView = new DataView();
		IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
		string text = productInformationService.GTISLevel(configuration.ProductID);
		string text2;
		if ((text2 = configuration.ProductID.ToUpper()) != null && text2 == "AEM")
		{
			ConfigureAEMProduct();
			return;
		}
		if (text.Equals("GTIS45"))
		{
			cmbFileType.Items.AddRange(new object[9] { "Unreleased Subfiles", "Released Subfiles", "E2M PreGTIS4.5 config file", "Engineering Tool Config files", "Production Tool Config files", "Non volatile Data files", "Boot loader files", "Reconfig I/O files", "Calibration files" });
			folderTypeForSelctedItem = new FolderType[9]
			{
				FolderType.UnreleasedCalibration,
				FolderType.ReleasedCalibration,
				FolderType.ProductSupport,
				FolderType.ProductSupport,
				FolderType.ProductSupport,
				FolderType.ProductSupport,
				FolderType.ProductSupport,
				FolderType.ProductSupport,
				FolderType.UnreleasedCalibration
			};
			fileTypeForSelectedItem = new FileType[9]
			{
				FileType.Subfile,
				FileType.Subfile,
				FileType.E2MFile,
				FileType.ECFGFile,
				FileType.PCFGFile,
				FileType.NVDFile,
				FileType.BOTFile,
				FileType.RIOFile,
				FileType.Calibration
			};
			FilterForSelectedItem = new string[9] { "*.*", "*.*", "*.e2m", "*.ecfg", "*.pcfg", "*.nvd", "*.bot", "*.rio", "*.*" };
		}
		else
		{
			cmbFileType.Items.AddRange(new object[9] { "Unreleased Subfiles", "Released Subfiles", "E2M PreGTIS4.5 config file", "Engineering Tool Config files", "Header record files", "Non volatile Data files", "Boot loader files", "Reconfig I/O files", "Calibration files" });
			folderTypeForSelctedItem = new FolderType[9]
			{
				FolderType.UnreleasedCalibration,
				FolderType.ReleasedCalibration,
				FolderType.ProductSupport,
				FolderType.ProductSupport,
				FolderType.ProductSupport,
				FolderType.ProductSupport,
				FolderType.ProductSupport,
				FolderType.ProductSupport,
				FolderType.UnreleasedCalibration
			};
			fileTypeForSelectedItem = new FileType[9]
			{
				FileType.Subfile,
				FileType.Subfile,
				FileType.E2MFile,
				FileType.ECFGFile,
				FileType.HDRFile,
				FileType.NVDFile,
				FileType.BOTFile,
				FileType.RIOFile,
				FileType.Calibration
			};
			FilterForSelectedItem = new string[9] { "*.*", "*.*", "*.e2m", "*.ecfg", "*.hdr", "*.nvd", "*.bot", "*.rio", "*.*" };
		}
		indexOfSelectCalibaration = 8;
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		((Form)this).Dispose(disposing);
	}

	protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
	{
		//IL_000b: Unknown result type (might be due to invalid IL or missing references)
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		//IL_000f: Invalid comparison between Unknown and I4
		//IL_0011: Unknown result type (might be due to invalid IL or missing references)
		//IL_0017: Unknown result type (might be due to invalid IL or missing references)
		//IL_001d: Invalid comparison between Unknown and I4
		//IL_0045: Unknown result type (might be due to invalid IL or missing references)
		try
		{
			Keys val = (Keys)(int)((Message)(ref msg)).WParam;
			if ((int)val == 72 && (keyData & 0x20000) == 131072)
			{
				Help.ShowHelp((Control)(object)this, Application.StartupPath + "\\CaltermIII.chm", (HelpNavigator)(-2147483642), (object)"Speed Transfer");
			}
		}
		catch
		{
		}
		return ((Form)this).ProcessCmdKey(ref msg, keyData);
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
		//IL_0050: Unknown result type (might be due to invalid IL or missing references)
		//IL_005a: Expected O, but got Unknown
		//IL_005b: Unknown result type (might be due to invalid IL or missing references)
		//IL_0065: Expected O, but got Unknown
		//IL_0066: Unknown result type (might be due to invalid IL or missing references)
		//IL_0070: Expected O, but got Unknown
		//IL_0071: Unknown result type (might be due to invalid IL or missing references)
		//IL_007b: Expected O, but got Unknown
		//IL_007c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0086: Expected O, but got Unknown
		//IL_0087: Unknown result type (might be due to invalid IL or missing references)
		//IL_0091: Expected O, but got Unknown
		//IL_0092: Unknown result type (might be due to invalid IL or missing references)
		//IL_009c: Expected O, but got Unknown
		//IL_009d: Unknown result type (might be due to invalid IL or missing references)
		//IL_00a7: Expected O, but got Unknown
		//IL_00a8: Unknown result type (might be due to invalid IL or missing references)
		//IL_00b2: Expected O, but got Unknown
		//IL_00b3: Unknown result type (might be due to invalid IL or missing references)
		//IL_00bd: Expected O, but got Unknown
		//IL_00be: Unknown result type (might be due to invalid IL or missing references)
		//IL_00c8: Expected O, but got Unknown
		//IL_00f7: Unknown result type (might be due to invalid IL or missing references)
		//IL_0101: Expected O, but got Unknown
		//IL_0182: Unknown result type (might be due to invalid IL or missing references)
		//IL_018c: Expected O, but got Unknown
		//IL_0589: Unknown result type (might be due to invalid IL or missing references)
		//IL_0593: Expected O, but got Unknown
		//IL_0650: Unknown result type (might be due to invalid IL or missing references)
		//IL_065a: Expected O, but got Unknown
		//IL_06e0: Unknown result type (might be due to invalid IL or missing references)
		//IL_06ea: Expected O, but got Unknown
		//IL_075f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0769: Expected O, but got Unknown
		//IL_07e7: Unknown result type (might be due to invalid IL or missing references)
		//IL_07f1: Expected O, but got Unknown
		//IL_0862: Unknown result type (might be due to invalid IL or missing references)
		//IL_086c: Expected O, but got Unknown
		//IL_08dc: Unknown result type (might be due to invalid IL or missing references)
		//IL_08e6: Expected O, but got Unknown
		//IL_096a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0974: Expected O, but got Unknown
		btnAdd = new Button();
		btnAddAll = new Button();
		dgSelectedFiles = new DataGrid();
		dgts = new DataGridTableStyle();
		dgtbc1 = new DataGridTextBoxColumn();
		dgtbc2 = new EJRColumnStyle(ColumnType.UserControl);
		dgtbc3 = new EJRColumnStyle(ColumnType.TextBox);
		dgtbc4 = new DataGridTextBoxColumn();
		btnUpload = new Button();
		btnClose = new Button();
		lblProductID = new Label();
		gbSourceFiles = new GroupBox();
		txtPath = new TextBox();
		btnBrowse = new Button();
		lbSource = new ListBox();
		cmbFileType = new ComboBox();
		btnRemove = new Button();
		btnRemoveAll = new Button();
		((ISupportInitialize)dgSelectedFiles).BeginInit();
		((Control)gbSourceFiles).SuspendLayout();
		((Control)this).SuspendLayout();
		((Control)btnAdd).Font = new Font("Tahoma", 12f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)btnAdd).Location = new Point(240, 120);
		((Control)btnAdd).Name = "btnAdd";
		((Control)btnAdd).Size = new Size(32, 23);
		((Control)btnAdd).TabIndex = 4;
		((Control)btnAdd).Text = "›";
		((Control)btnAdd).Click += btnAdd_Click;
		((Control)btnAddAll).Font = new Font("Tahoma", 12f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)btnAddAll).Location = new Point(240, 168);
		((Control)btnAddAll).Name = "btnAddAll";
		((Control)btnAddAll).Size = new Size(32, 23);
		((Control)btnAddAll).TabIndex = 5;
		((Control)btnAddAll).Text = "»";
		((Control)btnAddAll).Click += btnAddAll_Click;
		dgSelectedFiles.AllowSorting = false;
		dgSelectedFiles.CaptionText = "Selected Files Information";
		dgSelectedFiles.DataMember = "";
		dgSelectedFiles.HeaderForeColor = SystemColors.ControlText;
		((Control)dgSelectedFiles).Location = new Point(288, 32);
		((Control)dgSelectedFiles).Name = "dgSelectedFiles";
		((Control)dgSelectedFiles).Size = new Size(448, 312);
		((Control)dgSelectedFiles).TabIndex = 8;
		dgSelectedFiles.TableStyles.AddRange((DataGridTableStyle[])(object)new DataGridTableStyle[1] { dgts });
		dgSelectedFiles.CurrentCellChanged += dgSelectedFiles_CurrentCellChanged;
		dgts.AllowSorting = false;
		dgts.DataGrid = dgSelectedFiles;
		dgts.GridColumnStyles.AddRange((DataGridColumnStyle[])(object)new DataGridColumnStyle[4]
		{
			(DataGridColumnStyle)dgtbc1,
			dgtbc2,
			dgtbc3,
			(DataGridColumnStyle)dgtbc4
		});
		dgts.HeaderForeColor = SystemColors.ControlText;
		dgts.MappingName = "preparedFile";
		dgtbc1.Format = "";
		dgtbc1.FormatInfo = null;
		((DataGridColumnStyle)dgtbc1).HeaderText = "File Name";
		((DataGridColumnStyle)dgtbc1).MappingName = "fileName";
		((DataGridColumnStyle)dgtbc1).ReadOnly = true;
		((DataGridColumnStyle)dgtbc1).Width = 150;
		((DataGridColumnStyle)dgtbc2).HeaderText = "EJR Number";
		((DataGridColumnStyle)dgtbc2).MappingName = "EJRNo";
		((DataGridColumnStyle)dgtbc2).Width = 125;
		((DataGridColumnStyle)dgtbc2).WidthChanged += dgtbc2_WidthChanged;
		dgtbc3.InputChar = '*';
		dgtbc3.InputMask = "YDDDYDDD";
		dgtbc3.MaxLength = 8;
		((DataGridColumnStyle)dgtbc3).HeaderText = "Part Number";
		((DataGridColumnStyle)dgtbc3).MappingName = "partNumber";
		((DataGridColumnStyle)dgtbc3).Width = 75;
		((DataGridColumnStyle)dgtbc3).WidthChanged += dgtbc3_WidthChanged;
		dgtbc4.Format = "";
		dgtbc4.FormatInfo = null;
		((DataGridColumnStyle)dgtbc4).HeaderText = "Source File Path";
		((DataGridColumnStyle)dgtbc4).MappingName = "pathName";
		((DataGridColumnStyle)dgtbc4).ReadOnly = true;
		((DataGridColumnStyle)dgtbc4).Width = 650;
		btnUpload.DialogResult = (DialogResult)1;
		((Control)btnUpload).Location = new Point(568, 368);
		((Control)btnUpload).Name = "btnUpload";
		((Control)btnUpload).TabIndex = 9;
		((Control)btnUpload).Text = "&Upload";
		((Control)btnUpload).Click += btnUpload_Click;
		btnClose.DialogResult = (DialogResult)2;
		((Control)btnClose).Location = new Point(656, 368);
		((Control)btnClose).Name = "btnClose";
		((Control)btnClose).TabIndex = 10;
		((Control)btnClose).Text = "&Close";
		((Control)btnClose).Click += btnCancel_Click;
		((Control)lblProductID).AutoSize = true;
		((Control)lblProductID).Font = new Font("Tahoma", 8f, (FontStyle)1);
		((Control)lblProductID).Location = new Point(16, 8);
		((Control)lblProductID).Name = "lblProductID";
		((Control)lblProductID).Size = new Size(101, 16);
		((Control)lblProductID).TabIndex = 27;
		((Control)lblProductID).Text = "Product ID : CWX";
		((Control)gbSourceFiles).Controls.Add((Control)(object)txtPath);
		((Control)gbSourceFiles).Controls.Add((Control)(object)btnBrowse);
		((Control)gbSourceFiles).Controls.Add((Control)(object)lbSource);
		((Control)gbSourceFiles).Controls.Add((Control)(object)cmbFileType);
		((Control)gbSourceFiles).Font = new Font("Tahoma", 8f, (FontStyle)1);
		((Control)gbSourceFiles).Location = new Point(8, 32);
		((Control)gbSourceFiles).Name = "gbSourceFiles";
		((Control)gbSourceFiles).Size = new Size(224, 320);
		((Control)gbSourceFiles).TabIndex = 28;
		gbSourceFiles.TabStop = false;
		((Control)gbSourceFiles).Text = "Source Files";
		((Control)txtPath).BackColor = SystemColors.Window;
		((Control)txtPath).Font = new Font("Tahoma", 8f);
		((Control)txtPath).Location = new Point(8, 16);
		((Control)txtPath).Name = "txtPath";
		((TextBoxBase)txtPath).ReadOnly = true;
		((Control)txtPath).Size = new Size(184, 20);
		((Control)txtPath).TabIndex = 0;
		((Control)txtPath).Text = "";
		((Control)btnBrowse).Font = new Font("Tahoma", 9.75f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)btnBrowse).Location = new Point(192, 16);
		((Control)btnBrowse).Name = "btnBrowse";
		((Control)btnBrowse).Size = new Size(24, 20);
		((Control)btnBrowse).TabIndex = 1;
		((Control)btnBrowse).Text = "…";
		((Control)btnBrowse).Click += btnBrowse_Click;
		((Control)lbSource).Font = new Font("Tahoma", 8f);
		((Control)lbSource).Location = new Point(8, 80);
		((Control)lbSource).Name = "lbSource";
		lbSource.SelectionMode = (SelectionMode)2;
		((Control)lbSource).Size = new Size(208, 225);
		((Control)lbSource).TabIndex = 3;
		cmbFileType.DropDownStyle = (ComboBoxStyle)2;
		((Control)cmbFileType).Font = new Font("Tahoma", 8f);
		((Control)cmbFileType).Location = new Point(8, 48);
		((Control)cmbFileType).Name = "cmbFileType";
		((Control)cmbFileType).Size = new Size(208, 21);
		((Control)cmbFileType).TabIndex = 2;
		cmbFileType.SelectedIndexChanged += cmbFileType_SelectedIndexChanged;
		((Control)btnRemove).Font = new Font("Tahoma", 12f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)btnRemove).Location = new Point(240, 216);
		((Control)btnRemove).Name = "btnRemove";
		((Control)btnRemove).Size = new Size(32, 23);
		((Control)btnRemove).TabIndex = 6;
		((Control)btnRemove).Text = "‹";
		((Control)btnRemove).Click += btnRemove_Click;
		((Control)btnRemoveAll).Font = new Font("Tahoma", 12f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)btnRemoveAll).Location = new Point(240, 256);
		((Control)btnRemoveAll).Name = "btnRemoveAll";
		((Control)btnRemoveAll).Size = new Size(32, 23);
		((Control)btnRemoveAll).TabIndex = 7;
		((Control)btnRemoveAll).Text = "«";
		((Control)btnRemoveAll).Click += btnRemoveAll_Click;
		((Form)this).AutoScaleBaseSize = new Size(5, 13);
		((Form)this).CancelButton = (IButtonControl)(object)btnClose;
		((Form)this).ClientSize = new Size(744, 399);
		((Control)this).Controls.Add((Control)(object)btnRemoveAll);
		((Control)this).Controls.Add((Control)(object)btnRemove);
		((Control)this).Controls.Add((Control)(object)gbSourceFiles);
		((Control)this).Controls.Add((Control)(object)lblProductID);
		((Control)this).Controls.Add((Control)(object)btnClose);
		((Control)this).Controls.Add((Control)(object)btnUpload);
		((Control)this).Controls.Add((Control)(object)dgSelectedFiles);
		((Control)this).Controls.Add((Control)(object)btnAdd);
		((Control)this).Controls.Add((Control)(object)btnAddAll);
		((Form)this).FormBorderStyle = (FormBorderStyle)3;
		((Form)this).MaximizeBox = false;
		((Form)this).MinimizeBox = false;
		((Control)this).Name = "SpeedPrepareDialog";
		((Form)this).ShowInTaskbar = false;
		((Form)this).StartPosition = (FormStartPosition)4;
		((Control)this).Text = "Prepare Files to Upload";
		((Form)this).Load += SpeedPrepareDialog_Load;
		((ISupportInitialize)dgSelectedFiles).EndInit();
		((Control)gbSourceFiles).ResumeLayout(false);
		((Control)this).ResumeLayout(false);
	}

	private void btnBrowse_Click(object sender, EventArgs e)
	{
		directory = ((Control)txtPath).Text;
		Thread thread = new Thread(SelectDirectory);
		thread.SetApartmentState(ApartmentState.STA);
		thread.Start();
		((Control)this).Enabled = false;
		browseFolderDone.WaitOne();
		((Control)this).Enabled = true;
		((Form)this).Activate();
		if (directory.Length == 0)
		{
			return;
		}
		((Control)txtPath).Text = directory;
		string filter = FilterForSelectedItem[((ListControl)cmbFileType).SelectedIndex];
		if (fileTypeForSelectedItem[((ListControl)cmbFileType).SelectedIndex] == FileType.Subfile)
		{
			if (folderTypeForSelctedItem[((ListControl)cmbFileType).SelectedIndex] == FolderType.ReleasedCalibration)
			{
				UpdateSourceFileListForSubfiles(directory, SubfileReleaseState.Released);
			}
			else if (folderTypeForSelctedItem[((ListControl)cmbFileType).SelectedIndex] == FolderType.UnreleasedCalibration)
			{
				UpdateSourceFileListForSubfiles(directory, SubfileReleaseState.Unreleased);
			}
		}
		else
		{
			UpdateSourceFileList(directory, filter);
		}
	}

	private void SpeedPrepareDialog_Load(object sender, EventArgs e)
	{
		lbSource.Items.Clear();
		((Control)lblProductID).Text = "Product ID : " + configuration.ProductID;
		IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
		if (productInformationService.GetProductInformation(configuration.ProductID, ProductInformationType.ProductType).Equals("Calibration"))
		{
			((ListControl)cmbFileType).SelectedIndex = indexOfSelectCalibaration;
		}
		else
		{
			((ListControl)cmbFileType).SelectedIndex = 0;
		}
		preparedFilesView.Table = preparedFiles.Table;
		preparedFilesView.AllowNew = false;
		dgSelectedFiles.SetDataBinding((object)preparedFilesView, (string)null);
		((Control)btnAdd).Enabled = lbSource.Items.Count != 0;
		((Control)btnAddAll).Enabled = lbSource.Items.Count != 0;
		((Control)btnRemove).Enabled = preparedFiles.Count != 0;
		InitToolTips();
		((ContainerControl)this).ActiveControl = (Control)(object)btnBrowse;
	}

	private void cmbFileType_SelectedIndexChanged(object sender, EventArgs e)
	{
		FolderType folderType = folderTypeForSelctedItem[((ListControl)cmbFileType).SelectedIndex];
		string text = null;
		switch (folderType)
		{
		case FolderType.UnreleasedCalibration:
			text = configuration.ProductUnrlCalPath;
			break;
		case FolderType.ReleasedCalibration:
			text = configuration.ProductCalPath;
			break;
		case FolderType.ProductSupport:
			text = configuration.ProductSupportPath;
			break;
		}
		string filter = FilterForSelectedItem[((ListControl)cmbFileType).SelectedIndex];
		((Control)txtPath).Text = text;
		if (fileTypeForSelectedItem[((ListControl)cmbFileType).SelectedIndex] == FileType.Subfile)
		{
			if (folderTypeForSelctedItem[((ListControl)cmbFileType).SelectedIndex] == FolderType.ReleasedCalibration)
			{
				UpdateSourceFileListForSubfiles(text, SubfileReleaseState.Released);
			}
			else if (folderTypeForSelctedItem[((ListControl)cmbFileType).SelectedIndex] == FolderType.UnreleasedCalibration)
			{
				UpdateSourceFileListForSubfiles(text, SubfileReleaseState.Unreleased);
			}
		}
		else
		{
			UpdateSourceFileList(text, filter);
		}
	}

	private void btnAdd_Click(object sender, EventArgs e)
	{
		//IL_00ad: Unknown result type (might be due to invalid IL or missing references)
		Cursor.Current = Cursors.WaitCursor;
		try
		{
			foreach (int selectedIndex in lbSource.SelectedIndices)
			{
				AddOneFile(lbSource.Items[selectedIndex].ToString(), (string)((Control)lbSource).Tag, fileTypeForSelectedItem[((ListControl)cmbFileType).SelectedIndex]);
			}
		}
		catch (ArgumentException)
		{
			string text = resourceManager.GetString("MessageBoxCaption");
			string text2 = resourceManager.GetString("WhiteSpace");
			MessageBox.Show(text2, text, (MessageBoxButtons)0);
		}
		finally
		{
			((ListControl)lbSource).SelectedIndex = -1;
			Cursor.Current = Cursors.Arrow;
		}
	}

	private void dgSelectedFiles_CurrentCellChanged(object sender, EventArgs e)
	{
	}

	private void btnAddAll_Click(object sender, EventArgs e)
	{
		//IL_008b: Unknown result type (might be due to invalid IL or missing references)
		Cursor.Current = Cursors.WaitCursor;
		try
		{
			for (int i = 0; i < lbSource.Items.Count; i++)
			{
				AddOneFile(lbSource.Items[i].ToString(), (string)((Control)lbSource).Tag, fileTypeForSelectedItem[((ListControl)cmbFileType).SelectedIndex]);
			}
		}
		catch (ArgumentException)
		{
			string text = resourceManager.GetString("MessageBoxCaption");
			string text2 = resourceManager.GetString("WhiteSpace");
			MessageBox.Show(text2, text, (MessageBoxButtons)0);
		}
		finally
		{
			Cursor.Current = Cursors.Arrow;
			((ListControl)lbSource).SelectedIndex = -1;
		}
	}

	private void btnCancel_Click(object sender, EventArgs e)
	{
		//IL_0046: Unknown result type (might be due to invalid IL or missing references)
		if (preparedFiles.Table.Rows.Count != 0)
		{
			try
			{
				preparedFiles.SaveToFile();
				((Form)this).Close();
				return;
			}
			catch (InvalidConstraintException ex)
			{
				string text = resourceManager.GetString("MessageBoxCaption");
				MessageBox.Show(ex.Message, text, (MessageBoxButtons)0, (MessageBoxIcon)16);
				return;
			}
		}
		((Form)this).Close();
	}

	private void UpdateSourceFileList(string pathName, string filter)
	{
		if (pathName == null || pathName.Length == 0)
		{
			throw new ArgumentNullException("Path name");
		}
		if (!Directory.Exists(pathName))
		{
			Directory.CreateDirectory(pathName);
		}
		string[] files = Directory.GetFiles(pathName, filter);
		((Control)lbSource).Tag = pathName;
		lbSource.Items.Clear();
		string text = null;
		int num = 0;
		string[] array = files;
		foreach (string text2 in array)
		{
			num = text2.LastIndexOf('\\');
			text = text2.Substring(num + 1);
			lbSource.Items.Add((object)text);
		}
		((Control)btnAdd).Enabled = lbSource.Items.Count != 0;
		((Control)btnAddAll).Enabled = lbSource.Items.Count != 0;
	}

	private void UpdateSourceFileListForSubfiles(string pathName, SubfileReleaseState releaseState)
	{
		if (pathName == null || pathName.Length == 0)
		{
			throw new ArgumentNullException("Path name");
		}
		if (!Directory.Exists(pathName))
		{
			Directory.CreateDirectory(pathName);
		}
		string[] files = Directory.GetFiles(pathName, AllFiles);
		((Control)lbSource).Tag = pathName;
		lbSource.Items.Clear();
		string text = null;
		int num = 0;
		string[] array = files;
		foreach (string text2 in array)
		{
			num = text2.LastIndexOf('\\');
			text = text2.Substring(num + 1);
			AddSubfileToSourceFilelist(text, releaseState);
		}
		((Control)btnAdd).Enabled = lbSource.Items.Count != 0;
		((Control)btnAddAll).Enabled = lbSource.Items.Count != 0;
	}

	private void AddSubfileToSourceFilelist(string fileName, SubfileReleaseState releaseState)
	{
		Regex regex = ((releaseState != SubfileReleaseState.Released) ? new Regex(UnReleasedSubfileExtensionPattern) : new Regex(ReleasedSubfileExtensionPattern));
		string text = null;
		int num = (num = fileName.LastIndexOf(ExtensionSeparator));
		if (num == -1)
		{
			return;
		}
		text = fileName.Substring(num + 1);
		if (text.Length == 3)
		{
			Match match = regex.Match(text);
			if (match.Success)
			{
				lbSource.Items.Add((object)fileName);
			}
		}
	}

	private void AddOneFile(string fileName, string path, FileType fileType)
	{
		//IL_010a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0143: Unknown result type (might be due to invalid IL or missing references)
		if (fileName == null || fileName.Length == 0)
		{
			new ArgumentNullException("file name");
		}
		if (fileName.IndexOf(" ") != -1)
		{
			throw new ArgumentException("file name");
		}
		if (path == null || path.Length == 0)
		{
			new ArgumentNullException("file path");
		}
		if (path[path.Length - 1] != '\\')
		{
			path += "\\";
		}
		string text = path;
		text += fileName;
		bool flag = true;
		try
		{
			IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
			string text2 = productInformationService.GTISLevel(configuration.ProductID);
			if (!text2.ToUpper().Equals("GTISNA"))
			{
				preparer.CheckFile(text, fileType);
				if (fileType == FileType.Subfile)
				{
					ProcessReleaseState(text);
				}
			}
		}
		catch (CRCException ex)
		{
			string text3 = resourceManager.GetString("MessageBoxCaption");
			resourceManager.GetString("CannotSelectFile");
			string text4 = string.Format(ex.Message, ex.ContextData);
			MessageBox.Show(text4, text3, (MessageBoxButtons)0);
			flag = false;
		}
		catch (Exception ex2)
		{
			string text5 = resourceManager.GetString("MessageBoxCaption");
			resourceManager.GetString("CannotSelectFile");
			MessageBox.Show(ex2.Message, text5, (MessageBoxButtons)0);
			flag = false;
		}
		if (flag)
		{
			preparedFiles.Add(fileName, path, fileType);
			((Control)btnRemove).Enabled = true;
		}
	}

	private void InitToolTips()
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_000b: Expected O, but got Unknown
		tooltip = new ToolTip();
		tooltip.AutoPopDelay = 5000;
		tooltip.InitialDelay = 1000;
		tooltip.ReshowDelay = 500;
		tooltip.ShowAlways = true;
		tooltip.SetToolTip((Control)(object)btnAdd, "Add the selected source files");
		tooltip.SetToolTip((Control)(object)btnAddAll, "Add all the source files");
		tooltip.SetToolTip((Control)(object)btnRemove, "Remove the selected file");
		tooltip.SetToolTip((Control)(object)btnRemoveAll, "Remove all the selected files");
		tooltip.SetToolTip((Control)(object)btnBrowse, "Click to select a folder");
		tooltip.SetToolTip((Control)(object)txtPath, ((Control)txtPath).Text);
		tooltip.SetToolTip((Control)(object)cmbFileType, "Select the file type");
		tooltip.SetToolTip((Control)(object)btnUpload, "Prepare and Upload the selected files");
		tooltip.SetToolTip((Control)(object)btnClose, "Only Prepare the selected files");
	}

	private void SelectDirectory()
	{
		//IL_0000: Unknown result type (might be due to invalid IL or missing references)
		//IL_0006: Expected O, but got Unknown
		//IL_0022: Unknown result type (might be due to invalid IL or missing references)
		//IL_0028: Invalid comparison between Unknown and I4
		FolderBrowserDialog val = new FolderBrowserDialog();
		val.RootFolder = Environment.SpecialFolder.MyComputer;
		val.SelectedPath = directory;
		val.ShowNewFolderButton = false;
		if ((int)((CommonDialog)val).ShowDialog() == 1)
		{
			directory = val.SelectedPath;
		}
		else
		{
			directory = "";
		}
		browseFolderDone.Set();
	}

	private void ProcessReleaseState(string fileName)
	{
		Subfile subfile = new Subfile(fileName);
		switch (subfile.ReleaseState)
		{
		case ReleaseState.Unreleased:
			throw new SpeedTransferException(resourceManager.GetString("UnreleasedSubfile"));
		case ReleaseState.Checked:
			throw new SpeedTransferException(resourceManager.GetString("CheckedSubfile"));
		case ReleaseState.Assembled:
			if (SubfileType.Three != subfile.GetSubFileType(fileName))
			{
				throw new SpeedTransferException(resourceManager.GetString("AssembledSubfile"));
			}
			break;
		}
	}

	private void btnRemove_Click(object sender, EventArgs e)
	{
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0011: Unknown result type (might be due to invalid IL or missing references)
		DataGrid obj = dgSelectedFiles;
		DataGridCell currentCell = dgSelectedFiles.CurrentCell;
		string filename = (string)obj[((DataGridCell)(ref currentCell)).RowNumber, 0];
		preparedFiles.Delete(filename);
		((Control)btnRemove).Enabled = preparedFiles.Count != 0;
	}

	private void btnRemoveAll_Click(object sender, EventArgs e)
	{
		preparedFiles.Clear();
	}

	private void btnUpload_Click(object sender, EventArgs e)
	{
		//IL_0040: Unknown result type (might be due to invalid IL or missing references)
		try
		{
			if (preparedFiles.Table.Rows.Count != 0)
			{
				preparedFiles.Validate();
			}
		}
		catch (Exception ex)
		{
			string text = resourceManager.GetString("MessageBoxCaption");
			MessageBox.Show(ex.Message, text, (MessageBoxButtons)0, (MessageBoxIcon)16);
			((Form)this).DialogResult = (DialogResult)0;
		}
	}

	private void dgtbc2_WidthChanged(object sender, EventArgs e)
	{
		if (((DataGridColumnStyle)dgtbc2).Width <= 125)
		{
			((DataGridColumnStyle)dgtbc2).Width = 125;
		}
	}

	private void dgtbc3_WidthChanged(object sender, EventArgs e)
	{
		if (((DataGridColumnStyle)dgtbc3).Width <= 75)
		{
			((DataGridColumnStyle)dgtbc3).Width = 75;
		}
	}

	private void ConfigureAEMProduct()
	{
		FilterForSelectedItem = new string[6] { "*.e2m", "*.hdr", "*.nvd", "*.bot", "*.rio", "*.*" };
		fileTypeForSelectedItem = new FileType[6]
		{
			FileType.E2MFile,
			FileType.HDRFile,
			FileType.NVDFile,
			FileType.BOTFile,
			FileType.RIOFile,
			FileType.Calibration
		};
		folderTypeForSelctedItem = new FolderType[6]
		{
			FolderType.ProductSupport,
			FolderType.ProductSupport,
			FolderType.ProductSupport,
			FolderType.ProductSupport,
			FolderType.ProductSupport,
			FolderType.UnreleasedCalibration
		};
		cmbFileType.Items.Clear();
		cmbFileType.Items.AddRange(new object[6] { "E2M PreGTIS4.5 config file", "Header record files", "Non volatile Data files", "Boot loader files", "Reconfig I/O files", "Calibration files" });
		indexOfSelectCalibaration = 5;
	}
}
public delegate void ProgressChangedEventHandler(object sender, ProgressEventArgs progress);
public class SpeedTransferComponent : Component, IPropertyPageProvider, ICommandLine
{
	private const int EJRNUMBER_LENGTH1 = 9;

	private const int EJRNUMBER_LENGTH2 = 10;

	private const int ECMPARTNUMBER_LENGTH = 7;

	internal static string ResourceFilename = "Cummins.SpeedTransferComponent.Strings";

	private Container components;

	private ResourceManager resourceManager;

	private SpeedConfiguration configuration;

	private CaltermProgress progressView;

	private bool forCLI;

	public ArrayList Pages
	{
		get
		{
			ArrayList arrayList = new ArrayList();
			SpeedConfigurationPage value = new SpeedConfigurationPage("", "Speed Transfer");
			arrayList.Add(value);
			return arrayList;
		}
	}

	public event ProcessCompleteEventHandler ProcessCompleteEvent;

	public SpeedTransferComponent()
	{
		InitializeComponent();
		resourceManager = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
		configuration = new SpeedConfiguration(resourceManager);
	}

	public SpeedTransferComponent(bool speedUploadCLI, string productIdentifier)
	{
		InitializeComponent();
		resourceManager = new ResourceManager(ResourceFilename, Assembly.GetExecutingAssembly());
		configuration = new SpeedConfiguration(resourceManager, speedUploadCLI, productIdentifier);
		forCLI = speedUploadCLI;
	}

	private void InitializeComponent()
	{
		components = new Container();
	}

	public void Download(DownloadType downloadType, bool caltermCLI = false)
	{
		ReportType reportType = ReportType.FullDownloadReport;
		SpeedTransferReport reporter = new SpeedTransferReport(configuration, reportType, null, resourceManager);
		SpeedDownload speedDownload = new SpeedDownload(downloadType, configuration, reporter, resourceManager, caltermCLI);
		speedDownload.ProgressChangedEvent += OnProgressChaged;
		speedDownload.DownloadCompleteEvent += OnComplete;
		ThreadStart start = speedDownload.Start;
		Thread thread = new Thread(start);
		progressView = new CaltermProgress("SPEED Transfer : Download", allowCancel: false);
		thread.Start();
		if (!forCLI)
		{
			progressView.StartModal();
		}
	}

	public void PrepareForUpload(SpeedPreparedFiles preparedFiles)
	{
		throw new NotImplementedException("Not implemented");
	}

	public void Upload()
	{
		//IL_004e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0053: Unknown result type (might be due to invalid IL or missing references)
		//IL_005c: Unknown result type (might be due to invalid IL or missing references)
		//IL_005f: Invalid comparison between Unknown and I4
		SpeedTransferReport reporter = new SpeedTransferReport(configuration, ReportType.UploadReport, null, resourceManager);
		SpeedPrepare speedPrepare = new SpeedPrepare(configuration, resourceManager, reporter);
		SpeedPreparedFiles preparedFiles = new SpeedPreparedFiles(configuration, resourceManager);
		SpeedPrepareDialog speedPrepareDialog = new SpeedPrepareDialog(resourceManager, configuration, preparedFiles, speedPrepare);
		DialogResult val = ((Form)speedPrepareDialog).ShowDialog();
		speedPrepare.Prepare(preparedFiles);
		if ((int)val == 1)
		{
			SpeedUpload speedUpload = new SpeedUpload(configuration, resourceManager, preparedFiles, reporter);
			speedUpload.ProgressChangedEvent += OnProgressChaged;
			speedUpload.UploadCompleteEvent += OnComplete;
			progressView = new CaltermProgress("SPEED Transfer : Upload", allowCancel: false);
			ThreadStart start = speedUpload.Start;
			Thread thread = new Thread(start);
			thread.Start();
			progressView.StartModal();
		}
	}

	private void OnProgressChaged(object sender, ProgressEventArgs e)
	{
		progressView.SetProgress(e.Total, e.Current, e.Status);
	}

	private void OnComplete(object sender, EventArgs e)
	{
		if (forCLI)
		{
			if (e is ProcessCompleteEventArgs e2)
			{
				RaiseProcessCompleteEvent(e2.success, e2.resultString);
			}
		}
		else
		{
			progressView.Finish();
		}
	}

	public void Start(DataSet argumentDataSet)
	{
		try
		{
			if (argumentDataSet != null)
			{
				DataTable dataTable = argumentDataSet.Tables["SpeedUpload"];
				DataRow dataRow = dataTable.Rows[0];
				if (dataRow != null)
				{
					string productID = dataRow["ProductID"].ToString();
					string text = dataRow["ECMPartNumber"].ToString();
					string text2 = dataRow["EJRNumber"].ToString();
					string text3 = dataRow["UploadFile"].ToString();
					string text4 = dataRow["UploadFileType"].ToString().ToUpper();
					string text5 = dataRow["UploadReportFile"].ToString();
					string text6 = dataRow["UploadReportFormat"].ToString();
					if (dataRow["AppendReportFile"] != DBNull.Value)
					{
						configuration.AppendReportFile = bool.Parse(dataRow["AppendReportFile"].ToString());
					}
					ValidTheInputParameters(text2, text3, text);
					configuration.ProductID = productID;
					if (text6.Trim().Length > 0)
					{
						configuration.ReportFormat = text6;
					}
					if (text5.Trim().Length > 0)
					{
						configuration.UploadReportFileName = text5;
					}
					if (text5.Trim().Length == 0)
					{
						text5 = null;
					}
					SpeedTransferReport reporter = new SpeedTransferReport(configuration, ReportType.UploadReport, text5, resourceManager);
					SpeedPreparedFiles speedPreparedFiles = new SpeedPreparedFiles(configuration, resourceManager);
					int num = text3.LastIndexOf("\\");
					string fileName = text3.Substring(num + 1);
					string path = text3.Substring(0, num);
					FileType fileType = FileType.Calibration;
					switch (text4)
					{
					case "A":
						fileType = FileType.Calibration;
						break;
					case "B":
						fileType = FileType.Subfile;
						ValidateSubfileReleaseState(text3);
						break;
					case "C":
						fileType = FileType.ControlFile;
						break;
					case "D":
						fileType = FileType.Other;
						break;
					case "E":
						fileType = FileType.E2MFile;
						break;
					case "F":
						fileType = FileType.RIOFile;
						break;
					case "G":
						fileType = FileType.ECFGFile;
						break;
					case "H":
						fileType = FileType.HDRFile;
						break;
					case "I":
						fileType = FileType.SPEEDFile;
						break;
					case "L":
						fileType = FileType.BOTFile;
						break;
					case "V":
						fileType = FileType.NVDFile;
						break;
					case "P":
						fileType = FileType.PCFGFile;
						break;
					}
					speedPreparedFiles.Add(fileName, path, fileType);
					DataTable table = speedPreparedFiles.Table;
					DataRow dataRow2 = table.Rows[0];
					if (!string.IsNullOrEmpty(text2))
					{
						if (text2.Length == 10)
						{
							dataRow2["EJRNo"] = text2.Substring(0, 8) + "-" + text2.Substring(8);
						}
						else
						{
							dataRow2["EJRNo"] = text2.Substring(0, 7) + "-" + text2.Substring(7);
						}
					}
					dataRow2["partNumber"] = text;
					SpeedPrepare speedPrepare = new SpeedPrepare(configuration, resourceManager, reporter);
					speedPrepare.CheckFile(text3, fileType);
					speedPrepare.Prepare(speedPreparedFiles);
					SpeedUpload speedUpload = new SpeedUpload(configuration, resourceManager, speedPreparedFiles, reporter, caltermCLI: true);
					speedUpload.UploadCompleteEvent += OnComplete;
					speedUpload.Start();
					return;
				}
				throw new ArgumentException("DataSet does not have the SPEEDUpload data table.", "argumentDataSet");
			}
			throw new ArgumentNullException("argumentDataSet", "Start( DataSet argumentDataSet ) with null DataSet");
		}
		catch (FileNameWithSpaceException)
		{
			string resultMessage = resourceManager.GetString("WhiteSpace");
			RaiseProcessCompleteEvent(flag: false, resultMessage);
		}
		catch (SystemException ex2)
		{
			string resultMessage2 = "SpeedTransferComponent.Start error -" + ex2.Message;
			RaiseProcessCompleteEvent(flag: false, resultMessage2);
		}
	}

	private void ValidateSubfileReleaseState(string subfileName)
	{
		Subfile subfile = new Subfile(subfileName);
		switch (subfile.ReleaseState)
		{
		case ReleaseState.Unreleased:
			throw new SpeedTransferException(resourceManager.GetString("UnreleasedSubfile"));
		case ReleaseState.Checked:
			throw new SpeedTransferException(resourceManager.GetString("CheckedSubfile"));
		case ReleaseState.Assembled:
			if (SubfileType.Three != subfile.GetSubFileType(subfileName))
			{
				throw new SpeedTransferException(resourceManager.GetString("AssembledSubfile"));
			}
			break;
		}
	}

	public void Start(XmlDocument xmlDoc)
	{
		//IL_0013: Unknown result type (might be due to invalid IL or missing references)
		//IL_0019: Expected O, but got Unknown
		XmlNodeList elementsByTagName = xmlDoc.GetElementsByTagName("Configuration");
		XmlElement val = (XmlElement)elementsByTagName.Item(0);
		if (val.HasAttribute("ProductID"))
		{
			configuration.ProductID = val.GetAttribute("ProductID");
		}
		else
		{
			configuration.ProductID = string.Empty;
		}
		if (val.HasAttribute("AppendReportFile"))
		{
			try
			{
				configuration.AppendReportFile = bool.Parse(val.GetAttribute("AppendReportFile"));
			}
			catch
			{
				configuration.AppendReportFile = false;
			}
		}
		else
		{
			configuration.AppendReportFile = false;
		}
		if (val.HasAttribute("DownloadReportFile") && !string.IsNullOrEmpty(val.GetAttribute("DownloadReportFile")))
		{
			configuration.DowndReportFileFullPathName = val.GetAttribute("DownloadReportFile");
		}
		if (val.HasAttribute("DownloadReportFormat") && !string.IsNullOrEmpty(val.GetAttribute("DownloadReportFormat")))
		{
			configuration.ReportFormat = val.GetAttribute("DownloadReportFormat");
		}
		Download(DownloadType.Full, caltermCLI: true);
	}

	public void RaiseProcessCompleteEvent(bool flag, string resultMessage)
	{
		if (this.ProcessCompleteEvent != null)
		{
			ProcessCompleteEventArgs args = new ProcessCompleteEventArgs(flag, resultMessage);
			this.ProcessCompleteEvent(this, args);
		}
	}

	public void RaiseProcessCompleteEvent(ProcessCompleteEventArgs processCompleteEventArgs)
	{
		if (this.ProcessCompleteEvent != null)
		{
			this.ProcessCompleteEvent(this, processCompleteEventArgs);
		}
	}

	private void ValidTheInputParameters(string ejrNumber, string uploadCalFilePathAndName, string ecmPartNumber)
	{
		if (!string.IsNullOrEmpty(ejrNumber))
		{
			if (ejrNumber.Length != 9 && ejrNumber.Length != 10)
			{
				string text = " EJR number: ";
				text += ejrNumber;
				text += " is not a ";
				text = text + 9 + "OR" + 10;
				text += " character string.";
				throw new InvalidEJRNumberException(24, text);
			}
			Match match;
			if (ejrNumber.Length == 9)
			{
				Regex regex = new Regex("[a-zA-Z]{2}[0-9a-zA-Z]{1}[0-9]{6}");
				match = regex.Match(ejrNumber);
			}
			else
			{
				Regex regex2 = new Regex("[CR]{2}[0-9]{1}[0-9]{7}");
				match = regex2.Match(ejrNumber);
			}
			if (!match.Success)
			{
				string message = resourceManager.GetString("InvalidEJRNumber");
				throw new InvalidEJRNumberException(24, message);
			}
		}
		if (!File.Exists(uploadCalFilePathAndName))
		{
			string text2 = " Upload file: ";
			text2 += uploadCalFilePathAndName;
			text2 += " does not exist.";
			throw new UploadFileNotExistException(25, text2);
		}
		if (ecmPartNumber.Length == 7 || ecmPartNumber.Length == 8)
		{
			Match match2;
			if (ecmPartNumber.Length == 8)
			{
				Regex regex3 = new Regex("[A-Z]{1}[0-9]{3}[A-Z]{1}[0-9]{3}");
				match2 = regex3.Match(ecmPartNumber);
			}
			else
			{
				Regex regex4 = new Regex("[0-9]{7}");
				match2 = regex4.Match(ecmPartNumber);
			}
			if (!match2.Success)
			{
				string message2 = resourceManager.GetString("InvalidPartNumber");
				throw new PartNumberValidationException(8, message2);
			}
			return;
		}
		string message3 = resourceManager.GetString("InvalidPartNumber");
		throw new PartNumberValidationException(8, message3);
	}
}
public class SpeedTransferException : BaseException
{
	public SpeedTransferException()
		: base(Facility.SpeedTransfer, 0)
	{
	}

	public SpeedTransferException(string message)
		: base(Facility.SpeedTransfer, 0, message)
	{
	}

	public SpeedTransferException(short errorID, string message)
		: base(Facility.SpeedTransfer, errorID, message)
	{
	}

	public SpeedTransferException(short errorID, string message, Exception e)
		: base(Facility.SpeedTransfer, errorID, message, e)
	{
	}
}
public class InvalidRecordException : SpeedTransferException
{
	private string record;

	public string Record
	{
		get
		{
			return record;
		}
		set
		{
			record = value;
		}
	}

	internal static InvalidRecordException New(MessageIDs id, string message, string record)
	{
		InvalidRecordException ex = new InvalidRecordException((short)id, message);
		ex.Record = record;
		return ex;
	}

	public InvalidRecordException()
	{
	}

	public InvalidRecordException(string message)
		: base(message)
	{
	}

	public InvalidRecordException(short errorID, string message)
		: base(errorID, message)
	{
	}

	public InvalidRecordException(short errorID, string message, Exception e)
		: base(errorID, message, e)
	{
	}
}
public class PartNumberValidationException : SpeedTransferException
{
	private string partNumber;

	public string PartNumber
	{
		get
		{
			return partNumber;
		}
		set
		{
			partNumber = value;
		}
	}

	internal static PartNumberValidationException New(MessageIDs id, string message, string partNumber)
	{
		PartNumberValidationException ex = new PartNumberValidationException((short)id, message);
		ex.PartNumber = partNumber;
		return ex;
	}

	public PartNumberValidationException()
	{
	}

	public PartNumberValidationException(string message)
		: base(message)
	{
	}

	public PartNumberValidationException(short errorID, string message)
		: base(errorID, message)
	{
	}

	public PartNumberValidationException(short errorID, string message, Exception e)
		: base(errorID, message, e)
	{
	}
}
public class DataTableNotFoundException : SpeedTransferException
{
	private string tablename;

	public string Tablename
	{
		get
		{
			return tablename;
		}
		set
		{
			tablename = value;
		}
	}

	internal static DataTableNotFoundException New(MessageIDs id, string message, string tablename)
	{
		DataTableNotFoundException ex = new DataTableNotFoundException((short)id, message);
		ex.Tablename = tablename;
		return ex;
	}

	public DataTableNotFoundException()
	{
	}

	public DataTableNotFoundException(string message)
		: base(message)
	{
	}

	public DataTableNotFoundException(short errorID, string message)
		: base(errorID, message)
	{
	}

	public DataTableNotFoundException(short errorID, string message, Exception e)
		: base(errorID, message, e)
	{
	}
}
public class InvalidEJRNumberException : SpeedTransferException
{
	private string inputEJRNumber;

	public string InputEJRNumber
	{
		get
		{
			return inputEJRNumber;
		}
		set
		{
			inputEJRNumber = value;
		}
	}

	internal static InvalidEJRNumberException New(MessageIDs id, string message, string inputEJRNumber)
	{
		InvalidEJRNumberException ex = new InvalidEJRNumberException((short)id, message);
		ex.inputEJRNumber = inputEJRNumber;
		return ex;
	}

	public InvalidEJRNumberException()
	{
	}

	public InvalidEJRNumberException(string message)
		: base(message)
	{
	}

	public InvalidEJRNumberException(short errorID, string message)
		: base(errorID, message)
	{
	}

	public InvalidEJRNumberException(short errorID, string message, Exception e)
		: base(errorID, message, e)
	{
	}
}
public class UploadFileNotExistException : SpeedTransferException
{
	private string uploadFile;

	public string UploadFile
	{
		get
		{
			return uploadFile;
		}
		set
		{
			uploadFile = value;
		}
	}

	internal static UploadFileNotExistException New(MessageIDs id, string message, string uploadFile)
	{
		UploadFileNotExistException ex = new UploadFileNotExistException((short)id, message);
		ex.UploadFile = uploadFile;
		return ex;
	}

	public UploadFileNotExistException()
	{
	}

	public UploadFileNotExistException(string message)
		: base(message)
	{
	}

	public UploadFileNotExistException(short errorID, string message)
		: base(errorID, message)
	{
	}

	public UploadFileNotExistException(short errorID, string message, Exception e)
		: base(errorID, message, e)
	{
	}
}
public class FileNameWithSpaceException : SpeedTransferException
{
}
public class SpeedTransferReport
{
	private const string TransformExtension = ".xslt";

	private const string TransformPrefix = "Cummins.SpeedTransferComponent.";

	internal static string DownloadReportSchema = "Cummins.SpeedTransferComponent.SpeedDownloadReport.xsd";

	internal static string UploadReportSchema = "Cummins.SpeedTransferComponent.SpeedUploadReport.xsd";

	internal static string SpeedDownloadReportTag = "SpeedDownloadReport";

	internal static string SpeedUploadReportTag = "SpeedUploadReport";

	internal static string HeaderTable = "header";

	internal static string SummaryTable = "summary";

	internal static string MessagesMasterTable = "messages";

	internal static string MessagesDetailTable = "message";

	internal static string MissingFilesMasterTable = "filesMissing";

	internal static string MissingFilesDetailTable = "missingFilename";

	internal static string DownloadedFilesMasterTable = "filesDownloaded";

	internal static string DownloadedFilesDetailTable = "downloadedFilename";

	internal static string PreparedFilesMasterTable = "filesPrepared";

	internal static string PreparedFilesDetailTable = "preparedFilename";

	internal static string UploadedFilesMasterTable = "filesUploaded";

	internal static string UploadedFilesDetailTable = "uploadedFilename";

	internal static string ErrorsMasterTable = "erroneousFiles";

	internal static string ErrorsDetailTable = "error";

	internal static string FullDownloadReport = "Full Download";

	internal static string ID = "_Id";

	private SpeedConfiguration configuration;

	private ResourceManager resourceManager;

	private ReportType reportType;

	private DataSet reportDataSet;

	private string reportFileName;

	private DateTime startTime;

	private DateTime lastOperationTime;

	private bool reportSessionActive;

	public SpeedTransferReport(SpeedConfiguration conf, ReportType reportType, string reportFileName, ResourceManager resourceManager)
	{
		configuration = conf;
		this.reportType = reportType;
		this.resourceManager = resourceManager;
		bool flag = false;
		if (reportFileName != null && reportFileName.Length != 0)
		{
			FileInfo fileInfo = new FileInfo(reportFileName);
			if (!fileInfo.Exists)
			{
				DirectoryInfo directory = fileInfo.Directory;
				if (!directory.Exists)
				{
					throw new FileNotFoundException(resourceManager.GetString("InvalidReportFile"), reportFileName);
				}
			}
			else
			{
				flag = true;
			}
		}
		this.reportFileName = reportFileName;
		Stream stream = null;
		if (reportType == ReportType.UploadReport)
		{
			reportDataSet = new DataSet(SpeedUploadReportTag);
			stream = Assembly.GetExecutingAssembly().GetManifestResourceStream(UploadReportSchema);
		}
		else
		{
			reportDataSet = new DataSet(SpeedDownloadReportTag);
			stream = Assembly.GetExecutingAssembly().GetManifestResourceStream(DownloadReportSchema);
		}
		if (stream == null || stream.Length == 0)
		{
			throw NewResourceException(Facility.SpeedTransfer, 23, resourceManager.GetString("InvalidReportSchema"), DownloadReportSchema);
		}
		reportDataSet.ReadXmlSchema(stream);
		if (reportFileName != null && reportFileName.Length != 0 && flag)
		{
			try
			{
				reportDataSet.ReadXml(reportFileName);
			}
			catch
			{
			}
		}
		reportSessionActive = false;
		startTime = DateTime.Now;
		lastOperationTime = DateTime.Now;
	}

	public virtual void AddEntry(string fileName, ReportEntryType entryType, short messageCode, string message)
	{
		if (fileName == null || fileName.Length == 0)
		{
			throw new ArgumentNullException("fileName");
		}
		if (!reportSessionActive)
		{
			ActivateReportSession();
		}
		string text = null;
		string text2 = null;
		DataTable dataTable = null;
		switch (entryType)
		{
		case ReportEntryType.DownloadedFileEntry:
			text = DownloadedFilesMasterTable;
			text2 = DownloadedFilesDetailTable;
			break;
		case ReportEntryType.MissingFileEntry:
			text = MissingFilesMasterTable;
			text2 = MissingFilesDetailTable;
			break;
		case ReportEntryType.PreparedFileEntry:
			text = PreparedFilesMasterTable;
			text2 = PreparedFilesDetailTable;
			break;
		case ReportEntryType.UploadedFileEntry:
			text = UploadedFilesMasterTable;
			text2 = UploadedFilesDetailTable;
			break;
		case ReportEntryType.ErrorEntry:
			text = ErrorsMasterTable;
			text2 = ErrorsDetailTable;
			break;
		default:
			throw new InvalidOperationException("Invalid Case");
		}
		dataTable = reportDataSet.Tables[text2];
		if (dataTable != null)
		{
			int masterTableID = GetMasterTableID(entryType);
			DataRow dataRow = dataTable.NewRow();
			dataRow[0] = fileName;
			string columnName = text + ID;
			dataRow[columnName] = masterTableID;
			dataTable.Rows.Add(dataRow);
			dataTable.AcceptChanges();
			AddMessage(fileName, messageCode, message);
			lastOperationTime = DateTime.Now;
			return;
		}
		throw DataTableNotFoundException.New(MessageIDs.TableNotFoundInReport, resourceManager.GetString("TableNotFoundInReport"), text2);
	}

	private int GetMasterTableID(ReportEntryType entryType)
	{
		DataTable dataTable = null;
		string text = null;
		text = entryType switch
		{
			ReportEntryType.DownloadedFileEntry => DownloadedFilesMasterTable, 
			ReportEntryType.MissingFileEntry => MissingFilesMasterTable, 
			ReportEntryType.PreparedFileEntry => PreparedFilesMasterTable, 
			ReportEntryType.UploadedFileEntry => UploadedFilesMasterTable, 
			ReportEntryType.ErrorEntry => ErrorsMasterTable, 
			_ => throw new InvalidOperationException("Invalid Case"), 
		};
		dataTable = reportDataSet.Tables[text];
		int num = 0;
		if (dataTable != null)
		{
			if (dataTable.Rows.Count == 0)
			{
				DataRow row = dataTable.NewRow();
				dataTable.Rows.Add(row);
			}
			DataRow dataRow = dataTable.Rows[0];
			string columnName = text + ID;
			return int.Parse(dataRow[columnName].ToString());
		}
		throw DataTableNotFoundException.New(MessageIDs.TableNotFoundInReport, resourceManager.GetString("TableNotFoundInReport"), text);
	}

	public void AddMessage(string fileName, short messageCode, string message)
	{
		if (fileName == null || fileName.Length == 0)
		{
			throw new ArgumentNullException("file name");
		}
		if (messageCode == 0)
		{
			throw new ArgumentNullException("Message code");
		}
		if (message == null || message.Length == 0)
		{
			throw new ArgumentNullException("Message");
		}
		DataTable dataTable = reportDataSet.Tables[MessagesMasterTable];
		if (dataTable == null)
		{
			throw DataTableNotFoundException.New(MessageIDs.TableNotFoundInReport, resourceManager.GetString("TableNotFoundInReport"), MessagesMasterTable);
		}
		DataTable dataTable2 = reportDataSet.Tables[MessagesDetailTable];
		if (dataTable2 == null)
		{
			throw DataTableNotFoundException.New(MessageIDs.TableNotFoundInReport, resourceManager.GetString("TableNotFoundInReport"), MessagesDetailTable);
		}
		if (dataTable.Rows.Count == 0)
		{
			DataRow row = dataTable.NewRow();
			dataTable.Rows.Add(row);
		}
		DataRow dataRow = dataTable.Rows[0];
		string columnName = MessagesMasterTable + ID;
		int num = int.Parse(dataRow[columnName].ToString());
		DataRow dataRow2 = dataTable2.NewRow();
		dataRow2[columnName] = num;
		dataRow2["code"] = messageCode;
		dataRow2["fileName"] = fileName;
		dataRow2["content"] = message;
		dataTable2.Rows.Add(dataRow2);
		dataTable2.AcceptChanges();
	}

	public virtual string SaveToFile()
	{
		if (!reportSessionActive)
		{
			throw new SpeedTransferException(resourceManager.GetString("InvalidReportSession"));
		}
		PopulateSummaryTable();
		PopulateHeaderTable();
		if (!reportDataSet.HasErrors)
		{
			if (reportFileName == null)
			{
				if (reportType == ReportType.UploadReport)
				{
					reportFileName = configuration.GenerateFullUploadReportName();
				}
				else if (configuration.DowndReportFileFullPathName == string.Empty)
				{
					reportFileName = configuration.GenerateFullDownloadReportName();
				}
				else
				{
					reportFileName = configuration.DowndReportFileFullPathName;
				}
			}
			if (!Directory.Exists(Path.GetDirectoryName(reportFileName)))
			{
				try
				{
					EventLogger.Info("Directory Not Found", "The Default path for saving the report file was not available");
					Directory.CreateDirectory(Path.GetDirectoryName(reportFileName));
					EventLogger.Info("Directory Created", "Directory created for saving the report file at " + reportFileName);
				}
				catch (Exception)
				{
					string fileName = Path.GetFileName(reportFileName);
					reportFileName = Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory) + "\\" + fileName;
					EventLogger.Info("Directory Created", "Directory is created for saving the report file at " + reportFileName);
				}
			}
			if (configuration.ReportFormat.ToUpper().Equals("XML"))
			{
				reportDataSet.WriteXml(reportFileName);
			}
			else
			{
				TransformReport();
			}
			reportSessionActive = false;
			return reportFileName;
		}
		throw new SpeedTransferException(resourceManager.GetString("InvalidReport"));
	}

	private void SetProductID(string productID)
	{
		DataTable dataTable = reportDataSet.Tables[HeaderTable];
		DataRow dataRow = null;
		try
		{
			dataRow = dataTable.Rows[0];
			dataRow["product"] = productID;
		}
		catch (IndexOutOfRangeException)
		{
			dataRow = dataTable.NewRow();
			dataRow["product"] = productID;
			dataTable.Rows.Add(dataRow);
		}
		dataRow["product"] = productID;
		dataTable.AcceptChanges();
	}

	private void ActivateReportSession()
	{
		if (reportSessionActive)
		{
			throw new InvalidOperationException(resourceManager.GetString("InvalidReportStart"));
		}
		reportSessionActive = true;
		SetProductID(configuration.ProductID);
	}

	private void PopulateSummaryTable()
	{
		DataTable dataTable = reportDataSet.Tables[SummaryTable];
		DataRow dataRow = null;
		dataRow = ((dataTable.Rows.Count != 0) ? dataTable.Rows[0] : dataTable.NewRow());
		if (reportType == ReportType.UploadReport)
		{
			dataRow["totalFilesUploaded"] = reportDataSet.Tables[UploadedFilesDetailTable].Rows.Count;
			dataRow["totalFilesPrepared"] = reportDataSet.Tables[PreparedFilesDetailTable].Rows.Count;
		}
		else
		{
			dataRow["totalFilesDownloaded"] = reportDataSet.Tables[DownloadedFilesDetailTable].Rows.Count;
			dataRow["totalFilesMissing"] = reportDataSet.Tables[MissingFilesDetailTable].Rows.Count;
		}
		dataRow["errors"] = reportDataSet.Tables[ErrorsDetailTable].Rows.Count;
		if (dataTable.Rows.Count == 0)
		{
			dataTable.Rows.Add(dataRow);
		}
		dataTable.AcceptChanges();
	}

	private void PopulateHeaderTable()
	{
		DataTable dataTable = reportDataSet.Tables[HeaderTable];
		DataRow dataRow = null;
		dataRow = dataTable.Rows[0];
		if (dataRow != null)
		{
			dataRow["startTime"] = startTime.ToString();
			dataRow["endTime"] = lastOperationTime.ToString();
			if (reportType == ReportType.FullDownloadReport)
			{
				dataRow["downloadType"] = FullDownloadReport;
			}
			dataTable.AcceptChanges();
			return;
		}
		throw new InvalidOperationException(resourceManager.GetString("InvalidHeaderTableState"));
	}

	private void TransformReport()
	{
		//IL_0059: Unknown result type (might be due to invalid IL or missing references)
		//IL_0060: Expected O, but got Unknown
		//IL_0060: Unknown result type (might be due to invalid IL or missing references)
		//IL_0067: Expected O, but got Unknown
		//IL_00b8: Unknown result type (might be due to invalid IL or missing references)
		//IL_00bf: Expected O, but got Unknown
		//IL_00c4: Unknown result type (might be due to invalid IL or missing references)
		//IL_00df: Expected O, but got Unknown
		string text = "speedDownload";
		if (ReportType.UploadReport == reportType)
		{
			text = "speedUpload";
		}
		string tempFileName = Path.GetTempFileName();
		reportDataSet.WriteXml(tempFileName, XmlWriteMode.IgnoreSchema);
		StreamWriter streamWriter = null;
		streamWriter = ((!configuration.AppendReportFile) ? File.CreateText(reportFileName) : File.AppendText(reportFileName));
		Stream stream = File.OpenRead(tempFileName);
		XPathDocument val = new XPathDocument(stream);
		XslTransform val2 = new XslTransform();
		string name = "Cummins.SpeedTransferComponent." + text + "_" + configuration.ReportFormat.ToLower() + ".xslt";
		XmlTextReader val3 = new XmlTextReader(Assembly.GetExecutingAssembly().GetManifestResourceStream(name));
		val2.Load((IXPathNavigable)new XPathDocument((XmlReader)(object)val3, (XmlSpace)2), (XmlResolver)null, GetType().Assembly.Evidence);
		val2.Transform((IXPathNavigable)(object)val, (XsltArgumentList)null, (TextWriter)streamWriter, (XmlResolver)null);
		streamWriter.WriteLine();
		streamWriter.WriteLine();
		streamWriter.Close();
		stream.Close();
		((XmlReader)val3).Close();
		File.Delete(tempFileName);
	}

	private ResourceException NewResourceException(Facility facility, short errId, string message, string resourceName)
	{
		ResourceException ex = new ResourceException(facility, errId, message);
		ex.ContextData = resourceName;
		return ex;
	}
}
public class SpeedUpload
{
	private const string NotAvailable = "Not Available";

	internal static string SubfilePrefix = "B";

	internal static short MsgInvalidPreparedFile = 909;

	internal static short MsgInvalidUploadPath = 910;

	internal static short MsgUploadSuccess = 911;

	internal static short MsgUploadFailure = 912;

	private SpeedConfiguration configuration;

	private ResourceManager resourceManager;

	private SpeedPreparedFiles preparedFiles;

	private SpeedTransferReport reporter;

	private bool forCLI;

	private bool cliSuccess;

	private string _speedUploadPath = string.Empty;

	public event EventHandler UploadCompleteEvent;

	public event ProgressChangedEventHandler ProgressChangedEvent;

	public SpeedUpload(SpeedConfiguration configuration, ResourceManager resourceManager, SpeedPreparedFiles preparedFiles, SpeedTransferReport reporter)
	{
		InternalInitialize(configuration, resourceManager, preparedFiles, reporter, caltermCLI: false);
	}

	public SpeedUpload(SpeedConfiguration configuration, ResourceManager resourceManager, SpeedPreparedFiles preparedFiles, SpeedTransferReport reporter, bool caltermCLI)
	{
		InternalInitialize(configuration, resourceManager, preparedFiles, reporter, caltermCLI);
	}

	private void InternalInitialize(SpeedConfiguration configuration, ResourceManager resourceManager, SpeedPreparedFiles preparedFiles, SpeedTransferReport reporter, bool caltermCLI)
	{
		if (configuration == null)
		{
			throw new ArgumentNullException("configuration");
		}
		if (resourceManager == null)
		{
			throw new ArgumentNullException("resource Manager");
		}
		if (preparedFiles == null)
		{
			throw new ArgumentNullException("prepared files");
		}
		if (reporter == null)
		{
			throw new ArgumentNullException("upload reporter");
		}
		this.configuration = configuration;
		this.resourceManager = resourceManager;
		this.reporter = reporter;
		this.preparedFiles = preparedFiles;
		forCLI = caltermCLI;
		_speedUploadPath = this.configuration.SpeedServerUploadPath;
		if (configuration.CESProduct())
		{
			_speedUploadPath += "_CES";
		}
		IsSpeedTransferSupported();
	}

	public void Start()
	{
		string text = string.Empty;
		try
		{
			cliSuccess = false;
			string text2 = configuration.TempUploadPath;
			if (!text2.EndsWith("\\"))
			{
				text2 += "\\";
			}
			if (!Directory.Exists(text2))
			{
				Directory.CreateDirectory(text2);
			}
			int count = preparedFiles.Count;
			for (int i = 0; i < count; i++)
			{
				string preparedFileName = preparedFiles[i].PreparedFileName;
				string sourcePath = text2 + preparedFileName;
				string text3 = GetUploadPath(preparedFiles[i].ProductID) + preparedFileName;
				string status = string.Format(resourceManager.GetString("UploadingFile"), text3);
				RaiseProgressEvent(status, count, i + 1);
				UploadOneFile(sourcePath, text3);
			}
			preparedFiles.Clear();
			cliSuccess = true;
		}
		catch (SpeedTransferException ex)
		{
			int count2 = preparedFiles.Count;
			for (int j = 0; j < count2; j++)
			{
				string preparedFileName2 = preparedFiles[j].PreparedFileName;
				string text4 = configuration.TempUploadPath + "\\" + preparedFileName2;
				if (File.Exists(text4))
				{
					File.Delete(text4);
				}
				reporter.AddEntry(text4, ReportEntryType.ErrorEntry, MsgUploadFailure, resourceManager.GetString(MsgUploadFailure.ToString()) + ". " + ex.Message);
			}
			if (!forCLI)
			{
				EventLogger.Error("SPEED Upload", ex.Message);
			}
			else
			{
				text = ex.Message;
			}
		}
		finally
		{
			string text5 = null;
			try
			{
				text5 = reporter.SaveToFile();
				if (!forCLI)
				{
					RaiseUploadCompleteEvent();
					Process.Start(text5);
				}
				else
				{
					string text6 = string.Empty;
					if (text.Length > 0)
					{
						text6 = text + " ";
					}
					text6 += $"SPEED Upload report file: {text5}.";
					ProcessCompleteEventArgs processCompleteEventArgs = new ProcessCompleteEventArgs(cliSuccess, text6);
					RaiseUploadCompleteEvent(processCompleteEventArgs);
				}
			}
			catch (Exception ex2)
			{
				EventLogger.Error("SPEED Upload", ex2.Message);
				RaiseUploadCompleteEvent();
			}
		}
	}

	protected void RaiseProgressEvent(string status, int total, int current)
	{
		if (this.ProgressChangedEvent != null)
		{
			ProgressEventArgs progress = new ProgressEventArgs(status, total, current);
			this.ProgressChangedEvent(this, progress);
		}
	}

	protected void RaiseUploadCompleteEvent()
	{
		if (this.UploadCompleteEvent != null)
		{
			this.UploadCompleteEvent(this, EventArgs.Empty);
		}
	}

	protected void RaiseUploadCompleteEvent(ProcessCompleteEventArgs processCompleteEventArgs)
	{
		if (this.UploadCompleteEvent != null)
		{
			this.UploadCompleteEvent(this, processCompleteEventArgs);
		}
	}

	private void UploadOneFile(string sourcePath, string destinationPath)
	{
		cliSuccess = false;
		if (string.IsNullOrEmpty(sourcePath))
		{
			throw new ArgumentNullException("source path");
		}
		if (destinationPath == null || destinationPath.Length == 0)
		{
			throw new ArgumentNullException("destination path");
		}
		bool flag = true;
		if (!File.Exists(sourcePath))
		{
			reporter.AddEntry(sourcePath, ReportEntryType.ErrorEntry, MsgInvalidPreparedFile, resourceManager.GetString(MsgInvalidPreparedFile.ToString()));
			flag = false;
		}
		if (flag)
		{
			string path = destinationPath[..destinationPath.LastIndexOf('\\')];
			if (!Directory.Exists(path))
			{
				reporter.AddEntry(destinationPath, ReportEntryType.ErrorEntry, MsgInvalidUploadPath, resourceManager.GetString(MsgInvalidUploadPath.ToString()));
				flag = false;
			}
		}
		if (!flag)
		{
			return;
		}
		try
		{
			File.Delete(destinationPath);
			int num = sourcePath.LastIndexOf('\\');
			string text = sourcePath.Substring(num + 1);
			if (text.ToUpper().StartsWith(SubfilePrefix))
			{
				Subfile subfile = new Subfile(sourcePath);
				if (subfile.ReleaseState != ReleaseState.Unreleased)
				{
					subfile.ReleaseState = ReleaseState.Released;
					subfile.HasBusinessHeaderRecord = false;
					subfile.Save();
				}
			}
			try
			{
				File.SetAttributes(sourcePath, FileAttributes.ReadOnly);
			}
			catch
			{
			}
			File.Move(sourcePath, destinationPath);
			if (!File.Exists(destinationPath))
			{
				reporter.AddEntry(destinationPath, ReportEntryType.ErrorEntry, MsgUploadFailure, resourceManager.GetString(MsgUploadFailure.ToString()));
			}
			else
			{
				reporter.AddEntry(destinationPath, ReportEntryType.UploadedFileEntry, MsgUploadSuccess, resourceManager.GetString(MsgUploadSuccess.ToString()));
			}
		}
		catch (Exception ex)
		{
			reporter.AddEntry(destinationPath, ReportEntryType.ErrorEntry, MsgUploadFailure, resourceManager.GetString(MsgUploadFailure.ToString()) + ". " + ex.Message);
			flag = false;
		}
		finally
		{
			cliSuccess = flag;
			if (File.Exists(sourcePath))
			{
				try
				{
					File.Delete(sourcePath);
				}
				catch
				{
				}
			}
		}
	}

	private string GetUploadPath(string productID)
	{
		string text = _speedUploadPath;
		if (text[text.Length - 1] != '\\')
		{
			text += "\\";
		}
		text = text + productID + "\\";
		if (!Directory.Exists(text))
		{
			string message = string.Format(resourceManager.GetString("InvalidSpeedServerPath"), text);
			throw new SpeedTransferException(22, message);
		}
		return text;
	}

	private bool IsSpeedTransferSupported()
	{
		IProductInformationService productInformationService = (IProductInformationService)ServiceManager.Services.GetService(typeof(IProductInformationService));
		if (productInformationService.GetProductInformation(configuration.ProductID, ProductInformationType.SpeedSupport).Equals("Not Available"))
		{
			string message = string.Format(resourceManager.GetString(MessageIDs.UnsupportedProduct.ToString()), configuration.ProductID);
			throw new SpeedTransferException(message);
		}
		return true;
	}
}
public enum ReleaseState
{
	Released = 240,
	Verified = 252,
	Assembled = 253,
	Checked = 254,
	Unreleased = 255
}
public enum SubfileType
{
	None,
	One,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight
}
public class Subfile
{
	internal static string StarBPrefix = "B";

	internal static string StarCPrefix = "*C";

	internal static int ReleaseStateIndex = 2;

	internal static int SubfileTypeIndex = 4;

	internal static int ByteLength = 2;

	internal static string ReleaseStateFormat = "X2";

	private string subfileName;

	private ArrayList records;

	private bool hasBusinessHeaderRecord;

	private string businessHeaderRecord;

	public ReleaseState ReleaseState
	{
		get
		{
			return ReadReleaseState();
		}
		set
		{
			SetReleaseState(value);
		}
	}

	public bool HasBusinessHeaderRecord
	{
		get
		{
			if (records != null && records.Count != 0)
			{
				string text = (string)records[0];
				hasBusinessHeaderRecord = text.StartsWith(StarBPrefix);
			}
			else
			{
				hasBusinessHeaderRecord = false;
			}
			return hasBusinessHeaderRecord;
		}
		set
		{
			if (hasBusinessHeaderRecord != value)
			{
				if (records == null || records.Count == 0)
				{
					throw new InvalidOperationException("Subfile does not contain header records");
				}
				string text = (string)records[0];
				if (hasBusinessHeaderRecord && !value)
				{
					businessHeaderRecord = text;
					records.RemoveAt(0);
					hasBusinessHeaderRecord = value;
				}
				else if (!hasBusinessHeaderRecord && value && businessHeaderRecord.Length > 0)
				{
					records.Insert(0, businessHeaderRecord);
					hasBusinessHeaderRecord = value;
				}
			}
		}
	}

	public Subfile(string subfileName)
	{
		if (subfileName == null || subfileName.Length == 0)
		{
			throw new ArgumentNullException("subfileName");
		}
		this.subfileName = subfileName;
		if (File.Exists(subfileName))
		{
			TextReader textReader = new StreamReader(subfileName);
			records = new ArrayList();
			while (textReader.Peek() >= 0)
			{
				records.Add(textReader.ReadLine());
			}
			textReader.Close();
			string text = (string)records[0];
			if (text.StartsWith(StarBPrefix))
			{
				businessHeaderRecord = text;
				hasBusinessHeaderRecord = true;
			}
			else
			{
				businessHeaderRecord = "";
				hasBusinessHeaderRecord = false;
			}
			return;
		}
		throw new FileNotFoundException("File cannot be located", subfileName);
	}

	public void Save()
	{
		TextWriter textWriter = new StreamWriter(subfileName);
		foreach (string record in records)
		{
			textWriter.WriteLine(record);
		}
		textWriter.Close();
		CRCFile cRCFile = new CRCFile();
		cRCFile.SetSubfileCRC(subfileName);
	}

	public SubfileType GetSubFileType(string subFileName)
	{
		SubfileType subfileType = SubfileType.None;
		byte b = 0;
		try
		{
			int startIndex = 4;
			int length = 2;
			TextReader textReader = new StreamReader(subFileName);
			string text = textReader.ReadLine();
			if (text[0] != '*' || text[1] != 'C')
			{
				text = textReader.ReadLine();
			}
			textReader.Close();
			return byte.Parse(text.Substring(startIndex, length), NumberStyles.AllowHexSpecifier).ToString() switch
			{
				"1" => SubfileType.One, 
				"2" => SubfileType.Two, 
				"3" => SubfileType.Three, 
				"4" => SubfileType.Four, 
				"5" => SubfileType.Five, 
				"6" => SubfileType.Six, 
				"7" => SubfileType.Seven, 
				"8" => SubfileType.Eight, 
				_ => SubfileType.None, 
			};
		}
		catch
		{
			return SubfileType.None;
		}
	}

	private ReleaseState ReadReleaseState()
	{
		int index = 0;
		string text = (string)records[index];
		if (text.IndexOf(StarCPrefix) == -1)
		{
			index = 1;
			text = (string)records[index];
			if (text.IndexOf(StarCPrefix) == -1)
			{
				throw NewFileValidationException(Facility.SpeedTransfer, 11, "Invalid Subfile", subfileName);
			}
		}
		string s = text.Substring(ReleaseStateIndex, ByteLength);
		return (ReleaseState)byte.Parse(s, NumberStyles.AllowHexSpecifier);
	}

	private void SetReleaseState(ReleaseState releaseState)
	{
		int index = 0;
		string text = (string)records[index];
		if (text.IndexOf("*C") == -1)
		{
			index = 1;
			text = (string)records[index];
			if (text.IndexOf("*C") == -1)
			{
				throw NewFileValidationException(Facility.SpeedTransfer, 11, "Invalid Subfile", subfileName);
			}
		}
		text = StarCPrefix + ((byte)releaseState).ToString(ReleaseStateFormat) + text.Substring(SubfileTypeIndex, ByteLength);
		Checksum.AddLineChecksum(ref text);
		records[index] = text;
	}

	private FileValidationException NewFileValidationException(Facility facility, short errId, string message, string filename)
	{
		FileValidationException ex = new FileValidationException(facility, errId, message);
		ex.ContextData = filename;
		return ex;
	}
}
public enum DownloadType
{
	NotApplicable = 1,
	Full
}
public enum PostDownloadAction
{
	NoAction,
	CopyToUnrlcal,
	DeleteFromCal
}
public enum ReportEntryType
{
	MissingFileEntry,
	DownloadedFileEntry,
	UploadedFileEntry,
	PreparedFileEntry,
	ErrorEntry
}
public enum ReportType
{
	FullDownloadReport,
	FiveDaysDownloadReport,
	UploadReport
}
public enum FileType
{
	Other,
	Calibration,
	Subfile,
	ControlFile,
	E2MFile,
	ECFGFile,
	RIOFile,
	HDRFile,
	SPEEDFile,
	BOTFile,
	NVDFile,
	PCFGFile
}
public enum ReleasePhase
{
	Invalid,
	EPhase,
	DPhase,
	LPhase,
	PPhase,
	Obsolete
}
