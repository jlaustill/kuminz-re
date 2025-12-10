using System;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Windows.Forms;
using Cummins.Calibration;
using Cummins.EventLog;
using Cummins.Interop.CalDataServer;
using Cummins.Interop.Error;
using Cummins.Parameter;
using Cummins.Widgets;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - HexEditor")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTitle("Poodle")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.HexEditor;

public class HexEditor
{
	private HexEditorModel model;

	private HexEditorController controller;

	private HexEditorView view;

	private ICalibration currentCalibration;

	public HexEditorView View => view;

	public HexEditor()
	{
		model = new HexEditorModel();
		controller = new HexEditorController(model);
		view = new HexEditorView(model, controller);
	}

	public bool OpenHexEdit(ICalibration calibration)
	{
		bool result = true;
		try
		{
			currentCalibration = calibration;
			model.LoadCalibration(calibration);
		}
		catch (Exception)
		{
			result = false;
		}
		return result;
	}

	public bool Save()
	{
		return model.SaveHexData();
	}

	public bool SaveAs(string newFileName)
	{
		return model.SaveHexDataAs(newFileName);
	}
}
public class HexEditorController
{
	private HexEditorModel model;

	public HexEditorModel Model
	{
		get
		{
			return model;
		}
		set
		{
			model = value;
		}
	}

	public HexEditorController()
	{
	}

	public HexEditorController(HexEditorModel model)
	{
		Model = model;
	}

	public void SelectHexRange(int startAddress, int length)
	{
		Cursor current = Cursor.Current;
		try
		{
			Cursor.Current = Cursors.WaitCursor;
			Model.RetrieveHexData(startAddress, length);
		}
		finally
		{
			Cursor.Current = current;
		}
	}

	public void Undo()
	{
		try
		{
			Model.Undo();
		}
		catch
		{
		}
	}

	public void RevertAll()
	{
		try
		{
			Model.RevertAll();
		}
		catch
		{
		}
	}

	public bool Shutdown()
	{
		bool flag = true;
		return Shutdown(requestSavePrompt: true);
	}

	public bool Shutdown(bool requestSavePrompt)
	{
		//IL_0057: Unknown result type (might be due to invalid IL or missing references)
		//IL_005d: Invalid comparison between Unknown and I4
		bool result = true;
		if (requestSavePrompt)
		{
			string text = ShouldSave();
			if (text != "saved")
			{
				if (text == "yes")
				{
					if (model.SaveHexData())
					{
						model.RaiseStateChangedEvent(ChangeType.SavedAll, new Pointer(0, 0));
					}
					else if ((int)MessageBox.Show("Warning! Save was not successful. Do you want to exit anyway?", "Calibration Editor", (MessageBoxButtons)4, (MessageBoxIcon)32) != 6)
					{
						result = false;
					}
				}
				else if (!(text == "no"))
				{
					result = false;
				}
			}
		}
		return result;
	}

	public string ShouldSave()
	{
		//IL_0007: Unknown result type (might be due to invalid IL or missing references)
		//IL_003f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0044: Unknown result type (might be due to invalid IL or missing references)
		//IL_0045: Unknown result type (might be due to invalid IL or missing references)
		//IL_0047: Invalid comparison between Unknown and I4
		//IL_0051: Unknown result type (might be due to invalid IL or missing references)
		//IL_0053: Invalid comparison between Unknown and I4
		//IL_005d: Unknown result type (might be due to invalid IL or missing references)
		//IL_005f: Invalid comparison between Unknown and I4
		string result = "saved";
		DialogResult val = (DialogResult)6;
		if (model.HexData != null)
		{
			model.HexData.AcceptChanges();
			if (Model.IsDirty)
			{
				val = MessageBox.Show("Warning! There are modified parameters. Closing the editor will result in the modified data being discarded. Do you wish to save the modified data?", "Hex Editor", (MessageBoxButtons)3, (MessageBoxIcon)32);
				if ((int)val == 6)
				{
					result = "yes";
				}
				else if ((int)val == 7)
				{
					result = "no";
				}
				else if ((int)val == 2)
				{
					result = "cancel";
				}
			}
		}
		return result;
	}

	public void SetCurrentPosition(int row, int column)
	{
		Model.Index = new Pointer(row, column - 1);
	}

	public void PerformSaveOperation()
	{
		try
		{
			Model.SaveHexData();
			EventLogger.Info("CalibrationHexEdit", "Hex data Saved succcessfully to the calibration file.");
		}
		catch (Exception ex)
		{
			EventLogger.Error("CalibrationHexEdit", "Failed to save the Hex data to the calibration file. " + ex.GetBaseException().Message);
		}
	}

	public void SelectAddressRange(int startAddress, int endAddress)
	{
	}
}
public delegate void StateChangedEventHandler(object sender, StateChangedEventArgs e);
public enum ChangeType
{
	Changed,
	Reverted,
	RevertedAll,
	SavedAll,
	IndexChanged
}
public class StateChangedEventArgs
{
	public ChangeType ChangeType;

	public Pointer Index;

	public StateChangedEventArgs(ChangeType changeType, Pointer Index)
	{
		ChangeType = changeType;
		this.Index = Index;
	}
}
public class HexEditorModel
{
	internal static string hexDataTable = "hexDataTable";

	internal static SpecialParameters BDSNumberOfBlocksParameter = SpecialParameters.ConfigFile_Block_Data_StructureNumBlocks;

	internal static SpecialParameters BDSStartAddressOfBlocksParameter = SpecialParameters.ConfigFile_Block_Data_StructureAddressArray;

	internal static SpecialParameters BDSContentLengthOfBlocksParameter = SpecialParameters.ConfigFile_Block_Data_StructureContentLengthArray;

