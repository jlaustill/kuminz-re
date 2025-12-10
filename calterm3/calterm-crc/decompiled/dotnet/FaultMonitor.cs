#define TRACE
using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Data.Common;
using System.Data.OleDb;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Threading;
using System.Windows.Forms;
using Balloons;
using Cummins.AddressRepresentation;
using Cummins.ApplicationServices;
using Cummins.Calibration;
using Cummins.EventLog;
using Cummins.Interop.FaultCodes;
using Cummins.Module;
using Cummins.Services;
using Cummins.Widgets;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - FaultMonitor")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTitle("Poodle")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.FaultMonitor;

public class BlockedFaultList : Form
{
	private Button buttonOK;

	private DataTable blockedfaultTable;

	private DataView blockedfaultView;

	private DataGrid dtgBlockedFaults;

	private DataGridTableStyle dgtsDisplayBlockedFaults;

	private DataGridTextBoxColumn FaultCode;

	private DataGridTextBoxColumn FaultCount;

	private DataGridTextBoxColumn FaultStatus;

	private DataGridTextBoxColumn SourceAddress;

	private DataGridTextBoxColumn BlockingStatus;

	private Container components;

	public DataTable BlockedfaultTable
	{
		get
		{
			return blockedfaultTable;
		}
		set
		{
			blockedfaultTable = value;
		}
	}

	public BlockedFaultList(DataTable blockedFaultTable)
	{
		InitializeComponent();
		Init(blockedFaultTable);
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing)
		{
			if (components != null)
			{
				components.Dispose();
			}
			if (blockedfaultView != null)
			{
				blockedfaultView.Dispose();
			}
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
		//IL_038f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0399: Expected O, but got Unknown
		ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(BlockedFaultList));
		buttonOK = new Button();
		dtgBlockedFaults = new DataGrid();
		dgtsDisplayBlockedFaults = new DataGridTableStyle();
		FaultCode = new DataGridTextBoxColumn();
		FaultCount = new DataGridTextBoxColumn();
		FaultStatus = new DataGridTextBoxColumn();
		SourceAddress = new DataGridTextBoxColumn();
		BlockingStatus = new DataGridTextBoxColumn();
		((ISupportInitialize)dtgBlockedFaults).BeginInit();
		((Control)this).SuspendLayout();
		((Control)buttonOK).Anchor = (AnchorStyles)10;
		buttonOK.DialogResult = (DialogResult)2;
		((Control)buttonOK).Location = new Point(349, 240);
		((Control)buttonOK).Name = "buttonOK";
		((Control)buttonOK).Size = new Size(75, 23);
		((Control)buttonOK).TabIndex = 1;
		((Control)buttonOK).Text = "OK";
		((Control)buttonOK).Click += buttonOK_Click;
		dtgBlockedFaults.AllowNavigation = false;
		dtgBlockedFaults.BackgroundColor = SystemColors.Window;
		dtgBlockedFaults.CaptionVisible = false;
		dtgBlockedFaults.DataMember = "";
		dtgBlockedFaults.HeaderForeColor = SystemColors.ControlText;
		((Control)dtgBlockedFaults).Location = new Point(8, 8);
		((Control)dtgBlockedFaults).Name = "dtgBlockedFaults";
		dtgBlockedFaults.ReadOnly = true;
		((Control)dtgBlockedFaults).Size = new Size(416, 224);
		((Control)dtgBlockedFaults).TabIndex = 8;
		dtgBlockedFaults.TableStyles.AddRange((DataGridTableStyle[])(object)new DataGridTableStyle[1] { dgtsDisplayBlockedFaults });
		dgtsDisplayBlockedFaults.DataGrid = dtgBlockedFaults;
		dgtsDisplayBlockedFaults.GridColumnStyles.AddRange((DataGridColumnStyle[])(object)new DataGridColumnStyle[5]
		{
			(DataGridColumnStyle)FaultCode,
			(DataGridColumnStyle)FaultCount,
			(DataGridColumnStyle)FaultStatus,
			(DataGridColumnStyle)SourceAddress,
			(DataGridColumnStyle)BlockingStatus
		});
		dgtsDisplayBlockedFaults.HeaderForeColor = SystemColors.ControlText;
		dgtsDisplayBlockedFaults.PreferredColumnWidth = 90;
		dgtsDisplayBlockedFaults.ReadOnly = true;
		dgtsDisplayBlockedFaults.RowHeadersVisible = false;
		FaultCode.Format = "";
		FaultCode.FormatInfo = null;
		((DataGridColumnStyle)FaultCode).Width = 90;
		FaultCount.Format = "";
		FaultCount.FormatInfo = null;
		((DataGridColumnStyle)FaultCount).Width = 90;
		FaultStatus.Format = "";
		FaultStatus.FormatInfo = null;
		((DataGridColumnStyle)FaultStatus).Width = 90;
		SourceAddress.Format = "";
		SourceAddress.FormatInfo = null;
		((DataGridColumnStyle)SourceAddress).Width = 90;
		BlockingStatus.Format = "";
		BlockingStatus.FormatInfo = null;
		((DataGridColumnStyle)BlockingStatus).Width = 90;
		((Form)this).AcceptButton = (IButtonControl)(object)buttonOK;
		((Form)this).AutoScaleBaseSize = new Size(5, 13);
		((Form)this).CancelButton = (IButtonControl)(object)buttonOK;
		((Control)this).CausesValidation = false;
		((Form)this).ClientSize = new Size(434, 271);
		((Control)this).Controls.Add((Control)(object)dtgBlockedFaults);
		((Control)this).Controls.Add((Control)(object)buttonOK);
		((Form)this).FormBorderStyle = (FormBorderStyle)1;
		((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
		((Form)this).KeyPreview = true;
		((Form)this).MaximizeBox = false;
		((Control)this).Name = "BlockedFaultList";
		((Form)this).StartPosition = (FormStartPosition)1;
		((Control)this).Text = "Blocked Fault List";
		((Form)this).TopMost = true;
		((ISupportInitialize)dtgBlockedFaults).EndInit();
		((Control)this).ResumeLayout(false);
	}

	private void buttonOK_Click(object sender, EventArgs e)
	{
		((Component)this).Dispose();
	}

	public void Init(DataTable blockedFaultTable)
	{
		blockedfaultTable = blockedFaultTable;
		blockedfaultView = new DataView(blockedfaultTable);
		dtgBlockedFaults.DataSource = blockedfaultView;
		dgtsDisplayBlockedFaults.MappingName = "Fault Code";
		dtgBlockedFaults.TableStyles.Clear();
		dtgBlockedFaults.TableStyles.Add(dgtsDisplayBlockedFaults);
		int count = blockedfaultTable.Columns.Count;
		int verticalScrollBarWidth = SystemInformation.VerticalScrollBarWidth;
		int num = ((Control)dtgBlockedFaults).ClientSize.Width - verticalScrollBarWidth - 4;
		int num2 = 0;
		for (int i = 0; i < count - 1; i++)
		{
			num2 += dtgBlockedFaults.TableStyles["Fault Code"].GridColumnStyles[i].Width;
		}
		if (num2 < num)
		{
			dtgBlockedFaults.TableStyles["Fault Code"].GridColumnStyles[count - 1].Width = num - num2;
		}
	}
}
public class FaultData
{
	public string SID;

	public string PID;

	public string SPN;

	public string lampColor;

	public string description;
}
public class FaultDatabase
{
	private enum TableName
	{
		AppendixA,
		AppendixB
	}

	public const string DefaultFaultDataPath = "\\FaultDB\\Service Fault Codes.xls";

	private const string appBFilename = "Cummins.FaultMonitor.AppendixBTable.xml";

	private OleDbConnection DBConnection;

	private string databaseSource;

	private string[] tableName = new string[2] { "App A - CoreII & New Products", "App B - CoreI & Legacy" };

	private DataSet appBDataSet;

	public string DatabaseSource
	{
		get
		{
			return databaseSource;
		}
		set
		{
			databaseSource = value;
			MakeConnection();
		}
	}

	public FaultDatabase()
	{
		CreateAppendixBDataSet();
		MakeConnection();
	}

	public void GetFaultCodeData(string productId, int faultCode, out FaultData result)
	{
		result = new FaultData();
		result.description = "Not available";
		result.SID = "N/A";
		result.PID = "N/A";
		result.lampColor = "N/A";
		try
		{
			((DbConnection)(object)DBConnection).Open();
			OleDbCommand val = DBConnection.CreateCommand();
			string arg = SelectTable(productId);
			((DbCommand)(object)val).CommandText = $"SELECT [PID],[SID],[SPN],[Lamp Color],[Cummins Description] FROM [{arg}$B:M]WHERE [Cummins Fault Code]='{faultCode}'";
			OleDbDataReader val2 = val.ExecuteReader();
			while (((DbDataReader)(object)val2).Read())
			{
				result.SID = ((DbDataReader)(object)val2)["SID"].ToString();
				result.PID = ((DbDataReader)(object)val2)["PID"].ToString();
				result.SPN = ((DbDataReader)(object)val2)["SPN"].ToString();
				result.lampColor = ((DbDataReader)(object)val2)["Lamp Color"].ToString();
				result.description = ((DbDataReader)(object)val2)["Cummins Description"].ToString();
			}
		}
		catch (Exception)
		{
			result.description = "Failed to connect to data source";
		}
		finally
		{
			((DbConnection)(object)DBConnection).Close();
		}
	}

	private string SelectTable(string productId)
	{
		string text = "";
		DataRow[] array = appBDataSet.Tables["Product"].Select("ProductId = '" + productId + "'");
		if (array.Length > 0)
		{
			return tableName[1];
		}
		return tableName[0];
	}

	private void MakeConnection()
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_000b: Expected O, but got Unknown
		DBConnection = new OleDbConnection();
		((DbConnection)(object)DBConnection).ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + DatabaseSource + ";Extended Properties=\"Excel 8.0;IMEX=1\"";
	}

	private void CreateAppendixBDataSet()
	{
		appBDataSet = new DataSet();
		Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream("Cummins.FaultMonitor.AppendixBTable.xml");
		appBDataSet.ReadXml(manifestResourceStream);
		appBDataSet.CaseSensitive = false;
		manifestResourceStream.Close();
	}
}
internal interface IFaultMonitor
{
	event FaultsUpdateEventHandler FaultsUpdateEvent;
}
public class FaultMonitorController : Component, IPropertyPageProvider, IFaultMonitor
{
	private delegate void BlinkingFaultsDelegate(bool enable);

	private Container components;

	private Timer faultRefreshTimer;

	private FaultMonitorPreferences faultPreference;

	private FaultMonitorModel faultModel;

	private FaultMonitorView faultView;

	private bool faultMonitoringEnabled;

	private bool timerEnabled = true;

	private bool currentlyRefreshing;

	protected Mutex syncFaultRequest = new Mutex();

	public Timer FaultRefreshTimer
	{
		get
		{
			if (faultRefreshTimer == null)
			{
				faultRefreshTimer = new Timer(OnTimedEvent, null, -1, FaultModel.FaultMonitoringRate * 1000);
			}
			return faultRefreshTimer;
		}
	}

	public bool FaultMonitoringEnabled
	{
		get
		{
			return faultMonitoringEnabled;
		}
		set
		{
			if (faultMonitoringEnabled != value)
			{
				faultMonitoringEnabled = value;
				if (faultMonitoringEnabled)
				{
					StartMonitoring();
				}
				else
				{
					StopMonitoring(this, null);
				}
			}
		}
	}

