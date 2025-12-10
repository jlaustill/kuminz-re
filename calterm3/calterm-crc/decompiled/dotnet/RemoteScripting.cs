using System;
using System.Collections;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Xml;
using System.Xml.Schema;
using Cummins.CUTY.Exceptions;
using Cummins.DataMonitor;

[assembly: AssemblyCompany("Cummins, Inc. US")]
[assembly: AssemblyDescription("Cummins CUTY ASAM Scripting Component")]
[assembly: AssemblyCopyright("Copyright 2004 Cummins")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyTitle("CUTY ASAM Scripting Component")]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyProduct("ASAM Scripting Interface")]
[assembly: AssemblyKeyName("")]
[assembly: AssemblyKeyFile("..\\..\\mykey.snk")]
[assembly: AssemblyDelaySign(false)]
[assembly: TypeLibVersion(1, 0)]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyVersion("1.0.3600.41691")]
namespace Cummins
{
	public enum ErrorID
	{
		NoError,
		BadInput,
		NoConnection,
		GetScaledFloat,
		SetScaledFloat,
		QueryAvailableServices,
		ExecuteService,
		ServiceInformation,
		GetParameter,
		SetParameter,
		ExtGetScaledFloat,
		ExtSetScaledFloat,
		Init,
		Identify,
		Exit,
		SelectDescriptionFile,
		RemoveMonitorElement,
		FetchNotification,
		PumpNotification,
		SetupMonitoring,
		SwitchMonitoringState,
		TransferTimeOut,
		LoadScreenFile,
		ReceiveData,
		SendData,
		InvalidCheckSum,
		MonitoringRecording,
		InvalidASAMDataType,
		SendOperation,
		GetSetAddress,
		Download,
		Upload,
		StartMonitor2
	}
	public enum Severity
	{
		Information,
		Warning,
		Error
	}
}
namespace Cummins.CUTY
{
	public abstract class ASAMCommand
	{
		public virtual void Execute()
		{
		}

		protected void validateResponse(MCTelegram telegram)
		{
			switch (telegram.Status)
			{
			case 22102:
				throw new NotSupportedException(telegram.Command.ToString());
			case ushort.MaxValue:
				telegram.getWord();
				throw new Exception(telegram.getString());
			}
		}
	}
	public class ExecuteCommand : ASAMCommand
	{
		private ushort lun;

		private string command;

		protected ITransport transport;

		private string arguments;

		protected string responseString;

		public ushort LUN
		{
			get
			{
				return lun;
			}
			set
			{
				lun = value;
			}
		}

		public string Command
		{
			get
			{
				return command;
			}
			set
			{
				command = value;
			}
		}

		public string Arguments
		{
			get
			{
				return arguments;
			}
			set
			{
				arguments = value;
			}
		}

		public string ResponseString => responseString;

		public ExecuteCommand(ITransport transport)
		{
			this.transport = transport;
		}

		public override void Execute()
		{
			CommunicationLog instanceOf = CommunicationLog.InstanceOf;
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(202);
			ausyTelegram.putString(Command);
			ausyTelegram.putString(Arguments);
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			MCTelegram mCTelegram = new MCTelegram(rawData);
			validateResponse(mCTelegram);
			responseString = mCTelegram.getString();
			instanceOf.AddStringToLog(ElementType.file, "ExecuteCommand.CS");
			instanceOf.WriteToLogFile();
		}
	}
	public class DataBuffer
	{
		internal static int BitsnByte = 8;

		internal static int WordSize = 2;

		protected ushort length;

		protected int index;

		protected byte[] response;

		public DataBuffer(byte[] rawData)
		{
			response = rawData;
		}

		public virtual string getString()
		{
			string text = string.Empty;
			ushort word = getWord();
			if (word > 0)
			{
				int num = 0;
				while (num < word)
				{
					text += (char)response[index];
					num++;
					index++;
				}
			}
			if (word % 2 != 0)
			{
				index++;
			}
			return text.Trim();
		}

		public ushort getWord()
		{
			ushort num = BitConverter.ToUInt16(response, index);
			index += 2;
			if (ServerConnection.SwapBytes)
			{
				num = (ushort)((num << BitsnByte) | (num >> BitsnByte));
			}
			return num;
		}

		public ushort getWord(byte[] buffer, int position)
		{
			ushort num = BitConverter.ToUInt16(buffer, position);
			if (ServerConnection.SwapBytes)
			{
				num = (ushort)((num << BitsnByte) | (num >> BitsnByte));
			}
			return num;
		}

		public ulong getDWord()
		{
			byte[] array = new byte[4]
			{
				response[index],
				response[index + 1],
				response[index + 2],
				response[index + 3]
			};
			if (ServerConnection.SwapBytes)
			{
				Array.Reverse((Array)array);
			}
			ulong result = BitConverter.ToUInt32(array, index);
			index += 4;
			return result;
		}

		public float getFloat()
		{
			byte[] array = new byte[4]
			{
				response[index],
				response[index + 1],
				response[index + 2],
				response[index + 3]
			};
			if (ServerConnection.SwapBytes)
			{
				Array.Reverse((Array)array);
			}
			float result = BitConverter.ToSingle(array, 0);
			index += 4;
			return result;
		}

		public double getDouble()
		{
			byte[] array = new byte[8]
			{
				response[index],
				response[index + 1],
				response[index + 2],
				response[index + 3],
				response[index + 4],
				response[index + 5],
				response[index + 6],
				response[index + 7]
			};
			if (ServerConnection.SwapBytes)
			{
				Array.Reverse((Array)array);
			}
			double result = BitConverter.ToDouble(array, 0);
			index += 8;
			return result;
		}
	}
	public class MCTelegram : DataBuffer
	{
		private ushort status;

		private ushort command;

		private bool isValid;

		public bool IsValid => isValid;

		public ushort Status => status;

		public ushort Command => command;

		public MCTelegram(byte[] rawData)
			: base(rawData)
		{
			if (rawData == null || rawData.Length == 0)
			{
				isValid = false;
			}
			if (rawData.Length % 2 == 0 && rawData.Length >= 8)
			{
				isValid = true;
				response = rawData;
				length = getWord();
				if (length == rawData.Length)
				{
					validateCheckSum();
					command = getWord();
					status = getWord();
					return;
				}
				throw new MCTelegramLengthInvalidException(Facility.ServerConnection, ErrorID.ReceiveData);
			}
			throw new InvalidMCTelegramException(Facility.ServerConnection, ErrorID.ReceiveData);
		}

		public override string getString()
		{
			string result = string.Empty;
			if (index > 4 && index < length - 4)
			{
				result = base.getString();
			}
			return result;
		}

		private void validateCheckSum()
		{
			long num = 0L;
			for (int i = 0; i < response.Length - DataBuffer.WordSize; i += DataBuffer.WordSize)
			{
				num += getWord(response, i);
			}
			ushort num2 = (ushort)num;
			ushort word = getWord(response, response.Length - DataBuffer.WordSize);
			if (word != num2)
			{
				throw new MCTelegramCheckSumFailedException(Facility.ServerConnection, ErrorID.InvalidCheckSum);
			}
		}
	}
	public class ExtQueryServiceCommand : ASAMCommand
	{
		private ITransport transport;

		private StringCollection services;

		public StringCollection Services => services;

		public ExtQueryServiceCommand(ITransport transport)
		{
			this.transport = transport;
		}

		public override void Execute()
		{
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(200);
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			MCTelegram mCTelegram = new MCTelegram(rawData);
			validateResponse(mCTelegram);
			services = new StringCollection();
			ushort word = mCTelegram.getWord();
			for (ushort num = 0; num < word; num++)
			{
				services.Add(mCTelegram.getString());
			}
		}
	}
	public class InitCommand : ASAMCommand
	{
		private ITransport transport;

		public InitCommand(ITransport transport)
		{
			if (transport == null)
			{
				throw new ArgumentNullException("transport carrier");
			}
			this.transport = transport;
		}

		public override void Execute()
		{
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(2);
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			MCTelegram telegram = new MCTelegram(rawData);
			validateResponse(telegram);
		}
	}
	[ComVisible(false)]
	public enum MonitorState
	{
		Monitoring,
		Stopped
	}
	[ComVisible(false)]
	public interface ITransport
	{
		SortedList Properties { get; }

		void Send(byte[] rawData);

		byte[] Receive();

		byte[] Transport(byte[] rawData);
	}
	[ComVisible(false)]
	public interface IService
	{
		int MonitorRefreshRate { get; set; }

		MonitorState MonitorState { get; set; }

		string ReturnFromExecuteCmd { get; }

		MonitorDataRefreshDelegate MonitorDataRefreshEvent { get; set; }

		MonitorMode CurrentMonitorMode { get; set; }

		int UDPPort { get; set; }

		int DEFAULT_UDP_PORT { get; }

		bool IsStartMonitor2 { get; set; }

		ushort LUN { get; }

		bool MonitorStatusWhenMonitoring { get; set; }

		string ServerIdentity { get; }

		void Initialize();

		void Terminate();

		int _Open(string configurationFile, string binaryFile, string destination);

		double GetScaledFloat(string elementName);

		void SetScaledFloat(string elementName, double value);

		void ExecuteCommand(string command, string arguments);

		void AddToMonitor(string elementName);

		void RemoveFromMonitor(string elementName);

		void RemoveAllFromMonitor();

		void BatchAddMonitor(StringCollection elements);

		string GetString(string elementName);

		bool SetString(string elementName, string newValue);

		bool _Download();

		bool _Upload();

		bool _ChangeBinaryFileName(string binaryFileName);

		void ExecuteSendOperation(string _LUN, string operation, string[] inputs, out string[] outputs);

		string ExecuteGetSetAddress(string operation, string address, long length, string newValue);

		string ExecuteGetAddressByParameterName(string parameterName);

		string ExecuteGetParameterUnits(string parameterNames);

		string ExecuteReadNParameters(string inParamNames);
	}
	public class EmergencyCommand : ASAMCommand
	{
		public ushort EventCode;

		private ITransport transport;

		public EmergencyCommand(ITransport Transport)
		{
			if (transport == null)
			{
				throw new ArgumentNullException("transport carrier");
			}
			transport = transport;
			EventCode = 0;
		}

		public override void Execute()
		{
			CommunicationLog instanceOf = CommunicationLog.InstanceOf;
			instanceOf.AddStringToLog(ElementType.file, "EmergencyCommand.CS");
			instanceOf.WriteToLogFile();
		}
	}
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	[Guid("94312B18-0CFD-4b24-975F-FCFCA4BBF9DA")]
	public interface ICICommands4
	{
		[DispId(1)]
		string ReadNParameters(string parameterNames);
	}
	[ComVisible(false)]
	internal class Commands4 : ICICommands4
	{
		private ITransport transport;

		private IService service;

		public Commands4(ITransport transport, IService service)
		{
			this.transport = transport;
			this.service = service;
		}

		public string ReadNParameters(string inParamNames)
		{
			return service.ExecuteReadNParameters(inParamNames);
		}
	}
}
namespace Cummins.DataMonitor
{
	[Serializable]
	[DesignerCategory("code")]
	[DebuggerStepThrough]
	[ToolboxItem(true)]
	public class NewDataSet : DataSet
	{
		public delegate void MonitorSessionRowChangeEventHandler(object sender, MonitorSessionRowChangeEvent e);

		public delegate void ScreenRowChangeEventHandler(object sender, ScreenRowChangeEvent e);

		public delegate void GroupRowChangeEventHandler(object sender, GroupRowChangeEvent e);

		public delegate void ParameterRowChangeEventHandler(object sender, ParameterRowChangeEvent e);

		public delegate void ParameterYAxisRowChangeEventHandler(object sender, ParameterYAxisRowChangeEvent e);

		public delegate void GaugeConfigurationRowChangeEventHandler(object sender, GaugeConfigurationRowChangeEvent e);

		public delegate void GaugeRowChangeEventHandler(object sender, GaugeRowChangeEvent e);

		public delegate void GraphConfigurationRowChangeEventHandler(object sender, GraphConfigurationRowChangeEvent e);

		public delegate void GeneralRowChangeEventHandler(object sender, GeneralRowChangeEvent e);

		public delegate void XAxisRowChangeEventHandler(object sender, XAxisRowChangeEvent e);

		public delegate void YAxesRowChangeEventHandler(object sender, YAxesRowChangeEvent e);

		[DebuggerStepThrough]
		public class MonitorSessionDataTable : DataTable, IEnumerable
		{
			private DataColumn columnVersion;

			private DataColumn columnActiveScreen;

			private DataColumn columnMonitorSession_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn VersionColumn => columnVersion;

			internal DataColumn ActiveScreenColumn => columnActiveScreen;

			internal DataColumn MonitorSession_IdColumn => columnMonitorSession_Id;

			public MonitorSessionRow this[int index] => (MonitorSessionRow)base.Rows[index];

			public event MonitorSessionRowChangeEventHandler MonitorSessionRowChanged;

			public event MonitorSessionRowChangeEventHandler MonitorSessionRowChanging;

			public event MonitorSessionRowChangeEventHandler MonitorSessionRowDeleted;

			public event MonitorSessionRowChangeEventHandler MonitorSessionRowDeleting;

			internal MonitorSessionDataTable()
				: base("MonitorSession")
			{
				InitClass();
			}

