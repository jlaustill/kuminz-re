using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
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
using System.Threading;
using System.Windows.Forms;
using C1.Win.C1FlexGrid;
using Cummins.AddressRepresentation;
using Cummins.Calibration;
using Cummins.MessageDialog;
using Cummins.ParameterSelector.Properties;
using Cummins.Services;
using Cummins.Widgets;
using PCLWrapper;

[assembly: AssemblyProduct("Calterm III - Parameter Selectror")]
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
namespace Cummins.ParameterSelector
{
	public class BroadcastParameterDialog : Form
	{
		protected const int ParameterNameColumnNumber = 1;

		protected const int SrcAddrViewParamCommentColNumber = 2;

		protected const int PGNViewParamCommentColNumber = 3;

		protected const int SrcAddrColNumber = 2;

		protected const int PGNColNumber = 3;

		protected const int ParamViewParamCommentColNumber = 4;

		protected const string SrcAddrNodeCaption = "SourceAddress";

		protected const string CommentNodeCaption = "Comments";

		protected const string AllParametersNodeCaption = "All Parameters";

		protected const string PGNNodeCaption = "PGN";

		private const string ComplexScreenCaption = "Complex";

		protected const int PGNHeadSpace = 1;

		internal const string MenuItemCopy = "Copy";

		private int rowIndex = 1;

		public DataTable screenTable;

		private int maxParameterCount;

		protected IParameterListInfo parameterList;

		private bool shouldClose;

		protected IAppConfigService appConfigService;

		protected string queryString = string.Empty;

		protected string cbfFileName;

		private ICalibrationOnline calibrationOnline;

		private WaitDlg _WaitDlg;

		private IContainer components;

		private PublicDataParameterListInfo _publicDataParameterListInfo;

		protected BroadcastParameterSortType currentSortType = BroadcastParameterSortType.SourceAddress;

		protected ParameterListViewData _parameterListViewData = new ParameterListViewData();

		protected IAddressValue deviceAddress;

		protected int treeViewSrcAddrParameterNameColWidth = 209;

		protected int treeViewSrcAddrCommentColWidth = 209;

		protected int treeViewPGNParameterNameColWidth = 180;

		protected int treeViewSrcAddrColWidth = 58;

		protected int treeViewPGNCommentColWidth = 180;

		protected int listViewParameterNameColWidth = 159;

		protected int listViewPGNNameColWidth = 50;

		protected int listViewSrcAddrColWidth = 50;

		protected int listViewParameterCommentColWidth = 159;

		private ContextMenu csmMenu;

		protected ICalibrationOnline calibration;

		private GroupBox groupBox1;

		private Button btnClearSearchResults;

		private Button btnSearch;

		private ComboBox cmbBoxQuerySring;

		private CheckBox chkSearchComments;

		private Label labelQueryString;

		private GroupBox groupBox2;

		private Button btnUnSelectAll;

		private PictureBox picBoxCollapseAll;

		private PictureBox picBoxExpandAll;

		private ComboBox cmbBoxSortBy;

		private Label label1;

		protected C1FlexGrid broadcastParametersTreeView;

		private ToolTip createToolTip;

		private Button btnRefresh;

		private bool handledByEnter;

		private Label label2;

		private Label lblScreens;

		private Button btnApply;

		private Button btnClose;

		private CheckBox chkBoxAppend;

		private ComboBox cmbBoxAvailableScreens;

		private Timer waitTimer;

		public bool ShouldClose
		{
			get
			{
				return shouldClose;
			}
			set
			{
				shouldClose = value;
			}
		}

		protected virtual BroadcastParameterSortType CurrentSortType
		{
			get
			{
				return currentSortType;
			}
			set
			{
				if (value != currentSortType)
				{
					currentSortType = value;
					PopulateTree(broadcastParametersTreeView, isSelected: true);
					if (currentSortType == BroadcastParameterSortType.PGN)
					{
						broadcastParametersTreeView.Cols[1].Width = treeViewPGNParameterNameColWidth;
						broadcastParametersTreeView.Cols[2].Width = treeViewSrcAddrColWidth;
						broadcastParametersTreeView.Cols[3].Width = treeViewPGNCommentColWidth;
						broadcastParametersTreeView.Cols[4].Width = 0;
					}
					else if (currentSortType == BroadcastParameterSortType.ParameterName)
					{
						broadcastParametersTreeView.Cols[1].Width = listViewParameterNameColWidth;
						broadcastParametersTreeView.Cols[2].Width = listViewSrcAddrColWidth;
						broadcastParametersTreeView.Cols[3].Width = listViewPGNNameColWidth;
						broadcastParametersTreeView.Cols[4].Width = listViewParameterCommentColWidth;
					}
					else
					{
						broadcastParametersTreeView.Cols[1].Width = treeViewSrcAddrParameterNameColWidth;
						broadcastParametersTreeView.Cols[2].Width = treeViewSrcAddrCommentColWidth;
						broadcastParametersTreeView.Cols[3].Width = 0;
						broadcastParametersTreeView.Cols[4].Width = 0;
					}
				}
			}
		}

		public StringCollection SelectedParameter => GetOrderedParameterList(parameterList.SelectedParameters, currentSortType, deviceAddress);

		private int MaxParameterRowCount
		{
			get
			{
				maxParameterCount = 1;
				Dictionary<byte, IParameterListInfo> broadcastParameters = calibration.BroadcastParameters;
				foreach (byte key in broadcastParameters.Keys)
				{
					IParameterListInfo parameterListInfo = broadcastParameters[key];
					maxParameterCount += 1 + (parameterListInfo.Parameters as PublicDataParamInfoList).PGNs.Count;
					foreach (PCLWrapper.ParameterInfo pGN in (parameterListInfo.Parameters as PublicDataParamInfoList).PGNs)
					{
						if (pGN.Children != null)
						{
							maxParameterCount += pGN.Children.Count;
						}
					}
				}
				return maxParameterCount;
			}
		}

		public string CurrentScreenName
		{
			set
			{
				((Control)cmbBoxAvailableScreens).Text = value;
			}
		}

		public event CancelEventHandler ParameterQueryClosing
		{
			add
			{
				((Form)this).Closing += value;
			}
			remove
			{
				((Form)this).Closing -= value;
			}
		}

		public event EventHandler AddParameterOnEnterEvent;

		public event ParameterAddedOnScreenEventHandler ParameterAddedOnScreenEvent;

		public BroadcastParameterDialog(ICalibrationOnline dataSource, IParameterListInfo parameterList, DataTable screenTable)
		{
			this.screenTable = screenTable;
			this.parameterList = parameterList;
			calibrationOnline = dataSource;
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		}

		public void fetchData()
		{
			Thread thread = new Thread(BufferData);
			thread.IsBackground = true;
			thread.Start();
			Initialize(calibrationOnline);
		}

		private void BufferData()
		{
			//IL_0021: Unknown result type (might be due to invalid IL or missing references)
			_WaitDlg = new WaitDlg();
			_WaitDlg.setTitle("Buffering data, please wait for few seconds...");
			((Form)_WaitDlg).ShowDialog();
		}

		protected override void Dispose(bool disposing)
		{
			if (shouldClose)
			{
				if (disposing && components != null)
				{
					calibration.StopListeningForBroadcastParameters();
					components.Dispose();
				}
				((Form)this).Dispose(disposing);
			}
		}

		private void Initialize(ICalibrationOnline onlineCal)
		{
			//IL_0030: Unknown result type (might be due to invalid IL or missing references)
			//IL_003a: Expected O, but got Unknown
			//IL_0057: Unknown result type (might be due to invalid IL or missing references)
			//IL_0061: Expected O, but got Unknown
			InitializeComponent();
			waitTimer.Enabled = true;
			((Control)this).MinimumSize = new Size(((Control)this).Width, ((Control)this).Height - 230);
			csmMenu = new ContextMenu();
			((Menu)csmMenu).MenuItems.Add(0, new MenuItem("Copy", (EventHandler)OnCopyClick));
			((Control)broadcastParametersTreeView).ContextMenu = csmMenu;
			calibration = onlineCal;
			calibration.StartListeningForBroadcastParameters();
			Thread.Sleep(10000);
			_WaitDlg.ShouldCloseNow = true;
			screenTable.RowDeleting += OnScreenTableRowDeleting;
			screenTable.RowChanged += OnScreenTableRowChanged;
			screenTable.ColumnChanging += OnScreenTableColumnChanging;
			foreach (DataRow row in screenTable.Rows)
			{
				if ("Complex" != row["ScreenType"].ToString() && !cmbBoxAvailableScreens.Items.Contains(row["Name"]))
				{
					cmbBoxAvailableScreens.Items.Add((object)row["Name"].ToString());
				}
			}
			SelectComboBoxAvailableScreensItem();
			InitializeQueryComboBox();
			broadcastParametersTreeView.Cols[0].Visible = false;
			broadcastParametersTreeView.Cols.Count = 5;
			broadcastParametersTreeView.ExtendLastCol = false;
			broadcastParametersTreeView.Tree.Column = 1;
			broadcastParametersTreeView.Rows.Fixed = 1;
			PopulateTree(broadcastParametersTreeView, isSelected: false);
			broadcastParametersTreeView.Cols[2].AllowResizing = true;
			AddParameterOnEnterEvent += btnApply_Click;
		}

		protected void OnCopyClick(object sender, EventArgs e)
		{
			Copy(broadcastParametersTreeView.Clip);
		}