	public FaultMonitorModel FaultModel
	{
		get
		{
			return faultModel;
		}
		set
		{
			faultModel = value;
		}
	}

	public FaultMonitorView FaultView
	{
		get
		{
			return faultView;
		}
		set
		{
			faultView = value;
		}
	}

	public FaultMonitorOptions FaultOptions
	{
		get
		{
			return faultModel.FaultOptions;
		}
		set
		{
			faultModel.FaultOptions = value;
		}
	}

	public IModuleNetwork DataSource
	{
		get
		{
			return faultModel.DataSource;
		}
		set
		{
			if (faultModel.DataSource != null)
			{
				faultModel.DataSource.ConnectionFading -= OnConnectionLost;
				faultModel.DataSource.ConnectionLost -= OnConnectionLost;
				faultModel.DataSource.ConnectionEstablished -= OnConnectionEstablished;
				faultModel.DataSource.SuspendMonitoringChanged -= OnSuspendMonitoringChanged;
			}
			faultModel.DataSource = value;
			if (faultModel.DataSource != null)
			{
				faultModel.DataSource.ConnectionFading += OnConnectionLost;
				faultModel.DataSource.ConnectionLost += OnConnectionLost;
				faultModel.DataSource.ConnectionEstablished += OnConnectionEstablished;
				faultModel.DataSource.SuspendMonitoringChanged += OnSuspendMonitoringChanged;
				FaultMonitoringEnabled = !faultModel.DataSource.SuspendMonitoring;
				return;
			}
			FaultMonitoringEnabled = false;
			if (faultRefreshTimer != null)
			{
				faultRefreshTimer.Dispose();
				faultRefreshTimer = null;
				currentlyRefreshing = false;
			}
		}
	}

	public ArrayList Pages
	{
		get
		{
			ArrayList arrayList = new ArrayList();
			faultPreference = new FaultMonitorPreferences("", "Fault Monitor");
			faultPreference.Initialize(this, faultModel);
			faultPreference.FaultOptionChanged += faultModel.OnFaultOptionChanged;
			arrayList.Add(faultPreference);
			return arrayList;
		}
	}

	public bool BlockingStatus => faultModel.BlockingStatus;

	public bool CanBlockFault => faultModel.CanBlockFault;

	private event BlinkingFaultsDelegate BlinkFaultsEnabled;

	public event FaultsUpdateEventHandler FaultsUpdateEvent
	{
		add
		{
			faultModel.FaultsUpdateEvent += value;
		}
		remove
		{
			faultModel.FaultsUpdateEvent -= value;
		}
	}

	public FaultMonitorController(FaultMonitorView faultView)
	{
		InitializeComponent();
		faultModel = new FaultMonitorModel();
		this.faultView = faultView;
		Initialize();
	}

	public FaultMonitorController(IContainer container)
	{
		container.Add(this);
		InitializeComponent();
		faultModel = new FaultMonitorModel();
		faultView = new FaultMonitorView();
		Initialize();
	}

	public FaultMonitorController()
	{
		InitializeComponent();
		faultModel = new FaultMonitorModel();
		faultView = new FaultMonitorView();
		Initialize();
	}

	internal void Initialize()
	{
		faultView.FaultModel = faultModel;
		faultView.Initialize();
		faultModel.FaultMonitorExceptionEvent += StopMonitoring;
		faultModel.FaultModelChangedEvent += faultView.OnFaultModelChanged;
		faultModel.CurrentDeviceSetChanged += OnCurrentDeviceSetChanged;
		faultModel.FaultMonitorRateChanged += OnFaultMonitorRateChanged;
		faultModel.OnFaultOptionChanged(faultModel, EventArgs.Empty);
		currentlyRefreshing = false;
	}

	internal void OnCurrentDeviceSetChanged(object sender, EventArgs e)
	{
		try
		{
			if (FaultMonitoringEnabled)
			{
				StopMonitoring(this, EventArgs.Empty);
				faultModel.RefreshFaults();
				StartMonitoring();
			}
		}
		catch (Exception e2)
		{
			EventLogger.Error("FaultMonitor", "Error in setting the value for MultiModule monitoring", e2);
		}
	}

	private void InitializeComponent()
	{
		components = new Container();
	}

	private void StartMonitoring()
	{
		if (DataSource != null && !DataSource.SuspendMonitoring)
		{
			timerEnabled = true;
			FaultRefreshTimer.Change(0, FaultModel.FaultMonitoringRate * 1000);
			BlinkingFaultsEnabled(enable: true);
		}
	}

	private void StopMonitoring(object sender, EventArgs e)
	{
		if (faultRefreshTimer != null)
		{
			faultRefreshTimer.Change(-1, -1);
			faultRefreshTimer = null;
			timerEnabled = false;
			currentlyRefreshing = false;
		}
		BlinkingFaultsEnabled(enable: false);
	}

	private void BlinkingFaultsEnabled(bool enable)
	{
		if (faultView != null)
		{
			if (!((Control)faultView).InvokeRequired)
			{
				faultView.BlinkingFaults = enable;
				return;
			}
			((Control)faultView).BeginInvoke((Delegate)new BlinkingFaultsDelegate(BlinkingFaultsEnabled), new object[1] { enable });
		}
	}

	public void ResetActiveFaults()
	{
		faultModel.ResetFaults(FaultStatus.Active);
	}

	public void ResetInActiveFaults()
	{
		faultModel.ResetFaults(FaultStatus.PrevActive);
	}

	public void BlockSelectedFaults()
	{
		try
		{
			faultModel.BlockFault(faultView.GetSelectedFaultList());
		}
		catch (Exception ex)
		{
			EventLogger.Error("FaultController", ex.Message);
		}
	}

	public void UnblockFaults()
	{
		if (faultModel.BlockingStatus)
		{
			try
			{
				faultModel.UnblockFaults();
				faultView.FaultBlockLabel = " ";
				faultView.FaultBlockColor = SystemColors.ActiveCaption;
			}
			catch (Exception ex)
			{
				EventLogger.Error("FaultController", ex.Message);
			}
		}
	}

	public void ViewBlockedFaults()
	{
		//IL_0102: Unknown result type (might be due to invalid IL or missing references)
		DataTable dataTable = faultModel.FaultDataTable.Clone();
		DataRow[] array = faultModel.FaultDataTable.Select("BlockingStatus = 'true'");
		if (array.Length > 0)
		{
			for (int i = 0; i < array.Length; i++)
			{
				string text = (string)array[i]["FaultCode"];
				int num = (int)array[i]["FaultCount"];
				string text2 = (string)array[i]["FaultStatus"];
				string text3 = (string)array[i]["SourceAddress"];
				bool flag = (bool)array[i]["BlockingStatus"];
				dataTable.Rows.Add(text, num, text2, text3, flag);
			}
		}
		dataTable.AcceptChanges();
		if (dataTable.Rows.Count > 0)
		{
			BlockedFaultList blockedFaultList = new BlockedFaultList(dataTable);
			((Form)blockedFaultList).ShowDialog();
		}
	}

	public void RetrieveFault()
	{
		try
		{
			faultModel.RefreshFaults();
		}
		catch (Exception ex)
		{
			Trace.WriteLine(ex.Message + Environment.NewLine + ex.StackTrace, "FaultMonitorController.RetrieveFault");
		}
	}

	public void RefreshCodeFormat()
	{
		FaultView.ViewHexCodes();
	}

	public void UpdateFaultViewStyle()
	{
		if (faultModel.ViewSmallIcons)
		{
			FaultView.FaultList.View = (View)2;
		}
		else
		{
			FaultView.FaultList.View = (View)0;
		}
	}

	public void OnFaultOptionChanged(object caller, FaultMonitorOptions options)
	{
		FaultOptions = options;
	}

	internal void OnTimedEvent(object source)
	{
		if (!faultModel.StopMonitoring || currentlyRefreshing)
		{
			return;
		}
		syncFaultRequest.WaitOne();
		currentlyRefreshing = true;
		try
		{
			if (timerEnabled)
			{
				faultModel.RequestFault();
			}
		}
		catch (Exception ex)
		{
			Trace.WriteLine(ex.Message + Environment.NewLine + ex.StackTrace, "FaultMonitorController.OnTimedEvent");
		}
		finally
		{
			currentlyRefreshing = false;
			syncFaultRequest.ReleaseMutex();
		}
	}

	internal void OnSuspendMonitoringChanged(object sender, SuspendMonitoringChangedEventArgs e)
	{
		if (FaultModel != null && FaultModel.DataSource != null)
		{
			FaultMonitoringEnabled = !FaultModel.DataSource.SuspendMonitoring;
		}
	}

	internal void OnConnectionLost(object sender, DeviceAddressEventArgs e)
	{
		FaultMonitoringEnabled = false;
	}

	internal void OnConnectionEstablished(object sender, DeviceAddressEventArgs e)
	{
		if (FaultModel != null && FaultModel.DataSource != null)
		{
			FaultMonitoringEnabled = !FaultModel.DataSource.SuspendMonitoring;
		}
	}

	private void OnFaultMonitorRateChanged(object sender, FaultMonitorRateChangedEventArgs args)
	{
		if (args.OldValue != args.NewValue)
		{
			FaultRefreshTimer.Change(0, args.NewValue * 1000);
		}
	}
}
public enum FaultStatus
{
	Unknown,
	Active,
	PrevActive
}
public delegate void FaultsUpdateEventHandler(object sender, FaultsUpdateEventArgs eArgs);
public delegate void FaultMonitorRateChangedEventHandler(object sender, FaultMonitorRateChangedEventArgs args);
public delegate void FaultMenuClickedEventHandler(object sender, EventArgs e);
public delegate void FaultDisplayChangedHandler(object sender, EventArgs e);
public enum menuOptions
{
	StartFaultMonitor,
	StopFaultMonitor,
	BlockSelectedFaults,
	UnblockFaults,
	EraseInactiveFaults,
	EraseActiveFaults,
	EraseAllFaults,
	ShowFaultStatus,
	ShowFaultCount,
	ViewBlockedFaults,
	ViewLargeIcons,
	ViewSmallIcons,
	ShowDescription,
	ShowHexCode
}
public class FaultMonitorMenu : ContextMenu
{
	private const int NUMOFITEMS = 14;

	private string[] faultMenuOptions;

	private FaultMonitorModel faultModel;

	private bool BlockUnblockFault
	{
		set
		{
			((Menu)this).MenuItems[3].Visible = value;
			((Menu)this).MenuItems[2].Visible = value;
		}
	}

	public event FaultMenuClickedEventHandler FaultMenuClickedEvent;

	public event FaultDisplayChangedHandler FaultDisplayChangedEvent;

	public FaultMonitorMenu(FaultMonitorModel faultModel)
	{
		faultMenuOptions = new string[14]
		{
			"Start Fault Monitor", "Stop  Fault Monitor", "Block Selected Faults", "Unblock Faults", "Erase Inactive Faults", "Erase Active Faults", "Erase All Faults", "Show Fault Status", "Show Fault Count", "View Blocked Faults",
			"Show Faults with double-spaced", "Show Faults with single-spaced", "Show Description", "Show faults in HEX"
		};
		this.faultModel = faultModel;
		InitMenuItems();
		ISecurityService securityService = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
		securityService.LicenseChangedEvent += OnLicenseChanged;
	}

