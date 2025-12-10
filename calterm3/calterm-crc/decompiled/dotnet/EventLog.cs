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
using System.Runtime.Versioning;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using System.Windows.Forms.Layout;
using System.Xml;
using Balloons;
using Cummins.MessageDialog;
using Cummins.Services;
using Cummins.Widgets;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - EventLog")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTitle("Poodle")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.EventLog;

public delegate void DoubleClickEventHandler(object sender, EventArgs e);
public class DataBoundGrid : UserControl
{
	private Container components;

	private DataGrid dataGrid1;

	private string xmlFileName;

	private DataGridTableStyle dgts1;

	private string xmlTableName;

	private DataTable DT;

	private bool insideCell;

	private bool fullRowSelection;

	public string XmlFileName
	{
		get
		{
			return xmlFileName;
		}
		set
		{
			xmlFileName = value;
		}
	}

	public string XmlTableName
	{
		get
		{
			return xmlTableName;
		}
		set
		{
			xmlTableName = value;
		}
	}

	public DataGrid DtGrid => dataGrid1;

	public DataGridTableStyle GridTableStyle
	{
		get
		{
			return dgts1;
		}
		set
		{
			dgts1 = value;
		}
	}

	public DataTable DtTable
	{
		get
		{
			return DT;
		}
		set
		{
			DT = value;
		}
	}

	public bool InsideCellClick
	{
		get
		{
			return insideCell;
		}
		set
		{
			insideCell = value;
		}
	}

	public bool AllowFullRowSelection
	{
		get
		{
			return fullRowSelection;
		}
		set
		{
			fullRowSelection = value;
		}
	}

	public static event DoubleClickEventHandler DoubleClickEventFired;

	public DataBoundGrid()
	{
		InitializeComponent();
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
		//IL_00b5: Unknown result type (might be due to invalid IL or missing references)
		//IL_00bf: Expected O, but got Unknown
		//IL_00e3: Unknown result type (might be due to invalid IL or missing references)
		//IL_00ed: Expected O, but got Unknown
		dataGrid1 = new DataGrid();
		((ISupportInitialize)dataGrid1).BeginInit();
		((Control)this).SuspendLayout();
		dataGrid1.DataMember = "";
		((Control)dataGrid1).Dock = (DockStyle)5;
		dataGrid1.HeaderForeColor = SystemColors.ControlText;
		((Control)dataGrid1).Location = new Point(0, 0);
		((Control)dataGrid1).Name = "dataGrid1";
		dataGrid1.ReadOnly = true;
		dataGrid1.RowHeadersVisible = false;
		((Control)dataGrid1).Size = new Size(150, 150);
		((Control)dataGrid1).TabIndex = 0;
		((Control)dataGrid1).KeyUp += new KeyEventHandler(dataGrid1_KeyUp);
		((Control)dataGrid1).DoubleClick += dataGrid1_DoubleClick;
		((Control)dataGrid1).MouseUp += new MouseEventHandler(dataGrid1_MouseUp);
		((Control)this).Controls.Add((Control)(object)dataGrid1);
		((Control)this).Name = "DataBoundGrid";
		((ISupportInitialize)dataGrid1).EndInit();
		((Control)this).ResumeLayout(false);
	}

	public void RefreshData()
	{
		//IL_0006: Unknown result type (might be due to invalid IL or missing references)
		//IL_000c: Expected O, but got Unknown
		try
		{
			XmlTextReader xmlReader = new XmlTextReader(xmlFileName);
			RefreshData(xmlReader);
		}
		catch (Exception ex)
		{
			throw ex;
		}
	}

	public void RefreshData(XmlTextReader xmlReader)
	{
		XmlDataDocument xmlDataDocument = new XmlDataDocument();
		try
		{
			xmlDataDocument.DataSet.ReadXml((XmlReader?)(object)xmlReader);
			RefreshData(xmlDataDocument.DataSet);
		}
		catch (Exception ex)
		{
			throw ex;
		}
	}

	public void RefreshData(DataSet sourceDataSet)
	{
		try
		{
			if (sourceDataSet == null)
			{
				throw new ArgumentNullException("sourceDataSet");
			}
			DT = sourceDataSet.Tables[xmlTableName];
			if (DT == null)
			{
				throw new ArgumentException("sourceDataSet must contain an Items table", "sourceDataSet");
			}
			dataGrid1.DataSource = sourceDataSet;
			initGridStyles(DT);
		}
		catch (Exception ex)
		{
			throw ex;
		}
	}