		protected void Copy(string clipBoardData)
		{
			try
			{
				SafeClipBoard safeClipBoard = new SafeClipBoard();
				safeClipBoard.SetDataToClipBoard(clipBoardData);
			}
			catch
			{
			}
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
			//IL_00b1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00bb: Expected O, but got Unknown
			//IL_00bc: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c6: Expected O, but got Unknown
			//IL_00c7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d1: Expected O, but got Unknown
			//IL_00d2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00dc: Expected O, but got Unknown
			//IL_00dd: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e7: Expected O, but got Unknown
			//IL_00e8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f2: Expected O, but got Unknown
			//IL_00f3: Unknown result type (might be due to invalid IL or missing references)
			//IL_00fd: Expected O, but got Unknown
			//IL_00fe: Unknown result type (might be due to invalid IL or missing references)
			//IL_0108: Expected O, but got Unknown
			//IL_010f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0119: Expected O, but got Unknown
			//IL_040e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0418: Expected O, but got Unknown
			//IL_0927: Unknown result type (might be due to invalid IL or missing references)
			//IL_0931: Expected O, but got Unknown
			//IL_09ed: Unknown result type (might be due to invalid IL or missing references)
			//IL_09f7: Expected O, but got Unknown
			//IL_0dd9: Unknown result type (might be due to invalid IL or missing references)
			//IL_0de3: Expected O, but got Unknown
			components = new Container();
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(BroadcastParameterDialog));
			groupBox1 = new GroupBox();
			labelQueryString = new Label();
			btnClearSearchResults = new Button();
			btnSearch = new Button();
			cmbBoxQuerySring = new ComboBox();
			chkSearchComments = new CheckBox();
			groupBox2 = new GroupBox();
			btnUnSelectAll = new Button();
			picBoxCollapseAll = new PictureBox();
			picBoxExpandAll = new PictureBox();
			cmbBoxSortBy = new ComboBox();
			label1 = new Label();
			broadcastParametersTreeView = new C1FlexGrid();
			createToolTip = new ToolTip(components);
			btnRefresh = new Button();
			label2 = new Label();
			btnApply = new Button();
			btnClose = new Button();
			chkBoxAppend = new CheckBox();
			lblScreens = new Label();
			cmbBoxAvailableScreens = new ComboBox();
			waitTimer = new Timer(components);
			((Control)groupBox1).SuspendLayout();
			((Control)groupBox2).SuspendLayout();
			((ISupportInitialize)picBoxCollapseAll).BeginInit();
			((ISupportInitialize)picBoxExpandAll).BeginInit();
			((ISupportInitialize)broadcastParametersTreeView).BeginInit();
			((Control)this).SuspendLayout();
			((Control)groupBox1).Anchor = (AnchorStyles)13;
			((Control)groupBox1).Controls.Add((Control)(object)labelQueryString);
			((Control)groupBox1).Controls.Add((Control)(object)btnClearSearchResults);
			((Control)groupBox1).Controls.Add((Control)(object)btnSearch);
			((Control)groupBox1).Controls.Add((Control)(object)cmbBoxQuerySring);
			((Control)groupBox1).Controls.Add((Control)(object)chkSearchComments);
			((Control)groupBox1).Location = new Point(2, 3);
			((Control)groupBox1).Name = "groupBox1";
			((Control)groupBox1).Size = new Size(445, 71);
			((Control)groupBox1).TabIndex = 44;
			groupBox1.TabStop = false;
			((Control)groupBox1).Text = "Search";
			((Control)labelQueryString).Location = new Point(6, 14);
			((Control)labelQueryString).Name = "labelQueryString";
			((Control)labelQueryString).Size = new Size(75, 16);
			((Control)labelQueryString).TabIndex = 45;
			((Control)labelQueryString).Text = "Search String";
			((Control)btnClearSearchResults).Anchor = (AnchorStyles)9;
			((Control)btnClearSearchResults).Location = new Point(316, 41);
			((Control)btnClearSearchResults).Name = "btnClearSearchResults";
			((Control)btnClearSearchResults).Size = new Size(121, 24);
			((Control)btnClearSearchResults).TabIndex = 6;
			((Control)btnClearSearchResults).Tag = "0";
			((Control)btnClearSearchResults).Text = "&Clear Search Results";
			((Control)btnClearSearchResults).Click += btnClearSearchResults_Click;
			((Control)btnSearch).Anchor = (AnchorStyles)9;
			((Control)btnSearch).Location = new Point(381, 11);
			((Control)btnSearch).Name = "btnSearch";
			((Control)btnSearch).Size = new Size(56, 24);
			((Control)btnSearch).TabIndex = 5;
			((Control)btnSearch).Tag = "0";
			((Control)btnSearch).Text = "&Search";
			((Control)btnSearch).Click += OnSearchButtonClick;
			((Control)cmbBoxQuerySring).Anchor = (AnchorStyles)12;
			((ListControl)cmbBoxQuerySring).DisplayMember = "Text";
			((Control)cmbBoxQuerySring).Location = new Point(86, 11);
			((Control)cmbBoxQuerySring).Name = "cmbBoxQuerySring";
			((Control)cmbBoxQuerySring).Size = new Size(280, 21);
			((Control)cmbBoxQuerySring).TabIndex = 0;
			((Control)cmbBoxQuerySring).KeyUp += new KeyEventHandler(cmbBoxQuerySring_KeyUp);
			chkSearchComments.Checked = true;
			chkSearchComments.CheckState = (CheckState)1;
			((Control)chkSearchComments).Location = new Point(10, 41);
			((Control)chkSearchComments).Name = "chkSearchComments";
			((Control)chkSearchComments).Size = new Size(128, 16);
			((Control)chkSearchComments).TabIndex = 6;
			((Control)chkSearchComments).Text = "Search Comments?";
			((Control)groupBox2).Anchor = (AnchorStyles)13;
			((Control)groupBox2).Controls.Add((Control)(object)btnUnSelectAll);
			((Control)groupBox2).Controls.Add((Control)(object)picBoxCollapseAll);
			((Control)groupBox2).Controls.Add((Control)(object)picBoxExpandAll);
			((Control)groupBox2).Controls.Add((Control)(object)cmbBoxSortBy);
			((Control)groupBox2).Controls.Add((Control)(object)label1);
			((Control)groupBox2).Location = new Point(2, 80);
			((Control)groupBox2).Name = "groupBox2";
			((Control)groupBox2).Size = new Size(302, 69);
			((Control)groupBox2).TabIndex = 45;
			groupBox2.TabStop = false;
			((Control)groupBox2).Text = "Organize data";
			((Control)btnUnSelectAll).Location = new Point(219, 41);
			((Control)btnUnSelectAll).Name = "btnUnSelectAll";
			((Control)btnUnSelectAll).Size = new Size(75, 24);
			((Control)btnUnSelectAll).TabIndex = 20;
			((Control)btnUnSelectAll).Tag = "0";
			((Control)btnUnSelectAll).Text = "&Unselect all";
			((Control)btnUnSelectAll).Click += btnUnSelectAll_Click;
			picBoxCollapseAll.Image = (Image)(object)Resources.collapseIcon;
			((Control)picBoxCollapseAll).Location = new Point(47, 45);
			((Control)picBoxCollapseAll).Name = "picBoxCollapseAll";
			((Control)picBoxCollapseAll).Size = new Size(16, 16);
			picBoxCollapseAll.TabIndex = 19;
			picBoxCollapseAll.TabStop = false;
			createToolTip.SetToolTip((Control)(object)picBoxCollapseAll, "Collapse all");
			((Control)picBoxCollapseAll).Click += picBoxCollapseAll_Click;
			picBoxExpandAll.Image = (Image)(object)Resources.expandIcon;
			((Control)picBoxExpandAll).Location = new Point(16, 45);
			((Control)picBoxExpandAll).Name = "picBoxExpandAll";
			((Control)picBoxExpandAll).Size = new Size(16, 16);
			picBoxExpandAll.TabIndex = 18;
			picBoxExpandAll.TabStop = false;
			createToolTip.SetToolTip((Control)(object)picBoxExpandAll, "Expand all");
			((Control)picBoxExpandAll).Click += picBoxExpandAll_Click;
			((Control)cmbBoxSortBy).Anchor = (AnchorStyles)13;
			((ListControl)cmbBoxSortBy).DisplayMember = "Text";
			cmbBoxSortBy.Items.AddRange(new object[3] { "ParameterName", "PGN", "SourceAddress" });
			((Control)cmbBoxSortBy).Location = new Point(57, 16);
			((Control)cmbBoxSortBy).Name = "cmbBoxSortBy";
			((Control)cmbBoxSortBy).Size = new Size(238, 21);
			((Control)cmbBoxSortBy).TabIndex = 7;
			((Control)cmbBoxSortBy).Text = "SourceAddress";
			cmbBoxSortBy.SelectedIndexChanged += cmbBoxSortBy_SelectedIndexChanged;
			((Control)label1).Location = new Point(12, 19);
			((Control)label1).Name = "label1";
			((Control)label1).Size = new Size(68, 16);
			((Control)label1).TabIndex = 17;
			((Control)label1).Text = "Sort by";
			broadcastParametersTreeView.AllowDragging = AllowDraggingEnum.None;
			broadcastParametersTreeView.AllowSorting = AllowSortingEnum.MultiColumn;
			((Control)broadcastParametersTreeView).Anchor = (AnchorStyles)15;
			broadcastParametersTreeView.AutoSearch = AutoSearchEnum.FromTop;
			((Control)broadcastParametersTreeView).BackColor = SystemColors.Window;
			broadcastParametersTreeView.ColumnInfo = "10,0,0,0,0,75,Columns:";
			((Control)broadcastParametersTreeView).ForeColor = SystemColors.WindowText;
			((Control)broadcastParametersTreeView).Location = new Point(12, 173);
			((Control)broadcastParametersTreeView).Name = "broadcastParametersTreeView";
			broadcastParametersTreeView.SelectionMode = SelectionModeEnum.Cell;
			broadcastParametersTreeView.ShowButtons = ShowButtonsEnum.Always;
			((Control)broadcastParametersTreeView).Size = new Size(423, 313);
			broadcastParametersTreeView.Styles = new CellStyleCollection(componentResourceManager.GetString("broadcastParametersTreeView.Styles"));
			((Control)broadcastParametersTreeView).TabIndex = 47;
			broadcastParametersTreeView.Tree.Column = 1;
			broadcastParametersTreeView.AfterEdit += OnTreeViewAfterEdit;
			((Control)broadcastParametersTreeView).KeyDown += new KeyEventHandler(OnTreeViewKeyDown);
			((Control)btnRefresh).Anchor = (AnchorStyles)9;
			((Control)btnRefresh).Location = new Point(318, 122);
			((Control)btnRefresh).Name = "btnRefresh";
			((Control)btnRefresh).Size = new Size(121, 24);
			((Control)btnRefresh).TabIndex = 53;
			((Control)btnRefresh).Tag = "0";
			((Control)btnRefresh).Text = "&Refresh";
			((Control)btnRefresh).Click += btnRefresh_Click;
			((Control)label2).Anchor = (AnchorStyles)9;
			((Control)label2).Cursor = Cursors.Default;
			((Control)label2).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
			((Control)label2).ForeColor = SystemColors.Highlight;
			((Control)label2).Location = new Point(310, 87);
			((Control)label2).Name = "label2";
			((Control)label2).Size = new Size(154, 31);
			((Control)label2).TabIndex = 54;
			((Control)label2).Text = "Listening for data. Click Refresh for updates.";
			((Control)btnApply).Anchor = (AnchorStyles)10;
			((Control)btnApply).Location = new Point(370, 518);
			((Control)btnApply).Name = "btnApply";
			((Control)btnApply).Size = new Size(72, 24);
			((Control)btnApply).TabIndex = 61;
			((Control)btnApply).Text = "Apply";
			((Control)btnApply).Click += btnApply_Click;
			((Control)btnClose).Anchor = (AnchorStyles)10;
			btnClose.DialogResult = (DialogResult)2;
			((Control)btnClose).Location = new Point(371, 548);
			((Control)btnClose).Name = "btnClose";
			((Control)btnClose).Size = new Size(72, 24);
			((Control)btnClose).TabIndex = 62;
			((Control)btnClose).Text = "Close";
			((Control)btnClose).Click += btnClose_Click;
			((Control)chkBoxAppend).Anchor = (AnchorStyles)10;
			((Control)chkBoxAppend).AutoSize = true;
			chkBoxAppend.Checked = true;
			chkBoxAppend.CheckState = (CheckState)1;
			((Control)chkBoxAppend).Location = new Point(371, 495);
			((Control)chkBoxAppend).Name = "chkBoxAppend";
			((Control)chkBoxAppend).Size = new Size(63, 17);
			((Control)chkBoxAppend).TabIndex = 63;
			((Control)chkBoxAppend).Text = "Append";
			((ButtonBase)chkBoxAppend).UseVisualStyleBackColor = true;
			((Control)lblScreens).Anchor = (AnchorStyles)6;
			((Control)lblScreens).Location = new Point(1, 513);
			((Control)lblScreens).Name = "lblScreens";
			((Control)lblScreens).Size = new Size(46, 16);
			((Control)lblScreens).TabIndex = 60;
			((Control)lblScreens).Text = "Screens";
			((Control)cmbBoxAvailableScreens).Anchor = (AnchorStyles)14;
			cmbBoxAvailableScreens.DropDownStyle = (ComboBoxStyle)2;
			((Control)cmbBoxAvailableScreens).Location = new Point(54, 512);
			((Control)cmbBoxAvailableScreens).Name = "cmbBoxAvailableScreens";
			((Control)cmbBoxAvailableScreens).Size = new Size(307, 21);
			((Control)cmbBoxAvailableScreens).TabIndex = 59;
			waitTimer.Interval = 10000;
			waitTimer.Tick += waitTimer_Tick;
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Form)this).ClientSize = new Size(464, 581);
			((Control)this).Controls.Add((Control)(object)chkBoxAppend);
			((Control)this).Controls.Add((Control)(object)btnClose);
			((Control)this).Controls.Add((Control)(object)label2);
			((Control)this).Controls.Add((Control)(object)btnApply);
			((Control)this).Controls.Add((Control)(object)btnRefresh);
			((Control)this).Controls.Add((Control)(object)lblScreens);
			((Control)this).Controls.Add((Control)(object)broadcastParametersTreeView);
			((Control)this).Controls.Add((Control)(object)cmbBoxAvailableScreens);
			((Control)this).Controls.Add((Control)(object)groupBox2);
			((Control)this).Controls.Add((Control)(object)groupBox1);
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Control)this).Name = "BroadcastParameterDialog";
			((Control)this).Text = "BroadcastParameterDialog";
			((Form)this).TopMost = true;
			((Control)this).Resize += OnResizeParameterQuery;
			((Control)groupBox1).ResumeLayout(false);
			((Control)groupBox2).ResumeLayout(false);
			((ISupportInitialize)picBoxCollapseAll).EndInit();
			((ISupportInitialize)picBoxExpandAll).EndInit();
			((ISupportInitialize)broadcastParametersTreeView).EndInit();
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}

		private void waitTimer_Tick(object sender, EventArgs e)
		{
			waitTimer.Enabled = false;
			SendKeys.Send("{ESC}");
		}

		private void OnResizeParameterQuery(object sender, EventArgs e)
		{
			if (CurrentSortType == BroadcastParameterSortType.SourceAddress)
			{
				broadcastParametersTreeView.Cols[2].Width = ((Control)broadcastParametersTreeView).Width - broadcastParametersTreeView.Cols[1].Width;
				treeViewSrcAddrCommentColWidth = broadcastParametersTreeView.Cols[2].Width;
				treeViewPGNCommentColWidth = ((Control)broadcastParametersTreeView).Width - (treeViewSrcAddrColWidth + treeViewPGNParameterNameColWidth);
				listViewParameterCommentColWidth = ((Control)broadcastParametersTreeView).Width - (listViewSrcAddrColWidth + listViewPGNNameColWidth + listViewParameterNameColWidth);
			}
			else if (CurrentSortType == BroadcastParameterSortType.PGN)
			{
				broadcastParametersTreeView.Cols[3].Width = ((Control)broadcastParametersTreeView).Width - (broadcastParametersTreeView.Cols[1].Width + broadcastParametersTreeView.Cols[2].Width);
				treeViewPGNCommentColWidth = broadcastParametersTreeView.Cols[3].Width;
				treeViewSrcAddrCommentColWidth = ((Control)broadcastParametersTreeView).Width - treeViewSrcAddrParameterNameColWidth;
				listViewParameterCommentColWidth = ((Control)broadcastParametersTreeView).Width - (listViewSrcAddrColWidth + listViewPGNNameColWidth + listViewParameterNameColWidth);
			}
			else
			{
				broadcastParametersTreeView.Cols[4].Width = ((Control)broadcastParametersTreeView).Width - (broadcastParametersTreeView.Cols[1].Width + broadcastParametersTreeView.Cols[2].Width + broadcastParametersTreeView.Cols[3].Width);
				listViewParameterCommentColWidth = broadcastParametersTreeView.Cols[4].Width;
				treeViewSrcAddrCommentColWidth = ((Control)broadcastParametersTreeView).Width - treeViewSrcAddrParameterNameColWidth;
				treeViewPGNCommentColWidth = ((Control)broadcastParametersTreeView).Width - (treeViewSrcAddrColWidth + treeViewPGNParameterNameColWidth);
			}
		}

		private void btnClearSearchResults_Click(object sender, EventArgs e)
		{
			((Control)cmbBoxQuerySring).Text = "";
			queryString = null;
			QueryFromTree(selectedStatus: true);
		}

		private void SelectComboBoxAvailableScreensItem()
		{
			if (cmbBoxAvailableScreens.Items.Count > 0 && ((Control)cmbBoxAvailableScreens).Text == string.Empty)
			{
				((Control)cmbBoxAvailableScreens).Text = cmbBoxAvailableScreens.Items[0].ToString();
			}
		}

		private void OnSearchButtonClick(object sender, EventArgs e)
		{
			queryString = ((Control)cmbBoxQuerySring).Text;
			QueryFromTree(selectedStatus: true);
			AddToQueryList(cmbBoxQuerySring, queryString);
		}

		internal void InitializeQueryComboBox()
		{
			InitializeQueryComboBox(cmbBoxQuerySring);
		}

		protected void cmbBoxQuerySring_KeyUp(object sender, KeyEventArgs e)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0008: Invalid comparison between Unknown and I4
			if ((int)e.KeyData == 13)
			{
				OnSearchButtonClick(sender, (EventArgs)(object)e);
			}
		}

		protected void InitializeQueryComboBox(ComboBox comboBox)
		{
			for (int i = 0; i < 5; i++)
			{
				appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				try
				{
					string appSetting = appConfigService.GetAppSetting(ApplicationSettings.BroadcastParameterSearchText, (ushort)(i + 1));
					AddToQueryList(comboBox, appSetting);
				}
				catch
				{
				}
			}
		}

		protected void AddToQueryList(ComboBox comboBox, string queryString)
		{
			if (comboBox != null && queryString != null && queryString.Trim() != string.Empty && !comboBox.Items.Contains((object)queryString))
			{
				if (comboBox.Items.Count >= 5)
				{
					comboBox.Items.RemoveAt(0);
				}
				comboBox.Items.Add((object)queryString);
				for (int i = 0; i < comboBox.Items.Count; i++)
				{
					string value = comboBox.Items[i].ToString();
					appConfigService.SetAppSetting(ApplicationSettings.BroadcastParameterSearchText, value, (ushort)(i + 1));
				}
			}
		}

		private void picBoxExpandAll_Click(object sender, EventArgs e)
		{
			broadcastParametersTreeView.Redraw = false;
			if (broadcastParametersTreeView.Row > 0)
			{
				Node node = ((broadcastParametersTreeView.Row != 1) ? broadcastParametersTreeView.Rows[broadcastParametersTreeView.Row].Node : ((broadcastParametersTreeView.Rows.Count <= 2) ? broadcastParametersTreeView.Rows[broadcastParametersTreeView.Row].Node : broadcastParametersTreeView.Rows[broadcastParametersTreeView.Row + 1].Node));
				if (node != null)
				{
					Node node2 = node.GetNode(NodeTypeEnum.FirstSibling);
					if (node2 == null)
					{
						node2 = node;
					}
					while (node2 != null)
					{
						node2.Collapsed = false;
						node2 = node2.GetNode(NodeTypeEnum.NextSibling);
					}
				}
			}
			broadcastParametersTreeView.Redraw = true;
		}

		private void picBoxCollapseAll_Click(object sender, EventArgs e)
		{
			broadcastParametersTreeView.Redraw = false;
			if (broadcastParametersTreeView.Row > 0)
			{
				Node node = ((broadcastParametersTreeView.Row != 1) ? broadcastParametersTreeView.Rows[broadcastParametersTreeView.Row].Node : ((broadcastParametersTreeView.Rows.Count <= 2) ? broadcastParametersTreeView.Rows[broadcastParametersTreeView.Row].Node : broadcastParametersTreeView.Rows[broadcastParametersTreeView.Row + 1].Node));
				if (node != null)
				{
					Node node2 = node.GetNode(NodeTypeEnum.FirstSibling);
					if (node2 == null)
					{
						node2 = node;
					}
					while (node2 != null)
					{
						node2.Collapsed = true;
						node2 = node2.GetNode(NodeTypeEnum.NextSibling);
					}
				}
			}
			broadcastParametersTreeView.Redraw = true;
		}

		private void btnApply_Click(object sender, EventArgs e)
		{
			//IL_00d0: Unknown result type (might be due to invalid IL or missing references)
			if (((Control)cmbBoxAvailableScreens).Text != string.Empty)
			{
				if (this.ParameterAddedOnScreenEvent == null)
				{
					return;
				}
				Cursor cursor = ((Control)this).Cursor;
				((Control)this).Cursor = Cursors.WaitCursor;
				Dictionary<byte, IParameterListInfo> broadcastParameters = calibration.BroadcastParameters;
				foreach (byte key in broadcastParameters.Keys)
				{
					deviceAddress = AddressFactory.ProductAddressValue(key);
					try
					{
						ParameterAddedOnScreenEventArgs e2 = new ParameterAddedOnScreenEventArgs(((Control)cmbBoxAvailableScreens).Text, SelectedParameter, chkBoxAppend.Checked);
						this.ParameterAddedOnScreenEvent(this, e2, isBroadcast: true, deviceAddress);
					}
					finally
					{
						((Control)this).Cursor = cursor;
					}
				}
				ClearAll();
			}
			else
			{
				MessageBox.Show("Please select the screen name first", "Broadcast ParameterQuery");
			}
		}

		private void btnRefresh_Click(object sender, EventArgs e)
		{
			Cursor current = Cursor.Current;
			Cursor.Current = Cursors.WaitCursor;
			PopulateTree(broadcastParametersTreeView, isSelected: false);
			broadcastParametersTreeView.Cols[2].AllowResizing = true;
			Cursor.Current = current;
		}

		public void ClearAll()
		{
			int count = broadcastParametersTreeView.Rows.Count;
			StringEnumerator enumerator = parameterList.SelectedParameters.GetEnumerator();
			try
			{
				while (enumerator.MoveNext())
				{
					string current = enumerator.Current;
					parameterList[current].IsSelected = false;
				}
			}
			finally
			{
				if (enumerator is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
			parameterList.SelectedParameters.Clear();
			for (int i = 1; i < count; i++)
			{
				broadcastParametersTreeView.SetCellCheck(i, 1, CheckEnum.Unchecked);
			}
		}

		protected void QueryFromTree(bool selectedStatus)
		{
			Cursor current = Cursor.Current;
			Cursor.Current = Cursors.WaitCursor;
			BuildTreeView(broadcastParametersTreeView, CurrentSortType, selectedStatus, null, queryString);
			StringCollection orderedParameterList = GetOrderedParameterList(parameterList.SelectedParameters, currentSortType, null);
			for (int i = 1; i < broadcastParametersTreeView.Rows.Count; i++)
			{
				string value = broadcastParametersTreeView.Rows[i].Node.Data.ToString();
				if (orderedParameterList.Contains(value))
				{
					broadcastParametersTreeView.SetCellCheck(i, 1, CheckEnum.Checked);
				}
				else
				{
					broadcastParametersTreeView.SetCellCheck(i, 1, CheckEnum.Unchecked);
				}
			}
			Cursor.Current = current;
		}

		private void btnClose_Click(object sender, EventArgs e)
		{
			((Control)this).Visible = false;
		}

		private void btnUnSelectAll_Click(object sender, EventArgs e)
		{
			int count = broadcastParametersTreeView.Rows.Count;
			StringEnumerator enumerator = parameterList.SelectedParameters.GetEnumerator();
			try
			{
				while (enumerator.MoveNext())
				{
					string current = enumerator.Current;
					parameterList[current].IsSelected = false;
				}
			}
			finally
			{
				if (enumerator is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
			parameterList.SelectedParameters.Clear();
			for (int i = 1; i < count; i++)
			{
				broadcastParametersTreeView.SetCellCheck(i, 1, CheckEnum.Unchecked);
			}
		}

		private void cmbBoxSortBy_SelectedIndexChanged(object sender, EventArgs e)
		{
			switch (cmbBoxSortBy.SelectedItem.ToString())
			{
			case "ParameterName":
				CurrentSortType = BroadcastParameterSortType.ParameterName;
				break;
			case "PGN":
				CurrentSortType = BroadcastParameterSortType.PGN;
				break;
			case "SourceAddress":
				CurrentSortType = BroadcastParameterSortType.SourceAddress;
				break;
			}
		}

		private void OnTreeViewAfterEdit(object sender, RowColEventArgs e)
		{
			UpdateParameterSelection(e.Row);
		}

		private void OnTreeViewKeyDown(object sender, KeyEventArgs e)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0008: Invalid comparison between Unknown and I4
			//IL_0041: Unknown result type (might be due to invalid IL or missing references)
			//IL_0048: Invalid comparison between Unknown and I4
			if ((int)e.KeyData == 13)
			{
				int rowSel = broadcastParametersTreeView.RowSel;
				broadcastParametersTreeView.SetCellCheck(rowSel, 1, CheckEnum.Checked);
				UpdateParameterSelection(rowSel);
				RaiseAddParameterOnEnterEvent();
				handledByEnter = true;
				e.Handled = true;
			}
			else if ((int)e.KeyCode == 67 && e.Control)
			{
				Copy(broadcastParametersTreeView.Clip);
				e.Handled = true;
			}
			else
			{
				e.Handled = false;
			}
		}

		protected virtual void PopulateTree(C1FlexGrid treeView, bool isSelected)
		{
			treeView.Redraw = false;
			if (calibration != null)
			{
				Cursor current = Cursor.Current;
				Cursor.Current = Cursors.WaitCursor;
				Dictionary<byte, IParameterListInfo> broadcastParameters = calibration.BroadcastParameters;
				foreach (byte key in broadcastParameters.Keys)
				{
					IAddressValue addressValue = AddressFactory.ProductAddressValue(key);
					treeView.AddItem(addressValue.DisplayId);
					_publicDataParameterListInfo = (PublicDataParameterListInfo)broadcastParameters[key];
					List<PCLWrapper.ParameterInfo> pGNs = (_publicDataParameterListInfo.Parameters as PublicDataParamInfoList).PGNs;
					foreach (PCLWrapper.ParameterInfo item in pGNs)
					{
						if (item.Children == null)
						{
							continue;
						}
						foreach (SubParameterInfo child in item.Children)
						{
							treeView.AddItem(child.Name);
						}
					}
				}
				try
				{
					if (parameterList != null && (treeView.Rows.Count > 0 || !isSelected))
					{
						if (queryString == null || queryString == "")
						{
							BuildTreeView(treeView, CurrentSortType, isSelected, null, null);
						}
						else
						{
							BuildTreeView(treeView, CurrentSortType, isSelected, null, queryString);
						}
						int count = treeView.Rows.Count;
						StringCollection selectedParameters = parameterList.SelectedParameters;
						for (int i = 1; i < count; i++)
						{
							string text = treeView.Rows[i].Node.Data.ToString();
							if (selectedParameters.Contains(text))
							{
								treeView.SetCellCheck(i, 1, CheckEnum.Checked);
								if (parameterList.IsStructure(text))
								{
									for (Node node = treeView.Rows[i].Node.GetNode(NodeTypeEnum.FirstChild); node != null; node = node.GetNode(NodeTypeEnum.NextSibling))
									{
										i++;
										treeView.SetCellCheck(node.Row.Index, 1, CheckEnum.Checked);
									}
								}
							}
							else
							{
								treeView.SetCellCheck(i, 1, CheckEnum.Unchecked);
							}
						}
					}
				}
				finally
				{
					Cursor.Current = current;
				}
			}
			treeView.Redraw = true;
		}

		private StringCollection GetOrderedParameterList(StringCollection paramList, BroadcastParameterSortType sortType, IAddressValue deviceAddress)
		{
			StringCollection stringCollection = new StringCollection();
			for (int i = 2; i < broadcastParametersTreeView.Rows.Count; i++)
			{
				if (broadcastParametersTreeView.GetCellCheck(i, 1) != CheckEnum.Checked)
				{
					continue;
				}
				Node node = broadcastParametersTreeView.Rows[i].Node;
				Node node2 = node.GetNode(NodeTypeEnum.Parent);
				Node node3 = node2.GetNode(NodeTypeEnum.Parent);
				string text = null;
				if (node3 != null)
				{
					if ((deviceAddress.DisplayId == node3.Data.ToString() && node.Level == 3) || deviceAddress == null)
					{
						text = node2.Data.ToString() + "." + node.Data.ToString();
					}
					else if ((deviceAddress.DisplayId == broadcastParametersTreeView[i, 2].ToString() && node.Level == 2) || deviceAddress == null)
					{
						text = node2.Data.ToString() + "." + node.Data.ToString();
					}
				}
				else
				{
					if (node2.Data.ToString() == "PGN" || node2.Data.ToString() == "SourceAddress")
					{
						continue;
					}
					if (node2.Data.ToString() != "All Parameters")
					{
						text = node2.Data.ToString() + "." + node.Data.ToString();
					}
					else if (deviceAddress.DisplayId == broadcastParametersTreeView[i, 2].ToString() || deviceAddress == null)
					{
						text = string.Concat(broadcastParametersTreeView[i, 3], ".", node.Data.ToString());
					}
				}
				if (text != null)
				{
					stringCollection.Add(text);
				}
			}
			return stringCollection;
		}

		private void DoCheck(int row, CheckEnum checkValue)
		{
			if (row > 1)
			{
				broadcastParametersTreeView[row, 1].ToString();
				broadcastParametersTreeView.SetCellCheck(row, 1, checkValue);
			}
		}

		private void UpdateParameterSelection(int selectedRowIndex)
		{
			bool isIncludeComplexParameter = true;
			bool flag = false;
			if (!handledByEnter)
			{
				Node node = broadcastParametersTreeView.Rows[selectedRowIndex].Node;
				Node node2 = node.GetNode(NodeTypeEnum.Parent);
				Node node3 = null;
				if (node2 != null)
				{
					node3 = node2.GetNode(NodeTypeEnum.Parent);
				}
				if (node2 != null && !parameterList.IsStructure(node2.Data.ToString()))
				{
					DoSelect(selectedRowIndex, broadcastParametersTreeView.GetCellCheck(selectedRowIndex, 1));
					string paramName = null;
					if (node2.Data.ToString() == "All Parameters")
					{
						paramName = string.Concat(broadcastParametersTreeView[selectedRowIndex, 3], ".", node.Data.ToString());
						flag = true;
					}
					else if (node2.Data.ToString().Contains("SourceAddress") || node2.Data.ToString().Contains("PGN") || (node3 != null && node3.Data.ToString().Contains("SourceAddress")))
					{
						for (Node node4 = node.GetNode(NodeTypeEnum.FirstChild); node4 != null; node4 = node4.GetNode(NodeTypeEnum.NextSibling))
						{
							flag = true;
							UpdateParameterSelection(node4.Row.Index);
						}
						flag = false;
					}
					else if (node3 != null)
					{
						paramName = node2.Data.ToString() + "." + node.Data.ToString();
						flag = true;
					}
					if (flag)
					{
						IParamInfo paramInfo = parameterList[paramName];
						if (paramInfo == null)
						{
							if (node.Data.ToString().Equals("All Parameters") || node.Data.ToString().Equals("PGN") || parameterList.Groups.Contains(node.Data.ToString()) || node.Data.ToString().Equals("SourceAddress") || node3.Data.ToString().Equals("SourceAddress"))
							{
								isIncludeComplexParameter = true;
							}
						}
						else
						{
							isIncludeComplexParameter = true;
						}
					}
				}
				if (node.GetNode(NodeTypeEnum.FirstChild) != null)
				{
					if (parameterList.IsStructure(node.Data.ToString()))
					{
						Node node5 = node.GetNode(NodeTypeEnum.FirstChild);
						if (node5 == null)
						{
							node5 = node;
						}
						while (node5 != null)
						{
							DoCheck(node5.Row.Index, broadcastParametersTreeView.GetCellCheck(selectedRowIndex, 1));
							node5 = node5.GetNode(NodeTypeEnum.NextSibling);
						}
					}
					else
					{
						RecursiveSelect(isIncludeComplexParameter, node.GetNode(NodeTypeEnum.FirstChild), broadcastParametersTreeView.GetCellCheck(selectedRowIndex, 1));
					}
				}
				else
				{
					if (node2 == null)
					{
						return;
					}
					Node node6 = node2.GetNode(NodeTypeEnum.Parent);
					if (node6 == null)
					{
						return;
					}
					if (!node6.Data.ToString().ToUpper().StartsWith("PGN") && !node6.Data.ToString().ToUpper().StartsWith("SourceAddress") && !node6.Data.ToString().ToUpper().StartsWith("All Parameters") && node.Level < 3)
					{
						DoSelect(node2.Row.Index, broadcastParametersTreeView.GetCellCheck(selectedRowIndex, 1));
						Node node7 = node.GetNode(NodeTypeEnum.FirstSibling);
						if (node7 == null)
						{
							node7 = node;
						}
						while (node7 != null)
						{
							DoSelect(node7.Row.Index, broadcastParametersTreeView.GetCellCheck(selectedRowIndex, 1));
							node7 = node7.GetNode(NodeTypeEnum.NextSibling);
						}
					}
					else if (parameterList.IsStructure(node2.Data.ToString()))
					{
						DoSelect(node2.Row.Index, broadcastParametersTreeView.GetCellCheck(selectedRowIndex, 1));
						Node node8 = node.GetNode(NodeTypeEnum.FirstSibling);
						if (node8 == null)
						{
							node8 = node;
						}
						while (node8 != null)
						{
							DoCheck(node8.Row.Index, broadcastParametersTreeView.GetCellCheck(selectedRowIndex, 1));
							node8 = node8.GetNode(NodeTypeEnum.NextSibling);
						}
					}
				}
			}
			else
			{
				handledByEnter = false;
				broadcastParametersTreeView.SetCellCheck(selectedRowIndex, 1, CheckEnum.Unchecked);
			}
		}

		private void DoSelect(int row, CheckEnum checkValue)
		{
			if (row <= 1)
			{
				return;
			}
			string paramName = null;
			bool flag = false;
			Node node = broadcastParametersTreeView.Rows[row].Node;
			Node node2 = node.GetNode(NodeTypeEnum.Parent);
			if (CurrentSortType == BroadcastParameterSortType.SourceAddress)
			{
				if (node2 != null)
				{
					if (node.Level > 2)
					{
						paramName = node2.Data.ToString() + "." + broadcastParametersTreeView[row, 1].ToString();
						flag = true;
					}
					else if (node.Level == 2)
					{
						for (Node node3 = node.GetNode(NodeTypeEnum.FirstChild); node3 != null; node3 = node3.GetNode(NodeTypeEnum.NextSibling))
						{
							flag = true;
							DoSelect(node3.Row.Index, checkValue);
						}
						flag = false;
					}
					else if (node.Level == 1)
					{
						for (Node node4 = node.GetNode(NodeTypeEnum.FirstChild); node4 != null; node4 = node4.GetNode(NodeTypeEnum.NextSibling))
						{
							flag = true;
							for (Node node5 = node4.GetNode(NodeTypeEnum.FirstChild); node5 != null; node5 = node5.GetNode(NodeTypeEnum.NextSibling))
							{
								DoSelect(node5.Row.Index, checkValue);
							}
							DoSelect(node4.Row.Index, checkValue);
						}
						flag = false;
					}
				}
			}
			else if (CurrentSortType == BroadcastParameterSortType.PGN)
			{
				Node node6 = node2.GetNode(NodeTypeEnum.Parent);
				if (node6 != null && node6.Data.ToString() == "PGN")
				{
					paramName = node2.Data.ToString() + "." + broadcastParametersTreeView[row, 1].ToString();
					flag = true;
				}
				else
				{
					node.Data.ToString();
					for (Node node7 = node.GetNode(NodeTypeEnum.FirstChild); node7 != null; node7 = node7.GetNode(NodeTypeEnum.NextSibling))
					{
						flag = true;
						DoSelect(node7.Row.Index, checkValue);
					}
					flag = false;
				}
			}
			else
			{
				paramName = broadcastParametersTreeView[row, 3].ToString() + "." + broadcastParametersTreeView[row, 1].ToString();
				flag = true;
			}
			if (flag)
			{
				parameterList.SetSelectedStatus(paramName, checkValue == CheckEnum.Checked);
				broadcastParametersTreeView.SetCellCheck(row, 1, checkValue);
			}
		}

		private void RecursiveSelect(bool isIncludeComplexParameter, Node node, CheckEnum checkValue)
		{
			bool flag = false;
			while (node != null)
			{
				if (isIncludeComplexParameter)
				{
					flag = true;
				}
				if (flag)
				{
					DoSelect(node.Row.Index, checkValue);
					if (node.GetNode(NodeTypeEnum.FirstChild) != null)
					{
						DoSelect(node.GetNode(NodeTypeEnum.FirstChild).Row.Index, checkValue);
						RecursiveSelect(isIncludeComplexParameter, node.GetNode(NodeTypeEnum.FirstChild), checkValue);
					}
				}
				node = node.GetNode(NodeTypeEnum.NextSibling);
			}
		}

		public void BuildTreeView(C1FlexGrid treeView, BroadcastParameterSortType sortType, bool selectedStatus, string focusNodeName, string queryString)
		{
			treeView.Redraw = false;
			_parameterListViewData.CurrentParamLookup.Clear();
			Dictionary<byte, IParameterListInfo> broadcastParameters = calibration.BroadcastParameters;
			foreach (byte key in broadcastParameters.Keys)
			{
				_publicDataParameterListInfo = (PublicDataParameterListInfo)broadcastParameters[key];
				List<PCLWrapper.ParameterInfo> pGNs = (_publicDataParameterListInfo.Parameters as PublicDataParamInfoList).PGNs;
				foreach (PCLWrapper.ParameterInfo item in pGNs)
				{
					if (item.Children == null)
					{
						continue;
					}
					if (queryString != null && queryString.Trim() != string.Empty)
					{
						bool flag = false;
						if (item.Name.ToLower().IndexOf(queryString.ToLower()) > -1 || (chkSearchComments.Checked && item.Description.ToLower().IndexOf(queryString.ToLower()) > -1))
						{
							flag = true;
						}
						if (item.Children.Count > 0)
						{
							foreach (SubParameterInfo child in item.Children)
							{
								if (child.Name.ToLower().IndexOf(queryString.ToLower()) > -1 || (chkSearchComments.Checked && child.Description.ToLower().IndexOf(queryString.ToLower()) > -1))
								{
									flag = true;
								}
							}
						}
						if (!flag)
						{
							continue;
						}
					}
					if (!_parameterListViewData.CurrentParamLookup.Contains(item.Name))
					{
						_parameterListViewData.CurrentParamLookup.Add(item.Name, null);
					}
				}
			}
			BuildTreeView(treeView, sortType, focusNodeName);
			treeView.Redraw = true;
		}

		public void BuildTreeView(C1FlexGrid treeView, BroadcastParameterSortType sortType, string focusNodeName)
		{
			//IL_016c: Unknown result type (might be due to invalid IL or missing references)
			treeView.Redraw = false;
			treeView.Clear();
			rowIndex = 1;
			try
			{
				switch (sortType)
				{
				case BroadcastParameterSortType.ParameterName:
					if (treeView.Cols[1].Width != -1)
					{
						listViewParameterNameColWidth = treeView.Cols[1].Width;
						listViewSrcAddrColWidth = treeView.Cols[2].Width;
						listViewPGNNameColWidth = treeView.Cols[3].Width;
						listViewParameterCommentColWidth = treeView.Cols[4].Width;
					}
					BuildParameterView(treeView);
					break;
				case BroadcastParameterSortType.PGN:
					if (treeView.Cols[1].Width != -1)
					{
						treeViewPGNParameterNameColWidth = treeView.Cols[1].Width;
						treeViewSrcAddrColWidth = treeView.Cols[2].Width;
						treeViewPGNCommentColWidth = treeView.Cols[3].Width;
					}
					BuildParameterView(treeView);
					break;
				case BroadcastParameterSortType.SourceAddress:
					if (treeView.Cols[1].Width != -1)
					{
						treeViewSrcAddrParameterNameColWidth = treeView.Cols[1].Width;
						treeViewSrcAddrCommentColWidth = treeView.Cols[2].Width;
					}
					BuildSourceAddressView(treeView);
					break;
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show("Error - Failed to build tree view. (" + ex.Message + ")");
			}
			treeView.Redraw = true;
		}

		protected void BuildParentNode(C1FlexGrid treeView)
		{
			//IL_01c8: Unknown result type (might be due to invalid IL or missing references)
			//IL_01d2: Expected O, but got Unknown
			string value = "All Parameters";
			if (CurrentSortType == BroadcastParameterSortType.SourceAddress)
			{
				value = "SourceAddress";
				treeView.Cols[0].Width = 0;
				treeView.Cols[1].Width = treeViewSrcAddrParameterNameColWidth;
				treeView.Cols[2].Width = treeViewSrcAddrCommentColWidth;
				treeView.Cols[3].Width = 0;
				treeView.Cols[4].Width = 0;
			}
			else if (CurrentSortType == BroadcastParameterSortType.PGN)
			{
				value = "PGN";
				treeView.Cols[0].Width = 0;
				treeView.Cols[1].Width = treeViewPGNParameterNameColWidth;
				treeView.Cols[2].Width = treeViewSrcAddrColWidth;
				treeView.Cols[3].Width = treeViewPGNCommentColWidth;
				treeView.Cols[4].Width = 0;
			}
			else
			{
				treeView.Cols[0].Width = 0;
				treeView.Cols[1].Width = listViewParameterNameColWidth;
				treeView.Cols[2].Width = listViewSrcAddrColWidth;
				treeView.Cols[2].Width = listViewPGNNameColWidth;
				treeView.Cols[3].Width = listViewParameterCommentColWidth;
			}
			if (treeView.Rows.Count == 1)
			{
				treeView.Rows.Add();
			}
			treeView.Rows[0].StyleNew.Font = new Font(treeView.Rows[0].Style.Font.FontFamily, treeView.Rows[0].Style.Font.Size, (FontStyle)1);
			treeView.Rows[0].TextAlign = TextAlignEnum.CenterCenter;
			treeView[0, 1] = "Parameter Name";
			treeView[1, 1] = value;
			treeView.Rows[1].IsNode = true;
			treeView.Rows[1].Node.Level = 0;
			if (CurrentSortType == BroadcastParameterSortType.PGN)
			{
				treeView[0, 2] = "SourceAddress";
				treeView[0, 3] = "Comments";
			}
			else if (CurrentSortType == BroadcastParameterSortType.SourceAddress)
			{
				treeView[0, 2] = "Comments";
			}
			else
			{
				treeView[0, 2] = "SourceAddress";
				treeView[0, 3] = "PGN";
				treeView[0, 4] = "Comments";
			}
			treeView.SetCellCheck(1, 1, CheckEnum.Unchecked);
		}

		private void BuildSourceAddressView(C1FlexGrid treeView)
		{
			treeView.Rows.RemoveRange(0, treeView.Rows.Count - 1);
			BuildParentNode(treeView);
			Node node = treeView.Rows[1].Node;
			treeView.Rows[1].Node.Level = 0;
			treeView.Rows.InsertRange(treeView.Rows.Count, MaxParameterRowCount);
			Dictionary<byte, IParameterListInfo> broadcastParameters = calibration.BroadcastParameters;
			foreach (byte key in broadcastParameters.Keys)
			{
				rowIndex++;
				treeView.Rows[rowIndex].IsNode = true;
				treeView.Rows[rowIndex].Node.Level = 1;
				treeView.Rows[rowIndex].TextAlign = TextAlignEnum.LeftCenter;
				IAddressValue addressValue = AddressFactory.ProductAddressValue(key);
				treeView[rowIndex, 1] = addressValue.DisplayId;
				_publicDataParameterListInfo = (PublicDataParameterListInfo)broadcastParameters[key];
				List<PCLWrapper.ParameterInfo> pGNs = (_publicDataParameterListInfo.Parameters as PublicDataParamInfoList).PGNs;
				foreach (PCLWrapper.ParameterInfo item in pGNs)
				{
					if (_parameterListViewData.CurrentParamLookup.ContainsKey(item.Name))
					{
						AddPGNNode(treeView, item);
					}
				}
			}
			treeView.Rows.RemoveRange(rowIndex + 1, treeView.Rows.Count - 1 - rowIndex);
			for (Node node2 = node.GetNode(NodeTypeEnum.FirstChild); node2 != null; node2 = node2.GetNode(NodeTypeEnum.NextSibling))
			{
				for (Node node3 = node2.GetNode(NodeTypeEnum.FirstChild); node3 != null; node3 = node3.GetNode(NodeTypeEnum.NextSibling))
				{
					node3.Sort(SortFlags.Ascending);
				}
				node2.Sort(SortFlags.Ascending);
			}
			node.Sort(SortFlags.Ascending);
		}

		private void BuildParameterView(C1FlexGrid treeView)
		{
			treeView.Rows.RemoveRange(0, treeView.Rows.Count - 1);
			BuildParentNode(treeView);
			Node node = treeView.Rows[1].Node;
			treeView.Rows[1].Node.Level = 0;
			treeView.Rows.InsertRange(treeView.Rows.Count, MaxParameterRowCount);
			Dictionary<byte, IParameterListInfo> broadcastParameters = calibration.BroadcastParameters;
			foreach (byte key in broadcastParameters.Keys)
			{
				_publicDataParameterListInfo = (PublicDataParameterListInfo)broadcastParameters[key];
				List<PCLWrapper.ParameterInfo> pGNs = (_publicDataParameterListInfo.Parameters as PublicDataParamInfoList).PGNs;
				foreach (PCLWrapper.ParameterInfo item in pGNs)
				{
					if (_parameterListViewData.CurrentParamLookup.ContainsKey(item.Name))
					{
						AddParameterNode(treeView, item, key, CurrentSortType);
					}
				}
			}
			treeView.Rows.RemoveRange(rowIndex + 1, treeView.Rows.Count - 1 - rowIndex);
			for (Node node2 = node.GetNode(NodeTypeEnum.FirstChild); node2 != null; node2 = node2.GetNode(NodeTypeEnum.NextSibling))
			{
				node2.Sort(SortFlags.Ascending);
			}
			node.Sort(SortFlags.Ascending);
		}

		protected void AddPGNNode(C1FlexGrid treeView, PCLWrapper.ParameterInfo pgnInfo)
		{
			if (pgnInfo.Children == null)
			{
				return;
			}
			rowIndex++;
			treeView.Rows[rowIndex].IsNode = true;
			treeView.Rows[rowIndex].TextAlign = TextAlignEnum.LeftCenter;
			treeView[rowIndex, 1] = pgnInfo.Name;
			treeView[rowIndex, 2] = pgnInfo.Description;
			treeView.Rows[rowIndex].Node.Level = 2;
			foreach (SubParameterInfo child in pgnInfo.Children)
			{
				rowIndex++;
				treeView.Rows[rowIndex].IsNode = true;
				treeView.Rows[rowIndex].TextAlign = TextAlignEnum.LeftCenter;
				treeView.Rows[rowIndex].Node.Level = 3;
				treeView[rowIndex, 1] = child.Name;
				treeView[rowIndex, 2] = child.Description;
			}
		}

		protected void AddParameterNode(C1FlexGrid treeView, PCLWrapper.ParameterInfo pgnInfo, byte sourceAddress, BroadcastParameterSortType sortType)
		{
			if (pgnInfo.Children == null)
			{
				return;
			}
			switch (sortType)
			{
			case BroadcastParameterSortType.ParameterName:
			{
				IAddressValue addressValue2 = AddressFactory.ProductAddressValue(sourceAddress);
				{
					foreach (SubParameterInfo child in pgnInfo.Children)
					{
						rowIndex++;
						treeView.Rows[rowIndex].IsNode = true;
						treeView.Rows[rowIndex].Node.Level = 1;
						treeView.Rows[rowIndex].TextAlign = TextAlignEnum.LeftCenter;
						treeView[rowIndex, 1] = child.Name;
						treeView[rowIndex, 2] = addressValue2.DisplayId;
						treeView[rowIndex, 3] = pgnInfo.Name;
						treeView[rowIndex, 4] = child.Description;
					}
					break;
				}
			}
			case BroadcastParameterSortType.PGN:
			{
				rowIndex++;
				treeView.Rows[rowIndex].IsNode = true;
				treeView.Rows[rowIndex].Node.Level = 1;
				treeView.Rows[rowIndex].TextAlign = TextAlignEnum.LeftCenter;
				treeView[rowIndex, 1] = pgnInfo.Name;
				treeView[rowIndex, 3] = pgnInfo.Description;
				IAddressValue addressValue = AddressFactory.ProductAddressValue(sourceAddress);
				{
					foreach (SubParameterInfo child2 in pgnInfo.Children)
					{
						rowIndex++;
						treeView.Rows[rowIndex].IsNode = true;
						treeView.Rows[rowIndex].Node.Level = 2;
						treeView.Rows[rowIndex].TextAlign = TextAlignEnum.LeftCenter;
						treeView[rowIndex, 1] = child2.Name;
						treeView[rowIndex, 2] = addressValue.DisplayId;
						treeView[rowIndex, 3] = child2.Description;
					}
					break;
				}
			}
			}
		}

		private void RaiseAddParameterOnEnterEvent()
		{
			if (this.AddParameterOnEnterEvent != null)
			{
				this.AddParameterOnEnterEvent(this, EventArgs.Empty);
			}
		}

		private void OnScreenTableRowChanged(object sender, DataRowChangeEventArgs e)
		{
			if (e.Action == DataRowAction.Add && "Complex" != e.Row["ScreenType"].ToString() && !cmbBoxAvailableScreens.Items.Contains(e.Row["Name"]))
			{
				cmbBoxAvailableScreens.Items.Add((object)e.Row["Name"].ToString());
				SelectComboBoxAvailableScreensItem();
			}
		}

		private void OnScreenTableRowDeleting(object sender, DataRowChangeEventArgs e)
		{
			if (e.Action == DataRowAction.Delete && cmbBoxAvailableScreens.Items.Contains((object)e.Row["Name"].ToString()))
			{
				cmbBoxAvailableScreens.Items.Remove(e.Row["Name"]);
				SelectComboBoxAvailableScreensItem();
			}
		}

		private void OnScreenTableColumnChanging(object sender, DataColumnChangeEventArgs e)
		{
			if (e.Row.RowState == DataRowState.Detached || !(e.Column.ColumnName == "Name"))
			{
				return;
			}
			string text = e.ProposedValue.ToString();
			string text2 = e.Row["Name"].ToString();
			if (cmbBoxAvailableScreens.Items.Contains((object)text2))
			{
				bool flag = ((Control)cmbBoxAvailableScreens).Text == text2;
				cmbBoxAvailableScreens.Items.Remove((object)text2);
				cmbBoxAvailableScreens.Items.Add((object)text);
				if (flag)
				{
					((Control)cmbBoxAvailableScreens).Text = text;
				}
			}
		}
	}
	public enum BroadcastParameterSortType
	{
		ParameterName,
		PGN,
		SourceAddress
	}
	public class ParameterQuery : UserControl
	{
		protected const int ParameterNameColumnNumber = 1;

		protected const int ParameterCommentColumnNumber = 2;

		private const string dataPlateStructureName = "DataplateStructure";

		private const string ParameterColHeading = "Parameter Name";

		private const string CommentColHeading = "Comments";

		internal const string FileDialogFilterString = "Filter Files (*.flt.txt)|*.flt.txt|All files (*.*)|*.*";

		internal const string FilterCommentLinePrefix = ";";

		internal const string FilterFileExtension = ".flt.txt";

		internal const string MenuItemCopy = "Copy";

		protected const string CommentNodeCaption = "Comments";

		protected const string SubfileNodeCaption = "Subfiles";

		protected const string AllParametersNodeCaption = "All Parameters";

		protected const string GroupNodeCaption = "Groups";

		private const float countMultiplier = 0.5f;

		private const string subfile3 = "3";

		private const string FilterConfigHeaderParameterString = "ConfigHeaders.";

		private ComboBox cmbBoxFilter;

		private ComboBox cmbBoxSearchSring;

		private Container components;

		private Panel panel1;

		private CheckBox chkSearchComments;

		private Label lableSelectionCriteria;

		private Label labelSearchString;

		private CheckBox chkShowComment;

		private Button buttonSearchStart;

		private Button buttonCollapse;

		private bool handledByEnter;

		protected ParameterSortType currentSortType;

		protected ParameterSelectionCriteria parameterSelectionCriteria;

		protected ParameterFilterMode parameterFilterMode;

		protected C1FlexGrid unSelectedParametersTreeView;

		protected IParameterListInfo parameterList;

		protected IDirectoryService directoryService;

		protected IAppConfigService appConfigService;

		protected string currentProduct = string.Empty;

		protected string filterFilePath;

		protected string queryString = string.Empty;

		protected bool searchComments;

		protected bool showAllParameters = true;

		protected bool showComment = true;

		private bool showRamParameters = true;

		protected ParameterListViewData _parameterListViewData = new ParameterListViewData();

		protected int parameterNameColWidth = 209;

		protected int parameterCommentColWidth = 209;

		private GroupBox grpBoxSortBy;

		private RadioButton radioBtnParameter;

		private RadioButton radioBtnGroup;

		private RadioButton radioBtnSubfile;

		private GroupBox grpBoxFilterFile;

		private Button btnFilterClear;

		private Button btnFilterSave;

		private Button btnFilterOpen;

		private Label labelFilterFileName;

		private Label labelFilterFileApplied;

		private Label label1;

		private TextBox txtFilterFileName;

		private CheckBox chkBoxShowRamParam;

		private Button buttonUnselectAll;

		private int rowIndex = 1;

		private int maxParameterCount = -1;

		private bool isDataSourceOffline;

		private ContextMenu csmMenu;

		private bool includeStructureParameter = true;

		public bool IncludeStructureParameter
		{
			get
			{
				return includeStructureParameter;
			}
			set
			{
				includeStructureParameter = value;
			}
		}

		protected virtual ParameterSortType CurrentSortType
		{
			get
			{
				return currentSortType;
			}
			set
			{
				if (value != currentSortType)
				{
					currentSortType = value;
					PopulateTree(unSelectedParametersTreeView, ParameterFilterMode == ParameterFilterMode.Include, parameterSelectionCriteria);
					unSelectedParametersTreeView.Cols[1].Width = parameterNameColWidth;
					unSelectedParametersTreeView.Cols[2].Width = parameterCommentColWidth;
				}
			}
		}

		public virtual ParameterFilterMode ParameterFilterMode
		{
			get
			{
				return parameterFilterMode;
			}
			set
			{
				parameterFilterMode = value;
			}
		}

		public StringCollection SelectedParameter => GetOrderedParameterList(parameterList.SelectedParameters, currentSortType);

		private int MaxParameterRowCount
		{
			get
			{
				if (maxParameterCount == -1)
				{
					int num = AllParameterCount + GroupCount + RepeatedGroupCount + RepeatStructCount + SubfileCount;
					maxParameterCount = num + (int)((float)num * 0.5f);
				}
				return maxParameterCount;
			}
		}

		private int AllParameterCount
		{
			get
			{
				int num = 0;
				foreach (string key in parameterList.Parameters.Keys)
				{
					IParamInfo paramInfo = parameterList[key];
					if (!paramInfo.IsTable && paramInfo.IsAxis)
					{
						continue;
					}
					num++;
					if (paramInfo.IsTable && paramInfo.TableAxisInfo != null)
					{
						if (paramInfo.TableAxisInfo.XAxisName.Length > 0)
						{
							num++;
						}
						if (paramInfo.TableAxisInfo.YAxisName.Length > 0)
						{
							num++;
						}
					}
				}
				return num;
			}
		}

		private int GroupCount => parameterList.Groups.Count + parameterList.Structure.Count;

		private int RepeatedGroupCount
		{
			get
			{
				int num = 0;
				foreach (string key in parameterList.Subfile.Keys)
				{
					StringCollection stringCollection = (StringCollection)parameterList.Subfile[key];
					num += stringCollection.Count;
				}
				return num;
			}
		}

		private int RepeatStructCount
		{
			get
			{
				int num = 0;
				foreach (string key in parameterList.Structure.Keys)
				{
					num += parameterList.GetStructInfo(key).ParameterList.Count;
				}
				return num;
			}
		}

		private int SubfileCount => parameterList.Subfile.Count;

		public event EventHandler AddParameterOnEnterEvent;

		protected ParameterQuery()
		{
			directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			currentProduct = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			filterFilePath = appConfigService.GetLastUsedValue(currentProduct, LastUsedType.LastFilterFile);
			Control.CheckForIllegalCrossThreadCalls = false;
		}

		public ParameterQuery(IParameterListInfo parameterList)
			: this()
		{
			this.parameterList = parameterList;
			Initialize();
		}

		public ParameterQuery(IParameterListInfo parameterList, bool isDataSourceOffline)
			: this()
		{
			this.isDataSourceOffline = isDataSourceOffline;
			this.parameterList = parameterList;
			if (isDataSourceOffline)
			{
				showRamParameters = false;
			}
			Initialize();
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
			//IL_02c3: Unknown result type (might be due to invalid IL or missing references)
			//IL_02cd: Expected O, but got Unknown
			//IL_0677: Unknown result type (might be due to invalid IL or missing references)
			//IL_0681: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(ParameterQuery));
			cmbBoxFilter = new ComboBox();
			lableSelectionCriteria = new Label();
			cmbBoxSearchSring = new ComboBox();
			labelSearchString = new Label();
			panel1 = new Panel();
			buttonUnselectAll = new Button();
			chkBoxShowRamParam = new CheckBox();
			unSelectedParametersTreeView = new C1FlexGrid();
			chkSearchComments = new CheckBox();
			chkShowComment = new CheckBox();
			buttonSearchStart = new Button();
			grpBoxSortBy = new GroupBox();
			radioBtnParameter = new RadioButton();
			radioBtnGroup = new RadioButton();
			radioBtnSubfile = new RadioButton();
			grpBoxFilterFile = new GroupBox();
			label1 = new Label();
			txtFilterFileName = new TextBox();
			btnFilterClear = new Button();
			btnFilterSave = new Button();
			btnFilterOpen = new Button();
			labelFilterFileName = new Label();
			labelFilterFileApplied = new Label();
			buttonCollapse = new Button();
			((Control)panel1).SuspendLayout();
			((ISupportInitialize)unSelectedParametersTreeView).BeginInit();
			((Control)grpBoxSortBy).SuspendLayout();
			((Control)grpBoxFilterFile).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)cmbBoxFilter).Anchor = (AnchorStyles)13;
			cmbBoxFilter.DropDownStyle = (ComboBoxStyle)2;
			cmbBoxFilter.Items.AddRange(new object[3] { "Show all parameters", "Show interface parameters", "Hide interface parameters" });
			((Control)cmbBoxFilter).Location = new Point(105, 32);
			((Control)cmbBoxFilter).Name = "cmbBoxFilter";
			((Control)cmbBoxFilter).Size = new Size(201, 21);
			((Control)cmbBoxFilter).TabIndex = 5;
			cmbBoxFilter.SelectedIndexChanged += OnSelectionCriteriaChanged;
			((Control)lableSelectionCriteria).Location = new Point(8, 32);
			((Control)lableSelectionCriteria).Name = "lableSelectionCriteria";
			((Control)lableSelectionCriteria).Size = new Size(91, 21);
			((Control)lableSelectionCriteria).TabIndex = 17;
			((Control)lableSelectionCriteria).Text = "Selection Criteria";
			lableSelectionCriteria.TextAlign = (ContentAlignment)16;
			((Control)cmbBoxSearchSring).Anchor = (AnchorStyles)13;
			((ListControl)cmbBoxSearchSring).DisplayMember = "Text";
			((Control)cmbBoxSearchSring).Location = new Point(105, 8);
			((Control)cmbBoxSearchSring).Name = "cmbBoxSearchSring";
			((Control)cmbBoxSearchSring).Size = new Size(273, 21);
			((Control)cmbBoxSearchSring).TabIndex = 0;
			((Control)cmbBoxSearchSring).KeyUp += new KeyEventHandler(OnComboBoxQueryStringKeyUp);
			((Control)labelSearchString).Location = new Point(8, 8);
			((Control)labelSearchString).Name = "labelSearchString";
			((Control)labelSearchString).Size = new Size(91, 21);
			((Control)labelSearchString).TabIndex = 16;
			((Control)labelSearchString).Text = "Search String";
			labelSearchString.TextAlign = (ContentAlignment)16;
			((Control)panel1).Anchor = (AnchorStyles)15;
			((Control)panel1).Controls.Add((Control)(object)lableSelectionCriteria);
			((Control)panel1).Controls.Add((Control)(object)buttonUnselectAll);
			((Control)panel1).Controls.Add((Control)(object)chkBoxShowRamParam);
			((Control)panel1).Controls.Add((Control)(object)cmbBoxFilter);
			((Control)panel1).Controls.Add((Control)(object)unSelectedParametersTreeView);
			((Control)panel1).Controls.Add((Control)(object)cmbBoxSearchSring);
			((Control)panel1).Controls.Add((Control)(object)chkSearchComments);
			((Control)panel1).Controls.Add((Control)(object)chkShowComment);
			((Control)panel1).Controls.Add((Control)(object)buttonSearchStart);
			((Control)panel1).Controls.Add((Control)(object)grpBoxSortBy);
			((Control)panel1).Controls.Add((Control)(object)grpBoxFilterFile);
			((Control)panel1).Controls.Add((Control)(object)buttonCollapse);
			((Control)panel1).Location = new Point(0, 0);
			((Control)panel1).Name = "panel1";
			((Control)panel1).Size = new Size(456, 500);
			((Control)panel1).TabIndex = 3;
			((Control)buttonUnselectAll).Location = new Point(105, 131);
			((Control)buttonUnselectAll).Name = "buttonUnselectAll";
			((Control)buttonUnselectAll).Size = new Size(89, 24);
			((Control)buttonUnselectAll).TabIndex = 43;
			((Control)buttonUnselectAll).Text = "Unselect All";
			((Control)chkBoxShowRamParam).Anchor = (AnchorStyles)9;
			chkBoxShowRamParam.Checked = true;
			chkBoxShowRamParam.CheckState = (CheckState)1;
			((Control)chkBoxShowRamParam).Location = new Point(224, 131);
			((Control)chkBoxShowRamParam).Name = "chkBoxShowRamParam";
			((Control)chkBoxShowRamParam).Size = new Size(158, 24);
			((Control)chkBoxShowRamParam).TabIndex = 42;
			((Control)chkBoxShowRamParam).Text = "Display RAM Parameters";
			((ButtonBase)chkBoxShowRamParam).UseVisualStyleBackColor = true;
			unSelectedParametersTreeView.AllowDragging = AllowDraggingEnum.None;
			unSelectedParametersTreeView.AllowSorting = AllowSortingEnum.MultiColumn;
			((Control)unSelectedParametersTreeView).Anchor = (AnchorStyles)15;
			unSelectedParametersTreeView.AutoSearch = AutoSearchEnum.FromTop;
			((Control)unSelectedParametersTreeView).BackColor = SystemColors.Window;
			unSelectedParametersTreeView.ColumnInfo = "10,0,0,0,0,75,Columns:";
			((Control)unSelectedParametersTreeView).Location = new Point(8, 165);
			((Control)unSelectedParametersTreeView).Name = "unSelectedParametersTreeView";
			unSelectedParametersTreeView.SelectionMode = SelectionModeEnum.Cell;
			unSelectedParametersTreeView.ShowButtons = ShowButtonsEnum.Always;
			((Control)unSelectedParametersTreeView).Size = new Size(432, 319);
			unSelectedParametersTreeView.Styles = new CellStyleCollection(componentResourceManager.GetString("unSelectedParametersTreeView.Styles"));
			((Control)unSelectedParametersTreeView).TabIndex = 41;
			unSelectedParametersTreeView.Tree.Column = 1;
			unSelectedParametersTreeView.AfterEdit += OnTreeViewAfterEdit;
			((Control)unSelectedParametersTreeView).KeyDown += new KeyEventHandler(OnTreeViewKeyDown);
			((Control)chkSearchComments).Anchor = (AnchorStyles)9;
			chkSearchComments.Checked = true;
			chkSearchComments.CheckState = (CheckState)1;
			((Control)chkSearchComments).Location = new Point(312, 32);
			((Control)chkSearchComments).Name = "chkSearchComments";
			((Control)chkSearchComments).Size = new Size(128, 21);
			((Control)chkSearchComments).TabIndex = 6;
			((Control)chkSearchComments).Text = "Search Comments";
			chkShowComment.CheckAlign = (ContentAlignment)1;
			chkShowComment.Checked = true;
			chkShowComment.CheckState = (CheckState)1;
			((Control)chkShowComment).Location = new Point(8, 108);
			((Control)chkShowComment).Name = "chkShowComment";
			((Control)chkShowComment).Size = new Size(114, 15);
			((Control)chkShowComment).TabIndex = 13;
			((Control)chkShowComment).Text = "Show Comments";
			chkShowComment.CheckedChanged += OnShowCommentCheckedChanged;
			((Control)buttonSearchStart).Anchor = (AnchorStyles)9;
			((Control)buttonSearchStart).Location = new Point(384, 8);
			((Control)buttonSearchStart).Name = "buttonSearchStart";
			((Control)buttonSearchStart).Size = new Size(56, 21);
			((Control)buttonSearchStart).TabIndex = 4;
			((Control)buttonSearchStart).Tag = "0";
			((Control)buttonSearchStart).Text = "&Search";
			((Control)buttonSearchStart).Click += OnQueryButtonClick;
			((Control)grpBoxSortBy).Controls.Add((Control)(object)radioBtnParameter);
			((Control)grpBoxSortBy).Controls.Add((Control)(object)radioBtnGroup);
			((Control)grpBoxSortBy).Controls.Add((Control)(object)radioBtnSubfile);
			((Control)grpBoxSortBy).Location = new Point(8, 56);
			((Control)grpBoxSortBy).Name = "grpBoxSortBy";
			((Control)grpBoxSortBy).Size = new Size(216, 46);
			((Control)grpBoxSortBy).TabIndex = 19;
			grpBoxSortBy.TabStop = false;
			((Control)grpBoxSortBy).Text = "Sort By";
			radioBtnParameter.Checked = true;
			((Control)radioBtnParameter).Location = new Point(128, 16);
			((Control)radioBtnParameter).Name = "radioBtnParameter";
			((Control)radioBtnParameter).Size = new Size(80, 24);
			((Control)radioBtnParameter).TabIndex = 12;
			radioBtnParameter.TabStop = true;
			((Control)radioBtnParameter).Text = "Parameter";
			radioBtnParameter.CheckedChanged += radioBtnParameter_CheckedChanged;
			((Control)radioBtnGroup).Location = new Point(72, 16);
			((Control)radioBtnGroup).Name = "radioBtnGroup";
			((Control)radioBtnGroup).Size = new Size(56, 24);
			((Control)radioBtnGroup).TabIndex = 11;
			((Control)radioBtnGroup).Text = "Group";
			radioBtnGroup.CheckedChanged += radioBtnGroup_CheckedChanged;
			((Control)radioBtnSubfile).Location = new Point(8, 16);
			((Control)radioBtnSubfile).Name = "radioBtnSubfile";
			((Control)radioBtnSubfile).Size = new Size(64, 24);
			((Control)radioBtnSubfile).TabIndex = 10;
			((Control)radioBtnSubfile).Text = "Subfile";
			radioBtnSubfile.CheckedChanged += radioBtnSubfile_CheckedChanged;
			((Control)grpBoxFilterFile).Anchor = (AnchorStyles)9;
			((Control)grpBoxFilterFile).Controls.Add((Control)(object)label1);
			((Control)grpBoxFilterFile).Controls.Add((Control)(object)txtFilterFileName);
			((Control)grpBoxFilterFile).Controls.Add((Control)(object)btnFilterClear);
			((Control)grpBoxFilterFile).Controls.Add((Control)(object)btnFilterSave);
			((Control)grpBoxFilterFile).Controls.Add((Control)(object)btnFilterOpen);
			((Control)grpBoxFilterFile).Controls.Add((Control)(object)labelFilterFileName);
			((Control)grpBoxFilterFile).Controls.Add((Control)(object)labelFilterFileApplied);
			((Control)grpBoxFilterFile).Location = new Point(224, 56);
			((Control)grpBoxFilterFile).Name = "grpBoxFilterFile";
			((Control)grpBoxFilterFile).Size = new Size(216, 72);
			((Control)grpBoxFilterFile).TabIndex = 18;
			grpBoxFilterFile.TabStop = false;
			((Control)grpBoxFilterFile).Text = "Filter File";
			((Control)label1).Location = new Point(8, 48);
			((Control)label1).Name = "label1";
			((Control)label1).Size = new Size(84, 20);
			((Control)label1).TabIndex = 28;
			((Control)label1).Text = "Filter Filename ";
			((Control)txtFilterFileName).Anchor = (AnchorStyles)15;
			((Control)txtFilterFileName).Location = new Point(98, 48);
			((Control)txtFilterFileName).Name = "txtFilterFileName";
			((Control)txtFilterFileName).Size = new Size(112, 20);
			((Control)txtFilterFileName).TabIndex = 29;
			((Control)btnFilterClear).Location = new Point(152, 16);
			((Control)btnFilterClear).Name = "btnFilterClear";
			((Control)btnFilterClear).Size = new Size(56, 23);
			((Control)btnFilterClear).TabIndex = 9;
			((Control)btnFilterClear).Text = "Clear";
			((Control)btnFilterClear).Click += OnFilterClearClicked;
			((Control)btnFilterSave).Location = new Point(80, 16);
			((Control)btnFilterSave).Name = "btnFilterSave";
			((Control)btnFilterSave).Size = new Size(56, 23);
			((Control)btnFilterSave).TabIndex = 8;
			((Control)btnFilterSave).Text = "Save";
			((Control)btnFilterSave).Click += OnFilterSaveClicked;
			((Control)btnFilterOpen).Location = new Point(8, 16);
			((Control)btnFilterOpen).Name = "btnFilterOpen";
			((Control)btnFilterOpen).Size = new Size(56, 23);
			((Control)btnFilterOpen).TabIndex = 7;
			((Control)btnFilterOpen).Text = "Open";
			((Control)btnFilterOpen).Click += OnFilterOpenClicked;
			((Control)labelFilterFileName).AutoSize = true;
			((Control)labelFilterFileName).Location = new Point(8, 48);
			((Control)labelFilterFileName).Name = "labelFilterFileName";
			((Control)labelFilterFileName).Size = new Size(0, 13);
			((Control)labelFilterFileName).TabIndex = 20;
			labelFilterFileName.TextAlign = (ContentAlignment)16;
			((Control)labelFilterFileApplied).AutoSize = true;
			((Control)labelFilterFileApplied).Location = new Point(96, 48);
			((Control)labelFilterFileApplied).Name = "labelFilterFileApplied";
			((Control)labelFilterFileApplied).Size = new Size(0, 13);
			((Control)labelFilterFileApplied).TabIndex = 21;
			labelFilterFileApplied.TextAlign = (ContentAlignment)16;
			((Control)buttonCollapse).Location = new Point(8, 131);
			((Control)buttonCollapse).Name = "buttonCollapse";
			((Control)buttonCollapse).Size = new Size(89, 24);
			((Control)buttonCollapse).TabIndex = 22;
			((Control)buttonCollapse).Text = "Collapse";
			((Control)buttonCollapse).Click += OnCollapse;
			((Control)this).Controls.Add((Control)(object)labelSearchString);
			((Control)this).Controls.Add((Control)(object)panel1);
			((Control)this).Name = "ParameterQuery";
			((Control)this).Size = new Size(456, 500);
			((Control)this).VisibleChanged += OnVisibleChanged;
			((Control)this).Resize += OnResizeParameterQuery;
			((Control)panel1).ResumeLayout(false);
			((ISupportInitialize)unSelectedParametersTreeView).EndInit();
			((Control)grpBoxSortBy).ResumeLayout(false);
			((Control)grpBoxFilterFile).ResumeLayout(false);
			((Control)grpBoxFilterFile).PerformLayout();
			((Control)this).ResumeLayout(false);
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing)
			{
				if (components != null)
				{
					components.Dispose();
					components = null;
				}
				if (parameterList != null)
				{
					parameterList.Dispose();
					parameterList = null;
				}
				if (_parameterListViewData.CurrentParamLookup != null)
				{
					_parameterListViewData.CurrentParamLookup.Clear();
					_parameterListViewData.CurrentParamLookup = null;
				}
			}
			((ContainerControl)this).Dispose(disposing);
		}

		private void radioBtnParameter_CheckedChanged(object sender, EventArgs e)
		{
			CurrentSortType = ParameterSortType.ParameterName;
		}

		private void radioBtnGroup_CheckedChanged(object sender, EventArgs e)
		{
			CurrentSortType = ParameterSortType.Group;
		}

		private void radioBtnSubfile_CheckedChanged(object sender, EventArgs e)
		{
			CurrentSortType = ParameterSortType.Subfile;
		}

		protected string SelectAllMatching(string text)
		{
			string result = string.Empty;
			foreach (Row item in (IEnumerable)unSelectedParametersTreeView.Rows.Selected)
			{
				item.Selected = false;
			}
			foreach (Row item2 in (IEnumerable)unSelectedParametersTreeView.Rows)
			{
				if (item2[1].ToString().ToUpper().StartsWith(text))
				{
					item2.Selected = true;
					unSelectedParametersTreeView.Select(item2.Index, 1, show: true);
					unSelectedParametersTreeView.TopRow = item2.Index;
					result = item2[1].ToString();
					break;
				}
			}
			return result;
		}

		protected void OnComboBoxQueryStringKeyUp(object sender, KeyEventArgs e)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_000f: Invalid comparison between Unknown and I4
			//IL_0081: Unknown result type (might be due to invalid IL or missing references)
			//IL_0088: Invalid comparison between Unknown and I4
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Invalid comparison between Unknown and I4
			ComboBox val = (ComboBox)((sender is ComboBox) ? sender : null);
			if ((int)e.KeyData != 46 && (int)e.KeyData != 8 && ((Control)val).Text != string.Empty)
			{
				string text = SelectAllMatching(((Control)val).Text.ToUpper());
				if (text != string.Empty && text != ((Control)val).Text)
				{
					string text2 = ((Control)val).Text;
					((Control)val).Text = text;
					val.Select(text2.Length, text.Length - text2.Length);
				}
			}
			if ((int)e.KeyData == 13)
			{
				OnQueryButtonClick(sender, (EventArgs)(object)e);
			}
		}

		protected void OnCopyClick(object sender, EventArgs e)
		{
			Copy(unSelectedParametersTreeView.Clip);
		}

		protected void Copy(string clipBoardData)
		{
			try
			{
				SafeClipBoard safeClipBoard = new SafeClipBoard();
				safeClipBoard.SetDataToClipBoard(clipBoardData);
			}
			catch
			{
			}
		}

		private void RecursiveSelect(bool isIncludeComplexParameter, Node node, CheckEnum checkValue)
		{
			bool flag = false;
			while (node != null)
			{
				if (isIncludeComplexParameter)
				{
					flag = true;
				}
				else
				{
					IParamInfo paramInfo = parameterList[node.Data.ToString()];
					flag = ((!paramInfo.IsTable && !parameterList.Structure.Contains(node.Data.ToString())) ? true : false);
				}
				if (flag)
				{
					DoSelect(node.Row.Index, checkValue);
					if (node.GetNode(NodeTypeEnum.FirstChild) != null)
					{
						DoSelect(node.GetNode(NodeTypeEnum.FirstChild).Row.Index, checkValue);
						RecursiveSelect(isIncludeComplexParameter, node.GetNode(NodeTypeEnum.FirstChild), checkValue);
					}
				}
				node = node.GetNode(NodeTypeEnum.NextSibling);
			}
		}

		protected virtual void PopulateTree(C1FlexGrid treeView, bool isSelected, ParameterSelectionCriteria selectionCriteria)
		{
			Cursor current = Cursor.Current;
			Cursor.Current = Cursors.WaitCursor;
			try
			{
				if (parameterList == null || (treeView.Rows.Count <= 0 && isSelected))
				{
					return;
				}
				BuildTreeView(treeView, CurrentSortType, isSelected, null, selectionCriteria, null);
				int count = treeView.Rows.Count;
				StringCollection selectedParameters = parameterList.SelectedParameters;
				for (int i = 1; i < count; i++)
				{
					string text = treeView.Rows[i].Node.Data.ToString();
					GrayOutParameter(treeView, text, i);
					if (selectedParameters.Contains(text))
					{
						treeView.SetCellCheck(i, 1, CheckEnum.Checked);
						if (parameterList.IsStructure(text))
						{
							for (Node node = treeView.Rows[i].Node.GetNode(NodeTypeEnum.FirstChild); node != null; node = node.GetNode(NodeTypeEnum.NextSibling))
							{
								i++;
								treeView.SetCellCheck(node.Row.Index, 1, CheckEnum.Checked);
							}
						}
					}
					else
					{
						treeView.SetCellCheck(i, 1, CheckEnum.Unchecked);
					}
				}
			}
			finally
			{
				Cursor.Current = current;
			}
		}

		private void GrayOutParameter(C1FlexGrid treeView, string parameterName, int index)
		{
			if (ShouldGrayOutParameter(parameterName))
			{
				treeView.Rows[index].StyleNew.BackColor = SystemColors.GrayText;
				treeView.Rows[index].StyleNew.ForeColor = SystemColors.WindowText;
				return;
			}
			Node node = treeView.Rows[index].Node.GetNode(NodeTypeEnum.Parent);
			if (node != null && ShouldGrayOutParameter(node.Data.ToString()))
			{
				treeView.Rows[index].StyleNew.BackColor = SystemColors.GrayText;
				treeView.Rows[index].StyleNew.ForeColor = SystemColors.WindowText;
			}
		}

		private bool ShouldGrayOutParameter(string parameterName)
		{
			bool result = false;
			if (parameterList.IsParameterValid(parameterName) && ((parameterList.Parameters[parameterName].IsRuntime && isDataSourceOffline) || parameterList.Parameters[parameterName].IsCodeTypeParameter))
			{
				result = true;
			}
			return result;
		}

		private void DoSelect(int row, CheckEnum checkValue)
		{
			if (row > 1)
			{
				string paramName = unSelectedParametersTreeView[row, 1].ToString();
				parameterList.SetSelectedStatus(paramName, checkValue == CheckEnum.Checked);
				unSelectedParametersTreeView.SetCellCheck(row, 1, checkValue);
			}
		}

		private void DoCheck(int row, CheckEnum checkValue)
		{
			if (row > 1)
			{
				unSelectedParametersTreeView[row, 1].ToString();
				unSelectedParametersTreeView.SetCellCheck(row, 1, checkValue);
			}
		}

		private void UpdateParameterSelection(int selectedRowIndex)
		{
			bool isIncludeComplexParameter = true;
			if (!handledByEnter)
			{
				Node node = unSelectedParametersTreeView.Rows[selectedRowIndex].Node;
				Node node2 = node.GetNode(NodeTypeEnum.Parent);
				if (node2 != null && !parameterList.IsStructure(node2.Data.ToString()))
				{
					DoSelect(selectedRowIndex, unSelectedParametersTreeView.GetCellCheck(selectedRowIndex, 1));
				}
				IParamInfo paramInfo = parameterList[node.Data.ToString()];
				if (paramInfo == null)
				{
					if (node.Data.ToString().Equals("Subfiles") || node.Data.ToString().Equals("All Parameters") || node.Data.ToString().Equals("Groups"))
					{
						isIncludeComplexParameter = true;
					}
					else if (parameterList.Groups.Contains(node.Data.ToString()))
					{
						isIncludeComplexParameter = false;
					}
				}
				else
				{
					isIncludeComplexParameter = true;
				}
				if (node.GetNode(NodeTypeEnum.FirstChild) != null)
				{
					if (parameterList.IsStructure(node.Data.ToString()))
					{
						Node node3 = node.GetNode(NodeTypeEnum.FirstChild);
						if (node3 == null)
						{
							node3 = node;
						}
						while (node3 != null)
						{
							DoCheck(node3.Row.Index, unSelectedParametersTreeView.GetCellCheck(selectedRowIndex, 1));
							node3 = node3.GetNode(NodeTypeEnum.NextSibling);
						}
					}
					else
					{
						RecursiveSelect(isIncludeComplexParameter, node.GetNode(NodeTypeEnum.FirstChild), unSelectedParametersTreeView.GetCellCheck(selectedRowIndex, 1));
					}
				}
				else
				{
					if (node2 == null)
					{
						return;
					}
					Node node4 = node2.GetNode(NodeTypeEnum.Parent);
					if (node4 == null)
					{
						return;
					}
					if (!node4.Data.ToString().ToUpper().StartsWith("SUBFILE") && !node4.Data.ToString().ToUpper().StartsWith("GROUPS"))
					{
						DoSelect(node2.Row.Index, unSelectedParametersTreeView.GetCellCheck(selectedRowIndex, 1));
						Node node5 = node.GetNode(NodeTypeEnum.FirstSibling);
						if (node5 == null)
						{
							node5 = node;
						}
						while (node5 != null)
						{
							DoSelect(node5.Row.Index, unSelectedParametersTreeView.GetCellCheck(selectedRowIndex, 1));
							node5 = node5.GetNode(NodeTypeEnum.NextSibling);
						}
					}
					else if (parameterList.IsStructure(node2.Data.ToString()))
					{
						DoSelect(node2.Row.Index, unSelectedParametersTreeView.GetCellCheck(selectedRowIndex, 1));
						Node node6 = node.GetNode(NodeTypeEnum.FirstSibling);
						if (node6 == null)
						{
							node6 = node;
						}
						while (node6 != null)
						{
							DoCheck(node6.Row.Index, unSelectedParametersTreeView.GetCellCheck(selectedRowIndex, 1));
							node6 = node6.GetNode(NodeTypeEnum.NextSibling);
						}
					}
				}
			}
			else
			{
				handledByEnter = false;
				unSelectedParametersTreeView.SetCellCheck(selectedRowIndex, 1, CheckEnum.Unchecked);
			}
		}

		private void OnTreeViewAfterEdit(object sender, RowColEventArgs e)
		{
			UpdateParameterSelection(e.Row);
		}

		protected virtual void OnShowCommentCheckedChanged(object sender, EventArgs e)
		{
			unSelectedParametersTreeView.Cols[2].Visible = chkShowComment.Checked;
			showComment = chkShowComment.Checked;
			if (!chkShowComment.Checked)
			{
				unSelectedParametersTreeView.Cols[1].Width = ((Control)unSelectedParametersTreeView).Width;
			}
			else
			{
				unSelectedParametersTreeView.Cols[1].Width = parameterNameColWidth;
			}
		}

		public void BuildTreeView(C1FlexGrid treeView, ParameterSortType sortType, bool selectedStatus, string focusNodeName, ParameterSelectionCriteria selectionCriteria, string queryString)
		{
			_parameterListViewData.CurrentParamLookup.Clear();
			foreach (string key in parameterList.Parameters.Keys)
			{
				IParamInfo paramInfo = parameterList[key];
				if (paramInfo.IsPublicDataType || -1 != paramInfo.FullName.IndexOf("ConfigHeaders."))
				{
					continue;
				}
				if (queryString != null && queryString.Trim() != string.Empty)
				{
					bool flag = false;
					if (key.ToLower().IndexOf(queryString.ToLower()) > -1 || (searchComments && paramInfo.Comment.ToLower().IndexOf(queryString.ToLower()) > -1))
					{
						flag = true;
					}
					else if (paramInfo.IsTable && paramInfo.TableAxisInfo != null)
					{
						if (paramInfo.TableAxisInfo.XAxisName.ToLower().IndexOf(queryString.ToLower()) > -1 || paramInfo.TableAxisInfo.YAxisName.ToLower().IndexOf(queryString.ToLower()) > -1)
						{
							flag = true;
						}
						else if (searchComments)
						{
							IParamInfo paramInfo2 = parameterList[paramInfo.TableAxisInfo.XAxisName];
							IParamInfo paramInfo3 = parameterList[paramInfo.TableAxisInfo.YAxisName];
							if ((paramInfo2 != null && paramInfo2.Comment.ToLower().IndexOf(queryString.ToLower()) > -1) || (paramInfo3 != null && paramInfo3.Comment.ToLower().IndexOf(queryString.ToLower()) > -1))
							{
								flag = true;
							}
						}
					}
					if (!flag)
					{
						continue;
					}
				}
				if ((selectionCriteria != ParameterSelectionCriteria.HideInterface || !key.StartsWith("_")) && (selectionCriteria != ParameterSelectionCriteria.ShowInterface || key.StartsWith("_")) && (IncludeStructureParameter || !parameterList.IsStructure(key)) && (!paramInfo.IsRuntime || (parameterList.IncludeRuntimeParameters && showRamParameters)) && (Subfile3ParametersAddType.ExcludeAll != parameterList.Subfile3Parameters || !paramInfo.SubfileName.Equals("3")) && (!paramInfo.FullName.StartsWith("Config") || parameterList.Subfile3Parameters != Subfile3ParametersAddType.ExcludeCode || !paramInfo.IsCodeTypeParameter) && (showAllParameters || paramInfo.IsSelected == selectedStatus))
				{
					_parameterListViewData.CurrentParamLookup.Add(key, null);
				}
			}
			BuildTreeView(treeView, sortType, focusNodeName);
		}

		public void BuildTreeView(C1FlexGrid treeView, ParameterSortType sortType, string focusNodeName)
		{
			//IL_00b9: Unknown result type (might be due to invalid IL or missing references)
			if (treeView.Cols[1].Width != -1)
			{
				parameterNameColWidth = treeView.Cols[1].Width;
				parameterCommentColWidth = treeView.Cols[2].Width;
			}
			treeView.Clear();
			rowIndex = 1;
			_parameterListViewData.CurrentFocusNodeName = focusNodeName;
			treeView.Cols[2].Visible = showComment;
			try
			{
				switch (sortType)
				{
				case ParameterSortType.ParameterName:
					BuildParameterView(treeView);
					break;
				case ParameterSortType.Group:
					BuildGroupView(treeView);
					break;
				default:
					BuildSubfileView(treeView);
					break;
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show("Error - Failed to build tree view. (" + ex.Message + ")");
			}
		}

		private void BuildParameterView(C1FlexGrid treeView)
		{
			treeView.Rows.RemoveRange(0, treeView.Rows.Count - 1);
			BuildParentNode(treeView);
			_ = treeView.Rows[1].Node;
			treeView.Rows[1].Node.Level = 0;
			treeView.Rows.InsertRange(treeView.Rows.Count, MaxParameterRowCount);
			foreach (string key in _parameterListViewData.CurrentParamLookup.Keys)
			{
				if (!parameterList.Structure.ContainsKey(key))
				{
					AddParameterNode(treeView, key, 1, null, isStructureMember: false);
				}
				else
				{
					AddGroupNode(treeView, key, 1, null);
				}
			}
			treeView.Rows.RemoveRange(rowIndex + 1, treeView.Rows.Count - 1 - rowIndex);
		}

		private void BuildGroupView(C1FlexGrid treeView)
		{
			treeView.Rows.RemoveRange(0, treeView.Rows.Count - 1);
			BuildParentNode(treeView);
			Node node = treeView.Rows[1].Node;
			treeView.Rows[1].Node.Level = 0;
			treeView.Rows.InsertRange(treeView.Rows.Count, MaxParameterRowCount);
			int level = 1;
			foreach (string key in parameterList.Groups.Keys)
			{
				AddGroupNode(treeView, key, level, null);
			}
			foreach (string key2 in parameterList.Structure.Keys)
			{
				AddGroupNode(treeView, key2, level, null);
			}
			treeView.Rows.RemoveRange(rowIndex + 1, treeView.Rows.Count - 1 - rowIndex);
			for (Node node2 = node.GetNode(NodeTypeEnum.FirstChild); node2 != null; node2 = node2.GetNode(NodeTypeEnum.NextSibling))
			{
				node2.Sort(SortFlags.Ascending);
			}
			node.Sort(SortFlags.Ascending);
		}

		protected void BuildParentNode(C1FlexGrid treeView)
		{
			//IL_00c8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d2: Expected O, but got Unknown
			string value = "All Parameters";
			if (CurrentSortType == ParameterSortType.Group)
			{
				value = "Groups";
			}
			else if (CurrentSortType == ParameterSortType.Subfile)
			{
				value = "Subfiles";
			}
			treeView.Cols[0].Width = 0;
			treeView.Cols[1].Width = parameterNameColWidth;
			treeView.Cols[2].Width = parameterCommentColWidth;
			if (treeView.Rows.Count == 1)
			{
				treeView.Rows.Add();
			}
			treeView.Rows[0].StyleNew.Font = new Font(treeView.Rows[0].Style.Font.FontFamily, treeView.Rows[0].Style.Font.Size, (FontStyle)1);
			treeView.Rows[0].TextAlign = TextAlignEnum.CenterCenter;
			treeView[0, 1] = "Parameter Name";
			treeView[0, 2] = "Comments";
			treeView.Rows[1].IsNode = false;
			treeView[1, 1] = value;
			treeView[1, 2] = "Comments";
			treeView.Rows[1].IsNode = true;
			treeView.Rows[1].Node.Level = 0;
			treeView.SetCellCheck(1, 1, CheckEnum.Unchecked);
		}

		protected void BuildSubfileView(C1FlexGrid treeView)
		{
			treeView.Rows.RemoveRange(0, treeView.Rows.Count - 1);
			BuildParentNode(treeView);
			Node node = treeView.Rows[1].Node;
			treeView.Rows[1].Node.Level = 0;
			treeView.Rows.InsertRange(treeView.Rows.Count, MaxParameterRowCount);
			int num = 1;
			foreach (string key in parameterList.Subfile.Keys)
			{
				if (parameterList.Subfile3Parameters == Subfile3ParametersAddType.ExcludeAll && key.Equals("3"))
				{
					continue;
				}
				string empty = string.Empty;
				empty = ((!key.Equals("-1")) ? ("Subfile " + key) : "Subfile");
				rowIndex++;
				int num2 = rowIndex;
				treeView.Rows[rowIndex].IsNode = true;
				treeView.Rows[rowIndex].Node.Level = num;
				treeView[rowIndex, 1] = empty;
				_ = treeView.Rows[rowIndex].Node;
				StringCollection stringCollection = (StringCollection)parameterList.Subfile[key];
				StringEnumerator enumerator2 = stringCollection.GetEnumerator();
				try
				{
					while (enumerator2.MoveNext())
					{
						string current = enumerator2.Current;
						AddGroupNode(treeView, current, num + 1, key);
					}
				}
				finally
				{
					if (enumerator2 is IDisposable disposable)
					{
						disposable.Dispose();
					}
				}
				if (num2 == rowIndex)
				{
					rowIndex--;
				}
			}
			treeView.Rows.RemoveRange(rowIndex + 1, treeView.Rows.Count - 1 - rowIndex);
			for (Node node2 = node.GetNode(NodeTypeEnum.FirstChild); node2 != null; node2 = node2.GetNode(NodeTypeEnum.NextSibling))
			{
				for (Node node3 = node2.GetNode(NodeTypeEnum.FirstChild); node3 != null; node3 = node3.GetNode(NodeTypeEnum.NextSibling))
				{
					node3.Sort(SortFlags.Ascending);
				}
				node2.Sort(SortFlags.Ascending);
			}
			node.Sort(SortFlags.Ascending);
		}

		protected void AddGroupNode(C1FlexGrid treeView, string groupName, int level, string subfileName)
		{
			rowIndex++;
			int num = rowIndex;
			bool isStructureMember = false;
			treeView.Rows[rowIndex].IsNode = true;
			treeView.Rows[rowIndex].Node.Level = level;
			treeView[rowIndex, 1] = groupName;
			_ = treeView.Rows[rowIndex].Node;
			StringCollection stringCollection = new StringCollection();
			if (parameterList.GetGroupInfo(groupName) != null)
			{
				stringCollection = parameterList.GetGroupInfo(groupName).ParameterList;
				isStructureMember = false;
			}
			else if (_parameterListViewData.CurrentParamLookup.ContainsKey(groupName) || groupName == "DataplateStructure")
			{
				stringCollection = parameterList.GetStructInfo(groupName).ParameterList;
				if (groupName != "DataplateStructure")
				{
					isStructureMember = true;
				}
			}
			StringEnumerator enumerator = stringCollection.GetEnumerator();
			try
			{
				while (enumerator.MoveNext())
				{
					string current = enumerator.Current;
					AddParameterNode(treeView, current, level + 1, subfileName, isStructureMember);
				}
			}
			finally
			{
				if (enumerator is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
			if (num == rowIndex)
			{
				rowIndex--;
			}
		}

		protected void AddParameterNode(C1FlexGrid treeView, string paramName, int level, string subfileName, bool isStructureMember)
		{
			try
			{
				if (isStructureMember && parameterList.StructureMemberList[paramName] != null)
				{
					IStructureMemberInfo structureMemberInfo = parameterList.StructureMemberList[paramName];
					rowIndex++;
					treeView.Rows[rowIndex].IsNode = true;
					treeView.Rows[rowIndex].Node.Level = level;
					treeView[rowIndex, 1] = structureMemberInfo.Name;
					treeView[rowIndex, 2] = structureMemberInfo.Comment;
				}
				else
				{
					if (!_parameterListViewData.CurrentParamLookup.ContainsKey(paramName))
					{
						return;
					}
					IParamInfo paramInfo = parameterList[paramName];
					if ((parameterList.IncludeRuntimeParameters || !paramInfo.IsRuntime) && (paramInfo.IsTable || !paramInfo.IsAxis) && (subfileName == null || paramInfo.SubfileName.Equals(subfileName)))
					{
						rowIndex++;
						treeView.Rows[rowIndex].IsNode = true;
						treeView.Rows[rowIndex].Node.Level = level;
						treeView[rowIndex, 1] = paramName;
						treeView[rowIndex, 2] = paramInfo.Comment;
						if (paramInfo.IsTable && paramInfo.TableAxisInfo != null)
						{
							AddAxisChildNode(treeView, paramInfo.TableAxisInfo.XAxisName, level + 1);
							AddAxisChildNode(treeView, paramInfo.TableAxisInfo.YAxisName, level + 1);
						}
					}
				}
			}
			catch (Exception)
			{
			}
		}

		protected void AddAxisChildNode(C1FlexGrid treeView, string axisName, int level)
		{
			if (axisName.Length > 0)
			{
				rowIndex++;
				IParamInfo paramInfo = parameterList[axisName];
				treeView.Rows[rowIndex].IsNode = true;
				treeView[rowIndex, 1] = axisName;
				treeView.Rows[rowIndex].Node.Level = level;
				treeView[rowIndex, 2] = paramInfo.Comment;
				treeView.Rows[rowIndex].Node.Key = "Axis";
			}
		}

		protected void Collapse(C1FlexGrid treeView)
		{
			if (treeView.Row <= 0)
			{
				return;
			}
			Node node = ((treeView.Row != 1) ? treeView.Rows[treeView.Row].Node : ((treeView.Rows.Count <= 2) ? treeView.Rows[treeView.Row].Node : treeView.Rows[treeView.Row + 1].Node));
			if (node != null)
			{
				Node node2 = node.GetNode(NodeTypeEnum.FirstSibling);
				if (node2 == null)
				{
					node2 = node;
				}
				while (node2 != null)
				{
					node2.Collapsed = true;
					node2 = node2.GetNode(NodeTypeEnum.NextSibling);
				}
			}
		}

		private void OnCollapse(object sender, EventArgs e)
		{
			Collapse(unSelectedParametersTreeView);
		}

		private void RaiseAddParameterOnEnterEvent()
		{
			if (this.AddParameterOnEnterEvent != null)
			{
				this.AddParameterOnEnterEvent(this, EventArgs.Empty);
			}
		}

		private void OnTreeViewKeyDown(object sender, KeyEventArgs e)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0008: Invalid comparison between Unknown and I4
			//IL_0041: Unknown result type (might be due to invalid IL or missing references)
			//IL_0048: Invalid comparison between Unknown and I4
			if ((int)e.KeyData == 13)
			{
				int rowSel = unSelectedParametersTreeView.RowSel;
				unSelectedParametersTreeView.SetCellCheck(rowSel, 1, CheckEnum.Checked);
				UpdateParameterSelection(rowSel);
				RaiseAddParameterOnEnterEvent();
				handledByEnter = true;
				e.Handled = true;
			}
			else if ((int)e.KeyCode == 67 && e.Control)
			{
				Copy(unSelectedParametersTreeView.Clip);
				e.Handled = true;
			}
			else
			{
				e.Handled = false;
			}
		}

		private void OnResizeParameterQuery(object sender, EventArgs e)
		{
			unSelectedParametersTreeView.Cols[2].Width = ((Control)unSelectedParametersTreeView).Width - unSelectedParametersTreeView.Cols[1].Width;
		}

		protected virtual void OnSelectionCriteriaChanged(object sender, EventArgs e)
		{
			ComboBox val = (ComboBox)((sender is ComboBox) ? sender : null);
			if (((ListControl)val).SelectedIndex != (int)parameterSelectionCriteria)
			{
				parameterSelectionCriteria = (ParameterSelectionCriteria)((ListControl)val).SelectedIndex;
				PopulateTree(unSelectedParametersTreeView, ParameterFilterMode == ParameterFilterMode.Include, parameterSelectionCriteria);
			}
		}

		private void OnVisibleChanged(object sender, EventArgs e)
		{
			if (((Control)this).Visible)
			{
				((Control)cmbBoxSearchSring).Select();
			}
		}

		private void OnDisplayRamParamCheckChanged(object sender, EventArgs e)
		{
			showRamParameters = chkBoxShowRamParam.Checked;
			PopulateTree(unSelectedParametersTreeView, ParameterFilterMode == ParameterFilterMode.Include, parameterSelectionCriteria);
		}

		public bool LoadFilter(string fileName, bool accessFromCLI, ref string result)
		{
			//IL_0295: Unknown result type (might be due to invalid IL or missing references)
			if (fileName == null || fileName.Length == 0 || !File.Exists(fileName))
			{
				parameterList.ResetSelectionStatus(selectionStatus: false);
				return false;
			}
			if (fileName.ToLower().EndsWith(".xml"))
			{
				return LoadFilter_1xStyle(fileName);
			}
			bool result2 = true;
			List<string> list = new List<string>();
			StreamReader streamReader = new StreamReader(fileName);
			try
			{
				string text = streamReader.ReadLine();
				try
				{
					ParameterFilterMode = (ParameterFilterMode)Enum.Parse(typeof(ParameterFilterMode), text, ignoreCase: true);
					text = streamReader.ReadLine();
				}
				catch
				{
					ParameterFilterMode = ParameterFilterMode.Include;
				}
				parameterList.ResetSelectionStatus(selectionStatus: false);
				string text2 = string.Empty;
				int num = 0;
				while (text != null)
				{
					if (text.Trim() != string.Empty && !text.StartsWith(";"))
					{
						list.Add(text.Trim());
					}
					text = streamReader.ReadLine();
				}
				List<string> list2 = list;
				foreach (string item2 in list2)
				{
					bool flag = false;
					if (parameterList.IsParameterValid(item2))
					{
						IParamInfo paramInfo = parameterList.Parameters[item2];
						if (paramInfo.ParameterType == "ArrayXAxis")
						{
							IParamInfoList tableNames = parameterList.GetTableNames(item2);
							foreach (string key in tableNames.Keys)
							{
								if (list.Contains(key))
								{
									flag = true;
									break;
								}
							}
							if (!flag)
							{
								num++;
								object obj2 = text2;
								text2 = string.Concat(obj2, num, ". ", item2, "  (Related y/z axis parameter is missing in filter file)", Environment.NewLine);
							}
						}
						parameterList.SetSelectedStatus(item2, selectedStatus: true);
					}
					else
					{
						num++;
						object obj3 = text2;
						text2 = string.Concat(obj3, num, ". ", item2, "  (Not available in the data source)", Environment.NewLine);
					}
				}
				if (!string.IsNullOrEmpty(text2))
				{
					string message = "Following parameters from filter file were not being used.";
					if (!accessFromCLI)
					{
						MsgBox.Show(message, "Filter file Parameters", text2, MsgBoxButtons.OK, MsgBoxIcon.Information);
					}
					else
					{
						result = text2;
					}
				}
			}
			catch (Exception ex)
			{
				if (!accessFromCLI)
				{
					MessageBox.Show((IWin32Window)(object)this, "Failed to load filter named '" + fileName + "'.\nDetails: " + ex.Message);
				}
				result2 = false;
			}
			finally
			{
				streamReader.Close();
			}
			return result2;
		}

		protected void OnFilterOpenClicked(object sender, EventArgs e)
		{
			OnFilterOpen(sender, e);
			((Control)txtFilterFileName).Text = Path.GetFileName(filterFilePath);
		}

		protected void OnFilterOpen(object sender, EventArgs e)
		{
			//IL_004c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0052: Invalid comparison between Unknown and I4
			string result = "";
			SafeOpenFileDialog safeOpenFileDialog = new SafeOpenFileDialog();
			string initialDirectory = directoryService.FolderName(FolderType.Product, currentProduct);
			safeOpenFileDialog.Filter = "Filter Files (*.flt.txt)|*.flt.txt|All files (*.*)|*.*";
			safeOpenFileDialog.InitialDirectory = initialDirectory;
			safeOpenFileDialog.FileName = filterFilePath;
			safeOpenFileDialog.FilterIndex = 0;
			safeOpenFileDialog.RestoreDirectory = true;
			if ((int)safeOpenFileDialog.ShowDialog() == 1 && LoadFilter(safeOpenFileDialog.FileName, accessFromCLI: false, ref result))
			{
				filterFilePath = safeOpenFileDialog.FileName;
				appConfigService.SetLastUsedValue(currentProduct, safeOpenFileDialog.FileName, LastUsedType.LastFilterFile);
				LoadTreeAfterFilter();
			}
		}

		protected virtual void LoadTreeAfterFilter()
		{
			showAllParameters = false;
			PopulateTree(unSelectedParametersTreeView, ParameterFilterMode == ParameterFilterMode.Include, parameterSelectionCriteria);
		}

		protected virtual void OnFilterClearClicked(object sender, EventArgs e)
		{
			OnFilterClear(sender, e);
			((Control)txtFilterFileName).Text = "";
		}

		protected virtual void OnFilterClear(object sender, EventArgs e)
		{
			ParameterFilterMode = ParameterFilterMode.Include;
			showAllParameters = true;
			parameterList.ResetSelectionStatus(selectionStatus: false);
			appConfigService.SetLastUsedValue(currentProduct, "", LastUsedType.LastFilterFile);
			PopulateTree(unSelectedParametersTreeView, isSelected: false, parameterSelectionCriteria);
		}

		protected void OnFilterSaveClicked(object sender, EventArgs eArgs)
		{
			OnFilterSave(sender, eArgs);
			((Control)txtFilterFileName).Text = Path.GetFileName(filterFilePath);
		}

		protected void OnFilterSave(object sender, EventArgs eArgs)
		{
			//IL_0077: Unknown result type (might be due to invalid IL or missing references)
			//IL_007d: Invalid comparison between Unknown and I4
			SafeSaveFileDialog safeSaveFileDialog = new SafeSaveFileDialog();
			directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
			string initialDirectory = directoryService.FolderName(FolderType.Product, currentProduct);
			safeSaveFileDialog.Filter = "Filter Files (*.flt.txt)|*.flt.txt|All files (*.*)|*.*";
			safeSaveFileDialog.InitialDirectory = initialDirectory;
			safeSaveFileDialog.FileName = filterFilePath;
			safeSaveFileDialog.FilterIndex = 0;
			safeSaveFileDialog.RestoreDirectory = true;
			safeSaveFileDialog.AddExtension = true;
			safeSaveFileDialog.DefaultExt = ".flt.txt";
			if ((int)safeSaveFileDialog.ShowDialog() == 1 && SaveFilter(safeSaveFileDialog.FileName))
			{
				appConfigService.SetLastUsedValue(currentProduct, safeSaveFileDialog.FileName, LastUsedType.LastFilterFile);
				filterFilePath = safeSaveFileDialog.FileName;
			}
		}

		private bool LoadFilter_1xStyle(string fileName)
		{
			//IL_0110: Unknown result type (might be due to invalid IL or missing references)
			bool result = true;
			try
			{
				string name = "Cummins.ParameterSelector.FilterFile.xsd";
				Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream(name);
				if (manifestResourceStream == null)
				{
					throw new NullReferenceException("Failed to Initialize FilterFile DataSet");
				}
				DataSet dataSet = new DataSet("FilterFile");
				dataSet.ReadXmlSchema(manifestResourceStream);
				dataSet.ReadXml(fileName);
				DataSet dataSet2 = dataSet;
				parameterList.ResetSelectionStatus(selectionStatus: false);
				foreach (DataRow row in dataSet2.Tables["Parameter"].Rows)
				{
					string paramName = row["Name"].ToString();
					parameterList.SetSelectedStatus(paramName, selectedStatus: true);
				}
				DataRow dataRow2 = dataSet2.Tables["Mode"].Rows[0];
				ParameterFilterMode = ((!(bool)dataRow2["Include"]) ? ParameterFilterMode.Exclude : ParameterFilterMode.Include);
			}
			catch (Exception ex)
			{
				MessageBox.Show((IWin32Window)(object)this, "Failed to load filter named '" + fileName + "'.\nDetails: " + ex.Message);
				result = false;
			}
			return result;
		}

		private bool SaveFilter(string fileName)
		{
			//IL_009e: Unknown result type (might be due to invalid IL or missing references)
			bool result = true;
			fileName += (fileName.EndsWith(".flt.txt") ? "" : ".flt.txt");
			StreamWriter streamWriter = new StreamWriter(fileName, append: false);
			try
			{
				streamWriter.WriteLine(ParameterFilterMode.ToString());
				StringEnumerator enumerator = parameterList.SelectedParameters.GetEnumerator();
				try
				{
					while (enumerator.MoveNext())
					{
						string current = enumerator.Current;
						streamWriter.WriteLine(current);
					}
				}
				finally
				{
					if (enumerator is IDisposable disposable)
					{
						disposable.Dispose();
					}
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show((IWin32Window)(object)this, "Failed to save filter named '" + fileName + "'.\nDetails: " + ex.Message);
				result = false;
			}
			finally
			{
				streamWriter.Close();
			}
			return result;
		}

		private StringCollection GetOrderedParameterList(StringCollection paramList, ParameterSortType sortType)
		{
			StringCollection stringCollection = new StringCollection();
			for (int i = 2; i < unSelectedParametersTreeView.Rows.Count; i++)
			{
				if (unSelectedParametersTreeView.GetCellCheck(i, 1) == CheckEnum.Checked && paramList.Contains(unSelectedParametersTreeView[i, 1].ToString()))
				{
					stringCollection.Add(unSelectedParametersTreeView[i, 1].ToString());
				}
			}
			return stringCollection;
		}

		public void ClearAll()
		{
			int count = unSelectedParametersTreeView.Rows.Count;
			StringEnumerator enumerator = parameterList.SelectedParameters.GetEnumerator();
			try
			{
				while (enumerator.MoveNext())
				{
					string current = enumerator.Current;
					parameterList[current].IsSelected = false;
				}
			}
			finally
			{
				if (enumerator is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
			parameterList.SelectedParameters.Clear();
			for (int i = 1; i < count; i++)
			{
				unSelectedParametersTreeView.SetCellCheck(i, 1, CheckEnum.Unchecked);
			}
		}

		private void OnQueryButtonClick(object sender, EventArgs e)
		{
			queryString = ((Control)cmbBoxSearchSring).Text;
			searchComments = chkSearchComments.Checked;
			QueryFromTree(ParameterFilterMode == ParameterFilterMode.Include);
			AddToQueryList(cmbBoxSearchSring, queryString);
		}

		protected void QueryFromTree(bool selectedStatus)
		{
			Cursor current = Cursor.Current;
			Cursor.Current = Cursors.WaitCursor;
			BuildTreeView(unSelectedParametersTreeView, CurrentSortType, selectedStatus, null, parameterSelectionCriteria, queryString);
			StringCollection orderedParameterList = GetOrderedParameterList(parameterList.SelectedParameters, currentSortType);
			for (int i = 1; i < unSelectedParametersTreeView.Rows.Count; i++)
			{
				string text = unSelectedParametersTreeView.Rows[i].Node.Data.ToString();
				GrayOutParameter(unSelectedParametersTreeView, text, i);
				if (orderedParameterList.Contains(text))
				{
					unSelectedParametersTreeView.SetCellCheck(i, 1, CheckEnum.Checked);
				}
				else
				{
					unSelectedParametersTreeView.SetCellCheck(i, 1, CheckEnum.Unchecked);
				}
			}
			Cursor.Current = current;
		}

		internal void InitializeQueryComboBox()
		{
			InitializeQueryComboBox(cmbBoxSearchSring);
		}

		protected void InitializeQueryComboBox(ComboBox comboBox)
		{
			for (int i = 0; i < 5; i++)
			{
				appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				try
				{
					string appSetting = appConfigService.GetAppSetting(ApplicationSettings.ParameterSearchText, (ushort)(i + 1));
					AddToQueryList(comboBox, appSetting);
				}
				catch
				{
				}
			}
		}

		protected void AddToQueryList(ComboBox comboBox, string queryString)
		{
			if (comboBox != null && queryString != null && queryString.Trim() != string.Empty && !comboBox.Items.Contains((object)queryString))
			{
				if (comboBox.Items.Count >= 5)
				{
					comboBox.Items.RemoveAt(0);
				}
				comboBox.Items.Add((object)queryString);
				((Control)comboBox).Select();
				for (int i = 0; i < comboBox.Items.Count; i++)
				{
					string value = comboBox.Items[i].ToString();
					appConfigService.SetAppSetting(ApplicationSettings.ParameterSearchText, value, (ushort)(i + 1));
				}
			}
		}

		private void Initialize()
		{
			//IL_002f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0039: Expected O, but got Unknown
			//IL_0056: Unknown result type (might be due to invalid IL or missing references)
			//IL_0060: Expected O, but got Unknown
			InitializeComponent();
			chkBoxShowRamParam.Checked = showRamParameters;
			chkBoxShowRamParam.CheckedChanged += OnDisplayRamParamCheckChanged;
			csmMenu = new ContextMenu();
			((Menu)csmMenu).MenuItems.Add(0, new MenuItem("Copy", (EventHandler)OnCopyClick));
			((Control)unSelectedParametersTreeView).ContextMenu = csmMenu;
			parameterList.IncludeRuntimeParameters = true;
			parameterList.Subfile3Parameters = Subfile3ParametersAddType.IncludeAll;
			parameterList.ResetSelectionStatus(selectionStatus: false);
			((ListControl)cmbBoxFilter).SelectedIndex = 0;
			unSelectedParametersTreeView.Cols[0].Visible = false;
			unSelectedParametersTreeView.Cols.Count = 3;
			unSelectedParametersTreeView.ExtendLastCol = false;
			unSelectedParametersTreeView.Tree.Column = 1;
			unSelectedParametersTreeView.Rows.Fixed = 1;
			PopulateTree(unSelectedParametersTreeView, isSelected: false, ParameterSelectionCriteria.ShowAll);
			unSelectedParametersTreeView.Cols[2].AllowResizing = true;
		}
	}
	public class FilterView : ParameterQuery
	{
		private GroupBox grpBoxFilterFile;

		private Button btnClear;

		private Button btnSave;

		private Button btnOpen;

		private GroupBox grpBoxSortBy;

		private RadioButton radioBtnParameter;

		private RadioButton radioBtnGroup;

		private RadioButton radioBtnSubfile;

		private ComboBox cmbBoxFilter;

		private ComboBox cmbBoxQuerySring;

		private new C1FlexGrid unSelectedParametersTreeView;

		private C1FlexGrid selectedParametersTreeView;

		private Container components;

		private CheckBox chkSearchComments;

		private Label labelParameterList;

		private Label labelSelectionCriteria;

		private Label labelQueryString;

		private Panel panelMain;

		private Button buttonCollapse;

		private Button buttonClearAll;

		private CheckBox chkShowComment;

		private Button btnQuery;

		private TextBox txtFilterFileName;

		private Label labelFilterFileName;

		private GroupBox grpboxFilterMode;

		private RadioButton radioExcludeMode;

		private RadioButton radioIncludeMode;

		private Label labelSelectedParameterList;

		protected override ParameterSortType CurrentSortType
		{
			get
			{
				return currentSortType;
			}
			set
			{
				if (value != currentSortType)
				{
					currentSortType = value;
					PopulateTree(unSelectedParametersTreeView, isSelected: false, parameterSelectionCriteria);
					PopulateTree(selectedParametersTreeView, isSelected: true, ParameterSelectionCriteria.ShowAll);
					UpdateTree(selectedParametersTreeView, CheckEnum.Checked);
					UpdateTree(unSelectedParametersTreeView, CheckEnum.Unchecked);
				}
			}
		}

		public override ParameterFilterMode ParameterFilterMode
		{
			get
			{
				return parameterFilterMode;
			}
			set
			{
				if (parameterFilterMode != value)
				{
					base.ParameterFilterMode = value;
					if (value == ParameterFilterMode.Include)
					{
						radioIncludeMode.Checked = true;
					}
					else
					{
						radioExcludeMode.Checked = true;
					}
				}
			}
		}

		public FilterView()
		{
			Initialize();
			ParameterFilterMode = ParameterFilterMode.Exclude;
		}

		public FilterView(IParameterListInfo parameterList)
			: base(parameterList)
		{
			Initialize();
			base.unSelectedParametersTreeView = unSelectedParametersTreeView;
			base.parameterList = parameterList;
			ParameterFilterMode = ParameterFilterMode.Exclude;
		}

		private void Initialize()
		{
			InitializeComponent();
			base.unSelectedParametersTreeView = unSelectedParametersTreeView;
			((ListControl)cmbBoxFilter).SelectedIndex = 0;
			showAllParameters = false;
			InitializeQueryComboBox(cmbBoxQuerySring);
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
			//IL_00a6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b0: Expected O, but got Unknown
			//IL_00b1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00bb: Expected O, but got Unknown
			//IL_00bc: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c6: Expected O, but got Unknown
			//IL_00c7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d1: Expected O, but got Unknown
			//IL_00d2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00dc: Expected O, but got Unknown
			//IL_00e8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f2: Expected O, but got Unknown
			//IL_00f3: Unknown result type (might be due to invalid IL or missing references)
			//IL_00fd: Expected O, but got Unknown
			//IL_00fe: Unknown result type (might be due to invalid IL or missing references)
			//IL_0108: Expected O, but got Unknown
			//IL_0109: Unknown result type (might be due to invalid IL or missing references)
			//IL_0113: Expected O, but got Unknown
			//IL_0114: Unknown result type (might be due to invalid IL or missing references)
			//IL_011e: Expected O, but got Unknown
			//IL_011f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0129: Expected O, but got Unknown
			//IL_0723: Unknown result type (might be due to invalid IL or missing references)
			//IL_072d: Expected O, but got Unknown
			labelParameterList = new Label();
			grpBoxFilterFile = new GroupBox();
			btnClear = new Button();
			btnSave = new Button();
			btnOpen = new Button();
			grpBoxSortBy = new GroupBox();
			radioBtnParameter = new RadioButton();
			radioBtnGroup = new RadioButton();
			radioBtnSubfile = new RadioButton();
			cmbBoxFilter = new ComboBox();
			labelSelectionCriteria = new Label();
			cmbBoxQuerySring = new ComboBox();
			labelQueryString = new Label();
			panelMain = new Panel();
			unSelectedParametersTreeView = new C1FlexGrid();
			buttonCollapse = new Button();
			buttonClearAll = new Button();
			chkShowComment = new CheckBox();
			chkSearchComments = new CheckBox();
			btnQuery = new Button();
			selectedParametersTreeView = new C1FlexGrid();
			txtFilterFileName = new TextBox();
			labelFilterFileName = new Label();
			grpboxFilterMode = new GroupBox();
			radioExcludeMode = new RadioButton();
			radioIncludeMode = new RadioButton();
			labelSelectedParameterList = new Label();
			((Control)grpBoxFilterFile).SuspendLayout();
			((Control)grpBoxSortBy).SuspendLayout();
			((Control)panelMain).SuspendLayout();
			((ISupportInitialize)unSelectedParametersTreeView).BeginInit();
			((ISupportInitialize)selectedParametersTreeView).BeginInit();
			((Control)grpboxFilterMode).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)labelParameterList).AutoSize = true;
			((Control)labelParameterList).Location = new Point(16, 64);
			((Control)labelParameterList).Name = "labelParameterList";
			((Control)labelParameterList).Size = new Size(78, 16);
			((Control)labelParameterList).TabIndex = 29;
			((Control)labelParameterList).Text = "Parameter List";
			((Control)grpBoxFilterFile).Controls.Add((Control)(object)btnClear);
			((Control)grpBoxFilterFile).Controls.Add((Control)(object)btnSave);
			((Control)grpBoxFilterFile).Controls.Add((Control)(object)btnOpen);
			((Control)grpBoxFilterFile).Location = new Point(512, 219);
			((Control)grpBoxFilterFile).Name = "grpBoxFilterFile";
			((Control)grpBoxFilterFile).Size = new Size(224, 72);
			((Control)grpBoxFilterFile).TabIndex = 7;
			grpBoxFilterFile.TabStop = false;
			((Control)grpBoxFilterFile).Text = "Filter File";
			((Control)btnClear).Location = new Point(160, 16);
			((Control)btnClear).Name = "btnClear";
			((Control)btnClear).Size = new Size(56, 23);
			((Control)btnClear).TabIndex = 2;
			((Control)btnClear).Text = "Clear";
			((Control)btnClear).Click += OnClearClicked;
			((Control)btnSave).Location = new Point(88, 16);
			((Control)btnSave).Name = "btnSave";
			((Control)btnSave).Size = new Size(56, 23);
			((Control)btnSave).TabIndex = 1;
			((Control)btnSave).Text = "Save";
			((Control)btnSave).Click += OnSaveClicked;
			((Control)btnOpen).Location = new Point(16, 16);
			((Control)btnOpen).Name = "btnOpen";
			((Control)btnOpen).Size = new Size(56, 23);
			((Control)btnOpen).TabIndex = 0;
			((Control)btnOpen).Text = "Open";
			((Control)btnOpen).Click += OnOpenClicked;
			((Control)grpBoxSortBy).Controls.Add((Control)(object)radioBtnParameter);
			((Control)grpBoxSortBy).Controls.Add((Control)(object)radioBtnGroup);
			((Control)grpBoxSortBy).Controls.Add((Control)(object)radioBtnSubfile);
			((Control)grpBoxSortBy).Location = new Point(512, 161);
			((Control)grpBoxSortBy).Name = "grpBoxSortBy";
			((Control)grpBoxSortBy).Size = new Size(224, 48);
			((Control)grpBoxSortBy).TabIndex = 8;
			grpBoxSortBy.TabStop = false;
			((Control)grpBoxSortBy).Text = "Sort By";
			radioBtnParameter.Checked = true;
			((Control)radioBtnParameter).Location = new Point(136, 16);
			((Control)radioBtnParameter).Name = "radioBtnParameter";
			((Control)radioBtnParameter).Size = new Size(80, 24);
			((Control)radioBtnParameter).TabIndex = 2;
			radioBtnParameter.TabStop = true;
			((Control)radioBtnParameter).Text = "Parameter";
			radioBtnParameter.CheckedChanged += OnParameterSort;
			((Control)radioBtnGroup).Location = new Point(72, 16);
			((Control)radioBtnGroup).Name = "radioBtnGroup";
			((Control)radioBtnGroup).Size = new Size(56, 24);
			((Control)radioBtnGroup).TabIndex = 1;
			radioBtnGroup.TabStop = true;
			((Control)radioBtnGroup).Text = "Group";
			radioBtnGroup.CheckedChanged += OnGroupSort;
			((Control)radioBtnSubfile).Location = new Point(8, 16);
			((Control)radioBtnSubfile).Name = "radioBtnSubfile";
			((Control)radioBtnSubfile).Size = new Size(64, 24);
			((Control)radioBtnSubfile).TabIndex = 0;
			radioBtnSubfile.TabStop = true;
			((Control)radioBtnSubfile).Text = "Subfile";
			radioBtnSubfile.CheckedChanged += OnSubfileSort;
			cmbBoxFilter.Items.AddRange(new object[3] { "Show all parameters", "Show interface parameters", "Hide interface parameters" });
			((Control)cmbBoxFilter).Location = new Point(112, 40);
			((Control)cmbBoxFilter).Name = "cmbBoxFilter";
			((Control)cmbBoxFilter).Size = new Size(208, 21);
			((Control)cmbBoxFilter).TabIndex = 4;
			cmbBoxFilter.SelectedIndexChanged += OnSelectionCriteriaChanged;
			((Control)labelSelectionCriteria).AutoSize = true;
			((Control)labelSelectionCriteria).Location = new Point(16, 40);
			((Control)labelSelectionCriteria).Name = "labelSelectionCriteria";
			((Control)labelSelectionCriteria).Size = new Size(91, 16);
			((Control)labelSelectionCriteria).TabIndex = 25;
			((Control)labelSelectionCriteria).Text = "Selection Criteria";
			((Control)cmbBoxQuerySring).Location = new Point(112, 16);
			((Control)cmbBoxQuerySring).Name = "cmbBoxQuerySring";
			((Control)cmbBoxQuerySring).Size = new Size(352, 21);
			((Control)cmbBoxQuerySring).TabIndex = 0;
			((Control)cmbBoxQuerySring).KeyUp += new KeyEventHandler(base.OnComboBoxQueryStringKeyUp);
			((Control)labelQueryString).AutoSize = true;
			((Control)labelQueryString).Location = new Point(16, 16);
			((Control)labelQueryString).Name = "labelQueryString";
			((Control)labelQueryString).Size = new Size(68, 16);
			((Control)labelQueryString).TabIndex = 23;
			((Control)labelQueryString).Text = "Query String";
			((Control)panelMain).Controls.Add((Control)(object)unSelectedParametersTreeView);
			((Control)panelMain).Controls.Add((Control)(object)buttonCollapse);
			((Control)panelMain).Controls.Add((Control)(object)buttonClearAll);
			((Control)panelMain).Controls.Add((Control)(object)chkShowComment);
			((Control)panelMain).Controls.Add((Control)(object)chkSearchComments);
			((Control)panelMain).Controls.Add((Control)(object)btnQuery);
			((Control)panelMain).Controls.Add((Control)(object)selectedParametersTreeView);
			((Control)panelMain).Controls.Add((Control)(object)txtFilterFileName);
			((Control)panelMain).Controls.Add((Control)(object)labelFilterFileName);
			((Control)panelMain).Controls.Add((Control)(object)grpboxFilterMode);
			((Control)panelMain).Controls.Add((Control)(object)grpBoxFilterFile);
			((Control)panelMain).Controls.Add((Control)(object)labelSelectedParameterList);
			((Control)panelMain).Controls.Add((Control)(object)grpBoxSortBy);
			((Control)panelMain).Dock = (DockStyle)4;
			((Control)panelMain).Location = new Point(0, 0);
			((Control)panelMain).Name = "panelMain";
			((Control)panelMain).Size = new Size(752, 328);
			((Control)panelMain).TabIndex = 0;
			unSelectedParametersTreeView.AllowDragging = AllowDraggingEnum.None;
			unSelectedParametersTreeView.AllowSorting = AllowSortingEnum.MultiColumn;
			unSelectedParametersTreeView.AutoSearch = AutoSearchEnum.FromTop;
			unSelectedParametersTreeView.ColumnInfo = "10,0,0,0,0,75,Columns:";
			((Control)unSelectedParametersTreeView).Location = new Point(0, 80);
			((Control)unSelectedParametersTreeView).Name = "unSelectedParametersTreeView";
			unSelectedParametersTreeView.SelectionMode = SelectionModeEnum.Cell;
			unSelectedParametersTreeView.ShowButtons = ShowButtonsEnum.Always;
			((Control)unSelectedParametersTreeView).Size = new Size(248, 240);
			unSelectedParametersTreeView.Styles = new CellStyleCollection("Normal{WordWrap:True;}\tFixed{BackColor:Control;ForeColor:ControlText;Border:Flat,1,ControlDark,Both;}\tHighlight{BackColor:Highlight;ForeColor:HighlightText;}\tSearch{BackColor:Highlight;ForeColor:HighlightText;}\tFrozen{BackColor:Beige;}\tEmptyArea{BackColor:AppWorkspace;Border:Flat,1,ControlDarkDark,Both;}\tGrandTotal{BackColor:Black;ForeColor:White;}\tSubtotal0{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal1{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal2{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal3{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal4{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal5{BackColor:ControlDarkDark;ForeColor:White;}\t");
			((Control)unSelectedParametersTreeView).TabIndex = 40;
			unSelectedParametersTreeView.Tree.Column = 1;
			unSelectedParametersTreeView.AfterEdit += OnTreeViewEdit;
			((Control)buttonCollapse).Location = new Point(600, 296);
			((Control)buttonCollapse).Name = "buttonCollapse";
			((Control)buttonCollapse).Size = new Size(72, 24);
			((Control)buttonCollapse).TabIndex = 39;
			((Control)buttonCollapse).Text = "Collapse";
			((Control)buttonCollapse).Click += buttonCollapseClick;
			((Control)buttonClearAll).Location = new Point(512, 296);
			((Control)buttonClearAll).Name = "buttonClearAll";
			((Control)buttonClearAll).Size = new Size(72, 24);
			((Control)buttonClearAll).TabIndex = 9;
			((Control)buttonClearAll).Text = "Clear All";
			((Control)buttonClearAll).Click += OnClearSelection;
			chkShowComment.Checked = true;
			chkShowComment.CheckState = (CheckState)1;
			((Control)chkShowComment).Location = new Point(128, 64);
			((Control)chkShowComment).Name = "chkShowComment";
			((Control)chkShowComment).Size = new Size(128, 16);
			((Control)chkShowComment).TabIndex = 6;
			((Control)chkShowComment).Text = "Show Comments";
			chkShowComment.CheckedChanged += OnShowCommentCheckedChanged;
			chkSearchComments.Checked = true;
			chkSearchComments.CheckState = (CheckState)1;
			((Control)chkSearchComments).Location = new Point(336, 40);
			((Control)chkSearchComments).Name = "chkSearchComments";
			((Control)chkSearchComments).Size = new Size(128, 24);
			((Control)chkSearchComments).TabIndex = 5;
			((Control)chkSearchComments).Text = "Search Comments?";
			((Control)btnQuery).Location = new Point(472, 16);
			((Control)btnQuery).Name = "btnQuery";
			((Control)btnQuery).Size = new Size(56, 24);
			((Control)btnQuery).TabIndex = 3;
			((Control)btnQuery).Text = "&Query";
			((Control)btnQuery).Click += OnbuttonQueryClick;
			selectedParametersTreeView.AllowDragging = AllowDraggingEnum.None;
			selectedParametersTreeView.AllowSorting = AllowSortingEnum.MultiColumn;
			selectedParametersTreeView.AutoSearch = AutoSearchEnum.FromTop;
			selectedParametersTreeView.ColumnInfo = "10,0,0,0,0,75,Columns:";
			((Control)selectedParametersTreeView).Location = new Point(256, 80);
			((Control)selectedParametersTreeView).Name = "selectedParametersTreeView";
			selectedParametersTreeView.SelectionMode = SelectionModeEnum.Cell;
			selectedParametersTreeView.ShowButtons = ShowButtonsEnum.Always;
			((Control)selectedParametersTreeView).Size = new Size(248, 240);
			selectedParametersTreeView.Styles = new CellStyleCollection("Normal{WordWrap:True;}\tFixed{BackColor:Control;ForeColor:ControlText;Border:Flat,1,ControlDark,Both;}\tHighlight{BackColor:Highlight;ForeColor:HighlightText;}\tSearch{BackColor:Highlight;ForeColor:HighlightText;}\tFrozen{BackColor:Beige;}\tEmptyArea{BackColor:AppWorkspace;Border:Flat,1,ControlDarkDark,Both;}\tGrandTotal{BackColor:Black;ForeColor:White;}\tSubtotal0{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal1{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal2{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal3{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal4{BackColor:ControlDarkDark;ForeColor:White;}\tSubtotal5{BackColor:ControlDarkDark;ForeColor:White;}\t");
			((Control)selectedParametersTreeView).TabIndex = 2;
			selectedParametersTreeView.Tree.Column = 1;
			selectedParametersTreeView.AfterEdit += OnTreeViewEdit;
			((Control)txtFilterFileName).Anchor = (AnchorStyles)15;
			((Control)txtFilterFileName).Location = new Point(608, 266);
			((Control)txtFilterFileName).Name = "txtFilterFileName";
			((Control)txtFilterFileName).Size = new Size(115, 9);
			((Control)txtFilterFileName).TabIndex = 38;
			((Control)txtFilterFileName).Text = "";
			((Control)labelFilterFileName).AutoSize = true;
			((Control)labelFilterFileName).Location = new Point(528, 266);
			((Control)labelFilterFileName).Name = "labelFilterFileName";
			((Control)labelFilterFileName).Size = new Size(89, 16);
			((Control)labelFilterFileName).TabIndex = 37;
			((Control)labelFilterFileName).Text = "Filter File Name :";
			labelFilterFileName.TextAlign = (ContentAlignment)16;
			((Control)grpboxFilterMode).Anchor = (AnchorStyles)9;
			((Control)grpboxFilterMode).Controls.Add((Control)(object)radioExcludeMode);
			((Control)grpboxFilterMode).Controls.Add((Control)(object)radioIncludeMode);
			((Control)grpboxFilterMode).Location = new Point(512, 80);
			((Control)grpboxFilterMode).Name = "grpboxFilterMode";
			((Control)grpboxFilterMode).Size = new Size(224, 72);
			((Control)grpboxFilterMode).TabIndex = 6;
			grpboxFilterMode.TabStop = false;
			((Control)grpboxFilterMode).Text = "Filter Mode";
			radioExcludeMode.Checked = true;
			((Control)radioExcludeMode).Location = new Point(13, 40);
			((Control)radioExcludeMode).Name = "radioExcludeMode";
			((Control)radioExcludeMode).Size = new Size(184, 24);
			((Control)radioExcludeMode).TabIndex = 1;
			radioExcludeMode.TabStop = true;
			((Control)radioExcludeMode).Text = "&Exclude Selected Parameters";
			radioExcludeMode.CheckedChanged += OnFilterModeChanged;
			((Control)radioIncludeMode).Location = new Point(13, 16);
			((Control)radioIncludeMode).Name = "radioIncludeMode";
			((Control)radioIncludeMode).Size = new Size(176, 24);
			((Control)radioIncludeMode).TabIndex = 0;
			radioIncludeMode.TabStop = true;
			((Control)radioIncludeMode).Text = "&Include Selected Parameters";
			radioIncludeMode.CheckedChanged += OnFilterModeChanged;
			((Control)labelSelectedParameterList).AutoSize = true;
			((Control)labelSelectedParameterList).Location = new Point(272, 64);
			((Control)labelSelectedParameterList).Name = "labelSelectedParameterList";
			((Control)labelSelectedParameterList).Size = new Size(110, 16);
			((Control)labelSelectedParameterList).TabIndex = 35;
			((Control)labelSelectedParameterList).Text = "Selected Parameters";
			((Control)this).Controls.Add((Control)(object)cmbBoxFilter);
			((Control)this).Controls.Add((Control)(object)cmbBoxQuerySring);
			((Control)this).Controls.Add((Control)(object)labelParameterList);
			((Control)this).Controls.Add((Control)(object)labelSelectionCriteria);
			((Control)this).Controls.Add((Control)(object)labelQueryString);
			((Control)this).Controls.Add((Control)(object)panelMain);
			((Control)this).Name = "FilterView";
			((Control)this).Size = new Size(752, 328);
			((UserControl)this).Load += OnFilterViewLoad;
			((Control)grpBoxFilterFile).ResumeLayout(false);
			((Control)grpBoxSortBy).ResumeLayout(false);
			((Control)panelMain).ResumeLayout(false);
			((ISupportInitialize)unSelectedParametersTreeView).EndInit();
			((ISupportInitialize)selectedParametersTreeView).EndInit();
			((Control)grpboxFilterMode).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void OnFilterViewLoad(object sender, EventArgs e)
		{
			unSelectedParametersTreeView.Cols[0].Width = 0;
			unSelectedParametersTreeView.Cols[1].Width = ((Control)unSelectedParametersTreeView).Width / 2;
			unSelectedParametersTreeView.Cols[2].Width = ((Control)unSelectedParametersTreeView).Width / 2;
			unSelectedParametersTreeView.Rows.Fixed = 1;
			unSelectedParametersTreeView.Cols.Count = 3;
			unSelectedParametersTreeView.ExtendLastCol = false;
			unSelectedParametersTreeView.Tree.Column = 1;
			selectedParametersTreeView.Cols[0].Width = 0;
			selectedParametersTreeView.Cols[1].Width = ((Control)selectedParametersTreeView).Width / 2;
			selectedParametersTreeView.Cols[2].Width = ((Control)selectedParametersTreeView).Width / 2;
			selectedParametersTreeView.Cols.Count = 3;
			selectedParametersTreeView.ExtendLastCol = false;
			selectedParametersTreeView.Tree.Column = 1;
			selectedParametersTreeView.Rows.Fixed = 1;
			parameterCommentColWidth = ((Control)selectedParametersTreeView).Width / 2;
			parameterNameColWidth = ((Control)selectedParametersTreeView).Width / 2;
			PopulateTree(unSelectedParametersTreeView, isSelected: false, parameterSelectionCriteria);
			BuildParentNode(selectedParametersTreeView);
		}

		public void InitializeData(IParameterListInfo parameterList)
		{
			base.parameterList = parameterList;
			PopulateTree(unSelectedParametersTreeView, isSelected: false, parameterSelectionCriteria);
			unSelectedParametersTreeView.SetCellCheck(1, 1, CheckEnum.Unchecked);
			InitializeFilterData();
		}

		private void InitializeFilterData()
		{
			string result = "";
			if (!filterFilePath.Equals("") && LoadFilter(filterFilePath, accessFromCLI: false, ref result))
			{
				((Control)txtFilterFileName).Text = Path.GetFileName(filterFilePath);
				LoadTreeAfterFilter();
			}
		}

		private void OnParameterSort(object sender, EventArgs e)
		{
			CurrentSortType = ParameterSortType.ParameterName;
		}

		private void OnGroupSort(object sender, EventArgs e)
		{
			CurrentSortType = ParameterSortType.Group;
		}

		private void OnSubfileSort(object sender, EventArgs e)
		{
			CurrentSortType = ParameterSortType.Subfile;
		}

		private void DoSelect(Node node, bool isSelecting)
		{
			parameterList.SetSelectedStatus(node.Data.ToString(), isSelecting);
			for (node = node.GetNode(NodeTypeEnum.FirstChild); node != null; node = node.GetNode(NodeTypeEnum.NextSibling))
			{
				DoSelect(node, isSelecting);
			}
		}

		private void UpdateTree(C1FlexGrid grid, CheckEnum check)
		{
			for (int i = 1; i < grid.Rows.Count; i++)
			{
				grid.SetCellCheck(i, 1, check);
			}
		}

		private void OnTreeViewEdit(object sender, RowColEventArgs e)
		{
			C1FlexGrid c1FlexGrid = sender as C1FlexGrid;
			Cursor cursor = ((Control)this).Cursor;
			((Control)this).Cursor = Cursors.WaitCursor;
			c1FlexGrid.GetCellCheck(e.Row, 1);
			Node node = c1FlexGrid.Rows[e.Row].Node;
			if (node.Key != null && node.Key.ToString() == "Axis")
			{
				node = node.GetNode(NodeTypeEnum.Parent);
			}
			string focusNodeName = node.Data.ToString();
			bool flag = ((Control)c1FlexGrid).Name == "unSelectedParametersTreeView";
			C1FlexGrid c1FlexGrid2 = (flag ? selectedParametersTreeView : unSelectedParametersTreeView);
			CheckEnum check = (flag ? CheckEnum.Checked : CheckEnum.Unchecked);
			DoSelect(node, flag);
			BuildTreeView(c1FlexGrid2, currentSortType, flag, focusNodeName, parameterSelectionCriteria, null);
			c1FlexGrid2.SetCellCheck(1, 1, check);
			UpdateTree(c1FlexGrid2, check);
			node.RemoveNode();
			if (selectedParametersTreeView.Rows.Count == 2)
			{
				selectedParametersTreeView.SetCellCheck(1, 1, CheckEnum.Unchecked);
			}
			if (c1FlexGrid.Rows.Count == 1)
			{
				BuildParentNode(c1FlexGrid);
				c1FlexGrid.SetCellCheck(1, 1, CheckEnum.Unchecked);
			}
			((Control)this).Cursor = cursor;
		}

		private void buttonCollapseClick(object sender, EventArgs e)
		{
			Collapse(unSelectedParametersTreeView);
			Collapse(selectedParametersTreeView);
		}

		protected void OnOpenClicked(object sender, EventArgs e)
		{
			OnFilterOpen(sender, e);
			((Control)txtFilterFileName).Text = Path.GetFileName(filterFilePath);
		}

		protected void OnClearClicked(object sender, EventArgs e)
		{
			OnFilterClear(sender, e);
			((Control)txtFilterFileName).Text = "";
		}

		protected void OnSaveClicked(object sender, EventArgs e)
		{
			OnFilterSave(sender, e);
			((Control)txtFilterFileName).Text = Path.GetFileName(filterFilePath);
		}

		private void OnClearSelection(object sender, EventArgs e)
		{
			StringEnumerator enumerator = parameterList.SelectedParameters.GetEnumerator();
			try
			{
				while (enumerator.MoveNext())
				{
					string current = enumerator.Current;
					parameterList.SetSelectedStatus(current, selectedStatus: false);
				}
			}
			finally
			{
				if (enumerator is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
			PopulateTree(unSelectedParametersTreeView, isSelected: false, parameterSelectionCriteria);
			selectedParametersTreeView.Clear();
			selectedParametersTreeView.Rows.Count = 1;
			BuildParentNode(selectedParametersTreeView);
		}

		private void OnbuttonQueryClick(object sender, EventArgs e)
		{
			queryString = ((Control)cmbBoxQuerySring).Text;
			searchComments = chkSearchComments.Checked;
			QueryFromTree(selectedStatus: false);
			AddToQueryList(cmbBoxQuerySring, queryString);
		}

		protected override void OnShowCommentCheckedChanged(object sender, EventArgs e)
		{
			unSelectedParametersTreeView.Cols[2].Visible = chkShowComment.Checked;
			selectedParametersTreeView.Cols[2].Visible = chkShowComment.Checked;
			showComment = chkShowComment.Checked;
			if (!chkShowComment.Checked)
			{
				unSelectedParametersTreeView.Cols[1].Width = ((Control)unSelectedParametersTreeView).Width;
				selectedParametersTreeView.Cols[1].Width = ((Control)selectedParametersTreeView).Width;
			}
			else
			{
				unSelectedParametersTreeView.Cols[1].Width = parameterNameColWidth;
				selectedParametersTreeView.Cols[1].Width = parameterNameColWidth;
			}
		}

		protected override void OnSelectionCriteriaChanged(object sender, EventArgs e)
		{
			ComboBox val = (ComboBox)((sender is ComboBox) ? sender : null);
			if (((ListControl)val).SelectedIndex != (int)parameterSelectionCriteria)
			{
				parameterSelectionCriteria = (ParameterSelectionCriteria)((ListControl)val).SelectedIndex;
				PopulateTree(unSelectedParametersTreeView, isSelected: false, parameterSelectionCriteria);
			}
		}

		private void OnFilterModeChanged(object sender, EventArgs e)
		{
			ParameterFilterMode = ((!radioIncludeMode.Checked) ? ParameterFilterMode.Exclude : ParameterFilterMode.Include);
		}

		protected override void LoadTreeAfterFilter()
		{
			PopulateTree(unSelectedParametersTreeView, isSelected: false, parameterSelectionCriteria);
			PopulateTree(selectedParametersTreeView, isSelected: true, ParameterSelectionCriteria.ShowAll);
		}

		protected override void OnFilterClear(object sender, EventArgs e)
		{
			showAllParameters = false;
			ParameterFilterMode = ParameterFilterMode.Exclude;
			parameterList.ResetSelectionStatus(selectionStatus: false);
			appConfigService.SetLastUsedValue(currentProduct, "", LastUsedType.LastFilterFile);
			PopulateTree(unSelectedParametersTreeView, isSelected: false, parameterSelectionCriteria);
			selectedParametersTreeView.Clear();
			selectedParametersTreeView.Rows.Count = 1;
			BuildParentNode(selectedParametersTreeView);
		}
	}
	public enum PublicParameterSortType
	{
		ParameterName,
		PGN
	}
	public enum J1939SubscriptionType
	{
		RequestData,
		ListenOnly
	}
	public class J1939_71ParameterQuery : UserControl
	{
		protected const int ParameterNameColumnNumber = 1;

		protected const int PGNViewParamCommentColNumber = 2;

		protected const int PGNColumnNumber = 2;

		protected const int ParamViewParamCommentColNumber = 3;

		private const string ParameterColHeading = "Parameter Name";

		private const string CommentColHeading = "Comments";

		private const string PGNColHeading = "PGN";

		internal const string MenuItemCopy = "Copy";

		protected const string CommentNodeCaption = "Comments";

		protected const string AllParametersNodeCaption = "All Parameters";

		protected const string PGNNodeCaption = "PGN";

		private const string subfile3 = "3";

		private const string FilterConfigHeaderParameterString = "ConfigHeaders.";

		private ComboBox cmbBoxSearchSring;

		private IContainer components;

		private Panel panel1;

		private CheckBox chkSearchComments;

		private Label labelSearchString;

		private bool handledByEnter;

		protected ICalibrationOnline onlineCal;

		protected DataTable screenTable;

		protected PublicParameterSortType currentSortType = PublicParameterSortType.PGN;

		protected J1939SubscriptionType currentSubscriptionType;

		protected C1FlexGrid publicParametersTreeView;

		protected IParameterListInfo parameterList;

		protected IDirectoryService directoryService;

		protected IAppConfigService appConfigService;

		protected string currentProduct = string.Empty;

		protected string queryString = string.Empty;

		protected bool searchComments;

		protected bool showComment = true;

		protected ParameterListViewData _parameterListViewData = new ParameterListViewData();

		protected string cbfFileName;

		protected int treeViewParameterNameColWidth = 209;

		protected int treeViewParameterCommentColWidth = 209;

		protected int listViewParameterNameColWidth = 180;

		protected int listViewPGNNameColWidth = 58;

		protected int listViewParameterCommentColWidth = 180;

		private PublicDataParameterListInfo _publicDataParameterListInfo;

		private List<PCLWrapper.ParameterInfo> parametersAvailable;

		private GroupBox groupBox1;

		private GroupBox groupBox2;

		private Button btnClearSearchResults;

		private Button btnSearch;

		private Label label1;

		private PictureBox picBoxExpandAll;

		private ComboBox cmbBoxSortBy;

		private Button btnUnSelectAll;

		private Button btnBroadcastParam;

		private ToolTip createToolTip;

		private PictureBox picBoxCollapseAll;

		private GroupBox groupBox3;

		private RadioButton btnListenOnly;

		private RadioButton btnRequestData;

		protected SortedList currentParamLookup = new SortedList();

		private int rowIndex = 1;

		private ContextMenu csmMenu;

		public J1939SubscriptionType CurrentSubscriptionType
		{
			get
			{
				return currentSubscriptionType;
			}
			set
			{
				currentSubscriptionType = value;
			}
		}

		public PublicParameterSortType CurrentSortType
		{
			get
			{
				return currentSortType;
			}
			set
			{
				if (value != currentSortType)
				{
					currentSortType = value;
					PopulateTree(publicParametersTreeView, isSelected: true);
					if (currentSortType == PublicParameterSortType.PGN)
					{
						publicParametersTreeView.Cols[1].Width = treeViewParameterNameColWidth;
						publicParametersTreeView.Cols[2].Width = treeViewParameterCommentColWidth;
						publicParametersTreeView.Cols[3].Width = 0;
					}
					else
					{
						publicParametersTreeView.Cols[1].Width = listViewParameterNameColWidth;
						publicParametersTreeView.Cols[2].Width = listViewPGNNameColWidth;
						publicParametersTreeView.Cols[3].Width = listViewParameterCommentColWidth;
					}
				}
			}
		}

		public StringCollection SelectedParameter => GetOrderedParameterList(parameterList.SelectedParameters, currentSortType);

		public event EventHandler AddParameterOnEnterEvent;

		public event EventHandler ShowBroadcastListEvent;

		protected J1939_71ParameterQuery()
		{
			directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			currentProduct = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			cbfFileName = appConfigService.CBFFileName;
			Control.CheckForIllegalCrossThreadCalls = false;
		}

		public J1939_71ParameterQuery(IParameterListInfo parameterList)
			: this()
		{
			this.parameterList = onlineCal.PublicParameterInfo;
			Initialize();
		}

		public J1939_71ParameterQuery(ICalibration datasource, IParameterListInfo parameterList, DataTable screenTable)
			: this()
		{
			onlineCal = datasource as ICalibrationOnline;
			this.parameterList = parameterList;
			cbfFileName = appConfigService.CBFFileName;
			_publicDataParameterListInfo = new PublicDataParameterListInfo(cbfFileName);
			Initialize();
			this.screenTable = screenTable;
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
			//IL_00d2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00dc: Expected O, but got Unknown
			//IL_00dd: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e7: Expected O, but got Unknown
			//IL_00e8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f2: Expected O, but got Unknown
			//IL_01b6: Unknown result type (might be due to invalid IL or missing references)
			//IL_01c0: Expected O, but got Unknown
			//IL_0b29: Unknown result type (might be due to invalid IL or missing references)
			//IL_0b33: Expected O, but got Unknown
			components = new Container();
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(J1939_71ParameterQuery));
			cmbBoxSearchSring = new ComboBox();
			labelSearchString = new Label();
			panel1 = new Panel();
			groupBox3 = new GroupBox();
			btnBroadcastParam = new Button();
			groupBox2 = new GroupBox();
			picBoxCollapseAll = new PictureBox();
			btnUnSelectAll = new Button();
			picBoxExpandAll = new PictureBox();
			cmbBoxSortBy = new ComboBox();
			label1 = new Label();
			groupBox1 = new GroupBox();
			btnClearSearchResults = new Button();
			btnSearch = new Button();
			chkSearchComments = new CheckBox();
			publicParametersTreeView = new C1FlexGrid();
			createToolTip = new ToolTip(components);
			btnRequestData = new RadioButton();
			btnListenOnly = new RadioButton();
			((Control)panel1).SuspendLayout();
			((Control)groupBox3).SuspendLayout();
			((Control)groupBox2).SuspendLayout();
			((ISupportInitialize)picBoxCollapseAll).BeginInit();
			((ISupportInitialize)picBoxExpandAll).BeginInit();
			((Control)groupBox1).SuspendLayout();
			((ISupportInitialize)publicParametersTreeView).BeginInit();
			((Control)this).SuspendLayout();
			((Control)cmbBoxSearchSring).Anchor = (AnchorStyles)12;
			((ListControl)cmbBoxSearchSring).DisplayMember = "Text";
			((Control)cmbBoxSearchSring).Location = new Point(99, 14);
			((Control)cmbBoxSearchSring).Name = "cmbBoxSearchSring";
			((Control)cmbBoxSearchSring).Size = new Size(267, 21);
			((Control)cmbBoxSearchSring).TabIndex = 0;
			((Control)cmbBoxSearchSring).KeyUp += new KeyEventHandler(OnComboBoxQueryStringKeyUp);
			((Control)labelSearchString).Location = new Point(8, 14);
			((Control)labelSearchString).Name = "labelSearchString";
			((Control)labelSearchString).Size = new Size(85, 21);
			((Control)labelSearchString).TabIndex = 16;
			((Control)labelSearchString).Text = "Search String";
			labelSearchString.TextAlign = (ContentAlignment)16;
			((Control)panel1).Controls.Add((Control)(object)groupBox3);
			((Control)panel1).Controls.Add((Control)(object)groupBox2);
			((Control)panel1).Controls.Add((Control)(object)groupBox1);
			((Control)panel1).Controls.Add((Control)(object)publicParametersTreeView);
			((Control)panel1).Dock = (DockStyle)5;
			((Control)panel1).Location = new Point(0, 0);
			((Control)panel1).Name = "panel1";
			((Control)panel1).Size = new Size(456, 500);
			((Control)panel1).TabIndex = 3;
			((Control)groupBox3).Anchor = (AnchorStyles)9;
			((Control)groupBox3).Controls.Add((Control)(object)btnListenOnly);
			((Control)groupBox3).Controls.Add((Control)(object)btnRequestData);
			((Control)groupBox3).Controls.Add((Control)(object)btnBroadcastParam);
			((Control)groupBox3).Location = new Point(248, 80);
			((Control)groupBox3).Name = "groupBox3";
			((Control)groupBox3).Size = new Size(200, 67);
			((Control)groupBox3).TabIndex = 47;
			groupBox3.TabStop = false;
			((Control)groupBox3).Text = "Display Data";
			((Control)btnBroadcastParam).Anchor = (AnchorStyles)6;
			((Control)btnBroadcastParam).Location = new Point(6, 39);
			((Control)btnBroadcastParam).Name = "btnBroadcastParam";
			((Control)btnBroadcastParam).Size = new Size(186, 27);
			((Control)btnBroadcastParam).TabIndex = 45;
			((Control)btnBroadcastParam).Tag = "0";
			((Control)btnBroadcastParam).Text = "&Available Broadcast Parameters";
			((Control)btnBroadcastParam).Click += btnBroadcastParam_Click;
			((Control)groupBox2).Controls.Add((Control)(object)picBoxCollapseAll);
			((Control)groupBox2).Controls.Add((Control)(object)btnUnSelectAll);
			((Control)groupBox2).Controls.Add((Control)(object)picBoxExpandAll);
			((Control)groupBox2).Controls.Add((Control)(object)cmbBoxSortBy);
			((Control)groupBox2).Controls.Add((Control)(object)label1);
			((Control)groupBox2).Location = new Point(4, 78);
			((Control)groupBox2).Name = "groupBox2";
			((Control)groupBox2).Size = new Size(238, 69);
			((Control)groupBox2).TabIndex = 44;
			groupBox2.TabStop = false;
			((Control)groupBox2).Text = "Organize Data";
			((Control)picBoxCollapseAll).Anchor = (AnchorStyles)7;
			picBoxCollapseAll.Image = (Image)(object)Resources.collapseIcon;
			((Control)picBoxCollapseAll).Location = new Point(47, 45);
			((Control)picBoxCollapseAll).Name = "picBoxCollapseAll";
			((Control)picBoxCollapseAll).Size = new Size(16, 16);
			picBoxCollapseAll.TabIndex = 23;
			picBoxCollapseAll.TabStop = false;
			createToolTip.SetToolTip((Control)(object)picBoxCollapseAll, "Collapse all");
			((Control)picBoxCollapseAll).Click += picBoxCollapseAll_Click;
			((Control)btnUnSelectAll).Anchor = (AnchorStyles)9;
			((Control)btnUnSelectAll).Location = new Point(131, 41);
			((Control)btnUnSelectAll).Name = "btnUnSelectAll";
			((Control)btnUnSelectAll).Size = new Size(85, 24);
			((Control)btnUnSelectAll).TabIndex = 20;
			((Control)btnUnSelectAll).Tag = "0";
			((Control)btnUnSelectAll).Text = "&Unselect all";
			((Control)btnUnSelectAll).Click += btnUnSelectAll_Click;
			((Control)picBoxExpandAll).Anchor = (AnchorStyles)7;
			picBoxExpandAll.Image = (Image)(object)Resources.expandIcon;
			((Control)picBoxExpandAll).Location = new Point(16, 45);
			((Control)picBoxExpandAll).Name = "picBoxExpandAll";
			((Control)picBoxExpandAll).Size = new Size(16, 16);
			picBoxExpandAll.TabIndex = 22;
			picBoxExpandAll.TabStop = false;
			createToolTip.SetToolTip((Control)(object)picBoxExpandAll, "Expand all");
			((Control)picBoxExpandAll).Click += picBoxExpandAll_Click;
			((Control)cmbBoxSortBy).Anchor = (AnchorStyles)7;
			((ListControl)cmbBoxSortBy).DisplayMember = "Text";
			cmbBoxSortBy.Items.AddRange(new object[2] { "ParameterName", "PGN" });
			((Control)cmbBoxSortBy).Location = new Point(72, 16);
			((Control)cmbBoxSortBy).Name = "cmbBoxSortBy";
			((Control)cmbBoxSortBy).Size = new Size(156, 21);
			((Control)cmbBoxSortBy).TabIndex = 7;
			((Control)cmbBoxSortBy).Text = "PGN";
			cmbBoxSortBy.SelectedIndexChanged += cmbBoxSortBy_SelectedIndexChanged;
			((Control)label1).Anchor = (AnchorStyles)7;
			((Control)label1).Location = new Point(13, 19);
			((Control)label1).Name = "label1";
			((Control)label1).Size = new Size(68, 16);
			((Control)label1).TabIndex = 17;
			((Control)label1).Text = "Sort by";
			((Control)groupBox1).Anchor = (AnchorStyles)13;
			((Control)groupBox1).Controls.Add((Control)(object)labelSearchString);
			((Control)groupBox1).Controls.Add((Control)(object)btnClearSearchResults);
			((Control)groupBox1).Controls.Add((Control)(object)btnSearch);
			((Control)groupBox1).Controls.Add((Control)(object)cmbBoxSearchSring);
			((Control)groupBox1).Controls.Add((Control)(object)chkSearchComments);
			((Control)groupBox1).Location = new Point(3, 3);
			((Control)groupBox1).Name = "groupBox1";
			((Control)groupBox1).Size = new Size(445, 71);
			((Control)groupBox1).TabIndex = 43;
			groupBox1.TabStop = false;
			((Control)groupBox1).Text = "Search";
			((Control)btnClearSearchResults).Anchor = (AnchorStyles)9;
			((Control)btnClearSearchResults).Location = new Point(127, 41);
			((Control)btnClearSearchResults).Name = "btnClearSearchResults";
			((Control)btnClearSearchResults).Size = new Size(142, 24);
			((Control)btnClearSearchResults).TabIndex = 6;
			((Control)btnClearSearchResults).Tag = "0";
			((Control)btnClearSearchResults).Text = "&Clear Search Results";
			((Control)btnClearSearchResults).Click += btnClearSearchResults_Click;
			((Control)btnSearch).Anchor = (AnchorStyles)9;
			((Control)btnSearch).Location = new Point(381, 14);
			((Control)btnSearch).Name = "btnSearch";
			((Control)btnSearch).Size = new Size(56, 21);
			((Control)btnSearch).TabIndex = 5;
			((Control)btnSearch).Tag = "0";
			((Control)btnSearch).Text = "&Search";
			((Control)btnSearch).Click += OnSearchButtonClick;
			((Control)chkSearchComments).Anchor = (AnchorStyles)9;
			chkSearchComments.Checked = true;
			chkSearchComments.CheckState = (CheckState)1;
			((Control)chkSearchComments).Location = new Point(301, 41);
			((Control)chkSearchComments).Name = "chkSearchComments";
			((Control)chkSearchComments).Size = new Size(136, 24);
			((Control)chkSearchComments).TabIndex = 6;
			((Control)chkSearchComments).Text = "Search Comments";
			publicParametersTreeView.AllowDragging = AllowDraggingEnum.None;
			publicParametersTreeView.AllowSorting = AllowSortingEnum.MultiColumn;
			((Control)publicParametersTreeView).Anchor = (AnchorStyles)15;
			publicParametersTreeView.AutoSearch = AutoSearchEnum.FromTop;
			((Control)publicParametersTreeView).BackColor = SystemColors.Window;
			publicParametersTreeView.ColumnInfo = "10,0,0,0,0,75,Columns:";
			((Control)publicParametersTreeView).Location = new Point(8, 156);
			((Control)publicParametersTreeView).Name = "publicParametersTreeView";
			publicParametersTreeView.SelectionMode = SelectionModeEnum.Cell;
			publicParametersTreeView.ShowButtons = ShowButtonsEnum.Always;
			((Control)publicParametersTreeView).Size = new Size(423, 328);
			publicParametersTreeView.Styles = new CellStyleCollection(componentResourceManager.GetString("publicParametersTreeView.Styles"));
			((Control)publicParametersTreeView).TabIndex = 46;
			publicParametersTreeView.Tree.Column = 1;
			publicParametersTreeView.AfterEdit += OnTreeViewAfterEdit;
			((Control)publicParametersTreeView).KeyDown += new KeyEventHandler(OnTreeViewKeyDown);
			((Control)btnRequestData).AutoSize = true;
			btnRequestData.Checked = true;
			((Control)btnRequestData).Location = new Point(4, 20);
			((Control)btnRequestData).Name = "btnRequestData";
			((Control)btnRequestData).Size = new Size(91, 17);
			((Control)btnRequestData).TabIndex = 46;
			btnRequestData.TabStop = true;
			((Control)btnRequestData).Text = "Request Data";
			((ButtonBase)btnRequestData).UseVisualStyleBackColor = true;
			btnRequestData.CheckedChanged += btnRequestData_CheckedChanged;
			((Control)btnListenOnly).AutoSize = true;
			((Control)btnListenOnly).Location = new Point(106, 19);
			((Control)btnListenOnly).Name = "btnListenOnly";
			((Control)btnListenOnly).Size = new Size(77, 17);
			((Control)btnListenOnly).TabIndex = 46;
			((Control)btnListenOnly).Text = "Listen Only";
			((ButtonBase)btnListenOnly).UseVisualStyleBackColor = true;
			btnListenOnly.CheckedChanged += btnListenOnly_CheckedChanged;
			((Control)this).Controls.Add((Control)(object)panel1);
			((Control)this).Name = "J1939_71ParameterQuery";
			((Control)this).Size = new Size(456, 500);
			((Control)this).VisibleChanged += OnVisibleChanged;
			((Control)this).Resize += OnResizeParameterQuery;
			((Control)panel1).ResumeLayout(false);
			((Control)groupBox3).ResumeLayout(false);
			((Control)groupBox3).PerformLayout();
			((Control)groupBox2).ResumeLayout(false);
			((ISupportInitialize)picBoxCollapseAll).EndInit();
			((ISupportInitialize)picBoxExpandAll).EndInit();
			((Control)groupBox1).ResumeLayout(false);
			((ISupportInitialize)publicParametersTreeView).EndInit();
			((Control)this).ResumeLayout(false);
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing)
			{
				if (components != null)
				{
					components.Dispose();
					components = null;
				}
				if (parameterList != null)
				{
					parameterList.Dispose();
					parameterList = null;
				}
				if (currentParamLookup != null)
				{
					currentParamLookup.Clear();
					currentParamLookup = null;
				}
			}
			((ContainerControl)this).Dispose(disposing);
		}

		private void picBoxExpandAll_Click(object sender, EventArgs e)
		{
			publicParametersTreeView.Redraw = false;
			if (publicParametersTreeView.Row > 0)
			{
				Node node = ((publicParametersTreeView.Row != 1) ? publicParametersTreeView.Rows[publicParametersTreeView.Row].Node : ((publicParametersTreeView.Rows.Count <= 2) ? publicParametersTreeView.Rows[publicParametersTreeView.Row].Node : publicParametersTreeView.Rows[publicParametersTreeView.Row + 1].Node));
				if (node != null)
				{
					Node node2 = node.GetNode(NodeTypeEnum.FirstSibling);
					if (node2 == null)
					{
						node2 = node;
					}
					while (node2 != null)
					{
						node2.Collapsed = false;
						node2 = node2.GetNode(NodeTypeEnum.NextSibling);
					}
				}
			}
			publicParametersTreeView.Redraw = true;
		}

		private void picBoxCollapseAll_Click(object sender, EventArgs e)
		{
			publicParametersTreeView.Redraw = false;
			if (publicParametersTreeView.Row > 0)
			{
				Node node = ((publicParametersTreeView.Row != 1) ? publicParametersTreeView.Rows[publicParametersTreeView.Row].Node : ((publicParametersTreeView.Rows.Count <= 2) ? publicParametersTreeView.Rows[publicParametersTreeView.Row].Node : publicParametersTreeView.Rows[publicParametersTreeView.Row + 1].Node));
				if (node != null)
				{
					Node node2 = node.GetNode(NodeTypeEnum.FirstSibling);
					if (node2 == null)
					{
						node2 = node;
					}
					while (node2 != null)
					{
						node2.Collapsed = true;
						node2 = node2.GetNode(NodeTypeEnum.NextSibling);
					}
				}
			}
			publicParametersTreeView.Redraw = true;
		}

		private void btnUnSelectAll_Click(object sender, EventArgs e)
		{
			int count = publicParametersTreeView.Rows.Count;
			StringEnumerator enumerator = parameterList.SelectedParameters.GetEnumerator();
			try
			{
				while (enumerator.MoveNext())
				{
					string current = enumerator.Current;
					parameterList[current].IsSelected = false;
				}
			}
			finally
			{
				if (enumerator is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
			parameterList.SelectedParameters.Clear();
			for (int i = 1; i < count; i++)
			{
				publicParametersTreeView.SetCellCheck(i, 1, CheckEnum.Unchecked);
			}
		}

		private void btnClearSearchResults_Click(object sender, EventArgs e)
		{
			((Control)cmbBoxSearchSring).Text = "";
			queryString = null;
			QueryFromTree(selectedStatus: true);
		}

		private void cmbBoxSortBy_SelectedIndexChanged(object sender, EventArgs e)
		{
			switch (cmbBoxSortBy.SelectedItem.ToString())
			{
			case "ParameterName":
				CurrentSortType = PublicParameterSortType.ParameterName;
				break;
			case "PGN":
				CurrentSortType = PublicParameterSortType.PGN;
				break;
			}
		}

		protected string SelectAllMatching(string text)
		{
			string result = string.Empty;
			foreach (Row item in (IEnumerable)publicParametersTreeView.Rows.Selected)
			{
				item.Selected = false;
			}
			foreach (Row item2 in (IEnumerable)publicParametersTreeView.Rows)
			{
				if (item2[1].ToString().ToUpper().StartsWith(text))
				{
					item2.Selected = true;
					publicParametersTreeView.Select(item2.Index, 1, show: true);
					publicParametersTreeView.TopRow = item2.Index;
					result = item2[1].ToString();
					break;
				}
			}
			return result;
		}

		protected void OnComboBoxQueryStringKeyUp(object sender, KeyEventArgs e)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_000f: Invalid comparison between Unknown and I4
			//IL_0081: Unknown result type (might be due to invalid IL or missing references)
			//IL_0088: Invalid comparison between Unknown and I4
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Invalid comparison between Unknown and I4
			ComboBox val = (ComboBox)((sender is ComboBox) ? sender : null);
			if ((int)e.KeyData != 46 && (int)e.KeyData != 8 && ((Control)val).Text != string.Empty)
			{
				string text = SelectAllMatching(((Control)val).Text.ToUpper());
				if (text != string.Empty && text != ((Control)val).Text)
				{
					string text2 = ((Control)val).Text;
					((Control)val).Text = text;
					val.Select(text2.Length, text.Length - text2.Length);
				}
			}
			if ((int)e.KeyData == 13)
			{
				OnSearchButtonClick(sender, (EventArgs)(object)e);
			}
		}

		protected void OnCopyClick(object sender, EventArgs e)
		{
			Copy(publicParametersTreeView.Clip);
		}

		protected void Copy(string clipBoardData)
		{
			try
			{
				SafeClipBoard safeClipBoard = new SafeClipBoard();
				safeClipBoard.SetDataToClipBoard(clipBoardData);
			}
			catch
			{
			}
		}

		private void RecursiveSelect(bool isIncludeComplexParameter, Node node, CheckEnum checkValue)
		{
			bool flag = false;
			while (node != null)
			{
				if (isIncludeComplexParameter)
				{
					flag = true;
				}
				else
				{
					IParamInfo paramInfo = parameterList[node.Data.ToString()];
					flag = ((!paramInfo.IsTable && !parameterList.Structure.Contains(node.Data.ToString())) ? true : false);
				}
				if (flag)
				{
					DoSelect(node.Row.Index, checkValue);
					if (node.GetNode(NodeTypeEnum.FirstChild) != null)
					{
						DoSelect(node.GetNode(NodeTypeEnum.FirstChild).Row.Index, checkValue);
						RecursiveSelect(isIncludeComplexParameter, node.GetNode(NodeTypeEnum.FirstChild), checkValue);
					}
				}
				node = node.GetNode(NodeTypeEnum.NextSibling);
			}
		}

		private void InitTree(C1FlexGrid treeView)
		{
			int num = 0;
			parametersAvailable = (_publicDataParameterListInfo.Parameters as PublicDataParamInfoList).PGNs;
			publicParametersTreeView.Rows.RemoveRange(0, publicParametersTreeView.Rows.Count);
			treeView.Rows.InsertRange(0, parametersAvailable.Count);
			foreach (PCLWrapper.ParameterInfo item in parametersAvailable)
			{
				if (item.Children == null)
				{
					continue;
				}
				foreach (SubParameterInfo child in item.Children)
				{
					_ = child;
					num++;
				}
			}
			treeView.Rows.InsertRange(parametersAvailable.Count - 1, num);
		}

		protected virtual void PopulateTree(C1FlexGrid treeView, bool isSelected)
		{
			InitTree(treeView);
			treeView.Redraw = false;
			Cursor current = Cursor.Current;
			Cursor.Current = Cursors.WaitCursor;
			try
			{
				if (parameterList == null || (treeView.Rows.Count <= 0 && isSelected))
				{
					return;
				}
				if (queryString == null || queryString == "")
				{
					BuildTreeView(treeView, CurrentSortType, isSelected, null, null);
				}
				else
				{
					BuildTreeView(treeView, CurrentSortType, isSelected, null, queryString);
				}
				int count = treeView.Rows.Count;
				StringCollection selectedParameters = parameterList.SelectedParameters;
				for (int i = 1; i < count; i++)
				{
					string text = treeView.Rows[i].Node.Data.ToString();
					if (selectedParameters.Contains(text))
					{
						treeView.SetCellCheck(i, 1, CheckEnum.Checked);
						if (parameterList.IsStructure(text))
						{
							for (Node node = treeView.Rows[i].Node.GetNode(NodeTypeEnum.FirstChild); node != null; node = node.GetNode(NodeTypeEnum.NextSibling))
							{
								i++;
								treeView.SetCellCheck(node.Row.Index, 1, CheckEnum.Checked);
							}
						}
					}
					else
					{
						treeView.SetCellCheck(i, 1, CheckEnum.Unchecked);
					}
				}
			}
			finally
			{
				Cursor.Current = current;
				treeView.Redraw = true;
			}
		}

		private void DoSelect(int row, CheckEnum checkValue)
		{
			if (row <= 1)
			{
				return;
			}
			string paramName = null;
			bool flag = false;
			Node node = publicParametersTreeView.Rows[row].Node;
			Node node2 = node.GetNode(NodeTypeEnum.Parent);
			if (node2.Data.ToString() == "PGN")
			{
				node.Data.ToString();
				for (Node node3 = node.GetNode(NodeTypeEnum.FirstChild); node3 != null; node3 = node3.GetNode(NodeTypeEnum.NextSibling))
				{
					flag = true;
					DoSelect(node3.Row.Index, checkValue);
				}
				flag = false;
			}
			else if (node2.Data.ToString() != "PGN" && node2.Data.ToString() != "Parameter Name" && node2.Data.ToString() != "All Parameters")
			{
				paramName = node2.Data.ToString() + "." + publicParametersTreeView[row, 1].ToString();
				flag = true;
			}
			else if (node2.Data.ToString() == "All Parameters")
			{
				paramName = publicParametersTreeView[row, 2].ToString() + "." + publicParametersTreeView[row, 1].ToString();
				flag = true;
			}
			else
			{
				paramName = publicParametersTreeView[row, 1].ToString();
				flag = true;
			}
			if (flag)
			{
				parameterList.SetSelectedStatus(paramName, checkValue == CheckEnum.Checked);
				publicParametersTreeView.SetCellCheck(row, 1, checkValue);
			}
		}

		private void DoCheck(int row, CheckEnum checkValue)
		{
			if (row > 1)
			{
				publicParametersTreeView[row, 1].ToString();
				publicParametersTreeView.SetCellCheck(row, 1, checkValue);
			}
		}

		private void UpdateParameterSelection(int selectedRowIndex)
		{
			bool isIncludeComplexParameter = true;
			bool flag = false;
			if (!handledByEnter)
			{
				Node node = publicParametersTreeView.Rows[selectedRowIndex].Node;
				Node node2 = node.GetNode(NodeTypeEnum.Parent);
				if (node2 != null && !parameterList.IsStructure(node2.Data.ToString()))
				{
					DoSelect(selectedRowIndex, publicParametersTreeView.GetCellCheck(selectedRowIndex, 1));
					string paramName = null;
					if (node2.Data.ToString() == "All Parameters")
					{
						paramName = string.Concat(publicParametersTreeView[selectedRowIndex, 2], ".", node.Data.ToString());
						flag = true;
					}
					else if (node2.Data.ToString() == "PGN")
					{
						for (Node node3 = node.GetNode(NodeTypeEnum.FirstChild); node3 != null; node3 = node3.GetNode(NodeTypeEnum.NextSibling))
						{
							flag = true;
							UpdateParameterSelection(node3.Row.Index);
						}
						flag = false;
					}
					else if (node2 != null)
					{
						paramName = node2.Data.ToString() + "." + node.Data.ToString();
						flag = true;
					}
					if (flag)
					{
						IParamInfo paramInfo = parameterList[paramName];
						if (paramInfo == null)
						{
							if (node.Data.ToString().Equals("All Parameters") || node.Data.ToString().Equals("PGN") || parameterList.Groups.Contains(node.Data.ToString()))
							{
								isIncludeComplexParameter = true;
							}
						}
						else
						{
							isIncludeComplexParameter = true;
						}
					}
				}
				if (node.GetNode(NodeTypeEnum.FirstChild) != null)
				{
					if (parameterList.IsStructure(node.Data.ToString()))
					{
						Node node4 = node.GetNode(NodeTypeEnum.FirstChild);
						if (node4 == null)
						{
							node4 = node;
						}
						while (node4 != null)
						{
							DoCheck(node4.Row.Index, publicParametersTreeView.GetCellCheck(selectedRowIndex, 1));
							node4 = node4.GetNode(NodeTypeEnum.NextSibling);
						}
					}
					else
					{
						RecursiveSelect(isIncludeComplexParameter, node.GetNode(NodeTypeEnum.FirstChild), publicParametersTreeView.GetCellCheck(selectedRowIndex, 1));
					}
				}
				else
				{
					if (node2 == null)
					{
						return;
					}
					Node node5 = node2.GetNode(NodeTypeEnum.Parent);
					if (node5 == null)
					{
						return;
					}
					if (!node5.Data.ToString().ToUpper().StartsWith("PGN") && !node5.Data.ToString().ToUpper().StartsWith("ACRONYM") && !node5.Data.ToString().ToUpper().StartsWith("PARAMETER GROUP LABEL") && !node5.Data.ToString().ToUpper().StartsWith("SPN"))
					{
						DoSelect(node2.Row.Index, publicParametersTreeView.GetCellCheck(selectedRowIndex, 1));
						Node node6 = node.GetNode(NodeTypeEnum.FirstSibling);
						if (node6 == null)
						{
							node6 = node;
						}
						while (node6 != null)
						{
							DoSelect(node6.Row.Index, publicParametersTreeView.GetCellCheck(selectedRowIndex, 1));
							node6 = node6.GetNode(NodeTypeEnum.NextSibling);
						}
					}
					else if (parameterList.IsStructure(node2.Data.ToString()))
					{
						DoSelect(node2.Row.Index, publicParametersTreeView.GetCellCheck(selectedRowIndex, 1));
						Node node7 = node.GetNode(NodeTypeEnum.FirstSibling);
						if (node7 == null)
						{
							node7 = node;
						}
						while (node7 != null)
						{
							DoCheck(node7.Row.Index, publicParametersTreeView.GetCellCheck(selectedRowIndex, 1));
							node7 = node7.GetNode(NodeTypeEnum.NextSibling);
						}
					}
				}
			}
			else
			{
				handledByEnter = false;
				publicParametersTreeView.SetCellCheck(selectedRowIndex, 1, CheckEnum.Unchecked);
			}
		}

		private void OnTreeViewAfterEdit(object sender, RowColEventArgs e)
		{
			UpdateParameterSelection(e.Row);
		}

		public void BuildTreeView(C1FlexGrid treeView, PublicParameterSortType sortType, bool selectedStatus, string focusNodeName, string queryString)
		{
			treeView.Redraw = false;
			_parameterListViewData.CurrentParamLookup.Clear();
			InitTree(treeView);
			foreach (PCLWrapper.ParameterInfo item in parametersAvailable)
			{
				if (queryString != null && queryString.Trim() != string.Empty)
				{
					bool flag = false;
					if (item.Name.ToLower().IndexOf(queryString.ToLower()) > -1 || (searchComments && item.Description.ToLower().IndexOf(queryString.ToLower()) > -1))
					{
						flag = true;
					}
					else if (item.Children.Count > 0)
					{
						foreach (SubParameterInfo child in item.Children)
						{
							if (child.Name.ToLower().IndexOf(queryString.ToLower()) > -1 || (searchComments && child.Description.ToLower().IndexOf(queryString.ToLower()) > -1))
							{
								flag = true;
							}
						}
					}
					if (!flag)
					{
						continue;
					}
				}
				_parameterListViewData.CurrentParamLookup.Add(item.Name, null);
			}
			BuildTreeView(treeView, sortType, focusNodeName);
			treeView.Redraw = true;
		}

		public void BuildTreeView(C1FlexGrid treeView, PublicParameterSortType sortType, string focusNodeName)
		{
			//IL_00f3: Unknown result type (might be due to invalid IL or missing references)
			treeView.Redraw = false;
			treeView.Clear();
			rowIndex = 1;
			InitTree(treeView);
			try
			{
				switch (sortType)
				{
				case PublicParameterSortType.ParameterName:
					if (treeView.Cols[1].Width != -1)
					{
						listViewParameterNameColWidth = treeView.Cols[1].Width;
						listViewPGNNameColWidth = treeView.Cols[2].Width;
						listViewParameterCommentColWidth = treeView.Cols[3].Width;
					}
					BuildParameterView(treeView);
					break;
				case PublicParameterSortType.PGN:
					if (treeView.Cols[1].Width != -1)
					{
						treeViewParameterNameColWidth = treeView.Cols[1].Width;
						treeViewParameterCommentColWidth = treeView.Cols[2].Width;
					}
					BuildPGNView(treeView);
					break;
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show("Error - Failed to build tree view. (" + ex.Message + ")");
			}
			treeView.Redraw = true;
		}

		private void BuildParameterView(C1FlexGrid treeView)
		{
			BuildParentNode(treeView);
			Node node = treeView.Rows[1].Node;
			treeView.Rows[1].Node.Level = 0;
			foreach (PCLWrapper.ParameterInfo item in parametersAvailable)
			{
				if (_parameterListViewData.CurrentParamLookup.ContainsKey(item.Name))
				{
					AddParameterNode(treeView, item);
				}
			}
			treeView.Rows.RemoveRange(rowIndex + 1, treeView.Rows.Count - 1 - rowIndex);
			for (Node node2 = node.GetNode(NodeTypeEnum.FirstChild); node2 != null; node2 = node2.GetNode(NodeTypeEnum.NextSibling))
			{
				node2.Sort(SortFlags.Ascending);
			}
			node.Sort(SortFlags.Ascending);
		}

		private void BuildPGNView(C1FlexGrid treeView)
		{
			BuildParentNode(treeView);
			Node node = treeView.Rows[1].Node;
			treeView.Rows[1].Node.Level = 0;
			foreach (PCLWrapper.ParameterInfo item in parametersAvailable)
			{
				if (_parameterListViewData.CurrentParamLookup.ContainsKey(item.Name))
				{
					AddPGNNode(treeView, item);
				}
			}
			treeView.Rows.RemoveRange(rowIndex + 1, treeView.Rows.Count - 1 - rowIndex);
			for (Node node2 = node.GetNode(NodeTypeEnum.FirstChild); node2 != null; node2 = node2.GetNode(NodeTypeEnum.NextSibling))
			{
				node2.Sort(SortFlags.Ascending);
			}
			node.Sort(SortFlags.Ascending);
		}

		protected void BuildParentNode(C1FlexGrid treeView)
		{
			//IL_0168: Unknown result type (might be due to invalid IL or missing references)
			//IL_0172: Expected O, but got Unknown
			string value = "All Parameters";
			if (CurrentSortType == PublicParameterSortType.PGN)
			{
				value = "PGN";
				treeView.Cols[0].Width = 0;
				treeView.Cols[1].Width = treeViewParameterNameColWidth;
				treeView.Cols[2].Width = treeViewParameterCommentColWidth;
				treeView.Cols[3].Width = 0;
				treeView.Cols[2].StyleNew.TextAlign = TextAlignEnum.LeftCenter;
			}
			else
			{
				treeView.Cols[0].Width = 0;
				treeView.Cols[1].Width = listViewParameterNameColWidth;
				treeView.Cols[2].Width = listViewPGNNameColWidth;
				treeView.Cols[3].Width = listViewParameterCommentColWidth;
				treeView.Cols[2].StyleNew.TextAlign = TextAlignEnum.LeftCenter;
				treeView.Cols[3].StyleNew.TextAlign = TextAlignEnum.LeftCenter;
			}
			treeView.Rows.Add();
			treeView.Rows.Add();
			treeView.Rows[0].StyleNew.Font = new Font(treeView.Rows[0].Style.Font.FontFamily, treeView.Rows[0].Style.Font.Size, (FontStyle)1);
			treeView.Rows[0].TextAlign = TextAlignEnum.CenterCenter;
			treeView[0, 1] = "Parameter Name";
			treeView[1, 1] = value;
			treeView.Rows[1].IsNode = true;
			treeView.Rows[1].Node.Level = 0;
			if (CurrentSortType == PublicParameterSortType.PGN)
			{
				treeView[0, 2] = "Comments";
			}
			else
			{
				treeView[0, 2] = "PGN";
				treeView[0, 3] = "Comments";
			}
			treeView.SetCellCheck(1, 1, CheckEnum.Unchecked);
		}

		protected void AddParameterNode(C1FlexGrid treeView, PCLWrapper.ParameterInfo pgnInfo)
		{
			if (pgnInfo.Children == null)
			{
				return;
			}
			foreach (SubParameterInfo child in pgnInfo.Children)
			{
				rowIndex++;
				treeView.Rows[rowIndex].IsNode = true;
				treeView.Rows[rowIndex].Node.Level = 1;
				treeView[rowIndex, 1] = child.Name;
				treeView[rowIndex, 2] = pgnInfo.Name;
				treeView[rowIndex, 3] = child.Description;
			}
		}

		protected void AddPGNNode(C1FlexGrid treeView, PCLWrapper.ParameterInfo pgnInfo)
		{
			rowIndex++;
			treeView.Rows[rowIndex].IsNode = true;
			treeView.Rows[rowIndex].Node.Level = 1;
			treeView[rowIndex, 1] = pgnInfo.Name;
			treeView[rowIndex, 2] = pgnInfo.Description;
			if (pgnInfo.Children == null)
			{
				return;
			}
			foreach (SubParameterInfo child in pgnInfo.Children)
			{
				rowIndex++;
				treeView.Rows[rowIndex].IsNode = true;
				treeView.Rows[rowIndex].Node.Level = 2;
				treeView[rowIndex, 1] = child.Name;
				treeView[rowIndex, 2] = child.Description;
			}
		}

		private void RaiseAddParameterOnEnterEvent()
		{
			if (this.AddParameterOnEnterEvent != null)
			{
				this.AddParameterOnEnterEvent(this, EventArgs.Empty);
			}
		}

		private void RaiseShowBroadcastListEvent()
		{
			if (this.ShowBroadcastListEvent != null)
			{
				this.ShowBroadcastListEvent(this, EventArgs.Empty);
			}
		}

		private void OnTreeViewKeyDown(object sender, KeyEventArgs e)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0008: Invalid comparison between Unknown and I4
			//IL_0041: Unknown result type (might be due to invalid IL or missing references)
			//IL_0048: Invalid comparison between Unknown and I4
			if ((int)e.KeyData == 13)
			{
				int rowSel = publicParametersTreeView.RowSel;
				publicParametersTreeView.SetCellCheck(rowSel, 1, CheckEnum.Checked);
				UpdateParameterSelection(rowSel);
				RaiseAddParameterOnEnterEvent();
				handledByEnter = true;
				e.Handled = true;
			}
			else if ((int)e.KeyCode == 67 && e.Control)
			{
				Copy(publicParametersTreeView.Clip);
				e.Handled = true;
			}
			else
			{
				e.Handled = false;
			}
		}

		private void OnResizeParameterQuery(object sender, EventArgs e)
		{
			if (CurrentSortType == PublicParameterSortType.PGN)
			{
				publicParametersTreeView.Cols[2].Width = ((Control)publicParametersTreeView).Width - publicParametersTreeView.Cols[1].Width;
				treeViewParameterCommentColWidth = publicParametersTreeView.Cols[2].Width;
				listViewParameterCommentColWidth = ((Control)publicParametersTreeView).Width - (listViewParameterNameColWidth + listViewPGNNameColWidth);
			}
			else
			{
				publicParametersTreeView.Cols[3].Width = ((Control)publicParametersTreeView).Width - (publicParametersTreeView.Cols[1].Width + publicParametersTreeView.Cols[2].Width);
				listViewParameterCommentColWidth = publicParametersTreeView.Cols[3].Width;
				treeViewParameterCommentColWidth = ((Control)publicParametersTreeView).Width - treeViewParameterNameColWidth;
			}
		}

		private void OnVisibleChanged(object sender, EventArgs e)
		{
			if (((Control)this).Visible)
			{
				((Control)cmbBoxSearchSring).Select();
			}
		}

		private StringCollection GetOrderedParameterList(StringCollection paramList, PublicParameterSortType sortType)
		{
			StringCollection stringCollection = new StringCollection();
			for (int i = 2; i < publicParametersTreeView.Rows.Count; i++)
			{
				if (publicParametersTreeView.GetCellCheck(i, 1) == CheckEnum.Checked)
				{
					Node node = publicParametersTreeView.Rows[i].Node;
					Node node2 = node.GetNode(NodeTypeEnum.Parent);
					if (!(node2.Data.ToString() == "PGN"))
					{
						string value = ((!(node2.Data.ToString() != "All Parameters")) ? string.Concat(publicParametersTreeView[i, 2], ".", node.Data.ToString()) : (node2.Data.ToString() + "." + node.Data.ToString()));
						stringCollection.Add(value);
					}
				}
			}
			return stringCollection;
		}

		public void ClearAll()
		{
			int count = publicParametersTreeView.Rows.Count;
			StringEnumerator enumerator = parameterList.SelectedParameters.GetEnumerator();
			try
			{
				while (enumerator.MoveNext())
				{
					string current = enumerator.Current;
					parameterList[current].IsSelected = false;
				}
			}
			finally
			{
				if (enumerator is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
			parameterList.SelectedParameters.Clear();
			for (int i = 1; i < count; i++)
			{
				publicParametersTreeView.SetCellCheck(i, 1, CheckEnum.Unchecked);
			}
		}

		private void OnSearchButtonClick(object sender, EventArgs e)
		{
			queryString = ((Control)cmbBoxSearchSring).Text;
			searchComments = chkSearchComments.Checked;
			QueryFromTree(selectedStatus: true);
			AddToQueryList(cmbBoxSearchSring, queryString);
		}

		protected void QueryFromTree(bool selectedStatus)
		{
			Cursor current = Cursor.Current;
			Cursor.Current = Cursors.WaitCursor;
			BuildTreeView(publicParametersTreeView, CurrentSortType, selectedStatus, null, queryString);
			StringCollection orderedParameterList = GetOrderedParameterList(parameterList.SelectedParameters, currentSortType);
			for (int i = 1; i < publicParametersTreeView.Rows.Count; i++)
			{
				string value = publicParametersTreeView.Rows[i].Node.Data.ToString();
				if (orderedParameterList.Contains(value))
				{
					publicParametersTreeView.SetCellCheck(i, 1, CheckEnum.Checked);
				}
				else
				{
					publicParametersTreeView.SetCellCheck(i, 1, CheckEnum.Unchecked);
				}
			}
			Cursor.Current = current;
		}

		internal void InitializeQueryComboBox()
		{
			InitializeQueryComboBox(cmbBoxSearchSring);
		}

		protected void InitializeQueryComboBox(ComboBox comboBox)
		{
			for (int i = 0; i < 5; i++)
			{
				appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				try
				{
					string appSetting = appConfigService.GetAppSetting(ApplicationSettings.J1939_71ParameterSearchText, (ushort)(i + 1));
					AddToQueryList(comboBox, appSetting);
				}
				catch
				{
				}
			}
		}

		protected void AddToQueryList(ComboBox comboBox, string queryString)
		{
			if (comboBox != null && queryString != null && queryString.Trim() != string.Empty && !comboBox.Items.Contains((object)queryString))
			{
				if (comboBox.Items.Count >= 5)
				{
					comboBox.Items.RemoveAt(0);
				}
				comboBox.Items.Add((object)queryString);
				((Control)comboBox).Select();
				for (int i = 0; i < comboBox.Items.Count; i++)
				{
					string value = comboBox.Items[i].ToString();
					appConfigService.SetAppSetting(ApplicationSettings.J1939_71ParameterSearchText, value, (ushort)(i + 1));
				}
			}
		}

		private void Initialize()
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_0011: Expected O, but got Unknown
			//IL_002e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0038: Expected O, but got Unknown
			InitializeComponent();
			csmMenu = new ContextMenu();
			((Menu)csmMenu).MenuItems.Add(0, new MenuItem("Copy", (EventHandler)OnCopyClick));
			((Control)publicParametersTreeView).ContextMenu = csmMenu;
			publicParametersTreeView.Cols[0].Visible = false;
			publicParametersTreeView.Cols.Count = 4;
			publicParametersTreeView.ExtendLastCol = false;
			publicParametersTreeView.Tree.Column = 1;
			publicParametersTreeView.Rows.Fixed = 1;
			PopulateTree(publicParametersTreeView, isSelected: false);
			publicParametersTreeView.Cols[2].AllowResizing = true;
		}

		private void btnBroadcastParam_Click(object sender, EventArgs e)
		{
			RaiseShowBroadcastListEvent();
		}

		private void btnListenOnly_CheckedChanged(object sender, EventArgs e)
		{
			CurrentSubscriptionType = J1939SubscriptionType.ListenOnly;
		}

		private void btnRequestData_CheckedChanged(object sender, EventArgs e)
		{
			CurrentSubscriptionType = J1939SubscriptionType.RequestData;
		}
	}
	public class J1939_71ParameterQueryDialog : Form
	{
		private const string ComplexScreenCaption = "Complex";

		private Container components;

		private J1939_71ParameterQuery parameterQuery;

		private StatusBar statusBar1;

		private StatusBarPanel DataSource;

		private StatusBarPanel ConfigFile;

		private Panel panelMain;

		private Splitter splitter1;

		private DataTable screenTable;

		private SortedList deviceList;

		private Panel panelParameterView;

		private bool shouldClose;

		private Panel panel1;

		private Label lblDevices;

		private Label lblScreens;

		private ComboBox cmbBoxAvailableScreens;

		private ComboBox cmbBoxAvailableDevices;

		private Button btnClose;

		private Button btnApply;

		private CheckBox chkBoxAppend;

		private IAppConfigService appConfigService;

		public bool ShouldClose
		{
			get
			{
				return shouldClose;
			}
			set
			{
				shouldClose = value;
			}
		}

		public string CurrentScreenName
		{
			set
			{
				((Control)cmbBoxAvailableScreens).Text = value;
			}
		}

		public string DataSourceName
		{
			get
			{
				return DataSource.Text;
			}
			set
			{
				DataSource.Text = value;
			}
		}

		public event ParameterAddedOnScreenEventHandler ParameterAddedOnScreenEvent;

		public event EventHandler ShowBroadcastListDialog;

		public event CancelEventHandler ParameterQueryClosing
		{
			add
			{
				((Form)this).Closing += value;
			}
			remove
			{
				((Form)this).Closing -= value;
			}
		}

		public J1939_71ParameterQueryDialog(ICalibration datasource, IParameterListInfo paramInfo, DataTable screenTable, string dataSourceName, string confiFileName, SortedList deviceList)
		{
			InitializeComponent();
			this.deviceList = deviceList;
			this.screenTable = screenTable;
			screenTable.RowDeleting += OnScreenTableRowDeleting;
			screenTable.RowChanged += OnScreenTableRowChanged;
			screenTable.ColumnChanging += OnScreenTableColumnChanging;
			parameterQuery = new J1939_71ParameterQuery(datasource, paramInfo, screenTable);
			parameterQuery.AddParameterOnEnterEvent += btnApply_Click;
			parameterQuery.ShowBroadcastListEvent += parameterQuery_ShowBroadcastListEvent;
			Initialize();
			DataSource.Text = dataSourceName;
			DataSource.ToolTipText = dataSourceName;
			ConfigFile.Text = confiFileName;
			ConfigFile.ToolTipText = confiFileName;
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		}

		private void Initialize()
		{
			((Control)this).SuspendLayout();
			((Control)parameterQuery).Location = new Point(0, 0);
			((Control)parameterQuery).Name = "ParameterSelector";
			((Control)parameterQuery).TabIndex = 0;
			((Control)panelParameterView).Controls.Add((Control)(object)parameterQuery);
			((Control)parameterQuery).Dock = (DockStyle)5;
			((Control)this).ResumeLayout(false);
			((Control)this).MinimumSize = new Size(((Control)this).Width, ((Control)this).Height - 250);
			foreach (DataRow row in screenTable.Rows)
			{
				if ("Complex" != row["ScreenType"].ToString() && !cmbBoxAvailableScreens.Items.Contains(row["Name"]))
				{
					cmbBoxAvailableScreens.Items.Add((object)row["Name"].ToString());
				}
			}
			foreach (DictionaryEntry device in deviceList)
			{
				cmbBoxAvailableDevices.Items.Add((object)device.Key.ToString());
			}
		}

		protected override void Dispose(bool disposing)
		{
			if (shouldClose)
			{
				if (disposing && components != null)
				{
					components.Dispose();
				}
				((Form)this).Dispose(disposing);
			}
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
			//IL_0775: Unknown result type (might be due to invalid IL or missing references)
			//IL_077f: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(J1939_71ParameterQueryDialog));
			statusBar1 = new StatusBar();
			DataSource = new StatusBarPanel();
			ConfigFile = new StatusBarPanel();
			panelMain = new Panel();
			panel1 = new Panel();
			lblDevices = new Label();
			lblScreens = new Label();
			cmbBoxAvailableScreens = new ComboBox();
			cmbBoxAvailableDevices = new ComboBox();
			btnClose = new Button();
			btnApply = new Button();
			chkBoxAppend = new CheckBox();
			splitter1 = new Splitter();
			panelParameterView = new Panel();
			((ISupportInitialize)DataSource).BeginInit();
			((ISupportInitialize)ConfigFile).BeginInit();
			((Control)panelMain).SuspendLayout();
			((Control)panel1).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)statusBar1).Location = new Point(0, 557);
			((Control)statusBar1).Name = "statusBar1";
			statusBar1.Panels.AddRange((StatusBarPanel[])(object)new StatusBarPanel[2] { DataSource, ConfigFile });
			statusBar1.ShowPanels = true;
			((Control)statusBar1).Size = new Size(464, 24);
			((Control)statusBar1).TabIndex = 23;
			DataSource.AutoSize = (StatusBarPanelAutoSize)2;
			DataSource.Name = "DataSource";
			DataSource.Width = 223;
			ConfigFile.AutoSize = (StatusBarPanelAutoSize)2;
			ConfigFile.Name = "ConfigFile";
			ConfigFile.Width = 223;
			((Control)panelMain).Controls.Add((Control)(object)panel1);
			((Control)panelMain).Controls.Add((Control)(object)splitter1);
			((Control)panelMain).Controls.Add((Control)(object)panelParameterView);
			((Control)panelMain).Controls.Add((Control)(object)statusBar1);
			((Control)panelMain).Dock = (DockStyle)5;
			((Control)panelMain).Location = new Point(0, 0);
			((Control)panelMain).Name = "panelMain";
			((Control)panelMain).Size = new Size(464, 581);
			((Control)panelMain).TabIndex = 3;
			((Control)panel1).Anchor = (AnchorStyles)14;
			((Control)panel1).Controls.Add((Control)(object)lblDevices);
			((Control)panel1).Controls.Add((Control)(object)lblScreens);
			((Control)panel1).Controls.Add((Control)(object)cmbBoxAvailableScreens);
			((Control)panel1).Controls.Add((Control)(object)cmbBoxAvailableDevices);
			((Control)panel1).Controls.Add((Control)(object)btnClose);
			((Control)panel1).Controls.Add((Control)(object)btnApply);
			((Control)panel1).Controls.Add((Control)(object)chkBoxAppend);
			((Control)panel1).Location = new Point(3, 472);
			((Control)panel1).Name = "panel1";
			((Control)panel1).Size = new Size(456, 80);
			((Control)panel1).TabIndex = 26;
			((Control)lblDevices).Anchor = (AnchorStyles)6;
			((Control)lblDevices).Location = new Point(10, 31);
			((Control)lblDevices).Name = "lblDevices";
			((Control)lblDevices).Size = new Size(46, 16);
			((Control)lblDevices).TabIndex = 46;
			((Control)lblDevices).Text = "Devices";
			((Control)lblScreens).Anchor = (AnchorStyles)6;
			((Control)lblScreens).Location = new Point(9, 8);
			((Control)lblScreens).Name = "lblScreens";
			((Control)lblScreens).Size = new Size(46, 16);
			((Control)lblScreens).TabIndex = 43;
			((Control)lblScreens).Text = "Screens";
			((Control)cmbBoxAvailableScreens).Anchor = (AnchorStyles)14;
			cmbBoxAvailableScreens.DropDownStyle = (ComboBoxStyle)2;
			((Control)cmbBoxAvailableScreens).Location = new Point(62, 5);
			((Control)cmbBoxAvailableScreens).Name = "cmbBoxAvailableScreens";
			((Control)cmbBoxAvailableScreens).Size = new Size(307, 21);
			((Control)cmbBoxAvailableScreens).TabIndex = 39;
			((Control)cmbBoxAvailableDevices).Anchor = (AnchorStyles)14;
			cmbBoxAvailableDevices.DropDownStyle = (ComboBoxStyle)2;
			((Control)cmbBoxAvailableDevices).Location = new Point(62, 30);
			((Control)cmbBoxAvailableDevices).Name = "cmbBoxAvailableDevices";
			((Control)cmbBoxAvailableDevices).Size = new Size(307, 21);
			((Control)cmbBoxAvailableDevices).TabIndex = 45;
			((Control)btnClose).Anchor = (AnchorStyles)10;
			btnClose.DialogResult = (DialogResult)2;
			((Control)btnClose).Location = new Point(381, 54);
			((Control)btnClose).Name = "btnClose";
			((Control)btnClose).Size = new Size(72, 24);
			((Control)btnClose).TabIndex = 42;
			((Control)btnClose).Text = "Close";
			((Control)btnClose).Click += btnClose_Click;
			((Control)btnApply).Anchor = (AnchorStyles)10;
			((Control)btnApply).Location = new Point(297, 54);
			((Control)btnApply).Name = "btnApply";
			((Control)btnApply).Size = new Size(72, 24);
			((Control)btnApply).TabIndex = 40;
			((Control)btnApply).Text = "Apply";
			((Control)btnApply).Click += btnApply_Click;
			((Control)chkBoxAppend).Anchor = (AnchorStyles)10;
			((Control)chkBoxAppend).AutoSize = true;
			chkBoxAppend.Checked = true;
			chkBoxAppend.CheckState = (CheckState)1;
			((Control)chkBoxAppend).Location = new Point(386, 5);
			((Control)chkBoxAppend).Name = "chkBoxAppend";
			((Control)chkBoxAppend).Size = new Size(63, 17);
			((Control)chkBoxAppend).TabIndex = 44;
			((Control)chkBoxAppend).Text = "Append";
			((ButtonBase)chkBoxAppend).UseVisualStyleBackColor = true;
			chkBoxAppend.CheckedChanged += OnAppendCheckedChanged;
			((Control)splitter1).Dock = (DockStyle)1;
			((Control)splitter1).Location = new Point(0, 0);
			((Control)splitter1).Name = "splitter1";
			((Control)splitter1).Size = new Size(464, 3);
			((Control)splitter1).TabIndex = 25;
			splitter1.TabStop = false;
			((Control)panelParameterView).Anchor = (AnchorStyles)15;
			((Control)panelParameterView).Location = new Point(0, 0);
			((Control)panelParameterView).Name = "panelParameterView";
			((Control)panelParameterView).Size = new Size(464, 466);
			((Control)panelParameterView).TabIndex = 24;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).ClientSize = new Size(464, 581);
			((Control)this).Controls.Add((Control)(object)panelMain);
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).KeyPreview = true;
			((Form)this).MaximizeBox = false;
			((Control)this).Name = "J1939_71ParameterQueryDialog";
			((Control)this).Text = "J1939ParameterQuery";
			((Form)this).TopMost = true;
			((Form)this).Activated += OnJ1939ParameterQueryDialogActivated;
			((Form)this).Load += OnJ1939ParameterQueryDialogLoad;
			((ISupportInitialize)DataSource).EndInit();
			((ISupportInitialize)ConfigFile).EndInit();
			((Control)panelMain).ResumeLayout(false);
			((Control)panel1).ResumeLayout(false);
			((Control)panel1).PerformLayout();
			((Control)this).ResumeLayout(false);
		}

		private void OnbtnCancelClick(object sender, EventArgs e)
		{
			((Form)this).DialogResult = (DialogResult)2;
		}

		private void OnScreenTableRowDeleting(object sender, DataRowChangeEventArgs e)
		{
			if (e.Action == DataRowAction.Delete && cmbBoxAvailableScreens.Items.Contains((object)e.Row["Name"].ToString()))
			{
				cmbBoxAvailableScreens.Items.Remove(e.Row["Name"]);
				SelectComboBoxAvailableScreensItem();
			}
		}

		private void OnScreenTableRowChanged(object sender, DataRowChangeEventArgs e)
		{
			if (e.Action == DataRowAction.Add && "Complex" != e.Row["ScreenType"].ToString() && !cmbBoxAvailableScreens.Items.Contains(e.Row["Name"]))
			{
				cmbBoxAvailableScreens.Items.Add((object)e.Row["Name"].ToString());
				SelectComboBoxAvailableScreensItem();
			}
		}

		private void OnScreenTableColumnChanging(object sender, DataColumnChangeEventArgs e)
		{
			if (e.Row.RowState == DataRowState.Detached || !(e.Column.ColumnName == "Name"))
			{
				return;
			}
			string text = e.ProposedValue.ToString();
			string text2 = e.Row["Name"].ToString();
			if (cmbBoxAvailableScreens.Items.Contains((object)text2))
			{
				bool flag = ((Control)cmbBoxAvailableScreens).Text == text2;
				cmbBoxAvailableScreens.Items.Remove((object)text2);
				cmbBoxAvailableScreens.Items.Add((object)text);
				if (flag)
				{
					((Control)cmbBoxAvailableScreens).Text = text;
				}
			}
		}

		private void parameterQuery_ShowBroadcastListEvent(object sender, EventArgs e)
		{
			this.ShowBroadcastListDialog(sender, e);
		}

		private void btnApply_Click(object sender, EventArgs e)
		{
			//IL_00b1: Unknown result type (might be due to invalid IL or missing references)
			if (((Control)cmbBoxAvailableScreens).Text != string.Empty)
			{
				if (this.ParameterAddedOnScreenEvent != null)
				{
					Cursor cursor = ((Control)this).Cursor;
					((Control)this).Cursor = Cursors.WaitCursor;
					bool isBroadcast = parameterQuery.CurrentSubscriptionType == J1939SubscriptionType.ListenOnly;
					IAddressValue sourceAddress = AddressFactory.ProductAddressValue(((Control)cmbBoxAvailableDevices).Text);
					try
					{
						ParameterAddedOnScreenEventArgs e2 = new ParameterAddedOnScreenEventArgs(((Control)cmbBoxAvailableScreens).Text, parameterQuery.SelectedParameter, chkBoxAppend.Checked);
						this.ParameterAddedOnScreenEvent(this, e2, isBroadcast, sourceAddress);
						parameterQuery.ClearAll();
					}
					finally
					{
						((Control)this).Cursor = cursor;
					}
				}
			}
			else
			{
				MessageBox.Show("Please select the screen name first", "J1939-71 ParameterQuery");
			}
		}

		private void btnClose_Click(object sender, EventArgs e)
		{
			((Control)this).Visible = false;
		}

		private void OnJ1939ParameterQueryDialogLoad(object sender, EventArgs e)
		{
			parameterQuery.InitializeQueryComboBox();
			SelectComboBoxAvailableScreensItem();
			chkBoxAppend.Checked = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AppendCheckBoxState));
			if (cmbBoxAvailableDevices.Items.Count > 0 && ((Control)cmbBoxAvailableDevices).Text == string.Empty)
			{
				((Control)cmbBoxAvailableDevices).Text = cmbBoxAvailableDevices.Items[0].ToString();
			}
		}

		private void OnAppendCheckedChanged(object sender, EventArgs e)
		{
			appConfigService.SetAppSetting(ApplicationSettings.AppendCheckBoxState, chkBoxAppend.Checked.ToString());
		}

		private void OnJ1939ParameterQueryDialogActivated(object sender, EventArgs e)
		{
			parameterQuery.InitializeQueryComboBox();
		}

		private void SelectComboBoxAvailableScreensItem()
		{
			if (cmbBoxAvailableScreens.Items.Count > 0 && ((Control)cmbBoxAvailableScreens).Text == string.Empty)
			{
				((Control)cmbBoxAvailableScreens).Text = cmbBoxAvailableScreens.Items[0].ToString();
			}
		}
	}
	public class ParameterAddedOnScreenEventArgs : EventArgs
	{
		private string screenName;

		private StringCollection parametersSelected;

		private bool isAppend = true;

		public string ScreenName => screenName;

		public StringCollection ParametersSelected => parametersSelected;

		public bool IsAppend => isAppend;

		public ParameterAddedOnScreenEventArgs(string screenName, StringCollection selectedParametets, bool isAppend)
		{
			this.screenName = screenName;
			parametersSelected = selectedParametets;
			this.isAppend = isAppend;
		}
	}
}
namespace Cummins.Calibration
{
	public class ParameterListViewData
	{
		protected TreeNode currentFocusNode;