	public void DisableAllFaultMenuItems()
	{
		//IL_0014: Unknown result type (might be due to invalid IL or missing references)
		//IL_001a: Expected O, but got Unknown
		foreach (MenuItem menuItem in ((Menu)this).MenuItems)
		{
			MenuItem val = menuItem;
			val.Enabled = false;
		}
	}

	public void EnableAllFaultMenuItems()
	{
		//IL_0014: Unknown result type (might be due to invalid IL or missing references)
		//IL_001a: Expected O, but got Unknown
		foreach (MenuItem menuItem in ((Menu)this).MenuItems)
		{
			MenuItem val = menuItem;
			val.Enabled = true;
		}
	}

	public void SetFaultMenuItemEnableStatus(int menuIndex, bool status)
	{
		if (menuIndex < ((Menu)this).MenuItems.Count)
		{
			((Menu)this).MenuItems[menuIndex].Enabled = status;
		}
	}

	public void SetFaultMenuItemEnableStatus(menuOptions option, bool status)
	{
		((Menu)this).MenuItems[(int)option].Enabled = status;
	}

	internal void InitMenuItems()
	{
		//IL_0047: Unknown result type (might be due to invalid IL or missing references)
		//IL_004d: Expected O, but got Unknown
		for (int i = 0; i < faultMenuOptions.Length; i++)
		{
			((Menu)this).MenuItems.Add(faultMenuOptions[i], (EventHandler)popup);
		}
		foreach (MenuItem menuItem in ((Menu)this).MenuItems)
		{
			MenuItem val = menuItem;
			val.Checked = false;
		}
		SetMenuItemStatus();
	}

	internal void SetMenuItemStatus()
	{
		if (faultModel.ShowFaultStatus)
		{
			((Menu)this).MenuItems[7].Checked = true;
		}
		else
		{
			((Menu)this).MenuItems[7].Checked = false;
		}
		if (faultModel.ShowFaultCount)
		{
			((Menu)this).MenuItems[8].Checked = true;
		}
		else
		{
			((Menu)this).MenuItems[8].Checked = false;
		}
		if (faultModel.ShowDescription)
		{
			((Menu)this).MenuItems[12].Checked = true;
		}
		else
		{
			((Menu)this).MenuItems[12].Checked = false;
		}
		if (faultModel.ShowHexCode)
		{
			((Menu)this).MenuItems[7].Checked = true;
		}
		else
		{
			((Menu)this).MenuItems[7].Checked = false;
		}
		if (faultModel.ViewSmallIcons)
		{
			((Menu)this).MenuItems[11].Checked = true;
			((Menu)this).MenuItems[10].Checked = false;
		}
		else
		{
			((Menu)this).MenuItems[11].Checked = false;
			((Menu)this).MenuItems[10].Checked = true;
		}
		((Menu)this).MenuItems[0].Visible = false;
		((Menu)this).MenuItems[1].Visible = false;
		((Menu)this).MenuItems[5].Visible = false;
		((Menu)this).MenuItems[6].Visible = false;
		((Menu)this).MenuItems[4].Visible = false;
		ISecurityService securityService = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
		BlockUnblockFault = securityService.IsFeatureSelected("BlockUnBlockFaults");
	}

	internal void SetMenuItemStatus(int index, bool status)
	{
		((Menu)this).MenuItems[index].Checked = status;
	}

	private void popup(object sender, EventArgs e)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		MenuItem val = (MenuItem)sender;
		try
		{
			if (val.Index == 0)
			{
				if (!val.Checked)
				{
					val.Checked = true;
					((Menu)this).MenuItems[1].Checked = false;
					RaiseFaultMenuClickedEvent(val, null);
				}
			}
			else if (val.Index == 1)
			{
				if (!val.Checked)
				{
					val.Checked = true;
					((Menu)this).MenuItems[0].Checked = false;
					RaiseFaultMenuClickedEvent(val, null);
				}
			}
			else if (val.Index == 2)
			{
				((Menu)this).MenuItems[3].Checked = false;
				RaiseFaultMenuClickedEvent(val, null);
			}
			else if (val.Index == 3)
			{
				((Menu)this).MenuItems[2].Checked = false;
				RaiseFaultMenuClickedEvent(val, null);
			}
			else if (val.Index == 8)
			{
				val.Checked = !val.Checked;
				faultModel.ShowFaultCount = !faultModel.ShowFaultCount;
			}
			else if (val.Index == 7)
			{
				val.Checked = !val.Checked;
				faultModel.ShowFaultStatus = !faultModel.ShowFaultStatus;
			}
			else if (val.Index == 10 || val.Index == 11)
			{
				val.Checked = !val.Checked;
				faultModel.ViewSmallIcons = !faultModel.ViewSmallIcons;
				((Menu)this).MenuItems[11].Checked = faultModel.ViewSmallIcons;
				((Menu)this).MenuItems[10].Checked = !faultModel.ViewSmallIcons;
				RaiseFaultMenuClickedEvent(val, null);
			}
			else if (val.Index == 12)
			{
				val.Checked = !val.Checked;
				faultModel.ShowDescription = !faultModel.ShowDescription;
			}
			else if (val.Index == 13)
			{
				val.Checked = !val.Checked;
				faultModel.ShowHexCode = !faultModel.ShowHexCode;
				RaiseFaultMenuClickedEvent(val, null);
				RaiseFaultDisplayChangedEvent(val, null);
			}
			else
			{
				RaiseFaultMenuClickedEvent(val, null);
			}
		}
		catch
		{
		}
	}

	private void RaiseFaultMenuClickedEvent(object sender, EventArgs e)
	{
		if (this.FaultMenuClickedEvent != null)
		{
			this.FaultMenuClickedEvent(sender, e);
		}
	}

	private void RaiseFaultDisplayChangedEvent(object sender, EventArgs e)
	{
		if (this.FaultDisplayChangedEvent != null)
		{
			this.FaultDisplayChangedEvent(sender, e);
		}
	}

	private void OnLicenseChanged(object sender, EventArgs e)
	{
		BlockUnblockFault = (sender as ISecurityService).IsFeatureSelected(SelectableFeatures.BlockUnBlockFaults.ToString());
	}
}
public delegate void FaultItemChangedEventHandler(object sender, FaultItemChangedEventArgs e);
public delegate void ReloadFaultViewEventHandler(object sender, FaultsUpdateEventArgs eArgs);
public delegate void FaulMonitorExceptionEventHandler(object sender, EventArgs e);
public delegate void FaultModelChangedEventHandler(object sender, EventArgs e);
public delegate void RetrieveFaultCountDelegate(ref FaultCountInfo faultCountInfo);
public class FaultItemChangedEventArgs : EventArgs
{
	public string faultCode;

	public FaultStatus status;

	public string faultCount;

	public string sourceAddress;
}
public class FaultMonitorModel
{
	internal const int FaultCountNotAvailable = -1;

	private const int defaultFaultRate = 60;

	private const string ClearedStatus = "Cleared";

	private bool showDescription;

	private bool showSourceAddr;

	private bool showFaultCount;

	private bool showFaultStatus;

	private bool showHexCode;

	private SortedList faultComponent;

	private IModuleNetwork dataSource;

	private DataTable faultDataTable;

	private bool multimoduleMonitor;

	private bool viewSmallIcons = true;

	private IAddressValue currentDeviceAddress;

	private bool isCurrentlyRefreshing;

	private FaultDatabase faultDatabase;

	protected Mutex syncFaultUpdate = new Mutex();

	private bool stopMonitoring;

	private bool errorInRetrievingFault;

	private int faultMonitoringRate;

	private bool canBlockFault;

	internal bool MultimoduleMonitor
	{
		get
		{
			return multimoduleMonitor;
		}
		set
		{
			if (multimoduleMonitor != value)
			{
				multimoduleMonitor = value;
				RaiseCurrentDeviceSetChanged();
			}
		}
	}

	internal bool ViewSmallIcons
	{
		get
		{
			return viewSmallIcons;
		}
		set
		{
			viewSmallIcons = value;
		}
	}

	public IModuleNetwork DataSource
	{
		get
		{
			return dataSource;
		}
		set
		{
			dataSource = value;
			if (dataSource != null)
			{
				currentDeviceAddress = dataSource.CurrentDeviceAddress;
				for (byte b = 0; b < dataSource.Modules.Count; b++)
				{
					ICalibrationOnline calibrationOnline = dataSource.Modules.GetByIndex(b) as ICalibrationOnline;
					if (calibrationOnline is ICalibrationECM)
					{
						ICalibrationECM calibrationECM = calibrationOnline as ICalibrationECM;
						ResetFaultComponent(calibrationECM);
					}
				}
			}
			else
			{
				faultDataTable.Clear();
				faultDataTable.AcceptChanges();
				RaiseReloadFaultViewEvent(this, new FaultsUpdateEventArgs(FaultDataTable));
			}
		}
	}

	public FaultMonitorOptions FaultOptions
	{
		get
		{
			FaultMonitorOptions result = default(FaultMonitorOptions);
			result.showDescription = showDescription;
			result.showSourceAddr = showSourceAddr;
			result.showFaultCount = showFaultCount;
			result.showFaultStatus = showFaultStatus;
			result.viewSmallIcons = viewSmallIcons;
			return result;
		}
		set
		{
			showDescription = value.showDescription;
			showSourceAddr = value.showSourceAddr;
			showFaultCount = value.showFaultCount;
			showFaultStatus = value.showFaultStatus;
			viewSmallIcons = value.viewSmallIcons;
		}
	}

	public bool ShowDescription
	{
		get
		{
			return showDescription;
		}
		set
		{
			showDescription = value;
		}
	}

	public bool ShowHexCode
	{
		get
		{
			return showHexCode;
		}
		set
		{
			showHexCode = value;
		}
	}

	public bool StopMonitoring
	{
		get
		{
			return stopMonitoring;
		}
		set
		{
			stopMonitoring = value;
		}
	}

	public bool ShowSourceAddr
	{
		get
		{
			return showSourceAddr;
		}
		set
		{
			showSourceAddr = value;
		}
	}

	public bool ShowFaultCount
	{
		get
		{
			return showFaultCount;
		}
		set
		{
			showFaultCount = value;
		}
	}

	public bool ShowFaultStatus
	{
		get
		{
			return showFaultStatus;
		}
		set
		{
			showFaultStatus = value;
		}
	}

	public string FaultDatabaseFilename
	{
		get
		{
			return faultDatabase.DatabaseSource;
		}
		set
		{
			if (value != faultDatabase.DatabaseSource)
			{
				faultDatabase.DatabaseSource = value;
				RaiseFaultDataBaseChangedEvent();
			}
		}
	}

	public FaultDatabase FaultDatabaseData => faultDatabase;

	internal DataTable FaultDataTable => faultDataTable.Copy();

	internal bool BlockingStatus
	{
		get
		{
			bool result = false;
			try
			{
				DataRow[] array = faultDataTable.Select("BlockingStatus = true");
				result = array.Length > 0;
			}
			catch (Exception)
			{
			}
			return result;
		}
	}

	internal int FaultMonitoringRate
	{
		get
		{
			return faultMonitoringRate;
		}
		set
		{
			int num = value;
			if (num > FaultMonitorPreferences.DefaultMaxFaultRate)
			{
				num = FaultMonitorPreferences.DefaultMaxFaultRate;
			}
			else if (num < FaultMonitorPreferences.DefaultMinFaultRate)
			{
				num = FaultMonitorPreferences.DefaultMinFaultRate;
			}
			if (faultMonitoringRate != value)
			{
				int oldValue = faultMonitoringRate;
				faultMonitoringRate = num;
				RaiseFaultMonitorRateChanged(new FaultMonitorRateChangedEventArgs(oldValue, num));
			}
		}
	}