	internal static string AddressString = "Address";

	internal static int NumberOfDataColumns = 16;

	private ICalibration calibrationDataSource;

	private DataTable hexEditDataTable;

	private int startAddress;

	private int endAddress;

	private int length;

	private Pointer index;

	private UndoBuffer undoBuffer;

	private BDS bds;

	private bool isDirty;

	public BDS BDS => bds;

	public bool IsDirty => isDirty;

	public Pointer Index
	{
		get
		{
			return index;
		}
		set
		{
			if (value.Row != index.Row || value.Column != index.Column)
			{
				index = new Pointer(value.Row, value.Column);
				RaiseStateChangedEvent(ChangeType.IndexChanged, index);
			}
		}
	}

	public int StartAddress
	{
		get
		{
			return startAddress;
		}
		set
		{
			startAddress = value;
		}
	}

	public int EndAddress
	{
		get
		{
			return endAddress;
		}
		set
		{
			endAddress = value;
		}
	}

	public EventHandler BDSRetrievedEvent
	{
		get
		{
			return this.bdsRetrievedEvent;
		}
		set
		{
			this.bdsRetrievedEvent = value;
		}
	}

	public DataTable HexData => hexEditDataTable;

	private event EventHandler bdsRetrievedEvent;

	public event StateChangedEventHandler StateChangedEvent;

	public void LoadCalibration(ICalibration calibration)
	{
		ICalibrationECM calibrationECM = ((!(calibration is ICalibrationECM)) ? null : ((ICalibrationECM)calibration));
		if (calibrationECM != null && calibrationECM.ECMRunLocation == RunLocationType.RomBoot)
		{
			calibrationDataSource = calibration;
			return;
		}
		IParameterModel byFullName = calibration.GetByFullName(BDSNumberOfBlocksParameter);
		IValueModel valueModel = (IValueModel)byFullName;
		int numberOfBlocks = (int)valueModel.ScaledFloat();
		byFullName = calibration.Get(BDSStartAddressOfBlocksParameter);
		IArray1DModel blocksStartAddresses = (IArray1DModel)byFullName;
		byFullName = calibration.Get(BDSContentLengthOfBlocksParameter);
		IArray1DModel blocksLength = (IArray1DModel)byFullName;
		calibrationDataSource = calibration;
		bds = new BDS(numberOfBlocks, blocksStartAddresses, blocksLength);
		RaiseBlockDataStructureRetrievedEvent();
	}

	public void RetrieveHexData(int startAddress, int length)
	{
		try
		{
			ICICalDataServer dataServer = calibrationDataSource.CalibrationDataServer.DataServer;
			byte[] array = new byte[length];
			dataServer.ReadData(tagCIAddressingMode.address, startAddress, 0, length, 0, 3, out var Data);
			InitializeDataTable();
			array = (byte[])Data;
			int num = 0;
			num = ((length % NumberOfDataColumns != 0) ? (length / NumberOfDataColumns + 1) : (length / NumberOfDataColumns));
			int num2 = 0;
			int num3 = 0;
			int num4 = startAddress;
			for (int i = 0; i < num; i++)
			{
				DataRow dataRow = hexEditDataTable.NewRow();
				for (num2 = 1; num2 <= NumberOfDataColumns; num2++)
				{
					dataRow[num2.ToString()] = array[num3].ToString("X2");
					num3++;
					if (num3 >= length)
					{
						break;
					}
				}
				dataRow[0] = num4.ToString("X8");
				num4 += NumberOfDataColumns;
				hexEditDataTable.Rows.Add(dataRow);
			}
			hexEditDataTable.AcceptChanges();
			hexEditDataTable.ColumnChanging += OnColumnChanging;
			this.startAddress = startAddress;
			this.length = length;
		}
		catch (Exception)
		{
			throw;
		}
	}

	internal bool SaveHexData()
	{
		bool result = true;
		try
		{
			WriteHexData();
			bool flag = calibrationDataSource.Save();
			if (HexData != null)
			{
				if (flag)
				{
					HexData.AcceptChanges();
					isDirty = false;
					RaiseStateChangedEvent(ChangeType.SavedAll, Index);
				}
				else
				{
					HexData.RejectChanges();
				}
			}
		}
		catch (Exception)
		{
			result = false;
		}
		return result;
	}

	internal bool SaveHexDataAs(string newFilename)
	{
		bool result = true;
		try
		{
			WriteHexData();
			bool flag = calibrationDataSource.SaveAs(newFilename);
			if (HexData != null)
			{
				if (flag)
				{
					HexData.AcceptChanges();
					isDirty = false;
					RaiseStateChangedEvent(ChangeType.SavedAll, Index);
				}
				else
				{
					HexData.RejectChanges();
				}
			}
		}
		catch (Exception)
		{
			result = false;
		}
		return result;
	}

	public void Undo()
	{
		if (hexEditDataTable != null)
		{
			Index = undoBuffer.Index;
			hexEditDataTable.Rows[undoBuffer.Index.Row][undoBuffer.Index.Column] = undoBuffer.OldValue;
			RaiseStateChangedEvent(ChangeType.Reverted, undoBuffer.Index);
		}
	}

	public void RevertAll()
	{
		if (hexEditDataTable != null)
		{
			hexEditDataTable.RejectChanges();
			isDirty = false;
			RaiseStateChangedEvent(ChangeType.RevertedAll, default(Pointer));
		}
	}

	public void RaiseStateChangedEvent(ChangeType changeType, Pointer Index)
	{
		if (this.StateChangedEvent != null)
		{
			this.StateChangedEvent(this, new StateChangedEventArgs(changeType, Index));
		}
	}