	public void initGridStyles(DataTable DT)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_000b: Expected O, but got Unknown
		//IL_0070: Unknown result type (might be due to invalid IL or missing references)
		//IL_0076: Expected O, but got Unknown
		dgts1 = new DataGridTableStyle();
		dgts1.DataGrid = dataGrid1;
		dataGrid1.CaptionText = xmlTableName;
		dataGrid1.DataSource = DT;
		dgts1.RowHeadersVisible = false;
		dgts1.MappingName = xmlTableName;
		foreach (DataColumn column in DT.Columns)
		{
			DataGridColumnStyle val = (DataGridColumnStyle)new DataGridTextBoxColumn();
			val.MappingName = column.ColumnName;
			val.HeaderText = column.ColumnName;
			val.NullText = "";
			val.Width = (((Control)dataGrid1).Width - 4) / DT.Columns.Count;
			dgts1.GridColumnStyles.Add(val);
		}
		dataGrid1.TableStyles.Add(dgts1);
	}

	public void ResetData()
	{
		dataGrid1.DataSource = null;
		dataGrid1.DataMember = "";
		dataGrid1.CaptionText = "";
		dgts1.MappingName = "";
	}

	public void columnHide(string column)
	{
		//IL_0019: Unknown result type (might be due to invalid IL or missing references)
		//IL_001f: Expected O, but got Unknown
		//IL_0033: Unknown result type (might be due to invalid IL or missing references)
		//IL_0039: Expected O, but got Unknown
		foreach (DataGridTableStyle item in (BaseCollection)dataGrid1.TableStyles)
		{
			DataGridTableStyle val = item;
			foreach (DataGridColumnStyle item2 in (BaseCollection)val.GridColumnStyles)
			{
				DataGridColumnStyle val2 = item2;
				if (val2.MappingName.IndexOf(column) == 0)
				{
					val2.Width = 0;
				}
			}
		}
	}

	public void columnSetWidth(string column, int width)
	{
		//IL_0019: Unknown result type (might be due to invalid IL or missing references)
		//IL_001f: Expected O, but got Unknown
		//IL_0033: Unknown result type (might be due to invalid IL or missing references)
		//IL_0039: Expected O, but got Unknown
		foreach (DataGridTableStyle item in (BaseCollection)dataGrid1.TableStyles)
		{
			DataGridTableStyle val = item;
			foreach (DataGridColumnStyle item2 in (BaseCollection)val.GridColumnStyles)
			{
				DataGridColumnStyle val2 = item2;
				if (val2.MappingName.IndexOf(column) == 0)
				{
					val2.Width = width;
				}
			}
		}
	}

	public virtual void columnAutoFit()
	{
		//IL_0019: Unknown result type (might be due to invalid IL or missing references)
		//IL_001f: Expected O, but got Unknown
		//IL_0033: Unknown result type (might be due to invalid IL or missing references)
		//IL_0039: Expected O, but got Unknown
		foreach (DataGridTableStyle item in (BaseCollection)dataGrid1.TableStyles)
		{
			DataGridTableStyle val = item;
			foreach (DataGridColumnStyle item2 in (BaseCollection)val.GridColumnStyles)
			{
				DataGridColumnStyle val2 = item2;
				if (val2.Width != 0)
				{
					val2.Width = columnPreferredWidth(val2.MappingName);
				}
			}
		}
	}

	public void columnAutoDistribute()
	{
		//IL_001e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0024: Expected O, but got Unknown
		//IL_003c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0042: Expected O, but got Unknown
		//IL_0084: Unknown result type (might be due to invalid IL or missing references)
		//IL_008a: Expected O, but got Unknown
		foreach (DataGridTableStyle item in (BaseCollection)dataGrid1.TableStyles)
		{
			DataGridTableStyle val = item;
			int num = 0;
			foreach (DataGridColumnStyle item2 in (BaseCollection)val.GridColumnStyles)
			{
				DataGridColumnStyle val2 = item2;
				if (val2.Width == 0)
				{
					num++;
				}
			}
			foreach (DataGridColumnStyle item3 in (BaseCollection)val.GridColumnStyles)
			{
				DataGridColumnStyle val3 = item3;
				if (val3.Width != 0)
				{
					val3.Width = (((Control)dataGrid1).Width - 4) / (DT.Columns.Count - num);
				}
			}
		}
	}

	public int columnPreferredWidth(string column)
	{
		int num = 0;
		Graphics val = ((Control)this).CreateGraphics();
		foreach (DataRow row in DT.Rows)
		{
			SizeF sizeF = val.MeasureString(row[column].ToString(), ((Control)dataGrid1).Font);
			if (sizeF.Width > (float)num)
			{
				num = (int)sizeF.Width;
			}
		}
		val.Dispose();
		return num;
	}

	public void ColumnReadOnly(string column, bool readOnly)
	{
		//IL_0019: Unknown result type (might be due to invalid IL or missing references)
		//IL_001f: Expected O, but got Unknown
		//IL_0033: Unknown result type (might be due to invalid IL or missing references)
		//IL_0039: Expected O, but got Unknown
		foreach (DataGridTableStyle item in (BaseCollection)dataGrid1.TableStyles)
		{
			DataGridTableStyle val = item;
			foreach (DataGridColumnStyle item2 in (BaseCollection)val.GridColumnStyles)
			{
				DataGridColumnStyle val2 = item2;
				if (val2.MappingName.IndexOf(column) == 0)
				{
					val2.ReadOnly = readOnly;
					return;
				}
			}
		}
	}

	private void dataGrid1_MouseUp(object sender, MouseEventArgs e)
	{
		//IL_0029: Unknown result type (might be due to invalid IL or missing references)
		//IL_002f: Invalid comparison between Unknown and I4
		//IL_0043: Unknown result type (might be due to invalid IL or missing references)
		if (fullRowSelection)
		{
			Point point = new Point(e.X, e.Y);
			HitTestInfo val = dataGrid1.HitTest(point);
			if ((int)val.Type == 1)
			{
				dataGrid1.CurrentCell = new DataGridCell(val.Row, val.Column);
				dataGrid1.Select(val.Row);
				insideCell = true;
			}
			else
			{
				insideCell = false;
			}
		}
	}

	public int PreferredHeight()
	{
		int num = 0;
		int count = DT.Rows.Count;
		num = ((((Control)dataGrid1).Controls[2].Size.Height <= dataGrid1.TableStyles[0].PreferredRowHeight) ? dataGrid1.TableStyles[0].PreferredRowHeight : ((Control)dataGrid1).Controls[2].Size.Height);
		return count * num;
	}

	public int PreferredWidth()
	{
		int num = 0;
		foreach (DataColumn column in DT.Columns)
		{
			num += columnPreferredWidth(column.ColumnName);
			num += 2;
		}
		return num;
	}

	private void dataGrid1_DoubleClick(object sender, EventArgs e)
	{
		if (DataBoundGrid.DoubleClickEventFired != null)
		{
			DataBoundGrid.DoubleClickEventFired(sender, e);
		}
	}

	private void dataGrid1_KeyUp(object sender, KeyEventArgs e)
	{
		//IL_0009: Unknown result type (might be due to invalid IL or missing references)
		//IL_0010: Invalid comparison between Unknown and I4
		//IL_0013: Unknown result type (might be due to invalid IL or missing references)
		//IL_001a: Invalid comparison between Unknown and I4
		if (fullRowSelection && ((int)e.KeyCode == 38 || (int)e.KeyCode == 40) && dataGrid1.CurrentRowIndex != -1 && !dataGrid1.IsSelected(dataGrid1.CurrentRowIndex) && dataGrid1.CurrentRowIndex < DT.Rows.Count)
		{
			dataGrid1.Select(dataGrid1.CurrentRowIndex);
		}
	}
}
public class EventLogController : Component
{
	private Container components;

	private EventLogModel evtLogModel;

	private EventLogView evtLogView;

	private static volatile EventLogController instance = null;

	private static object syncObj = new object();

	public static EventLogController Instance
	{
		get
		{
			if (instance == null)
			{
				lock (syncObj)
				{
					if (instance == null)
					{
						instance = new EventLogController();
					}
				}
			}
			return instance;
		}
	}

	public EventLogView EvtLogView
	{
		get
		{
			return evtLogView;
		}
		set
		{
			evtLogView = value;
			if (evtLogView != null)
			{
				Init();
			}
		}
	}

	public EventLogModel EvtLogModel => evtLogModel;

	public event EventLogErrorMessageHandler EventLogErrorMessageFired;

	public event EventLogSaveHandler EventLogSaveFired;

	private EventLogController()
	{
		InitializeComponent();
		evtLogModel = new EventLogModel();
	}

	private void Init()
	{
		evtLogModel.Init();
		evtLogView.Init();
		evtLogView.EvtLogModel = evtLogModel;
	}

	private void InitializeComponent()
	{
		components = new Container();
	}
}
public class EventLogModel
{
	private const string xmlTableName = "Event Log";

	private DataSet evtDataSet;

	private long evtNum;

	public DataSet EvtDataSet => evtDataSet;

	public string XmlTableName => "Event Log";

	internal void Init()
	{
		LoadDBSchemas();
	}

	internal void LoadDBSchemas(string schemaFile)
	{
		if (schemaFile == null || schemaFile.Length <= 0)
		{
			throw new ArgumentNullException("Invalid input schemaFile: " + schemaFile);
		}
		if (evtDataSet == null)
		{
			evtDataSet = new DataSet();
			try
			{
				evtDataSet.ReadXmlSchema(schemaFile);
			}
			catch (Exception ex)
			{
				throw ex;
			}
		}
	}

	internal void LoadDBSchemas()
	{
		if (evtDataSet == null)
		{
			Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream("Cummins.EventLog.EventLog.xsd");
			evtDataSet = new DataSet();
			try
			{
				evtDataSet.ReadXmlSchema(manifestResourceStream);
			}
			catch (Exception ex)
			{
				throw ex;
			}
		}
	}

	public void ClearData()
	{
		evtDataSet.Tables["Event Log"].Clear();
	}

	public void SaveData(string fileName)
	{
		evtDataSet.AcceptChanges();
		if (fileName != null && fileName.Length > 0)
		{
			evtDataSet.WriteXml(fileName);
		}
	}

	internal void EventLogMessageCaptured(EventTypes evtType, string title, string evtArgs)
	{
		evtNum++;
		DataRow dataRow = evtDataSet.Tables["Event Log"].NewRow();
		dataRow["Type"] = evtType.ToString();
		dataRow["Description"] = evtArgs;
		dataRow["Event"] = evtNum;
		dataRow["Date"] = DateTime.Now.ToString("yyyy/MM/dd HH:mm:ss.fff");
		evtDataSet.Tables["Event Log"].Rows.Add(dataRow);
	}
}
public class EventLogView : UserControl
{
	public delegate void UpdateEventLogDelegate(EventTypes type, string title, string message, string deatiledDescription);

	public delegate void UpdateEventErrorLogDelegate(EventTypes type, string title, string message, string deatiledDescription, string errorCode);

	private const string detailedInfoColumnName = "DetailedDescription";

	private const string SourceNameForDownload = "Calibration Download";

	private const string InfoColumnName = "Description";

	private const string SearchFieldName = "Initializing calibration...";

	private const string DateColumnName = "Date DESC";

	private const int ColumnErrorCode = 7;

	private EventLogModel evtLogModel;

	private ContextMenu contextMenuEventLog;