	internal bool CanBlockFault
	{
		get
		{
			return canBlockFault;
		}
		set
		{
			canBlockFault = value;
		}
	}

	public event FaultItemChangedEventHandler FaultItemChangedEvent;

	public event FaultItemChangedEventHandler FaultItemRemovedEvent;

	public event ReloadFaultViewEventHandler ReloadFaultViewEvent;

	public event FaulMonitorExceptionEventHandler FaultMonitorExceptionEvent;

	public event FaultsUpdateEventHandler FaultsUpdateEvent;

	public event FaultModelChangedEventHandler FaultModelChangedEvent;

	public event FaultMonitorRateChangedEventHandler FaultMonitorRateChanged;

	public event EventHandler CurrentDeviceSetChanged;

	public event EventHandler FaultDataBaseChangedEvent;

	internal FaultMonitorModel()
	{
		FaultMonitoringRate = 60;
		faultComponent = new SortedList();
		isCurrentlyRefreshing = false;
		InitializeFaultDataTable();
		faultDatabase = new FaultDatabase();
	}

	~FaultMonitorModel()
	{
		if (faultComponent == null)
		{
			return;
		}
		byte b = 0;
		while (b < faultComponent.Count)
		{
			ICIFaultCodes2 iCIFaultCodes = (ICIFaultCodes2)faultComponent.GetByIndex(b);
			if (iCIFaultCodes != null)
			{
				while (Marshal.ReleaseComObject(iCIFaultCodes) > 0)
				{
				}
				iCIFaultCodes = null;
			}
			b++;
		}
	}

	private void InitializeFaultDataTable()
	{
		faultDataTable = new DataTable("Fault Data");
		faultDataTable.Columns.Add("FaultCode", typeof(string));
		faultDataTable.Columns.Add("FaultCount", typeof(int));
		faultDataTable.Columns["FaultCount"].DefaultValue = -1;
		faultDataTable.Columns.Add("PreviousStatus", typeof(string));
		faultDataTable.Columns.Add("CurrentStatus", typeof(string));
		faultDataTable.Columns.Add("SourceAddress", typeof(string));
		faultDataTable.Columns.Add("BlockingStatus", typeof(bool));
	}

	internal void RefreshFaults()
	{
		faultDataTable.Clear();
		faultDataTable.AcceptChanges();
		if (StopMonitoring)
		{
			RequestFault();
			RaiseReloadFaultViewEvent(this, new FaultsUpdateEventArgs(FaultDataTable));
		}
	}

	private void RefreshFaultDataTable(ICICollection faultCollection, IAddressValue deviceAddress)
	{
		if (deviceAddress.Type != AddressType.ECM)
		{
			return;
		}
		try
		{
			lock (faultDataTable)
			{
				foreach (DataRow row in faultDataTable.Rows)
				{
					if (multimoduleMonitor)
					{
						if ((string)row["SourceAddress"] == deviceAddress.Value)
						{
							row["CurrentStatus"] = "Cleared";
						}
					}
					else
					{
						row["CurrentStatus"] = "Cleared";
					}
				}
			}
			for (int i = 0; i < faultCollection.Count; i++)
			{
				ICIFault iCIFault = (ICIFault)faultCollection[i];
				string text = $"{iCIFault.Code,4:D4}";
				string value = deviceAddress.Value;
				DataRow[] array;
				lock (faultDataTable)
				{
					array = faultDataTable.Select("FaultCode = '" + text + "' AND SourceAddress= '" + value + "'");
				}
				if (array.Length == 0)
				{
					lock (faultDataTable)
					{
						faultDataTable.Rows.Add(text, -1, FaultStatus.Unknown.ToString(), ((FaultStatus)iCIFault.Status).ToString(), value, false);
					}
					FaultItemChangedEventArgs e = new FaultItemChangedEventArgs();
					e.faultCode = text;
					e.status = (FaultStatus)iCIFault.Status;
					e.faultCount = iCIFault.Counts.ToString();
					e.sourceAddress = value;
					RaiseFaultItemChangedEvent(this, e);
				}
				else
				{
					DataRow dataRow2 = array[0];
					dataRow2["PreviousStatus"] = dataRow2["CurrentStatus"];
					dataRow2["CurrentStatus"] = ((FaultStatus)iCIFault.Status).ToString();
				}
			}
			lock (faultDataTable)
			{
				DataRow[] array = faultDataTable.Select("CurrentStatus = 'Cleared'");
				DataRow[] array2 = array;
				foreach (DataRow dataRow3 in array2)
				{
					RaiseFaultItemRemovedEvent((string)dataRow3["FaultCode"], (string)dataRow3["SourceAddress"]);
					faultDataTable.Rows.Remove(dataRow3);
				}
			}
			RaiseFaultUpdateEvent();
		}
		catch (Exception)
		{
		}
	}

	public void OnCurrentDeviceChanged(object sender, IAddressValue deviceAddress)
	{
		if (currentDeviceAddress.DeviceAddress != deviceAddress.DeviceAddress)
		{
			currentDeviceAddress = deviceAddress;
			if (!MultimoduleMonitor)
			{
				RefreshFaults();
			}
		}
	}

	internal void RaiseFaultUpdateEvent()
	{
		if (this.FaultsUpdateEvent != null)
		{
			this.FaultsUpdateEvent(this, new FaultsUpdateEventArgs(FaultDataTable));
		}
	}

	private void MonitorFault(ICIFaultCodes2 fault, IAddressValue deviceAddress)
	{
		if (!StopMonitoring || isCurrentlyRefreshing)
		{
			return;
		}
		syncFaultUpdate.WaitOne();
		isCurrentlyRefreshing = true;
		try
		{
			if (fault != null)
			{
				ICICollection faultCollection = fault.RetrieveFaultCodes();
				RefreshFaultDataTable(faultCollection, deviceAddress);
				if (errorInRetrievingFault)
				{
					EventLogger.Info("Fault Monitor", "Fault Monitoring Resumed");
				}
				errorInRetrievingFault = false;
			}
		}
		catch (COMException e)
		{
			if (DataSource != null && DataSource.GetCalibration(deviceAddress) != null && !errorInRetrievingFault && DataSource.GetCalibration(deviceAddress).Connected)
			{
				EventLogger.Error("Fault Monitor", "Error in retreiving fault", e);
				errorInRetrievingFault = true;
			}
			faultDataTable.Clear();
			faultDataTable.AcceptChanges();
			RaiseReloadFaultViewEvent(this, new FaultsUpdateEventArgs(FaultDataTable));
			RaiseFaultUpdateEvent();
		}
		finally
		{
			isCurrentlyRefreshing = false;
			syncFaultUpdate.ReleaseMutex();
		}
	}

	internal void RequestFault()
	{
		if (faultComponent == null || dataSource == null)
		{
			return;
		}
		if (!MultimoduleMonitor)
		{
			if (faultComponent.ContainsKey(currentDeviceAddress) && !dataSource.SystemSuspendMonitoring(currentDeviceAddress) && dataSource.GetCalibration(currentDeviceAddress).Connected)
			{
				MonitorFault((ICIFaultCodes2)faultComponent[currentDeviceAddress], currentDeviceAddress);
			}
			return;
		}
		for (int i = 0; i < faultComponent.Count; i++)
		{
			IAddressValue addressValue = (IAddressValue)faultComponent.GetKey(i);
			if (!dataSource.SystemSuspendMonitoring(addressValue) && dataSource.GetCalibration(addressValue).Connected)
			{
				MonitorFault((CIFaultCodesClass)faultComponent[addressValue], addressValue);
			}
		}
	}

	internal void RaiseFaultMonitorExceptionEvent(object sender, EventArgs e)
	{
		if (this.FaultMonitorExceptionEvent != null)
		{
			this.FaultMonitorExceptionEvent(sender, e);
		}
	}

	internal void RaiseFaultItemChangedEvent(object sender, FaultItemChangedEventArgs eArgs)
	{
		if (this.FaultItemChangedEvent != null)
		{
			this.FaultItemChangedEvent(sender, eArgs);
		}
	}

	internal void RaiseFaultItemRemovedEvent(string faultCode, string sourceAddress)
	{
		FaultItemChangedEventArgs e = new FaultItemChangedEventArgs();
		e.faultCode = faultCode;
		e.sourceAddress = sourceAddress;
		if (this.FaultItemRemovedEvent != null)
		{
			this.FaultItemRemovedEvent(this, e);
		}
	}

	internal void RaiseReloadFaultViewEvent(object sender, FaultsUpdateEventArgs eArgs)
	{
		if (this.ReloadFaultViewEvent != null)
		{
			this.ReloadFaultViewEvent(sender, eArgs);
		}
	}

	internal string GetFaultStatus(string faultCode)
	{
		string result = "";
		lock (faultDataTable)
		{
			string text = faultCode.Substring(0, faultCode.IndexOf(":"));
			string text2 = "";
			if (ShowHexCode)
			{
				text2 = faultCode.Substring(faultCode.IndexOf("x") + 1, faultCode.Length - faultCode.IndexOf("x") - 1);
				int num = int.Parse(text2, NumberStyles.AllowHexSpecifier);
				text2 = $"{num,4:D4}";
			}
			else
			{
				text2 = faultCode.Substring(faultCode.IndexOf(":") + 1, faultCode.Length - faultCode.IndexOf(":") - 1);
			}
			DataRow[] array = faultDataTable.Select("FaultCode = '" + text2 + "' AND SourceAddress= '" + text + "'");
			if (array.Length > 0)
			{
				DataRow dataRow = array[0];
				if (dataRow != null)
				{
					result = (string)dataRow["CurrentStatus"];
				}
			}
		}
		return result;
	}

	internal void ResetFaults(FaultStatus resettingType)
	{
		if (DataSource == null || !((ICalibrationECM)DataSource).Connected)
		{
			return;
		}
		try
		{
			if (resettingType != FaultStatus.Active)
			{
				_ = 2;
			}
		}
		catch (Exception ex)
		{
			throw new Exception(ex.Message);
		}
		RefreshFaults();
	}

	internal void BlockFault(ArrayList faultList)
	{
		if (faultList.Count <= 0)
		{
			return;
		}
		for (int i = 0; i < faultList.Count; i++)
		{
			string text = (string)faultList[i];
			string text2 = text.Substring(0, text.IndexOf(":"));
			string s;
			if (ShowHexCode)
			{
				s = text.Substring(text.IndexOf("x") + 1, text.Length - text.IndexOf("x") - 1);
				int num = int.Parse(s, NumberStyles.AllowHexSpecifier);
				s = $"{num,4:D4}";
			}
			else
			{
				s = text.Substring(text.IndexOf(":") + 1, text.Length - text.IndexOf(":") - 1);
			}
			DataRow[] array = faultDataTable.Select("FaultCode = '" + s + "' AND SourceAddress= '" + text2 + "'");
			if (array.Length > 0)
			{
				array[0]["BlockingStatus"] = true;
			}
		}
		RaiseReloadFaultViewEvent(this, new FaultsUpdateEventArgs(FaultDataTable));
	}