		protected string currentFocusNodeName;

		protected SortedList currentParamLookup = new SortedList();

		public TreeNode CurrentFocusNode
		{
			get
			{
				return currentFocusNode;
			}
			set
			{
				currentFocusNode = value;
			}
		}

		public string CurrentFocusNodeName
		{
			get
			{
				return currentFocusNodeName;
			}
			set
			{
				currentFocusNodeName = value;
			}
		}

		public SortedList CurrentParamLookup
		{
			get
			{
				return currentParamLookup;
			}
			set
			{
				currentParamLookup = value;
			}
		}

		public ParameterListViewData()
		{
			currentFocusNode = null;
			currentFocusNodeName = null;
		}
	}
	public class ParameterListViewHelpers
	{
		public static ArrayList GetOrderedParameterList(ParameterListViewData parameterListViewData, IParameterListInfo paramListInfo, StringCollection paramList, TreeViewSortingType sortType)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Expected O, but got Unknown
			TreeView val = new TreeView();
			val.Sorted = true;
			BuildTreeView(parameterListViewData, paramListInfo, val, paramList, sortType, null);
			ArrayList arrayList = new ArrayList(paramList.Count);
			BuildOrderedParameterList(val.Nodes, arrayList, paramListInfo.Parameters);
			return arrayList;
		}