			internal MonitorSessionDataTable(DataTable table)
				: base(table.TableName)
			{
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
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddMonitorSessionRow(MonitorSessionRow row)
			{
				base.Rows.Add(row);
			}

			public MonitorSessionRow AddMonitorSessionRow(string Version, string ActiveScreen)
			{
				MonitorSessionRow monitorSessionRow = (MonitorSessionRow)NewRow();
				monitorSessionRow.ItemArray = new object[3] { Version, ActiveScreen, null };
				base.Rows.Add(monitorSessionRow);
				return monitorSessionRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				MonitorSessionDataTable monitorSessionDataTable = (MonitorSessionDataTable)base.Clone();
				monitorSessionDataTable.InitVars();
				return monitorSessionDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new MonitorSessionDataTable();
			}

			internal void InitVars()
			{
				columnVersion = base.Columns["Version"];
				columnActiveScreen = base.Columns["ActiveScreen"];
				columnMonitorSession_Id = base.Columns["MonitorSession_Id"];
			}

			private void InitClass()
			{
				columnVersion = new DataColumn("Version", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnVersion);
				columnActiveScreen = new DataColumn("ActiveScreen", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnActiveScreen);
				columnMonitorSession_Id = new DataColumn("MonitorSession_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnMonitorSession_Id);
				base.Constraints.Add(new UniqueConstraint("Constraint1", new DataColumn[1] { columnMonitorSession_Id }, isPrimaryKey: true));
				columnVersion.AllowDBNull = false;
				columnVersion.Namespace = "";
				columnActiveScreen.Namespace = "";
				columnMonitorSession_Id.AutoIncrement = true;
				columnMonitorSession_Id.AllowDBNull = false;
				columnMonitorSession_Id.Unique = true;
			}

			public MonitorSessionRow NewMonitorSessionRow()
			{
				return (MonitorSessionRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new MonitorSessionRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(MonitorSessionRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.MonitorSessionRowChanged != null)
				{
					this.MonitorSessionRowChanged(this, new MonitorSessionRowChangeEvent((MonitorSessionRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.MonitorSessionRowChanging != null)
				{
					this.MonitorSessionRowChanging(this, new MonitorSessionRowChangeEvent((MonitorSessionRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.MonitorSessionRowDeleted != null)
				{
					this.MonitorSessionRowDeleted(this, new MonitorSessionRowChangeEvent((MonitorSessionRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.MonitorSessionRowDeleting != null)
				{
					this.MonitorSessionRowDeleting(this, new MonitorSessionRowChangeEvent((MonitorSessionRow)e.Row, e.Action));
				}
			}

			public void RemoveMonitorSessionRow(MonitorSessionRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class MonitorSessionRow : DataRow
		{
			private MonitorSessionDataTable tableMonitorSession;

			public string Version
			{
				get
				{
					return (string)base[tableMonitorSession.VersionColumn];
				}
				set
				{
					base[tableMonitorSession.VersionColumn] = value;
				}
			}

			public string ActiveScreen
			{
				get
				{
					try
					{
						return (string)base[tableMonitorSession.ActiveScreenColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableMonitorSession.ActiveScreenColumn] = value;
				}
			}

			internal MonitorSessionRow(DataRowBuilder rb)
				: base(rb)
			{
				tableMonitorSession = (MonitorSessionDataTable)base.Table;
			}

			public bool IsActiveScreenNull()
			{
				return IsNull(tableMonitorSession.ActiveScreenColumn);
			}

			public void SetActiveScreenNull()
			{
				base[tableMonitorSession.ActiveScreenColumn] = Convert.DBNull;
			}

			public ScreenRow[] GetScreenRows()
			{
				return (ScreenRow[])GetChildRows(base.Table.ChildRelations["MonitorSession_Screen"]);
			}
		}

		[DebuggerStepThrough]
		public class MonitorSessionRowChangeEvent : EventArgs
		{
			private MonitorSessionRow eventRow;

			private DataRowAction eventAction;

			public MonitorSessionRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public MonitorSessionRowChangeEvent(MonitorSessionRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class ScreenDataTable : DataTable, IEnumerable
		{
			private DataColumn columnName;

			private DataColumn columnDataRefreshRate;

			private DataColumn columnBAMRefreshRate;

			private DataColumn columnIDLRefreshRate;

			private DataColumn columnUIRefreshRate;

			private DataColumn columnEDMRefreshRate;

			private DataColumn columnDataRefreshUnits;

			private DataColumn columnUIRefreshUnits;

			private DataColumn columnMonitorType;

			private DataColumn columnBAMTrigger;

			private DataColumn columnIDLTrigger;

			private DataColumn columnRadix;

			private DataColumn columnScreenType;

			private DataColumn columnScreen_Id;

			private DataColumn columnMonitorSession_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn NameColumn => columnName;

			internal DataColumn DataRefreshRateColumn => columnDataRefreshRate;

			internal DataColumn BAMRefreshRateColumn => columnBAMRefreshRate;

			internal DataColumn IDLRefreshRateColumn => columnIDLRefreshRate;

			internal DataColumn UIRefreshRateColumn => columnUIRefreshRate;

			internal DataColumn EDMRefreshRateColumn => columnEDMRefreshRate;

			internal DataColumn DataRefreshUnitsColumn => columnDataRefreshUnits;

			internal DataColumn UIRefreshUnitsColumn => columnUIRefreshUnits;

			internal DataColumn MonitorTypeColumn => columnMonitorType;

			internal DataColumn BAMTriggerColumn => columnBAMTrigger;

			internal DataColumn IDLTriggerColumn => columnIDLTrigger;

			internal DataColumn RadixColumn => columnRadix;

			internal DataColumn ScreenTypeColumn => columnScreenType;

			internal DataColumn Screen_IdColumn => columnScreen_Id;

			internal DataColumn MonitorSession_IdColumn => columnMonitorSession_Id;

			public ScreenRow this[int index] => (ScreenRow)base.Rows[index];

			public event ScreenRowChangeEventHandler ScreenRowChanged;

			public event ScreenRowChangeEventHandler ScreenRowChanging;

			public event ScreenRowChangeEventHandler ScreenRowDeleted;

			public event ScreenRowChangeEventHandler ScreenRowDeleting;

			internal ScreenDataTable()
				: base("Screen")
			{
				InitClass();
			}

			internal ScreenDataTable(DataTable table)
				: base(table.TableName)
			{
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
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddScreenRow(ScreenRow row)
			{
				base.Rows.Add(row);
			}

			public ScreenRow AddScreenRow(string Name, ushort DataRefreshRate, ushort BAMRefreshRate, ushort IDLRefreshRate, ushort UIRefreshRate, ushort EDMRefreshRate, string DataRefreshUnits, string UIRefreshUnits, string MonitorType, string BAMTrigger, string IDLTrigger, string Radix, string ScreenType, MonitorSessionRow parentMonitorSessionRowByMonitorSession_Screen)
			{
				ScreenRow screenRow = (ScreenRow)NewRow();
				screenRow.ItemArray = new object[15]
				{
					Name,
					DataRefreshRate,
					BAMRefreshRate,
					IDLRefreshRate,
					UIRefreshRate,
					EDMRefreshRate,
					DataRefreshUnits,
					UIRefreshUnits,
					MonitorType,
					BAMTrigger,
					IDLTrigger,
					Radix,
					ScreenType,
					null,
					parentMonitorSessionRowByMonitorSession_Screen[2]
				};
				base.Rows.Add(screenRow);
				return screenRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				ScreenDataTable screenDataTable = (ScreenDataTable)base.Clone();
				screenDataTable.InitVars();
				return screenDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new ScreenDataTable();
			}

			internal void InitVars()
			{
				columnName = base.Columns["Name"];
				columnDataRefreshRate = base.Columns["DataRefreshRate"];
				columnBAMRefreshRate = base.Columns["BAMRefreshRate"];
				columnIDLRefreshRate = base.Columns["IDLRefreshRate"];
				columnUIRefreshRate = base.Columns["UIRefreshRate"];
				columnEDMRefreshRate = base.Columns["EDMRefreshRate"];
				columnDataRefreshUnits = base.Columns["DataRefreshUnits"];
				columnUIRefreshUnits = base.Columns["UIRefreshUnits"];
				columnMonitorType = base.Columns["MonitorType"];
				columnBAMTrigger = base.Columns["BAMTrigger"];
				columnIDLTrigger = base.Columns["IDLTrigger"];
				columnRadix = base.Columns["Radix"];
				columnScreenType = base.Columns["ScreenType"];
				columnScreen_Id = base.Columns["Screen_Id"];
				columnMonitorSession_Id = base.Columns["MonitorSession_Id"];
			}

			private void InitClass()
			{
				columnName = new DataColumn("Name", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnName);
				columnDataRefreshRate = new DataColumn("DataRefreshRate", typeof(ushort), null, MappingType.Attribute);
				base.Columns.Add(columnDataRefreshRate);
				columnBAMRefreshRate = new DataColumn("BAMRefreshRate", typeof(ushort), null, MappingType.Attribute);
				base.Columns.Add(columnBAMRefreshRate);
				columnIDLRefreshRate = new DataColumn("IDLRefreshRate", typeof(ushort), null, MappingType.Attribute);
				base.Columns.Add(columnIDLRefreshRate);
				columnUIRefreshRate = new DataColumn("UIRefreshRate", typeof(ushort), null, MappingType.Attribute);
				base.Columns.Add(columnUIRefreshRate);
				columnEDMRefreshRate = new DataColumn("EDMRefreshRate", typeof(ushort), null, MappingType.Attribute);
				base.Columns.Add(columnEDMRefreshRate);
				columnDataRefreshUnits = new DataColumn("DataRefreshUnits", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnDataRefreshUnits);
				columnUIRefreshUnits = new DataColumn("UIRefreshUnits", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnUIRefreshUnits);
				columnMonitorType = new DataColumn("MonitorType", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnMonitorType);
				columnBAMTrigger = new DataColumn("BAMTrigger", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnBAMTrigger);
				columnIDLTrigger = new DataColumn("IDLTrigger", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnIDLTrigger);
				columnRadix = new DataColumn("Radix", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnRadix);
				columnScreenType = new DataColumn("ScreenType", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnScreenType);
				columnScreen_Id = new DataColumn("Screen_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnScreen_Id);
				columnMonitorSession_Id = new DataColumn("MonitorSession_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnMonitorSession_Id);
				base.Constraints.Add(new UniqueConstraint("Constraint1", new DataColumn[1] { columnScreen_Id }, isPrimaryKey: true));
				columnName.Namespace = "";
				columnDataRefreshRate.Namespace = "";
				columnBAMRefreshRate.Namespace = "";
				columnIDLRefreshRate.Namespace = "";
				columnUIRefreshRate.Namespace = "";
				columnEDMRefreshRate.Namespace = "";
				columnDataRefreshUnits.Namespace = "";
				columnDataRefreshUnits.DefaultValue = "Milliseconds";
				columnUIRefreshUnits.Namespace = "";
				columnUIRefreshUnits.DefaultValue = "Milliseconds";
				columnMonitorType.Namespace = "";
				columnMonitorType.DefaultValue = "RequestReceive";
				columnBAMTrigger.Namespace = "";
				columnBAMTrigger.DefaultValue = "Clock";
				columnIDLTrigger.Namespace = "";
				columnIDLTrigger.DefaultValue = "Clock";
				columnRadix.Namespace = "";
				columnRadix.DefaultValue = "Decimal";
				columnScreenType.Namespace = "";
				columnScreenType.DefaultValue = "Normal";
				columnScreen_Id.AutoIncrement = true;
				columnScreen_Id.AllowDBNull = false;
				columnScreen_Id.Unique = true;
			}

			public ScreenRow NewScreenRow()
			{
				return (ScreenRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new ScreenRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(ScreenRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.ScreenRowChanged != null)
				{
					this.ScreenRowChanged(this, new ScreenRowChangeEvent((ScreenRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.ScreenRowChanging != null)
				{
					this.ScreenRowChanging(this, new ScreenRowChangeEvent((ScreenRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.ScreenRowDeleted != null)
				{
					this.ScreenRowDeleted(this, new ScreenRowChangeEvent((ScreenRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.ScreenRowDeleting != null)
				{
					this.ScreenRowDeleting(this, new ScreenRowChangeEvent((ScreenRow)e.Row, e.Action));
				}
			}

			public void RemoveScreenRow(ScreenRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class ScreenRow : DataRow
		{
			private ScreenDataTable tableScreen;

			public string Name
			{
				get
				{
					try
					{
						return (string)base[tableScreen.NameColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableScreen.NameColumn] = value;
				}
			}

			public ushort DataRefreshRate
			{
				get
				{
					try
					{
						return (ushort)base[tableScreen.DataRefreshRateColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableScreen.DataRefreshRateColumn] = value;
				}
			}

			public ushort BAMRefreshRate
			{
				get
				{
					try
					{
						return (ushort)base[tableScreen.BAMRefreshRateColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableScreen.BAMRefreshRateColumn] = value;
				}
			}

			public ushort IDLRefreshRate
			{
				get
				{
					try
					{
						return (ushort)base[tableScreen.IDLRefreshRateColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableScreen.IDLRefreshRateColumn] = value;
				}
			}

			public ushort UIRefreshRate
			{
				get
				{
					try
					{
						return (ushort)base[tableScreen.UIRefreshRateColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableScreen.UIRefreshRateColumn] = value;
				}
			}

			public ushort EDMRefreshRate
			{
				get
				{
					try
					{
						return (ushort)base[tableScreen.EDMRefreshRateColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableScreen.EDMRefreshRateColumn] = value;
				}
			}

			public string DataRefreshUnits
			{
				get
				{
					try
					{
						return (string)base[tableScreen.DataRefreshUnitsColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableScreen.DataRefreshUnitsColumn] = value;
				}
			}

			public string UIRefreshUnits
			{
				get
				{
					try
					{
						return (string)base[tableScreen.UIRefreshUnitsColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableScreen.UIRefreshUnitsColumn] = value;
				}
			}

			public string MonitorType
			{
				get
				{
					try
					{
						return (string)base[tableScreen.MonitorTypeColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableScreen.MonitorTypeColumn] = value;
				}
			}

			public string BAMTrigger
			{
				get
				{
					try
					{
						return (string)base[tableScreen.BAMTriggerColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableScreen.BAMTriggerColumn] = value;
				}
			}

			public string IDLTrigger
			{
				get
				{
					try
					{
						return (string)base[tableScreen.IDLTriggerColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableScreen.IDLTriggerColumn] = value;
				}
			}

			public string Radix
			{
				get
				{
					try
					{
						return (string)base[tableScreen.RadixColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableScreen.RadixColumn] = value;
				}
			}

			public string ScreenType
			{
				get
				{
					try
					{
						return (string)base[tableScreen.ScreenTypeColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableScreen.ScreenTypeColumn] = value;
				}
			}

			public MonitorSessionRow MonitorSessionRow
			{
				get
				{
					return (MonitorSessionRow)GetParentRow(base.Table.ParentRelations["MonitorSession_Screen"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["MonitorSession_Screen"]);
				}
			}

			internal ScreenRow(DataRowBuilder rb)
				: base(rb)
			{
				tableScreen = (ScreenDataTable)base.Table;
			}

			public bool IsNameNull()
			{
				return IsNull(tableScreen.NameColumn);
			}

			public void SetNameNull()
			{
				base[tableScreen.NameColumn] = Convert.DBNull;
			}

			public bool IsDataRefreshRateNull()
			{
				return IsNull(tableScreen.DataRefreshRateColumn);
			}

			public void SetDataRefreshRateNull()
			{
				base[tableScreen.DataRefreshRateColumn] = Convert.DBNull;
			}

			public bool IsBAMRefreshRateNull()
			{
				return IsNull(tableScreen.BAMRefreshRateColumn);
			}

			public void SetBAMRefreshRateNull()
			{
				base[tableScreen.BAMRefreshRateColumn] = Convert.DBNull;
			}

			public bool IsIDLRefreshRateNull()
			{
				return IsNull(tableScreen.IDLRefreshRateColumn);
			}

			public void SetIDLRefreshRateNull()
			{
				base[tableScreen.IDLRefreshRateColumn] = Convert.DBNull;
			}

			public bool IsUIRefreshRateNull()
			{
				return IsNull(tableScreen.UIRefreshRateColumn);
			}

			public void SetUIRefreshRateNull()
			{
				base[tableScreen.UIRefreshRateColumn] = Convert.DBNull;
			}

			public bool IsEDMRefreshRateNull()
			{
				return IsNull(tableScreen.EDMRefreshRateColumn);
			}

			public void SetEDMRefreshRateNull()
			{
				base[tableScreen.EDMRefreshRateColumn] = Convert.DBNull;
			}

			public bool IsDataRefreshUnitsNull()
			{
				return IsNull(tableScreen.DataRefreshUnitsColumn);
			}

			public void SetDataRefreshUnitsNull()
			{
				base[tableScreen.DataRefreshUnitsColumn] = Convert.DBNull;
			}

			public bool IsUIRefreshUnitsNull()
			{
				return IsNull(tableScreen.UIRefreshUnitsColumn);
			}

			public void SetUIRefreshUnitsNull()
			{
				base[tableScreen.UIRefreshUnitsColumn] = Convert.DBNull;
			}

			public bool IsMonitorTypeNull()
			{
				return IsNull(tableScreen.MonitorTypeColumn);
			}

			public void SetMonitorTypeNull()
			{
				base[tableScreen.MonitorTypeColumn] = Convert.DBNull;
			}

			public bool IsBAMTriggerNull()
			{
				return IsNull(tableScreen.BAMTriggerColumn);
			}

			public void SetBAMTriggerNull()
			{
				base[tableScreen.BAMTriggerColumn] = Convert.DBNull;
			}

			public bool IsIDLTriggerNull()
			{
				return IsNull(tableScreen.IDLTriggerColumn);
			}

			public void SetIDLTriggerNull()
			{
				base[tableScreen.IDLTriggerColumn] = Convert.DBNull;
			}

			public bool IsRadixNull()
			{
				return IsNull(tableScreen.RadixColumn);
			}

			public void SetRadixNull()
			{
				base[tableScreen.RadixColumn] = Convert.DBNull;
			}

			public bool IsScreenTypeNull()
			{
				return IsNull(tableScreen.ScreenTypeColumn);
			}

			public void SetScreenTypeNull()
			{
				base[tableScreen.ScreenTypeColumn] = Convert.DBNull;
			}

			public GroupRow[] GetGroupRows()
			{
				return (GroupRow[])GetChildRows(base.Table.ChildRelations["Screen_Group"]);
			}
		}

		[DebuggerStepThrough]
		public class ScreenRowChangeEvent : EventArgs
		{
			private ScreenRow eventRow;

			private DataRowAction eventAction;

			public ScreenRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public ScreenRowChangeEvent(ScreenRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class GroupDataTable : DataTable, IEnumerable
		{
			private DataColumn columnName;

			private DataColumn columnComment;

			private DataColumn columnGroup_Id;

			private DataColumn columnScreen_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn NameColumn => columnName;

			internal DataColumn CommentColumn => columnComment;

			internal DataColumn Group_IdColumn => columnGroup_Id;

			internal DataColumn Screen_IdColumn => columnScreen_Id;

			public GroupRow this[int index] => (GroupRow)base.Rows[index];

			public event GroupRowChangeEventHandler GroupRowChanged;

			public event GroupRowChangeEventHandler GroupRowChanging;

			public event GroupRowChangeEventHandler GroupRowDeleted;

			public event GroupRowChangeEventHandler GroupRowDeleting;

			internal GroupDataTable()
				: base("Group")
			{
				InitClass();
			}

			internal GroupDataTable(DataTable table)
				: base(table.TableName)
			{
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
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddGroupRow(GroupRow row)
			{
				base.Rows.Add(row);
			}

			public GroupRow AddGroupRow(string Name, string Comment, ScreenRow parentScreenRowByScreen_Group)
			{
				GroupRow groupRow = (GroupRow)NewRow();
				groupRow.ItemArray = new object[4]
				{
					Name,
					Comment,
					null,
					parentScreenRowByScreen_Group[13]
				};
				base.Rows.Add(groupRow);
				return groupRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				GroupDataTable groupDataTable = (GroupDataTable)base.Clone();
				groupDataTable.InitVars();
				return groupDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new GroupDataTable();
			}

			internal void InitVars()
			{
				columnName = base.Columns["Name"];
				columnComment = base.Columns["Comment"];
				columnGroup_Id = base.Columns["Group_Id"];
				columnScreen_Id = base.Columns["Screen_Id"];
			}

			private void InitClass()
			{
				columnName = new DataColumn("Name", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnName);
				columnComment = new DataColumn("Comment", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnComment);
				columnGroup_Id = new DataColumn("Group_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnGroup_Id);
				columnScreen_Id = new DataColumn("Screen_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnScreen_Id);
				base.Constraints.Add(new UniqueConstraint("Constraint1", new DataColumn[1] { columnGroup_Id }, isPrimaryKey: true));
				columnName.AllowDBNull = false;
				columnName.Namespace = "";
				columnComment.Namespace = "";
				columnGroup_Id.AutoIncrement = true;
				columnGroup_Id.AllowDBNull = false;
				columnGroup_Id.Unique = true;
			}

			public GroupRow NewGroupRow()
			{
				return (GroupRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new GroupRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(GroupRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.GroupRowChanged != null)
				{
					this.GroupRowChanged(this, new GroupRowChangeEvent((GroupRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.GroupRowChanging != null)
				{
					this.GroupRowChanging(this, new GroupRowChangeEvent((GroupRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.GroupRowDeleted != null)
				{
					this.GroupRowDeleted(this, new GroupRowChangeEvent((GroupRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.GroupRowDeleting != null)
				{
					this.GroupRowDeleting(this, new GroupRowChangeEvent((GroupRow)e.Row, e.Action));
				}
			}

			public void RemoveGroupRow(GroupRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class GroupRow : DataRow
		{
			private GroupDataTable tableGroup;

			public string Name
			{
				get
				{
					return (string)base[tableGroup.NameColumn];
				}
				set
				{
					base[tableGroup.NameColumn] = value;
				}
			}

			public string Comment
			{
				get
				{
					try
					{
						return (string)base[tableGroup.CommentColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableGroup.CommentColumn] = value;
				}
			}

			public ScreenRow ScreenRow
			{
				get
				{
					return (ScreenRow)GetParentRow(base.Table.ParentRelations["Screen_Group"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["Screen_Group"]);
				}
			}

			internal GroupRow(DataRowBuilder rb)
				: base(rb)
			{
				tableGroup = (GroupDataTable)base.Table;
			}

			public bool IsCommentNull()
			{
				return IsNull(tableGroup.CommentColumn);
			}

			public void SetCommentNull()
			{
				base[tableGroup.CommentColumn] = Convert.DBNull;
			}

			public ParameterRow[] GetParameterRows()
			{
				return (ParameterRow[])GetChildRows(base.Table.ChildRelations["Group_Parameter"]);
			}

			public GaugeConfigurationRow[] GetGaugeConfigurationRows()
			{
				return (GaugeConfigurationRow[])GetChildRows(base.Table.ChildRelations["Group_GaugeConfiguration"]);
			}

			public GraphConfigurationRow[] GetGraphConfigurationRows()
			{
				return (GraphConfigurationRow[])GetChildRows(base.Table.ChildRelations["Group_GraphConfiguration"]);
			}
		}

		[DebuggerStepThrough]
		public class GroupRowChangeEvent : EventArgs
		{
			private GroupRow eventRow;

			private DataRowAction eventAction;

			public GroupRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public GroupRowChangeEvent(GroupRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class ParameterDataTable : DataTable, IEnumerable
		{
			private DataColumn columnSourceAddress;

			private DataColumn columnName;

			private DataColumn columnUnits;

			private DataColumn columnColor;

			private DataColumn columnGaugeIndex;

			private DataColumn columnViewType;

			private DataColumn columnParameter_Id;

			private DataColumn columnGroup_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn SourceAddressColumn => columnSourceAddress;

			internal DataColumn NameColumn => columnName;

			internal DataColumn UnitsColumn => columnUnits;

			internal DataColumn ColorColumn => columnColor;

			internal DataColumn GaugeIndexColumn => columnGaugeIndex;

			internal DataColumn ViewTypeColumn => columnViewType;

			internal DataColumn Parameter_IdColumn => columnParameter_Id;

			internal DataColumn Group_IdColumn => columnGroup_Id;

			public ParameterRow this[int index] => (ParameterRow)base.Rows[index];

			public event ParameterRowChangeEventHandler ParameterRowChanged;

			public event ParameterRowChangeEventHandler ParameterRowChanging;

			public event ParameterRowChangeEventHandler ParameterRowDeleted;

			public event ParameterRowChangeEventHandler ParameterRowDeleting;

			internal ParameterDataTable()
				: base("Parameter")
			{
				InitClass();
			}

			internal ParameterDataTable(DataTable table)
				: base(table.TableName)
			{
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
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddParameterRow(ParameterRow row)
			{
				base.Rows.Add(row);
			}

			public ParameterRow AddParameterRow(string SourceAddress, string Name, string Units, string Color, short GaugeIndex, string ViewType, GroupRow parentGroupRowByGroup_Parameter)
			{
				ParameterRow parameterRow = (ParameterRow)NewRow();
				parameterRow.ItemArray = new object[8]
				{
					SourceAddress,
					Name,
					Units,
					Color,
					GaugeIndex,
					ViewType,
					null,
					parentGroupRowByGroup_Parameter[2]
				};
				base.Rows.Add(parameterRow);
				return parameterRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				ParameterDataTable parameterDataTable = (ParameterDataTable)base.Clone();
				parameterDataTable.InitVars();
				return parameterDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new ParameterDataTable();
			}

			internal void InitVars()
			{
				columnSourceAddress = base.Columns["SourceAddress"];
				columnName = base.Columns["Name"];
				columnUnits = base.Columns["Units"];
				columnColor = base.Columns["Color"];
				columnGaugeIndex = base.Columns["GaugeIndex"];
				columnViewType = base.Columns["ViewType"];
				columnParameter_Id = base.Columns["Parameter_Id"];
				columnGroup_Id = base.Columns["Group_Id"];
			}

			private void InitClass()
			{
				columnSourceAddress = new DataColumn("SourceAddress", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnSourceAddress);
				columnName = new DataColumn("Name", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnName);
				columnUnits = new DataColumn("Units", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnUnits);
				columnColor = new DataColumn("Color", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnColor);
				columnGaugeIndex = new DataColumn("GaugeIndex", typeof(short), null, MappingType.Element);
				base.Columns.Add(columnGaugeIndex);
				columnViewType = new DataColumn("ViewType", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnViewType);
				columnParameter_Id = new DataColumn("Parameter_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnParameter_Id);
				columnGroup_Id = new DataColumn("Group_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnGroup_Id);
				base.Constraints.Add(new UniqueConstraint("Constraint1", new DataColumn[1] { columnParameter_Id }, isPrimaryKey: true));
				columnSourceAddress.AllowDBNull = false;
				columnSourceAddress.DefaultValue = "0";
				columnName.AllowDBNull = false;
				columnUnits.AllowDBNull = false;
				columnViewType.DefaultValue = "Normal";
				columnParameter_Id.AutoIncrement = true;
				columnParameter_Id.AllowDBNull = false;
				columnParameter_Id.Unique = true;
			}

			public ParameterRow NewParameterRow()
			{
				return (ParameterRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new ParameterRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(ParameterRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.ParameterRowChanged != null)
				{
					this.ParameterRowChanged(this, new ParameterRowChangeEvent((ParameterRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.ParameterRowChanging != null)
				{
					this.ParameterRowChanging(this, new ParameterRowChangeEvent((ParameterRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.ParameterRowDeleted != null)
				{
					this.ParameterRowDeleted(this, new ParameterRowChangeEvent((ParameterRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.ParameterRowDeleting != null)
				{
					this.ParameterRowDeleting(this, new ParameterRowChangeEvent((ParameterRow)e.Row, e.Action));
				}
			}

			public void RemoveParameterRow(ParameterRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class ParameterRow : DataRow
		{
			private ParameterDataTable tableParameter;

			public string SourceAddress
			{
				get
				{
					return (string)base[tableParameter.SourceAddressColumn];
				}
				set
				{
					base[tableParameter.SourceAddressColumn] = value;
				}
			}

			public string Name
			{
				get
				{
					return (string)base[tableParameter.NameColumn];
				}
				set
				{
					base[tableParameter.NameColumn] = value;
				}
			}

			public string Units
			{
				get
				{
					return (string)base[tableParameter.UnitsColumn];
				}
				set
				{
					base[tableParameter.UnitsColumn] = value;
				}
			}

			public string Color
			{
				get
				{
					try
					{
						return (string)base[tableParameter.ColorColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableParameter.ColorColumn] = value;
				}
			}

			public short GaugeIndex
			{
				get
				{
					try
					{
						return (short)base[tableParameter.GaugeIndexColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableParameter.GaugeIndexColumn] = value;
				}
			}

			public string ViewType
			{
				get
				{
					try
					{
						return (string)base[tableParameter.ViewTypeColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableParameter.ViewTypeColumn] = value;
				}
			}

			public GroupRow GroupRow
			{
				get
				{
					return (GroupRow)GetParentRow(base.Table.ParentRelations["Group_Parameter"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["Group_Parameter"]);
				}
			}

			internal ParameterRow(DataRowBuilder rb)
				: base(rb)
			{
				tableParameter = (ParameterDataTable)base.Table;
			}

			public bool IsColorNull()
			{
				return IsNull(tableParameter.ColorColumn);
			}

			public void SetColorNull()
			{
				base[tableParameter.ColorColumn] = Convert.DBNull;
			}

			public bool IsGaugeIndexNull()
			{
				return IsNull(tableParameter.GaugeIndexColumn);
			}

			public void SetGaugeIndexNull()
			{
				base[tableParameter.GaugeIndexColumn] = Convert.DBNull;
			}

			public bool IsViewTypeNull()
			{
				return IsNull(tableParameter.ViewTypeColumn);
			}

			public void SetViewTypeNull()
			{
				base[tableParameter.ViewTypeColumn] = Convert.DBNull;
			}

			public ParameterYAxisRow[] GetParameterYAxisRows()
			{
				return (ParameterYAxisRow[])GetChildRows(base.Table.ChildRelations["Parameter_ParameterYAxis"]);
			}
		}

		[DebuggerStepThrough]
		public class ParameterRowChangeEvent : EventArgs
		{
			private ParameterRow eventRow;

			private DataRowAction eventAction;

			public ParameterRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public ParameterRowChangeEvent(ParameterRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class ParameterYAxisDataTable : DataTable, IEnumerable
		{
			private DataColumn columnAutoScale;

			private DataColumn columnScaleType;

			private DataColumn columnAxisPosition;

			private DataColumn columnMaxValue;

			private DataColumn columnMinValue;

			private DataColumn columnParameter_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn AutoScaleColumn => columnAutoScale;

			internal DataColumn ScaleTypeColumn => columnScaleType;

			internal DataColumn AxisPositionColumn => columnAxisPosition;

			internal DataColumn MaxValueColumn => columnMaxValue;

			internal DataColumn MinValueColumn => columnMinValue;

			internal DataColumn Parameter_IdColumn => columnParameter_Id;

			public ParameterYAxisRow this[int index] => (ParameterYAxisRow)base.Rows[index];

			public event ParameterYAxisRowChangeEventHandler ParameterYAxisRowChanged;

			public event ParameterYAxisRowChangeEventHandler ParameterYAxisRowChanging;

			public event ParameterYAxisRowChangeEventHandler ParameterYAxisRowDeleted;

			public event ParameterYAxisRowChangeEventHandler ParameterYAxisRowDeleting;

			internal ParameterYAxisDataTable()
				: base("ParameterYAxis")
			{
				InitClass();
			}

			internal ParameterYAxisDataTable(DataTable table)
				: base(table.TableName)
			{
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
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddParameterYAxisRow(ParameterYAxisRow row)
			{
				base.Rows.Add(row);
			}

			public ParameterYAxisRow AddParameterYAxisRow(bool AutoScale, string ScaleType, string AxisPosition, double MaxValue, double MinValue, ParameterRow parentParameterRowByParameter_ParameterYAxis)
			{
				ParameterYAxisRow parameterYAxisRow = (ParameterYAxisRow)NewRow();
				parameterYAxisRow.ItemArray = new object[6]
				{
					AutoScale,
					ScaleType,
					AxisPosition,
					MaxValue,
					MinValue,
					parentParameterRowByParameter_ParameterYAxis[6]
				};
				base.Rows.Add(parameterYAxisRow);
				return parameterYAxisRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				ParameterYAxisDataTable parameterYAxisDataTable = (ParameterYAxisDataTable)base.Clone();
				parameterYAxisDataTable.InitVars();
				return parameterYAxisDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new ParameterYAxisDataTable();
			}

			internal void InitVars()
			{
				columnAutoScale = base.Columns["AutoScale"];
				columnScaleType = base.Columns["ScaleType"];
				columnAxisPosition = base.Columns["AxisPosition"];
				columnMaxValue = base.Columns["MaxValue"];
				columnMinValue = base.Columns["MinValue"];
				columnParameter_Id = base.Columns["Parameter_Id"];
			}

			private void InitClass()
			{
				columnAutoScale = new DataColumn("AutoScale", typeof(bool), null, MappingType.Element);
				base.Columns.Add(columnAutoScale);
				columnScaleType = new DataColumn("ScaleType", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnScaleType);
				columnAxisPosition = new DataColumn("AxisPosition", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAxisPosition);
				columnMaxValue = new DataColumn("MaxValue", typeof(double), null, MappingType.Element);
				base.Columns.Add(columnMaxValue);
				columnMinValue = new DataColumn("MinValue", typeof(double), null, MappingType.Element);
				base.Columns.Add(columnMinValue);
				columnParameter_Id = new DataColumn("Parameter_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnParameter_Id);
				columnAutoScale.AllowDBNull = false;
				columnAutoScale.DefaultValue = false;
				columnScaleType.AllowDBNull = false;
				columnScaleType.DefaultValue = "Linear";
				columnAxisPosition.AllowDBNull = false;
				columnAxisPosition.DefaultValue = "Left";
				columnMaxValue.DefaultValue = 100;
				columnMinValue.AllowDBNull = false;
				columnMinValue.DefaultValue = 0;
			}

			public ParameterYAxisRow NewParameterYAxisRow()
			{
				return (ParameterYAxisRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new ParameterYAxisRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(ParameterYAxisRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.ParameterYAxisRowChanged != null)
				{
					this.ParameterYAxisRowChanged(this, new ParameterYAxisRowChangeEvent((ParameterYAxisRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.ParameterYAxisRowChanging != null)
				{
					this.ParameterYAxisRowChanging(this, new ParameterYAxisRowChangeEvent((ParameterYAxisRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.ParameterYAxisRowDeleted != null)
				{
					this.ParameterYAxisRowDeleted(this, new ParameterYAxisRowChangeEvent((ParameterYAxisRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.ParameterYAxisRowDeleting != null)
				{
					this.ParameterYAxisRowDeleting(this, new ParameterYAxisRowChangeEvent((ParameterYAxisRow)e.Row, e.Action));
				}
			}

			public void RemoveParameterYAxisRow(ParameterYAxisRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class ParameterYAxisRow : DataRow
		{
			private ParameterYAxisDataTable tableParameterYAxis;

			public bool AutoScale
			{
				get
				{
					return (bool)base[tableParameterYAxis.AutoScaleColumn];
				}
				set
				{
					base[tableParameterYAxis.AutoScaleColumn] = value;
				}
			}

			public string ScaleType
			{
				get
				{
					return (string)base[tableParameterYAxis.ScaleTypeColumn];
				}
				set
				{
					base[tableParameterYAxis.ScaleTypeColumn] = value;
				}
			}

			public string AxisPosition
			{
				get
				{
					return (string)base[tableParameterYAxis.AxisPositionColumn];
				}
				set
				{
					base[tableParameterYAxis.AxisPositionColumn] = value;
				}
			}

			public double MaxValue
			{
				get
				{
					try
					{
						return (double)base[tableParameterYAxis.MaxValueColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableParameterYAxis.MaxValueColumn] = value;
				}
			}

			public double MinValue
			{
				get
				{
					return (double)base[tableParameterYAxis.MinValueColumn];
				}
				set
				{
					base[tableParameterYAxis.MinValueColumn] = value;
				}
			}

			public ParameterRow ParameterRow
			{
				get
				{
					return (ParameterRow)GetParentRow(base.Table.ParentRelations["Parameter_ParameterYAxis"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["Parameter_ParameterYAxis"]);
				}
			}

			internal ParameterYAxisRow(DataRowBuilder rb)
				: base(rb)
			{
				tableParameterYAxis = (ParameterYAxisDataTable)base.Table;
			}

			public bool IsMaxValueNull()
			{
				return IsNull(tableParameterYAxis.MaxValueColumn);
			}

			public void SetMaxValueNull()
			{
				base[tableParameterYAxis.MaxValueColumn] = Convert.DBNull;
			}
		}

		[DebuggerStepThrough]
		public class ParameterYAxisRowChangeEvent : EventArgs
		{
			private ParameterYAxisRow eventRow;

			private DataRowAction eventAction;

			public ParameterYAxisRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public ParameterYAxisRowChangeEvent(ParameterYAxisRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class GaugeConfigurationDataTable : DataTable, IEnumerable
		{
			private DataColumn columnGaugeConfiguration_Id;

			private DataColumn columnGroup_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn GaugeConfiguration_IdColumn => columnGaugeConfiguration_Id;

			internal DataColumn Group_IdColumn => columnGroup_Id;

			public GaugeConfigurationRow this[int index] => (GaugeConfigurationRow)base.Rows[index];

			public event GaugeConfigurationRowChangeEventHandler GaugeConfigurationRowChanged;

			public event GaugeConfigurationRowChangeEventHandler GaugeConfigurationRowChanging;

			public event GaugeConfigurationRowChangeEventHandler GaugeConfigurationRowDeleted;

			public event GaugeConfigurationRowChangeEventHandler GaugeConfigurationRowDeleting;

			internal GaugeConfigurationDataTable()
				: base("GaugeConfiguration")
			{
				InitClass();
			}

			internal GaugeConfigurationDataTable(DataTable table)
				: base(table.TableName)
			{
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
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddGaugeConfigurationRow(GaugeConfigurationRow row)
			{
				base.Rows.Add(row);
			}

			public GaugeConfigurationRow AddGaugeConfigurationRow(GroupRow parentGroupRowByGroup_GaugeConfiguration)
			{
				GaugeConfigurationRow gaugeConfigurationRow = (GaugeConfigurationRow)NewRow();
				gaugeConfigurationRow.ItemArray = new object[2]
				{
					null,
					parentGroupRowByGroup_GaugeConfiguration[2]
				};
				base.Rows.Add(gaugeConfigurationRow);
				return gaugeConfigurationRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				GaugeConfigurationDataTable gaugeConfigurationDataTable = (GaugeConfigurationDataTable)base.Clone();
				gaugeConfigurationDataTable.InitVars();
				return gaugeConfigurationDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new GaugeConfigurationDataTable();
			}

			internal void InitVars()
			{
				columnGaugeConfiguration_Id = base.Columns["GaugeConfiguration_Id"];
				columnGroup_Id = base.Columns["Group_Id"];
			}

			private void InitClass()
			{
				columnGaugeConfiguration_Id = new DataColumn("GaugeConfiguration_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnGaugeConfiguration_Id);
				columnGroup_Id = new DataColumn("Group_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnGroup_Id);
				base.Constraints.Add(new UniqueConstraint("Constraint1", new DataColumn[1] { columnGaugeConfiguration_Id }, isPrimaryKey: true));
				columnGaugeConfiguration_Id.AutoIncrement = true;
				columnGaugeConfiguration_Id.AllowDBNull = false;
				columnGaugeConfiguration_Id.Unique = true;
			}

			public GaugeConfigurationRow NewGaugeConfigurationRow()
			{
				return (GaugeConfigurationRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new GaugeConfigurationRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(GaugeConfigurationRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.GaugeConfigurationRowChanged != null)
				{
					this.GaugeConfigurationRowChanged(this, new GaugeConfigurationRowChangeEvent((GaugeConfigurationRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.GaugeConfigurationRowChanging != null)
				{
					this.GaugeConfigurationRowChanging(this, new GaugeConfigurationRowChangeEvent((GaugeConfigurationRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.GaugeConfigurationRowDeleted != null)
				{
					this.GaugeConfigurationRowDeleted(this, new GaugeConfigurationRowChangeEvent((GaugeConfigurationRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.GaugeConfigurationRowDeleting != null)
				{
					this.GaugeConfigurationRowDeleting(this, new GaugeConfigurationRowChangeEvent((GaugeConfigurationRow)e.Row, e.Action));
				}
			}

			public void RemoveGaugeConfigurationRow(GaugeConfigurationRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class GaugeConfigurationRow : DataRow
		{
			private GaugeConfigurationDataTable tableGaugeConfiguration;

			public GroupRow GroupRow
			{
				get
				{
					return (GroupRow)GetParentRow(base.Table.ParentRelations["Group_GaugeConfiguration"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["Group_GaugeConfiguration"]);
				}
			}

			internal GaugeConfigurationRow(DataRowBuilder rb)
				: base(rb)
			{
				tableGaugeConfiguration = (GaugeConfigurationDataTable)base.Table;
			}

			public GaugeRow[] GetGaugeRows()
			{
				return (GaugeRow[])GetChildRows(base.Table.ChildRelations["GaugeConfiguration_Gauge"]);
			}
		}

		[DebuggerStepThrough]
		public class GaugeConfigurationRowChangeEvent : EventArgs
		{
			private GaugeConfigurationRow eventRow;

			private DataRowAction eventAction;

			public GaugeConfigurationRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public GaugeConfigurationRowChangeEvent(GaugeConfigurationRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class GaugeDataTable : DataTable, IEnumerable
		{
			private DataColumn columnIndex;

			private DataColumn columnRedLinesStart;

			private DataColumn columnRedLineVisible;

			private DataColumn columnMaxValue;

			private DataColumn columnMinValue;

			private DataColumn columnGaugeConfiguration_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn IndexColumn => columnIndex;

			internal DataColumn RedLinesStartColumn => columnRedLinesStart;

			internal DataColumn RedLineVisibleColumn => columnRedLineVisible;

			internal DataColumn MaxValueColumn => columnMaxValue;

			internal DataColumn MinValueColumn => columnMinValue;

			internal DataColumn GaugeConfiguration_IdColumn => columnGaugeConfiguration_Id;

			public GaugeRow this[int index] => (GaugeRow)base.Rows[index];

			public event GaugeRowChangeEventHandler GaugeRowChanged;

			public event GaugeRowChangeEventHandler GaugeRowChanging;

			public event GaugeRowChangeEventHandler GaugeRowDeleted;

			public event GaugeRowChangeEventHandler GaugeRowDeleting;

			internal GaugeDataTable()
				: base("Gauge")
			{
				InitClass();
			}

			internal GaugeDataTable(DataTable table)
				: base(table.TableName)
			{
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
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddGaugeRow(GaugeRow row)
			{
				base.Rows.Add(row);
			}

			public GaugeRow AddGaugeRow(int Index, double RedLinesStart, bool RedLineVisible, double MaxValue, double MinValue, GaugeConfigurationRow parentGaugeConfigurationRowByGaugeConfiguration_Gauge)
			{
				GaugeRow gaugeRow = (GaugeRow)NewRow();
				gaugeRow.ItemArray = new object[6]
				{
					Index,
					RedLinesStart,
					RedLineVisible,
					MaxValue,
					MinValue,
					parentGaugeConfigurationRowByGaugeConfiguration_Gauge[0]
				};
				base.Rows.Add(gaugeRow);
				return gaugeRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				GaugeDataTable gaugeDataTable = (GaugeDataTable)base.Clone();
				gaugeDataTable.InitVars();
				return gaugeDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new GaugeDataTable();
			}

			internal void InitVars()
			{
				columnIndex = base.Columns["Index"];
				columnRedLinesStart = base.Columns["RedLinesStart"];
				columnRedLineVisible = base.Columns["RedLineVisible"];
				columnMaxValue = base.Columns["MaxValue"];
				columnMinValue = base.Columns["MinValue"];
				columnGaugeConfiguration_Id = base.Columns["GaugeConfiguration_Id"];
			}

			private void InitClass()
			{
				columnIndex = new DataColumn("Index", typeof(int), null, MappingType.Element);
				base.Columns.Add(columnIndex);
				columnRedLinesStart = new DataColumn("RedLinesStart", typeof(double), null, MappingType.Element);
				base.Columns.Add(columnRedLinesStart);
				columnRedLineVisible = new DataColumn("RedLineVisible", typeof(bool), null, MappingType.Element);
				base.Columns.Add(columnRedLineVisible);
				columnMaxValue = new DataColumn("MaxValue", typeof(double), null, MappingType.Element);
				base.Columns.Add(columnMaxValue);
				columnMinValue = new DataColumn("MinValue", typeof(double), null, MappingType.Element);
				base.Columns.Add(columnMinValue);
				columnGaugeConfiguration_Id = new DataColumn("GaugeConfiguration_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnGaugeConfiguration_Id);
				columnIndex.AllowDBNull = false;
				columnIndex.DefaultValue = -1;
				columnRedLinesStart.AllowDBNull = false;
				columnRedLinesStart.DefaultValue = 90;
				columnRedLineVisible.AllowDBNull = false;
				columnRedLineVisible.DefaultValue = true;
				columnMaxValue.DefaultValue = 100;
				columnMinValue.AllowDBNull = false;
				columnMinValue.DefaultValue = 0;
			}

			public GaugeRow NewGaugeRow()
			{
				return (GaugeRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new GaugeRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(GaugeRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.GaugeRowChanged != null)
				{
					this.GaugeRowChanged(this, new GaugeRowChangeEvent((GaugeRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.GaugeRowChanging != null)
				{
					this.GaugeRowChanging(this, new GaugeRowChangeEvent((GaugeRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.GaugeRowDeleted != null)
				{
					this.GaugeRowDeleted(this, new GaugeRowChangeEvent((GaugeRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.GaugeRowDeleting != null)
				{
					this.GaugeRowDeleting(this, new GaugeRowChangeEvent((GaugeRow)e.Row, e.Action));
				}
			}

			public void RemoveGaugeRow(GaugeRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class GaugeRow : DataRow
		{
			private GaugeDataTable tableGauge;

			public int Index
			{
				get
				{
					return (int)base[tableGauge.IndexColumn];
				}
				set
				{
					base[tableGauge.IndexColumn] = value;
				}
			}

			public double RedLinesStart
			{
				get
				{
					return (double)base[tableGauge.RedLinesStartColumn];
				}
				set
				{
					base[tableGauge.RedLinesStartColumn] = value;
				}
			}

			public bool RedLineVisible
			{
				get
				{
					return (bool)base[tableGauge.RedLineVisibleColumn];
				}
				set
				{
					base[tableGauge.RedLineVisibleColumn] = value;
				}
			}

			public double MaxValue
			{
				get
				{
					try
					{
						return (double)base[tableGauge.MaxValueColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableGauge.MaxValueColumn] = value;
				}
			}

			public double MinValue
			{
				get
				{
					return (double)base[tableGauge.MinValueColumn];
				}
				set
				{
					base[tableGauge.MinValueColumn] = value;
				}
			}

			public GaugeConfigurationRow GaugeConfigurationRow
			{
				get
				{
					return (GaugeConfigurationRow)GetParentRow(base.Table.ParentRelations["GaugeConfiguration_Gauge"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["GaugeConfiguration_Gauge"]);
				}
			}

			internal GaugeRow(DataRowBuilder rb)
				: base(rb)
			{
				tableGauge = (GaugeDataTable)base.Table;
			}

			public bool IsMaxValueNull()
			{
				return IsNull(tableGauge.MaxValueColumn);
			}

			public void SetMaxValueNull()
			{
				base[tableGauge.MaxValueColumn] = Convert.DBNull;
			}
		}

		[DebuggerStepThrough]
		public class GaugeRowChangeEvent : EventArgs
		{
			private GaugeRow eventRow;

			private DataRowAction eventAction;

			public GaugeRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public GaugeRowChangeEvent(GaugeRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class GraphConfigurationDataTable : DataTable, IEnumerable
		{
			private DataColumn columnGraphConfiguration_Id;

			private DataColumn columnGroup_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn GraphConfiguration_IdColumn => columnGraphConfiguration_Id;

			internal DataColumn Group_IdColumn => columnGroup_Id;

			public GraphConfigurationRow this[int index] => (GraphConfigurationRow)base.Rows[index];

			public event GraphConfigurationRowChangeEventHandler GraphConfigurationRowChanged;

			public event GraphConfigurationRowChangeEventHandler GraphConfigurationRowChanging;

			public event GraphConfigurationRowChangeEventHandler GraphConfigurationRowDeleted;

			public event GraphConfigurationRowChangeEventHandler GraphConfigurationRowDeleting;

			internal GraphConfigurationDataTable()
				: base("GraphConfiguration")
			{
				InitClass();
			}

			internal GraphConfigurationDataTable(DataTable table)
				: base(table.TableName)
			{
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
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddGraphConfigurationRow(GraphConfigurationRow row)
			{
				base.Rows.Add(row);
			}

			public GraphConfigurationRow AddGraphConfigurationRow(GroupRow parentGroupRowByGroup_GraphConfiguration)
			{
				GraphConfigurationRow graphConfigurationRow = (GraphConfigurationRow)NewRow();
				graphConfigurationRow.ItemArray = new object[2]
				{
					null,
					parentGroupRowByGroup_GraphConfiguration[2]
				};
				base.Rows.Add(graphConfigurationRow);
				return graphConfigurationRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				GraphConfigurationDataTable graphConfigurationDataTable = (GraphConfigurationDataTable)base.Clone();
				graphConfigurationDataTable.InitVars();
				return graphConfigurationDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new GraphConfigurationDataTable();
			}

			internal void InitVars()
			{
				columnGraphConfiguration_Id = base.Columns["GraphConfiguration_Id"];
				columnGroup_Id = base.Columns["Group_Id"];
			}

			private void InitClass()
			{
				columnGraphConfiguration_Id = new DataColumn("GraphConfiguration_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnGraphConfiguration_Id);
				columnGroup_Id = new DataColumn("Group_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnGroup_Id);
				base.Constraints.Add(new UniqueConstraint("Constraint1", new DataColumn[1] { columnGraphConfiguration_Id }, isPrimaryKey: true));
				columnGraphConfiguration_Id.AutoIncrement = true;
				columnGraphConfiguration_Id.AllowDBNull = false;
				columnGraphConfiguration_Id.Unique = true;
			}

			public GraphConfigurationRow NewGraphConfigurationRow()
			{
				return (GraphConfigurationRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new GraphConfigurationRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(GraphConfigurationRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.GraphConfigurationRowChanged != null)
				{
					this.GraphConfigurationRowChanged(this, new GraphConfigurationRowChangeEvent((GraphConfigurationRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.GraphConfigurationRowChanging != null)
				{
					this.GraphConfigurationRowChanging(this, new GraphConfigurationRowChangeEvent((GraphConfigurationRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.GraphConfigurationRowDeleted != null)
				{
					this.GraphConfigurationRowDeleted(this, new GraphConfigurationRowChangeEvent((GraphConfigurationRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.GraphConfigurationRowDeleting != null)
				{
					this.GraphConfigurationRowDeleting(this, new GraphConfigurationRowChangeEvent((GraphConfigurationRow)e.Row, e.Action));
				}
			}

			public void RemoveGraphConfigurationRow(GraphConfigurationRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class GraphConfigurationRow : DataRow
		{
			private GraphConfigurationDataTable tableGraphConfiguration;

			public GroupRow GroupRow
			{
				get
				{
					return (GroupRow)GetParentRow(base.Table.ParentRelations["Group_GraphConfiguration"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["Group_GraphConfiguration"]);
				}
			}

			internal GraphConfigurationRow(DataRowBuilder rb)
				: base(rb)
			{
				tableGraphConfiguration = (GraphConfigurationDataTable)base.Table;
			}

			public GeneralRow[] GetGeneralRows()
			{
				return (GeneralRow[])GetChildRows(base.Table.ChildRelations["GraphConfiguration_General"]);
			}

			public XAxisRow[] GetXAxisRows()
			{
				return (XAxisRow[])GetChildRows(base.Table.ChildRelations["GraphConfiguration_XAxis"]);
			}

			public YAxesRow[] GetYAxesRows()
			{
				return (YAxesRow[])GetChildRows(base.Table.ChildRelations["GraphConfiguration_YAxes"]);
			}
		}

		[DebuggerStepThrough]
		public class GraphConfigurationRowChangeEvent : EventArgs
		{
			private GraphConfigurationRow eventRow;

			private DataRowAction eventAction;

			public GraphConfigurationRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public GraphConfigurationRowChangeEvent(GraphConfigurationRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class GeneralDataTable : DataTable, IEnumerable
		{
			private DataColumn columnBackColor;

			private DataColumn columnTitle;

			private DataColumn columnTitlePosition;

			private DataColumn columnTitleVisble;

			private DataColumn columnGraphConfiguration_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn BackColorColumn => columnBackColor;

			internal DataColumn TitleColumn => columnTitle;

			internal DataColumn TitlePositionColumn => columnTitlePosition;

			internal DataColumn TitleVisbleColumn => columnTitleVisble;

			internal DataColumn GraphConfiguration_IdColumn => columnGraphConfiguration_Id;

			public GeneralRow this[int index] => (GeneralRow)base.Rows[index];

			public event GeneralRowChangeEventHandler GeneralRowChanged;

			public event GeneralRowChangeEventHandler GeneralRowChanging;

			public event GeneralRowChangeEventHandler GeneralRowDeleted;

			public event GeneralRowChangeEventHandler GeneralRowDeleting;

			internal GeneralDataTable()
				: base("General")
			{
				InitClass();
			}

			internal GeneralDataTable(DataTable table)
				: base(table.TableName)
			{
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
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddGeneralRow(GeneralRow row)
			{
				base.Rows.Add(row);
			}

			public GeneralRow AddGeneralRow(string BackColor, string Title, string TitlePosition, bool TitleVisble, GraphConfigurationRow parentGraphConfigurationRowByGraphConfiguration_General)
			{
				GeneralRow generalRow = (GeneralRow)NewRow();
				generalRow.ItemArray = new object[5]
				{
					BackColor,
					Title,
					TitlePosition,
					TitleVisble,
					parentGraphConfigurationRowByGraphConfiguration_General[0]
				};
				base.Rows.Add(generalRow);
				return generalRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				GeneralDataTable generalDataTable = (GeneralDataTable)base.Clone();
				generalDataTable.InitVars();
				return generalDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new GeneralDataTable();
			}

			internal void InitVars()
			{
				columnBackColor = base.Columns["BackColor"];
				columnTitle = base.Columns["Title"];
				columnTitlePosition = base.Columns["TitlePosition"];
				columnTitleVisble = base.Columns["TitleVisble"];
				columnGraphConfiguration_Id = base.Columns["GraphConfiguration_Id"];
			}

			private void InitClass()
			{
				columnBackColor = new DataColumn("BackColor", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnBackColor);
				columnTitle = new DataColumn("Title", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnTitle);
				columnTitlePosition = new DataColumn("TitlePosition", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnTitlePosition);
				columnTitleVisble = new DataColumn("TitleVisble", typeof(bool), null, MappingType.Element);
				base.Columns.Add(columnTitleVisble);
				columnGraphConfiguration_Id = new DataColumn("GraphConfiguration_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnGraphConfiguration_Id);
				columnBackColor.AllowDBNull = false;
				columnTitle.AllowDBNull = false;
				columnTitlePosition.AllowDBNull = false;
				columnTitlePosition.DefaultValue = "Top";
				columnTitleVisble.AllowDBNull = false;
			}

			public GeneralRow NewGeneralRow()
			{
				return (GeneralRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new GeneralRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(GeneralRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.GeneralRowChanged != null)
				{
					this.GeneralRowChanged(this, new GeneralRowChangeEvent((GeneralRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.GeneralRowChanging != null)
				{
					this.GeneralRowChanging(this, new GeneralRowChangeEvent((GeneralRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.GeneralRowDeleted != null)
				{
					this.GeneralRowDeleted(this, new GeneralRowChangeEvent((GeneralRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.GeneralRowDeleting != null)
				{
					this.GeneralRowDeleting(this, new GeneralRowChangeEvent((GeneralRow)e.Row, e.Action));
				}
			}

			public void RemoveGeneralRow(GeneralRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class GeneralRow : DataRow
		{
			private GeneralDataTable tableGeneral;

			public string BackColor
			{
				get
				{
					return (string)base[tableGeneral.BackColorColumn];
				}
				set
				{
					base[tableGeneral.BackColorColumn] = value;
				}
			}

			public string Title
			{
				get
				{
					return (string)base[tableGeneral.TitleColumn];
				}
				set
				{
					base[tableGeneral.TitleColumn] = value;
				}
			}

			public string TitlePosition
			{
				get
				{
					return (string)base[tableGeneral.TitlePositionColumn];
				}
				set
				{
					base[tableGeneral.TitlePositionColumn] = value;
				}
			}

			public bool TitleVisble
			{
				get
				{
					return (bool)base[tableGeneral.TitleVisbleColumn];
				}
				set
				{
					base[tableGeneral.TitleVisbleColumn] = value;
				}
			}

			public GraphConfigurationRow GraphConfigurationRow
			{
				get
				{
					return (GraphConfigurationRow)GetParentRow(base.Table.ParentRelations["GraphConfiguration_General"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["GraphConfiguration_General"]);
				}
			}

			internal GeneralRow(DataRowBuilder rb)
				: base(rb)
			{
				tableGeneral = (GeneralDataTable)base.Table;
			}
		}

		[DebuggerStepThrough]
		public class GeneralRowChangeEvent : EventArgs
		{
			private GeneralRow eventRow;

			private DataRowAction eventAction;

			public GeneralRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public GeneralRowChangeEvent(GeneralRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class XAxisDataTable : DataTable, IEnumerable
		{
			private DataColumn columnDisplayMode;

			private DataColumn columnStart;

			private DataColumn columnEnd;

			private DataColumn columnCursorColor;

			private DataColumn columnGraphConfiguration_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn DisplayModeColumn => columnDisplayMode;

			internal DataColumn StartColumn => columnStart;

			internal DataColumn EndColumn => columnEnd;

			internal DataColumn CursorColorColumn => columnCursorColor;

			internal DataColumn GraphConfiguration_IdColumn => columnGraphConfiguration_Id;

			public XAxisRow this[int index] => (XAxisRow)base.Rows[index];

			public event XAxisRowChangeEventHandler XAxisRowChanged;

			public event XAxisRowChangeEventHandler XAxisRowChanging;

			public event XAxisRowChangeEventHandler XAxisRowDeleted;

			public event XAxisRowChangeEventHandler XAxisRowDeleting;

			internal XAxisDataTable()
				: base("XAxis")
			{
				InitClass();
			}

			internal XAxisDataTable(DataTable table)
				: base(table.TableName)
			{
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
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddXAxisRow(XAxisRow row)
			{
				base.Rows.Add(row);
			}

			public XAxisRow AddXAxisRow(string DisplayMode, long Start, long End, string CursorColor, GraphConfigurationRow parentGraphConfigurationRowByGraphConfiguration_XAxis)
			{
				XAxisRow xAxisRow = (XAxisRow)NewRow();
				xAxisRow.ItemArray = new object[5]
				{
					DisplayMode,
					Start,
					End,
					CursorColor,
					parentGraphConfigurationRowByGraphConfiguration_XAxis[0]
				};
				base.Rows.Add(xAxisRow);
				return xAxisRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				XAxisDataTable xAxisDataTable = (XAxisDataTable)base.Clone();
				xAxisDataTable.InitVars();
				return xAxisDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new XAxisDataTable();
			}

			internal void InitVars()
			{
				columnDisplayMode = base.Columns["DisplayMode"];
				columnStart = base.Columns["Start"];
				columnEnd = base.Columns["End"];
				columnCursorColor = base.Columns["CursorColor"];
				columnGraphConfiguration_Id = base.Columns["GraphConfiguration_Id"];
			}

			private void InitClass()
			{
				columnDisplayMode = new DataColumn("DisplayMode", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnDisplayMode);
				columnStart = new DataColumn("Start", typeof(long), null, MappingType.Element);
				base.Columns.Add(columnStart);
				columnEnd = new DataColumn("End", typeof(long), null, MappingType.Element);
				base.Columns.Add(columnEnd);
				columnCursorColor = new DataColumn("CursorColor", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnCursorColor);
				columnGraphConfiguration_Id = new DataColumn("GraphConfiguration_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnGraphConfiguration_Id);
				columnDisplayMode.AllowDBNull = false;
				columnDisplayMode.DefaultValue = "StripChart";
				columnStart.AllowDBNull = false;
				columnEnd.AllowDBNull = false;
				columnCursorColor.AllowDBNull = false;
			}

			public XAxisRow NewXAxisRow()
			{
				return (XAxisRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new XAxisRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(XAxisRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.XAxisRowChanged != null)
				{
					this.XAxisRowChanged(this, new XAxisRowChangeEvent((XAxisRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.XAxisRowChanging != null)
				{
					this.XAxisRowChanging(this, new XAxisRowChangeEvent((XAxisRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.XAxisRowDeleted != null)
				{
					this.XAxisRowDeleted(this, new XAxisRowChangeEvent((XAxisRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.XAxisRowDeleting != null)
				{
					this.XAxisRowDeleting(this, new XAxisRowChangeEvent((XAxisRow)e.Row, e.Action));
				}
			}

			public void RemoveXAxisRow(XAxisRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class XAxisRow : DataRow
		{
			private XAxisDataTable tableXAxis;

			public string DisplayMode
			{
				get
				{
					return (string)base[tableXAxis.DisplayModeColumn];
				}
				set
				{
					base[tableXAxis.DisplayModeColumn] = value;
				}
			}

			public long Start
			{
				get
				{
					return (long)base[tableXAxis.StartColumn];
				}
				set
				{
					base[tableXAxis.StartColumn] = value;
				}
			}

			public long End
			{
				get
				{
					return (long)base[tableXAxis.EndColumn];
				}
				set
				{
					base[tableXAxis.EndColumn] = value;
				}
			}

			public string CursorColor
			{
				get
				{
					return (string)base[tableXAxis.CursorColorColumn];
				}
				set
				{
					base[tableXAxis.CursorColorColumn] = value;
				}
			}

			public GraphConfigurationRow GraphConfigurationRow
			{
				get
				{
					return (GraphConfigurationRow)GetParentRow(base.Table.ParentRelations["GraphConfiguration_XAxis"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["GraphConfiguration_XAxis"]);
				}
			}

			internal XAxisRow(DataRowBuilder rb)
				: base(rb)
			{
				tableXAxis = (XAxisDataTable)base.Table;
			}
		}

		[DebuggerStepThrough]
		public class XAxisRowChangeEvent : EventArgs
		{
			private XAxisRow eventRow;

			private DataRowAction eventAction;

			public XAxisRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public XAxisRowChangeEvent(XAxisRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class YAxesDataTable : DataTable, IEnumerable
		{
			private DataColumn columnScaleType;

			private DataColumn columnAutoScale;

			private DataColumn columnAxisPosition;

			private DataColumn columnYAxisDisplayMode;

			private DataColumn columnGraphConfiguration_Id;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn ScaleTypeColumn => columnScaleType;

			internal DataColumn AutoScaleColumn => columnAutoScale;

			internal DataColumn AxisPositionColumn => columnAxisPosition;

			internal DataColumn YAxisDisplayModeColumn => columnYAxisDisplayMode;

			internal DataColumn GraphConfiguration_IdColumn => columnGraphConfiguration_Id;

			public YAxesRow this[int index] => (YAxesRow)base.Rows[index];

			public event YAxesRowChangeEventHandler YAxesRowChanged;

			public event YAxesRowChangeEventHandler YAxesRowChanging;

			public event YAxesRowChangeEventHandler YAxesRowDeleted;

			public event YAxesRowChangeEventHandler YAxesRowDeleting;

			internal YAxesDataTable()
				: base("YAxes")
			{
				InitClass();
			}

			internal YAxesDataTable(DataTable table)
				: base(table.TableName)
			{
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
				base.DisplayExpression = table.DisplayExpression;
			}

			public void AddYAxesRow(YAxesRow row)
			{
				base.Rows.Add(row);
			}

			public YAxesRow AddYAxesRow(string ScaleType, bool AutoScale, string AxisPosition, string YAxisDisplayMode, GraphConfigurationRow parentGraphConfigurationRowByGraphConfiguration_YAxes)
			{
				YAxesRow yAxesRow = (YAxesRow)NewRow();
				yAxesRow.ItemArray = new object[5]
				{
					ScaleType,
					AutoScale,
					AxisPosition,
					YAxisDisplayMode,
					parentGraphConfigurationRowByGraphConfiguration_YAxes[0]
				};
				base.Rows.Add(yAxesRow);
				return yAxesRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				YAxesDataTable yAxesDataTable = (YAxesDataTable)base.Clone();
				yAxesDataTable.InitVars();
				return yAxesDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new YAxesDataTable();
			}

			internal void InitVars()
			{
				columnScaleType = base.Columns["ScaleType"];
				columnAutoScale = base.Columns["AutoScale"];
				columnAxisPosition = base.Columns["AxisPosition"];
				columnYAxisDisplayMode = base.Columns["YAxisDisplayMode"];
				columnGraphConfiguration_Id = base.Columns["GraphConfiguration_Id"];
			}

			private void InitClass()
			{
				columnScaleType = new DataColumn("ScaleType", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnScaleType);
				columnAutoScale = new DataColumn("AutoScale", typeof(bool), null, MappingType.Element);
				base.Columns.Add(columnAutoScale);
				columnAxisPosition = new DataColumn("AxisPosition", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnAxisPosition);
				columnYAxisDisplayMode = new DataColumn("YAxisDisplayMode", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnYAxisDisplayMode);
				columnGraphConfiguration_Id = new DataColumn("GraphConfiguration_Id", typeof(int), null, MappingType.Hidden);
				base.Columns.Add(columnGraphConfiguration_Id);
				columnScaleType.AllowDBNull = false;
				columnScaleType.DefaultValue = "Linear";
				columnAutoScale.AllowDBNull = false;
				columnAutoScale.DefaultValue = false;
				columnAxisPosition.AllowDBNull = false;
				columnAxisPosition.DefaultValue = "Left";
				columnYAxisDisplayMode.AllowDBNull = false;
				columnYAxisDisplayMode.DefaultValue = "Individual";
			}

			public YAxesRow NewYAxesRow()
			{
				return (YAxesRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new YAxesRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(YAxesRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.YAxesRowChanged != null)
				{
					this.YAxesRowChanged(this, new YAxesRowChangeEvent((YAxesRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.YAxesRowChanging != null)
				{
					this.YAxesRowChanging(this, new YAxesRowChangeEvent((YAxesRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.YAxesRowDeleted != null)
				{
					this.YAxesRowDeleted(this, new YAxesRowChangeEvent((YAxesRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.YAxesRowDeleting != null)
				{
					this.YAxesRowDeleting(this, new YAxesRowChangeEvent((YAxesRow)e.Row, e.Action));
				}
			}

			public void RemoveYAxesRow(YAxesRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class YAxesRow : DataRow
		{
			private YAxesDataTable tableYAxes;

			public string ScaleType
			{
				get
				{
					return (string)base[tableYAxes.ScaleTypeColumn];
				}
				set
				{
					base[tableYAxes.ScaleTypeColumn] = value;
				}
			}

			public bool AutoScale
			{
				get
				{
					return (bool)base[tableYAxes.AutoScaleColumn];
				}
				set
				{
					base[tableYAxes.AutoScaleColumn] = value;
				}
			}

			public string AxisPosition
			{
				get
				{
					return (string)base[tableYAxes.AxisPositionColumn];
				}
				set
				{
					base[tableYAxes.AxisPositionColumn] = value;
				}
			}

			public string YAxisDisplayMode
			{
				get
				{
					return (string)base[tableYAxes.YAxisDisplayModeColumn];
				}
				set
				{
					base[tableYAxes.YAxisDisplayModeColumn] = value;
				}
			}

			public GraphConfigurationRow GraphConfigurationRow
			{
				get
				{
					return (GraphConfigurationRow)GetParentRow(base.Table.ParentRelations["GraphConfiguration_YAxes"]);
				}
				set
				{
					SetParentRow(value, base.Table.ParentRelations["GraphConfiguration_YAxes"]);
				}
			}

			internal YAxesRow(DataRowBuilder rb)
				: base(rb)
			{
				tableYAxes = (YAxesDataTable)base.Table;
			}
		}

		[DebuggerStepThrough]
		public class YAxesRowChangeEvent : EventArgs
		{
			private YAxesRow eventRow;

			private DataRowAction eventAction;

			public YAxesRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public YAxesRowChangeEvent(YAxesRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		private MonitorSessionDataTable tableMonitorSession;

		private ScreenDataTable tableScreen;

		private GroupDataTable tableGroup;

		private ParameterDataTable tableParameter;

		private ParameterYAxisDataTable tableParameterYAxis;

		private GaugeConfigurationDataTable tableGaugeConfiguration;

		private GaugeDataTable tableGauge;

		private GraphConfigurationDataTable tableGraphConfiguration;

		private GeneralDataTable tableGeneral;

		private XAxisDataTable tableXAxis;

		private YAxesDataTable tableYAxes;

		private DataRelation relationParameter_ParameterYAxis;

		private DataRelation relationGaugeConfiguration_Gauge;

		private DataRelation relationGraphConfiguration_General;

		private DataRelation relationGraphConfiguration_XAxis;

		private DataRelation relationGraphConfiguration_YAxes;

		private DataRelation relationGroup_Parameter;

		private DataRelation relationGroup_GaugeConfiguration;

		private DataRelation relationGroup_GraphConfiguration;

		private DataRelation relationScreen_Group;

		private DataRelation relationMonitorSession_Screen;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Browsable(false)]
		public MonitorSessionDataTable MonitorSession => tableMonitorSession;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Browsable(false)]
		public ScreenDataTable Screen => tableScreen;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Browsable(false)]
		public GroupDataTable Group => tableGroup;

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ParameterDataTable Parameter => tableParameter;

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ParameterYAxisDataTable ParameterYAxis => tableParameterYAxis;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Browsable(false)]
		public GaugeConfigurationDataTable GaugeConfiguration => tableGaugeConfiguration;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Browsable(false)]
		public GaugeDataTable Gauge => tableGauge;

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public GraphConfigurationDataTable GraphConfiguration => tableGraphConfiguration;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Browsable(false)]
		public GeneralDataTable General => tableGeneral;

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public XAxisDataTable XAxis => tableXAxis;

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public YAxesDataTable YAxes => tableYAxes;

		public NewDataSet()
		{
			InitClass();
			CollectionChangeEventHandler value = SchemaChanged;
			base.Tables.CollectionChanged += value;
			base.Relations.CollectionChanged += value;
		}

		protected NewDataSet(SerializationInfo info, StreamingContext context)
		{
			//IL_0034: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Expected O, but got Unknown
			string text = (string)info.GetValue("XmlSchema", typeof(string));
			if (text != null)
			{
				DataSet dataSet = new DataSet();
				dataSet.ReadXmlSchema((XmlReader?)new XmlTextReader((TextReader)new StringReader(text)));
				if (dataSet.Tables["MonitorSession"] != null)
				{
					base.Tables.Add(new MonitorSessionDataTable(dataSet.Tables["MonitorSession"]));
				}
				if (dataSet.Tables["Screen"] != null)
				{
					base.Tables.Add(new ScreenDataTable(dataSet.Tables["Screen"]));
				}
				if (dataSet.Tables["Group"] != null)
				{
					base.Tables.Add(new GroupDataTable(dataSet.Tables["Group"]));
				}
				if (dataSet.Tables["Parameter"] != null)
				{
					base.Tables.Add(new ParameterDataTable(dataSet.Tables["Parameter"]));
				}
				if (dataSet.Tables["ParameterYAxis"] != null)
				{
					base.Tables.Add(new ParameterYAxisDataTable(dataSet.Tables["ParameterYAxis"]));
				}
				if (dataSet.Tables["GaugeConfiguration"] != null)
				{
					base.Tables.Add(new GaugeConfigurationDataTable(dataSet.Tables["GaugeConfiguration"]));
				}
				if (dataSet.Tables["Gauge"] != null)
				{
					base.Tables.Add(new GaugeDataTable(dataSet.Tables["Gauge"]));
				}
				if (dataSet.Tables["GraphConfiguration"] != null)
				{
					base.Tables.Add(new GraphConfigurationDataTable(dataSet.Tables["GraphConfiguration"]));
				}
				if (dataSet.Tables["General"] != null)
				{
					base.Tables.Add(new GeneralDataTable(dataSet.Tables["General"]));
				}
				if (dataSet.Tables["XAxis"] != null)
				{
					base.Tables.Add(new XAxisDataTable(dataSet.Tables["XAxis"]));
				}
				if (dataSet.Tables["YAxes"] != null)
				{
					base.Tables.Add(new YAxesDataTable(dataSet.Tables["YAxes"]));
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
				InitClass();
			}
			GetSerializationData(info, context);
			CollectionChangeEventHandler value = SchemaChanged;
			base.Tables.CollectionChanged += value;
			base.Relations.CollectionChanged += value;
		}

		public override DataSet Clone()
		{
			NewDataSet newDataSet = (NewDataSet)base.Clone();
			newDataSet.InitVars();
			return newDataSet;
		}

		protected override bool ShouldSerializeTables()
		{
			return false;
		}

		protected override bool ShouldSerializeRelations()
		{
			return false;
		}

		protected override void ReadXmlSerializable(XmlReader reader)
		{
			Reset();
			DataSet dataSet = new DataSet();
			dataSet.ReadXml(reader);
			if (dataSet.Tables["MonitorSession"] != null)
			{
				base.Tables.Add(new MonitorSessionDataTable(dataSet.Tables["MonitorSession"]));
			}
			if (dataSet.Tables["Screen"] != null)
			{
				base.Tables.Add(new ScreenDataTable(dataSet.Tables["Screen"]));
			}
			if (dataSet.Tables["Group"] != null)
			{
				base.Tables.Add(new GroupDataTable(dataSet.Tables["Group"]));
			}
			if (dataSet.Tables["Parameter"] != null)
			{
				base.Tables.Add(new ParameterDataTable(dataSet.Tables["Parameter"]));
			}
			if (dataSet.Tables["ParameterYAxis"] != null)
			{
				base.Tables.Add(new ParameterYAxisDataTable(dataSet.Tables["ParameterYAxis"]));
			}
			if (dataSet.Tables["GaugeConfiguration"] != null)
			{
				base.Tables.Add(new GaugeConfigurationDataTable(dataSet.Tables["GaugeConfiguration"]));
			}
			if (dataSet.Tables["Gauge"] != null)
			{
				base.Tables.Add(new GaugeDataTable(dataSet.Tables["Gauge"]));
			}
			if (dataSet.Tables["GraphConfiguration"] != null)
			{
				base.Tables.Add(new GraphConfigurationDataTable(dataSet.Tables["GraphConfiguration"]));
			}
			if (dataSet.Tables["General"] != null)
			{
				base.Tables.Add(new GeneralDataTable(dataSet.Tables["General"]));
			}
			if (dataSet.Tables["XAxis"] != null)
			{
				base.Tables.Add(new XAxisDataTable(dataSet.Tables["XAxis"]));
			}
			if (dataSet.Tables["YAxes"] != null)
			{
				base.Tables.Add(new YAxesDataTable(dataSet.Tables["YAxes"]));
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

		internal void InitVars()
		{
			tableMonitorSession = (MonitorSessionDataTable)base.Tables["MonitorSession"];
			if (tableMonitorSession != null)
			{
				tableMonitorSession.InitVars();
			}
			tableScreen = (ScreenDataTable)base.Tables["Screen"];
			if (tableScreen != null)
			{
				tableScreen.InitVars();
			}
			tableGroup = (GroupDataTable)base.Tables["Group"];
			if (tableGroup != null)
			{
				tableGroup.InitVars();
			}
			tableParameter = (ParameterDataTable)base.Tables["Parameter"];
			if (tableParameter != null)
			{
				tableParameter.InitVars();
			}
			tableParameterYAxis = (ParameterYAxisDataTable)base.Tables["ParameterYAxis"];
			if (tableParameterYAxis != null)
			{
				tableParameterYAxis.InitVars();
			}
			tableGaugeConfiguration = (GaugeConfigurationDataTable)base.Tables["GaugeConfiguration"];
			if (tableGaugeConfiguration != null)
			{
				tableGaugeConfiguration.InitVars();
			}
			tableGauge = (GaugeDataTable)base.Tables["Gauge"];
			if (tableGauge != null)
			{
				tableGauge.InitVars();
			}
			tableGraphConfiguration = (GraphConfigurationDataTable)base.Tables["GraphConfiguration"];
			if (tableGraphConfiguration != null)
			{
				tableGraphConfiguration.InitVars();
			}
			tableGeneral = (GeneralDataTable)base.Tables["General"];
			if (tableGeneral != null)
			{
				tableGeneral.InitVars();
			}
			tableXAxis = (XAxisDataTable)base.Tables["XAxis"];
			if (tableXAxis != null)
			{
				tableXAxis.InitVars();
			}
			tableYAxes = (YAxesDataTable)base.Tables["YAxes"];
			if (tableYAxes != null)
			{
				tableYAxes.InitVars();
			}
			relationParameter_ParameterYAxis = base.Relations["Parameter_ParameterYAxis"];
			relationGaugeConfiguration_Gauge = base.Relations["GaugeConfiguration_Gauge"];
			relationGraphConfiguration_General = base.Relations["GraphConfiguration_General"];
			relationGraphConfiguration_XAxis = base.Relations["GraphConfiguration_XAxis"];
			relationGraphConfiguration_YAxes = base.Relations["GraphConfiguration_YAxes"];
			relationGroup_Parameter = base.Relations["Group_Parameter"];
			relationGroup_GaugeConfiguration = base.Relations["Group_GaugeConfiguration"];
			relationGroup_GraphConfiguration = base.Relations["Group_GraphConfiguration"];
			relationScreen_Group = base.Relations["Screen_Group"];
			relationMonitorSession_Screen = base.Relations["MonitorSession_Screen"];
		}

		private void InitClass()
		{
			base.DataSetName = "NewDataSet";
			base.Prefix = "";
			base.Namespace = "";
			base.Locale = new CultureInfo("en-US");
			base.CaseSensitive = false;
			base.EnforceConstraints = true;
			tableMonitorSession = new MonitorSessionDataTable();
			base.Tables.Add(tableMonitorSession);
			tableScreen = new ScreenDataTable();
			base.Tables.Add(tableScreen);
			tableGroup = new GroupDataTable();
			base.Tables.Add(tableGroup);
			tableParameter = new ParameterDataTable();
			base.Tables.Add(tableParameter);
			tableParameterYAxis = new ParameterYAxisDataTable();
			base.Tables.Add(tableParameterYAxis);
			tableGaugeConfiguration = new GaugeConfigurationDataTable();
			base.Tables.Add(tableGaugeConfiguration);
			tableGauge = new GaugeDataTable();
			base.Tables.Add(tableGauge);
			tableGraphConfiguration = new GraphConfigurationDataTable();
			base.Tables.Add(tableGraphConfiguration);
			tableGeneral = new GeneralDataTable();
			base.Tables.Add(tableGeneral);
			tableXAxis = new XAxisDataTable();
			base.Tables.Add(tableXAxis);
			tableYAxes = new YAxesDataTable();
			base.Tables.Add(tableYAxes);
			ForeignKeyConstraint foreignKeyConstraint = new ForeignKeyConstraint("MonitorSession_Screen", new DataColumn[1] { tableMonitorSession.MonitorSession_IdColumn }, new DataColumn[1] { tableScreen.MonitorSession_IdColumn });
			tableScreen.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			foreignKeyConstraint = new ForeignKeyConstraint("Screen_Group", new DataColumn[1] { tableScreen.Screen_IdColumn }, new DataColumn[1] { tableGroup.Screen_IdColumn });
			tableGroup.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			foreignKeyConstraint = new ForeignKeyConstraint("Group_Parameter", new DataColumn[1] { tableGroup.Group_IdColumn }, new DataColumn[1] { tableParameter.Group_IdColumn });
			tableParameter.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			foreignKeyConstraint = new ForeignKeyConstraint("Parameter_ParameterYAxis", new DataColumn[1] { tableParameter.Parameter_IdColumn }, new DataColumn[1] { tableParameterYAxis.Parameter_IdColumn });
			tableParameterYAxis.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			foreignKeyConstraint = new ForeignKeyConstraint("Group_GaugeConfiguration", new DataColumn[1] { tableGroup.Group_IdColumn }, new DataColumn[1] { tableGaugeConfiguration.Group_IdColumn });
			tableGaugeConfiguration.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			foreignKeyConstraint = new ForeignKeyConstraint("GaugeConfiguration_Gauge", new DataColumn[1] { tableGaugeConfiguration.GaugeConfiguration_IdColumn }, new DataColumn[1] { tableGauge.GaugeConfiguration_IdColumn });
			tableGauge.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			foreignKeyConstraint = new ForeignKeyConstraint("Group_GraphConfiguration", new DataColumn[1] { tableGroup.Group_IdColumn }, new DataColumn[1] { tableGraphConfiguration.Group_IdColumn });
			tableGraphConfiguration.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			foreignKeyConstraint = new ForeignKeyConstraint("GraphConfiguration_General", new DataColumn[1] { tableGraphConfiguration.GraphConfiguration_IdColumn }, new DataColumn[1] { tableGeneral.GraphConfiguration_IdColumn });
			tableGeneral.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			foreignKeyConstraint = new ForeignKeyConstraint("GraphConfiguration_XAxis", new DataColumn[1] { tableGraphConfiguration.GraphConfiguration_IdColumn }, new DataColumn[1] { tableXAxis.GraphConfiguration_IdColumn });
			tableXAxis.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			foreignKeyConstraint = new ForeignKeyConstraint("GraphConfiguration_YAxes", new DataColumn[1] { tableGraphConfiguration.GraphConfiguration_IdColumn }, new DataColumn[1] { tableYAxes.GraphConfiguration_IdColumn });
			tableYAxes.Constraints.Add(foreignKeyConstraint);
			foreignKeyConstraint.AcceptRejectRule = AcceptRejectRule.None;
			foreignKeyConstraint.DeleteRule = Rule.Cascade;
			foreignKeyConstraint.UpdateRule = Rule.Cascade;
			relationParameter_ParameterYAxis = new DataRelation("Parameter_ParameterYAxis", new DataColumn[1] { tableParameter.Parameter_IdColumn }, new DataColumn[1] { tableParameterYAxis.Parameter_IdColumn }, createConstraints: false);
			relationParameter_ParameterYAxis.Nested = true;
			base.Relations.Add(relationParameter_ParameterYAxis);
			relationGaugeConfiguration_Gauge = new DataRelation("GaugeConfiguration_Gauge", new DataColumn[1] { tableGaugeConfiguration.GaugeConfiguration_IdColumn }, new DataColumn[1] { tableGauge.GaugeConfiguration_IdColumn }, createConstraints: false);
			relationGaugeConfiguration_Gauge.Nested = true;
			base.Relations.Add(relationGaugeConfiguration_Gauge);
			relationGraphConfiguration_General = new DataRelation("GraphConfiguration_General", new DataColumn[1] { tableGraphConfiguration.GraphConfiguration_IdColumn }, new DataColumn[1] { tableGeneral.GraphConfiguration_IdColumn }, createConstraints: false);
			relationGraphConfiguration_General.Nested = true;
			base.Relations.Add(relationGraphConfiguration_General);
			relationGraphConfiguration_XAxis = new DataRelation("GraphConfiguration_XAxis", new DataColumn[1] { tableGraphConfiguration.GraphConfiguration_IdColumn }, new DataColumn[1] { tableXAxis.GraphConfiguration_IdColumn }, createConstraints: false);
			relationGraphConfiguration_XAxis.Nested = true;
			base.Relations.Add(relationGraphConfiguration_XAxis);
			relationGraphConfiguration_YAxes = new DataRelation("GraphConfiguration_YAxes", new DataColumn[1] { tableGraphConfiguration.GraphConfiguration_IdColumn }, new DataColumn[1] { tableYAxes.GraphConfiguration_IdColumn }, createConstraints: false);
			relationGraphConfiguration_YAxes.Nested = true;
			base.Relations.Add(relationGraphConfiguration_YAxes);
			relationGroup_Parameter = new DataRelation("Group_Parameter", new DataColumn[1] { tableGroup.Group_IdColumn }, new DataColumn[1] { tableParameter.Group_IdColumn }, createConstraints: false);
			relationGroup_Parameter.Nested = true;
			base.Relations.Add(relationGroup_Parameter);
			relationGroup_GaugeConfiguration = new DataRelation("Group_GaugeConfiguration", new DataColumn[1] { tableGroup.Group_IdColumn }, new DataColumn[1] { tableGaugeConfiguration.Group_IdColumn }, createConstraints: false);
			relationGroup_GaugeConfiguration.Nested = true;
			base.Relations.Add(relationGroup_GaugeConfiguration);
			relationGroup_GraphConfiguration = new DataRelation("Group_GraphConfiguration", new DataColumn[1] { tableGroup.Group_IdColumn }, new DataColumn[1] { tableGraphConfiguration.Group_IdColumn }, createConstraints: false);
			relationGroup_GraphConfiguration.Nested = true;
			base.Relations.Add(relationGroup_GraphConfiguration);
			relationScreen_Group = new DataRelation("Screen_Group", new DataColumn[1] { tableScreen.Screen_IdColumn }, new DataColumn[1] { tableGroup.Screen_IdColumn }, createConstraints: false);
			relationScreen_Group.Nested = true;
			base.Relations.Add(relationScreen_Group);
			relationMonitorSession_Screen = new DataRelation("MonitorSession_Screen", new DataColumn[1] { tableMonitorSession.MonitorSession_IdColumn }, new DataColumn[1] { tableScreen.MonitorSession_IdColumn }, createConstraints: false);
			relationMonitorSession_Screen.Nested = true;
			base.Relations.Add(relationMonitorSession_Screen);
		}

		private bool ShouldSerializeMonitorSession()
		{
			return false;
		}

		private bool ShouldSerializeScreen()
		{
			return false;
		}

		private bool ShouldSerializeGroup()
		{
			return false;
		}

		private bool ShouldSerializeParameter()
		{
			return false;
		}

		private bool ShouldSerializeParameterYAxis()
		{
			return false;
		}

		private bool ShouldSerializeGaugeConfiguration()
		{
			return false;
		}

		private bool ShouldSerializeGauge()
		{
			return false;
		}

		private bool ShouldSerializeGraphConfiguration()
		{
			return false;
		}

		private bool ShouldSerializeGeneral()
		{
			return false;
		}

		private bool ShouldSerializeXAxis()
		{
			return false;
		}

		private bool ShouldSerializeYAxes()
		{
			return false;
		}

		private void SchemaChanged(object sender, CollectionChangeEventArgs e)
		{
			if (e.Action == CollectionChangeAction.Remove)
			{
				InitVars();
			}
		}
	}
}
namespace Cummins.CUTY
{
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	[Guid("C3D8FB17-2918-40ac-B855-FCDFD63BFEDE")]
	public interface ICICommands3
	{
		[DispId(1)]
		string GetParameterUnits(string parameterNames);
	}
	[ComVisible(false)]
	internal class Commands3 : ICICommands3
	{
		private ITransport transport;

		private IService service;

		public Commands3(ITransport transport, IService service)
		{
			this.transport = transport;
			this.service = service;
		}

		public string GetParameterUnits(string parameterNames)
		{
			string text = "";
			return service.ExecuteGetParameterUnits(parameterNames);
		}
	}
	[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
	[Guid("7017119A-92F8-46ac-9A77-4970C24AE750")]
	public interface ICIMonitorElement
	{
		[DispId(301)]
		string Name { get; }

		[DispId(302)]
		string Value { get; }

		[DispId(303)]
		string Units { get; }
	}
	[Guid("259C25D1-C9E2-46f8-B832-9F0534739C8B")]
	[ClassInterface(ClassInterfaceType.AutoDispatch)]
	[ProgId("Cummins.CUTYMonitorElement")]
	public class MonitorElement : ICIMonitorElement
	{
		private string elementName;

		private string elementValue;

		private string units;

		public string Name => elementName;

		public string Value => elementValue;

		public string Units => units;

		public MonitorElement(string elementName, string elementValue, string units)
		{
			if (elementName == null || elementValue == null || units == null || elementName == "")
			{
				throw new ArgumentNullException("monitoredElement");
			}
			this.elementName = elementName;
			this.elementValue = elementValue;
			this.units = units;
			this.units = this.units.Replace("\0", "");
			this.units = this.units.Replace("\n", "");
			this.units = this.units.Replace("\t", "");
		}
	}
	[Guid("D89D7C7A-2E92-4df5-96DF-AAA88628842B")]
	[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
	public interface ICINotification
	{
		[DispId(201)]
		int Count { get; }

		[DispId(202)]
		ICIMonitorElement GetElement(int index);
	}
	[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
	[Guid("0C88801C-6564-4d44-AAB8-7FFE468E398F")]
	public interface ICINotification2 : ICINotification
	{
		[DispId(203)]
		string TimeStamp { get; set; }
	}
	[Guid("B0749948-9B59-4d37-AA8C-DE39929F6613")]
	[ProgId("Cummins.CUTYMonitorNotification")]
	[ClassInterface(ClassInterfaceType.AutoDispatch)]
	public class MonitorElements : ICINotification2, ICINotification
	{
		private int count;

		private ICIMonitorElement[] monitorElements;

		private string timeStamp;

		public ICIMonitorElement this[int index]
		{
			get
			{
				return GetElement(index);
			}
			set
			{
				monitorElements[index] = value;
			}
		}

		public int Count => count;

		public string TimeStamp
		{
			get
			{
				return timeStamp;
			}
			set
			{
				timeStamp = value;
			}
		}

		public MonitorElements(int count)
		{
			monitorElements = new MonitorElement[count];
			this.count = count;
		}

		public ICIMonitorElement GetElement(int index)
		{
			return monitorElements[index];
		}
	}
	[Guid("6C99C567-A40F-4f5b-BFDD-82F67869F304")]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	public interface ICICommands
	{
		[DispId(29)]
		object[] GetFaults(FaultsType faultsType);

		[DispId(30)]
		void ClearFaults(FaultsType faultsType);

		[DispId(34)]
		void RequestChangeLock();

		[DispId(35)]
		void ReleaseChangeLock();

		[DispId(36)]
		void HoldChanges();

		[DispId(37)]
		void CancelChanges();

		[DispId(39)]
		void SaveChanges();

		[DispId(40)]
		void StopBroadCast();

		[DispId(41)]
		void StartBroadCast();

		[DispId(42)]
		void RunFromDevelopment();

		[DispId(43)]
		void RunFromDefault();

		[DispId(44)]
		void RunFromBoot();

		[DispId(42)]
		void GetChangeLockOwner();

		[DispId(50)]
		string SendOperation(string operationName, string inputArguments, out string outputArguments);
	}
	[ComVisible(false)]
	internal class Commands : ICICommands
	{
		private const char Space = ' ';

		private const char Colon = ':';

		private const string InActive = "INACTIVE";

		private const string FaultsCommand = "FAULTS";

		private const string ReadFaults = "ReadFaults";

		private const string Active = "ACTIVE";

		private const string PrevActive = "PREV_ACTIVE";

		private const string All = "ALL";

		private const string EraseECMFaults = "EraseFaults";

		private ITransport transport;

		private IService service;

		public Commands(ITransport transport, IService service)
		{
			this.transport = transport;
			this.service = service;
		}

		public object[] GetFaults(FaultsType faultsType)
		{
			string[] array = null;
			string[] array2 = null;
			string[] array3 = null;
			StringCollection stringCollection = new StringCollection();
			service.CurrentMonitorMode = MonitorMode.MonitorModeRequestReceive;
			service.ExecuteCommand("ReadFaults", service.LUN.ToString());
			string returnFromExecuteCmd = service.ReturnFromExecuteCmd;
			array3 = returnFromExecuteCmd.Split(new char[1] { ':' });
			int num = 0;
			num = array3.GetLength(0);
			if (num >= 1)
			{
				array = array3[1].Split(new char[1] { ' ' });
			}
			if (num >= 2)
			{
				array2 = array3[2].Split(new char[1] { ' ' });
			}
			switch (faultsType)
			{
			case FaultsType.Active:
			{
				string[] array6 = array;
				foreach (string text3 in array6)
				{
					if (-1 == text3.IndexOf("INACTIVE") && string.Empty != text3 && -1 == text3.IndexOf("FAULTS"))
					{
						stringCollection.Add(text3);
					}
				}
				break;
			}
			case FaultsType.InActive:
			{
				string[] array7 = array2;
				foreach (string text4 in array7)
				{
					if (string.Empty != text4 && -1 == text4.IndexOf("FAULTS"))
					{
						stringCollection.Add(text4);
					}
				}
				break;
			}
			default:
			{
				string[] array4 = array;
				foreach (string text in array4)
				{
					if (-1 == text.IndexOf("INACTIVE") && string.Empty != text && -1 == text.IndexOf("FAULTS"))
					{
						stringCollection.Add(text);
					}
				}
				string[] array5 = array2;
				foreach (string text2 in array5)
				{
					if (string.Empty != text2 && -1 == text2.IndexOf("FAULTS"))
					{
						stringCollection.Add(text2);
					}
				}
				break;
			}
			}
			object[] array8 = null;
			int num2 = 0;
			if (stringCollection.Count > 0)
			{
				array8 = new object[stringCollection.Count];
				StringEnumerator enumerator = stringCollection.GetEnumerator();
				try
				{
					while (enumerator.MoveNext())
					{
						string current = enumerator.Current;
						array8[num2++] = current;
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
			else
			{
				array8 = new object[1] { "" };
			}
			return array8;
		}

		public void ClearFaults(FaultsType faultsType)
		{
			switch (faultsType)
			{
			case FaultsType.Active:
			{
				string arguments = "ACTIVE " + service.LUN;
				service.ExecuteCommand("EraseFaults", arguments);
				break;
			}
			case FaultsType.InActive:
			{
				string arguments = "PREV_ACTIVE " + service.LUN;
				service.ExecuteCommand("EraseFaults", arguments);
				break;
			}
			default:
			{
				string arguments = "ALL " + service.LUN;
				service.ExecuteCommand("EraseFaults", arguments);
				break;
			}
			}
		}

		public void RequestChangeLock()
		{
			service.ExecuteCommand("RequestChangeLock", service.LUN.ToString());
		}

		public void ReleaseChangeLock()
		{
			service.ExecuteCommand("ReleaseChangeLock", service.LUN.ToString());
		}

		public void HoldChanges()
		{
			service.ExecuteCommand("HoldChanges", service.LUN.ToString());
		}

		public void CancelChanges()
		{
			service.ExecuteCommand("CancelChanges", service.LUN.ToString());
		}

		public void SaveChanges()
		{
			service.ExecuteCommand("SaveChanges", service.LUN.ToString());
		}

		public void StopBroadCast()
		{
			service.ExecuteCommand("StopBcast", service.LUN.ToString());
		}

		public void StartBroadCast()
		{
			service.ExecuteCommand("StartBcast", service.LUN.ToString());
		}

		public void RunFromDevelopment()
		{
			service.ExecuteCommand("RunFromDev", service.LUN.ToString());
		}

		public void RunFromDefault()
		{
			service.ExecuteCommand("RunFromDef", service.LUN.ToString());
		}

		public void RunFromBoot()
		{
			service.ExecuteCommand("RunFromBoot", service.LUN.ToString());
		}

		public void GetChangeLockOwner()
		{
			service.ExecuteCommand("GetChangeLockOwner", service.LUN.ToString());
		}

		private string ExecuteGetSetAddress(string operation, string address, long length, string newValue)
		{
			return service.ExecuteGetSetAddress(operation, address, length, newValue);
		}

		public string SendOperation(string operationName, string inputArguments, out string outputArguments)
		{
			string text = "";
			char[] array = new char[1] { ' ' };
			string[] array2 = new string[0];
			string[] inputs = inputArguments.Split(new char[1] { array[0] });
			string text2 = "";
			string lUN = service.LUN.ToString();
			service.ExecuteSendOperation(lUN, operationName, inputs, out var outputs);
			string[] array3;
			if (outputs != null)
			{
				switch (outputs.Length)
				{
				case 0:
					text = "";
					array3 = array2;
					break;
				case 1:
					text = outputs[0];
					array3 = array2;
					break;
				default:
				{
					text = outputs[0];
					array3 = new string[outputs.Length - 1];
					for (int i = 0; i < outputs.Length - 1; i++)
					{
						array3[i] = outputs[i + 1];
					}
					break;
				}
				}
			}
			else
			{
				text = "";
				array3 = array2;
			}
			for (int j = 0; j < array3.Length; j++)
			{
				text2 = ((j != 0) ? (text2 + array[0] + array3[j]) : array3[j]);
			}
			outputArguments = text2;
			return text;
		}
	}
	public class SetParameterCommand : ASAMCommand
	{
		protected string parameterName;

		protected ITransport transport;

		protected ushort lun;

		protected double parValue;

		public ushort LUN
		{
			get
			{
				return lun;
			}
			set
			{
				lun = value;
			}
		}

		public double ParValue
		{
			get
			{
				return parValue;
			}
			set
			{
				parValue = value;
			}
		}

		public string ParameterName
		{
			get
			{
				return parameterName;
			}
			set
			{
				parameterName = value;
			}
		}

		public SetParameterCommand(ITransport transport)
		{
			this.transport = transport;
			LUN = 0;
			parameterName = "";
		}

		public override void Execute()
		{
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(15);
			ausyTelegram.putWord(LUN);
			ausyTelegram.putString(parameterName);
			ausyTelegram.putFloat((float)parValue);
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			MCTelegram telegram = new MCTelegram(rawData);
			validateResponse(telegram);
		}
	}
	public class ExtSetParameterCommand : SetParameterCommand
	{
		protected string strParValue;

		public string StringParValue
		{
			get
			{
				return strParValue;
			}
			set
			{
				strParValue = value;
			}
		}

		public ExtSetParameterCommand(ITransport transport)
			: base(transport)
		{
		}

		public override void Execute()
		{
			ExtGetParameterCommand extGetParameterCommand = new ExtGetParameterCommand(transport);
			extGetParameterCommand.ParameterName = parameterName;
			extGetParameterCommand.LUN = lun;
			extGetParameterCommand.Execute();
			ASAMDataType aSAMDataType = extGetParameterCommand.DataType;
			if (aSAMDataType == ASAMDataType.Real && double.Parse(StringParValue) > 65535.0)
			{
				aSAMDataType = ASAMDataType.Real8;
			}
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(115);
			ausyTelegram.putWord(base.LUN);
			ausyTelegram.putString(parameterName);
			switch (aSAMDataType)
			{
			case ASAMDataType.Real:
				ausyTelegram.putWord(0);
				ausyTelegram.putFloat(float.Parse(StringParValue));
				break;
			case ASAMDataType.Real8:
				ausyTelegram.putWord(1);
				ausyTelegram.putDouble(double.Parse(StringParValue));
				break;
			default:
				ausyTelegram.putWord(2);
				ausyTelegram.putString(strParValue);
				break;
			}
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			MCTelegram telegram = new MCTelegram(rawData);
			validateResponse(telegram);
		}
	}
	public class ExitCommand : ASAMCommand
	{
		private ITransport transport;

		public ExitCommand(ITransport transport)
		{
			if (transport == null)
			{
				throw new ArgumentNullException("transport carrier");
			}
			this.transport = transport;
		}

		public override void Execute()
		{
			CommunicationLog instanceOf = CommunicationLog.InstanceOf;
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(50);
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			MCTelegram telegram = new MCTelegram(rawData);
			validateResponse(telegram);
			instanceOf.AddStringToLog(ElementType.file, "ExitCommand.CS");
			instanceOf.WriteToLogFile();
		}
	}
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	[Guid("14EEB212-F1D4-49cf-845B-E88B8065C527")]
	public interface ICICommands2
	{
		[DispId(1)]
		string GetAddressByParameterName(string parameterName);
	}
	[ComVisible(false)]
	internal class Commands2 : ICICommands2
	{
		private ITransport transport;

		private IService service;

		public Commands2(ITransport transport, IService service)
		{
			this.transport = transport;
			this.service = service;
		}

		public string GetAddressByParameterName(string parameterName)
		{
			string text = "";
			return service.ExecuteGetAddressByParameterName(parameterName);
		}
	}
	public class GetOnlineValueCommand : ASAMCommand
	{
		protected ushort commandCode;

		private ITransport transport;

		private MCTelegram mcTelegram;

		public MCTelegram Notification => mcTelegram;

		public GetOnlineValueCommand(ITransport transport)
		{
			commandCode = 19;
			this.transport = transport;
		}

		public override void Execute()
		{
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(commandCode);
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			mcTelegram = new MCTelegram(rawData);
		}
	}
	public class ExtendedGetOnlineValueCommand : GetOnlineValueCommand
	{
		public ExtendedGetOnlineValueCommand(ITransport transport)
			: base(transport)
		{
			commandCode = 119;
		}
	}
	public class SendOperation : ExecuteCommand
	{
		public SendOperation(ITransport transport)
			: base(transport)
		{
		}

		public override void Execute()
		{
			CommunicationLog instanceOf = CommunicationLog.InstanceOf;
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(202);
			ausyTelegram.putString("SendOperation");
			string empty = string.Empty;
			empty = base.Command + " " + base.Arguments;
			ausyTelegram.putString(empty);
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			MCTelegram mCTelegram = new MCTelegram(rawData);
			validateResponse(mCTelegram);
			responseString = mCTelegram.getString();
			instanceOf.AddStringToLog(ElementType.file, "SendOperation.CS");
			instanceOf.WriteToLogFile();
		}
	}
	public class DefineDescriptionAndBinaryFileCommand : ASAMCommand
	{
		private ITransport transport;

		private ushort target;

		private ushort source;

		private ushort lun;

		public ushort Target
		{
			get
			{
				return target;
			}
			set
			{
				target = value;
			}
		}

		public ushort Source
		{
			get
			{
				return source;
			}
			set
			{
				source = value;
			}
		}

		public ushort LUN
		{
			get
			{
				return lun;
			}
			set
			{
				lun = value;
			}
		}

		public DefineDescriptionAndBinaryFileCommand(ITransport transport)
		{
			this.transport = transport;
			source = source;
			lun = lun;
			target = target;
			LUN = 0;
			if (transport == null)
			{
				throw new ArgumentNullException("transport carrier");
			}
		}

		public override void Execute()
		{
			CommunicationLog instanceOf = CommunicationLog.InstanceOf;
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(4);
			ausyTelegram.putWord(Target);
			ausyTelegram.putWord(Source);
			ausyTelegram.putWord(LUN);
			transport.Send(ausyTelegram.RawData);
			byte[] rawData = transport.Receive();
			new MCTelegram(rawData);
			instanceOf.AddStringToLog(ElementType.file, "DefineDescriptionAndBinaryFileCommand.CS");
			instanceOf.WriteToLogFile();
		}
	}
	[Guid("5CF5F04C-E3A4-4f41-A254-77B0F7EDC63F")]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	public interface ICIRemoteLogger
	{
		[DispId(20)]
		int LoggingRefreshRate { get; set; }

		[DispId(21)]
		string StartCondition { get; set; }

		[DispId(22)]
		string StopCondition { get; set; }

		[DispId(27)]
		bool IsLogging { get; }

		[DispId(23)]
		void AddLoggingElement(string element);

		[DispId(24)]
		void RemoveLoggingElement(string element);

		[DispId(25)]
		void StartLogger(LoggingMode mode);

		[DispId(26)]
		void StopLogger();

		[DispId(28)]
		void SaveLog(string logFileName, LogFileLocation logFileLocation);
	}
	[ComVisible(false)]
	internal class RemoteLogger : ICIRemoteLogger
	{
		public int LoggingRefreshRate
		{
			get
			{
				return LoggingRefreshRate;
			}
			set
			{
				LoggingRefreshRate = value;
			}
		}

		public string StartCondition
		{
			get
			{
				return StartCondition;
			}
			set
			{
				StartCondition = value;
			}
		}

		public string StopCondition
		{
			get
			{
				return StopCondition;
			}
			set
			{
				StopCondition = value;
			}
		}

		public bool IsLogging => IsLogging;

		public void AddLoggingElement(string element)
		{
		}

		public void RemoveLoggingElement(string element)
		{
		}

		public void StartLogger(LoggingMode mode)
		{
		}

		public void StopLogger()
		{
		}

		public void SaveLog(string logFileName, LogFileLocation logFileLocation)
		{
		}
	}
	internal enum ASAMDataType
	{
		Real,
		Real8,
		String
	}
	internal class Parameter
	{
		private string name;

		private ASAMDataType type;

		public string Name => name;

		public ASAMDataType DataType
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

		public Parameter(string name)
		{
			this.name = name;
			type = ASAMDataType.Real;
		}
	}
	public enum ServiceState
	{
		Initialized,
		Terminated
	}
	public class ASAMService : IService
	{
		internal class ASAMBaseImpl
		{
			protected ASAMService parent;

			public ASAMBaseImpl(ASAMService parent)
			{
				this.parent = parent;
			}

			public virtual void StartMonitoring()
			{
				ParameterForValueAcquisitionCommand parameterForValueAcquisitionCommand = (ParameterForValueAcquisitionCommand)parent.cmdExecutor.Create(CommandType.ParameterForValueAcquisition);
				parameterForValueAcquisitionCommand.LUN = parent.LUN;
				parameterForValueAcquisitionCommand.RefreshRate = (ushort)parent.scanningRate;
				parameterForValueAcquisitionCommand.Parameters = new ArrayList();
				parameterForValueAcquisitionCommand.Execute();
				parameterForValueAcquisitionCommand = (ParameterForValueAcquisitionCommand)parent.cmdExecutor.Create(CommandType.ParameterForValueAcquisition);
				parameterForValueAcquisitionCommand.LUN = parent.LUN;
				parameterForValueAcquisitionCommand.RefreshRate = (ushort)parent.scanningRate;
				parameterForValueAcquisitionCommand.Parameters = parent.monitorElements;
				parameterForValueAcquisitionCommand.Execute();
				SwitchingOnlineOfflineCommand switchingOnlineOfflineCommand = (SwitchingOnlineOfflineCommand)parent.cmdExecutor.Create(CommandType.SwitchingOnlineOffline);
				switchingOnlineOfflineCommand.Mode = 1;
				switchingOnlineOfflineCommand.Execute();
			}

			public virtual ASAMCommand MonitorDataFetcher()
			{
				return parent.cmdExecutor.Create(CommandType.GetOnlineValue);
			}

			public virtual MonitorElements ParseMonitorData(MCTelegram telegram)
			{
				ushort word = telegram.getWord();
				MonitorElements monitorElements = new MonitorElements(word);
				for (int i = 0; i < word; i++)
				{
					string elementValue = telegram.getFloat().ToString("R");
					Parameter parameter = (Parameter)parent.monitorElements[i];
					monitorElements[i] = new MonitorElement(parameter.Name, elementValue, "None");
				}
				return monitorElements;
			}

			public virtual double GetScaledFloat(string elementName)
			{
				GetParameterCommand getParameterCommand = (GetParameterCommand)parent.cmdExecutor.Create(CommandType.GetParameter);
				getParameterCommand.LUN = parent.LUN;
				getParameterCommand.ParameterName = elementName;
				getParameterCommand.Execute();
				return getParameterCommand.ParValue;
			}

			public virtual void SetScaledFloat(string elementName, double value)
			{
				SetParameterCommand setParameterCommand = (SetParameterCommand)parent.cmdExecutor.Create(CommandType.SetParameter);
				setParameterCommand.LUN = parent.LUN;
				setParameterCommand.ParameterName = elementName;
				setParameterCommand.ParValue = value;
				setParameterCommand.Execute();
			}

			public virtual string GetString(string elementName)
			{
				ExtGetParameterCommand extGetParameterCommand = (ExtGetParameterCommand)parent.cmdExecutor.Create(CommandType.ExtendedGetParameter);
				extGetParameterCommand.LUN = parent.LUN;
				extGetParameterCommand.ParameterName = elementName;
				extGetParameterCommand.Execute();
				return extGetParameterCommand.StringValue;
			}

			public virtual bool SetString(string elementName, string newValue)
			{
				ExtSetParameterCommand extSetParameterCommand = (ExtSetParameterCommand)parent.cmdExecutor.Create(CommandType.ExtendedSetParameter);
				extSetParameterCommand.LUN = parent.LUN;
				extSetParameterCommand.ParameterName = elementName;
				extSetParameterCommand.StringParValue = newValue;
				extSetParameterCommand.Execute();
				return true;
			}

			public bool _Download()
			{
				CopyBinaryFileCommand copyBinaryFileCommand = (CopyBinaryFileCommand)parent.cmdExecutor.Create(CommandType.CopyBinaryFile);
				copyBinaryFileCommand.Target = 1;
				copyBinaryFileCommand.Source = 2;
				copyBinaryFileCommand.LUN = parent.LUN;
				copyBinaryFileCommand.Execute();
				return true;
			}

			public bool _Upload()
			{
				CopyBinaryFileCommand copyBinaryFileCommand = (CopyBinaryFileCommand)parent.cmdExecutor.Create(CommandType.CopyBinaryFile);
				copyBinaryFileCommand.Target = 2;
				copyBinaryFileCommand.Source = 1;
				copyBinaryFileCommand.LUN = parent.LUN;
				copyBinaryFileCommand.Execute();
				return true;
			}

			public bool _ChangeBinaryFileName(string binaryFileName)
			{
				ChangeBinaryFileNameCommand changeBinaryFileNameCommand = (ChangeBinaryFileNameCommand)parent.cmdExecutor.Create(CommandType.ChangeBinaryFileName);
				changeBinaryFileNameCommand.BinaryFileName = binaryFileName;
				changeBinaryFileNameCommand.LUN = parent.LUN;
				changeBinaryFileNameCommand.Execute();
				return true;
			}
		}

		internal class ASAMExtendedImpl : ASAMBaseImpl
		{
			public ASAMExtendedImpl(ASAMService parent)
				: base(parent)
			{
			}

			public override void StartMonitoring()
			{
				ExtParamForValueAcqCommand extParamForValueAcqCommand = (ExtParamForValueAcqCommand)parent.cmdExecutor.Create(CommandType.ExtendedParameterForValueAcquisition);
				extParamForValueAcqCommand.LUN = parent.LUN;
				extParamForValueAcqCommand.RefreshRate = (ushort)parent.scanningRate;
				if (parent.newlyAddedMonitorElements.Count > 0)
				{
					extParamForValueAcqCommand.Parameters = parent.newlyAddedMonitorElements;
					extParamForValueAcqCommand.Execute();
					parent.newlyAddedMonitorElements.Clear();
				}
			}

			public override ASAMCommand MonitorDataFetcher()
			{
				return parent.cmdExecutor.Create(CommandType.ExtendedGetOnlineValue);
			}

			public override MonitorElements ParseMonitorData(MCTelegram telegram)
			{
				ushort word = telegram.getWord();
				MonitorElements monitorElements = new MonitorElements(word);
				for (int i = 0; i < word; i++)
				{
					Parameter parameter = (Parameter)parent.monitorElements[i];
					string text = "";
					monitorElements[i] = new MonitorElement(elementValue: (parameter.DataType != ASAMDataType.Real8) ? ((parameter.DataType != ASAMDataType.String) ? telegram.getFloat().ToString("R") : telegram.getString()) : telegram.getDouble().ToString("R"), elementName: parameter.Name, units: "None");
				}
				return monitorElements;
			}

			public override double GetScaledFloat(string elementName)
			{
				ExtGetParameterCommand extGetParameterCommand = (ExtGetParameterCommand)parent.cmdExecutor.Create(CommandType.ExtendedGetParameter);
				extGetParameterCommand.LUN = parent.LUN;
				extGetParameterCommand.ParameterName = elementName;
				extGetParameterCommand.Execute();
				return extGetParameterCommand.ParValue;
			}

			public override void SetScaledFloat(string elementName, double value)
			{
				ExtSetParameterCommand extSetParameterCommand = (ExtSetParameterCommand)parent.cmdExecutor.Create(CommandType.ExtendedSetParameter);
				extSetParameterCommand.LUN = parent.LUN;
				extSetParameterCommand.ParameterName = elementName;
				extSetParameterCommand.ParValue = value;
				extSetParameterCommand.Execute();
			}

			public override string GetString(string elementName)
			{
				ExtGetParameterCommand extGetParameterCommand = (ExtGetParameterCommand)parent.cmdExecutor.Create(CommandType.ExtendedGetParameter);
				extGetParameterCommand.LUN = parent.LUN;
				extGetParameterCommand.ParameterName = elementName;
				extGetParameterCommand.Execute();
				return extGetParameterCommand.StringValue;
			}
		}

		private const string CutyDataStart = "DATA: ";

		private const string CutyDataStartWithTimeStamp = "TIME: ";

		private const string CutyDataEnd = "\n\0";

		private const int BufferCapacity = 262144;

		private const string CutyServerName = "cuty";

		private const char Space = ' ';

		private const char Comma = ',';

		private ITransport transport;

		private ASAMCommandFactory cmdExecutor;

		private ASAMBaseImpl asamImpl;

		private ushort lun = 255;

		private string returnFromExecuteCmd;

		private string serverIdentity = "Any ASAM3 Server";

		private ServiceState serviceState;

		private int serverProtocolVersion;

		private StringCollection extendedServices;

		private int streamingUDPPort;

		private ArrayList monitorElements = new ArrayList();

		private ArrayList newlyAddedMonitorElements = new ArrayList();

		private MonitorState monitorState = MonitorState.Stopped;

		private int scanningRate;

		private Thread notificationFetcher;

		private ManualResetEvent fetchSignal = new ManualResetEvent(initialState: false);

		private ManualResetEvent arrivedSignal = new ManualResetEvent(initialState: false);

		private bool keepAlive = true;

		private bool keepFetching;

		private bool monitorStatusWhenMonitoring;

		private MonitorDataRefreshDelegate monitorDataRefreshEvent;

		private bool extendedServicesSupportAvailable;

		private MonitorMode currentMonitorMode;

		private bool isStartMonitor2;

		private int udpPort;

		public MonitorDataRefreshDelegate MonitorDataRefreshEvent
		{
			get
			{
				return monitorDataRefreshEvent;
			}
			set
			{
				monitorDataRefreshEvent = value;
			}
		}

		private bool ExtendedServicesSupportAvailable
		{
			get
			{
				return extendedServicesSupportAvailable;
			}
			set
			{
				extendedServicesSupportAvailable = value;
			}
		}

		public ushort LUN => lun;

		public string ReturnFromExecuteCmd => returnFromExecuteCmd;

		public MonitorMode CurrentMonitorMode
		{
			get
			{
				return currentMonitorMode;
			}
			set
			{
				currentMonitorMode = value;
			}
		}

		public int DEFAULT_UDP_PORT => -1;

		public bool IsStartMonitor2
		{
			get
			{
				return isStartMonitor2;
			}
			set
			{
				isStartMonitor2 = value;
			}
		}

		public int UDPPort
		{
			get
			{
				return udpPort;
			}
			set
			{
				udpPort = value;
			}
		}

		public int MonitorRefreshRate
		{
			get
			{
				return scanningRate;
			}
			set
			{
				if (value > 0 && scanningRate != value)
				{
					scanningRate = value;
				}
			}
		}

		public bool MonitorStatusWhenMonitoring
		{
			get
			{
				return monitorStatusWhenMonitoring;
			}
			set
			{
				monitorStatusWhenMonitoring = value;
			}
		}

		public MonitorState MonitorState
		{
			get
			{
				return monitorState;
			}
			set
			{
				if (monitorState == value)
				{
					return;
				}
				switch (value)
				{
				case MonitorState.Monitoring:
				{
					if (UDPPort == DEFAULT_UDP_PORT)
					{
						InitializeMonitor();
						break;
					}
					Timer timer = new Timer(OnTimerElapsed, null, -1, MonitorRefreshRate);
					timer.Change(5000, 5000);
					MonitorStatusWhenMonitoring = true;
					IsStartMonitor2 = true;
					streamingUDPPort = UDPPort;
					StartMonitoring(currentMonitorMode);
					break;
				}
				case MonitorState.Stopped:
					if (IsStartMonitor2)
					{
						IsStartMonitor2 = false;
					}
					StopMonitoring();
					break;
				}
			}
		}

		public string ServerIdentity => serverIdentity;

		public ASAMService(ITransport transport)
		{
			this.transport = transport;
			cmdExecutor = new ASAMCommandFactory(transport);
			serviceState = ServiceState.Terminated;
		}

		public void Initialize()
		{
			InitCommand initCommand = (InitCommand)cmdExecutor.Create(CommandType.Init);
			initCommand.Execute();
			serviceState = ServiceState.Initialized;
			IdentifyCommand identifyCommand = (IdentifyCommand)cmdExecutor.Create(CommandType.Identify);
			identifyCommand.Execute();
			serverIdentity = identifyCommand.ServerName;
			serverProtocolVersion = identifyCommand.ServerProtocolVersion;
			asamImpl = new ASAMBaseImpl(this);
			try
			{
				ExtQueryServiceCommand extQueryServiceCommand = (ExtQueryServiceCommand)cmdExecutor.Create(CommandType.QueryAvailableServices);
				extQueryServiceCommand.Execute();
				extendedServices = extQueryServiceCommand.Services;
				ExtendedServicesSupportAvailable = true;
			}
			catch (NotSupportedException)
			{
			}
			keepAlive = true;
			keepFetching = true;
		}

		public double GetScaledFloat(string elementName)
		{
			double num = -1.0;
			try
			{
				return asamImpl.GetScaledFloat(elementName);
			}
			catch (Exception)
			{
				throw new ServiceNotfoundException(Facility.ExecuteCommand, ErrorID.GetScaledFloat);
			}
		}

		public void SetScaledFloat(string elementName, double value)
		{
			asamImpl.SetScaledFloat(elementName, value);
		}

		public int _Open(string configurationFile, string binaryFile, string destination)
		{
			SelectDescriptionFileCommand selectDescriptionFileCommand = (SelectDescriptionFileCommand)cmdExecutor.Create(CommandType.SelectDescriptionFile);
			selectDescriptionFileCommand.descriptionFileName = configurationFile;
			selectDescriptionFileCommand.binaryFileName = binaryFile;
			selectDescriptionFileCommand.destination = destination;
			selectDescriptionFileCommand.Execute();
			lun = selectDescriptionFileCommand.LUN;
			return selectDescriptionFileCommand.LUN;
		}

		public void ExecuteCommand(string command, string arguments)
		{
			if (extendedServices == null || extendedServices.Count == 0)
			{
				throw new ServiceNotfoundException(Facility.ExecuteCommand, ErrorID.ExecuteService);
			}
			if (extendedServices.IndexOf(command) != -1)
			{
				ExecuteCommand executeCommand = (ExecuteCommand)cmdExecutor.Create(CommandType.ExecuteService);
				executeCommand.Command = command;
				if (arguments != "")
				{
					executeCommand.Arguments = arguments + " " + LUN;
				}
				else
				{
					executeCommand.Arguments = arguments + "\0" + LUN;
				}
				executeCommand.LUN = lun;
				executeCommand.Execute();
				returnFromExecuteCmd = executeCommand.ResponseString;
				return;
			}
			throw new NotSupportedException(command);
		}

		public string ExecuteGetAddressByParameterName(string parameterName)
		{
			if (parameterName == null)
			{
				throw new ArgumentNullException("parameterName argument is not valid");
			}
			GetAddressByParameterName getAddressByParameterName = (GetAddressByParameterName)cmdExecutor.Create(CommandType.GetAddressByParameterName);
			getAddressByParameterName.Command = "GetAddressByParameterName";
			getAddressByParameterName.Arguments = LUN + " " + parameterName;
			getAddressByParameterName.Execute();
			returnFromExecuteCmd = getAddressByParameterName.ResponseString;
			return returnFromExecuteCmd;
		}

		public string ExecuteGetParameterUnits(string parameterNames)
		{
			if (parameterNames == null)
			{
				throw new ArgumentNullException("parameterName argument is not valid");
			}
			GetParameterUnits getParameterUnits = (GetParameterUnits)cmdExecutor.Create(CommandType.GetParameterUnits);
			getParameterUnits.Command = "GetParameterUnits";
			getParameterUnits.Arguments = LUN + " " + parameterNames;
			getParameterUnits.Execute();
			returnFromExecuteCmd = getParameterUnits.ResponseString;
			return returnFromExecuteCmd;
		}

		public void ExecuteSendOperation(string LUN, string operation, string[] inputs, out string[] outputs)
		{
			if (extendedServices == null || extendedServices.Count == 0)
			{
				throw new ServiceNotfoundException(Facility.ExecuteCommand, ErrorID.ExecuteService);
			}
			if (inputs == null)
			{
				throw new ArgumentNullException("inputs array for operation " + operation);
			}
			if (extendedServices.IndexOf("SendOperation") != -1)
			{
				SendOperation sendOperation = (SendOperation)cmdExecutor.Create(CommandType.SendOperation);
				sendOperation.Command = LUN + " " + operation;
				for (int i = 0; i < inputs.Length; i++)
				{
					if (i == 0)
					{
						sendOperation.Arguments = inputs[i];
					}
					else
					{
						sendOperation.Arguments = sendOperation.Arguments + " " + inputs[i];
					}
				}
				try
				{
					sendOperation.Execute();
				}
				catch (Exception ex)
				{
					throw new RemoteScriptingException(Facility.ExecuteCommand, ErrorID.SendOperation, "Unable to execute Operation  " + operation + " " + ex.Message);
				}
				returnFromExecuteCmd = sendOperation.ResponseString;
				if (returnFromExecuteCmd != null && returnFromExecuteCmd.Length > 0)
				{
					outputs = returnFromExecuteCmd.Split(new char[1] { ' ' });
				}
				else
				{
					outputs = new string[0];
				}
				return;
			}
			throw new NotSupportedException(operation);
		}

		public string ExecuteGetSetAddress(string operation, string address, long length, string newValue)
		{
			if (extendedServices == null || extendedServices.Count == 0)
			{
				throw new ServiceNotfoundException(Facility.ExecuteCommand, ErrorID.ExecuteService);
			}
			if (extendedServices.IndexOf(operation) != -1)
			{
				GetSetAddress getSetAddress = (GetSetAddress)cmdExecutor.Create(CommandType.GetSetAddress);
				getSetAddress.Command = operation;
				getSetAddress.Address = address;
				getSetAddress.Length = length;
				getSetAddress.NewValue = newValue;
				try
				{
					getSetAddress.Execute();
				}
				catch (Exception ex)
				{
					throw new RemoteScriptingException(Facility.ExecuteCommand, ErrorID.GetSetAddress, "Error executing " + operation + ":" + ex.Message);
				}
				returnFromExecuteCmd = getSetAddress.ResponseString;
				return returnFromExecuteCmd;
			}
			throw new NotSupportedException(operation);
		}

		public string GetString(string elementName)
		{
			return asamImpl.GetString(elementName);
		}

		public bool SetString(string elementName, string newValue)
		{
			return asamImpl.SetString(elementName, newValue);
		}

		public bool _Download()
		{
			bool flag = false;
			try
			{
				return asamImpl._Download();
			}
			catch (Exception ex)
			{
				flag = false;
				throw new RemoteScriptingException(Facility.CalibrationDownload, ErrorID.Download, "Error downloading calibration:" + ex.Message);
			}
		}

		public bool _Upload()
		{
			bool flag = false;
			try
			{
				return asamImpl._Upload();
			}
			catch (Exception ex)
			{
				flag = false;
				throw new RemoteScriptingException(Facility.CalibrationUpload, ErrorID.Upload, "Error uploading calibration:" + ex.Message);
			}
		}

		public bool _ChangeBinaryFileName(string binaryFileName)
		{
			bool flag = false;
			return asamImpl._ChangeBinaryFileName(binaryFileName);
		}

		public void AddToMonitor(string elementName)
		{
			MonitorState monitorState = MonitorState;
			if (monitorState == MonitorState.Monitoring)
			{
				MonitorState = MonitorState.Stopped;
			}
			monitorElements.Add(new Parameter(elementName));
			if (monitorState == MonitorState.Monitoring)
			{
				MonitorState = MonitorState.Monitoring;
			}
		}

		public void RemoveFromMonitor(string elementName)
		{
			bool flag = false;
			int i;
			for (i = 0; i < monitorElements.Count; i++)
			{
				Parameter parameter = (Parameter)monitorElements[i];
				if (parameter.Name == elementName)
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				MonitorState monitorState = MonitorState;
				if (monitorState == MonitorState.Monitoring)
				{
					MonitorState = MonitorState.Stopped;
				}
				monitorElements.RemoveAt(i);
				if (monitorState == MonitorState.Monitoring)
				{
					MonitorState = MonitorState.Monitoring;
				}
				return;
			}
			throw new ElementNotFoundException(Facility.Monitoring, ErrorID.RemoveMonitorElement);
		}

		public void RemoveAllFromMonitor()
		{
			if (monitorElements.Count > 0)
			{
				MonitorState monitorState = MonitorState;
				if (monitorState == MonitorState.Monitoring)
				{
					MonitorState = MonitorState.Stopped;
				}
				monitorElements.Clear();
				if (monitorState == MonitorState.Monitoring)
				{
					MonitorState = MonitorState.Monitoring;
				}
			}
		}

		public void BatchAddMonitor(StringCollection elements)
		{
			if (elements == null || elements.Count <= 0)
			{
				return;
			}
			MonitorState monitorState = MonitorState;
			if (monitorState == MonitorState.Monitoring)
			{
				MonitorState = MonitorState.Stopped;
			}
			StringEnumerator enumerator = elements.GetEnumerator();
			try
			{
				while (enumerator.MoveNext())
				{
					string current = enumerator.Current;
					monitorElements.Add(new Parameter(current));
				}
			}
			finally
			{
				if (enumerator is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}
			if (monitorState == MonitorState.Monitoring)
			{
				MonitorState = MonitorState.Monitoring;
			}
		}

		private void StartMonitoring(MonitorMode monitorMode)
		{
			CurrentMonitorMode = monitorMode;
			try
			{
				if (serverIdentity.ToLower().IndexOf("cuty") != -1)
				{
					ExecuteCommand executeCommand = new ExecuteCommand(transport);
					string text = transport.Properties["ipaddress"].ToString();
					switch (monitorMode)
					{
					case MonitorMode.MonitorModeEDM:
						executeCommand.Command = "SetStreamingInfo3";
						executeCommand.Arguments = LUN + "\t" + text + "\t" + streamingUDPPort + "\tEDM";
						break;
					case MonitorMode.MonitorModeIDL:
						executeCommand.Command = "SetStreamingInfo3";
						executeCommand.Arguments = LUN + "\t" + text + "\t" + streamingUDPPort + "\tIDL_NOBAM";
						break;
					case MonitorMode.MonitorModeBAM:
						executeCommand.Command = "SetStreamingInfo3";
						executeCommand.Arguments = LUN + "\t" + text + "\t" + streamingUDPPort + "\tBAM";
						break;
					case MonitorMode.MonitorModeRequestReceive:
						executeCommand.Command = "SetStreamingInfo3";
						executeCommand.Arguments = LUN + "\t" + text + "\t" + streamingUDPPort + "\tProprietary_Request";
						break;
					default:
						executeCommand.Command = "SetStreamingInfo";
						executeCommand.Arguments = LUN + "\t" + text + "\t" + streamingUDPPort;
						break;
					}
					executeCommand.Execute();
				}
				asamImpl.StartMonitoring();
				keepFetching = true;
				fetchSignal.Set();
				monitorState = MonitorState.Monitoring;
			}
			catch (Exception)
			{
			}
		}

		private void StopMonitoring()
		{
			try
			{
				SwitchingOnlineOfflineCommand switchingOnlineOfflineCommand = (SwitchingOnlineOfflineCommand)cmdExecutor.Create(CommandType.SwitchingOnlineOffline);
				switchingOnlineOfflineCommand.Mode = 0;
				switchingOnlineOfflineCommand.Execute();
				monitorState = MonitorState.Stopped;
				keepFetching = false;
				fetchSignal.Reset();
				arrivedSignal.Reset();
			}
			catch (Exception ex)
			{
				throw new Exception("Unable to stop monitoring. Error:" + ex.Message);
			}
		}

		private void InitializeMonitor()
		{
			try
			{
				if (serverIdentity.ToLower().IndexOf("cuty") != -1)
				{
					notificationFetcher = new Thread(CUTYNotificationReceiver);
				}
				else
				{
					notificationFetcher = new Thread(ASAMNotificationFetcher);
				}
				notificationFetcher.Name = "Monitor Notification Fetcher";
				notificationFetcher.IsBackground = true;
				notificationFetcher.Start();
			}
			catch (Exception ex)
			{
				throw new Exception("Error in InitializeMonitor. Error:" + ex.Message);
			}
		}

		private void ASAMNotificationFetcher()
		{
			StartMonitoring(currentMonitorMode);
			while (keepAlive)
			{
				fetchSignal.WaitOne();
				GetOnlineValueCommand getOnlineValueCommand = (GetOnlineValueCommand)asamImpl.MonitorDataFetcher();
				while (keepFetching && serviceState != ServiceState.Terminated)
				{
					try
					{
						getOnlineValueCommand.Execute();
						MCTelegram notification = getOnlineValueCommand.Notification;
						if (notification.Status == 0)
						{
							MonitorElements notification2 = asamImpl.ParseMonitorData(notification);
							RaiseNotficationEvent(notification2);
							Thread.Sleep(scanningRate / 2);
						}
					}
					catch (Exception)
					{
					}
				}
			}
		}

		private void CUTYNotificationReceiver()
		{
			bool flag = false;
			Timer timer = new Timer(OnTimerElapsed, null, -1, MonitorRefreshRate);
			try
			{
				Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
				socket.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReceiveBuffer, 262144);
				int num = (int)transport.Properties["port"];
				IPEndPoint iPEndPoint = new IPEndPoint(IPAddress.Any, 0);
				EndPoint remoteEP = iPEndPoint;
				while (!flag && num < 65536 && num > 1024)
				{
					try
					{
						IPEndPoint localEP = new IPEndPoint(IPAddress.Any, num);
						socket.Bind(localEP);
						flag = true;
						streamingUDPPort = num;
					}
					catch (SocketException ex)
					{
						if (num == 65536)
						{
							throw ex;
						}
						num++;
					}
				}
				StartMonitoring(currentMonitorMode);
				while (keepAlive)
				{
					fetchSignal.WaitOne();
					Thread.Sleep(1);
					while (keepFetching && socket.Available > 0)
					{
						timer.Change(5000, 5000);
						MonitorStatusWhenMonitoring = true;
						byte[] array = new byte[socket.Available];
						int num2 = socket.ReceiveFrom(array, ref remoteEP);
						byte[] array2 = new byte[num2];
						for (int i = 0; i < num2; i++)
						{
							array2[i] = array[i];
						}
						StringBuilder stringBuilder = new StringBuilder(array2.Length + 1);
						byte[] array3 = array2;
						foreach (byte value in array3)
						{
							stringBuilder.Append((char)value);
						}
						string text = stringBuilder.ToString();
						if (!text.EndsWith("\n\0") || (!text.StartsWith("DATA: ") && !text.StartsWith("TIME: ")))
						{
							continue;
						}
						string timeStamp = "";
						if (text.StartsWith("TIME: "))
						{
							text = text.Substring("TIME: ".Length);
							timeStamp = text.Substring(0, text.IndexOf(" "));
							timeStamp = timeStamp.Trim();
							text = text.Substring(text.IndexOf("DATA: "));
						}
						text = text.Substring("DATA: ".Length);
						try
						{
							string[] array4 = text.Split(new char[1] { ',' });
							MonitorElements monitorElements = new MonitorElements(array4.Length);
							monitorElements.TimeStamp = timeStamp;
							for (int k = 0; k < array4.Length; k++)
							{
								string[] array5 = array4[k].TrimEnd(new char[0]).Split(new char[1] { ' ' });
								if (array5.Length > 2)
								{
									monitorElements[k] = new MonitorElement(array5[0], array5[1], array5[2]);
								}
								else
								{
									monitorElements[k] = new MonitorElement(array5[0], array5[1], "Unitless");
								}
							}
							RaiseNotficationEvent(monitorElements);
							Thread.Sleep(scanningRate / 2);
						}
						catch (Exception)
						{
						}
					}
				}
				socket.Close();
				socket = null;
			}
			catch (SocketException ex3)
			{
				throw ex3;
			}
		}

		~ASAMService()
		{
			Terminate();
		}

		public void Terminate()
		{
			if (serviceState == ServiceState.Terminated)
			{
				return;
			}
			try
			{
				ExitCommand exitCommand = (ExitCommand)cmdExecutor.Create(CommandType.Exit);
				exitCommand.Execute();
				keepFetching = false;
				keepAlive = false;
				fetchSignal.Set();
				arrivedSignal.Set();
				if (notificationFetcher != null && notificationFetcher.IsAlive)
				{
					notificationFetcher.Join();
				}
			}
			catch (Exception)
			{
			}
			finally
			{
				serviceState = ServiceState.Terminated;
			}
		}

		protected void RaiseNotficationEvent(ICINotification2 notification)
		{
			if (MonitorDataRefreshEvent != null)
			{
				try
				{
					MonitorDataRefreshEvent(notification);
				}
				catch (Exception innerException)
				{
					throw new Exception("Error in RaiseNotficationEvent", innerException);
				}
			}
		}

		private void OnTimerElapsed(object sender)
		{
			MonitorStatusWhenMonitoring = false;
		}

		public string ExecuteReadNParameters(string inParamNames)
		{
			if (inParamNames == null)
			{
				throw new ArgumentNullException("parameterNames argument is not valid");
			}
			ReadNParameters readNParameters = (ReadNParameters)cmdExecutor.Create(CommandType.ReadNParameters);
			readNParameters.Command = "ReadNParameters";
			readNParameters.Arguments = LUN + " " + inParamNames;
			readNParameters.Execute();
			returnFromExecuteCmd = readNParameters.ResponseString;
			return returnFromExecuteCmd;
		}
	}
	internal class ASAMCommandFactory
	{
		public ITransport transport;

		public ASAMCommandFactory(ITransport transport)
		{
			this.transport = transport;
		}

		public ASAMCommand Create(CommandType command)
		{
			return command switch
			{
				CommandType.Emergency => new EmergencyCommand(transport), 
				CommandType.Init => new InitCommand(transport), 
				CommandType.Identify => new IdentifyCommand(transport), 
				CommandType.Exit => new ExitCommand(transport), 
				CommandType.SelectDescriptionFile => new SelectDescriptionFileCommand(transport), 
				CommandType.CopyBinaryFile => new CopyBinaryFileCommand(transport), 
				CommandType.ChangeBinaryFileName => new ChangeBinaryFileNameCommand(transport), 
				CommandType.DefineDescriptionAndBinaryFile => new DefineDescriptionAndBinaryFileCommand(transport), 
				CommandType.ParameterForValueAcquisition => new ParameterForValueAcquisitionCommand(transport), 
				CommandType.ExtendedParameterForValueAcquisition => new ExtParamForValueAcqCommand(transport), 
				CommandType.SwitchingOnlineOffline => new SwitchingOnlineOfflineCommand(transport), 
				CommandType.GetOnlineValue => new GetOnlineValueCommand(transport), 
				CommandType.ExtendedGetOnlineValue => new ExtendedGetOnlineValueCommand(transport), 
				CommandType.GetParameter => new GetParameterCommand(transport), 
				CommandType.SetParameter => new SetParameterCommand(transport), 
				CommandType.ExtendedGetParameter => new ExtGetParameterCommand(transport), 
				CommandType.ExtendedSetParameter => new ExtSetParameterCommand(transport), 
				CommandType.QueryAvailableServices => new ExtQueryServiceCommand(transport), 
				CommandType.GetAddressByParameterName => new GetAddressByParameterName(transport), 
				CommandType.GetParameterUnits => new GetParameterUnits(transport), 
				CommandType.ExecuteService => new ExecuteCommand(transport), 
				CommandType.SendOperation => new SendOperation(transport), 
				CommandType.GetSetAddress => new GetSetAddress(transport), 
				CommandType.ReadNParameters => new ReadNParameters(transport), 
				_ => new InitCommand(transport), 
			};
		}
	}
	[ComVisible(false)]
	internal enum ByteOrder
	{
		Intel,
		Motorola
	}
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	[Guid("B48BFDFE-827B-4530-A383-B88F6A20729D")]
	public interface ICIRemoteServer
	{
		[DispId(1)]
		string Configuration { get; set; }

		[DispId(3)]
		bool Connected { get; }

		[DispId(2)]
		void Connect();

		[DispId(50)]
		void Disconnect();
	}
	[ComVisible(false)]
	internal class ServerConnection : ICIRemoteServer, ITransport
	{
		private delegate void TransportDelegate(byte[] senderData, out byte[] receivedData);

		private const string IPAddressFormat = "[1-9]{1}[0-9]{1,2}\\.([0-9]{1,3}\\.){2}[1-9]{1}[0-9]{1,2}";

		private const int ServerMonitorRate = 10000;

		internal static string space = " ";

		internal static bool SwapBytes = false;

		private TransportDelegate asyncTransporter;

		private string configuration = string.Empty;

		private Socket socket;

		private IPEndPoint remoteEP;

		private string ipAddress;

		private ByteOrder byteOrder;

		private int port;

		private ServerStatus serverStatus;

		private Timer serverConnectionMonitor;

		private object transportLock = new object();

		private bool isMonitoring;

		private int transferTimeout = 20;

		private bool pingDevice;

		private SortedList properties;

		public string DeviceInfo => $"TCP/IP: {ipAddress}:{port}";

		public SortedList Properties => properties;

		public string Configuration
		{
			get
			{
				return configuration;
			}
			set
			{
				//IL_0027: Unknown result type (might be due to invalid IL or missing references)
				//IL_002d: Expected O, but got Unknown
				if (value == null || value.Length == 0)
				{
					throw new ArgumentException("configuration");
				}
				if (!(configuration != value))
				{
					return;
				}
				try
				{
					XmlDocument val = new XmlDocument();
					val.LoadXml(value);
					XmlElement documentElement = val.DocumentElement;
					ipAddress = readConfigValue(documentElement, "ipAddress");
					Regex regex = new Regex("[1-9]{1}[0-9]{1,2}\\.([0-9]{1,3}\\.){2}[1-9]{1}[0-9]{1,2}");
					Match match = regex.Match(ipAddress);
					if (!match.Success && ipAddress != "127.0.0.1")
					{
						throw new BadInputException(Facility.ServerConnection, ErrorID.BadInput);
					}
					string s = readConfigValue(documentElement, "servicePort");
					try
					{
						port = int.Parse(s);
					}
					catch
					{
						throw new BadInputException(Facility.ServerConnection, ErrorID.BadInput);
					}
					s = readConfigValue(documentElement, "byteOrder");
					try
					{
						byteOrder = (ByteOrder)Enum.Parse(typeof(ByteOrder), s);
					}
					catch
					{
						byteOrder = ByteOrder.Motorola;
					}
					s = readConfigValue(documentElement, "timeOut");
					try
					{
						transferTimeout = int.Parse(s);
					}
					catch
					{
						transferTimeout = 0;
					}
					if (port <= 1024 || port >= 65536)
					{
						throw new BadInputException(Facility.ServerConnection, ErrorID.BadInput);
					}
					configuration = value;
					properties.Add("ipaddress", ipAddress);
					properties.Add("port", port);
					properties.Add("byteOrder", byteOrder);
					if (BitConverter.IsLittleEndian)
					{
						SwapBytes = byteOrder == ByteOrder.Motorola;
					}
					else
					{
						SwapBytes = byteOrder == ByteOrder.Intel;
					}
				}
				catch (XmlException)
				{
					throw new Exception("Invalid XML");
				}
				catch (FormatException)
				{
					throw new BadInputException(Facility.ServerConnection, ErrorID.BadInput);
				}
			}
		}

		public bool Connected => ServerStatus == ServerStatus.Connected;

		public ServerStatus ServerStatus
		{
			get
			{
				return serverStatus;
			}
			set
			{
				if (serverStatus != value)
				{
					serverStatus = value;
					RaiseServerStatusChangeEvent();
				}
			}
		}

		public event ServerStatusChangeDelegate ServerStatusChangeEvent;

		public ServerConnection()
		{
			configuration = string.Empty;
			ipAddress = "127.0.0.1";
			port = 57005;
			asyncTransporter = Exchange;
			serverConnectionMonitor = new Timer(OnTimerElapsed, null, -1, 10000);
			properties = new SortedList();
		}

		public void Connect()
		{
			lock (this)
			{
				if (ServerStatus != ServerStatus.Connected)
				{
					ServerStatus = ServerStatus.Connecting;
					try
					{
						IPAddress address = IPAddress.Parse(ipAddress);
						remoteEP = new IPEndPoint(address, port);
						socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
						socket.Connect(remoteEP);
						ServerStatus = ServerStatus.Connected;
						serverConnectionMonitor.Change(10000, 10000);
						return;
					}
					catch (Exception ex)
					{
						ServerStatus = ServerStatus.Disconnected;
						throw ex;
					}
				}
			}
		}

		public void Disconnect()
		{
			try
			{
				if (ServerStatus != ServerStatus.Disconnected)
				{
					serverConnectionMonitor.Change(-1, 10000);
					if (socket.Connected)
					{
						socket.Close();
						socket = null;
					}
					ServerStatus = ServerStatus.Disconnected;
				}
			}
			catch (Exception)
			{
			}
		}

		public void ReConnect()
		{
			try
			{
				Disconnect();
				Connect();
			}
			catch (Exception)
			{
			}
		}

		public void Send(byte[] buffer)
		{
			if (Connected)
			{
				socket.Send(buffer);
				return;
			}
			throw new ServerNotConnectedException(Facility.ServerConnection, ErrorID.NoConnection);
		}

		public byte[] Receive()
		{
			byte[] array = null;
			if (Connected)
			{
				byte[] array2 = new byte[DataBuffer.WordSize];
				int num = socket.Receive(array2, DataBuffer.WordSize, SocketFlags.Peek);
				if (num != 2)
				{
					throw new Exception("Failed to receive packet from remote server... TODO: need to do more than this for error handling.");
				}
				DataBuffer dataBuffer = new DataBuffer(array2);
				int word = dataBuffer.getWord();
				if (word > 0)
				{
					array = new byte[word];
					socket.Receive(array);
					return array;
				}
				throw new Exception("Failed to receive packet from remote server...");
			}
			throw new ServerNotConnectedException(Facility.ServerConnection, ErrorID.NoConnection);
		}

		private void Exchange(byte[] senderData, out byte[] receivedData)
		{
			Send(senderData);
			receivedData = Receive();
		}

		public byte[] Transport(byte[] rawData)
		{
			if (Connected)
			{
				lock (transportLock)
				{
					byte[] receivedData = null;
					if (transferTimeout == 0)
					{
						Exchange(rawData, out receivedData);
					}
					else
					{
						IAsyncResult asyncResult = asyncTransporter.BeginInvoke(rawData, out receivedData, null, null);
						asyncResult.AsyncWaitHandle.WaitOne(transferTimeout * 1000, exitContext: false);
						if (!asyncResult.IsCompleted)
						{
							ServerStatus = ServerStatus.Disconnected;
							throw new ServerNotConnectedException(Facility.ServerConnection, ErrorID.TransferTimeOut);
						}
						asyncTransporter.EndInvoke(out receivedData, asyncResult);
					}
					return receivedData;
				}
			}
			throw new ServerNotConnectedException(Facility.ServerConnection, ErrorID.NoConnection);
		}

		protected void RaiseServerStatusChangeEvent()
		{
			if (this.ServerStatusChangeEvent != null)
			{
				try
				{
					this.ServerStatusChangeEvent(serverStatus);
				}
				catch (Exception)
				{
				}
			}
		}

		private string readConfigValue(XmlElement root, string elementName)
		{
			string result = "";
			XmlNode val = ((XmlNode)root).SelectSingleNode("//configuration/" + elementName);
			if (val != null && val.FirstChild != null)
			{
				result = val.FirstChild.Value;
			}
			return result;
		}

		private void OnTimerElapsed(object sender)
		{
			if (isMonitoring)
			{
				return;
			}
			isMonitoring = true;
			if (socket != null)
			{
				byte[] rawData = new byte[6] { 0, 6, 0, 2, 0, 0 };
				try
				{
					Transport(rawData);
					ServerStatus = ServerStatus.Connected;
				}
				catch (Exception)
				{
					Disconnect();
				}
			}
			else
			{
				ServerStatus = ServerStatus.Disconnected;
			}
			isMonitoring = false;
		}
	}
	[Guid("62B24ADF-FAD6-4933-B3C8-86A767FF2053")]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	public interface ICIMonitor
	{
		[DispId(12)]
		int MonitorRefreshRate { get; set; }

		[DispId(18)]
		string MonitorRecordFile { get; set; }

		[DispId(19)]
		bool MonitorRecording { get; set; }

		[DispId(13)]
		void AddMonitorElement(string element);

		[DispId(14)]
		void RemoveMonitorElement(string element);

		[DispId(33)]
		void RemoveAllMonitorElements();

		[DispId(15)]
		void LoadMonitorScreen(string screenFileName, string screenName);

		[DispId(16)]
		void StartMonitor(MonitorMode monitorMode);

		[DispId(17)]
		void StopMonitor();
	}
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	[Guid("DFFFCE3B-9662-4bb4-A7A2-46EAC1034C4C")]
	public interface ICIMonitor2
	{
		[DispId(1)]
		void StartMonitor2(MonitorMode monitorMode, int UDPPort);
	}
	[ComVisible(false)]
	internal class Monitor : ICIMonitor, ICIMonitor2
	{
		private StreamWriter streamWriter;

		private bool rewriteLogFileHeader = true;

		private string recordFile;

		private bool isRecording;

		private IService service;

		public int MonitorRefreshRate
		{
			get
			{
				return service.MonitorRefreshRate;
			}
			set
			{
				service.MonitorRefreshRate = value;
			}
		}

		public string MonitorRecordFile
		{
			get
			{
				return recordFile;
			}
			set
			{
				recordFile = value;
			}
		}

		public bool MonitorRecording
		{
			get
			{
				return isRecording;
			}
			set
			{
				if (value == isRecording)
				{
					return;
				}
				try
				{
					if (value)
					{
						IService obj = service;
						obj.MonitorDataRefreshEvent = (MonitorDataRefreshDelegate)Delegate.Combine(obj.MonitorDataRefreshEvent, new MonitorDataRefreshDelegate(WriteToMonitorFile));
						streamWriter = new StreamWriter(recordFile, append: true, Encoding.UTF8, 204800);
						streamWriter.AutoFlush = false;
					}
					else if (isRecording)
					{
						IService obj2 = service;
						obj2.MonitorDataRefreshEvent = (MonitorDataRefreshDelegate)Delegate.Remove(obj2.MonitorDataRefreshEvent, new MonitorDataRefreshDelegate(WriteToMonitorFile));
						rewriteLogFileHeader = true;
						if (streamWriter != null)
						{
							streamWriter.Flush();
							streamWriter.Close();
							streamWriter = null;
						}
					}
					isRecording = value;
				}
				catch (IOException ex)
				{
					throw new Exception("I/O error in MonitorRecording. " + ex.Message);
				}
				catch (Exception ex2)
				{
					throw new Exception("Error in MonitorRecording. " + ex2.Message);
				}
			}
		}

		public MonitorDataRefreshDelegate MonitorDataRefreshEvent
		{
			get
			{
				return service.MonitorDataRefreshEvent;
			}
			set
			{
				service.MonitorDataRefreshEvent = value;
			}
		}

		public Monitor(IService service)
		{
			if (service == null)
			{
				throw new ArgumentNullException("service");
			}
			this.service = service;
		}

		~Monitor()
		{
			if (MonitorRecording)
			{
				MonitorRecording = false;
			}
		}

		public void AddMonitorElement(string element)
		{
			if (element == null)
			{
				throw new ArgumentNullException("element");
			}
			service.AddToMonitor(element);
		}

		public void RemoveMonitorElement(string element)
		{
			if (element == null || element.Length == 0)
			{
				throw new ArgumentNullException("element");
			}
			service.RemoveFromMonitor(element);
		}

		public void RemoveAllMonitorElements()
		{
			service.RemoveAllFromMonitor();
		}

		public void LoadMonitorScreen(string screenFileName, string screenName)
		{
			if (screenFileName == null || screenFileName.Length == 0)
			{
				throw new ArgumentNullException("screenFileName");
			}
			if (screenFileName == null || screenFileName.Length == 0)
			{
				throw new ArgumentNullException("screenName");
			}
			if (!File.Exists(screenFileName))
			{
				throw new FileNotFoundException(screenFileName);
			}
			NewDataSet newDataSet = new NewDataSet();
			try
			{
				newDataSet.ReadXml(screenFileName);
			}
			catch (XmlException)
			{
				throw new InvalidScreenFileException(Facility.Monitoring, ErrorID.LoadScreenFile);
			}
			NewDataSet.ScreenRow[] array = (NewDataSet.ScreenRow[])newDataSet.Screen.Select("(Name = '" + screenName + "')");
			if (array.Length != 0)
			{
				StringCollection stringCollection = new StringCollection();
				NewDataSet.GroupRow[] groupRows = array[0].GetGroupRows();
				foreach (NewDataSet.GroupRow groupRow in groupRows)
				{
					NewDataSet.ParameterRow[] parameterRows = groupRow.GetParameterRows();
					foreach (NewDataSet.ParameterRow parameterRow in parameterRows)
					{
						if (parameterRow.Name != null && parameterRow.Name.Length > 0)
						{
							stringCollection.Add(parameterRow.Name);
						}
					}
				}
				service.BatchAddMonitor(stringCollection);
				return;
			}
			throw new ScreenNotFoundException(Facility.Monitoring, ErrorID.LoadScreenFile);
		}

		public void StartMonitor(MonitorMode monitorMode)
		{
			service.CurrentMonitorMode = monitorMode;
			service.UDPPort = service.DEFAULT_UDP_PORT;
			service.MonitorState = MonitorState.Monitoring;
		}

		public void StartMonitor2(MonitorMode monitorMode, int UDPPort)
		{
			if (UDPPort < 1024 || UDPPort > 65536)
			{
				throw new InvalidPortNumberException(Facility.Monitoring, ErrorID.StartMonitor2, "Invalid Port Number. The port number should be greater than 1024");
			}
			service.CurrentMonitorMode = monitorMode;
			service.UDPPort = UDPPort;
			service.MonitorState = MonitorState.Monitoring;
		}

		public void StopMonitor()
		{
			try
			{
				service.MonitorState = MonitorState.Stopped;
				if (MonitorRecording)
				{
					MonitorRecording = false;
				}
			}
			catch (Exception ex)
			{
				throw new Exception(ex.Message);
			}
		}

		private void WriteToMonitorFile(ICINotification arg)
		{
			ICINotification2 iCINotification = (ICINotification2)arg;
			if (service.MonitorState != MonitorState.Monitoring || !isRecording || recordFile == "" || streamWriter == null)
			{
				return;
			}
			try
			{
				string empty = string.Empty;
				if (rewriteLogFileHeader)
				{
					string value = DateTime.Now.ToShortDateString() + ' ' + DateTime.Now.ToLongTimeString();
					streamWriter.WriteLine(value);
					empty = "Parameter Name,timestamp,";
					for (int i = 0; i < iCINotification.Count; i++)
					{
						ICIMonitorElement element = iCINotification.GetElement(i);
						empty = empty + element.Name + ",";
					}
					streamWriter.WriteLine(empty);
					empty = "Units,none,";
					for (int j = 0; j < iCINotification.Count; j++)
					{
						ICIMonitorElement element = iCINotification.GetElement(j);
						empty = empty + element.Units + ",";
					}
					streamWriter.WriteLine(empty);
					streamWriter.WriteLine("Source Address,,R0");
					rewriteLogFileHeader = false;
				}
				empty = ((!(iCINotification.TimeStamp != string.Empty) || iCINotification.TimeStamp == null) ? ",," : ("," + FormatTime(iCINotification.TimeStamp) + ","));
				for (int k = 0; k < iCINotification.Count; k++)
				{
					ICIMonitorElement element = iCINotification.GetElement(k);
					empty = empty + element.Value + ",";
				}
				streamWriter.WriteLine(empty);
			}
			catch (IOException)
			{
				throw new RemoteScriptingException(Facility.Monitoring, ErrorID.MonitoringRecording);
			}
		}

		private string FormatTime(string timestamp)
		{
			double num = long.Parse(timestamp);
			double num2 = num;
			double num3 = Math.Floor(num / 1000.0);
			double num4 = Math.Floor(num3 / 60.0);
			double num5 = Math.Floor(num4 / 60.0);
			num2 -= num3 * 1000.0;
			num3 -= num4 * 60.0;
			num4 -= num5 * 60.0;
			string text = num2.ToString("000");
			string text2 = num3.ToString("00");
			string text3 = num4.ToString("00");
			string text4 = num5.ToString("00");
			return text4 + ":" + text3 + ":" + text2 + "." + text;
		}
	}
}
namespace Cummins.CUTY.Exceptions
{
	public class BaseException : ApplicationException
	{
		private string context;

		public int ErrorCode
		{
			get
			{
				return base.HResult;
			}
			set
			{
				base.HResult = value;
			}
		}

		public string ContextData
		{
			get
			{
				return context;
			}
			set
			{
				context = value;
			}
		}

		public BaseException(Facility facility, short errorNo)
		{
			base.HResult = MakeHResult(Severity.Error, facility, errorNo);
		}

		public BaseException(Facility facility, short errorNo, string message)
			: base(message)
		{
			base.HResult = MakeHResult(Severity.Error, facility, errorNo);
		}

		public BaseException(Facility facility, short errorNo, string message, Exception inner)
			: base(message, inner)
		{
			base.HResult = MakeHResult(Severity.Error, facility, errorNo);
		}

		public BaseException(Facility facility, short errorNo, string message, string context)
			: base(message)
		{
			base.HResult = MakeHResult(Severity.Error, facility, errorNo);
			this.context = context;
		}

		public BaseException(Facility facility, short errorNo, string message, string context, Exception inner)
			: base(message, inner)
		{
			base.HResult = MakeHResult(Severity.Error, facility, errorNo);
			this.context = context;
		}

		public BaseException(SerializationInfo info, StreamingContext context)
			: base(info, context)
		{
		}

		protected int MakeHResult(Severity severity, Facility facility, short errorNo)
		{
			int num = (int)facility << 4;
			num += errorNo;
			return num + ((int)severity << 7);
		}
	}
}
namespace Cummins.CUTY
{
	public class GetParameterUnits : ExecuteCommand
	{
		public GetParameterUnits(ITransport transport)
			: base(transport)
		{
		}

		public override void Execute()
		{
			_ = CommunicationLog.InstanceOf;
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(202);
			ausyTelegram.putString("GetParameterUnits");
			string empty = string.Empty;
			empty = base.Arguments;
			ausyTelegram.putString(empty);
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			MCTelegram mCTelegram = new MCTelegram(rawData);
			validateResponse(mCTelegram);
			responseString = mCTelegram.getString();
		}
	}
	public enum ServerStatus
	{
		Disconnected,
		Connecting,
		Connected
	}
	[ComVisible(false)]
	public delegate void ServerStatusChangeDelegate(ServerStatus status);
	public enum DeviceStatus
	{
		Unknown,
		Connecting,
		Connected,
		Disconnected,
		Closed
	}
	public enum MonitorMode
	{
		MonitorModeRequestReceive,
		MonitorModeEDM,
		MonitorModeIDL,
		MonitorModeBAM
	}
	[ComVisible(false)]
	public delegate void DeviceStatusChangeDelegate(DeviceStatus status);
	[Guid("5DE25EFC-B47F-4dd3-BDBF-11440C0F3EAB")]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	public interface ICIRemoteDevice
	{
		[DispId(51)]
		DeviceStatus DeviceStatus { get; }

		[DispId(4)]
		void Open(string configFile);

		[DispId(55)]
		void Open2(string configFile, string destination);

		[DispId(5)]
		double ReadParameter(string elementName);

		[DispId(7)]
		void WriteParameter(string elementName, double newValue);

		[DispId(52)]
		void WriteAddress(string address, string newValue);

		[DispId(53)]
		string ReadAddress(string address, long length);

		[DispId(9)]
		void Close();

		[DispId(10)]
		bool Download(string configFile, string binaryFile);

		[DispId(100)]
		bool Download2(string configFile, string binaryFile, string destinationAddress);

		[DispId(11)]
		void ExecuteCommand(string command, string arguments);
	}
	[ComVisible(false)]
	public delegate void MonitorDataRefreshDelegate(ICINotification notification);
	public enum LoggingMode
	{
		Manual,
		Triggered
	}
	public enum LogFileLocation
	{
		Local,
		Remote
	}
	public enum FaultsType
	{
		InActive,
		Active,
		All
	}
	public enum Facility
	{
		Unknown,
		ServerConnection,
		DeviceConnection,
		ExecuteCommand,
		Monitoring,
		Logging,
		Faults,
		CalibrationDownload,
		CalibrationUpload
	}
	[ComVisible(false)]
	public delegate void ProgressDelegate(Facility facility, string progress, int current, int total);
	[Guid("D9EC5920-A3DB-4b7e-B697-E72B5832B7D9")]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	public interface ICICommunicationLog
	{
		[DispId(31)]
		bool Enabled { get; set; }

		[DispId(32)]
		string ExecutionLogFile { get; set; }
	}
	[Guid("515D0981-FDCA-4390-B2EE-FD19E3D18BEC")]
	[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
	public interface ICIRemoteScriptingEvents
	{
		[DispId(100)]
		void ServerStatusChange(ServerStatus serverStatus);

		[DispId(2)]
		void DeviceStatusChange(DeviceStatus deviceStatus);

		[DispId(3)]
		void MonitorDataRefresh(ICINotification notification);

		[DispId(4)]
		void Progress(Facility facility, string progress, int current, int total);
	}
	[Guid("F1F78D46-E1B1-4a80-ADA5-8214A343668D")]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	public interface ICIRemoteDevice2
	{
		[DispId(1)]
		string ExecuteCommandResult();

		[DispId(2)]
		string ReadParameter2(string elementName);

		[DispId(3)]
		void WriteParameter2(string elementName, string newValue);
	}
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	[Guid("C569EAD2-D7F8-453a-B132-7D7D9DC30080")]
	public interface ICIRemoteDevice3
	{
		[DispId(1)]
		bool Upload(string calibrationFileName);
	}
	[ComVisible(false)]
	public delegate void MonitorDataRefreshDelegate2(ICINotification2 notification);
	public class SwitchingOnlineOfflineCommand : ASAMCommand
	{
		private ITransport transport;

		private ushort mode;

		public ushort Mode
		{
			set
			{
				mode = value;
			}
		}

		public SwitchingOnlineOfflineCommand(ITransport transport)
		{
			this.transport = transport;
			mode = 255;
		}

		public override void Execute()
		{
			if (mode > 1)
			{
				throw new InvalidOperationException("Mode not set");
			}
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(13);
			ausyTelegram.putWord(mode);
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			MCTelegram telegram = new MCTelegram(rawData);
			validateResponse(telegram);
		}
	}
	public class ParameterForValueAcquisitionCommand : ASAMCommand
	{
		private ushort refreshRate;

		private ArrayList parameters;

		private ITransport transport;

		private ushort lun;

		public ushort RefreshRate
		{
			set
			{
				refreshRate = value;
			}
		}

		public ushort LUN
		{
			set
			{
				lun = value;
			}
		}

		public ArrayList Parameters
		{
			get
			{
				return parameters;
			}
			set
			{
				parameters = value;
			}
		}

		public ParameterForValueAcquisitionCommand(ITransport transport)
		{
			this.transport = transport;
			refreshRate = 500;
			lun = 255;
		}

		protected MCTelegram ActualExecute(ushort cmd)
		{
			if (parameters == null || lun == 255)
			{
				throw new InvalidOperationException("Object not initiliazed");
			}
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(cmd);
			ausyTelegram.putWord(lun);
			ausyTelegram.putWord(refreshRate);
			ausyTelegram.putWord((ushort)parameters.Count);
			for (int i = 0; i < Parameters.Count; i++)
			{
				Parameter parameter = (Parameter)Parameters[i];
				ausyTelegram.putString(parameter.Name);
			}
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			MCTelegram mCTelegram = new MCTelegram(rawData);
			validateResponse(mCTelegram);
			return mCTelegram;
		}

		public override void Execute()
		{
			ActualExecute(12);
		}
	}
	public class ExtParamForValueAcqCommand : ParameterForValueAcquisitionCommand
	{
		public ExtParamForValueAcqCommand(ITransport transport)
			: base(transport)
		{
		}

		public override void Execute()
		{
			MCTelegram mCTelegram = ActualExecute(112);
			if (mCTelegram.Status != 0)
			{
				return;
			}
			for (int i = 0; i < base.Parameters.Count; i++)
			{
				Parameter parameter = (Parameter)base.Parameters[i];
				ushort word = mCTelegram.getWord();
				if (word >= 0 && word < 3)
				{
					parameter.DataType = (ASAMDataType)word;
					continue;
				}
				throw new ASAMCommandExecutionException(mCTelegram, Facility.Monitoring, ErrorID.InvalidASAMDataType);
			}
		}
	}
	[ComVisible(false)]
	internal class Device : ICIRemoteDevice, ICIRemoteDevice2, ICIRemoteDevice3
	{
		private const int DeviceConnectionMonitorRate = 5000;

		private const string ECM_Run_Time = "ECM_Run_Time";

		private const string CutyServerName = "cuty";

		private ITransport transport;

		private IService service;

		private DeviceStatus deviceStatus;

		private Timer deviceConnectionMonitor;

		private bool isDownloading;

		private bool isUploading;

		public DeviceStatus DeviceStatus => deviceStatus;

		private DeviceStatus InternalDeviceStatus
		{
			set
			{
				if (deviceStatus != value)
				{
					deviceStatus = value;
					RaiseDeviceStatusChangeEvent();
				}
			}
		}

		public event DeviceStatusChangeDelegate DeviceStatusChangeEvent;

		public void Open(string configFile)
		{
			_Open(configFile, "", "ff");
		}

		public void Open2(string configFile, string destination)
		{
			_Open(configFile, "", destination);
		}

		public double ReadParameter(string elementName)
		{
			if (elementName == null || elementName.Length == 0)
			{
				throw new ArgumentNullException("elementName");
			}
			try
			{
				return double.Parse(service.GetString(elementName));
			}
			catch (ServiceNotfoundException)
			{
				if (DeviceStatus == DeviceStatus.Connected)
				{
					throw new DeviceNotOpenException(Facility.DeviceConnection, ErrorID.NoConnection);
				}
				if (elementName == "ECM_Identifier")
				{
					throw new DeviceNotOpenException(Facility.DeviceConnection, ErrorID.NoConnection);
				}
				throw new ServiceNotfoundException(Facility.ExecuteCommand, ErrorID.GetScaledFloat);
			}
		}

		public void WriteParameter(string elementName, double Value)
		{
			if (elementName == null || elementName.Length == 0)
			{
				throw new ArgumentNullException("elementName");
			}
			if (DeviceStatus == DeviceStatus.Connected)
			{
				service.SetString(elementName, Value.ToString());
				return;
			}
			throw new DeviceNotOpenException(Facility.DeviceConnection, ErrorID.NoConnection);
		}

		public void Close()
		{
			if (service.ServerIdentity.ToLower().IndexOf("cuty") != -1)
			{
				deviceConnectionMonitor.Change(-1, 5000);
				InternalDeviceStatus = DeviceStatus.Closed;
			}
		}

		public bool Download(string configFile, string binaryFile)
		{
			return _Download(configFile, binaryFile, "ff");
		}

		public bool Download2(string configFile, string binaryFile, string destinationAddress)
		{
			return _Download(configFile, binaryFile, destinationAddress);
		}

		public void ExecuteCommand(string command, string arguments)
		{
			if (command == null || command.Length == 0)
			{
				throw new ArgumentNullException("command");
			}
			if (DeviceStatus == DeviceStatus.Connected)
			{
				service.ExecuteCommand(command, arguments);
				return;
			}
			throw new DeviceNotOpenException(Facility.DeviceConnection, ErrorID.NoConnection);
		}

		public void WriteAddress(string address, string newValue)
		{
			if (address == null || address.Length == 0)
			{
				throw new ArgumentNullException("address");
			}
			if (newValue == null || newValue.Length == 0)
			{
				throw new ArgumentNullException("value");
			}
			if (newValue.Length % 2 != 0)
			{
				throw new BadInputException(Facility.Unknown, ErrorID.BadInput, "Length of the value should be even.");
			}
			int num = 0;
			foreach (char character in newValue)
			{
				if (Uri.IsHexDigit(character))
				{
					num++;
				}
			}
			if (num != newValue.Length)
			{
				throw new BadInputException(Facility.Unknown, ErrorID.BadInput, "Value is not a valid hexadecimal number.");
			}
			if (DeviceStatus == DeviceStatus.Connected)
			{
				service.ExecuteGetSetAddress("SetAddress", address, 0L, newValue);
				return;
			}
			throw new DeviceNotOpenException(Facility.DeviceConnection, ErrorID.NoConnection);
		}

		public string ReadAddress(string address, long length)
		{
			if (address == null || address.Length == 0)
			{
				throw new ArgumentNullException("address");
			}
			if (DeviceStatus == DeviceStatus.Connected)
			{
				service.ExecuteGetSetAddress("GetAddress", address, length, "");
				return service.ReturnFromExecuteCmd;
			}
			throw new DeviceNotOpenException(Facility.DeviceConnection, ErrorID.NoConnection);
		}

		public string ExecuteCommandResult()
		{
			if (DeviceStatus == DeviceStatus.Connected)
			{
				return service.ReturnFromExecuteCmd;
			}
			throw new Exception("Can not execute command. No connection is established with a device.");
		}

		public string ReadParameter2(string elementName)
		{
			if (elementName == null || elementName.Length == 0)
			{
				throw new ArgumentNullException("elementName");
			}
			if (DeviceStatus == DeviceStatus.Connected)
			{
				return service.GetString(elementName);
			}
			throw new DeviceNotOpenException(Facility.DeviceConnection, ErrorID.NoConnection);
		}

		public bool WriteParameter2(string elementName, string newValue)
		{
			if (elementName == null || elementName.Length == 0)
			{
				throw new ArgumentNullException("elementName");
			}
			if (newValue == null)
			{
				throw new ArgumentNullException("newValue");
			}
			if (newValue.IndexOf(".") == -1 && (newValue.StartsWith("0x") || newValue.StartsWith("0X")))
			{
				try
				{
					newValue = int.Parse(newValue.Substring(2), NumberStyles.HexNumber).ToString();
				}
				catch (Exception)
				{
				}
			}
			if (DeviceStatus == DeviceStatus.Connected)
			{
				try
				{
					return service.SetString(elementName, newValue);
				}
				catch (Exception ex2)
				{
					throw new RemoteScriptingException(Facility.ExecuteCommand, ErrorID.SetParameter, ex2.Message);
				}
			}
			throw new DeviceNotOpenException(Facility.DeviceConnection, ErrorID.NoConnection);
		}

		public bool Upload(string binaryFileName)
		{
			return _Upload(binaryFileName);
		}

		public Device(ITransport transport, IService service)
		{
			this.transport = transport;
			this.service = service;
			InternalDeviceStatus = DeviceStatus.Connected;
		}

		private int _Open(string configFile, string binaryFile, string destination)
		{
			if (service.ServerIdentity.ToLower().IndexOf("cuty") != -1)
			{
				deviceConnectionMonitor = new Timer(OnTimerElapsed, null, -1, 5000);
			}
			int num = -1;
			try
			{
				if (configFile == null || configFile.Length == 0)
				{
					throw new ArgumentNullException("configFile");
				}
				if (service.ServerIdentity.ToLower().IndexOf("cuty") != -1 && DeviceStatus == DeviceStatus.Connected)
				{
					Close();
				}
				InternalDeviceStatus = DeviceStatus.Connecting;
				num = service._Open(configFile, binaryFile, destination);
				InternalDeviceStatus = DeviceStatus.Connected;
				if (service.ServerIdentity.ToLower().IndexOf("cuty") != -1)
				{
					deviceConnectionMonitor.Change(5000, 5000);
				}
				else
				{
					InternalDeviceStatus = DeviceStatus.Connected;
				}
			}
			catch
			{
				throw;
			}
			return num;
		}

		private bool _Download(string configFile, string binaryFile, string destinationAddress)
		{
			if (binaryFile == null || binaryFile.Length == 0)
			{
				throw new ArgumentNullException("binaryFile");
			}
			bool flag = false;
			_Open(configFile, binaryFile, destinationAddress);
			if (DeviceStatus == DeviceStatus.Connected)
			{
				isDownloading = true;
				flag = service._Download();
				isDownloading = false;
				return flag;
			}
			throw new DeviceNotOpenException(Facility.DeviceConnection, ErrorID.NoConnection);
		}

		private bool _Upload(string calibrationFileName)
		{
			bool flag = false;
			if (calibrationFileName == null || calibrationFileName.Length == 0)
			{
				throw new ArgumentNullException("calibrationFileName");
			}
			if (DeviceStatus == DeviceStatus.Connected)
			{
				_ChangeBinaryFileName(calibrationFileName);
				isUploading = true;
				flag = service._Upload();
				isUploading = false;
				return flag;
			}
			throw new DeviceNotOpenException(Facility.DeviceConnection, ErrorID.NoConnection);
		}

		private bool _ChangeBinaryFileName(string binaryFileName)
		{
			bool flag = false;
			return service._ChangeBinaryFileName(binaryFileName);
		}

		protected void RaiseDeviceStatusChangeEvent()
		{
			if (this.DeviceStatusChangeEvent != null)
			{
				try
				{
					this.DeviceStatusChangeEvent(deviceStatus);
				}
				catch (Exception)
				{
				}
			}
		}

		private void OnTimerElapsed(object sender)
		{
			if (isDownloading && isUploading)
			{
				return;
			}
			if (service.MonitorState == MonitorState.Stopped || service.IsStartMonitor2)
			{
				try
				{
					if (ReadParameter("ECM_Run_Time") != 0.0)
					{
						InternalDeviceStatus = DeviceStatus.Connected;
					}
					else
					{
						InternalDeviceStatus = DeviceStatus.Disconnected;
					}
					return;
				}
				catch (ServerNotConnectedException)
				{
					InternalDeviceStatus = DeviceStatus.Disconnected;
					return;
				}
				catch (DeviceNotOpenException)
				{
					try
					{
						if (ReadParameter("RUN_TIME") != 0.0)
						{
							InternalDeviceStatus = DeviceStatus.Connected;
						}
						else
						{
							InternalDeviceStatus = DeviceStatus.Disconnected;
						}
						return;
					}
					catch (DeviceNotOpenException)
					{
						InternalDeviceStatus = DeviceStatus.Disconnected;
						return;
					}
				}
				catch (Exception)
				{
					InternalDeviceStatus = DeviceStatus.Disconnected;
					return;
				}
			}
			if (service.MonitorStatusWhenMonitoring)
			{
				InternalDeviceStatus = DeviceStatus.Connected;
			}
			else
			{
				InternalDeviceStatus = DeviceStatus.Disconnected;
			}
		}

		void ICIRemoteDevice2.WriteParameter2(string elementName, string newValue)
		{
		}
	}
	internal class ReadNParameters : ExecuteCommand
	{
		public ReadNParameters(ITransport transport)
			: base(transport)
		{
		}

		public override void Execute()
		{
			_ = CommunicationLog.InstanceOf;
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(202);
			ausyTelegram.putString("ReadNParameters");
			string empty = string.Empty;
			empty = base.Arguments;
			ausyTelegram.putString(empty);
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			MCTelegram mCTelegram = new MCTelegram(rawData);
			validateResponse(mCTelegram);
			responseString = mCTelegram.getString();
		}
	}
	public class GetSetAddress : ExecuteCommand
	{
		private string address;

		private long length;

		private string newValue;

		public string Address
		{
			set
			{
				address = value;
			}
		}

		public long Length
		{
			set
			{
				length = value;
			}
		}

		public string NewValue
		{
			set
			{
				newValue = value;
			}
		}

		public GetSetAddress(ITransport transport)
			: base(transport)
		{
			address = string.Empty;
			length = -1L;
			newValue = string.Empty;
		}

		public override void Execute()
		{
			CommunicationLog instanceOf = CommunicationLog.InstanceOf;
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(202);
			ausyTelegram.putString(base.Command);
			string s = string.Empty;
			if (base.Command.Equals("GetAddress"))
			{
				s = base.LUN + " " + address.ToString() + " " + length;
			}
			if (base.Command.Equals("SetAddress"))
			{
				s = base.LUN + " " + address.ToString() + " " + newValue.ToString();
			}
			ausyTelegram.putString(s);
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			MCTelegram mCTelegram = new MCTelegram(rawData);
			validateResponse(mCTelegram);
			responseString = mCTelegram.getString();
			instanceOf.AddStringToLog(ElementType.file, "GetSetAddress.CS");
			instanceOf.WriteToLogFile();
		}
	}
	public class GetAddressByParameterName : ExecuteCommand
	{
		public GetAddressByParameterName(ITransport transport)
			: base(transport)
		{
		}

		public override void Execute()
		{
			_ = CommunicationLog.InstanceOf;
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(202);
			ausyTelegram.putString("GetAddressByParameterName");
			string empty = string.Empty;
			empty = base.Arguments;
			ausyTelegram.putString(empty);
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			MCTelegram mCTelegram = new MCTelegram(rawData);
			validateResponse(mCTelegram);
			responseString = mCTelegram.getString();
		}
	}
	public class SelectDescriptionFileCommand : ASAMCommand
	{
		public string descriptionFileName;

		public string binaryFileName;

		public string destination;

		private ITransport transport;

		private ushort lun;

		private bool isExecuted;

		public ushort LUN
		{
			get
			{
				if (!isExecuted)
				{
					throw new InvalidOperationException("Command not Executed");
				}
				return lun;
			}
			set
			{
				lun = value;
			}
		}

		public SelectDescriptionFileCommand(ITransport transport)
		{
			this.transport = transport;
			binaryFileName = "";
		}

		public override void Execute()
		{
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(3);
			ausyTelegram.putString(descriptionFileName);
			ausyTelegram.putString(binaryFileName);
			ausyTelegram.putWord(ushort.Parse(destination, NumberStyles.HexNumber));
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			isExecuted = true;
			MCTelegram mCTelegram = new MCTelegram(rawData);
			validateResponse(mCTelegram);
			LUN = mCTelegram.getWord();
		}
	}
	public class AusyTelegram
	{
		internal static string PadSpace = " ";

		internal static int BitsnByte = 8;

		internal static int WordSize = 2;

		private int index;

		private byte[] rawCommand;

		public byte[] RawData
		{
			get
			{
				byte[] array = new byte[index + WordSize];
				for (int i = 0; i < index; i++)
				{
					array[i] = rawCommand[i];
				}
				putWord(array, 0, (ushort)array.Length);
				EmbedCheckSum(array);
				return array;
			}
		}

		public AusyTelegram()
		{
			index = WordSize;
			rawCommand = new byte[10240];
		}

		public void putWord(ushort value)
		{
			if (ServerConnection.SwapBytes)
			{
				rawCommand[index++] = (byte)(value >> BitsnByte);
				rawCommand[index++] = (byte)value;
			}
			else
			{
				rawCommand[index++] = (byte)value;
				rawCommand[index++] = (byte)(value >> BitsnByte);
			}
		}

		public void putDWord(ulong value)
		{
			if (ServerConnection.SwapBytes)
			{
				rawCommand[index++] = (byte)(value >> 3 * BitsnByte);
				rawCommand[index++] = (byte)(value >> 2 * BitsnByte);
				rawCommand[index++] = (byte)(value >> BitsnByte);
				rawCommand[index++] = (byte)value;
			}
			else
			{
				rawCommand[index++] = (byte)value;
				rawCommand[index++] = (byte)(value >> BitsnByte);
				rawCommand[index++] = (byte)(value >> 2 * BitsnByte);
				rawCommand[index++] = (byte)(value >> 3 * BitsnByte);
			}
		}

		public void putFloat(float value)
		{
			byte[] bytes = BitConverter.GetBytes(value);
			if (ServerConnection.SwapBytes)
			{
				for (int num = bytes.Length - 1; num >= 0; num--)
				{
					rawCommand[index++] = bytes[num];
				}
			}
			else
			{
				for (int i = 0; i < bytes.Length; i++)
				{
					rawCommand[index++] = bytes[i];
				}
			}
		}

		public void putDouble(double value)
		{
			byte[] bytes = BitConverter.GetBytes(value);
			if (ServerConnection.SwapBytes)
			{
				for (int num = bytes.Length - 1; num >= 0; num--)
				{
					rawCommand[index++] = bytes[num];
				}
			}
			else
			{
				for (int i = 0; i < bytes.Length; i++)
				{
					rawCommand[index++] = bytes[i];
				}
			}
		}

		public void putString(string s)
		{
			if (s == null)
			{
				throw new ArgumentNullException("s");
			}
			putWord((ushort)s.Length);
			if (s.Length % 2 != 0)
			{
				s += PadSpace;
			}
			string text = s;
			for (int i = 0; i < text.Length; i++)
			{
				byte b = (byte)text[i];
				rawCommand[index++] = b;
			}
		}

		protected void putWord(byte[] buffer, int position, ushort value)
		{
			if (ServerConnection.SwapBytes)
			{
				buffer[position++] = (byte)(value >> BitsnByte);
				buffer[position++] = (byte)value;
			}
			else
			{
				buffer[position++] = (byte)value;
				buffer[position++] = (byte)(value >> BitsnByte);
			}
		}

		private void EmbedCheckSum(byte[] rawData)
		{
			long num = 0L;
			for (int i = 0; i < rawData.Length - 2; i += 2)
			{
				ushort num2 = BitConverter.ToUInt16(rawData, i);
				num = ((!ServerConnection.SwapBytes) ? (num + num2) : (num + ((num2 << 8) | (num2 >> 8))));
			}
			ushort value = (ushort)num;
			putWord(rawData, rawData.Length - 2, value);
		}
	}
	public enum CommandType
	{
		Emergency,
		Init,
		Identify,
		Exit,
		SelectDescriptionFile,
		CopyBinaryFile,
		ChangeBinaryFileName,
		DefineDescriptionAndBinaryFile,
		ParameterForValueAcquisition,
		ExtendedParameterForValueAcquisition,
		SwitchingOnlineOffline,
		GetOnlineValue,
		ExtendedGetOnlineValue,
		GetParameter,
		SetParameter,
		ExtendedGetParameter,
		ExtendedSetParameter,
		QueryAvailableServices,
		QueryServiceInformation,
		GetAddressByParameterName,
		ExecuteService,
		SendOperation,
		GetSetAddress,
		GetParameterUnits,
		ReadNParameters
	}
	[ComVisible(false)]
	public enum ElementType
	{
		text,
		thread,
		file,
		line,
		datetime,
		level,
		category
	}
	internal class CommunicationLog : ICICommunicationLog
	{
		private const string DefaultOutputFile = "C:\\test.xml";

		private static CommunicationLog instance;

		private static bool enabled;

		private static string executionLogFile;

		private Hashtable logStringsMap;

		private object ExecutionFileLock = new object();

		public static CommunicationLog InstanceOf
		{
			get
			{
				if (instance == null)
				{
					instance = new CommunicationLog();
				}
				return instance;
			}
		}

		public bool Enabled
		{
			get
			{
				return enabled;
			}
			set
			{
				enabled = value;
			}
		}

		public string ExecutionLogFile
		{
			get
			{
				return executionLogFile;
			}
			set
			{
				executionLogFile = value;
			}
		}

		private CommunicationLog()
		{
			logStringsMap = new Hashtable();
			executionLogFile = "C:\\test.xml";
		}

		public void AddStringToLog(ElementType elementType, string msg)
		{
			try
			{
				if (logStringsMap.Contains(elementType.ToString()))
				{
					logStringsMap.Remove(elementType.ToString());
				}
				switch (elementType)
				{
				case ElementType.category:
					logStringsMap.Add("category", msg);
					break;
				case ElementType.datetime:
					logStringsMap.Add("datetime", msg);
					break;
				case ElementType.file:
					logStringsMap.Add("file", msg);
					break;
				case ElementType.level:
					logStringsMap.Add("level", msg);
					break;
				case ElementType.line:
					logStringsMap.Add("line", msg);
					break;
				case ElementType.text:
					logStringsMap.Add("text", msg);
					break;
				case ElementType.thread:
					logStringsMap.Add("thread", msg);
					break;
				}
			}
			catch (Exception)
			{
			}
		}

		public void WriteToLogFile()
		{
			//IL_005a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0060: Expected O, but got Unknown
			//IL_00d1: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d8: Expected O, but got Unknown
			if (!Enabled)
			{
				return;
			}
			lock (ExecutionFileLock)
			{
				try
				{
					FileInfo fileInfo = new FileInfo(executionLogFile);
					if (!fileInfo.Exists)
					{
						StreamWriter streamWriter = new StreamWriter(executionLogFile, append: true);
						streamWriter.WriteLine("<contents>");
						streamWriter.WriteLine("</contents>");
						streamWriter.Flush();
						streamWriter.Close();
					}
					XmlDocument val = new XmlDocument();
					IDictionaryEnumerator enumerator = logStringsMap.GetEnumerator();
					val.Load(executionLogFile);
					XmlElement val2 = val.CreateElement("msg");
					while (enumerator.MoveNext())
					{
						XmlElement val3 = val.CreateElement((string)enumerator.Key);
						((XmlNode)val3).InnerText = (string)enumerator.Value;
						((XmlNode)val2).AppendChild((XmlNode)(object)val3);
					}
					((XmlNode)val.DocumentElement).AppendChild((XmlNode)(object)val2);
					XmlTextWriter val4 = new XmlTextWriter(executionLogFile, (Encoding)null);
					val4.Formatting = (Formatting)1;
					val.Save((XmlWriter)(object)val4);
					((XmlWriter)val4).Flush();
					((XmlWriter)val4).Close();
				}
				catch (IOException)
				{
				}
			}
		}
	}
	internal class DataSentReceivedLog
	{
		private const int MinStringBufferSize = 20;

		private const string DefaultOutputFile = "D:\\DataSentReceivedLog.txt";

		private static bool enabled;

		private static string dataSentReceivedLogFile;

		private static DataSentReceivedLog instance;

		private StringCollection stringCollection;

		private object DataSentReceivedFileLock = new object();

		public static DataSentReceivedLog InstanceOf
		{
			get
			{
				if (instance == null)
				{
					instance = new DataSentReceivedLog();
				}
				return instance;
			}
		}

		public bool Enabled
		{
			get
			{
				return enabled;
			}
			set
			{
				enabled = value;
			}
		}

		public string DataSentReceivedLogFile
		{
			get
			{
				return dataSentReceivedLogFile;
			}
			set
			{
				dataSentReceivedLogFile = value;
			}
		}

		private DataSentReceivedLog()
		{
			stringCollection = new StringCollection();
			dataSentReceivedLogFile = "D:\\DataSentReceivedLog.txt";
		}

		~DataSentReceivedLog()
		{
			WriteToLogFile();
		}

		public void AddStringToLog(string message)
		{
			try
			{
				stringCollection.Add(message);
				if (stringCollection.Count >= 20)
				{
					WriteToLogFile();
				}
			}
			catch (Exception)
			{
			}
		}

		private void WriteToLogFile()
		{
			if (!Enabled)
			{
				return;
			}
			lock (DataSentReceivedFileLock)
			{
				try
				{
					new FileInfo(dataSentReceivedLogFile);
					StreamWriter streamWriter = new StreamWriter(dataSentReceivedLogFile, append: true);
					StringEnumerator enumerator = stringCollection.GetEnumerator();
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
					stringCollection.Clear();
					streamWriter.Flush();
					streamWriter.Close();
				}
				catch (IOException)
				{
				}
			}
		}
	}
	[Guid("7A22292E-14F1-4d9d-A9C9-43ACC1E01D8A")]
	[ComSourceInterfaces(typeof(ICIRemoteScriptingEvents))]
	[ProgId("Cummins.RemoteScripting")]
	[ClassInterface(ClassInterfaceType.AutoDispatch)]
	public class RemoteScripting : ICIRemoteServer, ICIRemoteDevice, ICIMonitor, ICICommands, ICIRemoteLogger, ICICommunicationLog, ICIRemoteDevice2, ICICommands2, ICIRemoteDevice3, ICIMonitor2, ICICommands3, ICICommands4
	{
		private ServerConnection remoteserver;

		private Device remoteDevice;

		private IService protocolService;

		private ICICommands remoteCommands;

		private ICICommands2 remoteCommands2;

		private ICICommands3 remoteCommands3;

		private ICICommands4 remoteCommands4;

		private ICIRemoteLogger remoteLogger;

		private CommunicationLog executionLog;

		private Monitor monitor;

		public string Configuration
		{
			get
			{
				return remoteserver.Configuration;
			}
			set
			{
				remoteserver.Configuration = value;
			}
		}

		public bool Connected => remoteserver.Connected;

		public DeviceStatus DeviceStatus => remoteDevice.DeviceStatus;

		public int MonitorRefreshRate
		{
			get
			{
				return monitor.MonitorRefreshRate;
			}
			set
			{
				monitor.MonitorRefreshRate = value;
			}
		}

		public string MonitorRecordFile
		{
			get
			{
				return monitor.MonitorRecordFile;
			}
			set
			{
				monitor.MonitorRecordFile = value;
			}
		}

		public bool MonitorRecording
		{
			get
			{
				return monitor.MonitorRecording;
			}
			set
			{
				monitor.MonitorRecording = value;
			}
		}

		public int LoggingRefreshRate
		{
			get
			{
				return remoteLogger.LoggingRefreshRate;
			}
			set
			{
				remoteLogger.LoggingRefreshRate = value;
			}
		}

		public string StartCondition
		{
			get
			{
				return remoteLogger.StartCondition;
			}
			set
			{
				remoteLogger.StartCondition = value;
			}
		}

		public string StopCondition
		{
			get
			{
				return remoteLogger.StopCondition;
			}
			set
			{
				remoteLogger.StopCondition = value;
			}
		}

		public bool IsLogging => remoteLogger.IsLogging;

		public bool Enabled
		{
			get
			{
				return executionLog.Enabled;
			}
			set
			{
				executionLog.Enabled = value;
			}
		}

		public string ExecutionLogFile
		{
			get
			{
				return executionLog.ExecutionLogFile;
			}
			set
			{
				executionLog.ExecutionLogFile = value;
			}
		}

		public event ServerStatusChangeDelegate ServerStatusChange
		{
			add
			{
				remoteserver.ServerStatusChangeEvent += value;
			}
			remove
			{
				remoteserver.ServerStatusChangeEvent -= value;
			}
		}

		public event ProgressDelegate ProgressChange
		{
			add
			{
			}
			remove
			{
			}
		}

		public event DeviceStatusChangeDelegate DeviceStatusChange
		{
			add
			{
				remoteDevice.DeviceStatusChangeEvent += value;
			}
			remove
			{
				remoteDevice.DeviceStatusChangeEvent -= value;
			}
		}

		public event MonitorDataRefreshDelegate MonitorDataRefresh
		{
			add
			{
				Monitor obj = monitor;
				obj.MonitorDataRefreshEvent = (MonitorDataRefreshDelegate)Delegate.Combine(obj.MonitorDataRefreshEvent, value);
			}
			remove
			{
				Monitor obj = monitor;
				obj.MonitorDataRefreshEvent = (MonitorDataRefreshDelegate)Delegate.Remove(obj.MonitorDataRefreshEvent, value);
			}
		}

		public RemoteScripting()
		{
			try
			{
				remoteserver = new ServerConnection();
				protocolService = new ASAMService(remoteserver);
				remoteDevice = new Device(remoteserver, protocolService);
				monitor = new Monitor(protocolService);
				remoteCommands = new Commands(remoteserver, protocolService);
				remoteCommands2 = new Commands2(remoteserver, protocolService);
				remoteCommands3 = new Commands3(remoteserver, protocolService);
				remoteCommands4 = new Commands4(remoteserver, protocolService);
				remoteLogger = new RemoteLogger();
				executionLog = CommunicationLog.InstanceOf;
				executionLog.Enabled = false;
			}
			catch (Exception)
			{
			}
		}

		public void Connect()
		{
			remoteserver.Connect();
			protocolService.Initialize();
		}

		public void Disconnect()
		{
			if (remoteDevice.DeviceStatus == DeviceStatus.Connected)
			{
				monitor.StopMonitor();
			}
			if (remoteDevice.DeviceStatus == DeviceStatus.Connected)
			{
				remoteDevice.Close();
			}
			if (remoteserver.ServerStatus == ServerStatus.Connected)
			{
				protocolService.Terminate();
				remoteserver.Disconnect();
			}
		}

		public void Open(string configFile)
		{
			try
			{
				remoteDevice.Open(configFile);
			}
			catch (Exception)
			{
			}
		}

		public void Open2(string configFile, string destination)
		{
			try
			{
				remoteDevice.Open2(configFile, destination);
			}
			catch (Exception)
			{
			}
		}

		public double ReadParameter(string elementName)
		{
			try
			{
				return remoteDevice.ReadParameter(elementName);
			}
			catch (Exception ex)
			{
				throw ex;
			}
		}

		public void WriteParameter(string elementName, double newValue)
		{
			try
			{
				remoteDevice.WriteParameter(elementName, newValue);
			}
			catch (Exception)
			{
			}
		}

		public void Close()
		{
			try
			{
				remoteDevice.Close();
			}
			catch (Exception)
			{
			}
		}

		public bool Download(string configFile, string binaryFile)
		{
			try
			{
				return remoteDevice.Download(configFile, binaryFile);
			}
			catch (Exception ex)
			{
				throw ex;
			}
		}

		public bool Download2(string configFile, string binaryFile, string destinationAddress)
		{
			try
			{
				return remoteDevice.Download2(configFile, binaryFile, destinationAddress);
			}
			catch (Exception ex)
			{
				throw ex;
			}
		}

		public bool Upload(string calibrationFileName)
		{
			try
			{
				return remoteDevice.Upload(calibrationFileName);
			}
			catch (Exception ex)
			{
				throw ex;
			}
		}

		public void ExecuteCommand(string command, string arguments)
		{
			try
			{
				remoteDevice.ExecuteCommand(command, arguments);
			}
			catch (Exception)
			{
			}
		}

		public string ReadAddress(string address, long offset)
		{
			return remoteDevice.ReadAddress(address, offset);
		}

		public void WriteAddress(string address, string newValue)
		{
			try
			{
				remoteDevice.WriteAddress(address, newValue);
			}
			catch (Exception)
			{
			}
		}

		public string ExecuteCommandResult()
		{
			return remoteDevice.ExecuteCommandResult();
		}

		public string ReadParameter2(string elementName)
		{
			return remoteDevice.ReadParameter2(elementName);
		}

		public void WriteParameter2(string elementName, string newValue)
		{
			remoteDevice.WriteParameter2(elementName, newValue);
		}

		public void AddMonitorElement(string element)
		{
			try
			{
				monitor.AddMonitorElement(element);
			}
			catch
			{
			}
		}

		public void RemoveMonitorElement(string element)
		{
			monitor.RemoveMonitorElement(element);
		}

		public void RemoveAllMonitorElements()
		{
			monitor.RemoveAllMonitorElements();
		}

		public void LoadMonitorScreen(string screenFileName, string screenName)
		{
			monitor.LoadMonitorScreen(screenFileName, screenName);
		}

		public void StartMonitor(MonitorMode monitorMode)
		{
			if (remoteDevice.DeviceStatus == DeviceStatus.Connected)
			{
				monitor.StartMonitor(monitorMode);
				return;
			}
			throw new DeviceNotOpenException(Facility.Monitoring, ErrorID.SetupMonitoring);
		}

		public void StopMonitor()
		{
			if (remoteDevice.DeviceStatus == DeviceStatus.Connected)
			{
				monitor.StopMonitor();
				return;
			}
			throw new DeviceNotOpenException(Facility.Monitoring, ErrorID.SetupMonitoring);
		}

		public void StartMonitor2(MonitorMode monitorMode, int UDPPort)
		{
			if (remoteDevice.DeviceStatus == DeviceStatus.Connected)
			{
				monitor.StartMonitor2(monitorMode, UDPPort);
				return;
			}
			throw new DeviceNotOpenException(Facility.Monitoring, ErrorID.SetupMonitoring);
		}

		public object[] GetFaults(FaultsType faultsType)
		{
			return remoteCommands.GetFaults(faultsType);
		}

		public void ClearFaults(FaultsType faultsType)
		{
			remoteCommands.ClearFaults(faultsType);
		}

		public void RequestChangeLock()
		{
			remoteCommands.RequestChangeLock();
		}

		public void ReleaseChangeLock()
		{
			remoteCommands.ReleaseChangeLock();
		}

		public void HoldChanges()
		{
			remoteCommands.HoldChanges();
		}

		public void CancelChanges()
		{
			remoteCommands.CancelChanges();
		}

		public void SaveChanges()
		{
			remoteCommands.SaveChanges();
		}

		public void StopBroadCast()
		{
			remoteCommands.StopBroadCast();
		}

		public void StartBroadCast()
		{
			remoteCommands.StartBroadCast();
		}

		public void RunFromDevelopment()
		{
			remoteCommands.RunFromDevelopment();
		}

		public void RunFromDefault()
		{
			remoteCommands.RunFromDefault();
		}

		public void RunFromBoot()
		{
			remoteCommands.RunFromBoot();
		}

		public void GetChangeLockOwner()
		{
			remoteCommands.GetChangeLockOwner();
		}

		public string SendOperation(string operationName, string inputArguments, out string outputArguments)
		{
			return remoteCommands.SendOperation(operationName, inputArguments, out outputArguments);
		}

		public string GetAddressByParameterName(string parameterName)
		{
			return remoteCommands2.GetAddressByParameterName(parameterName);
		}

		public string GetParameterUnits(string parameterNames)
		{
			return remoteCommands3.GetParameterUnits(parameterNames);
		}

		public string ReadNParameters(string inParamsNames)
		{
			return remoteCommands4.ReadNParameters(inParamsNames);
		}

		public void AddLoggingElement(string element)
		{
			remoteLogger.AddLoggingElement(element);
		}

		public void RemoveLoggingElement(string element)
		{
			remoteLogger.RemoveLoggingElement(element);
		}

		public void StartLogger(LoggingMode mode)
		{
			remoteLogger.StartLogger(mode);
		}

		public void StopLogger()
		{
			remoteLogger.StopLogger();
		}

		public void SaveLog(string logFileName, LogFileLocation logFileLocation)
		{
			remoteLogger.SaveLog(logFileName, logFileLocation);
		}
	}
}
namespace Cummins.CUTY.Exceptions
{
	public class ProtocolException : BaseException
	{
		public ProtocolException(Facility facility, ErrorID errId)
			: base(facility, (short)errId)
		{
		}

		public ProtocolException(Facility facility, ErrorID errId, string message)
			: base(facility, (short)errId, message)
		{
		}

		public ProtocolException(Facility facility, ErrorID errId, string message, Exception inner)
			: base(facility, (short)errId, message, inner)
		{
		}
	}
	public class RemoteScriptingException : BaseException
	{
		public RemoteScriptingException(Facility facility, ErrorID errId)
			: base(facility, (short)errId)
		{
		}

		public RemoteScriptingException(Facility facility, ErrorID errId, string message)
			: base(facility, (short)errId, message)
		{
		}

		public RemoteScriptingException(Facility facility, ErrorID errId, string message, Exception inner)
			: base(facility, (short)errId, message, inner)
		{
		}
	}
	public class BadInputException : RemoteScriptingException
	{
		public BadInputException(Facility facility, ErrorID errId)
			: base(facility, errId)
		{
		}

		public BadInputException(Facility facility, ErrorID errId, string message)
			: base(facility, errId, message)
		{
		}

		public BadInputException(Facility facility, ErrorID errId, string message, Exception inner)
			: base(facility, errId, message, inner)
		{
		}
	}
	public class ServerNotConnectedException : RemoteScriptingException
	{
		public ServerNotConnectedException(Facility facility, ErrorID errId)
			: base(facility, errId)
		{
		}

		public ServerNotConnectedException(Facility facility, ErrorID errId, string message)
			: base(facility, errId, message)
		{
		}

		public ServerNotConnectedException(Facility facility, ErrorID errId, string message, Exception inner)
			: base(facility, errId, message, inner)
		{
		}
	}
	public class DeviceNotOpenException : RemoteScriptingException
	{
		public DeviceNotOpenException(Facility facility, ErrorID errId)
			: base(facility, errId)
		{
		}

		public DeviceNotOpenException(Facility facility, ErrorID errId, string message)
			: base(facility, errId, message)
		{
		}

		public DeviceNotOpenException(Facility facility, ErrorID errId, string message, Exception inner)
			: base(facility, errId, message, inner)
		{
		}
	}
	public class ElementNotFoundException : RemoteScriptingException
	{
		public ElementNotFoundException(Facility facility, ErrorID errId)
			: base(facility, errId)
		{
		}

		public ElementNotFoundException(Facility facility, ErrorID errId, string message)
			: base(facility, errId, message)
		{
		}

		public ElementNotFoundException(Facility facility, ErrorID errId, string message, Exception inner)
			: base(facility, errId, message, inner)
		{
		}
	}
	public class InvalidScreenFileException : RemoteScriptingException
	{
		public InvalidScreenFileException(Facility facility, ErrorID errId)
			: base(facility, errId)
		{
		}

		public InvalidScreenFileException(Facility facility, ErrorID errId, string message)
			: base(facility, errId, message)
		{
		}

		public InvalidScreenFileException(Facility facility, ErrorID errId, string message, Exception inner)
			: base(facility, errId, message, inner)
		{
		}
	}
	public class ScreenNotFoundException : RemoteScriptingException
	{
		public ScreenNotFoundException(Facility facility, ErrorID errId)
			: base(facility, errId)
		{
		}

		public ScreenNotFoundException(Facility facility, ErrorID errId, string message)
			: base(facility, errId, message)
		{
		}

		public ScreenNotFoundException(Facility facility, ErrorID errId, string message, Exception inner)
			: base(facility, errId, message, inner)
		{
		}
	}
	public class ServiceNotfoundException : RemoteScriptingException
	{
		public ServiceNotfoundException(Facility facility, ErrorID errId)
			: base(facility, errId)
		{
		}

		public ServiceNotfoundException(Facility facility, ErrorID errId, string message)
			: base(facility, errId, message)
		{
		}

		public ServiceNotfoundException(Facility facility, ErrorID errId, string message, Exception inner)
			: base(facility, errId, message, inner)
		{
		}
	}
	public class ASAMCommandExecutionException : ProtocolException
	{
		public MCTelegram Response;

		public ASAMCommandExecutionException(MCTelegram response, Facility facility, ErrorID errId)
			: base(facility, errId)
		{
			Response = response;
		}

		public ASAMCommandExecutionException(MCTelegram response, Facility facility, ErrorID errId, string message)
			: base(facility, errId, message)
		{
			Response = response;
		}

		public ASAMCommandExecutionException(MCTelegram response, Facility facility, ErrorID errId, string message, Exception inner)
			: base(facility, errId, message, inner)
		{
			Response = response;
		}
	}
	public class InvalidMCTelegramException : ProtocolException
	{
		public InvalidMCTelegramException(Facility facility, ErrorID errId)
			: base(facility, errId)
		{
		}

		public InvalidMCTelegramException(Facility facility, ErrorID errId, string message)
			: base(facility, errId, message)
		{
		}

		public InvalidMCTelegramException(Facility facility, ErrorID errId, string message, Exception inner)
			: base(facility, errId, message, inner)
		{
		}
	}
	public class MCTelegramLengthInvalidException : ProtocolException
	{
		public MCTelegramLengthInvalidException(Facility facility, ErrorID errId)
			: base(facility, errId)
		{
		}

		public MCTelegramLengthInvalidException(Facility facility, ErrorID errId, string message)
			: base(facility, errId, message)
		{
		}

		public MCTelegramLengthInvalidException(Facility facility, ErrorID errId, string message, Exception inner)
			: base(facility, errId, message, inner)
		{
		}
	}
	public class MCTelegramCheckSumFailedException : ProtocolException
	{
		public MCTelegramCheckSumFailedException(Facility facility, ErrorID errId)
			: base(facility, errId)
		{
		}

		public MCTelegramCheckSumFailedException(Facility facility, ErrorID errId, string message)
			: base(facility, errId, message)
		{
		}

		public MCTelegramCheckSumFailedException(Facility facility, ErrorID errId, string message, Exception inner)
			: base(facility, errId, message, inner)
		{
		}
	}
	public class InvalidPortNumberException : RemoteScriptingException
	{
		public InvalidPortNumberException(Facility facility, ErrorID errId)
			: base(facility, errId)
		{
		}

		public InvalidPortNumberException(Facility facility, ErrorID errId, string message)
			: base(facility, errId, message)
		{
		}

		public InvalidPortNumberException(Facility facility, ErrorID errId, string message, Exception inner)
			: base(facility, errId, message, inner)
		{
		}
	}
}
namespace Cummins.CUTY
{
	public class GetParameterCommand : ASAMCommand
	{
		protected double parValue;

		protected double parMinValue;

		protected double parMaxValue;

		protected double parMinIncValue;

		protected string strValue = "";

		private ushort lun;

		private ITransport transport;

		private string parameterName;

		public string ParameterName
		{
			get
			{
				return parameterName;
			}
			set
			{
				parameterName = value;
			}
		}

		public double ParValue => parValue;

		public ushort LUN
		{
			get
			{
				return lun;
			}
			set
			{
				lun = value;
			}
		}

		public string StringValue => strValue;

		public GetParameterCommand(ITransport transport)
		{
			this.transport = transport;
			parameterName = parameterName;
			LUN = 0;
		}

		protected MCTelegram ActualExecute(ushort command)
		{
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(command);
			ausyTelegram.putWord(LUN);
			ausyTelegram.putString(parameterName);
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			MCTelegram mCTelegram = new MCTelegram(rawData);
			validateResponse(mCTelegram);
			return mCTelegram;
		}

		public override void Execute()
		{
			MCTelegram mCTelegram = ActualExecute(14);
			if (mCTelegram.Status == 0)
			{
				parValue = mCTelegram.getFloat();
				parMinValue = mCTelegram.getFloat();
				parMaxValue = mCTelegram.getFloat();
				parMinIncValue = mCTelegram.getFloat();
			}
		}
	}
	public class ExtGetParameterCommand : GetParameterCommand
	{
		private ASAMDataType asamType;

		internal ASAMDataType DataType => asamType;

		public ExtGetParameterCommand(ITransport transport)
			: base(transport)
		{
		}

		public override void Execute()
		{
			MCTelegram mCTelegram = ActualExecute(114);
			if (mCTelegram.Status == 0)
			{
				switch (mCTelegram.getWord())
				{
				case 0:
					asamType = ASAMDataType.Real;
					parValue = mCTelegram.getFloat();
					parMinValue = mCTelegram.getFloat();
					parMaxValue = mCTelegram.getFloat();
					parMinIncValue = mCTelegram.getFloat();
					strValue = parValue.ToString("R");
					break;
				case 1:
					asamType = ASAMDataType.Real8;
					parValue = mCTelegram.getDouble();
					parMinValue = mCTelegram.getDouble();
					parMaxValue = mCTelegram.getDouble();
					parMinIncValue = mCTelegram.getDouble();
					strValue = parValue.ToString("R");
					break;
				case 2:
					asamType = ASAMDataType.String;
					strValue = mCTelegram.getString();
					break;
				default:
					throw new ASAMCommandExecutionException(mCTelegram, Facility.Monitoring, ErrorID.InvalidASAMDataType);
				}
			}
		}
	}
	public class ChangeBinaryFileNameCommand : ASAMCommand
	{
		private ITransport transport;

		public string BinaryFileName;

		public ushort LUN;

		public ChangeBinaryFileNameCommand(ITransport transport)
		{
			this.transport = transport;
		}

		public override void Execute()
		{
			CommunicationLog instanceOf = CommunicationLog.InstanceOf;
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(5);
			ausyTelegram.putString(BinaryFileName);
			ausyTelegram.putWord(LUN);
			transport.Send(ausyTelegram.RawData);
			byte[] rawData = transport.Receive();
			new MCTelegram(rawData);
			instanceOf.AddStringToLog(ElementType.file, "ChangeBinaryFileNameCommand.CS");
			instanceOf.WriteToLogFile();
		}
	}
	public class IdentifyCommand : ASAMCommand
	{
		private ITransport transport;

		private int protocolVersion;

		private string ausyName;

		private string serverName;

		private int serverProtocolVersion;

		public int ProtocolVersion
		{
			get
			{
				return protocolVersion;
			}
			set
			{
				protocolVersion = value;
			}
		}

		public string AusyName
		{
			get
			{
				return ausyName;
			}
			set
			{
				ausyName = value;
			}
		}

		public string ServerName => serverName;

		public int ServerProtocolVersion => serverProtocolVersion;

		public IdentifyCommand(ITransport transport)
		{
			this.transport = transport;
			protocolVersion = 513;
			ausyName = "Ausy 1.0v";
		}

		public override void Execute()
		{
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(20);
			ausyTelegram.putWord((ushort)protocolVersion);
			ausyTelegram.putString(ausyName);
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			MCTelegram mCTelegram = new MCTelegram(rawData);
			validateResponse(mCTelegram);
			serverProtocolVersion = mCTelegram.getWord();
			serverName = mCTelegram.getString();
		}
	}
	public class CopyBinaryFileCommand : ASAMCommand
	{
		private ITransport transport;

		private ushort target;

		private ushort source;

		private ushort lun;

		public ushort Target
		{
			get
			{
				return target;
			}
			set
			{
				target = value;
			}
		}

		public ushort Source
		{
			get
			{
				return source;
			}
			set
			{
				source = value;
			}
		}

		public ushort LUN
		{
			get
			{
				return lun;
			}
			set
			{
				lun = value;
			}
		}

		public CopyBinaryFileCommand(ITransport transport)
		{
			this.transport = transport;
			source = source;
			LUN = lun;
			Target = target;
			Source = source;
			if (transport == null)
			{
				throw new ArgumentNullException("transport carrier");
			}
			this.transport = transport;
		}

		public override void Execute()
		{
			CommunicationLog instanceOf = CommunicationLog.InstanceOf;
			AusyTelegram ausyTelegram = new AusyTelegram();
			ausyTelegram.putWord(4);
			ausyTelegram.putWord(Target);
			ausyTelegram.putWord(Source);
			ausyTelegram.putWord(LUN);
			byte[] rawData = transport.Transport(ausyTelegram.RawData);
			MCTelegram telegram = new MCTelegram(rawData);
			validateResponse(telegram);
			instanceOf.AddStringToLog(ElementType.file, "CopyBinaryFileCommand.CS");
			instanceOf.WriteToLogFile();
		}
	}
}