	internal void UnblockFaults()
	{
		foreach (DataRow row in faultDataTable.Rows)
		{
			row["BlockingStatus"] = false;
		}
		RaiseReloadFaultViewEvent(this, new FaultsUpdateEventArgs(FaultDataTable));
	}

	internal void GetFaultSnapsot()
	{
	}

	internal void OnFaultOptionChanged(object sender, EventArgs e)
	{
		showDescription = AppSettingHelper.GetSettingAsBool(ApplicationSettings.DisplayFaultDescriptionChecked);
		showFaultCount = AppSettingHelper.GetSettingAsBool(ApplicationSettings.DisplayFaultCountChecked);
		showFaultStatus = AppSettingHelper.GetSettingAsBool(ApplicationSettings.DisplayFaultStatusChecked);
		showSourceAddr = AppSettingHelper.GetSettingAsBool(ApplicationSettings.DisplayFaultSourceAddrChecked);
		FaultDatabaseFilename = AppSettingHelper.GetSetting(ApplicationSettings.FaultDatabaseFilename);
		IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
		if (FaultDatabaseFilename == "NONE")
		{
			FaultDatabaseFilename = directoryService.RootDirectory + "\\FaultDB\\Service Fault Codes.xls";
		}
		try
		{
			MultimoduleMonitor = AppSettingHelper.GetSettingAsBool(ApplicationSettings.MultiModuleFaultMonitor);
		}
		catch (FormatException)
		{
		}
		try
		{
			FaultMonitoringRate = int.Parse(AppSettingHelper.GetSetting(ApplicationSettings.FaultMonitorRate));
		}
		catch (FormatException)
		{
		}
		RaiseFaultModelChangedEvent();
	}

	internal void RaiseFaultModelChangedEvent()
	{
		if (this.FaultModelChangedEvent != null)
		{
			this.FaultModelChangedEvent(this, EventArgs.Empty);
		}
	}

	protected void RaiseFaultMonitorRateChanged(FaultMonitorRateChangedEventArgs e)
	{
		if (this.FaultMonitorRateChanged != null)
		{
			this.FaultMonitorRateChanged(this, e);
		}
	}

	protected void RaiseCurrentDeviceSetChanged()
	{
		if (this.CurrentDeviceSetChanged != null)
		{
			this.CurrentDeviceSetChanged(this, EventArgs.Empty);
		}
	}

	protected void RaiseFaultDataBaseChangedEvent()
	{
		if (this.FaultDataBaseChangedEvent != null)
		{
			this.FaultDataBaseChangedEvent(this, EventArgs.Empty);
		}
	}

	public void RetrieveFaultCount(ref FaultCountInfo faultInfo)
	{
		faultInfo.FaultCount = -1;
		try
		{
			IAddressValue addressValue = AddressFactory.ProductAddressValue(faultInfo.SourceAddress);
			if (!faultComponent.Contains(addressValue) || DataSource.SystemSuspendMonitoring(addressValue) || !DataSource.GetCalibration(addressValue).Connected)
			{
				return;
			}
			CIFaultCodesClass cIFaultCodesClass = (CIFaultCodesClass)faultComponent[addressValue];
			if (cIFaultCodesClass == null)
			{
				return;
			}
			ICICollection iCICollection = cIFaultCodesClass.RetrieveFaults();
			CIFault cIFault = null;
			for (int i = 0; i < iCICollection.Count; i++)
			{
				cIFault = (CIFault)iCICollection[i];
				if (faultInfo.FaultCode == $"{cIFault.Code,4:D4}")
				{
					faultInfo.FaultCount = cIFault.Counts;
					break;
				}
			}
		}
		catch (Exception ex)
		{
			Trace.WriteLine("Exception in retrieving the fault count : " + ex.Message);
		}
	}

	public void ResetFaultComponent(ICalibrationECM calibrationECM)
	{
		ICIFaultCodes iCIFaultCodes = (ICIFaultCodes)faultComponent[calibrationECM.SourceAddress];
		if (iCIFaultCodes != null)
		{
			while (Marshal.ReleaseComObject(iCIFaultCodes) > 0)
			{
			}
			iCIFaultCodes = null;
		}
		faultComponent.Remove(calibrationECM.SourceAddress);
		if (dataSource == null)
		{
			return;
		}
		iCIFaultCodes = new CIFaultCodesClass();
		try
		{
			faultComponent.Add(calibrationECM.SourceAddress, null);
			if (calibrationECM.ECMRunLocation != RunLocationType.RomBoot)
			{
				iCIFaultCodes.DataSource = (ICICalDataServer)calibrationECM.CalibrationDataServer.DataServer;
				faultComponent[calibrationECM.SourceAddress] = iCIFaultCodes;
			}
		}
		catch (Exception ex)
		{
			if (iCIFaultCodes != null)
			{
				while (Marshal.ReleaseComObject(iCIFaultCodes) > 0)
				{
				}
				iCIFaultCodes = null;
			}
			string message = "Error has occurred when associating fault with SourceAddress: " + calibrationECM.SourceAddress.ToString() + " ";
			EventLogger.Error("FaultModel", message, ex.Message);
		}
	}
}
public struct FaultMonitorOptions
{
	public bool showDescription;

	public bool showSourceAddr;

	public bool showFaultCount;

	public bool showFaultStatus;

	public bool viewSmallIcons;
}
public delegate void FaultOptionChangedEventHandler(object sender, EventArgs e);
public class FaultMonitorPreferences : UserControl, IPropertyPage
{
	private Container components;

	private Panel FaultMonitorPanel;

	private GroupBox groupBox1;

	private Label FaultMonitorPreferencesLbl;

	private CheckBox ShowFaultDescriptioncheckBox;

	private CheckBox ShowFaultCountcheckBox;

	private GroupBox groupBox2;

	private Label FaultRatelabel;

	private CheckBox ShowSourceAddrrescheckBox;

	private string parentNode;

	private string currentNode;

	private CheckBox ShowFaultStatuscheckBox;

	private Label label1;

	private TrackBar FaultsTrackBar;

	private TextBox TrackBarTextBox;

	internal static int DefaultMaxFaultRate = 1800;

	internal static int DefaultMinFaultRate = 2;

	private GroupBox grpBoxMonitorOptions;

	private RadioButton radioBtnMonitorAllModules;

	private RadioButton radioBtnMonitorCurrentModule;

	private Label label2;

	private Button browseButton;

	private Label RecomendedLabel;

	private TextBox faultDatabaseFilename;