	protected void RaiseBlockDataStructureRetrievedEvent()
	{
		if (BDSRetrievedEvent != null)
		{
			BDSRetrievedEvent(this, EventArgs.Empty);
		}
	}

	private void OnColumnChanging(object sender, DataColumnChangeEventArgs e)
	{
		if (!e.Column.ColumnName.Equals(AddressString))
		{
			if (e.ProposedValue.Equals(""))
			{
				e.ProposedValue = "00";
			}
			try
			{
				Index = new Pointer(Index.Row, e.Column.Ordinal);
				int num = int.Parse(e.ProposedValue.ToString(), NumberStyles.HexNumber);
				undoBuffer.Index = Index;
				undoBuffer.OldValue = hexEditDataTable.Rows[Index.Row][Index.Column].ToString();
				if (num.ToString("X2") != undoBuffer.OldValue)
				{
					e.ProposedValue = num.ToString("X2");
					isDirty = true;
					RaiseStateChangedEvent(ChangeType.Changed, Index);
				}
				return;
			}
			catch (FormatException)
			{
				EventLogger.Error("CalibrationHexEdit", "Invalid Hex value: " + e.ProposedValue);
				e.ProposedValue = e.Row[e.Column.Ordinal].ToString();
				return;
			}
		}
		throw new Exception("Address is Readonly");
	}

	private void InitializeDataTable()
	{
		hexEditDataTable = new DataTable(hexDataTable);
		hexEditDataTable.Columns.Add(AddressString);
		for (int i = 1; i <= NumberOfDataColumns; i++)
		{
			hexEditDataTable.Columns.Add(i.ToString(), typeof(string));
		}
		isDirty = false;
	}

	private void WriteHexData()
	{
		if (hexEditDataTable == null)
		{
			return;
		}
		try
		{
			byte[] array = new byte[length];
			DataRowCollection rows = hexEditDataTable.Rows;
			int num = 1;
			int num2 = 0;
			int num3 = 0;
			for (int i = 0; i < rows.Count; i++)
			{
				for (num = 1; num <= 16; num++)
				{
					if (DBNull.Value != hexEditDataTable.Rows[i][num] && num3 < length)
					{
						string value = hexEditDataTable.Rows[i][num].ToString();
						array[num2++] = Convert.ToByte(value, 16);
						num3++;
					}
				}
			}
			ICICalDataServer dataServer = calibrationDataSource.CalibrationDataServer.DataServer;
			dataServer.WriteData(tagCIAddressingMode.address, startAddress, 0, 0, 0, array, tagCIWriteMethod.WRITE_AUTOMATIC);
		}
		catch (Exception)
		{
		}
	}
}
public struct BDS
{
	private int[] hexDataStartAddresses;

	private int[] hexDataLengths;

	private int numberOfBlocks;

	public int NumberofBlocks => numberOfBlocks;

	public int[] StartAddresses => hexDataStartAddresses;

	public int[] BlockLengths => hexDataLengths;

	public BDS(int numberOfBlocks, IArray1DModel blocksStartAddresses, IArray1DModel blocksLength)
	{
		this.numberOfBlocks = numberOfBlocks;
		hexDataStartAddresses = new int[numberOfBlocks];
		hexDataLengths = new int[numberOfBlocks];
		for (int i = 0; i < numberOfBlocks; i++)
		{
			hexDataStartAddresses[i] = (int)blocksStartAddresses.ScaledFloat(i);
			hexDataLengths[i] = (int)blocksLength.ScaledFloat(i);
		}
	}
}
public struct UndoBuffer
{
	public string OldValue;

	public Pointer Index;
}
public struct Pointer
{
	public int Row;

	public int Column;

	public Pointer(int Row, int Column)
	{
		this.Row = Row;
		this.Column = Column;
	}
}
public class HexEditorView : UserControl
{
	private const string ResourceFileName = "Cummins.CalibrationEdit.CalibrationEditorStrings";

	protected ResourceManager resourceManager;

	private HexEditorModel model;

	private HexEditorController controller;

	private IContainer components;

	private Button btnHexEditRetrieve;

	private TextBox txtHexEditEndAddress;

	private Label lblEndAddress;

	private TextBox txtHexEditLength;

	private Label lblLength;

	private TextBox txtHexEditStartAddress;

	private Label lblStartAddress;

	private ListBox lstHexEditAddressRange;

	private Label lblAddressRange;

	private Panel paAddressSelection;

	private Panel paHexEditGrid;

	protected Panel paView;

	private CustomDataGrid hexEditDataGrid;

	private ContextMenu contextMenuCustomDataGrid;

	private MenuItem menuItemCopy;

	private MenuItem menuItemPaste;

	private Button btnSave;

	public HexEditorModel Model => model;

	public HexEditorController Controller => controller;

	public ResourceManager ResourceManager => resourceManager;

	public event KeyEventHandler GridKeyDown
	{
		add
		{
			hexEditDataGrid.GridKeyDown += value;
		}
		remove
		{
			hexEditDataGrid.GridKeyDown -= value;
		}
	}

	public HexEditorView()
	{
		resourceManager = new ResourceManager("Cummins.CalibrationEdit.CalibrationEditorStrings", Assembly.GetExecutingAssembly());
	}