	private string iconColumnName = "TypeIconIndex";

	private Panel panel1;

	private IconDataBoundGrid eventLogGrid;

	private Label evtLabel;

	private BalloonToolTip balloonToolTip;

	private Container components;

	public EventLogModel EvtLogModel
	{
		get
		{
			return evtLogModel;
		}
		set
		{
			evtLogModel = value;
		}
	}

	private BalloonToolTip BalloonToolTip
	{
		get
		{
			if (balloonToolTip == null)
			{
				balloonToolTip = new BalloonToolTip();
				balloonToolTip.CreateToolTip();
				balloonToolTip.Icon = BalloonToolTip.TooltipIcon.Info;
				balloonToolTip.TipText = " ";
				balloonToolTip.VisibleTime = 8000;
				balloonToolTip.Offset = new Point(0, -25);
				balloonToolTip.Alignment = BalloonToolTip.BalloonAlignment.BottomMiddle;
			}
			return balloonToolTip;
		}
	}

	public EventLogView()
	{
		InitializeComponent();
	}

	internal void Init()
	{
		SessionService.CurrentSession.EventLog.EventLogMessageFired += AddEventLogMessage;
		SessionService.CurrentSession.EventLog.EventLogSaveFired += SaveEventLog;
		EventLogController.Instance.EventLogErrorMessageFired += AddEventLogErrorMessage;
		DataBoundGrid.DoubleClickEventFired += ShowSelectedEventProperties;
	}

	public void AddEventLogMessage(EventTypes evtType, string title, string description, string detailedInformation)
	{
		AddEventLogErrorMessage(evtType, title, description, detailedInformation, string.Empty);
	}

	public void AddEventLogErrorMessage(EventTypes evtType, string title, string description, string detailedInformation, string errorCode)
	{
		if (!((Control)this).InvokeRequired)
		{
			try
			{
				int num = 0;
				eventLogGrid.DtGrid.CurrentRowIndex = 0;
				num = (int)evtType;
				DataRow dataRow = evtLogModel.EvtDataSet.Tables[eventLogGrid.XmlTableName].NewRow();
				if (evtType == EventTypes.Unknown)
				{
					num = 1;
				}
				dataRow[iconColumnName] = num;
				dataRow["Type"] = evtType.ToString();
				dataRow["Description"] = description;
				dataRow["Source"] = title;
				dataRow["Date"] = DateTime.Now.ToString("yyyy/MM/dd HH:mm:ss.fff");
				dataRow[7] = errorCode;
				dataRow["DetailedDescription"] = detailedInformation;
				dataRow["Event"] = evtLogModel.EvtDataSet.Tables[eventLogGrid.XmlTableName].Rows.Count + 1;
				evtLogModel.EvtDataSet.Tables[eventLogGrid.XmlTableName].Rows.InsertAt(dataRow, 0);
				evtLogModel.EvtDataSet.Tables[eventLogGrid.XmlTableName].AcceptChanges();
				eventLogGrid.columnAutoFit();
				if (!((Control)this).Visible)
				{
					switch (evtType)
					{
					case EventTypes.Warning:
						BalloonToolTip.Icon = BalloonToolTip.TooltipIcon.Warning;
						balloonToolTip.Title = "New warning in the Event log";
						BalloonToolTip.Show();
						break;
					default:
						BalloonToolTip.Icon = BalloonToolTip.TooltipIcon.Error;
						balloonToolTip.Title = "Error in the Event log : " + title;
						BalloonToolTip.Show();
						break;
					case EventTypes.Information:
						break;
					}
				}
				return;
			}
			catch (Exception)
			{
				return;
			}
		}
		UpdateEventErrorLogDelegate updateEventErrorLogDelegate = AddEventLogErrorMessage;
		((Control)this).BeginInvoke((Delegate)updateEventErrorLogDelegate, new object[5] { evtType, title, description, detailedInformation, errorCode });
	}

	private void SaveEventLog(string filename)
	{
		SaveEventLogs(filename);
	}

	public void RefreshData(DataSet xmlDataSet)
	{
		RefreshDataFromView(xmlDataSet);
		eventLogGrid.columnAutoDistribute();
	}

	public void ResetData()
	{
		eventLogGrid.ResetData();
	}

	private void ShowSelectedEventProperties(object sender, EventArgs e)
	{
		int currentRowIndex = eventLogGrid.DtGrid.CurrentRowIndex;
		if (currentRowIndex >= 0 && eventLogGrid.InsideCellClick)
		{
			string text = eventLogGrid.DtGrid[currentRowIndex, 3].ToString();
			string s = eventLogGrid.DtGrid[currentRowIndex, 0].ToString();
			EventTypes eventTypes = (EventTypes)int.Parse(s);
			if (text == "Calibration Download" && eventTypes == EventTypes.Error)
			{
				ShowCalibrationDownSelectedEvent();
			}
			else
			{
				ShowSelectedEvent();
			}
		}
	}

	private void SaveLogFile(object sender, EventArgs e)
	{
		SaveEventLogs(null);
	}

	private void ClearAllEvents(object sender, EventArgs e)
	{
		//IL_000f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0014: Unknown result type (might be due to invalid IL or missing references)
		//IL_0015: Unknown result type (might be due to invalid IL or missing references)
		//IL_0017: Invalid comparison between Unknown and I4
		//IL_001b: Unknown result type (might be due to invalid IL or missing references)
		//IL_001d: Invalid comparison between Unknown and I4
		try
		{
			bool flag = true;
			DialogResult val = MessageBox.Show("Do you want to save 'Event Log' before clearing it?", "Event Log", (MessageBoxButtons)3, (MessageBoxIcon)32);
			if ((int)val != 2)
			{
				if ((int)val == 6)
				{
					flag = SaveEventLogs(null);
				}
				if (flag)
				{
					evtLogModel.EvtDataSet.Tables[eventLogGrid.XmlTableName].Rows.Clear();
					eventLogGrid.columnAutoDistribute();
				}
			}
		}
		catch (Exception)
		{
			EventLogger.Warn("Event Log", "Failed to clear Event Logs");
		}
	}

	private bool SaveEventLogs(string filename)
	{
		//IL_003b: Unknown result type (might be due to invalid IL or missing references)
		//IL_0041: Invalid comparison between Unknown and I4
		string text = filename;
		bool flag = false;
		if (string.IsNullOrEmpty(text))
		{
			SafeSaveFileDialog safeSaveFileDialog = new SafeSaveFileDialog();
			safeSaveFileDialog.AddExtension = true;
			safeSaveFileDialog.DefaultExt = "*.evt";
			safeSaveFileDialog.Filter = "Event Log (EventLog.xml)|*.EventLog.xml";
			safeSaveFileDialog.Title = "Save 'Event Log' As";
			if ((int)safeSaveFileDialog.ShowDialog() == 1)
			{
				text = safeSaveFileDialog.FileName;
			}
		}
		if (!string.IsNullOrEmpty(text))
		{
			try
			{
				DataSet dataSet = evtLogModel.EvtDataSet.Copy();
				foreach (DataTable table in dataSet.Tables)
				{
					if (!(table.TableName == eventLogGrid.XmlTableName))
					{
						table.Clear();
					}
				}
				if (dataSet.Tables[eventLogGrid.XmlTableName].Columns.Contains(iconColumnName))
				{
					dataSet.Tables[eventLogGrid.XmlTableName].Columns.Remove(iconColumnName);
				}
				dataSet.WriteXml(text);
				flag = true;
			}
			catch (Exception)
			{
				flag = false;
				EventLogger.Warn("EventLog", "Failed to save Event Logs to <" + text + ">.  ");
			}
		}
		else
		{
			flag = false;
			EventLogger.Warn("Event Log", "Failed to save Event Logs to <" + text + ">.  ");
		}
		return flag;
	}