	public string FaultDatabaseFilename
	{
		get
		{
			return ((Control)faultDatabaseFilename).Text.Trim();
		}
		set
		{
			((Control)faultDatabaseFilename).Text = value;
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

	public event FaultOptionChangedEventHandler FaultOptionChanged;

	public FaultMonitorPreferences()
	{
		InitializeComponent();
	}

	public FaultMonitorPreferences(string parentNode, string currentNode)
	{
		InitializeComponent();
		this.parentNode = parentNode;
		this.currentNode = currentNode;
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
		//IL_006f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0079: Expected O, but got Unknown
		//IL_007a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0084: Expected O, but got Unknown
		//IL_0085: Unknown result type (might be due to invalid IL or missing references)
		//IL_008f: Expected O, but got Unknown
		//IL_0090: Unknown result type (might be due to invalid IL or missing references)
		//IL_009a: Expected O, but got Unknown
		//IL_009b: Unknown result type (might be due to invalid IL or missing references)
		//IL_00a5: Expected O, but got Unknown
		//IL_00a6: Unknown result type (might be due to invalid IL or missing references)
		//IL_00b0: Expected O, but got Unknown
		//IL_00b1: Unknown result type (might be due to invalid IL or missing references)
		//IL_00bb: Expected O, but got Unknown
		//IL_00bc: Unknown result type (might be due to invalid IL or missing references)
		//IL_00c6: Expected O, but got Unknown
		//IL_00c7: Unknown result type (might be due to invalid IL or missing references)
		//IL_00d1: Expected O, but got Unknown
		//IL_060a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0614: Expected O, but got Unknown
		FaultMonitorPanel = new Panel();
		RecomendedLabel = new Label();
		browseButton = new Button();
		faultDatabaseFilename = new TextBox();
		label2 = new Label();
		grpBoxMonitorOptions = new GroupBox();
		radioBtnMonitorCurrentModule = new RadioButton();
		radioBtnMonitorAllModules = new RadioButton();
		label1 = new Label();
		TrackBarTextBox = new TextBox();
		FaultsTrackBar = new TrackBar();
		FaultRatelabel = new Label();
		groupBox2 = new GroupBox();
		ShowFaultDescriptioncheckBox = new CheckBox();
		groupBox1 = new GroupBox();
		FaultMonitorPreferencesLbl = new Label();
		ShowFaultCountcheckBox = new CheckBox();
		ShowSourceAddrrescheckBox = new CheckBox();
		ShowFaultStatuscheckBox = new CheckBox();
		((Control)FaultMonitorPanel).SuspendLayout();
		((Control)grpBoxMonitorOptions).SuspendLayout();
		((ISupportInitialize)FaultsTrackBar).BeginInit();
		((Control)this).SuspendLayout();
		((Control)FaultMonitorPanel).Anchor = (AnchorStyles)15;
		((Control)FaultMonitorPanel).Controls.Add((Control)(object)RecomendedLabel);
		((Control)FaultMonitorPanel).Controls.Add((Control)(object)browseButton);
		((Control)FaultMonitorPanel).Controls.Add((Control)(object)faultDatabaseFilename);
		((Control)FaultMonitorPanel).Controls.Add((Control)(object)label2);
		((Control)FaultMonitorPanel).Controls.Add((Control)(object)grpBoxMonitorOptions);
		((Control)FaultMonitorPanel).Controls.Add((Control)(object)label1);
		((Control)FaultMonitorPanel).Controls.Add((Control)(object)TrackBarTextBox);
		((Control)FaultMonitorPanel).Controls.Add((Control)(object)FaultsTrackBar);
		((Control)FaultMonitorPanel).Controls.Add((Control)(object)FaultRatelabel);
		((Control)FaultMonitorPanel).Controls.Add((Control)(object)groupBox2);
		((Control)FaultMonitorPanel).Controls.Add((Control)(object)ShowFaultDescriptioncheckBox);
		((Control)FaultMonitorPanel).Controls.Add((Control)(object)groupBox1);
		((Control)FaultMonitorPanel).Controls.Add((Control)(object)FaultMonitorPreferencesLbl);
		((Control)FaultMonitorPanel).Controls.Add((Control)(object)ShowFaultCountcheckBox);
		((Control)FaultMonitorPanel).Controls.Add((Control)(object)ShowSourceAddrrescheckBox);
		((Control)FaultMonitorPanel).Controls.Add((Control)(object)ShowFaultStatuscheckBox);
		((Control)FaultMonitorPanel).Location = new Point(0, 0);
		((Control)FaultMonitorPanel).Name = "FaultMonitorPanel";
		((Control)FaultMonitorPanel).Size = new Size(392, 336);
		((Control)FaultMonitorPanel).TabIndex = 0;
		((Control)RecomendedLabel).Location = new Point(8, 280);
		((Control)RecomendedLabel).Name = "RecomendedLabel";
		((Control)RecomendedLabel).Size = new Size(384, 32);
		((Control)RecomendedLabel).TabIndex = 43;
		((Control)RecomendedLabel).Text = "Calterm III Default Fault monitoring rate : 30 seconds.\r\nMonitoring of faults may consume 100% of the datalink for up to 5 seconds.";
		((Control)browseButton).Location = new Point(352, 135);
		((Control)browseButton).Name = "browseButton";
		((Control)browseButton).Size = new Size(23, 24);
		((Control)browseButton).TabIndex = 42;
		((Control)browseButton).Text = "...";
		((Control)browseButton).Click += OpenDatabaseFile;
		((Control)faultDatabaseFilename).Location = new Point(104, 137);
		((Control)faultDatabaseFilename).Name = "faultDatabaseFilename";
		((Control)faultDatabaseFilename).Size = new Size(248, 20);
		((Control)faultDatabaseFilename).TabIndex = 41;
		((Control)label2).Location = new Point(19, 139);
		((Control)label2).Name = "label2";
		((Control)label2).Size = new Size(88, 16);
		((Control)label2).TabIndex = 40;
		((Control)label2).Text = "Fault Database:";
		((Control)grpBoxMonitorOptions).Controls.Add((Control)(object)radioBtnMonitorCurrentModule);
		((Control)grpBoxMonitorOptions).Controls.Add((Control)(object)radioBtnMonitorAllModules);
		((Control)grpBoxMonitorOptions).Location = new Point(184, 24);
		((Control)grpBoxMonitorOptions).Name = "grpBoxMonitorOptions";
		((Control)grpBoxMonitorOptions).Size = new Size(192, 100);
		((Control)grpBoxMonitorOptions).TabIndex = 39;
		grpBoxMonitorOptions.TabStop = false;
		((Control)grpBoxMonitorOptions).Text = "Monitor options";
		((Control)radioBtnMonitorCurrentModule).Location = new Point(24, 56);
		((Control)radioBtnMonitorCurrentModule).Name = "radioBtnMonitorCurrentModule";
		((Control)radioBtnMonitorCurrentModule).Size = new Size(160, 24);
		((Control)radioBtnMonitorCurrentModule).TabIndex = 1;
		((Control)radioBtnMonitorCurrentModule).Text = "Monitor the current module";
		((Control)radioBtnMonitorAllModules).Location = new Point(24, 24);
		((Control)radioBtnMonitorAllModules).Name = "radioBtnMonitorAllModules";
		((Control)radioBtnMonitorAllModules).Size = new Size(120, 24);
		((Control)radioBtnMonitorAllModules).TabIndex = 0;
		((Control)radioBtnMonitorAllModules).Text = "Monitor all modules";
		((Control)label1).Location = new Point(182, 248);
		((Control)label1).Name = "label1";
		((Control)label1).Size = new Size(119, 18);
		((Control)label1).TabIndex = 31;
		((Control)label1).Text = "Seconds/Time Interval";
		((Control)TrackBarTextBox).Location = new Point(122, 248);
		((Control)TrackBarTextBox).Name = "TrackBarTextBox";
		((Control)TrackBarTextBox).Size = new Size(51, 20);
		((Control)TrackBarTextBox).TabIndex = 38;
		((Control)TrackBarTextBox).KeyPress += new KeyPressEventHandler(TrackBarTextBox_KeyPress);
		((Control)TrackBarTextBox).Leave += TrackBarTextBoxLeave;
		((Control)FaultsTrackBar).Location = new Point(39, 200);
		FaultsTrackBar.Maximum = 1800;
		FaultsTrackBar.Minimum = 2;
		((Control)FaultsTrackBar).Name = "FaultsTrackBar";
		((Control)FaultsTrackBar).Size = new Size(326, 45);
		((Control)FaultsTrackBar).TabIndex = 37;
		FaultsTrackBar.Value = 5;
		FaultsTrackBar.Scroll += TrackBarScroll;
		((Control)FaultRatelabel).Location = new Point(19, 168);
		((Control)FaultRatelabel).Name = "FaultRatelabel";
		((Control)FaultRatelabel).Size = new Size(92, 15);
		((Control)FaultRatelabel).TabIndex = 26;
		((Control)FaultRatelabel).Text = "Fault Frequency";
		((Control)groupBox2).Anchor = (AnchorStyles)13;
		((Control)groupBox2).Location = new Point(137, 176);
		((Control)groupBox2).Name = "groupBox2";
		((Control)groupBox2).Size = new Size(247, 4);
		((Control)groupBox2).TabIndex = 23;
		groupBox2.TabStop = false;
		((Control)ShowFaultDescriptioncheckBox).Location = new Point(24, 32);
		((Control)ShowFaultDescriptioncheckBox).Name = "ShowFaultDescriptioncheckBox";
		((Control)ShowFaultDescriptioncheckBox).Size = new Size(154, 24);
		((Control)ShowFaultDescriptioncheckBox).TabIndex = 21;
		((Control)ShowFaultDescriptioncheckBox).Text = "Show Fault Description";
		((Control)groupBox1).Anchor = (AnchorStyles)13;
		((Control)groupBox1).Location = new Point(143, 16);
		((Control)groupBox1).Name = "groupBox1";
		((Control)groupBox1).Size = new Size(240, 4);
		((Control)groupBox1).TabIndex = 19;
		groupBox1.TabStop = false;
		((Control)FaultMonitorPreferencesLbl).Location = new Point(8, 8);
		((Control)FaultMonitorPreferencesLbl).Name = "FaultMonitorPreferencesLbl";
		((Control)FaultMonitorPreferencesLbl).Size = new Size(141, 17);
		((Control)FaultMonitorPreferencesLbl).TabIndex = 18;
		((Control)FaultMonitorPreferencesLbl).Text = "Fault Monitor Preferences";
		((Control)ShowFaultCountcheckBox).Location = new Point(24, 80);
		((Control)ShowFaultCountcheckBox).Name = "ShowFaultCountcheckBox";
		((Control)ShowFaultCountcheckBox).Size = new Size(113, 24);
		((Control)ShowFaultCountcheckBox).TabIndex = 22;
		((Control)ShowFaultCountcheckBox).Text = "Show Fault Count";
		((Control)ShowSourceAddrrescheckBox).Location = new Point(24, 56);
		((Control)ShowSourceAddrrescheckBox).Name = "ShowSourceAddrrescheckBox";
		((Control)ShowSourceAddrrescheckBox).Size = new Size(141, 24);
		((Control)ShowSourceAddrrescheckBox).TabIndex = 21;
		((Control)ShowSourceAddrrescheckBox).Text = "Show Device Address";
		((Control)ShowFaultStatuscheckBox).Location = new Point(24, 104);
		((Control)ShowFaultStatuscheckBox).Name = "ShowFaultStatuscheckBox";
		((Control)ShowFaultStatuscheckBox).Size = new Size(132, 24);
		((Control)ShowFaultStatuscheckBox).TabIndex = 22;
		((Control)ShowFaultStatuscheckBox).Text = "Show Fault Status";
		((Control)this).Controls.Add((Control)(object)FaultMonitorPanel);
		((Control)this).Name = "FaultMonitorPreferences";
		((Control)this).Size = new Size(392, 336);
		((Control)FaultMonitorPanel).ResumeLayout(false);
		((Control)FaultMonitorPanel).PerformLayout();
		((Control)grpBoxMonitorOptions).ResumeLayout(false);
		((ISupportInitialize)FaultsTrackBar).EndInit();
		((Control)this).ResumeLayout(false);
	}

	public void Initialize()
	{
	}

	public void Initialize(FaultMonitorController controller, FaultMonitorModel model)
	{
		ShowFaultDescriptioncheckBox.Checked = model.ShowDescription;
		ShowFaultCountcheckBox.Checked = model.ShowFaultCount;
		ShowFaultStatuscheckBox.Checked = model.ShowFaultStatus;
		ShowSourceAddrrescheckBox.Checked = model.ShowSourceAddr;
		FaultDatabaseFilename = model.FaultDatabaseFilename;
		if (model.MultimoduleMonitor)
		{
			radioBtnMonitorAllModules.Checked = true;
			radioBtnMonitorCurrentModule.Checked = false;
		}
		else
		{
			radioBtnMonitorAllModules.Checked = false;
			radioBtnMonitorCurrentModule.Checked = true;
		}
		FaultsTrackBar.Value = controller.FaultModel.FaultMonitoringRate;
		((Control)TrackBarTextBox).Text = FaultsTrackBar.Value.ToString();
	}

	public void SetOptions()
	{
		AppSettingHelper.ChangeSetting(ApplicationSettings.DisplayFaultDescriptionChecked, ShowFaultDescriptioncheckBox.Checked.ToString());
		AppSettingHelper.ChangeSetting(ApplicationSettings.DisplayFaultCountChecked, ShowFaultCountcheckBox.Checked.ToString());
		AppSettingHelper.ChangeSetting(ApplicationSettings.DisplayFaultStatusChecked, ShowFaultStatuscheckBox.Checked.ToString());
		AppSettingHelper.ChangeSetting(ApplicationSettings.DisplayFaultSourceAddrChecked, ShowSourceAddrrescheckBox.Checked.ToString());
		AppSettingHelper.ChangeSetting(ApplicationSettings.FaultMonitorRate, ((Control)TrackBarTextBox).Text);
		AppSettingHelper.ChangeSetting(ApplicationSettings.FaultDatabaseFilename, FaultDatabaseFilename);
		if (radioBtnMonitorAllModules.Checked)
		{
			AppSettingHelper.ChangeSetting(ApplicationSettings.MultiModuleFaultMonitor, "True");
		}
		else
		{
			AppSettingHelper.ChangeSetting(ApplicationSettings.MultiModuleFaultMonitor, "False");
		}
		OnFaultOptionChanged(this, EventArgs.Empty);
	}

	public void OnFaultOptionChanged(object sender, EventArgs e)
	{
		if (this.FaultOptionChanged != null)
		{
			this.FaultOptionChanged(sender, e);
		}
	}

	private void TrackBarTextBoxLeave(object sender, EventArgs e)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		TextBox val = (TextBox)sender;
		if (string.Empty == ((Control)val).Text)
		{
			((Control)val).Text = Convert.ToString(DefaultMinFaultRate, 10);
			FaultsTrackBar.Value = DefaultMinFaultRate;
		}
		else if (Convert.ToInt32(((Control)val).Text) > DefaultMaxFaultRate)
		{
			FaultsTrackBar.Value = DefaultMaxFaultRate;
			((Control)val).Text = Convert.ToString(DefaultMaxFaultRate, 10);
		}
		else if (Convert.ToInt32(((Control)val).Text) < DefaultMinFaultRate)
		{
			FaultsTrackBar.Value = DefaultMinFaultRate;
			((Control)val).Text = Convert.ToString(DefaultMinFaultRate, 10);
		}
		FaultsTrackBar.Value = Convert.ToInt32(((Control)val).Text);
	}

	private void TrackBarScroll(object sender, EventArgs e)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		TrackBar val = (TrackBar)sender;
		FaultsTrackBar.Value = val.Value;
		((Control)TrackBarTextBox).Text = FaultsTrackBar.Value.ToString();
	}

	private void TrackBarTextBox_KeyPress(object sender, KeyPressEventArgs e)
	{
		int keyChar = e.KeyChar;
		if (!char.IsDigit(e.KeyChar) && keyChar != 8)
		{
			e.Handled = true;
		}
	}