		private static void BuildOrderedParameterList(TreeNodeCollection nodeList, ArrayList orderedParameterList, IParamInfoList paramInfoList)
		{
			if (nodeList == null)
			{
				return;
			}
			for (int i = 0; i < nodeList.Count; i++)
			{
				TreeNode val = nodeList[i];
				if (paramInfoList[val.Text] != null && !orderedParameterList.Contains(val.Text))
				{
					orderedParameterList.Add(val.Text);
				}
				BuildOrderedParameterList(val.Nodes, orderedParameterList, paramInfoList);
			}
		}

		public static void BuildTreeView(ParameterListViewData parameterListViewData, TreeView treeView, TreeViewSortingType sortType, bool selectedStatus, IParameterListInfo paramListInfo, string focusNodeName)
		{
			StringCollection stringCollection = new StringCollection();
			foreach (string key in paramListInfo.Parameters.Keys)
			{
				IParamInfo paramInfo = paramListInfo.Parameters[key];
				if ((paramListInfo.IncludeRuntimeParameters || !paramInfo.IsRuntime) && (paramListInfo.IncludeSubfile3Parameters || !paramInfo.SubfileName.Equals("3")) && (!paramInfo.FullName.StartsWith("Config") || !paramListInfo.ExcludeCodeParameters || !paramInfo.IsCodeTypeParameter) && paramInfo.IsSelected == selectedStatus)
				{
					stringCollection.Add(key);
				}
			}
			BuildTreeView(parameterListViewData, paramListInfo, treeView, stringCollection, sortType, focusNodeName);
		}