	public HexEditorView(HexEditorModel model, HexEditorController controller)
	{
		//IL_0106: Unknown result type (might be due to invalid IL or missing references)
		//IL_0110: Expected O, but got Unknown
		try
		{
			InitializeComponent();
			InitializeView();
			this.controller = controller;
			this.model = model;
			HexEditorModel hexEditorModel = this.model;
			hexEditorModel.BDSRetrievedEvent = (EventHandler)Delegate.Combine(hexEditorModel.BDSRetrievedEvent, new EventHandler(OnBDSRetrieved));
			this.model.StateChangedEvent += OnStateChange;
			lstHexEditAddressRange.SelectedIndexChanged += OnAddressRangeSelectedIndexChanged;
			((Control)txtHexEditEndAddress).Validating += OnEndAddressValidating;
			((Control)txtHexEditStartAddress).Validating += OnStartAddressValidating;
			((Control)txtHexEditLength).Validating += OnLengthValidating;
			((DataGrid)hexEditDataGrid).CurrentCellChanged += OnCurrentCellChanged;
			((Control)hexEditDataGrid).ContextMenu = contextMenuCustomDataGrid;
			((Control)lstHexEditAddressRange).DoubleClick += OnAddressRangeDoubleClick;
			((Control)lstHexEditAddressRange).KeyPress += new KeyPressEventHandler(OnAddressRangeKeyPress);
		}
		catch (Exception innerException)
		{
			throw new Exception("Error initializing Calibration Hex Edit View!", innerException);
		}
	}

	public void Undo()
	{
		Controller.Undo();
	}