	public void RefreshDataFromView(DataSet sourceDataSet)
	{
		//IL_0089: Unknown result type (might be due to invalid IL or missing references)
		try
		{
			if (sourceDataSet == null)
			{
				throw new ArgumentNullException("sourceDataSet");
			}
			eventLogGrid.DtTable = sourceDataSet.Tables[eventLogGrid.XmlTableName];
			if (eventLogGrid.DtTable == null)
			{
				throw new ArgumentException("sourceDataSet must contain an Items table", "sourceDataSet");
			}
			eventLogGrid.DtGrid.DataSource = sourceDataSet;
			InitGridStyles(eventLogGrid.DtTable);
			eventLogGrid.columnAutoDistribute();
		}
		catch (Exception ex)
		{
			MessageBox.Show("Error while initializing Event Log.", "Event Log", (MessageBoxButtons)0, (MessageBoxIcon)16);
			throw ex;
		}
	}

	public void InitGridStyles(DataTable DT)
	{
		//IL_0016: Unknown result type (might be due to invalid IL or missing references)
		//IL_0020: Expected O, but got Unknown
		//IL_01ca: Unknown result type (might be due to invalid IL or missing references)
		//IL_01d1: Expected O, but got Unknown
		//IL_01dc: Unknown result type (might be due to invalid IL or missing references)
		//IL_01e3: Expected O, but got Unknown
		//IL_01ee: Unknown result type (might be due to invalid IL or missing references)
		//IL_01f5: Expected O, but got Unknown
		//IL_0200: Unknown result type (might be due to invalid IL or missing references)
		//IL_0207: Expected O, but got Unknown
		//IL_0212: Unknown result type (might be due to invalid IL or missing references)
		//IL_0219: Expected O, but got Unknown
		int num = 0;
		try
		{
			if (DT == null)
			{
				throw new ArgumentNullException("DataTable");
			}
			eventLogGrid.GridTableStyle = new DataGridTableStyle();
			eventLogGrid.GridTableStyle.AllowSorting = false;
			eventLogGrid.GridTableStyle.DataGrid = eventLogGrid.DtGrid;
			eventLogGrid.DtGrid.CaptionText = eventLogGrid.XmlTableName;
			eventLogGrid.DtGrid.DataSource = eventLogGrid.DtTable;
			eventLogGrid.GridTableStyle.RowHeadersVisible = false;
			eventLogGrid.GridTableStyle.MappingName = eventLogGrid.XmlTableName;
			DataColumn[] array = null;
			DataColumn dataColumn = new DataColumn(iconColumnName);
			array = new DataColumn[evtLogModel.EvtDataSet.Tables[eventLogGrid.XmlTableName].Columns.Count + 1];
			array[0] = dataColumn;
			foreach (DataColumn column in DT.Columns)
			{
				array[++num] = column;
			}
			evtLogModel.EvtDataSet.Tables[eventLogGrid.XmlTableName].Columns.Clear();
			evtLogModel.EvtDataSet.Tables[eventLogGrid.XmlTableName].Columns.AddRange(array);
			num = 0;
			foreach (DataColumn column2 in DT.Columns)
			{
				if (column2.ColumnName == iconColumnName)
				{
					Icon val = null;
					int num2 = 0;
					ImageList val2 = new ImageList();
					Icon val3 = new Icon(((object)this).GetType(), "Information.ICO");
					Icon val4 = new Icon(((object)this).GetType(), "Warning.ICO");
					Icon val5 = new Icon(((object)this).GetType(), "Error.ICO");
					val = new Icon(((object)this).GetType(), "Unexpected.ICO");
					if (val3 != null)
					{
						val2.Images.Add(val3);
						if (num2 < val3.Width)
						{
							num2 = val3.Width;
						}
					}
					if (val4 != null)
					{
						val2.Images.Add(val4);
						if (num2 < val4.Width)
						{
							num2 = val4.Width;
						}
					}
					if (val5 != null)
					{
						val2.Images.Add(val5);
						if (num2 < val5.Width)
						{
							num2 = val5.Width;
						}
					}
					if (val != null)
					{
						val2.Images.Add(val);
						if (num2 < val.Width)
						{
							num2 = val.Width;
						}
					}
					if (num2 > eventLogGrid.DtGrid.PreferredRowHeight)
					{
						eventLogGrid.DtGrid.PreferredRowHeight = num2 + 2;
					}
					val3 = null;
					val4 = null;
					val5 = null;
					val = null;
					DataGridIconAndTextColumn dataGridIconAndTextColumn = new DataGridIconAndTextColumn(val2, eventLogGrid.DtGrid, num, graphic: true, editCol: true);
					((DataGridColumnStyle)dataGridIconAndTextColumn).MappingName = column2.ColumnName;
					if (iconColumnName != column2.ColumnName)
					{
						((DataGridColumnStyle)dataGridIconAndTextColumn).HeaderText = column2.ColumnName;
					}
					else
					{
						((DataGridColumnStyle)dataGridIconAndTextColumn).HeaderText = "";
					}
					((DataGridColumnStyle)dataGridIconAndTextColumn).NullText = "";
					((DataGridColumnStyle)dataGridIconAndTextColumn).Width = (((Control)eventLogGrid.DtGrid).Width - 4) / DT.Columns.Count;
					eventLogGrid.GridTableStyle.GridColumnStyles.Add((DataGridColumnStyle)(object)dataGridIconAndTextColumn);
				}
				else
				{
					DataGridIconAndTextColumn dataGridIconAndTextColumn2 = new DataGridIconAndTextColumn(null, eventLogGrid.DtGrid, num, graphic: false, editCol: true);
					((DataGridColumnStyle)dataGridIconAndTextColumn2).MappingName = column2.ColumnName;
					if (iconColumnName != column2.ColumnName)
					{
						((DataGridColumnStyle)dataGridIconAndTextColumn2).HeaderText = column2.ColumnName;
					}
					else
					{
						((DataGridColumnStyle)dataGridIconAndTextColumn2).HeaderText = "";
					}
					((DataGridColumnStyle)dataGridIconAndTextColumn2).NullText = "";
					if (column2.ColumnName == "Source" || column2.ColumnName == "Event" || column2.ColumnName == "Type" || column2.ColumnName == "ErrorCode")
					{
						((DataGridColumnStyle)dataGridIconAndTextColumn2).Width = 0;
					}
					else
					{
						((DataGridColumnStyle)dataGridIconAndTextColumn2).Width = (((Control)eventLogGrid.DtGrid).Width - 4) / DT.Columns.Count;
					}
					eventLogGrid.GridTableStyle.GridColumnStyles.Add((DataGridColumnStyle)(object)dataGridIconAndTextColumn2);
				}
				num++;
			}
			eventLogGrid.DtGrid.TableStyles.Add(eventLogGrid.GridTableStyle);
			eventLogGrid.GridTableStyle.GridColumnStyles["DetailedDescription"].Width = 0;
		}
		catch (Exception ex)
		{
			throw ex;
		}
	}