	private void OpenDatabaseFile(object sender, EventArgs e)
	{
		//IL_0024: Unknown result type (might be due to invalid IL or missing references)
		//IL_002a: Invalid comparison between Unknown and I4
		SafeOpenFileDialog safeOpenFileDialog = new SafeOpenFileDialog();
		safeOpenFileDialog.Filter = "Access Database Files (*.xls)|*.xls";
		safeOpenFileDialog.Title = "Select a fault database file";
		safeOpenFileDialog.RestoreDirectory = true;
		if ((int)safeOpenFileDialog.ShowDialog() == 1)
		{
			FaultDatabaseFilename = safeOpenFileDialog.FileName;
		}
	}
}
public class FaultMonitorView : UserControl
{
	private delegate void AddFaultsEventHandler(string code, string status);

	private Label Title;

	private FaultMonitorModel faultModel;

	private Timer blinkingTimer;

	private ListView faultList;

	private bool revertColor;

	private IContainer components;

	private Label faultBlockLabel;

	private FaultMonitorMenu faultMenu;

	private Font normalFont;

	private Font boldFont;

	private bool autoLogging;

	private SortedList deviceList;

	private BalloonToolTip balloonToolTip;

	public FaultMonitorModel FaultModel
	{
		get
		{
			return faultModel;
		}
		set
		{
			faultModel = value;
		}
	}

	internal bool BlinkingFaults
	{
		get
		{
			return blinkingTimer.Enabled;
		}
		set
		{
			blinkingTimer.Enabled = value;
			if (blinkingTimer.Enabled)
			{
				return;
			}
			try
			{
				for (int i = 0; i < faultList.Items.Count; i++)
				{
					if (faultList.Items[i] == null)
					{
						continue;
					}
					string text = faultList.Items[i].Text;
					if (!string.IsNullOrEmpty(text))
					{
						if (faultModel.GetFaultStatus(text) == FaultStatus.Active.ToString())
						{
							faultList.Items[i].ForeColor = SystemColors.GrayText;
							faultList.Items[i].Font = boldFont;
						}
						else
						{
							faultList.Items[i].ForeColor = SystemColors.GrayText;
							faultList.Items[i].Font = normalFont;
						}
					}
				}
			}
			catch
			{
			}
		}
	}

	public int BlinkingInterval
	{
		get
		{
			return blinkingTimer.Interval;
		}
		set
		{
			blinkingTimer.Interval = value;
		}
	}

	public string FaultBlockLabel
	{
		get
		{
			return ((Control)faultBlockLabel).Text;
		}
		set
		{
			((Control)faultBlockLabel).Text = value;
		}
	}

	public ListView FaultList => faultList;

	public Color FaultBlockColor
	{
		get
		{
			return ((Control)faultBlockLabel).ForeColor;
		}
		set
		{
			((Control)faultBlockLabel).ForeColor = value;
		}
	}

	public FaultMonitorMenu FaultMenu => faultMenu;

	private BalloonToolTip BalloonToolTip
	{
		get
		{
			if (balloonToolTip == null)
			{
				balloonToolTip = new BalloonToolTip();
				balloonToolTip.CreateToolTip();
				balloonToolTip.Icon = BalloonToolTip.TooltipIcon.Info;
				balloonToolTip.Title = "Fault codes have changed";
				balloonToolTip.TipText = " ";
				balloonToolTip.VisibleTime = 5000;
				balloonToolTip.Offset = new Point(0, -25);
				balloonToolTip.Alignment = BalloonToolTip.BalloonAlignment.BottomRight;
			}
			return balloonToolTip;
		}
	}