	public void RevertAll()
	{
		Controller.RevertAll();
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
		//IL_009b: Unknown result type (might be due to invalid IL or missing references)
		//IL_00a5: Expected O, but got Unknown
		//IL_00a6: Unknown result type (might be due to invalid IL or missing references)
		//IL_00b0: Expected O, but got Unknown
		//IL_00b1: Unknown result type (might be due to invalid IL or missing references)
		//IL_00bb: Expected O, but got Unknown
		//IL_011c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0126: Expected O, but got Unknown
		//IL_0212: Unknown result type (might be due to invalid IL or missing references)
		//IL_021c: Expected O, but got Unknown
		//IL_0306: Unknown result type (might be due to invalid IL or missing references)
		//IL_0310: Expected O, but got Unknown
		//IL_040a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0414: Expected O, but got Unknown
		//IL_049b: Unknown result type (might be due to invalid IL or missing references)
		//IL_04a5: Expected O, but got Unknown
		//IL_050b: Unknown result type (might be due to invalid IL or missing references)
		//IL_0515: Expected O, but got Unknown
		//IL_06e8: Unknown result type (might be due to invalid IL or missing references)
		//IL_06f2: Expected O, but got Unknown
		btnHexEditRetrieve = new Button();
		txtHexEditEndAddress = new TextBox();
		lblEndAddress = new Label();
		txtHexEditLength = new TextBox();
		lblLength = new Label();
		txtHexEditStartAddress = new TextBox();
		lblStartAddress = new Label();
		lstHexEditAddressRange = new ListBox();
		lblAddressRange = new Label();
		paAddressSelection = new Panel();
		btnSave = new Button();
		paHexEditGrid = new Panel();
		paView = new Panel();
		hexEditDataGrid = new CustomDataGrid();
		contextMenuCustomDataGrid = new ContextMenu();
		menuItemCopy = new MenuItem();
		menuItemPaste = new MenuItem();
		((Control)paAddressSelection).SuspendLayout();
		((Control)paHexEditGrid).SuspendLayout();
		((Control)paView).SuspendLayout();
		((ISupportInitialize)hexEditDataGrid).BeginInit();
		((Control)this).SuspendLayout();
		((Control)btnHexEditRetrieve).BackColor = SystemColors.Control;
		((Control)btnHexEditRetrieve).Enabled = false;
		((Control)btnHexEditRetrieve).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)btnHexEditRetrieve).Location = new Point(8, 280);
		((Control)btnHexEditRetrieve).Name = "btnHexEditRetrieve";
		((Control)btnHexEditRetrieve).TabIndex = 8;
		((Control)btnHexEditRetrieve).Text = "&Retrieve";
		((Control)btnHexEditRetrieve).Click += hexEditRetrieve_Click;
		((Control)txtHexEditEndAddress).Anchor = (AnchorStyles)13;
		((Control)txtHexEditEndAddress).BackColor = SystemColors.Window;
		((Control)txtHexEditEndAddress).Location = new Point(112, 232);
		((TextBoxBase)txtHexEditEndAddress).MaxLength = 8;
		((Control)txtHexEditEndAddress).Name = "txtHexEditEndAddress";
		((Control)txtHexEditEndAddress).Size = new Size(96, 20);
		((Control)txtHexEditEndAddress).TabIndex = 7;
		((Control)txtHexEditEndAddress).Text = "";
		((Control)lblEndAddress).Font = new Font("Tahoma", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)lblEndAddress).Location = new Point(16, 232);
		((Control)lblEndAddress).Name = "lblEndAddress";
		((Control)lblEndAddress).Size = new Size(80, 32);
		((Control)lblEndAddress).TabIndex = 6;
		((Control)lblEndAddress).Text = "En&d Address";
		((Control)txtHexEditLength).Anchor = (AnchorStyles)13;
		((Control)txtHexEditLength).BackColor = SystemColors.Window;
		((Control)txtHexEditLength).Location = new Point(112, 200);
		((TextBoxBase)txtHexEditLength).MaxLength = 8;
		((Control)txtHexEditLength).Name = "txtHexEditLength";
		((Control)txtHexEditLength).Size = new Size(96, 20);
		((Control)txtHexEditLength).TabIndex = 5;
		((Control)txtHexEditLength).Text = "";
		((Control)lblLength).Font = new Font("Tahoma", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)lblLength).Location = new Point(16, 200);
		((Control)lblLength).Name = "lblLength";
		((Control)lblLength).Size = new Size(56, 24);
		((Control)lblLength).TabIndex = 4;
		((Control)lblLength).Text = "Le&ngth";
		((Control)txtHexEditStartAddress).Anchor = (AnchorStyles)13;
		((Control)txtHexEditStartAddress).BackColor = SystemColors.Window;
		((Control)txtHexEditStartAddress).Location = new Point(112, 168);
		((TextBoxBase)txtHexEditStartAddress).MaxLength = 8;
		((Control)txtHexEditStartAddress).Name = "txtHexEditStartAddress";
		((Control)txtHexEditStartAddress).Size = new Size(96, 20);
		((Control)txtHexEditStartAddress).TabIndex = 3;
		((Control)txtHexEditStartAddress).Text = "";
		((Control)lblStartAddress).BackColor = SystemColors.Control;
		((Control)lblStartAddress).Font = new Font("Tahoma", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)lblStartAddress).Location = new Point(16, 168);
		((Control)lblStartAddress).Name = "lblStartAddress";
		((Control)lblStartAddress).Size = new Size(88, 16);
		((Control)lblStartAddress).TabIndex = 2;
		((Control)lblStartAddress).Text = "St&art Address";
		((Control)lstHexEditAddressRange).Anchor = (AnchorStyles)13;
		((Control)lstHexEditAddressRange).BackColor = SystemColors.Window;
		((Control)lstHexEditAddressRange).Font = new Font("Tahoma", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
		((Control)lstHexEditAddressRange).Location = new Point(16, 56);
		((Control)lstHexEditAddressRange).Name = "lstHexEditAddressRange";
		lstHexEditAddressRange.ScrollAlwaysVisible = true;
		((Control)lstHexEditAddressRange).Size = new Size(192, 82);
		((Control)lstHexEditAddressRange).TabIndex = 1;
		((Control)lblAddressRange).Font = new Font("Tahoma", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)lblAddressRange).Location = new Point(16, 24);
		((Control)lblAddressRange).Name = "lblAddressRange";
		((Control)lblAddressRange).Size = new Size(168, 23);
		((Control)lblAddressRange).TabIndex = 0;
		((Control)lblAddressRange).Text = "Select a val&id address range:";
		((ScrollableControl)paAddressSelection).AutoScroll = true;
		((Control)paAddressSelection).BackColor = SystemColors.Control;
		((Control)paAddressSelection).Controls.Add((Control)(object)btnSave);
		((Control)paAddressSelection).Controls.Add((Control)(object)btnHexEditRetrieve);
		((Control)paAddressSelection).Controls.Add((Control)(object)txtHexEditEndAddress);
		((Control)paAddressSelection).Controls.Add((Control)(object)lblEndAddress);
		((Control)paAddressSelection).Controls.Add((Control)(object)txtHexEditLength);
		((Control)paAddressSelection).Controls.Add((Control)(object)lblLength);
		((Control)paAddressSelection).Controls.Add((Control)(object)txtHexEditStartAddress);
		((Control)paAddressSelection).Controls.Add((Control)(object)lblStartAddress);
		((Control)paAddressSelection).Controls.Add((Control)(object)lstHexEditAddressRange);
		((Control)paAddressSelection).Controls.Add((Control)(object)lblAddressRange);
		((Control)paAddressSelection).Dock = (DockStyle)3;
		((Control)paAddressSelection).Location = new Point(0, 0);
		((Control)paAddressSelection).Name = "paAddressSelection";
		((Control)paAddressSelection).Size = new Size(224, 592);
		((Control)paAddressSelection).TabIndex = 10;
		((Control)btnSave).BackColor = SystemColors.Control;
		((Control)btnSave).Enabled = false;
		((Control)btnSave).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)btnSave).Location = new Point(136, 280);
		((Control)btnSave).Name = "btnSave";
		((Control)btnSave).TabIndex = 9;
		((Control)btnSave).Text = "&Save";
		((Control)btnSave).Click += btnSave_Click;
		((Control)paHexEditGrid).BackColor = SystemColors.Control;
		((Control)paHexEditGrid).Controls.Add((Control)(object)paView);
		((Control)paHexEditGrid).Dock = (DockStyle)5;
		((Control)paHexEditGrid).Location = new Point(224, 0);
		((Control)paHexEditGrid).Name = "paHexEditGrid";
		((Control)paHexEditGrid).Size = new Size(688, 592);
		((Control)paHexEditGrid).TabIndex = 11;
		((Control)paView).BackColor = SystemColors.Control;
		((Control)paView).Controls.Add((Control)(object)hexEditDataGrid);
		((Control)paView).Dock = (DockStyle)5;
		((Control)paView).Location = new Point(0, 0);
		((Control)paView).Name = "paView";
		((Control)paView).Size = new Size(688, 592);
		((Control)paView).TabIndex = 6;
		hexEditDataGrid.AddRowWhilePaste = false;
		((DataGrid)hexEditDataGrid).AllowSorting = false;
		((Control)hexEditDataGrid).BackColor = SystemColors.Control;
		((DataGrid)hexEditDataGrid).BackgroundColor = SystemColors.Control;
		((DataGrid)hexEditDataGrid).DataMember = "";
		((Control)hexEditDataGrid).Dock = (DockStyle)5;
		((DataGrid)hexEditDataGrid).HeaderForeColor = SystemColors.ControlText;
		((Control)hexEditDataGrid).Location = new Point(0, 0);
		((Control)hexEditDataGrid).Name = "hexEditDataGrid";
		((Control)hexEditDataGrid).Size = new Size(688, 592);
		((Control)hexEditDataGrid).TabIndex = 0;
		((Menu)contextMenuCustomDataGrid).MenuItems.AddRange((MenuItem[])(object)new MenuItem[2] { menuItemCopy, menuItemPaste });
		menuItemCopy.Index = 0;
		menuItemCopy.Text = "Copy";
		menuItemCopy.Click += menuItemCopy_Click;
		menuItemPaste.Index = 1;
		menuItemPaste.Text = "Paste";
		menuItemPaste.Click += menuItemPaste_Click;
		((Control)this).Controls.Add((Control)(object)paHexEditGrid);
		((Control)this).Controls.Add((Control)(object)paAddressSelection);
		((Control)this).Name = "HexEditorView";
		((Control)this).Size = new Size(912, 592);
		((Control)paAddressSelection).ResumeLayout(false);
		((Control)paHexEditGrid).ResumeLayout(false);
		((Control)paView).ResumeLayout(false);
		((ISupportInitialize)hexEditDataGrid).EndInit();
		((Control)this).ResumeLayout(false);
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		((ContainerControl)this).Dispose(disposing);
	}

	private void InitializeHexEditDataGrid()
	{
		//IL_0037: Unknown result type (might be due to invalid IL or missing references)
		//IL_003d: Expected O, but got Unknown
		//IL_003d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0043: Expected O, but got Unknown
		//IL_004e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0054: Expected O, but got Unknown
		try
		{
			((DataGrid)hexEditDataGrid).DataSource = Model.HexData;
			CurrencyManager val = (CurrencyManager)((Control)this).BindingContext[((DataGrid)hexEditDataGrid).DataSource, ((DataGrid)hexEditDataGrid).DataMember];
			DataGridTableStyle val2 = new DataGridTableStyle();
			val2.MappingName = HexEditorModel.hexDataTable;
			DataGridTextBoxColumn val3 = new DataGridTextBoxColumn();
			((DataGridColumnStyle)val3).MappingName = HexEditorModel.AddressString;
			((DataGridColumnStyle)val3).HeaderText = HexEditorModel.AddressString;
			((DataGridColumnStyle)val3).Width = 100;
			((DataGridColumnStyle)val3).ReadOnly = true;
			val2.GridColumnStyles.Add((DataGridColumnStyle)(object)val3);
			PropertyDescriptor pd = ((BindingManagerBase)val).GetItemProperties()["Value"];
			for (int i = 0; i < HexEditorModel.NumberOfDataColumns; i++)
			{
				val3 = (DataGridTextBoxColumn)(object)new ColoredTextBoxColumn((DataGrid)(object)hexEditDataGrid, pd);
				((DataGridColumnStyle)val3).MappingName = (i + 1).ToString();
				((DataGridColumnStyle)val3).HeaderText = i.ToString("X1");
				((DataGridColumnStyle)val3).Width = 30;
				((TextBoxBase)val3.TextBox).MaxLength = 2;
				val2.GridColumnStyles.Add((DataGridColumnStyle)(object)val3);
			}
			((DataGrid)hexEditDataGrid).TableStyles.Clear();
			((DataGrid)hexEditDataGrid).TableStyles.Add(val2);
			((DataView)val.List).AllowNew = false;
			((DataView)val.List).AllowDelete = false;
		}
		catch (Exception)
		{
			throw;
		}
	}

	private void InitializeView()
	{
		//IL_0006: Unknown result type (might be due to invalid IL or missing references)
		//IL_000c: Expected O, but got Unknown
		((Control)this).SuspendLayout();
		Splitter val = new Splitter();
		((Control)val).Dock = (DockStyle)3;
		((Control)val).Width = 3;
		((Control)val).BackColor = Color.Black;
		val.BorderStyle = (BorderStyle)1;
		((Control)this).Controls.Remove((Control)(object)paHexEditGrid);
		((Control)this).Controls.Remove((Control)(object)paAddressSelection);
		((Control)this).Controls.AddRange((Control[])(object)new Control[3]
		{
			(Control)paHexEditGrid,
			(Control)val,
			(Control)paAddressSelection
		});
		((Control)this).ResumeLayout(false);
	}

	private void OnAddressRangeSelectedIndexChanged(object sender, EventArgs e)
	{
		string text = lstHexEditAddressRange.SelectedItem.ToString();
		if (text.ToLower() == "custom")
		{
			((Control)txtHexEditStartAddress).Enabled = true;
			((Control)txtHexEditLength).Enabled = true;
			((Control)txtHexEditEndAddress).Enabled = true;
			((Control)txtHexEditStartAddress).Focus();
			if (((Control)txtHexEditStartAddress).Text.Trim().Length == 0 || ((Control)txtHexEditLength).Text.Trim().Length == 0)
			{
				((Control)btnHexEditRetrieve).Enabled = false;
			}
			else
			{
				((Control)btnHexEditRetrieve).Enabled = true;
			}
			return;
		}
		((Control)txtHexEditStartAddress).Enabled = false;
		((Control)txtHexEditLength).Enabled = false;
		((Control)txtHexEditEndAddress).Enabled = false;
		text = text.Trim();
		string[] array = text.Split(new char[1] { '-' }, 2);
		string text2 = array[0].Trim();
		string text3 = array[1].Trim();
		((Control)txtHexEditStartAddress).Text = text2;
		((Control)txtHexEditEndAddress).Text = text3;
		int num = int.Parse(text2, NumberStyles.HexNumber);
		int num2 = int.Parse(text3, NumberStyles.HexNumber);
		((Control)txtHexEditLength).Text = Convert.ToString(num2 - num + 1, 16);
		controller.SelectAddressRange(num, num2);
		((Control)btnHexEditRetrieve).Enabled = true;
	}

	private void hexEditRetrieve_Click(object sender, EventArgs e)
	{
		//IL_00f9: Unknown result type (might be due to invalid IL or missing references)
		//IL_0127: Unknown result type (might be due to invalid IL or missing references)
		//IL_0051: Unknown result type (might be due to invalid IL or missing references)
		if (((Control)txtHexEditLength).Text.Trim().Length == 0 || ((Control)txtHexEditStartAddress).Text.Trim().Length == 0)
		{
			MessageBox.Show(resourceManager.GetString("InvalidHexAddressRange"), resourceManager.GetString("MessageBoxCaption"), (MessageBoxButtons)0, (MessageBoxIcon)16);
			((Control)txtHexEditStartAddress).Focus();
		}
		else if (controller.Shutdown(requestSavePrompt: true))
		{
			int startAddress = Convert.ToInt32(((Control)txtHexEditStartAddress).Text.Trim(), 16);
			int length = Convert.ToInt32(((Control)txtHexEditLength).Text.Trim(), 16);
			try
			{
				controller.SelectHexRange(startAddress, length);
				InitializeHexEditDataGrid();
				((Control)btnSave).Enabled = true;
			}
			catch (COMException ex)
			{
				ICIErrorMessageSet iCIErrorMessageSet = new ErrorMessageSetClass();
				iCIErrorMessageSet.loadXML(ex.Message);
				iCIErrorMessageSet.MoveFirst();
				string description = iCIErrorMessageSet.description;
				MessageBox.Show(description, ResourceManager.GetString("MessageBoxCaption"));
				EventLogger.Error("HexEditor", description, ex);
			}
			catch (Exception ex2)
			{
				MessageBox.Show(ex2.Message, ResourceManager.GetString("MessageBoxCaption"));
				EventLogger.Error("HexEditor", "Exception in HexEditor", ex2);
			}
		}
	}

	private void OnBDSRetrieved(object sender, EventArgs e)
	{
		lstHexEditAddressRange.Items.Clear();
		int num = 0;
		string text = "";
		string text2 = "";
		string text3 = "";
		for (num = 0; num < Model.BDS.NumberofBlocks; num++)
		{
			int num2 = Model.BDS.BlockLengths[num];
			int num3 = Model.BDS.StartAddresses[num];
			while (num2 > 0)
			{
				text = num3.ToString("X8");
				num3 = ((num2 <= 32767) ? (num3 + (num2 - 1)) : (num3 + 32766));
				text2 = num3.ToString("X8");
				text3 = text + "-" + text2;
				lstHexEditAddressRange.Items.Add((object)text3);
				num3++;
				num2 -= 32767;
			}
		}
		lstHexEditAddressRange.Items.Add((object)"Custom");
		num = lstHexEditAddressRange.Items.IndexOf((object)"Custom");
		((ListControl)lstHexEditAddressRange).SelectedIndex = num;
	}

	private void OnStartAddressValidating(object sender, CancelEventArgs e)
	{
		if (((Control)txtHexEditStartAddress).Text.Trim().Length != 0)
		{
			e.Cancel = false;
			long num = 0L;
			try
			{
				num = long.Parse(((Control)txtHexEditStartAddress).Text, NumberStyles.HexNumber);
			}
			catch (FormatException)
			{
				((Control)txtHexEditStartAddress).Text = "0";
			}
			long num2 = 0L;
			if (((Control)txtHexEditEndAddress).Text.Trim().Length != 0)
			{
				num2 = long.Parse(((Control)txtHexEditEndAddress).Text, NumberStyles.HexNumber);
			}
			long num3 = 0L;
			if (((Control)txtHexEditLength).Text.Trim().Length != 0)
			{
				num3 = long.Parse(((Control)txtHexEditLength).Text, NumberStyles.HexNumber);
			}
			if (num > num2)
			{
				if (0 == num3)
				{
					num2 = num + 1;
					num3 = 2L;
				}
				else
				{
					num2 = num + num3 - 1;
				}
			}
			else
			{
				num3 = num2 - num + 1;
			}
			((Control)txtHexEditEndAddress).Text = Convert.ToString(num2, 16);
			((Control)txtHexEditLength).Text = Convert.ToString(num3, 16);
			ShouldEnableRetrieve();
		}
		else
		{
			((Control)btnHexEditRetrieve).Enabled = false;
		}
	}

	private void OnLengthValidating(object sender, CancelEventArgs e)
	{
		if (((Control)txtHexEditLength).Text.Trim().Length != 0)
		{
			e.Cancel = false;
			long num = 2L;
			try
			{
				num = long.Parse(((Control)txtHexEditLength).Text, NumberStyles.HexNumber);
			}
			catch (FormatException)
			{
				((Control)txtHexEditLength).Text = "2";
			}
			long num2 = 0L;
			if (((Control)txtHexEditStartAddress).Text.Trim().Length != 0)
			{
				num2 = long.Parse(((Control)txtHexEditStartAddress).Text, NumberStyles.HexNumber);
			}
			long num3 = num2 + num - 1;
			((Control)txtHexEditEndAddress).Text = Convert.ToString(num3, 16);
			ShouldEnableRetrieve();
		}
		else
		{
			ShouldEnableRetrieve();
		}
	}

	private void OnEndAddressValidating(object sender, CancelEventArgs e)
	{
		if (((Control)txtHexEditEndAddress).Text.Trim().Length != 0)
		{
			e.Cancel = false;
			long num = 0L;
			try
			{
				num = long.Parse(((Control)txtHexEditEndAddress).Text, NumberStyles.HexNumber);
			}
			catch (FormatException)
			{
				((Control)txtHexEditEndAddress).Text = "0";
			}
			long num2 = 0L;
			if (((Control)txtHexEditStartAddress).Text.Trim().Length != 0)
			{
				num2 = long.Parse(((Control)txtHexEditStartAddress).Text, NumberStyles.HexNumber);
			}
			long num3 = 0L;
			if (num2 > num)
			{
				num2 = 0L;
			}
			num3 = num - num2 + 1;
			((Control)txtHexEditStartAddress).Text = Convert.ToString(num2, 16);
			((Control)txtHexEditLength).Text = Convert.ToString(num3, 16);
			ShouldEnableRetrieve();
		}
		else
		{
			ShouldEnableRetrieve();
		}
	}

	private void ShouldEnableRetrieve()
	{
		if ((((Control)txtHexEditLength).Text.Trim().Length == 0 && ((Control)txtHexEditStartAddress).Text.Trim().Length == 0) || (((Control)txtHexEditEndAddress).Text.Trim().Length == 0 && ((Control)txtHexEditStartAddress).Text.Trim().Length == 0) || ((Control)txtHexEditStartAddress).Text.Trim().Length == 0)
		{
			if (((Control)btnHexEditRetrieve).Enabled)
			{
				((Control)btnHexEditRetrieve).Enabled = false;
			}
		}
		else if (!((Control)btnHexEditRetrieve).Enabled)
		{
			((Control)btnHexEditRetrieve).Enabled = true;
		}
	}

	private void btnSave_Click(object sender, EventArgs e)
	{
		//IL_0078: Unknown result type (might be due to invalid IL or missing references)
		Cursor current = Cursor.Current;
		Cursor.Current = Cursors.WaitCursor;
		if (((Control)txtHexEditLength).Text.Trim().Length == 0 || ((Control)txtHexEditStartAddress).Text.Trim().Length == 0 || ((Control)txtHexEditEndAddress).Text.Trim().Length == 0)
		{
			MessageBox.Show(resourceManager.GetString("InvalidHexAddressRange"), resourceManager.GetString("MessageBoxCaption"), (MessageBoxButtons)0, (MessageBoxIcon)16);
			((Control)txtHexEditStartAddress).Focus();
		}
		else
		{
			controller.PerformSaveOperation();
			((Control)btnSave).Enabled = false;
		}
		Cursor.Current = current;
	}

	private void OnCurrentCellChanged(object sender, EventArgs e)
	{
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0011: Unknown result type (might be due to invalid IL or missing references)
		//IL_001f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0024: Unknown result type (might be due to invalid IL or missing references)
		HexEditorController hexEditorController = controller;
		DataGridCell currentCell = ((DataGrid)hexEditDataGrid).CurrentCell;
		int rowNumber = ((DataGridCell)(ref currentCell)).RowNumber;
		DataGridCell currentCell2 = ((DataGrid)hexEditDataGrid).CurrentCell;
		hexEditorController.SetCurrentPosition(rowNumber, ((DataGridCell)(ref currentCell2)).ColumnNumber);
	}

	private void OnAddressRangeDoubleClick(object sender, EventArgs e)
	{
		string text = lstHexEditAddressRange.SelectedItem.ToString();
		if (text.ToLower() != "custom")
		{
			((Control)txtHexEditStartAddress).Enabled = false;
			((Control)txtHexEditLength).Enabled = false;
			((Control)txtHexEditEndAddress).Enabled = false;
			text = text.Trim();
			string[] array = text.Split(new char[1] { '-' }, 2);
			string text2 = array[0].Trim();
			string text3 = array[1].Trim();
			((Control)txtHexEditStartAddress).Text = text2;
			((Control)txtHexEditEndAddress).Text = text3;
			long num = long.Parse(text2, NumberStyles.HexNumber);
			long num2 = long.Parse(text3, NumberStyles.HexNumber);
			((Control)txtHexEditLength).Text = Convert.ToString(num2 - num + 1, 16);
		}
		hexEditRetrieve_Click(null, null);
	}

	private void OnAddressRangeKeyPress(object sender, KeyPressEventArgs e)
	{
		if (e.KeyChar == '\r')
		{
			OnAddressRangeSelectedIndexChanged(sender, null);
		}
	}

	private void OnStateChange(object sender, StateChangedEventArgs e)
	{
		//IL_00d0: Unknown result type (might be due to invalid IL or missing references)
		ColoredTextBoxColumn coloredTextBoxColumn = null;
		switch (e.ChangeType)
		{
		case ChangeType.Changed:
			coloredTextBoxColumn = (ColoredTextBoxColumn)(object)((DataGrid)hexEditDataGrid).TableStyles[0].GridColumnStyles[e.Index.Column];
			coloredTextBoxColumn.ShowCellModified(e.Index.Row);
			((Control)btnSave).Enabled = true;
			break;
		case ChangeType.Reverted:
			coloredTextBoxColumn = (ColoredTextBoxColumn)(object)((DataGrid)hexEditDataGrid).TableStyles[0].GridColumnStyles[e.Index.Column + 1];
			coloredTextBoxColumn.ShowCellUnmodified(e.Index.Row);
			break;
		case ChangeType.IndexChanged:
			((DataGrid)hexEditDataGrid).CurrentCell = new DataGridCell(e.Index.Row, e.Index.Column + 1);
			break;
		default:
			UnHighlightAllGridCells();
			break;
		}
	}

	private void UnHighlightAllGridCells()
	{
		GridColumnStylesCollection gridColumnStyles = ((DataGrid)hexEditDataGrid).TableStyles[0].GridColumnStyles;
		for (int i = 1; i < ((BaseCollection)gridColumnStyles).Count - 1; i++)
		{
			ColoredTextBoxColumn coloredTextBoxColumn = (ColoredTextBoxColumn)(object)gridColumnStyles[i];
			coloredTextBoxColumn.ShowAllCellsUnmodified();
		}
	}

	private void menuItemPaste_Click(object sender, EventArgs e)
	{
		hexEditDataGrid.Paste();
	}

	private void menuItemCopy_Click(object sender, EventArgs e)
	{
		hexEditDataGrid.Copy();
	}
}