	internal void ShowCalibrationDownSelectedEvent()
	{
		//IL_0385: Unknown result type (might be due to invalid IL or missing references)
		//IL_0374: Unknown result type (might be due to invalid IL or missing references)
		try
		{
			int currentRowIndex = eventLogGrid.DtGrid.CurrentRowIndex;
			if (currentRowIndex < 0 || !eventLogGrid.InsideCellClick)
			{
				return;
			}
			DateTime dateTime = Convert.ToDateTime(eventLogGrid.DtGrid[currentRowIndex, 2].ToString());
			string text = eventLogGrid.DtGrid[currentRowIndex, 3].ToString();
			DataSet evtDataSet = evtLogModel.EvtDataSet;
			DataView dataView = new DataView(evtDataSet.Tables[0]);
			dataView.Sort = "Description";
			dataView.RowStateFilter = DataViewRowState.CurrentRows;
			DataRowView[] array = dataView.FindRows("Initializing calibration...");
			DataTable dataTable = new DataTable();
			dataTable = evtDataSet.Tables[0].Clone();
			dataTable.Clear();
			DataRowView[] array2 = array;
			foreach (DataRowView dataRowView in array2)
			{
				dataTable.ImportRow(dataRowView.Row);
			}
			DataView dataView2 = new DataView(dataTable);
			dataView2.Sort = "Date DESC";
			DataRowView dataRowView2 = dataView2[0];
			DateTime dateTime2 = Convert.ToDateTime(dataRowView2["Date"].ToString());
			bool flag = false;
			if (dataView2.Table.Rows.Count > 0)
			{
				for (int j = 1; j <= dataView2.Table.Rows.Count; j++)
				{
					if (dateTime2 > dateTime && !flag)
					{
						dataRowView2 = dataView2[j];
						flag = true;
					}
				}
			}
			new DataTable();
			_ = evtDataSet.Tables[0];
			DataView dataView3 = new DataView(evtDataSet.Tables[0]);
			dataView3.Sort = "Date";
			dataView3.RowFilter = string.Concat("Date >= '", dateTime2, "'AND Date <= '", dateTime, "'");
			string s = eventLogGrid.DtGrid[currentRowIndex, 0].ToString();
			string text2 = eventLogGrid.DtGrid[currentRowIndex, 1].ToString();
			text2 = text2 + " - " + eventLogGrid.DtGrid[currentRowIndex, 2].ToString() + ":\r\n";
			text2 = text2 + eventLogGrid.DtGrid[currentRowIndex, 5].ToString() + ".";
			string text3 = eventLogGrid.DtGrid[currentRowIndex, 6].ToString();
			text = eventLogGrid.DtGrid[currentRowIndex, 3].ToString();
			MessageDialogIcon icon = int.Parse(s) switch
			{
				0 => MessageDialogIcon.Information, 
				1 => MessageDialogIcon.Warning, 
				2 => MessageDialogIcon.Error, 
				3 => MessageDialogIcon.Question, 
				_ => MessageDialogIcon.Warning, 
			};
			text3 += "\r\n";
			foreach (DataRowView item in dataView3)
			{
				text3 += "\r\n";
				text3 += item["Description"];
				text3 += item["DetailedDescription"];
				text3 += "\r\n";
			}
			IMessageDialog caltermMessageDialog = MessageDialogComponent.CaltermMessageDialog;
			caltermMessageDialog.Show(text, text2, text3, MessageDialogButtons.OK, icon);
		}
		catch (Exception ex)
		{
			MessageBox.Show(ex.Message);
		}
	}

	internal void ShowSelectedEvent()
	{
		//IL_013d: Unknown result type (might be due to invalid IL or missing references)
		try
		{
			int currentRowIndex = eventLogGrid.DtGrid.CurrentRowIndex;
			if (currentRowIndex >= 0 && eventLogGrid.InsideCellClick)
			{
				string s = eventLogGrid.DtGrid[currentRowIndex, 0].ToString();
				string text = eventLogGrid.DtGrid[currentRowIndex, 1].ToString();
				text = text + " - " + eventLogGrid.DtGrid[currentRowIndex, 2].ToString() + ":\r\n";
				text = text + eventLogGrid.DtGrid[currentRowIndex, 5].ToString() + ".";
				string detailText = eventLogGrid.DtGrid[currentRowIndex, 6].ToString();
				string caption = eventLogGrid.DtGrid[currentRowIndex, 3].ToString();
				string errorCode = eventLogGrid.DtGrid[currentRowIndex, 7].ToString();
				MessageDialogIcon icon = int.Parse(s) switch
				{
					0 => MessageDialogIcon.Information, 
					1 => MessageDialogIcon.Warning, 
					2 => MessageDialogIcon.Error, 
					3 => MessageDialogIcon.Question, 
					_ => MessageDialogIcon.Warning, 
				};
				IMessageDialog caltermMessageDialog = MessageDialogComponent.CaltermMessageDialog;
				caltermMessageDialog.Show(caption, text, detailText, errorCode, MessageDialogButtons.OK, icon);
			}
		}
		catch (Exception)
		{
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

	private void InitializeComponent()
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_000b: Expected O, but got Unknown
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0016: Expected O, but got Unknown
		//IL_0017: Unknown result type (might be due to invalid IL or missing references)
		//IL_0021: Expected O, but got Unknown
		//IL_0103: Unknown result type (might be due to invalid IL or missing references)
		//IL_010d: Expected O, but got Unknown
		contextMenuEventLog = new ContextMenu();
		panel1 = new Panel();
		evtLabel = new Label();
		eventLogGrid = new IconDataBoundGrid();
		((Control)panel1).SuspendLayout();
		((Control)this).SuspendLayout();
		contextMenuEventLog.Popup += contextMenuEventLog_Popup;
		((Control)panel1).Controls.Add((Control)(object)evtLabel);
		((Control)panel1).Controls.Add((Control)(object)eventLogGrid);
		((Control)panel1).Dock = (DockStyle)5;
		((Control)panel1).Location = new Point(0, 0);
		((Control)panel1).Name = "panel1";
		((Control)panel1).Size = new Size(234, 206);
		((Control)panel1).TabIndex = 1;
		((Control)evtLabel).BackColor = SystemColors.ActiveCaption;
		((Control)evtLabel).Dock = (DockStyle)1;
		((Control)evtLabel).Font = new Font("Tahoma", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)evtLabel).ForeColor = SystemColors.ActiveCaptionText;
		((Control)evtLabel).Location = new Point(0, 0);
		((Control)evtLabel).Name = "evtLabel";
		((Control)evtLabel).Size = new Size(234, 20);
		((Control)evtLabel).TabIndex = 3;
		((Control)evtLabel).Text = "Event Log";
		evtLabel.TextAlign = (ContentAlignment)16;
		eventLogGrid.AllowFullRowSelection = true;
		((Control)eventLogGrid).ContextMenu = contextMenuEventLog;
		((Control)eventLogGrid).Dock = (DockStyle)5;
		eventLogGrid.DtTable = null;
		eventLogGrid.GridTableStyle = null;
		eventLogGrid.InsideCellClick = false;
		eventLogGrid.LastColumnAutoFit = false;
		((Control)eventLogGrid).Location = new Point(0, 0);
		((Control)eventLogGrid).Name = "eventLogGrid";
		((Control)eventLogGrid).Size = new Size(234, 206);
		((Control)eventLogGrid).TabIndex = 2;
		eventLogGrid.XmlFileName = null;
		eventLogGrid.XmlTableName = "Event Log";
		((Control)eventLogGrid).Enter += eventLogGrid_Enter;
		((Control)eventLogGrid).Leave += eventLogGrid_Leave;
		((Control)this).Controls.Add((Control)(object)panel1);
		((Control)this).Name = "EventLogView";
		((Control)this).Size = new Size(234, 206);
		((Control)panel1).ResumeLayout(false);
		((Control)this).ResumeLayout(false);
	}

	private void contextMenuEventLog_Popup(object sender, EventArgs e)
	{
		//IL_0021: Unknown result type (might be due to invalid IL or missing references)
		//IL_0027: Expected O, but got Unknown
		//IL_0038: Unknown result type (might be due to invalid IL or missing references)
		//IL_003e: Expected O, but got Unknown
		//IL_004f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0055: Expected O, but got Unknown
		try
		{
			((Menu)contextMenuEventLog).MenuItems.Clear();
			MenuItem val = new MenuItem("Save Event Log As...", (EventHandler)SaveLogFile);
			MenuItem val2 = new MenuItem("Clear all Events", (EventHandler)ClearAllEvents);
			MenuItem val3 = new MenuItem("Properties", (EventHandler)ShowSelectedEventProperties);
			if (evtLogModel.EvtDataSet.Tables[eventLogGrid.XmlTableName].Rows.Count == 0)
			{
				val2.Enabled = false;
				val3.Enabled = false;
			}
			((Menu)contextMenuEventLog).MenuItems.Add(val);
			((Menu)contextMenuEventLog).MenuItems.Add(val2);
			((Menu)contextMenuEventLog).MenuItems.Add(val3);
		}
		catch (Exception)
		{
		}
	}

	private void eventLogGrid_Load(object sender, EventArgs e)
	{
	}