		public static void BuildTreeView(ParameterListViewData parameterListViewData, IParameterListInfo paramListInfo, TreeView treeView, StringCollection paramList, TreeViewSortingType sortType, string focusNodeName)
		{
			//IL_00a8: Unknown result type (might be due to invalid IL or missing references)
			treeView.Nodes.Clear();
			parameterListViewData.CurrentFocusNode = null;
			parameterListViewData.CurrentFocusNodeName = focusNodeName;
			parameterListViewData.CurrentParamLookup.Clear();
			StringEnumerator enumerator = paramList.GetEnumerator();
			try
			{
				while (enumerator.MoveNext())
				{
					string current = enumerator.Current;
					parameterListViewData.CurrentParamLookup.Add(current, null);
				}
			}
			finally
			{
				if (enumerator is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
			try
			{
				switch (sortType)
				{
				case TreeViewSortingType.Parameter:
					BuildParameterView(parameterListViewData, paramListInfo, treeView);
					break;
				case TreeViewSortingType.Group:
					BuildGroupView(parameterListViewData, paramListInfo, treeView);
					break;
				default:
					BuildSubfileView(parameterListViewData, paramListInfo, treeView);
					break;
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show("Error - Failed to build tree view. (" + ex.Message + ")");
			}
			if (parameterListViewData.CurrentFocusNode != null)
			{
				parameterListViewData.CurrentFocusNode.EnsureVisible();
			}
		}

		private static void BuildParameterView(ParameterListViewData parameterListViewData, IParameterListInfo paramListInfo, TreeView treeView)
		{
			//IL_0005: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			TreeNode val = new TreeNode("All Parameters");
			foreach (string key in parameterListViewData.CurrentParamLookup.Keys)
			{
				AddParameterNode(parameterListViewData, paramListInfo, val.Nodes, key, null);
			}
			if (val.Nodes.Count > 0)
			{
				treeView.Nodes.Add(val);
			}
		}

		private static void BuildGroupView(ParameterListViewData parameterListViewData, IParameterListInfo paramListInfo, TreeView treeView)
		{
			foreach (string key in paramListInfo.Groups.Keys)
			{
				AddGroupNode(parameterListViewData, paramListInfo, treeView.Nodes, key, null);
			}
			foreach (string key2 in paramListInfo.Structure.Keys)
			{
				AddGroupNode(parameterListViewData, paramListInfo, treeView.Nodes, key2, null);
			}
		}

		private static void BuildSubfileView(ParameterListViewData parameterListViewData, IParameterListInfo paramListInfo, TreeView treeView)
		{
			//IL_0061: Unknown result type (might be due to invalid IL or missing references)
			//IL_0067: Expected O, but got Unknown
			//IL_004e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0054: Expected O, but got Unknown
			foreach (string key in paramListInfo.Subfile.Keys)
			{
				if (!paramListInfo.IncludeSubfile3Parameters && key.Equals("3"))
				{
					continue;
				}
				TreeNode val = ((!key.Equals("-1")) ? new TreeNode("Subfile " + key) : new TreeNode("Subfile"));
				StringCollection stringCollection = (StringCollection)paramListInfo.Subfile[key];
				StringEnumerator enumerator2 = stringCollection.GetEnumerator();
				try
				{
					while (enumerator2.MoveNext())
					{
						string current = enumerator2.Current;
						AddGroupNode(parameterListViewData, paramListInfo, val.Nodes, current, key);
					}
				}
				finally
				{
					if (enumerator2 is IDisposable disposable)
					{
						disposable.Dispose();
					}
				}
				if (val.Nodes.Count > 0)
				{
					treeView.Nodes.Add(val);
				}
			}
		}

		private static void AddGroupNode(ParameterListViewData parameterListViewData, IParameterListInfo paramListInfo, TreeNodeCollection nodes, string groupName, string subfileName)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0007: Expected O, but got Unknown
			TreeNode val = new TreeNode(groupName);
			StringCollection stringCollection = new StringCollection();
			if (paramListInfo.Groups[groupName] != null)
			{
				stringCollection = ((ParameterListInfo.GroupInfo)paramListInfo.Groups[groupName]).ParameterList;
			}
			else if (paramListInfo.IncludeRuntimeParameters || groupName == "DataplateStructure")
			{
				stringCollection = ((ParameterListInfo.GroupInfo)paramListInfo.Structure[groupName]).ParameterList;
			}
			StringEnumerator enumerator = stringCollection.GetEnumerator();
			try
			{
				while (enumerator.MoveNext())
				{
					string current = enumerator.Current;
					AddParameterNode(parameterListViewData, paramListInfo, val.Nodes, current, subfileName);
				}
			}
			finally
			{
				if (enumerator is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
			if (val.Nodes.Count > 0)
			{
				nodes.Add(val);
				if (groupName.Equals(parameterListViewData.CurrentFocusNodeName))
				{
					parameterListViewData.CurrentFocusNode = val;
				}
			}
		}

		private static void AddParameterNode(ParameterListViewData parameterListViewData, IParameterListInfo paramListInfo, TreeNodeCollection nodes, string paramName, string subfileName)
		{
			if (!parameterListViewData.CurrentParamLookup.ContainsKey(paramName))
			{
				return;
			}
			IParamInfo paramInfo = paramListInfo.Parameters[paramName];
			if (paramInfo != null && (paramInfo.IsTable || !paramInfo.IsAxis) && (subfileName == null || paramInfo.SubfileName.Equals(subfileName)))
			{
				TreeNode val = nodes.Add(paramName);
				if (paramName.Equals(parameterListViewData.CurrentFocusNodeName))
				{
					parameterListViewData.CurrentFocusNode = val;
				}
				if (paramInfo.IsTable && paramInfo.TableAxisInfo != null)
				{
					AddAxisChildNode(val, paramInfo.TableAxisInfo.XAxisName);
					AddAxisChildNode(val, paramInfo.TableAxisInfo.YAxisName);
				}
			}
		}

		private static void AddAxisChildNode(TreeNode tableNode, string axisName)
		{
			if (axisName.Length > 0)
			{
				TreeNode val = tableNode.Nodes.Add(axisName);
				val.Tag = "Axis";
			}
		}
	}
}
namespace Cummins.ParameterSelector
{
	public enum ParameterSelectionCriteria
	{
		ShowAll,
		ShowInterface,
		HideInterface
	}
	public enum ParameterSortType
	{
		ParameterName,
		Subfile,
		Group
	}
	public enum ParameterFilterMode
	{
		Include,
		Exclude
	}
	public class ParameterQueryConfiguration
	{
		private ParameterSelectionCriteria selectionCriteria;

		private bool serachComments = true;

		private bool showComemnt = true;

		private ParameterSortType sortType;

		private ParameterFilterMode filterMode;

		private string filterFile = string.Empty;

		public ParameterSelectionCriteria SelectionCriteria
		{
			get
			{
				return selectionCriteria;
			}
			set
			{
				selectionCriteria = value;
			}
		}

		public bool SerachComments
		{
			get
			{
				return serachComments;
			}
			set
			{
				serachComments = value;
			}
		}

		public bool ShowComemnt
		{
			get
			{
				return showComemnt;
			}
			set
			{
				showComemnt = value;
			}
		}

		public ParameterSortType SortType
		{
			get
			{
				return sortType;
			}
			set
			{
				sortType = value;
			}
		}

		public ParameterFilterMode FilterMode
		{
			get
			{
				return filterMode;
			}
			set
			{
				filterMode = value;
			}
		}

		public string FilterFile
		{
			get
			{
				return filterFile;
			}
			set
			{
				filterFile = value;
			}
		}
	}
	public delegate void ParameterAddedOnScreenEventHandler(object sender, ParameterAddedOnScreenEventArgs e, bool isBroadcast, IAddressValue sourceAddress);
	public class ParameterQueryDialog : Form
	{
		private const string ComplexScreenCaption = "Complex";

		private Container components;

		private ParameterQuery parameterQuery;

		private StatusBar statusBar1;

		private StatusBarPanel DataSource;

		private StatusBarPanel ConfigFile;

		private Panel panelMain;

		private DataTable screenTable;

		private bool shouldClose;

		private Panel panelParameterView;

		private Panel panel2;

		private CheckBox chkBoxAppend;

		private ComboBox comboBoxAvailableScreens;

		private Button btnOK;

		private Button btnCancel;

		private Label labelScreen;

		private IAppConfigService appConfigService;

		public bool ShouldClose
		{
			get
			{
				return shouldClose;
			}
			set
			{
				shouldClose = value;
			}
		}

		public string CurrentScreenName
		{
			set
			{
				((Control)comboBoxAvailableScreens).Text = value;
			}
		}

		public string DataSourceName
		{
			get
			{
				return DataSource.Text;
			}
			set
			{
				DataSource.Text = value;
			}
		}

		public event ParameterAddedOnScreenEventHandler ParameterAddedOnScreenEvent;

		public event CancelEventHandler ParameterQueryClosing
		{
			add
			{
				((Form)this).Closing += value;
			}
			remove
			{
				((Form)this).Closing -= value;
			}
		}

		public ParameterQueryDialog(IParameterListInfo paramInfo, DataTable screenTable, string dataSourceName, string confiFileName, bool isDataSourceOffline)
		{
			InitializeComponent();
			this.screenTable = screenTable;
			screenTable.RowDeleting += OnScreenTableRowDeleting;
			screenTable.RowChanged += OnScreenTableRowChanged;
			screenTable.ColumnChanging += OnScreenTableColumnChanging;
			parameterQuery = new ParameterQuery((IParameterListInfo)paramInfo.Clone(), isDataSourceOffline);
			parameterQuery.AddParameterOnEnterEvent += btnOK_Click;
			Initialize();
			DataSource.Text = dataSourceName;
			DataSource.ToolTipText = dataSourceName;
			ConfigFile.Text = confiFileName;
			ConfigFile.ToolTipText = confiFileName;
			appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
		}

		private void Initialize()
		{
			((Control)this).SuspendLayout();
			((Control)parameterQuery).Location = new Point(0, 0);
			((Control)parameterQuery).Name = "ParameterSelector";
			((Control)parameterQuery).TabIndex = 0;
			((Control)panelParameterView).Controls.Add((Control)(object)parameterQuery);
			((Control)parameterQuery).Dock = (DockStyle)5;
			((Control)this).ResumeLayout(false);
			((Control)this).MinimumSize = new Size(((Control)this).Width, ((Control)this).Height - 250);
			foreach (DataRow row in screenTable.Rows)
			{
				if ("Complex" != row["ScreenType"].ToString() && !comboBoxAvailableScreens.Items.Contains(row["Name"]))
				{
					comboBoxAvailableScreens.Items.Add((object)row["Name"].ToString());
				}
			}
		}

		protected override void Dispose(bool disposing)
		{
			if (shouldClose)
			{
				if (disposing && components != null)
				{
					components.Dispose();
				}
				((Form)this).Dispose(disposing);
			}
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
			//IL_05f5: Unknown result type (might be due to invalid IL or missing references)
			//IL_05ff: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(ParameterQueryDialog));
			statusBar1 = new StatusBar();
			DataSource = new StatusBarPanel();
			ConfigFile = new StatusBarPanel();
			panelMain = new Panel();
			panel2 = new Panel();
			chkBoxAppend = new CheckBox();
			comboBoxAvailableScreens = new ComboBox();
			btnOK = new Button();
			btnCancel = new Button();
			labelScreen = new Label();
			panelParameterView = new Panel();
			((ISupportInitialize)DataSource).BeginInit();
			((ISupportInitialize)ConfigFile).BeginInit();
			((Control)panelMain).SuspendLayout();
			((Control)panel2).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)statusBar1).Location = new Point(0, 557);
			((Control)statusBar1).Name = "statusBar1";
			statusBar1.Panels.AddRange((StatusBarPanel[])(object)new StatusBarPanel[2] { DataSource, ConfigFile });
			statusBar1.ShowPanels = true;
			((Control)statusBar1).Size = new Size(464, 24);
			((Control)statusBar1).TabIndex = 23;
			DataSource.AutoSize = (StatusBarPanelAutoSize)2;
			DataSource.Name = "DataSource";
			DataSource.Width = 223;
			ConfigFile.AutoSize = (StatusBarPanelAutoSize)2;
			ConfigFile.Name = "ConfigFile";
			ConfigFile.Width = 223;
			((Control)panelMain).Controls.Add((Control)(object)panel2);
			((Control)panelMain).Controls.Add((Control)(object)panelParameterView);
			((Control)panelMain).Controls.Add((Control)(object)statusBar1);
			((Control)panelMain).Dock = (DockStyle)5;
			((Control)panelMain).Location = new Point(0, 0);
			((Control)panelMain).Name = "panelMain";
			((Control)panelMain).Size = new Size(464, 581);
			((Control)panelMain).TabIndex = 3;
			((Control)panel2).Anchor = (AnchorStyles)14;
			((Control)panel2).Controls.Add((Control)(object)chkBoxAppend);
			((Control)panel2).Controls.Add((Control)(object)comboBoxAvailableScreens);
			((Control)panel2).Controls.Add((Control)(object)btnOK);
			((Control)panel2).Controls.Add((Control)(object)btnCancel);
			((Control)panel2).Controls.Add((Control)(object)labelScreen);
			((Control)panel2).Location = new Point(4, 491);
			((Control)panel2).Name = "panel2";
			((Control)panel2).Size = new Size(457, 60);
			((Control)panel2).TabIndex = 26;
			((Control)chkBoxAppend).Anchor = (AnchorStyles)10;
			chkBoxAppend.Checked = true;
			chkBoxAppend.CheckState = (CheckState)1;
			((Control)chkBoxAppend).Location = new Point(381, 9);
			((Control)chkBoxAppend).Name = "chkBoxAppend";
			((Control)chkBoxAppend).Size = new Size(63, 20);
			((Control)chkBoxAppend).TabIndex = 44;
			((Control)chkBoxAppend).Text = "Append";
			((ButtonBase)chkBoxAppend).UseVisualStyleBackColor = true;
			chkBoxAppend.CheckedChanged += OnAppendCheckedChanged;
			((Control)comboBoxAvailableScreens).Anchor = (AnchorStyles)14;
			comboBoxAvailableScreens.DropDownStyle = (ComboBoxStyle)2;
			((Control)comboBoxAvailableScreens).Location = new Point(55, 8);
			((Control)comboBoxAvailableScreens).Name = "comboBoxAvailableScreens";
			((Control)comboBoxAvailableScreens).Size = new Size(320, 21);
			((Control)comboBoxAvailableScreens).TabIndex = 39;
			((Control)btnOK).Anchor = (AnchorStyles)10;
			((Control)btnOK).Location = new Point(296, 34);
			((Control)btnOK).Name = "btnOK";
			((Control)btnOK).Size = new Size(72, 24);
			((Control)btnOK).TabIndex = 40;
			((Control)btnOK).Text = "Apply";
			((Control)btnOK).Click += btnOK_Click;
			((Control)btnCancel).Anchor = (AnchorStyles)10;
			btnCancel.DialogResult = (DialogResult)2;
			((Control)btnCancel).Location = new Point(374, 34);
			((Control)btnCancel).Name = "btnCancel";
			((Control)btnCancel).Size = new Size(72, 24);
			((Control)btnCancel).TabIndex = 42;
			((Control)btnCancel).Text = "Close";
			((Control)btnCancel).Click += btnCancel_Click;
			((Control)labelScreen).Anchor = (AnchorStyles)14;
			((Control)labelScreen).Location = new Point(3, 9);
			((Control)labelScreen).Name = "labelScreen";
			((Control)labelScreen).Size = new Size(46, 19);
			((Control)labelScreen).TabIndex = 43;
			((Control)labelScreen).Text = "Screens";
			((Control)panelParameterView).Anchor = (AnchorStyles)15;
			panelParameterView.AutoSizeMode = (AutoSizeMode)0;
			((Control)panelParameterView).Location = new Point(0, 0);
			((Control)panelParameterView).Name = "panelParameterView";
			((Control)panelParameterView).Size = new Size(464, 485);
			((Control)panelParameterView).TabIndex = 24;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).ClientSize = new Size(464, 581);
			((Control)this).Controls.Add((Control)(object)panelMain);
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).KeyPreview = true;
			((Form)this).MaximizeBox = false;
			((Control)this).Name = "ParameterQueryDialog";
			((Control)this).Text = "ParameterQuery";
			((Form)this).TopMost = true;
			((Form)this).Activated += OnParameterQueryDialogActivated;
			((Form)this).Load += OnParameterQueryDialogLoad;
			((ISupportInitialize)DataSource).EndInit();
			((ISupportInitialize)ConfigFile).EndInit();
			((Control)panelMain).ResumeLayout(false);
			((Control)panel2).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private void OnbtnCancelClick(object sender, EventArgs e)
		{
			((Form)this).DialogResult = (DialogResult)2;
		}

		private void OnScreenTableRowDeleting(object sender, DataRowChangeEventArgs e)
		{
			if (e.Action == DataRowAction.Delete && comboBoxAvailableScreens.Items.Contains((object)e.Row["Name"].ToString()))
			{
				comboBoxAvailableScreens.Items.Remove(e.Row["Name"]);
				SelectComboBoxAvailableScreensItem();
			}
		}

		private void OnScreenTableRowChanged(object sender, DataRowChangeEventArgs e)
		{
			if (e.Action == DataRowAction.Add && "Complex" != e.Row["ScreenType"].ToString() && !comboBoxAvailableScreens.Items.Contains(e.Row["Name"]))
			{
				comboBoxAvailableScreens.Items.Add((object)e.Row["Name"].ToString());
				SelectComboBoxAvailableScreensItem();
			}
		}

		private void OnScreenTableColumnChanging(object sender, DataColumnChangeEventArgs e)
		{
			if (e.Row.RowState == DataRowState.Detached || !(e.Column.ColumnName == "Name"))
			{
				return;
			}
			string text = e.ProposedValue.ToString();
			string text2 = e.Row["Name"].ToString();
			if (comboBoxAvailableScreens.Items.Contains((object)text2))
			{
				bool flag = ((Control)comboBoxAvailableScreens).Text == text2;
				comboBoxAvailableScreens.Items.Remove((object)text2);
				comboBoxAvailableScreens.Items.Add((object)text);
				if (flag)
				{
					((Control)comboBoxAvailableScreens).Text = text;
				}
			}
		}

		private void btnOK_Click(object sender, EventArgs e)
		{
			//IL_0088: Unknown result type (might be due to invalid IL or missing references)
			if (((Control)comboBoxAvailableScreens).Text != string.Empty)
			{
				if (this.ParameterAddedOnScreenEvent != null)
				{
					Cursor cursor = ((Control)this).Cursor;
					((Control)this).Cursor = Cursors.WaitCursor;
					bool isBroadcast = false;
					try
					{
						ParameterAddedOnScreenEventArgs e2 = new ParameterAddedOnScreenEventArgs(((Control)comboBoxAvailableScreens).Text, parameterQuery.SelectedParameter, chkBoxAppend.Checked);
						this.ParameterAddedOnScreenEvent(this, e2, isBroadcast, null);
						parameterQuery.ClearAll();
					}
					finally
					{
						((Control)this).Cursor = cursor;
					}
				}
			}
			else
			{
				MessageBox.Show("Please select the screen name first", "ParameterQuery");
			}
		}

		private void buttonClearAll_Click(object sender, EventArgs e)
		{
			parameterQuery.ClearAll();
		}

		private void btnCancel_Click(object sender, EventArgs e)
		{
			((Control)this).Visible = false;
		}

		private void OnParameterQueryDialogLoad(object sender, EventArgs e)
		{
			parameterQuery.InitializeQueryComboBox();
			SelectComboBoxAvailableScreensItem();
			chkBoxAppend.Checked = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.AppendCheckBoxState));
		}

		private void OnAppendCheckedChanged(object sender, EventArgs e)
		{
			appConfigService.SetAppSetting(ApplicationSettings.AppendCheckBoxState, chkBoxAppend.Checked.ToString());
		}

		private void OnParameterQueryDialogActivated(object sender, EventArgs e)
		{
			parameterQuery.InitializeQueryComboBox();
		}

		private void SelectComboBoxAvailableScreensItem()
		{
			if (comboBoxAvailableScreens.Items.Count > 0 && ((Control)comboBoxAvailableScreens).Text == string.Empty)
			{
				((Control)comboBoxAvailableScreens).Text = comboBoxAvailableScreens.Items[0].ToString();
			}
		}
	}
}
namespace Cummins.ParameterSelector.Properties
{
	[DebuggerNonUserCode]
	[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "4.0.0.0")]
	[CompilerGenerated]
	internal class Resources
	{
		private static ResourceManager resourceMan;

		private static CultureInfo resourceCulture;

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static ResourceManager ResourceManager
		{
			get
			{
				if (object.ReferenceEquals(resourceMan, null))
				{
					ResourceManager resourceManager = new ResourceManager("Cummins.ParameterSelector.Properties.Resources", typeof(Resources).Assembly);
					resourceMan = resourceManager;
				}
				return resourceMan;
			}
		}

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static CultureInfo Culture
		{
			get
			{
				return resourceCulture;
			}
			set
			{
				resourceCulture = value;
			}
		}

		internal static Bitmap collapseIcon
		{
			get
			{
				//IL_0016: Unknown result type (might be due to invalid IL or missing references)
				//IL_001c: Expected O, but got Unknown
				object obj = ResourceManager.GetObject("collapseIcon", resourceCulture);
				return (Bitmap)obj;
			}
		}

		internal static Bitmap expandIcon
		{
			get
			{
				//IL_0016: Unknown result type (might be due to invalid IL or missing references)
				//IL_001c: Expected O, but got Unknown
				object obj = ResourceManager.GetObject("expandIcon", resourceCulture);
				return (Bitmap)obj;
			}
		}

		internal Resources()
		{
		}
	}
}
