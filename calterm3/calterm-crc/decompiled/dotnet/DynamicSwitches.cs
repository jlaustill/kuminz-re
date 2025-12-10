using System;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using System.Windows.Forms;
using System.Xml;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - DynamicSwitches")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTitle("Poodle")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.DynamicSwitches;

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
		//IL_00ba: Unknown result type (might be due to invalid IL or missing references)
		//IL_00c4: Expected O, but got Unknown
		dataGrid1 = new DataGrid();
		((ISupportInitialize)dataGrid1).BeginInit();
		((Control)this).SuspendLayout();
		dataGrid1.DataMember = "";
		((Control)dataGrid1).Dock = (DockStyle)5;
		dataGrid1.HeaderForeColor = SystemColors.ControlText;
		((Control)dataGrid1).Name = "dataGrid1";
		dataGrid1.ReadOnly = true;
		dataGrid1.RowHeadersVisible = false;
		((Control)dataGrid1).Size = new Size(150, 150);
		((Control)dataGrid1).TabIndex = 0;
		((Control)dataGrid1).DoubleClick += dataGrid1_DoubleClick;
		((Control)dataGrid1).MouseUp += new MouseEventHandler(dataGrid1_MouseUp);
		((Control)this).Controls.AddRange((Control[])(object)new Control[1] { (Control)dataGrid1 });
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
		foreach (DataRow row in DT.Rows)
		{
			Graphics val = ((Control)this).CreateGraphics();
			SizeF sizeF = val.MeasureString(row[column].ToString(), ((Control)dataGrid1).Font);
			if (sizeF.Width > (float)num)
			{
				num = (int)sizeF.Width;
			}
		}
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
}
public class DynSwitchesCtrl : UserControl
{
	private const string SwitchesFilename = "Cummins.DynamicSwitches.Switches.xml";

	private DataBoundGrid dtgSwitches;

	private DataSet switchesDataSet;

	private Container components;

	public DynSwitchesCtrl()
	{
		InitializeComponent();
		try
		{
			Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream("Cummins.DynamicSwitches.Switches.xml");
			if (manifestResourceStream.Equals(null))
			{
				throw new ArgumentNullException("Could not open FileStream to Cummins.DynamicSwitches.Switches.xml");
			}
			switchesDataSet = new DataSet("SwitchesData");
			switchesDataSet.ReadXml(manifestResourceStream);
			switchesDataSet.CaseSensitive = false;
			manifestResourceStream.Close();
			manifestResourceStream = null;
			InitializeDataGrid();
		}
		catch (Exception ex)
		{
			throw new Exception("Can not create initialize dynamic switches component: " + ex.Message);
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
		dtgSwitches = new DataBoundGrid();
		((Control)this).SuspendLayout();
		dtgSwitches.AllowFullRowSelection = false;
		((Control)dtgSwitches).Anchor = (AnchorStyles)9;
		dtgSwitches.DtTable = null;
		dtgSwitches.GridTableStyle = null;
		dtgSwitches.InsideCellClick = false;
		((Control)dtgSwitches).Location = new Point(0, 0);
		((Control)dtgSwitches).Name = "dtgSwitches";
		((Control)dtgSwitches).Size = new Size(152, 229);
		((Control)dtgSwitches).TabIndex = 0;
		dtgSwitches.XmlFileName = null;
		dtgSwitches.XmlTableName = "SwitchesData";
		((Control)this).Controls.Add((Control)(object)dtgSwitches);
		((Control)this).Name = "DynSwitchesCtrl";
		((Control)this).Size = new Size(152, 229);
		((Control)this).ResumeLayout(false);
	}

	public void InitializeDataGrid()
	{
		if (switchesDataSet != null)
		{
			dtgSwitches.RefreshData(switchesDataSet);
			dtgSwitches.columnAutoDistribute();
		}
	}

	public void ResetData()
	{
		dtgSwitches.ResetData();
	}
}