	private void eventLogGrid_Enter(object sender, EventArgs e)
	{
		if (eventLogGrid.DtGrid.CurrentRowIndex != -1 && !eventLogGrid.DtGrid.IsSelected(eventLogGrid.DtGrid.CurrentRowIndex))
		{
			eventLogGrid.DtGrid.Select(eventLogGrid.DtGrid.CurrentRowIndex);
		}
	}

	private void eventLogGrid_Leave(object sender, EventArgs e)
	{
		if (eventLogGrid.DtGrid.CurrentRowIndex != -1 && eventLogGrid.DtGrid.IsSelected(eventLogGrid.DtGrid.CurrentRowIndex))
		{
			eventLogGrid.DtGrid.UnSelect(eventLogGrid.DtGrid.CurrentRowIndex);
		}
	}
}
public class ExceptionParser
{
	public static string ParseException(Exception ex)
	{
		return new ExceptionParser().InternalParseException(ex);
	}

	private string InternalParseException(Exception exception)
	{
		StringBuilder stringBuilder = new StringBuilder();
		while (exception != null)
		{
			if (exception.Message.StartsWith("<"))
			{
				stringBuilder.Append(ParseXMLNode(exception.Message));
			}
			else
			{
				stringBuilder.Append(exception.Message);
				stringBuilder.Append(Environment.NewLine);
			}
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append("Stack Trace: ");
			stringBuilder.Append(exception.StackTrace);
			exception = exception.InnerException;
		}
		return stringBuilder.ToString();
	}

	private string ParseXMLNode(string xmlString)
	{
		//IL_0006: Unknown result type (might be due to invalid IL or missing references)
		//IL_000c: Expected O, but got Unknown
		//IL_002b: Unknown result type (might be due to invalid IL or missing references)
		//IL_0031: Expected O, but got Unknown
		StringBuilder stringBuilder = new StringBuilder();
		try
		{
			XmlDocument val = new XmlDocument();
			val.LoadXml(xmlString);
			XmlNodeList childNodes = ((XmlNode)val).ChildNodes;
			foreach (XmlElement item in childNodes)
			{
				XmlElement xmlelement = item;
				stringBuilder.Append(ProcessXmlElement(xmlelement));
				stringBuilder.Append(Environment.NewLine);
			}
		}
		catch (Exception ex)
		{
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append("Exception Parser Error :");
			stringBuilder.Append(ex.Message);
			stringBuilder.Append(Environment.NewLine);
			stringBuilder.Append(xmlString);
		}
		return stringBuilder.ToString();
	}

	private string ProcessXmlElement(XmlElement xmlelement)
	{
		//IL_0021: Unknown result type (might be due to invalid IL or missing references)
		//IL_0027: Expected O, but got Unknown
		//IL_003d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0043: Expected O, but got Unknown
		_ = ((XmlNode)xmlelement).ChildNodes;
		string text = "";
		foreach (XmlNode childNode in ((XmlNode)xmlelement).ChildNodes)
		{
			XmlNode val = childNode;
			foreach (XmlNode childNode2 in val.ChildNodes)
			{
				XmlNode val2 = childNode2;
				text = text + val2.Name + ": " + val2.InnerText;
				text += Environment.NewLine;
			}
		}
		return text;
	}
}
public class IconDataBoundGrid : DataBoundGrid
{
	private IContainer components;

	private bool lastColumnAutoFit = true;

	public bool LastColumnAutoFit
	{
		get
		{
			return lastColumnAutoFit;
		}
		set
		{
			lastColumnAutoFit = value;
		}
	}

	public IconDataBoundGrid()
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
		((Control)this).SuspendLayout();
		((Control)this).Name = "IconDataBoundGrid";
		((Control)this).Resize += IconDataBoundGrid_Resize;
		((Control)this).ResumeLayout(false);
	}

	public override void columnAutoFit()
	{
		//IL_005c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0062: Expected O, but got Unknown
		//IL_007b: Unknown result type (might be due to invalid IL or missing references)
		//IL_0082: Expected O, but got Unknown
		int num = 0;
		try
		{
			if (base.DtGrid.DataSource == null)
			{
				return;
			}
			int count = ((DataTable)base.DtGrid.DataSource).Rows.Count;
			if (count <= 0)
			{
				columnAutoDistribute();
				return;
			}
			foreach (DataGridTableStyle item in (BaseCollection)base.DtGrid.TableStyles)
			{
				DataGridTableStyle val = item;
				foreach (DataGridColumnStyle item2 in (BaseCollection)val.GridColumnStyles)
				{
					DataGridColumnStyle val2 = item2;
					if (val2.Width == 0)
					{
						continue;
					}
					Type type = ((object)val2).GetType();
					if (type.Name.Equals("DataGridIconAndTextColumn"))
					{
						if (((DataGridIconAndTextColumn)(object)val2).Graphic)
						{
							val2.Width = ((DataGridIconAndTextColumn)(object)val2).IconList.ImageSize.Width + 2;
							num += val2.Width;
						}
						else
						{
							val2.Width = columnPreferredWidth(val2.MappingName);
							num += val2.Width;
						}
					}
					else
					{
						val2.Width = columnPreferredWidth(val2.MappingName);
						num += val2.Width;
					}
					val2.Width += 2;
				}
			}
			if (lastColumnAutoFit)
			{
				int count2 = ((DataTable)base.DtGrid.DataSource).Columns.Count;
				int num2 = (VerticalScrollBarVisible(base.DtGrid) ? SystemInformation.VerticalScrollBarWidth : 0);
				int num3 = ((Control)base.DtGrid).ClientSize.Width - num2 - 4;
				int num4 = 0;
				for (int i = 0; i < count2 - 1; i++)
				{
					num4 += base.DtGrid.TableStyles[base.XmlTableName].GridColumnStyles[i].Width;
				}
				if (num4 < num3 && base.DtGrid.TableStyles[base.XmlTableName].GridColumnStyles[count2 - 1].Width < num3 - num4)
				{
					base.DtGrid.TableStyles[base.XmlTableName].GridColumnStyles[count2 - 1].Width = num3 - num4;
				}
			}
		}
		catch (Exception)
		{
		}
	}

	private bool VerticalScrollBarVisible(DataGrid grid)
	{
		//IL_0019: Unknown result type (might be due to invalid IL or missing references)
		//IL_001f: Expected O, but got Unknown
		if (grid == null)
		{
			return false;
		}
		foreach (Control item in (ArrangedElementCollection)((Control)grid).Controls)
		{
			Control val = item;
			if (((object)val).GetType() == typeof(VScrollBar) && val.Visible)
			{
				return true;
			}
		}
		return false;
	}

	private void IconDataBoundGrid_Resize(object sender, EventArgs e)
	{
		columnAutoFit();
	}
}
public class DataGridIconAndTextColumn : DataGridTextBoxColumn
{
	private ImageList icons;

	private object parentGrid;

	private int colNum;

	private bool graphicCol;

	private bool editColumn;

	public bool Graphic => graphicCol;

	public bool AllowColumnEdit
	{
		get
		{
			return editColumn;
		}
		set
		{
			editColumn = value;
		}
	}

	public ImageList IconList => icons;

	public DataGridIconAndTextColumn(ImageList Icons, object parent, int colNumber, bool graphic, bool editCol)
	{
		icons = Icons;
		parentGrid = parent;
		colNum = colNumber;
		graphicCol = graphic;
		editColumn = editCol;
	}

	protected override void Edit(CurrencyManager source, int rowNum, Rectangle bounds, bool readOnly, string instantText, bool cellIsVisible)
	{
		if (!editColumn)
		{
			((DataGridTextBoxColumn)this).Edit(source, rowNum, bounds, readOnly, instantText, cellIsVisible);
		}
	}