	public FaultMonitorView()
	{
		InitializeComponent();
		faultModel = new FaultMonitorModel();
		deviceList = new SortedList();
		faultList.OwnerDraw = false;
		((UserControl)this).Load += OnFaultMonitorViewLoad;
		IAppConfigService appConfigService = ServiceManager.Services.GetService(typeof(IAppConfigService)) as IAppConfigService;
		autoLogging = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoLoggingChecked));
	}

	public FaultMonitorView(FaultMonitorModel model)
	{
		InitializeComponent();
		faultModel = model;
		IAppConfigService appConfigService = ServiceManager.Services.GetService(typeof(IAppConfigService)) as IAppConfigService;
		autoLogging = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AutoLoggingChecked));
		Initialize();
	}

	internal void Initialize()
	{
		//IL_009a: Unknown result type (might be due to invalid IL or missing references)
		//IL_00a4: Expected O, but got Unknown
		//IL_00b2: Unknown result type (might be due to invalid IL or missing references)
		//IL_00bc: Expected O, but got Unknown
		revertColor = true;
		BlinkingFaults = true;
		try
		{
			faultMenu = new FaultMonitorMenu(faultModel);
			((Control)faultList).ContextMenu = (ContextMenu)(object)faultMenu;
			faultModel.FaultItemChangedEvent += OnFaultIntemChanged;
			faultModel.FaultItemRemovedEvent += OnFaultItemRemoved;
			faultModel.ReloadFaultViewEvent += OnReloadFaultView;
			faultModel.FaultDataBaseChangedEvent += OnFaultDataBaseChangedEvent;
			normalFont = new Font("Arial", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
			boldFont = new Font("Arial", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		}
		catch (Exception ex)
		{
			EventLogger.Error("FaultView", ex.Message);
			throw new Exception(ex.Message);
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
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0016: Expected O, but got Unknown
		//IL_001d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0027: Expected O, but got Unknown
		//IL_0028: Unknown result type (might be due to invalid IL or missing references)
		//IL_0032: Expected O, but got Unknown
		//IL_0033: Unknown result type (might be due to invalid IL or missing references)
		//IL_003d: Expected O, but got Unknown
		//IL_012c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0136: Expected O, but got Unknown
		//IL_0219: Unknown result type (might be due to invalid IL or missing references)
		//IL_0223: Expected O, but got Unknown
		components = new Container();
		Title = new Label();
		blinkingTimer = new Timer(components);
		faultList = new ListView();
		faultBlockLabel = new Label();
		((Control)this).SuspendLayout();
		((Control)Title).BackColor = SystemColors.ActiveCaption;
		((Control)Title).Dock = (DockStyle)1;
		((Control)Title).ForeColor = SystemColors.ActiveCaptionText;
		((Control)Title).Location = new Point(0, 0);
		((Control)Title).Name = "Title";
		((Control)Title).Size = new Size(160, 20);
		((Control)Title).TabIndex = 1;
		((Control)Title).Text = "Faults";
		Title.TextAlign = (ContentAlignment)16;
		blinkingTimer.Interval = 1000;
		blinkingTimer.Tick += blinkingTimer_Tick;
		faultList.Alignment = (ListViewAlignment)5;
		faultList.BorderStyle = (BorderStyle)0;
		((Control)faultList).Dock = (DockStyle)5;
		((Control)faultList).Font = new Font("Tahoma", 8f);
		((Control)faultList).Location = new Point(0, 20);
		((Control)faultList).Name = "faultList";
		faultList.OwnerDraw = true;
		faultList.ShowItemToolTips = true;
		((Control)faultList).Size = new Size(160, 156);
		faultList.Sorting = (SortOrder)1;
		((Control)faultList).TabIndex = 1;
		faultList.UseCompatibleStateImageBehavior = false;
		faultList.View = (View)3;
		faultList.ItemActivate += faultList_ItemActivate;
		faultList.SelectedIndexChanged += OnSelectedIndexChanged;
		((Control)faultBlockLabel).Anchor = (AnchorStyles)9;
		((Control)faultBlockLabel).BackColor = SystemColors.ActiveCaption;
		((Control)faultBlockLabel).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
		((Control)faultBlockLabel).ForeColor = SystemColors.ActiveCaption;
		((Control)faultBlockLabel).Location = new Point(72, 3);
		((Control)faultBlockLabel).Name = "faultBlockLabel";
		((Control)faultBlockLabel).Size = new Size(80, 14);
		((Control)faultBlockLabel).TabIndex = 4;
		faultBlockLabel.TextAlign = (ContentAlignment)32;
		((Control)this).Controls.Add((Control)(object)faultBlockLabel);
		((Control)this).Controls.Add((Control)(object)faultList);
		((Control)this).Controls.Add((Control)(object)Title);
		((Control)this).Name = "FaultMonitorView";
		((Control)this).Size = new Size(160, 176);
		((Control)this).ResumeLayout(false);
	}

	internal void OnFaultIntemChanged(object sender, FaultItemChangedEventArgs eArgs)
	{
		if (!((Control)this).InvokeRequired)
		{
			addFault(eArgs.sourceAddress + ":" + eArgs.faultCode, eArgs.status.ToString());
			return;
		}
		((Control)this).BeginInvoke((Delegate)new AddFaultsEventHandler(addFault), new object[2]
		{
			eArgs.sourceAddress + ":" + eArgs.faultCode,
			eArgs.status.ToString()
		});
	}

	internal void OnFaultItemRemoved(object sender, FaultItemChangedEventArgs eArgs)
	{
		if (!((Control)this).InvokeRequired)
		{
			RemoveFault(eArgs.sourceAddress + ":" + eArgs.faultCode);
			return;
		}
		((Control)this).BeginInvoke((Delegate)new FaultItemChangedEventHandler(OnFaultItemRemoved), new object[2] { sender, eArgs });
	}

	private void RemoveFault(string code)
	{
		ListViewItem val = null;
		int count = faultList.Items.Count;
		for (int i = 0; i < count; i++)
		{
			if (code == faultList.Items[i].SubItems[0].Text)
			{
				val = faultList.Items[i];
				break;
			}
		}
		if (val != null)
		{
			faultList.Items.Remove(val);
			((Control)faultList).Invalidate();
		}
	}

	private void addFault(string code, string status)
	{
		//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
		//IL_00b1: Expected O, but got Unknown
		//IL_00b4: Unknown result type (might be due to invalid IL or missing references)
		//IL_00bb: Expected O, but got Unknown
		//IL_00dc: Unknown result type (might be due to invalid IL or missing references)
		//IL_00e6: Expected O, but got Unknown
		//IL_0111: Unknown result type (might be due to invalid IL or missing references)
		//IL_011b: Expected O, but got Unknown
		try
		{
			Color window = SystemColors.Window;
			Color color = ((!(status == "Active")) ? SystemColors.WindowText : ((!autoLogging) ? SystemColors.HighlightText : SystemColors.ControlDark));
			if (FaultModel.ShowHexCode)
			{
				string text = code.Substring(0, code.IndexOf(":") + 1);
				string s = code.Substring(code.IndexOf(":") + 1);
				int num = int.Parse(s, NumberStyles.Integer);
				code = text + "0x";
				code += $"{num,4:X4}";
			}
			ListViewItem val = new ListViewItem((ListViewSubItem[])(object)new ListViewSubItem[1]
			{
				new ListViewSubItem((ListViewItem)null, code, color, window, normalFont)
			}, -1);
			val.ToolTipText = GenerateToolTip(val.Text);
			faultList.DrawItem -= new DrawListViewItemEventHandler(faultList_DrawItem);
			faultList.Items.Add(val);
			((Control)faultList).Invalidate();
			faultList.DrawItem += new DrawListViewItemEventHandler(faultList_DrawItem);
			if (!((Control)this).Visible)
			{
				BalloonToolTip.Show();
			}
		}
		catch (Exception)
		{
		}
	}

	private void OnFaultDataBaseChangedEvent(object sender, EventArgs e)
	{
		//IL_0019: Unknown result type (might be due to invalid IL or missing references)
		//IL_001f: Expected O, but got Unknown
		foreach (ListViewItem item in faultList.Items)
		{
			ListViewItem val = item;
			if (val != null)
			{
				val.ToolTipText = GenerateToolTip(val.Text);
			}
		}
	}

	private void OnFaultMonitorViewLoad(object sender, EventArgs e)
	{
		faultList.OwnerDraw = true;
	}

	internal void OnReloadFaultView(object sender, FaultsUpdateEventArgs eArgs)
	{
		if (eArgs != null)
		{
			faultList.Clear();
			DataTable faultDataTable = eArgs.faultDataTable;
			int num = 0;
			foreach (DataRow row in faultDataTable.Rows)
			{
				if (!(bool)row["BlockingStatus"])
				{
					string code = (string)row["SourceAddress"] + ":" + (string)row["FaultCode"];
					try
					{
						addFault(code, (string)row["CurrentStatus"]);
					}
					catch (Exception ex)
					{
						Trace.WriteLine(ex.Message + Environment.NewLine + ex.StackTrace, "FaultMonitorView.OnReloadFaultView");
						_ = string.Empty;
					}
				}
				else
				{
					num++;
				}
			}
			if (num > 0)
			{
				FaultBlockLabel = num + " Blocked";
				FaultBlockColor = Color.Yellow;
				FaultMenu.SetFaultMenuItemEnableStatus(menuOptions.UnblockFaults, status: true);
				FaultMenu.SetFaultMenuItemEnableStatus(menuOptions.ViewBlockedFaults, status: true);
			}
			else
			{
				FaultMenu.SetFaultMenuItemEnableStatus(menuOptions.UnblockFaults, status: false);
				FaultMenu.SetFaultMenuItemEnableStatus(menuOptions.ViewBlockedFaults, status: false);
			}
			FaultMenu.SetFaultMenuItemEnableStatus(menuOptions.BlockSelectedFaults, status: false);
			faultModel.CanBlockFault = false;
		}
		((Control)this).Invalidate();
	}

	private void blinkingTimer_Tick(object sender, EventArgs e)
	{
		try
		{
			revertColor = !revertColor;
			for (int i = 0; i < faultList.Items.Count; i++)
			{
				if (faultList.Items[i] == null)
				{
					continue;
				}
				string text = faultList.Items[i].Text;
				if (string.IsNullOrEmpty(text))
				{
					continue;
				}
				if (faultModel.GetFaultStatus(text) == FaultStatus.Active.ToString())
				{
					if (revertColor)
					{
						faultList.Items[i].ForeColor = SystemColors.WindowText;
						faultList.Items[i].Font = normalFont;
					}
					else
					{
						faultList.Items[i].ForeColor = SystemColors.WindowText;
						faultList.Items[i].Font = boldFont;
					}
				}
				else
				{
					faultList.Items[i].ForeColor = SystemColors.WindowText;
					faultList.Items[i].Font = normalFont;
				}
			}
		}
		catch
		{
		}
	}

	public void ViewHexCodes()
	{
		try
		{
			for (int i = 0; i < faultList.Items.Count; i++)
			{
				string text = "";
				string text2 = faultList.Items[i].Text;
				_ = text2.Length;
				string text3 = text2.Substring(0, text2.IndexOf(":") + 1);
				text2 = text2.Remove(0, text2.IndexOf(":") + 1);
				if (FaultModel.ShowHexCode)
				{
					int num = int.Parse(text2, NumberStyles.Integer);
					text = "0x";
					text += $"{num,4:X4}";
				}
				else
				{
					if (text2.IndexOf("x") != -1)
					{
						text2 = text2.Remove(0, text2.IndexOf("x") + 1);
					}
					int num2 = int.Parse(text2, NumberStyles.AllowHexSpecifier);
					text = $"{num2,4:D4}";
				}
				if (!text.StartsWith(text3))
				{
					text = text3 + text;
				}
				faultList.Items[i].ToolTipText = faultList.Items[i].ToolTipText.Replace(text2, text.Replace(text3, string.Empty).Replace("0x", string.Empty));
				faultList.Items[i].Text = text;
			}
		}
		catch
		{
		}
	}

	internal void OnFaultModelChanged(object sender, EventArgs e)
	{
		faultMenu.SetMenuItemStatus();
	}

	private void faultList_ItemActivate(object sender, EventArgs e)
	{
		string text = faultList.SelectedItems[0].Text;
		string text2 = text.Substring(0, text.IndexOf(":"));
		string text3 = text.Substring(text.IndexOf(":") + 1, text.Length - text.IndexOf(":") - 1);
		if (FaultModel.ShowFaultCount)
		{
			string message = $"Fault monitor is retrieving the fault information for fault {text3} from device address {text2}, please be patient for a while.";
			EventLogger.Info("Fault Monitor", message);
			FaultCountInfo faultCountInfo = new FaultCountInfo(text3, text2);
			RetrieveFaultCountDelegate retrieveFaultCountDelegate = FaultModel.RetrieveFaultCount;
			retrieveFaultCountDelegate.BeginInvoke(ref faultCountInfo, ViewFaultCountInfo, faultCountInfo);
		}
		else
		{
			DisplayFaultInfo(text, -1);
		}
	}

	private void ViewFaultCountInfo(IAsyncResult ar)
	{
		if (!((Control)this).InvokeRequired)
		{
			FaultCountInfo faultCountInfo = (FaultCountInfo)ar.AsyncState;
			DisplayFaultInfo(faultCountInfo.SourceAddress + ":" + faultCountInfo.FaultCode, faultCountInfo.FaultCount);
		}
		else
		{
			((Control)this).BeginInvoke((Delegate)new AsyncCallback(ViewFaultCountInfo), new object[1] { ar });
		}
	}

	private string FormatText(string text, int width, string padding)
	{
		for (int i = width; i < text.Length; i += width)
		{
			int num = text.IndexOf(" ", i);
			if (num != -1)
			{
				text = text.Remove(num, 1);
				text = text.Insert(num, "\n" + padding);
				i = num;
			}
		}
		return text;
	}

	private string GetProductId(IAddressValue address)
	{
		string text = "";
		if (!deviceList.ContainsKey(address))
		{
			ICalibrationOnline calibration = faultModel.DataSource.GetCalibration(address);
			text = calibration.ProductID;
			deviceList.Add(address, text);
		}
		else
		{
			text = deviceList[address].ToString();
		}
		return text;
	}

	internal ArrayList GetSelectedFaultList()
	{
		//IL_0032: Unknown result type (might be due to invalid IL or missing references)
		//IL_0038: Expected O, but got Unknown
		ArrayList arrayList = new ArrayList();
		if (faultList.SelectedItems.Count > 0)
		{
			foreach (ListViewItem selectedItem in faultList.SelectedItems)
			{
				ListViewItem val = selectedItem;
				arrayList.Add(val.Text);
			}
		}
		return arrayList;
	}

	private void OnSelectedIndexChanged(object sender, EventArgs e)
	{
		bool flag = faultList.SelectedItems.Count > 0;
		FaultMenu.SetFaultMenuItemEnableStatus(menuOptions.BlockSelectedFaults, flag);
		faultModel.CanBlockFault = flag;
	}

	private void DisplayFaultInfo(string faultSource, int faultCount)
	{
		//IL_01a0: Unknown result type (might be due to invalid IL or missing references)
		string text = faultSource.Substring(0, faultSource.IndexOf(":"));
		IAddressValue address = AddressFactory.ProductAddressValue(text);
		string text2 = faultSource.Substring(faultSource.IndexOf(":") + 1, faultSource.Length - faultSource.IndexOf(":") - 1);
		string text3 = "Device Address: " + text + "\n";
		try
		{
			if (!faultModel.ShowFaultCount && !faultModel.ShowFaultStatus)
			{
				return;
			}
			text3 = text3 + "Fault Status: " + faultModel.GetFaultStatus(faultSource) + "\n";
			if (faultModel.ShowFaultCount)
			{
				string text4 = faultCount.ToString();
				if (-1 == faultCount)
				{
					text4 = "Not available";
				}
				text3 = text3 + "Fault Count: " + text4 + "\n";
			}
			if (faultModel.ShowDescription)
			{
				faultModel.FaultDatabaseData.GetFaultCodeData(GetProductId(address), int.Parse(text2), out var result);
				string text5 = text3;
				text3 = text5 + "Fault Description: \n  PID: " + result.PID + ", SID: " + result.SID + "\n  SPN: " + result.SPN + ", Lamp: " + result.lampColor + "\n  Description: " + FormatText("\n      " + result.description, 50, "      ");
			}
			MessageBox.Show(text3, "Information for fault code " + text2, (MessageBoxButtons)0, (MessageBoxIcon)64);
		}
		catch (Exception ex)
		{
			Trace.WriteLine(ex.Message + Environment.NewLine + ex.StackTrace, "FaultMonitorView.OnReloadFaultView");
		}
	}

	private string GenerateToolTip(string faultCode)
	{
		string text = string.Empty;
		try
		{
			IAddressValue addressValue = AddressFactory.ProductAddressValue(faultCode.Substring(0, faultCode.IndexOf(":")));
			if (faultModel.DataSource.GetCalibration(addressValue).Connected && faultCode != null && string.Empty != faultCode)
			{
				int num = 0;
				if (FaultModel.ShowHexCode)
				{
					faultCode = faultCode.Remove(0, faultCode.IndexOf("x") + 1);
					num = int.Parse(faultCode, NumberStyles.AllowHexSpecifier);
					text = $"{num:D}";
				}
				else
				{
					faultCode = faultCode.Substring(faultCode.IndexOf(":") + 1, faultCode.Length - faultCode.IndexOf(":") - 1);
					num = int.Parse(faultCode);
					text = faultCode;
				}
				faultModel.FaultDatabaseData.GetFaultCodeData(GetProductId(addressValue), num, out var result);
				text = FormatText(text + ": " + result.description, 30, string.Empty);
			}
		}
		catch (Exception)
		{
		}
		return text;
	}

	private void faultList_DrawItem(object sender, DrawListViewItemEventArgs e)
	{
		try
		{
			bool flag = false;
			if (faultModel.GetFaultStatus(e.Item.Text) == FaultStatus.Active.ToString() && !revertColor)
			{
				flag = true;
			}
			if (flag)
			{
				e.Item.Font = boldFont;
			}
			else
			{
				e.Item.Font = normalFont;
			}
			e.DrawText((TextFormatFlags)0);
		}
		catch
		{
		}
	}
}
public class FaultsUpdateEventArgs : EventArgs
{
	public DataTable faultDataTable;

	public FaultsUpdateEventArgs(DataTable faultDataTable)
	{
		this.faultDataTable = faultDataTable;
	}
}
public class FaultMonitorRateChangedEventArgs : EventArgs
{
	public int OldValue;

	public int NewValue;

	public FaultMonitorRateChangedEventArgs(int oldValue, int newValue)
	{
		OldValue = oldValue;
		NewValue = newValue;
	}
}
public class FaultCountInfo
{
	private string faultCode;

	private int faultCount;

	private string sourceAddress;

	public string FaultCode => faultCode;

	public string SourceAddress => sourceAddress;

	public int FaultCount
	{
		get
		{
			return faultCount;
		}
		set
		{
			faultCount = value;
		}
	}

	public FaultCountInfo(string faultCode, string sourceAddress)
	{
		this.faultCode = faultCode;
		this.sourceAddress = sourceAddress;
	}
}
