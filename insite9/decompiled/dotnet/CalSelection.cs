using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Data;
using System.Data.Common;
using System.Data.OleDb;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Runtime.Versioning;
using System.Text;
using System.Xml;
using System.Xml.Schema;
using System.Xml.Serialization;
using C1.C1Zip;
using CureCore;

[assembly: ComVisible(false)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Guid("874b8996-66c5-49de-9d02-3bcc0b7e1d0b")]
[assembly: AssemblyFileVersion("2.1.3.12258")]
[assembly: TargetFramework(".NETFramework,Version=v4.0,Profile=Client", FrameworkDisplayName = ".NET Framework 4 Client Profile")]
[assembly: AssemblyTitle("CalSelection")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc")]
[assembly: AssemblyProduct("Cummins Reflash Utillity")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2010-2012")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyVersion("2.1.3.12258")]
namespace CURE;

public class DatabaseInfo
{
	private const int _DB_EXPIRATION_DAY = 180;

	private const string _PRODUCT_LIST_LOCATION = "intelect\\esdn\\data\\";

	private const string _CONN_STRING = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source={0}";

	private const string _CALDATE = "CalDate";

	private const string _JULIAN_DATE = "JulianDate";

	private const string _CAL_DATE_QUERY = "SELECT * FROM CALDATE";

	private const string _CAL_TABLE_QUERY = "SELECT * FROM {0}";

	private string _displayName;

	private DateTime _calDate;

	private List<ProductInfo> _productList;

	private DirectoryInfo _dirInfo;

	public string DisplayName => _dirInfo.Name + " " + _displayName;

	public DateTime CalDate => _calDate;

	public List<ProductInfo> ProductList
	{
		get
		{
			List<ProductInfo> list = new List<ProductInfo>();
			lock (this)
			{
				if (_productList == null)
				{
					CreateProductList();
				}
				list.AddRange(_productList);
				return list;
			}
		}
	}

	public DatabaseInfo(DirectoryInfo dirInfo, string displayName, DateTime calDate)
	{
		_displayName = displayName;
		_calDate = calDate;
		_dirInfo = dirInfo;
		_productList = null;
	}

	public string GetTemporaryCalLocation(string productId, string calName)
	{
		string text = string.Format("{0}{1}{2}\\cal\\{3}", _dirInfo.Name, "intelect\\esdn\\data\\", productId, calName);
		try
		{
			if (File.Exists(text))
			{
				string tempFileName = Path.GetTempFileName();
				C1ZipFile c1ZipFile = new C1ZipFile();
				c1ZipFile.Open(text);
				c1ZipFile.Password = "ndse";
				c1ZipFile.Entries.Extract(0, tempFileName);
				c1ZipFile.Close();
				return tempFileName;
			}
			return null;
		}
		catch
		{
			return null;
		}
	}

	private void CreateProductList()
	{
		//IL_0102: Unknown result type (might be due to invalid IL or missing references)
		//IL_0109: Expected O, but got Unknown
		//IL_0110: Unknown result type (might be due to invalid IL or missing references)
		//IL_0117: Expected O, but got Unknown
		//IL_0119: Unknown result type (might be due to invalid IL or missing references)
		//IL_0120: Expected O, but got Unknown
		//IL_0236: Unknown result type (might be due to invalid IL or missing references)
		//IL_023d: Expected O, but got Unknown
		//IL_023f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0246: Expected O, but got Unknown
		lock (this)
		{
			_productList = new List<ProductInfo>();
			foreach (ProductInformation.ProductRow item in InCalDatabaseLoader.Instance.ProductMetadata.Product)
			{
				string text = string.Format("{0}{1}{2}\\{2}.cmp", _dirInfo.Name, "intelect\\esdn\\data\\", item.Id);
				ProductInfo productInfo = new ProductInfo(item);
				if (!File.Exists(text))
				{
					continue;
				}
				try
				{
					string tempFileName = Path.GetTempFileName();
					C1ZipFile c1ZipFile = new C1ZipFile();
					c1ZipFile.Open(text);
					c1ZipFile.Password = "ocec";
					for (int i = 0; i < c1ZipFile.Entries.Count; i++)
					{
						if (c1ZipFile.Entries[i].FileName.ToUpper() == $"{item.Id}.mdb".ToUpper())
						{
							c1ZipFile.Entries.Extract(i, tempFileName);
							break;
						}
					}
					c1ZipFile.Close();
					try
					{
						OleDbConnection val = new OleDbConnection($"Provider=Microsoft.ACE.OLEDB.12.0;Data Source={tempFileName}");
						try
						{
							OleDbCommand val2 = new OleDbCommand("SELECT * FROM CALDATE", val);
							OleDbDataAdapter val3 = new OleDbDataAdapter(val2);
							((DbConnection)(object)val).Open();
							DataTable dataTable = new DataTable();
							((DbDataAdapter)(object)val3).Fill(dataTable);
							if (dataTable.Rows.Count > 0)
							{
								DateTime dateTime = (DateTime)dataTable.Rows[0]["CalDate"];
								string text2 = (string)dataTable.Rows[0]["JulianDate"];
								string text3 = $"{dateTime.Year - 2000}{dateTime.DayOfYear:000}";
								string text4 = $"{CalDate.Year - 2000}{CalDate.DayOfYear:000}";
								TimeSpan timeSpan = DateTime.Now - CalDate;
								if (text2 == text3 && text4 == text2 && timeSpan.TotalDays < 180.0)
								{
									OleDbCommand val4 = new OleDbCommand($"SELECT * FROM {item.TableName}", val);
									OleDbDataAdapter val5 = new OleDbDataAdapter(val4);
									DataTable dataTable2 = new DataTable();
									((DbDataAdapter)(object)val5).Fill(dataTable2);
									productInfo.CalibrationTable = dataTable2;
									_productList.Add(productInfo);
								}
							}
							((DbConnection)(object)val).Close();
						}
						finally
						{
							((IDisposable)val)?.Dispose();
						}
					}
					catch
					{
					}
					File.Delete(tempFileName);
				}
				catch
				{
				}
			}
		}
	}
}
[Serializable]
[XmlSchemaProvider("GetTypedDataSetSchema")]
[DesignerCategory("code")]
[XmlRoot("ProductInformation")]
[HelpKeyword("vs.data.DataSet")]
[ToolboxItem(true)]
public class ProductInformation : DataSet
{
	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	public delegate void ProductRowChangeEventHandler(object sender, ProductRowChangeEvent e);

	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	public delegate void TableMapRowChangeEventHandler(object sender, TableMapRowChangeEvent e);

	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	public delegate void ColumnMapRowChangeEventHandler(object sender, ColumnMapRowChangeEvent e);

	[Serializable]
	[XmlSchemaProvider("GetTypedTableSchema")]
	public class ProductDataTable : TypedTableBase<ProductRow>
	{
		private DataColumn columnId;

		private DataColumn columnDislayName;

		private DataColumn columnTableName;

		private DataColumn columnAlgorithm;

		private DataColumn columnSelectionQuery;

		private DataColumn columnCalNameColumn;

		private DataColumn columnProduct_Id;

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public DataColumn IdColumn => columnId;

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public DataColumn DislayNameColumn => columnDislayName;

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public DataColumn TableNameColumn => columnTableName;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public DataColumn AlgorithmColumn => columnAlgorithm;

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public DataColumn SelectionQueryColumn => columnSelectionQuery;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public DataColumn CalNameColumnColumn => columnCalNameColumn;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public DataColumn Product_IdColumn => columnProduct_Id;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[Browsable(false)]
		[DebuggerNonUserCode]
		public int Count => base.Rows.Count;

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public ProductRow this[int index] => (ProductRow)base.Rows[index];

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public event ProductRowChangeEventHandler ProductRowChanging;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public event ProductRowChangeEventHandler ProductRowChanged;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public event ProductRowChangeEventHandler ProductRowDeleting;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public event ProductRowChangeEventHandler ProductRowDeleted;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public ProductDataTable()
		{
			base.TableName = "Product";
			BeginInit();
			InitClass();
			EndInit();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		internal ProductDataTable(DataTable table)
		{
			base.TableName = table.TableName;
			if (table.CaseSensitive != table.DataSet.CaseSensitive)
			{
				base.CaseSensitive = table.CaseSensitive;
			}
			if (table.Locale.ToString() != table.DataSet.Locale.ToString())
			{
				base.Locale = table.Locale;
			}
			if (table.Namespace != table.DataSet.Namespace)
			{
				base.Namespace = table.Namespace;
			}
			base.Prefix = table.Prefix;
			base.MinimumCapacity = table.MinimumCapacity;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		protected ProductDataTable(SerializationInfo info, StreamingContext context)
			: base(info, context)
		{
			InitVars();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public void AddProductRow(ProductRow row)
		{
			base.Rows.Add(row);
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public ProductRow AddProductRow(string Id, string DislayName, string TableName, string Algorithm, string SelectionQuery, string CalNameColumn)
		{
			ProductRow productRow = (ProductRow)NewRow();
			object[] itemArray = new object[7] { Id, DislayName, TableName, Algorithm, SelectionQuery, CalNameColumn, null };
			productRow.ItemArray = itemArray;
			base.Rows.Add(productRow);
			return productRow;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public override DataTable Clone()
		{
			ProductDataTable productDataTable = (ProductDataTable)base.Clone();
			productDataTable.InitVars();
			return productDataTable;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected override DataTable CreateInstance()
		{
			return new ProductDataTable();
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		internal void InitVars()
		{
			columnId = base.Columns["Id"];
			columnDislayName = base.Columns["DislayName"];
			columnTableName = base.Columns["TableName"];
			columnAlgorithm = base.Columns["Algorithm"];
			columnSelectionQuery = base.Columns["SelectionQuery"];
			columnCalNameColumn = base.Columns["CalNameColumn"];
			columnProduct_Id = base.Columns["Product_Id"];
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		private void InitClass()
		{
			columnId = new DataColumn("Id", typeof(string), null, MappingType.Element);
			base.Columns.Add(columnId);
			columnDislayName = new DataColumn("DislayName", typeof(string), null, MappingType.Element);
			base.Columns.Add(columnDislayName);
			columnTableName = new DataColumn("TableName", typeof(string), null, MappingType.Element);
			base.Columns.Add(columnTableName);
			columnAlgorithm = new DataColumn("Algorithm", typeof(string), null, MappingType.Element);
			base.Columns.Add(columnAlgorithm);
			columnSelectionQuery = new DataColumn("SelectionQuery", typeof(string), null, MappingType.Element);
			base.Columns.Add(columnSelectionQuery);
			columnCalNameColumn = new DataColumn("CalNameColumn", typeof(string), null, MappingType.Element);
			base.Columns.Add(columnCalNameColumn);
			columnProduct_Id = new DataColumn("Product_Id", typeof(int), null, MappingType.Hidden);
			base.Columns.Add(columnProduct_Id);
			base.Constraints.Add(new UniqueConstraint("Constraint1", new DataColumn[1] { columnProduct_Id }, isPrimaryKey: true));
			columnProduct_Id.AutoIncrement = true;
			columnProduct_Id.AllowDBNull = false;
			columnProduct_Id.Unique = true;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public ProductRow NewProductRow()
		{
			return (ProductRow)NewRow();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
		{
			return new ProductRow(builder);
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected override Type GetRowType()
		{
			return typeof(ProductRow);
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected override void OnRowChanged(DataRowChangeEventArgs e)
		{
			base.OnRowChanged(e);
			if (this.ProductRowChanged != null)
			{
				this.ProductRowChanged(this, new ProductRowChangeEvent((ProductRow)e.Row, e.Action));
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		protected override void OnRowChanging(DataRowChangeEventArgs e)
		{
			base.OnRowChanging(e);
			if (this.ProductRowChanging != null)
			{
				this.ProductRowChanging(this, new ProductRowChangeEvent((ProductRow)e.Row, e.Action));
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected override void OnRowDeleted(DataRowChangeEventArgs e)
		{
			base.OnRowDeleted(e);
			if (this.ProductRowDeleted != null)
			{
				this.ProductRowDeleted(this, new ProductRowChangeEvent((ProductRow)e.Row, e.Action));
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		protected override void OnRowDeleting(DataRowChangeEventArgs e)
		{
			base.OnRowDeleting(e);
			if (this.ProductRowDeleting != null)
			{
				this.ProductRowDeleting(this, new ProductRowChangeEvent((ProductRow)e.Row, e.Action));
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public void RemoveProductRow(ProductRow row)
		{
			base.Rows.Remove(row);
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public static XmlSchemaComplexType GetTypedTableSchema(XmlSchemaSet xs)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Expected O, but got Unknown
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_000c: Expected O, but got Unknown
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Expected O, but got Unknown
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_005a: Expected O, but got Unknown
			//IL_0089: Unknown result type (might be due to invalid IL or missing references)
			//IL_0090: Expected O, but got Unknown
			//IL_00b7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00be: Expected O, but got Unknown
			//IL_013c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0143: Expected O, but got Unknown
			XmlSchemaComplexType val = new XmlSchemaComplexType();
			XmlSchemaSequence val2 = new XmlSchemaSequence();
			ProductInformation productInformation = new ProductInformation();
			XmlSchemaAny val3 = new XmlSchemaAny();
			val3.Namespace = "http://www.w3.org/2001/XMLSchema";
			((XmlSchemaParticle)val3).MinOccurs = 0m;
			((XmlSchemaParticle)val3).MaxOccurs = decimal.MaxValue;
			val3.ProcessContents = (XmlSchemaContentProcessing)2;
			((XmlSchemaGroupBase)val2).Items.Add((XmlSchemaObject)(object)val3);
			XmlSchemaAny val4 = new XmlSchemaAny();
			val4.Namespace = "urn:schemas-microsoft-com:xml-diffgram-v1";
			((XmlSchemaParticle)val4).MinOccurs = 1m;
			val4.ProcessContents = (XmlSchemaContentProcessing)2;
			((XmlSchemaGroupBase)val2).Items.Add((XmlSchemaObject)(object)val4);
			XmlSchemaAttribute val5 = new XmlSchemaAttribute();
			val5.Name = "namespace";
			val5.FixedValue = productInformation.Namespace;
			val.Attributes.Add((XmlSchemaObject)(object)val5);
			XmlSchemaAttribute val6 = new XmlSchemaAttribute();
			val6.Name = "tableTypeName";
			val6.FixedValue = "ProductDataTable";
			val.Attributes.Add((XmlSchemaObject)(object)val6);
			val.Particle = (XmlSchemaParticle)(object)val2;
			XmlSchema schemaSerializable = productInformation.GetSchemaSerializable();
			if (xs.Contains(schemaSerializable.TargetNamespace))
			{
				MemoryStream memoryStream = new MemoryStream();
				MemoryStream memoryStream2 = new MemoryStream();
				try
				{
					XmlSchema val7 = null;
					schemaSerializable.Write((Stream)memoryStream);
					IEnumerator enumerator = xs.Schemas(schemaSerializable.TargetNamespace).GetEnumerator();
					while (enumerator.MoveNext())
					{
						val7 = (XmlSchema)enumerator.Current;
						memoryStream2.SetLength(0L);
						val7.Write((Stream)memoryStream2);
						if (memoryStream.Length == memoryStream2.Length)
						{
							memoryStream.Position = 0L;
							memoryStream2.Position = 0L;
							while (memoryStream.Position != memoryStream.Length && memoryStream.ReadByte() == memoryStream2.ReadByte())
							{
							}
							if (memoryStream.Position == memoryStream.Length)
							{
								return val;
							}
						}
					}
				}
				finally
				{
					memoryStream?.Close();
					memoryStream2?.Close();
				}
			}
			xs.Add(schemaSerializable);
			return val;
		}
	}

	[Serializable]
	[XmlSchemaProvider("GetTypedTableSchema")]
	public class TableMapDataTable : TypedTableBase<TableMapRow>
	{
		private DataColumn columnTableMap_Id;

		private DataColumn columnProduct_Id;

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public DataColumn TableMap_IdColumn => columnTableMap_Id;

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public DataColumn Product_IdColumn => columnProduct_Id;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[Browsable(false)]
		[DebuggerNonUserCode]
		public int Count => base.Rows.Count;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public TableMapRow this[int index] => (TableMapRow)base.Rows[index];

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public event TableMapRowChangeEventHandler TableMapRowChanging;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public event TableMapRowChangeEventHandler TableMapRowChanged;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public event TableMapRowChangeEventHandler TableMapRowDeleting;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public event TableMapRowChangeEventHandler TableMapRowDeleted;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public TableMapDataTable()
		{
			base.TableName = "TableMap";
			BeginInit();
			InitClass();
			EndInit();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		internal TableMapDataTable(DataTable table)
		{
			base.TableName = table.TableName;
			if (table.CaseSensitive != table.DataSet.CaseSensitive)
			{
				base.CaseSensitive = table.CaseSensitive;
			}
			if (table.Locale.ToString() != table.DataSet.Locale.ToString())
			{
				base.Locale = table.Locale;
			}
			if (table.Namespace != table.DataSet.Namespace)
			{
				base.Namespace = table.Namespace;
			}
			base.Prefix = table.Prefix;
			base.MinimumCapacity = table.MinimumCapacity;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected TableMapDataTable(SerializationInfo info, StreamingContext context)
			: base(info, context)
		{
			InitVars();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public void AddTableMapRow(TableMapRow row)
		{
			base.Rows.Add(row);
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public TableMapRow AddTableMapRow(ProductRow parentProductRowByProduct_TableMap)
		{
			TableMapRow tableMapRow = (TableMapRow)NewRow();
			object[] array = new object[2];
			object[] array2 = array;
			if (parentProductRowByProduct_TableMap != null)
			{
				array2[1] = parentProductRowByProduct_TableMap[6];
			}
			tableMapRow.ItemArray = array2;
			base.Rows.Add(tableMapRow);
			return tableMapRow;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public override DataTable Clone()
		{
			TableMapDataTable tableMapDataTable = (TableMapDataTable)base.Clone();
			tableMapDataTable.InitVars();
			return tableMapDataTable;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		protected override DataTable CreateInstance()
		{
			return new TableMapDataTable();
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		internal void InitVars()
		{
			columnTableMap_Id = base.Columns["TableMap_Id"];
			columnProduct_Id = base.Columns["Product_Id"];
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		private void InitClass()
		{
			columnTableMap_Id = new DataColumn("TableMap_Id", typeof(int), null, MappingType.Hidden);
			base.Columns.Add(columnTableMap_Id);
			columnProduct_Id = new DataColumn("Product_Id", typeof(int), null, MappingType.Hidden);
			base.Columns.Add(columnProduct_Id);
			base.Constraints.Add(new UniqueConstraint("Constraint1", new DataColumn[1] { columnTableMap_Id }, isPrimaryKey: true));
			columnTableMap_Id.AutoIncrement = true;
			columnTableMap_Id.AllowDBNull = false;
			columnTableMap_Id.Unique = true;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public TableMapRow NewTableMapRow()
		{
			return (TableMapRow)NewRow();
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
		{
			return new TableMapRow(builder);
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected override Type GetRowType()
		{
			return typeof(TableMapRow);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		protected override void OnRowChanged(DataRowChangeEventArgs e)
		{
			base.OnRowChanged(e);
			if (this.TableMapRowChanged != null)
			{
				this.TableMapRowChanged(this, new TableMapRowChangeEvent((TableMapRow)e.Row, e.Action));
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected override void OnRowChanging(DataRowChangeEventArgs e)
		{
			base.OnRowChanging(e);
			if (this.TableMapRowChanging != null)
			{
				this.TableMapRowChanging(this, new TableMapRowChangeEvent((TableMapRow)e.Row, e.Action));
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		protected override void OnRowDeleted(DataRowChangeEventArgs e)
		{
			base.OnRowDeleted(e);
			if (this.TableMapRowDeleted != null)
			{
				this.TableMapRowDeleted(this, new TableMapRowChangeEvent((TableMapRow)e.Row, e.Action));
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected override void OnRowDeleting(DataRowChangeEventArgs e)
		{
			base.OnRowDeleting(e);
			if (this.TableMapRowDeleting != null)
			{
				this.TableMapRowDeleting(this, new TableMapRowChangeEvent((TableMapRow)e.Row, e.Action));
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public void RemoveTableMapRow(TableMapRow row)
		{
			base.Rows.Remove(row);
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public static XmlSchemaComplexType GetTypedTableSchema(XmlSchemaSet xs)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Expected O, but got Unknown
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_000c: Expected O, but got Unknown
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Expected O, but got Unknown
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_005a: Expected O, but got Unknown
			//IL_0089: Unknown result type (might be due to invalid IL or missing references)
			//IL_0090: Expected O, but got Unknown
			//IL_00b7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00be: Expected O, but got Unknown
			//IL_013c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0143: Expected O, but got Unknown
			XmlSchemaComplexType val = new XmlSchemaComplexType();
			XmlSchemaSequence val2 = new XmlSchemaSequence();
			ProductInformation productInformation = new ProductInformation();
			XmlSchemaAny val3 = new XmlSchemaAny();
			val3.Namespace = "http://www.w3.org/2001/XMLSchema";
			((XmlSchemaParticle)val3).MinOccurs = 0m;
			((XmlSchemaParticle)val3).MaxOccurs = decimal.MaxValue;
			val3.ProcessContents = (XmlSchemaContentProcessing)2;
			((XmlSchemaGroupBase)val2).Items.Add((XmlSchemaObject)(object)val3);
			XmlSchemaAny val4 = new XmlSchemaAny();
			val4.Namespace = "urn:schemas-microsoft-com:xml-diffgram-v1";
			((XmlSchemaParticle)val4).MinOccurs = 1m;
			val4.ProcessContents = (XmlSchemaContentProcessing)2;
			((XmlSchemaGroupBase)val2).Items.Add((XmlSchemaObject)(object)val4);
			XmlSchemaAttribute val5 = new XmlSchemaAttribute();
			val5.Name = "namespace";
			val5.FixedValue = productInformation.Namespace;
			val.Attributes.Add((XmlSchemaObject)(object)val5);
			XmlSchemaAttribute val6 = new XmlSchemaAttribute();
			val6.Name = "tableTypeName";
			val6.FixedValue = "TableMapDataTable";
			val.Attributes.Add((XmlSchemaObject)(object)val6);
			val.Particle = (XmlSchemaParticle)(object)val2;
			XmlSchema schemaSerializable = productInformation.GetSchemaSerializable();
			if (xs.Contains(schemaSerializable.TargetNamespace))
			{
				MemoryStream memoryStream = new MemoryStream();
				MemoryStream memoryStream2 = new MemoryStream();
				try
				{
					XmlSchema val7 = null;
					schemaSerializable.Write((Stream)memoryStream);
					IEnumerator enumerator = xs.Schemas(schemaSerializable.TargetNamespace).GetEnumerator();
					while (enumerator.MoveNext())
					{
						val7 = (XmlSchema)enumerator.Current;
						memoryStream2.SetLength(0L);
						val7.Write((Stream)memoryStream2);
						if (memoryStream.Length == memoryStream2.Length)
						{
							memoryStream.Position = 0L;
							memoryStream2.Position = 0L;
							while (memoryStream.Position != memoryStream.Length && memoryStream.ReadByte() == memoryStream2.ReadByte())
							{
							}
							if (memoryStream.Position == memoryStream.Length)
							{
								return val;
							}
						}
					}
				}
				finally
				{
					memoryStream?.Close();
					memoryStream2?.Close();
				}
			}
			xs.Add(schemaSerializable);
			return val;
		}
	}

	[Serializable]
	[XmlSchemaProvider("GetTypedTableSchema")]
	public class ColumnMapDataTable : TypedTableBase<ColumnMapRow>
	{
		private DataColumn columnOriginal;

		private DataColumn columnMapName;

		private DataColumn columnTableMap_Id;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public DataColumn OriginalColumn => columnOriginal;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public DataColumn MapNameColumn => columnMapName;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public DataColumn TableMap_IdColumn => columnTableMap_Id;

		[Browsable(false)]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public int Count => base.Rows.Count;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public ColumnMapRow this[int index] => (ColumnMapRow)base.Rows[index];

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public event ColumnMapRowChangeEventHandler ColumnMapRowChanging;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public event ColumnMapRowChangeEventHandler ColumnMapRowChanged;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public event ColumnMapRowChangeEventHandler ColumnMapRowDeleting;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public event ColumnMapRowChangeEventHandler ColumnMapRowDeleted;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public ColumnMapDataTable()
		{
			base.TableName = "ColumnMap";
			BeginInit();
			InitClass();
			EndInit();
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		internal ColumnMapDataTable(DataTable table)
		{
			base.TableName = table.TableName;
			if (table.CaseSensitive != table.DataSet.CaseSensitive)
			{
				base.CaseSensitive = table.CaseSensitive;
			}
			if (table.Locale.ToString() != table.DataSet.Locale.ToString())
			{
				base.Locale = table.Locale;
			}
			if (table.Namespace != table.DataSet.Namespace)
			{
				base.Namespace = table.Namespace;
			}
			base.Prefix = table.Prefix;
			base.MinimumCapacity = table.MinimumCapacity;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		protected ColumnMapDataTable(SerializationInfo info, StreamingContext context)
			: base(info, context)
		{
			InitVars();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public void AddColumnMapRow(ColumnMapRow row)
		{
			base.Rows.Add(row);
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public ColumnMapRow AddColumnMapRow(string Original, string MapName, TableMapRow parentTableMapRowByTableMap_ColumnMap)
		{
			ColumnMapRow columnMapRow = (ColumnMapRow)NewRow();
			object[] array = new object[3] { Original, MapName, null };
			if (parentTableMapRowByTableMap_ColumnMap != null)
			{
				array[2] = parentTableMapRowByTableMap_ColumnMap[0];
			}
			columnMapRow.ItemArray = array;
			base.Rows.Add(columnMapRow);
			return columnMapRow;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public override DataTable Clone()
		{
			ColumnMapDataTable columnMapDataTable = (ColumnMapDataTable)base.Clone();
			columnMapDataTable.InitVars();
			return columnMapDataTable;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected override DataTable CreateInstance()
		{
			return new ColumnMapDataTable();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		internal void InitVars()
		{
			columnOriginal = base.Columns["Original"];
			columnMapName = base.Columns["MapName"];
			columnTableMap_Id = base.Columns["TableMap_Id"];
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		private void InitClass()
		{
			columnOriginal = new DataColumn("Original", typeof(string), null, MappingType.Attribute);
			base.Columns.Add(columnOriginal);
			columnMapName = new DataColumn("MapName", typeof(string), null, MappingType.Attribute);
			base.Columns.Add(columnMapName);
			columnTableMap_Id = new DataColumn("TableMap_Id", typeof(int), null, MappingType.Hidden);
			base.Columns.Add(columnTableMap_Id);
			columnOriginal.Namespace = "";
			columnMapName.Namespace = "";
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public ColumnMapRow NewColumnMapRow()
		{
			return (ColumnMapRow)NewRow();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
		{
			return new ColumnMapRow(builder);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		protected override Type GetRowType()
		{
			return typeof(ColumnMapRow);
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected override void OnRowChanged(DataRowChangeEventArgs e)
		{
			base.OnRowChanged(e);
			if (this.ColumnMapRowChanged != null)
			{
				this.ColumnMapRowChanged(this, new ColumnMapRowChangeEvent((ColumnMapRow)e.Row, e.Action));
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected override void OnRowChanging(DataRowChangeEventArgs e)
		{
			base.OnRowChanging(e);
			if (this.ColumnMapRowChanging != null)
			{
				this.ColumnMapRowChanging(this, new ColumnMapRowChangeEvent((ColumnMapRow)e.Row, e.Action));
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		protected override void OnRowDeleted(DataRowChangeEventArgs e)
		{
			base.OnRowDeleted(e);
			if (this.ColumnMapRowDeleted != null)
			{
				this.ColumnMapRowDeleted(this, new ColumnMapRowChangeEvent((ColumnMapRow)e.Row, e.Action));
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		protected override void OnRowDeleting(DataRowChangeEventArgs e)
		{
			base.OnRowDeleting(e);
			if (this.ColumnMapRowDeleting != null)
			{
				this.ColumnMapRowDeleting(this, new ColumnMapRowChangeEvent((ColumnMapRow)e.Row, e.Action));
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public void RemoveColumnMapRow(ColumnMapRow row)
		{
			base.Rows.Remove(row);
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public static XmlSchemaComplexType GetTypedTableSchema(XmlSchemaSet xs)
		{
			//IL_0000: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Expected O, but got Unknown
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_000c: Expected O, but got Unknown
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			//IL_0018: Expected O, but got Unknown
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_005a: Expected O, but got Unknown
			//IL_0089: Unknown result type (might be due to invalid IL or missing references)
			//IL_0090: Expected O, but got Unknown
			//IL_00b7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00be: Expected O, but got Unknown
			//IL_013c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0143: Expected O, but got Unknown
			XmlSchemaComplexType val = new XmlSchemaComplexType();
			XmlSchemaSequence val2 = new XmlSchemaSequence();
			ProductInformation productInformation = new ProductInformation();
			XmlSchemaAny val3 = new XmlSchemaAny();
			val3.Namespace = "http://www.w3.org/2001/XMLSchema";
			((XmlSchemaParticle)val3).MinOccurs = 0m;
			((XmlSchemaParticle)val3).MaxOccurs = decimal.MaxValue;
			val3.ProcessContents = (XmlSchemaContentProcessing)2;
			((XmlSchemaGroupBase)val2).Items.Add((XmlSchemaObject)(object)val3);
			XmlSchemaAny val4 = new XmlSchemaAny();
			val4.Namespace = "urn:schemas-microsoft-com:xml-diffgram-v1";
			((XmlSchemaParticle)val4).MinOccurs = 1m;
			val4.ProcessContents = (XmlSchemaContentProcessing)2;
			((XmlSchemaGroupBase)val2).Items.Add((XmlSchemaObject)(object)val4);
			XmlSchemaAttribute val5 = new XmlSchemaAttribute();
			val5.Name = "namespace";
			val5.FixedValue = productInformation.Namespace;
			val.Attributes.Add((XmlSchemaObject)(object)val5);
			XmlSchemaAttribute val6 = new XmlSchemaAttribute();
			val6.Name = "tableTypeName";
			val6.FixedValue = "ColumnMapDataTable";
			val.Attributes.Add((XmlSchemaObject)(object)val6);
			val.Particle = (XmlSchemaParticle)(object)val2;
			XmlSchema schemaSerializable = productInformation.GetSchemaSerializable();
			if (xs.Contains(schemaSerializable.TargetNamespace))
			{
				MemoryStream memoryStream = new MemoryStream();
				MemoryStream memoryStream2 = new MemoryStream();
				try
				{
					XmlSchema val7 = null;
					schemaSerializable.Write((Stream)memoryStream);
					IEnumerator enumerator = xs.Schemas(schemaSerializable.TargetNamespace).GetEnumerator();
					while (enumerator.MoveNext())
					{
						val7 = (XmlSchema)enumerator.Current;
						memoryStream2.SetLength(0L);
						val7.Write((Stream)memoryStream2);
						if (memoryStream.Length == memoryStream2.Length)
						{
							memoryStream.Position = 0L;
							memoryStream2.Position = 0L;
							while (memoryStream.Position != memoryStream.Length && memoryStream.ReadByte() == memoryStream2.ReadByte())
							{
							}
							if (memoryStream.Position == memoryStream.Length)
							{
								return val;
							}
						}
					}
				}
				finally
				{
					memoryStream?.Close();
					memoryStream2?.Close();
				}
			}
			xs.Add(schemaSerializable);
			return val;
		}
	}

	public class ProductRow : DataRow
	{
		private ProductDataTable tableProduct;

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public string Id
		{
			get
			{
				try
				{
					return (string)base[tableProduct.IdColumn];
				}
				catch (InvalidCastException innerException)
				{
					throw new StrongTypingException("The value for column 'Id' in table 'Product' is DBNull.", innerException);
				}
			}
			set
			{
				base[tableProduct.IdColumn] = value;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public string DislayName
		{
			get
			{
				try
				{
					return (string)base[tableProduct.DislayNameColumn];
				}
				catch (InvalidCastException innerException)
				{
					throw new StrongTypingException("The value for column 'DislayName' in table 'Product' is DBNull.", innerException);
				}
			}
			set
			{
				base[tableProduct.DislayNameColumn] = value;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public string TableName
		{
			get
			{
				try
				{
					return (string)base[tableProduct.TableNameColumn];
				}
				catch (InvalidCastException innerException)
				{
					throw new StrongTypingException("The value for column 'TableName' in table 'Product' is DBNull.", innerException);
				}
			}
			set
			{
				base[tableProduct.TableNameColumn] = value;
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public string Algorithm
		{
			get
			{
				try
				{
					return (string)base[tableProduct.AlgorithmColumn];
				}
				catch (InvalidCastException innerException)
				{
					throw new StrongTypingException("The value for column 'Algorithm' in table 'Product' is DBNull.", innerException);
				}
			}
			set
			{
				base[tableProduct.AlgorithmColumn] = value;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public string SelectionQuery
		{
			get
			{
				try
				{
					return (string)base[tableProduct.SelectionQueryColumn];
				}
				catch (InvalidCastException innerException)
				{
					throw new StrongTypingException("The value for column 'SelectionQuery' in table 'Product' is DBNull.", innerException);
				}
			}
			set
			{
				base[tableProduct.SelectionQueryColumn] = value;
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public string CalNameColumn
		{
			get
			{
				try
				{
					return (string)base[tableProduct.CalNameColumnColumn];
				}
				catch (InvalidCastException innerException)
				{
					throw new StrongTypingException("The value for column 'CalNameColumn' in table 'Product' is DBNull.", innerException);
				}
			}
			set
			{
				base[tableProduct.CalNameColumnColumn] = value;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public int Product_Id
		{
			get
			{
				return (int)base[tableProduct.Product_IdColumn];
			}
			set
			{
				base[tableProduct.Product_IdColumn] = value;
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		internal ProductRow(DataRowBuilder rb)
			: base(rb)
		{
			tableProduct = (ProductDataTable)base.Table;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public bool IsIdNull()
		{
			return IsNull(tableProduct.IdColumn);
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public void SetIdNull()
		{
			base[tableProduct.IdColumn] = Convert.DBNull;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public bool IsDislayNameNull()
		{
			return IsNull(tableProduct.DislayNameColumn);
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public void SetDislayNameNull()
		{
			base[tableProduct.DislayNameColumn] = Convert.DBNull;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public bool IsTableNameNull()
		{
			return IsNull(tableProduct.TableNameColumn);
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public void SetTableNameNull()
		{
			base[tableProduct.TableNameColumn] = Convert.DBNull;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public bool IsAlgorithmNull()
		{
			return IsNull(tableProduct.AlgorithmColumn);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public void SetAlgorithmNull()
		{
			base[tableProduct.AlgorithmColumn] = Convert.DBNull;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public bool IsSelectionQueryNull()
		{
			return IsNull(tableProduct.SelectionQueryColumn);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public void SetSelectionQueryNull()
		{
			base[tableProduct.SelectionQueryColumn] = Convert.DBNull;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public bool IsCalNameColumnNull()
		{
			return IsNull(tableProduct.CalNameColumnColumn);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public void SetCalNameColumnNull()
		{
			base[tableProduct.CalNameColumnColumn] = Convert.DBNull;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public TableMapRow[] GetTableMapRows()
		{
			if (base.Table.ChildRelations["Product_TableMap"] == null)
			{
				return new TableMapRow[0];
			}
			return (TableMapRow[])GetChildRows(base.Table.ChildRelations["Product_TableMap"]);
		}
	}

	public class TableMapRow : DataRow
	{
		private TableMapDataTable tableTableMap;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public int TableMap_Id
		{
			get
			{
				return (int)base[tableTableMap.TableMap_IdColumn];
			}
			set
			{
				base[tableTableMap.TableMap_IdColumn] = value;
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public int Product_Id
		{
			get
			{
				try
				{
					return (int)base[tableTableMap.Product_IdColumn];
				}
				catch (InvalidCastException innerException)
				{
					throw new StrongTypingException("The value for column 'Product_Id' in table 'TableMap' is DBNull.", innerException);
				}
			}
			set
			{
				base[tableTableMap.Product_IdColumn] = value;
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public ProductRow ProductRow
		{
			get
			{
				return (ProductRow)GetParentRow(base.Table.ParentRelations["Product_TableMap"]);
			}
			set
			{
				SetParentRow(value, base.Table.ParentRelations["Product_TableMap"]);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		internal TableMapRow(DataRowBuilder rb)
			: base(rb)
		{
			tableTableMap = (TableMapDataTable)base.Table;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public bool IsProduct_IdNull()
		{
			return IsNull(tableTableMap.Product_IdColumn);
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public void SetProduct_IdNull()
		{
			base[tableTableMap.Product_IdColumn] = Convert.DBNull;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public ColumnMapRow[] GetColumnMapRows()
		{
			if (base.Table.ChildRelations["TableMap_ColumnMap"] == null)
			{
				return new ColumnMapRow[0];
			}
			return (ColumnMapRow[])GetChildRows(base.Table.ChildRelations["TableMap_ColumnMap"]);
		}
	}

	public class ColumnMapRow : DataRow
	{
		private ColumnMapDataTable tableColumnMap;

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public string Original
		{
			get
			{
				try
				{
					return (string)base[tableColumnMap.OriginalColumn];
				}
				catch (InvalidCastException innerException)
				{
					throw new StrongTypingException("The value for column 'Original' in table 'ColumnMap' is DBNull.", innerException);
				}
			}
			set
			{
				base[tableColumnMap.OriginalColumn] = value;
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public string MapName
		{
			get
			{
				try
				{
					return (string)base[tableColumnMap.MapNameColumn];
				}
				catch (InvalidCastException innerException)
				{
					throw new StrongTypingException("The value for column 'MapName' in table 'ColumnMap' is DBNull.", innerException);
				}
			}
			set
			{
				base[tableColumnMap.MapNameColumn] = value;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public int TableMap_Id
		{
			get
			{
				try
				{
					return (int)base[tableColumnMap.TableMap_IdColumn];
				}
				catch (InvalidCastException innerException)
				{
					throw new StrongTypingException("The value for column 'TableMap_Id' in table 'ColumnMap' is DBNull.", innerException);
				}
			}
			set
			{
				base[tableColumnMap.TableMap_IdColumn] = value;
			}
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public TableMapRow TableMapRow
		{
			get
			{
				return (TableMapRow)GetParentRow(base.Table.ParentRelations["TableMap_ColumnMap"]);
			}
			set
			{
				SetParentRow(value, base.Table.ParentRelations["TableMap_ColumnMap"]);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		internal ColumnMapRow(DataRowBuilder rb)
			: base(rb)
		{
			tableColumnMap = (ColumnMapDataTable)base.Table;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public bool IsOriginalNull()
		{
			return IsNull(tableColumnMap.OriginalColumn);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public void SetOriginalNull()
		{
			base[tableColumnMap.OriginalColumn] = Convert.DBNull;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public bool IsMapNameNull()
		{
			return IsNull(tableColumnMap.MapNameColumn);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public void SetMapNameNull()
		{
			base[tableColumnMap.MapNameColumn] = Convert.DBNull;
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public bool IsTableMap_IdNull()
		{
			return IsNull(tableColumnMap.TableMap_IdColumn);
		}

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public void SetTableMap_IdNull()
		{
			base[tableColumnMap.TableMap_IdColumn] = Convert.DBNull;
		}
	}

	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	public class ProductRowChangeEvent : EventArgs
	{
		private ProductRow eventRow;

		private DataRowAction eventAction;

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public ProductRow Row => eventRow;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public DataRowAction Action => eventAction;

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public ProductRowChangeEvent(ProductRow row, DataRowAction action)
		{
			eventRow = row;
			eventAction = action;
		}
	}

	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	public class TableMapRowChangeEvent : EventArgs
	{
		private TableMapRow eventRow;

		private DataRowAction eventAction;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public TableMapRow Row => eventRow;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public DataRowAction Action => eventAction;

		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		[DebuggerNonUserCode]
		public TableMapRowChangeEvent(TableMapRow row, DataRowAction action)
		{
			eventRow = row;
			eventAction = action;
		}
	}

	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	public class ColumnMapRowChangeEvent : EventArgs
	{
		private ColumnMapRow eventRow;

		private DataRowAction eventAction;

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public ColumnMapRow Row => eventRow;

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public DataRowAction Action => eventAction;

		[DebuggerNonUserCode]
		[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
		public ColumnMapRowChangeEvent(ColumnMapRow row, DataRowAction action)
		{
			eventRow = row;
			eventAction = action;
		}
	}

	private ProductDataTable tableProduct;

	private TableMapDataTable tableTableMap;

	private ColumnMapDataTable tableColumnMap;

	private DataRelation relationProduct_TableMap;

	private DataRelation relationTableMap_ColumnMap;

	private SchemaSerializationMode _schemaSerializationMode = SchemaSerializationMode.IncludeSchema;

	[Browsable(false)]
	[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	[DebuggerNonUserCode]
	public ProductDataTable Product => tableProduct;

	[DebuggerNonUserCode]
	[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	[Browsable(false)]
	public TableMapDataTable TableMap => tableTableMap;

	[Browsable(false)]
	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
	[DebuggerNonUserCode]
	public ColumnMapDataTable ColumnMap => tableColumnMap;

	[Browsable(true)]
	[DebuggerNonUserCode]
	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	[DesignerSerializationVisibility(DesignerSerializationVisibility.Visible)]
	public override SchemaSerializationMode SchemaSerializationMode
	{
		get
		{
			return _schemaSerializationMode;
		}
		set
		{
			_schemaSerializationMode = value;
		}
	}

	[DebuggerNonUserCode]
	[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	public new DataTableCollection Tables => base.Tables;

	[DebuggerNonUserCode]
	[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	public new DataRelationCollection Relations => base.Relations;

	[DebuggerNonUserCode]
	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	public ProductInformation()
	{
		BeginInit();
		InitClass();
		CollectionChangeEventHandler value = SchemaChanged;
		base.Tables.CollectionChanged += value;
		base.Relations.CollectionChanged += value;
		EndInit();
	}

	[DebuggerNonUserCode]
	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	protected ProductInformation(SerializationInfo info, StreamingContext context)
		: base(info, context, ConstructSchema: false)
	{
		//IL_017d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0187: Expected O, but got Unknown
		//IL_007d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0087: Expected O, but got Unknown
		if (IsBinarySerialized(info, context))
		{
			InitVars(initTable: false);
			CollectionChangeEventHandler value = SchemaChanged;
			Tables.CollectionChanged += value;
			Relations.CollectionChanged += value;
			return;
		}
		string s = (string)info.GetValue("XmlSchema", typeof(string));
		if (DetermineSchemaSerializationMode(info, context) == SchemaSerializationMode.IncludeSchema)
		{
			DataSet dataSet = new DataSet();
			dataSet.ReadXmlSchema((XmlReader?)new XmlTextReader((TextReader)new StringReader(s)));
			if (dataSet.Tables["Product"] != null)
			{
				base.Tables.Add(new ProductDataTable(dataSet.Tables["Product"]));
			}
			if (dataSet.Tables["TableMap"] != null)
			{
				base.Tables.Add(new TableMapDataTable(dataSet.Tables["TableMap"]));
			}
			if (dataSet.Tables["ColumnMap"] != null)
			{
				base.Tables.Add(new ColumnMapDataTable(dataSet.Tables["ColumnMap"]));
			}
			base.DataSetName = dataSet.DataSetName;
			base.Prefix = dataSet.Prefix;
			base.Namespace = dataSet.Namespace;
			base.Locale = dataSet.Locale;
			base.CaseSensitive = dataSet.CaseSensitive;
			base.EnforceConstraints = dataSet.EnforceConstraints;
			Merge(dataSet, preserveChanges: false, MissingSchemaAction.Add);
			InitVars();
		}
		else
		{
			ReadXmlSchema((XmlReader?)new XmlTextReader((TextReader)new StringReader(s)));
		}
		GetSerializationData(info, context);
		CollectionChangeEventHandler value2 = SchemaChanged;
		base.Tables.CollectionChanged += value2;
		Relations.CollectionChanged += value2;
	}

	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	[DebuggerNonUserCode]
	protected override void InitializeDerivedDataSet()
	{
		BeginInit();
		InitClass();
		EndInit();
	}

	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	[DebuggerNonUserCode]
	public override DataSet Clone()
	{
		ProductInformation productInformation = (ProductInformation)base.Clone();
		productInformation.InitVars();
		productInformation.SchemaSerializationMode = SchemaSerializationMode;
		return productInformation;
	}

	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	[DebuggerNonUserCode]
	protected override bool ShouldSerializeTables()
	{
		return false;
	}

	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	[DebuggerNonUserCode]
	protected override bool ShouldSerializeRelations()
	{
		return false;
	}

	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	[DebuggerNonUserCode]
	protected override void ReadXmlSerializable(XmlReader reader)
	{
		if (DetermineSchemaSerializationMode(reader) == SchemaSerializationMode.IncludeSchema)
		{
			Reset();
			DataSet dataSet = new DataSet();
			dataSet.ReadXml(reader);
			if (dataSet.Tables["Product"] != null)
			{
				base.Tables.Add(new ProductDataTable(dataSet.Tables["Product"]));
			}
			if (dataSet.Tables["TableMap"] != null)
			{
				base.Tables.Add(new TableMapDataTable(dataSet.Tables["TableMap"]));
			}
			if (dataSet.Tables["ColumnMap"] != null)
			{
				base.Tables.Add(new ColumnMapDataTable(dataSet.Tables["ColumnMap"]));
			}
			base.DataSetName = dataSet.DataSetName;
			base.Prefix = dataSet.Prefix;
			base.Namespace = dataSet.Namespace;
			base.Locale = dataSet.Locale;
			base.CaseSensitive = dataSet.CaseSensitive;
			base.EnforceConstraints = dataSet.EnforceConstraints;
			Merge(dataSet, preserveChanges: false, MissingSchemaAction.Add);
			InitVars();
		}
		else
		{
			ReadXml(reader);
			InitVars();
		}
	}

	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	[DebuggerNonUserCode]
	protected override XmlSchema GetSchemaSerializable()
	{
		//IL_0009: Unknown result type (might be due to invalid IL or missing references)
		//IL_0013: Expected O, but got Unknown
		//IL_001c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0027: Expected O, but got Unknown
		MemoryStream memoryStream = new MemoryStream();
		WriteXmlSchema((XmlWriter?)new XmlTextWriter((Stream)memoryStream, (Encoding)null));
		memoryStream.Position = 0L;
		return XmlSchema.Read((XmlReader)new XmlTextReader((Stream)memoryStream), (ValidationEventHandler)null);
	}

	[DebuggerNonUserCode]
	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	internal void InitVars()
	{
		InitVars(initTable: true);
	}

	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	[DebuggerNonUserCode]
	internal void InitVars(bool initTable)
	{
		tableProduct = (ProductDataTable)base.Tables["Product"];
		if (initTable && tableProduct != null)
		{
			tableProduct.InitVars();
		}
		tableTableMap = (TableMapDataTable)base.Tables["TableMap"];
		if (initTable && tableTableMap != null)
		{
			tableTableMap.InitVars();
		}
		tableColumnMap = (ColumnMapDataTable)base.Tables["ColumnMap"];
		if (initTable && tableColumnMap != null)
		{
			tableColumnMap.InitVars();
		}
		relationProduct_TableMap = Relations["Product_TableMap"];
		relationTableMap_ColumnMap = Relations["TableMap_ColumnMap"];
	}

	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	[DebuggerNonUserCode]
	private void InitClass()
	{
		base.DataSetName = "ProductInformation";
		base.Prefix = "";
		base.EnforceConstraints = true;
		SchemaSerializationMode = SchemaSerializationMode.IncludeSchema;
		tableProduct = new ProductDataTable();
		base.Tables.Add(tableProduct);
		tableTableMap = new TableMapDataTable();
		base.Tables.Add(tableTableMap);
		tableColumnMap = new ColumnMapDataTable();
		base.Tables.Add(tableColumnMap);
		ForeignKeyConstraint foreignKeyConstraint = new ForeignKeyConstraint("Product_TableMap", new DataColumn[1] { tableProduct.Product_IdColumn }, new DataColumn[1] { tableTableMap.Product_IdColumn });
		tableTableMap.Constraints.Add(foreignKeyConstraint);
		foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
		foreignKeyConstraint.DeleteRule = Rule.Cascade;
		foreignKeyConstraint.UpdateRule = Rule.Cascade;
		foreignKeyConstraint = new ForeignKeyConstraint("TableMap_ColumnMap", new DataColumn[1] { tableTableMap.TableMap_IdColumn }, new DataColumn[1] { tableColumnMap.TableMap_IdColumn });
		tableColumnMap.Constraints.Add(foreignKeyConstraint);
		foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
		foreignKeyConstraint.DeleteRule = Rule.Cascade;
		foreignKeyConstraint.UpdateRule = Rule.Cascade;
		relationProduct_TableMap = new DataRelation("Product_TableMap", new DataColumn[1] { tableProduct.Product_IdColumn }, new DataColumn[1] { tableTableMap.Product_IdColumn }, createConstraints: false);
		relationProduct_TableMap.Nested = true;
		Relations.Add(relationProduct_TableMap);
		relationTableMap_ColumnMap = new DataRelation("TableMap_ColumnMap", new DataColumn[1] { tableTableMap.TableMap_IdColumn }, new DataColumn[1] { tableColumnMap.TableMap_IdColumn }, createConstraints: false);
		relationTableMap_ColumnMap.Nested = true;
		Relations.Add(relationTableMap_ColumnMap);
	}

	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	[DebuggerNonUserCode]
	private bool ShouldSerializeProduct()
	{
		return false;
	}

	[DebuggerNonUserCode]
	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	private bool ShouldSerializeTableMap()
	{
		return false;
	}

	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	[DebuggerNonUserCode]
	private bool ShouldSerializeColumnMap()
	{
		return false;
	}

	[DebuggerNonUserCode]
	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	private void SchemaChanged(object sender, CollectionChangeEventArgs e)
	{
		if (e.Action == CollectionChangeAction.Remove)
		{
			InitVars();
		}
	}

	[DebuggerNonUserCode]
	[GeneratedCode("System.Data.Design.TypedDataSetGenerator", "4.0.0.0")]
	public static XmlSchemaComplexType GetTypedDataSetSchema(XmlSchemaSet xs)
	{
		//IL_0006: Unknown result type (might be due to invalid IL or missing references)
		//IL_000c: Expected O, but got Unknown
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0012: Expected O, but got Unknown
		//IL_0012: Unknown result type (might be due to invalid IL or missing references)
		//IL_0018: Expected O, but got Unknown
		//IL_0089: Unknown result type (might be due to invalid IL or missing references)
		//IL_0090: Expected O, but got Unknown
		ProductInformation productInformation = new ProductInformation();
		XmlSchemaComplexType val = new XmlSchemaComplexType();
		XmlSchemaSequence val2 = new XmlSchemaSequence();
		XmlSchemaAny val3 = new XmlSchemaAny();
		val3.Namespace = productInformation.Namespace;
		((XmlSchemaGroupBase)val2).Items.Add((XmlSchemaObject)(object)val3);
		val.Particle = (XmlSchemaParticle)(object)val2;
		XmlSchema schemaSerializable = productInformation.GetSchemaSerializable();
		if (xs.Contains(schemaSerializable.TargetNamespace))
		{
			MemoryStream memoryStream = new MemoryStream();
			MemoryStream memoryStream2 = new MemoryStream();
			try
			{
				XmlSchema val4 = null;
				schemaSerializable.Write((Stream)memoryStream);
				IEnumerator enumerator = xs.Schemas(schemaSerializable.TargetNamespace).GetEnumerator();
				while (enumerator.MoveNext())
				{
					val4 = (XmlSchema)enumerator.Current;
					memoryStream2.SetLength(0L);
					val4.Write((Stream)memoryStream2);
					if (memoryStream.Length == memoryStream2.Length)
					{
						memoryStream.Position = 0L;
						memoryStream2.Position = 0L;
						while (memoryStream.Position != memoryStream.Length && memoryStream.ReadByte() == memoryStream2.ReadByte())
						{
						}
						if (memoryStream.Position == memoryStream.Length)
						{
							return val;
						}
					}
				}
			}
			finally
			{
				memoryStream?.Close();
				memoryStream2?.Close();
			}
		}
		xs.Add(schemaSerializable);
		return val;
	}
}
public class ProductInfo : IComparable<ProductInfo>
{
	private ProductInformation.ProductRow _productRow;

	private DataTable _calTable;

	public string ProductId => _productRow.Id;

	internal DataTable CalibrationTable
	{
		set
		{
			_calTable = value;
		}
	}

	public DownloadAlgorithm DownloadAlgorithm => (DownloadAlgorithm)Enum.Parse(typeof(DownloadAlgorithm), _productRow.Algorithm);

	public ProductInfo(ProductInformation.ProductRow productRow)
	{
		_productRow = productRow;
		_calTable = null;
	}

	public DataTable GetCompatibleCalibrations(string partNumber)
	{
		partNumber = partNumber.Trim();
		partNumber = partNumber.TrimStart(new char[1] { '0' });
		DataTable dataTable = null;
		if (_calTable != null && _calTable.Rows.Count != 0)
		{
			DataRow[] array = _calTable.Select(string.Format(_productRow.SelectionQuery, partNumber));
			if (array.Length > 0)
			{
				dataTable = new DataTable();
				DataRow[] array2 = _calTable.Select(string.Format(_productRow.SelectionQuery, partNumber));
				foreach (DataRow dataRow in array2)
				{
					DataRow dataRow2 = dataTable.NewRow();
					ProductInformation.ColumnMapRow[] columnMapRows = _productRow.GetTableMapRows()[0].GetColumnMapRows();
					foreach (ProductInformation.ColumnMapRow columnMapRow in columnMapRows)
					{
						if (!dataTable.Columns.Contains(columnMapRow.MapName))
						{
							dataTable.Columns.Add(columnMapRow.MapName, typeof(string));
						}
						dataRow2[columnMapRow.MapName] = dataRow[columnMapRow.Original].ToString();
					}
					bool flag = true;
					foreach (DataRow row in dataTable.Rows)
					{
						bool flag2 = true;
						for (int k = 0; k < dataTable.Columns.Count; k++)
						{
							if ((string)row[k] != (string)dataRow2[k])
							{
								flag2 = false;
								break;
							}
						}
						if (flag2)
						{
							flag = false;
							break;
						}
					}
					if (flag)
					{
						dataTable.Rows.Add(dataRow2);
					}
				}
			}
		}
		return dataTable;
	}

	public string GetCalibration(DataRow dataRow)
	{
		return $"{dataRow[_productRow.CalNameColumn]}.{ProductId.ToLower()}";
	}

	public override bool Equals(object otherInfo)
	{
		bool result = false;
		if (otherInfo is ProductInfo)
		{
			result = ProductId == ((ProductInfo)otherInfo).ProductId;
		}
		return result;
	}

	public override int GetHashCode()
	{
		return ProductId.GetHashCode();
	}

	public override string ToString()
	{
		return _productRow.DislayName;
	}

	public int CompareTo(ProductInfo other)
	{
		return ProductId.CompareTo(other.ProductId);
	}
}
public class InCalDatabaseLoader
{
	private const string _DATE_STRING = "DATE";

	private const string _DISPLAY_NAME_STRING = "DISPLAYNAME";

	private const string _DATABASE_LOCATION = "intelect\\esdn\\esdninfo.dat";

	private ProductInformation _productMetadata;

	private static InCalDatabaseLoader _loader = new InCalDatabaseLoader();

	public static InCalDatabaseLoader Instance => _loader;

	internal ProductInformation ProductMetadata => _productMetadata;

	public List<DatabaseInfo> GetDatabases()
	{
		lock (_loader)
		{
			List<DatabaseInfo> list = new List<DatabaseInfo>();
			DriveInfo[] drives = DriveInfo.GetDrives();
			foreach (DriveInfo driveInfo in drives)
			{
				DirectoryInfo rootDirectory = driveInfo.RootDirectory;
				DatabaseInfo databaseInfo = _CreateDBInfo(rootDirectory);
				if (databaseInfo != null)
				{
					list.Add(databaseInfo);
				}
			}
			return list;
		}
	}

	private InCalDatabaseLoader()
	{
		Stream manifestResourceStream = Assembly.GetExecutingAssembly().GetManifestResourceStream("CURE.ProductInformation.xml");
		_productMetadata = new ProductInformation();
		_productMetadata.ReadXml(manifestResourceStream);
		manifestResourceStream.Close();
	}

	private DatabaseInfo _CreateDBInfo(DirectoryInfo dirInfo)
	{
		DatabaseInfo result = null;
		string path = dirInfo.Name + "intelect\\esdn\\esdninfo.dat";
		if (File.Exists(path))
		{
			bool flag = false;
			DateTime calDate = new DateTime(2000, 1, 1);
			string displayName = string.Empty;
			try
			{
				using (StreamReader streamReader = new StreamReader(path))
				{
					while (streamReader.Peek() >= 0)
					{
						string text = streamReader.ReadLine();
						string[] array = text.Split(new char[1] { '=' });
						if (array == null || array.Length != 2)
						{
							continue;
						}
						if (array[0].Trim().ToUpper() == "DATE")
						{
							string text2 = array[1].Trim();
							int result2 = -1;
							int result3 = -1;
							if (text2.Length == 5 && int.TryParse(text2.Substring(0, 2), out result2) && int.TryParse(text2.Substring(2, 3), out result3) && result3 > 0)
							{
								flag = true;
								calDate = calDate.AddYears(result2);
								calDate = calDate.AddDays(result3 - 1);
							}
						}
						else if (array[0].Trim().ToUpper() == "DISPLAYNAME")
						{
							displayName = array[1].Trim();
						}
					}
					streamReader.Close();
				}
				if (flag)
				{
					result = new DatabaseInfo(dirInfo, displayName, calDate);
				}
			}
			catch
			{
			}
		}
		return result;
	}
}