	protected override void Paint(Graphics g, Rectangle bounds, CurrencyManager source, int rowNum, Brush backBrush, Brush foreBrush, bool alignToRight)
	{
		//IL_0006: Unknown result type (might be due to invalid IL or missing references)
		try
		{
			string s = ((DataGrid)parentGrid)[rowNum, colNum].ToString();
			if (graphicCol)
			{
				Image val = icons.Images[int.Parse(s)];
				Rectangle rectangle = new Rectangle(bounds.X, bounds.Y, val.Size.Width, bounds.Height);
				g.FillRectangle(backBrush, rectangle);
				g.DrawImage(val, rectangle);
				bounds.X += rectangle.Width;
				bounds.Width -= rectangle.Width;
				foreBrush = backBrush;
				val = null;
			}
			((DataGridTextBoxColumn)this).Paint(g, bounds, source, rowNum, backBrush, foreBrush, alignToRight);
		}
		catch (Exception)
		{
		}
	}
}
public class ResizableListBox : Panel
{
	private ArrayList m_Items = new ArrayList();

	private ArrayList m_SelectedItems = new ArrayList();

	private ArrayList m_SelectedItemIndices = new ArrayList();

	private ArrayList m_ItemHeights = new ArrayList();

	private bool m_CtrlPressed;

	private bool m_AllowMultiSelect = true;

	private MeasureItemEventHandler m_MeasureItem;

	private DrawItemEventHandler m_DrawItem;

	public ArrayList Items => m_Items;

	public object SelectedItem
	{
		get
		{
			if (m_SelectedItems.Count > 0)
			{
				return m_SelectedItems[0];
			}
			return null;
		}
		set
		{
			int num = m_Items.IndexOf(value);
			if (num >= 0)
			{
				m_SelectedItemIndices.Clear();
				m_SelectedItems.Clear();
				AddSelectedItem(num);
			}
		}
	}

	public ArrayList SelectedItems => m_Items;

	public int SelectedIndex
	{
		get
		{
			if (m_SelectedItemIndices.Count > 0)
			{
				return (int)m_SelectedItemIndices[0];
			}
			return -1;
		}
		set
		{
			if (value < m_Items.Count && value >= -1)
			{
				AddSelectedItem(value);
			}
		}
	}

	public ArrayList SelectedItemIndices => m_SelectedItemIndices;

	public event EventHandler SelectedIndexChanged;

	public event MeasureItemEventHandler MeasureItem
	{
		add
		{
			//IL_0010: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Expected O, but got Unknown
			MeasureItemEventHandler val = this.m_MeasureItem;
			MeasureItemEventHandler val2;
			do
			{
				val2 = val;
				MeasureItemEventHandler value2 = (MeasureItemEventHandler)Delegate.Combine((Delegate?)(object)val2, (Delegate?)(object)value);
				val = Interlocked.CompareExchange(ref this.m_MeasureItem, value2, val2);
			}
			while (val != val2);
		}
		remove
		{
			//IL_0010: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Expected O, but got Unknown
			MeasureItemEventHandler val = this.m_MeasureItem;
			MeasureItemEventHandler val2;
			do
			{
				val2 = val;
				MeasureItemEventHandler value2 = (MeasureItemEventHandler)Delegate.Remove((Delegate?)(object)val2, (Delegate?)(object)value);
				val = Interlocked.CompareExchange(ref this.m_MeasureItem, value2, val2);
			}
			while (val != val2);
		}
	}

	public event DrawItemEventHandler DrawItem
	{
		add
		{
			//IL_0010: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Expected O, but got Unknown
			DrawItemEventHandler val = this.m_DrawItem;
			DrawItemEventHandler val2;
			do
			{
				val2 = val;
				DrawItemEventHandler value2 = (DrawItemEventHandler)Delegate.Combine((Delegate?)(object)val2, (Delegate?)(object)value);
				val = Interlocked.CompareExchange(ref this.m_DrawItem, value2, val2);
			}
			while (val != val2);
		}
		remove
		{
			//IL_0010: Unknown result type (might be due to invalid IL or missing references)
			//IL_0016: Expected O, but got Unknown
			DrawItemEventHandler val = this.m_DrawItem;
			DrawItemEventHandler val2;
			do
			{
				val2 = val;
				DrawItemEventHandler value2 = (DrawItemEventHandler)Delegate.Remove((Delegate?)(object)val2, (Delegate?)(object)value);
				val = Interlocked.CompareExchange(ref this.m_DrawItem, value2, val2);
			}
			while (val != val2);
		}
	}

	public ResizableListBox()
	{
		((Control)this).SetStyle((ControlStyles)73750, true);
		((Control)this).BackColor = SystemColors.Window;
		((ScrollableControl)this).AutoScroll = true;
		((ScrollableControl)this).HScroll = false;
	}

	protected override void OnPaint(PaintEventArgs pe)
	{
		//IL_002c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0032: Expected O, but got Unknown
		//IL_0061: Unknown result type (might be due to invalid IL or missing references)
		//IL_0068: Expected O, but got Unknown
		//IL_00c4: Unknown result type (might be due to invalid IL or missing references)
		//IL_00d0: Unknown result type (might be due to invalid IL or missing references)
		//IL_00de: Unknown result type (might be due to invalid IL or missing references)
		//IL_00e5: Expected O, but got Unknown
		((Control)this).OnPaint(pe);
		Graphics graphics = pe.Graphics;
		Rectangle rectangle = default(Rectangle);
		int num = ((ScrollableControl)this).AutoScrollPosition.Y;
		Brush val = (Brush)new SolidBrush(((Control)this).BackColor);
		try
		{
			graphics.FillRectangle(val, ((Control)this).ClientRectangle);
		}
		finally
		{
			((IDisposable)val)?.Dispose();
		}
		m_ItemHeights.Clear();
		for (int i = 0; i < m_Items.Count; i++)
		{
			MeasureItemEventArgs e = new MeasureItemEventArgs(graphics, i);
			OnMeasureItem(e);
			rectangle.Location = new Point(0, num);
			rectangle.Size = new Size(((Control)this).ClientRectangle.Right, (int)m_ItemHeights[i]);
			DrawItemState val2 = (DrawItemState)(m_SelectedItemIndices.Contains(i) ? 1 : 32);
			DrawItemEventArgs e2 = new DrawItemEventArgs(graphics, ((Control)this).Font, rectangle, i, val2, ((Control)this).ForeColor, ((Control)this).BackColor);
			OnDrawItem(e2);
			num += (int)m_ItemHeights[i];
		}
		((ScrollableControl)this).AutoScrollMinSize = new Size(((Control)this).Width - 50, num);
	}

	protected override void OnMouseDown(MouseEventArgs e)
	{
		//IL_000f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0019: Invalid comparison between Unknown and I4
		((Control)this).OnMouseDown(e);
		((Control)this).Focus();
		if ((int)e.Button != 1048576)
		{
			return;
		}
		int num = ItemHitTest(e.X, e.Y);
		if (num < 0)
		{
			return;
		}
		if (m_CtrlPressed && m_AllowMultiSelect)
		{
			if (m_SelectedItemIndices.Contains(num))
			{
				RemoveSelectedItem(num);
			}
			else
			{
				AddSelectedItem(num);
			}
		}
		else
		{
			if (m_SelectedItemIndices.Contains(num) && m_SelectedItemIndices.Count == 1)
			{
				return;
			}
			m_SelectedItemIndices.Clear();
			m_SelectedItems.Clear();
			AddSelectedItem(num);
		}
		((Control)this).Invalidate();
	}

	protected override void OnKeyDown(KeyEventArgs e)
	{
		((Control)this).OnKeyDown(e);
		m_CtrlPressed = e.Control;
	}

	protected override void OnKeyUp(KeyEventArgs e)
	{
		((Control)this).OnKeyUp(e);
		m_CtrlPressed = e.Control;
	}

	private int ItemHitTest(int X, int Y)
	{
		int num = ((ScrollableControl)this).AutoScrollPosition.Y;
		for (int i = 0; i < m_ItemHeights.Count; i++)
		{
			num += (int)m_ItemHeights[i];
			if (Y < num)
			{
				return i;
			}
		}
		return -1;
	}

	private void AddSelectedItem(int index)
	{
		if (index == -1)
		{
			m_SelectedItemIndices.Clear();
			m_SelectedItems.Clear();
		}
		else
		{
			m_SelectedItemIndices.Add(index);
			m_SelectedItems.Add(m_Items[index]);
		}
		OnSelectedIndexChanged(new EventArgs());
	}

	private void RemoveSelectedItem(int index)
	{
		m_SelectedItemIndices.Remove(index);
		m_SelectedItems.Remove(m_Items[index]);
		OnSelectedIndexChanged(new EventArgs());
	}

	protected virtual void OnDrawItem(DrawItemEventArgs e)
	{
		//IL_001a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0020: Invalid comparison between Unknown and I4
		//IL_0052: Unknown result type (might be due to invalid IL or missing references)
		//IL_0058: Expected O, but got Unknown
		//IL_0027: Unknown result type (might be due to invalid IL or missing references)
		//IL_002d: Expected O, but got Unknown
		e.DrawBackground();
		e.DrawFocusRectangle();
		Rectangle bounds = e.Bounds;
		Color color = SystemColors.ControlText;
		if ((int)e.State == 1)
		{
			Brush val = (Brush)new SolidBrush(SystemColors.Highlight);
			try
			{
				e.Graphics.FillRectangle(val, e.Bounds);
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
			color = SystemColors.HighlightText;
		}
		SolidBrush val2 = new SolidBrush(color);
		try
		{
			e.Graphics.DrawString(m_Items[e.Index].ToString(), ((Control)this).Font, (Brush)(object)val2, (float)bounds.Left, (float)bounds.Top);
		}
		finally
		{
			((IDisposable)val2)?.Dispose();
		}
		if (this.DrawItem != null)
		{
			this.DrawItem.Invoke((object)this, e);
		}
	}

	protected virtual void OnMeasureItem(MeasureItemEventArgs e)
	{
		e.ItemHeight = ((Control)this).Font.Height;
		if (this.MeasureItem != null)
		{
			this.MeasureItem.Invoke((object)this, e);
		}
		m_ItemHeights.Add(e.ItemHeight);
	}

	protected virtual void OnSelectedIndexChanged(EventArgs e)
	{
		if (this.SelectedIndexChanged != null)
		{
			this.SelectedIndexChanged(this, e);
		}
	}
}
public class MessageListBox : ResizableListBox
{
	private const int m_MainTextOffset = 50;

	private Font m_HeadingFont;

	private ImageList IconList;

	private IContainer components;

	public MessageListBox()
	{
		//IL_0014: Unknown result type (might be due to invalid IL or missing references)
		//IL_001e: Expected O, but got Unknown
		//IL_0026: Unknown result type (might be due to invalid IL or missing references)
		//IL_0030: Expected O, but got Unknown
		InitializeComponent();
		m_HeadingFont = new Font(((Control)this).Font, (FontStyle)1);
		base.MeasureItem += new MeasureItemEventHandler(MeasureItemHandler);
	}

	private void InitializeComponent()
	{
		//IL_0022: Unknown result type (might be due to invalid IL or missing references)
		//IL_002c: Expected O, but got Unknown
		//IL_005d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0067: Expected O, but got Unknown
		components = new Container();
		ResourceManager resourceManager = new ResourceManager(typeof(MessageListBox));
		IconList = new ImageList(components);
		IconList.ColorDepth = (ColorDepth)8;
		IconList.ImageSize = new Size(16, 16);
		IconList.ImageStream = (ImageListStreamer)resourceManager.GetObject("IconList.ImageStream");
		IconList.TransparentColor = Color.Transparent;
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		m_HeadingFont.Dispose();
		((Control)this).Dispose(disposing);
	}

	protected override void OnDrawItem(DrawItemEventArgs e)
	{
		//IL_0031: Unknown result type (might be due to invalid IL or missing references)
		//IL_0037: Invalid comparison between Unknown and I4
		//IL_0092: Unknown result type (might be due to invalid IL or missing references)
		//IL_0099: Expected O, but got Unknown
		//IL_003e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0044: Expected O, but got Unknown
		e.DrawBackground();
		e.DrawFocusRectangle();
		Rectangle bounds = e.Bounds;
		Color color = SystemColors.ControlText;
		ParseMessageEventArgs e2 = (ParseMessageEventArgs)base.Items[e.Index];
		if ((int)e.State == 1)
		{
			Brush val = (Brush)new SolidBrush(SystemColors.Highlight);
			try
			{
				e.Graphics.FillRectangle(val, e.Bounds);
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
			color = SystemColors.HighlightText;
		}
		IconList.Draw(e.Graphics, bounds.Left + 1, bounds.Top + 2, (int)e2.MessageType);
		SolidBrush val2 = new SolidBrush(color);
		try
		{
			e.Graphics.DrawString(string.Concat(DateTime.Now, " - ", e2.Title, ":"), m_HeadingFont, (Brush)(object)val2, (float)(bounds.Left + IconList.ImageSize.Width + 5), (float)(bounds.Top + IconList.ImageSize.Height - m_HeadingFont.Height));
			int num = 0;
			Size size = new Size(((Control)this).Width - 50, ((Control)this).Font.Height);
			string text = e2.MessageText;
			int num2 = bounds.Top + IconList.ImageSize.Height + 2;
			int num3 = default(int);
			while (text.Length > 0)
			{
				e.Graphics.MeasureString(e2.MessageText, ((Control)this).Font, (SizeF)size, StringFormat.GenericDefault, ref num, ref num3);
				if (text.Length <= num)
				{
					e.Graphics.DrawString(text, ((Control)this).Font, (Brush)(object)val2, (float)(bounds.Left + 50), (float)num2);
					break;
				}
				string text2 = text.Substring(0, num);
				if (text2.LastIndexOf(" ") > 0)
				{
					text2 = text2.Substring(0, text2.LastIndexOf(" "));
				}
				e.Graphics.DrawString(text2, ((Control)this).Font, (Brush)(object)val2, (float)(bounds.Left + 50), (float)num2);
				num2 += ((Control)this).Font.Height;
				text = text.Substring(text2.Length + 1);
			}
		}
		finally
		{
			((IDisposable)val2)?.Dispose();
		}
	}

	private void MeasureItemHandler(object sender, MeasureItemEventArgs e)
	{
		ParseMessageEventArgs e2 = (ParseMessageEventArgs)base.Items[e.Index];
		Size size = new Size((int)((double)(((Control)this).Width - 50) * 0.9), 200);
		int num = default(int);
		int num2 = default(int);
		e.Graphics.MeasureString(e2.MessageText, ((Control)this).Font, (SizeF)size, StringFormat.GenericDefault, ref num, ref num2);
		int num3 = num2 * ((Control)this).Font.Height;
		e.ItemHeight = IconList.ImageSize.Height + num3 + 4;
	}
}
public class ParseMessageEventArgs : EventArgs
{
	private string m_Title;

	private string m_MessageText;

	private string m_ParseSource;

	private EventTypes m_Type = EventTypes.Unknown;

	public string MessageText
	{
		get
		{
			return m_MessageText;
		}
		set
		{
			m_MessageText = value;
		}
	}

	public string Source
	{
		get
		{
			return m_ParseSource;
		}
		set
		{
			m_ParseSource = value;
		}
	}

	public string Title
	{
		get
		{
			return m_Title;
		}
		set
		{
			m_Title = value;
		}
	}

	public EventTypes MessageType
	{
		get
		{
			return m_Type;
		}
		set
		{
			m_Type = value;
		}
	}

	public ParseMessageEventArgs()
	{
	}

	public ParseMessageEventArgs(EventTypes type, string Title, string MessageText)
		: this()
	{
		m_Title = Title;
		m_MessageText = MessageText;
		m_Type = type;
	}

	public ParseMessageEventArgs(EventTypes type, string Title, string MessageText, string Source)
		: this(type, Title, MessageText)
	{
		m_ParseSource = Source;
	}
}
